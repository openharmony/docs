# @ohos.animator (Animator)

The **Animator** module provides APIs for applying animation effects, including defining animations, starting animations, and playing animations in reverse order.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module can be used in ArkTS since API version 9.
>
> This module cannot be used in the file declaration of the [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md). In other words, the APIs of this module can be used only after a component instance is created; they cannot be called in the lifecycle of the UIAbility.
>
> The functionality of this module depends on UI context. This means that the APIs of this module cannot be used where the UI context is unclear. For details, see [UIContext](js-apis-arkui-UIContext.md#uicontext).
>
> Since API version 10, you can use the [createAnimator](js-apis-arkui-UIContext.md#createanimator) API in [UIContext](js-apis-arkui-UIContext.md#uicontext) to obtain the UI context.

## Modules to Import

```ts
import { Animator as animator, AnimatorOptions,AnimatorResult } from '@kit.ArkUI';
```
## create<sup>9+</sup>

create(options: AnimatorOptions): AnimatorResult

Creates an **Animator** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name    | Type                                 | Mandatory  | Description     |
| ------- | ----------------------------------- | ---- | ------- |
| options | [AnimatorOptions](#animatoroptions) | Yes   | Animator options. |

**Return value** 

| Type                               | Description           |
| --------------------------------- | ------------- |
| [AnimatorResult](#animatorresult) | Animator result. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |

**Example** 

  ```ts
import {Animator as animator, AnimatorOptions, AnimatorResult } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
let options: AnimatorOptions = {
   duration: 1500,
   easing: "friction",
   delay: 0,
   fill: "forwards",
   direction: "normal",
   iterations: 3,
   begin: 200.0,
   end: 400.0
};
animator.create(options);
  ```

## AnimatorResult

Defines the animator result.

### reset<sup>9+</sup>

reset(options: AnimatorOptions): void

Updates this animator.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name    | Type                                 | Mandatory  | Description     |
| ------- | ----------------------------------- | ---- | ------- |
| options | [AnimatorOptions](#animatoroptions) | Yes   | Animator options. |

**Error codes**

For details about the error codes, see [Animator Error Codes](errorcode-animator.md).

| ID  | Error Message |
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001    | The specified page is not found or the object property list is not obtained.|


**Example**

```ts
import {Animator as animator, AnimatorOptions, AnimatorResult } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
let options: AnimatorOptions = {
  duration: 1500,
  easing: "friction",
  delay: 0,
  fill: "forwards",
  direction: "normal",
  iterations: 3,
  begin: 200.0,
  end: 400.0
};
let optionsNew: AnimatorOptions = {
  duration: 1500,
  easing: "friction",
  delay: 0,
  fill: "forwards",
  direction: "normal",
  iterations: 5,
  begin: 200.0,
  end: 400.0
};
try {
  let animatorResult:AnimatorResult|undefined = animator.create(options)
  animatorResult.reset(optionsNew);
} catch(error) {
  let message = (error as BusinessError).message
  let code = (error as BusinessError).code
  console.error(`Animator reset failed, error code: ${code}, message: ${message}.`);
}
```

### play

play(): void

Plays this animation. The animation retains the previous playback state. For example, if the animation is set to **reverse** and paused, it will remain in **reverse** when resumed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
animator.play();
```

### finish

finish(): void

Ends this animation.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
animator.finish();
```

### pause

pause(): void

Pauses this animation.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
animator.pause();
```

### cancel

cancel(): void

Cancels this animation.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
animator.cancel();
```

### reverse

reverse(): void

Plays this animation in reverse order. This API does not take effect when the interpolating spring curve is used.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
animator.reverse();
```

### onFrame<sup>12+</sup>

onFrame: (progress: number) => void

Called when a frame is received.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name     | Type    | Mandatory  | Description      |
| -------- | ------ | ---- | -------- |
| progress | number | Yes   | Current value of the animation. |

**Example**

```ts
import {Animator as animator, AnimatorResult } from '@kit.ArkUI';
let animatorResult:AnimatorResult|undefined = animator.create(options)
animatorResult.onFrame = (value:number)=> {
  console.info("onFrame callback")
}
```

### onFinish<sup>12+</sup>

onFinish: () => void

Called when this animation is finished.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
import {Animator as animator, AnimatorResult } from '@kit.ArkUI';
let animatorResult:AnimatorResult|undefined = animator.create(options)
animatorResult.onFinish = ()=> {
  console.info("onFinish callback")
}
```

### onCancel<sup>12+</sup>

onCancel: () => void

Called when this animation is canceled.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
import { Animator as animator, AnimatorResult } from '@kit.ArkUI';
let animatorResult:AnimatorResult|undefined = animator.create(options)
animatorResult.onCancel = ()=> {
  console.info("onCancel callback")
}
```

### onRepeat<sup>12+</sup>

onRepeat: () => void

Called when this animation repeats.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
import {Animator as animator, AnimatorResult} from '@kit.ArkUI';
let animatorResult:AnimatorResult|undefined = animator.create(options)
animatorResult.onRepeat = ()=> {
  console.info("onRepeat callback")
}
```

### onframe<sup>(deprecated)</sup>

> **NOTE**
>
> This API is deprecated since API version 12. You are advised to use [onFrame](#onframe12) instead.

onframe: (progress: number) => void

Called when a frame is received.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name     | Type    | Mandatory  | Description      |
| -------- | ------ | ---- | -------- |
| progress | number | Yes   | Current progress of the animation. |

**Example**

```ts
import  { Animator as animator, AnimatorResult } from '@kit.ArkUI';
let animatorResult:AnimatorResult|undefined = animator.create(options)
animatorResult.onframe = (value)=> {
  console.info("onframe callback")
}
```

### onfinish<sup>(deprecated)</sup>

> **NOTE**
>
> This API is deprecated since API version 12. You are advised to use [onFinish](#onfinish12) instead.

onfinish: () => void

Called when this animation is finished.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
import { Animator as animator, AnimatorResult } from '@kit.ArkUI';
let animatorResult:AnimatorResult|undefined = animator.create(options)
animatorResult.onfinish = ()=> {
  console.info("onfinish callback")
}
```

### oncancel<sup>(deprecated)</sup>

> **NOTE**
>
> This API is deprecated since API version 12. You are advised to use [onCancel](#oncancel12) instead.


oncancel: () => void

Called when this animation is canceled.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
import { Animator as animator, AnimatorResult } from '@kit.ArkUI';
let animatorResult:AnimatorResult|undefined = animator.create(options)
animatorResult.oncancel = ()=> {
  console.info("oncancel callback")
}
```

### onrepeat<sup>(deprecated)</sup>

> **NOTE**
>
> This API is deprecated since API version 12. You are advised to use [onRepeat](#onrepeat12) instead.

onrepeat: () => void

Called when this animation repeats.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
import { Animator as animator, AnimatorResult } from '@kit.ArkUI';
let animatorResult:AnimatorResult|undefined = animator.create(options)
animatorResult.onrepeat = ()=> {
  console.info("onrepeat callback")
}
```

### setExpectedFrameRateRange<sup>12+</sup>

setExpectedFrameRateRange(rateRange: ExpectedFrameRateRange): void

Sets the expected frame rate range.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name          | Type                                      | Mandatory | Description                         |
| --------------- | ------------------------------------------ | ---- | -----------------------------|
| rateRange       | [ExpectedFrameRateRange](../apis-arkui/arkui-ts/ts-explicit-animation.md#expectedframeraterange11)| Yes  | Expected frame rate range.|

**Example**

```ts
import { Animator as animator, AnimatorResult } from '@kit.ArkUI';
let animatorResult: AnimatorResult | undefined = animator.create({
  duration: 2000,
  easing: "ease",
  delay: 0,
  fill: "forwards",
  direction: "normal",
  iterations: 1,
  begin: 100,
  end: 200
})
let expectedFrameRate: ExpectedFrameRateRange = {
  min: 0,
  max: 120,
  expected: 30
}
animatorResult.setExpectedFrameRateRange(expectedFrameRate);
```

## AnimatorOptions

Animator options.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Type                                                       | Mandatory | Description                                                        |
| ---------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| duration   | number                                                      | Yes  | Duration for playing the animation, in milliseconds.<br>Default value: **0**                                  |
| easing     | string                                                      | Yes  | Animation interpolation curve. Only the following values are supported:<br>**"linear"**: The animation speed keeps unchanged.<br>**"ease"**: The animation starts slowly, accelerates, and then slows down towards the end. The cubic-bezier curve (0.25, 0.1, 0.25, 1.0) is used.<br>**"ease-in"**: The animation starts at a low speed and then picks up speed until the end. The cubic-bezier curve (0.42, 0.0, 1.0, 1.0) is used.<br>**"ease-out"**: The animation ends at a low speed. The cubic-bezier curve (0.0, 0.0, 0.58, 1.0) is used.<br>**"ease-in-out"**: The animation starts and ends at a low speed. The cubic-bezier curve (0.42, 0.0, 0.58, 1.0) is used.<br>**"fast-out-slow-in"**: The animation uses the standard cubic-bezier curve (0.4, 0.0, 0.2, 1.0).<br>**"linear-out-slow-in"**: The animation uses the deceleration cubic-bezier curve (0.0, 0.0, 0.2, 1.0).<br>**"fast-out-linear-in"**: The animation uses acceleration cubic-bezier curve (0.4, 0.0, 1.0, 1.0)<br>**"friction"**: The animation uses the damping cubic-bezier curve (0.2, 0.0, 0.2, 1.0).<br>**"extreme-deceleration"**: The animation uses the extreme deceleration cubic-bezier curve (0.0, 0.0, 0.0, 1.0).<br>**"rhythm"**: The animation uses the rhythm cubic-bezier curve (0.7, 0.0, 0.2, 1.0).<br>**"sharp"**: The animation uses the sharp cubic-bezier curve (0.33, 0.0, 0.67, 1.0).<br>**"smooth"**: The animation uses the smooth cubic-bezier curve (0.4, 0.0, 0.4, 1.0).<br>**"cubic-bezier(x1,y1,x2,y2)"**: The animation uses the defined cubic bezier curve, where the value of **x1** and **x2** must range from 0 to 1. For example, **"cubic-bezier(0.42,0.0,0.58,1.0)"**.<br>**"steps(number,step-position)"**: The animation uses a step curve. The **number** parameter is mandatory and must be set to a positive integer. The **step-position** parameter is optional and can be set to **start** or **end** (default value). For example, **"steps(3,start)"**.<br>**"interpolating-spring(velocity,mass,stiffness,damping)"**: The animation uses an interpolating spring curve. This API is supported since API version 11 and can be used only in ArkTS. The **velocity**, **mass**, **stiffness**, and **damping** parameters are of the numeric type, and the values of **mass**, **stiffness**, and **damping** must be greater than 0. For details about the parameters, see [Curves.interpolatingSpring](./js-apis-curve.md#curvesinterpolatingspring10). When an interpolating spring curve is used, settings for the **duration**, **fill**, **direction**, and **iterations** do not take effect. Rather, the value of **duration** is subject to the spring settings, **fill** is fixed at **forwards**, **direction** at **normal**, and **iterations** at **1**. In addition, invoking [reverse](#reverse) of **animator** is not effective. In other words, when using an interpolating spring curve, the animation can play only once in forward mode.<br>Default value: **"ease"** |
| delay      | number                                                      | Yes  | Animation delay duration, in milliseconds. Value **0** means that there is no delay. If the value specified is a negative number, the animation starts playing ahead of its scheduled time. If the amount of time by which the playback is advanced is greater than the total duration of the animation, the animation skips to the end state immediately.<br>Default value: **0**         |
| fill       | "none" \| "forwards" \| "backwards" \| "both"               | Yes  | State of the animated target after the animation is executed.<br>**"none"**: No style is applied to the target before or after the animation is executed.<br>**"forwards"**: The target keeps the state at the end of the animation (defined in the last key frame) after the animation is executed.<br>**"backwards"**: The animation uses the value defined in the first key frame during the **animation-delay**. When **animation-direction** is set to **normal** or **alternate**, the value in the **from** key frame is used. When **animation-direction** is set to **reverse** or **alternate-reverse**, the value in the **to** key frame is used.<br>**"both"**: The animation follows the **forwards** and **backwards** rules. |
| direction  | "normal" \| "reverse" \| "alternate" \| "alternate-reverse" | Yes  | Animation playback mode.<br>**"normal"**: plays the animation in forward loop mode.<br>**"reverse"**: plays the animation in reverse loop mode.<br>**"alternate"**: plays the animation in alternating loop mode. When the animation is played for an odd number of times, the playback is in forward direction. When the animation is played for an even number of times, the playback is in reverse direction.<br>**"alternate-reverse"**: plays the animation in reverse alternating loop mode. When the animation is played for an odd number of times, the playback is in reverse direction. When the animation is played for an even number of times, the playback is in forward direction.<br>Default value: **'normal'** |
| iterations | number                                                      | Yes  | Number of times that the animation is played. The value **0** means not to play the animation, and **-1** means to play the animation for an unlimited number of times.<br>**NOTE**<br>If this parameter is set to a negative value other than **-1**, the value is invalid. In this case, the animation is played once. |
| begin      | number                                                      | Yes  | Start point of the animation interpolation.<br>Default value: **0**                                              |
| end        | number                                                      | Yes  | End point of animation interpolation.<br>Default value: **1**                                              |


## Example
### JavaScript-compatible Web-like Development Paradigm

```html
<!-- hml -->
<div class="container">
  <div class="Animation" style="height: {{divHeight}}px; width: {{divWidth}}px; background-color: red;" onclick="Show">
  </div>
</div>
```

```ts
import { Animator as animator, AnimatorResult } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
let DataTmp:Record<string,Animator> = {
  'divWidth': 200,
  'divHeight': 200,
  'animator': animator
}
class Tmp{
  data:animator = DataTmp
  onInit:Function = ()=>{}
  Show:Function = ()=>{}
}
class DateT{
  divWidth:number = 0
  divHeight:number = 0
  animator:AnimatorResult | null = null
}
(Fn:(v:Tmp) => void) => {Fn({
  data: DataTmp,
  onInit() {
    let options:AnimatorOptions = {
      duration: 1500,
      easing: "friction",
      delay: 0,
      fill: "forwards",
      direction: "normal",
      iterations: 2,
      begin: 200.0,
      end: 400.0
    };
    let DataTmp:DateT = {
      divWidth: 200,
      divHeight: 200,
      animator: null
    }
    DataTmp.animator = animator.create(options);
  },
  Show() {
    let options1:AnimatorOptions = {
      duration: 1500,
      easing: "friction",
      delay: 0,
      fill: "forwards",
      direction: "normal",
      iterations: 2,
      begin: 0,
      end: 400.0,
    };
    let DataTmp:DateT = {
      divWidth: 200,
      divHeight: 200,
      animator: null
    }
    try {
      DataTmp.animator = animator.create(options1);
      DataTmp.animator.reset(options1);
    } catch(error) {
      let message = (error as BusinessError).message
      let code = (error as BusinessError).code
      console.error(`Animator reset failed, error code: ${code}, message: ${message}.`);
    }
    let _this = DataTmp;
    if(DataTmp.animator){
      DataTmp.animator.onFrame = (value:number)=> {
        _this.divWidth = value;
        _this.divHeight = value;
      };
      DataTmp.animator.play();
    }
  }
})}
```

  ![en-us_image_00007](figures/en-us_image_00007.gif)

### ArkTS-based Declarative Development Paradigm

```ts
import { Animator as animator, AnimatorResult } from '@kit.ArkUI';


@Entry
@Component
struct AnimatorTest {
  private TAG: string = '[AnimatorTest]'
  private backAnimator: AnimatorResult | undefined = undefined
  private flag: boolean = false
  @State wid: number = 100
  @State hei: number = 100

  create() {
    let _this = this
    this.backAnimator = animator.create({
      duration: 2000,
      easing: "ease",
      delay: 0,
      fill: "forwards",
      direction: "normal",
      iterations: 1,
      begin: 100,
      end: 200
    })
    this.backAnimator.onFinish = ()=> {
      _this.flag = true
      console.info(_this.TAG, 'backAnimator onfinish')
    }
    this.backAnimator.onRepeat = ()=> {
      console.info(_this.TAG, 'backAnimator repeat')
    }
    this.backAnimator.onCancel = ()=> {
      console.info(_this.TAG, 'backAnimator cancel')
    }
    this.backAnimator.onFrame = (value:number)=> {
      _this.wid = value
      _this.hei = value
    }
  }

  aboutToDisappear() {
    // Because backAnimator references this in onframe, backAnimator is saved in this.
    // When the custom component disappears, leave backAnimator empty to avoid memory leak.
    this.backAnimator = undefined;
  }

  build() {
    Column() {
      Column() {
        Column()
          .width(this.wid)
          .height(this.hei)
          .backgroundColor(Color.Red)
      }
      .width('100%')
      .height(300)

      Column() {
        Row() {
          Button('create')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              this.create()
            })
        }
        .padding(10)

        Row() {
          Button('play')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              this.flag = false
              if(this.backAnimator){
                this.backAnimator.play()
              }
            })
        }
        .padding(10)

        Row() {
          Button('pause')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              if(this.backAnimator){
                this.backAnimator.pause()
              }
            })
        }
        .padding(10)

        Row() {
          Button('finish')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              this.flag = true
              if(this.backAnimator){
                this.backAnimator.finish()
              }
            })
        }
        .padding(10)

        Row() {
          Button('reverse')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              this.flag = false
              if(this.backAnimator){
                this.backAnimator.reverse()
              }
            })
        }
        .padding(10)

        Row() {
          Button('cancel')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              if(this.backAnimator){
                this.backAnimator.cancel()
              }
            })
        }
        .padding(10)

        Row() {
          Button('reset')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              if (this.flag) {
                this.flag = false
                if(this.backAnimator){
                  this.backAnimator.reset({
                    duration: 3000,
                    easing: "ease-in",
                    delay: 0,
                    fill: "forwards",
                    direction: "alternate",
                    iterations: 3,
                    begin: 100,
                    end: 300
                  })
                }
              } else {
                console.info(this.TAG, 'Animation not ended')
              }
            })
        }
        .padding(10)
      }
    }
  }
}
```

## update<sup>(deprecated)</sup>

update(options: AnimatorOptions): void

Updates this animator.

This API is deprecated since API version 9. You are advised to use [reset<sup>9+</sup>](#reset9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name    | Type                                 | Mandatory  | Description     |
| ------- | ----------------------------------- | ---- | ------- |
| options | [AnimatorOptions](#animatoroptions) | Yes   | Animator options. |

**Example**

```ts
animator.update(options);
```

## createAnimator<sup>(deprecated)</sup>

createAnimator(options: AnimatorOptions): AnimatorResult

Creates an **Animator** object.

This API is deprecated since API version 9. You are advised to use [create<sup>9+</sup>](#create9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name    | Type                                 | Mandatory  | Description     |
| ------- | ----------------------------------- | ---- | ------- |
| options | [AnimatorOptions](#animatoroptions) | Yes   | Animator options. |

**Return value** 

| Type                               | Description           |
| --------------------------------- | ------------- |
| [AnimatorResult](#animatorresult) | Animator result. |

**Example** 

```ts
import { Animator as animator, AnimatorResult } from '@kit.ArkUI';

let options: AnimatorOptions = { // The explicit type AnimatorOptions does not need to be emphasized in a .js file.
  duration: 1500,
  easing: "friction",
  delay: 0,
  fill: "forwards",
  direction: "normal",
  iterations: 3,
  begin: 200.0,
  end: 400.0,
};
this.animator = animator.createAnimator(options);
```
