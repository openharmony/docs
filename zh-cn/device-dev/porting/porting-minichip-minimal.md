# 轻量系统小型化适配指导

本文档面向轻量系统小型化适配场景，提供各核心模块Feature的说明与使用方法。

## 约束与限制

- 本文档适用于OpenHarmony轻量系统的小型化适配场景
- 目标芯片架构包括cortex-m、risc-v等系列
- 各模块Feature以config.json中的features配置项为入口进行裁剪与使能

## 整体架构

轻量系统小型化由以下核心模块组成：

| 模块 | 职责 |
| -------- | -------- |
| startup-启动恢复 | 提供启动引导功能以及系统参数管理能力 |
| samgr-系统服务管理 | 系统服务注册、发现与统一管理 |
| DFX | 可维可测能力，包括日志、事件打点等 |
| HCTEST-测试框架 | 兼容性测试框架，提供基本接口的测试验证能力 |
| 三方库 | 三方库mbedtls算法feature化改造（可配置功能，目前仅支持ws63平台） |
| 编译链接 | 编译构建配置与链接脚本管理 |

## 适配流程

**表1** 小型化适配步骤

| 步骤 | 说明 |
| -------- | -------- |
| 1. 适配准备 | 下载代码、搭建编译环境、熟悉编译构建框架 |
| 2. 模块适配 | 按本章各模块指导逐个适配startup、samgr、DFX、HCTEST、三方库、编译链接 |
| 3. 适配验证 | 使用HCTEST兼容性测试套件验证，并使用伙伴自有测试用例进行补充验证 |

---

## startup-启动恢复

在轻量系统中，startup包含两个模块：init和bootstrap_lite。init提供了系统属性设置、读取功能。bootstrap_lite提供了启动引导功能。

### Feature列表

| Feature名 | 说明 | 默认值 |
| -------- | -------- | -------- |
| bootstrap_lite_enable_bootstrap_service | 是否使能Bootstrap服务任务 | false |
| init_lite_memory_size | 参数空间总大小（字节） | 8192 |
| init_lite_param_const_value_len_max | 常量参数值的最大长度 | 256 |
| init_lite_param_value_len_max | 参数值的最大长度 | 48 |
| init_lite_param_name_len_max | 参数名的最大长度 | 48 |
| init_lite_persist_all | 是否持久化所有参数 | false |
| acts_lite_param_value_len_max_48 | 是否将xts用例中value的值替换为48字节的字符串（兼容测试） | true |

### Feature说明

- **bootstrap_lite_enable_bootstrap_service**：控制是否使能Bootstrap服务任务。设为true时，bootstrap_service向samgr注册回调任务以触发INIT_APP_CALL，从而注册App级服务并异步推进启动流程；设为false时，由samgr直接调用INIT_APP_CALL，同步完成App级服务注册并推进启动流程。

- **init_lite_memory_size**：设置init模块参数空间总大小，默认8192字节。若需要使用更多的参数，可根据实际需求增大该值。

- **init_lite_param_const_value_len_max**：设置常量参数值的最大允许长度，默认256字节。若需要使用更长的参数值，可根据实际需求增大该值。

- **init_lite_param_value_len_max**：设置非常量参数值的最大允许长度，默认48字节。若需要使用更长的参数值，可根据实际需求增大该值。与`acts_lite_param_value_len_max_48`配合使用。

- **init_lite_param_name_len_max**：设置参数名的最大允许长度，默认48字节。若需要使用更长的参数名，可根据实际需求增大该值。

- **init_lite_persist_all**：控制是否将所有系统参数持久化存储。默认false，仅持久化标记为persist的参数；设为true则持久化全部参数。开启后会增加Flash写入开销。

- **acts_lite_param_value_len_max_48**：控制是否将xts用例中value的值替换为48字节的字符串。与`init_lite_param_value_len_max`配合使用的兼容性修改。默认true。

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
> `acts_lite_param_value_len_max_48`为兼容性测试相关Feature，在执行HCTEST时需按需配置。

---

## samgr-系统服务管理

