# 事件订阅（ArkTS）

HiAppEvent提供了事件订阅接口，用于本地获取应用的事件。

## 接口说明

API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[@ohos.hiviewdfx.hiAppEvent (应用事件打点)ArkTS API文档](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md)。

**订阅接口功能介绍**：

| 接口名 | 描述 |
| -------- | -------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | 添加应用的事件观察者，以添加对应用的事件订阅。 |
| removeWatcher(watcher: Watcher): void | 移除应用的事件观察者，以移除对应用的事件订阅。 |

**打点接口功能介绍**：

| 接口名 | 描述 |
| -------- | -------- |
| write(info: AppEventInfo, callback: AsyncCallback&lt;void>): void | 应用事件异步打点方法，使用callback方式作为异步回调。 |
| write(info: AppEventInfo): Promise&lt;void> | 应用事件异步打点方法，使用Promise方式作为异步回调。 |

## 事件订阅开发指导

以订阅一个崩溃事件（系统事件）和一个按钮点击事件（应用事件）为例，说明开发步骤。

1. 新建一个ArkTS应用工程，编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，导入依赖模块：

   ```ts
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. 编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets” 文件，在onCreate函数中添加对崩溃事件、按钮点击事件的订阅。

   订阅崩溃事件，采用OnReceive类型观察者的订阅方式，观察者接收到事件后回立即触发OnReceive()回调。编辑"EntryAbility.ets"文件，定义OnReceive类型观察者相关方法：

   ```
   hiAppEvent.addWatcher({
     // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
     name: "AppCrashWatcher",
     // 订阅过滤条件，这里是订阅了系统事件中的崩溃事件
     appEventFilters: [
       {
         domain: hiAppEvent.domain.OS,
         names: [hiAppEvent.event.APP_CRASH]
       }
     ],
     // 实现onReceive回调，监听到事件后实时回调
     onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
       hilog.info(0x0000, 'testTag', `domain=${domain}`);
       for (const eventGroup of appEventGroups) {
         hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
         for (const eventInfo of eventGroup.appEventInfos) {
           // 开发者可以获取到崩溃事件发生的时间戳
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${JSON.stringify(eventInfo.params['time'])}`);
           // 开发者可以获取到崩溃应用的包名
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_name=${JSON.stringify(eventInfo.params['bundle_name'])}`);
           // 开发者可以获取到崩溃事件发生时的故障日志文件
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.external_log=${JSON.stringify(eventInfo.params['external_log'])}`);
         }
       }
     }
   });
   ```

   订阅按钮点击事件，采用OnTrigger类型观察者的订阅方式。需满足triggerCondition设置的条件，才能触发OnTrigger()回调。编辑 "EntryAbility.ets"文件，定义OnTrigger类型观察者相关方法：

   ```
   hiAppEvent.addWatcher({
     // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
     name: "ButtonClickWatcher",
     // 开发者可以订阅感兴趣的应用事件，此处是订阅了按钮事件
     appEventFilters: [{ domain: "button" }],
     // 开发者可以设置订阅回调触发的条件，此处是设置为事件打点数量满足1个
     triggerCondition: { row: 1 },
     // 开发者可以自行实现订阅回调函数，以便对订阅获取到的事件打点数据进行自定义处理
     onTrigger: (curRow: number, curSize: number, holder: hiAppEvent.AppEventPackageHolder) => {
       // 返回的holder对象为null，表示订阅过程发生异常，因此在记录错误日志后直接返回
       if (holder == null) {
         hilog.error(0x0000, 'testTag', "HiAppEvent holder is null");
         return;
       }
       hilog.info(0x0000, 'testTag', `HiAppEvent onTrigger: curRow=%{public}d, curSize=%{public}d`, curRow, curSize);
       let eventPkg: hiAppEvent.AppEventPackage | null = null;
       // 根据设置阈值大小（默认为1条事件）去获取订阅事件包，直到将订阅数据全部取出
       // 返回的事件包对象为null，表示当前订阅数据已被全部取出，此次订阅回调触发结束
       while ((eventPkg = holder.takeNext()) != null) {
         // 开发者可以对事件包中的事件打点数据进行自定义处理，此处是将事件打点数据打印在日志中
         hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.packageId=%{public}d`, eventPkg.packageId);
         hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.row=%{public}d`, eventPkg.row);
         hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.size=%{public}d`, eventPkg.size);
         for (const eventInfo of eventPkg.data) {
           hilog.info(0x0000, 'testTag', `HiAppEvent eventPkg.info=%{public}s`, eventInfo);
         }
       }
     }
   });
   ```

3. 编辑工程中的“entry > src > main > ets  > pages > Index.ets” 文件，导入依赖模块：

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

4. 编辑工程中的“entry > src > main > ets  > pages > Index.ets” 文件，新增"appCrash"按钮触发崩溃事件；新增"buttonClick"按钮，在按钮点击的函数中进行事件打点。示例代码如下：

   触发崩溃事件

   ```
     Button("appCrash")
       .onClick(()=>{
         // 在按钮点击函数中构造一个crash场景，触发应用崩溃事件
         let result: object = JSON.parse("");
       })
       .position({ x: 50, y: 100 }) // 设置按钮位置
   ```

   在按钮点击的函数中进行事件打点

   ```
     Button("buttonClick")
       .onClick(()=>{
         // 在按钮点击函数中进行事件打点，以记录按钮点击事件
         let eventParams: Record<string, number> = { 'click_time': 100 };
         let eventInfo: hiAppEvent.AppEventInfo = {
           // 事件领域定义
           domain: "button",
           // 事件名称定义
           name: "click",
           // 事件类型定义
           eventType: hiAppEvent.EventType.BEHAVIOR,
           // 事件参数定义
           params: eventParams
         };
         hiAppEvent.write(eventInfo).then(() => {
           hilog.info(0x0000, 'testTag', `HiAppEvent success to write event`);
         }).catch((err: BusinessError) => {
           hilog.error(0x0000, 'testTag', `HiAppEvent err.code: ${err.code}, err.message: ${err.message}`);
         });
         hilog.info(0x0000, 'testTag', `HiAppEvent write event`);
       })
       .position({ x: 50, y: 200 }) // 设置按钮的位置
   ```

## 调测验证

1. 点击DevEco Studio界面中的运行按钮，运行应用工程，然后在应用界面中点击按钮“appCrash”，触发一次崩溃事件。应用退出后再次打开应用。

2. 在HiLog窗口搜索“HiAppEvent”关键字，可以看到应用收到崩溃事件回调后对事件数据的处理日志：

   ```
   HiAppEvent eventName=APP_CRASH
   HiAppEvent eventInfo.params.time=1750747995874
   HiAppEvent eventInfo.params.bundle_name="com.example.txxxxx"
   HiAppEvent eventInfo.params.external_log=
   ["/data/storage/el2/log/hiappevent/APP_CRASH_1750747996042_28962.log"]
   ```

3. 点击DevEco Studio界面中的运行按钮，运行应用工程，然后在应用界面中点击按钮“buttonClick”，触发一次按钮点击事件并打点。

4. 在HiLog窗口搜索“HiAppEvent”关键字，可以看到应用收到按钮点击事件的回调后，对打点事件数据的处理日志：

   ```
   HiAppEvent write event
   HiAppEvent onTrigger: curRow=1, curSize=121
   HiAppEvent eventPkg.packageId=0
   HiAppEvent eventPkg.row=1
   HiAppEvent eventPkg.size=121
   HiAppEvent eventPkg.info={"domain_":"button","name_":"click","type_":4,"time_":1750754529033,"tz_":"","pid_":40664,"tid_":40664,"click_time":100}
   HiAppEvent success to write event
   ```
