# 管理系统窗口（仅Stage模型支持）

## 管理系统窗口概述

在`Stage`模型下， 允许系统应用创建和管理系统窗口，包括音量条、壁纸、通知栏、状态栏、导航栏等。具体支持的系统窗口类型见[API参考-WindowType](../reference/apis-arkui/js-apis-window.md#windowtype7)。

在窗口显示、隐藏及窗口间切换时，窗口模块通常会添加动画效果，以使各个交互过程更加连贯流畅。

在OpenHarmony中，应用窗口的动效为默认行为，不需要开发者进行设置或者修改。

相对于应用窗口，在显示系统窗口过程中，开发者可以自定义窗口的显示动画、隐藏动画。

> **说明：**
>
> 本文档涉及系统接口的使用，请使用full-SDK进行开发。<!--Del-->具体使用可见[full-SDK替换指南](../faqs/full-sdk-switch-guide.md)。<!--DelEnd-->


## 接口说明

更多API说明请参见[API参考](../reference/apis-arkui/js-apis-window-sys.md)。

| 实例名            | 接口名                                                       | 描述                                                         |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| window静态方法    | createWindow(config: Configuration, callback: AsyncCallback\<Window>): void | 创建子窗口或系统窗口。<br/>-`config`：创建窗口时的参数。     |
| Window            | resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | 改变当前窗口大小。                                           |
| Window            | moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | 移动当前窗口位置。                                           |
| Window            | setUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void | 根据当前工程中某个页面的路径为窗口加载具体的页面内容。<br>其中path为要加载到窗口中的页面内容的路径，在Stage模型下该路径需添加到工程的main_pages.json文件中。                                     |
| Window            | showWindow(callback: AsyncCallback\<void>): void             | 显示当前窗口。                                               |
| Window            | on(type: 'touchOutside', callback: Callback&lt;void&gt;): void | 开启本窗口区域外的点击事件的监听。                           |
| Window            | hide (callback: AsyncCallback\<void>): void                  | 隐藏当前窗口。此接口为系统接口。                             |
| Window            | destroyWindow(callback: AsyncCallback&lt;void&gt;): void     | 销毁当前窗口。                                               |
| Window            | getTransitionController(): TransitionController              | 获取窗口属性转换控制器。此接口为系统接口。                   |
| TransitionContext | completeTransition(isCompleted: boolean): void               | 设置属性转换的最终完成状态。该函数需要在动画函数[animateTo()](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md)执行后设置。此接口为系统接口。 |
| Window            | showWithAnimation(callback: AsyncCallback\<void>): void      | 显示当前窗口，过程中播放动画。此接口为系统接口。             |
| Window            | hideWithAnimation(callback: AsyncCallback\<void>): void      | 隐藏当前窗口，过程中播放动画。此接口为系统接口。             |

## 系统窗口的开发

本文以音量条窗口为例，介绍系统窗口的基本开发和管理步骤。

### 开发步骤


1. 创建系统窗口。

   在[ServiceExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-serviceExtensionContext-sys.md)下，使用`window.createWindow`接口创建音量条系统窗口。

2. 操作或设置系统窗口的属性。

   系统窗口创建成功后，可以改变其大小、位置等，还可以根据需要设置系统窗口的背景色、亮度等属性。

3. 加载显示系统窗口的具体内容。

   通过`setUIContent`和`showWindow`接口加载显示音量条窗口的具体内容。

4. 隐藏/销毁系统窗口。

   当不再需要音量条窗口时，可根据具体实现逻辑，使用`hide`接口或`destroyWindow`接口对其进行隐藏或销毁。

```ts
import { Want, ServiceExtensionAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ServiceExtensionAbility1 extends ServiceExtensionAbility {
  onCreate(want: Want) {
    // 1.创建音量条窗口。
    let windowClass: window.Window | null = null;
    let config: window.Configuration = {
      name: "volume", windowType: window.WindowType.TYPE_VOLUME_OVERLAY, ctx: this.context
    };
    window.createWindow(config, (err: BusinessError, data) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to create the volume window. Code:${err.code}, message:${err.message}`);
        return;
      }
      console.info('Succeeded in creating the volume window.')
      windowClass = data;
      // 2.创建音量条窗口成功之后，可以改变其大小、位置或设置背景色、亮度等属性。
      windowClass.moveWindowTo(300, 300, (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to move the window. Cause:' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in moving the window.');
      });
      windowClass.resize(500, 500, (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in changing the window size.');
      });
      // 3.为音量条窗口加载对应的目标页面。
      windowClass.setUIContent("pages/page_volume", (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to load the content. Cause:' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in loading the content.');
        // 3.显示音量条窗口。
        (windowClass as window.Window).showWindow((err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            console.error('Failed to show the window. Cause:' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in showing the window.');
        });
      });
      // 4.隐藏/销毁音量条窗口。当不再需要音量条时，可根据具体实现逻辑，对其进行隐藏或销毁。
      // 此处以监听音量条区域外的点击事件为例实现音量条窗口的隐藏。
      windowClass.on('touchOutside', () => {
        console.info('touch outside');
        (windowClass as window.Window).hide((err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in hiding the window.');
        });
      });
    });
  }
};
```

## 自定义系统窗口的显示与隐藏动画

在显示系统窗口过程中，开发者可以自定义窗口的显示动画。在隐藏系统窗口过程中，开发者可以自定义窗口的隐藏动画。本文以显示和隐藏动画为例介绍主要开发步骤。

### 开发步骤

1. 获取窗口属性转换控制器。

   通过`getTransitionController`接口获取控制器。后续的动画操作都由属性控制器来完成。

2. 配置窗口显示时的动画。

   通过动画函数[animateTo()](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md)配置具体的属性动画。

3. 设置属性转换完成。

   通过`completeTransition(true)`来设置属性转换的最终完成状态。如果传入false，则表示撤销本次转换。

4. 显示或隐藏当前窗口，过程中播放动画。

   调用`showWithAnimation`接口，来显示窗口并播放动画。调用`hideWithAnimation`接口，来隐藏窗口并播放动画。

```ts
// xxx.ts 实现使用ts文件引入showWithAnimation，hideWithAnimation方法
import { window } from '@kit.ArkUI';

