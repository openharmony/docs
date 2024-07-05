# 使用HiTraceChain打点（ArkTS/JS）

## 简介

HiTraceChain是基于云计算分布式跟踪调用链思想，在端侧业务流程（涉及跨线程、跨进程、跨设备）中的一种轻量级实现。hiTraceChain在业务控制面流程中，生成和传递唯一跟踪标识，在业务流程中输出的各类信息中（包括应用事件、系统时间、日志等）记录该跟踪标识。在调试、问题定位过程中，开发者可以通过该唯一跟踪标识将本次业务流程端到端的各类信息快速关联起来。hiTraceChain为开发者提供业务流程调用链跟踪的维测接口，帮助开发者迅速获取指定业务流程调用链的运行日志，定位跨设备/跨进程/跨线程的故障问题。

## 基本概念

**chainId**：分布式跟踪标识，属于HiTraceId的一部分，用于标识当前跟踪的业务流程。

## 接口说明

分布式跟踪接口由hiTraceChain模块提供，详细API请参考[分布式跟踪API参考](../reference/apis-performance-analysis-kit/js-apis-hitracechain.md)。

**分布式跟踪接口功能介绍：**

| 接口名                                                                   | 描述         |
| ------------------------------------------------------------------------|------------ |
| hiTraceChain.begin(name: string, flags?: number = HiTraceFlag.DEFAULT)   |开始跟踪。   |
| hiTraceChain.end(id: HiTraceId)                                          |结束跟踪。    |

## 开发步骤

以构造单次[应用事件打点](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md)的业务说明分布式调用链的使用方法。

1. 新建一个ets应用工程，编辑工程中的“entry > src > main > ets  > pages > index.ets” 文件，添加一个按钮，完整示例代码如下：

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
                  // 业务开始前，开启分布式跟踪。
                  let traceId = hiTraceChain.begin("Write a new app event", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC)
                  // 在按钮点击函数中进行事件打点，以记录按钮点击事件
                  let eventParams: Record<string, number> = { 'click_time': 100 }
                  let eventInfo: hiAppEvent.AppEventInfo = {
                    // 事件领域定义
                    domain: "button",
                    // 事件名称定义
                    name: "click",
                    // 事件类型定义
                    eventType: hiAppEvent.EventType.BEHAVIOR,
                    // 事件参数定义
                    params: eventParams,
                  }
                  hiAppEvent.write(eventInfo).then(() => {
                    hilog.info(0x0000, 'testTag', `Succeed to write an app event`)
                    // 业务结束，关闭分布式跟踪。
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

2. 点击IDE界面中的运行按钮，运行应用工程，然后在应用界面中点击“Start writing an app event”按钮，触发业务逻辑。

3. 在Log窗口查看分布式跟踪的相关信息，使用“.*\[([0-9a-zA-Z]{15}).*].*”过滤日志，查看该业务的分布式跟踪信息。hap进程号为“21519”，点击按钮触发的系统事件打点业务涉及到“21519”与“23924”两个线程，通过值为“a92ab94c18e1341”的chainId可以有效跟踪涉及该业务的所有线程的日志信息。
    ```text
    11-02 15:13:28.922  21519-21519  C02D03/HiTraceC                  com.example.hitracechaintest     I  [a92ab94c18e1341 0 0][dict]HiTraceBegin name:Write a new app event flags:0x01.
    11-02 15:13:28.924  21519-21519  C03915/AceInputTracking          com.example.hitracechaintest     I  [a92ab94c18e1341 0 0][ace_view_ohos.cpp(operator())-(0)] touch Event markProcessed in ace_view, eventInfo: id:764
    11-02 15:13:28.926  21519-23924  C02D07/HiAppEvent_ObserverMgr    com.example.hitracechaintest     I  [a92ab94c18e1341 0 0]start to handle event
    11-02 15:13:28.930  21519-21519  A00000/testTag                   com.example.hitracechaintest     I  [a92ab94c18e1341 324c3a3 0]Succeed to write an app event
    11-02 15:13:28.930  21519-21519  C02D03/HiTraceC                  com.example.hitracechaintest     I  [a92ab94c18e1341 324c3a3 0][dict]HiTraceEnd.
   ```

## 跨进程/跨设备分布式跟踪说明

跨进程/跨设备分布式跟踪依赖于OpenHarmony各模块相应业务接口的napi实现是否存在进程及设备之间的通信调用<!--Del-->，具体请参考<!--Del-->[HiTraceChain开发指导](../../device-dev/subsystems/subsys-dfx-hitracechain.md)<!--DelEnd-->。
