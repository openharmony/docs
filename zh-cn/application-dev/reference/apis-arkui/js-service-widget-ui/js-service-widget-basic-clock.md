# clock


时钟组件，用于提供时钟表盘界面。

> **说明：**
>
> 从API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

不支持。


## 属性

除支持[通用属性](js-service-widget-common-attributes.md)外，还支持如下属性：

| 名称          | 类型          | 默认值  | 必填   | 描述                                       |
| ----------- | ----------- | ---- | ---- | ---------------------------------------- |
| clockconfig | ClockConfig | -    | 是    | Clock的图片资源和样式设置，包括日间时段（6:00-18:00）和夜间时段（18:00-次日6:00）两套资源和样式设置。<br/>其中每套资源和样式包括表盘资源、时针指针资源、分针指针资源、秒针指针资源四张图和相应时间段的表盘数字颜色。<br/>日间资源为必填项。夜间资源可不填，不填时默认会复用日间资源用作夜间时段的显示。<br/>仅支持动态更新整个Object，不支持动态更新Object里的内容。<br/>建议使用PNG资源作为Clock组件的图片资源。<br/>不支持使用SVG资源作为Clock组件的图片资源。 |
| showdigit   | boolean     | true | 否    | 是否由Clock组件绘制表盘数字。<br/>该属性为true时，请留意clockconfig中digitRadiusRatio和digitSizeRatio参数与表盘的匹配情况。<br/>由Clock组件绘制的表盘数字支持国际化。 |
| hourswest   | number      | -    | 否    | 时钟的时区偏移值，时区为标准时区减去hourswest。<br/>有效范围为[-12,&nbsp;12]，其中负值范围表示东时区，比如东八区对应的是-8。不设置默认采用系统时间所在的时区。 |

  **表1** ClockConfig

| 名称               | 类型             | 默认值             | 必填   | 描述                                       |
| ---------------- | -------------- | --------------- | ---- | ---------------------------------------- |
| face             | &lt;string&gt; | -               | 是    | 日间时段的表盘资源路径。<br/>表盘资源须为包含时钟刻度的正方形图片，表盘区域（圆形）为该图片的内切圆或内切圆的同心圆。如果表盘区域为表盘资源内切圆的同心圆的话，请相应调整digitRadiusRatio和digitSizeRatio参数。 |
| hourHand         | &lt;string&gt; | -               | 是    | 日间时段的时针资源路径。<br/>- 时针图片的高度须与表盘资源高度相同。<br/>- 时针图片的宽高比建议在0.062。<br/>- 时针图片上指针的旋转中心须处于时针图片的中心（对角线交点）。<br/>- 夜间时段的时针资源请调整hourHandNight参数。 |
| minuteHand       | &lt;string&gt; | -               | 是    | 日间时段的分针资源路径。<br/>- 分针图片的高度须与表盘资源高度相同。<br/>- 分针图片的宽高比建议在0.062。<br/>- 分针图片上指针的旋转中心须处于分针图片的中心（对角线交点）。<br/>-&nbsp;夜间时段的分针资源请调整minuteHandNight参数。 |
| secondHand       | &lt;string&gt; | -               | 是    | 日间时段的秒针资源路径。<br/>- &nbsp;秒针图片的高度须与表盘资源高度相同。<br/>-&nbsp;秒针图片的宽高比建议在0.062。<br/>-&nbsp;秒针图片上指针的旋转中心须处于秒针图片的中心（对角线交点）。<br/>- 夜间时段的秒针资源请调整secondHandNightSrc参数。 |
| digitColor       | &lt;color&gt;  | \#FF000000      | 否    | 日间时段（6:00-18:00）的表盘文本颜色。                 |
| digitColorNight  | &lt;color&gt;  | 与digitColor保持一致 | 否    | 夜间时段（18:00-次日6:00）的表盘文本颜色。<br/>- 该属性未设置时，取digitColor的值作为digitColorNight的值（digitColor被设置时，取digitColor被设置的值）。<br/>- 请注意缺省状态下使用digitColor的值作为digitColorNight的值时，夜间时段表盘文本颜色与夜间时段表盘背景（faceNight）的颜色配合问题。 |
| faceNight        | &lt;string&gt; | -               | 否    | 夜间时段的表盘资源路径。<br/>未设置时使用face的资源路径作为夜间时段的表盘资源路径。 |
| hourHandNight    | &lt;string&gt; | -               | 否    | 夜间时段的时针资源路径。<br/>未设置时使用hourHand的资源路径作为夜间时段的时针资源路径。 |
| minuteHandNight  | &lt;string&gt; | -               | 否    | 夜间时段的分针资源路径。<br/>设置时使用minuteHand的资源路径作为夜间时段的分针资源路径。 |
| secondHandNight  | &lt;string&gt; | -               | 否    | 夜间时段的秒针资源路径。<br/>未设置时使用secondHand的资源路径作为夜间时段的秒针资源路径。 |
| digitRadiusRatio | number         | 0.7             | 否    | 表盘数字中心到表盘中心距离&nbsp;/&nbsp;表盘资源边长的一半。<br/>- 有效范围为(0,&nbsp;1]。<br/>- 该参数用于计算表盘数字在表盘上距离圆心的位置。<br/>- 该参数可以保证同一套表盘资源在不同组件尺寸下都有同样的相对位置，而不需要针对每个组件尺寸都重新调整数字位置。<br/>- 该参数设为1时数字会有部分区域超出表盘，建议结合表盘区域合理设置digitRadiusRatio。 |
| digitSizeRatio   | number         | 0.08            | 否    | 表盘数字尺寸/表盘资源边长。<br/>- 有效范围为(0,&nbsp;0.142]。<br/>- 该参数用于计算表盘数字相对表盘尺寸的大小。<br/>- 该参数可以保证同一套表盘资源在不同组件尺寸下都有同样的相对大小，而不需要针对每个组件尺寸都重新调整字号。 |

