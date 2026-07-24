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

| Feature名 | 说明 | 默认值 | 小型化建议值 |
| -------- | -------- | -------- | -------- |
| bootstrap_lite_enable_bootstrap_service | 是否使能Bootstrap服务任务 | true | false |
| init_lite_memory_size | 参数空间总大小（字节） | 15360 | 8192 |
| init_lite_param_const_value_len_max | 常量参数值的最大长度 | 4096 | 256 |
| init_lite_param_value_len_max | 参数值的最大长度 | 96 | 48 |
| init_lite_param_name_len_max | 参数名的最大长度 | 96 | 48 |
| init_lite_persist_all | 是否持久化所有参数 | true | false |
| acts_lite_param_value_len_max_48 | 是否将xts用例中value的值替换为48字节的字符串（兼容测试） | false | true |

### Feature说明

- **bootstrap_lite_enable_bootstrap_service**：控制是否使能Bootstrap服务任务。设为true时，bootstrap_service向samgr注册回调任务以触发INIT_APP_CALL，从而注册App级服务并异步推进启动流程；设为false时，由samgr直接调用INIT_APP_CALL，同步完成App级服务注册并推进启动流程。

- **init_lite_memory_size**：设置init模块参数空间总大小，默认15360字节。可根据实际需求调整该值。

- **init_lite_param_const_value_len_max**：设置常量参数值的最大允许长度，默认4096字节。可根据实际需求调整该值。

- **init_lite_param_value_len_max**：设置非常量参数值的最大允许长度，默认96字节。可根据实际需求调整该值。与`acts_lite_param_value_len_max_48`配合使用。

- **init_lite_param_name_len_max**：设置参数名的最大允许长度，默认96字节。可根据实际需求调整该值。

- **init_lite_persist_all**：控制是否将所有系统参数持久化存储。设为false时，仅持久化标记为persist的参数；设为true时，则持久化标记全部参数，会增加Flash写入开销。

- **acts_lite_param_value_len_max_48**：控制是否将xts用例中value的值替换为48字节的字符串。与`init_lite_param_value_len_max`配合使用的兼容性修改。默认false。

### 使用方法

#### 在config.json中添加启动子系统

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
}
```

> **说明：**
> `acts_lite_param_value_len_max_48`为兼容性测试相关Feature，在执行HCTEST时需按需配置。

---

## samgr-系统服务管理

系统服务管理子系统负责系统服务的注册、发现与统一管理，基于SAMGR框架实现服务的按需启动与生命周期管理。

### Feature列表

| Feature名 | 说明 | 默认值 | 小型化建议值 |
| -------- | -------- | -------- | -------- |
| enable_ohos_systemabilitymgr_samgr_lite_broadcast | 是否使能广播能力 | true | false |
| enable_ohos_systemabilitymgr_samgr_lite_system_capability | 是否使能系统能力 | true | false |
| config_ohos_systemabilitymgr_samgr_lite_shared_task_size | 共享任务栈大小（字节） | 2048 | 1024 |
| enable_ohos_systemabilitymgr_samgr_lite_specified_task | 是否使能指定任务模式 | true | false |
| enable_ohos_systemabilitymgr_samgr_lite_no_task | 是否使能无任务模式 | true | false |
| enable_ohos_test_xts_acts_use_samgr_lite_broadcast | 兼容性测试：是否使用广播能力 | true | false |
| enable_ohos_test_xts_acts_use_samgr_lite_debug | 兼容性测试：是否使能调试模式 | true | false |
| enable_ohos_test_xts_acts_use_samgr_lite_taskpool_notask | 兼容性测试：是否使用无任务池模式 | true | false |
| enable_ohos_test_xts_acts_use_samgr_lite_taskpool_specifiedtask | 兼容性测试：是否使用指定任务池模式 | true | false |

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

#### 在config.json中添加samgr子系统

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
}
```

