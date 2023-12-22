# Enter/Exit Transition


You can use [transition](../reference/arkui-ts/ts-transition-animation-component.md), a basic component transition API, to animate the appearance and disappearance of a component. You can even use it with [TransitionEffect](../reference/arkui-ts/ts-transition-animation-component.md#transitioneffect10) to up your animation game.


  **Table 1** Transition effect APIs

| API| Description| Animation|
| -------- | -------- | -------- |
| IDENTITY | Disables the transition effect.| None.|
| OPACITY | Applies the default opacity transition effect.| The component appears by changing the opacity from 0 to 1 and disappears by changing the opacity from 1 to 0.|
| SLIDE | Applies a sliding transition effect.| The component appears by sliding in from the left edge of the window and disappears by sliding out from the right edge of the window.|
| translate | Applies a translation transition effect.| The component appears by moving from the position set by the **translate** API to the default position (value **0**), and disappears by moving from the default position (value **0**) to the position set by the **translate** API.|
| rotate | Applies a rotation transition effect.| The component appears by rotating from the position set by the **rotate** API to the default position (value **0**), and disappears by rotating from the default position (value **0**) to the position set by the **rotate** API.|
| opacity | Applies an opacity transition effect.| The component appears by changing the opacity from the set value to **1** (default value) and disappears by changing the opacity from **1** to the set value.|
| move | Applies a transition effect by specifying which edge the component slides in and out of through [TransitionEdge](../reference/arkui-ts/ts-appendix-enums.md#transitionedge10).| The component appears by sliding in from the edge specified by **TransitionEdge** and disappears by sliding out of the same edge.|
| asymmetric | Applies an asymmetric transition effect.<br>- **appear**: transition effect for appearance.<br>- **disappear**: transition effect for disappearance.| The component appears by applying the transition effect specified by **appear** and disappears by applying the transition effect specified by **disappear**.|
| combine | Combines with other transition effects.| The component appears and disappears by combing with other transition effects.|
| animation | Defines the animation settings for the transition effect.<br>- If animation settings are not specified here, the animation settings of **animateTo** will be used.<br>- Animation settings cannot be configured through the **animation** API of the component.<br>- The **onFinish** callback of the **animation** parameter in **TransitionEffect** does not take effect.| The API call sequence is from top to bottom. This means that the **animation** settings of **TransitionEffect** at the upper level also take effect on **TransitionEffect** at the lower level .|


1. Create a **TransitionEffect** object.
  
   ```ts
   // The component appears by applying all transition effects for appearance and disappears by applying all transition effects for disappearance.
   // Define the animation settings for each transition effect.
   private effect: object =
     TransitionEffect.OPACITY // Apply an opacity transition effect. As the animation API is not called here, the animation settings of animateTo are used.
       // Apply a scaling transition effect and specify springMotion (0.6, 1.2) as the curve.
       .combine(TransitionEffect.scale({ x: 0, y: 0 }).animation({curve: curves.springMotion(0.6, 1.2) }))
       // Apply a rotation transition effect, whose animation settings follow TransitionEffect above, that is, springMotion (0.6, 1.2).
       .combine(TransitionEffect.rotate({ angle: 90 }))
       // Apply a translation transition effect, whose animation settings follow TransitionEffect above, that is, springMotion (0.6, 1.2).
       .combine(TransitionEffect.translate({ x: 150, y: 150 })
       // Apply a move transition effect and specify springMotion as the curve.
       .combine(TransitionEffect.move(TransitionEdge.END)).animation({curve: curves.springMotion()}))
       // Apply an asymmetric transition effect. As the animation API is not called here, the animation settings follow TransitionEffect above, that is, springMotion.
       .combine(TransitionEffect.asymmetric(TransitionEffect.scale({ x: 0, y: 0 }), TransitionEffect.rotate({angle: 90})));
   ```

2. Set the transition effects to the component by calling [transition](../reference/arkui-ts/ts-transition-animation-component.md).
  
   ```ts
   Text('test')
     .transition(effect)
   ```

3. Add or delete the component to trigger transition.
  
   ```ts
   @State isPresent: boolean = true;
   ...
   if (this.isPresent) {
     Text('test')
       .transition(effect)
   }
   ...
   // Control the addition or deletion of the component.
   // Method 1: Place the control variable in the animateTo closure. In this case, the transition effect for which the animation API is not call will follow the animation settings of animateTo.
   animateTo({curve: curves.springMotion()}, ()=> {
     this.isPresent = false;
   })
   
   // Method 2: Directly delete or add the component. In this case, the transition effects follow the animation settings specified by animation.
   this.isPresent = false;
   ```


 Below is the complete sample code and effect. In the example, the transition is triggered by deleting or adding a component. It can also be triggered by changing the variables in the **animateTo** closure.

```ts
import curves from '@ohos.curves';

@Entry
@Component
struct TransitionEffectDemo {
  @State isPresent: boolean = false;

  // Step 1: Create a TransitionEffect object.
  private effect: TransitionEffect =
    // Apply the default opacity transition effect and specify springMotion (0.6, 0.8) as the curve.
  TransitionEffect.OPACITY.animation({ curve: curves.springMotion(0.6, 0.8) })
    // Combine with a scale transition effect, whose animation settings follow TransitionEffect above, that is, springMotion(0.6, 0.8).
    .combine(TransitionEffect.scale({ x: 0, y: 0 }))
      // Apply a rotation transition effect, whose animation settings follow TransitionEffect above, that is, springMotion(0.6, 0.8).
    .combine(TransitionEffect.rotate({ angle: 90 }))
      // Apply a translation transition effect, whose animation settings are specified by animation, which is springMotion().
    .combine(TransitionEffect.translate({ y: 150 }).animation({ curve: curves.springMotion() }))
      // Apply a movement transition effect, whose animation settings follow TransitionEffect above, that is, springMotion().
    .combine(TransitionEffect.move(TransitionEdge.END))

  build() {
    Stack() {
      if (this.isPresent) {
        Column() {
          Text('ArkUI')
            .fontWeight(FontWeight.Bold)
            .fontSize(20)
            .fontColor(Color.White)
        }
        .justifyContent(FlexAlign.Center)
        .width(150)
        .height(150)
        .borderRadius(10)
        .backgroundColor(0xf56c6c)
        // Step 2: Set the transition effects to the component through the transition API.
        .transition(this.effect)
      }

      // Border
      Column()
        .width(155)
        .height(155)
        .border({
          width: 5,
          radius: 10,
          color: Color.Black,
        })

      // Step 3: Add or delete the component to trigger transition. Control the addition or deletion of the component.
      Button('Click')
        .margin({ top: 320 })
        .onClick(() => {
          this.isPresent = !this.isPresent;
        })
    }
    .width('100%')
    .height('60%')
  }
}
```



![en-us_image_0000001599818064](figures/en-us_image_0000001599818064.gif)
