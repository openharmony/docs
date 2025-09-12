# Creating Basic Data Types Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Introduction

In JavaScript (JS), the integer type represents a number without a decimal point, and the double type represents a number with a fractional part. Due to the limitation of the value storage mode of JS, very large or very small numbers cannot be accurately represented. In this case, you can use JSVM-API to represent large numbers in BigInt format.

## Basic Concepts

Before using the JSVM-API to create and obtain numeric types, you need to understand the following basic concepts:

- Number type<br>When using JSVM-API, you may need to convert values of number types between C and JS. When converting the data, pay attention to the data range, signedness (signed or unsigned), and precision (single or double precision).
- Error handling<br>You also need to use JSVM-API to capture and handle errors that may occur during the conversion. For example, when an integer is created, you may need to capture and handle memory allocation failures or other runtime errors.
- Interaction between JS and JSVM-API<br>During the development, you need to consider the interaction between JS and JSVM-API, including how to pass the data of the number type and return the correct value.

## Available APIs

| API                 | Description                                       |
| --------------------- | -----------------------------------------------|
| OH_JSVM_GetValueUint32 | Obtains the C Uint32 primitive equivalent of the given JS number.  |
| OH_JSVM_GetValueInt32  | Obtains the C Int32 primitive equivalent of the given JS number.   |
| OH_JSVM_GetValueInt64  | Obtains the C Int64 primitive equivalent of the given JS number.   |
| OH_JSVM_GetValueDouble | Obtains the C Double primitive equivalent of the given JS number.  |
| OH_JSVM_CreateInt32     | Creates a JS number object from a C Int32_t object.|
| OH_JSVM_CreateUint32    | Creates a JS number object from a C Uint32_t object.|
| OH_JSVM_CreateInt64     | Creates a JS number object from a C Int64_t object.|
| OH_JSVM_CreateDouble    | Creates a JS number object from a C double object. |

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in manipulating basic data types.

### OH_JSVM_GetValueUint32

Use **OH_JSVM_GetValueInt32** to obtain a C uint32 value from a JS value.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// Define OH_JSVM_GetValueUint32.
static JSVM_Value GetValueUint32(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the parameter of the Number type.
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    // Parse the input parameters.
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    uint32_t number = 0;
    // Obtain a 32-bit unsigned integer.
    JSVM_Status status = OH_JSVM_GetValueUint32(env, argv[0], &number);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueUint32 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueUint32 success: %{public}u", number);
    }
    return argv[0];
}

// Register the GetValueUint32 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueUint32},
};
static JSVM_CallbackStruct *method = param;

// Set a property descriptor named getValueUint and associate it with a callback. This allows the GetValueUint callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueUint32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char* srcCallNative = R"JS(getValueUint32(123))JS";
```
<!-- @[oh_jsvm_get_value_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/getvalueuint32/src/main/cpp/hello.cpp) -->

Expected result:

```
JSVM GetValueUint32 success: 123
```

### OH_JSVM_GetValueInt32

Use **OH_JSVM_GetValueInt32** to obtain a C Int32 value from a JS value.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// Define OH_JSVM_GetValueInt32.
static JSVM_Value GetValueInt32(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    int32_t result32 = 0;
    // Parse the input parameters.
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Convert the parameter into a C int32 value.
    JSVM_Status status = OH_JSVM_GetValueInt32(env, args[0], &result32);
    if (status != JSVM_OK) {
        return nullptr;
    }
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueInt32 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueInt32 success: %{public}d", result32);
    }
    return args[0];
}

// Register the GetValueInt32 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueInt32},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getValueInt32 and associate it with a callback. This allows the GetValueInt32 callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueInt32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char* srcCallNative = R"JS(getValueInt32(-123))JS";
```
<!-- @[oh_jsvm_get_value_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/getvalueint32/src/main/cpp/hello.cpp) -->

Expected result:

```
JSVM GetValueInt32 success: -123
```

### OH_JSVM_GetValueInt64

Use **OH_JSVM_GetValueInt32** to obtain a C Int64 value from a JS value.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// Define OH_JSVM_GetValueInt64.
static JSVM_Value GetValueInt64(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    int64_t result64 = 0;
    // Parse the input parameters.
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Convert the input parameters into C int64 values.
    JSVM_Status status = OH_JSVM_GetValueInt64(env, args[0], &result64);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueInt64 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueInt64 success: %{public}ld", result64);
    }
    return args[0];
}