![clock](figures/clock.png)


## 样式

除支持[通用样式](js-service-widget-common-styles.md)之外，还支持如下样式：

| 名称          | 类型             | 默认值        | 必填   | 描述                                       |
| ----------- | -------------- | ---------- | ---- | ---------------------------------------- |
| font-family | &lt;string&gt; | sans-serif | 否    | 表盘数字的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过2.1.6&nbsp;自定义字体样式指定的字体，会被选中作为文本的字体。 |

>  **说明：**
>
>  clock组件会保持显示区域的宽高比为1，最终正方形显示区域的边长为min(width, height)，在width \* height的组件区域中居中显示。


## 事件

| 名称   | 参数                  | 描述        |
| ---- | ------------------- | --------- |
| hour | {hour:&nbsp;number} | 每个整点触发该事件 |


## 示例


```html
<!-- xxx.hml -->
<div class="container">
    <div class="row">
        <clock class="clk" style="font-family:Courier;" hourswest="-8" clockconfig="{{clockconfig}}">
        </clock>
        <clock class="clk" style="font-family:Courier;" hourswest="4" clockconfig="{{clockconfig}}">
        </clock>
    </div>
</div>
```


```css
/* xxx.css */ 
.container {
    flex-direction:column;
    align-items:center;
}
.clk {
    width:350px;
    height:350px;
}
.row {
    flex-direction:row;
    align-items:center;
    justify-content: space-around;
    border-radius: 40px;
    padding-top: 20px;
    padding-bottom: 20px;
    background-color: #4169E1;
}
```


```json
{
  "data": {
    "clockconfig": {
      "digitRadiusRatio": 0.7,
      "digitSizeRatio": 0.08,
      "face": "common/clock_widget.png",
      "hourHand": "common/clock_widget_hour.png",
      "minuteHand": "common/clock_widget_minute.png",
      "secondHand": "common/clock_widget_second.png",
      "faceNight": "common/black_clock_widget.png",
      "hourHandNight": "common/black_clock_widget_hour.png",
      "minuteHandNight": "common/black_clock_widget_minute.png",
      "digitColor": "#000000",
      "digitColorNight": "#FFFFFF"
    }
  }
}
```
**2*4卡片**

![clockshow](figures/clockshow.png)

