# TextArea<a name="EN-US_TOPIC_0000001192755102"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

Provides the multi-line text input component.

## Required Permissions<a name="section781125411508"></a>

None

## Child Component<a name="section53281531154915"></a>

N/A

## APIs<a name="section1989913519718"></a>

TextArea\(value?: \{ placeholder?: string \}\)

-   Parameters

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.44%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.950000000000001%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.49%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>placeholder</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.44%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.950000000000001%" headers="mcps1.1.6.1.4 "><p id="p793071910214"><a name="p793071910214"></a><a name="p793071910214"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.49%" headers="mcps1.1.6.1.5 "><p id="p693016198212"><a name="p693016198212"></a><a name="p693016198212"></a>Text displayed when there is no input.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section18430105671014"></a>

In addition to the attributes in  [Universal Attributes](ts-universal-attributes.md), the following attributes are supported.

<a name="table1687143610336"></a>
<table><thead align="left"><tr id="row66873367334"><th class="cellrowborder" valign="top" width="18.709999999999997%" id="mcps1.1.5.1.1"><p id="p16687193613335"><a name="p16687193613335"></a><a name="p16687193613335"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="21.78%" id="mcps1.1.5.1.2"><p id="p18687163610335"><a name="p18687163610335"></a><a name="p18687163610335"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="13.51%" id="mcps1.1.5.1.3"><p id="p968743623315"><a name="p968743623315"></a><a name="p968743623315"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="46%" id="mcps1.1.5.1.4"><p id="p11687136103313"><a name="p11687136103313"></a><a name="p11687136103313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row12688133616332"><td class="cellrowborder" valign="top" width="18.709999999999997%" headers="mcps1.1.5.1.1 "><p id="p1368817365334"><a name="p1368817365334"></a><a name="p1368817365334"></a>placeholderColor</p>
</td>
<td class="cellrowborder" valign="top" width="21.78%" headers="mcps1.1.5.1.2 "><p id="p468853614333"><a name="p468853614333"></a><a name="p468853614333"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="13.51%" headers="mcps1.1.5.1.3 "><p id="p116887362331"><a name="p116887362331"></a><a name="p116887362331"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="46%" headers="mcps1.1.5.1.4 "><p id="p18688103623318"><a name="p18688103623318"></a><a name="p18688103623318"></a>Placeholder text color.</p>
</td>
</tr>
<tr id="row1688536173315"><td class="cellrowborder" valign="top" width="18.709999999999997%" headers="mcps1.1.5.1.1 "><p id="p3688103623316"><a name="p3688103623316"></a><a name="p3688103623316"></a>placeholderFont</p>
</td>
<td class="cellrowborder" valign="top" width="21.78%" headers="mcps1.1.5.1.2 "><p id="p13224252496"><a name="p13224252496"></a><a name="p13224252496"></a>{</p>
<p id="p1897895315911"><a name="p1897895315911"></a><a name="p1897895315911"></a>size?: number,</p>
<p id="p259423124117"><a name="p259423124117"></a><a name="p259423124117"></a>weight?:number | <a href="ts-universal-attributes-text-style.md#li24391125115311">FontWeight</a>,</p>
<p id="p1543313581098"><a name="p1543313581098"></a><a name="p1543313581098"></a>family?: string,</p>
<p id="p17521110141018"><a name="p17521110141018"></a><a name="p17521110141018"></a>style?: <a href="ts-universal-attributes-text-style.md#li6906111945316">FontStyle</a></p>
<p id="p3688636103319"><a name="p3688636103319"></a><a name="p3688636103319"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="13.51%" headers="mcps1.1.5.1.3 "><p id="p126881366333"><a name="p126881366333"></a><a name="p126881366333"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="46%" headers="mcps1.1.5.1.4 "><p id="p45161321194215"><a name="p45161321194215"></a><a name="p45161321194215"></a>Placeholder text style.</p>
<a name="ul183144224216"></a><a name="ul183144224216"></a><ul id="ul183144224216"><li><strong id="b1641473203114"><a name="b1641473203114"></a><a name="b1641473203114"></a>size</strong>: font size. If the value is of the number type, the unit fp is used.</li><li><strong id="b57593612338"><a name="b57593612338"></a><a name="b57593612338"></a>weight</strong>: font weight. For the number type, the value ranges from 100 to 900, at an interval of 100. The default value is <strong id="b3756155873216"><a name="b3756155873216"></a><a name="b3756155873216"></a>400</strong>. A larger value indicates a larger font weight.</li><li><strong id="b19118103403918"><a name="b19118103403918"></a><a name="b19118103403918"></a>family</strong>: font family. Use commas (,) to separate multiple fonts. The priority of the fonts is the sequence in which they are placed. An example value is <strong id="b1114919274018"><a name="b1114919274018"></a><a name="b1114919274018"></a>Arial, sans-serif</strong>.</li><li><strong id="b657431218403"><a name="b657431218403"></a><a name="b657431218403"></a>style</strong>: font style.</li></ul>
</td>
</tr>
<tr id="row268917361332"><td class="cellrowborder" valign="top" width="18.709999999999997%" headers="mcps1.1.5.1.1 "><p id="p106891536113312"><a name="p106891536113312"></a><a name="p106891536113312"></a>textAlign</p>
</td>
<td class="cellrowborder" valign="top" width="21.78%" headers="mcps1.1.5.1.2 "><p id="p176892363339"><a name="p176892363339"></a><a name="p176892363339"></a>TextAlign</p>
</td>
<td class="cellrowborder" valign="top" width="13.51%" headers="mcps1.1.5.1.3 "><p id="p9689183633317"><a name="p9689183633317"></a><a name="p9689183633317"></a>TextAlign.Start</p>
</td>
<td class="cellrowborder" valign="top" width="46%" headers="mcps1.1.5.1.4 "><p id="p186898362335"><a name="p186898362335"></a><a name="p186898362335"></a>Sets the text horizontal alignment mode.</p>
</td>
</tr>
<tr id="row768983643315"><td class="cellrowborder" valign="top" width="18.709999999999997%" headers="mcps1.1.5.1.1 "><p id="p1568983673318"><a name="p1568983673318"></a><a name="p1568983673318"></a>caretColor</p>
</td>
<td class="cellrowborder" valign="top" width="21.78%" headers="mcps1.1.5.1.2 "><p id="p4689143616333"><a name="p4689143616333"></a><a name="p4689143616333"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="13.51%" headers="mcps1.1.5.1.3 "><p id="p15689236103316"><a name="p15689236103316"></a><a name="p15689236103316"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="46%" headers="mcps1.1.5.1.4 "><p id="p126899368337"><a name="p126899368337"></a><a name="p126899368337"></a>Sets the color of the cursor in the text box.</p>
</td>
</tr>
</tbody>
</table>

-   TextAlign enumeration description

    <a name="table1889814410423"></a>
    <table><thead align="left"><tr id="row6899649423"><th class="cellrowborder" valign="top" width="22.56%" id="mcps1.1.3.1.1"><p id="p089910424220"><a name="p089910424220"></a><a name="p089910424220"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.44%" id="mcps1.1.3.1.2"><p id="p1389917420424"><a name="p1389917420424"></a><a name="p1389917420424"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16899174204211"><td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.3.1.1 "><p id="p198997424217"><a name="p198997424217"></a><a name="p198997424217"></a>Start</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.44%" headers="mcps1.1.3.1.2 "><p id="p198999494210"><a name="p198999494210"></a><a name="p198999494210"></a>Aligns the header horizontally.</p>
    </td>
    </tr>
    <tr id="row389974144214"><td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.3.1.1 "><p id="p089912415423"><a name="p089912415423"></a><a name="p089912415423"></a>Center</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.44%" headers="mcps1.1.3.1.2 "><p id="p1889944204220"><a name="p1889944204220"></a><a name="p1889944204220"></a>Horizontal center alignment.</p>
    </td>
    </tr>
    <tr id="row1789904154211"><td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.3.1.1 "><p id="p2089918413423"><a name="p2089918413423"></a><a name="p2089918413423"></a>End</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.44%" headers="mcps1.1.3.1.2 "><p id="p48998419426"><a name="p48998419426"></a><a name="p48998419426"></a>Align the tail horizontally.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Events<a name="section449664852016"></a>

<a name="table952mcpsimp"></a>
<table><thead align="left"><tr id="row959mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p963mcpsimp"><a name="p963mcpsimp"></a><a name="p963mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p967mcpsimp"><a name="p967mcpsimp"></a><a name="p967mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row163041291058"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p1352619001912"><a name="p1352619001912"></a><a name="p1352619001912"></a>onChange(callback: (value: string) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p772854496"><a name="p772854496"></a><a name="p772854496"></a>When the input changes, the callback function is triggered.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section13800193662114"></a>

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

