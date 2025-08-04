# 手势事件
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--SE: @piggyguy-->
<!--TSE: @songyanhong-->

手势表示由单个或多个事件识别的语义动作（例如：触摸、点击和长按）。一个完整的手势也可能由多个事件组成，对应手势的生命周期。支持的事件有：

**触摸**
- touchstart：手指触摸动作开始。

- touchmove：手指触摸后移动。

- touchcancel：手指触摸动作被打断，如来电提醒、弹窗。

- touchend：手指触摸动作结束。

**点击**

click：用户快速轻敲屏幕。

**长按**

longpress：用户在相同位置长时间保持与屏幕接触。

具体的使用示例如下：

```html
<!-- xxx.hml -->
<div class="container">
  <div class="text-container" onclick="click">
    <text class="text-style">{{onClick}}</text>
  </div>
  <div class="text-container" ontouchstart="touchStart">
    <text class="text-style">{{touchstart}}</text>
  </div>
  <div class="text-container" ontouchmove="touchMove">
    <text class="text-style">{{touchmove}}</text>
  </div>
  <div class="text-container" ontouchend="touchEnd">
    <text class="text-style">{{touchend}}</text>
  </div>
  <div class="text-container" ontouchcancel="touchCancel">
    <text class="text-style">{{touchcancel}}</text>
  </div>
  <div class="text-container" onlongpress="longPress">
    <text class="text-style">{{onLongPress}}</text>
  </div>
</div>
```

```css
/* xxx.css */
.container {
  width: 100%;
  height: 100%;
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
.text-container {
  margin-top: 30px;
  flex-direction: column;
  width: 600px;
  height: 70px;
  background-color: #0000FF;
}
.text-style {
  width: 100%;
  line-height: 50px;
  text-align: center;
  font-size: 24px;
  color: #ffffff;
}
```

```js
// xxx.js
export default {
  data: {
    touchstart: 'touchstart',
    touchmove: 'touchmove',
    touchend: 'touchend',
    touchcancel: 'touchcancel',
    onClick: 'onclick',
    onLongPress: 'onlongpress',
  },
  touchCancel: function (event) {
    this.touchcancel = 'canceled';
  },
  touchEnd: function(event) {
    this.touchend = 'ended';
  },
  touchMove: function(event) {
    this.touchmove = 'moved';
  }, 
  touchStart: function(event) {
    this.touchstart = 'touched';
  },
  longPress: function() {
    this.onLongPress = 'longpressed';
  },
  click: function() {
    this.onClick = 'clicked';
  },
}
```

![zh-cn_image_00000011](figures/zh-cn_image_00000011.gif)