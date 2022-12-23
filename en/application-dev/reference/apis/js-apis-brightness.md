# Screen Brightness

The Brightness module provides an API for setting the screen brightness.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.

## Modules to Import

```js
import brightness from '@ohos.brightness';
```

## brightness.setValue

setValue(value: number): void

Sets the screen brightness.

**System API**: This is a system API.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager

**Parameters**

| Name| Type  | Mandatory| Description                   |
| ------ | ------ | ---- | ----------------------- |
| value  | number | Yes  | Brightness value. The value ranges from 0 to 255.|

**Error codes**

For details about the error codes, see [Screen Brightness Error Codes](../errorcodes/errorcode-brightness.md).

| Code  | Error Message   |
|---------|---------|
| 4700101 | Operation failed. Cannot connect to service.|

**Example**

```js
try {
    brightness.setValue(128);
} catch(err) {
    console.error('set brightness failed, err: ' + err);
}
```
