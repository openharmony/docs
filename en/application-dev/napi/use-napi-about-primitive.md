# Working with Primitives Using Node-API
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## Introduction

With Node-API APIs, developers can interact with ArkTS objects in the Node-API module to transform data and obtain specific objects. These operations play an important role in different scenarios, enabling developers to process ArkTS values and objects more flexibly.

## Basic Concepts

Before using Node-API to operate ArkTS objects, you need to understand the following basic concepts:

- Conversion between ArkTS and C/C primitives: You can use Node-API to convert ArkTS values to C/C++ data types, for example, convert an ArkTS value into a C/C++ integer and convert an ArkTS string into a C/C++ string array. You can also convert C/C++ data into an ArkTS value and return the ArkTS value to ArkTS.

## Available APIs

The following APIs are used to interact with ArkTS from C/C++ code, transfer data, and perform operations.
| API| Description|
| -------- | -------- |
| napi_coerce_to_bool | Forcibly converts the given ArkTS value to an ArkTS Boolean value.|
| napi_coerce_to_number | Forcibly converts the given ArkTS value to an ArkTS number.|
| napi_coerce_to_object | Forcibly converts the given ArkTS value to an ArkTS object.|
| napi_coerce_to_string | Forcibly converts the given ArkTS value to an ArkTS string.|
| napi_get_boolean | Obtains the ArkTS boolean value based on the given C boolean value.|
| napi_get_value_bool | Obtains the C/C++ equivalent of the given ArkTS Boolean value.|
| napi_get_global | Obtains an ArkTS global object so that it can be accessed and manipulated in C/C++.|
| napi_get_null | Obtains ArkTS null.|
| napi_get_undefined | Obtains ArkTS undefined.|

## Example

For details about the Node-API development process, see [Using Node-APIs to Implement Cross-Language Interactive Development](use-napi-process.md). This document describes only the C++ and ArkTS code corresponding to the APIs.

### napi_coerce_to_bool

