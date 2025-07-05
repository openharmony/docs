# 使用JSVM-API接口进行Date相关开发

## 简介

JSVM-API中date相关接口用于处理JavaScript Date对象，并在JSVM模块和JavaScript代码之间进行日期数据的转换和处理。这对于在JSVM模块中处理时间和日期相关逻辑非常有用。

## 基本概念

在JSVM-API中，JavaScript Date对象的数据表示从UTC时间1970年1月1日0时0分0秒起至现在的总毫秒数。

JavaScript Date对象提供了一种在JavaScript中表示和操作日期和时间的方式。它们允许开发者创建表示特定时刻的日期对象，执行各种日期和时间相关的计算（如添加或减去时间间隔），以及格式化日期为字符串以供显示。

在JSVM-API中，通过提供与Date对象交互的函数，JSVM模块能够更紧密地与JavaScript环境集成，执行更复杂的日期和时间相关操作。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_CreateDate           | 创建了一个表示给定毫秒数的Date对象。  |
| OH_JSVM_GetDateValue        | 获取给定JavaScript Date的时间值的Double基础类型值。  |
| OH_JSVM_IsDate               | 判断一个JavaScript对象是否为Date类型对象。|

## 使用示例

JSVM-API接口开发流程请参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅展示接口对应的C++相关代码。

### OH_JSVM_CreateDate

创建一个表示给定毫秒数的Date对象。

cpp部分代码：

```cpp
#include <time.h>
// OH_JSVM_CreateDate的样例方法
static JSVM_Value CreateDate(JSVM_Env env, JSVM_CallbackInfo info) {
    // 通过c接口获取Unix纪元以来经过的秒数，并转化为毫秒数为单位
    double value = static_cast<double>(time(NULL) * 1000);
    // 调用OH_JSVM_CreateDate接口将double值转换成表示日期时间的JavaScript值返回出去
    JSVM_Value returnValue = nullptr;

    JSVM_CALL(OH_JSVM_CreateDate(env, value, &returnValue));

    bool isDate = false;
    JSVM_CALL(OH_JSVM_IsDate(env, returnValue, &isDate));
    if (!isDate) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsDate fail");
        return returnValue;
    }

    value = 0;
    JSVM_CALL(OH_JSVM_GetDateValue(env, returnValue, &value));

    uint64_t time = static_cast<uint64_t>(value) / 1000;
    char *date = ctime(reinterpret_cast<time_t *>(&time));
    OH_LOG_INFO(LOG_APP, "JSVM CreateDate success:%{public}s", date);

    return returnValue;
}

// CreateDate注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateDate},
};
static JSVM_CallbackStruct *method = param;
// CreateDate方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createDate", nullptr, method, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(createDate())JS";
```

预期结果：
```
JSVM CreateDate success:Mon Jul 7 10:42:34 2025
```

<!-- @[oh_jsvm_create_date](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutDate/createdate/src/main/cpp/hello.cpp) -->

### OH_JSVM_GetDateValue

获取给定JavaScript Date的时间值的Double基础类型值。

cpp部分代码：

```cpp
#include <ctime>
// OH_JSVM_GetDateValue的样例方法
static JSVM_Value GetDateValue(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
    // 获取传入的Unix Time Stamp时间
    double value = 0;
    JSVM_CALL(OH_JSVM_GetDateValue(env, args[0], &value)); 
   
    // 将获取到的Unix Time Stamp时间转化为日期字符串打印
    uint64_t time = static_cast<uint64_t>(value) / 1000;
    char *date = ctime(reinterpret_cast<time_t *>(&time));
    OH_LOG_INFO(LOG_APP, "JSVM GetDateValue success:%{public}s", date);
   
    JSVM_Value returnValue = nullptr;
    JSVM_CALL(OH_JSVM_CreateDouble(env, value, &returnValue));
    return returnValue;
}

// CreateDate注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetDateValue},
};
static JSVM_CallbackStruct *method = param;
// CreateDate方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getDateValue", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(getDateValue(new Date(Date.now())))JS";
```

预期结果：
```
JSVM GetDateValue success:Mon Jul 7 10:47:08 2025
```

<!-- @[oh_jsvm_get_date_value](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutDate/getdatevalue/src/main/cpp/hello.cpp) -->

### OH_JSVM_IsDate

判断一个JavaScript对象是否为Date类型对象。

cpp部分代码：

```cpp
// OH_JSVM_IsDate的样例方法
static JSVM_Value IsDate(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
    bool isData = false;
    JSVM_CALL(OH_JSVM_IsDate(env, args[0], &isData));
    OH_LOG_INFO(LOG_APP, "JSVM IsDate success:%{public}d", isData);
    
    JSVM_Value result = nullptr;
    JSVM_CALL(OH_JSVM_GetBoolean(env, isData, &result));
    return result;
}
// CreateDate注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsDate},
};
static JSVM_CallbackStruct *method = param;
// CreateDate方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"isDate", nullptr, method, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(isDate(new Date(Date.now())))JS";
```

预期结果：
```
JSVM IsDate success:1
```

<!-- @[oh_jsvm_is_date](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutDate/isdate/src/main/cpp/hello.cpp) -->
