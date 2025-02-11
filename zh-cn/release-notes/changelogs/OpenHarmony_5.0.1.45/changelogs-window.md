# 窗口子系统变更说明

## cl.window.1 在2in1设备上getWindowStatus和on('windowStatusChange')接口在窗口最大化状态返回值变更

**访问级别**

公开接口

**变更原因**

getWindowStatus和on('windowStatusChange') 接口在最大化状态返回值为 WindowStatusType::FULL_SCREEN，与实际情况不符合。

应用无法直接通过这两个接口在2in1设备上区分当前最大化和全屏状态，与接口功能设计不符合。

**变更影响**

该变更为不兼容变更。

变更前：2in1设备上调用getWindowStatus和on('windowStatusChange') 接口，在最大化状态返回值为WindowStatusType::FULL_SCREEN。

变更后：2in1设备上调用getWindowStatus和on('windowStatusChange') 接口，在最大化状态返回值为WindowStatusType::MAXIMIZE。

**起始 API Level**

on('windowStatusChange')接口从API version 11开始支持

在2in1设备上getWindowStatus接口从API version 12开始支持

**变更发生版本**

从OpenHarmony SDK 5.0.1.45开始。

**变更的接口/组件**

@ohos.window.d.ts

系统能力：SystemCapability.Window.SessionManager

接口：getWindowStatus、on('windowStatusChange')

**适配指导**

针对2in1设备上想要区分当前窗口最大化状态和全屏状态的场景，在变更前后的实现方案分别如下：

- API version 13及之前的版本，可以在窗口状态为WindowStatusType::FULL_SCREEN的情况下，再调用[getImmersiveModeEnabledState()](../../../application-dev/reference/apis-arkui/js-apis-window.md#getimmersivemodeenabledstate12) 接口进行进一步判断，到底是最大化状态还是全屏状态。若接口返回true则表示当前窗口为全屏状态，若接口返回false则表示当前窗口为最大化状态。

- API version 14及之后的版本，可以直接调用getWindowStatus、on('windowStatusChange')接口区分窗口最大化和全屏状态。

  不过需要注意返回值的变更和代码适配：若应用针对WindowStatusType::FULL_SCREEN 和 WindowStatusType::MAXIMIZE状态的代码处理逻辑相同，则在对应的逻辑处理时，直接追加WindowStatusType::MAXIMIZE判断条件（条件或）即可；若应用针对WindowStatusType::FULL_SCREEN和 WindowStatusType::MAXIMIZE状态有不同的处理逻辑，则需要增加新的WindowStatusType::MAXIMIZE条件判断分支中进行窗口最大化状态相关逻辑的处理。

以下示例以on('windowStatusChange') 接口为例，提供变更前后2in1设备上区分当前窗口最大化状态和全屏状态的指导和适配示例：

API version 13及之前版本区分最大化状态示例：
```ts
// EntryAbility.ets
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    try {
      let windowClass = windowStage.getMainWindowSync();
      windowClass?.on("windowStatusChange", (windowStatusType: window.WindowStatusType) => {
        if (windowStatusType == window.WindowStatusType.FULL_SCREEN) {
          // isFullScreen 为true 表示全屏，为false 表示最大化
          let isFullScreen: boolean = windowClass.getImmersiveModeEnabledState();
        } else {
          // ...
        }
      })
    } catch (exception) {
      console.error(`Failed to obtain the main window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

API version 14版本区分最大化状态示例：
```ts
// EntryAbility.ets
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    try {
      let windowClass = windowStage.getMainWindowSync();
      windowClass?.on("windowStatusChange", (windowStatusType: window.WindowStatusType) => {
        // 应用对于窗口全屏和最大化状态的处理逻辑不同，新增window.WindowStatusType.MAXIMIZE的判断分支
        if (windowStatusType == window.WindowStatusType.FULL_SCREEN) {
          // ....
        } else if (windowStatusType == window.WindowStatusType.MAXIMIZE) {
          // ...
        } else {
          // ...
        }
      })
    } catch (exception) {
      console.error(`Failed to obtain the main window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

API version 14版本不区分最大化状态示例：
```ts
// EntryAbility.ets
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    try {
      let windowClass = windowStage.getMainWindowSync();
      windowClass?.on("windowStatusChange", (windowStatusType: window.WindowStatusType) => {
        // 应用对于窗口全屏和最大化状态的处理逻辑相同，直接在判断时新增针对window.WindowStatusType.MAXIMIZE的或条件
        if (windowStatusType == window.WindowStatusType.FULL_SCREEN ||
            windowStatusType == window.WindowStatusType.MAXIMIZE) {
          // ....
        } else {
          // ...
        }
      })
    } catch (exception) {
      console.error(`Failed to obtain the main window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## cl.window.2 在2in1设备上hasImmersiveWindow接口在窗口最大化状态返回值变更

**访问级别**

系统接口

**变更原因**

在2in1设备上调用hasImmersiveWindow接口在窗口处于最大化状态时返回true，与实际情况不符合。

无法通过这个接口在2in1设备上区分是否有窗口处于最大化状态，还是全屏状态，与接口功能设计不符合。

**变更影响**

该变更为不兼容变更。

变更前：2in1设备上调用hasImmersiveWindow接口时，如果窗口处于最大化状态时下，则返回true。

变更后：2in1设备上调用hasImmersiveWindow接口时，如果窗口处于最大化状态时下，则返回false。

**起始 API Level**

hasImmersiveWindow接口从API version 11开始支持

**变更发生版本**

从OpenHarmony SDK 5.0.1.45开始。

**变更的接口/组件**

@ohos.display.d.ts

系统能力：SystemCapability.Window.SessionManager

接口：hasImmersiveWindow

**适配指导**

排查应用实现中是否存在调用hasImmersiveWindow判断当前屏幕是否包含全屏窗口的场景。若涉及，需要根据返回值变更进行调整适配。
