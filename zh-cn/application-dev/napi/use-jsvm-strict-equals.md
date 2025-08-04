# 使用JSVM-API判断给定的两个JS value是否严格相等
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @huanghan18; @suyuehhh; @KasonChan; @string_sz; @diking-->
<!--SE: @knightaoko-->
<!--TSE: @test_lzz-->

## 简介

JSVM-API 中的函数用于判断两个 JavaScript 值是否严格相等，类似于 JavaScript 中的 `===` 操作符。该函数避免类型转换和松散相等性比较，确保值和类型均相等。

## 基本概念

比较两个JavaScript值是否严格相等。严格相等比较不会进行类型转换，它要求两个值的类型和值完全相同才会返回true。

## 接口说明

| 接口                       | 功能说明                            |
|----------------------------|-------------------------------------|
| OH_JSVM_StrictEquals         | 判断两个JSVM_Value对象是否相等 |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### OH_JSVM_StrictEquals

判断给定的两个JS value是否严格相等。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_StrictEquals的样例方法
static JSVM_Value IsStrictEquals(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 接受两个入参
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 调用OH_JSVM_StrictEquals接口判断给定的两个JavaScript value是否严格相等
    bool result = false;
    JSVM_Status status = OH_JSVM_StrictEquals(env, args[0], args[1], &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_StrictEquals: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_StrictEquals: success: %{public}d", result);
    }
    JSVM_Value isStrictEqual = nullptr;
    OH_JSVM_GetBoolean(env, result, &isStrictEqual);
    return isStrictEqual;
}
// IsStrictEquals注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsStrictEquals},
};
static JSVM_CallbackStruct *method = param;
// IsStrictEquals方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"isStrictEquals", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char* srcCallNative = R"JS(data = '123';value = '123';isStrictEquals(data,value);)JS";
```
<!-- @[oh_jsvm_strict_equals](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/UsageInstructionsTwo/strictequals/src/main/cpp/hello.cpp) -->

预期的输出结果：

```ts
JSVM OH_JSVM_StrictEquals: success: 1
```
