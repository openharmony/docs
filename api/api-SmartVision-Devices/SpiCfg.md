# SpiCfg<a name="ZH-CN_TOPIC_0000001054879570"></a>

-   [Overview](#section1247638969165636)
-   [Summary](#section519846771165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section553147246165636)
-   [Field](#section199850120165636)
-   [bitsPerWord](#ac671a8fc23e2998243695c7bd27232f3)
-   [maxSpeedHz](#a81369e5879c93f2747375dffbd5f975d)
-   [mode](#a48b7732e7d6e53d5af6ad5ce36cb96d3)
-   [transferMode](#a4193f45f83d1501f5e0ead393e1e55a1)

## **Overview**<a name="section1247638969165636"></a>

**Related Modules:**

[SPI](SPI.md)

**Description:**

Defines the configuration of an SPI device. 

Attention
:   The specific SPI controller determines which variables in this structure are supported.

**Since:**

1.0

## **Summary**<a name="section519846771165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table858049802165636"></a>
<table><thead align="left"><tr id="row550174029165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1952263539165636"><a name="p1952263539165636"></a><a name="p1952263539165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p462307997165636"><a name="p462307997165636"></a><a name="p462307997165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1280153313165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p220335440165636"><a name="p220335440165636"></a><a name="p220335440165636"></a><a href="SpiCfg.md#a81369e5879c93f2747375dffbd5f975d">maxSpeedHz</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2108814029165636"><a name="p2108814029165636"></a><a name="p2108814029165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row237708740165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1032058859165636"><a name="p1032058859165636"></a><a name="p1032058859165636"></a><a href="SpiCfg.md#a48b7732e7d6e53d5af6ad5ce36cb96d3">mode</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1491825992165636"><a name="p1491825992165636"></a><a name="p1491825992165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row531136347165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1233180448165636"><a name="p1233180448165636"></a><a name="p1233180448165636"></a><a href="SpiCfg.md#a4193f45f83d1501f5e0ead393e1e55a1">transferMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1982512921165636"><a name="p1982512921165636"></a><a name="p1982512921165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row1570387663165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p635083884165636"><a name="p635083884165636"></a><a name="p635083884165636"></a><a href="SpiCfg.md#ac671a8fc23e2998243695c7bd27232f3">bitsPerWord</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p793644244165636"><a name="p793644244165636"></a><a name="p793644244165636"></a>uint8_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section553147246165636"></a>

## **Field **<a name="section199850120165636"></a>

## bitsPerWord<a name="ac671a8fc23e2998243695c7bd27232f3"></a>

```
uint8_t SpiCfg::bitsPerWord
```

 **Description:**

Data transfer bit width 

## maxSpeedHz<a name="a81369e5879c93f2747375dffbd5f975d"></a>

```
uint32_t SpiCfg::maxSpeedHz
```

 **Description:**

Maximum clock frequency 

## mode<a name="a48b7732e7d6e53d5af6ad5ce36cb96d3"></a>

```
uint16_t SpiCfg::mode
```

## transferMode<a name="a4193f45f83d1501f5e0ead393e1e55a1"></a>

```
uint8_t SpiCfg::transferMode
```

 **Description:**

Data transfer mode, as defined in  [SpiTransferMode](SPI.md#ga55946d1d895fc2b7b33007019de1668f). 

