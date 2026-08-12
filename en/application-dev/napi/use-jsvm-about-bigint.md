# Working with BigInt Using JSVM-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=f34ddda28f1bcebae0ddfbd293a9ffe8cb2789f9 translatedAt=2026-08-12T06:29:49.228Z pushedAt=2026-08-12T10:52:44.223Z -->

## Introduction

BigInt is a data type used to represent integers of any precision in JavaScript (JS), with values greater than the value range of the Number type. You can use JSVM-API to create, obtain, and operate JS BigInt values.

## Basic Concepts

Before using JSVM-API to operate BigInt values, you need to understand the following basic concepts:

- BigInt: a data type used to represent integers of any precision in JS. Unlike the Number type, BigInt can accurately represent very large integers without losing precision or causing overflows.

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
| OH_JSVM_GetValueBigintWords  | Obtains the underlying data (word representation) of a given JS BigInt object. The word representation includes a sign bit, a 64-bit little-endian array, and the length of the array. If **signBit** and **words** are set to **NULL**, only **wordCount** is obtained.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code and ArkTS code involved in related APIs.

### OH_JSVM_GetValueBigintWords

Use **OH_JSVM_GetValueBigintWords** to obtain the underlying data of a given JS BigInt object, that is, the word representation of BigInt data.

CPP code:

<!-- @[oh_jsvm_get_value_bigint_words](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutBigint/getvaluebigintwords/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "hilog/log.h"
#include "ark_runtime/jsvm.h"
#include <cstdlib>
// ...
// Sample method for OH_JSVM_GetValueBigintWords
static JSVM_Value GetValueBigintWords(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    int signBit = 0;
    size_t wordCount = 0;
    uint64_t* words{nullptr};
    // Call the OH_JSVM_GetValueBigintWords API to obtain wordCount.
    JSVM_Status status = OH_JSVM_GetValueBigintWords(env, args[0], nullptr, &wordCount, nullptr);
    OH_LOG_INFO(LOG_APP, "OH_JSVM_GetValueBigintWords wordCount:%{public}zu.", wordCount);
    if (wordCount == 0 || wordCount > MAX_MALLOC_SIZE) {
        OH_LOG_ERROR(LOG_APP, "Invalid wordCount: %{public}zu", wordCount);
        return nullptr;
    }
    words = (uint64_t*)malloc(wordCount*sizeof(uint64_t));
    if (words == nullptr) {
        OH_LOG_ERROR(LOG_APP, "OH_JSVM_GetValueBigintWords malloc failed.");
        return nullptr;
    }
    // Call the OH_JSVM_GetValueBigintWords API to obtain information about the incoming bigInt, such as passing the sign of bigInt via signBit.
    status = OH_JSVM_GetValueBigintWords(env, args[0], &signBit, &wordCount, words);
    free(words);
    words = nullptr;
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_JSVM_GetValueBigintWords fail, status:%{public}d.", status);
    } else {
        OH_LOG_INFO(LOG_APP, "OH_JSVM_GetValueBigintWords signBit: %{public}d.", signBit);
    }
    // Convert the sign bit to int type and pass it out.
    JSVM_Value returnValue = nullptr;
    OH_JSVM_CreateInt32(env, signBit, &returnValue);
    return returnValue;
}
// Register callback for GetValueBigintWords
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueBigintWords},
};
static JSVM_CallbackStruct *method = param;
// Alias for the GetValueBigintWords method, for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueBigintWords", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char* SRC_CALL_NATIVE = R"JS(getValueBigintWords(BigInt(5555555555555555)))JS";
```

Expected result:

```ts
OH_JSVM_GetValueBigintWords wordCount:1.
OH_JSVM_GetValueBigintWords signBit: 0.
```

### OH_JSVM_CreateBigintWords

Creates a JavaScript BigInt object based on a given uint64_t array.

CPP code:

<!-- @[oh_jsvm_create_bigint_words](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutBigint/createbigintwords/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...

// Sample method for OH_JSVM_CreateBigintWords
static int g_diffValueThree = 3;
static JSVM_Value CreateBigintWords(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Use the OH_JSVM_CreateBigintWords API to create a BigInt object.
    int signBit = 0;
    size_t wordCount = g_diffValueThree;
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
// Register callback for CreateBigintWords
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateBigintWords},
};
static JSVM_CallbackStruct *method = param;
// Alias for the CreateBigintWords method, for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"createBigintWords", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char* SRC_CALL_NATIVE = R"JS(createBigintWords())JS";
```

Expected result:

```ts
JSVM OH_JSVM_CreateBigintWords success
```

### OH_JSVM_CreateBigintUint64

Creates a JavaScript BigInt object based on a given uint64 type object.

CPP code:

