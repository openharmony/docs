# InputController<a name="ZH-CN_TOPIC_0000001343000869"></a>

## **概述**<a name="section685843372083932"></a>

**所属模块:**

[Input](_input.md)

## **汇总**<a name="section531156924083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table100184007083932"></a>
<table><thead align="left"><tr id="row1354973408083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1184926168083932"><a name="p1184926168083932"></a><a name="p1184926168083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p446180481083932"><a name="p446180481083932"></a><a name="p446180481083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1712747115083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1102796665083932"><a name="p1102796665083932"></a><a name="p1102796665083932"></a>( <a href="_input_controller.md#a38da915fec2698dff480ed686503f692">SetPowerStatus</a> )(uint32_t devIndex, uint32_t status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p121237636083932"><a name="p121237636083932"></a><a name="p121237636083932"></a>设置电源状态 <a href="_input_controller.md#a38da915fec2698dff480ed686503f692">更多...</a></p>
</td>
</tr>
<tr id="row447505307083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p62971503083932"><a name="p62971503083932"></a><a name="p62971503083932"></a>( <a href="_input_controller.md#afd9ffc4a180609ad970df6fd79806372">GetPowerStatus</a> )(uint32_t devIndex, uint32_t *status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1648404033083932"><a name="p1648404033083932"></a><a name="p1648404033083932"></a>获取电源状态 <a href="_input_controller.md#afd9ffc4a180609ad970df6fd79806372">更多...</a></p>
</td>
</tr>
<tr id="row616414304083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p492070231083932"><a name="p492070231083932"></a><a name="p492070231083932"></a>( <a href="_input_controller.md#aec8d8a22b37f572a9df8ef7ce988a6d3">GetDeviceType</a> )(uint32_t devIndex, uint32_t *deviceType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1123465553083932"><a name="p1123465553083932"></a><a name="p1123465553083932"></a>获取devIndex对应的input设备的类型 <a href="_input_controller.md#aec8d8a22b37f572a9df8ef7ce988a6d3">更多...</a></p>
</td>
</tr>
<tr id="row947535078083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1735453217083932"><a name="p1735453217083932"></a><a name="p1735453217083932"></a>( <a href="_input_controller.md#aa02ce599f0383c88e6efc301e31901b8">GetChipInfo</a> )(uint32_t devIndex, char *chipInfo, uint32_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1118726605083932"><a name="p1118726605083932"></a><a name="p1118726605083932"></a>获取器件对应的编码信息 <a href="_input_controller.md#aa02ce599f0383c88e6efc301e31901b8">更多...</a></p>
</td>
</tr>
<tr id="row1415288568083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p19769793083932"><a name="p19769793083932"></a><a name="p19769793083932"></a>( <a href="_input_controller.md#ab011f8433b9c5aa8493320dac9c4a683">GetVendorName</a> )(uint32_t devIndex, char *vendorName, uint32_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p55038143083932"><a name="p55038143083932"></a><a name="p55038143083932"></a>获取devIndex对应的模组厂商名 <a href="_input_controller.md#ab011f8433b9c5aa8493320dac9c4a683">更多...</a></p>
</td>
</tr>
<tr id="row1599760854083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p364897134083932"><a name="p364897134083932"></a><a name="p364897134083932"></a>( <a href="_input_controller.md#aaa131995539b4c0b783cdcbdd67b9687">GetChipName</a> )(uint32_t devIndex, char *chipName, uint32_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1232997528083932"><a name="p1232997528083932"></a><a name="p1232997528083932"></a>获取devIndex对应的驱动芯片名 <a href="_input_controller.md#aaa131995539b4c0b783cdcbdd67b9687">更多...</a></p>
</td>
</tr>
<tr id="row436608151083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1092929536083932"><a name="p1092929536083932"></a><a name="p1092929536083932"></a>( <a href="_input_controller.md#a2a5b24dfc129b58ae4663ca44ab2ad91">SetGestureMode</a> )(uint32_t devIndex, uint32_t gestureMode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p144327943083932"><a name="p144327943083932"></a><a name="p144327943083932"></a>设置手势模式 <a href="_input_controller.md#a2a5b24dfc129b58ae4663ca44ab2ad91">更多...</a></p>
</td>
</tr>
<tr id="row1125233516083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p836316868083932"><a name="p836316868083932"></a><a name="p836316868083932"></a>( <a href="_input_controller.md#afc470fb6e33a07aaa179980a4ded39db">RunCapacitanceTest</a> )(uint32_t devIndex, uint32_t testType, char *result, uint32_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1204888482083932"><a name="p1204888482083932"></a><a name="p1204888482083932"></a>执行容值自检测试 <a href="_input_controller.md#afc470fb6e33a07aaa179980a4ded39db">更多...</a></p>
</td>
</tr>
<tr id="row453418848083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1711525898083932"><a name="p1711525898083932"></a><a name="p1711525898083932"></a>( <a href="_input_controller.md#a19c15b3b535f63fbc4e17bbad24492c9">RunExtraCommand</a> )(uint32_t devIndex, <a href="_input_extra_cmd.md">InputExtraCmd</a> *cmd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p895533507083932"><a name="p895533507083932"></a><a name="p895533507083932"></a>执行拓展指令 <a href="_input_controller.md#a19c15b3b535f63fbc4e17bbad24492c9">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1646415217083932"></a>

提供input设备业务控制相关的接口。

此类接口包含电源状态的设置、特性的使能、器件信息的获取，以及产线相关的测试功能接口。

## **类成员变量说明**<a name="section316726925083932"></a>

## GetChipInfo<a name="aa02ce599f0383c88e6efc301e31901b8"></a>

```
int32_t(* InputController::GetChipInfo) (uint32_t devIndex, char *chipInfo, uint32_t length)
```

**描述：**

获取器件对应的编码信息

一款产品通常会有多家模组和Driver IC，上层应用如果关注具体器件型号，则通过此接口来获取。

**参数：**

<a name="table2061508314083932"></a>
<table><thead align="left"><tr id="row223367084083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p178735291083932"><a name="p178735291083932"></a><a name="p178735291083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p412809727083932"><a name="p412809727083932"></a><a name="p412809727083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row937168554083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2026261679083932p0"><a name="entry2026261679083932p0"></a><a name="entry2026261679083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry858590437083932p0"><a name="entry858590437083932p0"></a><a name="entry858590437083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备。</p>
</td>
</tr>
<tr id="row783967861083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry432526479083932p0"><a name="entry432526479083932p0"></a><a name="entry432526479083932p0"></a>chipInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry966087685083932p0"><a name="entry966087685083932p0"></a><a name="entry966087685083932p0"></a>获取的对应设备索引的器件编码信息。</p>
</td>
</tr>
<tr id="row1671807795083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry340745016083932p0"><a name="entry340745016083932p0"></a><a name="entry340745016083932p0"></a>length</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1273016781083932p0"><a name="entry1273016781083932p0"></a><a name="entry1273016781083932p0"></a>保存器件芯片信息的内存长度。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

## GetChipName<a name="aaa131995539b4c0b783cdcbdd67b9687"></a>

```
int32_t(* InputController::GetChipName) (uint32_t devIndex, char *chipName, uint32_t length)
```

**描述：**

获取devIndex对应的驱动芯片名

**参数：**

<a name="table578672107083932"></a>
<table><thead align="left"><tr id="row1928021193083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1528822189083932"><a name="p1528822189083932"></a><a name="p1528822189083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1518952142083932"><a name="p1518952142083932"></a><a name="p1518952142083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2020372035083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1745035438083932p0"><a name="entry1745035438083932p0"></a><a name="entry1745035438083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1945349360083932p0"><a name="entry1945349360083932p0"></a><a name="entry1945349360083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备。</p>
</td>
</tr>
<tr id="row427917643083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry210986009083932p0"><a name="entry210986009083932p0"></a><a name="entry210986009083932p0"></a>chipName</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1016393891083932p0"><a name="entry1016393891083932p0"></a><a name="entry1016393891083932p0"></a>获取的对应设备索引的驱动芯片名。</p>
</td>
</tr>
<tr id="row1051639607083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry302075584083932p0"><a name="entry302075584083932p0"></a><a name="entry302075584083932p0"></a>length</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1976581860083932p0"><a name="entry1976581860083932p0"></a><a name="entry1976581860083932p0"></a>保存驱动芯片名的内存长度。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

## GetDeviceType<a name="aec8d8a22b37f572a9df8ef7ce988a6d3"></a>

```
int32_t(* InputController::GetDeviceType) (uint32_t devIndex, uint32_t *deviceType)
```

**描述：**

获取devIndex对应的input设备的类型

**参数：**

<a name="table591679917083932"></a>
<table><thead align="left"><tr id="row3346939083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p535481820083932"><a name="p535481820083932"></a><a name="p535481820083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p914608954083932"><a name="p914608954083932"></a><a name="p914608954083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1155237828083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1818855014083932p0"><a name="entry1818855014083932p0"></a><a name="entry1818855014083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1079610184083932p0"><a name="entry1079610184083932p0"></a><a name="entry1079610184083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备。</p>
</td>
</tr>
<tr id="row2027824868083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1151588618083932p0"><a name="entry1151588618083932p0"></a><a name="entry1151588618083932p0"></a>deviceType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry922709241083932p0"><a name="entry922709241083932p0"></a><a name="entry922709241083932p0"></a>获取的对应设备索引的设备类型，具体参考 <strong id="b10777122419534"><a name="b10777122419534"></a><a name="b10777122419534"></a>InputDevType</strong>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

## GetPowerStatus<a name="afd9ffc4a180609ad970df6fd79806372"></a>

```
int32_t(* InputController::GetPowerStatus) (uint32_t devIndex, uint32_t *status)
```

**描述：**

获取电源状态

在系统休眠或者唤醒时，input服务或电源管理模块获取电源状态，以便驱动IC能正常进入对应的休眠模式。

**参数：**

<a name="table1849761396083932"></a>
<table><thead align="left"><tr id="row2679854083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p353182349083932"><a name="p353182349083932"></a><a name="p353182349083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1723013004083932"><a name="p1723013004083932"></a><a name="p1723013004083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row688802923083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1476342193083932p0"><a name="entry1476342193083932p0"></a><a name="entry1476342193083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry397076397083932p0"><a name="entry397076397083932p0"></a><a name="entry397076397083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备。</p>
</td>
</tr>
<tr id="row1656774332083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry899271958083932p0"><a name="entry899271958083932p0"></a><a name="entry899271958083932p0"></a>status</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1562084525083932p0"><a name="entry1562084525083932p0"></a><a name="entry1562084525083932p0"></a>获取的对应设备索引的电源状态，具体参考<strong id="b99904401033"><a name="b99904401033"></a><a name="b99904401033"></a>PowerStatus</strong>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus。**

## GetVendorName<a name="ab011f8433b9c5aa8493320dac9c4a683"></a>

```
int32_t(* InputController::GetVendorName) (uint32_t devIndex, char *vendorName, uint32_t length)
```

**描述：**

获取devIndex对应的模组厂商名

**参数：**

<a name="table1590392039083932"></a>
<table><thead align="left"><tr id="row300692609083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2030815123083932"><a name="p2030815123083932"></a><a name="p2030815123083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p833327104083932"><a name="p833327104083932"></a><a name="p833327104083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row624698645083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1224383010083932p0"><a name="entry1224383010083932p0"></a><a name="entry1224383010083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1973918272083932p0"><a name="entry1973918272083932p0"></a><a name="entry1973918272083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备。</p>
</td>
</tr>
<tr id="row759216874083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1401845337083932p0"><a name="entry1401845337083932p0"></a><a name="entry1401845337083932p0"></a>vendorName</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry321348005083932p0"><a name="entry321348005083932p0"></a><a name="entry321348005083932p0"></a>获取的对应设备索引的模组厂商名。</p>
</td>
</tr>
<tr id="row453286741083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry363308756083932p0"><a name="entry363308756083932p0"></a><a name="entry363308756083932p0"></a>length</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1185954031083932p0"><a name="entry1185954031083932p0"></a><a name="entry1185954031083932p0"></a>保存模组厂商名的内存长度。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

## RunCapacitanceTest<a name="afc470fb6e33a07aaa179980a4ded39db"></a>

```
int32_t(* InputController::RunCapacitanceTest) (uint32_t devIndex, uint32_t testType, char *result, uint32_t length)
```

**描述：**

执行容值自检测试

启动不同检测场景下的容值自检测试，并获取测试结果，容值自检项由器件厂商自定义， 一般包括RawData测试、 \* 短路检测、开路检测、干扰检测、行列差检测等测试项。

**参数：**

<a name="table1513482242083932"></a>
<table><thead align="left"><tr id="row2035408823083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p606186105083932"><a name="p606186105083932"></a><a name="p606186105083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1084239489083932"><a name="p1084239489083932"></a><a name="p1084239489083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1076083609083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry20332858083932p0"><a name="entry20332858083932p0"></a><a name="entry20332858083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1507809255083932p0"><a name="entry1507809255083932p0"></a><a name="entry1507809255083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备。</p>
</td>
</tr>
<tr id="row930184722083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1208029136083932p0"><a name="entry1208029136083932p0"></a><a name="entry1208029136083932p0"></a>testType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry22284406083932p0"><a name="entry22284406083932p0"></a><a name="entry22284406083932p0"></a>容值测试的测试类型，具体参考<strong id="b18131640270"><a name="b18131640270"></a><a name="b18131640270"></a>CapacitanceTest</strong>。</p>
</td>
</tr>
<tr id="row14639938056"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p13640338858"><a name="p13640338858"></a><a name="p13640338858"></a>result</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p664017381354"><a name="p664017381354"></a><a name="p664017381354"></a>容值测试的结果，成功则输出“SUCCESS”，失败则返回对应的错误提示 。</p>
</td>
</tr>
<tr id="row8588748956"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p8588114819515"><a name="p8588114819515"></a><a name="p8588114819515"></a>length</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p9588348453"><a name="p9588348453"></a><a name="p9588348453"></a>保存容值测试结果的内存长度。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

## RunExtraCommand<a name="a19c15b3b535f63fbc4e17bbad24492c9"></a>

```
int32_t(* InputController::RunExtraCommand) (uint32_t devIndex, InputExtraCmd *cmd)
```

**描述：**

执行拓展指令

**参数：**

<a name="table372158503083932"></a>
<table><thead align="left"><tr id="row410371769083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p930683410083932"><a name="p930683410083932"></a><a name="p930683410083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1458589218083932"><a name="p1458589218083932"></a><a name="p1458589218083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row757368640083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2045857176083932p0"><a name="entry2045857176083932p0"></a><a name="entry2045857176083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry597805429083932p0"><a name="entry597805429083932p0"></a><a name="entry597805429083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备。</p>
</td>
</tr>
<tr id="row1507348885083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry179951755083932p0"><a name="entry179951755083932p0"></a><a name="entry179951755083932p0"></a>cmd</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1064706693083932p0"><a name="entry1064706693083932p0"></a><a name="entry1064706693083932p0"></a>拓展指令数据包，包括指令编码及参数，具体参考<strong id="b1659444781012"><a name="b1659444781012"></a><a name="b1659444781012"></a>InputExtraCmd</strong>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

## SetGestureMode<a name="a2a5b24dfc129b58ae4663ca44ab2ad91"></a>

```
int32_t(* InputController::SetGestureMode) (uint32_t devIndex, uint32_t gestureMode)
```

**描述：**

设置手势模式

上层应用开关手势模式，即设置手势模式的对应使能bit

**参数：**

<a name="table1224852716083932"></a>
<table><thead align="left"><tr id="row1513274059083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p76866482083932"><a name="p76866482083932"></a><a name="p76866482083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p269800680083932"><a name="p269800680083932"></a><a name="p269800680083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row614109205083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry312452090083932p0"><a name="entry312452090083932p0"></a><a name="entry312452090083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1054936870083932p0"><a name="entry1054936870083932p0"></a><a name="entry1054936870083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备。</p>
</td>
</tr>
<tr id="row568643727083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1702177663083932p0"><a name="entry1702177663083932p0"></a><a name="entry1702177663083932p0"></a>gestureMode</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1142015478083932p0"><a name="entry1142015478083932p0"></a><a name="entry1142015478083932p0"></a>手势模式的开关状态</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

## SetPowerStatus<a name="a38da915fec2698dff480ed686503f692"></a>

```
int32_t(* InputController::SetPowerStatus) (uint32_t devIndex, uint32_t status)
```

**描述：**

设置电源状态

在系统休眠或者唤醒时，input服务或电源管理模块设置电源状态，以使驱动IC能正常进入对应的休眠模式。

**参数：**

<a name="table2094077726083932"></a>
<table><thead align="left"><tr id="row1826538799083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p166513583083932"><a name="p166513583083932"></a><a name="p166513583083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1714166830083932"><a name="p1714166830083932"></a><a name="p1714166830083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2039561606083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2136638454083932p0"><a name="entry2136638454083932p0"></a><a name="entry2136638454083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2028073443083932p0"><a name="entry2028073443083932p0"></a><a name="entry2028073443083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备。</p>
</td>
</tr>
<tr id="row595786156083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1936589391083932p0"><a name="entry1936589391083932p0"></a><a name="entry1936589391083932p0"></a>status</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1745140476083932p0"><a name="entry1745140476083932p0"></a><a name="entry1745140476083932p0"></a>设置的电源状态，input服务控制input设备进入resume或者suspend等状态<a href="_input.md#ga65e6bb4d942c22dba9975253b0a1d73f">PowerStatus</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

