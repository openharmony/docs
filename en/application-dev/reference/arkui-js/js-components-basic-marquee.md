# marquee<a name="EN-US_TOPIC_0000001173324593"></a>

The  **<marquee\>**  component displays single-line scrolling text.

## Permission List<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

Not supported

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
<tbody><tr id="row4159854131011"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p17480906111"><a name="p17480906111"></a><a name="p17480906111"></a>scrollamount</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p11480105116"><a name="p11480105116"></a><a name="p11480105116"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p9480809115"><a name="p9480809115"></a><a name="p9480809115"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1848070181110"><a name="p1848070181110"></a><a name="p1848070181110"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p164801809111"><a name="p164801809111"></a><a name="p164801809111"></a>Maximum length of each scroll.</p>
</td>
</tr>
<tr id="row66871514109"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p84809019113"><a name="p84809019113"></a><a name="p84809019113"></a>loop</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p548000141112"><a name="p548000141112"></a><a name="p548000141112"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p8480208113"><a name="p8480208113"></a><a name="p8480208113"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1948090161115"><a name="p1948090161115"></a><a name="p1948090161115"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p164801031110"><a name="p164801031110"></a><a name="p164801031110"></a>Number of rolling times. If this parameter is not set, the default value <strong id="b94021459245"><a name="b94021459245"></a><a name="b94021459245"></a>-1</strong> is used. When the value is less than or equal to <strong id="b415127958"><a name="b415127958"></a><a name="b415127958"></a>0</strong>, the marquee scrolls continuously.</p>
</td>
</tr>
<tr id="row192934491109"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p44801808116"><a name="p44801808116"></a><a name="p44801808116"></a>direction</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p114809011116"><a name="p114809011116"></a><a name="p114809011116"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1248015019119"><a name="p1248015019119"></a><a name="p1248015019119"></a>left</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p11480150191112"><a name="p11480150191112"></a><a name="p11480150191112"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p64801707115"><a name="p64801707115"></a><a name="p64801707115"></a>Direction in which the marquee scrolls, which can be <strong id="b13301427193515"><a name="b13301427193515"></a><a name="b13301427193515"></a>left</strong> or <strong id="b970462943510"><a name="b970462943510"></a><a name="b970462943510"></a>right</strong>.</p>
</td>
</tr>
</tbody>
</table>

## Style<a name="section14898114221220"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table155966253920"></a>
<table><thead align="left"><tr id="row195961025998"><th class="cellrowborder" valign="top" width="20.137986201379864%" id="mcps1.1.6.1.1"><p id="p1759616251194"><a name="p1759616251194"></a><a name="p1759616251194"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.968603139686032%" id="mcps1.1.6.1.2"><p id="p759613251897"><a name="p759613251897"></a><a name="p759613251897"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="18.358164183581643%" id="mcps1.1.6.1.3"><p id="p1659619251099"><a name="p1659619251099"></a><a name="p1659619251099"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p45961225998"><a name="p45961225998"></a><a name="p45961225998"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p14596142511915"><a name="p14596142511915"></a><a name="p14596142511915"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row16597162517910"><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p id="p2059717251991"><a name="p2059717251991"></a><a name="p2059717251991"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p id="p75977251899"><a name="p75977251899"></a><a name="p75977251899"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p id="p859714251891"><a name="p859714251891"></a><a name="p859714251891"></a>#e5000000</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p185974256916"><a name="p185974256916"></a><a name="p185974256916"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p15973251294"><a name="p15973251294"></a><a name="p15973251294"></a>Font color of the scrolling text.</p>
</td>
</tr>
<tr id="row6597525594"><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p id="p359710255920"><a name="p359710255920"></a><a name="p359710255920"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p id="p11597112510915"><a name="p11597112510915"></a><a name="p11597112510915"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p id="p45974252096"><a name="p45974252096"></a><a name="p45974252096"></a>37.5</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p359711251697"><a name="p359711251697"></a><a name="p359711251697"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p8597132516911"><a name="p8597132516911"></a><a name="p8597132516911"></a>Font size of the scrolling text. </p>
</td>
</tr>
<tr id="row1859816259917"><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p id="p1259882514916"><a name="p1259882514916"></a><a name="p1259882514916"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p id="p17598182515919"><a name="p17598182515919"></a><a name="p17598182515919"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p id="p145981525999"><a name="p145981525999"></a><a name="p145981525999"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p145981252096"><a name="p145981252096"></a><a name="p145981252096"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p7598192511919"><a name="p7598192511919"></a><a name="p7598192511919"></a>Whether the font size changes with the system's font size settings.</p>
<div class="note" id="note185981525290"><a name="note185981525290"></a><a name="note185981525290"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1259842517919"><a name="p1259842517919"></a><a name="p1259842517919"></a>If the <strong id="b1536242895218"><a name="b1536242895218"></a><a name="b1536242895218"></a>config-changes</strong> tag of <strong id="b6367152819525"><a name="b6367152819525"></a><a name="b6367152819525"></a>fontSize</strong> is configured for abilities in the <strong id="b2367228115217"><a name="b2367228115217"></a><a name="b2367228115217"></a>config.json</strong> file, the setting takes effect without application restart.</p>
</div></div>
</td>
</tr>
<tr id="row659811251296"><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p id="p155983256912"><a name="p155983256912"></a><a name="p155983256912"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p id="p155982251699"><a name="p155982251699"></a><a name="p155982251699"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p id="p16598125093"><a name="p16598125093"></a><a name="p16598125093"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p8598172512913"><a name="p8598172512913"></a><a name="p8598172512913"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p75985251598"><a name="p75985251598"></a><a name="p75985251598"></a>Font weight of the scrolling text. For details, see <a href="js-components-basic-text.md#section5775351116">font-weight</a> of the <strong id="b19548144111381"><a name="b19548144111381"></a><a name="b19548144111381"></a>text</strong> component.</p>
</td>
</tr>
<tr id="row155991725398"><td class="cellrowborder" valign="top" width="20.137986201379864%" headers="mcps1.1.6.1.1 "><p id="p1359915259911"><a name="p1359915259911"></a><a name="p1359915259911"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="13.968603139686032%" headers="mcps1.1.6.1.2 "><p id="p17599112517917"><a name="p17599112517917"></a><a name="p17599112517917"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="18.358164183581643%" headers="mcps1.1.6.1.3 "><p id="p115993251911"><a name="p115993251911"></a><a name="p115993251911"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p145994259915"><a name="p145994259915"></a><a name="p145994259915"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1459972510914"><a name="p1459972510914"></a><a name="p1459972510914"></a>Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font that exists in the system or the font specified by <a href="js-components-common-customizing-font.md">Custom Font Styles</a> in the family is selected as the font for the text. </p>
</td>
</tr>
</tbody>
</table>

