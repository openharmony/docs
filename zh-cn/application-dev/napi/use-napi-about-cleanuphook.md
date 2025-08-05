# 使用Node-API接口注册和使用环境清理钩子
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello; @yuanyao14; @lzj0614-->
<!--SE: @shilei123-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

## 简介

使用Node-API接口在进程退出时处理未释放资源，在Node-API模块注册清理钩子，一旦当前环境退出，这些钩子就会运行，使所有资源都被正确释放。

## 基本概念

Node-API提供了注册和取消注册清理钩子函数的功能，以下是相关概念：

- **资源管理**：在ArkTS中，通常需要管理一些系统资源，比如内存、文件句柄、网络连接等。这些资源必须在Node-API模块的生命周期中正确地创建、使用和释放，以避免资源泄漏和程序崩溃。资源管理通常包括初始化资源、在合适的时候清理资源，以及在清理资源时执行必要的操作，比如关闭文件或断开网络连接。
- **钩子函数（Hook）**：钩子函数是一种在特定事件或时间点自动执行的回调函数。在Node-API模块的上下文中，清理钩子函数通常用于在环境或进程退出时执行资源清理任务。这是因为环境或进程退出时，操作系统可能不会立即回收所有资源，因此需要通过清理钩子函数来确保所有资源都被正确释放。

以上这些基本概念是理解和使用Node-API接口注册环境清理钩子的基础，下面将介绍具体的接口和使用示例。

## 场景和功能介绍

以下Node-API接口用于注册和取消不同类型的清理钩子。他们的使用场景如下：

| 接口 | 描述 |
| -------- | -------- |
| napi_add_env_cleanup_hook | 注册一个环境清理钩子函数，该函数将在Node-API环境退出时被调用。 |
| napi_remove_env_cleanup_hook | 取消之前注册的环境清理钩子函数，避免其在环境清理时执行。 |
| napi_add_async_cleanup_hook | 注册一个异步清理钩子函数，该函数将在Node-API进程退出时异步执行。 |
| napi_remove_async_cleanup_hook | 取消之前注册的异步清理钩子函数，确保在不需要时不会执行相关的清理工作。 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### napi_add_env_cleanup_hook

用于注册一个环境清理钩子函数，该函数将在环境退出时执行。这是确保资源在环境销毁前得到清理的重要机制。

需要注意的是，napi_add_env_cleanup_hook接口并不支持对同一arg绑定多个回调。若出现env已销毁，但cleanup回调未被执行的情况，可以在启用ArkTS运行时[多线程检测](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-multi-thread-check)功能的前提下，查看hilog流水日志`AddCleanupHook Failed, data cannot register multiple times.`来查找发生注册失败的调用。

### napi_remove_env_cleanup_hook

用于取消之前注册的环境清理钩子函数。在某些情况下，需要在插件卸载或资源被重新分配时取消钩子函数。

cpp部分代码

