# UART<a name="ZH-CN_TOPIC_0000001054799549"></a>

-   [Overview](#section1891658640165623)
-   [Summary](#section34751695165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section541110488165623)
-   [Enumeration Type](#section1991208749165623)
-   [UartTransMode](#gab9e041a0802a7e24da22215b458bf7db)
-   [Function](#section372043577165623)
-   [UartClose\(\)](#ga4702e7771c5088a9acf350a4cc6d3cdc)
-   [UartGetAttribute\(\)](#gaff87cbe71e33c3cddfe41ccfbc422335)
-   [UartGetBaud\(\)](#ga3abaa2855a7ffd0bd277e0524d4a9f6e)
-   [UartOpen\(\)](#ga58c38269b20875dbbf924379edeec286)
-   [UartRead\(\)](#gafd054e271c663816db676dedce506cf1)
-   [UartSetAttribute\(\)](#ga76281a15464395451fc9844e717e0e10)
-   [UartSetBaud\(\)](#ga1e7084df70420be7f8ef77d32da875d5)
-   [UartSetTransMode\(\)](#ga99100dbfded04627fab8387abcbfd9a8)
-   [UartWrite\(\)](#ga47eb7fa4bdedf14b494c89da50b0628b)

## **Overview**<a name="section1891658640165623"></a>

**Description:**

Defines standard APIs of universal asynchronous receiver/transmitter \(UART\) capabilities. 

You can use this module to access the UART and enable the driver to operate a UART-compliant device. The functions in this module help you to obtain and release the UART device handle, read and write data, obtain and set the baud rate and device attributes.

**Since:**

1.0

## **Summary**<a name="section34751695165623"></a>

## Files<a name="files"></a>

<a name="table1388316070165623"></a>
<table><thead align="left"><tr id="row347914332165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p744209487165623"><a name="p744209487165623"></a><a name="p744209487165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p706787586165623"><a name="p706787586165623"></a><a name="p706787586165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1300080961165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2143396470165623"><a name="p2143396470165623"></a><a name="p2143396470165623"></a><a href="uart_if-h.md">uart_if.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1650994859165623"><a name="p1650994859165623"></a><a name="p1650994859165623"></a>Declares standard UART APIs. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1974517127165623"></a>
<table><thead align="left"><tr id="row893520768165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2121013263165623"><a name="p2121013263165623"></a><a name="p2121013263165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p45847797165623"><a name="p45847797165623"></a><a name="p45847797165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1634368325165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1773223849165623"><a name="p1773223849165623"></a><a name="p1773223849165623"></a><a href="UartAttribute.md">UartAttribute</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1355999204165623"><a name="p1355999204165623"></a><a name="p1355999204165623"></a>Defines basic attributes of the UART port. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1189144656165623"></a>
<table><thead align="left"><tr id="row560065303165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1565509390165623"><a name="p1565509390165623"></a><a name="p1565509390165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1096501567165623"><a name="p1096501567165623"></a><a name="p1096501567165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1997520569165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1922721026165623"><a name="p1922721026165623"></a><a name="p1922721026165623"></a><a href="UART.md#gab9e041a0802a7e24da22215b458bf7db">UartTransMode</a> {   <a href="UART.md#ggab9e041a0802a7e24da22215b458bf7dba969508add5bf29906cb8ed29cc724c12">UART_MODE_RD_BLOCK</a> = 0, <a href="UART.md#ggab9e041a0802a7e24da22215b458bf7dbad3855fe94d0ff6f630d552eed8b9acb1">UART_MODE_RD_NONBLOCK</a>, <a href="UART.md#ggab9e041a0802a7e24da22215b458bf7dba9aaa55c3b790ae8955a015a8f68c2cde">UART_MODE_DMA_RX_EN</a>, <a href="UART.md#ggab9e041a0802a7e24da22215b458bf7dbab33780e5d6e4607bae091771146e70ac">UART_MODE_DMA_RX_DIS</a>,   <a href="UART.md#ggab9e041a0802a7e24da22215b458bf7dbadecd4cef66348d7e9a5c6d1ad122d98a">UART_MODE_DMA_TX_EN</a>, <a href="UART.md#ggab9e041a0802a7e24da22215b458bf7dbab4aee82f37b579d2506c1c1cd36d7a65">UART_MODE_DMA_TX_DIS</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p214233096165623"><a name="p214233096165623"></a><a name="p214233096165623"></a>Enumerates UART transmission modes. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1791549900165623"></a>
<table><thead align="left"><tr id="row713008232165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p7105759165623"><a name="p7105759165623"></a><a name="p7105759165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p482356666165623"><a name="p482356666165623"></a><a name="p482356666165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1970589080165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1515998456165623"><a name="p1515998456165623"></a><a name="p1515998456165623"></a><a href="UART.md#ga58c38269b20875dbbf924379edeec286">UartOpen</a> (uint32_t port)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1015307300165623"><a name="p1015307300165623"></a><a name="p1015307300165623"></a><a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> </p>
<p id="p1736293281165623"><a name="p1736293281165623"></a><a name="p1736293281165623"></a>Obtains the UART device handle. </p>
</td>
</tr>
<tr id="row2096796976165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p989102618165623"><a name="p989102618165623"></a><a name="p989102618165623"></a><a href="UART.md#ga4702e7771c5088a9acf350a4cc6d3cdc">UartClose</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1516075312165623"><a name="p1516075312165623"></a><a name="p1516075312165623"></a>void </p>
<p id="p1423944405165623"><a name="p1423944405165623"></a><a name="p1423944405165623"></a>Releases the UART device handle. </p>
</td>
</tr>
<tr id="row856769974165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1609978087165623"><a name="p1609978087165623"></a><a name="p1609978087165623"></a><a href="UART.md#gafd054e271c663816db676dedce506cf1">UartRead</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1920735130165623"><a name="p1920735130165623"></a><a name="p1920735130165623"></a>int32_t </p>
<p id="p1499790612165623"><a name="p1499790612165623"></a><a name="p1499790612165623"></a>Reads data of a specified size from a UART device. </p>
</td>
</tr>
<tr id="row270841485165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2096310337165623"><a name="p2096310337165623"></a><a name="p2096310337165623"></a><a href="UART.md#ga47eb7fa4bdedf14b494c89da50b0628b">UartWrite</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1223144888165623"><a name="p1223144888165623"></a><a name="p1223144888165623"></a>int32_t </p>
<p id="p2035482927165623"><a name="p2035482927165623"></a><a name="p2035482927165623"></a>Writes data of a specified size into a UART device. </p>
</td>
</tr>
<tr id="row1991748368165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1786949416165623"><a name="p1786949416165623"></a><a name="p1786949416165623"></a><a href="UART.md#ga3abaa2855a7ffd0bd277e0524d4a9f6e">UartGetBaud</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint32_t *baudRate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1816599416165623"><a name="p1816599416165623"></a><a name="p1816599416165623"></a>int32_t </p>
<p id="p463698513165623"><a name="p463698513165623"></a><a name="p463698513165623"></a>Obtains the baud rate of the UART device. </p>
</td>
</tr>
<tr id="row748703947165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1657387693165623"><a name="p1657387693165623"></a><a name="p1657387693165623"></a><a href="UART.md#ga1e7084df70420be7f8ef77d32da875d5">UartSetBaud</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint32_t baudRate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p641576909165623"><a name="p641576909165623"></a><a name="p641576909165623"></a>int32_t </p>
<p id="p2027744123165623"><a name="p2027744123165623"></a><a name="p2027744123165623"></a>Sets the baud rate for the UART device. </p>
</td>
</tr>
<tr id="row674910462165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p534157947165623"><a name="p534157947165623"></a><a name="p534157947165623"></a><a href="UART.md#gaff87cbe71e33c3cddfe41ccfbc422335">UartGetAttribute</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, struct <a href="UartAttribute.md">UartAttribute</a> *attribute)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2045696066165623"><a name="p2045696066165623"></a><a name="p2045696066165623"></a>int32_t </p>
<p id="p734452123165623"><a name="p734452123165623"></a><a name="p734452123165623"></a>Obtains the UART attribute. </p>
</td>
</tr>
<tr id="row1830814794165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1285860208165623"><a name="p1285860208165623"></a><a name="p1285860208165623"></a><a href="UART.md#ga76281a15464395451fc9844e717e0e10">UartSetAttribute</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, struct <a href="UartAttribute.md">UartAttribute</a> *attribute)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p133322501165623"><a name="p133322501165623"></a><a name="p133322501165623"></a>int32_t </p>
<p id="p446061656165623"><a name="p446061656165623"></a><a name="p446061656165623"></a>Sets the UART attribute. </p>
</td>
</tr>
<tr id="row1445642324165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p400724779165623"><a name="p400724779165623"></a><a name="p400724779165623"></a><a href="UART.md#ga99100dbfded04627fab8387abcbfd9a8">UartSetTransMode</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, enum <a href="UART.md#gab9e041a0802a7e24da22215b458bf7db">UartTransMode</a> mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p501029554165623"><a name="p501029554165623"></a><a name="p501029554165623"></a>int32_t </p>
<p id="p594813157165623"><a name="p594813157165623"></a><a name="p594813157165623"></a>Sets the UART transmission mode. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section541110488165623"></a>

## **Enumeration Type **<a name="section1991208749165623"></a>

## UartTransMode<a name="gab9e041a0802a7e24da22215b458bf7db"></a>

```
enum [UartTransMode](UART.md#gab9e041a0802a7e24da22215b458bf7db)
```

 **Description:**

Enumerates UART transmission modes. 

**Attention:**

The UART controller determines whether an enumerated transmission mode is supported.

<a name="table960514303165623"></a>
<table><thead align="left"><tr id="row406467026165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p12286067165623"><a name="p12286067165623"></a><a name="p12286067165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1257284314165623"><a name="p1257284314165623"></a><a name="p1257284314165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row820777626165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab9e041a0802a7e24da22215b458bf7dba969508add5bf29906cb8ed29cc724c12"><a name="ggab9e041a0802a7e24da22215b458bf7dba969508add5bf29906cb8ed29cc724c12"></a><a name="ggab9e041a0802a7e24da22215b458bf7dba969508add5bf29906cb8ed29cc724c12"></a></strong>UART_MODE_RD_BLOCK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p527994519165623"><a name="p527994519165623"></a><a name="p527994519165623"></a>Blocking mode </p>
 </td>
</tr>
<tr id="row1337077203165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab9e041a0802a7e24da22215b458bf7dbad3855fe94d0ff6f630d552eed8b9acb1"><a name="ggab9e041a0802a7e24da22215b458bf7dbad3855fe94d0ff6f630d552eed8b9acb1"></a><a name="ggab9e041a0802a7e24da22215b458bf7dbad3855fe94d0ff6f630d552eed8b9acb1"></a></strong>UART_MODE_RD_NONBLOCK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1261556061165623"><a name="p1261556061165623"></a><a name="p1261556061165623"></a>Non-blocking mode </p>
 </td>
</tr>
<tr id="row1120607902165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab9e041a0802a7e24da22215b458bf7dba9aaa55c3b790ae8955a015a8f68c2cde"><a name="ggab9e041a0802a7e24da22215b458bf7dba9aaa55c3b790ae8955a015a8f68c2cde"></a><a name="ggab9e041a0802a7e24da22215b458bf7dba9aaa55c3b790ae8955a015a8f68c2cde"></a></strong>UART_MODE_DMA_RX_EN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1612026986165623"><a name="p1612026986165623"></a><a name="p1612026986165623"></a>DMA enabled for data receiving </p>
 </td>
</tr>
<tr id="row1293147961165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab9e041a0802a7e24da22215b458bf7dbab33780e5d6e4607bae091771146e70ac"><a name="ggab9e041a0802a7e24da22215b458bf7dbab33780e5d6e4607bae091771146e70ac"></a><a name="ggab9e041a0802a7e24da22215b458bf7dbab33780e5d6e4607bae091771146e70ac"></a></strong>UART_MODE_DMA_RX_DIS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p698104518165623"><a name="p698104518165623"></a><a name="p698104518165623"></a>DMA disabled for data receiving </p>
 </td>
</tr>
<tr id="row1712181713165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab9e041a0802a7e24da22215b458bf7dbadecd4cef66348d7e9a5c6d1ad122d98a"><a name="ggab9e041a0802a7e24da22215b458bf7dbadecd4cef66348d7e9a5c6d1ad122d98a"></a><a name="ggab9e041a0802a7e24da22215b458bf7dbadecd4cef66348d7e9a5c6d1ad122d98a"></a></strong>UART_MODE_DMA_TX_EN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1553928378165623"><a name="p1553928378165623"></a><a name="p1553928378165623"></a>DMA enabled for data transmitting </p>
 </td>
</tr>
<tr id="row1640744269165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggab9e041a0802a7e24da22215b458bf7dbab4aee82f37b579d2506c1c1cd36d7a65"><a name="ggab9e041a0802a7e24da22215b458bf7dbab4aee82f37b579d2506c1c1cd36d7a65"></a><a name="ggab9e041a0802a7e24da22215b458bf7dbab4aee82f37b579d2506c1c1cd36d7a65"></a></strong>UART_MODE_DMA_TX_DIS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p366940204165623"><a name="p366940204165623"></a><a name="p366940204165623"></a>DMA disabled for data transmitting </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section372043577165623"></a>

## UartClose\(\)<a name="ga4702e7771c5088a9acf350a4cc6d3cdc"></a>

```
void UartClose ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Releases the UART device handle. 

If you no longer need to access the UART device, you should call this function to close its handle so as to release unused memory resources.

**Parameters:**

<a name="table1806006560165623"></a>
<table><thead align="left"><tr id="row691346798165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1239147692165623"><a name="p1239147692165623"></a><a name="p1239147692165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1552944982165623"><a name="p1552944982165623"></a><a name="p1552944982165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row907632445165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the UART device handle, which is obtained via <a href="UART.md#ga58c38269b20875dbbf924379edeec286">UartOpen</a>.</td>
</tr>
</tbody>
</table>

## UartGetAttribute\(\)<a name="gaff87cbe71e33c3cddfe41ccfbc422335"></a>

```
int32_t UartGetAttribute ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, struct [UartAttribute](UartAttribute.md) * attribute )
```

 **Description:**

Obtains the UART attribute. 

UART attributes include data bits, stop bits, parity bit, CTS, RTS, and receiving and transmitting FIFO.

**Parameters:**

<a name="table225192817165623"></a>
<table><thead align="left"><tr id="row539657564165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p935189621165623"><a name="p935189621165623"></a><a name="p935189621165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1219701255165623"><a name="p1219701255165623"></a><a name="p1219701255165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1190689631165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the UART device handle, which is obtained via <a href="UART.md#ga58c38269b20875dbbf924379edeec286">UartOpen</a>. </td>
</tr>
<tr id="row1191476420165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attribute</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained UART attribute.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the UART attribute is obtained; returns a negative number otherwise. 

## UartGetBaud\(\)<a name="ga3abaa2855a7ffd0bd277e0524d4a9f6e"></a>

```
int32_t UartGetBaud ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint32_t * baudRate )
```

 **Description:**

Obtains the baud rate of the UART device. 

**Parameters:**

<a name="table2127230019165623"></a>
<table><thead align="left"><tr id="row491411362165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1558414774165623"><a name="p1558414774165623"></a><a name="p1558414774165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1394317839165623"><a name="p1394317839165623"></a><a name="p1394317839165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row430239068165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the UART device handle, which is obtained via <a href="UART.md#ga58c38269b20875dbbf924379edeec286">UartOpen</a>. </td>
</tr>
<tr id="row518006774165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">baudRate</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained baud rate.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the baud rate is obtained; returns a negative number otherwise. 

## UartOpen\(\)<a name="ga58c38269b20875dbbf924379edeec286"></a>

```
[DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) UartOpen (uint32_t port)
```

 **Description:**

Obtains the UART device handle. 

Before accessing the UART device, you must call this function to obtain the UART device handle.

**Parameters:**

<a name="table1158469928165623"></a>
<table><thead align="left"><tr id="row1044703494165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p739655308165623"><a name="p739655308165623"></a><a name="p739655308165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p940250852165623"><a name="p940250852165623"></a><a name="p940250852165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row309764564165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">port</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the UART port.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the UART device handle if the handle is obtained; returns  **NULL**  otherwise. 

## UartRead\(\)<a name="gafd054e271c663816db676dedce506cf1"></a>

```
int32_t UartRead ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint8_t * data, uint32_t size )
```

 **Description:**

Reads data of a specified size from a UART device. 

**Parameters:**

<a name="table2087604147165623"></a>
<table><thead align="left"><tr id="row758815857165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1364684796165623"><a name="p1364684796165623"></a><a name="p1364684796165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p363132653165623"><a name="p363132653165623"></a><a name="p363132653165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14382439165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the UART device handle, which is obtained via <a href="UART.md#ga58c38269b20875dbbf924379edeec286">UartOpen</a>. </td>
</tr>
<tr id="row586850916165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer for receiving the data. </td>
</tr>
<tr id="row514823677165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the data to read.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the size of the data that is successfully read; returns a negative number if the reading fails. 

## UartSetAttribute\(\)<a name="ga76281a15464395451fc9844e717e0e10"></a>

```
int32_t UartSetAttribute ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, struct [UartAttribute](UartAttribute.md) * attribute )
```

 **Description:**

Sets the UART attribute. 

UART attributes include data bits, stop bits, parity bit, CTS, RTS, and receiving and transmitting FIFO.

**Parameters:**

<a name="table1027054996165623"></a>
<table><thead align="left"><tr id="row689470267165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2119890785165623"><a name="p2119890785165623"></a><a name="p2119890785165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1321453804165623"><a name="p1321453804165623"></a><a name="p1321453804165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1456813613165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the UART device handle, which is obtained via <a href="UART.md#ga58c38269b20875dbbf924379edeec286">UartOpen</a>. </td>
</tr>
<tr id="row365707131165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attribute</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the UART attribute to set.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns a negative number otherwise. 

## UartSetBaud\(\)<a name="ga1e7084df70420be7f8ef77d32da875d5"></a>

```
int32_t UartSetBaud ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint32_t baudRate )
```

 **Description:**

Sets the baud rate for the UART device. 

**Parameters:**

<a name="table643331824165623"></a>
<table><thead align="left"><tr id="row1792641778165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1665548526165623"><a name="p1665548526165623"></a><a name="p1665548526165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p338563655165623"><a name="p338563655165623"></a><a name="p338563655165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row668926710165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the UART device handle, which is obtained via <a href="UART.md#ga58c38269b20875dbbf924379edeec286">UartOpen</a>. </td>
</tr>
<tr id="row972582081165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">baudRate</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the baud rate to set.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns a negative number otherwise. 

## UartSetTransMode\(\)<a name="ga99100dbfded04627fab8387abcbfd9a8"></a>

```
int32_t UartSetTransMode ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, enum [UartTransMode](UART.md#gab9e041a0802a7e24da22215b458bf7db) mode )
```

 **Description:**

Sets the UART transmission mode. 

**Parameters:**

<a name="table1945860074165623"></a>
<table><thead align="left"><tr id="row44145871165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p852919027165623"><a name="p852919027165623"></a><a name="p852919027165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1284230878165623"><a name="p1284230878165623"></a><a name="p1284230878165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row164619967165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the UART device handle, which is obtained via <a href="UART.md#ga58c38269b20875dbbf924379edeec286">UartOpen</a>. </td>
</tr>
<tr id="row507148287165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a transmission mode enumerated in {@linkUartTransMode}.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns a negative number otherwise. 

## UartWrite\(\)<a name="ga47eb7fa4bdedf14b494c89da50b0628b"></a>

```
int32_t UartWrite ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint8_t * data, uint32_t size )
```

 **Description:**

Writes data of a specified size into a UART device. 

**Parameters:**

<a name="table2099346495165623"></a>
<table><thead align="left"><tr id="row305961635165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1857565814165623"><a name="p1857565814165623"></a><a name="p1857565814165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p884607298165623"><a name="p884607298165623"></a><a name="p884607298165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row370558470165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the UART device handle, which is obtained via <a href="UART.md#ga58c38269b20875dbbf924379edeec286">UartOpen</a>. </td>
</tr>
<tr id="row863372135165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to write. </td>
</tr>
<tr id="row1765735939165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the data to write.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the data is successfully written; returns a negative number otherwise. 

