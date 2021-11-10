# 电量信息<a name="ZH-CN_TOPIC_0000001121409574"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 6 开始支持。

## 导入模块<a name="section199443271307"></a>

```
import batteryInfo from '@ohos.batteryInfo';
```

## 属性<a name="section0536924123914"></a>

描述电池信息。

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="21.58%" id="mcps1.1.6.1.1"><p id="a3d0fc780cc904c1cbab7991251622f65"><a name="a3d0fc780cc904c1cbab7991251622f65"></a><a name="a3d0fc780cc904c1cbab7991251622f65"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.349999999999998%" id="mcps1.1.6.1.2"><p id="ac1f1afc248084f8fb51242b648bc34de"><a name="ac1f1afc248084f8fb51242b648bc34de"></a><a name="ac1f1afc248084f8fb51242b648bc34de"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.950000000000001%" id="mcps1.1.6.1.3"><p id="p15118503351"><a name="p15118503351"></a><a name="p15118503351"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p13804175213358"><a name="p13804175213358"></a><a name="p13804175213358"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="42.6%" id="mcps1.1.6.1.5"><p id="afec895de33f94e3c87ee7acc20190a17"><a name="afec895de33f94e3c87ee7acc20190a17"></a><a name="afec895de33f94e3c87ee7acc20190a17"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row188481425182510"><td class="cellrowborder" valign="top" width="21.58%" headers="mcps1.1.6.1.1 "><p id="p938441717208"><a name="p938441717208"></a><a name="p938441717208"></a>batterySOC</p>
</td>
<td class="cellrowborder" valign="top" width="21.349999999999998%" headers="mcps1.1.6.1.2 "><p id="p6354841201511"><a name="p6354841201511"></a><a name="p6354841201511"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.950000000000001%" headers="mcps1.1.6.1.3 "><p id="p71155043513"><a name="p71155043513"></a><a name="p71155043513"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p188058527352"><a name="p188058527352"></a><a name="p188058527352"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.6%" headers="mcps1.1.6.1.5 "><p id="p103961315181818"><a name="p103961315181818"></a><a name="p103961315181818"></a>表示当前设备剩余电池容量。</p>
</td>
</tr>
<tr id="row0461622112513"><td class="cellrowborder" valign="top" width="21.58%" headers="mcps1.1.6.1.1 "><p id="p5354124120158"><a name="p5354124120158"></a><a name="p5354124120158"></a>chargingStatus</p>
</td>
<td class="cellrowborder" valign="top" width="21.349999999999998%" headers="mcps1.1.6.1.2 "><p id="p10354541181520"><a name="p10354541181520"></a><a name="p10354541181520"></a><a href="#section629045815408">BatteryChargeState</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.950000000000001%" headers="mcps1.1.6.1.3 "><p id="p11113502356"><a name="p11113502356"></a><a name="p11113502356"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p280555253510"><a name="p280555253510"></a><a name="p280555253510"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.6%" headers="mcps1.1.6.1.5 "><p id="p238673617568"><a name="p238673617568"></a><a name="p238673617568"></a>表示当前设备电池的充电状态。</p>
</td>
</tr>
<tr id="row09415619242"><td class="cellrowborder" valign="top" width="21.58%" headers="mcps1.1.6.1.1 "><p id="p1435434117152"><a name="p1435434117152"></a><a name="p1435434117152"></a>healthStatus</p>
</td>
<td class="cellrowborder" valign="top" width="21.349999999999998%" headers="mcps1.1.6.1.2 "><p id="p3354114131518"><a name="p3354114131518"></a><a name="p3354114131518"></a><a href="#section1636311513419">BatteryHealthState</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.950000000000001%" headers="mcps1.1.6.1.3 "><p id="p16111250153517"><a name="p16111250153517"></a><a name="p16111250153517"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p38051525356"><a name="p38051525356"></a><a name="p38051525356"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.6%" headers="mcps1.1.6.1.5 "><p id="p1365563875614"><a name="p1365563875614"></a><a name="p1365563875614"></a>表示当前设备电池的健康状态。</p>
</td>
</tr>
<tr id="row56471975243"><td class="cellrowborder" valign="top" width="21.58%" headers="mcps1.1.6.1.1 "><p id="p1835534116158"><a name="p1835534116158"></a><a name="p1835534116158"></a>pluggedType</p>
</td>
<td class="cellrowborder" valign="top" width="21.349999999999998%" headers="mcps1.1.6.1.2 "><p id="p235584114153"><a name="p235584114153"></a><a name="p235584114153"></a><a href="#section1861134715488">BatteryPluggedType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.950000000000001%" headers="mcps1.1.6.1.3 "><p id="p111125093513"><a name="p111125093513"></a><a name="p111125093513"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p198051752183511"><a name="p198051752183511"></a><a name="p198051752183511"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.6%" headers="mcps1.1.6.1.5 "><p id="p19264101622016"><a name="p19264101622016"></a><a name="p19264101622016"></a>表示当前设备连接的充电器类型。</p>
</td>
</tr>
<tr id="row4536161934520"><td class="cellrowborder" valign="top" width="21.58%" headers="mcps1.1.6.1.1 "><p id="p14355174151513"><a name="p14355174151513"></a><a name="p14355174151513"></a>voltage</p>
</td>
<td class="cellrowborder" valign="top" width="21.349999999999998%" headers="mcps1.1.6.1.2 "><p id="p7355741201519"><a name="p7355741201519"></a><a name="p7355741201519"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.950000000000001%" headers="mcps1.1.6.1.3 "><p id="p1811195013354"><a name="p1811195013354"></a><a name="p1811195013354"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1580585263519"><a name="p1580585263519"></a><a name="p1580585263519"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.6%" headers="mcps1.1.6.1.5 "><p id="p127111826172018"><a name="p127111826172018"></a><a name="p127111826172018"></a>表示当前设备电池的电压。</p>
</td>
</tr>
<tr id="row597319245451"><td class="cellrowborder" valign="top" width="21.58%" headers="mcps1.1.6.1.1 "><p id="p153551941141517"><a name="p153551941141517"></a><a name="p153551941141517"></a>technology</p>
</td>
<td class="cellrowborder" valign="top" width="21.349999999999998%" headers="mcps1.1.6.1.2 "><p id="p535514113154"><a name="p535514113154"></a><a name="p535514113154"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.950000000000001%" headers="mcps1.1.6.1.3 "><p id="p3111650133514"><a name="p3111650133514"></a><a name="p3111650133514"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1680575273515"><a name="p1680575273515"></a><a name="p1680575273515"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.6%" headers="mcps1.1.6.1.5 "><p id="p9298104612205"><a name="p9298104612205"></a><a name="p9298104612205"></a>表示当前设备电池的技术型号。</p>
</td>
</tr>
<tr id="row4978143312456"><td class="cellrowborder" valign="top" width="21.58%" headers="mcps1.1.6.1.1 "><p id="p7355114151515"><a name="p7355114151515"></a><a name="p7355114151515"></a>batteryTemperature</p>
</td>
<td class="cellrowborder" valign="top" width="21.349999999999998%" headers="mcps1.1.6.1.2 "><p id="p143551941201510"><a name="p143551941201510"></a><a name="p143551941201510"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.950000000000001%" headers="mcps1.1.6.1.3 "><p id="p14694205103613"><a name="p14694205103613"></a><a name="p14694205103613"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p980518523359"><a name="p980518523359"></a><a name="p980518523359"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.6%" headers="mcps1.1.6.1.5 "><p id="p7843573202"><a name="p7843573202"></a><a name="p7843573202"></a>表示当前设备电池的温度。</p>
</td>
</tr>
<tr id="row115952572810"><td class="cellrowborder" valign="top" width="21.58%" headers="mcps1.1.6.1.1 "><p id="p959152510281"><a name="p959152510281"></a><a name="p959152510281"></a>isBatteryPresent<sup id="sup15407935624"><a name="sup15407935624"></a><a name="sup15407935624"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.349999999999998%" headers="mcps1.1.6.1.2 "><p id="p659025192819"><a name="p659025192819"></a><a name="p659025192819"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="6.950000000000001%" headers="mcps1.1.6.1.3 "><p id="p1012195020357"><a name="p1012195020357"></a><a name="p1012195020357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p9805105213352"><a name="p9805105213352"></a><a name="p9805105213352"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.6%" headers="mcps1.1.6.1.5 "><p id="p15590255280"><a name="p15590255280"></a><a name="p15590255280"></a>表示当前设备是否支持电池或者电池是否在位。</p>
</td>
</tr>
</tbody>
</table>

