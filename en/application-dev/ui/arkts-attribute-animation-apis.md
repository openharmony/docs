# Implementing Property Animation

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=e19b652374a358a3a50594a3ad8cb6bde0515e4e translatedAt=2026-07-29T12:43:22.603Z pushedAt=2026-07-31T01:24:06.167Z -->

Continuous visual effects on the UI resulting from changes to animatable properties are called property animations. As the most fundamental and intuitive type of animation, property animations form the core of UI animation systems. ArkUI provides three animation APIs to create these effects: [animateTo](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#animateto), [animation](../reference/apis-arkui/arkui-ts/ts-animatorproperty.md), and [keyframeAnimateTo](../reference/apis-arkui/arkui-ts/ts-keyframeAnimateTo.md).

> **NOTE**
>
> The attribute animation discussed in this section is not the narrowly defined [animation](../reference/apis-arkui/arkui-ts/ts-animatorproperty.md), but rather a method of animating properties by specifying new end values for animatable properties.

| Animation API| Scope| Principle| Use Scenario|
| -------- | -------- | -------- | -------- |
| animateTo | UI changes caused by attribute changes within a closure. | A general-purpose function that animates the differences between the UI before the closure and the UI caused by state variable changes within the closure.<br/>Supports multiple calls and nesting. | Suitable for scenarios where multiple animatable attributes share the same animation parameters, or where animation is triggered imperatively and explicitly.<br/>Scenarios requiring nested animations.<br/>To achieve a multi-segment looping animation effect, configure the **playMode** and **iterations** properties of [AnimateParam](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md#animateparam), or use **keyframeAnimateTo**. |
| animation | UI changes caused by attribute changes bound to a component through the attribute API. | A declarative attribute animation that detects changes to a component's animatable attributes and automatically applies animation.<br/>Component API calls are executed from bottom to top, and **animation** only affects the attributes called above it.<br/>A component can set different **animation** parameters for multiple attributes based on the call order. | Suitable for scenarios where different animatable attributes require different animation parameters, and for declarative approaches where animation is implicitly triggered upon attribute changes. |
| keyframeAnimateTo | Segmented property animation caused by property changes in multiple closures.| This API is a common function. It animates the difference between state variables in each closure and the previous state.<br>This API supports multiple calls, but nesting is not recommended.| Multiple animations are applied to the same property sequentially.|

## animateTo

<!--deprecated_code_no_check-->

```ts
animateTo(value: AnimateParam, event: () => void): void
```

In the [animateTo](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#animateto) API, **value** specifies the [AnimateParam](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md#animateparam) (including **duration** and **curve**). **event** is the closure function of the animation. The attribute animation generated due to variable changes in the closure follows the same animation parameters.

> **NOTE**
>
> Directly using **animateTo** can lead to the issue of [ambiguous UI context](./arkts-global-interface.md). To avoid this, obtain the [UIContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md) object using the [getUIContext()](../reference/apis-arkui/arkui-ts/ts-custom-component-api.md#getuicontext) API and then call the [animateTo](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#animateto) API through this object.

<!-- @[attrAnimateToDemo2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/animation/template2/Index.ets) -->

``` TypeScript
import { curves } from '@kit.ArkUI';
@Entry
@Component
struct attrAnimateToDemo2 {
  @State animate: boolean = false;
  // Step 1: Declare related state variables.
  @State rotateValue: number = 0; // Rotation angle of component 1.
  @State translateX: number = 0; // Offset of component 2
  @State opacityValue: number = 1; // Opacity of component 2.

  // Step 2: Set the declared state variables to the related animatable property APIs.
  build() {
    Row() {
      // Component 1
      Column() {
      }
      .rotate({ angle: this.rotateValue })
      .backgroundColor('#317AF7')
      .justifyContent(FlexAlign.Center)
      .width(100)
      .height(100)
      .borderRadius(30)
      .onClick(() => {
        this.getUIContext()?.animateTo({ curve: curves.springMotion() }, () => {
          this.animate = !this.animate;
          // Step 3: Change the state variables in the closure to update the UI.
          // You can write any logic that can change the UI, such as array adding and visibility control. The system detects the differences between the new UI and the previous UI and adds animations for the differences.
          // The rotate property of component 1 is changed. Therefore, a rotate animation is added to component 1.
          this.rotateValue = this.animate ? 90 : 0;
          // The opacity property of component 2 is changed. Therefore, an opacity animation is added to component 2.
          this.opacityValue = this.animate ? 0.6 : 1;
          // The translate property of component 2 is changed. Therefore, a translate animation is added to component 2.
          this.translateX = this.animate ? 50 : 0;
        })
      })

      // Component 2
      Column() {
      }
      .justifyContent(FlexAlign.Center)
      .width(100)
      .height(100)
      .backgroundColor('#D94838')
      .borderRadius(30)
      .opacity(this.opacityValue)
      .translate({ x: this.translateX })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

![en-us_image_0000001599958466](figures/animateTo-01.gif)

## animation

Compared with the animateTo API, which requires property modifications to be encapsulated in a closure for execution, the [animation](../reference/apis-arkui/arkui-ts/ts-animatorproperty.md) API does not require a closure. Instead, it can be directly added after the animatable property to be animated. The animation API automatically applies property animations whenever it detects changes to the bound animatable property, whereas animateTo requires that the animatable property's value be changed within the animation closure to generate the animation.

<!-- @[attrAnimationDemo3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/animation/template3/Index.ets) -->  

``` TypeScript
import { curves } from '@kit.ArkUI';
@Entry
@Component
struct attrAnimationDemo3 {
  @State animate: boolean = false;
  // Step 1: Declare related state variables.
  @State rotateValue: number = 0; // Rotation angle of component 1.
  @State translateX: number = 0; // Offset of component 2
  @State opacityValue: number = 1; // Opacity of Component 1 and Component 2.

  // Step 2: Set the declared state variables to the related animatable property APIs.
  build() {
    Row() {
      // Component 1
      Column() {
      }
      .opacity(this.opacityValue)
      .rotate({ angle: this.rotateValue })
      // Step 3: Enable property animation.
      .animation({ curve: curves.springMotion() })
      .backgroundColor('#317AF7')
      .justifyContent(FlexAlign.Center)
      .width(100)
      .height(100)
      .borderRadius(30)
      .onClick(() => {
        this.animate = !this.animate;
        // Step 4: Change the state variables in the closure to update the UI.
        // You can write any logic that can change the UI, such as array adding and visibility control. The system detects the differences between the new UI and the previous UI and adds animations for the differences.
        // The rotate property of component 1 is changed. Therefore, a rotate animation is added to component 1.
        this.rotateValue = this.animate ? 90 : 0;
        // The translate property of component 2 is changed. Therefore, a translate animation is added to component 2.
        this.translateX = this.animate ? 50 : 0;
        // The opacity attribute of Component 1 and Component 2 changes, so an opacity animation is added to them.
        this.opacityValue = this.animate ? 0.6 : 1;
      })

      // Component 2
      Column() {
      }
      .justifyContent(FlexAlign.Center)
      .width(100)
      .height(100)
      .backgroundColor('#D94838')
      .borderRadius(30)
      .opacity(this.opacityValue)
      .translate({ x: this.translateX })
      .animation({ curve: curves.springMotion() })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

![en-us_image_0000001649279705](figures/animation-01.gif)

## keyframeAnimateTo

```ts
keyframeAnimateTo(param: KeyframeAnimateParam, keyframes: Array<KeyframeState>): void
```

In the [keyframeAnimateTo](../reference/apis-arkui/arkui-ts/ts-keyframeAnimateTo.md) API, the first parameter [KeyframeAnimateParam](../reference/apis-arkui/arkui-ts/ts-keyframeAnimateTo.md#keyframeanimateparam) is the overall parameter of the keyframe animation (including the **delay**, **iterations**, **onFinish**, and **expectedFrameRateRange**). The second parameter is an array. Each item indicates the animation behavior in a keyframe. The animation parameters (including **duration** and **curve**) of each animation can be controlled separately.

If there are multiple animations for the same attribute, you can create a new animation in the end callback. However, the implementation is complex, and it takes time to create a new animation each time, which may cause frame freezing. Keyframe animations are more suitable for this scenario.

This example demonstrates how to set the keyframe animation using **keyframeAnimateTo**.

<!-- @[KeyframeAnimateToDemo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/animation/template4/Index.ets) -->

``` TypeScript
@Entry
@Component
struct KeyframeAnimateToDemo {
  // Step 1: Declare related state variables.
  @State rotateValue: number = 0; // Rotation angle of component 1.
  @State translateX: number = 0; // Offset of component 2
  @State opacityValue: number = 1; // Opacity of component 2.
  // Step 2: Set the declared state variables to the related animatable property APIs.
  build() {
    Row() {
      // Component 1
      Column() {
      }
      .rotate({ angle: this.rotateValue })
      .backgroundColor('#317AF7')
      .justifyContent(FlexAlign.Center)
      .width(100)
      .height(100)
      .borderRadius(30)
      .onClick(() => {
        // Step 3: Call the keyframeAnimateTo API.
        this.getUIContext()?.keyframeAnimateTo({
          iterations: 1
        }, [
          {
            // The first keyframe animation has a duration of 800 ms: Component 1 rotates 90 degrees clockwise. Component 2's opacity changes from 1 to 0.6, and its translation (translate) changes from 0 to 50.
            duration: 800,
            event: () => {
              this.rotateValue = 90;
              this.opacityValue = 0.6;
              this.translateX = 50;
            }
          },
          {
            // The second keyframe animation has a duration of 500 ms. Component 1 rotates 90 degrees counterclockwise to return to 0 degrees. Component 2's opacity changes from 0.6 back to 1, and its translation (translate) changes from 50 back to 0.
            duration: 500,
            event: () => {
              this.rotateValue = 0;
              this.opacityValue = 1;
              this.translateX = 0;
            }
          }
        ]);
      })
      // Component 2
      Column() {
      }
      .justifyContent(FlexAlign.Center)
      .width(100)
      .height(100)
      .backgroundColor('#D94838')
      .borderRadius(30)
      .opacity(this.opacityValue)
      .translate({ x: this.translateX })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

![keyframeAnimateTo1](figures/keyframeAnimateTo1.gif)

> **NOTE**
> - When an animation is applied to the position or size change of a component, as layout measurement is involved, performance overheads are high. To reduce performance overheads, use the [scale](../reference/apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#scale) attribute instead, whose value change does not involve layout re-measurement. This practice is applicable where the component position and size change continuously, for example, where the component size changes as a response to gestures.
>
> - Apply property animations only to consistently visible components. For those components whose visibility may change, use the [transition animation](arkts-transition-overview.md).
>
> - Avoid using end callbacks with property animations. Property animations are applied to states that have occurred. As such, you do not need to process the end logic. If end callbacks are needed, be sure to correctly handle the data management for continuous operations.
>
> - If transition animations are disabled in Developer options, or if the UIAbility switches from the foreground to the background, the end callback will be triggered immediately. It is recommended that you verify these scenarios and avoid placing timing-sensitive logic in this callback.