# Key Press Event Listening Development

## When to Use

Key press event listening allows an application to listen for physical key press events when running in the foreground. Currently, this function applies only to the volume up and volume down keys. It enables applications to subscribe to key press events and override default system responses to those events, such as volume adjustments.

You can enhance user experience by leveraging volume key listeners to implement context-specific actions, such as binding page-turning functionality in reading apps or triggering the camera shutter in photography apps. Currently, this function is available only for mobile phones and tablets.

## Modules to Import

```js
import { inputConsumer, KeyEvent } from '@kit.InputKit';
```

## Available APIs

The following table lists the APIs related to key press event listening. For details about the APIs, see [ohos.multimodalInput.inputConsumer](../../reference/apis-input-kit/js-apis-inputconsumer.md).

| API | Description|
| ------------------------------------------------------------ | -------------------------- |
| on(type: "keyPressed", options: KeyPressedConfig, callback: Callback\<KeyEvent>): void |Subscribes to press events of the specified key and intercepts the default system response. |
| off(type: "keyPressed", callback?: Callback\<KeyEvent>): void |Unsubscribes from press events of the specified key and restores the default system response. |

## How to Develop

When an application is started, call [on](../../reference/apis-input-kit/js-apis-inputconsumer.md#inputconsumeronkeypressed16) to subscribe to key press events. When the application is closed, call [off](../../reference/apis-input-kit/js-apis-inputconsumer.md#inputconsumeroffkeypressed16) to unsubscribe from key press events.

### Page Turning and In-App Photographing via the Volume Button

In e-book or news reading apps, users can navigate pages via volume buttons—typically, the volume-up button turns to the next page, while the volume-down button returns to the previous page. In camera or barcode scanning apps, pressing a volume button triggers instant photography without switching to the system's camera interface.

```js
import { inputConsumer, KeyEvent } from '@kit.InputKit';
// Start the application.
try {
  let options: inputConsumer.KeyPressedConfig = {
    key: 17,
    action: 1,
    isRepeat: false,
  }
  // Subscribe to key press events.
  inputConsumer.on('keyPressed', options, (event: KeyEvent) => {
    console.info(`Subscribe success ${JSON.stringify(event)}`);
  });
  // You can define a typical scenario, such as page turning or in-app photographing via the volume button.
} catch (error) {
  console.error(`Subscribe execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
// Stop the application.
try {
  // Disable listening for a single callback.
  inputConsumer.off('keyPressed', (event: KeyEvent) => {
    console.info(`Unsubscribe success ${JSON.stringify(event)}`);
  });
  // Disable listening for all callbacks.
  inputConsumer.off("keyPressed");
} catch (error) {
  console.error(`Unsubscribe execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
