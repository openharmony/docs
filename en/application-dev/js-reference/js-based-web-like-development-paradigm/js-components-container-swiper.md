# swiper<a name="EN-US_TOPIC_0000001173164745"></a>

The  **<swiper\>**  component provides a container that allows users to switch among child components by swiping operations.

## Permission List<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

All child components except  **<list\>**  are supported.

## Attribute<a name="section2907183951110"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="aa872998ac2d84843a3c5161889afffef"><a name="aa872998ac2d84843a3c5161889afffef"></a><a name="aa872998ac2d84843a3c5161889afffef"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="ab2111648ee0e4f6d881be8954e7acaab"><a name="ab2111648ee0e4f6d881be8954e7acaab"></a><a name="ab2111648ee0e4f6d881be8954e7acaab"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="ab377d1c90900478ea4ecab51e9a058af"><a name="ab377d1c90900478ea4ecab51e9a058af"></a><a name="ab377d1c90900478ea4ecab51e9a058af"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="a1d574a0044ed42ec8a2603bc82734232"><a name="a1d574a0044ed42ec8a2603bc82734232"></a><a name="a1d574a0044ed42ec8a2603bc82734232"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1319425616340"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1892321283515"><a name="p1892321283515"></a><a name="p1892321283515"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p59239126351"><a name="p59239126351"></a><a name="p59239126351"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p492315120357"><a name="p492315120357"></a><a name="p492315120357"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p8923141253518"><a name="p8923141253518"></a><a name="p8923141253518"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p19923012153517"><a name="p19923012153517"></a><a name="p19923012153517"></a>Index of a child component currently displayed in the container.</p>
</td>
</tr>
<tr id="row165481652113414"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p109230127357"><a name="p109230127357"></a><a name="p109230127357"></a>autoplay </p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p6923151220359"><a name="p6923151220359"></a><a name="p6923151220359"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p39241112163515"><a name="p39241112163515"></a><a name="p39241112163515"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p19924912113514"><a name="p19924912113514"></a><a name="p19924912113514"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p192451253512"><a name="p192451253512"></a><a name="p192451253512"></a>Whether to enable autoplay for child component switching. If this attribute is <strong id="b15681104972613"><a name="b15681104972613"></a><a name="b15681104972613"></a>true</strong>, the indicator does not take effect<sup id="sup285913711416"><a name="sup285913711416"></a><a name="sup285913711416"></a>5+</sup>.</p>
</td>
</tr>
<tr id="row054835211347"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p592411211350"><a name="p592411211350"></a><a name="p592411211350"></a>interval </p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p99243129357"><a name="p99243129357"></a><a name="p99243129357"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p14924111218354"><a name="p14924111218354"></a><a name="p14924111218354"></a>3000</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p199241612143519"><a name="p199241612143519"></a><a name="p199241612143519"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p15924121219354"><a name="p15924121219354"></a><a name="p15924121219354"></a>Autoplay interval, in milliseconds, when autoplay is enabled.</p>
</td>
</tr>
<tr id="row3548452123418"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p392419124357"><a name="p392419124357"></a><a name="p392419124357"></a>indicator </p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1992419126353"><a name="p1992419126353"></a><a name="p1992419126353"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p129245120351"><a name="p129245120351"></a><a name="p129245120351"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p39241412123514"><a name="p39241412123514"></a><a name="p39241412123514"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p139247126354"><a name="p139247126354"></a><a name="p139247126354"></a>Whether to enable the indicator. The default value is <strong id="b11169818165715"><a name="b11169818165715"></a><a name="b11169818165715"></a>true</strong>.</p>
</td>
</tr>
<tr id="row2549452153416"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p11924181214359"><a name="p11924181214359"></a><a name="p11924181214359"></a>digital<sup id="sup862644131518"><a name="sup862644131518"></a><a name="sup862644131518"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p992411203518"><a name="p992411203518"></a><a name="p992411203518"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p99241312173519"><a name="p99241312173519"></a><a name="p99241312173519"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1692471216354"><a name="p1692471216354"></a><a name="p1692471216354"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p892412121355"><a name="p892412121355"></a><a name="p892412121355"></a>Whether to enable the digital indicator. The default value is <strong id="b186731053201012"><a name="b186731053201012"></a><a name="b186731053201012"></a>false</strong>.</p>
<div class="note" id="note592581253511"><a name="note592581253511"></a><a name="note592581253511"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1892581233520"><a name="p1892581233520"></a><a name="p1892581233520"></a>The digital indicator takes effect only when <strong id="b129911746141816"><a name="b129911746141816"></a><a name="b129911746141816"></a>indicator</strong> is set to <strong id="b1176765601811"><a name="b1176765601811"></a><a name="b1176765601811"></a>true</strong>.</p>
</div></div>
</td>
</tr>
<tr id="row20134846183410"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p392501293511"><a name="p392501293511"></a><a name="p392501293511"></a>indicatormask </p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p79251912133517"><a name="p79251912133517"></a><a name="p79251912133517"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1192511233517"><a name="p1192511233517"></a><a name="p1192511233517"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p12925201243510"><a name="p12925201243510"></a><a name="p12925201243510"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p12925111219353"><a name="p12925111219353"></a><a name="p12925111219353"></a>Whether to use the indicator mask. If this attribute is set to <strong id="b6349154810236"><a name="b6349154810236"></a><a name="b6349154810236"></a>true</strong>, the indicator has a gradient mask.</p>
<div class="note" id="note5256105081615"><a name="note5256105081615"></a><a name="note5256105081615"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p42561450171619"><a name="p42561450171619"></a><a name="p42561450171619"></a>This attribute does not take effect for smartphones.<sup id="sup95431732161815"><a name="sup95431732161815"></a><a name="sup95431732161815"></a>5+</sup></p>
</div></div>
</td>
</tr>
<tr id="row18467181913175"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p104671419151719"><a name="p104671419151719"></a><a name="p104671419151719"></a>indicatordisabled<sup id="sup0227116141915"><a name="sup0227116141915"></a><a name="sup0227116141915"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p64671319171712"><a name="p64671319171712"></a><a name="p64671319171712"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p20467119161717"><a name="p20467119161717"></a><a name="p20467119161717"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p11467519121712"><a name="p11467519121712"></a><a name="p11467519121712"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p12467101911179"><a name="p12467101911179"></a><a name="p12467101911179"></a>Whether gesture operations are disabled on the indicator. If this attribute is set to <strong id="b76131411183611"><a name="b76131411183611"></a><a name="b76131411183611"></a>true</strong>, the indicator does not respond to clicking or dragging operations.</p>
</td>
</tr>
<tr id="row813404683416"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p29251112133511"><a name="p29251112133511"></a><a name="p29251112133511"></a>loop</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p59251129353"><a name="p59251129353"></a><a name="p59251129353"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1492511216359"><a name="p1492511216359"></a><a name="p1492511216359"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1925191217350"><a name="p1925191217350"></a><a name="p1925191217350"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1492511233518"><a name="p1492511233518"></a><a name="p1492511233518"></a>Whether to enable looping.</p>
</td>
</tr>
<tr id="row959023815340"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p18926141243510"><a name="p18926141243510"></a><a name="p18926141243510"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1592618127351"><a name="p1592618127351"></a><a name="p1592618127351"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p49269123351"><a name="p49269123351"></a><a name="p49269123351"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p119261212183513"><a name="p119261212183513"></a><a name="p119261212183513"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p79261112123512"><a name="p79261112123512"></a><a name="p79261112123512"></a>Duration of the autoplay for child component switching.</p>
</td>
</tr>
<tr id="row448465042919"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1292671273516"><a name="p1292671273516"></a><a name="p1292671273516"></a>vertical</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p09261312133515"><a name="p09261312133515"></a><a name="p09261312133515"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p6926191283518"><a name="p6926191283518"></a><a name="p6926191283518"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p5926101223516"><a name="p5926101223516"></a><a name="p5926101223516"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p9926141215356"><a name="p9926141215356"></a><a name="p9926141215356"></a>Whether the swipe gesture is performed vertically. A vertical swipe uses the vertical indicator.</p>
</td>
</tr>
<tr id="row19614191801116"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p6615101813113"><a name="p6615101813113"></a><a name="p6615101813113"></a>cachedsize<sup id="sup116732071533"><a name="sup116732071533"></a><a name="sup116732071533"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p11615618191116"><a name="p11615618191116"></a><a name="p11615618191116"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p76150185113"><a name="p76150185113"></a><a name="p76150185113"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p6615141812113"><a name="p6615141812113"></a><a name="p6615141812113"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p161510182110"><a name="p161510182110"></a><a name="p161510182110"></a>Minimum number of cached items during delayed loading of the <strong id="b1461673213215"><a name="b1461673213215"></a><a name="b1461673213215"></a>&lt;swiper&gt;</strong> component. The value <strong id="b1622894813210"><a name="b1622894813210"></a><a name="b1622894813210"></a>-1</strong> indicates that all content is cached.</p>
</td>
</tr>
<tr id="row188171411181313"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p19817711111310"><a name="p19817711111310"></a><a name="p19817711111310"></a>scrolleffect<sup id="sup015918182539"><a name="sup015918182539"></a><a name="sup015918182539"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p58177111138"><a name="p58177111138"></a><a name="p58177111138"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p19817191116131"><a name="p19817191116131"></a><a name="p19817191116131"></a>spring</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1681791141315"><a name="p1681791141315"></a><a name="p1681791141315"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p118181116136"><a name="p118181116136"></a><a name="p118181116136"></a>Scroll effect. The options are as follows:</p>
<a name="ul5570142716148"></a><a name="ul5570142716148"></a><ul id="ul5570142716148"><li><strong id="b9832231639"><a name="b9832231639"></a><a name="b9832231639"></a>spring</strong>: Similar to the physical dynamic effect of a spring. After scrolling to the edge, you can continue to scroll for a distance based on the initial speed or by touching the knob of the scrollbar. After you release your hand, the knob is rebounded.</li><li><strong id="b1843310104318"><a name="b1843310104318"></a><a name="b1843310104318"></a>fade</strong>: Similar to the physical dynamic effect of fade. When you scroll to the edge, a wave shape fades. The fade changes according to the speed and scrolling distance.</li><li><strong id="b18395161410313"><a name="b18395161410313"></a><a name="b18395161410313"></a>none</strong>: No effect after the scroll bar is moved to the edge.<div class="note" id="note194872416715"><a name="note194872416715"></a><a name="note194872416715"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p104852416717"><a name="p104852416717"></a><a name="p104852416717"></a>This attribute is valid only when <strong id="b466318259316"><a name="b466318259316"></a><a name="b466318259316"></a>loop</strong> is set to <strong id="b99292718313"><a name="b99292718313"></a><a name="b99292718313"></a>false</strong>.</p>
</div></div>
</li></ul>
</td>
</tr>
</tbody>
</table>

