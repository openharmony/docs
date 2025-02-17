# 订阅主线程超时事件（ArkTS）

## 主线程超时事件规格说明

请参考[主线程超时事件介绍](./hiappevent-watcher-mainthreadjank-events.md)。

## 接口说明

API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[应用事件打点API文档](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md)。

| 接口名                                              | 描述                                         |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | 添加应用事件观察者，以添加对应用事件的订阅。 |
| removeWatcher(watcher: Watcher): void               | 移除应用事件观察者，以移除对应用事件的订阅。 |

## 开发步骤

本例以订阅主线程超时事件，发生**主线程超时触发采样栈场景**为例，说明开发步骤。

1. 新建一个ArkTS应用工程，编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，导入依赖模块：

   ```ts
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. 编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，在onCreate函数中添加系统事件的订阅，示例代码如下：

   ```ts
    hiAppEvent.addWatcher({
      // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
      name: "watcher",
      // 开发者可以订阅感兴趣的系统事件，此处是订阅了主线程超时事件
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.MAIN_THREAD_JANK]
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
            // 开发者可以获取到主线程超时事件发生的时间戳
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params['time']}`);
            // 开发者可以获取到主线程超时应用的版本信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_version=${eventInfo.params['bundle_version']}`);
            // 开发者可以获取到主线程超时应用的包名
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_name=${eventInfo.params['bundle_name']}`);
            // 开发者可以获取到主线程超时应用的pid、uid
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.pid=${eventInfo.params['pid']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params['uid']}`);
            // 开发者可以获取主线程处理开始和结束时间
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.begin_time=${eventInfo.params['begin_time']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.end_time=${eventInfo.params['end_time']}`);
            // 开发者可以获取到主线程超时事件发生时的故障日志文件
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.external_log=${JSON.stringify(eventInfo.params['external_log'])}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.log_over_limit=${eventInfo.params['log_over_limit']}`);
          }
        }
      }
    });
   ```

3. 编辑工程中的“entry > src > main > ets  > pages> Index.ets”文件，添加一个Button控件onClick中实现主线程超时代码，示例代码如下：

   ```ts
     Button("timeOut350")
     .fontSize(50)
     .fontWeight(FontWeight.Bold)
     .onClick(() => {
         let t = Date.now();
         while (Date.now() - t <= 350) {}
     })
   ```

4. 点击DevEco Studio界面中的运行按钮，运行应用工程，连续点击两次timeOut350按钮，会触发主线程超时事件。

5. 主线程超时事件上报后，系统会回调应用的onReceive函数，可以在Log窗口看到对系统事件数据的处理日志：

   主线程超时事件采样栈示例：

    ```text
     HiAppEvent eventInfo.domain=OS
     HiAppEvent eventInfo.name=MAIN_THREAD_JANK
     HiAppEvent eventInfo.eventType=1
     HiAppEvent eventInfo.params.time=1717593620518
     HiAppEvent eventInfo.params.bundle_version=1.0.0
     HiAppEvent eventInfo.params.bundle_name=com.example.main_thread_jank
     HiAppEvent eventInfo.params.pid=40986
     HiAppEvent eventInfo.params.uid=20020150
     HiAppEvent eventInfo.params.begin_time=1717593620016
     HiAppEvent eventInfo.params.end_time=1717593620518
     HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/watchdog/MAIN_THREAD_JANK_20240613211739_40986.txt"]
     HiAppEvent eventInfo.params.log_over_limit=false
    ```

   主线程超时事件采样trace，与采样栈的结果大致相同，不同的地方：

   栈：
   external_log=["/data/storage/el2/log/watchdog/MAIN_THREAD_JANK_yyyyMMDDHHmmss_xxxx.txt"]。xxxx：代表进程pid。

   trace：
   external_log=[""/data/storage/el2/log/watchdog/MAIN_THREAD_JANK_unix时间戳_xxxx.trace"]。xxxx：代表进程pid。
