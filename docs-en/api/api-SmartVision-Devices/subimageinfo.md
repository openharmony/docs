# SubImageInfo<a name="EN-US_TOPIC_0000001054718165"></a>

-   [Overview](#section1046388078165636)
-   [Summary](#section686124385165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section418259339165636)
-   [Field](#section1581362409165636)
-   [dataLength](#a6a56c46ceb0f503a7b1c3c70276a84ac)
-   [format](#a1ac1278b26a2e7a99b71d302c9c6ed14)
-   [height](#a81833417dd54630e8d6ce888e2bcebaf)
-   [rotate](#a101a202043f054757b7b24ff48cb1095)
-   [thumbnail](#a27cce274c2816cd851be6eb21b2d6324)
-   [width](#aef3b2ab41d5ff1e928b02fbba76fef36)

## **Overview**<a name="section1046388078165636"></a>

**Related Modules:**

[Format](format.md)

**Description:**

Defines image information. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section686124385165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1382316578165636"></a>
<table><thead align="left"><tr id="row1304000173165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p924689802165636"><a name="p924689802165636"></a><a name="p924689802165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p240186110165636"><a name="p240186110165636"></a><a name="p240186110165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row49212194165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p103600595165636"><a name="p103600595165636"></a><a name="p103600595165636"></a><a href="subimageinfo.md#a1ac1278b26a2e7a99b71d302c9c6ed14">format</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2006499935165636"><a name="p2006499935165636"></a><a name="p2006499935165636"></a><a href="format.md#gaf7ed135f15d4b218d41705bac0122ba7">CodecFormat</a> </p>
</td>
</tr>
<tr id="row1741503495165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p181963518165636"><a name="p181963518165636"></a><a name="p181963518165636"></a><a href="subimageinfo.md#aef3b2ab41d5ff1e928b02fbba76fef36">width</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p400544973165636"><a name="p400544973165636"></a><a name="p400544973165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row4917168165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1102995549165636"><a name="p1102995549165636"></a><a name="p1102995549165636"></a><a href="subimageinfo.md#a81833417dd54630e8d6ce888e2bcebaf">height</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1146752495165636"><a name="p1146752495165636"></a><a name="p1146752495165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row1805717531165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p683415201165636"><a name="p683415201165636"></a><a name="p683415201165636"></a><a href="subimageinfo.md#a101a202043f054757b7b24ff48cb1095">rotate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p675988760165636"><a name="p675988760165636"></a><a name="p675988760165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1558702727165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p482024090165636"><a name="p482024090165636"></a><a name="p482024090165636"></a><a href="subimageinfo.md#a6a56c46ceb0f503a7b1c3c70276a84ac">dataLength</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p113866823165636"><a name="p113866823165636"></a><a name="p113866823165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1712050545165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2136036659165636"><a name="p2136036659165636"></a><a name="p2136036659165636"></a><a href="subimageinfo.md#a27cce274c2816cd851be6eb21b2d6324">thumbnail</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1715522391165636"><a name="p1715522391165636"></a><a name="p1715522391165636"></a>bool </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section418259339165636"></a>

## **Field **<a name="section1581362409165636"></a>

## dataLength<a name="a6a56c46ceb0f503a7b1c3c70276a84ac"></a>

```
uint32_t SubImageInfo::dataLength
```

 **Description:**

Image size 

## format<a name="a1ac1278b26a2e7a99b71d302c9c6ed14"></a>

```
[CodecFormat](format.md#gaf7ed135f15d4b218d41705bac0122ba7) SubImageInfo::format
```

 **Description:**

Image encoding format. For details, see  [CodecFormat](format.md#gaf7ed135f15d4b218d41705bac0122ba7). 

## height<a name="a81833417dd54630e8d6ce888e2bcebaf"></a>

```
uint16_t SubImageInfo::height
```

 **Description:**

Height, in pixels 

## rotate<a name="a101a202043f054757b7b24ff48cb1095"></a>

```
uint32_t SubImageInfo::rotate
```

 **Description:**

Image rotation angle. The value can be  **90**,  **180**, or  **270**. The default value is  **0**. 

## thumbnail<a name="a27cce274c2816cd851be6eb21b2d6324"></a>

```
bool SubImageInfo::thumbnail
```

 **Description:**

Thumbnail flag 

## width<a name="aef3b2ab41d5ff1e928b02fbba76fef36"></a>

```
uint16_t SubImageInfo::width
```

 **Description:**

Width, in pixels 

