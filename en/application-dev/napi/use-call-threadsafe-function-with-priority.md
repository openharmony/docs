# Passing a Task with the Specified Priority to an ArkTS Thread from an Asynchronous Thread Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:28:58.015Z pushedAt=2026-08-12T10:47:56.678Z -->

You can use **napi_call_threadsafe_function_with_priority** to pass a task with a specified priority and enqueuing mode to an ArkTS thread from an asynchronous thread in a thread-safe manner. Then, the task will be processed based on its priority and enqueuing mode.

## Function Description

```cpp
napi_status napi_call_threadsafe_function_with_priority(napi_threadsafe_function func, void *data,
                                                        napi_task_priority priority, bool isTail);
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

- Implementation

  <!-- @[napi_call_threadsafe_function_with_priority_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/napi_init.cpp) -->  

  ``` C++
  #include "napi/native_api.h"
  // ...
  #include <hilog/log.h>
  // ...
  static constexpr int INT_ARG_2 = 2; // Input parameter index.
  static constexpr int INT_ARG_12 = 12; // Input parameter index.
  static constexpr int INT_ARG_15 = 15; // Input parameter index.
  // ...
  struct CallbackData {
      napi_threadsafe_function tsfn;
      napi_async_work work;
  };
  static void CallJs(napi_env env, napi_value jsCb, void *context, void *data)
  {
      if (env == nullptr) {
          return;
      }
  
      napi_handle_scope scope = nullptr;
      napi_status status = napi_open_handle_scope(env, &scope);
      if (status != napi_ok) {
          return;
      }
  
      napi_value resultNumber = nullptr;
      napi_value undefined = nullptr;
      napi_get_undefined(env, &undefined);
      napi_value number1 = nullptr;
      napi_create_int32(env, INT_ARG_12, &number1);
      napi_value number2 = nullptr;
      napi_create_int32(env, INT_ARG_15, &number2);
      napi_value argv[2] = {number1, number2};
      napi_call_function(env, undefined, jsCb, INT_ARG_2, argv, &resultNumber);
      int32_t res = 0;
      // Obtain the int32 value corresponding to resultNumber.
      napi_get_value_int32(env, resultNumber, &res);
  
      napi_close_handle_scope(env, scope);
  }
  
  // Call this API in an asynchronous thread to pass a task with the specified priority and enqueuing mode to an ArkTS thread.
  static void ExecuteWork(napi_env env, void *data)
  {
      CallbackData *callbackData = reinterpret_cast<CallbackData *>(data);
      // Post a task with the specified priority napi_priority_idle and enqueue it at the tail of the queue.
      napi_call_threadsafe_function_with_priority(callbackData->tsfn, nullptr, napi_priority_idle, true);
      // Post a task with the specified priority napi_priority_low and enqueue it at the tail of the queue.
      napi_call_threadsafe_function_with_priority(callbackData->tsfn, nullptr, napi_priority_low, true);
      // Post a task with the specified priority napi_priority_high and enqueue it at the tail of the queue.
      napi_call_threadsafe_function_with_priority(callbackData->tsfn, nullptr, napi_priority_high, true);
      // Post a task with the specified priority napi_priority_immediate and enqueue it at the tail of the queue.
      napi_call_threadsafe_function_with_priority(callbackData->tsfn, nullptr, napi_priority_immediate, true);
      // Post a task with the specified priority napi_priority_high and enqueue it at the head of the queue.
      napi_call_threadsafe_function_with_priority(callbackData->tsfn, nullptr, napi_priority_high, false);
  }
  
  static void WorkComplete(napi_env env, napi_status status, void *data)
  {
      CallbackData *callbackData = reinterpret_cast<CallbackData *>(data);
      if (callbackData->tsfn != nullptr) {
          napi_release_threadsafe_function(callbackData->tsfn, napi_tsfn_release);
          callbackData->tsfn = nullptr;
      }
      if (callbackData->work != nullptr) {
          napi_delete_async_work(env, callbackData->work);
          callbackData->work = nullptr;
      }
      delete callbackData;
  }
  
  static napi_value CallThreadSafeWithPriority(napi_env env, napi_callback_info info)
  {
      size_t argc = 1;
      napi_value jsCb = nullptr;
      CallbackData *callbackData = new CallbackData();
      napi_get_cb_info(env, info, &argc, &jsCb, nullptr, nullptr);
      napi_value resourceName = nullptr;
      napi_create_string_utf8(env, "Thread-safe Function Demo", NAPI_AUTO_LENGTH, &resourceName);
      if (napi_create_threadsafe_function(env, jsCb, nullptr, resourceName, 0, 1, nullptr, nullptr, nullptr, CallJs,
                                          &callbackData->tsfn) != napi_ok) {
          delete callbackData;
          return nullptr;
      }
      // Create an async task object.
      if (napi_create_async_work(env, nullptr, resourceName,
                                 ExecuteWork, WorkComplete, callbackData, &callbackData->work) != napi_ok) {
          if (callbackData->tsfn != nullptr) {
              napi_release_threadsafe_function(callbackData->tsfn, napi_tsfn_release);
          }
          delete callbackData;
          return nullptr;
      }
      if (napi_queue_async_work(env, callbackData->work) != napi_ok) {
          if (callbackData->tsfn != nullptr) {
              napi_release_threadsafe_function(callbackData->tsfn, napi_tsfn_release);
          }
          napi_delete_async_work(env, callbackData->work);
          delete callbackData;
          return nullptr;
      }
      return nullptr;
  }
  ```

- Register the module.

  ``` C++
  // Register the module.
  EXTERN_C_START
  static napi_value Init(napi_env env, napi_value exports)
  {
      napi_property_descriptor desc[] = {
          { "callThreadSafeWithPriority", nullptr, CallThreadSafeWithPriority, nullptr, nullptr, nullptr, napi_default, nullptr }
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

  <!-- @[napi_call_threadsafe_function_with_priority_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/types/libentry/Index.d.ts) -->

  ``` TypeScript
  // index.d.ts
  export const callThreadSafeWithPriority: (cb: (a: number, b: number) => number) => void;
  ```

- Configure compile settings.

  Configure the **CMakeLists.txt** file as follows:

  ```text
  # the minimum version of CMake.
  cmake_minimum_required(VERSION 3.5.0)
  project(MyApplication3)

  set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

  if(DEFINED PACKAGE_FIND_FILE)
      include(${PACKAGE_FIND_FILE})
  endif()
  add_definitions( "-DLOG_TAG=\"LOG_TAG\"" )
  include_directories(${NATIVERENDER_ROOT_PATH}
                      ${NATIVERENDER_ROOT_PATH}/include)

  add_library(entry SHARED napi_init.cpp)
  target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
  ```

- Import the header file of ArkTS.

  ``` TypeScript
  import testNapi from 'libentry.so';
  ```

- ArkTS sample code

  <!-- @[napi_call_threadsafe_function_with_priority_ets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  // index.ets
  let callback = (a: number, b: number): number => {
    console.info('result is ' + (a + b))
    return a + b;
  }
  testNapi.callThreadSafeWithPriority(callback);
  ```