## Style<a name="section08721578337"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table887265710335"></a>
<table><thead align="left"><tr id="row128728571331"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p16872857183318"><a name="p16872857183318"></a><a name="p16872857183318"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="18.938106189381063%" id="mcps1.1.6.1.2"><p id="p3872185715335"><a name="p3872185715335"></a><a name="p3872185715335"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.408959104089591%" id="mcps1.1.6.1.3"><p id="p8872115733310"><a name="p8872115733310"></a><a name="p8872115733310"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p48726579333"><a name="p48726579333"></a><a name="p48726579333"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p11872135710338"><a name="p11872135710338"></a><a name="p11872135710338"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row087215753313"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p138721657163318"><a name="p138721657163318"></a><a name="p138721657163318"></a>indicator-color</p>
</td>
<td class="cellrowborder" valign="top" width="18.938106189381063%" headers="mcps1.1.6.1.2 "><p id="p18873175711338"><a name="p18873175711338"></a><a name="p18873175711338"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.408959104089591%" headers="mcps1.1.6.1.3 "><p id="p387319579338"><a name="p387319579338"></a><a name="p387319579338"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p14873557133312"><a name="p14873557133312"></a><a name="p14873557133312"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p38731575337"><a name="p38731575337"></a><a name="p38731575337"></a>Fill color of the navigation point indicator.</p>
</td>
</tr>
<tr id="row1387305703318"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p887315773318"><a name="p887315773318"></a><a name="p887315773318"></a>indicator-selected-color </p>
</td>
<td class="cellrowborder" valign="top" width="18.938106189381063%" headers="mcps1.1.6.1.2 "><p id="p287311574339"><a name="p287311574339"></a><a name="p287311574339"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.408959104089591%" headers="mcps1.1.6.1.3 "><p id="p1873175716333"><a name="p1873175716333"></a><a name="p1873175716333"></a>#ff007dff</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p1487315715332"><a name="p1487315715332"></a><a name="p1487315715332"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p08741578331"><a name="p08741578331"></a><a name="p08741578331"></a>Color of the currently selected navigation point indicator.</p>
</td>
</tr>
<tr id="row28741757123314"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1487455763316"><a name="p1487455763316"></a><a name="p1487455763316"></a>indicator-size </p>
</td>
<td class="cellrowborder" valign="top" width="18.938106189381063%" headers="mcps1.1.6.1.2 "><p id="p687415578337"><a name="p687415578337"></a><a name="p687415578337"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.408959104089591%" headers="mcps1.1.6.1.3 "><p id="p13874957103314"><a name="p13874957103314"></a><a name="p13874957103314"></a>4px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p10874105714335"><a name="p10874105714335"></a><a name="p10874105714335"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1287415572334"><a name="p1287415572334"></a><a name="p1287415572334"></a>Diameter of the navigation point indicator.</p>
</td>
</tr>
<tr id="row38742578331"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p5874957103312"><a name="p5874957103312"></a><a name="p5874957103312"></a>indicator-top|left|right|bottom</p>
</td>
<td class="cellrowborder" valign="top" width="18.938106189381063%" headers="mcps1.1.6.1.2 "><p id="p18741457183312"><a name="p18741457183312"></a><a name="p18741457183312"></a>&lt;length&gt; | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.408959104089591%" headers="mcps1.1.6.1.3 "><p id="p148741857113313"><a name="p148741857113313"></a><a name="p148741857113313"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p188751357193317"><a name="p188751357193317"></a><a name="p188751357193317"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p28751457163310"><a name="p28751457163310"></a><a name="p28751457163310"></a>Relative position of the indicator in the swiper.</p>
</td>
</tr>
<tr id="row15827160201614"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p682740201616"><a name="p682740201616"></a><a name="p682740201616"></a>next-margin<sup id="sup363181741"><a name="sup363181741"></a><a name="sup363181741"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.938106189381063%" headers="mcps1.1.6.1.2 "><p id="p1682710012164"><a name="p1682710012164"></a><a name="p1682710012164"></a>&lt;length&gt; | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.408959104089591%" headers="mcps1.1.6.1.3 "><p id="p148271506167"><a name="p148271506167"></a><a name="p148271506167"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p11827130131611"><a name="p11827130131611"></a><a name="p11827130131611"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p082712081614"><a name="p082712081614"></a><a name="p082712081614"></a>Next margin, used to reveal a small part of the next item.</p>
</td>
</tr>
<tr id="row08411354161510"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p6842195461516"><a name="p6842195461516"></a><a name="p6842195461516"></a>previous-margin<sup id="sup43791142644"><a name="sup43791142644"></a><a name="sup43791142644"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.938106189381063%" headers="mcps1.1.6.1.2 "><p id="p188423543159"><a name="p188423543159"></a><a name="p188423543159"></a>&lt;length&gt; | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.408959104089591%" headers="mcps1.1.6.1.3 "><p id="p1584265416157"><a name="p1584265416157"></a><a name="p1584265416157"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p9842954201518"><a name="p9842954201518"></a><a name="p9842954201518"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1684225411159"><a name="p1684225411159"></a><a name="p1684225411159"></a>Previous margin, used to reveal a small part of the previous item.</p>
</td>
</tr>
</tbody>
</table>

