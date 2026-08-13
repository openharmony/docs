# Working with Primitives Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:41:04.492Z pushedAt=2026-08-12T11:14:35.034Z -->

## Introduction

Node-API provides APIs for converting data between C/C++ and ArkTS data types and obtaining the ArkTS objects in specified format.

## Basic Concepts

Before using Node-API to operate ArkTS objects, you need to understand the following basic concepts:

- Conversion between ArkTS and C/C primitives: You can use Node-API to convert ArkTS values to C/C++ data types, for example, convert an ArkTS value into a C/C++ integer and convert an ArkTS string into a C/C++ string array. You can also convert C/C++ data into an ArkTS value and return the ArkTS value to ArkTS.

## Available APIs

The following table lists the APIs for converting data between ArkTS and C/C++ types.

| API| Description|
| -------- | -------- |
| napi_coerce_to_bool | Forcibly converts an ArkTS value to an ArkTS Boolean value.|
| napi_coerce_to_number | Forcibly converts an ArkTS value to an ArkTS number.|
| napi_coerce_to_object | Forcibly converts an ArkTS value to an ArkTS object.|
| napi_coerce_to_string | Forcibly converts an ArkTS value to an ArkTS string.|
| napi_get_boolean | Obtains the ArkTS Boolean value based on the given C Boolean value.|
| napi_get_value_bool | Obtains the C/C++ equivalent of the given ArkTS Boolean value.|
| napi_get_global | Obtains an ArkTS global object so that it can be accessed and manipulated in C/C++.|
| napi_get_null | Obtains the ArkTS **null**.|
| napi_get_undefined | Obtains the ArkTS **undefined**.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code involved in related APIs.

### napi_coerce_to_bool

Call **napi_coerce_to_bool** to forcibly convert an ArkTS value to an ArkTS Boolean value.

CPP code:

