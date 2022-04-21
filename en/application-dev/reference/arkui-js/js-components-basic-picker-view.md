# picker-view<a name="EN-US_TOPIC_0000001127125108"></a>

The  **<picker-view\>**  component provides the view that shows an embedded scrollable selector on the screen.

## Child Components<a name="section54292411343"></a>

Not supported

## Attributes<a name="section121957126347"></a>

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
<tbody><tr id="row6290565914"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p136971571796"><a name="p136971571796"></a><a name="p136971571796"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p36971373918"><a name="p36971373918"></a><a name="p36971373918"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p3697774912"><a name="p3697774912"></a><a name="p3697774912"></a>text</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p12697377919"><a name="p12697377919"></a><a name="p12697377919"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p126974719915"><a name="p126974719915"></a><a name="p126974719915"></a>Type of the scrollable selector, which cannot be changed dynamically. Available values are as follows:</p>
<a name="ul16977711916"></a><a name="ul16977711916"></a><ul id="ul16977711916"><li><strong id="b184817616590"><a name="b184817616590"></a><a name="b184817616590"></a>text</strong>: text selector</li><li><strong id="b116831455916"><a name="b116831455916"></a><a name="b116831455916"></a>time</strong>: time selector</li><li><strong id="b42691554144215"><a name="b42691554144215"></a><a name="b42691554144215"></a>date</strong>: date selector</li><li><strong id="b540355819423"><a name="b540355819423"></a><a name="b540355819423"></a>datetime</strong>: date and time selector</li><li><strong id="b222813410439"><a name="b222813410439"></a><a name="b222813410439"></a>multi-text</strong>: multi-column text selector</li></ul>
</td>
</tr>
</tbody>
</table>

Text selector \(**type**  is  **text**\)

<a name="ta708bd4856a044b79bae50a2ce6981b8"></a>
<table><thead align="left"><tr id="re08662644cee4140ad0d5bac7978cd9b"><th class="cellrowborder" valign="top" width="24.007599240075994%" id="mcps1.1.6.1.1"><p id="af5b093e471ec47119f04bf2fe91b6f64"><a name="af5b093e471ec47119f04bf2fe91b6f64"></a><a name="af5b093e471ec47119f04bf2fe91b6f64"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.808919108089192%" id="mcps1.1.6.1.2"><p id="a8c2c2f6a645749b7852ec7dcadaca702"><a name="a8c2c2f6a645749b7852ec7dcadaca702"></a><a name="a8c2c2f6a645749b7852ec7dcadaca702"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.62913708629137%" id="mcps1.1.6.1.3"><p id="aa63c3dd750aa44fb9ec9031e632f4f5f"><a name="aa63c3dd750aa44fb9ec9031e632f4f5f"></a><a name="aa63c3dd750aa44fb9ec9031e632f4f5f"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.14928507149285%" id="mcps1.1.6.1.4"><p id="aee9661e3366543aeac6aa37e48de4c87"><a name="aee9661e3366543aeac6aa37e48de4c87"></a><a name="aee9661e3366543aeac6aa37e48de4c87"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="49.4050594940506%" id="mcps1.1.6.1.5"><p id="a2dc04c78fce4402d9dead84ab8412bb3"><a name="a2dc04c78fce4402d9dead84ab8412bb3"></a><a name="a2dc04c78fce4402d9dead84ab8412bb3"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="re8122915226c4596b2bffeae21e37b10"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="p64901432865"><a name="p64901432865"></a><a name="p64901432865"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="p194901326610"><a name="p194901326610"></a><a name="p194901326610"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="p16490183216616"><a name="p16490183216616"></a><a name="p16490183216616"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="p12490132765"><a name="p12490132765"></a><a name="p12490132765"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="p879110395507"><a name="p879110395507"></a><a name="p879110395507"></a>Value range of the text selector.</p>
<div class="note" id="note195791919121"><a name="note195791919121"></a><a name="note195791919121"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p11957191913124"><a name="p11957191913124"></a><a name="p11957191913124"></a>Use the data binding mode, for example, range = {{data}}. Declare the corresponding variable <strong id="b1056351631112"><a name="b1056351631112"></a><a name="b1056351631112"></a>data: ["15", "20", "25"]</strong> in JavaScript.</p>
</div></div>
</td>
</tr>
<tr id="row2068183074711"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="p54902321765"><a name="p54902321765"></a><a name="p54902321765"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="p24901321469"><a name="p24901321469"></a><a name="p24901321469"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="p14901932863"><a name="p14901932863"></a><a name="p14901932863"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="p1049018321869"><a name="p1049018321869"></a><a name="p1049018321869"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="p649017329613"><a name="p649017329613"></a><a name="p649017329613"></a>Default value of the text selector. The value is the index of <strong id="b121361525737"><a name="b121361525737"></a><a name="b121361525737"></a>range</strong>.</p>
</td>
</tr>
<tr id="row1045119531711"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="p54526530112"><a name="p54526530112"></a><a name="p54526530112"></a>indicatorprefix</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="p24521553119"><a name="p24521553119"></a><a name="p24521553119"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="p14524531315"><a name="p14524531315"></a><a name="p14524531315"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="p134526535117"><a name="p134526535117"></a><a name="p134526535117"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="p114526534115"><a name="p114526534115"></a><a name="p114526534115"></a>Prefix field added when a value is specified for the text selector.</p>
</td>
</tr>
<tr id="row115191458171210"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="p2052015584123"><a name="p2052015584123"></a><a name="p2052015584123"></a>indicatorsuffix</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="p0520458141213"><a name="p0520458141213"></a><a name="p0520458141213"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="p25201358191214"><a name="p25201358191214"></a><a name="p25201358191214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="p952085813124"><a name="p952085813124"></a><a name="p952085813124"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="p175201958121212"><a name="p175201958121212"></a><a name="p175201958121212"></a>Suffix field added when a value is specified for the text selector.</p>
</td>
</tr>
</tbody>
</table>

