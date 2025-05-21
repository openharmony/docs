# input

>  **说明：**
>  从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

交互式组件，包括单选框，多选框，按钮和单行文本输入框。

## 权限列表

无


## 子组件

不支持。


## 属性

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

| 名称                               | 类型                      | 默认值       | 必填   | 描述                                       |
| -------------------------------- | ----------------------- | --------- | ---- | ---------------------------------------- |
| type                             | string                  | text<br/> | 否    | input组件类型，可选值为text，email，date，time，number，password，button，checkbox，radio。<br/>其中text，email，date，time，number，password这六种类型之间支持动态切换修改。<br/>button，checkbox，radio不支持动态修改。可选值定义如下：<br/>-&nbsp;button：定义可点击的按钮；<br/>-&nbsp;checkbox：定义多选框；<br/>-&nbsp;radio：定义单选按钮，允许在多个拥有相同name值的选项中选中其中一个；<br/>-&nbsp;text：定义一个单行的文本字段；<br/>-&nbsp;email：定义用于e-mail地址的字段；<br/>-&nbsp;date：定义&nbsp;date&nbsp;控件（包括年、月、日，不包括时间）；<br/>-&nbsp;time：定义用于输入时间的控件（不带时区）；<br/>-&nbsp;number：定义用于输入数字的字段；<br/>-&nbsp;password：定义密码字段（字段中的字符会被遮蔽）。 |
| checked                          | boolean                 | false     | 否    | 当前组件是否选中，仅type为checkbox和radio生效。         |
| name                             | string                  | -         | 否    | input组件的名称。<br>type为radio时，name为必填。      |
| value                            | string                  | -         | 否    | input组件的value值，当类型为radio时必填且相同name值的选项该值唯一。 |
| placeholder                      | string                  | -         | 否    | 设置提示文本的内容，仅在type为text\|email\|date\|time\|number\|password时生效。 |
| maxlength                        | number                  | -         | 否    | 输入框可输入的最多字符数量，不填表示不限制输入框中字符数量。           |
| enterkeytype                     | string                  | default   | 否    | 不支持动态修改。<br/>设置软键盘Enter按钮的类型，可选值为：<br/>-&nbsp;default：默认<br/>-&nbsp;next：下一项<br/>-&nbsp;go：前往<br/>-&nbsp;done：完成<br/>-&nbsp;send：发送<br/>-&nbsp;search：搜索<br/>除“next”外，点击后会自动收起软键盘。 |
| headericon                       | string                  | -         | 否    | 在文本输入前的图标资源路径，该图标不支持点击事件（button，checkbox和radio不生效），图标格式为jpg，png和svg。 |
| showcounter<sup>5+</sup>         | boolean                 | false     | 否    | 文本输入框是否显示计数下标，需要配合maxlength一起使用。         |
| menuoptions<sup>5+</sup>         | Array&lt;MenuOption&gt; | -         | 否    | 设置文本选择弹框点击更多按钮之后显示的菜单项。                  |
| autofocus<sup>6+</sup>           | boolean                 | false     | 否    | 是否自动获焦。<br/>应用首页中设置不生效，可在onActive中延迟（100-500ms左右）调用focus方法实现输入框在首页中自动获焦。 |
| selectedstart<sup>6+</sup>       | number                  | -1        | 否    | 开始选择文本时初始选择位置。                           |
| selectedend<sup>6+</sup>         | number                  | -1        | 否    | 开始选择文本时结尾选择位置。                           |
| softkeyboardenabled<sup>6+</sup> | boolean                 | true      | 否    | 编辑时是否弹出系统软键盘。                            |
| showpasswordicon<sup>6+</sup>    | boolean                 | true      | 否    | 是否显示密码框末尾的图标（仅type为password时生效）。         |

**表1** MenuOption<sup>5+</sup>

| 名称      | 类型     | 描述          |
| ------- | ------ | ----------- |
| icon    | string | 菜单选项中的图标路径。 |
| content | string | 菜单选项中的文本内容。 |


## 样式

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

