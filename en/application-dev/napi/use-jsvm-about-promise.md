# Implementing Asynchronous Operations Using JSVM-API

## Introduction

JSVM-API provides APIs for implementing asynchronous operations. An asynchronous operation is used for a time-consuming task, for example, downloading data from network or reading a large file. Different from a synchronous operation which blocks the main thread, the asynchronous operation is executed in the background. When an asynchronous operation is complete, it will be put into the task queue and executed when the main thread is idle.

## Basic Concepts

**Promise** is an object used to handle asynchronous operations in JavaScript (JS). It has three states: **pending**, **fulfilled**, and **rejected**. The initial state is **pending**, which can be changed to **fulfilled** by **resolve()** and to **rejected** by **reject()**. Once the state is **fulfilled** or **rejected**, the promise state cannot be changed. Read on the following to learn basic concepts related to **Promise**:

- Synchronous: Code is executed line by line in sequence. Each line of code is executed after the previous line of code is executed. During synchronous execution, if an operation takes a long time, the execution of the entire application will be blocked until the operation is complete.
- Asynchronous: Tasks can be executed concurrently without waiting for the end of the previous task. In JS, common asynchronous operations apply for timers, event listening, and network requests. Instead of blocking subsequent tasks, the asynchronous task uses a callback or promise to process its result.
- **Promise**: a JS object used to handle asynchronous operations. Generally, it is exposed externally by using **then()**, **catch()**, or **finally()** to custom logic.
- **deferred**: a utility object associated with the **Promise** object to set **resolve()** and **reject()** of **Promise**. It is used internally to maintain the state of the asynchronous model and set the **resolve()** and **reject()** callbacks.
- **resolve**: a function used to change the promise state from **pending** to **fulfilled**. The parameters passed to **resolve()** can be obtained from **then()** of the **Promise** object.
- **reject**: a function used to change the promise state from **pending** to **rejected**. The parameters passed to **reject()** can be obtained from **catch()** of the **Promise** object.

**Promise** allows multiple callbacks to be called in a chain, providing better code readability and a better way to deal with asynchronous operations. JSVM-API provides APIs for implementing JS promises in C/C++.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_IsPromise            | Checks whether the given **JSVM_Value** is a **Promise** object.|
| OH_JSVM_CreatePromise        | Creates a **deferred** object and a JS promise.|
| OH_JSVM_ResolveDeferred      | Resolves a JS promise by using the **deferred** object associated with it.|
| OH_JSVM_RejectDeferred       | Rejects a JS promise by using the **deferred** object associated with it.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following only demonstrates the C++ and ArkTS code related to promises.

### OH_JSVM_IsPromise

Use **OH_JSVM_IsPromise** to check whether the given **JSVM_Value** is a **Promise** object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the IsPromise callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsPromise},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named isPromise and associate it with a callback. This allows the IsPromise callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"isPromise", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_IsPromise.
static JSVM_Value IsPromise(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool isPromise = false;
    JSVM_Status status = OH_JSVM_IsPromise(env, args[0], &isPromise);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_IsPromise fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_IsPromise success:%{public}d", isPromise);
    }
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, isPromise, &result);
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `
          let value = Promise.resolve();
          isPromise(value);
        `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'IsPromise: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'IsPromise: %{public}s', error.message);
}
```

### OH_JSVM_CreatePromise

Use **OH_JSVM_CreatePromise** to create a **Promise** object.

### OH_JSVM_ResolveDeferred & OH_JSVM_RejectDeferred

Use **OH_JSVM_ResolveDeferred** to change the promise state from **pending** to **fulfilled**, and use **OH_JSVM_RejectDeferred** to change the promise state from **pending** to **rejected**.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CreatePromise and ResolveRejectDeferred callbacks.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreatePromise},
    {.data = nullptr, .callback = ResolveRejectDeferred},
};
static JSVM_CallbackStruct *method = param;
// Set property descriptor named createPromise and resolveRejectDeferred and associate them with a callback each. This allows the CreatePromise and ResolveRejectDeferred callbacks to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createPromise", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"resolveRejectDeferred", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CreatePromise, OH_JSVM_ResolveDeferred, and OH_JSVM_RejectDeferred.
static JSVM_Value CreatePromise(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Deferred defer = nullptr;
    JSVM_Value promise = nullptr;
    JSVM_Status status = OH_JSVM_CreatePromise(env, &defer, &promise);
    bool isPromise = false;
    JSVM_Value returnIsPromise = nullptr;
    OH_JSVM_IsPromise(env, promise, &isPromise);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreatePromise fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM CreatePromise success:%{public}d", isPromise);
    }
    // Convert the Boolean value to JSVM_Value and return it.
    OH_JSVM_GetBoolean(env, isPromise, &returnIsPromise);
    return returnIsPromise;
}

static JSVM_Value ResolveRejectDeferred(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain and parse parameters.
    size_t argc = 3;
    JSVM_Value args[3] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // The first parameter is the data to be passed to Resolve(), the second parameter is the data to be passed to reject(), and the third parameter is the Promise state.
    bool status;
    OH_JSVM_GetValueBool(env, args[2], &status);
    // Create a Promise object.
    JSVM_Deferred deferred = nullptr;
    JSVM_Value promise = nullptr;
    JSVM_Status createStatus = OH_JSVM_CreatePromise(env, &deferred, &promise);
    if (createStatus != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "Create promise failed");
        return nullptr;
    }
    // Set the promise state based on the third parameter.
    if (status) {
        OH_JSVM_ResolveDeferred(env, deferred, args[0]);
        OH_LOG_INFO(LOG_APP, "OH_JSVM_ResolveDeferred resolve");
    } else {
        OH_JSVM_RejectDeferred(env, deferred, args[1]);
        OH_LOG_INFO(LOG_APP, "OH_JSVM_RejectDeferred reject");
    }
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, true, &result);
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let createPromiseScript: string = `createPromise();`;
let createPromiseresult = napitest.runJsVm(createPromiseScript);
hilog.info(0x0000, 'JSVM', 'CreatePromise: %{public}s', createPromiseresult);
// The third input parameter means to change the Promise state from pending to fulfilled.
let resolveScript: string = `resolveRejectDeferred('success','fail', true);`;
let result = napitest.runJsVm(resolveScript);
hilog.info(0x0000, 'JSVM', 'ResolveRejectDeferred: %{public}s', result);
// The third input parameter means to change the Promise state from pending to rejected.
let rejectScript: string = `resolveRejectDeferred('success','fail', false);`;
let rejectResult = napitest.runJsVm(rejectScript);
hilog.info(0x0000, 'JSVM', 'ResolveRejectDeferred: %{public}s', rejectResult);
```
