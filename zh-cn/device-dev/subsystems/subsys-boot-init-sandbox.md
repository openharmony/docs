# 沙盒管理

## 概述
### 功能简介
支持系统组件及芯片组件进程沙盒运行。

### 基本概念
在init里面创建系统组件沙盒和芯片组件沙盒，native服务根据功能进入system沙盒或者chipset沙盒。在system-sandbox.json、chipset-sandbox.json等配置文件中设置沙盒组件中mount bind 的目录或文件，实现沙盒组件通过mount属性进行隔离。同时，提供了一种沙盒调试工具，当需要在沙盒内验证或者进行沙盒相关开发时，方便对需求进行调试、验证、完善。begetctl沙盒命令参考:  **[begetctl命令说明](subsys-boot-init-plugin.md#参数说明)**。

### 约束与限制

仅标准系统下使用。

## 开发指导
### 参数说明
  **表1** 沙盒配置文件字段解释

  | JSON前缀 | 解释 |
  | ---------- | ---------- |
  | sandbox-root | 沙盒的根目录 |
  | mount-bind-paths | mount一个目录 |
  | mount-bind-files | mount一个文件 |
  | src-path | 需要mount的目录/文件路径 |
  | sandbox-path | 沙盒里面需要挂载至的目录/文件 |
  | sandbox-flags | mount的挂载标志位, 缺省"bind rec"标志位 |
  | ignore | 是否忽略mount失败，设置为1 则忽略失败，继续往下执行 |
  | target-name | 需要link的目录 |
  | link-name | 沙盒内link后的目录 |

  **表2** 沙盒配置文件解释
  | 沙盒配置文件 | 解释 |
  | -------- | -------- |
  | chipset-sandbox64.json | 64位系统的芯片沙盒配置文件 |
  | chipset-sandbox.json | 32位系统的芯片沙盒配置文件 |
  | system-sandbox64.json  | 64位系统的系统沙盒配置文件 |
  | system-sandbox.json  | 32位系统的系统沙盒配置文件 |

### 接口说明
**沙盒的逻辑存储结构：**

```c++
// 主要函数
// name is "system" or "chipset"
bool InitSandboxWithName(const char *name); // 解析JSON至结构体

typedef struct {
    ListNode pathMountsHead;   // sandbox mount_path list head
    ListNode fileMountsHead;   // sandbox mount_file list head
    ListNode linksHead;        // sandbox symbolic link list head
    char *rootPath;            // /mnt/sandbox/system|vendor|xxx
    char name[MAX_BUFFER_LEN]; // name of sandbox. i.e system, chipset etc.
    bool isCreated;            // sandbox already created or not
    int ns;                    // namespace
} sandbox_t;
```
### 开发步骤
1. 沙盒的创建方式
      - 创建system或者chipset沙盒，配置对应的system-sandbox.json或者chipset-sandbox.json文件，JSON文件配置参考: [沙盒JSON文件配置](#sandbox)
      - 默认情况下，服务的sandbox功能是打开的，如果不想让某个特定的服务进入沙盒，在cfg中配置sandbox ： 0。当在cfg配置sandbox ： 1，服务依进入沙盒。
        ```
        "sandbox" : 1
        ```

2.  修改沙盒JSON文件配置
    - 查看系统组件沙盒配置文件、芯片组件沙盒配置文件，进入/system/etc/sandbox/ 目录下，cat system-sandbox.json ，cat chipset-sandbox.json; 直接修改对应沙盒配置文件， 重新启动。
     对于64位系统，cat system-sandbox64.json ，cat chipset-sandbox64.json。
    - 代码路径下：base/startup/init/interfaces/innerkits/sandbox 修改对应沙盒配置文件。

### 开发实例
沙盒JSON文件配置<a name = "sandbox"></a>

```json
{
    "sandbox-root" : "/mnt/sandbox/system",
    "mount-bind-paths" : [{
        "src-path" : "/system/lib/ndk",
        "sandbox-path" : "/system/lib/ndk",
        "sandbox-flags" : [ "bind", "rec", "private" ]
    }],
    "mount-bind-files" : [{
        "src-path" : "/system/lib/ld-musl-aarch64.so.1",
        "sandbox-path" : "/system/lib/ld-musl-aarch64.so.1",
        "sandbox-flags" : [ "bind", "rec", "private" ]
    }],
    "symbol-links" : [{
        "target-name" : "/vendor/lib",
        "link-name" : "/lib"
    }]
}
```

## 系统/芯片沙盒常见问题
- 原因分析：
     相关服务访问不到所需要的so等资源文件 
- 解决方案：
    分析hilog，通过分析log检查失败的原因，在设备中搜索报错so的path，修改对应so的BUILD.gn文件。如下步骤:

    - log分析，hilog搜索关键字"failed"或".so"结果

      ```
      08-05 17:27:29.302   488   488 E C02500/driver_loader_full: get driver entry failed, /vendor/lib/libcamera_host_service_1.0.z.so load fail, Error loading shared library libdisplay_buffer_proxy_1.0.z.so: No such file or directory (needed by /system/lib/chipset-pub-sdk/libdisplay_buffer_hdi_impl.z.so)
      08-05 17:27:29.303   488   488 E C02500/devhost_service_full: DevHostServiceAddDevice failed and return -207
      08-05 17:27:29.305   488   488 E C02500/devhost_service_stub: Dis patch failed, add service failed and ret is -207
      08-05 17:27:29.307   488   488 I C02500/devhost_service_stub: add device 0x7000201
      08-05 17:27:29.308   488   488 E C02500/driver_loader_full: /vendor/lib/libhdi_media_layer_service.z.so no valid, errno:2
      ```

    - 根据结果，camera报错是由于libdisplay_buffer_proxy_1.0.z.so加载失败，两种方式进行处理，方式一在沙盒中对该file进行mount进行快速修复(仅支持本地debug，源码修改需要进行评审)，方式二需要修改对应BUILD.gn文件

      - 快速修复方式：沙盒中mount file/path

        - 系统沙盒: 编辑设备中/system/etc/sandbox/system-sandbox.json文件，默认只mount vendor路径下的部分文件，如有报错缺失在其中进行单独mount
      
        - chipset沙盒: 编辑设备中/system/etc/sandbox/chipset-sandbox.json文件，默认只mount system路径下的部分文件，如有报错缺失在其中进行单独mount
        
        - 如上case需要在/system/etc/sandbox/chipset-sandbox.json中添加如下：
        
        ```
        "mount-bind-files" : [
        	{
                "src-path" : "/system/lib/libdisplay_buffer_proxy_1.0.z.so",
                "sandbox-path" : "/system/lib/libdisplay_buffer_proxy_1.0.z.so",
                "sandbox-flags" : [ "bind", "rec", "private" ]
            },{...}
        ],
        ```
        
      - 方式二：添加innerapi_tags
      
        ```
        ohos_shared_library("xxx") {
        	...
        	innerapi_tags = [
            	"chipsetsdk",
            ]
        }
        ```
        
      - innerapi_tags相关:
      
        -   沙盒权限相关的tags包含"passthrough"、"chipsetsdk"、"passthrough_indirect "、"chipsetsdk_indirect" 
          
          -  可通过 Openharmony实时架构信息网站查看so信息，如果是间接依赖模块使用chipsetsdk_indirect或者passthrough_indirect , 其余使用chipsetsdk或者passthrough 
          -  安装到系统目录的so使用"chipsetsdk"和"chipsetsdk_indirect"，供芯片组件访问 
          -  安装到芯片目录的so使用"passthrough"和"passthrough_indirect "，供系统组件访问 
        -  通过innerapi_tags标记添加可以指定so安装的路径，比如标记了chipsetsdk的就装在/lib/chipset-sdk/目录下，具体逻辑源码如下，代码路径： build/templates/cxx/cxx.gni
        ```gni
        # auto set auto_relative_install_dir by innerapi_tags
        if (defined(invoker.innerapi_tags)) {
      	    is_chipsetsdk = false
            is_platformsdk = false
            is_passthrough = false
            foreach(tag, filter_include(invoker.innerapi_tags, [ "chipsetsdk*" ])) {
              is_chipsetsdk = true
            }
            foreach(tag, filter_include(invoker.innerapi_tags, [ "platformsdk*" ])) {
              is_platformsdk = true
            }
            foreach(tag, filter_include(invoker.innerapi_tags, [ "passthrough*" ])) {
              is_passthrough = true
            }
            if (is_chipsetsdk && is_platformsdk) {
              auto_relative_install_dir = "chipset-pub-sdk"
            } else if (is_chipsetsdk) {
              auto_relative_install_dir = "chipset-sdk"
            } else if (is_platformsdk) {
              auto_relative_install_dir = "platformsdk"
            }
            if (is_passthrough) {
              auto_relative_install_dir = chipset_passthrough_dir
            }
            ...
        }