# 使用Node-API接口进行线程安全开发
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--SE: @shilei123-->
<!--TSE: @kirl75; @zsw_zhushiwei-->


## 场景介绍

napi_create_threadsafe_function是Node-API接口之一，用于创建一个线程安全的JavaScript函数。该函数主要用于在多个线程之间共享和调用，避免竞争条件和死锁。包含以下场景：


- 异步计算：若需执行耗时的计算或IO操作，可创建线程安全的函数，在另一线程中完成计算或IO操作，避免阻塞主线程，提升程序响应速度。

- 数据共享：若多个线程需访问同一份数据，可以创建一个线程安全的函数，避免数据进行读写操作时发生竞争条件或死锁等问题。

- 多线程编程：若需要进行多线程编程，可以创建一个线程安全的函数，确保多个线程之间的通信和同步操作正确。


## 使用示例

1. 定义线程安全函数在Native入口。
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
       CallbackData *callbackData = new CallbackData(); // 异步任务完成时释放
       napi_get_cb_info(env, info, &argc, &jsCb, nullptr, nullptr);

       // 创建一个线程安全函数
       napi_value resourceName = nullptr;
       napi_create_string_utf8(env, "Thread-safe Function Demo", NAPI_AUTO_LENGTH, &resourceName);
       napi_create_threadsafe_function(env, jsCb, nullptr, resourceName, 0, 1, nullptr, nullptr,
           nullptr, CallJs, &callbackData->tsfn);

       // 创建一个异步任务
       // ExecuteWork会执行在一个由libuv创建的非JS线程上，此处使用napi_create_async_work是为了模拟在非JS线程场景使用napi_call_threadsafe_function接口向JS线程提交任务
       napi_create_async_work(env, nullptr, resourceName, ExecuteWork, WorkComplete, callbackData,
           &callbackData->work);

       // 将异步任务加入到异步队列中
       napi_queue_async_work(env, callbackData->work);
       return nullptr;
   }
   ```
   <!-- @[napi_thread_safety_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/thread_safety.cpp) -->

2. 在工作线程中调用ExecuteWork并执行线程安全函数。
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

3. 在JS线程中执行异步回调函数。
   ```c++
   static constexpr int INT_NUM_2 = 2;   // int类型数值2
   static constexpr int INT_BUF_32 = 32; // int类型字符串长度32

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

4. 任务执行完成后，进行资源清理回收。
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

5. 初始化模块并在ArkTS侧调用接口。
   ```c++
   // 模块初始化
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
   // 接口对应的.d.ts描述
   export const startThread: (callback: () => Promise<string>) => void;
   ```
   <!-- @[napi_thread_safety_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/types/libentry1/Index.d.ts) -->

   ``` ts
   // ArkTS侧调用接口
   import nativeModule from 'libentry.so'; // 通过import的方式，引入Native能力

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
