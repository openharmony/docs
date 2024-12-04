# Transient Task (C/C++)

## When to Use

An application is suspended after it runs in the background for a short period of time. If the application needs to execute a short-time task in the background, for example, saving the status, it can request a transient task to extend the running time in the background.

## Available APIs

The following table lists the common APIs.


| Name| Description|
| -------- | -------- |
| int32_t OH_BackgroundTaskManager_RequestSuspendDelay(const char *reason, TransientTask_Callback callback, TransientTask_DelaySuspendInfo *info); | Requests a transient task.|
| int32_t OH_BackgroundTaskManager_GetRemainingDelayTime(int32_t requestId, int32_t *delayTime); | Obtains the remaining time of a transient task.|
| int32_t OH_BackgroundTaskManager_CancelSuspendDelay(int32_t requestId); | Cancels a transient task.|

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
   export const RequestSuspendDelay: () => number;
   export const GetRemainingDelayTime: () => number;
   export const CancelSuspendDelay: () => number;
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
   }

   ```

### Configuring the Library Dependency

Configure the **CMakeLists.txt** file. Add the required shared library, that is, **libtransient_task.so**, to **target_link_libraries** in the **CMakeLists.txt** file automatically generated by the project.

## How to Test

1. Connect to the device and run the program.

2. Touch the **Request transient task** button. The console prints a log. The following is an example:

   ```
   The return requestId is 1
   ```

3. Touch the **Obtain remaining time** button. The console prints a log. The following is an example:

   ```
   The return requestId is 18000
   ```
4. Touch the **Cancel transient task** button. The console prints a log. The following is an example:

   ```
   The ret is 0
   ```
> **NOTE**
>
>If the **Request transient task** button is touched for more than three consecutive times, an error is reported. For more constraints, see [Transient Task (ArkTS)](transient-task.md#constraints).