## Event<a name="section5891352194417"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

<a name="table836435619510"></a>
<table><thead align="left"><tr id="row153658563517"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="a426b8903842d48fa8012a24ff3c997eb"><a name="a426b8903842d48fa8012a24ff3c997eb"></a><a name="a426b8903842d48fa8012a24ff3c997eb"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="a53448ba47e5e4ae9bf7774c90820e970"><a name="a53448ba47e5e4ae9bf7774c90820e970"></a><a name="a53448ba47e5e4ae9bf7774c90820e970"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="add489ff50c444f24b759162c7f4bad9a"><a name="add489ff50c444f24b759162c7f4bad9a"></a><a name="add489ff50c444f24b759162c7f4bad9a"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row135881215451"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p2030252874519"><a name="p2030252874519"></a><a name="p2030252874519"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p123024288459"><a name="p123024288459"></a><a name="p123024288459"></a>{ index: currentIndex }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p4302728104511"><a name="p4302728104511"></a><a name="p4302728104511"></a>Triggered when the index of the currently displayed component changes.</p>
</td>
</tr>
<tr id="row103876164452"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1830262817457"><a name="p1830262817457"></a><a name="p1830262817457"></a>rotation</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p1530220283457"><a name="p1530220283457"></a><a name="p1530220283457"></a>{ value: rotationValue }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p12302172834515"><a name="p12302172834515"></a><a name="p12302172834515"></a>Triggered when the crown of the wearable rotates.</p>
</td>
</tr>
<tr id="row10660153518166"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p166601635101610"><a name="p166601635101610"></a><a name="p166601635101610"></a>animationfinish<sup id="sup19967184217552"><a name="sup19967184217552"></a><a name="sup19967184217552"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p156601035201615"><a name="p156601035201615"></a><a name="p156601035201615"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p13660835101610"><a name="p13660835101610"></a><a name="p13660835101610"></a>Triggered when the animation is finished.</p>
</td>
</tr>
</tbody>
</table>

