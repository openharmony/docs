# Using HiDebug (C/C++)

This module can be used to obtain memory, CPU, and GPU data of application processes, and enable process trace collection. Since most APIs of this module are both performance-consuming and time-consuming, and are defined based on the HiDebug module, you are advised to use these APIs only during the application debugging and profiling phases. If the APIs are required in other scenarios, evaluate the impact of the APIs on application performance.

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
| OH_HiDebug_CreateBacktraceObject    | Creates an object for stack back tracing and stack parsing.<br>**Note**: This API is supported since API version 20.       |
| OH_HiDebug_DestroyBacktraceObject    | Destroys the object created for stack back tracing and stack parsing.<br>**Note**: This API is supported since API version 20.       |
| OH_HiDebug_BacktraceFromFp    | Obtains the backtrace frame starting from the specified stack frame pointer.<br>**Note**: This API is supported since API version 20.        |
| OH_HiDebug_SymbolicAddress    | Obtains detailed symbol information based on the specified program counter (PC).<br>**Note**: This API is supported since API version 20.|

For details about how to use the APIs (such as parameter usage restrictions and value ranges), see [HiDebug](../reference/apis-performance-analysis-kit/_hi_debug.md).

## How to Develop

### Obtaining the System CPU Usage Using HiDebug
The following describes how to add a button in an application and click the button to call the HiDebug NDK API to obtain the system CPU usage.

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
   # Add libohhidebug.so and libhilog_ndk.z.so (log output).
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhidebug.so)
   ```

3. Import the dependencies to the **napi_init.cpp** file, and define **LOG_TAG** and the test method.

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hidebug/hidebug.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   
   static napi_value TestHiDebugNdk(napi_env env, napi_callback_info info)
   {
       double cpuUsage = OH_HiDebug_GetSystemCpuUsage();
       OH_LOG_INFO(LogType::LOG_APP, "GetSystemCpuUsage: %{public}f", cpuUsage);
       return 0;
   }
   ```

4. Register **TestHiDebugNdk** as an ArkTS API.

   In the **napi_init.cpp** file, register **TestHiDebugNdk** as an ArkTS API.

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "testHiDebugNdk", nullptr, TestHiDebugNdk, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

   In the **index.d.ts** file, define the ArkTS API.

   ```typescript
   export const testHiDebugNdk: () => void;
   ```

5. In the **Index.ets** file, add a click event to the **Text** component. The sample code is as follows:

   ```ts
   import testNapi from 'libentry.so';
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(testNapi.testHiDebugNdk); //Add a click event to trigger testHiDebugNdk().
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

6. Click the **Run** button in DevEco Studio to run the project, and click "Hello world".

7. At the bottom of DevEco Studio, switch to the **Log** tab and set the filter criteria to **testTag**.

   ```Text
   09-10 09:40:26.755 17221-17221/com.example.myapplication I A00000/testTag: GetSystemCpuUsage: 0.083904
   ```

### Performing Stack Back Tracing on the Application Main Thread Using HiDebug
1. Create a native C++ project and add the **test_backtrace.cpp** and **test_backtrace.h** files. The directory structure is as follows:

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
           - test_backtrace.cpp
           - test_backtrace.h
         ets:
           - entryability:
               - EntryAbility.ts
           - pages:
               - Index.ets
   ```
