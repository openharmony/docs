# 使用Node-API接口创建和获取string值
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello; @yuanyao14; @lzj0614-->
<!--SE: @shilei123-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

## 简介

使用Node-API的六个关于string的接口，可以实现Node-API模块与ArkTS字符串的交互。

## 基本概念

字符串是编程中常用的数据类型，用于存储和操作文本数据。它可以表示和处理字符序列，构建用户界面元素（如标签、按钮和文本框），处理用户输入，验证和格式化数据。不同编码支持的字符集和语言不同，以下是一些主要编码方案及其区别：

- **ASCII**：ASCII是最早的字符编码方案之一，使用7位编码，只能表示英文字母、数字和一些基本符号。它是许多其他编码方案的基础。
- **UTF-8**：UTF-8是一种变长编码方案，可以表示全球范围的字符集。它使用8位编码，根据字符的不同范围使用不同长度的字节序列。UTF-8是互联网上广泛使用的编码方案。
- **UTF-16**：UTF-16是一种定长或变长编码方案，使用16位编码。它可以表示全球范围的字符集，并且适用于较大的字符集。
- **ISO-8859-1（Latin-1）**：ISO-8859-1是一种单字节编码方案，使用8位编码。它主要用于表示拉丁字母字符集，包括欧洲大部分语言。

## 场景和功能介绍

以下Node-API接口主要用于string值的创建和获取，使用场景如下：

| 接口 | 描述 |
| -------- | -------- |
| napi_get_value_string_utf8 | 需要将ArkTS的字符类型的数据转换为utf8编码的字符时使用这个函数。 |
| napi_create_string_utf8 | 需要通过UTF8编码的C字符串创建ArkTS string值时使用这个函数。 |
| napi_get_value_string_utf16 | 需要将ArkTS的字符类型的数据转换为utf16编码的字符时使用这个函数。 |
| napi_create_string_utf16 | 需要通过UTF16编码的C字符串创建ArkTS string值时使用这个函数。 |
| napi_get_value_string_latin1 | 需要将ArkTS的字符类型的数据转换为ISO-8859-1编码的字符时使用这个函数。 |
| napi_create_string_latin1 | 需要通过ISO-8859-1编码的字符串创建ArkTS string值时使用这个函数。 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### napi_get_value_string_utf8

将ArkTS的字符类型的数据转换为UTF-8编码的字符。

cpp部分代码