<!-- @[napi_coerce_to_bool](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_coerce_to_bool
static napi_value CoerceToBool(napi_env env, napi_callback_info info)
{
    // Get and parse the passed parameters.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the passed value to a boolean value.
    napi_value result = nullptr;
    napi_coerce_to_bool(env, args[0], &result);
    // Return the ArkTS boolean value after casting.
    return result;
}
```

API declaration:

<!-- @[napi_coerce_to_bool_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const coerceToBool: <T>(data: T) => boolean; // napi_coerce_to_bool
```

ArkTS code:

<!-- @[ark_napi_coerce_to_bool](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_coerce_to_bool
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

### napi_coerce_to_number

Call **napi_coerce_to_number** to forcibly convert an ArkTS value to an ArkTS number.

CPP code:

<!-- @[napi_coerce_to_number](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_coerce_to_number
static napi_value CoerceToNumber(napi_env env, napi_callback_info info)
{
    // Get and parse the passed parameters.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the passed value to a number value.
    napi_value result = nullptr;
    napi_coerce_to_number(env, args[0], &result);
    return result;
}
```

API declaration:

<!-- @[napi_coerce_to_number_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const coerceToNumber: <T>(data: T) => number; // napi_coerce_to_number
```

ArkTS code:

<!-- @[ark_napi_coerce_to_number](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_coerce_to_number
let value = testNapi.coerceToNumber<string>('2556');
let str = testNapi.coerceToNumber<string>('sssss');
let bool = testNapi.coerceToNumber<boolean>(true);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_number:%{public}d', value);
// The returned value is NaN.
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_number:%{public}d', str);
// The returned value is 1.
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_number:%{public}d', bool);
```

### napi_coerce_to_object

Call **napi_coerce_to_object** to forcibly convert an ArkTS value to an ArkTS object.

CPP code:

<!-- @[napi_coerce_to_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_coerce_to_object
static napi_value CoerceToObject(napi_env env, napi_callback_info info)
{
    // Get and parse the passed parameters.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_value obj = nullptr;
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the passed value to an Object value.
    napi_coerce_to_object(env, args[0], &obj);
    return obj;
}
```

API declaration:

<!-- @[napi_coerce_to_object_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) -->  

``` TypeScript
export const coerceToObject: <T>(data: T) => Object; // napi_coerce_to_object
```

ArkTS code:

<!-- @[ark_napi_coerce_to_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_coerce_to_object
let value = testNapi.coerceToObject<string>('222222');
let result = testNapi.coerceToObject<number>(111);
hilog.info(0x0000, 'testTag', 'Node-API coerceToObject:%{public}s.', typeof result);
if (typeof value === 'object') {
  hilog.info(0x0000, 'testTag', 'Node-API The value is an object.');
} else {
  hilog.info(0x0000, 'testTag', 'Node-API The value is not an object.');
}
```

### napi_coerce_to_string

Call **napi_coerce_to_string** to forcibly convert an ArkTS value to an ArkTS string.

CPP code:

<!-- @[napi_coerce_to_string](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_coerce_to_string
static napi_value CoerceToString(napi_env env, napi_callback_info info)
{
    // Get and parse the passed parameters.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the passed value to a string.
    napi_value str = nullptr;
    napi_coerce_to_string(env, args[0], &str);
    return str;
}
```

API declaration:

<!-- @[napi_coerce_to_string_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const coerceToString: <T>(data: T) => string; // napi_coerce_to_string
```

ArkTS code:

<!-- @[ark_napi_coerce_to_string](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_coerce_to_string
let value = testNapi.coerceToString<number>(212);
let obj = new Object();
let res = testNapi.coerceToString<Object>(obj);
let bool = testNapi.coerceToString<boolean>(false);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_string:%{public}s', value);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_string:%{public}s', typeof res);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_string:%{public}s', bool);
```

### napi_get_boolean

Call **napi_get_boolean** to obtain the ArkTS Boolean value based on the given C Boolean value.

CPP code:

<!-- @[napi_get_boolean](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_boolean
static napi_value GetBoolean(napi_env env, napi_callback_info info)
{
    // Pass and parse two parameters.
    size_t argc = 2;
    napi_value argv[2];
    napi_valuetype data = napi_undefined;
    napi_valuetype value = napi_undefined;
    napi_status status = napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "napi_get_cb_info failed");
        return nullptr;
    }
    // Determine the type values of the two parameters.
    napi_typeof(env, argv[0], &data);
    napi_typeof(env, argv[1], &value);

    napi_value returnValue = nullptr;
    // Determine whether the two type values are equal, and obtain the boolean value of the result.
    status = napi_get_boolean(env, data == value, &returnValue);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "napi_get_boolean failed");
        return nullptr;
    }
    // Return the result.
    return returnValue;
}
```

API declaration:

<!-- @[napi_get_boolean_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const getBoolean: <T>(data: T, value: String) => boolean; // napi_get_boolean
```

ArkTS code:

<!-- @[ark_napi_get_boolean](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_boolean
let value = testNapi.getBoolean<number>(1, '1');
let data = testNapi.getBoolean<string>('sss', '1');
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_boolean:%{public}s', value);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_boolean:%{public}s', data);
```

### napi_get_value_bool

Call **napi_get_value_bool** to obtain the C Boolean equivalent of an ArkTS Boolean value.

CPP code:

<!-- @[napi_get_value_bool](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_value_bool
static napi_value GetValueBool(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};

    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    bool boolC = false;
    napi_status status = napi_get_value_bool(env, args[0], &boolC);
    if (status == napi_boolean_expected) {
        // If napi_get_value_bool succeeds, napi_ok is returned. If a non-boolean value is passed, napi_boolean_expected is returned.
        return nullptr;
    }
    napi_value boolNapi = nullptr;
    status = napi_get_boolean(env, boolC, &boolNapi);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "napi_get_boolean failed");
        return nullptr;
    }
    return boolNapi;
}
```

API declaration:

<!-- @[napi_get_value_bool_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const getValueBool: (value: boolean | string) => boolean | undefined; // napi_get_value_bool
```

ArkTS code:

<!-- @[ark_napi_get_value_bool](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_value_bool
// Pass a boolean value and a non-boolean value to test the API. Passing a boolean value returns the original boolean value, and passing other types returns undefined.
hilog.info(0x0000, 'Node-API', 'get_value_bool_not_bool %{public}s',
  testNapi.getValueBool('Hello123'));
hilog.info(0x0000, 'Node-API', 'get_value_bool_true %{public}s', testNapi.getValueBool(true));
hilog.info(0x0000, 'Node-API', 'get_value_bool_false %{public}s', testNapi.getValueBool(false));
```

### napi_get_global

Call **napi_get_global** to obtain an ArkTS global object. You can use this API to obtain the **napi_value** that represents an ArkTS global object, so that the global object of the ArkTS runtime can be called by C/C++.

CPP code:

<!-- @[napi_get_global](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_global
static napi_value GetGlobal(napi_env env, napi_callback_info info)
{
    napi_value global = nullptr;
    // Obtain the global object.
    napi_get_global(env, &global);
    return global;
}
```

API declaration:

<!-- @[napi_get_global_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const getGlobal: () => Object; // napi_get_global
```

ArkTS code:

<!-- @[ark_napi_get_global](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_global
let globalObj = testNapi.getGlobal();
// Determine whether the obtained global object has its own properties.
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_global:%{public}s',
  globalObj.hasOwnProperty!("undefined"));
```

### napi_get_null

Call **napi_get_null** to obtain **null** in ArkTS.

CPP code:

<!-- @[napi_get_null](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_null
static napi_value GetNull(napi_env env, napi_callback_info info)
{
    napi_value nullValue = nullptr;
    napi_get_null(env, &nullValue);
    return nullValue;
}
```

API declaration:

<!-- @[napi_get_null_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const getNull: () => null; // napi_get_null
```

ArkTS code:

<!-- @[ark_napi_get_null](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_null
let value = testNapi.getNull();
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_null:%{public}s', value);
```

### napi_get_undefined

Call **napi_get_undefined** to obtain **undefined** in ArkTS.

CPP code:

<!-- @[napi_get_undefined](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_undefined
static napi_value GetUndefined(napi_env env, napi_callback_info info)
{
    // Get and parse the passed parameters.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    napi_value value = nullptr;
    napi_get_undefined(env, &value);
    // Determine whether the type of the passed parameter is consistent with the type of the undefined value.
    bool isEqual = false;
    napi_strict_equals(env, args[0], value, &isEqual);
    // The parameter is equal to the undefined value.
    napi_value result = nullptr;
    // Return the result after type determination. Returns true if equal, and false if not.
    napi_get_boolean(env, isEqual, &result);
    return result;
}
```

API declaration:

<!-- @[napi_get_undefined_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const getUndefined: (value: undefined) => boolean; // napi_get_undefined
```

ArkTS code:

<!-- @[ark_napi_get_undefined](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPrimitive/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_undefined
let data: undefined = undefined;
let value = testNapi.getUndefined(data);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_undefined:%{public}s', value);
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```