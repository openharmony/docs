# Working with Primitives Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Introduction

JSVM-API provides APIs for converting data between C/C++ and JavaScript (JS) data types and obtaining the JS object of the specified type.

## Basic Concepts

Before using the JSVM to operate JavaScript objects, you need to understand the following basic concepts:

- Conversion between JS and C/C primitives: You can use JSVM-API to convert JS values to C/C++ data types, for example, convert a JS value into a C/C++ integer and convert a JS string into a C/C++ string array. You can also convert C/C++ data into a JS value and return the JS value to JS.

## Available APIs

| API                  | Description                                               |
| ---------------------- | ------------------------------------------------------- |
| OH_JSVM_CoerceToBool   | Converts a JS value to an object of the Boolean type.  |
| OH_JSVM_CoerceToNumber | Converts a JS value to an object of the number type.   |
| OH_JSVM_CoerceToObject | Converts a JS value to an object of the object type.   |
| OH_JSVM_CoerceToString | Converts a JS value to an object of the string type.   |
| OH_JSVM_GetBoolean       | Obtains a JS singleton object that is used to represent the given Boolean value.|
| OH_JSVM_GetValueBool    | Obtains the C Boolean primitive equivalent of the given JS Boolean.|
| OH_JSVM_GetGlobal      | Obtains the **global** object of the current environment.                                     |
| OH_JSVM_GetNull          | Obtains the JS **null** object.                                       |
| OH_JSVM_GetUndefined     | Obtains the JS **undefined** object.                                  |

## Example

For details about the JSVM-API development process, see [Using JSVM-API to Implement Interactive Development Between JS and C/C++](use-jsvm-process.md). This document describes only the C++ code corresponding to the interface.

### OH_JSVM_CoerceToBool

Call **OH_JSVM_CoerceToBool** to forcibly convert a JS value to a JS Boolean value.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_CoerceToBool.
static JSVM_Value CoerceToBool(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value boolean = nullptr;
    JSVM_Status status = OH_JSVM_CoerceToBool(env, args[0], &boolean);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CoerceToBool failed");
    } else {
        bool result = false;
        OH_JSVM_GetValueBool(env, boolean, &result);
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CoerceToBool success:%{public}d", result);
    }
    return boolean;
}
// Register the CoerceToBool callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CoerceToBool},
};
static JSVM_CallbackStruct *method = param;
// Alias for the CoerceToBool method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"coerceToBool", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call C++ code from JS.
const char *srcCallNative = R"JS(coerceToBool("123"))JS";
```
<!-- @[oh_jsvm_coerce_to_bool](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/coercetobool/src/main/cpp/hello.cpp) -->

Expected result:
```
JSVM OH_JSVM_CoerceToBool success:1
```

### OH_JSVM_CoerceToNumber

Call **OH_JSVM_CoerceToNumber** to forcibly convert a JS value to a JS number.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_CoerceToNumber.
static JSVM_Value CoerceToNumber(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value number = nullptr;
    JSVM_Status status = OH_JSVM_CoerceToNumber(env, args[0], &number);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CoerceToNumber failed");
    } else {
        int32_t result = 0;
        OH_JSVM_GetValueInt32(env, number, &result);
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CoerceToNumber success:%{public}d", result);
    }
    return number;
}
// Register the CoerceToNumber callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CoerceToNumber},
};
static JSVM_CallbackStruct *method = param;
// Alias for the CoerceToNumber method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"coerceToNumber", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call C++ code from JS.
const char *srcCallNative = R"JS(coerceToNumber(true))JS";
```
<!-- @[oh_jsvm_coerce_to_number](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/coercetonumber/src/main/cpp/hello.cpp) -->

Expected result:
```
JSVM OH_JSVM_CoerceToNumber success:1
```

### OH_JSVM_CoerceToObject

Call **OH_JSVM_CoerceToObject** to forcibly convert a JS value to a JS object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_CoerceToObject.
static JSVM_Value CoerceToObject(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value obj = nullptr;
    JSVM_Status status = OH_JSVM_CoerceToObject(env, args[0], &obj);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_CoerceToObject failed");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CoerceToObject success");
    }
    return obj;
}
// Register the CoerceToObject callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CoerceToObject},
};
static JSVM_CallbackStruct *method = param;
// Alias for the CoerceToObject method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"coerceToObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call C++ code from JS.
const char *srcCallNative = R"JS(coerceToObject(123))JS";
```
<!-- @[oh_jsvm_coerce_to_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/coercetoobject/src/main/cpp/hello.cpp) -->

Expected result:
```
JSVM OH_JSVM_CoerceToObject success
```

### OH_JSVM_CoerceToString

Call **OH_JSVM_CoerceToString** to forcibly convert a JS value to a JS string.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_CoerceToString.
static JSVM_Value CoerceToString(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value str = nullptr;
    JSVM_Status status = OH_JSVM_CoerceToString(env, args[0], &str);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_CoerceToString fail");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CoerceToString success");
    }
    return str;
}
// Register the CoerceToString callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CoerceToString},
};
static JSVM_CallbackStruct *method = param;
// Alias for the CoerceToString method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"coerceToString", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call C++ code from JS.
const char *srcCallNative = R"JS(coerceToString(22222))JS";
```
<!-- @[oh_jsvm_coerce_to_string](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/coercetostring/src/main/cpp/hello.cpp) -->

Expected result:
```
JSVM OH_JSVM_CoerceToString success
```

### OH_JSVM_GetBoolean

