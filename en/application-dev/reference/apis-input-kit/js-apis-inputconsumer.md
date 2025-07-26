# @ohos.multimodalInput.inputConsumer (Global Shortcut Keys)

The **inputConsumer** module implements listening for combination key events as well as listening and interception for volume key events.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - Global shortcut keys are combination keys defined by the system or application. System shortcut keys are defined by the system, and application shortcut keys are defined by applications.


## Modules to Import


```js
import { inputConsumer, KeyEvent } from '@kit.InputKit';
```

## HotkeyOptions

Defines shortcut key options.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

| Name       | Type  | Read-Only  | Optional  | Description     |
| --------- | ------ | ------- | ------- | ------- |
| preKeys   | Array&lt;number&gt; | No     | No     | Modifier key set (including Ctrl, Shift, and Alt). A maximum of two modifier keys are supported. There is no requirement on the sequence of modifier keys.<br>For example, in **Ctrl+Shift+Esc**, **Ctrl** and **Shift** are modifier keys.|
| finalKey  | number  | No     | No     | Modified key, which can be any key except the modifier keys and Meta key. For details about the keys, see [Keycode](js-apis-keycode.md).<br>For example, in **Ctrl+Shift+Esc**, **Esc** is the modified key.|
| isRepeat  | boolean  | No     | Yes     | Whether to report repeated key events. The value **true** means to report repeated key events, and the value **false** means the opposite. The default value is **true**.|

## KeyPressedConfig<sup>16+</sup>

Sets the key event consumption configuration.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

| Name       | Type  | Read-Only  | Optional  | Description     |
| --------- | ------ | ------- | ------- | ------- |
| key       | number  | No     | No     | Key value.<br>Currently, only the [KEYCODE_VOLUME_UP](js-apis-keycode.md#keycode) and [KEYCODE_VOLUME_DOWN](js-apis-keycode.md#keycode) keys are supported.|
| action    | number  | No     | No     | Key event type. Currently, this parameter can only be set to **1**, indicating key press.|
| isRepeat  | boolean  | No     | No     | Whether to report repeated key events. The value **true** means to report repeated key events, and the value **false** means the opposite. The default value is **true**.|

## inputConsumer.getAllSystemHotkeys

getAllSystemHotkeys(): Promise&lt;Array&lt;HotkeyOptions&gt;&gt;

Obtains all system shortcut keys. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Return value**

| Type        |  Description                                      |
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

## inputConsumer.on('hotkeyChange')

on(type: 'hotkeyChange', hotkeyOptions: HotkeyOptions, callback: Callback&lt;HotkeyOptions&gt;): void

Subscribes to application shortcut key change events based on the specified options. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                                      |
| ---------- | -------------------------- | ---- | ---------- |
| type       | string                     | Yes   | Event type. This parameter has a fixed value of **hotkeyChange**.                  |
| hotkeyOptions | [HotkeyOptions](#hotkeyoptions) | Yes   | Shortcut key options.                |
| callback   | Callback&lt;HotkeyOptions&gt; | Yes   | Callback used to return the application shortcut key change event.|

**Error codes**:

For details about the error codes, see [Global Shortcut Key Error Codes](errorcode-inputconsumer.md) and [Universal Error Codes](../errorcode-universal.md).

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
  console.error(`Subscribe failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputConsumer.off('hotkeyChange')

off(type: 'hotkeyChange', hotkeyOptions: HotkeyOptions, callback?: Callback&lt;HotkeyOptions&gt;): void

Unsubscribes from application shortcut key change events.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                             |
| ---------- | -------------------------- | ---- | ---------- |
| type       | string                     | Yes   | Event type. This parameter has a fixed value of **hotkeyChange**.       |
| hotkeyOptions | [HotkeyOptions](#hotkeyoptions) | Yes   | Shortcut key options.            |
| callback   | Callback&lt;HotkeyOptions&gt; | No   | Callback to unregister. If this parameter is left unspecified, listening will be disabled for all callbacks registered for the specified shortcut key options.|

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
  console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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
  console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputConsumer.on('keyPressed')<sup>16+</sup>

on(type: 'keyPressed', options: KeyPressedConfig, callback: Callback&lt;KeyEvent&gt;): void

Subscribes to key press events. This API uses an asynchronous callback to return the result. If the current application is in the foreground focus window, a callback is triggered when the specified key is pressed. This API is available only for mobile phones and tablets.

If the API call is successful, the system's default response to the key event will be intercepted; that is, system-level actions, such as volume adjustment, will no longer be triggered. To restore the system response, call [off](#inputconsumeroffkeypressed16) to disable listening for the key event.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                               | Mandatory | Description                             |
| ---------- | --------------------------             | ----  | ---------- |
| type       | string                                 | Yes    | Event type. This parameter has a fixed value of **keyPressed**.       |
| options    | [KeyPressedConfig](#keypressedconfig16)| Yes    | Sets the key event consumption configuration.          |
| callback   | Callback&lt;[KeyEvent](./js-apis-keyevent.md#keyevent)&gt; | Yes   | Callback used to return key press events.|

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
  console.error(`Subscribe execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputConsumer.off('keyPressed')<sup>16+</sup>

off(type: 'keyPressed', callback?: Callback&lt;KeyEvent&gt;): void

Disables listening for the **keyPressed** event. This API uses an asynchronous callback to return the result. If the API call is successful, the system's default response to the key event will be resumed; that is, system-level actions, such as volume adjustment, will be triggered normally. This API is available only for mobile phones and tablets.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                             |
| ---------- | -------------------------- | ---- | ---------- |
| type       | string                     | Yes   | Event type. This parameter has a fixed value of **keyPressed**.       |
| callback   | Callback&lt;[KeyEvent](./js-apis-keyevent.md#keyevent)&gt; | No   | Callback to unregister. If this parameter is not specified, listening will be disabled for all registered callbacks.|

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
  console.error(`Unsubscribe execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
