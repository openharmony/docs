# Creating and Obtaining String Values Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Introduction

You can use the six string APIs of the JSVM-API to implement the interaction between the JSVM module and JavaScript character strings.

## Basic Concepts

As a common data type in programming, It is used to store and manipulate text data. It can be used to construct user interface elements, such as labels, buttons, and text boxes, process user input, and validate and format data. Different encodings support different character sets and languages. Major encoding schemes include the following:

- ASCII<br>ASCII is one of the earliest character encoding schemes. It uses 7 bits to represent English letters, digits, and some basic symbols. It serves as the foundation for encoding schemes.
- UTF-8<br>UTF-8 is a variable-length encoding scheme that can represent any Unicode character. It uses 8 bits per character and uses byte sequences of different lengths depending on the range of the character. UTF-8 is widely used for web content.
- UTF-16<br>UTF-16 is a fixed-length or variable-length encoding scheme that uses 16 bits per character. It can represent all Unicode characters and is suitable for larger character sets.
- ISO-8859-1 (Latin-1)<br>ISO-8859-1 is a single-byte coding scheme that uses 8 bits per character. It is mainly used to represent Latin alphabet characters and commonly used in European languages.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_GetValueStringUtf8       | Obtains the UTF8-encoded string from a JS string.|
| OH_JSVM_CreateStringUtf8          | Creates a JS string object from a UTF8-encoded C string.|
| OH_JSVM_GetValueStringUtf16      | Obtains the UTF16-encoded string from a JS string.|
| OH_JSVM_CreateStringUtf16         | Creates a JS string object based on a UTF16-encoded string.|
| OH_JSVM_GetValueStringLatin1     | Obtains the ISO-8859-1-encoded string from a JS string.|
| OH_JSVM_CreateStringLatin1        | Creates a JS string object from an ISO-8859-1-encoded C string. ISO-8859-1 is also referred to as Latin-1.|

## Example

For details about the JSVM-API development process, see [Using JSVM-API to Implement Interactive Development Between JS and C/C++](use-jsvm-process.md). This document describes only the C++ code corresponding to the interface.

### OH_JSVM_GetValueStringUtf8

Call **OH_JSVM_GetValueStringUtf8** to convert a JS string into a UTF-8-encoded string.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#include <cstdlib>
// Define OH_JSVM_GetValueStringUtf8.
static JSVM_Value GetValueStringUtf8(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    size_t length = 0;
    JSVM_Status status = OH_JSVM_GetValueStringUtf8(env, args[0], nullptr, 0, &length);
    char *buf = (char *)malloc(length + 1);
    if (buf == nullptr) {
        OH_LOG_ERROR(LOG_APP, "malloc failed");
        return nullptr;
    }
    memset(buf, 0, length + 1);
    status = OH_JSVM_GetValueStringUtf8(env, args[0], buf, length + 1, &length);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueStringUtf8 fail");
        free(buf);
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueStringUtf8 success: %{public}s", buf);
    }
    JSVM_Value result = nullptr;
    OH_JSVM_CreateStringUtf8(env, buf, length, &result);
    free(buf);
    return result;
}
// Register the GetValueStringUtf8 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueStringUtf8},
};
static JSVM_CallbackStruct *method = param;
// Alias for the GetValueStringUtf8 method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueStringUtf8", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char *srcCallNative = R"JS(
    let data = "aaBC+-$%^Hello 123";
    let script = getValueStringUtf8(data);
)JS";
```
<!-- @[oh_jsvm_get_value_string_utf8](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutString/getvaluestringutf8/src/main/cpp/hello.cpp) -->

Expected result:
```cpp
JSVM GetValueStringUtf8 success: aaBC+-$%^Hello 123
```
**NOTE**<br>The call fails if the input parameter **arg** of **getValueStringUtf8()** is not of the string type.

### OH_JSVM_CreateStringUtf8

Call **OH_JSVM_CreateStringUtf8** to create a JS string from a UTF8-encoded C string.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#include <string>
// Define OH_JSVM_CreateStringUtf8.
static JSVM_Value CreateStringUtf8(JSVM_Env env, JSVM_CallbackInfo info)
{
    const char *str = u8"Hello, World!, successes to create UTF-8 string!";
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
// Register the CreateStringUtf8 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateStringUtf8},
};
static JSVM_CallbackStruct *method = param;
// Alias for the CreateStringUtf8 method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createStringUtf8", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char *srcCallNative = R"JS(
    let script = createStringUtf8();
)JS";
```
<!-- @[oh_jsvm_create_string_utf8](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutString/createstringutf8/src/main/cpp/hello.cpp) -->

Expected result:
```cpp
JSVM CreateStringUtf8 success: Hello, World!, successes to create UTF-8 string!
```
### OH_JSVM_GetValueStringUtf16

Call **OH_JSVM_GetValueStringUtf16** to convert a JS string into a UTF-16-encoded string.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#include <codecvt>
#include <locale>
#include <cstdlib>

