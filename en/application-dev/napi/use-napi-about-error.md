# Error Handling Using Node-API
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## Introduction

Node-API provides APIs for handling errors occurred in ArkTS code via exceptions. Properly using these APIs helps improve module stability and reliability.

## Basic Concepts

Exceptions and errors are common concepts in ArkTS programming. An exception indicates the presence of an unexpected condition, and an error indicates that the application cannot perform certain operations correctly. Node-API provides a set of APIs for handling errors occurred in ArkTS code via exceptions. Read on the following to learn basic concepts related to error handling:

- Exception: indicates an unexpected condition that may occur during the execution of an application. It can be a syntax error, runtime error, or logic error. For example, the division of a non-zero value with zero and an operation on undefined variables are exceptions.
- Error: indicates that the application cannot perform some operations. Errors can be defined by the underlying system, API, or developer.
- **TypeError**: indicates that the type of an operation or value does not meet the expectation. Generally, this error is caused by an incorrect data type.
- **RangeError**: indicates that a value is not in the expected range. For example, an index beyond the array length is accessed.

These concepts are important in exception and error handling. Properly using methods to capture, handle, or report exceptions and errors help improve application stability.  

## Available APIs

The following table lists the APIs provided by the Node-API module for handling ArkTS errors and exceptions in C/C++. Procedure:
| API| Description|
| -------- | -------- |
| napi_create_error, napi_create_type_error, napi_create_range_error| Creates an error, which can be thrown to ArkTS using **napi_throw**.|
| napi_throw | Throws the ArkTS error object created by **napi_create_error** or obtained by **napi_get_last_error_info**.|
| napi_throw_error, napi_throw_type_error, napi_throw_range_error| Throws an ArkTS error occurred in C/C++.|
| napi_is_error | Checks whether a **napi_value** is an error object.|
| napi_get_and_clear_last_exception | Obtains and clears the latest exception.|
| napi_is_exception_pending | Checks whether there is a pending exception.|
| napi_fatal_error | Raises a fatal error to terminate the process immediately.|
| napi_fatal_exception | Throws a fatal exception, terminates the process, and generates a crash log.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code involved in the APIs for error handling.

### napi_get_last_error_info

Call **napi_get_last_error_info** to obtain the last error information, including the error code, error message, and stack information. This API can also be used to handle pending ArkTS exceptions.

CPP code:

```cpp
#include "napi/native_api.h"
static napi_value GetLastErrorInfo(napi_env env, napi_callback_info info)
{
    // Obtain the input parameter, that is the message string in this example.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Call napi_get_value_int32 to obtain the input string parameter to create an error.
    int32_t value = 0;
    napi_status status = napi_get_value_int32(env, args[0], &value);
    // The return value (status) is not napi_ok, which means an error occurred.
    if (status != napi_ok) {
        OH_LOG_INFO(LOG_APP, "Test Node-API napi_get_value_int32 return status, status is not equal to napi_ok.");
    }

    // Call napi_get_last_error_info to obtain the last error message.
    const napi_extended_error_info *errorInfo;
    napi_get_last_error_info(env, &errorInfo);
    // Obtain the error code and compare it with the return value (status) obtained.
    if (errorInfo->error_code == status) {
        OH_LOG_INFO(LOG_APP, "Test Node-API napi_get_last_error_info return errorInfo, error_code equal to status.");
    }

    // Obtain the error message as the return value and print it.
    napi_value result = nullptr;
    napi_create_string_utf8(env, errorInfo->error_message, NAPI_AUTO_LENGTH, &result);
    return result;
}
```
<!-- @[napi_get_last_error_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getLastErrorInfo: (str: string) => string;
```
<!-- @[napi_get_last_error_info_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_last_error_info: %{public}s', testNapi.getLastErrorInfo('message'));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_get_last_error_info error: %{public}s', error);
}
```
<!-- @[ark_napi_get_last_error_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

### napi_create_type_error

Call **napi_create_type_error** to create an ArkTS **TypeError** object with text information.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CreateTypeError(napi_env env, napi_callback_info info)
{
    // Construct errorCode and errorMessage.
    napi_value errorCode = nullptr;
    napi_create_string_utf8(env, "napi_create_error errorCode", NAPI_AUTO_LENGTH, &errorCode);
    napi_value errorMessage = nullptr;
    napi_create_string_utf8(env, "napi_create_error errorMessage", NAPI_AUTO_LENGTH, &errorMessage);
    // Call napi_create_type_error to create a typeError object.
    napi_value error = nullptr;
    napi_create_type_error(env, errorCode, errorMessage, &error);
    return error;
}
```
<!-- @[napi_create_type_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const createTypeError: () => Error;
```
<!-- @[napi_create_type_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  throw testNapi.createTypeError();
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_create_type_error errorCode: %{public}s, errorMessage %{public}s', error.code, error.message);
}
```
<!-- @[ark_napi_create_type_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

### napi_create_range_error

Call **napi_create_range_error** to create an ArkTS **RangeError** with text information.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CreateRangeError(napi_env env, napi_callback_info info)
{
    // Construct errorCode and errorMessage.
    napi_value errorCode = nullptr;
    napi_create_string_utf8(env, "napi_create_error errorCode", NAPI_AUTO_LENGTH, &errorCode);
    napi_value errorMessage = nullptr;
    napi_create_string_utf8(env, "napi_create_error errorMessage", NAPI_AUTO_LENGTH, &errorMessage);
    // Call napi_create_range_error to create a typeError object.
    napi_value error = nullptr;
    napi_create_range_error(env, errorCode, errorMessage, &error);
    return error;
}
```
<!-- @[napi_create_range_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const createRangeError: () => Error;
```
<!-- @[napi_create_range_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  throw testNapi.createRangeError();
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_create_range_error errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}
```
<!-- @[ark_napi_create_range_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

### napi_create_error

Call **napi_create_error** to create an ArkTS error object with text information.

### napi_throw

Call **napi_throw** to throw an ArkTS exception. You need to create an error object first and pass it to **napi_throw**. You can use this API to throw an ArkTS exception that indicates an error or unexpected behavior occurred in the native code so that exception can be captured and handled.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value NapiThrow(napi_env env, napi_callback_info info)
{
    // Perform the following operations to throw an exception to indicate an error occurred:
    // Create a string in the Node-API environment and store it in the errorCode variable.
    napi_value errorCode = nullptr;
    napi_create_string_utf8(env, "throw errorCode", NAPI_AUTO_LENGTH, &errorCode);
    // Create a string in the Node-API environment and store it in the errorMessage variable.
    napi_value errorMessage = nullptr;
    napi_create_string_utf8(env, "throw errorMessage", NAPI_AUTO_LENGTH, &errorMessage);
    // Create an ArkTS error object.
    napi_value error = nullptr;
    napi_create_error(env, errorCode, errorMessage, &error);
    // Call napi_throw to throw an error.
    napi_throw(env, error);
    return nullptr;
}
```
<!-- @[napi_create_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const napiThrow: () => void;
```
<!-- @[napi_create_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  testNapi.napiThrow();
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_throw errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}
```
<!-- @[ark_napi_create_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

### napi_throw_error

Call **napi_throw_error** to throw an ArkTS **Error** object with text information.

CPP code:

```cpp
#include "napi/native_api.h"

// Throw an error with an error message.
static napi_value NapiThrowErrorMessage(napi_env env, napi_callback_info info)
{
    napi_throw_error(env, nullptr, "napi_throw_error throwing an error");
    return nullptr;
}
// Pass in two parameters. Throw an error when the second parameter, that is, the divisor, is 0.
static napi_value NapiThrowError(napi_env env, napi_callback_info info)
{
    // Pass two parameters from ArkTS.
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Convert the two parameters to values of the double type as the dividend and divisor.
    double dividend, divisor;
    napi_get_value_double(env, argv[0], &dividend);
    napi_get_value_double(env, argv[1], &divisor);
    // If the divisor is 0, throw an error with the error code of DIVIDE_BY_ZERO and the error message of Cannot divide by zero.
    if (divisor == 0) {
        napi_throw_error(env, "DIVIDE_BY_ZERO", "Cannot divide by zero");
    }
    return nullptr;
}
```
<!-- @[napi_throw_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const napiThrowErrorMessage: () => void;
export const napiThrowError: (dividend: number, divisor: number) => void;
```
<!-- @[napi_throw_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  testNapi.napiThrowErrorMessage();
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_throw_error error code: %{public}s , message: %{public}s', error.code, error.message);
}
try {
  testNapi.napiThrowError(5, 0);
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_throw_error errorCode: %{public}s , errorMessage: %{public}s', error.code, error.message);
}
```
<!-- @[ark_napi_throw_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

### napi_throw_type_error

Use **napi_throw_type_error** to throw an ArkTS **TypeError** object with text information.

CPP code:

```cpp
#include "napi/native_api.h"

// Throw a type error with an error message.
static napi_value ThrowTypeErrorMessage(napi_env env, napi_callback_info info)
{
    napi_throw_type_error(env, nullptr, "napi_throw_type_error throwing an error");
    return nullptr;
}
// Pass in a parameter of incorrect type. Throw a type error when the parameter type is found incorrect.
static napi_value ThrowTypeError(napi_env env, napi_callback_info info)
{
    // Pass a parameter from ArkTS.
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Convert the input parameter to a value of the napi_valuetype type.
    napi_valuetype valueType;
    napi_typeof(env, argv[0], &valueType);
    // Throw a type error if the input parameter is not of the napi_number type.
    if (valueType != napi_number) {
        // Throw a type error with both errorCode and errorMessage.
        napi_throw_type_error(env, "napi_throw_type_error", "Argument must be a number");
    }
    return nullptr;
}
```
<!-- @[napi_throw_type_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const throwTypeErrorMessage: () => void;
export const throwTypeError: (message: string) => void;
```
<!-- @[napi_throw_type_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  testNapi.throwTypeErrorMessage();
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_throw_type_error errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}
try {
  testNapi.throwTypeError('str');
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_throw_type_error errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}
```
<!-- @[ark_napi_throw_type_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

### napi_throw_range_error

Use **napi_throw_range_error** to throw an ArkTS **RangeError** with text information.

CPP code:

```cpp
#include "napi/native_api.h"

// Throw a range error with an error message.
static napi_value ThrowRangeErrorMessage(napi_env env, napi_callback_info info)
{
    napi_throw_range_error(env, nullptr, "napi_throw_range_error one");
    return nullptr;
}
// Pass in parameters of incorrect quantity and throw a range error.
static napi_value ThrowRangeError(napi_env env, napi_callback_info info)
{
    // Pass two parameters from ArkTS.
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // If the number of parameters is not 2,
    if (argc != 2) {
        // Throw a range error.
        napi_throw_range_error(env, "napi_throw_range_error", "Expected two numbers as arguments");
        return nullptr;
    }
    // Add the two input values and return the result.
    double numOne = 0;
    double numTwo = 0;
    napi_get_value_double(env, argv[0], &numOne);
    napi_get_value_double(env, argv[1], &numTwo);
    double result = numOne + numTwo;
    napi_value resultValue;
    napi_create_double(env, result, &resultValue);
    return resultValue;
}
```
<!-- @[napi_throw_range_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const throwRangeErrorMessage: () => void;
export const throwRangeError: (num: number) => number | undefined;
```
<!-- @[napi_throw_range_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  testNapi.throwRangeErrorMessage();
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_throw_range_error errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}

try {
  testNapi.throwRangeError(1);
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_throw_range_error errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}
```
<!-- @[ark_napi_throw_range_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

### napi_is_error

Call **napi_is_error** to check whether the given **napi_value** represents an error object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value NapiIsError(napi_env env, napi_callback_info info)
{
    // Obtain the parameter passed in.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Call napi_is_error to check whether the input parameter is an error object.
    bool result = false;
    // If napi_value is an error object, set result to true. Otherwise, set result to false.
    napi_is_error(env, args[0], &result);
    // Obtain result, call napi_get_boolean to convert result to napi_value, and return napi_value.
    napi_value returnValue = nullptr;
    napi_get_boolean(env, result, &returnValue);
    return returnValue;
}
```
<!-- @[napi_is_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const napiIsError: <T>(obj: T) => boolean;
```
<!-- @[napi_is_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  throw new Error("throwing an error");
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_error error: %{public}s', testNapi.napiIsError(error)
    .toString());
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_error error: %{public}s', testNapi.napiIsError(1)
    .toString());
}
```
<!-- @[ark_napi_is_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

### napi_get_and_clear_last_exception

Call **napi_get_and_clear_last_exception** to obtain and clear the last exception.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetAndClearLastException(napi_env env, napi_callback_info info)
{
    // Throw an error.
    napi_throw_error(env, "napi_create_error errorCode", "napi_create_error errorMessage");
    // Call napi_get_and_clear_last_exception to obtain and clear the last unhandled exception. This API can be called even if there are suspended ArkTS exceptions.
    napi_value result = nullptr;
    napi_status status = napi_get_and_clear_last_exception(env, &result);
    if (status != napi_ok) {
        return nullptr;
    }
    return result;
}
```
<!-- @[napi_get_and_clear_last_exception](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getAndClearLastException: () => Error | undefined;
```
<!-- @[napi_get_and_clear_last_exception_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
// Obtain the last unprocessed exception.
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_and_clear_last_exception, error.message: %{public}s',
           testNapi.getAndClearLastException());
```
<!-- @[ark_napi_get_and_clear_last_exception](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

### napi_is_exception_pending

Call **napi_is_exception_pending** to check whether there is any pending exception.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value IsExceptionPending(napi_env env, napi_callback_info info)
{
    napi_status status;
    bool isExceptionPending = false;
    // Perform operations that may cause an error.
    napi_throw_error(env, "napi_create_error errorCode", "napi_create_error errorMessage");
    // Check whether there is a pending exception.
    status = napi_is_exception_pending(env, &isExceptionPending);
    if (status != napi_ok) {
        return nullptr;
    }
    if (isExceptionPending) {
        // Handle the pending exception.
        napi_value result = nullptr;
        status = napi_get_and_clear_last_exception(env, &result);
        if (status != napi_ok) {
            return nullptr;
        }
        // Return the result.
        return result;
    }
    return nullptr;
}
```
<!-- @[napi_is_exception_pending](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const isExceptionPending: () => Object | undefined;
```
<!-- @[napi_is_exception_pending_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
interface MyObject {
  code: string;
  message: string;
}
try {
  let result = testNapi.isExceptionPending() as MyObject;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_exception_pending, error.Code: %{public}s, error.message: %{public}s',
    result.code, result.message);
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_exception_pending error');
}
```
<!-- @[ark_napi_is_exception_pending](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

### napi_fatal_error

Call **napi_fatal_error** to raise a fatal error to terminate the process immediately. Calling **napi_fatal_error** will terminate the application immediately. Avoid frequently calling this API in during normal operations.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value FatalError(napi_env env, napi_callback_info info)
{
    // Calling **napi_fatal_error** will terminate the application process immediately. Use this API only when a fatal error that cannot be rectified occurs.
    // Simulate a fatal error.
    bool errorCondition = true;
    if (errorCondition) {
        // Create a fatal error.
        napi_fatal_error("napi_fatal_error test", NAPI_AUTO_LENGTH, "napi_create_error errorMessage", NAPI_AUTO_LENGTH);
    }
    return nullptr;
}
```
<!-- @[napi_fatal_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const fatalError: () => void;
```
<!-- @[napi_fatal_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  testNapi.fatalError();
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_fatal_error error');
}
```
<!-- @[ark_napi_fatal_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

### napi_fatal_exception
Call **napi_fatal_exception** in the context of the main thread to throw a fatal exception. As a result, the application is terminated and a crash log is generated. Exercise caution when using this API. Avoid frequently calling this API during normal operations.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value FatalException(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};

    napi_status status = napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    if (status != napi_ok) {
      return nullptr;
    }
    // Calling **napi_fatal_exception** will terminate the application process. Use this API only when a fatal error that cannot be rectified occurs in the main thread.
    // Simulate a fatal error.
    status = napi_fatal_exception(env, args[0]);
    if (status != napi_ok) {
      return nullptr;
    }
    return nullptr;
}
```
<!-- @[napi_fatal_exception](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const fatalException: (err: Error) => void;
```
<!-- @[napi_fatal_exception_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

const err = new Error("a fatal exception occurred");
testNapi.fatalException(err);
```
<!-- @[ark_napi_fatal_exception](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
