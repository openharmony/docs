# 订阅主线程超时事件（C/C++）

## 主线程超时事件规格说明

请参考[主线程超时事件介绍](./hiappevent-watcher-mainthreadjank-events.md)。

## 接口说明

API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[HiAppEvent](../reference/apis-performance-analysis-kit/_hi_app_event.md#hiappevent)。

**订阅接口功能介绍：**

| 接口名                                                       | 描述                                         |
| ------------------------------------------------------------ | -------------------------------------------- |
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
   #include "hiappevent/hiappevent_event.h"
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
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s",
                              appEventGroups[i].appEventInfos[j].domain);
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s",
                              appEventGroups[i].appEventInfos[j].name);
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d",
                              appEventGroups[i].appEventInfos[j].type);
                  if (strcmp(appEventGroups[i].appEventInfos[j].domain, DOMAIN_OS) == 0 &&
                      strcmp(appEventGroups[i].appEventInfos[j].name, EVENT_MAIN_THREAD_JANK) == 0) {
                      Json::Value params;
                      Json::Reader reader(Json::Features::strictMode());
                      Json::FastWriter writer;
                      if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                          auto time = params["time"].asInt64();
                          auto pid = params["pid"].asInt();
                          auto uid = params["uid"].asInt();
                          auto bundleName = params["bundle_name"].asString();
                          auto bundleVersion = params["bundle_version"].asString();
                          auto beginTime = params["begin_time"].asInt64();
                          auto endTime = params["end_time"].asInt64();
                          auto externalLog = writer.write(params["external_log"]);
                          auto logOverLimit = params["logOverLimit"].asBool();
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s",
                                      bundleName.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s",
                                      bundleVersion.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.begin_time=%{public}lld", beginTime);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.end_time=%{public}lld", endTime);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", externalLog.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}d",
                                      logOverLimit);
                      }
                  }
              }
          }
      }

      static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent RegisterWatcher");
          // 开发者自定义观察者名称，系统根据不同的名称来识别不同的观察者。
          systemEventWatcher = OH_HiAppEvent_CreateWatcher("onReceiverWatcher");
          // 设置订阅的事件为EVENT_MAIN_THREAD_JANK。
          const char *names[] = {EVENT_MAIN_THREAD_JANK};
          // 开发者订阅感兴趣的事件，此处订阅了系统事件。
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
          // 开发者设置已实现的回调函数，观察者接收到事件后回立即触发OnReceive回调。
          OH_HiAppEvent_SetWatcherOnReceive(systemEventWatcher, OnReceive);
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

6. 编辑工程中的“entry > src > main > ets > entryability> EntryAbility.ets”文件，在onCreate()函数中新增接口调用：

   ```typescript
   // 导入依赖模块
   import testNapi from 'libentry.so';

   // 在onCreate()函数中新增接口调用
   // 启动时，注册系统事件观察者
   testNapi.registerWatcher();
   ```

7. 编辑工程中的“entry > src > main > ets > pages> Index.ets”文件，添加一个Button控件onClick中实现主线程超时代码，示例代码如下：

   ```typescript
      Button("timeOut350")
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .onClick(() => {
          let t = Date.now();
          while (Date.now() - t <= 350) {}
      })
   ```

8. 点击DevEco Studio界面中的运行按钮，运行应用工程，连续点击两次timeOut350按钮，会触发主线程超时事件。

9. 主线程超时事件上报后，可以在Log窗口看到对系统事件数据的处理日志：

    ```text
      HiAppEvent eventInfo.domain=OS
      HiAppEvent eventInfo.name=MAIN_THREAD_JANK
      HiAppEvent eventInfo.eventType=1
      HiAppEvent eventInfo.params.time=1717597063727
      HiAppEvent eventInfo.params.pid=45572
      HiAppEvent eventInfo.params.uid=20020151
      HiAppEvent eventInfo.params.bundle_name=com.example.nativemainthread
      HiAppEvent eventInfo.params.bundle_version=1.0.0
      HiAppEvent eventInfo.params.begin_time=1717597063225
      HiAppEvent eventInfo.params.end_time=1717597063727
      HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/watchdog/MAIN_THREAD_JANK_20240613221239_45572.txt"]
      HiAppEvent eventInfo.params.log_over_limit=0
    ```

    > **说明：**
    > 主线程超时事件具体规格可参考：[主线程超时事件默认时间规格](./hiappevent-watcher-mainthreadjank-events.md#主线程超时事件默认时间规格) 和 [主线程超时事件日志规格](./hiappevent-watcher-mainthreadjank-events.md#主线程超时事件日志规格)。

11. 移除事件观察者：

    ```c++
    static napi_value RemoveWatcher(napi_env env, napi_callback_info info) {
        // 使观察者停止监听事件
        OH_HiAppEvent_RemoveWatcher(systemEventWatcher);
        return {};
    }
    ```

12. 销毁事件观察者：

    ```c++
    static napi_value DestroyWatcher(napi_env env, napi_callback_info info) {
        // 销毁创建的观察者，并置systemEventWatcher为nullptr。
        OH_HiAppEvent_DestroyWatcher(systemEventWatcher);
        systemEventWatcher = nullptr;
        return {};
    }
    ```