#### SAMGR启动流程

`OHOS_SystemInit()`中调用`SAMGR_Bootstrap()`完成服务框架初始化，各服务通过zinitcall段注册：

```c
// SAMGR_Bootstrap() 会依次执行：
// 1. .zinitcall.app.serviceX.init 段 —— 注册系统服务
// 2. .zinitcall.app.featureX.init 段 —— 注册服务Feature
```

#### 兼容性测试Feature配置

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

| Feature名 | 所属部件 | 说明 | 默认值 | 小型化建议值 |
| -------- | -------- | -------- | -------- | -------- |
| hilog_lite_mini | hilog_lite | 是否使能轻量系统日志功能 | true | true |
| hievent_lite_mini | hievent_lite | 是否使能轻量系统事件日志输出功能 | true | true |
| hiview_lite_mini | hiview_lite | 是否使能轻量维测基础配置功能 | true | true |

### Feature说明

- **hilog_lite_mini**：控制hilog_lite部件在轻量系统下的使能。开启后仅提供轻量级日志输出能力，减少ROM和RAM占用。

- **hievent_lite_mini**：控制hievent_lite部件在轻量系统下的使能。开启后提供轻量级事件控制台日志输出能力。

- **hiview_lite_mini**：控制hiview_lite部件在轻量系统下的使能。为hilog_lite和hievent_lite模块提供基础配置和公共函数封装。hiview_lite_mini不可单独使能，hiview_lite_mini需要和hilog_lite_mini、hievent_lite_mini一起配合使用。

### 使用方法

#### 在config.json中添加DFX子系统

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
}
```

---

## HCTEST-测试框架

HCTEST为OpenHarmony兼容性测试框架，提供基本接口的测试验证能力，用于在适配完成后对工程进行兼容性测试。

### Feature列表

| Feature名 | 说明 | 默认值 | 小型化建议值 |
| -------- | -------- | -------- | -------- |
| hctest_rodata_opt | 是否开启测试套描述放.rodata | false | true |
| xts_overlay | 是否开启最小集测试.bss共享同一VMA | false | true |
| hctest_task_stack_size | 配置测试任务栈大小 | 6144 | 2048 |
| hctest_task_queue_size | 配置测试任务队列大小 | 20 | 1 |
| hctest_task_type | 配置测试任务类型 | `SINGLE_TASK` | `SHARED_TASK` |

### Feature说明

- **hctest_rodata_opt**：测试套件描述放在Flash(.rodata)减少RAM占用。使能后xts跑在独立线程。

- **xts_overlay**：多个测试模块的.bss复用同一块overlay区域，节省BSS。

- **hctest_task_stack_size**：配置TestService任务栈大小。

- **hctest_task_queue_size**：配置TestService任务队列大小，hctest_task_type为SHARED_TASK时此项不起作用。

- **hctest_task_type**：配置TestService任务类型，SINGLE_TASK或SHARED_TASK。

### 使用方法

#### 编译时配置HCTEST Feature

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
       "xts_overlay = true",
       "hctest_task_stack_size = 2048",
       "hctest_task_queue_size = 1",
       "hctest_task_type = SHARED_TASK"
    ] },
    { "component": "tools", "features":[] }
   ]
 },
```

#### 链接脚本适配

##### 开启 hctest_rodata_opt 需要的链接器适配

###### 链接脚本改动

在链接脚本的 Flash/rodata 区域内，为每个测试模块添加 KEEP 段 + 边界符号：

```ld
. = ALIGN(4);
xts_init_ActsBootstrapTest_start = .;
KEEP(*(.xts_init.ActsBootstrapTest))
xts_init_ActsBootstrapTest_stop = .;

. = ALIGN(4);
xts_init_ActsDfxFuncTest_start = .;
KEEP(*(.xts_init.ActsDfxFuncTest))
xts_init_ActsDfxFuncTest_stop = .;

/* ... 每个模块一组 ... */
 ```

