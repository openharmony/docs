# Creating Basic Data Types Using Node-API

## Overview

The JavaScript (JS) Number type is a double-precision 64-bit binary IEEE 754 value. Only integers in the range of -2^53+1 to 2^53-1 (inclusive) can be represented without loss of precision. Integers out of this range must be handled by Node-API interfaces for BigInt.

## Basic Concepts

Before using Node-API to create and obtain the Number type, you need to understand the following concepts:

> - **Number type**<br>When using Node-API, you may need to convert data from C Number type to JS Number type, and the other way around. When converting the data, pay attention to the data range, signedness (signed or unsigned), and precision (single or double precision).
> - **Error handling**<br>You need to use Node-API to capture and handle errors that may occur. For example, use the error handling mechanism provided by Node-API to capture and handle memory allocation errors or other runtime errors occurring when integers are created.
> - **Interaction between JS and Node-API**<br>During the development, you need to consider the interaction between JS and Node-API interfaces, including how to pass the data of the Number type and return the correct value.

## Available APIs

The following Node-API functions are commonly used to develop ArkTS Node-API for converting data of the Number type between JS and C.
| API| Description|
| -------- | -------- |
| napi_get_value_uint32 | Obtains a C uint32 value from a JS number.|
| napi_get_value_int32 | Obtains a C int32 value from a JS number.|
| napi_get_value_int64 | Obtains a C int64 value from a JS number.|
| napi_get_value_double | Obtains a C double value from a JS number.|
| napi_create_int32 | Creates a JS number from a 32-bit signed integer. You can use this API to convert a C int32_t value into a JS number.|
| napi_create_uint32 | Creates a JS number from a 32-bit unsigned integer. You can use this API to convert a C uint32_t value into a JS number.|
| napi_create_int64 | Creates a JS number from a 64-bit signed integer. You can use this API to convert a C int64_t value into a JS number.|
| napi_create_double | Creates a JS number from a double-precision floating-point number. You can use this API to convert a C double value into a JS number.|

## How to Use

### napi_get_value_uint32

Obtains a C uint32 value from a JS number.

CPP code

```cpp
static napi_value GetValueUint32(napi_env env, napi_callback_info info)
{
    // Obtain the parameter of the Number type.
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    // Parse the input parameters.
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    uint32_t number = 0;
    // Obtain the 32-bit unsigned integer from the input parameter.
    napi_status status = napi_get_value_uint32(env, argv[0], &number);
    // If the input parameter is not a number, napi_number_expected will be returned. Set the function to return nullptr.
    if (status == napi_number_expected) {
        return nullptr;
    }
    napi_value result = nullptr;
    // Create a 32-bit unsigned integer and output the integer.
    napi_create_uint32(env, number, &result);
    return result;
}
```

API declaration

```ts
// index.d.ts
export const getValueUint32: <T>(data: T) => number | void;
```

ArkTS code

```ts
let value = testNapi.getValueUint32<number>(111111111111);
let data = testNapi.getValueUint32<string>("sssss");
hilog.info(0x0000, 'NAPI', 'get_value_uint32_number %{public}d', value);
// If "sssss" (a non-number) is passed in, undefined will be returned.
hilog.info(0x0000, 'NAPI', 'get_value_uint32_number %{public}s', data);
// If "100" (a number within the uint32 value range) is passed in, the original number will be returned.
hilog.info(0x0000, 'NAPI', 'get_value_uint32_number %{public}d', testNapi.getValueUint32<number>(100));
```

### napi_get_value_int32

Obtains a C int32 value from a JS number.

CPP code

```cpp
static napi_value GetValueInt32(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    int32_t result32 = 0;
    // Parse the input parameters.
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the parameter into a C int32 value.
    napi_status status = napi_get_value_int32(env, args[0], &result32);
    // If the input parameter is not a number, napi_number_expected will be returned. Set the function to return nullptr.
    if (status == napi_number_expected) {
        return nullptr;
    }
    // Call napi_create_int32 to create a JS number from the 32-bit signed integer.
    napi_value napiResult32 = nullptr;
    napi_create_int32(env, result32, &napiResult32);
    return napiResult32;
}
```

API declaration

```ts
// index.d.ts
export const getValueInt32: (value: number | string) => number | void;
```

ArkTS code

