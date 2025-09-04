# Using HiTraceChain (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--Designer: @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## Available APIs

The APIs for distributed call chain tracing are provided by the HiTraceChain module. For details, see [@ohos.hiTraceChain (Distributed Tracing)](../reference/apis-performance-analysis-kit/js-apis-hitracechain.md).

| API| Description| 
| -------- | -------- |
| hiTraceChain.begin(name: string, flags?: number = HiTraceFlag.DEFAULT): HiTraceId | Starts call chain tracing and returns the created **HiTraceId**.| 
| hiTraceChain.end(id: HiTraceId): void | Stops call chain tracing.| 
| hiTraceChain.getId(): HiTraceId | Obtains the trace ID.| 
| hiTraceChain.setId(id: HiTraceId): void | Sets the trace ID.| 
| hiTraceChain.clearId(): void | Clears the trace ID.| 
| hiTraceChain.createSpan(): HiTraceId | Creates a trace span. Specifically, create a **HiTraceId**, use the **chainId** and **spanId** in the Thread-Local Storage (TLS) of the current thread to initialize the **chainId** and **parentSpanId** of the **HiTraceId**, generate a new **spanId** for the **HiTraceId**, and return the **HiTraceId**.| 
| hiTraceChain.isValid(id: HiTraceId): boolean | Checks whether the **HiTraceId** is valid.<br>The value **true** indicates that **HiTraceId** is valid, and **false** indicates the opposite.| 
| hiTraceChain.isFlagEnabled(id: HiTraceId, flag: HiTraceFlag): boolean | Checks whether the trace flag specified by **HiTraceId** is enabled.<br>The value **true** indicates that the specified trace flag is enabled, and **false** indicates the opposite.| 
| hiTraceChain.enableFlag(id: HiTraceId, flag: HiTraceFlag): void | Enables the trace flag specified in **HiTraceId**.| 
| hiTraceChain.tracepoint(mode: HiTraceCommunicationMode, type: HiTraceTracepointType, id: HiTraceId, msg?: string): void | Adds a trace point for the HiTraceMeter logging.| 


## How to Develop

