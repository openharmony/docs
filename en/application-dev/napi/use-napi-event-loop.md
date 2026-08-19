# Running or Stopping an Event Loop in an Asynchronous Thread Using Node-API Extension APIs

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=2cc827181a31e0a77238ca42eb3b41991d5fd686 translatedAt=2026-08-12T06:41:53.141Z pushedAt=2026-08-12T11:16:00.360Z -->

## **Scenario**

When calling asynchronous ArkTS APIs in the ArkTS running environment, you can use **napi_run_event_loop** to run an event loop and use **napi_stop_event_loop** to stop an event loop.

## Example

If asynchronous ArkTS APIs are called, you can use **napi_run_event_loop** to run the events in the asynchronous thread cyclically. The underlying asynchronous tasks in the event queue will be processed based on the event loop mode. Currently, Node-API provides two modes for running event loops: **napi_event_mode_nowait** and **napi_event_mode_default**.

If **napi_event_mode_nowait** is used, the current asynchronous thread will not be blocked while the system attempts to process a task in the underlying event queue. After the task is complete, the event loop stops. If there is no task in the event queue, the event loop stops immediately.

If **napi_event_mode_default** is used, the system blocks the current asynchronous thread and keeps trying to obtain tasks from the event queue and execute these tasks. If you do not want the current thread to be blocked, use **napi_stop_event_loop** to stop the event loop.

### Sample Code

- Functionality implementation

  <!-- @[napi_event_loop_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/napi_init.cpp) -->  

  ``` C++
  #include "napi/native_api.h"
  #include <pthread.h>
  #include <hilog/log.h>
  #include <napi/common.h>
  static constexpr int INT_ARG_2 = 2; // Input parameter index.
  // ...
  static napi_value ResolvedCallback(napi_env env, napi_callback_info info)
  {
      napi_stop_event_loop(env);
      return nullptr;
  }
  
  static napi_value RejectedCallback(napi_env env, napi_callback_info info)
  {
      napi_stop_event_loop(env);
      return nullptr;
  }
  
  static bool CallSetTimeoutWithCallbacks(napi_env env, napi_value objectUtils)
  {
      napi_value setTimeout = nullptr;
      napi_value promise = nullptr;
  
      if (napi_get_named_property(env, objectUtils, "SetTimeout", &setTimeout) != napi_ok) {
          return false;
      }
      if (napi_call_function(env, objectUtils, setTimeout, 0, nullptr, &promise) != napi_ok) {
          return false;
      }
  
      napi_value theFunc = nullptr;
      if (napi_get_named_property(env, promise, "then", &theFunc) != napi_ok) {
          return false;
      }
  
      napi_value resolvedCallback = nullptr;
      napi_value rejectedCallback = nullptr;
      if (napi_create_function(env, "resolvedCallback", NAPI_AUTO_LENGTH,
                               ResolvedCallback, nullptr, &resolvedCallback) != napi_ok) {
          return false;
      }
      if (napi_create_function(env, "rejectedCallback", NAPI_AUTO_LENGTH,
                               RejectedCallback, nullptr, &rejectedCallback) != napi_ok) {
          return false;
      }
      napi_value argv[2] = {resolvedCallback, rejectedCallback};
      if (napi_call_function(env, promise, theFunc, INT_ARG_2, argv, nullptr) != napi_ok) {
          return false;
      }
      return true;
  }
  
  static void *RunEventLoopFunc(void *arg)
  {
      // 1. Create an ArkTS instance.
      napi_env env = nullptr;
      napi_status ret = napi_create_ark_runtime(&env);
      if (ret != napi_ok) {
          return nullptr;
      }
  
      napi_handle_scope scope = nullptr;
      napi_open_handle_scope(env, &scope);
  
      // 2. Load the custom modules.
      napi_value objectUtils = nullptr;
      // 'com.example.myapplication' is the bundle name of the current application.
      ret = napi_load_module_with_info(env, "entry/src/main/ets/pages/ObjectUtils", "com.example.myapplication/entry",
                                       &objectUtils);
      if (ret != napi_ok) {
          OH_LOG_INFO(LOG_APP, "Failed to load module");
          napi_close_handle_scope(env, scope);
          napi_destroy_ark_runtime(&env);
          return nullptr;
      }
  
      // 3. Call the asynchronous SetTimeout API.
      if (!CallSetTimeoutWithCallbacks(env, objectUtils)) {
          napi_close_handle_scope(env, scope);
          napi_destroy_ark_runtime(&env);
          return nullptr;
      }
  
      auto flag = reinterpret_cast<bool *>(arg);
      if (*flag == true) {
          if (napi_run_event_loop(env, napi_event_mode_default) != napi_ok) {
              napi_close_handle_scope(env, scope);
              napi_destroy_ark_runtime(&env);
              return nullptr;
          }
      } else {
          if (napi_run_event_loop(env, napi_event_mode_nowait) != napi_ok) {
              napi_close_handle_scope(env, scope);
              napi_destroy_ark_runtime(&env);
              return nullptr;
          }
      }
  
      if (scope != nullptr) {
          napi_close_handle_scope(env, scope);
          scope = nullptr;
      }
      if (env != nullptr) {
          napi_status destroy_ret = napi_destroy_ark_runtime(&env);
          if (destroy_ret != napi_ok) {
              OH_LOG_INFO(LOG_APP, "Failed to destroy ark runtime");
          }
          env = nullptr;
      }
      return nullptr;
  }
  
  static napi_value RunEventLoop(napi_env env, napi_callback_info info)
  {
      pthread_t tid;
      size_t argc = 1;
      napi_value argv[1] = { nullptr };
      napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
  
      bool flag = false;
      napi_get_value_bool(env, argv[0], &flag);
      // Create an asynchronous thread.
      pthread_create(&tid, nullptr, RunEventLoopFunc, &flag);
      pthread_join(tid, nullptr);
  
      return nullptr;
  }
  ```

- Register the modules.

  ``` C++
  EXTERN_C_START
  static napi_value Init(napi_env env, napi_value exports)
  {
      napi_property_descriptor desc[] = {
          { "runEventLoop", nullptr, RunEventLoop, nullptr, nullptr, nullptr, napi_default, nullptr }
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

- Declare the APIs.

  <!-- @[napi_event_loop_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/types/libentry/Index.d.ts) -->

  ``` TypeScript
  // index.d.ts
  export const runEventLoop: (isDefault: boolean) => object;
  ```

- Configure the compile settings.

1. Configure the CMakeLists.txt file as follows:

   ``` text
   // CMakeLists.txt
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

2. Add the following to the **build-profile.json5** file of the module.

   <!-- @[napi_event_loop_build](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/build-profile.json5) -->

   ``` JSON5
     "buildOption": {
       "arkOptions" : {
         "runtimeOnly" : {
           "sources": [
             "./src/main/ets/pages/ObjectUtils.ets"
           ]
         }
       },
   // ...
     },
   ```

- ArkTS sample code

  ``` TypeScript
  // Import the header file.
  import testNapi from 'libentry.so'
  ```

  <!-- @[napi_event_loop_ets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  // index.ets
  testNapi.runEventLoop(true);
  ```

  <!-- @[napi_event_loop_utils](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/ets/pages/ObjectUtils.ets) -->

  ``` TypeScript
  export function SetTimeout(): Promise<void> {
    return new Promise((resolve) => {
      setTimeout(() => {
        console.info('set timer delay 1s');
        // attempt to stop the event loop at napi terminal
        resolve();
      }, 1000)
    })
  }
  ```