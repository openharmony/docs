# Working with Latin1/UTF16 Strings Using JSVM-API

## Introduction

This topic walks you through on how to create and use external strings using JSVM-API.

## Basic Concepts

By using JSVM-API, you can create JS strings directly in the memory allocated for Latin1/UTF16 strings. This allows you to manipulate these strings like normal JS strings.

## Available APIs

| API                                  | Description                      |
|----------------------------------------|--------------------------------|
| OH_JSVM_CreateExternalStringLatin1     | Creates an external JS string from a C string encoded in ISO-8859-1 format. |
| OH_JSVM_CreateExternalStringUtf16      | Creates an external JS string from a C string encoded in UTF16-LE format. |

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in manipulating external strings.

### Creating and Using External Strings

CPP code:

```cpp

static char stringLatin1[] = "hello";
static char16_t stringUTF16[] = "world";

static JSVM_Value testExternalString(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_VM vm;
    OH_JSVM_GetVM(env, &vm);

    JSVM_HandleScope handleScope;
    OH_JSVM_OpenHandleScope(env, &handleScope);
    JSVM_Value jsStrLatin1 = nullptr;
    bool copied = true;
    char buf[10];
    OH_JSVM_CreateExternalStringLatin1(env, stringLatin1, strlen(stringLatin1), nullptr, nullptr,
                                       &jsStrLatin1, &copied)
    OH_JSVM_GetValueStringUTF8(env, jsStrLatin1, buf, 10, nullptr);
    OH_LOG_INFO(LOG_APP, "created latin1 string is : %{public}s\n", buf);
    // If the value of copied is true, the external string fails to be created. Otherwise, the external string is created successfully.
    OH_LOG_INFO(LOG_APP, "create external string failed : %{public}d\n", copied);
    copied = true;
    JSVM_Value jsStrUTF16 = nullptr;
    OH_JSVM_CreateExternalStringUtf16(env, stringLatin1, std::char_traits<char16_t>::length(stringUTF16),
                                      nullptr, nullptr, &jsStrUTF16, &copied)
    OH_JSVM_GetValueStringUTF8(env, jsStrUTF16, buf, 10, nullptr);
    OH_LOG_INFO(LOG_APP, "created utf16 string is : %{public}s\n", buf);
    // If the value of copied is true, the external string fails to be created. Otherwise, the external string is created successfully.
    OH_LOG_INFO(LOG_APP, "create external string failed : %{public}d\n", copied);
    OH_JSVM_CloseHandleScope(env, handleScope);

    return nullptr;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = testExternalString},
};

static JSVM_CallbackStruct *method = param;

// Alias for the wrapperObject method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"testExternalString", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char *srcCallNative = R"JS(testExternalString();)JS";

```

## Expected Result
```
created latin1 string is : hello
create external string failed: 0
created utf16 string is : world
create external string failed: 0
```
