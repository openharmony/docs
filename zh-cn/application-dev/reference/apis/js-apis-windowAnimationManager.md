# 窗口动画管理
窗口动画管理器，可以监听应用启动退出时应用的动画窗口，提供启动退出过程中控件动画和应用窗口联动动画能力。

>  **说明：**
>  该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  本模块接口为系统接口。

## 导入模块

```js
import windowAnimationManager from '@ohos.animation.windowAnimationManager'
```

## windowAnimationManager.setController

setController(controller: WindowAnimationController): void

设置窗口动画控制器。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| controller | [WindowAnimationController](#windowanimationcontroller) | 是 | 窗口动画的控制器。|

**示例：**

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

## windowAnimationManager.minimizeWindowWithAnimation

minimizeWindowWithAnimation(windowTarget: WindowAnimationTarget, callback: AsyncCallback&lt;WindowAnimationFinishedCallback&gt;): void

最小化动画目标窗口，并返回动画完成的回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowTarget | [WindowAnimationTarget](#windowanimationtarget) | 是 | 动画目标窗口。|
| callback | AsyncCallback&lt;[WindowAnimationFinishedCallback](#windowanimationfinishedcallback)&gt; | 是 | 动画完成后的回调。|

**示例：**

```js
var target: WindowAnimationTarget = undefined;
var controller = {
    onWindowAnimationTargetsUpdate(fullScreenWindowTarget: WindowAnimationTarget, floatingWindowTargets: Array<WindowAnimationTarget>): void {
      target = fullScreenWindowTarget;
	},
}

windowAnimationManager.setController(controller)

var finishedCallback = null;
windowAnimationManager.minimizeWindowWithAnimation(target, (err, data) => {
    if (err.code) {
        console.error('Failed to minimize the window target. Cause: ' + JSON.stringify(err));
        return;
    }

    finishedCallback = data;
});

finishedCallback.onAnimationFinish();
```

## windowAnimationManager.minimizeWindowWithAnimation

minimizeWindowWithAnimation(windowTarget: WindowAnimationTarget): Promise&lt;WindowAnimationFinishedCallback&gt;

最小化动画目标窗口，并返回动画完成的回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowTarget | [WindowAnimationTarget](#windowanimationtarget) | 是 | 动画目标窗口。|

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[WindowAnimationFinishedCallback](#windowanimationfinishedcallback)&gt; | Promise对象，返回动画完成的回调。 |


**示例：**

```js
var target: WindowAnimationTarget = undefined;
var controller = {
    onWindowAnimationTargetsUpdate(fullScreenWindowTarget: WindowAnimationTarget, floatingWindowTargets: Array<WindowAnimationTarget>): void {
      target = fullScreenWindowTarget;
	},
}

windowAnimationManager.setController(controller)

let promise = windowAnimationManager.minimizeWindowWithAnimation(target);
promise.then((data) => {
    data.onAnimationFinish();
}).catch((err)=>{
    console.error('Failed to minimize the window target. Cause: ' + JSON.stringify(err));
    return;
});
```

## WindowAnimationController

窗口动画控制器。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

### onStartAppFromLauncher

onStartAppFromLauncher(startingWindowTarget: WindowAnimationTarget,finishCallback: WindowAnimationFinishedCallback): void

从桌面启动应用时的回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数名               | 类型                                                         | 必填 | 说明               |
| -------------------- | ------------------------------------------------------------ | ---- | ------------------ |
| startingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)              | 是   | 动画目标窗口。     |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | 是   | 动画完成后的回调。 |

**示例：**

```js
var controller = {
    onStartAppFromLauncher(startingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
      console.log('onStartAppFromLauncher', startingWindowTarget);
	}
}
```

### onStartAppFromRecent

onStartAppFromRecent(startingWindowTarget: WindowAnimationTarget,finishCallback:WindowAnimationFinishedCallback): void

从最近任务列表启动应用时的回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数名               | 类型                                                         | 必填 | 说明               |
| -------------------- | ------------------------------------------------------------ | ---- | ------------------ |
| startingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)              | 是   | 动画目标窗口。     |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | 是   | 动画完成后的回调。 |

**示例：**

```js
var controller = {
    onStartAppFromRecent(startingWindowTarget: WindowAnimationTarget, finishCallback:     WindowAnimationFinishedCallback): void {
      console.log('onStartAppFromRecent', startingWindowTarget);
	}
}
```

### onStartAppFromOther

onStartAppFromOther(startingWindowTarget: WindowAnimationTarget,finishCallback: WindowAnimationFinishedCallback): void

从除了桌面和最近任务列表以外其他地方启动应用时的回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数名               | 类型                                                         | 必填 | 说明               |
| -------------------- | ------------------------------------------------------------ | ---- | ------------------ |
| startingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)              | 是   | 动画目标窗口。     |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | 是   | 动画完成后的回调。 |

**示例：**

```js
var controller = {
    onStartAppFromOther(startingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
      console.log('onStartAppFromOther', startingWindowTarget);
	}
}
```

### onAppTransition

onAppTransition(fromWindowTarget: WindowAnimationTarget, toWindowTarget: WindowAnimationTarget,finishCallback: WindowAnimationFinishedCallback): void

应用转场时的回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数名               | 类型                            | 必填 | 说明             |
| -------------------- | ------------------------------- | ---- | ---------------- |
| fromWindowTarget | [WindowAnimationTarget](#windowanimationtarget)           | 是   | 转场前的动画窗口。 |
| toWindowTarget       | [WindowAnimationTarget](#windowanimationtarget) | 是   | 转场后的动画窗口。 |
| finishCallback | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | 是   | 动画完成后的回调。 |

**示例：**

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

最小化窗口时的回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数名               | 类型                            | 必填 | 说明             |
| -------------------- | ------------------------------- | ---- | ---------------- |
| minimizingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)           | 是   | 动画目标窗口。    |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | 是   | 动画完成后的回调。 |

**示例：**

```js
var controller = {
    onMinimizeWindow(minimizingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
      console.log('onMinimizeWindow', minimizingWindowTarget);
	}
}
```

### onCloseWindow

onCloseWindow(closingWindowTarget: WindowAnimationTarget,finishCallback: WindowAnimationFinishedCallback): void

关闭窗口时的回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数名               | 类型                            | 必填 | 说明             |
| -------------------- | ------------------------------- | ---- | ---------------- |
| closingWindowTarget | [WindowAnimationTarget](#windowanimationtarget)           | 是   | 动画目标窗口。    |
| finishCallback       | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | 是   | 动画完成后的回调。 |

**示例：**

```js
var controller = {
    onCloseWindow(closingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
      console.log('onCloseWindow', closingWindowTarget);
	}
}
```

### onScreenUnlock

onScreenUnlock(finishCallback: [WindowAnimationFinishedCallback](#windowanimationfinishedcallback)): void

屏幕解锁时的回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数名         | 类型                                                         | 必填 | 说明               |
| -------------- | ------------------------------------------------------------ | ---- | ------------------ |
| finishCallback | [WindowAnimationFinishedCallback](#windowanimationfinishedcallback) | 是   | 动画完成后的回调。 |

**示例：**

```js
var controller = {
    onScreenUnlock(finishCallback: WindowAnimationFinishedCallback): void {
      console.log('onScreenUnlock'.);
	}
}
```

### onWindowAnimationTargetsUpdate

onWindowAnimationTargetsUpdate(fullScreenWindowTarget: WindowAnimationTarget, floatingWindowTargets: Array&lt;WindowAnimationTarget&gt;): void

动画目标窗口更新时的回调

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数名               | 类型                            | 必填 | 说明             |
| -------------------- | ------------------------------- | ---- | ---------------- |
| fullScreenWindowTarget | [WindowAnimationTarget](#windowanimationtarget) | 是   | 全屏状态的动画目标窗口。|
| floatingWindowTargets| Array&lt;[WindowAnimationTarget](#windowanimationtarget)&gt; | 是   | 悬浮状态的动画目标窗口 |

**示例：**

```js
var controller = {
    onWindowAnimationTargetsUpdate(fullScreenWindowTarget: WindowAnimationTarget, floatingWindowTargets: Array<WindowAnimationTarget>): void {
      console.log('onWindowAnimationTargetsUpdate'.);
    }
}

windowAnimationManager.setController(controller)
```

## WindowAnimationFinishedCallback
动画完成后的回调。

### onAnimationFinish

onAnimationFinish():void

结束本次动画。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**示例：**

```js
var controller = {
    onCloseWindow(closingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void {
      finishCallback.onAnimationFinish();
	}
}
```

## WindowAnimationTarget
动画目标窗口，用来实现动画。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数      | 类型     | 描述 |
| ------- | ------ | ----------------------- |
| bundleName  | string | 动画目标窗口所对应的包名。 |
| abilityName | string | 动画目标窗口所对应的Ability名称。 |
| windowBounds | [RRect](#rrect) | 动画目标窗口所对应的实际大小。 |
| missionId  | number | 任务ID。|

## RRect
圆角矩形。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数      | 类型     | 描述 |
| ------- | ------ | ----------------------- |
| left  | number | 动画目标窗口左上角相对于屏幕的横坐标。 |
| top | number | 动画目标窗口左上角相对于屏幕的纵坐标。 |
| width | number | 动画目标窗口的宽度大小。 |
| height | number | 动画目标窗口的高度大小。 |
| radius | number | 动画目标窗口的圆角大小。 |