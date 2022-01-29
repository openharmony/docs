# Type Attributes<a name="EN-US_TOPIC_0000001127125074"></a>

## Length Type<a name="section15406175012255"></a>

<a name="table726mcpsimp"></a>
<table><thead align="left"><tr id="row732mcpsimp"><th class="cellrowborder" valign="top" width="13.309999999999999%" id="mcps1.1.4.1.1"><p id="p734mcpsimp"><a name="p734mcpsimp"></a><a name="p734mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="26.35%" id="mcps1.1.4.1.2"><p id="p736mcpsimp"><a name="p736mcpsimp"></a><a name="p736mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="60.34%" id="mcps1.1.4.1.3"><p id="p738mcpsimp"><a name="p738mcpsimp"></a><a name="p738mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row739mcpsimp"><td class="cellrowborder" valign="top" width="13.309999999999999%" headers="mcps1.1.4.1.1 "><p id="p741mcpsimp"><a name="p741mcpsimp"></a><a name="p741mcpsimp"></a>length</p>
</td>
<td class="cellrowborder" valign="top" width="26.35%" headers="mcps1.1.4.1.2 "><p id="p743mcpsimp"><a name="p743mcpsimp"></a><a name="p743mcpsimp"></a>string | number</p>
</td>
<td class="cellrowborder" valign="top" width="60.34%" headers="mcps1.1.4.1.3 "><p id="p20927114417570"><a name="p20927114417570"></a><a name="p20927114417570"></a>Size unit. When the type is <strong id="b71391459181819"><a name="b71391459181819"></a><a name="b71391459181819"></a>number</strong>, the unit is px. When the type is <strong id="b3151125911813"><a name="b3151125911813"></a><a name="b3151125911813"></a>string</strong>, the pixel unit needs to be explicitly specified. Currently, the following pixel units are supported:</p>
<a name="ul817016527573"></a><a name="ul817016527573"></a><ul id="ul817016527573"><li><strong id="b1476613291919"><a name="b1476613291919"></a><a name="b1476613291919"></a>px</strong>: logical size unit.</li><li><strong id="b342812181918"><a name="b342812181918"></a><a name="b342812181918"></a>fp</strong><sup id="sup112751953020"><a name="sup112751953020"></a><a name="sup112751953020"></a>6+</sup>: font size unit, which varies according to the system font size. Only text components support the setting of the font size.</li></ul>
</td>
</tr>
<tr id="row477348822"><td class="cellrowborder" valign="top" width="13.309999999999999%" headers="mcps1.1.4.1.1 "><p id="p127741081724"><a name="p127741081724"></a><a name="p127741081724"></a>percentage</p>
</td>
<td class="cellrowborder" valign="top" width="26.35%" headers="mcps1.1.4.1.2 "><p id="p1777420810215"><a name="p1777420810215"></a><a name="p1777420810215"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="60.34%" headers="mcps1.1.4.1.3 "><p id="p377488228"><a name="p377488228"></a><a name="p377488228"></a>Unit in percentage, for example, <strong id="b17733540131913"><a name="b17733540131913"></a><a name="b17733540131913"></a>50%</strong>.</p>
</td>
</tr>
</tbody>
</table>

## Color Type<a name="section1326744510818"></a>

<a name="table112670450819"></a>
<table><thead align="left"><tr id="row11267545288"><th class="cellrowborder" valign="top" width="13.309999999999999%" id="mcps1.1.4.1.1"><p id="p326754519814"><a name="p326754519814"></a><a name="p326754519814"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="26.35%" id="mcps1.1.4.1.2"><p id="p1267045184"><a name="p1267045184"></a><a name="p1267045184"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="60.34%" id="mcps1.1.4.1.3"><p id="p626714451182"><a name="p626714451182"></a><a name="p626714451182"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row17267745782"><td class="cellrowborder" valign="top" width="13.309999999999999%" headers="mcps1.1.4.1.1 "><p id="p126711451816"><a name="p126711451816"></a><a name="p126711451816"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="26.35%" headers="mcps1.1.4.1.2 "><p id="p10267245383"><a name="p10267245383"></a><a name="p10267245383"></a>string | <a href="#table16879155017425"> Color enumeration values</a></p>
</td>
<td class="cellrowborder" valign="top" width="60.34%" headers="mcps1.1.4.1.3 "><p id="p142675454811"><a name="p142675454811"></a><a name="p142675454811"></a>Color information.</p>
<div class="p" id="a32012111f39544b09af2fab7da4c0fd4"><a name="a32012111f39544b09af2fab7da4c0fd4"></a><a name="a32012111f39544b09af2fab7da4c0fd4"></a>The String format is as follows:<a name="ul13562537161419"></a><a name="ul13562537161419"></a><ul id="ul13562537161419"><li>'rgb(255, 255, 255)'</li><li>'rgba(255, 255, 255, 1.0)'</li><li>HEX formats: #rrggbb and #aarrggbb</li><li>Enumeration format: 'black' and 'white'<div class="note" id="note1375413401269"><a name="note1375413401269"></a><a name="note1375413401269"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p075420406613"><a name="p075420406613"></a><a name="p075420406613"></a>The enumeration format is not supported in the JS script.</p>
</div></div>
</li></ul>
</div>
</td>
</tr>
</tbody>
</table>

**Table  1**  Currently supported colors

