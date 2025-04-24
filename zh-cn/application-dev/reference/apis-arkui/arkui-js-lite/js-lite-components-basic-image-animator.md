# image-animator

图片帧动画播放器。

> **说明：**
>
> 该组件从从API version 4 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

不支持。


## 属性

| 名称                  | 类型                       | 默认值   | 必填 | 描述                                                         |
| --------------------- | -------------------------- | -------- | ---- | ------------------------------------------------------------ |
| images                | Array&lt;ImageFrame&gt;    | -        | 是   | 设置图片帧信息集合。每一帧的帧信息包含图片路径、图片大小和图片位置信息。目前支持以下图片格式：png、jpg和bmp。ImageFrame的详细说明请见表1。<br/>**说明：**<br/>1.使用时需要使用数据绑定的方式，如images&nbsp;=&nbsp;{{images}}，js中声明相应变量：images:&nbsp;[{src:&nbsp;"/common/heart-rate01.png"},&nbsp;{src:&nbsp;"/common/heart-rate02.png"}]。<br/>2.部分轻量级设备不支持原图片格式的解析。所以，在应用编译阶段，图片会被直接编译为可解析的位图（总字节数约：图片长x宽x4），并打包在应用安装包里，这会增加安装包的大小。因此，在使用图片资源时，应尽量控制图片的分辨率，尺寸越大的图片对于空间的占用越明显。 |
| iteration             | number&nbsp;\|&nbsp;string | infinite | 否   | 设置帧动画播放次数。number表示固定次数，infinite枚举表示无限次数播放。 |
| reverse               | boolean                    | false    | 否   | 设置播放顺序。false表示从第1张图片播放到最后1张图片；&nbsp;true表示从最后1张图片播放到第1张图片。 |
| fixedsize             | boolean                    | true     | 否   | 设置图片大小是否固定为组件大小。&nbsp;true表示图片大小与组件大小一致，此时设置图片的width&nbsp;、height&nbsp;、top&nbsp;和left属性是无效的。false表示每一张图片的&nbsp;width&nbsp;、height&nbsp;、top和left属性都要单独设置。 |
| duration              | string                     | -        | 是   | 设置单次播放时长。单位支持[s(秒)\|ms(毫秒)]，默认单位为ms。&nbsp;duration为0时，不播放图片。&nbsp;值改变只会在下一次循环开始时生效。 |
| fillmode<sup>5+</sup> | string                     | forwards | 否   | 指定帧动画执行结束后的状态。可选项有：<br/>-&nbsp;none：恢复初始状态。<br/>-&nbsp;forwards：保持帧动画结束时的状态（在最后一个关键帧中定义）。 |
| id                    | string                     | -        | 否   | 组件的唯一标识。                                             |
| style                 | string                     | -        | 否   | 组件的样式声明。                                             |
| class                 | string                     | -        | 否   | 组件的样式类，用于引用样式表。                               |
| ref                   | string                     | -        | 否   | 用来指定指向子元素的引用信息，该引用将注册到父组件的$refs&nbsp;属性对象上。 |

  **表1** ImageFrame说明

| 名称     | 类型             | 默认值  | 必填   | 描述               |
| ------ | -------------- | ---- | ---- | ---------------- |
| src    | &lt;uri&gt;    | -    | 是    | 图片路径。            |
| width  | &lt;length&gt; | 0    | 否    | 图片宽度。            |
| height | &lt;length&gt; | 0    | 否    | 图片高度。            |
| top    | &lt;length&gt; | 0    | 否    | 图片相对于组件左上角的纵向坐标。 |
| left   | &lt;length&gt; | 0    | 否    | 图片相对于组件左上角的横向坐标。 |


## 事件

| 名称                 | 参数                                | 描述          |
| ------------------ | --------------------------------- | ----------- |
| stop               | -                                 | 帧动画结束时触发。   |
| click              | -                                 | 点击动作触发该事件。  |
| longpress          | -                                 | 长按动作触发该事件。  |
| swipe<sup>5+</sup> | [SwipeEvent](js-lite-common-events.md) | 组件上快速滑动后触发。 |


## 样式

