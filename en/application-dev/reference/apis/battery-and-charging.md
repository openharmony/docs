# Battery and Charging<a name="EN-US_TOPIC_0000001115974766"></a>

## Modules to Import<a name="en-us_topic_0000001100730486_section199443271307"></a>

```
import batteryInfo from '@ohos.batteryinfo.d.ts'
```

## BatteryInfo<a name="en-us_topic_0000001100730486_section1853612361618"></a>

Describes battery information.

<a name="en-us_topic_0000001100730486_table20633101642315"></a>
<table><thead align="left"><tr id="en-us_topic_0000001100730486_row663331618238"><th class="cellrowborder" valign="top" width="20.13%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001100730486_a3d0fc780cc904c1cbab7991251622f65"><a name="en-us_topic_0000001100730486_a3d0fc780cc904c1cbab7991251622f65"></a><a name="en-us_topic_0000001100730486_a3d0fc780cc904c1cbab7991251622f65"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.5%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001100730486_p1961191632214"><a name="en-us_topic_0000001100730486_p1961191632214"></a><a name="en-us_topic_0000001100730486_p1961191632214"></a>Readable/Writable</p>
</th>
<th class="cellrowborder" valign="top" width="23.29%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001100730486_ac1f1afc248084f8fb51242b648bc34de"><a name="en-us_topic_0000001100730486_ac1f1afc248084f8fb51242b648bc34de"></a><a name="en-us_topic_0000001100730486_ac1f1afc248084f8fb51242b648bc34de"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="43.08%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001100730486_afec895de33f94e3c87ee7acc20190a17"><a name="en-us_topic_0000001100730486_afec895de33f94e3c87ee7acc20190a17"></a><a name="en-us_topic_0000001100730486_afec895de33f94e3c87ee7acc20190a17"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001100730486_row188481425182510"><td class="cellrowborder" valign="top" width="20.13%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001100730486_p938441717208"><a name="en-us_topic_0000001100730486_p938441717208"></a><a name="en-us_topic_0000001100730486_p938441717208"></a>batterySOC</p>
</td>
<td class="cellrowborder" valign="top" width="13.5%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001100730486_p1396118166228"><a name="en-us_topic_0000001100730486_p1396118166228"></a><a name="en-us_topic_0000001100730486_p1396118166228"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="23.29%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001100730486_p6354841201511"><a name="en-us_topic_0000001100730486_p6354841201511"></a><a name="en-us_topic_0000001100730486_p6354841201511"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="43.08%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001100730486_p103961315181818"><a name="en-us_topic_0000001100730486_p103961315181818"></a><a name="en-us_topic_0000001100730486_p103961315181818"></a>Battery state of charge (SoC) of the current device</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row0461622112513"><td class="cellrowborder" valign="top" width="20.13%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001100730486_p5354124120158"><a name="en-us_topic_0000001100730486_p5354124120158"></a><a name="en-us_topic_0000001100730486_p5354124120158"></a>chargingStatus</p>
</td>
<td class="cellrowborder" valign="top" width="13.5%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001100730486_p159621168228"><a name="en-us_topic_0000001100730486_p159621168228"></a><a name="en-us_topic_0000001100730486_p159621168228"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="23.29%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001100730486_p10354541181520"><a name="en-us_topic_0000001100730486_p10354541181520"></a><a name="en-us_topic_0000001100730486_p10354541181520"></a>BatteryChargeState</p>
</td>
<td class="cellrowborder" valign="top" width="43.08%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001100730486_p238673617568"><a name="en-us_topic_0000001100730486_p238673617568"></a><a name="en-us_topic_0000001100730486_p238673617568"></a>Battery charging status of the current device</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row09415619242"><td class="cellrowborder" valign="top" width="20.13%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001100730486_p1435434117152"><a name="en-us_topic_0000001100730486_p1435434117152"></a><a name="en-us_topic_0000001100730486_p1435434117152"></a>healthStatus</p>
</td>
<td class="cellrowborder" valign="top" width="13.5%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001100730486_p1796210169224"><a name="en-us_topic_0000001100730486_p1796210169224"></a><a name="en-us_topic_0000001100730486_p1796210169224"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="23.29%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001100730486_p3354114131518"><a name="en-us_topic_0000001100730486_p3354114131518"></a><a name="en-us_topic_0000001100730486_p3354114131518"></a>BatteryHealthState</p>
</td>
<td class="cellrowborder" valign="top" width="43.08%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001100730486_p1365563875614"><a name="en-us_topic_0000001100730486_p1365563875614"></a><a name="en-us_topic_0000001100730486_p1365563875614"></a>Battery health state of the current device</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row56471975243"><td class="cellrowborder" valign="top" width="20.13%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001100730486_p1835534116158"><a name="en-us_topic_0000001100730486_p1835534116158"></a><a name="en-us_topic_0000001100730486_p1835534116158"></a>pluggedType</p>
</td>
<td class="cellrowborder" valign="top" width="13.5%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001100730486_p18962416132211"><a name="en-us_topic_0000001100730486_p18962416132211"></a><a name="en-us_topic_0000001100730486_p18962416132211"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="23.29%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001100730486_p235584114153"><a name="en-us_topic_0000001100730486_p235584114153"></a><a name="en-us_topic_0000001100730486_p235584114153"></a>BatteryPluggedType</p>
</td>
<td class="cellrowborder" valign="top" width="43.08%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001100730486_p19264101622016"><a name="en-us_topic_0000001100730486_p19264101622016"></a><a name="en-us_topic_0000001100730486_p19264101622016"></a>Charger type of the current device</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row4536161934520"><td class="cellrowborder" valign="top" width="20.13%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001100730486_p14355174151513"><a name="en-us_topic_0000001100730486_p14355174151513"></a><a name="en-us_topic_0000001100730486_p14355174151513"></a>voltage</p>
</td>
<td class="cellrowborder" valign="top" width="13.5%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001100730486_p296261662212"><a name="en-us_topic_0000001100730486_p296261662212"></a><a name="en-us_topic_0000001100730486_p296261662212"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="23.29%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001100730486_p7355741201519"><a name="en-us_topic_0000001100730486_p7355741201519"></a><a name="en-us_topic_0000001100730486_p7355741201519"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="43.08%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001100730486_p127111826172018"><a name="en-us_topic_0000001100730486_p127111826172018"></a><a name="en-us_topic_0000001100730486_p127111826172018"></a>Battery voltage of the current device</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row597319245451"><td class="cellrowborder" valign="top" width="20.13%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001100730486_p153551941141517"><a name="en-us_topic_0000001100730486_p153551941141517"></a><a name="en-us_topic_0000001100730486_p153551941141517"></a>technology</p>
</td>
<td class="cellrowborder" valign="top" width="13.5%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001100730486_p17962916162217"><a name="en-us_topic_0000001100730486_p17962916162217"></a><a name="en-us_topic_0000001100730486_p17962916162217"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="23.29%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001100730486_p535514113154"><a name="en-us_topic_0000001100730486_p535514113154"></a><a name="en-us_topic_0000001100730486_p535514113154"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="43.08%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001100730486_p9298104612205"><a name="en-us_topic_0000001100730486_p9298104612205"></a><a name="en-us_topic_0000001100730486_p9298104612205"></a>Battery technology of the current device</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row4978143312456"><td class="cellrowborder" valign="top" width="20.13%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001100730486_p7355114151515"><a name="en-us_topic_0000001100730486_p7355114151515"></a><a name="en-us_topic_0000001100730486_p7355114151515"></a>batteryTemperature</p>
</td>
<td class="cellrowborder" valign="top" width="13.5%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001100730486_p14962116172215"><a name="en-us_topic_0000001100730486_p14962116172215"></a><a name="en-us_topic_0000001100730486_p14962116172215"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="23.29%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001100730486_p143551941201510"><a name="en-us_topic_0000001100730486_p143551941201510"></a><a name="en-us_topic_0000001100730486_p143551941201510"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="43.08%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001100730486_p7843573202"><a name="en-us_topic_0000001100730486_p7843573202"></a><a name="en-us_topic_0000001100730486_p7843573202"></a>Battery temperature of the current device</p>
</td>
</tr>
</tbody>
</table>

