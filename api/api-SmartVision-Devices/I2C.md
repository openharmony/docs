# I2C<a name="ZH-CN_TOPIC_0000001054718075"></a>

-   [Overview](#section1269538504165623)
-   [Summary](#section1310832739165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section1093936068165623)
-   [Enumeration Type](#section716022081165623)
-   [I2cFlag](#ga32b58f021632085445d80c80e382a546)
-   [Function](#section1683434957165623)
-   [I2cClose\(\)](#ga3ca9d500e6fb6592a04f7dc33806c13e)
-   [I2cOpen\(\)](#ga564086bbb2121cd6771c66c886da11b5)
-   [I2cTransfer\(\)](#ga2395dc94da99c2b990096c659fcefc72)

## **Overview**<a name="section1269538504165623"></a>

**Description:**

Provides standard Inter-Integrated Circuit \(I2C\) interfaces. 

This module allows a driver to perform operations on an I2C controller for accessing devices on the I2C bus, including creating and destroying I2C controller handles as well as reading and writing data.

**Since:**

1.0

## **Summary**<a name="section1310832739165623"></a>

## Files<a name="files"></a>

<a name="table26709998165623"></a>
<table><thead align="left"><tr id="row1656041532165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p294052170165623"><a name="p294052170165623"></a><a name="p294052170165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2254416165623"><a name="p2254416165623"></a><a name="p2254416165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row309972251165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1707855681165623"><a name="p1707855681165623"></a><a name="p1707855681165623"></a><a href="i2c_if-h.md">i2c_if.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2026965133165623"><a name="p2026965133165623"></a><a name="p2026965133165623"></a>Declares the standard I2C interface functions. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1324012234165623"></a>
<table><thead align="left"><tr id="row326440456165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1416212243165623"><a name="p1416212243165623"></a><a name="p1416212243165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p720476982165623"><a name="p720476982165623"></a><a name="p720476982165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2081252798165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p608604646165623"><a name="p608604646165623"></a><a name="p608604646165623"></a><a href="I2cMsg.md">I2cMsg</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1610801398165623"><a name="p1610801398165623"></a><a name="p1610801398165623"></a>Defines the I2C transfer message used during custom transfers. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table628369493165623"></a>
<table><thead align="left"><tr id="row962240747165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2023553325165623"><a name="p2023553325165623"></a><a name="p2023553325165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1629020646165623"><a name="p1629020646165623"></a><a name="p1629020646165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row529206352165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1456252457165623"><a name="p1456252457165623"></a><a name="p1456252457165623"></a><a href="I2C.md#ga32b58f021632085445d80c80e382a546">I2cFlag</a> {   <a href="I2C.md#gga32b58f021632085445d80c80e382a546a65c5829d919f53dbc00b4c4e3f5a2f7a">I2C_FLAG_READ</a> = (0x1 &lt;&lt; 0), <a href="I2C.md#gga32b58f021632085445d80c80e382a546a830aec226b260e4624fb81f355e4fbd6">I2C_FLAG_ADDR_10BIT</a> = (0x1 &lt;&lt; 4), <a href="I2C.md#gga32b58f021632085445d80c80e382a546a801a2ec0dcf3069ba412311d00e45356">I2C_FLAG_READ_NO_ACK</a> = (0x1 &lt;&lt; 11), <a href="I2C.md#gga32b58f021632085445d80c80e382a546a6c8d6f7ba01b0e45fb73ee5883ba311c">I2C_FLAG_IGNORE_NO_ACK</a> = (0x1 &lt;&lt; 12),   <a href="I2C.md#gga32b58f021632085445d80c80e382a546a87b7c3b732260789c5acd9245171ad25">I2C_FLAG_NO_START</a> = (0x1 &lt;&lt; 14), <a href="I2C.md#gga32b58f021632085445d80c80e382a546a641c29990d13fe5f840b495dca8e21e9">I2C_FLAG_STOP</a> = (0x1 &lt;&lt; 15) }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2144732974165623"><a name="p2144732974165623"></a><a name="p2144732974165623"></a>Enumerates flags used for transferring I2C messages. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1308046703165623"></a>
<table><thead align="left"><tr id="row48201093165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1329338767165623"><a name="p1329338767165623"></a><a name="p1329338767165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p587185350165623"><a name="p587185350165623"></a><a name="p587185350165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row656492065165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1954558581165623"><a name="p1954558581165623"></a><a name="p1954558581165623"></a><a href="I2C.md#ga564086bbb2121cd6771c66c886da11b5">I2cOpen</a> (int16_t number)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p810460764165623"><a name="p810460764165623"></a><a name="p810460764165623"></a><a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> </p>
<p id="p1080045134165623"><a name="p1080045134165623"></a><a name="p1080045134165623"></a>Obtains the handle of an I2C controller. </p>
</td>
</tr>
<tr id="row2121925849165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1914323964165623"><a name="p1914323964165623"></a><a name="p1914323964165623"></a><a href="I2C.md#ga3ca9d500e6fb6592a04f7dc33806c13e">I2cClose</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p453373180165623"><a name="p453373180165623"></a><a name="p453373180165623"></a>void </p>
<p id="p1648760846165623"><a name="p1648760846165623"></a><a name="p1648760846165623"></a>Releases the handle of an I2C controller. </p>
</td>
</tr>
<tr id="row946427740165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1830925313165623"><a name="p1830925313165623"></a><a name="p1830925313165623"></a><a href="I2C.md#ga2395dc94da99c2b990096c659fcefc72">I2cTransfer</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, struct <a href="I2cMsg.md">I2cMsg</a> *msgs, int16_t count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p211409350165623"><a name="p211409350165623"></a><a name="p211409350165623"></a>int32_t </p>
<p id="p1448415766165623"><a name="p1448415766165623"></a><a name="p1448415766165623"></a>Launches a custom transfer to an I2C device. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1093936068165623"></a>

## **Enumeration Type **<a name="section716022081165623"></a>

## I2cFlag<a name="ga32b58f021632085445d80c80e382a546"></a>

```
enum [I2cFlag](I2C.md#ga32b58f021632085445d80c80e382a546)
```

 **Description:**

Enumerates flags used for transferring I2C messages. 

Multiple flags can be used to jointly control a single I2C message transfer. If a bit is set to  **1**, the corresponding feature is enabled. If a bit is set to  **0**, the corresponding feature is disabled.

<a name="table298426190165623"></a>
<table><thead align="left"><tr id="row1781763442165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1542075223165623"><a name="p1542075223165623"></a><a name="p1542075223165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p464808686165623"><a name="p464808686165623"></a><a name="p464808686165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row355170349165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga32b58f021632085445d80c80e382a546a65c5829d919f53dbc00b4c4e3f5a2f7a"><a name="gga32b58f021632085445d80c80e382a546a65c5829d919f53dbc00b4c4e3f5a2f7a"></a><a name="gga32b58f021632085445d80c80e382a546a65c5829d919f53dbc00b4c4e3f5a2f7a"></a></strong>I2C_FLAG_READ </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1440192614165623"><a name="p1440192614165623"></a><a name="p1440192614165623"></a>Read flag. The value <strong id="b1800144392165623"><a name="b1800144392165623"></a><a name="b1800144392165623"></a>1</strong> indicates the read operation, and <strong id="b1121098846165623"><a name="b1121098846165623"></a><a name="b1121098846165623"></a>0</strong> indicates the write operation. </p>
 </td>
</tr>
<tr id="row459796746165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga32b58f021632085445d80c80e382a546a830aec226b260e4624fb81f355e4fbd6"><a name="gga32b58f021632085445d80c80e382a546a830aec226b260e4624fb81f355e4fbd6"></a><a name="gga32b58f021632085445d80c80e382a546a830aec226b260e4624fb81f355e4fbd6"></a></strong>I2C_FLAG_ADDR_10BIT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1545073534165623"><a name="p1545073534165623"></a><a name="p1545073534165623"></a>10-bit addressing flag. The value <strong id="b855026656165623"><a name="b855026656165623"></a><a name="b855026656165623"></a>1</strong> indicates that a 10-bit address is used. </p>
 </td>
</tr>
<tr id="row320753612165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga32b58f021632085445d80c80e382a546a801a2ec0dcf3069ba412311d00e45356"><a name="gga32b58f021632085445d80c80e382a546a801a2ec0dcf3069ba412311d00e45356"></a><a name="gga32b58f021632085445d80c80e382a546a801a2ec0dcf3069ba412311d00e45356"></a></strong>I2C_FLAG_READ_NO_ACK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1595100506165623"><a name="p1595100506165623"></a><a name="p1595100506165623"></a>Non-ACK read flag. The value <strong id="b970587454165623"><a name="b970587454165623"></a><a name="b970587454165623"></a>1</strong> indicates that no ACK signal is sent during the read process. </p>
 </td>
</tr>
<tr id="row1630278658165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga32b58f021632085445d80c80e382a546a6c8d6f7ba01b0e45fb73ee5883ba311c"><a name="gga32b58f021632085445d80c80e382a546a6c8d6f7ba01b0e45fb73ee5883ba311c"></a><a name="gga32b58f021632085445d80c80e382a546a6c8d6f7ba01b0e45fb73ee5883ba311c"></a></strong>I2C_FLAG_IGNORE_NO_ACK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1497930094165623"><a name="p1497930094165623"></a><a name="p1497930094165623"></a>Ignoring no-ACK flag. The value <strong id="b147895848165623"><a name="b147895848165623"></a><a name="b147895848165623"></a>1</strong> indicates that the non-ACK signal is ignored. </p>
 </td>
</tr>
<tr id="row712998680165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga32b58f021632085445d80c80e382a546a87b7c3b732260789c5acd9245171ad25"><a name="gga32b58f021632085445d80c80e382a546a87b7c3b732260789c5acd9245171ad25"></a><a name="gga32b58f021632085445d80c80e382a546a87b7c3b732260789c5acd9245171ad25"></a></strong>I2C_FLAG_NO_START </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p227040693165623"><a name="p227040693165623"></a><a name="p227040693165623"></a>No START condition flag. The value <strong id="b1688005416165623"><a name="b1688005416165623"></a><a name="b1688005416165623"></a>1</strong> indicates that there is no START condition for the message transfer. </p>
 </td>
</tr>
<tr id="row549101543165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga32b58f021632085445d80c80e382a546a641c29990d13fe5f840b495dca8e21e9"><a name="gga32b58f021632085445d80c80e382a546a641c29990d13fe5f840b495dca8e21e9"></a><a name="gga32b58f021632085445d80c80e382a546a641c29990d13fe5f840b495dca8e21e9"></a></strong>I2C_FLAG_STOP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1688324362165623"><a name="p1688324362165623"></a><a name="p1688324362165623"></a>STOP condition flag. The value <strong id="b662762357165623"><a name="b662762357165623"></a><a name="b662762357165623"></a>1</strong> indicates that the current transfer ends with a STOP condition. </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section1683434957165623"></a>

## I2cClose\(\)<a name="ga3ca9d500e6fb6592a04f7dc33806c13e"></a>

```
void I2cClose ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Releases the handle of an I2C controller. 

If you no longer need to access the I2C controller, you should call this function to close its handle so as to release unused memory resources.

**Parameters:**

<a name="table437610247165623"></a>
<table><thead align="left"><tr id="row1627961132165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1210238016165623"><a name="p1210238016165623"></a><a name="p1210238016165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p290991333165623"><a name="p290991333165623"></a><a name="p290991333165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1087997652165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the I2C controller.</td>
</tr>
</tbody>
</table>

## I2cOpen\(\)<a name="ga564086bbb2121cd6771c66c886da11b5"></a>

```
[DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) I2cOpen (int16_t number)
```

 **Description:**

Obtains the handle of an I2C controller. 

You must call this function before accessing the I2C bus.

**Parameters:**

<a name="table474309123165623"></a>
<table><thead align="left"><tr id="row1675304177165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p36422137165623"><a name="p36422137165623"></a><a name="p36422137165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1126088108165623"><a name="p1126088108165623"></a><a name="p1126088108165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row425504951165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">number</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the I2C controller ID.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the  [DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041)  of the I2C controller if the operation is successful; returns  **NULL**  otherwise. 

## I2cTransfer\(\)<a name="ga2395dc94da99c2b990096c659fcefc72"></a>

```
int32_t I2cTransfer ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, struct [I2cMsg](I2cMsg.md) * msgs, int16_t count )
```

 **Description:**

Launches a custom transfer to an I2C device. 

**Parameters:**

<a name="table1483921284165623"></a>
<table><thead align="left"><tr id="row164515485165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1989170252165623"><a name="p1989170252165623"></a><a name="p1989170252165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1181206297165623"><a name="p1181206297165623"></a><a name="p1181206297165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1104906182165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the I2C controller obtained via <a href="I2C.md#ga564086bbb2121cd6771c66c886da11b5">I2cOpen</a>. </td>
</tr>
<tr id="row273915760165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">msgs</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the I2C transfer message structure array. </td>
</tr>
<tr id="row1387168362165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">count</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the message structure array.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of transferred message structures if the operation is successful; returns a negative value otherwise. 

**See also:**

[I2cMsg](I2cMsg.md) 

**Attention:**

This function does not limit the number of message structures specified by  **count**  or the data length of each message structure. The specific I2C controller determines the maximum number and data length allowed.

