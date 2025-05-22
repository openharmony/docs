# @ohos.animation.windowAnimationManager (Window Animation Management) (System API)

The **WindowAnimationManager** module provides APIs to listen for application start/exit events and window minimization/maximization events and associate animations with these events.

>  **NOTE**
>
>  - The APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
>  - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { windowAnimationManager } from '@kit.ArkUI';
```

## windowAnimationManager.setController

setController(controller: WindowAnimationController): void

Sets a window animation controller. For details about the controller, see [WindowAnimationController](#windowanimationcontroller).

Before using other APIs of **windowAnimationManager**, you must call this API to set a window animation controller.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| controller | [WindowAnimationController](#windowanimationcontroller) | Yes | Window animation controller to set.|

**Example**

```ts
let controller: windowAnimationManager.WindowAnimationController = {
    onStartAppFromLauncher(startingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onStartAppFromLauncher, the startingWindowTarget is: ' + startingWindowTarget);
        finishCallback.onAnimationFinish();
	  },
    onStartAppFromRecent(startingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onStartAppFromRecent, the startingWindowTarget is: ' + startingWindowTarget);
        finishCallback.onAnimationFinish();
    },
    onStartAppFromOther(startingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onStartAppFromOther, the startingWindowTarget is: ' + startingWindowTarget);
        finishCallback.onAnimationFinish();
    },
    onAppTransition(fromWindowTarget: windowAnimationManager.WindowAnimationTarget, toWindowTarget: WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onAppTransition, the fromWindowTarget is: ' + fromWindowTarget);
        console.log('onAppTransition, the toWindowTarget is: ' + toWindowTarget);
        finishCallback.onAnimationFinish();
    },
    onMinimizeWindow(minimizingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onMinimizeWindow, the minimizingWindowTarget is: ' + minimizingWindowTarget);
        finishCallback.onAnimationFinish();
    },
    onCloseWindow(closingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onCloseWindow, the closingWindowTarget is: ' + closingWindowTarget);
        finishCallback.onAnimationFinish();
    },
    onScreenUnlock(finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onScreenUnlock called');
        finishCallback.onAnimationFinish();
    },
    onWindowAnimationTargetsUpdate(fullScreenWindowTarget: windowAnimationManager.WindowAnimationTarget, floatingWindowTargets: Array<windowAnimationManager.WindowAnimationTarget>): void {
        console.log('onWindowAnimationTargetsUpdate, the fullScreenWindowTarget is: ' + fullScreenWindowTarget);
        console.log('onWindowAnimationTargetsUpdate, the floatingWindowTargets are: ' + floatingWindowTargets);
    }
}

windowAnimationManager.setController(controller);
```

## windowAnimationManager.minimizeWindowWithAnimation

minimizeWindowWithAnimation(windowTarget: WindowAnimationTarget, callback: AsyncCallback&lt;WindowAnimationFinishedCallback&gt;): void

Minimizes the window that displays the animation. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| windowTarget | [WindowAnimationTarget](#windowanimationtarget) | Yes | Target window to minimize.|
| callback | AsyncCallback&lt;[WindowAnimationFinishedCallback](#windowanimationfinishedcallback)&gt; | Yes | Callback used to return the result. If the target window is minimized, **err** is **undefined** and **data** is the **WindowAnimationFinishedCallback** obtained; otherwise, **err.code** is **-1** and **data** is **undefined**.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let target: windowAnimationManager.WindowAnimationTarget | null = null;
let controller: windowAnimationManager.WindowAnimationController = {
    onStartAppFromLauncher(startingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onStartAppFromLauncher, the startingWindowTarget is: ' + startingWindowTarget);
        target = startingWindowTarget;
        finishCallback.onAnimationFinish();
	  },
    onStartAppFromRecent(startingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onStartAppFromRecent, the startingWindowTarget is: ' + startingWindowTarget);
        target = startingWindowTarget;
        finishCallback.onAnimationFinish();
    },
    onStartAppFromOther(startingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onStartAppFromOther, the startingWindowTarget is: ' + startingWindowTarget);
        target = startingWindowTarget;
        finishCallback.onAnimationFinish();
    },
    onAppTransition(fromWindowTarget: windowAnimationManager.WindowAnimationTarget, toWindowTarget: WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onAppTransition, the fromWindowTarget is: ' + fromWindowTarget);
        console.log('onAppTransition, the toWindowTarget is: ' + toWindowTarget);
        target = toWindowTarget;
        finishCallback.onAnimationFinish();
    },
    onMinimizeWindow(minimizingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onMinimizeWindow, the minimizingWindowTarget is: ' + minimizingWindowTarget);
        target = minimizingWindowTarget;
        finishCallback.onAnimationFinish();
    },
    onCloseWindow(closingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onCloseWindow, the closingWindowTarget is: ' + closingWindowTarget);
        target = closingWindowTarget;
        finishCallback.onAnimationFinish();
    },
    onScreenUnlock(finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onScreenUnlock called');
        finishCallback.onAnimationFinish();
    },
    onWindowAnimationTargetsUpdate(fullScreenWindowTarget: windowAnimationManager.WindowAnimationTarget, floatingWindowTargets: Array<windowAnimationManager.WindowAnimationTarget>): void {
        console.log('onWindowAnimationTargetsUpdate, the fullScreenWindowTarget is: ' + fullScreenWindowTarget);
        console.log('onWindowAnimationTargetsUpdate, the floatingWindowTargets are: ' + floatingWindowTargets);
        target = fullScreenWindowTarget;
    }
}

windowAnimationManager.setController(controller);

let finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback;
windowAnimationManager.minimizeWindowWithAnimation(target, (err: BusinessError, data: windowAnimationManager.WindowAnimationFinishedCallback) => {
    if (err) {
        console.error('Failed to minimize the window target. Cause: ' + JSON.stringify(err));
        return;
    }
    finishedCallback = data;

    // After the callback is received, the window starts to play the animation. After the animation is finished, the **onAnimationFinish** callback is invoked.
    finishedCallback.onAnimationFinish();
});
```