-   Example

    ```
    import batteryInfo from '@ohos.batteryInfo';
    var batterySoc = batteryInfo.batterySOC;
    ```


## Enums<a name="en-us_topic_0000001100730486_section14572171519166"></a>

## BatteryPluggedType<a name="en-us_topic_0000001100730486_section1861134715488"></a>

Enumerates charger types.

<a name="en-us_topic_0000001100730486_table144441452192814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001100730486_row12444145210288"><th class="cellrowborder" valign="top" width="31.703170317031702%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001100730486_p162914100272"><a name="en-us_topic_0000001100730486_p162914100272"></a><a name="en-us_topic_0000001100730486_p162914100272"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="35.253525352535256%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001100730486_p044416523286"><a name="en-us_topic_0000001100730486_p044416523286"></a><a name="en-us_topic_0000001100730486_p044416523286"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="33.043304330433045%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001100730486_p1044495252810"><a name="en-us_topic_0000001100730486_p1044495252810"></a><a name="en-us_topic_0000001100730486_p1044495252810"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001100730486_row18444115215284"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001100730486_p954122310283"><a name="en-us_topic_0000001100730486_p954122310283"></a><a name="en-us_topic_0000001100730486_p954122310283"></a>NONE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001100730486_p0527233288"><a name="en-us_topic_0000001100730486_p0527233288"></a><a name="en-us_topic_0000001100730486_p0527233288"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001100730486_p12372352812"><a name="en-us_topic_0000001100730486_p12372352812"></a><a name="en-us_topic_0000001100730486_p12372352812"></a>Unknown type</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row55389918289"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001100730486_p15381795285"><a name="en-us_topic_0000001100730486_p15381795285"></a><a name="en-us_topic_0000001100730486_p15381795285"></a>AC</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001100730486_p45381291281"><a name="en-us_topic_0000001100730486_p45381291281"></a><a name="en-us_topic_0000001100730486_p45381291281"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001100730486_p1953979102813"><a name="en-us_topic_0000001100730486_p1953979102813"></a><a name="en-us_topic_0000001100730486_p1953979102813"></a>AC charger</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row928621592815"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001100730486_p1328691518288"><a name="en-us_topic_0000001100730486_p1328691518288"></a><a name="en-us_topic_0000001100730486_p1328691518288"></a>USB</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001100730486_p1728616154286"><a name="en-us_topic_0000001100730486_p1728616154286"></a><a name="en-us_topic_0000001100730486_p1728616154286"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001100730486_p188591922163215"><a name="en-us_topic_0000001100730486_p188591922163215"></a><a name="en-us_topic_0000001100730486_p188591922163215"></a>USB charger</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row3954122652810"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001100730486_p1995412614284"><a name="en-us_topic_0000001100730486_p1995412614284"></a><a name="en-us_topic_0000001100730486_p1995412614284"></a>WIRELESS</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001100730486_p395402620286"><a name="en-us_topic_0000001100730486_p395402620286"></a><a name="en-us_topic_0000001100730486_p395402620286"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001100730486_p235192423214"><a name="en-us_topic_0000001100730486_p235192423214"></a><a name="en-us_topic_0000001100730486_p235192423214"></a>Wireless charger</p>
</td>
</tr>
</tbody>
</table>

