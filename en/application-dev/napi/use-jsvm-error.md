# Error Handling Using JSVM-API

## Introduction

JSVM-API provides APIs for handling errors occurred in JavaScript (JS) code using exceptions. Properly using these APIs helps improve module stability and reliability.

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
| OH_JSVM_CreateError, OH_JSVM_CreateTypeError, OH_JSVM_CreateRangeError, OH_JSVM_CreateSyntaxError | Creates a JS error. The created error object can be thrown to ArkTS using **napi_throw**. |
| OH_JSVM_Throw | Throws a JS error object, which is created by **OH_JSVM_CreateError** or obtained by **OH_JSVM_GetLastErrorInfo**. |
| OH_JSVM_ThrowError, OH_JSVM_ThrowTypeError, OH_JSVM_ThrowRangeError, OH_JSVM_ThrowSyntaxError | Throws a JS error object. |
| OH_JSVM_IsError              | Checks whether the given **JSVM_Value** indicates an error.|
| OH_JSVM_GetAndClearLastException    | Obtains and clears the last JS exception.|
| OH_JSVM_IsExceptionPending   | Checks whether there is any pending exception.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ and ArkTS code related to exception handling.

### OH_JSVM_Throw

Use **OH_JSVM_Throw** to throw a JS error object so that the error can be captured and handled.

### OH_JSVM_CreateError

Creates a JS error object with text information.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
// Register the JsVmCreateThrowError callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateThrowError},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named jsVmCreateThrowError and associate it with a callback. This allows the JsVmCreateThrowError callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateThrowError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmCreateThrowError(JSVM_Env env, JSVM_CallbackInfo info) {
{
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // Create a string in the JSVM and store it in the errorCode variable.
    JSVM_Value errorCode = nullptr;
    OH_JSVM_CreateStringUtf8(env, "-1", JSVM_AUTO_LENGTH, &errorCode);
    // Create a string in the JSVM and store it in the errorMessage variable.
    JSVM_Value errorMessage = nullptr;
    OH_JSVM_CreateStringUtf8(env, "HasError", JSVM_AUTO_LENGTH, &errorMessage);
    // Create a JS error object.
    JSVM_Value error = nullptr;
    OH_JSVM_CreateError(env, errorCode, errorMessage, &error);
    // Call OH_JSVM_Throw to throw the error.
    OH_JSVM_Throw(env, error);
    return nullptr;
}
```

 

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
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

Use **OH_JSVM_ThrowError** to throw a JS **Error** object with text information.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
// Register the JsVmThrowError callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowError},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named jsVmThrowError and associate it with a callback. This allows the JsVmThrowError callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmThrowError(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    if (argc == 0) {
        // Throw an exception if no parameter is passed in.
        OH_JSVM_ThrowError(env, "-1", "has Error");
    } else if (argc == 1) {
        size_t length;
        // Obtain the length of the string passed from JS from the input parameter.
        OH_JSVM_GetValueStringUtf8(env, argv[0], nullptr, 0, &length);
        char *buffer = new char[length + 1];
        // Obtain the string of the input parameter.
        OH_JSVM_GetValueStringUtf8(env, argv[0], buffer, length + 1, nullptr);
        // Populate the error information to OH_JSVM_ThrowError.
        OH_JSVM_ThrowError(env, nullptr, buffer);
        delete[] buffer;
    }
    return nullptr;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
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

Use **OH_JSVM_ThrowTypeError** to throw a JS **TypeError** object with text information.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
// Register the **JsVmThrowTypeError** callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowTypeError},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named jsVmThrowTypeError and associate it with a callback. This allows the JsVmThrowTypeError callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowTypeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Throw a type error with an error message.
static JSVM_Value JsVmThrowTypeError(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    if (argc == 0) {
        // Throw an error if no parameter is passed in.
        OH_JSVM_ThrowTypeError(env, "-1", "throwing type error");
    } else if (argc == 1) {
        size_t length;
        // Obtain the length of the string in the input parameter passed from JS.
        OH_JSVM_GetValueStringUtf8(env, argv[0], nullptr, 0, &length);
        char *buffer = new char[length + 1];
        // Obtain the string of the input parameter.
        OH_JSVM_GetValueStringUtf8(env, argv[0], buffer, length + 1, nullptr);
        // Populate the error information to OH_JSVM_ThrowError.
        OH_JSVM_ThrowTypeError(env, nullptr, buffer);
        delete[] buffer;
    }
    return nullptr;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
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

Use **OH_JSVM_ThrowRangeError** to throw a JS **RangeError** object with text information.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
// Register the JsVmThrowRangeError callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowRangeError},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named jsVmThrowRangeError and associate it with a callback. This allows the JsVmThrowRangeError callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowRangeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmThrowRangeError(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Pass two parameters from JS.
    size_t argc = 2;
    JSVM_Value argv[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // If the number of parameters is not 2,
    if (argc != 2) {
        // Throw a RangeError.
        OH_JSVM_ThrowRangeError(env, "OH_JSVM_ThrowRangeError", "Expected two numbers as arguments");
        return nullptr;
    }
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, true, &result);
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
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

Use **OH_JSVM_ThrowSyntaxError** to throw a JS **SyntaxError** object with text information.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
// Register the JsVmThrowSyntaxError callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmThrowSyntaxError},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named jsVmThrowSyntaxError and associate it with a callback. This allows the JsVmThrowSyntaxError callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmThrowSyntaxError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmThrowSyntaxError(JSVM_Env env, JSVM_CallbackInfo info) {
    // Pass the JS code from JS.
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    JSVM_Script script = nullptr;
    // Call OH_JSVM_CompileScript to compile the JS code.
    OH_JSVM_CompileScript(env, argv[0], nullptr, 0, true, nullptr, &script);
    JSVM_Value scriptResult = nullptr;
    // Call OH_JSVM_RunScript to run the JS code.
    JSVM_Status status = OH_JSVM_RunScript(env, script, &scriptResult);
    if (status != JSVM_OK) {
        // If the value returned by JSVM_RunScript is not JSVM_OK, throw a SyntaxError.
        OH_JSVM_ThrowSyntaxError(env, "JsVmThrowSyntaxError", "throw syntax error");
        return nullptr;
    }
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, true, &result);
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
    let script: string =` jsVmThrowSyntaxError()`
    napitest.runJsVm(script);
} catch(error) {
    hilog.error(0x0000, 'testTag', 'Test jsVmThrowSyntaxError error message: %{public}s,', error.message);
}
```

