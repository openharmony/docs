# 电池和充电属性<a name="ZH-CN_TOPIC_0000001209412153"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 6 开始支持。

## 导入模块<a name="zh-cn_topic_0000001164127376_section199443271307"></a>

```
import batteryInfo from '@ohos.batteryinfo';
```

## batteryInfo<a name="zh-cn_topic_0000001164127376_section0536924123914"></a>

描述电池信息。

<a name="zh-cn_topic_0000001164127376_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001164127376_row663331618238"><th class="cellrowborder" valign="top" width="20.13%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164127376_a3d0fc780cc904c1cbab7991251622f65"><a name="zh-cn_topic_0000001164127376_a3d0fc780cc904c1cbab7991251622f65"></a><a name="zh-cn_topic_0000001164127376_a3d0fc780cc904c1cbab7991251622f65"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.5%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164127376_p1961191632214"><a name="zh-cn_topic_0000001164127376_p1961191632214"></a><a name="zh-cn_topic_0000001164127376_p1961191632214"></a>读写属性</p>
</th>
<th class="cellrowborder" valign="top" width="23.29%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164127376_ac1f1afc248084f8fb51242b648bc34de"><a name="zh-cn_topic_0000001164127376_ac1f1afc248084f8fb51242b648bc34de"></a><a name="zh-cn_topic_0000001164127376_ac1f1afc248084f8fb51242b648bc34de"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="43.08%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164127376_afec895de33f94e3c87ee7acc20190a17"><a name="zh-cn_topic_0000001164127376_afec895de33f94e3c87ee7acc20190a17"></a><a name="zh-cn_topic_0000001164127376_afec895de33f94e3c87ee7acc20190a17"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001164127376_row188481425182510"><td class="cellrowborder" valign="top" width="20.13%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164127376_p938441717208"><a name="zh-cn_topic_0000001164127376_p938441717208"></a><a name="zh-cn_topic_0000001164127376_p938441717208"></a>batterySOC</p>
</td>
<td class="cellrowborder" valign="top" width="13.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164127376_p1396118166228"><a name="zh-cn_topic_0000001164127376_p1396118166228"></a><a name="zh-cn_topic_0000001164127376_p1396118166228"></a>只读</p>
</td>
<td class="cellrowborder" valign="top" width="23.29%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164127376_p6354841201511"><a name="zh-cn_topic_0000001164127376_p6354841201511"></a><a name="zh-cn_topic_0000001164127376_p6354841201511"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="43.08%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164127376_p103961315181818"><a name="zh-cn_topic_0000001164127376_p103961315181818"></a><a name="zh-cn_topic_0000001164127376_p103961315181818"></a>表示当前设备剩余电池容量。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row0461622112513"><td class="cellrowborder" valign="top" width="20.13%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164127376_p5354124120158"><a name="zh-cn_topic_0000001164127376_p5354124120158"></a><a name="zh-cn_topic_0000001164127376_p5354124120158"></a>chargingStatus</p>
</td>
<td class="cellrowborder" valign="top" width="13.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164127376_p159621168228"><a name="zh-cn_topic_0000001164127376_p159621168228"></a><a name="zh-cn_topic_0000001164127376_p159621168228"></a>只读</p>
</td>
<td class="cellrowborder" valign="top" width="23.29%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164127376_p10354541181520"><a name="zh-cn_topic_0000001164127376_p10354541181520"></a><a name="zh-cn_topic_0000001164127376_p10354541181520"></a>BatteryChargeState</p>
</td>
<td class="cellrowborder" valign="top" width="43.08%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164127376_p238673617568"><a name="zh-cn_topic_0000001164127376_p238673617568"></a><a name="zh-cn_topic_0000001164127376_p238673617568"></a>表示当前设备电池的充电状态。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row09415619242"><td class="cellrowborder" valign="top" width="20.13%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164127376_p1435434117152"><a name="zh-cn_topic_0000001164127376_p1435434117152"></a><a name="zh-cn_topic_0000001164127376_p1435434117152"></a>healthStatus</p>
</td>
<td class="cellrowborder" valign="top" width="13.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164127376_p1796210169224"><a name="zh-cn_topic_0000001164127376_p1796210169224"></a><a name="zh-cn_topic_0000001164127376_p1796210169224"></a>只读</p>
</td>
<td class="cellrowborder" valign="top" width="23.29%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164127376_p3354114131518"><a name="zh-cn_topic_0000001164127376_p3354114131518"></a><a name="zh-cn_topic_0000001164127376_p3354114131518"></a>BatteryHealthState</p>
</td>
<td class="cellrowborder" valign="top" width="43.08%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164127376_p1365563875614"><a name="zh-cn_topic_0000001164127376_p1365563875614"></a><a name="zh-cn_topic_0000001164127376_p1365563875614"></a>表示当前设备电池的健康状态。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row56471975243"><td class="cellrowborder" valign="top" width="20.13%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164127376_p1835534116158"><a name="zh-cn_topic_0000001164127376_p1835534116158"></a><a name="zh-cn_topic_0000001164127376_p1835534116158"></a>pluggedType</p>
</td>
<td class="cellrowborder" valign="top" width="13.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164127376_p18962416132211"><a name="zh-cn_topic_0000001164127376_p18962416132211"></a><a name="zh-cn_topic_0000001164127376_p18962416132211"></a>只读</p>
</td>
<td class="cellrowborder" valign="top" width="23.29%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164127376_p235584114153"><a name="zh-cn_topic_0000001164127376_p235584114153"></a><a name="zh-cn_topic_0000001164127376_p235584114153"></a>BatteryPluggedType</p>
</td>
<td class="cellrowborder" valign="top" width="43.08%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164127376_p19264101622016"><a name="zh-cn_topic_0000001164127376_p19264101622016"></a><a name="zh-cn_topic_0000001164127376_p19264101622016"></a>表示当前设备连接的充电器类型。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row4536161934520"><td class="cellrowborder" valign="top" width="20.13%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164127376_p14355174151513"><a name="zh-cn_topic_0000001164127376_p14355174151513"></a><a name="zh-cn_topic_0000001164127376_p14355174151513"></a>voltage</p>
</td>
<td class="cellrowborder" valign="top" width="13.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164127376_p296261662212"><a name="zh-cn_topic_0000001164127376_p296261662212"></a><a name="zh-cn_topic_0000001164127376_p296261662212"></a>只读</p>
</td>
<td class="cellrowborder" valign="top" width="23.29%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164127376_p7355741201519"><a name="zh-cn_topic_0000001164127376_p7355741201519"></a><a name="zh-cn_topic_0000001164127376_p7355741201519"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="43.08%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164127376_p127111826172018"><a name="zh-cn_topic_0000001164127376_p127111826172018"></a><a name="zh-cn_topic_0000001164127376_p127111826172018"></a>表示当前设备电池的电压。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row597319245451"><td class="cellrowborder" valign="top" width="20.13%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164127376_p153551941141517"><a name="zh-cn_topic_0000001164127376_p153551941141517"></a><a name="zh-cn_topic_0000001164127376_p153551941141517"></a>technology</p>
</td>
<td class="cellrowborder" valign="top" width="13.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164127376_p17962916162217"><a name="zh-cn_topic_0000001164127376_p17962916162217"></a><a name="zh-cn_topic_0000001164127376_p17962916162217"></a>只读</p>
</td>
<td class="cellrowborder" valign="top" width="23.29%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164127376_p535514113154"><a name="zh-cn_topic_0000001164127376_p535514113154"></a><a name="zh-cn_topic_0000001164127376_p535514113154"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="43.08%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164127376_p9298104612205"><a name="zh-cn_topic_0000001164127376_p9298104612205"></a><a name="zh-cn_topic_0000001164127376_p9298104612205"></a>表示当前设备电池的技术型号。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row4978143312456"><td class="cellrowborder" valign="top" width="20.13%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164127376_p7355114151515"><a name="zh-cn_topic_0000001164127376_p7355114151515"></a><a name="zh-cn_topic_0000001164127376_p7355114151515"></a>batteryTemperature</p>
</td>
<td class="cellrowborder" valign="top" width="13.5%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164127376_p14962116172215"><a name="zh-cn_topic_0000001164127376_p14962116172215"></a><a name="zh-cn_topic_0000001164127376_p14962116172215"></a>只读</p>
</td>
<td class="cellrowborder" valign="top" width="23.29%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164127376_p143551941201510"><a name="zh-cn_topic_0000001164127376_p143551941201510"></a><a name="zh-cn_topic_0000001164127376_p143551941201510"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="43.08%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164127376_p7843573202"><a name="zh-cn_topic_0000001164127376_p7843573202"></a><a name="zh-cn_topic_0000001164127376_p7843573202"></a>表示当前设备电池的温度。</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
import batteryInfo from '@ohos.batteryInfo';
var batterySoc = batteryInfo.batterySOC;
```

## BatteryPluggedType<a name="zh-cn_topic_0000001164127376_section1861134715488"></a>

表示连接的充电器类型的枚举。

<a name="zh-cn_topic_0000001164127376_table144441452192814"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001164127376_row12444145210288"><th class="cellrowborder" valign="top" width="31.703170317031702%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001164127376_p162914100272"><a name="zh-cn_topic_0000001164127376_p162914100272"></a><a name="zh-cn_topic_0000001164127376_p162914100272"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="35.253525352535256%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001164127376_p044416523286"><a name="zh-cn_topic_0000001164127376_p044416523286"></a><a name="zh-cn_topic_0000001164127376_p044416523286"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="33.043304330433045%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001164127376_p1044495252810"><a name="zh-cn_topic_0000001164127376_p1044495252810"></a><a name="zh-cn_topic_0000001164127376_p1044495252810"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001164127376_row18444115215284"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001164127376_p954122310283"><a name="zh-cn_topic_0000001164127376_p954122310283"></a><a name="zh-cn_topic_0000001164127376_p954122310283"></a>NONE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001164127376_p0527233288"><a name="zh-cn_topic_0000001164127376_p0527233288"></a><a name="zh-cn_topic_0000001164127376_p0527233288"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001164127376_p12372352812"><a name="zh-cn_topic_0000001164127376_p12372352812"></a><a name="zh-cn_topic_0000001164127376_p12372352812"></a>表示连接充电器类型未知。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row55389918289"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001164127376_p15381795285"><a name="zh-cn_topic_0000001164127376_p15381795285"></a><a name="zh-cn_topic_0000001164127376_p15381795285"></a>AC</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001164127376_p45381291281"><a name="zh-cn_topic_0000001164127376_p45381291281"></a><a name="zh-cn_topic_0000001164127376_p45381291281"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001164127376_p1953979102813"><a name="zh-cn_topic_0000001164127376_p1953979102813"></a><a name="zh-cn_topic_0000001164127376_p1953979102813"></a>表示连接的充电器类型为交流充电器。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row928621592815"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001164127376_p1328691518288"><a name="zh-cn_topic_0000001164127376_p1328691518288"></a><a name="zh-cn_topic_0000001164127376_p1328691518288"></a>USB</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001164127376_p1728616154286"><a name="zh-cn_topic_0000001164127376_p1728616154286"></a><a name="zh-cn_topic_0000001164127376_p1728616154286"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001164127376_p188591922163215"><a name="zh-cn_topic_0000001164127376_p188591922163215"></a><a name="zh-cn_topic_0000001164127376_p188591922163215"></a>表示连接的充电器类型为USB。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row3954122652810"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001164127376_p1995412614284"><a name="zh-cn_topic_0000001164127376_p1995412614284"></a><a name="zh-cn_topic_0000001164127376_p1995412614284"></a>WIRELESS</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001164127376_p395402620286"><a name="zh-cn_topic_0000001164127376_p395402620286"></a><a name="zh-cn_topic_0000001164127376_p395402620286"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001164127376_p235192423214"><a name="zh-cn_topic_0000001164127376_p235192423214"></a><a name="zh-cn_topic_0000001164127376_p235192423214"></a>表示连接的充电器类型为无线充电器。</p>
</td>
</tr>
</tbody>
</table>

## BatteryChargeState<a name="zh-cn_topic_0000001164127376_section629045815408"></a>

表示电池充电状态的枚举。

<a name="zh-cn_topic_0000001164127376_table1368716015365"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001164127376_row106884010367"><th class="cellrowborder" valign="top" width="31.703170317031702%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001164127376_p468816023615"><a name="zh-cn_topic_0000001164127376_p468816023615"></a><a name="zh-cn_topic_0000001164127376_p468816023615"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="35.253525352535256%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001164127376_p15688505362"><a name="zh-cn_topic_0000001164127376_p15688505362"></a><a name="zh-cn_topic_0000001164127376_p15688505362"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="33.043304330433045%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001164127376_p1068830103619"><a name="zh-cn_topic_0000001164127376_p1068830103619"></a><a name="zh-cn_topic_0000001164127376_p1068830103619"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001164127376_row1868880113613"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001164127376_p1392942212399"><a name="zh-cn_topic_0000001164127376_p1392942212399"></a><a name="zh-cn_topic_0000001164127376_p1392942212399"></a>NONE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001164127376_p968880103613"><a name="zh-cn_topic_0000001164127376_p968880103613"></a><a name="zh-cn_topic_0000001164127376_p968880103613"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001164127376_p16911819163919"><a name="zh-cn_topic_0000001164127376_p16911819163919"></a><a name="zh-cn_topic_0000001164127376_p16911819163919"></a>表示电池充电状态未知。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row17688180173620"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001164127376_p12928922193920"><a name="zh-cn_topic_0000001164127376_p12928922193920"></a><a name="zh-cn_topic_0000001164127376_p12928922193920"></a>ENABLE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001164127376_p86893003614"><a name="zh-cn_topic_0000001164127376_p86893003614"></a><a name="zh-cn_topic_0000001164127376_p86893003614"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001164127376_p9910201913391"><a name="zh-cn_topic_0000001164127376_p9910201913391"></a><a name="zh-cn_topic_0000001164127376_p9910201913391"></a>表示电池充电状态为使能状态。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row1868914011367"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001164127376_p4926152211394"><a name="zh-cn_topic_0000001164127376_p4926152211394"></a><a name="zh-cn_topic_0000001164127376_p4926152211394"></a>DISABLE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001164127376_p186891001361"><a name="zh-cn_topic_0000001164127376_p186891001361"></a><a name="zh-cn_topic_0000001164127376_p186891001361"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001164127376_p1210733413414"><a name="zh-cn_topic_0000001164127376_p1210733413414"></a><a name="zh-cn_topic_0000001164127376_p1210733413414"></a>表示电池充电状态为停止状态。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row068911018360"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001164127376_p1992542211392"><a name="zh-cn_topic_0000001164127376_p1992542211392"></a><a name="zh-cn_topic_0000001164127376_p1992542211392"></a>FULL</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001164127376_p46895023619"><a name="zh-cn_topic_0000001164127376_p46895023619"></a><a name="zh-cn_topic_0000001164127376_p46895023619"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001164127376_p3614135154120"><a name="zh-cn_topic_0000001164127376_p3614135154120"></a><a name="zh-cn_topic_0000001164127376_p3614135154120"></a>表示电池充电状态为已充满状态。</p>
</td>
</tr>
</tbody>
</table>

## BatteryHealthState<a name="zh-cn_topic_0000001164127376_section1636311513419"></a>

表示电池的健康状态的枚举。

<a name="zh-cn_topic_0000001164127376_table1646153519380"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001164127376_row1847203533813"><th class="cellrowborder" valign="top" width="31.703170317031702%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001164127376_p44743514381"><a name="zh-cn_topic_0000001164127376_p44743514381"></a><a name="zh-cn_topic_0000001164127376_p44743514381"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="35.253525352535256%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001164127376_p164783513817"><a name="zh-cn_topic_0000001164127376_p164783513817"></a><a name="zh-cn_topic_0000001164127376_p164783513817"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="33.043304330433045%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001164127376_p447153533816"><a name="zh-cn_topic_0000001164127376_p447153533816"></a><a name="zh-cn_topic_0000001164127376_p447153533816"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001164127376_row10475355385"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001164127376_p9268513193910"><a name="zh-cn_topic_0000001164127376_p9268513193910"></a><a name="zh-cn_topic_0000001164127376_p9268513193910"></a>UNKNOWN</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001164127376_p147113523813"><a name="zh-cn_topic_0000001164127376_p147113523813"></a><a name="zh-cn_topic_0000001164127376_p147113523813"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001164127376_p840231793914"><a name="zh-cn_topic_0000001164127376_p840231793914"></a><a name="zh-cn_topic_0000001164127376_p840231793914"></a>表示电池健康状态未知。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row114716352387"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001164127376_p426781333915"><a name="zh-cn_topic_0000001164127376_p426781333915"></a><a name="zh-cn_topic_0000001164127376_p426781333915"></a>GOOD</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001164127376_p44843519383"><a name="zh-cn_topic_0000001164127376_p44843519383"></a><a name="zh-cn_topic_0000001164127376_p44843519383"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001164127376_p540191793918"><a name="zh-cn_topic_0000001164127376_p540191793918"></a><a name="zh-cn_topic_0000001164127376_p540191793918"></a>表示电池健康状态为正常。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row8481935183816"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001164127376_p82651913183910"><a name="zh-cn_topic_0000001164127376_p82651913183910"></a><a name="zh-cn_topic_0000001164127376_p82651913183910"></a>OVERHEAT</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001164127376_p184818358383"><a name="zh-cn_topic_0000001164127376_p184818358383"></a><a name="zh-cn_topic_0000001164127376_p184818358383"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001164127376_p2399117183918"><a name="zh-cn_topic_0000001164127376_p2399117183918"></a><a name="zh-cn_topic_0000001164127376_p2399117183918"></a>表示电池健康状态为过热。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row1448163593819"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001164127376_p10235161343911"><a name="zh-cn_topic_0000001164127376_p10235161343911"></a><a name="zh-cn_topic_0000001164127376_p10235161343911"></a>OVERVOLTAGE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001164127376_p34863518387"><a name="zh-cn_topic_0000001164127376_p34863518387"></a><a name="zh-cn_topic_0000001164127376_p34863518387"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001164127376_p203691717193914"><a name="zh-cn_topic_0000001164127376_p203691717193914"></a><a name="zh-cn_topic_0000001164127376_p203691717193914"></a>表示电池健康状态为过压。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row2096919723911"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001164127376_p12970127203916"><a name="zh-cn_topic_0000001164127376_p12970127203916"></a><a name="zh-cn_topic_0000001164127376_p12970127203916"></a>COLD</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001164127376_p17970572396"><a name="zh-cn_topic_0000001164127376_p17970572396"></a><a name="zh-cn_topic_0000001164127376_p17970572396"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001164127376_p20970177153913"><a name="zh-cn_topic_0000001164127376_p20970177153913"></a><a name="zh-cn_topic_0000001164127376_p20970177153913"></a>表示电池健康状态为低温。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164127376_row497017143917"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001164127376_p19710712394"><a name="zh-cn_topic_0000001164127376_p19710712394"></a><a name="zh-cn_topic_0000001164127376_p19710712394"></a>DEAD</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001164127376_p997117733916"><a name="zh-cn_topic_0000001164127376_p997117733916"></a><a name="zh-cn_topic_0000001164127376_p997117733916"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001164127376_p13971137153918"><a name="zh-cn_topic_0000001164127376_p13971137153918"></a><a name="zh-cn_topic_0000001164127376_p13971137153918"></a>表示电池健康状态为僵死状态。</p>
</td>
</tr>
</tbody>
</table>

