# OHOS::Media::FrameConfig<a name="ZH-CN_TOPIC_0000001055358122"></a>

-   [Overview](#section2020073262165632)
-   [Summary](#section1791407885165632)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section2020073262165632"></a>

**Related Modules:**

[MultiMedia\_FrameConfig](MultiMedia_FrameConfig.md)

**Description:**

Provides functions to configure frames. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1791407885165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1007958173165632"></a>
<table><thead align="left"><tr id="row1478254198165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2102809646165632"><a name="p2102809646165632"></a><a name="p2102809646165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1361413852165632"><a name="p1361413852165632"></a><a name="p1361413852165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row215882624165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p94817450165632"><a name="p94817450165632"></a><a name="p94817450165632"></a><a href="MultiMedia_FrameConfig.md#ga043537d52f5db46d981f9e89848b0fba">FrameConfig</a> ()=delete</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p44346026165632"><a name="p44346026165632"></a><a name="p44346026165632"></a> </p>
<p id="p223673899165632"><a name="p223673899165632"></a><a name="p223673899165632"></a>A constructor used to create a <strong id="b1303956254165632"><a name="b1303956254165632"></a><a name="b1303956254165632"></a><a href="OHOS-Media-FrameConfig.md">FrameConfig</a></strong> instance. </p>
</td>
</tr>
<tr id="row1039247684165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1865471492165632"><a name="p1865471492165632"></a><a name="p1865471492165632"></a><a href="MultiMedia_FrameConfig.md#gac8f74ff3689605a59a17997bdeaec1fc">FrameConfig</a> (int32_t type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1070372433165632"><a name="p1070372433165632"></a><a name="p1070372433165632"></a> </p>
<p id="p556403175165632"><a name="p556403175165632"></a><a name="p556403175165632"></a>A constructor used to create a <strong id="b1901214508165632"><a name="b1901214508165632"></a><a name="b1901214508165632"></a><a href="OHOS-Media-FrameConfig.md">FrameConfig</a></strong> instance based on the configuration mode. </p>
</td>
</tr>
<tr id="row1677675249165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p813463733165632"><a name="p813463733165632"></a><a name="p813463733165632"></a><a href="MultiMedia_FrameConfig.md#gaa2e58c2ce602d9263b76596374823616">~FrameConfig</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2067489943165632"><a name="p2067489943165632"></a><a name="p2067489943165632"></a> </p>
<p id="p1298313073165632"><a name="p1298313073165632"></a><a name="p1298313073165632"></a>A destructor used to delete the <strong id="b449552008165632"><a name="b449552008165632"></a><a name="b449552008165632"></a><a href="OHOS-Media-FrameConfig.md">FrameConfig</a></strong> instance. </p>
</td>
</tr>
<tr id="row1370278831165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1672524165632"><a name="p1672524165632"></a><a name="p1672524165632"></a><a href="MultiMedia_FrameConfig.md#ga382977445a583ed0424c5ccf581e824c">GetFrameConfigType</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1756387520165632"><a name="p1756387520165632"></a><a name="p1756387520165632"></a>int32_t </p>
<p id="p1654661141165632"><a name="p1654661141165632"></a><a name="p1654661141165632"></a>Obtains the frame configuration type. </p>
</td>
</tr>
<tr id="row438888363165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p28909436165632"><a name="p28909436165632"></a><a name="p28909436165632"></a><a href="MultiMedia_FrameConfig.md#ga955d04df96c009e4699ea6ed46d9e758">GetSurfaces</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p813399823165632"><a name="p813399823165632"></a><a name="p813399823165632"></a>std::list&lt; <a href="OHOS-Surface.md">Surface</a> * &gt; </p>
<p id="p431961039165632"><a name="p431961039165632"></a><a name="p431961039165632"></a>Obtains a list of shared memories (surface objects). </p>
</td>
</tr>
<tr id="row187953190165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2091554790165632"><a name="p2091554790165632"></a><a name="p2091554790165632"></a><a href="MultiMedia_FrameConfig.md#ga16760311713db03bf06ea0a6d6622013">AddSurface</a> (<a href="OHOS-Surface.md">Surface</a> &amp;surface)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1620172538165632"><a name="p1620172538165632"></a><a name="p1620172538165632"></a>void </p>
<p id="p2056676312165632"><a name="p2056676312165632"></a><a name="p2056676312165632"></a>Adds a surface (an object of shared memory). </p>
</td>
</tr>
<tr id="row1619903264165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1213245509165632"><a name="p1213245509165632"></a><a name="p1213245509165632"></a><a href="MultiMedia_FrameConfig.md#ga9ac4bc5e52840ee579482a3836774762">RemoveSurface</a> (<a href="OHOS-Surface.md">Surface</a> &amp;surface)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p941661665165632"><a name="p941661665165632"></a><a name="p941661665165632"></a>void </p>
<p id="p384577712165632"><a name="p384577712165632"></a><a name="p384577712165632"></a>Removes a surface (an object of shared memory). You can call this function to release the surface when your application does not need to obtain data. </p>
</td>
</tr>
<tr id="row1422263520165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1117841152165632"><a name="p1117841152165632"></a><a name="p1117841152165632"></a><a href="MultiMedia_FrameConfig.md#ga6b4ee39d1c1bf219e4a84df470f6007a">SetParameter</a> (uint32_t key, const T value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p966244898165632"><a name="p966244898165632"></a><a name="p966244898165632"></a>template&lt;typename T &gt; void </p>
<p id="p865772446165632"><a name="p865772446165632"></a><a name="p865772446165632"></a>Sets the common parameter. </p>
</td>
</tr>
<tr id="row539969599165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1082083329165632"><a name="p1082083329165632"></a><a name="p1082083329165632"></a><a href="MultiMedia_FrameConfig.md#ga05147491c6e25df54d75d5ed0c201d65">GetParameter</a> (uint32_t key, T &amp;value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p931693376165632"><a name="p931693376165632"></a><a name="p931693376165632"></a>template&lt;typename T &gt; void </p>
<p id="p1627605250165632"><a name="p1627605250165632"></a><a name="p1627605250165632"></a>Obtains the value of a common parameter based on its key. For details, see <strong id="b440884929165632"><a name="b440884929165632"></a><a name="b440884929165632"></a>CAMERA_FUC_KEY</strong>. </p>
</td>
</tr>
</tbody>
</table>

