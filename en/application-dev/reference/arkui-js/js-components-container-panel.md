# panel<a name="EN-US_TOPIC_0000001127284828"></a>

The  **<panel\>**  component is a slidable panel. It provides a lightweight content display window with flexible sizes. The  **<panel\>**  component pops up when it is displayed.

## Child Components<a name="section19368335134016"></a>

Yes

## Attributes<a name="section1100152194018"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="a45273e2103004ff3bdd3375013e96a2a"><a name="a45273e2103004ff3bdd3375013e96a2a"></a><a name="a45273e2103004ff3bdd3375013e96a2a"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.169999999999998%" id="mcps1.1.6.1.2"><p id="ad5b10d4a60e44bb4a8bbb3b4416d7b27"><a name="ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a><a name="ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.43%" id="mcps1.1.6.1.3"><p id="ab2ae3d9f60d6475ab95ba095851a9d07"><a name="ab2ae3d9f60d6475ab95ba095851a9d07"></a><a name="ab2ae3d9f60d6475ab95ba095851a9d07"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="af5c3b773ed0a42e589819a6c8d257ca1"><a name="af5c3b773ed0a42e589819a6c8d257ca1"></a><a name="af5c3b773ed0a42e589819a6c8d257ca1"></a>Triggered when</p>
</th>
</tr>
</thead>
<tbody><tr id="row741201424216"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1555482064215"><a name="p1555482064215"></a><a name="p1555482064215"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="p195541120124212"><a name="p195541120124212"></a><a name="p195541120124212"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="p05541220194219"><a name="p05541220194219"></a><a name="p05541220194219"></a>foldable</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p155541220104216"><a name="p155541220104216"></a><a name="p155541220104216"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p175541420104219"><a name="p175541420104219"></a><a name="p175541420104219"></a>Type of the slidable panel. This attribute cannot be dynamically changed. Available values are as follows:</p>
<a name="ul15554620204219"></a><a name="ul15554620204219"></a><ul id="ul15554620204219"><li><p id="p555417208423"><a name="p555417208423"></a><a name="p555417208423"></a><strong id="b75944818331"><a name="b75944818331"></a><a name="b75944818331"></a>minibar</strong>: A minibar panel displays content in the minibar area or a large (fullscreen-like) area.</p>
</li><li><p id="p15554920204216"><a name="p15554920204216"></a><a name="p15554920204216"></a><strong id="b1346141143510"><a name="b1346141143510"></a><a name="b1346141143510"></a>foldable</strong>: A foldable panel displays permanent content in a large (fullscreen-like), medium-sized (halfscreen-like), or small area.</p>
</li><li><p id="p35545206423"><a name="p35545206423"></a><a name="p35545206423"></a><strong id="b11403369397"><a name="b11403369397"></a><a name="b11403369397"></a>temporary</strong>: A temporary panel displays content in a large (fullscreen-like) or medium-sized (halfscreen-like) area.</p>
</li></ul>
</td>
</tr>
<tr id="row1815511615424"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1755419206420"><a name="p1755419206420"></a><a name="p1755419206420"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="p135544206422"><a name="p135544206422"></a><a name="p135544206422"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="p13554192010427"><a name="p13554192010427"></a><a name="p13554192010427"></a>full</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p155418205426"><a name="p155418205426"></a><a name="p155418205426"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p655415206425"><a name="p655415206425"></a><a name="p655415206425"></a>Initial status of the slidable panel. Available values are as follows:</p>
<a name="ol6554220154216"></a><a name="ol6554220154216"></a><ol id="ol6554220154216"><li><p id="p12554520154216"><a name="p12554520154216"></a><a name="p12554520154216"></a><strong id="b13227603353"><a name="b13227603353"></a><a name="b13227603353"></a>mini</strong>: Displays a <strong id="b18230114212422"><a name="b18230114212422"></a><a name="b18230114212422"></a>minibar</strong> or <strong id="b3615459421"><a name="b3615459421"></a><a name="b3615459421"></a>foldable</strong> panel in its minimum size. This attribute does not take effect for <strong id="b65822124212"><a name="b65822124212"></a><a name="b65822124212"></a>temporary</strong> panels.</p>
</li><li><p id="p1955422014218"><a name="p1955422014218"></a><a name="p1955422014218"></a><strong id="b7388181616411"><a name="b7388181616411"></a><a name="b7388181616411"></a>half</strong>: Displays a <strong id="b14130550104216"><a name="b14130550104216"></a><a name="b14130550104216"></a>foldable</strong> or <strong id="b1347545294213"><a name="b1347545294213"></a><a name="b1347545294213"></a>temporary</strong> panel in a medium-sized (halfscreen-like) area. This attribute does not take effect for <strong id="b17461163424318"><a name="b17461163424318"></a><a name="b17461163424318"></a>minibar</strong> panels.</p>
</li><li><p id="p15541020134214"><a name="p15541020134214"></a><a name="p15541020134214"></a><strong id="b56264913506"><a name="b56264913506"></a><a name="b56264913506"></a>full</strong>: Displays a panel in a large (fullscreen-like) area.</p>
</li></ol>
</td>
</tr>
<tr id="row1213173154220"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p855432019421"><a name="p855432019421"></a><a name="p855432019421"></a>dragbar</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="p155482015422"><a name="p155482015422"></a><a name="p155482015422"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="p1955552064210"><a name="p1955552064210"></a><a name="p1955552064210"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p755542024213"><a name="p755542024213"></a><a name="p755542024213"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p135551520114215"><a name="p135551520114215"></a><a name="p135551520114215"></a>Whether to enable a drag bar. The value <strong id="b899416435214"><a name="b899416435214"></a><a name="b899416435214"></a>true</strong> indicates that the drag bar will be displayed, and <strong id="b1834810239526"><a name="b1834810239526"></a><a name="b1834810239526"></a>false</strong> indicates the opposite.</p>
</td>
</tr>
<tr id="row827211578416"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p55550201428"><a name="p55550201428"></a><a name="p55550201428"></a>fullheight</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="p2055572012425"><a name="p2055572012425"></a><a name="p2055572012425"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="p145551220104214"><a name="p145551220104214"></a><a name="p145551220104214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1555182013429"><a name="p1555182013429"></a><a name="p1555182013429"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p16555102011423"><a name="p16555102011423"></a><a name="p16555102011423"></a>Panel height in the <strong id="b190616511539"><a name="b190616511539"></a><a name="b190616511539"></a>full</strong> mode. The default value is the screen height minus 8 px.</p>
</td>
</tr>
<tr id="row9344751124116"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p10555162017420"><a name="p10555162017420"></a><a name="p10555162017420"></a>halfheight</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="p1055572011422"><a name="p1055572011422"></a><a name="p1055572011422"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="p19555192018423"><a name="p19555192018423"></a><a name="p19555192018423"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p5555720134214"><a name="p5555720134214"></a><a name="p5555720134214"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p17555320194211"><a name="p17555320194211"></a><a name="p17555320194211"></a>Panel height in the <strong id="b360733265415"><a name="b360733265415"></a><a name="b360733265415"></a>half</strong> mode. The default value is half of the screen height.</p>
</td>
</tr>
<tr id="row278634674117"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p18556132014422"><a name="p18556132014422"></a><a name="p18556132014422"></a>miniheight</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="p5556920194212"><a name="p5556920194212"></a><a name="p5556920194212"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.43%" headers="mcps1.1.6.1.3 "><p id="p15561207425"><a name="p15561207425"></a><a name="p15561207425"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p55565208428"><a name="p55565208428"></a><a name="p55565208428"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p115561020164217"><a name="p115561020164217"></a><a name="p115561020164217"></a>Panel height in the <strong id="b634712315173"><a name="b634712315173"></a><a name="b634712315173"></a>mini</strong> mode. The default value is <strong id="b1170192112410"><a name="b1170192112410"></a><a name="b1170192112410"></a>48px</strong>.</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   Rendering attributes, including  **for**,  **if**, and  **show**, are not supported.
>-   The  **focusable**  and  **disabled**  attributes are not supported.

