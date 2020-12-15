# OHOS::Media::CameraConfig<a name="ZH-CN_TOPIC_0000001055198144"></a>

-   [Overview](#section367535151165632)
-   [Summary](#section416551332165632)
-   [Public Member Functions](#pub-methods)
-   [Static Public Member Functions](#pub-static-methods)
-   [Protected Member Functions](#pro-methods)

## **Overview**<a name="section367535151165632"></a>

**Related Modules:**

[MultiMedia\_CameraConfig](MultiMedia_CameraConfig.md)

**Description:**

Provides functions to configure camera parameters. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section416551332165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table311755662165632"></a>
<table><thead align="left"><tr id="row268560720165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1518227632165632"><a name="p1518227632165632"></a><a name="p1518227632165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1123021940165632"><a name="p1123021940165632"></a><a name="p1123021940165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1409983801165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1710302049165632"><a name="p1710302049165632"></a><a name="p1710302049165632"></a><a href="MultiMedia_CameraConfig.md#ga6730b1ff3808a97fe7095c1cd016d47c">~CameraConfig</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p852815311165632"><a name="p852815311165632"></a><a name="p852815311165632"></a>virtual </p>
<p id="p456277276165632"><a name="p456277276165632"></a><a name="p456277276165632"></a>A destructor used to delete the <strong id="b1067788601165632"><a name="b1067788601165632"></a><a name="b1067788601165632"></a><a href="OHOS-Media-CameraAbility.md">CameraAbility</a></strong> instance. </p>
</td>
</tr>
<tr id="row879896026165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1053079439165632"><a name="p1053079439165632"></a><a name="p1053079439165632"></a><a href="MultiMedia_CameraConfig.md#gaf6d7f82e9439dce13b0213f84a35ab59">SetFrameStateCallback</a> (<a href="OHOS-Media-FrameStateCallback.md">FrameStateCallback</a> *callback, EventHandler *handler)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p522484150165632"><a name="p522484150165632"></a><a name="p522484150165632"></a>virtual void </p>
<p id="p472186924165632"><a name="p472186924165632"></a><a name="p472186924165632"></a>Sets a frame state callback to responds to state changes. </p>
</td>
</tr>
<tr id="row927781870165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1000252284165632"><a name="p1000252284165632"></a><a name="p1000252284165632"></a><a href="MultiMedia_CameraConfig.md#ga65d8bb0bd5d996e51e4c6fa12a33931b">GetEventHandler</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1091575572165632"><a name="p1091575572165632"></a><a name="p1091575572165632"></a>virtual EventHandler * </p>
<p id="p1060453604165632"><a name="p1060453604165632"></a><a name="p1060453604165632"></a>Obtains the <strong id="b200622442165632"><a name="b200622442165632"></a><a name="b200622442165632"></a>EventHandler</strong> object. </p>
</td>
</tr>
<tr id="row1834885067165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p413158889165632"><a name="p413158889165632"></a><a name="p413158889165632"></a><a href="MultiMedia_CameraConfig.md#gae4864312836d34b9ad56675ed3e523a1">GetFrameStateCb</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1546428602165632"><a name="p1546428602165632"></a><a name="p1546428602165632"></a>virtual <a href="OHOS-Media-FrameStateCallback.md">FrameStateCallback</a> * </p>
<p id="p2135762901165632"><a name="p2135762901165632"></a><a name="p2135762901165632"></a>Obtains a <strong id="b44588528165632"><a name="b44588528165632"></a><a name="b44588528165632"></a><a href="OHOS-Media-FrameStateCallback.md">FrameStateCallback</a></strong> object. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Member Functions<a name="pub-static-methods"></a>

<a name="table2058747211165632"></a>
<table><thead align="left"><tr id="row2132909137165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1604682860165632"><a name="p1604682860165632"></a><a name="p1604682860165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p480978390165632"><a name="p480978390165632"></a><a name="p480978390165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row441053106165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1122800542165632"><a name="p1122800542165632"></a><a name="p1122800542165632"></a><a href="MultiMedia_CameraConfig.md#ga26f37610abb783b48d3e94662523fa94">CreateCameraConfig</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1727843336165632"><a name="p1727843336165632"></a><a name="p1727843336165632"></a>static <a href="OHOS-Media-CameraConfig.md">CameraConfig</a> * </p>
<p id="p1340320215165632"><a name="p1340320215165632"></a><a name="p1340320215165632"></a>Creates the <strong id="b1156082362165632"><a name="b1156082362165632"></a><a name="b1156082362165632"></a><a href="OHOS-Media-CameraConfig.md">CameraConfig</a></strong> instance of this singleton class to configure and read the required parameters. </p>
</td>
</tr>
</tbody>
</table>

## Protected Member Functions<a name="pro-methods"></a>

<a name="table316031151165632"></a>
<table><thead align="left"><tr id="row241912167165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p316116733165632"><a name="p316116733165632"></a><a name="p316116733165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1908849454165632"><a name="p1908849454165632"></a><a name="p1908849454165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row701603792165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1900153896165632"><a name="p1900153896165632"></a><a name="p1900153896165632"></a><a href="MultiMedia_CameraConfig.md#ga6cca70f5dea34d6ede94d0b258c0a350">CameraConfig</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p239717881165632"><a name="p239717881165632"></a><a name="p239717881165632"></a> </p>
<p id="p456981894165632"><a name="p456981894165632"></a><a name="p456981894165632"></a>A constructor used to create a <strong id="b1552706874165632"><a name="b1552706874165632"></a><a name="b1552706874165632"></a><a href="OHOS-Media-CameraConfig.md">CameraConfig</a></strong> instance. </p>
</td>
</tr>
</tbody>
</table>

