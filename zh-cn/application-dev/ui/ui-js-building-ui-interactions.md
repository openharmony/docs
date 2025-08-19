# 添加交互
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

添加交互可以通过在组件上关联事件实现。本节将介绍如何用div、text、image组件关联click事件，构建一个如下图所示的点赞按钮。

![zh-cn_image_0000001064068638](figures/zh-cn_image_0000001064068638.gif)


点赞按钮通过一个div组件关联click事件实现。div组件包含一个image组件和一个text组件：


- image组件用于显示未点赞和点赞的效果。click事件函数会交替更新点赞和未点赞图片的路径。

- text组件用于显示点赞数，点赞数会在click事件的函数中同步更新。


click事件作为一个函数定义在js文件中，可以更改isPressed的状态，从而更新显示的image组件。如果isPressed为真，则点赞数加1。该函数在hml文件中对应的div组件上生效，点赞按钮各子组件的样式设置在css文件当中。具体的实现示例如下：


```html
<!-- xxx.hml -->
<!-- 点赞按钮 -->
<div>
  <div class="like" onclick="likeClick">
    <image class="like-img" src="{{likeImage}}" focusable="true"></image>
    <text class="like-num" focusable="true">{{total}}</text>
  </div>
</div>
```


```css
/* xxx.css */
.like {
  width: 104px;
  height: 54px;
  border: 2px solid #bcbcbc;
  justify-content: space-between;
  align-items: center;
  margin-left: 72px;
  border-radius: 8px;
}
.like-img {
  width: 33px;
  height: 33px;
  margin-left: 14px;
}
.like-num {
  color: #bcbcbc;
  font-size: 20px;
  margin-right: 17px;
}
```


```js
// xxx.js
export default {
  data: {
    likeImage: '/common/unLike.png',
    isPressed: false,
    total: 20,
  },
  likeClick() {
    var temp;
    if (!this.isPressed) {
      temp = this.total + 1;
      this.likeImage = '/common/like.png';
    } else {
      temp = this.total - 1;
      this.likeImage = '/common/unLike.png';
    }
    this.total = temp;
    this.isPressed = !this.isPressed;
  },
}
```


除此之外，还提供了很多表单组件，例如开关、标签、滑动选择器等，以便于开发者在页面布局时灵活使用和提高交互性。