Time selector \(**type**  is  **time**\)

<a name="table89366820719"></a>
<table><thead align="left"><tr id="row49367819714"><th class="cellrowborder" valign="top" width="24%" id="mcps1.1.6.1.1"><p id="p1493614815715"><a name="p1493614815715"></a><a name="p1493614815715"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.83%" id="mcps1.1.6.1.2"><p id="p2936881677"><a name="p2936881677"></a><a name="p2936881677"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.61%" id="mcps1.1.6.1.3"><p id="p79362815719"><a name="p79362815719"></a><a name="p79362815719"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.6.1.4"><p id="p12936584719"><a name="p12936584719"></a><a name="p12936584719"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="49.41%" id="mcps1.1.6.1.5"><p id="p15936198876"><a name="p15936198876"></a><a name="p15936198876"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2937108277"><td class="cellrowborder" valign="top" width="24%" headers="mcps1.1.6.1.1 "><p id="p077212191171"><a name="p077212191171"></a><a name="p077212191171"></a>containsecond</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p id="p1177214198714"><a name="p1177214198714"></a><a name="p1177214198714"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.6.1.3 "><p id="p87721619275"><a name="p87721619275"></a><a name="p87721619275"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p id="p127721919372"><a name="p127721919372"></a><a name="p127721919372"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p id="p13773101919719"><a name="p13773101919719"></a><a name="p13773101919719"></a>Whether seconds are contained.</p>
</td>
</tr>
<tr id="row1293719814712"><td class="cellrowborder" valign="top" width="24%" headers="mcps1.1.6.1.1 "><p id="p577314191171"><a name="p577314191171"></a><a name="p577314191171"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p id="p177735196711"><a name="p177735196711"></a><a name="p177735196711"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.6.1.3 "><p id="p127734191714"><a name="p127734191714"></a><a name="p127734191714"></a><span id="ph61411732205214"><a name="ph61411732205214"></a><a name="ph61411732205214"></a>Current time</span></p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p id="p16773151914716"><a name="p16773151914716"></a><a name="p16773151914716"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p id="p5241145091814"><a name="p5241145091814"></a><a name="p5241145091814"></a>Default value of the time selector, in the format of HH:mm.</p>
<p id="p57739191974"><a name="p57739191974"></a><a name="p57739191974"></a>If seconds are contained, the format is HH:mm:ss.</p>
</td>
</tr>
<tr id="row3976191332214"><td class="cellrowborder" valign="top" width="24%" headers="mcps1.1.6.1.1 "><p id="p095363112111"><a name="p095363112111"></a><a name="p095363112111"></a>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p id="p6953193114218"><a name="p6953193114218"></a><a name="p6953193114218"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.6.1.3 "><p id="p16934121142417"><a name="p16934121142417"></a><a name="p16934121142417"></a>24<sup id="sup169341019245"><a name="sup169341019245"></a><a name="sup169341019245"></a>1-4</sup></p>
<p id="p81051142202817"><a name="p81051142202817"></a><a name="p81051142202817"></a>-<sup id="sup14229658122718"><a name="sup14229658122718"></a><a name="sup14229658122718"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p id="p0953193112117"><a name="p0953193112117"></a><a name="p0953193112117"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p id="p1095393116216"><a name="p1095393116216"></a><a name="p1095393116216"></a>Time format used by the time selector. Available values include:</p>
<a name="ul11382144442112"></a><a name="ul11382144442112"></a><ul id="ul11382144442112"><li><strong id="b793617752019"><a name="b793617752019"></a><a name="b793617752019"></a>12</strong>: displayed in 12-hour format and distinguished by a.m. and p.m.</li><li><strong id="b273115197214"><a name="b273115197214"></a><a name="b273115197214"></a>24</strong>: displayed in 24-hour format<div class="note" id="note189471313104"><a name="note189471313104"></a><a name="note189471313104"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p9947193114104"><a name="p9947193114104"></a><a name="p9947193114104"></a>The default value is the most commonly-used hour format in the current locale. <sup id="sup319942110314"><a name="sup319942110314"></a><a name="sup319942110314"></a>5+</sup></p>
</div></div>
</li></ul>
</td>
</tr>
</tbody>
</table>

