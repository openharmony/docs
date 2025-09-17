# @ohos.app.ability.kioskManager (Kiosk模式管理)(系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhu-feimo-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

KioskManager模块提供Kiosk模式管理能力，包括系统进入/退出Kiosk模式操作、查询当前系统Kiosk模式状态。

Kiosk模式是一种特殊的设备锁定模式，可以确保设备界面只服务于特定的交互场景。在这种模式下，用户只能使用特定的应用。例如，在银行ATM机上，用户只能通过ATM软件进行操作，而不能退出该软件或切换到其他应用。

> **说明：**
>
> - 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口仅可在Stage模型下使用。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.app.ability.kioskManager (Kiosk模式管理)](js-apis-app-ability-kioskManager.md)。

## 导入模块

```ts
import { kioskManager } from '@kit.AbilityKit';
```

## kioskManager.getKioskStatus

getKioskStatus(): Promise&lt;KioskStatus&gt;

获取系统Kiosk模式的状态信息（包括当前系统是否处于Kiosk模式、进入Kiosk模式应用的名称和UID）。使用Promise异步回调。

**系统能力**： SystemCapability.Ability.AbilityRuntime.Core

**系统接口：** 此接口为系统接口。

**设备行为差异**：该接口仅在2in1和Tablet设备中可正常调用，在其他设备中返回801错误码。

**返回值：**

| 类型 | 说明 |
|------|------|
| Promise&lt;[KioskStatus](./js-apis-app-ability-kioskManager.md#kioskstatus)&gt; | Promise对象，返回当前Kiosk状态信息。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
|---------|---------|
| 202 | Not system application. |
| 801 | Capability not supported. |
| 16000050 | Failed to connect to the system service. |

**示例**：

```ts
import { kioskManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    Column() {
      Button('getKioskinfo').margin({ top: 10 })
        .onClick(() => {
          kioskManager.getKioskStatus()
            .then((data: kioskManager.KioskStatus) => {
              hilog.info(0x0000, 'testTag', '%{public}s', `getKioskinfo success: ${JSON.stringify(data)}`);
            })
            .catch((error: BusinessError) => {
              hilog.error(0x0000, 'testTag', '%{public}s', `getKioskinfo failed:${JSON.stringify(error)}`);
            });
        })
    }
    .height('100%')
    .width('100%')
  }
}
```
