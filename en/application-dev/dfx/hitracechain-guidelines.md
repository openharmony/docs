# Development of Distributed Call Chain Tracing

## When to Use

HiTraceChain is the module that provides APIs to implement call chain tracing throughout a service process. With HiTraceChain, you can quickly obtain the run log for the call chain of a specified service process and locate faults in inter-device, inter-process, or inter-thread communications.

## Available APIs

The APIs for distributed call chain tracing are provided by the **hiTraceChain** module. For details, see [API Reference](../reference/apis/js-apis-hitracechain.md).

**APIs for distributed call chain tracing**

| API| Return Value| Description|
| ------------------------------------------------------------------------------------------------------------------- | -------------- | ------------ |
| hiTraceChain.begin(name: string, flags: number = HiTraceFlag.DEFAULT)                                               | HiTraceId      | Starts call chain tracing.|
| hiTraceChain.tracepoint(mode: HiTraceCommunicationMode, type: HiTraceTracepointType, id: HiTraceId, msg?: string)   | void           | Creates a trace point.|
| hiTraceChain.end(id: HiTraceId)                                                                                     | void           | Stops call chain tracing.|

## How to Develop

In this example, distributed call chain tracing begins when the application startup execution page is loaded and stops when the service usage is completed.

1. Create a JS application project. In the displayed **Project** window, choose **entry** > **src** > **main** > **js** > **default** > **pages** > **index**, and double-click **index.js**. Add the code to implement call chain tracing upon page loading. The sample code is as follows:

   ```
   import hiTraceChain from '@ohos.hiTraceChain'

   export default {
       data: {
           title: ""
       },
       onInit() {
           this.title = this.$t('strings.world');

           // 1. Enable distributed call chain tracing.
           let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC | hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
           
           // 2. Start the service process.
           console.log(`business start`);

           // 3. Add a trace point.
           hiTraceChain.tracepoint(hiTraceChain.HiTraceCommunicationMode.THREAD, hiTraceChain.HiTraceTracepointType.SS, asyncTraceId, "Just an example");

           // 4. Keep the service process running.
           console.log(`business running`);

           // 5. End the service process.
           console.log(`business end`);

           // 6. Stop call chain tracing.
           hiTraceChain.end(asyncTraceId);
       }
   }
   ```

2. Click the run button on the application page. Then, you'll obtain the log information for service analysis.
