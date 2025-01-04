# 使用Node-API接口进行错误处理开发

## 简介

使用Node-API接口进行错误处理开发，使得在Node-API模块中能够更好地管理和响应错误情况。通过合理使用这些函数，可以提高模块的稳定性和可靠性。

## 基本概念

在ArkTS编程中，异常和错误是常见的概念。异常表示发生了某种意外情况，而错误则指示程序无法正确执行某些操作。Node-API提供了一系列方法来帮助开发者在Node-API模块中处理ArkTS中的异常和错误。下面是一些基本概念：

- **异常（Exception）**：在程序执行过程中可能会出现的意外情况，可以是语法错误、运行时错误或逻辑错误，例如除以零或对未定义变量的操作。
- **错误（Error）**：表示程序无法顺利执行某些操作，可以是由底层系统、API函数或开发者自定义的。
- **类型错误（Type Error）**：表示操作或值的类型不符合预期的情况，通常是由于错误的数据类型导致的。
- **范围错误（Range Error）**：表示一个值不在预期的范围内，例如对数组长度之外的索引进行访问。

这些基本概念在异常和错误处理中非常重要，开发者需要通过适当的方法来捕获、处理或向用户报告这些异常和错误，以确保程序的稳定性和正确性。Node-API提供的方法可以帮助开发者在Node-API模块中处理ArkTS中的异常和错误。

## 场景和功能介绍

以下Node-API接口主要用于与ArkTS交互时处理错误和异常情况。他们的使用场景如下：
| 接口 | 描述 |
| -------- | -------- |
| napi_create_error、napi_create_type_error、napi_create_range_error | 在C/C++中需要创建一个错误对象时，可以使用这些函数。创建的错误对象可以使用napi_throw抛出到ArkTS |
| napi_throw | 当在C/C++中出现了错误或异常情况时，通过使用napi_create_error或napi_get_last_error_info方法创建或获取ArkTS Error对象，使用该方法抛出已有的ArkTS Error对象。 |
| napi_throw_error、napi_throw_type_error、napi_throw_range_error | 当在C/C++中出现了错误或异常情况时，可以使用这些函数来抛出ArkTS中的异常。 |
| napi_is_error | 检查一个napi_value是否代表一个错误对象时，可以使用这个函数。 |
| napi_get_and_clear_last_exception | 当你需要获取最近一次出现的异常，并将异常队列清空时，可以使用这个函数。 |
| napi_is_exception_pending | 当你需要判断是否有未处理的异常时，可以使用这个函数。 |
| napi_fatal_error | 当遇到严重错误或不可恢复的情况时，可以使用这个函数引发致命错误来立即终止进程。 |
| napi_fatal_exception | 抛出一个致命异常并终止进程, 同时产生相应的crash日志。|

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### napi_get_last_error_info

用于获取最后一次发生的错误信息，包括错误码、错误消息以及错误进栈信息，即使存在挂起的ArkTS异常，也可以调用此API。

cpp部分代码

```cpp
#include "napi/native_api.h"
#include <assert.h>
static napi_value GetLastErrorInfo(napi_env env, napi_callback_info info)
{
    // 获取输入参数（这里以字符串message作为参数传入）
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 将传入的字符串参数以napi_get_value_int32取出，主动制造错误
    int32_t value = 0;
    napi_status status = napi_get_value_int32(env, args[0], &value);
    // 接口使用错误，故返回值不为napi_ok
    assert(status != napi_ok);
    // 调用接口napi_get_last_error_info获取最后一次错误信息
    const napi_extended_error_info *errorInfo;
    napi_get_last_error_info(env, &errorInfo);
    // 取出错误码与接口调用错误后其返回值作比较
    assert(errorInfo->error_code == status);
    // 取出错误消息作为返回值带出去打印
    napi_value result = nullptr;
    napi_create_string_utf8(env, errorInfo->error_message, NAPI_AUTO_LENGTH, &result);
    return result;
}
```

接口声明

```ts
// index.d.ts
export const getLastErrorInfo: (str: string) => string;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_last_error_info: %{public}s', testNapi.getLastErrorInfo('message'));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_get_last_error_info error: %{public}s', error);
}
```

### napi_create_type_error

创建并获取一个带文本信息的ArkTS TypeError。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateTypeError(napi_env env, napi_callback_info info)
{
    // 构造errorCode和errorMessage
    napi_value errorCode = nullptr;
    napi_create_string_utf8(env, "napi_create_error errorCode", NAPI_AUTO_LENGTH, &errorCode);
    napi_value errorMessage = nullptr;
    napi_create_string_utf8(env, "napi_create_error errorMessage", NAPI_AUTO_LENGTH, &errorMessage);
    // 调用napi_create_type_error创建一个typeError错误对象
    napi_value error = nullptr;
    napi_create_type_error(env, errorCode, errorMessage, &error);
    return error;
}
```

接口声明

```ts
// index.d.ts
export const createTypeError: () => Error;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  throw testNapi.createTypeError();
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_create_type_error errorCode: %{public}s, errorMessage %{public}s', error.code, error.message);
}
```

### napi_create_range_error

创建并获取一个带文本信息的ArkTS RangeError。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateRangeError(napi_env env, napi_callback_info info)
{
    // 构造errorCode和errorMessage
    napi_value errorCode = nullptr;
    napi_create_string_utf8(env, "napi_create_error errorCode", NAPI_AUTO_LENGTH, &errorCode);
    napi_value errorMessage = nullptr;
    napi_create_string_utf8(env, "napi_create_error errorMessage", NAPI_AUTO_LENGTH, &errorMessage);
    // 调用napi_create_range_error创建一个typeError错误对象
    napi_value error = nullptr;
    napi_create_range_error(env, errorCode, errorMessage, &error);
    return error;
}
```

