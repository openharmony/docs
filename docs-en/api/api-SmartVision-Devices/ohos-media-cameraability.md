# OHOS::Media::CameraAbility<a name="EN-US_TOPIC_0000001054879542"></a>

-   [Overview](#section1978665259165632)
-   [Summary](#section2081471788165632)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1978665259165632"></a>

**Related Modules:**

[MultiMedia\_CameraAbility](multimedia_cameraability.md)

**Description:**

Declares functions of the  **[CameraAbility](ohos-media-cameraability.md)**  class. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2081471788165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table660328257165632"></a>
<table><thead align="left"><tr id="row1513276261165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p540391908165632"><a name="p540391908165632"></a><a name="p540391908165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1899249396165632"><a name="p1899249396165632"></a><a name="p1899249396165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row507871487165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p678343187165632"><a name="p678343187165632"></a><a name="p678343187165632"></a><a href="multimedia_cameraability.md#ga7f1b94b32f7c7b121ea14b3147788497">CameraAbility</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p968794369165632"><a name="p968794369165632"></a><a name="p968794369165632"></a> </p>
<p id="p565266812165632"><a name="p565266812165632"></a><a name="p565266812165632"></a>A constructor used to create a <strong id="b1093433490165632"><a name="b1093433490165632"></a><a name="b1093433490165632"></a><a href="ohos-media-cameraability.md">CameraAbility</a></strong> instance. </p>
</td>
</tr>
<tr id="row98714972165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p608069332165632"><a name="p608069332165632"></a><a name="p608069332165632"></a><a href="multimedia_cameraability.md#ga797435bcd10278e33fb7b6f4951f0d7f">~CameraAbility</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p986549236165632"><a name="p986549236165632"></a><a name="p986549236165632"></a>virtual </p>
<p id="p1535782987165632"><a name="p1535782987165632"></a><a name="p1535782987165632"></a>A destructor used to delete the <strong id="b15227085165632"><a name="b15227085165632"></a><a name="b15227085165632"></a><a href="ohos-media-cameraability.md">CameraAbility</a></strong> instance. </p>
</td>
</tr>
<tr id="row1970455025165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1818554740165632"><a name="p1818554740165632"></a><a name="p1818554740165632"></a><a href="multimedia_cameraability.md#ga840850d531b96cc5a829b257ade3c7e6">GetSupportedSizes</a> (int format) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p90367709165632"><a name="p90367709165632"></a><a name="p90367709165632"></a>std::list&lt; CameraPicSize &gt; </p>
<p id="p545557600165632"><a name="p545557600165632"></a><a name="p545557600165632"></a>Obtains the supported image sizes for a specified image format. </p>
</td>
</tr>
<tr id="row4466921165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1010873165632"><a name="p1010873165632"></a><a name="p1010873165632"></a><a href="multimedia_cameraability.md#ga23410306b850fe7edcb736f50fe8048d">SetParameterRange</a> (uint32_t key, std::list&lt; T &gt; rangeList)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p971428587165632"><a name="p971428587165632"></a><a name="p971428587165632"></a>template&lt;typename T &gt; int32_t </p>
<p id="p1039557271165632"><a name="p1039557271165632"></a><a name="p1039557271165632"></a>Sets value ranges for a specified parameter. </p>
</td>
</tr>
<tr id="row1170929430165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1046612982165632"><a name="p1046612982165632"></a><a name="p1046612982165632"></a><a href="multimedia_cameraability.md#ga3fb9142cc5bbeafef3201ecaaf50c737">GetParameterRange</a> (uint32_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1066732677165632"><a name="p1066732677165632"></a><a name="p1066732677165632"></a>template&lt;typename T &gt; std::list&lt; T &gt; </p>
<p id="p1487749216165632"><a name="p1487749216165632"></a><a name="p1487749216165632"></a>Obtains the parameter value range based on a specified parameter key. </p>
</td>
</tr>
</tbody>
</table>

