# Working with String Using Node-API

## Introduction

This topic walks you through on how to use Node-API to convert data between native strings and ArkTS strings.

## Basic Concepts

As a common data type in programming, string is a sequence of characters used to represent text. It can also be used to build user interface (UI) elements such as labels, buttons, and text boxes, process user input, and validate and format input data. Different encodings support different character sets and languages. Major encoding schemes include the following:

- ASCII<br>ASCII is one of the earliest character encoding schemes. It uses 7 bits to represent English letters, digits, and some basic symbols. It serves as the foundation for encoding schemes.
- UTF-8<br>UTF-8 is a variable-length encoding scheme that can represent any Unicode character. It uses 8 bits per character and uses byte sequences of different lengths depending on the range of the character. UTF-8 is widely used for web content.
- UTF-16<br>UTF-16 is a fixed-length or variable-length encoding scheme that uses 16 bits per character. It can represent all Unicode characters and is suitable for larger character sets.
- ISO-8859-1 (Latin-1)<br>ISO-8859-1 is a single-byte coding scheme that uses 8 bits per character. It is mainly used to represent Latin alphabet characters and commonly used in European languages.

## Available APIs

The following table lists the APIs provided by the Node-API module for creating and obtaining strings.
| API| Description|
| -------- | -------- |
| napi_get_value_string_utf8 | Obtains a UTF8-encoded string from an ArkTS value.|
| napi_create_string_utf8 | Creates an ArkTS string from a UTF8-encoded C string.|
| napi_get_value_string_utf16 | Obtains a UTF16-encoded string from an ArkTS value.|
| napi_create_string_utf16 | Creates an ArkTS string from a UTF16-encoded C string.|
| napi_get_value_string_latin1 | Obtains an ISO-8859-1-encoded string from an ArkTS value.|
| napi_create_string_latin1 | Creates an ArkTS string from an ISO-8859-1-encoded tring.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code involved in the string-related APIs.

### napi_get_value_string_utf8

Use **napi_get_value_string_utf8** to convert an ArkTS string to a UTF-8-encoded string.

CPP code:

```cpp
#include "napi/native_api.h"
#include <string>

static napi_value GetValueStringUtf8(napi_env env, napi_callback_info info) 
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};

    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    std::string buf;
    size_t length = 0;
    napi_status status = napi_get_value_string_utf8(env, args[0], (char*)buf.c_str(), NAPI_AUTO_LENGTH, &length);
    // napi_string_expected will be returned for non-string inputs.
    if (status == napi_string_expected) {
        return nullptr;
    }
    napi_value result;
    napi_create_string_utf8(env, buf.c_str(), length, &result);
    return result;
}
```

API declaration:

```ts
// index.d.ts
export const getValueStringUtf8: (param: string | number) => string | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
// Pass in a string and a number respectively. If the input is a string, the string will be returned. If the input is not a string, 'undefined' will be returned.
hilog.info(0x0000, 'testTag','Test Node-API get_value_string_utf8_string %{public}s', testNapi.getValueStringUtf8 ('aaBC+-$%^Hello 123');
hilog.info(0x0000, 'testTag', 'Test Node-API get_value_string_utf8_not_string %{public}s', testNapi.getValueStringUtf8(50));
```

### napi_create_string_utf8

Use **napi_create_string_utf8** to create an ArkTS string from a UTF8-encoded C string.

CPP code:

```cpp
#include "napi/native_api.h"
#include <string>

static napi_value CreateStringUtf8(napi_env env, napi_callback_info info) 
{
    const char *str = u8"Hello, World!, successes to create UTF-8 string! 111";
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

API declaration:

```ts
// index.d.ts
export const createStringUtf8: () => string | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_string_utf8:%{public}s', testNapi.createStringUtf8());
```

### napi_get_value_string_utf16

Use **napi_get_value_string_utf16** to convert an ArkTS string to a UTF-16-encoded string.

CPP code:

```cpp
#include "napi/native_api.h"

// Set the maximum length of the string buffer.
static const int MAX_BUFFER_SIZE = 128;

static napi_value GetValueStringUtf16(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    napi_value result = nullptr;
    // Buffer of the string.
    char16_t buffer[MAX_BUFFER_SIZE];
    // Size of the buffer for storing the string.
    size_t bufferSize = MAX_BUFFER_SIZE;
    // Length of the string.
    size_t stringLen;
    // Obtain the value and length of the string.
    napi_get_value_string_utf16(env, args[0], buffer, bufferSize, &stringLen);
    // Obtain the string.
    napi_create_string_utf16(env, buffer, stringLen, &result);
    // Return the result.
    return result; 
}
```

API declaration:

```ts
// index.d.ts
export const getValueStringUtf16: (data: string) => string;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let result = testNapi.getValueStringUtf16('hello,');
hilog.info(0x0000,'testTag','Node-API napi_get_value_string_utf16:%{public}s', result);
```

### napi_create_string_utf16

Use **napi_create_string_utf16** to create an ArkTS string from a UTF16-encoded C string.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CreateStringUtf16(napi_env env, napi_callback_info info)
{
    const char16_t *str = u"Hello, World!, successes to create UTF-16 string! 111";
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

API declaration:

```ts
// index.d.ts
export const createStringUtf16: () => string | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_string_utf16:%{public}s ', testNapi.createStringUtf16());
```

### napi_get_value_string_latin1

Use **napi_get_value_string_latin1** to convert an ArkTS string into an ISO-8859-1-encoded string.

CPP code:

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
    // If the value passed in is not a string, napi_string_expected will be returned.
    if (status == napi_string_expected) {
        return nullptr;
    }
    napi_create_string_latin1(env, buf, length, &napi_Res);
    return napi_Res;
}
```

API declaration:

```ts
// index.d.ts
export const getValueStringLatin1: (param: number | string) => string | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
// If non-character data is passed in, undefined will be returned.
hilog.info(0x0000, 'testTag', 'Test Node-API get_value_string_latin1_not_string %{public}s', testNapi.getValueStringLatin1(10));
// The ISO-8859-1 encoding does not support Chinese characters. If Chinese characters are passed in, garbled characters will be displayed.
hilog.info(0x0000, 'testTag','Test Node-API get_value_string_latin1_string_chinese %{public}s', testNapi.getValueStringLatin1 ('中文'));
// Passing in characters of other languages will not cause garbled characters.
hilog.info(0x0000, 'testTag', 'Test Node-API get_value_string_latin1_string %{public}s', testNapi.getValueStringLatin1('abo ABP=-&*/'));
```

### napi_create_string_latin1

Use **napi_create_string_latin1** to create an ArkTS string from an ISO-8859-1-encoded C string.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CreateStringLatin1(napi_env env, napi_callback_info info)
{
    const char *str = "Hello, World! éçñ, successes to create Latin1 string! 111";
    size_t length = NAPI_AUTO_LENGTH;
    napi_value result = nullptr;
    napi_status status = napi_create_string_latin1(env, str, length, &result);
    if (status != napi_ok) {
        // Error handling.
        napi_throw_error(env, nullptr, "Failed to create Latin1 string");
        return nullptr;
    }
    return result;
}
```

API declaration:

```ts
// index.d.ts
export const createStringLatin1: () => string | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

hilog.info(0x0000, 'testTag', 'Test Node-API  napi_create_string_latin1:%{public}s', testNapi.createStringLatin1());
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
<!--no_check-->