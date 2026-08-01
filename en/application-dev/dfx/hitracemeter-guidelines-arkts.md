# Using HiTraceMeter (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @yu_haoqiaida-->
<!--Designer: @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=9e7305fd2d0bf3a25be65abfadf2e97b359f1ac7 translatedAt=2026-07-31T01:34:59.209Z pushedAt=2026-07-31T08:04:56.296Z -->

## Overview

HiTraceMeter provides APIs for system performance tracing. You can call the APIs at key code to track processes and check system and application performance.

## Available APIs

The performance tracing APIs are provided by the HiTraceMeter module. For details about the APIs, see [@ohos.hiTraceMeter (Performance Tracing)](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md).

| API| Description|
| -------- | -------- |
| hiTraceMeter.startSyncTrace(level: HiTraceOutputLevel, name: string, customArgs?: string): void | Starts a synchronous time slice tracking event with hierarchical control of trace output.<br>**Note:** This API is supported since API version 19. |
| hiTraceMeter.finishSyncTrace(level: HiTraceOutputLevel): void | Ends a synchronous time slice tracking event with hierarchical control of trace output.<br>The value of **level** must be the same as that passed to the corresponding `startSyncTrace()` call.<br>**Note:** This API is supported since API version 19. |
| hiTraceMeter.startAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number, customCategory: string, customArgs?: string): void | Starts an asynchronous time slice tracking event with hierarchical control of trace output.<br>**taskId** is an ID used to indicate correlation in the trace. If multiple tasks with the same **name** run in parallel, you must pass a different **taskId** each time you call `startAsyncTrace()`. If tasks with the same **name** run serially, the same **taskId** can be used.<br>**Note:** This API is supported since API version 19. |
| hiTraceMeter.finishAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number): void | Ends an asynchronous time slice tracking event with hierarchical control of trace output.<br>The values of **level**, **name**, and **taskId** must be the same as those passed to the corresponding `startAsyncTrace()` call.<br>**Note:** This API is supported since API version 19. |
| hiTraceMeter.traceByValue(level: HiTraceOutputLevel, name: string, count: number): void | Creates an integer trace event with hierarchical control of trace output.<br>The **name** and **count** parameters are used to mark the name and integer value of a traced integer variable, respectively.<br>**Note:** This API is supported since API version 19. |
| hiTraceMeter.isTraceEnabled(): boolean | Checks whether app trace capture is currently enabled.<br>Returns **true** when capture is enabled through the hitrace CLI tool or other means. Returns **false** when capture is not enabled or has been stopped, in which case calling the HiTraceMeter performance tracing APIs has no effect.<br>**Note:** This API is supported since API version 19. |
| hiTraceMeter.registerTraceListener(callback: TraceEventListener): number | Registers a callback for app trace capture switch notifications. This API uses an asynchronous callback to return the result.<br>Upon successful registration, the callback is executed immediately once. Subsequent callback executions are triggered by changes in the app trace capture switch state.<br>**Note:** This API is supported since API version 22. |
| hiTraceMeter.unregisterTraceListener(index: number): number | Unregisters the callback for app trace capture switch notifications.<br>**Note:** This API is supported since API version 22. |

