# 部件
### 部件配置规则

部件的bundle.json放在部件源码的根目录下。以泛sensor子系统的sensor服务部件为例，部件属性定义描述文件字段说明如下：

```shell
{
    "name": "@ohos/sensor_lite",		                                 # HPM部件英文名称，格式"@组织/部件名称"
    "description": "Sensor services",		                             # 部件功能一句话描述	
    "version": "3.1",			                                         # 版本号，版本号与OpenHarmony版本号一致
    "license": "MIT",			                                         # 部件License
    "publishAs": "code-segment",		                                 # HPM包的发布方式，当前默认都为code-segment
    "segment": {										
        "destPath": ""			
    },					                                                 # 发布类型为code-segment时为必填项，定义发布类型code-segment的代码还原路径（源码路径）			
    "dirs": {"base/sensors/sensor_lite"},	                             # HPM包的目录结构，字段必填内容可以留空
    "scripts": {},			                                             # HPM包定义需要执行的脚本，字段必填，值非必填
    "licensePath": "COPYING",			
    "readmePath": {
        "en": "README.rst"
    },
    "component": {			                                             # 部件属性
        "name": "sensor_lite",			                                 # 部件名称		
        "subsystem": "",		                                         # 部件所属子系统
        "syscap": [],				                                     # 部件为应用提供的系统能力
        "features": [],                                                  # 部件对外的可配置特性列表，一般与build中的sub_component对应，可供产品配置
        "adapted_system_type": [],		                                 # 轻量(mini)小型(small)和标准(standard)，可以是多个
        "rom": "92KB",                                                   # 部件ROM值
        "ram": "~200KB",                                                 # 部件RAM估值       
        "deps": {                      
        "components": [                                                  # 部件依赖的其他部件
          "samgr_lite",
          "ipc_lite"
        ],
        "third_party": [                                                 # 部件依赖的三方开源软件
          "bounds_checking_function"
        ],
        "hisysevent_config": []                                          # 部件HiSysEvent打点配置文件编译入口
      }         
        "build": {				                                         # 编译相关配置
            "sub_component": [
                ""//base/sensors/sensor_lite/services:sensor_service"",  # 部件编译入口
            ],			                                                 # 部件编译入口，模块在此处配置
            "inner_kits": [],						                     # 部件间接口
            "test": []							                         # 部件测试用例编译入口
        }
    }
 }
```

> **注意**：lite上旧的部件在build/lite/components目录下对应子系统的json文件中，路径规则为：**{领域}/{子系统}/{部件}**，部件目录树规则如下：

```shell
component
├── interfaces
│   ├── innerkits  # 系统内接口，部件间使用
│   └── kits       # 应用接口，应用开发者使用
├── frameworks     # framework实现
├── services       # service实现
└── BUILD.gn       # 部件编译脚本
```

部件配置中需要配置部件的名称、源码路径、功能简介、是否必选、编译目标、RAM、ROM、编译输出、已适配的内核、可配置的特性和依赖等属性定义。

> **注意**：部件配置中HiSysEvent打点配置文件使用说明，请参考文档[HiSysEvent打点配置](subsys-dfx-hisysevent-logging-config.md)。

新增部件时需要在对应子系统json文件中添加相应的部件定义。产品所配置的部件必须在某个子系统中被定义过，否则会校验失败。

### 新增并编译部件

