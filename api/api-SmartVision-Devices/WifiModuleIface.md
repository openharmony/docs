# WifiModuleIface<a name="ZH-CN_TOPIC_0000001054918197"></a>

-   [Overview](#section738593741165636)
-   [Summary](#section565228422165636)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section738593741165636"></a>

**Related Modules:**

[WLAN](WLAN.md)

**Description:**

Defines WLAN module APIs. 

The APIs can be used to obtain, initialize, update, and perform other operations on a WLAN module.

**Since:**

1.0

## **Summary**<a name="section565228422165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1329522415165636"></a>
<table><thead align="left"><tr id="row1503795215165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p887926600165636"><a name="p887926600165636"></a><a name="p887926600165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p746322971165636"><a name="p746322971165636"></a><a name="p746322971165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1812855598165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p104955735165636"><a name="p104955735165636"></a><a name="p104955735165636"></a><a href="WLAN.md#gad7c080e7ac22daf18529184da55e910c">getModule</a> )(void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p739252620165636"><a name="p739252620165636"></a><a name="p739252620165636"></a>struct <a href="WifiModule.md">WifiModule</a> *(* </p>
</td>
</tr>
<tr id="row719340803165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p104419658165636"><a name="p104419658165636"></a><a name="p104419658165636"></a><a href="WLAN.md#ga5166022e5100e57fe0b307a4254e3dc1">updateModule</a> )(struct <a href="WifiModule.md">WifiModule</a> *module)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p203508361165636"><a name="p203508361165636"></a><a name="p203508361165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row1608658108165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p896568419165636"><a name="p896568419165636"></a><a name="p896568419165636"></a><a href="WLAN.md#gadf3d907844092764d8c8d3ce150e1712">init</a> )(struct <a href="WifiModule.md">WifiModule</a> *module)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1478827978165636"><a name="p1478827978165636"></a><a name="p1478827978165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row830705654165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1280136431165636"><a name="p1280136431165636"></a><a name="p1280136431165636"></a><a href="WLAN.md#ga378c89a04bb867068d3c86c5680ca9c0">deInit</a> )(struct <a href="WifiModule.md">WifiModule</a> *module)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1802519288165636"><a name="p1802519288165636"></a><a name="p1802519288165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row1162421298165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p459462172165636"><a name="p459462172165636"></a><a name="p459462172165636"></a><a href="WLAN.md#gadfa86fac18c68b890d3b33a269931efc">addFeature</a> )(struct <a href="WifiModule.md">WifiModule</a> *module, uint16_t featureType, struct <a href="WifiFeature.md">WifiFeature</a> *featureData)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p267185050165636"><a name="p267185050165636"></a><a name="p267185050165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row1230855518165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p940117685165636"><a name="p940117685165636"></a><a name="p940117685165636"></a><a href="WLAN.md#ga764ebf11b82c57d5185df50fab72a1d8">delFeature</a> )(struct <a href="WifiModule.md">WifiModule</a> *module, uint16_t featureType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p771985898165636"><a name="p771985898165636"></a><a name="p771985898165636"></a>int32_t(* </p>
</td>
</tr>
</tbody>
</table>

