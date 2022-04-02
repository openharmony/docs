# picker<a name="EN-US_TOPIC_0000001173324637"></a>

The  **<picker\>**  component supports common, date, time, data and time, and multi-column text selectors.

## Required Permissions<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

None

## Attributes<a name="section2907183951110"></a>

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
<tbody><tr id="row297418523612"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1292865313615"><a name="p1292865313615"></a><a name="p1292865313615"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1092810536617"><a name="p1092810536617"></a><a name="p1092810536617"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p192818533612"><a name="p192818533612"></a><a name="p192818533612"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p492817531269"><a name="p492817531269"></a><a name="p492817531269"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p99287536614"><a name="p99287536614"></a><a name="p99287536614"></a>Dynamic modification is not supported. Available values include:</p>
<a name="ul17928553367"></a><a name="ul17928553367"></a><ul id="ul17928553367"><li><strong id="b184817616590"><a name="b184817616590"></a><a name="b184817616590"></a>text</strong>: text selector</li><li><strong id="b167181151523"><a name="b167181151523"></a><a name="b167181151523"></a>data</strong>: date selector</li><li><strong id="b116831455916"><a name="b116831455916"></a><a name="b116831455916"></a>time</strong>: time selector</li><li><strong id="b0802045135218"><a name="b0802045135218"></a><a name="b0802045135218"></a>datetime</strong>: date and time selector</li><li><strong id="b7992511155314"><a name="b7992511155314"></a><a name="b7992511155314"></a>multi-text</strong>: multi-column text selector</li></ul>
</td>
</tr>
</tbody>
</table>

### Text Selector<a name="section28061337142416"></a>

When  **type**  is set to  **text**, a text selector is used.

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
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="p14907328610"><a name="p14907328610"></a><a name="p14907328610"></a>Value range of the common selector, for example, <strong id="b67251465227"><a name="b67251465227"></a><a name="b67251465227"></a>["15", "20", "25"]</strong>.</p>
<div class="note" id="note4860842141115"><a name="note4860842141115"></a><a name="note4860842141115"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1386074271117"><a name="p1386074271117"></a><a name="p1386074271117"></a>Use the data binding mode, for example, range = {{data}}. Declare the corresponding variable <strong id="b1056351631112"><a name="b1056351631112"></a><a name="b1056351631112"></a>data: ["15", "20", "25"]</strong> in the JavaScript.</p>
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
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="p649017329613"><a name="p649017329613"></a><a name="p649017329613"></a>Default value of the common selector. The value should be the index of <strong id="b1264831483012"><a name="b1264831483012"></a><a name="b1264831483012"></a>range</strong>.</p>
</td>
</tr>
<tr id="row8381203074710"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="p1349019328615"><a name="p1349019328615"></a><a name="p1349019328615"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="p114903324614"><a name="p114903324614"></a><a name="p114903324614"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="p34909328614"><a name="p34909328614"></a><a name="p34909328614"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="p164909325610"><a name="p164909325610"></a><a name="p164909325610"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="p04904325616"><a name="p04904325616"></a><a name="p04904325616"></a>Value of the common selector.</p>
</td>
</tr>
</tbody>
</table>

### Date Selector<a name="section194021642517"></a>

When  **type**  is set to  **date**, a date selector is used.

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
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p17695564620"><a name="p17695564620"></a><a name="p17695564620"></a>Default value of the date selector, in format of YYYY-MM-DD.</p>
</td>
</tr>
<tr id="row5556142018016"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p2556102015019"><a name="p2556102015019"></a><a name="p2556102015019"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p55560209013"><a name="p55560209013"></a><a name="p55560209013"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p55569201203"><a name="p55569201203"></a><a name="p55569201203"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p14556142017019"><a name="p14556142017019"></a><a name="p14556142017019"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p1855614200012"><a name="p1855614200012"></a><a name="p1855614200012"></a>Value of the date selector.</p>
</td>
</tr>
<tr id="row122372051111319"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p2238125117139"><a name="p2238125117139"></a><a name="p2238125117139"></a>lunar<sup id="sup6301324133317"><a name="sup6301324133317"></a><a name="sup6301324133317"></a>5+</sup></p>
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
<tr id="row106371036261"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p118782109269"><a name="p118782109269"></a><a name="p118782109269"></a>lunarswitch</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p188781410192610"><a name="p188781410192610"></a><a name="p188781410192610"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p14878181052613"><a name="p14878181052613"></a><a name="p14878181052613"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p20878141062610"><a name="p20878141062610"></a><a name="p20878141062610"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p9878910132617"><a name="p9878910132617"></a><a name="p9878910132617"></a>Whether the date selector displays the lunar calendar switch, which is used to switch between the Gregorian calendar and lunar calendar. The value <strong id="b1242195251513"><a name="b1242195251513"></a><a name="b1242195251513"></a>true</strong> means to display the lunar calendar switch for users to switch between the Gregorian calendar and lunar calendar. The value <strong id="b729391317186"><a name="b729391317186"></a><a name="b729391317186"></a>false</strong> means not to display the lunar calendar switch.</p>
<div class="note" id="note799016359510"><a name="note799016359510"></a><a name="note799016359510"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p49901135165115"><a name="p49901135165115"></a><a name="p49901135165115"></a> When both <strong id="b66411209185"><a name="b66411209185"></a><a name="b66411209185"></a>lunarswitch</strong> and <strong id="b1364102010185"><a name="b1364102010185"></a><a name="b1364102010185"></a>lunar</strong> are set to <strong id="b665102015187"><a name="b665102015187"></a><a name="b665102015187"></a>true</strong>, the switch is selected.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

