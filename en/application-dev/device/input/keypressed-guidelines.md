# Preferential Response of System Function Keys

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=40009f6ed8e7c23647b935ac57c1d470912f49a2 translatedAt=2026-07-28T02:35:10.043Z pushedAt=2026-07-28T03:03:28.207Z -->

## When to Use

Each system function key has a system-defined default behavior. For example, the volume keys adjust the device volume. However, some applications may need to customize the behavior of these keys in specific scenarios. This guide describes how to meet these requirements.<br/>Common use cases include reading applications that use the volume keys to turn pages and camera applications that use the volume keys to take photos.<br/>Supported keys: Starting from API version 16, the volume up and volume down keys are supported. Starting from API version 21, the media play/pause, media next, and media previous keys are supported. Starting from API version 26.0.0, upward and downward swipe gestures on the smart control key are supported. These key codes are not universal across devices. Before using them, check whether the current device supports reporting the corresponding key events.

## Constraints

- The preferential response feature takes effect only when the application window is the foreground focused window.

- After an application selects specific system function keys to take precedence over the system's default response, the keys' default behavior is disabled. Therefore, the application must ensure the custom function is activated only when it intends to respond.

## Available APIs

The following table lists common APIs for key press events. For details, see [@ohos.multimodalInput.inputConsumer (Global Shortcut Keys)](../../reference/apis-input-kit/js-apis-inputconsumer.md).

| API | Description|
| ------------------------------------------------------------ | -------------------------- |
| on(type: "keyPressed", options: KeyPressedConfig, callback: Callback\<KeyEvent>): void |Subscribes to press events of the specified key and intercepts the default system response. |
| off(type: "keyPressed", callback?: Callback\<KeyEvent>): void |Unsubscribes from press events of the specified key and restores the default system response. |

## How to Develop