Date selector \(**type**  is  **date**\)

<a name="table174784493618"></a>
<table><thead align="left"><tr id="row54789491561"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="p14781849561"><a name="p14781849561"></a><a name="p14781849561"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="p447834912613"><a name="p447834912613"></a><a name="p447834912613"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="p12479749564"><a name="p12479749564"></a><a name="p12479749564"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="p13479749560"><a name="p13479749560"></a><a name="p13479749560"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="p247913495610"><a name="p247913495610"></a><a name="p247913495610"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1047910498616"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p167682562062"><a name="p167682562062"></a><a name="p167682562062"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p67689566612"><a name="p67689566612"></a><a name="p67689566612"></a>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p1576817561266"><a name="p1576817561266"></a><a name="p1576817561266"></a>1970-1-1</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p476819561368"><a name="p476819561368"></a><a name="p476819561368"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p87681568618"><a name="p87681568618"></a><a name="p87681568618"></a>Start date of the date selector, in the format of YYYY-MM-DD.</p>
</td>
</tr>
<tr id="row3479549162"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p117686568615"><a name="p117686568615"></a><a name="p117686568615"></a>end</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p19768115614615"><a name="p19768115614615"></a><a name="p19768115614615"></a>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p27686569618"><a name="p27686569618"></a><a name="p27686569618"></a>2100-12-31</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p1076912564617"><a name="p1076912564617"></a><a name="p1076912564617"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p1176915562611"><a name="p1176915562611"></a><a name="p1176915562611"></a>End date of the date selector, in the format of YYYY-MM-DD.</p>
</td>
</tr>
<tr id="row147919493619"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p20769056565"><a name="p20769056565"></a><a name="p20769056565"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p1376935613619"><a name="p1376935613619"></a><a name="p1376935613619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p177694568616"><a name="p177694568616"></a><a name="p177694568616"></a>Current date</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p076925617611"><a name="p076925617611"></a><a name="p076925617611"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p17695564620"><a name="p17695564620"></a><a name="p17695564620"></a>Default value of the date selector, in the format of YYYY-MM-DD.</p>
</td>
</tr>
<tr id="row106371036261"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p2238125117139"><a name="p2238125117139"></a><a name="p2238125117139"></a>lunar<sup id="sup6301324133317"><a name="sup6301324133317"></a><a name="sup6301324133317"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p023825181319"><a name="p023825181319"></a><a name="p023825181319"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p18238115116134"><a name="p18238115116134"></a><a name="p18238115116134"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p0238851121311"><a name="p0238851121311"></a><a name="p0238851121311"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p14238195141316"><a name="p14238195141316"></a><a name="p14238195141316"></a>Whether the pop-up window displays the lunar calendar.</p>
</td>
</tr>
<tr id="row11239329191713"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p13816132171719"><a name="p13816132171719"></a><a name="p13816132171719"></a>lunarswitch</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p2081653261720"><a name="p2081653261720"></a><a name="p2081653261720"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p1816103221715"><a name="p1816103221715"></a><a name="p1816103221715"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p1181663281714"><a name="p1181663281714"></a><a name="p1181663281714"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p781663212178"><a name="p781663212178"></a><a name="p781663212178"></a>Whether to display the lunar calendar switch in the date selector. When this switch is displayed, you can switch between the lunar calendar and Gregorian calendar. Turn on the switch to display the lunar calendar, and turn off the switch to hide the lunar calendar. </p>
<div class="note" id="note1688512355211"><a name="note1688512355211"></a><a name="note1688512355211"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p488582345212"><a name="p488582345212"></a><a name="p488582345212"></a></p>
</div></div>
</td>
</tr>
</tbody>
</table>

