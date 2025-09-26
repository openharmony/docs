# Debugging and Profiling JS Code Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Introduction

JSVM-API provide APIs for retrieving JavaScript virtual machine (JSVM) instances and performing memory analysis, profiling, and debugging, which facilitates code optimization and improves development efficiency.

## Basic Concepts

- JSVM: A JSVM is an environment for executing JavaScript (JS) code. It parses and executes JS code, manages memory, and provides interaction with other system resources. For example, you can use **OH_JSVM_GetVM** to retrieve JSVM instances in a specific environment. This is one of the basic JSVM management operations.
- Debug: As an important activity in program development, debugging involves locating, analyzing, and rectifying code errors. For example, you can use **OH_JSVM_OpenInspector** to open inspector, a tool used to debug JS code, on a host and port and view the running status of an application on a real-time basis. You can use **OH_JSVM_CloseInspector** to close inspector.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_GetVM              |  Obtains a VM instance.|
| OH_JSVM_GetHeapStatistics  |  Obtains heap statistics of a VM.|
| OH_JSVM_StartCpuProfiler   |  Creates and starts a CPU profiler instance.|
| OH_JSVM_StopCpuProfiler    |  Stops the CPU profiler and outputs the result to a stream.|
| OH_JSVM_TakeHeapSnapshot   |  Obtains a snapshot of the current heap and outputs it to a stream.|
| OH_JSVM_OpenInspector      |  Opens an inspector instance on the specified host and port for debugging JS code.|
| OH_JSVM_OpenInspectorWithName | Opens an inspector instance based on the PID and name.|
| OH_JSVM_CloseInspector     |  Closes all remaining inspector connections.|
| OH_JSVM_WaitForDebugger    |  Waits for the host to set up a socket connection with an inspector. After the connection is set up, the application continues to run. You can use **Runtime.runIfWaitingForDebugger** to run paused targets.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in the APIs.

### OH_JSVM_GetVM

Retrieves VM instances in an environment.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// Define OH_JSVM_GetVM.
static JSVM_Value GetVM(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain a VM instance for subsequent VM-related operations or analysis.
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
// Register the GetVM callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetVM},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getVM and associate it with a callback. This allows the GetVM callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getVM", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
```

JS example:

```c++
const char *srcCallNative = R"JS(getVM())JS";
```
<!-- @[oh_jsvm_get_vm](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/UsageInstructionsTwo/getvm/src/main/cpp/hello.cpp) -->

Expected result:
```
JSVM OH_JSVM_GetVM: success
```

### OH_JSVM_GetHeapStatistics

Obtains heap statistics of a VM.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// Define OH_JSVM_GetHeapStatistics.
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
    // Obtain the VM instance.
    JSVM_VM testVm;
    OH_JSVM_GetVM(env, &testVm);
    // Obtain the heap statistics of the VM.
    JSVM_HeapStatistics result;
    OH_JSVM_GetHeapStatistics(testVm, &result);
    // Print VM heap statistics.
    PrintHeapStatistics(result);
    // Return the number of local contexts in the VM heap statistics.
    JSVM_Value nativeContextsCnt = nullptr;
    OH_JSVM_CreateInt64(env, result.numberOfNativeContexts, &nativeContextsCnt);
    return nativeContextsCnt;
}
// Register the GetHeapStatistics callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetHeapStatistics},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getHeapStatistics and associate it with a callback. This allows the GetHeapStatistics callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getHeapStatistics", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
```

JS example:

```c++
const char *srcCallNative = R"JS(getHeapStatistics())JS";
```
<!-- @[oh_jsvm_get_heap_statistics](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/UsageInstructionsTwo/getheapstatistics/src/main/cpp/hello.cpp) -->
Expected result:
```
JSVM API heap totalHeapSize: 1597440
JSVM API heap totalHeapSizeExecutable: 0
JSVM API heap totalPhysicalSize: 1323008
JSVM API heap totalAvailableSize: 1519203688
JSVM API heap usedHeapSize: 178256
JSVM API heap heapSizeLimit: 1518338048
JSVM API heap mallocedMemory: 32848
JSVM API heap externalMemory: 0
JSVM API heap peakMallocedMemory: 40960
JSVM API heap numberOfNativeContexts: 1
JSVM API heap numberOfDetachedContexts: 0
JSVM API heap totalGlobalHandlesSize: 8192
JSVM API heap usedGlobalHandlesSize: 32
```

For details about the sample code of the previous APIs, see:

[JSVM-API Debugging](./jsvm-debugger-cpuprofiler-heapsnapshot.md)

### OH_JSVM_StartCpuProfiler

Creates and starts a CPU profiler instance.

### OH_JSVM_StopCpuProfiler

Stops the CPU profiler and output the result to a stream.

### OH_JSVM_TakeHeapSnapshot

Obtains the current heap snapshot and outputs it to the stream.

### OH_JSVM_OpenInspector

Opens an inspector instance on a specified host and port for debugging JS code.

### OH_JSVM_CloseInspector

Closes all remaining inspector connections.

### OH_JSVM_WaitForDebugger

Waits for the host to set up a socket connection with the inspector. After the connection is set up, the application continues to run and sends the **Runtime.runIfWaitingForDebugger** command.
