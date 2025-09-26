# Working with Cleanup Hooks Using Node-API
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## Introduction

Node-API provides APIs for adding and removing cleanup hooks, which are called to release resources when the environment exits.

## Basic Concepts

Before using Node-API to add or remove cleanup hooks, understand the following concepts:

- Resource management<br>In ArkTS, you need to manage system resources, such as memory, file handles, and network connections. Properly creating, using, and releasing these resources during the lifecycle of the Node-API module can prevent resource leaks and application breakdown. Resource management usually includes initializing resources, clearing resources when required, and performing necessary operations when clearing resources, such as closing a file or disconnecting from the network.
- Hook function<br>A hook function is a callback that is automatically executed at the specified time or upon a specific event. When an environment or a process exits, not all the resources can be automatically reclaimed immediately. In the context of a Node-API module, the cleanup hooks are a supplement that ensures release of all the resources occupied.

So far, you've learnt resource management in ArkTS and cleanup hook functions. Read on to learn the Node-API interfaces that you can use to perform resource management with cleanup hooks.

## Available APIs

The following table lists the APIs for using different types of cleanup hooks.  

| API| Description|
| -------- | -------- |
| napi_add_env_cleanup_hook | Adds an environment cleanup hook function, which will be called when the Node-API environment exits.|
| napi_remove_env_cleanup_hook | Removes an environment cleanup hook function.|
| napi_add_async_cleanup_hook | Adds an async cleanup hook function, which will be executed asynchronously when the Node-API process exits.|
| napi_remove_async_cleanup_hook | Removes an async cleanup hook function.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code involved in the APIs for cleanup hooks.

### napi_add_env_cleanup_hook

Call **napi_add_env_cleanup_hook** to add an environment cleanup hook function, which will be executed when the environment exits. This ensures that resources are released before the environment is destroyed.

Note that **napi_add_env_cleanup_hook** does not support binding multiple callbacks to the same **arg**. If **env** is destroyed but the **cleanup** callback has not been executed, you can locate the failed calls with "AddCleanupHook Failed, data cannot register multiple times." on HiLog if the ArkTS runtime [multi-thread check](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-multi-thread-check) is enabled.

### napi_remove_env_cleanup_hook

Call **napi_remove_env_cleanup_hook** to remove the previously added environment cleanup hook function. You may need to use this API when an addon is uninstalled or resources are reallocated.

CPP code:

