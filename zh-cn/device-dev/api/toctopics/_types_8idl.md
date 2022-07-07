# Types.idl<a name="ZH-CN_TOPIC_0000001343321057"></a>

## **概述**<a name="section6325975083932"></a>

**所属模块:**

[Battery](battery.md)

## **汇总**<a name="section12342537083932"></a>

## 类<a name="nested-classes"></a>

<a name="table766223494083932"></a>
<table><thead align="left"><tr id="row561302998083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p886296095083932"><a name="p886296095083932"></a><a name="p886296095083932"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1395198574083932"><a name="p1395198574083932"></a><a name="p1395198574083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row367137560083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1962660119083931"><a name="p1962660119083931"></a><a name="p1962660119083931"></a><a href="_battery_info.md">BatteryInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1264535846083931"><a name="p1264535846083931"></a><a name="p1264535846083931"></a>电池相关信息。 <a href="_battery_info.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 枚举<a name="enum-members"></a>

<a name="table838230823083932"></a>
<table><thead align="left"><tr id="row1942453949083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p403572618083932"><a name="p403572618083932"></a><a name="p403572618083932"></a>枚举</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1090080729083932"><a name="p1090080729083932"></a><a name="p1090080729083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row893604216083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p239896966083932"><a name="p239896966083932"></a><a name="p239896966083932"></a><a href="battery.md#gaec9b86ee31a5d8abf7c804d81b542f2f">BatteryHealthState</a> {   <a href="battery.md#ggaec9b86ee31a5d8abf7c804d81b542f2fa383fc8bba89eb9195e07da10ebff6a6a">BATTERY_HEALTH_UNKNOWN</a> = 0, <a href="battery.md#ggaec9b86ee31a5d8abf7c804d81b542f2fa9019a1cab9aaffb56b968f846eae45c2">BATTERY_HEALTH_GOOD</a>, <a href="battery.md#ggaec9b86ee31a5d8abf7c804d81b542f2fa34cb203c04d3f8b391fd0f193673d2cc">BATTERY_HEALTH_OVERHEAT</a>, <a href="battery.md#ggaec9b86ee31a5d8abf7c804d81b542f2faeb20e3755faa28a34b37c20fce37672f">BATTERY_HEALTH_OVERVOLTAGE</a>,   <a href="battery.md#ggaec9b86ee31a5d8abf7c804d81b542f2fa1ed5e419d57b9ff71ac397d1b17eb420">BATTERY_HEALTH_COLD</a>, <a href="battery.md#ggaec9b86ee31a5d8abf7c804d81b542f2fa05f1241d31443ffefec7ac784e141341">BATTERY_HEALTH_DEAD</a>, <a href="battery.md#ggaec9b86ee31a5d8abf7c804d81b542f2fa9583572172c946660b255d5ac3604f9b">BATTERY_HEALTH_RESERVED</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1668214390083932"><a name="p1668214390083932"></a><a name="p1668214390083932"></a>电池的健康状态。 <a href="battery.md#gaec9b86ee31a5d8abf7c804d81b542f2f">更多...</a></p>
</td>
</tr>
<tr id="row1843272617083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1131007818083932"><a name="p1131007818083932"></a><a name="p1131007818083932"></a><a href="battery.md#ga35791cca3603f7855c6368fbd00b21f1">BatteryChargeState</a> {   <a href="battery.md#gga35791cca3603f7855c6368fbd00b21f1afdc91bf6bc92fdcd784cb274b1a14d28">CHARGE_STATE_NONE</a> = 0, <a href="battery.md#gga35791cca3603f7855c6368fbd00b21f1a03dc57c4f65da6b1472ae4f7ed676234">CHARGE_STATE_ENABLE</a>, <a href="battery.md#gga35791cca3603f7855c6368fbd00b21f1a33914f4c27c801d3ba5315ca486655cc">CHARGE_STATE_DISABLE</a>, <a href="battery.md#gga35791cca3603f7855c6368fbd00b21f1a70b48a2925871d0364ae6344bce944ae">CHARGE_STATE_FULL</a>,   <a href="battery.md#gga35791cca3603f7855c6368fbd00b21f1a38af1f4d697139ebaa8eb97fb5b34120">CHARGE_STATE_RESERVED</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p424305356083932"><a name="p424305356083932"></a><a name="p424305356083932"></a>电池的充电状态。 <a href="battery.md#ga35791cca3603f7855c6368fbd00b21f1">更多...</a></p>
</td>
</tr>
<tr id="row2091763269083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p165610259083932"><a name="p165610259083932"></a><a name="p165610259083932"></a><a href="battery.md#gab80029eabf9d0fdcc3ab4d4a4c3be6ba">BatteryPluggedType</a> {   <a href="battery.md#ggab80029eabf9d0fdcc3ab4d4a4c3be6baa23f13d9ed048300c42930d844ead29c7">PLUGGED_TYPE_NONE</a> = 0, <a href="battery.md#ggab80029eabf9d0fdcc3ab4d4a4c3be6baaba143c5ab6146a49e3c1362d3ba38751">PLUGGED_TYPE_AC</a>, <a href="battery.md#ggab80029eabf9d0fdcc3ab4d4a4c3be6baacfe481a50e9915a049edd3debcc7de1c">PLUGGED_TYPE_USB</a>, <a href="battery.md#ggab80029eabf9d0fdcc3ab4d4a4c3be6baaa8b900a0327e60b02ad7d3501057be38">PLUGGED_TYPE_WIRELESS</a>,   <a href="battery.md#ggab80029eabf9d0fdcc3ab4d4a4c3be6baac85bb1a7b26e14b55cd9bb977c3e66c0">PLUGGED_TYPE_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p508740713083932"><a name="p508740713083932"></a><a name="p508740713083932"></a>电池的充电设备类型。 <a href="battery.md#gab80029eabf9d0fdcc3ab4d4a4c3be6ba">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 变量<a name="var-members"></a>

<a name="table87694618083932"></a>
<table><thead align="left"><tr id="row1845028341083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1650151271083932"><a name="p1650151271083932"></a><a name="p1650151271083932"></a>变量 名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p240198648083932"><a name="p240198648083932"></a><a name="p240198648083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1880946993083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p14796448172411"><a name="p14796448172411"></a><a name="p14796448172411"></a>package ohos.hdi.battery.v1_0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p346903012185"><a name="p346903012185"></a><a name="p346903012185"></a>电池信息接口的包路径</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1922568893083932"></a>

电池信息相关数据类型。

电池信息中使用的数据类型，包括健康状态、充电状态、充电设备类型和电池信息结构。

**Since：**

3.1

**Version：**

1.0

