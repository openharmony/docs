# 订阅任务执行超时事件（ArkTS）

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @rr_cn-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 简介

从API version 21开始，支持arkTS接口订阅任务执行超时事件。 本文介绍如何使用HiAppEvent提供的ArkTS接口订阅任务执行超时事件。接口的详细使用说明（参数限制、取值范围等）请参考[@ohos.hiviewdfx.hiAppEvent (应用事件打点)ArkTS API文档](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md)。

## 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | 添加应用事件观察者，以添加对应用事件的订阅。 |
| removeWatcher(watcher: Watcher): void | 移除应用事件观察者，以取消对应用事件的订阅。 |

## 开发步骤

### 添加事件观察者

为确保开发阶段顺利接收事件回调，建议采取以下方案：创建新的Native C++工程，在ArkTs代码中实现订阅，并通过C++代码构造故障注入以触发任务执行超时事件。

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
             - EntryAbility.ets
           pages:
             - Index.ets
   ```

2. 编辑“CMakeLists.txt”文件，添加源文件及动态库。

   ```cmake
   # 新增动态库依赖libhilog_ndk.z.so（日志输出）及libohhicollie.so（hicollie检测）
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhicollie.so)
   ```

3. 编辑“EntryAbility.ets”文件，导入依赖模块，示例代码如下：

   ```ts
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

4. 订阅系统事件，编辑“EntryAbility.ets”文件，在onCreate函数中添加订阅代码，示例代码如下：

   ```ts
   let watcher: hiAppEvent.Watcher = {
     // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
     name: "watcher",
     // 开发者可以订阅感兴趣的系统事件，此处是订阅了任务执行超时事件
     appEventFilters: [
       {
         domain: hiAppEvent.domain.OS,
         names: [hiAppEvent.event.APP_HICOLLIE]
       }
     ],
     // 开发者可以自行实现订阅实时回调函数，以便对订阅获取到的事件数据进行自定义处理
     onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
       hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
       for (const eventGroup of appEventGroups) {
         hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
         for (const eventInfo of eventGroup.appEventInfos) {
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.domain=${eventInfo.domain}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.name=${eventInfo.name}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.eventType=${eventInfo.eventType}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params['time']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.foreground=${eventInfo.params['foreground']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_version=${eventInfo.params['bundle_version']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.process_name=${eventInfo.params['process_name']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.pid=${eventInfo.params['pid']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params['uid']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params['uuid']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.exception=${eventInfo.params['exception']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.hilog.size=${eventInfo.params['hilog'].length}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.peer_binder.size=${JSON.stringify(eventInfo.params['peer_binder'].length)}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.memory=${eventInfo.params['memory']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.external_log=${JSON.stringify(eventInfo.params['external_log'])}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.log_over_limit=${eventInfo.params['log_over_limit']}`);
         }
       }
     }
    };
   hiAppEvent.addWatcher(watcher);
   ```

5. 新增TestHiCollieTimerNdk函数。

   编辑“napi_init.cpp”文件，新增TestHiCollieTimerNdk函数，构造任务执行超时事件：

   ```c++
   // 引入hicollie.h头文件
   #include "napi/native_api.h"
   #include "hicollie/hicollie.h"
   #include "hilog/log.h"
   #include <unistd.h>
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   
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

6. 将TestHiCollieTimerNdk注册为ArkTS接口。

   编辑“napi_init.cpp”文件，TestHiCollieTimerNdk注册为ArkTS接口：

   ```c++
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "TestHiCollieTimerNdk", nullptr, TestHiCollieTimerNdk, nullptr, nullptr, nullptr, napi_default, nullptr }
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
   export const TestHiCollieTimerNdk: () => void;
   ```

7. 编辑“Index.ets”文件，新增按钮触发任务执行超时事件。

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

8. 单击DevEco Studio界面中的运行按钮，运行应用工程，然后在应用界面中单击按钮“testHiCollieTimerNdk”，触发任务执行超时事件。

### 验证观察者是否订阅到任务执行超时事件

应用工程崩溃退出后，再次运行可在Log窗口查看系统事件数据处理日志。

   ```text
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_HICOLLIE
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.params.time=1754914806680
   HiAppEvent eventInfo.params.foreground=true
   HiAppEvent eventInfo.params.bundle_version=1.0.0
   HiAppEvent eventInfo.params.process_name=com.example.myapplication
   HiAppEvent eventInfo.params.pid=20317
   HiAppEvent eventInfo.params.uid=20020198
   HiAppEvent eventInfo.params.uuid=4asd360e18f5d6d84cf4f0c9e80d66we5786c1cc2343d9632e07abb0d3552asd
   HiAppEvent eventInfo.params.exception={"message":"","name":"APP_HICOLLIE"}
   HiAppEvent eventInfo.params.hilog.size=28
   HiAppEvent eventInfo.params.peer_binder.size=0
   HiAppEvent eventInfo.params.memory={"pss":0,"rss":150748,"sys_avail_mem":5387264,"sys_free_mem":218902,"sys_total_mem":11679236,"vss":38306936}
   HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/APP_HICOLLIE_1754914811140_20317.log"]
   HiAppEvent eventInfo.params.log_over_limit=false
   ```

### 移除事件观察者

1. 移除事件观察者

```ts
// 移除该应用事件观察者以取消订阅事件
hiAppEvent.removeWatcher(watcher);
```