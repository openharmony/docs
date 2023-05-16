# @ohos.uiAppearance (UI Appearance)

The **uiAppearance** module provides basic capabilities for managing the system appearance. It allows for color mode configuration currently, and will introduce more features over time.

> **NOTE**
>
> The APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.


## Modules to Import

```ts
import uiAppearance from '@ohos.uiAppearance'
```


## DarkMode

Enumerates the color modes.


**System capability**: SystemCapability.ArkUI.UiAppearance

| Name| Value| Description|
| -- | -- | -- |
| ALWAYS_DARK | 0 | The system is always in dark mode. |
| ALWAYS_LIGHT | 1 | The system is always in light mode.|


## uiAppearance.setDarkMode

setDarkMode(mode: DarkMode, callback: AsyncCallback\<void>): void

Sets the system color mode. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.ArkUI.UiAppearance

**Parameters**
| Name| Type| Mandatory| Description|
| -- | -- | -- | -- |
| mode | [DarkMode](#darkmode) | Yes| Color mode to set.|
| callback | AsyncCallback\<void>| Yes| Callback used to return the result.|

**Example**
  ```ts
uiAppearance.setDarkMode(uiAppearance.DarkMode.ALWAYS_DARK, (err) => {
  console.info(`${err}`);
})
  ```


## uiAppearance.setDarkMode

setDarkMode(mode: DarkMode): Promise\<void>;

Sets the system color mode. This API uses a promise to return the result.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.ArkUI.UiAppearance

**Parameters**
| Name| Type| Mandatory| Description|
| -- | -- | -- | -- |
| mode | [DarkMode](#darkmode) | Yes| Color mode to set.|

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Example**
  ```ts
uiAppearance.setDarkMode(uiAppearance.DarkMode.ALWAYS_DARK).then(() => {
    console.log('Set dark-mode successfully.');
}).catch((err) => {
    console.log(`Set dark-mode failed, ${err}`);
});
  ```


## uiAppearance.getDarkMode

getDarkMode(): DarkMode;

Obtains the system color mode.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.ArkUI.UiAppearance

**Return value**
| Type| Description|
| -- | -- |
|[DarkMode](#darkmode) | Color mode obtained.|

**Example**
  ```ts
let darkMode = uiAppearance.getDarkMode();
console.log(`Get dark-mode ${darkMode}`);
  ```