系统服务管理子系统负责系统服务的注册、发现与统一管理，基于SAMGR框架实现服务的按需启动与生命周期管理。

### Feature列表

| Feature名 | 说明 | 默认值 |
| -------- | -------- | -------- |
| enable_ohos_systemabilitymgr_samgr_lite_broadcast | 是否使能广播能力 | false |
| enable_ohos_systemabilitymgr_samgr_lite_system_capability | 是否使能系统能力 | false |
| config_ohos_systemabilitymgr_samgr_lite_shared_task_size | 共享任务栈大小（字节） | 2048 |
| enable_ohos_systemabilitymgr_samgr_lite_specified_task | 是否使能指定任务模式 | false |
| enable_ohos_systemabilitymgr_samgr_lite_no_task | 是否使能无任务模式 | false |
| enable_ohos_test_xts_acts_use_samgr_lite_broadcast | 兼容性测试：是否使用广播能力 | false |
| enable_ohos_test_xts_acts_use_samgr_lite_debug | 兼容性测试：是否使能调试模式 | false |
| enable_ohos_test_xts_acts_use_samgr_lite_taskpool_notask | 兼容性测试：是否使用无任务池模式 | false |
| enable_ohos_test_xts_acts_use_samgr_lite_taskpool_specifiedtask | 兼容性测试：是否使用指定任务池模式 | false |

### Feature说明

- **enable_ohos_systemabilitymgr_samgr_lite_broadcast**：控制SAMGR Lite是否提供广播（Broadcast）能力。广播能力允许服务向多个订阅者发布消息，适用于一对多的事件通知场景。开启后会增加内存占用。

- **enable_ohos_systemabilitymgr_samgr_lite_system_capability**：控制是否使能系统能力（System Capability）添加、查询功能。开启后，服务可查询系统中已注册的能力列表，支持服务的动态添加。

- **config_ohos_systemabilitymgr_samgr_lite_shared_task_size**：设置SAMGR Lite共享任务栈的大小，单位为字节。默认2048字节。当多个服务共享同一个任务线程运行时，需确保栈空间足够。若服务处理逻辑较复杂或调用层级较深，需适当增大该值。

- **enable_ohos_systemabilitymgr_samgr_lite_specified_task**：控制是否使能指定任务模式。开启后，服务可运行在指定的独立任务线程中，而非共享任务池。适用于对实时性或隔离性要求较高的服务。

- **enable_ohos_systemabilitymgr_samgr_lite_no_task**：控制是否使能无任务模式。开启后，服务不创建独立任务线程，由调用者线程直接执行服务逻辑。适用于轻量场景，可节省任务创建开销。

- **enable_ohos_test_xts_acts_use_samgr_lite_broadcast**：兼容性测试相关，控制测试用例是否依赖SAMGR Lite的广播能力。需与`enable_ohos_systemabilitymgr_samgr_lite_broadcast`配合使用。

- **enable_ohos_test_xts_acts_use_samgr_lite_debug**：兼容性测试相关，控制是否使能SAMGR Lite调试模式，输出更多调试信息。

- **enable_ohos_test_xts_acts_use_samgr_lite_taskpool_notask**：兼容性测试相关，开启后，测试用例测试无任务池接口，需与`enable_ohos_systemabilitymgr_samgr_lite_no_task`配合使用。

- **enable_ohos_test_xts_acts_use_samgr_lite_taskpool_specifiedtask**：兼容性测试相关，开启后，测试用例测试指定任务池接口，需与`enable_ohos_systemabilitymgr_samgr_lite_specified_task`配合使用。

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

#### 3. 兼容性测试Feature配置

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
| hilog_lite_mini | hilog_lite | 是否使能轻量系统日志功能 | true |
| hievent_lite_mini | hievent_lite | 是否使能轻量系统事件日志输出功能 | true |
| hiview_lite_mini | hiview_lite | 是否使能轻量维测基础配置功能 | true |

### Feature说明

- **hilog_lite_mini**：控制hilog_lite部件在轻量系统下的使能。开启后仅提供轻量级日志输出能力，减少ROM和RAM占用。

