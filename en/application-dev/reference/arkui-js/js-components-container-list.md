# list<a name="EN-US_TOPIC_0000001127284836"></a>

The  **<list\>**  component provides a list container that presents a series of list items arranged in a column with the same width. Lists support presentations of the same data in a multiple and coherent row style, for example, images and texts.

## Required Permissions<a name="section11257113618419"></a>

N/A

## Child Components<a name="section9288143101012"></a>

<[list-item](js-components-container-list-item-group.md)\> and <[list-item-group](js-components-container-list-item.md)\>

## Attributes<a name="section2907183951110"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"><a name="en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a><a name="en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"><a name="en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a><a name="en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"><a name="en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a><a name="en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"><a name="en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a><a name="en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row389219166580"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p32747328584"><a name="p32747328584"></a><a name="p32747328584"></a>scrollpage</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1927413328589"><a name="p1927413328589"></a><a name="p1927413328589"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p142747324586"><a name="p142747324586"></a><a name="p142747324586"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1827423217589"><a name="p1827423217589"></a><a name="p1827423217589"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p627473213585"><a name="p627473213585"></a><a name="p627473213585"></a>Whether to scroll the non-list part on the top of the list page out of the visible area with the list. The value can be <strong id="b1827263010156"><a name="b1827263010156"></a><a name="b1827263010156"></a>true</strong> (scrolls the non-list part out) or <strong id="b1020123281511"><a name="b1020123281511"></a><a name="b1020123281511"></a>false</strong> (does not scroll the non-list part out). This attribute is not available when the direction is <strong id="b661941418162"><a name="b661941418162"></a><a name="b661941418162"></a>row</strong>.</p>
</td>
</tr>
<tr id="row9893216145818"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p112749323589"><a name="p112749323589"></a><a name="p112749323589"></a>cachedcount</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1427483225810"><a name="p1427483225810"></a><a name="p1427483225810"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p16274432145815"><a name="p16274432145815"></a><a name="p16274432145815"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p32741132185811"><a name="p32741132185811"></a><a name="p32741132185811"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p02741932195811"><a name="p02741932195811"></a><a name="p02741932195811"></a>Minimum number of cached list items when the long list is loaded with delay.</p>
<p id="p182741432115814"><a name="p182741432115814"></a><a name="p182741432115814"></a>When the number of list items cached outside the visible area is less than the value of this attribute, a <strong id="b34911451101"><a name="b34911451101"></a><a name="b34911451101"></a>requestitem</strong> event is triggered.</p>
</td>
</tr>
<tr id="row9893131620589"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p827410325586"><a name="p827410325586"></a><a name="p827410325586"></a>scrollbar</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p72741332125816"><a name="p72741332125816"></a><a name="p72741332125816"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p122741532125818"><a name="p122741532125818"></a><a name="p122741532125818"></a>off</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1227413295813"><a name="p1227413295813"></a><a name="p1227413295813"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p142744322587"><a name="p142744322587"></a><a name="p142744322587"></a>Display mode of the side scrollbar. (Currently, only the vertical scrollbar is supported.)</p>
<a name="ul162752325582"></a><a name="ul162752325582"></a><ul id="ul162752325582"><li><strong id="b067574210418"><a name="b067574210418"></a><a name="b067574210418"></a>off</strong>: No display</li><li><strong id="b694151664211"><a name="b694151664211"></a><a name="b694151664211"></a>auto</strong>: Displayed on demand (The side scrollbar is displayed when touched and disappears 2s later.)</li><li><strong id="b19479834154210"><a name="b19479834154210"></a><a name="b19479834154210"></a>on</strong>: Always displayed</li></ul>
</td>
</tr>
<tr id="row1089321620582"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1275832125813"><a name="p1275832125813"></a><a name="p1275832125813"></a>scrolleffect</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p7275193216582"><a name="p7275193216582"></a><a name="p7275193216582"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p13275232125815"><a name="p13275232125815"></a><a name="p13275232125815"></a>spring</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p327520323585"><a name="p327520323585"></a><a name="p327520323585"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1827516324585"><a name="p1827516324585"></a><a name="p1827516324585"></a>Scroll effect. Available values are as follows:</p>
<a name="ul13275532195819"></a><a name="ul13275532195819"></a><ul id="ul13275532195819"><li><strong id="b687114363370"><a name="b687114363370"></a><a name="b687114363370"></a>spring</strong>: Similar to the physical dynamic effect of a spring. After scrolling to the edge, you can continue to scroll for a distance based on the initial speed or by touching the knob of the scrollbar. After you release your hand, the knob is rebounded.</li><li><strong id="b767535112394"><a name="b767535112394"></a><a name="b767535112394"></a>fade</strong>: Similar to the physical dynamic effect of fade. When you scroll to the edge, a wave shape fades. The fade changes according to the speed and scrolling distance.</li><li><strong id="b136381350114118"><a name="b136381350114118"></a><a name="b136381350114118"></a>no</strong>: No effect after the scrollbar is moved to the edge.</li></ul>
</td>
</tr>
<tr id="row208941516165811"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1327573215812"><a name="p1327573215812"></a><a name="p1327573215812"></a>indexer</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p15275163245815"><a name="p15275163245815"></a><a name="p15275163245815"></a>boolean | Array&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p427553220580"><a name="p427553220580"></a><a name="p427553220580"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p627613214585"><a name="p627613214585"></a><a name="p627613214585"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1127613275818"><a name="p1127613275818"></a><a name="p1127613275818"></a>Whether to display the alphabetical index bar on the sidebar. If this attribute is set to <strong id="b1035315299257"><a name="b1035315299257"></a><a name="b1035315299257"></a>true</strong> or a customized indexer, the index bar is displayed at the right boundary of the list. Example:</p>
<p id="p19276132105811"><a name="p19276132105811"></a><a name="p19276132105811"></a><strong id="b119841862711"><a name="b119841862711"></a><a name="b119841862711"></a>"indexer" : "true"</strong> indicates the default alphabetical indexer.</p>
<p id="p10276133295813"><a name="p10276133295813"></a><a name="p10276133295813"></a><strong id="b158642216272"><a name="b158642216272"></a><a name="b158642216272"></a>"indexer" : "false"</strong> indicates no indexer.</p>
<p id="p1027643295815"><a name="p1027643295815"></a><a name="p1027643295815"></a>"indexer": ['#', '1', '2', '3', '4', '5', '6', '7', '8'] indicates a customized index. You must include <strong id="b095305716565"><a name="b095305716565"></a><a name="b095305716565"></a>"#"</strong> when using a customized indexer.</p>
<div class="note" id="note1752771418501"><a name="note1752771418501"></a><a name="note1752771418501"></a><span class="notetitle"> NOTE: </span><div class="notebody"><a name="ul55231518155017"></a><a name="ul55231518155017"></a><ul id="ul55231518155017"><li>This attribute is valid only when <strong id="b15581134072810"><a name="b15581134072810"></a><a name="b15581134072810"></a>flex-direction</strong> is set to <strong id="b13563344132812"><a name="b13563344132812"></a><a name="b13563344132812"></a>column</strong> and <strong id="b1047494711284"><a name="b1047494711284"></a><a name="b1047494711284"></a>columns</strong> is set to <strong id="b2312249162819"><a name="b2312249162819"></a><a name="b2312249162819"></a>1</strong>.</li><li>This attribute must be used together with the <a href="js-components-container-list-item.md#section2907183951110">section</a> attribute of <strong id="b562515564293"><a name="b562515564293"></a><a name="b562515564293"></a>&lt;list-item&gt;</strong>.</li></ul>
</div></div>
</td>
</tr>
<tr id="row1981645163320"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p105121047125317"><a name="p105121047125317"></a><a name="p105121047125317"></a>indexercircle<sup id="sup43038121535"><a name="sup43038121535"></a><a name="sup43038121535"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p8512114712538"><a name="p8512114712538"></a><a name="p8512114712538"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p551317471531"><a name="p551317471531"></a><a name="p551317471531"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p4513547195316"><a name="p4513547195316"></a><a name="p4513547195316"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1898916471451"><a name="p1898916471451"></a><a name="p1898916471451"></a>Whether to use a circle indexer.</p>
<p id="p10513447125316"><a name="p10513447125316"></a><a name="p10513447125316"></a>The default value is <strong id="b337272111448"><a name="b337272111448"></a><a name="b337272111448"></a>true</strong> for wearables and <strong id="b83154814105"><a name="b83154814105"></a><a name="b83154814105"></a>false</strong> for other device types. This attribute is invalid if <strong id="b155631448185810"><a name="b155631448185810"></a><a name="b155631448185810"></a>indexer</strong> is set to <strong id="b115688487588"><a name="b115688487588"></a><a name="b115688487588"></a>false</strong>.</p>
</td>
</tr>
<tr id="row1926180153418"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1370619211500"><a name="p1370619211500"></a><a name="p1370619211500"></a>indexermulti<sup id="sup1478641710316"><a name="sup1478641710316"></a><a name="sup1478641710316"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p13706112125019"><a name="p13706112125019"></a><a name="p13706112125019"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1770622195017"><a name="p1770622195017"></a><a name="p1770622195017"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p97060218503"><a name="p97060218503"></a><a name="p97060218503"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1768357350"><a name="p1768357350"></a><a name="p1768357350"></a>Whether to use a multi-language indexer.</p>
<p id="p57061219500"><a name="p57061219500"></a><a name="p57061219500"></a>This attribute is invalid if <strong id="b18235164351416"><a name="b18235164351416"></a><a name="b18235164351416"></a>indexer</strong> is set to <strong id="b223554316147"><a name="b223554316147"></a><a name="b223554316147"></a>false</strong>.</p>
</td>
</tr>
<tr id="row289205623319"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p336515269516"><a name="p336515269516"></a><a name="p336515269516"></a>indexerbubble<sup id="sup3412121919314"><a name="sup3412121919314"></a><a name="sup3412121919314"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p836613263515"><a name="p836613263515"></a><a name="p836613263515"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p153661126165120"><a name="p153661126165120"></a><a name="p153661126165120"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p0366182611512"><a name="p0366182611512"></a><a name="p0366182611512"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p15708185468"><a name="p15708185468"></a><a name="p15708185468"></a>Whether to display the bubble effect when switching among indexes.</p>
<p id="p12366132614518"><a name="p12366132614518"></a><a name="p12366132614518"></a>This attribute is invalid if <strong id="b3399153701610"><a name="b3399153701610"></a><a name="b3399153701610"></a>indexer</strong> is set to <strong id="b14404237151617"><a name="b14404237151617"></a><a name="b14404237151617"></a>false</strong>.</p>
</td>
</tr>
<tr id="row19197115453311"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p191412818511"><a name="p191412818511"></a><a name="p191412818511"></a>divider<sup id="sup918814291347"><a name="sup918814291347"></a><a name="sup918814291347"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p3914284516"><a name="p3914284516"></a><a name="p3914284516"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p10914285514"><a name="p10914285514"></a><a name="p10914285514"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p8914148051"><a name="p8914148051"></a><a name="p8914148051"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p111882182061"><a name="p111882182061"></a><a name="p111882182061"></a>Whether list items are separated by dividers.</p>
<p id="p20914284518"><a name="p20914284518"></a><a name="p20914284518"></a>For details about divider styles, see <strong id="b1680911361100"><a name="b1680911361100"></a><a name="b1680911361100"></a>divider-color</strong>, <strong id="b270113916020"><a name="b270113916020"></a><a name="b270113916020"></a>divider-height</strong>, <strong id="b312394211012"><a name="b312394211012"></a><a name="b312394211012"></a>divider-length</strong>, and <strong id="b17431644908"><a name="b17431644908"></a><a name="b17431644908"></a>divider-origin</strong> in the <a href="../../nottoctopics/en-us_topic_0000001131154746.md#section1071433432218">Styles</a> table.</p>
</td>
</tr>
<tr id="row311191013583"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p9276123217583"><a name="p9276123217583"></a><a name="p9276123217583"></a>shapemode</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1527610320588"><a name="p1527610320588"></a><a name="p1527610320588"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p17276832195815"><a name="p17276832195815"></a><a name="p17276832195815"></a>default</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p142761532145817"><a name="p142761532145817"></a><a name="p142761532145817"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p182761532205818"><a name="p182761532205818"></a><a name="p182761532205818"></a>Shape of the side scrollbar.</p>
<a name="ul4276203212589"></a><a name="ul4276203212589"></a><ul id="ul4276203212589"><li><strong id="b1694164924312"><a name="b1694164924312"></a><a name="b1694164924312"></a>default</strong>: not specified (following the theme)</li><li><strong id="b4888059134313"><a name="b4888059134313"></a><a name="b4888059134313"></a>rect</strong>: rectangle</li><li><strong id="b631715664410"><a name="b631715664410"></a><a name="b631715664410"></a>round</strong>: circle</li></ul>
</td>
</tr>
<tr id="row1465212481574"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p102776324585"><a name="p102776324585"></a><a name="p102776324585"></a>updateeffect</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p4277133275818"><a name="p4277133275818"></a><a name="p4277133275818"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p627763235813"><a name="p627763235813"></a><a name="p627763235813"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1927893215584"><a name="p1927893215584"></a><a name="p1927893215584"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p3278032145815"><a name="p3278032145815"></a><a name="p3278032145815"></a>Whether a dynamic effect is displayed when an item in the list is deleted or added.</p>
<a name="ul8278153205815"></a><a name="ul8278153205815"></a><ul id="ul8278153205815"><li><strong id="b1406192914574"><a name="b1406192914574"></a><a name="b1406192914574"></a>false</strong>: No dynamic effect is displayed.</li><li><strong id="b139515324582"><a name="b139515324582"></a><a name="b139515324582"></a>true</strong>: A dynamic effect is displayed when an item is added or deleted.</li></ul>
</td>
</tr>
<tr id="row1788316557427"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p198831055124217"><a name="p198831055124217"></a><a name="p198831055124217"></a>chainanimation<sup id="sup13376443103416"><a name="sup13376443103416"></a><a name="sup13376443103416"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p0883955174217"><a name="p0883955174217"></a><a name="p0883955174217"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p888305574219"><a name="p888305574219"></a><a name="p888305574219"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p19884755204213"><a name="p19884755204213"></a><a name="p19884755204213"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p78841255154210"><a name="p78841255154210"></a><a name="p78841255154210"></a>Whether to display chained animations on this list when it slides or its top and bottom are dragged. The list items are separated with even space, and one item animation starts after the previous animation during basic sliding interactions. The chained animation effect is similar with spring physics.</p>
<a name="ul1490293714519"></a><a name="ul1490293714519"></a><ul id="ul1490293714519"><li><strong id="b19321195416183"><a name="b19321195416183"></a><a name="b19321195416183"></a>false</strong>: Chained animations are displayed.</li><li><strong id="b1493073215190"><a name="b1493073215190"></a><a name="b1493073215190"></a>true</strong>: No chained animation is displayed.<div class="note" id="note775214910343"><a name="note775214910343"></a><a name="note775214910343"></a><span class="notetitle"> NOTE: </span><div class="notebody"><a name="ul99031432111819"></a><a name="ul99031432111819"></a><ul id="ul99031432111819"><li>Dynamic modification is not supported.</li><li>This attribute does not take effect if an indexer is used.</li><li>If this attribute is <strong id="b93341294243"><a name="b93341294243"></a><a name="b93341294243"></a>true</strong>, the <strong id="b123631857114410"><a name="b123631857114410"></a><a name="b123631857114410"></a>sticky</strong> attributes set for <strong id="b17762181514469"><a name="b17762181514469"></a><a name="b17762181514469"></a>&lt;list-item&gt;</strong> components do not take effect.</li></ul>
</div></div>
</li></ul>
</td>
</tr>
<tr id="row114931435579"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p2278932185814"><a name="p2278932185814"></a><a name="p2278932185814"></a>initialindex</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p627818324584"><a name="p627818324584"></a><a name="p627818324584"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p142783321586"><a name="p142783321586"></a><a name="p142783321586"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p20278123225811"><a name="p20278123225811"></a><a name="p20278123225811"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p19236720152515"><a name="p19236720152515"></a><a name="p19236720152515"></a>Item to be displayed at the start position of the viewport when the current list is loaded for the first time. The default value is <strong id="b1823682018251"><a name="b1823682018251"></a><a name="b1823682018251"></a>0</strong>, indicating that the first item is displayed.</p>
<p id="p16604922152515"><a name="p16604922152515"></a><a name="p16604922152515"></a>The setting does not take effect in any of the following cases:</p>
<a name="ul920222662516"></a><a name="ul920222662516"></a><ul id="ul920222662516"><li>The value you set is greater than the index of the last item.</li><li>The <strong id="b39045241265"><a name="b39045241265"></a><a name="b39045241265"></a>initialoffset</strong> attribute is set.</li><li><strong id="b102021626202510"><a name="b102021626202510"></a><a name="b102021626202510"></a>indexer</strong> or <strong id="b1420282652515"><a name="b1420282652515"></a><a name="b1420282652515"></a>scrollpage</strong> is set to <strong id="b192021826132518"><a name="b192021826132518"></a><a name="b192021826132518"></a>true</strong>.</li></ul>
</td>
</tr>
<tr id="row950539135714"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p827963212580"><a name="p827963212580"></a><a name="p827963212580"></a>initialoffset</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p227917321582"><a name="p227917321582"></a><a name="p227917321582"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p62791332105814"><a name="p62791332105814"></a><a name="p62791332105814"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1527943212583"><a name="p1527943212583"></a><a name="p1527943212583"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p327920329582"><a name="p327920329582"></a><a name="p327920329582"></a>Start offset of the viewport when the current list is loaded for the first time. The offset must not exceed the scrolling range of the current list. If exceeded, the offset is truncated to the maximum value of the scrolling range. This attribute does not take effect if <strong id="b519019121326"><a name="b519019121326"></a><a name="b519019121326"></a>indexer</strong> or <strong id="b519531213210"><a name="b519531213210"></a><a name="b519531213210"></a>scrollpage</strong> is set to <strong id="b121953129219"><a name="b121953129219"></a><a name="b121953129219"></a>true</strong>.</p>
</td>
</tr>
<tr id="row1914605315918"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p19147135375914"><a name="p19147135375914"></a><a name="p19147135375914"></a>selected<sup id="sup2083525912347"><a name="sup2083525912347"></a><a name="sup2083525912347"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p12147105375915"><a name="p12147105375915"></a><a name="p12147105375915"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p161471753195920"><a name="p161471753195920"></a><a name="p161471753195920"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p314745313591"><a name="p314745313591"></a><a name="p314745313591"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p11147853145914"><a name="p11147853145914"></a><a name="p11147853145914"></a>Selected item in the current list. The value can be a <strong id="b19508174512249"><a name="b19508174512249"></a><a name="b19508174512249"></a>section</strong> value of any list items.</p>
</td>
</tr>
</tbody>
</table>

