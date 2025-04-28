# RemoteWindow (系统接口)

远程控制窗口组件，可以通过此组件控制应用窗口，提供启动退出过程中控件动画和应用窗口联动动画的能力。

>  **说明：**
>  
>  该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  本模块为系统接口。

## 子组件

不可以包含子组件。

## 接口

RemoteWindow(target: WindowAnimationTarget)

通过窗口动画对象创建组件。

**参数:**

| 参数名 | 参数类型 | 必填  | 参数描述 |
| -------- | -------- | --------------- | -------- |
| target | [WindowAnimationTarget](#windowanimationtarget) | 是   | 需要控制的动画窗口的描述。 |

## WindowAnimationTarget

目标窗口，用来远程控制实现动画。

| 参数      | 类型     | 描述 |
| ------- | ------ | ----------------------- |
| bundleName  | string | 动画窗口所对应的进程。|
| abilityName | string | 动画窗口所对应的Ability。|
| windowBounds | [RRect](#rrect) | 动画窗口实际大小。|
| missionId  | number | 任务ID。|

## RRect

圆角矩形。

| 参数      | 类型     | 描述 |
| ------- | ------ | ----------------------- |
| left  | number | 动画窗口左上角相对于屏幕横坐标。|
| top | number | 动画窗口左上角相对于屏幕纵坐标。|
| width | number | 动画窗口宽度大小。|
| height | number | 动画窗口高度大小。|
| radius | number | 动画窗口圆角大小。|

## 属性

支持[通用属性](ts-component-general-attributes.md)。

## 事件

支持[通用事件](ts-component-general-events.md)。

## 示例
RemoteWindow需要接收由[windowAnimationManager](../js-apis-windowAnimationManager-sys.md)设置的WindowAnimationController对象传入对应窗口WindowAnimationTarget对象，可以创建一个RemoteWindowExample.ets作为示例组件将RemoteWindow组件和传入的WindowAnimationTarget对象关联封装起来。
由于RemoteWindow只能用于系统应用程序Launcher中，可以将RemoteWindowExample组件放置于Launcher的EntryView.ets页面的build函数中，编译Launcher, 然后推送Launcher安装包到设备系统中运行。

```ts
// WindowAnimationControllerImpl.ets 文件
import { windowAnimationManager } from '@kit.ArkUI';

export default class WindowAnimationControllerImpl implements windowAnimationManager.WindowAnimationController {
  private callback: (target: windowAnimationManager.WindowAnimationTarget) => void = () => {}

  OnTargetUpdate(callback: (target: windowAnimationManager.WindowAnimationTarget) => void)
  {
    this.callback = callback;
  }

  private NotifyTargetUpdate(target: windowAnimationManager.WindowAnimationTarget)
  {
    this.callback(target);
  }

  onStartAppFromLauncher(startingWindowTarget: windowAnimationManager.WindowAnimationTarget,
                         finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback): void
  {
    console.log(`remote window animation onStartAppFromLauncher`);
    this.NotifyTargetUpdate(startingWindowTarget);
    finishedCallback.onAnimationFinish();
  }

  onStartAppFromRecent(startingWindowTarget: windowAnimationManager.WindowAnimationTarget,
                       finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
    console.log(`remote window animation onStartAppFromRecent`);
    this.NotifyTargetUpdate(startingWindowTarget);
    finishedCallback.onAnimationFinish();
  }

  onStartAppFromOther(startingWindowTarget: windowAnimationManager.WindowAnimationTarget,
                      finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
    console.log(`remote window animation onStartAppFromOther`);
    this.NotifyTargetUpdate(startingWindowTarget);
    finishedCallback.onAnimationFinish();
  }

  onAppTransition(fromWindowTarget: windowAnimationManager.WindowAnimationTarget,
                  toWindowTarget: windowAnimationManager.WindowAnimationTarget,
                  finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback): void{
    console.log(`remote window animation onAppTransition`);
    this.NotifyTargetUpdate(fromWindowTarget);
    finishedCallback.onAnimationFinish();
  }

  onMinimizeWindow(minimizingWindowTarget: windowAnimationManager.WindowAnimationTarget,
                   finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
    console.log(`remote window animation onMinimizeWindow`);
    this.NotifyTargetUpdate(minimizingWindowTarget);
    finishedCallback.onAnimationFinish();
  }

  onCloseWindow(closingWindowTarget: windowAnimationManager.WindowAnimationTarget,
                finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
    console.log(`remote window animation onCloseWindow`);
    this.NotifyTargetUpdate(closingWindowTarget);
    finishedCallback.onAnimationFinish();
  }

  onScreenUnlock(finishedCallback: windowAnimationManager.WindowAnimationFinishedCallback): void {
    console.log(`remote window animation onScreenUnlock`);
    finishedCallback.onAnimationFinish();
  }

  onWindowAnimationTargetsUpdate(fullScreenWindowTarget: windowAnimationManager.WindowAnimationTarget, 
                              floatingWindowTargets: Array<windowAnimationManager.WindowAnimationTarget>): void {
    console.log('onWindowAnimationTargetsUpdate, the fullScreenWindowTarget is: ' + fullScreenWindowTarget);
    console.log('onWindowAnimationTargetsUpdate, the floatingWindowTargets are: ' + floatingWindowTargets);
  }
}
```

```ts
// RemoteWindowExample.ets 文件
import { windowAnimationManager } from '@kit.ArkUI';
import WindowAnimationControllerImpl from './WindowAnimationControllerImpl';

@Entry
@Component
export default struct RemoteWindowExample {
  @State target:WindowAnimationTarget | undefined = undefined // 通过windowAnimationManager获取
  
  aboutToAppear(): void {
    let controller: WindowAnimationControllerImpl = new WindowAnimationControllerImpl();
    windowAnimationManager.setController(controller);
    controller.OnTargetUpdate((target: windowAnimationManager.WindowAnimationTarget) => {
      this.target = target;
    });
  }

  build() {
    Column() {
      if(this.target){
        RemoteWindow(this.target)
          .scale({ x: 0.5, y: 0.5 }) // 仅用于可见效果的演示目的，正常使用须 .scale({ x: 1, y: 1 })
          .position({ x: this.getUIContext().px2vp(this.target?.windowBounds.left), y: this.getUIContext().px2vp(this.target?.windowBounds.top) })
          .width(this.getUIContext().px2vp(this.target?.windowBounds.width))
          .height(this.getUIContext().px2vp(this.target?.windowBounds.height))
      }
     }
  }
}
```