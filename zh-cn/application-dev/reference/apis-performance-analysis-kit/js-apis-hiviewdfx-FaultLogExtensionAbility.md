# @ohos.hiviewdfx.FaultLogExtensionAbility (故障延迟通知)
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony-->
<!--Designer: @StevenLai1994-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

本模块实现故障的延迟通知功能。

[HiAppEvent](js-apis-hiviewdfx-hiappevent.md)订阅崩溃、应用冻屏事件时，只有当应用下次启动后才能接收上一次的事件。如果应用无法启动或长时间未打开，则存在故障无法及时上报的局限性。

本模块作为该场景的补充。在应用实现FaultLogExtensionAbility后，当应用发生崩溃或冻屏时，系统服务预计会在30分钟后拉起FaultLogExtensionAbility。
开发者可在[onFaultReportReady](#onfaultreportready)中订阅并处理故障事件。

> **说明：**
>
> - 本模块接口从API version 21开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { FaultLogExtensionAbility } from '@kit.PerformanceAnalysisKit';
```

## FaultLogExtensionAbility

应用接入故障延迟通知需要通过FaultLogExtensionAbility实现，开发者可以在[onFaultReportReady](#onfaultreportready)中订阅并处理故障事件。

> **注意:**
>
> - FaultLogExtensionAbility被拉起后只有很短的时间完成故障处理，建议处理时间不要超过10秒。超时没有处理完成可以在[onDisconnect](#ondisconnect)中保存状态。
> - 从开机或上次拉起FaultLogExtensionAbility后，应用首次触发崩溃或冻屏开始计时。在拉起FaultLogExtensionAbility前反复触发崩溃或冻屏事件均不会重新计时。
> - FaultLogExtensionAbility自身崩溃时，不会再次被系统服务拉起。

### 属性

**系统能力**：SystemCapability.HiviewDFX.Hiview.FaultLogger

| 名称 | 类型| 只读 | 可选 | 说明 |
| --- | --- | --- | --- | --- |
| context | [FaultLogExtensionContext](js-apis-hiviewdfx-FaultLogExtensionContext.md)。| 否 | 否 | FaultLogExtensionAbility的上下文环境，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。|

### onConnect

onConnect(): void

FaultLogExtensionAbility生命周期回调。当系统服务完成连接时调用此接口，用于执行初始化操作，该方法可选择性重写。

**系统能力**：SystemCapability.HiviewDFX.Hiview.FaultLogger

**示例：**
```ts
export default class MyFaultLogExtension extends FaultLogExtensionAbility {
    onConnect {
      console.info('onConnect');
    }
}
```

### onDisconnect

onDisconnect(): void

FaultLogExtensionAbility生命周期回调。当系统服务完成断开连接时调用此接口，用于释放资源清理运行状态，该方法可选择性重写。

**系统能力**：SystemCapability.HiviewDFX.Hiview.FaultLogger

**示例：**
```ts
export default class MyFaultLogExtension extends FaultLogExtensionAbility {
    onDisconnect {
      console.info('onDisconnect');
    }
}
```

### onFaultReportReady

onFaultReportReady(): void

FaultLogExtensionAbility回调。系统服务通知FaultLogExtensionAbility可以进行故障处理时,回调此接口,可以在该方法中订阅故障事件进行处理。

**系统能力**：SystemCapability.HiviewDFX.Hiview.FaultLogger

**示例：**
  ```ts
  import { hiAppEvent } from '@kit.PerformanceAnalysisKit';

  export default class MyFaultLogExtension extends FaultLogExtensionAbility {
      onFaultReportReady {
          hiAppEvent.addWatcher({
              name: "watcher",
              appEventFilters: [
                  {
                      domain: hiAppEvent.domain.OS,
                      name: [hiAppEvent.event.APP_CRASH, hiAppEvent.event.APP_FREEZE]
                  }
              ],
              onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
                  // 进行故障事件处理
              }
          });
      }
  }
  ```
