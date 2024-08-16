# 使用JSVM-API接口进行错误处理开发

## 简介

使用JSVM-API接口进行错误处理开发，使得在JSVM-API模块中能够更好地管理和响应错误情况。通过合理使用这些函数，可以提高模块的稳定性和可靠性。

## 基本概念

在JavaScript编程中，异常和错误是常见的概念。异常表示发生了某种意外情况，而错误则指示程序无法正确执行某些操作。JSVM-API提供了一系列方法来帮助开发者在模块中处理JavaScript中的异常和错误。下面是一些基本概念：

- **异常（Exception）**：在程序执行过程中可能会出现的意外情况，可以是语法错误、运行时错误或逻辑错误，例如除以零或对未定义变量的操作。
- **错误（Error）**：表示程序无法顺利执行某些操作，可以是由底层系统、API函数或开发者自定义的。
- **类型错误（TypeError）**：表示操作或值的类型不符合预期的情况，通常是由于错误的数据类型导致的。
- **范围错误（RangeError）**：表示一个值不在预期的范围内，例如对数组长度之外的索引进行访问。
- **语法错误（SyntaxError）**：表示一段代码的语法错误。

这些基本概念在异常和错误处理中非常重要，开发者需要通过适当的方法来捕获、处理或向用户报告这些异常和错误，以确保程序的稳定性和正确性。JSVM-API提供的方法可以帮助开发者在模块开发中处理JavaScript中的异常和错误。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_CreateError、OH_JSVM_CreateTypeError、OH_JSVM_CreateRangeError、OH_JSVM_CreateSyntaxError | 在C/C++中需要创建一个错误对象时，可以使用这些函数。创建的错误对象可以使用napi_throw抛出到ArkTS |
| OH_JSVM_Throw | 当在C/C++中出现了错误或异常情况时，通过使用OH_JSVM_CreateError或OH_JSVM_GetLastErrorInfo方法创建或获取JavaScript Error对象，使用该方法抛出已有的JavaScript Error对象。 |
| OH_JSVM_ThrowError、OH_JSVM_ThrowTypeError、OH_JSVM_ThrowRangeError、OH_JSVM_ThrowSyntaxError | 当在C/C++中出现了错误或异常情况时，可以使用这些函数来抛出JavaScript中的异常。 |
| OH_JSVM_IsError              | 查询JSVM_Value以检查它是否表示错误对象。|
| OH_JSVM_GetAndClearLastException    | 清理并返回最后一个JS异常。|
| OH_JSVM_IsExceptionPending   | 判断当前是否有异常。|

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### OH_JSVM_Throw

用于在JSVM-NAPI模块中抛出JavaScript异常的函数。当在本机代码中发生错误或检测到不符合预期的情况时，可以使用此接口来抛出一个Javascript异常，使其能够被捕获并处理。

### OH_JSVM_CreateError

创建并获取一个带文本信息的JavaScript Error。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
// JsVmThrow注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateThrowError},
};
static JSVM_CallbackStruct *method = param;
// JsVmThrow方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateThrowError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmCreateThrowError(JSVM_Env env, JSVM_CallbackInfo info) {
{
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // 在JSVM环境中创建一个字符串，并将其存储在errorCode变量中
    JSVM_Value errorCode = nullptr;
    OH_JSVM_CreateStringUtf8(env, "-1", JSVM_AUTO_LENGTH, &errorCode);
    // 在JSVM环境中创建一个字符串，并将其存储在errorMessage变量中
    JSVM_Value errorMessage = nullptr;
    OH_JSVM_CreateStringUtf8(env, "HasError", JSVM_AUTO_LENGTH, &errorMessage);
    // 创建一个JavaScript对象error
    JSVM_Value error = nullptr;
    OH_JSVM_CreateError(env, errorCode, errorMessage, &error);
    // 通过OH_JSVM_Throw接口将对象抛出
    OH_JSVM_Throw(env, error);
    return nullptr;
}
```

接口声明

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string = `
   jsVmCreateThrowError();
`
try {
  testNapi.runJsVm(script);
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test OH_JSVM_Throw errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}
```

### OH_JSVM_ThrowError