### OH_JSVM_IsError

Use **OH_JSVM_IsError** to check whether the given **JSVM_Value** represents an error object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
// Register the JsVmIsError callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmIsError},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named OH_JSVM_IsError and associate it with a callback. This allows the JsVmIsError callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmIsError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmIsError(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Call OH_JSVM_IsError to check whether the input parameter is an error object.
    bool result = false;
    // If JSVM_Value is an error object, set result to true. Otherwise, set result to false.
    OH_JSVM_IsError(env, args[0], &result);
    // Obtain result, call OH_JSVM_GetBoolean to convert result to JSVM_Value, and return JSVM_Value.
    JSVM_Value returnValue = nullptr;
    OH_JSVM_GetBoolean(env, result, &returnValue);
    return returnValue;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string =
  `
      jsVmIsError(Error())
  `
const isError = napitest.runJsVm(script);
hilog.info(0x0000, 'testTag', 'Test OH_JSVM_IsError error: %{public}s', isError);
```

### OH_JSVM_CreateTypeError

Use **OH_JSVM_CreateTypeError** to create a JS **TypeError** object with text information.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// Register the JsVmCreateTypeError callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateTypeError},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named jsVmCreateTypeError and associate it with a callback. This allows the JsVmCreateTypeError callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateTypeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmCreateTypeError(JSVM_Env env, JSVM_CallbackInfo info) {
    // Create a string in the JSVM and store it in the errorCode variable.
    JSVM_Value errorCode = nullptr;
    OH_JSVM_CreateStringUtf8(env, "-1", JSVM_AUTO_LENGTH, &errorCode);
    // Create a string in the JSVM and store it in the errorMessage variable.
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

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string =`
     jsVmCreateTypeError()
  `
napitest.runJsVm(script);
```

### OH_JSVM_CreateRangeError

