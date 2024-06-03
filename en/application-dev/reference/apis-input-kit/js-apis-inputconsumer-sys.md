# @ohos.multimodalInput.inputConsumer (Input Consumer) (System API)

The **inputConsumer** module implements listening for combination key events.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.

## Modules to Import

```js
import { inputConsumer } from '@kit.InputKit';
```

## inputConsumer.on

on(type: 'key', keyOptions: KeyOptions, callback: Callback&lt;KeyOptions&gt;): void

Enables listening for combination key events. This API uses an asynchronous callback to return the combination key data when a combination key event that meets the specified condition occurs.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                                      |
| ---------- | -------------------------- | ---- | ---------------------------------------- |
| type       | string                     | Yes   | Event type. Currently, only **key** is supported.                      |
| keyOptions | [KeyOptions](#keyoptions)  | Yes   | Combination key options.                |
| callback   | Callback&lt;KeyOptions&gt; | Yes   | Callback used to return the combination key data when a combination key event that meets the specified condition occurs.|

**Example**

```js
let leftAltKey = 2045;
let tabKey = 2049;
let keyOptions: inputConsumer.KeyOptions = {
  preKeys: [ leftAltKey ],
  finalKey: tabKey,
  isFinalKeyDown: true,
  finalKeyDownDuration: 0
};
let callback = (keyOptions: inputConsumer.KeyOptions) => {
  console.log(`keyOptions: ${JSON.stringify(keyOptions)}`);
}
try {
  inputConsumer.on("key", keyOptions, callback);
} catch (error) {
  console.log(`Subscribe failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```


## inputConsumer.off

off(type: 'key', keyOptions: KeyOptions, callback?: Callback&lt;KeyOptions&gt;): void

Disables listening for combination key events.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                             |
| ---------- | -------------------------- | ---- | ------------------------------- |
| type       | string                     | Yes   | Event type. Currently, only **key** is supported.             |
| keyOptions | [KeyOptions](#keyoptions)  | Yes   | Combination key options.            |
| callback   | Callback&lt;KeyOptions&gt; | No   | Callback to unregister. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Example**

```js
let leftAltKey = 2045;
let tabKey = 2049;
// Disable listening for a single callback.
let callback = (keyOptions: inputConsumer.KeyOptions) => {
  console.log(`keyOptions: ${JSON.stringify(keyOptions)}`);
}
let keyOption: inputConsumer.KeyOptions = {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0};
try {
  inputConsumer.on("key", keyOption, callback);
  inputConsumer.off("key", keyOption, callback);
  console.log(`Unsubscribe success`);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
```js
let leftAltKey = 2045;
let tabKey = 2049;
// Disable listening for all callbacks.
let callback = (keyOptions: inputConsumer.KeyOptions) => {
  console.log(`keyOptions: ${JSON.stringify(keyOptions)}`);
}
let keyOption: inputConsumer.KeyOptions = {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0};
try {
  inputConsumer.on("key", keyOption, callback);
  inputConsumer.off("key", keyOption);
  console.log(`Unsubscribe success`);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputConsumer.setShieldStatus<sup>11+</sup>

setShieldStatus(shieldMode: ShieldMode, isShield: boolean): void

Sets the key shielding status.

**Required permissions**: ohos.permission.INPUT_CONTROL_DISPATCHING

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                                      |
| ---------- | -------------------------- | ---- | ---------------------------------------- |
| shieldMode       | ShieldMode                     | Yes   | Shielding mode. Currently, only **FACTORY_MODE** is supported.                      |
| isShield | boolean  | Yes   | Whether to enable key shielding. The value **true** means to enable key shielding, and the value **false** indicates the opposite.             |

**Example**

```js
let FACTORY_MODE = 0;
try {
  inputConsumer.setShieldStatus(FACTORY_MODE,true);
  console.log(`set shield status success`);
} catch (error) {
  console.log(`set shield status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}

```

## inputConsumer.getShieldStatus<sup>11+</sup>

getShieldStatus(shieldMode: ShieldMode): boolean

Checks whether key shielding is enabled.

**Required permissions**: ohos.permission.INPUT_CONTROL_DISPATCHING

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                                      |
| ---------- | -------------------------- | ---- | ---------------------------------------- |
| shieldMode       | ShieldMode                    | Yes   | Shielding mode. Currently, only **FACTORY_MODE** is supported.                      |

**Return value**

| Parameter        |  Description                                      |
| ---------- |  ---------------------------------------- |
| boolean                    | Whether to enable key shielding. The value **true** means to enable key shielding, and the value **false** indicates the opposite.                      |

**Example**

```js
try {
  let FACTORY_MODE = 0;
  let shieldstatusResult:Boolean =  inputConsumer.getShieldStatus(FACTORY_MODE);
  console.log(` get shield status result:${JSON.stringify(shieldstatusResult)}`);
} catch (error) {
  console.log(`Failed to get shield status, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## KeyOptions

Represents combination key options.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

| Name       | Type  | Readable  | Writable  | Description     |
| --------- | ------ | ---- | ---- | ------- |
| preKeys    | Array\<number>   | Yes   | No| Preceding key set. The number of preceding keys ranges from 0 to 4. There is no requirement on the sequence of the keys.<br>For example, in the combination keys **Ctrl+Alt+A**, **Ctrl+Alt** are called preceding keys.|
| finalKey             | number  | Yes   |  No| Final key. This parameter is mandatory. A callback is triggered by the final key.<br>For example, in the combination keys **Ctrl+Alt+A**, **A** is called the final key.|
| isFinalKeyDown       | boolean | Yes   |  No| Whether the final key is pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.|
| finalKeyDownDuration | number  | Yes   |  No| Duration for pressing a key, in μs.<br>If the value of this field is **0**, a callback is triggered immediately.<br>If the value of this field is greater than **0** and **isFinalKeyDown** is **true**, a callback is triggered when the key keeps being pressed after the specified duration expires. If **isFinalKeyDown** is **false**, a callback is triggered when the key is released before the specified duration expires.  |

## shieldMode<sup>11+</sup>

Enumerates key shielding modes.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

| Name                       | Type | Readable| Writable| Description          |
| ------------------------------ | ----------- | ---------------- | ---------------- | ---------------- |
| FACTORY_MODE | number | Yes| No| Factory mode, which means to shield all shortcut keys.|