// Register the GetValueInt64 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueInt64},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getValueInt64 and associate it with a callback. This allows the GetValueInt64 callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueInt64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char* srcCallNative = R"JS(getValueInt64(-123))JS";
```
<!-- @[oh_jsvm_get_value_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/getvalueint64/src/main/cpp/hello.cpp) -->

Expected result:

```
JSVM GetValueInt64 success: -123
```

### OH_JSVM_GetValueDouble

Use **OH_JSVM_GetValueDouble** to obtain a C double value from a JS value.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// Define OH_JSVM_GetValueDouble.
static JSVM_Value GetDouble(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    double value = 0;
    JSVM_Status status = OH_JSVM_GetValueDouble(env, args[0], &value);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetDouble fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetDouble success: %{public}f", value);
    }
    return args[0];
}

// Register the GetDouble callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetDouble},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getDouble and associate it with a callback. This allows the GetDouble callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getDouble", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char* srcCallNative = R"JS(getDouble(-110.0456))JS";
```
<!-- @[oh_jsvm_get_value_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/getvaluedouble/src/main/cpp/hello.cpp) -->

Expected result:

```
JSVM GetDouble success: -110.045600
```

### OH_JSVM_CreateInt32

Creates a JavaScript number object based on the int32_t data.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// Define OH_JSVM_CreateInt32.
static JSVM_Value CreateInt32(JSVM_Env env, JSVM_CallbackInfo info)
{
    int32_t value = -20;
    // Create a JS Int32 number.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateInt32(env, value, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateInt32 fail");
    } else {
        int32_t number = 0;
        OH_JSVM_GetValueInt32(env, result, &number);
        OH_LOG_INFO(LOG_APP, "JSVM CreateInt32 success: %{public}d", number);
    }
    return result;
}

// Register the CreateInt32 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateInt32},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createInt32 and associate it with a callback. This allows the CreateInt32 callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createInt32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char* srcCallNative = R"JS(createInt32())JS";
```
<!-- @[oh_jsvm_create_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/createint32/src/main/cpp/hello.cpp) -->

Expected result:

```
JSVM CreateInt32 success: -20
```

### OH_JSVM_CreateUint32

Creates a JavaScript number object based on the uint32_t data.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// Define OH_JSVM_CreateUint32.
static JSVM_Value CreateUInt32(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 
    // If the uint32_t type is used to represent -26, overflow occurs. Modulo operation is performed on the result to convert the binary complement of the negative number to a positive number. That is, 4294967270 will be returned.
    // uint32_t represents a 32-bit unsigned integer, ranging from 0 to 2^32 - 1, that is, 0 to 4294967295.
    // 
    uint32_t value = 26;
    // Create a JS Uint32 number.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateUint32(env, value, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateUInt32 fail");
    } else {
        uint32_t number = 0;
        OH_JSVM_GetValueUint32(env, result, &number);
        OH_LOG_INFO(LOG_APP, "JSVM CreateUInt32 success: %{public}u", number);
    }
    return result;
}

// Register the CreateUInt32 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateUInt32},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createUInt32 and associate it with a callback. This allows the CreateUInt32 callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createUInt32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char* srcCallNative = R"JS(createUInt32())JS";
```
<!-- @[oh_jsvm_create_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/createuint32/src/main/cpp/hello.cpp) -->

Expected result:

```
JSVM CreateUInt32 success: 26
```

### OH_JSVM_CreateInt64

Creates a JavaScript number object based on the int64_t data. If you need to indicate a large number of JS files, you are advised to use the BigInt interface.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// Define OH_JSVM_CreateInt64.
static JSVM_Value CreateInt64(JSVM_Env env, JSVM_CallbackInfo info)
{
    int64_t value = 2147483648;
    // Create a JS Int64 number.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateInt64(env, value, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateInt64 fail");
    } else {
        int64_t number = 0;
        OH_JSVM_GetValueInt64(env, result, &number);
        OH_LOG_INFO(LOG_APP, "JSVM CreateInt64 success: %{public}ld", number);
    }
    return result;
}

// Register the CreateInt64 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateInt64},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createInt64 and associate it with a callback. This allows the CreateInt64 callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createInt64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char* srcCallNative = R"JS(createInt64())JS";
```
<!-- @[oh_jsvm_create_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/createint64/src/main/cpp/hello.cpp) -->

Expected result:

```
JSVM CreateInt64 success: 2147483648
```

### OH_JSVM_CreateDouble

Creates a JavaScript number object based on double data.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// register a CreateDouble callback.

// Define OH_JSVM_CreateDouble.
static JSVM_Value CreateDouble(JSVM_Env env, JSVM_CallbackInfo info)
{
    double value = 1.234;
    // Create a JS double number.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateDouble(env, value, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateDouble fail");
    } else {
        double number = 0;
        OH_JSVM_GetValueDouble(env, result, &number);
        OH_LOG_INFO(LOG_APP, "JSVM CreateDouble success: %{public}f", number);
    }
    return result;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateDouble},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createDouble and associate it with a callback. This allows the CreateDouble callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createDouble", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char* srcCallNative = R"JS(createDouble())JS";
```
<!-- @[oh_jsvm_create_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/createdouble/src/main/cpp/hello.cpp) -->

Expected result:

```
JSVM CreateDouble success: 1.234000
```
