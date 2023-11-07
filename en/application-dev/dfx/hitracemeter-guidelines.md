# Development of Performance Tracing (ArkTS)

## Introduction

hiTraceMeter provides APIs for system performance tracing. You can call the APIs provided by the hiTraceMeter module in your own service logic to effectively track service processes and check the system performance.

## Basic Concepts

- **hiTraceMeter Tag**

  Tag used for tracing data categorization. It is also known as **hiTraceMeter Category**. Generally, one subsystem maps to a tag. The tag is passed as the **Tag** parameter in performance tracing APIs. When you use the hiTraceMeter CLI tool to collect tracing data, only the tracing data specified by the **Tag** parameter is collected.

## Working Principles

- The application calls hiTraceMeter APIs to perform performance tracing. The APIs output the tracing data to the kernel's ftrace data buffer through the kernel's sysfs file interface.
- The hiTraceMeter CLI tool reads the tracing data in the ftrace data buffer and saves the trace data as a text file on the device.

## Constraints

- Due to the asynchronous I/O feature of JS, the hiTraceMeter module provides only asynchronous APIs.

## Available APIs

The performance tracing APIs are provided by the **hiTraceMeter** module. For details, see [API Reference]( ../reference/apis/js-apis-hitracemeter.md).

**APIs for performance tracing**

| API                                                   | Return Value | Description                                                                                                                  |
| ------------------------------------------------------ | ---- | -------------------------------------------------------------------------------------------------------------------- |
| hiTraceMeter.startTrace(name: string, taskId: number)  | void | Marks the start of a trace task. If multiple trace tasks with the same name need to be performed at the same time or a trace task needs to be performed multiple times concurrently, different task IDs must be specified in **startTrace**. If the trace tasks with the same name are not performed at the same time, the same task ID can be used.|
| hiTraceMeter.finishTrace(name: string, taskId: number) | void | Marks the end of a trace task. The values of **name** and **taskId** must be the same as those of **hiTraceMeter.startTrace**.                                                                |
| hiTraceMeter.traceByValue(name: string, value: number) | void | Marks the value changes of a numeric variable in a trace task.                                                                                         |

## How to Develop

Start performance tracing upon page loading and stop it upon completion of service usage.

1. Create an ArkTS application project. In the displayed **Project** window, choose **entry** > **src** > **main** > **ets** > **pages** > **index**, and double-click **index.js**. Add the code to implement performance tracing upon page loading. For example, if the name of the trace task is **HITRACE\_TAG\_APP**, the sample code is as follows:
 
   ```ts
   import hiTraceMeter from '@ohos.hiTraceMeter';
  
   @Entry
   @Component
   struct Index {
     @State message: string = 'Running';
 
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(() => {
               this.message = 'Hello ArkUI';

               // Start trace tasks with the same name concurrently.
               hiTraceMeter.startTrace("HITRACE_TAG_APP", 1001);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
   
               // Start the second trace task with the same name while the first task is still running. The tasks are running concurrently and therefore their taskId must be different.
               hiTraceMeter.startTrace("HITRACE_TAG_APP", 1002);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
  
               hiTraceMeter.finishTrace("HITRACE_TAG_APP", 1001);
               hiTraceMeter.finishTrace("HITRACE_TAG_APP", 1002);
   
               // If trace tasks with the same name are not run concurrently, the same taskId can be used.
               hiTraceMeter.startTrace("HITRACE_TAG_APP", 1003);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
               // End the first trace task.
               hiTraceMeter.finishTrace("HITRACE_TAG_APP", 1003);
   
               // Start the second trace task with the same name in serial mode. It uses a taskId different from the first trace task.
               hiTraceMeter.startTrace("HITRACE_TAG_APP", 1004);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
               let traceCount = 3;
               hiTraceMeter.traceByValue("myTestCount", traceCount);
               hiTraceMeter.finishTrace("HITRACE_TAG_APP", 1004);
   
               // Start the third trace task with the same name in serial mode. It uses a taskId same as the second trace task.
               hiTraceMeter.startTrace("HITRACE_TAG_APP", 1004);
               // Keep the service process running.
               console.log(`HITRACE_TAG_APP running`);
               // End the third trace task.
               hiTraceMeter.finishTrace("HITRACE_TAG_APP", 1004);
   
             })
          }
          .width('100%')
        }
        .height('100%')
      }
   }
   ```
   
3. Click the run button on the application page. Then, run the following commands in sequence in shell:
 
   ```shell
   hdc shell
   hitrace --trace_begin app
   ```
   
   After the trace command is executed, call the hiTraceMeter APIs in your own service logic on the device. Then,  run the following commands in sequence:
  
   ```shell
   hitrace --trace_dump | grep tracing_mark_write
   hitrace --trace_finish
   ```
  
   The following is an example of the captured trace data:
  
   ```
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
