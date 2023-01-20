# Development of Performance Tracing

## Introduction

hiTraceMeter provides APIs for system performance tracing. You can call the APIs provided by the hiTraceMeter module in your own service logic to effectively track service processes and check the system performance.

## Basic Concepts

- **hiTraceMeter Tag**

  Tag used for tracing data categorization. It is also known as **hiTraceMeter Category**. Generally, one subsystem maps to a tag. The tag is passed as the **Tag** parameter in performance tracing APIs. When you use the hiTraceMeter CLI tool to collect tracing data, only the tracing data specified by the **Tag** parameter is collected.

## Working Principles

- The application calls hiTraceMeter APIs to perform performance tracing. The APIs output the tracing data to the kernel's ftrace data buffer through the kernel's sysfs file interface.
- The hiTraceMeter CLI tool reads the tracing data in the ftrace data buffer and saves the trace data as a text file on the device.

## Constraints

Due to the asynchronous I/O feature of JS, the hiTraceMeter module provides only asynchronous APIs.

## Available APIs
 
The performance tracing APIs are provided by the **hiTraceMeter** module. For details, see [API Reference](../reference/apis/js-apis-hitracemeter.md).

**Table 1** APIs for performance tracing

| API| Return Value| Description|
| ---------------------------------------------------------------------------- | --------- | ------------ |
| hiTraceMeter.startTrace(name: string, taskId: number) | void      | Starts a trace task. If multiple trace tasks with the same name need to be performed at the same time or a trace task needs to be performed multiple times concurrently, different task IDs must be specified in **startTrace**. If the trace tasks with the same name are not performed at the same time, the same task ID can be used.|
| hiTraceMeter.finishTrace(name: string, taskId: number)                       | void      | Stops a trace task. The values of **name** and **taskId** must be the same as those of **hiTraceMeter.startTrace**.|
| hiTraceMeter.traceByValue(name: string, value: number)                       | void      | Traces the value changes of a variable.|

## How to Develop

In this example, distributed call chain tracing begins when the application startup execution page is loaded and stops when the service usage is completed.

1. Create a JS application project. In the displayed **Project** window, choose **entry** > **src** > **main** > **js** > **default** > **pages** > **index**, and double-click **index.js**. Add the code to implement performance tracing upon page loading. The sample code is as follows:

   ```js
   import hiTraceMeter from '@ohos.hiTraceMeter'

   export default {
       data: {
           title: ""
       },
       onInit() {
           this.title = this.$t('strings.world');
           
           // Start track tasks with the same name concurrently.
           hiTraceMeter.startTrace("business", 1);
           // Keep the service process running.
           console.log(`business running`);
           hiTraceMeter.startTrace("business", 2);  // Start the second trace task while the first task is still running. The first and second tasks have the same name but different task IDs.
           // Keep the service process running.
           console.log(`business running`);
           hiTraceMeter.finishTrace("business", 1);
           // Keep the service process running.
           console.log(`business running`);
           hiTraceMeter.finishTrace("business", 2);

           // Start track tasks with the same name at different times.
           hiTraceMeter.startTrace("business", 1);
           // Keep the service process running.
           console.log(`business running`);
           hiTraceMeter.finishTrace("business", 1);  // End the first trace task.
           // Keep the service process running.
           console.log(`business running`);
           hiTraceMeter.startTrace("business", 1);   // Start the second trace task after the first trace task ends. The two tasks have the same name and task ID. 
           // Keep the service process running.
           console.log(`business running`);

           let traceCount = 3;
           hiTraceMeter.traceByValue("myTestCount", traceCount);
           traceCount = 4;
           hiTraceMeter.traceByValue("myTestCount", traceCount);
           hiTraceMeter.finishTrace("business", 1);
       }
   }
   ```

2. Click the run button on the application page. Then, you'll obtain the log information for service analysis.