## Styles<a name="section1137118175437"></a>

Only the following style attributes are supported.

<a name="table1744514388541"></a>
<table><thead align="left"><tr id="row1244614388545"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="a4e80fb5a797c4328af30d59e2c570c71"><a name="a4e80fb5a797c4328af30d59e2c570c71"></a><a name="a4e80fb5a797c4328af30d59e2c570c71"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="a4238bd3a376645a3ad8498d3916ed6c8"><a name="a4238bd3a376645a3ad8498d3916ed6c8"></a><a name="a4238bd3a376645a3ad8498d3916ed6c8"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="a5ece9efc3a1d464a868f9557e4784a97"><a name="a5ece9efc3a1d464a868f9557e4784a97"></a><a name="a5ece9efc3a1d464a868f9557e4784a97"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p117421754619"><a name="p117421754619"></a><a name="p117421754619"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="a2454f35c1eef44b4bb681caaa3ce48fc"><a name="a2454f35c1eef44b4bb681caaa3ce48fc"></a><a name="a2454f35c1eef44b4bb681caaa3ce48fc"></a>Triggered when</p>
</th>
</tr>
</thead>
<tbody><tr id="row18446638145412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a541d1aa6d8ec43c28527ff9791c4cfc3"><a name="a541d1aa6d8ec43c28527ff9791c4cfc3"></a><a name="a541d1aa6d8ec43c28527ff9791c4cfc3"></a>padding</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a4d96fa6350a84c17ad53830df77db84e"><a name="a4d96fa6350a84c17ad53830df77db84e"></a><a name="a4d96fa6350a84c17ad53830df77db84e"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="aaa8cc18f5e03468cac00fb13b44abe01"><a name="aaa8cc18f5e03468cac00fb13b44abe01"></a><a name="aaa8cc18f5e03468cac00fb13b44abe01"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a268bdb972a1147b2b1fc6b930ca565e7"><a name="a268bdb972a1147b2b1fc6b930ca565e7"></a><a name="a268bdb972a1147b2b1fc6b930ca565e7"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><div class="p" id="a9d4f39d126ce4c4cb7652dc07238acf0"><a name="a9d4f39d126ce4c4cb7652dc07238acf0"></a><a name="a9d4f39d126ce4c4cb7652dc07238acf0"></a>The attribute can have one to four values:<a name="udb68dd5e787d4dc4ba26465e8450efe7"></a><a name="udb68dd5e787d4dc4ba26465e8450efe7"></a><ul id="udb68dd5e787d4dc4ba26465e8450efe7"><li><p id="a95f9b1440265405fa0007c00d337dab3"><a name="a95f9b1440265405fa0007c00d337dab3"></a><a name="a95f9b1440265405fa0007c00d337dab3"></a>If you set only one value, it specifies the padding for four sides.</p>
</li><li><p id="a1c1fdd035aee4b3a8a61fc1a42c967e4"><a name="a1c1fdd035aee4b3a8a61fc1a42c967e4"></a><a name="a1c1fdd035aee4b3a8a61fc1a42c967e4"></a>If you set two values, the first value specifies the top and bottom padding, and the second value specifies the left and right padding.</p>
</li><li><p id="a643af1b111eb4220a3703a37180c0735"><a name="a643af1b111eb4220a3703a37180c0735"></a><a name="a643af1b111eb4220a3703a37180c0735"></a>If you set three values, the first value specifies the top padding, the second value specifies the left and right padding, and the third value specifies the bottom padding.</p>
</li><li><p id="ab8cfda39634d4ecf86eb772c1b654f7e"><a name="ab8cfda39634d4ecf86eb772c1b654f7e"></a><a name="ab8cfda39634d4ecf86eb772c1b654f7e"></a>If you set four values, they respectively specify the padding for top, right, bottom, and left sides (in clockwise order).</p>
</li></ul>
</div>
</td>
</tr>
<tr id="row24464380544"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a2b2d344bb3214009a6866bd4766407d3"><a name="a2b2d344bb3214009a6866bd4766407d3"></a><a name="a2b2d344bb3214009a6866bd4766407d3"></a>padding-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="aa67316592ce34e00bcbfaa90f10d08cf"><a name="aa67316592ce34e00bcbfaa90f10d08cf"></a><a name="aa67316592ce34e00bcbfaa90f10d08cf"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a426b27187104497493502b4c45545091"><a name="a426b27187104497493502b4c45545091"></a><a name="a426b27187104497493502b4c45545091"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a2018ad09e4c94cdf84d402e11c1410d5"><a name="a2018ad09e4c94cdf84d402e11c1410d5"></a><a name="a2018ad09e4c94cdf84d402e11c1410d5"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="ae34337bc334e4e15843bf03563f8572a"><a name="ae34337bc334e4e15843bf03563f8572a"></a><a name="ae34337bc334e4e15843bf03563f8572a"></a>Left, top, right, and bottom padding.</p>
</td>
</tr>
<tr id="row1144723845412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="aaff96272d36945239259ab5e76ec433e"><a name="aaff96272d36945239259ab5e76ec433e"></a><a name="aaff96272d36945239259ab5e76ec433e"></a>padding-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a2dedafe206c84605a2686c505cbd2096"><a name="a2dedafe206c84605a2686c505cbd2096"></a><a name="a2dedafe206c84605a2686c505cbd2096"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a27db5e428204402aa54deaa2c2630eac"><a name="a27db5e428204402aa54deaa2c2630eac"></a><a name="a27db5e428204402aa54deaa2c2630eac"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a2952814e86f14ec6a133e606c78683d8"><a name="a2952814e86f14ec6a133e606c78683d8"></a><a name="a2952814e86f14ec6a133e606c78683d8"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="aaf71a7aed79445c18bb63ae5f5a00314"><a name="aaf71a7aed79445c18bb63ae5f5a00314"></a><a name="aaf71a7aed79445c18bb63ae5f5a00314"></a>Start and end padding.</p>
</td>
</tr>
<tr id="row11447438175410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="ae3cc1b4f8cc94962aeaf8f3b52b4e9f0"><a name="ae3cc1b4f8cc94962aeaf8f3b52b4e9f0"></a><a name="ae3cc1b4f8cc94962aeaf8f3b52b4e9f0"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a81d0391edfc04d1395d61d8053fa93d6"><a name="a81d0391edfc04d1395d61d8053fa93d6"></a><a name="a81d0391edfc04d1395d61d8053fa93d6"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a9c42aa4dad8c4f58a9f85a3e2b4d1e15"><a name="a9c42aa4dad8c4f58a9f85a3e2b4d1e15"></a><a name="a9c42aa4dad8c4f58a9f85a3e2b4d1e15"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a9be9fbee32844dea910afca9a2221bac"><a name="a9be9fbee32844dea910afca9a2221bac"></a><a name="a9be9fbee32844dea910afca9a2221bac"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="afe56536fd53c409db2033b4be7135555"><a name="afe56536fd53c409db2033b4be7135555"></a><a name="afe56536fd53c409db2033b4be7135555"></a>Shorthand attribute to set margins for all sides in a declaration. The attribute can have one to four values:</p>
<a name="u1fe7f0fee6294e3aabd5a16f16f62eaa"></a><a name="u1fe7f0fee6294e3aabd5a16f16f62eaa"></a><ul id="u1fe7f0fee6294e3aabd5a16f16f62eaa"><li><p id="a51f7d66473934ec6918040a4da7ed533"><a name="a51f7d66473934ec6918040a4da7ed533"></a><a name="a51f7d66473934ec6918040a4da7ed533"></a>If you set only one value, it specifies the margin for all the four sides.</p>
</li><li><p id="a446e0dc7bfbc4aa580ede47e4af3901c"><a name="a446e0dc7bfbc4aa580ede47e4af3901c"></a><a name="a446e0dc7bfbc4aa580ede47e4af3901c"></a>If you set two values, the first value is for the top and bottom sides and the second value for the left and right sides.</p>
</li><li><p id="a2ce71640e6964e86acb7f6abd6e6aec8"><a name="a2ce71640e6964e86acb7f6abd6e6aec8"></a><a name="a2ce71640e6964e86acb7f6abd6e6aec8"></a>If you set three values, the first value is for the top, the second value for the left and right, and the third value for the bottom.</p>
</li><li><p id="a86622e9fbdeb409cb5afcc0b2c7fe651"><a name="a86622e9fbdeb409cb5afcc0b2c7fe651"></a><a name="a86622e9fbdeb409cb5afcc0b2c7fe651"></a>If you set four values, they are margins for top, right, bottom, and left sides, respectively.</p>
</li></ul>
</td>
</tr>
<tr id="row144473383544"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="af348632f1a9045e2a46377d98e6a823f"><a name="af348632f1a9045e2a46377d98e6a823f"></a><a name="af348632f1a9045e2a46377d98e6a823f"></a>margin-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="aa2920472d95e4c59b3caa0c64dbf028b"><a name="aa2920472d95e4c59b3caa0c64dbf028b"></a><a name="aa2920472d95e4c59b3caa0c64dbf028b"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a1086205d47a84dbcb8b537076d758d6f"><a name="a1086205d47a84dbcb8b537076d758d6f"></a><a name="a1086205d47a84dbcb8b537076d758d6f"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a644285f82f7a4953b96b710055360358"><a name="a644285f82f7a4953b96b710055360358"></a><a name="a644285f82f7a4953b96b710055360358"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a14777b85d0f7480b9e707f2986db519f"><a name="a14777b85d0f7480b9e707f2986db519f"></a><a name="a14777b85d0f7480b9e707f2986db519f"></a>Left, top, right, and bottom margins.</p>
</td>
</tr>
<tr id="row944743811541"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a2f323eb272624b5191876de68ebfd133"><a name="a2f323eb272624b5191876de68ebfd133"></a><a name="a2f323eb272624b5191876de68ebfd133"></a>margin-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001050791158_p157617124374"><a name="en-us_topic_0000001050791158_p157617124374"></a><a name="en-us_topic_0000001050791158_p157617124374"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a3874f54c277642e198919edbafa4216b"><a name="a3874f54c277642e198919edbafa4216b"></a><a name="a3874f54c277642e198919edbafa4216b"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p117511744618"><a name="p117511744618"></a><a name="p117511744618"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="ae427df4a00bf46379ce337974a1d17df"><a name="ae427df4a00bf46379ce337974a1d17df"></a><a name="ae427df4a00bf46379ce337974a1d17df"></a>Start and end margins.</p>
</td>
</tr>
<tr id="row16447238155411"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a5d03dcff88b94f7b894d65fdf08d1434"><a name="a5d03dcff88b94f7b894d65fdf08d1434"></a><a name="a5d03dcff88b94f7b894d65fdf08d1434"></a>border</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a5ebca7bf3c34482eae9b3148bb3394de"><a name="a5ebca7bf3c34482eae9b3148bb3394de"></a><a name="a5ebca7bf3c34482eae9b3148bb3394de"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a4bff92bcfc064eaf8ae31845ab40f95d"><a name="a4bff92bcfc064eaf8ae31845ab40f95d"></a><a name="a4bff92bcfc064eaf8ae31845ab40f95d"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p11175131715467"><a name="p11175131715467"></a><a name="p11175131715467"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a18290265c858402dad42d13f5df9556f"><a name="a18290265c858402dad42d13f5df9556f"></a><a name="a18290265c858402dad42d13f5df9556f"></a>Shorthand attribute to set all borders. Set <strong id="b083513429473"><a name="b083513429473"></a><a name="b083513429473"></a>border-width</strong>, <strong id="b984410426477"><a name="b984410426477"></a><a name="b984410426477"></a>border-style</strong>, and <strong id="b13845154204714"><a name="b13845154204714"></a><a name="b13845154204714"></a>border-color</strong> in sequence. Default values are used for attributes that are not set.</p>
</td>
</tr>
<tr id="row4447138115414"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a3247ae43aa8443f184f52e45ccd0ca07"><a name="a3247ae43aa8443f184f52e45ccd0ca07"></a><a name="a3247ae43aa8443f184f52e45ccd0ca07"></a>border-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a3da2ed807521431e987b22e624574dc0"><a name="a3da2ed807521431e987b22e624574dc0"></a><a name="a3da2ed807521431e987b22e624574dc0"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a0187620d3c154706944fc4c01734d48f"><a name="a0187620d3c154706944fc4c01734d48f"></a><a name="a0187620d3c154706944fc4c01734d48f"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p617531717464"><a name="p617531717464"></a><a name="p617531717464"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a29372dc23f5f4307929d789f9b76472e"><a name="a29372dc23f5f4307929d789f9b76472e"></a><a name="a29372dc23f5f4307929d789f9b76472e"></a>Shorthand attribute to set the style for all borders. Available values are as follows:</p>
<a name="u5617b1dfdf2048739b8699b11a69d8db"></a><a name="u5617b1dfdf2048739b8699b11a69d8db"></a><ul id="u5617b1dfdf2048739b8699b11a69d8db"><li><strong id="b152932468478"><a name="b152932468478"></a><a name="b152932468478"></a>dotted</strong>: dotted border. The radius of a dot is half of <strong id="b1294184614715"><a name="b1294184614715"></a><a name="b1294184614715"></a>border-width</strong>.</li><li><strong id="b063849104711"><a name="b063849104711"></a><a name="b063849104711"></a>dashed</strong>: dashed border</li></ul>
<a name="u9d6301312eda4022a25e3774fc603823"></a><a name="u9d6301312eda4022a25e3774fc603823"></a><ul id="u9d6301312eda4022a25e3774fc603823"><li><strong id="b770165294712"><a name="b770165294712"></a><a name="b770165294712"></a>solid</strong>: solid border</li></ul>
</td>
</tr>
<tr id="row1656512239262"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a3264ee35efcd40aeb8ed5931bf62f9e3"><a name="a3264ee35efcd40aeb8ed5931bf62f9e3"></a><a name="a3264ee35efcd40aeb8ed5931bf62f9e3"></a>border-[left|top|right|bottom]-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="af7370e9f2bd3451bba0b2b0a865b8f43"><a name="af7370e9f2bd3451bba0b2b0a865b8f43"></a><a name="af7370e9f2bd3451bba0b2b0a865b8f43"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a682f8be227ba4adfa13eac52c1c513b9"><a name="a682f8be227ba4adfa13eac52c1c513b9"></a><a name="a682f8be227ba4adfa13eac52c1c513b9"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a2edc177990bb4674bea5fc0c2cadf1df"><a name="a2edc177990bb4674bea5fc0c2cadf1df"></a><a name="a2edc177990bb4674bea5fc0c2cadf1df"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="abfe3dfb0662b4a6c850a8d5d285dff6d"><a name="abfe3dfb0662b4a6c850a8d5d285dff6d"></a><a name="abfe3dfb0662b4a6c850a8d5d285dff6d"></a>Styles of the left, top, right, and bottom borders. The available values are <strong id="b5137105454712"><a name="b5137105454712"></a><a name="b5137105454712"></a>dotted</strong>, <strong id="b111381654144718"><a name="b111381654144718"></a><a name="b111381654144718"></a>dashed</strong>, and <strong id="b101391554184712"><a name="b101391554184712"></a><a name="b101391554184712"></a>solid</strong>.</p>
</td>
</tr>
<tr id="row19448113811542"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="aca24a970df9c42d3bdd871a44ad17f2f"><a name="aca24a970df9c42d3bdd871a44ad17f2f"></a><a name="aca24a970df9c42d3bdd871a44ad17f2f"></a>border-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="af20792fd5492451096250fc7db910669"><a name="af20792fd5492451096250fc7db910669"></a><a name="af20792fd5492451096250fc7db910669"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="aa13a80ae5fad42289bae4fb76dc9efeb"><a name="aa13a80ae5fad42289bae4fb76dc9efeb"></a><a name="aa13a80ae5fad42289bae4fb76dc9efeb"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a45d917a58f9e45f79c931a9ede2f7521"><a name="a45d917a58f9e45f79c931a9ede2f7521"></a><a name="a45d917a58f9e45f79c931a9ede2f7521"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a5ec1cb3c8733406b91ad459e012f91f4"><a name="a5ec1cb3c8733406b91ad459e012f91f4"></a><a name="a5ec1cb3c8733406b91ad459e012f91f4"></a>Shorthand attribute to set the borders for every side respectively. You set <strong id="b11961957114716"><a name="b11961957114716"></a><a name="b11961957114716"></a>border-width</strong>, <strong id="b7103145715476"><a name="b7103145715476"></a><a name="b7103145715476"></a>border-style</strong>, and <strong id="b16104175711473"><a name="b16104175711473"></a><a name="b16104175711473"></a>border-color</strong> in sequence. Default values are used for attributes that are not set.</p>
</td>
</tr>
<tr id="row124481638165417"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a5e2a85c8033f42d7b69cf67e5468e805"><a name="a5e2a85c8033f42d7b69cf67e5468e805"></a><a name="a5e2a85c8033f42d7b69cf67e5468e805"></a>border-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a68368a57007c44faa8d926acac48f0df"><a name="a68368a57007c44faa8d926acac48f0df"></a><a name="a68368a57007c44faa8d926acac48f0df"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a21a68501e60245b9beba967ead6cb1f9"><a name="a21a68501e60245b9beba967ead6cb1f9"></a><a name="a21a68501e60245b9beba967ead6cb1f9"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p16175131724618"><a name="p16175131724618"></a><a name="p16175131724618"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="aad1af0ece034401a8c56fb287c16320c"><a name="aad1af0ece034401a8c56fb287c16320c"></a><a name="aad1af0ece034401a8c56fb287c16320c"></a>Shorthand attribute to set the width of all borders<span id="ph1439331144812"><a name="ph1439331144812"></a><a name="ph1439331144812"></a>, or separately set the width of each border</span>.</p>
</td>
</tr>
<tr id="row54481038165410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="af71ca4e515d0470ea0867f157c125ffb"><a name="af71ca4e515d0470ea0867f157c125ffb"></a><a name="af71ca4e515d0470ea0867f157c125ffb"></a>border-[left|top|right|bottom]-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a5d713a4524c94d88bb768770c4b9871b"><a name="a5d713a4524c94d88bb768770c4b9871b"></a><a name="a5d713a4524c94d88bb768770c4b9871b"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a598e0a5a87cc4e1aad99441d0899c064"><a name="a598e0a5a87cc4e1aad99441d0899c064"></a><a name="a598e0a5a87cc4e1aad99441d0899c064"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p11175151717466"><a name="p11175151717466"></a><a name="p11175151717466"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a0e87cf1edd0f474cb33591ce68b19296"><a name="a0e87cf1edd0f474cb33591ce68b19296"></a><a name="a0e87cf1edd0f474cb33591ce68b19296"></a>Attribute to set widths of left, top, right, and bottom borders.</p>
</td>
</tr>
<tr id="row1744817385547"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a971adbece55a4864ad6a089be7eb12d2"><a name="a971adbece55a4864ad6a089be7eb12d2"></a><a name="a971adbece55a4864ad6a089be7eb12d2"></a>border-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a2676a7ea563844569103471ed3d2bcb6"><a name="a2676a7ea563844569103471ed3d2bcb6"></a><a name="a2676a7ea563844569103471ed3d2bcb6"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a6a41565e7f71412b91e94f6ba95b8a84"><a name="a6a41565e7f71412b91e94f6ba95b8a84"></a><a name="a6a41565e7f71412b91e94f6ba95b8a84"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p1017518177465"><a name="p1017518177465"></a><a name="p1017518177465"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a5c2063b884d84196b3a328d8029c5bbd"><a name="a5c2063b884d84196b3a328d8029c5bbd"></a><a name="a5c2063b884d84196b3a328d8029c5bbd"></a>Shorthand attribute to set the color of all borders<span id="ph20728201214910"><a name="ph20728201214910"></a><a name="ph20728201214910"></a>, or separately set the color of each border</span>.</p>
</td>
</tr>
<tr id="row844813835410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a7385c35d96a84cb9945ba0afe8f39f27"><a name="a7385c35d96a84cb9945ba0afe8f39f27"></a><a name="a7385c35d96a84cb9945ba0afe8f39f27"></a>border-[left|top|right|bottom]-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="adc421d4d9fe242968ccae293e5a1d8ca"><a name="adc421d4d9fe242968ccae293e5a1d8ca"></a><a name="adc421d4d9fe242968ccae293e5a1d8ca"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a997049720b89455581e5ae2ea47c5f76"><a name="a997049720b89455581e5ae2ea47c5f76"></a><a name="a997049720b89455581e5ae2ea47c5f76"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p11175417184611"><a name="p11175417184611"></a><a name="p11175417184611"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a3a75202614f54b8d86865e6bdd23220e"><a name="a3a75202614f54b8d86865e6bdd23220e"></a><a name="a3a75202614f54b8d86865e6bdd23220e"></a>Attribute to set colors of left, top, right, and bottom borders.</p>
</td>
</tr>
<tr id="row944813389540"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="aeb41e1dcf38048a7a870b7fbc262d9b3"><a name="aeb41e1dcf38048a7a870b7fbc262d9b3"></a><a name="aeb41e1dcf38048a7a870b7fbc262d9b3"></a>border-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a1b2aa369911d430892c9c2ccc8c92eee"><a name="a1b2aa369911d430892c9c2ccc8c92eee"></a><a name="a1b2aa369911d430892c9c2ccc8c92eee"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="afebc1d7def134a30b454052ffd82fcd5"><a name="afebc1d7def134a30b454052ffd82fcd5"></a><a name="afebc1d7def134a30b454052ffd82fcd5"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a7477a88e90164a46ba6b4dd7b6b39909"><a name="a7477a88e90164a46ba6b4dd7b6b39909"></a><a name="a7477a88e90164a46ba6b4dd7b6b39909"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a3df8b3f3ec00490a9687f38cb6369c75"><a name="a3df8b3f3ec00490a9687f38cb6369c75"></a><a name="a3df8b3f3ec00490a9687f38cb6369c75"></a>Attribute to set the radius of round-corner borders. <span id="ph8921172719494"><a name="ph8921172719494"></a><a name="ph8921172719494"></a>This attribute cannot be used to set the width or color of a specific border. To set the width or color, you need to set <strong id="b1891342784915"><a name="b1891342784915"></a><a name="b1891342784915"></a>border-width</strong> or <strong id="b159203275495"><a name="b159203275495"></a><a name="b159203275495"></a>border-color</strong> for all the borders at the same time.</span></p>
</td>
</tr>
<tr id="row104494382546"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a7f4cc47cb21f4241bc50c09595abe42b"><a name="a7f4cc47cb21f4241bc50c09595abe42b"></a><a name="a7f4cc47cb21f4241bc50c09595abe42b"></a>border-[top|bottom]-[left|right]-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="af4577f8f400e44dd92306d77f0b600c7"><a name="af4577f8f400e44dd92306d77f0b600c7"></a><a name="af4577f8f400e44dd92306d77f0b600c7"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="adba608505d644afcb117ae14679054cf"><a name="adba608505d644afcb117ae14679054cf"></a><a name="adba608505d644afcb117ae14679054cf"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="af792dccde58c4e699a2a0b924d6111de"><a name="af792dccde58c4e699a2a0b924d6111de"></a><a name="af792dccde58c4e699a2a0b924d6111de"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a41f1597c4e454492aaea4818c234d429"><a name="a41f1597c4e454492aaea4818c234d429"></a><a name="a41f1597c4e454492aaea4818c234d429"></a>Attribute to receptively set the radii of upper-left, upper-right, lower-right, and lower-left rounded corners</p>
</td>
</tr>
<tr id="row1344912384548"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a473248d0f1ad4a6b87934aab462b09ce"><a name="a473248d0f1ad4a6b87934aab462b09ce"></a><a name="a473248d0f1ad4a6b87934aab462b09ce"></a>background</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a7c54e775a6bf4bbea277ff8927cc4c13"><a name="a7c54e775a6bf4bbea277ff8927cc4c13"></a><a name="a7c54e775a6bf4bbea277ff8927cc4c13"></a>&lt;linear-gradient&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a5bbca83860ff4086bba1bf5b8698e28c"><a name="a5bbca83860ff4086bba1bf5b8698e28c"></a><a name="a5bbca83860ff4086bba1bf5b8698e28c"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a047e39fe359445759a1ce07ca6d46a38"><a name="a047e39fe359445759a1ce07ca6d46a38"></a><a name="a047e39fe359445759a1ce07ca6d46a38"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a2681658e98234c0bb3dfb1a8fc1ae346"><a name="a2681658e98234c0bb3dfb1a8fc1ae346"></a><a name="a2681658e98234c0bb3dfb1a8fc1ae346"></a>This attribute supports <a href="js-components-common-gradient.md">Gradient Styles</a> only but is not compatible with <strong id="b199011833144912"><a name="b199011833144912"></a><a name="b199011833144912"></a>background-color</strong> or <strong id="b1690283344915"><a name="b1690283344915"></a><a name="b1690283344915"></a>background-image</strong>.</p>
</td>
</tr>
<tr id="row15449838185416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="af5c7b4fc3d8949b5aff81c5b49783259"><a name="af5c7b4fc3d8949b5aff81c5b49783259"></a><a name="af5c7b4fc3d8949b5aff81c5b49783259"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a3f45d99020c04479943ad07f262a591c"><a name="a3f45d99020c04479943ad07f262a591c"></a><a name="a3f45d99020c04479943ad07f262a591c"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="add693215147d46e59c859940cc4520e8"><a name="add693215147d46e59c859940cc4520e8"></a><a name="add693215147d46e59c859940cc4520e8"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a5bd974fe26aa45409ff08d6d652b03e6"><a name="a5bd974fe26aa45409ff08d6d652b03e6"></a><a name="a5bd974fe26aa45409ff08d6d652b03e6"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="acd48c077d9964749ae766636b8ada95c"><a name="acd48c077d9964749ae766636b8ada95c"></a><a name="acd48c077d9964749ae766636b8ada95c"></a>Background color.</p>
</td>
</tr>
<tr id="row54491338115412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a9ebf9bd289374413a2834bab0e3b46d4"><a name="a9ebf9bd289374413a2834bab0e3b46d4"></a><a name="a9ebf9bd289374413a2834bab0e3b46d4"></a>background-image</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a46c151a9e45b4ffcb4c45dfcb93214bd"><a name="a46c151a9e45b4ffcb4c45dfcb93214bd"></a><a name="a46c151a9e45b4ffcb4c45dfcb93214bd"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a8be7284eb5884350ba591183a67d4060"><a name="a8be7284eb5884350ba591183a67d4060"></a><a name="a8be7284eb5884350ba591183a67d4060"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a9ca4df413139442e8a520bc7c04dae02"><a name="a9ca4df413139442e8a520bc7c04dae02"></a><a name="a9ca4df413139442e8a520bc7c04dae02"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="aa236de4e56e349ff8c753d294e98abab"><a name="aa236de4e56e349ff8c753d294e98abab"></a><a name="aa236de4e56e349ff8c753d294e98abab"></a>Background image. Currently, this attribute is not compatible with <strong id="b168581843184914"><a name="b168581843184914"></a><a name="b168581843184914"></a>background-color</strong> or <strong id="b4866144318494"><a name="b4866144318494"></a><a name="b4866144318494"></a>background</strong>. Local  image resources are supported.</p>
</td>
</tr>
<tr id="row6449238185416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a5def9eea1a2b42e9b040f0f898a2fcdf"><a name="a5def9eea1a2b42e9b040f0f898a2fcdf"></a><a name="a5def9eea1a2b42e9b040f0f898a2fcdf"></a>background-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="uc9d67b59ab8c4f5d8f766deb0f8f657b"></a><a name="uc9d67b59ab8c4f5d8f766deb0f8f657b"></a><ul id="uc9d67b59ab8c4f5d8f766deb0f8f657b"><li>string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a2d537661fce74b13acbcc7a95ea56f08"><a name="a2d537661fce74b13acbcc7a95ea56f08"></a><a name="a2d537661fce74b13acbcc7a95ea56f08"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="aa5ecaa85d6924436bb54a637b9d46c8c"><a name="aa5ecaa85d6924436bb54a637b9d46c8c"></a><a name="aa5ecaa85d6924436bb54a637b9d46c8c"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a0709b83d5c8e4b75b1f0bb42d913ac02"><a name="a0709b83d5c8e4b75b1f0bb42d913ac02"></a><a name="a0709b83d5c8e4b75b1f0bb42d913ac02"></a>Background image size.</p>
<a name="ub2423a2f8d96432f8c58c629288432c5"></a><a name="ub2423a2f8d96432f8c58c629288432c5"></a><ul id="ub2423a2f8d96432f8c58c629288432c5"><li>The <strong id="b13127185124910"><a name="b13127185124910"></a><a name="b13127185124910"></a>string</strong> values are as follows:<a name="uee8f5c89381a4ce682a5d557f8e558ee"></a><a name="uee8f5c89381a4ce682a5d557f8e558ee"></a><ul id="uee8f5c89381a4ce682a5d557f8e558ee"><li><strong id="b1474287165014"><a name="b1474287165014"></a><a name="b1474287165014"></a>contain</strong>: Expands the image to the maximum size so that the height and width of the image are applicable to the content area.</li><li><strong id="b311264385312"><a name="b311264385312"></a><a name="b311264385312"></a>cover</strong>: Extends the background image to a large enough size so that the background image completely covers the background area. Some parts of the image may not be displayed in the background area.</li><li><strong id="b163611704548"><a name="b163611704548"></a><a name="b163611704548"></a>auto</strong>: The original image width-height ratio is retained.</li></ul>
</li><li>The two <strong id="b64592211545"><a name="b64592211545"></a><a name="b64592211545"></a>&lt;length&gt;</strong> values are as follows:<p id="a5b969a49f8074aae96a12e4232e47c5d"><a name="a5b969a49f8074aae96a12e4232e47c5d"></a><a name="a5b969a49f8074aae96a12e4232e47c5d"></a>Width and height of the background image. The first value indicates the width, and the second value indicates the height. If you only set one value, the other value is set to <strong id="b3412192712546"><a name="b3412192712546"></a><a name="b3412192712546"></a>auto</strong> by default.</p>
</li><li>The two <strong id="b344718292549"><a name="b344718292549"></a><a name="b344718292549"></a>&lt;percentage&gt;</strong> values are as follows:<p id="a19ef0a7986ce47f2b7fe614975e23cd9"><a name="a19ef0a7986ce47f2b7fe614975e23cd9"></a><a name="a19ef0a7986ce47f2b7fe614975e23cd9"></a>Width and height of the background image in percentage of the parent element. The first value indicates the width, and the second value indicates the height. If you only set one value, the other value is set to <strong id="b11170184116543"><a name="b11170184116543"></a><a name="b11170184116543"></a>auto</strong> by default.</p>
</li></ul>
</td>
</tr>
<tr id="row94491238155415"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a8e820e26428c4e008a691a8fc8c23294"><a name="a8e820e26428c4e008a691a8fc8c23294"></a><a name="a8e820e26428c4e008a691a8fc8c23294"></a>background-repeat</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="ab9ca7eb1f0fc48a9a3fc08b88fe11338"><a name="ab9ca7eb1f0fc48a9a3fc08b88fe11338"></a><a name="ab9ca7eb1f0fc48a9a3fc08b88fe11338"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="abbb032e6786d43568f7eea7b29611821"><a name="abbb032e6786d43568f7eea7b29611821"></a><a name="abbb032e6786d43568f7eea7b29611821"></a>repeat</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a53d72f211cdc44b181973e27c6f03845"><a name="a53d72f211cdc44b181973e27c6f03845"></a><a name="a53d72f211cdc44b181973e27c6f03845"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a64efc26d6e2c48a3a4032c71b8511085"><a name="a64efc26d6e2c48a3a4032c71b8511085"></a><a name="a64efc26d6e2c48a3a4032c71b8511085"></a>Repeating attribute of a background image. By default, a background image is repeated both horizontally and vertically.</p>
<a name="uee59e640d2304d56a0a5b396795a8cc5"></a><a name="uee59e640d2304d56a0a5b396795a8cc5"></a><ul id="uee59e640d2304d56a0a5b396795a8cc5"><li><strong id="b1953611845513"><a name="b1953611845513"></a><a name="b1953611845513"></a>repeat</strong>: Repeatedly draws images along the x-axis and y-axis at the same time.</li><li><strong id="b4728182018554"><a name="b4728182018554"></a><a name="b4728182018554"></a>repeat-x</strong>: Repeatedly draws images along the x-axis.</li><li><strong id="b38969231556"><a name="b38969231556"></a><a name="b38969231556"></a>repeat-y</strong>: Repeatedly draws images along the y-axis.</li><li><strong id="b106442517553"><a name="b106442517553"></a><a name="b106442517553"></a>no-repeat</strong>: The image is not drawn repeatedly.</li></ul>
</td>
</tr>
<tr id="row94491738105419"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a60e011e34e6c4b04a1c86ac873087eed"><a name="a60e011e34e6c4b04a1c86ac873087eed"></a><a name="a60e011e34e6c4b04a1c86ac873087eed"></a>background-position</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="u2fe0f6beda39428780ca525d6dca1b30"></a><a name="u2fe0f6beda39428780ca525d6dca1b30"></a><ul id="u2fe0f6beda39428780ca525d6dca1b30"><li>string string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="ad96af7b5874e476db4b4cf968156a633"><a name="ad96af7b5874e476db4b4cf968156a633"></a><a name="ad96af7b5874e476db4b4cf968156a633"></a>0px 0px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a735a713fbf2c4d2c9be71a5eb26e5371"><a name="a735a713fbf2c4d2c9be71a5eb26e5371"></a><a name="a735a713fbf2c4d2c9be71a5eb26e5371"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><a name="ub1e24d41a33d4560a6637f7a16ee5140"></a><a name="ub1e24d41a33d4560a6637f7a16ee5140"></a><ul id="ub1e24d41a33d4560a6637f7a16ee5140"><li>Using keywords: If only one keyword is specified, the other value is <strong id="b1375628105514"><a name="b1375628105514"></a><a name="b1375628105514"></a>center</strong> by default. The two values define the horizontal position and vertical position, respectively.<a name="uac6e07c1eb0244d79eeed180658cb6c6"></a><a name="uac6e07c1eb0244d79eeed180658cb6c6"></a><ul id="uac6e07c1eb0244d79eeed180658cb6c6"><li><strong id="b1895315557"><a name="b1895315557"></a><a name="b1895315557"></a>left</strong>: leftmost in the horizontal direction</li><li><strong id="b832423245517"><a name="b832423245517"></a><a name="b832423245517"></a>right</strong>: rightmost in the horizontal direction</li><li><strong id="b1252973310555"><a name="b1252973310555"></a><a name="b1252973310555"></a>top</strong>: top in the vertical direction</li><li><strong id="b157931134185511"><a name="b157931134185511"></a><a name="b157931134185511"></a>bottom</strong>: bottom in the vertical direction</li><li><strong id="b792773565515"><a name="b792773565515"></a><a name="b792773565515"></a>center</strong>: center position</li></ul>
</li></ul>
<a name="ua495746d9777430c973a5ec607309ac4"></a><a name="ua495746d9777430c973a5ec607309ac4"></a><ul id="ua495746d9777430c973a5ec607309ac4"><li>Using <strong id="b15235143718553"><a name="b15235143718553"></a><a name="b15235143718553"></a>&lt;length&gt;</strong>: The first value indicates the horizontal position, and the second value indicates the vertical position. <strong id="b10672040165512"><a name="b10672040165512"></a><a name="b10672040165512"></a>0 0</strong> indicates the upper left corner. The unit is pixel. If only one value is specified, the other one is <strong id="b182882471554"><a name="b182882471554"></a><a name="b182882471554"></a>50%</strong>.</li><li>Using <strong id="b4812144875514"><a name="b4812144875514"></a><a name="b4812144875514"></a>&lt;percentage&gt;</strong>: The first value indicates the horizontal position, and the second value indicates the vertical position. <strong id="b20541964578"><a name="b20541964578"></a><a name="b20541964578"></a>0% 0%</strong> indicates the upper left corner. <strong id="b561913815576"><a name="b561913815576"></a><a name="b561913815576"></a>100% 100%</strong> indicates the lower right corner. If only one value is specified, the other one is <strong id="b88734955715"><a name="b88734955715"></a><a name="b88734955715"></a>50%</strong>.</li><li>Using both <strong id="b6916141065718"><a name="b6916141065718"></a><a name="b6916141065718"></a>&lt;percentage&gt;</strong> and <strong id="b5917121019577"><a name="b5917121019577"></a><a name="b5917121019577"></a>&lt;length&gt;</strong>.</li></ul>
</td>
</tr>
<tr id="row20450143885416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a529a69841d634cdfa9637284412e5cf1"><a name="a529a69841d634cdfa9637284412e5cf1"></a><a name="a529a69841d634cdfa9637284412e5cf1"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a0820f7d1c5b34d6eab999bd9dddfad6c"><a name="a0820f7d1c5b34d6eab999bd9dddfad6c"></a><a name="a0820f7d1c5b34d6eab999bd9dddfad6c"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a35dd1b1eab3a421f9c95d512860d5bda"><a name="a35dd1b1eab3a421f9c95d512860d5bda"></a><a name="a35dd1b1eab3a421f9c95d512860d5bda"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="ad2fe0856816f4eaf9c10e2a1d74419a9"><a name="ad2fe0856816f4eaf9c10e2a1d74419a9"></a><a name="ad2fe0856816f4eaf9c10e2a1d74419a9"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a2e8d180f3c914356af72e679446f4ab5"><a name="a2e8d180f3c914356af72e679446f4ab5"></a><a name="a2e8d180f3c914356af72e679446f4ab5"></a>Opacity of an element. The value ranges from <strong id="b15364171275710"><a name="b15364171275710"></a><a name="b15364171275710"></a>0</strong> to <strong id="b93641412135719"><a name="b93641412135719"></a><a name="b93641412135719"></a>1</strong>. The value <strong id="b03651712145710"><a name="b03651712145710"></a><a name="b03651712145710"></a>1</strong> means opaque, and <strong id="b17366101211577"><a name="b17366101211577"></a><a name="b17366101211577"></a>0</strong> means completely transparent.</p>
</td>
</tr>
</tbody>
</table>

