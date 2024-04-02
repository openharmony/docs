# Calling Back ArkTS APIs in a Non-ArkTS Thread

## When to Use

ArkTS is a single-thread language. Normally, all operations on an ArkTS object through Node-API interfaces must be performed by the same ArkTS thread. The following example describes how to use **napi_get_uv_event_loop** and **uv_queue_work** to call back ArkTS functions using Node-API in a non-ArkTS thread.

## Example

1. Declare the APIs, configure compile settings, and register the module.

   **Declare the APIs.**

   ```ts
   // index.d.ts
   export const queueWork: (cb: (arg: number) => void) => void;
   ```

   **Configure compile settings.**

   ```
   // CMakeLists.txt
   # Minimum version of CMake.
   cmake_minimum_required(VERSION 3.4.1)
   project(MyApplication)
   
   set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
   
   include_directories(${NATIVERENDER_ROOT_PATH}
                       ${NATIVERENDER_ROOT_PATH}/include)
   add_library(queue_work SHARED queue_work.cpp)
   target_link_libraries(queue_work PUBLIC libace_napi.z.so libhilog_ndk.z.so libuv.so)
   ```

   **Register the module.**

   ```cpp
   // queue_work.cpp
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "queueWork", nullptr, QueueWork, nullptr, nullptr, nullptr, napi_default, nullptr }
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
       .nm_modname = "queue_work",
       .nm_priv = nullptr,
       .reserved = { 0 },
   };
   
   extern "C" __attribute__((constructor)) void RegisterQueueWorkModule()
   {
       napi_module_register(&nativeModule);
   }
   ```

2. Obtain the loop corresponding to **env** and throw a task to an ArkTS thread.

   ```cpp
   // queue_work.cpp
   #include <thread>
   
   #include "napi/native_api.h"
   #include "uv.h"
   
   struct CallbackContext {
       napi_env env = nullptr;
       napi_ref callbackRef = nullptr;
       int32_t retData = 0;
   };
   
   void StartThread(CallbackContext* context)
   {
       // Obtain the loop corresponding to the ArkTS thread from env, which must be saved when the JS callback is registered.
       uv_loop_s* loop = nullptr;
       napi_get_uv_event_loop(context->env, &loop);
   
       // Create uv_work_t to pass private data. Note that memory must be released after the callback is complete. The logic for generating the returned data is omitted here. In this example, int 1 is returned. 
       uv_work_t* work = new uv_work_t;
       context->retData = 1;
       work->data = context;
   
       // Throw a work object to the ArkTS thread.
       uv_queue_work(
           loop,
           work,
           // The work_cb callback is executed in another worker thread to process asynchronous or time-consuming tasks. After the callback is executed, the subsequent callback is executed. In this example, you do not need to perform the task.
           [](uv_work_t* work) {},
           // The after_work_cb callback is executed in the ArkTS thread corresponding to env.
           [](uv_work_t* work, int status) {
               CallbackContext* context = reinterpret_cast<CallbackContext*>(work->data);
               napi_handle_scope scope = nullptr;
               // Open the handle scope to manage the lifecycle of napi_value. Otherwise, memory leakage may occur.
               napi_open_handle_scope(context->env, &scope);
               if (scope == nullptr) {
                   return;
               }
   
               // Call back the ArkTS function.
               napi_value callback = nullptr;
               napi_get_reference_value(context->env, context->callbackRef, &callback);
               napi_value retArg;
               napi_create_int32(context->env, context->retData, &retArg);
               napi_value ret;
               napi_call_function(context->env, nullptr, callback, 1, &retArg, &ret);
               napi_delete_reference(context->env, context->callbackRef);
   
               // Close the handle scope to release napi_value.
               napi_close_handle_scope(context->env, scope);
   
               if (work != nullptr) {
                   delete work;
               }
               delete context;
           }
       );
   }
   
   static napi_value QueueWork(napi_env env, napi_callback_info info)
   {
       size_t argc = 1;
       napi_value argv[1] = {nullptr};
       napi_value thisVar = nullptr;
       void *data = nullptr;
       napi_get_cb_info(env, info, &argc, argv, &thisVar, &data);
   
       // Check parameters.
       if (argc < 1) {
           napi_throw_error(env, "ParameterError", "one param expected");
           return nullptr;
       }
       napi_valuetype valueType = napi_undefined;
       napi_typeof(env, argv[0], &valueType);
       if (valueType != napi_function) {
           napi_throw_error(env, "ParameterError", "function expected");
           return nullptr;
       }
   
       // Save env and the callback for subsequent invoking.
       auto asyncContext = new CallbackContext();
       asyncContext->env = env;
       napi_create_reference(env, argv[0], 1, &asyncContext->callbackRef);
       // Simulate the logic for throwing a work object to a non-JS thread.
       std::thread testThread(StartThread, asyncContext);
       testThread.detach();
   
       return nullptr;
   }
   ```

3. Sample ArkTS code.

   ```ts
   import { queueWork }  from 'libqueue_work.so'
   
   queueWork((result: number) => {
       console.log("result = " + result);
   });
   ```
