# Performing JSON Operations Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Introduction

This topic walks you through on how to use JSVM-API to manipulate data in JavaScript Object Notation (JSON).

## Basic Concepts

- **JSON (JavaScript Object Notation)**: a common data exchange format for data transfer, storage, and communication between the frontend and backend. It interacts with multiple programming languages and is widely used in JavaScript for data processing.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_JsonParse          | Parses a JSON string and stores the result in a JSON object.|
| OH_JSVM_JsonStringify      | Converts a JS object into a JSON string stores the result in a JSVM string object.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in related APIs.

### OH_JSVM_JsonParse & OH_JSVM_JsonStringify

Use **OH_JSVM_JsonParse** to parse a JSON object and **OH_JSVM_JsonStringify** to output the parsing result.

CPP code:

```cpp
// hello.cpp
#include <string>

// Parse a JSON number.
static JSVM_Value JsonParseNumber(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Set the JSON number to be parsed.
    std::string strNumber = "10.555";
    JSVM_Value jsonString = nullptr;
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, strNumber.c_str(), strNumber.size(), &jsonString));
    JSVM_Value jsonObject = nullptr;
    // Call OH_JSVM_JsonParse to parse the JSON number and store the result in a JSON object.
    JSVM_CALL(OH_JSVM_JsonParse(env, jsonString, &jsonObject));
    double number = 0.0f;
    JSVM_CALL(OH_JSVM_GetValueDouble(env, jsonObject, &number));
    OH_LOG_INFO(LOG_APP, "Test JSVM jsonParseNumber: %{public}f", number);
    return nullptr;
}

// Parse a JSON object.
static JSVM_Value JsonParseObject(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Set the JSON object string to be parsed.
    std::string strObject = "{\"first\": \"one\", \"second\": \"two\", \"third\": \"three\"}";
    JSVM_Value strJson = nullptr;
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, strObject.c_str(), strObject.size(), &strJson));
    JSVM_Value jsonObject = nullptr;
    // Call OH_JSVM_JsonParse to parse the JSON string object and store the result in a JSON object.
    JSVM_CALL(OH_JSVM_JsonParse(env, strJson, &jsonObject));
    JSVM_Value jsonString = nullptr;
    // Call OH_JSVM_JsonStringify to convert the object into a string and store the string in a JSVM string object.
    JSVM_CALL(OH_JSVM_JsonStringify(env, jsonObject, &jsonString));
    size_t totalLen = 0;
    JSVM_CALL(OH_JSVM_GetValueStringUtf8(env, jsonString, nullptr, 0, &totalLen));
    size_t needLen = totalLen + 1;
    char* buff = new char[needLen];
    JSVM_CALL(OH_JSVM_GetValueStringUtf8(env, jsonString, buff, needLen, &totalLen));
    OH_LOG_INFO(LOG_APP, "Test JSVM jsonParseObject: %{public}s", buff);
    delete[] buff;
    return nullptr;
}

// Register JsonParse callbacks.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsonParseNumber},
    {.data = nullptr, .callback = JsonParseObject},
};

static JSVM_CallbackStruct *method = param;

JSVM_PropertyDescriptor descriptor[] = {
    {"jsonParseNumber", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"jsonParseObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// JS code to be executed.
static const char *srcCallNative = R"JS(jsonParseNumber();jsonParseObject();)JS";
```
<!-- @[oh_jsvm_json_parse_and_json_stringify](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/UsageInstructionsOne/aboutjson/src/main/cpp/hello.cpp) -->

## Expected result:
```cpp
Test JSVM jsonParseNumber: 10.555000

Test JSVM jsonParseObject: {"first":"one","second":"two","third":"three"}
```
