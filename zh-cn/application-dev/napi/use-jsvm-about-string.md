# 使用JSVM-API接口创建和获取string值

## 简介

使用JSVM-API关于string的六个接口，可以让JSVM模块和JavaScript字符串进行交互。

## 基本概念

string是编程中常用的数据类型之一。它可以存储和操作文本数据，用于表示和处理字符序列。还可用于构建用户界面元素，如标签、按钮和文本框，处理用户输入，验证和格式化输入数据。不同的编码支持不同的字符集和语言，以下是一些主要的编码方案及其区别：

- **ASCII**：ASCII是最早的字符编码方案之一，使用7位编码，只能表示英文字母、数字和一些基本符号。它是许多其他编码方案的基础。
- **UTF-8**：UTF-8是一种变长编码方案，可以表示全球范围的字符集。它使用8位编码，根据字符的不同范围使用不同长度的字节序列。UTF-8是互联网上广泛使用的编码方案。
- **UTF-16**：UTF-16是一种定长或变长编码方案，使用16位编码。它可以表示全球范围的字符集，并且适用于较大的字符集。
- **ISO-8859-1（Latin-1）**：ISO-8859-1是一种单字节编码方案，使用8位编码。它主要用于表示拉丁字母字符集，包括欧洲大部分语言。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_GetValueStringUtf8       | 获取给定JavaScript string对象的Utf8编码字符串。|
| OH_JSVM_CreateStringUtf8          | 根据Utf8编码的字符串创建一个JavaScript string对象。|
| OH_JSVM_GetValueStringUtf16      | 获取给定JavaScript string对象的Utf16编码字符串|
| OH_JSVM_CreateStringUtf16         | 通过UTF16编码的C字符串数据创建JS String。|
| OH_JSVM_GetValueStringLatin1     | 获取给定JavaScript string对象的Latin1编码字符串|
| OH_JSVM_CreateStringLatin1        | 根据Latin-1编码的字符串创建一个JavaScript string对象。|

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### OH_JSVM_GetValueStringUtf8

OH_JSVM_GetValueStringUtf8接口可以将JavaScript的字符类型的数据转换为utf8编码的字符。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// GetValueStringUtf8注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueStringUtf8},
};
static JSVM_CallbackStruct *method = param;
// GetValueStringUtf8方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueStringUtf8", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_GetValueStringUtf8的样例方法
static JSVM_Value GetValueStringUtf8(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    size_t length = 0;
    JSVM_Status status = OH_JSVM_GetValueStringUtf8(env, args[0], nullptr, 0, &length);
    char *buf = (char *)malloc(length + 1);
    status = OH_JSVM_GetValueStringUtf8(env, args[0], buf, length + 1, &length);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueStringUtf8 fail");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueStringUtf8 success: %{public}s", buf);
    }
    JSVM_Value result = nullptr;
    OH_JSVM_CreateStringUtf8(env, buf, length, &result);
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
try {
  let data = `"aaBC+-$%^你好123"`;
  let script: string = `getValueStringUtf8(${data})`;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getValueStringUtf8: %{public}s', napitest.runJsVm(script));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getValueStringUtf8 error: %{public}s', error.message);
}
try {
  let script: string = `getValueStringUtf8(50)`;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getValueStringUtf8: %{public}s', napitest.runJsVm(script));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getValueStringUtf8 error: %{public}s', error.message);
}
```

### OH_JSVM_CreateStringUtf8

用于创建一个UTF-8编码的JavaScript字符串。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// CreateStringUtf8注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateStringUtf8},
};
static JSVM_CallbackStruct *method = param;
// CreateStringUtf8方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createStringUtf8", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_CreateStringUtf8的样例方法
static JSVM_Value CreateStringUtf8(JSVM_Env env, JSVM_CallbackInfo info)
{
    const char *str = u8"你好, World!, successes to create UTF-8 string!";
    size_t length = strlen(str);
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateStringUtf8(env, str, length, &result);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "Failed to create UTF-8 string");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM CreateStringUtf8 success: %{public}s", str);
    }
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
try {
  let script: string = `createStringUtf8()`;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createStringUtf8: %{public}s', napitest.runJsVm(script));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createStringUtf8 error: %{public}s', error.message);
}
```

### OH_JSVM_GetValueStringUtf16

OH_JSVM_GetValueStringUtf16，将JavaScript的字符类型的数据转换为utf16编码的字符。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#include <codecvt>
#include <locale>

