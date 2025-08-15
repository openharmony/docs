# 使用HiTraceChain打点（ArkTS）

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--Designer: @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 接口说明

分布式跟踪接口由HiTraceChain模块提供，详细API请参考[分布式跟踪ArkTS API](../reference/apis-performance-analysis-kit/js-apis-hitracechain.md)。

| 接口名 | 描述 | 
| -------- | -------- |
| hiTraceChain.begin(name: string, flags?: number = HiTraceFlag.DEFAULT): HiTraceId | 开始跟踪，并返回创建的HiTraceId。 | 
| hiTraceChain.end(id: HiTraceId): void | 结束跟踪。 | 
| hiTraceChain.getId(): HiTraceId | 获取跟踪标识。 | 
| hiTraceChain.setId(id: HiTraceId): void | 设置跟踪标识。 | 
| hiTraceChain.clearId(): void | 清除跟踪标识。 | 
| hiTraceChain.createSpan(): HiTraceId | 创建跟踪分支。创建一个HiTraceId，使用当前线程TLS中的chainId、spanId初始化HiTraceId的chainId、parentSpanId，并为HiTraceId生成一个新的spanId，返回该HiTraceId。 | 
| hiTraceChain.isValid(id: HiTraceId): boolean | 判断HiTraceId是否有效。<br/>true：HiTraceId有效；false：HiTraceId无效。 | 
| hiTraceChain.isFlagEnabled(id: HiTraceId, flag: HiTraceFlag): boolean | 判断HiTraceId中指定的跟踪标志是否已启用。<br/>true：指定的跟踪标志已启用；false：指定的跟踪标志未启用。 | 
| hiTraceChain.enableFlag(id: HiTraceId, flag: HiTraceFlag): void | 启用HiTraceId中指定的跟踪标志。 | 
| hiTraceChain.tracepoint(mode: HiTraceCommunicationMode, type: HiTraceTracepointType, id: HiTraceId, msg?: string): void | HiTraceMeter打点信息埋点。 | 


## 开发步骤

