# Error Handling Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=2cc827181a31e0a77238ca42eb3b41991d5fd686 translatedAt=2026-08-12T06:40:04.569Z pushedAt=2026-08-12T11:11:39.598Z -->

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

The following [Node-APIs](../reference/native-lib/napi.md#symbols-exported-from-the-node-api-library) are used to handle errors and exceptions during interaction with ArkTS. Procedure:

| API| Description|
| -------- | -------- |
| napi_create_error, napi_create_type_error, napi_create_range_error| Creates an error, which can be thrown to ArkTS using **napi_throw**.|
| napi_throw | Throws the ArkTS error object created by **napi_create_error** or obtained by **napi_get_last_error_info**.|
| napi_throw_error, napi_throw_type_error, napi_throw_range_error, napi_throw_business_error| Throws an ArkTS error occurred in C/C++.|
| napi_is_error | Checks whether a **napi_value** is an error object.|
| napi_get_and_clear_last_exception | Obtains and clears the latest exception.|
| napi_is_exception_pending | Checks whether there is a pending exception.|
| napi_fatal_error | Raises a fatal error to terminate the process immediately.|
| napi_fatal_exception | Throws a fatal exception, terminates the process, and generates a corresponding crash log. |

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code involved in the APIs for error handling.

### napi_get_last_error_info

Call **napi_get_last_error_info** to obtain the last error information, including the error code, error message, and stack information. This API can also be used to handle pending ArkTS exceptions.

CPP code:

<!-- @[napi_get_last_error_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_last_error_info
static napi_value GetLastErrorInfo(napi_env env, napi_callback_info info)
{
    // Obtain the input parameter (a string message is passed in as the parameter here).
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Retrieve the incoming string parameter using napi_get_value_int32 to deliberately cause an error.
    int32_t value = 0;
    napi_status status = napi_get_value_int32(env, args[0], &value);
    // The API is used incorrectly, so the return value is not napi_ok.
    if (status != napi_ok) {
        OH_LOG_INFO(LOG_APP, "napi_get_value_int32 return status, status is not equal to napi_ok.");
    }
    // Call napi_get_last_error_info to obtain the last error information.
    const napi_extended_error_info *errorInfo;
    napi_get_last_error_info(env, &errorInfo);
    // Retrieve the error code and compare it with the return value after the API call error.
    if (errorInfo->error_code == status) {
        OH_LOG_INFO(LOG_APP, "napi_get_last_error_info return errorInfo, error_code equal to status.");
    }
    // Retrieve the error message as the return value for printing.
    napi_value result = nullptr;
    napi_create_string_utf8(env, errorInfo->error_message, NAPI_AUTO_LENGTH, &result);
    return result;
}
```

API declaration:

<!-- @[napi_get_last_error_info_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->  

``` TypeScript
export const getLastErrorInfo: (str: string) => string; // napi_get_last_error_info
```

ArkTS code:

<!-- @[ark_napi_get_last_error_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_last_error_info
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_last_error_info: %{public}s',
    testNapi.getLastErrorInfo('message'));
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_get_last_error_info error: %{public}s', error);
  // ...
}
```

### napi_create_type_error

Call **napi_create_type_error** to create an ArkTS **TypeError** object with text information.

CPP code:

<!-- @[napi_create_type_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_create_type_error
static napi_value CreateTypeError(napi_env env, napi_callback_info info)
{
    // Construct errorCode and errorMessage.
    napi_value errorCode = nullptr;
    napi_create_string_utf8(env, "napi_create_error errorCode", NAPI_AUTO_LENGTH, &errorCode);
    napi_value errorMessage = nullptr;
    napi_create_string_utf8(env, "napi_create_error errorMessage", NAPI_AUTO_LENGTH, &errorMessage);
    napi_value error = nullptr;
    napi_create_type_error(env, errorCode, errorMessage, &error);
    return error;
}
```

API declaration:

<!-- @[napi_create_type_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->  

``` TypeScript
export const createTypeError: () => Error; // napi_create_type_error
```

ArkTS code:

<!-- @[ark_napi_create_type_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
try {
  // ...
  throw testNapi.createTypeError();
} catch (error) { // napi_create_type_error
  hilog.error(0x0000, 'testTag',
    'Test Node-API napi_create_type_error errorCode: %{public}s, errorMessage %{public}s', error.code,
    error.message);
  // ...
}
```

### napi_create_range_error

Call **napi_create_range_error** to create an ArkTS **RangeError** with text information.

CPP code:

<!-- @[napi_create_range_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_create_range_error
static napi_value CreateRangeError(napi_env env, napi_callback_info info)
{
    // Construct errorCode and errorMessage.
    napi_value errorCode = nullptr;
    napi_create_string_utf8(env, "napi_create_error errorCode", NAPI_AUTO_LENGTH, &errorCode);
    napi_value errorMessage = nullptr;
    napi_create_string_utf8(env, "napi_create_error errorMessage", NAPI_AUTO_LENGTH, &errorMessage);
    napi_value error = nullptr;
    napi_create_range_error(env, errorCode, errorMessage, &error);
    return error;
}
```

API declaration:

<!-- @[napi_create_range_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->  

``` TypeScript
export const createRangeError: () => Error; // napi_create_range_error
```

ArkTS code:

<!-- @[ark_napi_create_range_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_create_range_error
try {
  // ...
  throw testNapi.createRangeError();
} catch (error) {
  hilog.error(0x0000, 'testTag',
    'Test Node-API napi_create_range_error errorCode: %{public}s, errorMessage: %{public}s',
    error.code,
    error.message);
  // ...
}
```

### napi_create_error

Call **napi_create_error** to create an ArkTS error object with text information.

### napi_throw

Call **napi_throw** to throw an ArkTS exception. You need to create an error object first and pass it to **napi_throw**. You can use this API to throw an ArkTS exception that indicates an error or unexpected behavior occurred in the native code so that exception can be captured and handled.

CPP code:

<!-- @[napi_create_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_create_error and napi_throw
static napi_value NapiThrow(napi_env env, napi_callback_info info)
{
    // After certain errors occur in the code, perform the following operations to throw an exception.
    // Create a string in the Node-API environment and store it in the errorCode variable.
    napi_value errorCode = nullptr;
    napi_create_string_utf8(env, "throw errorCode", NAPI_AUTO_LENGTH, &errorCode);
    // Create a string in the Node-API environment and store it in the errorMessage variable.
    napi_value errorMessage = nullptr;
    napi_create_string_utf8(env, "throw errorMessage", NAPI_AUTO_LENGTH, &errorMessage);
    // Create an ArkTS object named error.
    napi_value error = nullptr;
    napi_create_error(env, errorCode, errorMessage, &error);
    // Throw the object via the napi_throw API.
    napi_throw(env, error);
    return nullptr;
}
```

API declaration:

<!-- @[napi_create_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->  

``` TypeScript
export const napiThrow: () => void; // napi_create_error and napi_throw
```

ArkTS code:

<!-- @[ark_napi_create_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_create_error and napi_throw
try {
  testNapi.napiThrow();
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag',
    'Test Node-API napi_throw errorCode: %{public}s, errorMessage: %{public}s',
    error.code, error.message);
  // ...
}
```

### napi_throw_error

Call **napi_throw_error** to throw an ArkTS **Error** object with text information.

CPP code:

<!-- @[napi_throw_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_throw_error
// Directly throw an error with an errorMessage here.
static napi_value NapiThrowErrorMessage(napi_env env, napi_callback_info info)
{
    napi_throw_error(env, nullptr, "napi_throw_error throwing an error");
    return nullptr;
}

// Pass in two parameters. Throw an error when the second parameter, i.e., the divisor, is 0.
static napi_value NapiThrowError(napi_env env, napi_callback_info info)
{
    // Two parameters are passed in from the ArkTS side.
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Convert them to double values as the dividend and divisor.
    double dividend;
    double divisor;
    napi_get_value_double(env, argv[0], &dividend);
    napi_get_value_double(env, argv[1], &divisor);
    // Check here: if the divisor is 0, directly throw an error with errorCode: DIVIDE_BY_ZERO and errorMessage: Cannot divide by zero.
    if (divisor == 0) {
        napi_throw_error(env, "DIVIDE_BY_ZERO", "Cannot divide by zero");
    }
    return nullptr;
}
```

API declaration:

<!-- @[napi_throw_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->  

``` TypeScript
export const napiThrowErrorMessage: () => void; // napi_throw_error

export const napiThrowError: (dividend: number, divisor: number) => void; // napi_throw_error
```

ArkTS code:

<!-- @[ark_napi_throw_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_throw_error
try {
  testNapi.napiThrowErrorMessage();
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag',
    'Test Node-API napi_throw_error error code: %{public}s , message: %{public}s', error.code,
    error.message);
  // ...
}
try {
  testNapi.napiThrowError(5, 0);
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag',
    'Test Node-API napi_throw_error errorCode: %{public}s , errorMessage: %{public}s', error.code,
    error.message);
  // ...
}
```

### napi_throw_business_error

[napi_throw_business_error](../reference/native-lib/napi.md#napi_throw_business_error) throws an ArkTS `Error` with text information, where the `code` property of the error object is of the `number` type. This API throws a native `Error` object, not a `BusinessError` object declared in the ArkTS SDK.

CPP code:

<!-- [napi_throw_business_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

```cpp
#include "napi/native_api.h"
#include "hilog/log.h"

static constexpr int INT_ARG_100 = 100;

// Throw an error with an error message.
static napi_value NapiThrowBusinessError(napi_env env, napi_callback_info info)
{
    napi_status status = napi_throw_business_error(env, INT_ARG_100, "error message");
    if (status != napi_ok) {
        OH_LOG_INFO(LOG_APP, "napi_throw_business_error failed :: %{public}d", status);
    }
    return nullptr;
}
```

API declaration:

<!-- [napi_throw_business_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->

```ts
// index.d.ts
export const napiThrowBusinessError: () => void;
```

ArkTS code:

<!-- [ark_napi_throw_business_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

try {
  testNapi.napiThrowBusinessError();
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_throw_business_error error code: %{public}d , message: %{public}s', error.code, error.message);
  console.info(typeof error.code); // "number"
}
```

### napi_throw_type_error

Use **napi_throw_type_error** to throw an ArkTS **TypeError** object with text information.

CPP code:

<!-- @[napi_throw_type_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_throw_type_error
// Directly throw a TypeError with an errorMessage here.
static napi_value ThrowTypeErrorMessage(napi_env env, napi_callback_info info)
{
    napi_throw_type_error(env, nullptr, "napi_throw_type_error throwing an error");
    return nullptr;
}

// Pass in a parameter of mismatched type. Throw a typeError after detecting the type mismatch.
static napi_value ThrowTypeError(napi_env env, napi_callback_info info)
{
    // One parameter is passed in from the ArkTS side.
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Convert the incoming parameter to a value of type napi_valuetype.
    napi_valuetype valueType;
    napi_typeof(env, argv[0], &valueType);
    // If the incoming parameter is not a value of type napi_number, throw a TypeError.
    if (valueType != napi_number) {
        // Throw a TypeError with both an errorCode and an errorMessage here.
        napi_throw_type_error(env, "napi_throw_type_error", "Argument must be a number");
    }
    return nullptr;
}
```

API declaration:

<!-- @[napi_throw_type_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->  

``` TypeScript
export const throwTypeErrorMessage: () => void; // napi_throw_type_error

export const throwTypeError: (message: string) => void; // napi_throw_type_error
```

ArkTS code:

<!-- @[ark_napi_throw_type_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_throw_type_error
try {
  testNapi.throwTypeErrorMessage();
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag',
    'Test Node-API napi_throw_type_error errorCode: %{public}s, errorMessage: %{public}s',
    error.code,
    error.message);
  // ...
}
try {
  testNapi.throwTypeError('str');
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag',
    'Test Node-API napi_throw_type_error errorCode: %{public}s, errorMessage: %{public}s',
    error.code,
    error.message);
  // ...
}
```

### napi_throw_range_error

Use **napi_throw_range_error** to throw an ArkTS **RangeError** with text information.

CPP code:

<!-- @[napi_throw_range_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_throw_range_error
// Directly throw a RangeError with an errorMessage here.
static napi_value ThrowRangeErrorMessage(napi_env env, napi_callback_info info)
{
    napi_throw_range_error(env, nullptr, "napi_throw_range_error one");
    return nullptr;
}

// Pass in a mismatched number of parameters. Throw a rangeError after detecting the mismatch.
static napi_value ThrowRangeError(napi_env env, napi_callback_info info)
{
    // Two parameters are passed in from the ArkTS side.
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // If the number of incoming parameters is not 2.
    if (argc != 2) {
        // Throw a RangeError here.
        napi_throw_range_error(env, "napi_throw_range_error", "Expected two numbers as arguments");
        return nullptr;
    }
    // Add the two incoming values and pass the result out.
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

API declaration:

<!-- @[napi_throw_range_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->  

``` TypeScript
export const throwRangeErrorMessage: () => void; // napi_throw_range_error

export const throwRangeError: (num: number) => number | undefined; // napi_throw_range_error
```

ArkTS code:

<!-- @[ark_napi_throw_range_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_throw_range_error
try {
  testNapi.throwRangeErrorMessage();
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag',
    'Test Node-API napi_throw_range_error errorCode: %{public}s, errorMessage: %{public}s',
    error.code,
    error.message);
  // ...
}

try {
  testNapi.throwRangeError(1);
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag',
    'Test Node-API napi_throw_range_error errorCode: %{public}s, errorMessage: %{public}s',
    error.code,
    error.message);
  // ...
}
```

### napi_is_error

Call **napi_is_error** to check whether the given **napi_value** represents an error object.

CPP code:

<!-- @[napi_is_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_is_error
static napi_value NapiIsError(napi_env env, napi_callback_info info)
{
    // Receive one input parameter.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Call napi_is_error to check whether the input parameter is an error object.
    bool result = false;
    // If the napi_value is an error object, set result to the boolean value true; otherwise, set it to false.
    napi_is_error(env, args[0], &result);
    // Retrieve result and convert the bool value to a napi_value via napi_get_boolean, then return it.
    napi_value returnValue = nullptr;
    napi_get_boolean(env, result, &returnValue);
    return returnValue;
}
```

API declaration:

<!-- @[napi_is_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->  

``` TypeScript
export const napiIsError: <T>(obj: T) => boolean; // napi_is_error
```

ArkTS code:

<!-- @[ark_napi_is_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_is_error
try {
  // ...
  throw new Error("throwing an error");
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_error error: %{public}s',
    testNapi.napiIsError(error)
      .toString());
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_error error: %{public}s',
    testNapi.napiIsError(1)
      .toString());
  // ...
}
```

### napi_get_and_clear_last_exception

Call **napi_get_and_clear_last_exception** to obtain and clear the last exception.

CPP code:

<!-- @[napi_get_and_clear_last_exception](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_and_clear_last_exception
static napi_value GetAndClearLastException(napi_env env, napi_callback_info info)
{
    // Throw an exception to create an exceptional situation.
    napi_throw_error(env, "napi_create_error errorCode", "napi_create_error errorMessage");
    // Call napi_get_and_clear_last_exception to obtain and clear the last unhandled exception. This API can be called even if there is a pending ArkTS exception.
    napi_value result = nullptr;
    napi_status status = napi_get_and_clear_last_exception(env, &result);
    if (status != napi_ok) {
        return nullptr;
    }
    return result;
}
```

API declaration:

<!-- @[napi_get_and_clear_last_exception_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->  

``` TypeScript
export const getAndClearLastException: () => Error | undefined; // napi_get_and_clear_last_exception
```

ArkTS code:

<!-- @[ark_napi_get_and_clear_last_exception](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->  

``` TypeScript
// napi_get_and_clear_last_exception
// Obtain the last unhandled exception here.
let exception = testNapi.getAndClearLastException();
hilog.info(0x0000, 'testTag',
  'Test Node-API napi_get_and_clear_last_exception, error.message: %{public}s',
  exception ? exception.message : '');
```

### napi_is_exception_pending

Call **napi_is_exception_pending** to check whether there is any pending exception.

CPP code:

<!-- @[napi_is_exception_pending](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_is_exception_pending
static napi_value IsExceptionPending(napi_env env, napi_callback_info info)
{
    napi_status status;
    bool isExceptionPending = false;
    // After performing some operations that may cause an exception.
    napi_throw_error(env, "napi_create_error errorCode", "napi_create_error errorMessage");
    // Check whether there is a pending exception in the current environment.
    status = napi_is_exception_pending(env, &isExceptionPending);
    if (status != napi_ok) {
        return nullptr;
    }
    if (isExceptionPending) {
        // Handle the case where an exception is pending.
        napi_value result = nullptr;
        status = napi_get_and_clear_last_exception(env, &result);
        if (status != napi_ok) {
            return nullptr;
        }
        // Return the handled exception.
        return result;
    }
    return nullptr;
}
```

API declaration:

<!-- @[napi_is_exception_pending_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->  

``` TypeScript
export const isExceptionPending: () => Object | undefined; // napi_is_exception_pending
```

ArkTS code:

<!-- @[ark_napi_is_exception_pending](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_is_exception_pending
interface MyObject {
  code: string;
  message: string;
}

try {
  let result = testNapi.isExceptionPending() as MyObject;
  hilog.info(0x0000, 'testTag',
    'Test Node-API napi_is_exception_pending, error.Code: %{public}s, error.message: %{public}s',
    result.code, result.message);
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_exception_pending error');
  // ...
}
```

### napi_fatal_error

Call **napi_fatal_error** to raise a fatal error to terminate the process immediately. Calling **napi_fatal_error** will terminate the application immediately. Avoid frequently calling this API during normal operations.

CPP code:

<!-- @[napi_fatal_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_fatal_error
static napi_value FatalError(napi_env env, napi_callback_info info)
{
    // Note that using the napi_fatal_error function will cause the app process to terminate directly. Therefore, use it with caution and only call it when encountering an unrecoverable critical error.
    // Simulate a fatal error condition.
    bool errorCondition = true;
    if (errorCondition) {
        // Create a fatal error message.
        napi_fatal_error("napi_fatal_error test", NAPI_AUTO_LENGTH, "napi_create_error errorMessage", NAPI_AUTO_LENGTH);
    }
    return nullptr;
}
```

API declaration:

<!-- @[napi_fatal_error_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) -->  

``` TypeScript
export const fatalError: () => void; // napi_fatal_error
```

ArkTS code:

<!-- @[ark_napi_fatal_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_fatal_error Note that using the napi_fatal_error function will cause the app process to terminate directly. Therefore, use it with caution and only call it when encountering an unrecoverable critical error.
// Simulate a fatal error condition.
try {
  testNapi.fatalError();
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_fatal_error error');
  // ...
}
```

### napi_fatal_exception

Call **napi_fatal_exception** in the context of the main thread to throw a fatal exception. As a result, the application is terminated and a crash log is generated. Exercise caution when using this API. Avoid frequently calling this API during normal operations.

CPP code:

<!-- @[napi_fatal_exception](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_fatal_exception
static napi_value FatalException(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};

    napi_status status = napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    if (status != napi_ok) {
        return nullptr;
    }
    // Note that using the napi_fatal_exception function will cause the app process to terminate directly. Therefore, use it with caution and only call it on the main thread when encountering an unrecoverable critical error.
    // Simulate a fatal error condition.
    status = napi_fatal_exception(env, args[0]);
    if (status != napi_ok) {
        return nullptr;
    }
    return nullptr;
}
```

API declaration:

<!-- @[napi_fatal_exception_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/cpp/types/libentry/Index.d.ts) --> 

``` TypeScript
export const fatalException: (err: Error) => void; // napi_fatal_exception
```

ArkTS code:

<!-- @[ark_napi_fatal_exception](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIError/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
const err = new Error("a fatal exception occurred");
testNapi.fatalException(err);
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```