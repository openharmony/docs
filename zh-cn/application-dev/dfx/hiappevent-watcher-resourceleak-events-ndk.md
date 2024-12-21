# 订阅资源泄漏事件（C/C++）

## 接口说明

API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[HiAppEvent](../reference/apis-performance-analysis-kit/_hi_app_event.md#hiappevent)。

**订阅接口功能介绍：**

| 接口名                                                         | 描述                                         |
|-------------------------------------------------------------| -------------------------------------------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher *watcher)   | 添加应用事件观察者，以添加对应用事件的订阅。 |
| int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher *watcher) | 移除应用事件观察者，以移除对应用事件的订阅。 |

## 开发步骤

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
                      strcmp(appEventGroups[i].appEventInfos[j].name, EVENT_RESOURCE_OVERLIMIT) == 0) {
                      Json::Value params;
                      Json::Reader reader(Json::Features::strictMode());
                      Json::FastWriter writer;
                      if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                          auto time = params["time"].asInt64();
                          auto pid = params["pid"].asInt();
                          auto uid = params["uid"].asInt();
                          auto resourceType = params["resourceType"].asString();
                          auto bundleName = params["bundle_name"].asString();
                          auto bundleVersion = params["bundle_version"].asString();
                          auto memory = writer.write(params["memory"]);
                          auto externalLog = writer.write(eventInfo["external_log"]);
                          std::string logOverLimit = eventInfo["log_over_limit"].asBool() ? "true":"false";
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.resource_type=%{public}s", resourceType.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", bundleName.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s", memory.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", externalLog.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}d", logOverLimit.c_str());
                      }
                  }
              }
          }
      }
      
      static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
          // 开发者自定义观察者名称，系统根据不同的名称来识别不同的观察者。
          systemEventWatcher = OH_HiAppEvent_CreateWatcher("onReceiverWatcher");
          // 设置订阅的事件为EVENT_RESOURCE_OVERLIMIT。
          const char *names[] = {EVENT_RESOURCE_OVERLIMIT};
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
                  if (domain ==  DOMAIN_OS && name == EVENT_RESOURCE_OVERLIMIT) {
                      auto time = eventInfo["time"].asInt64();
                      auto pid = eventInfo["pid"].asInt();
                      auto uid = eventInfo["uid"].asInt();
                      auto resourceType = eventInfo["resourceType"].asString();
                      auto bundleName = eventInfo["bundle_name"].asString();
                      auto bundleVersion = eventInfo["bundle_version"].asString();
                      auto memory = writer.write(eventInfo["memory"]);
                      auto externalLog = writer.write(eventInfo["external_log"]);
                      std::string logOverLimit = eventInfo["log_over_limit"].asBool() ? "true":"false";
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.resource_type=%{public}s", resourceType.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", bundleName.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s", memory.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", externalLog.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}d", logOverLimit.c_str());
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
          // 设置订阅的事件为EVENT_RESOURCE_OVERLIMIT。
          const char *names[] = {EVENT_RESOURCE_OVERLIMIT};
          // 开发者订阅感兴趣的事件，此处订阅了系统事件。
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
          // 开发者设置已实现的回调函数，需OH_HiAppEvent_SetTriggerCondition设置的条件满足方可触发。
          OH_HiAppEvent_SetWatcherOnTrigger(systemEventWatcher, OnTrigger);
          // 开发者可以设置订阅触发回调的条件，此处是设置新增事件打点数量为2个时，触发onTrigger回调。
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
   import testNapi from 'libentry.so'
   import hidebug from '@kit.PerformanceAnalysisKit'
   export default class EntryAbility extends UIAbility {
     onCreate(want, launchParam) {
       // 启动时，注册系统事件观察者
       testNapi.registerWatcher();
     }
   }
   ```

7. 编辑工程中的“entry > src > main > ets  > pages > Index.ets”文件，添加按钮并在其onClick函数构造资源泄漏场景，以触发资源泄漏事件。
   此处需要使用[hidebug.setAppResourceLimit](../reference/apis-performance-analysis-kit/js-apis-hidebug.md#hidebugsetappresourcelimit12)设置内存限制，造成内存内存泄漏，需要同步在“开发者选项”中打开“系统资源泄漏日志”。接口示例代码如下：

   ```ts
    import hidebug from "@ohos.hidebug";

    @Entry
    @Component
    struct Index {
    @State leakedArray: string[][] = [];

    build() {
      Column() {
        Row() {
          Column() {
            Button("pss leak")
              .onClick(() => {
                hidebug.setAppResourceLimit("pss_memory", 1024, true);
                for (let i = 0; i < 20 * 1024; i++) {
                  this.leakedArray.push(new Array(1).fill("leak"));
                }
              })
          }
        }
        .height('100%')
        .width('100%')
      }
    }
   ```

8. 点击IDE界面中的运行按钮，运行应用工程，等待15~30分钟，会上报应用内存泄漏事件。
   同一个应用，24小时内至多上报一次内存泄漏，如果短时间内要二次上报，需要重启设备。

9. 内存泄漏事件上报后，可以在Log窗口看到对系统事件数据的处理日志：

   ```text
   08-07 03:53:35.314 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.domain=OS
   08-07 03:53:35.314 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.name=RESOURCE_OVERLIMIT
   08-07 03:53:35.314 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.eventType=1
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.time=1502049167732
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.pid=1587
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.uid=20010043
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.resource_type=pss_memory
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.bundle_version=1.0.0
   08-07 03:53:35.350 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.memory={"pss":2100257,"rss":1352644,"sys_avail_mem":250272,"sys_free_mem":60004,"sys_total_mem":1992340,"vss":2462936}
   08-07 03:53:35.350 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/resourcelimit/RESOURCE_OVERLIMIT_1725614572401_6808.log","/data/storage/el2/log/resourcelimit/RESOURCE_OVERLIMIT_1725614572412_6808.log"]
   08-07 03:53:35.350 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.log_over_limit=false
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
