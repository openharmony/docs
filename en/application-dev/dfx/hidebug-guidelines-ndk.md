# Using HiDebug APIs (C/C++)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--Designer: @kutcherzhou1-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

The HiDebug C/C++ APIs are independent. You can call them to obtain debugging information. For details, see the following examples.

## How to Develop

The following describes how to call the HiDebug NDK APIs in an application.

Step 1: Create a project

1. Use DevEco Studio to create a project and select **Native C++**.

2. In the **CMakeLists.txt** file, add the dependencies.

   ```cmake
   # Add **libhiappevent_ndk.z.so** and **libhilog_ndk.z.so** (log output).
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhidebug.so)
   ```

3. Import the dependencies to the **napi_init.cpp** file, and define **LOG_TAG** and the test method.

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hidebug/hidebug.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   napi_value TestHiDebugNdk(napi_env env, napi_callback_info info) {    
       // Call the NDK APIs to test.
       return nullptr;
   }
   ```

   Register the test method as an ArkTS API.

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
         {"testHiDebugNdk", nullptr, TestHiDebugNdk, nullptr, nullptr, nullptr, napi_default, nullptr}
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

4. In the **index.d.ts** file, define the ArkTS API.

   ```typescript
   export const testHiDebugNdk: () => void;
   ```

5. In the **Index.ets** file, add a click event to the **Text** component. The sample code is as follows:

   ```typescript
   import testNapi from 'libentry.so';
   
   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         Column() {
           Button("testHiDebugNdk")
             .type(ButtonType.Capsule)
             .margin({
               top: 20
             })
             .backgroundColor('#0D9FFB')
             .width('60%')
             .height('5%')
             // Add a click event.
             .onClick(testNapi.testHiDebugNdk);
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

Step 2: Run the project

Click the **Run** button in DevEco Studio to run the project, and click **testHiDebugNdk** to trigger the calling of the NDK API.

### Obtaining the CPU Usage of a Thread

The data returned by the **OH_HiDebug_GetAppThreadCpuUsage** API is in the linked list structure. After using the data, call **OH_HiDebug_FreeThreadCpuUsage** to reclaim the memory. For details, see the following example.

1. Define the **TestHiDebugNdk** method by referring to [How to Develop](#how-to-develop) and call the APIs in the method.

   ```c++
    static napi_value TestHiDebugNdk(napi_env env, napi_callback_info info)
    {
        HiDebug_ThreadCpuUsagePtr cpuUsage = OH_HiDebug_GetAppThreadCpuUsage();
        if (cpuUsage != nullptr) {
            do {
                OH_LOG_INFO(LogType::LOG_APP, 
                            "GetAppThreadCpuUsage: threadId %{public}d, vssLimit: %{public}f", cpuUsage->threadId, cpuUsage->cpuUsage);
                cpuUsage = cpuUsage->next; // Obtain the CPU usage object pointer of the next thread.
            } while(cpuUsage != nullptr);
            OH_HiDebug_FreeThreadCpuUsage(&cpuUsage); // Release the memory to prevent memory leaks.
        }
        return nullptr;
    }
   ```

2. Trigger the API call and view the console output. The following is an example of the log output:
   ```Text
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15025, vssLimit: 0.000762
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15143, vssLimit: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15144, vssLimit: 0.000055
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15152, vssLimit: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15154, vssLimit: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15155, vssLimit: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15156, vssLimit: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15157, vssLimit: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15158, vssLimit: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15159, vssLimit: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15160, vssLimit: 0.000033
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15161, vssLimit: 0.000077
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15162, vssLimit: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15163, vssLimit: 0.000033
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15171, vssLimit: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15175, vssLimit: 0.000011
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15176, vssLimit: 0.000033
   ```

### Obtaining Stack Information

The following describes how to use HiDebug to perform a main-thread stack backtrace in an application.

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

   ```c++
   #ifndef MYAPPLICATION_TESTBACKTRACE_H
   #define MYAPPLICATION_TESTBACKTRACE_H
   
   void InitSignalHandle();
   void BacktraceFrames();
   
   #endif // MYAPPLICATION_TESTBACKTRACE_H
   ```

3. Edit the **test_backtrace.cpp** file as follows:

   ```c++
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
       std::condition_variable cv_; // Used to control the logical sequence of the thread and main thread.
       std::mutex mutex_; // Used to control the logical sequence of the thread and main thread.
       int pcSize = -1;
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
   
   BackTraceObject& BackTraceObject::GetInstance() { // Singleton used for exchanging data between the signal handler and the thread requesting stack capture. Note that this class is not async-signal-safe; application logic must guarantee single-thread access at any given time.
       static BackTraceObject instance;
       return instance;
   }
   
   bool BackTraceObject::Init(uint32_t size) { // Initialize resources.
       backtraceObject_ = OH_HiDebug_CreateBacktraceObject();
       if (backtraceObject_ == nullptr) {
           return false;
       }
       pcs_  = new (std::nothrow) void*[size]{nullptr};
       if (pcs_ == nullptr) {
           return false;
       }
       return true;
   }
   
   void BackTraceObject::Release() { // Release resources.
       OH_HiDebug_DestroyBacktraceObject(backtraceObject_);
       backtraceObject_ = nullptr;
       delete[] pcs_;
       pcs_ = nullptr;
   }
   
   int BackTraceObject::BackTraceFromFp(void* startFp, int size) { // Perform stack backtracing to obtain the PC address.
       if (size <= MAX_FRAME_SIZE) {
           return OH_HiDebug_BacktraceFromFp(backtraceObject_, startFp, pcs_, size); // Example of calling the OH_HiDebug_BacktraceFromFp API.
       }
       return 0;
   }
   
   void BackTraceObject::PrintStackFrame(void* pc, const HiDebug_StackFrame& frame) { // Output the stack content.
       if (frame.type == HIDEBUG_STACK_FRAME_TYPE_JS) { // Use different stack frame output modes based on the stack frame type.
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "TestTag",
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
               frame.frame.js.packageName
           );
       } else {
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "TestTag",
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
               frame.frame.native.reserved
           );
       }
   }
   
   void BackTraceObject::SymbolicAddress(int index) { // Stack parsing API.
       if (index < 0 || index >= MAX_FRAME_SIZE) {
           return;
       }
       OH_HiDebug_SymbolicAddress(backtraceObject_, pcs_[index], this, [](void* pc, void* arg, const HiDebug_StackFrame* frame) {
           reinterpret_cast<BackTraceObject*>(arg)->PrintStackFrame(pc, *frame);
       }); // Call the OH_HiDebug_SymbolicAddress API to parse the stack.
   }
   
   void SignalHandler(int sig, siginfo_t *si, void* context) { // This function is used to process signals.
       if (sig != SIGUSR1) {
           return;
       }
       auto startFp = reinterpret_cast<ucontext_t *>(context)->uc_mcontext.regs[29]; // Read the fp address stored in register X29.
       std::unique_lock<std::mutex> lock(mutex_);
       pcSize = BackTraceObject::GetInstance().BackTraceFromFp(reinterpret_cast<void*>(startFp), MAX_FRAME_SIZE); // This function is asyn-signal-safe. Only the asyn-signal-safe function can be used in the signal processing function.
       cv_.notify_all(); // Notify the thread that requests stack trace data when the stack back tracing is complete.
   }
   
   void InitSignalHandle() { // Register the signal processing function.
       struct sigaction action{0};
       sigfillset(&action.sa_mask);
       action.sa_sigaction = SignalHandler;
       action.sa_flags = SA_RESTART | SA_SIGINFO | SA_ONSTACK;
       sigaction(SIGUSR1, &action, nullptr); // Ensure that the signal does not conflict with the original signal.
   }
   
   void BacktraceFrames() { // This API is not thread-safe. It can be used by only one thread at a time.
       if (!BackTraceObject::GetInstance().Init(MAX_FRAME_SIZE)) { // Ensure that resources are requested before stack backtracing. Repeated initialization is not allowed.
           BackTraceObject::GetInstance().Release();         
           OH_LOG_Print(LOG_APP, LOG_WARN, LOG_PRINT_DOMAIN, "TestTag", "failed init backtrace object.");
           return;
       }
       pcSize = -1; // Initialize pcSize to -1.
       siginfo_t si{0};
       si.si_signo = SIGUSR1;
       if (syscall(SYS_rt_tgsigqueueinfo, getpid(), getpid(), si.si_signo, &si) != 0) { // Send a signal to the main thread to trigger the signal handling function.
           BackTraceObject::GetInstance().Release();   
           OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "TestTag", "failed send sig");
           return;
       }
       {
           std::unique_lock<std::mutex> lock(mutex_);
           cv_.wait(lock, []{return pcSize >= 0;}); // Wait for the main thread to perform stack back tracing in the signal processing function.
       }
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

5. In the **napi_init.cpp** file, import the dependency files and define the test method.

   ```c++
   #include "napi/native_api.h"
   #include "test_backtrace.h"
   #include <thread>
   
   #include "napi/native_api.h"
   #include "test_backtrace.h"
   
   __attribute((noinline)) __attribute((optnone)) void TestNativeFrames(int i)
   {
       if (i > 0) {
           TestNativeFrames(i - 1);
           return;
       }
       std::this_thread::sleep_for(std::chrono::seconds(3)); // Simulate a main thread block event.
   }
   __attribute((noinline)) __attribute((optnone)) napi_value TestHiDebugNdk(napi_env env, napi_callback_info info)
   {
       std::thread([]{
           std::this_thread::sleep_for(std::chrono::seconds(1));
           BacktraceFrames();
       }).detach (); // Start the second thread to capture the stack of the main thread.
       TestNativeFrames(1); 
       return nullptr;
   }
   ```

   Register **TestHiDebugNdk** as an ArkTS API and initialize the signal handling function of the main thread.

   ```c++
   static napi_value Init(napi_env env, napi_value exports) {
       napi_property_descriptor desc[] = {
           {"testHiDebugNdk", nullptr, TestHiDebugNdk, nullptr, nullptr, nullptr, napi_default, nullptr}};
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       InitSignalHandle(); // Initialize the signal handling function.
       return exports;
   }
   ```

6. In the **index.d.ts** file, declare the ArkTS API.

   ```typescript
   export const testHiDebugNdk: () => void;
   ```

7. In the **Index.ets** file, add a button to trigger the API call. The sample code is as follows:

   ```typescript
   import testNapi from 'libentry.so';
   function testJsFrame(i : number) : void {
     if (i > 0) {
       return testJsFrame(i-1);
     }
     return testNapi.testHiDebugNdk();
   }
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize($r('app.float.page_text_font_size'))
             .fontWeight(FontWeight.Bold)
             .onClick(() => {
               testJsFrame(3);
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

Step 2: Run the project

1. Click the **Run** button in DevEco Studio to run the project, and click "Hello world".

2. At the bottom of DevEco Studio, switch to the **Log** tab and set the filter criteria to **TestTag** to view related logs.

   ```Text
   ...
   05-10 17:26:24.229 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I native stack frame info for pc: 0x5b3e193d24 is relativePc: 0xd3d24 funcOffset: 0x60 mapName: 0x5b3e831880 functionName: std::__n1::this_thread::sleep_for(std::__n1::chrono::duration<long long, std::__n1::ratio<1l, 1000000000l>> const&) buildId: 459a4d9b28503b85a67ca37bda676b03da86e7d6 reserved: (null).
   05-10 17:26:24.229 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I native stack frame info for pc: 0x5b3e208524 is relativePc: 0x8524 funcOffset: 0xbc mapName: 0x5b3e822e30 functionName: void std::__n1::this_thread::sleep_for<long long, std::__n1::ratio<1l, 1l>>(std::n1::chrono::duration<long long, std::n1::ratio<1l, 1l>> const&) buildId: 18a155ee0e687664c5f2c552762efb5ff9ee3724 reserved: (null).
   05-10 17:26:24.229 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I native stack frame info for pc: 0x5b3e208434 is relativePc: 0x8434 funcOffset: 0x68 mapName: 0x5b3e822d10 functionName: TestNativeFrames(int) buildId: 18a155ee0e687664c5f2c552762efb5ff9ee3724 reserved: (null).
   05-10 17:26:24.229 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I native stack frame info for pc: 0x5b3e20840c is relativePc: 0x840c funcOffset: 0x40 mapName: 0x5b3e822ec0 functionName: TestNativeFrames(int) buildId: 18a155ee0e687664c5f2c552762efb5ff9ee3724 reserved: (null).
   05-10 17:26:24.229 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I native stack frame info for pc: 0x5b3e208654 is relativePc: 0x8654 funcOffset: 0xd4 mapName: 0x5b3e822f50 functionName: Add(napi_env*, napi_callback_info*) buildId: 18a155ee0e687664c5f2c552762efb5ff9ee3724 reserved: (null).
   ...
   05-10 17:26:24.234 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I js stack frame info for pc: 0x5a3d773f92 is relativePc: 0x2f92 line: 17 column: 16 mapName: /data/storage/el1/bundle/entry.hap functionName: testJsFrame url: entry|entry|1.0.0|src/main/ets/pages/Index.ts packageName: .
   05-10 17:26:24.235 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I js stack frame info for pc: 0x5a3d773f6c is relativePc: 0x2f6c line: 13 column: 16 mapName: /data/storage/el1/bundle/entry.hap functionName: testJsFrame url: entry|entry|1.0.0|src/main/ets/pages/Index.ts packageName: .
   05-10 17:26:24.235 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I js stack frame info for pc: 0x5a3d773f6c is relativePc: 0x2f6c line: 13 column: 16 mapName: /data/storage/el1/bundle/entry.hap functionName: testJsFrame url: entry|entry|1.0.0|src/main/ets/pages/Index.ts packageName: .
   05-10 17:26:24.235 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I js stack frame info for pc: 0x5a3d773f6c is relativePc: 0x2f6c line: 13 column: 16 mapName: /data/storage/el1/bundle/entry.hap functionName: testJsFrame url: entry|entry|1.0.0|src/main/ets/pages/Index.ts packageName: .
   05-10 17:26:24.235 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I js stack frame info for pc: 0x5a3d7743f0 is relativePc: 0x33f0 line: 69 column: 17 mapName: /data/storage/el1/bundle/entry.hap functionName: anonymous url: entry|entry|1.0.0|src/main/ets/pages/Index.ts packageName: .
   ...
   ```
