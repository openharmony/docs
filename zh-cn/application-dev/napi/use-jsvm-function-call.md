# 使用JSVM-API接口进行函数创建和调用

## 简介

函数调用允许开发者从JSVM模块中调用JavaScript函数，并传递参数进行调用，或者直接在JSVM模块中创建一个JavaScript方法。

## 基本概念

函数是一种非常重要的编程概念，可以执行特定的任务或操作、提高代码的可读性、把复杂任务简化、提高代码复用性以及支持代码的组织与管理。每个函数可以负责不同的功能，提供一种将代码模块化和组织结构化的方式，使其更易于理解、维护和重用。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_GetCbInfo          | 从给定的callback info中获取有关调用的详细信息，如参数和this指针。|
| OH_JSVM_CallFunction       | 在C/C++侧调用JavaScript方法。|
| OH_JSVM_CreateFunction     | 用于创建JavaScript函数,用于从JavaScript环境中调用C/C++代码中的函数|

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### OH_JSVM_GetCbInfo

获取有关函数调用的详细信息。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// GetCbArgs注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetCbArgs},
};
static JSVM_CallbackStruct *method = param;
// GetCbArgs方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getCbArgs", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_GetCbInfo的样例方法
static JSVM_Value GetCbArgs(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    JSVM_Status status = OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetCbInfo: failed");
        return nullptr;
    }
    // 此处需要8个字节的缓冲区，具体大小根据实际情况调整
    size_t bufSize = 8;
    char buf[bufSize];
    size_t result = 0;
    OH_JSVM_GetValueStringUtf8(env, args[0], buf, bufSize, &result);
    OH_LOG_INFO(LOG_APP, "JSVM args[0] is: %{public}s", buf);
    return args[0];
}
```

ArkTS 侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string = `
   const str = 'message';
   getCbArgs(str);
  `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'GetCbArgs:%{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'GetCbArgs: %{public}s', error.message);
}
```

### OH_JSVM_CallFunction

在C/C++侧对JavaScript函数进行调用。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// CallFunction注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CallFunction},
};
static JSVM_CallbackStruct *method = param;
// CallFunction方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"callFunction", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_CallFunction的样例方法
static JSVM_Value CallFunction(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    // 获取JavaScript侧入参
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 获取全局对象，这里用global是因为OH_JSVM_CallFunction的第二个参数是JS函数的this入参。
    JSVM_Value global;
    OH_JSVM_GetGlobal(env, &global);
    // 调用JavaScript方法
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CallFunction(env, global, args[0], 0, nullptr, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CallFunction: failed");
        return nullptr;
    }
    // 将传入的JavaScript方法的执行结果打印出来
    int32_t resultValue = 0;
    OH_JSVM_GetValueInt32(env, result, &resultValue);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CallFunction reslut is: %{public}d", resultValue);
    OH_LOG_INFO(LOG_APP, "If the resultValue is 10, the example runs successfully");
    return result;
}
```

ArkTS 侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string = `
    function returnNumber(){
        return 10;
    }
    callFunction(returnNumber)
`
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM callFunction: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM callFunction error: %{public}s', error.message);
}
```

### OH_JSVM_CreateFunction

将一个C/C++函数包装为可在JavaScript中调用的函数，并返回一个表示该函数的JSVM_Value。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// CreateFunction注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateFunction},
};
static JSVM_CallbackStruct *method = param;
// CreateFunction方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createFunction", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// CalculateArea自定义函数
static JSVM_Value CalculateArea(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 获取js侧传入的两个参数
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    double width;
    OH_JSVM_GetValueDouble(env, args[0], &width);
    double height;
    OH_JSVM_GetValueDouble(env, args[1], &height);
    JSVM_Value area;
    OH_JSVM_CreateDouble(env, width * height, &area);
    return area;
}
static double width = 1.4;
static double height = 5.0;
// OH_JSVM_CreateFunction的样例使用方法
static JSVM_Value CreateFunction(JSVM_Env env, JSVM_CallbackInfo info) {
    // 创建名为param的回调结构体传入OH_JSVM_CreateFunction
    JSVM_CallbackStruct param;
    param.data = nullptr;
    param.callback = CalculateArea;
    JSVM_Value funcValue = nullptr;
    // 创建名为calculateArea的JavaScript函数
    JSVM_Status status = OH_JSVM_CreateFunction(env, "calculateArea", JSVM_AUTO_LENGTH, &param, &funcValue);
    if (funcValue == nullptr || status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_CreateFunction failed");
    }
    // 创建参数
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_CreateDouble(env, width, &args[0]);
    OH_JSVM_CreateDouble(env, height, &args[1]);
    JSVM_Value global;
    OH_JSVM_GetGlobal(env, &global);
    // 调用calculateArea函数并传入参数
    JSVM_Value ret = nullptr;
    OH_JSVM_CallFunction(env, global, funcValue, 2, args, &ret);
    // 返回calculateArea函数执行后的的结果
    int32_t result = 0;
    OH_JSVM_GetValueInt32(env, ret, &result);
    OH_LOG_INFO(LOG_APP, "JSVM If 7 is printed here, the use case is correct: %{public}d", result);
    return ret;
}
```

ArkTS 侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string = `createFunction()`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createFunction: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createFunction error: %{public}s', error.message);
}
```
