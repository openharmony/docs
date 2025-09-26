# Implementing Asynchronous Operations Using Node-API
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## Introduction

Node-API provides APIs for implementing asynchronous operations for time-consuming tasks, such as downloading data from network or reading a large file. Unlike synchronous operations, asynchronous operations are executed in the background without blocking the main thread. When an asynchronous operation is complete, it will be added to the task queue and executed when the main thread is idle.

## Basic Concepts

**Promise** is an object used to handle asynchronous operations in ArkTS. It has three states: **pending**, **fulfilled**, and **rejected**. The initial state is **pending**, which can be changed to **fulfilled** by **resolve()** and to rejected by **reject()**. Once the state is **fulfilled** or **rejected**, the promise state cannot be changed. The basic concepts are as follows:

- Synchronous: Code is executed line by line in sequence. Each line of code is executed after the previous line of code is executed. If an operation takes a long time, the entire application will be blocked.
- Asynchronous: Tasks can be executed concurrently without waiting for the end of the previous task. Common asynchronous operations apply for timers, event listening, and network requests. Instead of blocking subsequent tasks, the asynchronous task uses a callback or promise to process its result.
- **Promise**: an ArkTS object used to handle asynchronous operations. It is customized by using **then()**, **catch()**, and **finally()**.
- **deferred**: a deferred object associated with **Promise**. It is used to set the callbacks **resolve()** and **reject()** of **Promise** to maintain the asynchronous model state.
- **resolve**: a function used to change the promise state from **pending** to **fulfilled**. The parameters passed to **resolve()** can be obtained from **then()** of the **Promise** object.
- **reject**: a function used to change the promise state from **pending** to **rejected**. The parameters passed to **reject()** can be obtained from **catch()** of the **Promise** object.

**Promise** allows multiple callbacks to be called in a chain, providing better code readability and a better way to deal with asynchronous operations. The APIs provided by the Node-API module help you flexibly process ArkTS asynchronous operations in C/C++.

## Available APIs

The following table lists the APIs for implementing asynchronous operations using ArkTS promises.   

| API| Description|
| -------- | -------- |
| napi_is_promise | Checks whether a **napi_value** is a **Promise** object.|
| napi_create_promise | Creates a **Promise** object.|
| napi_resolve_deferred | Resolves a promise by using the **deferred** object associated with it.|
| napi_reject_deferred | Rejects a promise by using the **deferred** object associated with it|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code related to promise development.

### napi_is_promise

Call **napi_is_promise** to check whether the given **napi_value** is a **Promise** object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value IsPromise(napi_env env, napi_callback_info info)
{
    napi_value argv[1] = {nullptr};
    size_t argc = 1;
    napi_status status;
    // Obtain the parameters passed in.
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    bool isPromise = false;
    // Check whether the given parameter is a Promise object and save the result in the isPromise variable.
    status = napi_is_promise(env, argv[0], &isPromise);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_is_promise failed");
        return nullptr;
    }
    napi_value result = nullptr;
    // Convert the value of isPromise to the type specified by napi_value, and return it.
    napi_get_boolean(env, isPromise, &result);
    return result;
}
```
<!-- @[napi_is_promise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const isPromise: <T>(value: T) => boolean;
```
<!-- @[napi_is_promise_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let value = Promise.resolve();
// Return true if the object passed in is a promise; return false otherwise.
hilog.info(0x0000, 'Node-API', 'napi_is_promise %{public}s', testNapi.isPromise(value));
hilog.info(0x0000, 'Node-API', 'napi_is_promise string %{public}s', testNapi.isPromise(''));
```
<!-- @[ark_napi_is_promise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/ets/pages/Index.ets) -->

### napi_create_promise

Call **napi_create_promise** to create a **Promise** object.

When using this API, observe to the following:

1. If **napi_create_promise** is called when there is an exception not handled, **napi_pending_exception** will be returned.
2. After calling **napi_create_promise**, always check whether the return value is **napi_ok**. If **deferred** and **promise** are used, the application will crash.

```c++
napi_value NapiPromiseDemo(napi_env env, napi_callback_info info)
{
    napi_deferred deferred = nullptr;
    napi_value promise = nullptr;
    napi_status status = napi_ok;

    napi_throw_error(env, "500", "common error");

    status = napi_create_promise(env, &deferred, &promise); // If there is an error, return napi_pending_exception with deferred and promise set to nullptr.
    if (status == napi_ok) {
        // do something
    }

    return nullptr;
}
```

### napi_resolve_deferred & napi_reject_deferred

Call **napi_resolve_deferred** to change the promise state from **pending** to **fulfilled**, and call **napi_reject_deferred** to change the promise state from **pending** to **rejected**.

To ensure execution of microtasks, the ArkTS runtime will trigger a microtask execution when fulfilling a promise using Node-API.

CPP code:

```cpp
#include "napi/native_api.h"

static constexpr int INT_ARG_2 = 2; // Input parameter index.

static napi_value CreatePromise(napi_env env, napi_callback_info info)
{
    // The deferred object is used to delay the execution of a function for a certain period of time.
    napi_deferred deferred = nullptr;
    napi_value promise = nullptr;
    // Create a Promise object.
    napi_status status = napi_create_promise(env, &deferred, &promise);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Create promise failed");
        return nullptr;
    }
    //Call napi_is_promise to check whether the object created by napi_create_promise is a Promise object.
    bool isPromise = false;
    napi_value returnIsPromise = nullptr;
    status = napi_is_promise(env, promise, &isPromise);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_is_promise failed");
        return nullptr;
    }
    // Convert the Boolean value to napi_value and return it.
    napi_get_boolean(env, isPromise, &returnIsPromise);
    return returnIsPromise;
}