-   示例：

    ```
    import batteryInfo from '@ohos.batteryInfo';
    var batterySoc = batteryInfo.batterySOC;
    ```


## BatteryPluggedType<a name="section1861134715488"></a>

表示连接的充电器类型的枚举。

<a name="table144441452192814"></a>
<table><thead align="left"><tr id="row12444145210288"><th class="cellrowborder" valign="top" width="31.703170317031702%" id="mcps1.1.4.1.1"><p id="p162914100272"><a name="p162914100272"></a><a name="p162914100272"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="35.253525352535256%" id="mcps1.1.4.1.2"><p id="p044416523286"><a name="p044416523286"></a><a name="p044416523286"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="33.043304330433045%" id="mcps1.1.4.1.3"><p id="p1044495252810"><a name="p1044495252810"></a><a name="p1044495252810"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row18444115215284"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="p954122310283"><a name="p954122310283"></a><a name="p954122310283"></a>NONE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="p0527233288"><a name="p0527233288"></a><a name="p0527233288"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="p12372352812"><a name="p12372352812"></a><a name="p12372352812"></a>表示连接充电器类型未知。</p>
</td>
</tr>
<tr id="row55389918289"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="p15381795285"><a name="p15381795285"></a><a name="p15381795285"></a>AC</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="p45381291281"><a name="p45381291281"></a><a name="p45381291281"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="p1953979102813"><a name="p1953979102813"></a><a name="p1953979102813"></a>表示连接的充电器类型为交流充电器。</p>
</td>
</tr>
<tr id="row928621592815"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="p1328691518288"><a name="p1328691518288"></a><a name="p1328691518288"></a>USB</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="p1728616154286"><a name="p1728616154286"></a><a name="p1728616154286"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="p188591922163215"><a name="p188591922163215"></a><a name="p188591922163215"></a>表示连接的充电器类型为USB。</p>
</td>
</tr>
<tr id="row3954122652810"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="p1995412614284"><a name="p1995412614284"></a><a name="p1995412614284"></a>WIRELESS</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="p395402620286"><a name="p395402620286"></a><a name="p395402620286"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="p235192423214"><a name="p235192423214"></a><a name="p235192423214"></a>表示连接的充电器类型为无线充电器。</p>
</td>
</tr>
</tbody>
</table>