Call **napi_coerce_to_bool** to forcibly convert an ArkTS value to an ArkTS Boolean value.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CoerceToBool(napi_env env, napi_callback_info info)
{
    // Obtain and parse the parameters passed in.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the input value to a Boolean value.
    napi_value result = nullptr;
    napi_coerce_to_bool(env, args[0], &result);
    // Return the ArkTS boolean value.
    return result;
}
```
<!-- @[napi_coerce_to_bool](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const coerceToBool: <T>(data: T) => boolean;
```
<!-- @[napi_coerce_to_bool_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let value = testNapi.coerceToBool<number>(0);
let str = testNapi.coerceToBool<string>('111111111');
let obj = new Object();
let res = testNapi.coerceToBool<Object>(obj);
let result = testNapi.coerceToBool<null>(null);
// false
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_bool:%{public}s', value);
// true
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_bool:%{public}s', str);
// true
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_bool:%{public}s', res);
// false
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_bool:%{public}s', result);
```
<!-- @[ark_napi_coerce_to_bool](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

### napi_coerce_to_number

Forcibly converts the given ArkTS value to an ArkTS number.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CoerceToNumber(napi_env env, napi_callback_info info)
{
    // Obtain and parse the parameters passed in.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the input value to a number.
    napi_value result = nullptr;
    napi_coerce_to_number(env, args[0], &result);
    return result;
}
```
<!-- @[napi_coerce_to_number](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const coerceToNumber: <T>(data: T) => number;
```
<!-- @[napi_coerce_to_number_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let value = testNapi.coerceToNumber<string>('2556');
let str = testNapi.coerceToNumber<string>('sssss');
let bool = testNapi.coerceToNumber<boolean>(true);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_number:%{public}d', value);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_number:%{public}d', str);    // The value is NAN.
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_number:%{public}d', bool);   // The value is 1.
```
<!-- @[ark_napi_coerce_to_number](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

### napi_coerce_to_object

Call **napi_coerce_to_object** to forcibly convert an ArkTS value to an ArkTS object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CoerceToObject(napi_env env, napi_callback_info info)
{
    // Obtain and parse the parameters passed in.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_value obj = nullptr;
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the input value to an object.
    napi_coerce_to_object(env, args[0], &obj);
    return obj;
}
```
<!-- @[napi_coerce_to_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const coerceToObject: <T>(data: T) => Object;
```
<!-- @[napi_coerce_to_object_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let value = testNapi.coerceToObject<string>('222222');
let result = testNapi.coerceToObject<number>(111);
hilog.info(0x0000, 'testTag', 'Node-API coerceToObject:%{public}s.', typeof result);
if (typeof value === 'object') {
  hilog.info(0x0000, 'testTag', 'Node-API The value is an object.');
} else {
  hilog.info(0x0000, 'testTag', 'Node-API The value is not an object.');
}
```
<!-- @[ark_napi_coerce_to_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

### napi_coerce_to_string

Call **napi_coerce_to_string** to forcibly convert an ArkTS value to an ArkTS string.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CoerceToString(napi_env env, napi_callback_info info)
{
    // Obtain and parse the parameters passed in.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the input value to a string.
    napi_value str = nullptr;
    napi_coerce_to_string(env, args[0], &str);
    return str;
}
```
<!-- @[napi_coerce_to_string](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const coerceToString: <T>(data: T) => string;
```
<!-- @[napi_coerce_to_string_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let value = testNapi.coerceToString<number>(212);
let obj = new Object();
let res = testNapi.coerceToString<Object>(obj);
let bool = testNapi.coerceToString<boolean>(false);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_string:%{public}s', value);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_string:%{public}s', typeof res);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_string:%{public}s', bool);
```
<!-- @[ark_napi_coerce_to_string](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

### napi_get_boolean

Obtains the equivalent ArkTS Boolean value based on the given C Boolean value.

CPP code:

```cpp
#include "napi/native_api.h"
#include "hilog/log.h"

static napi_value GetBoolean(napi_env env, napi_callback_info info)
{
    // Pass in two parameters and parse them.
    size_t argc = 2;
    napi_value argv[2];
    napi_valuetype data, value;
    napi_status status = napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "napi_get_cb_info failed");
        return nullptr;
    }
    // Check the types of the two parameters.
    napi_typeof(env, argv[0], &data);
    napi_typeof(env, argv[1], &value);

    napi_value returnValue = nullptr;
    // Check whether the types of the two parameters are the same and return the result via a Boolean value.
    status = napi_get_boolean(env, data == value, &returnValue);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "napi_get_boolean failed");
        return nullptr;
    }
    // Return the result.
    return returnValue;
}
```
<!-- @[napi_get_boolean](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getBoolean: <T>(data: T, value: string) => boolean;
```
<!-- @[napi_get_boolean_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let value = testNapi.getBoolean<number>(1, '1');
let data = testNapi.getBoolean<string>('sss', '1');
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_boolean:%{public}s', value);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_boolean:%{public}s', data);
```
<!-- @[ark_napi_get_boolean](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

### napi_get_value_bool

Call **napi_get_value_bool** to obtain the C Boolean equivalent of an ArkTS Boolean value.

CPP code:

```cpp
#include "napi/native_api.h"
#include "hilog/log.h"

static napi_value GetValueBool(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};

    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    bool bool_c = false;
    napi_status status = napi_get_value_bool(env, args[0], &bool_c);
    if (status == napi_boolean_expected) {
        // If napi_get_value_bool is successful, napi_ok is returned. If a non-Boolean value is passed in, napi_boolean_expected is returned.
        return nullptr;
    }
    napi_value boolNapi = nullptr;
    status = napi_get_boolean(env, bool_c, &boolNapi);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "napi_get_boolean failed");
        return nullptr;
    }
    return boolNapi;
}
```
<!-- @[napi_get_value_bool](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getValueBool: (value: boolean | string) => boolean | undefined;
```
<!-- @[napi_get_value_bool_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

// Pass in a Boolean value and a non-Boolean value. After the Boolean value is passed in, the Boolean value is returned. After the non-Boolean value is passed in, undefined is returned.
hilog.info(0x0000, 'Node-API', 'get_value_bool_not_bool %{public}s', testNapi.getValueBool ('Hello 123'));
hilog.info(0x0000, 'Node-API', 'get_value_bool_true %{public}s', testNapi.getValueBool(true));
hilog.info(0x0000, 'Node-API', 'get_value_bool_false %{public}s', testNapi.getValueBool(false));
```
<!-- @[ark_napi_get_value_bool](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

### napi_get_global

Obtains a global ArkTS object. This function is used to obtain the napi_value of the ArkTS global object so that the C/C++ module can interact with the ArkTS global object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetGlobal(napi_env env, napi_callback_info info)
{
    napi_value global = nullptr;
    // Obtains a global object.
    napi_get_global(env, &global);
    return global;
}
```
<!-- @[napi_get_global](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getGlobal: () => Object;
```
<!-- @[napi_get_global_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let globalObj = testNapi.getGlobal();
// Check whether the obtained global object has its own properties.
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_global:%{public}s', globalObj.hasOwnProperty!("undefined"));
```
<!-- @[ark_napi_get_global](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

### napi_get_null

Obtains the null value in ArkTS.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetNull(napi_env env, napi_callback_info info)
{
    napi_value nullValue = nullptr;
    napi_get_null(env, &nullValue);
    return nullValue;
}
```
<!-- @[napi_get_null](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getNull: () => null;
```
<!-- @[napi_get_null_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let value = testNapi.getNull();
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_null:%{public}s', value);
```
<!-- @[ark_napi_get_null](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

### napi_get_undefined

Obtains the undefined value in ArkTS.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetUndefined(napi_env env, napi_callback_info info)
{
    // Obtain and parse the parameters passed in.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    napi_value value = nullptr;
    napi_get_undefined(env, &value);
    // Check whether the input parameter is equal to the ArkTS 'undefined' in both the type and value.
    bool isEqual = false;
    napi_strict_equals(env, args[0], value, &isEqual);
    // Return a value based on the strict equality check.
    napi_value result = nullptr;
    // Return true if the two parameters are equal, return false otherwise.
    napi_get_boolean(env, isEqual, &result);
    return result;
}
```
<!-- @[napi_get_undefined](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getUndefined: (value: undefined) => boolean;
```
<!-- @[napi_get_undefined_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let data: undefined = undefined;
let value = testNapi.getUndefined(data);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_undefined:%{public}s', value);
```
<!-- @[ark_napi_get_undefined](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
