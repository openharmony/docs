# VideoTrackSourceInfo<a name="ZH-CN_TOPIC_0000001055518130"></a>

-   [Overview](#section1352262344165636)
-   [Summary](#section1798057246165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section1402916045165636)
-   [Field](#section1325198502165636)
-   [bitRate](#a61809ef1608eedcd1cb62b53a835acb2)
-   [codecType](#af5da9e75ec58525d973015237eda6dfc)
-   [frameRate](#ad73d656b0f478e287b305609bc831f52)
-   [height](#a97aff725ec37d360cd3dee5a0050d597)
-   [keyFrameInterval](#a645143b2ac9d6de335300c62aec4c73e)
-   [speed](#a2485907934d8d174860dcb915c8cbef7)
-   [width](#ac05a648fdbc7902c8845b9784398ec70)

## **Overview**<a name="section1352262344165636"></a>

**Related Modules:**

[Format](Format.md)

**Description:**

Defines information about the muxer video source. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1798057246165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table499868024165636"></a>
<table><thead align="left"><tr id="row462056653165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p709760630165636"><a name="p709760630165636"></a><a name="p709760630165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p536628625165636"><a name="p536628625165636"></a><a name="p536628625165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row713402178165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1250131680165636"><a name="p1250131680165636"></a><a name="p1250131680165636"></a><a href="VideoTrackSourceInfo.md#af5da9e75ec58525d973015237eda6dfc">codecType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p563165184165636"><a name="p563165184165636"></a><a name="p563165184165636"></a><a href="Format.md#gaf7ed135f15d4b218d41705bac0122ba7">CodecFormat</a> </p>
</td>
</tr>
<tr id="row523672014165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p345635729165636"><a name="p345635729165636"></a><a name="p345635729165636"></a><a href="VideoTrackSourceInfo.md#ac05a648fdbc7902c8845b9784398ec70">width</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1043660140165636"><a name="p1043660140165636"></a><a name="p1043660140165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row226620620165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p669465837165636"><a name="p669465837165636"></a><a name="p669465837165636"></a><a href="VideoTrackSourceInfo.md#a97aff725ec37d360cd3dee5a0050d597">height</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p148079721165636"><a name="p148079721165636"></a><a name="p148079721165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row669141959165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1260601317165636"><a name="p1260601317165636"></a><a name="p1260601317165636"></a><a href="VideoTrackSourceInfo.md#a61809ef1608eedcd1cb62b53a835acb2">bitRate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p666856751165636"><a name="p666856751165636"></a><a name="p666856751165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1545016474165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2014792234165636"><a name="p2014792234165636"></a><a name="p2014792234165636"></a><a href="VideoTrackSourceInfo.md#ad73d656b0f478e287b305609bc831f52">frameRate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2061043203165636"><a name="p2061043203165636"></a><a name="p2061043203165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row637524923165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1170382815165636"><a name="p1170382815165636"></a><a name="p1170382815165636"></a><a href="VideoTrackSourceInfo.md#a2485907934d8d174860dcb915c8cbef7">speed</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p975289525165636"><a name="p975289525165636"></a><a name="p975289525165636"></a>float </p>
</td>
</tr>
<tr id="row676037835165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p321585366165636"><a name="p321585366165636"></a><a name="p321585366165636"></a><a href="VideoTrackSourceInfo.md#a645143b2ac9d6de335300c62aec4c73e">keyFrameInterval</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1786839245165636"><a name="p1786839245165636"></a><a name="p1786839245165636"></a>uint32_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1402916045165636"></a>

## **Field **<a name="section1325198502165636"></a>

## bitRate<a name="a61809ef1608eedcd1cb62b53a835acb2"></a>

```
uint32_t VideoTrackSourceInfo::bitRate
```

 **Description:**

Encoding bit rate, in bit/s 

## codecType<a name="af5da9e75ec58525d973015237eda6dfc"></a>

```
[CodecFormat](Format.md#gaf7ed135f15d4b218d41705bac0122ba7) VideoTrackSourceInfo::codecType
```

 **Description:**

Video encoding type, for details, see  [CodecFormat](Format.md#gaf7ed135f15d4b218d41705bac0122ba7). 

## frameRate<a name="ad73d656b0f478e287b305609bc831f52"></a>

```
uint32_t VideoTrackSourceInfo::frameRate
```

 **Description:**

Encoding frame rate 

## height<a name="a97aff725ec37d360cd3dee5a0050d597"></a>

```
uint32_t VideoTrackSourceInfo::height
```

 **Description:**

Video height 

## keyFrameInterval<a name="a645143b2ac9d6de335300c62aec4c73e"></a>

```
uint32_t VideoTrackSourceInfo::keyFrameInterval
```

 **Description:**

Keyframe interval 

## speed<a name="a2485907934d8d174860dcb915c8cbef7"></a>

```
float VideoTrackSourceInfo::speed
```

 **Description:**

Video speed 

## width<a name="ac05a648fdbc7902c8845b9784398ec70"></a>

```
uint32_t VideoTrackSourceInfo::width
```

 **Description:**

Video width 

