# Customizing Asynchronous Operations Using Node-API

## Introduction

Node-API provides APIs for customizing asynchronous (async for short) operations to handle time-consuming tasks that may block event loops while maintaining quick response and high performance of ArkTS applications.

## Basic Concepts

Async operations are used to complete I/O-intensive or compute-intensive tasks, which usually need to be executed without blocking the main thread. Before you get started, understand the following concepts:

- Async model: Node-API provides APIs that implement async operations using a promise or a callback. Promise is a programming model based on future values. It allows results of async operations to be encapsulated in objects and called in a chain. Callback is a traditional async programming mode. It uses callback functions to process async operation results.
- Temporary result: When a native method (Node-API) is called, it immediately returns a temporary result to the ArkTS caller. The temporary result is usually a flag indicating an async operation being performed or a handle for subsequent processing of an async operation result.
- Callback/Promise: When an async operation is complete, the result is returned to the ArkTS caller through a callback function or a promise object. This allows the processing of the subsequent logic after the async operation is complete.

## Available APIs

The following table lists the APIs provided by the Node-API module for customizing async operations. You can use these APIs to implement ArkTS callbacks and manage the resource lifecycle in C/C++. These APIs help implement complex async operations and effective interaction with ArkTS.  
| API| Description|
| -------- | -------- |
| napi_async_init, napi_async_destroy| Creates/Destroys an async context. <br/>You can use these APIs to handle time-consuming tasks, such as file I/O operations and network requests, without blocking the main thread. You can use **napi_async_init** to create an async context for executing the task, and use **napi_async_destroy** after the task is complete to destroy and release related resources.|
| napi_make_callback | Executes an ArkTS callback function in an async context and returns the operation result to ArkTS.|
| napi_open_callback_scope, napi_close_callback_scope| Opens/Closes a callback scope. You can use these APIs to execute ArkTS code and manage its context during the async operation.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code involved in the APIs for customizing async operations.

### napi_async_init and napi_async_destroy

Use **napi_async_init** to create an async context, and use **napi_async_destroy** to destroy an async context. Note that these APIs do not support capabilities related to **async_hook**.

### napi_make_callback

To call and execute an ArkTS callback after an async operation is complete, use **napi_make_callback**.

### napi_open_callback_scope and napi_close_callback_scope

To make the ArkTS context still available during an async operation, use **napi_open_callback_scope** to create a scope for the callback. You can use **napi_close_callback_scope** to close the scope after the async operation is complete.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value AsynchronousWork(napi_env env, napi_callback_info info)
{
    // Initialize an array to hold four parameters.
    size_t argc = 4;
    napi_value args[4] = {nullptr};
    // Obtain parameters from the callback information.
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Extract resources, receiver objects, and functions from the parameters.
    napi_value resource = args[0];
    napi_value recv = args[1];
    napi_value func = args[2];
    napi_value argv[1] = {nullptr};
    argv[0] = args[3];
    // Obtain the function type.
    napi_valuetype funcType;
    napi_typeof(env, func, &funcType);
    // Create a string named "test".
    napi_value resourceName = nullptr;
    napi_create_string_utf8(env, "test", NAPI_AUTO_LENGTH, &resourceName);
    // Initialize the async context.
    napi_async_context context;
    napi_status status = napi_async_init(env, resource, resourceName, &context);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_async_init fail");
        return nullptr;
    }
    // Open a callback scope.
    napi_callback_scope scope = nullptr;
    napi_open_callback_scope(env, resource, context, &scope);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_open_callback_scope fail");
        return nullptr;
    }
    // Invoke the callback function defined.
    napi_value result = nullptr;
    if (funcType == napi_function) {
        napi_make_callback(env, context, recv, func, 1, argv, &result);
    } else {
        napi_throw_error(env, nullptr, "Unexpected argument type");
        return nullptr;
    }
    // Close the callback scope.
    napi_close_callback_scope(env, scope);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_close_callback_scope fail");
        return nullptr;
    }
    // Destroy the async context.
    napi_async_destroy(env, context);
    return result;
}
```

API declaration:

```ts
// index.d.ts
export const asynchronousWork: (object: Object, obj: Object, fun: Function, num: number) => number | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
import process from '@ohos.process'
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API asynchronousWork: %{public}d', testNapi.asynchronousWork({}, process.ProcessManager, (num: number)=>{return num;}, 123));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API asynchronousWork error: %{public}s', error.message);
}
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so )
```
