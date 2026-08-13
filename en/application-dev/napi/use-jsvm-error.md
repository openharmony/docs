# Error Handling Using JSVM-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=fa3fc214ef4b265f033bc3f0d0a2df54f511a497 translatedAt=2026-08-12T06:36:15.686Z pushedAt=2026-08-12T11:02:32.207Z -->

## Introduction

JSVM-API provides APIs for handling errors occurred in JS code using exceptions. Properly using these APIs helps improve module stability and reliability.

## Basic Concepts

Exceptions and errors are common concepts in JS programming. An exception indicates the presence of an unexpected condition, and an error indicates that the application cannot perform certain operations correctly. JSVM-API provides a set of APIs for handling errors occurred in JS code using exceptions. Read on the following to learn basic concepts related to exception handling:

- Exception: indicates an unexpected condition that may occur during the execution of an application. It can be a syntax error, runtime error, or logic error. For example, the division of a non-zero value with zero and an operation on undefined variables are exceptions.

- Error: indicates that the application cannot perform some operations. Errors can be defined by the underlying system, API, or developer.

- **TypeError**: indicates that the type of an operation or value does not meet the expectation. Generally, this error is caused by an incorrect data type.

- **RangeError**: indicates that a value is not in the expected range. For example, an index beyond the array length is accessed.

- **SyntaxError**: indicates a mistake in the syntax of a piece of code.

These concepts are important in exception and error handling. Properly using methods to capture, handle, or report exceptions and errors help improve application stability. JSVM-API provides APIs for handling errors in JS code using exceptions.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_CreateError, OH_JSVM_CreateTypeError, OH_JSVM_CreateRangeError, OH_JSVM_CreateSyntaxError| Creates a JS error.|
| OH_JSVM_Throw | Throws a JS error object, which is created by **OH_JSVM_CreateError** or obtained by **OH_JSVM_GetLastErrorInfo**.|
| OH_JSVM_ThrowError, OH_JSVM_ThrowTypeError, OH_JSVM_ThrowRangeError, OH_JSVM_ThrowSyntaxError| Throws a JS error object.|
| OH_JSVM_IsError              | Checks whether the given **JSVM_Value** indicates an error.|
| OH_JSVM_GetAndClearLastException    | Obtains and clears the last JS exception.|
| OH_JSVM_IsExceptionPending   | Checks whether there is any pending exception.|
| OH_JSVM_GetLastErrorInfo     | Obtains the last error information.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in related APIs.

### OH_JSVM_Throw

Call **OH_JSVM_Throw** to throw a JS error object. You can use this API to throw a JS error that indicates an error or unexpected behavior occurred in the native code so that exception can be captured and handled. For details about the example, see the example of **OH_JSVM_CreateError**.

### OH_JSVM_CreateError

Call **OH_JSVM_CreateError** to create a JS error object with text information.

CPP code:

<!-- @[oh_jsvm_create_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/createerror/src/main/cpp/hello.cpp) -->

``` C++
// Catch, clear, and print the error. This function serves as a common utility and is not redeclared or redefined in subsequent examples of this document.
static void GetLastErrorAndClean(JSVM_Env env)
{
    // Call OH_JSVM_GetAndClearLastException to obtain and clear the last unhandled exception. This API can be called even when a JavaScript exception is pending.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_GetAndClearLastException(env, &result);
    // Print the error message.
    JSVM_Value message = nullptr;
    JSVM_Value errorCode = nullptr;
    OH_JSVM_GetNamedProperty((env), result, "message", &message);
    OH_JSVM_GetNamedProperty((env), result, "code", &errorCode);
    const int maxMessageLength = 256;
    const int maxCodeLength = 256;
    char messageStr[maxMessageLength];
    char codeStr[maxCodeLength];
    OH_JSVM_GetValueStringUtf8(env, message, messageStr, maxMessageLength, nullptr);
    OH_JSVM_GetValueStringUtf8(env, errorCode, codeStr, maxCodeLength, nullptr);
    OH_LOG_INFO(LOG_APP, "JSVM error message: %{public}s, error code: %{public}s", messageStr, codeStr);
}

// Sample method for OH_JSVM_CreateError.
static JSVM_Value JsVmCreateThrowError(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Create a string in the JSVM environment and store it in the errorCode variable.
    JSVM_Value errorCode = nullptr;
    OH_JSVM_CreateStringUtf8(env, "-1", JSVM_AUTO_LENGTH, &errorCode);
    // Create a string in the JSVM environment and store it in the errorMessage variable.
    JSVM_Value errorMessage = nullptr;
    OH_JSVM_CreateStringUtf8(env, "HasError", JSVM_AUTO_LENGTH, &errorMessage);
    // Create a JavaScript error object.
    JSVM_Value error = nullptr;
    OH_JSVM_CreateError(env, errorCode, errorMessage, &error);
    // Throw the object via OH_JSVM_Throw.
    OH_JSVM_Throw(env, error);
    GetLastErrorAndClean(env);
    return nullptr;
}

// Register callback for JsVmCreateThrowError.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateThrowError},
};
static JSVM_CallbackStruct *method = param;
// Alias of JsVmCreateThrowError for JS invocation.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateThrowError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS.
const char *SRC_CALL_NATIVE = R"JS(jsVmCreateThrowError();)JS";
```

