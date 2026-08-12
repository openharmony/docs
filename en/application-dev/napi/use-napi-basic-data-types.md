# Creating Basic Data Types Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:41:57.788Z pushedAt=2026-08-12T11:15:55.962Z -->

## Introduction

The ArkTS Number type represents a double-precision 64-bit binary IEEE 754 value. Only integers in the range of -2^53+1 to 2^53-1 (inclusive) can be represented without loss of precision. Integers out of this range must be handled by Node-API interfaces for BigInt.

## Basic Concepts

Before using Node-API to create and obtain numbers, you need to understand the following concepts:

- Number type<br>When using Node-API, you may need to convert values of number types between C and ArkTS. When converting the data, pay attention to the data range, signedness (signed or unsigned), and precision (single or double precision).

- Error handling<br>You also need to use Node-API to capture and handle errors that may occur during the conversion. For example, when an integer is created, you may need to capture and handle memory allocation failures or other runtime errors.

- Interaction between ArkTS and Node-API<br>During the development, you need to consider the interaction between ArkTS and Node-API, including how to pass the data of the number type and return the correct value.

## Available APIs

The following table lists the APIs provided by the Node-API module for converting number types between ArkTS and C/C++.

| API| Description|
| -------- | -------- |
| napi_get_value_uint32 | Obtains a C uint32_t value from an ArkTS number.|
| napi_get_value_int32 | Obtains a C int32_t value from an ArkTS number.|
| napi_get_value_int64 | Obtains a C int64_t value from an ArkTS number.|
| napi_get_value_double | Obtains a C double value from an ArkTS number.|
| [napi_get_value_bool](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/use-napi-about-primitive#napi_get_value_bool)| Obtains a C bool value from an ArkTS boolean.|
| [napi_get_value_string_utf8](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/use-napi-about-string#napi_get_value_string_utf8) | Obtains a C UTF-8-encoded string value from an ArkTS string.|
| [napi_get_value_string_utf16](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/use-napi-about-string#napi_get_value_string_utf16) | Obtains a C UTF-16-encoded string value from an ArkTS string.|
| [napi_get_value_string_latin1](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/use-napi-about-string#napi_get_value_string_latin1) | Obtains a C ISO-8859-1-encoded string value from an ArkTS string.|
| napi_create_int32 | Creates an ArkTS number from a 32-bit signed integer.|
| napi_create_uint32 | Creates an ArkTS number from a 32-bit unsigned integer.|
| napi_create_int64 | Creates an ArkTS number from a 64-bit signed integer.|
| napi_create_double | Creates an ArkTS number from a double-precision floating-point number.|
| [napi_get_boolean](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/use-napi-about-primitive#napi_get_boolean) | Obtain an ArkTS boolean from a C bool.|
| [napi_create_string_utf8](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/use-napi-about-string#napi_create_string_utf8) | Creates an ArkTS string from a C UTF-8-encoded string.|
| [napi_create_string_utf16](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/use-napi-about-string#napi_create_string_utf16) | Creates an ArkTS string from a C UTF-16-encoded string.|
| [napi_create_string_latin1](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/use-napi-about-string#napi_create_string_latin1) | Creates an ArkTS string from a C ISO-8859-1-encoded string.|
| [napi_create_external_string_ascii](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/use-napi-about-string#napi_create_external_string_ascii) | Creates an ArkTS string from a C ASCII-encoded string without copying.|
| [napi_create_external_string_utf16](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/use-napi-about-string#napi_create_external_string_utf16) | Creates an ArkTS string from a C UTF16-encoded string without copying.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code involved in the APIs for manipulating basic data types.

### napi_get_value_uint32

Use **napi_get_value_uint32** to obtain a 32-bit unsigned integer from an ArkTS number.

CPP code:

<!-- @[napi_get_value_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_value_uint32
static napi_value GetValueUint32(napi_env env, napi_callback_info info)
{
    // Obtain the numeric type parameter passed in.
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    // Parse the passed-in parameter.
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    uint32_t number = 0;
    // Obtain the unsigned 32-bit integer from the passed-in parameter value.
    napi_status status = napi_get_value_uint32(env, argv[0], &number);
    // If the passed-in parameter is not a number, napi_number_expected is returned and the function returns nullptr.
    if (status != napi_ok) {
        return nullptr;
    }
    napi_value result = nullptr;
    // Create an unsigned 32-bit integer from the passed-in parameter and return it.
    napi_create_uint32(env, number, &result);
    return result;
}
```

API declaration:

<!-- @[napi_get_value_uint32_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const getValueUint32: <T>(data: T) => number | undefined; // napi_get_value_uint32
```

ArkTS code:

<!-- @[ark_napi_get_value_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_value_uint32
let value = testNapi.getValueUint32<number>(111111111111);
let data = testNapi.getValueUint32<string>("sssss");
hilog.info(0x0000, 'Node-API', 'get_value_uint32_number %{public}d', value);
// When a non-number "sssss" is passed in, the function returns undefined.
hilog.info(0x0000, 'Node-API', 'get_value_uint32_number %{public}s', data);
// When the number 100 within the uint32 range is passed in, the function returns the original number.
hilog.info(0x0000, 'Node-API', 'get_value_uint32_number %{public}d',
  testNapi.getValueUint32<number>(100));
```

### napi_get_value_int32

Use **napi_get_value_int32** to convert an ArkTS value to a C int32 value.

CPP code:

<!-- @[napi_get_value_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_value_int32
static napi_value GetValueInt32(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    int32_t result32 = 0;
    // Parse the passed-in parameter.
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the parameter passed from the frontend to the int32 type of the Node-API module.
    napi_status status = napi_get_value_int32(env, args[0], &result32);
    // If the passed-in parameter is not a number, the napi_get_value_int32 API returns napi_number_expected and the function returns nullptr.
    if (status != napi_ok) {
        return nullptr;
    }
    // Call the napi_create_int32 API to convert int32 data to napi_value and return it.
    napi_value napiResult32 = nullptr;
    napi_create_int32(env, result32, &napiResult32);
    return napiResult32;
}
```

API declaration:

<!-- @[napi_get_value_int32_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const getValueInt32: (value: number | string) => number | undefined; // napi_get_value_int32
```

ArkTS code:

<!-- @[ark_napi_get_value_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_value_int32
// When a non-number "ss" is passed in, the function returns undefined.
hilog.info(0x0000, 'Node-API', 'get_value_int32_not_number %{public}s', testNapi.getValueInt32('ss'));
// When the number 100 within the int32 range is passed in, the function returns the original number.
hilog.info(0x0000, 'Node-API', 'get_value_int32_number %{public}d', testNapi.getValueInt32(100));
// When 68719476735 is passed in, its binary representation is 111111111111111111111111111111111111, which represents -1 in the int32 type.
hilog.info(0x0000, 'Node-API', 'get_value_int32_oversize %{public}d',
  testNapi.getValueInt32(68719476735));
// Numbers greater than 2^31 - 1 that do not have a binary representation like 111111111111111111111111111111111111 (which has special meaning in int32) also overflow, causing the value to change. The return value is decoded based on the last 32 bits of the binary encoding.
hilog.info(0x0000, 'Node-API', 'get_value_int32_oversize %{public}d',
  testNapi.getValueInt32(687194767355));
// When NaN (not a number), +Infinity (positive infinity), or -Infinity (negative infinity) is passed in, the number 0 is returned.
hilog.info(0x0000, 'Node-API', 'get_value_int32_number_NAN %{public}d', testNapi.getValueInt32(NaN));
hilog.info(0x0000, 'Node-API', 'get_value_int32_number_+Infinity %{public}d',
  testNapi.getValueInt32(+Infinity));
hilog.info(0x0000, 'Node-API', 'get_value_int32_number_-Infinity %{public}d',
  testNapi.getValueInt32(-Infinity));
```

### napi_get_value_int64

Use **napi_get_value_int64** to convert an ArkTS value to a C int64 value.

CPP code:

<!-- @[napi_get_value_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_value_int64
static napi_value GetValueInt64(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    int64_t result64 = 0;
    // Parse the passed-in value.
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the parameter passed from the frontend to the int64 type of the Node-API module.
    napi_status status = napi_get_value_int64(env, args[0], &result64);
    // If the passed-in parameter is not a number, napi_number_expected is returned.
    if (status != napi_ok) {
        return nullptr;
    }
    // Call the napi_create_int64 API to convert int64 data to napi_value and return it to the frontend.
    napi_value napiResult64 = nullptr;
    napi_create_int64(env, result64, &napiResult64);
    return napiResult64;
}
```

API declaration:

<!-- @[napi_get_value_int64_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const getValueInt64: (value: number | string) => number | undefined; // napi_get_value_int64
```

ArkTS code:

<!-- @[ark_napi_get_value_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_value_int64
// When a number within the int64 representable range is passed in, that number is returned.
hilog.info(0x0000, 'Node-API', 'get_value_int64_number %{public}d', testNapi.getValueInt64(80));
// When a non-number "ss" is passed in, the value returned by the function should be undefined.
hilog.info(0x0000, 'Node-API', 'get_value_int64_not_number %{public}s',
  testNapi.getValueInt64('sAs'));
// When a number exceeding the int64 representable range is passed in, it overflows and loses precision, causing the input number and the returned number to differ.
hilog.info(0x0000, 'Node-API', 'get_value_int64_number_oversize %{public}d',
  testNapi.getValueInt64(9223372036854775809));
// When NaN (not a number), +Infinity (positive infinity), or -Infinity (negative infinity) is passed in, the API returns the number 0.
hilog.info(0x0000, 'Node-API', 'get_value_int64_number_NAN %{public}d', testNapi.getValueInt64(NaN));
hilog.info(0x0000, 'Node-API', 'get_value_int64_number_+Infinity %{public}d',
  testNapi.getValueInt64(+Infinity));
hilog.info(0x0000, 'Node-API', 'get_value_int64_number_-Infinity %{public}d',
  testNapi.getValueInt64(-Infinity));
```

### napi_get_value_double

Use **napi_get_value_double** to convert an ArkTS value to a C double value.

CPP code:

<!-- @[napi_get_value_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_value_double
static napi_value GetDouble(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    double value = 0;
    napi_status status = napi_get_value_double(env, args[0], &value);
    // When a non-number is passed in, the API returns napi_number_expected.
    if (status != napi_ok) {
        return nullptr;
    }
    napi_value result = nullptr;
    napi_create_double(env, value, &result);
    return result;
}
```

API declaration:

<!-- @[napi_get_value_double_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const getDouble: (value: number | string) => number | undefined; // napi_get_value_double
```

ArkTS code:

<!-- @[ark_napi_get_value_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_value_double
// When a number is passed in, that number is returned.
hilog.info(0x0000, 'Node-API', 'get_value_double_number %{public}d', testNapi.getDouble(80.885));
// When a non-number is passed in, the value returned by the function should be undefined.
hilog.info(0x0000, 'Node-API', 'get_value_double_not_number %{public}s', testNapi.getDouble('sAs'));
```

### napi_create_int32

Use **napi_create_int32** to create an ArkTS number from a 32-bit signed integer.

CPP code:

<!-- @[napi_create_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_create_int32
static napi_value CreateInt32(napi_env env, napi_callback_info info)
{
    // int32_t is a signed 32-bit integer type that represents signed integers. Its range is from -2^31 to 2^31 - 1, that is, from -2147483648 to 2147483647.
    // The integer value to represent.
    int32_t value = -26;
    // Create an int32 number in ArkTS.
    napi_value result = nullptr;
    napi_status status = napi_create_int32(env, value, &result);
    if (status != napi_ok) {
        // Handle the error.
        napi_throw_error(env, nullptr, "Failed to create int32 value");
    }
    return result;
}
```

API declaration:

<!-- @[napi_create_int32_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createInt32: () => number; // napi_create_int32
```

ArkTS code:

<!-- @[ark_napi_create_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_create_int32
hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_int32：' + testNapi.createInt32());
```

### napi_create_uint32

Use **napi_create_uint32** to create an ArkTS number from a 32-bit unsigned integer.

CPP code:

<!-- @[napi_create_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_create_uint32
static napi_value CreateUInt32(napi_env env, napi_callback_info info)
{
    // If you use
    // the uint32_t type to define -26, an overflow occurs. When overflow happens, a modulo operation is performed on the result, converting the two's complement of the negative number to the corresponding positive number. -26 outputs 4294967270.
    // uint32_t is an unsigned 32-bit integer type that can only represent non-negative integers. Its range is from 0 to 2^32 - 1, that is, from 0 to 4294967295.
    // The integer value to represent.
    uint32_t value = 26;
    // Create a uint32 number in ArkTS.
    napi_value result = nullptr;
    napi_status status = napi_create_uint32(env, value, &result);
    if (status != napi_ok) {
        // Handle the error.
        napi_throw_error(env, nullptr, "Failed to create uint32 value");
    }
    return result;
}
```

API declaration:

<!-- @[napi_create_uint32_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createUInt32: () => number; // napi_create_uint32
```

ArkTS code:

<!-- @[ark_napi_create_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_create_uint32
hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_uint32: ' + testNapi.createUInt32());
```

### napi_create_int64

Use **napi_create_int64** to create an ArkTS number from a 64-bit signed integer.

CPP code:

<!-- @[napi_create_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_create_int64
static napi_value CreateInt64(napi_env env, napi_callback_info info)
{
    // int64 is a signed 64-bit integer type that can represent integers ranging from -2^63 to 2^63 - 1, that is, from -9223372036854775808 to 9223372036854775807.
    // The integer value to represent.
    int64_t value = 2147483648;
    // Create an ArkTS number using the given value. Only integers in the range from -2^53 + 1 to 2^53 - 1 (inclusive) can be accurately represented.
    // If the value to represent exceeds 2^53, use the napi_create_bigint64 API.
    napi_value result = nullptr;
    napi_status status = napi_create_int64(env, value, &result);
    if (status != napi_ok) {
        // Handle the error.
        napi_throw_error(env, nullptr, "Failed to create int64 value");
    }
    return result;
}
```

API declaration:

<!-- @[napi_create_int64_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createInt64: () => number; // napi_create_int64
```

ArkTS code:

<!-- @[ark_napi_create_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_create_int64
hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_int64: ' + testNapi.createInt64());
```

### napi_create_double

Use **napi_create_double** to create an ArkTS number from a double-precision floating-point number.

CPP code:

<!-- @[napi_create_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_create_double
static napi_value CreateDouble(napi_env env, napi_callback_info info)
{
    double value = 1.234;
    // Create a double number in ArkTS.
    napi_value result = nullptr;
    napi_status status = napi_create_double(env, value, &result);
    if (status != napi_ok) {
        // Handle the error.
        napi_throw_error(env, nullptr, "Failed to create double value");
    }
    return result;
}
```

API declaration:

<!-- @[napi_create_double_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createDouble: () => number; // napi_create_double
```

ArkTS code:

<!-- @[ark_napi_create_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_create_double
hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_double: ' + testNapi.createDouble());
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```