用于抛出一个带文本信息的JS Error。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
// JsVmThrowError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowError},
};
static JSVM_CallbackStruct *method = param;
// JsVmThrowError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmThrowError(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    if (argc == 0) {
        // 如果没有传递参数，直接抛出异常
        OH_JSVM_ThrowError(env, "-1", "has Error");
    } else if (argc == 1) {
        size_t length;
        // 通过入参获取到javaScript侧传入的字符串长度。
        OH_JSVM_GetValueStringUtf8(env, argv[0], nullptr, 0, &length);
        char *buffer = new char[length + 1];
        // 获取入参的字符串内容。
        OH_JSVM_GetValueStringUtf8(env, argv[0], buffer, length + 1, nullptr);
        // 作为error信息填入到OH_JSVM_ThrowError接口中。
        OH_JSVM_ThrowError(env, nullptr, buffer);
        delete[] buffer;
    }
    return nullptr;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let firstScript: string = `jsVmThrowError()`
try {
    napitest.runJsVm(firstScript);
} catch (error) {
    hilog.error(0x0000, 'testTag', 'Test OH_JSVM_ThrowError errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}

try {
    let errMessage = `\"has Error\"`
    let sencodeScript: string =
        `
            jsVmThrowError(${errMessage})
        `
    napitest.runJsVm(sencodeScript);
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test OH_JSVM_ThrowError errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}
```

### OH_JSVM_ThrowTypeError

创建并获取一个带文本信息的JavaScript TypeError。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
// JsVmThrowTypeError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowTypeError},
};
static JSVM_CallbackStruct *method = param;
// JsVmThrowTypeError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowTypeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 这里直接抛出一个带有errorMessage的TypeError
static JSVM_Value JsVmThrowTypeError(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    if (argc == 0) {
        // 如果没有传递参数，直接抛出异常
        OH_JSVM_ThrowTypeError(env, "-1", "throwing type error");
    } else if (argc == 1) {
        size_t length;
        // 通过入参获取到javaScript侧传入的字符串长度
        OH_JSVM_GetValueStringUtf8(env, argv[0], nullptr, 0, &length);
        char *buffer = new char[length + 1];
        // 获取入参的字符串内容
        OH_JSVM_GetValueStringUtf8(env, argv[0], buffer, length + 1, nullptr);
        // 作为error信息填入到OH_JSVM_ThrowError接口中
        OH_JSVM_ThrowTypeError(env, nullptr, buffer);
        delete[] buffer;
    }
    return nullptr;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
try {
  let script: string =
  `
      jsVmThrowTypeError()
  `
  napitest.runJsVm(script);
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test OH_JSVM_TypeError');
}

try {
  let script: string =
  `
      jsVmThrowTypeError("has type Error")
  `
  napitest.runJsVm(script);
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test OH_JSVM_TypeError');
}
```

### OH_JSVM_ThrowRangeError

创建并获取一个带文本信息的JavaScript RangeError。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
// JsVmThrowRangeError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowRangeError},
};
static JSVM_CallbackStruct *method = param;
// JsVmThrowRangeError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowRangeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmThrowRangeError(JSVM_Env env, JSVM_CallbackInfo info)
{
    // js侧传入两个参数
    size_t argc = 2;
    JSVM_Value argv[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // 如果传入参数个数不为2
    if (argc != 2) {
        // 这里抛出一个RangeError
        OH_JSVM_ThrowRangeError(env, "OH_JSVM_ThrowRangeError", "Expected two numbers as arguments");
        return nullptr;
    }
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, true, &result);
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
try {
  let script: string =
  `
      jsVmThrowRangeError(1)
  `
  napitest.runJsVm(script);
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test OH_JSVM_ThrowRangeError');
}
```

### OH_JSVM_ThrowSyntaxError

创建并获取一个带文本信息的JavaScript SyntaxError。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
// JsVmThrowSyntaxError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowSyntaxError},
};
static JSVM_CallbackStruct *method = param;
// JsVmThrowSyntaxError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowSyntaxError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmThrowSyntaxError(JSVM_Env env, JSVM_CallbackInfo info) {
    // JS侧传入运行的JS代码
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    JSVM_Script script = nullptr;
    // 通过OH_JSVM_CompileScript接口编译JS代码
    OH_JSVM_CompileScript(env, argv[0], nullptr, 0, true, nullptr, &script);
    JSVM_Value scriptResult = nullptr;
    // 通过OH_JSVM_RunScript接口运行JS代码
    JSVM_Status status = OH_JSVM_RunScript(env, script, &scriptResult);
    if (status != JSVM_OK) {
        // 如果JSVM_RunScript接口返回状态不为JSVM_OK，则抛出一个SyntaxError
        OH_JSVM_ThrowSyntaxError(env, "JsVmThrowSyntaxError", "throw syntax error");
        return nullptr;
    }
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, true, &result);
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
try {
    let script: string =` jsVmThrowSyntaxError()`
    napitest.runJsVm(script);
} catch(error) {
    hilog.error(0x0000, 'testTag', 'Test jsVmThrowSyntaxError error message: %{public}s,', error.message);
}
```

### OH_JSVM_IsError

用于判断给定的JSVM_Value是否表示一个error对象。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
// JsVmIsError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmIsError},
};
static JSVM_CallbackStruct *method = param;
// JsVmIsError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmIsError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmIsError(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 调用接口OH_JSVM_IsError判断入参是否为一个error对象
    bool result = false;
    // 如果JSVM_Value为一个error对象，则设置result为true的布尔值，否则设置为false
    OH_JSVM_IsError(env, args[0], &result);
    // 取出result通过OH_JSVM_GetBoolean接口将取出的bool值转换为JSVM_Value类型的值返回出去
    JSVM_Value returnValue = nullptr;
    OH_JSVM_GetBoolean(env, result, &returnValue);
    return returnValue;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string =
  `
      jsVmIsError(Error())
  `
const isError = napitest.runJsVm(script);
hilog.info(0x0000, 'testTag', 'Test OH_JSVM_IsError error: %{public}s', isError);
```

### OH_JSVM_CreateTypeError

创建并获取一个带文本信息的JavaScript TypeError。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// JsVmCreateTypeError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateTypeError},
};
static JSVM_CallbackStruct *method = param;
// JsVmCreateTypeError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateTypeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmCreateTypeError(JSVM_Env env, JSVM_CallbackInfo info) {
    // 在JSVM环境中创建一个字符串，并将其存储在errorCode变量中
    JSVM_Value errorCode = nullptr;
    OH_JSVM_CreateStringUtf8(env, "-1", JSVM_AUTO_LENGTH, &errorCode);
    // 在JSVM环境中创建一个字符串，并将其存储在errorMessage变量中
    JSVM_Value errorMessage = nullptr;
    OH_JSVM_CreateStringUtf8(env, "HasError", JSVM_AUTO_LENGTH, &errorMessage);
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateTypeError(env, errorCode, errorMessage, &result);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "JSVM API Create TypeError SUCCESS");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM API Create TypeError FAILED");
    }
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string =`
     jsVmCreateTypeError()
  `
napitest.runJsVm(script);
```

### OH_JSVM_CreateRangeError

创建并获取一个带文本信息的JavaScript RangeError。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// JsVmCreateRangeError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateRangeError},
};
static JSVM_CallbackStruct *method = param;
// JsVmCreateRangeError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateRangeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmCreateRangeError(JSVM_Env env, JSVM_CallbackInfo info) {
    // 在JSVM环境中创建一个字符串，并将其存储在errorCode变量中
    JSVM_Value errorCode = nullptr;
    OH_JSVM_CreateStringUtf8(env, "-1", JSVM_AUTO_LENGTH, &errorCode);
    // 在JSVM环境中创建一个字符串，并将其存储在errorMessage变量中
    JSVM_Value errorMessage = nullptr;
    OH_JSVM_CreateStringUtf8(env, "HasError", JSVM_AUTO_LENGTH, &errorMessage);
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateRangeError(env, errorCode, errorMessage, &result);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "JSVM API CreateRangeError SUCCESS");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM API CreateRangeError FAILED");
    }
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string =
   `
    jsVmCreateRangeError()
   `
