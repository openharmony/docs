# InputController<a name="EN-US_TOPIC_0000001055518090"></a>

-   [Overview](#section38728142165631)
-   [Summary](#section1909951786165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1347173943165631)
-   [Field](#section1364095562165631)
-   [GetChipInfo](#aa02ce599f0383c88e6efc301e31901b8)
-   [GetChipName](#aaa131995539b4c0b783cdcbdd67b9687)
-   [GetDeviceType](#aec8d8a22b37f572a9df8ef7ce988a6d3)
-   [GetPowerStatus](#afd9ffc4a180609ad970df6fd79806372)
-   [GetVendorName](#ab011f8433b9c5aa8493320dac9c4a683)
-   [RunCapacitanceTest](#afc470fb6e33a07aaa179980a4ded39db)
-   [RunExtraCommand](#a19c15b3b535f63fbc4e17bbad24492c9)
-   [SetGestureMode](#a2a5b24dfc129b58ae4663ca44ab2ad91)
-   [SetPowerStatus](#a38da915fec2698dff480ed686503f692)

## **Overview**<a name="section38728142165631"></a>

**Related Modules:**

[Input](input.md)

**Description:**

Provides interfaces for controlling the business process of input devices. 

The interfaces can be called to control the power status, enable or disable a feature, get driver chip information, and control the production test. 

## **Summary**<a name="section1909951786165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1194806598165631"></a>
<table><thead align="left"><tr id="row1847208249165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p686522201165631"><a name="p686522201165631"></a><a name="p686522201165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p302660226165631"><a name="p302660226165631"></a><a name="p302660226165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row999332193165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1563527777165631"><a name="p1563527777165631"></a><a name="p1563527777165631"></a><a href="inputcontroller.md#a38da915fec2698dff480ed686503f692">SetPowerStatus</a> )(uint32_t devIndex, uint32_t status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p311906685165631"><a name="p311906685165631"></a><a name="p311906685165631"></a>int32_t(* </p>
<p id="p1580338161165631"><a name="p1580338161165631"></a><a name="p1580338161165631"></a>Sets the power status. </p>
</td>
</tr>
<tr id="row1328101729165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p535342853165631"><a name="p535342853165631"></a><a name="p535342853165631"></a><a href="inputcontroller.md#afd9ffc4a180609ad970df6fd79806372">GetPowerStatus</a> )(uint32_t devIndex, uint32_t *status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p928571729165631"><a name="p928571729165631"></a><a name="p928571729165631"></a>int32_t(* </p>
<p id="p1834559604165631"><a name="p1834559604165631"></a><a name="p1834559604165631"></a>Gets the power status. </p>
</td>
</tr>
<tr id="row432369624165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1335281635165631"><a name="p1335281635165631"></a><a name="p1335281635165631"></a><a href="inputcontroller.md#aec8d8a22b37f572a9df8ef7ce988a6d3">GetDeviceType</a> )(uint32_t devIndex, uint32_t *deviceType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p9577388165631"><a name="p9577388165631"></a><a name="p9577388165631"></a>int32_t(* </p>
<p id="p979060353165631"><a name="p979060353165631"></a><a name="p979060353165631"></a>Gets the type of the input device based on the specified device index. </p>
</td>
</tr>
<tr id="row1874408208165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1449981330165631"><a name="p1449981330165631"></a><a name="p1449981330165631"></a><a href="inputcontroller.md#aa02ce599f0383c88e6efc301e31901b8">GetChipInfo</a> )(uint32_t devIndex, char *chipInfo, uint32_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1685055840165631"><a name="p1685055840165631"></a><a name="p1685055840165631"></a>int32_t(* </p>
<p id="p834279611165631"><a name="p834279611165631"></a><a name="p834279611165631"></a>Gets the chip information of the specified device. </p>
</td>
</tr>
<tr id="row368682448165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p687885077165631"><a name="p687885077165631"></a><a name="p687885077165631"></a><a href="inputcontroller.md#ab011f8433b9c5aa8493320dac9c4a683">GetVendorName</a> )(uint32_t devIndex, char *vendorName, uint32_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1966183049165631"><a name="p1966183049165631"></a><a name="p1966183049165631"></a>int32_t(* </p>
<p id="p492603188165631"><a name="p492603188165631"></a><a name="p492603188165631"></a>Gets the module vendor name of the specified device. </p>
</td>
</tr>
<tr id="row807381156165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1631984331165631"><a name="p1631984331165631"></a><a name="p1631984331165631"></a><a href="inputcontroller.md#aaa131995539b4c0b783cdcbdd67b9687">GetChipName</a> )(uint32_t devIndex, char *chipName, uint32_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1923254506165631"><a name="p1923254506165631"></a><a name="p1923254506165631"></a>int32_t(* </p>
<p id="p1242785247165631"><a name="p1242785247165631"></a><a name="p1242785247165631"></a>Gets the driver chip name of the specified device. </p>
</td>
</tr>
<tr id="row709346504165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p400575773165631"><a name="p400575773165631"></a><a name="p400575773165631"></a><a href="inputcontroller.md#a2a5b24dfc129b58ae4663ca44ab2ad91">SetGestureMode</a> )(uint32_t devIndex, uint32_t gestureMode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1135966754165631"><a name="p1135966754165631"></a><a name="p1135966754165631"></a>int32_t(* </p>
<p id="p1809643383165631"><a name="p1809643383165631"></a><a name="p1809643383165631"></a>Sets the gesture mode. </p>
</td>
</tr>
<tr id="row1936987432165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2001211302165631"><a name="p2001211302165631"></a><a name="p2001211302165631"></a><a href="inputcontroller.md#afc470fb6e33a07aaa179980a4ded39db">RunCapacitanceTest</a> )(uint32_t devIndex, uint32_t testType, char *result, uint32_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1555427518165631"><a name="p1555427518165631"></a><a name="p1555427518165631"></a>int32_t(* </p>
<p id="p175784017165631"><a name="p175784017165631"></a><a name="p175784017165631"></a>Conducts a capacitance self-test. </p>
</td>
</tr>
<tr id="row1506337588165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p870190403165631"><a name="p870190403165631"></a><a name="p870190403165631"></a><a href="inputcontroller.md#a19c15b3b535f63fbc4e17bbad24492c9">RunExtraCommand</a> )(uint32_t devIndex, <a href="inputextracmd.md">InputExtraCmd</a> *cmd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p418859781165631"><a name="p418859781165631"></a><a name="p418859781165631"></a>int32_t(* </p>
<p id="p431429605165631"><a name="p431429605165631"></a><a name="p431429605165631"></a>Executes the extra command. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1347173943165631"></a>

## **Field **<a name="section1364095562165631"></a>

## GetChipInfo<a name="aa02ce599f0383c88e6efc301e31901b8"></a>

```
int32_t(* InputController::GetChipInfo) (uint32_t devIndex, char *chipInfo, uint32_t length)
```

 **Description:**

Gets the chip information of the specified device. 

A product is usually equipped with modules and driver ICs provided by multiple vendors. An input service can call this function to get the specific information if needed.

**Parameters:**

<a name="table887577075165631"></a>
<table><thead align="left"><tr id="row1697114015165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1015883241165631"><a name="p1015883241165631"></a><a name="p1015883241165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2141396051165631"><a name="p2141396051165631"></a><a name="p2141396051165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2018703774165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b346189528165631"><a name="b346189528165631"></a><a name="b346189528165631"></a>0</strong> represents the first input device. </td>
</tr>
<tr id="row242687629165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">chipInfo</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the chip information. </td>
</tr>
<tr id="row1717354250165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">length</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the chip information. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

## GetChipName<a name="aaa131995539b4c0b783cdcbdd67b9687"></a>

```
int32_t(* InputController::GetChipName) (uint32_t devIndex, char *chipName, uint32_t length)
```

 **Description:**

Gets the driver chip name of the specified device. 

**Parameters:**

<a name="table1791801048165631"></a>
<table><thead align="left"><tr id="row629341621165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p94014639165631"><a name="p94014639165631"></a><a name="p94014639165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1838636957165631"><a name="p1838636957165631"></a><a name="p1838636957165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1742795618165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b1514838692165631"><a name="b1514838692165631"></a><a name="b1514838692165631"></a>0</strong> represents the first input device. </td>
</tr>
<tr id="row1634530157165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">chipName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the driver chip name. </td>
</tr>
<tr id="row710097384165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">length</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the driver chip name. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

## GetDeviceType<a name="aec8d8a22b37f572a9df8ef7ce988a6d3"></a>

```
int32_t(* InputController::GetDeviceType) (uint32_t devIndex, uint32_t *deviceType)
```

 **Description:**

Gets the type of the input device based on the specified device index. 

**Parameters:**

<a name="table1482664177165631"></a>
<table><thead align="left"><tr id="row1904450125165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p5811953165631"><a name="p5811953165631"></a><a name="p5811953165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p195979874165631"><a name="p195979874165631"></a><a name="p195979874165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1179540020165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b1276388771165631"><a name="b1276388771165631"></a><a name="b1276388771165631"></a>0</strong> represents the first input device. </td>
</tr>
<tr id="row1400268170165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">deviceType</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device type. For details, see <a href="input.md#gaa8225ba155dfa1ef2c4119c832bc4dd3">InputDevType</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

## GetPowerStatus<a name="afd9ffc4a180609ad970df6fd79806372"></a>

```
int32_t(* InputController::GetPowerStatus) (uint32_t devIndex, uint32_t *status)
```

 **Description:**

Gets the power status. 

The input service or the power management module can set the power status for the input device when the OS is in the Resume or Suspend status, so that the driver IC of the device can normally enter the specified status. You can call this function to obtain the power status.

**Parameters:**

<a name="table593829208165631"></a>
<table><thead align="left"><tr id="row1137612694165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1296918252165631"><a name="p1296918252165631"></a><a name="p1296918252165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1581244548165631"><a name="p1581244548165631"></a><a name="p1581244548165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1699531319165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b81702613165631"><a name="b81702613165631"></a><a name="b81702613165631"></a>0</strong> represents the first input device. </td>
</tr>
<tr id="row833663871165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">status</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the power status of the device. For details, see <a href="input.md#ga65e6bb4d942c22dba9975253b0a1d73f">PowerStatus</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

## GetVendorName<a name="ab011f8433b9c5aa8493320dac9c4a683"></a>

```
int32_t(* InputController::GetVendorName) (uint32_t devIndex, char *vendorName, uint32_t length)
```

 **Description:**

Gets the module vendor name of the specified device. 

**Parameters:**

<a name="table1366574635165631"></a>
<table><thead align="left"><tr id="row1856278085165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p228868602165631"><a name="p228868602165631"></a><a name="p228868602165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1344287734165631"><a name="p1344287734165631"></a><a name="p1344287734165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1450044187165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b2088131552165631"><a name="b2088131552165631"></a><a name="b2088131552165631"></a>0</strong> represents the first input device. </td>
</tr>
<tr id="row1554203859165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">vendorName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the module vendor name. </td>
</tr>
<tr id="row1087358545165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">length</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the vendor name. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

## RunCapacitanceTest<a name="afc470fb6e33a07aaa179980a4ded39db"></a>

```
int32_t(* InputController::RunCapacitanceTest) (uint32_t devIndex, uint32_t testType, char *result, uint32_t length)
```

 **Description:**

Conducts a capacitance self-test. 

The capacitance self-test items are defined by the component vendor, such as the tests on the raw data, short circuit, open circuit, interference, and row/column difference.

**Parameters:**

<a name="table1213313171165631"></a>
<table><thead align="left"><tr id="row550879977165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2035638673165631"><a name="p2035638673165631"></a><a name="p2035638673165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p632379103165631"><a name="p632379103165631"></a><a name="p632379103165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row462142346165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b943402545165631"><a name="b943402545165631"></a><a name="b943402545165631"></a>0</strong> represents the first input device. </td>
</tr>
<tr id="row765260204165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">testType</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the capacitance test type. For details, see <a href="input.md#gae96e484cfd64ea37b5b7782f57f38a21">CapacitanceTest</a>. </td>
</tr>
<tr id="row863950573165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">result</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the capacitance test result. The value is <strong id="b1611866253165631"><a name="b1611866253165631"></a><a name="b1611866253165631"></a>SUCC</strong> for a successful operation and is an error code for a failed operation. </td>
</tr>
<tr id="row1352045397165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">length</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the test result. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

## RunExtraCommand<a name="a19c15b3b535f63fbc4e17bbad24492c9"></a>

```
int32_t(* InputController::RunExtraCommand) (uint32_t devIndex, [InputExtraCmd](inputextracmd.md) *cmd)
```

 **Description:**

Executes the extra command. 

**Parameters:**

<a name="table1940113581165631"></a>
<table><thead align="left"><tr id="row2088581311165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p74502341165631"><a name="p74502341165631"></a><a name="p74502341165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p230896113165631"><a name="p230896113165631"></a><a name="p230896113165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1907215862165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b1024443217165631"><a name="b1024443217165631"></a><a name="b1024443217165631"></a>0</strong> represents the first input device. </td>
</tr>
<tr id="row593470156165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cmd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the extra command data packet, including the command codes and parameters. For details, see <a href="inputextracmd.md">InputExtraCmd</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

## SetGestureMode<a name="a2a5b24dfc129b58ae4663ca44ab2ad91"></a>

```
int32_t(* InputController::SetGestureMode) (uint32_t devIndex, uint32_t gestureMode)
```

 **Description:**

Sets the gesture mode. 

The input service can use this function to enable or disable the gesture mode by setting  **EnableBit**  of the gesture mode.

**Parameters:**

<a name="table2055573299165631"></a>
<table><thead align="left"><tr id="row864692000165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1492048312165631"><a name="p1492048312165631"></a><a name="p1492048312165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1698210876165631"><a name="p1698210876165631"></a><a name="p1698210876165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row632264915165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b2009888340165631"><a name="b2009888340165631"></a><a name="b2009888340165631"></a>0</strong> represents the first input device. </td>
</tr>
<tr id="row1649498022165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">gestureMode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the gesture mode to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

## SetPowerStatus<a name="a38da915fec2698dff480ed686503f692"></a>

```
int32_t(* InputController::SetPowerStatus) (uint32_t devIndex, uint32_t status)
```

 **Description:**

Sets the power status. 

This function is called only when the power status of the OS is changed. The input service or the power management module can call this function to set the power status for the input device when the OS is in the Resume or Suspend status, so that the driver integrated circuit \(IC\) of the device can normally enter the specified status. 

**Parameters:**

<a name="table1781849161165631"></a>
<table><thead align="left"><tr id="row445441046165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p395039696165631"><a name="p395039696165631"></a><a name="p395039696165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p120194064165631"><a name="p120194064165631"></a><a name="p120194064165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1015885983165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b2038157531165631"><a name="b2038157531165631"></a><a name="b2038157531165631"></a>0</strong> represents the first input device. </td>
</tr>
<tr id="row273950230165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">status</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the power status to set. The input service will notify the input device of entering the Resume or Suspend state specified by <a href="input.md#ga65e6bb4d942c22dba9975253b0a1d73f">PowerStatus</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

