# Consumer<a name="EN-US_TOPIC_0000001055078133"></a>

-   [Overview](#section232136428165631)
-   [Summary](#section430934111165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section304163631165631)
-   [Field](#section1026643206165631)
-   [Equal](#a38ab45549e981dc8c8c0a90883a6bac8)
-   [identity](#ac6e98b3361e6be922804e8c459fe303b)
-   [Notify](#a57b8ea7ff05c30832af06804a0526765)

## **Overview**<a name="section232136428165631"></a>

**Related Modules:**

[Broadcast](broadcast.md)

**Description:**

Defines the topic consumer used to receive events and push data. You need to implement this struct for your application. 

## **Summary**<a name="section430934111165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table771842471165631"></a>
<table><thead align="left"><tr id="row811376784165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1313789521165631"><a name="p1313789521165631"></a><a name="p1313789521165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1623831590165631"><a name="p1623831590165631"></a><a name="p1623831590165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1725223854165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2080209934165631"><a name="p2080209934165631"></a><a name="p2080209934165631"></a><a href="consumer.md#ac6e98b3361e6be922804e8c459fe303b">identity</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p775692238165631"><a name="p775692238165631"></a><a name="p775692238165631"></a>const <a href="identity.md">Identity</a> * </p>
</td>
</tr>
<tr id="row1161342717165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p245049565165631"><a name="p245049565165631"></a><a name="p245049565165631"></a><a href="consumer.md#a57b8ea7ff05c30832af06804a0526765">Notify</a> )(<a href="consumer.md">Consumer</a> *consumer, const <a href="broadcast.md#gaf03f5bc94cad32ab628a6cdee09b0542">Topic</a> *topic, const <a href="request.md">Request</a> *origin)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1497081705165631"><a name="p1497081705165631"></a><a name="p1497081705165631"></a>void(* </p>
<p id="p1011069323165631"><a name="p1011069323165631"></a><a name="p1011069323165631"></a>Defines how the consumer will process the events or data of a released topic. </p>
</td>
</tr>
<tr id="row690162539165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p257928500165631"><a name="p257928500165631"></a><a name="p257928500165631"></a><a href="consumer.md#a38ab45549e981dc8c8c0a90883a6bac8">Equal</a> )(const <a href="consumer.md">Consumer</a> *current, const <a href="consumer.md">Consumer</a> *other)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1812876356165631"><a name="p1812876356165631"></a><a name="p1812876356165631"></a>BOOL(* </p>
<p id="p1638459615165631"><a name="p1638459615165631"></a><a name="p1638459615165631"></a>Checks whether two consumers are equal. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section304163631165631"></a>

## **Field **<a name="section1026643206165631"></a>

## Equal<a name="a38ab45549e981dc8c8c0a90883a6bac8"></a>

```
BOOL(* Consumer::Equal) (const [Consumer](consumer.md) *current, const [Consumer](consumer.md) *other)
```

 **Description:**

Checks whether two consumers are equal. 

You need to implement this function to prevent repeated topic subscription. 

**Parameters:**

<a name="table413133702165631"></a>
<table><thead align="left"><tr id="row935843313165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1420411528165631"><a name="p1420411528165631"></a><a name="p1420411528165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2099372885165631"><a name="p2099372885165631"></a><a name="p2099372885165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1731164163165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">current</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the current consumer. </td>
</tr>
<tr id="row53667923165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">other</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the target consumer to compare. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **TRUE**  if the two consumers are equal; returns  **FALSE**  otherwise. 

## identity<a name="ac6e98b3361e6be922804e8c459fe303b"></a>

```
const [Identity](identity.md)* Consumer::identity
```

 **Description:**

[Consumer](consumer.md)  ID 

## Notify<a name="a57b8ea7ff05c30832af06804a0526765"></a>

```
void(* Consumer::Notify) ([Consumer](consumer.md) *consumer, const [Topic](broadcast.md#gaf03f5bc94cad32ab628a6cdee09b0542) *topic, const [Request](request.md) *origin)
```

 **Description:**

Defines how the consumer will process the events or data of a released topic. 

You can implement this function for consumers to process topics associated with the them. Note that the passed topic must have been subscribed by the consumer. Otherwise, the function does nothing. 

**Parameters:**

<a name="table1180735570165631"></a>
<table><thead align="left"><tr id="row1920208490165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p574769601165631"><a name="p574769601165631"></a><a name="p574769601165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1066652007165631"><a name="p1066652007165631"></a><a name="p1066652007165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2006218039165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">consumer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates <strong id="b2137454649165631"><a name="b2137454649165631"></a><a name="b2137454649165631"></a>this</strong> pointer of the consumer. </td>
</tr>
<tr id="row190964430165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">topic</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the topic to be processed. </td>
</tr>
<tr id="row309971703165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">origin</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to be processed. </td>
</tr>
</tbody>
</table>

