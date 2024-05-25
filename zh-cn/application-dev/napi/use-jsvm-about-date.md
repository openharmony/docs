# 使用JSVM-API接口进行Date相关开发

## 简介

JSVM-API中date相关接口用于处理JavaScript Date对象，并在JSVM模块和JavaScript代码之间进行日期数据的转换和处理。这对于在JSVM模块中处理时间和日期相关逻辑非常有用。

## 基本概念

在JSVM-API中，JavaScript Date对象的数据表示从UTC时间1970年1月1日0时0分0秒起至现在的总毫秒数。

JavaScript Date对象提供了一种在JavaScript中表示和操作日期和时间的方式。它们允许您创建表示特定时刻的日期对象，执行各种日期和时间相关的计算（如添加或减去时间间隔），以及格式化日期为字符串以供显示。

在JSVM-API中，通过提供与Date对象交互的函数，JSVM模块能够更紧密地与JavaScript环境集成，执行更复杂的日期和时间相关操作。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_CreateDate           | 创建了一个表示给定毫秒数的Date对象。  |
| OH_JSVM_GetDateValue        | 获取给定JavaScript Date的时间值的Double基础类型值。  |
| OH_JSVM_IsDate               | 判断一个JavaScript对象是否为Date类型对象。|

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### OH_JSVM_CreateDate

创建一个表示给定毫秒数的Date对象。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// CreateDate注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateDate},
};
static JSVM_CallbackStruct *method = param;
// CreateDate方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createDate", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_CreateDate的样例方法
static JSVM_Value CreateDate(JSVM_Env env, JSVM_CallbackInfo info) {
    double value = 1501924876711;
    // 调用OH_JSVM_CreateDate接口将double值转换成表示日期时间的JavaScript值返回出去
    JSVM_Value returnValue = nullptr;
    JSVM_Status status = OH_JSVM_CreateDate(env, value, &returnValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateDate fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM CreateDate success");
    }
    return returnValue;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string = `createDate()`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM CreateDate: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM CreateDate error: %{public}s', error.message);
}
```

### OH_JSVM_GetDateValue

获取给定JavaScript Date的时间值的Double基础类型值。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// GetDateValue注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetDateValue},
};
static JSVM_CallbackStruct *method = param;
// GetDateValue方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getDateValue", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_GetDateValue的样例方法
static JSVM_Value GetDateValue(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 获取传入的Unix Time Stamp时间
    double value;
    JSVM_Status status = OH_JSVM_GetDateValue(env, args[0], &value);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsArray fail");
    } else {
        // 将获取到的Unix Time Stamp时间打印
        OH_LOG_INFO(LOG_APP, "JSVM gets the incoming Green time:%{public}lf.", value);
    }
    JSVM_Value returnValue = nullptr;
    OH_JSVM_CreateDouble(env, value, &returnValue);
    return returnValue;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
let script: string = `getDateValue(new Date(Date.now()))`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM GetDateValue: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM GetDateValue error: %{public}s', error.message);
}
```

### OH_JSVM_IsDate

判断一个JavaScript对象是否为Date类型对象。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// IsDate注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsDate},
};
static JSVM_CallbackStruct *method = param;
// IsDate方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"isDate", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_IsDate的样例方法
static JSVM_Value IsDate(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool result;
    JSVM_Status status = OH_JSVM_IsDate(env, args[0], &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsDate fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM IsDate success:%{public}d", result);
    }
    JSVM_Value isDate = nullptr;
    OH_JSVM_GetBoolean(env, result, &isDate);
    return isDate;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
try {
  let script: string = `isDate(new Date(Date.now()))`;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM IsDate: %{public}s', napitest.runJsVm(script));
  script = `
      isDate(1)
  `;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM IsDate: %{public}s', napitest.runJsVm(script));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM IsDate error: %{public}s', error.message);
}
```
