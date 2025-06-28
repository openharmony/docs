# 使用JSVM-API接口进行生命周期相关开发

## 简介

在JSVM-API中，JSVM_Value是一个表示JavaScript值的抽象类型，它可以表示任何JavaScript值，包括基本类型（如数字、字符串、布尔值）和对象类型（如数组、函数、对象等）。
JSVM_Value的生命周期与JavaScript值的生命周相关。JavaScript值被垃圾回收时，JSVM_Value不再有效。不要在JavaScript值不再存在时使用JSVM_Value。

框架层的scope通常用于管理JSVM_Value的生命周期。在JSVM-API中，可以使用OH_JSVM_OpenHandleScope和OH_JSVM_CloseHandleScope函数来创建和销毁scope。通过在scope内创建JSVM_Value，可以确保在scope结束时自动释放JSVM_Value，避免内存泄漏。

JSVM_Ref是一个JSVM-API类型，用于管理JSVM_Value的生命周期。JSVM_Ref允许您在JSVM_Value的生命周期内保持对其的引用，即使它已经超出了其原始上下文的范围。这使得您可以在不同的上下文中共享JSVM_Value，并确保在不再需要时正确释放其内存。

合理使用OH_JSVM_OpenHandleScope和OH_JSVM_CloseHandleScope管理JSVM_Value的生命周期，做到生命周期最小化，避免发生内存泄漏问题。

每个JSVM_Value属于特定的HandleScope，HandleScope通过OH_JSVM_OpenHandleScope和OH_JSVM_CloseHandleScope来建立和关闭，HandleScope关闭后，所属的JSVM_Value就会自动释放。

## 基本概念

JSVM-API提供了一组功能，使开发人员能够在JSVM-API模块中创建和操作JavaScript对象，管理引用和生命周期，并注册垃圾回收回调函数等。下面是一些基本概念：

- **作用域**：用于创建一个范围，在范围内声明的引用在范围外部将不再生效。JSVM-API提供了创建、关闭普通和可逃逸的作用域的函数。
- **引用管理**：JSVM-API提供函数来创建、删除和管理对象的引用，以延长对象的生命周期，并避免在使用对象时发生内存泄漏。
- **可逃逸的作用域**：允许在创建的作用域中声明的对象返回到父作用域，通过OH_JSVM_OpenEscapableHandleScope和OH_JSVM_CloseEscapableHandleScope进行管理。
- **垃圾回收回调**：允许注册回调函数，以便在JavaScript对象被垃圾回收时执行特定的清理操作。

这些基本概念使开发人员安全且有效地操作JavaScript对象，正确管理对象的生命周期。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_OpenHandleScope     | 打开一个Handle scope，确保scope范围内的JSVM_Value不被GC回收。 |
| OH_JSVM_CloseHandleScope    | 关闭Handle scope。|
| OH_JSVM_OpenEscapableHandleScope     | 打开一个新的scope逃逸Handle scope，在关闭该scope之前创建的对象与父作用域有相同的生命周期。 |
| OH_JSVM_CloseEscapableHandleScope    | 关闭一个scope，在此scope范围外创建的对象不受父作用域保护。 |
| OH_JSVM_EscapeHandle         | 将JavaScript对象的句柄提升到外部作用域，确保在外部作用域中可以持续地使用该对象。 |
| OH_JSVM_CreateReference      | 以指定的引用计数为JavaScript对象创建一个新的引用，该引用将指向传入的对象，引用允许在不同的上下文中使用和共享对象，并且可以有效地跟踪对象的生命周期。 |
| OH_JSVM_DeleteReference      | 释放由OH_JSVM_CreateReference创建的引用，确保对象在不再被使用时能够被正确地释放和回收，避免内存泄漏。 |
| OH_JSVM_ReferenceRef         | 增加由OH_JSVM_CreateReference创建的引用的引用计数，以确保对象在有引用时不会被提前释放。 |
| OH_JSVM_ReferenceUnref       | 减少引用计数，用于管理引用计数。|
| OH_JSVM_GetReferenceValue   | 减少由OH_JSVM_CreateReference创建的引用的引用计数，以确保没有任何引用指向该对象时能正确地释放和回收。 |
| OH_JSVM_AddFinalizer          | 为对象添加JSVM_Finalize回调，以便在JavaScript对象被垃圾回收时调用来释放原生对象。|

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### OH_JSVM_OpenHandleScope、OH_JSVM_CloseHandleScope

