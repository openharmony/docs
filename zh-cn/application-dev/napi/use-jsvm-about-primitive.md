# 使用JSVM-API接口进行primitive类相关开发

## 简介

在使用JSVM-API接口时，开发人员可以实现在JSVM模块中与JavaScript对象的交互，并进行数据转换和获取特定对象的操作，它们在不同的场景中发挥着重要的作用，使开发人员能够更灵活地处理JavaScript值和对象。

## 基本概念

在使用JSVM操作JavaScript对象时，需要了解一些基本概念：

- **JavaScript值到C/C++类型的转换：** 在JSVM模块中，可以使用JSVM函数将JavaScript值转换为C/C++的数据类型，如将JavaScript数值转换为C/C++的整数、将JavaScript字符串转换为C/C++的字符数组等。同样，也可以将C/C++的数据类型转换为JavaScript值，以便将结果返回给JavaScript代码。

## 接口说明

| 接口                   | 功能说明                                                |
| ---------------------- | ------------------------------------------------------- |
| OH_JSVM_CoerceToBool   | 将目标值转换为Boolean类型对象。   |
| OH_JSVM_CoerceToNumber | 将目标值转换为Number类型对象。    |
| OH_JSVM_CoerceToObject | 将目标值转换为Object类型对象。    |
| OH_JSVM_CoerceToString | 将目标值转换为String类型对象。    |
| OH_JSVM_GetBoolean       | 获取JavaScript单例对象。 |
| OH_JSVM_GetValueBool    | 获取给定JavaScript Boolean的C布尔基础类型值。 |
| OH_JSVM_GetGlobal      | 获取当前环境中的全局global对象。                                      |
| OH_JSVM_GetNull          | 获取JavaScript null。                                        |
| OH_JSVM_GetUndefined     | 获取JavaScript undefined。                                   |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)。本文仅展示接口对应的C++相关代码。

### OH_JSVM_CoerceToBool

用于将一个给定的JavaScript值强制转为JavaScript boolean值。

cpp 部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_CoerceToBool的样例方法
static JSVM_Value CoerceToBool(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value boolean = nullptr;
    JSVM_Status status = OH_JSVM_CoerceToBool(env, args[0], &boolean);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CoerceToBool failed");
    } else {
        bool result = false;
        OH_JSVM_GetValueBool(env, boolean, &result);
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CoerceToBool success:%{public}d", result);
    }
    return boolean;
}
// CoerceToBool注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CoerceToBool},
};
static JSVM_CallbackStruct *method = param;
// CoerceToBool方法别名，ArkTS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"coerceToBool", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(coerceToBool("123"))JS";
```
<!-- @[oh_jsvm_coerce_to_bool](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/coercetobool/src/main/cpp/hello.cpp) -->

预期结果：
```
SVM OH_JSVM_CoerceToBool success:1
```

### OH_JSVM_CoerceToNumber

用于将给定的JavaScript value强转为JavaScript number。

cpp 部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_CoerceToNumber的样例方法
static JSVM_Value CoerceToNumber(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value number = nullptr;
    JSVM_Status status = OH_JSVM_CoerceToNumber(env, args[0], &number);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CoerceToNumber failed");
    } else {
        int32_t result = 0;
        OH_JSVM_GetValueInt32(env, number, &result);
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CoerceToNumber success:%{public}d", result);
    }
    return number;
}
// CoerceToNumber注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CoerceToNumber},
};
static JSVM_CallbackStruct *method = param;
// CoerceToNumber方法别名，ArkTS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"coerceToNumber", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(coerceToNumber(true))JS";
```
<!-- @[oh_jsvm_coerce_to_number](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/coercetonumber/src/main/cpp/hello.cpp) -->

预期结果：
```
JSVM OH_JSVM_CoerceToNumber success:1
```

### OH_JSVM_CoerceToObject

用于将给定的JavaScript value强转为JavaScript Object类型。

cpp 部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_CoerceToObject的样例方法
static JSVM_Value CoerceToObject(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value obj = nullptr;
    JSVM_Status status = OH_JSVM_CoerceToObject(env, args[0], &obj);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_CoerceToObject failed");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CoerceToObject success");
    }
    return obj;
}
// CoerceToObject注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CoerceToObject},
};
static JSVM_CallbackStruct *method = param;
// CoerceToObject方法别名，ArkTS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"coerceToObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(coerceToObject(123))JS";
```
<!-- @[oh_jsvm_coerce_to_object](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/coercetoobject/src/main/cpp/hello.cpp) -->

预期结果：
```
JSVM OH_JSVM_CoerceToObject success
```

### OH_JSVM_CoerceToString

用于将给定的JavaScript value强转为JavaScript string类型。

cpp 部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_CoerceToString的样例方法
static JSVM_Value CoerceToString(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value str = nullptr;
    JSVM_Status status = OH_JSVM_CoerceToString(env, args[0], &str);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_CoerceToString fail");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CoerceToString success");
    }
    return str;
}
// CoerceToString注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CoerceToString},
};
static JSVM_CallbackStruct *method = param;
// CoerceToString方法别名，ArkTS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"coerceToString", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(coerceToString(22222))JS";
```
<!-- @[oh_jsvm_coerce_to_string](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/coercetostring/src/main/cpp/hello.cpp) -->

预期结果：
```
JSVM OH_JSVM_CoerceToString success
```

