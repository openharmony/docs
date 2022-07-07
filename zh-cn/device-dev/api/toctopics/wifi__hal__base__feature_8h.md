# wifi\_hal\_base\_feature.h<a name="ZH-CN_TOPIC_0000001290561144"></a>

## **概述**<a name="section1353610900083931"></a>

**所属模块:**

[WLAN](_w_l_a_n.md)

## **汇总**<a name="section403762605083931"></a>

## 类<a name="nested-classes"></a>

<a name="table367320829083931"></a>
<table><thead align="left"><tr id="row1562004198083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1689706546083931"><a name="p1689706546083931"></a><a name="p1689706546083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p527341916083931"><a name="p527341916083931"></a><a name="p527341916083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1384756297083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1338022536083931"><a name="p1338022536083931"></a><a name="p1338022536083931"></a><a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p342957881083931"><a name="p342957881083931"></a><a name="p342957881083931"></a>WLAN基本特性操作接口，包括获取网卡名称，设置MAC地址，设置发射功率等公共能力接口。 <a href="_i_wi_fi_base_feature.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 宏定义<a name="define-members"></a>

<a name="table598924707083931"></a>
<table><thead align="left"><tr id="row1124844842083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1856217083931"><a name="p1856217083931"></a><a name="p1856217083931"></a>宏定义</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1357262162083931"><a name="p1357262162083931"></a><a name="p1357262162083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1379287062083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1882068118083931"><a name="p1882068118083931"></a><a name="p1882068118083931"></a><a href="_w_l_a_n.md#ga63637ece87095ff8d153f650434ecf97">IFNAME_MAX_LEN</a>   16</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p707366547083931"><a name="p707366547083931"></a><a name="p707366547083931"></a>网卡名称最大长度。</p>
</td>
</tr>
<tr id="row845997065083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p320378880083931"><a name="p320378880083931"></a><a name="p320378880083931"></a><a href="_w_l_a_n.md#ga27ea7645cf89c113dae48346e19a676f">WIFI_MAC_ADDR_LENGTH</a>   6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p550077496083931"><a name="p550077496083931"></a><a name="p550077496083931"></a>WLAN的MAC地址长度。</p>
</td>
</tr>
<tr id="row1195912645083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1606713319083931"><a name="p1606713319083931"></a><a name="p1606713319083931"></a><a href="_w_l_a_n.md#gadfe9ac5a374d348cd8f77a84cd5ab94e">ERR_UNAUTH_ACCESS</a>   (-6)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2106591476083931"><a name="p2106591476083931"></a><a name="p2106591476083931"></a>定义访问失败错误码。</p>
</td>
</tr>
</tbody>
</table>

## 枚举<a name="enum-members"></a>

<a name="table1045627179083931"></a>
<table><thead align="left"><tr id="row610398091083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p763540428083931"><a name="p763540428083931"></a><a name="p763540428083931"></a>枚举</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1905201854083931"><a name="p1905201854083931"></a><a name="p1905201854083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1475608189083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1237377984083931"><a name="p1237377984083931"></a><a name="p1237377984083931"></a><a href="_w_l_a_n.md#gad2b28a6ade408676d1371ea941824012">FeatureType</a> {   <a href="_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012a6b209b916aabd18f2a950a82e68b6a4c">PROTOCOL_80211_IFTYPE_UNSPECIFIED</a>, <a href="_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012a0926a98ddc2ceec4ba58ebfc01c5fe35">PROTOCOL_80211_IFTYPE_ADHOC</a>, <a href="_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012acd26f8cefbd658e9ea02feecefd054fb">PROTOCOL_80211_IFTYPE_STATION</a>, <a href="_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012a9e92654b9ab6ed6eb62868f1e0e4ea8f">PROTOCOL_80211_IFTYPE_AP</a>,   <a href="_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012a991ad1a3f8c43b06c4eeb9dc88acdb1e">PROTOCOL_80211_IFTYPE_AP_VLAN</a>, <a href="_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012aa25631c32cd6c996a7c96ba4f61299e2">PROTOCOL_80211_IFTYPE_WDS</a>, <a href="_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012a3ff1c1358af5a0c50b64e0ef0e96a970">PROTOCOL_80211_IFTYPE_MONITOR</a>, <a href="_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012a382756b8a71015cd536cdbc113c4f483">PROTOCOL_80211_IFTYPE_MESH_POINT</a>,   <a href="_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012acfd81d6e484c6f7a3b863327af112cfc">PROTOCOL_80211_IFTYPE_P2P_CLIENT</a>, <a href="_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012abca0ccb5cf4c14af9b6ff0bd9eeb4173">PROTOCOL_80211_IFTYPE_P2P_GO</a>, <a href="_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012ad63ad4a5a66892e842e4d75cc82b0755">PROTOCOL_80211_IFTYPE_P2P_DEVICE</a>, <a href="_w_l_a_n.md#p3611518433">PROTOCOL_80211_IFTYPE_NUM</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p185371790083931"><a name="p185371790083931"></a><a name="p185371790083931"></a>枚举WLAN相关特性的类型<a href="_w_l_a_n.md#gad2b28a6ade408676d1371ea941824012">FeatureType</a>。 <a href="_w_l_a_n.md#gad2b28a6ade408676d1371ea941824012">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 函数<a name="func-members"></a>

<a name="table593874652083931"></a>
<table><thead align="left"><tr id="row2106713317083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p364196658083931"><a name="p364196658083931"></a><a name="p364196658083931"></a>函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1250789531083931"><a name="p1250789531083931"></a><a name="p1250789531083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row659918891083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p525022384083931"><a name="p525022384083931"></a><a name="p525022384083931"></a><a href="_w_l_a_n.md#ga09c0538ddabbc140480e24fb8b3c25e4">InitBaseFeature</a> (struct <a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a> **fe)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1937964889083931"><a name="p1937964889083931"></a><a name="p1937964889083931"></a>WLAN服务创建任何类型的特性{@Link FeatureType}时，都需要调用此函数。 <a href="_w_l_a_n.md#ga09c0538ddabbc140480e24fb8b3c25e4">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section999680322083931"></a>

提供WLAN基本特性能力。

**Since：**

1.0

**Version：**

1.0

