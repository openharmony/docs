# 事件订阅（C/C++）

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--Designer: @junjie_shi-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

HiAppEvent提供了事件订阅接口，用于获取应用的事件。

## 接口说明

API接口的使用说明，包括参数使用限制和取值范围，请参考[HiAppEvent C API文档](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md)。

**订阅接口功能介绍**：

| 接口名 | 描述 |
| -------- | -------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher* watcher) | 添加应用的事件观察者。 |
| int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher* watcher) | 移除应用的事件观察者。 |

**打点接口功能介绍**：

| 接口名 | 描述 |
| -------- | -------- |
| int OH_HiAppEvent_Write(const char* domain, const char* name, enum EventType type, const ParamList list) | 实现对参数为列表类型的应用事件打点。 |

## 事件订阅开发指导

以订阅崩溃事件（系统事件）和按钮点击事件（应用事件）为例，说明开发步骤。

### 步骤一：新建工程及编译配置

1. 获取该示例工程依赖的jsoncpp文件，
   从[三方开源库jsoncpp代码仓](https://github.com/open-source-parsers/jsoncpp)下载源码的压缩包，并按照README的**Amalgamated source**中介绍的操作步骤得到jsoncpp.cpp、json.h和json-forwards.h三个文件。
   新建Native C++工程，并将jsoncpp导入工程，目录结构如下：

   ```text
   entry
   └── src
       └── main
           ├── cpp
           │   ├── CMakeLists.txt
           │   ├── json
           │   │   ├── json-forwards.h
           │   │   └── json.h
           │   ├── jsoncpp.cpp
           │   ├── napi_init.cpp
           │   └── types
           │       └── libentry
           │           ├── Index.d.ts
           │           └── oh-package.json5
           └── ets
               ├── entryability
               │   └── EntryAbility.ets
               └── pages
                   └── Index.ets
   ```

2. 编辑“CMakeLists.txt”文件，添加源文件和动态库。

   ```cmake
   # 新增jsoncpp.cpp(解析订阅事件中的json字符串)源文件
   add_library(entry SHARED napi_init.cpp jsoncpp.cpp)
   # 新增动态库依赖libhiappevent_ndk.z.so和libhilog_ndk.z.so(日志输出)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libhiappevent_ndk.z.so)
   ```

3. 编辑“napi_init.cpp”文件，导入依赖的文件并定义LOG_TAG：

   ```c++
   #include "napi/native_api.h"
   #include "json/json.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   ```

### 步骤二：订阅事件

1. 订阅事件。分别使用OnReceive类型观察者、OnTrigger类型观察者的订阅方式。
   - 订阅崩溃事件（系统事件），采用OnReceive类型观察者的订阅方式，观察者接收到事件后会立即触发OnReceive()回调。编辑“napi_init.cpp”文件，定义OnReceive类型观察者相关方法：

      ```c++
      // 定义变量，用来缓存创建的观察者的指针。
      static HiAppEvent_Watcher *onReceiverWatcher;
      
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
                          // 开发者可以获取到崩溃事件发生的时间戳
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", params["time"].asInt64());
                          // 开发者可以获取到崩溃应用的包名
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", params["bundle_name"].asString().c_str());
                          auto external_log = writer.write(params["external_log"]);
                          // 开发者可以获取到崩溃事件发生时的故障日志文件
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", external_log.c_str());
                      }
                  }
              }
          }
      }
      static napi_value RegisterWatcherCrash(napi_env env, napi_callback_info info) {
          // 开发者自定义观察者名称，系统根据不同的名称来识别不同的观察者。
          onReceiverWatcher = OH_HiAppEvent_CreateWatcher("AppCrashWatcher");
          // 设置订阅的事件名称为EVENT_APP_CRASH，即崩溃事件。
          const char *names[] = {EVENT_APP_CRASH};
          // 开发者订阅感兴趣的事件，此处订阅了系统事件。
          OH_HiAppEvent_SetAppEventFilter(onReceiverWatcher, DOMAIN_OS, 0, names, 1);
          // 开发者设置已实现的回调函数，观察者接收到事件后回立即触发OnReceive回调。
          OH_HiAppEvent_SetWatcherOnReceive(onReceiverWatcher, OnReceive);
          // 使观察者开始监听订阅的事件。
          OH_HiAppEvent_AddWatcher(onReceiverWatcher);
          return {};
      }
      ```

   - 订阅按钮点击事件（应用事件），采用OnTrigger类型观察者的订阅方式。需满足OH_HiAppEvent_SetTriggerCondition()设置的条件，才能触发OnTrigger()回调。编辑 “napi_init.cpp”文件，定义OnTrigger类型观察者相关方法：

      ```c++
      // 定义变量，用来缓存创建的观察者的指针。
      static HiAppEvent_Watcher *onTriggerWatcher;
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
          OH_HiAppEvent_TakeWatcherData(onTriggerWatcher, row, OnTake);
      }
      
      static napi_value RegisterWatcherClick(napi_env env, napi_callback_info info) {
          // 开发者自定义观察者名称，系统根据不同的名称来识别不同的观察者。
          onTriggerWatcher = OH_HiAppEvent_CreateWatcher("ButtonClickWatcher");
          // 设置订阅的事件名称为click。
          const char *names[] = {"click"};
          // 开发者订阅感兴趣的应用事件，此处订阅了button相关事件。
          OH_HiAppEvent_SetAppEventFilter(onTriggerWatcher, "button", 0, names, 1);
          // 开发者设置已实现的回调函数，需OH_HiAppEvent_SetTriggerCondition设置的条件满足方可触发。
          OH_HiAppEvent_SetWatcherOnTrigger(onTriggerWatcher, OnTrigger);
          // 开发者可以设置订阅触发回调的条件，此处是设置新增事件打点数量为1个时，触发onTrigger回调。
          OH_HiAppEvent_SetTriggerCondition(onTriggerWatcher, 1, 0, 0);
          // 使观察者开始监听订阅的事件。
          OH_HiAppEvent_AddWatcher(onTriggerWatcher);
          return {};
      }
      ```

2. 编辑“napi_init.cpp”文件，添加按钮点击事件的打点接口：

   ```c++
   static napi_value WriteAppEvent(napi_env env, napi_callback_info info) {
       auto params = OH_HiAppEvent_CreateParamList();
       OH_HiAppEvent_AddInt64Param(params, "click_time", time(nullptr));
       OH_HiAppEvent_Write("button", "click", EventType::BEHAVIOR, params);
       OH_HiAppEvent_DestroyParamList(params);
       return {};
   }
   ```

3. 编辑“napi_init.cpp”文件，注册RegisterWatcherCrash()(订阅崩溃事件)、RegisterWatcherClick()（订阅按钮点击事件）、WriteAppEvent()(按钮点击事件打点接口)为ArkTS接口：

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "registerWatcherCrash", nullptr, RegisterWatcherCrash, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "registerWatcherClick", nullptr, RegisterWatcherClick, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "writeAppEvent", nullptr, WriteAppEvent, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

4. 编辑“index.d.ts”文件，定义ArkTS接口：

   ```ts
   export const registerWatcherCrash: () => void;
   export const registerWatcherClick: () => void;
   export const writeAppEvent: () => void;
   ```

5. 编辑“EntryAbility.ets”文件，在onCreate()函数中添加接口调用：

   ```ts
   // 导入依赖模块
   import testNapi from 'libentry.so';
   
   // 在onCreate()函数中添加接口调用
   // 启动时，注册崩溃事件观察者
   testNapi.registerWatcherCrash();
   // 启动时，注册按钮点击事件观察者
   testNapi.registerWatcherClick();
   ```

### 步骤三：触发事件

编辑“Index.ets”文件，新增“appCrash”按钮以触发崩溃事件；新增“buttonClick”按钮，在按钮点击函数中进行事件打点。示例代码如下：

```ts
// 导入依赖模块
import testNapi from 'libentry.so';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button("appCrash")
          .onClick(() => {
            // 在按钮点击函数中构造一个crash场景，触发应用崩溃事件
            let result: object = JSON.parse("");
          })
          .position({ x: 100, y: 100 }) // 设置按钮位置

        Button("buttonClick")
          .onClick(() => {
            // 在按钮点击函数中进行事件打点，以记录按钮点击事件
            testNapi.writeAppEvent();
          })
          .position({ x: 100, y: 200 }) // 设置按钮位置
        }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 调测验证

1. 点击DevEco Studio界面中的运行按钮，运行应用工程。在应用界面中点击“appCrash”按钮，触发崩溃事件。应用退出后重新打开应用。

2. 搜索关键字“HiAppEvent”，在HiLog窗口查看应用处理崩溃事件数据的日志：

   ```text
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_CRASH
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.params.time=1750946685473
   HiAppEvent eventInfo.params.bundle_name=com.example.cxxxx
   HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/APP_CRASH_1750946685805_64003.log"]
   ```

3. 点击buttonClick按钮，触发按钮点击事件。搜索关键字“HiAppEvent”，在HiLog窗口查看应用处理按钮点击事件数据的日志：

   ```text
   HiAppEvent eventInfo={"domain_":"button","name_":"click","type_":4,"time_":1750947007108,"tz_":"","pid_":64750,"tid_":64750,"click_time":1750947007}
   HiAppEvent eventInfo.domain=button
   HiAppEvent eventInfo.name=click
   HiAppEvent eventInfo.eventType=4
   HiAppEvent eventInfo.params.click_time=1750947007
   ```

4. 移除应用的事件观察者：

   ```c++
   static napi_value RemoveWatcher(napi_env env, napi_callback_info info) {
       // 使观察者停止监听事件
       OH_HiAppEvent_RemoveWatcher(appEventWatcher);
       return {};
   }
   ```

5. 销毁应用的事件观察者：

   ```c++
   static napi_value DestroyWatcher(napi_env env, napi_callback_info info) {
       // 销毁创建的观察者，并置appEventWatcher为nullptr
       OH_HiAppEvent_DestroyWatcher(appEventWatcher);
       appEventWatcher = nullptr;
       return {};
   }
   ```
