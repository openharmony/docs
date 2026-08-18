# Creating a Sendable Strong Reference to an ArkTS Object Using Node-API Extension APIs

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:40:51.771Z pushedAt=2026-08-12T11:15:00.224Z -->

OpenHarmony APIs provide the capability of sharing strong references across ArkTS threads in the same process. Unlike **napi_ref**, **napi_sendable_ref** supports operations across ArkTS threads, but also has some restrictions.

## When to Use

You can use the [napi_create_strong_sendable_reference](../reference/native-lib/napi.md#napi_create_strong_sendable_reference) API to create a Sendable strong reference to a Sendable ArkTS object, use the [napi_get_strong_sendable_reference_value](../reference/native-lib/napi.md#napi_get_strong_sendable_reference_value) API to obtain the referenced ArkTS object, and use the [napi_delete_strong_sendable_reference](../reference/native-lib/napi.md#napi_delete_strong_sendable_reference) API to delete the Sendable strong reference. These operations can be performed in the same ArkTS thread or different ArkTS threads.

## Available APIs

| API                                    | Description                                      |
| ---------------------------------------- | ------------------------------------------ |
| [napi_create_strong_sendable_reference](../reference/native-lib/napi.md#napi_create_strong_sendable_reference)    | Creates a Sendable strong reference to a Sendable ArkTS object.|
| napi_delete_strong_sendable_reference   | Deletes a Sendable strong reference.                       |
| napi_get_strong_sendable_reference_value| Obtains the ArkTS object value associated with a Sendable strong reference.  |

## Sample Code

- Module registration

   ```c++
   // napi_init.cpp
   #include "napi/native_api.h"
   #include <cstdlib>
   #include <thread>

   #define ASSERT_EQ(a, b) \
   do {                    \
      if (a != b) {        \
         std::abort();     \
      }                    \
   } while(0)

   #define ASSERT_CHECK_CALL(a) ASSERT_EQ(a, napi_ok)

   napi_sendable_ref sRef = nullptr;
   static napi_value CreateSendableRef(napi_env env, napi_callback_info info)
   {
      size_t argc = 1;
      napi_value args[1] = {nullptr};

      ASSERT_CHECK_CALL(napi_get_cb_info(env, info, &argc, args, nullptr, nullptr));
      ASSERT_CHECK_CALL(napi_create_strong_sendable_reference(env, args[0], &sRef));
      
      napi_value str = nullptr;
      ASSERT_CHECK_CALL(napi_create_string_utf8(env, "success", NAPI_AUTO_LENGTH, &str));
      return str;
   }

   static napi_value GetAndModifySendableRefValueInArkRuntime(napi_env env, napi_callback_info info)
   {
      // The service logic of the caller in the main thread is omitted here.
      // ...
      
      // Simulate the caller to obtain the shared object in napi_sendable_ref on another ArkTS thread.
      std::thread t1([]() {
         napi_env newEnv = nullptr;
         ASSERT_CHECK_CALL(napi_create_ark_runtime(&newEnv));
         napi_handle_scope scope = nullptr;
         ASSERT_CHECK_CALL(napi_open_handle_scope(newEnv, &scope));
         if (!sRef) {
            std::abort();
         }
         napi_value sObj = nullptr;
         ASSERT_CHECK_CALL(napi_get_strong_sendable_reference_value(newEnv, sRef, &sObj));
         
         // Verify the sObj content.
         napi_value numValue = nullptr;
         ASSERT_CHECK_CALL(napi_get_named_property(newEnv, sObj, "num", &numValue));
         int32_t num = 0;
         ASSERT_CHECK_CALL(napi_get_value_int32(newEnv, numValue, &num));
         ASSERT_EQ(num, 1111);
         
         // Modify the sObj content.
         napi_value newNum = nullptr;
         ASSERT_CHECK_CALL(napi_create_int32(newEnv, num * 2, &newNum));
         ASSERT_CHECK_CALL(napi_set_named_property(newEnv, sObj, "num", newNum));
         ASSERT_CHECK_CALL(napi_close_handle_scope(newEnv, scope));
         ASSERT_CHECK_CALL(napi_destroy_ark_runtime(&newEnv));
      });
      t1.join();

      napi_value str = nullptr;
      ASSERT_CHECK_CALL(napi_create_string_utf8(env, "success", NAPI_AUTO_LENGTH, &str));
      return str;
   }

   static napi_value GetSendableRefValueInWorkerOrTaskpool(napi_env env, napi_callback_info info)
   {
      // The service logic of the caller in the worker/taskpool thread is omitted here.
      // ...

      // Simulate the caller to obtain the shared object in napi_sendable_ref on another worker/taskpool thread.
      if (!sRef) {
         napi_value undefined = nullptr;
         napi_get_undefined(env, &undefined);
         return undefined;
      }
      napi_value sObj = nullptr;
      ASSERT_CHECK_CALL(napi_get_strong_sendable_reference_value(env, sRef, &sObj));

      // Verify the sObj content.
      napi_value numValue = nullptr;
      ASSERT_CHECK_CALL(napi_get_named_property(env, sObj, "num", &numValue));
      int32_t num = 0;
      ASSERT_CHECK_CALL(napi_get_value_int32(env, numValue, &num));
      ASSERT_EQ(num, 1111);

      return sObj;
   }

   static napi_value CheckAndDeleteSendableRef(napi_env env, napi_callback_info info)
   {
      if (!sRef) {
         napi_value undefined = nullptr;
         ASSERT_CHECK_CALL(napi_get_undefined(env, &undefined));
         return undefined;
      }

      // You can also verify and delete the reference in the ArkTS thread. In this example, the main thread is used.
      // Verify the sObj content.
      napi_value sObj = nullptr;
      ASSERT_CHECK_CALL(napi_get_strong_sendable_reference_value(env, sRef, &sObj));
      napi_value numValue = nullptr;
      ASSERT_CHECK_CALL(napi_get_named_property(env, sObj, "num", &numValue));
      int32_t num = 0;
      ASSERT_CHECK_CALL(napi_get_value_int32(env, numValue, &num));
      ASSERT_EQ(num, 2222);

      ASSERT_CHECK_CALL(napi_delete_strong_sendable_reference(env, sRef));
      sRef = nullptr;

      // Delete SendableRef.
      napi_value str = nullptr;
      ASSERT_CHECK_CALL(napi_create_string_utf8(env, "success", NAPI_AUTO_LENGTH, &str));
      return str;
   }

   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
      napi_property_descriptor desc[] = {
         { "createSendableRef", nullptr, CreateSendableRef, nullptr, nullptr, nullptr, napi_default, nullptr },
         { "getAndModifySendableRefValueInArkRuntime", nullptr, GetAndModifySendableRefValueInArkRuntime,
               nullptr,nullptr, nullptr, napi_default, nullptr },
         { "getSendableRefValueInWorkerOrTaskpool", nullptr, GetSendableRefValueInWorkerOrTaskpool,
               nullptr,nullptr, nullptr, napi_default, nullptr },
         { "checkAndDeleteSendableRef", nullptr, CheckAndDeleteSendableRef,
               nullptr, nullptr, nullptr, napi_default, nullptr },
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
      .nm_modname = "entry",
      .nm_priv = ((void*)0),
      .reserved = { 0 },
   };

   extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
   {
      napi_module_register(&demoModule);
   }

   ```

- API declaration

   ```ts
   // index.d.ts
   export const createSendableRef: (a: object) => string;
   export const getAndModifySendableRefValueInArkRuntime: () => string;
   export const getSendableRefValueInWorkerOrTaskpool: () => object;
   export const checkAndDeleteSendableRef: () => string;
   ```

- ArkTS sample code

   ```ts
   // index.ets
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import testNapi from 'libentry.so';
   import { MessageEvents, taskpool, worker} from '@kit.ArkTS'

   const DOMAIN = 0x0000;

   @Sendable
   class SendableClass {
      num: number = 1111;
   }

   @Concurrent
   function TaskpoolFunc(data: string) {
      console.info('testTag, ' + data);
      let sObj = testNapi.getSendableRefValueInWorkerOrTaskpool() as SendableClass;
      sObj.num = 2222;
   }

   async function concurrentFunc() {
      let sObj = new SendableClass();
      hilog.info(DOMAIN, 'testTag', 'Test CreateSendableRef result = %{public}s',
         testNapi.createSendableRef(sObj));
      const task: taskpool.Task = new taskpool.Task(TaskpoolFunc,
         'Please check sendable ref value in taskpool thread');
      await taskpool.execute(task);
      let ret: string = testNapi.checkAndDeleteSendableRef();
      return ret;
   }

   @Entry
   @Component
   struct Index {
      @State TestMsg1: string = 'TestInArkRuntime';
      @State TestMsg2: string = 'TestInWorker';
      @State TestMsg3: string = 'TestInTaskpool';

      build() {
         Row() {
            Column() {
               Button(this.TestMsg1)
                  .fontSize($r('app.float.page_text_font_size'))
                  .fontWeight(FontWeight.Bold)
                  .onClick(() => {
                     let sObj = new SendableClass();
                     hilog.info(DOMAIN, 'testTag', 'Test CreateSendableRef result = %{public}s',
                        testNapi.createSendableRef(sObj));
                     hilog.info(DOMAIN, 'testTag', 'Test GetAndModifySendableRefValue result = %{public}s',
                        testNapi.getAndModifySendableRefValueInArkRuntime());
                     this.TestMsg1 = testNapi.checkAndDeleteSendableRef();
                  })
               Button(this.TestMsg2)
                  .fontSize($r('app.float.page_text_font_size'))
                  .fontWeight(FontWeight.Bold)
                  .onClick(() => {
                     let sObj = new SendableClass();
                     hilog.info(DOMAIN, 'testTag', 'Test CreateSendableRef result = %{public}s',
                     testNapi.createSendableRef(sObj));
                     const worker1: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/Worker.ets');
                     worker1.onmessage = (e: MessageEvents) => {
                        let data: string = e.data;
                        hilog.info(DOMAIN, 'testTag', data);
                        this.TestMsg2 = testNapi.checkAndDeleteSendableRef();
                     }
                     worker1.postMessage('Please check sendable ref value in worker thread');
                  })
               Button(this.TestMsg3)
                  .fontSize($r('app.float.page_text_font_size'))
                  .fontWeight(FontWeight.Bold)
                  .onClick(() => {
                     concurrentFunc().then((ret) => {
                        this.TestMsg3 = ret;
                     });
                  })
            }
            .width('100%')
         }
         .height('100%')
      }
   }
   ```

   ```ts
   // Worker.ets
   import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
   import testNapi from 'libentry.so';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   const DOMAIN = 0x0000;

   @Sendable
   class SendableClass {
      num: number = 1111;
   }

   const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

   /**
   * Defines the event handler to be called when the worker thread receives a message sent by the host thread.
   * The event handler is executed in the worker thread.
   *
   * @param event message data
   */
   workerPort.onmessage = (event: MessageEvents) => {
      let data: string = event.data;
      hilog.info(DOMAIN, 'testTag', data);
      let sObj = testNapi.getSendableRefValueInWorkerOrTaskpool() as SendableClass;
      sObj.num = 2222;
      workerPort.postMessage('Please check sendable ref value and delete ref');
   };

   /**
   * Defines the event handler to be called when the worker receives a message that cannot be deserialized.
   * The event handler is executed in the worker thread.
   *
   * @param event message data
   */
   workerPort.onmessageerror = (event: MessageEvents) => {
   };

   /**
   * Defines the event handler to be called when an exception occurs during worker execution.
   * The event handler is executed in the worker thread.
   *
   * @param event error message
   */
   workerPort.onerror = (event: ErrorEvent) => {
   };
   ```

## Precautions

1. **napi_sendable_ref** can be created only for [Sendable objects](../arkts-utils/arkts-sendable.md#sendable-data-types).

2. **napi_sendable_ref** can be used across ArkTS threads. When performing multithreaded operations, the caller must manage the release timing to avoid issues related to using after release.

3. Within the same process, a maximum of 51200 **napi_sendable_ref** instances can coexist.

4. **napi_sendable_ref** is different from other reference types. Therefore, you cannot forcibly convert **napi_ref** or **napi_strong_ref** to **napi_sendable_ref**. **napi_delete_strong_sendable_reference** and **napi_get_strong_sendable_reference_value** accept only **napi_sendable_ref** created by calling **napi_create_strong_sendable_reference**.

5. When using the **napi_create_strong_sendable_reference**, **napi_get_strong_sendable_reference_value**, and **napi_delete_strong_sendable_reference** APIs, ensure that the input **env** parameter is the ArkTS thread environment object of the current API. Otherwise, [multithreading safety issues](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-ark-runtime-detection#section19357830121120) may occur.