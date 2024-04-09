# popup

>  **说明：**
> 从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

气泡指示。给控件绑定气泡弹窗，并在点击控件或者调用气泡弹窗显示方法后弹出相应的气泡提示来引导用户进行操作。

## 权限列表

无


## 子组件

支持单个子组件节点<sup>5+</sup>。


## 属性

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

| 名称 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| target | string | - | 是 | popup绑定目标元素的id属性值，不支持动态切换。 |
| placement | string | bottom | 否 | popup相对于目标元素的位置。可选值为：<br/>-&nbsp;left：位于目标元素左边；<br/>-&nbsp;right：位于目标元素右边；<br/>-&nbsp;top：位于目标元素上边；<br/>-&nbsp;bottom：位于目标元素下边；<br/>-&nbsp;topLeft：位于目标元素左上角；<br/>-&nbsp;topRight：位于目标元素右上角；<br/>-&nbsp;bottomLeft：位于目标元素左下角；<br/>-&nbsp;bottomRight：位于目标元素右下角。 |
| keepalive<sup>5+</sup> | boolean | false | 否 | 设置当前popup是否需要保留。设置为true时，点击屏幕区域或者页面切换气泡不会消失，需调用气泡组件的hide方法才可让气泡消失；设置为false时，点击屏幕区域或者页面切换气泡会自动消失。 |
| clickable<sup>5+</sup> | boolean | true | 否 | popup是否支持点击目标元素弹窗，当设置为false时，只支持方法调用显示弹窗。 |
| arrowoffset<sup>5+</sup> | &lt;length&gt; | 0 | 否 | popup箭头在弹窗处的偏移，默认居中，正值按照语言方向进行偏移，负值相反。 |

>  **说明：**
>
> - 不支持focusable属性。


## 样式

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

| 名称 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| mask-color | &lt;color&gt; | - | 否 | 遮罩层的颜色，默认值为全透明。 |

>  **说明：**
>
> - 不支持position相关样式。


## 事件

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

| 名称 | 参数 | 描述 |
| -------- | -------- | -------- |
| visibilitychange | {&nbsp;visibility:&nbsp;boolean&nbsp;} | 当气泡弹出和消失时会触发该回调函数。 |


## 方法

仅支持如下方法：

| 名称 | 参数 | 描述 |
| -------- | -------- | -------- |
| show<sup>5+</sup> | - | 弹出气泡提示。 |
| hide<sup>5+</sup> | - | 隐藏气泡提示。 |

>  **说明：**
> 1. popup气泡弹窗属性、样式均不支持动态更新。
> 
> 2. popup气泡弹窗的margin样式是相对于target元素进行生效的，如popup在target元素下方，此时只生效margin-top样式，popup在target元素左上方，此时只生效margin-bottom和margin-right样式。
> 
> 3. popup的border四边样式需一致，若四边设置不一致且圆角为零，则按左、上、右、下的顺序取第一个被设置的样式，否则border不生效。
> 
> 4. popup的target组件的click事件不生效。


## 示例

```html
<!-- xxx.hml -->
<div class="container">
  <text id="text">Click to show the pop-up</text>
  <!-- popup supports single child of any type5+ -->
  <popup id="popup" class="popup" target="text" placement="top" keepalive="true" clickable="true" 
    arrowoffset="100px" onvisibilitychange="visibilitychange" onclick="hidepopup">
    <text class="text">Text content of the pop-up</text>
  </popup>
  <button class="button" onclick="showpopup">Click to show the pop-up</button>
</div>
```

```css
/* xxx.css */
.container {
  flex-direction: column;
  align-items: center;
  padding-top: 200px;
}
.popup {
  mask-color: gray;
}
.text {
  color: white;
}
.button {
  width: 220px;
  height: 70px;
  margin-top: 50px;
}
```

```js
// xxx.js
import promptAction from '@ohos.promptAction'
export default {
  visibilitychange(e) {
    promptAction.showToast({
      message: 'visibility change visibility: ' + e.visibility,
        duration: 3000
    }); 
  },
  showpopup() {
    this.$element("popup").show();
  },
  hidepopup() {
    this.$element("popup").hide();
  }
}
```

![zh-cn_image_0000001178886129](figures/zh-cn_image_0000001178886129.png)
