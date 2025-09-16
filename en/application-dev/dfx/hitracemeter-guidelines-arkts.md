# Using HiTraceMeter (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--Designer: @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## Overview

HiTraceMeter provides APIs for system performance tracing. You can call the APIs at key code to track processes and check system and application performance.


## Available APIs

The performance tracing APIs are provided by the **HiTraceMeter** module. For details, see [@ohos.hiTraceMeter (Performance Tracing)](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md).

| API| Description| 
| -------- | -------- |
| hiTraceMeter.startSyncTrace(level: HiTraceOutputLevel, name: string, customArgs?: string): void | Starts a synchronous time slice trace with the trace output level specified.<br>**Note**: This API is supported since API version 19.| 
| hiTraceMeter.finishSyncTrace(level: HiTraceOutputLevel): void | Stops a synchronous time slice trace with the trace output level specified.<br>The value of **level** must be the same as that of **startSyncTrace**.<br>**Note**: This API is supported since API version 19.| 
| hiTraceMeter.startAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number, customCategory: string, customArgs?: string): void | Starts an asynchronous time slice trace with the trace output level specified.<br>If multiple tracing tasks with the same name need to be performed at the same time, different task IDs must be specified through **taskId**. If the tracing tasks with the same name are not performed at the same time, the same task ID can be used.<br>**Note**: This API is supported since API version 19.| 
| hiTraceMeter.finishAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number): void | Stops an asynchronous time slice trace with the trace output level specified.<br>Stops a tracing task. The values of **name** and **taskId** must be the same as those in **startAsyncTrace**.<br>**Note**: This API is supported since API version 19.| 
| hiTraceMeter.traceByValue(level: HiTraceOutputLevel, name: string, count: number): void | Traces an integer with the trace output level specified.<br>**name** indicates the name of an integer variable to trace, and **count** indicates the integer value.<br>**Note**: This API is supported since API version 19.| 
| hiTraceMeter.isTraceEnabled(): boolean | Checks whether application trace capture is enabled.<br>When it is enabled, **true** is returned; when it is disabled or stopped, **false** is returned. In this case, calling the HiTraceMeter API does not take effect.<br>**Note**: This API is supported since API version 19.| 

> **NOTE**
>
> The vertical bar (|) is used as the separator in [user-mode trace format](hitracemeter-view.md#user-mode-trace-format). Therefore, the string parameters passed by the HiTraceMeter APIs must exclude this character to avoid trace parsing exceptions.


### API Types

HiTraceMeter APIs are classified into three types: synchronous timeslice tracing APIs, asynchronous timeslice tracing APIs, and integer tracing APIs. HiTraceMeter APIs are synchronous. The synchronous and asynchronous modes describe the traced services. The synchronous timeslice tracing APIs are used for synchronous services, and the asynchronous timeslice tracing APIs are used for asynchronous services. HiTraceMeter APIs can be used with [HiTraceChain](hitracechain-guidelines-arkts.md) to associate and analyze logging across devices, processes, or threads.


### Use Scenarios

- Synchronous timeslice tracing APIs:
  The **startSyncTrace** and **finishSyncTrace** APIs must be used sequentially for logging during sequential execution. If they are not called in the correct order, the trace file will appear abnormal in visualization tools such as SmartPerf.

- Asynchronous timeslice tracing APIs:
  The **startAsyncTrace** API is called to start logging before an asynchronous operation is performed, and the **finishAsyncTrace** API is called to end logging after the asynchronous operation is performed. 
  During trace parsing, different asynchronous traces are identified by the **name** and **taskId** parameters. These two APIs must be used in sequence as a pair, with the same **name** and **taskId** passed. 
  Different **name** and **taskId** values must be used for different asynchronous processes. However, the same **name** and **taskId** values can be used if asynchronous processes do not occur at the same time. 
  If the API is called incorrectly, the trace file will appear abnormal in visualization tools such as SmartPerf.

- Integer tracing APIs:
  The APIs are used to trace integer variables. The **traceByValue** API is called when integer values change. You can view the change in the lane diagram of SmartPerf. The values during the interval between the start of data collection and the first logging cannot be viewed.


### Parameter Description

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| level | enum | Yes| Trace output level. Trace data whose levels are lower than the system threshold will not be output.<br>By default, the log version threshold is **INFO**, and the nolog version threshold is **COMMERCIAL**.| 
| name | string | Yes| Name of the task or integer variable to trace.| 
| taskId | number | Yes| Task ID for association. If multiple tasks with the same name are executed concurrently, different task IDs must be set when the **startAsyncTrace** API is called.| 
| count | number | Yes| Value of an integer variable.| 
| customCategory | string | Yes| Custom category name, which is used to collect asynchronous trace data of the same type.<br>If the category is not required, pass in an empty string.| 
| customArgs | string | No| Custom key-value pair. If there are multiple key-value pairs, separate them with commas (,), for example, **key1=value1,key2=value2**.<br>If this parameter is not required, do not pass in it or pass in an empty string.| 

> **NOTE**
>
> The maximum length of a [user-mode trace](hitracemeter-view.md#user-mode-trace-format) is 512 characters. Excess characters will be truncated. Therefore, it is recommended that the total length of the **name**, **customCategory**, and **customArgs** fields be less than or equal to 420 characters.


## How to Develop

The following is an example of an ArkTS application that uses the HiTraceMeter APIs.


### Step 1: Creating a Project

1. Create a project in DevEco Studio and select **Empty Ability**. The project directory structure is as follows:

   ```text
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

2. In the **entry/src/main/ets/pages/index.ets** file, use the HiTraceMeter API in the processing service of the text click event. The sample code is as follows:

   ```ts
   import { hiTraceMeter, hilog } from '@kit.PerformanceAnalysisKit';
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(() => {
               this.message = (this.message == 'Hello HiTrace') ? 'Hello World' : 'Hello HiTrace';
               const COMMERCIAL = hiTraceMeter.HiTraceOutputLevel.COMMERCIAL;
   
               let traceCount = 0;
               // Start the first asynchronous tracing task.
               hiTraceMeter.startAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1001, 'categoryTest', 'key=value');
               // Start counting the task.
               traceCount++;
               hiTraceMeter.traceByValue(COMMERCIAL, 'myTestCountTrace', traceCount);
               // Keep the service process running.
               hilog.info(0x0000, 'testTrace', 'myTraceTest running, taskId: 1001');
   
               // Start the second asynchronous tracing task with the same name while the first task is still running. The tasks are running concurrently and therefore their taskId must be different.
               hiTraceMeter.startAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1002, 'categoryTest', 'key=value');
               // Start counting the task.
               traceCount++;
               hiTraceMeter.traceByValue(COMMERCIAL, 'myTestCountTrace', traceCount);
               // Keep the service process running.
               hilog.info(0x0000, 'testTrace', 'myTraceTest running, taskId: 1002');
   
               // Stop the asynchronous tracing task whose taskId is 1001.
               hiTraceMeter.finishAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1001);
               // Stop the asynchronous tracing task whose taskId is 1002.
               hiTraceMeter.finishAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1002);
               
               // Start a synchronous tracing task.
               hiTraceMeter.startSyncTrace(COMMERCIAL, 'myTestSyncTrace', 'key=value');
               // Keep the service process running.
               hilog.info(0x0000, 'testTrace', 'myTraceTest running, synchronizing trace');
               // Stop the synchronous tracing task.
               hiTraceMeter.finishSyncTrace(COMMERCIAL);
               
               // If the process of generating the parameters passed by the HiTraceMeter API is complex, you can use isTraceEnabled to determine whether trace capture is enabled.
               // Avoid performance loss when application trace capture is not enabled.
               if (hiTraceMeter.isTraceEnabled()) {
                   let customArgs = 'key0=value0';
                   for(let index = 1; index < 10; index++) {
                       customArgs += `,key${index}=value${index}`
                   }
                   hiTraceMeter.startAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1003, 'categoryTest', customArgs);
                   hilog.info(0x0000, 'testTrace', 'myTraceTest running, taskId: 1003');
                   hiTraceMeter.finishAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1003);
               } else {
                   hilog.info(0x0000, 'testTrace', 'myTraceTest running, trace is not enabled');
               }
             })
          }
          .width('100%')
        }
        .height('100%')
      }
   }
   ```


### Step 2: Collecting and Viewing Trace Information

1. Run the following command in DevEco Studio Terminal to enable trace capture:

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```

