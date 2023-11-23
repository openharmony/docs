# @ohos.animation.windowAnimationManager    
窗口动画管理器，可以监听应用启动退出时应用的动画窗口，提供启动退出过程中控件动画和应用窗口联动动画能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import windowAnimationManager from '@ohos.animation.windowAnimationManager'    
```  
    
## setController    
设置窗口动画控制器。窗口动画控制器的说明请参考[WindowAnimationController](#windowanimationcontroller)。  
 **调用形式：**     
- setController(controller: WindowAnimationController): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| controller | WindowAnimationController | true | 窗口动画的控制器。 |  
    
 **示例代码：**   
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
  
    
## minimizeWindowWithAnimation    
最小化动画目标窗口，并返回动画完成的回调。使用callback异步回调  
 **调用形式：**     
    
- minimizeWindowWithAnimation(windowTarget: WindowAnimationTarget,     callback: AsyncCallback\<WindowAnimationFinishedCallback>): void    
起始版本： 9    
- minimizeWindowWithAnimation(windowTarget: WindowAnimationTarget): Promise\<WindowAnimationFinishedCallback>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| windowTarget | WindowAnimationTarget | true | 动画目标窗口。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当最小化动画目标窗口成功，err为undefined，data为获取到的WindowAnimationFinishedCallback；否则返回err.code为-1，data为undefined。 |  
| Promise<WindowAnimationFinishedCallback> | Promise对象，返回动画完成的回调。 |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import {BusinessError} from '@ohos.base';  
  
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
  
    // 在收到回调后，需要开始进行窗口动画，在窗口动画结束后，调用onAnimationFinish回调  
    finishedCallback.onAnimationFinish();  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import {BusinessError} from '@ohos.base';  
  
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
  
    
## RRect    
圆角矩形。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| left | number | false | true | 动画目标窗口左上角相对于屏幕的横坐标。 |  
| top | number | false | true | 动画目标窗口左上角相对于屏幕的纵坐标。 |  
| width | number | false | true | 动画目标窗口的宽度大小。 |  
| height | number | false | true | 动画目标窗口的高度大小。 |  
| radius | number | false | true | 动画目标窗口的圆角大小。 |  
    
## WindowAnimationTarget    
动画目标窗口，用来实现动画。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | true | true | 动画目标窗口所对应的包名。 |  
| abilityName | string | true | true | 动画目标窗口所对应的Ability名称。 |  
| windowBounds | RRect | true | true | 动画目标窗口所对应的实际大小。 |  
| missionId | number | true | true | 任务ID，多任务中用于与ability进行匹配。 |  
    
## WindowAnimationFinishedCallback    
动画完成后的回调。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### onAnimationFinish    
结束本次动画。  
 **调用形式：**     
- onAnimationFinish(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
## WindowAnimationController    
窗口动画控制器。在创建一个WindowAnimationController对象时，需要实现其中的所有回调函数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### onStartAppFromLauncher  
 **调用形式：**     
- onStartAppFromLauncher(startingWindowTarget: WindowAnimationTarget,       finishCallback: WindowAnimationFinishedCallback): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| startingWindowTarget | WindowAnimationTarget | true |  |  
| finishCallback | WindowAnimationFinishedCallback | true |  |  
    
 **示例代码：**   
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
  
    
### onStartAppFromRecent  
 **调用形式：**     
- onStartAppFromRecent(startingWindowTarget: WindowAnimationTarget,       finishCallback: WindowAnimationFinishedCallback): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| startingWindowTarget | WindowAnimationTarget | true |  |  
| finishCallback | WindowAnimationFinishedCallback | true |  |  
    
 **示例代码：**   
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
  
    
### onStartAppFromOther  
 **调用形式：**     
- onStartAppFromOther(startingWindowTarget: WindowAnimationTarget,       finishCallback: WindowAnimationFinishedCallback): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| startingWindowTarget | WindowAnimationTarget | true |  |  
| finishCallback | WindowAnimationFinishedCallback | true |  |  
    
 **示例代码：**   
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
  
    
### onAppTransition  
 **调用形式：**     
- onAppTransition(fromWindowTarget: WindowAnimationTarget, toWindowTarget: WindowAnimationTarget,       finishCallback: WindowAnimationFinishedCallback): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fromWindowTarget | WindowAnimationTarget | true |  |  
| toWindowTarget | WindowAnimationTarget | true |  |  
| finishCallback | WindowAnimationFinishedCallback | true |  |  
    
 **示例代码：**   
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
  
    
### onMinimizeWindow  
 **调用形式：**     
- onMinimizeWindow(minimizingWindowTarget: WindowAnimationTarget,       finishCallback: WindowAnimationFinishedCallback): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| minimizingWindowTarget | WindowAnimationTarget | true |  |  
| finishCallback | WindowAnimationFinishedCallback | true |  |  
    
 **示例代码：**   
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
  
    
### onCloseWindow    
关闭窗口时的回调。  
 **调用形式：**     
- onCloseWindow(closingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| closingWindowTarget | WindowAnimationTarget | true | 动画目标窗口。 |  
| finishCallback | WindowAnimationFinishedCallback | true | 动画完成后的回调。 |  
    
 **示例代码：**   
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
  
    
### onScreenUnlock    
屏幕解锁时的回调。  
 **调用形式：**     
- onScreenUnlock(finishCallback: WindowAnimationFinishedCallback): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| finishCallback | WindowAnimationFinishedCallback | true | 动画完成后的回调。 |  
    
 **示例代码：**   
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
  
    
### onWindowAnimationTargetsUpdate  
 **调用形式：**     
- onWindowAnimationTargetsUpdate(fullScreenWindowTarget: WindowAnimationTarget,       floatingWindowTargets: Array\<WindowAnimationTarget>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fullScreenWindowTarget | WindowAnimationTarget | true |  |  
| floatingWindowTargets | Array<WindowAnimationTarget> | true |  |  
    
 **示例代码：**   
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
  
    
 **示例代码：**   
```ts    
import windowAnimationManager from '@ohos.animation.windowAnimationManager'    
```    
  
