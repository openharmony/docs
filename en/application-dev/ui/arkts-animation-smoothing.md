# Animation Smoothing

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=5676df03a5c7f39e1f4c1a810694dac229a591ff translatedAt=2026-07-29T12:43:05.003Z pushedAt=2026-07-30T01:10:07.715Z -->

When running animations, the UI is also interacting with users in real time. It must respond immediately to changes in user behavior. For example, if the user swipes up to exit in the midst of an application launch process, the UI should immediately transit from the startup animation to the exit animation, rather than finishing the startup animation before exiting. For scenarios such as desktop page‑turning where an animation is triggered after the finger lifts from the screen following a dragging gesture, the initial velocity of the post‑lift animation should inherit the gesture velocity to avoid a sense of stutter caused by velocity discontinuity. For the preceding and similar scenarios, the system provides efficient APIs for smoothing between animations and between animations and gestures while minimizing development complexity.

Assume that there is a running animation for an animatable property. If the end value of the property changes due to an operation on the UI, you can create a new animation for it, by changing the property value in the [animateTo](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md) closure or by changing the input parameter value of the [animation](../reference/apis-arkui/arkui-ts/ts-animatorproperty.md) API. The system then automatically connects the previous animation with the new animation. You only need to focus on the implementation of the current single animation.

The following example demonstrates how clicking the **Click** button changes the scale property of the red square. When you click **Click** repeatedly, the target value of the **scale** property changes continuously, and the animation smoothly moves toward the new target value.

<!-- @[animation_template1_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/cohesion/template1/Index.ets) -->

``` TypeScript
import { curves } from '@kit.ArkUI';

class SetAnimationVariables {
  isAnimation: boolean = true

  set(): void {
    this.isAnimation = !this.isAnimation;
  }
}

@Entry
@Component
struct AnimationToAnimationDemo {
  // Step 1: Declare the related state variable.
  @State animationController: SetAnimationVariables = new SetAnimationVariables();

  build() {
    Column() {
      Text('ArkUI')
        .fontWeight(FontWeight.Bold)
        .fontSize(12)
        .fontColor(Color.White)
        .textAlign(TextAlign.Center)
        .borderRadius(10)
        .backgroundColor(0xf56c6c)
        .width(100)
        .height(100)
        .scale({
          // Step 2: Set the declared state variable to the related animatable property.
          x: this.animationController.isAnimation ? 2 : 1,
          y: this.animationController.isAnimation ? 2 : 1
        })
        .animation({ curve: curves.springMotion(0.4, 0.8) }) // Step 4: Enable animation. When the animation target value changes, the system automatically applies smooth transition.

      Button('Click')
        .margin({ top: 200 })
        .onClick(() => {
          // Step 3: Change the state variable value through the click event, which updates the property value.
          this.animationController.set()
        })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

![en-us_image_0000001599971890](figures/Animation-smoothing.gif)

## Smoothing Between Gestures and Animations

In scenarios where gestures are used, a property change is generally triggered when the user places or moves their finger (or fingers) on the screen, and continues after the user lifts their finger (or fingers) off the screen until the end value of the property is reached.

The initial velocity of the property change after the user lifts their finger (or fingers) should be consistent with the velocity of the property change at the moment before the user lifts their finger (or fingers). If the former is **0**, it feels like a running car stops suddenly, an unusual abrupt change not comfortable to users.

For scenarios where a transition is needed between [touch events](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md) and [animations](./arkts-animation.md) (such as list scrolling), a property animation using the follow-hand spring curve can be applied each time a component attribute is changed during the follow-hand phase. When the user lifts their finger, the lift-finger spring curve is used to generate the property animation for the lift-finger phase. For animations that use the [springMotion](../reference/apis-arkui/js-apis-curve.md#curvesspringmotion9) curve, the animation in the lift-finger phase automatically inherits the velocity from the follow-hand phase animation, starting from the current position of the follow-hand animation and moving to the specified target attribute value.

The following example implements a ball moving smoothly with the gesture.

<!-- @[animation_template2_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/cohesion/template2/Index.ets) -->

``` TypeScript
import { curves } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;
const TAG: string = '[AnimatorTest]';

@Entry
@Component
struct SpringMotionDemo {
  // Step 1: Declare the related state variable.
  @State positionX: number = 100;
  @State positionY: number = 100;
  diameter: number = 50;

  build() {
    Column() {
      Row() {
        Circle({ width: this.diameter, height: this.diameter })
          .fill(Color.Blue)
          .position ({x: this.positionX, y: this.positionY})// Step 2: Set the declared state variable to the related animatable property.
          .onTouch((event?: TouchEvent) => {
            // Step 3: Change the state variable value for the time when the user places or moves their finger (or fingers) on the screen and use responsiveSpringMotion for movement toward the new value.
            if (event) {
              if (event.type === TouchType.Move) {
                // When the user places or moves their finger on the screen, use the responsiveSpringMotion curve.
                this.getUIContext()?.animateTo({ curve: curves.responsiveSpringMotion() }, () => {
                  // Subtract the radius so that the center of the ball moves to where the finger is placed.
                  this.positionX = event.touches[0].windowX - this.diameter / 2;
                  this.positionY = event.touches[0].windowY - this.diameter / 2;
                  hilog.info(DOMAIN, TAG, `move, animateTo x:${this.positionX}, y:${this.positionY}`);
                })
              } else if (event.type === TouchType.Up) {
                // Step 4: Set the end value of the state variable for after the user lifts their finger (or fingers), and use springMotion for movement toward the new value. The springMotion animation inherits the previous velocity.
                this.getUIContext()?.animateTo({ curve: curves.springMotion() }, () => {
                  this.positionX = 100;
                  this.positionY = 100;
                  hilog.info(DOMAIN, TAG, `touchUp, animateTo x:100, y:100`);
                })
              }
            }
          })
      }
      .width('100%').height('80%')
      .clip(true) // If the ball moves beyond the parent component, it is invisible.
      .backgroundColor(Color.Orange)

      Flex({ direction: FlexDirection.Row, alignItems: ItemAlign.Start, justifyContent: FlexAlign.Center }) {
        // Replace $r('app.string.drag') with the actual resource file. In this example, the value in the resource file is "Drag the ball."
        Text($r('app.string.drag')).fontSize(16)
      }
      .width('100%')

      Row() {
        // Replace $r('app.string.location') with the actual resource file. In this example, the value in the resource file is "Clicked at:".
        Text($r('app.string.location') + ' [x: ' + Math.round(this.positionX) + ', y:' + Math.round(this.positionY) + ']').fontSize(16)
      }
      .padding(10)
      .width('100%')
    }.height('100%').width('100%')
  }
}
```

![en-us_image_0000001647027001](figures/Smoothing-Gestures-Animations.gif)