###### 模块列表

必须与 test/xts/tools/lite/hctest/src/hctest.c 的 g_xtsModules[] 数组完全一致：

```bash
ActsBootstrapTest
ActsDfxFuncTest
ActsHieventLiteTest
ActsParameterTest
ActsSamgrTest
ActsKvStoreTest
ActsLwipTest
ActsHuksHalFunctionTest
ActsDeviceAttestTest
ActsUpdaterFuncTest
ActsWifiIotTest
ActsUtilsFileTest
```
> **说明：**
> 新增测试模块时，g_xtsModules[] 和链接脚本两处都要加。

##### 开启 xts_overlay 需要的链接器适配

###### .bss EXCLUDE_FILE

在链接脚本的 .bss 收集处，排除 5 个 overlay 模块的 .bss，使其落入下方的 OVERLAY 块：

```ld
*(EXCLUDE_FILE(*libmodule_ActsDfxFuncTest.a *libmodule_ActsHieventLiteTest.a
               *libmodule_ActsBootstrapTest.a *libmodule_ActsParameterTest.a
               *libmodule_ActsSamgrTest.a) .bss*)
```

###### OVERLAY 块

在 .bss 段之后、.heap 之前，创建 5 模块共享的 overlay 区域：

```ld
xts_overlay_start = .;
OVERLAY . :
{
    .xts_bss_ActsDfxFuncTest     { *libmodule_ActsDfxFuncTest.a:*(.bss*) }
    .xts_bss_ActsHieventLiteTest { *libmodule_ActsHieventLiteTest.a:*(.bss*) }
    .xts_bss_ActsBootstrapTest   { *libmodule_ActsBootstrapTest.a:*(.bss*) }
    .xts_bss_ActsParameterTest   { *libmodule_ActsParameterTest.a:*(.bss*) }
    .xts_bss_ActsSamgrTest       { *libmodule_ActsSamgrTest.a:*(.bss*) }
} > RAM
xts_overlay_end = .;
```

###### ASSERT 校验

每个子段必须 ≤ overlay 区域大小（最大的模块应放最后）：

```ld
ASSERT(xts_overlay_end - xts_overlay_start >= SIZEOF(.xts_bss_ActsDfxFuncTest), "XTS overlay error: reorder OVERLAY block")
/* ... 每个模块一条 ... */
```

###### 5个 overlay 模块

ActsDfxFuncTest、ActsHieventLiteTest、ActsBootstrapTest、ActsParameterTest、ActsSamgrTest。

OVERLAY 块中的 .a 文件名格式为 *libmodule_\<ModuleName\>.a，与 GN 编译 acts 测试模块时的 target 名一致。

##### Feature 隔离

###### Feature 说明

| Feature | 编译宏 | 作用 |
| -------- | -------- | -------- |
| xts_overlay | XTS_OVERLAY_ENABLE | 5 个测试模块 .bss 复用同一 VMA（overlay），省 BSS |
| hctest_rodata_opt | HCTEST_RODATA_OPT | 测试套描述 放 Flash(.rodata) + xts 跑独立线程 |
| （派生）任一开启 | HCTEST_NEW_RUNNER | 切换xts测试入口 + .xts_init 延迟注册机制 |

> **说明：**
> 两个 Feature 正交，可单独开启或同时开启。派生宏 HCTEST_NEW_RUNNER = xts_overlay OR hctest_rodata_opt。

如需支持 Feature 关闭时回到原始行为（链接脚本与未适配前一致），需要：
###### 链接脚本：用 #if defined() 包裹新增代码