### OH_JSVM_GetBoolean

获取给定布尔值的JavaScript单例对象。

cpp 部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_GetBoolean的样例方法
static JSVM_Value GetBoolean(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 传入两个参数并解析
    size_t argc = 2;
    JSVM_Value argv[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    int32_t paramData = 0;
    OH_JSVM_GetValueInt32(env, argv[0], &paramData);
    int32_t paramValue = 0;
    OH_JSVM_GetValueInt32(env, argv[1], &paramValue);
    JSVM_Value returnValue = nullptr;
    bool type = false;
    if (paramData == paramValue) {
        OH_LOG_INFO(LOG_APP, "JSVM resultType equal");
        type = true;
    }
    JSVM_Status status = OH_JSVM_GetBoolean(env, type, &returnValue);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_CoerceToNumber fail");
    } else {
        bool result = false;
        OH_JSVM_GetValueBool(env, returnValue, &result);
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CoerceToNumber success:%{public}d", result);
    }
    // 返回结果
    return returnValue;
}
// GetBoolean注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetBoolean},
};
static JSVM_CallbackStruct *method = param;
// GetBoolean方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getBoolean", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(getBoolean(1, 2);
                                 getBoolean(1, 1))JS";
```
<!-- @[oh_jsvm_get_boolean](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/getboolean/src/main/cpp/hello.cpp) -->

预期结果：
```
JSVM OH_JSVM_CoerceToNumber success:0
JSVM resultType equal
JSVM OH_JSVM_CoerceToNumber success:1
```

### OH_JSVM_GetValueBool

使用这个函数将JavaScript中的布尔值转为等价的C布尔值。

cpp 部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_GetValueBool的样例方法
static JSVM_Value GetValueBool(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool result = false;
    JSVM_Status status = OH_JSVM_GetValueBool(env, args[0], &result);
    if (status == JSVM_BOOLEAN_EXPECTED || status != JSVM_OK) {
        // 如果OH_JSVM_GetValueBool成功会返回JSVM_OK，如果传入一个非布尔值则会返回JSVM_BOOLEAN_EXPECTED
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetValueBool fail:%{public}d", status);
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetValueBool success:%{public}d", result);
    }
    JSVM_Value boolJv = nullptr;
    OH_JSVM_GetBoolean(env, result, &boolJv);
    return boolJv;
}
// GetValueBool注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueBool},
};
static JSVM_CallbackStruct *method = param;
// GetValueBool方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueBool", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(getValueBool("abc");
                                getValueBool(true);
                                getValueBool(false);)JS";
```
<!-- @[oh_jsvm_get_value_bool](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/getvaluebool/src/main/cpp/hello.cpp) -->

预期结果：
```
JSVM OH_JSVM_GetValueBool fail:7
JSVM OH_JSVM_GetValueBool success:1
JSVM OH_JSVM_GetValueBool success:0
```

### OH_JSVM_GetGlobal

用于获取全局JavaScript对象。该函数的主要作用是获取表示JavaScript全局对象的JSVM_Value，使JSVM模块能够与JavaScript运行时的全局对象进行交互。

cpp 部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_GetGlobal的样例方法
static JSVM_Value GetGlobal(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 获取全局对象
    JSVM_Value value = nullptr;
    JSVM_Value global = nullptr;
    OH_JSVM_CreateInt32(env, 1, &value);
    JSVM_Status status = OH_JSVM_GetGlobal(env, &global);
    OH_JSVM_SetNamedProperty(env, global, "Row", value);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetGlobal fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetGlobal success");
    }
    return global;
}
// GetGlobal注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetGlobal},
};
static JSVM_CallbackStruct *method = param;
// GetGlobal方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getGlobal", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(getGlobal())JS";
```
<!-- @[oh_jsvm_get_global](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/getglobal/src/main/cpp/hello.cpp) -->

预期结果：
```
JSVM OH_JSVM_GetGlobal success
```

### OH_JSVM_GetNull

用于获取 JavaScript null 对象。

cpp 部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_GetNull的样例方法
static JSVM_Value GetNull(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_Value nullValue = nullptr;
    JSVM_Status status = OH_JSVM_GetNull(env, &nullValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetNull fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetNull success");
    }
    return nullValue;
}
// GetNull注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetNull},
};
static JSVM_CallbackStruct *method = param;
// GetNull方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getNull", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(getNull())JS";
```
<!-- @[oh_jsvm_get_null](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/getnull/src/main/cpp/hello.cpp) -->

预期结果:
```
JSVM OH_JSVM_GetNull success
```

### OH_JSVM_GetUndefined

用于获取 JavaScript undefined 对象。

cpp 部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_GetUndefined的样例方法
static JSVM_Value GetUndefined(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 获取并解析传进的参数
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 创建一个undefined值
    JSVM_Value value = nullptr;
    JSVM_Status status = OH_JSVM_GetUndefined(env, &value);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetUndefined failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetUndefined success");
    }
    return value;
}
// GetUndefined注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetUndefined},
};
static JSVM_CallbackStruct *method = param;
// GetUndefined方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getUndefined", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(getUndefined())JS";
```
<!-- @[oh_jsvm_get_undefined](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPrimitive/getundefined/src/main/cpp/hello.cpp) -->

预期结果:
```
JSVM OH_JSVM_GetUndefined success
```
