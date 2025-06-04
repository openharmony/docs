# 使用HiDebug获取调试信息（C/C++）

本模块可用于应用进程的内存、CPU、GPU等相关数据的获取，开启进程trace采集等。由于该模块的接口大多比较耗费性能，接口调用较为耗时，且基于HiDebug模块定义，该模块内的接口仅建议在应用调试，调优阶段使用。若需要在其他场景使用时，请认真评估所需调用的接口对应用性能的影响。

## 接口说明
| 接口名                          | 描述                              |
| ------------------------------- | --------------------------------- |
| OH_HiDebug_GetSystemCpuUsage    | 获取系统的CPU资源占用情况百分比。 |
| OH_HiDebug_GetAppCpuUsage       | 获取进程的CPU使用率百分比。       |
| OH_HiDebug_GetAppThreadCpuUsage | 获取应用所有线程CPU使用情况。     |
| OH_HiDebug_FreeThreadCpuUsage   | 释放线程数据结构。                |
| OH_HiDebug_GetSystemMemInfo     | 获取系统内存信息。                |
| OH_HiDebug_GetAppNativeMemInfo  | 获取应用程序进程的内存信息。      |
| OH_HiDebug_GetAppMemoryLimit    | 获取应用程序进程的内存限制。      |
| OH_HiDebug_StartAppTraceCapture | 启动应用trace采集。               |
| OH_HiDebug_StopAppTraceCapture  | 停止应用trace采集。               |
| OH_HiDebug_GetGraphicsMemory    | 获取应用显存大小。          |
| OH_HiDebug_CreateBacktraceObject    | 创建一个用于栈回溯及栈解析的对象。 </br>**说明**：从API version 20开始，支持该接口。        |
| OH_HiDebug_DestroyBacktraceObject    | 销毁创建的用于栈回溯及栈解析对象。 </br>**说明**：从API version 20开始，支持该接口。        |
| OH_HiDebug_BacktraceFromFp    | 获取从给定的栈帧指针开始的回溯帧。</br>**说明**：从API version 20开始，支持该接口。         |
| OH_HiDebug_SymbolicAddress    | 通过给定的程序计数器（PC）获取详细的符号信息。 </br>**说明**：从API version 20开始，支持该接口。 |

API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[HiDebug](../reference/apis-performance-analysis-kit/_hi_debug.md)。

## 开发步骤

### 使用HiDebug获取系统CPU使用率
下文将展示如何在应用内增加一个按钮，并单击该按钮以调用HiDebug Ndk接口获取系统CPU使用率。

1. 新建Native C++工程，目录结构如下：

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

2. 编辑“CMakeLists.txt”文件，添加库依赖：

   ```cmake
   # 新增动态库依赖libohhidebug.so和libhilog_ndk.z.so（日志输出）
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhidebug.so)
   ```

3. 编辑“napi_init.cpp”文件，导入依赖的文件，并定义LOG_TAG及测试方法：

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

4. 将TestHiDebugNdk注册为ArkTS接口：

   编辑“napi_init.cpp”文件，将TestHiDebugNdk注册为ArkTS接口：

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

   编辑“index.d.ts”文件，定义ArkTS接口：

   ```typescript
   export const testHiDebugNdk: () => void;
   ```

5. 编辑“Index.ets”文件，给文本Text组件添加一个点击事件，示例代码如下：

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
             .onClick(testNapi.testHiDebugNdk);//添加点击事件，触发testHiDebugNdk方法。
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

6. 点击DevEco Studio界面中的运行按钮，运行应用工程，点击“Hello world”文本。

7. 在DevEco Studio的底部，切换到“Log”窗口，设置日志的过滤条件为“testTag”。

   ```Text
   09-10 09:40:26.755 17221-17221/com.example.myapplication I A00000/testTag: GetSystemCpuUsage: 0.083904
   ```

