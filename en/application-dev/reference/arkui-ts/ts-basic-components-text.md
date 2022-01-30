# Text<a name="EN-US_TOPIC_0000001192915102"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The  **<Text\>**  component is used to display a paragraph of textual information.

## Required Permissions<a name="section1895361713156"></a>

None

## Child Components<a name="section1444658131617"></a>

The  **<Text\>**  component can contain the child component  [<Span\>](ts-basic-components-span.md).

## APIs<a name="section1383178131719"></a>

Text\(content?: string\)

-   Parameters

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="13%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.869999999999997%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>content</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p id="p421641117507"><a name="p421641117507"></a><a name="p421641117507"></a>''</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p693016198212"><a name="p693016198212"></a><a name="p693016198212"></a>Text content, which is the content of the child component <strong id="b151011122422"><a name="b151011122422"></a><a name="b151011122422"></a>&lt;Span&gt;</strong>. This parameter does not take effect when the child component <strong id="b1465974710421"><a name="b1465974710421"></a><a name="b1465974710421"></a>&lt;Span&gt;</strong> is contained.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section175320400172"></a>

<a name="table952mcpsimp"></a>
<table><thead align="left"><tr id="row959mcpsimp"><th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.1"><p id="p961mcpsimp"><a name="p961mcpsimp"></a><a name="p961mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="24.14%" id="mcps1.1.5.1.2"><p id="p963mcpsimp"><a name="p963mcpsimp"></a><a name="p963mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="33.35%" id="mcps1.1.5.1.3"><p id="p965mcpsimp"><a name="p965mcpsimp"></a><a name="p965mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="26.51%" id="mcps1.1.5.1.4"><p id="p967mcpsimp"><a name="p967mcpsimp"></a><a name="p967mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1007mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p1009mcpsimp"><a name="p1009mcpsimp"></a><a name="p1009mcpsimp"></a>textAlign</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.5.1.2 "><p id="p1011mcpsimp"><a name="p1011mcpsimp"></a><a name="p1011mcpsimp"></a><a href="#li16164333289">TextAlign</a></p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.1.5.1.3 "><p id="p1013mcpsimp"><a name="p1013mcpsimp"></a><a name="p1013mcpsimp"></a>Start</p>
</td>
<td class="cellrowborder" valign="top" width="26.51%" headers="mcps1.1.5.1.4 "><p id="p1015mcpsimp"><a name="p1015mcpsimp"></a><a name="p1015mcpsimp"></a>Text alignment mode of multiple lines of text.</p>
</td>
</tr>
<tr id="row1029mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p1031mcpsimp"><a name="p1031mcpsimp"></a><a name="p1031mcpsimp"></a>textOverflow</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.5.1.2 "><p id="p1033mcpsimp"><a name="p1033mcpsimp"></a><a name="p1033mcpsimp"></a>{overflow: <a href="#li3837144314284">TextOverflow</a>}</p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.1.5.1.3 "><p id="p11638840426"><a name="p11638840426"></a><a name="p11638840426"></a>{overflow: TextOverflow.Clip}</p>
</td>
<td class="cellrowborder" valign="top" width="26.51%" headers="mcps1.1.5.1.4 "><p id="p1037mcpsimp"><a name="p1037mcpsimp"></a><a name="p1037mcpsimp"></a>Display mode when the text is too long.</p>
</td>
</tr>
<tr id="row1041mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p1043mcpsimp"><a name="p1043mcpsimp"></a><a name="p1043mcpsimp"></a>maxLines</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.5.1.2 "><p id="p1045mcpsimp"><a name="p1045mcpsimp"></a><a name="p1045mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.1.5.1.3 "><p id="p1047mcpsimp"><a name="p1047mcpsimp"></a><a name="p1047mcpsimp"></a>Infinity</p>
</td>
<td class="cellrowborder" valign="top" width="26.51%" headers="mcps1.1.5.1.4 "><p id="p1049mcpsimp"><a name="p1049mcpsimp"></a><a name="p1049mcpsimp"></a>Maximum number of lines in the text.</p>
</td>
</tr>
<tr id="row543016141359"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p139641823122615"><a name="p139641823122615"></a><a name="p139641823122615"></a>lineHeight</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.5.1.2 "><p id="p18964172311266"><a name="p18964172311266"></a><a name="p18964172311266"></a>Length</p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.1.5.1.3 "><p id="p896413235265"><a name="p896413235265"></a><a name="p896413235265"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="26.51%" headers="mcps1.1.5.1.4 "><p id="p159651223202613"><a name="p159651223202613"></a><a name="p159651223202613"></a>Text line height. If the value is less than or equal to <strong id="b17795171804316"><a name="b17795171804316"></a><a name="b17795171804316"></a>0</strong>, the line height is not limited and the font size is adaptive. If the value of the number type, the unit fp is used.</p>
</td>
</tr>
<tr id="row163041291058"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p63041596511"><a name="p63041596511"></a><a name="p63041596511"></a>decoration</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.5.1.2 "><p id="p143131349610"><a name="p143131349610"></a><a name="p143131349610"></a>{</p>
<p id="p282514269218"><a name="p282514269218"></a><a name="p282514269218"></a>type: <a href="#li182215492284">TextDecorationType</a>,</p>
<p id="p1236612297213"><a name="p1236612297213"></a><a name="p1236612297213"></a>color?: Color</p>
<p id="p4225174410519"><a name="p4225174410519"></a><a name="p4225174410519"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.1.5.1.3 "><p id="p9718489210"><a name="p9718489210"></a><a name="p9718489210"></a>{</p>
<p id="p18996125116210"><a name="p18996125116210"></a><a name="p18996125116210"></a>type: TextDecorationType.None,</p>
<p id="p027574216212"><a name="p027574216212"></a><a name="p027574216212"></a>color: Color.Black</p>
<p id="p23053910513"><a name="p23053910513"></a><a name="p23053910513"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="26.51%" headers="mcps1.1.5.1.4 "><p id="p12726144512611"><a name="p12726144512611"></a><a name="p12726144512611"></a>Style and color of the text decorative line.</p>
</td>
</tr>
<tr id="row936214307719"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p33620302718"><a name="p33620302718"></a><a name="p33620302718"></a>baselineOffset</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.5.1.2 "><p id="p63637301577"><a name="p63637301577"></a><a name="p63637301577"></a>Length</p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.1.5.1.3 "><p id="p19363163018717"><a name="p19363163018717"></a><a name="p19363163018717"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="26.51%" headers="mcps1.1.5.1.4 "><p id="p163635301075"><a name="p163635301075"></a><a name="p163635301075"></a>Offset of the text baseline.</p>
</td>
</tr>
<tr id="row2542164915718"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p1542849972"><a name="p1542849972"></a><a name="p1542849972"></a>textCase</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.5.1.2 "><p id="p1454214498717"><a name="p1454214498717"></a><a name="p1454214498717"></a><a href="#li6551155619287">TextCase</a></p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.1.5.1.3 "><p id="p85421449872"><a name="p85421449872"></a><a name="p85421449872"></a>Normal</p>
</td>
<td class="cellrowborder" valign="top" width="26.51%" headers="mcps1.1.5.1.4 "><p id="p75429492719"><a name="p75429492719"></a><a name="p75429492719"></a>Text case.</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li16164333289"></a>TextAlign enums

    <a name="table12144170154116"></a>
    <table><thead align="left"><tr id="row1314430184118"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p1614414014416"><a name="p1614414014416"></a><a name="p1614414014416"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p1314415074113"><a name="p1314415074113"></a><a name="p1314415074113"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row61441505417"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p191443034117"><a name="p191443034117"></a><a name="p191443034117"></a>Center</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p121447017412"><a name="p121447017412"></a><a name="p121447017412"></a>The text is center-aligned.</p>
    </td>
    </tr>
    <tr id="row20144801418"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p17145110194110"><a name="p17145110194110"></a><a name="p17145110194110"></a>Start</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p171454015415"><a name="p171454015415"></a><a name="p171454015415"></a>The text is aligned with the direction in which the text is written.</p>
    </td>
    </tr>
    <tr id="row914570194112"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p714511012418"><a name="p714511012418"></a><a name="p714511012418"></a>End</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p101451704415"><a name="p101451704415"></a><a name="p101451704415"></a>The text is aligned with the opposite direction in which the text is written.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li3837144314284"></a>TextOverflow enums

    <a name="table189737541745"></a>
    <table><thead align="left"><tr id="row1797335419414"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p1597314541412"><a name="p1597314541412"></a><a name="p1597314541412"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p1197365410413"><a name="p1197365410413"></a><a name="p1197365410413"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row149730541412"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1797310541344"><a name="p1797310541344"></a><a name="p1797310541344"></a>Clip</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p13973105416419"><a name="p13973105416419"></a><a name="p13973105416419"></a>Extra text is truncated.</p>
    </td>
    </tr>
    <tr id="row189732054048"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1597313541444"><a name="p1597313541444"></a><a name="p1597313541444"></a>Ellipsis</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p119741754244"><a name="p119741754244"></a><a name="p119741754244"></a>The ellipsis (...) is used for extra-long text.</p>
    </td>
    </tr>
    <tr id="row1997445416413"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p13974185410411"><a name="p13974185410411"></a><a name="p13974185410411"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p69744541410"><a name="p69744541410"></a><a name="p69744541410"></a>No truncation or ellipsis is used for extra-long text.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li182215492284"></a>TextDecorationType enums

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>Underline</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245211421393"><a name="p1245211421393"></a><a name="p1245211421393"></a>An underline is used.</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p54523425398"><a name="p54523425398"></a><a name="p54523425398"></a>LineThrough</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p745215426391"><a name="p745215426391"></a><a name="p745215426391"></a>A strikethrough is used.</p>
    </td>
    </tr>
    <tr id="row9452134213392"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p510719111403"><a name="p510719111403"></a><a name="p510719111403"></a>Overline</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p154533425394"><a name="p154533425394"></a><a name="p154533425394"></a>An overline is used.</p>
    </td>
    </tr>
    <tr id="row1345313424399"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1766215124010"><a name="p1766215124010"></a><a name="p1766215124010"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245319426394"><a name="p1245319426394"></a><a name="p1245319426394"></a>No decorative line is used.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li6551155619287"></a>TextCase enums

    <a name="table5287134045213"></a>
    <table><thead align="left"><tr id="row02871840155217"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p10287184045214"><a name="p10287184045214"></a><a name="p10287184045214"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p1287164085212"><a name="p1287164085212"></a><a name="p1287164085212"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row228717404527"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p928710407525"><a name="p928710407525"></a><a name="p928710407525"></a>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1128719404524"><a name="p1128719404524"></a><a name="p1128719404524"></a>The original case of the text is retained.</p>
    </td>
    </tr>
    <tr id="row62871040175213"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p0287140135215"><a name="p0287140135215"></a><a name="p0287140135215"></a>LowerCase</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p028784055213"><a name="p028784055213"></a><a name="p028784055213"></a>All letters in the text are in lowercase.</p>
    </td>
    </tr>
    <tr id="row19287164065216"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p0288114019528"><a name="p0288114019528"></a><a name="p0288114019528"></a>UpperCase</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p11288104015214"><a name="p11288104015214"></a><a name="p11288104015214"></a>All letters in the text are in uppercase.</p>
    </td>
    </tr>
    </tbody>
    </table>


>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The  **<Text\>**  component cannot contain both the text and the child component  **<Span\>**. If both of them exist, only the content in  **<Span\>**  is displayed.

## Example<a name="section13800193662114"></a>

```
@Entry
@Component
struct TextExample1 {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('lineHeight').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text with the line height set This is the text with the line height set This is the text with the line height set.')
        .lineHeight(25).fontSize(12).border({ width: 1 }).padding(10)

      Text('TextOverflow').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the setting of textOverflow to none text content This is the setting of textOverflow to none text content.')
        .textOverflow({ overflow: TextOverflow.None })
        .fontSize(12).border({ width: 1 }).padding(10)
      Text('This is the setting of textOverflow to Clip text content This is the setting of textOverflow to Clip text content.')
        .textOverflow({ overflow: TextOverflow.Clip })
        .maxLines(1).fontSize(12).border({ width: 1 }).padding(10)
      Text('This is set textOverflow to Ellipsis text content This is set textOverflow to Ellipsis text content.')
        .textOverflow({ overflow: TextOverflow.Ellipsis })
        .maxLines(1).fontSize(12).border({ width: 1 }).padding(10)

      Text('decoration').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text content with the decoration set to Underline and the color set to Red.')
        .decoration({ type: TextDecorationType.Underline, color: Color.Red })
        .fontSize(12).border({ width: 1 }).padding(10)
      Text('This is the text content with the decoration set to LineThrough and the color set to Red.')
        .decoration({ type: TextDecorationType.LineThrough, color: Color.Red })
        .fontSize(12).border({ width: 1 }).padding(10)
      Text('This is the text content with the decoration set to Overline and the color set to Red.')
        .decoration({ type: TextDecorationType.Overline, color: Color.Red })
        .fontSize(12).border({ width: 1 }).padding(10)
    }.height(600).width(350).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![](figures/text1.gif)

```
@Entry
@Component
struct TextExample2 {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('textCase').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text content with textCase set to Normal.')
        .textCase(TextCase.Normal)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with textCase set to LowerCase.')
        .textCase(TextCase.LowerCase)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with textCase set to UpperCase.')
        .textCase(TextCase.UpperCase)
        .fontSize(12).border({ width: 1 }).padding(10)

      Text('textAlign').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text content with textAlign set to Center.')
        .textAlign(TextAlign.Center)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with textAlign set to Start.')
        .textAlign(TextAlign.Start)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with textAlign set to End.')
        .textAlign(TextAlign.End)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')

      Text('baselineOffset').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text content with baselineOffset set to 10.')
        .baselineOffset(10).fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with baselineOffset set to 30.')
        .baselineOffset(30).fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with baselineOffset set to -10.')
        .baselineOffset(-10).fontSize(12).border({ width: 1 }).padding(10).width('100%')
    }.height(700).width(350).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![](figures/text2.gif)

