# Using HiTraceMeter (ArkTS/JS)

## Overview

HiTraceMeter provides APIs for system performance tracing. You can call the HiTraceMeter APIs in key codes to track service processes and check the system performance.

## Basic Concepts

**HiTraceMeter Tag**: Tag used for tracing data categorization. It is also known as **HiTraceMeter Category**. Generally, one subsystem maps to a tag. When you use the [HiTrace](hitrace.md) CLI tool to collect tracing data, only the data specified by the **Tag** parameter is collected. The HiTraceMeter tag for applications is **HITRACE_TAG_APP**, which corresponds to **app** in the tag list displayed by running the **[hitrace](hitrace.md) -l** command.

## Working Principles

1. The application calls HiTraceMeter APIs to trace and input the tracing data to the kernel's ftrace buffer through the kernel's sysfs file interface.
2. The [HiTrace](hitrace.md) CLI tool reads the trace data in the kernel ftrace buffer and outputs the trace data to the file on the device.

## Available APIs

The performance tracing APIs are provided by the **HiTraceMeter** module. For details, see [Hitrace](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md).

| API                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| startSyncTrace(level: HiTraceOutputLevel, name: string, customArgs?: string): void | Starts a synchronous time slice trace with the trace output level specified.              |
| finishSyncTrace(level: HiTraceOutputLevel): void             | Stops a synchronous time slice trace with the trace output level specified. The value of **level** must be the same as that of **startSyncTrace**.|
| startAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number, customCategory: string, customArgs?: string): void | Starts an asynchronous time slice trace with the trace output level specified. If multiple tracing tasks with the same name need to be performed at the same time, different task IDs must be specified through **taskId**. If the tracing tasks with the same name are not performed at the same time, the same task ID can be used.|
| finishAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number): void | Stops an asynchronous time slice trace with the trace output level specified. Stops a tracing task. The values of **name** and **taskId** must be the same as those in **startAsyncTrace**.|
| traceByValue(level: HiTraceOutputLevel, name: string, count: number): void | Traces an integer with the trace output level specified. **name** and **count** are used to identify the name and value of an integer variable to be traced.|
| isTraceEnabled(): boolean                                    | Checks whether application trace capture is enabled. If not, HiTraceMeter performance tracing is invalid.|

HiTraceMeter logging APIs are classified into three types by functionality/behavior: API for synchronous time slice tracing, API for asynchronous time slice tracing, and API for integer tracing. Both synchronous and asynchronous time slice tracing APIs are synchronous APIs. You can use HiTraceMeter APIs with [HiTraceChain](./hitracechain-guidelines-arkts.md) to perform tracing and analysis across devices, processes, and threads.

- The synchronous time slice tracing APIs are used in the scenario where tasks are executed in sequence.
- The asynchronous time slice tracing APIs are used in the scenario where tasks are executed asynchronously. The start and end of an asynchronous trace task are not in sequence. Therefore, the **name** and **taskId** parameters are used to identify the start and end of an asynchronous trace task.
- The integer tracing API is used to trace integer variables.

**Parameters**

| Name        | Type  | Mandatory| Description                                                        |
| -------------- | ------ | ---- | ------------------------------------------------------------ |
| level          | enum   | Yes  | Trace output level. Trace data whose levels are lower than the system threshold will not be output.<br>The log version threshold is **INFO**, and the nolog version threshold is **COMMERCIAL**.|
| name           | string | Yes  | Name of the task or integer variable to trace. The value contains a maximum of 320 characters. If the value length exceeds this limit, excess content will be truncated.|
| taskId         | number | Yes  | Task ID. If multiple tasks with the same **name** are executed at the same time, you must set different **taskId** when calling **startAsyncTrace**.|
| count          | number | Yes  | Value of an integer variable.                                              |
| customCategory | string | Yes  | Custom category name, which is used to collect asynchronous trace data of the same type. The value contains a maximum of 64 characters. If the value length exceeds this limit, excess content will be truncated.<br>If the category is not required, pass in an empty string.|
| customArgs     | string | No  | Custom key-value pair. If there are multiple key-value pairs, separate them with commas (,), for example, **key1=value1,key2=value2**.<br>A maximum of 512 characters are output. If the **name** and **customCategory** parameters occupy too many characters, the value of **customArgs** may be truncated.<br>If this parameter is not required, do not pass in it or pass in an empty string.|

