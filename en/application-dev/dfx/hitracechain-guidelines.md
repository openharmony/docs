# Development of Distributed Call Chain Tracing

## Overview

hiTraceChain is a lightweight implementation of the cloud-based distributed call chain tracing. It allows applications to trace cross-thread, cross-process, and cross-device service calls. The hiTraceChain module generates a unique **chainId** for a service process and passes it to various information (including application events, system time, and logs) specific to the service process. During debugging and fault locating, you can use the unique **chainId** to quickly correlate various information related to the service process. The hiTraceChain module provides APIs to implement call chain tracing throughout a service process. This can help you quickly obtain the run log for the call chain of a specified service process and locate faults in inter-device, inter-process, or inter-thread communications.

## Basic Concepts

- **chainId**

  Distributed call chain tracing ID, which is a part of **HiTraceId** and is used to identify the service process being traced.

## Available APIs

The APIs for distributed call chain tracing are provided by the **hiTraceChain** module. For details, see [API Reference](../reference/apis/js-apis-hitracechain.md).

**APIs for distributed call chain tracing**

| API                                                                                                             | Return Value        | Description                        |
| ------------------------------------------------------------------------------------------------------------------- | -------------- | ------------                 |
| hiTraceChain.begin(name: string, flags: number = HiTraceFlag.DEFAULT)                                               | HiTraceId      | Starts call chain tracing.                  |
| hiTraceChain.end(id: HiTraceId)                                                                                     | void           | Stops call chain tracing.                  |

## How to Develop

The following example illustrates how to simulate one-time [system event logging](../reference/apis/js-apis-hiappevent.md) to implement distributed call chain tracing.

1. Create an eTS application project. In the displayed **Project** window, choose **entry** > **src** > **main** > **ets** > **pages** > **index.ets**, and double-click **index.ets**. Then, add a button to trigger system event logging.

    ```ts
    import hiAppEvent from '@ohos.hiviewdfx.hiAppEvent'
    import hilog from '@ohos.hilog'
    import hiTraceChain from '@ohos.hiTraceChain'
    import { BusinessError } from '@ohos.base'

    @Entry
    @Component
    struct Index {
      @State message: string = 'Start writing an app event'

      build() {
        Row() {
          Column() {
            Button(this.message)
              .fontSize(20)
              .margin(5)
              .width(350)
              .height(60)
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                try {
                  // Enable distributed call chain tracing before the service starts.
                  let traceId = hiTraceChain.begin("Write a new app event", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC)
                  // Enable event logging in the button click function to log button click events.
                  let eventParams: Record<string, number> = { 'click_time': 100 }
                  let eventInfo: hiAppEvent.AppEventInfo = {
                    // Define the event domain.
                    domain: "button",
                    // Define the event name.
                    name: "click",
                    // Define the event type.
                    eventType: hiAppEvent.EventType.BEHAVIOR,
                    // Define event parameters.
                    params: eventParams,
                  }
                  hiAppEvent.write(eventInfo).then(() => {
                    hilog.info(0x0000, 'testTag', `Succeed to write an app event`)
                    // Disable distributed call chain tracing when the service ends.
                    hiTraceChain.end(traceId)
                  }).catch((err: BusinessError) => {
                    hilog.error(0x0000, 'testTag', `HiAppEvent err.code: ${err.code}, err.message: ${err.message}`)
                  })
                } catch (err) {
                  console.error(`error message is ${(err as BusinessError).message}`)
                }
              })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```

2. Touch the run button on the IDE to run the project. Then, touch the **Start writing an app event** button on the application UI to trigger system event logging.

3. View the information printed in the **Log** window. You can use **.*\[([0-9a-zA-Z]{15}).*].*** to access distributed call chain tracing information specific to the service. The process ID of the service is **21519**. Two threads, whose IDs are **21519** and **23924**, are involved in the system event logging. Based on the chain ID **a92ab94c18e1341**, you can then effectively trace the log information of the two threads.
    ```text
    11-02 15:13:28.922  21519-21519  C02D03/HiTraceC                  com.example.hitracechaintest     I  [a92ab94c18e1341 0 0][dict]HiTraceBegin name:Write a new app event flags:0x01.
    11-02 15:13:28.924  21519-21519  C03915/AceInputTracking          com.example.hitracechaintest     I  [a92ab94c18e1341 0 0][ace_view_ohos.cpp(operator())-(0)] touch Event markProcessed in ace_view, eventInfo: id:764
    11-02 15:13:28.926  21519-23924  C02D07/HiAppEvent_ObserverMgr    com.example.hitracechaintest     I  [a92ab94c18e1341 0 0]start to handle event
    11-02 15:13:28.930  21519-21519  A00000/testTag                   com.example.hitracechaintest     I  [a92ab94c18e1341 324c3a3 0]Succeed to write an app event
    11-02 15:13:28.930  21519-21519  C02D03/HiTraceC                  com.example.hitracechaintest     I  [a92ab94c18e1341 324c3a3 0][dict]HiTraceEnd.
   ```

## About Cross-Process/Cross-Device Distributed Call Chain Tracing

Cross-process/cross-device distributed call chain tracing depends on the NAPI implementation of the corresponding service APIs of each OpenHarmony module. For details, see the [HiTraceChain Development](../../device-dev/subsystems/subsys-dfx-hitracechain.md).
