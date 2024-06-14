# Animation Effect


You can set the interpolator to implement the animation effect.


## Creating an Animation Object

Use createAnimator to create an animation object and set the animation attributes by using the options parameter.

```html
<!-- xxx.hml -->
<div class="container">
  <div style="width: 300px;height: 300px;margin-top: 100px;background: linear-gradient(pink, purple);transform: translate({{translateVal}});">
  </div>
  <div class="row">
    <button type="capsule" value="play" onclick="playAnimation"></button>
  </div>
</div>
```

```css
/* xxx.css */
.container {
  width:100%;
  height:100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
}
button{
  width: 200px;
}
.row{
  width: 65%;
  height: 100px;
  align-items: center;
  justify-content: space-between;
  margin-top: 50px;
  margin-left: 260px;
}
```

```js
// xxx.js
import animator from '@ohos.animator';
export default {
  data: {
    translateVal: 0,
    animation: null
  },
  onInit() {},
  onShow(){
    var options = {
      duration: 3000,
      easing:"friction",
      delay:"1000",
      fill: 'forwards',
      direction:'alternate',
      iterations: 2,
      begin: 0,
      end: 180
    };// Set attributes.
    this.animation = animator.createAnimator(options)// Create an animation.
  },
  playAnimation() {
    var _this = this;
    this.animation.onframe = function(value) {
      _this.translateVal= value
    };
    this.animation.play();
  }
}
```

![en-us_image_0000001267887885](figures/en-us_image_0000001267887885.gif)

> **NOTE**
>
> - When you use createAnimator to create an animation object, you must pass the options parameter.
>
> - begin indicates the start point of the animation interpolation. If it is not set, the default value 0 is used.
>
> - end indicates the end point of the animation interpolation. If it is not set, the default value 1 is used.


## Adding Animation Events and Calling Methods

The animator supports events and methods, which you can use to customize the animation effect. Events include frame, cancel, repeat, and finish. Methods include update, play, pause, cancel, reverse, and finish. For details about the supported events and methods, see [animator supported events and animator supported APIs](../reference/apis-arkui/js-apis-animator.md).

```html
<!-- xxx.hml -->
<div style="flex-direction: column;align-items: center;width: 100%;height: 100%;">
  <div style="width:200px;height: 200px;margin-top: 100px;background: linear-gradient(#b30d29, #dcac1b);
  transform: scale({{scaleVal}});"></div>
  <div style="width: {{DivWidth}};height: {{DivHeight}};margin-top: 200px;
  background: linear-gradient(pink, purple);margin-top: 200px;transform:translateY({{translateVal}});">
  </div>
  <div class="row">
    <button type="capsule" value="play" onclick="playAnimation"></button>
    <button type="capsule" value="update" onclick="updateAnimation"></button>
  </div>
  <div class="row1">
    <button type="capsule" value="pause" onclick="pauseAnimation"></button>
    <button type="capsule" value="finish" onclick="finishAnimation"></button>
  </div>
  <div class="row2">
    <button type="capsule" value="cancel" onclick="cancelAnimation"></button>
    <button type="capsule" value="reverse" onclick="reverseAnimation"></button>
  </div>
</div>
```

```css
/* xxx.css */
button{
  width: 200px;
}
.row{
  width: 65%;
  height: 100px;
  align-items: center;
  justify-content: space-between;
  margin-top: 150px;
  position: fixed;
  top: 52%;
  left: 120px;
}
.row1{
  width: 65%;
  height: 100px;
  align-items: center;
  justify-content: space-between;
  margin-top: 120px;
  position: fixed;
  top: 65%;
  left: 120px;
}
.row2{
  width: 65%;
  height: 100px;
  align-items: center;
  justify-content: space-between;
  margin-top: 100px;
  position: fixed;
  top: 75%;
  left: 120px;
}
```

```js
// xxx.js
import animator from '@ohos.animator';
import promptAction from '@ohos.promptAction';
export default {
  data: {
    scaleVal:1,
    DivWidth:200,
    DivHeight:200,
    translateVal:0,
    animation: null
  },
  onInit() {
    var options = {
      duration: 3000,
      fill: 'forwards',
      begin: 200,
      end: 270
    };
    this.animation = animator.createAnimator(options);
  },
  onShow() {
    var _this= this;
    // Add an animation repeat event.
    this.animation.onrepeat = function() {
      promptAction.showToast({
        message: 'repeat'
      });
      var repeatoptions = {
        duration: 2000,
        iterations: 1,
         direction: 'alternate',
         begin: 180,
         end: 240
       };
        _this.animation.update(repeatoptions);
        _this.animation.play();
      };
  },
  playAnimation() {
    var _this= this;
    // Add the frame-by-frame interpolation callback event for the animation.
    this.animation.onframe = function(value) {
      _this. scaleVal= value/150,
      _this.DivWidth = value,
      _this.DivHeight = value,
      _this.translateVal = value-180
    };
    this.animation.play();
  },
  updateAnimation() {
    var newoptions = {
      duration: 5000,
      iterations: 2,
      begin: 120,
      end: 180
    };
    this.animation.update(newoptions);
    this.animation.play();// Play this animation.
  },
  pauseAnimation() {
    this.animation.pause();// Pause this animation.
  },
  finishAnimation() {
    var _this= this;
   // Add an animation completion event.
    this.animation.onfinish = function() {
      promptAction.showToast({
        message: 'finish'
      })
    };
    this.animation.finish(); // Finish this animation.
  },
  cancelAnimation() {
    this.animation.cancel(); // Cancel this animation.
  },
  reverseAnimation() {
    this.animation.reverse(); // Reverse this animation.
  }
}
```

![en-us_image_0000001223287724](figures/en-us_image_0000001223287724.gif)

> **NOTE**
>
> When calling the update method, you can use it to update the animation parameters. The input parameters are the same as those of createAnimator.
