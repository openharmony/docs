# Combination Key Development

## When to Use

The **inputConsumer** module provides capabilities such as subscribing to combination key events and setting the key shielding status. For example, if an application needs to implement a shortcut function using combination keys, you can listen for combination key events to serve that purpose.

## Modules to Import

```js
import { inputConsumer } from '@kit.InputKit';
```

## Available APIs

The following table lists the common APIs provided by the inputConsumer module. For details, see [ohos.multimodalInput.inputConsumer-sys](../../reference/apis-input-kit/js-apis-inputconsumer-sys.md) and [ohos.multimodalInput.inputConsumer](../../reference/apis-input-kit/js-apis-inputconsumer.md).

| API | Description|
| ------------------------------------------------------------ | -------------------------- |
| on(type: 'key', keyOptions: KeyOptions, callback: Callback\<KeyOptions>): void | Enables listening for combination key events.|
| off(type: 'key', keyOptions: KeyOptions, callback?: Callback\<KeyOptions>): void | Disables listening for combination key events.|
| setShieldStatus(shieldMode: ShieldMode, isShield: boolean): void | Sets the key shielding status.|
| getShieldStatus(shieldMode: ShieldMode): boolean | Checks whether key shielding is enabled.|
| getAllSystemHotkeys(): Promise\<Array\<HotkeyOptions>> | Obtains all system combination keys.|
| on(type: 'hotkeyChange', hotkeyOptions: HotkeyOptions, callback: Callback\<HotkeyOptions>): void | Enables listening for global combination key events.|
| off(type: 'hotkeyChange', hotkeyOptions: HotkeyOptions, callback?: Callback\<HotkeyOptions>): void | Disables listening for global combination key events.|

## How to Develop

When an application that uses specific combination keys is started, [on](../../reference/apis-input-kit/js-apis-inputconsumer-sys.md#inputconsumeron) is called to subscribe to combination key events.
When the application is stopped, [off](../../reference/apis-input-kit/js-apis-inputconsumer-sys.md#inputconsumeroff) is called to unsubscribe from combination key events.

```js
let leftAltKey = 2045;
let tabKey = 2049;
let callback = (keyOptions: inputConsumer.KeyOptions) => {
  console.log(`keyOptions: ${JSON.stringify(keyOptions)}`);
}
// Start the application.
let keyOption: inputConsumer.KeyOptions = {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0};
try {
  inputConsumer.on("key", keyOption, callback);// Listen for combination key events.
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
// Stop the application.
try {
  inputConsumer.off("key", keyOption, callback);// Disable listening for combination key events.
  console.log(`Unsubscribe success`);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}

let leftCtrlKey = 2072;
let zKey = 2042;
let hotkeyCallback = (hotkeyOptions: inputConsumer.HotkeyOptions) => {
  console.log(`keyOptions: ${JSON.stringify(hotkeyOptions)}`);
}
let hotkeyOption: inputConsumer.HotkeyOptions = {preKeys: [leftCtrlKey], finalKey: zKey, isRepeat: false};
// Before subscribing to global combination keys, obtain all system combination keys and check whether the combination keys to subscribe are on the system combination key list.
inputConsumer.getAllSystemHotkeys().then((data: Array<inputConsumer.HotkeyOptions>) => {//: Obtain all system combination keys.
  console.log(`List of system hotkeys : ${JSON.stringify(data)}`);
});
// Start the application.
try {
  inputConsumer.on("hotkeyChange", hotkeyOption, hotkeyCallback);// Subscribe to global combination keys.
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
// Stop the application.
try {
  inputConsumer.off("hotkeyChange", hotkeyOption, hotkeyCallback);// Unsubscribe from global combination keys.
  console.log(`Unsubscribe success`);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
