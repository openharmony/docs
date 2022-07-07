# LightInfo<a name="ZH-CN_TOPIC_0000001343200761"></a>

## **概述**<a name="section1345740381083932"></a>

**所属模块:**

[Light](_light.md)

## **汇总**<a name="section78343700083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table679838191083932"></a>
<table><thead align="left"><tr id="row1436954416083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p844181483083932"><a name="p844181483083932"></a><a name="p844181483083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1263358844083932"><a name="p1263358844083932"></a><a name="p1263358844083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1336493886083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1588209933083932"><a name="p1588209933083932"></a><a name="p1588209933083932"></a><a href="_light_info.md#a947ec53ba5eae0674bbf103311a9b4dd">lightId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1050180340083932p0"><a name="entry1050180340083932p0"></a><a name="entry1050180340083932p0"></a>灯ID</p>
</td>
</tr>
<tr id="row838196843083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p492058713083932"><a name="p492058713083932"></a><a name="p492058713083932"></a><a href="_light_info.md#aaa675d3b1cf4f5e067e771596a8d6a85">reserved</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1156790452083932p0"><a name="entry1156790452083932p0"></a><a name="entry1156790452083932p0"></a>自定义扩展信息</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1145057426083932"></a>

定义灯的基本信息。

基本的灯信息包括灯ID和自定义扩展信息。

**Since：**

3.1

## **类成员变量说明**<a name="section1222452663083932"></a>

## lightId<a name="a947ec53ba5eae0674bbf103311a9b4dd"></a>

```
uint32_t LightInfo::lightId
```

**描述：**

灯ID，详见[LightId](_light.md#ga8af1cb654f32fb5377425257b28748e5)。

## reserved<a name="aaa675d3b1cf4f5e067e771596a8d6a85"></a>

```
int32_t LightInfo::reserved
```

**描述：**

自定义扩展信息。