## Event<a name="section3892191911214"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

<a name="table84827284164"></a>
<table><thead align="left"><tr id="row8483172891613"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="a426b8903842d48fa8012a24ff3c997eb"><a name="a426b8903842d48fa8012a24ff3c997eb"></a><a name="a426b8903842d48fa8012a24ff3c997eb"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="a53448ba47e5e4ae9bf7774c90820e970"><a name="a53448ba47e5e4ae9bf7774c90820e970"></a><a name="a53448ba47e5e4ae9bf7774c90820e970"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="add489ff50c444f24b759162c7f4bad9a"><a name="add489ff50c444f24b759162c7f4bad9a"></a><a name="add489ff50c444f24b759162c7f4bad9a"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row16168174591613"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p2558953141613"><a name="p2558953141613"></a><a name="p2558953141613"></a>bounce(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p10558253161617"><a name="p10558253161617"></a><a name="p10558253161617"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p65581539160"><a name="p65581539160"></a><a name="p65581539160"></a>Triggered when the marquee scrolls to the end.</p>
</td>
</tr>
<tr id="row101671442171616"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p15585534167"><a name="p15585534167"></a><a name="p15585534167"></a>finish(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p145584535165"><a name="p145584535165"></a><a name="p145584535165"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p18558125361620"><a name="p18558125361620"></a><a name="p18558125361620"></a>Triggered when the marquee finishes the specified number of scrollings (value of the <strong id="b1030012198368"><a name="b1030012198368"></a><a name="b1030012198368"></a>loop</strong> attribute). It can be triggered only when the <strong id="b15990247163611"><a name="b15990247163611"></a><a name="b15990247163611"></a>loop</strong> attribute is set to a number greater than 0.</p>
</td>
</tr>
<tr id="row9227173721610"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p35585536166"><a name="p35585536166"></a><a name="p35585536166"></a>start(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p5558115318166"><a name="p5558115318166"></a><a name="p5558115318166"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1955817532168"><a name="p1955817532168"></a><a name="p1955817532168"></a>Triggered when the marquee starts to scroll.</p>
</td>
</tr>
</tbody>
</table>

## Method<a name="section47669296127"></a>

In addition to the methods in  [Universal Methods](js-components-common-methods.md), the following events are supported.

<a name="ta27ae6832ab647a880ab27801368ec17"></a>
<table><thead align="left"><tr id="r00746cc3f4244fd7bf405d1640b42842"><th class="cellrowborder" valign="top" width="16.689999999999998%" id="mcps1.1.4.1.1"><p id="a6853bf471a534d9185a46033e5301a3c"><a name="a6853bf471a534d9185a46033e5301a3c"></a><a name="a6853bf471a534d9185a46033e5301a3c"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="6.5600000000000005%" id="mcps1.1.4.1.2"><p id="a2f6b46265ccd412b8be977c934e2e06e"><a name="a2f6b46265ccd412b8be977c934e2e06e"></a><a name="a2f6b46265ccd412b8be977c934e2e06e"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="76.75%" id="mcps1.1.4.1.3"><p id="ab97e815e4f734c4290f4f7cb608e45d4"><a name="ab97e815e4f734c4290f4f7cb608e45d4"></a><a name="ab97e815e4f734c4290f4f7cb608e45d4"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="rfd984b5dab4c419fb56fb95b53614076"><td class="cellrowborder" valign="top" width="16.689999999999998%" headers="mcps1.1.4.1.1 "><p id="a650170fd03b64d42894295d360ad74dd"><a name="a650170fd03b64d42894295d360ad74dd"></a><a name="a650170fd03b64d42894295d360ad74dd"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="6.5600000000000005%" headers="mcps1.1.4.1.2 "><p id="a634a82d9b27a449891db2c1e04622259"><a name="a634a82d9b27a449891db2c1e04622259"></a><a name="a634a82d9b27a449891db2c1e04622259"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="76.75%" headers="mcps1.1.4.1.3 "><p id="a8ab976e5b8344f9b9849843a5b30128a"><a name="a8ab976e5b8344f9b9849843a5b30128a"></a><a name="a8ab976e5b8344f9b9849843a5b30128a"></a>Starts scrolling.</p>
</td>
</tr>
<tr id="r15b7a1086fd047ea984b9cb4955dd98c"><td class="cellrowborder" valign="top" width="16.689999999999998%" headers="mcps1.1.4.1.1 "><p id="aab35a49bf5d440958734b6b30ae5c129"><a name="aab35a49bf5d440958734b6b30ae5c129"></a><a name="aab35a49bf5d440958734b6b30ae5c129"></a>stop</p>
</td>
<td class="cellrowborder" valign="top" width="6.5600000000000005%" headers="mcps1.1.4.1.2 "><p id="aaf270b3435ba4d1ba5c038066d3d08a8"><a name="aaf270b3435ba4d1ba5c038066d3d08a8"></a><a name="aaf270b3435ba4d1ba5c038066d3d08a8"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="76.75%" headers="mcps1.1.4.1.3 "><p id="a4ea339c3428f474696fe3491579ac922"><a name="a4ea339c3428f474696fe3491579ac922"></a><a name="a4ea339c3428f474696fe3491579ac922"></a>Stops scrolling.</p>
</td>
</tr>
</tbody>
</table>

## Example Code<a name="section198211501414"></a>

```
<!-- xxx.hml -->
<div class="container">
  <marquee id="customMarquee" class="customMarquee" scrollamount="{{scrollAmount}}" loop="{{loop}}"direction="{{marqueeDir}}"
    onbounce="onMarqueeBounce" onstart="onMarqueeStart" onfinish="onMarqueeFinish">{{marqueeCustomData}}</marquee>
  <div class="content">
    <button class="controlButton" onclick="onStartClick">Start</button>
    <button class="controlButton" onclick="onStopClick">Stop</button>
  </div>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #ffffff;
}
.customMarquee {
  width: 100%;
  height: 80px;
  padding: 10px;
  margin: 20px;
  border: 4px solid #ff8888;
  border-radius: 20px;
  font-size: 40px;
  color: #ff8888;
  font-weight: bolder;
  font-family: serif;
  background-color: #ffdddd;
}
.content {
  flex-direction: row;
}
.controlButton {
  flex-grow: 1;
  background-color: #F2F2F2;
  text-color: #0D81F2;
}
```

```
// xxx.js
export default {
  data: {
    scrollAmount: 30,
    loop: 3,
    marqueeDir: 'left',
    marqueeCustomData: 'Custom marquee',
  },
  onMarqueeBounce: function() {
    console.log("onMarqueeBounce");
  },
  onMarqueeStart: function() {
    console.log("onMarqueeStart");
  },
  onMarqueeFinish: function() {
    console.log("onMarqueeFinish");
  },
  onStartClick (evt) {
    this.$element('customMarquee').start();
  },
  onStopClick (evt) {
    this.$element('customMarquee').stop();
  }
}
```

![](figures/lite_bar.gif)

