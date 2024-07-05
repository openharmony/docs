# Creating and Obtaining String Values Using Node-API

## Overview

Use Node-API to convert data between native strings and JavaScript (JS) strings.

## Basic Concepts

As one of the common data types in programming, a string is a sequence of characters used to represent text. It can also be used to build user interface (UI) elements such as labels, buttons, and text boxes, process user input, and validate and format input data. Different encodings support different character sets and languages. Major encoding schemes include the following:

- **ASCII**: ASCII is one of the earliest character encoding schemes. It uses 7 bits to represent English letters, digits, and some basic symbols. It serves as the foundation for encoding schemes.
- **UTF-8**: UTF-8 is a variable-length encoding scheme that can represent any Unicode character. It uses 8 bits per character and uses byte sequences of different lengths depending on the range of the character. UTF-8 is widely used for web content.
- **UTF-16**: UTF-16 is a fixed-length or variable-length encoding scheme that uses 16 bits per character. It can represent all Unicode characters and is suitable for larger character sets.
- **ISO-8859-1 (Latin-1)**: ISO-8859-1 is a single-byte coding scheme that uses 8 bits per character. It is mainly used to represent Latin alphabet characters and commonly used in European languages.

## Available APIs

You can use the following APIs to create and obtain string values.
| API| Description|
| -------- | -------- |
| napi_get_value_string_utf8 | Converts a JS string into a UTF-8 encoded string.|
| napi_create_string_utf8 | Creates a JS string from a UTF8-encoded C string.|
| napi_get_value_string_utf16 | Converts a JS string into a UTF-16-encoded string.|
| napi_create_string_utf16 | Creates a JS string from a UTF16-encoded C string.|
| napi_get_value_string_latin1 | Converts a JS string into an ISO-8859-1-encoded string.|
| napi_create_string_latin1 | Creates a JS string from an ISO-8859-1-encoded C string.|

## Example

### napi_get_value_string_utf8

Use **napi_get_value_string_utf8** to convert a JS string into a UTF-8-encoded string.

CPP code

```cpp
static napi_value GetValueStringUtf8(napi_env env, napi_callback_info info) 
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};

    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    std::string buf;
    size_t length = 0;
    napi_status status = napi_get_value_string_utf8(env, args[0], (char*)buf.c_str(), NAPI_AUTO_LENGTH, &length);
    // If a non-character string is passed in, napi_get_value_string_utf8 returns napi_string_expected.
    if (status == napi_string_expected) {
        return nullptr;
    }
    napi_value result;
    napi_create_string_utf8(env, buf.c_str(), length, &result);
    return result;
}
```

API declaration

```ts
// index.d.ts
export const getValueStringUtf8: (param: string | number) => string | void;
```

ArkTS code

```ts
 // Pass in characters and non-characters respectively. If data of the string type is passed, the data will be returned. If data of any other type is passed in, undefined will be returned.
hilog.info(0x0000, 'testTag','Test NAPI get_value_string_utf8_string %{public}s', testNapi.getValueStringUtf8 ('aaBC+-$ %^Hello 123');
hilog.info(0x0000, 'testTag', 'Test NAPI get_value_string_utf8_not_string %{public}s', testNapi.getValueStringUtf8(50));
```

### napi_create_string_utf8

Use **napi_create_string_utf8** to create a JS string from a UTF8-encoded C string.

CPP code

```cpp
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

API declaration

```ts
// index.d.ts
export const createStringUtf8: () => string | void;
```

ArkTS code

```ts
hilog.info(0x0000, 'testTag', 'Test NAPI napi_create_string_utf8:%{public}s', testNapi.createStringUtf8());
```

### napi_get_value_string_utf16

Use **napi_get_value_string_utf16** to convert a JS string into a UTF-16-encoded string.

CPP code

```cpp
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
    size_t string;
    // Obtain the value and length of the string.
    napi_get_value_string_utf16(env, args[0], buffer, bufferSize, &string);
    // Obtain the string.
    napi_create_string_utf16(env, buffer, string, &result);
    // Return the result.
    return result; 
}
```

API declaration

```ts
// index.d.ts
export const getValueStringUtf16: (data: string) => string;
```

ArkTS code

```ts
let result = testNapi.getValueStringUtf16('hello,');
hilog.info(0x0000,'testTag','NAPI napi_get_value_string_utf16:%{public}s', result);
```

### napi_create_string_utf16

Use **napi_create_string_utf16** to create a JS string from a UTF16-encoded C string.

CPP code

```cpp
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

API declaration

```ts
// index.d.ts
export const createStringUtf16: () => string | void;
```

ArkTS code

```ts
hilog.info(0x0000, 'testTag', 'Test NAPI napi_create_string_utf16:%{public}s ', testNapi.createStringUtf16());
```

### napi_get_value_string_latin1

Use **napi_get_value_string_latin1** to convert a JS string into an ISO-8859-1-encoded string.

CPP code

```cpp
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

API declaration

```ts
// index.d.ts
export const getValueStringLatin1: (param: number | string) => string | void;
```

ArkTS code

```ts
// If non-character data is passed in, undefined will be returned.
hilog.info(0x0000, 'testTag', 'Test NAPI get_value_string_latin1_not_string %{public}s', testNapi.getValueStringLatin1(10));
// The ISO-8859-1 encoding does not support Chinese characters. If Chinese characters are passed in, garbled characters will be displayed.
hilog.info(0x0000, 'testTag','Test NAPI get_value_string_latin1_string_chinese %{public}s', testNapi.getValueStringLatin1 ('中文');
// Passing in characters of other languages will not cause garbled characters.
hilog.info(0x0000, 'testTag', 'Test NAPI get_value_string_latin1_string %{public}s', testNapi.getValueStringLatin1('abo ABP=-&*/'));
```

### napi_create_string_latin1

Use **napi_create_string_latin1** to create a JS string from an ISO-8859-1-encoded C string.

CPP code

```cpp
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

API declaration

```ts
// index.d.ts
export const createStringLatin1: () => string | void;
```

ArkTS code

```ts
hilog.info(0x0000, 'testTag', 'Test NAPI  napi_create_string_latin1:%{public}s', testNapi.createStringLatin1());
```

## Configuring Compile Settings and Registering a Module

- Configure compile settings.

```text
// CMakeLists.txt
# the minimum version of CMake.
cmake_minimum_required(VERSION 3.4.1)
project(about_string)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

add_library(entry SHARED about_string.cpp)
target_link_libraries(entry PUBLIC libace_napi.z.so)
```

- Register the module.

```cpp
// about_string.cpp
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) 
{
    napi_property_descriptor desc[] = {
        {"getValueStringUtf8", nullptr, GetValueStringUtf8, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"createStringUtf8", nullptr, CreateStringUtf8, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getValueStringUtf16", nullptr, GetValueStringUtf16, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"createStringUtf16", nullptr, CreateStringUtf16, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getValueStringLatin1", nullptr, GetValueStringLatin1, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"createStringLatin1", nullptr, CreateStringLatin1, nullptr, nullptr, nullptr, napi_default, nullptr }
        };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END
```

<!--no_check-->