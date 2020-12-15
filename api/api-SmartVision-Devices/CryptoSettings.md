# CryptoSettings<a name="ZH-CN_TOPIC_0000001054718121"></a>

-   [Overview](#section1206504114165631)
-   [Summary](#section969690503165631)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section1206504114165631"></a>

**Related Modules:**

[WLAN](WLAN.md)

**Description:**

Describes cryptography settings. 

**Since:**

1.0

## **Summary**<a name="section969690503165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1012142149165631"></a>
<table><thead align="left"><tr id="row2135705609165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1230648579165631"><a name="p1230648579165631"></a><a name="p1230648579165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2026093866165631"><a name="p2026093866165631"></a><a name="p2026093866165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1971006897165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p996026958165631"><a name="p996026958165631"></a><a name="p996026958165631"></a><a href="WLAN.md#ga2b21ef556b428238d4dc5009b82087ff">wpaVersions</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1742516287165631"><a name="p1742516287165631"></a><a name="p1742516287165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row514961990165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1712463173165631"><a name="p1712463173165631"></a><a name="p1712463173165631"></a><a href="WLAN.md#ga9be34adb7e26191321b38c37b341e20d">cipherGroup</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p714818404165631"><a name="p714818404165631"></a><a name="p714818404165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row1014005362165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1019842383165631"><a name="p1019842383165631"></a><a name="p1019842383165631"></a><a href="WLAN.md#gace9dbbf9c1a035b350224b1832d35377">n_ciphersPairwise</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p755474686165631"><a name="p755474686165631"></a><a name="p755474686165631"></a>int32_t </p>
</td>
</tr>
<tr id="row1903097872165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p457147287165631"><a name="p457147287165631"></a><a name="p457147287165631"></a><a href="WLAN.md#ga53c85b4e0f5f5e10bb16935fb8a77df0">ciphersPairwise</a> [NL80211_MAX_NR_CIPHER_SUITES]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p101451314165631"><a name="p101451314165631"></a><a name="p101451314165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row866086288165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1720964211165631"><a name="p1720964211165631"></a><a name="p1720964211165631"></a><a href="WLAN.md#ga35627fc7ac0924a52e51427375501f8a">n_akmSuites</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p585886769165631"><a name="p585886769165631"></a><a name="p585886769165631"></a>int32_t </p>
</td>
</tr>
<tr id="row853730938165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p162181737165631"><a name="p162181737165631"></a><a name="p162181737165631"></a><a href="WLAN.md#ga142aeeaed24db6cd329c0b8b78ab13bc">akmSuites</a> [NL80211_MAX_NR_AKM_SUITES]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1176412896165631"><a name="p1176412896165631"></a><a name="p1176412896165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row1844168271165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p462780130165631"><a name="p462780130165631"></a><a name="p462780130165631"></a><a href="WLAN.md#ga67b6c08be0641796798513fbbb13dd73">controlPortEthertype</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p384627576165631"><a name="p384627576165631"></a><a name="p384627576165631"></a>uint16_t </p>
</td>
</tr>
<tr id="row1981426318165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1411921963165631"><a name="p1411921963165631"></a><a name="p1411921963165631"></a><a href="WLAN.md#ga2f49a07024546730d0cd60e93cb9e450">controlPort</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p319855997165631"><a name="p319855997165631"></a><a name="p319855997165631"></a>int8_t </p>
</td>
</tr>
<tr id="row2093462018165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p218544120165631"><a name="p218544120165631"></a><a name="p218544120165631"></a><a href="WLAN.md#ga020b34dbfd5f961c86ef416873a9c02c">controlPortNoEncrypt</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p942903110165631"><a name="p942903110165631"></a><a name="p942903110165631"></a>int8_t </p>
</td>
</tr>
</tbody>
</table>

