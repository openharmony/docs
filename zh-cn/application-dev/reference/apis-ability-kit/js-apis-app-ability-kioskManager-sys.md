# @ohos.app.ability.kioskManager (Kiosk模式管理)(系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhu-feimo-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

KioskManager模块提供Kiosk模式管理能力，包括系统进入/退出Kiosk模式操作、查询当前系统Kiosk模式状态。

该模块仅适用于企业应用。企业应用可以使用该模式将设备锁定至单一应用，确保界面只服务于特定的交互场景，例如银行ATM设备软件、KTV点歌系统、点餐系统等。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.app.ability.kioskManager (Kiosk模式管理)](js-apis-app-ability-kioskManager.md)。

## 导入模块

```ts
import { kioskManager } from '@kit.AbilityKit';
```

## kioskManager.getKioskStatus

getKioskStatus(): Promise&lt;KioskStatus&gt;

获取系统Kiosk模式的状态信息（包括当前系统是否处于Kiosk模式、进入Kiosk模式应用的名称和UID。）使用Promise异步回调。

**系统能力**： SystemCapability.Ability.AbilityRuntime.Core

**系统接口：** 此接口为系统接口。

**返回值：**

| 类型 | 说明 |
|------|------|
| Promise&lt;[KioskStatus](./js-apis-app-ability-kioskManager.md#kioskstatus20)&gt; | Promise对象，返回当前Kiosk状态信息。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
|---------|---------|
| 202 | Not system application. |
| 801 | Capability not supported. |
| 16000050 | Internal error. |

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