napitest.runJsVm(script);
```

### OH_JSVM_CreateSyntaxError

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>


// JsVmCreateSyntaxError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateSyntaxError},
};
static JSVM_CallbackStruct *method = param;
// JsVmThrow方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateSyntaxError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmCreateSyntaxError(JSVM_Env env, JSVM_CallbackInfo info) {
    // 在JSVM环境中创建一个字符串，并将其存储在errorCode变量中
    JSVM_Value errorCode = nullptr;
    OH_JSVM_CreateStringUtf8(env, "-1", JSVM_AUTO_LENGTH, &errorCode);
    // 在JSVM环境中创建一个字符串，并将其存储在errorMessage变量中
    JSVM_Value errorMessage = nullptr;
    OH_JSVM_CreateStringUtf8(env, "HasError", JSVM_AUTO_LENGTH, &errorMessage);
    JSVM_Value result = nullptr;
    JSVM_Status status =  OH_JSVM_CreateSyntaxError(env, errorCode, errorMessage, &result);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "JSVM API CreateSyntaxError SUCCESS");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM API CreateSyntaxError FAILED");
    }
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string =
  `
  let error = jsVmCreateSyntaxError()
  `
napitest.runJsVm(script);
```

### OH_JSVM_GetAndClearLastException

用于获取并清除最近一次出现的异常。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// JsVmGetAndClearLastException注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmGetAndClearLastException},
};
static JSVM_CallbackStruct *method = param;
// JsVmGetAndClearLastException方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmGetAndClearLastException", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmGetAndClearLastException(JSVM_Env env, JSVM_CallbackInfo info) {
    // 抛出异常，创造异常情况
    OH_JSVM_ThrowError(env, "OH_JSVM_ThrowError errorCode", "OH_JSVM_ThrowError errorMessage");
    // 调用OH_JSVM_GetAndClearLastException接口获取并清除最后一个未处理的异常。即使存在挂起的JavaScript异常，也可以调用此API
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_GetAndClearLastException(env, &result);
    if (status != JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "JSVM API OH_JSVM_GetAndClearLastException FAILED");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM API OH_JSVM_GetAndClearLastException SUCCESS");
    }
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string =
 `
   jsVmGetAndClearLastException()
`
napitest.runJsVm(script);
```

### OH_JSVM_IsExceptionPending

用于判断是否出现了异常。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// JsVmIsExceptionPending注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmIsExceptionPending},
};
static JSVM_CallbackStruct *method = param;
// JsVmIsExceptionPending方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmIsExceptionPending", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmIsExceptionPending(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_Status status;
    bool isExceptionPending = false;
    // 在执行一些可能引发异常的操作后
    OH_JSVM_ThrowError(env, "OH_JSVM_ThrowError errorCode", "OH_JSVM_ThrowError errorMessage");
    // 检查当前环境中是否有异常挂起
    status = OH_JSVM_IsExceptionPending(env, &isExceptionPending);
    if (status != JSVM_OK) {
        return nullptr;
    }
    if (isExceptionPending) {
        OH_LOG_INFO(LOG_APP, "JSVM API OH_JSVM_IsExceptionPending: SUCCESS");
        // 处理异常挂起的情况
        JSVM_Value result = nullptr;
        status = OH_JSVM_GetAndClearLastException(env, &result);
        if (status != JSVM_OK) {
            return nullptr;
        }
        // 将处理的异常返回出去
        return result;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM API OH_JSVM_IsExceptionPending: FAILED");
    }
    return nullptr;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string =
              `
    let error = jsVmIsExceptionPending()
    `
napitest.runJsVm(script);
```

