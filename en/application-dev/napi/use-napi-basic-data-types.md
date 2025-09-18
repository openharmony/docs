# Creating Basic Data Types Using Node-API
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

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
| napi_get_value_uint32 | Obtains a C uint32 value from an ArkTS number.|
| napi_get_value_int32 | Obtains a C int32 value from an ArkTS number.|
| napi_get_value_int64 | Obtains a C int64 value from an ArkTS number.|
| napi_get_value_double | Obtains a C double value from an ArkTS number.|
| napi_create_int32 | Creates an ArkTS number from a 32-bit signed integer.|
| napi_create_uint32 | Creates an ArkTS number from a 32-bit unsigned integer.|
| napi_create_int64 | Creates an ArkTS number from a 64-bit signed integer.|
| napi_create_double | Creates an ArkTS number from a double-precision floating-point number.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code involved in the APIs for manipulating basic data types.

### napi_get_value_uint32

Use **napi_get_value_uint32** to obtain a 32-bit unsigned integer from an ArkTS number.

CPP code:

```cpp
#include "napi/native_api.h"

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
    // If the input parameter is not a number, napi_number_expected will be thrown. Set the return value of the function to nullptr.
    if (status != napi_ok) {
        return nullptr;
    }
    napi_value result = nullptr;
    // Create a 32-bit unsigned integer and output the integer.
    napi_create_uint32(env, number, &result);
    return result;
}
```
<!-- @[napi_get_value_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getValueUint32: <T>(data: T) => number | undefined;
```
<!-- @[napi_get_value_uint32_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let value = testNapi.getValueUint32<number>(111111111111);
let data = testNapi.getValueUint32<string>("sssss");
hilog.info(0x0000, 'Node-API', 'get_value_uint32_number %{public}d', value);
// If "sssss" (a non-number) is passed in, undefined will be returned.
hilog.info(0x0000, 'Node-API', 'get_value_uint32_number %{public}s', data);
// If 100 (a number within the uint32 value range) is passed in, the original number will be returned.
hilog.info(0x0000, 'Node-API', 'get_value_uint32_number %{public}d', testNapi.getValueUint32<number>(100));
```
<!-- @[ark_napi_get_value_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

### napi_get_value_int32

Use **napi_get_value_int32** to convert an ArkTS value to a C int32 value.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetValueInt32(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    int32_t result32 = 0;
    // Parse the input parameter.
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the parameter into a C int32 value.
    napi_status status = napi_get_value_int32(env, args[0], &result32);
    // If the input parameter is not a number, napi_number_expected will be thrown. Set the return value of the function to nullptr.
    if (status != napi_ok) {
        return nullptr;
    }
    // Call napi_create_int32 to convert the 32-bit signed integer into a napi_value and return it.
    napi_value napiResult32 = nullptr;
    napi_create_int32(env, result32, &napiResult32);
    return napiResult32;
}
```
<!-- @[napi_get_value_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getValueInt32: (value: number | string) => number | undefined;
```
<!-- @[napi_get_value_int32_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

// If 'ss' (a non-number) is passed in, undefined will be returned.
hilog.info(0x0000, 'Node-API', 'get_value_int32_not_number %{public}s', testNapi.getValueInt32('ss'));
// If 100 (a number within the int32 value range) is passed in, the original number will be returned.
hilog.info(0x0000, 'Node-API', 'get_value_int32_number %{public}d', testNapi.getValueInt32(100));
// If 68719476735 (which is 111111111111111111111111111111111111 in binary format and corresponds to the value -1 when interpreted as an int32 number) is passed in, -1 will be returned.
hilog.info(0x0000, 'Node-API', 'get_value_int32_oversize %{public}d', testNapi.getValueInt32(68719476735));
// If the input number is greater than 2 <sup>31</sup>-1 and its binary format does not indicate a special number in int32 like 111111111111111111111111111111111111, the integer overflows. In this case, a number decoded from the last 32-bit binary code will be returned.
hilog.info(0x0000, 'Node-API', 'get_value_int32_oversize %{public}d', testNapi.getValueInt32(687194767355));
// If NaN (Not-a-Number), +Infinity (positive infinity), or -Infinity (negative infinity) is passed in, 0 will be returned.
hilog.info(0x0000, 'Node-API', 'get_value_int32_number_NAN %{public}d', testNapi.getValueInt32(NaN));
hilog.info(0x0000, 'Node-API', 'get_value_int32_number_+Infinity %{public}d', testNapi.getValueInt32(+Infinity));
hilog.info(0x0000, 'Node-API', 'get_value_int32_number_-Infinity %{public}d', testNapi.getValueInt32(-Infinity));
```
<!-- @[ark_napi_get_value_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

### napi_get_value_int64

Use **napi_get_value_int64** to convert an ArkTS value to a C int64 value.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetValueInt64(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    int64_t result64 = 0;
    // Parse the parameter passed in.
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the parameter into a C int64 value.
    napi_status status = napi_get_value_int64(env, args[0], &result64);
    // If the input parameter is not a number, return napi_number_expected.
    if (status != napi_ok) {
        return nullptr;
    }
    // Call napi_create_int64 to convert the int64 value to a napi_value and return it.
    napi_value napiResult64 = nullptr;
    napi_create_int64(env, result64, &napiResult64);
    return napiResult64;
}
```
<!-- @[napi_get_value_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getValueInt64: (value: number | string) => number | undefined;
```
<!-- @[napi_get_value_int64_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

// If a number within the int64 value range is passed in, the original number will be returned.
hilog.info(0x0000, 'Node-API', 'get_value_int64_number %{public}d', testNapi.getValueInt64(80));
// If "sAs" (a non-number) is passed in, 'undefined' will be returned.
hilog.info(0x0000, 'Node-API', 'get_value_int64_not_number %{public}s', testNapi.getValueInt64('sAs'));
// If a number out of the int64 value range is passed in, it will cause integer overflow and loss of precision. The number returned is not equal to the number passed in.
hilog.info(0x0000, 'Node-API', 'get_value_int64_number_oversize %{public}d', testNapi.getValueInt64(9223372036854775809));
// If NaN (Not-a-Number), +Infinity (positive infinity), or -Infinity (negative infinity) is passed in, 0 will be returned.
hilog.info(0x0000, 'Node-API', 'get_value_int64_number_NAN %{public}d', testNapi.getValueInt64(NaN));
hilog.info(0x0000, 'Node-API', 'get_value_int64_number_+Infinity %{public}d', testNapi.getValueInt64(+Infinity));
hilog.info(0x0000, 'Node-API', 'get_value_int64_number_-Infinity %{public}d', testNapi.getValueInt64(-Infinity));
```
<!-- @[ark_napi_get_value_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

### napi_get_value_double

Use **napi_get_value_double** to convert an ArkTS value to a C double value.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetDouble(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    double value = 0;
    napi_status status = napi_get_value_double(env, args[0], &value);
    // If a non-number is passed in, napi_number_expected will be thrown.
    if (status != napi_ok) {
        return nullptr;
    }
    napi_value result = nullptr;
    napi_create_double(env, value, &result);
    return result;
}
```
<!-- @[napi_get_value_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getDouble: (value: number | string) => number | undefined;
```
<!-- @[napi_get_value_double_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
// If a number is passed in, the number will be returned.
hilog.info(0x0000, 'Node-API', 'get_value_double_number %{public}d', testNapi.getDouble(80.885));
// If a non-number is passed in, undefined will be returned.
hilog.info(0x0000, 'Node-API', 'get_value_double_not_number %{public}s', testNapi.getDouble('sAs'));
```
<!-- @[ark_napi_get_value_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

### napi_create_int32

Use **napi_create_int32** to create an ArkTS number from a 32-bit signed integer.

CPP code:

```cpp
#include "napi/native_api.h"
static constexpr int INT_NUM_NEG_26 = -26;   // Integer -26

static napi_value CreateInt32(napi_env env, napi_callback_info info)
{
    // int32_t represents a 32-bit signed integer, ranging from -2^31 to 2^31 - 1, that is, -2147483648 to 2147483647.
    // 
    int32_t value = INT_NUM_NEG_26;
    // Create an ArkTS Int32 number.
    napi_value result = nullptr;
    napi_status status = napi_create_int32(env, value, &result);
    if (status != napi_ok) {
        // Error handling.
        napi_throw_error(env, nullptr, "Failed to create int32 value");
    }
    return result;
}
```
<!-- @[napi_create_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const createInt32: () => number;
```
<!-- @[napi_create_int32_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag','Test Node-API napi_create_int32: ' + testNapi.createInt32());
```
<!-- @[ark_napi_create_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

### napi_create_uint32

Use **napi_create_uint32** to create an ArkTS number from a 32-bit unsigned integer.

CPP code:

```cpp
#include "napi/native_api.h"
static constexpr int INT_NUM_26 = 26;   // Integer 26

static napi_value CreateUInt32(napi_env env, napi_callback_info info)
{
    // If the uint32_t type is used to represent -26, overflow occurs. Modulo operation is performed on the result to convert the binary complement of the negative number to a positive number. That is, 4294967270 will be returned.
    // uint32_t represents a 32-bit unsigned integer, ranging from 0 to 2^32 - 1, that is, 0 to 4294967295.
    // 
    uint32_t value = INT_NUM_26;
    // Create an ArkTS Uint32 number.
    napi_value result = nullptr;
    napi_status status = napi_create_uint32(env, value, &result);
    if (status != napi_ok) {
        // Error handling.
        napi_throw_error(env, nullptr, "Failed to create uint32 value");
    }
    return result;
}
```
<!-- @[napi_create_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const createUInt32: () => number;
```
<!-- @[napi_create_uint32_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag','Test Node-API napi_create_uint32: ' + testNapi.createUInt32());
```
<!-- @[ark_napi_create_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

### napi_create_int64

Use **napi_create_int64** to create an ArkTS number from a 64-bit signed integer.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CreateInt64(napi_env env, napi_callback_info info)
{
    // 
    int64_t value = 2147483648;
    // Create an ArkTS number using the given value. Only integers in the range from -2^53 + 1 to 2^53 - 1 (inclusive) can be accurately represented.
    // If the value to be represented exceeds 2^53, use napi_create_bigint64.
    napi_value result = nullptr;
    napi_status status = napi_create_int64(env, value, &result);
    if (status != napi_ok) {
        // Error handling.
        napi_throw_error(env, nullptr, "Failed to create int64 value");
    }
    return result;
}
```
<!-- @[napi_create_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const createInt64: () => number;
```
<!-- @[napi_create_int64_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag','Test Node-API napi_create_int64: ' + testNapi.createInt64());
```
<!-- @[ark_napi_create_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

### napi_create_double

Use **napi_create_double** to create an ArkTS number from a double-precision floating-point number.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CreateDouble(napi_env env, napi_callback_info info)
{
    double value = 1.234;
    // Create an ArkTS double number.
    napi_value result = nullptr;
    napi_status status = napi_create_double(env, value, &result);
    if (status != napi_ok) {
        // Error handling.
        napi_throw_error(env, nullptr, "Failed to create double value");
    }
    return result;
}
```
<!-- @[napi_create_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const createDouble: () => number;
```
<!-- @[napi_create_double_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag','Test Node-API napi_create_double: ' + testNapi.createDouble());
```
<!-- @[ark_napi_create_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