## Method<a name="section47669296127"></a>

In addition to the methods in  [Universal Methods](js-components-common-methods.md), the following events are supported.

<a name="te7404653e7d24f40acacb0305c705aa2"></a>
<table><thead align="left"><tr id="r7df84ee4172341538bc618c4345bbdfb"><th class="cellrowborder" valign="top" width="19.439999999999998%" id="mcps1.1.4.1.1"><p id="a84cfe32d70ef464c8469ce267d0d73e8"><a name="a84cfe32d70ef464c8469ce267d0d73e8"></a><a name="a84cfe32d70ef464c8469ce267d0d73e8"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="30.56%" id="mcps1.1.4.1.2"><p id="a9f4903e9b8134a1e9fadce6a61670fb8"><a name="a9f4903e9b8134a1e9fadce6a61670fb8"></a><a name="a9f4903e9b8134a1e9fadce6a61670fb8"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.4.1.3"><p id="a4c4693c36e024fb2a0cb911f30c93c56"><a name="a4c4693c36e024fb2a0cb911f30c93c56"></a><a name="a4c4693c36e024fb2a0cb911f30c93c56"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="r8554a956136c49f8a359d08629dad179"><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.1.4.1.1 "><p id="aed0f2fb3d4cd4e36a97feb6e7109d93e"><a name="aed0f2fb3d4cd4e36a97feb6e7109d93e"></a><a name="aed0f2fb3d4cd4e36a97feb6e7109d93e"></a>swipeTo</p>
</td>
<td class="cellrowborder" valign="top" width="30.56%" headers="mcps1.1.4.1.2 "><p id="a455221cd9db84f4e8e07d33556a6cc21"><a name="a455221cd9db84f4e8e07d33556a6cc21"></a><a name="a455221cd9db84f4e8e07d33556a6cc21"></a>{ index: number(specified position) }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="a446f14fd895449f68d98b2a7e1c4bd04"><a name="a446f14fd895449f68d98b2a7e1c4bd04"></a><a name="a446f14fd895449f68d98b2a7e1c4bd04"></a>Scrolls the child component to the position at the specified index.</p>
</td>
</tr>
<tr id="row47605285519"><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.1.4.1.1 "><p id="p37655213550"><a name="p37655213550"></a><a name="p37655213550"></a>showNext</p>
</td>
<td class="cellrowborder" valign="top" width="30.56%" headers="mcps1.1.4.1.2 "><p id="p117613529552"><a name="p117613529552"></a><a name="p117613529552"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="p47675220555"><a name="p47675220555"></a><a name="p47675220555"></a>Shows the next child component.</p>
</td>
</tr>
<tr id="row5694155435516"><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.1.4.1.1 "><p id="p3694185420554"><a name="p3694185420554"></a><a name="p3694185420554"></a>showPrevious</p>
</td>
<td class="cellrowborder" valign="top" width="30.56%" headers="mcps1.1.4.1.2 "><p id="p369455411559"><a name="p369455411559"></a><a name="p369455411559"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="p2694135412552"><a name="p2694135412552"></a><a name="p2694135412552"></a>Shows the previous child component.</p>
</td>
</tr>
</tbody>
</table>

