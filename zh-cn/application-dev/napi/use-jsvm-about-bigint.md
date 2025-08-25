# 使用JSVM-API接口操作bigint类型值
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## 简介

BigInt是JavaScript中用于表示任意精度整数的数据类型，能够处理比Number类型更大范围的整数值。JSVM-API提供的接口支持在JSVM模块中创建、获取和操作BigInt类型值。

## 基本概念

使用JSVM-API接口操作BigInt类型值需要理解以下基本概念：

- **BigInt类型：** BigInt是JavaScript中的一种数据类型，用于表示任意精度的整数。与Number类型不同，BigInt类型可以精确表示非常大的整数，而不会丢失精度或溢出。
- **BigInt创建：** 使用JSVM-API提供的接口，可以通过传递C的int64或uint64数据来创建对应的JavaScript BigInt。这使得在JSVM模块中可以方便地创建BigInt类型值。
- **BigInt操作：** JSVM-API提供了多个接口用于操作BigInt类型值。通过这些接口，可以获取BigInt的数值，进行数值转换，以及执行常见的算术和位运算操作。

## 接口说明

| 接口                         | 功能说明                                 |
| ---------------------------- | ---------------------------------------- |
| OH_JSVM_CreateBigintInt64     | 将C int64_t类型的值转换为JavaScript BigInt类型。|
| OH_JSVM_CreateBigintUint64    | 将C uint64_t类型的值转换为JavaScript BigInt类型。|
| OH_JSVM_CreateBigintWords     | 将一组无符号64位字转换为单个BigInt值。|
| OH_JSVM_GetValueBigintInt64  | 返回给定JavaScript BigInt的C int64_t基础类型等价值。 如果需要，它将截断该值，将lossless设置为false。       |
| OH_JSVM_GetValueBigintUint64 | 返回给定JavaScript BigInt的C uint64_t基础类型等价值。 如果需要，它将截断该值，将lossless设置为false。      |
| OH_JSVM_GetValueBigintWords  | 将单个BigInt值转换为一个符号位、一个64位的小端数组和该数组的长度。 signBit和words参数可以都设置为NULL，这种情况下，只获取wordCount。|

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)。本文仅展示接口对应的C++及ArkTS相关代码。

### OH_JSVM_GetValueBigintWords

获取给定JavaScript BigInt对象的底层数据，即BigInt数据的字词表示。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#include <fstream>

// OH_JSVM_GetValueBigintWords的样例方法
static JSVM_Value GetValueBigintWords(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    int signBit = 0;
    size_t wordCount = 0;
    uint64_t* words{nullptr};
    // 调用OH_JSVM_GetValueBigintWords接口获取wordCount
    JSVM_Status status = OH_JSVM_GetValueBigintWords(env, args[0], nullptr, &wordCount, nullptr);
    OH_LOG_INFO(LOG_APP, "OH_JSVM_GetValueBigintWords wordCount:%{public}d.", wordCount);
    words = (uint64_t*)malloc(wordCount*sizeof(uint64_t));
    if (words == nullptr) {
        OH_LOG_ERROR(LOG_APP, "OH_JSVM_GetValueBigintWords malloc failed.");
        return nullptr;
    }
    // 调用OH_JSVM_GetValueBigintWords接口获取传入bigInt相关信息，如：signBit传入bigInt正负信息
    status = OH_JSVM_GetValueBigintWords(env, args[0], &signBit, &wordCount, words);
    free(words);
    words = nullptr;
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_JSVM_GetValueBigintWords fail, status:%{public}d.", status);
    } else {
        OH_LOG_INFO(LOG_APP, "OH_JSVM_GetValueBigintWords signBit: %{public}d.", signBit);
    }
    // 将符号位转化为int类型传出去
    JSVM_Value returnValue = nullptr;
    OH_JSVM_CreateInt32(env, signBit, &returnValue);
    return returnValue;
}
// GetValueBigintWords注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueBigintWords},
};
static JSVM_CallbackStruct *method = param;
// GetValueBigintWords方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueBigintWords", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char* srcCallNative = R"JS(getValueBigintWords(BigInt(5555555555555555)))JS";
```
<!-- @[oh_jsvm_get_value_bigint_words](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutBigint/getvaluebigintwords/src/main/cpp/hello.cpp) -->

预期的输出结果
```ts
OH_JSVM_GetValueBigintWords wordCount:1.
OH_JSVM_GetValueBigintWords signBit: 0.
```

### OH_JSVM_CreateBigintWords

根据给定的Uint64_t数组创建一个JavaScript BigInt对象。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_CreateBigintWords的样例方法
static int DIFF_VALUE_THREE = 3;
static JSVM_Value CreateBigintWords(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 使用OH_JSVM_CreateBigintWords接口创建一个BigInt对象
    int signBit = 0;
    size_t wordCount = DIFF_VALUE_THREE;
    uint64_t words[] = {12ULL, 34ULL, 56ULL};
    JSVM_Value returnValue = nullptr;
    JSVM_Status status = OH_JSVM_CreateBigintWords(env, signBit, wordCount, words, &returnValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateBigintWords fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CreateBigintWords success");
    }
    return returnValue;
}
// CreateBigintWords注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateBigintWords},
};
static JSVM_CallbackStruct *method = param;
// CreateBigintWords方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createBigintWords", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char* srcCallNative = R"JS(createBigintWords())JS";
```
<!-- @[oh_jsvm_create_bigint_words](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutBigint/createbigintwords/src/main/cpp/hello.cpp) -->

