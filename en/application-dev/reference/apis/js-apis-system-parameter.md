# systemParameter<a name="EN-US_TOPIC_0000001094819718"></a>

## Modules to Import<a name="section370mcpsimp"></a>

```
import parameter from '@ohos.systemParameter'
```

## Required Permissions<a name="section373mcpsimp"></a>

None

## parameter.getSync<a name="section3381192816421"></a>

getSync\(key: string, def?: string\)

Gets the value of the attribute with the specified key.

**Parameters**

<a name="table14473145217456"></a>
<table><thead align="left"><tr id="row1052235294518"><th class="cellrowborder" valign="top" width="11.219999999999999%" id="mcps1.1.5.1.1"><p id="p15522195234514"><a name="p15522195234514"></a><a name="p15522195234514"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p id="p1852285215454"><a name="p1852285215454"></a><a name="p1852285215454"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.16%" id="mcps1.1.5.1.3"><p id="p125221452154514"><a name="p125221452154514"></a><a name="p125221452154514"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="67.35%" id="mcps1.1.5.1.4"><p id="p552214521459"><a name="p552214521459"></a><a name="p552214521459"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row165221352124511"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="p85221523450"><a name="p85221523450"></a><a name="p85221523450"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="p1452275204516"><a name="p1452275204516"></a><a name="p1452275204516"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.16%" headers="mcps1.1.5.1.3 "><p id="p1152275224511"><a name="p1152275224511"></a><a name="p1152275224511"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="67.35%" headers="mcps1.1.5.1.4 "><p id="p175228526455"><a name="p175228526455"></a><a name="p175228526455"></a>Key of the system attribute</p>
</td>
</tr>
<tr id="row12676182816132"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="p567652819135"><a name="p567652819135"></a><a name="p567652819135"></a>def</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="p156769289137"><a name="p156769289137"></a><a name="p156769289137"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.16%" headers="mcps1.1.5.1.3 "><p id="p96763289138"><a name="p96763289138"></a><a name="p96763289138"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="67.35%" headers="mcps1.1.5.1.4 "><p id="p16761628121319"><a name="p16761628121319"></a><a name="p16761628121319"></a>Default value</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="table1926815519481"></a>
<table><thead align="left"><tr id="row92682052486"><th class="cellrowborder" valign="top" width="16.46%" id="mcps1.1.3.1.1"><p id="p326920564820"><a name="p326920564820"></a><a name="p326920564820"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="83.54%" id="mcps1.1.3.1.2"><p id="p1126911514486"><a name="p1126911514486"></a><a name="p1126911514486"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row12269165164818"><td class="cellrowborder" valign="top" width="16.46%" headers="mcps1.1.3.1.1 "><p id="p12269145144816"><a name="p12269145144816"></a><a name="p12269145144816"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="83.54%" headers="mcps1.1.3.1.2 "><p id="p026955154811"><a name="p026955154811"></a><a name="p026955154811"></a>System attribute value. If the specified key does not exist, the default value is returned. If no default value has been set, an empty string will be returned.</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
try {
    var info = parameter.getSync("test.parameter.key");
    console.log(JSON.stringify(info));
}catch(e){
    console.log("getSync unexpected error: " + e);
}
```

## parameter.get<a name="section19655131534912"></a>

get\(key: string, callback: AsyncCallback<string\>\)

Gets the value of the attribute with the specified key.

**Parameters**

<a name="table76561515144911"></a>
<table><thead align="left"><tr id="row165611155491"><th class="cellrowborder" valign="top" width="10.979547900968782%" id="mcps1.1.5.1.1"><p id="p146561115114920"><a name="p146561115114920"></a><a name="p146561115114920"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="19.806243272335845%" id="mcps1.1.5.1.2"><p id="p2656111554911"><a name="p2656111554911"></a><a name="p2656111554911"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="5.930130149721108%" id="mcps1.1.5.1.3"><p id="p12656121504916"><a name="p12656121504916"></a><a name="p12656121504916"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="63.28407867697427%" id="mcps1.1.5.1.4"><p id="p14656415104917"><a name="p14656415104917"></a><a name="p14656415104917"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row46561715194912"><td class="cellrowborder" valign="top" width="10.979547900968782%" headers="mcps1.1.5.1.1 "><p id="p11656715154910"><a name="p11656715154910"></a><a name="p11656715154910"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="19.806243272335845%" headers="mcps1.1.5.1.2 "><p id="p66561515204914"><a name="p66561515204914"></a><a name="p66561515204914"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.930130149721108%" headers="mcps1.1.5.1.3 "><p id="p065691514917"><a name="p065691514917"></a><a name="p065691514917"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="63.28407867697427%" headers="mcps1.1.5.1.4 "><p id="p8656111544920"><a name="p8656111544920"></a><a name="p8656111544920"></a>Key of the system attribute</p>
</td>
</tr>
<tr id="row1263818717506"><td class="cellrowborder" valign="top" width="10.979547900968782%" headers="mcps1.1.5.1.1 "><p id="p663817735014"><a name="p663817735014"></a><a name="p663817735014"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.806243272335845%" headers="mcps1.1.5.1.2 "><p id="p12638872501"><a name="p12638872501"></a><a name="p12638872501"></a>AsyncCallback&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="5.930130149721108%" headers="mcps1.1.5.1.3 "><p id="p863847125019"><a name="p863847125019"></a><a name="p863847125019"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="63.28407867697427%" headers="mcps1.1.5.1.4 "><p id="p16638207205014"><a name="p16638207205014"></a><a name="p16638207205014"></a>Callback function</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
try {
    parameter.get("test.parameter.key", function (err, data) {
    if (err == undefined) {
        console.log("get test.parameter.key value success:" + data)
    } else {
        console.log(" get test.parameter.key value err:" + err.code)
    }});
}catch(e){
    console.log("get unexpected error: " + e);
}
```

