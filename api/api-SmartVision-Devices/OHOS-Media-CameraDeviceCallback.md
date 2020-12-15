# OHOS::Media::CameraDeviceCallback<a name="ZH-CN_TOPIC_0000001055198140"></a>

-   [Overview](#section1981938762165632)
-   [Summary](#section677004534165632)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1981938762165632"></a>

**Related Modules:**

[MultiMedia\_CameraDeviceCallback](MultiMedia_CameraDeviceCallback.md)

**Description:**

Provides functions to response to device changes. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section677004534165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1927507409165632"></a>
<table><thead align="left"><tr id="row1542057248165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1367853343165632"><a name="p1367853343165632"></a><a name="p1367853343165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1396408986165632"><a name="p1396408986165632"></a><a name="p1396408986165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row192997475165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1667942242165632"><a name="p1667942242165632"></a><a name="p1667942242165632"></a><a href="MultiMedia_CameraDeviceCallback.md#ga5e81f9fa5dd53d9d1f8ca0cc4497fd59">CameraDeviceCallback</a> ()=default</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1383712078165632"><a name="p1383712078165632"></a><a name="p1383712078165632"></a> </p>
<p id="p1626998013165632"><a name="p1626998013165632"></a><a name="p1626998013165632"></a>A constructor used to create a <strong id="b785720062165632"><a name="b785720062165632"></a><a name="b785720062165632"></a><a href="OHOS-Media-CameraDeviceCallback.md">CameraDeviceCallback</a></strong> instance. </p>
</td>
</tr>
<tr id="row278368515165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1231572390165632"><a name="p1231572390165632"></a><a name="p1231572390165632"></a><a href="MultiMedia_CameraDeviceCallback.md#gac88b6972227ec2ba65feeb15c31aea83">~CameraDeviceCallback</a> ()=default</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p596433846165632"><a name="p596433846165632"></a><a name="p596433846165632"></a>virtual </p>
<p id="p2003763692165632"><a name="p2003763692165632"></a><a name="p2003763692165632"></a>A destructor used to delete the <strong id="b1573193060165632"><a name="b1573193060165632"></a><a name="b1573193060165632"></a><a href="OHOS-Media-CameraDeviceCallback.md">CameraDeviceCallback</a></strong> instance. </p>
</td>
</tr>
<tr id="row6852546165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1998016333165632"><a name="p1998016333165632"></a><a name="p1998016333165632"></a><a href="MultiMedia_CameraDeviceCallback.md#ga2ae4d3d8ae13f73986f8dc7cf4bb7960">OnCameraStatus</a> (std::string cameraId, int32_t status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1844569413165632"><a name="p1844569413165632"></a><a name="p1844569413165632"></a>virtual void </p>
<p id="p2021455115165632"><a name="p2021455115165632"></a><a name="p2021455115165632"></a>Called when the camera state changes. </p>
</td>
</tr>
</tbody>
</table>

