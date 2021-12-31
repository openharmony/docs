# TextInput<a name="ZH-CN_TOPIC_0000001192595168"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

提供单行文本输入组件。

## 权限列表<a name="section781125411508"></a>

无

## 子组件<a name="section1037371523612"></a>

无

## 接口<a name="section33135508"></a>

TextInput\(value?: \{ placeholder?: string \}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.499999999999998%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>placeholder</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>无输入时的提示文本。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section18430105671014"></a>

除支持[通用属性](ts-universal-attributes.md)外，还支持以下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.98%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="27.500000000000004%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.239999999999998%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="43.28%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.98%" headers="mcps1.1.5.1.1 "><p>type</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p><a href="#li1018842194211">InputType</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p>InputType.Normal</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p>设置输入框类型。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.98%" headers="mcps1.1.5.1.1 "><p>placeholderColor</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p>设置placeholder颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.98%" headers="mcps1.1.5.1.1 "><p>placeholderFont</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>size?: Length,</p>
<p>weight?: number | <a href="ts-universal-attributes-text-style.md#li24391125115311">FontWeight</a>,</p>
<p>family?: string,</p>
<p>style?: <a href="ts-basic-components-textarea.md#table952mcpsimp">FontStyle</a></p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p>设置placeholder文本样式：</p>
<ul><li>size: 设置文本尺寸，Length为number类型时，使用fp单位。</li><li>weight: 设置文本的字体粗细，number类型取值[100, 900]，取值间隔为100，默认为400，取值越大，字体越粗。</li><li>family: 设置文本的字体列表。使用多个字体，使用','进行分割，优先级按顺序生效。例如：'Arial, sans-serif'。</li><li>style: 设置文本的字体样式。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.98%" headers="mcps1.1.5.1.1 "><p>enterKeyType</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p><a href="#li1231618102427">EnterKeyType</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p>EnterKeyType.Done</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p>设置输入法回车键类型。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.98%" headers="mcps1.1.5.1.1 "><p>caretColor</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p>设置输入框光标颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.98%" headers="mcps1.1.5.1.1 "><p>maxLength</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p>设置文本的最大输入字符数。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li1231618102427"></a>EnterKeyType枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="26.13%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.87%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p>Go</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p>显示Go文本。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p>Search</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p>显示为搜索样式。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p>Send</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p>显示为发送样式。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p>Next</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p>显示为下一个样式。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p>Done</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p>标准样式。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li1018842194211"></a>InputType枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="26.13%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.87%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p>基本输入模式。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p>Password</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p>密码输入模式。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p>Email</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p>e-mail地址输入模式。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p>Number</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p>纯数字输入模式。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section449664852016"></a>

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onChange(value: string) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>输入发生变化时，触发回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onSubmit(callback: (enterKey: <a href="#li1231618102427">EnterKeyType</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>回车键或者软键盘回车键触发该回调，参数为当前软键盘回车键类型。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onEditChanged(callback: (isEditing: boolean) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>输入状态变化时，触发回调。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section3619717314"></a>

```
@Entry
@Component
struct TextInputTest {
    @State text: string = ''
    @State text1: string = ''
    @State text2: string = ''
    build() {
      Column() {
        TextInput({ placeholder: 'input your word' })
          .type(InputType.Normal)
          .placeholderColor(Color.Blue)
          .placeholderFont({ size: 40, weight: FontWeight.Normal, family: "sans-serif", style: FontStyle.Normal })
          .enterKeyType(EnterKeyType.Next)
          .caretColor(Color.Green)
          .height(60)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .fontFamily("cursive")
          .fontStyle(FontStyle.Italic)
          .fontColor(Color.Red)
          .maxLength(20)
          .onChange((value: string) => {
            this.text = value
          })
          .onSubmit((enterKey) => {
            this.text1 = 'onSubmit'
          })
          .onEditChanged((isEditing) => {
            this.text2 = 'onEditChanged'
          })
          Text(this.text)
          Text(this.text1)
          Text(this.text2)
        }
    }
}
```

![](figures/textinput1.gif)

