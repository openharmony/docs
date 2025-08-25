# HiDebug接口使用示例(C/C++)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--Designer: @kutcherzhou1-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

HiDebug C/C++接口功能独立，需要获取调试信息时直接调用。具体调用示例请参考下文。

## 通用开发示例

下文将展示如何在应用内调用HiDebug Ndk接口：

步骤一：创建项目

1. 使用DevEco Studio新建工程，选择“Native C++”选项。

2. 编辑“CMakeLists.txt”文件，添加库依赖：

   ```cmake
   # 新增动态库依赖libhiappevent_ndk.z.so和libhilog_ndk.z.so(日志输出)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhidebug.so)
   ```

3. 编辑“napi_init.cpp”文件，导入依赖的文件，并定义LOG_TAG及测试方法：

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hidebug/hidebug.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   napi_value TestHiDebugNdk(napi_env env, napi_callback_info info) {    
       // todo 调用需测试的Ndk接口
       return nullptr;
   }
   ```

   将测试方法注册为ArkTS接口：

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

4. 编辑“index.d.ts”文件，定义ArkTS接口：

   ```typescript
   export const testHiDebugNdk: () => void;
   ```

5. 编辑“Index.ets”文件，为Text组件添加点击事件。示例代码如下：

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
             // 添加点击事件
             .onClick(testNapi.testHiDebugNdk);
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

步骤二：运行工程

点击DevEco Studio界面中的运行按钮，运行应用工程，然后点击“testHiDebugNdk”触发NDK接口调用。

### 获取线程CPU使用率

OH_HiDebug_GetAppThreadCpuUsage接口返回的数据为链表结构。使用完毕后，需通过OH_HiDebug_FreeThreadCpuUsage接口回收内存。详情请参考如下示例。

1. 参考[通用开发示例](#通用开发示例)，并定义“TestHiDebugNdk”方法，在该方法中调用接口：

   ```c++
    static napi_value TestHiDebugNdk(napi_env env, napi_callback_info info)
    {
        HiDebug_ThreadCpuUsagePtr cpuUsage = OH_HiDebug_GetAppThreadCpuUsage();
        if (cpuUsage != nullptr) {
            do {
                OH_LOG_INFO(LogType::LOG_APP, 
                            "GetAppThreadCpuUsage: threadId %{public}d, cpuUsage: %{public}f", cpuUsage->threadId, cpuUsage->cpuUsage);
                cpuUsage = cpuUsage->next; // 获取下一个线程的cpu使用率对象指针。
            } while(cpuUsage != nullptr);
            OH_HiDebug_FreeThreadCpuUsage(&cpuUsage); // 释放内存，防止内存泄露。
        }
        return nullptr;
    }
   ```

2. 触发接口调用并查看控制台输出，日志输出示例如下：
   ```Text
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15025, cpuUsage: 0.000762
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15143, cpuUsage: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15144, cpuUsage: 0.000055
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15152, cpuUsage: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15154, cpuUsage: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15155, cpuUsage: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15156, cpuUsage: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15157, cpuUsage: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15158, cpuUsage: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15159, cpuUsage: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15160, cpuUsage: 0.000033
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15161, cpuUsage: 0.000077
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15162, cpuUsage: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15163, cpuUsage: 0.000033
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15171, cpuUsage: 0.000000
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15175, cpuUsage: 0.000011
    06-04 15:18:27.585   15025-15025   A00000/com.exa...ation/testTag  com.examp...lication  I     GetAppThreadCpuUsage: threadId 15176, cpuUsage: 0.000033
   ```

### 获取堆栈信息

下文展示如何在应用内使用HiDebug进行主线程栈回溯。

步骤一：创建项目

1. 使用DevEco Studio新建一个Native C++工程，并新增文件“test_backtrace.cpp”与“test_backtrace.h”，目录结构如下：

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

2. 编辑“test_backtrace.h”文件，内容如下：

   ```c++
   #ifndef MYAPPLICATION_TESTBACKTRACE_H
   #define MYAPPLICATION_TESTBACKTRACE_H
   
   void InitSignalHandle();
   void BacktraceFrames();
   
   #endif // MYAPPLICATION_TESTBACKTRACE_H
   ```

3. 编辑“test_backtrace.cpp”文件, 内容如下：

   ```c++
   #include "test_backtrace.h"
   #include <condition_variable>
   #include <csignal>
   #include <unistd.h>
   #include <sys/syscall.h>
   #include "hidebug/hidebug.h"
   #include "hilog/log.h"
   
   #define MAX_FRAME_SIZE 256 // 最大栈回溯深度，应根据业务场景调整该值。
   
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
       void SymbolicAddress(int index); // 该函数耗费性能，请避免频繁调用。
       void PrintStackFrame(void* pc, const HiDebug_StackFrame& frame);
   private:
       BackTraceObject() = default;
       ~BackTraceObject() = default;
       HiDebug_Backtrace_Object backtraceObject_ = nullptr;
       void** pcs_ = nullptr;
   };
   
   BackTraceObject& BackTraceObject::GetInstance() { // 单例模式，用于信号处理和请求抓栈线程的数据交互。注意该类非异步信号安全，业务逻辑应确保同一时刻仅单个线程访问。
       static BackTraceObject instance;
       return instance;
   }
   
   bool BackTraceObject::Init(uint32_t size) { // 初始化资源。
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
   
   void BackTraceObject::Release() { // 释放资源。
       OH_HiDebug_DestroyBacktraceObject(backtraceObject_);
       backtraceObject_ = nullptr;
       delete[] pcs_;
       pcs_ = nullptr;
   }
   
   int BackTraceObject::BackTraceFromFp(void* startFp, int size) { // 栈回溯获取pc地址。
       if (size <= MAX_FRAME_SIZE) {
           return OH_HiDebug_BacktraceFromFp(backtraceObject_, startFp, pcs_, size); // OH_HiDebug_BacktraceFromFp接口调用示例。
       }
       return 0;
   }
   
   void BackTraceObject::PrintStackFrame(void* pc, const HiDebug_StackFrame& frame) { // 输出栈内容。
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
   
   void BackTraceObject::SymbolicAddress(int index) { // 栈解析接口。
       if (index < 0 || index >= MAX_FRAME_SIZE) {
           return;
       }
       OH_HiDebug_SymbolicAddress(backtraceObject_, pcs_[index], this, [](void* pc, void* arg, const HiDebug_StackFrame* frame) {
           reinterpret_cast<BackTraceObject*>(arg)->PrintStackFrame(pc, *frame);
       }); // 调用OH_HiDebug_SymbolicAddress接口解析栈。
   }
   
   void SignalHandler(int sig, siginfo_t *si, void* context) { // 信号处理函数。
       if (sig != SIGUSR1) {
           return;
       }
       auto startFp = reinterpret_cast<ucontext_t *>(context)->uc_mcontext.regs[29]; // 读取寄存器X29中存放的fp地址。
       std::unique_lock<std::mutex> lock(mutex_);
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
   
   void BacktraceFrames() { // 该接口非线程安全，同一时刻只能由一个线程使用。
       if (!BackTraceObject::GetInstance().Init(MAX_FRAME_SIZE)) { // 注意：在调用栈回溯函数之前，需申请资源，且不可重复初始化。
           BackTraceObject::GetInstance().Release();         
           OH_LOG_Print(LOG_APP, LOG_WARN, LOG_PRINT_DOMAIN, "TestTag", "failed init backtrace object.");
           return;
       }
       pcSize = -1; // 初始化pcSize为-1。
       siginfo_t si{0};
       si.si_signo = SIGUSR1;
       if (syscall(SYS_rt_tgsigqueueinfo, getpid(), getpid(), si.si_signo, &si) != 0) { // 发送信号给主线程以触发信号处理函数。
           BackTraceObject::GetInstance().Release();   
           OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "TestTag", "failed send sig");
           return;
       }
       {
           std::unique_lock<std::mutex> lock(mutex_);
           cv_.wait(lock, []{return pcSize >= 0;}); // 等待主线程在信号处理函数内进行栈回溯。
       }
       for (int i = 0; i < pcSize; i++) {
           BackTraceObject::GetInstance().SymbolicAddress(i); // 主线程获取pc后，对pc值进行栈解析。
       }
       BackTraceObject::GetInstance().Release(); // 栈回溯并且解析结束后，及时释放资源。
   }
   ```

4. 编辑“CMakeLists.txt”文件，添加库依赖：

   ```cmake
   # 新增动态库依赖libohhidebug.so和libhilog_ndk.z.so（日志输出）
   add_library(entry SHARED napi_init.cpp test_backtrace.cpp)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhidebug.so)
   ```

5. 编辑“napi_init.cpp”文件，导入依赖文件并定义测试方法。

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

   注册“TestHiDebugNdk”为ArkTS接口并初始化主线程的信号处理函数:

   ```c++
   static napi_value Init(napi_env env, napi_value exports) {
       napi_property_descriptor desc[] = {
           {"testHiDebugNdk", nullptr, TestHiDebugNdk, nullptr, nullptr, nullptr, napi_default, nullptr}};
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       InitSignalHandle(); // 初始化信号处理函数。
       return exports;
   }
   ```

6. 编辑“index.d.ts”文件，声明ArkTS接口：

   ```typescript
   export const testHiDebugNdk: () => void;
   ```

7. 编辑“Index.ets”文件，添加触发接口调用的按钮，示例代码如下：

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

步骤二：运行工程

1. 点击DevEco Studio界面中的运行按钮，然后单击应用界面上的“Hello World”文本。

2. 在DevEco Studio底部切换到“Log”窗口，设置日志过滤条件为“TestTag”，即可查看相关日志：

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