### Time Selector<a name="section14386134222510"></a>

When  **type**  is set to  **time**, a time selector is used.

<a name="table89366820719"></a>
<table><thead align="left"><tr id="row49367819714"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="p1493614815715"><a name="p1493614815715"></a><a name="p1493614815715"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="p2936881677"><a name="p2936881677"></a><a name="p2936881677"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="p79362815719"><a name="p79362815719"></a><a name="p79362815719"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="p12936584719"><a name="p12936584719"></a><a name="p12936584719"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="p15936198876"><a name="p15936198876"></a><a name="p15936198876"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2937108277"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p077212191171"><a name="p077212191171"></a><a name="p077212191171"></a>containsecond</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p1177214198714"><a name="p1177214198714"></a><a name="p1177214198714"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p87721619275"><a name="p87721619275"></a><a name="p87721619275"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p127721919372"><a name="p127721919372"></a><a name="p127721919372"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p13773101919719"><a name="p13773101919719"></a><a name="p13773101919719"></a>Whether seconds are contained.</p>
</td>
</tr>
<tr id="row1293719814712"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p577314191171"><a name="p577314191171"></a><a name="p577314191171"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p177735196711"><a name="p177735196711"></a><a name="p177735196711"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p127734191714"><a name="p127734191714"></a><a name="p127734191714"></a>Current time</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p16773151914716"><a name="p16773151914716"></a><a name="p16773151914716"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p57739191974"><a name="p57739191974"></a><a name="p57739191974"></a>Default value of the time selector, in the format of HH:mm. If seconds are contained, the format is HH:mm:ss.</p>
</td>
</tr>
<tr id="row179378815715"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p1577313191078"><a name="p1577313191078"></a><a name="p1577313191078"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p47731191717"><a name="p47731191717"></a><a name="p47731191717"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p137731819271"><a name="p137731819271"></a><a name="p137731819271"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p1977310195710"><a name="p1977310195710"></a><a name="p1977310195710"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p117733191473"><a name="p117733191473"></a><a name="p117733191473"></a>Value of the time selector.</p>
</td>
</tr>
<tr id="row3976191332214"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p7249338141710"><a name="p7249338141710"></a><a name="p7249338141710"></a>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p9642147162010"><a name="p9642147162010"></a><a name="p9642147162010"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p10455132202312"><a name="p10455132202312"></a><a name="p10455132202312"></a>24<sup id="sup13455132211233"><a name="sup13455132211233"></a><a name="sup13455132211233"></a>1-4</sup></p>
<p id="p19642164711209"><a name="p19642164711209"></a><a name="p19642164711209"></a>-<sup id="sup14229658122718"><a name="sup14229658122718"></a><a name="sup14229658122718"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p1964254732010"><a name="p1964254732010"></a><a name="p1964254732010"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p1642114782010"><a name="p1642114782010"></a><a name="p1642114782010"></a>Time format used by the time selector. Available values include:</p>
<a name="ul174074428121"></a><a name="ul174074428121"></a><ul id="ul174074428121"><li><strong id="b793617752019"><a name="b793617752019"></a><a name="b793617752019"></a>12</strong>: displayed in 12-hour format and distinguished by a.m. and p.m.</li><li><strong id="b273115197214"><a name="b273115197214"></a><a name="b273115197214"></a>24</strong>: displayed in 24-hour format<div class="note" id="note189471313104"><a name="note189471313104"></a><a name="note189471313104"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p9947193114104"><a name="p9947193114104"></a><a name="p9947193114104"></a>The default value is the most commonly-used hour format in the current locale. <sup id="sup15655162732715"><a name="sup15655162732715"></a><a name="sup15655162732715"></a>5+</sup></p>
</div></div>
</li></ul>
</td>
</tr>
</tbody>
</table>

### Date and Time Selector<a name="section10180192513261"></a>

