# Brightness

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The Brightness module provides an API for setting the screen brightness.


## Modules to Import

```js
import brightness from '@ohos.brightness';
```

## brightness.setValue

setValue(value: number): void

Sets the screen brightness.

This is a system API and cannot be called by third-party applications.

**System capability:** SystemCapability.PowerManager.DisplayPowerManager

**Parameters**

| Name  | Type    | Mandatory  | Description         |
| ----- | ------ | ---- | ----------- |
| value | number | Yes   | Brightness value, ranging from **0** to **255**.|

**Example**

```js
brightness.setValue(128);
```
