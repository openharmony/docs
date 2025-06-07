# Node-API FAQs

## What should I do when "undefined/not callable" or specific error message is reported for xxx after "import xxx from libxxx.so" is executed?

1. Check whether the module name in the .cpp file used in module registration is the same as that in the .so file name.
   If the module name is **entry**, the .so file name must be **libentry.so**, and the **nm_modname** field in **napi_module** must be **entry**. The module names must be of the same case.

2. Check whether the .so file is successfully loaded.
   Check the logs related to module loading during the application startup. Search for the keyword "dlopen" and check for error information. Generally, a loading failure is caused when the file to be loaded does not exist or is in a blocklist or the application does not have the required permission. In multi-thread scenarios (such as worker threads and taskpool), check whether **nm_modname** is the same as the module name. The module names must be of the same case.

3. Check whether the dependency .so files are successfully loaded.
   Check that all the dependency .so files are packaged into the application and the application has the permission to open them.  

4. Check whether the module import mode matches the .so file path.
   If the module is imported by using **import xxx from '\@ohos.yyy.zzz'**, you may find **libzzz.z.so** or **libzzz_napi.z.so** in **/system/lib/module/yyy** (for a 32-bit system) or **/system/lib64/module/yyy** (for a 64-bit system). If the .so file does not exist or the file names do not match, an error containing the keyword "dlopen" will be reported.

    

| **Error Log**| **Solution**|
| -------- | -------- |
| module $SO is not allowed to load in restricted runtime. | The module, identified by **$SO**, is not allowed for the worker thread running in a restricted environment and cannot be loaded. You are advised to delete the module.|
| module $SO is in blocklist, loading prohibited. | The module, identified by **$SO**, is in the blocklist due to the control of the widget or Extension, and cannot be loaded. You are advised to delete the module.|
| load module failed. $ERRMSG. | The dynamic library fails to be loaded. **$ERRMSG** indicates the cause of the loading failure. Possible causes include the following:<br>- The .so file to be loaded does not exist.<br>- The dependency .so file does not exist. <br>- Undefined symbol is found. <br>Locate the cause based on the error message.|
| try to load abc file from $FILEPATH failed. | You can load either a dynamic library or an .abc file. If this log information is displayed when you attempt to load a dynamic library, ignore this message. If it is displayed when you attempt to load an .abc file, the .abc file does not exist. **$FILEPATH** indicates the module path.|

5. If specific error message is reported, identify the fault based on the error message.

| **Error message** | **Fault Analysis & Solution**|
| -------- | -------- |
| First attempt: $ERRMSG. | Loading the .so file with the module name of "xxx" fails. *$ERRMSG* indicates the error information.|
| Second attempt: $ERRMSG. | Loading the .so file with the module name of "xxx_napi" fails. *$ERRMSG* indicates the error information.|
| try to load abc file from xxx failed. | Loading the .abc file fails. *xxx* indicates the name of the .abc file.|
| module xxx is not allowed to load in restricted runtime. | This module cannot be used in restricted runtime. *xxx* indicates the module name. You are advised to delete the module.|
| module xxx is in blocklist, loading prohibited. | The module cannot be used in the current extension. *xxx* indicates the module name. You are advised to delete the module.|

## What should I do when an unexpected value is returned by an API and "occur exception need return" is reported?

Before the call is complete, some Node-API interfaces are checked for JavaScript (JS) exceptions in the VM. If an exception is detected, "occur exception need return" will be reported, with the line number of the code and the Node-API interface name.

You can solve this problem as follows:

- If the exception does not matter, clear the exception.
  Call **napi_get_and_clear_last_exception** before "occur exception need return" is printed to clear the exception.

- Throw the exception to the ArkTS layer for capture.
  Throw the exception directly to the ArkTS layer without going through the native logic.

## What are the differences between the lifecycle of napi_value and napi_ref?

- **native_value** is managed by **HandleScope**. Generally, you do not need to add **HandleScope** for **native_value** (except for **complete callback** of **uv_queue_work**).

- **napi_ref** must be deleted manually.

