# 窗口子系统变更说明

## cl.window.1 setWindowLayoutFullScreen、setImmersiveModeEnabledState接口在2in1设备和平板设备的自由多窗模式上禁用

**访问级别**

公开接口

**变更原因**

因为phone设备上的沉浸式是应用布局全屏且窗口与系统状态栏与导航条交叠，而平板设备的自由多窗模式上的沉浸式是应用布局全屏且窗口与导航条交叠，2in1设备上的沉浸式是应用布局全屏且隐藏系统状态栏和Dock栏，行为与phone设备不一致。所以在2in1设备和平板设备的自由多窗模式上禁用setWindowLayoutFullScreen、setImmersiveModeEnabledState接口，只能调用maximize接口设置进入/退出沉浸式，在进入最大化时通过maximize接口的入参控制状态栏和Dock栏的隐藏/显示状态。

**变更影响**

该变更为不兼容变更。

变更前：2in1设备和平板设备的自由多窗模式上调用setWindowLayoutFullScreen、setImmersiveModeEnabledState接口，窗口进入/退出沉浸式。

变更后：2in1设备和平板设备的自由多窗模式上调用setWindowLayoutFullScreen、setImmersiveModeEnabledState接口不生效。

**起始 API Level**

setWindowLayoutFullScreen接口从API version 9开始支持

setImmersiveModeEnabledState接口从API version 12开始支持

**变更发生版本**

从OpenHarmony SDK 5.0.0.56开始。

**变更的接口/组件**

@ohos.window.d.ts

系统能力：SystemCapability.Window.SessionManager

接口：setWindowLayoutFullScreen、setImmersiveModeEnabledState

**适配指导**

2in1设备和平板设备的自由多窗模式上需要调用[maximize](../../../application-dev/reference/apis-arkui/js-apis-window.md#maximize12)接口实现窗口沉浸式状态设置。

当调用[setWindowLayoutFullScreen](../../../application-dev/reference/apis-arkui/js-apis-window.md#setwindowlayoutfullscreen9)接口时，建议同时调用setWindowLayoutFullScreen和maximize接口。

当调用[setImmersiveModeEnabledState](../../../application-dev/reference/apis-arkui/js-apis-window.md#setimmersivemodeenabledstate12)接口时，建议同时调用setImmersiveModeEnabledState和maximize接口。

示例：

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