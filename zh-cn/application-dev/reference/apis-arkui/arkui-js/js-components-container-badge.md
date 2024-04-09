# badge

>  **说明：**
>  从API version 5开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

应用中如果有需用户关注的新事件提醒，可以采用新事件标记来标识。


## 权限列表

无


## 子组件

支持单个子组件。

>  **说明：**
>  仅支持单子组件节点，如果使用多子组件节点，默认使用第一个子组件节点。


## 属性

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

| 名称               | 类型        | 默认值   | 必填 | 描述                                                         |
| ------------------ | ----------- | -------- | ---- | ------------------------------------------------------------ |
| placement          | string      | rightTop | 否   | 事件提醒的数字标记或者圆点标记的位置，可选值为：<br/>-&nbsp;right：位于组件右边框。<br/>-&nbsp;rightTop：位于组件边框右上角。<br/>-&nbsp;left：位于组件左边框。 |
| count              | number      | 0        | 否   | 设置提醒的消息数，默认为0，为0时不显示。当设置相应的提醒消息数大于0时，消息提醒会变成数字标记类型。<br/>当数字设置大于maxcount时，将使用maxcount显示。count属性最大支持整数值为2147483647。 |
| visible            | boolean     | false    | 否   | 是否显示消息提醒，当收到新信息提醒时可以设置该属性为true，显示相应的消息提醒，如果需要使用数字标记类型，同时需要设置相应的count属性。 |
| maxcount           | number      | 99       | 否   | 最大消息数限制，当收到新信息提醒大于该限制时，标识数字会进行省略，仅显示maxcount+。<br/>maxcount属性支持的最大整数值为2147483647。 |
| config             | BadgeConfig | -        | 否   | 设置新事件标记相关配置属性。                                 |
| label<sup>6+</sup> | string      | -        | 否   | 设置新事件提醒的文本值。<br/>使用该属性时，count和maxcount属性不生效。 |

**表1** BadgeConfig

| 名称         | 类型             | 默认值      | 必填   | 描述           |
| ---------- | -------------- | -------- | ---- | ------------ |
| badgeColor | &lt;color&gt;  | \#fa2a2d | 否    | 新事件标记背景色。    |
| textColor  | &lt;color&gt;  | \#ffffff | 否    | 数字标记的数字文本颜色。 |
| textSize   | &lt;length&gt; | 10px     | 否    | 数字标记的数字文本大小。 |
| badgeSize  | &lt;length&gt; | 6px      | 否    | 圆点标记的默认大小    |


## 样式

支持[通用样式](js-components-common-styles.md)。

>  **说明：**
>  badge组件的子组件大小不能超过badge组件本身的大小，否则子组件不会绘制。


## 事件

支持[通用事件](js-components-common-events.md)。


## 方法

支持[通用方法](js-components-common-methods.md)。


## 示例

```html
<!-- xxx.hml -->
<div class="container">
  <badge class="badge" config="{{badgeconfig}}" visible="true" count="100" maxcount="99">
    <text class="text1">example</text>
  </badge>
  <badge class="badge" visible="true" count="0">
    <text class="text2">example</text>
  </badge>
</div>
```

```css
/* xxx.css */
.container {
  flex-direction: column;
  width: 100%;
  align-items: center;
}
.badge {
  width: 50%;
  margin-top: 100px;
}
.text1 {
  background-color: #f9a01e;
  font-size: 50px;
}
.text2 {
  background-color: #46b1e3;
  font-size: 50px;
}
```

```js
// xxx.js
export default {
  data:{
    badgeconfig:{
      badgeColor:"#0a59f7",
      textColor:"#ffffff",
    }
  }
}
```

![zh-cn_image_000000117726526811](figures/zh-cn_image_000000117726526811.png)
