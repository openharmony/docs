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
      - 默认情况下，服务的sandbox功能是打开的，如果不想让某个特定的服务不进入沙盒，在cfg中配置sandbox ： 0。当在cfg配置sandbox ： 1，服务依进入沙盒。
        ```
        "sandbox" : 1
        ```

2.  修改沙盒JSON文件配置
    - 查看系统组件沙盒配置文件、芯片组件沙盒配置文件，进入/system/etc/sandbox/ 目录下，cat system-sandbox.json ，cat chipset-sandbox.json; 直接修改对应沙盒配置文件， 重新启动。
     对于64位系统，cat system-sandbox64.json ，cat chipset-sandbox64.json。
    - 代码路径下：base/startup/init_lite/interfaces/innerkits/sandbox 修改对应沙盒配置文件。

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

## 常见问题
### 沙盒没有创建成功

**现象描述**

dmesg或者hilog日志中出现 Sandbox %s has not been created.

**原因分析**

沙盒没有创建成功，主要原因是mount与link时出现错误，根据mount与link的主要函数的日志，排查具体问题。

**解决方法**
1. 检查JSON文件是否配置正确。
2. 创建的沙盒是否受支持。