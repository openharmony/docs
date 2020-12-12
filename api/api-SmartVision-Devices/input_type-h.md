# input\_type.h<a name="ZH-CN_TOPIC_0000001055678064"></a>

-   [Overview](#section1424166204165627)
-   [Summary](#section597880895165627)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)

## **Overview**<a name="section1424166204165627"></a>

**Related Modules:**

[Input](Input.md)

**Description:**

Declares types of input devices as well as the structure and enumeration types used by driver interfaces. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section597880895165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table742519891165627"></a>
<table><thead align="left"><tr id="row917266377165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1296392966165627"><a name="p1296392966165627"></a><a name="p1296392966165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p634333951165627"><a name="p634333951165627"></a><a name="p634333951165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row630885483165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p466125173165627"><a name="p466125173165627"></a><a name="p466125173165627"></a><a href="InputExtraCmd.md">InputExtraCmd</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p844771175165627"><a name="p844771175165627"></a><a name="p844771175165627"></a>Defines the extra commands. </p>
</td>
</tr>
<tr id="row43781317165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p973595405165627"><a name="p973595405165627"></a><a name="p973595405165627"></a><a href="InputEventData.md">InputEventData</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1419200528165627"><a name="p1419200528165627"></a><a name="p1419200528165627"></a>Describes the input event data. </p>
</td>
</tr>
<tr id="row1880682663165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p556154582165627"><a name="p556154582165627"></a><a name="p556154582165627"></a><a href="InputReportEventCb.md">InputReportEventCb</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p82678030165627"><a name="p82678030165627"></a><a name="p82678030165627"></a>Describes the input event callback registered by the input service. </p>
</td>
</tr>
<tr id="row1637632443165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1940444181165627"><a name="p1940444181165627"></a><a name="p1940444181165627"></a><a href="DeviceInfo.md">DeviceInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2120296495165627"><a name="p2120296495165627"></a><a name="p2120296495165627"></a>Describes basic device information of the input device. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1862866804165627"></a>
<table><thead align="left"><tr id="row1137775508165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p974844601165627"><a name="p974844601165627"></a><a name="p974844601165627"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1505430381165627"><a name="p1505430381165627"></a><a name="p1505430381165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1222639140165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p808511394165627"><a name="p808511394165627"></a><a name="p808511394165627"></a><a href="Input.md#ga85d58a5185669daa4995e332b63eba7a">RetStatus</a> {   <a href="Input.md#gga85d58a5185669daa4995e332b63eba7aa4b6c3821e689826c4323c4eb759b4d3a">INPUT_SUCCESS</a>, <a href="Input.md#gga85d58a5185669daa4995e332b63eba7aa2b90cc2935e5f41dfe3c2deb64bf5b7d">INPUT_EINVAL</a>, <a href="Input.md#gga85d58a5185669daa4995e332b63eba7aa53d87c9b8af7f40db9749009897f51c6">INPUT_EFAULT</a>, <a href="Input.md#gga85d58a5185669daa4995e332b63eba7aafdde805f755166272b7ad0032519061d">INPUT_ENOMEM</a>,   <a href="Input.md#gga85d58a5185669daa4995e332b63eba7aa24ea43cc8f7bdc8845ce70377d5a03a3">INPUT_ETIMEOUT</a>, <a href="Input.md#gga85d58a5185669daa4995e332b63eba7aa3b5144f6e7cfd213e63a9220e60a681f">INPUT_EUNSUPPORT</a>, <a href="Input.md#gga85d58a5185669daa4995e332b63eba7aa9ce09ddb5727168672050bb75da9460c">INPUT_EUNKNOWN</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p652072478165627"><a name="p652072478165627"></a><a name="p652072478165627"></a>Enumerates return values. </p>
</td>
</tr>
<tr id="row480993825165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p377296276165627"><a name="p377296276165627"></a><a name="p377296276165627"></a><a href="Input.md#gaa8225ba155dfa1ef2c4119c832bc4dd3">InputDevType</a> {   <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a621678554aac2b37ac244b80fc33da0d">INDEV_TYPE_TOUCH</a>, <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4c4c8407342021cc06a95aa13ebeaca1">INDEV_TYPE_KEY</a>, <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a3a4137efe666a3aaccf267d597879fdc">INDEV_TYPE_KEYBOARD</a>, <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3abe68740c1d125d3d474fdadc7d31d11c">INDEV_TYPE_MOUSE</a>,   <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a2815a25dde3e56e1f8eb57f20049e8c0">INDEV_TYPE_BUTTON</a>, <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4ef2ab6bc355e2321664709716d1d04f">INDEV_TYPE_CROWN</a>, <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a8cd6b27ac631b9d3fa89a17ddca37291">INDEV_TYPE_ENCODER</a>, <a href="Input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4097247eba52062f47a1aa99414033de">INDEV_TYPE_UNKNOWN</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1639250645165627"><a name="p1639250645165627"></a><a name="p1639250645165627"></a>Enumerates input device types. </p>
</td>
</tr>
<tr id="row1058402922165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1491835120165627"><a name="p1491835120165627"></a><a name="p1491835120165627"></a><a href="Input.md#ga65e6bb4d942c22dba9975253b0a1d73f">PowerStatus</a> { <a href="Input.md#gga65e6bb4d942c22dba9975253b0a1d73fa5edb1acdc509659046de9cb61bd9508a">INPUT_RESUME</a>, <a href="Input.md#gga65e6bb4d942c22dba9975253b0a1d73fa2a6aab1b3d50dae2b6ba43779e185ea5">INPUT_SUSPEND</a>, <a href="Input.md#gga65e6bb4d942c22dba9975253b0a1d73fa8895c64802d558830d46bcd921830e9d">INPUT_LOW_POWER</a>, <a href="Input.md#gga65e6bb4d942c22dba9975253b0a1d73fa728020b31c626f749d426cbe8f0f92fe">INPUT_POWER_STATUS_UNKNOWN</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1276040581165627"><a name="p1276040581165627"></a><a name="p1276040581165627"></a>Enumerates power statuses. </p>
</td>
</tr>
<tr id="row1044224389165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2082438523165627"><a name="p2082438523165627"></a><a name="p2082438523165627"></a><a href="Input.md#gae96e484cfd64ea37b5b7782f57f38a21">CapacitanceTest</a> {   <a href="Input.md#ggae96e484cfd64ea37b5b7782f57f38a21aedd31f50c79a36cc8e084d69a3fc695b">BASE_TEST</a>, <a href="Input.md#ggae96e484cfd64ea37b5b7782f57f38a21abfe92c879dc84b5b071899a7ec5cc41d">FULL_TEST</a>, <a href="Input.md#ggae96e484cfd64ea37b5b7782f57f38a21a93335d88212604ade3b0bfe7e619916f">MMI_TEST</a>, <a href="Input.md#ggae96e484cfd64ea37b5b7782f57f38a21a31afc25da895db4eaa2af6cec1d6b37c">RUNNING_TEST</a>,   <a href="Input.md#ggae96e484cfd64ea37b5b7782f57f38a21a9d739cecefd291b39152e3815445aa20">TEST_TYPE_UNKNOWN</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p476780826165627"><a name="p476780826165627"></a><a name="p476780826165627"></a>Enumerates types of capacitance tests. </p>
</td>
</tr>
</tbody>
</table>

