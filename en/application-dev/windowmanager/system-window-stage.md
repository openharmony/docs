# System Window Development (Stage Model Only)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @waterwin-->
<!--Designer: @nyankomiya-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## Overview

In the stage model, system applications are allowed to create and manage system windows, including the volume bar, wallpaper, notification panel, status bar, and navigation bar. For details about the supported system window types, see [WindowType](../reference/apis-arkui/arkts-apis-window-e.md#windowtype7).

When a window is displayed, hidden, or switched, an animation is usually used to smooth the interaction process.

The animation is the default behavior for application windows. You do not need to set or modify the code.

However, you can customize an animation to be played during the display or hiding of a system window.

> **NOTE**
>
> This document involves the use of system APIs. You must use the full SDK for development. <!--Del-->For details, see [Guide to Switching to Full SDK](../faqs/full-sdk-switch-guide.md).<!--DelEnd-->


## Available APIs

For details about more APIs, see [Window](../reference/apis-arkui/js-apis-window-sys.md).

| Instance           | API                                                      | Description                                                        |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Window static method   | createWindow(config: Configuration, callback: AsyncCallback\<Window>): void | Creates a child window or system window.<br>**config**: parameters used for creating the window.    |
| Window            | resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | Changes the window size.                                          |
| Window            | moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | Moves this window.                                          |
| Window            | setUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void | Loads the content of a page, with its path in the current project specified, to this window.<br>**path**: path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project in the stage model.                                    |
| Window            | showWindow(callback: AsyncCallback\<void>): void             | Shows this window.                                              |
| Window            | on(type: 'touchOutside', callback: Callback&lt;void&gt;): void | Subscribes to touch events outside this window.                          |
| Window            | hide (callback: AsyncCallback\<void>): void                  | Hides this window. This is a system API.                            |
| Window            | destroyWindow(callback: AsyncCallback&lt;void&gt;): void     | Destroys this window.                                              |
| Window            | getTransitionController(): TransitionController              | Obtains the transition animation controller. This is a system API.                  |
| TransitionContext | completeTransition(isCompleted: boolean): void               | Completes the transition. This API can be called only after [animateTo()](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md) is executed. This is a system API.|
| Window            | showWithAnimation(callback: AsyncCallback\<void>): void      | Shows this window and plays an animation during the process. This is a system API.            |
| Window            | hideWithAnimation(callback: AsyncCallback\<void>): void      | Hides this window and plays an animation during the process. This is a system API.            |

## Developing a System Window

This section uses the volume bar as an example to describe how to develop a system window.

### How to Develop


1. Create a system window.

   In [ServiceExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-serviceExtensionContext-sys.md), call **window.createWindow** to create a system window of the volume bar type.

2. Set the properties of the system window.

   After the volume bar window is created, you can change its size and position, and set its properties such as the background color and brightness.

3. Load content to and show the system window.

   You can call **setUIContent** to load content to the volume bar window and **showWindow** to show the window.

4. Hide or destroy the system window.

   When the volume bar window is no longer needed, you can call **hide** or **destroyWindow** to hide or destroy it.

```ts
import { Want, ServiceExtensionAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ServiceExtensionAbility1 extends ServiceExtensionAbility {
  onCreate(want: Want) {
    // 1. Create a volume bar window.
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
      if (!windowClass) {
        console.error('windowClass is null');
        return;
      }
      // 2. Change the size and position of the volume bar window, or set its properties such as the background color and brightness.
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
      // 3.1 Load content to the volume bar window.
      windowClass.setUIContent("pages/page_volume", (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to load the content. Cause:' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in loading the content.');
        if (!windowClass) {
          console.error('windowClass is null');
          return;
        }
        // 3.2 Show the volume bar window.
        windowClass.showWindow((err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            console.error('Failed to show the window. Cause:' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in showing the window.');
        });
      });
      // 4. Hide or destroy the volume bar window.
      // Hide the volume bar window when a touch event outside the window is detected.
      windowClass.on('touchOutside', () => {
        console.info('touch outside');
        if (!windowClass) {
          console.error('windowClass is null');
          return;
        }
        windowClass.hide((err: BusinessError) => {
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

## Customizing an Animation to Be Played During the Display or Hiding of a System Window

You can determine whether to play an animation when a system window is showing or hiding.  

### How to Develop

1. Obtain the transition animation controller.

   Call **getTransitionController** to obtain the controller, which completes subsequent animation operations.

2. Configure the animation to be played.

   Call [animateTo()](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md) to configure the animation attributes.

3. Complete the transition.

   Use **completeTransition(true)** to set the completion status of the transition. If **false** is passed in, the transition is canceled.

4. Show or hide the system window and play the animation during the process.

   Call **showWithAnimation** to show the window and play the animation. Call **hideWithAnimation** to hide the window and play the animation.

```ts
// Import the showWithAnimation and hideWithAnimation methods to the .ts file.
import { window } from '@kit.ArkUI';

export class AnimationConfig {
  private animationForShownCallFunc_: ((context: window.TransitionContext) => void) | undefined = undefined;
  private animationForHiddenCallFunc_: ((context: window.TransitionContext) => void) | undefined = undefined;

  ShowWindowWithCustomAnimation(windowClass: window.Window, callback: (context: window.TransitionContext) => void) {
    if (!windowClass) {
      console.error('LOCAL-TEST windowClass is undefined');
      return false;
    }
    this.animationForShownCallFunc_ = callback;
    // Obtain the transition animation controller.
    let controller: window.TransitionController = windowClass.getTransitionController();
    controller.animationForShown = (context: window.TransitionContext)=> {
      this.animationForShownCallFunc_(context);
    };

    windowClass.showWithAnimation(()=>{
      console.info('LOCAL-TEST show with animation success');
    })
    return true;
  }

  HideWindowWithCustomAnimation(windowClass: window.Window, callback: (context: window.TransitionContext) => void) {
    if (!windowClass) {
      console.error('LOCAL-TEST window is undefined');
      return false;
    }
    this.animationForHiddenCallFunc_ = callback;
    // Obtain the transition animation controller.
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
// In the .ets file, implement the operation of creating the main window.
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
// In the xxx.ets file, implement the attribute setting of the child window.
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
          .fontWeight(FontWeight.Normal)
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
// In the .ets file, implement the operations of creating a child window and displaying or hiding a window.
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
    let context = AppStorage.get<common.UIAbilityContext>("currentContext");
    console.log('LOCAL-TEST try to CreateTransferSubWindow');
    let windowConfig:window.Configuration = {
      name : "systemTypeWindow",
      windowType : window.WindowType.TYPE_FLOAT,
      ctx : context,
    };
    let promise = window.createWindow(windowConfig);
    promise.then(async(subWin: window.Window) => {
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
    animationConfig.ShowWindowWithCustomAnimation(systemTypeWindow, (context:window.TransitionContext) => {
      console.info('LOCAL-TEST start show window animation');
      let toWindow = context.toWindow;
      this.getUIContext()?.animateTo({
        duration: 200, // Animation duration
        tempo: 0.5, // Playback speed.
        curve: Curve.EaseInOut, // Animation curve.
        delay: 0, // Animation delay.
        iterations: 1, // Number of playback times.
        playMode: PlayMode.Normal // Animation playback mode.
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
          toWindow?.translate(obj); // Set the transition animation.
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
    animationConfig.HideWindowWithCustomAnimation(systemTypeWindow, (context:window.TransitionContext) => {
      console.info('LOCAL-TEST start hide window animation');
      let toWindow = context.toWindow;
      this.getUIContext()?.animateTo({
        duration: 200, // Animation duration
        tempo: 0.5, // Playback speed.
        curve: Curve.EaseInOut, // Animation curve.
        delay: 0, // Animation delay.
        iterations: 1, // Number of playback times.
        playMode: PlayMode.Normal // Animation playback mode.
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
          toWindow?.translate(obj); // Set the transition animation.
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
