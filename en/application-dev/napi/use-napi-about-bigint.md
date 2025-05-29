# Working with BigInt Using Node-API

## Introduction

BigInt is a data type used to represent integers of any precision in ArkTS, with values greater than the value range of the Number type. You can use Node-API to create, obtain, and operate ArkTS BigInt values.

## Basic Concepts

Before using Node-API to operate BigInt values, you need to understand the following basic concepts:

- BigInt: a data type used to represent integers of any precision in ArkTS. Different from the Number type, BigInt can accurately represent very large integers without losing precision or causing overflows.
- BigInt creation: You can use Node-API to create a ArkTS BigInt object from a C **Int64** or **Uint64** value. This makes it easy to create BigInt values using C/C++.
- BigInt operation: Node-API provides APIs for operating BigInt values. You can use these APIs to obtain and convert BigInt values and perform arithmetic and bitwise operations.

## Available APIs

| API| Description|
| -------- | -------- |
| napi_create_bigint_int64 | Creates an ArkTS BigInt object from a signed 64-bit integer in C/C++.|
| napi_create_bigint_uint64 | Creates an ArkTS BigInt object from an unsigned 64-bit integer in C/C++.|
| napi_create_bigint_words | Creates an ArkTS BigInt object from an array of unsigned 64-bit byte data in C/C++.|
| napi_get_value_bigint_int64 | Obtains a signed 64-bit integer from an ArkTS BigInt object.|
| napi_get_value_bigint_uint64 | Obtains an unsigned 64-bit integer from an ArkTS BigInt object.|
| napi_get_value_bigint_words | Obtains the underlying 64-bit unsigned (uint64) byte data from an ArkTS BigInt object.|


## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code related to BigInt conversions.

### napi_create_bigint_int64

Use **napi_create_bigint_int64** to create an ArkTS BigInt object from a signed 64-bit integer in C/C++.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CreateBigintInt64t(napi_env env, napi_callback_info info)
{
    // Declare the int64_t variable value.
    int64_t value = -5555555555555555555;
    // Convert the value to the napi_value type and return napi_value.
    napi_value returnValue = nullptr;
    napi_create_bigint_int64(env, value, &returnValue);
    return returnValue;
}
```

API declaration:

```ts
// index.d.ts
export const createBigintInt64t: () => bigint;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_bigint_int64: %{public}d', testNapi.createBigintInt64t());
```

### napi_create_bigint_uint64

Use **napi_create_bigint_uint64** to create an ArkTS BigInt object from an unsigned 64-bit integer in C/C++.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CreateBigintUint64t(napi_env env, napi_callback_info info)
{
    // Declare the uint64_t variable value.
    uint64_t value = 5555555555555555555;
    // Convert the value to the napi_value type and return napi_value.
    napi_value returnValue = nullptr;
    napi_create_bigint_uint64(env, value, &returnValue);
    return returnValue;
}
```

API declaration:

```ts
// index.d.ts
export const createBigintUint64t: () => bigint;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_bigint_uint64: %{public}d', testNapi.createBigintUint64t());
```

### napi_create_bigint_words

Use **napi_create_bigint_words** to create an ArkTS BigInt object based on the given byte data.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CreateBigintWords(napi_env env, napi_callback_info info)
{
    // Call napi_create_bigint_words to create a BigInt object.
    int signBit = 0;
    size_t wordCount = 3;
    uint64_t words[] = {12ULL, 34ULL, 56ULL};
    napi_value returnValue = nullptr;
    napi_status status = napi_create_bigint_words(env, signBit, wordCount, words, &returnValue);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_create_bigint_words fail");
        return nullptr;
    }
    return returnValue;
}
```

API declaration:

```ts
// index.d.ts
export const createBigintWords: () => bigint | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_bigint_words: %{public}d', testNapi.createBigintWords());
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API NapiGetValueBigint: %{public}s', error.message);
}
```

### napi_get_value_bigint_int64

Use **napi_get_value_bigint_int64** to obtain a signed 64-bit integer from an ArkTS BigInt object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetValueBigintInt64t(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the 64-bit big integer from the input parameter.
    int64_t value = 0;
    bool lossLess = false;
    napi_status status = napi_get_value_bigint_int64(env, args[0], &value, &lossLess);
    // Check whether the BigInt value obtained is a product of lossless conversion. If no, throw an exception.
    if (!lossLess) {
        napi_throw_error(env, nullptr, "BigInt values have not been lossless converted");
        return nullptr;
    }
    // If the API is successfully called, return true to ArkTS.
    napi_value returnValue = nullptr;
    napi_get_boolean(env, status == napi_ok, &returnValue);
    return returnValue;
}
```

