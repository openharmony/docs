# InputManager<a name="ZH-CN_TOPIC_0000001290561184"></a>

## **概述**<a name="section1773654478083932"></a>

**所属模块:**

[Input](_input.md)

## **汇总**<a name="section1409129743083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1090284407083932"></a>
<table><thead align="left"><tr id="row1999417771083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1673435983083932"><a name="p1673435983083932"></a><a name="p1673435983083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1467148922083932"><a name="p1467148922083932"></a><a name="p1467148922083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1216122878083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1139708733083932"><a name="p1139708733083932"></a><a name="p1139708733083932"></a>( <a href="_input_manager.md#a88865cf8fa852d45900dc1c11116f179">ScanInputDevice</a> )(DevDesc *staArr, uint32_t arrLen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1511899538083932"><a name="p1511899538083932"></a><a name="p1511899538083932"></a>input服务用于扫描所有在线设备。 <a href="_input_manager.md#a88865cf8fa852d45900dc1c11116f179">更多...</a></p>
</td>
</tr>
<tr id="row185318529083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1604656309083932"><a name="p1604656309083932"></a><a name="p1604656309083932"></a>( <a href="_input_manager.md#a9153e901b4811654d8dfc2e78aa29f07">OpenInputDevice</a> )(uint32_t devIndex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p874045340083932"><a name="p874045340083932"></a><a name="p874045340083932"></a>input服务打开对应设备的设备文件 <a href="_input_manager.md#a9153e901b4811654d8dfc2e78aa29f07">更多...</a></p>
</td>
</tr>
<tr id="row1952320614083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p230039118083932"><a name="p230039118083932"></a><a name="p230039118083932"></a>( <a href="_input_manager.md#a41f3a8a5d8995c9a08bd90c1d367209d">CloseInputDevice</a> )(uint32_t devIndex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1768731773083932"><a name="p1768731773083932"></a><a name="p1768731773083932"></a>input服务关闭对应设备的设备文件 <a href="_input_manager.md#a41f3a8a5d8995c9a08bd90c1d367209d">更多...</a></p>
</td>
</tr>
<tr id="row584417971083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p245260377083932"><a name="p245260377083932"></a><a name="p245260377083932"></a>( <a href="_input_manager.md#abf32ba302df150d952714776e1707bc5">GetInputDevice</a> )(uint32_t devIndex, <a href="_device_info.md">DeviceInfo</a> **devInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1939958383083932"><a name="p1939958383083932"></a><a name="p1939958383083932"></a>input服务获取对应ID的设备信息 <a href="_input_manager.md#abf32ba302df150d952714776e1707bc5">更多...</a></p>
</td>
</tr>
<tr id="row1917591473083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1135479281083932"><a name="p1135479281083932"></a><a name="p1135479281083932"></a>( <a href="_input_manager.md#a74f11b9e24d19413f5eb9b35700be078">GetInputDeviceList</a> )(uint32_t *devNum, <a href="_device_info.md">DeviceInfo</a> **devList, uint32_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p816499649083932"><a name="p816499649083932"></a><a name="p816499649083932"></a>input服务获取所有input设备列表的设备信息 <a href="_input_manager.md#a74f11b9e24d19413f5eb9b35700be078">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section138929233083932"></a>

提供input设备管理相关的接口。

此类接口包含input设备的扫描、打开和关闭、特定设备信息查询，以及所有设备列表信息获取等接口。

## **类成员变量说明**<a name="section432508033083932"></a>

## CloseInputDevice<a name="a41f3a8a5d8995c9a08bd90c1d367209d"></a>

```
int32_t(* InputManager::CloseInputDevice) (uint32_t devIndex)
```

**描述：**

input服务关闭对应设备的设备文件

**参数：**

<a name="table1605947082083932"></a>
<table><thead align="left"><tr id="row1387718629083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1342901408083932"><a name="p1342901408083932"></a><a name="p1342901408083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1849513122083932"><a name="p1849513122083932"></a><a name="p1849513122083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1630799208083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1697170856083932p0"><a name="entry1697170856083932p0"></a><a name="entry1697170856083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry788516653083932p0"><a name="entry788516653083932p0"></a><a name="entry788516653083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

## GetInputDevice<a name="abf32ba302df150d952714776e1707bc5"></a>

```
int32_t(* InputManager::GetInputDevice) (uint32_t devIndex, DeviceInfo **devInfo)
```

**描述：**

input服务获取对应ID的设备信息。

**参数：**

<a name="table1168178706083932"></a>
<table><thead align="left"><tr id="row1235758766083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p269528320083932"><a name="p269528320083932"></a><a name="p269528320083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2019398926083932"><a name="p2019398926083932"></a><a name="p2019398926083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1226815059083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1576972187083932p0"><a name="entry1576972187083932p0"></a><a name="entry1576972187083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry967555163083932p0"><a name="entry967555163083932p0"></a><a name="entry967555163083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备。</p>
</td>
</tr>
<tr id="row630773833083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1881491975083932p0"><a name="entry1881491975083932p0"></a><a name="entry1881491975083932p0"></a>devInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry149305610083932p0"><a name="entry149305610083932p0"></a><a name="entry149305610083932p0"></a>即devIndex对应设备的设备信息，具体参考<strong id="b781115219166"><a name="b781115219166"></a><a name="b781115219166"></a>DeviceInfo</strong>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

## GetInputDeviceList<a name="a74f11b9e24d19413f5eb9b35700be078"></a>

```
int32_t(* InputManager::GetInputDeviceList) (uint32_t *devNum, DeviceInfo **devList, uint32_t size)
```

**描述：**

input服务获取所有input设备列表的设备信息。

**参数：**

<a name="table1487255171083932"></a>
<table><thead align="left"><tr id="row790604719083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1654529251083932"><a name="p1654529251083932"></a><a name="p1654529251083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1881222600083932"><a name="p1881222600083932"></a><a name="p1881222600083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row883304418083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1292899283083932p0"><a name="entry1292899283083932p0"></a><a name="entry1292899283083932p0"></a>devNum</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1671228451083932p0"><a name="entry1671228451083932p0"></a><a name="entry1671228451083932p0"></a>当前已经注册过的所有input设备的总数。</p>
</td>
</tr>
<tr id="row734222093083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry264647790083932p0"><a name="entry264647790083932p0"></a><a name="entry264647790083932p0"></a>devInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1865367509083932p0"><a name="entry1865367509083932p0"></a><a name="entry1865367509083932p0"></a>input设备列表所对应的设备信息，具体参考<strong id="b727510179187"><a name="b727510179187"></a><a name="b727510179187"></a>DeviceInfo</strong>。</p>
</td>
</tr>
<tr id="row89405197175"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p994131910172"><a name="p994131910172"></a><a name="p994131910172"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p10941161911718"><a name="p10941161911718"></a><a name="p10941161911718"></a>即指定deviceList数组对应的元素个数。</p>
</td>
</tr>
</tbody>
</table>

返回：

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

## OpenInputDevice<a name="a9153e901b4811654d8dfc2e78aa29f07"></a>

```
int32_t(* InputManager::OpenInputDevice) (uint32_t devIndex)
```

**描述：**

input服务打开对应设备的设备文件

**参数：**

<a name="table726821116083932"></a>
<table><thead align="left"><tr id="row362004650083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p868577499083932"><a name="p868577499083932"></a><a name="p868577499083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p525547561083932"><a name="p525547561083932"></a><a name="p525547561083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1684739480083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1660939084083932p0"><a name="entry1660939084083932p0"></a><a name="entry1660939084083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry149574193083932p0"><a name="entry149574193083932p0"></a><a name="entry149574193083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

## ScanInputDevice<a name="a88865cf8fa852d45900dc1c11116f179"></a>

```
int32_t(* InputManager::ScanInputDevice) (DevDesc *staArr, uint32_t arrLen)
```

**描述：**

input服务用于扫描所有在线设备。

**参数：**

<a name="table291125003083932"></a>
<table><thead align="left"><tr id="row1155662345083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1952064077083932"><a name="p1952064077083932"></a><a name="p1952064077083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1454190491083932"><a name="p1454190491083932"></a><a name="p1454190491083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row307303727083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry767500553083932p0"><a name="entry767500553083932p0"></a><a name="entry767500553083932p0"></a>staArr</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1497939174083932p0"><a name="entry1497939174083932p0"></a><a name="entry1497939174083932p0"></a>存放Input设备扫描信息的数组，信息包含设备索引以及设备类型。</p>
</td>
</tr>
<tr id="row390722712083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1964031112083932p0"><a name="entry1964031112083932p0"></a><a name="entry1964031112083932p0"></a>arrLen</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2073028787083932p0"><a name="entry2073028787083932p0"></a><a name="entry2073028787083932p0"></a>staArr数组的长度信息。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

