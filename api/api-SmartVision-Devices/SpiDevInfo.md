# SpiDevInfo<a name="ZH-CN_TOPIC_0000001055039554"></a>

-   [Overview](#section911266885165636)
-   [Summary](#section2004328004165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section251235474165636)
-   [Field](#section1389783708165636)
-   [busNum](#a317656e748a353d8520d891e77c7b111)
-   [csNum](#aff59a847b2a6144dd93047fff7841ec7)

## **Overview**<a name="section911266885165636"></a>

**Related Modules:**

[SPI](SPI.md)

**Description:**

Defines the general SPI device descriptor, which can be used as the unique identifier of an SPI device. When operating an SPI device, you need to specify a descriptor of the  [SpiDevInfo](SpiDevInfo.md)  type, and obtain the handle of the SPI device by calling  [SpiOpen](SPI.md#ga193e808f7e68a5b4c6b71ca2db47a11f). 

**Since:**

1.0

## **Summary**<a name="section2004328004165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table117659404165636"></a>
<table><thead align="left"><tr id="row428082426165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p228472347165636"><a name="p228472347165636"></a><a name="p228472347165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p326387224165636"><a name="p326387224165636"></a><a name="p326387224165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row97419566165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1868712849165636"><a name="p1868712849165636"></a><a name="p1868712849165636"></a><a href="SpiDevInfo.md#a317656e748a353d8520d891e77c7b111">busNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1638488513165636"><a name="p1638488513165636"></a><a name="p1638488513165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row560633190165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1136504604165636"><a name="p1136504604165636"></a><a name="p1136504604165636"></a><a href="SpiDevInfo.md#aff59a847b2a6144dd93047fff7841ec7">csNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1490690439165636"><a name="p1490690439165636"></a><a name="p1490690439165636"></a>uint32_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section251235474165636"></a>

## **Field **<a name="section1389783708165636"></a>

## busNum<a name="a317656e748a353d8520d891e77c7b111"></a>

```
uint32_t SpiDevInfo::busNum
```

 **Description:**

SPI bus number 

## csNum<a name="aff59a847b2a6144dd93047fff7841ec7"></a>

```
uint32_t SpiDevInfo::csNum
```

 **Description:**

SPI device chip select \(CS\) 

