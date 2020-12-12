# InputReporter<a name="EN-US_TOPIC_0000001054479565"></a>

-   [Overview](#section1071467766165631)
-   [Summary](#section42665863165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1227693544165631)
-   [Field](#section1743608718165631)
-   [GetInputEvent](#a879d9272d932f566e667b7e768b5530e)
-   [RegisterReportCallback](#a8cbea98a78a293bc8ab6f41c6adeb675)
-   [UnregisterReportCallback](#a8c10af61e0c73c91292b806a7ea1d069)

## **Overview**<a name="section1071467766165631"></a>

**Related Modules:**

[Input](input.md)

**Description:**

Provides interfaces for reporting event data of input devices. 

The interfaces include the callback for reporting the input event data and the functions for obtaining the data in polling mode. 

## **Summary**<a name="section42665863165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table473126876165631"></a>
<table><thead align="left"><tr id="row1944083526165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1889911657165631"><a name="p1889911657165631"></a><a name="p1889911657165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2119430451165631"><a name="p2119430451165631"></a><a name="p2119430451165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1252146808165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p357361933165631"><a name="p357361933165631"></a><a name="p357361933165631"></a><a href="inputreporter.md#a8cbea98a78a293bc8ab6f41c6adeb675">RegisterReportCallback</a> )(uint32_t devIndex, <a href="inputreporteventcb.md">InputReportEventCb</a> *callback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1783654172165631"><a name="p1783654172165631"></a><a name="p1783654172165631"></a>int32_t(* </p>
<p id="p1513629444165631"><a name="p1513629444165631"></a><a name="p1513629444165631"></a>Registers a callback for reporting subscribed data of specified input devices. </p>
</td>
</tr>
<tr id="row1524409805165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1009696949165631"><a name="p1009696949165631"></a><a name="p1009696949165631"></a><a href="inputreporter.md#a8c10af61e0c73c91292b806a7ea1d069">UnregisterReportCallback</a> )(uint32_t devIndex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p575206508165631"><a name="p575206508165631"></a><a name="p575206508165631"></a>int32_t(* </p>
<p id="p409640673165631"><a name="p409640673165631"></a><a name="p409640673165631"></a>Unregisters the callback for reporting subscribed data of specified input devices. </p>
</td>
</tr>
<tr id="row1780856585165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1379250441165631"><a name="p1379250441165631"></a><a name="p1379250441165631"></a><a href="inputreporter.md#a879d9272d932f566e667b7e768b5530e">GetInputEvent</a> )(uint32_t devIndex, <a href="inputeventdata.md">InputEventData</a> *eventData)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2040566279165631"><a name="p2040566279165631"></a><a name="p2040566279165631"></a>int32_t(* </p>
<p id="p580211397165631"><a name="p580211397165631"></a><a name="p580211397165631"></a>Gets the input event data. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1227693544165631"></a>

## **Field **<a name="section1743608718165631"></a>

## GetInputEvent<a name="a879d9272d932f566e667b7e768b5530e"></a>

```
int32_t(* InputReporter::GetInputEvent) (uint32_t devIndex, [InputEventData](inputeventdata.md) *eventData)
```

 **Description:**

Gets the input event data. 

This function enables the input service to proactively obtain the input event data in polling mode.

**Parameters:**

<a name="table1461616715165631"></a>
<table><thead align="left"><tr id="row989522076165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1137325050165631"><a name="p1137325050165631"></a><a name="p1137325050165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1842676424165631"><a name="p1842676424165631"></a><a name="p1842676424165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row257446400165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b1127209054165631"><a name="b1127209054165631"></a><a name="b1127209054165631"></a>0</strong> represents the first input device. </td>
</tr>
<tr id="row1762688831165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">eventData</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the input event data reported by the input driver. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

## RegisterReportCallback<a name="a8cbea98a78a293bc8ab6f41c6adeb675"></a>

```
int32_t(* InputReporter::RegisterReportCallback) (uint32_t devIndex, [InputReportEventCb](inputreporteventcb.md) *callback)
```

 **Description:**

Registers a callback for reporting subscribed data of specified input devices. 

After this callback is successfully registered, the driver can report the input event data to the input service through this callback.

**Parameters:**

<a name="table1316631842165631"></a>
<table><thead align="left"><tr id="row793359002165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1369046072165631"><a name="p1369046072165631"></a><a name="p1369046072165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1491016563165631"><a name="p1491016563165631"></a><a name="p1491016563165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1496620011165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b451627212165631"><a name="b451627212165631"></a><a name="b451627212165631"></a>0</strong> represents the first input device. </td>
</tr>
<tr id="row379217300165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">callback</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the callback to register. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

## UnregisterReportCallback<a name="a8c10af61e0c73c91292b806a7ea1d069"></a>

```
int32_t(* InputReporter::UnregisterReportCallback) (uint32_t devIndex)
```

 **Description:**

Unregisters the callback for reporting subscribed data of specified input devices. 

**Parameters:**

<a name="table1622060286165631"></a>
<table><thead align="left"><tr id="row623477284165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1574662516165631"><a name="p1574662516165631"></a><a name="p1574662516165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2140450373165631"><a name="p2140450373165631"></a><a name="p2140450373165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row484706313165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b1770058281165631"><a name="b1770058281165631"></a><a name="b1770058281165631"></a>0</strong> represents the first input device. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [RetStatus](input.md#ga85d58a5185669daa4995e332b63eba7a)  otherwise. 

