# IBatteryInterface<a name="ZH-CN_TOPIC_0000001291040580"></a>

## **概述**<a name="section1624282165083932"></a>

**所属模块:**

[Battery](battery.md)

## **汇总**<a name="section608750910083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table1111731046083932"></a>
<table><thead align="left"><tr id="row1510102251083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1565227999083932"><a name="p1565227999083932"></a><a name="p1565227999083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p466130259083932"><a name="p466130259083932"></a><a name="p466130259083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row942613384083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p646655863083932"><a name="p646655863083932"></a><a name="p646655863083932"></a><a href="interface_i_battery_interface.md#ad92a74e22a1d2e11fa8fedc7f582559c">Register</a> ([in] <a href="interface_i_battery_callback.md">IBatteryCallback</a> event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p924057672083932"><a name="p924057672083932"></a><a name="p924057672083932"></a>注册电池信息的回调。 <a href="interface_i_battery_interface.md#ad92a74e22a1d2e11fa8fedc7f582559c">更多...</a></p>
</td>
</tr>
<tr id="row1165633429083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p211289376083932"><a name="p211289376083932"></a><a name="p211289376083932"></a><a href="interface_i_battery_interface.md#ab7d303718899d2ef079f85c72c3412cd">UnRegister</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1035874308083932"><a name="p1035874308083932"></a><a name="p1035874308083932"></a>取消注册电池信息的回调。 <a href="interface_i_battery_interface.md#ab7d303718899d2ef079f85c72c3412cd">更多...</a></p>
</td>
</tr>
<tr id="row1966985409083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1630294917083932"><a name="p1630294917083932"></a><a name="p1630294917083932"></a><a href="interface_i_battery_interface.md#afa0730f663318aa8b8d80c2ef72d9c5f">ChangePath</a> ([in] String path)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p719646399083932"><a name="p719646399083932"></a><a name="p719646399083932"></a>设置电池信息节点的路径。 <a href="interface_i_battery_interface.md#afa0730f663318aa8b8d80c2ef72d9c5f">更多...</a></p>
</td>
</tr>
<tr id="row508154628083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p637602032083932"><a name="p637602032083932"></a><a name="p637602032083932"></a><a href="interface_i_battery_interface.md#a0abb3601e346bdae231648d2bcf0d37c">GetCapacity</a> ([out] int capacity)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p833696169083932"><a name="p833696169083932"></a><a name="p833696169083932"></a>获取电池的电量百分比。 <a href="interface_i_battery_interface.md#a0abb3601e346bdae231648d2bcf0d37c">更多...</a></p>
</td>
</tr>
<tr id="row970388528083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p429386244083932"><a name="p429386244083932"></a><a name="p429386244083932"></a><a href="interface_i_battery_interface.md#a8847e34902b827eff5fa1f20a7f2b6f9">GetVoltage</a> ([out] int voltage)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1788394201083932"><a name="p1788394201083932"></a><a name="p1788394201083932"></a>获取电池的电压，单位微伏。 <a href="interface_i_battery_interface.md#a8847e34902b827eff5fa1f20a7f2b6f9">更多...</a></p>
</td>
</tr>
<tr id="row1561818858083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2060108616083932"><a name="p2060108616083932"></a><a name="p2060108616083932"></a><a href="interface_i_battery_interface.md#a230716ad6e330304789ced6c6b071bb7">GetTemperature</a> ([out] int temperature)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1677846766083932"><a name="p1677846766083932"></a><a name="p1677846766083932"></a>获取电池的充电温度，单位0.1摄氏度。 <a href="interface_i_battery_interface.md#a230716ad6e330304789ced6c6b071bb7">更多...</a></p>
</td>
</tr>
<tr id="row1939006147083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p323478572083932"><a name="p323478572083932"></a><a name="p323478572083932"></a><a href="interface_i_battery_interface.md#a2200c3f7443a9301cc3fab94400759fe">GetHealthState</a> ([out] enum <a href="battery.md#gaec9b86ee31a5d8abf7c804d81b542f2f">BatteryHealthState</a> healthState)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p277987251083932"><a name="p277987251083932"></a><a name="p277987251083932"></a>获取电池的健康状态。 <a href="interface_i_battery_interface.md#a2200c3f7443a9301cc3fab94400759fe">更多...</a></p>
</td>
</tr>
<tr id="row1066714501083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1634766195083932"><a name="p1634766195083932"></a><a name="p1634766195083932"></a><a href="interface_i_battery_interface.md#abbf8efa7adc874b598b3baa6b5b1049d">GetPluggedType</a> ([out] enum <a href="battery.md#gab80029eabf9d0fdcc3ab4d4a4c3be6ba">BatteryPluggedType</a> pluggedType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1372687635083932"><a name="p1372687635083932"></a><a name="p1372687635083932"></a>获取充电设备类型。 <a href="interface_i_battery_interface.md#abbf8efa7adc874b598b3baa6b5b1049d">更多...</a></p>
</td>
</tr>
<tr id="row267185639083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p535329883083932"><a name="p535329883083932"></a><a name="p535329883083932"></a><a href="interface_i_battery_interface.md#afeb6a5f6f7a1d07492c12f8f31cae4c3">GetChargeState</a> ([out] enum <a href="battery.md#ga35791cca3603f7855c6368fbd00b21f1">BatteryChargeState</a> chargeState)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p891782901083932"><a name="p891782901083932"></a><a name="p891782901083932"></a>获取充电状态。 <a href="interface_i_battery_interface.md#afeb6a5f6f7a1d07492c12f8f31cae4c3">更多...</a></p>
</td>
</tr>
<tr id="row1432859141083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1524075935083932"><a name="p1524075935083932"></a><a name="p1524075935083932"></a><a href="interface_i_battery_interface.md#aeee555b6f97789349bf7b9d64b4d783e">GetPresent</a> ([out] boolean present)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p770846458083932"><a name="p770846458083932"></a><a name="p770846458083932"></a>获取是否支持电池或者电池是否在位。 <a href="interface_i_battery_interface.md#aeee555b6f97789349bf7b9d64b4d783e">更多...</a></p>
</td>
</tr>
<tr id="row2124143773083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1851299327083932"><a name="p1851299327083932"></a><a name="p1851299327083932"></a><a href="interface_i_battery_interface.md#a70328c8f742b5a70a9c388b8c72f84e6">GetTechnology</a> ([out] String technology)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p758749213083932"><a name="p758749213083932"></a><a name="p758749213083932"></a>获取电池的技术型号。 <a href="interface_i_battery_interface.md#a70328c8f742b5a70a9c388b8c72f84e6">更多...</a></p>
</td>
</tr>
<tr id="row1989985143083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p189198639083932"><a name="p189198639083932"></a><a name="p189198639083932"></a><a href="interface_i_battery_interface.md#a156dfa0abdc4644ef2e2be22132ec48c">GetTotalEnergy</a> ([out] int totalEnergy)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1229370624083932"><a name="p1229370624083932"></a><a name="p1229370624083932"></a>获取电池的总容量。 <a href="interface_i_battery_interface.md#a156dfa0abdc4644ef2e2be22132ec48c">更多...</a></p>
</td>
</tr>
<tr id="row265119587083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1928588695083932"><a name="p1928588695083932"></a><a name="p1928588695083932"></a><a href="interface_i_battery_interface.md#a10bf80b436e15ff386c042cadf4e8c51">GetCurrentAverage</a> ([out] int curAverage)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1863519338083932"><a name="p1863519338083932"></a><a name="p1863519338083932"></a>获取电池的平均电流。 <a href="interface_i_battery_interface.md#a10bf80b436e15ff386c042cadf4e8c51">更多...</a></p>
</td>
</tr>
<tr id="row909487270083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1360283363083932"><a name="p1360283363083932"></a><a name="p1360283363083932"></a><a href="interface_i_battery_interface.md#ad4f971592e9bb7e63d9064d944fa2dfb">GetCurrentNow</a> ([out] int curNow)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1658389972083932"><a name="p1658389972083932"></a><a name="p1658389972083932"></a>获取电池的电流。 <a href="interface_i_battery_interface.md#ad4f971592e9bb7e63d9064d944fa2dfb">更多...</a></p>
</td>
</tr>
<tr id="row431438693083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1546155821083932"><a name="p1546155821083932"></a><a name="p1546155821083932"></a><a href="interface_i_battery_interface.md#a057befa17672be9824d62e51de852fb4">GetRemainEnergy</a> ([out] int remainEnergy)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p455298704083932"><a name="p455298704083932"></a><a name="p455298704083932"></a>获取电池的剩余容量。 <a href="interface_i_battery_interface.md#a057befa17672be9824d62e51de852fb4">更多...</a></p>
</td>
</tr>
<tr id="row1692178569083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1612240130083932"><a name="p1612240130083932"></a><a name="p1612240130083932"></a><a href="interface_i_battery_interface.md#a4806bc306aee79990f3132fb5cd27056">GetBatteryInfo</a> ([out] struct <a href="_battery_info.md">BatteryInfo</a> info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1386260184083932"><a name="p1386260184083932"></a><a name="p1386260184083932"></a>获取电池的全部信息。 <a href="interface_i_battery_interface.md#a4806bc306aee79990f3132fb5cd27056">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1752897336083932"></a>

获取、订阅电池信息的接口。

服务获取此对象后，可以调用相关的接口获取、订阅电池信息。

**Since：**

3.1

## **成员函数说明**<a name="section133695180083932"></a>

## ChangePath\(\)<a name="afa0730f663318aa8b8d80c2ef72d9c5f"></a>

```
IBatteryInterface::ChangePath ([in] String path)
```

**描述：**

设置电池信息节点的路径。

**参数：**

<a name="table1783175459083932"></a>
<table><thead align="left"><tr id="row648747613083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1417144671083932"><a name="p1417144671083932"></a><a name="p1417144671083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p19412124083932"><a name="p19412124083932"></a><a name="p19412124083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row676114416083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1744892593083932p0"><a name="entry1744892593083932p0"></a><a name="entry1744892593083932p0"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1262275737083932p0"><a name="entry1262275737083932p0"></a><a name="entry1262275737083932p0"></a>输入参数，电池信息节点的路径。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示路径设置成功。

## GetBatteryInfo\(\)<a name="a4806bc306aee79990f3132fb5cd27056"></a>

```
IBatteryInterface::GetBatteryInfo ([out] struct BatteryInfo info)
```

**描述：**

获取电池的全部信息。

**参数：**

<a name="table455721358083932"></a>
<table><thead align="left"><tr id="row1783880652083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p621630804083932"><a name="p621630804083932"></a><a name="p621630804083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2077716894083932"><a name="p2077716894083932"></a><a name="p2077716894083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row163084704083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1227076232083932p0"><a name="entry1227076232083932p0"></a><a name="entry1227076232083932p0"></a>info</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry97937457083932p0"><a name="entry97937457083932p0"></a><a name="entry97937457083932p0"></a>输出参数，电池的全部信息。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取成功。

**参见：**

[BatteryInfo](_battery_info.md)

## GetCapacity\(\)<a name="a0abb3601e346bdae231648d2bcf0d37c"></a>

```
IBatteryInterface::GetCapacity ([out] int capacity)
```

**描述：**

获取电池的电量百分比。

**参数：**

<a name="table1652134155083932"></a>
<table><thead align="left"><tr id="row441021363083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1199033926083932"><a name="p1199033926083932"></a><a name="p1199033926083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p367058587083932"><a name="p367058587083932"></a><a name="p367058587083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row346528202083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry127965635083932p0"><a name="entry127965635083932p0"></a><a name="entry127965635083932p0"></a>capacity</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1395535800083932p0"><a name="entry1395535800083932p0"></a><a name="entry1395535800083932p0"></a>输出参数，表示电量的百分比值。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取成功。

## GetChargeState\(\)<a name="afeb6a5f6f7a1d07492c12f8f31cae4c3"></a>

```
IBatteryInterface::GetChargeState ([out] enum BatteryChargeState chargeState)
```

**描述：**

获取充电状态。

**参数：**

<a name="table1796251911083932"></a>
<table><thead align="left"><tr id="row1193496666083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p481707780083932"><a name="p481707780083932"></a><a name="p481707780083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1688275790083932"><a name="p1688275790083932"></a><a name="p1688275790083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1983753653083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry438973255083932p0"><a name="entry438973255083932p0"></a><a name="entry438973255083932p0"></a>chargeState</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry397329798083932p0"><a name="entry397329798083932p0"></a><a name="entry397329798083932p0"></a>输出参数，表示充电状态。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取成功。

**参见：**

[BatteryChargeState](battery.md#ga35791cca3603f7855c6368fbd00b21f1)

## GetCurrentAverage\(\)<a name="a10bf80b436e15ff386c042cadf4e8c51"></a>

```
IBatteryInterface::GetCurrentAverage ([out] int curAverage)
```

**描述：**

获取电池的平均电流。

**参数：**

<a name="table1853962444083932"></a>
<table><thead align="left"><tr id="row1482736446083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1248969377083932"><a name="p1248969377083932"></a><a name="p1248969377083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p654719413083932"><a name="p654719413083932"></a><a name="p654719413083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row127667083083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry289493340083932p0"><a name="entry289493340083932p0"></a><a name="entry289493340083932p0"></a>totalEnergy</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1139428737083932p0"><a name="entry1139428737083932p0"></a><a name="entry1139428737083932p0"></a>输出参数，表示电池的平均电流，单位毫安。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取成功。

## GetCurrentNow\(\)<a name="ad4f971592e9bb7e63d9064d944fa2dfb"></a>

```
IBatteryInterface::GetCurrentNow ([out] int curNow)
```

**描述：**

获取电池的电流。

**参数：**

<a name="table2073965796083932"></a>
<table><thead align="left"><tr id="row158407977083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p655748772083932"><a name="p655748772083932"></a><a name="p655748772083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p146431038083932"><a name="p146431038083932"></a><a name="p146431038083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1330579917083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry365885366083932p0"><a name="entry365885366083932p0"></a><a name="entry365885366083932p0"></a>curNow</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1215677724083932p0"><a name="entry1215677724083932p0"></a><a name="entry1215677724083932p0"></a>输出参数，表示电池的实时电流，单位毫安。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取成功。

## GetHealthState\(\)<a name="a2200c3f7443a9301cc3fab94400759fe"></a>

```
IBatteryInterface::GetHealthState ([out] enum BatteryHealthState healthState)
```

**描述：**

获取电池的健康状态。

**参数：**

<a name="table159461564083932"></a>
<table><thead align="left"><tr id="row491660815083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1385323761083932"><a name="p1385323761083932"></a><a name="p1385323761083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p302501612083932"><a name="p302501612083932"></a><a name="p302501612083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row788942266083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry56264216083932p0"><a name="entry56264216083932p0"></a><a name="entry56264216083932p0"></a>healthState</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1000467528083932p0"><a name="entry1000467528083932p0"></a><a name="entry1000467528083932p0"></a>输出参数，表示电池健康状态。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取成功。

**参见：**

[BatteryHealthState](battery.md#gaec9b86ee31a5d8abf7c804d81b542f2f)

## GetPluggedType\(\)<a name="abbf8efa7adc874b598b3baa6b5b1049d"></a>

```
IBatteryInterface::GetPluggedType ([out] enum BatteryPluggedType pluggedType)
```

**描述：**

获取充电设备类型。

**参数：**

<a name="table1395075795083932"></a>
<table><thead align="left"><tr id="row1078322634083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p102314366083932"><a name="p102314366083932"></a><a name="p102314366083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1938855389083932"><a name="p1938855389083932"></a><a name="p1938855389083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1977540842083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry43498993083932p0"><a name="entry43498993083932p0"></a><a name="entry43498993083932p0"></a>pluggedType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry440978475083932p0"><a name="entry440978475083932p0"></a><a name="entry440978475083932p0"></a>输出参数，表示充电设备类型。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取成功。

**参见：**

[BatteryPluggedType](battery.md#gab80029eabf9d0fdcc3ab4d4a4c3be6ba)

## GetPresent\(\)<a name="aeee555b6f97789349bf7b9d64b4d783e"></a>

```
IBatteryInterface::GetPresent ([out] boolean present)
```

**描述：**

获取是否支持电池或者电池是否在位。

**参数：**

<a name="table865622515083932"></a>
<table><thead align="left"><tr id="row1802086458083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1562150002083932"><a name="p1562150002083932"></a><a name="p1562150002083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p90212773083932"><a name="p90212773083932"></a><a name="p90212773083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1756553842083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1771991904083932p0"><a name="entry1771991904083932p0"></a><a name="entry1771991904083932p0"></a>present</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1637178631083932p0"><a name="entry1637178631083932p0"></a><a name="entry1637178631083932p0"></a>输出参数，表示是否支持电池或者电池是否在位。true表示支持或在位，false表示不支持或不在位。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取成功。

## GetRemainEnergy\(\)<a name="a057befa17672be9824d62e51de852fb4"></a>

```
IBatteryInterface::GetRemainEnergy ([out] int remainEnergy)
```

**描述：**

获取电池的剩余容量。

**参数：**

<a name="table208632981083932"></a>
<table><thead align="left"><tr id="row1419104196083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p986349676083932"><a name="p986349676083932"></a><a name="p986349676083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2135091275083932"><a name="p2135091275083932"></a><a name="p2135091275083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1665459605083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry187451654083932p0"><a name="entry187451654083932p0"></a><a name="entry187451654083932p0"></a>remainEnergy</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1072842142083932p0"><a name="entry1072842142083932p0"></a><a name="entry1072842142083932p0"></a>输出参数，表示电池的剩余容量，单位毫安时。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取成功。

## GetTechnology\(\)<a name="a70328c8f742b5a70a9c388b8c72f84e6"></a>

```
IBatteryInterface::GetTechnology ([out] String technology)
```

**描述：**

获取电池的技术型号。

**参数：**

<a name="table40071572083932"></a>
<table><thead align="left"><tr id="row999981093083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p865937930083932"><a name="p865937930083932"></a><a name="p865937930083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p728907732083932"><a name="p728907732083932"></a><a name="p728907732083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1056999657083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry95853634083932p0"><a name="entry95853634083932p0"></a><a name="entry95853634083932p0"></a>technology</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry643647424083932p0"><a name="entry643647424083932p0"></a><a name="entry643647424083932p0"></a>输出参数，当前电池技术型号。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取成功。

## GetTemperature\(\)<a name="a230716ad6e330304789ced6c6b071bb7"></a>

```
IBatteryInterface::GetTemperature ([out] int temperature)
```

**描述：**

获取电池的充电温度，单位0.1摄氏度。

**参数：**

<a name="table669493023083932"></a>
<table><thead align="left"><tr id="row814879151083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p842586197083932"><a name="p842586197083932"></a><a name="p842586197083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1549202603083932"><a name="p1549202603083932"></a><a name="p1549202603083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1935955279083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry410780708083932p0"><a name="entry410780708083932p0"></a><a name="entry410780708083932p0"></a>temperature</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1491288371083932p0"><a name="entry1491288371083932p0"></a><a name="entry1491288371083932p0"></a>输出参数，表示电池温度。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取成功。

## GetTotalEnergy\(\)<a name="a156dfa0abdc4644ef2e2be22132ec48c"></a>

```
IBatteryInterface::GetTotalEnergy ([out] int totalEnergy)
```

**描述：**

获取电池的总容量。

**参数：**

<a name="table687498024083932"></a>
<table><thead align="left"><tr id="row955426463083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1972489050083932"><a name="p1972489050083932"></a><a name="p1972489050083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p23670629083932"><a name="p23670629083932"></a><a name="p23670629083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row200282231083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1135219819083932p0"><a name="entry1135219819083932p0"></a><a name="entry1135219819083932p0"></a>totalEnergy</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2141246642083932p0"><a name="entry2141246642083932p0"></a><a name="entry2141246642083932p0"></a>输出参数，表示电池的总容量，单位毫安时。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取成功。

## GetVoltage\(\)<a name="a8847e34902b827eff5fa1f20a7f2b6f9"></a>

```
IBatteryInterface::GetVoltage ([out] int voltage)
```

**描述：**

获取电池的电压，单位微伏。

**参数：**

<a name="table1706500177083932"></a>
<table><thead align="left"><tr id="row343356588083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p907508331083932"><a name="p907508331083932"></a><a name="p907508331083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2054235384083932"><a name="p2054235384083932"></a><a name="p2054235384083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row644492325083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1439668980083932p0"><a name="entry1439668980083932p0"></a><a name="entry1439668980083932p0"></a>voltage</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2097539483083932p0"><a name="entry2097539483083932p0"></a><a name="entry2097539483083932p0"></a>输出参数，表示电池的电压。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取成功。

## Register\(\)<a name="ad92a74e22a1d2e11fa8fedc7f582559c"></a>

```
IBatteryInterface::Register ([in] IBatteryCallback event)
```

**描述：**

注册电池信息的回调。

**参数：**

<a name="table515294350083932"></a>
<table><thead align="left"><tr id="row801960446083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2016371966083932"><a name="p2016371966083932"></a><a name="p2016371966083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1674392906083932"><a name="p1674392906083932"></a><a name="p1674392906083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1921218594083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2020500573083932p0"><a name="entry2020500573083932p0"></a><a name="entry2020500573083932p0"></a>event</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1580737125083932p0"><a name="entry1580737125083932p0"></a><a name="entry1580737125083932p0"></a>输入参数，服务注册的回调。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示注册成功。

## UnRegister\(\)<a name="ab7d303718899d2ef079f85c72c3412cd"></a>

```
IBatteryInterface::UnRegister ()
```

**描述：**

取消注册电池信息的回调。

**返回：**

HDF\_SUCCESS 表示取消注册成功。