### 使用HiDebug对应用主线程进行栈回溯
1. 新建Native C++工程，并新增文件“test_backtrace.cpp”与“test_backtrace.h”，目录结构如下：

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
2. 编辑“test_backtrace.h”文件如下：
    ```c++
    #ifndef MYAPPLICATION_TESTBACKTRACE_H
    #define MYAPPLICATION_TESTBACKTRACE_H

    void InitSignalHandle();
    void BacktraceFrames();

    #endif //MYAPPLICATION_TESTBACKTRACE_H
    ```
3. 编辑“test_backtrace.cpp”文件如下：

    ```c++
    #include "test_backtrace.h"
    #include <condition_variable>
    #include <csignal>
    #include <unistd.h>
    #include <sys/syscall.h>
    #include "hidebug/hidebug.h"
    #include "hilog/log.h"

    #define MAX_FRAME_SIZE 256 //最大栈回溯深度，应根据业务场景调整该值。

    namespace {
        constexpr auto LOG_PRINT_DOMAIN = 0xFF00;
        std::condition_variable cv_; // 用于控制线程与主线程的逻辑顺序。
        std::mutex mutex_; // 用于控制线程与主线程的逻辑顺序。
        int pcSize = -1;
    }

    class BackTraceObject { // 封装了抓栈过程中需要使用的资源，在使用过程中请注意线程安全和异步信号安全。
    public:
        static BackTraceObject& GetInstance();
        BackTraceObject(const BackTraceObject&) = delete;
        BackTraceObject& operator=(const BackTraceObject&) = delete;
        BackTraceObject(BackTraceObject&&) = delete;
        BackTraceObject& operator=(BackTraceObject&&) = delete;
        bool Init(uint32_t size);
        void Release();
        int BackTraceFromFp(void* startFp, int size); // 该函数异步信号安全。
        void SymbolicAddress(int index); // 该函数较为耗费性能，请避免频繁调用。
        void PrintStackFrame(void* pc, const HiDebug_StackFrame& frame);
    private:
        BackTraceObject() = default;
        ~BackTraceObject() = default;
        HiDebug_Backtrace_Object backtraceObject_ = nullptr;
        void** pcs_ = nullptr;
    };

    BackTraceObject& BackTraceObject::GetInstance() { // 单例模式，用于信号处理函数线程与请求抓栈线程共同访问，以进行数据交互，注意该类非异步信号安全，应在业务逻辑中保证同一时刻仅单个线程在访问该类。
        static BackTraceObject instance;
        return instance;
    }

    bool BackTraceObject::Init(uint32_t size) { // 初始化，申请资源。
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

    void BackTraceObject::Release() { // 释放栈回溯及栈解析的资源。
        OH_HiDebug_DestroyBacktraceObject(backtraceObject_);
        backtraceObject_ = nullptr;
        delete[] pcs_;
        pcs_ = nullptr;
    }

    int BackTraceObject::BackTraceFromFp(void* startFp, int size) { // 根据startFp进行栈回溯，获取pc地址。
        if (size <= MAX_FRAME_SIZE) {
            return OH_HiDebug_BacktraceFromFp(backtraceObject_, startFp, pcs_, size); // OH_HiDebug_BacktraceFromFp接口调用示例。
        }
        return 0;
    }

    void BackTraceObject::PrintStackFrame(void* pc, const HiDebug_StackFrame& frame) { // 用来输出栈内容的函数。
        if (frame.type == HIDEBUG_STACK_FRAME_TYPE_JS) { // 根据栈帧的类型，区分不同的栈帧输出方式。
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

    void BackTraceObject::SymbolicAddress(int index) { // 进行栈解析的接口。
        if (index < 0 || index >= MAX_FRAME_SIZE) {
            return;
        }
        OH_HiDebug_SymbolicAddress(backtraceObject_, pcs_[index], this, [](void* pc, void* arg, const HiDebug_StackFrame* frame) {
            reinterpret_cast<BackTraceObject*>(arg)->PrintStackFrame(pc, *frame);
        }); // 调用OH_HiDebug_SymbolicAddress接口解析栈。
    }
    
    void SignalHandler(int sig, siginfo_t *si, void* context) { // 信号处理函数。
        auto startFp = reinterpret_cast<ucontext_t *>(context)->uc_mcontext.regs[29]; // 读取寄存器X29中存放的fp地址。
        pcSize = BackTraceObject::GetInstance().BackTraceFromFp(reinterpret_cast<void*>(startFp), MAX_FRAME_SIZE); // 该函数异步信号安全，仅异步信号安全函数可在信号处理函数内使用。
        cv_.notify_all(); // 栈回溯结束，通知给请求回栈的线程。
    }

    void InitSignalHandle() { // 注册信号处理函数。
        struct sigaction action{0};
        sigfillset(&action.sa_mask);
        action.sa_sigaction = SignalHandler;
        action.sa_flags = SA_RESTART | SA_SIGINFO | SA_ONSTACK;
        sigaction(SIGUSR1, &action, nullptr); // 注意: 所使用的信号应避免与原有信号冲突。
    }

    void BacktraceFrames() { // 该接口非线程安全，同一时刻仅能使用一个线程进行回栈。
        if (!BackTraceObject::GetInstance().Init(MAX_FRAME_SIZE)) { // 注意：栈回溯前，需申请资源，且不可重复初始化。
            OH_LOG_Print(LOG_APP, LOG_WARN, LOG_PRINT_DOMAIN, "TestTag", "failed init backtrace object.");
            return;
        }
        pcSize = -1; // 初始化pcSize为-1。
        siginfo_t si{0};
        si.si_signo = SIGUSR1;
        if (syscall(SYS_rt_sigqueueinfo, getpid(), si.si_signo, &si) != 0) { // 发送信号给主线程以触发信号处理函数。
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "TestTag", "failed send sig");
        }
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, []{return pcSize >= 0;}); // 等待主线程在信号处理函数内进行栈回溯。
        for (int i = 0; i < pcSize; i++) {
            BackTraceObject::GetInstance().SymbolicAddress(i); // 主线程获取pc后，对pc值进行栈解析。
        }
        BackTraceObject::GetInstance().Release(); // 栈回溯并且解析结束后，及时释放资源。
    }
    ```
