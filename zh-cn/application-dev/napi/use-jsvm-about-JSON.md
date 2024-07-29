# 使用JSVM-API接口进行JSON操作

## 简介

JSON格式的数据可用于实现前后端之间的数据传递、存储和交流，并且可以与多种编程语言进行交互。

## 基本概念

- **JSON（JavaScript Object Notation）**：是一种常见的数据交换格式，在JavaScript中被广泛应用于数据处理。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_JsonParse          | 解析JSON字符串，并返回成功解析的值。 |
| OH_JSVM_JsonStringify      | 将对象字符串化，并返回成功转换后的字符串。 |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### OH_JSVM_JsonParse

对JSON字符串执行解析操作，并返回解析结果的有效值。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// JsonParse注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsonParseNumber},
    {.data = nullptr, .callback = JsonParseObject},
};
static JSVM_CallbackStruct *method = param;
// JsonParse方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsonParseNumber", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"jsonParseObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_JsonParse的样例方法

// 解析JSON字符串中的数字
static JSVM_Value JsonParseNumber(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 设置要解析的JSON数字字符串
    std::string strNumber = "10.555";
    JSVM_Value jsonString;
    OH_JSVM_CreateStringUtf8(env, strNumber.c_str(), strNumber.size(), &jsonString);
    // 调用OH_JSVM_JsonParse函数解析JSON字符串，并将结果存储在result中
    JSVM_Value result;
    JSVM_Status status = OH_JSVM_JsonParse(env, jsonString, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM JsonParseNumber fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM JsonParseNumber success");
    }
    return result;
}
// 解析JSON字符串中的对象
static JSVM_Value JsonParseObject(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 设置要解析的JSON对象字符串
    std::string strObject = "{\"first\": \"one\", \"second\": \"two\", \"third\": \"three\"}";
    JSVM_Value strJson;
    OH_JSVM_CreateStringUtf8(env, strObject.c_str(), strObject.size(), &strJson);
    // 调用OH_JSVM_JsonParse函数解析JSON字符串，并将结果存储在ret中
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

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
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

将对象转换为字符串格式，并返回转换成功的字符串值。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// JsonStringify注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = JsonStringify},
};
static JSVM_CallbackStruct *method = param;
// JsonStringify方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"jsonStringify", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_JsonStringify的样例方法
static JSVM_Value JsonStringify(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 创建一个对象并将其转换成字符串
    JSVM_Value jsonObject;
    OH_JSVM_CreateObject(env, &jsonObject);
    // 设置属性
    std::string strValue = "JsonStringify";
    JSVM_Value value = nullptr;
    JSVM_Value key;
    OH_JSVM_CreateStringUtf8(env, "property", JSVM_AUTO_LENGTH, &key);
    OH_JSVM_CreateStringUtf8(env, strValue.c_str(), strValue.size(), &value);
    OH_JSVM_SetProperty(env, jsonObject, key, value);
    // 调用OH_JSVM_JsonStringify接口将object对象转换成字符串并输出
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

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
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
