# Using hiTraceMeter (ArkTS/JS)

## Overview

**hiTraceMeter** provides APIs for system performance tracing. You can call the APIs provided by **hiTraceMeter** in key codes to track service processes and check the system performance.

## Basic Concepts

**hiTraceMeter Tag**: tag specifying the category of the data to trace. It is also known as **HiTraceMeter Category**. Generally, one subsystem maps to a tag. The tag is passed in by the **Tag** parameter in performance tracing APIs. When you use the hiTraceMeter CLI tool to collect tracing data, only the data specified by the **Tag** parameter is collected.

## Working Principles

1. The application calls hiTraceMeter APIs to trace and output the tracing data to the kernel's ftrace buffer through the kernel's sysfs file interface.

2. The hiTraceMeter CLI tool reads the tracing data in the ftrace buffer and saves the trace data as a text file on the device.

## Available APIs

The performance tracing APIs are provided by the **hiTraceMeter** module. For details, see [Hitrace](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md).

| API| Description| 
| -------- | -------- |
| hiTraceMeter.startTrace(name: string, taskId: number) | Starts an asynchronous time slice trace task. If multiple tracing tasks with the same name need to be performed at the same time, different task IDs must be specified through **taskId**. If the tracing tasks with the same name are not performed at the same time, the same task ID can be used.| 
| hiTraceMeter.finishTrace(name: string, taskId: number) | Stops an asynchronous time slice trace task. The values of **name** and **taskId** must be the same as those of **hiTraceMeter.startTrace**. | 
| hiTraceMeter.traceByValue(name: string, value: number) | Traces the value changes of a numeric variable, which is an integer.| 

HiTraceMeter logging APIs are classified into three types by functionality/behavior: API for synchronous time slice tracing, API for asynchronous time slice tracing, and API for integer tracing. APIs for synchronous and asynchronous time slice tracing are synchronous and are used in the same thread. Cross-thread logging and analysis are not supported.

- The API for synchronous time slice tracing is used for sequential logging, which is not supported in ArkTS/JS.
- The API for asynchronous time slice tracing is used to start logging before an operation is called and end longing after the operation is complete. Since the start and end of asynchronous tracing do not occur in sequence, a unique task ID is used to identify the start and end of asynchronous tracing. The task ID is passed as a parameter of the API for asynchronous tracing.
- The integer tracing API is used to trace numeric variables.

## How to Develop

In this example, distributed call chain tracing begins when the application startup execution page is loaded and stops when the service usage is completed.

1. In DevEco Studio, create an ArkTS application project. In the **Project** window, choose **entry** > **src** > **main** > **ets** > **pages** > **index**, and double-click **index.ets**. Add the code to the file to implement performance tracing upon page loading. The sample code of tracing task **myTraceTest** is as follows:

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
                
               let traceCount = 0;
               // Start the first tracing task.
               hiTraceMeter.startTrace("myTraceTest", 1001);
               // Start counting the task.
               traceCount++;
               hiTraceMeter.traceByValue("myTestCount", traceCount);
               // Keep the service process running.
               console.log(`myTraceTest running, taskid: 1001`);
                 
               // Start the second tracing task with the same name while the first task is still running. The tasks are running concurrently and therefore their taskId must be different.
               hiTraceMeter.startTrace("myTraceTest", 1002);
               // Start counting the task.
               traceCount++;
               hiTraceMeter.traceByValue("myTestCount", traceCount);
               // Keep the service process running.
               console.log(`myTraceTest running, taskid: 1002`);
   
               // End the tracing task whose task ID is 1001.
               hiTraceMeter.finishTrace("myTraceTest", 1001);
               // End the tracing task whose task ID is 1002.
               hiTraceMeter.finishTrace("myTraceTest", 1002);

             })
          }
          .width('100%')
        }
        .height('100%')
      }
   }
   ```

2. Click the **Run** button in DevEco Studio to run the project. Then, run the [hitrace](hitrace.md) command to obtain the tracing task logs.
   
   Run the following command in DevEco Studio Terminal:

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```

   After the **trace** command is executed, call the HiTraceMeter APIs in your service logic on the device. Then, run the following commands in sequence:

   ```shell
   $ hitrace --trace_dump | grep tracing_mark_write
   $ hitrace --trace_finish
   ```

   The following is an example of the captured trace data:

   ```text
   <...>-3310    (-------) [005] .... 351382.921936: tracing_mark_write: S|3310|H:myTraceTest 1001
   <...>-3310    (-------) [005] .... 351382.922233: tracing_mark_write: C|3310|H:myTestCount 1
   <...>-3310    (-------) [005] .... 351382.922138: tracing_mark_write: S|3310|H:myTraceTest 1002
   <...>-3310    (-------) [005] .... 351382.922233: tracing_mark_write: C|3310|H:myTestCount 2
   <...>-3310    (-------) [005] .... 351382.922165: tracing_mark_write: F|3310|H:myTestCount 1001
   <...>-3310    (-------) [005] .... 351382.922175: tracing_mark_write: F|3310|H:myTestCount 1002
   ```