| 名称                       | 类型                         | 默认值        | 必填   | 描述                                       |
| ------------------------ | -------------------------- | ---------- | ---- | ---------------------------------------- |
| color                    | &lt;color&gt;              | \#e6000000 | 否    | 单行输入框或者按钮的文本颜色。                          |
| font-size                | &lt;length&gt;             | 16px       | 否    | 单行输入框或者按钮的文本尺寸。                          |
| allow-scale              | boolean                    | true       | 否    | 单行输入框或者按钮的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。true表示跟随系统放大缩小，false表示不跟随系统放大缩小。<br/>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。 |
| placeholder-color        | &lt;color&gt;              | \#99000000 | 否    | 单行输入框的提示文本的颜色，type为text\|email\|date\|time\|number\|password时生效。 |
| font-weight              | number&nbsp;\|&nbsp;string | normal     | 否    | 单行输入框或者按钮的字体粗细，见[text组件font-weight的样式属性](js-components-basic-text.md#样式)。 |
| caret-color<sup>6+</sup> | &lt;color&gt;              | -          | 否    | 设置输入光标的颜色。                               |


## 事件

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

- 当input类型为text、email、date、time、number、password时，支持如下事件：

  | 名称                        | 参数                                       | 描述                                       |
  | ------------------------- | ---------------------------------------- | ---------------------------------------- |
  | change                    | {<br>&nbsp;value: inputValue<br>&nbsp;}  | 输入框输入内容发生变化时触发该事件，返回用户当前输入值。<br/>改变value属性值不会触发该回调。 |
  | enterkeyclick             | {<br>&nbsp;value: enterKey<br>&nbsp;}    | 软键盘enter键点击后触发该事件，返回enter按钮的类型，enterKey类型为number，可选值为：<br/>-&nbsp;2：设置enterkeytype属性为go时生效。<br/>-&nbsp;3：设置enterkeytype属性为search时生效。<br/>-&nbsp;4：设置enterkeytype属性为send时生效。<br/>-&nbsp;5：设置enterkeytype属性为next时生效。<br/>-&nbsp;6：不设置enterkeytype或者设置enterkeytype属性为default、done时生效。 |
  | translate<sup>5+</sup>    | {<br>&nbsp;value:&nbsp;selectedText<br>&nbsp;} | 设置此事件后，进行文本选择操作后文本选择弹窗会出现翻译按钮，点击翻译按钮之后，触发该回调，返回选中的文本内容。 |
  | share<sup>5+</sup>        | {<br>&nbsp;value:&nbsp;selectedText<br>&nbsp;} | 设置此事件后，进行文本选择操作后文本选择弹窗会出现分享按钮，点击分享按钮之后，触发该回调，返回选中的文本内容。 |
  | search<sup>5+</sup>       | {<br>&nbsp;value:&nbsp;selectedText<br>&nbsp;} | 设置此事件后，进行文本选择操作后文本选择弹窗会出现搜索按钮，点击搜索按钮之后，触发该回调，返回选中的文本内容。 |
  | optionselect<sup>5+</sup> | {<br>&nbsp;index: optionIndex,<br>&nbsp;value:&nbsp;selectedText<br>&nbsp;} | 文本选择弹窗中设置menuoptions属性后，用户在文本选择操作后，点击菜单项后触发该回调，返回点击的菜单项序号和选中的文本内容。 |
  | selectchange<sup>6+</sup> | {<br>start:&nbsp;number,<br>end:&nbsp;number<br>&nbsp;} | 文本选择变化时触发事件。                             |

- 当input类型为checkbox、radio时，支持如下事件：

  | 名称     | 参数                                       | 描述                                       |
  | ------ | ---------------------------------------- | ---------------------------------------- |
  | change | {<br>&nbsp;checked:true&nbsp;\|&nbsp;false&nbsp;<br>} | checkbox多选框或radio单选框的checked状态发生变化时触发该事件。 |

## 方法

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

| 名称                  | 参数                                       | 描述                                       |
| ------------------- | ---------------------------------------- | ---------------------------------------- |
| focus               | {<br>&nbsp;focus:&nbsp;true\|false<br>&nbsp;}，<br>focus不传值时，默认为true。 | 使组件获得或者失去焦点，type为text\|email\|date\|time\|number\|password时，可弹出或收起输入法。 |
| showError           | {<br>&nbsp;error:&nbsp;string&nbsp;<br>} | 展示输入错误提示，type为text\|email\|date\|time\|number\|password时生效。 |
| delete<sup>6+</sup> | -                                        | type为text\|email\|date\|time\|number\|password时，根据当前光标位置删除文本内容，如果当前输入组件没有光标，默认删除最后一个字符并展示光标。 |

## 示例

1. type为text
   ```html
   <!-- xxx.hml -->
   <div class="content">
     <input id="input" class="input" type="text" value="" maxlength="20" enterkeytype="send"
       headericon="/common/search.svg" placeholder="Please input text" onchange="change"
       onenterkeyclick="enterkeyClick">
     </input>
     <input class="button" type="button" value="Submit" onclick="buttonClick" style="color: blue"></input>
   </div>
   ```

   ```css
   /* xxx.css */
   .content {
     width: 100%;
     flex-direction: column;
     align-items: center;
   }
   .input {
     width: 60%;
     placeholder-color: gray;
   }
   .button {
     width: 60%;
     background-color: gray;
     margin-top: 20px;
    }
   ```
   
   ```js
   // xxx.js
   import promptAction from '@ohos.promptAction';
   export default {
     change(e){
       promptAction.showToast({
         message: "value: " + e.value,
         duration: 3000,
       });
     },
     enterkeyClick(e){
       promptAction.showToast({
         message: "enterkey clicked",
         duration: 3000,
       });
     },
     buttonClick(e){
       this.$element("input").showError({
         error: 'error text'
       });
     },
    }
   ```


   ![zh-cn_image_0000001252835901](figures/zh-cn_image_0000001252835901.png)

2. type为button
   ```html
   <!-- xxx.hml -->
   <div class="div-button">
     <input class="button" type="button" value="Input-Button"></input>
   </div>
   ```

   ```css
   /* xxx.css */
   .div-button {
     flex-direction: column;
     align-items: center;
   }
   .button {
     margin-top: 30px;
     width: 280px;
   }
   ```

   ![zh-cn_image_0000001207995958](figures/zh-cn_image_0000001207995958.png)

3. type为checkbox
   ```html
   <!-- xxx.hml -->
   <div class="content">
     <input onchange="checkboxOnChange" checked="true" type="checkbox"></input>
   </div>
   ```

   ```css
   /* xxx.css */
   .content{
     width: 100%;
     height: 200px;
     align-items: center; 
     justify-content: center;   
   }
   ```

   ```js
   // xxx.js
   import promptAction from '@ohos.promptAction';
   export default {
     checkboxOnChange(e) {
       promptAction.showToast({
         message:'checked: ' + e.checked,
         duration: 3000,
       });
     }
   }
   ```

   ![zh-cn_image_0000001208155956](figures/zh-cn_image_0000001208155956.png)

4. type为radio
   ```html
   <!-- xxx.hml -->
   <div class="content">
     <input type="radio" checked='true' name="radioSample" value="radio1" onchange="onRadioChange('radio1')"></input>
     <input type="radio" checked='false' name="radioSample" value="radio2" onchange="onRadioChange('radio2')"></input>
     <input type="radio" checked='false' name="radioSample" value="radio3" onchange="onRadioChange('radio3')"></input>
   </div>
   ```

   ```css
   /* xxx.css */
   .content{
     width: 100%;
     height: 200px;
     justify-content: center;
     align-items: center;
   }
   ```

   ```js
   // xxx.js
   import promptAction from '@ohos.promptAction';
   export default {
     onRadioChange(inputValue, e) {
       if (inputValue === e.value) {
         promptAction.showToast({
           message: 'The chosen radio is ' + e.value,
           duration: 3000,
         });
       }
     }
   }
   ```

   ![zh-cn_image_0000001208315918](figures/zh-cn_image_0000001208315918.png)
