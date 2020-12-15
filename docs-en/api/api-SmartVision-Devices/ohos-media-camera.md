# OHOS::Media::Camera<a name="EN-US_TOPIC_0000001055078149"></a>

-   [Overview](#section782472257165632)
-   [Summary](#section672881182165632)
-   [Public Member Functions](#pub-methods)
-   [Protected Member Functions](#pro-methods)

## **Overview**<a name="section782472257165632"></a>

**Related Modules:**

[MultiMedia\_Camera](multimedia_camera.md)

**Description:**

Provides functions in the  **[Camera](ohos-media-camera.md)**  class to implement camera operations. operations. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section672881182165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table281601374165632"></a>
<table><thead align="left"><tr id="row1749984937165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1765185118165632"><a name="p1765185118165632"></a><a name="p1765185118165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p420871537165632"><a name="p420871537165632"></a><a name="p420871537165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1836230531165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2133938529165632"><a name="p2133938529165632"></a><a name="p2133938529165632"></a><a href="multimedia_camera.md#gab24c0e4ca1e15bb2a481fb1550955611">~Camera</a> ()=default</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1530357493165632"><a name="p1530357493165632"></a><a name="p1530357493165632"></a>virtual </p>
<p id="p456856958165632"><a name="p456856958165632"></a><a name="p456856958165632"></a>A destructor used to delete the <strong id="b2100670446165632"><a name="b2100670446165632"></a><a name="b2100670446165632"></a><a href="ohos-media-camera.md">Camera</a></strong> instance. </p>
</td>
</tr>
<tr id="row1818819927165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p881240062165632"><a name="p881240062165632"></a><a name="p881240062165632"></a><a href="multimedia_camera.md#ga4b6fec3c9290e7d388147dcdd288b918">GetCameraId</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1780395154165632"><a name="p1780395154165632"></a><a name="p1780395154165632"></a>virtual std::string </p>
<p id="p1166109829165632"><a name="p1166109829165632"></a><a name="p1166109829165632"></a>Obtains the camera ID. </p>
</td>
</tr>
<tr id="row1774811733165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p242341286165632"><a name="p242341286165632"></a><a name="p242341286165632"></a><a href="multimedia_camera.md#ga04cc021b827824d0363037b630326264">GetCameraConfig</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1750296179165632"><a name="p1750296179165632"></a><a name="p1750296179165632"></a>virtual const <a href="ohos-media-cameraconfig.md">CameraConfig</a> * </p>
<p id="p933679151165632"><a name="p933679151165632"></a><a name="p933679151165632"></a>Obtains the camera configuration. You can use the obtained <strong id="b1061643934165632"><a name="b1061643934165632"></a><a name="b1061643934165632"></a><a href="ohos-media-cameraconfig.md">CameraConfig</a></strong> object to configure the camera. </p>
</td>
</tr>
<tr id="row2075578990165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1324824109165632"><a name="p1324824109165632"></a><a name="p1324824109165632"></a><a href="multimedia_camera.md#ga4e3f97ac484b85cd221a996689a3de61">GetFrameConfig</a> (int32_t type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1563147063165632"><a name="p1563147063165632"></a><a name="p1563147063165632"></a>virtual <a href="ohos-media-frameconfig.md">FrameConfig</a> * </p>
<p id="p1220048594165632"><a name="p1220048594165632"></a><a name="p1220048594165632"></a>Obtains the frame configuration. </p>
</td>
</tr>
<tr id="row1127108765165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p511584385165632"><a name="p511584385165632"></a><a name="p511584385165632"></a><a href="multimedia_camera.md#ga5f240a74fefa168cbf94b4603b76ef7b">Configure</a> (<a href="ohos-media-cameraconfig.md">CameraConfig</a> &amp;config)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1151456952165632"><a name="p1151456952165632"></a><a name="p1151456952165632"></a>virtual void </p>
<p id="p1948752876165632"><a name="p1948752876165632"></a><a name="p1948752876165632"></a>Configures the camera using the <strong id="b1246170627165632"><a name="b1246170627165632"></a><a name="b1246170627165632"></a><a href="ohos-media-cameraconfig.md">CameraConfig</a></strong> object. </p>
</td>
</tr>
<tr id="row2050336262165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p853400002165632"><a name="p853400002165632"></a><a name="p853400002165632"></a><a href="multimedia_camera.md#ga1cd68b1b385da5224dbfdb6993c5cf08">TriggerLoopingCapture</a> (<a href="ohos-media-frameconfig.md">FrameConfig</a> &amp;frameConfig)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1218702427165632"><a name="p1218702427165632"></a><a name="p1218702427165632"></a>virtual int32_t </p>
<p id="p1861099059165632"><a name="p1861099059165632"></a><a name="p1861099059165632"></a>Triggers looping-frame capture. </p>
</td>
</tr>
<tr id="row1920802507165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p673386942165632"><a name="p673386942165632"></a><a name="p673386942165632"></a><a href="multimedia_camera.md#ga564c26b845affb1dbe05d4d7982ed1ad">StopLoopingCapture</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1501187882165632"><a name="p1501187882165632"></a><a name="p1501187882165632"></a>virtual void </p>
<p id="p1245896141165632"><a name="p1245896141165632"></a><a name="p1245896141165632"></a>Stops looping-frame capture. </p>
</td>
</tr>
<tr id="row130860814165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1393401988165632"><a name="p1393401988165632"></a><a name="p1393401988165632"></a><a href="multimedia_camera.md#gac05d783b1655fe505a4afa23496d7e84">TriggerSingleCapture</a> (<a href="ohos-media-frameconfig.md">FrameConfig</a> &amp;frameConfig)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2064846761165632"><a name="p2064846761165632"></a><a name="p2064846761165632"></a>virtual int32_t </p>
<p id="p199622435165632"><a name="p199622435165632"></a><a name="p199622435165632"></a>Starts single-frame capture. The frame parameters are set through the <strong id="b1170795186165632"><a name="b1170795186165632"></a><a name="b1170795186165632"></a><a href="ohos-media-frameconfig.md">FrameConfig</a></strong> object, and the captured image data is stored in the surface of the <strong id="b2032572435165632"><a name="b2032572435165632"></a><a name="b2032572435165632"></a><a href="ohos-media-frameconfig.md">FrameConfig</a></strong> object. </p>
</td>
</tr>
<tr id="row1741934163165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p523467415165632"><a name="p523467415165632"></a><a name="p523467415165632"></a><a href="multimedia_camera.md#ga7986d17e54fe9cd77df9465287fa5643">Release</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1248739381165632"><a name="p1248739381165632"></a><a name="p1248739381165632"></a>virtual void </p>
<p id="p872314138165632"><a name="p872314138165632"></a><a name="p872314138165632"></a>Releases the <strong id="b1679829888165632"><a name="b1679829888165632"></a><a name="b1679829888165632"></a><a href="ohos-media-camera.md">Camera</a></strong> object and associated resources. </p>
</td>
</tr>
</tbody>
</table>

## Protected Member Functions<a name="pro-methods"></a>

<a name="table1316281178165632"></a>
<table><thead align="left"><tr id="row1009184080165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p623150209165632"><a name="p623150209165632"></a><a name="p623150209165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p237050561165632"><a name="p237050561165632"></a><a name="p237050561165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1032492970165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p812137848165632"><a name="p812137848165632"></a><a name="p812137848165632"></a><a href="multimedia_camera.md#ga7df4eba3316a6fe7c623e420c0a295e5">Camera</a> ()=default</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1801901123165632"><a name="p1801901123165632"></a><a name="p1801901123165632"></a> </p>
<p id="p604316911165632"><a name="p604316911165632"></a><a name="p604316911165632"></a>A constructor used to create a <strong id="b783050406165632"><a name="b783050406165632"></a><a name="b783050406165632"></a><a href="ohos-media-camera.md">Camera</a></strong> instance. </p>
</td>
</tr>
</tbody>
</table>

