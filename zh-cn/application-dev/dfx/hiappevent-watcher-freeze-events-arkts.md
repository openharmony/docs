# 订阅应用冻屏事件（ArkTS）

## 简介

本文介绍如何使用HiAppEvent提供的ArkTs接口订阅应用无响应事件。接口的详细使用说明（参数限制、取值范围等）请参考[@ohos.hiviewdfx.hiAppEvent (应用事件打点)ArkTS API文档](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md)。

## 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | 添加应用事件观察者，以添加对应用事件的订阅。 |
| removeWatcher(watcher: Watcher): void | 移除应用事件观察者，以移除对应用事件的订阅。 |

## 开发步骤

### 添加事件观察者

以实现对用户点击按钮触发应用无响应场景生成的应用无响应事件订阅为例，说明开发步骤。

1. 新建一个ArkTS应用工程，编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，导入依赖模块，示例代码如下：

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. 编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，在onCreate函数中设置事件的自定义参数，示例代码如下：

   ```ts
    // 开发者完成参数键值对赋值
    let params: Record<string, hiAppEvent.ParamType> = {
      "test_data": 100,
    };
    // 开发者可以设置应用无响应事件的自定义参数
    hiAppEvent.setEventParam(params, hiAppEvent.domain.OS, hiAppEvent.event.APP_FREEZE).then(() => {
      hilog.info(0x0000, 'testTag', `HiAppEvent success to set event param`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
    });
   ```

3. 编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，在onCreate函数中添加系统事件的订阅，示例代码如下：

   ```ts
     hiAppEvent.addWatcher({
      // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
      name: "watcher",
      // 开发者可以订阅感兴趣的系统事件，此处是订阅了应用无响应事件
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.APP_FREEZE]
        }
      ],
      // 开发者可以自行实现订阅实时回调函数，以便对订阅获取到的事件数据进行自定义处理
      onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
        hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
        for (const eventGroup of appEventGroups) {
          // 开发者可以根据事件集合中的事件名称区分不同的系统事件
          hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
          for (const eventInfo of eventGroup.appEventInfos) {
            // 开发者可以对事件集合中的事件数据进行自定义处理，此处是将事件数据打印在日志中
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.domain=${eventInfo.domain}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.name=${eventInfo.name}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.eventType=${eventInfo.eventType}`);
            // 开发者可以获取到应用无响应事件发生的时间戳
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params['time']}`);
            // 开发者可以获取到应用无响应应用的前后台状态
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.foreground=${eventInfo.params['foreground']}`);
            // 开发者可以获取到应用无响应应用的版本信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_version=${eventInfo.params['bundle_version']}`);
            // 开发者可以获取到应用无响应应用的包名
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_name=${eventInfo.params['bundle_name']}`);
            // 开发者可以获取到应用无响应应用的进程名称
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.process_name=${eventInfo.params['process_name']}`);
            // 开发者可以获取到应用无响应应用的进程id
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.pid=${eventInfo.params['pid']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params['uid']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uuid=${eventInfo.params['uuid']}`);
            // 开发者可以获取到应用无响应事件发生的异常类型、异常原因
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.exception=${JSON.stringify(eventInfo.params['exception'])}`);
            // 开发者可以获取到应用无响应事件发生时日志信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.hilog.size=${eventInfo.params['hilog'].length}`);
            // 开发者可以获取到应用无响应事件发生时主线程未处理消息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler.size=${eventInfo.params['event_handler'].length}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler_size_3s=${eventInfo.params['event_handler_size_3s']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler_size_6s=${eventInfo.params['event_handler_size_6s']}`);
            // 开发者可以获取到应用无响应事件发生时同步binder调用信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.peer_binder.size=${eventInfo.params['peer_binder'].length}`);
            // 开发者可以获取到应用无响应事件发生时全量线程调用栈
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.threads.size=${eventInfo.params['threads'].length}`);
            // 开发者可以获取到应用无响应事件发生时内存信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.memory=${JSON.stringify(eventInfo.params['memory'])}`);
            // 开发者可以获取到应用无响应事件发生时的故障日志文件
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.external_log=${JSON.stringify(eventInfo.params['external_log'])}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.log_over_limit=${eventInfo.params['log_over_limit']}`);
            // 开发者可以获取到应用无响应事件的自定义数据test_data
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.test_data=${eventInfo.params['test_data']}`);
          }
        }
      }
    });
   ```

4. 编辑工程中的“entry > src > main > ets  > pages > Index.ets”文件，添加按钮并在其onClick函数构造应用无响应场景，以触发应用无响应事件，示例代码如下：

   ```ts
    Button("appFreeze").onClick(()=>{
      // 在按钮点击函数中构造一个freeze场景，触发应用应用无响应事件
      setTimeout(() => {
        let t = Date.now();
        while (Date.now() - t <= 15000) {}
      }, 5000);
    })
   ```

5. 点击DevEco Studio界面中的运行按钮，运行应用工程，然后在应用界面中点击按钮“appFreeze”，触发一次应用无响应事件。

### 验证观察者是否订阅到应用无响应事件

1. 应用应用无响应退出后，重新进入应用可以在Log窗口看到对系统事件数据的处理日志：

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=APP_FREEZE
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_FREEZE
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.params.time=1711440881768
   HiAppEvent eventInfo.params.foreground=true
   HiAppEvent eventInfo.params.bundle_version=1.0.0
   HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
   HiAppEvent eventInfo.params.process_name=com.example.myapplication
   HiAppEvent eventInfo.params.pid=3197
   HiAppEvent eventInfo.params.uid=20010043
   HiAppEvent eventInfo.params.uuid=27fac7098da46efe1cae9904946ec06c5acc91689c365efeefb7a23a0c37df77
   HiAppEvent eventInfo.params.exception={"message":"App main thread is not response!","name":"THREAD_BLOCK_6S"}
   HiAppEvent eventInfo.params.hilog.size=77
   HiAppEvent eventInfo.params.event_handler.size=6
   HiAppEvent eventInfo.params.event_handler_size_3s=5
   HiAppEvent eventInfo.params.event_handler_size_6s=6
   HiAppEvent eventInfo.params.peer_binder.size=0
   HiAppEvent eventInfo.params.threads.size=28
   HiAppEvent eventInfo.params.memory={"pss":0,"rss":0,"sys_avail_mem":1361464,"sys_free_mem":796232,"sys_total_mem":1992340,"vss":0}
   HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/APP_FREEZE_1711440899240_3197.log"]
   HiAppEvent eventInfo.params.log_over_limit=false
   HiAppEvent eventInfo.params.test_data=100
   ```

<!--RP1-->
<!--RP1End-->