| 名称                                 | 类型                                       | 默认值   | 必填   | 描述                                       |
| ---------------------------------- | ---------------------------------------- | ----- | ---- | ---------------------------------------- |
| width                              | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | -     | 否    | 设置组件自身的宽度。<br/>未设置时组件宽度默认为0。        |
| height                             | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | -     | 否    | 设置组件自身的高度。<br/>未设置时组件高度默认为0。        |
| padding                            | &lt;length&gt;                           | 0     | 否    | 使用简写属性设置所有的内边距属性。<br/>&nbsp;&nbsp;该属性可以有1到4个值：<br/>-&nbsp;指定一个值时，该值指定四个边的内边距。<br/>-&nbsp;指定两个值时，第一个值指定上下两边的内边距，第二个指定左右两边的内边距。<br/>-&nbsp;指定三个值时，第一个指定上边的内边距，第二个指定左右两边的内边距，第三个指定下边的内边距。<br/>-&nbsp;指定四个值时分别为上、右、下、左边的内边距（顺时针顺序）。 |
| padding-[left\|top\|right\|bottom] | &lt;length&gt;                           | 0     | 否    | 设置左、上、右、下内边距属性。                          |
| margin                             | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | 0     | 否    | 使用简写属性设置所有的外边距属性，该属性可以有1到4个值。<br/>-&nbsp;只有一个值时，这个值会被指定给全部的四个边。<br/>-&nbsp;两个值时，第一个值被匹配给上和下，第二个值被匹配给左和右。<br/>-&nbsp;三个值时，第一个值被匹配给上,&nbsp;第二个值被匹配给左和右，第三个值被匹配给下。<br/>-&nbsp;四个值时，会依次按上、右、下、左的顺序匹配&nbsp;(即顺时针顺序)。 |
| margin-[left\|top\|right\|bottom]  | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | 0     | 否    | 设置左、上、右、下外边距属性。                          |
| border-width                       | &lt;length&gt;                           | 0     | 否    | 使用简写属性设置元素的所有边框宽度。                       |
| border-color                       | &lt;color&gt;                            | black | 否    | 使用简写属性设置元素的所有边框颜色。                       |
| border-radius                      | &lt;length&gt;                           | -     | 否    | border-radius属性是设置元素的外边框圆角半径。            |
| background-color                   | &lt;color&gt;                            | -     | 否    | 设置背景颜色。                                  |
| opacity<sup>5+</sup>               | number                                   | 1     | 否    | 元素的透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。        |
| display                            | string                                   | flex  | 否    | 确定一个元素所产生的框的类型，可选值为：<br/>-&nbsp;flex：弹性布局。<br/>-&nbsp;none：不渲染此元素。 |
| [left\|top]                        | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>6+</sup> | -     | 否    | left\|top确定元素的偏移位置。<br/>-&nbsp;left属性规定元素的左边缘。该属性定义了定位元素左外边距边界与其包含块左边界之间的偏移。<br/>-&nbsp;top属性规定元素的顶部边缘。该属性定义了一个定位元素的上外边距边界与其包含块上边界之间的偏移。 |


## 方法

| 名称       | 参数   | 描述                                       |
| -------- | ---- | ---------------------------------------- |
| start    | -    | 开始播放图片帧动画。再次调用，重新从第1帧开始播放。               |
| pause    | -    | 暂停播放图片帧动画。                               |
| stop     | -    | 停止播放图片帧动画。                               |
| resume   | -    | 继续播放图片帧。                                 |
| getState | -    | 获取播放状态。可能值有：<br/>-&nbsp;playing：播放中<br/>-&nbsp;paused：已暂停<br/>-&nbsp;stopped：已停止。 |


## 示例


```html
<!-- xxx.hml -->
<div class="container">
  <image-animator class="animator" ref="animator" images="{{frames}}" duration="1s" />
  <div class="btn-box">
    <input class="btn" type="button" value="start" @click="handleStart" />
    <input class="btn" type="button" value="stop" @click="handleStop" />
    <input class="btn" type="button" value="pause" @click="handlePause" />
    <input class="btn" type="button" value="resume" @click="handleResume" />
  </div>
</div>
```


```css
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}
.animator {
  width: 70px;
  height: 70px;
}
.btn-box {
  width: 264px;
  height: 120px;
  flex-wrap: wrap;
  justify-content: space-around;
  align-items: center;
}
.btn {
  border-radius: 8px;
  width: 120px;
  margin-top: 8px;
}
```


```js
//xxx.js
export default {
  data: {
    frames: [
      {
        src: "/common/asserts/heart78.png",
      },
      {
        src: "/common/asserts/heart79.png",
      },
      {
        src: "/common/asserts/heart80.png",
      },
      {
        src: "/common/asserts/heart81.png",
      },
      {
        src: "/common/asserts/heart82.png",
      },
      {
        src: "/common/asserts/heart83.png",
      },
      {
        src: "/common/asserts/heart84.png",
      },
      {
        src: "/common/asserts/heart85.png",
      },
      {
        src: "/common/asserts/heart86.png",
      },
      {
        src: "/common/asserts/heart87.png",
      },
      {
        src: "/common/asserts/heart88.png",
      },
      {
        src: "/common/asserts/heart89.png",
      },
      {
        src: "/common/asserts/heart90.png",
      },
      {
        src: "/common/asserts/heart91.png",
      },
      {
        src: "/common/asserts/heart92.png",
      },
      {
        src: "/common/asserts/heart93.png",
      },
      {
        src: "/common/asserts/heart94.png",
      },
      {
        src: "/common/asserts/heart95.png",
      },
      {
        src: "/common/asserts/heart96.png",
      },
    ],
  },
  handleStart() {
    this.$refs.animator.start();
  },
  handlePause() {
    this.$refs.animator.pause();
  },
  handleResume() {
    this.$refs.animator.resume();
  },
  handleStop() {
    this.$refs.animator.stop();
  },
};
```

![image-animator](figures/image-animator-lite.gif)
