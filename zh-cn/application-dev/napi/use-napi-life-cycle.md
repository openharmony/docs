# 使用Node-API接口进行生命周期相关开发
<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

## 简介

在Node-API中，napi_value是一个表示ArkTS值的抽象类型，它可以表示任何ArkTS值，包括基本类型（如数字、字符串、布尔值）和复杂对象类型（如数组、函数、对象等）。

napi_value的生命周期与其在ArkTS中的对应值的生命周期紧密相关。当ArkTS值被垃圾回收时，与之关联的napi_value也将不再有效。重要的是不要在ArkTS值不再存在时尝试使用napi_value。

框架层的scope通常用于管理napi_value的生命周期。在Node-API中，可以使用napi_open_handle_scope和napi_close_handle_scope函数来创建和销毁scope。通过在scope内创建napi_value，可以确保在scope结束时自动释放napi_value，避免内存泄漏。

napi_ref是一个Node-API类型，用于管理napi_value的生命周期。napi_ref允许您在napi_value的生命周期内保持对其的引用，即使它已经超出了其原始上下文的范围。这使得您可以在不同的上下文中共享napi_value，并确保在不再需要时正确释放其内存。

## 基本概念

Node-API提供了一组功能，使开发人员能够在Node-API模块中创建和操作ArkTS对象，管理引用和生命周期，并注册垃圾回收回调函数等。下面是一些基本概念：

- **作用域**：用于管理ArkTS对象的生命周期。在某个作用域中创建的对象句柄，默认情况下只能在该作用域内使用。当作用域被关闭后，其中创建的对象将无法再被访问，除非显式地将它们逃逸出当前作用域。
- **引用管理**：Node-API提供函数来创建、删除和管理对象的引用，以延长对象的生命周期，避免出现对象use-after-free的问题。同时也通过引用管理去避免发生内存泄漏的问题。
- **可逃逸的作用域**：允许在创建的作用域中声明的对象返回到父作用域，通过napi_open_escapable_handle_scope和napi_close_escapable_handle_scope进行管理。
- **垃圾回收回调**：允许注册回调函数，以便在ArkTS对象被垃圾回收时执行特定的清理操作。

这些基本概念使开发人员能够在Node-API模块中安全且有效地操作ArkTS对象，并确保正确管理对象的生命周期。

## 场景和功能介绍

以下Node-API接口主要用于ArkTS对象的引用管理，并确保在Node-API模块代码中正确地处理ArkTS对象的生命周期。使用场景如下：
| 接口 | 描述 |
| -------- | -------- |
| napi_open_handle_scope、napi_close_handle_scope | 主要用于管理ArkTS对象的生命周期，确保在Node-API模块代码中使用ArkTS对象时能够正确地进行内存管理。当在Node-API模块中处理ArkTS对象时，需要创建一个临时的作用域来存储对象的引用，以便在执行期间正确访问这些对象，并在执行结束后关闭这个handle scope。 |
| napi_open_escapable_handle_scope、napi_close_escapable_handle_scope | 用于创建一个可逃逸的作用域，使得在原生函数中创建的ArkTS对象可以被正确返回到调用该函数的外部ArkTS环境中。 |
| napi_escape_handle | 将ArkTS对象的生命周期提升到父作用域中，避免对象被意外释放。 |
| napi_create_reference、napi_delete_reference | 主要用于在Node-API模块代码中管理ArkTS对象的引用，以确保对象的生命周期符合插件的需求。 |
| napi_reference_ref、napi_reference_unref | 主要用于管理ArkTS对象引用的引用计数，以确保在多个地方共享引用时引用计数能够正确地增加和减少。 |
| napi_get_reference_value | 主要用于在Node-API模块代码中获取与引用相关联的ArkTS对象，以便在Node-API模块中对其进行操作。 |
| napi_add_finalizer | 在需要在ArkTS对象被垃圾回收前执行一些清理或释放资源的情况下，确保资源的正确释放和管理。 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

