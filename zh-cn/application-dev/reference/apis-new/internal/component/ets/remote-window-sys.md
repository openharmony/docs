# remote_window    
远程控制窗口组件，可以通过此组件控制应用窗口，提供启动退出过程中控件动画和应用窗口联动动画的能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## RRect  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| left | number | false | true |  |  
| top | number | false | true |  |  
| width | number | false | true |  |  
| height | number | false | true |  |  
| radius | number | false | true |  |  
    
## WindowAnimationTarget  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | true | true |  |  
| abilityName | string | true | true |  |  
| windowBounds | RRect | true | true |  |  
| missionId | number | true | true |  |  
    
## 接口  
  
  
    
 **调用形式**     
    
- RemoteWindow(target: WindowAnimationTarget)    
起始版本： 9    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| target | WindowAnimationTarget | true |  |  
    
 **示例代码1：**   
RemoteWindow需要接收由[windowAnimationManager](../apis/js-apis-windowAnimationManager.md)设置的WindowAnimationController对象传入对应窗口WindowAnimationTarget对象，可以创建一个RemoteWindowExample.ets作为示例组件将RemoteWindow组件和传入的WindowAnimationTarget对象关联封装起来。由于RemoteWindow只能用于系统应用程序Launcher中，可以将RemoteWindowExample组件放置于Launcher的EntryView.ets页面的build函数中，编译Launcher, 然后推送Launcher安装包到设备系统中运行。  
```ts    
// WindowAnimationControllerImpl.ets 文件  
import windowAnimationManager from '@ohos.animation.windowAnimationManager';  
  
export default class WindowAnimationControllerImpl implements windowAnimationManager.WindowAnimationController {  
  onStartAppFromLauncher(startingWindowTarget: windowAnimationManager.WindowAnimationTarget,  
                         finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback): void  
  {  
    console.log(`remote window animaion onStartAppFromLauncher`);  
    finishedCallback.onAnimationFinish();  
  }  
  
  onStartAppFromRecent(startingWindowTarget: windowAnimationManager.WindowAnimationTarget,  
                       finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {  
    console.log(`remote window animaion onStartAppFromRecent`);  
    finishedCallback.onAnimationFinish();  
  }  
  
  onStartAppFromOther(startingWindowTarget: windowAnimationManager.WindowAnimationTarget,  
                      finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {  
    console.log(`remote window animaion onStartAppFromOther`);  
    finishedCallback.onAnimationFinish();  
  }  
  
  onAppTransition(fromWindowTarget: windowAnimationManager.WindowAnimationTarget,  
                  toWindowTarget: windowAnimationManager.WindowAnimationTarget,  
                  finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback): void{  
    console.log(`remote window animaion onAppTransition`);  
    finishedCallback.onAnimationFinish();  
  }  
  
  onMinimizeWindow(minimizingWindowTarget: windowAnimationManager.WindowAnimationTarget,  
                   finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {  
    console.log(`remote window animaion onMinimizeWindow`);  
    finishedCallback.onAnimationFinish();  
  }  
  
  onCloseWindow(closingWindowTarget: windowAnimationManager.WindowAnimationTarget,  
                finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {  
    console.log(`remote window animaion onCloseWindow`);  
    finishedCallback.onAnimationFinish();  
  }  
  
  onScreenUnlock(finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {  
    console.log(`remote window animaion onScreenUnlock`);  
    finishedCallback.onAnimationFinish();  
  }  
  
  onWindowAnimationTargetsUpdate(fullScreenWindowTarget: windowAnimationManager.WindowAnimationTarget,   
                              floatingWindowTargets: Array<windowAnimationManager.WindowAnimationTarget>): void {  
    console.log('onWindowAnimationTargetsUpdate, the fullScreenWindowTarget is: ' + fullScreenWindowTarget);  
    console.log('onWindowAnimationTargetsUpdate, the floatingWindowTargets are: ' + floatingWindowTargets);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
```ts    
// RemoteWindowExample.ets 文件  
import windowAnimationManager from '@ohos.animation.windowAnimationManager';  
import WindowAnimationControllerImpl from './WindowAnimationControllerImpl';  
  
@Entry  
@Component  
export default struct RemoteWindowExample {  
  @State target:WindowAnimationTarget | undefined = undefined // 通过windowAnimationManager获取  
    
  aboutToAppear(): void {  
    let controller: WindowAnimationControllerImpl = new WindowAnimationControllerImpl();  
    windowAnimationManager.setController(controller);  
  
    controller.onStartAppFromLauncher = (startingWindowTarget: WindowAnimationTarget,  
                                         finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback) => {  
      console.log(`RemoteWindowExample: remote window animaion onStartAppFromLauncher`);  
      this.target = startingWindowTarget;  
      finishedCallback.onAnimationFinish();  
    }  
  
    controller.onStartAppFromRecent = (startingWindowTarget: WindowAnimationTarget,  
                                       finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback) => {  
      console.log(`RemoteWindowExample: remote window animaion onStartAppFromRecent`);  
      this.target = startingWindowTarget;  
      finishedCallback.onAnimationFinish();  
    }  
  
    controller.onStartAppFromOther = (startingWindowTarget: WindowAnimationTarget,  
                                      finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback) => {  
      console.log(`RemoteWindowExample: remote window animaion onStartAppFromOther`);  
      this.target = startingWindowTarget;  
      finishedCallback.onAnimationFinish();  
    }  
  
    controller.onAppTransition = (fromWindowTarget: WindowAnimationTarget, toWindowTarget: WindowAnimationTarget,  
                                  finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback) => {  
      console.log(`RemoteWindowExample: remote window animaion onAppTransition`);  
      this.target = toWindowTarget;  
      finishedCallback.onAnimationFinish();  
    }  
  
    controller.onMinimizeWindow = (minimizingWindowTarget: WindowAnimationTarget,  
                                   finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback) => {  
      console.log(`RemoteWindowExample: remote window animaion onMinimizeWindow`);  
      this.target = minimizingWindowTarget;  
      finishedCallback.onAnimationFinish();  
    }  
  
    controller.onCloseWindow = (closingWindowTarget: WindowAnimationTarget,  
                                finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback) => {  
      console.log(`RemoteWindowExample: remote window animaion onCloseWindow`);  
      this.target = closingWindowTarget;  
      finishedCallback.onAnimationFinish();  
    }  
  }  
  
  build() {  
    Column() {  
      if(this.target){  
        RemoteWindow(this.target)  
          .scale({ x: 0.5, y: 0.5 }) // 仅用于可见效果的演示目的，正常使用须 .scale({ x: 1, y: 1 })  
          .position({ x: px2vp(this.target?.windowBounds.left), y: px2vp(this.target?.windowBounds.top) })  
          .width(px2vp(this.target?.windowBounds.width))  
          .height(px2vp(this.target?.windowBounds.height))  
      }  
     }  
  }  
}  
    
```    
  
