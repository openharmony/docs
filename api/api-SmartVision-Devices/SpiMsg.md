# SpiMsg<a name="ZH-CN_TOPIC_0000001054479601"></a>

-   [Overview](#section1972004157165636)
-   [Summary](#section1293398165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section770647843165636)
-   [Field](#section1902860348165636)
-   [csChange](#a1a38a03e30428aca7054cc8555b749a9)
-   [delayUs](#a443b7f63c6b33719759eacf600da3aab)
-   [len](#acb96c50b34d79d00277cbea9881b701a)
-   [rbuf](#a575755ef9506c10199c47f636f1de1de)
-   [speed](#adff9e15325aab2afb066a1f3489b55d5)
-   [wbuf](#ae2aed8b3bd1d75a50f82c880a45cf521)

## **Overview**<a name="section1972004157165636"></a>

**Related Modules:**

[SPI](SPI.md)

**Description:**

Defines the custom SPI transfer message. 

Attention
:   The specific SPI controller determines whether  **speed**,  **delayUs**, and  **csChange**  are supported.

**Since:**

1.0

## **Summary**<a name="section1293398165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table2003777103165636"></a>
<table><thead align="left"><tr id="row1556677169165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p44418077165636"><a name="p44418077165636"></a><a name="p44418077165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1534487636165636"><a name="p1534487636165636"></a><a name="p1534487636165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row30257823165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1620528773165636"><a name="p1620528773165636"></a><a name="p1620528773165636"></a><a href="SpiMsg.md#ae2aed8b3bd1d75a50f82c880a45cf521">wbuf</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p30636575165636"><a name="p30636575165636"></a><a name="p30636575165636"></a>uint8_t * </p>
</td>
</tr>
<tr id="row1172929204165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1395837004165636"><a name="p1395837004165636"></a><a name="p1395837004165636"></a><a href="SpiMsg.md#a575755ef9506c10199c47f636f1de1de">rbuf</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p394634459165636"><a name="p394634459165636"></a><a name="p394634459165636"></a>uint8_t * </p>
</td>
</tr>
<tr id="row240310619165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1704567169165636"><a name="p1704567169165636"></a><a name="p1704567169165636"></a><a href="SpiMsg.md#acb96c50b34d79d00277cbea9881b701a">len</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p120572530165636"><a name="p120572530165636"></a><a name="p120572530165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row454214147165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1512099638165636"><a name="p1512099638165636"></a><a name="p1512099638165636"></a><a href="SpiMsg.md#adff9e15325aab2afb066a1f3489b55d5">speed</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1379239657165636"><a name="p1379239657165636"></a><a name="p1379239657165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row553694686165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1414316792165636"><a name="p1414316792165636"></a><a name="p1414316792165636"></a><a href="SpiMsg.md#a443b7f63c6b33719759eacf600da3aab">delayUs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1388517823165636"><a name="p1388517823165636"></a><a name="p1388517823165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row562590973165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1505106416165636"><a name="p1505106416165636"></a><a name="p1505106416165636"></a><a href="SpiMsg.md#a1a38a03e30428aca7054cc8555b749a9">csChange</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p580641256165636"><a name="p580641256165636"></a><a name="p580641256165636"></a>uint8_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section770647843165636"></a>

## **Field **<a name="section1902860348165636"></a>

## csChange<a name="a1a38a03e30428aca7054cc8555b749a9"></a>

```
uint8_t SpiMsg::csChange
```

 **Description:**

Whether to switch off the CS before the next transfer when the current transfer has been completed.  **1**  indicates to switch off the CS;  **0**  indicates to switch on the CS. 

## delayUs<a name="a443b7f63c6b33719759eacf600da3aab"></a>

```
uint16_t SpiMsg::delayUs
```

 **Description:**

Delay \(in microseconds\) before starting the next transfer. The value  **0**  indicates there is no delay between transfers. 

## len<a name="acb96c50b34d79d00277cbea9881b701a"></a>

```
uint32_t SpiMsg::len
```

 **Description:**

Length of the read and write buffers. The read buffer and the write buffer have the same length. 

## rbuf<a name="a575755ef9506c10199c47f636f1de1de"></a>

```
uint8_t* SpiMsg::rbuf
```

 **Description:**

Address of the read buffer 

## speed<a name="adff9e15325aab2afb066a1f3489b55d5"></a>

```
uint32_t SpiMsg::speed
```

 **Description:**

Current message transfer speed 

## wbuf<a name="ae2aed8b3bd1d75a50f82c880a45cf521"></a>

```
uint8_t* SpiMsg::wbuf
```

 **Description:**

Address of the write buffer 

