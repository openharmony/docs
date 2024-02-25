# panel

>  **说明：**
>  从API version 5开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

可滑动面板，提供一种轻量的内容展示窗口，在不同尺寸中切换，属于弹出式组件。


## 子组件

支持


## 属性

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

| 名称         | 类型             | 默认值      | 必填   | 描述                                       |
| ---------- | -------------- | -------- | ---- | ---------------------------------------- |
| type       | string         | foldable | 是    | 设置可滑动面板类型，不可动态变更，可选值有：<br/>-&nbsp;minibar：提供minibar和类全屏展示切换效果。<br/>-&nbsp;foldable：内容永久展示类，提供大（类全屏）、中（类半屏）、小三种尺寸展示切换效果。<br/>-&nbsp;temporary：内容临时展示区，提供大（类全屏）、中（类半屏）两种尺寸展示切换效果。 |
| mode       | string         | full     | 否    | 设置初始状态，mode参数可选值为：<br/>1.&nbsp;mini：类型为minibar和foldable时，为最小状态；类型为temporary，则不生效。<br/>2.&nbsp;half:&nbsp;类型为foldable和temporary时，为类半屏状态；类型为minibar，则不生效。<br/>3.&nbsp;full:&nbsp;类全屏状态。 |
| dragbar    | boolean        | true     | 否    | 设置是否存在dragbar，true表示存在，false表示不存在。       |
| fullheight | &lt;length&gt; | -        | 否    | 指定full状态下的高度，默认为屏幕尺寸&nbsp;-&nbsp;8px。    |
| halfheight | &lt;length&gt; | -        | 否    | 指定half状态下的高度，默认为屏幕尺寸的一半。                 |
| miniheight | &lt;length&gt; | -        | 否    | 指定mini状态下的高度，默认为48px。                    |

>  **说明：**
>  - 不支持渲染属性，包括for、if和show。
>
>  - 不支持focusable和disabled属性。


## 样式

仅支持如下样式：

