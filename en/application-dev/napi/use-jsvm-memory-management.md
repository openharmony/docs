# Performing Memory Management Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Introduction

JSVM-API provides APIs for managing JavaScript virtual machine (JSVM) memory. With these APIs, you can better control the memory used by JS code and optimize memory management and garbage collection (GC) mechanisms.

## Basic Concepts

In JS, memory management and GC are performed automatically. The JSVM is responsible for tracking the allocation and release of objects and reclaiming the memory that is no longer required. However, if a JSVM consumes a large amount of memory, an out-of-memory error may occur. To prevent this type of errors, JSVM-API provides APIs to better control memory management and GC mechanisms.

## Available APIs

| API                      | Description                           |
|----------------------------|-------------------------------------|
| OH_JSVM_AdjustExternalMemory         | Manages the external allocated memory held by a JS object.|
| OH_JSVM_MemoryPressureNotification   | Notifies the underlying JSVM that the VM system memory is insufficient and selectively trigger GC.|

## Example

For details about the JSVM-API development process, see [Using JSVM-API to Implement Interactive Development Between JS and C/C++](use-jsvm-process.md). This document describes only the C++ and ArkTS code corresponding to the APIs.

### OH_JSVM_AdjustExternalMemory

Call **OH_JSVM_AdjustExternalMemory** to adjust the amount of externally allocated memory that is kept alive for a JS object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_AdjustExternalMemory.
static JSVM_Value AdjustExternalMemory(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Allocate 1 MB of memory.
    int64_t change = 1024 * 1024;
    int64_t adjustedValue = 0;
    JSVM_Status status = OH_JSVM_AdjustExternalMemory(env, change, &adjustedValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_AdjustExternalMemory: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_AdjustExternalMemory: success");
        OH_LOG_INFO(LOG_APP, "JSVM Allocate memory size: %{public}d", adjustedValue);
    }
    JSVM_Value checked;
    OH_JSVM_GetBoolean(env, true, &checked);
    return checked;
}
// Register the AdjustExternalMemory callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = AdjustExternalMemory},
};
static JSVM_CallbackStruct *method = param;
// Alias for the AdjustExternalMemory method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"adjustExternalMemory", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
```

JS Example

```c++
const char *srcCallNative = R"JS(adjustExternalMemory())JS";
```
<!-- @[oh_jsvm_adjust_external_memory](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/UsageInstructionsTwo/adjustexternalmemory/src/main/cpp/hello.cpp) -->
Output:
The following information is displayed in the log:
```cpp
JSVM OH_JSVM_AdjustExternalMemory: success
JSVM Allocate memory size: 1048576
```
### OH_JSVM_MemoryPressureNotification

Notifies the VM of insufficient system memory and selectively triggers garbage collection.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_MemoryPressureNotification.
static JSVM_Value MemoryPressureNotification(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Set the memory pressure level of the current JSVM.
    JSVM_Status status = OH_JSVM_MemoryPressureNotification(env, JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_MemoryPressureNotification: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_MemoryPressureNotification: success");
        OH_LOG_INFO(LOG_APP, "JSVM Current JSVM memory pressure level: %{public}d", JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL);
    }
    return nullptr;
}
// Register the MemoryPressureNotification callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = MemoryPressureNotification},
};
static JSVM_CallbackStruct *method = param;
// Alias for the MemoryPressureNotification method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"memoryPressureNotification", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
```

JS Example

```c++
const char *srcCallNative = R"JS(memoryPressureNotification())JS";
```
<!-- @[oh_jsvm_memory_pressure_notification](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/UsageInstructionsTwo/memorypressurenotification/src/main/cpp/hello.cpp) -->
Output:
The following information is displayed in the log:
```cpp
JSVM OH_JSVM_MemoryPressureNotification: success
JSVM Current JSVM memory pressure level: 2
```