## Example Code<a name="section1933534232313"></a>

```
<!-- xxx.hml -->
<div class="container">
  <swiper class="swiper" id="swiper" index="0" indicator="true" loop="true" digital="false" cachedsize="-1"
    scrolleffect="spring">
    <div class = "swiperContent1" >
      <text class = "text">First screen</text>
    </div>
    <div class = "swiperContent2">
      <text class = "text">Second screen</text>
    </div>
    <div class = "swiperContent3">
      <text class = "text">Third screen</text>
    </div>
  </swiper>
  <input class="button" type="button" value="swipeTo" onclick="swipeTo"></input>
  <input class="button" type="button" value="showNext" onclick="showNext"></input>
  <input class="button" type="button" value="showPrevious" onclick="showPrevious"></input>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  width: 100%;
  height: 100%;
  align-items: center;
}
.swiper {
  flex-direction: column;
  align-content: center;
  align-items: center;
  width: 70%;
  height: 130px;
  border: 1px solid #000000;
  indicator-color: #cf2411;
  indicator-size: 14px;
  indicator-bottom: 20px;
  indicator-right: 30px;
  margin-top: 100px;
  next-margin:20px;
  previous-margin:20px;
}
.swiperContent1{
  height: 100%;
  justify-content: center;
  background-color: #007dff;
}
.swiperContent2{
  height: 100%;
  justify-content: center;
  background-color: #ff7500;
}
.swiperContent3{
  height: 100%;
  justify-content: center;
  background-color: #41ba41;
}
.button {
  width: 70%;
  margin: 10px;
}
.text {
  font-size: 40px;
}
```

```
// xxx.js
export default {
  swipeTo() {
    this.$element('swiper').swipeTo({index: 2});
  },
  showNext() {
    this.$element('swiper').showNext();
  },
  showPrevious() {
    this.$element('swiper').showPrevious();
  }
}
```

![](figures/4-31.gif)

