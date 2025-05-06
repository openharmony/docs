# Web页面显示内容滚动

当Web页面的内容高度或宽度超过可视区域时，页面才可以滚动，Web页面滚动有很多种方式：控制外接设备、ets侧接口调用、js侧接口调用等方式

## 外接设备
+ 手指触屏滚动
+ 手指触摸板滚动
+ 鼠标滚轮滚动等方

## ets侧接口
+ scrollTo：在指定时间内，将页面滚动到指定的绝对位置，[详见链接](../reference/apis-arkweb/js-apis-webview.md#scrollto)。

  (1) 如果想在滚动中打断，可以通过再次执行一个时间约为0的动画进行强制打断。
  ```ts
  this.controller.scrollBy(0, 0, 1); //如果想停止当前scroll产生的动画，可再次生成一个1ms的动画去打断该动画。
  ```

  (2) 可以实现置顶：scrollTo(0,0);
  ```ts
  this.controller.scrollTo(0, 0);
  ```
+ scrollBy：在指定时间内将页面滚动指定的偏移量，[详见链接](../reference/apis-arkweb/js-apis-webview.md#scrollby)。

  (1) 如果想在滚动中打断，可以通过再次执行一个时间约为0的动画进行强制打断。
  ```ts
  this.controller.scrollBy(0, 0, 1); //如果想停止当前scroll产生的动画，可再次生成一个1ms的动画去打断该动画。
  ```

  (2) 可以作为Web组件嵌套滚动中，控制Web组件滚动的接口：[详见链接](web-nested-scrolling.md#示例2)

+ pageUp：将Webview的内容向上滚动半个视框大小或者跳转到页面最顶部，通过top入参控制，[详见链接](../reference/apis-arkweb/js-apis-webview.md#pageup)。
+ pageDown：将Webview的内容向下滚动半个视框大小或者跳转到页面最底部，通过bottom入参控制，[详见链接](../reference/apis-arkweb/js-apis-webview.md#pagedown)。
## js侧接口
+ scrollBy接口

  ```javascript
  window.scrollBy(deltaX, deltaY);//deltaX是元素要在横轴上滚动的距离，deltaY是元素要在纵轴上滚动的距离。
  ```
+ scrollTo接口
  ```javascript
  window.scrollBy(x, y);//X是你想要显示在左上角的元素沿水平轴的像素，Y是你想要显示在左上角的元素沿垂直轴的像素。
  ```