Expected result:

```ts
JSVM error message: HasError, error code: -1
```

### OH_JSVM_ThrowError

Call **OH_JSVM_ThrowError** to throw a JS **Error** object with text information.

CPP code:

<!-- @[oh_jsvm_throw_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/throwerror/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_ThrowError.
static JSVM_Value JsVmThrowError(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    if (argc == 0) {
        // If no parameter is passed, throw an error directly.
        OH_JSVM_ThrowError(env, "-1", "has Error");
    } else if (argc == 1) {
        size_t length = 0;
        // Obtain the length of the string passed from the JavaScript side via the input parameter.
        OH_JSVM_GetValueStringUtf8(env, argv[0], nullptr, 0, &length);
        char *buffer = new char[length + 1];
        // Obtain the string content of the input parameter.
        OH_JSVM_GetValueStringUtf8(env, argv[0], buffer, length + 1, nullptr);
        // Pass it as the error message to OH_JSVM_ThrowError.
        OH_JSVM_ThrowError(env, "self defined error code", buffer);
        delete[] buffer;
    }
    GetLastErrorAndClean(env);
    return nullptr;
}
// Register callback for JsVmThrowError.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowError},
};
static JSVM_CallbackStruct *method = param;
// Alias of JsVmThrowError for JS invocation.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS.
const char *SRC_CALL_NATIVE = R"JS(jsVmThrowError();jsVmThrowError("self defined error message");)JS";
```

Expected result:

```ts
JSVM error message: has Error, error code: -1
JSVM error message: self defined error message, error code: self defined error code
```

### OH_JSVM_ThrowTypeError

Call **OH_JSVM_CreateTypeError** to create a JS **TypeError** object with text information.

CPP code:

<!-- @[oh_jsvm_throw_type_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/throwtypeerror/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_ThrowTypeError.
static JSVM_Value JsVmThrowTypeError(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    if (argc == 0) {
        // If no parameter is passed, throw an error directly.
        OH_JSVM_ThrowTypeError(env, "-1", "throwing type error");
    } else if (argc == 1) {
        size_t length = 0;
        // Obtain the length of the string passed from the JavaScript side via the input parameter.
        OH_JSVM_GetValueStringUtf8(env, argv[0], nullptr, 0, &length);
        char *buffer = new char[length + 1];
        // Obtain the string content of the input parameter.
        OH_JSVM_GetValueStringUtf8(env, argv[0], buffer, length + 1, nullptr);
        // Pass it as the error message to OH_JSVM_ThrowTypeError.
        OH_JSVM_ThrowTypeError(env, "self defined error code", buffer);
        delete[] buffer;
    }
    GetLastErrorAndClean(env);
    return nullptr;
}
// Register callback for JsVmThrowTypeError.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowTypeError},
};
static JSVM_CallbackStruct *method = param;
// Alias of JsVmThrowTypeError for JS invocation.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowTypeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS.
const char *SRC_CALL_NATIVE = R"JS(jsVmThrowTypeError();jsVmThrowTypeError("self defined error message");)JS";
```