## Styles<a name="section5775351116"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table1744514388541"></a>
<table><thead align="left"><tr id="row1244614388545"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="ae8fba6e2bad749f49d7af2927756ecac"><a name="ae8fba6e2bad749f49d7af2927756ecac"></a><a name="ae8fba6e2bad749f49d7af2927756ecac"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="a4543b5564fb34df0b7d83c5640a46890"><a name="a4543b5564fb34df0b7d83c5640a46890"></a><a name="a4543b5564fb34df0b7d83c5640a46890"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="a779ef1afb2d74c0fac0e8014dd85e120"><a name="a779ef1afb2d74c0fac0e8014dd85e120"></a><a name="a779ef1afb2d74c0fac0e8014dd85e120"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p117421754619"><a name="p117421754619"></a><a name="p117421754619"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="aaed5c586aaf5480c8db9e53a6a22428c"><a name="aaed5c586aaf5480c8db9e53a6a22428c"></a><a name="aaed5c586aaf5480c8db9e53a6a22428c"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row194212174919"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p199724441985"><a name="p199724441985"></a><a name="p199724441985"></a>divider-color<sup id="sup3982558172012"><a name="sup3982558172012"></a><a name="sup3982558172012"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p097214420817"><a name="p097214420817"></a><a name="p097214420817"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p2097211443820"><a name="p2097211443820"></a><a name="p2097211443820"></a>transparent</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p11972204415818"><a name="p11972204415818"></a><a name="p11972204415818"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1397215441382"><a name="p1397215441382"></a><a name="p1397215441382"></a>Item divider color. This style is valid only when the <strong id="b1297030161517"><a name="b1297030161517"></a><a name="b1297030161517"></a>divider</strong> attribute of <strong id="b5742145113148"><a name="b5742145113148"></a><a name="b5742145113148"></a>&lt;list&gt;</strong> is set to <strong id="b1358345714144"><a name="b1358345714144"></a><a name="b1358345714144"></a>true</strong>.</p>
</td>
</tr>
<tr id="row391641412910"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1098356680"><a name="p1098356680"></a><a name="p1098356680"></a>divider-height<sup id="sup19987635215"><a name="sup19987635215"></a><a name="sup19987635215"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p149835619814"><a name="p149835619814"></a><a name="p149835619814"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1498145614817"><a name="p1498145614817"></a><a name="p1498145614817"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p29815567820"><a name="p29815567820"></a><a name="p29815567820"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p10983561383"><a name="p10983561383"></a><a name="p10983561383"></a>Item divider height. This style is valid only when the <strong id="b11937127141512"><a name="b11937127141512"></a><a name="b11937127141512"></a>divider</strong> attribute of <strong id="b189375713157"><a name="b189375713157"></a><a name="b189375713157"></a>&lt;list&gt;</strong> is set to <strong id="b69387717151"><a name="b69387717151"></a><a name="b69387717151"></a>true</strong>.</p>
</td>
</tr>
<tr id="row28222110920"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1144015414911"><a name="p1144015414911"></a><a name="p1144015414911"></a>divider-length<sup id="sup5326118102117"><a name="sup5326118102117"></a><a name="sup5326118102117"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p3440174196"><a name="p3440174196"></a><a name="p3440174196"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p0440741193"><a name="p0440741193"></a><a name="p0440741193"></a>The main axis width</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p15440541997"><a name="p15440541997"></a><a name="p15440541997"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p10440341697"><a name="p10440341697"></a><a name="p10440341697"></a>Item divider length. If this style is not set, the maximum length is the width of the main axis, and the actual length depends on the <strong id="b11621155518258"><a name="b11621155518258"></a><a name="b11621155518258"></a>divider-origin</strong> parameter. This style is valid only when the <strong id="b68621714152610"><a name="b68621714152610"></a><a name="b68621714152610"></a>divider</strong> attribute of <strong id="b189911656201616"><a name="b189911656201616"></a><a name="b189911656201616"></a>&lt;list&gt;</strong> is set to <strong id="b1040015185263"><a name="b1040015185263"></a><a name="b1040015185263"></a>true</strong>.</p>
</td>
</tr>
<tr id="row46441281390"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1223216191395"><a name="p1223216191395"></a><a name="p1223216191395"></a>divider-origin<sup id="sup18714913122119"><a name="sup18714913122119"></a><a name="sup18714913122119"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p1232161919915"><a name="p1232161919915"></a><a name="p1232161919915"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p723231910913"><a name="p723231910913"></a><a name="p723231910913"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p3232141916912"><a name="p3232141916912"></a><a name="p3232141916912"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p42327191895"><a name="p42327191895"></a><a name="p42327191895"></a>Item divider offset relative to the start point of the main axis. This style is valid only when the <strong id="b194511311204618"><a name="b194511311204618"></a><a name="b194511311204618"></a>divider</strong> attribute of <strong id="b16151347170"><a name="b16151347170"></a><a name="b16151347170"></a>&lt;list&gt;</strong> is set to <strong id="b13844149467"><a name="b13844149467"></a><a name="b13844149467"></a>true</strong>.</p>
</td>
</tr>
<tr id="row39106404819"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p11283866482"><a name="p11283866482"></a><a name="p11283866482"></a>flex-direction</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p7283162488"><a name="p7283162488"></a><a name="p7283162488"></a>string</p>
<p id="p182831368480"><a name="p182831368480"></a><a name="p182831368480"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p0283762488"><a name="p0283762488"></a><a name="p0283762488"></a>column</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p172837614485"><a name="p172837614485"></a><a name="p172837614485"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p172837654814"><a name="p172837654814"></a><a name="p172837654814"></a>Main axis direction of the flex container. It specifies how items are placed in the flex container.</p>
<a name="ul132831763482"></a><a name="ul132831763482"></a><ul id="ul132831763482"><li><strong id="b195531457856"><a name="b195531457856"></a><a name="b195531457856"></a>column</strong>: The y-axis is the maim axis.</li><li><strong id="b1454210619720"><a name="b1454210619720"></a><a name="b1454210619720"></a>row</strong>: The x-axis is the main axis.</li></ul>
<p id="p132831263486"><a name="p132831263486"></a><a name="p132831263486"></a>For the <strong id="b587519315312"><a name="b587519315312"></a><a name="b587519315312"></a>&lt;list&gt;</strong> component, the default value is <strong id="b2766193510313"><a name="b2766193510313"></a><a name="b2766193510313"></a>column</strong>. For other components, the default value is <strong id="b1853133913313"><a name="b1853133913313"></a><a name="b1853133913313"></a>row</strong>. </p>
</td>
</tr>
<tr id="row114441253204717"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p192847684817"><a name="p192847684817"></a><a name="p192847684817"></a>columns</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p92848613481"><a name="p92848613481"></a><a name="p92848613481"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1928410616485"><a name="p1928410616485"></a><a name="p1928410616485"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p192844611485"><a name="p192844611485"></a><a name="p192844611485"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1928418624820"><a name="p1928418624820"></a><a name="p1928418624820"></a>Number of columns displayed in the cross axis direction of the list. The default value is <strong id="b106911824153820"><a name="b106911824153820"></a><a name="b106911824153820"></a>1</strong>.</p>
<div class="note" id="note87762014175811"><a name="note87762014175811"></a><a name="note87762014175811"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p157761214205810"><a name="p157761214205810"></a><a name="p157761214205810"></a>When multiple columns are set, the columns are evenly distributed on the cross axis of the <strong id="b20419145511271"><a name="b20419145511271"></a><a name="b20419145511271"></a>&lt;list&gt;</strong> component. The size of each column is the same.</p>
</div></div>
</td>
</tr>
<tr id="row2220195185518"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p12617942184311"><a name="p12617942184311"></a><a name="p12617942184311"></a>align-items</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p15617194264312"><a name="p15617194264312"></a><a name="p15617194264312"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p061744213433"><a name="p061744213433"></a><a name="p061744213433"></a>stretch</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p12617154214437"><a name="p12617154214437"></a><a name="p12617154214437"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p9617542124318"><a name="p9617542124318"></a><a name="p9617542124318"></a>Alignment of items in each column on the cross axis. Available values are as follows:</p>
<a name="ul166171442134312"></a><a name="ul166171442134312"></a><ul id="ul166171442134312"><li><strong id="b162552382282"><a name="b162552382282"></a><a name="b162552382282"></a>stretch</strong>: Items are stretched to the same height or width as the container in the cross axis direction. </li><li><strong id="b534154612815"><a name="b534154612815"></a><a name="b534154612815"></a>flex-start</strong>: Items are aligned to the start of the cross axis.</li><li><strong id="b12116104832812"><a name="b12116104832812"></a><a name="b12116104832812"></a>flex-end</strong>: Items are aligned to the end of the cross axis.</li><li><strong id="b16621855132813"><a name="b16621855132813"></a><a name="b16621855132813"></a>center</strong>: Items are aligned in the middle of the cross axis.<div class="note" id="note10891229703"><a name="note10891229703"></a><a name="note10891229703"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p18891029105"><a name="p18891029105"></a><a name="p18891029105"></a>This style takes effect only on items of each column. Columns are evenly distributed.</p>
</div></div>
</li></ul>
</td>
</tr>
<tr id="row487325034719"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p2028420617487"><a name="p2028420617487"></a><a name="p2028420617487"></a>item-extent</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p828496164810"><a name="p828496164810"></a><a name="p828496164810"></a>&lt;length&gt; | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p928413644818"><a name="p928413644818"></a><a name="p928413644818"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p2028416134815"><a name="p2028416134815"></a><a name="p2028416134815"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p18284660488"><a name="p18284660488"></a><a name="p18284660488"></a>Size of an internal item. When a percentage is set, the value indicates the percentage of the length in the main axis direction relative to the list viewpoint.</p>
</td>
</tr>
<tr id="row99041447114713"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p172840624815"><a name="p172840624815"></a><a name="p172840624815"></a>fade-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p132851863484"><a name="p132851863484"></a><a name="p132851863484"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1728506174819"><a name="p1728506174819"></a><a name="p1728506174819"></a>grey</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p22852060481"><a name="p22852060481"></a><a name="p22852060481"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p428518694818"><a name="p428518694818"></a><a name="p428518694818"></a>Color of the physical dynamic effect. This attribute is valid only when <strong id="b1640719118429"><a name="b1640719118429"></a><a name="b1640719118429"></a>scrolleffect</strong> is set to <strong id="b1941331114423"><a name="b1941331114423"></a><a name="b1941331114423"></a>fade</strong>.</p>
</td>
</tr>
<tr id="row023410442716"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p829911534213"><a name="p829911534213"></a><a name="p829911534213"></a>scrollbar-color<sup id="sup843916381239"><a name="sup843916381239"></a><a name="sup843916381239"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p122991553112113"><a name="p122991553112113"></a><a name="p122991553112113"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p17299253132120"><a name="p17299253132120"></a><a name="p17299253132120"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p9299135342110"><a name="p9299135342110"></a><a name="p9299135342110"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p14300165317215"><a name="p14300165317215"></a><a name="p14300165317215"></a>Color of the scrollbar.</p>
</td>
</tr>
<tr id="row1117810274"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1433575912212"><a name="p1433575912212"></a><a name="p1433575912212"></a>scrollbar-width<sup id="sup10700174022317"><a name="sup10700174022317"></a><a name="sup10700174022317"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p3335165919217"><a name="p3335165919217"></a><a name="p3335165919217"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p6335175914219"><a name="p6335175914219"></a><a name="p6335175914219"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p13335759172115"><a name="p13335759172115"></a><a name="p13335759172115"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p533510595217"><a name="p533510595217"></a><a name="p533510595217"></a>Width of the scrollbar.</p>
</td>
</tr>
<tr id="row11452128142314"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p99726914238"><a name="p99726914238"></a><a name="p99726914238"></a>scrollbar-offset<sup id="sup697216902311"><a name="sup697216902311"></a><a name="sup697216902311"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p119725918233"><a name="p119725918233"></a><a name="p119725918233"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p79725972313"><a name="p79725972313"></a><a name="p79725972313"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p1297210918239"><a name="p1297210918239"></a><a name="p1297210918239"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p17972694239"><a name="p17972694239"></a><a name="p17972694239"></a>Offset between the scrollbar and the default position of the list. The value must be a positive number. The default position is on the right edge of the list. You can adjust the horizontal position of the scrollbar by setting this offset. If the scrollbar is drawn outside the list and the parent component of the list is capable of cropping, the scrollbar will be cropped.</p>
</td>
</tr>
</tbody>
</table>