HiTraceChain在ArkTS中的使用方法参考以下示例，开发者可参考[约束与限制](hitracechain-intro.md#约束与限制)，了解常见的支持与不支持HiTraceChain自动传递的机制。


### async/await和promise/then异步任务中使用HiTraceChain

async/await和promise/then异步任务支持HiTraceChain自动传递，示例结合[应用事件订阅](hiappevent-watcher-app-events-arkts.md)和[HiTraceMeter性能跟踪](hitracemeter-guidelines-arkts.md)，说明分布式跟踪在ArkTS中的使用方法。

1. 在DevEco Studio中新建工程，选择“Empty Ability”，SDK版本选择19及以上（示例工程使用的HiTraceMeter接口从API version 19开始支持），工程的目录结构如下：
   ```txt
   ├── entry
   │   ├── src
   │       ├── main
   │       │   ├── ets
   │       │   │   ├── entryability
   │       │   │   │   └── EntryAbility.ets
   │       │   │   ├── entrybackupability
   │       │   │   │   └── EntryBackupAbility.ets
   │       │   │   └── pages
   │       │   │       └── Index.ets
   ```

2. 编辑“entry &gt; src &gt; main &gt; ets &gt; pages &gt; Index.ets”文件，使用HiTraceChain跟踪异步任务，完整的示例代码如下：

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hiAppEvent, hilog, hiTraceChain, hiTraceMeter } from '@kit.PerformanceAnalysisKit';
   
   async function test3() {
     hilog.info(0x0000, "testTag", "test3");
   }
   
   async function test2() {
     hilog.info(0x0000, "testTag", "test2");
   }
   
   async function test1() {
     hilog.info(0x0000, 'testTag', "test1_1");
     await test2();
     hilog.info(0x0000, 'testTag', "test1_2");
     await test3();
     hilog.info(0x0000, 'testTag', "test1_3");
   }
   
   @Entry
   @Component
   struct Index {
     @State message: string = "clickTime=0";
     @State clickTime: number = 0;
   
     build() {
       Row() {
         Column() {
           Button(this.message)
             .fontSize(20)
             .margin(5)
             .width(350)
             .height(60)
             .fontWeight(FontWeight.Bold)
             .onClick(() => {
               this.clickTime++;
               this.message = "clickTime=" + this.clickTime;
               // 业务开始前，开启分布式跟踪
               // INCLUDE_ASYNC表示会在系统支持的异步机制里自动传递HiTraceId
               let traceId = hiTraceChain.begin("testTag: hiTraceChain begin", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
               // 开始HiTraceMeter同步打点，该接口API version 19开始支持
               hiTraceMeter.startSyncTrace(hiTraceMeter.HiTraceOutputLevel.COMMERCIAL, "onClick", this.message);
   
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
                 hilog.info(0x0000, "testTag", "Succeeded in writing an app event");
                 // 按钮点击事件处理结束，关闭异步处理分支的分布式跟踪
                 hiTraceChain.end(traceId);
                 hilog.info(0x0000, "testTag", "hiTraceChain end in hiAppEvent");
               }).catch((err: BusinessError) => {
                 hilog.error(0x0000, "testTag", `HiAppEvent err.code: ${err.code}, err.message: ${err.message}`);
                 // 异常处理结束，关闭异步处理分支的分布式跟踪
                 hiTraceChain.end(traceId);
                 hilog.info(0x0000, "testTag", "hiTraceChain end in hiAppEvent");
               });
   
               // 创建Promise对象执行随机数生成任务，若随机数大于0.5，则正常返回结果，反之则返回异常信息
               const promise: Promise<number> = new Promise((resolve: Function, reject: Function) => {
                 hilog.info(0x0000, "testTag", "promise task");
                 const randomNumber: number = Math.random();
                 if (randomNumber > 0.5) {
                   resolve(randomNumber);
                 } else {
                   reject(new Error('Random number is too small'));
                 }
               });
   
               // then方法的回调函数处理Promise对象的执行结果
               promise.then((result: number) => {
                 // 成功时执行
                 hilog.info(0x0000, "testTag", "Random number is %{public}d", result);
                 // 回调函数处理结束，关闭异步处理分支的分布式跟踪
                 hiTraceChain.end(traceId);
                 hilog.info(0x0000, "testTag", "hiTraceChain end in promise/then");
               }).catch((error: BusinessError) => {
                 // 失败时执行
                 hilog.error(0x0000, "testTag", error.message);
                 // 异常处理结束，关闭异步处理分支的分布式跟踪
                 hiTraceChain.end(traceId);
                 hilog.info(0x0000, "testTag", "hiTraceChain end in promise/then");
               });
   
               // 执行async/await异步任务
               let res = test1();
               // then方法的回调函数处理异步任务的执行结果
               res.then(() => {
                 hilog.info(0x0000, "testTag", "then task");
                 // 功能同hiTraceChain.end，关闭异步处理分支的分布式跟踪
                 hiTraceChain.clearId();
                 hilog.info(0x0000, "testTag", "hiTraceChain end in async/await");
               });
   
               // 结束HiTraceMeter同步打点，该接口API version 19开始支持
               hiTraceMeter.finishSyncTrace(hiTraceMeter.HiTraceOutputLevel.COMMERCIAL);
               // 业务结束后，关闭分布式跟踪
               hiTraceChain.end(traceId);
               hilog.info(0x0000, "testTag", "hiTraceChain end in main thread");
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

3. 点击DevEco Studio界面中的运行按钮，运行应用工程。在DevEco Studio Terminal窗口中执行以下命令，捕获10秒内的应用trace，并使用关键字“onClick”过滤示例代码中hiTraceMeter.startSyncTrace和hiTraceMeter.finishSyncTrace生成的trace日志。

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace -t 10 app | grep onClick
   ```

4. 点击设备上的“clickTime=0”按钮（需在10秒内完成，否则步骤3捕获不到trace数据），触发业务逻辑。

5. 查看运行结果。
   - 设备屏幕上按钮显示“clickTime=1”，表示点击了按钮一次，已触发业务逻辑。
   - 在DevEco Studio Log窗口查看分布式跟踪的相关信息。
      - 示例所有hilog打印均使用了“testTag”，因此可以使用关键字“testTag”过滤日志，查看该业务代码打印的hilog日志。

         ```txt
         06-04 17:46:45.156   55451-55451   C02D33/com.exa...tion/HiTraceC  com.examp...lication  I     [a92ab116052648e 0 0]HiTraceBegin name:testTag: hiTraceChain begin flags:0x01.
         06-04 17:46:45.157   55451-55451   A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab116052648e 0 0]promise task
         06-04 17:46:45.158   55451-55451   A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab116052648e 0 0]test1_1
         06-04 17:46:45.158   55451-55451   A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab116052648e 0 0]test2
         06-04 17:46:45.158   55451-55451   A00000/com.exa...ation/testTag  com.examp...lication  I     hiTraceChain end in main thread
         06-04 17:46:45.158   55451-55451   A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab116052648e 3457eff 0]test1_2
         06-04 17:46:45.158   55451-55451   A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab116052648e 3457eff 0]test3
         06-04 17:46:45.158   55451-55451   A00000/com.exa...ation/testTag  com.examp...lication  E     [a92ab116052648e 1bb5a1b 35d9c46]Random number is too small
         06-04 17:46:45.158   55451-55451   A00000/com.exa...ation/testTag  com.examp...lication  I     hiTraceChain end in promise/then
         06-04 17:46:45.158   55451-55451   A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab116052648e 2ddfb70 3457eff]test1_3
         06-04 17:46:45.158   55451-55451   A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab116052648e 225a1d9 2ddfb70]then task
         06-04 17:46:45.158   55451-55451   A00000/com.exa...ation/testTag  com.examp...lication  I     hiTraceChain end in async/await
         06-04 17:46:45.163   55451-55451   A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab116052648e 3a75cb2 520a92]Succeeded in writing an app event
         06-04 17:46:45.163   55451-55451   A00000/com.exa...ation/testTag  com.examp...lication  I     hiTraceChain end in hiAppEvent
         ```

      - hilog日志前附加的[chainId spanId parentSpanId]格式的信息即为HiTraceId信息，例如[a92ab116052648e 2ddfb70 3457eff]表示跟踪链标识chainId值为a92ab116052648e，分支标识spanId值为2ddfb70，父分支标识parentSpanId值为3457eff。
      - 示例得到的跟踪链标识chainId值为a92ab116052648e，可使用chainId值过滤日志，查看业务完整的调用链hilog日志。
      - promise/then和async/await异步机制都会自动传递HiTraceId，并生成分支标识，例如示例hilog日志中的3457eff、2ddfb70、225a1d9等，均为异步任务自动生成的分支标识。
      - hiTraceChain.end和hiTraceChain.clear都可以结束跟踪，跟踪结束后，hilog日志不再携带HiTraceId信息。

   - 在DevEco Studio Terminal窗口查看trace数据，HiTraceChain跟踪开启期间，HiTraceMeter打点得到的trace日志会自动携带HiTraceId信息。

      ```txt
       e.myapplication-55451   (  55451) [010] .... 27164.174417: tracing_mark_write: B|55451|H:[a92ab116052648e,0,0]#onClick|M62|clickTime=1
      ```


### 异步宏任务setInterval和setTimeout中使用HiTraceChain

异步宏任务setInterval和setTimeout不支持HiTraceChain自动传递，以下示例说明如何使用hiTraceChain.getId、hiTraceChain.setId接口传递HiTraceId，如何使用hiTraceChain.createSpan接口创建分支标识，进行分布式跟踪。

1. 在DevEco Studio中新建工程，选择“Empty Ability”，工程的目录结构如下：

   ```txt
   ├── entry
   │   ├── src
   │       ├── main
   │       │   ├── ets
   │       │   │   ├── entryability
   │       │   │   │   └── EntryAbility.ets
   │       │   │   ├── entrybackupability
   │       │   │   │   └── EntryBackupAbility.ets
   │       │   │   └── pages
   │       │   │       └── Index.ets
   ```

2. 编辑工程中的“entry &gt; src &gt; main &gt; ets &gt; pages &gt; Index.ets”文件，使用HiTraceChain跟踪异步任务，完整的示例代码如下：

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog, hiTraceChain } from '@kit.PerformanceAnalysisKit';
   
   @Entry
   @Component
   struct Index {
     @State message: string = "clickTime=0";
     @State clickTime: number = 0;
   
     build() {
       Row() {
         Column() {
           Button(this.message)
             .fontSize(20)
             .margin(5)
             .width(350)
             .height(60)
             .fontWeight(FontWeight.Bold)
             .onClick(() => {
               this.clickTime++;
               this.message = "clickTime=" + this.clickTime;
               // 获取当前线程的HiTraceId
               let traceId = hiTraceChain.getId();
               // 如果traceId无效，为当前线程开启分布式跟踪
               if (!hiTraceChain.isValid(traceId)) {
                 hilog.info(0x0000, "testTag", "HiTraceId is invalid, begin hiTraceChain");
                 traceId = hiTraceChain.begin("testTag: hiTraceChain begin");
                 // 使能traceId的INCLUDE_ASYNC，INCLUDE_ASYNC表示会在系统支持的异步机制里自动传递HiTraceId
                 hiTraceChain.enableFlag(traceId, hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
                 // 将使能INCLUDE_ASYNC的HiTraceId设置到当前线程
                 hiTraceChain.setId(traceId);
                 // 查询INCLUDE_ASYNC是否设置成功
                 if (hiTraceChain.isFlagEnabled(hiTraceChain.getId(), hiTraceChain.HiTraceFlag.INCLUDE_ASYNC)) {
                   hilog.info(0x0000, "testTag", "HiTraceFlag INCLUDE_ASYNC is enabled");
                 }
               }
   
               const promise: Promise<number> = new Promise((resolve: Function, reject: Function) => {
                 // 创建异步重复定时任务，每1s执行一次
                 let intervalID = setInterval(() => {
                   // 为当前异步重复定时任务设置HiTraceId
                   hiTraceChain.setId(traceId);
                   const randomNumber: number = Math.random();
                   hilog.info(0x0000, "testTag", "Interval 1s: randomNumber is %{public}d", randomNumber);
                   // 关闭当前异步重复定时任务的分布式跟踪
                   hiTraceChain.end(traceId);
                 }, 1000)
   
                 // 创建异步定时任务，2.5s后执行，结束异步重复定时任务
                 setTimeout(() => {
                   // 为异步定时任务设置HiTraceId
                   hiTraceChain.setId(traceId);
                   // 为异步定时任务生成分支标识spanId
                   let traceIdTimeout = hiTraceChain.createSpan();
                   // 为异步定时任务设置带spanId的HiTraceId
                   hiTraceChain.setId(traceIdTimeout);
                   hilog.info(0x0000, 'testTag', "setTimeout 2.5s");
                   // 结束异步重复定时任务
                   clearInterval(intervalID);
                   const randomNumber: number = Math.random();
                   if (randomNumber > 0.5) {
                     resolve(randomNumber);
                   } else {
                     reject(new Error('Random number is too small'));
                   }
                   // 关闭异步定时任务的分布式跟踪
                   hiTraceChain.end(traceId);
                 }, 2500)
               })
   
               promise.then((result: number) => {
                 // 成功时执行
                 hilog.info(0x0000, 'testTag', "Random number is %{public}d", result);
                 // 回调函数处理结束，关闭异步处理分支的分布式跟踪
                 hiTraceChain.end(traceId);
               }).catch((error: BusinessError) => {
                 // 失败时执行
                 hilog.error(0x0000, 'testTag', error.message);
                 // 异常处理结束，关闭异步处理分支的分布式跟踪
                 hiTraceChain.end(traceId);
               });
   
               // 业务结束后，关闭分布式跟踪
               hiTraceChain.end(traceId);
               hilog.info(0x0000, "testTag", "hiTraceChain end in main thread");
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

3. 点击DevEco Studio界面中的运行按钮，运行应用工程，点击设备上“clickTime=0”按钮，触发业务逻辑。

4. 查看运行结果。
   - 设备屏幕上按钮显示“clickTime=1”，表示点击了按钮一次，已触发业务逻辑。
   - 在DevEco Studio Log窗口查看分布式跟踪的相关信息。
      - 示例所有hilog打印均使用了“testTag”，因此可以使用关键字“testTag”过滤日志，查看该业务代码打印的hilog日志。

         ```txt
         06-05 15:46:04.544   49568-49568   A00000/com.exa...ation/testTag  com.examp...lication  I     HiTraceId is invalid, begin hiTraceChain
         06-05 15:46:04.544   49568-49568   C02D33/com.exa...tion/HiTraceC  com.examp...lication  I     [a92ab34b3c84ea7 0 0]HiTraceBegin name:testTag: hiTraceChain begin flags:0x00.
         06-05 15:46:04.544   49568-49568   A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab34b3c84ea7 0 0]HiTraceFlag INCLUDE_ASYNC is enabled
         06-05 15:46:04.544   49568-49568   A00000/com.exa...ation/testTag  com.examp...lication  I     hiTraceChain end in main thread
         06-05 15:46:05.547   49568-49568   A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab34b3c84ea7 0 0]Interval 1s: randomNumber is 0.863610
         06-05 15:46:06.548   49568-49568   A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab34b3c84ea7 0 0]Interval 1s: randomNumber is 0.365460
         06-05 15:46:07.047   49568-49568   A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab34b3c84ea7 3cafdfd 0]setTimeout 2.5s
         06-05 15:46:07.048   49568-49568   A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab34b3c84ea7 dc842f 3cafdfd]Random number is 0.524236
         ```

      - hilog日志前附加的[chainId spanId parentSpanId]格式的信息即为HiTraceId信息，例如[a92ab34b3c84ea7 dc842f 3cafdfd]表示跟踪链标识chainId值为a92ab34b3c84ea7，分支标识spanId值为dc842f，父分支标识parentSpanId值为3cafdfd。
      - 示例得到的chainId值为a92ab34b3c84ea7，可使用chainId值过滤日志，查看业务完整的调用链hilog日志。