接口声明

```ts
// index.d.ts
export const createRangeError: () => Error;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  throw testNapi.createRangeError();
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_create_range_error errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}
```

### napi_create_error

创建并获取一个带文本信息的ArkTS Error。

### napi_throw

用于在Node-API模块中抛出ArkTS异常的函数。当在本机代码中发生错误或检测到不符合预期的情况时，可以使用此接口来抛出一个ArkTS异常，使其能够被捕获并处理。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value NapiThrow(napi_env env, napi_callback_info info)
{
    // 代码中发生某些错误后，可执行以下操作抛出异常
    // 在Node-API环境中创建一个字符串，并将其存储在errorCode变量中
    napi_value errorCode = nullptr;
    napi_create_string_utf8(env, "throw errorCode", NAPI_AUTO_LENGTH, &errorCode);
    // 在Node-API环境中创建一个字符串，并将其存储在errorMessage变量中
    napi_value errorMessage = nullptr;
    napi_create_string_utf8(env, "throw errorMessage", NAPI_AUTO_LENGTH, &errorMessage);
    // 创建一个ArkTS对象error
    napi_value error = nullptr;
    napi_create_error(env, errorCode, errorMessage, &error);
    // 通过napi_throw接口将对象抛出
    napi_throw(env, error);
    return nullptr;
}
```

接口声明

```ts
// index.d.ts
export const napiThrow: () => void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  testNapi.napiThrow();
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_throw errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}
```

### napi_throw_error

用于抛出一个带文本信息的ArkTS Error。

cpp部分代码

```cpp
#include "napi/native_api.h"

// 这里直接抛出一个带有errorMessage的错误
static napi_value NapiThrowErrorMessage(napi_env env, napi_callback_info info)
{
    napi_throw_error(env, nullptr, "napi_throw_error throwing an error");
    return nullptr;
}
// 传入两个参数，在第二个参数，也就是除数为0的时候抛出一个错误
static napi_value NapiThrowError(napi_env env, napi_callback_info info)
{
    // ArkTS侧传入两个参数
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // 将其转换为double类型的值作为被除数和除数
    double dividend, divisor;
    napi_get_value_double(env, argv[0], &dividend);
    napi_get_value_double(env, argv[1], &divisor);
    // 在这里判断除数如果为0则直接抛出一个错误，errorCode为：DIVIDE_BY_ZERO，errorMessage为：Cannot divide by zero
    if (divisor == 0) {
        napi_throw_error(env, "DIVIDE_BY_ZERO", "Cannot divide by zero");
    }
    return nullptr;
}
```

接口声明

```ts
// index.d.ts
export const napiThrowErrorMessage: () => void;
export const napiThrowError: (dividend: number, divisor: number) => void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  testNapi.napiThrowErrorMessage();
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_throw_error error code: %{public}s , message: %{public}s', error.code, error.message);
}
try {
  testNapi.napiThrowError(5, 0);
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_throw_error errorCode: %{public}s , errorManager: %{public}s', error.code, error.message);
}
```

### napi_throw_type_error

创建并获取一个带文本信息的ArkTS TypeError。

cpp部分代码

```cpp
#include "napi/native_api.h"

// 这里直接抛出一个带有errorMessage的TypeError
static napi_value ThrowTypeErrorMessage(napi_env env, napi_callback_info info)
{
    napi_throw_type_error(env, nullptr, "napi_throw_type_error throwing an error");
    return nullptr;
}
// 传入一个类型不匹配的参数，判断类型不匹配之后抛出typeError
static napi_value ThrowTypeError(napi_env env, napi_callback_info info)
{
    // ArkTS侧传入一个参数
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // 将传入参数转换为napi_valuetype类型的值
    napi_valuetype valueType;
    napi_typeof(env, argv[0], &valueType);
    // 如果传入参数不为napi_number类型的值则抛出TypeError
    if (valueType != napi_number) {
        // 这里抛出一个既带有errorCode也带有errorMessage的TypeError
        napi_throw_type_error(env, "napi_throw_type_error", "Argument must be a number");
    }
    return nullptr;
}
```

接口声明

```ts
// index.d.ts
export const throwTypeErrorMessage: () => void;
export const throwTypeError: (message: string) => void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
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

### napi_throw_range_error

创建并获取一个带文本信息的ArkTS RangeError。

cpp部分代码

