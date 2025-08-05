# 使用JSVM-API接口创建基本数据类型
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @huanghan18; @suyuehhh; @KasonChan; @string_sz; @diking-->
<!--SE: @knightaoko-->
<!--TSE: @test_lzz-->

## 简介

在JavaScript中，整数类型是一种基本数据类型，用于表示没有小数部分的数值。Double类型用于表示有小数的数值。JavaScript的数值存储方式会导致在某些情况下无法准确表示非常大或非常小的数值，在这种情况下，需要使用BigInt对应的JSVM-API接口来处理更大范围的整数。

## 基本概念

当使用JSVM-API接口进行数值类型的创建和获取时，需要了解以下基本概念：

- **数值类型** 在使用JSVM-API接口时，可能需要从JSVM模块数值类型转换为JavaScript数值类型，或者从JavaScript数值类型转换为JSVM模块数值类型。在进行数据类型转换时，需要注意数据范围是否匹配，以及有无符号整数和双精度数值等区别。
- **错误处理** 在使用这些接口时，需要对可能发生的错误进行适当处理。例如，在创建整数值时可能发生内存分配错误或其他运行时错误，需要使用JSVM-API提供的错误处理机制来捕获并处理这些错误。
- **JavaScript交互** 在开发过程中，需要考虑如何将创建的数值类型值与JavaScript环境进行交互，包括传递参数、返回值等。

## 接口说明

| 接口                  | 功能说明                                        |
| --------------------- | -----------------------------------------------|
| OH_JSVM_GetValueUint32 | 获取给定JavaScript number的Uint32基础类型值。   |
| OH_JSVM_GetValueInt32  | 获取给定JavaScript number的Int32基础类型值。    |
| OH_JSVM_GetValueInt64  | 获取给定JavaScript number的Int64基础类型值。    |
| OH_JSVM_GetValueDouble | 获取给定JavaScript number的Double基础类型值。   |
| OH_JSVM_CreateInt32     | 根据Int32_t类型对象创建JavaScript number对象。 |
| OH_JSVM_CreateUint32    | 根据Uint32_t类型对象创建JavaScript number对象。|
| OH_JSVM_CreateInt64     | 根据Int64_t类型对象创建JavaScript number对象。 |
| OH_JSVM_CreateDouble    | 根据Double类型对象创建JavaScript number对象。  |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### OH_JSVM_GetValueUint32

将JavaScript value转为JSVM模块中的uint32类型数据。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// OH_JSVM_GetValueUint32的样例方法
static JSVM_Value GetValueUint32(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 获取传入的数字类型参数
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    // 解析传入的参数
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    uint32_t number = 0;
    // 获取传入参数的值中的无符号32位整数
    JSVM_Status status = OH_JSVM_GetValueUint32(env, argv[0], &number);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueUint32 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueUint32 success: %{public}u", number);
    }
    return argv[0];
}

// GetValueUint32注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueUint32},
};
static JSVM_CallbackStruct *method = param;

// GetValueUint32方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueUint32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char* srcCallNative = R"JS(getValueUint32(123))JS";
```
<!-- @[oh_jsvm_get_value_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/getvalueuint32/src/main/cpp/hello.cpp) -->

预期的输出结果：

```
JSVM GetValueUint32 success: 123
```

### OH_JSVM_GetValueInt32

将JavaScript value转为JSVM模块中的Int32类型数据。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// OH_JSVM_GetValueInt32的样例方法
static JSVM_Value GetValueInt32(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    int32_t result32 = 0;
    // 解析传递的参数
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 将前端传过来的参数转为JSVM模块的int32类型
    JSVM_Status status = OH_JSVM_GetValueInt32(env, args[0], &result32);
    if (status != JSVM_OK) {
        return nullptr;
    }
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueInt32 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueInt32 success: %{public}d", result32);
    }
    return args[0];
}

// GetValueInt32注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueInt32},
};
static JSVM_CallbackStruct *method = param;
// GetValueInt32方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueInt32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char* srcCallNative = R"JS(getValueInt32(-123))JS";
```
<!-- @[oh_jsvm_get_value_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/getvalueint32/src/main/cpp/hello.cpp) -->

预期的输出结果：

```
JSVM GetValueInt32 success: -123
```

### OH_JSVM_GetValueInt64

将JavaScript value转为JSVM模块中的Int64类型数据。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// OH_JSVM_GetValueInt64的样例方法
static JSVM_Value GetValueInt64(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    int64_t result64 = 0;
    // 解析传递的值
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 将前端传过来的参数分别转为JSVM模块的int64类型
    JSVM_Status status = OH_JSVM_GetValueInt64(env, args[0], &result64);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueInt64 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueInt64 success: %{public}ld", result64);
    }
    return args[0];
}

