# 使用JSVM-API接口进行JSON操作

## 简介

使用JSVM-API接口对JSON数据操作时，相关接口可以在JSVM模块中直接操作和处理JSON格式的数据。

## 基本概念

- **JSON（ JavaScript Object Notation）**：是一种常见的数据交换格式，可用于实现前后端之间的数据传递、存储和交流，并且可以与多种编程语言进行交互，在JavaScript中被广泛应用于数据处理。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_JsonParse          | 解析JSON字符串，并将结果存储在JSON对象。 |
| OH_JSVM_JsonStringify      | 将对象字符串化，并将结果存储在JSVM字符串对象。 |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### OH_JSVM_JsonParse && OH_JSVM_JsonStringify

对JSON对象进行解析操作，并输出解析结果的有效值。

cpp部分代码

```cpp
// hello.cpp
#include <string>

// 待执行的js代码
static const char *STR_TASK = R"JS(jsonParseNumber();jsonParseObject();)JS";

// 解析JSON数字
static JSVM_Value JsonParseNumber(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 设置要解析的JSON数字
    std::string strNumber = "10.555";
    JSVM_Value jsonString;
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, strNumber.c_str(), strNumber.size(), &jsonString));
    JSVM_Value jsonObject;
    // 调用OH_JSVM_JsonParse函数解析JSON数字，并将结果存储在JSON对象中
    JSVM_CALL(OH_JSVM_JsonParse(env, jsonString, &jsonObject));
    double number;
    JSVM_CALL(OH_JSVM_GetValueDouble(env, jsonObject, &number));
    OH_LOG_INFO(LOG_APP, "Test JSVM jsonParseNumber: %{public}f", number);
    return nullptr;
}

// 解析JSON字符串中的对象
static JSVM_Value JsonParseObject(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 设置要解析的JSON对象字符串
    std::string strObject = "{\"first\": \"one\", \"second\": \"two\", \"third\": \"three\"}";
    JSVM_Value strJson;
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, strObject.c_str(), strObject.size(), &strJson));
    JSVM_Value jsonObject;
    // 调用OH_JSVM_JsonParse函数解析JSON对象字符串，并将结果存储在JSON对象中
    JSVM_CALL(OH_JSVM_JsonParse(env, strJson, &jsonObject));
    JSVM_Value jsonString;
    // 调用OH_JSVM_JsonStringify函数将对象转换为字符串格式，并将结果存储在JSVM字符串对象中
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

```

## 预期结果

Test JSVM jsonParseNumber: 10.555000

Test JSVM jsonParseNumber: {"first":"one","second":"two","third":"three"}

