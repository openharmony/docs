# VideoTrackInfo<a name="ZH-CN_TOPIC_0000001055678134"></a>

-   [Overview](#section1574075901165636)
-   [Summary](#section624473362165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section202472917165636)
-   [Field](#section1507177165165636)
-   [bitrate](#a62bf491fa162c1b41c8ab3f8034c78a4)
-   [durationMs](#ade7b28ac81909b6578a5b7df05f0a57c)
-   [format](#a6c1972b11cd0dccb6dcfb5a5f9be960f)
-   [fpsDen](#ac2340827ee1c6faac89fec69deb1f909)
-   [fpsNum](#a2534734c1e6fd5aeaa598fb697bdce16)
-   [height](#a6f23a6eb3e140c8d5c88067a9517ccad)
-   [profile](#ae88938813de34933b48a0bf4c784d13e)
-   [rotate](#a075619b83522eb991e8349bafe042455)
-   [width](#aeb35e568d32f0e62ff156cd0add506e5)

## **Overview**<a name="section1574075901165636"></a>

**Related Modules:**

[Format](Format.md)

**Description:**

Defines video track information. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section624473362165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1277686017165636"></a>
<table><thead align="left"><tr id="row1291302308165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2038007009165636"><a name="p2038007009165636"></a><a name="p2038007009165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p232145711165636"><a name="p232145711165636"></a><a name="p232145711165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row401785446165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2095893300165636"><a name="p2095893300165636"></a><a name="p2095893300165636"></a><a href="VideoTrackInfo.md#a6c1972b11cd0dccb6dcfb5a5f9be960f">format</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p731609312165636"><a name="p731609312165636"></a><a name="p731609312165636"></a><a href="Format.md#gaf7ed135f15d4b218d41705bac0122ba7">CodecFormat</a> </p>
</td>
</tr>
<tr id="row1315378088165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p44393297165636"><a name="p44393297165636"></a><a name="p44393297165636"></a><a href="VideoTrackInfo.md#ae88938813de34933b48a0bf4c784d13e">profile</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1618133206165636"><a name="p1618133206165636"></a><a name="p1618133206165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row1934070173165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1747323722165636"><a name="p1747323722165636"></a><a name="p1747323722165636"></a><a href="VideoTrackInfo.md#aeb35e568d32f0e62ff156cd0add506e5">width</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p179094148165636"><a name="p179094148165636"></a><a name="p179094148165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row1618380632165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p423749129165636"><a name="p423749129165636"></a><a name="p423749129165636"></a><a href="VideoTrackInfo.md#a6f23a6eb3e140c8d5c88067a9517ccad">height</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1233168009165636"><a name="p1233168009165636"></a><a name="p1233168009165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row1560765179165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1978312622165636"><a name="p1978312622165636"></a><a name="p1978312622165636"></a><a href="VideoTrackInfo.md#a2534734c1e6fd5aeaa598fb697bdce16">fpsNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p130423651165636"><a name="p130423651165636"></a><a name="p130423651165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row1423890170165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1284893813165636"><a name="p1284893813165636"></a><a name="p1284893813165636"></a><a href="VideoTrackInfo.md#ac2340827ee1c6faac89fec69deb1f909">fpsDen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p368368683165636"><a name="p368368683165636"></a><a name="p368368683165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row1818842376165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p584416258165636"><a name="p584416258165636"></a><a name="p584416258165636"></a><a href="VideoTrackInfo.md#a62bf491fa162c1b41c8ab3f8034c78a4">bitrate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1414113839165636"><a name="p1414113839165636"></a><a name="p1414113839165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1289987933165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p664944903165636"><a name="p664944903165636"></a><a name="p664944903165636"></a><a href="VideoTrackInfo.md#a075619b83522eb991e8349bafe042455">rotate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1668237199165636"><a name="p1668237199165636"></a><a name="p1668237199165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1986485287165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1031687444165636"><a name="p1031687444165636"></a><a name="p1031687444165636"></a><a href="VideoTrackInfo.md#ade7b28ac81909b6578a5b7df05f0a57c">durationMs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p390303377165636"><a name="p390303377165636"></a><a name="p390303377165636"></a>int64_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section202472917165636"></a>

## **Field **<a name="section1507177165165636"></a>

## bitrate<a name="a62bf491fa162c1b41c8ab3f8034c78a4"></a>

```
uint32_t VideoTrackInfo::bitrate
```

 **Description:**

<Video bit rate, in bit/s 

## durationMs<a name="ade7b28ac81909b6578a5b7df05f0a57c"></a>

```
int64_t VideoTrackInfo::durationMs
```

 **Description:**

Track duration, in milliseconds 

## format<a name="a6c1972b11cd0dccb6dcfb5a5f9be960f"></a>

```
[CodecFormat](Format.md#gaf7ed135f15d4b218d41705bac0122ba7) VideoTrackInfo::format
```

 **Description:**

Video encoding format. For details, see  [CodecFormat](Format.md#gaf7ed135f15d4b218d41705bac0122ba7). 

## fpsDen<a name="ac2340827ee1c6faac89fec69deb1f909"></a>

```
uint16_t VideoTrackInfo::fpsDen
```

 **Description:**

Denominator of the frame rate 

## fpsNum<a name="a2534734c1e6fd5aeaa598fb697bdce16"></a>

```
uint16_t VideoTrackInfo::fpsNum
```

 **Description:**

Numerator of the frame rate 

## height<a name="a6f23a6eb3e140c8d5c88067a9517ccad"></a>

```
uint16_t VideoTrackInfo::height
```

 **Description:**

Height, in pixels 

## profile<a name="ae88938813de34933b48a0bf4c784d13e"></a>

```
uint16_t VideoTrackInfo::profile
```

 **Description:**

Profile 

## rotate<a name="a075619b83522eb991e8349bafe042455"></a>

```
uint32_t VideoTrackInfo::rotate
```

 **Description:**

Video rotation angle. The value can be  **90**,  **180**, or  **270**. The default value is  **0**. 

## width<a name="aeb35e568d32f0e62ff156cd0add506e5"></a>

```
uint16_t VideoTrackInfo::width
```

 **Description:**

Width, in pixels 

