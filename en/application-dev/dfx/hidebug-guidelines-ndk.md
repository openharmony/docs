# Using HiDebug (C/C++)

HiDebug provides APIs for application debugging.

## Available APIs
| API                         | Description                             |
| ------------------------------- | --------------------------------- |
| OH_HiDebug_GetSystemCpuUsage    | Obtains the CPU usage of the system.|
| OH_HiDebug_GetAppCpuUsage       | Obtains the CPU usage of an application.      |
| OH_HiDebug_GetAppThreadCpuUsage | Obtains the CPU usage of all threads of an application.    |
| OH_HiDebug_FreeThreadCpuUsage   | Releases the thread data structure.               |
| OH_HiDebug_GetSystemMemInfo     | Obtains system memory information.               |
| OH_HiDebug_GetAppNativeMemInfo  | Obtains the memory information of an application.     |
| OH_HiDebug_GetAppMemoryLimit    | Obtains the memory limit of an application.     |
| OH_HiDebug_StartAppTraceCapture | Starts application trace collection.              |
| OH_HiDebug_StopAppTraceCapture  | Stops application trace collection.              |
| OH_HiDebug_GetGraphicsMemory    | Obtains the size of the GPU memory.         |

For details about how to use the APIs (such as parameter usage restrictions and value ranges), see [HiDebug](../reference/apis-performance-analysis-kit/_hi_debug.md).

## How to Develop
The following describes how to add a button in the application and click the button to call the HiDebug APIs.

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

2. In the **CMakeLists.txt** file, add the dependencies.

   ```cmake
   # Add libhiappevent_ndk.z.so and libhilog_ndk.z.so (log output). 
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhidebug.so)
   ```

3. Import the dependencies to the **napi_init.cpp** file, and define **LOG_TAG** and the test method.

   The following calls **OH_HiDebug_GetSystemCpuUsage()** and outputs the return value. For details about how to use other APIs, see [HiDebug](../reference/apis-performance-analysis-kit/_hi_debug.md).

   ```c++
   # include "napi/native_api.h"
   # include "hilog/log.h"
   # include "hidebug/hidebug.h"
   
   # undef LOG_TAG
   # define LOG_TAG "testTag"
   
   static napi_value TestHidebugNdk(napi_env env, napi_callback_info info)
   {
       double cpuUsage = OH_HiDebug_GetSystemCpuUsage();
       OH_LOG_INFO(LogType::LOG_APP, "GetSystemCpuUsage: %{public}f", cpuUsage);
       return 0;
   }
   ```

4. Register **TestHidebugNdk** as an ArkTS API.

   In the **napi_init.cpp** file, register **TestHidebugNdk** as an ArkTS API.

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "testHidebugNdk", nullptr, TestHidebugNdk, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

   In the **index.d.ts** file, define the ArkTS API.

   ```typescript
   export const testHidebugNdk: () => void;
   ```

5. In the **Index.ets** file, add a click event to the **Text** component. The sample code is as follows:

   ```ts
   import testNapi from 'libentry.so'
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World'
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(testNapi.testHidebugNdk);// Add a click event to trigger testHidebugNdk().
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

6. Click the **Run** button in DevEco Studio to run the project, and click "Hello world".

7. At the bottom of DevEco Studio, switch to the **Log** tab and set the filter criteria to **testTag**.
   Then, the CPU usage logs obtained using **OH_HiDebug_GetSystemCpuUsage()** are displayed in the window.

   ```Text
   09-10 09:40:26.755 17221-17221/com.example.myapplication I A00000/testTag: GetSystemCpuUsage: 0.083904
   ```

<!--no_check-->