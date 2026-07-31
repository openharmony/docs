# Frame Animation (ohos.animator)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=fd87a3fabd6b3d582616cc6b10933b62b2152e9f translatedAt=2026-07-29T12:41:35.624Z pushedAt=2026-07-30T01:12:51.805Z -->

The frame animation allows you to adjust your animation properties on each frame, thanks to its per-frame callback. By leveraging the **onFrame** callback of [AnimatorResult](../reference/apis-arkui/js-apis-animator.md#animatorresult), you can dynamically set property values on each frame, creating smooth and natural animations. For details about the frame animation APIs, see [@ohos.animator (Animator)](../reference/apis-arkui/js-apis-animator.md).

Compared with the property animation, the frame animation offers the benefits of real-time visibility into the animation process and allows you to modify UI values on the fly. In addition, it provides high responsiveness to events and can be paused as needed. However, it is worth noting that the frame animation may not be as performant as the property animation. Therefore, where the property animation meets the requirements, you are advised to use the property animation APIs. For details, see [Implementing Property Animation](./arkts-attribute-animation-apis.md). The table below provides a comparison between the property animation and frame animation.

| Name| Implementation| Event Response| Pausable| Performance|
| -------- | -------- | -------- | -------- |-------- |
| Frame animation (ohos.animator)| Allows real-time modification and updating of UI properties on each frame.| Responds in real time| Yes| Relatively lower|
| Property animation| Calculates the final state of the animation, with the UI reflecting only the end state, not the intermediate rendering values.| Responds to the end state| No| Generally higher|

The following figures illustrate the difference: The frame animation offers real-time responsiveness, whereas the property animation reacts to the final state of the animation.

![Alt text](figures/ohos.animator.gif)

![Alt text](figures/animation.gif)

## Using Frame Animation to Implement Animation Effects

To create a simple animator and print the current interpolation value in each frame callback:

1. Import dependencies.

   <!-- @[animator_import_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/animator/template4/AnimatorPage.ets) -->

   ``` TypeScript
   import { AnimatorOptions, AnimatorResult } from '@kit.ArkUI';
   ```

2. Create an animator object.

   <!-- @[animator_options_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/animator/template4/AnimatorPage.ets) -->

   ``` TypeScript
   // Initial options for creating an animator object
   let options: AnimatorOptions = {
     duration: 1500,
     easing: 'friction',
     delay: 0,
     fill: 'forwards',
     direction: 'normal',
     iterations: 2,
     // Initial frame value used for interpolation in the onFrame callback
     begin: 200.0,
     // End frame value used for interpolation in the onFrame callback
     end: 400.0
   };
   let result: AnimatorResult | undefined = this.getUIContext().createAnimator(options);
   // Set up a callback for when a frame is received, so that the onFrame callback is called for every frame throughout the animation playback process.
   result.onFrame = (value: number) => {
     hilog.info(DOMAIN, TAG, 'current value is :' + value);
   
   }
   ```

3. Play the animation.

   <!-- @[animator_play_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/animator/template4/AnimatorPage.ets) -->

   ``` TypeScript
   // Play the animation.
   result.play();
   ```

4. After the animation has finished executing, manually release the **AnimatorResult** object.

   <!-- @[animator_result_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/animator/template4/AnimatorPage.ets) -->

   ``` TypeScript
   // Release the animation object.
   result = undefined;
   ```

## Using Frame Animation to Implement a Ball's Parabolic Motion

1. Import dependencies.

   <!-- @[animator_template4_import_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/animator/template4/Index.ets) -->

   ``` TypeScript
   import { AnimatorOptions, AnimatorResult } from '@kit.ArkUI';
   ```

2. Define the component to be animated.

   <!-- @[animator_template4_button_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/animator/template4/Index.ets) -->

   ``` TypeScript
   Button()
     .width(60)
     .height(60)
     .translate({ x: this.translateX, y: this.translateY })
   ```

3. Create an **AnimatorResult** Object in **onPageShow**.

   <!-- @[animator_template4_show_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/animator/template4/Index.ets) -->

   ``` TypeScript
   onPageShow(): void {
     // Create an animatorResult object.
     this.animatorResult = this.getUIContext().createAnimator(this.animatorOption);
     this.animatorResult.onFrame = (progress: number) => {
       this.translateX = progress;
       if (progress > this.topWidth && this.translateY < this.bottomHeight) {
         this.translateY = Math.pow(progress - this.topWidth, 2) * this.g;
       }
     }
     // Execute the method when the animation is canceled.
     this.animatorResult.onCancel = () => {
       // Replace $r('app.string.cancel') with the actual resource file. In this example, the value in the resource file is "Canceled."
       this.animatorStatus = $r('app.string.cancel');
     }
     // Execute the method when the animation is complete.
     this.animatorResult.onFinish = () => {
       // Replace $r('app.string.complete') with the actual resource file. In this example, the value in the resource file is "Finished."
       this.animatorStatus = $r('app.string.complete');
     }
     // Execute the method when the animation is played repeatedly.
     this.animatorResult.onRepeat = () => {
       // The value in the 'repeat' resource file is 'Animation repeating.'
       hilog.info(DOMAIN, TAG, this.manager.getStringByNameSync('repeat'));
     }
   }
   ```

4. Define buttons for playing, resetting, and pausing animations.

   <!-- @[animator_template4_buttons_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/animator/template4/Index.ets) -->

   ``` TypeScript
   // Replace $r('app.string.play') with the actual resource file. In this example, the value in the resource file is "Play."
   Button($r('app.string.play')).onClick(() => {
     this.animatorResult?.play();
     // Replace $r('app.string.playing') with the actual resource file. In this example, the value in the resource file is "Playing."
     this.animatorStatus = $r('app.string.playing');
   }).width(80).height(35)
   // Replace $r('app.string.reset') with the actual resource file. In this example, the value in the resource file is "Reset."
   Button($r('app.string.reset')).onClick(() => {
     this.translateX = 0;
     this.translateY = 0;
   }).width(80).height(35)
   // Replace $r('app.string.pause') with the actual resource file. In this example, the value in the resource file is "Pause."
   Button($r('app.string.pause')).onClick(() => {
     this.animatorResult?.pause();
     // Replace $r('app.string.pause') with the actual resource file. In this example, the value in the resource file is "Pause."
     this.animatorStatus = $r('app.string.pause');
   }).width(80).height(35)
   ```

5. Release animation objects in the page hide or destroy lifecycle to avoid memory leaks.

   <!-- @[animator_template4_hide_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/animator/template4/Index.ets) -->

   ``` TypeScript
   onPageHide(): void {
     this.animatorResult = undefined;
   }
   ```

A complete example is as follows: 

<!-- @[animator_template3_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/animator/template3/Index.ets) -->

``` TypeScript
import { AnimatorOptions, AnimatorResult } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;
const TAG: string = '[AnimatorTest]';

@Entry
@Component
struct Index {
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  private manager = this.context.resourceManager;
  @State animatorResult: AnimatorResult | undefined = undefined;
  // The value in the 'create' resource file is 'Create.'
  @State animatorStatus: string = 'create';
  begin: number = 0;
  end: number = 300;
  topWidth: number = 150;
  bottomHeight: number = 100;
  // Acceleration coefficient for the free‑fall motion.
  g: number = 0.18;
  animatorOption: AnimatorOptions = {
    duration: 4000,
    delay: 0,
    easing: 'linear',
    iterations: 1,
    fill: "forwards",
    direction: 'normal',
    begin: this.begin,
    end: this.end
  };
  @State translateX: number = 0;
  @State translateY: number = 0;

  onPageShow(): void {
    this.animatorResult = this.getUIContext().createAnimator(this.animatorOption);
    this.animatorResult.onFrame = (progress: number) => {
      this.translateX = progress;
      if (progress > this.topWidth && this.translateY < this.bottomHeight) {
        this.translateY = Math.pow(progress - this.topWidth, 2) * this.g;
      }
    }
    this.animatorResult.onCancel = () => {
      // The value in the 'cancel' resource file is 'Canceled.'
      this.animatorStatus = 'cancel';
    }
    this.animatorResult.onFinish = () => {
      // The value in the 'complete' resource file is 'Finished.'
      this.animatorStatus = 'complete';
    }
    this.animatorResult.onRepeat = () => {
      // The value in the 'repeat' resource file is 'Animation repeating.'
      hilog.info(DOMAIN, TAG, this.manager.getStringByNameSync('repeat'));
    }
  }

  onPageHide(): void {
    this.animatorResult = undefined;
  }

  build() {
    Column() {
      Column({ space: 30 }) {
        // Replace $r('app.string.play') with the actual resource file. In this example, the value in the resource file is "Play."
        Button($r('app.string.play')).onClick(() => {
          this.animatorResult?.play();
          // The value in the 'playing' resource file is 'Playing.'
          this.animatorStatus = 'playing';
        }).width(80).height(35)
        // Replace $r('app.string.reset') with the actual resource file. In this example, the value in the resource file is "Reset."
        Button($r('app.string.reset')).onClick(() => {
          this.translateX = 0;
          this.translateY = 0;
        }).width(80).height(35)
        // Replace $r('app.string.pause') with the actual resource file. In this example, the value in the resource file is "Pause."
        Button($r('app.string.pause')).onClick(() => {
          this.animatorResult?.pause();
          // The value in the 'pause' resource file is 'Pause.'
          this.animatorStatus = 'pause';
        }).width(80).height(35)
      }.width('100%').height('25%')

      Stack() {
        Button()
          .width(60)
          .height(60)
          .translate({ x: this.translateX, y: this.translateY })
      }
      .width('100%')
      .height('45%')
      .align(Alignment.Start)
      // The value in the 'animatorStatus' resource file is 'Current animation state:'.
      Text(this.manager.getStringByNameSync('animatorStatus') + this.manager.getStringByNameSync(this.animatorStatus))
    }.width('100%').height('100%')
  }
}
```

![en-us_image_0000001599958466](figures/animatorSimple.gif)