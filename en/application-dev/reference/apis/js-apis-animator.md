# @ohos.animator

The **animator** module provides APIs for applying animation effects, including defining animations, starting animations, and playing animations in reverse order.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import animator from '@ohos.animator';
```
## create<sup>9+</sup>

create(options: AnimatorOptions): AnimatorResult

Creates an **Animator** object.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                 | Mandatory  | Description     |
| ------- | ----------------------------------- | ---- | ------- |
| options | [AnimatorOptions](#animatoroptions) | Yes   | Animator options.|

**Return value**

| Type                               | Description           |
| --------------------------------- | ------------- |
| [AnimatorResult](#animatorresult) | Animator result.|

**Example**

  ```js
  let options = {
    duration: 1500,
    easing: 'friction',
    delay: 0,
    fill: 'forwards',
    direction: "normal",
    iterations: 3,
    begin: 200.0,
    end: 400.0,
  };
  animator.create(options);
  ```

## AnimatorResult

Defines the animator result.

### reset<sup>9+</sup>

reset(options: AnimatorOptions): void

Updates this animator.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                 | Mandatory  | Description     |
| ------- | ----------------------------------- | ---- | ------- |
| options | [AnimatorOptions](#animatoroptions) | Yes   | Animator options.|

**Error codes**

For details about the error codes, see [Animator Error Codes](../errorcodes/errorcode-animator.md).

| ID  | Error Message|
| --------- | ------- |
| 100001    | If no page is found for pageId or fail to get object property list. |


**Example**

```js
let options = {
  duration: 1500,
  easing: 'friction',
  delay: 0,
  fill: 'forwards',
  direction: "normal",
  iterations: 3,
  begin: 200.0,
  end: 400.0,
};
try {
  animator.reset(options);
} catch(error) {
  console.error(`Animator reset failed, error code: ${error.code}, message: ${error.message}.`);
}
```

### play

play(): void

Plays this animation.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```js
animator.play();
```

### finish

finish(): void

Ends this animation.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```js
animator.finish();
```

### pause

pause(): void

Pauses this animation.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```js
animator.pause();
```

### cancel

cancel(): void

Cancels this animation.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```js
animator.cancel();
```

### reverse

reverse(): void

Plays this animation in reverse order.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```js
animator.reverse();
```

### onframe

onframe: (progress: number) => void

Called when a frame is received.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description      |
| -------- | ------ | ---- | -------- |
| progress | number | Yes   | Current progress of the animation.|

**Example**

```js
let animatorResult = animator.create(options)
animatorResult.onframe = function(value) {
  console.info("onframe callback")
}
```

### onfinish

onfinish: () => void

Called when this animation is finished.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```js
let animatorResult = animator.create(options)
animatorResult.onfinish = function() {
  console.info("onfinish callback")
}
```

### oncancel

oncancel: () => void

Called when this animation is canceled.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```js
let animatorResult = animator.create(options)
animatorResult.oncancel = function() {
  console.info("oncancel callback")
}
```

### onrepeat

onrepeat: () => void

Called when this animation repeats.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```js
let animatorResult = animator.create(options)
animatorResult.onrepeat = function() {
  console.info("onrepeat callback")
}
```



## AnimatorOptions

Defines animator options.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                    | Mandatory  | Description                                      |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| duration   | number                                   | Yes   | Duration for playing the animation, in milliseconds. The default value is **0**.                      |
| easing     | string                                   | Yes   | Animation interpolation curve. The default value is **ease**.                       |
| delay      | number                                   | Yes   | Animation delay duration, in milliseconds. The default value is **0**, indicating that there is no delay.                |
| fill       | "none" \| "forwards" \| "backwards" \| "both" | Yes   | State of the animated target after the animation is executed. The default value is **none**, which means that the target will retain its end state (defined by the last keyframe) after the animation is executed.|
| direction  | "normal" \| "reverse" \| "alternate" \| "alternate-reverse" | Yes   | Animation playback mode. The default value is **normal**.                     |
| iterations | number                                   | Yes   | Number of times that the animation is played. The default value is **1**. The value **0** means not to play the animation, and **-1** means to play the animation for an unlimited number of times.       |
| begin      | number                                   | Yes   | Start point of the animation interpolation. The default value is 0.                            |
| end        | number                                   | Yes   | End point of animation interpolation. The default value is 1.                            |


## Example
### JavaScript-compatible Web-like Development Paradigm

```html
<!-- hml -->
<div class="container">
  <div class="Animation" style="height: {{divHeight}}px; width: {{divWidth}}px; background-color: red;" onclick="Show">
  </div>
