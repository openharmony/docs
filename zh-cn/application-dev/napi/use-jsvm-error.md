# 使用JSVM-API接口进行错误处理开发
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--SE: @knightaoko-->
<!--TSE: @test_lzz-->

## 简介

使用JSVM-API接口进行错误处理，可以更好地管理和响应错误情况。合理使用这些函数，可以提高模块的稳定性和可靠性。

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
| OH_JSVM_CreateError、OH_JSVM_CreateTypeError、OH_JSVM_CreateRangeError、OH_JSVM_CreateSyntaxError | 在C/C++中需要创建一个错误对象时，可以使用这些函数。|
| OH_JSVM_Throw | 当在C/C++中出现了错误或异常情况时，通过使用OH_JSVM_CreateError或OH_JSVM_GetLastErrorInfo方法创建或获取JavaScript Error对象，使用该方法抛出已有的JavaScript Error对象。 |
| OH_JSVM_ThrowError、OH_JSVM_ThrowTypeError、OH_JSVM_ThrowRangeError、OH_JSVM_ThrowSyntaxError | 当在C/C++中出现了错误或异常情况时，可以使用这些函数来抛出JavaScript中的异常。 |
| OH_JSVM_IsError              | 查询JSVM_Value以检查它是否表示错误对象。|
| OH_JSVM_GetAndClearLastException    | 清理并返回最后一个JS异常。|
| OH_JSVM_IsExceptionPending   | 判断当前是否有异常。|
| OH_JSVM_GetLastErrorInfo     | 获取最后一次发生的错误信息。|

## 使用示例

JSVM-API接口开发流程可参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅展示接口对应的C++相关代码。

### OH_JSVM_Throw

用于抛出JavaScript Error对象。当在本机代码中发生错误或检测到不符合预期的情况时，可以使用此接口来抛出JavaScript Error，使其能够被捕获并处理。示例参考OH_JSVM_CreateError。

### OH_JSVM_CreateError

创建并获取一个带文本信息的JavaScript Error。

cpp部分代码：

```cpp
// hello.cpp
// 捕获清除并打印错误,该函数作为公共函数，在本文档后续样例中不再声明和定义
static void GetLastErrorAndClean(JSVM_Env env) {
    // 调用OH_JSVM_GetAndClearLastException接口获取并清除最后一个未处理的异常。即使存在挂起的JavaScript异常，也可以调用此API
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_GetAndClearLastException(env, &result);
    // 打印错误信息
    JSVM_Value message = nullptr;
    JSVM_Value errorCode = nullptr;
    OH_JSVM_GetNamedProperty((env), result, "message", &message);
    OH_JSVM_GetNamedProperty((env), result, "code", &errorCode);
    char messagestr[256];
    char codeStr[256];
    OH_JSVM_GetValueStringUtf8(env, message, messagestr, 256, nullptr);
    OH_JSVM_GetValueStringUtf8(env, errorCode, codeStr, 256, nullptr);
    OH_LOG_INFO(LOG_APP, "JSVM error message: %{public}s, error code: %{public}s", messagestr, codeStr);
}

// OH_JSVM_CreateError的样例方法
static JSVM_Value JsVmCreateThrowError(JSVM_Env env, JSVM_CallbackInfo info) {
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
    GetLastErrorAndClean(env);
    return nullptr;
}

// JsVmThrow注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateThrowError},
};
static JSVM_CallbackStruct *method = param;
// JsVmCreateThrowError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateThrowError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(jsVmCreateThrowError();)JS";
```
<!-- @[oh_jsvm_create_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/createerror/src/main/cpp/hello.cpp) -->
预期输出结果
```ts
JSVM error message: HasError, error code: -1
```

### OH_JSVM_ThrowError

用于抛出一个带文本信息的JS Error。

cpp部分代码：

```cpp
// hello.cpp
// OH_JSVM_ThrowError的样例方法
static JSVM_Value JsVmThrowError(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    if (argc == 0) {
        // 如果没有传递参数，直接抛出错误
        OH_JSVM_ThrowError(env, "-1", "has Error");
    } else if (argc == 1) {
        size_t length = 0;
        // 通过入参获取到javaScript侧传入的字符串长度。
        OH_JSVM_GetValueStringUtf8(env, argv[0], nullptr, 0, &length);
        char *buffer = new char[length + 1];
        // 获取入参的字符串内容。
        OH_JSVM_GetValueStringUtf8(env, argv[0], buffer, length + 1, nullptr);
        // 作为error信息填入到OH_JSVM_ThrowError接口中。
        OH_JSVM_ThrowError(env, "self defined error code", buffer);
        delete[] buffer;
    }
    GetLastErrorAndClean(env);
    return nullptr;
}
// JsVmThrowError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowError},
};
static JSVM_CallbackStruct *method = param;
// JsVmThrowError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(jsVmThrowError();jsVmThrowError("self defined error message");)JS";
```
<!-- @[oh_jsvm_throw_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/throwerror/src/main/cpp/hello.cpp) -->