```cpp
#include <hilog/log.h>
#include <string>
#include "napi/native_api.h"
// 定义内存结构，包含指向数据的指针和数据的大小
typedef struct {
    char *data;
    size_t size;
} Memory;
// 外部缓冲区清理回调函数，用于释放分配的内存
void ExternalFinalize(napi_env env, void *finalize_data, void *finalize_hint)
{
    Memory *wrapper = (Memory *)finalize_hint;
    free(wrapper->data);
    free(wrapper);
    OH_LOG_INFO(LOG_APP, "Node-API napi_add_env_cleanup_hook ExternalFinalize");
}
// 在环境关闭时执行一些清理操作，如清理全局变量或其他需要在环境关闭时处理的资源
static void Cleanup(void *arg)
{
    // 执行清理操作
    OH_LOG_INFO(LOG_APP, "Node-API napi_add_env_cleanup_hook cleanuped: %{public}d", *(int *)(arg));
}
// 创建外部缓冲区并注册环境清理钩子函数
static napi_value NapiEnvCleanUpHook(napi_env env, napi_callback_info info)
{
    // 分配内存并复制字符串数据到内存中
    std::string str("Hello from Node-API!");
    Memory *wrapper = (Memory *)malloc(sizeof(Memory));
    if (wrapper == nullptr) {
        OH_LOG_ERROR(LOG_APP, "malloc for wrapper failed");
        return nullptr;
    }
    wrapper->data = static_cast<char *>(malloc(str.size() + 1));
    if (wrapper->data == nullptr) {
        free(wrapper);
        OH_LOG_ERROR(LOG_APP, "malloc for wrapper->data failed");
        return nullptr;
    }
    memset(wrapper->data, 0, str.size() + 1);
    strcpy(wrapper->data, str.c_str());
    wrapper->size = str.size();
    // 创建外部缓冲区对象，并指定清理回调函数
    // 注意：wrapper->data 的内存释放依赖于 ExternalFinalize 回调，只有 buffer 被正确持有并最终被 GC 回收时，ExternalFinalize 才会被调用，否则会导致内存泄漏。
    napi_value buffer = nullptr;
    napi_status status = napi_create_external_buffer(env, wrapper->size, (void *)wrapper->data, ExternalFinalize, wrapper, &buffer);
    if (status != napi_ok) {
        // 创建失败时需主动释放内存，避免泄漏
        free(wrapper->data);
        free(wrapper);
        OH_LOG_ERROR(LOG_APP, "napi_create_external_buffer failed");
        return nullptr;
    }
    // 静态变量作为钩子函数参数
    static int hookArg = 42;
    static int hookParameter = 1;
    // 注册环境清理钩子函数
    status = napi_add_env_cleanup_hook(env, Cleanup, &hookArg);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "Test Node-API napi_add_env_cleanup_hook failed.");
        return nullptr;
    }
    // 注册环境清理钩子函数，此处不移除环境清理钩子，为了在Java环境被销毁时，这个钩子函数被调用，用来模拟执行一些清理操作，例如释放资源、关闭文件等。
    status = napi_add_env_cleanup_hook(env, Cleanup, &hookParameter);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "Test Node-API napi_add_env_cleanup_hook failed.");
        return nullptr;
    }
    // 立即移除环境清理钩子函数，确保不会在后续环境清理时被调用
    // 通常，当为其添加此钩子的资源无论如何都被拆除时调用这个接口
    napi_remove_env_cleanup_hook(env, Cleanup, &hookArg);
    napi_remove_env_cleanup_hook(env, Cleanup, &hookParameter);
    // 返回创建的外部缓冲区对象
    return buffer;
}
```
<!-- @[napi_remove_add_env_cleanup_hook](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPICleanuphook/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const napiEnvCleanUpHook: () => Object | undefined;
```
<!-- @[napi_remove_add_env_cleanup_hook_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPICleanuphook/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
// index.ets
import { hilog } from '@kit.PerformanceAnalysisKit';
import worker from '@ohos.worker';

let wk = new worker.ThreadWorker("entry/ets/workers/worker.ts");
// 发送消息到worker线程
wk.postMessage("test NapiEnvCleanUpHook");
// 处理来自worker线程的消息
wk.onmessage = (message) => {
  hilog.info(0x0000, 'testTag', 'Test Node-API message from worker: %{public}s', JSON.stringify(message));
  wk.terminate();
};
```
<!-- @[connect_with_worker](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPICleanuphook/entry/src/main/ets/pages/Index.ets) -->

```ts
// worker.ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import worker from '@ohos.worker';
import testNapi from 'libentry.so';

let parent = worker.workerPort;
// 处理来自主线程的消息
parent.onmessage = (message) => {
  hilog.info(0x0000, 'testTag', 'Test Node-API message from main thread: %{public}s', JSON.stringify(message));
  // 发送消息到主线程
  parent.postMessage('Test Node-API worker:' + testNapi.napiEnvCleanUpHook());
}
```
<!-- @[connect_with_main_thread](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPICleanuphook/entry/src/main/ets/workers/worker.ts) -->

worker相关开发配置和流程参考以下链接：
[使用Worker进行线程间通信](../arkts-utils/worker-introduction.md)

### napi_add_async_cleanup_hook

这个接口用于注册一个异步清理钩子函数，该函数将在环境退出时异步执行。与同步钩子不同，异步钩子允许在进程退出时进行更长时间的操作，而不会阻塞进程退出。

### napi_remove_async_cleanup_hook

这个接口用于取消之前注册的异步清理钩子函数。与取消同步钩子类似，这通常是在不再需要钩子函数时进行的操作。

cpp部分代码

```cpp
#include <cstdlib>
#include <string.h>
#include "napi/native_api.h"
#include "uv.h"

// 包含异步操作内容
typedef struct {
    napi_env env;
    void *testData;
    uv_async_s asyncUv;
    napi_async_cleanup_hook_handle cleanupHandle;
} AsyncContent;
// 删除异步工作对象并注销钩子函数
static void FinalizeWork(uv_handle_s *handle)
{
    AsyncContent *asyncData = reinterpret_cast<AsyncContent *>(handle->data);
    // 不再需要异步清理钩子函数的情况下，尝试将其从环境中移除
    napi_status result = napi_remove_async_cleanup_hook(asyncData->cleanupHandle);
    if (result != napi_ok) {
        napi_throw_error(asyncData->env, nullptr, "Test Node-API napi_remove_async_cleanup_hook failed");
    }
    // 释放AsyncContent
    free(asyncData);
}
// 异步执行环境清理工作
static void AsyncWork(uv_async_s *async)
{
    // 执行一些清理工作,比如释放动态分配的内存
    AsyncContent *asyncData = reinterpret_cast<AsyncContent *>(async->data);
    
    if (asyncData != nullptr && asyncData->testData != nullptr) {
        free(asyncData->testData);
        asyncData->testData = nullptr;
    }
    // 关闭libuv句柄，并触发FinalizeWork回调清理
    uv_close((uv_handle_s *)async, FinalizeWork);
}
// 异步清理钩子函数，创建异步工作对象并执行
static void AsyncCleanup(napi_async_cleanup_hook_handle handle, void *info)
{
    AsyncContent *data = reinterpret_cast<AsyncContent *>(info);
    // 获取libUv循环实例并初始化一个异步句柄，以便后续执行异步工作
    uv_loop_s *uvLoop;
    napi_get_uv_event_loop(data->env, &uvLoop);
    uv_async_init(uvLoop, &data->asyncUv, AsyncWork);

    data->asyncUv.data = data;
    data->cleanupHandle = handle;
    // 发送异步信号触发AsyncWork函数执行清理工作
    uv_async_send(&data->asyncUv);
}

static napi_value NapiAsyncCleanUpHook(napi_env env, napi_callback_info info)
{
    // 分配AsyncContent内存
    AsyncContent *data = reinterpret_cast<AsyncContent *>(malloc(sizeof(AsyncContent)));
    if (data == nullptr) {
        napi_throw_error(env, nullptr, "Test Node-API malloc AsyncContent failed");
        return nullptr;
    }
    data->env = env;
    data->cleanupHandle = nullptr;
    // 分配内存并复制字符串数据
    const char *testDataStr = "TestNapiAsyncCleanUpHook";
    data->testData = strdup(testDataStr);
    if (data->testData == nullptr) {
        free(data);
        napi_throw_error(env, nullptr, "Test Node-API data->testData is nullptr");
        return nullptr;
    }
    // 添加异步清理钩子函数
    napi_status status = napi_add_async_cleanup_hook(env, AsyncCleanup, data, &data->cleanupHandle);
    if (status != napi_ok) {
        free(data->testData);
        free(data);
        napi_throw_error(env, nullptr, "Test Node-API napi_add_async_cleanup_hook failed");
        return nullptr;
    }
    napi_value result = nullptr;
    napi_get_boolean(env, true, &result);
    return result;
}
```
<!-- @[napi_add_remove_async_cleanup_hook](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPICleanuphook/entry/src/main/cpp/napi_init.cpp) -->

由于需要包含“uv.h”库，所以需要在CMakeLists文件中添加配置：
```text
// CMakeLists.txt
target_link_libraries(entry PUBLIC libace_napi.z.so libuv.so)
```

接口声明

```ts
// index.d.ts
export const napiAsyncCleanUpHook: () => boolean | undefined;
```
<!-- @[napi_remove_add_env_cleanup_hook_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPICleanuphook/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_add_async_cleanup_hook: %{public}s', testNapi.napiAsyncCleanUpHook());
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_add_async_cleanup_hook error.message: %{public}s', error.message);
}
```
<!-- @[ark_napi_remove_add_env_cleanup_hook](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPICleanuphook/entry/src/main/ets/pages/Index.ets) -->

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