4. 编辑“CMakeLists.txt”文件，添加库依赖以及源文件：

   ```cmake
   # 新增动态库依赖libohhidebug.so和libhilog_ndk.z.so（日志输出）
   add_library(entry SHARED napi_init.cpp test_backtrace.cpp)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhidebug.so)
   ```

5. 编辑“napi_init.cpp”文件，导入依赖的文件，并定义LOG_TAG及测试方法：

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
       std::this_thread::sleep_for(std::chrono::seconds(3)); //模拟主线程阻塞。
   }

   __attribute((noinline)) __attribute((optnone)) napi_value TestHiDebugNdk(napi_env env, napi_callback_info info)
   {
       std::thread([]{
           std::this_thread::sleep_for(std::chrono::seconds(1));
           BacktraceFrames();
       }).detach(); // 启用第二个线程，对主线程进行抓栈。
       TestNativeFrames(1); 
       return nullptr;
   }
   ```

6. 将TestHiDebugNdk注册为ArkTS接口：

   编辑“napi_init.cpp”文件，将TestHiDebugNdk注册为ArkTS接口：

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

   编辑“index.d.ts”文件，定义ArkTS接口：

   ```typescript
   export const testHiDebugNdk: () => void;
   ```

7. 编辑“Index.ets”文件，给文本Text组件添加一个点击事件，示例代码如下：

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
             });//添加点击事件，触发testHiDebugNdk方法。
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

8. 点击DevEco Studio界面中的运行按钮，运行应用工程，点击“Hello world”文本。

9. 在DevEco Studio的底部，切换到“Log”窗口，设置日志的过滤条件为“TestTag”。

   此时窗口将显示通过主线程当前调用栈的相关日志，由于回栈时基于LR寄存器（保存的函数返回地址），故无法获取到当前调用函数的栈信息。

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


