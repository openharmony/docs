# TextInput<a name="EN-US_TOPIC_0000001192595168"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The  **<TextInput\>**  component provides single-line text input.

## Required Permissions<a name="section781125411508"></a>

None

## Child Components<a name="section1037371523612"></a>

None

## APIs<a name="section33135508"></a>

TextInput\(value?: \{ placeholder?: string \}\)

-   Parameters

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.499999999999998%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>placeholder</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p id="p92371110145314"><a name="p92371110145314"></a><a name="p92371110145314"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p793071910214"><a name="p793071910214"></a><a name="p793071910214"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p693016198212"><a name="p693016198212"></a><a name="p693016198212"></a>Text displayed when there is no input.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section18430105671014"></a>

In addition to the attributes in  [Universal Attributes](ts-universal-attributes.md), the following attributes are supported.

<a name="table1687143610336"></a>
<table><thead align="left"><tr id="row66873367334"><th class="cellrowborder" valign="top" width="15.98%" id="mcps1.1.5.1.1"><p id="p16687193613335"><a name="p16687193613335"></a><a name="p16687193613335"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="27.500000000000004%" id="mcps1.1.5.1.2"><p id="p18687163610335"><a name="p18687163610335"></a><a name="p18687163610335"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="13.239999999999998%" id="mcps1.1.5.1.3"><p id="p968743623315"><a name="p968743623315"></a><a name="p968743623315"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="43.28%" id="mcps1.1.5.1.4"><p id="p11687136103313"><a name="p11687136103313"></a><a name="p11687136103313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row12688133616332"><td class="cellrowborder" valign="top" width="15.98%" headers="mcps1.1.5.1.1 "><p id="p1368817365334"><a name="p1368817365334"></a><a name="p1368817365334"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p id="p468853614333"><a name="p468853614333"></a><a name="p468853614333"></a><a href="#li1018842194211">InputType</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p id="p116887362331"><a name="p116887362331"></a><a name="p116887362331"></a>InputType.Normal</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p id="p3812938142619"><a name="p3812938142619"></a><a name="p3812938142619"></a>Input box type.</p>
</td>
</tr>
<tr id="row12220165182710"><td class="cellrowborder" valign="top" width="15.98%" headers="mcps1.1.5.1.1 "><p id="p122135162713"><a name="p122135162713"></a><a name="p122135162713"></a>placeholderColor</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p id="p222119513275"><a name="p222119513275"></a><a name="p222119513275"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p id="p182215552714"><a name="p182215552714"></a><a name="p182215552714"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p id="p11222145152719"><a name="p11222145152719"></a><a name="p11222145152719"></a>Placeholder color.</p>
</td>
</tr>
<tr id="row1688536173315"><td class="cellrowborder" valign="top" width="15.98%" headers="mcps1.1.5.1.1 "><p id="p3688103623316"><a name="p3688103623316"></a><a name="p3688103623316"></a>placeholderFont</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p id="p882493814282"><a name="p882493814282"></a><a name="p882493814282"></a>{</p>
<p id="p184037108449"><a name="p184037108449"></a><a name="p184037108449"></a>size?: Length,</p>
<p id="p19398101644016"><a name="p19398101644016"></a><a name="p19398101644016"></a>weight?: number | <a href="ts-universal-attributes-text-style.md#li24391125115311">FontWeight</a>,</p>
<p id="p72012120614"><a name="p72012120614"></a><a name="p72012120614"></a>family?: string,</p>
<p id="p1146164442811"><a name="p1146164442811"></a><a name="p1146164442811"></a>style?: <a href="ts-basic-components-textarea.md#table952mcpsimp">FontStyle</a></p>
<p id="p1997730195410"><a name="p1997730195410"></a><a name="p1997730195410"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p id="p126881366333"><a name="p126881366333"></a><a name="p126881366333"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p id="p12813172410123"><a name="p12813172410123"></a><a name="p12813172410123"></a>Placeholder text style.</p>
<a name="ul183144224216"></a><a name="ul183144224216"></a><ul id="ul183144224216"><li><strong id="b1289754510410"><a name="b1289754510410"></a><a name="b1289754510410"></a>size</strong>: font size. If the value is of the number type, the unit fp is used.</li><li><strong id="b1643995074118"><a name="b1643995074118"></a><a name="b1643995074118"></a>weight</strong>: font weight. For the number type, the value ranges from 100 to 900, at an interval of 100. The default value is <strong id="b1044545020416"><a name="b1044545020416"></a><a name="b1044545020416"></a>400</strong>. A larger value indicates a larger font weight.</li><li><strong id="b553705184110"><a name="b553705184110"></a><a name="b553705184110"></a>family</strong>: font family. Use commas (,) to separate multiple fonts. The priority of the fonts is the sequence in which they are placed. An example value is <strong id="b587695310415"><a name="b587695310415"></a><a name="b587695310415"></a>Arial, sans-serif</strong>.</li><li><strong id="b96676548411"><a name="b96676548411"></a><a name="b96676548411"></a>style</strong>: font style.</li></ul>
</td>
</tr>
<tr id="row1816315198291"><td class="cellrowborder" valign="top" width="15.98%" headers="mcps1.1.5.1.1 "><p id="p1024618557297"><a name="p1024618557297"></a><a name="p1024618557297"></a>enterKeyType</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p id="p1116431919292"><a name="p1116431919292"></a><a name="p1116431919292"></a><a href="#li1231618102427">EnterKeyType</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p id="p181641919162912"><a name="p181641919162912"></a><a name="p181641919162912"></a>EnterKeyType.Done</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p id="p143216412306"><a name="p143216412306"></a><a name="p143216412306"></a>How the Enter key is labeled.</p>
</td>
</tr>
<tr id="row768983643315"><td class="cellrowborder" valign="top" width="15.98%" headers="mcps1.1.5.1.1 "><p id="p1568983673318"><a name="p1568983673318"></a><a name="p1568983673318"></a>caretColor</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p id="p4689143616333"><a name="p4689143616333"></a><a name="p4689143616333"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p id="p15689236103316"><a name="p15689236103316"></a><a name="p15689236103316"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p id="p126899368337"><a name="p126899368337"></a><a name="p126899368337"></a>Color of the caret (also known as the text insertion cursor).</p>
</td>
</tr>
<tr id="row1072711357529"><td class="cellrowborder" valign="top" width="15.98%" headers="mcps1.1.5.1.1 "><p id="p455216340525"><a name="p455216340525"></a><a name="p455216340525"></a>maxLength</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p id="p831934135317"><a name="p831934135317"></a><a name="p831934135317"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p id="p20553113445216"><a name="p20553113445216"></a><a name="p20553113445216"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p id="p755333417520"><a name="p755333417520"></a><a name="p755333417520"></a>Maximum number of characters in the text input.</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li1231618102427"></a>EnterKeyType enums

    <a name="table8101631142317"></a>
    <table><thead align="left"><tr id="row1610133132320"><th class="cellrowborder" valign="top" width="26.13%" id="mcps1.1.3.1.1"><p id="p101083192316"><a name="p101083192316"></a><a name="p101083192316"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.87%" id="mcps1.1.3.1.2"><p id="p6101631102315"><a name="p6101631102315"></a><a name="p6101631102315"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row51063112236"><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p id="p01016313235"><a name="p01016313235"></a><a name="p01016313235"></a>Go</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p id="p18112319232"><a name="p18112319232"></a><a name="p18112319232"></a>The Enter key is labeled "Go."</p>
    </td>
    </tr>
    <tr id="row141110316236"><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p id="p011431152310"><a name="p011431152310"></a><a name="p011431152310"></a>Search</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p id="p1011131122310"><a name="p1011131122310"></a><a name="p1011131122310"></a>The Enter key is labeled "Search."</p>
    </td>
    </tr>
    <tr id="row11110317238"><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p id="p61163118233"><a name="p61163118233"></a><a name="p61163118233"></a>Send</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p id="p21163116234"><a name="p21163116234"></a><a name="p21163116234"></a>The Enter key is labeled "Send."</p>
    </td>
    </tr>
    <tr id="row41183114239"><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p id="p2011631162310"><a name="p2011631162310"></a><a name="p2011631162310"></a>Next</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p id="p1111931202317"><a name="p1111931202317"></a><a name="p1111931202317"></a>The Enter key is labeled "Next."</p>
    </td>
    </tr>
    <tr id="row811173110237"><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p id="p11117313230"><a name="p11117313230"></a><a name="p11117313230"></a>Done</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p id="p1411331182311"><a name="p1411331182311"></a><a name="p1411331182311"></a>The Enter key is labeled "Done."</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li1018842194211"></a>InputType enums

    <a name="table1399312391899"></a>
    <table><thead align="left"><tr id="row12993143919912"><th class="cellrowborder" valign="top" width="26.13%" id="mcps1.1.3.1.1"><p id="p12993183910920"><a name="p12993183910920"></a><a name="p12993183910920"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.87%" id="mcps1.1.3.1.2"><p id="p1499317391799"><a name="p1499317391799"></a><a name="p1499317391799"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row699420391094"><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p id="p79942391992"><a name="p79942391992"></a><a name="p79942391992"></a>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p id="p49949391798"><a name="p49949391798"></a><a name="p49949391798"></a>Normal input mode.</p>
    </td>
    </tr>
    <tr id="row189944396915"><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p id="p19949391291"><a name="p19949391291"></a><a name="p19949391291"></a>Password</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p id="p899433910917"><a name="p899433910917"></a><a name="p899433910917"></a>Password input mode.</p>
    </td>
    </tr>
    <tr id="row3994153916912"><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p id="p2099416394913"><a name="p2099416394913"></a><a name="p2099416394913"></a>Email</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p id="p29941393911"><a name="p29941393911"></a><a name="p29941393911"></a>Email address input mode.</p>
    </td>
    </tr>
    <tr id="row1899410394914"><td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.1.3.1.1 "><p id="p19941339195"><a name="p19941339195"></a><a name="p19941339195"></a>Number</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.87%" headers="mcps1.1.3.1.2 "><p id="p16994103919917"><a name="p16994103919917"></a><a name="p16994103919917"></a>Digit input mode.</p>
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
<tbody><tr id="row163041291058"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p1352619001912"><a name="p1352619001912"></a><a name="p1352619001912"></a>onChange(value: string) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p772854496"><a name="p772854496"></a><a name="p772854496"></a>Triggered when the input changes.</p>
</td>
</tr>
<tr id="row799082415332"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p146301030123313"><a name="p146301030123313"></a><a name="p146301030123313"></a>onSubmit(callback: (enterKey: <a href="#li1231618102427">EnterKeyType</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1499122417333"><a name="p1499122417333"></a><a name="p1499122417333"></a>Triggered when the Enter key on the physical or soft keyboard is pressed.</p>
</td>
</tr>
<tr id="row784037123313"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p5593444143313"><a name="p5593444143313"></a><a name="p5593444143313"></a>onEditChanged(callback: (isEditing: boolean) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p19312125443411"><a name="p19312125443411"></a><a name="p19312125443411"></a>Triggered when the input status changes.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section3619717314"></a>

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