| 名称                                       | 类型                                       | 默认值          | 必填   | 描述                                       |
| ---------------------------------------- | ---------------------------------------- | ------------ | ---- | ---------------------------------------- |
| padding                                  | &lt;length&gt;                           | 0            | 否    | 该属性可以有1到4个值：<br/>-&nbsp;指定一个值时，该值指定四个边的内边距。<br/>-&nbsp;指定两个值时，第一个值指定上下两边的内边距，第二个指定左右两边的内边距。<br/>-&nbsp;指定三个值时，第一个指定上边的内边距，第二个指定左右两边的内边距，第三个指定下边的内边距。<br/>-&nbsp;指定四个值时分别为上、右、下、左边的内边距（顺时针顺序）。 |
| padding-[left\|top\|right\|bottom]       | &lt;length&gt;                           | 0            | 否    | 设置左、上、右、下内边距属性。                          |
| padding-[start\|end]                     | &lt;length&gt;                           | 0            | 否    | 设置起始和末端内边距属性。                            |
| margin                                   | &lt;length&gt;                           | 0            | 否    | 使用简写属性设置所有的外边距属性，该属性可以有1到4个值。<br/>-&nbsp;只有一个值时，这个值会被指定给全部的四个边。<br/>-&nbsp;两个值时，第一个值被匹配给上和下，第二个值被匹配给左和右。<br/>-&nbsp;三个值时，第一个值被匹配给上,&nbsp;第二个值被匹配给左和右，第三个值被匹配给下。<br/>-&nbsp;四个值时，会依次按上、右、下、左的顺序匹配&nbsp;(即顺时针顺序)。 |
| margin-[left\|top\|right\|bottom]        | &lt;length&gt;                           | 0            | 否    | 设置左、上、右、下外边距属性。                          |
| margin-[start\|end]                      | &lt;length&gt;                           | 0            | 否    | 设置起始和末端外边距属性。                            |
| border                                   | -                                        | 0            | 否    | 使用简写属性设置所有的边框属性，包含边框的宽度，样式，颜色属性，顺序设置为border-width、border-style、border-color，不设置时，各属性值为默认值。 |
| border-style                             | string                                   | solid        | 否    | 使用简写属性设置所有边框的样式，可选值为：<br/>-&nbsp;dotted：显示为一系列圆点，圆点半径为border-width的一半。<br/>-&nbsp;dashed：显示为一系列短的方形虚线。<br/>-&nbsp;solid：显示为一条实线。 |
| border-[left\|top\|right\|bottom]-style  | string                                   | solid        | 否    | 分别设置左、上、右、下四个边框的样式，可选值为dotted、dashed、solid。 |
| border-[left\|top\|right\|bottom]        | -                                        | -            | 否    | 使用简写属性设置对应位置的边框属性，包含边框的宽度，样式，颜色属性，顺序设置为border-width、border-style、border-color，不设置的值为默认值。 |
| border-width                             | &lt;length&gt;                           | 0            | 否    | 使用简写属性设置元素的所有边框宽度，或者单独为各边边框设置宽度。         |
| border-[left\|top\|right\|bottom]-width  | &lt;length&gt;                           | 0            | 否    | 分别设置左、上、右、下四个边框的宽度。                      |
| border-color                             | &lt;color&gt;                            | black        | 否    | 使用简写属性设置元素的所有边框颜色，或者单独为各边边框设置颜色。         |
| border-[left\|top\|right\|bottom]-color  | &lt;color&gt;                            | black        | 否    | 分别设置左、上、右、下四个边框的颜色。                      |
| border-radius                            | &lt;length&gt;                           | -            | 否    | border-radius属性是设置元素的外边框圆角半径。设置border-radius时不能单独设置某一个方向的border-[left\|top\|right\|bottom]-width，border-[left\|top\|right\|bottom]-color&nbsp;，如果要设置color和width，需要将四个方向一起设置（border-width、border-color）。 |
| border-[top\|bottom]-[left\|right]-radius | &lt;length&gt;                           | -            | 否    | 分别设置左上，右上，右下和左下四个角的圆角半径。                 |
| background                               | &lt;linear-gradient&gt;                  | -            | 否    | 仅支持设置[渐变样式](js-components-common-gradient.md)，与background-color、background-image不兼容。 |
| background-color                         | &lt;color&gt;                            | -            | 否    | 设置背景颜色。                                  |
| background-image                         | string                                   | -            | 否    | 设置背景图片。与background-color、background不兼容；支持本地图片资源地址。 |
| background-size                          | -&nbsp;string<br/>-&nbsp;&lt;length&gt;&nbsp;&lt;length&gt;<br/>-&nbsp;&lt;percentage&gt;&nbsp;&lt;percentage&gt; | auto         | 否    | 设置背景图片的大小。<br/>-&nbsp;string可选值：<br/>&nbsp;&nbsp;-&nbsp;contain：把图像扩展至最大尺寸，以使其高度和宽度完全适用内容区域。<br/>&nbsp;&nbsp;-&nbsp;cover：把背景图像扩展至足够大，以使背景图像完全覆盖背景区域；背景图像的某些部分也许无法显示在背景定位区域中。<br/>&nbsp;&nbsp;-&nbsp;auto：保持原图的比例不变。<br/>-&nbsp;length值参数方式：<br/>&nbsp;&nbsp;设置背景图像的高度和宽度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为&nbsp;"auto"。<br/>-&nbsp;百分比参数方式：<br/>&nbsp;&nbsp;以父元素的百分比来设置背景图像的宽度和高度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为&nbsp;"auto"。 |
| background-repeat                        | string                                   | repeat       | 否    | 针对重复背景图像样式进行设置，背景图像默认在水平和垂直方向上重复。<br/>-&nbsp;repeat：在水平轴和竖直轴上同时重复绘制图片。<br/>-&nbsp;repeat-x：只在水平轴上重复绘制图片。<br/>-&nbsp;repeat-y：只在竖直轴上重复绘制图片。<br/>-&nbsp;no-repeat：不会重复绘制图片。 |
| background-position                      | -&nbsp;string&nbsp;string<br/>-&nbsp;&lt;length&gt;&nbsp;&lt;length&gt;<br/>-&nbsp;&lt;percentage&gt;&nbsp;&lt;percentage&gt; | 0px&nbsp;0px | 否    | -&nbsp;关键词方式：如果仅规定了一个关键词，那么第二个值为"center"。两个值分别定义水平方向位置和竖直方向位置。<br/>&nbsp;&nbsp;-&nbsp;left：水平方向上最左侧。<br/>&nbsp;&nbsp;-&nbsp;right：水平方向上最右侧。<br/>&nbsp;&nbsp;-&nbsp;top：竖直方向上最顶部。<br/>&nbsp;&nbsp;-&nbsp;bottom：竖直方向上最底部。<br/>&nbsp;&nbsp;-&nbsp;center：水平方向或竖直方向上中间位置。<br/>-&nbsp;length值参数方式：第一个值是水平位置，第二个值是垂直位置。&nbsp;左上角是&nbsp;0&nbsp;0。单位是像素&nbsp;(0px&nbsp;0px)&nbsp;&nbsp;。如果仅规定了一个值，另外一个值将是50%。<br/>-&nbsp;百分比参数方式：第一个值是水平位置，第二个值是垂直位置。左上角是&nbsp;0%&nbsp;0%。右下角是&nbsp;100%&nbsp;100%。如果仅规定了一个值，另外一个值为50%。<br/>-&nbsp;可以混合使用&lt;percentage&gt;和&lt;length&gt; |
| opacity                                  | number                                   | 1            | 否    | 元素的透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。        |


