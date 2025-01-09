# 使用JSVM-API感知JSVM引擎生命周期管理

## 简介

JSVM-API提供了用于监测JavaScript虚拟机内存GC的回调函数注册能力。允许开发者在垃圾回收开始之前或者垃圾回收结束之后添加自定义逻辑，帮助开发者在垃圾回收时，执行一些优化、调试或者性能监控操作。

## 基本概念

在JavaScript中，内存的垃圾回收是自动进行的，用户并不直接感知JavaScript虚拟机的GC行为。每次GC执行之前，JS引擎会先进入一个"Prologue"阶段。每次GC执行之后，JS引擎会进入一个"Epilogue"阶段。"Prologue"阶段是GC的初始阶段，主要目标是做一些准备工作，以确保垃圾回收能够顺利进行。"Epilogue"阶段则是垃圾回收的最终清理和整理，确保内存恢复到一个正常的状态，并为下一次分配做好准备。在这两个阶段，JS引擎会分别调用用户提前注册的函数。用户可以在"Prologue"阶段所执行的注册函数中暂停某些任务、记录内存使用情况、执行性能调优等。在"Epilogue"阶段所执行的注册函数中，也可以去记录GC后的内存状态、启动后续的任务等等。

JSVM-API提供了OH_JSVM_AddHandlerForGC接口，可以在VM中注册回调函数。通过传入JSVM_CB_TRIGGER_BEFORE_GC来控制回调函数在"Prologue"阶段执行；通过传入JSVM_CB_TRIGGER_AFTER_GC来控制回调函数在"Epilogue"阶段执行。通过OH_JSVM_RemoveHandlerForGC，可以从VM中移除注册过的回调函数。

## 接口说明

| 接口                       | 功能说明                            |
|----------------------------|-------------------------------------|
| OH_JSVM_AddHandlerForGC         | 用于向VM中注册回调函数|
| OH_JSVM_RemoveHandlerForGC   | 用于从VM中移除注册过的回调函数|

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### OH_JSVM_AddHandlerForGC & OH_JSVM_RemoveHandlerForGC

可以多次调用OH_JSVM_AddHandlerForGC向VM中注册回调函数，并且所注册的回调函数都会生效。注册行为以回调函数指针和native-data作为key，如果多次注册行为存在相同的key，则会判定为无效注册，并返回JSVM_INVALID_ARG错误码。在相同触发条件下，回调函数的回调顺序与回调函数的注册顺序并不严格一致。
通过OH_JSVM_RemoveHandlerForGC可以从VM中移除注册过的回调函数。重复移除具有相同key的回调函数，则会判定为无效移除，并返回JSVM_INVALID_ARG错误码。

#### cpp部分代码

