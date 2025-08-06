# 窗口生命周期机制说明与开发指导

## 应用主窗口生命周期和UIAbility组件生命周期

**应用主窗口生命周期概述**

窗口在进入前台、前后台切换及退后台时，会触发窗口相应的生命周期状态变化。应用主窗口的生命周期状态包括切到前台（SHOWN）、可交互状态（RESUMED）、不可交互状态（PAUSED）和切到后台（HIDDEN）。

**UIAbility组件生命周期概述**

用户在打开、切换和返回到应用时，UIAbility实例会在其生命周期的不同状态之间转换。UIAbility的生命周期包括Create、Foreground、Background和Destroy四个状态，如下图所示。

![tabStop](figures/uiablity-lifecycle.png)

当用户在执行应用启动、应用前后台切换、应用退出等操作时，系统会触发相关应用组件的生命周期回调。其中，UIAbility组件的核心生命周期回调包括onCreate、onForeground、onBackground、onDestroy。回调的详细说明参见[UIAbility组件生命周期](../../application-models/uiability-lifecycle.md#uiability组件生命周期)。

UIAbility实例创建完成之后，在进入前台之前，系统会创建一个[WindowStage](../../windowmanager/application-window-stage.md)。WindowStage创建完成后会进入[onWindowStageCreate()](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onwindowstagecreate)回调，开发者可以在该回调中设置UI界面加载、设置WindowStage的事件订阅。UIAbility的生命周期与[WindowStage](../../windowmanager/application-window-stage.md)的生命周期存在关联关系，两者生命周期关系示意图如下图所示。

![tabStop](figures/uiability-lifecycle-windowstage.png)

## 应用主窗口生命周期说明

> **说明：**
>
> - 如果需要感知应用主窗口生命周期变化，开发者可以使用[on('windowStageLifecycleEvent')](arkts-apis-window-WindowStage.md#on('windowstagelifecycleevent')20)注册监听应用主窗口生命周期变化。

**SHOWN**

窗口进入到前台。窗口触发SHOWN生命周期事件后，将会进入到可交互状态。特殊场景下，会进入不可交互状态，例如应用锁加锁场景。

**RESUMED**

窗口进入可交互状态。窗口到前台后会进入该状态，另外，窗口恢复，也会触发RESUMED生命周期事件。例如从多任务列表进入应用。

**PAUSED**

窗口进入不可交互状态。窗口触发PAUSED生命周期事件，说明窗口不再位于前台，窗口会保持这种状态，直到恢复或退后台。如果窗口恢复，则会触发RESUMED生命周期事件，进入可交互状态。

**HIDDEN**

窗口进入到后台。当窗口不在对用户可见时，触发HIDDEN生命周期事件，它会进入到后台。例如应用内上滑返回桌面，应用会进入该状态。

|事件名称|说明|触发场景举例|
|-------|----------|----------|
|SHOWN  |切到前台        |例如：应用全屏启动、悬浮窗被拉起等。|
|RESUMED|前台可交互状态  |例如：应用全屏启动、悬浮窗被拉起、应用上滑悬停后回到应用等。|
|PAUSED |前台不可交互状态|例如：应用退后台回到桌面、上滑进入多任务、进入应用锁认证界面，应用上滑悬停、应用退后台、应用销毁等。|
|HIDDEN |切到后台       |例如：应用上滑回到桌面、应用退后台、应用销毁等。|

应用主窗口生命周期事件调度关系如下图：

![tabStop](figures/window-lifecycle-event.png)

### 应用主窗口生命周期RESUMED和PAUSED状态详细说明

RESUMED和PAUSED状态分别在窗口切换至前台和切换至后台时触发。但是在一些场景下，RESUMED和PAUSED状态触发会有差异。
- 如果前台窗口是全屏或悬浮窗时，可能存在PAUSED事件差异。
- 在一些系统管控场景下会导致RESUMED和PAUSED事件差异，例如应用锁场景，应用窗口在切换至前台进入到认证界面时，触发PAUSED事件。

## 新接口与老接口差异

**新接口**

新接口[on('windowStageLifecycleEvent')](arkts-apis-window-WindowStage.md#on('windowstagelifecycleevent')20)监听的窗口生命周期包括切到前台（SHOWN）、前台可交互状态（RESUMED）、前台不可交互状态（PAUSED）和切到后台（HIDDEN），不包含获焦状态（ACTIVE）和失焦状态（INACTIVE）。

**老接口**

老接口[on('windowStageEvent')](arkts-apis-window-WindowStage.md#on('windowstageevent')9)监听的窗口生命周期包括切到前台（SHOWN）、获焦状态（ACTIVE）、失焦状态（INACTIVE）、切到后台（HIDDEN）、前台可交互状态（RESUMED）和前台不可交互状态（PAUSED）。

**新接口和老接口区别**

- 老接口无法保证状态切换间的顺序，对于状态间的顺序有要求的情况下不推荐使用，推荐使用新接口；
- 新接口不提供WindowStage的获焦失焦状态监听，对于windowStage获焦失焦状态有监听需求的情况下，推荐使用[on('windowEvent')](arkts-apis-window-Window.md#on('windowevent')10)。

## 新接口适配指导

**开启监听**

通过新接口[on('windowStageLifecycleEvent')](arkts-apis-window-WindowStage.md#on('windowstagelifecycleevent')20)开启WindowStage新生命周期变化的监听可参考下列代码进行适配。

示例：

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    const callback = (data: window.WindowStageLifecycleEventType) => {
      console.info('Succeeded in enabling the listener for window stage event changes. Data: ' +
        JSON.stringify(data));
      // 根据事件状态类型选择进行具体的处理
      if (data === window.WindowStageLifecycleEventType.SHOWN) {
        console.info('current window stage event is SHOWN');
        // ...
      } else if (data === window.WindowStageLifecycleEventType.RESUMED) {
        console.info('current window stage event is RESUMED');
        // ...
      } else if (data === window.WindowStageLifecycleEventType.PAUSED) {
        console.info('current window stage event is PAUSED');
        // ...
      } else if (data === window.WindowStageLifecycleEventType.HIDDEN) {
        console.info('current window stage event is HIDDEN');
        // ...
      }
      // ...
    }
    try {
      windowStage.on('windowStageLifecycleEvent', callback);
    } catch (exception) {
      console.error(`Failed to enable the listener for window stage event changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

**关闭监听**

通过新接口[off('windowStageLifecycleEvent')](arkts-apis-window-WindowStage.md#off('windowstagelifecycleevent')20)关闭WindowStage新生命周期变化的监听可参考如下代码进行适配。

示例：

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    const callback = (windowStageLifecycleEvent: window.WindowStageLifecycleEventType) => {
      // ...
    }
    try {
      windowStage.on('windowStageLifecycleEvent', callback);
    } catch (exception) {
      console.error(`Failed to enable the listener for window stage event changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
    try {
      windowStage.off('windowStageLifecycleEvent', callback);
      // 如果通过on开启多个callback进行监听，同时关闭所有监听：
      windowStage.off('windowStageLifecycleEvent');
    } catch (exception) {
      console.error(`Failed to disable the listener for window stage event changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```
