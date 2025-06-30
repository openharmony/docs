# switch

>  **说明：**
>  从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

开关选择器，通过开关，开启或关闭某个功能。

## 权限列表

无


## 子组件

不支持。


## 属性

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

| 名称       | 类型      | 默认值   | 必填   | 描述         |
| -------- | ------- | ----- | ---- | ---------- |
| checked  | boolean | false | 否    | 是否选中。 true表示选中，false表示未选中。     |
| showtext | boolean | false | 否    | 是否显示文本。true表示显示文本，false表示不显示文本。    |
| texton   | string  | "On"  | 否    | 选中时显示的文本。  |
| textoff  | string  | "Off" | 否    | 未选中时显示的文本。 |


## 样式



除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

| 名称            | 类型                         | 默认值        | 必填   | 描述                                       |
| ------------- | -------------------------- | ---------- | ---- | ---------------------------------------- |
| texton-color  | &lt;color&gt;              | \#000000   | 否    | 选中时显示的文本颜色，仅设置texton和textoff生效。          |
| textoff-color | &lt;color&gt;              | \#000000   | 否    | 未选中时显示的文本颜色，仅设置texton和textoff生效。         |
| text-padding  | number                     | 0px        | 否    | texton/textoff中最长文本两侧距离滑块边界的距离。          |
| font-size     | &lt;length&gt;             | -          | 否    | 文本尺寸，仅设置texton和textoff生效。                |
| allow-scale   | boolean                    | true       | 否    | 文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。true表示跟随系统放大缩小，false表示不跟随系统放大缩小。<br/>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。 |
| font-style    | string                     | normal     | 否    | 字体样式，仅设置texton和textoff生效。见text组件[font-style的样式属性](js-components-basic-text.md#样式)。 |
| font-weight   | number&nbsp;\|&nbsp;string | normal     | 否    | 字体粗细，仅设置texton和textoff生效。见text组件的[font-weight的样式属性](js-components-basic-text.md#样式)。 |
| font-family   | string                     | sans-serif | 否    | 字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过[自定义字体](js-components-common-customizing-font.md)指定的字体，会被选中作为文本的字体。仅设置texton和textoff生效。 |


## 事件

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

| 名称     | 参数                                       | 描述            |
| ------ | ---------------------------------------- | ------------- |
| change | {&nbsp;checked:&nbsp;checkedValue&nbsp;} | 选中状态改变时触发该事件。 |

## 方法

支持[通用方法](js-components-common-methods.md)。

## 示例

```html
<!-- xxx.hml -->
<div class="container">
    <switch @change="normalswitchChange">
    </switch>
    <switch class="switch" showtext="true" texton="开启" textoff="关闭" @change="switchChange">
    </switch>
    <switch class="switch text" showtext="true" texton="开启" textoff="关闭" checked="true" @change="switchChange">
    </switch>
</div>
```

```css
/* xxx.css */
.container {
    display: flex;
    justify-content: center;
    align-items: center;
}
.switch {
    texton-color: red;
    textoff-color: forestgreen;
}
.text {
    text-padding: 20px;
    font-size: 30px;
    font-weight: 700;
}
```

```js
// xxx.js
import promptAction from '@ohos.promptAction';
export default {
    data: {
        title: 'World'
    },
    switchChange(e) {
        if (e.checked) {
            promptAction.showToast({
                message: "打开开关"
            });
        } else {
            promptAction.showToast({
                message: "关闭开关"
            });
        }
    },
    normalswitchChange(e) {
        if (e.checked) {
            promptAction.showToast({
                message: "switch on"
            });
        } else {
            promptAction.showToast({
                message: "switch off"
            });
        }
    }
}
```

![zh-cn_image_0000001152862510](figures/switch.gif)
