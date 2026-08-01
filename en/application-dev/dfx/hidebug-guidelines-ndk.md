# Using HiDebug APIs (C/C++)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @leiguangyu-->
<!--Designer: @mgce1-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=44da34c75e0877dd26e067a23f1dc0303066fdbb translatedAt=2026-07-31T01:30:37.918Z pushedAt=2026-07-31T07:06:45.446Z -->

The HiDebug C/C++ APIs are independent. You can call them to obtain debugging information. For details, see the following examples.

## How to Develop

The following demonstrates how to use HiDebug NDK APIs in an app to perform thread stack backtrace and obtain the CPU usage of threads within a process:

Step 1: Create a project

1. Use DevEco Studio to create a native C++ project and add the **test_backtrace.cpp** and **test_backtrace.h** files. The directory structure is as follows:

   ```yml
   entry:
     src:
       main:
         cpp:
           - types:
             - libentry:
               - index.d.ts
           - CMakeLists.txt
           - napi_init.cpp
           - test_backtrace.cpp
           - test_backtrace.h
         ets:
           pages:
             - Index.ets
   ```

2. Edit the **test_backtrace.h** file as follows:

   <!-- @[TestHidebugNdk_Backtrace](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/cpp/test_backtrace.h) -->

   ``` C
   #ifndef MYAPPLICATION_TESTBACKTRACE_H
   #define MYAPPLICATION_TESTBACKTRACE_H
   
   void BacktraceCurrentThread();
   
   #endif // MYAPPLICATION_TESTBACKTRACE_H
   ```

3. Edit the **test_backtrace.cpp** file as follows:

   <!-- @[TestHidebugNdk_Backtrace](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/cpp/test_backtrace.cpp) -->

   ``` C++
   #include "test_backtrace.h"
   #include <condition_variable>
   #include <csignal>
   #include <unistd.h>
   #include <sys/syscall.h>
   #include "hidebug/hidebug.h"
   #include "hilog/log.h"
   
   #define MAX_FRAME_SIZE 256 // Maximum stack backtrace depth. You need to adjust the value based on the service scenario.
   
   namespace {
       constexpr auto LOG_PRINT_DOMAIN = 0xFF00;
   }
   
   class BackTraceObject { // Encapsulate the resources required for capturing stacks. You must ensure thread safety and asynchronous signal safety.
   public:
       static BackTraceObject& GetInstance();
       BackTraceObject(const BackTraceObject&) = delete;
       BackTraceObject& operator=(const BackTraceObject&) = delete;
       BackTraceObject(BackTraceObject&&) = delete;
       BackTraceObject& operator=(BackTraceObject&&) = delete;
       bool Init(uint32_t size);
       void Release();
       int BackTraceFromFp (void* startFp, int size); // This function is async-signal-safe.
       void SymbolicAddress(int index); // This function is performance-intensive. Do not call it frequently.
       void PrintStackFrame(void* pc, const HiDebug_StackFrame& frame);
   private:
       BackTraceObject() = default;
       ~BackTraceObject() = default;
       HiDebug_Backtrace_Object backtraceObject_ = nullptr;
       void** pcs_ = nullptr;
   };
   
   BackTraceObject& BackTraceObject::GetInstance() // Singleton used for exchanging data between the signal handler and the thread requesting stack capture. Note that this class is not async-signal-safe; application logic must guarantee single-thread access at any given time.
   {
       static BackTraceObject instance;
       return instance;
   }
   
   bool BackTraceObject::Init(uint32_t size) // Initialize resources.
   {
       backtraceObject_ = OH_HiDebug_CreateBacktraceObject();
       if (backtraceObject_ == nullptr || size > MAX_FRAME_SIZE) {
           return false;
       }
       pcs_ = new (std::nothrow) void* [size]{nullptr};
       if (pcs_ == nullptr) {
           return false;
       }
       return true;
   }
   
   void BackTraceObject::Release() // Release resources.
   {
       OH_HiDebug_DestroyBacktraceObject(backtraceObject_);
       backtraceObject_ = nullptr;
       delete[] pcs_;
       pcs_ = nullptr;
   }
   
   int BackTraceObject::BackTraceFromFp(void* startFp, int size) // Perform stack backtracing to obtain the PC address.
   {
       if (size <= MAX_FRAME_SIZE) {
           return OH_HiDebug_BacktraceFromFp(backtraceObject_, startFp, pcs_, size); // Example of calling the OH_HiDebug_BacktraceFromFp API.
       }
       return 0;
   }
   
   void BackTraceObject::PrintStackFrame(void* pc, const HiDebug_StackFrame& frame) // Output the stack content.
   {
       if (frame.type == HIDEBUG_STACK_FRAME_TYPE_JS) { // Use different stack frame output modes based on the stack frame type.
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "testTag",
               "js stack frame info for pc: %{public}p is "
               "relativePc: %{public}p "
               "line: %{public}d "
               "column: %{public}d "
               "mapName: %{public}s "
               "functionName: %{public}s "
               "url: %{public}s "
               "packageName: %{public}s.",
               pc,
               reinterpret_cast<void*>(frame.frame.js.relativePc),
               frame.frame.js.line,
               frame.frame.js.column,
               frame.frame.js.mapName,
               frame.frame.js.functionName,
               frame.frame.js.url,
               frame.frame.js.packageName);
       } else {
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "testTag",
               "native stack frame info for pc: %{public}p is "
               "relativePc: %{public}p "
               "funcOffset: %{public}p "
               "mapName: %{public}s "
               "functionName: %{public}s "
               "buildId: %{public}s "
               "reserved: %{public}s.",
               pc,
               reinterpret_cast<void*>(frame.frame.native.relativePc),
               reinterpret_cast<void*>(frame.frame.native.funcOffset),
               frame.frame.native.mapName,
               frame.frame.native.functionName,
               frame.frame.native.buildId,
               frame.frame.native.reserved);
       }
   }
   
   void BackTraceObject::SymbolicAddress(int index)  // Stack parsing API.
   {
       if (index < 0 || index >= MAX_FRAME_SIZE) {
           return;
       }
       OH_HiDebug_SymbolicAddress(backtraceObject_, pcs_[index], this,
           [] (void* pc, void* arg, const HiDebug_StackFrame* frame) {
               reinterpret_cast<BackTraceObject*>(arg)->PrintStackFrame(pc, *frame);
           }); // Call the OH_HiDebug_SymbolicAddress API to parse the stack.
   }
   
   void BacktraceCurrentThread() // This API is not thread-safe. It can be used by only one thread at a time.
   {
       if (!BackTraceObject::GetInstance().Init(MAX_FRAME_SIZE)) { // Ensure that resources are requested before stack backtracing. Repeated initialization is not allowed.
           BackTraceObject::GetInstance().Release();
           OH_LOG_Print(LOG_APP, LOG_WARN, LOG_PRINT_DOMAIN, "testTag", "failed init backtrace object.");
           return;
       }
       int pcSize = BackTraceObject::GetInstance().BackTraceFromFp(__builtin_frame_address(0), MAX_FRAME_SIZE);
       for (int i = 0; i < pcSize; i++) {
           BackTraceObject::GetInstance().SymbolicAddress(i); // The main thread parses the value of PC after obtaining it.
       }
       BackTraceObject::GetInstance().Release (); // Release resources in time after stack back tracing and parsing are complete.
   }
   ```