```cpp
// hello.cpp
#include <iostream>

#include "jsvmtest.h"

static bool before_flag1 = false;
static bool before_flag2 = false;
static bool after_flag1 = false;
static bool after_flag2 = false;

void OnBeforeGC(JSVM_VM vm, JSVM_GCType gcType, JSVM_GCCallbackFlags flags, void *data)
{
    OH_LOG_INFO(LOG_APP, "== before GC ==");
    OH_LOG_INFO(LOG_APP, "gc type: %{public}d", gcType);
    OH_LOG_INFO(LOG_APP, "gc flag: %{public}d", flags);
    before_flag1 = true;
}

void OnBeforeGC2(JSVM_VM vm, JSVM_GCType gcType, JSVM_GCCallbackFlags flags, void *data)
{
    OH_LOG_INFO(LOG_APP, "== before GC2 ==");
    OH_LOG_INFO(LOG_APP, "gc type: %{public}d", gcType);
    OH_LOG_INFO(LOG_APP, "gc flag: %{public}d", flags);
    OH_LOG_INFO(LOG_APP, "data: %{public}d", *(int*)data);
    if (*(int*)data == 2024) {
        before_flag2 = true;
    }
}

void OnAfterGC(JSVM_VM vm, JSVM_GCType gcType, JSVM_GCCallbackFlags flags, void *data)
{
    after_flag1 = true;
}

void OnAfterGC2(JSVM_VM vm, JSVM_GCType gcType, JSVM_GCCallbackFlags flags, void *data)
{
    after_flag2 = true;
}

void OnAfterGC3(JSVM_VM vm, JSVM_GCType gcType, JSVM_GCCallbackFlags flags, void *data)
{
    after_flag2 = true;
}

static JSVM_Value TriggerGC(JSVM_Env env, JSVM_CallbackInfo info)
{
    bool remove_repeated = false;
    bool remove_notAdded = false;
    bool add_repeated = false;
    before_flag1 = false;
    before_flag2 = false;
    after_flag1 = false;
    after_flag2 = false;
    JSVM_VM vm;
    OH_JSVM_GetVM(env, &vm);
    // 设置两个回调函数，在GC执行之前触发回调
    int data = 2024;
    JSVM_CALL(OH_JSVM_AddHandlerForGC(vm, JSVM_CB_TRIGGER_BEFORE_GC, OnBeforeGC, JSVM_GC_TYPE_ALL, NULL));
    JSVM_CALL(OH_JSVM_AddHandlerForGC(vm, JSVM_CB_TRIGGER_BEFORE_GC, OnBeforeGC2, JSVM_GC_TYPE_ALL, (void*)(&data)));
    // 设置两个回调函数，在GC执行之后触发回调
    JSVM_CALL(OH_JSVM_AddHandlerForGC(vm, JSVM_CB_TRIGGER_AFTER_GC, OnAfterGC, JSVM_GC_TYPE_ALL, NULL));
    JSVM_CALL(OH_JSVM_AddHandlerForGC(vm, JSVM_CB_TRIGGER_AFTER_GC, OnAfterGC2, JSVM_GC_TYPE_ALL, NULL));
    // (OnAfterGC2, NULL)的组合已经注册过了，重复注册为无效行为
    if (OH_JSVM_AddHandlerForGC(vm, JSVM_CB_TRIGGER_AFTER_GC, OnAfterGC2, JSVM_GC_TYPE_ALL, NULL) == JSVM_INVALID_ARG) {
        add_repeated = true;
    }
    // 移除OnAfter2回调函数
    JSVM_CALL(OH_JSVM_RemoveHandlerForGC(vm, JSVM_CB_TRIGGER_AFTER_GC, OnAfterGC2, NULL));
    // 重复移除OnAfter2属于无效用法
    if (OH_JSVM_RemoveHandlerForGC(vm, JSVM_CB_TRIGGER_AFTER_GC, OnAfterGC2, new int(12)) == JSVM_INVALID_ARG) {
        remove_repeated = true;
    }
    // 移除从未设置过的函数属于无效用法
    if (OH_JSVM_RemoveHandlerForGC(vm, JSVM_CB_TRIGGER_AFTER_GC, OnAfterGC3, NULL) == JSVM_INVALID_ARG) {
        remove_notAdded = true;
    }
    // 通知引擎当前存在比较大的内存压力，能大概率触发JS引擎的GC流程。
    JSVM_CALL(OH_JSVM_MemoryPressureNotification(env, JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL));
    if ((before_flag1 == true) &&
        (before_flag2 == true) &&
        (after_flag1 == true) &&
        (after_flag2 == false) &&
        (remove_repeated == true) &&
        (remove_notAdded == true) &&
        (add_repeated == true)) {
        OH_LOG_INFO(LOG_APP, "JSVM Trigger GC: success");
    } else {
        OH_LOG_ERROR(LOG_APP, "JSVM Trigger GC: failed");
    }
    JSVM_Value checked;
    OH_JSVM_GetBoolean(env, true, &checked);
    return checked;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = TriggerGC},
};
static JSVM_CallbackStruct *method = param;

static JSVM_PropertyDescriptor descriptor[] = {
    {"triggerGC", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
```
#### 样例测试JS
const char *srcCallNative = R"JS(triggerGC();)JS";

#### 执行结果
在LOG中输出下面结果：
== before GC ==
gc type: 4
gc flag: 4
== before GC2 ==
gc type: 4
gc flag: 4
data: 2024
JSVM Trigger GC: success