预期输出结果：
```ts
JSVM error message: has Error, error code: -1
JSVM error message: self defined error message, error code: self defined error code
```

### OH_JSVM_ThrowTypeError

创建并获取一个带文本信息的JavaScript TypeError。

cpp部分代码：

```cpp
// hello.cpp
// OH_JSVM_ThrowTypeError的样例方法
static JSVM_Value JsVmThrowTypeError(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    if (argc == 0) {
        // 如果没有传递参数，直接抛出错误
        OH_JSVM_ThrowTypeError(env, "-1", "throwing type error");
    } else if (argc == 1) {
        size_t length = 0;
        // 通过入参获取到javaScript侧传入的字符串长度
        OH_JSVM_GetValueStringUtf8(env, argv[0], nullptr, 0, &length);
        char *buffer = new char[length + 1];
        // 获取入参的字符串内容
        OH_JSVM_GetValueStringUtf8(env, argv[0], buffer, length + 1, nullptr);
        // 作为error信息填入到OH_JSVM_ThrowTypeError接口中
        OH_JSVM_ThrowTypeError(env, "self defined error code", buffer);
        delete[] buffer;
    }
    GetLastErrorAndClean(env);
    return nullptr;
}
// JsVmThrowTypeError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowTypeError},
};
static JSVM_CallbackStruct *method = param;
// JsVmThrowTypeError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowTypeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(jsVmThrowTypeError();jsVmThrowTypeError("self defined error message");)JS";
```
<!-- @[oh_jsvm_throw_type_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/throwtypeerror/src/main/cpp/hello.cpp) -->

预期输出结果：
```ts
JSVM error message: throwing type error, error code: -1
JSVM error message: self defined error message, error code: self defined error code
```

### OH_JSVM_ThrowRangeError

创建并获取一个带文本信息的JavaScript RangeError。

cpp部分代码：

```cpp
// hello.cpp
// OH_JSVM_ThrowRangeError的样例方法
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
        GetLastErrorAndClean(env);
        return nullptr;
    }
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, true, &result);
    return result;
}
// JsVmThrowRangeError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowRangeError},
};
static JSVM_CallbackStruct *method = param;
// JsVmThrowRangeError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowRangeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(jsVmThrowRangeError(1);)JS";
```
<!-- @[oh_jsvm_throw_range_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/throwrangeerror/src/main/cpp/hello.cpp) -->


预期输出结果：
```ts
JSVM error message: Expected two numbers as arguments, error code: OH_JSVM_ThrowRangeError
```

### OH_JSVM_ThrowSyntaxError

创建并获取一个带文本信息的JavaScript SyntaxError。

cpp部分代码：

```cpp
// hello.cpp
// OH_JSVM_ThrowSyntaxError的样例方法
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
        GetLastErrorAndClean(env);
        return nullptr;
    }
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, true, &result);
    return result;
}
// JsVmThrowSyntaxError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowSyntaxError},
};
static JSVM_CallbackStruct *method = param;
// JsVmThrowSyntaxError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowSyntaxError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(jsVmThrowSyntaxError();)JS";
```
<!-- @[oh_jsvm_throw_syntax_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/throwsyntaxerror/src/main/cpp/hello.cpp) -->

预期输出结果：
```ts
JSVM error message: throw syntax error, error code: JsVmThrowSyntaxError
```

### OH_JSVM_IsError

用于判断给定的JSVM_Value是否表示一个Error对象。

cpp部分代码：

```cpp
// hello.cpp
// OH_JSVM_IsError的样例方法
static JSVM_Value JsVmIsError(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 调用接口OH_JSVM_IsError判断入参是否为一个error对象
    bool result = false;
    // 如果JSVM_Value为一个error对象，则设置result为true的布尔值，否则设置为false
    JSVM_Status status = OH_JSVM_IsError(env, args[0], &result);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "JSVM API call OH_JSVM_IsError success, result is %{public}d", result);
    }else {
        OH_LOG_INFO(LOG_APP, "JSVM API call OH_JSVM_IsError failed");
    }
    // 取出result通过OH_JSVM_GetBoolean接口将取出的bool值转换为JSVM_Value类型的值返回出去
    JSVM_Value returnValue = nullptr;
    OH_JSVM_GetBoolean(env, result, &returnValue);
    return returnValue;
}
// JsVmIsError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmIsError},
};
static JSVM_CallbackStruct *method = param;
// JsVmIsError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmIsError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(jsVmIsError(Error()))JS";
```
<!-- @[oh_jsvm_is_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/iserror/src/main/cpp/hello.cpp) -->

预期输出结果：
```ts
JSVM API call OH_JSVM_IsError success, result is 1
```

### OH_JSVM_CreateTypeError

