# LightInterface<a name="ZH-CN_TOPIC_0000001290840948"></a>

## **概述**<a name="section881688967083932"></a>

**所属模块:**

[Light](_light.md)

## **汇总**<a name="section995131992083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1978386675083932"></a>
<table><thead align="left"><tr id="row796005623083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p84246230083932"><a name="p84246230083932"></a><a name="p84246230083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p651329179083932"><a name="p651329179083932"></a><a name="p651329179083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1679599922083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p591955307083932"><a name="p591955307083932"></a><a name="p591955307083932"></a>( <a href="_light_interface.md#abc2e95b6ab4976fcc9d87edb6bababfd">GetLightInfo</a> )([out] struct <a href="_light_info.md">LightInfo</a> **lightInfo, [out] uint32_t *count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p11728582083932"><a name="p11728582083932"></a><a name="p11728582083932"></a>获取当前系统中所有类型的灯信息。 <a href="_light_interface.md#abc2e95b6ab4976fcc9d87edb6bababfd">更多...</a></p>
</td>
</tr>
<tr id="row538376766083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1357078757083932"><a name="p1357078757083932"></a><a name="p1357078757083932"></a>( <a href="_light_interface.md#a8677305ede194202a338a693a8243a7e">TurnOnLight</a> )([in] uint32_t lightId, [in] struct <a href="_light_effect.md">LightEffect</a> *effect)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p988096060083932"><a name="p988096060083932"></a><a name="p988096060083932"></a>根据指定的灯ID打开列表中的可用灯。 <a href="_light_interface.md#a8677305ede194202a338a693a8243a7e">更多...</a></p>
</td>
</tr>
<tr id="row662427207083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1549149434083932"><a name="p1549149434083932"></a><a name="p1549149434083932"></a>( <a href="_light_interface.md#ad0ce38e244fba61a572119efe9278d3d">TurnOffLight</a> )([in] uint32_t lightId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p679715044083932"><a name="p679715044083932"></a><a name="p679715044083932"></a>根据指定的灯ID关闭列表中的可用灯。 <a href="_light_interface.md#ad0ce38e244fba61a572119efe9278d3d">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1490029347083932"></a>

定义可以在灯上执行的基本操作。

操作包括获取灯的信息、打开或关闭灯、设置灯的亮度或闪烁模式。

## **类成员变量说明**<a name="section260410791083932"></a>

## GetLightInfo<a name="abc2e95b6ab4976fcc9d87edb6bababfd"></a>

```
int32_t(* LightInterface::GetLightInfo) ([out] struct LightInfo **lightInfo,[out] uint32_t *count)
```

**描述：**

获取当前系统中所有类型的灯信息。

**参数：**

<a name="table488356074083932"></a>
<table><thead align="left"><tr id="row962954723083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p706847298083932"><a name="p706847298083932"></a><a name="p706847298083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1428909069083932"><a name="p1428909069083932"></a><a name="p1428909069083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row429920340083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry400903273083932p0"><a name="entry400903273083932p0"></a><a name="entry400903273083932p0"></a>lightInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1594006821083932p0"><a name="entry1594006821083932p0"></a><a name="entry1594006821083932p0"></a>表示指向灯信息的二级指针，详见<a href="_light_info.md">LightInfo</a>。</p>
</td>
</tr>
<tr id="row1271624804083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry617766336083932p0"><a name="entry617766336083932p0"></a><a name="entry617766336083932p0"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1833024732083932p0"><a name="entry1833024732083932p0"></a><a name="entry1833024732083932p0"></a>表示指向灯数量的指针。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## TurnOffLight<a name="ad0ce38e244fba61a572119efe9278d3d"></a>

```
int32_t(* LightInterface::TurnOffLight) ([in] uint32_t lightId)
```

**描述：**

根据指定的灯ID关闭列表中的可用灯。

**参数：**

<a name="table1724601872083932"></a>
<table><thead align="left"><tr id="row807791709083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1283707047083932"><a name="p1283707047083932"></a><a name="p1283707047083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1385247597083932"><a name="p1385247597083932"></a><a name="p1385247597083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1569784427083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry113268975083932p0"><a name="entry113268975083932p0"></a><a name="entry113268975083932p0"></a>lightId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2010282881083932p0"><a name="entry2010282881083932p0"></a><a name="entry2010282881083932p0"></a>表示灯ID，详见<a href="_light.md#ga8af1cb654f32fb5377425257b28748e5">LightId</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## TurnOnLight<a name="a8677305ede194202a338a693a8243a7e"></a>

```
int32_t(* LightInterface::TurnOnLight) ([in] uint32_t lightId,[in] struct LightEffect *effect)
```

**描述：**

根据指定的灯ID打开列表中的可用灯。

**参数：**

<a name="table2133352404083932"></a>
<table><thead align="left"><tr id="row553350716083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1915846073083932"><a name="p1915846073083932"></a><a name="p1915846073083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p326506710083932"><a name="p326506710083932"></a><a name="p326506710083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row520738281083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1008389750083932p0"><a name="entry1008389750083932p0"></a><a name="entry1008389750083932p0"></a>lightId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2013724137083932p0"><a name="entry2013724137083932p0"></a><a name="entry2013724137083932p0"></a>表示灯ID，详见<a href="_light.md#ga8af1cb654f32fb5377425257b28748e5">LightId</a>。</p>
</td>
</tr>
<tr id="row1286098823083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry424868410083932p0"><a name="entry424868410083932p0"></a><a name="entry424868410083932p0"></a>effect</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1682907736083932p0"><a name="entry1682907736083932p0"></a><a name="entry1682907736083932p0"></a>表示指向灯效果的指针，如果lightbrightness字段为0时， 灯的亮度根据HCS配置的默认亮度进行设置，详见<a href="_light_effect.md">LightEffect</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果不支持灯ID，则返回-1。

如果不支持闪烁设置，则返回-2。

如果不支持亮度设置，则返回3。

