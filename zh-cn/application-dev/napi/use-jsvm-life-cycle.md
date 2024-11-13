# 使用JSVM-API接口进行生命周期相关开发

## 简介

在JSVM-API中，JSVM_Value是一个表示JavaScript值的抽象类型，它可以表示任何JavaScript值，包括基本类型（如数字、字符串、布尔值）和对象类型（如数组、函数、对象等）。
JSVM_Value的生命周期与其在JavaScript中的对应值的生命周期紧密相关。当JavaScript值被垃圾回收时，与之关联的JSVM_Value也将不再有效。重要的是不要在JavaScript值不再存在时尝试使用JSVM_Value。

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

这些基本概念使开发人员能够在JSVM-API模块中安全且有效地操作JavaScript对象，并确保正确管理对象的生命周期。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_OpenHandleScope     | 打开一个Handle scope，确保scope范围内的JSVM_Value不被GC回收 |
| OH_JSVM_CloseHandleScope    | 关闭Handle scope|
| OH_JSVM_OpenEscapableHandleScope     | 打开一个新的scope逃逸Handle scope，在关闭该scope之前创建的对象与父作用域有相同的生命周期 |
| OH_JSVM_CloseEscapableHandleScope    | 关闭一个scope，在此scope范围外创建的对象不受父作用域保护 |
| OH_JSVM_EscapeHandle         | 将JavaScript对象的句柄提升到外部作用域，确保在外部作用域中可以持续地使用该对象 |
| OH_JSVM_CreateReference      | 以指定的引用计数为JavaScript对象创建一个新的引用，该引用将指向传入的对象，引用允许在不同的上下文中使用和共享对象，并且可以有效地跟踪对象的生命周期 |
| OH_JSVM_DeleteReference      | 释放由OH_JSVM_CreateReference创建的引用，确保对象在不再被使用时能够被正确地释放和回收，避免内存泄漏 |
| OH_JSVM_ReferenceRef         | 增加由OH_JSVM_CreateReference创建的引用的引用计数，以确保对象在有引用时不会被提前释放 |
| OH_JSVM_ReferenceUnref       | 减少引用计数，用于管理引用计数。|
| OH_JSVM_GetReferenceValue   | 减少由OH_JSVM_CreateReference创建的引用的引用计数，以确保没有任何引用指向该对象时能正确地释放和回收 |
| OH_JSVM_AddFinalizer          | 为对象添加JSVM_Finalize回调，以便在JavaScript对象被垃圾回收时调用来释放原生对象。|

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### OH_JSVM_OpenHandleScope、OH_JSVM_CloseHandleScope

通过接口OH_JSVM_OpenHandleScope创建一个上下文环境使用。需要使用OH_JSVM_CloseHandleScope进行关闭。用于管理JavaScript对象的生命周期确保在JSVM-API模块代码处理JavaScript对象时能够正确地管理其句柄，以避免出现垃圾回收相关的问题。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// HandleScopeTest、HandleScope、HandleScopeFor注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = HandleScopeTest},
    {.data = nullptr, .callback = HandleScope},
    {.data = nullptr, .callback = HandleScopeFor},
};
static JSVM_CallbackStruct *method = param;
// HandleScopeTest、HandleScope、HandleScopeFor方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"handleScopeTest", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"handleScope", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"handleScopeFor", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static int DIFF_VALUE_HUNDRED_THOUSAND = 100000;
// OH_JSVM_OpenHandleScope、OH_JSVM_CloseHandleScope的三种样例方法
static JSVM_Value HandleScopeFor(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 在for循环中频繁调用JSVM接口创建js对象时，要加handle_scope及时释放不再使用的资源。
    // 下面例子中，每次循环结束局部变量res的生命周期已结束，因此加scope及时释放其持有的js对象，防止内存泄漏
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

static JSVM_Value HandleScopeTest(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 注意：
    // 以下代码中obj是在句柄作用域内创建的，然后通过OH_JSVM_OpenHandleScope关闭了句柄作用域。
    // 但在此情况下可以正常返回出去。
    // 这是因为在这段代码中，obj是通过将其返回作为函数的返回值的方式，
    // 而不需要在句柄作用域之外继续使用obj。因此，代码中obj能够正常返回出去。
    // 通过调用OH_JSVM_OpenHandleScope来创建一个句柄作用域
    JSVM_HandleScope scope = nullptr;
    JSVM_Status status = OH_JSVM_OpenHandleScope(env, &scope);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_OpenHandleScope: failed");
        return nullptr;
    }
    // 在句柄作用域内创建一个obj
    JSVM_Value obj = nullptr;
    OH_JSVM_CreateObject(env, &obj);
    // 在对象中添加属性
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "test handleScope", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_SetNamedProperty(env, obj, "name", value);
    // 关闭句柄作用域，自动释放在该作用域内创建的对象句柄
    status = OH_JSVM_CloseHandleScope(env, scope);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CloseHandleScope: failed");
        return nullptr;
    }
    OH_LOG_INFO(LOG_APP, "JSVM HandleScopeTest: success");
    return obj;
}

