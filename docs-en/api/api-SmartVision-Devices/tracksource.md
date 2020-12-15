# TrackSource<a name="EN-US_TOPIC_0000001055078179"></a>

-   [Overview](#section735209042165636)
-   [Summary](#section1973261726165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section1215343180165636)
-   [Field](#section1495104159165636)
-   [audioInfo](#a0cac47bdef450bfb8fd3b8ed882ef674)
-   [dataInfo](#a89cccaaf705df735a3ab8e9792564105)
-   [trackSourceType](#a39d729c668eddbf6b8403b7364e74b61)
-   [videoInfo](#abee3acb91d3005141f11abd87c77aa83)

## **Overview**<a name="section735209042165636"></a>

**Related Modules:**

[Format](format.md)

**Description:**

Defines information about the muxer source. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1973261726165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1075318236165636"></a>
<table><thead align="left"><tr id="row424774808165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2135823359165636"><a name="p2135823359165636"></a><a name="p2135823359165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p658176026165636"><a name="p658176026165636"></a><a name="p658176026165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1048326484165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1084956672165636"><a name="p1084956672165636"></a><a name="p1084956672165636"></a><a href="tracksource.md#a39d729c668eddbf6b8403b7364e74b61">trackSourceType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p360375319165636"><a name="p360375319165636"></a><a name="p360375319165636"></a><a href="format.md#ga953bc46f95d7b2d8866838d792f8f6aa">TrackSourceType</a> </p>
</td>
</tr>
<tr id="row205126070165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p380963129165636"><a name="p380963129165636"></a><a name="p380963129165636"></a><strong id="a7b23279b3033b43e1587fdccbda02359"><a name="a7b23279b3033b43e1587fdccbda02359"></a><a name="a7b23279b3033b43e1587fdccbda02359"></a></strong> union {</p>
</td>
</tr>
<tr id="row1153909488165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1752621646165636"><a name="p1752621646165636"></a><a name="p1752621646165636"></a>   <a href="videotracksourceinfo.md">VideoTrackSourceInfo</a>   <a href="tracksource.md#abee3acb91d3005141f11abd87c77aa83">videoInfo</a></p>
</td>
</tr>
<tr id="row1378898111165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p594879020165636"><a name="p594879020165636"></a><a name="p594879020165636"></a>   <a href="audiotracksourceinfo.md">AudioTrackSourceInfo</a>   <a href="tracksource.md#a0cac47bdef450bfb8fd3b8ed882ef674">audioInfo</a></p>
</td>
</tr>
<tr id="row180047799165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1953158142165636"><a name="p1953158142165636"></a><a name="p1953158142165636"></a>   <a href="datatracksourceinfo.md">DataTrackSourceInfo</a>   <a href="tracksource.md#a89cccaaf705df735a3ab8e9792564105">dataInfo</a></p>
</td>
</tr>
<tr id="row1433933591165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1955446847165636"><a name="p1955446847165636"></a><a name="p1955446847165636"></a><a href="tracksource.md#a7b23279b3033b43e1587fdccbda02359">trackSourceInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1501237829165636"><a name="p1501237829165636"></a><a name="p1501237829165636"></a>} </p>
<p id="p1739241100165636"><a name="p1739241100165636"></a><a name="p1739241100165636"></a>Defines detailed information about different types of stream sources. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1215343180165636"></a>

## **Field **<a name="section1495104159165636"></a>

## audioInfo<a name="a0cac47bdef450bfb8fd3b8ed882ef674"></a>

```
[AudioTrackSourceInfo](audiotracksourceinfo.md) TrackSource::audioInfo
```

 **Description:**

Audio stream. For details, see  [AudioTrackSourceInfo](audiotracksourceinfo.md). 

## dataInfo<a name="a89cccaaf705df735a3ab8e9792564105"></a>

```
[DataTrackSourceInfo](datatracksourceinfo.md) TrackSource::dataInfo
```

 **Description:**

Data stream. For details, see  [DataTrackSourceInfo](datatracksourceinfo.md) 

## trackSourceType<a name="a39d729c668eddbf6b8403b7364e74b61"></a>

```
[TrackSourceType](format.md#ga953bc46f95d7b2d8866838d792f8f6aa) TrackSource::trackSourceType
```

 **Description:**

Stream source type. For details, see  [TrackSourceType](format.md#ga953bc46f95d7b2d8866838d792f8f6aa) 

## videoInfo<a name="abee3acb91d3005141f11abd87c77aa83"></a>

```
[VideoTrackSourceInfo](videotracksourceinfo.md) TrackSource::videoInfo
```

 **Description:**

Video stream. For details, see  [VideoTrackSourceInfo](videotracksourceinfo.md). 

