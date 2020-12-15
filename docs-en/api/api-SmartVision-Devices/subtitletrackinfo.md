# SubtitleTrackInfo<a name="EN-US_TOPIC_0000001055678132"></a>

-   [Overview](#section860295795165636)
-   [Summary](#section1449578668165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section107940712165636)
-   [Field](#section1828222786165636)
-   [charSet](#a71f5455adc1defa10b4f292dede95f58)
-   [format](#a8f0db970e60f19d5deb18fbbdbc7ea28)
-   [language](#abb57b361b445696d272cf8bb54cb12d0)
-   [originalFrameHeight](#a70c3d91bb8b6d8e79a22fe0206130a2f)
-   [originalFrameWidth](#a7d5cefc1e9f402657c2f9c2950688472)

## **Overview**<a name="section860295795165636"></a>

**Related Modules:**

[Format](format.md)

**Description:**

Defines subtitle stream information. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1449578668165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table595094308165636"></a>
<table><thead align="left"><tr id="row1595881816165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p834095310165636"><a name="p834095310165636"></a><a name="p834095310165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1069788195165636"><a name="p1069788195165636"></a><a name="p1069788195165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row196668182165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1450171382165636"><a name="p1450171382165636"></a><a name="p1450171382165636"></a><a href="subtitletrackinfo.md#a8f0db970e60f19d5deb18fbbdbc7ea28">format</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1523667424165636"><a name="p1523667424165636"></a><a name="p1523667424165636"></a><a href="format.md#gadac45ce4731516c262292c15433439b3">SubtitleFormat</a> </p>
</td>
</tr>
<tr id="row495363172165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1196671282165636"><a name="p1196671282165636"></a><a name="p1196671282165636"></a><a href="subtitletrackinfo.md#a71f5455adc1defa10b4f292dede95f58">charSet</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p361901637165636"><a name="p361901637165636"></a><a name="p361901637165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1411285524165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p365659353165636"><a name="p365659353165636"></a><a name="p365659353165636"></a><a href="subtitletrackinfo.md#abb57b361b445696d272cf8bb54cb12d0">language</a> [<a href="format.md#gac2d2d077edb8e9bb9f85ab6350015c5b">FORMAT_MAX_LANGUAGE_NUM</a>][<a href="format.md#gaa70508bb1089c99f9aa3d59fcbdfa8eb">FORMAT_LANGUAGE_LEN</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1359810914165636"><a name="p1359810914165636"></a><a name="p1359810914165636"></a>char </p>
</td>
</tr>
<tr id="row1335737493165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p254535958165636"><a name="p254535958165636"></a><a name="p254535958165636"></a><a href="subtitletrackinfo.md#a7d5cefc1e9f402657c2f9c2950688472">originalFrameWidth</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p638529911165636"><a name="p638529911165636"></a><a name="p638529911165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row1602257229165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p383676513165636"><a name="p383676513165636"></a><a name="p383676513165636"></a><a href="subtitletrackinfo.md#a70c3d91bb8b6d8e79a22fe0206130a2f">originalFrameHeight</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1459178614165636"><a name="p1459178614165636"></a><a name="p1459178614165636"></a>uint16_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section107940712165636"></a>

## **Field **<a name="section1828222786165636"></a>

## charSet<a name="a71f5455adc1defa10b4f292dede95f58"></a>

```
uint32_t SubtitleTrackInfo::charSet
```

 **Description:**

Character encoding format 

## format<a name="a8f0db970e60f19d5deb18fbbdbc7ea28"></a>

```
[SubtitleFormat](format.md#gadac45ce4731516c262292c15433439b3) SubtitleTrackInfo::format
```

 **Description:**

Subtitle encoding and decoding format. For details, see  [SubtitleFormat](format.md#gadac45ce4731516c262292c15433439b3) 

## language<a name="abb57b361b445696d272cf8bb54cb12d0"></a>

```
char SubtitleTrackInfo::language[[FORMAT_MAX_LANGUAGE_NUM](format.md#gac2d2d077edb8e9bb9f85ab6350015c5b)][[FORMAT_LANGUAGE_LEN](format.md#gaa70508bb1089c99f9aa3d59fcbdfa8eb)]
```

 **Description:**

Subtitle language 

## originalFrameHeight<a name="a70c3d91bb8b6d8e79a22fe0206130a2f"></a>

```
uint16_t SubtitleTrackInfo::originalFrameHeight
```

 **Description:**

Height of the original image. This variable is valid for the image subtitle. 

## originalFrameWidth<a name="a7d5cefc1e9f402657c2f9c2950688472"></a>

```
uint16_t SubtitleTrackInfo::originalFrameWidth
```

 **Description:**

Width of the original image. This variable is valid for the image subtitle. 