</div>
```

```js
export default {
  data: {
    divWidth: 200,
    divHeight: 200,
    animator: null
  },
  onInit() {
    let options = {
      duration: 1500,
      easing: 'friction',
      delay: 0,
      fill: 'forwards',
      direction: "normal",
      iterations: 2,
      begin: 200.0,
      end: 400.0
    };
    this.animator = animator.create(options);
  },
  Show() {
    let options1 = {
      duration: 1500,
      easing: 'friction',
      delay: 0,
      fill: 'forwards',
      direction: "normal",
      iterations: 2,
      begin: 0,
      end: 400.0,
    };
    try {
      this.animator.reset(options1);
    } catch(error) {
      console.error(`Animator reset failed, error code: ${error.code}, message: ${error.message}.`);
    }
    let _this = this;
    this.animator.onframe = function(value) {
      _this.divWidth = value;
      _this.divHeight = value;
    };
    this.animator.play();
  }
}
```

  ![en-us_image_00007](figures/en-us_image_00007.gif)

### ArkTS-based Declarative Development Paradigm

```ts
import animator from '@ohos.animator';

@Entry
@Component
struct AnimatorTest {
  private TAG: string = '[AnimatorTest]'
  private backAnimator: any = undefined
  private flag: boolean = false
  @State wid: number = 100
  @State hei: number = 100

  create() {
    let _this = this
    this.backAnimator = animator.create({
      duration: 2000,
      easing: 'ease',
      delay: 0,
      fill: 'none',
      direction: 'normal',
      iterations: 1,
      begin: 100,
      end: 200
    })
    this.backAnimator.onfinish = function () {
      _this.flag = true
      console.info(_this.TAG, 'backAnimator onfinish')
    }
    this.backAnimator.onrepeat = function () {
      console.info(_this.TAG, 'backAnimator repeat')
    }
    this.backAnimator.oncancel = function () {
      console.info(_this.TAG, 'backAnimator cancel')
    }
    this.backAnimator.onframe = function (value) {
      _this.wid = value
      _this.hei = value
    }
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
              this.backAnimator.play()
            })
        }
        .padding(10)

        Row() {
          Button('pause')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              this.backAnimator.pause()
            })
        }
        .padding(10)

        Row() {
          Button('finish')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              this.flag = true
              this.backAnimator.finish()
            })
        }
        .padding(10)

        Row() {
          Button('reverse')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              this.flag = false
              this.backAnimator.reverse()
            })
        }
        .padding(10)

        Row() {
          Button('cancel')
            .fontSize(30)
            .fontColor(Color.Black)
            .onClick(() => {
              this.backAnimator.cancel()
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
                this.backAnimator.reset({
                  duration: 5000,
                  easing: 'ease-in',
                  delay: 0,
                  fill: 'none',
                  direction: 'normal',
                  iterations: 4,
                  begin: 100,
                  end: 300
                })
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
| options | [AnimatorOptions](#animatoroptions) | Yes   | Animator options.|

**Example**

```js
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
| options | [AnimatorOptions](#animatoroptions) | Yes   | Animator options.|

**Return value**

| Type                               | Description           |
| --------------------------------- | ------------- |
| [AnimatorResult](#animatorresult) | Animator result.|

**Example**

```js
let options = {
  duration: 1500,
  easing: 'friction',
  delay: 0,
  fill: 'forwards',
  direction: "normal",
  iterations: 3,
  begin: 200.0,
  end: 400.0,
};
this.animator = animator.createAnimator(options);
```
