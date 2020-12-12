# Subscriber<a name="ZH-CN_TOPIC_0000001055078177"></a>

-   [Overview](#section2024935250165636)
-   [Summary](#section1403630683165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section1104851508165636)
-   [Field](#section324310952165636)
-   [AddTopic](#afc91fc1255ae42cba3d037bbe27096fd)
-   [ModifyConsumer](#ab61beca9e502b1f6098ed49956a9ad51)
-   [Subscribe](#a963e7a8519c854662e8ba901d08838ee)
-   [Unsubscribe](#a37a99e64f59194d8f2191b91f566f0f4)

## **Overview**<a name="section2024935250165636"></a>

**Related Modules:**

[Broadcast](Broadcast.md)

**Description:**

Defines the subscriber for external interfaces to subscribe to events and data of a topic. 

## **Summary**<a name="section1403630683165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table170338880165636"></a>
<table><thead align="left"><tr id="row237079455165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1388507619165636"><a name="p1388507619165636"></a><a name="p1388507619165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p284806076165636"><a name="p284806076165636"></a><a name="p284806076165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row799687112165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p798125084165636"><a name="p798125084165636"></a><a name="p798125084165636"></a><a href="Subscriber.md#afc91fc1255ae42cba3d037bbe27096fd">AddTopic</a> )(<a href="IUnknown.md">IUnknown</a> *iUnknown, const <a href="Broadcast.md#gaf03f5bc94cad32ab628a6cdee09b0542">Topic</a> *topic)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1583258532165636"><a name="p1583258532165636"></a><a name="p1583258532165636"></a>int(* </p>
<p id="p201790664165636"><a name="p201790664165636"></a><a name="p201790664165636"></a>Adds a specified topic to the Broadcast service. </p>
</td>
</tr>
<tr id="row85876164165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1294393139165636"><a name="p1294393139165636"></a><a name="p1294393139165636"></a><a href="Subscriber.md#a963e7a8519c854662e8ba901d08838ee">Subscribe</a> )(<a href="IUnknown.md">IUnknown</a> *iUnknown, const <a href="Broadcast.md#gaf03f5bc94cad32ab628a6cdee09b0542">Topic</a> *topic, <a href="Consumer.md">Consumer</a> *consumer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p38634790165636"><a name="p38634790165636"></a><a name="p38634790165636"></a>int(* </p>
<p id="p1341760376165636"><a name="p1341760376165636"></a><a name="p1341760376165636"></a>Subscribes to a specified topic for consumers. </p>
</td>
</tr>
<tr id="row2024442562165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p368762500165636"><a name="p368762500165636"></a><a name="p368762500165636"></a><a href="Subscriber.md#ab61beca9e502b1f6098ed49956a9ad51">ModifyConsumer</a> )(<a href="IUnknown.md">IUnknown</a> *iUnknown, const <a href="Broadcast.md#gaf03f5bc94cad32ab628a6cdee09b0542">Topic</a> *topic, <a href="Consumer.md">Consumer</a> *old, <a href="Consumer.md">Consumer</a> *current)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p245506693165636"><a name="p245506693165636"></a><a name="p245506693165636"></a><a href="Consumer.md">Consumer</a> *(* </p>
<p id="p2053043524165636"><a name="p2053043524165636"></a><a name="p2053043524165636"></a>Modifies the consumer of a specified topic. </p>
</td>
</tr>
<tr id="row1654636690165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p811944811165636"><a name="p811944811165636"></a><a name="p811944811165636"></a><a href="Subscriber.md#a37a99e64f59194d8f2191b91f566f0f4">Unsubscribe</a> )(<a href="IUnknown.md">IUnknown</a> *iUnknown, const <a href="Broadcast.md#gaf03f5bc94cad32ab628a6cdee09b0542">Topic</a> *topic, const <a href="Consumer.md">Consumer</a> *consumer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1468251167165636"><a name="p1468251167165636"></a><a name="p1468251167165636"></a><a href="Consumer.md">Consumer</a> *(* </p>
<p id="p957904217165636"><a name="p957904217165636"></a><a name="p957904217165636"></a>Unsubscribes from a specified topic. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1104851508165636"></a>

## **Field **<a name="section324310952165636"></a>

## AddTopic<a name="afc91fc1255ae42cba3d037bbe27096fd"></a>

```
int(* Subscriber::AddTopic) ([IUnknown](IUnknown.md) *iUnknown, const [Topic](Broadcast.md#gaf03f5bc94cad32ab628a6cdee09b0542) *topic)
```

 **Description:**

Adds a specified topic to the Broadcast service. 

The specified topic is added by the subscriber. A topic can be subscribed to only after being added. 

**Parameters:**

<a name="table1862002472165636"></a>
<table><thead align="left"><tr id="row627357946165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p365465263165636"><a name="p365465263165636"></a><a name="p365465263165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p695275679165636"><a name="p695275679165636"></a><a name="p695275679165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1727634480165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iUnknown</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates external interface of the pub/sub feature. </td>
</tr>
<tr id="row323070388165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">topic</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the topic to be subscribed to. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **EC\_SUCCESS**  if the topic is successfully added; returns other error codes if the topic fails to be added. 

## ModifyConsumer<a name="ab61beca9e502b1f6098ed49956a9ad51"></a>

```
[Consumer](Consumer.md)*(* Subscriber::ModifyConsumer) ([IUnknown](IUnknown.md) *iUnknown, const [Topic](Broadcast.md#gaf03f5bc94cad32ab628a6cdee09b0542) *topic, [Consumer](Consumer.md) *old, [Consumer](Consumer.md) *current)
```

 **Description:**

Modifies the consumer of a specified topic. 

**Parameters:**

<a name="table1858424148165636"></a>
<table><thead align="left"><tr id="row596838323165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p231664530165636"><a name="p231664530165636"></a><a name="p231664530165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2051262344165636"><a name="p2051262344165636"></a><a name="p2051262344165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row309698415165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iUnknown</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the external interface of the pub/sub feature. </td>
</tr>
<tr id="row1934409471165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">topic</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the topic whose consumer will be modified. </td>
</tr>
<tr id="row1600468617165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">old</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the original consumer of the topic. </td>
</tr>
<tr id="row803464047165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">current</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the new consumer of the topic. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer of the original consumer if the modification is successful; returns  **NULL**  otherwise. 

## Subscribe<a name="a963e7a8519c854662e8ba901d08838ee"></a>

```
int(* Subscriber::Subscribe) ([IUnknown](IUnknown.md) *iUnknown, const [Topic](Broadcast.md#gaf03f5bc94cad32ab628a6cdee09b0542) *topic, [Consumer](Consumer.md) *consumer)
```

 **Description:**

Subscribes to a specified topic for consumers. 

Call this function on the subscriber. The topic to be subscribed to must have been added to the Broadcast service. 

**Parameters:**

<a name="table1550835247165636"></a>
<table><thead align="left"><tr id="row1742964238165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p764503081165636"><a name="p764503081165636"></a><a name="p764503081165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1674931571165636"><a name="p1674931571165636"></a><a name="p1674931571165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2140309071165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iUnknown</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates external interface of the pub/sub feature. </td>
</tr>
<tr id="row1819474715165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">topic</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the topic to be subscribed to. </td>
</tr>
<tr id="row1942199820165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">consumer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the consumer who subscribes to the topic. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **EC\_SUCCESS**  if the subscription is successful; returns other error codes if the subscription fails. 

## Unsubscribe<a name="a37a99e64f59194d8f2191b91f566f0f4"></a>

```
[Consumer](Consumer.md)*(* Subscriber::Unsubscribe) ([IUnknown](IUnknown.md) *iUnknown, const [Topic](Broadcast.md#gaf03f5bc94cad32ab628a6cdee09b0542) *topic, const [Consumer](Consumer.md) *consumer)
```

 **Description:**

Unsubscribes from a specified topic. 

This function cancels the subscription relationship between the specified topic and consumer. 

**Parameters:**

<a name="table277308068165636"></a>
<table><thead align="left"><tr id="row1979939816165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2073763428165636"><a name="p2073763428165636"></a><a name="p2073763428165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p159932464165636"><a name="p159932464165636"></a><a name="p159932464165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1209745913165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iUnknown</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates external interface of the pub/sub feature. This parameter is used to obtain subscription relationships. </td>
</tr>
<tr id="row1448812377165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">topic</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the topic to unsubscribe from. </td>
</tr>
<tr id="row362476215165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">consumer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the consumer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer of the consumer if the unsubscription is successful; returns  **NULL**  otherwise. 

