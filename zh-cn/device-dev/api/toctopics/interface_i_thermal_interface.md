# IThermalInterface<a name="ZH-CN_TOPIC_0000001343120349"></a>

## **概述**<a name="section1774562916083932"></a>

**所属模块:**

[Thermal](thermal.md)

## **汇总**<a name="section1306493347083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table1866961550083932"></a>
<table><thead align="left"><tr id="row2104761370083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1992210121083932"><a name="p1992210121083932"></a><a name="p1992210121083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1665632850083932"><a name="p1665632850083932"></a><a name="p1665632850083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2012446748083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p737562792083932"><a name="p737562792083932"></a><a name="p737562792083932"></a><a href="interface_i_thermal_interface.md#a48361072473e883e01d0d8d4e39a4b60">SetCpuFreq</a> ([in] int freq)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1241738909083932"><a name="p1241738909083932"></a><a name="p1241738909083932"></a>设置CPU频率。 <a href="interface_i_thermal_interface.md#a48361072473e883e01d0d8d4e39a4b60">更多...</a></p>
</td>
</tr>
<tr id="row1478508081083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p513754700083932"><a name="p513754700083932"></a><a name="p513754700083932"></a><a href="interface_i_thermal_interface.md#a10c09de95897610e2e31f0a459a6a802">SetGpuFreq</a> ([in] int freq)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1122084372083932"><a name="p1122084372083932"></a><a name="p1122084372083932"></a>设置GPU频率。 <a href="interface_i_thermal_interface.md#a10c09de95897610e2e31f0a459a6a802">更多...</a></p>
</td>
</tr>
<tr id="row255463294083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p125565877083932"><a name="p125565877083932"></a><a name="p125565877083932"></a><a href="interface_i_thermal_interface.md#a37f45e4aea73c4d8fef2e7d46e715c6e">SetBatteryCurrent</a> ([in] int current)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1367079147083932"><a name="p1367079147083932"></a><a name="p1367079147083932"></a>设置充电电流。 <a href="interface_i_thermal_interface.md#a37f45e4aea73c4d8fef2e7d46e715c6e">更多...</a></p>
</td>
</tr>
<tr id="row1570156706083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1338437638083932"><a name="p1338437638083932"></a><a name="p1338437638083932"></a><a href="interface_i_thermal_interface.md#aeb140e31d471455aa9df8d09e9adb7b4">GetThermalZoneInfo</a> ([out] struct <a href="_hdf_thermal_callback_info.md">HdfThermalCallbackInfo</a> event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1252807945083932"><a name="p1252807945083932"></a><a name="p1252807945083932"></a>获取设备发热的信息。 <a href="interface_i_thermal_interface.md#aeb140e31d471455aa9df8d09e9adb7b4">更多...</a></p>
</td>
</tr>
<tr id="row1796007375083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p244297288083932"><a name="p244297288083932"></a><a name="p244297288083932"></a><a href="interface_i_thermal_interface.md#a031669e1df8628e9210ee7b246313451">Register</a> ([in] <a href="interface_i_thermal_callback.md">IThermalCallback</a> callbackObj)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1432443310083932"><a name="p1432443310083932"></a><a name="p1432443310083932"></a>注册设备发热状态的回调。 <a href="interface_i_thermal_interface.md#a031669e1df8628e9210ee7b246313451">更多...</a></p>
</td>
</tr>
<tr id="row2043635947083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1548038685083932"><a name="p1548038685083932"></a><a name="p1548038685083932"></a><a href="interface_i_thermal_interface.md#ac6d4ecc51939272d8bd5ead21a83de20">Unregister</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1592577322083932"><a name="p1592577322083932"></a><a name="p1592577322083932"></a>取消注册设备发热状态的回调。 <a href="interface_i_thermal_interface.md#ac6d4ecc51939272d8bd5ead21a83de20">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section958623693083932"></a>

设备温度管理、控制及订阅接口。

服务获取此对象后，可以调用相关的接口管理、控制和订阅设备温度。

**Since：**

3.1

## **成员函数说明**<a name="section956830085083932"></a>

## GetThermalZoneInfo\(\)<a name="aeb140e31d471455aa9df8d09e9adb7b4"></a>

```
IThermalInterface::GetThermalZoneInfo ([out] struct HdfThermalCallbackInfo event)
```

**描述：**

获取设备发热的信息。

**参数：**

<a name="table855629649083932"></a>
<table><thead align="left"><tr id="row1832861295083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1640646805083932"><a name="p1640646805083932"></a><a name="p1640646805083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1575809974083932"><a name="p1575809974083932"></a><a name="p1575809974083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1052214928083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry83665843083932p0"><a name="entry83665843083932p0"></a><a name="entry83665843083932p0"></a>event</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry708413056083932p0"><a name="entry708413056083932p0"></a><a name="entry708413056083932p0"></a>输出参数，设备发热信息，包括器件类型、器件温度。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取成功。

**参见：**

[HdfThermalCallbackInfo](_hdf_thermal_callback_info.md)

## Register\(\)<a name="a031669e1df8628e9210ee7b246313451"></a>

```
IThermalInterface::Register ([in] IThermalCallback callbackObj)
```

**描述：**

注册设备发热状态的回调。

**参数：**

<a name="table1690931980083932"></a>
<table><thead align="left"><tr id="row720762268083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p935339259083932"><a name="p935339259083932"></a><a name="p935339259083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p357834003083932"><a name="p357834003083932"></a><a name="p357834003083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1155242186083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1909631431083932p0"><a name="entry1909631431083932p0"></a><a name="entry1909631431083932p0"></a>callbackObj</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry969098796083932p0"><a name="entry969098796083932p0"></a><a name="entry969098796083932p0"></a>输入参数，服务注册的回调。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示注册成功。

**参见：**

[IThermalCallback](interface_i_thermal_callback.md)

## SetBatteryCurrent\(\)<a name="a37f45e4aea73c4d8fef2e7d46e715c6e"></a>

```
IThermalInterface::SetBatteryCurrent ([in] int current)
```

**描述：**

设置充电电流。

**参数：**

<a name="table330475504083932"></a>
<table><thead align="left"><tr id="row269394362083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1896293317083932"><a name="p1896293317083932"></a><a name="p1896293317083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1384680624083932"><a name="p1384680624083932"></a><a name="p1384680624083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1288906156083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1512627594083932p0"><a name="entry1512627594083932p0"></a><a name="entry1512627594083932p0"></a>current</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry785316386083932p0"><a name="entry785316386083932p0"></a><a name="entry785316386083932p0"></a>输入参数，充电电流，单位毫安。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示设置成功

## SetCpuFreq\(\)<a name="a48361072473e883e01d0d8d4e39a4b60"></a>

```
IThermalInterface::SetCpuFreq ([in] int freq)
```

**描述：**

设置CPU频率。

**参数：**

<a name="table230517037083932"></a>
<table><thead align="left"><tr id="row2058306316083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1619228043083932"><a name="p1619228043083932"></a><a name="p1619228043083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1650729200083932"><a name="p1650729200083932"></a><a name="p1650729200083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row635254450083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1727914329083932p0"><a name="entry1727914329083932p0"></a><a name="entry1727914329083932p0"></a>freq</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1528292284083932p0"><a name="entry1528292284083932p0"></a><a name="entry1528292284083932p0"></a>输入参数，设置CPU频率的值。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示设置成功。

## SetGpuFreq\(\)<a name="a10c09de95897610e2e31f0a459a6a802"></a>

```
IThermalInterface::SetGpuFreq ([in] int freq)
```

**描述：**

设置GPU频率。

**参数：**

<a name="table37275613083932"></a>
<table><thead align="left"><tr id="row1565828717083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1795901138083932"><a name="p1795901138083932"></a><a name="p1795901138083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1814364757083932"><a name="p1814364757083932"></a><a name="p1814364757083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1492610394083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry478473147083932p0"><a name="entry478473147083932p0"></a><a name="entry478473147083932p0"></a>freq</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry474372637083932p0"><a name="entry474372637083932p0"></a><a name="entry474372637083932p0"></a>输入参数，设置GPU频率的值。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示设置成功。

## Unregister\(\)<a name="ac6d4ecc51939272d8bd5ead21a83de20"></a>

```
IThermalInterface::Unregister ()
```

**描述：**

取消注册设备发热状态的回调。

**返回：**

HDF\_SUCCESS 表示取消注册成功。

