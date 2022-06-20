# Animator

> **NOTE**<br>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import animator from '@ohos.animator';
```


## createAnimator

createAnimator(options: AnimatorOptions): AnimatorResult

Creates an **Animator** object.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [AnimatorOptions](#animatoroptions) | Yes| Animator options. For details, see **AnimatorOptions**.|

**Return value**
| Type| Description|
| -------- | -------- |
| [AnimatorResult](#animatorresult) | Animator result.|

**Example**

  ```
  <!-- hml -->
  <div class="container">
    <div class="Animation" style="height: {{divHeight}}px; width: {{divWidth}}px; background-color: red;" onclick="Show">
    </div>
  </div>
  ```

  ```
  // js
  export default {
    data : {
      divWidth: 200,
      divHeight: 200,
      animator: null
    },
    onInit() {
      var options = {
        duration: 1500,
        easing: 'friction',
        fill: 'forwards',
        iterations: 2,
        begin: 200.0,
        end: 400.0
      };
      this.animator = animator.createAnimator(options);
    },
    Show() {
      var options1 = {
        duration: 2000,
        easing: 'friction',
        fill: 'forwards',
        iterations: 1,
        begin: 200.0,
        end: 400.0
      };
      this.animator.update(options1);
      var _this = this;
      this.animator.onframe = function(value) {
        _this.divWidth = value;
        _this.divHeight = value;
      };
      this.animator.play();
    }
  }
  ```

## AnimatorResult

Defines the animator result.

### update

update(options: AnimatorOptions): void

Updates this animator.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [AnimatorOptions](#animatoroptions) | Yes| Animator options.|

**Example**
```
animator.update(options);
```

### play

play(): void

Plays this animation.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**
```
animator.play();
```

### finish

finish(): void

Ends this animation.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**
```
animator.finish();
```

### pause

pause(): void

Pauses this animation.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**
```
animator.pause();
```

### cancel

cancel(): void

Cancels this animation.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**
```
animator.cancel();
```

### reverse

reverse(): void

Plays this animation in reverse order.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**
```
animator.reverse();
```

### onframe

onframe: (progress: number) => void

Called when a frame is received.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| progress | number | Yes| Current progress of the animation.|

**Example**
```
animator.onframe();
```

### onfinish

onfinish: () => void

Called when this animation is finished.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**
```
animator.onfinish();
```

### oncancel

oncancel: () => void

Called when this animation is canceled.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**
```
animator.oncancel();
```

### onrepeat

onrepeat: () => void

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**
```
animator.onrepeat();
```

Called when this animation repeats.

## AnimatorOptions

Defines animator options.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| duration | number | Yes| Duration for playing the animation, in milliseconds. The default value is **0**.|
| easing | string | Yes| Animation interpolation curve. The default value is **ease**.|
| delay | number | Yes| Animation delay duration, in milliseconds. The default value is **0**, indicating that there is no delay.|
| fill | "none" \| "forwards" \| "backwards" \| "both" | Yes| State of the animated target after the animation is executed. The default value is **none**, which means that after the animation is executed, the target will retain the state (defined by the last keyframe) it is in when the animation ends.|
| direction | "normal" \| "reverse" \| "alternate" \| "alternate-reverse" | Yes| Animation playback mode. The default value is **normal**.|
| iterations | number | Yes| Number of times that the animation is played. The default value is **1**. The value **0** means not to play the animation, and **-1** means to play the animation for an unlimited number of times.|
| begin | number | Yes| Start point of the animation interpolation. If this parameter is not set, the default value **0** is used.|
| end | number | Yes| End point of the animation interpolation. If this parameter is not set, the default value **1** is used.|
