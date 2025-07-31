# @ohos.app.ability.kioskManager (Kiosk Mode Management)

The KioskManager module provides APIs to manage kiosk mode, including entering and exiting kiosk mode.

This module applies only to enterprise applications. In kiosk mode, an enterprise application can lock a device to a single application, ensuring that the UI serves only specific interactive scenarios, such as bank ATM terminals, KTV song-selection systems, and restaurant ordering systems.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { kioskManager } from '@kit.AbilityKit';
```

## enterKioskMode

enterKioskMode(context: UIAbilityContext): Promise&lt;void&gt;

Enters kiosk mode. This API uses a promise to return the result.

This API applies only to EDM-configured applications that support kiosk mode.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| context | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | Yes| Context of the UIAbility.|

**Return value**

| Type| Description|
|------|------|
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
|---------|---------|
| 801 | Capability not support. |
| 16000050 | Internal error. |
| 16000110 | Current application is not in kiosk app list, can not enter kiosk mode. |
| 16000111 | System is already in kiosk mode, can not enter again. |
| 16000113 | Current ability is not in foreground. |

**Example**

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

## exitKioskMode

exitKioskMode(context: UIAbilityContext): Promise&lt;void&gt;

Exits kiosk mode. This API uses a promise to return the result.

This API takes effect only for applications that have entered kiosk mode.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| context | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | Yes| Context of the UIAbility.|

**Return value**

| Type| Description|
|------|------|
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
|---------|---------|
| 801 | Capability not support. |
| 16000050 | Internal error. |
| 16000110 | Current application is not in kiosk app list, can not exit kiosk mode. |
| 16000112 | Current application is not in kiosk mode, can not exit. |

**Example**

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
