# Global Hotkey Development

## When to Use

The **inputConsumer** module implements global hotkey management, such as subscribing to global hotkeys and setting the key shielding status. By subscribing to global hotkeys, you can use the corresponding key combinations to activate shortcut functions.

Specifically, global hotkeys are combination keys defined by either the system or applications; system hotkeys are those defined by the system, while application hotkeys are those defined by applications.

## Modules to Import

```js
import { inputConsumer } from '@kit.InputKit';
```

## Available APIs

The following table lists the common APIs provided by the **inputConsumer** module. For details, see [ohos.multimodalInput.inputConsumer-sys](../../reference/apis-input-kit/js-apis-inputconsumer-sys.md) and [ohos.multimodalInput.inputConsumer](../../reference/apis-input-kit/js-apis-inputconsumer.md).

| API | Description|
| ------------------------------------------------------------ | -------------------------- |
| on(type: 'key', keyOptions: KeyOptions, callback: Callback\<KeyOptions>): void | Subscribes to system hotkey change events.|
| off(type: 'key', keyOptions: KeyOptions, callback?: Callback\<KeyOptions>): void | Unsubscribes from system hotkey change events.|
| setShieldStatus(shieldMode: ShieldMode, isShield: boolean): void | Sets the key shielding status.|
| getShieldStatus(shieldMode: ShieldMode): boolean | Checks whether key shielding is enabled.|
| getAllSystemHotkeys(): Promise\<Array\<HotkeyOptions>> | Obtains all system hotkeys.|
| on(type: 'hotkeyChange', hotkeyOptions: HotkeyOptions, callback: Callback\<HotkeyOptions>): void | Subscribes to application hotkey change events.|
| off(type: 'hotkeyChange', hotkeyOptions: HotkeyOptions, callback?: Callback\<HotkeyOptions>): void | Unsubscribes from application hotkey change events.|

## How to Develop

When an application that uses specific combination keys is started, call [on](../../reference/apis-input-kit/js-apis-inputconsumer-sys.md#inputconsumeron) to subscribe to combination key events. When the application is stopped, call [off](../../reference/apis-input-kit/js-apis-inputconsumer-sys.md#inputconsumeroff) to unsubscribe from combination key events.

```js
import { inputConsumer } from '@kit.InputKit';

let leftAltKey = 2045;
let tabKey = 2049;
let callback = (keyOptions: inputConsumer.KeyOptions) => {
  console.info(`keyOptions: ${JSON.stringify(keyOptions)}`);
}
// Start the application.
let keyOption: inputConsumer.KeyOptions = {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0};
try {
  inputConsumer.on("key", keyOption, callback);// Subscribe to system hotkey change events.
} catch (error) {
  console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
// Stop the application.
try {
  inputConsumer.off("key", keyOption, callback);// Unsubscribe from system hotkey change events.
  console.info(`Unsubscribe success`);
} catch (error) {
  console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}

let leftCtrlKey = 2072;
let zKey = 2042;
let hotkeyCallback = (hotkeyOptions: inputConsumer.HotkeyOptions) => {
  console.info(`keyOptions: ${JSON.stringify(hotkeyOptions)}`);
}
let hotkeyOption: inputConsumer.HotkeyOptions = {preKeys: [leftCtrlKey], finalKey: zKey, isRepeat: false};
// Before subscribing to change events of the specified hotkey, you need to check whether the hotkey exists in the system hotkey list to avoid conflicts.
inputConsumer.getAllSystemHotkeys().then((data: Array<inputConsumer.HotkeyOptions>) => {// Obtain all system hotkeys.
  console.info(`List of system hotkeys : ${JSON.stringify(data)}`);
});
// Start the application.
try {
  inputConsumer.on("hotkeyChange", hotkeyOption, hotkeyCallback);// Subscribe to change events of the hotkey.
} catch (error) {
  console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
// Stop the application.
try {
  inputConsumer.off("hotkeyChange", hotkeyOption, hotkeyCallback);// Unsubscribe from change events of the hotkey.
  console.info(`Unsubscribe success`);
} catch (error) {
  console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
