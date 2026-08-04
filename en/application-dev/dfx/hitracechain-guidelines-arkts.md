# Using HiTraceChain (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @yu_haoqiaida-->
<!--Designer: @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=9e7305fd2d0bf3a25be65abfadf2e97b359f1ac7 translatedAt=2026-07-31T01:33:28.565Z pushedAt=2026-07-31T07:54:29.551Z -->

## Available APIs

The distributed tracing APIs are provided by the HiTraceChain module. For details about the APIs, see [@ohos.hiTraceChain (Distributed Tracing)](../reference/apis-performance-analysis-kit/js-apis-hitracechain.md).

| API| Description|
| -------- | -------- |
| hiTraceChain.begin(name: string, flags?: number = HiTraceFlag.DEFAULT): HiTraceId | Starts call chain tracing and returns the created **HiTraceId**.|
| hiTraceChain.end(id: HiTraceId): void | Stops call chain tracing.|
| hiTraceChain.getId(): HiTraceId | Obtains the trace ID.|
| hiTraceChain.setId(id: HiTraceId): void | Sets the trace ID.|
| hiTraceChain.clearId(): void | Clears the trace ID.|
| hiTraceChain.createSpan(): HiTraceId | Creates a trace span. Specifically, create a **HiTraceId**, use the **chainId** and **spanId** in the Thread-Local Storage (TLS) of the current thread to initialize the **chainId** and **parentSpanId** of the **HiTraceId**, generate a new **spanId** for the **HiTraceId**, and return the **HiTraceId**.|
| hiTraceChain.isValid(id: HiTraceId): boolean | Checks whether the **HiTraceId** is valid.<br>**true**: The HiTraceId is valid; **false**: The **HiTraceId** is invalid. |
| hiTraceChain.isFlagEnabled(id: HiTraceId, flag: HiTraceFlag): boolean | Checks whether the specified trace flag in the **HiTraceId** is enabled.<br>**true**: The specified trace flag is enabled; **false**: The specified trace flag is not enabled. |
| hiTraceChain.enableFlag(id: HiTraceId, flag: HiTraceFlag): void | Enables the trace flag specified in **HiTraceId**.|
| hiTraceChain.tracepoint(mode: HiTraceCommunicationMode, type: HiTraceTracepointType, id: HiTraceId, msg?: string): void | Adds a trace point for the HiTraceMeter logging.|

## How to Develop

