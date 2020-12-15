# InputManager<a name="EN-US_TOPIC_0000001054799601"></a>

-   [Overview](#section1517000695165631)
-   [Summary](#section1422849149165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1439023108165631)
-   [Field](#section142390188165631)
-   [CloseInputDevice](#a41f3a8a5d8995c9a08bd90c1d367209d)
-   [GetInputDevice](#abf32ba302df150d952714776e1707bc5)
-   [GetInputDeviceList](#a74f11b9e24d19413f5eb9b35700be078)
-   [OpenInputDevice](#a9153e901b4811654d8dfc2e78aa29f07)

## **Overview**<a name="section1517000695165631"></a>

**Related Modules:**

[Input](input.md)

**Description:**

Provides interfaces for managing input devices. 

The interfaces can be used to perform basic operations on the input devices, such as opening and closing the device files and querying information about the input device. 

## **Summary**<a name="section1422849149165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table214761541165631"></a>
<table><thead align="left"><tr id="row1626022214165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p859013185165631"><a name="p859013185165631"></a><a name="p859013185165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p817772437165631"><a name="p817772437165631"></a><a name="p817772437165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1642383983165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p996081094165631"><a name="p996081094165631"></a><a name="p996081094165631"></a><a href="inputmanager.md#a9153e901b4811654d8dfc2e78aa29f07">OpenInputDevice</a> )(uint32_t devIndex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p266945387165631"><a name="p266945387165631"></a><a name="p266945387165631"></a>int32_t(* </p>
<p id="p716293002165631"><a name="p716293002165631"></a><a name="p716293002165631"></a>Opens a specified input device file. </p>
</td>
</tr>
<tr id="row394296720165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p431318370165631"><a name="p431318370165631"></a><a name="p431318370165631"></a><a href="inputmanager.md#a41f3a8a5d8995c9a08bd90c1d367209d">CloseInputDevice</a> )(uint32_t devIndex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p826061738165631"><a name="p826061738165631"></a><a name="p826061738165631"></a>int32_t(* </p>
<p id="p1159292376165631"><a name="p1159292376165631"></a><a name="p1159292376165631"></a>Closes a specified input device file. </p>
</td>
</tr>
<tr id="row1609880364165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1754696607165631"><a name="p1754696607165631"></a><a name="p1754696607165631"></a><a href="inputmanager.md#abf32ba302df150d952714776e1707bc5">GetInputDevice</a> )(uint32_t devIndex, <a href="deviceinfo.md">DeviceInfo</a> **devInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1650645130165631"><a name="p1650645130165631"></a><a name="p1650645130165631"></a>int32_t(* </p>
<p id="p1748479069165631"><a name="p1748479069165631"></a><a name="p1748479069165631"></a>Gets information about a specified input device. </p>
</td>
</tr>
<tr id="row1499675120165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p650374227165631"><a name="p650374227165631"></a><a name="p650374227165631"></a><a href="inputmanager.md#a74f11b9e24d19413f5eb9b35700be078">GetInputDeviceList</a> )(uint32_t *devNum, <a href="deviceinfo.md">DeviceInfo</a> **devList, uint32_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1233368212165631"><a name="p1233368212165631"></a><a name="p1233368212165631"></a>int32_t(* </p>
<p id="p1601347890165631"><a name="p1601347890165631"></a><a name="p1601347890165631"></a>Gets information about all input devices in the device list. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1439023108165631"></a>

## **Field **<a name="section142390188165631"></a>

## CloseInputDevice<a name="a41f3a8a5d8995c9a08bd90c1d367209d"></a>

```
int32_t(* InputManager::CloseInputDevice) (uint32_t devIndex)
```

 **Description:**

Closes a specified input device file. 

**Parameters:**

<a name="table450013883165631"></a>
<table><thead align="left"><tr id="row1513269223165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1606301074165631"><a name="p1606301074165631"></a><a name="p1606301074165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p158114511165631"><a name="p158114511165631"></a><a name="p158114511165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2085529401165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b1576089454165631"><a name="b1576089454165631"></a><a name="b1576089454165631"></a>0</strong> represents the first input device. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

## GetInputDevice<a name="abf32ba302df150d952714776e1707bc5"></a>

```
int32_t(* InputManager::GetInputDevice) (uint32_t devIndex, [DeviceInfo](deviceinfo.md) **devInfo)
```

 **Description:**

Gets information about a specified input device. 

**Parameters:**

<a name="table555787885165631"></a>
<table><thead align="left"><tr id="row1022990945165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p867627162165631"><a name="p867627162165631"></a><a name="p867627162165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1079065607165631"><a name="p1079065607165631"></a><a name="p1079065607165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1631778092165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b2137347081165631"><a name="b2137347081165631"></a><a name="b2137347081165631"></a>0</strong> represents the first input device. </td>
</tr>
<tr id="row455497556165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devInfo</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to information about the specified device. For details, see <a href="deviceinfo.md">DeviceInfo</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

## GetInputDeviceList<a name="a74f11b9e24d19413f5eb9b35700be078"></a>

```
int32_t(* InputManager::GetInputDeviceList) (uint32_t *devNum, [DeviceInfo](deviceinfo.md) **devList, uint32_t size)
```

 **Description:**

Gets information about all input devices in the device list. 

**Parameters:**

<a name="table1372346536165631"></a>
<table><thead align="left"><tr id="row2141631618165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2032329217165631"><a name="p2032329217165631"></a><a name="p2032329217165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p390983674165631"><a name="p390983674165631"></a><a name="p390983674165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1982086959165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devNum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the total number of input devices which have been registered. </td>
</tr>
<tr id="row938405318165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devList</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to information about all devices in the device list. For details, see <a href="deviceinfo.md">DeviceInfo</a>. </td>
</tr>
<tr id="row141550251165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of elements in the <strong id="b1333087694165631"><a name="b1333087694165631"></a><a name="b1333087694165631"></a>devList</strong> array. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

## OpenInputDevice<a name="a9153e901b4811654d8dfc2e78aa29f07"></a>

```
int32_t(* InputManager::OpenInputDevice) (uint32_t devIndex)
```

 **Description:**

Opens a specified input device file. 

**Parameters:**

<a name="table535230571165631"></a>
<table><thead align="left"><tr id="row2082251219165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p486497372165631"><a name="p486497372165631"></a><a name="p486497372165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p324580229165631"><a name="p324580229165631"></a><a name="p324580229165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row904944851165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b1556340919165631"><a name="b1556340919165631"></a><a name="b1556340919165631"></a>0</strong> represents the first input device. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