<!-- @[oh_jsvm_create_bigint_uint64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutBigint/createbigintuint64/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...

// Declare a uint64_t variable value.
static uint64_t g_testValue = 5555555555555555555;
// Sample method for OH_JSVM_CreateBigintUint64
static JSVM_Value CreateBigintUint64(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Convert value to JSVM_Value type and return it.
    JSVM_Value returnValue = nullptr;
    JSVM_Status status = OH_JSVM_CreateBigintUint64(env, g_testValue, &returnValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateBigintUint64 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CreateBigintUint64 success");
    }
    return returnValue;
}
// Register callback for CreateBigintUint64
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateBigintUint64},
};
static JSVM_CallbackStruct *method = param;
// Alias for the CreateBigintUint64 method, for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"createBigintUint64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(createBigintUint64())JS";
```

Expected result:

```ts
JSVM OH_JSVM_CreateBigintUint64 success

```

### OH_JSVM_GetValueBigintUint64

Obtains the uint64_t primitive type value of a given JavaScript BigInt.

CPP code:

<!-- @[oh_jsvm_get_value_bigint_uint64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutBigint/getvaluebigintuint64/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...

// Sample method for OH_JSVM_GetValueBigintUint64
static JSVM_Value GetValueBigintUint64(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the BigInt value from the parameter.
    uint64_t value = 0;
    bool lossLess = false;
    OH_JSVM_GetValueBigintUint64(env, args[0], &value, &lossLess);
    // Check whether the bigint obtained from the JS side is a lossless conversion. If not, throw an exception.
    if (!lossLess) {
        OH_JSVM_ThrowError(env, nullptr, "BigInt values have no lossless conversion");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueBigintUint64 success:%{public}d", lossLess);
    }
    JSVM_Value returnValue = nullptr;
    OH_JSVM_CreateBigintUint64(env, value, &returnValue);
    return returnValue;
}
// Register callback for GetValueBigintUint64
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueBigintUint64},
};
static JSVM_CallbackStruct *method = param;
// Alias for the GetValueBigintUint64 method, for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueBigintUint64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char* SRC_CALL_NATIVE = R"JS(getValueBigintUint64(BigInt(5555555555555555)))JS";
```

Expected result:

```ts
JSVM GetValueBigintUint64 success
```

### OH_JSVM_CreateBigintInt64

Creates a JavaScript BigInt object based on a given int64_t type object.

CPP code:

<!-- @[oh_jsvm_create_bigint_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutBigint/createbigintint64/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...

// Declare an int64_t variable value.
static int64_t g_testValueDemo = -5555555555555555555;
// Sample method for OH_JSVM_CreateBigintInt64
static JSVM_Value CreateBigintInt64(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Value returnValue = nullptr;
    JSVM_Status status = OH_JSVM_CreateBigintInt64(env, g_testValueDemo, &returnValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateBigintInt64 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CreateBigintInt64 success");
    }
    return returnValue;
}
// Register callback for CreateBigintInt64
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateBigintInt64},
};
static JSVM_CallbackStruct *method = param;
// Alias for the CreateBigintInt64 method, for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"createBigintInt64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char* SRC_CALL_NATIVE = R"JS(createBigintInt64())JS";
```

Expected result:

```ts
JSVM OH_JSVM_CreateBigintInt64 success
```

### OH_JSVM_GetValueBigintInt64

Use OH_JSVM_GetValueBigintInt64 to obtain the C int64_t primitive equivalent of the given JS BigInt object.

CPP code:

<!-- @[oh_jsvm_get_value_bigint_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutBigint/getvaluebigintint64/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...

// Sample method for OH_JSVM_GetValueBigintInt64
static JSVM_Value GetBigintInt64(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Extract the 64-bit integer BigInt data from the incoming parameter.
    int64_t value = 0;
    bool lossLess = false;
    OH_JSVM_GetValueBigintInt64(env, args[0], &value, &lossLess);
    // Check whether the bigint obtained from the JS side is a lossless conversion. If not, throw an exception.
    if (!lossLess) {
        OH_JSVM_ThrowError(env, nullptr, "BigInt values have no lossless conversion");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetBigintInt64 success:%{public}d", lossLess);
    }
    JSVM_Value returnValue = nullptr;
    OH_JSVM_CreateBigintInt64(env, value, &returnValue);
    return returnValue;
}
// Register callback for GetBigintInt64
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetBigintInt64},
};
static JSVM_CallbackStruct *method = param;
// Alias for the GetBigintInt64 method, for JS invocation
static JSVM_PropertyDescriptor descriptor[] = {
    {"getBigintInt64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char* SRC_CALL_NATIVE = R"JS(getBigintInt64(BigInt(-5555555555555555)))JS";
```

Expected result:

```ts
JSVM GetBigintInt64 success:1
```