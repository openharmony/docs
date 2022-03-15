# Brightness

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The Brightness module provides an API for setting the screen brightness.


## Modules to Import

```
import brightness from '@ohos.brightness';
```

## brightness.setValue

setValue(value: number)

Sets the screen brightness.

**System capability:** SystemCapability.PowerManager.DisplayPowerManager

**Note:** This is a system API and it is used only for system applications.

**Parameters**

| Name  | Type    | Mandatory  | Description         |
| ----- | ------ | ---- | ----------- |
| value | number | Yes   | Brightness value, ranging from 0 to 255.|

**Example**

```
brightness.setValue(128);
```
