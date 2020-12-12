# Identity<a name="EN-US_TOPIC_0000001054918159"></a>

-   [Overview](#section1236276226165632)
-   [Summary](#section1686359004165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section852837605165632)
-   [Field](#section231810944165632)
-   [featureId](#a8a76b43d4bb4e3d861ff63e0716f178d)
-   [queueId](#ad34d38c75a24903672bb64f29c1b1132)
-   [serviceId](#a062375b8be3ad40e72263a7ce2268af3)

## **Overview**<a name="section1236276226165632"></a>

**Related Modules:**

[Samgr](samgr.md)

**Description:**

Identifies a service and feature. 

You can use this structure to identity a  [IUnknown](iunknown.md)  feature to which messages will be sent through the asynchronous function of  [IUnknown](iunknown.md). 

## **Summary**<a name="section1686359004165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1456054174165632"></a>
<table><thead align="left"><tr id="row1003750964165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p324473493165632"><a name="p324473493165632"></a><a name="p324473493165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1658744382165632"><a name="p1658744382165632"></a><a name="p1658744382165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row549603196165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1214858234165632"><a name="p1214858234165632"></a><a name="p1214858234165632"></a><a href="identity.md#a062375b8be3ad40e72263a7ce2268af3">serviceId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p504218854165632"><a name="p504218854165632"></a><a name="p504218854165632"></a>int16 </p>
</td>
</tr>
<tr id="row1982071147165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1396838012165632"><a name="p1396838012165632"></a><a name="p1396838012165632"></a><a href="identity.md#a8a76b43d4bb4e3d861ff63e0716f178d">featureId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1588216855165632"><a name="p1588216855165632"></a><a name="p1588216855165632"></a>int16 </p>
</td>
</tr>
<tr id="row1137778775165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p370654274165632"><a name="p370654274165632"></a><a name="p370654274165632"></a><a href="identity.md#ad34d38c75a24903672bb64f29c1b1132">queueId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p852866985165632"><a name="p852866985165632"></a><a name="p852866985165632"></a>MQueueId </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section852837605165632"></a>

## **Field **<a name="section231810944165632"></a>

## featureId<a name="a8a76b43d4bb4e3d861ff63e0716f178d"></a>

```
int16 Identity::featureId
```

 **Description:**

[Feature](feature.md)  ID 

## queueId<a name="ad34d38c75a24903672bb64f29c1b1132"></a>

```
MQueueId Identity::queueId
```

 **Description:**

Message queue ID 

## serviceId<a name="a062375b8be3ad40e72263a7ce2268af3"></a>

```
int16 Identity::serviceId
```

 **Description:**

[Service](service.md)  ID 

