# 使用Node-API进行自定义异步操作相关开发

## 简介

使用Node-API的自定义异步操作功能，可以使ArkTS的使用更加灵活和高效，可以处理那些可能阻塞事件循环的长时间运行任务，同时保持ArkTS应用的响应性和性能。

## 基本概念

Node-API支持异步操作，这对于处理IO密集型或计算密集型的任务非常重要，因为这些任务通常需要非阻塞的执行方式以避免阻塞主线程。以下是一些关于自定义异步操作的基本概念：

- **异步模型：** Node-API支持异步模型，提供了Promise和Callback两种方式来实现异步操作。Promise是一种基于未来值的编程模型，它允许开发者将异步操作的结果封装在一个对象中，并通过链式调用的方式处理异步操作的结果。Callback则是一种传统的异步编程方式，通过回调函数来处理异步操作的结果。
- **临时结果：** 当原生方法（即Node-API代码）被调用时，它会立即返回一个临时结果给ArkTS调用者。这个临时结果通常是一个表示异步操作正在进行中的标志，或者是用于后续处理异步操作结果的句柄。
- **回调或Promise：** 当异步操作完成后，结果会通过回调函数或Promise对象返回给ArkTS调用者。这样，ArkTS代码就可以在异步操作完成后继续执行后续的逻辑。

## 场景和功能介绍

这些Node-API接口可以在Node-API模块中执行异步操作、进行ArkTS回调以及管理相关资源的生命周期。通过使用这些函数，可以有效地与ArkTS环境进行交互，并实现复杂的异步操作。他们的使用场景如下：
| 接口 | 描述 |
| -------- | -------- |
| napi_async_init、napi_async_destroy | 用于创建和销毁异步资源上下文环境。这些函数可以用于处理长时间运行的异步操作，例如文件I/O操作、网络请求等。在这些情况下，创建异步资源上下文环境，执行必要的异步任务，然后销毁资源以释放相关的资源和内容。 |
| napi_make_callback | 用于在异步资源上下文环境中执行ArkTS回调函数。在处理异步操作的结果后，将结果传递回ArkTS代码。 |
| napi_open_callback_scope、napi_close_callback_scope | 用于创建和关闭回调作用域。在异步操作期间执行ArkTS代码并管理其上下文。 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### napi_async_init、napi_async_destroy

在需要管理异步资源上下文环境的创建和销毁时，可以使用napi_async_init和napi_async_destroy来管理这些环境。需要注意的是，这些函数不支持与async_hook相关的能力，所以在使用时需要注意可能会存在的限制。

### napi_make_callback

在编写Node-API模块时，需要在异步操作完成后调用ArkTS回调函数。可以使用napi_async_init创建异步资源上下文环境，然后使用napi_make_callback在该环境中执行ArkTS回调函数。

### napi_open_callback_scope、napi_close_callback_scope

在需要创建一个回调作用域来确保异步操作期间ArkTS环境仍然可用时。可以使用napi_open_callback_scope创建回调作用域，然后在异步操作完成后使用napi_close_callback_scope关闭该作用域。

cpp部分代码

```cpp
#include "napi/native_api.h"

static constexpr int INT_ARG_2 = 2; // 入参索引
static constexpr int INT_ARG_3 = 3; // 入参索引

static napi_value AsynchronousWork(napi_env env, napi_callback_info info)
{
    // 接受四个参数
    size_t argc = 4;
    napi_value args[4] = {nullptr};
    // 从回调信息中获取参数
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 提取参数中的资源、接收器对象和函数
    napi_value resource = args[0];
    napi_value recv = args[1];
    napi_value func = args[INT_ARG_2];
    napi_value argv[1] = {nullptr};
    argv[0] = args[INT_ARG_3];
    // 获取函数的类型
    napi_valuetype funcType;
    napi_typeof(env, func, &funcType);
    // 创建一个资源名称为"test"的字符串
    napi_value resourceName = nullptr;
    napi_create_string_utf8(env, "test", NAPI_AUTO_LENGTH, &resourceName);
    // 初始化异步上下文
    napi_async_context context;
    napi_status status = napi_async_init(env, resource, resourceName, &context);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_async_init fail");
        return nullptr;
    }
    // 打开回调作用域
    napi_callback_scope scope = nullptr;
    napi_open_callback_scope(env, resource, context, &scope);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_open_callback_scope fail");
        return nullptr;
    }
    // 调用回调函数
    napi_value result = nullptr;
    if (funcType == napi_function) {
        napi_make_callback(env, context, recv, func, 1, argv, &result);
    } else {
        napi_throw_error(env, nullptr, "Unexpected argument type");
        return nullptr;
    }
    // 关闭回调作用域
    napi_close_callback_scope(env, scope);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_close_callback_scope fail");
        return nullptr;
    }
    // 销毁异步上下文
    napi_async_destroy(env, context);
    return result;
}
```
<!-- @[napi_async_open_close_callback_scope](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPICustomAsynchronousOperations/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const asynchronousWork: (object: Object, obj: Object, fun: Function, num: number) => number | void;
```
<!-- @[napi_async_open_close_callback_scope_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPICustomAsynchronousOperations/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
import process from '@ohos.process';
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API asynchronousWork: %{public}d', testNapi.asynchronousWork({}, process.ProcessManager, (num: number)=>{return num;}, 123));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API asynchronousWork error: %{public}s', error.message);
}
```
<!-- @[ark_napi_async_open_close_callback_scope](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPICustomAsynchronousOperations/entry/src/main/ets/pages/Index.ets) -->

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so )
```