## BatteryChargeState<a name="en-us_topic_0000001100730486_section629045815408"></a>

Enumerates battery charging states.

<a name="en-us_topic_0000001100730486_table1368716015365"></a>
<table><thead align="left"><tr id="en-us_topic_0000001100730486_row106884010367"><th class="cellrowborder" valign="top" width="31.703170317031702%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001100730486_p468816023615"><a name="en-us_topic_0000001100730486_p468816023615"></a><a name="en-us_topic_0000001100730486_p468816023615"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="35.253525352535256%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001100730486_p15688505362"><a name="en-us_topic_0000001100730486_p15688505362"></a><a name="en-us_topic_0000001100730486_p15688505362"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="33.043304330433045%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001100730486_p1068830103619"><a name="en-us_topic_0000001100730486_p1068830103619"></a><a name="en-us_topic_0000001100730486_p1068830103619"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001100730486_row1868880113613"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001100730486_p1392942212399"><a name="en-us_topic_0000001100730486_p1392942212399"></a><a name="en-us_topic_0000001100730486_p1392942212399"></a>NONE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001100730486_p968880103613"><a name="en-us_topic_0000001100730486_p968880103613"></a><a name="en-us_topic_0000001100730486_p968880103613"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001100730486_p16911819163919"><a name="en-us_topic_0000001100730486_p16911819163919"></a><a name="en-us_topic_0000001100730486_p16911819163919"></a>Unknown state</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row17688180173620"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001100730486_p12928922193920"><a name="en-us_topic_0000001100730486_p12928922193920"></a><a name="en-us_topic_0000001100730486_p12928922193920"></a>ENABLE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001100730486_p86893003614"><a name="en-us_topic_0000001100730486_p86893003614"></a><a name="en-us_topic_0000001100730486_p86893003614"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001100730486_p9910201913391"><a name="en-us_topic_0000001100730486_p9910201913391"></a><a name="en-us_topic_0000001100730486_p9910201913391"></a>The battery is being charged.</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row1868914011367"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001100730486_p4926152211394"><a name="en-us_topic_0000001100730486_p4926152211394"></a><a name="en-us_topic_0000001100730486_p4926152211394"></a>DISABLE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001100730486_p186891001361"><a name="en-us_topic_0000001100730486_p186891001361"></a><a name="en-us_topic_0000001100730486_p186891001361"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001100730486_p1210733413414"><a name="en-us_topic_0000001100730486_p1210733413414"></a><a name="en-us_topic_0000001100730486_p1210733413414"></a>The battery is not being charged.</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row068911018360"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001100730486_p1992542211392"><a name="en-us_topic_0000001100730486_p1992542211392"></a><a name="en-us_topic_0000001100730486_p1992542211392"></a>FULL</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001100730486_p46895023619"><a name="en-us_topic_0000001100730486_p46895023619"></a><a name="en-us_topic_0000001100730486_p46895023619"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001100730486_p3614135154120"><a name="en-us_topic_0000001100730486_p3614135154120"></a><a name="en-us_topic_0000001100730486_p3614135154120"></a>The battery is fully charged.</p>
</td>
</tr>
</tbody>
</table>