## parameter.get<a name="section045334733915"></a>

get\(key: string, def: string, callback: AsyncCallback<string\>\)

Gets the value of the attribute with the specified key.

**Parameters**

<a name="table1545354713914"></a>
<table><thead align="left"><tr id="row11453184743918"><th class="cellrowborder" valign="top" width="11.219999999999999%" id="mcps1.1.5.1.1"><p id="p045394710392"><a name="p045394710392"></a><a name="p045394710392"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.61%" id="mcps1.1.5.1.2"><p id="p7453647113916"><a name="p7453647113916"></a><a name="p7453647113916"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.18%" id="mcps1.1.5.1.3"><p id="p745374763917"><a name="p745374763917"></a><a name="p745374763917"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.99%" id="mcps1.1.5.1.4"><p id="p13453847103918"><a name="p13453847103918"></a><a name="p13453847103918"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2453174773917"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="p1545413471396"><a name="p1545413471396"></a><a name="p1545413471396"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="p145416477394"><a name="p145416477394"></a><a name="p145416477394"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.18%" headers="mcps1.1.5.1.3 "><p id="p15454124783916"><a name="p15454124783916"></a><a name="p15454124783916"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.99%" headers="mcps1.1.5.1.4 "><p id="p645454720398"><a name="p645454720398"></a><a name="p645454720398"></a>Key of the system attribute</p>
</td>
</tr>
<tr id="row1586513411413"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="p4866114116410"><a name="p4866114116410"></a><a name="p4866114116410"></a>def</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="p286618418410"><a name="p286618418410"></a><a name="p286618418410"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.18%" headers="mcps1.1.5.1.3 "><p id="p148664412416"><a name="p148664412416"></a><a name="p148664412416"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.99%" headers="mcps1.1.5.1.4 "><p id="p188663413413"><a name="p188663413413"></a><a name="p188663413413"></a>Default value</p>
</td>
</tr>
<tr id="row34546477396"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="p1454134712395"><a name="p1454134712395"></a><a name="p1454134712395"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="p19454047123915"><a name="p19454047123915"></a><a name="p19454047123915"></a>AsyncCallback&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.18%" headers="mcps1.1.5.1.3 "><p id="p445454783919"><a name="p445454783919"></a><a name="p445454783919"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.99%" headers="mcps1.1.5.1.4 "><p id="p1454124713391"><a name="p1454124713391"></a><a name="p1454124713391"></a>Callback function</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
try {
    parameter.get("test.parameter.key", "default", function (err, data) {
        if (err == undefined) {
            console.log("get test.parameter.key value success:" + data)
        } else {
            console.log(" get test.parameter.key value err:" + err.code)
        }
    });
}catch(e){
    console.log("get unexpected error:" + e)
}
```

## parameter.get<a name="section10288162818402"></a>

get\(key: string, def?: string\)

Gets the value of the attribute with the specified key.

**Parameters**

<a name="table1028882844020"></a>
<table><thead align="left"><tr id="row132880285407"><th class="cellrowborder" valign="top" width="11.219999999999999%" id="mcps1.1.5.1.1"><p id="p1828872816408"><a name="p1828872816408"></a><a name="p1828872816408"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p id="p1328810281407"><a name="p1328810281407"></a><a name="p1328810281407"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.16%" id="mcps1.1.5.1.3"><p id="p72881628154019"><a name="p72881628154019"></a><a name="p72881628154019"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="67.35%" id="mcps1.1.5.1.4"><p id="p16288172814407"><a name="p16288172814407"></a><a name="p16288172814407"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row52888288404"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="p4288128194010"><a name="p4288128194010"></a><a name="p4288128194010"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="p1528817286404"><a name="p1528817286404"></a><a name="p1528817286404"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.16%" headers="mcps1.1.5.1.3 "><p id="p62895286409"><a name="p62895286409"></a><a name="p62895286409"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="67.35%" headers="mcps1.1.5.1.4 "><p id="p4289142812409"><a name="p4289142812409"></a><a name="p4289142812409"></a>Key of the system attribute</p>
</td>
</tr>
<tr id="row828962817403"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="p1289152874016"><a name="p1289152874016"></a><a name="p1289152874016"></a>def</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="p228922815406"><a name="p228922815406"></a><a name="p228922815406"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.16%" headers="mcps1.1.5.1.3 "><p id="p19289428184020"><a name="p19289428184020"></a><a name="p19289428184020"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="67.35%" headers="mcps1.1.5.1.4 "><p id="p1428942818407"><a name="p1428942818407"></a><a name="p1428942818407"></a>Default value</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="table1644156114210"></a>
<table><thead align="left"><tr id="row16441756114213"><th class="cellrowborder" valign="top" width="16.46%" id="mcps1.1.3.1.1"><p id="p564413569429"><a name="p564413569429"></a><a name="p564413569429"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="83.54%" id="mcps1.1.3.1.2"><p id="p2644135684219"><a name="p2644135684219"></a><a name="p2644135684219"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row126441156204215"><td class="cellrowborder" valign="top" width="16.46%" headers="mcps1.1.3.1.1 "><p id="p146441656144211"><a name="p146441656144211"></a><a name="p146441656144211"></a>Promise&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="83.54%" headers="mcps1.1.3.1.2 "><p id="p2644115664211"><a name="p2644115664211"></a><a name="p2644115664211"></a>Promise, which is used to obtain the result asynchronously</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
try {
    var p = parameter.get("test.parameter.key");
    p.then(function (value) {
        console.log("get test.parameter.key success: " + value);
    }).catch(function (err) {
        console.log("get test.parameter.key error: " + err.code);
    });
}catch(e){
    console.log("get unexpected error: " + e);
}
```

