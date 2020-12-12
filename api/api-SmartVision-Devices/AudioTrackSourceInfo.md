# AudioTrackSourceInfo<a name="ZH-CN_TOPIC_0000001055518078"></a>

-   [Overview](#section857880338165630)
-   [Summary](#section570326748165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section1608966908165630)
-   [Field](#section1553039920165630)
-   [avgBytesPerSec](#aca750f7a7165a35cfa92a6af0c23d771)
-   [channelCount](#a9102735a0ca74b965f1946b5a282ce49)
-   [codecType](#abb7f5e09a8cc552aa558d8da6d45a2b7)
-   [sampleBitWidth](#a4d17b98a1cb944d9e401fb5ea158c72e)
-   [sampleRate](#a1853d9a135862a487c7c612862871b33)
-   [samplesPerFrame](#ab1878c9d95c3f20395d219c662e2ae6f)

## **Overview**<a name="section857880338165630"></a>

**Related Modules:**

[Format](Format.md)

**Description:**

Defines information about the muxer audio source. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section570326748165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1947928010165630"></a>
<table><thead align="left"><tr id="row2079650335165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p494422878165630"><a name="p494422878165630"></a><a name="p494422878165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p366475500165630"><a name="p366475500165630"></a><a name="p366475500165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1434132478165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1726992021165630"><a name="p1726992021165630"></a><a name="p1726992021165630"></a><a href="AudioTrackSourceInfo.md#abb7f5e09a8cc552aa558d8da6d45a2b7">codecType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p206519478165630"><a name="p206519478165630"></a><a name="p206519478165630"></a><a href="Format.md#gaf7ed135f15d4b218d41705bac0122ba7">CodecFormat</a> </p>
</td>
</tr>
<tr id="row1296939895165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1292194458165630"><a name="p1292194458165630"></a><a name="p1292194458165630"></a><a href="AudioTrackSourceInfo.md#a1853d9a135862a487c7c612862871b33">sampleRate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1527781231165630"><a name="p1527781231165630"></a><a name="p1527781231165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row1333313462165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p419289112165630"><a name="p419289112165630"></a><a name="p419289112165630"></a><a href="AudioTrackSourceInfo.md#a9102735a0ca74b965f1946b5a282ce49">channelCount</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1632337105165630"><a name="p1632337105165630"></a><a name="p1632337105165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row391237786165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p940212580165630"><a name="p940212580165630"></a><a name="p940212580165630"></a><a href="AudioTrackSourceInfo.md#a4d17b98a1cb944d9e401fb5ea158c72e">sampleBitWidth</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p779786566165630"><a name="p779786566165630"></a><a name="p779786566165630"></a><a href="Format.md#gadf0700999998f587f0017c4d02977b22">AudioSampleFmt</a> </p>
</td>
</tr>
<tr id="row1350176546165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1949028033165630"><a name="p1949028033165630"></a><a name="p1949028033165630"></a><a href="AudioTrackSourceInfo.md#ab1878c9d95c3f20395d219c662e2ae6f">samplesPerFrame</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1504508863165630"><a name="p1504508863165630"></a><a name="p1504508863165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row1099470452165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1472342781165630"><a name="p1472342781165630"></a><a name="p1472342781165630"></a><a href="AudioTrackSourceInfo.md#aca750f7a7165a35cfa92a6af0c23d771">avgBytesPerSec</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p715990230165630"><a name="p715990230165630"></a><a name="p715990230165630"></a>uint32_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1608966908165630"></a>

## **Field **<a name="section1553039920165630"></a>

## avgBytesPerSec<a name="aca750f7a7165a35cfa92a6af0c23d771"></a>

```
uint32_t AudioTrackSourceInfo::avgBytesPerSec
```

 **Description:**

Average bit rate, in byte/s 

## channelCount<a name="a9102735a0ca74b965f1946b5a282ce49"></a>

```
uint32_t AudioTrackSourceInfo::channelCount
```

 **Description:**

Number of audio channels 

## codecType<a name="abb7f5e09a8cc552aa558d8da6d45a2b7"></a>

```
[CodecFormat](Format.md#gaf7ed135f15d4b218d41705bac0122ba7) AudioTrackSourceInfo::codecType
```

 **Description:**

Audio encoding type, for details, see  [CodecFormat](Format.md#gaf7ed135f15d4b218d41705bac0122ba7). 

## sampleBitWidth<a name="a4d17b98a1cb944d9e401fb5ea158c72e"></a>

```
[AudioSampleFmt](Format.md#gadf0700999998f587f0017c4d02977b22) AudioTrackSourceInfo::sampleBitWidth
```

 **Description:**

Bit width 

## sampleRate<a name="a1853d9a135862a487c7c612862871b33"></a>

```
uint32_t AudioTrackSourceInfo::sampleRate
```

 **Description:**

Sampling rate 

## samplesPerFrame<a name="ab1878c9d95c3f20395d219c662e2ae6f"></a>

```
uint32_t AudioTrackSourceInfo::samplesPerFrame
```

 **Description:**

Number of samples per frame 