## Events<a name="section471854810515"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

<a name="table12718648205119"></a>
<table><thead align="left"><tr id="row17185480518"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="p14718114825114"><a name="p14718114825114"></a><a name="p14718114825114"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="p137181948105111"><a name="p137181948105111"></a><a name="p137181948105111"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="p18718164812518"><a name="p18718164812518"></a><a name="p18718164812518"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row0718194813519"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p971894825110"><a name="p971894825110"></a><a name="p971894825110"></a>indexerchange<sup id="sup27189486514"><a name="sup27189486514"></a><a name="sup27189486514"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p197191148155114"><a name="p197191148155114"></a><a name="p197191148155114"></a>{ local: booleanValue }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1871920489510"><a name="p1871920489510"></a><a name="p1871920489510"></a>Triggered when the indexer switches between local and alphabetic indexers. This parameter takes effect only when both <strong id="b16937844815"><a name="b16937844815"></a><a name="b16937844815"></a>indexer</strong> and <strong id="b239116138814"><a name="b239116138814"></a><a name="b239116138814"></a>indexermulti</strong> are set to <strong id="b14371161515817"><a name="b14371161515817"></a><a name="b14371161515817"></a>true</strong>. The value of <strong id="b122409572813"><a name="b122409572813"></a><a name="b122409572813"></a>booleanValue</strong> can be:</p>
<a name="ul18719104820516"></a><a name="ul18719104820516"></a><ul id="ul18719104820516"><li><strong id="b6542135618131"><a name="b6542135618131"></a><a name="b6542135618131"></a>true</strong>: The local index is displayed.</li><li><strong id="b17362155812135"><a name="b17362155812135"></a><a name="b17362155812135"></a>false</strong>: The alphabetic index is displayed.</li></ul>
</td>
</tr>
<tr id="row4719114805113"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p157191048155110"><a name="p157191048155110"></a><a name="p157191048155110"></a>scroll</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p177191548175111"><a name="p177191548175111"></a><a name="p177191548175111"></a>{ scrollX: scrollXValue, scrollY: scrollYValue, scrollState: stateValue }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1571914895114"><a name="p1571914895114"></a><a name="p1571914895114"></a>Triggered to indicate the offset and status of list scrolling.</p>
<p id="p13719164815112"><a name="p13719164815112"></a><a name="p13719164815112"></a><strong id="b19254154542413"><a name="b19254154542413"></a><a name="b19254154542413"></a>stateValue: 0</strong>: The list is not scrolling.</p>
<p id="p1719154885113"><a name="p1719154885113"></a><a name="p1719154885113"></a><strong id="b679923542516"><a name="b679923542516"></a><a name="b679923542516"></a>stateValue: 1</strong>: The list is scrolling along with user's touches.</p>
<p id="p8719148105112"><a name="p8719148105112"></a><a name="p8719148105112"></a><strong id="b6111123911267"><a name="b6111123911267"></a><a name="b6111123911267"></a>stateValue: 2</strong>: The list is scrolling after the touches stop.</p>
</td>
</tr>
<tr id="row1371954819511"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p671984817514"><a name="p671984817514"></a><a name="p671984817514"></a>scrollbottom </p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p1971944810515"><a name="p1971944810515"></a><a name="p1971944810515"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p371984855113"><a name="p371984855113"></a><a name="p371984855113"></a>Triggered when the list is scrolled to the bottom.</p>
</td>
</tr>
<tr id="row1671944812519"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p971919481515"><a name="p971919481515"></a><a name="p971919481515"></a>scrolltop </p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p12719348135112"><a name="p12719348135112"></a><a name="p12719348135112"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p127193483517"><a name="p127193483517"></a><a name="p127193483517"></a>Triggered when the list is scrolled to the top.</p>
</td>
</tr>
<tr id="row17209489513"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p672034817518"><a name="p672034817518"></a><a name="p672034817518"></a>scrollend</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p67202487511"><a name="p67202487511"></a><a name="p67202487511"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1472054895112"><a name="p1472054895112"></a><a name="p1472054895112"></a>Triggered when the list stops scrolling.</p>
</td>
</tr>
<tr id="row27207484515"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p67201048125114"><a name="p67201048125114"></a><a name="p67201048125114"></a>scrolltouchup </p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p1720164814510"><a name="p1720164814510"></a><a name="p1720164814510"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p17720548105118"><a name="p17720548105118"></a><a name="p17720548105118"></a>Triggered when the list continues scrolling after the user lifts their fingers.</p>
</td>
</tr>
<tr id="row18720104812512"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p14720174820515"><a name="p14720174820515"></a><a name="p14720174820515"></a>requestitem </p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p572034875112"><a name="p572034875112"></a><a name="p572034875112"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p272034815115"><a name="p272034815115"></a><a name="p272034815115"></a>Triggered for a request to create a list-item.</p>
<p id="p1372014820516"><a name="p1372014820516"></a><a name="p1372014820516"></a>This event is triggered when the number of cached list-items outside the visible area is less than the value of <strong id="b1137011348317"><a name="b1137011348317"></a><a name="b1137011348317"></a>cachedcount</strong> during long list loading with delay.</p>
</td>
</tr>
<tr id="row16353171781416"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p13354161718142"><a name="p13354161718142"></a><a name="p13354161718142"></a>rotate<sup id="sup915919368206"><a name="sup915919368206"></a><a name="sup915919368206"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p1135419179146"><a name="p1135419179146"></a><a name="p1135419179146"></a>{ rotateValue: number }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1835471721415"><a name="p1835471721415"></a><a name="p1835471721415"></a>Triggered to indicate the incremental value of the rotation angle of the watch crown. This parameter is only supported by wearables.</p>
</td>
</tr>
</tbody>
</table>