For details about how to use HiTraceChain in ArkTS, see the following example. You can refer to [Constraints](hitracechain-intro.md#constraints) to understand the common mechanisms that support and do not support HiTraceChain automatic transfer.

1. Create a project in DevEco Studio and select **Empty Ability**. The project directory structure is as follows:

   ```txt
   ├── entry
   │   ├── src
   │       ├── main
   │       │   ├── ets
   │       │   │   ├── entryability
   │       │   │   │   └── EntryAbility.ets
   │       │   │   └── pages
   │       │   │       └── Index.ets
   ```

2. Edit the **entry &gt; src &gt; main &gt; ets &gt; pages &gt; Index.ets** file in the project:

   Import the required dependencies:

   <!-- @[TestHiTraceChain_Import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiTrace/HitraceChain_ArkTS/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   import { hiTraceChain, hilog } from '@kit.PerformanceAnalysisKit';
   ```

   Define the test methods:

   <!-- @[TestHiTraceChain_TestFunc](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiTrace/HitraceChain_ArkTS/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   function initTraceId() {
     let traceId = hiTraceChain.getId();
     if (!hiTraceChain.isValid(traceId)) {
       hilog.info(0x0000, 'testTag', 'HiTraceId is invalid, begin hiTraceChain');
       traceId = hiTraceChain.begin('testTag: hiTraceChain begin', hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
     } else if (!hiTraceChain.isFlagEnabled(traceId, hiTraceChain.HiTraceFlag.INCLUDE_ASYNC)) {
       hiTraceChain.enableFlag(traceId, hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
       hiTraceChain.setId(traceId);
     }
     return traceId;
   }
   
   async function test(index: number) {
     if (index > 0) {
       await test(index - 1)
       hilog.info(0x0000, 'testTag', `record with traceId at task ${index}`);
     }
   }
   
   function testHiTraceIdPassedAutomatically() {
     let traceId = initTraceId();
     hilog.info(0x0000, 'testTag', 'record with traceId at first task');
     test(10).then(()=>{
       hilog.info(0x0000, 'testTag', 'record with traceId at then function');
     })
     hiTraceChain.end(traceId);
     hilog.info(0x0000, 'testTag', 'hiTraceChain end in main thread');
   }
   
   function testHiTraceIdPassedManually() {
     let traceId = initTraceId();
     hilog.info(0x0000, 'testTag', 'start testHiTraceIdPassedManually async trace');
     setTimeout(() => {
       // Set the HiTraceId for the asynchronous scheduled task.
       hiTraceChain.setId(traceId);
       // Generate a branch identifier (spanId) for the asynchronous scheduled task.
       let traceIdTimeout = hiTraceChain.createSpan();
       // Set the HiTraceId with the spanId for the asynchronous scheduled task.
       hiTraceChain.setId(traceIdTimeout);
       hilog.info(0x0000, 'testTag', 'end testHiTraceIdPassedManually async trace');
     }, 100);
     hiTraceChain.end(traceId);
     hilog.info(0x0000, 'testTag', 'hiTraceChain end in main thread');
   }
   ```

   Add buttons to trigger API calls:

   <!-- @[TestHiTraceChain_Button](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiTrace/HitraceChain_ArkTS/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   Button("testHiTraceIdPassedAutomatically").backgroundColor('#FFFF00FF')
     .onClick(testHiTraceIdPassedAutomatically)
   
   Button("testHiTraceIdPassedManually").backgroundColor('#FFFF00FF')
     .onClick(testHiTraceIdPassedManually)
   ```

3. Click the **Run** button in DevEco Studio to run the app project, and filter logs by **testTag** in the HiLog logs:

   - Scenario where **HiTraceId** supports automatic transfer:

      Tap **testHiTraceIdPassedAutomatically** on the device to trigger the service logic. The following content is displayed in the HiLog logs: 

      ```text
      05-28 11:47:20.499   7439-7439     A00000/testTag                  com.examp...racedemo  I     HiTraceId is invalid, begin hiTraceChain
      05-28 11:47:20.500   7439-7439     A00000/testTag                  com.examp...racedemo  I     [a92ab104a53adf0, 32a835e, 0] record with traceId at first task
      05-28 11:47:20.509   7439-7439     A00000/testTag                  com.examp...racedemo  I     hiTraceChain end in main thread
      05-28 11:47:20.511   7439-7439     A00000/testTag                  com.examp...racedemo  I     [a92ab104a53adf0, 23e9386, 32a835e] record with traceId at task 1
      05-28 11:47:20.511   7439-7439     A00000/testTag                  com.examp...racedemo  I     [a92ab104a53adf0, 38a1eb2, 23e9386] record with traceId at task 2
      05-28 11:47:20.511   7439-7439     A00000/testTag                  com.examp...racedemo  I     [a92ab104a53adf0, 363113e, 38a1eb2] record with traceId at task 3
      05-28 11:47:20.511   7439-7439     A00000/testTag                  com.examp...racedemo  I     [a92ab104a53adf0, 3919396, 363113e] record with traceId at task 4
      05-28 11:47:20.511   7439-7439     A00000/testTag                  com.examp...racedemo  I     [a92ab104a53adf0, 2f5f6d7, 3919396] record with traceId at task 5
      05-28 11:47:20.511   7439-7439     A00000/testTag                  com.examp...racedemo  I     [a92ab104a53adf0, 3220957, 2f5f6d7] record with traceId at task 6
      05-28 11:47:20.512   7439-7439     A00000/testTag                  com.examp...racedemo  I     [a92ab104a53adf0, f3a42b, 3220957] record with traceId at task 7
      05-28 11:47:20.512   7439-7439     A00000/testTag                  com.examp...racedemo  I     [a92ab104a53adf0, b293a8, f3a42b] record with traceId at task 8
      05-28 11:47:20.512   7439-7439     A00000/testTag                  com.examp...racedemo  I     [a92ab104a53adf0, 2090dea, b293a8] record with traceId at task 9
      05-28 11:47:20.512   7439-7439     A00000/testTag                  com.examp...racedemo  I     [a92ab104a53adf0, 1b63a3e, 1b63a3e] record with traceId at task 10
      05-28 11:47:20.513   7439-7439     A00000/testTag                  com.examp...racedemo  I     [a92ab104a53adf0, 2df6e91, 2df6e91] record with traceId at then function
      ```

      - The information in the **[chainId spanId parentSpanId]** format appended before the HiLog log is the HiTraceId information. For example, **[a92ab104a53adf0 23e9386 32a835e]** indicates that the trace chain identifier **chainId** value is **a92ab104a53adf0**, the span identifier **spanId** value is **23e9386**, and the parent span identifier **parentSpanId** value is **32a835e**.

      - The trace chain identifier **chainId** value obtained in the example is **a92ab104a53adf0**. You can use the **chainId** value to filter logs and view the complete HiLog logs of the service call chain.

      - Both the **promise**/**then** and **async**/**await** asynchronous mechanisms automatically transfer **HiTraceId** and generate span identifiers. For example, **32a835e**, **23e9386**, and **38a1eb2** in the sample HiLog logs are span identifiers automatically generated for asynchronous tasks, and the generation chain of these span identifiers can be inferred from the **parentSpanId** information.

      - Both **hiTraceChain.end()** and **hiTraceChain.clear()** can end tracing. After tracing is ended, HiLog logs no longer carry **HiTraceId** information. For example, the log "hiTraceChain end in main thread" no longer carries **HiTraceId** information.

   - Scenario where **HiTraceId** does not support automatic transfer:

      Tap the **testHiTraceIdPassedManually** button on the device to trigger the service logic. The following content is displayed in the HiLog logs:

      ```text
      05-28 11:49:00.787   7439-7439     A00000/testTag                  com.examp...racedemo  I     HiTraceId is invalid, begin hiTraceChain
      05-28 11:49:00.788   7439-7439     A00000/testTag                  com.examp...racedemo  I     [a92ab4bb2cc0575, 0, 0] start testHiTraceIdPassedManually async trace
      05-28 11:49:00.789   7439-7439     A00000/testTag                  com.examp...racedemo  I     hiTraceChain end in main thread
      05-28 11:49:00.890   7439-7439     A00000/testTag                  com.examp...racedemo  I     [a92ab4bb2cc0575, 3b5f934, 0] end testHiTraceIdPassedManually async trace
      ```