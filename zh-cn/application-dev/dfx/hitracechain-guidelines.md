# 分布式跟踪开发指导

## 简介

hiTraceChain是基于云计算分布式跟踪调用链思想，在端侧业务流程（涉及跨线程、跨进程、跨设备）中的一种轻量级实现。hiTraceChain在业务控制面流程中，生成和传递唯一跟踪标识，在业务流程中输出的各类信息中（包括应用事件、系统时间、日志等）记录该跟踪标识。在调试、问题定位过程中，开发者可以通过该唯一跟踪标识将本次业务流程端到端的各类信息快速关联起来。hiTraceChain为开发者提供业务流程调用链跟踪的维测接口，帮助开发者迅速获取指定业务流程调用链的运行日志，定位跨设备/跨进程/跨线程的故障问题。

## 基本概念

- **chainId**

  分布式跟踪标识，属于HiTraceId的一部分，用于标识当前跟踪的业务流程。

## 接口说明

分布式跟踪接口由hiTraceChain模块提供，详细API请参考[分布式跟踪API参考](../reference/apis/js-apis-hitracechain.md)。

**分布式跟踪接口功能介绍：**

| 接口名                                                                                                              | 返回值         | 描述                         |
| ------------------------------------------------------------------------------------------------------------------- | -------------- | ------------                 |
| hiTraceChain.begin(name: string, flags: number = HiTraceFlag.DEFAULT)                                               | HiTraceId      | 开始跟踪。                   |
| hiTraceChain.end(id: HiTraceId)                                                                                     | void           | 结束跟踪。                   |

## 开发步骤

以构造单次[系统事件打点](../reference/apis/js-apis-hisysevent.md)的业务说明在单hap业务跨线程中分布式调用链的使用方法。

1. 新建一个ets应用工程，编辑工程中的“entry > src > main > ets  > pages > index.ets” 文件，添加一个按钮，完整示例代码如下：

    ```ts
    import hiTraceChain from '@ohos.hiTraceChain';
    import hiSysEvent from '@ohos.hiSysEvent';

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
                  // 业务开始前，开启分布式跟踪。
                  let traceId = hiTraceChain.begin("Write a new system event", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
                  // 业务开始：完成一次系统事件打点。
                  hiSysEvent.write({
                    domain: "RELIABILITY",
                    name: "STACK",
                    eventType: hiSysEvent.EventType.FAULT,
                    params: {
                      PID: 1,
                      UID: 1,
                      PACKAGE_NAME: "com.demo.hitracechain",
                      PROCESS_NAME: "hitracechaindemo",
                      MSG: "no msg."
                    }
                  }).then((val) => {
                    console.info(`write result is ${val}`);
                    // 业务结束，关闭分布式跟踪。
                    hiTraceChain.end(traceId);
                  }).catch((err) => {
                    console.error(`error message is ${err.message}`);
                  });
                } catch (err) {
                  console.error(`error message is ${err.message}`);
                }
              })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```

2. 点击IDE界面中的运行按钮，运行应用工程，然后在应用界面中点击“Start writing system event”按钮，触发业务逻辑。

3. 在Log窗口查看分布式跟踪的相关信息，使用“.*: \[([0-9a-zA-Z]{15}),.*].*”过滤日志，查看该业务的分布式跟踪信息。hap进程号为“8801”，点击按钮触发的系统事件打点业务涉及到“8801”与“8819”两个线程，通过值为“edcfa53017a88e3”的chainId可以有效跟踪涉及该业务的所有线程的日志信息。
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

## 跨进程/跨设备分布式跟踪说明

跨进程/跨设备分布式跟踪依赖于OpenHarmony各模块相应业务接口的napi实现是否存在进程及设备之间的通信调用，具体请参考[HiTraceChain开发指导](../../device-dev/subsystems/subsys-dfx-hitracechain.md)。