# 使用HiCollie检测业务线程卡死卡顿问题（C/C++）
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @rr_cn-->
<!--SE: @peterhuangyu-->
<!--TSE: @gcw_KuLfPSbe-->

## 简介

用户在使用应用时，如果出现点击无反应或应用无响应等情况，并且持续时间超过一定限制，就会被定义为[应用冻屏](appfreeze-guidelines.md)。本文面向开发者介绍HiCollie模块对外提供检测业务线程卡死、卡顿，以及上报卡死事件的能力。

## 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| OH_HiCollie_Init_StuckDetection | 注册应用业务线程卡死的周期性检测任务。用户实现回调函数, 用于定时检测业务线程卡死情况。<br/>默认检测时间：3s上报BUSSINESS_THREAD_BLOCK_3S告警事件，6s上报BUSSINESS_THREAD_BLOCK_6S卡死事件。 |
| OH_HiCollie_Init_StuckDetectionWithTimeout | 注册应用业务线程卡死的周期性检测任务。用户实现回调函数, 用于定时检测业务线程卡死情况。<br/>开发者可以设置卡死检测时间，可设置的时间范围：[3, 15]，单位：s。<br/>说明：从API version 18开始，支持该接口。 |
| OH_HiCollie_Init_JankDetection | 注册应用业务线程卡顿检测的回调函数。<br/>线程卡顿监控功能需要开发者实现两个卡顿检测回调函数，分别放在业务线程处理事件的前后。作为插桩函数，监控业务线程处理事件执行情况。 |
| OH_HiCollie_Report | 上报应用业务线程卡死事件，生成卡死故障日志，辅助定位应用卡死问题。<br/>先调用OH_HiCollie_Init_StuckDetection或OH_HiCollie_Init_StuckDetectionWithTimeout接口，初始化检测的task；<br/>如果task任务超时，结合业务逻辑，调用OH_HiCollie_Report接口上报卡死事件。 |

API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[HiCollie](../reference/apis-performance-analysis-kit/capi-hicollie-h.md)。

## 检测原理

1. 业务线程卡顿OH_HiCollie_Init_JankDetection故障规格，请参考[主线程超时事件检测原理](hiappevent-watcher-mainthreadjank-events.md)。

2. 业务线程卡死故障：
   （1）OH_HiCollie_Init_StuckDetection检测原理：应用的watchdog线程会周期性进行业务线程判活检测。当判活检测超过3s没有被执行，上报BUSSINESS_THREAD_BLOCK_3S线程告警事件；超过6s依然没有被执行，会上报BUSSINESS_THREAD_BLOCK_6S线程卡死事件。两个事件根据系统匹配规则生成appfreeze故障日志。

   （2）OH_HiCollie_Init_StuckDetectionWithTimeout检测原理：应用的watchdog线程会周期性进行业务线程判活检测。当判活检测超过stuckTimeout时间没有被执行，上报BUSSINESS_THREAD_BLOCK_3S告警事件；超过stuckTimeout \* 2时间，依然没有被执行，会上报BUSSINESS_THREAD_BLOCK_6S线程卡死事件。两个事件匹配生成appfreeze故障日志。

## 日志规格

