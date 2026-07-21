# Mini芯片最小系统适配指南

本文档面向Mini芯片最小系统适配场景，提供各核心模块Feature的说明与使用方法。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本文档为框架文档，各模块章节中标注 **[待补充]** 的部分需由对应模块补充完善。

## 约束与限制

- 本文档适用于OpenHarmony轻量系统（mini系统）的最小系统适配场景
- 目标芯片架构以cortex-m、risc-v系列为典型代表
- 各模块Feature以config.json中的features配置项为入口进行裁剪与使能

## 整体架构

Mini芯片最小系统由以下核心模块组成：

| 模块 | 职责 |
| -------- | -------- |
| init-启动恢复 | 内核启动后的系统关键进程和服务启动、系统参数管理 |
| samgr-系统服务管理 | 系统服务注册、发现与统一管理 |
| DFX | 可维可测能力，包括日志、事件打点等 |
| HCTEST-测试框架 | 兼容性测试框架，提供基本接口的测试验证能力 |
| 三方库 | 第三方库的适配适配与集成 |
| 编译链接 | 编译构建配置与链接脚本管理 |

## 适配流程

**表1** Mini芯片最小系统适配步骤

| 步骤 | 说明 |
| -------- | -------- |
| 1. 适配准备 | 下载代码、搭建编译环境、熟悉编译构建框架 |
| 2. 内核适配 | 适配伙伴SDK到OpenHarmony平台，确认arch支持 |
| 3. 模块适配 | 按本章各模块指导逐个适配init、samgr、DFX、HCTEST、三方库、编译链接 |
| 4. 适配验证 | 使用HCTEST兼容性测试套件验证，伙伴自有测试补充 |

---

## init-启动恢复

启动恢复子系统负责在内核启动之后到应用启动之前的系统关键进程和服务的启动过程。

### Feature列表

| Feature名 | 说明 | 默认值 |
| -------- | -------- | -------- |
| bootstrap_lite_enable_bootstrap_service | 是否使能bootstrap服务启动能力 | false |
| init_lite_memory_size | 启动模块内存池大小（字节） | 8192 |
| init_lite_param_const_value_len_max | 常量参数值的最大长度 | 256 |
| init_lite_param_value_len_max | 参数值的最大长度 | 48 |
| init_lite_param_name_len_max | 参数名的最大长度 | 48 |
| init_lite_persist_all | 是否持久化所有参数 | false |
| acts_lite_deviceinfo_merge | 是否合并设备信息测试用例 | true |
| acts_lite_param_value_len_max_48 | 是否将参数值最大长度限制为48（兼容测试） | true |

### Feature说明

- **bootstrap_lite_enable_bootstrap_service**：控制bootstrap服务启动能力是否使能。设为true时，启动阶段将通过bootstrap标识的入口函数启动系统服务；设为false则跳过该流程。适用于需要精简启动流程的场景。

- **init_lite_memory_size**：设置启动模块内存池大小，单位为字节。默认8192字节，若启动阶段注册的服务或参数较多，可适当增大该值。需根据实际芯片RAM资源调整。

- **init_lite_param_const_value_len_max**：设置常量参数值的最大允许长度。默认256字节，影响系统参数中常量值的存储上限。

- **init_lite_param_value_len_max**：设置可变参数值的最大允许长度。默认48字节，影响系统参数中可变值的存储上限。与`acts_lite_param_value_len_max_48`配合使用。

- **init_lite_param_name_len_max**：设置参数名的最大允许长度。默认48字节，影响系统参数名的存储上限。

- **init_lite_persist_all**：控制是否将所有系统参数持久化存储。默认false，仅持久化标记为persist的参数；设为true则持久化全部参数。开启后会增加Flash写入开销。

- **acts_lite_deviceinfo_merge**：兼容性测试相关，控制是否将设备信息测试用例合并执行。默认true。

- **acts_lite_param_value_len_max_48**：兼容性测试相关，确认参数值最大长度为48字节的测试约束。默认true。

### 使用方法

#### 1. 在config.json中添加启动子系统

路径："vendor/MyVendorCompany/MyProduct/config.json"

