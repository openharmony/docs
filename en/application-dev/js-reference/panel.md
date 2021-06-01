# panel<a name="EN-US_TOPIC_0000001115974732"></a>

-   [Permission List](#en-us_topic_0000001062321291_section11257113618419)
-   [Child Component](#en-us_topic_0000001062321291_section19368335134016)
-   [Attribute](#en-us_topic_0000001062321291_section1100152194018)
-   [Style](#en-us_topic_0000001062321291_section1137118175437)
-   [Event](#en-us_topic_0000001062321291_section1614413538447)
-   [Method](#en-us_topic_0000001062321291_section165301745164719)
-   [Example Code](#en-us_topic_0000001062321291_section36743614499)

The  **<panel\>**  component is a slidable panel. It provides a lightweight content display window with flexible sizes. The  **<panel\>**  component pops up when it is displayed.

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 5.

## Permission List<a name="en-us_topic_0000001062321291_section11257113618419"></a>

None

## Child Component<a name="en-us_topic_0000001062321291_section19368335134016"></a>

Yes

## Attribute<a name="en-us_topic_0000001062321291_section1100152194018"></a>

<a name="en-us_topic_0000001062321291_table20633101642315"></a>
<table><thead align="left"><tr id="en-us_topic_0000001062321291_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p942mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p942mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p942mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.169999999999998%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p944mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p944mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p944mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.43%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p946mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p946mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p946mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001062321291_p824610360217"><a name="en-us_topic_0000001062321291_p824610360217"></a><a name="en-us_topic_0000001062321291_p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p948mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p948mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p948mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001062321291_row741201424216"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_p1555482064215"><a name="en-us_topic_0000001062321291_p1555482064215"></a><a name="en-us_topic_0000001062321291_p1555482064215"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_p195541120124212"><a name="en-us_topic_0000001062321291_p195541120124212"></a><a name="en-us_topic_0000001062321291_p195541120124212"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_p05541220194219"><a name="en-us_topic_0000001062321291_p05541220194219"></a><a name="en-us_topic_0000001062321291_p05541220194219"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p155541220104216"><a name="en-us_topic_0000001062321291_p155541220104216"></a><a name="en-us_topic_0000001062321291_p155541220104216"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_p175541420104219"><a name="en-us_topic_0000001062321291_p175541420104219"></a><a name="en-us_topic_0000001062321291_p175541420104219"></a>Type of the slidable panel. This attribute cannot be dynamically changed. Available values are as follows:</p>
<a name="en-us_topic_0000001062321291_ul15554620204219"></a><a name="en-us_topic_0000001062321291_ul15554620204219"></a><ul id="en-us_topic_0000001062321291_ul15554620204219"><li><p id="en-us_topic_0000001062321291_p555417208423"><a name="en-us_topic_0000001062321291_p555417208423"></a><a name="en-us_topic_0000001062321291_p555417208423"></a><strong id="en-us_topic_0000001062321291_b75944818331"><a name="en-us_topic_0000001062321291_b75944818331"></a><a name="en-us_topic_0000001062321291_b75944818331"></a>minibar</strong>: A minibar panel displays content in the minibar area or a large (fullscreen-like) area.</p>
</li><li><p id="en-us_topic_0000001062321291_p15554920204216"><a name="en-us_topic_0000001062321291_p15554920204216"></a><a name="en-us_topic_0000001062321291_p15554920204216"></a><strong id="en-us_topic_0000001062321291_b1346141143510"><a name="en-us_topic_0000001062321291_b1346141143510"></a><a name="en-us_topic_0000001062321291_b1346141143510"></a>foldable</strong>: A foldable panel displays permanent content in a large (fullscreen-like), medium-sized (halfscreen-like), or small area.</p>
</li><li><p id="en-us_topic_0000001062321291_p35545206423"><a name="en-us_topic_0000001062321291_p35545206423"></a><a name="en-us_topic_0000001062321291_p35545206423"></a><strong id="en-us_topic_0000001062321291_b11403369397"><a name="en-us_topic_0000001062321291_b11403369397"></a><a name="en-us_topic_0000001062321291_b11403369397"></a>temporary</strong>: A temporary panel displays content in a large (fullscreen-like) or medium-sized (halfscreen-like) area.</p>
</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row1815511615424"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_p1755419206420"><a name="en-us_topic_0000001062321291_p1755419206420"></a><a name="en-us_topic_0000001062321291_p1755419206420"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_p135544206422"><a name="en-us_topic_0000001062321291_p135544206422"></a><a name="en-us_topic_0000001062321291_p135544206422"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_p13554192010427"><a name="en-us_topic_0000001062321291_p13554192010427"></a><a name="en-us_topic_0000001062321291_p13554192010427"></a>full</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p155418205426"><a name="en-us_topic_0000001062321291_p155418205426"></a><a name="en-us_topic_0000001062321291_p155418205426"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_p655415206425"><a name="en-us_topic_0000001062321291_p655415206425"></a><a name="en-us_topic_0000001062321291_p655415206425"></a>Initial status of the slidable panel. Available values are as follows:</p>
<a name="en-us_topic_0000001062321291_ol6554220154216"></a><a name="en-us_topic_0000001062321291_ol6554220154216"></a><ol id="en-us_topic_0000001062321291_ol6554220154216"><li><p id="en-us_topic_0000001062321291_p12554520154216"><a name="en-us_topic_0000001062321291_p12554520154216"></a><a name="en-us_topic_0000001062321291_p12554520154216"></a><strong id="en-us_topic_0000001062321291_b13227603353"><a name="en-us_topic_0000001062321291_b13227603353"></a><a name="en-us_topic_0000001062321291_b13227603353"></a>mini</strong>: Displays a <strong id="en-us_topic_0000001062321291_b18230114212422"><a name="en-us_topic_0000001062321291_b18230114212422"></a><a name="en-us_topic_0000001062321291_b18230114212422"></a>minibar</strong> or <strong id="en-us_topic_0000001062321291_b3615459421"><a name="en-us_topic_0000001062321291_b3615459421"></a><a name="en-us_topic_0000001062321291_b3615459421"></a>foldable</strong> panel in its minimum size. This attribute does not take effect for <strong id="en-us_topic_0000001062321291_b65822124212"><a name="en-us_topic_0000001062321291_b65822124212"></a><a name="en-us_topic_0000001062321291_b65822124212"></a>temporary</strong> panels.</p>
</li><li><p id="en-us_topic_0000001062321291_p1955422014218"><a name="en-us_topic_0000001062321291_p1955422014218"></a><a name="en-us_topic_0000001062321291_p1955422014218"></a><strong id="en-us_topic_0000001062321291_b7388181616411"><a name="en-us_topic_0000001062321291_b7388181616411"></a><a name="en-us_topic_0000001062321291_b7388181616411"></a>half</strong>: Displays a <strong id="en-us_topic_0000001062321291_b14130550104216"><a name="en-us_topic_0000001062321291_b14130550104216"></a><a name="en-us_topic_0000001062321291_b14130550104216"></a>foldable</strong> or <strong id="en-us_topic_0000001062321291_b1347545294213"><a name="en-us_topic_0000001062321291_b1347545294213"></a><a name="en-us_topic_0000001062321291_b1347545294213"></a>temporary</strong> panel in a medium-sized (halfscreen-like) area. This attribute does not take effect for <strong id="en-us_topic_0000001062321291_b17461163424318"><a name="en-us_topic_0000001062321291_b17461163424318"></a><a name="en-us_topic_0000001062321291_b17461163424318"></a>minibar</strong> panels.</p>
</li><li><p id="en-us_topic_0000001062321291_p15541020134214"><a name="en-us_topic_0000001062321291_p15541020134214"></a><a name="en-us_topic_0000001062321291_p15541020134214"></a><strong id="en-us_topic_0000001062321291_b56264913506"><a name="en-us_topic_0000001062321291_b56264913506"></a><a name="en-us_topic_0000001062321291_b56264913506"></a>full</strong>: Displays a panel in a large (fullscree-like) area.</p>
</li></ol>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row1213173154220"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_p855432019421"><a name="en-us_topic_0000001062321291_p855432019421"></a><a name="en-us_topic_0000001062321291_p855432019421"></a>dragbar</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_p155482015422"><a name="en-us_topic_0000001062321291_p155482015422"></a><a name="en-us_topic_0000001062321291_p155482015422"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_p1955552064210"><a name="en-us_topic_0000001062321291_p1955552064210"></a><a name="en-us_topic_0000001062321291_p1955552064210"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p755542024213"><a name="en-us_topic_0000001062321291_p755542024213"></a><a name="en-us_topic_0000001062321291_p755542024213"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_p135551520114215"><a name="en-us_topic_0000001062321291_p135551520114215"></a><a name="en-us_topic_0000001062321291_p135551520114215"></a>Whether to enable a drag bar. The value <strong id="en-us_topic_0000001062321291_b899416435214"><a name="en-us_topic_0000001062321291_b899416435214"></a><a name="en-us_topic_0000001062321291_b899416435214"></a>true</strong> indicates that the drag bar will be displayed, and <strong id="en-us_topic_0000001062321291_b1834810239526"><a name="en-us_topic_0000001062321291_b1834810239526"></a><a name="en-us_topic_0000001062321291_b1834810239526"></a>false</strong> indicates the opposite.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row827211578416"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_p55550201428"><a name="en-us_topic_0000001062321291_p55550201428"></a><a name="en-us_topic_0000001062321291_p55550201428"></a>fullheight</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_p2055572012425"><a name="en-us_topic_0000001062321291_p2055572012425"></a><a name="en-us_topic_0000001062321291_p2055572012425"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_p145551220104214"><a name="en-us_topic_0000001062321291_p145551220104214"></a><a name="en-us_topic_0000001062321291_p145551220104214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p1555182013429"><a name="en-us_topic_0000001062321291_p1555182013429"></a><a name="en-us_topic_0000001062321291_p1555182013429"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_p16555102011423"><a name="en-us_topic_0000001062321291_p16555102011423"></a><a name="en-us_topic_0000001062321291_p16555102011423"></a>Panel height in the <strong id="en-us_topic_0000001062321291_b190616511539"><a name="en-us_topic_0000001062321291_b190616511539"></a><a name="en-us_topic_0000001062321291_b190616511539"></a>full</strong> mode. The default value is the screen height minus 8 px.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row9344751124116"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_p10555162017420"><a name="en-us_topic_0000001062321291_p10555162017420"></a><a name="en-us_topic_0000001062321291_p10555162017420"></a>halfheight</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_p1055572011422"><a name="en-us_topic_0000001062321291_p1055572011422"></a><a name="en-us_topic_0000001062321291_p1055572011422"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_p19555192018423"><a name="en-us_topic_0000001062321291_p19555192018423"></a><a name="en-us_topic_0000001062321291_p19555192018423"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p5555720134214"><a name="en-us_topic_0000001062321291_p5555720134214"></a><a name="en-us_topic_0000001062321291_p5555720134214"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_p17555320194211"><a name="en-us_topic_0000001062321291_p17555320194211"></a><a name="en-us_topic_0000001062321291_p17555320194211"></a>Panel height in the <strong id="en-us_topic_0000001062321291_b360733265415"><a name="en-us_topic_0000001062321291_b360733265415"></a><a name="en-us_topic_0000001062321291_b360733265415"></a>half</strong> mode. The default value is half of the screen height.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row278634674117"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_p18556132014422"><a name="en-us_topic_0000001062321291_p18556132014422"></a><a name="en-us_topic_0000001062321291_p18556132014422"></a>miniheight</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_p5556920194212"><a name="en-us_topic_0000001062321291_p5556920194212"></a><a name="en-us_topic_0000001062321291_p5556920194212"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_p15561207425"><a name="en-us_topic_0000001062321291_p15561207425"></a><a name="en-us_topic_0000001062321291_p15561207425"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p55565208428"><a name="en-us_topic_0000001062321291_p55565208428"></a><a name="en-us_topic_0000001062321291_p55565208428"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_p115561020164217"><a name="en-us_topic_0000001062321291_p115561020164217"></a><a name="en-us_topic_0000001062321291_p115561020164217"></a>Panel height in the <strong id="en-us_topic_0000001062321291_b634712315173"><a name="en-us_topic_0000001062321291_b634712315173"></a><a name="en-us_topic_0000001062321291_b634712315173"></a>mini</strong> mode. The default value is <strong id="en-us_topic_0000001062321291_b1170192112410"><a name="en-us_topic_0000001062321291_b1170192112410"></a><a name="en-us_topic_0000001062321291_b1170192112410"></a>48px</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row36332165231"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p952mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p952mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p952mcpsimp"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p954mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p954mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p954mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p956mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p956mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p956mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p42461736102118"><a name="en-us_topic_0000001062321291_p42461736102118"></a><a name="en-us_topic_0000001062321291_p42461736102118"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p958mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p958mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p958mcpsimp"></a>Unique ID of a component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row13633131616239"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p961mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p961mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p961mcpsimp"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p963mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p963mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p963mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p965mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p965mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p965mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p17246836142119"><a name="en-us_topic_0000001062321291_p17246836142119"></a><a name="en-us_topic_0000001062321291_p17246836142119"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p967mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p967mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p967mcpsimp"></a>Style declaration of a component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row10634131610230"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p970mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p970mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p970mcpsimp"></a>class</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p972mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p972mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p972mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p974mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p974mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p974mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p324614367213"><a name="en-us_topic_0000001062321291_p324614367213"></a><a name="en-us_topic_0000001062321291_p324614367213"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p976mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p976mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p976mcpsimp"></a>Style class of a component, which is used to refer to a style table.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row1634171618236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_p1786251117156"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_p1786251117156"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_p1786251117156"></a>ref</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_p1086241119157"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_p1086241119157"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_p1086241119157"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_p586281111151"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_p586281111151"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_p586281111151"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p1624612362219"><a name="en-us_topic_0000001062321291_p1624612362219"></a><a name="en-us_topic_0000001062321291_p1624612362219"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_p113416153342"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_p113416153342"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_p113416153342"></a>Used to register reference information of child elements<span id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_ph5815920163518"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_ph5815920163518"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_ph5815920163518"></a> or child components</span>. The reference information is registered with the parent component on <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_b08212202354"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_b08212202354"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_b08212202354"></a>$refs</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row1263451617236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p997mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p997mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p997mcpsimp"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p999mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p999mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p999mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p1001mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p1001mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p1001mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p22471736132114"><a name="en-us_topic_0000001062321291_p22471736132114"></a><a name="en-us_topic_0000001062321291_p22471736132114"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p1003mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p1003mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050831187_en-us_topic_0000000000611464_p1003mcpsimp"></a>Attribute set for components to facilitate data storage and reading.</p>
</td>
</tr>
</tbody>
</table>

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>Currently, the  **<panel\>**  component does not support rendering attributes, including  **for**,  **if**, and  **show**.

## Style<a name="en-us_topic_0000001062321291_section1137118175437"></a>

<a name="en-us_topic_0000001062321291_table1744514388541"></a>
<table><thead align="left"><tr id="en-us_topic_0000001062321291_row1244614388545"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1060mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1060mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1060mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1062mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1062mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1062mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1064mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1064mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1064mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001062321291_p117421754619"><a name="en-us_topic_0000001062321291_p117421754619"></a><a name="en-us_topic_0000001062321291_p117421754619"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1066mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1066mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1066mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001062321291_row18446638145412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1088mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1088mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1088mcpsimp"></a>padding</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1090mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1090mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1090mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1092mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1092mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1092mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p19729127112814"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p19729127112814"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p19729127112814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><div class="p" id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1094mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1094mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1094mcpsimp"></a>The attribute can have one to four values:<a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul15202134923211"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul15202134923211"></a><ul id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul15202134923211"><li><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p10614155353215"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p10614155353215"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p10614155353215"></a>If you set only one value, it specifies the padding for four sides.</p>
</li><li><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p10614175393216"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p10614175393216"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p10614175393216"></a>If you set two values, the first value specifies the top and bottom padding, and the second value specifies the left and right padding.</p>
</li><li><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p8614205393214"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p8614205393214"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p8614205393214"></a>If you set three values, the first value specifies the top padding, the second value specifies the left and right padding, and the third value specifies the bottom padding.</p>
</li><li><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p106141853193215"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p106141853193215"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p106141853193215"></a>If you set four values, they respectively specify the padding for top, right, bottom, and left sides (in clockwise order).</p>
</li></ul>
</div>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row24464380544"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1097mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1097mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1097mcpsimp"></a>padding-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1099mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1099mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1099mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1101mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1101mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1101mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p11729374289"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p11729374289"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p11729374289"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1103mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1103mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1103mcpsimp"></a>Left, top, right, and bottom padding (in px).</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row1144723845412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p769124717365"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p769124717365"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p769124717365"></a>padding-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p157617124374"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p157617124374"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p157617124374"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1069144703616"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1069144703616"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1069144703616"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1373027182819"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1373027182819"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1373027182819"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1269184753610"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1269184753610"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1269184753610"></a>Start and end padding.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row11447438175410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1106mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1106mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1106mcpsimp"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1108mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1108mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1108mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1110mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1110mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1110mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p4730774285"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p4730774285"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p4730774285"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1112mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1112mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1112mcpsimp"></a>Shorthand attribute to set margins for all sides in a declaration. The attribute can have one to four values:</p>
<a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul5333133311105"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul5333133311105"></a><ul id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul5333133311105"><li><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p03345339103"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p03345339103"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p03345339103"></a>If you set only one value, it specifies the margin for all the four sides.</p>
</li><li><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1133420334108"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1133420334108"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1133420334108"></a>If you set two values, the first value is for the top and bottom sides and the second value for the left and right sides.</p>
</li><li><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p193341533191015"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p193341533191015"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p193341533191015"></a>If you set three values, the first value is for the top, the second value for the left and right, and the third value for the bottom.</p>
</li><li><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p733412334102"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p733412334102"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p733412334102"></a>If you set four values, they are margins for top, right, bottom, and left sides, respectively.</p>
</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row144473383544"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1115mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1115mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1115mcpsimp"></a>margin-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1117mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1117mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1117mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1119mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1119mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1119mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p773013742811"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p773013742811"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p773013742811"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1121mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1121mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1121mcpsimp"></a>Left, top, right, and bottom margins.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row944743811541"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p9492107123816"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p9492107123816"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p9492107123816"></a>margin-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p157617124374_1"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p157617124374_1"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p157617124374_1"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1549213793811"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1549213793811"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1549213793811"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p117511744618"><a name="en-us_topic_0000001062321291_p117511744618"></a><a name="en-us_topic_0000001062321291_p117511744618"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1049212715388"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1049212715388"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1049212715388"></a>Start and end margins.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row16447238155411"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1124mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1124mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1124mcpsimp"></a>border</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1126mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1126mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1126mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1128mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1128mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1128mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p11175131715467"><a name="en-us_topic_0000001062321291_p11175131715467"></a><a name="en-us_topic_0000001062321291_p11175131715467"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1130mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1130mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1130mcpsimp"></a>Shorthand attribute to set all borders. You can set <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b79128342503"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b79128342503"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b79128342503"></a>border-width</strong>, <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b9366173919505"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b9366173919505"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b9366173919505"></a>border-style</strong>, and <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b184351248205019"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b184351248205019"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b184351248205019"></a>border-color</strong> in sequence. Default values are used for attributes that are not set.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row4447138115414"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1133mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1133mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1133mcpsimp"></a>border-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p513631613319"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p513631613319"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p513631613319"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1137mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1137mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1137mcpsimp"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p617531717464"><a name="en-us_topic_0000001062321291_p617531717464"></a><a name="en-us_topic_0000001062321291_p617531717464"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p342285712314"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p342285712314"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p342285712314"></a>Shorthand attribute to set the style for all borders. Available values are as follows:</p>
<a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul1470834505612"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul1470834505612"></a><ul id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul1470834505612"><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b143453286360"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b143453286360"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b143453286360"></a>dotted</strong>: Dotted border. The radius of a dot is half of border-width.</li><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b792117280367"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b792117280367"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b792117280367"></a>dashed</strong>: Dashed border</li></ul>
<a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul15621125545612"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul15621125545612"></a><ul id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul15621125545612"><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1335862963610"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1335862963610"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1335862963610"></a>solid</strong>: Solid border</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row1656512239262"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p119531437370"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p119531437370"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p119531437370"></a>border-[left|top|right|bottom]-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p129532037175"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p129532037175"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p129532037175"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p495312372717"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p495312372717"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p495312372717"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p169534375717"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p169534375717"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p169534375717"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p595353718719"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p595353718719"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p595353718719"></a>Styles of the left, top, right, and bottom borders. The available values are <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b17769171311540"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b17769171311540"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b17769171311540"></a>dotted</strong>, <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b237141519547"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b237141519547"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b237141519547"></a>dashed</strong>, and <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b8949161613540"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b8949161613540"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b8949161613540"></a>solid</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row19448113811542"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1142mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1142mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1142mcpsimp"></a>border-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1144mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1144mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1144mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1146mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1146mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1146mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p67303762810"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p67303762810"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p67303762810"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1148mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1148mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1148mcpsimp"></a>Shorthand attribute to set the borders for every side respectively. You can set <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b122415514554"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b122415514554"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b122415514554"></a>border-width</strong>, <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b12296178135513"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b12296178135513"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b12296178135513"></a>border-style</strong>, and <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1129701210553"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1129701210553"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1129701210553"></a>border-color</strong> in sequence. Default values are used for attributes that are not set.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row124481638165417"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1151mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1151mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1151mcpsimp"></a>border-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1153mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1153mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1153mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1155mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1155mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1155mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p16175131724618"><a name="en-us_topic_0000001062321291_p16175131724618"></a><a name="en-us_topic_0000001062321291_p16175131724618"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1157mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1157mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1157mcpsimp"></a>Shorthand attribute to set the width of all borders<span id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ph07997369365"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ph07997369365"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ph07997369365"></a>, or separately set the width of each border</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row54481038165410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1160mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1160mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1160mcpsimp"></a>border-[left|top|right|bottom]-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1162mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1162mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1162mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1164mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1164mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1164mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p11175151717466"><a name="en-us_topic_0000001062321291_p11175151717466"></a><a name="en-us_topic_0000001062321291_p11175151717466"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1166mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1166mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1166mcpsimp"></a>Attribute to set widths of left, top, right, and bottom borders.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row1744817385547"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1169mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1169mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1169mcpsimp"></a>border-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1171mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1171mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1171mcpsimp"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1173mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1173mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1173mcpsimp"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p1017518177465"><a name="en-us_topic_0000001062321291_p1017518177465"></a><a name="en-us_topic_0000001062321291_p1017518177465"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1175mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1175mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1175mcpsimp"></a>Shorthand attribute to set the color of all borders<span id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ph9587639113619"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ph9587639113619"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ph9587639113619"></a>, or separately set the color of each border</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row844813835410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1178mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1178mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1178mcpsimp"></a>border-[left|top|right|bottom]-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1180mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1180mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1180mcpsimp"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1182mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1182mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1182mcpsimp"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_p11175417184611"><a name="en-us_topic_0000001062321291_p11175417184611"></a><a name="en-us_topic_0000001062321291_p11175417184611"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1184mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1184mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1184mcpsimp"></a>Attribute to set colors of left, top, right, and bottom borders.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row944813389540"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1187mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1187mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1187mcpsimp"></a>border-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1189mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1189mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1189mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1191mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1191mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1191mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p67306752816"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p67306752816"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p67306752816"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p18998933174117"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p18998933174117"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p18998933174117"></a>Attribute to set the radius of round borders of an element. <span id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ph1249443123611"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ph1249443123611"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ph1249443123611"></a>This attribute cannot be used to set the width or color of a specific border. To set the width or color, you need to set <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b124211434362"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b124211434362"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b124211434362"></a>border-width</strong> or <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b124894383615"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b124894383615"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b124894383615"></a>border-color</strong> for all the borders at the same time.</span></p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row104494382546"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1198mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1198mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1198mcpsimp"></a>border-[top|bottom]-[left|right]-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1200mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1200mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1200mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1202mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1202mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1202mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p27305718283"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p27305718283"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p27305718283"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1204mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1204mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1204mcpsimp"></a>Attribute to receptively set the radii of upper-left, upper-right, lower-right, and lower-left rounded corners</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row1344912384548"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1207mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1207mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1207mcpsimp"></a>background</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1209mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1209mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1209mcpsimp"></a>&lt;linear-gradient&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1211mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1211mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1211mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p15730197132811"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p15730197132811"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p15730197132811"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1213mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1213mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1213mcpsimp"></a>This attribute supports <a href="gradient-styles.md#EN-US_TOPIC_0000001115974726">Gradient Styles</a> only but is not compatible with <strong id="en-us_topic_0000001062321291_b10695758175019"><a name="en-us_topic_0000001062321291_b10695758175019"></a><a name="en-us_topic_0000001062321291_b10695758175019"></a>background-color</strong> or <strong id="en-us_topic_0000001062321291_b1369505895010"><a name="en-us_topic_0000001062321291_b1369505895010"></a><a name="en-us_topic_0000001062321291_b1369505895010"></a>background-image</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row15449838185416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1217mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1217mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1217mcpsimp"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1219mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1219mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1219mcpsimp"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1221mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1221mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1221mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p17730577282"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p17730577282"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p17730577282"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1223mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1223mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1223mcpsimp"></a>Background color.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row54491338115412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1226mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1226mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1226mcpsimp"></a>background-image</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1228mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1228mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1228mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1230mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1230mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1230mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p7730976285"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p7730976285"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p7730976285"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1232mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1232mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1232mcpsimp"></a>Background image. Currently, this attribute is not compatible with <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b17699154763620"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b17699154763620"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b17699154763620"></a>background-color</strong> or <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b87001647163613"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b87001647163613"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b87001647163613"></a>background</strong>. Both Internet and local image resources are supported.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row6449238185416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p15157115065817"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p15157115065817"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p15157115065817"></a>background-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul1065173641310"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul1065173641310"></a><ul id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul1065173641310"><li>string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p8157195019585"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p8157195019585"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p8157195019585"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p137309714282"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p137309714282"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p137309714282"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p91971112114318"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p91971112114318"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p91971112114318"></a>Background image size.</p>
<a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul41331853154111"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul41331853154111"></a><ul id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul41331853154111"><li>The <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1229715499365"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1229715499365"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1229715499365"></a>string</strong> values are as follows:<a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul13611494111"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul13611494111"></a><ul id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul13611494111"><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b4759749163610"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b4759749163610"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b4759749163610"></a>contain</strong>: Expands the image to the maximum size so that the height and width of the image are applicable to the content area.</li><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b136485011365"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b136485011365"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b136485011365"></a>cover</strong>: Extends the background image to a large enough size so that the background image completely covers the background area. Some parts of the image may not be displayed in the background localization area.</li><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1425512535366"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1425512535366"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1425512535366"></a>auto</strong>: The original image width-height ratio is retained.</li></ul>
</li><li>The two <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b13309145193614"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b13309145193614"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b13309145193614"></a>&lt;length&gt;</strong> values are as follows:<p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1840244924418"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1840244924418"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1840244924418"></a>Width and height of the background image. The first value indicates the width, and the second value indicates the height. If you only set one value, the other value is set to <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b146661156143617"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b146661156143617"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b146661156143617"></a>auto</strong> by default.</p>
</li><li>The two <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1667415763613"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1667415763613"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1667415763613"></a>&lt;percentage&gt;</strong> values are as follows:<p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p17936154410457"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p17936154410457"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p17936154410457"></a>Width and height of the background image in percentage of the parent element. The first value indicates the width, and the second value indicates the height. If you only set one value, the other value is set to <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b17190164371"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b17190164371"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b17190164371"></a>auto</strong> by default.</p>
</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row94491238155415"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1235mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1235mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1235mcpsimp"></a>background-repeat</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1237mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1237mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1237mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1239mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1239mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1239mcpsimp"></a>repeat</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1673015702810"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1673015702810"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1673015702810"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1241mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1241mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1241mcpsimp"></a>Repeating attribute of a background image. By default, a background image is repeated both horizontally and vertically.</p>
<a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul8236153103612"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul8236153103612"></a><ul id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul8236153103612"><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1363463710"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1363463710"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1363463710"></a>repeat</strong>: Draws images along the x-axis and y-axis at the same time.</li><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b267416916377"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b267416916377"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b267416916377"></a>repeat-x</strong>: Draws images along the x-axis.</li><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b625561011379"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b625561011379"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b625561011379"></a>repeat-y</strong>: Draws images along the y-axis.</li><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1122181133715"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1122181133715"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1122181133715"></a>no-repeat</strong>: The image is not drawn repeatedly.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row94491738105419"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1244mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1244mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1244mcpsimp"></a>background-position</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul8874155216502"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul8874155216502"></a><ul id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul8874155216502"><li>string string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1248mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1248mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1248mcpsimp"></a>0px 0px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p173010720280"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p173010720280"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p173010720280"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul1590812103363"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul1590812103363"></a><ul id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul1590812103363"><li>Using keywords: If only one keyword is specified, the other value is <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b997011116376"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b997011116376"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b997011116376"></a>center</strong> by default. The two values define the horizontal position and vertical position, respectively.<a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul1453531734716"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul1453531734716"></a><ul id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul1453531734716"><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b0982111273712"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b0982111273712"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b0982111273712"></a>left</strong>: leftmost in the horizontal direction</li><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b866713583912"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b866713583912"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b866713583912"></a>right</strong>: rightmost in the horizontal direction</li><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b5886013193716"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b5886013193716"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b5886013193716"></a>top</strong>: top in the vertical direction</li><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b84197142376"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b84197142376"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b84197142376"></a>bottom</strong>: bottom in the vertical direction</li><li><strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b14894114103710"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b14894114103710"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b14894114103710"></a>center</strong>: center position</li></ul>
</li></ul>
<a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul10908121023615"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul10908121023615"></a><ul id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_ul10908121023615"><li>Using <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b11401615193715"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b11401615193715"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b11401615193715"></a>&lt;length&gt;</strong>: The first value indicates the horizontal position, and the second value indicates the vertical position. <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1341381819379"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1341381819379"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1341381819379"></a>0 0</strong> indicates the upper left corner. The unit is pixel. If only one value is specified, the other one is <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b48671516183714"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b48671516183714"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b48671516183714"></a>50%</strong>.</li><li>Using <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b5492717163712"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b5492717163712"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b5492717163712"></a>&lt;percentage&gt;</strong>: The first value indicates the horizontal position, and the second value indicates the vertical position. <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b164741723183712"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b164741723183712"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b164741723183712"></a>0% 0%</strong> indicates the upper left corner. <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b64022245377"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b64022245377"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b64022245377"></a>100% 100%</strong> indicates the lower right corner. If only one value is specified, the other one is <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b7893424163718"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b7893424163718"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b7893424163718"></a>50%</strong>.</li><li>Using both <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b154811725193718"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b154811725193718"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b154811725193718"></a>&lt;percentage&gt;</strong> and <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b34834254377"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b34834254377"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b34834254377"></a>&lt;length&gt;</strong>.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row20450143885416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p134581712103910"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p134581712103910"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p134581712103910"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1267mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1267mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1267mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1269mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1269mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_en-us_topic_0000000000611468_p1269mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1873011722814"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1873011722814"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p1873011722814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p122515161139"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p122515161139"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_p122515161139"></a>Transparency of an element. The value ranges from <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1871715526385"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1871715526385"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b1871715526385"></a>0</strong> to <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b177181452103815"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b177181452103815"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b177181452103815"></a>1</strong>. The value <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b13718155210380"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b13718155210380"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b13718155210380"></a>1</strong> means opaque, and <strong id="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b6718152103818"><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b6718152103818"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001050791158_b6718152103818"></a>0</strong> means completely transparent.</p>
</td>
</tr>
</tbody>
</table>

## Event<a name="en-us_topic_0000001062321291_section1614413538447"></a>

<a name="en-us_topic_0000001062321291_table836435619510"></a>
<table><thead align="left"><tr id="en-us_topic_0000001062321291_row153658563517"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001062321291_en-us_topic_0000001051151132_en-us_topic_0000000000611460_p619mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001051151132_en-us_topic_0000000000611460_p619mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001051151132_en-us_topic_0000000000611460_p619mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001062321291_en-us_topic_0000001051151132_en-us_topic_0000000000611460_p621mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001051151132_en-us_topic_0000000000611460_p621mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001051151132_en-us_topic_0000000000611460_p621mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001062321291_en-us_topic_0000001051151132_en-us_topic_0000000000611460_p623mcpsimp"><a name="en-us_topic_0000001062321291_en-us_topic_0000001051151132_en-us_topic_0000000000611460_p623mcpsimp"></a><a name="en-us_topic_0000001062321291_en-us_topic_0000001051151132_en-us_topic_0000000000611460_p623mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001062321291_row0576209174715"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001062321291_p1652031354715"><a name="en-us_topic_0000001062321291_p1652031354715"></a><a name="en-us_topic_0000001062321291_p1652031354715"></a>sizechange</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001062321291_p2520913204711"><a name="en-us_topic_0000001062321291_p2520913204711"></a><a name="en-us_topic_0000001062321291_p2520913204711"></a>{ size: { height: heightLength, width: widthLength }, mode: modeStr }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001062321291_p8520101364714"><a name="en-us_topic_0000001062321291_p8520101364714"></a><a name="en-us_topic_0000001062321291_p8520101364714"></a>Triggered when the status of the slidable panel changes. Available <strong id="en-us_topic_0000001062321291_b122905111282"><a name="en-us_topic_0000001062321291_b122905111282"></a><a name="en-us_topic_0000001062321291_b122905111282"></a>mode</strong> values are as follows:</p>
<a name="en-us_topic_0000001062321291_ol5520181316476"></a><a name="en-us_topic_0000001062321291_ol5520181316476"></a><ol id="en-us_topic_0000001062321291_ol5520181316476"><li><p id="en-us_topic_0000001062321291_p4520141364713"><a name="en-us_topic_0000001062321291_p4520141364713"></a><a name="en-us_topic_0000001062321291_p4520141364713"></a><strong id="en-us_topic_0000001062321291_b45816387277"><a name="en-us_topic_0000001062321291_b45816387277"></a><a name="en-us_topic_0000001062321291_b45816387277"></a>mini</strong>: Displays a <strong id="en-us_topic_0000001062321291_b10542195774416"><a name="en-us_topic_0000001062321291_b10542195774416"></a><a name="en-us_topic_0000001062321291_b10542195774416"></a>minibar</strong> or <strong id="en-us_topic_0000001062321291_b134141855164411"><a name="en-us_topic_0000001062321291_b134141855164411"></a><a name="en-us_topic_0000001062321291_b134141855164411"></a>foldable</strong> panel in its minimum size.</p>
</li><li><p id="en-us_topic_0000001062321291_p6520191324711"><a name="en-us_topic_0000001062321291_p6520191324711"></a><a name="en-us_topic_0000001062321291_p6520191324711"></a><strong id="en-us_topic_0000001062321291_b2065484932810"><a name="en-us_topic_0000001062321291_b2065484932810"></a><a name="en-us_topic_0000001062321291_b2065484932810"></a>half</strong>: Displays a <strong id="en-us_topic_0000001062321291_b166951703457"><a name="en-us_topic_0000001062321291_b166951703457"></a><a name="en-us_topic_0000001062321291_b166951703457"></a>foldable</strong> panel in a medium-sized (halfscreen-like) area.</p>
</li><li><p id="en-us_topic_0000001062321291_p252018137477"><a name="en-us_topic_0000001062321291_p252018137477"></a><a name="en-us_topic_0000001062321291_p252018137477"></a><strong id="en-us_topic_0000001062321291_b1696104211503"><a name="en-us_topic_0000001062321291_b1696104211503"></a><a name="en-us_topic_0000001062321291_b1696104211503"></a>full</strong>: Displays a panel in a large (fullscreen-like) area.</p>
<div class="note" id="en-us_topic_0000001062321291_note1672712533287"><a name="en-us_topic_0000001062321291_note1672712533287"></a><a name="en-us_topic_0000001062321291_note1672712533287"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001062321291_p1672795314285"><a name="en-us_topic_0000001062321291_p1672795314285"></a><a name="en-us_topic_0000001062321291_p1672795314285"></a>The returned <strong id="en-us_topic_0000001062321291_b17504232153714"><a name="en-us_topic_0000001062321291_b17504232153714"></a><a name="en-us_topic_0000001062321291_b17504232153714"></a>height</strong> value indicates the content area height. However, when the <strong id="en-us_topic_0000001062321291_b6111851103715"><a name="en-us_topic_0000001062321291_b6111851103715"></a><a name="en-us_topic_0000001062321291_b6111851103715"></a>dragbar</strong> attribute is <strong id="en-us_topic_0000001062321291_b1019713539372"><a name="en-us_topic_0000001062321291_b1019713539372"></a><a name="en-us_topic_0000001062321291_b1019713539372"></a>true</strong>, the <strong id="en-us_topic_0000001062321291_b21622103812"><a name="en-us_topic_0000001062321291_b21622103812"></a><a name="en-us_topic_0000001062321291_b21622103812"></a>height</strong> value is the height of the drag bar plus that of the content area.</p>
</div></div>
</li></ol>
</td>
</tr>
</tbody>
</table>

## Method<a name="en-us_topic_0000001062321291_section165301745164719"></a>

<a name="en-us_topic_0000001062321291_table20753173210251"></a>
<table><thead align="left"><tr id="en-us_topic_0000001062321291_row575363214257"><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001062321291_p157531032112517"><a name="en-us_topic_0000001062321291_p157531032112517"></a><a name="en-us_topic_0000001062321291_p157531032112517"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001062321291_p77531632132518"><a name="en-us_topic_0000001062321291_p77531632132518"></a><a name="en-us_topic_0000001062321291_p77531632132518"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001062321291_p147531232132512"><a name="en-us_topic_0000001062321291_p147531232132512"></a><a name="en-us_topic_0000001062321291_p147531232132512"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001062321291_row15753113210251"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001062321291_p2314135812511"><a name="en-us_topic_0000001062321291_p2314135812511"></a><a name="en-us_topic_0000001062321291_p2314135812511"></a>show</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001062321291_p7314115819256"><a name="en-us_topic_0000001062321291_p7314115819256"></a><a name="en-us_topic_0000001062321291_p7314115819256"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001062321291_p0314958162512"><a name="en-us_topic_0000001062321291_p0314958162512"></a><a name="en-us_topic_0000001062321291_p0314958162512"></a>Pops the slidable panel up.</p>
</td>
</tr>
<tr id="en-us_topic_0000001062321291_row393410526251"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001062321291_p7314358182512"><a name="en-us_topic_0000001062321291_p7314358182512"></a><a name="en-us_topic_0000001062321291_p7314358182512"></a>close</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001062321291_p1231455814253"><a name="en-us_topic_0000001062321291_p1231455814253"></a><a name="en-us_topic_0000001062321291_p1231455814253"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001062321291_p10314105842512"><a name="en-us_topic_0000001062321291_p10314105842512"></a><a name="en-us_topic_0000001062321291_p10314105842512"></a>Closes the slidable panel that has been popped up.</p>
</td>
</tr>
</tbody>
</table>

## Example Code<a name="en-us_topic_0000001062321291_section36743614499"></a>

```
<!-- xxx.hml -->
<div class="doc-page">
  <div class="btn-div">
    <button type="capsule" value="Click here" onclick="showPanel"></button>
  </div>
  <panel id="simplepanel" type="foldable" mode="half" onsizechange="changeMode" miniheight="200px">
    <div class="panel-div">
      <div class="inner-txt">
        <text class="txt">Simple panel in {{modeFlag}} mode</text>
      </div>
      <div class="inner-btn">
        <button type="capsule" value="Close" onclick="closePanel"></button>
      </div>
    </div>
  </panel>
</div>
```

```
/* xxx.css */
.doc-page {
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
.btn-div {
  width: 100%;
  height: 200px;
  flex-direction: column;
  align-items: center;
  justify-content: center;
}
.txt {
  color: #000000;
  font-weight: bold;
  font-size: 39px;
}
.panel-div {
  width: 100%;
  flex-direction: column;
  align-items: center;
}
.inner-txt {
  width: 100%;
  height: 160px;
  flex-direction: column;
  align-items: center;
  justify-content: center;
}
.inner-btn {
  width: 100%;
  height: 120px;
  justify-content: center;
  align-items: center;
}
```

```
// xxx.js
export default {
  data: {
    modeFlag: "half"
  },
  showPanel(e) {
    this.$element('simplepanel').show()
  },
  closePanel(e) {
    this.$element('simplepanel').close()
  },
  changeMode(e) {
    this.modeFlag = e.mode
  }
}
```

![](figures/panel6.gif)