预期的输出结果
```ts
JSVM OH_JSVM_CreateBigintWords success
```

### OH_JSVM_CreateBigintUint64

根据给定的Uint64类型对象创建JavaScript BigInt对象。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// 声明uint64_t的变量value
static uint64_t TEST_VALUE = 5555555555555555555;
// OH_JSVM_CreateBigintUint64的样例方法
static JSVM_Value CreateBigintUint64(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 将value转化为JSVM_Value类型返回
    JSVM_Value returnValue = nullptr;
    JSVM_Status status = OH_JSVM_CreateBigintUint64(env, TEST_VALUE, &returnValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateBigintUint64 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CreateBigintUint64 success");
    }
    return returnValue;
}
// CreateBigintUint64注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateBigintUint64},
};
static JSVM_CallbackStruct *method = param;
// CreateBigintUint64方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createBigintUint64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char* srcCallNative = R"JS(createBigintUint64())JS";
```
<!-- @[oh_jsvm_create_bigint_uint64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutBigint/createbigintuint64/src/main/cpp/hello.cpp) -->

预期的输出结果
```ts
JSVM OH_JSVM_CreateBigintUint64 success

```

### OH_JSVM_GetValueBigintUint64

获取给定JavaScript BigInt的Uint64_t基础类型值。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_GetValueBigintUint64的样例方法
static JSVM_Value GetValueBigintUint64(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 从参数值中获取BigInt的数值
    uint64_t value = 0;
    bool lossLess = false;
    OH_JSVM_GetValueBigintUint64(env, args[0], &value, &lossLess);
    // 判断从JS侧获取bigint是否为无损转换，如果不是抛出异常
    if (!lossLess) {
        OH_JSVM_ThrowError(env, nullptr, "BigInt values have no lossless converted");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueBigintUint64 success");
    }
    JSVM_Value returnValue = nullptr;
    OH_JSVM_CreateBigintUint64(env, value, &returnValue);
    return returnValue;
}
// GetValueBigintUint64注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueBigintUint64},
};
static JSVM_CallbackStruct *method = param;
// GetValueBigintUint64方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueBigintUint64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char* srcCallNative = R"JS(getValueBigintUint64(BigInt(5555555555555555)))JS";
```
<!-- @[oh_jsvm_get_value_bigint_uint64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutBigint/getvaluebigintuint64/src/main/cpp/hello.cpp) -->

预期的输出结果
```ts
JSVM GetValueBigintUint64 success
```

### OH_JSVM_CreateBigintInt64

根据给定的Uint64类型对象创建JavaScript BigInt对象。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// 声明int64_t的变量value
static int64_t TEST_VALUE_DEMO = -5555555555555555555;
// OH_JSVM_CreateBigintInt64的样例方法
static JSVM_Value CreateBigintInt64(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Value returnValue = nullptr;
    JSVM_Status status = OH_JSVM_CreateBigintInt64(env, TEST_VALUE_DEMO, &returnValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateBigintInt64 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CreateBigintInt64 success");
    }
    return returnValue;
}
// CreateBigintInt64注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateBigintInt64},
};
static JSVM_CallbackStruct *method = param;
// CreateBigintInt64方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createBigintInt64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char* srcCallNative = R"JS(createBigintInt64())JS";
```
<!-- @[oh_jsvm_create_bigint_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutBigint/createbigintint64/src/main/cpp/hello.cpp) -->

预期的输出结果
```ts
JSVM OH_JSVM_CreateBigintInt64 success
```

### OH_JSVM_GetValueBigintInt64

用于从传入的参数中提取64位整数的BigInt数据，以供后续处理。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_GetValueBigintInt64的样例方法
static JSVM_Value GetBigintInt64(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 从传入的参数中提取64位整数的BigInt数据
    int64_t value = 0;
    bool lossLess = false;
    OH_JSVM_GetValueBigintInt64(env, args[0], &value, &lossLess);
    // 判断从JS侧获取bigint是否为无损转换，如果不是抛出异常
    if (!lossLess) {
        OH_JSVM_ThrowError(env, nullptr, "BigInt values have no lossless converted");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetBigintInt64 success");
    }
    JSVM_Value returnValue = nullptr;
    OH_JSVM_CreateBigintInt64(env, value, &returnValue);
    return returnValue;
}
// GetBigintInt64注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetBigintInt64},
};
static JSVM_CallbackStruct *method = param;
// GetBigintInt64方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getBigintInt64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char* srcCallNative = R"JS(getBigintInt64(BigInt(-5555555555555555)))JS";
```
<!-- @[oh_jsvm_get_value_bigint_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutBigint/getvaluebigintint64/src/main/cpp/hello.cpp) -->

预期的输出结果
```ts
JSVM GetValueBigintUint64 success
```
