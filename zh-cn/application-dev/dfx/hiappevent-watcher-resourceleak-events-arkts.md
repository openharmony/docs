# 订阅资源泄漏事件（ArkTS）

## 接口说明

API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[应用事件打点API文档](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md)。

| 接口名                                              | 描述                                         |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | 添加应用事件观察者，以添加对应用事件的订阅。 |
| removeWatcher(watcher: Watcher): void               | 移除应用事件观察者，以移除对应用事件的订阅。 |

## 开发步骤

以实现对发生内存泄漏场景生成的资源泄漏事件订阅为例，说明开发步骤。

1. 新建一个ArkTS应用工程，编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，导入依赖模块：

   ```ts
   import { hiAppEvent, hilog, hidebug } from '@kit.PerformanceAnalysisKit';
   ```

2. 编辑工程中的“entry > src > main > ets  > entryability > EntryAbility.ets”文件，在onCreate函数中添加系统事件的订阅，示例代码如下：

   ```ts
    hiAppEvent.addWatcher({
      // 开发者可以自定义观察者名称，系统会使用名称来标识不同的观察者
      name: "watcher",
      // 开发者可以订阅感兴趣的系统事件，此处是订阅了资源泄漏事件
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.RESOURCE_OVERLIMIT]
        }
      ],
      // 开发者可以自行实现订阅实时回调函数，以便对订阅获取到的事件数据进行自定义处理
      onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
        hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
        for (const eventGroup of appEventGroups) {
          // 开发者可以根据事件集合中的事件名称区分不同的系统事件
          hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
          for (const eventInfo of eventGroup.appEventInfos) {
            // 开发者可以获取到资源泄漏事件发生时内存信息
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.memory=${JSON.stringify(eventInfo)}`);
          }
        }
      }
    });
   ```

3. 编辑工程中的“entry > src > main > ets  > pages > Index.ets”文件，添加按钮并在其onClick函数构造资源泄漏场景，以触发资源泄漏事件。
   此处需要使用[hidebug.setAppResourceLimit](../reference/apis-performance-analysis-kit/js-apis-hidebug.md#hidebugsetappresourcelimit12)设置内存限制，造成内存内存泄漏，需要同步在“开发者选项”中打开“系统资源泄漏日志”，并重启设备。接口示例代码如下：

   ```ts
    import hidebug from "@ohos.hidebug";

    @Entry
    @Component
    struct Index {
      @State leakedArray: string[][] = [];

      build() {
        Column() {
          Row() {
            Column() {
              Button("pss leak")
                .onClick(() => {
                  hidebug.setAppResourceLimit("pss_memory", 1024, true);
                  for (let i = 0; i < 20 * 1024; i++) {
                    this.leakedArray.push(new Array(1).fill("leak"));
                  }
                })
            }
          }
          .height('100%')
          .width('100%')
        }
      }
    }
   ```

4. 点击DevEco Studio界面中的运行按钮，运行应用工程，等待15~30分钟，会上报应用内存泄漏事件。
   同一个应用，24小时内至多上报一次内存泄漏，如果短时间内要二次上报，需要重启设备。

5. 内存泄漏事件上报后，系统会回调应用的onReceive函数，可以在Log窗口看到对系统事件数据的处理日志：

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=RESOURCE_OVERLIMIT
   HiAppEvent eventInfo={"domain":"OS","name":"RESOURCE_OVERLIMIT","eventType":1,"params":{"bundle_name":"com.example.myapplication","bundle_version":"1.0.0","memory":{"pss":2100257,"rss":1352644,"sys_avail_mem":250272,"sys_free_mem":60004,"sys_total_mem":1992340,"vss":2462936},"pid":20731,"resource_type":"pss_memory","time":1502348798106,"uid":20010044,"external_log": ["/data/storage/el2/log/resourcelimit/RESOURCE_OVERLIMIT_1725614572401_6808.log", "/data/storage/el2/log/resourcelimit/RESOURCE_OVERLIMIT_1725614572412_6808.log"], "log_over_limit": false}}
   ```