export class AnimationConfig {
  private animationForShownCallFunc_: Function = undefined;
  private animationForHiddenCallFunc_: Function = undefined;

  ShowWindowWithCustomAnimation(windowClass: window.Window, callback) {
    if (!windowClass) {
      console.error('LOCAL-TEST windowClass is undefined');
      return false;
    }
    this.animationForShownCallFunc_ = callback;
    // 获取窗口属性转换控制器
    let controller: window.TransitionController = windowClass.getTransitionController();
    controller.animationForShown = (context: window.TransitionContext)=> {
      this.animationForShownCallFunc_(context);
    };

    windowClass.showWithAnimation(()=>{
      console.info('LOCAL-TEST show with animation success');
    })
    return true;
  }

  HideWindowWithCustomAnimation(windowClass: window.Window, callback) {
    if (!windowClass) {
      console.error('LOCAL-TEST window is undefined');
      return false;
    }
    this.animationForHiddenCallFunc_ = callback;
    // 获取窗口属性转换控制器
    let controller: window.TransitionController = windowClass.getTransitionController();
    controller.animationForHidden = (context : window.TransitionContext) => {
      this.animationForHiddenCallFunc_(context);
    };

    windowClass.hideWithAnimation(()=>{
      console.info('Hide with animation success');
    })
    return true;
  }
}
```

```ts
// xxx.ets 实现主窗口创建相关操作
import { window } from '@kit.ArkUI';
import { UIAbility, Want, AbilityConstant, common } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit'

export default class EntryAbility extends UIAbility {
  onCreate(want: Want,launchParam:AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability Destroy');
  }

  onWindowStageCreate(windowStage:window.WindowStage): void{
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/transferControllerPage',(err, data)=>{
      if(err.code){
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause:%{public}s', JSON.stringify(err)??'');
        return ;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data:%{public}s', JSON.stringify(data)??'');

    });

    AppStorage.setOrCreate<common.UIAbilityContext>("currentContext",this.context);
  }

  onWindowStageDestroy(): void{
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void{
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void{
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
  }
};
```

```ts
// xxx.ets 实现子窗口的属性设置
import { window, router } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct transferCtrlSubWindow {
  @State message: string = 'transferCtrlSubWindow'

  build() {
    Column() {
      Text("close")
        .fontSize(24)
        .fontWeight(FontWeight.Normal)
        .margin({ left: 10, top: 10 })
      Button() {
        Text("close")
          .fontSize(24)
          .fontSize(FontWeight.Normal)
      }.width(220).height(68)
      .margin({ left: 10, top: 10 })
      .onClick(() => {
        let subWin = AppStorage.get<window.Window>("TransferSubWindow");
        subWin?.destroyWindow();
        AppStorage.setOrCreate<window.Window>("TransferSubWindow", undefined);
      })
    }.height('100%').width('100%').backgroundColor('#ff556243').shadow({radius: 30,color: '#ff555555',offsetX: 15,offsetY: 15})
  }
}
```

```ts
// xxx.ets 实现子窗口的创建以及显示、隐藏窗口时的动效操作
import { window, router } from '@kit.ArkUI';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AnimationConfig } from '../entryability/AnimationConfig';

@Entry
@Component
struct Index {
  @State message: string = 'transferControllerWindow';

  private animationConfig_?:AnimationConfig = undefined;
  private subWindow_?:window.Window = undefined;