## BatteryHealthState<a name="en-us_topic_0000001100730486_section1636311513419"></a>

Enumerates battery health states.

<a name="en-us_topic_0000001100730486_table1646153519380"></a>
<table><thead align="left"><tr id="en-us_topic_0000001100730486_row1847203533813"><th class="cellrowborder" valign="top" width="31.703170317031702%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001100730486_p44743514381"><a name="en-us_topic_0000001100730486_p44743514381"></a><a name="en-us_topic_0000001100730486_p44743514381"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="35.253525352535256%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001100730486_p164783513817"><a name="en-us_topic_0000001100730486_p164783513817"></a><a name="en-us_topic_0000001100730486_p164783513817"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="33.043304330433045%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001100730486_p447153533816"><a name="en-us_topic_0000001100730486_p447153533816"></a><a name="en-us_topic_0000001100730486_p447153533816"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001100730486_row10475355385"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001100730486_p9268513193910"><a name="en-us_topic_0000001100730486_p9268513193910"></a><a name="en-us_topic_0000001100730486_p9268513193910"></a>UNKNOWN</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001100730486_p147113523813"><a name="en-us_topic_0000001100730486_p147113523813"></a><a name="en-us_topic_0000001100730486_p147113523813"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001100730486_p840231793914"><a name="en-us_topic_0000001100730486_p840231793914"></a><a name="en-us_topic_0000001100730486_p840231793914"></a>Unknown state</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row114716352387"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001100730486_p426781333915"><a name="en-us_topic_0000001100730486_p426781333915"></a><a name="en-us_topic_0000001100730486_p426781333915"></a>GOOD</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001100730486_p44843519383"><a name="en-us_topic_0000001100730486_p44843519383"></a><a name="en-us_topic_0000001100730486_p44843519383"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001100730486_p540191793918"><a name="en-us_topic_0000001100730486_p540191793918"></a><a name="en-us_topic_0000001100730486_p540191793918"></a>The battery is in healthy state.</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row8481935183816"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001100730486_p82651913183910"><a name="en-us_topic_0000001100730486_p82651913183910"></a><a name="en-us_topic_0000001100730486_p82651913183910"></a>OVERHEAT</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001100730486_p184818358383"><a name="en-us_topic_0000001100730486_p184818358383"></a><a name="en-us_topic_0000001100730486_p184818358383"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001100730486_p2399117183918"><a name="en-us_topic_0000001100730486_p2399117183918"></a><a name="en-us_topic_0000001100730486_p2399117183918"></a>The battery is overheated.</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row1448163593819"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001100730486_p10235161343911"><a name="en-us_topic_0000001100730486_p10235161343911"></a><a name="en-us_topic_0000001100730486_p10235161343911"></a>OVERVOLTAGE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001100730486_p34863518387"><a name="en-us_topic_0000001100730486_p34863518387"></a><a name="en-us_topic_0000001100730486_p34863518387"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001100730486_p203691717193914"><a name="en-us_topic_0000001100730486_p203691717193914"></a><a name="en-us_topic_0000001100730486_p203691717193914"></a>The battery voltage is over high.</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row2096919723911"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001100730486_p12970127203916"><a name="en-us_topic_0000001100730486_p12970127203916"></a><a name="en-us_topic_0000001100730486_p12970127203916"></a>COLD</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001100730486_p17970572396"><a name="en-us_topic_0000001100730486_p17970572396"></a><a name="en-us_topic_0000001100730486_p17970572396"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001100730486_p20970177153913"><a name="en-us_topic_0000001100730486_p20970177153913"></a><a name="en-us_topic_0000001100730486_p20970177153913"></a>The battery temperature is low.</p>
</td>
</tr>
<tr id="en-us_topic_0000001100730486_row497017143917"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001100730486_p19710712394"><a name="en-us_topic_0000001100730486_p19710712394"></a><a name="en-us_topic_0000001100730486_p19710712394"></a>DEAD</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001100730486_p997117733916"><a name="en-us_topic_0000001100730486_p997117733916"></a><a name="en-us_topic_0000001100730486_p997117733916"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001100730486_p13971137153918"><a name="en-us_topic_0000001100730486_p13971137153918"></a><a name="en-us_topic_0000001100730486_p13971137153918"></a>The battery is dead.</p>
</td>
</tr>
</tbody>
</table>

