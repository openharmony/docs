# InputReportEventCb<a name="ZH-CN_TOPIC_0000001055358110"></a>

-   [Overview](#section530819023165631)
-   [Summary](#section533892924165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1103444491165631)
-   [Field](#section1797037931165631)
-   [ReportEventCallback](#a458c9d1bae3f36937db2977fcc777136)

## **Overview**<a name="section530819023165631"></a>

**Related Modules:**

[Input](Input.md)

**Description:**

Describes the input event callback registered by the input service. 

## **Summary**<a name="section533892924165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table892710264165631"></a>
<table><thead align="left"><tr id="row783079434165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p52901943165631"><a name="p52901943165631"></a><a name="p52901943165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1686354950165631"><a name="p1686354950165631"></a><a name="p1686354950165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row830547159165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1750463617165631"><a name="p1750463617165631"></a><a name="p1750463617165631"></a><a href="InputReportEventCb.md#a458c9d1bae3f36937db2977fcc777136">ReportEventCallback</a> )(const <a href="InputEventData.md">InputEventData</a> *eventData, uint32_t count, uint32_t devIndex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p308874657165631"><a name="p308874657165631"></a><a name="p308874657165631"></a>void(* </p>
<p id="p868499198165631"><a name="p868499198165631"></a><a name="p868499198165631"></a>Reports input event data by the registered callback. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1103444491165631"></a>

## **Field **<a name="section1797037931165631"></a>

## ReportEventCallback<a name="a458c9d1bae3f36937db2977fcc777136"></a>

```
void(* InputReportEventCb::ReportEventCallback) (const [InputEventData](InputEventData.md) *eventData, uint32_t count, uint32_t devIndex)
```

 **Description:**

Reports input event data by the registered callback. 

**Parameters:**

<a name="table1098905804165631"></a>
<table><thead align="left"><tr id="row2098629022165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1106838111165631"><a name="p1106838111165631"></a><a name="p1106838111165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p351235312165631"><a name="p351235312165631"></a><a name="p351235312165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1295153732165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">eventData</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the input event data reported by the input driver. </td>
</tr>
<tr id="row498111617165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">count</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of input event data packets. </td>
</tr>
<tr id="row1977090500165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of an input device. A maximum of 32 input devices are supported. The value ranges from 0 to 31, and value <strong id="b150856320165631"><a name="b150856320165631"></a><a name="b150856320165631"></a>0</strong> represents the first input device.</td>
</tr>
</tbody>
</table>

