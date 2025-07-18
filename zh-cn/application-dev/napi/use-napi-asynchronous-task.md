# 使用Node-API接口进行异步任务开发

## 场景介绍

[napi_create_async_work](../reference/native-lib/napi.md#napi_create_async_work)是Node-API接口之一，用于创建一个异步工作对象。在需要执行耗时操作的场景中使用，避免阻塞env所在的ArkTS线程，确保应用程序的性能和响应性能。例如以下场景：

- 文件操作：读取大型文件或执行复杂的文件操作时，可以使用异步工作对象来避免阻塞env所在的ArkTS线程。

- 网络请求：当需要进行网络请求并等待响应时，使用异步工作对象确保主线程不被阻塞，提高应用程序的响应性能。

- 数据库操作：当需要执行复杂的数据库查询或写入操作时，使用异步工作对象确保主线程不被阻塞，提高应用程序的并发性能。

- 图像处理：当需要对大型图像进行处理或执行复杂的图像算法时，使用异步工作对象确保主线程不被阻塞，提高应用程序的实时性能。

napi_queue_async_work接口使用uv_queue_work能力，并管理回调中napi_value的生命周期。

异步调用支持callback和Promise两种方式，选择哪种方式由开发者决定。以下是两种方式的示例代码：

![NAPI 异步任务线程](figures/napi_async_work.png)

## 使用Promise方式示例

![NAPI Promise异步流程](figures/napi_async_work_with_promise.png)

1. 使用napi_create_async_work创建异步任务，使用napi_queue_async_work将任务加入队列，等待执行。

   ```cpp
   // 调用方提供的data context，该数据会传递给execute和complete函数
   struct CallbackData {
       napi_async_work asyncWork = nullptr;
       napi_deferred deferred = nullptr;
       napi_ref callback = nullptr;
       double args = 0;
       double result = 0;
   };

   static napi_value AsyncWork(napi_env env, napi_callback_info info)
   {
      size_t argc = 1;
      napi_value args[1];
      napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

      napi_value promise = nullptr;
      napi_deferred deferred = nullptr;
      napi_create_promise(env, &deferred, &promise);

      auto callbackData = new CallbackData();
      callbackData->deferred = deferred;
      napi_get_value_double(env, args[0], &callbackData->args);

      napi_value resourceName = nullptr;
      napi_create_string_utf8(env, "AsyncCallback", NAPI_AUTO_LENGTH, &resourceName);
      // 创建异步任务
      napi_create_async_work(env, nullptr, resourceName, ExecuteCB, CompleteCB, callbackData, &callbackData->asyncWork);
      // 将异步任务加入队列
      napi_queue_async_work(env, callbackData->asyncWork);

      return promise;
   }
   ```
   <!-- @[napi_create_async_work](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIAsynchronousTask/entry/src/main/cpp/napi_init.cpp) -->

2. 定义异步任务的第一个回调函数，该函数在工作线程中执行，处理具体的业务逻辑。

   ```cpp
   static void ExecuteCB(napi_env env, void *data)
   {
       CallbackData *callbackData = reinterpret_cast<CallbackData *>(data);
       callbackData->result = callbackData->args;
   }
   ```
   <!-- @[napi_first_call_back_work](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIAsynchronousTask/entry/src/main/cpp/napi_init.cpp) -->

3. 定义异步任务的第二个回调函数，该函数在主线程执行，将结果传递给ArkTS侧。

   ```cpp
   static void CompleteCB(napi_env env, napi_status status, void *data)
   {
       CallbackData *callbackData = reinterpret_cast<CallbackData *>(data);
       napi_value result = nullptr;
       napi_create_double(env, callbackData->result, &result);
       if (callbackData->result > 0) {
           napi_resolve_deferred(env, callbackData->deferred, result);
       } else {
           napi_reject_deferred(env, callbackData->deferred, result);
       }

       napi_delete_async_work(env, callbackData->asyncWork);
       delete callbackData;
       callbackData = nullptr;
   }
   ```
   <!-- @[napi_second_call_back_main](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIAsynchronousTask/entry/src/main/cpp/napi_init.cpp) -->

4. 模块初始化和ArkTS侧调用接口。

   ```cpp
   // 模块初始化
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "asyncWork", nullptr, AsyncWork, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
    ```
   <!-- @[napi_value_init](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIAsynchronousTask/entry/src/main/cpp/callback.cpp) -->

    ```ts
   // 接口对应的.d.ts描述
   export const asyncWork: (data: number) => Promise<number>;

   // ArkTS侧调用接口
   nativeModule.asyncWork(1024).then((result) => {
       hilog.info(0x0000, 'XXX', 'result is %{public}d', result);
   });
   ```
   运行结果：result is 1024

## 使用callback方式示例

![NAPI Callback异步流程](figures/napi_async_work_with_callback.png)

1. 使用napi_create_async_work创建异步任务，并使用napi_queue_async_work将异步任务加入队列，等待执行。

   ```cpp
   static constexpr int INT_ARG_2 = 2; // 入参索引

   // 调用方提供的data context，该数据会传递给execute和complete函数
   struct CallbackData {
       napi_async_work asyncWork = nullptr;
       napi_ref callbackRef = nullptr;
       double args[2] = {0};
       double result = 0;
   };

   napi_value AsyncWork(napi_env env, napi_callback_info info)
   {
       size_t argc = 3;
       napi_value args[3];
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
       auto asyncContext = new CallbackData();
       // 将接收到的参数保存到callbackData
       napi_get_value_double(env, args[0], &asyncContext->args[0]);
       napi_get_value_double(env, args[1], &asyncContext->args[1]);
       // 将传入的callback转换为napi_ref延长其生命周期，防止被GC掉
       napi_create_reference(env, args[INT_ARG_2], 1, &asyncContext->callbackRef);
       napi_value resourceName = nullptr;
       napi_create_string_utf8(env, "asyncWorkCallback", NAPI_AUTO_LENGTH, &resourceName);
       // 创建异步任务
       napi_create_async_work(env, nullptr, resourceName, ExecuteCB, CompleteCB,
                              asyncContext, &asyncContext->asyncWork);
       // 将异步任务加入队列
       napi_queue_async_work(env, asyncContext->asyncWork);
       return nullptr;
   }
   ```
   <!-- @[napi_create_queue_async_work](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIAsynchronousTask/entry/src/main/cpp/callback.cpp) -->

2. 定义异步任务的第一个回调函数，该函数在工作线程中执行，处理具体的业务逻辑。

   ```cpp
   static void ExecuteCB(napi_env env, void *data)
   {
       CallbackData *callbackData = reinterpret_cast<CallbackData *>(data);
       callbackData->result = callbackData->args[0] + callbackData->args[1];
   }
   ```
   <!-- @[napi_async_first_call_back_work](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIAsynchronousTask/entry/src/main/cpp/callback.cpp) -->

3. 定义异步任务的第二个回调函数，该函数在主线程执行，将结果传递给ArkTS侧。

   ```cpp
   static void CompleteCB(napi_env env, napi_status status, void *data)
   {
       CallbackData *callbackData = reinterpret_cast<CallbackData *>(data);
       napi_value callbackArg[1] = {nullptr};
       napi_create_double(env, callbackData->result, &callbackArg[0]);
       napi_value callback = nullptr;
       napi_get_reference_value(env, callbackData->callbackRef, &callback);
       // 执行回调函数
       napi_value result;
       napi_value undefined;
       napi_get_undefined(env, &undefined);
       napi_call_function(env, undefined, callback, 1, callbackArg, &result);
       // 删除napi_ref对象以及异步任务
       napi_delete_reference(env, callbackData->callbackRef);
       napi_delete_async_work(env, callbackData->asyncWork);
       delete callbackData;
       callbackData = nullptr;
   }
   ```
   <!-- @[napi_async_second_call_back_work](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIAsynchronousTask/entry/src/main/cpp/callback.cpp) -->

4. 模块初始化以及ArkTS侧调用接口。

   ```cpp
   // 模块初始化
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "asyncWork", nullptr, AsyncWork, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```
   <!-- @[napi_value_init](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIAsynchronousTask/entry/src/main/cpp/callback.cpp) -->

   ```ts
   // 接口对应的.d.ts描述
   export const asyncWork: (arg1: number, arg2: number, callback: (result: number) => void) => void;

   // ArkTS侧调用接口
   let num1: number = 123;
   let num2: number = 456;
   nativeModule.asyncWork(num1, num2, (result) => {
       hilog.info(0x0000, 'XXX', 'result is %{public}d', result);
   });
   ```
   运行结果：result is 579

## 注意事项
- 调用napi_cancel_async_work接口，无论底层uv是否失败都会返回napi_ok。若因为底层uv导致取消任务失败，complete callback中的status会传入对应错误值，请在complete callback中对status进行处理。
- NAPI的异步工作项（napi_async_work）建议单次使用。napi_queue_async_work后，该napi_async_work需在complete回调执行时或执行后，通过napi_delete_async_work完成释放。同一个napi_async_work只允许释放一次，重复释放会导致未定义行为。
`napi_async_work`的`execute_cb`运行在一个独立的工作线程中，该线程从uv线程池中取出。不同工作线程之间互不影响。
- 在任务的执行时序上，`napi_async_work`仅保证`complete_cb`在`execute_cb`之后执行。不同`napi_async_work`的`execute_cb`在各自的工作线程上运行，因此无法保证不同`execute_cb`的执行顺序。如果任务执行需要顺序，建议使用`napi_threadsafe_function`系列接口，这些接口是保序的。具体使用方法可参考[链接](use-napi-thread-safety.md)。