# Implementing Asynchronous Operations Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:40:58.754Z pushedAt=2026-08-12T11:14:42.615Z -->

## Introduction

Node-API provides APIs for implementing asynchronous operations for time-consuming tasks, such as downloading data from network or reading a large file. Unlike synchronous operations, asynchronous operations are executed in the background without blocking the main thread. When an asynchronous operation is complete, it will be added to the task queue and executed when the main thread is idle.

## Basic Concepts

**Promise** is an object used to handle asynchronous operations in ArkTS. It has three states: **pending**, **fulfilled**, and **rejected**. The initial state is **pending**, which can be changed to **fulfilled** by **resolve()** and to rejected by **reject()**. Once the state is **fulfilled** or **rejected**, the promise state cannot be changed. The basic concepts are as follows:

- Synchronous: Code is executed line by line in sequence. Each line of code is executed after the previous line of code is executed. If an operation takes a long time, the entire application will be blocked.

- Asynchronous: Tasks can be executed concurrently without waiting for the end of the previous task. Common asynchronous operations apply for timers, event listening, and network requests. Instead of blocking subsequent tasks, the asynchronous task uses a callback or promise to process its result.

- **Promise**: an ArkTS object used to handle asynchronous operations. It is customized by using **then()**, **catch()**, and **finally()**.

- **deferred**: an object used to control the state of a Promise. It allows you to mark the Promise state as **fulfilled** or **rejected** at a future moment.

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

<!-- @[napi_is_promise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_is_promise
static napi_value IsPromise(napi_env env, napi_callback_info info)
{
    napi_value argv[1] = {nullptr};
    size_t argc = 1;
    napi_status status;
    // Obtain the passed-in parameters.
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    bool isPromise = false;
    // Check whether the given argument is a Promise object, and save the result in the isPromise variable.
    status = napi_is_promise(env, argv[0], &isPromise);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_is_promise failed");
        return nullptr;
    }
    napi_value result = nullptr;
    // Convert the value of isPromise to the napi_value type and return it.
    napi_get_boolean(env, isPromise, &result);
    return result;
}
```

API declaration:

<!-- @[napi_is_promise_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const isPromise: <T>(value: T) => boolean; // napi_is_promise
```

ArkTS code:

<!-- @[ark_napi_is_promise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_is_promise
let value = Promise.resolve();
// If the passed-in object is a Promise, true is returned; otherwise, false is returned.
hilog.info(0x0000, 'Node-API', 'napi_is_promise %{public}s', testNapi.isPromise(value));
hilog.info(0x0000, 'Node-API', 'napi_is_promise string %{public}s', testNapi.isPromise(''));
```

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

<!-- @[napi_resolve_reject_deferred](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_resolve_deferred & napi_reject_deferred
static napi_value CreatePromise(napi_env env, napi_callback_info info)
{
    // deferred is an object associated with a Promise object, used to control the Promise state (resolve or reject).
    napi_deferred deferred = nullptr;
    napi_value promise = nullptr;
    // Call the API to create a Promise object.
    napi_status status = napi_create_promise(env, &deferred, &promise);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Create promise failed");
        return nullptr;
    }
    // Call napi_is_promise to check whether the object created by napi_create_promise is a Promise object.
    bool isPromise = false;
    napi_value returnIsPromise = nullptr;
    status = napi_is_promise(env, promise, &isPromise);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_is_promise failed");
        return nullptr;
    }
    // Convert the boolean value to napi_value that can be returned.
    napi_get_boolean(env, isPromise, &returnIsPromise);
    return returnIsPromise;
}

static napi_value ResolveRejectDeferred(napi_env env, napi_callback_info info)
{
    // Obtain and parse the parameters.
    size_t argc = 3;
    napi_value args[3] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // The first parameter is the information passed to resolve, the second parameter is the information passed to reject, and the third parameter is the Promise state.
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
    // Set resolve or reject based on the third parameter.
    if (promiseStatus) {
        napi_resolve_deferred(env, deferred, args[INT_ARG_0]);
    } else {
        napi_reject_deferred(env, deferred, args[INT_ARG_1]);
    }
    // Return the Promise object with resolve or reject set.
    return promise;
}
```

API declaration example:

<!-- @[napi_resolve_reject_deferred_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createPromise: () => boolean | undefined; // napi_resolve_deferred & napi_reject_deferred

export const resolveRejectDeferred: (resolve: string, reject: string, status: boolean) => Promise<string> | undefined;
```

ArkTS code:

<!-- @[ark_napi_resolve_reject_deferred](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_resolve_deferred & napi_reject_deferred
// If the promise is created successfully, true is returned; otherwise, false is returned.
hilog.info(0x0000, 'Node-API', 'napi_create_promise %{public}s', testNapi.createPromise());
// Call the resolveRejectDeferred function to set the return results of resolve and reject, as well as the Promise state.
// When the Promise state is true, resolve is set, and the return result is obtained in the then function.
let promiseSuccess: Promise<string> =
  testNapi.resolveRejectDeferred('success', 'fail', true) as Promise<string>;
promiseSuccess.then((res) => {
  hilog.info(0x0000, 'Node-API', 'get_resolve_deferred resolve %{public}s', res);
  // ...
}).catch((err: Error) => {
  hilog.info(0x0000, 'Node-API', 'get_resolve_deferred reject %{public}s', err);
  // ...
})
// When the Promise state is false, reject is set, and the return result is obtained in the catch function.
let promiseFail: Promise<string> =
  testNapi.resolveRejectDeferred('success', 'fail', false) as Promise<string>;
promiseFail.then((res) => {
  hilog.info(0x0000, 'Node-API', 'get_resolve_deferred resolve %{public}s', res);
  // ...
}).catch((err: Error) => {
  hilog.info(0x0000, 'Node-API', 'get_resolve_deferred reject %{public}s', err);
  // ...
})
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```