Expected result:

```ts
JSVM error message: throwing type error, error code: -1
JSVM error message: self defined error message, error code: self defined error code
```

### OH_JSVM_ThrowRangeError

Call **OH_JSVM_CreateRangeError** to create a JS **RangeError** with text information.

CPP code:

<!-- @[oh_jsvm_throw_range_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/throwrangeerror/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_ThrowRangeError.
static JSVM_Value JsVmThrowRangeError(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Two parameters are passed from the JS side.
    size_t argc = 2;
    JSVM_Value argv[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // If the number of parameters passed is not 2.
    if (argc != 2) {
        // Throw a RangeError here.
        OH_JSVM_ThrowRangeError(env, "OH_JSVM_ThrowRangeError", "Expected two numbers as arguments");
        GetLastErrorAndClean(env);
        return nullptr;
    }
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, true, &result);
    return result;
}
// Register callback for JsVmThrowRangeError.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowRangeError},
};
static JSVM_CallbackStruct *method = param;
// Alias of JsVmThrowRangeError for JS invocation.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowRangeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS.
const char *SRC_CALL_NATIVE = R"JS(jsVmThrowRangeError(1);)JS";
```

Expected result:

```ts
JSVM error message: Expected two numbers as arguments, error code: OH_JSVM_ThrowRangeError
```

### OH_JSVM_ThrowSyntaxError

Call **OH_JSVM_ThrowSyntaxError** to create and throw a JS **SyntaxError** object with text information.

CPP code:

<!-- @[oh_jsvm_throw_syntax_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/throwsyntaxerror/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_ThrowSyntaxError.
static JSVM_Value JsVmThrowSyntaxError(JSVM_Env env, JSVM_CallbackInfo info)
{
    // The JS side passes the JS code to be executed.
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    JSVM_Script script = nullptr;
    // Compile the JS code via OH_JSVM_CompileScript.
    OH_JSVM_CompileScript(env, argv[0], nullptr, 0, true, nullptr, &script);
    JSVM_Value scriptResult = nullptr;
    // Run the JS code via OH_JSVM_RunScript.
    JSVM_Status status = OH_JSVM_RunScript(env, script, &scriptResult);
    if (status != JSVM_OK) {
        // If the return status of JSVM_RunScript is not JSVM_OK, throw a SyntaxError.
        OH_JSVM_ThrowSyntaxError(env, "JsVmThrowSyntaxError", "throw syntax error");
        GetLastErrorAndClean(env);
        return nullptr;
    }
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, true, &result);
    return result;
}
// Register callback for JsVmThrowSyntaxError.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowSyntaxError},
};
static JSVM_CallbackStruct *method = param;
// Alias of JsVmThrowSyntaxError for JS invocation.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowSyntaxError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS.
const char *SRC_CALL_NATIVE = R"JS(jsVmThrowSyntaxError();)JS";
```

Expected result:

```ts
JSVM error message: throw syntax error, error code: JsVmThrowSyntaxError
```

### OH_JSVM_IsError

Call **OH_JSVM_IsError** to check whether the given **JSVM_Value** represents an error object.

CPP code:

<!-- @[oh_jsvm_is_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/iserror/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_IsError.
static JSVM_Value JsVmIsError(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Call OH_JSVM_IsError to determine whether the input parameter is an error object.
    bool result = false;
    // If JSVM_Value is an error object, set result to the boolean value true; otherwise, set it to false.
    JSVM_Status status = OH_JSVM_IsError(env, args[0], &result);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "JSVM API call OH_JSVM_IsError success, result is %{public}d", result);
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM API call OH_JSVM_IsError failed");
    }
    // Retrieve result and convert the bool value to a JSVM_Value via OH_JSVM_GetBoolean, then return it.
    JSVM_Value returnValue = nullptr;
    OH_JSVM_GetBoolean(env, result, &returnValue);
    return returnValue;
}
// Register callback for JsVmIsError.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmIsError},
};
static JSVM_CallbackStruct *method = param;
// Alias of JsVmIsError for JS invocation.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmIsError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS.
const char *SRC_CALL_NATIVE = R"JS(jsVmIsError(Error()))JS";
```

Expected result:

```ts
JSVM API call OH_JSVM_IsError success, result is 1
```

### OH_JSVM_CreateTypeError

Call **OH_JSVM_CreateTypeError** to create a JS **TypeError** object with text information.

CPP code:

<!-- @[oh_jsvm_create_type_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/createtypeerror/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_CreateTypeError.
static JSVM_Value JsVmCreateTypeError(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Create a string in the JSVM environment and store it in the errorCode variable.
    JSVM_Value errorCode = nullptr;
    OH_JSVM_CreateStringUtf8(env, "-1", JSVM_AUTO_LENGTH, &errorCode);
    // Create a string in the JSVM environment and store it in the errorMessage variable.
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
// Register callback for JsVmCreateTypeError.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateTypeError},
};
static JSVM_CallbackStruct *method = param;
// Alias of JsVmCreateTypeError for JS invocation.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateTypeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS.
const char *SRC_CALL_NATIVE = R"JS(jsVmCreateTypeError();)JS";
```

