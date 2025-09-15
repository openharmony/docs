# FAQs About Memory Leaks
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## Is there a mechanism to check whether napi_ref is leaked?

- Specific problem: napi_create_reference can be used to create a reference to the JS object and ensure that the JS object is not released. In normal cases, napi_delete_reference needs to be used to release the JS object after the JS object is used. However, if napi_delete_reference is not used, the JS object memory may leak, is there a mechanism to check/test whether there is a leaked napi_ref? 
- Detection method: 
You can use the Allocation tool provided by DevEco Studio (IDE) to perform the check. 
[Basic Memory Analysis: Allocation Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-insight-session-allocations) 
The internal implementation of the napi_create_reference interface creates a C++ object. Therefore, if you forget to use the napi_delete_reference interface, the new C++ object will be leaked. In this case, you can use the Allocation tool to detect the leakage, this tool prints the allocation stacks of unreleased objects. If napi_ref is leaked, you can view it on the allocation stack. 

## How do I locate and solve the memory leakage problem during napi development?

When the button is clicked, the memory usage increases. Even if GC is triggered, the memory cannot be reclaimed. How Do I Locate and Solve the Memory Leakage Problem During Node-API Development?

- Suggestion 
You need to understand the Node-API lifecycle mechanism. The related materials are as follows: 
[Performing Lifecycle Management Using Node-API](use-napi-life-cycle.md) 
Common causes of memory leakage when Node-API is used: 
1. napi_value is not managed by napi_handle_scope. As a result, the ArkTS object held by napi_value cannot be released. This problem usually occurs when uv_queue_work is directly used. The solution is to add the napi_open_handle_scope and napi_close_handle_scope interfaces.
You can use snapshots to analyze and locate the cause of the leakage. The distance of the leaked ArkTS object is 1, indicating that the owner is unknown. In this case, the ArkTS object is held by native (napi_value is a pointer that points to the native owner). The value of napi_value is not within the range of napi_handle_scope. For details, see [Error-prone API Usage Specifications](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-coding-standard-api#section1219614634615).  
2. A strong reference (the `initial_refcount` parameter is greater than 0) is created for the ArkTS object using `napi_create_reference` and is not deleted. As a result, the ArkTS object cannot be reclaimed. A C++ object is created in the `napi_create_reference` interface. Therefore, the leak is usually a double leak of the ArkTS object and Native object. You can use the Allocation tool to capture the native object leakage stack and check whether there are stack frames related to `napi_create_reference`. 
[Basic Memory Analysis: Allocation Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-insight-session-allocations) 

3. When the leaked object is held by another live ArkTS object, use the snapshot to view the owner of the leaked object. 

## What should I do if memory leaks when napi_threadsafe_function is used?

When **napi_threadsafe_function** (**tsfn** for short) is used, **napi_acquire_threadsafe_function** is often called to change the reference count of **tsfn** to ensure that **tsfn** is not released unexpectedly. When all the **tsfn** calls are complete, **napi_release_threadsafe_function** should be called in **napi_tsfn_release** mode in a timely manner to ensure that the reference count returns to the value before **napi_acquire_threadsafe_function** is called. **tsfn** can be correctly released only when the reference count is **0**.

When the env is about to exit but the reference count of tsfn does not return to zero, use the `napi_tsfn_abort` mode to call the `napi_release_threadsafe_function` method to ensure that the env does not hold or use tsfn after being released. Continuing to hold tsfn after env exits will cause undefined behavior, which may cause a crash.

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
// Because the Node-API method is used, MyTsfnContext should be constructed only in the ArkTS thread.
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

// Callback sent by tsfn to the JS thread for execution.
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

The following is the main thread logic, which creates worker threads and instruct workers to execute tasks.

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
Module name of the import napiModule from 'libentry.so'; // libentry.so: Node-API library.

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
