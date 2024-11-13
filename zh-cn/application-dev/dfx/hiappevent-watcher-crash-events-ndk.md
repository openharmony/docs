# 订阅崩溃事件（C/C++）

## 接口说明

API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[HiAppEvent](../reference/apis-performance-analysis-kit/_hi_app_event.md#hiappevent)。

> **说明：**
>
> 使用C/C++接口订阅崩溃事件，包含JsError和NativeCrash两种崩溃类型。

**订阅接口功能介绍：**

| 接口名                                                       | 描述                                         |
| ------------------------------------------------------------ | -------------------------------------------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher \*watcher)   | 添加应用事件观察者，以添加对应用事件的订阅。 |
| int OH_HiAppEvent_RemoveWatcher (HiAppEvent_Watcher \*watcher) | 移除应用事件观察者，以移除对应用事件的订阅。 |

## 开发步骤

以实现对用户点击按钮触发崩溃场景生成的崩溃事件订阅为例，说明开发步骤。

1. 新建Native C++工程，并将jsoncpp导入到新建工程内，目录结构如下：

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

2. 编辑"CMakeLists.txt"文件，添加源文件及动态库：

   ```cmake
   # 新增jsoncpp.cpp(解析订阅事件中的json字符串)源文件
   add_library(entry SHARED napi_init.cpp jsoncpp.cpp)
   # 新增动态库依赖libhiappevent_ndk.z.so和libhilog_ndk.z.so(日志输出)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libhiappevent_ndk.z.so)
   ```

3. 编辑"napi_init.cpp"文件，导入依赖的文件，并定义LOG_TAG：

   ```c++
   #include "napi/native_api.h"
   #include "json/json.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   ```

4. 订阅系统事件：

   - onReceive类型观察者：

     编辑"napi_init.cpp"文件，定义onReceive类型观察者相关方法：

     ```c++
     //定义一变量，用来缓存创建的观察者的指针。
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
         // 开发者自定义观察者名称，系统根据不同的名称来识别不同的观察者。
         systemEventWatcher = OH_HiAppEvent_CreateWatcher("onReceiverWatcher");
         // 设置订阅的事件为EVENT_APP_CRASH。
         const char *names[] = {EVENT_APP_CRASH};
         // 开发者订阅感兴趣的事件，此处订阅了系统事件。
         OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
         // 开发者设置已实现的回调函数，观察者接收到事件后回立即触发OnReceive回调。
         OH_HiAppEvent_SetWatcherOnReceive(systemEventWatcher, OnReceive);
         // 使观察者开始监听订阅的事件。
         OH_HiAppEvent_AddWatcher(systemEventWatcher);
         return {};
     }
     ```
     
   - onTrigger类型观察者：

     编辑"napi_init.cpp"文件，定义OnTrigger类型观察者相关方法：

     ```c++
     //定义一变量，用来缓存创建的观察者的指针。
     static HiAppEvent_Watcher *systemEventWatcher;
     
     // 开发者可以自行实现获取已监听到事件的回调函数，其中events指针指向内容仅在该函数内有效。
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
     
     // 开发者可以自行实现订阅回调函数，以便对获取到的事件打点数据进行自定义处理。
     static void OnTrigger(int row, int size) {
         // 接收回调后，获取指定数量的已接收事件。
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
         // 开发者可以设置订阅触发回调的条件，此处是设置新增事件打点数量为1个时，触发onTrigger回调。
         OH_HiAppEvent_SetTriggerCondition(systemEventWatcher, 1, 0, 0);
         // 使观察者开始监听订阅的事件。
         OH_HiAppEvent_AddWatcher(systemEventWatcher);
         return {};
     }
     ```

5. 将RegisterWatcher注册为ArkTS接口：

   编辑"napi_init.cpp"文件，将RegisterWatcher注册为ArkTS接口：

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

   编辑"index.d.ts"文件，定义ArkTS接口：

   ```typescript
   export const registerWatcher: () => void;
   ```

6. 编辑"EntryAbility.ets"文件，在onCreate()函数中新增接口调用：

   ```typescript
   // 导入依赖模块
   import testNapi from 'libentry.so'

   // 在onCreate()函数中新增接口调用
   // 启动时，注册系统事件观察者
   testNapi.registerWatcher();
   ```

7. 编辑"Index.ets"文件，新增按钮触发崩溃事件：

   ```typescript
   Button("appCrash").onClick(() => {
     JSON.parse("");
   })
   ```

8. 点击IDE界面中的运行按钮，运行应用工程，然后在应用界面中点击按钮“appCrash”，触发一次崩溃事件。崩溃事件发生后，系统会根据崩溃类型（JsError或NativeCrash）采用不同的栈回溯方式生成崩溃日志，然后再进行回调。其中NativeCrash栈回溯耗时约2秒，实际耗时与业务线程数量、进程间通信耗时有关。JsError触发进程内栈回溯，NativeCrash触发进程外栈回溯，因此NativeCrash栈回溯会比JsError栈回溯更耗时。用户可以订阅崩溃事件，栈回溯完成后会异步上报，不会阻塞当前业务。

9. 下次应用启动后，HiAppEvent将崩溃事件上报给应用已注册的监听，完成回调。并可以在Log窗口看到对系统事件数据的处理日志：

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

10. 移除事件观察者：

    ```c++
    static napi_value RemoveWatcher(napi_env env, napi_callback_info info) {
        // 使观察者停止监听事件
        OH_HiAppEvent_RemoveWatcher(systemEventWatcher);
        return {};
    }
    ```

11. 销毁事件观察者：

    ```c++
    static napi_value DestroyWatcher(napi_env env, napi_callback_info info) {
        // 销毁创建的观察者，并置systemEventWatcher为nullptr。
        OH_HiAppEvent_DestroyWatcher(systemEventWatcher);
        systemEventWatcher = nullptr;
        return {};
    }
    ```
