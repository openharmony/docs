# Obtaining the JSVM API Version Using JSVM-API

## Introduction

This topic walks you through on how to use JSVM-API to obtain the API version and VM information.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_GetVersion         | Obtains the latest JSVM API version supported by the JSVM runtime. |
| OH_JSVM_GetVMInfo          | Obtains the VM information.             |

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ and ArkTS code related to version management.

### OH_JSVM_GetVersion

Use **OH_JSVM_GetVersion** to obtain the latest JSVM API version supported by the JSVM runtime.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetVersion callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetVersion},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getVersion and associate it with a callback. This allows the GetVersion callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getVersion", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetVersion.
static JSVM_Value GetVersion(JSVM_Env env, JSVM_CallbackInfo info)
{
    uint32_t jsVersion = 0;
    // Obtain the latest JSVM API version supported by the current JSVM runtime.
    JSVM_Status status = OH_JSVM_GetVersion(env, &jsVersion);
    JSVM_Value result = nullptr;
    OH_JSVM_CreateUint32(env, jsVersion, &result);
    int value = static_cast<int>(jsVersion);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetVersion fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetVersion success:%{public}d", value);
    }
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `
    getVersion()
`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getVersion: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getVersion error: %{public}s', error.message);
}
```

### OH_JSVM_GetVMInfo

Use **OH_JSVM_GetVMInfo** to obtain VM information.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetVMInfo callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetVMInfo},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named GetVMInfo and associate it with a callback. This allows the GetVMInfo callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getVMInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetVMInfo.
// Print the JSVM information.
void PrintVmInfo(JSVM_VMInfo vmInfo) {
    OH_LOG_INFO(LOG_APP, "JSVM API apiVersion: %{public}d", vmInfo.apiVersion);
    OH_LOG_INFO(LOG_APP, "JSVM API engine: %{public}s", vmInfo.engine);
    OH_LOG_INFO(LOG_APP, "JSVM API version: %{public}s", vmInfo.version);
    OH_LOG_INFO(LOG_APP, "JSVM API cachedDataVersionTag: 0x%{public}x", vmInfo.cachedDataVersionTag);
}
static JSVM_Value GetVMInfo(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the VM information.
    JSVM_VMInfo result;
    OH_JSVM_GetVMInfo(&result);
    // Obtain the latest API version supported by the VM and print the information.
    JSVM_Value version = nullptr;
    OH_JSVM_CreateUint32(env, result.apiVersion, &version);
    // Output VM information.
    PrintVmInfo(result);
    return version;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `
    getVMInfo()
`
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getVMInfo apiVersion: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getVMInfo error: %{public}s', error.message);
}
```
