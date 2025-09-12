# 使用JSVM-API接口进行JSON操作
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## 简介

使用JSVM-API接口操作JSON数据时，JSVM模块中的相关接口可以直接处理JSON格式的数据。

## 基本概念

- **JSON（JavaScript Object Notation）**：是一种常见的数据交换格式，用于前后端数据的传递、存储和交流。可以与多种编程语言进行交互，在JavaScript中被广泛应用于数据处理。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_JsonParse          | 解析JSON字符串，并将结果存储在JSON对象。 |
| OH_JSVM_JsonStringify      | 将对象字符串化，并将结果存储在JSVM字符串对象。 |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅展示接口对应的C++相关代码。

### OH_JSVM_JsonParse & OH_JSVM_JsonStringify

解析JSON对象，并输出有效的解析结果。

cpp部分代码：

```cpp
// hello.cpp
#include <string>

// 解析JSON数字
static JSVM_Value JsonParseNumber(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 设置要解析的JSON数字
    std::string strNumber = "10.555";
    JSVM_Value jsonString = nullptr;
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, strNumber.c_str(), strNumber.size(), &jsonString));
    JSVM_Value jsonObject = nullptr;
    // 调用OH_JSVM_JsonParse函数解析JSON数字，并将结果存储在JSON对象中
    JSVM_CALL(OH_JSVM_JsonParse(env, jsonString, &jsonObject));
    double number = 0.0f;
    JSVM_CALL(OH_JSVM_GetValueDouble(env, jsonObject, &number));
    OH_LOG_INFO(LOG_APP, "Test JSVM jsonParseNumber: %{public}f", number);
    return nullptr;
}

// 解析JSON字符串中的对象
static JSVM_Value JsonParseObject(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 设置要解析的JSON对象字符串
    std::string strObject = "{\"first\": \"one\", \"second\": \"two\", \"third\": \"three\"}";
    JSVM_Value strJson = nullptr;
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, strObject.c_str(), strObject.size(), &strJson));
    JSVM_Value jsonObject = nullptr;
    // 调用OH_JSVM_JsonParse函数解析JSON对象字符串，并将结果存储在JSON对象中
    JSVM_CALL(OH_JSVM_JsonParse(env, strJson, &jsonObject));
    JSVM_Value jsonString = nullptr;
    // 调用OH_JSVM_JsonStringify函数将对象转换为字符串格式，并将结果存储在JSVM字符串对象中
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

// JsonParse注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsonParseNumber},
    {.data = nullptr, .callback = JsonParseObject},
};

static JSVM_CallbackStruct *method = param;

JSVM_PropertyDescriptor descriptor[] = {
    {"jsonParseNumber", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"jsonParseObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 待执行的js代码
static const char *srcCallNative = R"JS(jsonParseNumber();jsonParseObject();)JS";
```
<!-- @[oh_jsvm_json_parse_and_json_stringify](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/UsageInstructionsOne/aboutjson/src/main/cpp/hello.cpp) -->

## 预期结果：
```cpp
Test JSVM jsonParseNumber: 10.555000

Test JSVM jsonParseObject: {"first":"one","second":"two","third":"three"}
```