For details about how to use HiTraceChain in ArkTS, see the following example. You can refer to [Constraints](hitracechain-intro.md#constraints) to understand the common mechanisms that support and do not support HiTraceChain automatic transfer.


### Using HiTraceChain in async/await and promise/then Asynchronous Tasks

The **async**/**await** and **promise**/**then** asynchronous tasks support automatic transfer of HiTraceChain. The following example describes how to use distributed tracing in ArkTS based on [Event Subscription (ArkTS)](hiappevent-watcher-app-events-arkts.md) and [Using HiTraceMeter (ArkTS)](hitracemeter-guidelines-arkts.md).

1. Create a project in DevEco Studio, select **Empty Ability**, and set the SDK version to 19 or later. (The HiTraceMeter APIs used in the sample project are supported since API version 19.) The project directory structure is as follows:
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

2. In the **entry/src/main/ets/pages/index.ets** file, use HiTraceChain to trace asynchronous tasks. The complete code is as follows:

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
               // Start distributed call chain tracing before the service starts.
               // INCLUDE_ASYNC indicates that HiTraceId is automatically transferred in the asynchronous mechanism supported by the system.
               let traceId = hiTraceChain.begin("testTag: hiTraceChain begin", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
               // Start HiTraceMeter synchronous logging. This API is supported since API version 19.
               hiTraceMeter.startSyncTrace(hiTraceMeter.HiTraceOutputLevel.COMMERCIAL, "onClick", this.message);
   
               // Log a button onclick event when the button is clicked.
               let eventParams: Record<string, number> = { 'click_time': 100 };
               let eventInfo: hiAppEvent.AppEventInfo = {
                 // Define the event domain.
                 domain: "button",
                 // Define the event name.
                 name: "click",
                 // Define the event type.
                 eventType: hiAppEvent.EventType.BEHAVIOR,
                 // Define the event parameters.
                 params: eventParams
               };
               hiAppEvent.write(eventInfo).then(() => {
                 hilog.info(0x0000, "testTag", "Succeeded in writing an app event");
                 // After the button click event is processed, disable the distributed tracing of the asynchronous processing span.
                 hiTraceChain.end(traceId);
                 hilog.info(0x0000, "testTag", "hiTraceChain end in hiAppEvent");
               }).catch((err: BusinessError) => {
                 hilog.error(0x0000, "testTag", `HiAppEvent err.code: ${err.code}, err.message: ${err.message}`);
                 // After the exception handling is complete, disable the distributed tracing of the asynchronous processing span.
                 hiTraceChain.end(traceId);
                 hilog.info(0x0000, "testTag", "hiTraceChain end in hiAppEvent");
               });
   
               // Create a Promise object to execute the random number generation task. If the random number is greater than 0.5, the result is returned. Otherwise, an exception is returned.
               const promise: Promise<number> = new Promise((resolve: Function, reject: Function) => {
                 hilog.info(0x0000, "testTag", "promise task");
                 const randomNumber: number = Math.random();
                 if (randomNumber > 0.5) {
                   resolve(randomNumber);
                 } else {
                   reject(new Error('Random number is too small'));
                 }
               });
   
               // Use the callback of the then method to process the execution result of the Promise object.
               promise.then((result: number) => {
                 // Executed when the operation is successful.
                 hilog.info(0x0000, "testTag", "Random number is %{public}d", result);
                 // After the callback processing is complete, disable the distributed tracing of the asynchronous processing span.
                 hiTraceChain.end(traceId);
                 hilog.info(0x0000, "testTag", "hiTraceChain end in promise/then");
               }).catch((error: BusinessError) => {
                 // Executed when the operation fails.
                 hilog.error(0x0000, "testTag", error.message);
                 // After the exception handling is complete, disable the distributed tracing of the asynchronous processing span.
                 hiTraceChain.end(traceId);
                 hilog.info(0x0000, "testTag", "hiTraceChain end in promise/then");
               });
   
               // Execute an async/await task.
               let res = test1();
               // Use the callback of the then method to process the execution result of the async task.
               res.then(() => {
                 hilog.info(0x0000, "testTag", "then task");
                 // Disable distributed tracing of the asynchronous processing span. This functionality is the same as that of hiTraceChain.end.
                 hiTraceChain.clearId();
                 hilog.info(0x0000, "testTag", "hiTraceChain end in async/await");
               });
   
               // End HiTraceMeter synchronous logging. This API is supported since API version 19.
               hiTraceMeter.finishSyncTrace(hiTraceMeter.HiTraceOutputLevel.COMMERCIAL);
               // Stop distributed call chain tracing when the service ends.
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

3. Click the **Run** button in DevEco Studio to run the project. In the **Terminal** window, run the following command to capture the application traces generated within 10 seconds and use the keyword **onClick** to filter the trace logs generated by **hiTraceMeter.startSyncTrace** and **hiTraceMeter.finishSyncTrace** in the sample code.

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace -t 10 app | grep onClick
   ```

4. Click the **clickTime=0** button on the device to trigger the service logic. (The operation must be completed within 10 seconds. Otherwise, the trace data cannot be captured in step 3.)

5. View the execution result.
   - If **clickTime=1** is displayed on the device screen, the button is clicked once and the service logic is triggered.
   - In the **Log** window of DevEco Studio, view the distributed tracing information.
      - All HiLog logs in this example use **testTag**. You can filter logs by the keyword **testTag** to view the HiLog logs printed by the service code.

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

      - The **[chainId spanId parentSpanId]** information added before the HiLog log is **HiTraceId** information. For example, **[a92ab116052648e 2ddfb70 3457eff]** indicates that the trace chain ID (**chainId**) is **a92ab116052648e**, the span ID (**spanId**) is **2ddfb70**, and the parent span ID (**parentSpanId**) is **3457eff**.
      - The **chainId** in the example is **a92ab116052648e**. You can use it to filter logs and view the complete HiLog logs of the service call chain.
      - The **promise**/**then** and **async**/**await** mechanisms automatically transfer **HiTraceId** and generate span IDs. For example, **3457eff**, **2ddfb70**, and **225a1d9** in the HiLog logs in the example are span IDs automatically generated by asynchronous tasks.
      - Both **hiTraceChain.end** and **hiTraceChain.clear** can end tracing. After tracing is ended, HiLog logs no longer carry **HiTraceId** information.

   - View the trace data in the **Terminal** window of DevEco Studio. During HiTraceChain tracing, the trace logs obtained from HiTraceMeter automatically carry **HiTraceId** information.

      ```txt
       e.myapplication-55451   (  55451) [010] .... 27164.174417: tracing_mark_write: B|55451|H:[a92ab116052648e,0,0]#onClick|M62|clickTime=1
      ```


### Using HiTraceChain in setInterval and setTimeout of Asynchronous Macro Tasks

**setInterval** and **setTimeout** of asynchronous macro tasks do not support HiTraceChain automatic transfer. The following example shows how to use the **hiTraceChain.getId** and **hiTraceChain.setId** APIs to transfer **HiTraceId** and how to use the **hiTraceChain.createSpan** API to create a branch ID for distributed tracing.

1. Create a project in DevEco Studio and select **Empty Ability**. The project directory structure is as follows:

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

2. In the **entry/src/main/ets/pages/index.ets** file of the project, use HiTraceChain to trace asynchronous tasks. The complete code is as follows:

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
               // Obtain the HiTraceId of the current thread.
               let traceId = hiTraceChain.getId();
               // If the traceId is invalid, enable distributed tracing for the current thread.
               if (!hiTraceChain.isValid(traceId)) {
                 hilog.info(0x0000, "testTag", "HiTraceId is invalid, begin hiTraceChain");
                 traceId = hiTraceChain.begin("testTag: hiTraceChain begin");
                 // Enable INCLUDE_ASYNC for traceId. INCLUDE_ASYNC indicates that HiTraceId is automatically transferred in the asynchronous mechanism supported by the system.
                 hiTraceChain.enableFlag(traceId, hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
                 // Set the HiTraceId with INCLUDE_ASYNC enabled to the current thread.
                 hiTraceChain.setId(traceId);
                 // Check whether INCLUDE_ASYNC is successfully enabled.
                 if (hiTraceChain.isFlagEnabled(hiTraceChain.getId(), hiTraceChain.HiTraceFlag.INCLUDE_ASYNC)) {
                   hilog.info(0x0000, "testTag", "HiTraceFlag INCLUDE_ASYNC is enabled");
                 }
               }
   
               const promise: Promise<number> = new Promise((resolve: Function, reject: Function) => {
                 // Create an asynchronous recurring scheduled task that runs every 1s.
                 let intervalID = setInterval(() => {
                   // Set HiTraceId for the current asynchronous recurring scheduled task.
                   hiTraceChain.setId(traceId);
                   const randomNumber: number = Math.random();
                   hilog.info(0x0000, "testTag", "Interval 1s: randomNumber is %{public}d", randomNumber);
                   // Disable distributed tracing for the current asynchronous recurring scheduled task.
                   hiTraceChain.end(traceId);
                 }, 1000)
   
                 // Create an asynchronous scheduled task to be executed 2.5s later and end the asynchronous recurring scheduled task.
                 setTimeout(() => {
                   // Set HiTraceId for the asynchronous scheduled task.
                   hiTraceChain.setId(traceId);
                   // Generate a spanId for the asynchronous scheduled task.
                   let traceIdTimeout = hiTraceChain.createSpan();
                   // Set HiTraceId with spanId for the asynchronous scheduled task.
                   hiTraceChain.setId(traceIdTimeout);
                   hilog.info(0x0000, 'testTag', "setTimeout 2.5s");
                   // End the asynchronous recurring scheduled task.
                   clearInterval(intervalID);
                   const randomNumber: number = Math.random();
                   if (randomNumber > 0.5) {
                     resolve(randomNumber);
                   } else {
                     reject(new Error('Random number is too small'));
                   }
                   // Disable distributed tracing for the asynchronous scheduled task.
                   hiTraceChain.end(traceId);
                 }, 2500)
               })
   
               promise.then((result: number) => {
                 // Executed when the operation is successful.
                 hilog.info(0x0000, 'testTag', "Random number is %{public}d", result);
                 // After the callback processing is complete, disable the distributed tracing of the asynchronous processing span.
                 hiTraceChain.end(traceId);
               }).catch((error: BusinessError) => {
                 // Executed when the operation fails.
                 hilog.error(0x0000, 'testTag', error.message);
                 // After the exception handling is complete, disable the distributed tracing of the asynchronous processing span.
                 hiTraceChain.end(traceId);
               });
   
               // Stop distributed call chain tracing when the service ends.
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

3. Click the **Run** button on DevEco Studio to run the application project. Click the **clickTime=0** button on the device to trigger the service logic.

4. View the execution result.
   - If **clickTime=1** is displayed on the device screen, the button is clicked once and the service logic is triggered.
   - In the **Log** window of DevEco Studio, view the distributed tracing information.
      - All HiLog logs in this example use **testTag**. You can filter logs by the keyword **testTag** to view the HiLog logs printed by the service code.

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

      - The **[chainId spanId parentSpanId]** information added before the HiLog log is **HiTraceId** information. For example, **[a92ab34b3c84ea7 dc842f 3cafdfd]** indicates that the trace chain ID (**chainId**) is **a92ab34b3c84ea7**, the span ID (**spanId**) is **dc842f**, and the parent span ID (**parentSpanId**) is **3cafdfd**.
      - The **chainId** value obtained in the example is **a92ab34b3c84ea7**. You can use is to filter logs and view the complete HiLog logs of the service call chain.