4. In the **CMakeLists.txt** file, add the dependencies.

   ```cmake
   # Add libohhidebug.so and libhilog_ndk.z.so (log output).
   add_library(entry SHARED napi_init.cpp test_backtrace.cpp)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhidebug.so)
   ```

5. In the **napi_init.cpp** file, import the dependencies and define the test method.

   <!-- @[TestHidebugNdk_Function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   #include <thread>
   #include "hidebug/hidebug.h"
   #include "hilog/log.h"
   #include "test_backtrace.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   
   __attribute((noinline)) __attribute((optnone)) void TestNativeFrames(int i)
   {
       if (i > 0) {
           TestNativeFrames(i - 1);
           return;
       }
       BacktraceCurrentThread();
   }
   
   __attribute((noinline)) __attribute((optnone)) napi_value TestBackTrace(napi_env env, napi_callback_info info)
   {
       TestNativeFrames(1);
       return nullptr;
   }
   
   napi_value TestGetThreadCpuUsage(napi_env env, napi_callback_info info)
   {
       HiDebug_ThreadCpuUsagePtr cpuUsage = OH_HiDebug_GetAppThreadCpuUsage();
       while (cpuUsage != nullptr) {
           OH_LOG_INFO(LogType::LOG_APP,
               "GetAppThreadCpuUsage: threadId %{public}d, cpuUsage: %{public}f", cpuUsage->threadId, cpuUsage->cpuUsage);
           cpuUsage = cpuUsage->next; // Obtain the CPU usage object pointer of the next thread.
       }
       OH_HiDebug_FreeThreadCpuUsage(&cpuUsage); // Release the memory to prevent memory leaks.
       return nullptr;
   }
   ```

   Register **TestHiDebugNdk** as an ArkTS API and initialize the signal handling function of the main thread.

   <!-- @[TestHidebugNdk_Define](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   napi_property_descriptor desc[] = {
       { "testGetThreadCpuUsage", nullptr, TestGetThreadCpuUsage, nullptr, nullptr, nullptr, napi_default, nullptr },
       { "testBackTrace", nullptr, TestBackTrace, nullptr, nullptr, nullptr, napi_default, nullptr },
   };
   ```

6. In the **index.d.ts** file, declare the ArkTS API.

   <!-- @[TestHidebugNdk](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/cpp/types/libentry/Index.d.ts) -->

   ``` TypeScript
   export const testGetThreadCpuUsage: () => void;
   export const testBackTrace: () => void;
   ```

7. In the **Index.ets** file, add a button to trigger the API call. The sample code is as follows:

   Import dependencies.

   <!-- @[TestHidebugNdk_Import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   import testNapi from 'libentry.so';
   ```

   Define the test method.

   <!-- @[TestHidebugNdk_Function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   function testBackTraceJsFrame(i : number) : void {
     if (i > 0) {
       return testBackTraceJsFrame(i-1);
     }
     return testNapi.testBackTrace();
   }
   
   function testBackTrace() : void {
     testBackTraceJsFrame(3);
   }
   
   function testGetThreadCpuUsage() : void {
     testNapi.testGetThreadCpuUsage();
   }
   ```

   Add a button to trigger the API call.

   <!-- @[TestHidebugNdk_Buttons](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   Button('testGetThreadCpuUsage')
     .type(ButtonType.Capsule)
     .margin({
       top: 20
     })
     .backgroundColor('#0D9FFB')
     .width('60%')
     .height('5%')
     // Add a click event.
     .onClick(testGetThreadCpuUsage);
   
   Button('testHiDebugBackTrace')
     .type(ButtonType.Capsule)
     .margin({
       top: 20
     })
     .backgroundColor('#0D9FFB')
     .width('60%')
     .height('5%')
     // Add a click event.
     .onClick(testBackTrace);
   ```

Step 2: Run the project

1. Click the **Run** button in DevEco Studio. Then, click the **testGetThreadCpuUsage** and **testHiDebugBackTrace** buttons.

2. At the bottom of DevEco Studio, switch to the **Log** tab and set the filter criteria to **testTag** to view related logs.

   ```Text
   ...
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19261, cpuUsage: 0.000104
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19381, cpuUsage: 0.000000
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19382, cpuUsage: 0.000040
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19383, cpuUsage: 0.000010
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19384, cpuUsage: 0.000001
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19386, cpuUsage: 0.000038
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19387, cpuUsage: 0.000000
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19388, cpuUsage: 0.000007
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19389, cpuUsage: 0.000004
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19390, cpuUsage: 0.000007
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19391, cpuUsage: 0.000006
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19393, cpuUsage: 0.000001
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19394, cpuUsage: 0.000004
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19397, cpuUsage: 0.000002
   10-22 15:46:05.933   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     GetAppThreadCpuUsage: threadId 19401, cpuUsage: 0.000001
   ...
   10-22 15:46:13.351   19261-19261   A0FF00/com.sam...gtool/testTag  com.sampl...ebugtool  I     native stack frame info for pc: ************ is relativePc: ****** funcOffset: 0x38 mapName: /data/storage/el1/bundle/libs/arm64/libentry.so functionName: TestNativeFrames(int) buildId: b6d3429f6e2e594b1c696e13049dae7e51694099 reserved: (null).
   10-22 15:46:13.351   19261-19261   A0FF00/com.sam...gtool/testTag  com.sampl...ebugtool  I     native stack frame info for pc: ************ is relativePc: ****** funcOffset: 0x30 mapName: /data/storage/el1/bundle/libs/arm64/libentry.so functionName: TestNativeFrames(int) buildId: b6d3429f6e2e594b1c696e13049dae7e51694099 reserved: (null).
   10-22 15:46:13.351   19261-19261   A0FF00/com.sam...gtool/testTag  com.sampl...ebugtool  I     native stack frame info for pc: ************ is relativePc: ****** funcOffset: 0x1c mapName: /data/storage/el1/bundle/libs/arm64/libentry.so functionName: TestBackTrace(napi_env__*, napi_callback_info__*) buildId: b6d3429f6e2e594b1c696e13049dae7e51694099 reserved: (null).
   ...
   10-22 15:46:13.354   19261-19261   A0FF00/com.sam...gtool/testTag  com.sampl...ebugtool  I     js stack frame info for pc: ************ is relativePc: ****** line: 27 column: 21 mapName: /data/storage/el1/bundle/entry.hap functionName: testBackTraceJsFrame url: entry|entry|1.0.0|src/main/ets/pages/Index.ts packageName: .
   10-22 15:46:13.354   19261-19261   A0FF00/com.sam...gtool/testTag  com.sampl...ebugtool  I     js stack frame info for pc: ************ is relativePc: ****** line: 25 column: 16 mapName: /data/storage/el1/bundle/entry.hap functionName: testBackTraceJsFrame url: entry|entry|1.0.0|src/main/ets/pages/Index.ts packageName: .
   10-22 15:46:13.354   19261-19261   A0FF00/com.sam...gtool/testTag  com.sampl...ebugtool  I     js stack frame info for pc: ************ is relativePc: ****** line: 25 column: 16 mapName: /data/storage/el1/bundle/entry.hap functionName: testBackTraceJsFrame url: entry|entry|1.0.0|src/main/ets/pages/Index.ts packageName: .
   10-22 15:46:13.354   19261-19261   A0FF00/com.sam...gtool/testTag  com.sampl...ebugtool  I     js stack frame info for pc: ************ is relativePc: ****** line: 25 column: 16 mapName: /data/storage/el1/bundle/entry.hap functionName: testBackTraceJsFrame url: entry|entry|1.0.0|src/main/ets/pages/Index.ts packageName: ....
   ...
   ```