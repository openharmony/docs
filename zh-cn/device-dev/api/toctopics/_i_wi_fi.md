# IWiFi<a name="ZH-CN_TOPIC_0000001343321033"></a>

## **概述**<a name="section92892097083932"></a>

**所属模块:**

[WLAN](_w_l_a_n.md)

## **汇总**<a name="section1349142076083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1723592773083932"></a>
<table><thead align="left"><tr id="row228965525083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p854431331083932"><a name="p854431331083932"></a><a name="p854431331083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1115439119083932"><a name="p1115439119083932"></a><a name="p1115439119083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row908480677083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1857767892083932"><a name="p1857767892083932"></a><a name="p1857767892083932"></a>( <a href="_i_wi_fi.md#abda8182ff3c87cb9a4d8b9d251fac376">start</a> )(struct <a href="_i_wi_fi.md">IWiFi</a> *iwifi)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p490857133083932"><a name="p490857133083932"></a><a name="p490857133083932"></a>创建HAL和驱动之间的通道及获取驱动网卡信息，该函数调用在创建IWiFi实体后进行。 <a href="_i_wi_fi.md#abda8182ff3c87cb9a4d8b9d251fac376">更多...</a></p>
</td>
</tr>
<tr id="row677042643083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p888268608083932"><a name="p888268608083932"></a><a name="p888268608083932"></a>( <a href="_i_wi_fi.md#ab070de6037c84f15b1b0a58ddb80d3ba">stop</a> )(struct <a href="_i_wi_fi.md">IWiFi</a> *iwifi)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1279684888083932"><a name="p1279684888083932"></a><a name="p1279684888083932"></a>销毁HAL和驱动之间的通道，该函数调用在销毁IWiFi实体前进行。 <a href="_i_wi_fi.md#ab070de6037c84f15b1b0a58ddb80d3ba">更多...</a></p>
</td>
</tr>
<tr id="row1098424675083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1878032207083932"><a name="p1878032207083932"></a><a name="p1878032207083932"></a>( <a href="_i_wi_fi.md#aa18ded1fb5412e854c8d1a7fbfb1c762">getSupportFeature</a> )(uint8_t *supType, uint32_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p815021869083932"><a name="p815021869083932"></a><a name="p815021869083932"></a>获取该设备支持的WLAN特性（不考虑当前的使用状态）。 <a href="_i_wi_fi.md#aa18ded1fb5412e854c8d1a7fbfb1c762">更多...</a></p>
</td>
</tr>
<tr id="row1433565518083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p560619819083932"><a name="p560619819083932"></a><a name="p560619819083932"></a>( <a href="_i_wi_fi.md#a1ccfc2f7e89297e2c17d301a2576f6e4">getSupportCombo</a> )(uint64_t *combo, uint32_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1278892965083932"><a name="p1278892965083932"></a><a name="p1278892965083932"></a>获取多网卡共存情况。 <a href="_i_wi_fi.md#a1ccfc2f7e89297e2c17d301a2576f6e4">更多...</a></p>
</td>
</tr>
<tr id="row1949397193083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p520390573083932"><a name="p520390573083932"></a><a name="p520390573083932"></a>( <a href="_i_wi_fi.md#a67783c077919d42ec5ec6fc616ab3870">createFeature</a> )(int32_t type, struct <a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a> **ifeature)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p142117626083932"><a name="p142117626083932"></a><a name="p142117626083932"></a>根据输入类型创建对应的特性<a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a>。 <a href="_i_wi_fi.md#a67783c077919d42ec5ec6fc616ab3870">更多...</a></p>
</td>
</tr>
<tr id="row2101397828083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p190137771083932"><a name="p190137771083932"></a><a name="p190137771083932"></a>( <a href="_i_wi_fi.md#adda806aec8d0d572b29c905822f35f3b">getFeatureByIfName</a> )(const char *ifName, struct <a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a> **ifeature)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1216715235083932"><a name="p1216715235083932"></a><a name="p1216715235083932"></a>通过网络接口名字获取对应的特性。 <a href="_i_wi_fi.md#adda806aec8d0d572b29c905822f35f3b">更多...</a></p>
</td>
</tr>
<tr id="row256627033083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p612808617083932"><a name="p612808617083932"></a><a name="p612808617083932"></a>( <a href="_i_wi_fi.md#a68468c07345582779beb37a8d5005d82">registerEventCallback</a> )(<a href="_w_l_a_n.md#gaa7dd2fac193e1b8de1e2c063b2ed175a">CallbackFunc</a> cbFunc, const char *ifName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p247793705083932"><a name="p247793705083932"></a><a name="p247793705083932"></a>注册IWiFi的回调函数，监听异步事件。 <a href="_i_wi_fi.md#a68468c07345582779beb37a8d5005d82">更多...</a></p>
</td>
</tr>
<tr id="row148584600083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1961364595083932"><a name="p1961364595083932"></a><a name="p1961364595083932"></a>( <a href="_i_wi_fi.md#a72c1035791e2d8d8786c97acde0e89ba">unregisterEventCallback</a> )(<a href="_w_l_a_n.md#gaa7dd2fac193e1b8de1e2c063b2ed175a">CallbackFunc</a> cbFunc, const char *ifName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1481059349083932"><a name="p1481059349083932"></a><a name="p1481059349083932"></a>去注册IWiFi的回调函数。 <a href="_i_wi_fi.md#a72c1035791e2d8d8786c97acde0e89ba">更多...</a></p>
</td>
</tr>
<tr id="row1366428033083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1362356333083932"><a name="p1362356333083932"></a><a name="p1362356333083932"></a>( <a href="_i_wi_fi.md#a414fa1ecbd733befdddac9a33cd19ab6">destroyFeature</a> )(struct <a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a> *ifeature)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1370013232083932"><a name="p1370013232083932"></a><a name="p1370013232083932"></a>根据输入类型销毁对应的特性<a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a>。 <a href="_i_wi_fi.md#a414fa1ecbd733befdddac9a33cd19ab6">更多...</a></p>
</td>
</tr>
<tr id="row1812526643083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1854695726083932"><a name="p1854695726083932"></a><a name="p1854695726083932"></a>( <a href="_i_wi_fi.md#ae843d53e9e83896dc103b312d36030bd">resetDriver</a> )(const uint8_t chipId, const char *ifName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1551806601083932"><a name="p1551806601083932"></a><a name="p1551806601083932"></a>重置具有指定芯片ID的WLAN驱动程序。 <a href="_i_wi_fi.md#ae843d53e9e83896dc103b312d36030bd">更多...</a></p>
</td>
</tr>
<tr id="row17914628083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p501088759083932"><a name="p501088759083932"></a><a name="p501088759083932"></a>( <a href="_i_wi_fi.md#aca62e8a46a2d135e1a4345a305c51c59">getNetDevInfo</a> )(struct NetDeviceInfoResult *netDeviceInfoResult)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1524856186083932"><a name="p1524856186083932"></a><a name="p1524856186083932"></a>获取网络设备信息（设备索引、网卡名字、MAC等信息）。 <a href="_i_wi_fi.md#aca62e8a46a2d135e1a4345a305c51c59">更多...</a></p>
</td>
</tr>
<tr id="row3689161083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p61800945083932"><a name="p61800945083932"></a><a name="p61800945083932"></a>( <a href="_i_wi_fi.md#af1a711c975cd4b8a9e3d6144c3c6abc9">getPowerMode</a> )(const char *ifName, uint8_t *mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1684569027083932"><a name="p1684569027083932"></a><a name="p1684569027083932"></a>获取正在使用的功率模式。 <a href="_i_wi_fi.md#af1a711c975cd4b8a9e3d6144c3c6abc9">更多...</a></p>
</td>
</tr>
<tr id="row1357893574083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p545293541083932"><a name="p545293541083932"></a><a name="p545293541083932"></a>( <a href="_i_wi_fi.md#a88a3c2b384a27a0a3158ed961c15b730">setPowerMode</a> )(const char *ifName, uint8_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1989497206083932"><a name="p1989497206083932"></a><a name="p1989497206083932"></a>设置功率模式 <a href="_i_wi_fi.md#a88a3c2b384a27a0a3158ed961c15b730">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1487457054083932"></a>

HAL对WLAN服务提供的基本能力。

用于创建HAL与驱动的通道，创建/获取/销毁WLAN特性等。

**Since：**

1.0

**Version：**

1.0

## **类成员变量说明**<a name="section429667712083932"></a>

## createFeature<a name="a67783c077919d42ec5ec6fc616ab3870"></a>

```
int32_t(* IWiFi::createFeature) (int32_t type, struct IWiFiBaseFeature **ifeature)
```

**描述：**

根据输入类型创建对应的特性[IWiFiBaseFeature](_i_wi_fi_base_feature.md)。

**参数：**

<a name="table538513748083932"></a>
<table><thead align="left"><tr id="row912886587083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p123113198083932"><a name="p123113198083932"></a><a name="p123113198083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1725505258083932"><a name="p1725505258083932"></a><a name="p1725505258083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2095558424083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1382535200083932p0"><a name="entry1382535200083932p0"></a><a name="entry1382535200083932p0"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry988648768083932p0"><a name="entry988648768083932p0"></a><a name="entry988648768083932p0"></a>输入参数，创建的feature类型。</p>
</td>
</tr>
<tr id="row389630956083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1068701438083932p0"><a name="entry1068701438083932p0"></a><a name="entry1068701438083932p0"></a>ifeature</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry165862577083932p0"><a name="entry165862577083932p0"></a><a name="entry165862577083932p0"></a>输出参数，获取创建的feature对象。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## destroyFeature<a name="a414fa1ecbd733befdddac9a33cd19ab6"></a>

```
int32_t(* IWiFi::destroyFeature) (struct IWiFiBaseFeature *ifeature)
```

**描述：**

根据输入类型销毁对应的特性[IWiFiBaseFeature](_i_wi_fi_base_feature.md)。

**参数：**

<a name="table1295712590083932"></a>
<table><thead align="left"><tr id="row556760499083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2143790005083932"><a name="p2143790005083932"></a><a name="p2143790005083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2037115341083932"><a name="p2037115341083932"></a><a name="p2037115341083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row552618451083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry108259713083932p0"><a name="entry108259713083932p0"></a><a name="entry108259713083932p0"></a>ifeature</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1172390749083932p0"><a name="entry1172390749083932p0"></a><a name="entry1172390749083932p0"></a>输入参数，销毁的feature对象。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## getFeatureByIfName<a name="adda806aec8d0d572b29c905822f35f3b"></a>

```
int32_t(* IWiFi::getFeatureByIfName) (const char *ifName, struct IWiFiBaseFeature **ifeature)
```

**描述：**

通过网络接口名字获取对应的特性。

**参数：**

<a name="table1263802171083932"></a>
<table><thead align="left"><tr id="row121502423083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1374979336083932"><a name="p1374979336083932"></a><a name="p1374979336083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1983289414083932"><a name="p1983289414083932"></a><a name="p1983289414083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1987623804083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry877586781083932p0"><a name="entry877586781083932p0"></a><a name="entry877586781083932p0"></a>ifName</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1141322299083932p0"><a name="entry1141322299083932p0"></a><a name="entry1141322299083932p0"></a>输入参数，网卡名称。</p>
</td>
</tr>
<tr id="row886102306083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1544027467083932p0"><a name="entry1544027467083932p0"></a><a name="entry1544027467083932p0"></a>ifeature</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1747333017083932p0"><a name="entry1747333017083932p0"></a><a name="entry1747333017083932p0"></a>输出参数，获取该网络接口名字的feature对象。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## getNetDevInfo<a name="aca62e8a46a2d135e1a4345a305c51c59"></a>

```
int32_t(* IWiFi::getNetDevInfo) (struct NetDeviceInfoResult *netDeviceInfoResult)
```

**描述：**

获取网络设备信息（设备索引、网卡名字、MAC等信息）。

**参数：**

<a name="table1315002754083932"></a>
<table><thead align="left"><tr id="row33535840083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p975431896083932"><a name="p975431896083932"></a><a name="p975431896083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1952566033083932"><a name="p1952566033083932"></a><a name="p1952566033083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1792680778083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry278484035083932p0"><a name="entry278484035083932p0"></a><a name="entry278484035083932p0"></a>netDeviceInfoResult</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry669458200083932p0"><a name="entry669458200083932p0"></a><a name="entry669458200083932p0"></a>输出参数，得到的网络设备信息。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## getPowerMode<a name="af1a711c975cd4b8a9e3d6144c3c6abc9"></a>

```
int32_t(* IWiFi::getPowerMode) (const char *ifName, uint8_t *mode)
```

**描述：**

获取正在使用的功率模式。

**参数：**

<a name="table1885979364083932"></a>
<table><thead align="left"><tr id="row1389831164083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1678874468083932"><a name="p1678874468083932"></a><a name="p1678874468083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p508055334083932"><a name="p508055334083932"></a><a name="p508055334083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row84693988083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1499536668083932p0"><a name="entry1499536668083932p0"></a><a name="entry1499536668083932p0"></a>ifName</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry20404289083932p0"><a name="entry20404289083932p0"></a><a name="entry20404289083932p0"></a>输入参数，网卡名称。</p>
</td>
</tr>
<tr id="row924565705083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2075425115083932p0"><a name="entry2075425115083932p0"></a><a name="entry2075425115083932p0"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry990214123083932p0"><a name="entry990214123083932p0"></a><a name="entry990214123083932p0"></a>输出参数，功率模式，包括睡眠模式（待机状态运行）、一般模式（正常额定功率运行）、穿墙模式（最大功率运行，提高信号强度和覆盖面积）。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## getSupportCombo<a name="a1ccfc2f7e89297e2c17d301a2576f6e4"></a>

```
int32_t(* IWiFi::getSupportCombo) (uint64_t *combo, uint32_t size)
```

**描述：**

获取多网卡共存情况。

**参数：**

<a name="table946497197083932"></a>
<table><thead align="left"><tr id="row119879582083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p455991512083932"><a name="p455991512083932"></a><a name="p455991512083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1916400089083932"><a name="p1916400089083932"></a><a name="p1916400089083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row317035709083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry804194305083932p0"><a name="entry804194305083932p0"></a><a name="entry804194305083932p0"></a>combo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1437764963083932p0"><a name="entry1437764963083932p0"></a><a name="entry1437764963083932p0"></a>输出参数，基于芯片的能力保存当前所有支持的多网卡共存情况（比如支持AP，STA，P2P等不同组合的共存）。</p>
</td>
</tr>
<tr id="row2047576904083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry999545087083932p0"><a name="entry999545087083932p0"></a><a name="entry999545087083932p0"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry703254710083932p0"><a name="entry703254710083932p0"></a><a name="entry703254710083932p0"></a>输入参数，combo数组的长度。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## getSupportFeature<a name="aa18ded1fb5412e854c8d1a7fbfb1c762"></a>

```
int32_t(* IWiFi::getSupportFeature) (uint8_t *supType, uint32_t size)
```

**描述：**

获取该设备支持的WLAN特性（不考虑当前的使用状态）。

**参数：**

<a name="table1750650081083932"></a>
<table><thead align="left"><tr id="row832798732083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1601552136083932"><a name="p1601552136083932"></a><a name="p1601552136083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1724079121083932"><a name="p1724079121083932"></a><a name="p1724079121083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1259377148083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry927956827083932p0"><a name="entry927956827083932p0"></a><a name="entry927956827083932p0"></a>supType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry127982174083932p0"><a name="entry127982174083932p0"></a><a name="entry127982174083932p0"></a>输出参数，保存当前设备支持的特性。</p>
</td>
</tr>
<tr id="row67710933083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2119625964083932p0"><a name="entry2119625964083932p0"></a><a name="entry2119625964083932p0"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry918415773083932p0"><a name="entry918415773083932p0"></a><a name="entry918415773083932p0"></a>输入参数，supType数组的长度。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## registerEventCallback<a name="a68468c07345582779beb37a8d5005d82"></a>

```
int32_t(* IWiFi::registerEventCallback) (CallbackFunc cbFunc, const char *ifName)
```

**描述：**

注册IWiFi的回调函数，监听异步事件。

**参数：**

<a name="table616098649083932"></a>
<table><thead align="left"><tr id="row2076413239083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p802498379083932"><a name="p802498379083932"></a><a name="p802498379083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p47888493083932"><a name="p47888493083932"></a><a name="p47888493083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row266403304083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1479419305083932p0"><a name="entry1479419305083932p0"></a><a name="entry1479419305083932p0"></a>cbFunc</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry935984922083932p0"><a name="entry935984922083932p0"></a><a name="entry935984922083932p0"></a>输入参数，注册的回调函数。</p>
</td>
</tr>
<tr id="row375665307083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1347295508083932p0"><a name="entry1347295508083932p0"></a><a name="entry1347295508083932p0"></a>ifName</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1708777573083932p0"><a name="entry1708777573083932p0"></a><a name="entry1708777573083932p0"></a>输入参数，网卡名称。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## resetDriver<a name="ae843d53e9e83896dc103b312d36030bd"></a>

```
int32_t(* IWiFi::resetDriver) (const uint8_t chipId, const char *ifName)
```

**描述：**

重置具有指定芯片ID的WLAN驱动程序。

**参数：**

<a name="table1922804445083932"></a>
<table><thead align="left"><tr id="row1885349971083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1408039985083932"><a name="p1408039985083932"></a><a name="p1408039985083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2136220981083932"><a name="p2136220981083932"></a><a name="p2136220981083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row649999961083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2023608886083932p0"><a name="entry2023608886083932p0"></a><a name="entry2023608886083932p0"></a>chipId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1261373537083932p0"><a name="entry1261373537083932p0"></a><a name="entry1261373537083932p0"></a>输入参数，需要进行重置驱动的对应芯片ID。</p>
</td>
</tr>
<tr id="row175021689083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1055814871083932p0"><a name="entry1055814871083932p0"></a><a name="entry1055814871083932p0"></a>ifName</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry912497813083932p0"><a name="entry912497813083932p0"></a><a name="entry912497813083932p0"></a>输入参数，网卡名称。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## setPowerMode<a name="a88a3c2b384a27a0a3158ed961c15b730"></a>

```
int32_t(* IWiFi::setPowerMode) (const char *ifName, uint8_t mode)
```

**描述：**

设置功率模式

**参数：**

<a name="table1387072557083932"></a>
<table><thead align="left"><tr id="row395417516083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1570515130083932"><a name="p1570515130083932"></a><a name="p1570515130083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1781492498083932"><a name="p1781492498083932"></a><a name="p1781492498083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1940196069083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1656985720083932p0"><a name="entry1656985720083932p0"></a><a name="entry1656985720083932p0"></a>ifName</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1114518014083932p0"><a name="entry1114518014083932p0"></a><a name="entry1114518014083932p0"></a>输入参数，网卡名称。</p>
</td>
</tr>
<tr id="row1740219004083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry755502104083932p0"><a name="entry755502104083932p0"></a><a name="entry755502104083932p0"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry955314016083932p0"><a name="entry955314016083932p0"></a><a name="entry955314016083932p0"></a>输入参数，功率模式,包括睡眠模式（待机状态运行）、一般模式（正常额定功率运行）、穿墙模式（最大功率运行，提高信号强度和覆盖面积）。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## start<a name="abda8182ff3c87cb9a4d8b9d251fac376"></a>

```
int32_t(* IWiFi::start) (struct IWiFi *iwifi)
```

**描述：**

创建HAL和驱动之间的通道及获取驱动网卡信息，该函数调用在创建IWiFi实体后进行。

**参数：**

<a name="table852697537083932"></a>
<table><thead align="left"><tr id="row1457365893083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p712608457083932"><a name="p712608457083932"></a><a name="p712608457083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2137827760083932"><a name="p2137827760083932"></a><a name="p2137827760083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1880019132083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1781913124083932p0"><a name="entry1781913124083932p0"></a><a name="entry1781913124083932p0"></a>iwifi</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1321728939083932p0"><a name="entry1321728939083932p0"></a><a name="entry1321728939083932p0"></a>输入参数，IWiFi对象。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## stop<a name="ab070de6037c84f15b1b0a58ddb80d3ba"></a>

```
int32_t(* IWiFi::stop) (struct IWiFi *iwifi)
```

**描述：**

销毁HAL和驱动之间的通道，该函数调用在销毁IWiFi实体前进行。

**参数：**

<a name="table1803938733083932"></a>
<table><thead align="left"><tr id="row1066446203083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p469114155083932"><a name="p469114155083932"></a><a name="p469114155083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p975692218083932"><a name="p975692218083932"></a><a name="p975692218083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row664150998083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry574172335083932p0"><a name="entry574172335083932p0"></a><a name="entry574172335083932p0"></a>iwifi</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry695323144083932p0"><a name="entry695323144083932p0"></a><a name="entry695323144083932p0"></a>输入参数，IWiFi对象。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## unregisterEventCallback<a name="a72c1035791e2d8d8786c97acde0e89ba"></a>

```
int32_t(* IWiFi::unregisterEventCallback) (CallbackFunc cbFunc, const char *ifName)
```

**描述：**

去注册IWiFi的回调函数。

**参数：**

<a name="table89967947083932"></a>
<table><thead align="left"><tr id="row724478818083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p162076554083932"><a name="p162076554083932"></a><a name="p162076554083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1601123060083932"><a name="p1601123060083932"></a><a name="p1601123060083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row506693031083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry955120647083932p0"><a name="entry955120647083932p0"></a><a name="entry955120647083932p0"></a>cbFunc</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1415282134083932p0"><a name="entry1415282134083932p0"></a><a name="entry1415282134083932p0"></a>输入参数，去注册的回调函数。</p>
</td>
</tr>
<tr id="row27072332083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry384765719083932p0"><a name="entry384765719083932p0"></a><a name="entry384765719083932p0"></a>ifName</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1901621056083932p0"><a name="entry1901621056083932p0"></a><a name="entry1901621056083932p0"></a>输入参数，网卡名称。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

