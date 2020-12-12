# TrackInfo<a name="EN-US_TOPIC_0000001055358148"></a>

-   [Overview](#section356081685165636)
-   [Summary](#section1006894799165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section1984291573165636)
-   [Field](#section258879702165636)
-   [audTrack](#a491fd1e304e19924d5d1c81aa07c3425)
-   [imgTrack](#a6c7a67bd3651140b5551e407aa07fccc)
-   [item](#a6548bea85adbb29bd0a4029a1d6f1c1c)
-   [itemCnt](#aa3140178f070f85c2c778410b96db77a)
-   [subTrack](#a3ae6adfd7981cd2e87223fb2d47f2805)
-   [trackId](#aeb352032456b0841382a015d6f256529)
-   [trackType](#a8b7ca46e972b746fb3f7a634cd07d6c4)
-   [vidTrack](#aaa84d3f413e5d742953e6ba0d0a35276)

## **Overview**<a name="section356081685165636"></a>

**Related Modules:**

[Format](format.md)

**Description:**

Defines track information. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1006894799165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table153039875165636"></a>
<table><thead align="left"><tr id="row196146953165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p155895776165636"><a name="p155895776165636"></a><a name="p155895776165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1562676806165636"><a name="p1562676806165636"></a><a name="p1562676806165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row726057853165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p556436346165636"><a name="p556436346165636"></a><a name="p556436346165636"></a><a href="trackinfo.md#a8b7ca46e972b746fb3f7a634cd07d6c4">trackType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1144688719165636"><a name="p1144688719165636"></a><a name="p1144688719165636"></a><a href="format.md#gad80740dd555f7d3688d2c4d9f44d3b04">TrackType</a> </p>
</td>
</tr>
<tr id="row240226356165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1149774443165636"><a name="p1149774443165636"></a><a name="p1149774443165636"></a><a href="trackinfo.md#aeb352032456b0841382a015d6f256529">trackId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1221984258165636"><a name="p1221984258165636"></a><a name="p1221984258165636"></a>int32_t </p>
</td>
</tr>
<tr id="row1560651143165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p757997407165636"><a name="p757997407165636"></a><a name="p757997407165636"></a><a href="trackinfo.md#aa3140178f070f85c2c778410b96db77a">itemCnt</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1742087245165636"><a name="p1742087245165636"></a><a name="p1742087245165636"></a>int32_t </p>
</td>
</tr>
<tr id="row1510728303165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1320286307165636"><a name="p1320286307165636"></a><a name="p1320286307165636"></a><a href="trackinfo.md#a6548bea85adbb29bd0a4029a1d6f1c1c">item</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p882350588165636"><a name="p882350588165636"></a><a name="p882350588165636"></a><a href="parameteritem.md">ParameterItem</a> * </p>
</td>
</tr>
<tr id="row9016420165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2109098283165636"><a name="p2109098283165636"></a><a name="p2109098283165636"></a><a href="trackinfo.md#aaa84d3f413e5d742953e6ba0d0a35276">vidTrack</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1812481773165636"><a name="p1812481773165636"></a><a name="p1812481773165636"></a><a href="videotrackinfo.md">VideoTrackInfo</a> </p>
</td>
</tr>
<tr id="row1550977522165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p712074012165636"><a name="p712074012165636"></a><a name="p712074012165636"></a><a href="trackinfo.md#a491fd1e304e19924d5d1c81aa07c3425">audTrack</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2030060717165636"><a name="p2030060717165636"></a><a name="p2030060717165636"></a><a href="audiotrackinfo.md">AudioTrackInfo</a> </p>
</td>
</tr>
<tr id="row1592917977165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p36765192165636"><a name="p36765192165636"></a><a name="p36765192165636"></a><a href="trackinfo.md#a3ae6adfd7981cd2e87223fb2d47f2805">subTrack</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1099322210165636"><a name="p1099322210165636"></a><a name="p1099322210165636"></a><a href="subtitletrackinfo.md">SubtitleTrackInfo</a> </p>
</td>
</tr>
<tr id="row1329422804165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1177369268165636"><a name="p1177369268165636"></a><a name="p1177369268165636"></a><a href="trackinfo.md#a6c7a67bd3651140b5551e407aa07fccc">imgTrack</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2034155330165636"><a name="p2034155330165636"></a><a name="p2034155330165636"></a><a href="imagetrackinfo.md">ImageTrackInfo</a> </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1984291573165636"></a>

## **Field **<a name="section258879702165636"></a>

## audTrack<a name="a491fd1e304e19924d5d1c81aa07c3425"></a>

```
[AudioTrackInfo](audiotrackinfo.md) TrackInfo::audTrack
```

 **Description:**

Audio track information 

## imgTrack<a name="a6c7a67bd3651140b5551e407aa07fccc"></a>

```
[ImageTrackInfo](imagetrackinfo.md) TrackInfo::imgTrack
```

 **Description:**

Image track information 

## item<a name="a6548bea85adbb29bd0a4029a1d6f1c1c"></a>

```
[ParameterItem](parameteritem.md)* TrackInfo::item
```

 **Description:**

Pointer to the array of extra track information, including HDR, DRM, and CAS 

## itemCnt<a name="aa3140178f070f85c2c778410b96db77a"></a>

```
int32_t TrackInfo::itemCnt
```

 **Description:**

Number of extra track information entries 

## subTrack<a name="a3ae6adfd7981cd2e87223fb2d47f2805"></a>

```
[SubtitleTrackInfo](subtitletrackinfo.md) TrackInfo::subTrack
```

 **Description:**

Subtitle track information 

## trackId<a name="aeb352032456b0841382a015d6f256529"></a>

```
int32_t TrackInfo::trackId
```

 **Description:**

Track index 

## trackType<a name="a8b7ca46e972b746fb3f7a634cd07d6c4"></a>

```
[TrackType](format.md#gad80740dd555f7d3688d2c4d9f44d3b04) TrackInfo::trackType
```

 **Description:**

Track type. For details, see  [TrackType](format.md#gad80740dd555f7d3688d2c4d9f44d3b04) 

## vidTrack<a name="aaa84d3f413e5d742953e6ba0d0a35276"></a>

```
[VideoTrackInfo](videotrackinfo.md) TrackInfo::vidTrack
```

 **Description:**

Video track information 

