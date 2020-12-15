# WifiModule<a name="EN-US_TOPIC_0000001054718169"></a>

-   [Overview](#section1120062347165636)
-   [Summary](#section1930645831165636)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section1120062347165636"></a>

**Related Modules:**

[WLAN](wlan.md)

**Description:**

Defines the WLAN module. 

The structure contains private data, APIs, module configurations, a module that communicates with user-level processes, and WLAN features.

**Since:**

1.0

## **Summary**<a name="section1930645831165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table515157890165636"></a>
<table><thead align="left"><tr id="row367125978165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1074660505165636"><a name="p1074660505165636"></a><a name="p1074660505165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1671704298165636"><a name="p1671704298165636"></a><a name="p1671704298165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1725049322165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p33425531165636"><a name="p33425531165636"></a><a name="p33425531165636"></a><a href="wlan.md#gab8c955bd3dd2cb79c3c0c3dfdc3b08f5">modulePrivate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p840039249165636"><a name="p840039249165636"></a><a name="p840039249165636"></a>void * </p>
</td>
</tr>
<tr id="row309576805165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p218800165636"><a name="p218800165636"></a><a name="p218800165636"></a><a href="wlan.md#ga8666b5068c46aa89a3cae49b7a31c224">iface</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p996330267165636"><a name="p996330267165636"></a><a name="p996330267165636"></a>struct <a href="wifimoduleiface.md">WifiModuleIface</a> * </p>
</td>
</tr>
<tr id="row836732870165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1692830838165636"><a name="p1692830838165636"></a><a name="p1692830838165636"></a><a href="wlan.md#gaa54566af9b7dda68e119649b3510c858">moduleConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p535828712165636"><a name="p535828712165636"></a><a name="p535828712165636"></a>struct <a href="wifimoduleconfig.md">WifiModuleConfig</a> </p>
</td>
</tr>
<tr id="row503261021165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1358505154165636"><a name="p1358505154165636"></a><a name="p1358505154165636"></a><a href="wlan.md#ga347d5b39c9a96835ae85358ba0895cc3">feList</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1140566196165636"><a name="p1140566196165636"></a><a name="p1140566196165636"></a>struct <a href="wififeaturelist.md">WifiFeatureList</a> * </p>
</td>
</tr>
</tbody>
</table>

