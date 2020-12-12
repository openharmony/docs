# OsalFwBlock<a name="EN-US_TOPIC_0000001055678108"></a>

-   [Overview](#section1801840668165633)
-   [Summary](#section655348150165633)
-   [Data Fields](#pub-attribs)
-   [Details](#section1615420802165633)
-   [Field](#section576570456165633)
-   [curOffset](#a74631bb4d6242a21146e6465c9640fa8)
-   [data](#affee01298d0388b9e14da67fd17e6eba)
-   [dataSize](#a383d93123b0d78a8031132d06ff035c5)
-   [endFlag](#ada578cbe9c02da3ebef4e70835d42774)

## **Overview**<a name="section1801840668165633"></a>

**Related Modules:**

[OSAL](osal.md)

**Description:**

Defines the data structure for reading a firmware file. 

This structure declares the firmware block to read each time. The firmware file can be read in split mode. 

## **Summary**<a name="section655348150165633"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1218145080165633"></a>
<table><thead align="left"><tr id="row2081849986165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1062994693165633"><a name="p1062994693165633"></a><a name="p1062994693165633"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p509982363165633"><a name="p509982363165633"></a><a name="p509982363165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1565179986165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1504888496165633"><a name="p1504888496165633"></a><a name="p1504888496165633"></a><a href="osalfwblock.md#affee01298d0388b9e14da67fd17e6eba">data</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p294266097165633"><a name="p294266097165633"></a><a name="p294266097165633"></a>uint8_t * </p>
</td>
</tr>
<tr id="row48427956165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p200464655165633"><a name="p200464655165633"></a><a name="p200464655165633"></a><a href="osalfwblock.md#ada578cbe9c02da3ebef4e70835d42774">endFlag</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p979322194165633"><a name="p979322194165633"></a><a name="p979322194165633"></a>bool </p>
</td>
</tr>
<tr id="row2123463355165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1609411796165633"><a name="p1609411796165633"></a><a name="p1609411796165633"></a><a href="osalfwblock.md#a383d93123b0d78a8031132d06ff035c5">dataSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p991303494165633"><a name="p991303494165633"></a><a name="p991303494165633"></a>uint32_t </p>
</td>
</tr>
<tr id="row1095696134165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1069420991165633"><a name="p1069420991165633"></a><a name="p1069420991165633"></a><a href="osalfwblock.md#a74631bb4d6242a21146e6465c9640fa8">curOffset</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1441199909165633"><a name="p1441199909165633"></a><a name="p1441199909165633"></a>int32_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1615420802165633"></a>

## **Field **<a name="section576570456165633"></a>

## curOffset<a name="a74631bb4d6242a21146e6465c9640fa8"></a>

```
int32_t OsalFwBlock::curOffset
```

 **Description:**

Offset in the firmware file 

## data<a name="affee01298d0388b9e14da67fd17e6eba"></a>

```
uint8_t* OsalFwBlock::data
```

 **Description:**

Firmware content read this time. You do not need to allocate space. 

## dataSize<a name="a383d93123b0d78a8031132d06ff035c5"></a>

```
uint32_t OsalFwBlock::dataSize
```

 **Description:**

Firmware block size read this time 

## endFlag<a name="ada578cbe9c02da3ebef4e70835d42774"></a>

```
bool OsalFwBlock::endFlag
```

 **Description:**

Whether the firmware file is read completely 

