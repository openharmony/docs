# Development of Distributed Call Chain Tracing

## Introduction

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

The following example illustrates how to simulate one-time [system event logging](../reference/apis/js-apis-hisysevent.md) to implement cross-thread distributed call chain tracing in a single HAP service.

1. Create an eTS application project. In the displayed **Project** window, choose **entry** > **src** > **main** > **ets** > **pages** > **index.ets**, and double-click **index.ets**. Then, add a button to trigger system event logging.

    ```ts
    import hiTraceChain from '@ohos.hiTraceChain';
    import hiSysEvent from '@ohos.hiSysEvent';
    import { BusinessError } from '@ohos.base';

    @Entry
    @Component
    struct Index {
      @State message: string = 'Start writing system event';

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
                  let traceId = hiTraceChain.begin("Write a new system event", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
                  // Implement one-time system event logging when the service starts.
                  let customizedParams: Record<string, string | number> = {
                    'PID': 1,
                    'UID': 1,
                    'PACKAGE_NAME': "com.demo.hitracechain",
                    'PROCESS_NAME': "hitracechaindemo",
                    'MSG': "no msg."
                  };
                  let eventInfo: hiSysEvent.SysEventInfo = {
                    domain: "RELIABILITY",
                    name: "STACK",
                    eventType: hiSysEvent.EventType.FAULT,
                    params: customizedParams
                  };
                  hiSysEvent.write(eventInfo).then(() => {
                    // Disable distributed call chain tracing when the service ends.
                    hiTraceChain.end(traceId);
                  }).catch((err: BusinessError) => {
                    console.error(`error message is ${err.message}`);
                  });
                } catch (err) {
                  console.error(`error message is ${(err as BusinessError).message}`);
                }
              })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```

2. Touch the run button on the IDE to run the project. Then, touch the **Start writing system event** button on the application UI to trigger system event logging.

