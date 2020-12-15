# spi\_if.h<a name="ZH-CN_TOPIC_0000001054718105"></a>

-   [Overview](#section1643949175165628)
-   [Summary](#section347787277165628)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section1643949175165628"></a>

**Related Modules:**

[SPI](SPI.md)

**Description:**

Defines standard SPI-specific interfaces for driver development. 

A driver needs to use the SPI-specific interfaces for data writing and reading before performing any operations on an SPI-compliant device.

**Since:**

1.0

## **Summary**<a name="section347787277165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table523263550165628"></a>
<table><thead align="left"><tr id="row681406299165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p229533901165628"><a name="p229533901165628"></a><a name="p229533901165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p937420906165628"><a name="p937420906165628"></a><a name="p937420906165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row684096604165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1642617918165628"><a name="p1642617918165628"></a><a name="p1642617918165628"></a><a href="SpiDevInfo.md">SpiDevInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p412481405165628"><a name="p412481405165628"></a><a name="p412481405165628"></a>Defines the general SPI device descriptor, which can be used as the unique identifier of an SPI device. When operating an SPI device, you need to specify a descriptor of the <a href="SpiDevInfo.md">SpiDevInfo</a> type, and obtain the handle of the SPI device by calling <a href="SPI.md#ga193e808f7e68a5b4c6b71ca2db47a11f">SpiOpen</a>. </p>
</td>
</tr>
<tr id="row1956962196165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2063945550165628"><a name="p2063945550165628"></a><a name="p2063945550165628"></a><a href="SpiMsg.md">SpiMsg</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1813575927165628"><a name="p1813575927165628"></a><a name="p1813575927165628"></a>Defines the custom SPI transfer message. </p>
</td>
</tr>
<tr id="row1876086683165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1289826619165628"><a name="p1289826619165628"></a><a name="p1289826619165628"></a><a href="SpiCfg.md">SpiCfg</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p213674419165628"><a name="p213674419165628"></a><a name="p213674419165628"></a>Defines the configuration of an SPI device. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table2136677008165628"></a>
<table><thead align="left"><tr id="row1514535453165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p430853731165628"><a name="p430853731165628"></a><a name="p430853731165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2093217503165628"><a name="p2093217503165628"></a><a name="p2093217503165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1718224891165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p958821592165628"><a name="p958821592165628"></a><a name="p958821592165628"></a><a href="SPI.md#ga430ad9ccffd42f4427ba22fcc8167c64">SPI_CLK_PHASE</a>   (1 &lt;&lt; 0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2067084455165628"><a name="p2067084455165628"></a><a name="p2067084455165628"></a>Indicates the SPI clock phase. The value <strong id="b604454703165628"><a name="b604454703165628"></a><a name="b604454703165628"></a>0</strong> indicates that data will be sampled on the first clock edge, and <strong id="b788797261165628"><a name="b788797261165628"></a><a name="b788797261165628"></a>1</strong> indicates that data will be sampled on the second clock edge. </p>
</td>
</tr>
<tr id="row1957015182165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1956828172165628"><a name="p1956828172165628"></a><a name="p1956828172165628"></a><a href="SPI.md#ga4cafe948918622f80c27db640c6c23c6">SPI_CLK_POLARITY</a>   (1 &lt;&lt; 1)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1213998790165628"><a name="p1213998790165628"></a><a name="p1213998790165628"></a>Indicates the SPI clock polarity. The value <strong id="b708677398165628"><a name="b708677398165628"></a><a name="b708677398165628"></a>0</strong> indicates a low-level clock signal in the idle state, and <strong id="b1877012488165628"><a name="b1877012488165628"></a><a name="b1877012488165628"></a>1</strong> indicates a high-level clock signal in the idle state. </p>
</td>
</tr>
<tr id="row458292312165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1185977171165628"><a name="p1185977171165628"></a><a name="p1185977171165628"></a><a href="SPI.md#ga11113e647ddd2101c1c693632f63aa7c">SPI_MODE_3WIRE</a>   (1 &lt;&lt; 2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p820689627165628"><a name="p820689627165628"></a><a name="p820689627165628"></a>Indicates that a single data line is used for both input and output. </p>
</td>
</tr>
<tr id="row1725742844165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1198291188165628"><a name="p1198291188165628"></a><a name="p1198291188165628"></a><a href="SPI.md#ga8619b297de563eca6852af34c79daa62">SPI_MODE_LOOP</a>   (1 &lt;&lt; 3)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1907417210165628"><a name="p1907417210165628"></a><a name="p1907417210165628"></a>Indicates the SPI loopback mode. </p>
</td>
</tr>
<tr id="row1881290376165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p39716245165628"><a name="p39716245165628"></a><a name="p39716245165628"></a><a href="SPI.md#ga4da8777b0d2d7dd96d6038411791c36e">SPI_MODE_LSBFE</a>   (1 &lt;&lt; 4)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1329771987165628"><a name="p1329771987165628"></a><a name="p1329771987165628"></a>Indicates the SPI data transfer order. The value <strong id="b464048982165628"><a name="b464048982165628"></a><a name="b464048982165628"></a>0</strong> indicates that data is transferred from the most significant bit (MSB) to the least significant bit (LSB), and <strong id="b1156369380165628"><a name="b1156369380165628"></a><a name="b1156369380165628"></a>1</strong> indicates the opposite. </p>
</td>
</tr>
<tr id="row1970544080165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1391534643165628"><a name="p1391534643165628"></a><a name="p1391534643165628"></a><a href="SPI.md#ga361195644b8e753d5469dd492c66217b">SPI_MODE_NOCS</a>   (1 &lt;&lt; 5)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1553001600165628"><a name="p1553001600165628"></a><a name="p1553001600165628"></a>Indicates that there is only one SPI device, and no chip select (CS) is required. </p>
</td>
</tr>
<tr id="row1296955538165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1129816662165628"><a name="p1129816662165628"></a><a name="p1129816662165628"></a><a href="SPI.md#ga33d89d81eb33b7a5de1a03e88279163d">SPI_MODE_CS_HIGH</a>   (1 &lt;&lt; 6)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p946061116165628"><a name="p946061116165628"></a><a name="p946061116165628"></a>Indicates that the CS level is high when an SPI device is selected. </p>
</td>
</tr>
<tr id="row187003238165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1762524803165628"><a name="p1762524803165628"></a><a name="p1762524803165628"></a><a href="SPI.md#ga42f3ef9ad5429ac10662448fe1f5a746">SPI_MODE_READY</a>   (1 &lt;&lt; 7)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1602780297165628"><a name="p1602780297165628"></a><a name="p1602780297165628"></a>Indicates that the SPI device is set to low for pausing data transfer. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1114056835165628"></a>
<table><thead align="left"><tr id="row1171527200165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p182113121165628"><a name="p182113121165628"></a><a name="p182113121165628"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1197247913165628"><a name="p1197247913165628"></a><a name="p1197247913165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2111342280165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1307019249165628"><a name="p1307019249165628"></a><a name="p1307019249165628"></a><a href="SPI.md#ga55946d1d895fc2b7b33007019de1668f">SpiTransferMode</a> { <a href="SPI.md#gga55946d1d895fc2b7b33007019de1668fad91925d3e1b3e82ff14004dd0b9d98a3">SPI_INTERRUPT_TRANSFER</a> = 0, <a href="SPI.md#gga55946d1d895fc2b7b33007019de1668fa51d9bac6c8cbf4d95705563b097bb0b2">SPI_POLLING_TRANSFER</a>, <a href="SPI.md#gga55946d1d895fc2b7b33007019de1668fad4d2e8d82f1d9a15198399d6540bacd1">SPI_DMA_TRANSFER</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p215626221165628"><a name="p215626221165628"></a><a name="p215626221165628"></a>Enumerates transfer modes of SPI data. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table135442638165628"></a>
<table><thead align="left"><tr id="row675176906165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1385128802165628"><a name="p1385128802165628"></a><a name="p1385128802165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1162411976165628"><a name="p1162411976165628"></a><a name="p1162411976165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1865452496165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p691430417165628"><a name="p691430417165628"></a><a name="p691430417165628"></a><a href="SPI.md#ga193e808f7e68a5b4c6b71ca2db47a11f">SpiOpen</a> (const struct <a href="SpiDevInfo.md">SpiDevInfo</a> *info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1688773226165628"><a name="p1688773226165628"></a><a name="p1688773226165628"></a><a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> </p>
<p id="p1272843051165628"><a name="p1272843051165628"></a><a name="p1272843051165628"></a>Obtains the handle of an SPI device. </p>
</td>
</tr>
<tr id="row283560958165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1663646452165628"><a name="p1663646452165628"></a><a name="p1663646452165628"></a><a href="SPI.md#ga4c961307ea89008ba0f064c92eb1617d">SpiClose</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p100756827165628"><a name="p100756827165628"></a><a name="p100756827165628"></a>void </p>
<p id="p2107897943165628"><a name="p2107897943165628"></a><a name="p2107897943165628"></a>Releases the handle of an SPI device. </p>
</td>
</tr>
<tr id="row21022524165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2013036520165628"><a name="p2013036520165628"></a><a name="p2013036520165628"></a><a href="SPI.md#gaf9226a2ce4ff75c7dc76279b3bbd7af4">SpiTransfer</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, struct <a href="SpiMsg.md">SpiMsg</a> *msgs, uint32_t count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1431289001165628"><a name="p1431289001165628"></a><a name="p1431289001165628"></a>int32_t </p>
<p id="p2130372802165628"><a name="p2130372802165628"></a><a name="p2130372802165628"></a>Launches a custom transfer to an SPI device. </p>
</td>
</tr>
<tr id="row1389008804165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p411155686165628"><a name="p411155686165628"></a><a name="p411155686165628"></a><a href="SPI.md#gaa860e42dac8b2caabefda6e82ba1a541">SpiRead</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *buf, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p594866797165628"><a name="p594866797165628"></a><a name="p594866797165628"></a>int32_t </p>
<p id="p1189205133165628"><a name="p1189205133165628"></a><a name="p1189205133165628"></a>Reads data of a specified length from an SPI device. </p>
</td>
</tr>
<tr id="row1224118124165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p955135751165628"><a name="p955135751165628"></a><a name="p955135751165628"></a><a href="SPI.md#ga0073b24fba24fb37b3ea451a0c7d911f">SpiWrite</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *buf, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145485114165628"><a name="p1145485114165628"></a><a name="p1145485114165628"></a>int32_t </p>
<p id="p1100639478165628"><a name="p1100639478165628"></a><a name="p1100639478165628"></a>Writes data of a specified length to an SPI device. </p>
</td>
</tr>
<tr id="row787293067165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1425152680165628"><a name="p1425152680165628"></a><a name="p1425152680165628"></a><a href="SPI.md#gafbca6de683781921a8d1cb41ead0030e">SpiSetCfg</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, struct <a href="SpiCfg.md">SpiCfg</a> *cfg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1253729718165628"><a name="p1253729718165628"></a><a name="p1253729718165628"></a>int32_t </p>
<p id="p909645969165628"><a name="p909645969165628"></a><a name="p909645969165628"></a>Sets configuration parameters for an SPI device. </p>
</td>
</tr>
<tr id="row1819379772165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p369613424165628"><a name="p369613424165628"></a><a name="p369613424165628"></a><a href="SPI.md#ga77d533d55c550c4478185a02a4e12fb1">SpiGetCfg</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, struct <a href="SpiCfg.md">SpiCfg</a> *cfg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p429889601165628"><a name="p429889601165628"></a><a name="p429889601165628"></a>int32_t </p>
<p id="p795440734165628"><a name="p795440734165628"></a><a name="p795440734165628"></a>Obtains the configuration parameters of an SPI device. </p>
</td>
</tr>
</tbody>
</table>

