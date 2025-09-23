# 使用FaultLogExtensionAbility订阅事件

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @chenshi51-->
<!--Designer: @Maplestory91-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

从API version 21开始，FaultLogExtensionAbility提供了事件订阅接口，用于应用故障事件（包括[崩溃](./cppcrash-guidelines.md)和[冻屏](./appfreeze-guidelines.md)事件）的延迟通知。当应用无法启动或长时间未启动，可以不依赖应用启动而实现故障的hiappevent订阅上报。

## 约束与限制

- FaultLogExtensionAbility被拉起后只有很短的时间完成故障处理，建议处理时间不要超过10秒。超时没有处理完成可以在[onDisconnect](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-FaultLogExtensionAbility.md#ondisconnect)中保存状态。

- 从开机或上次拉起FaultLogExtensionAbility后，应用首次触发崩溃或冻屏开始计时。在拉起FaultLogExtensionAbility前反复触发崩溃或冻屏事件均不会重新计时。

- FaultLogExtensionAbility自身崩溃时，不会再次被系统服务拉起。

- FaultLogExtensionAbility调用限制的API名单见[附录](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-FaultLogExtensionAbility.md#附录)。

## 接口说明

API接口使用说明，包括参数使用限制和具体取值范围。请参考[@ohos.hiviewdfx.FaultLogExtensionAbility (故障延迟通知)](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-FaultLogExtensionAbility.md)。

仅适用于Stage模型。

接入FaultLogExtensionAbility能力后，若应用故障发生后设备重启，重启后不支持重启前故障的接口回调。

**订阅接口功能介绍**：

| 接口名 | 描述 |
| -------- | -------- |
| [onConnect(): void](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-FaultLogExtensionAbility.md#onconnect) | 生命周期回调函数，系统连接FaultLogExtensionAbility时触发。 |
| [onDisconnect(): void](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-FaultLogExtensionAbility.md#ondisconnect) | 生命周期回调函数，系统断开FaultLogExtensionAbility时触发。 |
| [onFaultReportReady(): void](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-FaultLogExtensionAbility.md#onfaultreportready) | 生命周期回调函数，系统准备好故障信息后，回调该函数通知ability进行处理。回调函数中的业务逻辑建议不超过10s。|

## 事件订阅开发指导

以订阅appfreeze事件为例，说明开发步骤。

1. 新建一个ArkTS应用工程。编辑工程中的“entry > src > main > ets > pages > Index.ets”文件。构造appfreeze故障的代码示例如下：

   ```ts
   @Entry
   @Component
   struct Index {
     build() {
       Button("AppInput").
       .onClick(() => {
         let t = Date.now();
         while (Date.now() - t <= 15000) {}
       })
     }
   }
   ```
 
2. 编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，示例代码如下：
   
   ```ts
   // 导入hiAppEvent依赖模块
   import { hiAppEvent } from '@kit.PerformanceAnalysisKit';
   // 略去的代码...
     // 在onCreate函数中添加系统事件的订阅
     hiAppEvent.addWatcher ({
      // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
      name: "watcher",
      // 开发者可以订阅兴感趣的系统事件，此处是订阅了应用冻屏事件
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.APP_FREEZE]
        }
      ]
    });
   // 略去的代码...
   ```

3. 在“entry > src > main > ets” 路径下，新建faultlogextension/MyFaultLogExtensionAbility.ets文件。新建类MyFaultLogExtensionAbility继承FaultLogExtensionAbility，重写订阅功能相关的三个接口函数，代码示例如下：

   ```ts
   // 导入需要继承的类FaultLogExtensionAbility
   import { FaultLogExtensionAbility, hilog, hiAppEvent } from '@kit.PerformanceAnalysisKit';

   export default class MyFaultLogExtensionAbility extends FaultLogExtensionAbility {
    // 重写onConnect函数
    onConnect() {
      hilog.info(0x0000, 'testTag', `FaultLogExtensionAbility onConnect`);
    }

    // 重写onDisconnect函数
    onDisconnect() {
      hilog.info(0x0000, 'testTag', `FaultLogExtensionAbility onDisconnect`);
    }

    // 重写onFaultReportReady函数
    onFaultReportReady() {
      hilog.info(0x0000, 'testTag', `FaultLogExtensionAbility onFaultReportReady`);
     hiAppEvent.addWatcher({
      // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
      name: "watcher",
      // 开发者可以订阅感兴趣的系统事件，此处是订阅了应用冻屏事件
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.APP_FREEZE]
        }
      ],
      // 开发者可以自行实现订阅回调函数，以便对订阅获取到的事件数据进行自定义处理
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
            // 开发者可以获取到应用冻屏事件发生的时间戳
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params['time']}`);
            // 开发者可以获取到应用冻屏事件发生时应用的前后台状态
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.foreground=${eventInfo.params['foreground']}`);
            // 开发者可以获取到应用冻屏事件发生时应用的版本信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_version=${eventInfo.params['bundle_version']}`);
            // 开发者可以获取到应用冻屏事件发生时应用的包名
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_name=${eventInfo.params['bundle_name']}`);
            // 开发者可以获取到应用冻屏事件发生时应用的进程名称
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.process_name=${eventInfo.params['process_name']}`);
            // 开发者可以获取到应用冻屏事件发生时应用的进程id
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.pid=${eventInfo.params['pid']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params['uid']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uuid=${eventInfo.params['uuid']}`);
            // 开发者可以获取到应用冻屏事件发生的异常类型、异常原因
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.exception=${JSON.stringify(eventInfo.params['exception'])}`);
            // 开发者可以获取到应用冻屏事件发生时日志信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.hilog.size=${eventInfo.params['hilog'].length}`);
            // 开发者可以获取到应用冻屏事件发生时主线程未处理消息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler=${eventInfo.params['event_handler']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler_size_3s=${eventInfo.params['event_handler_size_3s']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler_size_6s=${eventInfo.params['event_handler_size_6s']}`);
            // 开发者可以获取到应用冻屏事件发生时同步binder调用信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.peer_binder=${eventInfo.params['peer_binder']}`);
            // 开发者可以获取到应用冻屏事件发生时全量线程调用栈
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.threads.size=${eventInfo.params['threads'].length}`);
            // 开发者可以获取到应用冻屏事件发生时内存信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.memory=${JSON.stringify(eventInfo.params['memory'])}`);
            // 开发者可以获取到应用冻屏事件发生时的故障日志文件
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.external_log=${JSON.stringify(eventInfo.params['external_log'])}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.log_over_limit=${eventInfo.params['log_over_limit']}`);
          }
        }
      }
    });
    }
   }
   ```

4. 编辑工程中的“entry > src > main > module.json5” 文件，新增相关的extensionAbility信息，文件新增修改的部分示例如下：

   ```
   "extensionAbilities": [
     {
       "name" : "MyFaultLogExtensionAbility",
       "srcEntry": "./ets/faultlogextension/MyFaultLogExtensionAbility.ets",
       "type": "faultLog"
     }
   ]
   ```

## 调测验证

点击DevEco Studio界面的运行按钮，启动应用工程。在应用界面点击“AppInput”按钮，触发崩溃事件。应用退出后，设备不得重启，等待30分钟左右。

在HiLog窗口搜索“testTag”关键字，查看FaultLogExtensionAbility执行回调函数的结果：

   ```text
   FaultLogExtensionAbility onConnect
   FaultLogExtensionAbility onFaultReportReady
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=APP_FREEZE
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_FREEZE
   HiAppEvent eventInfo.eventType=1
   ......
   FaultLogExtensionAbility onDisconnect
   ```
  表示FaultLogExtensionAbility依次执行连接、处理和断开。