## Methods<a name="section47669296127"></a>

In addition to the methods in  [Universal Methods](js-components-common-methods.md), the following events are supported.

<a name="t0c307a0cf3734cb28f3adf6af246a486"></a>
<table><thead align="left"><tr id="r83b0c5b4f4b54874b1b3d7a36bcfa36b"><th class="cellrowborder" valign="top" width="14.09%" id="mcps1.1.4.1.1"><p id="af4002018158a424c9fe9ad1a0e8a395f"><a name="af4002018158a424c9fe9ad1a0e8a395f"></a><a name="af4002018158a424c9fe9ad1a0e8a395f"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="34.910000000000004%" id="mcps1.1.4.1.2"><p id="a08987b2b1bc34babb92dd601235b0e24"><a name="a08987b2b1bc34babb92dd601235b0e24"></a><a name="a08987b2b1bc34babb92dd601235b0e24"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="51%" id="mcps1.1.4.1.3"><p id="a5e3e3d76323a4ebe96e1bdb1d1c338eb"><a name="a5e3e3d76323a4ebe96e1bdb1d1c338eb"></a><a name="a5e3e3d76323a4ebe96e1bdb1d1c338eb"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="r6eb16143d32645c2ae58f1e4857b0d99"><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p id="a16f9fd69364541c3bf57f9b2305ba51f"><a name="a16f9fd69364541c3bf57f9b2305ba51f"></a><a name="a16f9fd69364541c3bf57f9b2305ba51f"></a>scrollTo</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p id="abfb4febc1ae4429b8f593e96c50c9bc7"><a name="abfb4febc1ae4429b8f593e96c50c9bc7"></a><a name="abfb4febc1ae4429b8f593e96c50c9bc7"></a>{ index: number(specified position) }</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p id="a75c53230ef704966b5b25d2e2606584f"><a name="a75c53230ef704966b5b25d2e2606584f"></a><a name="a75c53230ef704966b5b25d2e2606584f"></a>Scrolls the list to the position of the item at the specified index.</p>
</td>
</tr>
<tr id="r9c30e9310fb349a4bf157e92668927fc"><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p id="a8ce0c025f94046a89cfe7a3d4e20d802"><a name="a8ce0c025f94046a89cfe7a3d4e20d802"></a><a name="a8ce0c025f94046a89cfe7a3d4e20d802"></a>scrollBy</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p id="ae74f4613d9a44d7f890b38e10b61e249"><a name="ae74f4613d9a44d7f890b38e10b61e249"></a><a name="ae74f4613d9a44d7f890b38e10b61e249"></a><a href="#t54327f53ea104788bc430b9047ecb47b">ScrollParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p id="a5a3997da89d649f0ac1c71461d953294"><a name="a5a3997da89d649f0ac1c71461d953294"></a><a name="a5a3997da89d649f0ac1c71461d953294"></a>Scrolls the list for a certain distance.</p>
<p id="a0767362b2b4a4535a06cb42e483b14cd"><a name="a0767362b2b4a4535a06cb42e483b14cd"></a><a name="a0767362b2b4a4535a06cb42e483b14cd"></a>This method applies only to smart TVs.</p>
</td>
</tr>
<tr id="row10674141618528"><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p id="p1166501614521"><a name="p1166501614521"></a><a name="p1166501614521"></a>scrollTop</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p id="p13665201655211"><a name="p13665201655211"></a><a name="p13665201655211"></a>{ smooth: boolean }</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p id="p1466520168521"><a name="p1466520168521"></a><a name="p1466520168521"></a>If <strong id="b984720142292"><a name="b984720142292"></a><a name="b984720142292"></a>smooth</strong> is set to <strong id="b2026210453280"><a name="b2026210453280"></a><a name="b2026210453280"></a>false</strong> (default value), the list is directly scrolled to the top.</p>
<p id="p1166519160524"><a name="p1166519160524"></a><a name="p1166519160524"></a>If <strong id="b3593012162913"><a name="b3593012162913"></a><a name="b3593012162913"></a>smooth</strong> is set to <strong id="b1085141612919"><a name="b1085141612919"></a><a name="b1085141612919"></a>true</strong>, the list is smoothly scrolled to the top.</p>
</td>
</tr>
<tr id="row1067461665217"><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p id="p96651616195214"><a name="p96651616195214"></a><a name="p96651616195214"></a>scrollBottom</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p id="p566501617522"><a name="p566501617522"></a><a name="p566501617522"></a>{ smooth: boolean }</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p id="p1966571635219"><a name="p1966571635219"></a><a name="p1966571635219"></a>If <strong id="b1850718335307"><a name="b1850718335307"></a><a name="b1850718335307"></a>smooth</strong> is set to <strong id="b155131133173012"><a name="b155131133173012"></a><a name="b155131133173012"></a>false</strong> (default value), the list is directly scrolled to the bottom.</p>
<p id="p1566513161529"><a name="p1566513161529"></a><a name="p1566513161529"></a>If <strong id="b92856582554"><a name="b92856582554"></a><a name="b92856582554"></a>smooth</strong> is set to <strong id="b1285858195517"><a name="b1285858195517"></a><a name="b1285858195517"></a>true</strong>, the list is smoothly scrolled to the bottom.</p>
</td>
</tr>
<tr id="row667481665218"><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p id="p966520161520"><a name="p966520161520"></a><a name="p966520161520"></a>scrollPage</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p id="p1166551610522"><a name="p1166551610522"></a><a name="p1166551610522"></a>{ reverse: boolean, smooth: boolean }</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p id="p156651016205211"><a name="p156651016205211"></a><a name="p156651016205211"></a>If <strong id="b4550185811294"><a name="b4550185811294"></a><a name="b4550185811294"></a>reverse</strong> is set to <strong id="b117247306"><a name="b117247306"></a><a name="b117247306"></a>false</strong> (default value), the next page is displayed. If there is no next page, the list scrolls to the bottom.</p>
<p id="p11665141617522"><a name="p11665141617522"></a><a name="p11665141617522"></a>If <strong id="b930919101316"><a name="b930919101316"></a><a name="b930919101316"></a>reverse</strong> is set to <strong id="b143091510103117"><a name="b143091510103117"></a><a name="b143091510103117"></a>true</strong>, the previous page is displayed. If there is no previous page, the list scrolls to the top.</p>
<p id="p466513161522"><a name="p466513161522"></a><a name="p466513161522"></a>If <strong id="b21022056123111"><a name="b21022056123111"></a><a name="b21022056123111"></a>smooth</strong> is set to <strong id="b16107155643115"><a name="b16107155643115"></a><a name="b16107155643115"></a>false</strong> (default value), the list is directly scrolled to another page.</p>
<p id="p5665131615528"><a name="p5665131615528"></a><a name="p5665131615528"></a>If <strong id="b115833242327"><a name="b115833242327"></a><a name="b115833242327"></a>smooth</strong> is set to <strong id="b1058832493214"><a name="b1058832493214"></a><a name="b1058832493214"></a>true</strong>, the list is smoothly scrolled to another page.</p>
</td>
</tr>
<tr id="row13674616205216"><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p id="p176652164528"><a name="p176652164528"></a><a name="p176652164528"></a>scrollArrow</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p id="p166513161529"><a name="p166513161529"></a><a name="p166513161529"></a>{ reverse: boolean, smooth: boolean }</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p id="p1966551617521"><a name="p1966551617521"></a><a name="p1966551617521"></a>If <strong id="b1549291018335"><a name="b1549291018335"></a><a name="b1549291018335"></a>reverse</strong> is set to <strong id="b20492111023311"><a name="b20492111023311"></a><a name="b20492111023311"></a>false</strong> (default value), the list scrolls towards the bottom for a certain distance. If there is no sufficient distance, the list scrolls to the bottom.</p>
<p id="p266511168524"><a name="p266511168524"></a><a name="p266511168524"></a>If <strong id="b5940743113413"><a name="b5940743113413"></a><a name="b5940743113413"></a>reverse</strong> is set to <strong id="b5940243133413"><a name="b5940243133413"></a><a name="b5940243133413"></a>true</strong>, the list scrolls towards the top for a certain distance. If there is no sufficient distance, the list scrolls to the top.</p>
<p id="p466510161529"><a name="p466510161529"></a><a name="p466510161529"></a>If <strong id="b3360148173519"><a name="b3360148173519"></a><a name="b3360148173519"></a>smooth</strong> is set to <strong id="b436188123520"><a name="b436188123520"></a><a name="b436188123520"></a>false</strong> (default value), the list is directly scrolled.</p>
<p id="p966561612526"><a name="p966561612526"></a><a name="p966561612526"></a>If <strong id="b914072419593"><a name="b914072419593"></a><a name="b914072419593"></a>smooth</strong> is set to <strong id="b5146224175917"><a name="b5146224175917"></a><a name="b5146224175917"></a>true</strong>, the list is smoothly scrolled.</p>
</td>
</tr>
<tr id="row146741516135215"><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p id="p16666161613523"><a name="p16666161613523"></a><a name="p16666161613523"></a>collapseGroup</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p id="p466641685216"><a name="p466641685216"></a><a name="p466641685216"></a>{ groupid: string }</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p id="p206661165523"><a name="p206661165523"></a><a name="p206661165523"></a>Collapses a group.</p>
<p id="p15666516205215"><a name="p15666516205215"></a><a name="p15666516205215"></a><strong id="b15480175617355"><a name="b15480175617355"></a><a name="b15480175617355"></a>groupid</strong>: ID of the group to collapse.</p>
<p id="p1566613167526"><a name="p1566613167526"></a><a name="p1566613167526"></a>All groups are collapsed when <strong id="b717013733612"><a name="b717013733612"></a><a name="b717013733612"></a>groupid</strong> is not specified.</p>
</td>
</tr>
<tr id="row2674171665212"><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p id="p16666716155214"><a name="p16666716155214"></a><a name="p16666716155214"></a>expandGroup</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p id="p1466681665219"><a name="p1466681665219"></a><a name="p1466681665219"></a>{ groupid: string }</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p id="p11666816135210"><a name="p11666816135210"></a><a name="p11666816135210"></a>Expands a group.</p>
<p id="p1766615169528"><a name="p1766615169528"></a><a name="p1766615169528"></a><strong id="b15511066374"><a name="b15511066374"></a><a name="b15511066374"></a>groupid</strong>: ID of the group to expand.</p>
<p id="p1766616164528"><a name="p1766616164528"></a><a name="p1766616164528"></a>All groups are expanded when <strong id="b692019124376"><a name="b692019124376"></a><a name="b692019124376"></a>groupid</strong> is not specified.</p>
</td>
</tr>
<tr id="row9562194955312"><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p id="p4562174912536"><a name="p4562174912536"></a><a name="p4562174912536"></a>currentOffset</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p id="p5562449185318"><a name="p5562449185318"></a><a name="p5562449185318"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p id="p8563144914534"><a name="p8563144914534"></a><a name="p8563144914534"></a>Returns the offset of the current scrolling. The return value type is <strong id="b619148183811"><a name="b619148183811"></a><a name="b619148183811"></a>Object</strong>. For details, see <a href="#table1145513617576">Table 2</a>.</p>
</td>
</tr>
</tbody>
</table>