```cpp
#include <hilog/log.h>
#include <string>
#include "napi/native_api.h"
// Define the memory struct, including the pointer to the data and the data size.
typedef struct {
    char *data;
    size_t size;
} Memory;
// Callback for clearing the external buffer. It is used to release the allocated memory.
void ExternalFinalize(napi_env env, void *finalize_data, void *finalize_hint)
{
    Memory *wrapper = (Memory *)finalize_hint;
    free(wrapper->data);
    free(wrapper);
    OH_LOG_INFO(LOG_APP, "Node-API napi_add_env_cleanup_hook ExternalFinalize");
}
// Perform cleanup operations when the environment is closed, for example, clear global variables or other resources.
static void Cleanup(void *arg)
{
    // Perform the cleanup operation.
    OH_LOG_INFO(LOG_APP, "Node-API napi_add_env_cleanup_hook cleanuped: %{public}d", *(int *)(arg));
}
// Create an external buffer and add the environment cleanup hook function.
static napi_value NapiEnvCleanUpHook(napi_env env, napi_callback_info info)
{
    // Allocate memory and copy the string to the memory.
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
    // Create an external buffer object and specify the cleanup callback function.
    // Note: The memory release of wrapper->data depends on the ExternalFinalize callback. ExternalFinalize is called only when the buffer is correctly held and finally reclaimed by GC. Otherwise, memory leaks occur.
    napi_value buffer = nullptr;
    napi_status status = napi_create_external_buffer(env, wrapper->size, (void *)wrapper->data, ExternalFinalize, wrapper, &buffer);
    if (status != napi_ok) {
        // If the creation fails, proactively release the memory to avoid memory leaks.
        free(wrapper->data);
        free(wrapper);
        OH_LOG_ERROR(LOG_APP, "napi_create_external_buffer failed");
        return nullptr;
    }
    // Use static variables as hook function parameters.
    static int hookArg = 42;
    static int hookParameter = 1;
    // Add a cleanup hook function for releasing resources when the environment exits.
    status = napi_add_env_cleanup_hook(env, Cleanup, &hookArg);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "Test Node-API napi_add_env_cleanup_hook failed.");
        return nullptr;
    }
    // Add the environment cleanup hook function. The hook function is not removed here to make it called to simulate some cleanup operations, such as releasing resources and closing files, when the Java environment is destroyed.
    status = napi_add_env_cleanup_hook(env, Cleanup, &hookParameter);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "Test Node-API napi_add_env_cleanup_hook failed.");
        return nullptr;
    }
    // Remove the environment cleanup hook function immediately.
    // Generally, use this API when the resource associated with the hook must be released.
    napi_remove_env_cleanup_hook(env, Cleanup, &hookArg);
    napi_remove_env_cleanup_hook(env, Cleanup, &hookParameter);
    // Return the created external buffer object.
    return buffer;
}
```
<!-- @[napi_remove_add_env_cleanup_hook](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPICleanuphook/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const napiEnvCleanUpHook: () => Object | undefined;
```
<!-- @[napi_remove_add_env_cleanup_hook_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPICleanuphook/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
// index.ets
import { hilog } from '@kit.PerformanceAnalysisKit';
import worker from '@ohos.worker';

let wk = new worker.ThreadWorker("entry/ets/workers/worker.ts");
// Send a message to the worker thread.
wk.postMessage("test NapiEnvCleanUpHook");
// Process the message from the worker thread.
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
// Process messages from the main thread.
parent.onmessage = (message) => {
  hilog.info(0x0000, 'testTag', 'Test Node-API message from main thread: %{public}s', JSON.stringify(message));
  // Send a message to the main thread.
  parent.postMessage('Test Node-API worker:' + testNapi.napiEnvCleanUpHook());
};
```
<!-- @[connect_with_main_thread](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPICleanuphook/entry/src/main/ets/workers/worker.ts) -->

For details about the worker development, see:
[Worker Introduction](../arkts-utils/worker-introduction.md)

### napi_add_async_cleanup_hook

Call **napi_add_async_cleanup_hook** to add an async cleanup hook function, which will be executed asynchronously when the environment exits. Unlike a sync hook, an async hook allows a longer operation without blocking the process exit.

### napi_remove_async_cleanup_hook

Call **napi_remove_async_cleanup_hook** to remove an async cleanup hook function that is no longer required.

CPP code:

```cpp
#include <cstdlib>
#include <string.h>
#include "napi/native_api.h"
#include "uv.h"

// Async operation content.
typedef struct {
    napi_env env;
    void *testData;
    uv_async_s asyncUv;
    napi_async_cleanup_hook_handle cleanupHandle;
} AsyncContent;
// Delete the async work object and remove the hook function.
static void FinalizeWork(uv_handle_s *handle)
{
    AsyncContent *asyncData = reinterpret_cast<AsyncContent *>(handle->data);
    // Remove the hook function from the environment when it is no longer required.
    napi_status result = napi_remove_async_cleanup_hook(asyncData->cleanupHandle);
    if (result != napi_ok) {
        napi_throw_error(asyncData->env, nullptr, "Test Node-API napi_remove_async_cleanup_hook failed");
    }
    // Release AsyncContent.
    free(asyncData);
}
// Asynchronously clear the environment.
static void AsyncWork(uv_async_s *async)
{
    // Perform cleanup operations, for example, release the dynamically allocated memory.
    AsyncContent *asyncData = reinterpret_cast<AsyncContent *>(async->data);
    
    if (asyncData != nullptr && asyncData->testData != nullptr) {
        free(asyncData->testData);
        asyncData->testData = nullptr;
    }
    // Close the libuv handle and trigger the FinalizeWork callback to clear the handle.
    uv_close((uv_handle_s *)async, FinalizeWork);
}
// Create and trigger an async cleanup operation in an event loop.
static void AsyncCleanup(napi_async_cleanup_hook_handle handle, void *info)
{
    AsyncContent *data = reinterpret_cast<AsyncContent *>(info);
    // Obtain a libuv loop instance and initialize a handle for subsequent async work.
    uv_loop_s *uvLoop;
    napi_get_uv_event_loop(data->env, &uvLoop);
    uv_async_init(uvLoop, &data->asyncUv, AsyncWork);

    data->asyncUv.data = data;
    data->cleanupHandle = handle;
    // Send an async signal to trigger the AsyncWork function to perform cleanup.
    uv_async_send(&data->asyncUv);
}

static napi_value NapiAsyncCleanUpHook(napi_env env, napi_callback_info info)
{
    // Allocate the AsyncContent memory.
    AsyncContent *data = reinterpret_cast<AsyncContent *>(malloc(sizeof(AsyncContent)));
    if (data == nullptr) {
        napi_throw_error(env, nullptr, "Test Node-API malloc AsyncContent failed");
        return nullptr;
    }
    data->env = env;
    data->cleanupHandle = nullptr;
    // Allocate memory and copy string data.
    const char *testDataStr = "TestNapiAsyncCleanUpHook";
    data->testData = strdup(testDataStr);
    if (data->testData == nullptr) {
        free(data);
        napi_throw_error(env, nullptr, "Test Node-API data->testData is nullptr");
        return nullptr;
    }
    // Add an async cleanup hook function.
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

Since the uv.h library is used, add the following configuration to the CMakeLists file:
```text
// CMakeLists.txt
target_link_libraries(entry PUBLIC libace_napi.z.so libuv.so)
```

API declaration:

```ts
// index.d.ts
export const napiAsyncCleanUpHook: () => boolean | undefined;
```
<!-- @[napi_remove_add_env_cleanup_hook_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPICleanuphook/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

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

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
