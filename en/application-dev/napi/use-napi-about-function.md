# Working with Functions Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=2cc827181a31e0a77238ca42eb3b41991d5fd686 translatedAt=2026-08-12T06:40:06.561Z pushedAt=2026-08-12T11:14:17.703Z -->

## Introduction

Node-API provides APIs for calling ArkTS functions and passing parameters or creating ArkTS functions in C/C++.

## Basic Concepts

Functions are blocks of reusable code that performs specific tasks or operations. You can define functions to implement different operations. Functions provide a way to modularize and structure code, helping make your code more organized, reusable, and maintainable.

## Available APIs

| API| Description|
| -------- | -------- |
| napi_get_cb_info | Obtains detailed information about the call, such as the parameters and **this** pointer, from the given callback information.|
| napi_call_function | Calls an ArkTS function from a C/C++ addon.|
| napi_create_function | Creates an ArkTS function based on a C/C++ function.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code related to function invocation.

## napi_get_cb_info

Use **napi_get_cb_info** to obtain detailed information about function calls.

CPP code:

<!-- @[napi_get_cb_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/cpp/napi_init.cpp) --> 

``` C++
#include "napi/native_api.h"

// napi_get_cb_info
// Obtain parameter information of the input arguments from the ArkTS side.
static napi_value GetCbArgs(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    return args[0];
}

// Obtain the number of input arguments from the ArkTS side.
static napi_value GetCbArgQuantity(napi_env env, napi_callback_info info)
{
    size_t argc = 0;
    napi_value result = nullptr;
    napi_get_cb_info(env, info, &argc, nullptr, nullptr, nullptr);
    napi_create_int32(env, argc, &result);
    return result;
}

// Obtain the this parameter from the ArkTS side.
static napi_value GetCbContext(napi_env env, napi_callback_info info)
{
    napi_value thisArg = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &thisArg, nullptr);
    return thisArg;
}
```

API declaration:

<!-- @[napi_get_cb_info_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const getCbArgs: <T>(arg: T) => T; // napi_get_cb_info

// The input arguments of getCbArgQuantity are user-defined. In this example, two arguments are used: one string and one number.
export const getCbArgQuantity: (str: string, num: number) => number;

export const getCbContext: () => Object;
```

ArkTS code:

<!-- @[ark_napi_get_cb_info_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

function summation(arr: Array<number>) {
  let sum: number = 0;
  for (let i = 0; i < arr.length; i++) {
    sum += arr[i];
  }
  return sum;
}

const str = 'message';
const arr = [0, 1, 2, 3, 4, 5];
const num = 526;

class Student {
  name: string;
  age: number;
  score: number;

  constructor(name: string, age: number, score: number) {
    this.name = name;
    this.age = age;
    this.score = score;
  }
}
```

<!-- @[ark_napi_get_cb_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// napi_get_cb_info
let student = new Student('Alice', 18, 100);
// Obtain parameters.
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get string arg:%{public}s',
  testNapi.getCbArgs(str));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get array arg:%{public}s ',
  testNapi.getCbArgs(arr).toString());
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get num arg:%{public}d ',
  testNapi.getCbArgs(num));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get undefined arg:%{public}s ',
  testNapi.getCbArgs(undefined));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get object arg:%{public}s ',
  JSON.stringify(testNapi.getCbArgs(student)));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get function arg:%{public}d ',
  testNapi.getCbArgs(summation(arr)));
// Obtain the number of arguments.
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get arg quantity:%{public}d ',
  testNapi.getCbArgQuantity(str, num));
// Obtain the context.
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get thisArg:%{public}s ',
  testNapi.getCbContext().toString());
```

## napi_call_function

Use **napi_call_function** to call an ArkTS function from a C/C++ addon.

**Note:** The length of argv passed to napi_call_function must be no less than argc; if argc is 0, nullptr can be passed; otherwise, each argv element must be a valid `napi_value`.

CPP code:

<!-- @[napi_call_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/cpp/napi_init.cpp) --> 

``` C++
// napi_call_function
constexpr int ARG_NUM = 10;
static napi_value CallFunction(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    // Obtain the input arguments from the ArkTS side.
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Obtain the global object. Here, global is used because the second parameter of napi_call_function is the this argument of the JS function.
    napi_value global = nullptr;
    napi_get_global(env, &global);
    // Create a numeric input argument.
    napi_value args[1] = {nullptr};
    napi_create_int32(env, ARG_NUM, &args[0]);
    // Call the ArkTS method.
    napi_value result = nullptr;
    // When calling napi_call_function, the length of argv must be greater than or equal to the number declared by argc.
    napi_call_function(env, global, argv[0], 1, args, &result);
    return result;
}

static napi_value ObjCallFunction(napi_env env, napi_callback_info info)
{
    // Obtain the two arguments passed from the ArkTS side.
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    // Obtain the input arguments from the ArkTS side.
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Call the ArkTS method.
    napi_value result = nullptr;
    // The age method has no input arguments. Pass 0 for argc and nullptr for argv in napi_call_function.
    napi_call_function(env, argv[0], argv[1], 0, nullptr, &result);
    return result;
}
```

API declaration:

<!-- @[napi_call_function_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const callFunction: (func: Function) => number; // napi_call_function

export const objCallFunction: (obj: Object, func: Function) => number;
```

ArkTS code:

<!-- @[ark_napi_call_function_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
function returnNumber(num: number) {
  return num;
}

class Person {
  age(): number {
    return 11;
  }
}
```

<!-- @[ark_napi_call_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// napi_call_function
const person = new Person();
hilog.info(0x0000, 'testTag', 'Test Node-API call_function:%{public}d',
  testNapi.callFunction(returnNumber));
hilog.info(0x0000, 'testTag', 'Test Node-API call_function:%{public}d',
  testNapi.objCallFunction(person, person.age));
```

## napi_create_function

Use **napi_create_function** to create an ArkTS function object in native code, which allows calling into the native code from ArkTS. This API returns a **napi_value** that represents the function created.

CPP code:

<!-- @[napi_create_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/cpp/napi_init.cpp) --> 

``` C++
// napi_create_function
static napi_value CalculateArea(napi_env env, napi_callback_info info)
{
    // Obtain the two arguments passed from the ArkTS side.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    double width = 0;
    napi_get_value_double(env, args[0], &width);
    double height = 0;
    napi_get_value_double(env, args[1], &height);
    napi_value area = nullptr;
    napi_create_double(env, width * height, &area);
    return area;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    // ...
    napi_value fn = nullptr;
    napi_create_function(env, nullptr, 0, CalculateArea, nullptr, &fn);
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    napi_set_named_property(env, exports, "calculateArea", fn);
    return exports;
}
EXTERN_C_END
```

API declaration:

<!-- @[napi_create_function_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const calculateArea: (width: number, height: number) => number; // napi_create_function
```

ArkTS code:

<!-- @[ark_napi_create_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// napi_create_function
hilog.info(0x0000, 'testTag', 'Test Node-API create_function:%{public}d ',
  testNapi.calculateArea(1.2, 4));
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```