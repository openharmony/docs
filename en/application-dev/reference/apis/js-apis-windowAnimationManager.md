# Window Animation Management
The **WindowAnimationManager** module provides APIs to listen for application start/exit events and window minimization/maximization events and associate animations with these events.

>  **NOTE**
>
>  The APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
>  The APIs provided by this module are system APIs.

## Modules to Import

```js
import windowAnimationManager from '@ohos.animation.windowAnimationManager'
```

## windowAnimationManager.setController

setController(controller: WindowAnimationController): void

Sets a window animation controller.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| controller | [WindowAnimationController](#windowanimationcontroller) | Yes| Window animation controller to set.|

**Example**

```js
var controller = {
    onStartAppFromLauncher(startingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
      console.log('onStartAppFromLauncher', startingWindowTarget);
	},
    onStartAppFromRecent(startingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
  		console.log('onStartAppFromRecent', startingWindowTarget);
    },
    onStartAppFromOther(startingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
        console.log('onStartAppFromOther', startingWindowTarget);
    },
    onAppTransition(fromWindowTarget: WindowAnimationTarget, toWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
    },
    onMinimizeWindow(minimizingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
    },
    onCloseWindow(closingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
    },
    onScreenUnlock(finishCallback: WindowAnimationFinishedCallback): void {
    }
}

windowAnimationManager.setController(controller)
```

## WindowAnimationController

Implements the window animation controller.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

### onStartAppFromLauncher

onStartAppFromLauncher(startingWindowTarget: WindowAnimationTarget,finishCallback: WindowAnimationFinishedCallback): void

Called when an application is started from the home screen.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Type                                                        | Mandatory| Description              |
| -------------------- | ------------------------------------------------------------ | ---- | ------------------ |
| startingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)              | Yes  | Target window to display the animation.    |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | Yes  | Callback invoked when the animation is finished.|

**Example**

```js
var controller = {
    onStartAppFromLauncher(startingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
      console.log('onStartAppFromLauncher', startingWindowTarget);
	}
}
```

### onStartAppFromRecent

onStartAppFromRecent(startingWindowTarget: WindowAnimationTarget,finishCallback:WindowAnimationFinishedCallback): void

Called when an application is started from the recent task list.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Type                                                        | Mandatory| Description              |
| -------------------- | ------------------------------------------------------------ | ---- | ------------------ |
| startingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)              | Yes  | Target window to display the animation.    |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | Yes  | Callback invoked when the animation is finished.|

**Example**

```js
var controller = {
    onStartAppFromRecent(startingWindowTarget: WindowAnimationTarget, finishCallback:     WindowAnimationFinishedCallback): void {
      console.log('onStartAppFromRecent', startingWindowTarget);
	}
}
```

### onStartAppFromOther

onStartAppFromOther(startingWindowTarget: WindowAnimationTarget,finishCallback: WindowAnimationFinishedCallback): void

Called when an application is started from a place other than the home screen and recent task list.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Type                                                        | Mandatory| Description              |
| -------------------- | ------------------------------------------------------------ | ---- | ------------------ |
| startingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)              | Yes  | Target window to display the animation.    |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | Yes  | Callback invoked when the animation is finished.|

**Example**

```js
var controller = {
    onStartAppFromOther(startingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
      console.log('onStartAppFromOther', startingWindowTarget);
	}
}
```

### onAppTransition

onAppTransition(fromWindowTarget: WindowAnimationTarget, toWindowTarget: WindowAnimationTarget,finishCallback: WindowAnimationFinishedCallback): void

Called during application transition.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Type                           | Mandatory| Description            |
| -------------------- | ------------------------------- | ---- | ---------------- |
| fromWindowTarget | [WindowAnimationTarget](#windowanimationtarget)           | Yes  | Window that displays the animation before the transition.|
| toWindowTarget       | [WindowAnimationTarget](#windowanimationtarget) | Yes  | Window that displays the animation after the transition.|
| finishCallback | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | Yes  | Callback invoked when the animation is finished.|

**Example**

```js
var controller = {
	onAppTransition(fromWindowTarget: WindowAnimationTarget, toWindowTarget: WindowAnimationTarget,
	  finishCallback: WindowAnimationFinishedCallback): void {
		console.log('onAppTransition', fromWindowTarget);
	}
}
```

### onMinimizeWindow

onMinimizeWindow(minimizingWindowTarget: WindowAnimationTarget,finishCallback: WindowAnimationFinishedCallback): void

Called when a window is minimized.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Type                           | Mandatory| Description            |
| -------------------- | ------------------------------- | ---- | ---------------- |
| minimizingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)           | Yes  | Target window to display the animation.   |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | Yes  | Callback invoked when the animation is finished.|

**Example**

```js
var controller = {
    onMinimizeWindow(minimizingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
      console.log('onMinimizeWindow', minimizingWindowTarget);
	}
}
```

### onCloseWindow

onCloseWindow(closingWindowTarget: WindowAnimationTarget,finishCallback: WindowAnimationFinishedCallback): void

Called when a window is closed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Type                           | Mandatory| Description            |
| -------------------- | ------------------------------- | ---- | ---------------- |
| closingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)           | Yes  | Target window to display the animation.   |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | Yes  | Callback invoked when the animation is finished.|

**Example**

```js
var controller = {
    onCloseWindow(closingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
      console.log('onCloseWindow', closingWindowTarget);
	}
}
```

### onScreenUnlock

onScreenUnlock(finishCallback: [WindowAnimationFinishedCallback](#windowanimationfinishedcallback)): void

Called when the screen is unlocked.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name        | Type                                                        | Mandatory| Description              |
| -------------- | ------------------------------------------------------------ | ---- | ------------------ |
| finishCallback | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | Yes  | Callback invoked when the animation is finished.|

**Example**

```js
var controller = {
    onScreenUnlock(finishCallback: WindowAnimationFinishedCallback): void {
      console.log('onScreenUnlock'.);
	}
}
```

## WindowAnimationFinishedCallback
Implements a callback that is invoked when the animation is finished.

### onAnimationFinish

onAnimationFinish():void

Called when the animation is finished.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Example**

```js
var controller = {
    onCloseWindow(closingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
      finishCallback.onAnimationFinish();
	}
}
```

## WindowAnimationTarget
Defines a window to display animation.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name     | Type    | Description|
| ------- | ------ | ----------------------- |
| bundleName  | string | Bundle name corresponding to the target window.|
| abilityName | string | Ability name corresponding to the target window.|
| windowBounds | [RRect](#rrect) | Actual size of the target window.|

## RRect
Describes a rounded rectangle.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name     | Type    | Description|
| ------- | ------ | ----------------------- |
| left  | number | Horizontal coordinate of the upper left corner of the target window relative to the screen.|
| top | number | Vertical coordinate of the upper left corner of the target window relative to the screen.|
| width | number | Width of the target window.|
| height | number | Height of the target window.|
| radius | number | Radius of the rounded corner of the target window.|