API declaration:

```ts
// index.d.ts
export const getValueBigintInt64t: (bigInt64: bigint) => boolean | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
let bigInt = BigInt(-5555555555555555);
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_value_bigint_int64: %{public}s',
             JSON.stringify(testNapi.getValueBigintInt64t(bigInt)));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API NapiGetValueBigint: %{public}s', error.message);
}
```

### napi_get_value_bigint_uint64

Use **napi_get_value_bigint_uint64** to obtain an unsigned 64-bit integer from an ArkTS BigInt object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetValueBigintUint64t(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the BigInt value.
    uint64_t value = 0;
    bool lossLess = false;
    napi_status status = napi_get_value_bigint_uint64(env, args[0], &value, &lossLess);
    // Check whether the BigInt value obtained is a product of lossless conversion. If no, throw an exception.
    if (!lossLess) {
        napi_throw_error(env, nullptr, "BigInt values have no lossless converted");
        return nullptr;
    }
    // If the API is successfully called, return true to ArkTS.
    napi_value returnValue = nullptr;
    napi_get_boolean(env, status == napi_ok, &returnValue);
    return returnValue;
}
```

API declaration:

```ts
// index.d.ts
export const getValueBigintUint64t: (bigUint64: bigint) => boolean | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
let bigUint = BigInt(5555555555555555);
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_value_bigint_uint64: %{public}s',
             JSON.stringify(testNapi.getValueBigintUint64t(bigUint)));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API NapiGetValueBigint: %{public}s', error.message);
}
```

### napi_get_value_bigint_words

Use **napi_get_value_bigint_words** to obtain the underlying unsigned 64-bit (uint64) binary byte data from an ArkTS BigInt object.

CPP code:

```cpp
#include "hilog/log.h"
#include "napi/native_api.h"

static napi_value GetValueBigintWords(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    int signBit = 0;
    size_t wordCount = 0;
    uint64_t words = 0;
    // Call napi_get_value_bigint_words to obtain wordCount.
    napi_status status = napi_get_value_bigint_words(env, args[0], nullptr, &wordCount, nullptr);
    OH_LOG_INFO(LOG_APP, "Node-API , wordCount:%{public}d.", wordCount);
    // Call napi_get_value_bigint_words to obtain BigInt information, such as whether the value passed by signBit is a positive or negative number.
    status = napi_get_value_bigint_words(env, args[0], &signBit, &wordCount, &words);
    OH_LOG_INFO(LOG_APP, "Node-API , signBit: %{public}d.", signBit);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "Node-API , reason:%{public}d.", status);
        napi_throw_error(env, nullptr, "napi_get_date_value fail");
        return nullptr;
    }
    // Convert the sign bit into a value of Int type and pass it.
    napi_value returnValue = nullptr;
    napi_create_int32(env, signBit, &returnValue);
    return returnValue;
}
```

API declaration:

```ts
// index.d.ts
export const getValueBigintWords: (bigIntWords: bigint) => bigint | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
let bigInt = BigInt(-5555555555555555);
let bigUint = BigInt(5555555555555555);
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_value_bigint_words signBit is: %{public}d', testNapi.getValueBigintWords(bigInt));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_value_bigint_words signBit is: %{public}d', testNapi.getValueBigintWords(bigUint));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API NapiGetValueBigint: %{public}s', error.message);
}
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
