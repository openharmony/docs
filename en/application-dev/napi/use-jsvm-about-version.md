# Obtaining the JSVM-API Version Using JSVM-API

## Introduction

This topic walks you through on how to use JSVM-API to obtain the API version and VM information.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_GetVersion         | Obtains the latest JSVM API version supported by the JSVM runtime.|
| OH_JSVM_GetVMInfo          | Obtains the VM information.             |

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in using version-related APIs.

### OH_JSVM_GetVersion && OH_JSVM_GetVMInfo

Use **OH_JSVM_GetVersion && OH_JSVM_GetVMInfo** to obtain the latest JSVM API version supported by the current environment and the VM information.

CPP code:

```cpp
// hello.cpp
#include <string.h>

// Define OH_JSVM_GetVersion.
static JSVM_Value GetVersion(JSVM_Env env, JSVM_CallbackInfo info)
{
    uint32_t jsVersion = 0;
    // Obtain the latest JSVM API version supported by the current JSVM runtime.
    JSVM_CALL(OH_JSVM_GetVersion(env, &jsVersion));
    int value = static_cast<int>(jsVersion);
    OH_LOG_INFO(LOG_APP, "JSVM GetVersion success:%{public}d", value);
    return nullptr;
}

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
    JSVM_CALL(OH_JSVM_GetVMInfo(&result));
    // Output VM information.
    PrintVmInfo(result);
    return nullptr;
}

// JS code to be executed.
static const char *srcCallNative = R"JS(getVersion();getVMInfo();)JS";

// Register the GetVersion and GetVMInfo callbacks.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetVersion},
    {.data = nullptr, .callback = GetVMInfo},
};
static JSVM_CallbackStruct *method = param;
// Aliases of the GetVersion and GetVMInfo methods, which can be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getVersion", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"getVMInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
```
