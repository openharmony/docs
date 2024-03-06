# 使用Node-API接口进行线程安全开发


## 场景介绍

napi_create_threadsafe_function是Node-API接口之一，用于创建一个线程安全的JavaScript函数。主要用于在多个线程之间共享和调用，而不会出现竞争条件或死锁。例如以下场景：


- 异步计算：如果需要进行耗时的计算或IO操作，可以创建一个线程安全的函数，将计算或IO操作放在另一个线程中执行，避免阻塞主线程，提高程序的响应速度。

- 数据共享：如果多个线程需要访问同一份数据，可以创建一个线程安全的函数，确保数据的读写操作不会发生竞争条件或死锁等问题。

- 多线程编程：如果需要进行多线程编程，可以创建一个线程安全的函数，确保多个线程之间的通信和同步操作正确无误。


## 使用示例

1. 在Native入口定义线程安全函数。
   ```c++
   struct CallbackData {
       napi_threadsafe_function tsfn;
       napi_async_work work;
   };
   
   static napi_value StartThread(napi_env env, napi_callback_info info)
   {
       size_t argc = 1;
       napi_value jsCb = nullptr;
       CallbackData *callbackData = nullptr;
       napi_get_cb_info(env, info, &argc, &jsCb, nullptr, reinterpret_cast<void **>(&callbackData));
   
       // 创建一个线程安全函数
       napi_value resourceName = nullptr;
       napi_create_string_utf8(env, "Thread-safe Function Demo", NAPI_AUTO_LENGTH, &resourceName);
       napi_create_threadsafe_function(env, jsCb, nullptr, resourceName, 0, 1, callbackData, nullptr, 
           callbackData, CallJs, &callbackData->tsfn);
   
       // 创建一个异步任务
       napi_create_async_work(env, nullptr, resourceName, ExecuteWork, WorkComplete, callbackData,
           &callbackData->work);
   
       // 将异步任务加入到异步队列中
       napi_queue_async_work(env, callbackData->work);
       return nullptr;
   }
   ```

2. 在工作线程中调用ExecuteWork，并执行线程安全函数。
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

3. 在JS线程执行异步回调函数。
   ```c++
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
       napi_get_value_string_utf8(env, argv[0], buf, 32, &result);
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
       napi_create_function(env, "resolvedCallback", NAPI_AUTO_LENGTH, ResolvedCallback, data,
   					     &resolvedCallback);
       napi_create_function(env, "rejectedCallback", NAPI_AUTO_LENGTH, RejectedCallback, data,
   					     &rejectedCallback);
       napi_value argv[2] = {resolvedCallback, rejectedCallback};
       napi_call_function(env, promise, thenFunc, 2, argv, nullptr);
   }
   ```

4. 任务执行完成后，进行资源清理回收。
   ```c++
   static void WorkComplete(napi_env env, napi_status status, void *data)
   {
       CallbackData *callbackData = reinterpret_cast<CallbackData *>(data);
       napi_release_threadsafe_function(callbackData->tsfn, napi_tsfn_release);
       napi_delete_async_work(env, callbackData->work);
       callbackData->tsfn = nullptr;
       callbackData->work = nullptr;
   }
   ```

5. 模块初始化以及ArkTS侧调用接口。
   ```
   // 模块初始化
   static napi_value Init(napi_env env, napi_value exports) {
       CallbackData *callbackData = new CallbackData(); // 可在线程退出时释放
       napi_property_descriptor desc[] = {
           {"startThread", nullptr, StartThread, nullptr, nullptr, nullptr, napi_default, callbackData},
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   
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
