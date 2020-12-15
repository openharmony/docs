# HdfSBuf<a name="EN-US_TOPIC_0000001055039516"></a>

-   [Overview](#section1430273793165631)
-   [Summary](#section301392379165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section566322632165631)
-   [Field](#section1299622958165631)
-   [capacity](#a4b8ee04fe9c107abec005bc3828a135d)
-   [data](#a72274990ce3144c476b74734413d8564)
-   [isBind](#a3c130cb993cd738efaf14c3f45d085b2)
-   [readPos](#a34756aefb83171abc63d0b5684597542)
-   [writePos](#a0de2284b2d9921bdd47e598e0b71a440)

## **Overview**<a name="section1430273793165631"></a>

**Related Modules:**

[Core](core.md)

**Description:**

Defines a  **[HdfSBuf](hdfsbuf.md)**. 

**Since:**

1.0

## **Summary**<a name="section301392379165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table825752567165631"></a>
<table><thead align="left"><tr id="row1558183920165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1161485090165631"><a name="p1161485090165631"></a><a name="p1161485090165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2090527116165631"><a name="p2090527116165631"></a><a name="p2090527116165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1458214117165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1152630023165631"><a name="p1152630023165631"></a><a name="p1152630023165631"></a><a href="hdfsbuf.md#a0de2284b2d9921bdd47e598e0b71a440">writePos</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1883608463165631"><a name="p1883608463165631"></a><a name="p1883608463165631"></a>size_t </p>
</td>
</tr>
<tr id="row227918882165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1107661415165631"><a name="p1107661415165631"></a><a name="p1107661415165631"></a><a href="hdfsbuf.md#a34756aefb83171abc63d0b5684597542">readPos</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p758815297165631"><a name="p758815297165631"></a><a name="p758815297165631"></a>size_t </p>
</td>
</tr>
<tr id="row893936111165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p448440858165631"><a name="p448440858165631"></a><a name="p448440858165631"></a><a href="hdfsbuf.md#a4b8ee04fe9c107abec005bc3828a135d">capacity</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1376824312165631"><a name="p1376824312165631"></a><a name="p1376824312165631"></a>size_t </p>
</td>
</tr>
<tr id="row788312589165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1294220400165631"><a name="p1294220400165631"></a><a name="p1294220400165631"></a><a href="hdfsbuf.md#a72274990ce3144c476b74734413d8564">data</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1140571400165631"><a name="p1140571400165631"></a><a name="p1140571400165631"></a>uint8_t * </p>
</td>
</tr>
<tr id="row889346179165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p40851927165631"><a name="p40851927165631"></a><a name="p40851927165631"></a><a href="hdfsbuf.md#a3c130cb993cd738efaf14c3f45d085b2">isBind</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p174192554165631"><a name="p174192554165631"></a><a name="p174192554165631"></a>bool </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section566322632165631"></a>

## **Field **<a name="section1299622958165631"></a>

## capacity<a name="a4b8ee04fe9c107abec005bc3828a135d"></a>

```
size_t HdfSBuf::capacity
```

 **Description:**

Storage capacity, at most 512 KB. 

## data<a name="a72274990ce3144c476b74734413d8564"></a>

```
uint8_t* HdfSBuf::data
```

 **Description:**

Pointer to data storage 

## isBind<a name="a3c130cb993cd738efaf14c3f45d085b2"></a>

```
bool HdfSBuf::isBind
```

 **Description:**

Whether to bind the externally transferred pointer for data storage 

## readPos<a name="a34756aefb83171abc63d0b5684597542"></a>

```
size_t HdfSBuf::readPos
```

 **Description:**

Current read position 

## writePos<a name="a0de2284b2d9921bdd47e598e0b71a440"></a>

```
size_t HdfSBuf::writePos
```

 **Description:**

Current write position 

