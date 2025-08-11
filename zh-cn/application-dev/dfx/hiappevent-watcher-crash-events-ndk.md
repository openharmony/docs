# 订阅崩溃事件（C/C++）
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @chenshi51-->
<!--SE: @Maplestory-->
<!--TSE: @yufeifei-->

## 简介

本文介绍如何使用HiAppEvent提供的C/C++接口订阅应用崩溃事件。详细使用说明请参考[HiAppEvent C API文档](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md)。

> **说明：**
>
> 使用C/C++接口订阅JsError和NativeCrash崩溃事件。

## 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher \*watcher) | 添加应用事件观察者，以添加对应用事件的订阅。 |
| int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher \*watcher) | 移除应用事件观察者，以移除对应用事件的订阅。 |

## 开发步骤

### 添加事件观察者

**在应用启动后，在执行业务逻辑前添加事件观察者，以确保订阅到崩溃事件。否则，应用可能因崩溃而退出，无法订阅崩溃事件。**

以用户点击按钮触发崩溃事件为例，开发步骤如下：

1. 获取示例工程的依赖项jsoncpp。

   参考[三方开源库jsoncpp代码仓](https://github.com/open-source-parsers/jsoncpp)README中**Amalgamated source**部分，获取jsoncpp.cpp、json.h和json-forwards.h三个文件。

2. 新建Native C++工程，并将上述文件导入到新建工程，目录结构如下。

   ```yml
   entry:
     src:
       main:
         cpp:
           - json:
               - json.h
               - json-forwards.h
           - types:
               libentry:
                 - index.d.ts
           - CMakeLists.txt
           - napi_init.cpp
           - jsoncpp.cpp
         ets:
           - entryability:
               - EntryAbility.ets
           - pages:
               - Index.ets
   ```

3. 在"CMakeLists.txt"文件中，添加源文件和动态库。

   ```cmake
   # 新增jsoncpp.cpp(解析订阅事件中的json字符串)源文件
   add_library(entry SHARED napi_init.cpp jsoncpp.cpp)
   # 新增动态库依赖libhiappevent_ndk.z.so和libhilog_ndk.z.so(日志输出)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libhiappevent_ndk.z.so)
   ```

4. 在"napi_init.cpp"文件中，导入依赖文件，并定义LOG_TAG。

   ```c++
   #include "napi/native_api.h"
   #include "json/json.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   ```

5. 订阅系统事件。

   - onReceive类型观察者

      在"napi_init.cpp"文件中，定义onReceive类型观察者的方法：

      ```c++
      //定义一个变量，缓存创建的观察者指针。
      static HiAppEvent_Watcher *systemEventWatcher; 
      
      static void OnReceive(const char *domain, const struct HiAppEvent_AppEventGroup *appEventGroups, uint32_t groupLen) {
          for (int i = 0; i < groupLen; ++i) {
              for (int j = 0; j < appEventGroups[i].infoLen; ++j) {
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s", appEventGroups[i].appEventInfos[j].domain);
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s", appEventGroups[i].appEventInfos[j].name);
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d", appEventGroups[i].appEventInfos[j].type);
                  if (strcmp(appEventGroups[i].appEventInfos[j].domain, DOMAIN_OS) == 0 && 
                      strcmp(appEventGroups[i].appEventInfos[j].name, EVENT_APP_CRASH) == 0) {
                      Json::Value params;
                      Json::Reader reader(Json::Features::strictMode());
                      Json::FastWriter writer;
                      if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                          auto time = params["time"].asInt64();
                          auto crashType = params["crash_type"].asString();
                          auto foreground = params["foreground"].asBool();
                          auto bundleVersion = params["bundle_version"].asString();
                          auto bundleName = params["bundle_name"].asString();
                          auto pid = params["pid"].asInt();
                          auto uid = params["uid"].asInt();
                          auto uuid = params["uuid"].asString();
                          auto exception = writer.write(params["exception"]);
                          auto hilogSize = params["hilog"].size();
                          auto externalLog = writer.write(params["external_log"]);
                          auto logOverLimit = params["log_over_limit"].asBool();
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.crash_type=%{public}s", crashType.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}d", foreground);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", bundleName.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uuid=%{public}s", uuid.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.exception=%{public}s", exception.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.hilog.size=%{public}d", hilogSize);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", externalLog.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}d", logOverLimit);
                      }
                  }
              }
          }
      }
      
      static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
          // 开发者自定义观察者名称，系统根据名称识别不同的观察者。
          systemEventWatcher = OH_HiAppEvent_CreateWatcher("onReceiverWatcher");
          // 订阅的事件为EVENT_APP_CRASH。
          const char *names[] = {EVENT_APP_CRASH};
          // 此处开发者订阅了系统事件EVENT_APP_CRASH。
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
          // 开发者通过调用OH_HiAppEvent_SetWatcherOnReceive函数设置已实现的回调函数，观察者接收到事件后会触发OnReceive回调。
          OH_HiAppEvent_SetWatcherOnReceive(systemEventWatcher, OnReceive);
          // 启动观察者以监听事件。
          OH_HiAppEvent_AddWatcher(systemEventWatcher);
          return {};
      }
      ```

   - onTrigger类型观察者

      在"napi_init.cpp"文件中，定义OnTrigger类型观察者：

      ```c++
      //定义一个变量，用来缓存创建的观察者指针。
      static HiAppEvent_Watcher *systemEventWatcher;
      
      // 开发者需要实现一个回调函数`OnTake`来获取已监听事件，其中`events`指针仅在该函数内有效。
      static void OnTake(const char *const *events, uint32_t eventLen) {
          Json::Reader reader(Json::Features::strictMode());
          Json::FastWriter writer;
          for (int i = 0; i < eventLen; ++i) {
              Json::Value eventInfo;
              if (reader.parse(events[i], eventInfo)) {
                  auto domain =  eventInfo["domain_"].asString();
                  auto name = eventInfo["name_"].asString();
                  auto type = eventInfo["type_"].asInt();
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s", domain.c_str());
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s", name.c_str());
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d", type);
                  if (domain ==  DOMAIN_OS && name == EVENT_APP_CRASH) {
                      auto time = eventInfo["time"].asInt64();
                      auto crashType = eventInfo["crash_type"].asString();
                      auto foreground = eventInfo["foreground"].asBool();
                      auto bundleVersion = eventInfo["bundle_version"].asString();
                      auto bundleName = eventInfo["bundle_name"].asString();
                      auto pid = eventInfo["pid"].asInt();
                      auto uid = eventInfo["uid"].asInt();
                      auto uuid = eventInfo["uuid"].asString();
                      auto exception = writer.write(eventInfo["exception"]);
                      auto hilogSize = eventInfo["hilog"].size();
                      auto externalLog = writer.write(eventInfo["external_log"]);
                      auto logOverLimit = eventInfo["log_over_limit"].asBool();
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.crash_type=%{public}s", crashType.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}d", foreground);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", bundleName.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uuid=%{public}s", uuid.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.exception=%{public}s", exception.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.hilog.size=%{public}d", hilogSize);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", externalLog.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}d", logOverLimit);
                  }
              }
          }
      }
      
      // 开发者应实现订阅回调函数，用以对获取的事件打点数据进行自定义处理。
      static void OnTrigger(int row, int size) {
          // 接收回调后，获取指定数量的事件。
          OH_HiAppEvent_TakeWatcherData(systemEventWatcher, row, OnTake);
      }
      
      static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
          // 开发者自定义观察者名称，系统根据不同的名称来识别不同的观察者。
          systemEventWatcher = OH_HiAppEvent_CreateWatcher("onTriggerWatcher");
          // 设置订阅的事件为EVENT_APP_CRASH。
          const char *names[] = {EVENT_APP_CRASH};
          // 开发者订阅感兴趣的事件，此处订阅了系统事件。
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
          // 开发者设置已实现的回调函数，需OH_HiAppEvent_SetTriggerCondition设置的条件满足方可触发。
          OH_HiAppEvent_SetWatcherOnTrigger(systemEventWatcher, OnTrigger);
          // 设置订阅触发回调的条件：当设置新增事件打点数量为1时，触发onTrigger回调。
          OH_HiAppEvent_SetTriggerCondition(systemEventWatcher, 1, 0, 0);
          // 启动观察者以监听订阅的事件。
          OH_HiAppEvent_AddWatcher(systemEventWatcher);
          return {};
      }
      ```

6. 将RegisterWatcher注册为ArkTS接口。

   在"napi_init.cpp"文件中，将RegisterWatcher注册为ArkTS接口：

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "registerWatcher", nullptr, RegisterWatcher, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

   在"index.d.ts"文件中，定义ArkTS接口：

   ```typescript
   export const registerWatcher: () => void;
   ```

7. 在"EntryAbility.ets"文件的onCreate()函数中添加接口调用。

   ```typescript
   // 导入依赖模块
   import testNapi from 'libentry.so'
   
   // 在onCreate()函数中新增接口调用
   // 启动时，注册系统事件观察者
   testNapi.registerWatcher();
   ```

8. 在"Index.ets"文件中，新增按钮触发崩溃事件。

   ```typescript
   Button("appCrash").onClick(() => {
     JSON.parse("");
   })
   ```

9. 点击运行按钮，启动应用工程。在应用界面中点击“appCrash”按钮，触发崩溃事件。系统生成相应的崩溃日志并进行回调。

> **说明：**
>
> JsError通过进程内采集故障信息触发回调，速度快。NativeCrash采取进程外采集故障信息，平均耗时约2秒，具体受业务线程数量和进程间通信影响。订阅崩溃事件后，故障信息采集完成会异步上报，不阻塞当前业务。

### 验证观察者是否订阅到崩溃事件

在应用未主动捕获崩溃异常和主动捕获崩溃异常的两种场景中，崩溃事件的回调时机不同。开发者需要在每种情况下验证是否订阅到崩溃事件。

**应用未主动捕获崩溃异常场景**

若应用未主动捕获崩溃异常，则系统处理崩溃后应用将退出。**应用下次启动时**，HiAppEvent将崩溃事件上报给已注册的监听，完成回调。

**应用主动捕获崩溃异常场景**

若应用主动捕获崩溃异常，HiAppEvent事件将在**应用退出前**触发回调，例如：

1. 异常处理中未主动退出的应用崩溃后不会退出。

   采用[errorManger.on](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronerror)方法捕获异常会导致JsError类型的崩溃事件在应用退出前触发回调。若应用注册[崩溃信号](cppcrash-guidelines.md#系统处理的崩溃信号)处理函数但未主动退出，会导致NativeCrash类型的崩溃事件在应用退出前触发回调。

2. 异常处理耗时过长，会导致应用退出延迟。

在开发调试阶段，HiAppEvent上报事件完成回调后，可在DevEco Studio的HiLog窗口查看订阅的崩溃事件内容。

```text
HiAppEvent eventInfo.domain=OS
HiAppEvent eventInfo.name=APP_CRASH
HiAppEvent eventInfo.eventType=1
HiAppEvent eventInfo.params.time=1502032265088
HiAppEvent eventInfo.params.crash_type=JsError
HiAppEvent eventInfo.params.foreground=1
HiAppEvent eventInfo.params.bundle_version=1.0.0
HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
HiAppEvent eventInfo.params.pid=19237
HiAppEvent eventInfo.params.uid=20010043
HiAppEvent eventInfo.params.uuid=cc0f062e1b28c1fd2c817fafab5e8ca3207925b4bdd87c43ed23c60029659e01
HiAppEvent eventInfo.params.exception={"message":"Unexpected Text in JSON","name":"SyntaxError","stack":"at anonymous (entry/src/main/ets/pages/Index.ets:16:11)"}
HiAppEvent eventInfo.params.hilog.size=110
HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/APP_CRASH_1502032265211_19237.log"]
HiAppEvent eventInfo.params.log_over_limit=0
```

### 移除并销毁事件观察者

1. 移除事件观察者。

   ```c++
   static napi_value RemoveWatcher(napi_env env, napi_callback_info info) {
       // 使观察者停止监听事件
       OH_HiAppEvent_RemoveWatcher(systemEventWatcher);
       return {};
   }
   ```

2. 销毁事件观察者。

   ```c++
   static napi_value DestroyWatcher(napi_env env, napi_callback_info info) {
       // 销毁创建的观察者，并置systemEventWatcher为nullptr。
       OH_HiAppEvent_DestroyWatcher(systemEventWatcher);
       systemEventWatcher = nullptr;
       return {};
   }
   ```