## How to Develop

In this example, distributed call chain tracing begins when the application startup execution page is loaded and stops when the service usage is completed. In the following example, the **startAsyncTrace**, **finishAsyncTrace**, and **traceByValue** APIs of HiTraceMeter are used in ArkTS.

1. In DevEco Studio, create an ArkTS application project. In the **Project** window, choose **entry** > **src** > **main** > **ets** > **pages** > **index**, and double-click **index.ets**. Add the code to the file to implement performance tracing upon page loading. The sample code of tracing task **myTestAsyncTrace** is as follows:

   ```ts
   import hiTraceMeter from '@ohos.hiTraceMeter';
   
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
               this.message = 'Hello Hitrace';
               const COMMERCIAL = hiTraceMeter.HiTraceOutputLevel.COMMERCIAL;
   
               let traceCount = 0;
               // Start the first tracing task.
               hiTraceMeter.startAsyncTrace(COMMERCIAL, "myTestAsyncTrace", 1001, "categoryTest", "key=value");
               // Start counting the task.
               traceCount++;
               hiTraceMeter.traceByValue(COMMERCIAL, "myTestCountTrace", traceCount);
               // Keep the service process running.
               console.log(`myTraceTest running, taskid: 1001`);
   
               // Start the second tracing task with the same name while the first task is still running. The tasks are running concurrently and therefore their taskId must be different.
               hiTraceMeter.startAsyncTrace(COMMERCIAL, "myTestAsyncTrace", 1002, "categoryTest", "key=value");
               // Start counting the task.
               traceCount++;
               hiTraceMeter.traceByValue(COMMERCIAL, "myTestCountTrace", traceCount);
               // Keep the service process running.
               console.log(`myTraceTest running, taskid: 1002`);
   
               // End the tracing task whose task ID is 1001.
               hiTraceMeter.finishAsyncTrace(COMMERCIAL, "myTestAsyncTrace", 1001);
               // End the tracing task whose task ID is 1002.
               hiTraceMeter.finishAsyncTrace(COMMERCIAL, "myTestAsyncTrace", 1002);
             })
          }
          .width('100%')
        }
        .height('100%')
      }
   }
   ```
2. Click the **Run** button in DevEco Studio to run the project. Then, run the [HiTrace](hitrace.md) command to obtain the tracing task logs.

   Run the following command in DevEco Studio Terminal to enable trace capture:

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```
   Start the application, execute the service call logic (including HiTraceMeter APIs), and run the following commands in sequence:

   ```shell
   $ hitrace --trace_dump | grep myTest
   $ hitrace --trace_finish
   ```
   The following is an example of the captured trace data:

   ```text
   <...>-23649   (-------) [007] ....  2078.630872: tracing_mark_write: S|23649|H:myTestAsyncTrace|1001|M62|categoryTest|key=value
   <...>-23649   (-------) [007] ....  2078.630887: tracing_mark_write: C|23649|H:myTestCountTrace|1|M62
   <...>-23649   (-------) [007] ....  2078.630989: tracing_mark_write: S|23649|H:myTestAsyncTrace|1002|M62|categoryTest|key=value
   <...>-23649   (-------) [007] ....  2078.630996: tracing_mark_write: C|23649|H:myTestCountTrace|2|M62
   <...>-23649   (-------) [007] ....  2078.631027: tracing_mark_write: F|23649|H:myTestAsyncTrace|1001|M62
   <...>-23649   (-------) [007] ....  2078.631033: tracing_mark_write: F|23649|H:myTestAsyncTrace|1002|M62
   ```