> **NOTE**
>
> The vertical bar (|) is used as the separator in [user-mode trace format](hitracemeter-view.md#user-mode-trace-format). Therefore, the string parameters passed by the HiTraceMeter APIs must exclude this character to avoid trace parsing exceptions.

### API Types

HiTraceMeter APIs are classified into three types: synchronous timeslice tracing APIs, asynchronous timeslice tracing APIs, and integer tracing APIs. HiTraceMeter APIs are synchronous. The synchronous and asynchronous modes describe the traced services. The synchronous timeslice tracing APIs are used for synchronous services, and the asynchronous timeslice tracing APIs are used for asynchronous services. HiTraceMeter APIs can be used with [HiTraceChain](hitracechain-guidelines-arkts.md) to associate and analyze logging across devices, processes, or threads.

### Use Scenarios

- Synchronous timeslice tracing APIs:

  The **startSyncTrace()** and **finishSyncTrace()** APIs must be used sequentially for logging during sequential execution. If they are not called in the correct order, the trace file will appear abnormal in visualization tools such as SmartPerf.

- Asynchronous timeslice tracing APIs:

  The **startAsyncTrace()** API is called to start logging before an asynchronous operation is performed, and the **finishAsyncTrace()** API is called to end logging after the asynchronous operation is performed.

  During trace parsing, different asynchronous traces are identified by the **name** and **taskId** parameters. These two APIs must be used in sequence as a pair, with the same **name** and **taskId** passed.

  Different **name** and **taskId** values must be used for different asynchronous processes. However, the same **name** and **taskId** values can be used if asynchronous processes do not occur at the same time.

  If the API is called incorrectly, the trace file will appear abnormal in visualization tools such as SmartPerf.

- Integer tracing APIs:

  The APIs are used to trace integer variables. The **traceByValue()** API is called when integer values change. You can view the change in the lane diagram of SmartPerf. The values during the interval between the start of data collection and the first logging cannot be viewed.

### Parameter Description

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| level | enum | Yes | Trace output level. Traces below the system threshold will not be output.<br>The threshold defaults to `INFO` for the log version and `COMMERCIAL` for the nolog version. |
| name | string | Yes| Name of the task or integer variable to trace.|
| taskId | number | Yes| Task ID. If multiple tasks with the same **name** are executed at the same time, you must set different **taskId** when calling **startAsyncTrace()**.|
| count | number | Yes| Value of an integer variable.|
| customCategory | string | Yes | Custom cluster name, used to cluster asynchronous tracing events of the same category.<br>If clustering is not required, pass an empty string. |
| customArgs | string | No | Custom key-value pair. If there are multiple key-value pairs, separate them with commas, for example, "key1=value1,key2=value2".<br>If this parameter is not required, you can omit it or pass an empty string. |
| callback | (boolean) => void | Yes| Registered callback.|
| index | number | Yes| Callback index returned by **registerTraceListener()**.|

> **NOTE**
>
> The total length of a [user-mode trace](hitracemeter-view.md#user-mode-trace-format) is limited to 512 characters, and any excess will be truncated. It is recommended that the combined length of the `name`, `customCategory`, and `customArgs` fields does not exceed 420 characters to avoid trace truncation.

## How to Develop

The following is an example of an ArkTS application that uses the HiTraceMeter APIs.

### Step 1: Creating a Project

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

   <!-- @[TestHiTraceMeter_Import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiTrace/HitraceMeter_ArkTS/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   import { hiTraceMeter, hilog} from '@kit.PerformanceAnalysisKit';
   ```

   Define the test methods:

   <!-- @[TestHiTraceMeter_FUNC](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiTrace/HitraceMeter_ArkTS/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   function testHiTraceMeterASync() {
     const COMMERCIAL = hiTraceMeter.HiTraceOutputLevel.COMMERCIAL;
     hiTraceMeter.startAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1001, 'categoryTest', 'key=value');
     hiTraceMeter.startAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1002, 'categoryTest', 'key=value');
   
     setTimeout(() => {
       // End the asynchronous trace task with taskId 1001.
       hiTraceMeter.finishAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1001);
     }, 2000);
   
     setTimeout(() => {
       // End the asynchronous trace task with taskId 1002.
       hiTraceMeter.finishAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1002);
     }, 1000);
   }
   
   function testHiTraceMeterSync() {
     const COMMERCIAL = hiTraceMeter.HiTraceOutputLevel.COMMERCIAL;
     // Start the synchronous trace task.
     hiTraceMeter.startSyncTrace(COMMERCIAL, 'myTestSyncTrace', 'key=value');
     // Business process.
     hilog.info(0x0000, 'testTrace', 'myTraceTest running, synchronizing trace');
     // End the synchronous trace task.
     hiTraceMeter.finishSyncTrace(COMMERCIAL);
   }
   
   function testHiTraceMeterValue() {
     const COMMERCIAL = hiTraceMeter.HiTraceOutputLevel.COMMERCIAL;
     let traceCount = 0;
     // Initial value of the trace count.
     hiTraceMeter.traceByValue(COMMERCIAL, 'myTestCountTrace', traceCount);
     traceCount++;
     // Trace count value after the change.
     hiTraceMeter.traceByValue(COMMERCIAL, 'myTestCountTrace', traceCount);
   }
   
   function testHiTraceMeter() {
     // Avoid performance overhead in this part when app trace capture is not enabled.
     if (hiTraceMeter.isTraceEnabled()) {
       testHiTraceMeterASync();
       testHiTraceMeterSync();
       testHiTraceMeterValue();
     } else {
       hilog.info(0x0000, 'testTrace', 'myTraceTest running, trace is not enabled');
     }
   }
   ```

   Add buttons to trigger API calls:

   <!-- @[TestHiTraceMeter_BUTTON](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiTrace/HitraceMeter_ArkTS/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   Button("testHiTraceMeter").backgroundColor('#FFFF00FF')
     .onClick(testHiTraceMeter)
   ```

### Step 2: Collecting and Viewing Trace Information

1. Run the following command in DevEco Studio Terminal to enable trace capture:

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```

2. Click the run button on the DevEco Studio interface to start the app. Tap the **testHiTraceMeter** button on the app screen to execute the service logic that includes HiTraceMeter tracing. Then run the following command to capture trace data and use the keyword "myTest" to filter the trace data (the `name` field passed by the sample tracing APIs all use the prefix "myTest").

   ```shell
   $ hitrace --trace_dump | grep myTest
   ```

   The sample trace data is as follows:

   ```text
   <...>-30265   (-------) [003] ..... 223860.709694: tracing_mark_write: S|30265|H:myTestAsyncTrace|1001|M62|categoryTest|key=value
   <...>-30265   (-------) [003] ..... 223860.709735: tracing_mark_write: S|30265|H:myTestAsyncTrace|1002|M62|categoryTest|key=value
   <...>-30265   (-------) [003] ..... 223860.710081: tracing_mark_write: B|30265|H:myTestSyncTrace|M62|key=value
   <...>-30265   (-------) [003] ..... 223860.710305: tracing_mark_write: C|30265|H:myTestCountTrace|0|M62
   <...>-30265   (-------) [003] ..... 223860.710332: tracing_mark_write: C|30265|H:myTestCountTrace|1|M62
   <...>-30265   (-------) [003] ..... 223861.711284: tracing_mark_write: F|30265|H:myTestAsyncTrace|1002|M62
   <...>-30265   (-------) [003] ..... 223862.709901: tracing_mark_write: F|30265|H:myTestAsyncTrace|1001|M62
   ```

   In the trace data line, **tracing_mark_write** indicates the logging event type. This event is used by the HiTraceMeter API in applications. The data before the logging event type is the thread name, thread ID, process ID, CPU, and logging time (from the startup time to the current time, in seconds). For the data that follows the logging event type, see [User-Mode Trace Format](hitracemeter-view.md#user-mode-trace-format).

### Step 3: Stopping Trace Capture

1. Run the following command to stop trace capture of the application.

   ```shell
   $ hitrace --trace_finish
   ```

2. Tap the **testHiTraceMeter** button on the app screen again. The trace capture of the app is now disabled, and the **isTraceEnabled()** API returns **false**. In the **Log** window of DevEco Studio, filter by the keyword "not enabled", and the following log will be printed.

   ```text
   myTraceTest running, trace is not enabled
   ```

   > **NOTE**
   >
   > In the log version, after the **hitrace --trace_finish** command is used to stop capture, the snapshot mode is automatically started and trace capture is enabled. In this case, the **isTraceEnabled()** API returns **true**, and the preceding log is not printed.