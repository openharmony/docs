# 使用JSVM-API接口进行ArrayBuffer相关开发

## 简介

ArrayBuffer 是 JavaScript 中的一种数据类型，用于表示通用的、固定长度的原始二进制数据缓冲区。它提供了一种在 JavaScript 中有效地表示和操作原始二进制数据的方式。

## 基本概念

- **ArrayBuffer**：ArrayBuffer 对象用来表示一个通用的、固定长度的原始二进制数据缓冲区。不能直接操作 ArrayBuffer 的内容，而是需要通过包装成 TypedArray 对象或 DataView 对象来读写。ArrayBuffer 常用于处理大量的二进制数据，如文件、网络数据包等。
- **生命周期和内存管理**：在使用 JSVM 处理 ArrayBuffer 时，需要特别注意生命周期和内存管理。

## 接口说明

| 接口                         | 功能说明                                   |
| ---------------------------- | ------------------------------------------ |
| OH_JSVM_GetArraybufferInfo    | 检索 ArrayBuffer 的底层数据缓冲区及其长度。 |
| OH_JSVM_IsArraybuffer        | 判断一个 JavaScript 对象是否为 ArrayBuffer 类型对象。        |
| OH_JSVM_DetachArraybuffer    | 调用 ArrayBuffer 对象的 Detach 操作。            |
| OH_JSVM_IsDetachedArraybuffer | 检查给定的 ArrayBuffer 是否已被分离(detached)。        |
| OH_JSVM_CreateArraybuffer      | 创建一个指定大小的 ArrayBuffer 对象。   |

## 使用示例

JSVM-API 接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应 C++ 相关代码进行展示。

### OH_JSVM_GetArraybufferInfo

检索 ArrayBuffer 的底层数据缓冲区及其长度。

cpp 部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_GetArraybufferInfo的样例方法
static JSVM_Value GetArraybufferInfo(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    // 解析传递的参数
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 检查参数是否为ArrayBuffer
    bool isArrayBuffer = false;
    OH_JSVM_IsArraybuffer(env, args[0], &isArrayBuffer);
    if (!isArrayBuffer) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetArraybufferInfo isArrayBuffer:false");
    }
    void *data;
    size_t byteLength;
    // 获取ArrayBuffer的底层数据缓冲区和长度
    JSVM_Status status = OH_JSVM_GetArraybufferInfo(env, args[0], &data, &byteLength);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetArraybufferInfo: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetArraybufferInfo: success");
    }
    return args[0];
}
// GetArraybufferInfo注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetArraybufferInfo},
};
static JSVM_CallbackStruct *method = param;
// GetArraybufferInfo方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getArraybufferInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(
getArraybufferInfo(new ArrayBuffer(10));
)JS";
```
<!-- @[oh_jsvm_get_arraybuffer_info](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/JSVMAPI/JsvmUsageGuide/JsvmAboutArraybuffer/getarraybufferinfo/src/main/cpp/hello.cpp) -->

### OH_JSVM_IsArraybuffer

判断一个 JavaScript 对象是否为 Arraybuffer 类型对象。

cpp 部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_IsArraybuffer的样例方法
static JSVM_Value IsArrayBuffer(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 调用OH_JSVM_IsArraybuffer接口判断给定入参是否为ArrayBuffer数据
    bool isArrayBuffer = false;
    JSVM_Status status = OH_JSVM_IsArraybuffer(env, args[0], &isArrayBuffer);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsArrayBuffer: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM IsArrayBuffer: success");
        OH_LOG_INFO(LOG_APP, "JSVM IsArrayBuffer: %{public}d", isArrayBuffer);
    }
    JSVM_Value boolean = nullptr;
    OH_JSVM_GetBoolean(env, isArrayBuffer, &boolean);
    return boolean;
}
// IsArrayBuffer注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsArrayBuffer},
};
static JSVM_CallbackStruct *method = param;
// IsArrayBuffer方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"isArrayBuffer", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(
isArrayBuffer(new ArrayBuffer(8));
)JS";
```
<!-- @[oh_jsvm_is_arraybuffer](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/JSVMAPI/JsvmUsageGuide/JsvmAboutArraybuffer/isarraybuffer/src/main/cpp/hello.cpp) -->

### OH_JSVM_DetachArraybuffer

调用 ArrayBuffer 对象的 Detach 操作。

### OH_JSVM_IsDetachedArraybuffer

检查给定的 ArrayBuffer 是否已被分离。

cpp 部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_DetachArraybuffer、OH_JSVM_IsDetachedArraybuffer的样例方法
static JSVM_Value DetachArraybuffer(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value arraybuffer = args[0];
    JSVM_Status status = OH_JSVM_DetachArraybuffer(env, arraybuffer);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM DetachArraybuffer: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM DetachArraybuffer: success");
    }
    return arraybuffer;
}
static JSVM_Value IsDetachedArraybuffer(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value arraybuffer = args[0];
    OH_JSVM_DetachArraybuffer(env, arraybuffer);
    bool result = false;
    JSVM_Status status = OH_JSVM_IsDetachedArraybuffer(env, arraybuffer, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsDetachedArraybuffer: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM IsDetachedArraybuffer: success");
        OH_LOG_INFO(LOG_APP, "JSVM IsArrayBuffer: %{public}d", result);
    }
    JSVM_Value isDetached = nullptr;
    OH_JSVM_GetBoolean(env, result, &isDetached);
    return isDetached;
}
// DetachArraybuffer、IsDetachedArraybuffer注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = DetachArraybuffer},
    {.data = nullptr, .callback = IsDetachedArraybuffer},
};
static JSVM_CallbackStruct *method = param;
// DetachArraybuffer、IsDetachedArraybuffer方法别名，TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"detachArraybuffer", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"isDetachedArraybuffer", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(
let arrayBuffer = new ArrayBuffer(10);
detachArraybuffer(arrayBuffer);
isDetachedArraybuffer(arrayBuffer);
)JS";
```
<!-- @[oh_jsvm_is_detached_arraybuffer](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/JSVMAPI/JsvmUsageGuide/JsvmAboutArraybuffer/isdetachedarraybuffer/src/main/cpp/hello.cpp) -->

### OH_JSVM_CreateArraybuffer

创建一个指定大小的 ArrayBuffer 对象。

cpp 部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_CreateArraybuffer的样例方法
static JSVM_Value CreateArraybuffer(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    JSVM_Value result = nullptr;
    // 解析传递的参数
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    int32_t value = 0;
    size_t length = 0;
    OH_JSVM_GetValueInt32(env, argv[0], &value);
    length = size_t(value);
    void *data;
    // 创建一个新的ArrayBuffer
    JSVM_Status status = OH_JSVM_CreateArraybuffer(env, length, &data, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateArraybuffer: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM CreateArraybuffer: success");
        OH_LOG_INFO(LOG_APP, "JSVM ArrayBuffer length: %{public}d", length);
    }
    // 返回创建好的ArrayBuffer
    return result;
}
// CreateArraybuffer注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateArraybuffer},
};
static JSVM_CallbackStruct *method = param;
// CreateArraybuffer方法别名，供TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createArraybuffer", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// 样例测试js
const char *srcCallNative = R"JS(
createArraybuffer(8);
)JS";
```
<!-- @[oh_jsvm_create_arraybuffer](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/JSVMAPI/JsvmUsageGuide/JsvmAboutArraybuffer/createarraybuffer/src/main/cpp/hello.cpp) -->