```ld
/* .xts_init KEEP 段 */
#if defined(HCTEST_NEW_RUNNER)
    . = ALIGN(4);
    xts_init_ActsBootstrapTest_start = .;
    KEEP(*(.xts_init.ActsBootstrapTest))
    xts_init_ActsBootstrapTest_stop = .;
    /* ... */
#endif

/* .bss EXCLUDE_FILE */
#if defined(XTS_OVERLAY_ENABLE)
    *(EXCLUDE_FILE(*libmodule_ActsDfxFuncTest.a ...) .bss*)
#else
    *(.bss*)
#endif

/* OVERLAY 块 */
#if defined(XTS_OVERLAY_ENABLE)
    xts_overlay_start = .;
    OVERLAY . : { ... } > RAM
    xts_overlay_end = .;
    ASSERT(...)
#endif
```

###### 预处理器入口：条件化传递 -D宏

根据 GN Feature 状态条件传递-D宏。完整链路：

```bash
GN args (xts_overlay / hctest_rodata_opt)
  ↓ BUILD.gn 传递
hm_build.sh 参数 / 环境变量
  ↓ hm_build.sh 翻译
SDK 构建系统配置（config 文件 / 环境变量）
  ↓ SDK 构建系统读取
链接脚本预处理器 -D 标志（条件）
```

BUILD.gn：引入 Feature 声明，将值传入 hm_build.sh：

```gn
import("//test/xts/tools/lite/hctest/hctest_opt_args.gni")

if (xts_overlay) {
    overlay_arg = "xts_overlay"
} else {
    overlay_arg = "no_xts_overlay"
}
if (hctest_rodata_opt) {
    rodata_arg = "hctest_rodata_opt"
} else {
    rodata_arg = "no_hctest_rodata_opt"
}
command = "sh hm_build.sh $outdir linux $overlay_arg $rodata_arg"
```

hm_build.sh：根据参数决定是否写配置 / 导出环境变量：

```bash
# scons 系：写 usr_config.mk
if [ "$xts_overlay_arg" = "xts_overlay" ]; then
    echo "CONFIG_XTS_OVERLAY=y" >> "$usr_cfg"
fi
if [ "$xts_overlay_arg" = "xts_overlay" ] || [ "$hctest_rodata_arg" = "hctest_rodata_opt" ]; then
    echo "CONFIG_HCTEST_NEW_RUNNER=y" >> "$usr_cfg"
fi
```

```bash
# cmake 系：导出环境变量
if [ "$XTS_OVERLAY_ARG" = "true" ]; then
    export XTS_OVERLAY_ENABLE=true
fi
if [ "$XTS_OVERLAY_ARG" = "true" ] || [ "$HCTEST_RODATA_OPT_ARG" = "true" ]; then
    export HCTEST_NEW_RUNNER=true
fi
```

预处理器入口：条件添加 -D：

```bash
# scons 系 config.mk
ifeq ($(CONFIG_XTS_OVERLAY), y)
    LINK_SCRIPTS_FLAG += -DXTS_OVERLAY_ENABLE
endif
ifeq ($(CONFIG_HCTEST_NEW_RUNNER), y)
    LINK_SCRIPTS_FLAG += -DHCTEST_NEW_RUNNER
endif
```

```bash
# cmake 系 build_linker.cmake
if("$ENV{XTS_OVERLAY_ENABLE}" STREQUAL "true")
    list(APPEND LDS_DEFINES "-DXTS_OVERLAY_ENABLE")
endif()
if("$ENV{HCTEST_NEW_RUNNER}" STREQUAL "true")
    list(APPEND LDS_DEFINES "-DHCTEST_NEW_RUNNER")
endif()
```

scons 系还需在 common_env.py 注册 set_config 映射：

```bash
set_config('env_cfg', 'CONFIG_XTS_OVERLAY', 'y', ['-DXTS_OVERLAY_ENABLE'], 'link_scripts_flag', 'common')
set_config('env_cfg', 'CONFIG_HCTEST_NEW_RUNNER', 'y', ['-DHCTEST_NEW_RUNNER'], 'link_scripts_flag', 'common')
```

##### 3861 与 3863 已适配对比

