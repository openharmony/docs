# Broadcast<a name="EN-US_TOPIC_0000001055198082"></a>

-   [Overview](#section1713724700165625)
-   [Summary](#section1229551294165625)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Details](#section2073864747165625)
-   [Typedef](#section1755526484165625)
-   [Topic](#gaf03f5bc94cad32ab628a6cdee09b0542)
-   [Enumeration Type](#section520045311165625)
-   [BroadcastErrCode](#ga98f7a28020aa045ad049d116e1ca666d)

## **Overview**<a name="section1713724700165625"></a>

**Description:**

Provides data subscription and data push for services. 

With this module, the  [Service](service.md),  [Feature](feature.md), or other modules can broadcast events or data. All services that listen to these events or data can receive these broadcasts. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1229551294165625"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1848225549165625"></a>
<table><thead align="left"><tr id="row1831676263165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p156173697165625"><a name="p156173697165625"></a><a name="p156173697165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p102221301165625"><a name="p102221301165625"></a><a name="p102221301165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1617271714165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p48755426165625"><a name="p48755426165625"></a><a name="p48755426165625"></a><a href="consumer.md">Consumer</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p127338074165625"><a name="p127338074165625"></a><a name="p127338074165625"></a>Defines the topic consumer used to receive events and push data. You need to implement this struct for your application. </p>
</td>
</tr>
<tr id="row1779938451165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p992052160165625"><a name="p992052160165625"></a><a name="p992052160165625"></a><a href="provider.md">Provider</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1301283763165625"><a name="p1301283763165625"></a><a name="p1301283763165625"></a>Defines the provider of events and data of a topic. </p>
</td>
</tr>
<tr id="row1049364937165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1282325790165625"><a name="p1282325790165625"></a><a name="p1282325790165625"></a><a href="subscriber.md">Subscriber</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1484790362165625"><a name="p1484790362165625"></a><a name="p1484790362165625"></a>Defines the subscriber for external interfaces to subscribe to events and data of a topic. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1310695771165625"></a>
<table><thead align="left"><tr id="row1112633081165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1388407610165625"><a name="p1388407610165625"></a><a name="p1388407610165625"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1399921083165625"><a name="p1399921083165625"></a><a name="p1399921083165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1058503302165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1875492436165625"><a name="p1875492436165625"></a><a name="p1875492436165625"></a><a href="broadcast.md#gaf03f5bc94cad32ab628a6cdee09b0542">Topic</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1688232748165625"><a name="p1688232748165625"></a><a name="p1688232748165625"></a>typedef uint32 </p>
<p id="p1555548092165625"><a name="p1555548092165625"></a><a name="p1555548092165625"></a>Indicates the topic of an event or data, which is used to distinguish different types of events or data. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table692404702165625"></a>
<table><thead align="left"><tr id="row866369479165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1684594416165625"><a name="p1684594416165625"></a><a name="p1684594416165625"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1868975201165625"><a name="p1868975201165625"></a><a name="p1868975201165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2099483858165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p825236711165625"><a name="p825236711165625"></a><a name="p825236711165625"></a><a href="broadcast.md#ga98f7a28020aa045ad049d116e1ca666d">BroadcastErrCode</a> { <a href="broadcast.md#gga98f7a28020aa045ad049d116e1ca666da200821a903aa0ca4df7e25d2a0a3186b">EC_ALREADY_SUBSCRIBED</a> = EC_SUCCESS + 1 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p573074585165625"><a name="p573074585165625"></a><a name="p573074585165625"></a>Enumerates error codes unique to the Broadcast service. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2073864747165625"></a>

## **Typedef **<a name="section1755526484165625"></a>

## Topic<a name="gaf03f5bc94cad32ab628a6cdee09b0542"></a>

```
typedef uint32 [Topic](broadcast.md#gaf03f5bc94cad32ab628a6cdee09b0542)
```

 **Description:**

Indicates the topic of an event or data, which is used to distinguish different types of events or data. 

## **Enumeration Type **<a name="section520045311165625"></a>

## BroadcastErrCode<a name="ga98f7a28020aa045ad049d116e1ca666d"></a>

```
enum [BroadcastErrCode](broadcast.md#ga98f7a28020aa045ad049d116e1ca666d)
```

 **Description:**

Enumerates error codes unique to the Broadcast service. 

<a name="table611741774165625"></a>
<table><thead align="left"><tr id="row1556944128165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p109229145165625"><a name="p109229145165625"></a><a name="p109229145165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1050015299165625"><a name="p1050015299165625"></a><a name="p1050015299165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row308452260165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga98f7a28020aa045ad049d116e1ca666da200821a903aa0ca4df7e25d2a0a3186b"><a name="gga98f7a28020aa045ad049d116e1ca666da200821a903aa0ca4df7e25d2a0a3186b"></a><a name="gga98f7a28020aa045ad049d116e1ca666da200821a903aa0ca4df7e25d2a0a3186b"></a></strong>EC_ALREADY_SUBSCRIBED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p404530656165625"><a name="p404530656165625"></a><a name="p404530656165625"></a>Error code showing that a topic has been subscribed to </p>
 </td>
</tr>
</tbody>
</table>

