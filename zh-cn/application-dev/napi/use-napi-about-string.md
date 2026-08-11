# 使用Node-API接口创建和获取string值
<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

## 简介

使用Node-API的八个关于string的接口，可以实现Node-API模块与ArkTS字符串的交互。

## 基本概念

字符串是编程中常用的数据类型，用于存储和操作文本数据。它可以表示和处理字符序列，构建用户界面元素（如标签、按钮和文本框），处理用户输入，验证和格式化数据。不同编码支持的字符集和语言不同，以下是一些主要编码方案及其区别：

- **ASCII**：ASCII是最早的字符编码方案之一，使用7位编码，只能表示英文字母、数字和一些基本符号。它是许多其他编码方案的基础。
- **UTF-8**：UTF-8是一种变长编码方案，可以表示全球范围的字符集。它使用8位编码，根据字符的不同范围使用不同长度的字节序列。UTF-8是互联网上广泛使用的编码方案。
- **UTF-16**：UTF-16是一种定长或变长编码方案，使用16位编码。它可以表示全球范围的字符集，并且适用于较大的字符集。
- **ISO-8859-1（Latin-1）**：ISO-8859-1是一种单字节编码方案，使用8位编码。它主要用于表示拉丁字母字符集，包括欧洲大部分语言。

## 场景和功能介绍

以下Node-API接口主要用于string值的创建和获取，使用场景如下：

| 接口 | 描述 | 起始支持版本 |
| -------- | -------- | -------- |
| napi_get_value_string_utf8 | 需要将ArkTS的字符类型的数据转换为UTF-8编码的字符时使用这个函数。 | 10 |
| napi_create_string_utf8 | 需要通过UTF-8编码的C字符串创建ArkTS string值时使用这个函数。 | 10 |
| napi_get_value_string_utf16 | 需要将ArkTS的字符类型的数据转换为UTF-16编码的字符时使用这个函数。 | 10 |
| napi_create_string_utf16 | 需要通过UTF-16编码的C字符串创建ArkTS string值时使用这个函数。 | 10 |
| napi_get_value_string_latin1 | 需要将ArkTS的字符类型的数据转换为ISO-8859-1编码的字符时使用这个函数。 | 10 |
| napi_create_string_latin1 | 需要通过ISO-8859-1编码的字符串创建ArkTS string值时使用这个函数。 | 10 |
| napi_create_external_string_utf16 | 需要通过外部UTF-16编码的字符串缓冲区创建ArkTS字符串值且避免内存拷贝时使用此函数。 | 22 |
| napi_create_external_string_ascii | 需要通过外部ASCII编码的字符串缓冲区创建ArkTS字符串值且避免内存拷贝时使用此函数。 | 22 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### napi_get_value_string_utf8

将ArkTS的字符类型的数据转换为UTF-8编码的字符。

cpp部分代码

<!-- @[napi_get_value_string_utf8](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/napi_init.cpp) -->

``` C++
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
    char *buf = new char[length + 1];
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

接口声明

<!-- @[napi_get_value_string_utf8_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const getValueStringUtf8: (param: string | number) => string | undefined;
```

ArkTS侧示例代码

