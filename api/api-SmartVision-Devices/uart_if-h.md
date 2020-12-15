# uart\_if.h<a name="ZH-CN_TOPIC_0000001055039498"></a>

-   [Overview](#section1321589303165629)
-   [Summary](#section788592983165629)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section2141832930165629)
-   [Macro Definition](#section353483346165629)
-   [UART\_ATTR\_CTS\_DIS](#a326c98b1572b40a83a0e4635eb856e5e)
-   [UART\_ATTR\_CTS\_EN](#a097c9cebfaf73088fc9e8bea12bfe12f)
-   [UART\_ATTR\_DATABIT\_5](#af7add98615bfa0f6b9fa612aefcb1a86)
-   [UART\_ATTR\_DATABIT\_6](#a0170d90e903308157615a9d492522a45)
-   [UART\_ATTR\_DATABIT\_7](#a1a0f284bb3f73eb5f410a3b800f05c3d)
-   [UART\_ATTR\_DATABIT\_8](#af5e815055116901ca2031dfa07aab973)
-   [UART\_ATTR\_PARITY\_EVEN](#a9f3c0d0f62f5d9320567948fd4d92be2)
-   [UART\_ATTR\_PARITY\_MARK](#a22c4b8c1eb660d64564900a2088bd1ee)
-   [UART\_ATTR\_PARITY\_NONE](#a4babcc869fd207988d961ccca101abd2)
-   [UART\_ATTR\_PARITY\_ODD](#a5fee103697a67af905c21a2107141ceb)
-   [UART\_ATTR\_PARITY\_SPACE](#a1817d247706383e20fea3699a95a466a)
-   [UART\_ATTR\_RTS\_DIS](#a0266381d78b0452a252e195ff9515906)
-   [UART\_ATTR\_RTS\_EN](#a7cfdcad6fe75be1ccb06bed6d94da7e6)
-   [UART\_ATTR\_RX\_FIFO\_DIS](#acb395fb111f746ecf37ab86d255024a4)
-   [UART\_ATTR\_RX\_FIFO\_EN](#a1e1fcc1dbf4cfab102ea77fbae2b9bb5)
-   [UART\_ATTR\_STOPBIT\_1](#a985cd0b852a617f1265315030bc1cf8c)
-   [UART\_ATTR\_STOPBIT\_1P5](#a2ebde6313789cc5d787c274240f64deb)
-   [UART\_ATTR\_STOPBIT\_2](#a97875399f1914c0b66c5c6cea59afe38)
-   [UART\_ATTR\_TX\_FIFO\_DIS](#a220e22bdcc6c4bc4de7c9896a22b0ae2)
-   [UART\_ATTR\_TX\_FIFO\_EN](#aa434b054edcab341947c1c4dd71972eb)

## **Overview**<a name="section1321589303165629"></a>

**Related Modules:**

[UART](UART.md)

**Description:**

Declares standard UART APIs. 

**Since:**

1.0

## **Summary**<a name="section788592983165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1010565492165629"></a>
<table><thead align="left"><tr id="row409553314165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1362291594165629"><a name="p1362291594165629"></a><a name="p1362291594165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1241818975165629"><a name="p1241818975165629"></a><a name="p1241818975165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1840868081165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1836218430165629"><a name="p1836218430165629"></a><a name="p1836218430165629"></a><a href="UartAttribute.md">UartAttribute</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1183258240165629"><a name="p1183258240165629"></a><a name="p1183258240165629"></a>Defines basic attributes of the UART port. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table955151099165629"></a>
<table><thead align="left"><tr id="row2018414162165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2010612308165629"><a name="p2010612308165629"></a><a name="p2010612308165629"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p578664390165629"><a name="p578664390165629"></a><a name="p578664390165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1690822886165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1483525397165629"><a name="p1483525397165629"></a><a name="p1483525397165629"></a><a href="uart_if-h.md#af5e815055116901ca2031dfa07aab973">UART_ATTR_DATABIT_8</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p158269937165629"><a name="p158269937165629"></a><a name="p158269937165629"></a>Indicates the UART word length, which is 8 data bits per frame. </p>
</td>
</tr>
<tr id="row520102465165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p50708469165629"><a name="p50708469165629"></a><a name="p50708469165629"></a><a href="uart_if-h.md#a1a0f284bb3f73eb5f410a3b800f05c3d">UART_ATTR_DATABIT_7</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1771080894165629"><a name="p1771080894165629"></a><a name="p1771080894165629"></a>Indicates the UART word length, which is 7 data bits per frame. </p>
</td>
</tr>
<tr id="row772248462165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p610247715165629"><a name="p610247715165629"></a><a name="p610247715165629"></a><a href="uart_if-h.md#a0170d90e903308157615a9d492522a45">UART_ATTR_DATABIT_6</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1934612053165629"><a name="p1934612053165629"></a><a name="p1934612053165629"></a>Indicates the UART word length, which is 6 data bits per frame. </p>
</td>
</tr>
<tr id="row186431706165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1234404573165629"><a name="p1234404573165629"></a><a name="p1234404573165629"></a><a href="uart_if-h.md#af7add98615bfa0f6b9fa612aefcb1a86">UART_ATTR_DATABIT_5</a>   3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1098942971165629"><a name="p1098942971165629"></a><a name="p1098942971165629"></a>Indicates the UART word length, which is 5 data bits per frame. </p>
</td>
</tr>
<tr id="row1000683973165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1922614359165629"><a name="p1922614359165629"></a><a name="p1922614359165629"></a><a href="uart_if-h.md#a4babcc869fd207988d961ccca101abd2">UART_ATTR_PARITY_NONE</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1910731752165629"><a name="p1910731752165629"></a><a name="p1910731752165629"></a>Indicates that the UART device has no parity bit. </p>
</td>
</tr>
<tr id="row1789852838165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1352967651165629"><a name="p1352967651165629"></a><a name="p1352967651165629"></a><a href="uart_if-h.md#a5fee103697a67af905c21a2107141ceb">UART_ATTR_PARITY_ODD</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p788608147165629"><a name="p788608147165629"></a><a name="p788608147165629"></a>Indicates that the UART device has an odd parity bit. </p>
</td>
</tr>
<tr id="row549362606165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p813600556165629"><a name="p813600556165629"></a><a name="p813600556165629"></a><a href="uart_if-h.md#a9f3c0d0f62f5d9320567948fd4d92be2">UART_ATTR_PARITY_EVEN</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1900292398165629"><a name="p1900292398165629"></a><a name="p1900292398165629"></a>Indicates that the UART device has an even parity bit. </p>
</td>
</tr>
<tr id="row105281364165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1947658665165629"><a name="p1947658665165629"></a><a name="p1947658665165629"></a><a href="uart_if-h.md#a22c4b8c1eb660d64564900a2088bd1ee">UART_ATTR_PARITY_MARK</a>   3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2074956182165629"><a name="p2074956182165629"></a><a name="p2074956182165629"></a>Indicates that the parity bit is 1. </p>
</td>
</tr>
<tr id="row1181159762165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1581129968165629"><a name="p1581129968165629"></a><a name="p1581129968165629"></a><a href="uart_if-h.md#a1817d247706383e20fea3699a95a466a">UART_ATTR_PARITY_SPACE</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1982774497165629"><a name="p1982774497165629"></a><a name="p1982774497165629"></a>Indicates that the parity bit is 0. </p>
</td>
</tr>
<tr id="row582827935165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p831522924165629"><a name="p831522924165629"></a><a name="p831522924165629"></a><a href="uart_if-h.md#a985cd0b852a617f1265315030bc1cf8c">UART_ATTR_STOPBIT_1</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p454958615165629"><a name="p454958615165629"></a><a name="p454958615165629"></a>Indicates that the UART device has 1 stop bit. </p>
</td>
</tr>
<tr id="row2070775186165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p602808095165629"><a name="p602808095165629"></a><a name="p602808095165629"></a><a href="uart_if-h.md#a2ebde6313789cc5d787c274240f64deb">UART_ATTR_STOPBIT_1P5</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1421088283165629"><a name="p1421088283165629"></a><a name="p1421088283165629"></a>Indicates that the UART device has 1.5 stop bits. </p>
</td>
</tr>
<tr id="row544108073165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p159075830165629"><a name="p159075830165629"></a><a name="p159075830165629"></a><a href="uart_if-h.md#a97875399f1914c0b66c5c6cea59afe38">UART_ATTR_STOPBIT_2</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p573719286165629"><a name="p573719286165629"></a><a name="p573719286165629"></a>Indicates that the UART device has 2 stop bits. </p>
</td>
</tr>
<tr id="row1966710060165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p369590734165629"><a name="p369590734165629"></a><a name="p369590734165629"></a><a href="uart_if-h.md#a0266381d78b0452a252e195ff9515906">UART_ATTR_RTS_DIS</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1617219015165629"><a name="p1617219015165629"></a><a name="p1617219015165629"></a>Indicates that <a href="Request.md">Request</a> To Send (RTS) is disabled for the UART device. </p>
</td>
</tr>
<tr id="row904044165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1992551813165629"><a name="p1992551813165629"></a><a name="p1992551813165629"></a><a href="uart_if-h.md#a7cfdcad6fe75be1ccb06bed6d94da7e6">UART_ATTR_RTS_EN</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p266910709165629"><a name="p266910709165629"></a><a name="p266910709165629"></a>Indicates that RTS is enabled for the UART device. </p>
</td>
</tr>
<tr id="row1194867242165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1470909008165629"><a name="p1470909008165629"></a><a name="p1470909008165629"></a><a href="uart_if-h.md#a326c98b1572b40a83a0e4635eb856e5e">UART_ATTR_CTS_DIS</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p705928479165629"><a name="p705928479165629"></a><a name="p705928479165629"></a>Indicates that Clear To Send (CTS) is disabled for the UART device. </p>
</td>
</tr>
<tr id="row1101469877165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1405869157165629"><a name="p1405869157165629"></a><a name="p1405869157165629"></a><a href="uart_if-h.md#a097c9cebfaf73088fc9e8bea12bfe12f">UART_ATTR_CTS_EN</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1314713455165629"><a name="p1314713455165629"></a><a name="p1314713455165629"></a>Indicates that CTS is enabled for the UART device. </p>
</td>
</tr>
<tr id="row1066979610165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1249486082165629"><a name="p1249486082165629"></a><a name="p1249486082165629"></a><a href="uart_if-h.md#acb395fb111f746ecf37ab86d255024a4">UART_ATTR_RX_FIFO_DIS</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1911850415165629"><a name="p1911850415165629"></a><a name="p1911850415165629"></a>Indicates that First In First Out (FIFO) is disabled for the receiving UART. </p>
</td>
</tr>
<tr id="row718499973165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p33094009165629"><a name="p33094009165629"></a><a name="p33094009165629"></a><a href="uart_if-h.md#a1e1fcc1dbf4cfab102ea77fbae2b9bb5">UART_ATTR_RX_FIFO_EN</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1917455022165629"><a name="p1917455022165629"></a><a name="p1917455022165629"></a>Indicates that FIFO is enabled for the receiving UART. </p>
</td>
</tr>
<tr id="row1569810463165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p81295990165629"><a name="p81295990165629"></a><a name="p81295990165629"></a><a href="uart_if-h.md#a220e22bdcc6c4bc4de7c9896a22b0ae2">UART_ATTR_TX_FIFO_DIS</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1079263179165629"><a name="p1079263179165629"></a><a name="p1079263179165629"></a>Indicates that FIFO is disabled for the transmitting UART. </p>
</td>
</tr>
<tr id="row1220886520165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1611979518165629"><a name="p1611979518165629"></a><a name="p1611979518165629"></a><a href="uart_if-h.md#aa434b054edcab341947c1c4dd71972eb">UART_ATTR_TX_FIFO_EN</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1627058866165629"><a name="p1627058866165629"></a><a name="p1627058866165629"></a>Indicates that FIFO is enabled for the transmitting UART. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1836444239165629"></a>
<table><thead align="left"><tr id="row1374446970165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1366552234165629"><a name="p1366552234165629"></a><a name="p1366552234165629"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p178279605165629"><a name="p178279605165629"></a><a name="p178279605165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1572756686165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1454892598165629"><a name="p1454892598165629"></a><a name="p1454892598165629"></a><a href="UART.md#gab9e041a0802a7e24da22215b458bf7db">UartTransMode</a> {   <a href="UART.md#ggab9e041a0802a7e24da22215b458bf7dba969508add5bf29906cb8ed29cc724c12">UART_MODE_RD_BLOCK</a> = 0, <a href="UART.md#ggab9e041a0802a7e24da22215b458bf7dbad3855fe94d0ff6f630d552eed8b9acb1">UART_MODE_RD_NONBLOCK</a>, <a href="UART.md#ggab9e041a0802a7e24da22215b458bf7dba9aaa55c3b790ae8955a015a8f68c2cde">UART_MODE_DMA_RX_EN</a>, <a href="UART.md#ggab9e041a0802a7e24da22215b458bf7dbab33780e5d6e4607bae091771146e70ac">UART_MODE_DMA_RX_DIS</a>,   <a href="UART.md#ggab9e041a0802a7e24da22215b458bf7dbadecd4cef66348d7e9a5c6d1ad122d98a">UART_MODE_DMA_TX_EN</a>, <a href="UART.md#ggab9e041a0802a7e24da22215b458bf7dbab4aee82f37b579d2506c1c1cd36d7a65">UART_MODE_DMA_TX_DIS</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p97261025165629"><a name="p97261025165629"></a><a name="p97261025165629"></a>Enumerates UART transmission modes. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table680895279165629"></a>
<table><thead align="left"><tr id="row358285322165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p857509701165629"><a name="p857509701165629"></a><a name="p857509701165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p729924044165629"><a name="p729924044165629"></a><a name="p729924044165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row22842420165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1485883719165629"><a name="p1485883719165629"></a><a name="p1485883719165629"></a><a href="UART.md#ga58c38269b20875dbbf924379edeec286">UartOpen</a> (uint32_t port)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p668679962165629"><a name="p668679962165629"></a><a name="p668679962165629"></a><a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> </p>
<p id="p1284741419165629"><a name="p1284741419165629"></a><a name="p1284741419165629"></a>Obtains the UART device handle. </p>
</td>
</tr>
<tr id="row1870627607165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2145855763165629"><a name="p2145855763165629"></a><a name="p2145855763165629"></a><a href="UART.md#ga4702e7771c5088a9acf350a4cc6d3cdc">UartClose</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p946661743165629"><a name="p946661743165629"></a><a name="p946661743165629"></a>void </p>
<p id="p1586737513165629"><a name="p1586737513165629"></a><a name="p1586737513165629"></a>Releases the UART device handle. </p>
</td>
</tr>
<tr id="row305929830165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1452439544165629"><a name="p1452439544165629"></a><a name="p1452439544165629"></a><a href="UART.md#gafd054e271c663816db676dedce506cf1">UartRead</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1282339786165629"><a name="p1282339786165629"></a><a name="p1282339786165629"></a>int32_t </p>
<p id="p808130068165629"><a name="p808130068165629"></a><a name="p808130068165629"></a>Reads data of a specified size from a UART device. </p>
</td>
</tr>
<tr id="row117763562165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p829788819165629"><a name="p829788819165629"></a><a name="p829788819165629"></a><a href="UART.md#ga47eb7fa4bdedf14b494c89da50b0628b">UartWrite</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p635406200165629"><a name="p635406200165629"></a><a name="p635406200165629"></a>int32_t </p>
<p id="p2038618182165629"><a name="p2038618182165629"></a><a name="p2038618182165629"></a>Writes data of a specified size into a UART device. </p>
</td>
</tr>
<tr id="row1770519412165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p434872527165629"><a name="p434872527165629"></a><a name="p434872527165629"></a><a href="UART.md#ga3abaa2855a7ffd0bd277e0524d4a9f6e">UartGetBaud</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint32_t *baudRate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p880552110165629"><a name="p880552110165629"></a><a name="p880552110165629"></a>int32_t </p>
<p id="p1896092795165629"><a name="p1896092795165629"></a><a name="p1896092795165629"></a>Obtains the baud rate of the UART device. </p>
</td>
</tr>
<tr id="row992870150165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1836130854165629"><a name="p1836130854165629"></a><a name="p1836130854165629"></a><a href="UART.md#ga1e7084df70420be7f8ef77d32da875d5">UartSetBaud</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint32_t baudRate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p582225090165629"><a name="p582225090165629"></a><a name="p582225090165629"></a>int32_t </p>
<p id="p1476457515165629"><a name="p1476457515165629"></a><a name="p1476457515165629"></a>Sets the baud rate for the UART device. </p>
</td>
</tr>
<tr id="row1212796799165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p156383423165629"><a name="p156383423165629"></a><a name="p156383423165629"></a><a href="UART.md#gaff87cbe71e33c3cddfe41ccfbc422335">UartGetAttribute</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, struct <a href="UartAttribute.md">UartAttribute</a> *attribute)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p528202574165629"><a name="p528202574165629"></a><a name="p528202574165629"></a>int32_t </p>
<p id="p317029624165629"><a name="p317029624165629"></a><a name="p317029624165629"></a>Obtains the UART attribute. </p>
</td>
</tr>
<tr id="row1882863347165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p580959732165629"><a name="p580959732165629"></a><a name="p580959732165629"></a><a href="UART.md#ga76281a15464395451fc9844e717e0e10">UartSetAttribute</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, struct <a href="UartAttribute.md">UartAttribute</a> *attribute)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p118016606165629"><a name="p118016606165629"></a><a name="p118016606165629"></a>int32_t </p>
<p id="p1863704977165629"><a name="p1863704977165629"></a><a name="p1863704977165629"></a>Sets the UART attribute. </p>
</td>
</tr>
<tr id="row304409550165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1900843371165629"><a name="p1900843371165629"></a><a name="p1900843371165629"></a><a href="UART.md#ga99100dbfded04627fab8387abcbfd9a8">UartSetTransMode</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, enum <a href="UART.md#gab9e041a0802a7e24da22215b458bf7db">UartTransMode</a> mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p271817091165629"><a name="p271817091165629"></a><a name="p271817091165629"></a>int32_t </p>
<p id="p888928711165629"><a name="p888928711165629"></a><a name="p888928711165629"></a>Sets the UART transmission mode. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2141832930165629"></a>

## **Macro Definition **<a name="section353483346165629"></a>

## UART\_ATTR\_CTS\_DIS<a name="a326c98b1572b40a83a0e4635eb856e5e"></a>

```
#define UART_ATTR_CTS_DIS   0
```

 **Description:**

Indicates that Clear To Send \(CTS\) is disabled for the UART device. 

## UART\_ATTR\_CTS\_EN<a name="a097c9cebfaf73088fc9e8bea12bfe12f"></a>

```
#define UART_ATTR_CTS_EN   1
```

 **Description:**

Indicates that CTS is enabled for the UART device. 

## UART\_ATTR\_DATABIT\_5<a name="af7add98615bfa0f6b9fa612aefcb1a86"></a>

```
#define UART_ATTR_DATABIT_5   3
```

 **Description:**

Indicates the UART word length, which is 5 data bits per frame. 

## UART\_ATTR\_DATABIT\_6<a name="a0170d90e903308157615a9d492522a45"></a>

```
#define UART_ATTR_DATABIT_6   2
```

 **Description:**

Indicates the UART word length, which is 6 data bits per frame. 

## UART\_ATTR\_DATABIT\_7<a name="a1a0f284bb3f73eb5f410a3b800f05c3d"></a>

```
#define UART_ATTR_DATABIT_7   1
```

 **Description:**

Indicates the UART word length, which is 7 data bits per frame. 

## UART\_ATTR\_DATABIT\_8<a name="af5e815055116901ca2031dfa07aab973"></a>

```
#define UART_ATTR_DATABIT_8   0
```

 **Description:**

Indicates the UART word length, which is 8 data bits per frame. 

## UART\_ATTR\_PARITY\_EVEN<a name="a9f3c0d0f62f5d9320567948fd4d92be2"></a>

```
#define UART_ATTR_PARITY_EVEN   2
```

 **Description:**

Indicates that the UART device has an even parity bit. 

## UART\_ATTR\_PARITY\_MARK<a name="a22c4b8c1eb660d64564900a2088bd1ee"></a>

```
#define UART_ATTR_PARITY_MARK   3
```

 **Description:**

Indicates that the parity bit is 1. 

## UART\_ATTR\_PARITY\_NONE<a name="a4babcc869fd207988d961ccca101abd2"></a>

```
#define UART_ATTR_PARITY_NONE   0
```

 **Description:**

Indicates that the UART device has no parity bit. 

## UART\_ATTR\_PARITY\_ODD<a name="a5fee103697a67af905c21a2107141ceb"></a>

```
#define UART_ATTR_PARITY_ODD   1
```

 **Description:**

Indicates that the UART device has an odd parity bit. 

## UART\_ATTR\_PARITY\_SPACE<a name="a1817d247706383e20fea3699a95a466a"></a>

```
#define UART_ATTR_PARITY_SPACE   4
```

 **Description:**

Indicates that the parity bit is 0. 

## UART\_ATTR\_RTS\_DIS<a name="a0266381d78b0452a252e195ff9515906"></a>

```
#define UART_ATTR_RTS_DIS   0
```

 **Description:**

Indicates that  [Request](Request.md)  To Send \(RTS\) is disabled for the UART device. 

## UART\_ATTR\_RTS\_EN<a name="a7cfdcad6fe75be1ccb06bed6d94da7e6"></a>

```
#define UART_ATTR_RTS_EN   1
```

 **Description:**

Indicates that RTS is enabled for the UART device. 

## UART\_ATTR\_RX\_FIFO\_DIS<a name="acb395fb111f746ecf37ab86d255024a4"></a>

```
#define UART_ATTR_RX_FIFO_DIS   0
```

 **Description:**

Indicates that First In First Out \(FIFO\) is disabled for the receiving UART. 

## UART\_ATTR\_RX\_FIFO\_EN<a name="a1e1fcc1dbf4cfab102ea77fbae2b9bb5"></a>

```
#define UART_ATTR_RX_FIFO_EN   1
```

 **Description:**

Indicates that FIFO is enabled for the receiving UART. 

## UART\_ATTR\_STOPBIT\_1<a name="a985cd0b852a617f1265315030bc1cf8c"></a>

```
#define UART_ATTR_STOPBIT_1   0
```

 **Description:**

Indicates that the UART device has 1 stop bit. 

## UART\_ATTR\_STOPBIT\_1P5<a name="a2ebde6313789cc5d787c274240f64deb"></a>

```
#define UART_ATTR_STOPBIT_1P5   1
```

 **Description:**

Indicates that the UART device has 1.5 stop bits. 

## UART\_ATTR\_STOPBIT\_2<a name="a97875399f1914c0b66c5c6cea59afe38"></a>

```
#define UART_ATTR_STOPBIT_2   2
```

 **Description:**

Indicates that the UART device has 2 stop bits. 

## UART\_ATTR\_TX\_FIFO\_DIS<a name="a220e22bdcc6c4bc4de7c9896a22b0ae2"></a>

```
#define UART_ATTR_TX_FIFO_DIS   0
```

 **Description:**

Indicates that FIFO is disabled for the transmitting UART. 

## UART\_ATTR\_TX\_FIFO\_EN<a name="aa434b054edcab341947c1c4dd71972eb"></a>

```
#define UART_ATTR_TX_FIFO_EN   1
```

 **Description:**

Indicates that FIFO is enabled for the transmitting UART. 

