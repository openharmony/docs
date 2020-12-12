# Input<a name="ZH-CN_TOPIC_0000001054879480"></a>

-   [Overview](#section1419845336165623)
-   [Summary](#section300915032165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section417783477165623)
-   [Enumeration Type](#section150212759165623)
-   [CapacitanceTest](#gae96e484cfd64ea37b5b7782f57f38a21)
-   [InputDevType](#gaa8225ba155dfa1ef2c4119c832bc4dd3)
-   [PowerStatus](#ga65e6bb4d942c22dba9975253b0a1d73f)
-   [RetStatus](#ga85d58a5185669daa4995e332b63eba7a)
-   [Function](#section882045796165623)
-   [GetInputInterface\(\)](#ga3ca3e6b9bb859ba407b00a2175309cd3)

## **Overview**<a name="section1419845336165623"></a>

**Description:**

Provides driver interfaces for the input service. 

These driver interfaces can be used to open and close input device files, get input events, query device information, register callback functions, and control the feature status.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section300915032165623"></a>

## Files<a name="files"></a>

<a name="table1531607533165623"></a>
<table><thead align="left"><tr id="row502643327165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1543749664165623"><a name="p1543749664165623"></a><a name="p1543749664165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p795625085165623"><a name="p795625085165623"></a><a name="p795625085165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1862003708165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p709342716165623"><a name="p709342716165623"></a><a name="p709342716165623"></a><a href="input_controller-h.md">input_controller.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1541117903165623"><a name="p1541117903165623"></a><a name="p1541117903165623"></a>Declares the driver interfaces for controlling the business process of input devices. </p>
</td>
</tr>
<tr id="row1195079904165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p755988395165623"><a name="p755988395165623"></a><a name="p755988395165623"></a><a href="input_manager-h.md">input_manager.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1708262564165623"><a name="p1708262564165623"></a><a name="p1708262564165623"></a>Declares the driver interfaces for managing input devices. </p>
</td>
</tr>
<tr id="row2112114227165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p254635683165623"><a name="p254635683165623"></a><a name="p254635683165623"></a><a href="input_reporter-h.md">input_reporter.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p888411922165623"><a name="p888411922165623"></a><a name="p888411922165623"></a>Declares the driver interfaces for reporting data of input devices. </p>
</td>
</tr>
<tr id="row967082088165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1018911832165623"><a name="p1018911832165623"></a><a name="p1018911832165623"></a><a href="input_type-h.md">input_type.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p840869644165623"><a name="p840869644165623"></a><a name="p840869644165623"></a>Declares types of input devices as well as the structure and enumeration types used by driver interfaces. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1454003029165623"></a>
<table><thead align="left"><tr id="row1871529872165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p187083580165623"><a name="p187083580165623"></a><a name="p187083580165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1956590113165623"><a name="p1956590113165623"></a><a name="p1956590113165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1827284456165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1540077734165623"><a name="p1540077734165623"></a><a name="p1540077734165623"></a><a href="InputController.md">InputController</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1620564257165623"><a name="p1620564257165623"></a><a name="p1620564257165623"></a>Provides interfaces for controlling the business process of input devices. </p>
</td>
</tr>
<tr id="row409066274165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1526494654165623"><a name="p1526494654165623"></a><a name="p1526494654165623"></a><a href="InputManager.md">InputManager</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p870426933165623"><a name="p870426933165623"></a><a name="p870426933165623"></a>Provides interfaces for managing input devices. </p>
</td>
</tr>
<tr id="row1456093764165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p704050206165623"><a name="p704050206165623"></a><a name="p704050206165623"></a><a href="IInputInterface.md">IInputInterface</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2125187248165623"><a name="p2125187248165623"></a><a name="p2125187248165623"></a>Defines interfaces for providing driver capabilities of input devices. </p>
</td>
</tr>
<tr id="row19636766165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1565522787165623"><a name="p1565522787165623"></a><a name="p1565522787165623"></a><a href="InputReporter.md">InputReporter</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p611613369165623"><a name="p611613369165623"></a><a name="p611613369165623"></a>Provides interfaces for reporting event data of input devices. </p>
</td>
</tr>
<tr id="row1133752667165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1376651491165623"><a name="p1376651491165623"></a><a name="p1376651491165623"></a><a href="InputExtraCmd.md">InputExtraCmd</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p33989793165623"><a name="p33989793165623"></a><a name="p33989793165623"></a>Defines the extra commands. </p>
</td>
</tr>
<tr id="row1733225535165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p531811345165623"><a name="p531811345165623"></a><a name="p531811345165623"></a><a href="InputEventData.md">InputEventData</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p784272245165623"><a name="p784272245165623"></a><a name="p784272245165623"></a>Describes the input event data. </p>
</td>
</tr>
<tr id="row1201497290165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p302411996165623"><a name="p302411996165623"></a><a name="p302411996165623"></a><a href="InputReportEventCb.md">InputReportEventCb</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p475019559165623"><a name="p475019559165623"></a><a name="p475019559165623"></a>Describes the input event callback registered by the input service. </p>
</td>
</tr>
<tr id="row207395142165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p627775029165623"><a name="p627775029165623"></a><a name="p627775029165623"></a><a href="DeviceInfo.md">DeviceInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p692644240165623"><a name="p692644240165623"></a><a name="p692644240165623"></a>Describes basic device information of the input device. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table713621467165623"></a>
<table><thead align="left"><tr id="row890289790165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p785119075165623"><a name="p785119075165623"></a><a name="p785119075165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1144903278165623"><a name="p1144903278165623"></a><a name="p1144903278165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row414596594165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1710382706165623"><a name="p1710382706165623"></a><a name="p1710382706165623"></a><a href="Input.md#ga85d58a5185669daa4995e332b63eba7a">RetStatus</a> {   <a href="Input.md#gga85d58a5185669daa4995e332b63eba7aa4b6c3821e689826c4323c4eb759b4d3a">INPUT_SUCCESS</a>, <a href="Input.md#gga85d58a5185669daa4995e332b63eba7aa2b90cc2935e5f41dfe3c2deb64bf5b7d">INPUT_EINVAL</a>, <a href="Input.md#gga85d58a5185669daa4995e332b63eba7aa53d87c9b8af7f40db9749009897f51c6">INPUT_EFAULT</a>, <a href="Input.md#gga85d58a5185669daa4995e332b63eba7aafdde805f755166272b7ad0032519061d">INPUT_ENOMEM</a>,   <a href="Input.md#gga85d58a5185669daa4995e332b63eba7aa24ea43cc8f7bdc8845ce70377d5a03a3">INPUT_ETIMEOUT</a>, <a href="Input.md#gga85d58a5185669daa4995e332b63eba7aa3b5144f6e7cfd213e63a9220e60a681f">INPUT_EUNSUPPORT</a>, <a href="Input.md#gga85d58a5185669daa4995e332b63eba7aa9ce09ddb5727168672050bb75da9460c">INPUT_EUNKNOWN</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p983265838165623"><a name="p983265838165623"></a><a name="p983265838165623"></a>Enumerates return values. </p>
</td>
</tr>
<tr id="row1442531173165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1033993322165623"><a name="p1033993322165623"></a><a name="p1033993322165623"></a><a href="Input.md#gaa8225ba155dfa1ef2c4119c832bc4dd3">InputDevType</a> {   <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a621678554aac2b37ac244b80fc33da0d">INDEV_TYPE_TOUCH</a>, <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4c4c8407342021cc06a95aa13ebeaca1">INDEV_TYPE_KEY</a>, <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a3a4137efe666a3aaccf267d597879fdc">INDEV_TYPE_KEYBOARD</a>, <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3abe68740c1d125d3d474fdadc7d31d11c">INDEV_TYPE_MOUSE</a>,   <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a2815a25dde3e56e1f8eb57f20049e8c0">INDEV_TYPE_BUTTON</a>, <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4ef2ab6bc355e2321664709716d1d04f">INDEV_TYPE_CROWN</a>, <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a8cd6b27ac631b9d3fa89a17ddca37291">INDEV_TYPE_ENCODER</a>, <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4097247eba52062f47a1aa99414033de">INDEV_TYPE_UNKNOWN</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p708198190165623"><a name="p708198190165623"></a><a name="p708198190165623"></a>Enumerates input device types. </p>
</td>
</tr>
<tr id="row821800503165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p704870712165623"><a name="p704870712165623"></a><a name="p704870712165623"></a><a href="Input.md#ga65e6bb4d942c22dba9975253b0a1d73f">PowerStatus</a> { <a href="Input.md#gga65e6bb4d942c22dba9975253b0a1d73fa5edb1acdc509659046de9cb61bd9508a">INPUT_RESUME</a>, <a href="Input.md#gga65e6bb4d942c22dba9975253b0a1d73fa2a6aab1b3d50dae2b6ba43779e185ea5">INPUT_SUSPEND</a>, <a href="Input.md#gga65e6bb4d942c22dba9975253b0a1d73fa8895c64802d558830d46bcd921830e9d">INPUT_LOW_POWER</a>, <a href="Input.md#gga65e6bb4d942c22dba9975253b0a1d73fa728020b31c626f749d426cbe8f0f92fe">INPUT_POWER_STATUS_UNKNOWN</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1583171583165623"><a name="p1583171583165623"></a><a name="p1583171583165623"></a>Enumerates power statuses. </p>
</td>
</tr>
<tr id="row2057616830165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1328152374165623"><a name="p1328152374165623"></a><a name="p1328152374165623"></a><a href="Input.md#gae96e484cfd64ea37b5b7782f57f38a21">CapacitanceTest</a> {   <a href="Input.md#ggae96e484cfd64ea37b5b7782f57f38a21aedd31f50c79a36cc8e084d69a3fc695b">BASE_TEST</a>, <a href="Input.md#ggae96e484cfd64ea37b5b7782f57f38a21abfe92c879dc84b5b071899a7ec5cc41d">FULL_TEST</a>, <a href="Input.md#ggae96e484cfd64ea37b5b7782f57f38a21a93335d88212604ade3b0bfe7e619916f">MMI_TEST</a>, <a href="Input.md#ggae96e484cfd64ea37b5b7782f57f38a21a31afc25da895db4eaa2af6cec1d6b37c">RUNNING_TEST</a>,   <a href="Input.md#ggae96e484cfd64ea37b5b7782f57f38a21a9d739cecefd291b39152e3815445aa20">TEST_TYPE_UNKNOWN</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p813861446165623"><a name="p813861446165623"></a><a name="p813861446165623"></a>Enumerates types of capacitance tests. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table284840291165623"></a>
<table><thead align="left"><tr id="row1452803039165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1408821695165623"><a name="p1408821695165623"></a><a name="p1408821695165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1289956320165623"><a name="p1289956320165623"></a><a name="p1289956320165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1294647921165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1425751491165623"><a name="p1425751491165623"></a><a name="p1425751491165623"></a><a href="Input.md#ga3ca3e6b9bb859ba407b00a2175309cd3">GetInputInterface</a> (<a href="IInputInterface.md">IInputInterface</a> **interface)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1090596501165623"><a name="p1090596501165623"></a><a name="p1090596501165623"></a>int </p>
<p id="p2038056410165623"><a name="p2038056410165623"></a><a name="p2038056410165623"></a>Gets all interfaces for performing operations on input devices. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section417783477165623"></a>

## **Enumeration Type **<a name="section150212759165623"></a>

## CapacitanceTest<a name="gae96e484cfd64ea37b5b7782f57f38a21"></a>

```
enum [CapacitanceTest](Input.md#gae96e484cfd64ea37b5b7782f57f38a21)
```

 **Description:**

Enumerates types of capacitance tests. 

<a name="table438372025165623"></a>
<table><thead align="left"><tr id="row1611379257165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1554188216165623"><a name="p1554188216165623"></a><a name="p1554188216165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p870760206165623"><a name="p870760206165623"></a><a name="p870760206165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1979012717165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae96e484cfd64ea37b5b7782f57f38a21aedd31f50c79a36cc8e084d69a3fc695b"><a name="ggae96e484cfd64ea37b5b7782f57f38a21aedd31f50c79a36cc8e084d69a3fc695b"></a><a name="ggae96e484cfd64ea37b5b7782f57f38a21aedd31f50c79a36cc8e084d69a3fc695b"></a></strong>BASE_TEST </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1738518317165623"><a name="p1738518317165623"></a><a name="p1738518317165623"></a>Basic capacitance test </p>
 </td>
</tr>
<tr id="row423863856165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae96e484cfd64ea37b5b7782f57f38a21abfe92c879dc84b5b071899a7ec5cc41d"><a name="ggae96e484cfd64ea37b5b7782f57f38a21abfe92c879dc84b5b071899a7ec5cc41d"></a><a name="ggae96e484cfd64ea37b5b7782f57f38a21abfe92c879dc84b5b071899a7ec5cc41d"></a></strong>FULL_TEST </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1597935807165623"><a name="p1597935807165623"></a><a name="p1597935807165623"></a>Full capacitance self-test </p>
 </td>
</tr>
<tr id="row610244970165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae96e484cfd64ea37b5b7782f57f38a21a93335d88212604ade3b0bfe7e619916f"><a name="ggae96e484cfd64ea37b5b7782f57f38a21a93335d88212604ade3b0bfe7e619916f"></a><a name="ggae96e484cfd64ea37b5b7782f57f38a21a93335d88212604ade3b0bfe7e619916f"></a></strong>MMI_TEST </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1094849503165623"><a name="p1094849503165623"></a><a name="p1094849503165623"></a>Man-Machine Interface (MMI) capacitance test </p>
 </td>
</tr>
<tr id="row1609888942165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae96e484cfd64ea37b5b7782f57f38a21a31afc25da895db4eaa2af6cec1d6b37c"><a name="ggae96e484cfd64ea37b5b7782f57f38a21a31afc25da895db4eaa2af6cec1d6b37c"></a><a name="ggae96e484cfd64ea37b5b7782f57f38a21a31afc25da895db4eaa2af6cec1d6b37c"></a></strong>RUNNING_TEST </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p843949496165623"><a name="p843949496165623"></a><a name="p843949496165623"></a>Running capacitance test </p>
 </td>
</tr>
<tr id="row559948160165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae96e484cfd64ea37b5b7782f57f38a21a9d739cecefd291b39152e3815445aa20"><a name="ggae96e484cfd64ea37b5b7782f57f38a21a9d739cecefd291b39152e3815445aa20"></a><a name="ggae96e484cfd64ea37b5b7782f57f38a21a9d739cecefd291b39152e3815445aa20"></a></strong>TEST_TYPE_UNKNOWN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1862188001165623"><a name="p1862188001165623"></a><a name="p1862188001165623"></a>Unknown test type </p>
 </td>
</tr>
</tbody>
</table>

## InputDevType<a name="gaa8225ba155dfa1ef2c4119c832bc4dd3"></a>

```
enum [InputDevType](Input.md#gaa8225ba155dfa1ef2c4119c832bc4dd3)
```

 **Description:**

Enumerates input device types. 

<a name="table1706893790165623"></a>
<table><thead align="left"><tr id="row458524869165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1077785378165623"><a name="p1077785378165623"></a><a name="p1077785378165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p462247727165623"><a name="p462247727165623"></a><a name="p462247727165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1691898346165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa8225ba155dfa1ef2c4119c832bc4dd3a621678554aac2b37ac244b80fc33da0d"><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3a621678554aac2b37ac244b80fc33da0d"></a><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3a621678554aac2b37ac244b80fc33da0d"></a></strong>INDEV_TYPE_TOUCH </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1657971308165623"><a name="p1657971308165623"></a><a name="p1657971308165623"></a>Touchscreen </p>
 </td>
</tr>
<tr id="row1420252354165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa8225ba155dfa1ef2c4119c832bc4dd3a4c4c8407342021cc06a95aa13ebeaca1"><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3a4c4c8407342021cc06a95aa13ebeaca1"></a><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3a4c4c8407342021cc06a95aa13ebeaca1"></a></strong>INDEV_TYPE_KEY </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1039727958165623"><a name="p1039727958165623"></a><a name="p1039727958165623"></a>Physical key </p>
 </td>
</tr>
<tr id="row2134985926165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa8225ba155dfa1ef2c4119c832bc4dd3a3a4137efe666a3aaccf267d597879fdc"><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3a3a4137efe666a3aaccf267d597879fdc"></a><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3a3a4137efe666a3aaccf267d597879fdc"></a></strong>INDEV_TYPE_KEYBOARD </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p504531963165623"><a name="p504531963165623"></a><a name="p504531963165623"></a>Keyboard </p>
 </td>
</tr>
<tr id="row406789237165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa8225ba155dfa1ef2c4119c832bc4dd3abe68740c1d125d3d474fdadc7d31d11c"><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3abe68740c1d125d3d474fdadc7d31d11c"></a><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3abe68740c1d125d3d474fdadc7d31d11c"></a></strong>INDEV_TYPE_MOUSE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1646580209165623"><a name="p1646580209165623"></a><a name="p1646580209165623"></a>Mouse </p>
 </td>
</tr>
<tr id="row554665347165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa8225ba155dfa1ef2c4119c832bc4dd3a2815a25dde3e56e1f8eb57f20049e8c0"><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3a2815a25dde3e56e1f8eb57f20049e8c0"></a><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3a2815a25dde3e56e1f8eb57f20049e8c0"></a></strong>INDEV_TYPE_BUTTON </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p68933054165623"><a name="p68933054165623"></a><a name="p68933054165623"></a>Virtual button </p>
 </td>
</tr>
<tr id="row653272906165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa8225ba155dfa1ef2c4119c832bc4dd3a4ef2ab6bc355e2321664709716d1d04f"><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3a4ef2ab6bc355e2321664709716d1d04f"></a><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3a4ef2ab6bc355e2321664709716d1d04f"></a></strong>INDEV_TYPE_CROWN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p95485486165623"><a name="p95485486165623"></a><a name="p95485486165623"></a>Watch crown </p>
 </td>
</tr>
<tr id="row359147613165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa8225ba155dfa1ef2c4119c832bc4dd3a8cd6b27ac631b9d3fa89a17ddca37291"><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3a8cd6b27ac631b9d3fa89a17ddca37291"></a><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3a8cd6b27ac631b9d3fa89a17ddca37291"></a></strong>INDEV_TYPE_ENCODER </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p612486296165623"><a name="p612486296165623"></a><a name="p612486296165623"></a>Customized type of a specific function or event </p>
 </td>
</tr>
<tr id="row894166235165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa8225ba155dfa1ef2c4119c832bc4dd3a4097247eba52062f47a1aa99414033de"><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3a4097247eba52062f47a1aa99414033de"></a><a name="ggaa8225ba155dfa1ef2c4119c832bc4dd3a4097247eba52062f47a1aa99414033de"></a></strong>INDEV_TYPE_UNKNOWN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p181438744165623"><a name="p181438744165623"></a><a name="p181438744165623"></a>Unknown input device type </p>
 </td>
</tr>
</tbody>
</table>

## PowerStatus<a name="ga65e6bb4d942c22dba9975253b0a1d73f"></a>

```
enum [PowerStatus](Input.md#ga65e6bb4d942c22dba9975253b0a1d73f)
```

 **Description:**

Enumerates power statuses. 

<a name="table1965129775165623"></a>
<table><thead align="left"><tr id="row305380030165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1831766004165623"><a name="p1831766004165623"></a><a name="p1831766004165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2118534707165623"><a name="p2118534707165623"></a><a name="p2118534707165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row626027946165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga65e6bb4d942c22dba9975253b0a1d73fa5edb1acdc509659046de9cb61bd9508a"><a name="gga65e6bb4d942c22dba9975253b0a1d73fa5edb1acdc509659046de9cb61bd9508a"></a><a name="gga65e6bb4d942c22dba9975253b0a1d73fa5edb1acdc509659046de9cb61bd9508a"></a></strong>INPUT_RESUME </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p263116248165623"><a name="p263116248165623"></a><a name="p263116248165623"></a>Resume status </p>
 </td>
</tr>
<tr id="row1309179979165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga65e6bb4d942c22dba9975253b0a1d73fa2a6aab1b3d50dae2b6ba43779e185ea5"><a name="gga65e6bb4d942c22dba9975253b0a1d73fa2a6aab1b3d50dae2b6ba43779e185ea5"></a><a name="gga65e6bb4d942c22dba9975253b0a1d73fa2a6aab1b3d50dae2b6ba43779e185ea5"></a></strong>INPUT_SUSPEND </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p949048566165623"><a name="p949048566165623"></a><a name="p949048566165623"></a>Suspend status </p>
 </td>
</tr>
<tr id="row240708959165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga65e6bb4d942c22dba9975253b0a1d73fa8895c64802d558830d46bcd921830e9d"><a name="gga65e6bb4d942c22dba9975253b0a1d73fa8895c64802d558830d46bcd921830e9d"></a><a name="gga65e6bb4d942c22dba9975253b0a1d73fa8895c64802d558830d46bcd921830e9d"></a></strong>INPUT_LOW_POWER </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p894237544165623"><a name="p894237544165623"></a><a name="p894237544165623"></a>Low-power status </p>
 </td>
</tr>
<tr id="row1334620583165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga65e6bb4d942c22dba9975253b0a1d73fa728020b31c626f749d426cbe8f0f92fe"><a name="gga65e6bb4d942c22dba9975253b0a1d73fa728020b31c626f749d426cbe8f0f92fe"></a><a name="gga65e6bb4d942c22dba9975253b0a1d73fa728020b31c626f749d426cbe8f0f92fe"></a></strong>INPUT_POWER_STATUS_UNKNOWN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p806473836165623"><a name="p806473836165623"></a><a name="p806473836165623"></a>Unknown power status </p>
 </td>
</tr>
</tbody>
</table>

## RetStatus<a name="ga85d58a5185669daa4995e332b63eba7a"></a>

```
enum [RetStatus](Input.md#ga85d58a5185669daa4995e332b63eba7a)
```

 **Description:**

Enumerates return values. 

<a name="table1449987954165623"></a>
<table><thead align="left"><tr id="row1940801633165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1819512974165623"><a name="p1819512974165623"></a><a name="p1819512974165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p963142743165623"><a name="p963142743165623"></a><a name="p963142743165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row768764389165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga85d58a5185669daa4995e332b63eba7aa4b6c3821e689826c4323c4eb759b4d3a"><a name="gga85d58a5185669daa4995e332b63eba7aa4b6c3821e689826c4323c4eb759b4d3a"></a><a name="gga85d58a5185669daa4995e332b63eba7aa4b6c3821e689826c4323c4eb759b4d3a"></a></strong>INPUT_SUCCESS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2016642971165623"><a name="p2016642971165623"></a><a name="p2016642971165623"></a>Success </p>
 </td>
</tr>
<tr id="row1175305024165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga85d58a5185669daa4995e332b63eba7aa2b90cc2935e5f41dfe3c2deb64bf5b7d"><a name="gga85d58a5185669daa4995e332b63eba7aa2b90cc2935e5f41dfe3c2deb64bf5b7d"></a><a name="gga85d58a5185669daa4995e332b63eba7aa2b90cc2935e5f41dfe3c2deb64bf5b7d"></a></strong>INPUT_EINVAL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p414090419165623"><a name="p414090419165623"></a><a name="p414090419165623"></a>Invalid value </p>
 </td>
</tr>
<tr id="row462593271165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga85d58a5185669daa4995e332b63eba7aa53d87c9b8af7f40db9749009897f51c6"><a name="gga85d58a5185669daa4995e332b63eba7aa53d87c9b8af7f40db9749009897f51c6"></a><a name="gga85d58a5185669daa4995e332b63eba7aa53d87c9b8af7f40db9749009897f51c6"></a></strong>INPUT_EFAULT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1745573674165623"><a name="p1745573674165623"></a><a name="p1745573674165623"></a>Runtime error </p>
 </td>
</tr>
<tr id="row2138525638165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga85d58a5185669daa4995e332b63eba7aafdde805f755166272b7ad0032519061d"><a name="gga85d58a5185669daa4995e332b63eba7aafdde805f755166272b7ad0032519061d"></a><a name="gga85d58a5185669daa4995e332b63eba7aafdde805f755166272b7ad0032519061d"></a></strong>INPUT_ENOMEM </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1708441662165623"><a name="p1708441662165623"></a><a name="p1708441662165623"></a>Failed to apply for memory </p>
 </td>
</tr>
<tr id="row465443899165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga85d58a5185669daa4995e332b63eba7aa24ea43cc8f7bdc8845ce70377d5a03a3"><a name="gga85d58a5185669daa4995e332b63eba7aa24ea43cc8f7bdc8845ce70377d5a03a3"></a><a name="gga85d58a5185669daa4995e332b63eba7aa24ea43cc8f7bdc8845ce70377d5a03a3"></a></strong>INPUT_ETIMEOUT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p422552200165623"><a name="p422552200165623"></a><a name="p422552200165623"></a>Execution timed out </p>
 </td>
</tr>
<tr id="row1596911622165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga85d58a5185669daa4995e332b63eba7aa3b5144f6e7cfd213e63a9220e60a681f"><a name="gga85d58a5185669daa4995e332b63eba7aa3b5144f6e7cfd213e63a9220e60a681f"></a><a name="gga85d58a5185669daa4995e332b63eba7aa3b5144f6e7cfd213e63a9220e60a681f"></a></strong>INPUT_EUNSUPPORT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p617367410165623"><a name="p617367410165623"></a><a name="p617367410165623"></a>The feature is not supported </p>
 </td>
</tr>
<tr id="row877204038165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga85d58a5185669daa4995e332b63eba7aa9ce09ddb5727168672050bb75da9460c"><a name="gga85d58a5185669daa4995e332b63eba7aa9ce09ddb5727168672050bb75da9460c"></a><a name="gga85d58a5185669daa4995e332b63eba7aa9ce09ddb5727168672050bb75da9460c"></a></strong>INPUT_EUNKNOWN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1861818423165623"><a name="p1861818423165623"></a><a name="p1861818423165623"></a>Unknown error </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section882045796165623"></a>

## GetInputInterface\(\)<a name="ga3ca3e6b9bb859ba407b00a2175309cd3"></a>

```
int GetInputInterface ([IInputInterface](IInputInterface.md) ** interface)
```

 **Description:**

Gets all interfaces for performing operations on input devices. 

You can call this function after the input service is started.

**Parameters:**

<a name="table344536011165623"></a>
<table><thead align="left"><tr id="row717142382165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1328153687165623"><a name="p1328153687165623"></a><a name="p1328153687165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p313201975165623"><a name="p313201975165623"></a><a name="p313201975165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row123998389165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">interface</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the interface for performing operations on input devices. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](Input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

