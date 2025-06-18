# Using HiTraceMeter (ArkTS)

## Overview

HiTraceMeter provides APIs for system performance tracing. You can call the HiTraceMeter APIs in key codes to track service processes and check the system performance.

## Basic Concepts

**HiTraceMeter Tag**: Tag used for tracing data categorization. It is also known as **HiTraceMeter Category**. Generally, one subsystem maps to a tag. When you use the [HiTrace](hitrace.md) CLI tool to collect tracing data, only the data specified by the **Tag** parameter is collected. The HiTraceMeter tag for applications is **HITRACE_TAG_APP**, which corresponds to **app** in the tag list displayed by running the **[hitrace](hitrace.md) -l** command.

## Working Principles

1. The application calls HiTraceMeter APIs to trace and input the tracing data to the kernel's ftrace buffer through the kernel's sysfs file interface.
2. The [HiTrace](hitrace.md) CLI tool reads the trace data in the kernel ftrace buffer and outputs the trace data to the file on the device.

## Available APIs

The performance tracing APIs are provided by the **HiTraceMeter** module. For details, see [HiTrace](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md).

| API                                                | Description                                                        |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| hiTraceMeter.startTrace(name: string, taskId: number)  | Starts an asynchronous time slice trace task. If multiple tracing tasks with the same name need to be performed at the same time, different task IDs must be specified through **taskId**. If the tracing tasks with the same name are not performed at the same time, the same task ID can be used.|
| hiTraceMeter.finishTrace(name: string, taskId: number) | Stops an asynchronous time slice trace task. The values of **name** and **taskId** must be the same as those of **hiTraceMeter.startTrace**.|
| hiTraceMeter.traceByValue(name: string, value: number) | Traces the value changes of a numeric variable, which is an integer.|

> **NOTE**
>
> The vertical bar (|) is used as the separator in user-mode trace format. Therefore, the string parameters passed by the HiTraceMeter APIs must exclude this character to avoid trace parsing exceptions.

HiTraceMeter logging APIs are classified into three types by functionality/behavior: API for synchronous time slice tracing, API for asynchronous time slice tracing, and API for integer tracing. Both synchronous and asynchronous time slice tracing APIs are synchronous APIs. You can use HiTraceMeter APIs with [HiTraceChain](./hitracechain-guidelines-arkts.md) to perform tracing and analysis across devices, processes, and threads.

- The API for synchronous time slice tracing is used for sequential logging, which is not supported in ArkTS/JS.
- The asynchronous time slice tracing APIs are used in the scenario where tasks are executed asynchronously. The start and end of an asynchronous tracing task are not in sequence. Therefore, the **name** and **taskId** parameters are used to identify the start and end of an asynchronous tracing task.
- The integer tracing API is used to trace integer variables.

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | Yes  | Name of the task or integer variable to trace.                            |
| taskId | number | Yes  | Task ID. If multiple tasks with the same **name** are executed at the same time, you must set different **taskId** when calling **startAsyncTrace**.|
| count  | number | Yes  | Value of an integer variable.                                              |

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
   
               let traceCount = 0;
               // Start the first tracing task.
               hiTraceMeter.startTrace("myTestAsyncTrace", 1001);
               // Start counting the task.
               traceCount++;
               hiTraceMeter.traceByValue("myTestCountTrace", traceCount);
               // Keep the service process running.
               console.log(`myTraceTest running, taskid: 1001`);
   
               // Start the second tracing task with the same name while the first task is still running. The tasks are running concurrently and therefore their taskId must be different.
               hiTraceMeter.startTrace("myTestAsyncTrace", 1002);
               // Start counting the task.
               traceCount++;
               hiTraceMeter.traceByValue("myTestCountTrace", traceCount);
               // Keep the service process running.
               console.log(`myTraceTest running, taskid: 1002`);
   
               // End the tracing task whose task ID is 1001.
               hiTraceMeter.finishTrace("myTestAsyncTrace", 1001);
               // End the tracing task whose task ID is 1002.
               hiTraceMeter.finishTrace("myTestAsyncTrace", 1002);
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
   <...>-24812   (-------) [010] .... 372550.749599: tracing_mark_write: S|24812|H:myTestAsyncTrace|1001
   <...>-24812   (-------) [010] .... 372550.749622: tracing_mark_write: C|24812|H:myTestCountTrace|1
   <...>-24812   (-------) [010] .... 372550.750118: tracing_mark_write: S|24812|H:myTestAsyncTrace|1002
   <...>-24812   (-------) [010] .... 372550.750131: tracing_mark_write: C|24812|H:myTestCountTrace|2
   <...>-24812   (-------) [010] .... 372550.750177: tracing_mark_write: F|24812|H:myTestAsyncTrace|1001
   <...>-24812   (-------) [010] .... 372550.750188: tracing_mark_write: F|24812|H:myTestAsyncTrace|1002
   ```
   
5. Run the following command to stop the application trace capture:

   ```shell
   $ hitrace --trace_finish
   ```