```json
{
    "subsystem": "startup",
    "components": [
        {
            "component": "bootstrap_lite",
            "features": [
                "bootstrap_lite_enable_bootstrap_service = false"
            ]
        },
        {
            "component": "syspara_lite",
            "features": [
                "init_lite_memory_size = 8192",
                "init_lite_param_const_value_len_max = 256",
                "init_lite_param_value_len_max = 48",
                "init_lite_param_name_len_max = 48",
                "init_lite_persist_all = false"
            ]
        }
    ]
},
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> `acts_lite_deviceinfo_merge`和`acts_lite_param_value_len_max_48`为兼容性测试相关Feature，在执行HCTEST时需按需配置。

---

## samgr-系统服务管理

系统服务管理子系统负责系统服务的注册、发现与统一管理，基于SAMGR框架实现服务的按需启动与生命周期管理。

### Feature列表

| Feature名 | 说明 | 默认值 |
| -------- | -------- | -------- |
| enable_ohos_systemabilitymgr_samgr_lite_broadcast | 是否使能广播能力 | false |
| enable_ohos_systemabilitymgr_samgr_lite_system_capability | 是否使能系统能力查询 | false |
| config_ohos_systemabilitymgr_samgr_lite_shared_task_size | 共享任务栈大小（字节） | 2048 |
| enable_ohos_systemabilitymgr_samgr_lite_specified_task | 是否使能指定任务模式 | false |
| enable_ohos_systemabilitymgr_samgr_lite_no_task | 是否使能无任务模式 | false |
| enable_ohos_test_xts_acts_use_samgr_lite_broadcast | 兼容性测试：是否使用广播能力 | false |
| enable_ohos_test_xts_acts_use_samgr_lite_debug | 兼容性测试：是否使能调试模式 | false |
| enable_ohos_test_xts_acts_use_samgr_lite_taskpool_notask | 兼容性测试：是否使用无任务池模式 | false |
| enable_ohos_test_xts_acts_use_samgr_lite_taskpool_specifiedtask | 兼容性测试：是否使用指定任务池模式 | false |

### Feature说明

- **enable_ohos_systemabilitymgr_samgr_lite_broadcast**：控制SAMGR Lite是否提供广播（Broadcast）能力。广播能力允许服务向多个订阅者发布消息，适用于一对多的事件通知场景。开启后会增加内存占用。

- **enable_ohos_systemabilitymgr_samgr_lite_system_capability**：控制是否使能系统能力（System Capability）查询功能。开启后，服务可查询系统中已注册的能力列表，支持服务的动态发现。

- **config_ohos_systemabilitymgr_samgr_lite_shared_task_size**：设置SAMGR Lite共享任务栈的大小，单位为字节。默认2048字节。当多个服务共享同一个任务线程运行时，需确保栈空间足够。若服务处理逻辑较复杂或调用层级较深，需适当增大该值。

- **enable_ohos_systemabilitymgr_samgr_lite_specified_task**：控制是否使能指定任务模式。开启后，服务可运行在指定的独立任务线程中，而非共享任务池。适用于对实时性或隔离性要求较高的服务。

- **enable_ohos_systemabilitymgr_samgr_lite_no_task**：控制是否使能无任务模式。开启后，服务不创建独立任务线程，由调用者线程直接执行服务逻辑。适用于极轻量场景，可节省任务创建开销。

- **enable_ohos_test_xts_acts_use_samgr_lite_broadcast**：兼容性测试相关，控制测试用例是否依赖SAMGR Lite的广播能力。需与`enable_ohos_systemabilitymgr_samgr_lite_broadcast`配合使用。

- **enable_ohos_test_xts_acts_use_samgr_lite_debug**：兼容性测试相关，控制是否使能SAMGR Lite调试模式，输出更多调试信息。

- **enable_ohos_test_xts_acts_use_samgr_lite_taskpool_notask**：兼容性测试相关，控制测试用例是否使用无任务池模式运行。

- **enable_ohos_test_xts_acts_use_samgr_lite_taskpool_specifiedtask**：兼容性测试相关，控制测试用例是否使用指定任务池模式运行。

### 使用方法

#### 1. 在config.json中添加samgr子系统

路径："vendor/MyVendorCompany/MyProduct/config.json"

```json
{
    "subsystem": "distributed_schedule",
    "components": [
        {
            "component": "system_ability_manager",
            "features": [
                "enable_ohos_systemabilitymgr_samgr_lite_broadcast = false",
                "enable_ohos_systemabilitymgr_samgr_lite_system_capability = false",
                "config_ohos_systemabilitymgr_samgr_lite_shared_task_size = 2048",
                "enable_ohos_systemabilitymgr_samgr_lite_specified_task = false",
                "enable_ohos_systemabilitymgr_samgr_lite_no_task = false"
            ]
        }
    ]
},
```

#### 2. SAMGR启动流程

`OHOS_SystemInit()`中调用`SAMGR_Bootstrap()`完成服务框架初始化，各服务通过zinitcall段注册：

```c
// SAMGR_Bootstrap() 会依次执行：
// 1. .zinitcall.app.serviceX.init 段 —— 注册系统服务
// 2. .zinitcall.app.featureX.init 段 —— 注册服务Feature
```

#### 3. 注册自定义系统服务

**[待补充服务注册的示例代码与步骤]**

#### 4. 兼容性测试Feature配置

执行HCTEST时，需按需开启测试相关Feature：

```json
{
    "component": "system_ability_manager",
    "features": [
        "enable_ohos_test_xts_acts_use_samgr_lite_broadcast = false",
        "enable_ohos_test_xts_acts_use_samgr_lite_debug = false",
        "enable_ohos_test_xts_acts_use_samgr_lite_taskpool_notask = false",
        "enable_ohos_test_xts_acts_use_samgr_lite_taskpool_specifiedtask = false"
    ]
}
```

---

## DFX

DFX（Design for eXcellence）可维可测子系统提供日志、事件打点等维测能力，是系统运行态问题定位的关键基础设施。

### Feature列表

| Feature名 | 所属部件 | 说明 | 默认值 |
| -------- | -------- | -------- | -------- |
| hilog_lite_mini | hilog_lite | 是否使能Mini系统日志功能 | true |
| hievent_lite_mini | hievent_lite | 是否使能Mini系统事件打点功能 | true |
| hiview_lite_mini | hiview_lite | 是否使能Mini系统维测视图功能 | true |

### Feature说明

- **hilog_lite_mini**：控制hilog_lite部件在Mini系统下的使能。开启后提供轻量级日志输出能力，支持日志分级（DEBUG/INFO/WARN/ERROR/FATAL）、按模块过滤等功能。关闭后可减少ROM和RAM占用，但将失去运行态日志输出能力。

- **hievent_lite_mini**：控制hievent_lite部件在Mini系统下的使能。开启后提供轻量级事件打点能力，支持关键事件的记录与上报，用于系统行为分析和故障定位。

- **hiview_lite_mini**：控制hiview_lite部件在Mini系统下的使能。开启后提供维测视图能力，支持日志和事件的统一管理与查询。

### 使用方法

#### 1. 在config.json中添加DFX子系统

路径："vendor/MyVendorCompany/MyProduct/config.json"

```json
{
    "subsystem": "hiviewdfx",
    "components": [
        {
            "component": "hilog_lite",
            "features": ["hilog_lite_mini = true"]
        },
        {
            "component": "hievent_lite",
            "features": ["hievent_lite_mini = true"]
        },
        {
            "component": "hiview_lite",
            "features": ["hiview_lite_mini = true"]
        }
    ]
},
```

#### 2. 日志功能使用

**[待补充hilog_lite的使用示例与API说明]**

#### 3. 事件打点功能使用

**[待补充hievent_lite的使用示例与API说明]**

#### 4. 维测视图功能使用

**[待补充hiview_lite的使用示例与API说明]**

---

## HCTEST-测试框架

HCTEST为OpenHarmony兼容性测试框架，提供基本接口的测试验证能力，用于在适配完成后对工程进行兼容性测试。

### Feature列表

| Feature名 | 说明 | 默认值 |
| -------- | -------- | -------- |
| hctest_rodata_opt | 是否使能测试只读数据优化 | true |
| xts_overlay | 是否使能XTS覆盖层 | true |

### Feature说明

- **hctest_rodata_opt**：控制测试只读数据段优化。使能后可减少测试用例对ROM空间的占用，适用于Flash资源紧张的Mini芯片场景。

- **xts_overlay**：控制XTS（X Test Suite）覆盖层功能。使能后支持测试套件的覆盖执行模式，允许对特定模块进行针对性测试。

### 使用方法

#### 1. 编译时配置HCTEST Feature

HCTEST的Feature通过编译参数`--gn-args`传入，也可以通过config.json中的features字段开启：

```bash
hb build --gn-args hctest_rodata_opt=true xts_overlay=true
```

#### 2. 执行兼容性测试

**[待补充测试执行命令与步骤]**

#### 3. 测试结果分析

**[待补充]**

---

## 三方库

三方库模块负责第三方库的适配适配与集成，确保外部依赖库能正确集成到OpenHarmony编译体系中。

### 使用方法

#### 1. 基于CMake的三方库适配

参考[porting-thirdparty-cmake](porting-thirdparty-cmake.md)。

**[待补充具体步骤与注意事项]**

#### 2. 基于Makefile的三方库适配

参考[porting-thirdparty-makefile](porting-thirdparty-makefile.md)。

**[待补充具体步骤与注意事项]**

---

## 编译链接

编译链接模块负责编译构建配置与链接脚本管理，确保编译选项和链接配置满足Mini芯片场景需求。

### Feature列表

| Feature名 | 说明 | 默认值 |
| -------- | -------- | -------- |
| ohos_stack_protector | 栈保护级别配置 | strong |
| ohos_mem_opt_extra | 是否使能额外内存优化 | true |

### Feature说明

- **ohos_stack_protector**：设置栈保护（Stack Protector）级别。可选值：
  - `strong`：强保护模式，为大部分函数插入栈保护代码，安全性高但略有性能开销
  - `all`：全保护模式，为所有函数插入栈保护代码
  - `none`：禁用栈保护

- **ohos_mem_opt_extra**：控制是否使能额外的内存优化选项。开启后编译器会进行更激进的内存优化（如优化内存布局、减少冗余分配），适用于RAM资源受限的Mini芯片场景。

### 使用方法

#### 1. 编译时配置Feature

通过编译参数`--gn-args`传入：

```bash
hb build --gn-args ohos_stack_protector=strong ohos_mem_opt_extra=true
```

#### 2. 链接脚本配置

**[待补充链接脚本的关键配置项与修改方法]**

---

## 相关能力

完成最小系统适配后，可根据产品需求选配以下子系统能力，以扩展芯片功能。各子系统均提供独立的移植指导文档，按需适配即可。

| 子系统 | 能力说明 | 典型用途 | 资源影响 | 移植指导 |
| -------- | -------- | -------- | -------- | -------- |
| 通信子系统 | 提供Wi-Fi Station/SoftAP、蓝牙等无线通信能力 | 设备联网、数据交互、配网 | 增加ROM约100KB+，RAM约20KB+ | [移植通信子系统](porting-minichip-subsys-communication.md) |
| 外设驱动子系统 | 提供GPIO、I2C、SPI、PWM、UART、FLASH、WATCHDOG等外设操作接口 | 传感器数据采集、外设控制、屏显驱动 | 按需引入，单接口增加ROM约2~10KB | [移植外设驱动子系统](porting-minichip-subsys-driver.md) |
| 文件子系统 | 提供文件打开、关闭、读写、Seek等操作接口 | 日志存储、配置持久化、数据记录 | 增加ROM约10KB+，RAM约2KB+ | [移植文件子系统](porting-minichip-subsys-filesystem.md) |
| 安全子系统 | 提供硬件随机数、密钥管理（huks）、设备认证（hichainsdk）等安全能力 | 安全连接、数据加密、设备鉴权 | 依赖mbedtls，增加ROM约50KB+ | [移植安全子系统](porting-minichip-subsys-security.md) |
| 分布式调度子系统 | 提供系统服务注册与发现能力（SAMGR框架），无需额外移植 | 跨设备组件管理、服务发现 | 少量RAM开销 | [配置其他子系统](porting-minichip-subsys-others.md) |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 上表资源影响为参考值，实际占用与芯片架构、编译器优化等级、使能的具体Feature有关。
> - 选配子系统时，请根据芯片实际ROM/RAM资源情况评估，确保不超过硬件限制。
> - 各子系统的详细移植步骤与接口定义，请参考对应的移植指导文档。

## 常见问题

**[待各模块补充FAQ]**

| 问题 | 所属模块 | 解决方案 |
| -------- | -------- | -------- |
| [待补充] | [待补充] | [待补充] |

## 参考配置

以下为典型 minimal 产品的参考配置，可供适配时参考：

| 芯片型号 | 产品路径 | 参考配置地址 |
| -------- | -------- | -------- |
| Hi3861 | hispark_pegasus | `vendor/hisilicon/hispark_pegasus_minimal/config.json` |
| Hi3863 | KHD-3863B | `vendor/hihope/nearlink_dk_3863_xts_minimal/config.json` |

## 参考文档

- [概述](porting-minichip-overview.md)
- [移植准备](porting-minichip-prepare.md)
- [移植内核](porting-minichip-kernel.md)
- [移植启动恢复子系统](porting-minichip-subsys-startup.md)
- [移植子系统概述](porting-minichip-subsys-overview.md)
- [配置其他子系统](porting-minichip-subsys-others.md)
- [三方库CMake适配](porting-thirdparty-cmake.md)
- [三方库Makefile适配](porting-thirdparty-makefile.md)
- [移植验证](porting-minichip-verification.md)