- **hievent_lite_mini**：控制hievent_lite部件在轻量系统下的使能。开启后提供轻量级事件控制台日志输出能力。

- **hiview_lite_mini**：控制hiview_lite部件在轻量系统下的使能。为hilog_lite和hievent_lite模块提供基础配置和公共函数封装。hiview_lite_mini不可单独使能，hiview_lite_mini需要和hilog_lite_mini、hievent_lite_mini一起配合使用。

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

---

## HCTEST-测试框架

HCTEST为OpenHarmony兼容性测试框架，提供基本接口的测试验证能力，用于在适配完成后对工程进行兼容性测试。

### Feature列表

| Feature名 | 说明 | 默认值 |
| -------- | -------- | -------- |
| hctest_rodata_opt | 是否开启测试套描述放.rodata | false |
| xts_overlay | 是否开启最小集测试.bss共享同一VMA | false |
| hctest_task_stack_size | 配置测试任务栈大小 | 6144 |
| hctest_task_queue_size | 配置测试任务队列大小 | 20 |
| hctest_task_type | 配置测试任务类型 | `SINGLE_TASK` |

### Feature说明

- **hctest_rodata_opt**：测试套件描述放在Flash(.rodata)减少RAM占用。使能后xts跑在独立线程。

- **xts_overlay**：多个测试模块的.bss复用同一块overlay区域，节省BSS。


### 使用方法

#### 1. 编译时配置HCTEST Feature

HCTEST的Feature通过编译参数`--gn-args`传入，也可以通过config.json中的features字段开启：

 ```bash
hb build --gn-args hctest_rodata_opt=true xts_overlay=true hctest_task_stack_size=2048 hctest_task_queue_size=1 'hctest_task_type="SHARED_TASK"'
 ```

 config.json配置方法参考 vendor/hisilicon/hispark_pegasus_minimal/config.json
 ```json
 {
   "subsystem": "xts",
   "components": [
     { "component": "acts", "features":[
        "enable_ohos_test_xts_acts_use_thirdparty_lwip = false",
        "hctest_rodata_opt = true",
        "xts_overlay = false",
        "hctest_task_stack_size = 2048",
        "hctest_task_queue_size = 1",
        "hctest_task_type = SHARED_TASK"
     ] },
     { "component": "tools", "features":[] }
    ]
  },
 ```

#### 2. 链接脚本配置

参考hi3861与hi3863的minimal产品
添加配置
"ohos_stack_protector=strong",
"ohos_mem_opt_extra=true"
- 3861：
  - vendor/hisilicon/hispark_pegasus_minimal/config.json
  - product_wifiiot_hispark_pegasus_minimal的features
- 3863：
  - vendor/hihope/nearlink_dk_3863_xts_minimal/config.json
  - product_nearlink_dk_3863_xts_minimal的features

#### 3. 链接脚本适配

当开启HCTEST的hctest_rodata_opt或xts_overlay时，需在板侧链接脚本中完成对应的段布局适配。本节给出与板无关的适配契约、两种典型构建系统的差异、链接脚本逐处改法及约束。参考实现为hi3861（scons/make，模板build/link/link.ld.S）与hi3863/ws63（cmake，模板`drivers/boards/.../linker.prelds）两份补丁，目标板可参照构建系统相近的一份适配。

##### 1. 适配契约：flag 传递链

所有板侧都必须复刻如下传递链，确保开关从GN构建参数一路到达链接脚本预处理器：

```bash
GN args: xts_overlay / hctest_rodata_opt            （由 hctest_opt_args.gni 的 declare_args() 声明）
   │   BUILD.gn 将 args 序列化为构建脚本能读取的信道
   ▼
hm_build.sh: 读取 args → 变量名转译 + HCTEST_NEW_RUNNER 析取 → 写入/导出板侧配置
   │
   ▼
链接脚本预处理器: 接收 -DXTS_OVERLAY_ENABLE / -DHCTEST_NEW_RUNNER
   │   （cpp -P -E 预处理模板，生成最终 .lds）
   ▼
