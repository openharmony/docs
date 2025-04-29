# picker-view

嵌入页面的滑动选择器。

> **说明：**
>
> 该组件从API version 4 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

不支持。


## 属性

| 名称 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| type | string | text | 否 | 设置滑动选择器的类型，该属性不支持动态修改，可选项有：<br/>-&nbsp;text：文本选择器。<br/>-&nbsp;time：时间选择器。 |
| id | string | - | 否 | 组件的唯一标识。 |
| style | string | - | 否 | 组件的样式声明。 |
| class | string | - | 否 | 组件的样式类，用于引用样式表。 |
| ref | string | - | 否 | 用来指定指向子元素的引用信息，该引用将注册到父组件的$refs&nbsp;属性对象上。 |

文本选择器：type=text

| 名称 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| range | Array | - | 否 | 设置文本选择器的取值范围。<br/>使用时需要使用数据绑定的方式，如range&nbsp;=&nbsp;{{data}}，js中声明相应变量：data：["15",&nbsp;"20",&nbsp;"25"]。 |
| selected | string | 0 | 否 | 设置文本选择器的默认选择值，该值需要为range的索引。 |

时间选择器：type=time

| 名称 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| selected | string | 00:00 | 否 | 设置时间选择器的默认取值，格式为&nbsp;HH:mm；<br/> |


## 事件

type=text：

| 名称 | 参数 | 描述 |
| -------- | -------- | -------- |
| change | {&nbsp;newValue:&nbsp;newValue,&nbsp;newSelected:&nbsp;newSelected&nbsp;} | 文本选择器选定值后触发该事件。 |

type=time：

| 名称 | 参数 | 描述 |
| -------- | -------- | -------- |
| change | {&nbsp;hour:&nbsp;hour,&nbsp;minute:&nbsp;minute} | 时间选择器选定值后触发该事件。<br/> |


## 样式

| 名称 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| color | &lt;color&gt; | \#808080<br/> | 否 | 候选项字体颜色。 |
| font-size | &lt;length&gt; | 30px<br/> | 否 | 候选项字体尺寸，类型length，单位px。 |
| selected-color | &lt;color&gt; | \#ffffff<br/> | 否 | 选中项字体颜色。 |
| selected-font-size | &lt;length&gt; | 38px<br/> | 否 | 选中项字体尺寸，类型length，单位px。 |
| selected-font-family | string | HYQiHei-65S | 否 | 选中项字体类型。 |
| font-family | string | <br/>HYQiHei-65S | 否 | 选项字体类型。 |
| width | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | - | 否 | 设置组件自身的宽度。<br/>未设置时组件宽度默认为0。 |
| height | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | - | 否 | 设置组件自身的高度。<br/>未设置时组件高度默认为0。 |
| padding | &lt;length&gt; | 0 | 否 | 使用简写属性设置所有的内边距属性。<br/>&nbsp;&nbsp;该属性可以有1到4个值：<br/>-&nbsp;指定一个值时，该值指定四个边的内边距。<br/>-&nbsp;指定两个值时，第一个值指定上下两边的内边距，第二个指定左右两边的内边距。<br/>-&nbsp;指定三个值时，第一个指定上边的内边距，第二个指定左右两边的内边距，第三个指定下边的内边距。<br/>-&nbsp;指定四个值时分别为上、右、下、左边的内边距（顺时针顺序）。 |
| padding-[left\|top\|right\|bottom] | &lt;length&gt; | 0 | 否 | 设置左、上、右、下内边距属性。 |
| margin | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | 0 | 否 | 使用简写属性设置所有的外边距属性，该属性可以有1到4个值。<br/>-&nbsp;只有一个值时，这个值会被指定给全部的四个边。<br/>-&nbsp;两个值时，第一个值被匹配给上和下，第二个值被匹配给左和右。<br/>-&nbsp;三个值时，第一个值被匹配给上,&nbsp;第二个值被匹配给左和右，第三个值被匹配给下。<br/>-&nbsp;四个值时，会依次按上、右、下、左的顺序匹配&nbsp;(即顺时针顺序)。 |
| margin-[left\|top\|right\|bottom] | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | 0 | 否 | 设置左、上、右、下外边距属性。 |
| border-width | &lt;length&gt; | 0 | 否 | 使用简写属性设置元素的所有边框宽度。 |
| border-color | &lt;color&gt; | black | 否 | 使用简写属性设置元素的所有边框颜色。 |
| border-radius | &lt;length&gt; | - | 否 | border-radius属性是设置元素的外边框圆角半径。 |
| background-color | &lt;color&gt; | - | 否 | 设置背景颜色。 |
| display | string | flex | 否 | 确定一个元素所产生的框的类型，可选值为：<br/>-&nbsp;flex：弹性布局。<br/>-&nbsp;none：不渲染此元素。 |
| [left\|top] | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>6+</sup> | - | 否 | left\|top确定元素的偏移位置。<br/>-&nbsp;left属性规定元素的左边缘。该属性定义了定位元素左外边距边界与其包含块左边界之间的偏移。<br/>-&nbsp;top属性规定元素的顶部边缘。该属性定义了一个定位元素的上外边距边界与其包含块上边界之间的偏移。 |


## 示例


```html
<!-- xxx.hml -->
<div class="container" @swipe="handleSwipe">
  <text class="title">
    Selected：{{time}}
  </text>
  <picker-view class="time-picker" type="time" selected="{{defaultTime}}" @change="handleChange"></picker-view>
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
.title {
  font-size: 30px;
  text-align: center;
}
.time-picker {
  width: 500px;
  height: 400px;
  margin-top: 20px;
}
```


```js
/* xxx.js */
export default {
  data: {
    defaultTime: "",
    time: "",
  },
  onInit() {
    this.defaultTime = this.now();
  },
  handleChange(data) {
    this.time = this.concat(data.hour, data.minute);
  },
  now() {
    const date = new Date();
    const hours = date.getHours();
    const minutes = date.getMinutes();
    return this.concat(hours, minutes);
  },

  fill(value) {
    return (value > 9 ? "" : "0") + value;
  },

  concat(hours, minutes) {
    return `${this.fill(hours)}:${this.fill(minutes)}`;
  },
}
```

![picker-view](figures/picker-view-lite.png)