When  **type**  is set to  **datetime**, a date and time selector is used.

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
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p177512214430"><a name="p177512214430"></a><a name="p177512214430"></a>Default value of the date and time selector. The value can be in either of the following formats:</p>
<a name="ul204071643430"></a><a name="ul204071643430"></a><ul id="ul204071643430"><li>MM-DD-HH-mm</li><li>YYYY-MM-DD-HH-mm</li></ul>
<p id="p192194417433"><a name="p192194417433"></a><a name="p192194417433"></a>If the year is not set, the current year is used by default. The value you set is the date selected by default in the pop-up window.</p>
</td>
</tr>
<tr id="row1887173951219"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p1288733931210"><a name="p1288733931210"></a><a name="p1288733931210"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p1788703918124"><a name="p1788703918124"></a><a name="p1788703918124"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p18887193911129"><a name="p18887193911129"></a><a name="p18887193911129"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p88873396121"><a name="p88873396121"></a><a name="p88873396121"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p1388773910128"><a name="p1388773910128"></a><a name="p1388773910128"></a>Value of the date and time selector.</p>
</td>
</tr>
<tr id="row25569188246"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p655031510218"><a name="p655031510218"></a><a name="p655031510218"></a>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p1814251913247"><a name="p1814251913247"></a><a name="p1814251913247"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p1097921216293"><a name="p1097921216293"></a><a name="p1097921216293"></a>24<sup id="sup1626816180414"><a name="sup1626816180414"></a><a name="sup1626816180414"></a>1-4</sup></p>
<p id="p797971210297"><a name="p797971210297"></a><a name="p797971210297"></a>-<sup id="sup13979712182910"><a name="sup13979712182910"></a><a name="sup13979712182910"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p171426196242"><a name="p171426196242"></a><a name="p171426196242"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p1314251932418"><a name="p1314251932418"></a><a name="p1314251932418"></a>Time format used by the date and time selector. Available values include:</p>
<a name="ul4189124631213"></a><a name="ul4189124631213"></a><ul id="ul4189124631213"><li><strong id="b113902010491"><a name="b113902010491"></a><a name="b113902010491"></a>12</strong>: displayed in 12-hour format and distinguished by a.m. and p.m.</li><li><strong id="b1676844709"><a name="b1676844709"></a><a name="b1676844709"></a>24</strong>: displayed in 24-hour format<div class="note" id="note1563822112115"><a name="note1563822112115"></a><a name="note1563822112115"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1563882115113"><a name="p1563882115113"></a><a name="p1563882115113"></a>The default value is the most commonly-used hour format in the current locale. <sup id="sup1719092182914"><a name="sup1719092182914"></a><a name="sup1719092182914"></a>5+</sup></p>
</div></div>
</li></ul>
</td>
</tr>
<tr id="row1742363212240"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p17312155631610"><a name="p17312155631610"></a><a name="p17312155631610"></a>lunar<sup id="sup1613014514117"><a name="sup1613014514117"></a><a name="sup1613014514117"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p23121856191617"><a name="p23121856191617"></a><a name="p23121856191617"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p331265681617"><a name="p331265681617"></a><a name="p331265681617"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p331265615166"><a name="p331265615166"></a><a name="p331265615166"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p63124569165"><a name="p63124569165"></a><a name="p63124569165"></a>Whether the pop-up window displays the lunar calendar.</p>
</td>
</tr>
<tr id="row13832125261615"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p23121056171615"><a name="p23121056171615"></a><a name="p23121056171615"></a>lunarswitch</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p153121564169"><a name="p153121564169"></a><a name="p153121564169"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p14312205651615"><a name="p14312205651615"></a><a name="p14312205651615"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p12312856141615"><a name="p12312856141615"></a><a name="p12312856141615"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p134738505123"><a name="p134738505123"></a><a name="p134738505123"></a>Whether the date selector displays the lunar calendar switch, which is used to switch between the Gregorian calendar and lunar calendar. The value <strong id="b11888837151819"><a name="b11888837151819"></a><a name="b11888837151819"></a>true</strong> means to display the lunar calendar switch for users to switch between the Gregorian calendar and lunar calendar. The value <strong id="b454518384186"><a name="b454518384186"></a><a name="b454518384186"></a>false</strong> means not to display the lunar calendar switch.</p>
<div class="note" id="note5428114735118"><a name="note5428114735118"></a><a name="note5428114735118"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1342819474512"><a name="p1342819474512"></a><a name="p1342819474512"></a>When both <strong id="b57802039111819"><a name="b57802039111819"></a><a name="b57802039111819"></a>lunarswitch</strong> and <strong id="b18781153991810"><a name="b18781153991810"></a><a name="b18781153991810"></a>lunar</strong> are set to <strong id="b4781173931813"><a name="b4781173931813"></a><a name="b4781173931813"></a>true</strong>, the switch is selected.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

### Multi-Column Text Selector<a name="section18757165414262"></a>

