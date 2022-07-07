# SensorEvents<a name="ZH-CN_TOPIC_0000001343321053"></a>

## **概述**<a name="section1222091790083932"></a>

**所属模块:**

[Sensor](_sensor.md)

## **汇总**<a name="section1124342934083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1822954140083932"></a>
<table><thead align="left"><tr id="row626227307083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p664359937083932"><a name="p664359937083932"></a><a name="p664359937083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p166047590083932"><a name="p166047590083932"></a><a name="p166047590083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row796685060083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1631939742083932"><a name="p1631939742083932"></a><a name="p1631939742083932"></a><a href="_sensor_events.md#a3f11a3f2e63241230bafcc18677cac57">sensorId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry94500171083932p0"><a name="entry94500171083932p0"></a><a name="entry94500171083932p0"></a>传感器的标识号。</p>
</td>
</tr>
<tr id="row1338661117083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1176564512083932"><a name="p1176564512083932"></a><a name="p1176564512083932"></a><a href="_sensor_events.md#a5fb8965b5c4bd238180740ee127316a7">version</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p73474374403"><a name="p73474374403"></a><a name="p73474374403"></a>传感器算法版本号。</p>
</td>
</tr>
<tr id="row956771988083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p564784368083932"><a name="p564784368083932"></a><a name="p564784368083932"></a><a href="_sensor_events.md#ae8ae1f81193df1c0e08b716152525b50">timestamp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2030009176083932p0"><a name="entry2030009176083932p0"></a><a name="entry2030009176083932p0"></a>传感器数据生成时间。</p>
</td>
</tr>
<tr id="row1912973348083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1839447026083932"><a name="p1839447026083932"></a><a name="p1839447026083932"></a><a href="_sensor_events.md#a3de8d3ac3fa336f21c2fbc6cf79215a0">option</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry472189244083932p0"><a name="entry472189244083932p0"></a><a name="entry472189244083932p0"></a>传感器量程精度可选配置。</p>
</td>
</tr>
<tr id="row1330104326083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1315020998083932"><a name="p1315020998083932"></a><a name="p1315020998083932"></a><a href="_sensor_events.md#aebc1b1d4aed18c3681984b61fe76c40d">mode</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p177811993720"><a name="p177811993720"></a><a name="p177811993720"></a>传感器工作模式。</p>
</td>
</tr>
<tr id="row1415539862083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p314427260083932"><a name="p314427260083932"></a><a name="p314427260083932"></a><a href="_sensor_events.md#a5e00e8b6b83c286a190f8282dc242b64">data</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry402360639083932p0"><a name="entry402360639083932p0"></a><a name="entry402360639083932p0"></a>传感器数据地址。</p>
</td>
</tr>
<tr id="row118286547083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p267644012083932"><a name="p267644012083932"></a><a name="p267644012083932"></a><em id="a555165c3f8f4df7d2b69504a99e2673d"><a name="a555165c3f8f4df7d2b69504a99e2673d"></a><a name="a555165c3f8f4df7d2b69504a99e2673d"></a></em><a href="#section0442151664211">dataLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1572051426083932p0"><a name="entry1572051426083932p0"></a><a name="entry1572051426083932p0"></a>传感器数据长度。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section987493526083932"></a>

上报传感器数据结构。

上报传感器设备数据事件信息包括传感器的标识号、传感器算法版本号、传感器数据生成时间、传感器量程精度可选配置、传感器工作模式、传感器数据地址、传感器数据长度。

**Since：**

2.2

## **类成员变量说明**<a name="section1111649019083932"></a>

## data<a name="a5e00e8b6b83c286a190f8282dc242b64"></a>

```
uint8_t* SensorEvents::data
```

**描述：**

传感器数据地址。

## mode<a name="aebc1b1d4aed18c3681984b61fe76c40d"></a>

```
int32_t SensorEvents::mode
```

**描述：**

传感器工作模式。

## option<a name="a3de8d3ac3fa336f21c2fbc6cf79215a0"></a>

```
uint32_t SensorEvents::option
```

**描述：**

传感器量程精度可选配置。

## sensorId<a name="a3f11a3f2e63241230bafcc18677cac57"></a>

```
int32_t SensorEvents::sensorId
```

**描述：**

传感器的标识号。

## timestamp<a name="ae8ae1f81193df1c0e08b716152525b50"></a>

```
int64_t SensorEvents::timestamp
```

**描述：**

传感器数据生成时间。

## version<a name="a5fb8965b5c4bd238180740ee127316a7"></a>

```
int32_t SensorEvents::version
```

**描述：**

传感器算法版本号。

## dataLen<a name="section0442151664211"></a>

```
int32_t SensorEvents::dataLen
```

**描述：**

传感器算法版本号。