1. 业务线程卡死故障日志以appfreeze-开头，生成在“设备/data/log/faultlog/faultlogger/”路径下。该日志文件名格式为“appfreeze-应用包名-应用UID-秒级时间”。具体规格可参考[应用冻屏（AppFreeze）日志规格](appfreeze-guidelines.md#日志规格)。

2. OH_HiCollie_Init_StuckDetection日志规格，请参考[主线程超时事件日志规格](hiappevent-watcher-mainthreadjank-events.md)。

## 开发步骤

下文将展示如何在应用内增加一个按钮，并单击该按钮以调用HiCollie Ndk接口。

1. 新建Native C++工程，目录结构如下：

   ```yml
   entry:
     src:
       main:
         cpp:
           types:
             libentry:
               - index.d.ts
           - CMakeLists.txt
           - napi_init.cpp
         ets:
           entryability:
             - EntryAbility.ts
           pages:
             - Index.ets
   ```

2. 编辑“CMakeLists.txt”文件，添加源文件及动态库：

   ```cmake
   # 新增动态库依赖libhilog_ndk.z.so(日志输出)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhicollie.so)
   ```

3. 编辑“napi_init.cpp”文件，导入依赖的文件，定义LOG_TAG，下述代码步骤用于模拟卡死卡顿场景，具体使用请结合业务需要。示例代码如下：

   （1）**应用线程卡顿检测**： OH_HiCollie_Init_JankDetection，示例代码如下：

   ```c++
   #include <thread>
   #include <string>
   #include <unistd.h>
   #include <atomic>
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hicollie/hicollie.h"
   
   #undef LOG_TAG
   #define LOG_TAG "JankTest"
   
   //定义两个回调函数对象
   static OH_HiCollie_BeginFunc beginFunc_;
   static OH_HiCollie_EndFunc endFunc_;
   
   //定义监控应用显示开始、结束的回调函数
   void InitBeginFunc(const char* eventName)
   {
       std::string str(eventName);
       OH_LOG_INFO(LogType::LOG_APP, "InitBeginFunc eventName: %{public}s", str.c_str());
   }
   void InitEndFunc(const char* eventName)
   {
       std::string str(eventName);
       OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_EndFunc eventName: %{public}s", str.c_str());
   }
   
   void StartDelayTimer()
   {
     //等待1s
     std::chrono::seconds delay(1);
     OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_JankDetection delay before");
     std::this_thread::sleep_for(delay);
     OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_JankDetection delay after");
   }
   
   //定义子线程回调函数
   void TestJankDetection()
   {
       // 初始化回调函数参数
       beginFunc_ = InitBeginFunc;
       endFunc_ = InitEndFunc;
       HiCollie_DetectionParam param {0};
       // 初始化线程卡顿监控函数
       int initResult = OH_HiCollie_Init_JankDetection(&beginFunc_, &endFunc_, param);
       // 线程启动1s内，不进行检测
       StartDelayTimer();
       // 成功结果：0
       OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_JankDetection: %{public}d", initResult);
       int count = 0;
       while (count < 3) {
           // 设置处理开始回调函数，监控线程任务执行开始时长
           beginFunc_("TestBegin");
           // 休眠350ms，模拟任务线程处理事件卡顿场景
           usleep(350 * 1000);
           // 设置处理结束回调函数，监控线程任务执行结束时长
           endFunc_("TestEnd");
           count++;
       }
   }
   
   static napi_value TestHiCollieJankNdk(napi_env env, napi_callback_info info)
   {
       // 创建子线程
       std::thread threadObj(TestJankDetection);
       // 执行TestJankDetection任务
       threadObj.join();
       return 0;
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "testHiCollieJankNdk", nullptr, TestHiCollieJankNdk, nullptr, nullptr, nullptr, napi_default, nullptr },
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END
   
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

   （2）**应用线程卡死检测**： OH_HiCollie_Init_StuckDetection, 示例代码如下：

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hicollie/hicollie.h"
   #include <thread>
   #include <string>
   #include <unistd.h>
   
   #undef LOG_TAG
   #define LOG_TAG "StruckTest"
   
   // 自定义休眠时间，模拟卡死场景
   const int64_t BLOCK_TIME = 3; 
   // 设置应用线程执行任务情况标志位, true-正常，false-卡死
   std::shared_ptr<std::atomic<bool>> appThreadIsAlive_ = std::make_shared<std::atomic<bool>>(true);
   // 设置上报应用线程卡死事件标志位
   std::shared_ptr<std::atomic<bool>> isSixSecondEvent_ = std::make_shared<std::atomic<bool>>(false);
   
   void ReportEvent() {
       bool temp = isSixSecondEvent_->load();
       int reportResult = OH_HiCollie_Report(&temp);
       // 成功：0
       OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Report: %{public}d, isSixSecondEvent: %{public}d", reportResult, isSixSecondEvent_->load());
       isSixSecondEvent_->store(temp);
   }
   
   void SetTimeout()
   {
     int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::
       system_clock::now().time_since_epoch()).count();
     sleep(BLOCK_TIME);
     int64_t currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::
       system_clock::now().time_since_epoch()).count();
     if (currentTime - now < BLOCK_TIME) {
       appThreadIsAlive_->store(true);
       return;
     }
     appThreadIsAlive_->store(false);
   }
   
   // 开发者可自定义周期性检测任务
   void Timer()
   {
     // 每隔3s检查应用是否正常执行任务
     if (appThreadIsAlive_->load()) {
       OH_LOG_INFO(LogType::LOG_APP, "Check appThread isAlive.");
       // 更新appThreadIsAlive_，正常执行下次检测时为true
       appThreadIsAlive_->store(false);
       // 模拟超时场景
       SetTimeout();
       return;
     }
     ReportEvent();
   }
   
   //定义子线程回调函数
   void InitStuckDetection()
   {
     // 初始化线程卡死监控函数
     int initResult = OH_HiCollie_Init_StuckDetection(Timer);
     // 成功结果：0
     OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_StuckDetection: %{public}d", initResult);
   }
   
   static napi_value TestHiCollieStuckNdk(napi_env env, napi_callback_info info)
   {
     // 创建子线程
     std::thread threadObj(InitStuckDetection);
     // 执行任务
     threadObj.join();
     return 0;
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "testHiCollieStuckNdk", nullptr, TestHiCollieStuckNdk, nullptr, nullptr, nullptr, napi_default, nullptr },
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END
   
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

   （3）**应用线程卡死检测，自定义检测时间**： OH_HiCollie_Init_StuckDetectionWithTimeout，示例代码如下：

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hicollie/hicollie.h"
   #include <thread>
   #include <string>
   #include <unistd.h>
   
   #undef LOG_TAG
   #define LOG_TAG "StruckTest"
   
   // 自定义休眠时间，模拟卡死场景
   const int64_t BLOCK_TIME = 5; 
   // 设置应用线程执行任务情况标志位, true-正常， false-卡死
   std::shared_ptr<std::atomic<bool>> appThreadIsAlive_ = std::make_shared<std::atomic<bool>>(true);
   // 设置上报应用线程卡死事件标志位
   std::shared_ptr<std::atomic<bool>> isSixSecondEvent_ = std::make_shared<std::atomic<bool>>(false);
   
   void ReportEvent() {
       bool temp = isSixSecondEvent_->load();
       int reportResult = OH_HiCollie_Report(&temp);
       // 成功：0
       OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Report: %{public}d, isSixSecondEvent: %{public}d", reportResult, isSixSecondEvent_->load());
       isSixSecondEvent_->store(temp);
   }
   
   void SetTimeout()
   {
     int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::
       system_clock::now().time_since_epoch()).count();
     sleep(BLOCK_TIME);
     int64_t currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::
       system_clock::now().time_since_epoch()).count();
     if (currentTime - now < BLOCK_TIME) {
       appThreadIsAlive_->store(true);
       return;
     }
     appThreadIsAlive_->store(false);
   }
   
   // 开发者可自定义周期性检测任务
   void Timer()
   {
     // 每隔5s检查应用是否正常执行任务
     if (appThreadIsAlive_->load()) {
       OH_LOG_INFO(LogType::LOG_APP, "Check appThread isAlive.");
       // 更新appThreadIsAlive_，正常执行下次检测时为true
       appThreadIsAlive_->store(false);
       // 模拟超时场景
       SetTimeout();
       return;
     }
     ReportEvent();
   }
   
   //定义子线程回调函数
   void InitStuckDetectionWithTimeout()
   {
     // 初始化线程卡死监控函数
     int initResult = OH_HiCollie_Init_StuckDetectionWithTimeout(Timer, BLOCK_TIME);
     // 成功结果：0
     OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_StuckDetection: %{public}d", initResult);
   }
   
   static napi_value TestHiCollieStuckWithTimeoutNdk(napi_env env, napi_callback_info info)
   {
     // 创建子线程
     std::thread threadObj(InitStuckDetectionWithTimeout);
     // 执行任务
     threadObj.join();
     return 0;
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "testHiCollieStuckWithTimeoutNdk", nullptr, TestHiCollieStuckWithTimeoutNdk, nullptr, nullptr, nullptr, napi_default, nullptr },
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END
   
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

4. 将TestHiCollieNdk注册为ArkTS接口。
   （1）OH_HiCollie_Init_JankDetection示例，编辑“index.d.ts”文件，定义ArkTS接口：

   ```typescript
   export const testHiCollieJankNdk: () => void;
   ```

   （2）OH_HiCollie_Init_StuckDetection示例，编辑“index.d.ts”文件，定义ArkTS接口：

   ```typescript
   export const testHiCollieStuckNdk: () => void;
   ```

   （3）OH_HiCollie_Init_StuckDetectionWithTimeout示例，编辑“index.d.ts”文件，定义ArkTS接口：

   ```typescript
   export const testHiCollieStuckWithTimeoutNdk: () => void;
   ```

5. 编辑“Index.ets”文件：

   ```ts
   import testNapi from 'libentry.so'
   
   @Entry
   @Component
   struct Index {
     build() {
       RelativeContainer() {
         Column() {
           //选择下方对应的功能，可在此处添加不同的点击事件
           
         }
         .width('100%')
       }
       .height('100%')
       .width('100%')
     }
   }
   ```

   （1）添加点击事件，触发OH_HiCollie_Init_JankDetection方法。

   ```ts
   Column() {
     Button("testHiCollieJankNdk", { stateEffect:true, type: ButtonType.Capsule})
       .width('75%')
       .height(50)
       .margin(15)
       .fontSize(20)
       .fontWeight(FontWeight.Bold)
       .onClick(testNapi.testHiCollieJankNdk);
   }
   ```

   （2）添加点击事件，触发OH_HiCollie_Init_StuckDetection方法。

   ```ts
   Column() {
     Button("testHiCollieStuckNdk", { stateEffect:true, type: ButtonType.Capsule})
       .width('75%')
       .height(50)
       .margin(15)
       .fontSize(20)
       .fontWeight(FontWeight.Bold)
       .onClick(testNapi.testHiCollieStuckNdk);
   }
   ```

   （3）添加点击事件，触发OH_HiCollie_Init_StuckDetectionWithTimeout方法。

   ```ts
   Column() {
     Button("testHiCollieStuckWithTimeoutNdk", { stateEffect:true, type: ButtonType.Capsule})
       .width('75%')
       .height(50)
       .margin(15)
       .fontSize(20)
       .fontWeight(FontWeight.Bold)
       .onClick(testNapi.testHiCollieStuckWithTimeoutNdk);
   }
   ```

6. 点击DevEco Studio界面中的运行按钮，运行应用工程。

7. 在DevEco Studio的底部，切换到“Log”窗口，过滤自定义的LOG_TAG。
   （1）点击“testHiCollieJankNdk”按钮。

   此时窗口将显示通过OH_HiCollie_Init_JankDetection接口获取的应用业务线程采样栈的超时信息。可以通过订阅hiappevent获取对应的事件，参见[订阅主线程超时事件](hiappevent-watcher-mainthreadjank-events-arkts.md)。

   （2）点击“testHiCollieStuckNdk”按钮。

   此时窗口将显示通过OH_HiCollie_Init_StuckDetection接口，初始化卡死检测回调函数。可以根据实际业务场景，自行定义卡死检测函数。

   （3）点击“testHiCollieStuckWithTimeoutNdk”按钮。

   此时窗口将显示通过OH_HiCollie_Init_StuckDetectionWithTimeout接口，初始化卡死检测回调函数。可以根据实际业务场景，自行定义卡死检测函数，及卡死检测时间。
