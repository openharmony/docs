# Comparing JS Values Using JSVM-API

## Introduction

This topic walks you through on how to use JSVM-API to check whether two JavaScript (JS) values are strictly equal (equal in both value and type). The API provided is equivalent to the JS strict equality operator (===).

## Basic Concepts

Strictly equal: If two values are strictly equal, they are equal in both value and type. When type conversion is considered, if the values being compared are of different types, **false** will be returned even if the values are the same.

## Available APIs

| API                      | Description                           |
|----------------------------|-------------------------------------|
| OH_JSVM_StrictEquals         | Checks whether two **JSVM_Value** objects are strictly equal. |

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ and ArkTS code related to the comparison.

### OH_JSVM_StrictEquals

Use **OH_JSVM_StrictEquals** to check whether two JS values are strictly equal.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the IsStrictEquals callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsStrictEquals},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named isStrictEquals and associate it with a callback. This allows the isStrictEquals callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"isStrictEquals", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_StrictEquals.
static JSVM_Value IsStrictEquals(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the input parameters.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Call OH_JSVM_StrictEquals to check whether two given JS values are strictly equal.
    bool result = false;
    JSVM_Status status = OH_JSVM_StrictEquals(env, args[0], args[1], &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_StrictEquals: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_StrictEquals: success: %{public}d", result);
    }
    JSVM_Value isStrictEqual;
    OH_JSVM_GetBoolean(env, result, &isStrictEqual);
    return isStrictEqual;
}
```

ArkTS code:

```ts
let script: string = `
    let data = '123';
    let value = 123;
    isStrictEquals(data,value);
`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'isStrictEquals: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'isStrictEquals: %{public}s', error.message);
}
```
