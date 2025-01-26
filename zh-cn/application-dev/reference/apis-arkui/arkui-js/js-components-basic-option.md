# option

>  **说明：**
>  从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

当作为&lt;[select](js-components-basic-select.md)&gt;的子组件时用来展示下拉选择的具体项目。


当作为&lt;[menu](js-components-basic-menu.md)&gt;的子组件时用来展示弹出菜单的具体项目。


## 权限列表

无


## 子组件

不支持。


## 属性

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

| 名称       | 类型      | 默认值  | 必填   | 描述                                       |
| -------- | ------- | ---- | ---- | ---------------------------------------- |
| selected | boolean | -    | 否    | 选择项是否为下拉列表的默认项，仅在父组件是select时生效。          |
| value    | string  | -    | 是    | 选择项的值，作为select、menu父组件的selected事件中的返回值。<br/>option选项的UI展示值需要放在标签内，如：<br>`<option value="10">十月</option>` |
| icon     | string  | -    | 否    | 图标资源路径，该图标展示在选项文本前，图标格式为jpg，png和svg。     |


## 样式

支持如下样式。

| 名称              | 类型                         | 默认值        | 必填   | 描述                                       |
| --------------- | -------------------------- | ---------- | ---- | ---------------------------------------- |
| color           | &lt;color&gt;              | \#e6000000 | 否    | 选择项的文本颜色。                                |
| font-size       | &lt;length&gt;             | 16px       | 否    | 选择项的文本尺寸。                                |
| allow-scale     | boolean                    | true       | 否    | 选择项的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。<br/>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。 |
| font-weight     | number&nbsp;\|&nbsp;string | normal     | 否    | 选择项的字体粗细，见[text组件font-weight的样式属性](js-components-basic-text.md#样式)。 |
| text-decoration | string                     | none       | 否    | 选择项的文本修饰，见[text组件text-decoration的样式属性](js-components-basic-text.md#样式)。 |
| font-family     | string                     | sans-serif | 否    | 选择项的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过[自定义字体](js-components-common-customizing-font.md)指定的字体，会被选中作为文本的字体。 |


## 事件

不支持。


## 方法

不支持。


## 示例

详见[menu示例](js-components-basic-menu.md#示例)。
