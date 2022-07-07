# IWiFiSta<a name="ZH-CN_TOPIC_0000001290840944"></a>

## **概述**<a name="section764288137083932"></a>

**所属模块:**

[WLAN](_w_l_a_n.md)

## **汇总**<a name="section1660441574083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table585561149083932"></a>
<table><thead align="left"><tr id="row759455489083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p852755050083932"><a name="p852755050083932"></a><a name="p852755050083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1787829229083932"><a name="p1787829229083932"></a><a name="p1787829229083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1753517149083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1445777323083932"><a name="p1445777323083932"></a><a name="p1445777323083932"></a><a href="_i_wi_fi_sta.md#abc77e8a3a8cd9cf5cb0a5bdbeb15507d">baseFeature</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1415983440083932p0"><a name="entry1415983440083932p0"></a><a name="entry1415983440083932p0"></a>基本特性。</p>
</td>
</tr>
<tr id="row1678245344083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2083725127083932"><a name="p2083725127083932"></a><a name="p2083725127083932"></a>( <a href="_i_wi_fi_sta.md#a11764790759470b18aab8d17706d1d8d">setScanningMacAddress</a> )(const struct <a href="_i_wi_fi_sta.md">IWiFiSta</a> *staFeature, unsigned char *scanMac, uint8_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p141011563083932"><a name="p141011563083932"></a><a name="p141011563083932"></a>设置扫描单个MAC地址。 <a href="_i_wi_fi_sta.md#a11764790759470b18aab8d17706d1d8d">更多...</a></p>
</td>
</tr>
<tr id="row335942693083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p132434864083932"><a name="p132434864083932"></a><a name="p132434864083932"></a>( <a href="_i_wi_fi_sta.md#a1c6418c79b6e4e91576fcd6112a79d6c">startScan</a> )(const char *ifName, WifiScan *scan)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1214717105083932"><a name="p1214717105083932"></a><a name="p1214717105083932"></a>启动扫描。 <a href="_i_wi_fi_sta.md#a1c6418c79b6e4e91576fcd6112a79d6c">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section5876249083932"></a>

继承了[IWiFiBaseFeature](_i_wi_fi_base_feature.md)基本特性，额外包含设置扫描单个MAC地址功能。

**Since：**

1.0

**Version：**

1.0

## **类成员变量说明**<a name="section910908398083932"></a>

## baseFeature<a name="abc77e8a3a8cd9cf5cb0a5bdbeb15507d"></a>

```
struct IWiFiBaseFeature IWiFiSta::baseFeature
```

**描述：**

基本特性。

## setScanningMacAddress<a name="a11764790759470b18aab8d17706d1d8d"></a>

```
int32_t(* IWiFiSta::setScanningMacAddress) (const struct IWiFiSta *staFeature, unsigned char *scanMac, uint8_t len)
```

**描述：**

设置扫描单个MAC地址。

**参数：**

<a name="table2127484195083932"></a>
<table><thead align="left"><tr id="row1565413257083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1790625343083932"><a name="p1790625343083932"></a><a name="p1790625343083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1733511772083932"><a name="p1733511772083932"></a><a name="p1733511772083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row495763070083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1617954361083932p0"><a name="entry1617954361083932p0"></a><a name="entry1617954361083932p0"></a>staFeature</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry957944409083932p0"><a name="entry957944409083932p0"></a><a name="entry957944409083932p0"></a>输入参数，STA特性<a href="_i_wi_fi_sta.md">IWiFiSta</a>。</p>
</td>
</tr>
<tr id="row1439687568083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry162564452083932p0"><a name="entry162564452083932p0"></a><a name="entry162564452083932p0"></a>scanMac</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry720471019083932p0"><a name="entry720471019083932p0"></a><a name="entry720471019083932p0"></a>输入参数，设置STA扫描的MAC地址。</p>
</td>
</tr>
<tr id="row234775690083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1824587716083932p0"><a name="entry1824587716083932p0"></a><a name="entry1824587716083932p0"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry200532605083932p0"><a name="entry200532605083932p0"></a><a name="entry200532605083932p0"></a>输入参数，MAC地址的长度。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## startScan<a name="a1c6418c79b6e4e91576fcd6112a79d6c"></a>

```
int32_t(* IWiFiSta::startScan) (const char *ifName, WifiScan *scan)
```

**描述：**

启动扫描。

**参数：**

<a name="table1684858450083932"></a>
<table><thead align="left"><tr id="row113977106083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p830864000083932"><a name="p830864000083932"></a><a name="p830864000083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p748375193083932"><a name="p748375193083932"></a><a name="p748375193083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row258960573083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2036733517083932p0"><a name="entry2036733517083932p0"></a><a name="entry2036733517083932p0"></a>ifName</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry902507283083932p0"><a name="entry902507283083932p0"></a><a name="entry902507283083932p0"></a>输入参数，网卡名称。</p>
</td>
</tr>
<tr id="row145228182083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1169355588083932p0"><a name="entry1169355588083932p0"></a><a name="entry1169355588083932p0"></a>scan</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1158171859083932p0"><a name="entry1158171859083932p0"></a><a name="entry1158171859083932p0"></a>输入参数，扫描参数。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

