# Comparing JS Values Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Introduction

The function in JSVM-API is used to determine whether two JavaScript values are strictly equal, which is similar to the `===` operator in JavaScript. This function avoids type conversion and loose equality comparison to ensure that values and types are equal.

## Basic Concepts

Strictly equal: If two values are strictly equal, they are equal in both value and type. When type conversion is considered, if the values being compared are of different types, **false** will be returned even if the values are the same.

## Available APIs

| API                      | Description                           |
|----------------------------|-------------------------------------|
| OH_JSVM_StrictEquals         | Checks whether two **JSVM_Value** objects are strictly equal.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in comparing JS values.

### OH_JSVM_StrictEquals

Use **OH_JSVM_StrictEquals** to check whether two JS values are strictly equal.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
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
    JSVM_Value isStrictEqual = nullptr;
    OH_JSVM_GetBoolean(env, result, &isStrictEqual);
    return isStrictEqual;
}
// Register the IsStrictEquals callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsStrictEquals},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named isStrictEquals and associate it with a callback. This allows the isStrictEquals callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"isStrictEquals", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char* srcCallNative = R"JS(data = '123';value = '123';isStrictEquals(data,value);)JS";
```
<!-- @[oh_jsvm_strict_equals](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/UsageInstructionsTwo/strictequals/src/main/cpp/hello.cpp) -->

Expected result:

```ts
JSVM OH_JSVM_StrictEquals: success: 1
```