Call **OH_JSVM_GetBoolean** to obtain a JS singleton object that is used to represent the given Boolean value.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_GetBoolean.
static JSVM_Value GetBoolean(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Pass in two parameters and parse them.
    size_t argc = 2;
    JSVM_Value argv[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    int32_t paramData = 0;
    OH_JSVM_GetValueInt32(env, argv[0], &paramData);
    int32_t paramValue = 0;
    OH_JSVM_GetValueInt32(env, argv[1], &paramValue);
    JSVM_Value returnValue = nullptr;
    bool type = false;
    if (paramData == paramValue) {
        OH_LOG_INFO(LOG_APP, "JSVM resultType equal");
        type = true;
    }
    JSVM_Status status = OH_JSVM_GetBoolean(env, type, &returnValue);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_GetBoolean fail");
    } else {
        bool result = false;
        OH_JSVM_GetValueBool(env, returnValue, &result);
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetBoolean success:%{public}d", result);
    }
    // Return the result.
    return returnValue;
}
// Register the GetBoolean callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetBoolean},
};
static JSVM_CallbackStruct *method = param;
// Alias for the GetBoolean method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getBoolean", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call C++ code from JS.
const char *srcCallNative = R"JS(getBoolean(1, 2);
                                 getBoolean(1, 1))JS";
```
<!-- @[oh_jsvm_get_boolean](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/getboolean/src/main/cpp/hello.cpp) -->

Expected result:
```
JSVM OH_JSVM_GetBoolean success:0
JSVM resultType equal
JSVM OH_JSVM_GetBoolean success:1
```

### OH_JSVM_GetValueBool

Call **OH_JSVM_GetValueBool** to obtain the C Boolean primitive equivalent of the given JS Boolean.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_GetValueBool.
static JSVM_Value GetValueBool(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool result = false;
    JSVM_Status status = OH_JSVM_GetValueBool(env, args[0], &result);
    if (status != JSVM_OK) {
        // If OH_JSVM_GetValueBool is successful, JSVM_OK is returned. If a non-Boolean value is passed in, JSVM_BOOLEAN_EXPECTED is returned.
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetValueBool fail:%{public}d", status);
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetValueBool success:%{public}d", result);
    }
    JSVM_Value boolJv = nullptr;
    OH_JSVM_GetBoolean(env, result, &boolJv);
    return boolJv;
}
// Register the GetValueBool callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueBool},
};
static JSVM_CallbackStruct *method = param;
// Alias for the GetValueBool method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueBool", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call C++ code from JS.
const char *srcCallNative = R"JS(getValueBool("abc");
                                getValueBool(true);
                                getValueBool(false);)JS";
```
<!-- @[oh_jsvm_get_value_bool](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/getvaluebool/src/main/cpp/hello.cpp) -->

Expected result:
```
JSVM OH_JSVM_GetValueBool fail:7
JSVM OH_JSVM_GetValueBool success:1
JSVM OH_JSVM_GetValueBool success:0
```

### OH_JSVM_GetGlobal

Call **OH_JSVM_GetGlobal** to obtain a JS **global** object. You can use this API to obtain the **JSVM_Value** that represents a JS global object, so that the JSVM module can interact with the global variables and functions defined in the JS context.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_GetGlobal.
static JSVM_Value GetGlobal(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the global object.
    JSVM_Value value = nullptr;
    JSVM_Value global = nullptr;
    OH_JSVM_CreateInt32(env, 1, &value);
    JSVM_Status status = OH_JSVM_GetGlobal(env, &global);
    OH_JSVM_SetNamedProperty(env, global, "Row", value);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetGlobal fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetGlobal success");
    }
    return global;
}
// Register the GetGlobal callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetGlobal},
};
static JSVM_CallbackStruct *method = param;
// Alias for the GetGlobal method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getGlobal", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call C++ code from JS.
const char *srcCallNative = R"JS(getGlobal())JS";
```
<!-- @[oh_jsvm_get_global](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/getglobal/src/main/cpp/hello.cpp) -->

Expected result:
```
JSVM OH_JSVM_GetGlobal success
```

### OH_JSVM_GetNull

Obtains the JavaScript null object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_GetNull.
static JSVM_Value GetNull(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_Value nullValue = nullptr;
    JSVM_Status status = OH_JSVM_GetNull(env, &nullValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetNull fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetNull success");
    }
    return nullValue;
}
// Register the GetNull callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetNull},
};
static JSVM_CallbackStruct *method = param;
// Alias for the GetNull method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getNull", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call C++ code from JS.
const char *srcCallNative = R"JS(getNull())JS";
```
<!-- @[oh_jsvm_get_null](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/getnull/src/main/cpp/hello.cpp) -->

Expected Results
```
JSVM OH_JSVM_GetNull success
```

### OH_JSVM_GetUndefined

Obtains the JavaScript undefined object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_GetUndefined.
static JSVM_Value GetUndefined(JSVM_Env env, JSVM_CallbackInfo info)
{
    //Obtain and parse the input parameters.
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Create the value 'undefined'.
    JSVM_Value value = nullptr;
    JSVM_Status status = OH_JSVM_GetUndefined(env, &value);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetUndefined failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetUndefined success");
    }
    return value;
}
// Register the GetUndefined callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetUndefined},
};
static JSVM_CallbackStruct *method = param;
// Alias for the GetUndefined method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getUndefined", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call C++ code from JS.
const char *srcCallNative = R"JS(getUndefined())JS";
```
<!-- @[oh_jsvm_get_undefined](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/getundefined/src/main/cpp/hello.cpp) -->

Expected Results
```
JSVM OH_JSVM_GetUndefined success
```
