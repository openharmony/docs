# @ohos.app.ability.kioskManager (Kiosk Mode Management) (System APIs)

The KioskManager module provides APIs to manage kiosk mode, including entering/exiting kiosk mode and querying the kiosk mode status.

This module applies only to enterprise applications. In kiosk mode, an enterprise application can lock a device to a single application, ensuring that the UI serves only specific interactive scenarios, such as bank ATM terminals, KTV song-selection systems, and restaurant ordering systems.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module are system APIs and cannot be called by third-party applications.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.app.ability.kioskManager (Kiosk Mode Management)](js-apis-app-ability-kioskManager.md).

## Modules to Import

```ts
import { kioskManager } from '@kit.AbilityKit';
```

## getKioskStatus

getKioskStatus(): Promise&lt;KioskStatus&gt;

Obtains the Kiosk mode status information, including whether the system is in kiosk mode, and the name and UID of the application that has entered Kiosk mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Return value**

| Type| Description|
|------|------|
| Promise&lt;[KioskStatus](./js-apis-application-KioskStatus.md#kioskstatus)&gt; | Promise used to return the kiosk mode status information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
|---------|---------|
| 202 | Not system application. |
| 801 | Capability not support. |
| 16000050 | Internal error. |

**Example**

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
