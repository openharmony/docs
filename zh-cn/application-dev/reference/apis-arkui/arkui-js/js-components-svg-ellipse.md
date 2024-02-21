# ellipse


>  **说明：**
> 该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

椭圆形状。

## 权限列表

无


## 子组件

支持[animate](js-components-svg-animate.md)、[animateMotion](js-components-svg-animatemotion.md)、[animateTransform](js-components-svg-animatetransform.md)。


## 属性

支持Svg组件[通用属性](js-components-svg-common-attributes.md)和以下属性。

| 名称 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| id | string | - | 否 | 组件的唯一标识。 |
| cx | &lt;length&gt;\|&lt;percentage&gt; | 0 | 否 | 设置椭圆的x轴坐标。支持属性动画 |
| cy | &lt;length&gt;\|&lt;percentage&gt; | 0 | 否 | 设置椭圆的y轴坐标。支持属性动画 |
| rx | &lt;length&gt;\|&lt;percentage&gt; | 0 | 否 | 设置椭圆x轴的半径。支持属性动画 |
| ry | &lt;length&gt;\|&lt;percentage&gt; | 0 | 否 | 设置椭圆y轴的半径。支持属性动画 |


## 示例

```html
<!-- xxx.hml -->
<div class="container">
  <svg fill="white" width="400" height="400">
    <ellipse cx="60" cy="200" rx="50" ry="100" stroke-width="4" fill="red" stroke="blue"></ellipse>
    <ellipse cx="220" cy="200" rx="100" ry="50" stroke-width="5" stroke="red" stroke-dasharray="10 5" stroke-dashoffset="3"></ellipse>
  </svg>
</div>
```


![zh-cn_image_0000001173164793](figures/zh-cn_image_0000001173164793.png)