## parameter.setSync<a name="section63102185493"></a>

setSync\(key: string, value: string\)

Sets a value for the attribute with the specified key.

**Parameters**

<a name="table15310418174916"></a>
<table><thead align="left"><tr id="row15311121811495"><th class="cellrowborder" valign="top" width="11.219999999999999%" id="mcps1.1.5.1.1"><p id="p19311101814493"><a name="p19311101814493"></a><a name="p19311101814493"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p id="p18311118204915"><a name="p18311118204915"></a><a name="p18311118204915"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.16%" id="mcps1.1.5.1.3"><p id="p11311131894919"><a name="p11311131894919"></a><a name="p11311131894919"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="67.35%" id="mcps1.1.5.1.4"><p id="p1131161804919"><a name="p1131161804919"></a><a name="p1131161804919"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row183114182499"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="p12311141816498"><a name="p12311141816498"></a><a name="p12311141816498"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="p931121804918"><a name="p931121804918"></a><a name="p931121804918"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.16%" headers="mcps1.1.5.1.3 "><p id="p10311161874910"><a name="p10311161874910"></a><a name="p10311161874910"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="67.35%" headers="mcps1.1.5.1.4 "><p id="p531161819498"><a name="p531161819498"></a><a name="p531161819498"></a>Key of the system attribute</p>
</td>
</tr>
<tr id="row11371940105211"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="p713019471526"><a name="p713019471526"></a><a name="p713019471526"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="p1213013472526"><a name="p1213013472526"></a><a name="p1213013472526"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.16%" headers="mcps1.1.5.1.3 "><p id="p18130104735216"><a name="p18130104735216"></a><a name="p18130104735216"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="67.35%" headers="mcps1.1.5.1.4 "><p id="p141301747155214"><a name="p141301747155214"></a><a name="p141301747155214"></a>System attribute value to set</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
try {
    parameter.setSync("test.parameter.key", "default");
}catch(e){
    console.log("set unexpected error: " + e);
}
```

## parameter.set<a name="section18770184911197"></a>

set\(key: string, value: string, callback: AsyncCallback<void\>\)

Sets a value for the attribute with the specified key.

**Parameters**

<a name="table97701049101914"></a>
<table><thead align="left"><tr id="row977164981919"><th class="cellrowborder" valign="top" width="10.93141075604053%" id="mcps1.1.5.1.1"><p id="p57712497198"><a name="p57712497198"></a><a name="p57712497198"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.630943102104442%" id="mcps1.1.5.1.2"><p id="p1077184911195"><a name="p1077184911195"></a><a name="p1077184911195"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.819953234606392%" id="mcps1.1.5.1.3"><p id="p8771184913196"><a name="p8771184913196"></a><a name="p8771184913196"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="65.61769290724864%" id="mcps1.1.5.1.4"><p id="p1677116491196"><a name="p1677116491196"></a><a name="p1677116491196"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1771194916198"><td class="cellrowborder" valign="top" width="10.93141075604053%" headers="mcps1.1.5.1.1 "><p id="p127713497196"><a name="p127713497196"></a><a name="p127713497196"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="16.630943102104442%" headers="mcps1.1.5.1.2 "><p id="p1777174912196"><a name="p1777174912196"></a><a name="p1777174912196"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="p577164914199"><a name="p577164914199"></a><a name="p577164914199"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="65.61769290724864%" headers="mcps1.1.5.1.4 "><p id="p27711349121916"><a name="p27711349121916"></a><a name="p27711349121916"></a>Key of the system attribute</p>
</td>
</tr>
<tr id="row117711549201917"><td class="cellrowborder" valign="top" width="10.93141075604053%" headers="mcps1.1.5.1.1 "><p id="p87711149111911"><a name="p87711149111911"></a><a name="p87711149111911"></a>def</p>
</td>
<td class="cellrowborder" valign="top" width="16.630943102104442%" headers="mcps1.1.5.1.2 "><p id="p1977134961915"><a name="p1977134961915"></a><a name="p1977134961915"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="p13771204911918"><a name="p13771204911918"></a><a name="p13771204911918"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="65.61769290724864%" headers="mcps1.1.5.1.4 "><p id="p1177117490192"><a name="p1177117490192"></a><a name="p1177117490192"></a>Default value</p>
</td>
</tr>
<tr id="row17771124917194"><td class="cellrowborder" valign="top" width="10.93141075604053%" headers="mcps1.1.5.1.1 "><p id="p207728494195"><a name="p207728494195"></a><a name="p207728494195"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="16.630943102104442%" headers="mcps1.1.5.1.2 "><p id="p2077274961913"><a name="p2077274961913"></a><a name="p2077274961913"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="p15772184914197"><a name="p15772184914197"></a><a name="p15772184914197"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="65.61769290724864%" headers="mcps1.1.5.1.4 "><p id="p1977244913198"><a name="p1977244913198"></a><a name="p1977244913198"></a>Callback function.</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
try {
    parameter.set("test.parameter.key", "testValue", function (err, data) {
    if (err == undefined) {
        console.log("set test.parameter.key value success :" + data)
    } else {
        console.log("set test.parameter.key value err:" + err.code)
    }});
}catch(e){
    console.log("set unexpected error: " + e);
}
```