```ts
// If "ss" (a non-number) is passed in, undefined will be returned.
hilog.info(0x0000, 'NAPI', 'get_value_int32_not_number %{public}s', testNapi.getValueInt32('ss'));
// If 100 (a number within the int32 value range) is passed in, the original number will be returned.
hilog.info(0x0000, 'NAPI', 'get_value_int32_number %{public}d', testNapi.getValueInt32(100));
// If 68719476735 (which is 11111111111111111111111111111111111111111111 in binary format and corresponds to the value -1 when interpreted as an int32 number), -1 will be returned.
hilog.info(0x0000, 'NAPI', 'get_value_int32_oversize %{public}d', testNapi.getValueInt32(68719476735));
// If the input number is greater than 2 <sup>31</sup>-1 and its binary format does not indicate a special number in int32 like 111111111111111111111111111111111111, the interger overflows. In this case, a number decoded from the last 32-bit binary code will be returned.
hilog.info(0x0000, 'NAPI', 'get_value_int32_oversize %{public}d', testNapi.getValueInt32(687194767355));
// If NAN (not a number), +Infinity (positive infinity), or -Infinity (negative infinity) is passed in, 0 will be returned.
hilog.info(0x0000, 'NAPI', 'get_value_int32_number_NAN %{public}d', testNapi.getValueInt32(NaN));
hilog.info(0x0000, 'NAPI', 'get_value_int32_number_+Infinity %{public}d', testNapi.getValueInt32(+Infinity));
hilog.info(0x0000, 'NAPI', 'get_value_int32_number_-Infinity %{public}d', testNapi.getValueInt32(-Infinity));
```

### napi_get_value_int64

Obtains a C int64 value from a JS number.

CPP code

```cpp
static napi_value GetValueInt64(napi_env env, napi_callback_info info) 
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    int64_t result64 = 0;
    // Parse the input parameters.
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the input parameters into C int64 values.
    napi_status status = napi_get_value_int64(env, args[0], &result64);
    // If the input parameter is not a number, napi_number_expected will be returned. Set the function to return nullptr.
    if (status == napi_number_expected) {
        return nullptr;
    }
    // Call napi_create_int64 to convert int64 data to napi_value and return the value.
    napi_value napiResult64 = nullptr;
    napi_create_int64(env, result64, &napiResult64);
    return napiResult64;
}
```

API declaration

```ts
// index.d.ts
export const getValueInt64: (value: number | string) => number | void;
```

ArkTS code

```ts
// If a number within the int64 value range is passed in, the original number will be returned.
hilog.info(0x0000, 'NAPI', 'get_value_int64_number %{public}d', testNapi.getValueInt64(80));
// If "ss" (a non-number) is passed in, undefined will be returned.
hilog.info(0x0000, 'NAPI', 'get_value_int64_not_number %{public}s', testNapi.getValueInt64('sAs'));
// If a number out of the int64 value range is passed in, it will cause integer overflow and loss of precision. The number returned is not equal to the number passed in.
hilog.info(0x0000, 'NAPI', 'get_value_int64_number_oversize %{public}d', testNapi.getValueInt64(9223372036854775809));
// If NAN (not a number), +Infinity (positive infinity), or -Infinity (negative infinity) is passed in, 0 will be returned.
hilog.info(0x0000, 'NAPI', 'get_value_int64_number_NAN %{public}d', testNapi.getValueInt64(NaN));
hilog.info(0x0000, 'NAPI', 'get_value_int64_number_+Infinity %{public}d', testNapi.getValueInt64(+Infinity));
hilog.info(0x0000, 'NAPI', 'get_value_int64_number_-Infinity %{public}d', testNapi.getValueInt64(-Infinity));
```

### napi_get_value_double

Obtains a C double value from a JS number.

CPP code

```cpp
static napi_value GetDouble(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    double value = 0;
    napi_status status = napi_get_value_double(env, args[0], &value);
    // If a non-number is passed in, napi_number_expected will be returned.
    if(status == napi_number_expected) {
        return nullptr;
    }
    napi_value result = nullptr;
    napi_create_double(env, value, &result);
    return result;
}
```

API declaration

```ts
// index.d.ts
export const getDouble: (value: number | string) => number | void;
```

ArkTS code

```ts
// If a number is passed in, the number will be returned.
hilog.info(0x0000, 'NAPI', 'get_value_double_number %{public}d', testNapi.getDouble(80.885));
// If a non-number is passed in, undefined will be returned.
hilog.info(0x0000, 'NAPI', 'get_value_double_not_number %{public}s', testNapi.getDouble('sAs'));
```

