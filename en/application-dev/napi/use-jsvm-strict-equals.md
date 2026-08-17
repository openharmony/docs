# Comparing JS Values Using JSVM-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=d475d826f8ab6e97b4b69944b8a9a6d84f792324 translatedAt=2026-08-12T06:36:20.791Z pushedAt=2026-08-12T11:03:57.997Z -->

## Introduction

This topic walks you through on how to use JSVM-API to check whether two JavaScript (JS) values are strictly equal (equal in both value and type). The API provided is equivalent to the JS strict equality operator (**===**). This API avoids type conversion and loose equality comparison, ensuring equal values and types.

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

<!-- @[oh_jsvm_strict_equals](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/UsageInstructionsTwo/strictequals/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...
// Sample method for OH_JSVM_StrictEquals
static JSVM_Value IsStrictEquals(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Accept two input parameters.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Call the OH_JSVM_StrictEquals API to determine whether two given JavaScript values are strictly equal.
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
// Alias for the IsStrictEquals method, for JS invocation.
static JSVM_PropertyDescriptor descriptor[] = {
    {"isStrictEquals", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char* SRC_CALL_NATIVE = R"JS(data = '123';value = '123';isStrictEquals(data,value);)JS";
```

Expected result:

```ts
JSVM OH_JSVM_StrictEquals: success: 1
```