# Ieee80211Channel<a name="ZH-CN_TOPIC_0000001054879538"></a>

-   [Overview](#section1507479398165632)
-   [Summary](#section830081582165632)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section1507479398165632"></a>

**Related Modules:**

[WLAN](WLAN.md)

**Description:**

Describes a communication channel. 

**Since:**

1.0

## **Summary**<a name="section830081582165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table420564105165632"></a>
<table><thead align="left"><tr id="row393381909165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p665620449165632"><a name="p665620449165632"></a><a name="p665620449165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p983041601165632"><a name="p983041601165632"></a><a name="p983041601165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1920694194165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p867375670165632"><a name="p867375670165632"></a><a name="p867375670165632"></a><a href="WLAN.md#gaab4e3330566d5b0b02e7c6117c7b9a73">band</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p361623278165632"><a name="p361623278165632"></a><a name="p361623278165632"></a>enum <a href="WLAN.md#ga9882f415202cf9acb0f4cdfbc456a88d">Ieee80211Band</a> </p>
</td>
</tr>
<tr id="row1578046767165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1961902357165632"><a name="p1961902357165632"></a><a name="p1961902357165632"></a><a href="WLAN.md#ga42300a5593bf6b40a4d823af2dbe2a5d">centerFreq</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1313258531165632"><a name="p1313258531165632"></a><a name="p1313258531165632"></a>uint16_t </p>
</td>
</tr>
<tr id="row1846637723165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1756298476165632"><a name="p1756298476165632"></a><a name="p1756298476165632"></a><a href="WLAN.md#ga88c500579917b7a4b0167623851abcf2">hwValue</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2082625562165632"><a name="p2082625562165632"></a><a name="p2082625562165632"></a>uint16_t </p>
</td>
</tr>
<tr id="row425509109165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p812347317165632"><a name="p812347317165632"></a><a name="p812347317165632"></a><a href="WLAN.md#gaadedfd33df129639f135a6f5d0322e4e">flags</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2070757576165632"><a name="p2070757576165632"></a><a name="p2070757576165632"></a>uint32_t </p>
</td>
</tr>
<tr id="row629303333165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p551669637165632"><a name="p551669637165632"></a><a name="p551669637165632"></a><a href="WLAN.md#gacd256a8179e084497aad4cacfac77dc2">maxAntennaGain</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1196730591165632"><a name="p1196730591165632"></a><a name="p1196730591165632"></a>int32_t </p>
</td>
</tr>
<tr id="row1569929335165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1756314711165632"><a name="p1756314711165632"></a><a name="p1756314711165632"></a><a href="WLAN.md#gaf998a486d7bc53071e68374a13aa18d8">maxPower</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p600546623165632"><a name="p600546623165632"></a><a name="p600546623165632"></a>int32_t </p>
</td>
</tr>
<tr id="row1094557743165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p921327224165632"><a name="p921327224165632"></a><a name="p921327224165632"></a><a href="WLAN.md#ga55c6f1eaedc16b99dc299530a0dc6f83">beaconFound</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p904380545165632"><a name="p904380545165632"></a><a name="p904380545165632"></a>int8_t </p>
</td>
</tr>
<tr id="row511173461165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p342756819165632"><a name="p342756819165632"></a><a name="p342756819165632"></a><a href="WLAN.md#ga8ae51118ee5e1a121bad85055ecad454">resv</a> [IEEE80211_CHANNEL_RESV]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1981222229165632"><a name="p1981222229165632"></a><a name="p1981222229165632"></a>uint8_t </p>
</td>
</tr>
<tr id="row1188909295165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p972461363165632"><a name="p972461363165632"></a><a name="p972461363165632"></a><a href="WLAN.md#gaa8e6146a2fa16a47e794d7d9bbaccf1e">origFlags</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p931488806165632"><a name="p931488806165632"></a><a name="p931488806165632"></a>uint32_t </p>
</td>
</tr>
<tr id="row682730762165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p928495984165632"><a name="p928495984165632"></a><a name="p928495984165632"></a><a href="WLAN.md#gaf5bc0d20f7c46fbcfd69cb62c3470dfe">origMag</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p162933286165632"><a name="p162933286165632"></a><a name="p162933286165632"></a>int32_t </p>
</td>
</tr>
<tr id="row1339872211165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1885086152165632"><a name="p1885086152165632"></a><a name="p1885086152165632"></a><a href="WLAN.md#gaa9666ab4a0f723741328722d1ab74588">origMpwr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1582595998165632"><a name="p1582595998165632"></a><a name="p1582595998165632"></a>int32_t </p>
</td>
</tr>
</tbody>
</table>

