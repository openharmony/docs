# 使用Node-API接口从异步线程向ArkTS线程投递指定优先级和入队方式的的任务
Node-API中的napi_call_threadsafe_function_with_priority接口的功能是从异步线程向ArkTS线程投递任务，底层队列会根据任务的优先级和入队方式来处理任务。

## 函数说明

```cpp
napi_status napi_call_threadsafe_function_with_priority(napi_threadsafe_function func, void *data,
                                                        napi_task_priority priority, bool isTail);
```

| 参数            | 说明          |
| :------------- | :----------------------------- |
| func           | 线程安全方法                   |
| data           | 异步线程期望传递给主线程的数据  |
| priority       | 指定任务的优先级[napi_task_priority](napi-data-types-interfaces.md#线程安全任务优先级) |
| isTail         | 指定任务的入队方式，true代表任务从队列的尾部入队，false代表任务从队列的头部入队。 |

## 场景介绍
异步线程向ArkTS主线程投递的任务需要根据任务指定的优先级和入队方式进行处理。

## 调用异步的ArkTS接口示例

### 示例代码

- 模块注册

   ```c++
    // napi_init.cpp
    #include "napi/native_api.h"
    #include <string.h>
    #include <stdlib.h>

    static constexpr int INT_NUM_2 = 2;     // int类型数值2
    static constexpr int INT_NUM_12 = 12;   // int类型数值12
    static constexpr int INT_NUM_15 = 15;   // int类型数值15

    struct CallbackData {
        napi_threadsafe_function tsfn;
        napi_async_work work;
    };
    // ArkTS线程的回调实现
    static void CallJs(napi_env env, napi_value jsCb, void *context, void *data) {
        if (env == nullptr) {
            return;
        }
        napi_value resultNumber = nullptr;
        napi_value undefined = nullptr;
        napi_get_undefined(env, &undefined);
        napi_value number1 = nullptr;
        napi_create_int32(env, INT_NUM_12, &number1);
        napi_value number2 = nullptr;
        napi_create_int32(env, INT_NUM_15, &number2);
        napi_value argv[2] = {number1, number2};
        napi_call_function(env, undefined, jsCb, INT_NUM_2, argv, &resultNumber);
        int32_t res = 0;
        napi_get_value_int32(env, resultNumber, &res);
    }

    // 异步线程中调用该接口向ArkTS线程投递指定优先级和入队方式的任务
    static void ExecuteWork(napi_env env, void *data) {
        CallbackData *callbackData = reinterpret_cast<CallbackData *>(data);
        // 执行任务为napi_priority_idle优先级，入队方式为队列尾部入队
        napi_call_threadsafe_function_with_priority(callbackData->tsfn, nullptr, napi_priority_idle, true);
        napi_call_threadsafe_function_with_priority(callbackData->tsfn, nullptr, napi_priority_low, true);
        napi_call_threadsafe_function_with_priority(callbackData->tsfn, nullptr, napi_priority_high, true);
        napi_call_threadsafe_function_with_priority(callbackData->tsfn, nullptr, napi_priority_immediate, true);
        // 执行任务为napi_priority_high优先级，入队方式为队列头部入队
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

    // 注册模块接口
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

- 接口声明

    ```ts
    // index.d.ts
    export const callThreadSafeWithPriority: (cb: (a: number, b: number) => number) => void;
    ```

- 编译配置

  CMakeLists.txt文件需要按照如下配置

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

- ArkTS代码示例

    ```ts
    // index.ets
    import testNapi from 'libentry.so';
    
    let callback = (a: number, b: number) : number => {
        console.info('result is ' + (a + b));
        return a + b;
    }
    testNapi.callThreadSafeWithPriority(callback);
    ```