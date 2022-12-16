# Input Consumer

The Input Consumer module implements listening for combination key events.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.


## Modules to Import


```js
import inputConsumer from '@ohos.multimodalInput.inputConsumer';
```


## inputConsumer.on

on(type: "key", keyOptions: KeyOptions, callback: Callback&lt;KeyOptions&gt;): void

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
try {
  inputConsumer.on("key", {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0}, keyOptions => {
    console.log(`keyOptions: ${JSON.stringify(keyOptions)}`);
  });
} catch (error) {
  console.log(`Subscribe failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```


## inputConsumer.off

off(type: "key", keyOptions: KeyOptions, callback?: Callback&lt;KeyOptions&gt;): void

Disables listening for combination key events.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                             |
| ---------- | -------------------------- | ---- | ------------------------------- |
| type       | string                     | Yes   | Event type. Currently, only **key** is supported.             |
| keyOptions | [KeyOptions](#keyoptions)  | Yes   | Combination key options.            |
| callback   | Callback&lt;KeyOptions&gt; | No   | Callback for which listening is disabled. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Example**

```js
let leftAltKey = 2045;
let tabKey = 2049;
// Disable listening for a single callback function.
let callback = function (keyOptions) {
  console.log(`keyOptions: ${JSON.stringify(keyOptions)}`);
}
let keyOption = {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0};
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
// Disable listening for all callback functions.
let callback = function (keyOptions) {
  console.log(`keyOptions: ${JSON.stringify(keyOptions)}`);
}
let keyOption = {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0};
try {
  inputConsumer.on("key", keyOption, callback);
  inputConsumer.off("key", keyOption);
  console.log(`Unsubscribe success`);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```


## KeyOptions

Represents combination key options.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

| Name       | Type  | Readable  | Writable  | Description     |
| --------- | ------ | ---- | ---- | ------- |
| preKeys              | Array\<number>   | Yes   | No| Front key set. The number of front keys ranges from 0 to 4. There is no requirement on the sequence of the keys.|
| finalKey             | number  | Yes   |  No| Final key. This parameter is mandatory. A callback function is triggered by the final key.|
| isFinalKeyDown       | boolean | Yes   |  No| Whether the final key is pressed.|
| finalKeyDownDuration | number  | Yes   |  No| Duration within which the final key is pressed. If the value is **0**, the callback function is triggered immediately. If the value is greater than **0** and the value of **isFinalKeyDown** is **true**, the callback function is triggered when the key press duration is longer than the value of this parameter. If the value of **isFinalKeyDown** is **false**, the callback function is triggered when the duration from key press to key release is less than the value of this parameter.  |
