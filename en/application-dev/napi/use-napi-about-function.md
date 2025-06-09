# Creating and Calling Functions Using Node-API

## Introduction

Node-API provides APIs for calling ArkTS functions and passing parameters or creating ArkTS methods in C/C++.

## Basic Concepts

Functions are blocks of reusable code that performs specific tasks or operations. You can define functions to implement different operations. Functions provide a way to modularize and structure code, helping make your code more organized, reusable, and maintainable.

## Available APIs

| API| Description|
| -------- | -------- |
| napi_get_cb_info | Obtains detailed information about the call, such as the parameters and **this** pointer, from the given callback information.|
| napi_call_function | Calls an ArkTS function from a C/C++ addon.|
| napi_create_function | Creates an ArkTS function based on a C/C++ function.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code related to function invocation. The **napi_create_function** API is different. For details, see the example.

## napi_get_cb_info

Use **napi_get_cb_info** to obtain detailed information about function calls.

CPP code:

```cpp
#include "napi/native_api.h"
// Obtain information about the parameters passed from ArkTS.
static napi_value GetCbArgs(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    return args[0];
}
// Obtain the number of parameters passed from ArkTS.
static napi_value GetCbArgQuantity(napi_env env, napi_callback_info info)
{
    size_t argc = 0;
    napi_value result = nullptr;
    napi_get_cb_info(env, info, &argc, nullptr, nullptr, nullptr);
    napi_create_int32(env, argc, &result);
    return result;
}
// Obtain thisArg passed from ArkTS.
static napi_value GetCbContext(napi_env env, napi_callback_info info)
{
    napi_value thisArg = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &thisArg, nullptr);
    return thisArg;
}
```

API declaration:

```ts
// index.d.ts
export const getCbArgs: <T>(arg: T) => T;
// The input parameters of getCbArgQuantity are customized. In this example, two input parameters are used: string and number.
export const getCbArgQuantity: (str: string, num: number) => number;
export const getCbContext: () => Object;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog';
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
let student = new Student('Alice', 18, 100);
// Obtain parameters.
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get string arg:%{public}s', testNapi.getCbArgs(str));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get array arg:%{public}s ', testNapi.getCbArgs(arr).toString());
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get num arg:%{public}d ', testNapi.getCbArgs(num));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get undefined arg:%{public}s ', testNapi.getCbArgs(undefined));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get object arg:%{public}s ', JSON.stringify(testNapi.getCbArgs(student)));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get function arg:%{public}d ', testNapi.getCbArgs(summation(arr)));
// Obtain the number of parameters.
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get arg quantity:%{public}d ', testNapi.getCbArgQuantity(str, num));
// Obtain the context.
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get thisArg:%{public}s ', testNapi.getCbContext().toString());
```

## napi_call_function

Use **napi_call_function** to call an ArkTS function from a C/C++ addon.
>**NOTE**<br>The length of **argv** passed by **napi_call_function** must be greater than or equal to the value of **argc** and must be initialized to **nullptr**.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CallFunction(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    // Obtain the parameters passed from ArkTS.
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Obtain the global object. Here, global is used because the second parameter of napi_call_function is the this parameter of the ArkTS function.
    napi_value global = nullptr;
    napi_get_global(env, &global);
    // Call the ArkTS method.
    napi_value result = nullptr;
    // The length of argv passed by napi_call_function must be greater than or equal to the value of argc and must be initialized to nullptr.
    napi_call_function(env, global, argv[0], argc, argv, &result);
    return result;
}

static napi_value ObjCallFunction(napi_env env, napi_callback_info info)
{
    // Obtain the two parameters passed from ArkTS.
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    // Obtain the parameters passed from ArkTS.
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Call the ArkTS method.
    napi_value result = nullptr;
    // The length of argv passed by napi_call_function must be greater than or equal to the value of argc and must be initialized to nullptr.
    napi_call_function(env, argv[0], argv[1], argc, argv, &result);
    return result;
}
```

API declaration:

```ts
// index.d.ts
export const callFunction: (func: Function) => number;
export const objCallFunction: (obj: Object, func: Function) => number;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

function returnNumber() {
  return 10;
}
class Person {
  age(): number {
    return 11;
  }
}
const person = new Person();
hilog.info(0x0000, 'testTag', 'Test Node-API call_function:%{public}d', testNapi.callFunction(returnNumber));
hilog.info(0x0000, 'testTag', 'Test Node-API call_function:%{public}d', testNapi.objCallFunction(person,person.age));
```

## napi_create_function

Use **napi_create_function** to create an ArkTS function object in native code, which allows calling into the native code from ArkTS. This API returns a **napi_value** that represents the function created.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CalculateArea(napi_env env, napi_callback_info info)
{
    // Obtain the two parameters passed from ArkTS.
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
static napi_value Init(napi_env env, napi_value exports) {
    napi_value fn = nullptr;
    napi_create_function(env, nullptr, 0, CalculateArea, nullptr, &fn);
    napi_set_named_property(env, exports, "calculateArea", fn);
    return exports;
}
EXTERN_C_END
```

API declaration:

```ts
// index.d.ts
export const calculateArea: (width: number, height: number) => number;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag', 'Test Node-API create_function:%{public}d ', testNapi.calculateArea(1.2, 4));
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
