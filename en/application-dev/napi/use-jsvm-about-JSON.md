# Performing JSON Operations Using JSVM-API

## Introduction

This topic walks you through on how to use JSVM-API to manipulate data in JavaScript Object Notation (JSON).

## Basic Concepts

JSON: a common text format that is language-independent and can be easily transmitted and stored between the frontend and backend. It is widely used for data processing in JavaScript (JS).

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_JsonParse          | Parses a JSON string and stores the result in a JSON object.|
| OH_JSVM_JsonStringify      | Converts a JS object into a JSON string stores the result in a JSVM string object.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in processing JSON data.

### OH_JSVM_JsonParse and OH_JSVM_JsonStringify

Parse a JSON object and return a valid value.

CPP code:

```cpp
// hello.cpp
#include <string>

// JS code to be executed.
static const char *STR_TASK = R"JS(jsonParseNumber();jsonParseObject();)JS";

// Parse a JSON number.
static JSVM_Value JsonParseNumber(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Set the JSON number to be parsed.
    std::string strNumber = "10.555";
    JSVM_Value jsonString;
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, strNumber.c_str(), strNumber.size(), &jsonString));
    JSVM_Value jsonObject;
    // Call OH_JSVM_JsonParse to parse the JSON number and store the result in a JSON object.
    JSVM_CALL(OH_JSVM_JsonParse(env, jsonString, &jsonObject));
    double number;
    JSVM_CALL(OH_JSVM_GetValueDouble(env, jsonObject, &number));
    OH_LOG_INFO(LOG_APP, "Test JSVM jsonParseNumber: %{public}f", number);
    return nullptr;
}

// Parse a JSON object.
static JSVM_Value JsonParseObject(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Set the JSON object string to be parsed.
    std::string strObject = "{\"first\": \"one\", \"second\": \"two\", \"third\": \"three\"}";
    JSVM_Value strJson;
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, strObject.c_str(), strObject.size(), &strJson));
    JSVM_Value jsonObject;
    // Call OH_JSVM_JsonParse to parse the JSON string object and store the result in a JSON object.
    JSVM_CALL(OH_JSVM_JsonParse(env, strJson, &jsonObject));
    JSVM_Value jsonString;
    // Call OH_JSVM_JsonStringify to convert the object into a string and store the string in a JSVM string object.
    JSVM_CALL(OH_JSVM_JsonStringify(env, jsonObject, &jsonString));
    size_t totalLen = 0;
    JSVM_CALL(OH_JSVM_GetValueStringUtf8(env, jsonString, nullptr, 0, &totalLen));
    size_t needLen = totalLen + 1;
    char* buff = new char[needLen];
    JSVM_CALL(OH_JSVM_GetValueStringUtf8(env, jsonString, buff, needLen, &totalLen));
    OH_LOG_INFO(LOG_APP, "Test JSVM jsonParseNumber: %{public}s", buff);
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

```

## Expected Result

Test JSVM jsonParseNumber: 10.555000

Test JSVM jsonParseNumber: {"first":"one","second":"two","third":"three"}
