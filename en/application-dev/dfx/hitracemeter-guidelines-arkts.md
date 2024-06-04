# Using HiTraceMeter to Trace Performance (ArkTS/JS)

## Overview

The **HiTraceMeter** module provides APIs for system performance tracing. You can call the APIs provided by the **HiTraceMeter** module to effectively track service processes and check the system performance.

## Basic Concepts

**HiTraceMeter Tag**: tag used for tracing data categorization. It is also known as **HiTraceMeter Category**. Generally, one subsystem maps to a tag. The tag is passed as the **Tag** parameter in performance tracing APIs. When you use the HiTraceMeter CLI tool to collect tracing data, only the tracing data specified by the **Tag** parameter is collected.

## Working Principles

1. The application calls HiTraceMeter APIs to perform performance tracing. The APIs output the tracing data to the kernel's ftrace data buffer through the kernel's sysfs file interface.

2. The HiTraceMeter CLI tool reads the tracing data in the ftrace data buffer and saves the trace data as a text file on the device.

## Constraints

Due to the asynchronous I/O feature of JS, the HiTraceMeter module provides only asynchronous APIs.

## Available APIs

The performance tracing APIs are provided by the **HiTraceMeter** module. For details, see [Hitrace](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md).

| API| Description| 
| -------- | -------- |
| hiTraceMeter.startTrace(name: string, taskId: number) | Marks the start of a trace task. If multiple trace tasks with the same name need to be performed at the same time, different task IDs must be specified through **taskId**. If the trace tasks with the same name are not performed at the same time, the same task ID can be used.| 
| hiTraceMeter.finishTrace(name: string, taskId: number) | Marks the end of a trace task. The values of **name** and **taskId** must be the same as those in **hiTraceMeter.startTrace**.| 
| hiTraceMeter.traceByValue(name: string, value: number) | Marks the value changes of a numeric variable in a trace task.| 

## How to Develop

In this example, distributed call chain tracing begins when the application startup execution page is loaded and stops when the service usage is completed.

1. In DevEco Studio, create an ArkTS application project. In the **Project** window, choose **entry** > **src** > **main** > **ets** > **pages** > **index**, and double-click **index.js**. Add the code to the file to implement performance tracing upon page loading. For example, if the name of the trace task is **HITRACE\_TAG\_APP**, the sample code is as follows:

   ```ts
   import hitrace from '@ohos.hiTraceMeter';
   
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
               this.message = 'Hello ArkUI';
   
               // Start trace tasks with the same name concurrently.
               hitrace.startTrace("HITRACE_TAG_APP", 1001);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
   
               // Start the second trace task with the same name while the first task is still running. The tasks are running concurrently and therefore their taskId must be different.
               hitrace.startTrace("HITRACE_TAG_APP", 1002);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
   
               hitrace.finishTrace("HITRACE_TAG_APP", 1001);
               hitrace.finishTrace("HITRACE_TAG_APP", 1002);
   
               // If trace tasks with the same name are not run concurrently, the same taskId can be used.
               hitrace.startTrace("HITRACE_TAG_APP", 1003);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
               // End the first trace task.
               hitrace.finishTrace("HITRACE_TAG_APP", 1003);
   
               // Start the second trace task with the same name in serial mode. It uses a taskId different from the first trace task.
               hitrace.startTrace("HITRACE_TAG_APP", 1004);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
               let traceCount = 3;
               hitrace.traceByValue("myTestCount", traceCount);
               hitrace.finishTrace("HITRACE_TAG_APP", 1004);
   
               // Start the third trace task with the same name in serial mode. It uses a taskId same as the second trace task.
               hitrace.startTrace("HITRACE_TAG_APP", 1004);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
               // End the third trace task.
               hitrace.finishTrace("HITRACE_TAG_APP", 1004);
   
             })
          }
          .width('100%')
        }
        .height('100%')
      }
   }
   ```

2. Run the project. Then, run the following commands in sequence in shell:

   ```shell
   hdc shell
   hitrace --trace_begin app
   ```

   After the trace command is executed, call the HiTraceMeter APIs in your own service logic on the device. Then, run the following commands in sequence:

   ```shell
   hitrace --trace_dump | grep tracing_mark_write
   hitrace --trace_finish
   ```

   The following is an example of the captured trace data:

   ```text
   <...>-3310    (-------) [005] .... 351382.921936: tracing_mark_write: S|3310|H:HITRACE_TAG_APP 1001
   <...>-3310    (-------) [005] .... 351382.922138: tracing_mark_write: S|3310|H:HITRACE_TAG_APP 1002
   <...>-3310    (-------) [005] .... 351382.922165: tracing_mark_write: F|3310|H:HITRACE_TAG_APP 1001
   <...>-3310    (-------) [005] .... 351382.922175: tracing_mark_write: F|3310|H:HITRACE_TAG_APP 1002
   <...>-3310    (-------) [005] .... 351382.922182: tracing_mark_write: S|3310|H:HITRACE_TAG_APP 1003
   <...>-3310    (-------) [005] .... 351382.922203: tracing_mark_write: F|3310|H:HITRACE_TAG_APP 1003
   <...>-3310    (-------) [005] .... 351382.922210: tracing_mark_write: S|3310|H:HITRACE_TAG_APP 1004
   <...>-3310    (-------) [005] .... 351382.922233: tracing_mark_write: C|3310|H:myTestCount 3
   <...>-3310    (-------) [005] .... 351382.922240: tracing_mark_write: F|3310|H:HITRACE_TAG_APP 1004
   <...>-3310    (-------) [005] .... 351382.922247: tracing_mark_write: S|3310|H:HITRACE_TAG_APP 1004
   <...>-3310    (-------) [005] .... 351382.922266: tracing_mark_write: F|3310|H:HITRACE_TAG_APP 1004
   ```
