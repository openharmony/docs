# Using HiTraceMeter (ArkTS/JS)

## Overview

HiTraceMeter provides APIs for system performance tracing. You can call the HiTraceMeter APIs in key codes to track service processes and check the system performance.

## Basic Concepts

**HiTraceMeter Tag**: Tag used for tracing data categorization. It is also known as **HiTraceMeter Category**. Generally, one subsystem maps to a tag. When you use the [HiTrace](hitrace.md) CLI tool to collect tracing data, only the data specified by the **Tag** parameter is collected. The HiTraceMeter tag for applications is **HITRACE_TAG_APP**, which corresponds to **app** in the tag list displayed by running the **[hitrace](hitrace.md) -l** command.

## Working Principles

1. The application calls HiTraceMeter APIs to trace and input the tracing data to the kernel's ftrace buffer through the kernel's sysfs file interface.
2. The [HiTrace](hitrace.md) CLI tool reads the trace data in the kernel ftrace buffer and outputs the trace data to the file on the device.

## Available APIs

The performance tracing APIs are provided by the **HiTraceMeter** module. For details, see [HiTrace](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md).

| API                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| startSyncTrace(level: HiTraceOutputLevel, name: string, customArgs?: string): void | Starts a synchronous time slice trace with the trace output level specified.<br>**Note**: This API is supported since API version 19.|
| finishSyncTrace(level: HiTraceOutputLevel): void             | Stops a synchronous time slice trace with the trace output level specified. The value of **level** must be the same as that of **startSyncTrace**.<br>**Note**: This API is supported since API version 19.|
| startAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number, customCategory: string, customArgs?: string): void | Starts an asynchronous time slice trace with the trace output level specified. If multiple tracing tasks with the same name need to be performed at the same time, different task IDs must be specified through **taskId**. If the tracing tasks with the same name are not performed at the same time, the same task ID can be used.<br>**Note**: This API is supported since API version 19.|
| finishAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number): void | Stops an asynchronous time slice trace with the trace output level specified. Stops a tracing task. The values of **name** and **taskId** must be the same as those in **startAsyncTrace**.<br>**Note**: This API is supported since API version 19.|
| traceByValue(level: HiTraceOutputLevel, name: string, count: number): void | Traces an integer with the trace output level specified. **name** indicates the name of an integer variable to trace, and **count** indicates the integer value.<br>**Note**: This API is supported since API version 19.|
| isTraceEnabled(): boolean                                    | Checks whether application trace capture is enabled. If not, HiTraceMeter performance tracing is invalid.<br>**Note**: This API is supported since API version 19.|

> **NOTE**
>
> The vertical bar (|) is used as the separator in [user-mode trace format](./hitracemeter-view.md#user-mode-trace-format). Therefore, the string parameters passed by the HiTraceMeter APIs must exclude this character to avoid trace parsing exceptions.

HiTraceMeter logging APIs are classified into three types by functionality/behavior: API for synchronous time slice tracing, API for asynchronous time slice tracing, and API for integer tracing. Both synchronous and asynchronous time slice tracing APIs are synchronous APIs. You can use HiTraceMeter APIs with [HiTraceChain](./hitracechain-guidelines-arkts.md) to perform tracing and analysis across devices, processes, and threads.

- The synchronous time slice tracing APIs are used in the scenario where tasks are executed in sequence.
- The asynchronous time slice tracing APIs are used in the scenario where tasks are executed asynchronously. The start and end of an asynchronous tracing task are not in sequence. Therefore, the **name** and **taskId** parameters are used to identify the start and end of an asynchronous tracing task.
- The integer tracing API is used to trace integer variables.

**Parameters**

| Name        | Type  | Mandatory| Description                                                        |
| -------------- | ------ | ---- | ------------------------------------------------------------ |
| level          | enum   | Yes  | Trace output level. Trace data whose levels are lower than the system threshold will not be output.<br>The log version threshold is **INFO**, and the nolog version threshold is **COMMERCIAL**.|
| name           | string | Yes  | Name of the task or integer variable to trace.                            |
| taskId         | number | Yes  | Task ID. If multiple tasks with the same **name** are executed at the same time, you must set different **taskId** when calling **startAsyncTrace**.|
| count          | number | Yes  | Value of an integer variable.                                              |
| customCategory | string | Yes  | Custom category name, which is used to collect asynchronous trace data of the same type.<br>If the category is not required, pass in an empty string.|
| customArgs     | string | No  | Custom key-value pair. If there are multiple key-value pairs, separate them with commas (,), for example, **key1=value1,key2=value2**.<br>If this parameter is not required, do not pass in it or pass in an empty string.|

> **NOTE**
>
> The maximum length of a [user-mode trace format](./hitracemeter-view.md#user-mode-trace-format) is 512 characters. Excess characters will be truncated. Therefore, it is recommended that the total length of the **name**, **customCategory**, and **customArgs** fields be less than or equal to 420 characters.

## How to Develop

In this example, distributed call chain tracing begins when the application startup execution page is loaded and stops when the service usage is completed. The following is an example of an ArkTS application that uses the HiTraceMeter API.

1. Create an ArkTS application project. The project directory structure is as follows:

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

2. In the **Index.ets** file, use the HiTraceMeter API in the processing service of the text click event. The sample code is as follows:

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

3. Run the following command in DevEco Studio Terminal to enable trace capture:

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```

4. In DevEco Studio, click the **Run** button to run the project. Click the string in the middle of the screen to execute the service logic that contains the HiTraceMeter logging. Then run the following command to capture trace data:

   ```shell
   $ hitrace --trace_dump | grep myTest
   ```

   The sample trace data is as follows:

   ```text
   <...>-39945   (-------) [010] .... 347921.342267: tracing_mark_write: S|39945|H:myTestAsyncTrace|1001|M62|categoryTest|key=value
   <...>-39945   (-------) [010] .... 347921.342280: tracing_mark_write: C|39945|H:myTestCountTrace|1|M62
   <...>-39945   (-------) [010] .... 347921.342327: tracing_mark_write: S|39945|H:myTestAsyncTrace|1002|M62|categoryTest|key=value
   <...>-39945   (-------) [010] .... 347921.342333: tracing_mark_write: C|39945|H:myTestCountTrace|2|M62
   <...>-39945   (-------) [010] .... 347921.342358: tracing_mark_write: F|39945|H:myTestAsyncTrace|1001|M62
   <...>-39945   (-------) [010] .... 347921.342365: tracing_mark_write: F|39945|H:myTestAsyncTrace|1002|M62
   <...>-39945   (-------) [010] .... 347921.342387: tracing_mark_write: B|39945|H:myTestSyncTrace|M62|key=value
   <...>-39945   (-------) [010] .... 347921.342586: tracing_mark_write: S|39945|H:myTestAsyncTrace|1003|M62|categoryTest|key0=value0,key1=value1,key2=value2,key3=value3,key4=value4,key5=value5,key6=value6,key7=value7,key8=value8,key9=value9
   <...>-39945   (-------) [010] .... 347921.342615: tracing_mark_write: F|39945|H:myTestAsyncTrace|1003|M62
   ```

5. Run the following command to stop the application trace capture:

   ```shell
   $ hitrace --trace_finish
   ```

6. Click the string in the middle of the screen again. The application trace capture function is disabled, and **isTraceEnabled** returns **false**. In the **Log** panel in DevEco Studio, select **enable** to filter logs. The following information is displayed:

   ```text
   myTraceTest running, trace is not enabled
   ```

   
