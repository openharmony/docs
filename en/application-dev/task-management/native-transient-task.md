# Transient Task (C/C++)

## When to Use

An application is suspended after it runs in the background for a short period of time. If the application needs to execute a short-time task in the background, for example, saving the status, it can request a transient task to extend the running time in the background.

## Available APIs

The following table lists the common APIs. For details, see [API Reference](../reference/apis-backgroundtasks-kit/capi-transient-task-api-h.md#functions).


| Name| Description|
| -------- | -------- |
| int32_t OH_BackgroundTaskManager_RequestSuspendDelay(const char *reason, TransientTask_Callback callback, TransientTask_DelaySuspendInfo *info); | Requests a transient task.|
| int32_t OH_BackgroundTaskManager_GetRemainingDelayTime(int32_t requestId, int32_t *delayTime); | Obtains the remaining time of a transient task.|
| int32_t OH_BackgroundTaskManager_CancelSuspendDelay(int32_t requestId); | Cancels a transient task.|
| int32_t OH_BackgroundTaskManager_GetTransientTaskInfo(TransientTask_TransientTaskInfo  *transientTaskInfo); | Obtains all information about a transient task, including the remaining quota of the current day.|

## How to Develop

### Encapsulating the Functions and Registering Modules in the napi_init.cpp File

1. Encapsulate the functions.

   ```C
   #include "napi/native_api.h"
   #include "transient_task/transient_task_api.h"

   TransientTask_DelaySuspendInfo delaySuspendInfo;

   static void callback(void)
   {
      // The transient task is about to end. The service cancels the transient task here.
      OH_BackgroundTaskManager_CancelSuspendDelay(delaySuspendInfo.requestId);
   }

   // Request a transient task.
   static napi_value RequestSuspendDelay(napi_env env, napi_callback_info info)
   {
         napi_value result;
         int32_t res = OH_BackgroundTaskManager_RequestSuspendDelay("test", callback, &delaySuspendInfo);
         if (res == 0) {
            napi_create_int32(env, delaySuspendInfo.requestId, &result);
         } else {
            napi_create_int32(env, -1, &result);
         }
         return result;
   }

   // Obtain the remaining time.
   static napi_value GetRemainingDelayTime(napi_env env, napi_callback_info info)
   {
         napi_value result;
         int32_t delayTime = 0;
         int32_t res = OH_BackgroundTaskManager_GetRemainingDelayTime(delaySuspendInfo.requestId, &delayTime);
         if (res == 0) {
            napi_create_int32(env, delayTime, &result);
         } else {
            napi_create_int32(env, -1, &result);
         }
         return result;
   }

   // Cancel the transient task.
   static napi_value CancelSuspendDelay(napi_env env, napi_callback_info info)
   {
         napi_value result;
         int32_t res = OH_BackgroundTaskManager_CancelSuspendDelay(delaySuspendInfo.requestId);
         napi_create_int32(env, res, &result);
         return result;
   }

   // Obtain all transient task information.
   TransientTask_TransientTaskInfo transientTaskInfo;

   static napi_value GetTransientTaskInfo(napi_env env, napi_callback_info info)
   {
      napi_value result;
      napi_create_object(env, &result);
      int32_t res = OH_BackgroundTaskManager_GetTransientTaskInfo(&transientTaskInfo);
      napi_value napiRemainingQuota = nullptr;
      // The data is successfully obtained. The data is formatted and returned to the API.
      if (res == 0) {
         napi_create_int32(env, transientTaskInfo.remainingQuota, &napiRemainingQuota);
         napi_set_named_property(env, result, "remainingQuota", napiRemainingQuota); // Format the total quota of the current day.
   
         napi_value info {nullptr};
         napi_create_array(env, &info);
         uint32_t count = 0;
         // Format all requested transient task information.
         for (int index = 0; index < 3; index++) {
            if (transientTaskInfo.transientTasks[index].requestId == 0) {
                continue;
            }
            
            napi_value napiWork = nullptr;
            napi_create_object(env, &napiWork);
   
            napi_value napiRequestId = nullptr;
            napi_create_int32(env, transientTaskInfo.transientTasks[index].requestId, &napiRequestId);
            napi_set_named_property(env, napiWork, "requestId", napiRequestId);
   
            napi_value napiActualDelayTime = nullptr;
            napi_create_int32(env, transientTaskInfo.transientTasks[index].actualDelayTime, &napiActualDelayTime);
            napi_set_named_property(env, napiWork, "actualDelayTime", napiActualDelayTime);
   
            napi_set_element(env, info, count, napiWork);
            count++;
         }
         napi_set_named_property(env, result, "transientTasks", info);
      } else {
         napi_create_int32(env, 0, &napiRemainingQuota);
         napi_set_named_property(env, result, "remainingQuota", napiRemainingQuota);
         napi_value info {nullptr};
         napi_create_array(env, &info);
         napi_set_named_property(env, result, "transientTasks", info);
      }
      return result;
   }
   ```

2. Register the functions.

   ```C
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           {"RequestSuspendDelay", nullptr, RequestSuspendDelay, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"GetRemainingDelayTime", nullptr, GetRemainingDelayTime, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"CancelSuspendDelay", nullptr, CancelSuspendDelay, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"GetTransientTaskInfo", nullptr, GetTransientTaskInfo, nullptr, nullptr, nullptr, napi_default, nullptr },
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END
   ```

3. Register the module.

   ```C
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

### Declaring the Functions in the index.d.ts File

   ```ts
   import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';

   export const RequestSuspendDelay: () => number;
   export const GetRemainingDelayTime: () => number;
   export const CancelSuspendDelay: () => number;
   export const GetTransientTaskInfo: () => backgroundTaskManager.TransientTaskInfo;
   ```

### Calling the Functions in the index.ets File

   ```ts
   import testTransientTask from 'libentry.so';

   @Entry
   @Component
   struct Index {
     @State message: string = '';

     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
           Button('Request transient task').onClick(event => {
             this.RequestSuspendDelay();
           })
           Button('Obtain remaining time').onClick(event =>{
             this.GetRemainingDelayTime();
           })
           Button('Cancel transient task').onClick(event =>{
             this.CancelSuspendDelay();
           })
           Button('Obtain all transient task information').onClick(event =>{
             this.GetTransientTaskInfo();
           })
         }
         .width('100%')
        }
       .height('100%')
     }

     RequestSuspendDelay() {
       let requestId = testTransientTask.RequestSuspendDelay();
       console.log("The return requestId is " + requestId);
     }

     GetRemainingDelayTime() {
       let time = testTransientTask.GetRemainingDelayTime();
       console.log("The time is " + time);
     }

     CancelSuspendDelay() {
       let ret = testTransientTask.CancelSuspendDelay();
       console.log("The ret is " + ret);
     }

     GetTransientTaskInfo() {
       let ret = testTransientTask.GetTransientTaskInfo();
       console.log("The ret is " + JSON.stringify(ret));
     }
   }

   ```

### Configuring the Library Dependency

Configure the `CMakeLists.txt` file. Add the required shared library, that is, `libtransient_task.so`, to `target_link_libraries` in the `CMakeLists.txt` file automatically generated by the project.

   ```txt
   target_link_libraries(entry PUBLIC libace_napi.z.so libtransient_task.so)
   ```

## How to Test

1. Connect to the device and run the program.

2. Touch the `Request transient task` button. The console prints a log. The following is an example:

   ```
   The return requestId is 1
   ```

3. Touch the `Obtain remaining time` button. The console prints a log. The following is an example:

   ```
   The return requestId is 18000
   ```
4. Touch the `Cancel transient task` button. The console prints a log. The following is an example:

   ```
   The ret is 0
   ```
5. Touch the `Obtain all transient task information` button. The console prints a log. The following is an example:

   ```
   The ret is {"remainingQuota":600000,"transientTasks":[]}
   ```
> **NOTE**
>
>If the `Request transient task` button is touched for more than three consecutive times, an error is reported. For more constraints, see [Transient Task (ArkTS)](transient-task.md#constraints).
