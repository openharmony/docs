# OHOS::Media::FrameStateCallback<a name="EN-US_TOPIC_0000001055078153"></a>

-   [Overview](#section1027762142165632)
-   [Summary](#section280971760165632)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1027762142165632"></a>

**Related Modules:**

[MultiMedia\_FrameStateCallback](multimedia_framestatecallback.md)

**Description:**

Provides functions to listen for frame states and response to the state changes. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section280971760165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table555438848165632"></a>
<table><thead align="left"><tr id="row1895226050165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p350748329165632"><a name="p350748329165632"></a><a name="p350748329165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1782273999165632"><a name="p1782273999165632"></a><a name="p1782273999165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row821138065165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1449434790165632"><a name="p1449434790165632"></a><a name="p1449434790165632"></a><a href="multimedia_framestatecallback.md#gab2557f65a2744911b66361a895450d67">FrameStateCallback</a> ()=default</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p938733221165632"><a name="p938733221165632"></a><a name="p938733221165632"></a> </p>
<p id="p633353240165632"><a name="p633353240165632"></a><a name="p633353240165632"></a>A constructor used to create a <strong id="b1505154983165632"><a name="b1505154983165632"></a><a name="b1505154983165632"></a><a href="ohos-media-framestatecallback.md">FrameStateCallback</a></strong> instance. </p>
</td>
</tr>
<tr id="row9620502165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1008925165632"><a name="p1008925165632"></a><a name="p1008925165632"></a><a href="multimedia_framestatecallback.md#gad9ee33e328b523316313b79979b93abb">~FrameStateCallback</a> ()=default</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1404596400165632"><a name="p1404596400165632"></a><a name="p1404596400165632"></a> </p>
<p id="p795018961165632"><a name="p795018961165632"></a><a name="p795018961165632"></a>A destructor used to delete the <strong id="b1627785424165632"><a name="b1627785424165632"></a><a name="b1627785424165632"></a><a href="ohos-media-framestatecallback.md">FrameStateCallback</a></strong> instance. </p>
</td>
</tr>
<tr id="row475594284165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1024741973165632"><a name="p1024741973165632"></a><a name="p1024741973165632"></a><a href="multimedia_framestatecallback.md#gaad7c0bd2d27255a8b63d0f5fb75f3b1e">OnFrameFinished</a> (<a href="ohos-media-camera.md">Camera</a> &amp;camera, <a href="ohos-media-frameconfig.md">FrameConfig</a> &amp;frameConfig, FrameResult &amp;frameResult)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1906157979165632"><a name="p1906157979165632"></a><a name="p1906157979165632"></a>virtual void </p>
<p id="p1187344021165632"><a name="p1187344021165632"></a><a name="p1187344021165632"></a>Called when the frame capture is finished. </p>
</td>
</tr>
<tr id="row795833183165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1315866455165632"><a name="p1315866455165632"></a><a name="p1315866455165632"></a><a href="multimedia_framestatecallback.md#ga8692c0a7433e0a98b6a6e364081c3b6a">OnFrameError</a> (<a href="ohos-media-camera.md">Camera</a> &amp;camera, <a href="ohos-media-frameconfig.md">FrameConfig</a> &amp;frameConfig, int32_t errorCode, FrameResult &amp;frameResult)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1115566538165632"><a name="p1115566538165632"></a><a name="p1115566538165632"></a>virtual void </p>
<p id="p1341096226165632"><a name="p1341096226165632"></a><a name="p1341096226165632"></a>Called when the frame capture fails. </p>
</td>
</tr>
</tbody>
</table>