<a name="table16879155017425"></a>
<table><thead align="left"><tr id="row2879185094217"><th class="cellrowborder" valign="top" width="32.71%" id="mcps1.2.4.1.1"><p id="p1388011504420"><a name="p1388011504420"></a><a name="p1388011504420"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="36.44%" id="mcps1.2.4.1.2"><p id="p1288065019429"><a name="p1288065019429"></a><a name="p1288065019429"></a>Hexadecimal Code</p>
</th>
<th class="cellrowborder" valign="top" width="30.85%" id="mcps1.2.4.1.3"><p id="p3481124102312"><a name="p3481124102312"></a><a name="p3481124102312"></a>Color</p>
</th>
</tr>
</thead>
<tbody><tr id="row20756101410572"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1756101413571"><a name="p1756101413571"></a><a name="p1756101413571"></a>aliceblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p2756121418573"><a name="p2756121418573"></a><a name="p2756121418573"></a>#f0f8ff</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1275671417575"><a name="p1275671417575"></a><a name="p1275671417575"></a><a name="image77611647105815"></a><a name="image77611647105815"></a><span><img id="image77611647105815" src="figures/aliceblue.png"></span></p>
</td>
</tr>
<tr id="row1880150194215"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1095353414319"><a name="p1095353414319"></a><a name="p1095353414319"></a>antiquewhite</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p295323434313"><a name="p295323434313"></a><a name="p295323434313"></a>#faebd7</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1976961419400"><a name="p1976961419400"></a><a name="p1976961419400"></a><a name="image107691114134014"></a><a name="image107691114134014"></a><span><img id="image107691114134014" src="figures/antiquewhite.png"></span></p>
</td>
</tr>
<tr id="row2880115074210"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1395316349437"><a name="p1395316349437"></a><a name="p1395316349437"></a>aqua</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1595343464317"><a name="p1595343464317"></a><a name="p1595343464317"></a>#00ffff</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p156401004011"><a name="p156401004011"></a><a name="p156401004011"></a><a name="image196401004012"></a><a name="image196401004012"></a><span><img id="image196401004012" src="figures/aqua.png"></span></p>
</td>
</tr>
<tr id="row988095054210"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p5953183418437"><a name="p5953183418437"></a><a name="p5953183418437"></a>aquamarine</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1095373474319"><a name="p1095373474319"></a><a name="p1095373474319"></a>#7fffd4</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p15402182920402"><a name="p15402182920402"></a><a name="p15402182920402"></a><a name="image194021829144016"></a><a name="image194021829144016"></a><span><img id="image194021829144016" src="figures/aquamarine.png"></span></p>
</td>
</tr>
<tr id="row88801850104217"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1995393434315"><a name="p1995393434315"></a><a name="p1995393434315"></a>azure</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p995343484311"><a name="p995343484311"></a><a name="p995343484311"></a>#f0ffff</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p137142041174012"><a name="p137142041174012"></a><a name="p137142041174012"></a><a name="image371444120404"></a><a name="image371444120404"></a><span><img id="image371444120404" src="figures/azure.png"></span></p>
</td>
</tr>
<tr id="row1688011508423"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p09531434124311"><a name="p09531434124311"></a><a name="p09531434124311"></a>beige</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p19954143434315"><a name="p19954143434315"></a><a name="p19954143434315"></a>#f5f5dc</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p520025324012"><a name="p520025324012"></a><a name="p520025324012"></a><a name="image1620095314015"></a><a name="image1620095314015"></a><span><img id="image1620095314015" src="figures/beige.png"></span></p>
</td>
</tr>
<tr id="row58802050114219"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p595473413437"><a name="p595473413437"></a><a name="p595473413437"></a>bisque</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p12954234124313"><a name="p12954234124313"></a><a name="p12954234124313"></a>#ffe4c4</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p10516201310425"><a name="p10516201310425"></a><a name="p10516201310425"></a><a name="image1051621364218"></a><a name="image1051621364218"></a><span><img id="image1051621364218" src="figures/bisque.png"></span></p>
</td>
</tr>
<tr id="row08801550104211"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p13954183418436"><a name="p13954183418436"></a><a name="p13954183418436"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p19954173420433"><a name="p19954173420433"></a><a name="p19954173420433"></a>#000000</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1782641372612"><a name="p1782641372612"></a><a name="p1782641372612"></a><a name="image1826213162617"></a><a name="image1826213162617"></a><span><img id="image1826213162617" src="figures/000000-12.png"></span></p>
</td>
</tr>
<tr id="row17880250144216"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p119544349431"><a name="p119544349431"></a><a name="p119544349431"></a>blanchedalmond</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p795473415432"><a name="p795473415432"></a><a name="p795473415432"></a>#ffebcd</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1075803184213"><a name="p1075803184213"></a><a name="p1075803184213"></a><a name="image137584317429"></a><a name="image137584317429"></a><span><img id="image137584317429" src="figures/blanchedalmond.png"></span></p>
</td>
</tr>
<tr id="row8880195016428"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p10954133414320"><a name="p10954133414320"></a><a name="p10954133414320"></a>blue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1095413343431"><a name="p1095413343431"></a><a name="p1095413343431"></a>#0000ff</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p984711485429"><a name="p984711485429"></a><a name="p984711485429"></a><a name="image48472485425"></a><a name="image48472485425"></a><span><img id="image48472485425" src="figures/blue.png"></span></p>
</td>
</tr>
<tr id="row17880650184218"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p179549345439"><a name="p179549345439"></a><a name="p179549345439"></a>blueviolet</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p13954113410438"><a name="p13954113410438"></a><a name="p13954113410438"></a>#8a2be2</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p832413184311"><a name="p832413184311"></a><a name="p832413184311"></a><a name="image632418164312"></a><a name="image632418164312"></a><span><img id="image632418164312" src="figures/blueviolet.png"></span></p>
</td>
</tr>
<tr id="row14881165084220"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p169541348434"><a name="p169541348434"></a><a name="p169541348434"></a>brown</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p12954103404317"><a name="p12954103404317"></a><a name="p12954103404317"></a>#a52a2a</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1014112124314"><a name="p1014112124314"></a><a name="p1014112124314"></a><a name="image1141521144311"></a><a name="image1141521144311"></a><span><img id="image1141521144311" src="figures/brown.png"></span></p>
</td>
</tr>
<tr id="row9881135094211"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p395433416436"><a name="p395433416436"></a><a name="p395433416436"></a>burlywood</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p13954334184314"><a name="p13954334184314"></a><a name="p13954334184314"></a>#deB887</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p4262237124319"><a name="p4262237124319"></a><a name="p4262237124319"></a><a name="image62622037174315"></a><a name="image62622037174315"></a><span><img id="image62622037174315" src="figures/burlywood.png"></span></p>
</td>
</tr>
<tr id="row988195004212"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p895418344437"><a name="p895418344437"></a><a name="p895418344437"></a>cadetblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p6954143484312"><a name="p6954143484312"></a><a name="p6954143484312"></a>#5f9ea0</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p12812166114410"><a name="p12812166114410"></a><a name="p12812166114410"></a><a name="image181211613446"></a><a name="image181211613446"></a><span><img id="image181211613446" src="figures/cadetblue.png"></span></p>
</td>
</tr>
<tr id="row1088115507421"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p12954133418437"><a name="p12954133418437"></a><a name="p12954133418437"></a>chartreuse</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p19541734194319"><a name="p19541734194319"></a><a name="p19541734194319"></a>#7fff00</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p154011223204420"><a name="p154011223204420"></a><a name="p154011223204420"></a><a name="image1940111238440"></a><a name="image1940111238440"></a><span><img id="image1940111238440" src="figures/chartreuse.png"></span></p>
</td>
</tr>
<tr id="row688110509429"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p2954173474319"><a name="p2954173474319"></a><a name="p2954173474319"></a>chocolate</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p14955434124314"><a name="p14955434124314"></a><a name="p14955434124314"></a>#d2691e</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1973838164417"><a name="p1973838164417"></a><a name="p1973838164417"></a><a name="image09738385445"></a><a name="image09738385445"></a><span><img id="image09738385445" src="figures/chocolate.png"></span></p>
</td>
</tr>
<tr id="row13881450194219"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p69551434174319"><a name="p69551434174319"></a><a name="p69551434174319"></a>coral</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p695553420433"><a name="p695553420433"></a><a name="p695553420433"></a>#ff7f50</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p313785217448"><a name="p313785217448"></a><a name="p313785217448"></a><a name="image11136145254418"></a><a name="image11136145254418"></a><span><img id="image11136145254418" src="figures/coral.png"></span></p>
</td>
</tr>
<tr id="row588165010429"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1795533417432"><a name="p1795533417432"></a><a name="p1795533417432"></a>cornflowerblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p7955173464311"><a name="p7955173464311"></a><a name="p7955173464311"></a>#6495ed</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p131231967454"><a name="p131231967454"></a><a name="p131231967454"></a><a name="image121234614517"></a><a name="image121234614517"></a><span><img id="image121234614517" src="figures/cornflowerblue.png"></span></p>
</td>
</tr>
<tr id="row98811950154217"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1795513424312"><a name="p1795513424312"></a><a name="p1795513424312"></a>cornsilk</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p295573414437"><a name="p295573414437"></a><a name="p295573414437"></a>#fff8dc</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p9942111819457"><a name="p9942111819457"></a><a name="p9942111819457"></a><a name="image99421918104515"></a><a name="image99421918104515"></a><span><img id="image99421918104515" src="figures/cornsilk.png"></span></p>
</td>
</tr>
<tr id="row118818503421"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p495593419436"><a name="p495593419436"></a><a name="p495593419436"></a>crimson</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p19955173417439"><a name="p19955173417439"></a><a name="p19955173417439"></a>#dc143c</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p6661184204517"><a name="p6661184204517"></a><a name="p6661184204517"></a><a name="image1066115428450"></a><a name="image1066115428450"></a><span><img id="image1066115428450" src="figures/crimson.png"></span></p>
</td>
</tr>
<tr id="row588135012427"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p89551434204317"><a name="p89551434204317"></a><a name="p89551434204317"></a>cyan</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p13955183444317"><a name="p13955183444317"></a><a name="p13955183444317"></a>#00ffff</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p19208910174610"><a name="p19208910174610"></a><a name="p19208910174610"></a><a name="image72081710124617"></a><a name="image72081710124617"></a><span><img id="image72081710124617" src="figures/cyan.png"></span></p>
</td>
</tr>
<tr id="row1288155074210"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p395513418438"><a name="p395513418438"></a><a name="p395513418438"></a>darkblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p11955123417435"><a name="p11955123417435"></a><a name="p11955123417435"></a>#00008b</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p7468173717462"><a name="p7468173717462"></a><a name="p7468173717462"></a><a name="image13467737124616"></a><a name="image13467737124616"></a><span><img id="image13467737124616" src="figures/darkblue.png"></span></p>
</td>
</tr>
<tr id="row688245010423"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p295583444319"><a name="p295583444319"></a><a name="p295583444319"></a>darkcyan</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p09556348434"><a name="p09556348434"></a><a name="p09556348434"></a>#008b8b</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p725246164715"><a name="p725246164715"></a><a name="p725246164715"></a><a name="image525212644715"></a><a name="image525212644715"></a><span><img id="image525212644715" src="figures/darkcyan.png"></span></p>
</td>
</tr>
<tr id="row118821450164217"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p995583413433"><a name="p995583413433"></a><a name="p995583413433"></a>darkgoldenrod</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p16955203434313"><a name="p16955203434313"></a><a name="p16955203434313"></a>#b8860b</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p97511924184712"><a name="p97511924184712"></a><a name="p97511924184712"></a><a name="image4751724174713"></a><a name="image4751724174713"></a><span><img id="image4751724174713" src="figures/darkgoldenrod.png"></span></p>
</td>
</tr>
<tr id="row088214509426"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p7955153434311"><a name="p7955153434311"></a><a name="p7955153434311"></a>darkgray</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p8955173413434"><a name="p8955173413434"></a><a name="p8955173413434"></a>#a9a9a9</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p6679193894719"><a name="p6679193894719"></a><a name="p6679193894719"></a><a name="image3678203811476"></a><a name="image3678203811476"></a><span><img id="image3678203811476" src="figures/darkgray.png"></span></p>
</td>
</tr>
<tr id="row7882205017428"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p195663464310"><a name="p195663464310"></a><a name="p195663464310"></a>darkgreen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p18956734104315"><a name="p18956734104315"></a><a name="p18956734104315"></a>#006400</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p934115113477"><a name="p934115113477"></a><a name="p934115113477"></a><a name="image10341135115471"></a><a name="image10341135115471"></a><span><img id="image10341135115471" src="figures/darkgreen.png"></span></p>
</td>
</tr>
<tr id="row18882195094213"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p8956163410436"><a name="p8956163410436"></a><a name="p8956163410436"></a>darkgrey</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p8956103413430"><a name="p8956103413430"></a><a name="p8956103413430"></a>#a9a9a9</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p154576224816"><a name="p154576224816"></a><a name="p154576224816"></a><a name="image174576234818"></a><a name="image174576234818"></a><span><img id="image174576234818" src="figures/darkgrey.png"></span></p>
</td>
</tr>
<tr id="row13882195018427"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p16956123413434"><a name="p16956123413434"></a><a name="p16956123413434"></a>darkkhaki</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1956203434314"><a name="p1956203434314"></a><a name="p1956203434314"></a>#bdb76b</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p161121818144813"><a name="p161121818144813"></a><a name="p161121818144813"></a><a name="image1211251810485"></a><a name="image1211251810485"></a><span><img id="image1211251810485" src="figures/darkkhaki.png"></span></p>
</td>
</tr>
<tr id="row17882165074213"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p19956113414437"><a name="p19956113414437"></a><a name="p19956113414437"></a>darkmagenta</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p6956153494314"><a name="p6956153494314"></a><a name="p6956153494314"></a>#8b008b</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1901129154820"><a name="p1901129154820"></a><a name="p1901129154820"></a><a name="image13901729194817"></a><a name="image13901729194817"></a><span><img id="image13901729194817" src="figures/darkmagenta.png"></span></p>
</td>
</tr>
<tr id="row1688219505423"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p49561934134314"><a name="p49561934134314"></a><a name="p49561934134314"></a>darkolivegreen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p15956123484310"><a name="p15956123484310"></a><a name="p15956123484310"></a>#556b2f</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1768124214488"><a name="p1768124214488"></a><a name="p1768124214488"></a><a name="image1676724254816"></a><a name="image1676724254816"></a><span><img id="image1676724254816" src="figures/darkolivegreen.png"></span></p>
</td>
</tr>
<tr id="row2088285015425"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1395683494311"><a name="p1395683494311"></a><a name="p1395683494311"></a>darkorange</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1795693410435"><a name="p1795693410435"></a><a name="p1795693410435"></a>#ff8c00</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p166670244913"><a name="p166670244913"></a><a name="p166670244913"></a><a name="image6667112164914"></a><a name="image6667112164914"></a><span><img id="image6667112164914" src="figures/darkorange.png"></span></p>
</td>
</tr>
<tr id="row1288295024213"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1495603412438"><a name="p1495603412438"></a><a name="p1495603412438"></a>darkorchid</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p5956113414310"><a name="p5956113414310"></a><a name="p5956113414310"></a>#9932cc</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p847015159494"><a name="p847015159494"></a><a name="p847015159494"></a><a name="image84701815194914"></a><a name="image84701815194914"></a><span><img id="image84701815194914" src="figures/darkorchid.png"></span></p>
</td>
</tr>
<tr id="row28821750184212"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p6956153414313"><a name="p6956153414313"></a><a name="p6956153414313"></a>darkred</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1795633416439"><a name="p1795633416439"></a><a name="p1795633416439"></a>#8b0000</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p125621025154919"><a name="p125621025154919"></a><a name="p125621025154919"></a><a name="image25612253499"></a><a name="image25612253499"></a><span><img id="image25612253499" src="figures/darkred.png"></span></p>
</td>
</tr>
<tr id="row148831050194219"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p195613345434"><a name="p195613345434"></a><a name="p195613345434"></a>darksalmon</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p13956133415430"><a name="p13956133415430"></a><a name="p13956133415430"></a>#e9967a</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1759415365497"><a name="p1759415365497"></a><a name="p1759415365497"></a><a name="image12594136134919"></a><a name="image12594136134919"></a><span><img id="image12594136134919" src="figures/darksalmon.png"></span></p>
</td>
</tr>
<tr id="row118831750124214"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p495663413432"><a name="p495663413432"></a><a name="p495663413432"></a>darkseagreen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p49568345431"><a name="p49568345431"></a><a name="p49568345431"></a>#8fbc8f</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1732975418491"><a name="p1732975418491"></a><a name="p1732975418491"></a><a name="image1032917546492"></a><a name="image1032917546492"></a><span><img id="image1032917546492" src="figures/darkseagreen.png"></span></p>
</td>
</tr>
<tr id="row588365018424"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p29575345431"><a name="p29575345431"></a><a name="p29575345431"></a>darkslateblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p16957734114317"><a name="p16957734114317"></a><a name="p16957734114317"></a>#483d8b</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p549464135016"><a name="p549464135016"></a><a name="p549464135016"></a><a name="image154941412506"></a><a name="image154941412506"></a><span><img id="image154941412506" src="figures/darkslateblue.png"></span></p>
</td>
</tr>
<tr id="row1488395024212"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1295743434319"><a name="p1295743434319"></a><a name="p1295743434319"></a>darkslategray</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p2095743419434"><a name="p2095743419434"></a><a name="p2095743419434"></a>#2f4f4f</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p12483154112313"><a name="p12483154112313"></a><a name="p12483154112313"></a><a name="image19920646195110"></a><a name="image19920646195110"></a><span><img id="image19920646195110" src="figures/darkslategray.png"></span></p>
</td>
</tr>
<tr id="row198831750194217"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1295713415436"><a name="p1295713415436"></a><a name="p1295713415436"></a>darkslategrey</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1195793418437"><a name="p1195793418437"></a><a name="p1195793418437"></a>#2f4f4f</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p44831410231"><a name="p44831410231"></a><a name="p44831410231"></a><a name="image1160718251512"></a><a name="image1160718251512"></a><span><img id="image1160718251512" src="figures/darkslategrey.png"></span></p>
</td>
</tr>
<tr id="row14883145074219"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p295783417437"><a name="p295783417437"></a><a name="p295783417437"></a>darkturquoise</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p129571234194311"><a name="p129571234194311"></a><a name="p129571234194311"></a>#00ced1</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p104831452320"><a name="p104831452320"></a><a name="p104831452320"></a><a name="image578213365213"></a><a name="image578213365213"></a><span><img id="image578213365213" src="figures/darkturquoise.png"></span></p>
</td>
</tr>
<tr id="row178839502421"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p8957153494311"><a name="p8957153494311"></a><a name="p8957153494311"></a>darkviolet</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p9957834114320"><a name="p9957834114320"></a><a name="p9957834114320"></a>#9400d3</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p0483124192314"><a name="p0483124192314"></a><a name="p0483124192314"></a><a name="image144705418546"></a><a name="image144705418546"></a><span><img id="image144705418546" src="figures/darkviolet.png"></span></p>
</td>
</tr>
<tr id="row108834508427"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p12957234194317"><a name="p12957234194317"></a><a name="p12957234194317"></a>deeppink</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p8957834154320"><a name="p8957834154320"></a><a name="p8957834154320"></a>#ff1493</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1848394132314"><a name="p1848394132314"></a><a name="p1848394132314"></a><a name="image86106112572"></a><a name="image86106112572"></a><span><img id="image86106112572" src="figures/deeppink.png"></span></p>
</td>
</tr>
<tr id="row16883145015423"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p395717342433"><a name="p395717342433"></a><a name="p395717342433"></a>deepskyblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1895716341438"><a name="p1895716341438"></a><a name="p1895716341438"></a>#00bfff</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1727019195712"><a name="p1727019195712"></a><a name="p1727019195712"></a><a name="image1472611192570"></a><a name="image1472611192570"></a><span><img id="image1472611192570" src="figures/deepskyblue.png"></span></p>
</td>
</tr>
<tr id="row1988355016428"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p4957734144310"><a name="p4957734144310"></a><a name="p4957734144310"></a>dimgray</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p2095753414316"><a name="p2095753414316"></a><a name="p2095753414316"></a>#696969</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p144838420234"><a name="p144838420234"></a><a name="p144838420234"></a><a name="image87061041105713"></a><a name="image87061041105713"></a><span><img id="image87061041105713" src="figures/dimgray.png"></span></p>
</td>
</tr>
<tr id="row1883195054211"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p14958103494312"><a name="p14958103494312"></a><a name="p14958103494312"></a>dimgrey</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p14958193424311"><a name="p14958193424311"></a><a name="p14958193424311"></a>#696969</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p8483243233"><a name="p8483243233"></a><a name="p8483243233"></a><a name="image0693145711577"></a><a name="image0693145711577"></a><span><img id="image0693145711577" src="figures/dimgrey.png"></span></p>
</td>
</tr>
<tr id="row9884115014218"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p395873484320"><a name="p395873484320"></a><a name="p395873484320"></a>dodgerblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p195873434314"><a name="p195873434314"></a><a name="p195873434314"></a>#1e90ff</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1148314132317"><a name="p1148314132317"></a><a name="p1148314132317"></a><a name="image1576454581"></a><a name="image1576454581"></a><span><img id="image1576454581" src="figures/dodgerblue.png"></span></p>
</td>
</tr>
<tr id="row5884135015429"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p49582034144317"><a name="p49582034144317"></a><a name="p49582034144317"></a>firebrick</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p995803413434"><a name="p995803413434"></a><a name="p995803413434"></a>#b22222</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p134831411235"><a name="p134831411235"></a><a name="p134831411235"></a><a name="image197955135589"></a><a name="image197955135589"></a><span><img id="image197955135589" src="figures/firebrick.png"></span></p>
</td>
</tr>
<tr id="row18841850114213"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p3958163484313"><a name="p3958163484313"></a><a name="p3958163484313"></a>floralwhite</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p179582034114310"><a name="p179582034114310"></a><a name="p179582034114310"></a>#fffaf0</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p16484149236"><a name="p16484149236"></a><a name="p16484149236"></a><a name="image139481149155420"></a><a name="image139481149155420"></a><span><img id="image139481149155420" src="figures/floralwhite.png"></span></p>
</td>
</tr>
<tr id="row17884145015428"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p14958103464313"><a name="p14958103464313"></a><a name="p14958103464313"></a>forestgreen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1295853434318"><a name="p1295853434318"></a><a name="p1295853434318"></a>#228b22</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p948412414235"><a name="p948412414235"></a><a name="p948412414235"></a><a name="image2051115175516"></a><a name="image2051115175516"></a><span><img id="image2051115175516" src="figures/forestgreen.png"></span></p>
</td>
</tr>
<tr id="row108843501423"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p10959434144311"><a name="p10959434144311"></a><a name="p10959434144311"></a>fuchsia</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p9959173434317"><a name="p9959173434317"></a><a name="p9959173434317"></a>#ff00ff</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p148418462315"><a name="p148418462315"></a><a name="p148418462315"></a><a name="image163885331552"></a><a name="image163885331552"></a><span><img id="image163885331552" src="figures/fuchsia.png"></span></p>
</td>
</tr>
<tr id="row6884145054211"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p89591134194317"><a name="p89591134194317"></a><a name="p89591134194317"></a>gainsboro</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1959123419438"><a name="p1959123419438"></a><a name="p1959123419438"></a>#dcdcdc</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p18484442233"><a name="p18484442233"></a><a name="p18484442233"></a><a name="image512114316557"></a><a name="image512114316557"></a><span><img id="image512114316557" src="figures/gainsboro.png"></span></p>
</td>
</tr>
<tr id="row148848505421"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1895993414432"><a name="p1895993414432"></a><a name="p1895993414432"></a>ghostwhite</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p395915347438"><a name="p395915347438"></a><a name="p395915347438"></a>#f8f8ff</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p174845416232"><a name="p174845416232"></a><a name="p174845416232"></a><a name="image334975115514"></a><a name="image334975115514"></a><span><img id="image334975115514" src="figures/ghostwhite.png"></span></p>
</td>
</tr>
<tr id="row48841509423"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1959193464319"><a name="p1959193464319"></a><a name="p1959193464319"></a>gold</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p49591034164310"><a name="p49591034164310"></a><a name="p49591034164310"></a>#ffd700</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1048417418232"><a name="p1048417418232"></a><a name="p1048417418232"></a><a name="image123097594559"></a><a name="image123097594559"></a><span><img id="image123097594559" src="figures/gold.png"></span></p>
</td>
</tr>
<tr id="row15884125012423"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p595993417438"><a name="p595993417438"></a><a name="p595993417438"></a>goldenrod</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p395973494316"><a name="p395973494316"></a><a name="p395973494316"></a>#daa520</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1148410412317"><a name="p1148410412317"></a><a name="p1148410412317"></a><a name="image1257467125615"></a><a name="image1257467125615"></a><span><img id="image1257467125615" src="figures/goldenrod.png"></span></p>
</td>
</tr>
<tr id="row168841250154213"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p6959234194314"><a name="p6959234194314"></a><a name="p6959234194314"></a>gray</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p995923420437"><a name="p995923420437"></a><a name="p995923420437"></a>#808080</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p24848417232"><a name="p24848417232"></a><a name="p24848417232"></a><a name="image82198152566"></a><a name="image82198152566"></a><span><img id="image82198152566" src="figures/gray.png"></span></p>
</td>
</tr>
<tr id="row288475018428"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1959203411430"><a name="p1959203411430"></a><a name="p1959203411430"></a>green</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p119599349432"><a name="p119599349432"></a><a name="p119599349432"></a>#008000</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p648413492318"><a name="p648413492318"></a><a name="p648413492318"></a><a name="image17894132211567"></a><a name="image17894132211567"></a><span><img id="image17894132211567" src="figures/green.png"></span></p>
</td>
</tr>
<tr id="row888585015426"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p195914341437"><a name="p195914341437"></a><a name="p195914341437"></a>greenyellow</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p7959134174315"><a name="p7959134174315"></a><a name="p7959134174315"></a>#adff2f</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p164843462318"><a name="p164843462318"></a><a name="p164843462318"></a><a name="image7227130175610"></a><a name="image7227130175610"></a><span><img id="image7227130175610" src="figures/greenyellow.png"></span></p>
</td>
</tr>
<tr id="row78851150194218"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p15959123413439"><a name="p15959123413439"></a><a name="p15959123413439"></a>grey</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p12959134134315"><a name="p12959134134315"></a><a name="p12959134134315"></a>#808080</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p14846418233"><a name="p14846418233"></a><a name="p14846418233"></a><a name="image101063411564"></a><a name="image101063411564"></a><span><img id="image101063411564" src="figures/grey.png"></span></p>
</td>
</tr>
<tr id="row13885205064215"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p209593345434"><a name="p209593345434"></a><a name="p209593345434"></a>honeydew</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1396010340434"><a name="p1396010340434"></a><a name="p1396010340434"></a>#f0fff0</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p144841549234"><a name="p144841549234"></a><a name="p144841549234"></a><a name="image16390249155613"></a><a name="image16390249155613"></a><span><img id="image16390249155613" src="figures/honeydew.png"></span></p>
</td>
</tr>
<tr id="row16885550134212"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p196043494319"><a name="p196043494319"></a><a name="p196043494319"></a>hotpink</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p09601134124310"><a name="p09601134124310"></a><a name="p09601134124310"></a>#ff69b4</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p848416419236"><a name="p848416419236"></a><a name="p848416419236"></a><a name="image45759145615"></a><a name="image45759145615"></a><span><img id="image45759145615" src="figures/hotpink.png"></span></p>
</td>
</tr>
<tr id="row388595074216"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p09604346432"><a name="p09604346432"></a><a name="p09604346432"></a>indianred</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p19960193412439"><a name="p19960193412439"></a><a name="p19960193412439"></a>#cd5c5c</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p148464142314"><a name="p148464142314"></a><a name="p148464142314"></a><a name="image17625171719574"></a><a name="image17625171719574"></a><span><img id="image17625171719574" src="figures/indianred.png"></span></p>
</td>
</tr>
<tr id="row158851950194216"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p179606341439"><a name="p179606341439"></a><a name="p179606341439"></a>indigo</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p13960173413438"><a name="p13960173413438"></a><a name="p13960173413438"></a>#4b0082</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1484143230"><a name="p1484143230"></a><a name="p1484143230"></a><a name="image18844426195718"></a><a name="image18844426195718"></a><span><img id="image18844426195718" src="figures/indigo.png"></span></p>
</td>
</tr>
<tr id="row20885135024219"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1196093413436"><a name="p1196093413436"></a><a name="p1196093413436"></a>ivory</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p79603349438"><a name="p79603349438"></a><a name="p79603349438"></a>#fffff0</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p12484104122315"><a name="p12484104122315"></a><a name="p12484104122315"></a><a name="image54078364573"></a><a name="image54078364573"></a><span><img id="image54078364573" src="figures/ivory.png"></span></p>
</td>
</tr>
<tr id="row118857509427"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p096033415431"><a name="p096033415431"></a><a name="p096033415431"></a>khaki</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p15960143404310"><a name="p15960143404310"></a><a name="p15960143404310"></a>#f0e68c</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p144843412314"><a name="p144843412314"></a><a name="p144843412314"></a><a name="image031105025713"></a><a name="image031105025713"></a><span><img id="image031105025713" src="figures/khaki.png"></span></p>
</td>
</tr>
<tr id="row1488555084218"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p896083415433"><a name="p896083415433"></a><a name="p896083415433"></a>lavender</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p6960193416433"><a name="p6960193416433"></a><a name="p6960193416433"></a>#e6e6fa</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1748494152314"><a name="p1748494152314"></a><a name="p1748494152314"></a><a name="image81691158165711"></a><a name="image81691158165711"></a><span><img id="image81691158165711" src="figures/lavender.png"></span></p>
</td>
</tr>
<tr id="row788511508421"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p7960134154319"><a name="p7960134154319"></a><a name="p7960134154319"></a>lavenderblush</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p15960034114313"><a name="p15960034114313"></a><a name="p15960034114313"></a>#fff0f5</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1148417420231"><a name="p1148417420231"></a><a name="p1148417420231"></a><a name="image116018149585"></a><a name="image116018149585"></a><span><img id="image116018149585" src="figures/lavenderblush.png"></span></p>
</td>
</tr>
<tr id="row1788665017424"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p496010343432"><a name="p496010343432"></a><a name="p496010343432"></a>lawngreen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p169601734124315"><a name="p169601734124315"></a><a name="p169601734124315"></a>#7cfc00</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p448418442312"><a name="p448418442312"></a><a name="p448418442312"></a><a name="image1914715257581"></a><a name="image1914715257581"></a><span><img id="image1914715257581" src="figures/lawngreen.png"></span></p>
</td>
</tr>
<tr id="row14886155012420"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1696013484317"><a name="p1696013484317"></a><a name="p1696013484317"></a>lemonchiffon</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1996013418435"><a name="p1996013418435"></a><a name="p1996013418435"></a>#fffacd</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p548411482316"><a name="p548411482316"></a><a name="p548411482316"></a><a name="image9663173295815"></a><a name="image9663173295815"></a><span><img id="image9663173295815" src="figures/lemonchiffon.png"></span></p>
</td>
</tr>
<tr id="row6886105074220"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p179601534194310"><a name="p179601534194310"></a><a name="p179601534194310"></a>lightblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p596118340433"><a name="p596118340433"></a><a name="p596118340433"></a>#add8e6</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p2485164192318"><a name="p2485164192318"></a><a name="p2485164192318"></a><a name="image25234011586"></a><a name="image25234011586"></a><span><img id="image25234011586" src="figures/lightblue.png"></span></p>
</td>
</tr>
<tr id="row4886125074210"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p199612345432"><a name="p199612345432"></a><a name="p199612345432"></a>lightcoral</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p49616346432"><a name="p49616346432"></a><a name="p49616346432"></a>#f08080</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1148519422317"><a name="p1148519422317"></a><a name="p1148519422317"></a><a name="image560711514597"></a><a name="image560711514597"></a><span><img id="image560711514597" src="figures/lightcoral.png"></span></p>
</td>
</tr>
<tr id="row388655054213"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p19611934154316"><a name="p19611934154316"></a><a name="p19611934154316"></a>lightcyan</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p109611534164317"><a name="p109611534164317"></a><a name="p109611534164317"></a>#e0ffff</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p148511413232"><a name="p148511413232"></a><a name="p148511413232"></a><a name="image16760131375920"></a><a name="image16760131375920"></a><span><img id="image16760131375920" src="figures/lightcyan.png"></span></p>
</td>
</tr>
<tr id="row788695014213"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p11961334164313"><a name="p11961334164313"></a><a name="p11961334164313"></a>lightgoldenrodyellow</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p89611534194315"><a name="p89611534194315"></a><a name="p89611534194315"></a>#fafad2</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p548511419235"><a name="p548511419235"></a><a name="p548511419235"></a><a name="image1432932213597"></a><a name="image1432932213597"></a><span><img id="image1432932213597" src="figures/lightgoldenrodyellow.png"></span></p>
</td>
</tr>
<tr id="row1088618507427"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p159611634184319"><a name="p159611634184319"></a><a name="p159611634184319"></a>lightgray</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p396113414439"><a name="p396113414439"></a><a name="p396113414439"></a>#d3d3d3</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1148574172318"><a name="p1148574172318"></a><a name="p1148574172318"></a><a name="image114141631185918"></a><a name="image114141631185918"></a><span><img id="image114141631185918" src="figures/lightgray.png"></span></p>
</td>
</tr>
<tr id="row1788655034219"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1296114343430"><a name="p1296114343430"></a><a name="p1296114343430"></a>lightgreen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p296123416434"><a name="p296123416434"></a><a name="p296123416434"></a>#90ee90</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p124851241233"><a name="p124851241233"></a><a name="p124851241233"></a><a name="image1192143825911"></a><a name="image1192143825911"></a><span><img id="image1192143825911" src="figures/lightgreen.png"></span></p>
</td>
</tr>
<tr id="row14886105034210"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p10961163424311"><a name="p10961163424311"></a><a name="p10961163424311"></a>lightpink</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p17961334154318"><a name="p17961334154318"></a><a name="p17961334154318"></a>#ffb6c1</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p124857442312"><a name="p124857442312"></a><a name="p124857442312"></a><a name="image112183527591"></a><a name="image112183527591"></a><span><img id="image112183527591" src="figures/lightpink.png"></span></p>
</td>
</tr>
<tr id="row888725044217"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p17961123464312"><a name="p17961123464312"></a><a name="p17961123464312"></a>lightsalmon</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p99618346436"><a name="p99618346436"></a><a name="p99618346436"></a>#ffa07a</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1485341231"><a name="p1485341231"></a><a name="p1485341231"></a><a name="image14407115965919"></a><a name="image14407115965919"></a><span><img id="image14407115965919" src="figures/lightsalmon.png"></span></p>
</td>
</tr>
<tr id="row38874504425"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p3961153444310"><a name="p3961153444310"></a><a name="p3961153444310"></a>lightseagreen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p69611534134311"><a name="p69611534134311"></a><a name="p69611534134311"></a>#20b2aa</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p64851448238"><a name="p64851448238"></a><a name="p64851448238"></a><a name="image182055131001"></a><a name="image182055131001"></a><span><img id="image182055131001" src="figures/lightseagreen.png"></span></p>
</td>
</tr>
<tr id="row1188775014216"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p20962193454318"><a name="p20962193454318"></a><a name="p20962193454318"></a>lightskyblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p18962534114316"><a name="p18962534114316"></a><a name="p18962534114316"></a>#87cefa</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p11485174142313"><a name="p11485174142313"></a><a name="p11485174142313"></a><a name="image180552120013"></a><a name="image180552120013"></a><span><img id="image180552120013" src="figures/lightskyblue.png"></span></p>
</td>
</tr>
<tr id="row0887115064217"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p89627349432"><a name="p89627349432"></a><a name="p89627349432"></a>lightslategray</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p296273415433"><a name="p296273415433"></a><a name="p296273415433"></a>#778899</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p248514142319"><a name="p248514142319"></a><a name="p248514142319"></a><a name="image1496113214011"></a><a name="image1496113214011"></a><span><img id="image1496113214011" src="figures/lightslategray.png"></span></p>
</td>
</tr>
<tr id="row88871750194214"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p29621834144318"><a name="p29621834144318"></a><a name="p29621834144318"></a>lightslategrey</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p496203464319"><a name="p496203464319"></a><a name="p496203464319"></a>#778899</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p114851647236"><a name="p114851647236"></a><a name="p114851647236"></a><a name="image14141640401"></a><a name="image14141640401"></a><span><img id="image14141640401" src="figures/lightslategrey.png"></span></p>
</td>
</tr>
<tr id="row168871450154219"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p896213347439"><a name="p896213347439"></a><a name="p896213347439"></a>lightsteelblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p59624344432"><a name="p59624344432"></a><a name="p59624344432"></a>#b0c4de</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p16485124132310"><a name="p16485124132310"></a><a name="p16485124132310"></a><a name="image567018461208"></a><a name="image567018461208"></a><span><img id="image567018461208" src="figures/lightsteelblue.png"></span></p>
</td>
</tr>
<tr id="row8887250194218"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p209621834104314"><a name="p209621834104314"></a><a name="p209621834104314"></a>lightyellow</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p119622034174311"><a name="p119622034174311"></a><a name="p119622034174311"></a>#ffffe0</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p44851441237"><a name="p44851441237"></a><a name="p44851441237"></a><a name="image29067560017"></a><a name="image29067560017"></a><span><img id="image29067560017" src="figures/lightyellow.png"></span></p>
</td>
</tr>
<tr id="row12887135004214"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p179626343430"><a name="p179626343430"></a><a name="p179626343430"></a>lime</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1096253419433"><a name="p1096253419433"></a><a name="p1096253419433"></a>#00ff00</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p197548441411"><a name="p197548441411"></a><a name="p197548441411"></a><a name="image327305919116"></a><a name="image327305919116"></a><span><img id="image327305919116" src="figures/lime.png"></span></p>
</td>
</tr>
<tr id="row198876501429"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p796253454319"><a name="p796253454319"></a><a name="p796253454319"></a>limegreen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p129621634104313"><a name="p129621634104313"></a><a name="p129621634104313"></a>#32cd32</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1075212446118"><a name="p1075212446118"></a><a name="p1075212446118"></a><a name="image172591371216"></a><a name="image172591371216"></a><span><img id="image172591371216" src="figures/limegreen.png"></span></p>
</td>
</tr>
<tr id="row9888165016421"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1396263416438"><a name="p1396263416438"></a><a name="p1396263416438"></a>linen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p39620348432"><a name="p39620348432"></a><a name="p39620348432"></a>#faf0e6</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p13485154112310"><a name="p13485154112310"></a><a name="p13485154112310"></a><a name="image330610261115"></a><a name="image330610261115"></a><span><img id="image330610261115" src="figures/linen.png"></span></p>
</td>
</tr>
<tr id="row48882050194220"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p19962134154315"><a name="p19962134154315"></a><a name="p19962134154315"></a>magenta</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p096223411435"><a name="p096223411435"></a><a name="p096223411435"></a>#ff00ff</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p74855410238"><a name="p74855410238"></a><a name="p74855410238"></a><a name="image16368183418115"></a><a name="image16368183418115"></a><span><img id="image16368183418115" src="figures/magenta.png"></span></p>
</td>
</tr>
<tr id="row1188825084214"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p8962153410436"><a name="p8962153410436"></a><a name="p8962153410436"></a>maroon</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p7962034124315"><a name="p7962034124315"></a><a name="p7962034124315"></a>#800000</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1048512413235"><a name="p1048512413235"></a><a name="p1048512413235"></a><a name="image127711851322"></a><a name="image127711851322"></a><span><img id="image127711851322" src="figures/maroon.png"></span></p>
</td>
</tr>
<tr id="row388815084210"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p2963113484315"><a name="p2963113484315"></a><a name="p2963113484315"></a>mediumaquamarine</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p159632343431"><a name="p159632343431"></a><a name="p159632343431"></a>#66cdaa</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p104861442314"><a name="p104861442314"></a><a name="p104861442314"></a><a name="image176388116314"></a><a name="image176388116314"></a><span><img id="image176388116314" src="figures/mediumaquamarine.png"></span></p>
</td>
</tr>
<tr id="row1888816508426"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p396323494320"><a name="p396323494320"></a><a name="p396323494320"></a>mediumblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p69631348438"><a name="p69631348438"></a><a name="p69631348438"></a>#0000cd</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1748620417231"><a name="p1748620417231"></a><a name="p1748620417231"></a><a name="image552414121438"></a><a name="image552414121438"></a><span><img id="image552414121438" src="figures/mediumblue.png"></span></p>
</td>
</tr>
<tr id="row688865016422"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p896353494315"><a name="p896353494315"></a><a name="p896353494315"></a>mediumorchid</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1963234194316"><a name="p1963234194316"></a><a name="p1963234194316"></a>#ba55d3</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p34861492311"><a name="p34861492311"></a><a name="p34861492311"></a><a name="image1678214241137"></a><a name="image1678214241137"></a><span><img id="image1678214241137" src="figures/mediumorchid.png"></span></p>
</td>
</tr>
<tr id="row588895044218"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p596363454319"><a name="p596363454319"></a><a name="p596363454319"></a>mediumpurple</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p996373416438"><a name="p996373416438"></a><a name="p996373416438"></a>#9370db</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p114861842234"><a name="p114861842234"></a><a name="p114861842234"></a><a name="image145821533238"></a><a name="image145821533238"></a><span><img id="image145821533238" src="figures/mediumpurple.png"></span></p>
</td>
</tr>
<tr id="row1088818503429"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p7963163411431"><a name="p7963163411431"></a><a name="p7963163411431"></a>mediumseagreen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1996363419431"><a name="p1996363419431"></a><a name="p1996363419431"></a>#3cb371</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1648616482316"><a name="p1648616482316"></a><a name="p1648616482316"></a><a name="image79201141639"></a><a name="image79201141639"></a><span><img id="image79201141639" src="figures/mediumseagreen.png"></span></p>
</td>
</tr>
<tr id="row488845010428"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p7963434104316"><a name="p7963434104316"></a><a name="p7963434104316"></a>mediumslateblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1963183474314"><a name="p1963183474314"></a><a name="p1963183474314"></a>#7b68ee</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1848616420232"><a name="p1848616420232"></a><a name="p1848616420232"></a><a name="image14279151732"></a><a name="image14279151732"></a><span><img id="image14279151732" src="figures/mediumslateblue.png"></span></p>
</td>
</tr>
<tr id="row488812503422"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p79638343437"><a name="p79638343437"></a><a name="p79638343437"></a>mediumspringgreen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p49631134164318"><a name="p49631134164318"></a><a name="p49631134164318"></a>#00fa9a</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p248694132317"><a name="p248694132317"></a><a name="p248694132317"></a><a name="image21781112415"></a><a name="image21781112415"></a><span><img id="image21781112415" src="figures/mediumspringgreen.png"></span></p>
</td>
</tr>
<tr id="row3888145010427"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p796373411436"><a name="p796373411436"></a><a name="p796373411436"></a>mediumturquoise</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1196333484319"><a name="p1196333484319"></a><a name="p1196333484319"></a>#48d1cc</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p17486104162311"><a name="p17486104162311"></a><a name="p17486104162311"></a><a name="image127288116416"></a><a name="image127288116416"></a><span><img id="image127288116416" src="figures/mediumturquoise.png"></span></p>
</td>
</tr>
<tr id="row1188910506427"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p196363404319"><a name="p196363404319"></a><a name="p196363404319"></a>mediumvioletred</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p17963123434318"><a name="p17963123434318"></a><a name="p17963123434318"></a>#c71585</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p64863420232"><a name="p64863420232"></a><a name="p64863420232"></a><a name="image0130122316412"></a><a name="image0130122316412"></a><span><img id="image0130122316412" src="figures/mediumvioletred.png"></span></p>
</td>
</tr>
<tr id="row11889145017422"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p12963834134320"><a name="p12963834134320"></a><a name="p12963834134320"></a>midnightblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p119631634154316"><a name="p119631634154316"></a><a name="p119631634154316"></a>#191970</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p74866419239"><a name="p74866419239"></a><a name="p74866419239"></a><a name="image886113218413"></a><a name="image886113218413"></a><span><img id="image886113218413" src="figures/midnightblue.png"></span></p>
</td>
</tr>
<tr id="row3889175084212"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p109641334194319"><a name="p109641334194319"></a><a name="p109641334194319"></a>mintcream</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p2964134154313"><a name="p2964134154313"></a><a name="p2964134154313"></a>#f5fffa</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p144864452315"><a name="p144864452315"></a><a name="p144864452315"></a><a name="image199418431849"></a><a name="image199418431849"></a><span><img id="image199418431849" src="figures/mintcream.png"></span></p>
</td>
</tr>
<tr id="row58897507428"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p17964183474319"><a name="p17964183474319"></a><a name="p17964183474319"></a>mistyrose</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p18964143418439"><a name="p18964143418439"></a><a name="p18964143418439"></a>#ffe4e1</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p154863452317"><a name="p154863452317"></a><a name="p154863452317"></a><a name="image1544814529417"></a><a name="image1544814529417"></a><span><img id="image1544814529417" src="figures/mistyrose.png"></span></p>
</td>
</tr>
<tr id="row11889115019424"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p996463410432"><a name="p996463410432"></a><a name="p996463410432"></a>moccasin</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p17964173415431"><a name="p17964173415431"></a><a name="p17964173415431"></a>#ffe4b5</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1748694102313"><a name="p1748694102313"></a><a name="p1748694102313"></a><a name="image1398462159"></a><a name="image1398462159"></a><span><img id="image1398462159" src="figures/moccasin.png"></span></p>
</td>
</tr>
<tr id="row17889175019429"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p3964634184312"><a name="p3964634184312"></a><a name="p3964634184312"></a>navajowhite</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p2964183419433"><a name="p2964183419433"></a><a name="p2964183419433"></a>#ffdead</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p34868452317"><a name="p34868452317"></a><a name="p34868452317"></a><a name="image136488252511"></a><a name="image136488252511"></a><span><img id="image136488252511" src="figures/navajowhite.png"></span></p>
</td>
</tr>
<tr id="row788975054218"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p18964734154312"><a name="p18964734154312"></a><a name="p18964734154312"></a>navy</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p119642342434"><a name="p119642342434"></a><a name="p119642342434"></a>#000080</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1348614416237"><a name="p1348614416237"></a><a name="p1348614416237"></a><a name="image361419372052"></a><a name="image361419372052"></a><span><img id="image361419372052" src="figures/navy.png"></span></p>
</td>
</tr>
<tr id="row18889550104218"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1196414342438"><a name="p1196414342438"></a><a name="p1196414342438"></a>oldlace</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1596416348430"><a name="p1596416348430"></a><a name="p1596416348430"></a>#fdf5e6</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1486164172311"><a name="p1486164172311"></a><a name="p1486164172311"></a><a name="image1226865012514"></a><a name="image1226865012514"></a><span><img id="image1226865012514" src="figures/oldlace.png"></span></p>
</td>
</tr>
<tr id="row1788916501420"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p69642344435"><a name="p69642344435"></a><a name="p69642344435"></a>olive</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p5964183413436"><a name="p5964183413436"></a><a name="p5964183413436"></a>#808000</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1486104122318"><a name="p1486104122318"></a><a name="p1486104122318"></a><a name="image1366861467"></a><a name="image1366861467"></a><span><img id="image1366861467" src="figures/olive.png"></span></p>
</td>
</tr>
<tr id="row10889115019421"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p6964834154315"><a name="p6964834154315"></a><a name="p6964834154315"></a>olivedrab</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p12964203414434"><a name="p12964203414434"></a><a name="p12964203414434"></a>#6b8e23</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p12486134162319"><a name="p12486134162319"></a><a name="p12486134162319"></a><a name="image345111613612"></a><a name="image345111613612"></a><span><img id="image345111613612" src="figures/olivedrab.png"></span></p>
</td>
</tr>
<tr id="row1089045010425"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p209641434124310"><a name="p209641434124310"></a><a name="p209641434124310"></a>orange</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1964123417430"><a name="p1964123417430"></a><a name="p1964123417430"></a>#ffa500</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1848618417239"><a name="p1848618417239"></a><a name="p1848618417239"></a><a name="image57231425662"></a><a name="image57231425662"></a><span><img id="image57231425662" src="figures/orange.png"></span></p>
</td>
</tr>
<tr id="row5890115018420"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p2964173434318"><a name="p2964173434318"></a><a name="p2964173434318"></a>orangered</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p2964163420434"><a name="p2964163420434"></a><a name="p2964163420434"></a>#ff4500</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p134861341235"><a name="p134861341235"></a><a name="p134861341235"></a><a name="image1836216353619"></a><a name="image1836216353619"></a><span><img id="image1836216353619" src="figures/orangered.png"></span></p>
</td>
</tr>
<tr id="row7890195013422"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p18965103413434"><a name="p18965103413434"></a><a name="p18965103413434"></a>orchid</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p17965163416439"><a name="p17965163416439"></a><a name="p17965163416439"></a>#da70d6</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p24867413231"><a name="p24867413231"></a><a name="p24867413231"></a><a name="image1531619437610"></a><a name="image1531619437610"></a><span><img id="image1531619437610" src="figures/orchid.png"></span></p>
</td>
</tr>
<tr id="row3890175064219"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p6965193414435"><a name="p6965193414435"></a><a name="p6965193414435"></a>palegoldenrod</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p179657346433"><a name="p179657346433"></a><a name="p179657346433"></a>#eee8aa</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p174871740238"><a name="p174871740238"></a><a name="p174871740238"></a><a name="image156101055866"></a><a name="image156101055866"></a><span><img id="image156101055866" src="figures/palegoldenrod.png"></span></p>
</td>
</tr>
<tr id="row3890125004215"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p69657347433"><a name="p69657347433"></a><a name="p69657347433"></a>palegreen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p196518340434"><a name="p196518340434"></a><a name="p196518340434"></a>#98fb98</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1348764142310"><a name="p1348764142310"></a><a name="p1348764142310"></a><a name="image75602010875"></a><a name="image75602010875"></a><span><img id="image75602010875" src="figures/palegreen.png"></span></p>
</td>
</tr>
<tr id="row1890125019428"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1096515344438"><a name="p1096515344438"></a><a name="p1096515344438"></a>paleturquoise</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p11965143434316"><a name="p11965143434316"></a><a name="p11965143434316"></a>#afeeee</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p13487184102316"><a name="p13487184102316"></a><a name="p13487184102316"></a><a name="image27293245719"></a><a name="image27293245719"></a><span><img id="image27293245719" src="figures/paleturquoise.png"></span></p>
</td>
</tr>
<tr id="row289055064214"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p89652034144311"><a name="p89652034144311"></a><a name="p89652034144311"></a>palevioletred</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p17965183454318"><a name="p17965183454318"></a><a name="p17965183454318"></a>#db7093</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p54876482317"><a name="p54876482317"></a><a name="p54876482317"></a><a name="image192681937278"></a><a name="image192681937278"></a><span><img id="image192681937278" src="figures/palevioletred.png"></span></p>
</td>
</tr>
<tr id="row989016509428"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p596510344434"><a name="p596510344434"></a><a name="p596510344434"></a>papayawhip</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p19651034124319"><a name="p19651034124319"></a><a name="p19651034124319"></a>#ffefd5</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p2048717413236"><a name="p2048717413236"></a><a name="p2048717413236"></a><a name="image19361820162213"></a><a name="image19361820162213"></a><span><img id="image19361820162213" src="figures/papayawhip.png"></span></p>
</td>
</tr>
<tr id="row1989015507428"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p11965134184312"><a name="p11965134184312"></a><a name="p11965134184312"></a>peachpuff</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p10965334184319"><a name="p10965334184319"></a><a name="p10965334184319"></a>#ffdab9</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p184874412319"><a name="p184874412319"></a><a name="p184874412319"></a><a name="image1493153512211"></a><a name="image1493153512211"></a><span><img id="image1493153512211" src="figures/peachpuff.png"></span></p>
</td>
</tr>
<tr id="row3890450124216"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p209652347439"><a name="p209652347439"></a><a name="p209652347439"></a>peru</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1796515342430"><a name="p1796515342430"></a><a name="p1796515342430"></a>#cd853f</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p348719432311"><a name="p348719432311"></a><a name="p348719432311"></a><a name="image29585439227"></a><a name="image29585439227"></a><span><img id="image29585439227" src="figures/peru.png"></span></p>
</td>
</tr>
<tr id="row178914503424"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p8965193474317"><a name="p8965193474317"></a><a name="p8965193474317"></a>pink</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p2965103416438"><a name="p2965103416438"></a><a name="p2965103416438"></a>#ffc0cb</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p44871042237"><a name="p44871042237"></a><a name="p44871042237"></a><a name="image14330155414221"></a><a name="image14330155414221"></a><span><img id="image14330155414221" src="figures/pink.png"></span></p>
</td>
</tr>
<tr id="row19891135011422"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p596519340436"><a name="p596519340436"></a><a name="p596519340436"></a>plum</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p119657346437"><a name="p119657346437"></a><a name="p119657346437"></a>#dda0dd</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1148717482320"><a name="p1148717482320"></a><a name="p1148717482320"></a><a name="image068120317233"></a><a name="image068120317233"></a><span><img id="image068120317233" src="figures/plum.png"></span></p>
</td>
</tr>
<tr id="row7891125054219"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p12966134134315"><a name="p12966134134315"></a><a name="p12966134134315"></a>powderblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1966434184316"><a name="p1966434184316"></a><a name="p1966434184316"></a>#b0e0e6</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p144872414232"><a name="p144872414232"></a><a name="p144872414232"></a><a name="image0858104812312"></a><a name="image0858104812312"></a><span><img id="image0858104812312" src="figures/powderblue.png"></span></p>
</td>
</tr>
<tr id="row1889111504427"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p596618342434"><a name="p596618342434"></a><a name="p596618342434"></a>purple</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1496633424313"><a name="p1496633424313"></a><a name="p1496633424313"></a>#800080</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p44873416233"><a name="p44873416233"></a><a name="p44873416233"></a><a name="image112171247241"></a><a name="image112171247241"></a><span><img id="image112171247241" src="figures/purple.png"></span></p>
</td>
</tr>
<tr id="row8370172417592"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p037182425915"><a name="p037182425915"></a><a name="p037182425915"></a>rebeccapurple</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p5371324105914"><a name="p5371324105914"></a><a name="p5371324105914"></a>#663399</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1537112418598"><a name="p1537112418598"></a><a name="p1537112418598"></a><a name="image591817019012"></a><a name="image591817019012"></a><span><img id="image591817019012" src="figures/rebeccapurple.png"></span></p>
</td>
</tr>
<tr id="row1689117509426"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p119661734114313"><a name="p119661734114313"></a><a name="p119661734114313"></a>red</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p8966193414314"><a name="p8966193414314"></a><a name="p8966193414314"></a>#ff0000</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p12487144192318"><a name="p12487144192318"></a><a name="p12487144192318"></a><a name="image19292173182417"></a><a name="image19292173182417"></a><span><img id="image19292173182417" src="figures/red.png"></span></p>
</td>
</tr>
<tr id="row12891350194210"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p79666343431"><a name="p79666343431"></a><a name="p79666343431"></a>rosybrown</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p796683464310"><a name="p796683464310"></a><a name="p796683464310"></a>#bc8f8f</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p248714412312"><a name="p248714412312"></a><a name="p248714412312"></a><a name="image93291912132510"></a><a name="image93291912132510"></a><span><img id="image93291912132510" src="figures/rosybrown.png"></span></p>
</td>
</tr>
<tr id="row17891155019427"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1796612345437"><a name="p1796612345437"></a><a name="p1796612345437"></a>royalblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p13966143414314"><a name="p13966143414314"></a><a name="p13966143414314"></a>#4169e1</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1748710442311"><a name="p1748710442311"></a><a name="p1748710442311"></a><a name="image129511229252"></a><a name="image129511229252"></a><span><img id="image129511229252" src="figures/royalblue.png"></span></p>
</td>
</tr>
<tr id="row3891185044219"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p9966334124313"><a name="p9966334124313"></a><a name="p9966334124313"></a>saddlebrown</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p119662034184318"><a name="p119662034184318"></a><a name="p119662034184318"></a>#8b4513</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p6487194162311"><a name="p6487194162311"></a><a name="p6487194162311"></a><a name="image206551331122510"></a><a name="image206551331122510"></a><span><img id="image206551331122510" src="figures/saddlebrown.png"></span></p>
</td>
</tr>
<tr id="row88911250114213"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p149661634174319"><a name="p149661634174319"></a><a name="p149661634174319"></a>salmon</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1296643474310"><a name="p1296643474310"></a><a name="p1296643474310"></a>#fa8072</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p16487343237"><a name="p16487343237"></a><a name="p16487343237"></a><a name="image116291440112510"></a><a name="image116291440112510"></a><span><img id="image116291440112510" src="figures/salmon.png"></span></p>
</td>
</tr>
<tr id="row1189175094216"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p69662344435"><a name="p69662344435"></a><a name="p69662344435"></a>sandybrown</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p296653454315"><a name="p296653454315"></a><a name="p296653454315"></a>#f4a460</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p64877417234"><a name="p64877417234"></a><a name="p64877417234"></a><a name="image19108115142510"></a><a name="image19108115142510"></a><span><img id="image19108115142510" src="figures/sandybrown.png"></span></p>
</td>
</tr>
<tr id="row18922050194216"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p79667344434"><a name="p79667344434"></a><a name="p79667344434"></a>seagreen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p996623434311"><a name="p996623434311"></a><a name="p996623434311"></a>#2e8b57</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1248718492319"><a name="p1248718492319"></a><a name="p1248718492319"></a><a name="image1120665917251"></a><a name="image1120665917251"></a><span><img id="image1120665917251" src="figures/seagreen.png"></span></p>
</td>
</tr>
<tr id="row13892145014212"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1796643474313"><a name="p1796643474313"></a><a name="p1796643474313"></a>seashell</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p179671534154318"><a name="p179671534154318"></a><a name="p179671534154318"></a>#fff5ee</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p8487348239"><a name="p8487348239"></a><a name="p8487348239"></a><a name="image615210882610"></a><a name="image615210882610"></a><span><img id="image615210882610" src="figures/seashell.png"></span></p>
</td>
</tr>
<tr id="row11892950104216"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p14967203424314"><a name="p14967203424314"></a><a name="p14967203424314"></a>sienna</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p496712341435"><a name="p496712341435"></a><a name="p496712341435"></a>#a0522d</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p848718418230"><a name="p848718418230"></a><a name="p848718418230"></a><a name="image089541622616"></a><a name="image089541622616"></a><span><img id="image089541622616" src="figures/sienna.png"></span></p>
</td>
</tr>
<tr id="row20892105019426"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p896710346433"><a name="p896710346433"></a><a name="p896710346433"></a>silver</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p89671634164310"><a name="p89671634164310"></a><a name="p89671634164310"></a>#c0c0c0</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p2488248237"><a name="p2488248237"></a><a name="p2488248237"></a><a name="image6891182410263"></a><a name="image6891182410263"></a><span><img id="image6891182410263" src="figures/silver.png"></span></p>
</td>
</tr>
<tr id="row19892155010427"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p199671334174315"><a name="p199671334174315"></a><a name="p199671334174315"></a>skyblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p996723417438"><a name="p996723417438"></a><a name="p996723417438"></a>#87ceeb</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p448814417234"><a name="p448814417234"></a><a name="p448814417234"></a><a name="image1641614341261"></a><a name="image1641614341261"></a><span><img id="image1641614341261" src="figures/skyblue.png"></span></p>
</td>
</tr>
<tr id="row13892105004215"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1296714343437"><a name="p1296714343437"></a><a name="p1296714343437"></a>slateblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p796717341432"><a name="p796717341432"></a><a name="p796717341432"></a>#6a5acd</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1648817442315"><a name="p1648817442315"></a><a name="p1648817442315"></a><a name="image320694413264"></a><a name="image320694413264"></a><span><img id="image320694413264" src="figures/slateblue.png"></span></p>
</td>
</tr>
<tr id="row1489235019428"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p119671434114315"><a name="p119671434114315"></a><a name="p119671434114315"></a>slategray</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p15967123454311"><a name="p15967123454311"></a><a name="p15967123454311"></a>#708090</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1448814432318"><a name="p1448814432318"></a><a name="p1448814432318"></a><a name="image1580565162613"></a><a name="image1580565162613"></a><span><img id="image1580565162613" src="figures/slategray.png"></span></p>
</td>
</tr>
<tr id="row16892195044211"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p196753413430"><a name="p196753413430"></a><a name="p196753413430"></a>slategrey</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p139671234134310"><a name="p139671234134310"></a><a name="p139671234134310"></a>#708090</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p74881432316"><a name="p74881432316"></a><a name="p74881432316"></a><a name="image7301503270"></a><a name="image7301503270"></a><span><img id="image7301503270" src="figures/slategray-13.png"></span></p>
</td>
</tr>
<tr id="row138922050154211"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p796733464316"><a name="p796733464316"></a><a name="p796733464316"></a>snow</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p19967634154319"><a name="p19967634154319"></a><a name="p19967634154319"></a>#fffafa</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p5488104192310"><a name="p5488104192310"></a><a name="p5488104192310"></a><a name="image17397512162712"></a><a name="image17397512162712"></a><span><img id="image17397512162712" src="figures/snow.png"></span></p>
</td>
</tr>
<tr id="row889355044220"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1696711347433"><a name="p1696711347433"></a><a name="p1696711347433"></a>springgreen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p196713434319"><a name="p196713434319"></a><a name="p196713434319"></a>#00ff7f</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p134888418233"><a name="p134888418233"></a><a name="p134888418233"></a><a name="image1114411216274"></a><a name="image1114411216274"></a><span><img id="image1114411216274" src="figures/springgreen.png"></span></p>
</td>
</tr>
<tr id="row188931950154212"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p896773411431"><a name="p896773411431"></a><a name="p896773411431"></a>steelblue</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1496783484310"><a name="p1496783484310"></a><a name="p1496783484310"></a>#4682b4</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p648812417237"><a name="p648812417237"></a><a name="p648812417237"></a><a name="image19263629122717"></a><a name="image19263629122717"></a><span><img id="image19263629122717" src="figures/steelblue.png"></span></p>
</td>
</tr>
<tr id="row2089365019421"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p99673346432"><a name="p99673346432"></a><a name="p99673346432"></a>tan</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p189681934164313"><a name="p189681934164313"></a><a name="p189681934164313"></a>#d2b48c</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p04887411230"><a name="p04887411230"></a><a name="p04887411230"></a><a name="image18707163819279"></a><a name="image18707163819279"></a><span><img id="image18707163819279" src="figures/tan.png"></span></p>
</td>
</tr>
<tr id="row198937501422"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p139684341433"><a name="p139684341433"></a><a name="p139684341433"></a>teal</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p99681234164318"><a name="p99681234164318"></a><a name="p99681234164318"></a>#008080</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p12488348231"><a name="p12488348231"></a><a name="p12488348231"></a><a name="image118401947152718"></a><a name="image118401947152718"></a><span><img id="image118401947152718" src="figures/teal.png"></span></p>
</td>
</tr>
<tr id="row18931750194212"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1996812341434"><a name="p1996812341434"></a><a name="p1996812341434"></a>thistle</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p12968143410433"><a name="p12968143410433"></a><a name="p12968143410433"></a>#d8Bfd8</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p448834112316"><a name="p448834112316"></a><a name="p448834112316"></a><a name="image1684175672719"></a><a name="image1684175672719"></a><span><img id="image1684175672719" src="figures/thistle.png"></span></p>
</td>
</tr>
<tr id="row17893175024216"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p11968183410433"><a name="p11968183410433"></a><a name="p11968183410433"></a>tomato</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p17968173414430"><a name="p17968173414430"></a><a name="p17968173414430"></a>#ff6347</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1248844152318"><a name="p1248844152318"></a><a name="p1248844152318"></a><a name="image16898060283"></a><a name="image16898060283"></a><span><img id="image16898060283" src="figures/tomato.png"></span></p>
</td>
</tr>
<tr id="row489335024214"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p189689343434"><a name="p189689343434"></a><a name="p189689343434"></a>turquoise</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1396893410435"><a name="p1396893410435"></a><a name="p1396893410435"></a>#40e0d0</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1148812452317"><a name="p1148812452317"></a><a name="p1148812452317"></a><a name="image20987121510287"></a><a name="image20987121510287"></a><span><img id="image20987121510287" src="figures/turquoise.png"></span></p>
</td>
</tr>
<tr id="row158931450134218"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p6968234184311"><a name="p6968234184311"></a><a name="p6968234184311"></a>violet</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p1096817348436"><a name="p1096817348436"></a><a name="p1096817348436"></a>#ee82ee</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p174883452316"><a name="p174883452316"></a><a name="p174883452316"></a><a name="image18185102313286"></a><a name="image18185102313286"></a><span><img id="image18185102313286" src="figures/violet.png"></span></p>
</td>
</tr>
<tr id="row1989365034210"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1896818348430"><a name="p1896818348430"></a><a name="p1896818348430"></a>wheat</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p3968143424315"><a name="p3968143424315"></a><a name="p3968143424315"></a>#f5deb3</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p114881410232"><a name="p114881410232"></a><a name="p114881410232"></a><a name="image75612327286"></a><a name="image75612327286"></a><span><img id="image75612327286" src="figures/wheat.png"></span></p>
</td>
</tr>
<tr id="row289315054212"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p18968133434319"><a name="p18968133434319"></a><a name="p18968133434319"></a>white</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p19968113494316"><a name="p19968113494316"></a><a name="p19968113494316"></a>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p448814142310"><a name="p448814142310"></a><a name="p448814142310"></a><a name="image693584014283"></a><a name="image693584014283"></a><span><img id="image693584014283" src="figures/white.png"></span></p>
</td>
</tr>
<tr id="row118941550174220"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p1296818341430"><a name="p1296818341430"></a><a name="p1296818341430"></a>whitesmoke</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p13968163434317"><a name="p13968163434317"></a><a name="p13968163434317"></a>#f5f5f5</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p1648818432314"><a name="p1648818432314"></a><a name="p1648818432314"></a><a name="image486611488286"></a><a name="image486611488286"></a><span><img id="image486611488286" src="figures/whitesmoke.png"></span></p>
</td>
</tr>
<tr id="row2089415004213"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p13968163420430"><a name="p13968163420430"></a><a name="p13968163420430"></a>yellow</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p12969193454320"><a name="p12969193454320"></a><a name="p12969193454320"></a>#ffff00</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p948815452317"><a name="p948815452317"></a><a name="p948815452317"></a><a name="image038713915415"></a><a name="image038713915415"></a><span><img id="image038713915415" src="figures/yellow.png"></span></p>
</td>
</tr>
<tr id="row08941050144220"><td class="cellrowborder" valign="top" width="32.71%" headers="mcps1.2.4.1.1 "><p id="p9969834194315"><a name="p9969834194315"></a><a name="p9969834194315"></a>yellowgreen</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.4.1.2 "><p id="p8969113413438"><a name="p8969113413438"></a><a name="p8969113413438"></a>#9acd32</p>
</td>
<td class="cellrowborder" valign="top" width="30.85%" headers="mcps1.2.4.1.3 "><p id="p84885482310"><a name="p84885482310"></a><a name="p84885482310"></a><a name="image1218175915317"></a><a name="image1218175915317"></a><span><img id="image1218175915317" src="figures/yellowgreen.png"></span></p>
</td>
</tr>
</tbody>
</table>
