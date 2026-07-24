# 使用Node-API接口进行函数创建和调用
<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

## 简介

函数调用允许开发者从Node-API模块中调用ArkTS函数并传递参数，或在Node-API模块中创建ArkTS函数。

## 基本概念

函数是一种非常重要的编程概念，可以执行特定的任务或操作、提高代码的可读性、把复杂任务简化、提高代码复用性以及支持代码的组织与管理。每个函数可以负责不同的功能，提供一种将代码模块化和组织结构化的方式，使其更易于理解、维护和重用。

## 场景和功能介绍

| 接口 | 描述 |
| -------- | -------- |
| napi_get_cb_info | 当需要从给定的callback info中获取有关调用的参数信息和this指针时，可使用此接口。 |
| napi_call_function | 当需要在Node-API模块中对ArkTS侧函数进行调用时，可使用此接口。 |
| napi_create_function | 当需要将C/C++函数创建为ArkTS函数时，可以使用此接口。 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。
## napi_get_cb_info

获取有关函数调用的详细信息。

cpp部分代码

<!-- @[napi_get_cb_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/cpp/napi_init.cpp) --> 

``` C++
#include "napi/native_api.h"

// napi_get_cb_info
// 获取ArkTS侧入参的参数信息
static napi_value GetCbArgs(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    return args[0];
}

// 获取ArkTS侧入参的参数个数
static napi_value GetCbArgQuantity(napi_env env, napi_callback_info info)
{
    size_t argc = 0;
    napi_value result = nullptr;
    napi_get_cb_info(env, info, &argc, nullptr, nullptr, nullptr);
    napi_create_int32(env, argc, &result);
    return result;
}

// 获取ArkTS侧this参数
static napi_value GetCbContext(napi_env env, napi_callback_info info)
{
    napi_value thisArg = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &thisArg, nullptr);
    return thisArg;
}
```

接口声明

<!-- @[napi_get_cb_info_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const getCbArgs: <T>(arg: T) => T; // napi_get_cb_info

// getCbArgQuantity的入参由用户自定义，在此用例中，我们用两个入参，一个是string，一个是number
export const getCbArgQuantity: (str: string, num: number) => number;

export const getCbContext: () => Object;
```

ArkTS 侧示例代码

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
// 获取参数
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
// 获取参数个数
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get arg quantity:%{public}d ',
  testNapi.getCbArgQuantity(str, num));
// 获取上下文
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_cb_info get thisArg:%{public}s ',
  testNapi.getCbContext().toString());
```

## napi_call_function

在C/C++侧对ArkTS函数进行调用。

注意事项：napi_call_function传入的argv长度需不少于argc；argc为0时可传nullptr，否则argv元素应为有效的`napi_value`。

cpp部分代码

<!-- @[napi_call_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/cpp/napi_init.cpp) --> 

``` C++
// napi_call_function
static napi_value CallFunction(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    // 获取ArkTS侧入参
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // 获取全局对象，这里用global是因为napi_call_function的第二个参数是JS函数的this入参。
    napi_value global = nullptr;
    napi_get_global(env, &global);
    // 调用ArkTS方法
    napi_value result = nullptr;
    // 调用napi_call_function时传入的argv的长度必须大于等于argc声明的数量，且被初始化成nullptr
    napi_call_function(env, global, argv[0], argc, argv, &result);
    return result;
}

static napi_value ObjCallFunction(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传递的两个参数
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    // 获取ArkTS侧入参
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // 调用ArkTS方法
    napi_value result = nullptr;
    // 调用napi_call_function时传入的argv的长度必须大于等于argc声明的数量，且被初始化成nullptr
    napi_call_function(env, argv[0], argv[1], argc, argv, &result);
    return result;
}
```

接口声明

<!-- @[napi_call_function_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const callFunction: (func: Function) => number; // napi_call_function

export const objCallFunction: (obj: Object, func: Function) => number;
```

ArkTS 侧示例代码

<!-- @[ark_napi_call_function_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
function returnNumber() {
  return 10;
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

将一个C/C++函数包装为可在ArkTS中调用的函数，并返回一个表示该函数的napi_value。

cpp部分代码

<!-- @[napi_create_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/cpp/napi_init.cpp) --> 

``` C++
// napi_create_function
static napi_value CalculateArea(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传递的两个参数
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

接口声明

<!-- @[napi_create_function_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const calculateArea: (width: number, height: number) => number; // napi_create_function
```

ArkTS 侧示例代码

<!-- @[ark_napi_create_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIFunction/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// napi_create_function
hilog.info(0x0000, 'testTag', 'Test Node-API create_function:%{public}d ',
  testNapi.calculateArea(1.2, 4));
```

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
