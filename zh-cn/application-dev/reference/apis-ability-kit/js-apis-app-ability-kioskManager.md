# @ohos.app.ability.kioskManager (Kiosk模式管理)

KioskManager模块提供Kiosk模式管理能力，包括系统进入/退出Kiosk模式操作。

该模块仅适用于企业应用。企业应用可以使用该模式将设备锁定至单一应用，确保界面只服务于特定的交互场景，例如银行ATM设备软件、KTV点歌系统、点餐系统等。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { kioskManager } from '@kit.AbilityKit';
```

## kioskManager.enterKioskMode

enterKioskMode(context: UIAbilityContext): Promise&lt;void&gt;

进入Kiosk模式。使用Promise异步回调。

该接口仅适用于EDM配置的支持Kiosk模式的应用。

**系统能力**： SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| context | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | 是 | 当前UIAbility的上下文。 |

**返回值：**

| 类型 | 说明 |
|------|------|
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
|---------|---------|
| 801 | Capability not support. |
| 16000050 | Internal error. |
| 16000110 | Current application is not in kiosk app list, can not enter kiosk mode. |
| 16000111 | System is already in kiosk mode, can not enter again. |
| 16000113 | Current ability is not in foreground. |

**示例**：

```ts
import { common, kioskManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  private uiAbilityContext: common.UIAbilityContext | undefined =
    this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Button('enterKioskMode').margin({ top: 30 })
        .onClick(() => {
          kioskManager.enterKioskMode(this.uiAbilityContext)
            .then(() => {
              hilog.info(0x0000, 'testTag', '%{public}s', 'enterKioskMode success');
            })
            .catch((error: BusinessError) => {
              hilog.error(0x0000, 'testTag', '%{public}s', `enterKioskMode failed:${JSON.stringify(error)}`);
            });
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## kioskManager.exitKioskMode

exitKioskMode(context: UIAbilityContext): Promise&lt;void&gt;

退出Kiosk模式。使用Promise异步回调。

该接口仅对已进入Kiosk模式的应用生效。

**系统能力**： SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| context | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | 是 | 当前UIAbility的上下文。 |

**返回值：**

| 类型 | 说明 |
|------|------|
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
|---------|---------|
| 801 | Capability not support. |
| 16000050 | Internal error. |
| 16000110 | Current application is not in kiosk app list, can not exit kiosk mode. |
| 16000112 | Current application is not in kiosk mode, can not exit. |

**示例**：

```ts
import { common, kioskManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  private uiAbilityContext: common.UIAbilityContext | undefined =
    this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Button('exitKioskMode').margin({ top: 10 })
        .onClick(() => {
          kioskManager.exitKioskMode(this.uiAbilityContext)
            .then(() => {
              hilog.info(0x0000, 'testTag', '%{public}s', 'exitKioskMode success');
            })
            .catch((error: BusinessError) => {
              hilog.error(0x0000, 'testTag', '%{public}s', `exitKioskMode failed:${JSON.stringify(error)}`);
            });
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## KioskStatus<sup>20+</sup>

type KioskStatus = _KioskStatus

Kiosk状态信息，包括系统是否处于Kiosk模式以及该模式下的应用信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_KioskStatus](js-apis-application-KioskStatus.md#kioskstatus) | 表示Kiosk状态信息，包括系统是否处于Kiosk模式以及该模式下的应用信息。 |