链接脚本模板: #if defined(...) 条件包含 OVERLAY 段 / .xts_init KEEP / .bss EXCLUDE_FILE
 ```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 全链路必须以#if defined(...)/if (... STREQUAL "true")/ifeq(...,y)门控。所有flag关闭时，预处理产出的链接脚本应与未适配构建逐字节一致，以保证对现有工程零回归。若任一段链路断裂，宏无法到达模板，#if defined()永不成立，会静默退化为"不开优化"状态——无报错但无收益，需特别排查。

**表2** 两种构建系统的 flag 链形状

| 链路段 | scons / make（参考 hi3861） | cmake（参考 hi3863/ws63） |
| -------- | -------- | -------- |
| GN → shell | BUILD.gn将arg作为hm_build.sh的位置参数传入（第3/4参数，值为xts_overlay/no_xts_overlay字面量） | BUILD.gn将arg拼入build_env字符串（XTS_OVERLAY_ARG=${xts_overlay}，值为true/false） |
| shell → 预处理器 | hm_build.sh改写build/config/usr_config.mk，写入CONFIG_XTS_OVERLAY=y/CONFIG_HCTEST_NEW_RUNNER=y；由common_env.py的set_config(...,'link_scripts_flag',...)翻译为-D宏，config.mk以ifeq加入LINK_SCRIPTS_FLAG | hm_build.sh直接export XTS_OVERLAY_ENABLE=true；build_linker.cmake读取$ENV{...}加入LDS_DEFINES |
| 预处理器 | scons以LINK_SCRIPTS_FLAG中的-D预处理link.ld.S | cmake以CMAKE_C_COMPILER -P -E+LDS_DEFINES预处理linker.prelds |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 变量名转译与析取合并是hm_build.sh的职责（GN侧无法表达跨两个arg的析取）。HCTEST_NEW_RUNNER不单独对应一个GN arg，而是xts_overlay OR hctest_rodata_opt的运行时副作用合并，须在shell中以||表达。

##### 2. 链接脚本逐处适配

###### 1. rodata优化：.xts_init KEEP块（门控HCTEST_NEW_RUNNER）

插入位置：.rodata段内，紧跟现有*(.rodata*)之后、段尾对齐符号之前。

```bash
#if defined(HCTEST_NEW_RUNNER)
        . = ALIGN(4);
        xts_init_<Module>_start = .;
        KEEP(*(.xts_init.<Module>))
        xts_init_<Module>_stop = .;
        /* 对每个 XTS 模块重复上述三行 */
#endif  /* HCTEST_NEW_RUNNER */
```

适配要求：
 - 模块名契约（硬约束）：<Module>及xts_init_<Module>_start/stop符号名必须与共享hctest.c中的XTS_MODULE_LINKER_SYMS列表逐字一致。符号名错一个即导致该模块注册失败、运行时找不到入口。适配前请先读取hctest.c取得实际列表，勿直接照抄参考补丁。
 - 建议列全量模块：参考补丁列出12个模块（ActsBootstrapTest/ActsDfxFuncTest/ActsHieventLiteTest/ActsParameterTest/ActsSamgrTest/ActsKvStoreTest/ActsLwipTest/ActsHuksHalFunctionTest/ActsDeviceAttestTest/ActsUpdaterFuncTest/ActsWifiIotTest/ActsUtilsFileTest）。未实际编译的模块其.xts_init.<Module>段为空，KEEP空段无害；列出全量可避免将来扩展acts时反复改脚本。
 - 必须置于.rodata（Flash/XIP只读区）：函数指针运行时只读，放Flash可节省RAM，由XIP直接读取。切勿放.data。
 - KEEP不可省略：否则--gc-sections会将未被静态引用的指针表作为未引用段回收，运行时_stop - _start == 0，全部模块注册失败。
 - 整段以#if defined(HCTEST_NEW_RUNNER)包裹：关闭时不产生任何符号与段，保证预处理产物与原构建一致。

###### 2. bss overlay：.bss段 EXCLUDE_FILE（门控XTS_OVERLAY_ENABLE）

插入位置：主.bss段内，替换原有*(.bss) *(.bss*)。

scons/make写法（带SORT）：
```bash
#if defined(XTS_OVERLAY_ENABLE)
        SORT(*)(EXCLUDE_FILE(*libmodule_ActsDfxFuncTest.a *libmodule_ActsHieventLiteTest.a *libmodule_ActsBootstrapTest.a *libmodule_ActsParameterTest.a *libmodule_ActsSamgrTest.a) .bss*)
