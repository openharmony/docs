# 订阅应用事件（C/C++）

HiAppEvent提供了事件订阅接口，用于本地获取应用事件。

## 接口说明
API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[HiAppEvent](../reference/apis-performance-analysis-kit/_hi_app_event.md#hiappevent)。

**打点接口功能介绍：**

| 接口名                                                       | 描述                                 |
| ------------------------------------------------------------ | ------------------------------------ |
| int OH_HiAppEvent_Write(const char \*domain, const char \*name, enum EventType type, const ParamList list) | 实现对参数为列表类型的应用事件打点。 |

**订阅接口功能介绍：**

| 接口名                                                       | 描述                                         |
| ------------------------------------------------------------ | -------------------------------------------- |
| int OH_HiAppEvent_AddWatcher (HiAppEvent_Watcher \*watcher)  | 添加应用事件观察者，以添加对应用事件的订阅。 |
| int OH_HiAppEvent_RemoveWatcher (HiAppEvent_Watcher \*watcher) | 移除应用事件观察者，以移除对应用事件的订阅。 |

## 开发步骤

以实现对用户点击按钮行为的事件打点及订阅为例，说明开发步骤：

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

4. 订阅应用事件：

   - onReceive类型观察者：

     编辑"napi_init.cpp"文件，定义onReceive类型观察者相关方法：

     ```c++
     static HiAppEvent_Watcher *appEventWatcher;
     
     static void OnReceive(const char *domain, const struct HiAppEvent_AppEventGroup *appEventGroups, uint32_t groupLen) {
         for (int i = 0; i < groupLen; ++i) {
             for (int j = 0; j < appEventGroups[i].infoLen; ++j) {
                 OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s", appEventGroups[i].appEventInfos[j].domain);
                 OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s", appEventGroups[i].appEventInfos[j].name);
                 OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d", appEventGroups[i].appEventInfos[j].type);
                 if (strcmp(appEventGroups[i].appEventInfos[j].domain, "button") == 0 &&
                     strcmp(appEventGroups[i].appEventInfos[j].name, "click") == 0) {
                     Json::Value params;
                     Json::Reader reader(Json::Features::strictMode());
                     if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                         auto time = params["click_time"].asInt64();
                         OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.click_time=%{public}lld", time);
                     }
                 }
             }
         }
     }
     
     static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
         // 开发者自定义观察者名称，系统根据不同的名称来识别不同的观察者。
         appEventWatcher = OH_HiAppEvent_CreateWatcher("onReceiverWatcher");
         // 设置订阅的事件名称为click。
         const char *names[] = {"click"};
         // 开发者订阅感兴趣的应用事件，此处订阅了button相关事件。
         OH_HiAppEvent_SetAppEventFilter(appEventWatcher, "button", 0, names, 1);
         // 开发者设置已实现的回调函数，观察者接收到事件后回立即触发OnReceive回调。
         OH_HiAppEvent_SetWatcherOnReceive(appEventWatcher, OnReceive);
         // 使观察者开始监听订阅的事件。
         OH_HiAppEvent_AddWatcher(appEventWatcher);
         return {};
     }
     ```

   - onTrigger类型观察者：

     编辑"napi_init.cpp"文件，定义OnTrigger类型观察者相关方法：

     ```c++
     //定义一变量，用来缓存创建的观察者的指针。
     static HiAppEvent_Watcher *appEventWatcher;
     
     // 开发者可以自行实现获取已监听到事件的回调函数，其中events指针指向内容仅在该函数内有效。
     static void OnTake(const char *const *events, uint32_t eventLen) {
         Json::Reader reader(Json::Features::strictMode());
         for (int i = 0; i < eventLen; ++i) {
             OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo=%{public}s", events[i]);
             Json::Value eventInfo;
             if (reader.parse(events[i], eventInfo)) {
                 auto domain = eventInfo["domain_"].asString();
                 auto name = eventInfo["name_"].asString();
                 auto type = eventInfo["type_"].asInt();
                 OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s", domain.c_str());
                 OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s", name.c_str());
                 OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d", type);
                 if (domain == "button" && name == "click") {
                     auto clickTime = eventInfo["click_time"].asInt64();
                     OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.click_time=%{public}lld", clickTime);
                 }
             }
         }
     }
     
     // 开发者可以自行实现订阅回调函数，以便对获取到的事件打点数据进行自定义处理。
     static void OnTrigger(int row, int size) {
         // 接收回调后，获取指定数量的已接收事件。
         OH_HiAppEvent_TakeWatcherData(appEventWatcher, row, OnTake);
     }
     
     static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
         // 开发者自定义观察者名称，系统根据不同的名称来识别不同的观察者。
         appEventWatcher = OH_HiAppEvent_CreateWatcher("onTriggerWatcher");
         // 设置订阅的事件名称为click。
         const char *names[] = {"click"};
         // 开发者订阅感兴趣的应用事件，此处订阅了button相关事件。
         OH_HiAppEvent_SetAppEventFilter(appEventWatcher, "button", 0, names, 1);
         // 开发者设置已实现的回调函数，需OH_HiAppEvent_SetTriggerCondition设置的条件满足方可触发。
         OH_HiAppEvent_SetWatcherOnTrigger(appEventWatcher, OnTrigger);
         // 开发者可以设置订阅触发回调的条件，此处是设置新增事件打点数量为1个时，触发onTrigger回调。
         OH_HiAppEvent_SetTriggerCondition(appEventWatcher, 1, 0, 0);
         // 使观察者开始监听订阅的事件。
         OH_HiAppEvent_AddWatcher(appEventWatcher);
         return {};
     }
     ```

5. 编辑"napi_init.cpp"文件，添加button事件打点接口：

   ```c++
   static napi_value WriteAppEvent(napi_env env, napi_callback_info info) {
       auto params = OH_HiAppEvent_CreateParamList();
       OH_HiAppEvent_AddInt64Param(params, "click_time", time(nullptr));
       OH_HiAppEvent_Write("button", "click", EventType::BEHAVIOR, params);
       OH_HiAppEvent_DestroyParamList(params);
       return {};
   }
   ```

6. 编辑"napi_init.cpp"文件，将RegisterWatcher和WriteAppEvent注册为ArkTS接口：

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           {"registerWatcher", nullptr, RegisterWatcher, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"writeAppEvent", nullptr, WriteAppEvent, nullptr, nullptr, nullptr, napi_default, nullptr}
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

   编辑"index.d.ts"文件，定义ArkTS接口：

   ```typescript
   export const registerWatcher: () => void;
   export const writeAppEvent: () => void;
   ```

7. 编辑"EntryAbility.ets"文件，在onCreate()函数中新增接口调用：

   ```typescript
   // 导入依赖模块
   import testNapi from 'libentry.so'

   // 在onCreate()函数中新增接口调用
   // 启动时，注册应用事件观察者
   testNapi.registerWatcher();
   ```

8. 编辑"Index.ets"文件，新增按钮触发打点事件：

   ```typescript
   import testNapi from 'libentry.so'

   Button("button_click").onClick(() => {
     testNapi.writeAppEvent();
   })
   ```

9. 可以在Log窗口看到对应用事件数据的处理日志：

   ```text
   HiAppEvent eventInfo.domain=button
   HiAppEvent eventInfo.name=click
   HiAppEvent eventInfo.eventType=4
   HiAppEvent eventInfo.params.click_time=1502031843
   ```

10. 移除应用事件观察者：

    ```c++
    static napi_value RemoveWatcher(napi_env env, napi_callback_info info) {
        // 使观察者停止监听事件
        OH_HiAppEvent_RemoveWatcher(appEventWatcher);
        return {};
    }
    ```

11. 销毁应用事件观察者：

    ```c++
    static napi_value DestroyWatcher(napi_env env, napi_callback_info info) {
        // 销毁创建的观察者，并置appEventWatcher为nullptr。
        OH_HiAppEvent_DestroyWatcher(appEventWatcher);
        appEventWatcher = nullptr;
        return {};
    }
    ```
