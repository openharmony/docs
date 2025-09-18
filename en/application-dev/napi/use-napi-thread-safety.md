# Thread Safety Development Using Node-API
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->


## When to Use

**napi_create_threadsafe_function** is a Node-API interface used to create a thread-safe JS function, which This function is used for sharing and invoking among multiple threads to avoid race conditions and deadlocks. The following scenarios are involved:


- Asynchronous computing: If time-consuming computing or I/O operations need to be performed, you can create thread-safe functions to complete the computing or I/O operations in another thread. This prevents the main thread from being blocked and improves the program response speed.

- Data sharing: If multiple threads need to access the same data, you can create a thread-safe function to prevent problems such as competition conditions or deadlocks during data read and write.

- Multithread programming: In the case of multithread programming, a thread-safe function can ensure communication and synchronization between multiple threads.


## Example

1. Define the thread-safe function at the native entry.
   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include <future>

   struct CallbackData {
       napi_threadsafe_function tsfn;
       napi_async_work work;
   };

   static napi_value StartThread(napi_env env, napi_callback_info info)
   {
       size_t argc = 1;
       napi_value jsCb = nullptr;
       CallbackData *callbackData = new CallbackData (); // Released when the asynchronous task is complete.
       napi_get_cb_info(env, info, &argc, &jsCb, nullptr, nullptr);

       // Create a thread-safe function.
       napi_value resourceName = nullptr;
       napi_create_string_utf8(env, "Thread-safe Function Demo", NAPI_AUTO_LENGTH, &resourceName);
       napi_create_threadsafe_function(env, jsCb, nullptr, resourceName, 0, 1, nullptr, nullptr,
           nullptr, CallJs, &callbackData->tsfn);

       // Create an asynchronous work object.
       // ExecuteWork is executed on a non-JS thread created by libuv. The napi_create_async_work is used to simulate the scenario, in which napi_call_threadsafe_function is used to submit tasks to a JS thread from a non-JS thread.
       napi_create_async_work(env, nullptr, resourceName, ExecuteWork, WorkComplete, callbackData,
           &callbackData->work);

       // Add the asynchronous work object to the asynchronous task queue.
       napi_queue_async_work(env, callbackData->work);
       return nullptr;
   }
   ```
   <!-- @[napi_thread_safety_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/thread_safety.cpp) -->

2. Call **ExecuteWork** in a worker thread to execute the thread-safe function.
   ```c++
   static void ExecuteWork(napi_env env, void *data)
   {
       CallbackData *callbackData = reinterpret_cast<CallbackData *>(data);
       std::promise<std::string> promise;
       auto future = promise.get_future();
       napi_call_threadsafe_function(callbackData->tsfn, &promise, napi_tsfn_nonblocking);
       try {
           auto result = future.get();
           // OH_LOG_INFO(LOG_APP, "XXX, Result from JS %{public}s", result.c_str());
       } catch (const std::exception &e) {
           // OH_LOG_INFO(LOG_APP, "XXX, Result from JS %{public}s", e.what());
       }
   }
   ```
   <!-- @[napi_thread_safety_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/thread_safety.cpp) -->

3. Execute the asynchronous callback in a JS thread.
   ```c++
   static constexpr int INT_NUM_2 = 2;   // Integer 2
   static constexpr int INT_BUF_32 = 32; // The length of the integer string is 32.

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
       napi_value resolvedCallback = nullptr;
       napi_value rejectedCallback = nullptr;
       napi_create_function(env, "resolvedCallback", NAPI_AUTO_LENGTH, ResolvedCallback, data,
   					     &resolvedCallback);
       napi_create_function(env, "rejectedCallback", NAPI_AUTO_LENGTH, RejectedCallback, data,
   					     &rejectedCallback);
       napi_value argv[2] = {resolvedCallback, rejectedCallback};
       napi_call_function(env, promise, thenFunc, INT_NUM_2, argv, nullptr);
   }
   ```
   <!-- @[napi_thread_safety_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/thread_safety.cpp) -->

4. After the task is complete, clear and reclaim resources.
   ```c++
   static void WorkComplete(napi_env env, napi_status status, void *data)
   {
       CallbackData *callbackData = reinterpret_cast<CallbackData *>(data);
       if (callbackData == nullptr) {
           return;
       }
       napi_release_threadsafe_function(callbackData->tsfn, napi_tsfn_release);
       napi_delete_async_work(env, callbackData->work);
       callbackData->tsfn = nullptr;
       callbackData->work = nullptr;
       delete callbackData;
   }
   ```
   <!-- @[napi_thread_safety_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/thread_safety.cpp) -->

5. Initialize the module and call the API on the ArkTS side.
   ```c++
   // Initialize the module.
   static napi_value Init(napi_env env, napi_value exports) {
       napi_property_descriptor desc[] = {
           {"startThread", nullptr, StartThread, nullptr, nullptr, nullptr, napi_default, nullptr},
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```
   <!-- @[napi_thread_safety_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/thread_safety.cpp) -->

   ``` ts
   // Description of the interface in the .d.ts file.
   export const startThread: (callback: () => Promise<string>) => void;
   ```
   <!-- @[napi_thread_safety_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/types/libentry1/Index.d.ts) -->

   ``` ts
   // Call the API of ArkTS.
   import nativeModule from 'libentry.so'; // Import native capabilities.

   let callback = (): Promise<string> => {
     return new Promise((resolve) => {
       setTimeout(() => {
         resolve("string from promise");
       }, 5000);
     });
   }
   nativeModule.startThread(callback);
   ```
   <!-- @[napi_thread_safety_ets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/ets/pages/Index.ets) -->
