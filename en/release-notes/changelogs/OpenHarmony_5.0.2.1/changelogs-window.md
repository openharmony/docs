# Window Subsystem Changelog

## cl.window.1 Disabling setWindowLayoutFullScreen and setImmersiveModeEnabledState on 2-in-1 Devices and Tablets in Freeform Window Mode

**Access Level**

Public API

**Reason for Change**

On smartphones, immersive mode means the application layout is full-screen and the window overlaps with the system status bar and navigation bar. On tablets in freeform window mode, immersive mode means the application layout is full-screen and the window overlaps with the navigation bar. On 2-in-1 devices, immersive mode means the application layout is full-screen and the system status bar and dock bar are hidden. Since the behavior on 2-in-1 devices and tablets does not align with that on smartphones, the **setWindowLayoutFullScreen** and **setImmersiveModeEnabledState** APIs have been disabled on 2-in-1 devices and tablets in freeform window mode. Instead, the **maximize** API should be used to enter or exit immersive mode, and the visibility of the status bar and dock bar should be controlled through the parameters of the **maximize** API when entering maximized mode.

**Change Impact**

This change is a non-compatible change.

Before the change, on 2-in-1 devices and tablets in freeform window mode, calling **setWindowLayoutFullScreen** and **setImmersiveModeEnabledState** puts the window into or exit immersive mode.

After the change, on 2-in-1 devices and tablets in freeform window mode, calling **setWindowLayoutFullScreen** and **setImmersiveModeEnabledState** does not take effect.

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

To set immersive mode for 2-in-1 devices and tablets in freeform window mode, call [maximize](../../../application-dev/reference/apis-arkui/js-apis-window.md#maximize12).

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