## How do I locate the fault if the return value of a Node-API interface is not "napi_ok"?

When a Node-API interface is successfully executed, **napi_ok** is returned. If the return value is not **napi_ok**, locate the fault as follows:

- Check the result of the input parameter null check, which is performed first before a Node-API interface is executed. The code is as follows:

  ```cpp
  CHECK_ENV: null check for env.
  CHECK_ARG: null check for other input parameters.
  ```

- Check the result of the input parameter type check, which is performed for certain Node-API interfaces. For example, **napi_get_value_double** is used to obtain a C double value from a JS number, and the type of the JS value passed in must be number. The parameter type check is as follows:

  ```cpp
  RETURN_STATUS_IF_FALSE(env, nativeValue->TypeOf() == NATIVE_NUMBER, napi_number_expected);
  ```

- Check the return value, which contains the verification result of certain interfaces. For example, **napi_call_function** is used to execute a JS function. If an exception occurs in the JS function, Node-API returns **napi_pending_exception**.

  ```cpp
  auto resultValue = engine->CallFunction(nativeRecv, nativeFunc, nativeArgv, argc);
  RETURN_STATUS_IF_FALSE(env, resultValue != nullptr, napi_pending_exception)
  ```

- Determine the status value returned, and analyze the situation in which the status value is returned.

## What should I do if memory leaks when napi_threadsafe_function is used?

When **napi_threadsafe_function** (**tsfn** for short) is used, **napi_acquire_threadsafe_function** is often called to change the reference count of **tsfn** to ensure that **tsfn** is not released unexpectedly. When all the **tsfn** calls are complete, **napi_release_threadsafe_function** should be called in **napi_tsfn_release** mode in a timely manner to ensure that the reference count returns to the value before **napi_acquire_threadsafe_function** is called. **tsfn** can be correctly released only when the reference count is **0**.

When **env** is about to exit but the reference count of **tsfn** is not **0**, **napi_release_threadsafe_function** should be called in **napi_tsfn_abort** mode to ensure that **tsfn** is not held or used by **env** after **env** is released. If **env** continues to hold and use **tsfn** after exiting, the application may crash.

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
// MyTsfnContext is constructed only in a JS thread because Node-API is used.
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

## napi_get_uv_event_loop Error Codes

Additional parameter verification is added to prevent use of invalid **napi_env** in **napi_get_uv_event_loop**. The return value indicates the verification result. The return values of this API are as follows:

1. If **env** and/or **loop** are **nullptr**, **napi_invalid_arg** is returned.
2. If **env** is a valid **napi_env** and **loop** is a valid pointer, **napi_ok** is returned.
3. If **env** is not a valid **napi_env** (for example, a released **env**), **napi_generic_failure** is returned.

Example:

```c++
napi_value NapiInvalidArg(napi_env env, napi_callback_info)
{
    napi_status status = napi_ok;
    status = napi_get_uv_event_loop(env, nullptr); // loop is nullptr, napi_invalid_arg.
    if (status == napi_ok) {
        // do something
    }

    uv_loop_s* loop = nullptr;
    status = napi_get_uv_event_loop(nullptr, &loop); // env is nullptr, napi_invalid_arg.
    if (status == napi_ok) {
        // do something
    }

    status = napi_get_uv_event_loop(nullptr, nullptr); // Both env and loop are nullptr, napi_invalid_arg.
    if (status == napi_ok) {
        // do something
    }

    return nullptr;
}

napi_value NapiGenericFailure(napi_env env, napi_callback_info)
{
    std::thread([]() {
        napi_env env = nullptr;
        napi_create_ark_runtime (&env); // Generally, the return value needs to be checked.
        // napi_destroy_ark_runtime sets the pointer to null. Copy the pointer to simulate the problem.
        napi_env copiedEnv = env;
        napi_destroy_ark_runtime(&env);
        uv_loop_s* loop = nullptr;
        napi_status status = napi_get_uv_event_loop(copiedEnv, &loop); // env is invalid. napi_generic_failure will be returned.
        if (status == napi_ok) {
            // do something
        }
    }).detach();;
}
```
