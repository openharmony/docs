# ImageTrackInfo<a name="ZH-CN_TOPIC_0000001054718131"></a>

-   [Overview](#section1744552881165632)
-   [Summary](#section123137755165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section2111273362165632)
-   [Field](#section1288122154165632)
-   [subImageInfo](#a5c06f24e374fca6adc906aa90c837297)
-   [subImageNum](#ace6e4d15cfb775f2cd22107fd726b677)

## **Overview**<a name="section1744552881165632"></a>

**Related Modules:**

[Format](Format.md)

**Description:**

Defines image stream information. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section123137755165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1251850015165632"></a>
<table><thead align="left"><tr id="row1069876281165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1281192700165632"><a name="p1281192700165632"></a><a name="p1281192700165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1953445051165632"><a name="p1953445051165632"></a><a name="p1953445051165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1566140221165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p281997864165632"><a name="p281997864165632"></a><a name="p281997864165632"></a><a href="ImageTrackInfo.md#ace6e4d15cfb775f2cd22107fd726b677">subImageNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1996687448165632"><a name="p1996687448165632"></a><a name="p1996687448165632"></a>int32_t </p>
</td>
</tr>
<tr id="row1452113714165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1995023681165632"><a name="p1995023681165632"></a><a name="p1995023681165632"></a><a href="ImageTrackInfo.md#a5c06f24e374fca6adc906aa90c837297">subImageInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1952137436165632"><a name="p1952137436165632"></a><a name="p1952137436165632"></a><a href="SubImageInfo.md">SubImageInfo</a> * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2111273362165632"></a>

## **Field **<a name="section1288122154165632"></a>

## subImageInfo<a name="a5c06f24e374fca6adc906aa90c837297"></a>

```
[SubImageInfo](SubImageInfo.md)* ImageTrackInfo::subImageInfo
```

 **Description:**

Detailed information about a sub-image 

## subImageNum<a name="ace6e4d15cfb775f2cd22107fd726b677"></a>

```
int32_t ImageTrackInfo::subImageNum
```

 **Description:**

Number of sub-images 

