# Implementing Asynchronous Operations Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Introduction

JSVM-API provides APIs for implementing asynchronous operations. An asynchronous operation is used for a time-consuming task, for example, downloading data from network or reading a large file. Unlike a synchronous operation which blocks the main thread, the asynchronous operation is executed in the background. When an asynchronous operation is complete, it will be put into the task queue and executed when the main thread is idle.

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
| OH_JSVM_PromiseRegisterHandler | Registers a callback to be invoked after a promise is fulfilled or rejected.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in promise development.

### OH_JSVM_IsPromise

Call **OH_JSVM_IsPromise** to check whether the given **JSVM_Value** is a **Promise** object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
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
// Register the IsPromise callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsPromise},
};
static JSVM_CallbackStruct *method = param;
// Alias for the IsPromise method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"isPromise", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char *srcCallNative = R"JS(isPromise())JS";
```
<!-- @[oh_jsvm_ispromise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPromise/ispromise/src/main/cpp/hello.cpp) -->

Expected result:
```
JSVM OH_JSVM_IsPromise success:0
```

### OH_JSVM_CreatePromise

Call **OH_JSVM_CreatePromise** to create a **Promise** object.

### OH_JSVM_ResolveDeferred and OH_JSVM_RejectDeferred

Call **OH_JSVM_ResolveDeferred** to change the promise state from **pending** to **fulfilled**, and call **OH_JSVM_RejectDeferred** to change the promise state from **pending** to **rejected**.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
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
    bool status = false;
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
// Register the CreatePromise and ResolveRejectDeferred callbacks.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreatePromise},
    {.data = nullptr, .callback = ResolveRejectDeferred},
};
static JSVM_CallbackStruct *method = param;
// Aliases for the CreatePromise and ResolveRejectDeferred methods to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createPromise", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"resolveRejectDeferred", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char *srcCallNative = R"JS(createPromise();
                                 resolveRejectDeferred('success', 'fail', true);
                                 resolveRejectDeferred('success', 'fail', false);)JS";
```
<!-- @[oh_jsvm_resolvedeferred_and_rejectdeferred](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPromise/resolvereject/src/main/cpp/hello.cpp) -->

Expected result:
```
JSVM CreatePromise success:1
OH_JSVM_ResolveDeferred resolve
OH_JSVM_RejectDeferred reject
```

## OH_JSVM_PromiseRegisterHandler

Call **OH_JSVM_PromiseRegisterHandler** to register a callback that is invoked after a promise is fulfilled rejected. It is equivalent to calling the native **Promise.then()** or **Promise.catch()**.

The following describes only part of the C++ code. For details about other framework code, such as the **TestJSVM** function, see the implementation of **OH_JSVM_SetMicrotaskPolicy** in [Working with Tasks Using JSVM-API](use-jsvm-execute_tasks.md).

```cpp
static int PromiseRegisterHandler(JSVM_VM vm, JSVM_Env env) {
    const char *defineFunction = R"JS(
        var x1 = 0;
        var x2 = 0;
        function f1(x) {
            x1 = x;
            return x + 1;
        }
        function f2(x) {
            x2 = x;
            return x + 1;
        }
    )JS";

    const char *init = R"JS(
        x1 = 0;
        x2 = 0;
    )JS";

    JSVM_Script script;
    JSVM_Value jsSrc;
    JSVM_Value result;

    // Define the JS functions f1 and f2.
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, defineFunction, JSVM_AUTO_LENGTH, &jsSrc));
    CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));

    // Initialize x1 and x2 to 0.
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, init, JSVM_AUTO_LENGTH, &jsSrc));
    CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));

    // Obtain functions f1 and f2.
    JSVM_Value global;
    CHECK_RET(OH_JSVM_GetGlobal(env, &global));
    JSVM_Value f1;
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "f1", &f1));
    JSVM_Value f2;
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "f2", &f2));

    // Create a promise.
    JSVM_Value promise;
    JSVM_Deferred deferred;
    CHECK_RET(OH_JSVM_CreatePromise(env, &deferred, &promise));
    // Register a callback for the promise and assign the result (new promise) of then() to promise1.
    JSVM_Value promise1;
    CHECK_RET(OH_JSVM_PromiseRegisterHandler(env, promise, f1, nullptr, &promise1));
    // Register a callback for promise1.
    CHECK_RET(OH_JSVM_PromiseRegisterHandler(env, promise1, f2, nullptr, nullptr));

    // Obtain the values of x1 and x2 before the promise is parsed.
    JSVM_Value x1;
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "x1", &x1));
    int32_t x1Int = 0;
    CHECK_RET(OH_JSVM_GetValueInt32(env, x1, &x1Int));
    JSVM_Value x2;
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "x2", &x2));
    int32_t x2Int = 0;
    CHECK_RET(OH_JSVM_GetValueInt32(env, x2, &x2Int));
    OH_LOG_INFO(LOG_APP, "Before promise resolved, x1: %{public}d, x2: %{public}d", x1Int, x2Int);

    // Parse the promise.
    JSVM_Value resolveValue;
    CHECK_RET(OH_JSVM_CreateInt32(env, 2, &resolveValue));
    if (deferred != nullptr) {
        OH_JSVM_ResolveDeferred(env, deferred, resolveValue);
        deferred = nullptr;
    }

    // Obtain the values of x1 and x2 after the promise is parsed.
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "x1", &x1));
    CHECK_RET(OH_JSVM_GetValueInt32(env, x1, &x1Int));
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "x2", &x2));
    CHECK_RET(OH_JSVM_GetValueInt32(env, x2, &x2Int));
    OH_LOG_INFO(LOG_APP, "After promise resolved, x1: %{public}d, x2: %{public}d", x1Int, x2Int);

    return 0;
}

static void RunDemo(JSVM_VM vm, JSVM_Env env) {
    if (PromiseRegisterHandler(vm, env) != 0) {
        OH_LOG_INFO(LOG_APP, "Run PromiseRegisterHandler failed");
    }
}
```

Expected result:
```
Before promise resolved, x1: 0, x2: 0
After promise resolved, x1: 2, x2: 3
```
