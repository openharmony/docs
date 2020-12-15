# Provider<a name="EN-US_TOPIC_0000001055678128"></a>

-   [Overview](#section94821796165635)
-   [Summary](#section1262804507165635)
-   [Data Fields](#pub-attribs)
-   [Details](#section344628975165635)
-   [Field](#section984770604165635)
-   [Publish](#afbce5ffb04137a55e45161a7ba8577b7)

## **Overview**<a name="section94821796165635"></a>

**Related Modules:**

[Broadcast](broadcast.md)

**Description:**

Defines the provider of events and data of a topic. 

## **Summary**<a name="section1262804507165635"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table51951714165635"></a>
<table><thead align="left"><tr id="row1869859129165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p352635347165635"><a name="p352635347165635"></a><a name="p352635347165635"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p587723558165635"><a name="p587723558165635"></a><a name="p587723558165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row948355439165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1140574994165635"><a name="p1140574994165635"></a><a name="p1140574994165635"></a><a href="provider.md#afbce5ffb04137a55e45161a7ba8577b7">Publish</a> )(<a href="iunknown.md">IUnknown</a> *iUnknown, const <a href="broadcast.md#gaf03f5bc94cad32ab628a6cdee09b0542">Topic</a> *topic, uint8 *data, int16 len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1011613075165635"><a name="p1011613075165635"></a><a name="p1011613075165635"></a>BOOL(* </p>
<p id="p370952178165635"><a name="p370952178165635"></a><a name="p370952178165635"></a>Publishes events and data of a specified topic. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section344628975165635"></a>

## **Field **<a name="section984770604165635"></a>

## Publish<a name="afbce5ffb04137a55e45161a7ba8577b7"></a>

```
BOOL(* Provider::Publish) ([IUnknown](iunknown.md) *iUnknown, const [Topic](broadcast.md#gaf03f5bc94cad32ab628a6cdee09b0542) *topic, uint8 *data, int16 len)
```

 **Description:**

Publishes events and data of a specified topic. 

The events or data is published by the publisher, sent to all consumers who have subscribed to the topic, and processed by the consumers. 

**Parameters:**

<a name="table1252428420165635"></a>
<table><thead align="left"><tr id="row88026213165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1225062952165635"><a name="p1225062952165635"></a><a name="p1225062952165635"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p922398289165635"><a name="p922398289165635"></a><a name="p922398289165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row652470881165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iUnknown</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates external interface of the pub/sub feature. </td>
</tr>
<tr id="row788731993165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">topic</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the topic to publish. </td>
</tr>
<tr id="row680943768165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to publish. </td>
</tr>
<tr id="row1743779538165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the data to be published. The length must be the same as the <strong id="b1891492777165635"><a name="b1891492777165635"></a><a name="b1891492777165635"></a>data</strong> length. The caller must ensure the validity of this parameter. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **TRUE**  if the topic is successfully published; returns  **FALSE**  otherwise. 