// GetValueStringUtf16注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueStringUtf16},
};
static JSVM_CallbackStruct *method = param;
// GetValueStringUtf16方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueStringUtf16", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_GetValueStringUtf16的样例方法
// 定义字符串缓冲区的最大长度
static const int MAX_BUFFER_SIZE = 128;
static JSVM_Value GetValueStringUtf16(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value result = nullptr;
    size_t length = 0;
    char16_t buffer[MAX_BUFFER_SIZE] = {0};
    // 字符串的缓冲区大小
    size_t bufferSize = MAX_BUFFER_SIZE;
    JSVM_Status status = OH_JSVM_GetValueStringUtf16(env, args[0], buffer, bufferSize, &length);
    // 将 char16_t 转换为 std::u16string
    std::u16string u16str = {buffer};
    // 将 std::u16string 转换为 std::string
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
    std::string str = converter.to_bytes(u16str);
    // 获取字符串返回结果
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueStringUtf16 fail");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueStringUtf16 success: %{public}s", str.c_str());
    }
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
try {
  let data = `"ahello。"`;
  let script: string = `getValueStringUtf16(${data})`;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getValueStringUtf16: %{public}s', napitest.runJsVm(script));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getValueStringUtf16 error: %{public}s', error.message);
}
try {
  let script: string = `getValueStringUtf16(50)`;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getValueStringUtf16: %{public}s', napitest.runJsVm(script));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getValueStringUtf16 error: %{public}s', error.message);
}
```

### OH_JSVM_CreateStringUtf16

用于创建一个UTF-16编码的JavaScript字符串。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#include <codecvt>
#include <locale>

// CreateStringUtf16注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateStringUtf16},
};
static JSVM_CallbackStruct *method = param;
// CreateStringUtf16方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createStringUtf16", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_CreateStringUtf16的样例方法
static JSVM_Value CreateStringUtf16(JSVM_Env env, JSVM_CallbackInfo info)
{
    const char16_t *str = u"你好, World!, successes to create UTF-16 string!";
    std::u16string ustr(str);
    size_t length = ustr.length();
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateStringUtf16(env, str, length, &result);
    std::u16string u16str = {str};
    // 将 std::u16string 转换为 std::string
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
    std::string strResult = converter.to_bytes(u16str);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateStringUtf16 fail");
    }else {
        OH_LOG_INFO(LOG_APP, "JSVM CreateStringUtf16 success: %{public}s", strResult.c_str());
    }
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
try {
  let script: string = `
        createStringUtf16()
  `;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createStringUtf16: %{public}s', napitest.runJsVm(script));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createStringUtf16 error: %{public}s', error.message);
}
```

### OH_JSVM_GetValueStringLatin1

OH_JSVM_GetValueStringLatin1接口可以将JavaScript的字符类型的数据转换为ISO-8859-1编码的字符。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// GetValueStringLatin1注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueStringLatin1},
};
static JSVM_CallbackStruct *method = param;
// GetValueStringLatin1方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueStringLatin1", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_GetValueStringLatin1的样例方法
// 定义字符串缓冲区的最大长度
static const int MAX_BUFFER_SIZE = 128;
static JSVM_Value GetValueStringLatin1(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    char buf[MAX_BUFFER_SIZE];
    size_t length;
    JSVM_Value jsvmRes = nullptr;
    JSVM_Status status = OH_JSVM_GetValueStringLatin1(env, args[0], buf, MAX_BUFFER_SIZE, &length);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueStringLatin1 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueStringLatin1 success: %{public}s", buf);
    }
    OH_JSVM_CreateStringLatin1(env, buf, length, &jsvmRes);
    return jsvmRes;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
try {
  // ISO-8859-1编码不支持中文，传入中文字符会乱码
  let data = `"中文"`;
  let script: string = `getValueStringLatin1(${data})`;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getValueStringLatin1: %{public}s', napitest.runJsVm(script));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getValueStringLatin1 error: %{public}s', error.message);
}
try {
  // 传入非字符型数据，函数返回undefined
  let script: string = `getValueStringLatin1(10)`;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getValueStringLatin1: %{public}s', napitest.runJsVm(script));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getValueStringLatin1 error: %{public}s', error.message);
}
try {
  // 传入其他字符，不会乱码
  let data = `"abo ABP=-&*/"`;
  let script: string = `getValueStringLatin1(${data})`;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getValueStringLatin1: %{public}s', napitest.runJsVm(script));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getValueStringLatin1 error: %{public}s', error.message);
}
```

### OH_JSVM_CreateStringLatin1

用于创建一个Latin1编码的JavaScript字符串。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// CreateStringLatin1注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateStringLatin1},
};
static JSVM_CallbackStruct *method = param;
// CreateStringLatin1方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createStringLatin1", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 定义字符串缓冲区的最大长度
static const int MAX_BUFFER_SIZE = 128;
// OH_JSVM_CreateStringLatin1的样例方法
static JSVM_Value CreateStringLatin1(JSVM_Env env, JSVM_CallbackInfo info)
{
    const char *str = "Hello, World! éçñ, successes to create Latin1 string! 111";
    size_t length = JSVM_AUTO_LENGTH;
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateStringLatin1(env, str, length, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateStringLatin1 fail");
    } else {
        char buf[MAX_BUFFER_SIZE];
        size_t length;
        OH_JSVM_GetValueStringLatin1(env, result, buf, MAX_BUFFER_SIZE, &length);
        OH_LOG_INFO(LOG_APP, "JSVM CreateStringLatin1 success: %{public}s", buf);
    }
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
try {
  let script: string = `createStringLatin1()`;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createStringLatin1: %{public}s', napitest.runJsVm(script));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createStringLatin1 error: %{public}s', error.message);
}
```