Date and time selector \(**type**  is  **datetime**\)

<a name="table1188511392120"></a>
<table><thead align="left"><tr id="row16886193915128"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="p58868399129"><a name="p58868399129"></a><a name="p58868399129"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="p19886739161213"><a name="p19886739161213"></a><a name="p19886739161213"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="p138864393128"><a name="p138864393128"></a><a name="p138864393128"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="p288653914122"><a name="p288653914122"></a><a name="p288653914122"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="p1886193931212"><a name="p1886193931212"></a><a name="p1886193931212"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row288753919128"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p20887539141215"><a name="p20887539141215"></a><a name="p20887539141215"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p788753910126"><a name="p788753910126"></a><a name="p788753910126"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p16887539111214"><a name="p16887539111214"></a><a name="p16887539111214"></a>Current date and time</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p4887203911129"><a name="p4887203911129"></a><a name="p4887203911129"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p33848571013"><a name="p33848571013"></a><a name="p33848571013"></a>Default value of the date and time selector. The value can be in the format of MM-DD-HH-mm or YYYY-MM-DD-HH-mm. If the year is not set, the current year is used by default. The value you set is the date selected by default in the pop-up window.</p>
</td>
</tr>
<tr id="row25569188246"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p7249338141710"><a name="p7249338141710"></a><a name="p7249338141710"></a>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p1814251913247"><a name="p1814251913247"></a><a name="p1814251913247"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p51424195244"><a name="p51424195244"></a><a name="p51424195244"></a>24<sup id="sup1626816180414"><a name="sup1626816180414"></a><a name="sup1626816180414"></a>1-4</sup></p>
<p id="p52731028173117"><a name="p52731028173117"></a><a name="p52731028173117"></a>-<sup id="sup627311285313"><a name="sup627311285313"></a><a name="sup627311285313"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p171426196242"><a name="p171426196242"></a><a name="p171426196242"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p1314251932418"><a name="p1314251932418"></a><a name="p1314251932418"></a>Time format used by the date and time selector. Available values include:</p>
<a name="ul15923173119204"></a><a name="ul15923173119204"></a><ul id="ul15923173119204"><li><strong id="b113902010491"><a name="b113902010491"></a><a name="b113902010491"></a>12</strong>: displayed in 12-hour format and distinguished by a.m. and p.m.</li><li><strong id="b930736675"><a name="b930736675"></a><a name="b930736675"></a>24</strong>: displayed in 24-hour format<div class="note" id="note1880145011113"><a name="note1880145011113"></a><a name="note1880145011113"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1988165031111"><a name="p1988165031111"></a><a name="p1988165031111"></a>The default value is the most commonly-used hour format in the current locale. <sup id="sup11183114910314"><a name="sup11183114910314"></a><a name="sup11183114910314"></a>5+</sup></p>
</div></div>
</li></ul>
</td>
</tr>
<tr id="row1742363212240"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p1820281519182"><a name="p1820281519182"></a><a name="p1820281519182"></a>lunar<sup id="sup370711541116"><a name="sup370711541116"></a><a name="sup370711541116"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p9202131571819"><a name="p9202131571819"></a><a name="p9202131571819"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p520313152182"><a name="p520313152182"></a><a name="p520313152182"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p142031715201812"><a name="p142031715201812"></a><a name="p142031715201812"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p16203181541812"><a name="p16203181541812"></a><a name="p16203181541812"></a>Whether the pop-up window displays the lunar calendar.</p>
</td>
</tr>
<tr id="row34576125180"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p120351520182"><a name="p120351520182"></a><a name="p120351520182"></a>lunarswitch</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p5203415171819"><a name="p5203415171819"></a><a name="p5203415171819"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p120317151181"><a name="p120317151181"></a><a name="p120317151181"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p16203115101819"><a name="p16203115101819"></a><a name="p16203115101819"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p12203111510184"><a name="p12203111510184"></a><a name="p12203111510184"></a>Whether to display the lunar calendar switch in the date and time selector. When this switch is displayed, you can switch between the lunar calendar and Gregorian calendar. Turn on the switch to display the lunar calendar, and turn off the switch to hide the lunar calendar. </p>
<div class="note" id="note11541837195218"><a name="note11541837195218"></a><a name="note11541837195218"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p454119371529"><a name="p454119371529"></a><a name="p454119371529"></a>
</div></div>
</td>
</tr>
</tbody>
</table>

