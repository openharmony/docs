# path


>  **说明：**
> 该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

绘制路径。

## 权限列表

无


## 子组件

支持[animate](js-components-svg-animate.md)、[animateMotion](js-components-svg-animatemotion.md)、[animateTransform](js-components-svg-animatetransform.md)。


## 属性

支持Svg组件[通用属性](js-components-svg-common-attributes.md)和以下属性，设置的通用属性会传递给子组件。

| 名称 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| id | string | - | 否 | 组件的唯一标识。 |
| d | string | - | 否 | 设置路径的形状。包含一组字符指令，大写字母为绝对路径，小写字符为相对路径。<br/>字母指令表示的意义如下：<br/>-&nbsp;M/m&nbsp;=&nbsp;moveto<br/>-&nbsp;L/l&nbsp;=&nbsp;lineto<br/>-&nbsp;H/h&nbsp;=&nbsp;horizontal&nbsp;lineto<br/>-&nbsp;V/v&nbsp;=&nbsp;vertical&nbsp;lineto<br/>-&nbsp;C/c&nbsp;=&nbsp;curveto<br/>-&nbsp;S/s&nbsp;=&nbsp;smooth&nbsp;curveto<br/>-&nbsp;Q/q&nbsp;=&nbsp;quadratic&nbsp;Belzier&nbsp;curve<br/>-&nbsp;T/t&nbsp;=&nbsp;smooth&nbsp;quadratic&nbsp;Belzier&nbsp;curveto<br/>-&nbsp;A/a&nbsp;=&nbsp;elliptical&nbsp;Arc<br/>-&nbsp;Z/z&nbsp;=&nbsp;closepath |


## 示例

```html
<!-- xxx.hml -->
<div class="container">
    <svg width="400" height="400">
        <path d="M 10,30 A 20,20 0,0,1 50,30 A 20,20 0,0,1 90,30 Q 90,60 50,90 Q 10,60 10,30 z"
          stroke="blue" stroke-width="3" fill="red">
        </path>
    </svg>
</div>
```


![zh-cn_image_0000001173164891](figures/zh-cn_image_0000001173164891.png)