### napi_create_int32

Creates a JS number from a 32-bit signed integer.

CPP code

```cpp
static napi_value CreateInt32(napi_env env, napi_callback_info info)
{
    // int32_t represents a 32-bit signed integer, ranging from -2^31 to 2^31 - 1, that is, -2147483648 to 2147483647.
     
    int32_t value = -26; 
    // Create a JS int32 number.
    napi_value result = nullptr;
    napi_status status = napi_create_int32(env, value, &result);
    if (status != napi_ok) {
        // Error handling.
        napi_throw_error(env, nullptr, "Failed to create int32 value");
    }
    return result;
}
```

API declaration

```ts
// index.d.ts
export const createInt32: () => number;
```

ArkTS code

```ts
hilog.info(0x0000, 'testTag','Test NAPI napi_create_int32: ' + testNapi.createInt32());
```

### napi_create_uint32

Creates a JS number from a 32-bit unsigned integer.

CPP code

```cpp
static napi_value CreateUInt32(napi_env env, napi_callback_info info) 
{
    // If the uint32_t type is used to represent -26, overflow occurs. Modulo operation is performed on the result to convert the binary complement of the negative number to a positive number. That is, 4294967270 will be returned.
    // uint32_t represents a 32-bit unsigned integer, ranging from 0 to 2^32 - 1, that is, 0 to 4294967295.
    // It only represents non-negative values (zero or positive integers).
    uint32_t value = 26;
    // Create a JS uint32 number.
    napi_value result = nullptr;
    napi_status status = napi_create_uint32(env, value, &result);
    if (status != napi_ok) {
        // Error handling.
        napi_throw_error(env, nullptr, "Failed to create uint32 value");
    }
    return result;
}
```

API declaration

```ts
// index.d.ts
export const createUInt32: () => number;
```

ArkTS code

```ts
 hilog.info(0x0000, 'testTag','Test NAPI napi_create_uint32: ' + testNapi.createUInt32());
```

### napi_create_int64

Creates a JS number from a 64-bit signed integer.

CPP code

```cpp
static napi_value CreateInt64(napi_env env, napi_callback_info info)
{
    // int64 represents a 64-bit signed integer, ranging from -2^63 to 2^63 - 1, that is, -9223372036854775808 to 9223372036854775807.
     
    int64_t value = 2147483648;
    // Create a JS int64 number.
    napi_value result = nullptr;
    napi_status status = napi_create_int64(env, value, &result);
    if (status != napi_ok) {
        // Error handling.
        napi_throw_error(env, nullptr, "Failed to create int64 value");
    }
    return result;
}
```

API declaration

```ts
// index.d.ts
export const createInt64: () => number;
```

ArkTS code

```ts
hilog.info(0x0000, 'testTag','Test NAPI napi_create_int64: ' + testNapi.createInt64());
```

### napi_create_double

Creates a JS number from a double-precision floating-point number.

CPP code

```cpp
static napi_value CreateDouble(napi_env env, napi_callback_info info)
{
    double value = 1.234;
    // Create a JS double number.
    napi_value result = nullptr;
    napi_status status = napi_create_double(env, value, &result);
    if (status != napi_ok) {
        // Error handling.
        napi_throw_error(env, nullptr, "Failed to create double value");
    }
    return result;
}
```

API declaration

```ts
// index.d.ts
export const createDouble: () => number;
```

ArkTS code

```ts
hilog.info(0x0000, 'testTag','Test NAPI napi_create_double: ' + testNapi.createDouble());
```

### Configuring Compile Settings and Registering a Module

- Configure compile settings.

```text
// CMakeLists.txt
# the minimum version of CMake.
cmake_minimum_required(VERSION 3.4.1)
project(AboutNumber)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

add_library(entry SHARED number.cpp)
target_link_libraries(entry PUBLIC libace_napi.z.so)
```

- Register the module.

```cpp
// number.cpp
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        {"getValueUint32", nullptr, GetValueUint32, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getValueInt32", nullptr, GetValueInt32, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getValueInt64", nullptr, GetValueInt64, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getDouble", nullptr, GetDouble, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"createInt32", nullptr, CreateInt32, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"createUInt32", nullptr, CreateUInt32, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"createInt64", nullptr, CreateInt64, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"createDouble", nullptr, CreateDouble, nullptr, nullptr, nullptr, napi_default, nullptr}
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END
```
