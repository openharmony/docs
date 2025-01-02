# 使用HiCollie检测业务线程卡死卡顿问题（C/C++）

HiCollie模块对外提供检测业务线程卡死、卡顿，以及上报卡死事件的能力。

## 接口说明
| 接口名                          | 描述                              |
| ------------------------------- | --------------------------------- |
| OH_HiCollie_Init_StuckDetection | 注册应用业务线程卡死的周期性检测任务。用户实现回调函数, 用于定时检测业务线程卡死情况。          |
| OH_HiCollie_Init_JankDetection | 注册应用业务线程卡顿检测的回调函数。线程卡顿监控功能需要开发者实现两个卡顿检测回调函数, 分别放在业务线程处理事件的前后。作为插桩函数，监控业务线程处理事件执行情况。                 |
| OH_HiCollie_Report | 用于上报应用业务线程卡死事件，生成超时故障日志，辅助定位应用超时问题。结合OH_HiCollie_Init_StuckDetection接口配套使用，先初始化卡死检测，出现卡死时，再上报事件。 |

> **说明：**
>
> 业务线程卡死故障日志是以appfreeze-开头，生成在”设备/data/log/faultlog/faultlogger/”路径下。该日志文件名格式为“appfreeze-应用包名-应用UID-秒级时间”。具体规格可参考：[appfreeze-应用无响应日志分析](./appfreeze-guidelines.md#应用无响应日志分析)。
>
> 业务线程卡顿故障日志规格，可参考：[MAIN_THREAD_JANK-主线程超时事件规格](./hiappevent-watcher-mainthreadjank-events.md#主线程超时事件规格)。


API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[HiCollie](../reference/apis-performance-analysis-kit/_hi_hicollie.md)。

## 开发步骤
下文将展示如何在应用内增加一个按钮，并单击该按钮以调用HiCollie Ndk接口。

1. 新建Native C++工程，并将jsoncpp导入到新建工程内，目录结构如下：

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

2. 编辑"CMakeLists.txt"文件，添加源文件及动态库：

   ```cmake
   # 新增动态库依赖libhilog_ndk.z.so(日志输出)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhicollie.so)
   ```

3. 编辑"napi_init.cpp"文件，导入依赖的文件，并定义LOG_TAG及测试方法：

   ```c++
    #include "napi/native_api.h"
    #include "hilog/log.h"
    #include "hicollie/hicollie.h"
    #include <thread>
    #include <string>
    #include <unistd.h>
    #include <atomic>
    
    #undef LOG_TAG
    #define LOG_TAG "testTag"

    static OH_HiCollie_BeginFunc beginFunc_; //定义回调函数对象
    static OH_HiCollie_EndFunc endFunc_; //定义回调函数对象
    HiCollie_DetectionParam param {.sampleStackTriggerTime = 150,.reserved = 0}; //定义结构体
    int64_t lastWatchTime = 0; // 记录上次卡死检测时间
    const int64_t CHECK_INTERNAL_TIME = 3000; // 设置卡死检测间隔
    std::shared_ptr<std::atomic<bool>> isReport = std::make_shared<std::atomic<bool>>(false); // 设置上报卡死事件标志位
    int count = 0; // 记录第一次初始化
    bool needReport = false; // 根据实际场景，设置是否上报标志

    //定义回调函数
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
    //定义子线程回调函数
    void TestJankDetection()
    {
        beginFunc_ = InitBeginFunc; // 初始化回调函数
        endFunc_ = InitEndFunc;
        int initResult = OH_HiCollie_Init_JankDetection(&beginFunc_, &endFunc_, param); // 初始化线程卡顿监控函数
        OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_JankDetection: %{public}d", initResult); // 成功结果：0
        int count = 0;
        while (count < 2) {
            beginFunc_("TestBegin"); // 设置处理开始回调函数，监控线程任务执行开始时长
            usleep(350 * 1000); // 睡眠350ms，模拟任务线程处理事件卡顿场景
            endFunc_("TestEnd"); // 设置处理结束回调函数，监控线程任务执行结束时长
            count++;
        }
    }

    static napi_value TestHiCollieJankNdk(napi_env env, napi_callback_info info)
    {
        std::thread threadObj(TestJankDetection); // 创建子线程
        threadObj.join(); // 执行回调函数
        return 0;
    }

    int64_t GetCurrentTime()
    {
      return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::
          system_clock::now().time_since_epoch()).count();
    }

    bool ReportEvent()
    {
      if ((GetCurrentTime() - lastWatchTime) > CHECK_INTERNAL_TIME) {
          return true;
      }
      return false;
    }

    void TestTask()
    {
        if (needReport && ReportEvent()) {
          bool temp = isReport->load();
          int reportResult = OH_HiCollie_Report(&temp);
          OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Report: %{public}d", reportResult); // 成功结果：0
          OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Report isReport: %{public}d", temp);
          needReport = false;
        }
        int64_t now = GetCurrentTime();
        if ((now - lastWatchTime) >= (CHECK_INTERNAL_TIME / 2)) {
            lastWatchTime = now;
        }
    }

    //定义子线程回调函数
    void TestStuckDetection()
    {
        int initResult = -1;
        if(count == 0) {
          initResult = OH_HiCollie_Init_StuckDetection(TestTask); // 初始化线程卡死监控函数
          OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_StuckDetection: %{public}d", initResult); // 成功结果：0
          count++;
        }
    }
    static napi_value TestHiCollieStuckNdk(napi_env env, napi_callback_info info)
    {
      std::thread threadObj(TestStuckDetection); // 创建子线程
      threadObj.join(); // 执行回调函数
      return 0;
    }
   ```

4. 将TestHiCollieNdk注册为ArkTS接口：

   编辑"napi_init.cpp"文件，将TestHiCollieNdk注册为ArkTS接口：

   ```c++
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            { "testHiCollieJankNdk", nullptr, TestHiCollieJankNdk, nullptr, nullptr, nullptr, napi_default, nullptr },
            { "testHiCollieStuckNdk", nullptr, TestHiCollieStuckNdk, nullptr, nullptr, nullptr, napi_default, nullptr }};
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
   ```

   编辑"index.d.ts"文件，定义ArkTS接口：

   ```typescript
   export const testHiCollieJankNdk: () => void;
   export const testHiCollieStuckNdk: () => void;
   ```

5. 编辑"Index.ets"文件：

   ```ts
   import testNapi from 'libentry.so'
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World'
   
     build() {
       Row() {
         Column() {
           Button("testHiCollieJankNdk")
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(testNapi.testHiCollieJankNdk);//添加点击事件，触发testHiCollieJankNdk方法。
           Button("testHiCollieStuckNdk")
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(testNapi.testHiCollieStuckNdk);//添加点击事件，触发testHiCollieStuckNdk方法。
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

6. 点击DevEco Studio界面中的运行按钮，运行应用工程。

7. 在DevEco Studio的底部，切换到“Log”窗口，设置日志的过滤条件为“testTag”。

    （1）等待10s，再点击"testHiCollieJankNdk"按钮（线程启动10s内，不进行卡顿检测）。
      此时窗口将显示通过OH_HiCollie_Init_JankDetection接口获取的应用业务线程采样栈的超时信息。
      生成栈文件目录地址：/data/app/el2/100/log/应用bundle name/watchdog/BUSSINESS_THREAD_JANK_XXX.txt。

    （2）点击"testHiCollieStuckNdk"按钮。
      此时窗口将显示通过OH_HiCollie_Init_StuckDetection接口，初始化卡死检测回调函数。可以根据实际业务场景，自行定义卡死检测函数。