```cpp
#include "napi/native_api.h"

// 这里直接抛出一个带有errorMessage的RangeError
static napi_value ThrowRangeErrorMessage(napi_env env, napi_callback_info info)
{
    napi_throw_range_error(env, nullptr, "napi_throw_range_error one");
    return nullptr;
}
// 传入不匹配的参数个数，判断不匹配之后抛出rangeError
static napi_value ThrowRangeError(napi_env env, napi_callback_info info)
{
    // ArkTS侧传入两个参数
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // 如果传入参数个数不为2
    if (argc != 2) {
        // 这里抛出一个RangeError
        napi_throw_range_error(env, "napi_throw_range_error", "Expected two numbers as arguments");
        return nullptr;
    }
    // 下面将传入的两值相加并传出去
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

接口声明

```ts
// index.d.ts
export const throwRangeErrorMessage: () => void;
export const throwRangeError: (num: number) => number | void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
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

### napi_is_error

用于判断给定的napi_value是否表示一个error对象。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value NapiIsError(napi_env env, napi_callback_info info)
{
    // 接收一个入参
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 调用接口napi_is_error判断入参是否为一个error对象
    bool result = false;
    // 如果napi_value为一个error对象，则设置result为true的布尔值，否则设置为false
    napi_is_error(env, args[0], &result);
    // 取出result通过napi_get_boolean接口将取出的bool值转换为napi_value类型的值返回出去
    napi_value returnValue = nullptr;
    napi_get_boolean(env, result, &returnValue);
    return returnValue;
}
```

接口声明

```ts
// index.d.ts
export const napiIsError: <T>(obj: T) => boolean;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  throw new Error("throwing an error");
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_error error: %{public}s', testNapi.napiIsError(error)
    .toString());
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_error error: %{public}s', testNapi.napiIsError(1)
    .toString());
}
```

### napi_get_and_clear_last_exception

用于获取并清除最近一次出现的异常。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetAndClearLastException(napi_env env, napi_callback_info info)
{
    // 抛出异常，创造异常情况
    napi_throw_error(env, "napi_create_error errorCode", "napi_create_error errorMessage");
    // 调用napi_get_and_clear_last_exception接口获取并清除最后一个未处理的异常。即使存在挂起的ArkTS异常，也可以调用此API
    napi_value result = nullptr;
    napi_status status = napi_get_and_clear_last_exception(env, &result);
    if (status != napi_ok) {
        return nullptr;
    }
    return result;
}
```

接口声明

```ts
// index.d.ts
export const getAndClearLastException: () => Error | void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
// 这里获取到最后一个未处理的异常
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_and_clear_last_exception, error.message: %{public}s',
           testNapi.getAndClearLastException());
```

### napi_is_exception_pending

用于判断是否出现了异常。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value IsExceptionPending(napi_env env, napi_callback_info info)
{
    napi_status status;
    bool isExceptionPending = false;
    // 在执行一些可能引发异常的操作后
    napi_throw_error(env, "napi_create_error errorCode", "napi_create_error errorMessage");
    // 检查当前环境中是否有异常挂起
    status = napi_is_exception_pending(env, &isExceptionPending);
    if (status != napi_ok) {
        return nullptr;
    }
    if (isExceptionPending) {
        // 处理异常挂起的情况
        napi_value result = nullptr;
        status = napi_get_and_clear_last_exception(env, &result);
        if (status != napi_ok) {
            return nullptr;
        }
        // 将处理的异常返回出去
        return result;
    }
    return nullptr;
}
```

接口声明

```ts
// index.d.ts
export const isExceptionPending: () => Object | void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
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

### napi_fatal_error

用于引发致命错误以立即终止进程。在调用napi_fatal_error函数后，导致应用程序终止，因此应该慎重使用，避免在正常操作中频繁调用该函数。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value FatalError(napi_env env, napi_callback_info info)
{
    // 请注意，使用napi_fatal_error函数会导致应用进程直接终止，因此应该谨慎使用，仅在遇到无法恢复的严重错误时才应该调用该函数
    // 模拟一个致命错误条件
    bool errorCondition = true;
    if (errorCondition) {
        // 创建一个致命错误信息
        napi_fatal_error("napi_fatal_error test", NAPI_AUTO_LENGTH, "napi_create_error errorMessage", NAPI_AUTO_LENGTH);
    }
    return nullptr;
}
```

接口声明

```ts
// index.d.ts
export const fatalError: () => void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  testNapi.fatalError();
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_fatal_error error');
}
```

### napi_fatal_exception
在主线程的上下文环境中调用napi_fatal_exception函数后，抛出一个致命异常，导致应用程序终止，同时会生成相应的crash日志。因此应该慎重使用，避免在正常操作中频繁调用该函数。

cpp部分代码

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
    // 请注意，使用napi_fatal_exception函数会导致应用进程直接终止，因此应该谨慎使用，仅在主线程遇到无法恢复的严重错误时才应该调用该函数
    // 模拟一个致命错误条件
    status = napi_fatal_exception(env, args[0]);
    if (status != napi_ok) {
      return nullptr;
    }
    return nullptr;
}
```

接口声明

```ts
// index.d.ts
export const fatalException: (err: Error) => void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

const err = new Error("a fatal exception occurred");
testNapi.fatalException(err);
```

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```