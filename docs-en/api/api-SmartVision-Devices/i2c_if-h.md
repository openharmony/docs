# i2c\_if.h<a name="EN-US_TOPIC_0000001054479535"></a>

-   [Overview](#section128619600165627)
-   [Summary](#section2094038425165627)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section128619600165627"></a>

**Related Modules:**

[I2C](i2c.md)

**Description:**

Declares the standard I2C interface functions. 

**Since:**

1.0

## **Summary**<a name="section2094038425165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1586257614165627"></a>
<table><thead align="left"><tr id="row351023303165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p740360593165627"><a name="p740360593165627"></a><a name="p740360593165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1489113103165627"><a name="p1489113103165627"></a><a name="p1489113103165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1922984107165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p453426949165627"><a name="p453426949165627"></a><a name="p453426949165627"></a><a href="i2cmsg.md">I2cMsg</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p17417393165627"><a name="p17417393165627"></a><a name="p17417393165627"></a>Defines the I2C transfer message used during custom transfers. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table208715155165627"></a>
<table><thead align="left"><tr id="row1551150252165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p63042454165627"><a name="p63042454165627"></a><a name="p63042454165627"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1439743886165627"><a name="p1439743886165627"></a><a name="p1439743886165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1718954417165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1652796845165627"><a name="p1652796845165627"></a><a name="p1652796845165627"></a><a href="i2c.md#ga32b58f021632085445d80c80e382a546">I2cFlag</a> {   <a href="i2c.md#gga32b58f021632085445d80c80e382a546a65c5829d919f53dbc00b4c4e3f5a2f7a">I2C_FLAG_READ</a> = (0x1 &lt;&lt; 0), <a href="i2c.md#gga32b58f021632085445d80c80e382a546a830aec226b260e4624fb81f355e4fbd6">I2C_FLAG_ADDR_10BIT</a> = (0x1 &lt;&lt; 4), <a href="i2c.md#gga32b58f021632085445d80c80e382a546a801a2ec0dcf3069ba412311d00e45356">I2C_FLAG_READ_NO_ACK</a> = (0x1 &lt;&lt; 11), <a href="i2c.md#gga32b58f021632085445d80c80e382a546a6c8d6f7ba01b0e45fb73ee5883ba311c">I2C_FLAG_IGNORE_NO_ACK</a> = (0x1 &lt;&lt; 12),   <a href="i2c.md#gga32b58f021632085445d80c80e382a546a87b7c3b732260789c5acd9245171ad25">I2C_FLAG_NO_START</a> = (0x1 &lt;&lt; 14), <a href="i2c.md#gga32b58f021632085445d80c80e382a546a641c29990d13fe5f840b495dca8e21e9">I2C_FLAG_STOP</a> = (0x1 &lt;&lt; 15) }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1200057953165627"><a name="p1200057953165627"></a><a name="p1200057953165627"></a>Enumerates flags used for transferring I2C messages. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table2104986207165627"></a>
<table><thead align="left"><tr id="row1753602323165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1720297129165627"><a name="p1720297129165627"></a><a name="p1720297129165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1770296411165627"><a name="p1770296411165627"></a><a name="p1770296411165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1554102380165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1297922641165627"><a name="p1297922641165627"></a><a name="p1297922641165627"></a><a href="i2c.md#ga564086bbb2121cd6771c66c886da11b5">I2cOpen</a> (int16_t number)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p758566898165627"><a name="p758566898165627"></a><a name="p758566898165627"></a><a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> </p>
<p id="p246622755165627"><a name="p246622755165627"></a><a name="p246622755165627"></a>Obtains the handle of an I2C controller. </p>
</td>
</tr>
<tr id="row686067202165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p597549966165627"><a name="p597549966165627"></a><a name="p597549966165627"></a><a href="i2c.md#ga3ca9d500e6fb6592a04f7dc33806c13e">I2cClose</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1873875376165627"><a name="p1873875376165627"></a><a name="p1873875376165627"></a>void </p>
<p id="p872380995165627"><a name="p872380995165627"></a><a name="p872380995165627"></a>Releases the handle of an I2C controller. </p>
</td>
</tr>
<tr id="row1617341674165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1748730061165627"><a name="p1748730061165627"></a><a name="p1748730061165627"></a><a href="i2c.md#ga2395dc94da99c2b990096c659fcefc72">I2cTransfer</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, struct <a href="i2cmsg.md">I2cMsg</a> *msgs, int16_t count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1210012438165627"><a name="p1210012438165627"></a><a name="p1210012438165627"></a>int32_t </p>
<p id="p999411075165627"><a name="p999411075165627"></a><a name="p999411075165627"></a>Launches a custom transfer to an I2C device. </p>
</td>
</tr>
</tbody>
</table>

