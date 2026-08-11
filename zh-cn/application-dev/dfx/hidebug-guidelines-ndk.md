# HiDebug接口使用示例（C/C++）

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @leiguangyu-->
<!--Designer: @mgce1-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

HiDebug C/C++接口功能独立，需要获取调试信息时直接调用。具体调用示例请参考下文。

## 通用开发示例


下文展示如何在应用内使用HiDebug NDK接口以进行线程栈回溯，且获取进程内线程的CPU使用率：

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

   <!-- @[TestHidebugNdk_Backtrace](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/cpp/test_backtrace.h) -->
   
   ``` C
   #ifndef MYAPPLICATION_TESTBACKTRACE_H
   #define MYAPPLICATION_TESTBACKTRACE_H
   
   void BacktraceCurrentThread();
   
   #endif // MYAPPLICATION_TESTBACKTRACE_H
   ```

3. 编辑“test_backtrace.cpp”文件，内容如下：

   <!-- @[TestHidebugNdk_Backtrace](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/cpp/test_backtrace.cpp) -->
   
   ``` C++
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
   
   BackTraceObject& BackTraceObject::GetInstance() // 单例模式，用于信号处理和请求抓栈线程的数据交互。注意该类非异步信号安全，业务逻辑应确保同一时刻仅单个线程访问。
   {
       static BackTraceObject instance;
       return instance;
   }
   
   bool BackTraceObject::Init(uint32_t size) // 初始化资源。
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
   
   void BackTraceObject::Release() // 释放资源。
   {
       OH_HiDebug_DestroyBacktraceObject(backtraceObject_);
       backtraceObject_ = nullptr;
       delete[] pcs_;
       pcs_ = nullptr;
   }
   
   int BackTraceObject::BackTraceFromFp(void* startFp, int size) // 栈回溯获取pc地址。
   {
       if (size <= MAX_FRAME_SIZE) {
           return OH_HiDebug_BacktraceFromFp(backtraceObject_, startFp, pcs_, size); // OH_HiDebug_BacktraceFromFp接口调用示例。
       }
       return 0;
   }
   
   void BackTraceObject::PrintStackFrame(void* pc, const HiDebug_StackFrame& frame) // 输出栈内容。
   {
       if (frame.type == HIDEBUG_STACK_FRAME_TYPE_JS) { // 根据栈帧的类型，区分不同的栈帧输出方式。
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
   
   void BackTraceObject::SymbolicAddress(int index)  // 栈解析接口。
   {
       if (index < 0 || index >= MAX_FRAME_SIZE) {
           return;
       }
       OH_HiDebug_SymbolicAddress(backtraceObject_, pcs_[index], this,
           [] (void* pc, void* arg, const HiDebug_StackFrame* frame) {
               reinterpret_cast<BackTraceObject*>(arg)->PrintStackFrame(pc, *frame);
           }); // 调用OH_HiDebug_SymbolicAddress接口解析栈。
   }
   
   void BacktraceCurrentThread() // 该接口非线程安全，同一时刻只能由一个线程使用。
   {
       if (!BackTraceObject::GetInstance().Init(MAX_FRAME_SIZE)) { // 注意：在调用栈回溯函数之前，需申请资源，且不可重复初始化。
           BackTraceObject::GetInstance().Release();
           OH_LOG_Print(LOG_APP, LOG_WARN, LOG_PRINT_DOMAIN, "testTag", "failed init backtrace object.");
           return;
       }
       int pcSize = BackTraceObject::GetInstance().BackTraceFromFp(__builtin_frame_address(0), MAX_FRAME_SIZE);
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

5. 编辑“napi_init.cpp”文件，导入依赖文件并定义测试方法：

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
           cpuUsage = cpuUsage->next; // 获取下一个线程的cpu使用率对象指针。
       }
       OH_HiDebug_FreeThreadCpuUsage(&cpuUsage); // 释放内存，防止内存泄露。
       return nullptr;
   }
   ```

   注册“TestHiDebugNdk”为ArkTS接口并初始化主线程的信号处理函数：

   <!-- @[TestHidebugNdk_Define](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/cpp/napi_init.cpp) -->
   
   ``` C++
   napi_property_descriptor desc[] = {
       { "testGetThreadCpuUsage", nullptr, TestGetThreadCpuUsage, nullptr, nullptr, nullptr, napi_default, nullptr },
       { "testBackTrace", nullptr, TestBackTrace, nullptr, nullptr, nullptr, napi_default, nullptr },
   };
   ```

6. 编辑“index.d.ts”文件，声明ArkTS接口：
   <!-- @[TestHidebugNdk](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/cpp/types/libentry/Index.d.ts) -->
   
   ``` TypeScript
   export const testGetThreadCpuUsage: () => void;
   export const testBackTrace: () => void;
   ```

7. 编辑“Index.ets”文件，添加触发接口调用的按钮，示例代码如下：

   导入依赖：
   <!-- @[TestHidebugNdk_Import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   import testNapi from 'libentry.so';
   ```
   定义测试方法：
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
   添加按钮以触发接口调用：
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
     // 添加点击事件
     .onClick(testGetThreadCpuUsage);
   
   Button('testHiDebugBackTrace')
     .type(ButtonType.Capsule)
     .margin({
       top: 20
     })
     .backgroundColor('#0D9FFB')
     .width('60%')
     .height('5%')
     // 添加点击事件
     .onClick(testBackTrace);
   ```

步骤二：运行工程

1. 点击DevEco Studio界面中的运行按钮，然后分别单击应用界面上的“testGetThreadCpuUsage”和“testHiDebugBackTrace”按钮。

2. 在DevEco Studio底部切换到“Log”窗口，设置日志过滤条件为“testTag”，即可查看相关日志：

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