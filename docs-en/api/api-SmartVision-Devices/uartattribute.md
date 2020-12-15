# UartAttribute<a name="EN-US_TOPIC_0000001054918195"></a>

-   [Overview](#section731235949165636)
-   [Summary](#section532115424165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section1595673192165636)
-   [Field](#section62349060165636)
-   [cts](#a8c2ec715ce735b87619440004a5816f3)
-   [dataBits](#a884f85f5c82f063596a52f43c12af1a8)
-   [fifoRxEn](#a171de31a6414563a1b8ca13c6209e52a)
-   [fifoTxEn](#a12cd3afb4dfbc5ed70578e0fcee0700d)
-   [parity](#abc4eefd31616175d469bc41d24b5b37b)
-   [reserved](#a415c8237e3a34dfe812e6c6cc7a7a1fa)
-   [rts](#a5ebfed49568aa4717b72d89084a13f3a)
-   [stopBits](#a29782a670eaf734ed02955eff0cdd4b9)

## **Overview**<a name="section731235949165636"></a>

**Related Modules:**

[UART](uart.md)

**Description:**

Defines basic attributes of the UART port. 

You can configure the attributes via  [UartSetAttribute](uart.md#ga76281a15464395451fc9844e717e0e10). If the parameters are not set, default attributes are used.

Attention
:   The UART controller determines which UART attribute parameters are supported.

**Since:**

1.0

## **Summary**<a name="section532115424165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table709140478165636"></a>
<table><thead align="left"><tr id="row1930313381165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p617830080165636"><a name="p617830080165636"></a><a name="p617830080165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p960631774165636"><a name="p960631774165636"></a><a name="p960631774165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1245792119165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p760772659165636"><a name="p760772659165636"></a><a name="p760772659165636"></a><a href="uartattribute.md#a884f85f5c82f063596a52f43c12af1a8">dataBits</a>: 4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p283548929165636"><a name="p283548929165636"></a><a name="p283548929165636"></a>unsigned int </p>
</td>
</tr>
<tr id="row851183058165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p620407527165636"><a name="p620407527165636"></a><a name="p620407527165636"></a><a href="uartattribute.md#abc4eefd31616175d469bc41d24b5b37b">parity</a>: 4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1088207675165636"><a name="p1088207675165636"></a><a name="p1088207675165636"></a>unsigned int </p>
</td>
</tr>
<tr id="row343783557165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p750163538165636"><a name="p750163538165636"></a><a name="p750163538165636"></a><a href="uartattribute.md#a29782a670eaf734ed02955eff0cdd4b9">stopBits</a>: 4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1804054375165636"><a name="p1804054375165636"></a><a name="p1804054375165636"></a>unsigned int </p>
</td>
</tr>
<tr id="row1550994942165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1737520512165636"><a name="p1737520512165636"></a><a name="p1737520512165636"></a><a href="uartattribute.md#a5ebfed49568aa4717b72d89084a13f3a">rts</a>: 1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1687967076165636"><a name="p1687967076165636"></a><a name="p1687967076165636"></a>unsigned int </p>
</td>
</tr>
<tr id="row1327899313165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1039859452165636"><a name="p1039859452165636"></a><a name="p1039859452165636"></a><a href="uartattribute.md#a8c2ec715ce735b87619440004a5816f3">cts</a>: 1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1947423142165636"><a name="p1947423142165636"></a><a name="p1947423142165636"></a>unsigned int </p>
</td>
</tr>
<tr id="row515185768165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2134813956165636"><a name="p2134813956165636"></a><a name="p2134813956165636"></a><a href="uartattribute.md#a171de31a6414563a1b8ca13c6209e52a">fifoRxEn</a>: 1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1063900195165636"><a name="p1063900195165636"></a><a name="p1063900195165636"></a>unsigned int </p>
</td>
</tr>
<tr id="row172711629165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p887952404165636"><a name="p887952404165636"></a><a name="p887952404165636"></a><a href="uartattribute.md#a12cd3afb4dfbc5ed70578e0fcee0700d">fifoTxEn</a>: 1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1669697675165636"><a name="p1669697675165636"></a><a name="p1669697675165636"></a>unsigned int </p>
</td>
</tr>
<tr id="row446548795165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1026857034165636"><a name="p1026857034165636"></a><a name="p1026857034165636"></a><a href="uartattribute.md#a415c8237e3a34dfe812e6c6cc7a7a1fa">reserved</a>: 16</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2091478475165636"><a name="p2091478475165636"></a><a name="p2091478475165636"></a>unsigned int </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1595673192165636"></a>

## **Field **<a name="section62349060165636"></a>

## cts<a name="a8c2ec715ce735b87619440004a5816f3"></a>

```
unsigned int UartAttribute::cts
```

## dataBits<a name="a884f85f5c82f063596a52f43c12af1a8"></a>

```
unsigned int UartAttribute::dataBits
```

## fifoRxEn<a name="a171de31a6414563a1b8ca13c6209e52a"></a>

```
unsigned int UartAttribute::fifoRxEn
```

## fifoTxEn<a name="a12cd3afb4dfbc5ed70578e0fcee0700d"></a>

```
unsigned int UartAttribute::fifoTxEn
```

## parity<a name="abc4eefd31616175d469bc41d24b5b37b"></a>

```
unsigned int UartAttribute::parity
```

## reserved<a name="a415c8237e3a34dfe812e6c6cc7a7a1fa"></a>

```
unsigned int UartAttribute::reserved
```

 **Description:**

Reserved bits 

## rts<a name="a5ebfed49568aa4717b72d89084a13f3a"></a>

```
unsigned int UartAttribute::rts
```

## stopBits<a name="a29782a670eaf734ed02955eff0cdd4b9"></a>

```
unsigned int UartAttribute::stopBits
```

