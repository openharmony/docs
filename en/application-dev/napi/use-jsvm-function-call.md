# Creating and Calling JS Functions Using JSVM-API

## Introduction

JSVM-API provides APIs for calling JavaScript (JS) functions and passing parameters or creating JS methods in C/C++.

## Basic Concepts

Functions are blocks of reusable code that performs specific tasks or operations. You can define functions to implement different operations. Functions provide a way to modularize and structure code, helping make your code more organized, reusable, and maintainable.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_GetCbInfo          | Obtains detailed information about the call, such as the parameters and **this** pointer, from the given callback information.|
| OH_JSVM_CallFunction       | Calls a JS function from a C/C++ addon.|
| OH_JSVM_CreateFunction     | Creates a JS function object in native code, which allows calling into the native code from JS.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ and ArkTS code related to the APIs for creating and calling JS functions.

### OH_JSVM_GetCbInfo

Use **OH_JSVM_GetCbInfo** to obtain detailed information about function calls.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetCbArgs callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetCbArgs},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getCbArgs and associate it with a callback. This allows the GetCbArgs callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getCbArgs", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetCbInfo.
static JSVM_Value GetCbArgs(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    JSVM_Status status = OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetCbInfo: failed");
        return nullptr;
    }
    // In this example, an 8-byte buffer is set. Set the buffer size based on service requirements.
    size_t bufSize = 8;
    char buf[bufSize];
    size_t result = 0;
    OH_JSVM_GetValueStringUtf8(env, args[0], buf, bufSize, &result);
    OH_LOG_INFO(LOG_APP, "JSVM args[0] is: %{public}s", buf);
    return args[0];
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
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

Use **OH_JSVM_CallFunction** to call a JS function from a C/C++ addon.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CallFunction callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CallFunction},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named callFunction and associate it with a callback. This allows the CallFunction callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"callFunction", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CallFunction.
static JSVM_Value CallFunction(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    // Obtain the parameters passed from JS.
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the global object. Here, global is used because the second parameter of OH_JSVM_CallFunction is the input parameter this of the JS function.
    JSVM_Value global;
    OH_JSVM_GetGlobal(env, &global);
    // Call the JS method.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CallFunction(env, global, args[0], 0, nullptr, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CallFunction: failed");
        return nullptr;
    }
    // Print the execution result of the JS method.
    int32_t resultValue = 0;
    OH_JSVM_GetValueInt32(env, result, &resultValue);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CallFunction reslut is: %{public}d", resultValue);
    OH_LOG_INFO(LOG_APP, "If the resultValue is 10, the example runs successfully");
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
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

Use **OH_JSVM_CreateFunction** to create a JS function object in native code, which allows calling into the native code from JS.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CreateFunction callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateFunction},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createFunction and associate it with a callback. This allows the CreateFunction callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createFunction", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define the CalculateArea function.
static JSVM_Value CalculateArea(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the two parameters passed from JS.
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
// Define OH_JSVM_CreateFunction.
static JSVM_Value CreateFunction(JSVM_Env env, JSVM_CallbackInfo info) {
    // Create a callback struct named param and pass in OH_JSVM_CreateFunction.
    JSVM_CallbackStruct param;
    param.data = nullptr;
    param.callback = CalculateArea;
    JSVM_Value funcValue = nullptr;
    // Create a JS function named calculateArea.
    JSVM_Status status = OH_JSVM_CreateFunction(env, "calculateArea", JSVM_AUTO_LENGTH, &param, &funcValue);
    if (funcValue == nullptr || status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_CreateFunction failed");
    }
    // Create parameters.
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_CreateDouble(env, width, &args[0]);
    OH_JSVM_CreateDouble(env, height, &args[1]);
    JSVM_Value global;
    OH_JSVM_GetGlobal(env, &global);
    // Call the calculateArea function and pass in parameters.
    JSVM_Value ret = nullptr;
    OH_JSVM_CallFunction(env, global, funcValue, 2, args, &ret);
    // Return the execution result of the calculateArea function.
    int32_t result = 0;
    OH_JSVM_GetValueInt32(env, ret, &result);
    OH_LOG_INFO(LOG_APP, "JSVM If 7 is printed here, the use case is correct: %{public}d", result);
    return ret;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `createFunction()`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createFunction: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createFunction error: %{public}s', error.message);
}
```
