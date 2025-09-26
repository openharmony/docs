# FAQs About Memory Leaks
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## Is there any mechanism to check whether napi_ref leaks

- Question: When **napi_create_reference** is used to create a reference to a JS object, **napi_delete_reference** needs to be used to release the JS object. If **napi_delete_reference** is not used, the JS object memory may leak. Is there any mechanism to check or test whether **napi_ref** leaks? 
- Answer: 
Use Allocation provided by DevEco Studio. 
For details, see [Memory Analysis: Allocation](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-insight-session-allocations). 
The internal implementation of the **napi_create_reference** API creates a C++ object. Therefore, if you forget to use the **napi_delete_reference** API, the new C++ object will leak. In this case, you can use Allocation to print the allocation stack of the unreleased objects, where you can check whether **napi_ref** leaks. 

## How do I locate and resolve memory leaks during Node-API development

The memory usage increases when the button is clicked, and the memory cannot be reclaimed even if GC is triggered. How do I locate and resolve memory leaks during Node-API development?

- Answer: 
You need to understand the Node-API lifecycle mechanism. The references are as follows: 
[Performing Lifecycle Management Using Node-API](use-napi-life-cycle.md) 
Common causes of memory leaks during Node-API development: 
1. **napi_value** is not managed by **napi_handle_scope**. As a result, the ArkTS object held by **napi_value** cannot be released. This problem often occurs when **uv_queue_work** is used. To solve this problem, add the **napi_open_handle_scope** and **napi_close_handle_scope** APIs.
You can analyze the snapshot to locate the cause of the leak. If the **distance** of the leaked ArkTS object is **1**, the object may be held by native (**napi_value** is a pointer to the native owner), and **napi_value** is not within the range of **napi_handle_scope**.  
2. A strong reference (with the **initial_refcount** parameter greater than 0) is created for the ArkTS object using **napi_create_reference**, and the reference is not deleted. As a result, the ArkTS object cannot be reclaimed. The **napi_create_reference** API creates a C++ object internally. Therefore, both the ArkTS object and native object are leaked. You can use Allocation to capture the native object leak stack and check whether stack frames related to **napi_create_reference** exist. 
For details, see [Memory Analysis: Allocation](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-insight-session-allocations). 

3. The leaked object is held by another active ArkTS object. In this case, check the owner of the leaked object using snapshot. 

## What should I do if memory leaks when napi_threadsafe_function is used

When **napi_threadsafe_function** (**tsfn** for short) is used, **napi_acquire_threadsafe_function** is often called to change the reference count of **tsfn** to ensure that **tsfn** is not released unexpectedly. When all the **tsfn** calls are complete, **napi_release_threadsafe_function** should be called in **napi_tsfn_release** mode in a timely manner to ensure that the reference count returns to the value before **napi_acquire_threadsafe_function** is called. **tsfn** can be correctly released only when the reference count is **0**.

When **env** is about to exit but the reference count of **tsfn** is not 0, **napi_release_threadsafe_function** should be called in **napi_tsfn_abort** mode to ensure that **tsfn** is not held or used by **env** after **env** is released. If **env** continues to hold **tsfn** after exiting, the application may crash.

The following code shows how to register **env_cleanup** to ensure that **tsfn** is no longer held by **env** after **env** exits.

