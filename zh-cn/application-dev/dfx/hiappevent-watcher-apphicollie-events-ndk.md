# 订阅任务执行超时事件（C/C++）

## 简介

本文介绍如何使用HiAppEvent提供的C/C++接口订阅任务执行超时事件。接口的详细使用说明（参数限制、取值范围等）请参考[HiAppEvent C API文档](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md)。

## 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher \*watcher) | 添加应用事件观察者，以添加对应用事件的订阅。 |
| int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher \*watcher) | 移除应用事件观察者，以移除对应用事件的订阅。 |

## 开发步骤

### 添加事件观察者

以实现对用户点击按钮触发卡顿场景生成的卡顿事件订阅为例，说明开发步骤。

1. 参考[三方开源库jsoncpp代码仓](https://github.com/open-source-parsers/jsoncpp)README中**Using JsonCpp in your project**介绍的使用方法获取到jsoncpp.cpp、json.h和json-forwards.h三个文件。

2. 新建Native C++工程，并将上述文件导入到新建工程内，目录结构如下：

   ```yml
   entry:
     src:
       main:
         cpp:
           json:
             - json.h
             - json-forwards.h
           types:
             libentry:
               - index.d.ts
           - CMakeLists.txt
           - jsoncpp.cpp
           - napi_init.cpp
         ets:
           entryability:
             - EntryAbility.ets
           pages:
             - Index.ets
   ```

3. 编辑“CMakeLists.txt”文件，添加源文件及动态库。

   ```cmake
   # 新增jsoncpp.cpp(解析订阅事件中的json字符串)源文件
   add_library(entry SHARED napi_init.cpp jsoncpp.cpp)
   # 新增动态库依赖libhiappevent_ndk.z.so、libhilog_ndk.z.so（日志输出）及libohhicollie.so（hicollie检测）
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhicollie.so libhiappevent_ndk.z.so)
   ```

4. 编辑“napi_init.cpp”文件，导入依赖的文件，并定义LOG_TAG。

   ```c++
   #include "napi/native_api.h"
   #include "json/json.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"
   #include <thread>
   #include <unistd.h>
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   ```

5. 订阅系统事件：

   - onReceive类型观察者

   编辑“napi_init.cpp”文件，定义onReceive类型观察者相关函数：

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
                   strcmp(appEventGroups[i].appEventInfos[j].name, EVENT_APP_HICOLLIE) == 0) {
                   Json::Value params;
                   Json::Reader reader(Json::Features::strictMode());
                   Json::FastWriter writer;
                   if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                       auto time = params["time"].asInt64();
                       auto foreground = params["foreground"].asBool();
                       auto bundleVersion = params["bundle_version"].asString();
                       auto processName = params["process_name"].asString();
                       auto pid = params["pid"].asInt();
                       auto uid = params["uid"].asInt();
                       auto uuid = params["uuid"].asString();
                       auto exception = writer.write(params["exception"]);
                       auto hilogSize = params["hilog"].size();
                       auto peerBindSize =  params["peer_binder"].size();
                       auto memory =  writer.write(params["memory"]);
                       auto externalLog = writer.write(params["external_log"]);
                       auto logOverLimit = params["log_over_limit"].asBool();
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}d", foreground);
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.process_name=%{public}s", processName.c_str());
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uuid=%{public}s", uuid.c_str());
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.exception=%{public}s", exception.c_str());
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.hilog.size=%{public}d", hilogSize);
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.peer_binder.size=%{public}d", peerBindSize);
                       OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s", memory.c_str());
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
       // 设置订阅的事件为EVENT_APP_HICOLLIE。
       const char *names[] = {EVENT_APP_HICOLLIE};
       // 开发者订阅感兴趣的事件，此处订阅了系统事件。
       OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
       // 开发者设置已实现的回调函数，观察者接收到事件后回立即触发OnReceive回调。
       OH_HiAppEvent_SetWatcherOnReceive(systemEventWatcher, OnReceive);
       // 使观察者开始监听订阅的事件。
       OH_HiAppEvent_AddWatcher(systemEventWatcher);
       return {};
   }
   ```

   - onTrigger类型观察者

   编辑“napi_init.cpp”文件，定义OnTrigger类型观察者相关函数：

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
               if (domain ==  DOMAIN_OS && name == EVENT_APP_HICOLLIE) {
                   auto time = eventInfo["time"].asInt64();
                   auto foreground = eventInfo["foreground"].asBool();
                   auto bundleVersion = eventInfo["bundle_version"].asString();
                   auto processName = eventInfo["process_name"].asString();
                   auto pid = eventInfo["pid"].asInt();
                   auto uid = eventInfo["uid"].asInt();
                   auto uuid = eventInfo["uuid"].asString();
                   auto exception = writer.write(eventInfo["exception"]);
                   auto hilogSize = eventInfo["hilog"].size();
                   auto peerBindSize =  eventInfo["peer_binder"].size();
                   auto memory =  writer.write(eventInfo["memory"]);
                   auto externalLog = writer.write(eventInfo["external_log"]);
                   auto logOverLimit = eventInfo["log_over_limit"].asBool();
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}d", foreground);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.process_name=%{public}s", processName.c_str());
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uuid=%{public}s", uuid.c_str());
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.exception=%{public}s", exception.c_str());
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.hilog.size=%{public}d", hilogSize);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.peer_binder.size=%{public}d", peerBindSize);
                   OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s", memory.c_str());
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
        // 设置订阅的事件为EVENT_APP_HICOLLIE。
        const char *names[] = {EVENT_APP_HICOLLIE};
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

6. 新增TestHiCollieTimerNdk函数。

   编辑“napi_init.cpp”文件，新增TestHiCollieTimerNdk函数，构造任务执行超时事件：

   ```c++
   // 引入hicollie.h头文件
   #include "hicollie/hicollie.h"
   static napi_value TestHiCollieTimerNdk(napi_env env, napi_callback_info exports)
   {
       // 定义执行任务超时id值
       int id;  
       // 定义任务超时检测参数：超时时间阈值1s，动作级别为生成日志
       HiCollie_SetTimerParam param = {"testTimer", 1, nullptr, nullptr, HiCollie_Flag::HICOLLIE_FLAG_LOG};
       // 设置检测
       HiCollie_ErrorCode errorCode = OH_HiCollie_SetTimer(param, &id);
       if (errorCode == HICOLLIE_SUCCESS) {
           OH_LOG_INFO(LogType::LOG_APP, "Timer Id is %{public}d", id);
           // 构造超时2s
           sleep(2);
           OH_HiCollie_CancelTimer(id);
       }
       return nullptr; 
   }
   ```

7. 将RegisterWatcher及TestHiCollieTimerNdk注册为ArkTS接口。

   编辑“napi_init.cpp”文件，将RegisterWatcher及TestHiCollieTimerNdk注册为ArkTS接口：

   ```c++
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "RegisterWatcher", nullptr, RegisterWatcher, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "TestHiCollieTimerNdk", nullptr, TestHiCollieTimerNdk, nullptr, nullptr, nullptr, napi_default, nullptr },
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

   编辑“index.d.ts”文件，定义ArkTS接口：

   ```typescript
   export const RegisterWatcher: () => void;
   export const TestHiCollieTimerNdk: () => void;
   ```