## BatteryChargeState<a name="section629045815408"></a>

表示电池充电状态的枚举。

<a name="table1368716015365"></a>
<table><thead align="left"><tr id="row106884010367"><th class="cellrowborder" valign="top" width="31.703170317031702%" id="mcps1.1.4.1.1"><p id="p468816023615"><a name="p468816023615"></a><a name="p468816023615"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="35.253525352535256%" id="mcps1.1.4.1.2"><p id="p15688505362"><a name="p15688505362"></a><a name="p15688505362"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="33.043304330433045%" id="mcps1.1.4.1.3"><p id="p1068830103619"><a name="p1068830103619"></a><a name="p1068830103619"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1868880113613"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="p1392942212399"><a name="p1392942212399"></a><a name="p1392942212399"></a>NONE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="p968880103613"><a name="p968880103613"></a><a name="p968880103613"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="p16911819163919"><a name="p16911819163919"></a><a name="p16911819163919"></a>表示电池充电状态未知。</p>
</td>
</tr>
<tr id="row17688180173620"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="p12928922193920"><a name="p12928922193920"></a><a name="p12928922193920"></a>ENABLE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="p86893003614"><a name="p86893003614"></a><a name="p86893003614"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="p9910201913391"><a name="p9910201913391"></a><a name="p9910201913391"></a>表示电池充电状态为使能状态。</p>
</td>
</tr>
<tr id="row1868914011367"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="p4926152211394"><a name="p4926152211394"></a><a name="p4926152211394"></a>DISABLE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="p186891001361"><a name="p186891001361"></a><a name="p186891001361"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="p1210733413414"><a name="p1210733413414"></a><a name="p1210733413414"></a>表示电池充电状态为停止状态。</p>
</td>
</tr>
<tr id="row068911018360"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="p1992542211392"><a name="p1992542211392"></a><a name="p1992542211392"></a>FULL</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="p46895023619"><a name="p46895023619"></a><a name="p46895023619"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="p3614135154120"><a name="p3614135154120"></a><a name="p3614135154120"></a>表示电池充电状态为已充满状态。</p>
</td>
</tr>
</tbody>
</table>