Expected result:

```ts
JSVM API Create TypeError SUCCESS
```

### OH_JSVM_CreateRangeError

Call **OH_JSVM_CreateRangeError** to create a JS **RangeError** with text information.

CPP code:

<!-- @[oh_jsvm_create_range_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/createrangeerror/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_CreateRangeError.
static JSVM_Value JsVmCreateRangeError(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Create a string in the JSVM environment and store it in the errorCode variable.
    JSVM_Value errorCode = nullptr;
    OH_JSVM_CreateStringUtf8(env, "-1", JSVM_AUTO_LENGTH, &errorCode);
    // Create a string in the JSVM environment and store it in the errorMessage variable.
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
// Register callback for JsVmCreateRangeError.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateRangeError},
};
static JSVM_CallbackStruct *method = param;
// Alias of JsVmCreateRangeError for JS invocation.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateRangeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS.
const char *SRC_CALL_NATIVE = R"JS(jsVmCreateRangeError();)JS";
```

Expected result:

```ts
JSVM API CreateRangeError SUCCESS
```

### OH_JSVM_CreateSyntaxError

Call **OH_JSVM_CreateSyntaxError** to create and throw a JS **SyntaxError** object with text information.

CPP code:

<!-- @[oh_jsvm_create_syntax_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/createsyntaxerror/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_CreateSyntaxError.
static JSVM_Value JsVmCreateSyntaxError(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Create a string in the JSVM environment and store it in the errorCode variable.
    JSVM_Value errorCode = nullptr;
    OH_JSVM_CreateStringUtf8(env, "-1", JSVM_AUTO_LENGTH, &errorCode);
    // Create a string in the JSVM environment and store it in the errorMessage variable.
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
// Register callback for JsVmCreateSyntaxError.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateSyntaxError},
};
static JSVM_CallbackStruct *method = param;
// Alias of JsVmCreateSyntaxError for JS invocation.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateSyntaxError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS.
const char *SRC_CALL_NATIVE = R"JS(jsVmCreateSyntaxError();)JS";
```

Expected result:

```ts
JSVM API CreateSyntaxError SUCCESS
```

### OH_JSVM_GetAndClearLastException

Call **OH_JSVM_GetAndClearLastException** to obtain and clear the latest exception.

CPP code:

<!-- @[oh_jsvm_get_and_clear_last_exception](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/getandclearlastexception/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_GetAndClearLastException.
static JSVM_Value JsVmGetAndClearLastException(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Throw an exception to create an exceptional condition.
    OH_JSVM_ThrowError(env, "OH_JSVM_ThrowError errorCode", "OH_JSVM_ThrowError errorMessage");
    // Call OH_JSVM_GetAndClearLastException to obtain and clear the last unhandled exception. This API can be called even when a JavaScript exception is pending.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_GetAndClearLastException(env, &result);
    if (status != JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "JSVM API OH_JSVM_GetAndClearLastException FAILED");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM API OH_JSVM_GetAndClearLastException SUCCESS");
    }
    return result;
}
// Register callback for JsVmGetAndClearLastException.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmGetAndClearLastException},
};
static JSVM_CallbackStruct *method = param;
// Alias of JsVmGetAndClearLastException for JS invocation.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmGetAndClearLastException", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS.
const char *SRC_CALL_NATIVE = R"JS(jsVmGetAndClearLastException();)JS";
```

Expected result:

```ts
JSVM API OH_JSVM_GetAndClearLastException SUCCESS
```

### OH_JSVM_IsExceptionPending

Call **OH_JSVM_IsExceptionPending** to check whether there is any pending exception.

CPP code:

<!-- @[oh_jsvm_is_exception_pending](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/isexceptionpending/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_IsExceptionPending.
static JSVM_Value JsVmIsExceptionPending(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Status status;
    bool isExceptionPending = false;
    // After performing an operation that may cause an exception.
    OH_JSVM_ThrowError(env, "OH_JSVM_ThrowError errorCode", "OH_JSVM_ThrowError errorMessage");
    // Check whether an exception is pending in the current environment.
    status = OH_JSVM_IsExceptionPending(env, &isExceptionPending);
    if (status != JSVM_OK) {
        return nullptr;
    }
    if (isExceptionPending) {
        OH_LOG_INFO(LOG_APP, "JSVM API OH_JSVM_IsExceptionPending: SUCCESS");
        // Handle the pending exception.
        JSVM_Value result = nullptr;
        status = OH_JSVM_GetAndClearLastException(env, &result);
        if (status != JSVM_OK) {
            return nullptr;
        }
        // Return the handled exception.
        return result;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM API OH_JSVM_IsExceptionPending: FAILED");
    }
    return nullptr;
}
// Register callback for JsVmIsExceptionPending.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmIsExceptionPending},
};
static JSVM_CallbackStruct *method = param;
// Alias of JsVmIsExceptionPending for JS invocation.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmIsExceptionPending", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS.
const char *SRC_CALL_NATIVE = R"JS(jsVmIsExceptionPending();)JS";
```

