# 使用JSVM-API接口进行JavaScript代码调试调优

## 简介

这些JSVM-API接口涵盖了虚拟机实例检索、内存分析、性能剖析和调试支持，为优化代码性能及提升开发效率提供了有力的支持。

## 基本概念

- **JSVM**：JavaScript虚拟机是执行JavaScript代码的环境。它负责解析和执行JavaScript代码，管理内存，并提供与其他系统资源的交互。接口如OH_JSVM_GetVM用于检索特定环境的虚拟机实例，这是JSVM管理的基本操作之一。
- **调试（debug）**：调试是程序开发中的一项重要活动，它涉及到定位、分析和修复代码中的错误。OH_JSVM_OpenInspector和OH_JSVM_CloseInspector接口提供了在特定主机和端口上激活和关闭inspector的功能，inspector是一个用于调试JavaScript代码的工具，允许开发者实时查看和交互程序的运行状态。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_GetVM              |  将检索给定环境的虚拟机实例。 |
| OH_JSVM_GetHeapStatistics  |  返回一组虚拟机堆的统计数据。 |
| OH_JSVM_StartCpuProfiler   |  创建并启动一个CPU profiler。 |
| OH_JSVM_StopCpuProfiler    |  停止CPU profiler并将结果输出到流。 |
| OH_JSVM_TakeHeapSnapshot   |  获取当前堆快照并将其输出到流。 |
| OH_JSVM_OpenInspector      |  在指定的主机和端口上激活inspector，将用来调试JS代码。 |
| OH_JSVM_CloseInspector     |  尝试关闭剩余的所有inspector连接。 |
| OH_JSVM_WaitForDebugger    |  等待主机与inspector建立socket连接，连接建立后程序将继续运行。发送Runtime.runIfWaitingForDebugger命令。 |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### OH_JSVM_GetVM

将检索给定环境的虚拟机实例。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// GetVM注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetVM},
};
static JSVM_CallbackStruct *method = param;
// GetVM方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getVM", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_GetVM的样例方法
static JSVM_Value GetVM(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 获取当前虚拟机对象,后续可以进行与虚拟机相关的操作或分析
    JSVM_VM testVm;
    JSVM_Status status = OH_JSVM_GetVM(env, &testVm);
    JSVM_Value result = nullptr;
    if (status != JSVM_OK || testVm == nullptr) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetVM: failed");
        OH_JSVM_GetBoolean(env, true, &result);
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetVM: success");
        OH_JSVM_GetBoolean(env, false, &result);
    }
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string = `
    getVM()
`
let result = napitest.runJsVm(script);
hilog.info(0x0000, 'testJSVM', 'Test JSVM getVM: %{public}s', result);
```

### OH_JSVM_GetHeapStatistics

返回一组虚拟机堆的统计数据。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// GetHeapStatistics注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetHeapStatistics},
};
static JSVM_CallbackStruct *method = param;
// GetHeapStatistics方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getHeapStatistics", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_GetHeapStatistics的样例方法
void PrintHeapStatistics(JSVM_HeapStatistics result)
{
    OH_LOG_INFO(LOG_APP, "JSVM API heap totalHeapSize: %{public}zu", result.totalHeapSize);
    OH_LOG_INFO(LOG_APP, "JSVM API heap totalHeapSizeExecutable: %{public}zu", result.totalHeapSizeExecutable);
    OH_LOG_INFO(LOG_APP, "JSVM API heap totalPhysicalSize: %{public}zu", result.totalPhysicalSize);
    OH_LOG_INFO(LOG_APP, "JSVM API heap totalAvailableSize: %{public}zu", result.totalAvailableSize);
    OH_LOG_INFO(LOG_APP, "JSVM API heap usedHeapSize: %{public}zu", result.usedHeapSize);
    OH_LOG_INFO(LOG_APP, "JSVM API heap heapSizeLimit: %{public}zu", result.heapSizeLimit);
    OH_LOG_INFO(LOG_APP, "JSVM API heap mallocedMemory: %{public}zu", result.mallocedMemory);
    OH_LOG_INFO(LOG_APP, "JSVM API heap externalMemory: %{public}zu", result.externalMemory);
    OH_LOG_INFO(LOG_APP, "JSVM API heap peakMallocedMemory: %{public}zu", result.peakMallocedMemory);
    OH_LOG_INFO(LOG_APP, "JSVM API heap numberOfNativeContexts: %{public}zu", result.numberOfNativeContexts);
    OH_LOG_INFO(LOG_APP, "JSVM API heap numberOfDetachedContexts: %{public}zu", result.numberOfDetachedContexts);
    OH_LOG_INFO(LOG_APP, "JSVM API heap totalGlobalHandlesSize: %{public}zu", result.totalGlobalHandlesSize);
    OH_LOG_INFO(LOG_APP, "JSVM API heap usedGlobalHandlesSize: %{public}zu", result.usedGlobalHandlesSize);
}

static JSVM_Value GetHeapStatistics(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 获取当前虚拟机对象
    JSVM_VM testVm;
    OH_JSVM_GetVM(env, &testVm);
    // 获取虚拟机的堆统计信息
    JSVM_HeapStatistics result;
    OH_JSVM_GetHeapStatistics(testVm, &result);
    // 打印虚拟机堆统计信息
    PrintHeapStatistics(result);
    // 返回虚拟机堆统计信息中‘本机上下文数量’
    JSVM_Value nativeContextsCnt = nullptr;
    OH_JSVM_CreateInt64(env, result.numberOfNativeContexts, &nativeContextsCnt);
    return nativeContextsCnt;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string = `
    getHeapStatistics()
`
let numberOfNativeContexts = napitest.runJsVm(script);
hilog.info(0x0000, 'testJSVM', 'Test JSVM getHeapStatistics: %{public}s', numberOfNativeContexts);
```

以下接口的示例代码可以参考链接：

[JSVM调试调优能力](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/napi/jsvm-debugger-cpuprofiler-heapsnapshot.md)

### OH_JSVM_StartCpuProfiler

创建并启动一个CPU profiler。

### OH_JSVM_StopCpuProfiler

停止CPU profiler并将结果输出到流。

### OH_JSVM_TakeHeapSnapshot

获取当前堆快照并将其输出到流。

### OH_JSVM_OpenInspector

在指定的主机和端口上激活inspector，将用来调试JS代码。

### OH_JSVM_CloseInspector

尝试关闭剩余的所有inspector连接。

### OH_JSVM_WaitForDebugger

等待主机与inspector建立socket连接，连接建立后程序将继续运行。发送Runtime.runIfWaitingForDebugger命令。