本文cpp部分代码所需引用的头文件如下：
```cpp
#include "napi/native_api.h"
// log.h用于C++中日志打印
#include "hilog/log.h"
```
本文ArkTS侧示例代码所需的模块导入如下：
```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
```

### napi_open_handle_scope、napi_close_handle_scope

通过接口napi_open_handle_scope创建一个上下文环境，并使用napi_close_handle_scope进行关闭。这组接口用于管理ArkTS对象的生命周期，确保在Node-API模块代码处理ArkTS对象时能够正确地管理其句柄，以避免出现对象错误回收的问题。  

需要注意的是，接口仅支持单层嵌套的scope结构。在任何时刻，只有一个scope处于活动状态，所有新创建的handles都将与该scope相关联。scope必须按照与打开顺序相反的顺序关闭。此外，在native方法中创建的所有scope必须在该方法返回之前被关闭。

关于生命周期管理的代码部分也可参考下面链接：

[生命周期管理](napi-guidelines.md#生命周期管理)  

关于典型错误使用方法的代码部分也可参考下面链接：

[典型错误场景](napi-faq-about-stability.md#napi_open_handle_scope与napi_close_handle_scope进行生命周期相关开发典型错误场景)

cpp部分代码

<!-- @[napi_open_close_handle_scope](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPILifeCycle/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
// napi_open_handle_scope、napi_close_handle_scope
static napi_value HandleScopeTest(napi_env env, napi_callback_info info)
{
    // 通过调用napi_open_handle_scope来创建一个句柄作用域
    napi_handle_scope scope;
    napi_open_handle_scope(env, &scope);
    // 在句柄作用域内创建一个obj
    napi_value obj = nullptr;
    napi_create_object(env, &obj);
    // 在对象中添加属性
    napi_value value = nullptr;
    napi_create_string_utf8(env, "handleScope", NAPI_AUTO_LENGTH, &value);
    napi_set_named_property(env, obj, "key", value);
    // 在作用域内获取obj的属性并返回
    napi_value result = nullptr;
    napi_get_named_property(env, obj, "key", &result);
    // 关闭句柄作用域，自动释放在该作用域内创建的对象句柄
    napi_close_handle_scope(env, scope);
    // result已经离开scope的作用域，继续使用可能会存在稳定性问题，如果需要在作用域外使用对象，建议使用napi_open_escapable_handle_scope系列接口
    return nullptr;
}

static napi_value HandleScope(napi_env env, napi_callback_info info)
{
    // 通过调用napi_open_handle_scope来创建一个句柄作用域
    napi_handle_scope scope;
    napi_open_handle_scope(env, &scope);
    // 在句柄作用域内创建一个obj
    napi_value obj = nullptr;
    napi_create_object(env, &obj);
    // 在对象中添加属性
    napi_value value = nullptr;
    napi_create_string_utf8(env, "handleScope", NAPI_AUTO_LENGTH, &value);
    napi_set_named_property(env, obj, "key", value);
    // 关闭句柄作用域，自动释放在该作用域内创建的对象句柄
    napi_close_handle_scope(env, scope);
    // 在作用域外获取obj的属性并返回，此处只能得到“undefined”
    napi_value result = nullptr;
    napi_get_named_property(env, obj, "key", &result);
    return result;
}
```


接口声明

index.d.ts
<!-- @[napi_open_close_handle_scope_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPILifeCycle/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const handleScopeTest: () => string; // napi_open_handle_scope、napi_close_handle_scope

export const handleScope: () => string;
```


ArkTS侧示例代码

<!-- @[ark_napi_open_close_handle_scope](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPILifeCycle/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_open_handle_scope  napi_close_handle_scope
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API handleScopeTest: %{public}s',
    testNapi.handleScopeTest());
  hilog.info(0x0000, 'testTag', 'Test Node-API handleScope: %{public}s', testNapi.handleScope());
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag',
    'Test Node-API handleScopeTest errorCode: %{public}s, errorMessage: %{public}s', error.code,
    error.message);
  // ...
}
```


框架层在核心初始化函数Init中定义了ArkTS侧和native侧的接口映射表，在ArkTS侧通过映射表中的接口访问native侧的函数时，框架层会自动加上scope，不需要额外增加napi_open_handle_scope、napi_close_handle_scope接口来管理ArkTS对象的生命周期。即：进入开发者自己写的native函数前自动open scope，native函数结束后自动close scope。native侧函数中创建的ArkTS对象的生命周期在native函数返回时结束，不会存在内存泄漏的问题。以NewObject函数举例如下（定义接口映射表中映射的函数不需要手动加napi_open_handle_scope、napi_close_handle_scope管理ArkTS对象的生命周期）：
```cpp
// 调用NewObject前会open scope
napi_value NewObject(napi_env env, napi_callback_info info)
{
    napi_value object = nullptr;
    // 创建一个空对象
    napi_create_object(env, &object);
    // 设置对象的属性
    napi_value name = nullptr;
    // 设置属性名为"name"
    napi_create_string_utf8(env, "name", NAPI_AUTO_LENGTH, &name);
    napi_value value = nullptr;
    // 设置属性值为"Hello from Node-API!"
    napi_create_string_utf8(env, "Hello from Node-API!", NAPI_AUTO_LENGTH, &value);
    // 将属性设置到对象上
    napi_set_property(env, object, name, value);
    //result离开作用域后，对象句柄（handle）跟随释放，返回到ArkTS侧的对象由ArkTS侧管理
    return object;
}
// NewObject调用函数结束后框架层会close scope

// 核心初始化函数
static napi_value Init(napi_env env, napi_value exports)
{
    // 定义接口映射表
    napi_property_descriptor desc[] = {
        { "newObject", nullptr, NewObject, nullptr, nullptr, nullptr, napi_default, nullptr }
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
```

### napi_open_escapable_handle_scope、napi_close_escapable_handle_scope、napi_escape_handle

通过接口napi_open_escapable_handle_scope创建出一个可逃逸的handle scope，可将范围内声明的值返回到父作用域。该作用域需要使用napi_close_escapable_handle_scope进行关闭。napi_escape_handle用于提升传入的ArkTS对象的生命周期到其父作用域。

通过上述接口可以更灵活地使用管理传入的ArkTS对象，特别是在处理跨作用域的值传递时非常有用。

cpp部分代码

<!-- @[napi_open_close_escapable_handle_scope](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPILifeCycle/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_open_escapable_handle_scope、napi_close_escapable_handle_scope、napi_escape_handle
static napi_value EscapableHandleScopeTest(napi_env env, napi_callback_info info)
{
    // 创建一个可逃逸的句柄作用域
    napi_escapable_handle_scope scope;
    napi_open_escapable_handle_scope(env, &scope);
    // 在可逃逸的句柄作用域内创建一个obj
    napi_value obj = nullptr;
    napi_create_object(env, &obj);
    // 在对象中添加属性
    napi_value value = nullptr;
    napi_create_string_utf8(env, "Test napi_escapable_handle_scope", NAPI_AUTO_LENGTH, &value);
    napi_set_named_property(env, obj, "key", value);
    napi_value prop = nullptr;
    napi_get_named_property(env, obj, "key", &prop);
    // 调用napi_escape_handle将属性值逃逸到作用域之外
    napi_value result = nullptr;
    napi_escape_handle(env, scope, prop, &result);
    // 关闭可逃逸的句柄作用域，清理资源
    napi_close_escapable_handle_scope(env, scope);
    // 逃逸后的result可以在作用域外继续使用
    return result;
}
```


接口声明

index.d.ts
<!-- @[napi_open_close_escapable_handle_scope_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPILifeCycle/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const escapableHandleScopeTest: () => string; // napi_open_escapable_handle_scope、napi_close_escapable_handle_scope、napi_escape_handle
```


ArkTS侧示例代码

<!-- @[ark_napi_open_close_escapable_handle_scope](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPILifeCycle/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_open_escapable_handle_scope napi_close_escapable_handle_scope、napi_escape_handle
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API EscapableHandleScopeTest: %{public}s',
    testNapi.escapableHandleScopeTest());
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag',
    'Test Node-API EscapableHandleScopeTest errorCode: %{public}s, errorMessage: %{public}s',
    error.code,
    error.message);
  // ...
}
```
### napi_ref

napi_ref 是 napi 中用于管理 ArkTS 对象生命周期的引用类型，分为强引用和弱引用两种类型。当ref计数为0时为弱引用，计数大于0时为强引用。强引用会阻止垃圾回收器回收被引用的对象，适用于需要长期保持对象存活的场景，但必须手动管理引用计数和释放，否则会导致内存泄漏；弱引用则不会阻止垃圾回收，允许对象在不再被其他强引用持有时被正常回收，适用于缓存等临时性引用场景，能够自动失效但需要在获取时检查对象是否仍存活。正确选择强弱引用类型对于平衡内存管理和性能至关重要。

### napi_create_reference、napi_delete_reference

为Object创建一个reference，以延长其生命周期。调用者需要自己管理reference生命周期。可以调用napi_delete_reference删除传入的reference。

### napi_reference_ref、napi_reference_unref

增加/减少传入的reference的引用计数，并获取新的计数。

### napi_get_reference_value

获取与reference相关联的ArkTS Object。

> **说明**
>
> 由于弱引用（引用计数为0的napi_ref）的释放与gc回收js对象并非同时发生。
>
> 因此可能在弱引用被释放前，js对象已经被回收。
>
> 这意味着你可能在napi_ref有效的情况下，通过本接口获取到一个空指针。

**弱引用使用示例代码：**

创建时将引用计数初始化为0，这样创建的ref即为弱引用，弱引用不会阻止对象被回收。获取前需将weakValue初始化为nullptr，获取后检查weakValue是否仍为nullptr。若为nullptr，说明对象已被回收；若不为nullptr，则可继续使用。

cpp部分代码

``` C++
#include "napi/native_api.h"

napi_ref g_weakRef = nullptr;

static napi_value CreateWeakReference(napi_env env, napi_callback_info info)
{
    napi_value value = nullptr;
    napi_create_string_utf8(env, "This is a test property", NAPI_AUTO_LENGTH, &value);
    napi_value jsObject = nullptr;
    napi_create_object(env, &jsObject);
    napi_set_named_property(env, jsObject, "test", value);

    // 清理之前的引用（如果存在）
    if (g_weakRef != nullptr) {
        napi_delete_reference(env, g_weakRef);
        g_weakRef = nullptr;
    }

    // 创建弱引用，不会阻止垃圾回收，没有其他强引用持有时会被正常回收
    napi_status status = napi_create_reference(env, jsObject, 0, &g_weakRef);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to create weak reference");
        return nullptr;
    }

    return nullptr;
}

static napi_value GetWeakReferenceValue(napi_env env, napi_callback_info info)
{
    napi_value weakValue;
    napi_status status = napi_get_reference_value(env, g_weakRef, &weakValue);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to get reference value");
        return nullptr;
    }

    // 判断对象是否已被回收
    if (weakValue == nullptr) {
        napi_throw_error(env, nullptr, "Object has been garbage collected");
        return nullptr;
    }

    // 尝试获取对象的属性来确认它仍然有效
    napi_value result = nullptr;
    napi_get_named_property(env, weakValue, "test", &result);

    return result;
}
```

接口声明

// index.d.ts

``` TypeScript
export const createWeakReference: () => void;

export const getWeakReferenceValue: () => string;
```

ArkTS侧示例代码

``` TypeScript
try {
    testNapi.createWeakReference();
    hilog.info(0x0000, 'testTag', 'reference test: %{public}s', testNapi.getWeakReferenceValue());
} catch (error) {
    hilog.error(0x0000, 'testTag', `调用错误：${error.message}`);
}
```

**强引用使用示例代码：**

创建时将引用计数初始化为1，这样创建的ref即为强引用，保证对象不会被回收。不再使用时调用napi_delete_reference释放对象，避免内存泄漏。

cpp部分代码

``` C++
#include "napi/native_api.h"

// 全局强引用
napi_ref g_strongRef = nullptr;

// 创建强引用
static napi_value CreateStrongReference(napi_env env, napi_callback_info info)
{
    napi_value value = nullptr;
    napi_create_string_utf8(env, "This is a test property", NAPI_AUTO_LENGTH, &value);
    napi_value jsObject = nullptr;
    napi_create_object(env, &jsObject);
    napi_set_named_property(env, jsObject, "test", value);

    // 清理之前的强引用（如果存在）
    if (g_strongRef != nullptr) {
        napi_delete_reference(env, g_strongRef);
        g_strongRef = nullptr;
    }

    // 创建强引用（初始引用计数为1），阻止垃圾回收器回收
    napi_status status = napi_create_reference(env, jsObject, 1, &g_strongRef);

    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to create strong reference");
        return nullptr;
    }

    return nullptr;
}

static napi_value GetStrongReferenceValue(napi_env env, napi_callback_info info)
{
    napi_value jsValue;
    napi_status status = napi_get_reference_value(env, g_strongRef, &jsValue);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to get reference value");
        return nullptr;
    }

    // 尝试获取对象的属性来确认它仍然有效
    napi_value result = nullptr;
    napi_get_named_property(env, jsValue, "test", &result);

    return result;
}

// 清理强引用
static napi_value CleanupStrongReference(napi_env env, napi_callback_info info) {
    napi_value ret = nullptr;
    if (g_strongRef != nullptr) {
        // 强制删除引用，即使引用计数不为0
        napi_delete_reference(env, g_strongRef);
        g_strongRef = nullptr;
        napi_get_boolean(env, true, &ret);
        return ret;
    }
    napi_get_boolean(env, false, &ret);
    return ret;
}
```

接口声明

// index.d.ts

``` TypeScript
export const createStrongReference: () => void;

export const getStrongReferenceValue: () => string;

export const cleanupStrongReference: () => void;
```

ArkTS侧示例代码

``` TypeScript
try {
    testNapi.createStrongReference();
    hilog.info(0x0000, 'testTag', 'reference test: %{public}s', testNapi.getStrongReferenceValue());
    testNapi.cleanupStrongReference();
} catch (error) {
    hilog.error(0x0000, 'testTag', `调用错误：${error.message}`);
}
```

### napi_add_finalizer

当ArkTS Object中的对象被垃圾回收时调用注册的napi_add_finalizer回调。

cpp部分代码

<!-- @[napi_create_delete_reference](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPILifeCycle/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// 创建一个napi_ref类型的指针，用于存储创建的引用。在调用napi_add_finalizer函数前，分配一个napi_ref类型的变量，并传递其地址作为result参数。
napi_ref gRefFinalizer = nullptr;

// 创建一个napi_ref类型的指针，用于存储创建的引用。在调用napi_create_reference函数前，分配一个napi_ref类型的变量，并传递其地址作为result参数。
napi_ref gRef = nullptr;

void Finalizer(napi_env env, void *data, void *hint)
{
    // 执行资源清理操作
    OH_LOG_INFO(LOG_APP, "Test Node-API Use Finalizer to release resources.");
    // do something 执行资源清理操作
}

static napi_value AddFinalizer(napi_env env, napi_callback_info info)
{
    napi_value obj = nullptr;
    napi_status status = napi_create_object(env, &obj);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_create_object fail");
        return nullptr;
    }
    napi_value value = nullptr;
    status = napi_create_string_utf8(env, "AddFinalizer", NAPI_AUTO_LENGTH, &value);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_create_string_utf8 fail");
        return nullptr;
    }
    // 将键值对添加到对象中
    status = napi_set_named_property(env, obj, "key", value);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_set_named_property fail");
        return nullptr;
    }

    // 注册回调函数Finalizer用于清理资源
    void *data = {};
    status = napi_add_finalizer(env, obj, data, Finalizer, nullptr, &gRefFinalizer);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_add_finalizer fail");
        return nullptr;
    }

    return obj;
}

static napi_value CreateReference(napi_env env, napi_callback_info info)
{
    napi_value obj = nullptr;
    napi_status status = napi_create_object(env, &obj);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_create_object fail");
        return nullptr;
    }
    napi_value value = nullptr;
    status = napi_create_string_utf8(env, "CreateReference", NAPI_AUTO_LENGTH, &value);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_create_string_utf8 fail");
        return nullptr;
    }
    // 将键值对添加到对象中
    status = napi_set_named_property(env, obj, "key", value);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_set_named_property fail");
        return nullptr;
    }
    // 创建对ArkTS对象的引用
    status = napi_create_reference(env, obj, 1, &gRef);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_create_reference fail");
        return nullptr;
    }
    // 增加传入引用的引用计数并返回生成的引用计数
    uint32_t result = 0;
    status = napi_reference_ref(env, gRef, &result);
    OH_LOG_INFO(LOG_APP, "Test Node-API napi_reference_ref, count = %{public}d.", result);
    uint32_t numCount = 2;
    if (status != napi_ok || result != numCount) {
        // 若传入引用的引用计数未增加，则抛出错误
        napi_throw_error(env, nullptr, "napi_reference_ref fail");
        return nullptr;
    }
    return obj;
}