static JSVM_Value HandleScope(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 通过调用OH_JSVM_OpenHandleScope来创建一个句柄作用域
    JSVM_HandleScope scope = nullptr;
    JSVM_Status status = OH_JSVM_OpenHandleScope(env, &scope);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_OpenHandleScope: failed");
        return nullptr;
    }
    // 在句柄作用域内创建一个obj
    JSVM_Value obj = nullptr;
    OH_JSVM_CreateObject(env, &obj);
    // 在对象中添加属性
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "handleScope", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_SetNamedProperty(env, obj, "name", value);
    // 关闭句柄作用域，自动释放在该作用域内创建的对象句柄
    status = OH_JSVM_CloseHandleScope(env, scope);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CloseHandleScope: failed");
        return nullptr;
    }
    // 关闭句柄作用域之后继续在对象中添加属性，jsvm中原先设置的name失效
    OH_JSVM_CreateStringUtf8(env, "001", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_SetNamedProperty(env, obj, "id", value);
    // 此处的obj的name失效
    bool result = true;
    OH_JSVM_CreateStringUtf8(env, "name", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_HasProperty(env, obj, value, &result);
    if (!result) {
        OH_LOG_INFO(LOG_APP, "JSVM HandleScope: success");
    }
    return obj;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
try {
  let script: string = `handleScopeTest()`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM handleScopeTest: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM handleScopeTest error: %{public}s', error.message);
}
try {
  let script: string = `handleScope()`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM handleScope: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM handleScope error: %{public}s', error.message);
}
try {
  let script: string = `handleScopeFor()`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM handleScopeFor: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM handleScopeFor error: %{public}s', error.message);
}
```

### OH_JSVM_OpenEscapableHandleScope、OH_JSVM_CloseEscapableHandleScope、OH_JSVM_EscapeHandle

通过接口OH_JSVM_OpenEscapableHandleScope创建出一个可逃逸的handel scope，可将范围内声明的值返回到父作用域。需要使用OH_JSVM_CloseEscapableHandleScope进行关闭。OH_JSVM_EscapeHandle用于提升传入的JavaScript对象的生命周期到其父作用域。
通过上述接口可以更灵活的使用管理传入的JavaScript对象，特别是在处理跨作用域的值传递时非常有用。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// EscapableHandleScopeTest注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = EscapableHandleScopeTest},
};
static JSVM_CallbackStruct *method = param;
// EscapableHandleScopeTest方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"escapableHandleScopeTest", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
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
    // 在作用域外继续使用escapedObj 此时的escapedObj已逃逸，可以设置成功，在ArkTS侧可以取到东西
    OH_JSVM_CreateStringUtf8(env, "001", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_SetNamedProperty(env, obj, "id", value);
    bool result = false;
    OH_JSVM_CreateStringUtf8(env, "id", JSVM_AUTO_LENGTH, &value);
    OH_JSVM_HasProperty(env, obj, value, &result);
    if (result) {
        OH_LOG_INFO(LOG_APP, "JSVM EscapableHandleScopeTest: success");
    }
    return escapedObj;
}
```

接口声明

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
try {
  let script: string = `escapableHandleScopeTest()`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM escapableHandleScopeTest: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM escapableHandleScopeTest error: %{public}s', error.message);
}
```

### OH_JSVM_CreateReference、OH_JSVM_DeleteReference

为Object创建一个reference，以延长其生命周期。调用者需要自己管理reference生命周期。可以调用OH_JSVM_DeleteReference删除传入的reference。

### OH_JSVM_ReferenceRef、OH_JSVM_ReferenceUnref

增加/减少 传入的reference的引用计数，并获取新的计数。

### OH_JSVM_GetReferenceValue

获取与reference相关联的JavaScript Object。

### OH_JSVM_AddFinalizer

当JavaScript Object中的对象被垃圾回收时调用注册的OH_JSVM_AddFinalizer回调。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// CreateReference、UseReference、DeleteReference注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateReference},
    {.data = nullptr, .callback = UseReference},
    {.data = nullptr, .callback = DeleteReference},
};
static JSVM_CallbackStruct *method = param;
// CreateReference、UseReference、DeleteReference方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createReference", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"useReference", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"deleteReference", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_CreateReference、OH_JSVM_AddFinalizer的样例方法
static JSVM_Value CreateReference(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Ref g_ref = nullptr;
    JSVM_Value obj = nullptr;
    OH_JSVM_CreateObject(env, &obj);
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "CreateReference", JSVM_AUTO_LENGTH, &value);
    // 将键值对添加到对象中
    OH_JSVM_SetNamedProperty(env, obj, "name", value);
    // 创建对JavaScript对象的引用
    JSVM_Status status = OH_JSVM_CreateReference(env, obj, 1, &g_ref);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateReference: failed");
        return nullptr;
    }
    JSVM_Finalize jSVM_Finalize = nullptr;
    OH_JSVM_AddFinalizer(env, obj, nullptr, jSVM_Finalize, nullptr, &g_ref);
    // 增加传入引用的引用计数并返回生成的引用计数
    uint32_t result;
    OH_JSVM_ReferenceRef(env, g_ref, &result);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_ReferenceRef, count = %{public}d.", result);
    if (result != 2) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_ReferenceRef: failed");
        return nullptr;
    }
    OH_LOG_INFO(LOG_APP, "JSVM CreateReference success");
    return obj;
}
// OH_JSVM_ReferenceRef、OH_JSVM_GetReferenceValue的样例方法
static JSVM_Value UseReference(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Ref g_ref = nullptr;
    JSVM_Value obj = nullptr;
    OH_JSVM_CreateObject(env, &obj);
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "UseReference", JSVM_AUTO_LENGTH, &value);
    // 将键值对添加到对象中
    OH_JSVM_SetNamedProperty(env, obj, "name", value);
    // 创建对JavaScript对象的引用
    JSVM_Status status = OH_JSVM_CreateReference(env, obj, 1, &g_ref);
    if (status != JSVM_OK) {
        return nullptr;
    }
    JSVM_Finalize jSVM_Finalize = nullptr;
    OH_JSVM_AddFinalizer(env, obj, nullptr, jSVM_Finalize, nullptr, &g_ref);
    // 增加传入引用的引用计数并返回生成的引用计数
    uint32_t result;
    OH_JSVM_ReferenceRef(env, g_ref, &result);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_ReferenceRef, count = %{public}d.", result);
    if (result != 2) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_ReferenceRef: failed");
        return nullptr;
    }
    JSVM_Value object = nullptr;
    // 通过调用OH_JSVM_GetReferenceValue获取引用的JavaScript对象
    status = OH_JSVM_GetReferenceValue(env, g_ref, &object);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetReferenceValue: failed");
        return nullptr;
    }
    // 将获取到的对象返回
    OH_LOG_INFO(LOG_APP, "JSVM UseReference success");
    return object;
}
// OH_JSVM_ReferenceUnref、OH_JSVM_DeleteReference的样例方法
static JSVM_Value DeleteReference(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Ref g_ref = nullptr;
    JSVM_Value obj = nullptr;
    OH_JSVM_CreateObject(env, &obj);
    JSVM_Value value = nullptr;
    OH_JSVM_CreateStringUtf8(env, "DeleteReference", JSVM_AUTO_LENGTH, &value);
    // 将键值对添加到对象中
    OH_JSVM_SetNamedProperty(env, obj, "name", value);
    // 创建对JavaScript对象的引用
    JSVM_Status status = OH_JSVM_CreateReference(env, obj, 1, &g_ref);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CreateReference: failed");
        return nullptr;
    }
    JSVM_Finalize jSVM_Finalize = nullptr;
    OH_JSVM_AddFinalizer(env, obj, nullptr, jSVM_Finalize, nullptr, &g_ref);
    // 增加传入引用的引用计数并返回生成的引用计数
    uint32_t result;
    OH_JSVM_ReferenceRef(env, g_ref, &result);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_ReferenceRef, count = %{public}d.", result);
    if (result != 2) {
        return nullptr;
    }
    // 减少传入引用的引用计数并返回生成的引用计数
    uint32_t num;
    OH_JSVM_ReferenceUnref(env, g_ref, &num);
    OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_ReferenceUnref, count = %{public}d.", num);
    if (num != 1) {
        return nullptr;
    }
    // 通过调用OH_JSVM_DeleteReference删除对JavaScript对象的引用
    status = OH_JSVM_DeleteReference(env, g_ref);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_DeleteReference: failed");
        return nullptr;
    }
    JSVM_Value returnResult = nullptr;
    OH_JSVM_CreateStringUtf8(env, "OH_JSVM_DeleteReference success", JSVM_AUTO_LENGTH, &returnResult);
    OH_LOG_INFO(LOG_APP, "JSVM DeleteReference success");
    return returnResult;
}
```

ArkTS侧示例代码

```ts
import hilog from "@ohos.hilog"
// 通过import的方式，引入Native能力。
import napitest from "libentry.so"
try {
  let script: string = `createReference();`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createReference: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createReference error: %{public}s', error.message);
}
try {
  let script: string = `useReference();`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM useReference: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM useReference error: %{public}s', error.message);
}
try {
  let script: string = `deleteReference();`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM deleteReference: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM deleteReference error: %{public}s', error.message);
}
```
