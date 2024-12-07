# Passing a Task with the Specified Priority to an ArkTS Thread from an Asynchronous Thread Using Node-API
You can use **napi_call_threadsafe_function_with_priority** to pass a task to an ArkTS thread from an asynchronous thread in a thread-safe manner. Then, the task will be processed based on its priority and enqueuing mode.

## Function Description

```cpp
napi_status napi_call_threadsafe_function_with_priority(napi_threadsafe_function func,
                                                        void *data,
                                                        napi_task_priority priority,
                                                        bool isTail);
```

| Name           | Description         |
| :------------- | :----------------------------- |
| func           | Thread-safe function to call.                  |
| data           | Data to be passed from the asynchronous thread to the main thread. |
| priority       | Priority of the task. For details, see [napi_task_priority](napi-data-types-interfaces.md#thread-safe-task-priority).|
| isTail         | Whether to add the task to the end (tail) of the task queue. The value **true** means to add the task to the end of the task queue; the value **false** means to add the task to the head of the queue.|

## When to Use
Pass a task to the ArkTS main thread from an asynchronous thread in a thread-safe manner. Then, the task will be processed based on its priority and enqueuing mode.

## Calling an ArkTS API Asynchronously

### Example

- Register the module.

   ```c++
    // hello.cpp
    #include "napi/native_api.h"
    #include <string.h>
    #include <stdlib.h>

    struct CallbackData {
        napi_threadsafe_function tsfn;
        napi_async_work work;
    };
    // Callback implementation in the ArkTS thread.
    static void CallJs(napi_env env, napi_value jsCb, void *context, void *data) {
        if (env == nullptr) {
            return;
        }
        napi_value resultNumber = nullptr;
        napi_value undefined = nullptr;
        napi_get_undefined(env, &undefined);
        napi_value number1 = nullptr;
        napi_create_int32(env, 12, &number1);
        napi_value number2 = nullptr;
        napi_create_int32(env, 15, &number2);
        napi_value argv[2] = {number1, number2};
        napi_call_function(env, undefined, jsCb, 2, argv, &resultNumber);
        int32_t res = 0;
        napi_get_value_int32(env, resultNumber, &res);
    }

    // Call this API in an asynchronous thread to pass a task with the specified priority and enqueuing mode to an ArkTS thread.
    static void ExecuteWork(napi_env env, void *data) {
        CallbackData *callbackData = reinterpret_cast<CallbackData *>(data);
        // The task priority is napi_priority_idle, and the task is added to the end of the task queue.
        napi_call_threadsafe_function_with_priority(callbackData->tsfn, nullptr, napi_priority_idle, true);
        napi_call_threadsafe_function_with_priority(callbackData->tsfn, nullptr, napi_priority_low, true);
        napi_call_threadsafe_function_with_priority(callbackData->tsfn, nullptr, napi_priority_high, true);
        napi_call_threadsafe_function_with_priority(callbackData->tsfn, nullptr, napi_priority_immediate, true);
        // The task priority is napi_priority_high, and the task is added to the head of the task queue.
        napi_call_threadsafe_function_with_priority(callbackData->tsfn, nullptr, napi_priority_high, false);
    }

    static void WorkComplete(napi_env env, napi_status status, void *data) {
        CallbackData *callbackData = reinterpret_cast<CallbackData *>(data);
        napi_release_threadsafe_function(callbackData->tsfn, napi_tsfn_release);
        napi_delete_async_work(env, callbackData->work);
        callbackData->work = nullptr;
        callbackData->tsfn = nullptr;
    }

    static napi_value CallThreadSafeWithPriority(napi_env env, napi_callback_info info) {
        size_t argc = 1;
        napi_value jsCb = nullptr;
        CallbackData *callbackData = nullptr;
        napi_get_cb_info(env, info, &argc, &jsCb, nullptr, reinterpret_cast<void **>(&callbackData));
        napi_value resourceName = nullptr;
        napi_create_string_utf8(env, "Thread-safe Function Demo", NAPI_AUTO_LENGTH, &resourceName);
        napi_create_threadsafe_function(env, jsCb, nullptr, resourceName, 0, 1, callbackData, nullptr, callbackData, CallJs,
                                        &callbackData->tsfn);
        napi_create_async_work(env, nullptr, resourceName, ExecuteWork, WorkComplete, callbackData, &callbackData->work);
        napi_queue_async_work(env, callbackData->work);
        return nullptr;
    }

    // Register the module.
    EXTERN_C_START
    static napi_value Init(napi_env env, napi_value exports)
    {
        CallbackData *callbackData = new CallbackData();
        napi_property_descriptor desc[] = {
            { "callThreadSafeWithPriority", nullptr, CallThreadSafeWithPriority, nullptr, nullptr, nullptr, napi_default, callbackData }
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    EXTERN_C_END

    static napi_module nativeModule = {
        .nm_version = 1,
        .nm_flags = 0,
        .nm_filename = nullptr,
        .nm_register_func = Init,
        .nm_modname = "entry",
        .nm_priv = nullptr,
        .reserved = { 0 },
    };

    extern "C" __attribute__((constructor)) void RegisterEntryModule()
    {
        napi_module_register(&nativeModule);
    }
   ```

- Declare the API.

    ```ts
    // index.d.ts
    export const callThreadSafeWithPriority: (cb: (a: number, b: number) => number) => void;
    ```

- Configure compile settings.

  Configure the **CMakeLists.txt** file as follows:

    ```
    // CMakeLists.txt
    # the minimum version of CMake.
    cmake_minimum_required(VERSION 3.4.1)
    project(myapplication)

    set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

    if(DEFINED PACKAGE_FIND_FILE)
        include(${PACKAGE_FIND_FILE})
    endif()

    include_directories(${NATIVERENDER_ROOT_PATH}
                        ${NATIVERENDER_ROOT_PATH}/include)
    add_library(entry SHARED hello.cpp)
    target_link_libraries(entry PUBLIC libace_napi.z.so)
    ```

- ArkTS sample code

    ```ts
    // index.ets
    import testNapi from 'libentry.so'

    let callback = (a: number, b: number) : number => {
        console.info('result is ' + (a + b))
        return a + b;
    }
    testNapi.callThreadSafeWithPriority(callback);
    ```