### OH_JSVM_GetLastErrorInfo

用于获取最后一次发生的错误信息，包括错误码、错误消息以及错误进栈信息，即使存在挂起的JavaScript异常，也可以调用此API。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// JsVmGetLastErrorInfo注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmGetLastErrorInfo},
};
static JSVM_CallbackStruct *method = param;
// JsVmGetLastErrorInfo方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmGetLastErrorInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmGetLastErrorInfo(JSVM_Env env, JSVM_CallbackInfo info) {
    // 获取输入参数（这里以字符串message作为参数传入）
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 将传入的字符串参数以OH_JSVM_GetValueInt32取出，主动制造错误
    int32_t value = 0;
     OH_JSVM_GetValueInt32(env, args[0], &value);
    // 调用接口OH_JSVM_GetLastErrorInfo获取最后一次错误信息
    const JSVM_ExtendedErrorInfo *errorInfo;
    OH_JSVM_GetLastErrorInfo(env, &errorInfo);
    // 取出错误消息作为返回值带出去打印
    JSVM_Value result = nullptr;
    OH_LOG_INFO(LOG_APP, "JSVM API OH_JSVM_GetLastErrorInfo: SUCCESS");

    OH_JSVM_CreateInt32(env, errorInfo->errorCode, &result);
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string = `jsVmGetLastErrorInfo()`
napitest.runJsVm(script);
```
