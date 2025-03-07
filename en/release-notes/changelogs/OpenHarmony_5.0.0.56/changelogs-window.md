# Window Subsystem Changelog

## cl.window.1 setWindowLayoutFullScreen and setImmersiveModeEnabledState Are Not Valid for 2-in-1 Devices

**Access Level**

Public API

**Reason for Change**

For mobile phones, immersive mode is characterized by full-screen application layouts that overlap with the system status bar and navigation bar. However, on 2-in-1 devices, full-screen windows tend to hide the system status bar and dock bar, which is different from the behavior on mobile phones. Therefore, the **setWindowLayoutFullScreen** and **setImmersiveModeEnabledState** APIs are disabled on 2-in-1 devices. Instead, the **maximize** API is used to enter or exit immersive mode, and the visibility of the status bar and dock bar is managed by the parameters passed to the **maximize** API.

**Change Impact**

This change is a non-compatible change.

Before change: When the **setWindowLayoutFullScreen** and **setImmersiveModeEnabledState** APIs are called on 2-in-1 devices, the window enters or exits immersive mode.

After change: The **setWindowLayoutFullScreen** and **setImmersiveModeEnabledState** APIs do not take effect on 2-in-1 devices.

**Start API Level**

API version 9 for **setWindowLayoutFullScreen**

API version 12 for **setImmersiveModeEnabledState**

**Change Since**

OpenHarmony SDK 5.0.0.56

**Key API/Component Changes**

@ohos.window.d.ts

System capability: SystemCapability.Window.SessionManager

APIs: **setWindowLayoutFullScreen** and **setImmersiveModeEnabledState**

**Adaptation Guide**

To set the immersive state for a window on 2-in-1 devices, call [maximize](../../../application-dev/reference/apis-arkui/js-apis-window.md#maximize12).

When calling [setWindowLayoutFullScreen](../../../application-dev/reference/apis-arkui/js-apis-window.md#setwindowlayoutfullscreen9), you are advised to call **maximize** at the same time.

When calling [setImmersiveModeEnabledState](../../../application-dev/reference/apis-arkui/js-apis-window.md#setimmersivemodeenabledstate12), you are advised to call **maximize** at the same time.

Example:

```ts
// EntryAbility.ets
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let isLayoutFullScreen = true;
      try {
        let promise = windowClass.setWindowLayoutFullScreen(isLayoutFullScreen);
        promise.then(() => {
          console.info('Succeeded in setting the window layout to full-screen mode.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the window layout to full-screen mode. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set the window layout to full-screen mode. Cause code: ${exception.code}, message: ${exception.message}`);
      }

      try {
        let promise = windowClass.maximize(window.MaximizePresentation.ENTER_IMMERSIVE);
        promise.then(() => {
          console.info('Succeeded in maximizing the window.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to maximize the window. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to maximize the window. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

```ts
// EntryAbility.ets
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      try {
        let enabled = true;
        windowClass.setImmersiveModeEnabledState(enabled);
      } catch (exception) {
        console.error(`Failed to set the window immersive mode enabled status. Cause code: ${exception.code}, message: ${exception.message}`);
      }

      try {
        let promise = windowClass.maximize(window.MaximizePresentation.ENTER_IMMERSIVE);
        promise.then(() => {
          console.info('Succeeded in maximizing the window.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to maximize the window. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to maximize the window. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```