When  **type**  is set to  **multi-text**, a multi-column text selector is used.

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
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p139301644675"><a name="p139301644675"></a><a name="p139301644675"></a>Items of the multi-column text selector. <strong id="b74831653144819"><a name="b74831653144819"></a><a name="b74831653144819"></a>range</strong> is a two-dimensional array that indicates the number of columns. Each item in the array indicates the data of each column, for example, <strong id="b1751216441149"><a name="b1751216441149"></a><a name="b1751216441149"></a>[["a","b"], ["c","d"]]</strong>.</p>
<div class="note" id="note0651143101220"><a name="note0651143101220"></a><a name="note0651143101220"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p15651335123"><a name="p15651335123"></a><a name="p15651335123"></a>Use the data binding mode, for example, range = {{data}}. Declare the corresponding variable <strong id="b4470649201410"><a name="b4470649201410"></a><a name="b4470649201410"></a>data: [["a","b"], ["c","d"]]</strong> in the JavaScript.</p>
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
<tr id="row1186818329711"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p1693054420719"><a name="p1693054420719"></a><a name="p1693054420719"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p69308446714"><a name="p69308446714"></a><a name="p69308446714"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p1893014441578"><a name="p1893014441578"></a><a name="p1893014441578"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p11930174414718"><a name="p11930174414718"></a><a name="p11930174414718"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p5930344474"><a name="p5930344474"></a><a name="p5930344474"></a>Value of the multi-column text selector, which is an array consisting of the values of the selected items in each column.</p>
</td>
</tr>
</tbody>
</table>