#else
        SORT(*)(.bss*)
#endif
```

cmake写法（.bss与.bss*分列，EXCLUDE_FILE各自重复）：
```bash
#if defined(XTS_OVERLAY_ENABLE)
        *(EXCLUDE_FILE(*libmodule_ActsDfxFuncTest.a *libmodule_ActsHieventLiteTest.a *libmodule_ActsBootstrapTest.a *libmodule_ActsParameterTest.a *libmodule_ActsSamgrTest.a) .bss)
        *(EXCLUDE_FILE(*libmodule_ActsDfxFuncTest.a *libmodule_ActsHieventLiteTest.a *libmodule_ActsBootstrapTest.a *libmodule_ActsParameterTest.a *libmodule_ActsSamgrTest.a) .bss*)
#else
        *(.bss)
        *(.bss*)
#endif
```

适配要求：

 - 被排除的模块集 = 实际同时链接进固件的minimal集：参考补丁使用5个模块（ActsDfxFuncTest/ActsHieventLiteTest/ActsBootstrapTest/ActsParameterTest/ActsSamgrTest）。若目标板minimal集不同，EXCLUDE_FILE、OVERLAY子段、ASSERT三处的模块列表必须同步修改并保持一致，三者不一致将导致链接错乱。
 - .sbss*与COMMON必须保留在主.bss（架构硬约束）：.sbss为RISC-V gp相对寻址小数据段，必须位于_gp_（在.data中设置）附近；移入OVERLAY将破坏gp寻址语义，导致链接失败或运行时访问错误地址。COMMON在-fno-common下为空，保留原位为无害占位。若目标板无gp寻址机制，该约束可放宽，但默认保留原位最为安全。
 - EXCLUDE_FILE文件匹配：*libmodule_<Module>.a匹配该模块静态库的全部.bss*。注意不同构建系统下EXCLUDE_FILE的写法差异，请沿用目标板已有的EXCLUDE_FILE风格。
 - #else分支必须保留原*(.bss) *(.bss*)：关闭时与原脚本一致。

###### 3. bss overlay：OVERLAY段（门控XTS_OVERLAY_ENABLE）

插入位置：主.bss段结束之后、.heap之前（参考补丁置于_end = .;/__bss_size__定义之后）。

```bash
#if defined(XTS_OVERLAY_ENABLE)
      xts_overlay_start = .;
      OVERLAY . :
      {
          .xts_bss_<M1> { *libmodule_<M1>.a:*(.bss*) }
          .xts_bss_<M2> { *libmodule_<M2>.a:*(.bss*) }
          /* ... */
          .xts_bss_<M_last> { *libmodule_<M_last>.a:*(.bss*) }   /* .bss 最大的模块必须排在最后 */
      } > <RAM 或 SRAM，须与主 .bss 同区>
      xts_overlay_end = .;
      ASSERT(xts_overlay_end - xts_overlay_start >= SIZEOF(.xts_bss_<M1>), "XTS overlay error: <M1> > last module, reorder OVERLAY block")
      /* 对每个模块重复 ASSERT */
