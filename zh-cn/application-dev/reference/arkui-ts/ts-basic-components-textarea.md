# TextArea<a name="ZH-CN_TOPIC_0000001192755102"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

提供多行文本输入组件。

## 权限列表<a name="section781125411508"></a>

无

## 子组件<a name="section53281531154915"></a>

无

## 接口<a name="section1989913519718"></a>

TextArea\(value?: \{ placeholder?: string \}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.44%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.950000000000001%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.49%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>placeholder</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.44%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.950000000000001%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.49%" headers="mcps1.1.6.1.5 "><p>无输入时的提示文本。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section18430105671014"></a>

除支持[通用属性](ts-universal-attributes.md)外，还支持以下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.709999999999997%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.78%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.51%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="46%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="18.709999999999997%" headers="mcps1.1.5.1.1 "><p>placeholderColor</p>
</td>
<td class="cellrowborder" valign="top" width="21.78%" headers="mcps1.1.5.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="13.51%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="46%" headers="mcps1.1.5.1.4 "><p>设置placeholder文本颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.709999999999997%" headers="mcps1.1.5.1.1 "><p>placeholderFont</p>
</td>
<td class="cellrowborder" valign="top" width="21.78%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>size?: number,</p>
<p>weight?:number | <a href="ts-universal-attributes-text-style.md#li24391125115311">FontWeight</a>,</p>
<p>family?: string,</p>
<p>style?: <a href="ts-universal-attributes-text-style.md#li6906111945316">FontStyle</a></p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="13.51%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="46%" headers="mcps1.1.5.1.4 "><p>设置placeholder文本样式：</p>
<ul><li>size: 设置文本尺寸，Length为number类型时，使用fp单位。</li><li>weight: 设置文本的字体粗细，number类型取值[100, 900]，取值间隔为100，默认为400，取值越大，字体越粗。</li><li>family: 设置文本的字体列表。使用多个字体，使用','进行分割，优先级按顺序生效。例如：'Arial, sans-serif'。</li><li>style: 设置文本的字体样式。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.709999999999997%" headers="mcps1.1.5.1.1 "><p>textAlign</p>
</td>
<td class="cellrowborder" valign="top" width="21.78%" headers="mcps1.1.5.1.2 "><p>TextAlign</p>
</td>
<td class="cellrowborder" valign="top" width="13.51%" headers="mcps1.1.5.1.3 "><p>TextAlign.Start</p>
</td>
<td class="cellrowborder" valign="top" width="46%" headers="mcps1.1.5.1.4 "><p>设置文本水平对齐方式。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.709999999999997%" headers="mcps1.1.5.1.1 "><p>caretColor</p>
</td>
<td class="cellrowborder" valign="top" width="21.78%" headers="mcps1.1.5.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="13.51%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="46%" headers="mcps1.1.5.1.4 "><p>设置输入框光标颜色。</p>
</td>
</tr>
</tbody>
</table>

-   TextAlign枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="22.56%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.44%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.3.1.1 "><p>Start</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.44%" headers="mcps1.1.3.1.2 "><p>水平对齐首部。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.3.1.1 "><p>Center</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.44%" headers="mcps1.1.3.1.2 "><p>水平居中对齐。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.3.1.1 "><p>End</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.44%" headers="mcps1.1.3.1.2 "><p>水平对齐尾部。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section449664852016"></a>

<a name="table952mcpsimp"></a>
<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onChange(callback: (value: string) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>输入发生变化时，触发回调。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section13800193662114"></a>

```
@Entry
@Component
struct TextAreaExample {
  @State text: string = ''

  build() {
    Column() {
      TextArea({ placeholder: 'input your word' })
        .placeholderColor("rgb(0,0,225)")
        .placeholderFont({ size: 30, weight: 100, family: 'cursive', style: FontStyle.Italic })
        .textAlign(TextAlign.Center)
        .caretColor(Color.Blue)
        .height(50)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .fontFamily("sans-serif")
        .fontStyle(FontStyle.Normal)
        .fontColor(Color.Red)
        .onChange((value: string) => {
          this.text = value
        })
      Text(this.text).width('90%')
    }
  }
}
```

![](figures/textarea1.gif)

