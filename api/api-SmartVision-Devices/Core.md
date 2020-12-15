# Core<a name="ZH-CN_TOPIC_0000001054718073"></a>

-   [Overview](#section1091526830165623)
-   [Summary](#section1644000024165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section642258245165623)
-   [Macro Definition](#section917737689165623)
-   [HDF\_INIT](#ga99831072fdca13e3c423a14fa6a83c34)
-   [Typedef](#section1250679194165623)
-   [OnEventReceived](#gae314b850ba4b0927007038cf8cc32580)
-   [Enumeration Type](#section1155043563165623)
-   [DevicePreload](#ga0f3d81b5ff5d3896f7d8cf15f76b451e)
-   [ServicePolicy](#ga172844da8a6908bf7226eee703ad9f80)
-   [Function](#section692951378165623)
-   [DevSvcManagerClntGetService\(\)](#gab28c6481fc79bd055e2551abebb841bf)
-   [HdfDeviceGetServiceName\(\)](#gac899589dfa47b45f43b8dd027b65b5d9)
-   [HdfDeviceRegisterEventListener\(\)](#gaa7855b3930b5378954927548e5623663)
-   [HdfDeviceSendEvent\(\)](#gac9670df1316b5ddd651a50ebee0b6557)
-   [HdfDeviceSendEventToClient\(\)](#ga9c47da8d82820bce2d32051324480f45)
-   [HdfDeviceSubscribeService\(\)](#ga224908f55daa1b9553841735e5f1f65c)
-   [HdfDeviceUnregisterEventListener\(\)](#gab95668359f0b6a47f48c47541caed7fd)
-   [HdfIoServiceBind\(\)](#ga31198b68423805193274d3973c178ab5)
-   [HdfIoServiceRecycle\(\)](#gada2867af690aac9e6c3b2c8812b3037c)
-   [HdfSBufBind\(\)](#gabcc9a442a3b2615828d60a1d4664b4a9)
-   [HdfSBufCopy\(\)](#ga406275df686ff556fd5bdb20349e4972)
-   [HdfSbufFlush\(\)](#ga2b7a5750bf42151edd7bd686fb11a39d)
-   [HdfSbufGetCapacity\(\)](#ga74941de5883ae39cb6103591f67dbea0)
-   [HdfSbufGetData\(\)](#ga3f4f5fdb03f64c23f318ecf7c602ac59)
-   [HdfSbufGetDataSize\(\)](#gaf983c174acfb5b1f8f9dc5b6c2f52e0d)
-   [HdfSBufMove\(\)](#ga22d4a953c89a941337e593647ebe2f5b)
-   [HdfSBufObtain\(\)](#ga5e3dee8b1a2128da70cc5718b631c8ba)
-   [HdfSBufObtainDefaultSize\(\)](#ga479315c09d0d927aa211de829388122d)
-   [HdfSbufReadBuffer\(\)](#ga345e8524a6cea44a0424e23b8f659792)
-   [HdfSbufReadInt16\(\)](#ga3fce62cbc34a70259d21399d5ff91b32)
-   [HdfSbufReadInt32\(\)](#ga22e7b97735f54e57c0d3bed2fa3a47c4)
-   [HdfSbufReadInt64\(\)](#ga7fb121b4351f85e1735c6e63a5c951cc)
-   [HdfSbufReadInt8\(\)](#gafff778f76f9142602ef25e8afff47c83)
-   [HdfSbufReadString\(\)](#gab03aa25c90fda50138496b0f874a664e)
-   [HdfSbufReadUint16\(\)](#gabc151ad38bdecd5589623a6298c31930)
-   [HdfSbufReadUint32\(\)](#gac953788575b0c22947f18fa9f19a5bf5)
-   [HdfSbufReadUint64\(\)](#gabb10a71c031d3633c5745ba6fd62b0a4)
-   [HdfSbufReadUint8\(\)](#ga07d93e6bcd8a6a8646067783d6f46e74)
-   [HdfSBufRecycle\(\)](#gaa0041d238cfc7cf00779191aa58e7ee0)
-   [HdfSbufTransDataOwnership\(\)](#gaf391e9f47cc668daf3150c00f369bf1f)
-   [HdfSbufWriteBuffer\(\)](#ga567eb533aa53051d0beec43f08e72dd8)
-   [HdfSbufWriteInt16\(\)](#gaaa278bf9aa182a4c65c390c6c9ff06d2)
-   [HdfSbufWriteInt32\(\)](#ga3913510d670da2f8ffa3103b5ff293f1)
-   [HdfSbufWriteInt64\(\)](#ga7c63eb006b19e2aac43c23318c4ebe3b)
-   [HdfSbufWriteInt8\(\)](#gac514c3debd605043ad1bfa9c05a115a0)
-   [HdfSbufWriteString\(\)](#gaf782f8a08dcd81f4038ab9d9bbc1cf9b)
-   [HdfSbufWriteUint16\(\)](#ga31c9edfd9b20d6e44d34839efa0e08f7)
-   [HdfSbufWriteUint32\(\)](#ga23f2331cdfb0bf91a29f47f20ffd50df)
-   [HdfSbufWriteUint64\(\)](#ga164de95ad00302b599290bdb476a032f)
-   [HdfSbufWriteUint8\(\)](#gafb4fe74246f85a158c140bf4c4951256)

## **Overview**<a name="section1091526830165623"></a>

**Description:**

Provides OpenHarmony Driver Foundation \(HDF\) APIs. 

The HDF implements driver framework capabilities such as driver loading, service management, and driver message model. You can develop drivers based on the HDF.

**Since:**

1.0

## **Summary**<a name="section1644000024165623"></a>

## Files<a name="files"></a>

<a name="table1203785706165623"></a>
<table><thead align="left"><tr id="row1854810185165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p10208035165623"><a name="p10208035165623"></a><a name="p10208035165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1103899874165623"><a name="p1103899874165623"></a><a name="p1103899874165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row495078936165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p560742801165623"><a name="p560742801165623"></a><a name="p560742801165623"></a><a href="hdf_device_desc-h.md">hdf_device_desc.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p521205906165623"><a name="p521205906165623"></a><a name="p521205906165623"></a>Declares functions related to driver loading, service obtaining, and power management. </p>
</td>
</tr>
<tr id="row2077092536165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p631674224165623"><a name="p631674224165623"></a><a name="p631674224165623"></a><a href="hdf_io_service_if-h.md">hdf_io_service_if.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1557651958165623"><a name="p1557651958165623"></a><a name="p1557651958165623"></a>Declares the structures defining driver service objects and event listeners, as well as the functions for obtaining a driver service object, dispatching a driver service call, and registering or unregistering an event listener. </p>
</td>
</tr>
<tr id="row755748411165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1550364637165623"><a name="p1550364637165623"></a><a name="p1550364637165623"></a><a href="hdf_object-h.md">hdf_object.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p442124739165623"><a name="p442124739165623"></a><a name="p442124739165623"></a>Declares the base object provided by the HDF for the driver. </p>
</td>
</tr>
<tr id="row584865483165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1094652429165623"><a name="p1094652429165623"></a><a name="p1094652429165623"></a><a href="hdf_sbuf-h.md">hdf_sbuf.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1985298839165623"><a name="p1985298839165623"></a><a name="p1985298839165623"></a>Defines functions related to a <strong id="b1708571075165623"><a name="b1708571075165623"></a><a name="b1708571075165623"></a><a href="HdfSBuf.md">HdfSBuf</a></strong>. The HDF provides data serialization and deserialization capabilities for data transmission between user-mode applications and kernel-mode drivers. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table107466402165623"></a>
<table><thead align="left"><tr id="row866217556165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1804256393165623"><a name="p1804256393165623"></a><a name="p1804256393165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p433226351165623"><a name="p433226351165623"></a><a name="p433226351165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1145453619165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1626926716165623"><a name="p1626926716165623"></a><a name="p1626926716165623"></a><a href="HdfDeviceObject.md">HdfDeviceObject</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1228822917165623"><a name="p1228822917165623"></a><a name="p1228822917165623"></a>Defines the device object. </p>
</td>
</tr>
<tr id="row739740763165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1874719343165623"><a name="p1874719343165623"></a><a name="p1874719343165623"></a><a href="HdfDeviceIoClient.md">HdfDeviceIoClient</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p642166398165623"><a name="p642166398165623"></a><a name="p642166398165623"></a>Defines the client object structure of the I/O service. </p>
</td>
</tr>
<tr id="row533962172165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1787387579165623"><a name="p1787387579165623"></a><a name="p1787387579165623"></a><a href="IDeviceIoService.md">IDeviceIoService</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p27186204165623"><a name="p27186204165623"></a><a name="p27186204165623"></a>Defines the driver service. </p>
</td>
</tr>
<tr id="row1760992218165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p798877469165623"><a name="p798877469165623"></a><a name="p798877469165623"></a><a href="SubscriberCallback.md">SubscriberCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p156854962165623"><a name="p156854962165623"></a><a name="p156854962165623"></a>Called when the driver subscribes to other driver services. </p>
</td>
</tr>
<tr id="row1982087632165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p456500101165623"><a name="p456500101165623"></a><a name="p456500101165623"></a><a href="IPowerEventListener.md">IPowerEventListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p476973405165623"><a name="p476973405165623"></a><a name="p476973405165623"></a>Defines the power management functions provided by the HDF for the driver. </p>
</td>
</tr>
<tr id="row1066807730165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1962420145165623"><a name="p1962420145165623"></a><a name="p1962420145165623"></a><a href="HdfDriverEntry.md">HdfDriverEntry</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1640360841165623"><a name="p1640360841165623"></a><a name="p1640360841165623"></a>Defines the entry structure of the driver in the HDF. </p>
</td>
</tr>
<tr id="row1122389662165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1956906292165623"><a name="p1956906292165623"></a><a name="p1956906292165623"></a><a href="HdfDevEventlistener.md">HdfDevEventlistener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1155311309165623"><a name="p1155311309165623"></a><a name="p1155311309165623"></a>Defines a driver event listener object. </p>
</td>
</tr>
<tr id="row628961171165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p946669355165623"><a name="p946669355165623"></a><a name="p946669355165623"></a><a href="HdfIoDispatcher.md">HdfIoDispatcher</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2047267206165623"><a name="p2047267206165623"></a><a name="p2047267206165623"></a>Defines a driver service call dispatcher. </p>
</td>
</tr>
<tr id="row1528149091165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p722495713165623"><a name="p722495713165623"></a><a name="p722495713165623"></a><a href="HdfIoService.md">HdfIoService</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p64997634165623"><a name="p64997634165623"></a><a name="p64997634165623"></a>Defines a driver service object. </p>
</td>
</tr>
<tr id="row1974809872165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p613171957165623"><a name="p613171957165623"></a><a name="p613171957165623"></a><a href="HdfObject.md">HdfObject</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p602605739165623"><a name="p602605739165623"></a><a name="p602605739165623"></a>Describes base class objects defined by the HDF. </p>
</td>
</tr>
<tr id="row1928207441165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1609761668165623"><a name="p1609761668165623"></a><a name="p1609761668165623"></a><a href="HdfSBuf.md">HdfSBuf</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1226310672165623"><a name="p1226310672165623"></a><a name="p1226310672165623"></a>Defines a <strong id="b1060743080165623"><a name="b1060743080165623"></a><a name="b1060743080165623"></a><a href="HdfSBuf.md">HdfSBuf</a></strong>. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1064583754165623"></a>
<table><thead align="left"><tr id="row292147800165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p490396830165623"><a name="p490396830165623"></a><a name="p490396830165623"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1060395738165623"><a name="p1060395738165623"></a><a name="p1060395738165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row201999157165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1758542491165623"><a name="p1758542491165623"></a><a name="p1758542491165623"></a><em id="ga5957e60db74b1b0703ebd1c53f964d48"><a name="ga5957e60db74b1b0703ebd1c53f964d48"></a><a name="ga5957e60db74b1b0703ebd1c53f964d48"></a></em>MAX_PRIORITY_NUM    200</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2039455547165623"><a name="p2039455547165623"></a><a name="p2039455547165623"></a>The maximum priority for loading the host and device. </p>
</td>
</tr>
<tr id="row1221314169165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p239783207165623"><a name="p239783207165623"></a><a name="p239783207165623"></a><a href="Core.md#ga99831072fdca13e3c423a14fa6a83c34">HDF_INIT</a>(module)   HDF_DRIVER_INIT(module)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p623346043165623"><a name="p623346043165623"></a><a name="p623346043165623"></a>Registers the driver with the HDF. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table802143826165623"></a>
<table><thead align="left"><tr id="row1410745716165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p634237031165623"><a name="p634237031165623"></a><a name="p634237031165623"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1154540702165623"><a name="p1154540702165623"></a><a name="p1154540702165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row877736117165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1255816128165623"><a name="p1255816128165623"></a><a name="p1255816128165623"></a><a href="Core.md#gae314b850ba4b0927007038cf8cc32580">OnEventReceived</a>) (void *priv, uint32_t id, struct <a href="HdfSBuf.md">HdfSBuf</a> *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1262191130165623"><a name="p1262191130165623"></a><a name="p1262191130165623"></a>typedef int(* </p>
<p id="p670482111165623"><a name="p670482111165623"></a><a name="p670482111165623"></a>Called when a driver event occurs. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1363573863165623"></a>
<table><thead align="left"><tr id="row1567412698165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1336052135165623"><a name="p1336052135165623"></a><a name="p1336052135165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p283173221165623"><a name="p283173221165623"></a><a name="p283173221165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1058235143165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1178483198165623"><a name="p1178483198165623"></a><a name="p1178483198165623"></a><a href="Core.md#ga172844da8a6908bf7226eee703ad9f80">ServicePolicy</a> {   <a href="Core.md#gga172844da8a6908bf7226eee703ad9f80aeed8de39f7a8c5a5be1f7b8beb7221e1">SERVICE_POLICY_NONE</a> = 0, <a href="Core.md#gga172844da8a6908bf7226eee703ad9f80a5ec1b4a05e5ba37c9bf58f039fe2c245">SERVICE_POLICY_PUBLIC</a>, <a href="Core.md#gga172844da8a6908bf7226eee703ad9f80a9a398765ae7bad9ce86e12a91683334c">SERVICE_POLICY_CAPACITY</a>, <a href="Core.md#gga172844da8a6908bf7226eee703ad9f80ac2fe21ccc86fbb38747c733716a6b2e0">SERVICE_POLICY_FRIENDLY</a>,   <a href="Core.md#gga172844da8a6908bf7226eee703ad9f80ac7918e4a8fa4a2c29ccc8bf97537b61c">SERVICE_POLICY_PRIVATE</a>, <a href="Core.md#gga172844da8a6908bf7226eee703ad9f80a423a5d22d00f6a45f0281dd287fc3b4d">SERVICE_POLICY_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p454753225165623"><a name="p454753225165623"></a><a name="p454753225165623"></a>Enumerates policies for releasing driver services developed based on the HDF. </p>
</td>
</tr>
<tr id="row1087024670165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p885074591165623"><a name="p885074591165623"></a><a name="p885074591165623"></a><a href="Core.md#ga0f3d81b5ff5d3896f7d8cf15f76b451e">DevicePreload</a> { <a href="Core.md#gga0f3d81b5ff5d3896f7d8cf15f76b451ea0fd51c3697833ef66f7ff68adb96a04d">DEVICE_PRELOAD_ENABLE</a> = 0, <a href="Core.md#gga0f3d81b5ff5d3896f7d8cf15f76b451ea2c36597f3f647a621ab56b666ed6cb3e">DEVICE_PRELOAD_DISABLE</a>, <a href="Core.md#gga0f3d81b5ff5d3896f7d8cf15f76b451ea679c4d6dabdd7795bdbfaee5cc26367e">DEVICE_PRELOAD_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1832723004165623"><a name="p1832723004165623"></a><a name="p1832723004165623"></a>Enumerates driver loading policies. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table662889268165623"></a>
<table><thead align="left"><tr id="row467419335165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1653869157165623"><a name="p1653869157165623"></a><a name="p1653869157165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p705919191165623"><a name="p705919191165623"></a><a name="p705919191165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row212059075165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1640732706165623"><a name="p1640732706165623"></a><a name="p1640732706165623"></a><a href="Core.md#gab28c6481fc79bd055e2551abebb841bf">DevSvcManagerClntGetService</a> (const char *svcName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p198728472165623"><a name="p198728472165623"></a><a name="p198728472165623"></a>const struct <a href="HdfObject.md">HdfObject</a> * </p>
<p id="p85773770165623"><a name="p85773770165623"></a><a name="p85773770165623"></a>Obtains the driver service object based on a driver service name. </p>
</td>
</tr>
<tr id="row533062967165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1639337060165623"><a name="p1639337060165623"></a><a name="p1639337060165623"></a><a href="Core.md#gac899589dfa47b45f43b8dd027b65b5d9">HdfDeviceGetServiceName</a> (const struct <a href="HdfDeviceObject.md">HdfDeviceObject</a> *deviceObject)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2062659143165623"><a name="p2062659143165623"></a><a name="p2062659143165623"></a>const char * </p>
<p id="p895982775165623"><a name="p895982775165623"></a><a name="p895982775165623"></a>Obtains the service name of a driver. </p>
</td>
</tr>
<tr id="row1431313246165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p903257543165623"><a name="p903257543165623"></a><a name="p903257543165623"></a><a href="Core.md#ga224908f55daa1b9553841735e5f1f65c">HdfDeviceSubscribeService</a> (struct <a href="HdfDeviceObject.md">HdfDeviceObject</a> *deviceObject, const char *serviceName, struct <a href="SubscriberCallback.md">SubscriberCallback</a> callback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1396227787165623"><a name="p1396227787165623"></a><a name="p1396227787165623"></a>int32_t </p>
<p id="p118382299165623"><a name="p118382299165623"></a><a name="p118382299165623"></a>Subscribes to a driver service. </p>
</td>
</tr>
<tr id="row1245343810165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1934338332165623"><a name="p1934338332165623"></a><a name="p1934338332165623"></a><a href="Core.md#gac9670df1316b5ddd651a50ebee0b6557">HdfDeviceSendEvent</a> (const struct <a href="HdfDeviceObject.md">HdfDeviceObject</a> *deviceObject, uint32_t id, const struct <a href="HdfSBuf.md">HdfSBuf</a> *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p768109417165623"><a name="p768109417165623"></a><a name="p768109417165623"></a>int32_t </p>
<p id="p1933017329165623"><a name="p1933017329165623"></a><a name="p1933017329165623"></a>Sends event messages. </p>
</td>
</tr>
<tr id="row887179579165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1455277913165623"><a name="p1455277913165623"></a><a name="p1455277913165623"></a><a href="Core.md#ga9c47da8d82820bce2d32051324480f45">HdfDeviceSendEventToClient</a> (const struct <a href="HdfDeviceIoClient.md">HdfDeviceIoClient</a> *client, uint32_t id, const struct <a href="HdfSBuf.md">HdfSBuf</a> *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p617236651165623"><a name="p617236651165623"></a><a name="p617236651165623"></a>int32_t </p>
<p id="p183439850165623"><a name="p183439850165623"></a><a name="p183439850165623"></a>Sends an event message to a specified client object. </p>
</td>
</tr>
<tr id="row1537608603165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1264823908165623"><a name="p1264823908165623"></a><a name="p1264823908165623"></a><a href="Core.md#ga31198b68423805193274d3973c178ab5">HdfIoServiceBind</a> (const char *serviceName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p27871620165623"><a name="p27871620165623"></a><a name="p27871620165623"></a>struct <a href="HdfIoService.md">HdfIoService</a> * </p>
<p id="p519737280165623"><a name="p519737280165623"></a><a name="p519737280165623"></a>Obtains a driver service object. </p>
</td>
</tr>
<tr id="row777885673165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1152273330165623"><a name="p1152273330165623"></a><a name="p1152273330165623"></a><a href="Core.md#gada2867af690aac9e6c3b2c8812b3037c">HdfIoServiceRecycle</a> (struct <a href="HdfIoService.md">HdfIoService</a> *service)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1922949056165623"><a name="p1922949056165623"></a><a name="p1922949056165623"></a>void </p>
<p id="p828343957165623"><a name="p828343957165623"></a><a name="p828343957165623"></a>Destroys a specified driver service object to release resources if it is no longer required. </p>
</td>
</tr>
<tr id="row1485556064165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1882152647165623"><a name="p1882152647165623"></a><a name="p1882152647165623"></a><a href="Core.md#gaa7855b3930b5378954927548e5623663">HdfDeviceRegisterEventListener</a> (struct <a href="HdfIoService.md">HdfIoService</a> *target, struct <a href="HdfDevEventlistener.md">HdfDevEventlistener</a> *listener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p978348185165623"><a name="p978348185165623"></a><a name="p978348185165623"></a>int </p>
<p id="p1572874146165623"><a name="p1572874146165623"></a><a name="p1572874146165623"></a>Registers a custom <a href="HdfDevEventlistener.md">HdfDevEventlistener</a> for listening for events reported by a specified driver service object. </p>
</td>
</tr>
<tr id="row1976666907165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p472126107165623"><a name="p472126107165623"></a><a name="p472126107165623"></a><a href="Core.md#gab95668359f0b6a47f48c47541caed7fd">HdfDeviceUnregisterEventListener</a> (struct <a href="HdfIoService.md">HdfIoService</a> *target, struct <a href="HdfDevEventlistener.md">HdfDevEventlistener</a> *listener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2086196698165623"><a name="p2086196698165623"></a><a name="p2086196698165623"></a>int </p>
<p id="p854345823165623"><a name="p854345823165623"></a><a name="p854345823165623"></a>Unregisters a previously registered <a href="HdfDevEventlistener.md">HdfDevEventlistener</a> to release resources if it is no longer required. </p>
</td>
</tr>
<tr id="row1213214934165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p969071577165623"><a name="p969071577165623"></a><a name="p969071577165623"></a><a href="Core.md#ga567eb533aa53051d0beec43f08e72dd8">HdfSbufWriteBuffer</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, const void *data, uint32_t writeSize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1579925114165623"><a name="p1579925114165623"></a><a name="p1579925114165623"></a>bool </p>
<p id="p1998779901165623"><a name="p1998779901165623"></a><a name="p1998779901165623"></a>Writes a data segment to a <strong id="b1315466502165623"><a name="b1315466502165623"></a><a name="b1315466502165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row2039259618165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p498467552165623"><a name="p498467552165623"></a><a name="p498467552165623"></a><a href="Core.md#ga164de95ad00302b599290bdb476a032f">HdfSbufWriteUint64</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, uint64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p520911280165623"><a name="p520911280165623"></a><a name="p520911280165623"></a>bool </p>
<p id="p1891993308165623"><a name="p1891993308165623"></a><a name="p1891993308165623"></a>Writes a 64-bit unsigned integer to a <strong id="b1945894404165623"><a name="b1945894404165623"></a><a name="b1945894404165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row476606811165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1723986608165623"><a name="p1723986608165623"></a><a name="p1723986608165623"></a><a href="Core.md#ga23f2331cdfb0bf91a29f47f20ffd50df">HdfSbufWriteUint32</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, uint32_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1591761769165623"><a name="p1591761769165623"></a><a name="p1591761769165623"></a>bool </p>
<p id="p1650102451165623"><a name="p1650102451165623"></a><a name="p1650102451165623"></a>Writes a 32-bit unsigned integer to a <strong id="b1446830572165623"><a name="b1446830572165623"></a><a name="b1446830572165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row709219302165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2058894865165623"><a name="p2058894865165623"></a><a name="p2058894865165623"></a><a href="Core.md#ga31c9edfd9b20d6e44d34839efa0e08f7">HdfSbufWriteUint16</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, uint16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p757736458165623"><a name="p757736458165623"></a><a name="p757736458165623"></a>bool </p>
<p id="p1267115084165623"><a name="p1267115084165623"></a><a name="p1267115084165623"></a>Writes a 16-bit unsigned integer to a <strong id="b846513924165623"><a name="b846513924165623"></a><a name="b846513924165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row353821621165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p917510250165623"><a name="p917510250165623"></a><a name="p917510250165623"></a><a href="Core.md#gafb4fe74246f85a158c140bf4c4951256">HdfSbufWriteUint8</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, uint8_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1017097402165623"><a name="p1017097402165623"></a><a name="p1017097402165623"></a>bool </p>
<p id="p634482669165623"><a name="p634482669165623"></a><a name="p634482669165623"></a>Writes an 8-bit unsigned integer to a <strong id="b831053205165623"><a name="b831053205165623"></a><a name="b831053205165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row518138915165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1007709180165623"><a name="p1007709180165623"></a><a name="p1007709180165623"></a><a href="Core.md#ga7c63eb006b19e2aac43c23318c4ebe3b">HdfSbufWriteInt64</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1091136786165623"><a name="p1091136786165623"></a><a name="p1091136786165623"></a>bool </p>
<p id="p808545283165623"><a name="p808545283165623"></a><a name="p808545283165623"></a>Writes a 64-bit signed integer to a <strong id="b1768802842165623"><a name="b1768802842165623"></a><a name="b1768802842165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1468998206165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1482283442165623"><a name="p1482283442165623"></a><a name="p1482283442165623"></a><a href="Core.md#ga3913510d670da2f8ffa3103b5ff293f1">HdfSbufWriteInt32</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, int32_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1449294790165623"><a name="p1449294790165623"></a><a name="p1449294790165623"></a>bool </p>
<p id="p1679675558165623"><a name="p1679675558165623"></a><a name="p1679675558165623"></a>Writes a 32-bit signed integer to a <strong id="b603499206165623"><a name="b603499206165623"></a><a name="b603499206165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row544349520165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p267678291165623"><a name="p267678291165623"></a><a name="p267678291165623"></a><a href="Core.md#gaaa278bf9aa182a4c65c390c6c9ff06d2">HdfSbufWriteInt16</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, int16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1553223548165623"><a name="p1553223548165623"></a><a name="p1553223548165623"></a>bool </p>
<p id="p632175594165623"><a name="p632175594165623"></a><a name="p632175594165623"></a>Writes a 16-bit signed integer to a <strong id="b411244232165623"><a name="b411244232165623"></a><a name="b411244232165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row425176811165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p927701654165623"><a name="p927701654165623"></a><a name="p927701654165623"></a><a href="Core.md#gac514c3debd605043ad1bfa9c05a115a0">HdfSbufWriteInt8</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, int8_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1764958410165623"><a name="p1764958410165623"></a><a name="p1764958410165623"></a>bool </p>
<p id="p301866505165623"><a name="p301866505165623"></a><a name="p301866505165623"></a>Writes an 8-bit signed integer to a <strong id="b1131229156165623"><a name="b1131229156165623"></a><a name="b1131229156165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1475315228165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1981737830165623"><a name="p1981737830165623"></a><a name="p1981737830165623"></a><a href="Core.md#gaf782f8a08dcd81f4038ab9d9bbc1cf9b">HdfSbufWriteString</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, const char *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p650530584165623"><a name="p650530584165623"></a><a name="p650530584165623"></a>bool </p>
<p id="p1125911368165623"><a name="p1125911368165623"></a><a name="p1125911368165623"></a>Writes a string to a <strong id="b1936536013165623"><a name="b1936536013165623"></a><a name="b1936536013165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1915882160165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p936728383165623"><a name="p936728383165623"></a><a name="p936728383165623"></a><a href="Core.md#ga345e8524a6cea44a0424e23b8f659792">HdfSbufReadBuffer</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, const void **data, uint32_t *readSize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1999765623165623"><a name="p1999765623165623"></a><a name="p1999765623165623"></a>bool </p>
<p id="p206714543165623"><a name="p206714543165623"></a><a name="p206714543165623"></a>Reads a data segment from a <strong id="b1403038004165623"><a name="b1403038004165623"></a><a name="b1403038004165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1101486895165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p602210853165623"><a name="p602210853165623"></a><a name="p602210853165623"></a><a href="Core.md#gabb10a71c031d3633c5745ba6fd62b0a4">HdfSbufReadUint64</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, uint64_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1509617100165623"><a name="p1509617100165623"></a><a name="p1509617100165623"></a>bool </p>
<p id="p1606949792165623"><a name="p1606949792165623"></a><a name="p1606949792165623"></a>Reads a 64-bit unsigned integer from a <strong id="b1690346314165623"><a name="b1690346314165623"></a><a name="b1690346314165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row198959219165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p879155049165623"><a name="p879155049165623"></a><a name="p879155049165623"></a><a href="Core.md#gac953788575b0c22947f18fa9f19a5bf5">HdfSbufReadUint32</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, uint32_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1456763319165623"><a name="p1456763319165623"></a><a name="p1456763319165623"></a>bool </p>
<p id="p1670519217165623"><a name="p1670519217165623"></a><a name="p1670519217165623"></a>Reads a 32-bit unsigned integer from a <strong id="b1161499106165623"><a name="b1161499106165623"></a><a name="b1161499106165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1774758603165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2140856948165623"><a name="p2140856948165623"></a><a name="p2140856948165623"></a><a href="Core.md#gabc151ad38bdecd5589623a6298c31930">HdfSbufReadUint16</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, uint16_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p12781661165623"><a name="p12781661165623"></a><a name="p12781661165623"></a>bool </p>
<p id="p1299015510165623"><a name="p1299015510165623"></a><a name="p1299015510165623"></a>Reads a 16-bit unsigned integer from a <strong id="b359804181165623"><a name="b359804181165623"></a><a name="b359804181165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1310702018165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p655193231165623"><a name="p655193231165623"></a><a name="p655193231165623"></a><a href="Core.md#ga07d93e6bcd8a6a8646067783d6f46e74">HdfSbufReadUint8</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, uint8_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p486608209165623"><a name="p486608209165623"></a><a name="p486608209165623"></a>bool </p>
<p id="p2111964746165623"><a name="p2111964746165623"></a><a name="p2111964746165623"></a>Reads an 8-bit unsigned integer from a <strong id="b1103898522165623"><a name="b1103898522165623"></a><a name="b1103898522165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1093041774165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p554951229165623"><a name="p554951229165623"></a><a name="p554951229165623"></a><a href="Core.md#ga7fb121b4351f85e1735c6e63a5c951cc">HdfSbufReadInt64</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, int64_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1813097153165623"><a name="p1813097153165623"></a><a name="p1813097153165623"></a>bool </p>
<p id="p989369840165623"><a name="p989369840165623"></a><a name="p989369840165623"></a>Reads a 64-bit signed integer from a <strong id="b772958706165623"><a name="b772958706165623"></a><a name="b772958706165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row3548665165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1923252111165623"><a name="p1923252111165623"></a><a name="p1923252111165623"></a><a href="Core.md#ga22e7b97735f54e57c0d3bed2fa3a47c4">HdfSbufReadInt32</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, int32_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1033935027165623"><a name="p1033935027165623"></a><a name="p1033935027165623"></a>bool </p>
<p id="p136825611165623"><a name="p136825611165623"></a><a name="p136825611165623"></a>Reads a 32-bit signed integer from a <strong id="b1672147199165623"><a name="b1672147199165623"></a><a name="b1672147199165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1320285253165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1755194879165623"><a name="p1755194879165623"></a><a name="p1755194879165623"></a><a href="Core.md#ga3fce62cbc34a70259d21399d5ff91b32">HdfSbufReadInt16</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, int16_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1783630983165623"><a name="p1783630983165623"></a><a name="p1783630983165623"></a>bool </p>
<p id="p829375253165623"><a name="p829375253165623"></a><a name="p829375253165623"></a>Reads a 16-bit signed integer from a <strong id="b870209586165623"><a name="b870209586165623"></a><a name="b870209586165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row952389669165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p568760449165623"><a name="p568760449165623"></a><a name="p568760449165623"></a><a href="Core.md#gafff778f76f9142602ef25e8afff47c83">HdfSbufReadInt8</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf, int8_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1072771554165623"><a name="p1072771554165623"></a><a name="p1072771554165623"></a>bool </p>
<p id="p1228712743165623"><a name="p1228712743165623"></a><a name="p1228712743165623"></a>Reads an 8-bit signed integer from a <strong id="b898841743165623"><a name="b898841743165623"></a><a name="b898841743165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1330682335165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1202725650165623"><a name="p1202725650165623"></a><a name="p1202725650165623"></a><a href="Core.md#gab03aa25c90fda50138496b0f874a664e">HdfSbufReadString</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1627525323165623"><a name="p1627525323165623"></a><a name="p1627525323165623"></a>const char * </p>
<p id="p1461627657165623"><a name="p1461627657165623"></a><a name="p1461627657165623"></a>Reads a string from a <strong id="b454990845165623"><a name="b454990845165623"></a><a name="b454990845165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row747428727165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1845166382165623"><a name="p1845166382165623"></a><a name="p1845166382165623"></a><a href="Core.md#ga3f4f5fdb03f64c23f318ecf7c602ac59">HdfSbufGetData</a> (const struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1095452528165623"><a name="p1095452528165623"></a><a name="p1095452528165623"></a>uint8_t * </p>
<p id="p1408476434165623"><a name="p1408476434165623"></a><a name="p1408476434165623"></a>Obtains the pointer to the data stored in a<strong id="b899000684165623"><a name="b899000684165623"></a><a name="b899000684165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1208251361165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1081479846165623"><a name="p1081479846165623"></a><a name="p1081479846165623"></a><a href="Core.md#ga2b7a5750bf42151edd7bd686fb11a39d">HdfSbufFlush</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1800842560165623"><a name="p1800842560165623"></a><a name="p1800842560165623"></a>void </p>
<p id="p461999770165623"><a name="p461999770165623"></a><a name="p461999770165623"></a>Clears the data stored in a <strong id="b1342308381165623"><a name="b1342308381165623"></a><a name="b1342308381165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1917127364165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p949785578165623"><a name="p949785578165623"></a><a name="p949785578165623"></a><a href="Core.md#ga74941de5883ae39cb6103591f67dbea0">HdfSbufGetCapacity</a> (const struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p181346554165623"><a name="p181346554165623"></a><a name="p181346554165623"></a>size_t </p>
<p id="p939894242165623"><a name="p939894242165623"></a><a name="p939894242165623"></a>Obtains the capacity of a <strong id="b618890149165623"><a name="b618890149165623"></a><a name="b618890149165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row239949313165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p736448283165623"><a name="p736448283165623"></a><a name="p736448283165623"></a><a href="Core.md#gaf983c174acfb5b1f8f9dc5b6c2f52e0d">HdfSbufGetDataSize</a> (const struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p483481856165623"><a name="p483481856165623"></a><a name="p483481856165623"></a>size_t </p>
<p id="p1270756287165623"><a name="p1270756287165623"></a><a name="p1270756287165623"></a>Obtains the size of the data stored in a <strong id="b1803288867165623"><a name="b1803288867165623"></a><a name="b1803288867165623"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row2082293903165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1693908756165623"><a name="p1693908756165623"></a><a name="p1693908756165623"></a><a href="Core.md#ga5e3dee8b1a2128da70cc5718b631c8ba">HdfSBufObtain</a> (size_t capacity)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1155144981165623"><a name="p1155144981165623"></a><a name="p1155144981165623"></a>struct <a href="HdfSBuf.md">HdfSBuf</a> * </p>
<p id="p431008626165623"><a name="p431008626165623"></a><a name="p431008626165623"></a>Obtains a <strong id="b470223663165623"><a name="b470223663165623"></a><a name="b470223663165623"></a>SBuf</strong> instance. </p>
</td>
</tr>
<tr id="row2033179779165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2061327476165623"><a name="p2061327476165623"></a><a name="p2061327476165623"></a><a href="Core.md#ga479315c09d0d927aa211de829388122d">HdfSBufObtainDefaultSize</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1274469229165623"><a name="p1274469229165623"></a><a name="p1274469229165623"></a>struct <a href="HdfSBuf.md">HdfSBuf</a> * </p>
<p id="p1383947375165623"><a name="p1383947375165623"></a><a name="p1383947375165623"></a>Obtains a <strong id="b2073313254165623"><a name="b2073313254165623"></a><a name="b2073313254165623"></a>SBuf</strong> instance of the default capacity (256 bytes). </p>
</td>
</tr>
<tr id="row723845892165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1515363234165623"><a name="p1515363234165623"></a><a name="p1515363234165623"></a><a href="Core.md#gabcc9a442a3b2615828d60a1d4664b4a9">HdfSBufBind</a> (uintptr_t base, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1745885548165623"><a name="p1745885548165623"></a><a name="p1745885548165623"></a>struct <a href="HdfSBuf.md">HdfSBuf</a> * </p>
<p id="p808458678165623"><a name="p808458678165623"></a><a name="p808458678165623"></a>Creates a <strong id="b1402068381165623"><a name="b1402068381165623"></a><a name="b1402068381165623"></a>SBuf</strong> instance with the specified data and size. The pointer to the data stored in the <strong id="b1430824456165623"><a name="b1430824456165623"></a><a name="b1430824456165623"></a>SBuf</strong> is released by the caller, and the written data size should not exceed the specified value of <strong id="b1382966861165623"><a name="b1382966861165623"></a><a name="b1382966861165623"></a>size</strong>. </p>
</td>
</tr>
<tr id="row70698002165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1353646354165623"><a name="p1353646354165623"></a><a name="p1353646354165623"></a><a href="Core.md#gaa0041d238cfc7cf00779191aa58e7ee0">HdfSBufRecycle</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2012427475165623"><a name="p2012427475165623"></a><a name="p2012427475165623"></a>void </p>
<p id="p1603330170165623"><a name="p1603330170165623"></a><a name="p1603330170165623"></a>Releases a <strong id="b1121018723165623"><a name="b1121018723165623"></a><a name="b1121018723165623"></a>SBuf </strong>. </p>
</td>
</tr>
<tr id="row1453097135165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p550675220165623"><a name="p550675220165623"></a><a name="p550675220165623"></a><a href="Core.md#ga22d4a953c89a941337e593647ebe2f5b">HdfSBufMove</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1496014248165623"><a name="p1496014248165623"></a><a name="p1496014248165623"></a>struct <a href="HdfSBuf.md">HdfSBuf</a> * </p>
<p id="p117995503165623"><a name="p117995503165623"></a><a name="p117995503165623"></a>Creates a <strong id="b1712865445165623"><a name="b1712865445165623"></a><a name="b1712865445165623"></a>SBuf</strong> instance with an original <strong id="b668276828165623"><a name="b668276828165623"></a><a name="b668276828165623"></a>SBuf</strong>. This function moves the data stored in the original <strong id="b1523334779165623"><a name="b1523334779165623"></a><a name="b1523334779165623"></a>SBuf</strong> to the new one without memory copy. </p>
</td>
</tr>
<tr id="row1211764804165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p13444309165623"><a name="p13444309165623"></a><a name="p13444309165623"></a><a href="Core.md#ga406275df686ff556fd5bdb20349e4972">HdfSBufCopy</a> (const struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1031652460165623"><a name="p1031652460165623"></a><a name="p1031652460165623"></a>struct <a href="HdfSBuf.md">HdfSBuf</a> * </p>
<p id="p767264737165623"><a name="p767264737165623"></a><a name="p767264737165623"></a>Creates a <strong id="b736601505165623"><a name="b736601505165623"></a><a name="b736601505165623"></a>SBuf</strong> instance with an original <strong id="b564853626165623"><a name="b564853626165623"></a><a name="b564853626165623"></a>SBuf</strong>. This function copies the data stored in the original <strong id="b1848362346165623"><a name="b1848362346165623"></a><a name="b1848362346165623"></a>SBuf</strong> to the new one. </p>
</td>
</tr>
<tr id="row1143952253165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p148379928165623"><a name="p148379928165623"></a><a name="p148379928165623"></a><a href="Core.md#gaf391e9f47cc668daf3150c00f369bf1f">HdfSbufTransDataOwnership</a> (struct <a href="HdfSBuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1387087662165623"><a name="p1387087662165623"></a><a name="p1387087662165623"></a>void </p>
<p id="p1657196777165623"><a name="p1657196777165623"></a><a name="p1657196777165623"></a>Transfers the data ownership to a <strong id="b175595157165623"><a name="b175595157165623"></a><a name="b175595157165623"></a>SBuf</strong>. Once the <strong id="b1543177452165623"><a name="b1543177452165623"></a><a name="b1543177452165623"></a>SBuf</strong> is released, the bound data memory is also released. This function is used together with <a href="Core.md#gabcc9a442a3b2615828d60a1d4664b4a9">HdfSBufBind</a>. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section642258245165623"></a>

## **Macro Definition **<a name="section917737689165623"></a>

## HDF\_INIT<a name="ga99831072fdca13e3c423a14fa6a83c34"></a>

```
#define HDF_INIT( module)   HDF_DRIVER_INIT(module)
```

 **Description:**

Registers the driver with the HDF. 

For a driver developed based on the HDF,  [HDF\_INIT](Core.md#ga99831072fdca13e3c423a14fa6a83c34)  must be used to register an entry with the HDF, and the registered object must be of the  [HdfDriverEntry](HdfDriverEntry.md)  type.

**Parameters:**

<a name="table545627567165623"></a>
<table><thead align="left"><tr id="row2133276501165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p755342112165623"><a name="p755342112165623"></a><a name="p755342112165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1207628060165623"><a name="p1207628060165623"></a><a name="p1207628060165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1491420416165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">module</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the global variable of the <a href="HdfDriverEntry.md">HdfDriverEntry</a> type</td>
</tr>
</tbody>
</table>

## **Typedef **<a name="section1250679194165623"></a>

## OnEventReceived<a name="gae314b850ba4b0927007038cf8cc32580"></a>

```
typedef int(* OnEventReceived) (void *priv, uint32_t id, struct [HdfSBuf](HdfSBuf.md) *data)
```

 **Description:**

Called when a driver event occurs. 

You can implement this function and bind it to the custom  [HdfDevEventlistener](HdfDevEventlistener.md)  object. 

**Parameters:**

<a name="table2078803243165623"></a>
<table><thead align="left"><tr id="row1087764661165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1172286596165623"><a name="p1172286596165623"></a><a name="p1172286596165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p473573539165623"><a name="p473573539165623"></a><a name="p473573539165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row824809108165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">priv</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the private data bound to this listener. </td>
</tr>
<tr id="row1964501632165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">id</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the serial number of the driver event occurred. </td>
</tr>
<tr id="row855454238165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the content data of the driver event. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise.

## **Enumeration Type **<a name="section1155043563165623"></a>

## DevicePreload<a name="ga0f3d81b5ff5d3896f7d8cf15f76b451e"></a>

```
enum [DevicePreload](Core.md#ga0f3d81b5ff5d3896f7d8cf15f76b451e)
```

 **Description:**

Enumerates driver loading policies. 

If a driver developed based on the HDF needs to use the on-demand loading mechanism in the HDF, the  **PRELOAD**  field must be correctly set in the driver configuration information to control the driver loading mode.

<a name="table22245091165623"></a>
<table><thead align="left"><tr id="row971706780165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1384456259165623"><a name="p1384456259165623"></a><a name="p1384456259165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p702285468165623"><a name="p702285468165623"></a><a name="p702285468165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row126281340165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga0f3d81b5ff5d3896f7d8cf15f76b451ea0fd51c3697833ef66f7ff68adb96a04d"><a name="gga0f3d81b5ff5d3896f7d8cf15f76b451ea0fd51c3697833ef66f7ff68adb96a04d"></a><a name="gga0f3d81b5ff5d3896f7d8cf15f76b451ea0fd51c3697833ef66f7ff68adb96a04d"></a></strong>DEVICE_PRELOAD_ENABLE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p296072342165623"><a name="p296072342165623"></a><a name="p296072342165623"></a>The driver is loaded during system startup by default. </p>
 </td>
</tr>
<tr id="row649538170165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga0f3d81b5ff5d3896f7d8cf15f76b451ea2c36597f3f647a621ab56b666ed6cb3e"><a name="gga0f3d81b5ff5d3896f7d8cf15f76b451ea2c36597f3f647a621ab56b666ed6cb3e"></a><a name="gga0f3d81b5ff5d3896f7d8cf15f76b451ea2c36597f3f647a621ab56b666ed6cb3e"></a></strong>DEVICE_PRELOAD_DISABLE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p86826503165623"><a name="p86826503165623"></a><a name="p86826503165623"></a>The driver is not loaded during system startup by default. </p>
 </td>
</tr>
<tr id="row2051362971165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga0f3d81b5ff5d3896f7d8cf15f76b451ea679c4d6dabdd7795bdbfaee5cc26367e"><a name="gga0f3d81b5ff5d3896f7d8cf15f76b451ea679c4d6dabdd7795bdbfaee5cc26367e"></a><a name="gga0f3d81b5ff5d3896f7d8cf15f76b451ea679c4d6dabdd7795bdbfaee5cc26367e"></a></strong>DEVICE_PRELOAD_INVALID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1830556809165623"><a name="p1830556809165623"></a><a name="p1830556809165623"></a>The loading policy is incorrect. </p>
 </td>
</tr>
</tbody>
</table>

## ServicePolicy<a name="ga172844da8a6908bf7226eee703ad9f80"></a>

```
enum [ServicePolicy](Core.md#ga172844da8a6908bf7226eee703ad9f80)
```

 **Description:**

Enumerates policies for releasing driver services developed based on the HDF. 

If a driver is developed based on the HDF and uses the service management feature of the HDF, you need to configure the policy for releasing services to external systems.

<a name="table2052200708165623"></a>
<table><thead align="left"><tr id="row519277013165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2098745302165623"><a name="p2098745302165623"></a><a name="p2098745302165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1894950102165623"><a name="p1894950102165623"></a><a name="p1894950102165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row835306883165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga172844da8a6908bf7226eee703ad9f80aeed8de39f7a8c5a5be1f7b8beb7221e1"><a name="gga172844da8a6908bf7226eee703ad9f80aeed8de39f7a8c5a5be1f7b8beb7221e1"></a><a name="gga172844da8a6908bf7226eee703ad9f80aeed8de39f7a8c5a5be1f7b8beb7221e1"></a></strong>SERVICE_POLICY_NONE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1998682072165623"><a name="p1998682072165623"></a><a name="p1998682072165623"></a>The driver does not provide services externally. </p>
 </td>
</tr>
<tr id="row1261614285165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga172844da8a6908bf7226eee703ad9f80a5ec1b4a05e5ba37c9bf58f039fe2c245"><a name="gga172844da8a6908bf7226eee703ad9f80a5ec1b4a05e5ba37c9bf58f039fe2c245"></a><a name="gga172844da8a6908bf7226eee703ad9f80a5ec1b4a05e5ba37c9bf58f039fe2c245"></a></strong>SERVICE_POLICY_PUBLIC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p50884645165623"><a name="p50884645165623"></a><a name="p50884645165623"></a>The driver provides services for kernel-level applications. </p>
 </td>
</tr>
<tr id="row1605550271165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga172844da8a6908bf7226eee703ad9f80a9a398765ae7bad9ce86e12a91683334c"><a name="gga172844da8a6908bf7226eee703ad9f80a9a398765ae7bad9ce86e12a91683334c"></a><a name="gga172844da8a6908bf7226eee703ad9f80a9a398765ae7bad9ce86e12a91683334c"></a></strong>SERVICE_POLICY_CAPACITY </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p515335508165623"><a name="p515335508165623"></a><a name="p515335508165623"></a>The driver provides services for both kernel- and user-level applications. </p>
 </td>
</tr>
<tr id="row326930160165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga172844da8a6908bf7226eee703ad9f80ac2fe21ccc86fbb38747c733716a6b2e0"><a name="gga172844da8a6908bf7226eee703ad9f80ac2fe21ccc86fbb38747c733716a6b2e0"></a><a name="gga172844da8a6908bf7226eee703ad9f80ac2fe21ccc86fbb38747c733716a6b2e0"></a></strong>SERVICE_POLICY_FRIENDLY </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p544984748165623"><a name="p544984748165623"></a><a name="p544984748165623"></a>Driver services are not released externally but can be subscribed to. </p>
 </td>
</tr>
<tr id="row2042117314165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga172844da8a6908bf7226eee703ad9f80ac7918e4a8fa4a2c29ccc8bf97537b61c"><a name="gga172844da8a6908bf7226eee703ad9f80ac7918e4a8fa4a2c29ccc8bf97537b61c"></a><a name="gga172844da8a6908bf7226eee703ad9f80ac7918e4a8fa4a2c29ccc8bf97537b61c"></a></strong>SERVICE_POLICY_PRIVATE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p549278792165623"><a name="p549278792165623"></a><a name="p549278792165623"></a>Driver services are only internally available. They are not released externally and cannot be subscribed to by external users. </p>
 </td>
</tr>
<tr id="row332293741165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga172844da8a6908bf7226eee703ad9f80a423a5d22d00f6a45f0281dd287fc3b4d"><a name="gga172844da8a6908bf7226eee703ad9f80a423a5d22d00f6a45f0281dd287fc3b4d"></a><a name="gga172844da8a6908bf7226eee703ad9f80a423a5d22d00f6a45f0281dd287fc3b4d"></a></strong>SERVICE_POLICY_INVALID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p809233835165623"><a name="p809233835165623"></a><a name="p809233835165623"></a>The service policy is incorrect. </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section692951378165623"></a>

## DevSvcManagerClntGetService\(\)<a name="gab28c6481fc79bd055e2551abebb841bf"></a>

```
const struct [HdfObject](HdfObject.md)* DevSvcManagerClntGetService (const char * svcName)
```

 **Description:**

Obtains the driver service object based on a driver service name. 

**Parameters:**

<a name="table1787631851165623"></a>
<table><thead align="left"><tr id="row1166183854165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1199676069165623"><a name="p1199676069165623"></a><a name="p1199676069165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1388990956165623"><a name="p1388990956165623"></a><a name="p1388990956165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row945182254165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">serviceName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the released driver service name.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the driver service object if the operation is successful; returns  **NULL**  otherwise. 

## HdfDeviceGetServiceName\(\)<a name="gac899589dfa47b45f43b8dd027b65b5d9"></a>

```
const char* HdfDeviceGetServiceName (const struct [HdfDeviceObject](HdfDeviceObject.md) * deviceObject)
```

 **Description:**

Obtains the service name of a driver. 

If a driver does not save its service name, it can use this function to obtain the service name. 

**Parameters:**

<a name="table1916635492165623"></a>
<table><thead align="left"><tr id="row1099737675165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1156846481165623"><a name="p1156846481165623"></a><a name="p1156846481165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p778194534165623"><a name="p778194534165623"></a><a name="p778194534165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1061751160165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">deviceObject</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the driver device object.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the service name if the operation is successful; returns  **NULL**  otherwise. 

## HdfDeviceRegisterEventListener\(\)<a name="gaa7855b3930b5378954927548e5623663"></a>

```
int HdfDeviceRegisterEventListener (struct [HdfIoService](HdfIoService.md) * target, struct [HdfDevEventlistener](HdfDevEventlistener.md) * listener )
```

 **Description:**

Registers a custom  [HdfDevEventlistener](HdfDevEventlistener.md)  for listening for events reported by a specified driver service object. 

**Parameters:**

<a name="table1510029408165623"></a>
<table><thead align="left"><tr id="row335029131165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1872502705165623"><a name="p1872502705165623"></a><a name="p1872502705165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p83221864165623"><a name="p83221864165623"></a><a name="p83221864165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1830108303165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">target</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the driver service object to listen, which is obtained through the <a href="Core.md#ga31198b68423805193274d3973c178ab5">HdfIoServiceBind</a> function. </td>
</tr>
<tr id="row291069850165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">listener</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the listener to register. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise.

## HdfDeviceSendEvent\(\)<a name="gac9670df1316b5ddd651a50ebee0b6557"></a>

```
int32_t HdfDeviceSendEvent (const struct [HdfDeviceObject](HdfDeviceObject.md) * deviceObject, uint32_t id, const struct [HdfSBuf](HdfSBuf.md) * data )
```

 **Description:**

Sends event messages. 

When the driver service invokes this function to send a message, all user-level applications that have registered listeners through  [HdfDeviceRegisterEventListener](Core.md#gaa7855b3930b5378954927548e5623663)  will receive the message.

**Parameters:**

<a name="table663292865165623"></a>
<table><thead align="left"><tr id="row1928229398165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1667220546165623"><a name="p1667220546165623"></a><a name="p1667220546165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p674642861165623"><a name="p674642861165623"></a><a name="p674642861165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1229330035165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">deviceObject</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the driver device object. </td>
</tr>
<tr id="row722626296165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">id</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of the message sending event. </td>
</tr>
<tr id="row962153558165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the message content sent by the driver.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## HdfDeviceSendEventToClient\(\)<a name="ga9c47da8d82820bce2d32051324480f45"></a>

```
int32_t HdfDeviceSendEventToClient (const struct [HdfDeviceIoClient](HdfDeviceIoClient.md) * client, uint32_t id, const struct [HdfSBuf](HdfSBuf.md) * data )
```

 **Description:**

Sends an event message to a specified client object. 

When the driver service invokes this function to send a message, the user-level applications that have registered listeners through  [HdfDeviceRegisterEventListener](Core.md#gaa7855b3930b5378954927548e5623663)  and correspond to this client object will receive the message.

**Parameters:**

<a name="table201912294165623"></a>
<table><thead align="left"><tr id="row943019840165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2035037933165623"><a name="p2035037933165623"></a><a name="p2035037933165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1920387674165623"><a name="p1920387674165623"></a><a name="p1920387674165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row371297718165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">client</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the client object of the driver service. </td>
</tr>
<tr id="row611894927165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">id</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of the message sending event. </td>
</tr>
<tr id="row1833728910165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the message content sent by the driver.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## HdfDeviceSubscribeService\(\)<a name="ga224908f55daa1b9553841735e5f1f65c"></a>

```
int32_t HdfDeviceSubscribeService (struct [HdfDeviceObject](HdfDeviceObject.md) * deviceObject, const char * serviceName, struct [SubscriberCallback](SubscriberCallback.md) callback )
```

 **Description:**

Subscribes to a driver service. 

If the driver loading time is not perceived, this function can be used to subscribe to the driver service. \(The driver service and the subscriber must be on the same host.\) After the subscribed-to driver service is loaded by the HDF, the framework proactively releases the service interface to the subscriber. 

**Parameters:**

<a name="table376433271165623"></a>
<table><thead align="left"><tr id="row1078566797165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1359158796165623"><a name="p1359158796165623"></a><a name="p1359158796165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p536402363165623"><a name="p536402363165623"></a><a name="p536402363165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row277923660165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">deviceObject</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the driver device object of the subscriber. </td>
</tr>
<tr id="row877156698165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">serviceName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the driver service name. </td>
</tr>
<tr id="row1290844166165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">callback</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the callback invoked by the HDF after the subscribed-to driver service is loaded.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## HdfDeviceUnregisterEventListener\(\)<a name="gab95668359f0b6a47f48c47541caed7fd"></a>

```
int HdfDeviceUnregisterEventListener (struct [HdfIoService](HdfIoService.md) * target, struct [HdfDevEventlistener](HdfDevEventlistener.md) * listener )
```

 **Description:**

Unregisters a previously registered  [HdfDevEventlistener](HdfDevEventlistener.md)  to release resources if it is no longer required. 

**Parameters:**

<a name="table630723906165623"></a>
<table><thead align="left"><tr id="row1063742022165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1193250675165623"><a name="p1193250675165623"></a><a name="p1193250675165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1140080378165623"><a name="p1140080378165623"></a><a name="p1140080378165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1999590318165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">target</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the driver service object that has been listened. </td>
</tr>
<tr id="row1604583514165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">listener</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the listener object registered by <a href="Core.md#gaa7855b3930b5378954927548e5623663">HdfDeviceRegisterEventListener</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise.

## HdfIoServiceBind\(\)<a name="ga31198b68423805193274d3973c178ab5"></a>

```
struct [HdfIoService](HdfIoService.md)* HdfIoServiceBind (const char * serviceName)
```

 **Description:**

Obtains a driver service object. 

**Parameters:**

<a name="table933124961165623"></a>
<table><thead align="left"><tr id="row1997006733165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2107664932165623"><a name="p2107664932165623"></a><a name="p2107664932165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p88525673165623"><a name="p88525673165623"></a><a name="p88525673165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row788390805165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">serviceName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the service to obtain. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the driver service object if the operation is successful; returns  **NULL**  otherwise.

## HdfIoServiceRecycle\(\)<a name="gada2867af690aac9e6c3b2c8812b3037c"></a>

```
void HdfIoServiceRecycle (struct [HdfIoService](HdfIoService.md) * service)
```

 **Description:**

Destroys a specified driver service object to release resources if it is no longer required. 

**Parameters:**

<a name="table550509660165623"></a>
<table><thead align="left"><tr id="row552933556165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1555078624165623"><a name="p1555078624165623"></a><a name="p1555078624165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1508539236165623"><a name="p1508539236165623"></a><a name="p1508539236165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1293245675165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the driver service object to destroy.</td>
</tr>
</tbody>
</table>

## HdfSBufBind\(\)<a name="gabcc9a442a3b2615828d60a1d4664b4a9"></a>

```
struct [HdfSBuf](HdfSBuf.md)* HdfSBufBind (uintptr_t base, size_t size )
```

 **Description:**

Creates a  **SBuf**  instance with the specified data and size. The pointer to the data stored in the  **SBuf**  is released by the caller, and the written data size should not exceed the specified value of  **size**. 

**Parameters:**

<a name="table385176058165623"></a>
<table><thead align="left"><tr id="row1790618351165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p678085701165623"><a name="p678085701165623"></a><a name="p678085701165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1990595206165623"><a name="p1990595206165623"></a><a name="p1990595206165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row641958816165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">base</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the base of the data to use. </td>
</tr>
<tr id="row352573359165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the data to use. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the  **SBuf**  instance.

## HdfSBufCopy\(\)<a name="ga406275df686ff556fd5bdb20349e4972"></a>

```
struct [HdfSBuf](HdfSBuf.md)* HdfSBufCopy (const struct [HdfSBuf](HdfSBuf.md) * sbuf)
```

 **Description:**

Creates a  **SBuf**  instance with an original  **SBuf**. This function copies the data stored in the original  **SBuf**  to the new one. 

**Parameters:**

<a name="table1579902623165623"></a>
<table><thead align="left"><tr id="row385959643165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1261995158165623"><a name="p1261995158165623"></a><a name="p1261995158165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p88286324165623"><a name="p88286324165623"></a><a name="p88286324165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1120162126165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the original <strong id="b1313180931165623"><a name="b1313180931165623"></a><a name="b1313180931165623"></a>SBuf</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the new  **SBuf**  instance.

## HdfSbufFlush\(\)<a name="ga2b7a5750bf42151edd7bd686fb11a39d"></a>

```
void HdfSbufFlush (struct [HdfSBuf](HdfSBuf.md) * sbuf)
```

 **Description:**

Clears the data stored in a  **SBuf**. 

**Parameters:**

<a name="table1354781184165623"></a>
<table><thead align="left"><tr id="row1823188536165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1638682065165623"><a name="p1638682065165623"></a><a name="p1638682065165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1204599318165623"><a name="p1204599318165623"></a><a name="p1204599318165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row714851411165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b1569843455165623"><a name="b1569843455165623"></a><a name="b1569843455165623"></a>SBuf</strong>.</td>
</tr>
</tbody>
</table>

## HdfSbufGetCapacity\(\)<a name="ga74941de5883ae39cb6103591f67dbea0"></a>

```
size_t HdfSbufGetCapacity (const struct [HdfSBuf](HdfSBuf.md) * sbuf)
```

 **Description:**

Obtains the capacity of a  **SBuf**. 

**Parameters:**

<a name="table199711016165623"></a>
<table><thead align="left"><tr id="row1397547506165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1337099613165623"><a name="p1337099613165623"></a><a name="p1337099613165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p410450834165623"><a name="p410450834165623"></a><a name="p410450834165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1324645750165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b1172068876165623"><a name="b1172068876165623"></a><a name="b1172068876165623"></a>SBuf</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the  **SBuf**  capacity. 

## HdfSbufGetData\(\)<a name="ga3f4f5fdb03f64c23f318ecf7c602ac59"></a>

```
uint8_t* HdfSbufGetData (const struct [HdfSBuf](HdfSBuf.md) * sbuf)
```

 **Description:**

Obtains the pointer to the data stored in a**SBuf**. 

**Parameters:**

<a name="table385941989165623"></a>
<table><thead align="left"><tr id="row396392418165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1222964443165623"><a name="p1222964443165623"></a><a name="p1222964443165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2090760349165623"><a name="p2090760349165623"></a><a name="p2090760349165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1551024273165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b1937883490165623"><a name="b1937883490165623"></a><a name="b1937883490165623"></a>SBuf</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the data stored in the target  **SBuf**.

## HdfSbufGetDataSize\(\)<a name="gaf983c174acfb5b1f8f9dc5b6c2f52e0d"></a>

```
size_t HdfSbufGetDataSize (const struct [HdfSBuf](HdfSBuf.md) * sbuf)
```

 **Description:**

Obtains the size of the data stored in a  **SBuf**. 

**Parameters:**

<a name="table1754541374165623"></a>
<table><thead align="left"><tr id="row1483722407165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1803275785165623"><a name="p1803275785165623"></a><a name="p1803275785165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1539194298165623"><a name="p1539194298165623"></a><a name="p1539194298165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row795833433165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b773390164165623"><a name="b773390164165623"></a><a name="b773390164165623"></a>SBuf</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the data size.

## HdfSBufMove\(\)<a name="ga22d4a953c89a941337e593647ebe2f5b"></a>

```
struct [HdfSBuf](HdfSBuf.md)* HdfSBufMove (struct [HdfSBuf](HdfSBuf.md) * sbuf)
```

 **Description:**

Creates a  **SBuf**  instance with an original  **SBuf**. This function moves the data stored in the original  **SBuf**  to the new one without memory copy. 

**Parameters:**

<a name="table2011217414165623"></a>
<table><thead align="left"><tr id="row517034492165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p792042679165623"><a name="p792042679165623"></a><a name="p792042679165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p340565355165623"><a name="p340565355165623"></a><a name="p340565355165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1425322568165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the original <strong id="b1495367418165623"><a name="b1495367418165623"></a><a name="b1495367418165623"></a>SBuf</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the new  **SBuf**  instance.

## HdfSBufObtain\(\)<a name="ga5e3dee8b1a2128da70cc5718b631c8ba"></a>

```
struct [HdfSBuf](HdfSBuf.md)* HdfSBufObtain (size_t capacity)
```

 **Description:**

Obtains a  **SBuf**  instance. 

**Parameters:**

<a name="table529520884165623"></a>
<table><thead align="left"><tr id="row1008947223165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p133689264165623"><a name="p133689264165623"></a><a name="p133689264165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1604697146165623"><a name="p1604697146165623"></a><a name="p1604697146165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1804088625165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">capacity</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the initial capacity of the<strong id="b2087112480165623"><a name="b2087112480165623"></a><a name="b2087112480165623"></a>SBuf</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the  **SBuf**  instance.

## HdfSBufObtainDefaultSize\(\)<a name="ga479315c09d0d927aa211de829388122d"></a>

```
struct [HdfSBuf](HdfSBuf.md)* HdfSBufObtainDefaultSize (void )
```

 **Description:**

Obtains a  **SBuf**  instance of the default capacity \(256 bytes\). 

**Returns:**

Returns the  **SBuf**  instance.

## HdfSbufReadBuffer\(\)<a name="ga345e8524a6cea44a0424e23b8f659792"></a>

```
bool HdfSbufReadBuffer (struct [HdfSBuf](HdfSBuf.md) * sbuf, const void ** data, uint32_t * readSize )
```

 **Description:**

Reads a data segment from a  **SBuf**. 

**Parameters:**

<a name="table1448615313165623"></a>
<table><thead align="left"><tr id="row225931183165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1559541124165623"><a name="p1559541124165623"></a><a name="p1559541124165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1857404293165623"><a name="p1857404293165623"></a><a name="p1857404293165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1106596174165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b978684412165623"><a name="b978684412165623"></a><a name="b978684412165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row1843335299165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the data read. The data read is stored in <strong id="b2107477024165623"><a name="b2107477024165623"></a><a name="b2107477024165623"></a>*data</strong>, which is requested by the caller. The memory pointed to by <strong id="b868352780165623"><a name="b868352780165623"></a><a name="b868352780165623"></a>*data</strong> is managed by the <strong id="b1538345033165623"><a name="b1538345033165623"></a><a name="b1538345033165623"></a>SBuf</strong> and they share the same lifecycle. </td>
</tr>
<tr id="row56829498165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">readSize</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the size of the data read. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufReadInt16\(\)<a name="ga3fce62cbc34a70259d21399d5ff91b32"></a>

```
bool HdfSbufReadInt16 (struct [HdfSBuf](HdfSBuf.md) * sbuf, int16_t * value )
```

 **Description:**

Reads a 16-bit signed integer from a  **SBuf**. 

**Parameters:**

<a name="table1511610850165623"></a>
<table><thead align="left"><tr id="row885692640165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p961968253165623"><a name="p961968253165623"></a><a name="p961968253165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p692294492165623"><a name="p692294492165623"></a><a name="p692294492165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row800220446165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b2056449356165623"><a name="b2056449356165623"></a><a name="b2056449356165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row1698065505165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the 16-bit signed integer read, which is requested by the caller. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufReadInt32\(\)<a name="ga22e7b97735f54e57c0d3bed2fa3a47c4"></a>

```
bool HdfSbufReadInt32 (struct [HdfSBuf](HdfSBuf.md) * sbuf, int32_t * value )
```

 **Description:**

Reads a 32-bit signed integer from a  **SBuf**. 

**Parameters:**

<a name="table1919212481165623"></a>
<table><thead align="left"><tr id="row1147598180165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p330938915165623"><a name="p330938915165623"></a><a name="p330938915165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p971524139165623"><a name="p971524139165623"></a><a name="p971524139165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1684657344165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b2126973951165623"><a name="b2126973951165623"></a><a name="b2126973951165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row629281508165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the 32-bit signed integer read, which is requested by the caller. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufReadInt64\(\)<a name="ga7fb121b4351f85e1735c6e63a5c951cc"></a>

```
bool HdfSbufReadInt64 (struct [HdfSBuf](HdfSBuf.md) * sbuf, int64_t * value )
```

 **Description:**

Reads a 64-bit signed integer from a  **SBuf**. 

**Parameters:**

<a name="table694686264165623"></a>
<table><thead align="left"><tr id="row421572074165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1743398053165623"><a name="p1743398053165623"></a><a name="p1743398053165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p143931571165623"><a name="p143931571165623"></a><a name="p143931571165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1064854630165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b1108820834165623"><a name="b1108820834165623"></a><a name="b1108820834165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row559256721165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the 64-bit signed integer read, which is requested by the caller. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufReadInt8\(\)<a name="gafff778f76f9142602ef25e8afff47c83"></a>

```
bool HdfSbufReadInt8 (struct [HdfSBuf](HdfSBuf.md) * sbuf, int8_t * value )
```

 **Description:**

Reads an 8-bit signed integer from a  **SBuf**. 

**Parameters:**

<a name="table365108724165623"></a>
<table><thead align="left"><tr id="row1028190087165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p76289939165623"><a name="p76289939165623"></a><a name="p76289939165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p643857199165623"><a name="p643857199165623"></a><a name="p643857199165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1338366508165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b1610428284165623"><a name="b1610428284165623"></a><a name="b1610428284165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row1789081893165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the 8-bit signed integer read, which is requested by the caller. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufReadString\(\)<a name="gab03aa25c90fda50138496b0f874a664e"></a>

```
const char* HdfSbufReadString (struct [HdfSBuf](HdfSBuf.md) * sbuf)
```

 **Description:**

Reads a string from a  **SBuf**. 

**Parameters:**

<a name="table245162910165623"></a>
<table><thead align="left"><tr id="row1177566622165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1304141852165623"><a name="p1304141852165623"></a><a name="p1304141852165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2026948895165623"><a name="p2026948895165623"></a><a name="p2026948895165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1997762807165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b291060900165623"><a name="b291060900165623"></a><a name="b291060900165623"></a>SBuf</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the string read if the operation is successful; returns  **NULL**  otherwise. The memory pointed to by this pointer is managed by the  **SBuf**  and they share the same lifecycle.

## HdfSbufReadUint16\(\)<a name="gabc151ad38bdecd5589623a6298c31930"></a>

```
bool HdfSbufReadUint16 (struct [HdfSBuf](HdfSBuf.md) * sbuf, uint16_t * value )
```

 **Description:**

Reads a 16-bit unsigned integer from a  **SBuf**. 

**Parameters:**

<a name="table276108276165623"></a>
<table><thead align="left"><tr id="row375136483165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2010471592165623"><a name="p2010471592165623"></a><a name="p2010471592165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p962620668165623"><a name="p962620668165623"></a><a name="p962620668165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1879224558165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b1916616133165623"><a name="b1916616133165623"></a><a name="b1916616133165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row1847937593165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the 16-bit unsigned integer read, which is requested by the caller. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufReadUint32\(\)<a name="gac953788575b0c22947f18fa9f19a5bf5"></a>

```
bool HdfSbufReadUint32 (struct [HdfSBuf](HdfSBuf.md) * sbuf, uint32_t * value )
```

 **Description:**

Reads a 32-bit unsigned integer from a  **SBuf**. 

**Parameters:**

<a name="table1688562204165623"></a>
<table><thead align="left"><tr id="row2142271038165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1367993804165623"><a name="p1367993804165623"></a><a name="p1367993804165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1962110987165623"><a name="p1962110987165623"></a><a name="p1962110987165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2051736448165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b1469591783165623"><a name="b1469591783165623"></a><a name="b1469591783165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row2123541019165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the 32-bit unsigned integer read, which is requested by the caller. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufReadUint64\(\)<a name="gabb10a71c031d3633c5745ba6fd62b0a4"></a>

```
bool HdfSbufReadUint64 (struct [HdfSBuf](HdfSBuf.md) * sbuf, uint64_t * value )
```

 **Description:**

Reads a 64-bit unsigned integer from a  **SBuf**. 

**Parameters:**

<a name="table261742498165623"></a>
<table><thead align="left"><tr id="row281972383165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p626555764165623"><a name="p626555764165623"></a><a name="p626555764165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1924537594165623"><a name="p1924537594165623"></a><a name="p1924537594165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row106452194165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b170479906165623"><a name="b170479906165623"></a><a name="b170479906165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row1832682214165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the 64-bit unsigned integer read, which is requested by the caller. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufReadUint8\(\)<a name="ga07d93e6bcd8a6a8646067783d6f46e74"></a>

```
bool HdfSbufReadUint8 (struct [HdfSBuf](HdfSBuf.md) * sbuf, uint8_t * value )
```

 **Description:**

Reads an 8-bit unsigned integer from a  **SBuf**. 

**Parameters:**

<a name="table1092815931165623"></a>
<table><thead align="left"><tr id="row1271567575165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1729587443165623"><a name="p1729587443165623"></a><a name="p1729587443165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1066827164165623"><a name="p1066827164165623"></a><a name="p1066827164165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1711468248165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b1446889029165623"><a name="b1446889029165623"></a><a name="b1446889029165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row366319744165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the 8-bit unsigned integer read, which is requested by the caller. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSBufRecycle\(\)<a name="gaa0041d238cfc7cf00779191aa58e7ee0"></a>

```
void HdfSBufRecycle (struct [HdfSBuf](HdfSBuf.md) * sbuf)
```

 **Description:**

Releases a  **SBuf **. 

**Parameters:**

<a name="table1090915810165623"></a>
<table><thead align="left"><tr id="row995094312165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p251572146165623"><a name="p251572146165623"></a><a name="p251572146165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1766075024165623"><a name="p1766075024165623"></a><a name="p1766075024165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1122738003165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b1619827794165623"><a name="b1619827794165623"></a><a name="b1619827794165623"></a>SBuf</strong> to release.</td>
</tr>
</tbody>
</table>

## HdfSbufTransDataOwnership\(\)<a name="gaf391e9f47cc668daf3150c00f369bf1f"></a>

```
void HdfSbufTransDataOwnership (struct [HdfSBuf](HdfSBuf.md) * sbuf)
```

 **Description:**

Transfers the data ownership to a  **SBuf**. Once the  **SBuf**  is released, the bound data memory is also released. This function is used together with  [HdfSBufBind](Core.md#gabcc9a442a3b2615828d60a1d4664b4a9). 

**Parameters:**

<a name="table1734639043165623"></a>
<table><thead align="left"><tr id="row1380121398165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1519973104165623"><a name="p1519973104165623"></a><a name="p1519973104165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1683051116165623"><a name="p1683051116165623"></a><a name="p1683051116165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1255929287165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b2067020129165623"><a name="b2067020129165623"></a><a name="b2067020129165623"></a>SBuf</strong>.</td>
</tr>
</tbody>
</table>

## HdfSbufWriteBuffer\(\)<a name="ga567eb533aa53051d0beec43f08e72dd8"></a>

```
bool HdfSbufWriteBuffer (struct [HdfSBuf](HdfSBuf.md) * sbuf, const void * data, uint32_t writeSize )
```

 **Description:**

Writes a data segment to a  **SBuf**. 

**Parameters:**

<a name="table678367099165623"></a>
<table><thead align="left"><tr id="row1517321006165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1999283845165623"><a name="p1999283845165623"></a><a name="p1999283845165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1178284944165623"><a name="p1178284944165623"></a><a name="p1178284944165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row941551900165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b6545925165623"><a name="b6545925165623"></a><a name="b6545925165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row1788058352165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data segment to write. </td>
</tr>
<tr id="row704060668165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">writeSize</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the data segment to write. The maximum value is 512 KB. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufWriteInt16\(\)<a name="gaaa278bf9aa182a4c65c390c6c9ff06d2"></a>

```
bool HdfSbufWriteInt16 (struct [HdfSBuf](HdfSBuf.md) * sbuf, int16_t value )
```

 **Description:**

Writes a 16-bit signed integer to a  **SBuf**. 

**Parameters:**

<a name="table1806888043165623"></a>
<table><thead align="left"><tr id="row1292818494165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1011367661165623"><a name="p1011367661165623"></a><a name="p1011367661165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p384513379165623"><a name="p384513379165623"></a><a name="p384513379165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2011294944165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b1082586240165623"><a name="b1082586240165623"></a><a name="b1082586240165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row1131471959165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the 16-bit signed integer to write. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufWriteInt32\(\)<a name="ga3913510d670da2f8ffa3103b5ff293f1"></a>

```
bool HdfSbufWriteInt32 (struct [HdfSBuf](HdfSBuf.md) * sbuf, int32_t value )
```

 **Description:**

Writes a 32-bit signed integer to a  **SBuf**. 

**Parameters:**

<a name="table2120298338165623"></a>
<table><thead align="left"><tr id="row1984711856165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1942134366165623"><a name="p1942134366165623"></a><a name="p1942134366165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1088111632165623"><a name="p1088111632165623"></a><a name="p1088111632165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1555962232165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b1436167162165623"><a name="b1436167162165623"></a><a name="b1436167162165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row507396772165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the 32-bit signed integer to write. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufWriteInt64\(\)<a name="ga7c63eb006b19e2aac43c23318c4ebe3b"></a>

```
bool HdfSbufWriteInt64 (struct [HdfSBuf](HdfSBuf.md) * sbuf, int64_t value )
```

 **Description:**

Writes a 64-bit signed integer to a  **SBuf**. 

**Parameters:**

<a name="table776103901165623"></a>
<table><thead align="left"><tr id="row2119434631165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1641577695165623"><a name="p1641577695165623"></a><a name="p1641577695165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p600526513165623"><a name="p600526513165623"></a><a name="p600526513165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1826867901165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b1168525577165623"><a name="b1168525577165623"></a><a name="b1168525577165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row1946810767165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the 64-bit signed integer to write. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufWriteInt8\(\)<a name="gac514c3debd605043ad1bfa9c05a115a0"></a>

```
bool HdfSbufWriteInt8 (struct [HdfSBuf](HdfSBuf.md) * sbuf, int8_t value )
```

 **Description:**

Writes an 8-bit signed integer to a  **SBuf**. 

**Parameters:**

<a name="table1223542090165623"></a>
<table><thead align="left"><tr id="row74363061165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1746225992165623"><a name="p1746225992165623"></a><a name="p1746225992165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p963315937165623"><a name="p963315937165623"></a><a name="p963315937165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1572797735165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b409815913165623"><a name="b409815913165623"></a><a name="b409815913165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row755031079165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the 8-bit signed integer to write. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufWriteString\(\)<a name="gaf782f8a08dcd81f4038ab9d9bbc1cf9b"></a>

```
bool HdfSbufWriteString (struct [HdfSBuf](HdfSBuf.md) * sbuf, const char * value )
```

 **Description:**

Writes a string to a  **SBuf**. 

**Parameters:**

<a name="table1812209903165623"></a>
<table><thead align="left"><tr id="row225523451165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1399188548165623"><a name="p1399188548165623"></a><a name="p1399188548165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1341481600165623"><a name="p1341481600165623"></a><a name="p1341481600165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row647076174165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b723660050165623"><a name="b723660050165623"></a><a name="b723660050165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row1426032923165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to write. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufWriteUint16\(\)<a name="ga31c9edfd9b20d6e44d34839efa0e08f7"></a>

```
bool HdfSbufWriteUint16 (struct [HdfSBuf](HdfSBuf.md) * sbuf, uint16_t value )
```

 **Description:**

Writes a 16-bit unsigned integer to a  **SBuf**. 

**Parameters:**

<a name="table1934207094165623"></a>
<table><thead align="left"><tr id="row1710271342165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1211157653165623"><a name="p1211157653165623"></a><a name="p1211157653165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p704602404165623"><a name="p704602404165623"></a><a name="p704602404165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1558158291165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b1448263181165623"><a name="b1448263181165623"></a><a name="b1448263181165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row519611098165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the 16-bit unsigned integer to write. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufWriteUint32\(\)<a name="ga23f2331cdfb0bf91a29f47f20ffd50df"></a>

```
bool HdfSbufWriteUint32 (struct [HdfSBuf](HdfSBuf.md) * sbuf, uint32_t value )
```

 **Description:**

Writes a 32-bit unsigned integer to a  **SBuf**. 

**Parameters:**

<a name="table24151142165623"></a>
<table><thead align="left"><tr id="row257089088165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1191576316165623"><a name="p1191576316165623"></a><a name="p1191576316165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1435951103165623"><a name="p1435951103165623"></a><a name="p1435951103165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1894359152165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b1765613704165623"><a name="b1765613704165623"></a><a name="b1765613704165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row1320482668165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the 32-bit unsigned integer to write. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufWriteUint64\(\)<a name="ga164de95ad00302b599290bdb476a032f"></a>

```
bool HdfSbufWriteUint64 (struct [HdfSBuf](HdfSBuf.md) * sbuf, uint64_t value )
```

 **Description:**

Writes a 64-bit unsigned integer to a  **SBuf**. 

**Parameters:**

<a name="table2069383485165623"></a>
<table><thead align="left"><tr id="row303603186165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p37269716165623"><a name="p37269716165623"></a><a name="p37269716165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p220889823165623"><a name="p220889823165623"></a><a name="p220889823165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row331749204165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b554086485165623"><a name="b554086485165623"></a><a name="b554086485165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row341985743165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the 64-bit unsigned integer to write. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

## HdfSbufWriteUint8\(\)<a name="gafb4fe74246f85a158c140bf4c4951256"></a>

```
bool HdfSbufWriteUint8 (struct [HdfSBuf](HdfSBuf.md) * sbuf, uint8_t value )
```

 **Description:**

Writes an 8-bit unsigned integer to a  **SBuf**. 

**Parameters:**

<a name="table430775951165623"></a>
<table><thead align="left"><tr id="row463284740165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1975333078165623"><a name="p1975333078165623"></a><a name="p1975333078165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2122718224165623"><a name="p2122718224165623"></a><a name="p2122718224165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1855789829165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sbuf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target <strong id="b544096225165623"><a name="b544096225165623"></a><a name="b544096225165623"></a>SBuf</strong>. </td>
</tr>
<tr id="row177096460165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the 8-bit unsigned integer to write. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise.