2. Click the **Run** button in DevEco Studio to run the project. Then, click "Hello world" to execute the service logic that contains HiTraceMeter logging. Run the following command to capture trace data and filter the trace data using the keyword **myTest** (the name field prefix passed by the logging API is **myTest** in this example).

   ```shell
   $ hitrace --trace_dump | grep myTest
   ```

   The sample trace data is as follows:

   ```text
   e.myapplication-39945   (  39945) [010] .... 347921.342267: tracing_mark_write: S|39945|H:myTestAsyncTrace|1001|M62|categoryTest|key=value
   e.myapplication-39945   (  39945) [010] .... 347921.342280: tracing_mark_write: C|39945|H:myTestCountTrace|1|M62
   e.myapplication-39945   (  39945) [010] .... 347921.342327: tracing_mark_write: S|39945|H:myTestAsyncTrace|1002|M62|categoryTest|key=value
   e.myapplication-39945   (  39945) [010] .... 347921.342333: tracing_mark_write: C|39945|H:myTestCountTrace|2|M62
   e.myapplication-39945   (  39945) [010] .... 347921.342358: tracing_mark_write: F|39945|H:myTestAsyncTrace|1001|M62
   e.myapplication-39945   (  39945) [010] .... 347921.342365: tracing_mark_write: F|39945|H:myTestAsyncTrace|1002|M62
   e.myapplication-39945   (  39945) [010] .... 347921.342387: tracing_mark_write: B|39945|H:myTestSyncTrace|M62|key=value
   e.myapplication-39945   (  39945) [010] .... 347921.342586: tracing_mark_write: S|39945|H:myTestAsyncTrace|1003|M62|categoryTest|key0=value0,key1=value1,key2=value2,key3=value3,key4=value4,key5=value5,key6=value6,key7=value7,key8=value8,key9=value9
   e.myapplication-39945   (  39945) [010] .... 347921.342615: tracing_mark_write: F|39945|H:myTestAsyncTrace|1003|M62
   ```

   In the trace data line, **tracing_mark_write** indicates the logging event type. This event is used by the HiTraceMeter API in applications. The data before the logging event type is the thread name, thread ID, process ID, CPU, and logging time (from the startup time to the current time, in seconds). For the data that follows the logging event type, see [User-Mode Trace Format](hitracemeter-view.md#user-mode-trace-format).


### Step 3: Stoping Trace Capture


1. Run the following command to stop trace capture of the application.

   ```shell
   $ hitrace --trace_finish
   ```

2. Click "Hello World" on the application screen again. The trace capture of the application is disabled, and the **isTraceEnabled** API returns **false**. In the **Log** window of the DevEco Studio, input the keyword **not enabled** for filtering and the following log is displayed.

   ```text
   myTraceTest running, trace is not enabled
   ```

   > **NOTE**
   >
   > In the log version, after the **hitrace --trace_finish** command is used to stop capture, the snapshot mode is automatically started and trace capture is enabled. In this case, the **isTraceEnabled** API returns **true**, and the preceding log is not printed.