  aboutToAppear(){
    if(!this.animationConfig_){
      this.animationConfig_ = new AnimationConfig();
    }
  }

  private CreateTransferSubWindow(){
    if(this.subWindow_){
      this.subWindow_ = AppStorage.get<window.Window>("TransferSubWindow");
      if(!this.subWindow_){
        this.subWindow_ = undefined;
      }
    }
    let context = AppStorage.get<common.UIAbilityContext>("currentContext");
    console.log('LOCAL-TEST try to CreateTransferSubWindow');
    let windowConfig:window.Configuration = {
      name : "systemTypeWindow",
      windowType : window.WindowType.TYPE_FLOAT,
      ctx : context,
    };
    let promise = window?.createWindow(windowConfig);
    promise?.then(async(subWin) => {
      this.subWindow_ = subWin;
      AppStorage.setOrCreate<window.Window>("systemTypeWindow", subWin);
      await subWin.setUIContent("pages/transferCtrlSubWindow",()=>{});
      await subWin.moveWindowTo(100,100);
      await subWin.resize(200,200);
    }).catch((err:Error)=>{
      console.log('LOCAL-TEST createSubWindow err:' + JSON.stringify(err));
    })
  }
  private ShowSUBWindow(){
    if(!this.subWindow_){
      console.log('LOCAL-TEST this.subWindow_is null');
      return ;
    }
    let animationConfig = new AnimationConfig();
    let systemTypeWindow = window.findWindow("systemTypeWindow");
    console.log("LOCAL-TEST try to ShowWindowWithCustomAnimation");
    animationConfig.ShowWindowWithCustomAnimation(systemTypeWindow,(context:window.TransitionContext)=>{
      console.info('LOCAL-TEST start show window animation');
      let toWindow = context.toWindow;
      animateTo({
        duration: 200, // 动画时长
        tempo: 0.5, // 播放速率
        curve: Curve.EaseInOut, // 动画曲线
        delay: 0, // 动画延迟
        iterations: 1, // 播放次数
        playMode: PlayMode.Normal, // 动画模式
        onFinish: () => {
          console.info('LOCAL-TEST onFinish in show animation');
          context.completeTransition(true);
        }
      },() => {
        let obj: window.TranslateOptions = {
          x: 100.0,
          y: 0.0,
          z: 0.0
        };
        try {
          toWindow.translate(obj); // 设置动画过程中的属性转换
        }catch(exception){
          console.error('Failed to translate. Cause: ' + JSON.stringify(exception));
        }
      });
      console.info('LOCAL-TEST complete transition end');
    });
  }

  private HideSUBWindow(){
    if(!this.subWindow_){
      console.log('LOCAL-TEST this.subWindow_is null');
      return ;
    }
    let animationConfig = new AnimationConfig();
    let systemTypeWindow = window.findWindow("systemTypeWindow");
    console.log("LOCAL-TEST try to HideWindowWithCustomAnimation");
    animationConfig.HideWindowWithCustomAnimation(systemTypeWindow,(context:window.TransitionContext)=>{
      console.info('LOCAL-TEST start hide window animation');
      let toWindow = context.toWindow;
      animateTo({
        duration: 200, // 动画时长
        tempo: 0.5, // 播放速率
        curve: Curve.EaseInOut, // 动画曲线
        delay: 0, // 动画延迟
        iterations: 1, // 播放次数
        playMode: PlayMode.Normal, // 动画模式
        onFinish: () => {
          console.info('LOCAL-TEST onFinish in hide animation');
          context.completeTransition(true);
        }
      },() => {
        let obj: window.TranslateOptions = {
          x: 500.0,
          y: 0.0,
          z: 0.0
        };
        try {
          toWindow.translate(obj); // 设置动画过程中的属性转换
        }catch(exception){
          console.error('Failed to translate. Cause: ' + JSON.stringify(exception));
        }
      });
      console.info('LOCAL-TEST complete transition end');
    });
  }

  build() {
    Column() {
      Text(this.message)
        .fontSize(24)
        .fontWeight(FontWeight.Normal)
        .margin({left: 10, top: 10})

      Button(){
        Text("CreateSub")
          .fontSize(24)
          .fontWeight(FontWeight.Normal)
      }.width(220).height(68)
      .margin({left: 10, top: 10})
      .onClick(() => {
        this.CreateTransferSubWindow();
      })

      Button(){
        Text("Show")
          .fontSize(24)
          .fontWeight(FontWeight.Normal)
      }.width(220).height(68)
      .margin({left: 10, top: 10})
      .onClick(() => {
        this.ShowSUBWindow();
      })

      Button(){
        Text("Hide")
          .fontSize(24)
          .fontWeight(FontWeight.Normal)
      }.width(220).height(68)
      .margin({left: 10, top: 10})
      .onClick(() => {
        this.HideSUBWindow();
      })
    }.width('100%').height('100%')
  }
}
```