Multi-column text selector \(**type**  is  **multi-text**\)

<a name="table1886619321772"></a>
<table><thead align="left"><tr id="row198671332179"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="p168677321871"><a name="p168677321871"></a><a name="p168677321871"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="p38670322711"><a name="p38670322711"></a><a name="p38670322711"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="p178670321276"><a name="p178670321276"></a><a name="p178670321276"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="p9867183215719"><a name="p9867183215719"></a><a name="p9867183215719"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="p168671324711"><a name="p168671324711"></a><a name="p168671324711"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3757154961319"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p12757204951314"><a name="p12757204951314"></a><a name="p12757204951314"></a>columns</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p13757124918137"><a name="p13757124918137"></a><a name="p13757124918137"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p0757144914132"><a name="p0757144914132"></a><a name="p0757144914132"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p14757149111317"><a name="p14757149111317"></a><a name="p14757149111317"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p1675884931313"><a name="p1675884931313"></a><a name="p1675884931313"></a>Number of columns in the multi-column text selector.</p>
</td>
</tr>
<tr id="row3867103214710"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p793074416717"><a name="p793074416717"></a><a name="p793074416717"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p793010441976"><a name="p793010441976"></a><a name="p793010441976"></a>Two-dimensional array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p7930174418712"><a name="p7930174418712"></a><a name="p7930174418712"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p2930444971"><a name="p2930444971"></a><a name="p2930444971"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p139301644675"><a name="p139301644675"></a><a name="p139301644675"></a>Items of the multi-column text selector. <strong id="b164211558164916"><a name="b164211558164916"></a><a name="b164211558164916"></a>range</strong> is a two-dimensional array that indicates the number of columns. Each item in the array indicates the data of each column, for example, <strong id="b1751216441149"><a name="b1751216441149"></a><a name="b1751216441149"></a>[["a","b"], ["c","d"]]</strong>.</p>
<div class="note" id="note112201642121219"><a name="note112201642121219"></a><a name="note112201642121219"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p8220114221212"><a name="p8220114221212"></a><a name="p8220114221212"></a>Use the data binding mode, for example, range = {{data}}. Declare the corresponding variable <strong id="b4470649201410"><a name="b4470649201410"></a><a name="b4470649201410"></a>data: [["a","b"], ["c","d"]]</strong> in the JavaScript.</p>
</div></div>
</td>
</tr>
<tr id="row18671332572"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p693016441273"><a name="p693016441273"></a><a name="p693016441273"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p159306448720"><a name="p159306448720"></a><a name="p159306448720"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p18930544471"><a name="p18930544471"></a><a name="p18930544471"></a>0,0,0,...</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p69305448719"><a name="p69305448719"></a><a name="p69305448719"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p12930144373"><a name="p12930144373"></a><a name="p12930144373"></a>Default value of the multi-column text selector, which is an array consisting of the indexes of the selected items in each column.</p>
</td>
</tr>
</tbody>
</table>