// Define OH_JSVM_GetValueStringUtf16.
// Set the maximum length of the string buffer.
static const int MAX_BUFFER_SIZE = 128;
static JSVM_Value GetValueStringUtf16(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value result = nullptr;
    size_t length = 0;
    char16_t buffer[MAX_BUFFER_SIZE] = {0};
    // Size of the buffer for storing the string.
    size_t bufferSize = MAX_BUFFER_SIZE;
    JSVM_Status status = OH_JSVM_GetValueStringUtf16(env, args[0], buffer, bufferSize, &length);
    // Convert char16_t to std::u16string.
    std::u16string u16str = {buffer};
    // Convert std::u16string to std::string.
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
    std::string str = converter.to_bytes(u16str);
    // Obtain the string.
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueStringUtf16 fail");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueStringUtf16 success: %{public}s", str.c_str());
    }
    return result;
}
// Register the GetValueStringUtf16 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueStringUtf16},
};
static JSVM_CallbackStruct *method = param;
// Alias for the GetValueStringUtf16 method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueStringUtf16", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char *srcCallNative = R"JS(
    let data = "ahello.";
    let script = getValueStringUtf16(data);
)JS";
```
<!-- @[oh_jsvm_get_value_string_utf16](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutString/getvaluestringutf16/src/main/cpp/hello.cpp) -->

Expected result:
```cpp
JSVM GetValueStringUtf16 success: ahello.
```
**Note**: The `arg` parameter of `getValueStringUtf16(arg)` must be a string. Otherwise, the API fails to be called.

### OH_JSVM_CreateStringUtf16

Call **OH_JSVM_GetValueStringUtf16** to create a JS string from a UTF16-encoded C string.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#include <codecvt>
#include <locale>
#include <cstring>

// Define OH_JSVM_CreateStringUtf16.
static JSVM_Value CreateStringUtf16(JSVM_Env env, JSVM_CallbackInfo info)
{
    const char16_t *str = u"Hello, World!, successes to create UTF-16 string!";
    std::u16string ustr(str);
    size_t length = ustr.length();
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateStringUtf16(env, str, length, &result);
    std::u16string u16str = {str};
    // Convert std::u16string to std::string.
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
    std::string strResult = converter.to_bytes(u16str);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateStringUtf16 fail");
    }else {
        OH_LOG_INFO(LOG_APP, "JSVM CreateStringUtf16 success: %{public}s", strResult.c_str());
    }
    return result;
}
// Register the CreateStringUtf16 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateStringUtf16},
};
static JSVM_CallbackStruct *method = param;
// Alias for the CreateStringUtf16 method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createStringUtf16", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char *srcCallNative = R"JS(
    let script = createStringUtf16();
)JS";
```
<!-- @[oh_jsvm_create_string_utf16](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutString/createstringutf16/src/main/cpp/hello.cpp) -->

Expected result:
```cpp
JSVM CreateStringUtf16 success: Hello, World!, successes to create UTF-16 string!
```
### OH_JSVM_GetValueStringLatin1

Call **OH_JSVM_GetValueStringLatin1** to convert a JS string into an ISO-8859-1-encoded string.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#include <cstdlib>
// Define OH_JSVM_GetValueStringLatin1.
// Set the maximum length of the string buffer.
static const int MAX_BUFFER_SIZE = 128;
static JSVM_Value GetValueStringLatin1(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    char buf[MAX_BUFFER_SIZE];
    size_t length = 0;
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
// Register the GetValueStringLatin1 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueStringLatin1},
};
static JSVM_CallbackStruct *method = param;
// Alias for the GetValueStringLatin1 method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueStringLatin1", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char *srcCallNative = R"JS(
    let data = "中文";
    let script = getValueStringLatin1(data);
)JS";
```
<!-- @[oh_jsvm_get_value_string_latin1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutString/getvaluestringlatin1/src/main/cpp/hello.cpp) -->

Expected result (ISO-8859-1 encoding does not support Chinese characters. If Chinese characters are input, garbled characters will be displayed.):

![GetValueStringLatin1](figures/jsvm_about_string_GetValueStringLatin1.png)

**Note**: The `arg` input parameter must be of the string type. Otherwise, the interface fails to be called.

### OH_JSVM_CreateStringLatin1

Call **OH_JSVM_CreateStringLatin1** to create a JS string from an ISO-8859-1-encoded C string.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#include <cstring>
// Register the CreateStringLatin1 callback.
// Set the maximum length of the string buffer.
static const int MAX_BUFFER_SIZE = 128;
// Define OH_JSVM_CreateStringLatin1.
static JSVM_Value CreateStringLatin1(JSVM_Env env, JSVM_CallbackInfo info)
{
    const char *str = "Hello, World! éçñ, successes to create Latin1 string!";
    size_t length = JSVM_AUTO_LENGTH;
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateStringLatin1(env, str, length, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateStringLatin1 fail");
    } else {
        char buf[MAX_BUFFER_SIZE];
        size_t length = 0;
        OH_JSVM_GetValueStringLatin1(env, result, buf, MAX_BUFFER_SIZE, &length);
        OH_LOG_INFO(LOG_APP, "JSVM CreateStringLatin1 success: %{public}s", buf);
    }
    return result;
}
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateStringLatin1},
};
static JSVM_CallbackStruct *method = param;
// Alias for the CreateStringLatin1 method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createStringLatin1", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char *srcCallNative = R"JS(
    let script = createStringLatin1();
)JS";
```
<!-- @[oh_jsvm_create_string_latin1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutString/createstringlatin1/src/main/cpp/hello.cpp) -->

Expected result:
```cpp
JSVM CreateStringLatin1 success: Hello, World! éçñ, successes to create Latin1 string!
```

<!--no_check-->