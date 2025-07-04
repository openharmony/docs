# 使用Node-API接口操作bigint类型值

## 简介

BigInt是ArkTS中用于表示任意精度整数的数据类型，它能够处理比Number类型更大范围的整数值。通过Node-API提供的接口，可以在Node-API模块中创建、获取和操作BigInt类型值，从而实现与BigInt相关的功能扩展。

## 基本概念

在使用Node-API接口操作BigInt类型值时，需要理解以下基本概念：

- **BigInt类型：** BigInt是ArkTS中的一种数据类型，用于表示任意精度的整数。与Number类型不同，BigInt类型可以精确表示非常大的整数，而不会丢失精度或溢出。
- **BigInt创建：** 使用Node-API提供的接口，可以通过传递C的int64或uint64数据来创建对应的ArkTS BigInt。这使得在Node-API模块中可以方便地创建BigInt类型值。
- **BigInt操作：** Node-API提供了多个接口用于操作BigInt类型值。通过这些接口，可以获取BigInt的数值，进行数值转换，以及执行常见的算术和位运算操作。

## 场景和功能介绍

| 接口 | 描述 |
| -------- | -------- |
| napi_create_bigint_int64 | 用于创建64位带符号整数（int64）的BigInt对象的函数。 |
| napi_create_bigint_uint64 | 用于创建64位无符号整数（uint64）的BigInt对象的函数。 |
| napi_create_bigint_words | 用于根据提供的64位无符号（uint64）字节数据创建BigInt对象的函数。 |
| napi_get_value_bigint_int64 | 用于从BigInt对象中获取64位带符号整数（int64）值的函数。 |
| napi_get_value_bigint_uint64 | 用于从BigInt对象中获取64位无符号整数（uint64）值的函数。 |
| napi_get_value_bigint_words | 用于从BigInt对象中获取底层的64位无符号（uint64）字节数据。 |


## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### napi_create_bigint_int64

这个函数用于在给定的Node-API环境中依据一个带有符号的64位整数创建一个ArkTS的BigInt对象。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateBigintInt64t(napi_env env, napi_callback_info info)
{
    // 声明int64_t的变量value
    int64_t value = -5555555555555555555;
    // 将value转化为napi_value类型返回
    napi_value returnValue = nullptr;
    napi_create_bigint_int64(env, value, &returnValue);
    return returnValue;
}
```
<!-- @[napi_create_bigint_int64](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const createBigintInt64t: () => bigint;
```
<!-- @[napi_create_bigint_int64_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_bigint_int64: %{public}d', testNapi.createBigintInt64t());
```
<!-- @[ark_napi_create_bigint_int64](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/ets/pages/Index.ets) -->

### napi_create_bigint_uint64

这个函数用于在给定的Node-API环境中依据一个无符号的64位整数创建一个ArkTS的BigInt对象。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateBigintUint64t(napi_env env, napi_callback_info info)
{
    // 声明uint64_t的变量value
    uint64_t value = 5555555555555555555;
    // 将value转化为napi_value类型返回
    napi_value returnValue = nullptr;
    napi_create_bigint_uint64(env, value, &returnValue);
    return returnValue;
}
```
<!-- @[napi_create_bigint_uint64](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const createBigintUint64t: () => bigint;
```
<!-- @[napi_create_bigint_uint64_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_bigint_uint64: %{public}d', testNapi.createBigintUint64t());
```
<!-- @[ark_napi_create_bigint_uint64](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/ets/pages/Index.ets) -->

### napi_create_bigint_words

这个函数用于在给定的Node-API环境中由一系列无符号64位整数创建一个ArkTS的BigInt对象。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateBigintWords(napi_env env, napi_callback_info info)
{
    // 使用napi_create_bigint_words接口创建一个BigInt对象
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
<!-- @[napi_create_bigint_words](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const createBigintWords: () => bigint | void;
```
<!-- @[napi_create_bigint_words_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_bigint_words: %{public}d', testNapi.createBigintWords());
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API NapiGetValueBigint: %{public}s', error.message);
}
```
<!-- @[ark_napi_create_bigint_words](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/ets/pages/Index.ets) -->

### napi_get_value_bigint_int64

用于从传入的参数中提取64位整数的BigInt数据，以供后续处理。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetValueBigintInt64t(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 从传入的参数中提取64位整数的BigInt数据
    int64_t value = 0;
    bool lossLess = false;
    napi_status status = napi_get_value_bigint_int64(env, args[0], &value, &lossLess);
    // 判断从ArkTS侧获取bigint是否为无损转换，如果不是抛出异常
    if (!lossLess) {
        napi_throw_error(env, nullptr, "BigInt values have not been lossless converted");
        return nullptr;
    }
    // 如果接口调用成功正常调用则返回true给ArkTS侧
    napi_value returnValue = nullptr;
    napi_get_boolean(env, status == napi_ok, &returnValue);
    return returnValue;
}
```
<!-- @[napi_get_value_bigint_int64](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getValueBigintInt64t: (bigInt64: bigint) => boolean | void;
```
<!-- @[napi_get_value_bigint_int64_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

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
<!-- @[ark_napi_get_value_bigint_int64](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/ets/pages/Index.ets) -->

### napi_get_value_bigint_uint64

用于从传入的参数中提取无符号64位整数的BigInt数据，以供后续处理。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetValueBigintUint64t(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 从参数值中获取BigInt的数值
    uint64_t value = 0;
    bool lossLess = false;
    napi_status status = napi_get_value_bigint_uint64(env, args[0], &value, &lossLess);
    // 判断从ArkTS侧获取bigint是否为无损转换，如果不是抛出异常
    if (!lossLess) {
        napi_throw_error(env, nullptr, "BigInt values have no lossless converted");
        return nullptr;
    }
    // 如果接口调用成功正常调用则返回true给ArkTS侧
    napi_value returnValue = nullptr;
    napi_get_boolean(env, status == napi_ok, &returnValue);
    return returnValue;
}
```
<!-- @[napi_get_value_bigint_uint64](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getValueBigintUint64t: (bigUint64: bigint) => boolean | void;
```
<!-- @[napi_get_value_bigint_uint64_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

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
<!-- @[ark_napi_get_value_bigint_uint64](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/ets/pages/Index.ets) -->

### napi_get_value_bigint_words

用于获取ArkTS的BigInt对象底层的64位无符号（uint64）二进制字节数据。

cpp部分代码

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
    // 调用napi_get_value_bigint_words接口获取wordCount
    napi_status status = napi_get_value_bigint_words(env, args[0], nullptr, &wordCount, nullptr);
    OH_LOG_INFO(LOG_APP, "Node-API , wordCount:%{public}d.", wordCount);
    // 调用napi_get_value_bigint_words接口获取传入bigInt相关信息，如：signBit传入bigInt正负信息
    status = napi_get_value_bigint_words(env, args[0], &signBit, &wordCount, &words);
    OH_LOG_INFO(LOG_APP, "Node-API , signBit: %{public}d.", signBit);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "Node-API , reason:%{public}d.", status);
        napi_throw_error(env, nullptr, "napi_get_date_value fail");
        return nullptr;
    }
    // 将符号位转化为int类型传出去
    napi_value returnValue = nullptr;
    napi_create_int32(env, signBit, &returnValue);
    return returnValue;
}
```
<!-- @[napi_get_value_bigint_words](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getValueBigintWords: (bigIntWords: bigint) => bigint | void;
```
<!-- @[napi_get_value_bigint_words_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

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
<!-- @[ark_napi_get_value_bigint_words](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBigint/entry/src/main/ets/pages/Index.ets) -->

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