通过接口OH_JSVM_OpenHandleScope创建一个上下文环境。需要使用OH_JSVM_CloseHandleScope进行关闭。这用于管理JavaScript对象的生命周期，确保在JSVM-API模块中处理JavaScript对象时能正确管理其句柄，避免垃圾回收相关的问题。

cpp部分代码：

```cpp
// OH_JSVM_OpenHandleScope、OH_JSVM_CloseHandleScope的三种样例方法
static JSVM_Value HandleScopeFor(JSVM_Env env, JSVM_CallbackInfo info) {
    // 在for循环中频繁调用JSVM接口创建js对象时，要加handle_scope及时释放不再使用的资源。
    // 下面例子中，每次循环结束局部变量res的生命周期已结束，因此加scope及时释放其持有的js对象，防止内存泄漏
    constexpr uint32_t DIFF_VALUE_HUNDRED_THOUSAND = 10000;
    JSVM_Value checked = nullptr;
    for (int i = 0; i < DIFF_VALUE_HUNDRED_THOUSAND; i++) {
        JSVM_HandleScope scope = nullptr;
        JSVM_Status status = OH_JSVM_OpenHandleScope(env, &scope);
        if (status != JSVM_OK || scope == nullptr) {
            OH_JSVM_GetBoolean(env, false, &checked);
            OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_OpenHandleScope: failed");
            return checked;
        }
        JSVM_Value res = nullptr;
        OH_JSVM_CreateObject(env, &res);
        status = OH_JSVM_CloseHandleScope(env, scope);
        if (status != JSVM_OK) {
            OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CloseHandleScope: failed");
        }
    }
    OH_JSVM_GetBoolean(env, true, &checked);
    OH_LOG_INFO(LOG_APP, "JSVM HandleScopeFor: success");
    return checked;
}

// HandleScopeFor注册回调
static JSVM_CallbackStruct param[] = {
    {.callback = HandleScopeFor, .data = nullptr},
};

static JSVM_CallbackStruct *method = param;
// HandleScopeFor方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"HandleScopeFor", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

const char *srcCallNative = "HandleScopeFor()";
```
<!-- @[oh_jsvm_open_handle_scope_and_oh_jsvm_close_handle_scope](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmLifeCycle/openhandlescope/src/main/cpp/hello.cpp) -->

预期输出
```
JSVM HandleScopeFor: success
```

### OH_JSVM_OpenEscapableHandleScope、OH_JSVM_CloseEscapableHandleScope、OH_JSVM_EscapeHandle

通过接口 OH_JSVM_OpenEscapableHandleScope 创建出一个可逃逸的 handel scope，可将 1 个范围内声明的值返回到父作用域。创建的 scope 需使用 OH_JSVM_CloseEscapableHandleScope 进行关闭。OH_JSVM_EscapeHandle 将传入的 JavaScript 对象的生命周期提升到其父作用域。
通过上述接口可以更灵活的使用管理传入的 JavaScript 对象，特别是在处理跨作用域的值传递时非常有用。

cpp 部分代码

