# 通用属性

>  **说明：**
> 从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


| 名称 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| fill | &lt;color&gt; | black | 否 | 使用简写属性设置元素的填充色。支持属性动画。 |
| fill-opacity | number | 1 | 否 | 填充色的透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。支持属性动画。 |
| fill-rule | nonzero&nbsp;\|&nbsp;evenodd | nonzero | 否 | nonzero:非零规则;&nbsp;evenodd:奇偶规则。 |
| opacity | number | 1 | 否 | 元素的透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。支持属性动画。 |
| stroke | &lt;color&gt; | - | 否 | 设置形状轮廓的颜色。支持属性动画。 |
| stroke-dasharray | &lt;string&gt; | - | 否 | 指定短划线和缺口的长度。格式为[length&nbsp;length&nbsp;length&nbsp;length]，短划线和缺口的长度中间空格隔开成对出现。 |
| stroke-dashoffset | &lt;length&gt; | 0 | 否 | 设置关联虚线数组渲染时的偏移量。支持属性动画。 |
| stroke-linejoin | [bevel&nbsp;\|&nbsp;miter&nbsp;\|&nbsp;round] | miter | 否 | 进行描边时在路径的拐角处使用的形状。<br/>bevel：使用斜角连接路径段；<br/>miter：使用尖角连接路径段；<br/>round：使用圆角连接路径段。 |
| stroke-linecap | [butt&nbsp;\|&nbsp;round&nbsp;\|&nbsp;square] | butt | 否 | 路径描边时在它们的结尾处使用的形状。<br/>butt：不在路径两端扩展；<br/>round：在路径的末端延伸半个圆，直径等于线宽；<br/>square：在路径的末端延伸一个矩形，宽度等于线宽的一半，高度等于线宽。 |
| stroke-miterlimit | number | 4 | 否 | 设置将锐角绘制成斜角的极限值。支持属性动画。 |
| stroke-opacity | number | 1 | 否 | 轮廓线条的透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。支持属性动画。 |
| stroke-width | &lt;length&gt; | 1px | 否 | 设置轮廓线条的宽度。支持属性动画。 |
| transform | &lt;string&gt; | - | 否 | 设置组件以及子组件的坐标变换参数。<br/>支持以下格式：<br/>translate(&lt;x&gt;&nbsp;[&lt;y&gt;])&nbsp;：沿x[y]轴方向平移<br/>scale(&lt;x&gt;&nbsp;[&lt;y&gt;])&nbsp;：沿x[y]轴缩放<br/>rotate(&lt;a&gt;&nbsp;[&lt;x&gt;&nbsp;&lt;y&gt;])&nbsp;：以(x,y)点进行旋转a度角<br/>skewX(&lt;a&gt;)&nbsp;：沿x轴倾斜a度角的变换<br/>skewY(&lt;a&gt;)&nbsp;：沿y轴倾斜a度角的变换。 |
