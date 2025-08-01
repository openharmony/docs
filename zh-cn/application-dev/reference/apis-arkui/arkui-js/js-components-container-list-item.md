# list-item

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yylong-->
<!--SE: @yylong-->
<!--TSE: @liuzhenshuo-->

>  **说明：**
> 从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

&lt;[list](js-components-container-list.md)&gt;的子组件，用来展示列表具体item。由于父元素list组件的align-items默认样式为stretch，该组件宽度默认充满list组件。设置父元素list组件的align-items样式为非stretch来生效自定义宽度。

## 权限列表

无


## 子组件

支持单个子组件。


## 属性

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

| 名称 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| type | string | default | 否 | list-item类型，默认值为default，同一list中可以包含多种type的list-item，相同type的list-item需要确保渲染后的视图布局也相同，如果type固定，则使用show属性代替if属性，确保视图布局不变。 |
| primary | boolean | false | 否 | 设置为true表示该item是group中的主item，即收拢时显示的item。如果有多个primary，以第一个为准。如果没有标记为primary的item，则以第一个item为主item。 |
| section | string | - | 否 | 当前item的匹配字符串，如不设置则为空。不支持动态修改。group内只有主item设置有效。 |
| sticky | string | none | 否 | 设置当前item是否为吸顶item以及其吸顶消失的效果，当前仅支持纵向list，group内部的item不可吸顶，设置该属性无效。<br/>-&nbsp;none：当前item不吸顶。<br/>-&nbsp;normal：当前item吸顶，消失效果滑动消失。<br/>-&nbsp;opacity：当前item吸顶，消失效果渐隐消失，仅在智能穿戴上支持。 |
| clickeffect<sup>5+</sup> | boolean | true | 否 | 设置当前item是否有点击动效。<br/>-&nbsp;false：item点击时无点击动效。<br/>-&nbsp;true：item点击时有点击动效。 |


## 样式



除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

| 名称 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| column-span | &lt;number&gt; | 1 | 否 | 当前的list-item需要在list中占据的列的数量，默认占一列，仅在list为多列时生效。 |


## 事件



除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

| 名称 | 参数 | 描述 |
| -------- | -------- | -------- |
| sticky | {&nbsp;state:&nbsp;boolean&nbsp;} | 吸顶组件回调事件。<br/>value:&nbsp;false表示当前item处于非吸顶状态；<br/>value:&nbsp;true表示当前item处于吸顶状态；<br/>说明：仅当item设置sticky属性时支持注册此事件。 |

## 方法

支持[通用方法](js-components-common-methods.md)。


## 示例

详见[List示例](js-components-container-list.md#示例)。