3. View the information printed in the **Log** window. You can use **.*: \[([0-9a-zA-Z]{15}),.*].*** to access distributed call chain tracing information specific to the HAP service. The process ID of the HAP service is **8801**. Two threads, whose IDs are **8801** and **8819**, are involved in the system event logging. Based on the chain ID **edcfa53017a88e3**, you can then effectively trace the log information of the two threads.
    ```text
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain I C02d03/HiTraceC: [edcfa53017a88e3, 0, 0] HiTraceBegin name:Write a new system event flags:0x01.
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain D C02d03/HITRACE_UTIL_NAPI: [edcfa53017a88e3, 0, 0] Native2Js: chainId is edcfa53017a88e3.
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain D C02d03/HITRACE_UTIL_NAPI: [edcfa53017a88e3, 0, 0] Native2Js: spanId is 0.
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain D C02d03/HITRACE_UTIL_NAPI: [edcfa53017a88e3, 0, 0] Native2Js: parentSpanId is 0.
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain D C02d03/HITRACE_UTIL_NAPI: [edcfa53017a88e3, 0, 0] Native2Js: flags is 1.
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain D C02d08/NAPI_HISYSEVENT_UTIL: [edcfa53017a88e3, 0, 0] domain is RELIABILITY.
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain D C02d08/NAPI_HISYSEVENT_UTIL: [edcfa53017a88e3, 0, 0] name is STACK.
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain D C02d08/NAPI_HISYSEVENT_UTIL: [edcfa53017a88e3, 0, 0] eventType is 1.
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain E C02d08/NAPI_HISYSEVENT_UTIL: [edcfa53017a88e3, 0, 0] napi value type not match: valueType=3, typeName=6.
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain E C02d08/NAPI_HISYSEVENT_UTIL: [edcfa53017a88e3, 0, 0] napi value type not match: valueType=3, typeName=6.
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain E C02d08/NAPI_HISYSEVENT_UTIL: [edcfa53017a88e3, 0, 0] napi value type not match: valueType=4, typeName=6.
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain E C02d08/NAPI_HISYSEVENT_UTIL: [edcfa53017a88e3, 0, 0] napi value type not match: valueType=4, typeName=6.
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain E C02d08/NAPI_HISYSEVENT_UTIL: [edcfa53017a88e3, 0, 0] napi value type not match: valueType=4, typeName=6.
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain D C02d08/NAPI_HISYSEVENT_UTIL: [edcfa53017a88e3, 0, 0] create napi value of string type, value is JSHiSysEventWrite.
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain I C03900/Ace: [edcfa53017a88e3, 0, 0] [flutter_ace_view.cpp(operator())-(0)] Mark 0 id Touch Event Processed
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain D C02800/ClientMsgHandler: [edcfa53017a88e3, 0, 0] in OnDispatchEventProcessed, enter
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain D C02800/ANRHandler: [edcfa53017a88e3, 0, 0] in SetLastProcessedEventId, enter
    07-05 19:50:47.690 8801-8819/com.demo.hitracechain D C02d08/HISYSEVENT: [edcfa53017a88e3, 0, 0] size=312, sysevent={"domain_":"RELIABILITY","name_":"STACK","type_":1,"time_":47591447690,"tz_":"+0000","pid_":8801,"tid_":8819,"uid_":20010045,"traceid_":"edcfa53017a88e3","spanid_":"0","pspanid_":"0","trace_flag_":1,"UID":1,"PID":1,"MSG":"no msg.","PROCESS_NAME":"hitracechaindemo","PACKAGE_NAME":"com.demo.hitracechain"}
    07-05 19:50:47.690 8801-8801/com.demo.hitracechain D C02800/ANRHandler: [edcfa53017a88e3, 0, 0] in SetLastProcessedEventId, Processed event type:0, id:831, actionTime:6694499314, currentTime:6694501330, timeoutTime:4997984
    07-05 19:50:47.691 8801-8801/com.demo.hitracechain D C02800/ANRHandler: [edcfa53017a88e3, 0, 0] in SetLastProcessedEventId, leave
    07-05 19:50:47.691 8801-8801/com.demo.hitracechain D C02800/ClientMsgHandler: [edcfa53017a88e3, 0, 0] in OnDispatchEventProcessed, leave
    07-05 19:50:47.691 8801-8819/com.demo.hitracechain D C02d08/HISYSEVENT: [edcfa53017a88e3, 0, 0] reset send buffer size old=245760, new=524288
    07-05 19:50:47.691 8801-8819/com.demo.hitracechain D C02d08/HISYSEVENT: [edcfa53017a88e3, 0, 0] HiSysEvent send data successful
    07-05 19:50:47.691 8801-8801/com.demo.hitracechain D C02d08/NAPI_HISYSEVENT_UTIL: [edcfa53017a88e3, 0, 0] create napi value of int32 type, value is 0.
    07-05 19:50:47.691 8801-8801/com.demo.hitracechain E A0fefe/JsApp: [edcfa53017a88e3, 399db38, 0] write result is 0
    07-05 19:50:47.691 8801-8801/com.demo.hitracechain D C02d03/HITRACE_UTIL_NAPI: [edcfa53017a88e3, 399db38, 0] Js2Native: chainId is edcfa53017a88e3.
    07-05 19:50:47.691 8801-8801/com.demo.hitracechain D C02d03/HITRACE_UTIL_NAPI: [edcfa53017a88e3, 399db38, 0] Js2Native: spanId is 0.
    07-05 19:50:47.691 8801-8801/com.demo.hitracechain D C02d03/HITRACE_UTIL_NAPI: [edcfa53017a88e3, 399db38, 0] Js2Native: parentSpanId is 0.
    07-05 19:50:47.691 8801-8801/com.demo.hitracechain D C02d03/HITRACE_UTIL_NAPI: [edcfa53017a88e3, 399db38, 0] Js2Native: flags is 1.
    07-05 19:50:47.691 8801-8801/com.demo.hitracechain I C02d03/HiTraceC: [edcfa53017a88e3, 399db38, 0] HiTraceEnd.
   ```

## About Cross-Process/Cross-Device Distributed Call Chain Tracing

Cross-process/cross-device distributed call chain tracing depends on the NAPI implementation of the corresponding service APIs of each OpenHarmony module. For details, see the [HiTraceChain Development](../../device-dev/subsystems/subsys-dfx-hitracechain.md).
