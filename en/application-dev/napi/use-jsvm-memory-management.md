# Performing Memory Management Using JSVM-API

## Introduction

JSVM-API provides APIs for managing JavaScript virtual machine (JSVM) memory. With these APIs, you can better control the memory used by JS code and optimize memory management and garbage collection (GC) mechanisms.

## Basic Concepts

In JS, memory management and GC are performed automatically. The JSVM is responsible for tracking the allocation and release of objects and reclaiming the memory that is no longer required. However, if a JSVM consumes a large amount of memory, an out-of-memory error may occur. To prevent this type of errors, JSVM-API provides APIs to better control memory management and GC mechanisms.

## Available APIs

| API                      | Description                           |
|----------------------------|-------------------------------------|
| OH_JSVM_AdjustExternalMemory         | Manages the external allocated memory held by a JS object.|
| OH_JSVM_MemoryPressureNotification   | Notifies the VM of the memory pressure level and selectively triggers GC.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ and ArkTS code related to memory management.

### OH_JSVM_AdjustExternalMemory

Use **OH_JSVM_AdjustExternalMemory** to adjust the amount of externally allocated memory that is kept alive for a JS object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the AdjustExternalMemory callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = AdjustExternalMemory},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named adjustExternalMemory and associate it with a callback. This allows the AdjustExternalMemory callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"adjustExternalMemory", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
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
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `
   adjustExternalMemory()
  `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'adjustExternalMemory:%{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'adjustExternalMemory: %{public}s', error.message);
}
```

### OH_JSVM_MemoryPressureNotification

Use **OH_JSVM_MemoryPressureNotification** to notify the underlying JSVM that the VM system memory is insufficient and selectively trigger GC.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the MemoryPressureNotification callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = MemoryPressureNotification},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named memoryPressureNotification and associate it with a callback. This allows the MemoryPressureNotification callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"memoryPressureNotification", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
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
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `
   memoryPressureNotification();
  `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'memoryPressureNotification:%{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'memoryPressureNotification:%{public}s', error.message);
}
```
