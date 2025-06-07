# span

>  **说明：**
>  从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

作为&lt;[text](js-components-basic-text.md)&gt;子组件提供文本修饰能力。

## 权限列表

无


## 子组件

无


## 属性

支持[通用属性](js-components-common-attributes.md)。

>  **说明：**
>  不支持focusable和disabled属性。


## 样式

仅支持如下样式：

| 名称              | 类型                         | 默认值        | 必填   | 描述                                       |
| --------------- | -------------------------- | ---------- | ---- | ---------------------------------------- |
| color           | &lt;color&gt;              | -          | 否    | 设置文本段落的文本颜色。                             |
| font-size       | &lt;length&gt;             | 30px       | 否    | 设置文本段落的文本尺寸。                             |
| allow-scale     | boolean                    | true       | 否    | 设置文本段落的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。true表示跟随系统放大缩小，false表示不跟随系统放大缩小。<br/>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。 |
| font-style      | string                     | normal     | 否    | 设置文本段落的字体样式，见[text组件font-style的样式属性](js-components-basic-text.md#样式)。 |
| font-weight     | number&nbsp;\|&nbsp;string | normal     | 否    | 设置文本段落的字体粗细，见[text组件font-weight的样式属性](js-components-basic-text.md#样式)。 |
| text-decoration | string                     | none       | 否    | 设置文本段落的文本修饰，见[text组件text-decoration样式属性](js-components-basic-text.md#样式)。 |
| font-family     | string                     | sans-serif | 否    | 设置文本段落的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过[自定义字体](js-components-common-customizing-font.md)指定的字体，会被选中作为文本的字体。 |


## 事件

仅支持[通用事件](js-components-common-events.md)中的click事件。


## 方法

不支持。


## 示例

```html
<!-- xxx.hml -->
<div class="container">
  <text class="title">
    <span class="spanTxt">span</span>
  </text>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
.title {
  font-size: 30px;
  text-align: center;
  width: 100%;
  height: 100px;
}
.spanTxt{
  color: chartreuse;
  font-size: 80px;
}
```

![zh-cn_image_0000001152588626](figures/zh-cn_image_0000001152588626.png)
