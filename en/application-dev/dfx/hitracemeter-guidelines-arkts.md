# Using hiTraceMeter (ArkTS/JS)

## Overview

**hiTraceMeter** provides APIs for system performance tracing. You can call the APIs provided by **hiTraceMeter** in key codes to track service processes and check the system performance.

## Basic Concepts

**hiTraceMeter Tag**: tag specifying the category of the data to trace. It is also known as **HiTraceMeter Category**. Generally, one subsystem maps to a tag. The tag is passed in by the **Tag** parameter in performance tracing APIs. When you use the hiTraceMeter CLI tool to collect tracing data, only the data specified by the **Tag** parameter is collected.

## Working Principles

1. The application calls hiTraceMeter APIs to trace and output the tracing data to the kernel's ftrace buffer through the kernel's sysfs file interface.

2. The hiTraceMeter CLI tool reads the tracing data in the ftrace buffer and saves the trace data as a text file on the device.

## Constraints

Due to the asynchronous I/O feature of JS, the **hiTraceMeter** module provides only asynchronous APIs.

## Available APIs

The performance tracing APIs are provided by the **hiTraceMeter** module. For details, see [Hitrace](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md).

| API| Description| 
| -------- | -------- |
| hiTraceMeter.startTrace(name: string, taskId: number) | Starts a tracing task. If multiple tracing tasks with the same name need to be performed at the same time, different task IDs must be specified through **taskId**. If the tracing tasks with the same name are not performed at the same time, the same task ID can be used.| 
| hiTraceMeter.finishTrace(name: string, taskId: number) | Stops a tracing task. The values of **name** and **taskId** must be the same as those in **hiTraceMeter.startTrace**.| 
| hiTraceMeter.traceByValue(name: string, value: number) | Traces the value changes of a numeric variable.| 

## How to Develop

In this example, distributed call chain tracing begins when the application startup execution page is loaded and stops when the service usage is completed.

1. In DevEco Studio, create an ArkTS application project. In the **Project** window, choose **entry** > **src** > **main** > **ets** > **pages** > **index**, and double-click **index.ets**. Add the code to the file to implement performance tracing upon page loading. The sample code of tracing task **HITRACE\_TAG\_APP** is as follows:

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
   
               // Start concurrent tracing tasks with the same name.
               hitrace.startTrace("HITRACE_TAG_APP", 1001);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
   
               // Start the second tracing task with the same name while the first task is still running. The tasks are running concurrently and therefore their taskId must be different.
               hitrace.startTrace("HITRACE_TAG_APP", 1002);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
   
               hitrace.finishTrace("HITRACE_TAG_APP", 1001);
               hitrace.finishTrace("HITRACE_TAG_APP", 1002);
   
               // If tracing tasks with the same name are not run concurrently, the same taskId can be used.
               hitrace.startTrace("HITRACE_TAG_APP", 1003);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
               // Stop the first tracing task.
               hitrace.finishTrace("HITRACE_TAG_APP", 1003);
   
               // Start the second tracing task with the same name in serial mode. It uses a taskId different from the first tracing task.
               hitrace.startTrace("HITRACE_TAG_APP", 1004);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
               let traceCount = 3;
               hitrace.traceByValue("myTestCount", traceCount);
               hitrace.finishTrace("HITRACE_TAG_APP", 1004);
   
               // Start the third tracing task with the same name in serial mode. It uses a taskId same as the second tracing task.
               hitrace.startTrace("HITRACE_TAG_APP", 1004);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
               // Stop the third tracing task.
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

   After the **trace** command is executed, call the HiTraceMeter APIs in your service logic on the device. Then, run the following commands in sequence:

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