## Events<a name="section1614413538447"></a>

The following events are supported.

<a name="table836435619510"></a>
<table><thead align="left"><tr id="row153658563517"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="a0ff86a4560fa46bfbeb711d109869422"><a name="a0ff86a4560fa46bfbeb711d109869422"></a><a name="a0ff86a4560fa46bfbeb711d109869422"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="a4c85eb8ca18b4169a25c4a9263fa63ed"><a name="a4c85eb8ca18b4169a25c4a9263fa63ed"></a><a name="a4c85eb8ca18b4169a25c4a9263fa63ed"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="ab30b2353efa245fbad4d2aaa2ee33def"><a name="ab30b2353efa245fbad4d2aaa2ee33def"></a><a name="ab30b2353efa245fbad4d2aaa2ee33def"></a>Triggered when</p>
</th>
</tr>
</thead>
<tbody><tr id="row0576209174715"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1652031354715"><a name="p1652031354715"></a><a name="p1652031354715"></a>sizechange</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p2520913204711"><a name="p2520913204711"></a><a name="p2520913204711"></a>{ size: { height: heightLength, width: widthLength }, mode: modeStr }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p8520101364714"><a name="p8520101364714"></a><a name="p8520101364714"></a>Triggered when the status of the slidable panel changes. Available <strong id="b122905111282"><a name="b122905111282"></a><a name="b122905111282"></a>mode</strong> values are as follows:</p>
<a name="ol5520181316476"></a><a name="ol5520181316476"></a><ol id="ol5520181316476"><li><p id="p4520141364713"><a name="p4520141364713"></a><a name="p4520141364713"></a><strong id="b45816387277"><a name="b45816387277"></a><a name="b45816387277"></a>mini</strong>: Displays a <strong id="b10542195774416"><a name="b10542195774416"></a><a name="b10542195774416"></a>minibar</strong> or <strong id="b134141855164411"><a name="b134141855164411"></a><a name="b134141855164411"></a>foldable</strong> panel in its minimum size.</p>
</li><li><p id="p6520191324711"><a name="p6520191324711"></a><a name="p6520191324711"></a><strong id="b2065484932810"><a name="b2065484932810"></a><a name="b2065484932810"></a>half</strong>: Displays a <strong id="b166951703457"><a name="b166951703457"></a><a name="b166951703457"></a>foldable</strong> panel in a medium-sized (halfscreen-like) area.</p>
</li><li><p id="p252018137477"><a name="p252018137477"></a><a name="p252018137477"></a><strong id="b1696104211503"><a name="b1696104211503"></a><a name="b1696104211503"></a>full</strong>: Displays a panel in a large (fullscreen-like) area.</p>
<div class="note" id="note1672712533287"><a name="note1672712533287"></a><a name="note1672712533287"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1672795314285"><a name="p1672795314285"></a><a name="p1672795314285"></a>The returned <strong id="b17504232153714"><a name="b17504232153714"></a><a name="b17504232153714"></a>height</strong> value indicates the content area height. However, when the <strong id="b6111851103715"><a name="b6111851103715"></a><a name="b6111851103715"></a>dragbar</strong> attribute is <strong id="b1019713539372"><a name="b1019713539372"></a><a name="b1019713539372"></a>true</strong>, the <strong id="b21622103812"><a name="b21622103812"></a><a name="b21622103812"></a>height</strong> value is the height of the drag bar plus that of the content area.</p>
</div></div>
</li></ol>
</td>
</tr>
</tbody>
</table>