```cpp
// OH_JSVM_OpenEscapableHandleScope、OH_JSVM_CloseEscapableHandleScope、OH_JSVM_EscapeHandle的样例方法
static JSVM_Value EscapableHandleScopeTest(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 创建一个可逃逸的句柄作用域
    JSVM_EscapableHandleScope scope = nullptr;
    JSVM_Status status = OH_JSVM_OpenEscapableHandleScope(env, &scope);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_OpenEscapableHandleScope: failed");
        return nullptr;
    }
    // 在可逃逸的句柄作用域内创建一个obj
    JSVM_Value obj;
    OH_JSVM_CreateObject(env, &obj);
    // 在对象中添加属性
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "Test jsvm_escapable_handle_scope", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_SetNamedProperty(env, obj, "name", value);
    // 调用OH_JSVM_EscapeHandle将对象逃逸到作用域之外
    JSVM_Value escapedObj = nullptr;
    OH_JSVM_EscapeHandle(env, scope, obj, &escapedObj);
    // 关闭可逃逸的句柄作用域，清理资源
    status = OH_JSVM_CloseEscapableHandleScope(env, scope);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CloseEscapableHandleScope: failed");
        return nullptr;
    }
    // 此时的escapedObj已逃逸，可以在作用域外继续使用escapedObj
    bool result = false;
    OH_JSVM_CreateStringUtf8(env, "name", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_HasProperty(env, escapedObj, value, &result);
    if (result) {
        OH_LOG_INFO(LOG_APP, "JSVM EscapableHandleScopeTest: success");
    }
    return escapedObj;
}

// EscapableHandleScopeTest注册回调
static JSVM_CallbackStruct param[] = {
    {.callback = EscapableHandleScopeTest, .data = nullptr},
};
static JSVM_CallbackStruct *method = param;
// EscapableHandleScopeTest方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"escapableHandleScopeTest", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

const char *srcCallNative = "escapableHandleScopeTest()";
```
<!-- @[oh_jsvm_open_escapable_handle_scope_close_escapable_handle_scope_escape_handle](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmLifeCycle/openescapablehandlescope/src/main/cpp/hello.cpp) -->

预期输出

```
JSVM EscapableHandleScopeTest: success
```

### OH_JSVM_CreateReference、OH_JSVM_DeleteReference、OH_JSVM_GetReferenceValue

1. 调用 OH_JSVM_CreateReference 为 JavaScript 变量创建一个引用，以延长其生命周期。
2. 调用 OH_JSVM_GetReferenceValue 获取与引用关联的 JavaScript 变量。
3. 调用 OH_JSVM_DeleteReference 删除传入的引用。

调用者需要自己管理引用生命周期，引用有效期间 JavaScript 变量不会被垃圾回收处理。

### OH_JSVM_ReferenceRef、OH_JSVM_ReferenceUnref

增加/减少 传入的引用的引用计数，并获取新的计数。当引用计数被置为 0 后，对于可以被设置为弱引用的 JavaScript 类型（对象、函数、外部变量），引用将被置为弱引用，在垃圾回收机制认为必要的时候该变量会被回收，当变量被回收后，调用 OH_JSVM_GetReferenceValue 会获得 C NULL；对于不可被置为弱引用的 JavaScript 类型，该引用会被清除，调用 OH_JSVM_GetReferenceValue 会获得 C NULL。

cpp部分代码：

