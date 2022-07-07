# IWiFiAp<a name="ZH-CN_TOPIC_0000001291040596"></a>

## **概述**<a name="section1827087334083932"></a>

**所属模块:**

[WLAN](_w_l_a_n.md)

## **汇总**<a name="section777972412083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table360884770083932"></a>
<table><thead align="left"><tr id="row211452796083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1340604917083932"><a name="p1340604917083932"></a><a name="p1340604917083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1343861160083932"><a name="p1343861160083932"></a><a name="p1343861160083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1218576169083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p94771819083932"><a name="p94771819083932"></a><a name="p94771819083932"></a><a href="_i_wi_fi_ap.md#acedb7eef7fc584385c6eb2e69f517c9e">baseFeature</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry495996323083932p0"><a name="entry495996323083932p0"></a><a name="entry495996323083932p0"></a>基本特性。</p>
</td>
</tr>
<tr id="row676362552083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p281045814083932"><a name="p281045814083932"></a><a name="p281045814083932"></a>( <a href="_i_wi_fi_ap.md#a204ed4b7968fc8e5fdf771f885b79d49">getAsscociatedStas</a> )(const struct <a href="_i_wi_fi_ap.md">IWiFiAp</a> *apFeature, struct <a href="_sta_info.md">StaInfo</a> *staInfo, uint32_t count, uint32_t *num)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1683272639083932"><a name="p1683272639083932"></a><a name="p1683272639083932"></a>获取连接上的所有STA的信息（目前只包含MAC地址）。 <a href="_i_wi_fi_ap.md#a204ed4b7968fc8e5fdf771f885b79d49">更多...</a></p>
</td>
</tr>
<tr id="row994358356083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p187203410083932"><a name="p187203410083932"></a><a name="p187203410083932"></a>( <a href="_i_wi_fi_ap.md#ad7d53be7b457806eb14cd90089b816cc">setCountryCode</a> )(const struct <a href="_i_wi_fi_ap.md">IWiFiAp</a> *apFeature, const char *code, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1040817789083932"><a name="p1040817789083932"></a><a name="p1040817789083932"></a>设置国家码（表示AP射频所在的国家，规定了AP射频特性，包括AP的发送功率、支持的信道等。其目的是为了使AP的射频特性符合不同国家或区域的法律法规要求）。 <a href="_i_wi_fi_ap.md#ad7d53be7b457806eb14cd90089b816cc">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section684302873083932"></a>

继承了IWiFiBaseFeature基本特性，并包含AP模式下获取连接STA的信息和设置国家码的功能。

**Since：**

1.0

**Version：**

1.0

## **类成员变量说明**<a name="section2017947692083932"></a>

## baseFeature<a name="acedb7eef7fc584385c6eb2e69f517c9e"></a>

```
struct IWiFiBaseFeature IWiFiAp::baseFeature
```

**描述：**

基本特性。

## getAsscociatedStas<a name="a204ed4b7968fc8e5fdf771f885b79d49"></a>

```
int32_t(* IWiFiAp::getAsscociatedStas) (const struct IWiFiAp *apFeature, struct StaInfo *staInfo, uint32_t count, uint32_t *num)
```

**描述：**

获取连接上的所有STA的信息（目前只包含MAC地址）。

**参数：**

<a name="table829508683083932"></a>
<table><thead align="left"><tr id="row733702319083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1689925318083932"><a name="p1689925318083932"></a><a name="p1689925318083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1173375290083932"><a name="p1173375290083932"></a><a name="p1173375290083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1996784511083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry821734716083932p0"><a name="entry821734716083932p0"></a><a name="entry821734716083932p0"></a>apFeature</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry59748839083932p0"><a name="entry59748839083932p0"></a><a name="entry59748839083932p0"></a>输入参数，AP特性<a href="_i_wi_fi_ap.md">IWiFiAp</a>。</p>
</td>
</tr>
<tr id="row363971460083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry144093712083932p0"><a name="entry144093712083932p0"></a><a name="entry144093712083932p0"></a>staInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry42745102083932p0"><a name="entry42745102083932p0"></a><a name="entry42745102083932p0"></a>输出参数，保存与AP连接的STA的基本信息。</p>
</td>
</tr>
<tr id="row612451389083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1347177607083932p0"><a name="entry1347177607083932p0"></a><a name="entry1347177607083932p0"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2032302383083932p0"><a name="entry2032302383083932p0"></a><a name="entry2032302383083932p0"></a>输入参数，staInfo结构体数组的元素个数。</p>
</td>
</tr>
<tr id="row1706441868083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry233542368083932p0"><a name="entry233542368083932p0"></a><a name="entry233542368083932p0"></a>num</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1395009454083932p0"><a name="entry1395009454083932p0"></a><a name="entry1395009454083932p0"></a>输出参数，实际连接的STA的个数。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## setCountryCode<a name="ad7d53be7b457806eb14cd90089b816cc"></a>

```
int32_t(* IWiFiAp::setCountryCode) (const struct IWiFiAp *apFeature, const char *code, uint32_t len)
```

**描述：**

设置国家码（表示AP射频所在的国家，规定了AP射频特性，包括AP的发送功率、支持的信道等。其目的是为了使AP的射频特性符合不同国家或区域的法律法规要求）。

**参数：**

<a name="table384892791083932"></a>
<table><thead align="left"><tr id="row2139401043083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1501217280083932"><a name="p1501217280083932"></a><a name="p1501217280083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2062302152083932"><a name="p2062302152083932"></a><a name="p2062302152083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row146631868083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry320091160083932p0"><a name="entry320091160083932p0"></a><a name="entry320091160083932p0"></a>apFeature</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry861372405083932p0"><a name="entry861372405083932p0"></a><a name="entry861372405083932p0"></a>输入参数，AP特性<a href="_i_wi_fi_ap.md">IWiFiAp</a>。</p>
</td>
</tr>
<tr id="row1189736167083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2005447155083932p0"><a name="entry2005447155083932p0"></a><a name="entry2005447155083932p0"></a>code</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2091194763083932p0"><a name="entry2091194763083932p0"></a><a name="entry2091194763083932p0"></a>输入参数，设置的国家码。</p>
</td>
</tr>
<tr id="row1200057922083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry718445892083932p0"><a name="entry718445892083932p0"></a><a name="entry718445892083932p0"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry424366601083932p0"><a name="entry424366601083932p0"></a><a name="entry424366601083932p0"></a>输入参数，国家码长度。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

