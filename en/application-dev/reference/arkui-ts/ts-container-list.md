# List<a name="EN-US_TOPIC_0000001237555113"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The  **<List\>**  component provides a list container that presents a series of list items arranged in a column with the same width. It supports presentations of the same type of data in a multiple and coherent row style, for example, images or text.

## Required Permissions<a name="section0178213104516"></a>

None

## Child Components<a name="section872315253456"></a>

This component contains the child component  [<ListItem\>](ts-container-listitem.md).

## APIs<a name="section297911264713"></a>

List\(value:\{space?: number, initialIndex?: number\}\)

-   Parameters

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.959999999999999%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.04%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.88%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>space</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.04%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p id="p029607124312"><a name="p029607124312"></a><a name="p029607124312"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p693016198212"><a name="p693016198212"></a><a name="p693016198212"></a>Spacing between list items.</p>
    </td>
    </tr>
    <tr id="row1924045711917"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p72401857201915"><a name="p72401857201915"></a><a name="p72401857201915"></a>initialIndex</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.1.6.1.2 "><p id="p14240957171918"><a name="p14240957171918"></a><a name="p14240957171918"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.04%" headers="mcps1.1.6.1.3 "><p id="p62402572196"><a name="p62402572196"></a><a name="p62402572196"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p id="p4240957101912"><a name="p4240957101912"></a><a name="p4240957101912"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p4240145781913"><a name="p4240145781913"></a><a name="p4240145781913"></a>Item displayed at the beginning of the component when the current list is loaded for the first time, that is, the first item to be displayed. If the configured sequence number is greater than the sequence number of the last item, the setting does not take effect.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section10148192384712"></a>

