# 订阅应用查杀事件（C/C++）

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @shead-master-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 应用查杀事件规格说明

请参考[应用查杀事件介绍](./hiappevent-watcher-app-killed-events.md)。

## 接口说明

API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[HiAppEvent](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md)。

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
   #include <thread>
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   ```

4. 订阅系统事件：

    - onReceive类型观察者：

      编辑"napi_init.cpp"文件，定义onReceive类型观察者相关方法，并且新增Native内存泄漏方法：

      ```c++
      // 定义一变量，用来缓存创建的观察者的指针。
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
                      strcmp(appEventGroups[i].appEventInfos[j].name, EVENT_APP_KILLED) == 0) {
                      Json::Value params;
                      Json::Reader reader(Json::Features::strictMode());
                      Json::FastWriter writer;
                      if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                          auto time = params["time"].asInt64();
                          auto reason = params["reason"].asString();
                          auto foreground = params["foreground"].asString();
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.reason=%{public}s",
                                      reason.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.foreground=%{public}s",
                                      foreground.c_str());
                      }
                  }
              }
          }
      }
      
      static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent RegisterWatcher");
          // 开发者自定义观察者名称，系统根据不同的名称来识别不同的观察者。
          systemEventWatcher = OH_HiAppEvent_CreateWatcher("onReceiverWatcher");
          // 设置订阅的事件为EVENT_APP_KILLED。
          const char *names[] = {EVENT_APP_KILLED};
          // 开发者订阅感兴趣的事件，此处订阅了系统事件。
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
          // 开发者设置已实现的回调函数，观察者接收到事件后回立即触发OnReceive回调。
          OH_HiAppEvent_SetWatcherOnReceive(systemEventWatcher, OnReceive);
          // 使观察者开始监听订阅的事件。
          OH_HiAppEvent_AddWatcher(systemEventWatcher);
          return {};
      }
      ```

5. 实现Leak接口（仅用于故障注入及自验证，无需集成到业务逻辑中）：

   ```c++
   static void NativeLeak()
   {
       constexpr int leak_size_per_time = 500000;
       while (true) {
           char *p = (char *)malloc(leak_size_per_time + 1);
           if (!p) {
               break;
           }
           memset(p, 'a', leak_size_per_time);
           std::this_thread::sleep_for(std::chrono::milliseconds(10));
       }
   }
   
   static napi_value Leak(napi_env env, napi_callback_info info) {
   	std::thread t1(NativeLeak);
   	t1.detach();
       return {};
   }
   ```

6. 编辑"napi_init.cpp"文件，将RegisterWatcher和Leak注册为ArkTS接口：

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "registerWatcher", nullptr, RegisterWatcher, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "leak", nullptr, Leak, nullptr, nullptr, nullptr, napi_default, nullptr },
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```
   
   编辑"index.d.ts"文件，定义ArkTS接口：

   ```typescript
   export const registerWatcher: () => void;
   export const leak: () => void;
   ```
   
7. 编辑工程中的“entry > src > main > ets > entryability> EntryAbility.ets”文件，在onCreate()函数中新增接口调用：

   ```typescript
   // 导入依赖模块
   import testNapi from 'libentry.so';
   
   // 在onCreate()函数中新增接口调用
   // 启动时，注册系统事件观察者
   testNapi.registerWatcher();
   
   // 在按钮操作或者启动时，触发泄漏
   testNapi.leak();
   ```

8. 点击DevEco Studio界面中的运行按钮，运行应用工程，触发泄漏后，等待2-3分钟，应用会退出。

9. 应用被查杀后，重新打开应用，会触发查杀事件上报，系统会回调应用的onReceive函数，可以在Log窗口看到对系统事件数据的处理日志：

    ```text
      HiAppEvent eventInfo.domain=OS
      HiAppEvent eventInfo.name=APP_KILLED
      HiAppEvent eventInfo.eventType=2
      HiAppEvent eventInfo.params.time=1717597063727
      HiAppEvent eventInfo.params.reason="RssThresholdKiller"
      HiAppEvent eventInfo.params.foreground=true
    ```

    > **说明：**
    >
    > 根据日志报错内容，可查看具体[查杀原因](./hiappevent-watcher-app-killed-events.md)。

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
