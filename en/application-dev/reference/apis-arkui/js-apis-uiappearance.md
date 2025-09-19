# @ohos.uiAppearance (UI Appearance)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @lushi871202-->
<!--Designer: @lushi871202-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

Provides capabilities for retrieving system appearance configurations, including dark/light mode, font size scaling, and font weight scaling.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { uiAppearance } from '@kit.ArkUI';
```

## DarkMode

Enumerates the color modes.

**System capability**: SystemCapability.ArkUI.UiAppearance

| Name          | Value | Description                  |
| ------------- | ----- | ---------------------------- |
| ALWAYS_DARK   | 0     | The system is always in dark mode.  |
| ALWAYS_LIGHT  | 1     | The system is always in light mode. |

## uiAppearance.getDarkMode

getDarkMode(): DarkMode

Obtains the current system dark mode configuration.

<!--Del-->
> **NOTE**
>
> This API was a system API in API version 19 and earlier. To use it, you needed to request the `ohos.permission.UPDATE_CONFIGURATION` permission.
<!--DelEnd-->

**System capability**: SystemCapability.ArkUI.UiAppearance

**Return value**

| Type      | Description                           |
| --------- | ------------------------------------- |
| [DarkMode](#darkmode) | Current dark mode configuration of the system. |

**Error codes**

For details about the error codes, see [UI Appearance Error Codes](errorcode-uiappearance.md).

| ID      | Error Message      |
| ------- | ------------------ |
| 500001  | Internal error.    |

**Example**

```ts
import { uiAppearance } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let darkMode = uiAppearance.getDarkMode();
  console.info('Current dark mode: ' + darkMode);
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('Failed to get dark mode. Error: ' + message);
}
```

## uiAppearance.getFontScale

getFontScale(): number

Obtains the current font size scaling ratio.

<!--Del-->
> **NOTE**
>
> This API was a system API in API version 19 and earlier. To use it, you needed to request the `ohos.permission.UPDATE_CONFIGURATION` permission.
<!--DelEnd-->

**System capability**: SystemCapability.ArkUI.UiAppearance

**Return value**

| Type   | Description                     |
| ------ | ------------------------------- |
| number | Current font size scaling ratio. |

**Error codes**

For details about the error codes, see [UI Appearance Error Codes](errorcode-uiappearance.md).

| ID      | Error Message      |
| ------- | ------------------ |
| 500001  | Internal error.    |

**Example**

```ts
import { uiAppearance } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let fontScale = uiAppearance.getFontScale();
  console.info('Current font scale: ' + fontScale);
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('Failed to get font scale. Error: ' + message);
}
```

## uiAppearance.getFontWeightScale

getFontWeightScale(): number

Obtains the current font weight scaling ratio.

<!--Del-->
> **NOTE**
>
> This API was a system API in API version 19 and earlier. To use it, you needed to request the `ohos.permission.UPDATE_CONFIGURATION` permission.
<!--DelEnd-->

**System capability**: SystemCapability.ArkUI.UiAppearance

**Return value**

| Type   | Description                       |
| ------ | --------------------------------- |
| number | Current font weight scaling ratio. |

**Error codes**

For details about the error codes, see [UI Appearance Error Codes](errorcode-uiappearance.md).

| ID      | Error Message      |
| ------- | ------------------ |
| 500001  | Internal error.    |

**Example**

```ts
import { uiAppearance } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let fontWeightScale = uiAppearance.getFontWeightScale();
  console.info('Current font weight scale: ' + fontWeightScale);
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('Failed to get font weight scale. Error: ' + message);
}
```