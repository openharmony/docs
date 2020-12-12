# OHOS::Media::CameraKit<a name="EN-US_TOPIC_0000001054479573"></a>

-   [Overview](#section517282025165632)
-   [Summary](#section1975045411165632)
-   [Public Member Functions](#pub-methods)
-   [Static Public Member Functions](#pub-static-methods)

## **Overview**<a name="section517282025165632"></a>

**Related Modules:**

[MultiMedia\_CameraKit](multimedia_camerakit.md)

**Description:**

Provides functions in the  **[CameraKit](ohos-media-camerakit.md)**  class. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1975045411165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1984282802165632"></a>
<table><thead align="left"><tr id="row573064229165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1394744870165632"><a name="p1394744870165632"></a><a name="p1394744870165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2115988785165632"><a name="p2115988785165632"></a><a name="p2115988785165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row383503498165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1377398869165632"><a name="p1377398869165632"></a><a name="p1377398869165632"></a><a href="multimedia_camerakit.md#ga7d36867ec1bd57e25d1c60b5de24cbe6">~CameraKit</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p693328575165632"><a name="p693328575165632"></a><a name="p693328575165632"></a> </p>
<p id="p1362560412165632"><a name="p1362560412165632"></a><a name="p1362560412165632"></a>A destructor used to delete the <strong id="b122878040165632"><a name="b122878040165632"></a><a name="b122878040165632"></a><a href="ohos-media-camerakit.md">CameraKit</a></strong> instance. </p>
</td>
</tr>
<tr id="row1699893706165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p456913825165632"><a name="p456913825165632"></a><a name="p456913825165632"></a><a href="multimedia_camerakit.md#ga8894d876198f2614d65b432a8a002163">GetCameraIds</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1945031367165632"><a name="p1945031367165632"></a><a name="p1945031367165632"></a>std::list&lt; std::string &gt; </p>
<p id="p771689403165632"><a name="p771689403165632"></a><a name="p771689403165632"></a>Obtains IDs of cameras that are currently available. </p>
</td>
</tr>
<tr id="row1150333865165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p439830559165632"><a name="p439830559165632"></a><a name="p439830559165632"></a><a href="multimedia_camerakit.md#gab4cfb051de29415d080a203ca4639448">GetCameraAbility</a> (std::string cameraId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p293530006165632"><a name="p293530006165632"></a><a name="p293530006165632"></a>const <a href="ohos-media-cameraability.md">CameraAbility</a> * </p>
<p id="p2035926078165632"><a name="p2035926078165632"></a><a name="p2035926078165632"></a>Obtains the camera capability, including the resolutions and frame rates. </p>
</td>
</tr>
<tr id="row1530970675165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p998008361165632"><a name="p998008361165632"></a><a name="p998008361165632"></a><a href="multimedia_camerakit.md#ga4e6cd8787f06c4a82ad982d36029b3ec">RegisterCameraDeviceCallback</a> (<a href="ohos-media-cameradevicecallback.md">CameraDeviceCallback</a> &amp;callback, EventHandler &amp;handler)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p6172879165632"><a name="p6172879165632"></a><a name="p6172879165632"></a>void </p>
<p id="p1730793993165632"><a name="p1730793993165632"></a><a name="p1730793993165632"></a>Registers a camera callback for camera status changes and an event callback to respond to a triggered event. </p>
</td>
</tr>
<tr id="row438851021165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p794856625165632"><a name="p794856625165632"></a><a name="p794856625165632"></a><a href="multimedia_camerakit.md#ga4f0117575ee988f6d74a3636e01f0aba">UnregisterCameraDeviceCallback</a> (<a href="ohos-media-cameradevicecallback.md">CameraDeviceCallback</a> &amp;callback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1667228838165632"><a name="p1667228838165632"></a><a name="p1667228838165632"></a>void </p>
<p id="p1751433177165632"><a name="p1751433177165632"></a><a name="p1751433177165632"></a>Unregisters a camera callback. </p>
</td>
</tr>
<tr id="row1538006904165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p84503411165632"><a name="p84503411165632"></a><a name="p84503411165632"></a><a href="multimedia_camerakit.md#gaa21f4e248e3a46a4f78f4261cba82fe2">CreateCamera</a> (const std::string &amp;cameraId, <a href="ohos-media-camerastatecallback.md">CameraStateCallback</a> &amp;callback, EventHandler &amp;handler)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1411849945165632"><a name="p1411849945165632"></a><a name="p1411849945165632"></a>void </p>
<p id="p2041920376165632"><a name="p2041920376165632"></a><a name="p2041920376165632"></a>Creates a camera object. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Member Functions<a name="pub-static-methods"></a>

<a name="table707783472165632"></a>
<table><thead align="left"><tr id="row1414793341165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p139995682165632"><a name="p139995682165632"></a><a name="p139995682165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2080889610165632"><a name="p2080889610165632"></a><a name="p2080889610165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1591372613165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p372685682165632"><a name="p372685682165632"></a><a name="p372685682165632"></a><a href="multimedia_camerakit.md#ga1911ba8eca0e57ddc15df25cf2b21f7b">GetInstance</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1758011974165632"><a name="p1758011974165632"></a><a name="p1758011974165632"></a>static <a href="ohos-media-camerakit.md">CameraKit</a> * </p>
<p id="p1596004039165632"><a name="p1596004039165632"></a><a name="p1596004039165632"></a>Obtains a single instance of the <strong id="b1670915486165632"><a name="b1670915486165632"></a><a name="b1670915486165632"></a><a href="ohos-media-camerakit.md">CameraKit</a></strong>. </p>
</td>
</tr>
</tbody>
</table>

