# 组件化启动
## 概述
### 功能简介
构建四个基础组件镜像，提供相应的组件化目录，包括：
- 系统组件：system
- 产品通用配置组件：sys_prod
- 芯片组件：chipset
- 产品硬件配置组件：chip_prod;

确保系统参数以及启动脚本都可以按照组件的优先级进行扫描初始化;
完成系统组件和芯片组件的独立编译构建。
### 基本概念
- 基础组件

   system：系统组件文件系统挂载点，与芯片及硬件无关的平台业务；
   sys_prod：对系统组件的能力扩展以及能力定制，承载产品级差异能力，存放产品相关的配置文件；
   chipset：芯片组件文件系统挂载点，为系统组件提供统一的硬件抽象服务,相同的芯片平台可统一一份芯片组件;
   chip_prod：单板外设特有硬件能力以及产品级硬件差异配置, 存放芯片相关的配置文件。

- 组件化编译构建

  通过"target_cpu" 指定系统组件的指令集；通过"inherit" 继承base、headless或者rich等通用组件集合；最后通过"subsystems" 定义该形态更多的部件。

- 系统参数以及启动脚本按照组件的优先级进行扫描初始化

  系统参数以及启动脚本包括：服务的cfg配置文件、param文件、沙盒json配置文件以及module插件化库文件等。相关文件优先级顺序是 /system < /chipset < /sys_prod < /chip_prod，即优先级高的配置文件将取代、更新低优先级配置。


### 约束与限制
对于标准版本和小型系统都支持组件化编译构建，以及系统参数以及启动脚本按照组件的优先级进行扫描初始化。

## 开发指导
### 场景介绍
组件化启动主要是满足厂家、硬件平台通过模块化的组合快速实现产品开发。以下以rk3568产品为例介绍组件化启动。

### rk3568产品的组件化构建编译
//vendor/hihope/rk3568/config.json 配置文件实现构建此产品需要的组件，如下所示：

        {
          "product_name": "rk3568",
          "device_company": "rockchip",
          ...
          "target_cpu": "arm",
          ...
          "inherit": [ "productdefine/common/inherit/rich.json", "productdefine/common/inherit/chipset_common.json" ],
          "subsystems": [
            {
              "subsystem": "security",
              "components": [
                {
                  "component": "selinux",
                  "features": []
                }
              ]
            }
          ...
        }

从中可以看出产品名称、芯片厂家、支持的指令集等；inherit指出依赖的通用组件；subsystems指出通用组件以外的部件。
//productdefine/common/inherit/rich.json 如下所示配置系统组件完整的部件；系统组件还可以包括base.json(所有产品都要包含的最小部件集合列表)、headless.json(没有ui界面的产品支持应用安装管理的最小部件集合)。

    {
      "version": "3.0",
      "subsystems": [
      {
        "subsystem": "arkui",
        "components": [
          {
            "component": "ace_engine",
            "features": []
          },
          {
            "component": "napi",
            "features": []
          }
        ]
      },
      {
        "subsystem": "account",
        "components": [
          {
            "component": "os_account",
            "features": []
          }
        ]
      },
      ...
    }

### 系统参数根据优先级扫描初始化
对于服务的cfg配置文件优先级是/system/etc < /system/etc/init < /chipset/etc，即优先级高的配置文件将取代、更新低优先级配置。例如/system/etc/init/camera_service.cfg，

      {
        "services" : [{
            "name" : "camera_service",
            "path" : ["/system/bin/sa_main", "/system/profile/camera_service.xml"],
            "uid" : "cameraserver",
            "gid" : ["system", "shell"],
            "secon" : "u:r:camera_service:s0",
            "permission" : ["ohos.permission.GET_SENSITIVE_PERMISSIONS"],
            "permission_acls" : ["ohos.permission.GET_SENSITIVE_PERMISSIONS"]
        }]
      }  

同时存在/chipset/etc/camera_B_service.cfg

       {
        "services" : [{
            "name" : "camera_service",
            "path" : ["/system/bin/sa_main", "/system/profile/camera_B_service.xml"],
            "uid" : "cameraserver",
            "gid" : ["system", "shell"],
            "secon" : "u:r:camera_service:s0",
            "permission" : ["ohos.permission.GET_SENSITIVE_PERMISSIONS"],
            "permission_acls" : ["ohos.permission.GET_SENSITIVE_PERMISSIONS"],
            "disabled" : 1
        }]
      }  

那么根据优先级的要求，camera_service服务"path"属性将会被优先级高的["/system/bin/sa_main", "/system/profile/camera_B_service.xml"]取代，同时增加"disabled"属性。