8. 编辑“EntryAbility.ets”文件，在onCreate()函数中新增接口调用。

   ```typescript
   // 导入依赖模块
   import testNapi from 'libentry.so'
   
   // 在onCreate()函数中新增接口调用
   // 启动时，注册系统事件观察者
   testNapi.RegisterWatcher();
   ```

9. 编辑“Index.ets”文件，新增按钮触发任务执行超时事件。

   ```typescript
   import testNapi from 'libentry.so';
   @Entry
     @Component
     struct Index {
       @State message: string = 'Hello World';
      
       build() {
         Row() {
           Column() {
             Button("TestHiCollieTimerNdk")
               .fontSize(50)
               .fontWeight(FontWeight.Bold)
               .onClick(testNapi.TestHiCollieTimerNdk);  //添加点击事件，触发TestHiCollieTimerNdk方法。
           }
           .width('100%')
         }
         .height('100%')
       }
   }
   ```

10. 点击DevEco Studio界面中的运行按钮，运行应用工程，然后在应用界面中点击按钮“testHiCollieTimerNdk”，触发任务执行超时事件。

### 验证观察者是否订阅到任务执行超时事件

1. 应用工程崩溃退出后再次运行可以在Log窗口看到对系统事件数据的处理日志。

   ```text
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_HICOLLIE
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.params.time=1740993639620
   HiAppEvent eventInfo.params.foreground=1
   HiAppEvent eventInfo.params.bundle_version=1.0.0
   HiAppEvent eventInfo.params.process_name=com.example.myapplication
   HiAppEvent eventInfo.params.pid=26251
   HiAppEvent eventInfo.params.uid=20020172
   HiAppEvent eventInfo.params.uuid=4e5d7d0e18f5d6d84cf4f0c9e80d66d0b646c1cc2343d3595f07abb0d3547feb
   HiAppEvent eventInfo.params.exception={"message":"","name":"APP_HICOLLIE"}
   HiAppEvent eventInfo.params.hilog.size=77
   HiAppEvent eventInfo.params.peer_binder.size=18
   HiAppEvent eventInfo.params.threads.size=28
   HiAppEvent eventInfo.params.memory={"pss":0,"rss":124668,"sys_avail_mem":2220032,"sys_free_mem":526680,"sys_total_mem":11692576,"vss":4238700}
   HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/APP_HICOLLIE_1740993644458_26215.log"]
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