<!-- @[ark_napi_get_value_string_utf8](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// 分别传入字符和非字符检测接口，传入字符串类型的数据将返回原字符串，传入其他类型返回undefined
hilog.info(0x0000, 'testTag', 'Test Node-API get_value_string_utf8_string %{public}s',
  testNapi.getValueStringUtf8('aaBC+-$%^你好123'));
hilog.info(0x0000, 'testTag', 'Test Node-API get_value_string_utf8_not_string %{public}s',
  testNapi.getValueStringUtf8(50));
```

### napi_create_string_utf8

用于创建一个UTF-8编码的ArkTS字符串。

cpp部分代码

<!-- @[napi_create_string_utf8](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/napi_init.cpp) -->

``` C++
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

接口声明

<!-- @[napi_create_string_utf8_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createStringUtf8: () => string | undefined;
```

ArkTS侧示例代码

<!-- @[ark_napi_create_string_utf8](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_string_utf8:%{public}s',
  testNapi.createStringUtf8());
```

### napi_get_value_string_utf16

将ArkTS的字符类型的数据转换为UTF-16编码的字符。

cpp部分代码

<!-- @[napi_get_value_string_utf16](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/napi_init.cpp) -->

``` C++
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

接口声明

<!-- @[napi_get_value_string_utf16_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const getValueStringUtf16: (data: string) => string;
```

ArkTS侧示例代码

<!-- @[ark_napi_get_value_string_utf16](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
let result = testNapi.getValueStringUtf16('hello,');
hilog.info(0x0000, 'testTag', 'Node-API napi_get_value_string_utf16:%{public}s', result);
```

### napi_create_string_utf16

创建一个UTF-16编码的ArkTS字符串。

cpp部分代码

<!-- @[napi_create_string_utf16](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/napi_init.cpp) -->

``` C++
static napi_value CreateStringUtf16(napi_env env, napi_callback_info info)
{
    const char16_t *str = u"你好, World!, successes to create UTF-16 string! 111";
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

接口声明

<!-- @[napi_create_string_utf16_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createStringUtf16: () => string | undefined;
```

ArkTS侧示例代码

<!-- @[ark_napi_create_string_utf16](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_string_utf16:%{public}s ',
  testNapi.createStringUtf16());
```

### napi_get_value_string_latin1

将ArkTS的字符类型数据转换为ISO-8859-1编码。

cpp部分代码

<!-- @[napi_get_value_string_latin1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/napi_init.cpp) -->

``` C++
static napi_value GetValueStringLatin1(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
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

接口声明

<!-- @[napi_get_value_string_latin1_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const getValueStringLatin1: (param: number | string) => string | undefined;
```

ArkTS侧示例代码

<!-- @[ark_napi_get_value_string_latin1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// 传入非字符型数据，函数返回undefined
hilog.info(0x0000, 'testTag', 'Test Node-API get_value_string_latin1_not_string %{public}s',
  testNapi.getValueStringLatin1(10));
// ISO-8859-1编码不支持中文，传入中文字符会乱码
hilog.info(0x0000, 'testTag', 'Test Node-API get_value_string_latin1_string_chinese %{public}s',
  testNapi.getValueStringLatin1('中文'));
// 传入其他字符，不会乱码
hilog.info(0x0000, 'testTag', 'Test Node-API get_value_string_latin1_string %{public}s',
  testNapi.getValueStringLatin1('abo ABP=-&*/'));
```

### napi_create_string_latin1

创建一个Latin-1编码的ArkTS字符串。

cpp部分代码

<!-- @[napi_create_string_latin1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/napi_init.cpp) -->

``` C++
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

接口声明

<!-- @[napi_create_string_latin1_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createStringLatin1: () => string | undefined;
```

ArkTS侧示例代码

<!-- @[ark_napi_create_string_latin1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
hilog.info(0x0000, 'testTag', 'Test Node-API  napi_create_string_latin1:%{public}s',
  testNapi.createStringLatin1());
```

### napi_create_external_string_utf16

创建一个引用外部资源的UTF-16编码的ArkTS字符串。

cpp部分代码

<!-- @[napi_create_external_string_utf16](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/napi_init.cpp) --> 

``` C++
// 定义字符串的析构回调函数，如果需要释放外部资源，可以在该函数中实现
// hint参数可以传递一些额外的信息，如引用计数等，也可以忽略此参数，直接传入nullptr
static void StringFinalizerUTF16(void* data, void* hint)
{
    // 释放外部资源
    delete[] static_cast<char16_t*>(data);
    // 重要：析构回调执行的时候会挂起其它js线程，因此需要保证回调执行过程中无锁操作，否则可能导致死锁。
    // 由于回调是在其它非注册线程执行，因此需要保证回调是线程安全的。
}

static napi_value CreateExternalStringUtf16(napi_env env, napi_callback_info info)
{
    const char16_t source[] = u"你好, World!, successes to create UTF-16 string! 111";
    napi_value result = nullptr;
    int char16tLength = sizeof(source) / sizeof(char16_t);
    // 在堆上动态分配内存，并复制字符串内容
    char16_t* str = new char16_t[char16tLength];
    std::copy(source, source + char16tLength, str);
    // 当创建出来的字符串在ArkTS侧生命周期结束被GC回收时，会调用StringFinalizerUTF16函数，调用方式为StringFinalizerUTF16(str, finalize_hint);
    // 如果finalize_callback传入nullptr，则不会调用任何回调函数。开发者需要自行管理外部资源str的生命周期。
    napi_status status = napi_create_external_string_utf16(
        env,
        str,                    // 外部字符串缓冲区
        NAPI_AUTO_LENGTH,       // 字符串长度，如果传入NAPI_AUTO_LENGTH，则字符串需要以'\0'结尾
        StringFinalizerUTF16,   // 字符串的析构回调函数
        nullptr,                // 传递给析构回调函数的hint参数，本例不需要
        &result);               // 接收创建的ArkTS字符串值
    // 重要：str指向的内存必须在ArkTS string对象的整个生命周期内保持有效。
    // 而且在调用此接口后，str指向的内存内容必须保持不可变。任何对该内存的写入操作都可能导致程序崩溃。
    if (status != napi_ok) {
        // 处理错误
        delete[] str;
        napi_throw_error(env, nullptr, "Failed to create utf16 string");
        return nullptr;
    }
    return result;
}
```

接口声明

<!-- @[napi_create_external_string_utf16_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const CreateExternalStringUtf16: () => string | undefined;
```

ArkTS侧示例代码

<!-- @[ark_napi_create_external_string_utf16](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
hilog.info(0x0000, 'testTag', 'Test Node-API  napi_create_external_string_utf16:%{public}s',
  testNapi.CreateExternalStringUtf16());
```
通过napi_create_external_string_utf16接口创建出的ArkTS string对象受GC管理，其生命周期结束，GC会回收ArkTS string对象，同时触发StringFinalizerUTF16函数来回收ArkTS string对象指向的native侧资源。

### napi_create_external_string_ascii

创建一个引用外部资源的ASCII编码的ArkTS字符串。

cpp部分代码

<!-- @[napi_create_external_string_ascii](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// 定义字符串的析构回调函数，如果需要释放外部资源，可以在该函数中实现
// hint参数可以传递一些额外的信息，如引用计数等，也可以忽略此参数，直接传入nullptr
static void StringFinalizerASCII(void* data, void* hint)
{
    // 释放外部资源
    delete[] static_cast<char*>(data);
    // 重要：析构回调执行的时候会挂起其它js线程，因此需要保证回调执行过程中无锁操作，否则可能导致死锁。
    // 由于回调是在其它非注册线程执行，因此需要保证回调是线程安全的。
}

static napi_value CreateExternalStringAscii(napi_env env, napi_callback_info info)
{
    const char source[] = "hello, World!, successes to create ASCII string! 111";
    napi_value result = nullptr;
    int charLength = sizeof(source) / sizeof(char);
    // 在堆上动态分配内存，并复制字符串内容
    char* str = new char[charLength];
    std::copy(source, source + charLength, str);
    // 当创建出来的字符串在ArkTS侧生命周期结束被GC回收时，会调用StringFinalizerASCII函数，调用方式为StringFinalizerASCII(str, finalize_hint);
    // 如果finalize_callback传入nullptr，则不会调用任何回调函数。开发者需要自行管理外部资源str的生命周期。
    // napi_create_external_string_ascii 接口要求传入的字符串在指定的长度范围内不得包含'\0'字符，否则可能导致异常行为。
    napi_status status = napi_create_external_string_ascii(
        env,
        str,                    // 外部字符串缓冲区
        NAPI_AUTO_LENGTH,       // 字符串长度，如果传入NAPI_AUTO_LENGTH，则字符串需要以'\0'结尾
        StringFinalizerASCII,   // 字符串的析构回调函数
        nullptr,                // 传递给析构回调函数的hint参数，本例不需要
        &result);               // 接收创建的ArkTS字符串值
    // 重要：str指向的内存必须在ArkTS string对象的整个生命周期内保持有效。
    // 而且在调用此接口后，str指向的内存内容必须保持不可变。任何对该内存的写入操作都可能导致程序崩溃。
    if (status != napi_ok) {
        // 处理错误
        delete[] str;
        napi_throw_error(env, nullptr, "Failed to create ascii string");
        return nullptr;
    }
    return result;
}
```

接口声明

<!-- @[napi_create_external_string_ascii_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const CreateExternalStringAscii: () => string | undefined;
```

ArkTS侧示例代码

<!-- @[ark_napi_create_external_string_ascii](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIString/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
hilog.info(0x0000, 'testTag', 'Test Node-API  napi_create_external_string_ascii:%{public}s',
  testNapi.CreateExternalStringAscii());
```
通过napi_create_external_string_ascii接口创建出的ArkTS string对象受GC管理，其生命周期结束，GC会回收ArkTS string对象，同时触发StringFinalizerASCII函数来回收ArkTS string对象指向的native侧资源。

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