**Table  1**  ScrollParam

<a name="t54327f53ea104788bc430b9047ecb47b"></a>
<table><thead align="left"><tr id="r6bc769560d884ebca11d7ef155cfc00c"><th class="cellrowborder" valign="top" width="12.000000000000002%" id="mcps1.2.6.1.1"><p id="a2b340d5b063045f9b972339877932f7d"><a name="a2b340d5b063045f9b972339877932f7d"></a><a name="a2b340d5b063045f9b972339877932f7d"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="22.000000000000004%" id="mcps1.2.6.1.2"><p id="a9710da1e083c4c4980317ab1772446a1"><a name="a9710da1e083c4c4980317ab1772446a1"></a><a name="a9710da1e083c4c4980317ab1772446a1"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.2.6.1.3"><p id="a273155109e9b41b1876c7b4944800ee4"><a name="a273155109e9b41b1876c7b4944800ee4"></a><a name="a273155109e9b41b1876c7b4944800ee4"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="21.000000000000004%" id="mcps1.2.6.1.4"><p id="ae31408099fa24514bac47cf09a9e7b1a"><a name="ae31408099fa24514bac47cf09a9e7b1a"></a><a name="ae31408099fa24514bac47cf09a9e7b1a"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="21.000000000000004%" id="mcps1.2.6.1.5"><p id="a333063706a09429cbe9ac81130d2b6cc"><a name="a333063706a09429cbe9ac81130d2b6cc"></a><a name="a333063706a09429cbe9ac81130d2b6cc"></a>Remarks</p>
</th>
</tr>
</thead>
<tbody><tr id="r6d4c75c9670d49ada849ec9f6bef83dd"><td class="cellrowborder" valign="top" width="12.000000000000002%" headers="mcps1.2.6.1.1 "><p id="ac4d9ce9a62d9442cb65658878f44e018"><a name="ac4d9ce9a62d9442cb65658878f44e018"></a><a name="ac4d9ce9a62d9442cb65658878f44e018"></a>dx</p>
</td>
<td class="cellrowborder" valign="top" width="22.000000000000004%" headers="mcps1.2.6.1.2 "><p id="aa6b8f1f0155a4954aab3a9609cadaf3a"><a name="aa6b8f1f0155a4954aab3a9609cadaf3a"></a><a name="aa6b8f1f0155a4954aab3a9609cadaf3a"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.2.6.1.3 "><p id="a95db84bc6a774d029883ad1abae2d022"><a name="a95db84bc6a774d029883ad1abae2d022"></a><a name="a95db84bc6a774d029883ad1abae2d022"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="21.000000000000004%" headers="mcps1.2.6.1.4 "><p id="aaa6df3c43c9b47bf81b339edcae98840"><a name="aaa6df3c43c9b47bf81b339edcae98840"></a><a name="aaa6df3c43c9b47bf81b339edcae98840"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="21.000000000000004%" headers="mcps1.2.6.1.5 "><p id="aaffe44e874d74b6297ea7841258cb941"><a name="aaffe44e874d74b6297ea7841258cb941"></a><a name="aaffe44e874d74b6297ea7841258cb941"></a>Offset for scrolling the list in the horizontal direction, in px.</p>
</td>
</tr>
<tr id="rf56d36eb7a184adc843f20b499344ed6"><td class="cellrowborder" valign="top" width="12.000000000000002%" headers="mcps1.2.6.1.1 "><p id="acb8223e7297d4dbfa243b4b974c92560"><a name="acb8223e7297d4dbfa243b4b974c92560"></a><a name="acb8223e7297d4dbfa243b4b974c92560"></a>dy</p>
</td>
<td class="cellrowborder" valign="top" width="22.000000000000004%" headers="mcps1.2.6.1.2 "><p id="aa88695593f93485a9b64158a7e05cda4"><a name="aa88695593f93485a9b64158a7e05cda4"></a><a name="aa88695593f93485a9b64158a7e05cda4"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.2.6.1.3 "><p id="a08e26d1dfd3e406b849dfaa715b0e985"><a name="a08e26d1dfd3e406b849dfaa715b0e985"></a><a name="a08e26d1dfd3e406b849dfaa715b0e985"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="21.000000000000004%" headers="mcps1.2.6.1.4 "><p id="aede3e64e10724335b9297743fece7e4a"><a name="aede3e64e10724335b9297743fece7e4a"></a><a name="aede3e64e10724335b9297743fece7e4a"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="21.000000000000004%" headers="mcps1.2.6.1.5 "><p id="ade99317ad7354fee8e88ca282cf70446"><a name="ade99317ad7354fee8e88ca282cf70446"></a><a name="ade99317ad7354fee8e88ca282cf70446"></a>Offset for scrolling the list in the vertical direction, in px.</p>
</td>
</tr>
<tr id="r69d5b3d9c60a4a5ea242be132f754948"><td class="cellrowborder" valign="top" width="12.000000000000002%" headers="mcps1.2.6.1.1 "><p id="ae0636046822644c7b7a5289fbbcd53e6"><a name="ae0636046822644c7b7a5289fbbcd53e6"></a><a name="ae0636046822644c7b7a5289fbbcd53e6"></a>smooth</p>
</td>
<td class="cellrowborder" valign="top" width="22.000000000000004%" headers="mcps1.2.6.1.2 "><p id="a7d930786d83a4f9f92a4ba4e6cbb9db0"><a name="a7d930786d83a4f9f92a4ba4e6cbb9db0"></a><a name="a7d930786d83a4f9f92a4ba4e6cbb9db0"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.2.6.1.3 "><p id="a643ff67584184620885e6ee1fddee8cb"><a name="a643ff67584184620885e6ee1fddee8cb"></a><a name="a643ff67584184620885e6ee1fddee8cb"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="21.000000000000004%" headers="mcps1.2.6.1.4 "><p id="ac86052e652c54edead6588ad0932a118"><a name="ac86052e652c54edead6588ad0932a118"></a><a name="ac86052e652c54edead6588ad0932a118"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="21.000000000000004%" headers="mcps1.2.6.1.5 "><p id="a1a8906b49d5e48f98a068f339df880e9"><a name="a1a8906b49d5e48f98a068f339df880e9"></a><a name="a1a8906b49d5e48f98a068f339df880e9"></a>Whether a sliding animation is displayed when the list position is changed.</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  Attributes of the currentOffset return object

