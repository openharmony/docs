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

## KeyPressedConfig<sup>16+</sup>

Sets the key event consumption configuration.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

| Name       | Type  | Readable  | Writable  | Description     |
| --------- | ------ | ------- | ------- | ------- |
| key       | number  | Yes     | No     | Key value.<br>Currently, only the [KEYCODE_VOLUME_UP](js-apis-keycode.md#keycode) and [KEYCODE_VOLUME_DOWN](js-apis-keycode.md#keycode) keys are supported.|  
| action    | number  | Yes     | No     | Key event type. Currently, the value can only be **1**.<br>- **1**: Key press.<br>- **2**: Key release.|  
| isRepeat  | boolean  | Yes     | No     | Whether to report repeated key events.|

## inputConsumer.getAllSystemHotkeys<sup>14+</sup>

getAllSystemHotkeys(): Promise&lt;Array&lt;HotkeyOptions&gt;&gt;

Obtains all system shortcut keys. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Return value**

| Parameter        |  Description                                      |
| ---------- |  ---------------------------------------- |
| Promise&lt;Array&lt;HotkeyOptions&gt;&gt;                    | Promise used to return the list of all system shortcut keys.|

**Error codes**:

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message                 |
| -------- | ------------------------- |
| 801      | Capability not supported. |

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
| 801 | Capability not supported. |
| 4200002  | The hotkey has been used by the system. |
| 4200003  | The hotkey has been subscribed to by another. |

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
| 801 | Capability not supported. |

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

## inputConsumer.on('keyPressed')<sup>16+</sup>

on(type: 'keyPressed', options: KeyPressedConfig, callback: Callback&lt;KeyEvent&gt;): void

Subscribes to key press events. If the current application is in the foreground focus window, a callback is triggered when the specified key is pressed.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                               | Mandatory | Description                             |
| ---------- | --------------------------             | ----  | ---------- |
| type       | string                                 | Yes    | Event type. This parameter has a fixed value of **keyPressed**.       |
| options    | [KeyPressedConfig](#keypressedconfig16)| Yes    | Sets the key event consumption configuration.          |
| callback   | Callback&lt;[KeyEvent](./js-apis-keyevent.md#keyevent)&gt; | Yes   | Callback used to return the key event.|

**Error codes**:

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |

**Example**

```js
try {
  let options: inputConsumer.KeyPressedConfig = {
    key: 16,
    action: 1,
    isRepeat: false,
  }
  inputConsumer.on('keyPressed', options, (event: KeyEvent) => {
    console.log(`Subscribe success ${JSON.stringify(event)}`);
  });
} catch (error) {
  console.log(`Subscribe execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputConsumer.off('keyPressed')<sup>16+</sup>

off(type: 'keyPressed', callback?: Callback&lt;KeyEvent&gt;): void

Unsubscribes from key press events.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                             |
| ---------- | -------------------------- | ---- | ---------- |
| type       | string                     | Yes   | Event type. This parameter has a fixed value of **keyPressed**.       |
| callback   | Callback&lt;[KeyEvent](./js-apis-keyevent.md#keyevent)&gt; | No   | Callback to unregister. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Error codes**:

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |

**Example**

```js
try {
  // Disable listening for a single callback.
  inputConsumer.off('keyPressed', (event: KeyEvent) => {
    console.log(`Unsubscribe success ${JSON.stringify(event)}`);
  });
  // Disable listening for all callbacks.
  inputConsumer.off("keyPressed");
} catch (error) {
  console.log(`Unsubscribe execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
