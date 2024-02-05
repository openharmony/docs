# animateMotion


>  **说明：**
> 该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

路径动效。

## 权限列表

无


## 子组件

不支持。


## 属性

支持animate属性（values不生效）和以下表格中的属性。

| 名称 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| keyPoints | string | - | 是 | 一组关键帧的点位置，每帧的值为对象沿路径的距离比例。功能与animate属性中的values相同。 |
| path | string | - | 是 | 定义运动的路径，使用与path组件d属性相同的语法。 |
| rotate | [auto&nbsp;\|&nbsp;auto-reverse&nbsp;\|&nbsp;&lt;number&gt;] | auto | 否 | 设置动画对象的旋转方向。 |


## 示例

```html
<!-- xxx.hml -->
<div class="container">
  <svg fill="white" width="400" height="400">
    <path fill="none" stroke="blue" stroke-width="3" d="m40,60 c0,-100 160,100 160,0 c0,-100 -160,100 -160,0 z"></path>
    <path fill="none" stroke="blue" stroke-width="3" d="m40,130 c0,-100 160,100 160,0 c0,-100 -160,100 -160,0 z"></path>
    <path fill="none" stroke="blue" stroke-width="3" d="m40,200 c0,-100 160,100 160,0 c0,-100 -160,100 -160,0 z"></path>
    <path fill="red" d="M-5,-5 L10,0 L-5,5 L0,0 Z">
      <animateMotion dur="2000" repeatCount="indefinite" rotate="auto" keyPoints="0;0.2;0.4;0.6;0.8;1" path="m40,60 c0,-100 160,100 160,0 c0,-100 -160,100 -160,0 z">
      </animateMotion>
    </path>
    <path fill="red" d="M-5,-5 L10,0 L-5,5 L0,0 Z">
      <animateMotion dur="2000" repeatCount="indefinite" rotate="auto-reverse"path="m40,130 c0,-100 160,100 160,0 c0,-100,-160,100 -160,0 z">
      </animateMotion>
    </path>
    <path fill="red" d="M-5,-5 L10,0 L-5,5 L0,0 Z">
      <animateMotion dur="2000" repeatCount="indefinite" rotate="45"path="m40,200 c0,-100 160,100 160,0 c0,-100 -160,100 -160,0 z"></animateMotion>
    </path>
  </svg>
</div>
```


![zh-cn_image_0000001213381209](figures/zh-cn_image_0000001213381209.gif)