## Styles<a name="section1299175511712"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table861635214361"></a>
<table><thead align="left"><tr id="row161725216363"><th class="cellrowborder" valign="top" width="14.318568143185681%" id="mcps1.1.6.1.1"><p id="p166171452183611"><a name="p166171452183611"></a><a name="p166171452183611"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="11.528847115288471%" id="mcps1.1.6.1.2"><p id="p0617952203612"><a name="p0617952203612"></a><a name="p0617952203612"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="13.268673132686734%" id="mcps1.1.6.1.3"><p id="p5617252183615"><a name="p5617252183615"></a><a name="p5617252183615"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="8.60913908609139%" id="mcps1.1.6.1.4"><p id="p561775273618"><a name="p561775273618"></a><a name="p561775273618"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="52.274772522747725%" id="mcps1.1.6.1.5"><p id="p12617185218369"><a name="p12617185218369"></a><a name="p12617185218369"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row26174523369"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="p861715528369"><a name="p861715528369"></a><a name="p861715528369"></a>text-color</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="p12617195219360"><a name="p12617195219360"></a><a name="p12617195219360"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="p156171552173616"><a name="p156171552173616"></a><a name="p156171552173616"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="p1961715522367"><a name="p1961715522367"></a><a name="p1961715522367"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="p761713528364"><a name="p761713528364"></a><a name="p761713528364"></a>Text color of the selector.</p>
</td>
</tr>
<tr id="row96178528368"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="p161785273614"><a name="p161785273614"></a><a name="p161785273614"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="p14618752123616"><a name="p14618752123616"></a><a name="p14618752123616"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="p4618145223618"><a name="p4618145223618"></a><a name="p4618145223618"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="p26189527366"><a name="p26189527366"></a><a name="p26189527366"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="p186188525363"><a name="p186188525363"></a><a name="p186188525363"></a>Font size of the selector.</p>
</td>
</tr>
<tr id="row18618195220360"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="p13618205233610"><a name="p13618205233610"></a><a name="p13618205233610"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="p146184528362"><a name="p146184528362"></a><a name="p146184528362"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="p15618852133613"><a name="p15618852133613"></a><a name="p15618852133613"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="p12618652143612"><a name="p12618652143612"></a><a name="p12618652143612"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="p106188526364"><a name="p106188526364"></a><a name="p106188526364"></a>Whether the font size changes with the system's font size settings.</p>
<div class="note" id="note17618552143613"><a name="note17618552143613"></a><a name="note17618552143613"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p186187525369"><a name="p186187525369"></a><a name="p186187525369"></a>If the <strong id="b133885541595"><a name="b133885541595"></a><a name="b133885541595"></a>config-changes</strong> tag of <strong id="b103882542599"><a name="b103882542599"></a><a name="b103882542599"></a>fontSize</strong> is configured for abilities in the <strong id="b538965485919"><a name="b538965485919"></a><a name="b538965485919"></a>config.json</strong> file, the setting takes effect without application restart.</p>
</div></div>
</td>
</tr>
<tr id="row13618135215369"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="p16618175233612"><a name="p16618175233612"></a><a name="p16618175233612"></a>letter-spacing</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="p1618175253611"><a name="p1618175253611"></a><a name="p1618175253611"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="p13618052133610"><a name="p13618052133610"></a><a name="p13618052133610"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="p561811521364"><a name="p561811521364"></a><a name="p561811521364"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="p3619852193615"><a name="p3619852193615"></a><a name="p3619852193615"></a>Letter spacing of the selector. For details, see <a href="js-components-basic-text.md#section5775351116">letter-spacing</a> of the <strong id="b16466115785416"><a name="b16466115785416"></a><a name="b16466115785416"></a>text</strong> component.</p>
</td>
</tr>
<tr id="row166194521368"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="p76191552133617"><a name="p76191552133617"></a><a name="p76191552133617"></a>text-decoration</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="p11619155211364"><a name="p11619155211364"></a><a name="p11619155211364"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="p166191252123618"><a name="p166191252123618"></a><a name="p166191252123618"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="p661975283615"><a name="p661975283615"></a><a name="p661975283615"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="p13619115293616"><a name="p13619115293616"></a><a name="p13619115293616"></a>Text decoration of the selector. For details, see <a href="js-components-basic-text.md#section5775351116">text-decoration</a> of the <strong id="b3970995559"><a name="b3970995559"></a><a name="b3970995559"></a>text</strong> component.</p>
</td>
</tr>
<tr id="row18619205203619"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="p11619155203617"><a name="p11619155203617"></a><a name="p11619155203617"></a>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="p2061910523364"><a name="p2061910523364"></a><a name="p2061910523364"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="p1561995212365"><a name="p1561995212365"></a><a name="p1561995212365"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="p196193523361"><a name="p196193523361"></a><a name="p196193523361"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="p11619205253614"><a name="p11619205253614"></a><a name="p11619205253614"></a>Font style of the selector. For details, see <a href="js-components-basic-text.md#section5775351116">font-style</a> of the <strong id="b270516223556"><a name="b270516223556"></a><a name="b270516223556"></a>text</strong> component.</p>
</td>
</tr>
<tr id="row3619652133619"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="p7619135233617"><a name="p7619135233617"></a><a name="p7619135233617"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="p13619165203616"><a name="p13619165203616"></a><a name="p13619165203616"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="p10619175217364"><a name="p10619175217364"></a><a name="p10619175217364"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="p16619252163610"><a name="p16619252163610"></a><a name="p16619252163610"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="p762025283614"><a name="p762025283614"></a><a name="p762025283614"></a>Font weight of the selector. For details, see <a href="js-components-basic-text.md#section5775351116">font-weight</a> of the <strong id="b1825684285512"><a name="b1825684285512"></a><a name="b1825684285512"></a>text</strong> component.</p>
</td>
</tr>
<tr id="row6620145263610"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="p186206524367"><a name="p186206524367"></a><a name="p186206524367"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="p1462035215367"><a name="p1462035215367"></a><a name="p1462035215367"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="p18620352103613"><a name="p18620352103613"></a><a name="p18620352103613"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="p9620135217365"><a name="p9620135217365"></a><a name="p9620135217365"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="p16620195219364"><a name="p16620195219364"></a><a name="p16620195219364"></a>Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font that exists in the system or the font specified by <a href="js-components-common-customizing-font.md">Custom Font Styles</a> in the family is selected as the font for the text.</p>
</td>
</tr>
<tr id="row9620155217363"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="p146201152123616"><a name="p146201152123616"></a><a name="p146201152123616"></a>line-height</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="p262035263611"><a name="p262035263611"></a><a name="p262035263611"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="p1062025219364"><a name="p1062025219364"></a><a name="p1062025219364"></a>0px</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="p16620165213368"><a name="p16620165213368"></a><a name="p16620165213368"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="p1562017529368"><a name="p1562017529368"></a><a name="p1562017529368"></a>Text line height of the selector.</p>
</td>
</tr>
<tr id="row1662035223613"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="p66201752133616"><a name="p66201752133616"></a><a name="p66201752133616"></a>column-height<sup id="sup162018529360"><a name="sup162018529360"></a><a name="sup162018529360"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="p46200529364"><a name="p46200529364"></a><a name="p46200529364"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="p1562125212366"><a name="p1562125212366"></a><a name="p1562125212366"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="p1862185217363"><a name="p1862185217363"></a><a name="p1862185217363"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="p116215526369"><a name="p116215526369"></a><a name="p116215526369"></a>Height of the selector option list.</p>
<div class="note" id="note769381335220"><a name="note769381335220"></a><a name="note769381335220"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p18693101311524"><a name="p18693101311524"></a><a name="p18693101311524"></a></p>
</div></div>
</td>
</tr>
</tbody>
</table>

## Events<a name="section1724215114357"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

### Common Selector<a name="section167201221192710"></a>

<a name="table1024535153519"></a>
<table><thead align="left"><tr id="row14245051103519"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="p024535163513"><a name="p024535163513"></a><a name="p024535163513"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="p20245185119357"><a name="p20245185119357"></a><a name="p20245185119357"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="p7245105143510"><a name="p7245105143510"></a><a name="p7245105143510"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1624595173510"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="p1424518517357"><a name="p1424518517357"></a><a name="p1424518517357"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="p52451351143515"><a name="p52451351143515"></a><a name="p52451351143515"></a>{ newValue: newValue, newSelected: newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="p202450516358"><a name="p202450516358"></a><a name="p202450516358"></a>Triggered when a value is selected and the OK button is clicked in the displayed pop-up window. <strong id="b13272174011538"><a name="b13272174011538"></a><a name="b13272174011538"></a>newSelected</strong> is the index.</p>
</td>
</tr>
<tr id="row152451751123518"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="p13245251133518"><a name="p13245251133518"></a><a name="p13245251133518"></a>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="p52457518356"><a name="p52457518356"></a><a name="p52457518356"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="p1724618510355"><a name="p1724618510355"></a><a name="p1724618510355"></a>Triggered when the cancel button is clicked.</p>
</td>
</tr>
</tbody>
</table>