## Styles<a name="section198061172344"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table94919235408"></a>
<table><thead align="left"><tr id="row1349111237406"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p13491122316409"><a name="p13491122316409"></a><a name="p13491122316409"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="p649192317408"><a name="p649192317408"></a><a name="p649192317408"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.47895210478952%" id="mcps1.1.6.1.3"><p id="p1849162384015"><a name="p1849162384015"></a><a name="p1849162384015"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="5.909409059094091%" id="mcps1.1.6.1.4"><p id="p449162318408"><a name="p449162318408"></a><a name="p449162318408"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p12491102344016"><a name="p12491102344016"></a><a name="p12491102344016"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row114923234409"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1849262316408"><a name="p1849262316408"></a><a name="p1849262316408"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p1249252318405"><a name="p1249252318405"></a><a name="p1249252318405"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="p9492162315401"><a name="p9492162315401"></a><a name="p9492162315401"></a>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="p134923233404"><a name="p134923233404"></a><a name="p134923233404"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p84926239401"><a name="p84926239401"></a><a name="p84926239401"></a>Font color of a candidate item.</p>
</td>
</tr>
<tr id="row1249232316406"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p14492122354013"><a name="p14492122354013"></a><a name="p14492122354013"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p249222310403"><a name="p249222310403"></a><a name="p249222310403"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="p1149212231402"><a name="p1149212231402"></a><a name="p1149212231402"></a>16px</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="p1849282317409"><a name="p1849282317409"></a><a name="p1849282317409"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p19492112316406"><a name="p19492112316406"></a><a name="p19492112316406"></a>Font size of a candidate item. The value is of the length type, in pixels.</p>
</td>
</tr>
<tr id="row1249262314017"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p54925236401"><a name="p54925236401"></a><a name="p54925236401"></a>selected-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p449219234408"><a name="p449219234408"></a><a name="p449219234408"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="p54924238408"><a name="p54924238408"></a><a name="p54924238408"></a>#ff0a69f7</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="p949242334013"><a name="p949242334013"></a><a name="p949242334013"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p20492152334010"><a name="p20492152334010"></a><a name="p20492152334010"></a>Font color of the selected item.</p>
</td>
</tr>
<tr id="row10492423134013"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p174938237409"><a name="p174938237409"></a><a name="p174938237409"></a>selected-font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p9493182314010"><a name="p9493182314010"></a><a name="p9493182314010"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="p16493223104019"><a name="p16493223104019"></a><a name="p16493223104019"></a>20px</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="p74931223124013"><a name="p74931223124013"></a><a name="p74931223124013"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p449342311407"><a name="p449342311407"></a><a name="p449342311407"></a>Font size of the selected item. The value is of the length type, in pixels.</p>
</td>
</tr>
<tr id="row84941623134017"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p104941323114011"><a name="p104941323114011"></a><a name="p104941323114011"></a>disappear-color<sup id="sup54941523144015"><a name="sup54941523144015"></a><a name="sup54941523144015"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p349412319400"><a name="p349412319400"></a><a name="p349412319400"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="p14942236409"><a name="p14942236409"></a><a name="p14942236409"></a>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="p10494123164013"><a name="p10494123164013"></a><a name="p10494123164013"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p20494323144012"><a name="p20494323144012"></a><a name="p20494323144012"></a>Font color of the items that gradually disappear. Disappearing items are the top option and bottom option of a column containing five options in total.</p>
<div class="note" id="note682125718522"><a name="note682125718522"></a><a name="note682125718522"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p17821185711521"><a name="p17821185711521"></a><a name="p17821185711521"></a></p>
</div></div>
</td>
</tr>
<tr id="row1949432318405"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1549419237407"><a name="p1549419237407"></a><a name="p1549419237407"></a>disappear-font-size<sup id="sup0494132313404"><a name="sup0494132313404"></a><a name="sup0494132313404"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p144940238404"><a name="p144940238404"></a><a name="p144940238404"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="p64941023194020"><a name="p64941023194020"></a><a name="p64941023194020"></a>14px</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="p1949522364020"><a name="p1949522364020"></a><a name="p1949522364020"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1549532364020"><a name="p1549532364020"></a><a name="p1549532364020"></a>Font size of the items that gradually disappear. Disappearing items are the top option and bottom option of a column containing five options in total.</p>
<div class="note" id="note17211975317"><a name="note17211975317"></a><a name="note17211975317"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1821895535"><a name="p1821895535"></a><a name="p1821895535"></a></p>
</div></div>
</td>
</tr>
<tr id="row19495152311405"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p154951237400"><a name="p154951237400"></a><a name="p154951237400"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p3495192316402"><a name="p3495192316402"></a><a name="p3495192316402"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="p8495172324010"><a name="p8495172324010"></a><a name="p8495172324010"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="p134951723154010"><a name="p134951723154010"></a><a name="p134951723154010"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p124957233408"><a name="p124957233408"></a><a name="p124957233408"></a>Font type of an item. Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the font specified by <a href="js-components-common-customizing-font.md">Custom Font Styles</a> is used for the text</p>
</td>
</tr>
</tbody>
</table>

