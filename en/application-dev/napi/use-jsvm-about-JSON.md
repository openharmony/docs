# Performing JSON Operations Using JSVM-API

## Introduction

Data in JavaScript Object Notation (JSON) is used for data transfer, storage, and exchange between the frontend and backend. JSON is language-independent, which means it can be used with multiple programming languages.

## Basic Concepts

JSON: a text-based format for representing structured data. It is widely used for data processing in JS.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_JsonParse          | Parses a JSON string and returns the parsed value. |
| OH_JSVM_JsonStringify      | Converts a JS object into a JSON string and returns the converted string. |

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ and ArkTS code related to JSON operations.

### OH_JSVM_JsonParse

Use **OH_JSVM_JsonParse** to parse a JSON string and return a valid value of the parsing result.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register JsonParse callbacks.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsonParseNumber},
    {.data = nullptr, .callback = JsonParseObject},
};
static JSVM_CallbackStruct *method = param;
// Expose theJsonParse callbacks to JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsonParseNumber", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"jsonParseObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_JsonParse methods.

// Parse the number in a JSON string.
static JSVM_Value JsonParseNumber(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Set the JSON numeric string to be parsed.
    std::string strNumber = "10.555";
    JSVM_Value jsonString;
    OH_JSVM_CreateStringUtf8(env, strNumber.c_str(), strNumber.size(), &jsonString);
    // Call OH_JSVM_JsonParse to parse the JSON string and store the parsed value in result.
    JSVM_Value result;
    JSVM_Status status = OH_JSVM_JsonParse(env, jsonString, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM JsonParseNumber fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM JsonParseNumber success");
    }
    return result;
}
// Parse the object in a JSON string.
static JSVM_Value JsonParseObject(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Set the JSON object string to be parsed.
    std::string strObject = "{\"first\": \"one\", \"second\": \"two\", \"third\": \"three\"}";
    JSVM_Value strJson;
    OH_JSVM_CreateStringUtf8(env, strObject.c_str(), strObject.size(), &strJson);
    // Call OH_JSVM_JsonParse to parse the JSON string and store the parsed value in ret.
    JSVM_Value ret;
    JSVM_Status status = OH_JSVM_JsonParse(env, strJson, &ret);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM JsonParseObject fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM JsonParseObject success");
    }
    return ret;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `
    jsonParseNumber()
`
let script1: string = `
    jsonParseObject()
`
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM jsonParseNumber: %{public}s', result);
  let result1 = napitest.runJsVm(script1);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM jsonParseObject: %{public}s', result1);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM JsonParse error: %{public}s', error.message);
}
```

### OH_JSVM_JsonStringify

User **OH_JSVM_JsonStringify** to convert an object to a string and return the string value.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the JsonStringify callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsonStringify},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named jsonStringify and associate it with a callback. This allows the JsonStringify callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsonStringify", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_JsonStringify.
static JSVM_Value JsonStringify(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Create an object and convert it to a string.
    JSVM_Value jsonObject;
    OH_JSVM_CreateObject(env, &jsonObject);
    // Set properties.
    std::string strValue = "JsonStringify";
    JSVM_Value value = nullptr;
    JSVM_Value key;
    OH_JSVM_CreateStringUtf8(env, "property", JSVM_AUTO_LENGTH, &key);
    OH_JSVM_CreateStringUtf8(env, strValue.c_str(), strValue.size(), &value);
    OH_JSVM_SetProperty(env, jsonObject, key, value);
    // Call OH_JSVM_JsonStringify to convert the object into a string and output the string.
    JSVM_Value result;
    JSVM_Status status = OH_JSVM_JsonStringify(env, jsonObject, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_JsonStringify fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_JsonStringify success");
    }
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `
    jsonStringify()
`
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM jsonStringify: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getVMInfo error: %{public}s', error.message);
}
```