1. 添加部件。 本节以添加一个自定义的部件为例，描述如何编译部件，编译库、编译可执行文件等。

   示例部件partA由feature1、feature2和feature3组成，feature1的编译目标为一个动态库，feature2的目标为一个可执行程序，feature3的目标为一个etc配置文件。

   示例部件partA的配置需要添加到一个子系统中，本次示例将添加到subsystem_examples子系统中（subsystem_examples子系统定义在test/examples/目录）。

   示例部件partA的完整目录结构如下：

   ```shell
   test/examples/partA
   ├── feature1
   │   ├── BUILD.gn
   │   ├── include
   │   │   └── helloworld1.h
   │   └── src
   │       └── helloworld1.cpp
   ├── feature2
   │   ├── BUILD.gn
   │   ├── include
   │   │   └── helloworld2.h
   │   └── src
   │       └── helloworld2.cpp
   └── feature3
       ├── BUILD.gn
       └── src
           └── config.conf
   ```

   示例1：编写动态库gn脚本test/examples/partA/feature1/BUILD.gn，示例如下：

   ```shell
   config("helloworld_lib_config") {
    include_dirs = [ "include" ]
   }
   
   ohos_shared_library("helloworld_lib") {
     sources = [
       "include/helloworld1.h",
       "src/helloworld1.cpp",
     ]
     public_configs = [ ":helloworld_lib_config" ]
     part_name = "partA"
   }
   ```

   示例2：编写可执行文件gn脚本test/examples/partA/feature2/BUILD.gn，示例如下：

   ```shell
   ohos_executable("helloworld_bin") {
     sources = [
       "src/helloworld2.cpp"
     ]
     include_dirs = [ "include" ]
     deps = [                                # 依赖部件内模块
       "../feature1:helloworld_lib"
     ]
     external_deps = [ "partB:module1" ]     # （可选）如果有跨部件的依赖，格式为“部件名:模块名”
     install_enable = true                   # 可执行程序缺省不安装，需要安装时需要指定
     part_name = "partA"
   }
   ```

   示例3：编写etc模块gn脚本test/examples/partA/feature3/BUILD.gn，示例如下：

   ```shell
   ohos_prebuilt_etc("feature3_etc") {
     source = "src/config.conf"
     relative_install_dir = "init"    #可选，模块安装相对路径，相对于默认安装路径；默认在/system/etc目录
     part_name = "partA"
   }
   ```

   示例4：在部件的bundle.json中添加模块配置：test/examples/bundle.json。每个部件都有一个bundle.json配置文件，在部件的根目录下。示例见：[部件的bundle.json](subsys-build-component.md#部件配置规则)

2. 将部件添加到产品配置中。 在产品的配置中添加部件，产品对应的配置文件：//vendor/{product_company}/{product-name}/config.json。下面以vendor/hisilicon/hispark_taurus_standard/config.json为例：

    ```shell
      {
        "product_name": "hispark_taurus_standard",
        "device_company": "hisilicon",
        "device_build_path": "device/board/hisilicon/hispark_taurus/linux",
        "target_cpu": "arm",
        "type": "standard",
        "version": "3.0",
        "board": "hispark_taurus",
        "inherit": [ "productdefine/common/base/standard_system.json",
                    "productdefine/common/inherit/ipcamera.json"
        ],
        "enable_ramdisk": true,
        "subsystems": [
          {
            "subsystem": "subsystem_examples",                              # 部件所属子系统
            "components": [
              {
                "component": "partA",                                       # 部件名称
                "features": []                                              # 部件对外的可配置特性列表
              }
            ]
          },
        ······
      }
    ```

    从中可以看出产品名称、芯片厂家等；inherit指出依赖的通用组件；subsystems指出通用组件以外的部件。

    在产品配置文件中添加 "subsystem_examples:partA"，表示该产品中会编译并打包partA到版本中。

3. 编译。 主要有两种编译方式，[命令行方式和hb方式](subsys-build-all.md#编译命令)，下面以命令行方式为例：

   部件可以使用"--build-target 部件名"进行单独编译，以编译产品hispark_taurus_standard的musl部件为例，编译命令如下：

   ```
   ./build.sh --product-name hispark_taurus_standard --build-target musl --ccache
   ```

   也可以编译相应产品，以编译hispark_taurus_standard为例，编译命令如下：

   ```shell
   ./build.sh --product-name hispark_taurus_standard --ccache
   ```

4. 编译输出。 编译所生成的文件都归档在out/hispark_taurus/目录下，结果镜像输出在 out/hispark_taurus/packages/phone/images/ 目录下。