## parameter.set<a name="section187724496193"></a>

set\(key: string, def?: string\)

Sets a value for the attribute with the specified key.

**Parameters**

<a name="table17724498192"></a>
<table><thead align="left"><tr id="row277217498197"><th class="cellrowborder" valign="top" width="11.219999999999999%" id="mcps1.1.5.1.1"><p id="p57724491193"><a name="p57724491193"></a><a name="p57724491193"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p id="p6772134931918"><a name="p6772134931918"></a><a name="p6772134931918"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.16%" id="mcps1.1.5.1.3"><p id="p577210499193"><a name="p577210499193"></a><a name="p577210499193"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="67.35%" id="mcps1.1.5.1.4"><p id="p11773124941911"><a name="p11773124941911"></a><a name="p11773124941911"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row677384921911"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="p677317495199"><a name="p677317495199"></a><a name="p677317495199"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="p177731049131913"><a name="p177731049131913"></a><a name="p177731049131913"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.16%" headers="mcps1.1.5.1.3 "><p id="p777324918197"><a name="p777324918197"></a><a name="p777324918197"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="67.35%" headers="mcps1.1.5.1.4 "><p id="p13773849191918"><a name="p13773849191918"></a><a name="p13773849191918"></a>Key of the system attribute</p>
</td>
</tr>
<tr id="row13773114921911"><td class="cellrowborder" valign="top" width="11.219999999999999%" headers="mcps1.1.5.1.1 "><p id="p1777374951915"><a name="p1777374951915"></a><a name="p1777374951915"></a>def</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="p1877394921916"><a name="p1877394921916"></a><a name="p1877394921916"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.16%" headers="mcps1.1.5.1.3 "><p id="p1177314917194"><a name="p1177314917194"></a><a name="p1177314917194"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="67.35%" headers="mcps1.1.5.1.4 "><p id="p7773204917199"><a name="p7773204917199"></a><a name="p7773204917199"></a>Default value</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="table14773154913191"></a>
<table><thead align="left"><tr id="row877314991912"><th class="cellrowborder" valign="top" width="16.46%" id="mcps1.1.3.1.1"><p id="p1077313493199"><a name="p1077313493199"></a><a name="p1077313493199"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="83.54%" id="mcps1.1.3.1.2"><p id="p1677411498195"><a name="p1677411498195"></a><a name="p1677411498195"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1977413496194"><td class="cellrowborder" valign="top" width="16.46%" headers="mcps1.1.3.1.1 "><p id="p67742498197"><a name="p67742498197"></a><a name="p67742498197"></a>Promise&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="83.54%" headers="mcps1.1.3.1.2 "><p id="p4774164916199"><a name="p4774164916199"></a><a name="p4774164916199"></a>Promise, which is used to obtain the result asynchronously</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
try {
    var p = para.set("test.parameter.key", "testValue");
    p.then(function (value) {
        console.log("set test.parameter.key success: " + value);
    }).catch(function (err) {
        console.log(" set test.parameter.key error: " + err.code);
    });
}catch(e){
    console.log("set unexpected error: " + e);
}
```

