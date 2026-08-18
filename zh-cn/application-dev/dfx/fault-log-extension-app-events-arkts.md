# 使用FaultLogExtensionAbility订阅事件

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @chenshi51-->
<!--Designer: @Maplestory91-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

从API version 21开始，可以在FaultLogExtensionAbility中使用HiAppEvent事件订阅接口，实现应用故障事件（仅包括[崩溃事件](./hiappevent-watcher-crash-events.md)和[应用冻屏事件](./hiappevent-watcher-freeze-events.md)）的延迟通知。应用因崩溃或冻屏退出后，无法启动或长时间未启动的场景下，可以不依赖应用启动实现故障事件信息的订阅回调。FaultLogExtensionAbility仅用于补充处理故障事件，不能替代[主进程](../application-models/process-model-overview.md#基本进程类型)正常启动时进行故障事件处理。

在应用发生崩溃或者冻屏事件30分钟后，系统拉起FaultLogExtensionAbility进程，实际拉起时间可能会因为系统调度有所延迟。该30分钟是设备在非休眠状态下累积的时间。测试时需要保持测试设备屏幕常亮，防止设备休眠。灭屏状态下设备可能会休眠，导致实际接收到回调的时间延长。

## 原理机制说明

FaultLogExtensionAbility的原理机制如下图所示：

![工作机制说明](figures/fault_log_extension_ability_1.PNG)

1. 主进程启动后，在主进程中添加事件观察者A和事件观察者B，其中A包含正常实现的回调处理函数以及事件订阅过滤条件[appEventFilter](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#appeventfilter)，应用发生故障后正常重启会由A的回调处理HiAppEvent事件；B的回调处理函数为空实现，仅用于生成需要保存的事件订阅过滤条件。
2. 事件观察者A和B的事件订阅过滤条件会被保存到应用沙箱中。当应用移除事件观察者时，应用沙箱中保存的相应观察者的事件订阅过滤条件也会被删除。
3. 应用业务运行过程中发生崩溃事件或应用冻屏事件。
4. 系统服务感知到应用故障后，采集应用故障信息。
5. 系统服务采集完应用故障现场信息后，应用退出。
6. 系统侧根据应用订阅的HiAppEvent订阅事件类型，将采集到的应用故障信息保存进应用的沙箱中。若应用及时重启，HiAppEvent检测到应用沙箱中的未回调处理的故障事件，并且这些事件满足事件观察者A的过滤条件，会触发事件观察者A的回调函数处理事件，由于事件观察者B的回调为空实现不会对相同事件重复处理。
7. 若应用在故障发生后未及时重启并处理故障事件，故障发生后系统服务会创建一个延时30分钟后执行的任务，用于拉起应用的FaultLogExtensionAbility进程。如果任务队列中已存在当前进程的延时拉起任务，则不再创建新的延时任务，无论事件是否已被处理，FaultLogExtensionAbility进程都会在10秒后退出。
8. 在FaultLogExtensionAbility进程中添加事件观察者B，该事件观察者B需要开发者自行实现正常的回调处理函数，且与之前主进程添加的事件观察者B同名。
9. 由于FaultLogExtensionAbility进程添加事件观察者B和主进程添加的事件观察者B同名，应用沙箱会覆盖之前保存的B的事件订阅过滤条件。
10. HiAppEvent检测到应用沙箱中存在未回调处理的故障事件，当这些故障事件满足FaultLogExtensionAbility进程中事件观察者B的过滤条件时，会触发事件观察者B的回调处理逻辑。沙箱中存储的未回调的事件信息，会在故障事件被回调处理后删除。

## 约束与限制

- FaultLogExtensionAbility被拉起后只有10s的时间用以完成故障处理。超时没有处理完成可以在[onDisconnect](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-FaultLogExtensionAbility.md#ondisconnect)中保存状态。

- 从开机或上次拉起FaultLogExtensionAbility后，应用首次触发崩溃或冻屏开始计时。在拉起FaultLogExtensionAbility前反复触发崩溃或冻屏事件均不会重新计时。计时30分钟后拉起FaultLogExtensionAbility进程。

- FaultLogExtensionAbility自身崩溃时，不会再次被系统服务拉起。

- 针对FaultLogExtensionAbility接口调用限制，详情请参考API中[约束限制](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-FaultLogExtensionAbility.md#约束限制)。

- FaultLogExtensionAbility进程中订阅的事件需要在主进程中使用HiAppEvent进行订阅。否则，可能会发生[FaultLogExtensionAbility进程没有接收到回调事件](#faultlogextensionability进程没有接收到回调事件)的问题。

- FaultLogExtensionAbility进程中仅订阅崩溃、应用冻屏事件，不订阅除这两类外的系统事件。否则，可能会发生[系统事件重复上报](#系统事件重复上报)的问题。

- 主进程用于延迟回调处理事件观察者B和非延迟处理的事件观察者A定义名字不能重复。否则，可能会发生[部分事件丢失](#部分事件丢失)的问题。

- 接入FaultLogExtensionAbility能力后，若应用故障发生后设备重启，重启后不会拉起FaultLogExtensionAbility进程。

## 接口说明

API接口使用说明，包括参数使用限制和具体取值范围。请参考[@ohos.hiviewdfx.FaultLogExtensionAbility (故障延迟通知)](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-FaultLogExtensionAbility.md)。

仅适用于Stage模型。

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
       Button("AppInput")
       .onClick(() => {
         let t = Date.now();
         while (Date.now() - t <= 15000) {}
       })
     }
   }
   ```

2. 编辑工程中的“entry > src > main > ets > entryability > EntryAbility.ets”文件，示例代码如下：

   ```ts
   // 导入hiAppEvent依赖模块
   import { hiAppEvent } from '@kit.PerformanceAnalysisKit';
       // 略去的代码...
       // 在onCreate函数中添加系统事件的订阅,观察者A
       hiAppEvent.addWatcher ({
          // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
          name: "EntryAbilityWatcherNormal",
          // 开发者可以订阅感兴趣的系统事件，此处是订阅了应用冻屏事件
          appEventFilters: [
              {
                  domain: hiAppEvent.domain.OS,
                  names: [hiAppEvent.event.APP_FREEZE]
              }
          ],
          // 故障发生后，正常重启执行观察者A处理事件回调
          onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
              // 略去的代码...
          }
       });
       // 在onCreate函数中添加系统事件的订阅，观察者B
       hiAppEvent.addWatcher ({
          // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
          name: "EntryAbilityWatcherExtension",
          // 开发者可以订阅感兴趣的系统事件，此处是订阅了应用冻屏事件
          appEventFilters: [
              {
                  domain: hiAppEvent.domain.OS,
                  names: [hiAppEvent.event.APP_FREEZE]
              }
          ],
          // 空实现，仅用于生成过滤规则，使故障事件在被处理前保留在应用沙箱内；
          // 若应用正常重启，观察者A已处理相同事件，观察者B通过空处理消耗从沙箱获取的事件，不对事件重复处理。
          onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {

          }
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
        // 观察者名称，保持与主进程事件观察者B一致
        name: "EntryAbilityWatcherExtension",
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
              // 开发者可以获取到应用冻屏事件发生时应用的唯一关联id
              hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.app_running_unique_id=${eventInfo.params['app_running_unique_id']}`);
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

   ```json5
   "extensionAbilities": [
     {
       "name" : "MyFaultLogExtensionAbility",
       "srcEntry": "./ets/faultlogextension/MyFaultLogExtensionAbility.ets",
       "type": "faultLog"
     }
   ]
   ```

## 调测验证

点击DevEco Studio界面的运行按钮，启动应用工程。在应用界面点击“AppInput”按钮，触发冻屏事件。应用退出后，应用和设备不得重启，等待30分钟左右。

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

## FaultLogExtensionAbility常见问题

### FaultLogExtensionAbility进程没有接收到回调事件

FaultLogExtensionAbility进程启动后，没有收到HiAppEvent订阅的回调。可能是以下原因导致：

- 在FaultLogExtensionAbility进程启动前，主进程已经订阅并处理了事件。
- 在FaultLogExtensionAbility进程中的订阅是应用安装后的首次订阅。HiAppEvent不感知在订阅操作前发生的事件，需要主进程中正常订阅相关事件，发生故障后HiAppEvent才会记录相关事件，在拉起FaultLogExtensionAbility后进行回调。

### 系统事件重复上报

系统事件将通过HiAppEvent回调通知所有订阅了该事件的事件观察者。当FaultLogExtensionAbility进程与主进程同时存在，并且均订阅了同一个系统事件时，触发该系统事件后，两个进程皆将接收到相应的事件回调。

### 部分事件丢失

在应用启动之后，事件观察者注册之前发生的事件丢失。检查是否注册了多个同名的事件观察者。

为了保障事件不丢失，HiAppEvent在应用启动后，事件观察者注册前会先扫描应用上次退出前未移除的事件观察者的订阅过滤条件，并据此对事件进行订阅保存。重复注册相同名称的事件观察者，后一次注册的事件观察者信息会覆盖前一次的事件观察者信息，导致订阅过滤条件被覆盖，事件丢失。