```cpp
static JSVM_Value UseReference(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 创建 JavaScript 对象
    JSVM_Value obj = nullptr;
    OH_JSVM_CreateObject(env, &obj);
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "UseReference", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_SetNamedProperty(env, obj, "name", value);
    
    JSVM_Ref g_ref = nullptr;
    // 创建对JavaScript对象的引用
    JSVM_Status status = OH_JSVM_CreateReference(env, obj, 1, &g_ref);
    if (status != JSVM_OK) {
        return nullptr;
    }

    // 增加传入引用的引用计数并返回生成的引用计数
    uint32_t result = 0u;
    OH_JSVM_ReferenceRef(env, g_ref, &result);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_ReferenceRef, count = %{public}d.", result);
    if (result != 2) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_ReferenceRef: failed");
        return nullptr;
    }

    //  减少传入引用的引用计数并返回生成的引用计数
    uint32_t num = 0u;
    OH_JSVM_ReferenceUnref(env, g_ref, &num);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_ReferenceUnref, count = %{public}d.", num);
    if (num != 1) {
        return nullptr;
    }

    JSVM_Value object = nullptr;
    // 通过调用OH_JSVM_GetReferenceValue获取引用的JavaScript对象
    status = OH_JSVM_GetReferenceValue(env, g_ref, &object);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetReferenceValue: failed");
        return nullptr;
    }

    // 不再使用引用，通过调用OH_JSVM_DeleteReference删除对JavaScript对象的引用
    status = OH_JSVM_DeleteReference(env, g_ref);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_DeleteReference: failed");
        return nullptr;
    }

    // 将获取到的对象返回
    OH_LOG_INFO(LOG_APP, "JSVM UseReference success");
    return object;
}

// CreateReference、UseReference、DeleteReference注册回调
static JSVM_CallbackStruct param[] = {
    {.callback = UseReference, .data = nullptr},
};
static JSVM_CallbackStruct *method = param;
// CreateReference、UseReference、DeleteReference方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"useReference", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

const char *srcCallNative = "useReference()";
```
<!-- @[oh_jsvm_reference_ref_and_oh_jsvm_reference_unref](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmLifeCycle/referenceref/src/main/cpp/hello.cpp) -->

预期结果：

```
JSVM OH_JSVM_ReferenceRef, count = 2.
JSVM OH_JSVM_ReferenceUnref, count = 1.
JSVM UseReference success
```

### OH_JSVM_AddFinalizer
为 JavaScript 对象添加 JSVM_Finalize 回调，当 JavaScript 对象被垃圾回收时执行函数回调，该接口通常被用于释放与 JavaScript 对象相关的原生对象。如果传入的参数类型不是 JavaScript 对象，该接口调用失败并返回错误码。
Finalizer 方法被注册后无法取消，如果在调用 OH_JSVM_DestroyEnv 前均未被执行，则在 OH_JVSM_DestroyEnv 时执行。

cpp 部分代码

```cpp
static int AddFinalizer(JSVM_VM vm, JSVM_Env env) {
    // 打开 handlescope
    JSVM_HandleScope handleScope;
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));
    // 创建 object 并设置回调
    JSVM_Value obj;
    CHECK_RET(OH_JSVM_CreateObject(env, &obj));
    CHECK_RET(OH_JSVM_AddFinalizer(
        env, obj, nullptr,
        [](JSVM_Env env, void *data, void *hint) -> void {
            // Finalizer 方法，可在该方法中清理 Native 对象
            OH_LOG_INFO(LOG_APP, "JSVM: finalizer called.");
        },
        nullptr, nullptr));
    OH_LOG_INFO(LOG_APP, "JSVM: finalizer added.");
    // 关闭 handlescope，触发 GC，GC 时 Finalizer 会被调用
    CHECK_RET(OH_JSVM_CloseHandleScope(env, handleScope));
    OH_LOG_INFO(LOG_APP, "JSVM: before call gc.");
    CHECK_RET(OH_JSVM_MemoryPressureNotification(env, JSVM_MemoryPressureLevel::JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL));
    OH_LOG_INFO(LOG_APP, "JSVM: after call gc.");

    return 0;
}

static JSVM_Value RunDemo(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_VM vm;
    OH_JSVM_GetVM(env, &vm);
    if (AddFinalizer(vm, env) != 0) {
        OH_LOG_INFO(LOG_APP, "Run PromiseRegisterHandler failed");
    }

    return nullptr;
}

// RunDemo注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = RunDemo},
};
static JSVM_CallbackStruct *method = param;
// RunDemo方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"RunDemo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(RunDemo();)JS";
```
<!-- @[oh_jsvm_add_finalizer](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmLifeCycle/addfinalizer/src/main/cpp/hello.cpp) -->

预期结果：
```ts
JSVM: finalizer added.
JSVM: before call gc.
JSVM: finalizer called.
JSVM: after call gc.
```