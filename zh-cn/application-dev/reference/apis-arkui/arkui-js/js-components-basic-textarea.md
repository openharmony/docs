# textarea

>  **说明：**
>  从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

多行文本输入的文本框。


## 权限列表

无


## 子组件

不支持。


## 属性

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

| 名称                             | 类型                    | 默认值 | 必填 | 描述                                                         |
| -------------------------------- | ----------------------- | ------ | ---- | ------------------------------------------------------------ |
| placeholder                      | string                  | -      | 否   | 多行文本框的提示文本内容。                                   |
| maxlength                        | number                  | -      | 否   | 多行文本框可输入的最多字符数量。                             |
| headericon                       | string                  | -      | 否   | 在文本输入前的图标展示，该图标不支持点击事件，图标格式为jpg，png和svg。 |
| extend                           | boolean                 | false  | 否   | 文本框是否支持可扩展，设置可扩展属性后文本框高度可以跟随文字自适应。 |
| value<sup>5+</sup>               | string                  | -      | 否   | 多行文本框的内容。                                           |
| showcounter<sup>5+</sup>         | boolean                 | false  | 否   | 文本框是否需要开启计数下标功能，需要配合maxlength一起使用。  |
| menuoptions<sup>5+</sup>         | Array&lt;MenuOption&gt; | -      | 否   | 设置文本选择弹框点击更多按钮之后显示的菜单项。               |
| autofocus<sup>6+</sup>           | boolean                 | false  | 否   | 是否自动获焦。                                               |
| selectedstart<sup>6+</sup>       | number                  | -1     | 否   | 开始选择文本时初始选择位置。                                 |
| selectedend<sup>6+</sup>         | number                  | -1     | 否   | 开始选择文本时结尾选择位置。                                 |
| softkeyboardenabled<sup>6+</sup> | boolean                 | true   | 否   | 编辑时是否弹出系统软键盘。                                   |

**表1** MenuOption<sup>5+</sup>

| 名称      | 类型     | 描述          |
| ------- | ------ | ----------- |
| icon    | string | 菜单选项中的图标路径。 |
| content | string | 菜单选项中的文本内容。 |


## 样式

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

| 名称                       | 类型                         | 默认值        | 必填   | 描述                                       |
| ------------------------ | -------------------------- | ---------- | ---- | ---------------------------------------- |
| color                    | &lt;color&gt;              | \#e6000000 | 否    | 多行文本框的文本颜色。                              |
| font-size                | &lt;length&gt;             | 16px       | 否    | 多行文本框的文本尺寸。                              |
| allow-scale              | boolean                    | true       | 否    | 多行文本框的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。<br/>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。 |
| placeholder-color        | &lt;color&gt;              | \#99000000 | 否    | 多行文本框的提示文本颜色，type为text\|email\|date\|time\|number\|password时生效。 |
| font-weight              | number&nbsp;\|&nbsp;string | normal     | 否    | 多行文本框的字体粗细，见[text组件font-weight的样式属性](js-components-basic-text.md#样式)。 |
| font-family              | string                     | sans-serif | 否    | 多行文本框的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过[自定义字体](js-components-common-customizing-font.md)指定的字体，会被选中作为文本的字体。 |
| caret-color<sup>6+</sup> | &lt;color&gt;              | -          | 否    | 设置输入光标的颜色。                               |


## 事件

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

| 名称                        | 参数                                       | 描述                                       |
| ------------------------- | ---------------------------------------- | ---------------------------------------- |
| change                    | {&nbsp;text:&nbsp;newText,&nbsp;lines:&nbsp;textLines,&nbsp;height:&nbsp;textHeight&nbsp;} | 输入内容发生变化时触发该事件，通过参数获取输入内容、行数和行高。<br/>从API Version 5开始，改变value属性值不会触发该回调。 |
| translate<sup>5+</sup>    | {&nbsp;value:&nbsp;selectedText&nbsp;}   | 设置此事件后，进行文本选择操作后文本选择弹窗会出现翻译按钮，点击翻译按钮之后，触发该回调，返回选中的文本内容。 |
| share<sup>5+</sup>        | {&nbsp;value:&nbsp;selectedText&nbsp;}   | 设置此事件后，进行文本选择操作后文本选择弹窗会出现分享按钮，点击分享按钮之后，触发该回调，返回选中的文本内容。 |
| search<sup>5+</sup>       | {&nbsp;value:&nbsp;selectedText&nbsp;}   | 设置此事件后，进行文本选择操作后文本选择弹窗会出现搜索按钮，点击搜索按钮之后，触发该回调，返回选中的文本内容。 |
| optionselect<sup>5+</sup> | {&nbsp;index:optionIndex,&nbsp;value:&nbsp;selectedText&nbsp;} | 文本选择弹窗中设置menuoptions属性后，用户在文本选择操作后，点击菜单项后触发该回调，返回点击的菜单项序号和选中的文本内容。 |
| selectchange<sup>6+</sup> | {&nbsp;start:&nbsp;number，end:&nbsp;number&nbsp;} | 文本选择变化时触发事件。                             |


## 方法

支持[通用方法](js-components-common-methods.md)。


## 示例

```html
<!-- xxx.hml -->
<textarea id="textarea" class="textarea" extend="true" maxlength="20"
  headericon="/common/navigation_menu1_icon.svg" placeholder="Please input text"
  onchange="change">
</textarea>
```

```css
/* xxx.css */
.textarea {
  placeholder-color: gray;
}
```

```js
// xxx.js
import promptAction from '@ohos.promptAction';
export default {
change(e){
  promptAction.showToast({
    message: 'value: ' + e.text + ', lines: ' + e.lines + ', height: ' + e.height,
    duration: 3000,
  });
}
}
```

![zh-cn_image_0000001127125124](figures/zh-cn_image_0000001127125124.png)
