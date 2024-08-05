# @ohos.uiAppearance (UI Appearance) (System API)

The **uiAppearance** module provides basic capabilities for managing the system appearance. It allows for color mode configuration currently, and will introduce more features over time.

> **NOTE**
>
> The APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.


## Modules to Import

```ts
import { uiAppearance } from '@kit.ArkUI'
```


## DarkMode

Enumerates the color modes.


**System capability**: SystemCapability.ArkUI.UiAppearance

| Name | Value | Description |
| -- | -- | -- |
| ALWAYS_DARK | 0 | The system is always in dark mode. |
| ALWAYS_LIGHT | 1 | The system is always in light mode. |


## uiAppearance.setDarkMode

setDarkMode(mode: DarkMode, callback: AsyncCallback\<void>): void

Sets the system color mode. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.ArkUI.UiAppearance

**Parameters** 

| Name | Type | Mandatory | Description |
| -- | -- | -- | -- |
| mode | [DarkMode](#darkmode) | Yes | Color mode to set. |
| callback | AsyncCallback\<void>| Yes | Callback used to return the result. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [UI Appearance Error Codes](errorcode-uiappearance.md).

| ID | Error Message |
| -- | -- |
| 201 | Permission denied. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 500001 | Internal error. |

**Example** 

  ```ts
import { uiAppearance } from '@kit.ArkUI'
import { BusinessError } from '@kit.BasicServicesKit';
try {
    uiAppearance.setDarkMode(uiAppearance.DarkMode.ALWAYS_DARK, (error) => {
      if (error) {
        console.error('Set dark-mode failed, ' + error.message);
      } else {
        console.info('Set dark-mode successfully.');
      }
    })
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('Set dark-mode failed, ' + message);
}
  ```


## uiAppearance.setDarkMode

setDarkMode(mode: DarkMode): Promise\<void>;

Sets the system color mode. This API uses a promise to return the result.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.ArkUI.UiAppearance

**Parameters** 

| Name | Type | Mandatory | Description |
| -- | -- | -- | -- |
| mode | [DarkMode](#darkmode) | Yes | Color mode to set. |

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [UI Appearance Error Codes](errorcode-uiappearance.md).

| ID | Error Message |
| -- | -- |
| 201 | Permission denied. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 500001 | Internal error. |

**Example** 

  ```ts
import { uiAppearance } from '@kit.ArkUI'
import { BusinessError } from '@kit.BasicServicesKit';
try {
    uiAppearance.setDarkMode(uiAppearance.DarkMode.ALWAYS_DARK).then(() => {
      console.info('Set dark-mode successfully.');
    }).catch((error:Error) => {
      console.error('Set dark-mode failed, ' + error.message);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('Set dark-mode failed, ' + message);
}
  ```


## uiAppearance.getDarkMode

getDarkMode(): DarkMode;

Obtains the system color mode.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.ArkUI.UiAppearance

**Return value** 

| Type | Description |
| -- | -- |
|[DarkMode](#darkmode) | Color mode obtained. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [UI Appearance Error Codes](errorcode-uiappearance.md).

| ID | Error Message |
| -- | -- |
| 201 | Permission denied. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 500001 | Internal error. |

**Example** 

  ```ts
import { uiAppearance } from '@kit.ArkUI'
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let darkMode = uiAppearance.getDarkMode();
    console.info('Get dark-mode ' + darkMode);
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('Get dark-mode failed, ' + message);
}
  ```