2. Edit the **test_backtrace.h** file as follows:
    ```c++
    #ifndef MYAPPLICATION_TESTBACKTRACE_H
    #define MYAPPLICATION_TESTBACKTRACE_H

    void InitSignalHandle();
    void BacktraceFrames();

    #endif //MYAPPLICATION_TESTBACKTRACE_H
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

    #define MAX_FRAME_SIZE 256 // Maximum stack back tracing depth. You need to adjust the value based on the service scenario.

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
        void SymbolicAddress (int index); // This function is performance-intensive. Do not call it frequently.
        void PrintStackFrame(void* pc, const HiDebug_StackFrame& frame);
    private:
        BackTraceObject() = default;
        ~BackTraceObject() = default;
        HiDebug_Backtrace_Object backtraceObject_ = nullptr;
        void** pcs_ = nullptr;
    };

    BackTraceObject& BackTraceObject::GetInstance () { // Singleton pattern used for shared access by the signal processing thread and the stack capture request thread to exchange data. Note that this class is not async-signal-safe; you should ensure that only one thread accesses this class at a time in the business logic.
        static BackTraceObject instance;
        return instance;
    }

    bool BackTraceObject::Init (uint32_t size) { // Perform initialization and apply for resources.
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

    void BackTraceObject::Release () { // Release stack back tracing and stack parsing resources.
        OH_HiDebug_DestroyBacktraceObject(backtraceObject_);
        backtraceObject_ = nullptr;
        delete[] pcs_;
        pcs_ = nullptr;
    }

    int BackTraceObject::BackTraceFromFp(void* startFp, int size) { // Perform stack back tracing based on startFp to obtain the PC address.
        if (size <= MAX_FRAME_SIZE) {
            return OH_HiDebug_BacktraceFromFp(backtraceObject_, startFp, pcs_, size); // Example of calling the OH_HiDebug_BacktraceFromFp API.
        }
        return 0;
    }

    void BackTraceObject::PrintStackFrame(void* pc, const HiDebug_StackFrame& frame) { // This function is used to output the stack content.
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

    void BackTraceObject::SymbolicAddress(int index) { // This API is used for stack parsing.
        if (index < 0 || index >= MAX_FRAME_SIZE) {
            return;
        }
        OH_HiDebug_SymbolicAddress(backtraceObject_, pcs_[index], this, [](void* pc, void* arg, const HiDebug_StackFrame* frame) {
            reinterpret_cast<BackTraceObject*>(arg)->PrintStackFrame(pc, *frame);
        }); // Call the OH_HiDebug_SymbolicAddress API to parse the stack.
    }
    
    void SignalHandler(int sig, siginfo_t *si, void* context) { // This function is used to process signals.
        auto startFp = reinterpret_cast<ucontext_t *>(context)->uc_mcontext.regs[29]; // Read the fp address stored in register X29.
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

    void BacktraceFrames() { // This API is not thread-safe. It can be called by only one thread at a time.
        if (!BackTraceObject::GetInstance().Init(MAX_FRAME_SIZE)) { // Ensure that resources are requested before stack back tracing and repeat initialization is not allowed.
            OH_LOG_Print(LOG_APP, LOG_WARN, LOG_PRINT_DOMAIN, "TestTag", "failed init backtrace object.");
            return;
        }
        pcSize = -1; // Initialize pcSize to -1.
        siginfo_t si{0};
        si.si_signo = SIGUSR1;
        if (syscall(SYS_rt_sigqueueinfo, getpid(), si.si_signo, &si) != 0) { // Send a signal to the main thread to trigger the signal processing function.
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "TestTag", "failed send sig");
        }
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, []{return pcSize >= 0;}); // Wait for the main thread to perform stack back tracing in the signal processing function.
        for (int i = 0; i < pcSize; i++) {
            BackTraceObject::GetInstance().SymbolicAddress(i); // The main thread parses the value of PC after obtaining it.
        }
        BackTraceObject::GetInstance().Release (); // Release resources in time after stack back tracing and parsing are complete.
    }
    ```
4. In the **CMakeLists.txt** file, add dependencies and source files.

   ```cmake
   # Add libohhidebug.so and libhilog_ndk.z.so (log output).
   add_library(entry SHARED napi_init.cpp test_backtrace.cpp)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhidebug.so)
   ```

5. Import the dependencies to the **napi_init.cpp** file, and define **LOG_TAG** and the test method.

   ```c++
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

6. Register **TestHiDebugNdk** as an ArkTS API.

   In the **napi_init.cpp** file, register **TestHiDebugNdk** as an ArkTS API.

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       InitSignalHandle();
       napi_property_descriptor desc[] = {
           { "testHiDebugNdk", nullptr, TestHiDebugNdk, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

   In the **index.d.ts** file, define the ArkTS API.

   ```typescript
   export const testHiDebugNdk: () => void;
   ```

7. In the **Index.ets** file, add a click event to the **Text** component. The sample code is as follows:

   ```ts
   import testNapi from 'libentry.so';
   function testJsFrame(i : number) : void {
     if (i > 0) {
       testJsFrame(i - 1);
       return;
     }
     testNapi.testHiDebugNdk();
   }

   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';

     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(() => {
                testJsFrame(3);
             });//Add a click event to trigger the **testHiDebugNdk** method.
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

