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
import { KeyCode } from '@kit.InputKit';

@Entry
@Component
struct TestDemo14 {
  private volumeUpCallBackFunc: (event: KeyEvent) => void = () => {
  }
  private volumeDownCallBackFunc: (event: KeyEvent) => void = () => {
  }

  aboutToAppear(): void {
    try {
      let options1: inputConsumer.KeyPressedConfig = {
        key: KeyCode.KEYCODE_VOLUME_UP,
        action: 1, // The value 1 indicates a key press.
        isRepeat: false, // Key events are consumed preferentially and not reported.
      }
      let options2: inputConsumer.KeyPressedConfig = {
        key: KeyCode.KEYCODE_VOLUME_DOWN,
        action: 1, // The value 1 indicates a key press.
        isRepeat: false, // Key events are consumed preferentially and not reported.
      }

      // Callback invoked when the Volume Up button is pressed
      this.volumeUpCallBackFunc = (event: KeyEvent) => {
        this.getUIContext().getPromptAction().showToast({ message: 'The Volume Up button was pressed.' });
        // do something
      }

      // Callback invoked when the Volume Down button is pressed
      this.volumeDownCallBackFunc = (event: KeyEvent) => {
        this.getUIContext().getPromptAction().showToast({ message: 'The Volume Down button was pressed.' });
        // do something
      }
      // Register an event listener.
      inputConsumer.on('keyPressed', options1, this.volumeUpCallBackFunc);
      inputConsumer.on('keyPressed', options2, this.volumeDownCallBackFunc);
    } catch (error) {
      console.error(`Subscribe execute failed, error: ${JSON.stringify(error, ["code", "message"])}`);
    }
  }

  build() {
    Column() {
      Row() {
        Button ('Cancel listening for Volume Up button events')
          .onClick(() => {
            try {
              // Disable listening for a single callback.
              inputConsumer.off('keyPressed', this.volumeUpCallBackFunc);
              this.getUIContext().getPromptAction().showToast({ message: ''Listening for Volume Up button events is canceled successfully.' });
            } catch (error) {
              console.error(`Unsubscribe execute failed, error: ${JSON.stringify(error, ["code", "message"])}`);
            }
          })
      }.width('100%')
      .justifyContent(FlexAlign.Center)
      .margin({ top: 20, bottom: 50 })

      Row() {
        Button ('Cancel listening for Volume Down button events')
          .onClick(() => {
            try {
              // Disable listening for a single callback.
              inputConsumer.off('keyPressed', this.volumeDownCallBackFunc);
              this.getUIContext().getPromptAction().showToast({ message: 'Listening for Volume Down button events is canceled successfully.' });
            } catch (error) {
              console.error(`Unsubscribe execute failed, error: ${JSON.stringify(error, ["code", "message"])}`);
            }
          })
      }.width('100%')
      .justifyContent(FlexAlign.Center)
      .margin({ top: 20, bottom: 50 })
      Row(){
        Text ('Listening is enabled for Volume Down and Volume Down button events by default.')
      }
      .width('100%')
      .justifyContent(FlexAlign.Center)
    }.width('100%').height('100%')
  }
}
```