## windowAnimationManager.minimizeWindowWithAnimation

minimizeWindowWithAnimation(windowTarget: WindowAnimationTarget): Promise&lt;WindowAnimationFinishedCallback&gt;

Minimizes the window that displays the animation. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| windowTarget | [WindowAnimationTarget](#windowanimationtarget) | Yes | Target window to display the animation.|

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[WindowAnimationFinishedCallback](#windowanimationfinishedcallback)&gt; | Promise used to return a call when the animation is finished. |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let target: windowAnimationManager.WindowAnimationTarget | null  = null;
let controller: windowAnimationManager.WindowAnimationController = {
    onStartAppFromLauncher(startingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onStartAppFromLauncher, the startingWindowTarget is: ' + startingWindowTarget);
        finishCallback.onAnimationFinish();
	  },
    onStartAppFromRecent(startingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onStartAppFromRecent, the startingWindowTarget is: ' + startingWindowTarget);
        finishCallback.onAnimationFinish();
    },
    onStartAppFromOther(startingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onStartAppFromOther, the startingWindowTarget is: ' + startingWindowTarget);
        finishCallback.onAnimationFinish();
    },
    onAppTransition(fromWindowTarget: windowAnimationManager.WindowAnimationTarget, toWindowTarget: WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onAppTransition, the fromWindowTarget is: ' + fromWindowTarget);
        console.log('onAppTransition, the toWindowTarget is: ' + toWindowTarget);
        finishCallback.onAnimationFinish();
    },
    onMinimizeWindow(minimizingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onMinimizeWindow, the minimizingWindowTarget is: ' + minimizingWindowTarget);
        finishCallback.onAnimationFinish();
    },
    onCloseWindow(closingWindowTarget: windowAnimationManager.WindowAnimationTarget, finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onCloseWindow, the closingWindowTarget is: ' + closingWindowTarget);
        finishCallback.onAnimationFinish();
    },
    onScreenUnlock(finishCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
        console.log('onScreenUnlock called');
        finishCallback.onAnimationFinish();
    },
    onWindowAnimationTargetsUpdate(fullScreenWindowTarget: windowAnimationManager.WindowAnimationTarget, floatingWindowTargets: Array<windowAnimationManager.WindowAnimationTarget>): void {
        console.log('onWindowAnimationTargetsUpdate, the fullScreenWindowTarget is: ' + fullScreenWindowTarget);
        console.log('onWindowAnimationTargetsUpdate, the floatingWindowTargets are: ' + floatingWindowTargets);
    }
}

windowAnimationManager.setController(controller);

let promise: Promise<windowAnimationManager.WindowAnimationFinishedCallback> = windowAnimationManager.minimizeWindowWithAnimation(target);
promise.then((data: windowAnimationManager.WindowAnimationFinishedCallback) => {
    data.onAnimationFinish();
}).catch((err: BusinessError)=>{
    console.error('Failed to minimize the window target. Cause: ' + JSON.stringify(err));
    return;
});
```

## WindowAnimationController

Implements the window animation controller. When creating a **WindowAnimationController** object, you must implement all callbacks in the object.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

### onStartAppFromLauncher

onStartAppFromLauncher(startingWindowTarget: WindowAnimationTarget,finishCallback: WindowAnimationFinishedCallback): void

Called when an application is started from the home screen.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Type                                                        | Mandatory | Description              |
| -------------------- | ------------------------------------------------------------ | ---- | ------------------ |
| startingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)              | Yes  | Target window to display the animation.    |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | Yes  | Callback invoked when the animation is finished. |

**Example**

For details, see the sample code under [windowAnimationManager.setController](#windowanimationmanagersetcontroller).

### onStartAppFromRecent

onStartAppFromRecent(startingWindowTarget: WindowAnimationTarget,finishCallback:WindowAnimationFinishedCallback): void

Called when an application is started from the recent task list.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Type                                                        | Mandatory | Description              |
| -------------------- | ------------------------------------------------------------ | ---- | ------------------ |
| startingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)              | Yes  | Target window to display the animation.    |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | Yes  | Callback invoked when the animation is finished. |

**Example**

For details, see the sample code under [windowAnimationManager.setController](#windowanimationmanagersetcontroller).

### onStartAppFromOther

onStartAppFromOther(startingWindowTarget: WindowAnimationTarget,finishCallback: WindowAnimationFinishedCallback): void

Called when an application is started from a place other than the home screen and recent task list.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Type                                                        | Mandatory | Description              |
| -------------------- | ------------------------------------------------------------ | ---- | ------------------ |
| startingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)              | Yes  | Target window to display the animation.    |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | Yes  | Callback invoked when the animation is finished. |

**Example**

For details, see the sample code under [windowAnimationManager.setController](#windowanimationmanagersetcontroller).

### onAppTransition

onAppTransition(fromWindowTarget: WindowAnimationTarget, toWindowTarget: WindowAnimationTarget,finishCallback: WindowAnimationFinishedCallback): void

Called during application transition.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Type                           | Mandatory | Description            |
| -------------------- | ------------------------------- | ---- | ---------------- |
| fromWindowTarget | [WindowAnimationTarget](#windowanimationtarget)           | Yes  | Window that displays the animation before the transition. |
| toWindowTarget       | [WindowAnimationTarget](#windowanimationtarget) | Yes  | Window that displays the animation after the transition. |
| finishCallback | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | Yes  | Callback invoked when the animation is finished. |

**Example**

For details, see the sample code under [windowAnimationManager.setController](#windowanimationmanagersetcontroller).

### onMinimizeWindow

onMinimizeWindow(minimizingWindowTarget: WindowAnimationTarget,finishCallback: WindowAnimationFinishedCallback): void

Called when a window is minimized.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Type                           | Mandatory | Description            |
| -------------------- | ------------------------------- | ---- | ---------------- |
| minimizingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)           | Yes  | Target window to display the animation.   |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | Yes  | Callback invoked when the animation is finished. |

**Example**

For details, see the sample code under [windowAnimationManager.setController](#windowanimationmanagersetcontroller).

### onCloseWindow

onCloseWindow(closingWindowTarget: WindowAnimationTarget,finishCallback: WindowAnimationFinishedCallback): void

Called when a window is closed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Type                           | Mandatory | Description            |
| -------------------- | ------------------------------- | ---- | ---------------- |
| closingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)           | Yes  | Target window to display the animation.   |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | Yes  | Callback invoked when the animation is finished. |

**Example**

For details, see the sample code under [windowAnimationManager.setController](#windowanimationmanagersetcontroller).

### onScreenUnlock

onScreenUnlock(finishCallback: [WindowAnimationFinishedCallback](#windowanimationfinishedcallback)): void

Called when the screen is unlocked.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name        | Type                                                        | Mandatory | Description              |
| -------------- | ------------------------------------------------------------ | ---- | ------------------ |
| finishCallback | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | Yes  | Callback invoked when the animation is finished. |

**Example**

For details, see the sample code under [windowAnimationManager.setController](#windowanimationmanagersetcontroller).

### onWindowAnimationTargetsUpdate

onWindowAnimationTargetsUpdate(fullScreenWindowTarget: WindowAnimationTarget, floatingWindowTargets: Array&lt;WindowAnimationTarget&gt;): void

Called when the window that displays the animation is updated.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Type                           | Mandatory | Description            |
| -------------------- | ------------------------------- | ---- | ---------------- |
| fullScreenWindowTarget | [WindowAnimationTarget](#windowanimationtarget) | Yes  | Target window in full-screen mode.|
| floatingWindowTargets| Array&lt;[WindowAnimationTarget](#windowanimationtarget)&gt; | Yes  | Target window in the form of a floating window. |

**Example**

For details, see the sample code under [windowAnimationManager.setController](#windowanimationmanagersetcontroller).

## WindowAnimationFinishedCallback
Implements a callback that is invoked when the animation is finished.

### onAnimationFinish

onAnimationFinish():void

Called when the animation is finished.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Example**

For details, see the sample code under [windowAnimationManager.setController](#windowanimationmanagersetcontroller).

## WindowAnimationTarget
Defines a window to display animation.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name     | Type    | Mandatory | Description |
| ------- | ------ | ------ | ----------------------- |
| bundleName  | string | Yes |Bundle name corresponding to the target window. |
| abilityName | string | Yes |Ability name corresponding to the target window. |
| windowBounds | [RRect](#rrect) | Yes |Actual size of the target window. |
| missionId  | number | Yes |Mission ID, which is used to match an ability when there are multiple missions.|

## RRect
Describes a rounded rectangle.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name     | Type    | Mandatory | Description |
| ------- | ------ | ------|----------------------- |
| left  | number | Yes |Horizontal coordinate of the upper left corner of the target window relative to the screen. |
| top | number | Yes |Vertical coordinate of the upper left corner of the target window relative to the screen. |
| width | number | Yes |Width of the target window. |
| height | number | Yes |Height of the target window. |
| radius | number | Yes |Radius of the rounded corner of the target window. |
