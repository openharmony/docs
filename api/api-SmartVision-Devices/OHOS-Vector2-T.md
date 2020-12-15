# OHOS::Vector2< T \><a name="ZH-CN_TOPIC_0000001055518120"></a>

-   [Overview](#section1740720448165635)
-   [Summary](#section197169423165635)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1740720448165635"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

template<typename T\> class OHOS::Vector2< T \>

Defines the two-dimensional vector, and provides basic mathematical operations such as vector assignment, scalar product, cross product, addition, and subtraction. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section197169423165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1212438842165635"></a>
<table><thead align="left"><tr id="row413887097165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1255852844165635"><a name="p1255852844165635"></a><a name="p1255852844165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p752920293165635"><a name="p752920293165635"></a><a name="p752920293165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row689428737165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1275453136165635"><a name="p1275453136165635"></a><a name="p1275453136165635"></a><a href="Graphic.md#ga7fd378c8c6c9fcf7325fa354f182865c">Vector2</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p965195474165635"><a name="p965195474165635"></a><a name="p965195474165635"></a> </p>
<p id="p157237461165635"><a name="p157237461165635"></a><a name="p157237461165635"></a>A constructor used to create a <strong id="b1097053695165635"><a name="b1097053695165635"></a><a name="b1097053695165635"></a><a href="OHOS-Vector2-T.md">Vector2</a></strong> instance. </p>
</td>
</tr>
<tr id="row1863345501165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1227189764165635"><a name="p1227189764165635"></a><a name="p1227189764165635"></a><a href="Graphic.md#gada601fe3518d7bb489010370f1db9903">Vector2</a> (T x, T y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p367482647165635"><a name="p367482647165635"></a><a name="p367482647165635"></a> </p>
<p id="p1768157851165635"><a name="p1768157851165635"></a><a name="p1768157851165635"></a>A constructor used to create a <strong id="b1868007541165635"><a name="b1868007541165635"></a><a name="b1868007541165635"></a><a href="OHOS-Vector2-T.md">Vector2</a></strong> instance based on the X and Y coordinates. </p>
</td>
</tr>
<tr id="row575141664165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1512960834165635"><a name="p1512960834165635"></a><a name="p1512960834165635"></a><a href="Graphic.md#ga1cc5130b89192fc1403eb29dd4504cbb">~Vector2</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p982248090165635"><a name="p982248090165635"></a><a name="p982248090165635"></a> </p>
<p id="p1132868338165635"><a name="p1132868338165635"></a><a name="p1132868338165635"></a>A destructor used to delete the <strong id="b1471557654165635"><a name="b1471557654165635"></a><a name="b1471557654165635"></a><a href="OHOS-Vector2-T.md">Vector2</a></strong> instance. </p>
</td>
</tr>
<tr id="row1265180700165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p611640380165635"><a name="p611640380165635"></a><a name="p611640380165635"></a><a href="Graphic.md#gae45c198b5bcb73ecac8d654c281bc21a">Dot</a> (const <a href="OHOS-Vector2-T.md">Vector2</a>&lt; T &gt; &amp;other) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1728639174165635"><a name="p1728639174165635"></a><a name="p1728639174165635"></a>T </p>
<p id="p1942964421165635"><a name="p1942964421165635"></a><a name="p1942964421165635"></a>Calculates the scalar product of the two-dimensional vector and another two-dimensional vector. </p>
</td>
</tr>
<tr id="row1771082348165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p787693930165635"><a name="p787693930165635"></a><a name="p787693930165635"></a><a href="Graphic.md#gac1c8e01fd488d5f8aea6bddad1dec206">Cross</a> (const <a href="OHOS-Vector2-T.md">Vector2</a>&lt; T &gt; &amp;other) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1195178540165635"><a name="p1195178540165635"></a><a name="p1195178540165635"></a>T </p>
<p id="p1361776022165635"><a name="p1361776022165635"></a><a name="p1361776022165635"></a>Calculates the cross product of the two-dimensional vector and another two-dimensional vector. </p>
</td>
</tr>
<tr id="row302680612165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2070511548165635"><a name="p2070511548165635"></a><a name="p2070511548165635"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1384346232165635"><a name="p1384346232165635"></a><a name="p1384346232165635"></a>void * </p>
<p id="p589511055165635"><a name="p589511055165635"></a><a name="p589511055165635"></a>Overrides the <strong id="b1047997813165635"><a name="b1047997813165635"></a><a name="b1047997813165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row243714670165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p516790914165635"><a name="p516790914165635"></a><a name="p516790914165635"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1516685180165635"><a name="p1516685180165635"></a><a name="p1516685180165635"></a>void </p>
<p id="p1480968366165635"><a name="p1480968366165635"></a><a name="p1480968366165635"></a>Overrides the <strong id="b646150075165635"><a name="b646150075165635"></a><a name="b646150075165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

