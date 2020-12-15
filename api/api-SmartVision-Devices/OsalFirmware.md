# OsalFirmware<a name="ZH-CN_TOPIC_0000001054718141"></a>

-   [Overview](#section521004557165633)
-   [Summary](#section961483112165633)
-   [Data Fields](#pub-attribs)
-   [Details](#section1150528670165633)
-   [Field](#section1475257401165633)
-   [fwSize](#abc1fab9dde51713c504936594369d067)
-   [para](#a11f428199ca9e9e4f94c1ef7c2bdea11)

## **Overview**<a name="section521004557165633"></a>

**Related Modules:**

[OSAL](OSAL.md)

**Description:**

Defines the data structure for operating a firmware file. 

## **Summary**<a name="section961483112165633"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table921123992165633"></a>
<table><thead align="left"><tr id="row130390102165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p596062142165633"><a name="p596062142165633"></a><a name="p596062142165633"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p766977681165633"><a name="p766977681165633"></a><a name="p766977681165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2109972556165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1715391617165633"><a name="p1715391617165633"></a><a name="p1715391617165633"></a><a href="OsalFirmware.md#abc1fab9dde51713c504936594369d067">fwSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1322965289165633"><a name="p1322965289165633"></a><a name="p1322965289165633"></a>uint32_t </p>
</td>
</tr>
<tr id="row644661307165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1657671684165633"><a name="p1657671684165633"></a><a name="p1657671684165633"></a><a href="OsalFirmware.md#a11f428199ca9e9e4f94c1ef7c2bdea11">para</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1868000485165633"><a name="p1868000485165633"></a><a name="p1868000485165633"></a>void * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1150528670165633"></a>

## **Field **<a name="section1475257401165633"></a>

## fwSize<a name="abc1fab9dde51713c504936594369d067"></a>

```
uint32_t OsalFirmware::fwSize
```

 **Description:**

Firmware file size, which is returned by calling  [OsalRequestFirmware](OSAL.md#ga428b9de7fb95a20ab9e25b47a7d4272c). 

## para<a name="a11f428199ca9e9e4f94c1ef7c2bdea11"></a>

```
void* OsalFirmware::para
```

 **Description:**

Pointer to a firmware file, which is returned by calling  [OsalRequestFirmware](OSAL.md#ga428b9de7fb95a20ab9e25b47a7d4272c). You do not need to allocate space. 