```cpp
#include "napi/native_api.h"
#include "hilog/log.h"
#include <cstring>

static napi_value GetValueStringUtf8(napi_env env, napi_callback_info info) 
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};

    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 获取字符串的长度
    size_t length = 0;
    napi_status status = napi_get_value_string_utf8(env, args[0], nullptr, 0, &length);
    // 传入一个非字符串 napi_get_value_string_utf8接口会返回napi_string_expected
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "napi_get_value_string_utf8 failed");
        return nullptr;
    }
    char* buf = new char[length + 1];
    std::memset(buf, 0, length + 1);
    status = napi_get_value_string_utf8(env, args[0], buf, length + 1, &length);
    if (status != napi_ok) {
        if (buf) {
            delete[] buf;
        }
        OH_LOG_ERROR(LOG_APP, "napi_get_value_string_utf8 failed");
        return nullptr;
    }
    napi_value result = nullptr;
    status = napi_create_string_utf8(env, buf, length, &result);
    if (buf) {
        delete[] buf;
    }
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_create_string_utf8 failed");
        return nullptr;
    }
    return result;
}
```
<!-- @[napi_get_value_string_utf8](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getValueStringUtf8: (param: string | number) => string | undefined;
```
<!-- @[napi_get_value_string_utf8_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
// 分别传入字符和非字符检测接口，传入字符串类型的数据将返回原字符串，传入其他类型返回undefined
hilog.info(0x0000, 'testTag', 'Test Node-API get_value_string_utf8_string %{public}s', testNapi.getValueStringUtf8('aaBC+-$%^你好123'));
hilog.info(0x0000, 'testTag', 'Test Node-API get_value_string_utf8_not_string %{public}s', testNapi.getValueStringUtf8(50));
```
<!-- @[ark_napi_get_value_string_utf8](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/ets/pages/Index.ets) -->

### napi_create_string_utf8

用于创建一个UTF-8编码的ArkTS字符串。

cpp部分代码

```cpp
#include "napi/native_api.h"
#include <string>

static napi_value CreateStringUtf8(napi_env env, napi_callback_info info) 
{
    const char *str = u8"你好, World!, successes to create UTF-8 string! 111";
    size_t length = strlen(str);                                        
    napi_value result = nullptr;
    napi_status status = napi_create_string_utf8(env, str, length, &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to create UTF-8 string");
        return nullptr;
    }
    return result;
}
```
<!-- @[napi_create_string_utf8](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const createStringUtf8: () => string | undefined;
```
<!-- @[napi_create_string_utf8_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_string_utf8:%{public}s', testNapi.createStringUtf8());
```
<!-- @[ark_napi_create_string_utf8](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/ets/pages/Index.ets) -->

### napi_get_value_string_utf16

将ArkTS的字符类型的数据转换为UTF-16编码的字符。

cpp部分代码

```cpp
#include "napi/native_api.h"

// 定义字符串缓冲区的最大长度
static const int MAX_BUFFER_SIZE = 128;

static napi_value GetValueStringUtf16(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    napi_value result = nullptr;
    // 字符串的缓冲区
    char16_t buffer[MAX_BUFFER_SIZE];
    // 字符串的缓冲区大小
    size_t bufferSize = MAX_BUFFER_SIZE;
    // 字符串的长度
    size_t stringLen;
    // 获取字符串的数据和长度
    napi_get_value_string_utf16(env, args[0], buffer, bufferSize, &stringLen);
    // 获取字符串返回结果
    napi_create_string_utf16(env, buffer, stringLen, &result);
    // 返回结果
    return result; 
}
```
<!-- @[napi_get_value_string_utf16](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getValueStringUtf16: (data: string) => string;
```
<!-- @[napi_get_value_string_utf16_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let result = testNapi.getValueStringUtf16('hello,');
hilog.info(0x0000,'testTag','Node-API napi_get_value_string_utf16:%{public}s', result);
```
<!-- @[ark_napi_get_value_string_utf16](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/ets/pages/Index.ets) -->

### napi_create_string_utf16

创建一个UTF-16编码的ArkTS字符串。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateStringUtf16(napi_env env, napi_callback_info info)
{
    const char16_t  *str = u"你好, World!, successes to create UTF-16 string! 111";
    size_t length = NAPI_AUTO_LENGTH;
    napi_value result = nullptr;
    napi_status status = napi_create_string_utf16(env, str, length, &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to create UTF-16 string");
        return nullptr;
    }
    return result;
}
```
<!-- @[napi_create_string_utf16](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const createStringUtf16: () => string | undefined;
```
<!-- @[napi_create_string_utf16_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_string_utf16:%{public}s ', testNapi.createStringUtf16());
```
<!-- @[ark_napi_create_string_utf16](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/ets/pages/Index.ets) -->

### napi_get_value_string_latin1

将ArkTS的字符类型数据转换为ISO-8859-1编码。

cpp部分代码

```cpp
#include "napi/native_api.h"

static const int MAX_BUFFER_SIZE = 128;

static napi_value GetValueStringLatin1(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    char buf[MAX_BUFFER_SIZE];
    size_t length = 0;
    napi_value napi_Res = nullptr;
    napi_status status = napi_get_value_string_latin1(env, args[0], buf, MAX_BUFFER_SIZE, &length);
    // 当输入的值不是字符串时，接口会返回napi_string_expected
    if (status != napi_ok) {
        return nullptr;
    }
    napi_create_string_latin1(env, buf, length, &napi_Res);
    return napi_Res;
}
```
<!-- @[napi_get_value_string_latin1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getValueStringLatin1: (param: number | string) => string | undefined;
```
<!-- @[napi_get_value_string_latin1_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
// 传入非字符型数据，函数返回undefined
hilog.info(0x0000, 'testTag', 'Test Node-API get_value_string_latin1_not_string %{public}s', testNapi.getValueStringLatin1(10));
// ISO-8859-1编码不支持中文，传入中文字符会乱码
hilog.info(0x0000, 'testTag', 'Test Node-API get_value_string_latin1_string_chinese %{public}s', testNapi.getValueStringLatin1('中文'));
// 传入其他字符，不会乱码
hilog.info(0x0000, 'testTag', 'Test Node-API get_value_string_latin1_string %{public}s', testNapi.getValueStringLatin1('abo ABP=-&*/'));
```
<!-- @[ark_napi_get_value_string_latin1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/ets/pages/Index.ets) -->

### napi_create_string_latin1

创建一个Latin1编码的ArkTS字符串。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateStringLatin1(napi_env env, napi_callback_info info)
{
    const char *str = "Hello, World! éçñ, successes to create Latin1 string! 111";
    size_t length = NAPI_AUTO_LENGTH;
    napi_value result = nullptr;
    napi_status status = napi_create_string_latin1(env, str, length, &result);
    if (status != napi_ok) {
        // 处理错误
        napi_throw_error(env, nullptr, "Failed to create Latin1 string");
        return nullptr;
    }
    return result;
}
```
<!-- @[napi_create_string_latin1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const createStringLatin1: () => string | undefined;
```
<!-- @[napi_create_string_latin1_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag', 'Test Node-API  napi_create_string_latin1:%{public}s', testNapi.createStringLatin1());
```
<!-- @[ark_napi_create_string_latin1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/ets/pages/Index.ets) -->

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
