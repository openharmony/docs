# Using HiTraceChain (ArkTS/JS)

## Overview

hiTraceChain is a lightweight implementation of the cloud-based distributed call chain tracing on the device side. It allows the calls made in a service process to be traced, helping locating issues across threads, processes, and devices. With hiTraceChain, a unique ID is generated for a service process, passed throughout the service process, and associated with various output information (including application events, system time, and logs). During debugging and fault locating, you can use this unique ID to quickly correlate various information related to the service process. hiTraceChain provides APIs to implement call chain tracing throughout a service process. This can help you quickly obtain the run log for the call chain of a service process and locate faults across devices, processes, and threads.

## Basic Concepts

**chainId**: a distributed trace ID that uniquely identifies a service process being traced. It is a part of **hiTraceId**.

## Available APIs

The APIs for distributed call chain tracing are provided by the **hiTraceChain** module. For details, see [Distributed Tracing](../reference/apis-performance-analysis-kit/js-apis-hitracechain.md).

**APIs for distributed call chain tracing**

| API                                                                  | Description        |
| ------------------------------------------------------------------------|------------ |
| hiTraceChain.begin(name: string, flags?: number = HiTraceFlag.DEFAULT)   |Starts call chain tracing.  |
| hiTraceChain.end(id: HiTraceId)                                          |Stops call chain tracing.   |

## How to Develop

The following example walks you through on how to implement distributed call chain tracing on  a one-time [application event logging](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

1. Create an ets application project. In the **entry/src/main/ets/pages/index.ets** file, add a button to trigger system event logging. The sample code is as follows:

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hiAppEvent, hilog, hiTraceChain } from '@kit.PerformanceAnalysisKit';

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
                  // Start distributed call chain tracing before the service starts.
                  let traceId = hiTraceChain.begin("Write a new app event", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC)
                  // Log a button onclick event when the button is clicked.
                  let eventParams: Record<string, number> = { 'click_time': 100 }
                  let eventInfo: hiAppEvent.AppEventInfo = {
                    // Define the event domain.
                    domain: "button",
                    // Define the event name.
                    name: "click",
                    // Define the event type.
                    eventType: hiAppEvent.EventType.BEHAVIOR,
                    // Define the event parameters.
                    params: eventParams,
                  }
                  hiAppEvent.write(eventInfo).then(() => {
                    hilog.info(0x0000, 'testTag', `Succeed to write an app event`)
                    // Stop distributed call chain tracing when the service ends.
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

2. In DevEco Studio, click the **Run** button to run the project. Then, click the **Start writing an app event** button on the application UI to trigger system event logging.

3. View the information printed in the **Log** window. <br>You can use **.*\[([0-9a-zA-Z]{15}).*].** to filter log information and view the distributed call chain tracing information specific to the service. <br>The process ID of the HAP service is **21519**. Two threads, whose IDs are **21519** and **23924**, are involved in the system event logging. Based on the chain ID **a92ab94c18e1341**, you can trace the log information of the two threads.
    ```text
    11-02 15:13:28.922  21519-21519  C02D03/HiTraceC                  com.example.hitracechaintest     I  [a92ab94c18e1341 0 0][dict]HiTraceBegin name:Write a new app event flags:0x01.
    11-02 15:13:28.924  21519-21519  C03915/AceInputTracking          com.example.hitracechaintest     I  [a92ab94c18e1341 0 0][ace_view_ohos.cpp(operator())-(0)] touch Event markProcessed in ace_view, eventInfo: id:764
    11-02 15:13:28.926  21519-23924  C02D07/HiAppEvent_ObserverMgr    com.example.hitracechaintest     I  [a92ab94c18e1341 0 0]start to handle event
    11-02 15:13:28.930  21519-21519  A00000/testTag                   com.example.hitracechaintest     I  [a92ab94c18e1341 324c3a3 0]Succeed to write an app event
    11-02 15:13:28.930  21519-21519  C02D03/HiTraceC                  com.example.hitracechaintest     I  [a92ab94c18e1341 324c3a3 0][dict]HiTraceEnd.
   ```

## Constraints

The distributed call chain tracing across processes or devices depends on whether inter-process or inter-device communication exists in the Node-API implementations of  OpenHarmony modules<!--Del-->. For details, see <!--Del-->[HiTraceChain Development Guide](../../device-dev/subsystems/subsys-dfx-hitracechain.md)<!--DelEnd-->.