### Date Selector<a name="section161113322714"></a>

<a name="table424655112352"></a>
<table><thead align="left"><tr id="row7246155163518"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="p02465511352"><a name="p02465511352"></a><a name="p02465511352"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="p7246351143517"><a name="p7246351143517"></a><a name="p7246351143517"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="p424665133514"><a name="p424665133514"></a><a name="p424665133514"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row82462051163517"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="p424617518356"><a name="p424617518356"></a><a name="p424617518356"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="p8246185133519"><a name="p8246185133519"></a><a name="p8246185133519"></a>{ year: year, month: month, day: day }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="p192461451183514"><a name="p192461451183514"></a><a name="p192461451183514"></a>Triggered when a value is selected and the OK button is clicked in the displayed pop-up window.</p>
<div class="note" id="note192461751103512"><a name="note192461751103512"></a><a name="note192461751103512"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p16246125163517"><a name="p16246125163517"></a><a name="p16246125163517"></a>The value of <strong id="b86982012556"><a name="b86982012556"></a><a name="b86982012556"></a>month</strong> ranges from 0 (January) to 11 (December). <sup id="sup102461651123517"><a name="sup102461651123517"></a><a name="sup102461651123517"></a>5+</sup></p>
</div></div>
</td>
</tr>
<tr id="row1424615115350"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="p1724618511355"><a name="p1724618511355"></a><a name="p1724618511355"></a>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="p52467516353"><a name="p52467516353"></a><a name="p52467516353"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="p172469518350"><a name="p172469518350"></a><a name="p172469518350"></a>Triggered when the cancel button is clicked.</p>
</td>
</tr>
</tbody>
</table>

### Date and Time Selector<a name="section15386114572710"></a>

<a name="table2024785114353"></a>
<table><thead align="left"><tr id="row2247551163520"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="p824775114357"><a name="p824775114357"></a><a name="p824775114357"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="p1324775113359"><a name="p1324775113359"></a><a name="p1324775113359"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="p224785143516"><a name="p224785143516"></a><a name="p224785143516"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row192475517358"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="p724705119351"><a name="p724705119351"></a><a name="p724705119351"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="p5247175116352"><a name="p5247175116352"></a><a name="p5247175116352"></a>{ year: year, month: month, day: day,  hour: hour, minute: minute}</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="p13247155111354"><a name="p13247155111354"></a><a name="p13247155111354"></a>Triggered when a value is selected and the OK button is clicked in the displayed pop-up window.</p>
</td>
</tr>
<tr id="row172475516357"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="p024755117352"><a name="p024755117352"></a><a name="p024755117352"></a>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="p1524775113519"><a name="p1524775113519"></a><a name="p1524775113519"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="p102472518354"><a name="p102472518354"></a><a name="p102472518354"></a>Triggered when the cancel button is clicked.</p>
</td>
</tr>
</tbody>
</table>

### Time Selector<a name="section17835159152813"></a>

<a name="table102472051113519"></a>
<table><thead align="left"><tr id="row162481151143512"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="p18248145153511"><a name="p18248145153511"></a><a name="p18248145153511"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="p1924810511351"><a name="p1924810511351"></a><a name="p1924810511351"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="p152481851103514"><a name="p152481851103514"></a><a name="p152481851103514"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row82481516354"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="p824812519355"><a name="p824812519355"></a><a name="p824812519355"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="p5248115183512"><a name="p5248115183512"></a><a name="p5248115183512"></a>{ hour: hour, minute: minute, [second: second] }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="p824811519353"><a name="p824811519353"></a><a name="p824811519353"></a>Triggered when a value is selected and the OK button is clicked in the displayed pop-up window. If <strong id="b793820412016"><a name="b793820412016"></a><a name="b793820412016"></a>containsecond</strong> is set to true, value contains seconds.</p>
</td>
</tr>
<tr id="row3248135118354"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="p12249165113512"><a name="p12249165113512"></a><a name="p12249165113512"></a>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="p15249105114351"><a name="p15249105114351"></a><a name="p15249105114351"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="p1249145115358"><a name="p1249145115358"></a><a name="p1249145115358"></a>Triggered when the cancel button is clicked.</p>
</td>
</tr>
</tbody>
</table>

### Multi-Column Text Selector<a name="section126981922162818"></a>

