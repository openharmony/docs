# SPI<a name="ZH-CN_TOPIC_0000001055518038"></a>

-   [Overview](#section652650751165623)
-   [Summary](#section1949059107165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section1765579536165623)
-   [Macro Definition](#section1272510252165623)
-   [SPI\_CLK\_PHASE](#ga430ad9ccffd42f4427ba22fcc8167c64)
-   [SPI\_CLK\_POLARITY](#ga4cafe948918622f80c27db640c6c23c6)
-   [SPI\_MODE\_3WIRE](#ga11113e647ddd2101c1c693632f63aa7c)
-   [SPI\_MODE\_CS\_HIGH](#ga33d89d81eb33b7a5de1a03e88279163d)
-   [SPI\_MODE\_LOOP](#ga8619b297de563eca6852af34c79daa62)
-   [SPI\_MODE\_LSBFE](#ga4da8777b0d2d7dd96d6038411791c36e)
-   [SPI\_MODE\_NOCS](#ga361195644b8e753d5469dd492c66217b)
-   [SPI\_MODE\_READY](#ga42f3ef9ad5429ac10662448fe1f5a746)
-   [Enumeration Type](#section1553762052165623)
-   [SpiTransferMode](#ga55946d1d895fc2b7b33007019de1668f)
-   [Function](#section496230935165623)
-   [SpiClose\(\)](#ga4c961307ea89008ba0f064c92eb1617d)
-   [SpiGetCfg\(\)](#ga77d533d55c550c4478185a02a4e12fb1)
-   [SpiOpen\(\)](#ga193e808f7e68a5b4c6b71ca2db47a11f)
-   [SpiRead\(\)](#gaa860e42dac8b2caabefda6e82ba1a541)
-   [SpiSetCfg\(\)](#gafbca6de683781921a8d1cb41ead0030e)
-   [SpiTransfer\(\)](#gaf9226a2ce4ff75c7dc76279b3bbd7af4)
-   [SpiWrite\(\)](#ga0073b24fba24fb37b3ea451a0c7d911f)

## **Overview**<a name="section652650751165623"></a>

**Description:**

Defines standard APIs of the Serial Peripheral Interface \(SPI\) capabilities. 

The SPI module abstracts the SPI capabilities of different system platforms to provide stable APIs for driver development. This module can create and destroy SPI device handles, read and write SPI data, and obtain and set configuration parameters.

**Since:**

1.0

## **Summary**<a name="section1949059107165623"></a>

## Files<a name="files"></a>

<a name="table479110516165623"></a>
<table><thead align="left"><tr id="row1427069622165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1813704173165623"><a name="p1813704173165623"></a><a name="p1813704173165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1027214754165623"><a name="p1027214754165623"></a><a name="p1027214754165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3350177165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1276116054165623"><a name="p1276116054165623"></a><a name="p1276116054165623"></a><a href="spi_if-h.md">spi_if.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1741597673165623"><a name="p1741597673165623"></a><a name="p1741597673165623"></a>Defines standard SPI-specific interfaces for driver development. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table193777004165623"></a>
<table><thead align="left"><tr id="row1423214261165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p36294802165623"><a name="p36294802165623"></a><a name="p36294802165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1737693558165623"><a name="p1737693558165623"></a><a name="p1737693558165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1427720483165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p372432662165623"><a name="p372432662165623"></a><a name="p372432662165623"></a><a href="SpiDevInfo.md">SpiDevInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p299567353165623"><a name="p299567353165623"></a><a name="p299567353165623"></a>Defines the general SPI device descriptor, which can be used as the unique identifier of an SPI device. When operating an SPI device, you need to specify a descriptor of the <a href="SpiDevInfo.md">SpiDevInfo</a> type, and obtain the handle of the SPI device by calling <a href="SPI.md#ga193e808f7e68a5b4c6b71ca2db47a11f">SpiOpen</a>. </p>
</td>
</tr>
<tr id="row1400510353165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p59228059165623"><a name="p59228059165623"></a><a name="p59228059165623"></a><a href="SpiMsg.md">SpiMsg</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p895676004165623"><a name="p895676004165623"></a><a name="p895676004165623"></a>Defines the custom SPI transfer message. </p>
</td>
</tr>
<tr id="row472377791165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p169352059165623"><a name="p169352059165623"></a><a name="p169352059165623"></a><a href="SpiCfg.md">SpiCfg</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1818389002165623"><a name="p1818389002165623"></a><a name="p1818389002165623"></a>Defines the configuration of an SPI device. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1918407450165623"></a>
<table><thead align="left"><tr id="row862799477165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1432349470165623"><a name="p1432349470165623"></a><a name="p1432349470165623"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1987812896165623"><a name="p1987812896165623"></a><a name="p1987812896165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row941391600165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2053444156165623"><a name="p2053444156165623"></a><a name="p2053444156165623"></a><a href="SPI.md#ga430ad9ccffd42f4427ba22fcc8167c64">SPI_CLK_PHASE</a>   (1 &lt;&lt; 0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1349263291165623"><a name="p1349263291165623"></a><a name="p1349263291165623"></a>Indicates the SPI clock phase. The value <strong id="b1899649781165623"><a name="b1899649781165623"></a><a name="b1899649781165623"></a>0</strong> indicates that data will be sampled on the first clock edge, and <strong id="b1798915839165623"><a name="b1798915839165623"></a><a name="b1798915839165623"></a>1</strong> indicates that data will be sampled on the second clock edge. </p>
</td>
</tr>
<tr id="row1922748571165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p563383260165623"><a name="p563383260165623"></a><a name="p563383260165623"></a><a href="SPI.md#ga4cafe948918622f80c27db640c6c23c6">SPI_CLK_POLARITY</a>   (1 &lt;&lt; 1)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2107976077165623"><a name="p2107976077165623"></a><a name="p2107976077165623"></a>Indicates the SPI clock polarity. The value <strong id="b2145609173165623"><a name="b2145609173165623"></a><a name="b2145609173165623"></a>0</strong> indicates a low-level clock signal in the idle state, and <strong id="b1034808004165623"><a name="b1034808004165623"></a><a name="b1034808004165623"></a>1</strong> indicates a high-level clock signal in the idle state. </p>
</td>
</tr>
<tr id="row1613512946165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1276424549165623"><a name="p1276424549165623"></a><a name="p1276424549165623"></a><a href="SPI.md#ga11113e647ddd2101c1c693632f63aa7c">SPI_MODE_3WIRE</a>   (1 &lt;&lt; 2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p967029033165623"><a name="p967029033165623"></a><a name="p967029033165623"></a>Indicates that a single data line is used for both input and output. </p>
</td>
</tr>
<tr id="row732540285165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p947121258165623"><a name="p947121258165623"></a><a name="p947121258165623"></a><a href="SPI.md#ga8619b297de563eca6852af34c79daa62">SPI_MODE_LOOP</a>   (1 &lt;&lt; 3)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2064183688165623"><a name="p2064183688165623"></a><a name="p2064183688165623"></a>Indicates the SPI loopback mode. </p>
</td>
</tr>
<tr id="row1793932554165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p670257318165623"><a name="p670257318165623"></a><a name="p670257318165623"></a><a href="SPI.md#ga4da8777b0d2d7dd96d6038411791c36e">SPI_MODE_LSBFE</a>   (1 &lt;&lt; 4)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p429037913165623"><a name="p429037913165623"></a><a name="p429037913165623"></a>Indicates the SPI data transfer order. The value <strong id="b1164081415165623"><a name="b1164081415165623"></a><a name="b1164081415165623"></a>0</strong> indicates that data is transferred from the most significant bit (MSB) to the least significant bit (LSB), and <strong id="b2127838121165623"><a name="b2127838121165623"></a><a name="b2127838121165623"></a>1</strong> indicates the opposite. </p>
</td>
</tr>
<tr id="row230891291165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1017829497165623"><a name="p1017829497165623"></a><a name="p1017829497165623"></a><a href="SPI.md#ga361195644b8e753d5469dd492c66217b">SPI_MODE_NOCS</a>   (1 &lt;&lt; 5)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1227337877165623"><a name="p1227337877165623"></a><a name="p1227337877165623"></a>Indicates that there is only one SPI device, and no chip select (CS) is required. </p>
</td>
</tr>
<tr id="row1423364292165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1510715011165623"><a name="p1510715011165623"></a><a name="p1510715011165623"></a><a href="SPI.md#ga33d89d81eb33b7a5de1a03e88279163d">SPI_MODE_CS_HIGH</a>   (1 &lt;&lt; 6)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1860638719165623"><a name="p1860638719165623"></a><a name="p1860638719165623"></a>Indicates that the CS level is high when an SPI device is selected. </p>
</td>
</tr>
<tr id="row527390034165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1721885873165623"><a name="p1721885873165623"></a><a name="p1721885873165623"></a><a href="SPI.md#ga42f3ef9ad5429ac10662448fe1f5a746">SPI_MODE_READY</a>   (1 &lt;&lt; 7)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p277252629165623"><a name="p277252629165623"></a><a name="p277252629165623"></a>Indicates that the SPI device is set to low for pausing data transfer. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table453576116165623"></a>
<table><thead align="left"><tr id="row1059799362165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p181359404165623"><a name="p181359404165623"></a><a name="p181359404165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1136037209165623"><a name="p1136037209165623"></a><a name="p1136037209165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1975408056165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p909124369165623"><a name="p909124369165623"></a><a name="p909124369165623"></a><a href="SPI.md#ga55946d1d895fc2b7b33007019de1668f">SpiTransferMode</a> { <a href="SPI.md#gga55946d1d895fc2b7b33007019de1668fad91925d3e1b3e82ff14004dd0b9d98a3">SPI_INTERRUPT_TRANSFER</a> = 0, <a href="SPI.md#gga55946d1d895fc2b7b33007019de1668fa51d9bac6c8cbf4d95705563b097bb0b2">SPI_POLLING_TRANSFER</a>, <a href="SPI.md#gga55946d1d895fc2b7b33007019de1668fad4d2e8d82f1d9a15198399d6540bacd1">SPI_DMA_TRANSFER</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1712692214165623"><a name="p1712692214165623"></a><a name="p1712692214165623"></a>Enumerates transfer modes of SPI data. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table717602761165623"></a>
<table><thead align="left"><tr id="row1787301538165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p802592898165623"><a name="p802592898165623"></a><a name="p802592898165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p230903298165623"><a name="p230903298165623"></a><a name="p230903298165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row58076626165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1416982687165623"><a name="p1416982687165623"></a><a name="p1416982687165623"></a><a href="SPI.md#ga193e808f7e68a5b4c6b71ca2db47a11f">SpiOpen</a> (const struct <a href="SpiDevInfo.md">SpiDevInfo</a> *info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p230968671165623"><a name="p230968671165623"></a><a name="p230968671165623"></a><a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> </p>
<p id="p1590835686165623"><a name="p1590835686165623"></a><a name="p1590835686165623"></a>Obtains the handle of an SPI device. </p>
</td>
</tr>
<tr id="row1802604141165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1283041699165623"><a name="p1283041699165623"></a><a name="p1283041699165623"></a><a href="SPI.md#ga4c961307ea89008ba0f064c92eb1617d">SpiClose</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p103717457165623"><a name="p103717457165623"></a><a name="p103717457165623"></a>void </p>
<p id="p755306650165623"><a name="p755306650165623"></a><a name="p755306650165623"></a>Releases the handle of an SPI device. </p>
</td>
</tr>
<tr id="row695141670165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1003833164165623"><a name="p1003833164165623"></a><a name="p1003833164165623"></a><a href="SPI.md#gaf9226a2ce4ff75c7dc76279b3bbd7af4">SpiTransfer</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, struct <a href="SpiMsg.md">SpiMsg</a> *msgs, uint32_t count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p121672169165623"><a name="p121672169165623"></a><a name="p121672169165623"></a>int32_t </p>
<p id="p2042704727165623"><a name="p2042704727165623"></a><a name="p2042704727165623"></a>Launches a custom transfer to an SPI device. </p>
</td>
</tr>
<tr id="row489479442165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p950160209165623"><a name="p950160209165623"></a><a name="p950160209165623"></a><a href="SPI.md#gaa860e42dac8b2caabefda6e82ba1a541">SpiRead</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *buf, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1238495864165623"><a name="p1238495864165623"></a><a name="p1238495864165623"></a>int32_t </p>
<p id="p1875041219165623"><a name="p1875041219165623"></a><a name="p1875041219165623"></a>Reads data of a specified length from an SPI device. </p>
</td>
</tr>
<tr id="row1538669845165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p613871853165623"><a name="p613871853165623"></a><a name="p613871853165623"></a><a href="SPI.md#ga0073b24fba24fb37b3ea451a0c7d911f">SpiWrite</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *buf, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1564168694165623"><a name="p1564168694165623"></a><a name="p1564168694165623"></a>int32_t </p>
<p id="p1465826687165623"><a name="p1465826687165623"></a><a name="p1465826687165623"></a>Writes data of a specified length to an SPI device. </p>
</td>
</tr>
<tr id="row1870690103165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p117058465165623"><a name="p117058465165623"></a><a name="p117058465165623"></a><a href="SPI.md#gafbca6de683781921a8d1cb41ead0030e">SpiSetCfg</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, struct <a href="SpiCfg.md">SpiCfg</a> *cfg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p457958865165623"><a name="p457958865165623"></a><a name="p457958865165623"></a>int32_t </p>
<p id="p1000047419165623"><a name="p1000047419165623"></a><a name="p1000047419165623"></a>Sets configuration parameters for an SPI device. </p>
</td>
</tr>
<tr id="row1482302835165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1736385123165623"><a name="p1736385123165623"></a><a name="p1736385123165623"></a><a href="SPI.md#ga77d533d55c550c4478185a02a4e12fb1">SpiGetCfg</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, struct <a href="SpiCfg.md">SpiCfg</a> *cfg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1422503551165623"><a name="p1422503551165623"></a><a name="p1422503551165623"></a>int32_t </p>
<p id="p425081909165623"><a name="p425081909165623"></a><a name="p425081909165623"></a>Obtains the configuration parameters of an SPI device. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1765579536165623"></a>

## **Macro Definition **<a name="section1272510252165623"></a>

## SPI\_CLK\_PHASE<a name="ga430ad9ccffd42f4427ba22fcc8167c64"></a>

```
#define SPI_CLK_PHASE   (1 << 0)
```

 **Description:**

Indicates the SPI clock phase. The value  **0**  indicates that data will be sampled on the first clock edge, and  **1**  indicates that data will be sampled on the second clock edge. 

## SPI\_CLK\_POLARITY<a name="ga4cafe948918622f80c27db640c6c23c6"></a>

```
#define SPI_CLK_POLARITY   (1 << 1)
```

 **Description:**

Indicates the SPI clock polarity. The value  **0**  indicates a low-level clock signal in the idle state, and  **1**  indicates a high-level clock signal in the idle state. 

## SPI\_MODE\_3WIRE<a name="ga11113e647ddd2101c1c693632f63aa7c"></a>

```
#define SPI_MODE_3WIRE   (1 << 2)
```

 **Description:**

Indicates that a single data line is used for both input and output. 

## SPI\_MODE\_CS\_HIGH<a name="ga33d89d81eb33b7a5de1a03e88279163d"></a>

```
#define SPI_MODE_CS_HIGH   (1 << 6)
```

 **Description:**

Indicates that the CS level is high when an SPI device is selected. 

## SPI\_MODE\_LOOP<a name="ga8619b297de563eca6852af34c79daa62"></a>

```
#define SPI_MODE_LOOP   (1 << 3)
```

 **Description:**

Indicates the SPI loopback mode. 

## SPI\_MODE\_LSBFE<a name="ga4da8777b0d2d7dd96d6038411791c36e"></a>

```
#define SPI_MODE_LSBFE   (1 << 4)
```

 **Description:**

Indicates the SPI data transfer order. The value  **0**  indicates that data is transferred from the most significant bit \(MSB\) to the least significant bit \(LSB\), and  **1**  indicates the opposite. 

## SPI\_MODE\_NOCS<a name="ga361195644b8e753d5469dd492c66217b"></a>

```
#define SPI_MODE_NOCS   (1 << 5)
```

 **Description:**

Indicates that there is only one SPI device, and no chip select \(CS\) is required. 

## SPI\_MODE\_READY<a name="ga42f3ef9ad5429ac10662448fe1f5a746"></a>

```
#define SPI_MODE_READY   (1 << 7)
```

 **Description:**

Indicates that the SPI device is set to low for pausing data transfer. 

## **Enumeration Type **<a name="section1553762052165623"></a>

## SpiTransferMode<a name="ga55946d1d895fc2b7b33007019de1668f"></a>

```
enum [SpiTransferMode](SPI.md#ga55946d1d895fc2b7b33007019de1668f)
```

 **Description:**

Enumerates transfer modes of SPI data. 

**Attention:**

The specific SPI controller determines which variables in this structure are supported.

<a name="table2045379425165623"></a>
<table><thead align="left"><tr id="row950473180165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p624435491165623"><a name="p624435491165623"></a><a name="p624435491165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1220758407165623"><a name="p1220758407165623"></a><a name="p1220758407165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1646202161165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga55946d1d895fc2b7b33007019de1668fad91925d3e1b3e82ff14004dd0b9d98a3"><a name="gga55946d1d895fc2b7b33007019de1668fad91925d3e1b3e82ff14004dd0b9d98a3"></a><a name="gga55946d1d895fc2b7b33007019de1668fad91925d3e1b3e82ff14004dd0b9d98a3"></a></strong>SPI_INTERRUPT_TRANSFER </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p814784018165623"><a name="p814784018165623"></a><a name="p814784018165623"></a>Interrupt transfer mode </p>
 </td>
</tr>
<tr id="row286823671165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga55946d1d895fc2b7b33007019de1668fa51d9bac6c8cbf4d95705563b097bb0b2"><a name="gga55946d1d895fc2b7b33007019de1668fa51d9bac6c8cbf4d95705563b097bb0b2"></a><a name="gga55946d1d895fc2b7b33007019de1668fa51d9bac6c8cbf4d95705563b097bb0b2"></a></strong>SPI_POLLING_TRANSFER </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2144289745165623"><a name="p2144289745165623"></a><a name="p2144289745165623"></a>Polling transfer mode </p>
 </td>
</tr>
<tr id="row1569827334165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga55946d1d895fc2b7b33007019de1668fad4d2e8d82f1d9a15198399d6540bacd1"><a name="gga55946d1d895fc2b7b33007019de1668fad4d2e8d82f1d9a15198399d6540bacd1"></a><a name="gga55946d1d895fc2b7b33007019de1668fad4d2e8d82f1d9a15198399d6540bacd1"></a></strong>SPI_DMA_TRANSFER </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p426853005165623"><a name="p426853005165623"></a><a name="p426853005165623"></a>Direct Memory Access (DMA) transfer mode </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section496230935165623"></a>

## SpiClose\(\)<a name="ga4c961307ea89008ba0f064c92eb1617d"></a>

```
void SpiClose ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Releases the handle of an SPI device. 

**Parameters:**

<a name="table56759381165623"></a>
<table><thead align="left"><tr id="row107942213165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p620475579165623"><a name="p620475579165623"></a><a name="p620475579165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p950160591165623"><a name="p950160591165623"></a><a name="p950160591165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1635788788165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the SPI device handle obtained via <a href="SPI.md#ga193e808f7e68a5b4c6b71ca2db47a11f">SpiOpen</a>.</td>
</tr>
</tbody>
</table>

## SpiGetCfg\(\)<a name="ga77d533d55c550c4478185a02a4e12fb1"></a>

```
int32_t SpiGetCfg ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, struct [SpiCfg](SpiCfg.md) * cfg )
```

 **Description:**

Obtains the configuration parameters of an SPI device. 

**Parameters:**

<a name="table1554771798165623"></a>
<table><thead align="left"><tr id="row717306265165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p868307499165623"><a name="p868307499165623"></a><a name="p868307499165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1301488904165623"><a name="p1301488904165623"></a><a name="p1301488904165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row543434241165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the SPI device handle obtained via <a href="SPI.md#ga193e808f7e68a5b4c6b71ca2db47a11f">SpiOpen</a>. </td>
</tr>
<tr id="row750682857165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cfg</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration parameters.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise.

## SpiOpen\(\)<a name="ga193e808f7e68a5b4c6b71ca2db47a11f"></a>

```
[DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) SpiOpen (const struct [SpiDevInfo](SpiDevInfo.md) * info)
```

 **Description:**

Obtains the handle of an SPI device. 

**Parameters:**

<a name="table1526915377165623"></a>
<table><thead align="left"><tr id="row379734551165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2094300844165623"><a name="p2094300844165623"></a><a name="p2094300844165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1686554279165623"><a name="p1686554279165623"></a><a name="p1686554279165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row263089840165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">info</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the SPI device information.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the handle of the SPI device if the operation is successful; returns  **NULL**  otherwise.

## SpiRead\(\)<a name="gaa860e42dac8b2caabefda6e82ba1a541"></a>

```
int32_t SpiRead ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint8_t * buf, uint32_t len )
```

 **Description:**

Reads data of a specified length from an SPI device. 

**Parameters:**

<a name="table1710253595165623"></a>
<table><thead align="left"><tr id="row878546928165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1779947467165623"><a name="p1779947467165623"></a><a name="p1779947467165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1004057674165623"><a name="p1004057674165623"></a><a name="p1004057674165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1721577829165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the SPI device handle obtained via <a href="SPI.md#ga193e808f7e68a5b4c6b71ca2db47a11f">SpiOpen</a>. </td>
</tr>
<tr id="row1696356907165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer for receiving the data. </td>
</tr>
<tr id="row141951371165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the data to read.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise.

## SpiSetCfg\(\)<a name="gafbca6de683781921a8d1cb41ead0030e"></a>

```
int32_t SpiSetCfg ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, struct [SpiCfg](SpiCfg.md) * cfg )
```

 **Description:**

Sets configuration parameters for an SPI device. 

**Parameters:**

<a name="table666380838165623"></a>
<table><thead align="left"><tr id="row80571568165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p757697155165623"><a name="p757697155165623"></a><a name="p757697155165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1798038333165623"><a name="p1798038333165623"></a><a name="p1798038333165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1599287610165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the SPI device handle obtained via <a href="SPI.md#ga193e808f7e68a5b4c6b71ca2db47a11f">SpiOpen</a>. </td>
</tr>
<tr id="row1769055361165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cfg</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration parameters.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise.

## SpiTransfer\(\)<a name="gaf9226a2ce4ff75c7dc76279b3bbd7af4"></a>

```
int32_t SpiTransfer ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, struct [SpiMsg](SpiMsg.md) * msgs, uint32_t count )
```

 **Description:**

Launches a custom transfer to an SPI device. 

**Parameters:**

<a name="table1521704986165623"></a>
<table><thead align="left"><tr id="row1138048055165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1837718422165623"><a name="p1837718422165623"></a><a name="p1837718422165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1758625485165623"><a name="p1758625485165623"></a><a name="p1758625485165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1352172008165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the SPI device handle obtained via <a href="SPI.md#ga193e808f7e68a5b4c6b71ca2db47a11f">SpiOpen</a>. </td>
</tr>
<tr id="row728220943165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">msgs</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to transfer. </td>
</tr>
<tr id="row329343594165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">count</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the message structure array.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise. 

**See also:**

[SpiMsg](SpiMsg.md) 

## SpiWrite\(\)<a name="ga0073b24fba24fb37b3ea451a0c7d911f"></a>

```
int32_t SpiWrite ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint8_t * buf, uint32_t len )
```

 **Description:**

Writes data of a specified length to an SPI device. 

**Parameters:**

<a name="table1503130490165623"></a>
<table><thead align="left"><tr id="row463267665165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1942062880165623"><a name="p1942062880165623"></a><a name="p1942062880165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p451197772165623"><a name="p451197772165623"></a><a name="p451197772165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1340751861165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the SPI device handle obtained via <a href="SPI.md#ga193e808f7e68a5b4c6b71ca2db47a11f">SpiOpen</a>. </td>
</tr>
<tr id="row757709427165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to write. </td>
</tr>
<tr id="row1483157939165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the data to write.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise.

