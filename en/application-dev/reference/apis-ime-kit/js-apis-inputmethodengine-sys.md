# @ohos.inputMethodEngine (Input Method Service) (System API)

The **inputMethodEngine** module provides management capabilities for system input method applications. With the APIs of this module, input method applications are able to create soft keyboard windows, insert or delete characters, select text, and listen for physical keyboard events.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { inputMethodEngine } from '@kit.IMEKit';
```

## SizeUpdateCallback<sup>14+</sup>

type SizeUpdateCallback = (size: window.Size, keyboardArea: KeyboardArea) => void

Callback triggered when the size of the input method panel changes.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**System API**: This is a system API.

| Name      | Type                                                | Mandatory| Description                            |
| ------------ | ---------------------------------------------------- | ---- | -------------------------------- |
| size         | [window.Size](../apis-arkui/js-apis-window.md#size7) | Yes  | Panel size.                  |
| keyboardArea | [KeyboardArea](./js-apis-inputmethodengine.md#keyboardarea15)    | Yes  | Size of the keyboard area.|

## Panel<sup>10+</sup>

You need to use [createPanel](./js-apis-inputmethodengine.md#createpanel10) to obtain the panel instance and then call the following APIs through the instance.

### on('sizeUpdate')<sup>14+</sup>

on(type: 'sizeUpdate', callback: SizeUpdateCallback): void

Listens for the panel size change. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API applies only to the panels of the **SOFT_KEYBOARD** type in the **FLG_FIXED** or **FLG_FLOATING** state. When you call [adjustPanelRect](./js-apis-inputmethodengine.md#adjustpanelrect15) to adjust the panel size, the system calculates the final value based on certain rules (for example, whether the panel size exceeds the screen). This callback can be used to obtain the actual panel size to refresh the panel layout.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**System API**: This is a system API.

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                  |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                      | Yes  | Event type, which is **'sizeUpdate'**.|
| callback | [SizeUpdateCallback](#sizeupdatecallback14) | Yes  | Callback used to return the result, the size of the soft keyboard panel, including the width and height.|

**Example**

```ts
import { window } from '@kit.ArkUI';

try {
  panel.on('sizeUpdate', (windowSize: window.Size, keyboardArea: inputMethodEngine.KeyboardArea) => {
    console.info(`panel size changed, windowSize: ${JSON.stringify(windowSize)}, keyboardArea: ${JSON.stringify(keyboardArea)}`);
  });
} catch(err) {
  console.error(`Failed to subscribe sizeUpdate: ${JSON.stringify(err)}`);
}
```

### off('sizeUpdate')<sup>14+</sup>

off(type: 'sizeUpdate', callback?: SizeUpdateCallback): void

Disables listening for the panel size change. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API applies only to the panels of the **SOFT_KEYBOARD** type in the **FLG_FIXED** or **FLG_FLOATING** state. When you call [adjustPanelRect](./js-apis-inputmethodengine.md#adjustpanelrect15) to adjust the panel size, the system calculates the final value based on certain rules (for example, whether the panel size exceeds the screen). This callback can be used to obtain the actual panel size to refresh the panel layout.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**System API**: This is a system API.

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                    |
| -------- | ------------------------------------------- | ---- | -------------------------------------------------------- |
| type     | string                                      | Yes  | Event type, which is **'sizeUpdate'**.|
| callback | [SizeUpdateCallback](#sizeupdatecallback14) | No  | Callback used to return the result, the size of the soft keyboard panel, including the width and height.  |

**Example**

```ts
import { window } from '@kit.ArkUI';

try {
  panel.off('sizeUpdate', (windowSize: window.Size, keyboardArea: inputMethodEngine.KeyboardArea) => {
    console.info(`panel size changed, width: ${windowSize.width}, height: ${windowSize.height}`);
  });
} catch(err) {
    console.error(`Failed to subscribe sizeUpdate: ${JSON.stringify(err)}`);
}
```
<!--no_check-->