## BatteryHealthState<a name="section1636311513419"></a>

表示电池的健康状态的枚举。

<a name="table1646153519380"></a>
<table><thead align="left"><tr id="row1847203533813"><th class="cellrowborder" valign="top" width="31.703170317031702%" id="mcps1.1.4.1.1"><p id="p44743514381"><a name="p44743514381"></a><a name="p44743514381"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="35.253525352535256%" id="mcps1.1.4.1.2"><p id="p164783513817"><a name="p164783513817"></a><a name="p164783513817"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="33.043304330433045%" id="mcps1.1.4.1.3"><p id="p447153533816"><a name="p447153533816"></a><a name="p447153533816"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row10475355385"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="p9268513193910"><a name="p9268513193910"></a><a name="p9268513193910"></a>UNKNOWN</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="p147113523813"><a name="p147113523813"></a><a name="p147113523813"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="p840231793914"><a name="p840231793914"></a><a name="p840231793914"></a>表示电池健康状态未知。</p>
</td>
</tr>
<tr id="row114716352387"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="p426781333915"><a name="p426781333915"></a><a name="p426781333915"></a>GOOD</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="p44843519383"><a name="p44843519383"></a><a name="p44843519383"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="p540191793918"><a name="p540191793918"></a><a name="p540191793918"></a>表示电池健康状态为正常。</p>
</td>
</tr>
<tr id="row8481935183816"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="p82651913183910"><a name="p82651913183910"></a><a name="p82651913183910"></a>OVERHEAT</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="p184818358383"><a name="p184818358383"></a><a name="p184818358383"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="p2399117183918"><a name="p2399117183918"></a><a name="p2399117183918"></a>表示电池健康状态为过热。</p>
</td>
</tr>
<tr id="row1448163593819"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="p10235161343911"><a name="p10235161343911"></a><a name="p10235161343911"></a>OVERVOLTAGE</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="p34863518387"><a name="p34863518387"></a><a name="p34863518387"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="p203691717193914"><a name="p203691717193914"></a><a name="p203691717193914"></a>表示电池健康状态为过压。</p>
</td>
</tr>
<tr id="row2096919723911"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="p12970127203916"><a name="p12970127203916"></a><a name="p12970127203916"></a>COLD</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="p17970572396"><a name="p17970572396"></a><a name="p17970572396"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="p20970177153913"><a name="p20970177153913"></a><a name="p20970177153913"></a>表示电池健康状态为低温。</p>
</td>
</tr>
<tr id="row497017143917"><td class="cellrowborder" valign="top" width="31.703170317031702%" headers="mcps1.1.4.1.1 "><p id="p19710712394"><a name="p19710712394"></a><a name="p19710712394"></a>DEAD</p>
</td>
<td class="cellrowborder" valign="top" width="35.253525352535256%" headers="mcps1.1.4.1.2 "><p id="p997117733916"><a name="p997117733916"></a><a name="p997117733916"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="33.043304330433045%" headers="mcps1.1.4.1.3 "><p id="p13971137153918"><a name="p13971137153918"></a><a name="p13971137153918"></a>表示电池健康状态为僵死状态。</p>
</td>
</tr>
</tbody>
</table>

