# Working with BigInt Using JSVM-API

## Introduction

BigInt is a data type used to represent integers of any precision in JavaScript (JS), with values greater than the value range of the Number type. You can use JSVM-API to create, obtain, and operate JS BigInt values.

## Basic Concepts

Before using JSVM-API to operate BigInt values, you need to understand the following basic concepts:

- BigInt: a data type used to represent integers of any precision in JS. Different from the Number type, BigInt can accurately represent very large integers without losing precision or causing overflows.
- BigInt creation: You can use JSVM-API to create a JS BigInt object from a C **Int64** or **Uint64** value. This makes it easy to create BigInt values using C/C++.
- BigInt operation: JSVM-API provides APIs for operating BigInt values. You can use these APIs to obtain and convert BigInt values and perform arithmetic and bitwise operations.

## Available APIs

| API                        | Description                                |
| ---------------------------- | ---------------------------------------- |
| OH_JSVM_CreateBigintInt64     | Creates a JS BigInt object from a C int64_t object.|
| OH_JSVM_CreateBigintUint64    | Creates a JS BigInt object from a C uint64_t object.|
| OH_JSVM_CreateBigintWords     | Creates a JS BigInt object from a C uint64_t array.|
| OH_JSVM_GetValueBigintInt64  | Obtains the C int64_t primitive equivalent of the given JS BigInt. If necessary, it truncates the value and sets **lossless** to **false**.      |
| OH_JSVM_GetValueBigintUint64 | Obtains the C uint64_t primitive equivalent of the given JS BigInt. If necessary, it truncates the value and sets **lossless** to **false**.     |
| OH_JSVM_GetValueBigintWords  | Obtains the underlying data of a given JS BigInt object, that is, the word representation of BigInt data. Both **signBit** and **words** can be set to **NULL**. In this case, only **wordCount** is obtained.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ and ArkTS code related to BigInt operations.

### OH_JSVM_GetValueBigintWords

Use **OH_JSVM_GetValueBigintWords** to obtain the underlying data of a given JS BigInt object, that is, the word representation of BigInt data.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetValueBigintWords callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueBigintWords},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getValueBigintWords and associate it with a callback. This allows the GetValueBigintWords callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueBigintWords", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetValueBigintWords.
static JSVM_Value GetValueBigintWords(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    int signBit = 0;
    size_t wordCount = 0;
    uint64_t words;
    // Call OH_JSVM_GetValueBigintWords to obtain wordCount.
    JSVM_Status status = OH_JSVM_GetValueBigintWords(env, args[0], nullptr, &wordCount, nullptr);
    OH_LOG_INFO(LOG_APP, "OH_JSVM_GetValueBigintWords wordCount:%{public}d.", wordCount);
    // Call OH_JSVM_GetValueBigintWords to obtain BigInt information, such as whether the value passed by signBit is a positive or negative number.
    status = OH_JSVM_GetValueBigintWords(env, args[0], &signBit, &wordCount, &words);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_JSVM_GetValueBigintWords fail, status:%{public}d.", status);
    } else {
        OH_LOG_INFO(LOG_APP, "OH_JSVM_GetValueBigintWords signBit: %{public}d.", signBit);
    }
    // Convert the sign bit into a value of Int type and pass it.
    JSVM_Value returnValue = nullptr;
    OH_JSVM_CreateInt32(env, signBit, &returnValue);
    return returnValue;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  let script: string = `getValueBigintWords(BigInt(5555555555555555))`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getValueBigintWords: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getValueBigintWords error: %{public}s', error.message);
}
try {
  let script: string = `getValueBigintWords(BigInt(-5555555555555555))`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getValueBigintWords: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getValueBigintWords error: %{public}s', error.message);
}
```

### OH_JSVM_CreateBigintWords

Use **OH_JSVM_GetValueBigintWords** to create a JS BigInt object from a C uint64_t array.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CreateBigintWords callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateBigintWords},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createBigintWords and associate it with a callback. This allows the CreateBigintWords callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createBigintWords", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CreateBigintWords.
static int DIFF_VALUE_THREE = 3;
static JSVM_Value CreateBigintWords(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Call OH_JSVM_CreateBigintWords to create a BigInt object.
    int signBit = 0;
    size_t wordCount = DIFF_VALUE_THREE;
    uint64_t words[] = {12ULL, 34ULL, 56ULL};
    JSVM_Value returnValue = nullptr;
    JSVM_Status status = OH_JSVM_CreateBigintWords(env, signBit, wordCount, words, &returnValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateBigintWords fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CreateBigintWords success");
    }
    return returnValue;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  let script: string = `createBigintWords()`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createBigintWords: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createBigintWords error: %{public}s', error.message);
}
```

