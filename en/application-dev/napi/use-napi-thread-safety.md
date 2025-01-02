# Thread Safety Development Using Node-API


## When to Use

**napi_create_threadsafe_function** is a Node-API interface used to create a thread-safe JS function, which can be called from multiple threads without race conditions or deadlocks. Thread-safe functions can be used in the following scenarios:


- Asynchronous computing: If a time-consuming computing or I/O operation needs to be performed, you can create a thread-safe function to have the computing or I/O operation executed in a dedicated thread. This ensures normal running of the main thread and improves the response speed of your application.

- Data sharing: When multiple threads need to access the same data, using a thread-safe function can prevent race conditions or deadlocks during data read and write operations.

- Multithread programming: In the case of multithread programming, a thread-safe function can ensure communication and synchronization between multiple threads.


## Example

1. Define a thread-safe function at the native entry.
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
   
       // Create a thread-safe function.
       napi_value resourceName = nullptr;
       napi_create_string_utf8(env, "Thread-safe Function Demo", NAPI_AUTO_LENGTH, &resourceName);
       napi_create_threadsafe_function(env, jsCb, nullptr, resourceName, 0, 1, callbackData, nullptr, 
           callbackData, CallJs, &callbackData->tsfn);
   
       // Create an asynchronous work object.
       // ExecuteWork is executed on a non-JS thread created by libuv. The napi_create_async_work is used to simulate the scenario, in which napi_call_threadsafe_function is used to submit tasks to a JS thread from a non-JS thread.
       napi_create_async_work(env, nullptr, resourceName, ExecuteWork, WorkComplete, callbackData,
           &callbackData->work);
   
       // Add the asynchronous work object to the asynchronous task queue.
       napi_queue_async_work(env, callbackData->work);
       return nullptr;
   }
   ```

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

3. Execute the asynchronous callback in a JS thread.
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

4. After the task is complete, clear and reclaim resources.
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

5. Initialize the module and call the API from ArkTS.
   ```c++
   // Initialize the module.
   static napi_value Init(napi_env env, napi_value exports) {
       CallbackData *callbackData = new CallbackData(); // Release when the thread exits.
       napi_property_descriptor desc[] = {
           {"startThread", nullptr, StartThread, nullptr, nullptr, nullptr, napi_default, callbackData},
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   
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
