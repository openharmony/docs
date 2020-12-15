# AudioTrackInfo<a name="ZH-CN_TOPIC_0000001055678082"></a>

-   [Overview](#section383083123165630)
-   [Summary](#section550070999165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section160263714165630)
-   [Field](#section1710969037165630)
-   [bitrate](#a5e5683087b9272d3ee346180ca199afa)
-   [channels](#a4468c447f3ad0673c6d06590ff764099)
-   [durationMs](#a67862089989d0fae5fd35312ed5287fe)
-   [format](#ae7b9c8bf17575184f4027cbe55b7c0a9)
-   [language](#ac7d6fb077c4ef6f2c14737fef8f92ba7)
-   [profile](#a87acdd081cb338b01364e1ced4c132aa)
-   [sampleFmt](#a5a4778ebb70d50bc91f250ae6254ab26)
-   [sampleRate](#a7504ddf6a446c7e157eeb015194e2db8)
-   [subStreamID](#a682193c30bd99445980e3a8d591bb0ae)

## **Overview**<a name="section383083123165630"></a>

**Related Modules:**

[Format](Format.md)

**Description:**

Defines audio track information. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section550070999165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1913754128165630"></a>
<table><thead align="left"><tr id="row637329224165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1592491254165630"><a name="p1592491254165630"></a><a name="p1592491254165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1232311847165630"><a name="p1232311847165630"></a><a name="p1232311847165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row593027325165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1758646818165630"><a name="p1758646818165630"></a><a name="p1758646818165630"></a><a href="AudioTrackInfo.md#ae7b9c8bf17575184f4027cbe55b7c0a9">format</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p957080990165630"><a name="p957080990165630"></a><a name="p957080990165630"></a><a href="Format.md#gaf7ed135f15d4b218d41705bac0122ba7">CodecFormat</a> </p>
</td>
</tr>
<tr id="row360703335165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1676792485165630"><a name="p1676792485165630"></a><a name="p1676792485165630"></a><a href="AudioTrackInfo.md#a87acdd081cb338b01364e1ced4c132aa">profile</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1228167615165630"><a name="p1228167615165630"></a><a name="p1228167615165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row1463751543165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1983975352165630"><a name="p1983975352165630"></a><a name="p1983975352165630"></a><a href="AudioTrackInfo.md#a7504ddf6a446c7e157eeb015194e2db8">sampleRate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1113230733165630"><a name="p1113230733165630"></a><a name="p1113230733165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row894231661165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1547750072165630"><a name="p1547750072165630"></a><a name="p1547750072165630"></a><a href="AudioTrackInfo.md#a5a4778ebb70d50bc91f250ae6254ab26">sampleFmt</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1240692784165630"><a name="p1240692784165630"></a><a name="p1240692784165630"></a>uint16_t </p>
</td>
</tr>
<tr id="row1961303445165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1457788921165630"><a name="p1457788921165630"></a><a name="p1457788921165630"></a><a href="AudioTrackInfo.md#a4468c447f3ad0673c6d06590ff764099">channels</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p54026063165630"><a name="p54026063165630"></a><a name="p54026063165630"></a>uint16_t </p>
</td>
</tr>
<tr id="row1919176094165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1753679308165630"><a name="p1753679308165630"></a><a name="p1753679308165630"></a><a href="AudioTrackInfo.md#a682193c30bd99445980e3a8d591bb0ae">subStreamID</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p374517900165630"><a name="p374517900165630"></a><a name="p374517900165630"></a>int32_t </p>
</td>
</tr>
<tr id="row61780465165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p493538331165630"><a name="p493538331165630"></a><a name="p493538331165630"></a><a href="AudioTrackInfo.md#a5e5683087b9272d3ee346180ca199afa">bitrate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1991386312165630"><a name="p1991386312165630"></a><a name="p1991386312165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row952557950165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2064246857165630"><a name="p2064246857165630"></a><a name="p2064246857165630"></a><a href="AudioTrackInfo.md#ac7d6fb077c4ef6f2c14737fef8f92ba7">language</a> [<a href="Format.md#gaa70508bb1089c99f9aa3d59fcbdfa8eb">FORMAT_LANGUAGE_LEN</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1667413635165630"><a name="p1667413635165630"></a><a name="p1667413635165630"></a>char </p>
</td>
</tr>
<tr id="row1138328144165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1215398927165630"><a name="p1215398927165630"></a><a name="p1215398927165630"></a><a href="AudioTrackInfo.md#a67862089989d0fae5fd35312ed5287fe">durationMs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p552658326165630"><a name="p552658326165630"></a><a name="p552658326165630"></a>int64_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section160263714165630"></a>

## **Field **<a name="section1710969037165630"></a>

## bitrate<a name="a5e5683087b9272d3ee346180ca199afa"></a>

```
uint32_t AudioTrackInfo::bitrate
```

 **Description:**

Audio and video bit rate 

## channels<a name="a4468c447f3ad0673c6d06590ff764099"></a>

```
uint16_t AudioTrackInfo::channels
```

 **Description:**

Number of audio channels 

## durationMs<a name="a67862089989d0fae5fd35312ed5287fe"></a>

```
int64_t AudioTrackInfo::durationMs
```

 **Description:**

Stream duration, in milliseconds 

## format<a name="ae7b9c8bf17575184f4027cbe55b7c0a9"></a>

```
[CodecFormat](Format.md#gaf7ed135f15d4b218d41705bac0122ba7) AudioTrackInfo::format
```

 **Description:**

Audio encoding format. For details, see  [CodecFormat](Format.md#gaf7ed135f15d4b218d41705bac0122ba7). 

## language<a name="ac7d6fb077c4ef6f2c14737fef8f92ba7"></a>

```
char AudioTrackInfo::language[[FORMAT_LANGUAGE_LEN](Format.md#gaa70508bb1089c99f9aa3d59fcbdfa8eb)]
```

 **Description:**

Audio track language 

## profile<a name="a87acdd081cb338b01364e1ced4c132aa"></a>

```
uint32_t AudioTrackInfo::profile
```

 **Description:**

Audio encoding profile, for example,  **0x160\(WMAV1\)**  and  **0x161 \(WMAV2\)**. 

## sampleFmt<a name="a5a4778ebb70d50bc91f250ae6254ab26"></a>

```
uint16_t AudioTrackInfo::sampleFmt
```

 **Description:**

Data storage format of one sample in an audio channel. For details, see  [AudioSampleFmt](Format.md#gadf0700999998f587f0017c4d02977b22). 

## sampleRate<a name="a7504ddf6a446c7e157eeb015194e2db8"></a>

```
uint32_t AudioTrackInfo::sampleRate
```

 **Description:**

Audio sampling rate, for example,  **8000**,  **16000**,  **24000**,  **32000**,  **11025**,  **22050**,  **441000**, and  **48000** 

## subStreamID<a name="a682193c30bd99445980e3a8d591bb0ae"></a>

```
int32_t AudioTrackInfo::subStreamID
```

 **Description:**

ID of the subsidiary audio stream, which is used when the encoding or decoding format of the primary stream is not supported for audio rendering. 

