# IWiFiBaseFeature<a name="ZH-CN_TOPIC_0000001343200757"></a>

## **概述**<a name="section923781154083932"></a>

**所属模块:**

[WLAN](_w_l_a_n.md)

## **汇总**<a name="section1060589681083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table974813728083932"></a>
<table><thead align="left"><tr id="row1487026934083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p331685843083932"><a name="p331685843083932"></a><a name="p331685843083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1074069677083932"><a name="p1074069677083932"></a><a name="p1074069677083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1426929928083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1796276805083932"><a name="p1796276805083932"></a><a name="p1796276805083932"></a><a href="_i_wi_fi_base_feature.md#a07280f2fc38c5b6f0acdd67f0eeeeccd">ifName</a> [<a href="_w_l_a_n.md#ga63637ece87095ff8d153f650434ecf97">IFNAME_MAX_LEN</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1088418941083932p0"><a name="entry1088418941083932p0"></a><a name="entry1088418941083932p0"></a>网卡名称。</p>
</td>
</tr>
<tr id="row256101559083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p732752178083932"><a name="p732752178083932"></a><a name="p732752178083932"></a><em id="acadec8056cf10200aba0b9b78cc89494"><a name="acadec8056cf10200aba0b9b78cc89494"></a><a name="acadec8056cf10200aba0b9b78cc89494"></a></em><strong id="b89705576083932"><a name="b89705576083932"></a><a name="b89705576083932"></a>type</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p137211548115817"><a name="p137211548115817"></a><a name="p137211548115817"></a>特性的类型，参考<a href="_w_l_a_n.md#gad2b28a6ade408676d1371ea941824012">FeatureType</a>。</p>
</td>
</tr>
<tr id="row1848880469083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p130886749083932"><a name="p130886749083932"></a><a name="p130886749083932"></a>( <a href="_i_wi_fi_base_feature.md#ad99aaf10b52b60d550ed9e4e22651b34">getNetworkIfaceName</a> )(const struct <a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a> *baseFeature)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p20172306083932"><a name="p20172306083932"></a><a name="p20172306083932"></a>根据基本特性获取网卡名称。 <a href="_i_wi_fi_base_feature.md#ad99aaf10b52b60d550ed9e4e22651b34">更多...</a></p>
</td>
</tr>
<tr id="row1983708624083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p601691377083932"><a name="p601691377083932"></a><a name="p601691377083932"></a>( <a href="_i_wi_fi_base_feature.md#a2285183acbc5958148207f683514aae0">getFeatureType</a> )(const struct <a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a> *baseFeature)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p835427044083932"><a name="p835427044083932"></a><a name="p835427044083932"></a>获取基本特性的类型<a href="_w_l_a_n.md#gad2b28a6ade408676d1371ea941824012">FeatureType</a>。 <a href="_i_wi_fi_base_feature.md#a2285183acbc5958148207f683514aae0">更多...</a></p>
</td>
</tr>
<tr id="row784417147083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1063639259083932"><a name="p1063639259083932"></a><a name="p1063639259083932"></a>( <a href="_i_wi_fi_base_feature.md#afe6b53a61bbec5e062406715ea089349">setMacAddress</a> )(const struct <a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a> *baseFeature, unsigned char *mac, uint8_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1643651907083932"><a name="p1643651907083932"></a><a name="p1643651907083932"></a>根据传入参数设置对应网卡的MAC地址。 <a href="_i_wi_fi_base_feature.md#afe6b53a61bbec5e062406715ea089349">更多...</a></p>
</td>
</tr>
<tr id="row489209989083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p892215984083932"><a name="p892215984083932"></a><a name="p892215984083932"></a>( <a href="_i_wi_fi_base_feature.md#a624446d7468884eb471b55cfdf21eb87">getDeviceMacAddress</a> )(const struct <a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a> *baseFeature, unsigned char *mac, uint8_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1317473830083932"><a name="p1317473830083932"></a><a name="p1317473830083932"></a>获取设备的MAC地址。 <a href="_i_wi_fi_base_feature.md#a624446d7468884eb471b55cfdf21eb87">更多...</a></p>
</td>
</tr>
<tr id="row2106491352083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1579537325083932"><a name="p1579537325083932"></a><a name="p1579537325083932"></a>( <a href="_i_wi_fi_base_feature.md#a5b0cdd85035205dd1cd4a3ced2f4bdee">getValidFreqsWithBand</a> )(const struct <a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a> *baseFeature, int32_t band, int32_t *freqs, uint32_t count, uint32_t *num)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p641278430083932"><a name="p641278430083932"></a><a name="p641278430083932"></a>获取指定频段（2.4G或者5G）下支持的频率。 <a href="_i_wi_fi_base_feature.md#a5b0cdd85035205dd1cd4a3ced2f4bdee">更多...</a></p>
</td>
</tr>
<tr id="row1129738746083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1203936816083932"><a name="p1203936816083932"></a><a name="p1203936816083932"></a>( <a href="_i_wi_fi_base_feature.md#a48a0bfce07012d0f79883b9457e9d87d">setTxPower</a> )(const struct <a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a> *baseFeature, int32_t power)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p106242027083932"><a name="p106242027083932"></a><a name="p106242027083932"></a>设置发射功率。 <a href="_i_wi_fi_base_feature.md#a48a0bfce07012d0f79883b9457e9d87d">更多...</a></p>
</td>
</tr>
<tr id="row93441958083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1775288446083932"><a name="p1775288446083932"></a><a name="p1775288446083932"></a>( <a href="_i_wi_fi_base_feature.md#ab3393149ec209ae8d378954b4ee9f5c4">getChipId</a> )(const struct <a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a> *baseFeature, uint8_t *chipId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p599763488083932"><a name="p599763488083932"></a><a name="p599763488083932"></a>获得当前驱动的芯片ID。 <a href="_i_wi_fi_base_feature.md#ab3393149ec209ae8d378954b4ee9f5c4">更多...</a></p>
</td>
</tr>
<tr id="row555432023083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p577031674083932"><a name="p577031674083932"></a><a name="p577031674083932"></a>( <a href="_i_wi_fi_base_feature.md#a8afaa8b3dea4f203cf221ac73222a156">getIfNamesByChipId</a> )(const uint8_t chipId, char **ifNames, uint32_t *num)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p744007590083932"><a name="p744007590083932"></a><a name="p744007590083932"></a>通过芯片ID获得当前芯片所有的网卡名称。 <a href="_i_wi_fi_base_feature.md#a8afaa8b3dea4f203cf221ac73222a156">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section344306483083932"></a>

WLAN基本特性操作接口，包括获取网卡名称，设置MAC地址，设置发射功率等公共能力接口。

**Since：**

1.0

**Version：**

1.0

## **类成员变量说明**<a name="section2147460362083932"></a>

## getChipId<a name="ab3393149ec209ae8d378954b4ee9f5c4"></a>

```
int32_t(* IWiFiBaseFeature::getChipId) (const struct IWiFiBaseFeature *baseFeature, uint8_t *chipId)
```

**描述：**

获得当前驱动的芯片ID。

**参数：**

<a name="table1734478373083932"></a>
<table><thead align="left"><tr id="row1382900495083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p48131758083932"><a name="p48131758083932"></a><a name="p48131758083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p204161626083932"><a name="p204161626083932"></a><a name="p204161626083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row660344004083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1899213799083932p0"><a name="entry1899213799083932p0"></a><a name="entry1899213799083932p0"></a>baseFeature</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry931352228083932p0"><a name="entry931352228083932p0"></a><a name="entry931352228083932p0"></a>输入参数，基本特性<a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a>。</p>
</td>
</tr>
<tr id="row738113402083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1150365125083932p0"><a name="entry1150365125083932p0"></a><a name="entry1150365125083932p0"></a>chipId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry897145084083932p0"><a name="entry897145084083932p0"></a><a name="entry897145084083932p0"></a>输出参数，获得的芯片ID。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## getDeviceMacAddress<a name="a624446d7468884eb471b55cfdf21eb87"></a>

```
int32_t(* IWiFiBaseFeature::getDeviceMacAddress) (const struct IWiFiBaseFeature *baseFeature, unsigned char *mac, uint8_t len)
```

**描述：**

获取设备的MAC地址。

**参数：**

<a name="table445844141083932"></a>
<table><thead align="left"><tr id="row565008911083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2033091392083932"><a name="p2033091392083932"></a><a name="p2033091392083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p585441608083932"><a name="p585441608083932"></a><a name="p585441608083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1445373947083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1573004054083932p0"><a name="entry1573004054083932p0"></a><a name="entry1573004054083932p0"></a>baseFeature</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1727351420083932p0"><a name="entry1727351420083932p0"></a><a name="entry1727351420083932p0"></a>输入参数，基本特性<a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a>。</p>
</td>
</tr>
<tr id="row1963735775083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2011143317083932p0"><a name="entry2011143317083932p0"></a><a name="entry2011143317083932p0"></a>mac</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1804234186083932p0"><a name="entry1804234186083932p0"></a><a name="entry1804234186083932p0"></a>输出参数，获得的MAC地址。</p>
</td>
</tr>
<tr id="row1953790191083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1453807054083932p0"><a name="entry1453807054083932p0"></a><a name="entry1453807054083932p0"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry849756876083932p0"><a name="entry849756876083932p0"></a><a name="entry849756876083932p0"></a>输入参数，获得的MAC地址长度。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## getFeatureType<a name="a2285183acbc5958148207f683514aae0"></a>

```
int32_t(* IWiFiBaseFeature::getFeatureType) (const struct IWiFiBaseFeature *baseFeature)
```

**描述：**

获取基本特性的类型[FeatureType](_w_l_a_n.md#gad2b28a6ade408676d1371ea941824012)。

**参数：**

<a name="table847552436083932"></a>
<table><thead align="left"><tr id="row899129024083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p916669648083932"><a name="p916669648083932"></a><a name="p916669648083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1535528599083932"><a name="p1535528599083932"></a><a name="p1535528599083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row969593669083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1355923485083932p0"><a name="entry1355923485083932p0"></a><a name="entry1355923485083932p0"></a>baseFeature</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1124019449083932p0"><a name="entry1124019449083932p0"></a><a name="entry1124019449083932p0"></a>输入参数，基本特性<a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## getIfNamesByChipId<a name="a8afaa8b3dea4f203cf221ac73222a156"></a>

```
int32_t(* IWiFiBaseFeature::getIfNamesByChipId) (const uint8_t chipId, char **ifNames, uint32_t *num)
```

**描述：**

通过芯片ID获得当前芯片所有的网卡名称。

**参数：**

<a name="table1186574951083932"></a>
<table><thead align="left"><tr id="row1586136824083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2047782921083932"><a name="p2047782921083932"></a><a name="p2047782921083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p852962164083932"><a name="p852962164083932"></a><a name="p852962164083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row149650915083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry65829633083932p0"><a name="entry65829633083932p0"></a><a name="entry65829633083932p0"></a>chipId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry589484368083932p0"><a name="entry589484368083932p0"></a><a name="entry589484368083932p0"></a>输入参数，需要获取网卡名称的芯片ID。</p>
</td>
</tr>
<tr id="row279051726083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1117307930083932p0"><a name="entry1117307930083932p0"></a><a name="entry1117307930083932p0"></a>ifNames</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry705220414083932p0"><a name="entry705220414083932p0"></a><a name="entry705220414083932p0"></a>输出参数，网卡名称。</p>
</td>
</tr>
<tr id="row837071497083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1863679624083932p0"><a name="entry1863679624083932p0"></a><a name="entry1863679624083932p0"></a>num</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1986317534083932p0"><a name="entry1986317534083932p0"></a><a name="entry1986317534083932p0"></a>输出参数，网卡的数量。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## getNetworkIfaceName<a name="ad99aaf10b52b60d550ed9e4e22651b34"></a>

```
const char*(* IWiFiBaseFeature::getNetworkIfaceName) (const struct IWiFiBaseFeature *baseFeature)
```

**描述：**

根据基本特性获取网卡名称。

**参数：**

<a name="table726639690083932"></a>
<table><thead align="left"><tr id="row1468567834083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p984981282083932"><a name="p984981282083932"></a><a name="p984981282083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p524713004083932"><a name="p524713004083932"></a><a name="p524713004083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row6826346083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry744718935083932p0"><a name="entry744718935083932p0"></a><a name="entry744718935083932p0"></a>baseFeature</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry911276156083932p0"><a name="entry911276156083932p0"></a><a name="entry911276156083932p0"></a>输入参数，基本特性<a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## getValidFreqsWithBand<a name="a5b0cdd85035205dd1cd4a3ced2f4bdee"></a>

```
int32_t(* IWiFiBaseFeature::getValidFreqsWithBand) (const struct IWiFiBaseFeature *baseFeature, int32_t band, int32_t *freqs, uint32_t count, uint32_t *num)
```

**描述：**

获取指定频段（2.4G或者5G）下支持的频率。

**参数：**

<a name="table1900429989083932"></a>
<table><thead align="left"><tr id="row1926288679083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p845805990083932"><a name="p845805990083932"></a><a name="p845805990083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1648904346083932"><a name="p1648904346083932"></a><a name="p1648904346083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row130558924083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry669298487083932p0"><a name="entry669298487083932p0"></a><a name="entry669298487083932p0"></a>baseFeature</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry343602990083932p0"><a name="entry343602990083932p0"></a><a name="entry343602990083932p0"></a>输入参数，基本特性<a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a>。</p>
</td>
</tr>
<tr id="row1422035026083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry692634921083932p0"><a name="entry692634921083932p0"></a><a name="entry692634921083932p0"></a>band</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1748523529083932p0"><a name="entry1748523529083932p0"></a><a name="entry1748523529083932p0"></a>输入参数，指定的一个频段。</p>
</td>
</tr>
<tr id="row1207318255083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2031577507083932p0"><a name="entry2031577507083932p0"></a><a name="entry2031577507083932p0"></a>freqs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1035594587083932p0"><a name="entry1035594587083932p0"></a><a name="entry1035594587083932p0"></a>输出参数，保存支持的频率。</p>
</td>
</tr>
<tr id="row152486382083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1993915674083932p0"><a name="entry1993915674083932p0"></a><a name="entry1993915674083932p0"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry954330358083932p0"><a name="entry954330358083932p0"></a><a name="entry954330358083932p0"></a>输入参数，频率数组的元素个数。</p>
</td>
</tr>
<tr id="row876875306083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2069886768083932p0"><a name="entry2069886768083932p0"></a><a name="entry2069886768083932p0"></a>num</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1896454706083932p0"><a name="entry1896454706083932p0"></a><a name="entry1896454706083932p0"></a>输出参数，实际支持的频率个数。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## ifName<a name="a07280f2fc38c5b6f0acdd67f0eeeeccd"></a>

```
char IWiFiBaseFeature::ifName[IFNAME_MAX_LEN]
```

**描述：**

网卡名称。

## setMacAddress<a name="afe6b53a61bbec5e062406715ea089349"></a>

```
int32_t(* IWiFiBaseFeature::setMacAddress) (const struct IWiFiBaseFeature *baseFeature, unsigned char *mac, uint8_t len)
```

**描述：**

根据传入参数设置对应网卡的MAC地址。

**参数：**

<a name="table1126809291083932"></a>
<table><thead align="left"><tr id="row989988141083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1841986741083932"><a name="p1841986741083932"></a><a name="p1841986741083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1003540030083932"><a name="p1003540030083932"></a><a name="p1003540030083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row750234017083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry296432439083932p0"><a name="entry296432439083932p0"></a><a name="entry296432439083932p0"></a>baseFeature</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry928528806083932p0"><a name="entry928528806083932p0"></a><a name="entry928528806083932p0"></a>输入参数，基本特性<a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a>。</p>
</td>
</tr>
<tr id="row118122226083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry657098581083932p0"><a name="entry657098581083932p0"></a><a name="entry657098581083932p0"></a>mac</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1292561570083932p0"><a name="entry1292561570083932p0"></a><a name="entry1292561570083932p0"></a>输入参数，设置的MAC地址。</p>
</td>
</tr>
<tr id="row1786774081083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry423193649083932p0"><a name="entry423193649083932p0"></a><a name="entry423193649083932p0"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry56588592083932p0"><a name="entry56588592083932p0"></a><a name="entry56588592083932p0"></a>输入参数，设置的MAC地址长度。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## setTxPower<a name="a48a0bfce07012d0f79883b9457e9d87d"></a>

```
int32_t(* IWiFiBaseFeature::setTxPower) (const struct IWiFiBaseFeature *baseFeature, int32_t power)
```

**描述：**

设置发射功率。

**参数：**

<a name="table1036140220083932"></a>
<table><thead align="left"><tr id="row248084163083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p897255175083932"><a name="p897255175083932"></a><a name="p897255175083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1823115531083932"><a name="p1823115531083932"></a><a name="p1823115531083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row344656176083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry751908987083932p0"><a name="entry751908987083932p0"></a><a name="entry751908987083932p0"></a>baseFeature</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1190324301083932p0"><a name="entry1190324301083932p0"></a><a name="entry1190324301083932p0"></a>输入参数，基本特性<a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a>。</p>
</td>
</tr>
<tr id="row1530156651083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2070714106083932p0"><a name="entry2070714106083932p0"></a><a name="entry2070714106083932p0"></a>power</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1177299659083932p0"><a name="entry1177299659083932p0"></a><a name="entry1177299659083932p0"></a>输入参数，设置的发射功率。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