<a name="table1474mcpsimp"></a>
<table><thead align="left"><tr id="row1481mcpsimp"><th class="cellrowborder" valign="top" width="14.08%" id="mcps1.1.5.1.1"><p id="p1483mcpsimp"><a name="p1483mcpsimp"></a><a name="p1483mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25.46%" id="mcps1.1.5.1.2"><p id="p1485mcpsimp"><a name="p1485mcpsimp"></a><a name="p1485mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="15.790000000000001%" id="mcps1.1.5.1.3"><p id="p1487mcpsimp"><a name="p1487mcpsimp"></a><a name="p1487mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="44.67%" id="mcps1.1.5.1.4"><p id="p1489mcpsimp"><a name="p1489mcpsimp"></a><a name="p1489mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1490mcpsimp"><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p id="p1492mcpsimp"><a name="p1492mcpsimp"></a><a name="p1492mcpsimp"></a>listDirection</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p id="p1494mcpsimp"><a name="p1494mcpsimp"></a><a name="p1494mcpsimp"></a><a href="ts-appendix-enums.md#section1397918486200">Axis</a></p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p id="p1496mcpsimp"><a name="p1496mcpsimp"></a><a name="p1496mcpsimp"></a>Vertical</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p id="p17471191815396"><a name="p17471191815396"></a><a name="p17471191815396"></a>Direction in which the list items are arranged. For details, see <a href="#li7849892417">Axis enums</a>.</p>
</td>
</tr>
<tr id="row1501mcpsimp"><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p id="p1503mcpsimp"><a name="p1503mcpsimp"></a><a name="p1503mcpsimp"></a>divider</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p id="p12218118141515"><a name="p12218118141515"></a><a name="p12218118141515"></a>{</p>
<p id="p255942119159"><a name="p255942119159"></a><a name="p255942119159"></a>strokeWidth: Length,</p>
<p id="p43412027131515"><a name="p43412027131515"></a><a name="p43412027131515"></a>color?:Color,</p>
<p id="p815211349155"><a name="p815211349155"></a><a name="p815211349155"></a>startMargin?: Length,</p>
<p id="p148515412150"><a name="p148515412150"></a><a name="p148515412150"></a>endMargin?: Length</p>
<p id="p1184352016391"><a name="p1184352016391"></a><a name="p1184352016391"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p id="p1507mcpsimp"><a name="p1507mcpsimp"></a><a name="p1507mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p id="p1509mcpsimp"><a name="p1509mcpsimp"></a><a name="p1509mcpsimp"></a>Style of the divider for the list items. By default, there is no divider.</p>
<p id="p6920226101412"><a name="p6920226101412"></a><a name="p6920226101412"></a><strong id="b1383233713406"><a name="b1383233713406"></a><a name="b1383233713406"></a>strokeWidth</strong>: stroke width of the divider.</p>
<p id="p131957614154"><a name="p131957614154"></a><a name="p131957614154"></a><strong id="b793185424014"><a name="b793185424014"></a><a name="b793185424014"></a>color</strong>: color of the divider.</p>
<p id="p119577207152"><a name="p119577207152"></a><a name="p119577207152"></a><strong id="b1884840114117"><a name="b1884840114117"></a><a name="b1884840114117"></a>startMargin</strong>: distance between the divider and the start of the list.</p>
<p id="p1923017271175"><a name="p1923017271175"></a><a name="p1923017271175"></a><strong id="b1116613794113"><a name="b1116613794113"></a><a name="b1116613794113"></a>endMargin</strong>: distance between the divider and the end of the list.</p>
</td>
</tr>
<tr id="row1513mcpsimp"><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p id="p1515mcpsimp"><a name="p1515mcpsimp"></a><a name="p1515mcpsimp"></a>editMode</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p id="p1517mcpsimp"><a name="p1517mcpsimp"></a><a name="p1517mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p id="p20134833915"><a name="p20134833915"></a><a name="p20134833915"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p id="p1521mcpsimp"><a name="p1521mcpsimp"></a><a name="p1521mcpsimp"></a>Whether the <strong id="b1748852594110"><a name="b1748852594110"></a><a name="b1748852594110"></a>&lt;List&gt;</strong> component is in editable mode.</p>
</td>
</tr>
<tr id="row331042411123"><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p id="p1275832125813"><a name="p1275832125813"></a><a name="p1275832125813"></a>edgeEffect</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p id="p5311324191218"><a name="p5311324191218"></a><a name="p5311324191218"></a><a href="#li13407161352416">EdgeEffect</a></p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p id="p13275232125815"><a name="p13275232125815"></a><a name="p13275232125815"></a>Spring</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p id="p1827516324585"><a name="p1827516324585"></a><a name="p1827516324585"></a>Sliding effect. For details, see <a href="#li13407161352416">EdgeEffect enums</a>.</p>
</td>
</tr>
<tr id="row18775128141213"><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p id="p8775122831218"><a name="p8775122831218"></a><a name="p8775122831218"></a>chainAnimation</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p id="p67751028161210"><a name="p67751028161210"></a><a name="p67751028161210"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p id="p888305574219"><a name="p888305574219"></a><a name="p888305574219"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p id="p78841255154210"><a name="p78841255154210"></a><a name="p78841255154210"></a>Whether to display chained animations on this list when it slides or its top and bottom are dragged. The list items are separated with even space, and one item animation starts after the previous animation during basic sliding interactions. The chained animation effect is similar with spring physics.</p>
<a name="ul1490293714519"></a><a name="ul1490293714519"></a><ul id="ul1490293714519"><li><strong id="b6318183104217"><a name="b6318183104217"></a><a name="b6318183104217"></a>false</strong>: No chained animations are displayed.</li><li><strong id="b139221053421"><a name="b139221053421"></a><a name="b139221053421"></a>true</strong>: Chained animations are displayed.</li></ul>
</td>
</tr>
</tbody>
</table>

-   <a name="li13407161352416"></a>EdgeEffect enums

    <a name="table13368194184518"></a>
    <table><thead align="left"><tr id="row163686417455"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p153688444519"><a name="p153688444519"></a><a name="p153688444519"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p136815414459"><a name="p136815414459"></a><a name="p136815414459"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row536834164511"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p3368164134520"><a name="p3368164134520"></a><a name="p3368164134520"></a>Spring</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p33688411457"><a name="p33688411457"></a><a name="p33688411457"></a>Similar to the physical dynamic effect of a spring. After scrolling to the edge, you can continue to scroll for a distance based on the initial speed or by touching the knob of the scrollbar. After you release your hand, the knob is rebounded.</p>
    </td>
    </tr>
    <tr id="row8368154174512"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p63689444519"><a name="p63689444519"></a><a name="p63689444519"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1927035264510"><a name="p1927035264510"></a><a name="p1927035264510"></a>No effect after the scroll bar is moved to the edge.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Events<a name="section5672149135016"></a>

<a name="table268mcpsimp"></a>
<table><thead align="left"><tr id="row274mcpsimp"><th class="cellrowborder" valign="top" width="52.07000000000001%" id="mcps1.1.3.1.1"><p id="p276mcpsimp"><a name="p276mcpsimp"></a><a name="p276mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="47.93%" id="mcps1.1.3.1.2"><p id="p280mcpsimp"><a name="p280mcpsimp"></a><a name="p280mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row281mcpsimp"><td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.3.1.1 "><p id="p283mcpsimp"><a name="p283mcpsimp"></a><a name="p283mcpsimp"></a>onItemDelete(index: number) =&gt; boolean</p>
</td>
<td class="cellrowborder" valign="top" width="47.93%" headers="mcps1.1.3.1.2 "><p id="p19272193554015"><a name="p19272193554015"></a><a name="p19272193554015"></a>Triggered when a list item is deleted.</p>
</td>
</tr>
<tr id="row14368347144014"><td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.3.1.1 "><p id="p44468559402"><a name="p44468559402"></a><a name="p44468559402"></a>onScrollIndex(firstIndex: number, lastIndex: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="47.93%" headers="mcps1.1.3.1.2 "><p id="p6369104717402"><a name="p6369104717402"></a><a name="p6369104717402"></a>Triggered when the start position and end position of the current list are changed.</p>
</td>
</tr>
<tr id="row141733308324"><td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.3.1.1 "><p id="p1217353043218"><a name="p1217353043218"></a><a name="p1217353043218"></a>onItemDragEnter(callback: (event: <a href="#li2640114814351">ItemDragInfo</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" width="47.93%" headers="mcps1.1.3.1.2 "><p id="p23399260547"><a name="p23399260547"></a><a name="p23399260547"></a>Triggered when the list item that is bound to the drag event enters a valid drop target.</p>
<a name="ul1833918269542"></a><a name="ul1833918269542"></a><ul id="ul1833918269542"><li><strong id="b560301120593"><a name="b560301120593"></a><a name="b560301120593"></a>itemIndex</strong>: original index of the list item that is being dragged.</li><li><strong id="b199637243011"><a name="b199637243011"></a><a name="b199637243011"></a>insertIndex</strong>: index of the list item after it is dragged and inserted into the list.</li></ul>
<div class="note" id="note1389615018342"><a name="note1389615018342"></a><a name="note1389615018342"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1589619033415"><a name="p1589619033415"></a><a name="p1589619033415"></a>This event is valid only when the <strong id="b350094618013"><a name="b350094618013"></a><a name="b350094618013"></a>onDrop</strong> event is listened to.</p>
</div></div>
</td>
</tr>
<tr id="row2057824563212"><td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.3.1.1 "><p id="p1167987103713"><a name="p1167987103713"></a><a name="p1167987103713"></a>onItemDragMove(callback: (event: <a href="#li2640114814351">ItemDragInfo</a>, itemIndex: number, insertIndex: number) =&gt; void)</p>
<p id="p186798733715"><a name="p186798733715"></a><a name="p186798733715"></a></p>
</td>
<td class="cellrowborder" valign="top" width="47.93%" headers="mcps1.1.3.1.2 "><p id="p1157864513220"><a name="p1157864513220"></a><a name="p1157864513220"></a>Triggered when the list item that is bound to the drag event enters a valid drop target.</p>
<a name="ul836918413451"></a><a name="ul836918413451"></a><ul id="ul836918413451"><li><strong id="b8247135719415"><a name="b8247135719415"></a><a name="b8247135719415"></a>itemIndex</strong>: original index of the list item that is being dragged.</li><li><strong id="b5579858449"><a name="b5579858449"></a><a name="b5579858449"></a>insertIndex</strong>: index of the list item after it is dragged and inserted into the list.</li></ul>
<div class="note" id="note590016344379"><a name="note590016344379"></a><a name="note590016344379"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1542313448378"><a name="p1542313448378"></a><a name="p1542313448378"></a>This event is valid only when the <strong id="b109221227518"><a name="b109221227518"></a><a name="b109221227518"></a>onDrop</strong> event is listened to.</p>
</div></div>
</td>
</tr>
<tr id="row974815613383"><td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.3.1.1 "><p id="p19672727173815"><a name="p19672727173815"></a><a name="p19672727173815"></a>onItemDragLeave(callback: (event: <a href="#li2640114814351">ItemDragInfo</a>, itemIndex: number) =&gt; void)</p>
<p id="p10672202753811"><a name="p10672202753811"></a><a name="p10672202753811"></a></p>
</td>
<td class="cellrowborder" valign="top" width="47.93%" headers="mcps1.1.3.1.2 "><p id="p656844733810"><a name="p656844733810"></a><a name="p656844733810"></a>Triggered when the list item that is bound to the drag event leaves a valid drop target.</p>
<a name="ul99161456478"></a><a name="ul99161456478"></a><ul id="ul99161456478"><li><strong id="b182438421552"><a name="b182438421552"></a><a name="b182438421552"></a>itemIndex</strong>: original index of the list item that is being dragged.</li></ul>
<div class="note" id="note243419019390"><a name="note243419019390"></a><a name="note243419019390"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p104341033917"><a name="p104341033917"></a><a name="p104341033917"></a>This event is valid only when the <strong id="b1019610147619"><a name="b1019610147619"></a><a name="b1019610147619"></a>onDrop</strong> event is listened to.</p>
</div></div>
</td>
</tr>
<tr id="row1720491343810"><td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.3.1.1 "><p id="p9577114710395"><a name="p9577114710395"></a><a name="p9577114710395"></a>onItemDragStart(callback: (event: <a href="#li2640114814351">ItemDragInfo</a>, itemIndex: number)  =&gt; <a href="../../toctopics/en-us_topic_0000001237475069.md#section2538145016250">CustomBuilder</a>)</p>
<p id="p4577104710392"><a name="p4577104710392"></a><a name="p4577104710392"></a></p>
</td>
<td class="cellrowborder" valign="top" width="47.93%" headers="mcps1.1.3.1.2 "><p id="p182042136385"><a name="p182042136385"></a><a name="p182042136385"></a>Triggered when the list item that is bound to the drag event is dragged for the first time.</p>
<a name="ul1881145784611"></a><a name="ul1881145784611"></a><ul id="ul1881145784611"><li><strong id="b82390280516"><a name="b82390280516"></a><a name="b82390280516"></a>itemIndex</strong>: original index of the list item that is being dragged.</li><li>Return value: floating UI layout of the list item that is being dragged.</li></ul>
<div class="note" id="note1037918101408"><a name="note1037918101408"></a><a name="note1037918101408"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p9379310194011"><a name="p9379310194011"></a><a name="p9379310194011"></a>This event is valid only when the <strong id="b177064346511"><a name="b177064346511"></a><a name="b177064346511"></a>onDrop</strong> event is listened to.</p>
</div></div>
</td>
</tr>
<tr id="row4718518103817"><td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.3.1.1 "><p id="p136755015412"><a name="p136755015412"></a><a name="p136755015412"></a>onItemDrop(callback: (event: <a href="#li2640114814351">ItemDragInfo</a>, itemIndex: number, insertIndex: number, isSuccess: boolean) =&gt; void)</p>
<p id="p1667517004111"><a name="p1667517004111"></a><a name="p1667517004111"></a></p>
</td>
<td class="cellrowborder" valign="top" width="47.93%" headers="mcps1.1.3.1.2 "><p id="p652618815718"><a name="p652618815718"></a><a name="p652618815718"></a>Triggered when the list item that is bound to the drag event is dropped on a valid drop target.</p>
<a name="ul37763355718"></a><a name="ul37763355718"></a><ul id="ul37763355718"><li><strong id="b0833843159"><a name="b0833843159"></a><a name="b0833843159"></a>itemIndex</strong>: original index of the list item that is being dragged.</li><li><strong id="b4895105717514"><a name="b4895105717514"></a><a name="b4895105717514"></a>insertIndex</strong>: index of the list item after it is dragged and inserted into the list.</li><li><strong id="b94071747612"><a name="b94071747612"></a><a name="b94071747612"></a>isSuccess</strong>: whether the insertion is successful after the list item is dropped.</li></ul>
<div class="note" id="note1965019172424"><a name="note1965019172424"></a><a name="note1965019172424"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1965081715421"><a name="p1965081715421"></a><a name="p1965081715421"></a>This event is valid only when the <strong id="b1264511141175"><a name="b1264511141175"></a><a name="b1264511141175"></a>onDrop</strong> event is listened to.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>To enable the editable mode for a list, the following conditions must be met:
>-   **editMode**  is set to  **true**.
>-   The list is bound to the  **onItemDelete**  event and the event returns  **true**  during event callback.
>-   The  **editable**  attribute of  **ListItem**  is set to  **true**.
>To enable for a list item, the following conditions must be met:
>-   **editMode**  is set to  **true**.
>-   The list item is bound to the  **onItemDragStart**  event and the event returns a floating UI during event callback.

-   <a name="li2640114814351"></a>ItemDragInfo attributes

    <a name="table157652053174913"></a>
    <table><thead align="left"><tr id="row18765165318494"><th class="cellrowborder" valign="top" width="20.09%" id="mcps1.1.4.1.1"><p id="p18765145315496"><a name="p18765145315496"></a><a name="p18765145315496"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.22%" id="mcps1.1.4.1.2"><p id="p37651453144919"><a name="p37651453144919"></a><a name="p37651453144919"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.69%" id="mcps1.1.4.1.3"><p id="p376585317492"><a name="p376585317492"></a><a name="p376585317492"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1476685312494"><td class="cellrowborder" valign="top" width="20.09%" headers="mcps1.1.4.1.1 "><p id="p3766753204913"><a name="p3766753204913"></a><a name="p3766753204913"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.22%" headers="mcps1.1.4.1.2 "><p id="p1576614537496"><a name="p1576614537496"></a><a name="p1576614537496"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.69%" headers="mcps1.1.4.1.3 "><p id="p976617538499"><a name="p976617538499"></a><a name="p976617538499"></a>X-coordinate of the item that is being dragged.</p>
    </td>
    </tr>
    <tr id="row776635311495"><td class="cellrowborder" valign="top" width="20.09%" headers="mcps1.1.4.1.1 "><p id="p4766145315497"><a name="p4766145315497"></a><a name="p4766145315497"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.22%" headers="mcps1.1.4.1.2 "><p id="p11766153104919"><a name="p11766153104919"></a><a name="p11766153104919"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.69%" headers="mcps1.1.4.1.3 "><p id="p16766195315494"><a name="p16766195315494"></a><a name="p16766195315494"></a>Y-coordinate of the item that is being dragged.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section02653368513"></a>

```
@Entry
@Component
struct ListExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State editFlag: boolean = false

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column() {
        List({ space: 20, initialIndex: 0 }) {
          ForEach(this.arr, (item) => {
            ListItem() {
              Text('' + item)
                .width('100%').height(100).fontSize(16)
                .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
            }.editable(true)
          }, item => item)
        }
        .listDirection(Axis.Vertical) //Arrangement direction
        .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 }) // Divider line
        .edgeEffect(EdgeEffect.None) // No effect when sliding to the edge
        .chainAnimation(false) // Chained animations are disabled.
        .onScrollIndex((firstIndex: number, lastIndex: number) => {
          console.info('first' + firstIndex)
          console.info('last' + lastIndex)
        })
        .editMode(this.editFlag)
        .onItemDelete((index: number) => {
          console.info(this.arr[index] + 'Delete')
          this.arr.splice(index, 1)
          console.info(JSON.stringify(this.arr))
          this.editFlag = false
          return true
        }).width('90%')
      }.width('100%')

      Button('edit list')
        .onClick(() => {
          this.editFlag = !this.editFlag
        }).margin({ top: 5, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![](figures/list.gif)

```
@Entry
@Component
struct DragListExample {
  @State number1: string[] = ['0', '1', '2']
  @State number2: string[] = ['one', 'two', 'three']
  @State text: string = ''
  @State bool1: boolean = false
  @State bool2: boolean = false

  @Builder pixelMapBuilder() {
    Text('-1')
      .width('100%').height(100).fontSize(16)
      .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
  }

  build() {
    Column() {
      List() {
        ForEach(this.number1, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xF666FF)
          }
        }, item => item)
      }
      .editMode(true)
      .width('90%').divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 })
      .onItemDelete((index: number) => {
        console.info(this.Number1[index] + 'Delete')
        this.Number1.splice(index, 1)
        console.info(JSON.stringify(this.Number1))
        return true
      })
      .onItemDragStart((event: ItemDragInfo, itemIndex: number) => {
        this.bool1 = true
        this.text = this.number1[itemIndex]
        console.log("List1 onItemDragStart, itemIndex:" + itemIndex + ",  ItemDragInfo:"+`${JSON.stringify(event)}`)
        return this.pixelMapBuilder
      })
      .onItemDragEnter((event: ItemDragInfo) => {
        console.log("List1 onItemDragEnter")
      })
      .onItemDragMove((event: ItemDragInfo, itemIndex: number, insertIndex: number) => {
        console.log("List1 onItemDragMove, itemIndex:" + itemIndex + ", insertIndex:" + insertIndex)
      })
      .onItemDragLeave((event: ItemDragInfo, itemIndex: number) => {
        console.log("List1 onItemDragLeave, itemIndex:" + itemIndex)
      })
      .onItemDrop((event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => {
        if (isSuccess) {
          if (this.bool2) {
            this.number2.splice(itemIndex, 1)
            this.number1.splice(insertIndex, 0, this.text)
            this.bool1 = false
            this.bool2 = false
          } else if (this.bool1) {
            this.number1.splice(itemIndex, 1)
            this.number1.splice(insertIndex, 0, this.text)
            this.bool1 = false
            this.bool2 = false
          }
        }
        console.log("List1 onItemDrop, itemIndex:" + itemIndex + ", insertIndex:" + insertIndex + ", isSuccess:" + isSuccess)
      })
      Divider().strokeWidth(5).color(0x2788D9).lineCap(LineCapStyle.Round).margin(20)
      List() {
        ForEach(this.Number2, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFF888)
          }
        }, item => item)
      }
      .edgeEffect(EdgeEffect.None)
      .width('90%')
      .editMode(true)
      .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 })
      .onItemDragStart((event: ItemDragInfo, itemIndex: number) => {
        this.bool2 = true
        this.text = this.number2[itemIndex]
        console.log("List2 onItemDragStart, itemIndex:" + itemIndex)
        return this.pixelMapBuilder
      })
      .onItemDragEnter((event: ItemDragInfo) => {
        console.log("List2 onItemDragEnter")
      })
      .onItemDragMove((event: ItemDragInfo, itemIndex: number, insertIndex: number) => {
        console.log("List2 onItemDragMove, itemIndex:" + itemIndex + ", insertIndex:" + insertIndex)
      })
      .onItemDragLeave((event: ItemDragInfo, itemIndex: number) => {
        console.log("List2 onItemDragLeave, itemIndex:" + itemIndex)
      })
      .onItemDrop((event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => {
        if (isSuccess) {
          if (this.bool1) {
            this.number1.splice(itemIndex, 1)
            this.number2.splice(insertIndex, 0, this.text)
            this.bool1 = false
            this.bool2 = false
          } else if (this.bool2) {
            this.number2.splice(itemIndex, 1)
            this.number2.splice(insertIndex, 0, this.text)
            this.bool1 = false
            this.bool2 = false
          }
        }
        console.log("List2 onItemDrop, itemIndex:" + itemIndex + ", insertIndex:" + insertIndex + ", isSuccess:" + isSuccess)
      })
    }.width('100%').height('100%').backgroundColor(0xE600000).padding({ top: 25 })
  }
}
```

![](figures/gif-4.gif)