8. Click the **Run** button in DevEco Studio to run the project, and click "Hello world".

9. At the bottom of DevEco Studio, switch to the **Log** tab and set the filter criteria to **TestTag**.

   The logs of the current call stack of the main thread are displayed. Because the stack back tracing is based on the function return addresses saved in the link register (LR), the stack information of the current function cannot be obtained.

   ```Text
    ...
    05-10 17:26:24.229 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I native stack frame info for pc: 0x5b3e193d24 is relativePc: 0xd3d24 funcOffset: 0x60 mapName: /data/storage/el1/bundle/libs/arm64/libc++_shared.so functionName: std::__n1::this_thread::sleep_for(std::__n1::chrono::duration<long long, std::__n1::ratio<1l, 1000000000l>> const&) buildId: 459a4d9b28503b85a67ca37bda676b03da86e7d6 reserved: (null).
    05-10 17:26:24.229 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I native stack frame info for pc: 0x5b3e208524 is relativePc: 0x8524 funcOffset: 0xbc mapName: /data/storage/el1/bundle/libs/arm64/libentry.so functionName: void std::__n1::this_thread::sleep_for<long long, std::__n1::ratio<1l, 1l>>(std::n1::chrono::duration<long long, std::n1::ratio<1l, 1l>> const&) buildId: 18a155ee0e687664c5f2c552762efb5ff9ee3724 reserved: (null).
    05-10 17:26:24.229 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I native stack frame info for pc: 0x5b3e208434 is relativePc: 0x8434 funcOffset: 0x68 mapName: /data/storage/el1/bundle/libs/arm64/libentry.so functionName: TestNativeFrames(int) buildId: 18a155ee0e687664c5f2c552762efb5ff9ee3724 reserved: (null).
    05-10 17:26:24.229 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I native stack frame info for pc: 0x5b3e20840c is relativePc: 0x840c funcOffset: 0x40 mapName: /data/storage/el1/bundle/libs/arm64/libentry.so functionName: TestNativeFrames(int) buildId: 18a155ee0e687664c5f2c552762efb5ff9ee3724 reserved: (null).
    05-10 17:26:24.229 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I native stack frame info for pc: 0x5b3e208654 is relativePc: 0x8654 funcOffset: 0xd4 mapName: /data/storage/el1/bundle/libs/arm64/libentry.so functionName: TestHiDebugNdk(napi_env*, napi_callback_info*) buildId: 18a155ee0e687664c5f2c552762efb5ff9ee3724 reserved: (null).
    ...
    05-10 17:26:24.234 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I js stack frame info for pc: 0x5a3d773f92 is relativePc: 0x2f92 line: 17 column: 16 mapName: /data/storage/el1/bundle/entry.hap functionName: testJsFrame url: entry|entry|1.0.0|src/main/ets/pages/Index.ts packageName: .
    05-10 17:26:24.235 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I js stack frame info for pc: 0x5a3d773f6c is relativePc: 0x2f6c line: 13 column: 16 mapName: /data/storage/el1/bundle/entry.hap functionName: testJsFrame url: entry|entry|1.0.0|src/main/ets/pages/Index.ts packageName: .
    05-10 17:26:24.235 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I js stack frame info for pc: 0x5a3d773f6c is relativePc: 0x2f6c line: 13 column: 16 mapName: /data/storage/el1/bundle/entry.hap functionName: testJsFrame url: entry|entry|1.0.0|src/main/ets/pages/Index.ts packageName: .
    05-10 17:26:24.235 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I js stack frame info for pc: 0x5a3d773f6c is relativePc: 0x2f6c line: 13 column: 16 mapName: /data/storage/el1/bundle/entry.hap functionName: testJsFrame url: entry|entry|1.0.0|src/main/ets/pages/Index.ts packageName: .
    05-10 17:26:24.235 8324-8865 A0FF00/com.exa...ation/TestTag com.examp...lication I js stack frame info for pc: 0x5a3d7743f0 is relativePc: 0x33f0 line: 69 column: 17 mapName: /data/storage/el1/bundle/entry.hap functionName: anonymous url: entry|entry|1.0.0|src/main/ets/pages/Index.ts packageName: .
    ...
   ```