Use **OH_JSVM_CreateRangeError** to create a JS **RangeError** with text information.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// Register the JsVmCreateRangeError callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateRangeError},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named jsVmCreateRangeError and associate it with a callback. This allows the JsVmCreateRangeError callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateRangeError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmCreateRangeError(JSVM_Env env, JSVM_CallbackInfo info) {
    // Create a string in the JSVM and store it in the errorCode variable.
    JSVM_Value errorCode = nullptr;
    OH_JSVM_CreateStringUtf8(env, "-1", JSVM_AUTO_LENGTH, &errorCode);
    // Create a string in the JSVM and store it in the errorMessage variable.
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

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string =
   `
    jsVmCreateRangeError()
   `
napitest.runJsVm(script);
```

### OH_JSVM_CreateSyntaxError

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>


// Register the JsVmCreateSyntaxError callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmCreateSyntaxError},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named jsVmThrow and associate it with a callback. This allows the JsVmThrow callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmCreateSyntaxError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmCreateSyntaxError(JSVM_Env env, JSVM_CallbackInfo info) {
    // Create a string in the JSVM and store it in the errorCode variable.
    JSVM_Value errorCode = nullptr;
    OH_JSVM_CreateStringUtf8(env, "-1", JSVM_AUTO_LENGTH, &errorCode);
    // Create a string in the JSVM and store it in the errorMessage variable.
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

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string =
  `
  let error = jsVmCreateSyntaxError()
  `
napitest.runJsVm(script);
```

### OH_JSVM_GetAndClearLastException

Use **OH_JSVM_GetAndClearLastException** to obtain and clear the latest exception.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// Register the JsVmGetAndClearLastException callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmGetAndClearLastException},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named jsVmGetAndClearLastException and associate it with a callback. This allows the JsVmGetAndClearLastException callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmGetAndClearLastException", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmGetAndClearLastException(JSVM_Env env, JSVM_CallbackInfo info) {
    // Throw an error.
    OH_JSVM_ThrowError(env, "OH_JSVM_ThrowError errorCode", "OH_JSVM_ThrowError errorMessage");
    // Call OH_JSVM_GetAndClearLastException to obtain and clear the last exception. This API can also be used to handle a suspended JS exception.
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

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string =
 `
   jsVmGetAndClearLastException()
`
napitest.runJsVm(script);
```

### OH_JSVM_IsExceptionPending

Use **OH_JSVM_IsExceptionPending** to check whether there is any pending exception.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// Register the JsVmIsExceptionPending callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmIsExceptionPending},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named jsVmIsExceptionPending and associate it with a callback. This allows the JsVmIsExceptionPending callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmIsExceptionPending", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmIsExceptionPending(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_Status status;
    bool isExceptionPending = false;
    // Perform operations that may cause an error.
    OH_JSVM_ThrowError(env, "OH_JSVM_ThrowError errorCode", "OH_JSVM_ThrowError errorMessage");
    // Check whether there is a pending exception.
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
        // Return the result.
        return result;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM API OH_JSVM_IsExceptionPending: FAILED");
    }
    return nullptr;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string =
              `
    let error = jsVmIsExceptionPending()
    `
napitest.runJsVm(script);
```

### OH_JSVM_GetLastErrorInfo

Use **OH_JSVM_GetLastErrorInfo** to obtain the last error information, including the error code, error message, and stack information. This API can also be used to handle pending JS exceptions.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// Register the JsVmGetLastErrorInfo callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsVmGetLastErrorInfo},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named jsVmGetLastErrorInfo and associate it with a callback. This allows the JsVmGetLastErrorInfo callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsVmGetLastErrorInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static JSVM_Value JsVmGetLastErrorInfo(JSVM_Env env, JSVM_CallbackInfo info) {
    // Obtain the input parameter, that is the message string in this example.
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Call OH_JSVM_GetValueInt32 to obtain the input string parameter to create an error.
    int32_t value = 0;
     OH_JSVM_GetValueInt32(env, args[0], &value);
    // Call OH_JSVM_GetLastErrorInfo to obtain the last error message.
    const JSVM_ExtendedErrorInfo *errorInfo;
    OH_JSVM_GetLastErrorInfo(env, &errorInfo);
    // Obtain the error message as the return value and print it.
    JSVM_Value result = nullptr;
    OH_LOG_INFO(LOG_APP, "JSVM API OH_JSVM_GetLastErrorInfo: SUCCESS");

    OH_JSVM_CreateInt32(env, errorInfo->errorCode, &result);
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `jsVmGetLastErrorInfo()`
napitest.runJsVm(script);
```
