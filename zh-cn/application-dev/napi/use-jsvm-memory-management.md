# 使用JSVM-API进行内存管理

## 简介

JSVM-API提供了一组用于管理JavaScript虚拟机内存的API，可以更好地控制JavaScript代码使用的内存，并优化内存管理和垃圾回收机制。

## 基本概念

在JavaScript中，内存管理和垃圾回收是自动进行的。JavaScript虚拟机负责跟踪对象的分配和释放，并在必要时回收不再使用的内存。但是，在某些情况下，JSVM可能会消耗大量的内存，这可能会导致内存不足的错误。为了避免这种情况，JSVM-API提供了一些接口，以便更好地控制内存管理和垃圾回收机制。

## 接口说明

| 接口                       | 功能说明                            |
|----------------------------|-------------------------------------|
| OH_JSVM_AdjustExternalMemory         | 用于管理由JavaScript对象持有的外部分配内存|
| OH_JSVM_MemoryPressureNotification   | 通知虚拟机系统内存不足并有选择地触发垃圾回收|

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### OH_JSVM_AdjustExternalMemory

设置JavaScript对象保持活动状态的外部分配内存的数量

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_AdjustExternalMemory的样例方法
static JSVM_Value AdjustExternalMemory(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 分配1MB的内存
    int64_t change = 1024 * 1024;
    int64_t adjustedValue = 0;
    JSVM_Status status = OH_JSVM_AdjustExternalMemory(env, change, &adjustedValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_AdjustExternalMemory: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_AdjustExternalMemory: success");
        OH_LOG_INFO(LOG_APP, "JSVM Allocate memory size: %{public}d", adjustedValue);
    }
    JSVM_Value checked;
    OH_JSVM_GetBoolean(env, true, &checked);
    return checked;
}
// AdjustExternalMemory注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = AdjustExternalMemory},
};
static JSVM_CallbackStruct *method = param;
// AdjustExternalMemory方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"adjustExternalMemory", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
```

// 样例测试JS

```c++
const char *srcCallNative = R"JS(adjustExternalMemory())JS";
```
<!-- @[oh_jsvm_adjust_external_memory](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/UsageInstructionsTwo/adjustexternalmemory/src/main/cpp/hello.cpp) -->
输出结果：
在LOG中输出以下信息：
JSVM OH_JSVM_AdjustExternalMemory: success
JSVM Allocate memory size: 1048576

### OH_JSVM_MemoryPressureNotification

通知虚拟机系统内存不足并有选择地触发垃圾回收

cpp部分代码：

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_MemoryPressureNotification的样例方法
static JSVM_Value MemoryPressureNotification(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 设置当前JSVM的内存压力级别
    JSVM_Status status = OH_JSVM_MemoryPressureNotification(env, JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_MemoryPressureNotification: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_MemoryPressureNotification: success");
        OH_LOG_INFO(LOG_APP, "JSVM Current JSVM memory pressure level: %{public}d", JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL);
    }
    return nullptr;
}
// MemoryPressureNotification注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = MemoryPressureNotification},
};
static JSVM_CallbackStruct *method = param;
// MemoryPressureNotification方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"memoryPressureNotification", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
```

// 样例测试JS

```c++
const char *srcCallNative = R"JS(memoryPressureNotification())JS";
```
<!-- @[oh_jsvm_memory_pressure_notification](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/UsageInstructionsTwo/memorypressurenotification/src/main/cpp/hello.cpp) -->
输出结果：
在LOG中输出以下信息：
JSVM OH_JSVM_MemoryPressureNotification: success
JSVM Current JSVM memory pressure level: 2