When an application is started, call [on](../../reference/apis-input-kit/js-apis-inputconsumer.md#inputconsumeronkeypressed16) to subscribe to key press events. When the application is closed, call [off](../../reference/apis-input-kit/js-apis-inputconsumer.md#inputconsumeroffkeypressed16) to unsubscribe from key press events.

### Prioritizing System Function Key Events

In e-book or news reader applications, users may want to use the volume keys or swipe gestures on the smart control key to turn pages. For example, volume up and an upward swipe turn to the previous page, while volume down and a downward swipe turn to the next page. Upward and downward swipe gestures on the smart control key are not supported on all devices. Before using them, check whether the current device supports reporting the corresponding key events. In camera or code-scanning applications, users can press a volume key to take a photo directly without launching the system Camera application.

<!-- @[input_monitor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputKit/ArkTSInputConsumer/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import { inputConsumer, KeyEvent, inputDevice, KeyCode } from '@kit.InputKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const DOMAIN = 0x0000;

@Entry
@Component
struct TestDemo14 {
  @State showComponent: boolean = false
  @State text: string = "Default monitoring for Volume Up and Down keys has been added."
  private volumeUpCallBackFunc: (event: KeyEvent) => void = () => {
  }
  private volumeDownCallBackFunc: (event: KeyEvent) => void = () => {
  }
  private slideUpCallBackFunc: (event: KeyEvent) => void = () => {
  }
  private slideDownCallBackFunc: (event: KeyEvent) => void = () => {
  }
  options1: inputConsumer.KeyPressedConfig = {
    key: KeyCode.KEYCODE_VOLUME_UP,
    action: 1, // The value 1 indicates a key press.
    isRepeat: false, // Key events are consumed preferentially and not reported.
  }
  options2: inputConsumer.KeyPressedConfig = {
    key: KeyCode.KEYCODE_VOLUME_DOWN,
    action: 1, // Behavior when the key is pressed.
    isRepeat: false, // Consume the key event with priority and do not report it.
  }
  options3: inputConsumer.KeyPressedConfig = {
    key: KeyCode.KEYCODE_FINGERPRINT_SLIDE_UP,
    action: 1, // Behavior when the key is pressed.
    isRepeat: false, // Consume the key event with priority and do not report it.
  }
  options4: inputConsumer.KeyPressedConfig = {
    key: KeyCode.KEYCODE_FINGERPRINT_SLIDE_DOWN,
    action: 1, // The value 1 indicates a key press.
    isRepeat: false, // Key events are consumed preferentially and not reported.
  }
  // Check whether the device supports KEYCODE_FINGERPRINT_SLIDE_UP and KEYCODE_FINGERPRINT_SLIDE_DOWN.
  private isFingerprintSlideKeySupported(): Promise<boolean> {
    return new Promise<boolean>((resolve) => {
      inputDevice.getDeviceList((error: BusinessError, ids: Array<Number>) => {
        if (error) {
          console.error(`keyPressed Failed to get device id list, error: ${
            JSON.stringify(error, ['code', 'message'])}`);
          resolve(false);
          return;
        }
        console.info(`keyPressed Device id list: ${JSON.stringify(ids)}`);
        for (let idTemp of ids) {
          let res = inputDevice.supportKeysSync(Number(idTemp), [KeyCode.KEYCODE_FINGERPRINT_SLIDE_UP,
            KeyCode.KEYCODE_FINGERPRINT_SLIDE_DOWN]);
          if (res[0] && res[1]) {
            console.info(`keyPressed ${idTemp} Device id list supportKeysSync : ${JSON.stringify(res)}`);
            resolve(true);
            return;
          }
        }
        resolve(false);
      });
    });
  }

  aboutToAppear(): void {
    try {
      // Callback invoked when the Volume Up button is pressed
      this.volumeUpCallBackFunc = (event: KeyEvent) => {
        this.getUIContext().getPromptAction().showToast({ message: 'Volume Up key pressed' })
        // do something
      }

      // Callback invoked when the Volume Down button is pressed
      this.volumeDownCallBackFunc = (event: KeyEvent) => {
        this.getUIContext().getPromptAction().showToast({ message: 'Volume Down key pressed' })
        // do something
      }
      // Callback for the smart control key slide-up event.
      this.slideUpCallBackFunc = (event: KeyEvent) => {
        this.getUIContext().getPromptAction().showToast({ message: 'Slide Up key pressed' })
        // do something
      }

      // Callback for the smart control key slide-down event.
      this.slideDownCallBackFunc = (event: KeyEvent) => {
        this.getUIContext().getPromptAction().showToast({ message: 'Slide Down key pressed' })
        // do something
      }
      this.isFingerprintSlideKeySupported().then((supported: boolean) => {
        this.showComponent = supported;
      }).catch((error: Error) => {
        console.error(`Failed to check fingerprint support: ${JSON.stringify(error)}`);
        this.showComponent = false;
      });
    } catch (error) {
      hilog.error(DOMAIN, 'InputConsumer', `Subscribe execute failed, error: %{public}s`,
        JSON.stringify(error, ["code", "message"]));
    }
  }

  build() {
    Column() {
      // Register and unregister volume key events.
      Row() {
        Button('Add monitoring for Volume Up key')
          .onClick(() => {
            try {
              // Add a specified callback function.
              inputConsumer.on('keyPressed', this.options1, this.volumeUpCallBackFunc);
              this.getUIContext()
                .getPromptAction()
                .showToast({ message: 'Successfully added monitoring for Volume Up key!' })
              this.text = "Monitoring for Volume Up key has been added."
            } catch (error) {
              hilog.error(DOMAIN, 'InputConsumer', `Unsubscribe execute failed, error: %{public}s`,
                JSON.stringify(error, ["code", "message"]));
              this.getUIContext()
                .getPromptAction()
                .showToast({ message: 'Failed to add monitoring for Volume Up key!' })
              this.text = `Failed to add monitoring for Volume Up key: ${JSON.stringify(error, ["code", "message"])}`
            }
          })
      }.width('100%')
      .justifyContent(FlexAlign.Center)
      .margin({ top: 20, bottom: 20 })

      Row() {
        Button('Remove monitoring for Volume Up key')
          .onClick(() => {
            try {
              // Disable listening for a single callback.
              inputConsumer.off('keyPressed', this.volumeUpCallBackFunc);
              this.getUIContext()
                .getPromptAction()
                .showToast({ message: 'Successfully removed monitoring for Volume Up key!' })
              this.text = "Monitoring for Volume Up key has been removed."
            } catch (error) {
              hilog.error(DOMAIN, 'InputConsumer', `Unsubscribe execute failed, error: %{public}s`,
                JSON.stringify(error, ["code", "message"]));
              this.getUIContext()
                .getPromptAction()
                .showToast({ message: 'Failed to remove monitoring for Volume Up key!' })
              this.text = `Failed to remove monitoring for Volume Up key: ${JSON.stringify(error, ["code", "message"])}`
            }
          })
      }.width('100%')
      .justifyContent(FlexAlign.Center)
      .margin({ top: 20, bottom: 20 })

      Row() {
        Button('Add monitoring for Volume Down key')
          .onClick(() => {
            try {
              // Add a specified callback function.
              inputConsumer.on('keyPressed', this.options2, this.volumeDownCallBackFunc);
              this.getUIContext()
                .getPromptAction()
                .showToast({ message: 'Successfully added monitoring for Volume Down key!' })
              this.text = "Monitoring for Volume Down key has been added."
            } catch (error) {
              hilog.error(DOMAIN, 'InputConsumer', `Unsubscribe execute failed, error: %{public}s`,
                JSON.stringify(error, ["code", "message"]));
              this.getUIContext()
                .getPromptAction()
                .showToast({ message: 'Failed to add monitoring for Volume Down key!' })
              this.text = `Failed to add monitoring for Volume Down key: ${JSON.stringify(error, ["code", "message"])}`
            }
          })
      }.width('100%')
      .justifyContent(FlexAlign.Center)
      .margin({ top: 20, bottom: 20 })

      Row() {
        Button('Remove monitoring for Volume Down key')
          .onClick(() => {
            try {
              // Disable listening for a single callback.
              inputConsumer.off('keyPressed', this.volumeDownCallBackFunc);
              this.getUIContext()
                .getPromptAction()
                .showToast({ message: 'Successfully removed monitoring for Volume Down key!' })
              this.text = "Monitoring for Volume Down key has been removed."
            } catch (error) {
              hilog.error(DOMAIN, 'InputConsumer', `Unsubscribe execute failed, error: %{public}s`,
                JSON.stringify(error, ["code", "message"]));
              this.getUIContext()
                .getPromptAction()
                .showToast({ message: 'Failed to remove monitoring for Volume Down key!' })
              this.text =
                `Failed to remove monitoring for Volume Down key: ${JSON.stringify(error, ["code", "message"])}`
            }
          })
      }.width('100%')
      .justifyContent(FlexAlign.Center)
      .margin({ top: 20, bottom: 20 })

      // Register and unregister smart control key events.
      // If the device does not support the smart control key slide-up and slide-down keys, disable the user entry.
      if (this.showComponent) {
        Row() {
          Button('Add monitoring for Slide Up key')
            .onClick(() => {
              try {
                // Add the specified callback function.
                inputConsumer.on('keyPressed', this.options3, this.slideUpCallBackFunc);
                this.getUIContext()
                  .getPromptAction()
                  .showToast({ message: 'Successfully added monitoring for Slide Up key!' })
                this.text = "Monitoring for Slide Up key has been added."
              } catch (error) {
                hilog.error(DOMAIN, 'InputConsumer', `Unsubscribe execute failed, error: %{public}s`,
                  JSON.stringify(error, ["code", "message"]));
                this.getUIContext()
                  .getPromptAction()
                  .showToast({ message: 'Failed to add monitoring for Slide Up key!' })
                this.text = `Failed to add monitoring for Slide Up key: ${JSON.stringify(error, ["code", "message"])}`
              }
            })
        }.width('100%')
        .justifyContent(FlexAlign.Center)
        .margin({ top: 20, bottom: 20 })

        Row() {
          Button('Remove monitoring for Slide Up key')
            .onClick(() => {
              try {
                // Remove the specified callback function.
                inputConsumer.off('keyPressed', this.slideUpCallBackFunc);
                this.getUIContext()
                  .getPromptAction()
                  .showToast({ message: 'Successfully removed monitoring for Slide Up key!' })
                this.text = "Monitoring for Slide Up key has been removed."
              } catch (error) {
                hilog.error(DOMAIN, 'InputConsumer', `Unsubscribe execute failed, error: %{public}s`,
                  JSON.stringify(error, ["code", "message"]));
                this.getUIContext()
                  .getPromptAction()
                  .showToast({ message: 'Failed to remove monitoring for Slide Up key!' })
                this.text =
                  `Failed to remove monitoring for Slide Up key: ${JSON.stringify(error, ["code", "message"])}`
              }
            })
        }.width('100%')
        .justifyContent(FlexAlign.Center)
        .margin({ top: 20, bottom: 20 })

        Row() {
          Button('Add monitoring for Slide Down key')
            .onClick(() => {
              try {
                // Add the specified callback function.
                inputConsumer.on('keyPressed', this.options4, this.slideDownCallBackFunc);
                this.getUIContext()
                  .getPromptAction()
                  .showToast({ message: 'Successfully added monitoring for Slide Down key!' })
                this.text = "Monitoring for Slide Down key has been added."
              } catch (error) {
                hilog.error(DOMAIN, 'InputConsumer', `Unsubscribe execute failed, error: %{public}s`,
                  JSON.stringify(error, ["code", "message"]));
                this.getUIContext()
                  .getPromptAction()
                  .showToast({ message: 'Failed to add monitoring for Slide Down key!' })
                this.text = `Failed to add monitoring for Slide Down key: ${JSON.stringify(error, ["code", "message"])}`
              }
            })
        }.width('100%')
        .justifyContent(FlexAlign.Center)
        .margin({ top: 20, bottom: 20 })

        Row() {
          Button('Remove monitoring for Slide Down key')
            .onClick(() => {
              try {
                // Remove the specified callback function.
                inputConsumer.off('keyPressed', this.slideDownCallBackFunc);
                this.getUIContext()
                  .getPromptAction()
                  .showToast({ message: 'Successfully removed monitoring for Slide Down key!' })
                this.text = "Monitoring for Slide Down key has been removed."
              } catch (error) {
                hilog.error(DOMAIN, 'InputConsumer', `Unsubscribe execute failed, error: %{public}s`,
                  JSON.stringify(error, ["code", "message"]));
                this.getUIContext()
                  .getPromptAction()
                  .showToast({ message: 'Failed to remove monitoring for Slide Down key!' })
                this.text =
                  `Failed to remove monitoring for Slide Down key: ${JSON.stringify(error, ["code", "message"])}`
              }
            })
        }.width('100%')
        .justifyContent(FlexAlign.Center)
        .margin({ top: 20, bottom: 20 })
      }

      Row() {
        Text(this.text)
      }
      .width('100%')
      .justifyContent(FlexAlign.Center)
    }.width('100%').height('100%')
  }
}
```