// GetValueInt64注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueInt64},
};
static JSVM_CallbackStruct *method = param;
// GetValueInt64方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueInt64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char* srcCallNative = R"JS(getValueInt64(-123))JS";
```
<!-- @[oh_jsvm_get_value_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/getvalueint64/src/main/cpp/hello.cpp) -->

预期的输出结果：

```
JSVM GetValueInt64 success: -123
```

### OH_JSVM_GetValueDouble

将JavaScript value转为JSVM模块中的double类型数据。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// OH_JSVM_GetValueDouble的样例方法
static JSVM_Value GetDouble(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    double value = 0;
    JSVM_Status status = OH_JSVM_GetValueDouble(env, args[0], &value);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetDouble fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetDouble success: %{public}f", value);
    }
    return args[0];
}

// GetDouble注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetDouble},
};
static JSVM_CallbackStruct *method = param;
// GetDouble方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getDouble", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char* srcCallNative = R"JS(getDouble(-110.0456))JS";
```
<!-- @[oh_jsvm_get_value_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/getvaluedouble/src/main/cpp/hello.cpp) -->

预期的输出结果：

```
JSVM GetDouble success: -110.045600
```

### OH_JSVM_CreateInt32

根据int32_t数据创建JavaScript number对象。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// OH_JSVM_CreateInt32的样例方法
static JSVM_Value CreateInt32(JSVM_Env env, JSVM_CallbackInfo info)
{
    int32_t value = -20;
    // 创建JavaScript中的int32数字
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateInt32(env, value, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateInt32 fail");
    } else {
        int32_t number = 0;
        OH_JSVM_GetValueInt32(env, result, &number);
        OH_LOG_INFO(LOG_APP, "JSVM CreateInt32 success: %{public}d", number);
    }
    return result;
}

// CreateInt32注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateInt32},
};
static JSVM_CallbackStruct *method = param;
// CreateInt32方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createInt32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char* srcCallNative = R"JS(createInt32())JS";
```
<!-- @[oh_jsvm_create_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/createint32/src/main/cpp/hello.cpp) -->

预期的输出结果：

```
JSVM CreateInt32 success: -20
```

### OH_JSVM_CreateUint32

根据uint32_t数据创建JavaScript number对象。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// OH_JSVM_CreateUint32的样例方法
static JSVM_Value CreateUInt32(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 如果使用
    // uint32_t类型来定义-26，会发生溢出，溢出时会对结果进行模运算，将负数的二进制补码转换为相应的正数。-26输出4294967270
    // uint32_t是无符号的32位整数类型，只能表示非负整数。它的范围是从0到2 ^32 - 1，即0到4294967295
    // 要表示的整数值
    uint32_t value = 26;
    // 创建JavaScript中的uint32数字
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateUint32(env, value, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateUInt32 fail");
    } else {
        uint32_t number = 0;
        OH_JSVM_GetValueUint32(env, result, &number);
        OH_LOG_INFO(LOG_APP, "JSVM CreateUInt32 success: %{public}u", number);
    }
    return result;
}

// CreateUInt32注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateUInt32},
};
static JSVM_CallbackStruct *method = param;
// CreateUInt32方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createUInt32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char* srcCallNative = R"JS(createUInt32())JS";
```
<!-- @[oh_jsvm_create_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/createuint32/src/main/cpp/hello.cpp) -->

预期的输出结果：

```
JSVM CreateUInt32 success: 26
```

### OH_JSVM_CreateInt64

根据int64_t数据创建JavaScript number对象。如果需要表示JS超大数，建议使用BigInt接口。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

// OH_JSVM_CreateInt64的样例方法
static JSVM_Value CreateInt64(JSVM_Env env, JSVM_CallbackInfo info)
{
    int64_t value = 2147483648;
    // 创建JavaScript中的int64数字
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateInt64(env, value, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateInt64 fail");
    } else {
        int64_t number = 0;
        OH_JSVM_GetValueInt64(env, result, &number);
        OH_LOG_INFO(LOG_APP, "JSVM CreateInt64 success: %{public}ld", number);
    }
    return result;
}

// CreateInt64注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateInt64},
};
static JSVM_CallbackStruct *method = param;
// CreateInt64方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createInt64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char* srcCallNative = R"JS(createInt64())JS";
```
<!-- @[oh_jsvm_create_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/createint64/src/main/cpp/hello.cpp) -->

预期的输出结果：

```
JSVM CreateInt64 success: 2147483648
```

### OH_JSVM_CreateDouble

根据double数据创建JavaScript number对象。

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// CreateDouble注册回调

// OH_JSVM_CreateDouble的样例方法
static JSVM_Value CreateDouble(JSVM_Env env, JSVM_CallbackInfo info)
{
    double value = 1.234;
    // 创建JavaScript中的double数字
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateDouble(env, value, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateDouble fail");
    } else {
        double number = 0;
        OH_JSVM_GetValueDouble(env, result, &number);
        OH_LOG_INFO(LOG_APP, "JSVM CreateDouble success: %{public}f", number);
    }
    return result;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateDouble},
};
static JSVM_CallbackStruct *method = param;
// CreateDouble方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createDouble", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char* srcCallNative = R"JS(createDouble())JS";
```
<!-- @[oh_jsvm_create_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmBasicDataTypes/createdouble/src/main/cpp/hello.cpp) -->

预期的输出结果：

```
JSVM CreateDouble success: 1.234000
```