## 事件

仅支持如下事件：

| 名称         | 参数                                       | 描述                                       |
| ---------- | ---------------------------------------- | ---------------------------------------- |
| sizechange | {&nbsp;size:&nbsp;{&nbsp;height:&nbsp;heightLength,&nbsp;width:&nbsp;widthLength&nbsp;},&nbsp;mode:&nbsp;modeStr&nbsp;} | 当可滑动面板发生状态变化时触发，mode参数可选值为：<br/>- &nbsp;mini：类型为minibar和foldable时，处于最小状态；<br/>- &nbsp;half:&nbsp;类型为foldable时，处于类半屏状态；<br/>- &nbsp;full:&nbsp;类全屏状态。<br/>返回的height值为内容区高度值，当dragbar属性为true时，panel本身的高度值为dragbar高度加上内容区高度。 |


## 方法

仅支持如下方法：

| 名称    | 参数   | 描述            |
| ----- | ---- | ------------- |
| show  | -    | 弹出panel可滑动面板。 |
| close | -    | 关闭panel可滑动面板。 |


## 示例

```html
<!-- xxx.hml -->
<div class="doc-page">
    <div class="btn-div">
        <button type="capsule" value="Click here" onclick="showPanel"></button>
    </div>
    <panel id="simplepanel" type="foldable" mode="half" onsizechange="changeMode" miniheight="200px">
        <div class="panel-div">
            <div class="inner-txt">
                <text class="txt">Simple panel in {{ modeFlag }} mode</text>
            </div>
            <div class="inner-btn">
                <button type="capsule" value="Close" onclick="closePanel"></button>
            </div>
        </div>
    </panel>
</div>
```

```css
/* xxx.css */
.doc-page {
    flex-direction: column;
    justify-content: center;
    align-items: center;
}

.btn-div {
    width: 100%;
    height: 200px;
    flex-direction: column;
    align-items: center;
    justify-content: center;
}

.txt {
    color: #000000;
    font-weight: bold;
    font-size: 39px;
}

.panel-div {
    width: 100%;
    flex-direction: column;
    align-items: center;
}

.inner-txt {
    width: 100%;
    height: 160px;
    flex-direction: column;
    align-items: center;
    justify-content: center;
}

.inner-btn {
    width: 100%;
    height: 120px;
    justify-content: center;
    align-items: center;
}
```

```js
// xxx.js
export default {
  data: {
    modeFlag: "half"
  },
  showPanel() {
    this.$element('simplepanel').show()
  },
  closePanel() {
    this.$element('simplepanel').close()
  },
  changeMode(e) {
    this.modeFlag = e.mode
  }
}
```

![zh-cn_image_0000001173164785](figures/zh-cn_image_0000001173164785.gif)
