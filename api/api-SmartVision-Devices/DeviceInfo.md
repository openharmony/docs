# DeviceInfo<a name="ZH-CN_TOPIC_0000001055678088"></a>

-   [Overview](#section1817258413165631)
-   [Summary](#section402734126165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1024585535165631)
-   [Field](#section1981473937165631)
-   [callback](#a90b6d7e07aa21e507a7b16f380df4fb8)
-   [chipInfo](#a39b8ad5d23fb776ec333adbd64025691)
-   [chipName](#ad6458f297131a4f3a9dba820e069d525)
-   [devIndex](#a1582f8d7e63ac2a2c1a1511bb73aeafd)
-   [devNodePath](#a47e7d5536f061f3e11934fd1ff4cf61b)
-   [devType](#aec5bff7e9a51ba2fc149156d83154448)
-   [fd](#a8be40a9da438bed3c2f13bf2bf07217b)
-   [powerStatus](#adcedf378ddac2489b2a6abc1970807df)
-   [solutionX](#aba81fb331433f16cfcf435dd05c6e3c3)
-   [solutionY](#a90174e4a421db368c2d179ab1bbb0f96)
-   [vendorName](#a24b2b30666e776c0637d7c3f2805bb04)

## **Overview**<a name="section1817258413165631"></a>

**Related Modules:**

[Input](Input.md)

**Description:**

Describes basic device information of the input device. 

## **Summary**<a name="section402734126165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1979167624165631"></a>
<table><thead align="left"><tr id="row1481056118165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1808517400165631"><a name="p1808517400165631"></a><a name="p1808517400165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1736715230165631"><a name="p1736715230165631"></a><a name="p1736715230165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1380498161165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1405664589165631"><a name="p1405664589165631"></a><a name="p1405664589165631"></a><a href="DeviceInfo.md#a1582f8d7e63ac2a2c1a1511bb73aeafd">devIndex</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1487657606165631"><a name="p1487657606165631"></a><a name="p1487657606165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row183961228165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p989917200165631"><a name="p989917200165631"></a><a name="p989917200165631"></a><a href="DeviceInfo.md#a8be40a9da438bed3c2f13bf2bf07217b">fd</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1324048497165631"><a name="p1324048497165631"></a><a name="p1324048497165631"></a>int32_t </p>
</td>
</tr>
<tr id="row1908202225165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p707403832165631"><a name="p707403832165631"></a><a name="p707403832165631"></a><a href="DeviceInfo.md#aec5bff7e9a51ba2fc149156d83154448">devType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p697977854165631"><a name="p697977854165631"></a><a name="p697977854165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row1595825562165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p582993921165631"><a name="p582993921165631"></a><a name="p582993921165631"></a><a href="DeviceInfo.md#adcedf378ddac2489b2a6abc1970807df">powerStatus</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p673254171165631"><a name="p673254171165631"></a><a name="p673254171165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row2128446751165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p993106241165631"><a name="p993106241165631"></a><a name="p993106241165631"></a><a href="DeviceInfo.md#a39b8ad5d23fb776ec333adbd64025691">chipInfo</a> [CHIP_INFO_LEN]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1950493923165631"><a name="p1950493923165631"></a><a name="p1950493923165631"></a>char </p>
</td>
</tr>
<tr id="row20470428165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p865313036165631"><a name="p865313036165631"></a><a name="p865313036165631"></a><a href="DeviceInfo.md#a24b2b30666e776c0637d7c3f2805bb04">vendorName</a> [VENDOR_NAME_LEN]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p579243817165631"><a name="p579243817165631"></a><a name="p579243817165631"></a>char </p>
</td>
</tr>
<tr id="row738795752165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p172184434165631"><a name="p172184434165631"></a><a name="p172184434165631"></a><a href="DeviceInfo.md#ad6458f297131a4f3a9dba820e069d525">chipName</a> [CHIP_NAME_LEN]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p475832451165631"><a name="p475832451165631"></a><a name="p475832451165631"></a>char </p>
</td>
</tr>
<tr id="row2108281214165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p753784851165631"><a name="p753784851165631"></a><a name="p753784851165631"></a><a href="DeviceInfo.md#a47e7d5536f061f3e11934fd1ff4cf61b">devNodePath</a> [DEV_NODE_PATH]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1123671370165631"><a name="p1123671370165631"></a><a name="p1123671370165631"></a>char </p>
</td>
</tr>
<tr id="row366715668165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1891009787165631"><a name="p1891009787165631"></a><a name="p1891009787165631"></a><a href="DeviceInfo.md#aba81fb331433f16cfcf435dd05c6e3c3">solutionX</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1092496610165631"><a name="p1092496610165631"></a><a name="p1092496610165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row1476052508165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1026412028165631"><a name="p1026412028165631"></a><a name="p1026412028165631"></a><a href="DeviceInfo.md#a90174e4a421db368c2d179ab1bbb0f96">solutionY</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p528084630165631"><a name="p528084630165631"></a><a name="p528084630165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row1105804807165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p420649689165631"><a name="p420649689165631"></a><a name="p420649689165631"></a><a href="DeviceInfo.md#a90b6d7e07aa21e507a7b16f380df4fb8">callback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2088500700165631"><a name="p2088500700165631"></a><a name="p2088500700165631"></a><a href="InputReportEventCb.md">InputReportEventCb</a> * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1024585535165631"></a>

## **Field **<a name="section1981473937165631"></a>

## callback<a name="a90b6d7e07aa21e507a7b16f380df4fb8"></a>

```
[InputReportEventCb](InputReportEventCb.md)* DeviceInfo::callback
```

 **Description:**

Callback  [InputReportEventCb](InputReportEventCb.md)  for reporting data 

## chipInfo<a name="a39b8ad5d23fb776ec333adbd64025691"></a>

```
char DeviceInfo::chipInfo[CHIP_INFO_LEN]
```

 **Description:**

Driver chip information 

## chipName<a name="ad6458f297131a4f3a9dba820e069d525"></a>

```
char DeviceInfo::chipName[CHIP_NAME_LEN]
```

 **Description:**

Driver chip name 

## devIndex<a name="a1582f8d7e63ac2a2c1a1511bb73aeafd"></a>

```
uint32_t DeviceInfo::devIndex
```

 **Description:**

Device index 

## devNodePath<a name="a47e7d5536f061f3e11934fd1ff4cf61b"></a>

```
char DeviceInfo::devNodePath[DEV_NODE_PATH]
```

 **Description:**

Device file path 

## devType<a name="aec5bff7e9a51ba2fc149156d83154448"></a>

```
uint32_t DeviceInfo::devType
```

 **Description:**

Device type 

## fd<a name="a8be40a9da438bed3c2f13bf2bf07217b"></a>

```
int32_t DeviceInfo::fd
```

 **Description:**

File descriptor of the device 

## powerStatus<a name="adcedf378ddac2489b2a6abc1970807df"></a>

```
uint32_t DeviceInfo::powerStatus
```

 **Description:**

Power status 

## solutionX<a name="aba81fb331433f16cfcf435dd05c6e3c3"></a>

```
uint32_t DeviceInfo::solutionX
```

 **Description:**

Resolution in the X axis 

## solutionY<a name="a90174e4a421db368c2d179ab1bbb0f96"></a>

```
uint32_t DeviceInfo::solutionY
```

 **Description:**

Resolution in the Y axis 

## vendorName<a name="a24b2b30666e776c0637d7c3f2805bb04"></a>

```
char DeviceInfo::vendorName[VENDOR_NAME_LEN]
```

 **Description:**

Module vendor name 