## Methods<a name="section165301745164719"></a>

Only the following methods are supported.

<a name="table20753173210251"></a>
<table><thead align="left"><tr id="row575363214257"><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p id="p157531032112517"><a name="p157531032112517"></a><a name="p157531032112517"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p id="p77531632132518"><a name="p77531632132518"></a><a name="p77531632132518"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p id="p147531232132512"><a name="p147531232132512"></a><a name="p147531232132512"></a>Triggered when</p>
</th>
</tr>
</thead>
<tbody><tr id="row15753113210251"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p2314135812511"><a name="p2314135812511"></a><a name="p2314135812511"></a>show</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p7314115819256"><a name="p7314115819256"></a><a name="p7314115819256"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p0314958162512"><a name="p0314958162512"></a><a name="p0314958162512"></a>Pops the slidable panel up.</p>
</td>
</tr>
<tr id="row393410526251"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p7314358182512"><a name="p7314358182512"></a><a name="p7314358182512"></a>close</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p1231455814253"><a name="p1231455814253"></a><a name="p1231455814253"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p10314105842512"><a name="p10314105842512"></a><a name="p10314105842512"></a>Closes the slidable panel that has been popped up.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section36743614499"></a>

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
  showPanel() {
    this.$element('simplepanel').show()
  },
  closePanel() {
    this.$element('simplepanel').close()
  },
  changeMode(e) {
    this.modeFlag = e.mode
  }
}
```

![](figures/panel6.gif)