<a name="table14249251153519"></a>
<table><thead align="left"><tr id="row152491451133516"><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.4.1.1"><p id="p202497516355"><a name="p202497516355"></a><a name="p202497516355"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="36.9%" id="mcps1.1.4.1.2"><p id="p17249351103515"><a name="p17249351103515"></a><a name="p17249351103515"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="49.13%" id="mcps1.1.4.1.3"><p id="p11249185111354"><a name="p11249185111354"></a><a name="p11249185111354"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row13249351183510"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.4.1.1 "><p id="p1524916515353"><a name="p1524916515353"></a><a name="p1524916515353"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="36.9%" headers="mcps1.1.4.1.2 "><p id="p1249195111352"><a name="p1249195111352"></a><a name="p1249195111352"></a>{ newValue: [newValue1, newValue2, newValue3, …], newSelected:[newSelected1, newSelected2, newSelected3, …] }</p>
</td>
<td class="cellrowborder" valign="top" width="49.13%" headers="mcps1.1.4.1.3 "><p id="p10250165119356"><a name="p10250165119356"></a><a name="p10250165119356"></a>Triggered when an item is selected and the OK button is clicked in the displayed pop-up window.</p>
<a name="ul1425045115352"></a><a name="ul1425045115352"></a><ul id="ul1425045115352"><li><strong id="b0626192372512"><a name="b0626192372512"></a><a name="b0626192372512"></a>newValue</strong> is an array consisting of the values of the selected items.</li><li><strong id="b1290181522710"><a name="b1290181522710"></a><a name="b1290181522710"></a>newSelected</strong> is an array consisting of the indexes of the selected items. The lengths of <strong id="b142032033192714"><a name="b142032033192714"></a><a name="b142032033192714"></a>newValue</strong> and <strong id="b131696406270"><a name="b131696406270"></a><a name="b131696406270"></a>newSelected</strong> are the same as the length of <strong id="b49772553275"><a name="b49772553275"></a><a name="b49772553275"></a>range</strong>.</li></ul>
</td>
</tr>
<tr id="row325015143518"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.4.1.1 "><p id="p8250205119359"><a name="p8250205119359"></a><a name="p8250205119359"></a>columnchange</p>
</td>
<td class="cellrowborder" valign="top" width="36.9%" headers="mcps1.1.4.1.2 "><p id="p1325015111351"><a name="p1325015111351"></a><a name="p1325015111351"></a>{ column: column, newValue: newValue, newSelected: newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="49.13%" headers="mcps1.1.4.1.3 "><p id="p5250115112351"><a name="p5250115112351"></a><a name="p5250115112351"></a>Triggered when the value of a column in the multi-column selector changes.</p>
<a name="ul025095133520"></a><a name="ul025095133520"></a><ul id="ul025095133520"><li><strong id="b1266741291"><a name="b1266741291"></a><a name="b1266741291"></a>column</strong> indicates the column whose value has changed.</li><li><strong id="b1657817287298"><a name="b1657817287298"></a><a name="b1657817287298"></a>newValue</strong> indicates the selected value.</li><li><strong id="b0186105592917"><a name="b0186105592917"></a><a name="b0186105592917"></a>newSelected</strong> indicates the index of the selected value.</li></ul>
</td>
</tr>
<tr id="row1250651143510"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.4.1.1 "><p id="p62501519350"><a name="p62501519350"></a><a name="p62501519350"></a>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="36.9%" headers="mcps1.1.4.1.2 "><p id="p725015517358"><a name="p725015517358"></a><a name="p725015517358"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="49.13%" headers="mcps1.1.4.1.3 "><p id="p325017519359"><a name="p325017519359"></a><a name="p325017519359"></a>Triggered when the cancel button is clicked.</p>
</td>
</tr>
</tbody>
</table>

## Methods<a name="section47669296127"></a>

In addition to the methods in  [Universal Methods](js-components-common-methods.md), the following events are supported.

<a name="t26fe2ddff8674cc38a3a1ec490b76e2f"></a>
<table><thead align="left"><tr id="r237544a789f74f4599b0688cdb75239a"><th class="cellrowborder" valign="top" width="23%" id="mcps1.1.4.1.1"><p id="a897dc10a0e4e45bc94f02c558c679435"><a name="a897dc10a0e4e45bc94f02c558c679435"></a><a name="a897dc10a0e4e45bc94f02c558c679435"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="32%" id="mcps1.1.4.1.2"><p id="ac86c6eca347b48e9a749143ecf54f38f"><a name="ac86c6eca347b48e9a749143ecf54f38f"></a><a name="ac86c6eca347b48e9a749143ecf54f38f"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45%" id="mcps1.1.4.1.3"><p id="a0050d08b0c5744de88990d92ef35d3b1"><a name="a0050d08b0c5744de88990d92ef35d3b1"></a><a name="a0050d08b0c5744de88990d92ef35d3b1"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="r08b3c58c981c42a390dc730286c9ce95"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p id="a6385a8ec6d534f7698eaf47b265bec85"><a name="a6385a8ec6d534f7698eaf47b265bec85"></a><a name="a6385a8ec6d534f7698eaf47b265bec85"></a>show</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p id="p178497012101"><a name="p178497012101"></a><a name="p178497012101"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p id="p384919011103"><a name="p384919011103"></a><a name="p384919011103"></a>Displays the picker.</p>
</td>
</tr>
</tbody>
</table>

## Example Code<a name="section11956342165513"></a>

```
<!-- xxx.hml -->
<div class="container">
  <select @change="selectChange">
        <option value="{{ item }}" for="item in selectList">
            {{ item }}
        </option>
  </select>
  <picker id="picker0" type="text" value="{{textvalue}}" selected="{{textselect}}" range="{{rangetext}}" onchange="textonchange"
    oncancel="textoncancel" class="pickertext"  "></picker>

  <picker id="picker1" type="date" value="{{datevalue}}" start="2002-2-5" end="2030-6-5" selected="{{dateselect}}" lunarswitch="true"
    onchange="dateonchange" oncancel="dateoncancel" class="pickerdate" show="false"></picker>

  <picker id="picker2" type="time" value="{{timevalue}}" containsecond="{{containsecond}}" selected="{{timeselect}}" hours="12"
    onchange="timeonchange" oncancel="timeoncancel" class="pickertime" show="false"></picker>

  <picker id="picker3" type="datetime" value="{{datetimevalue}}" selected="{{datetimeselect}}" hours="24" lunarswitch="true"
    onchange="datetimeonchange" oncancel="datetimeoncancel" class="pickerdatetime" show="false"></picker>

  <picker id="picker4" type="multi-text" value="{{multitextvalue}}" columns="3" range="{{multitext}}" selected="{{multitextselect}}"
    onchange="multitextonchange" oncancel="multitextoncancel" class="pickermuitl" show="false"></picker>
</div>
```

```
/* xxx.css */
.container {    
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
 picker{
  width:60%;
  height:80px;
  border-radius:20px;
  text-color:white;
  font-size:15px;
  background-color:#4747e3;
  margin-left:20%;
}
 select{
  background-color: #efecec;
  height: 50px;
  width: 60%;
  margin-left: 20%;
  margin-top: 300px;
  margin-bottom: 50px;
  font-size: 22px;
}
```

```
// xxx.js
import router from '@system.router';
import prompt from '@system.prompt';
export default {
  data: {    
    selectList:["text","data","time","datetime","multitext"],
    rangetext:['15', "20", "25"],    
    multitext:[["a", "b", "c"], ["e", "f", "g"], ["h", "i"], ["k", "l", "m"]],    
    textvalue:'default textvalue',    
    datevalue:'default datevalue',    
    timevalue:'default timevalue',    
    datetimevalue:'default datetimevalue',    
    multitextvalue:'default multitextvalue',    
    containsecond:true,    
    multitextselect:[1,2,0],    
    datetimeselect:'2012-5-6-11-25',    
    timeselect:'11:22:30',    
    dateselect:'2021-3-2',    
    textselect:'2'
  },
  selectChange(e){
        for(let i = 0;i<this.selectList.length;i++){
            if(e.newValue == this.selectList[i]){
                this.$element("picker"+i).show();
            }
        }
    },
  textonchange(e) {    
    this.textvalue = e.newValue;    
    prompt.showToast({ message:"text:"+e.newValue+",newSelected:"+e.newSelected })
  },
  textoncancel(e) {    
    prompt.showToast({ message:"text: textoncancel" })
  },
  dateonchange(e) {    
    this.datevalue = e.year + "-" + e.month + "-" + e.day;    
    prompt.showToast({ message:"date:"+e.year+"-"+(e.month+1)+"-"+e.day })
  },
  dateoncancel() {    
    prompt.showToast({ message:"date: dateoncancel" })
  },
  timeonchange(e) {    
    if(this.containsecond){        
      this.timevalue=e.hour+":"+e.minute+":"+e.second;        
      prompt.showToast({ message:"Time:" + e.hour + ":" + e.minute + ":" + e.second })
    } else {        
      this.timevalue=e.hour+":"+e.minute;        
      prompt.showToast({ message:"Time:" + e.hour + ":" + e.minute })
    }},
  timeoncancel() {    
    prompt.showToast({ message:"timeoncancel" })
  },
  datetimeonchange(e) {    
    this.datetimevalue=e.year+"-"+e.month+"-"+e.day+" "+e.hour+":"+e.minute;    
    prompt.showToast({ message:"Time:"+(e.month+1)+"-"+e.day+" "+e.hour+":"+e.minute })
  },
  datetimeoncancel() {    
    prompt.showToast({ message:"datetimeoncancel" })
  },
  multitextonchange(e) {    
    this.multitextvalue=e.newValue;    
    prompt.showToast({ message:"Multi-column text change" + e.newValue })
  },
  multitextoncancel() {    
    prompt.showToast({ message:"multitextoncancel" })
  },
  popup_picker() {    
    this.$element("picker_text").show();
  },
}
```

![](figures/mmmm.gif)