#endif  /* XTS_OVERLAY_ENABLE */
```

适配要求：
 - GNU ld OVERLAY语义：块内子段共享同一VMA，LMA依次排列；区域大小等于最后一个列出子段的大小（非各子段之和，亦非最大值）。
 - 最大模块必须排在末尾（锚定）：因区域大小取最后一个子段，必须将.bss最大的模块置于OVERLAY列表末尾，否则该模块运行时被截断、丢失数据。ASSERT为编译期安全网：若某模块.bss大于区域（即大于最后一个子段），ASSERT失败并提示重排。
 - xts_overlay_start/xts_overlay_end为运行时契约符号：hctest.c须以extern声明并在切换模块前清零[start, end)区间，使下一模块获得零初始化的.bss（C静态变量零初始化语义）。符号名不可更改。
 - > <区>必须与主.bss同区：VMA重叠合法的前提。区名按目标板memory region定义填写（参考板为RAM/SRAM）。
 - 仅适用于顺序执行的模块：XTS一次仅运行一个模块，共享.bss安全。不得对会并发执行的模块使用overlay。
 - 整段以#if defined包裹（含ASSERT）：关闭时不产生该段。

**表3** 内存区名对照

| 项 | hi3861 | hi3863/ws63 |
| -------- | -------- | -------- |
| .xts_init所在只读段 | .rodata，Flash（NON_ROM_TEXT_REGION） | .rodata/flashtext，PROGRAM（Flash，XIP） |
| OVERLAY区所在内存区 | > RAM | > SRAM |
| 主.bss所在区 | RAM | SRAM |

KEEP块须落在真正Flash/XIP只读区；OVERLAY须落在.bss所在可读写RAM区且与主.bss同区。

适配步骤

> 1. 读取hctest.c取得XTS_MODULE_LINKER_SYMS实际列表，确定.xts_init KEEP块的模块与符号命名。
> 2. 确定minimal实编模块集，确定EXCLUDE_FILE/OVERLAY/ASSERT三处列出的模块（三处须一致）。
> 3. 识别构建系统，按表2对应列复刻flag链三段（GN → shell → 预处理器）。
> 4. 定位链接脚本模板与.rodata/.bss/内存区名，按上文修改链接脚本。
> 5. 测量各模块.bss大小（map文件或size工具），将最大模块排到OVERLAY末尾，确保ASSERT编译期通过。
> 6. 关闭flag验证零回归：不开启flag完整编译，比对预处理产物（linker.lds/预处理后.lds）与未适配构建一致。
> 7. 开启flag实编译并烧录全量验证，按下文约束逐项确认。

---

## 三方库

三方库模块，对thirdparty下mbedtls进行了算法feature化改造，以ws63产品为范例（当前仅适配了ws63），展现feature化对内存的影响。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 非必须，按需配置，当前对ws63内存无正面优化效果。

### 使用方法

#### 1. Feature化生效

```bash
--gn-args mbedtls_featureized=true
```

#### 2. Feature说明

- 在third_party/mbedtls/mbedtls_feature.gni中配置了算法相关feature，
- 通过 --gn-args mbedtls_feature_xxx = true的方式可开启
- 以下为ws63上使用feature化的示例
  - ws63切换mbedtls使用的源：
    - 一些产品使用了自己sdk特化的mbedtls，需先行切换
    - （是否要切换到thirdparty下的，可根据实际判断，mbedtls_ohos_switch当前仅适配了ws63）
    - --gn-args mbedtls_ohos_switch=true
    - --gn-args 'huks_dependency_mbedtls_path="//third_party/mbedtls"'
    - --gn-args mbedtls_featureized=true
    - 编译全量xts，需额外开启：
    - --gn-args mbedtls_feature_x509=true
    - --gn-args mbedtls_feature_ssl_tls12=true
    - --gn-args mbedtls_feature_ssl_misc=true
    - ws63的minimal产品暂不使用mbedtls

#### 3. 注意事项

算法间存在依赖关系，违反时编译失败；
若要在产品的bundle.json文件中通过配置的方式开启，需将对应的feature声明在bundle.json的features中。

---

## 编译链接

编译链接模块负责编译构建配置与链接脚本管理，确保编译选项和链接配置满足轻量系统芯片场景需求。

### Feature列表

| Feature名 | 说明 | 默认值 |
| -------- | -------- | -------- |
| ohos_stack_protector | 栈保护级别配置，提供no和strong级别的配置，默认为""表示使用产品本身配置 | "" |
| ohos_mem_opt_extra | 是否使能额外内存优化 | false |

### Feature说明

- **ohos_stack_protector**：设置栈保护（Stack Protector）级别。可选值：
  - `strong`：强保护模式，为大部分函数插入栈保护代码，安全性高但略有性能开销
  - `no`：无保护模式，内存优化最佳，安全性最低
  - `""`：使用产品本身配置

- **ohos_mem_opt_extra**：控制是否使能额外的内存优化选项。开启后编译器会进行更激进的内存优化（如优化内存布局、减少冗余分配），适用于RAM资源受限的轻量系统芯片场景。

### 使用方法

#### 1. 编译时配置Feature

通过编译参数`--gn-args`传入：

```bash
hb build --gn-args ohos_stack_protector=strong ohos_mem_opt_extra=true
```

#### 2. 链接脚本配置

参考hi3861与hi3863的minimal产品
添加配置
"ohos_stack_protector=strong",
"ohos_mem_opt_extra=true"
- 3861：
  - vendor/hisilicon/hispark_pegasus_minimal/config.json
  - product_wifiiot_hispark_pegasus_minimal的features
- 3863：
  - vendor/hihope/nearlink_dk_3863_xts_minimal/config.json
  - product_nearlink_dk_3863_xts_minimal的features

---

## 相关能力

完成最小系统适配后，可根据产品需求选配以下子系统能力，以扩展芯片功能。各子系统均提供独立的移植指导文档，按需适配即可。

| 子系统 | 能力说明 | 典型用途 | 资源影响 | 移植指导 |
| -------- | -------- | -------- | -------- | -------- |
| 通信子系统 | 提供Wi-Fi Station/SoftAP、蓝牙等无线通信能力 | 设备联网、数据交互、配网 | 增加ROM约100KB+，RAM约20KB+ | [移植通信子系统](porting-minichip-subsys-communication.md) |
| 外设驱动子系统 | 提供GPIO、I2C、SPI、PWM、UART、FLASH、WATCHDOG等外设操作接口 | 传感器数据采集、外设控制、屏显驱动 | 按需引入，单接口增加ROM约2~10KB | [移植外设驱动子系统](porting-minichip-subsys-driver.md) |
| 文件子系统 | 提供文件打开、关闭、读写、Seek等操作接口 | 日志存储、配置持久化、数据记录 | 增加ROM约10KB+，RAM约2KB+ | [移植文件子系统](porting-minichip-subsys-filesystem.md) |
| 安全子系统 | 提供硬件随机数、密钥管理（huks）、设备认证（hichainsdk）等安全能力 | 安全连接、数据加密、设备鉴权 | 依赖mbedtls，增加ROM约50KB+ | [移植安全子系统](porting-minichip-subsys-security.md) |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 上表资源影响为参考值，实际占用与芯片架构、编译器优化等级、使能的具体Feature有关。
> - 选配子系统时，请根据芯片实际ROM/RAM资源情况评估，确保不超过硬件限制。
> - 各子系统的详细移植步骤与接口定义，请参考对应的移植指导文档。

## 参考配置

以下为典型 minimal 产品的参考配置，可供适配时参考：

| 芯片型号 | 产品路径 | 参考配置地址 |
| -------- | -------- | -------- |
| Hi3861 | hispark_pegasus_minimal | `vendor/hisilicon/hispark_pegasus_minimal/config.json` |
| Hi3863 | nearlink_dk_3863_xts_minimal | `vendor/hihope/nearlink_dk_3863_xts_minimal/config.json` |

## 参考文档

- [概述](porting-minichip-overview.md)
- [移植准备](porting-minichip-prepare.md)
- [移植内核](porting-minichip-kernel.md)
- [移植子系统概述](porting-minichip-subsys-overview.md)
- [移植启动恢复子系统](porting-minichip-subsys-startup.md)
- [配置其他子系统](porting-minichip-subsys-others.md)
- [三方库CMake适配](porting-thirdparty-cmake.md)
- [三方库Makefile适配](porting-thirdparty-makefile.md)
- [移植验证](porting-minichip-verification.md)