| 环节 | 3861 (hi3861v100) | 3863 (ws63v100) |
| -------- | -------- | -------- |
| SDK 构建系统 | scons | cmake |
| 链接脚本 | device/soc/hisilicon/hi3861v100/sdk_liteos/build/link/link.ld.S | device/soc/hisilicon/ws63v100/sdk/drivers/boards/ws63/evb/linker/.../linker.prelds |
| 预处理器入口 | device/soc/hisilicon/hi3861v100/sdk_liteos/build/make_scripts/config.mk + device/soc/hisilicon/hi3861v100/sdk_liteos/build/scripts/common_env.py | device/soc/hisilicon/ws63v100/sdk/build/cmake/build_linker.cmake |
| BSS 段名 | .bss* | .bss + .bss* |
| RAM 段名 | RAM | SRAM |

##### 验证

```bash
# .xts_init KEEP 段符号（HCTEST_NEW_RUNNER 生效时）
nm <elf> | grep xts_init_Acts    # 每个模块的 _start/_stop 符号对

# OVERLAY 区域符号（XTS_OVERLAY_ENABLE 生效时）
nm <elf> | grep xts_overlay      # xts_overlay_start / xts_overlay_end
```

##### 注意事项

1. **模块列表同步**：链接脚本的 `.xts_init` 模块列表必须与 `hctest.c` 的 `g_xtsModules[]` 一致。新增测试模块时两处都要改。
2. **OVERLAY 模块顺序**：最大的模块应放最后，ASSERT 会检查每个子段 ≤ overlay 区域大小。
3. **BSS glob 语法**：不同 SDK 对 `.bss` 收集语法可能不同，EXCLUDE_FILE 写法需匹配本 SDK。
4. **RAM 段名**：OVERLAY 块的 `> RAM` / `> SRAM` 需匹配本 SDK 内存区域定义。

---

## 三方库

三方库模块，对thirdparty下mbedtls进行了算法feature化改造，以ws63产品为范例（当前仅适配了ws63），展现feature化对内存的影响。

> **说明：**
> 非必须，按需配置，当前对ws63内存无正面优化效果。

### 使用方法

#### Feature化生效

```bash
--gn-args mbedtls_featureized=true
```

#### Feature说明

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

#### 注意事项

算法间存在依赖关系，违反时编译失败。

若要在产品的bundle.json文件中通过配置的方式开启，需将对应的feature声明在bundle.json的features中。

---

## 编译链接

编译链接模块负责编译构建配置与链接脚本管理，确保编译选项和链接配置满足轻量系统芯片场景需求。

### Feature列表

| Feature名 | 说明 | 默认值 | 小型化建议值 |
| -------- | -------- | -------- | -------- |
| ohos_stack_protector | 栈保护级别配置，提供no和strong级别的配置，默认为""表示使用产品本身配置 | "" | strong |
| ohos_mem_opt_extra | 是否使能额外内存优化 | false | true |

### Feature说明

- **ohos_stack_protector**：设置栈保护（Stack Protector）级别。可选值：
  - `strong`：强保护模式，为大部分函数插入栈保护代码，安全性高但略有性能开销
  - `no`：无保护模式，内存优化最佳，安全性最低
  - `""`：使用产品本身配置

- **ohos_mem_opt_extra**：控制是否使能额外的内存优化选项。开启后编译器会进行更激进的内存优化（如优化内存布局、减少冗余分配），适用于RAM资源受限的轻量系统芯片场景。

### 使用方法

#### 编译时配置Feature

通过编译参数`--gn-args`传入：

```bash
hb build --gn-args ohos_stack_protector=strong ohos_mem_opt_extra=true
```

#### 链接脚本配置

参考hi3861与hi3863的minimal产品，在config.json中添加配置：

```json
"ohos_stack_protector=strong",
"ohos_mem_opt_extra=true"
```
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

> **说明：**
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
