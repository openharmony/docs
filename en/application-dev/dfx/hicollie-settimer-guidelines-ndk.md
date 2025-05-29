# Using HiCollie to Monitor the Function Execution Time (C/C++)

HiCollie provides APIs for detecting the function execution timeout events.

## Available APIs

| API                         | Description                             |
| ------------------------------  | --------------------------------- |
| OH_HiCollie_SetTimer | Enables a timer for checking the function execution duration. Use this function before calling a time-consuming function or code block.         |
| OH_HiCollie_CancelTimer | Cancels a timer for checking the function execution duration. Use this function after calling a time-consuming function or code block.      |

> **NOTE**
>
> You can obtain the function execution timeout log in the following paths:
> 1. The **APP_HICOLLIE-*process ID*-*time*.log** file in **device/data/log/eventlog/**.
> 2. 2. The **syswarning-*bundle name*-*application UID*-*second-level time*** file in **device/data/log/faultlog/faultlogger/**.

For details (such as parameter usage and value ranges), see [HiCollie](../reference/apis-performance-analysis-kit/_hi_collie.md).

## How to Develop

The following describes how to add a button in the application and click the button to call the HiCollie APIs.

1. Create a native C++ project. The directory structure is as follows:

   ```yml
   entry:
     src:
       main:
         cpp:
           - types:
               libentry:
                 - index.d.ts
           - CMakeLists.txt
           - napi_init.cpp
         ets:
           - entryability:
               - EntryAbility.ts
           - pages:
               - Index.ets
   ```

2. In the **CMakeLists.txt** file, add the source file and dynamic libraries.

   ```cmake
   # Add libhilog_ndk.z.so (log output) and libohhicollie.so (HiCollie external APIs).
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhicollie.so)
   ```

3. Import the dependencies to the **napi_init.cpp** file, and define **LOG_TAG** and the test method.

   ```c++
    #include "napi/native_api.h"
    #include "hicollie/hicollie.h"
    #include "hilog/log.h"

    #include <unistd.h>

    #undef LOG_TAG
    #define LOG_TAG "testTag"

    // Define the callback.
    void CallBack(void* callBackParam)
    {
      int* num = reinterpret_cast<int*> (callBackParam);
      OH_LOG_INFO(LogType::LOG_APP, "HiCollieTimerNdk callBackParam: %{public}d", *num);  // Print logs in the callback.
      delete num;
    }

    static napi_value TestHiCollieTimerNdk(napi_env env, napi_callback_info info)
    {
      int id;
      int* callBackParam = new int(2024);
      HiCollie_SetTimerParam param = {"testTimer", 1, CallBack, callBackParam, HiCollie_Flag::HICOLLIE_FLAG_LOG};  // Set HiCollieTimer parameters (timer name, timeout interval, callback, callback parameters, and behavior after timeout).
      HiCollie_ErrorCode errorCode = OH_HiCollie_SetTimer(param, &id);  // Register the HiCollieTimer function to execute a one-off task for timeout detection.
      if (errorCode == HICOLLIE_SUCCESS) {  // The HiCollieTiimer task is successfully registered.
        OH_LOG_INFO(LogType::LOG_APP, "HiCollieTimer taskId: %{public}d", id); // Print the task ID.
        sleep (2); // Simulate the execution of a time-consuming function. Here, the thread is blocked for 2s.
        OH_HiCollie_CancelTimer (id); // Cancel a registered timer based on the ID.
      }
      delete callBackParam;
      return 0;
    }
   ```

4. Register **TestHiCollieTimerNdk** as an ArkTS API.

   In the **napi_init.cpp** file, register **TestHiCollieTimerNdk** as an ArkTS API.

   ```c++
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            { "testHiCollieTimerNdk", nullptr, TestHiCollieTimerNdk, nullptr, nullptr, nullptr, napi_default, nullptr }
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
   ```

   In the **index.d.ts** file, define the ArkTS API.

   ```typescript
   export const testHiCollieTimerNdk: () => void;
   ```

5. Edit the **Index.ets** file.

   ```ts
   import testNapi from 'libentry.so'
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World'
   
     build() {
       Row() {
         Column() {
           Button("testHiCollieTimerNdk")
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(testNapi.testHiCollieTimerNdk);  //Add a click event to trigger the testHiCollieTimerNdk method.
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

6. Click the **Run** button in DevEco Studio to run the project.

7. At the bottom of DevEco Studio, switch to the **Log** tab and set the filter criteria to **testTag**.
   
   Click the **testHiCollieTimerNdk** button to execute the program. In the log window, the task ID is displayed. After 2 seconds, the callback content is displayed.
   
   The timeout logs are stored in: **data/log/eventlog/APP_HICOLLIE-*process ID*-*time*.log** and **syswarning-*bundle name*-*application UID*-*second-level time***.