创建并获取一个带文本信息的JavaScript TypeError。

cpp部分代码：

```cpp
// hello.cpp
// OH_JSVM_CreateTypeError的样例方法
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
// JsVmCreateTypeError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateTypeError},
};
static JSVM_CallbackStruct *method = param;
// JsVmCreateTypeError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateTypeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(jsVmCreateTypeError();)JS";
```
<!-- @[oh_jsvm_create_type_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/createtypeerror/src/main/cpp/hello.cpp) -->

预期输出结果：
```ts
JSVM API Create TypeError SUCCESS
```

### OH_JSVM_CreateRangeError

创建并获取一个带文本信息的JavaScript RangeError。

cpp部分代码：

```cpp
// hello.cpp
// OH_JSVM_CreateRangeError的样例方法
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
// JsVmCreateRangeError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateRangeError},
};
static JSVM_CallbackStruct *method = param;
// JsVmCreateRangeError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateRangeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(jsVmCreateRangeError();)JS";
```
<!-- @[oh_jsvm_create_range_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/createrangeerror/src/main/cpp/hello.cpp) -->

预期输出结果：
```ts
JSVM API CreateRangeError SUCCESS
```
### OH_JSVM_CreateSyntaxError

用于创建并获取一个带文本信息的JavaScript SyntaxError。

cpp部分代码：

```cpp
// hello.cpp
// OH_JSVM_CreateSyntaxError的样例方法
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
// JsVmCreateSyntaxError注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateSyntaxError},
};
static JSVM_CallbackStruct *method = param;
// JsVmCreateSyntaxError方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateSyntaxError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(jsVmCreateSyntaxError();)JS";
```
<!-- @[oh_jsvm_create_syntax_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/createsyntaxerror/src/main/cpp/hello.cpp) -->

预期输出结果：
```ts
JSVM API CreateSyntaxError SUCCESS
```

### OH_JSVM_GetAndClearLastException

用于获取并清除最近一次出现的异常。

cpp部分代码：

```cpp
// hello.cpp
// OH_JSVM_GetAndClearLastException的样例方法
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
// JsVmGetAndClearLastException注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmGetAndClearLastException},
};
static JSVM_CallbackStruct *method = param;
// JsVmGetAndClearLastException方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmGetAndClearLastException", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(jsVmGetAndClearLastException();)JS";
```
<!-- @[oh_jsvm_get_and_clear_last_exception](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/getandclearlastexception/src/main/cpp/hello.cpp) -->

预期输出结果：
```ts
JSVM API OH_JSVM_GetAndClearLastException SUCCESS
```

### OH_JSVM_IsExceptionPending

用于判断是否出现了异常。

cpp部分代码：

```cpp
// hello.cpp
// OH_JSVM_IsExceptionPending的样例方法
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
// JsVmIsExceptionPending注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmIsExceptionPending},
};
static JSVM_CallbackStruct *method = param;
// JsVmIsExceptionPending方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmIsExceptionPending", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(jsVmIsExceptionPending();)JS";
```
<!-- @[oh_jsvm_is_exception_pending](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/isexceptionpending/src/main/cpp/hello.cpp) -->

预期输出结果：
```ts
JSVM API OH_JSVM_IsExceptionPending: SUCCESS
```

### OH_JSVM_GetLastErrorInfo

用于获取调用JSVM接口最后一次发生的错误信息（接口返回值不为JSVM_OK），包括错误码、错误消息以及错误堆栈信息，即使存在挂起的JavaScript异常，也可以调用此API。
注意: 通过OH_JSVM_ThrowError等接口主动触发的Error不会被该接口获取，除非调用接口时返回值不为JSVM_OK。

cpp部分代码：

```cpp
// hello.cpp
// OH_JSVM_GetLastErrorInfo的样例方法
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
    OH_LOG_INFO(LOG_APP,
                "JSVM API OH_JSVM_GetLastErrorInfo: SUCCESS, error message is %{public}s, error code is %{public}d",
                errorInfo->errorMessage, errorInfo->errorCode);
    // 对异常进行处理，防止程序由于抛异常而退出
    JSVM_Value result1 = nullptr;
    OH_JSVM_GetAndClearLastException(env, &result1);
    OH_JSVM_CreateInt32(env, errorInfo->errorCode, &result);
    return result;
}
// JsVmGetLastErrorInfo注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmGetLastErrorInfo},
};
static JSVM_CallbackStruct *method = param;
// JsVmGetLastErrorInfo方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmGetLastErrorInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(jsVmGetLastErrorInfo();)JS";
```
<!-- @[oh_jsvm_get_last_error_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/getlasterrorinfo/src/main/cpp/hello.cpp) -->

预期输出结果：
```ts
JSVM API OH_JSVM_GetLastErrorInfo: SUCCESS, error message is A number was expected, error code is 6
```