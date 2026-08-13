# Thread Safety Development Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:42:53.205Z pushedAt=2026-08-12T11:16:54.642Z -->

## When to Use

[napi_create_threadsafe_function](../reference/native-lib/napi.md#napi_create_threadsafe_function) is a Node-API used to create a thread-safe JS function, which can be called from multiple threads without race conditions or deadlocks. The following scenarios are involved:

- Asynchronous computing: If a time-consuming computing or I/O operation needs to be performed, you can create a thread-safe function to have the computing or I/O operation executed in a dedicated thread. This ensures normal running of the main thread and improves the response speed of your application.

- Data sharing: When multiple threads need to access the same data, using a thread-safe function can prevent race conditions or deadlocks during data read and write operations.

- Multithread programming: In the case of multithread programming, a thread-safe function can ensure communication and synchronization between multiple threads.

## Example

1. Configure the **CMakeLists.txt** file.

   ``` txt
   # the minimum version of CMake.
   cmake_minimum_required(VERSION 3.5.0)
   project(MyApplication3)

   set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

   if(DEFINED PACKAGE_FIND_FILE)
       include(${PACKAGE_FIND_FILE})
   endif()
   add_definitions( "-DLOG_DOMAIN=0xd0d0" )
   add_definitions( "-DLOG_TAG=\"testTag\"" )
   include_directories(${NATIVERENDER_ROOT_PATH}
                       ${NATIVERENDER_ROOT_PATH}/include)

   add_library(entry SHARED napi_init.cpp)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)

   add_library(entry1 SHARED thread_safety.cpp)
   target_link_libraries(entry1 PUBLIC libace_napi.z.so libhilog_ndk.z.so)
   ```

2. Define a thread-safe function at the native entry.

   <!-- @[napi_thread_safety_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/thread_safety.cpp) -->

   ``` C++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include <future>
   
   static constexpr int INT_ARG_2 = 2; // Input parameter index.
   static constexpr int INT_BUF_32 = 32; // Input parameter index.
   
   struct CallbackData {
       napi_threadsafe_function tsfn;
       napi_async_work work;
   };
   
   // Call ExecuteWork in the worker thread and execute the thread-safe function.
   static void ExecuteWork(napi_env env, void *data)
   {
       CallbackData *callbackData = reinterpret_cast<CallbackData *>(data);
       std::promise<std::string> promise;
       auto future = promise.get_future();
       napi_acquire_threadsafe_function(callbackData->tsfn);
       napi_call_threadsafe_function(callbackData->tsfn, &promise, napi_tsfn_nonblocking);
       napi_release_threadsafe_function(callbackData->tsfn, napi_tsfn_release);
       try {
           auto result = future.get();
           OH_LOG_INFO(LOG_APP, "XXX, Result from JS %{public}s", result.c_str());
       } catch (const std::exception &e) {
           OH_LOG_INFO(LOG_APP, "XXX, Result from JS %{public}s", e.what());
       }
   }
   
   static napi_value ResolvedCallback(napi_env env, napi_callback_info info)
   {
       void *data = nullptr;
       size_t argc = 1;
       napi_value argv[1];
       if (napi_get_cb_info(env, info, &argc, argv, nullptr, &data) != napi_ok) {
           return nullptr;
       }
       size_t result = 0;
       char buf[32] = {0};
       napi_get_value_string_utf8(env, argv[0], buf, INT_BUF_32, &result);
       reinterpret_cast<std::promise<std::string> *>(data)->set_value(std::string(buf));
       return nullptr;
   }
   
   static napi_value RejectedCallback(napi_env env, napi_callback_info info)
   {
       void *data = nullptr;
       if (napi_get_cb_info(env, info, nullptr, nullptr, nullptr, &data) != napi_ok) {
           return nullptr;
       }
       reinterpret_cast<std::promise<std::string> *>(data)->set_exception(
           std::make_exception_ptr(std::runtime_error("Error in jsCallback")));
       return nullptr;
   }
   
   static void CallJs(napi_env env, napi_value jsCb, void *context, void *data)
   {
       if (env == nullptr) {
           return;
       }
       napi_value undefined = nullptr;
       napi_value promise = nullptr;
       napi_get_undefined(env, &undefined);
       napi_call_function(env, undefined, jsCb, 0, nullptr, &promise);
       napi_value thenFunc = nullptr;
       if (napi_get_named_property(env, promise, "then", &thenFunc) != napi_ok) {
           return;
       }
       napi_value resolvedCallback;
       napi_value rejectedCallback;
       napi_create_function(env, "resolvedCallback", NAPI_AUTO_LENGTH, ResolvedCallback, data, &resolvedCallback);
       napi_create_function(env, "rejectedCallback", NAPI_AUTO_LENGTH, RejectedCallback, data, &rejectedCallback);
       napi_value argv[2] = {resolvedCallback, rejectedCallback};
       napi_call_function(env, promise, thenFunc, INT_ARG_2, argv, nullptr);
   }
   
   // After the task is complete, clear and reclaim resources.
   static void WorkComplete(napi_env env, napi_status status, void *data)
   {
       CallbackData *callbackData = reinterpret_cast<CallbackData *>(data);
       napi_release_threadsafe_function(callbackData->tsfn, napi_tsfn_release);
       napi_delete_async_work(env, callbackData->work);
       callbackData->tsfn = nullptr;
       callbackData->work = nullptr;
       delete callbackData;
   }
   
   static napi_value StartThread(napi_env env, napi_callback_info info)
   {
       CallbackData *callbackData = new CallbackData();
       size_t argc = 1;
       napi_value jsCb = nullptr;
       napi_get_cb_info(env, info, &argc, &jsCb, nullptr, nullptr);
   
       // Create a thread-safe function.
       napi_value resourceName = nullptr;
       napi_create_string_utf8(env, "Thread-safe Function Demo", NAPI_AUTO_LENGTH, &resourceName);
       napi_create_threadsafe_function(env, jsCb, nullptr, resourceName, 0, 1, callbackData, nullptr, callbackData, CallJs,
                                       &callbackData->tsfn);
   
       // Create an asynchronous work object.
       // ExecuteWork is executed on a non-JS thread created by libuv.
       // napi_create_async_work is used to simulate the scenario where the napi_call_threadsafe_function API is used to submit a task to the JS thread from a non-JS thread.
       napi_create_async_work(env, nullptr, resourceName, ExecuteWork, WorkComplete, callbackData, &callbackData->work);
   
       // Add the asynchronous work object to the asynchronous task queue.
       napi_queue_async_work(env, callbackData->work);
       return nullptr;
   }
   ```

3. Module registration.

   ```c++
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           {"startThread", nullptr, StartThread, nullptr, nullptr, nullptr, napi_default, nullptr}
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END

   static napi_module demoModule = {
       .nm_version = 1,
       .nm_flags = 0,
       .nm_filename = nullptr,
       .nm_register_func = Init,
       .nm_modname = "entry1",
       .nm_priv = ((void *)0),
       .reserved = {0},
   };

   extern "C" __attribute__((constructor)) void RegisterEntryModule(void) { napi_module_register(&demoModule); }
   ```

4. ArkTS code:

   <!-- @[napi_thread_safety_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/types/libentry1/Index.d.ts) -->

   ``` TypeScript
   export const startThread: (a: () => Promise<string>) => void;
   ```

   Import the header files.

   ``` ts
   import nativeModule from 'libentry1.so';
   ```

   <!-- @[napi_thread_safety_ets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // index.ets
   let callback = (): Promise<string> => {
     return new Promise((resolve) => {
       setTimeout(() => {
         resolve('string from promise');
       }, 5000);
     });
   }
   nativeModule.startThread(callback);
   ```

## Child Thread Interaction Scenarios

- **napi_threadsafe_function** is used the same way in the main thread and child thread. The following is an example of using **napi_threadsafe_function** in the child thread.

### C++ and ArkTS Child Thread Interaction Based on [Worker](../../application-dev/arkts-utils/worker-introduction.md)

1. Configure the **CMakeLists.txt** file.

   ``` txt
   # the minimum version of CMake.
   cmake_minimum_required(VERSION 3.5.0)
   project(MyApplication3)

   set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

   if(DEFINED PACKAGE_FIND_FILE)
       include(${PACKAGE_FIND_FILE})
   endif()
   add_definitions( "-DLOG_DOMAIN=0xd0d0" )
   add_definitions( "-DLOG_TAG=\"testTag\"" )
   include_directories(${NATIVERENDER_ROOT_PATH}
                       ${NATIVERENDER_ROOT_PATH}/include)

   add_library(entry SHARED napi_init.cpp)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)

   add_library(entry1 SHARED thread_safety.cpp)
   target_link_libraries(entry1 PUBLIC libace_napi.z.so libhilog_ndk.z.so)
   ```

2. Define a thread-safe function and create a child thread at the native entry.

   <!-- @[napi_call_threadsafe_function_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/thread_safety.cpp) -->

   ``` C++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include <future>
   // ...
   
   struct TsfnContext {
       napi_ref callbackRef;
   };
   
   struct ThreadData {
       std::string inputStr;
       napi_threadsafe_function tsfn;
   };
   
   // C++ child thread.
   void NativeThread(void* arg)
   {
       auto* data = static_cast<ThreadData*>(arg);
       OH_LOG_INFO(LOG_APP, "[C++ SubThread] Received from Worker: %{public}s\n", data->inputStr.c_str());
       std::string str = "Hello from C++!";
       std::string msg = "Echo of " + str;
       char* cstr = strdup(msg.c_str());
       napi_call_threadsafe_function(data->tsfn, cstr, napi_tsfn_nonblocking);
       napi_release_threadsafe_function(data->tsfn, napi_tsfn_release);
       delete data;
   }
   
   // Callback executed in the JS thread.
   void CallJsCallback(napi_env env, napi_value jsCallback, void* context, void* data)
   {
       if (data == nullptr) {
           return;
       }
       char* message = static_cast<char*>(data);
       napi_value jsStr;
       napi_create_string_utf8(env, message, NAPI_AUTO_LENGTH, &jsStr);
       napi_value global;
       napi_get_global(env, &global);
       napi_value result;
       napi_call_function(env, global, jsCallback, 1, &jsStr, &result);
       free(message);
   }
   
   // Callback triggered when the tsfn is destroyed.
   void TsfnFinalizeCallback(napi_env env, void* finalizeData, void* finalizeHint)
   {
       TsfnContext* ctx = static_cast<TsfnContext*>(finalizeData);
       if (ctx && ctx->callbackRef) {
           napi_delete_reference(env, ctx->callbackRef);
           delete ctx;
       }
   }
   
   // Entry function called by ArkTS.
   napi_value StartWithCallback(napi_env env, napi_callback_info info)
   {
       size_t argc = 2;
       napi_value args[2];
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
       size_t length = 0;
       napi_status status = napi_get_value_string_utf8(env, args[0], nullptr, 0, &length);
       if (status != napi_ok) {
           OH_LOG_ERROR(LOG_APP, "napi_get_value_string_utf8 failed");
           return nullptr;
       }
       char* inputStr = new char[length + 1];
       std::fill(inputStr, inputStr + (length + 1), 0);
       status = napi_get_value_string_utf8(env, args[0], inputStr, length + 1, &length);
       if (status != napi_ok) {
           if (inputStr) {
               delete[] inputStr;
           }
           OH_LOG_ERROR(LOG_APP, "napi_get_value_string_utf8 failed");
           return nullptr;
       }
       std::string inputString(inputStr, length);
       delete[] inputStr;
       TsfnContext* ctx = new TsfnContext();
       napi_create_reference(env, args[1], 1, &ctx->callbackRef);
       napi_value resourceName;
       napi_create_string_utf8(env, "TSFN_WorkerToCpp", NAPI_AUTO_LENGTH, &resourceName);
       napi_threadsafe_function tsfn;
       napi_create_threadsafe_function(env, args[1], nullptr, resourceName,
                                       0, 1, ctx, TsfnFinalizeCallback, nullptr, CallJsCallback, &tsfn);
       auto* threadData = new ThreadData{std::move(inputString), tsfn};
       std::thread nativethread(NativeThread, threadData);
       nativethread.detach();
       return nullptr;
   }
   ```

3. Module registration.

   ``` c++
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           {"startWithCallback", nullptr, StartWithCallback, nullptr, nullptr, nullptr, napi_default, nullptr}
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END

   static napi_module demoModule = {
       .nm_version = 1,
       .nm_flags = 0,
       .nm_filename = nullptr,
       .nm_register_func = Init,
       .nm_modname = "entry1",
       .nm_priv = ((void *)0),
       .reserved = {0},
   };

   extern "C" __attribute__((constructor)) void RegisterEntryModule(void) { napi_module_register(&demoModule); }
   ```

4. DevEco Studio supports generation of Worker templates with a single click. In the corresponding {moduleName} directory, right-click anywhere and choose **New > Worker** to automatically generate the Worker template files and configuration information. In this example, we will create a Worker named "Worker".

   ``` json5
   "buildOption": {
     "sourceOption": {
       "workers": [
         "./src/main/ets/workers/Worker.ets"
        ]
     },
   }
   ```

5. Sample code of the worker thread.

   <!-- @[napi_call_threadsafe_function_worker](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/ets/workers/Worker.ets) -->

   ``` TypeScript
   // entry/src/main/ets/workers/Worker.ets
   
   import nativeModule from 'libentry1.so';
   import { worker, MessageEvents } from '@kit.ArkTS';
   
   const port = worker.workerPort;
   
   port.onmessage = (e: MessageEvents) => {
     console.info('Worker thread received:' + e.data);
     nativeModule.startWithCallback('Hello', (result: string) => {
       console.info('[Worker] Got from native:', result);
       port.postMessage(result);
     });
   }
   ```

6. Description of the API in the .d.ts file.

   <!-- @[napi_call_threadsafe_function_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/types/libentry1/Index.d.ts) -->

   ``` TypeScript
   export const startWithCallback: (input: string, callback: (msg: string) => void) => void;
   ```

7. Call APIs from ArkTS.

   ``` ts
   import nativeModule from 'libentry1.so';
   import { worker } from '@kit.ArkTS';
   ```

   <!-- @[napi_call_threadsafe_function_worker_ets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/ets/pages/Index.ets) -->  

   ``` TypeScript
   // index.ets
   const wk = new worker.ThreadWorker('entry/ets/workers/Worker.ets');
   wk.postMessage('Start');
   wk.onmessage = (msg) => {
     console.info('[Main] Received:', msg.data);
     wk.terminate();
   }
   ```

   ``` txt
   Execution result:
   Worker thread received:Start
   [C++ SubThread] Received from Worker: Hello
   [Worker] Got from native: Echo of Hello from C++!
   [Main] Received: Echo of Hello from C++
   ```

### C++ and ArkTS Child Thread Interaction Based on [Taskpool](../../application-dev/arkts-utils/taskpool-introduction.md)

1. The implementation code and module registration on the native side are the same as those in "C++ and ArkTS Child Thread Interaction Based on Worker". You can directly reuse the code.

2. ArkTS code:

   ``` ts
   import nativeModule from 'libentry1.so';
   import { taskpool } from '@kit.ArkTS';

   @Concurrent
   function nativeCall(input : string): void {
     console.info('Taskpool thread received:%s', input);
     nativeModule.startWithCallback('Hello', (result: string) => {
       console.info('[Taskpool] Got from native:', result);
     });
   }

   async function testTaskpool() : Promise<void> {
     try {
       const task = new taskpool.Task(nativeCall, 'Start');
       await taskpool.execute(task);
     } catch (e) {
       console.error(`Taskpool execute error: ${e}`);
     }
   }
   ```

   <!-- @[napi_call_threadsafe_function_taskpool_ets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // index.ets
   testTaskpool();
   ```

   ``` txt
   Execution result:
   Taskpool thread received:Start
   [C++ SubThread] Received from Worker: Hello
   [Taskpool] Got from native: Echo of Hello from C++!
   ```