Expected result:

```ts
JSVM API OH_JSVM_IsExceptionPending: SUCCESS
```

### OH_JSVM_GetLastErrorInfo

Call **OH_JSVM_GetLastErrorInfo** to obtain the last error information (the return value is not **JSVM_OK**), including the error code, error message, and stack information. This API can also be used for suspended JS errors.

**Note:** Errors actively thrown through APIs such as OH_JSVM_ThrowError are not captured by this API, unless the return value is not JSVM_OK when the API is called.

CPP code:

<!-- @[oh_jsvm_get_last_error_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmError/getlasterrorinfo/src/main/cpp/hello.cpp) -->

``` C++
// Sample method for OH_JSVM_GetLastErrorInfo.
static JSVM_Value JsVmGetLastErrorInfo(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the input parameter (a string message is passed as the parameter here).
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Retrieve the string parameter via OH_JSVM_GetValueInt32 to deliberately trigger an error.
    int32_t value = 0;
    OH_JSVM_GetValueInt32(env, args[0], &value);
    // Call OH_JSVM_GetLastErrorInfo to obtain the last error information.
    const JSVM_ExtendedErrorInfo *errorInfo;
    OH_JSVM_GetLastErrorInfo(env, &errorInfo);

    // Retrieve the error message as the return value for printing.
    JSVM_Value result = nullptr;
    OH_LOG_INFO(LOG_APP,
                "JSVM API OH_JSVM_GetLastErrorInfo: SUCCESS, error message is %{public}s, error code is %{public}d",
                errorInfo->errorMessage, errorInfo->errorCode);
    // Handle the exception to prevent the program from exiting due to the thrown exception.
    JSVM_Value result1 = nullptr;
    OH_JSVM_GetAndClearLastException(env, &result1);
    OH_JSVM_CreateInt32(env, errorInfo->errorCode, &result);
    return result;
}
// Register callback for JsVmGetLastErrorInfo.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmGetLastErrorInfo},
};
static JSVM_CallbackStruct *method = param;
// Alias of JsVmGetLastErrorInfo for JS invocation.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmGetLastErrorInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS.
const char *SRC_CALL_NATIVE = R"JS(jsVmGetLastErrorInfo();)JS";
```

Expected result:

```ts
JSVM API OH_JSVM_GetLastErrorInfo: SUCCESS, error message is A number was expected, error code is 6
```