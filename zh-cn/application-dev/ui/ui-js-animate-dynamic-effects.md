# 动画动效
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @yangfan229-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->


通过设置插值器来实现动画效果。


## 创建动画对象

通过createAnimator创建一个动画对象，通过设置参数options来设置动画的属性。

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
    };//设置参数
    this.animation = this.getUIContext().createAnimator(options);//创建动画
  },
  playAnimation() {
    var _this = this;
    this.animation.onframe = function(value) {
      _this.translateVal= value;
    };
    this.animation.play();
  }
}
```

![zh-cn_image_0000001174756776](figures/zh-cn_image_0000001174756776.gif)

> **说明：**
> - 使用createAnimator创建动画对象时必须传入options参数。
>
> - begin插值起点，不设置时默认为0。
>
> - end插值终点，不设置时默认为1。


## 添加动画事件和调用接口

animator支持事件和接口，可以通过添加frame、cancel、repeat、finish事件和调用update、play、pause、cancel、reverse、finish接口自定义动画效果。animator支持的事件和接口具体见动画中的[createAnimator](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#createanimator)。

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
export default {
  data: {
    scaleVal:1,
    DivWidth:200,
    DivHeight:200,
    translateVal:0,
    animation: null
  },
  onInit() {},
  onShow() {
    var options = {
      duration: 3000,
      fill: 'forwards',
      begin: 200,
      end: 270
    };
    this.animation = this.getUIContext().createAnimator(options);
    var _this= this;
    //添加动画重放事件
    this.animation.onrepeat = function() {
      this.getUIContext().getPromptAction().showToast({
        message: 'repeat'
      });
      var repeatOptions = {
        duration: 2000,
        iterations: 1,
         direction: 'alternate',
         begin: 180,
         end: 240
       };
        _this.animation?.update(repeatOptions);
        _this.animation?.play();
      };
  },
  playAnimation() {
    var _this= this;
    //添加动画逐帧插值回调事件
    this.animation.onframe = function(value) {
      _this.scaleVal= value/150,
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
    this.animation.play();//调用动画播放接口
  },
  pauseAnimation() {
    this.animation.pause();//调用动画暂停接口
  },
  finishAnimation() {
    var _this= this;
   //添加动画完成事件
    this.animation.onfinish = function() {
      this.getUIContext().getPromptAction().showToast({
        message: 'finish'
      });
    };
    this.animation.finish(); //调用动画完成接口
  },
  cancelAnimation() {
    this.animation.cancel(); //调用动画取消接口
  },
  reverseAnimation() {
    this.animation.reverse(); //调用动画倒放接口
  }
}
```

![zh-cn_image_0000001220635059](figures/zh-cn_image_0000001220635059.gif)

> **说明：** 
>
> 在调用[reset](../reference/apis-arkui/js-apis-animator.md#reset9)接口的过程中可以使用这个接口更新动画参数，入参与[createAnimator](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#createanimator)一致。
