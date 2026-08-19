# Creating and Obtaining Values Using JSVM-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:34:56.056Z pushedAt=2026-08-12T11:01:45.750Z -->

## Introduction

In JavaScript (JS), the integer type represents a number without a decimal point, and the double type represents a number with a fractional part. Due to the limitation of the value storage mode of JS, very large or very small numbers cannot be accurately represented. In this case, you can use JSVM-API to represent large numbers in BigInt format.

## Basic Concepts

Before using JSVM-API to create and obtain numbers, you need to understand the following concepts:

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

<!-- @[oh_jsvm_get_value_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/getvalueuint32/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_GetValueUint32
static JSVM_Value GetValueUint32(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the passed-in number type parameter.
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    // Parse the passed-in parameter.
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    uint32_t number = 0;
    // Obtain the unsigned 32-bit integer from the passed-in parameter value.
    JSVM_Status status = OH_JSVM_GetValueUint32(env, argv[0], &number);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueUint32 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueUint32 success: %{public}u", number);
    }
    return argv[0];
}

// GetValueUint32 registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueUint32},
};
static JSVM_CallbackStruct *method = param;

// GetValueUint32 method alias for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueUint32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char* SRC_CALL_NATIVE = R"JS(getValueUint32(123))JS";
```

Expected result:

```txt
JSVM GetValueUint32 success: 123
```

### OH_JSVM_GetValueInt32

Use **OH_JSVM_GetValueInt32** to obtain a C Int32 value from a JS value.

CPP code:

<!-- @[oh_jsvm_get_value_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/getvalueint32/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_GetValueInt32
static JSVM_Value GetValueInt32(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    int32_t result32 = 0;
    // Parse the passed parameter.
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Convert the parameter passed from the frontend to the int32 type in the JSVM module.
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

// GetValueInt32 registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueInt32},
};
static JSVM_CallbackStruct *method = param;
// GetValueInt32 method alias for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueInt32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char* SRC_CALL_NATIVE = R"JS(getValueInt32(-123))JS";
```

Expected result:

```txt
JSVM GetValueInt32 success: -123
```

### OH_JSVM_GetValueInt64

Use **OH_JSVM_GetValueInt64** to obtain a C Int64 value from a JS value.

CPP code:

<!-- @[oh_jsvm_get_value_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/getvalueint64/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_GetValueInt64
static JSVM_Value GetValueInt64(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    int64_t result64 = 0;
    // Parse the passed value.
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Convert the parameter passed from the frontend to the int64 type in the JSVM module.
    JSVM_Status status = OH_JSVM_GetValueInt64(env, args[0], &result64);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueInt64 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueInt64 success: %{public}d", result64);
    }
    return args[0];
}

// GetValueInt64 registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueInt64},
};
static JSVM_CallbackStruct *method = param;
// GetValueInt64 method alias for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueInt64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char* SRC_CALL_NATIVE = R"JS(getValueInt64(-123))JS";
```

Expected result:

```txt
JSVM GetValueInt64 success: -123
```

### OH_JSVM_GetValueDouble

Use **OH_JSVM_GetValueDouble** to obtain a C double value from a JS value.

CPP code:

<!-- @[oh_jsvm_get_value_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/getvaluedouble/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_GetValueDouble
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

// GetDouble registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetDouble},
};
static JSVM_CallbackStruct *method = param;
// GetDouble method alias for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"getDouble", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char* SRC_CALL_NATIVE = R"JS(getDouble(-110.0456))JS";
```

Expected result:

```txt
JSVM GetDouble success: -110.045600
```

### OH_JSVM_CreateInt32

Use **OH_JSVM_CreateInt32** to create a JS number object from an int32_t object.

CPP code:

<!-- @[oh_jsvm_create_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/createint32/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_CreateInt32
static JSVM_Value CreateInt32(JSVM_Env env, JSVM_CallbackInfo info)
{
    int32_t value = -20;
    // Create an int32 number in JavaScript.
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

// CreateInt32 registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateInt32},
};
static JSVM_CallbackStruct *method = param;
// CreateInt32 method alias for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"createInt32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char* SRC_CALL_NATIVE = R"JS(createInt32())JS";
```

Expected result:

```txt
JSVM CreateInt32 success: -20
```

### OH_JSVM_CreateUint32

Use **OH_JSVM_CreateUint32** to create a JS number object from a uint32_t object.

CPP code:

<!-- @[oh_jsvm_create_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/createuint32/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_CreateUint32
static JSVM_Value CreateUInt32(JSVM_Env env, JSVM_CallbackInfo info)
{
    // If you use
    // uint32_t to define -26, overflow occurs. When overflow occurs, a modulo operation is performed on the result, converting the two's complement of the negative number to the corresponding positive number. -26 outputs 4294967270.
    // uint32_t is an unsigned 32-bit integer type that can only represent non-negative integers. Its range is from 0 to 2^32 - 1, that is, 0 to 4294967295.
    // The integer value to represent
    uint32_t value = 26;
    // Create a uint32 number in JavaScript.
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

// CreateUInt32 registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateUInt32},
};
static JSVM_CallbackStruct *method = param;
// CreateUInt32 method alias for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"createUInt32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char* SRC_CALL_NATIVE = R"JS(createUInt32())JS";
```

Expected result:

```txt
JSVM CreateUInt32 success: 26
```

### OH_JSVM_CreateInt64

Use **OH_JSVM_CreateInt64** to create a JS number object from an int64_t object. You are advised to use the **BigInt** API to indicate the large JS number.

CPP code:

<!-- @[oh_jsvm_create_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/createint64/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_CreateInt64
static JSVM_Value CreateInt64(JSVM_Env env, JSVM_CallbackInfo info)
{
    // int64 is a signed 64-bit integer type that can represent integers ranging from -2^63 to 2^63 - 1, that is, -9223372036854775808 to 9223372036854775807.
    // The integer value to represent
    int64_t value = 2147483648;
    // Create an int64 number in JavaScript.
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

// CreateInt64 registration callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateInt64},
};
static JSVM_CallbackStruct *method = param;
// CreateInt64 method alias for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"createInt64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char* SRC_CALL_NATIVE = R"JS(createInt64())JS";
```

Expected result:

```txt
JSVM CreateInt64 success: 2147483648
```

### OH_JSVM_CreateDouble

Use **OH_JSVM_CreateDouble** to create a JS number object from a double object.

CPP code:

<!-- @[oh_jsvm_create_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/createdouble/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_CreateDouble
static JSVM_Value CreateDouble(JSVM_Env env, JSVM_CallbackInfo info)
{
    double value = 1.234;
    // Create a double number in JavaScript.
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
// CreateDouble method alias for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"createDouble", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Sample test JS
const char* SRC_CALL_NATIVE = R"JS(createDouble())JS";
```

Expected result:

```txt
JSVM CreateDouble success: 1.234000
```