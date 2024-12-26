# @ohos.multimodalInput.inputConsumer (Input Consumer)

The **inputConsumer** module implements listening for combination key events.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```js
import { inputConsumer } from '@kit.InputKit';
```

## HotkeyOptions<sup>14+</sup>

Defines shortcut key options.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

| Name       | Type  | Readable  | Writable  | Description     |
| --------- | ------ | ------- | ------- | ------- |
| preKeys   | Array&lt;number&gt; | Yes     | No     | Modifier key set (including Ctrl, Shift, and Alt). A maximum of two modifier keys are supported. There is no requirement on the sequence of modifier keys.<br>For example, in **Ctrl+Shift+Esc**, **Ctrl** and **Shift** are modifier keys.|
| finalKey  | number  | Yes     | No     | Modified key, which is the key other than the modifier key and meta key.<br>For example, in **Ctrl+Shift+Esc**, **Esc** is the modified key.|
| isRepeat  | boolean  | Yes     | No     | Whether to report repeated key events. The value **true** means to report repeated key events, and the value **false** means the opposite. The default value is **true**.|

## inputConsumer.getAllSystemHotkeys<sup>14+</sup>

getAllSystemHotkeys(): Promise&lt;Array&lt;HotkeyOptions&gt;&gt;

Obtains all system shortcut keys. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Return value**

| Parameter        |  Description                                      |
| ---------- |  ---------------------------------------- |
| Promise&lt;Array&lt;HotkeyOptions&gt;&gt;                    | Promise used to return the list of all system shortcut keys.|

**Example**

```js
inputConsumer.getAllSystemHotkeys().then((data: Array<inputConsumer.HotkeyOptions>) => {
  console.log(`List of system hotkeys : ${JSON.stringify(data)}`);
});
```

## inputConsumer.on('hotkeyOptions')<sup>14+</sup>

on(type: 'hotkeyChange', hotkeyOptions: HotkeyOptions, callback: Callback&lt;HotkeyOptions&gt;): void

Enables listening for global combination key events. This API uses an asynchronous callback to return the combination key data when a combination key event that meets the specified condition occurs.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                                      |
| ---------- | -------------------------- | ---- | ---------- |
| type       | string                     | Yes   | Event type. This parameter has a fixed value of **hotkeyChange**.                  |
| hotkeyOptions | [HotkeyOptions](#hotkeyoptions14) | Yes   | Shortcut key options.                |
| callback   | Callback&lt;HotkeyOptions&gt; | Yes   | Callback used to return the combination key data when a global combination key event that meets the specified condition occurs.|

**Error codes**:

For details about the error codes, see [Input Consumer Error Codes](errorcode-inputconsumer.md) and [Universal Error Codes](../errorcode-universal.md).

| Error Code | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 4200002  | Parameter error. The hotkey has been used by the system. You can call the [inputConsumer.getAllSystemHotkeys](#inputconsumergetallsystemhotkeys14) interface to query all system hotkeys. |
| 4200003  | Parameter error. The hotkey has been subscribed to by another. |

**Example**

```js
let leftCtrlKey = 2072;
let zKey = 2042;
let hotkeyOptions: inputConsumer.HotkeyOptions = {
  preKeys: [ leftCtrlKey ],
  finalKey: zKey,
  isRepeat: true
};
let hotkeyCallback = (hotkeyOptions: inputConsumer.HotkeyOptions) => {
  console.log(`hotkeyOptions: ${JSON.stringify(hotkeyOptions)}`);
}
try {
  inputConsumer.on("hotkeyChange", hotkeyOptions, hotkeyCallback);
} catch (error) {
  console.log(`Subscribe failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputConsumer.off('hotkeyOptions')<sup>14+</sup>

off(type: 'hotkeyChange', hotkeyOptions: HotkeyOptions, callback?: Callback&lt;HotkeyOptions&gt;): void

Disables listening for global combination key events. 

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                             |
| ---------- | -------------------------- | ---- | ---------- |
| type       | string                     | Yes   | Event type. This parameter has a fixed value of **hotkeyChange**.       |
| hotkeyOptions | [HotkeyOptions](#hotkeyoptions14) | Yes   | Shortcut key options.            |
| callback   | Callback&lt;HotkeyOptions&gt; | No   | Callback to unregister. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Error codes**:

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
let leftCtrlKey = 2072;
let zKey = 2042;
// Disable listening for a single callback.
let hotkeyCallback = (hotkeyOptions: inputConsumer.HotkeyOptions) => {
  console.log(`hotkeyOptions: ${JSON.stringify(hotkeyOptions)}`);
}
let hotkeyOption: inputConsumer.HotkeyOptions = {preKeys: [leftCtrlKey], finalKey: zKey, isRepeat: true};
try {
  inputConsumer.on("hotkeyChange", hotkeyOption, hotkeyCallback);
  inputConsumer.off("hotkeyChange", hotkeyOption, hotkeyCallback);
  console.log(`Unsubscribe success`);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
```js
let leftCtrlKey = 2072;
let zKey = 2042;
// Disable listening for all callbacks.
let hotkeyCallback = (hotkeyOptions: inputConsumer.HotkeyOptions) => {
  console.log(`hotkeyOptions: ${JSON.stringify(hotkeyOptions)}`);
}
let hotkeyOption: inputConsumer.HotkeyOptions = {preKeys: [leftCtrlKey], finalKey: zKey, isRepeat: true};
try {
  inputConsumer.on("hotkeyChange", hotkeyOption, hotkeyCallback);
  inputConsumer.off("hotkeyChange", hotkeyOption);
  console.log(`Unsubscribe success`);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