```cpp
//napi_init.cpp
#include <hilog/log.h> // To output logs, link libhilog_ndk.z.so.
#include <thread> // Include the thread module to create and manage threads.
#include <unistd.h> // Include unistd.h to suspend the execution of the calling thread.

// Define the log domain and tag.
#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x2342
#define LOG_TAG "MY_TSFN_DEMO"

/*
  To construct a scenario in which the env lifecycle is shorter than the native lifecycle,
  the following uses worker, taskpool, and napi_create_ark_runtime
  to create an ArkTS running environment for a worker thread and manually stop the thread in advance.
*/


// Define a struct to simulate the scenario where tsfn is stored.
class MyTsfnContext {
public:
// MyTsfnContext is constructed only in an ArkTS thread because Node-API is used.
MyTsfnContext(napi_env env, napi_value workName) {
    // Register the env_cleanup_hook function.
    napi_add_env_cleanup_hook(env, Cleanup, this);
    // Create a thread-safe function.
    if (napi_create_threadsafe_function(env, nullptr, nullptr, workName, 1, 1, this,
            TsfnFinalize, this, TsfnCallJs, &tsfn_) != napi_ok) {
        OH_LOG_INFO(LOG_APP, "tsfn is created failed");
        return;
    };
};

~MyTsfnContext() { OH_LOG_INFO(LOG_APP, "MyTsfnContext is deconstructed"); };

napi_threadsafe_function GetTsfn() {
    std::unique_lock<std::mutex> lock(mutex_);
    return tsfn_;
}

bool Acquire() {
    if (GetTsfn() == nullptr) {
        return false;
    };
    return (napi_acquire_threadsafe_function(GetTsfn()) == napi_ok);
};

bool Release() {
    if (GetTsfn() == nullptr) {
        return false;
    };
    return (napi_release_threadsafe_function(GetTsfn(), napi_tsfn_release) == napi_ok);
};

bool Call(void *data) {
    if (GetTsfn() == nullptr) {
        return false;
    };
    return (napi_call_threadsafe_function(GetTsfn(), data, napi_tsfn_blocking) == napi_ok);
};

private:
// Ensure correct read and write of tsfn by multiple threads.
std::mutex mutex_;
napi_threadsafe_function tsfn_ = nullptr;

// Call napi_add_env_cleanup_hook.
static void Cleanup(void *data) {
    MyTsfnContext *that = reinterpret_cast<MyTsfnContext *>(data);
    napi_threadsafe_function tsfn = that->GetTsfn();
    std::unique_lock<std::mutex> lock(that->mutex_);
    that->tsfn_ = nullptr;
    lock.unlock();
    OH_LOG_WARN(LOG_APP, "cleanup is called");
    napi_release_threadsafe_function(tsfn, napi_tsfn_abort);
};

// Callback to be invoked when tsfn is released.
static void TsfnFinalize(napi_env env, void *data, void *hint) {
    MyTsfnContext *ctx = reinterpret_cast<MyTsfnContext *>(data);
    OH_LOG_INFO(LOG_APP, "tsfn is released");
    napi_remove_env_cleanup_hook(env, MyTsfnContext::Cleanup, ctx);
    // Cleanup releases the thread-safe function in advance. To avoid UAF, enable the caller to trigger the release.
    if (ctx->GetTsfn() != nullptr) {
        OH_LOG_INFO(LOG_APP, "ctx is released");
        delete ctx;
    }
};

// Callback sent by tsfn to the ArkTS thread for execution.
static void TsfnCallJs(napi_env env, napi_value func, void *context, void *data) {
    MyTsfnContext *ctx = reinterpret_cast<MyTsfnContext *>(context);
    char *str = reinterpret_cast<char *>(data);
    OH_LOG_INFO(LOG_APP, "tsfn is called, data is: \"%{public}s\"", str);
    // The service logic is omitted here.
};
};

// Register the myTsfnDemo method with the module Index.d.ts. The myTsfnDemo method is defined as follows:
// export const myTsfnDemo: () => void;
napi_value MyTsfnDemo(napi_env env, napi_callback_info info) {
    OH_LOG_ERROR(LOG_APP, "MyTsfnDemo is called");
    napi_value workName = nullptr;
    napi_create_string_utf8(env, "MyTsfnWork", NAPI_AUTO_LENGTH, &workName);
    MyTsfnContext *myContext = new MyTsfnContext(env, workName);
    if (myContext->GetTsfn() == nullptr) {
        OH_LOG_ERROR(LOG_APP, "failed to create tsfn");
        delete myContext;
        return nullptr;
    };
    char *data0 = new char[]{"Im call in ArkTS Thread"};
    if (!myContext->Call(data0)) {
        OH_LOG_INFO(LOG_APP, "call tsfn failed");
    };

    // Create a thread to simulate an asynchronous operation.
    std::thread(
        [](MyTsfnContext *myCtx) {
            if (!myCtx->Acquire()) {
                OH_LOG_ERROR(LOG_APP, "acquire tsfn failed");
                return;
            };
            char *data1 = new char[]{"Im call in std::thread"};
            // This operation is optional and used only to check whether the asynchronous tsfn is still valid.
            if (!myCtx->Call(data1)) {
                OH_LOG_ERROR(LOG_APP, "call tsfn failed");
            };
            // Suspend the thread for 5 seconds to simulate a time-consuming operation, which is not complete when env exits.
            sleep(5);
            // When the asynchronous operation is complete, tsfn has been released and set to nullptr.
            char *data2 = new char[]{"Im call after work"};
            if (!myCtx->Call(data2) && !myCtx->Release()) {
                OH_LOG_ERROR(LOG_APP, "call and release tsfn failed");
                delete myCtx;
            }
        },
        myContext)
        .detach();
    return nullptr;
};
```

The following is the main thread logic, which creates worker threads and instruct them to execute tasks.

```ts
// Main thread Index.ets
import worker, { MessageEvents } from '@ohos.worker';

const mWorker = new worker.ThreadWorker('../workers/Worker');
mWorker.onmessage = (e: MessageEvents) => {
    const action: string | undefined = e.data?.action;
    if (action === 'kill') {
        mWorker.terminate();
    }
}

// The registration of the triggering mode is omitted.
mWorker.postMessage({action: 'tsfn-demo'});

```

The following is the worker thread logic, which triggers native tasks.

```ts
// worker.ets
import worker, { ThreadWorkerGlobalScope, MessageEvents, ErrorEvent } from '@ohos.worker';
import napiModule from 'libentry.so'; // libentry.so is the module name of the Node-API library.

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = (e: MessageEvents) => {
    const action: string | undefined = e.data?.action;
    if (action === 'tsfn-demo') {
        // Trigger the tsfn demo in C++.
        napiModule.myTsfnDemo();
        // Instruct the main thread to terminate the worker.
        workerPort.postMessage({action: 'kill'});
    };
}
```