<a name="table1145513617576"></a>
<table><thead align="left"><tr id="row1445543665717"><th class="cellrowborder" valign="top" width="21.82%" id="mcps1.2.4.1.1"><p id="p0455183695711"><a name="p0455183695711"></a><a name="p0455183695711"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="40%" id="mcps1.2.4.1.2"><p id="p2045533685711"><a name="p2045533685711"></a><a name="p2045533685711"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="38.18%" id="mcps1.2.4.1.3"><p id="p144557363572"><a name="p144557363572"></a><a name="p144557363572"></a>Remarks</p>
</th>
</tr>
</thead>
<tbody><tr id="row545516365576"><td class="cellrowborder" valign="top" width="21.82%" headers="mcps1.2.4.1.1 "><p id="p6455136135712"><a name="p6455136135712"></a><a name="p6455136135712"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.2.4.1.2 "><p id="p14456113625711"><a name="p14456113625711"></a><a name="p14456113625711"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="38.18%" headers="mcps1.2.4.1.3 "><p id="p19456436165717"><a name="p19456436165717"></a><a name="p19456436165717"></a>Scrolling offset in the x-axis, in px</p>
</td>
</tr>
<tr id="row134561936125711"><td class="cellrowborder" valign="top" width="21.82%" headers="mcps1.2.4.1.1 "><p id="p194561736145714"><a name="p194561736145714"></a><a name="p194561736145714"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.2.4.1.2 "><p id="p1345612364579"><a name="p1345612364579"></a><a name="p1345612364579"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="38.18%" headers="mcps1.2.4.1.3 "><p id="p1144122515599"><a name="p1144122515599"></a><a name="p1144122515599"></a>Scrolling offset in the y-axis, in px</p>
</td>
</tr>
</tbody>
</table>

## Example

```
<!-- index.hml -->
<div class="container">
  <list class="todo-wrapper">
    <list-item for="{{todolist}}" class="todo-item">
      <div style="flex-direction: column;align-items: center;justify-content: center;">
        <text class="todo-title">{{$item.title}}</text>
        <text class="todo-title">{{$item.date}}</text>
      </div>
    </list-item>
  </list>
</div>
```

```
// index.js
export default {
  data: {
    todolist: [{
      title: 'Prepare for the interview',
      date: '2021-12-31 10:00:00',
    }, {
      title: 'Watch the movie',
      date: '2021-12-31 20:00:00',
    }],
  },
}
```

```
/* index.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
  width: 100%;
  height: 100%;
}
.todo-wrapper {
  width: 100%;
  height: 300px;
}
.todo-item {
  width: 100%;
  height: 120px;
  justify-content:center;
}
.todo-title {
  width: 100%;
  height: 80px;
  text-align: center;
}
```

![en-us_image_0000001185033226](figures/en-us_image_0000001185033226.png)