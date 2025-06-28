# 使用Node-API接口进行生命周期相关开发

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

### napi_open_handle_scope、napi_close_handle_scope

通过接口napi_open_handle_scope创建一个上下文环境，并使用napi_close_handle_scope进行关闭。这组接口用于管理ArkTS对象的生命周期，确保在Node-API模块代码处理ArkTS对象时能够正确地管理其句柄，以避免出现对象错误回收的问题。
需要注意的是合理使用napi_open_handle_scope和napi_close_handle_scope管理napi_value的生命周期，做到生命周期最小化，避免发生内存泄漏问题。

代码部分也可参考下面链接：
[生命周期管理](napi-guidelines.md#生命周期管理)

cpp部分代码

```cpp
#include "napi/native_api.h"

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
    // 此处的result能够得到值“handleScope”
    return result;
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

```ts
// index.d.ts
export const handleScopeTest: () => string;
export const handleScope: () => string;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API handleScopeTest: %{public}s', testNapi.handleScopeTest());
  hilog.info(0x0000, 'testTag', 'Test Node-API handleScope: %{public}s', testNapi.handleScope());
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API handleScopeTest errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}
```

### napi_open_escapable_handle_scope、napi_close_escapable_handle_scope、napi_escape_handle

通过接口napi_open_escapable_handle_scope创建出一个可逃逸的handel scope，可将范围内声明的值返回到父作用域。该作用域需要使用napi_close_escapable_handle_scope进行关闭。napi_escape_handle用于提升传入的ArkTS对象的生命周期到其父作用域。
通过上述接口可以更灵活的使用管理传入的ArkTS对象，特别是在处理跨作用域的值传递时非常有用。

cpp部分代码

```cpp
#include "napi/native_api.h"

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
    // 调用napi_escape_handle将对象逃逸到作用域之外
    napi_value escapedObj = nullptr;
    napi_escape_handle(env, scope, obj, &escapedObj);
    // 关闭可逃逸的句柄作用域，清理资源
    napi_close_escapable_handle_scope(env, scope);
    // 在获取逃逸后的obj：escapedObj的属性并返回，此处也能够得到“napi_escapable_handle_scope”
    napi_value result = nullptr;
    // 为了验证逃逸的实现，可以在此处获取obj的属性，此处会得到“undefined”
    napi_get_named_property(env, escapedObj, "key", &result);
    return result;
}
```

接口声明

```ts
// index.d.ts
export const escapableHandleScopeTest: () => string;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API EscapableHandleScopeTest: %{public}s', testNapi.escapableHandleScopeTest());
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API EscapableHandleScopeTest errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}
```

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

### napi_add_finalizer

当ArkTS Object中的对象被垃圾回收时调用注册的napi_add_finalizer回调。

cpp部分代码

```cpp
// log.h用于C++中日志打印
#include "hilog/log.h"
#include "napi/native_api.h"
// 创建一个指向napi_ref类型的指针，用于存储创建的引用。在调用napi_create_reference函数之前，你需要分配一个napi_ref类型的变量，并将其地址传递给result位置的参数
napi_ref g_ref;

void Finalizer(napi_env env, void *data, void *hint)
{
    // 执行资源清理操作
    OH_LOG_INFO(LOG_APP, "Node-API: Use terminators to release resources.");
}

static napi_value CreateReference(napi_env env, napi_callback_info info)
{
    napi_value obj = nullptr;
    napi_create_object(env, &obj);
    napi_value value = nullptr;
    napi_create_string_utf8(env, "CreateReference", NAPI_AUTO_LENGTH, &value);
    // 将键值对添加到对象中
    napi_set_named_property(env, obj, "key", value);

    // 添加终结器
    void *data = {};
    napi_add_finalizer(env, obj, data, Finalizer, nullptr, &g_ref);
    // 增加传入引用的引用计数并返回生成的引用计数
    uint32_t result = 0;
    napi_reference_ref(env, g_ref, &result);
    OH_LOG_INFO(LOG_APP, "napi_reference_ref, count = %{public}d.", result);
    if (result != 2) {
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
    napi_status status = napi_get_reference_value(env, g_ref, &obj);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_get_reference_value fail");
        return nullptr;
    }
    // 将获取到的对象返回
    return obj;
}

static napi_value DeleteReference(napi_env env, napi_callback_info info)
{
    // 减少传入引用的引用计数并返回生成的引用计数
    uint32_t result = 0;
    napi_value count = nullptr;
    napi_reference_unref(env, g_ref, &result);
    OH_LOG_INFO(LOG_APP, "napi_reference_ref, count = %{public}d.", result);
    if (result != 1) {
        // 若传入引用的引用计数未减少，则抛出错误
        napi_throw_error(env, nullptr, "napi_reference_unref fail");
        return nullptr;
    }
    // 通过调用napi_delete_reference删除对ArkTS对象的引用
    napi_status status = napi_delete_reference(env, g_ref);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_delete_reference fail");
        return nullptr;
    }
    napi_value returnResult = nullptr;
    napi_create_string_utf8(env, "napi_delete_reference success", NAPI_AUTO_LENGTH, &returnResult);
    return returnResult;
}
```

接口声明

```ts
// index.d.ts
export const createReference: () => Object | void;
export const useReference: () => Object | void;
export const deleteReference: () => string | void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API createReference: %{public}s', JSON.stringify(testNapi.createReference()));
  hilog.info(0x0000, 'testTag', 'Test Node-API useReference: %{public}s', JSON.stringify(testNapi.useReference()));
  hilog.info(0x0000, 'testTag', 'Test Node-API deleteReference: %{public}s', testNapi.deleteReference());
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API ReferenceTest errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}
```

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