static napi_value ResolveRejectDeferred(napi_env env, napi_callback_info info)
{
    // Obtain and parse parameters.
    size_t argc = 3;
    napi_value args[3] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // The first parameter is the data to be passed to Resolve(), the second parameter is the data to be passed to reject(), and the third parameter is the Promise state.
    bool promiseStatus;
    napi_status status = napi_get_value_bool(env, args[INT_ARG_2], &promiseStatus);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_get_value_bool failed");
        return nullptr;
    }

    // Create a Promise object.
    napi_deferred deferred = nullptr;
    napi_value promise = nullptr;
    status = napi_create_promise(env, &deferred, &promise);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Create promise failed");
        return nullptr;
    }
    // Set the promise state based on the third parameter.
    if (promiseStatus) {
        napi_resolve_deferred(env, deferred, args[0]);
    } else {
        napi_reject_deferred(env, deferred, args[1]);
    }
    // Return the Promise object with the state set.
    return promise;
}
```
<!-- @[napi_resolve_reject_deferred](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/cpp/napi_init.cpp) -->

API declaration example:

```ts
// index.d.ts
export const createPromise: () => boolean | undefined;
export const resolveRejectDeferred: (resolve: string, reject: string, status: boolean) => Promise<string> | undefined;
```
<!-- @[napi_resolve_reject_deferred_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

// Create a promise. Return true if the operation is successful, and return false otherwise.
hilog.info(0x0000, 'Node-API', 'napi_create_promise %{public}s', testNapi.createPromise());
// Call resolveRejectDeferred to resolve or reject the promise and set the promise state.
// Resolve the promise. The return value is passed to the then function.
let promiseSuccess: Promise<string> = testNapi.resolveRejectDeferred('success', 'fail', true) as Promise<string>;
promiseSuccess.then((res) => {
  hilog.info(0x0000, 'Node-API', 'get_resolve_deferred resolve %{public}s', res)
}).catch((err: Error) => {
  hilog.info(0x0000, 'Node-API', 'get_resolve_deferred reject %{public}s', err)
})
// Reject the promise. The return value is passed to the catch function.
let promiseFail: Promise<string> = testNapi.resolveRejectDeferred('success', 'fail', false) as Promise<string>;
promiseFail.then((res) => {
  hilog.info(0x0000, 'Node-API', 'get_resolve_deferred resolve %{public}s', res)
}).catch((err: Error) => {
  hilog.info(0x0000, 'Node-API', 'get_resolve_deferred reject %{public}s', err)
})
```
<!-- @[ark_napi_resolve_reject_deferred](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/ets/pages/Index.ets) -->

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
