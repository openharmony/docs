# hdf\_log.h<a name="EN-US_TOPIC_0000001054918123"></a>

-   [Overview](#section85189941165627)
-   [Summary](#section1068036471165627)
-   [Macros](#define-members)

## **Overview**<a name="section85189941165627"></a>

**Related Modules:**

[DriverUtils](driverutils.md)

**Description:**

Declares log printing functions of the driver module. This module provides functions for printing logs at the verbose, debug, information, warning, and error levels. 

To use these functions, you must define  **HDF\_LOG\_TAG**, for example, \#define HDF\_LOG\_TAG evt.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1068036471165627"></a>

## Macros<a name="define-members"></a>

<a name="table661385496165627"></a>
<table><thead align="left"><tr id="row2081287675165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1815779085165627"><a name="p1815779085165627"></a><a name="p1815779085165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1817401365165627"><a name="p1817401365165627"></a><a name="p1817401365165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1307982524165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p648293816165627"><a name="p648293816165627"></a><a name="p648293816165627"></a><a href="driverutils.md#ga7e862bda9f0b95d1628f6f62598f1f42">LOG_TAG_MARK_EXTEND</a>(HDF_TAG)   #HDF_TAG</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row544310956165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p778753995165627"><a name="p778753995165627"></a><a name="p778753995165627"></a><a href="driverutils.md#ga4abebfca1aaeb8125f85800425caf304">HDF_LOGV</a>(fmt, arg...)   <a href="io.md#ga98631211a4a8aee62f572375d5b637be">printf</a>("[HDF:V/" LOG_TAG "]" fmt "\r\n", ##arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1979507370165627"><a name="p1979507370165627"></a><a name="p1979507370165627"></a>Prints logs at the verbose level. </p>
</td>
</tr>
<tr id="row1403585574165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p228125667165627"><a name="p228125667165627"></a><a name="p228125667165627"></a><a href="driverutils.md#gaa0411582f697619cdb045ae61ac42539">HDF_LOGD</a>(fmt, arg...)   <a href="io.md#ga98631211a4a8aee62f572375d5b637be">printf</a>("[HDF:D/" LOG_TAG "]" fmt "\r\n", ##arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p778332602165627"><a name="p778332602165627"></a><a name="p778332602165627"></a>Prints logs at the debug level. </p>
</td>
</tr>
<tr id="row1173582297165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p82532840165627"><a name="p82532840165627"></a><a name="p82532840165627"></a><a href="driverutils.md#ga369d56841d17e6908fc6885fcb814b80">HDF_LOGI</a>(fmt, arg...)   <a href="io.md#ga98631211a4a8aee62f572375d5b637be">printf</a>("[HDF:I/" LOG_TAG "]" fmt "\r\n", ##arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1466410148165627"><a name="p1466410148165627"></a><a name="p1466410148165627"></a>Prints logs at the information level. </p>
</td>
</tr>
<tr id="row2143801864165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p725003520165627"><a name="p725003520165627"></a><a name="p725003520165627"></a><a href="driverutils.md#ga72f232dade88b85aff2d8c0e42b82df0">HDF_LOGW</a>(fmt, arg...)   <a href="io.md#ga98631211a4a8aee62f572375d5b637be">printf</a>("[HDF:W/" LOG_TAG "]" fmt "\r\n", ##arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p506587631165627"><a name="p506587631165627"></a><a name="p506587631165627"></a>Prints logs at the warning level. </p>
</td>
</tr>
<tr id="row618449535165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2010237531165627"><a name="p2010237531165627"></a><a name="p2010237531165627"></a><a href="driverutils.md#gaacd0eb778948960a7f97af155287ce8c">HDF_LOGE</a>(fmt, arg...)   <a href="io.md#ga98631211a4a8aee62f572375d5b637be">printf</a>("[HDF:E/" LOG_TAG "]" fmt "\r\n", ##arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1839673280165627"><a name="p1839673280165627"></a><a name="p1839673280165627"></a>Prints logs at the error level. </p>
</td>
</tr>
</tbody>
</table>

