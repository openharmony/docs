# Triggering GC Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Introduction

JSVM-API provides the capability of registering callback functions to monitor the memory GC of the JavaScript VM. You can add custom logic before and after garbage collection to perform optimization, debugging, or performance monitoring during garbage collection.

## Basic Concepts

In JS, GC is automatically performed, and users are not aware of the GC behavior of the JSVM. The JS engine enters the prologue phase before each GC, and enters the epilogue phase after each GC. The prologue is the setup phase before the actual GC begins. In this phase, the system prepares for GC. The epilogue is the cleanup phase after the GC. It ensures that the memory is restored to the normal state and ready for the next allocation. In these two phases, the JS engine calls the callbacks registered. You can suspend some tasks, record the memory usage, and optimize performance in the callbacks registered in the prologue phase, and record the memory status after GC and start subsequent tasks in the callbacks registered in the epilogue phase.

JSVM-API provides the **OH_JSVM_AddHandlerForGC** API for registering a callback with a JSVM. You can pass in **JSVM_CB_TRIGGER_BEFORE_GC** to specify the callback in the prologue phase, and pass in **JSVM_CB_TRIGGER_AFTER_GC** to specify the callback in the epilogue phase. You can use **OH_JSVM_RemoveHandlerForGC** to remove a registered callback from a JSVM.

## Available APIs

| API                      | Description                           |
|----------------------------|-------------------------------------|
| OH_JSVM_AddHandlerForGC         | Registers a callback with a JSVM.|
| OH_JSVM_RemoveHandlerForGC   | Removes a registered callback from a JSVM.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in GC management.

### OH_JSVM_AddHandlerForGC & OH_JSVM_RemoveHandlerForGC

You can call **OH_JSVM_AddHandlerForGC** multiple times to register callbacks with a JSVM, and all registered callbacks will take effect. During registration, the callback function pointer and native-data are used as keys. If the same key exists in multiple registrations, the registration is invalid and the error code JSVM_INVALID_ARG is returned. Under the same triggering condition, the callback sequence of the callback function is not strictly consistent with the registration sequence.
You can use **OH_JSVM_RemoveHandlerForGC** to remove a registered callback from a JSVM. Removing callbacks with the same key will be considered an invalid removal, and the **JSVM_INVALID_ARG** error will be returned.

CPP code:

```cpp
// hello.cpp
#include <iostream>

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
    // Register two callbacks to be called before GC.
    int data = 2024;
    JSVM_CALL(OH_JSVM_AddHandlerForGC(vm, JSVM_CB_TRIGGER_BEFORE_GC, OnBeforeGC, JSVM_GC_TYPE_ALL, NULL));
    JSVM_CALL(OH_JSVM_AddHandlerForGC(vm, JSVM_CB_TRIGGER_BEFORE_GC, OnBeforeGC2, JSVM_GC_TYPE_ALL, (void*)(&data)));
    // Register two callbacks to be called after GC.
    JSVM_CALL(OH_JSVM_AddHandlerForGC(vm, JSVM_CB_TRIGGER_AFTER_GC, OnAfterGC, JSVM_GC_TYPE_ALL, NULL));
    JSVM_CALL(OH_JSVM_AddHandlerForGC(vm, JSVM_CB_TRIGGER_AFTER_GC, OnAfterGC2, JSVM_GC_TYPE_ALL, NULL));
    // The registration is invalid because (OnAfterGC2, NULL) has been registered.
    if (OH_JSVM_AddHandlerForGC(vm, JSVM_CB_TRIGGER_AFTER_GC, OnAfterGC2, JSVM_GC_TYPE_ALL, NULL) == JSVM_INVALID_ARG) {
        add_repeated = true;
    }
    // Remove the OnAfter2 callback.
    JSVM_CALL(OH_JSVM_RemoveHandlerForGC(vm, JSVM_CB_TRIGGER_AFTER_GC, OnAfterGC2, NULL));
    // Repeated removal of OnAfter2 is invalid.
    if (OH_JSVM_RemoveHandlerForGC(vm, JSVM_CB_TRIGGER_AFTER_GC, OnAfterGC2, NULL) == JSVM_INVALID_ARG) {
        remove_repeated = true;
    }
    // Removing a callback that has never been registered is invalid.
    if (OH_JSVM_RemoveHandlerForGC(vm, JSVM_CB_TRIGGER_AFTER_GC, OnAfterGC3, NULL) == JSVM_INVALID_ARG) {
        remove_notAdded = true;
    }
    // Notify the system when the JSVM is under high memory pressure, which is likely to trigger GC of the JSVM.
    JSVM_CALL(OH_JSVM_MemoryPressureNotification(env, JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL));
    if ((before_flag1) &&
        (before_flag2) &&
        (after_flag1) &&
        (!after_flag2) &&
        (remove_repeated) &&
        (remove_notAdded) &&
        (add_repeated)) {
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
JS Example
```cpp
const char *srcCallNative = R"JS(triggerGC();)JS";
```
**Execution result**

The following information is displayed in the log:
```cpp
== before GC ==
gc type: 4
gc flag: 4
== before GC2 ==
gc type: 4
gc flag: 4
data: 2024
JSVM Trigger GC: success
```