static napi_value UseReference(napi_env env, napi_callback_info info)
{
    napi_value obj = nullptr;
    // 通过调用napi_get_reference_value获取引用的ArkTS对象
    napi_status status = napi_get_reference_value(env, gRef, &obj);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_get_reference_value fail");
        return nullptr;
    }
    // 返回获取的对象
    return obj;
}

static napi_value DeleteReference(napi_env env, napi_callback_info info)
{
    // 减少传入引用的引用计数并返回生成的引用计数
    uint32_t result = 0;
    napi_value count = nullptr;
    napi_status status = napi_reference_unref(env, gRef, &result);
    OH_LOG_INFO(LOG_APP, "Test Node-API napi_reference_unref, count = %{public}d.", result);
    uint32_t numCount = 1;
    if (status != napi_ok || result != numCount) {
        // 若传入引用的引用计数未减少，则抛出错误
        napi_throw_error(env, nullptr, "napi_reference_unref fail");
        return nullptr;
    }

    // 通过调用napi_delete_reference删除对ArkTS对象的引用
    status = napi_delete_reference(env, gRef);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_delete_reference fail");
        return nullptr;
    }

    status = napi_delete_reference(env, gRefFinalizer);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_delete_reference fail");
        return nullptr;
    }
    napi_value returnResult = nullptr;
    status = napi_create_string_utf8(env, "napi_delete_reference success", NAPI_AUTO_LENGTH, &returnResult);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_create_string_utf8 fail");
        return nullptr;
    }
    return returnResult;
}
```


接口声明

// index.d.ts
<!-- @[napi_create_delete_reference_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPILifeCycle/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const addFinalizer: () => Object | undefined; // napi_add_finalizer

export const createReference: () => Object | undefined; // napi_create_reference、napi_reference_ref

export const useReference: () => Object | undefined; // napi_get_reference_value

export const deleteReference: () => string | undefined; // napi_delete_reference、napi_reference_unref
```


ArkTS侧示例代码

<!-- @[ark_napi_create_delete_reference](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPILifeCycle/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_add_finalizer
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API addFinalizer: %{public}s',
    JSON.stringify(testNapi.addFinalizer()));
  hilog.info(0x0000, 'testTag', 'Test Node-API createReference: %{public}s',
    JSON.stringify(testNapi.createReference()));
  hilog.info(0x0000, 'testTag', 'Test Node-API useReference: %{public}s',
    JSON.stringify(testNapi.useReference()));
  hilog.info(0x0000, 'testTag', 'Test Node-API deleteReference: %{public}s',
    testNapi.deleteReference());
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag',
    'Test Node-API ReferenceTest errorCode: %{public}s, errorMessage: %{public}s', error.code,
    error.message);
  // ...
}
```


以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
