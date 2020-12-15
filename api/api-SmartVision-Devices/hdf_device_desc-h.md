# hdf\_device\_desc.h<a name="ZH-CN_TOPIC_0000001055678062"></a>

-   [Overview](#section2126061454165627)
-   [Summary](#section1232562669165627)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section2126061454165627"></a>

**Related Modules:**

[Core](Core.md)

**Description:**

Declares functions related to driver loading, service obtaining, and power management. 

**Since:**

1.0

## **Summary**<a name="section1232562669165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1417430029165627"></a>
<table><thead align="left"><tr id="row322565642165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p541298986165627"><a name="p541298986165627"></a><a name="p541298986165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1950640490165627"><a name="p1950640490165627"></a><a name="p1950640490165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1024569568165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p826342005165627"><a name="p826342005165627"></a><a name="p826342005165627"></a><a href="HdfDeviceObject.md">HdfDeviceObject</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2034832234165627"><a name="p2034832234165627"></a><a name="p2034832234165627"></a>Defines the device object. </p>
</td>
</tr>
<tr id="row2022006154165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1627267963165627"><a name="p1627267963165627"></a><a name="p1627267963165627"></a><a href="HdfDeviceIoClient.md">HdfDeviceIoClient</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p700783378165627"><a name="p700783378165627"></a><a name="p700783378165627"></a>Defines the client object structure of the I/O service. </p>
</td>
</tr>
<tr id="row545648299165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p294414726165627"><a name="p294414726165627"></a><a name="p294414726165627"></a><a href="IDeviceIoService.md">IDeviceIoService</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1048631905165627"><a name="p1048631905165627"></a><a name="p1048631905165627"></a>Defines the driver service. </p>
</td>
</tr>
<tr id="row1273908608165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p767082182165627"><a name="p767082182165627"></a><a name="p767082182165627"></a><a href="SubscriberCallback.md">SubscriberCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p903797344165627"><a name="p903797344165627"></a><a name="p903797344165627"></a>Called when the driver subscribes to other driver services. </p>
</td>
</tr>
<tr id="row1385476825165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p204680048165627"><a name="p204680048165627"></a><a name="p204680048165627"></a><a href="IPowerEventListener.md">IPowerEventListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2011796863165627"><a name="p2011796863165627"></a><a name="p2011796863165627"></a>Defines the power management functions provided by the HDF for the driver. </p>
</td>
</tr>
<tr id="row733017484165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1347054354165627"><a name="p1347054354165627"></a><a name="p1347054354165627"></a><a href="HdfDriverEntry.md">HdfDriverEntry</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p897077038165627"><a name="p897077038165627"></a><a name="p897077038165627"></a>Defines the entry structure of the driver in the HDF. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1374574785165627"></a>
<table><thead align="left"><tr id="row954855939165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1246520721165627"><a name="p1246520721165627"></a><a name="p1246520721165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1339627749165627"><a name="p1339627749165627"></a><a name="p1339627749165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1708642661165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p6262957165627"><a name="p6262957165627"></a><a name="p6262957165627"></a><a href="Core.md#ga5957e60db74b1b0703ebd1c53f964d48">MAX_PRIORITY_NUM</a>   200</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1547521013165627"><a name="p1547521013165627"></a><a name="p1547521013165627"></a>The maximum priority for loading the host and device. </p>
</td>
</tr>
<tr id="row1450965184165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1443979633165627"><a name="p1443979633165627"></a><a name="p1443979633165627"></a><a href="Core.md#ga99831072fdca13e3c423a14fa6a83c34">HDF_INIT</a>(module)   HDF_DRIVER_INIT(module)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1377359880165627"><a name="p1377359880165627"></a><a name="p1377359880165627"></a>Registers the driver with the HDF. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1076980031165627"></a>
<table><thead align="left"><tr id="row978116658165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p412379885165627"><a name="p412379885165627"></a><a name="p412379885165627"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1339358751165627"><a name="p1339358751165627"></a><a name="p1339358751165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row672369550165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1440108258165627"><a name="p1440108258165627"></a><a name="p1440108258165627"></a><a href="Core.md#ga172844da8a6908bf7226eee703ad9f80">ServicePolicy</a> {   <a href="Core.md#gga172844da8a6908bf7226eee703ad9f80aeed8de39f7a8c5a5be1f7b8beb7221e1">SERVICE_POLICY_NONE</a> = 0, <a href="Core.md#gga172844da8a6908bf7226eee703ad9f80a5ec1b4a05e5ba37c9bf58f039fe2c245">SERVICE_POLICY_PUBLIC</a>, <a href="Core.md#gga172844da8a6908bf7226eee703ad9f80a9a398765ae7bad9ce86e12a91683334c">SERVICE_POLICY_CAPACITY</a>, <a href="Core.md#gga172844da8a6908bf7226eee703ad9f80ac2fe21ccc86fbb38747c733716a6b2e0">SERVICE_POLICY_FRIENDLY</a>,   <a href="Core.md#gga172844da8a6908bf7226eee703ad9f80ac7918e4a8fa4a2c29ccc8bf97537b61c">SERVICE_POLICY_PRIVATE</a>, <a href="Core.md#gga172844da8a6908bf7226eee703ad9f80a423a5d22d00f6a45f0281dd287fc3b4d">SERVICE_POLICY_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1278561219165627"><a name="p1278561219165627"></a><a name="p1278561219165627"></a>Enumerates policies for releasing driver services developed based on the HDF. </p>
</td>
</tr>
<tr id="row2138840640165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p617383856165627"><a name="p617383856165627"></a><a name="p617383856165627"></a><a href="Core.md#ga0f3d81b5ff5d3896f7d8cf15f76b451e">DevicePreload</a> { <a href="Core.md#gga0f3d81b5ff5d3896f7d8cf15f76b451ea0fd51c3697833ef66f7ff68adb96a04d">DEVICE_PRELOAD_ENABLE</a> = 0, <a href="Core.md#gga0f3d81b5ff5d3896f7d8cf15f76b451ea2c36597f3f647a621ab56b666ed6cb3e">DEVICE_PRELOAD_DISABLE</a>, <a href="Core.md#gga0f3d81b5ff5d3896f7d8cf15f76b451ea679c4d6dabdd7795bdbfaee5cc26367e">DEVICE_PRELOAD_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p643268086165627"><a name="p643268086165627"></a><a name="p643268086165627"></a>Enumerates driver loading policies. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1966142916165627"></a>
<table><thead align="left"><tr id="row1250163885165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1470099893165627"><a name="p1470099893165627"></a><a name="p1470099893165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p152029452165627"><a name="p152029452165627"></a><a name="p152029452165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1805261208165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p286022033165627"><a name="p286022033165627"></a><a name="p286022033165627"></a><a href="Core.md#gab28c6481fc79bd055e2551abebb841bf">DevSvcManagerClntGetService</a> (const char *svcName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1555856738165627"><a name="p1555856738165627"></a><a name="p1555856738165627"></a>const struct <a href="HdfObject.md">HdfObject</a> * </p>
<p id="p177466674165627"><a name="p177466674165627"></a><a name="p177466674165627"></a>Obtains the driver service object based on a driver service name. </p>
</td>
</tr>
<tr id="row671782114165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p838157417165627"><a name="p838157417165627"></a><a name="p838157417165627"></a><a href="Core.md#gac899589dfa47b45f43b8dd027b65b5d9">HdfDeviceGetServiceName</a> (const struct <a href="HdfDeviceObject.md">HdfDeviceObject</a> *deviceObject)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p147766874165627"><a name="p147766874165627"></a><a name="p147766874165627"></a>const char * </p>
<p id="p420740179165627"><a name="p420740179165627"></a><a name="p420740179165627"></a>Obtains the service name of a driver. </p>
</td>
</tr>
<tr id="row856013652165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p544997645165627"><a name="p544997645165627"></a><a name="p544997645165627"></a><a href="Core.md#ga224908f55daa1b9553841735e5f1f65c">HdfDeviceSubscribeService</a> (struct <a href="HdfDeviceObject.md">HdfDeviceObject</a> *deviceObject, const char *serviceName, struct <a href="SubscriberCallback.md">SubscriberCallback</a> callback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p57098871165627"><a name="p57098871165627"></a><a name="p57098871165627"></a>int32_t </p>
<p id="p1876997693165627"><a name="p1876997693165627"></a><a name="p1876997693165627"></a>Subscribes to a driver service. </p>
</td>
</tr>
<tr id="row1807839190165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1885402695165627"><a name="p1885402695165627"></a><a name="p1885402695165627"></a><a href="Core.md#gac9670df1316b5ddd651a50ebee0b6557">HdfDeviceSendEvent</a> (const struct <a href="HdfDeviceObject.md">HdfDeviceObject</a> *deviceObject, uint32_t id, const struct <a href="HdfSBuf.md">HdfSBuf</a> *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1552666759165627"><a name="p1552666759165627"></a><a name="p1552666759165627"></a>int32_t </p>
<p id="p107786636165627"><a name="p107786636165627"></a><a name="p107786636165627"></a>Sends event messages. </p>
</td>
</tr>
<tr id="row1939225584165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p324981974165627"><a name="p324981974165627"></a><a name="p324981974165627"></a><a href="Core.md#ga9c47da8d82820bce2d32051324480f45">HdfDeviceSendEventToClient</a> (const struct <a href="HdfDeviceIoClient.md">HdfDeviceIoClient</a> *client, uint32_t id, const struct <a href="HdfSBuf.md">HdfSBuf</a> *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1117861959165627"><a name="p1117861959165627"></a><a name="p1117861959165627"></a>int32_t </p>
<p id="p824150765165627"><a name="p824150765165627"></a><a name="p824150765165627"></a>Sends an event message to a specified client object. </p>
</td>
</tr>
</tbody>
</table>

