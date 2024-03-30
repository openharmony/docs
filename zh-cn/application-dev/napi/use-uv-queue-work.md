# 在非ArkTS线程中回调ArkTS接口

## 场景介绍

ArkTS是单线程语言，通过NAPI接口对ArkTS对象的所有操作都须保证在同一个ArkTS线程上进行。本示例将介绍通过`napi_get_uv_event_loop`和`uv_queue_work`实现在非ArkTS线程中通过NAPI接口回调ArkTS函数。

## 使用示例

1. 接口声明、编译配置以及模块注册

   **接口声明**

   ```ts
   // index.d.ts
   export const queueWork: (cb: (arg: number) => void) => void;
   ```

   **编译配置**

   ```
   // CMakeLists.txt
   # the minimum version of CMake.
   cmake_minimum_required(VERSION 3.4.1)
   project(MyApplication)
   
   set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
   
   include_directories(${NATIVERENDER_ROOT_PATH}
                       ${NATIVERENDER_ROOT_PATH}/include)
   add_library(queue_work SHARED queue_work.cpp)
   target_link_libraries(queue_work PUBLIC libace_napi.z.so libhilog_ndk.z.so libuv.so)
   ```

   **模块注册**

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

2. 获取env对应的loop，并抛任务到ArkTS线程

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
       // 从env中获取对应的ArkTS线程的loop，此处的env需要在注册JS回调时保存下来。
       uv_loop_s* loop = nullptr;
       napi_get_uv_event_loop(context->env, &loop);
   
       // 创建uv_work_t用于传递私有数据，注意回调完成后需要释放内存,此处省略生成回传数据的逻辑，传回int类型1。
       uv_work_t* work = new uv_work_t;
       context->retData = 1;
       work->data = context;
   
       // 抛任务到ArkTS线程
       uv_queue_work(
           loop,
           work,
           // work_cb 此回调在另一个普通线程中执行，用于处理异步或者耗时任务，回调执行完后执行下面的回调。本示例中无需执行任务。
           [](uv_work_t* work) {},
           // after_work_cb 此回调在env对应的ArkTS线程中执行。
           [](uv_work_t* work, int status) {
               CallbackContext* context = reinterpret_cast<CallbackContext*>(work->data);
               napi_handle_scope scope = nullptr;
               // 打开handle scope用于管理napi_value的生命周期，否则会内存泄露。
               napi_open_handle_scope(context->env, &scope);
               if (scope == nullptr) {
                   return;
               }
   
               // 回调ArkTS函数
               napi_value callback = nullptr;
               napi_get_reference_value(context->env, context->callbackRef, &callback);
               napi_value retArg;
               napi_create_int32(context->env, context->retData, &retArg);
               napi_value ret;
               napi_call_function(context->env, nullptr, callback, 1, &retArg, &ret);
               napi_delete_reference(context->env, context->callbackRef);
   
               // 关闭handle scope释放napi_value
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
   
       // 参数检查
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
   
       // 保存env和回调函数，以便后续回调
       auto asyncContext = new CallbackContext();
       asyncContext->env = env;
       napi_create_reference(env, argv[0], 1, &asyncContext->callbackRef);
       // 模拟抛到非js线程执行逻辑
       std::thread testThread(StartThread, asyncContext);
       testThread.detach();
   
       return nullptr;
   }
   ```

3. ArkTS侧示例代码

   ```ts
   import { queueWork }  from 'libqueue_work.so'
   
   queueWork((result: number) => {
       console.log("result = " + result);
   });
   ```