## Events<a name="section103398253399"></a>

The following events are supported.

Text selector \(**type**  is  **text**\)

<a name="table17339225123915"></a>
<table><thead align="left"><tr id="row1339925143920"><th class="cellrowborder" valign="top" width="16.16161616161616%" id="mcps1.1.4.1.1"><p id="p8340925103911"><a name="p8340925103911"></a><a name="p8340925103911"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="41.41414141414141%" id="mcps1.1.4.1.2"><p id="p2340325113912"><a name="p2340325113912"></a><a name="p2340325113912"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="42.42424242424242%" id="mcps1.1.4.1.3"><p id="p1534013255394"><a name="p1534013255394"></a><a name="p1534013255394"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row15340192543910"><td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.1.4.1.1 "><p id="p334016258395"><a name="p334016258395"></a><a name="p334016258395"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="41.41414141414141%" headers="mcps1.1.4.1.2 "><p id="p93401725183918"><a name="p93401725183918"></a><a name="p93401725183918"></a>{ newValue: newValue, newSelected: newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="42.42424242424242%" headers="mcps1.1.4.1.3 "><p id="p17340122515397"><a name="p17340122515397"></a><a name="p17340122515397"></a>Triggered when a value is specified for the text selector.</p>
</td>
</tr>
</tbody>
</table>

Time selector \(**type**  is  **time**\)

<a name="table13340325133918"></a>
<table><thead align="left"><tr id="row20340125143918"><th class="cellrowborder" valign="top" width="16.16161616161616%" id="mcps1.1.4.1.1"><p id="p14340152533917"><a name="p14340152533917"></a><a name="p14340152533917"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="41.41414141414141%" id="mcps1.1.4.1.2"><p id="p1634082553920"><a name="p1634082553920"></a><a name="p1634082553920"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="42.42424242424242%" id="mcps1.1.4.1.3"><p id="p134072523914"><a name="p134072523914"></a><a name="p134072523914"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1434032553920"><td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.1.4.1.1 "><p id="p3341625183910"><a name="p3341625183910"></a><a name="p3341625183910"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="41.41414141414141%" headers="mcps1.1.4.1.2 "><p id="p1634122513911"><a name="p1634122513911"></a><a name="p1634122513911"></a>{ hour: hour, minute: minute<span id="ph734120255396"><a name="ph734120255396"></a><a name="ph734120255396"></a>, [second:second] </span>}</p>
</td>
<td class="cellrowborder" valign="top" width="42.42424242424242%" headers="mcps1.1.4.1.3 "><p id="p4341225133916"><a name="p4341225133916"></a><a name="p4341225133916"></a>Triggered when a value is specified for the time selector.</p>
<p id="p1341192514397"><a name="p1341192514397"></a><a name="p1341192514397"></a>If seconds are contained, the value contains hour, minute, and second.</p>
</td>
</tr>
</tbody>
</table>

Date selector \(**type**  is  **date**\)

<a name="table103414254397"></a>
<table><thead align="left"><tr id="row234142553912"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="p7341125153916"><a name="p7341125153916"></a><a name="p7341125153916"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="p1834182593915"><a name="p1834182593915"></a><a name="p1834182593915"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="p5341142593910"><a name="p5341142593910"></a><a name="p5341142593910"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row83411325103912"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="p6341122553914"><a name="p6341122553914"></a><a name="p6341122553914"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="p17341192563911"><a name="p17341192563911"></a><a name="p17341192563911"></a>{ year:year, month:month, day:day }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="p103419259392"><a name="p103419259392"></a><a name="p103419259392"></a>Triggered when a value is specified for the date selector.</p>
</td>
</tr>
</tbody>
</table>

Date and time selector \(**type**  is  **datetime**\)

<a name="table6342192514395"></a>
<table><thead align="left"><tr id="row43421725183919"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="p17342325173911"><a name="p17342325173911"></a><a name="p17342325173911"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="p63421825113915"><a name="p63421825113915"></a><a name="p63421825113915"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="p634217257395"><a name="p634217257395"></a><a name="p634217257395"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1234216257392"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="p5342725203916"><a name="p5342725203916"></a><a name="p5342725203916"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="p20342132512395"><a name="p20342132512395"></a><a name="p20342132512395"></a>{ year:year, month:month, day:day,  hour:hour, minute:minute }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="p11342102563910"><a name="p11342102563910"></a><a name="p11342102563910"></a>Triggered when a value is specified for the date and time selector.</p>
</td>
</tr>
</tbody>
</table>

Multi-text selector \(**type**  is  **multi-text**\)

<a name="table5342325203913"></a>
<table><thead align="left"><tr id="row153422255390"><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.4.1.1"><p id="p153431725153916"><a name="p153431725153916"></a><a name="p153431725153916"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="36.9%" id="mcps1.1.4.1.2"><p id="p11343102523916"><a name="p11343102523916"></a><a name="p11343102523916"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="49.13%" id="mcps1.1.4.1.3"><p id="p16343925193913"><a name="p16343925193913"></a><a name="p16343925193913"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row103430256392"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.4.1.1 "><p id="p19343122514399"><a name="p19343122514399"></a><a name="p19343122514399"></a>columnchange</p>
</td>
<td class="cellrowborder" valign="top" width="36.9%" headers="mcps1.1.4.1.2 "><p id="p12343102573913"><a name="p12343102573913"></a><a name="p12343102573913"></a>{ column:column, newValue:newValue, newSelected:newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="49.13%" headers="mcps1.1.4.1.3 "><p id="p1534352593917"><a name="p1534352593917"></a><a name="p1534352593917"></a>Triggered when the value of a column in the multi-column selector changes. <strong id="b3821122445914"><a name="b3821122445914"></a><a name="b3821122445914"></a>column</strong> indicates the column whose value has changed, <strong id="b15827124135915"><a name="b15827124135915"></a><a name="b15827124135915"></a>newValue</strong> indicates the selected value, and <strong id="b782722495913"><a name="b782722495913"></a><a name="b782722495913"></a>newSelected</strong> indicates the index of the selected value.</p>
</td>
</tr>
</tbody>
</table>

## Methods<a name="section718304515396"></a>

Not supported

## Example Code<a name="section738534695417"></a>

```
<!-- xxx.hml -->
<div class="container" @swipe="handleSwipe">
  <text class="title">
    Selected: {{time}}
  </text>
  <picker-view class="time-picker" type="time" selected="{{defaultTime}}" @change="handleChange"></picker-view>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}
.title {
  font-size: 30px;
  text-align: center;
}
.time-picker {
  width: 500px;
  height: 400px;
  margin-top: 20px;
}
```

```
/* xxx.js */
export default {
  data: {
    defaultTime: "",
    time: "",
  },
  onInit() {
    this.defaultTime = this.now();
  },
  handleChange(data) {
    this.time = this.concat(data.hour, data.minute);
  },
  now() {
    const date = new Date();
    const hours = date.getHours();
    const minutes = date.getMinutes();
    return this.concat(hours, minutes);
  },

  fill(value) {
    return (value > 9 ? "" : "0") + value;
  },

  concat(hours, minutes) {
    return `${this.fill(hours)}:${this.fill(minutes)}`;
  },
}
```

![](figures/lite_bar-4.png)

