# AudioCapture<a name="ZH-CN_TOPIC_0000001055358098"></a>

-   [Overview](#section1508227372165630)
-   [Summary](#section1685488375165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section2098671874165630)
-   [Field](#section655888037165630)
-   [CaptureFrame](#a89f1baf4b6177f91b9135e86cc8681da)
-   [GetCapturePosition](#ad307fd1eca38f257f865c1316db6e5d5)

## **Overview**<a name="section1508227372165630"></a>

**Related Modules:**

[Audio](Audio.md)

**Description:**

Provides capabilities for audio capturing, including controlling the capturing, setting audio attributes, scenes, and volume, and capturing audio frames. 

See also
:   [AudioControl](AudioControl.md) 

:    [AudioAttribute](AudioAttribute.md) 

:    [AudioScene](AudioScene.md) 

:    [AudioVolume](AudioVolume.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1685488375165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table569602508165630"></a>
<table><thead align="left"><tr id="row172285453165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p74744830165630"><a name="p74744830165630"></a><a name="p74744830165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1083569289165630"><a name="p1083569289165630"></a><a name="p1083569289165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row210988567165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1956959387165630"><a name="p1956959387165630"></a><a name="p1956959387165630"></a>control </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p60790403165630"><a name="p60790403165630"></a><a name="p60790403165630"></a><strong id="a3722b1e55fa79af775b5d3acd08f29c4"><a name="a3722b1e55fa79af775b5d3acd08f29c4"></a><a name="a3722b1e55fa79af775b5d3acd08f29c4"></a></strong> struct <a href="AudioControl.md">AudioControl</a> </p>
<p id="p2015637552165630"><a name="p2015637552165630"></a><a name="p2015637552165630"></a>Defines the audio control. For details, see <a href="AudioControl.md">AudioControl</a>. </p>
</td>
</tr>
<tr id="row1980761153165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1300432836165630"><a name="p1300432836165630"></a><a name="p1300432836165630"></a>attr </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1733046245165630"><a name="p1733046245165630"></a><a name="p1733046245165630"></a><strong id="a3b1231763ecdab4d60809048136ae017"><a name="a3b1231763ecdab4d60809048136ae017"></a><a name="a3b1231763ecdab4d60809048136ae017"></a></strong> struct <a href="AudioAttribute.md">AudioAttribute</a> </p>
<p id="p1400430510165630"><a name="p1400430510165630"></a><a name="p1400430510165630"></a>Defines the audio attribute. For details, see <a href="AudioAttribute.md">AudioAttribute</a>. </p>
</td>
</tr>
<tr id="row2078626241165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p742449053165630"><a name="p742449053165630"></a><a name="p742449053165630"></a>scene </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p3653311165630"><a name="p3653311165630"></a><a name="p3653311165630"></a><strong id="a55ba54428fc285c97032ce27ae0ab4aa"><a name="a55ba54428fc285c97032ce27ae0ab4aa"></a><a name="a55ba54428fc285c97032ce27ae0ab4aa"></a></strong> struct <a href="AudioScene.md">AudioScene</a> </p>
<p id="p827282717165630"><a name="p827282717165630"></a><a name="p827282717165630"></a>Defines the audio scene. For details, see <a href="AudioScene.md">AudioScene</a>. </p>
</td>
</tr>
<tr id="row1677913329165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2008954166165630"><a name="p2008954166165630"></a><a name="p2008954166165630"></a>volume </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2001570132165630"><a name="p2001570132165630"></a><a name="p2001570132165630"></a><strong id="a066923e8aff005d677c7b7c33a036f41"><a name="a066923e8aff005d677c7b7c33a036f41"></a><a name="a066923e8aff005d677c7b7c33a036f41"></a></strong> struct <a href="AudioVolume.md">AudioVolume</a> </p>
<p id="p291840025165630"><a name="p291840025165630"></a><a name="p291840025165630"></a>Defines audio volume. For details, see <a href="AudioVolume.md">AudioVolume</a>. </p>
</td>
</tr>
<tr id="row2113068896165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1824437910165630"><a name="p1824437910165630"></a><a name="p1824437910165630"></a><a href="AudioCapture.md#a89f1baf4b6177f91b9135e86cc8681da">CaptureFrame</a> )(struct <a href="AudioCapture.md">AudioCapture</a> *capture, void *frame, uint64_t requestBytes, uint64_t *replyBytes)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p143108336165630"><a name="p143108336165630"></a><a name="p143108336165630"></a>int32_t(* </p>
<p id="p1351518203165630"><a name="p1351518203165630"></a><a name="p1351518203165630"></a>Reads a frame of input data (uplink data) from the audio driver for capturing. </p>
</td>
</tr>
<tr id="row909738583165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1457912118165630"><a name="p1457912118165630"></a><a name="p1457912118165630"></a><a href="AudioCapture.md#ad307fd1eca38f257f865c1316db6e5d5">GetCapturePosition</a> )(struct <a href="AudioCapture.md">AudioCapture</a> *capture, uint64_t *frames, struct <a href="AudioTimeStamp.md">AudioTimeStamp</a> *<a href="TIME.md#gae7841e681c8c9d59818568d39553642c">time</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1342911351165630"><a name="p1342911351165630"></a><a name="p1342911351165630"></a>int32_t(* </p>
<p id="p678731176165630"><a name="p678731176165630"></a><a name="p678731176165630"></a>Obtains the last number of input audio frames. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2098671874165630"></a>

## **Field **<a name="section655888037165630"></a>

## CaptureFrame<a name="a89f1baf4b6177f91b9135e86cc8681da"></a>

```
int32_t(* AudioCapture::CaptureFrame) (struct [AudioCapture](AudioCapture.md) *capture, void *frame, uint64_t requestBytes, uint64_t *replyBytes)
```

 **Description:**

Reads a frame of input data \(uplink data\) from the audio driver for capturing. 

**Parameters:**

<a name="table646465127165630"></a>
<table><thead align="left"><tr id="row1836835386165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1416518623165630"><a name="p1416518623165630"></a><a name="p1416518623165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1599073410165630"><a name="p1599073410165630"></a><a name="p1599073410165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row153155045165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">capture</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b1153262080165630"><a name="b1153262080165630"></a><a name="b1153262080165630"></a><a href="AudioCapture.md">AudioCapture</a></strong> object to operate. </td>
</tr>
<tr id="row1356075329165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">frame</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the input data to read. </td>
</tr>
<tr id="row353484416165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">requestBytes</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the input data, in bytes. </td>
</tr>
<tr id="row1234347410165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">replyBytes</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the actual length (in bytes) of the audio data to read. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the input data is read successfully; returns a negative value otherwise. 

## GetCapturePosition<a name="ad307fd1eca38f257f865c1316db6e5d5"></a>

```
int32_t(* AudioCapture::GetCapturePosition) (struct [AudioCapture](AudioCapture.md) *capture, uint64_t *frames, struct [AudioTimeStamp](AudioTimeStamp.md) *[time](TIME.md#gae7841e681c8c9d59818568d39553642c))
```

 **Description:**

Obtains the last number of input audio frames. 

**Parameters:**

<a name="table267149435165630"></a>
<table><thead align="left"><tr id="row1006537338165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1294646800165630"><a name="p1294646800165630"></a><a name="p1294646800165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p216567187165630"><a name="p216567187165630"></a><a name="p216567187165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1290230423165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">capture</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b666205316165630"><a name="b666205316165630"></a><a name="b666205316165630"></a><a href="AudioCapture.md">AudioCapture</a></strong> object to operate. </td>
</tr>
<tr id="row243601487165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">frames</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the last number of input audio frames. </td>
</tr>
<tr id="row674964067165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">time</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the timestamp associated with the frame. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the last number is obtained; returns a negative value otherwise. 

**See also:**

[CaptureFrame](AudioCapture.md#a89f1baf4b6177f91b9135e86cc8681da) 

