# CodecCallback<a name="ZH-CN_TOPIC_0000001055358102"></a>

-   [Overview](#section1117951861165631)
-   [Summary](#section1269918023165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1278003397165631)
-   [Field](#section1513699407165631)
-   [InputBufferAvailable](#a97ba05617547d79b459bfed6172b4d75)
-   [OnEvent](#a039d0a4af8c4e3d10f49426d46f0b0f3)
-   [OutputBufferAvailable](#ad99eedd9953bdf22e426a181b08b8d0d)

## **Overview**<a name="section1117951861165631"></a>

**Related Modules:**

[Codec](Codec.md)

**Description:**

Defines callbacks and their parameters. 

## **Summary**<a name="section1269918023165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table827249335165631"></a>
<table><thead align="left"><tr id="row34784417165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1235306087165631"><a name="p1235306087165631"></a><a name="p1235306087165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1241487047165631"><a name="p1241487047165631"></a><a name="p1241487047165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row27325728165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1293176428165631"><a name="p1293176428165631"></a><a name="p1293176428165631"></a><a href="CodecCallback.md#a039d0a4af8c4e3d10f49426d46f0b0f3">OnEvent</a> )(<a href="Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc">UINTPTR</a> comp, <a href="Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc">UINTPTR</a> appData, <a href="Codec.md#ga2628ea8d12e8b2563c32f05dc7fff6fa">EventType</a> event, uint32_t data1, uint32_t data2, <a href="Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc">UINTPTR</a> eventData)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p769028949165631"><a name="p769028949165631"></a><a name="p769028949165631"></a>int(* </p>
<p id="p1759996502165631"><a name="p1759996502165631"></a><a name="p1759996502165631"></a>Reports an event. </p>
</td>
</tr>
<tr id="row1308975361165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p606061675165631"><a name="p606061675165631"></a><a name="p606061675165631"></a><a href="CodecCallback.md#a97ba05617547d79b459bfed6172b4d75">InputBufferAvailable</a> )(<a href="Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc">UINTPTR</a> comp, <a href="Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc">UINTPTR</a> appData, <a href="InputInfo.md">InputInfo</a> *inBuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1079389224165631"><a name="p1079389224165631"></a><a name="p1079389224165631"></a>int(* </p>
<p id="p995228769165631"><a name="p995228769165631"></a><a name="p995228769165631"></a>Reports that the input data has been used. </p>
</td>
</tr>
<tr id="row456804631165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p218873712165631"><a name="p218873712165631"></a><a name="p218873712165631"></a><a href="CodecCallback.md#ad99eedd9953bdf22e426a181b08b8d0d">OutputBufferAvailable</a> )(<a href="Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc">UINTPTR</a> comp, <a href="Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc">UINTPTR</a> appData, <a href="OutputInfo.md">OutputInfo</a> *outBuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1953949008165631"><a name="p1953949008165631"></a><a name="p1953949008165631"></a>int(* </p>
<p id="p1051390987165631"><a name="p1051390987165631"></a><a name="p1051390987165631"></a>Reports that the output is complete. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1278003397165631"></a>

## **Field **<a name="section1513699407165631"></a>

## InputBufferAvailable<a name="a97ba05617547d79b459bfed6172b4d75"></a>

```
int(* CodecCallback::InputBufferAvailable) ([UINTPTR](Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc) comp, [UINTPTR](Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc) appData, [InputInfo](InputInfo.md) *inBuf)
```

 **Description:**

Reports that the input data has been used. 

This callback is invoked in asynchronous mode.

**Parameters:**

<a name="table339939142165631"></a>
<table><thead align="left"><tr id="row86120334165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p455200962165631"><a name="p455200962165631"></a><a name="p455200962165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1219342047165631"><a name="p1219342047165631"></a><a name="p1219342047165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row392320281165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">hComponent</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the handle of the codec component. </td>
</tr>
<tr id="row1506299519165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pAppData</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates upper-layer data, which is generally an upper-layer instance passed when this callback is set. </td>
</tr>
<tr id="row1977953011165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pBuffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the input data that has been used. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## OnEvent<a name="a039d0a4af8c4e3d10f49426d46f0b0f3"></a>

```
int(* CodecCallback::OnEvent) ([UINTPTR](Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc) comp, [UINTPTR](Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc) appData, [EventType](Codec.md#ga2628ea8d12e8b2563c32f05dc7fff6fa) event, uint32_t data1, uint32_t data2, [UINTPTR](Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc) eventData)
```

 **Description:**

Reports an event. 

Reports event errors and output format changes.

**Parameters:**

<a name="table1919635177165631"></a>
<table><thead align="left"><tr id="row532557393165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1835921152165631"><a name="p1835921152165631"></a><a name="p1835921152165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1019894881165631"><a name="p1019894881165631"></a><a name="p1019894881165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1128322453165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">hComponent</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the handle of the codec component. </td>
</tr>
<tr id="row379435871165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pAppData</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates upper-layer data, which is generally an upper-layer instance passed when this callback is set. </td>
</tr>
<tr id="row1735615878165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">EVENTTYPE</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the event type. </td>
</tr>
<tr id="row168900354165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nData1</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the first value contained in the reported event. This parameter is optional. </td>
</tr>
<tr id="row1696233859165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nData2</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the second value contained in the reported event. This parameter is optional. </td>
</tr>
<tr id="row1673939211165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pEventData</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to data contained in the reported event. This parameter is optional. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## OutputBufferAvailable<a name="ad99eedd9953bdf22e426a181b08b8d0d"></a>

```
int(* CodecCallback::OutputBufferAvailable) ([UINTPTR](Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc) comp, [UINTPTR](Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc) appData, [OutputInfo](OutputInfo.md) *outBuf)
```

 **Description:**

Reports that the output is complete. 

This callback is invoked in asynchronous mode.

**Parameters:**

<a name="table162573900165631"></a>
<table><thead align="left"><tr id="row1733558103165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2141960478165631"><a name="p2141960478165631"></a><a name="p2141960478165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1402007112165631"><a name="p1402007112165631"></a><a name="p1402007112165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row112974550165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">hComponent</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the handle of the codec component. </td>
</tr>
<tr id="row698167071165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pAppData</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates upper-layer data, which is generally an upper-layer instance passed when this callback is registered. </td>
</tr>
<tr id="row717310021165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pBuffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the output data that has been generated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