### OH_JSVM_CreateBigintUint64

Use **OH_JSVM_CreateBigintUint64** to create a JS BigInt object from a C Uint64 object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Declare the variable value of uint64_t.
static uint64_t TEST_VALUE = 5555555555555555555;
// Define CreateBigintUint64.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateBigintUint64},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createBigintUint64 and associate it with a callback. This allows the CreateBigintUint64 callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createBigintUint64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CreateBigintUint64.
static JSVM_Value CreateBigintUint64(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Convert value to the JSVM_Value type and return the value.
    JSVM_Value returnValue = nullptr;
    JSVM_Status status = OH_JSVM_CreateBigintUint64(env, TEST_VALUE, &returnValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateBigintUint64 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CreateBigintUint64 success");
    }
    return returnValue;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  let script: string = `createBigintUint64()`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createBigintUint64: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createBigintUint64 error: %{public}s', error.message);
}
```

### OH_JSVM_GetValueBigintUint64

Use **OH_JSVM_GetValueBigintUint64** to obtain the C uint64_t primitive equivalent of the given JS BigInt object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetValueBigintUint64 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueBigintUint64},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getValueBigintUint64 and associate it with a callback. This allows the GetValueBigintUint64 callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueBigintUint64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetValueBigintUint64.
static JSVM_Value GetValueBigintUint64(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the BigInt value.
    uint64_t value = 0;
    bool lossLess = false;
    OH_JSVM_GetValueBigintUint64(env, args[0], &value, &lossLess);
    // Check whether the BigInt value obtained is a product of lossless conversion. If no, an exception is thrown.
    if (!lossLess) {
        OH_JSVM_ThrowError(env, nullptr, "BigInt values have no lossless converted");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueBigintUint64 success:%{public}d", lossLess);
    }
    JSVM_Value returnValue = nullptr;
    OH_JSVM_CreateBigintUint64(env, value, &returnValue);
    return returnValue;
}
```

API declaration:

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  let script: string = `getValueBigintUint64(BigInt(5555555555555555))`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getValueBigintUint64: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getValueBigintUint64 error: %{public}s', error.message);
}
```

### OH_JSVM_CreateBigintInt64

Use **OH_JSVM_CreateBigintInt64** to create a JS BigInt object from a C Int64 object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Declare the variable value of int64_t.
static int64_t TEST_VALUE_DEMO = -5555555555555555555;
// Register the CreateBigintInt64 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateBigintInt64},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createBigintInt64 and associate it with a callback. This allows the CreateBigintInt64 callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createBigintInt64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CreateBigintInt64.
static JSVM_Value CreateBigintInt64(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Value returnValue = nullptr;
    JSVM_Status status = OH_JSVM_CreateBigintInt64(env, TEST_VALUE_DEMO, &returnValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateBigintInt64 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CreateBigintInt64 success");
    }
    return returnValue;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  let script: string = `createBigintInt64()`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createBigintInt64: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createBigintInt64 error: %{public}s', error.message);
}
```

### OH_JSVM_GetValueBigintInt64

Use OH_JSVM_GetValueBigintInt64 to obtain the C int64_t primitive equivalent of the given JS BigInt object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetBigintInt64 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetBigintInt64},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getBigintInt64 and associate it with a callback. This allows the GetBigintInt64 callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getBigintInt64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetValueBigintInt64.
static JSVM_Value GetBigintInt64(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the 64-bit big integer from the input parameter.
    int64_t value;
    bool lossLess;
    OH_JSVM_GetValueBigintInt64(env, args[0], &value, &lossLess);
    // Check whether the BigInt value obtained is a product of lossless conversion. If no, an exception is thrown.
    if (!lossLess) {
        OH_JSVM_ThrowError(env, nullptr, "BigInt values have no lossless converted");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetBigintInt64 success:%{public}d", lossLess);
    }
    JSVM_Value returnValue = nullptr;
    OH_JSVM_CreateBigintInt64(env, value, &returnValue);
    return returnValue;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  let script: string = `getBigintInt64(BigInt(-5555555555555555))`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getBigintInt64: %{public}d', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getBigintInt64 error: %{public}s', error.message);
}
```
