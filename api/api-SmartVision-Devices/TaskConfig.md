# TaskConfig<a name="ZH-CN_TOPIC_0000001055198170"></a>

-   [Overview](#section782171903165636)
-   [Summary](#section664677408165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section1671497423165636)
-   [Field](#section1084727059165636)
-   [level](#a9578c14c10691d7f1cbd8c34210630e7)
-   [priority](#abbfc4d996107bc34e0443e1a32d46b6d)
-   [queueSize](#ae8fd2e3f9bc0937c09e07944cc9a5d30)
-   [stackSize](#a4a4fb5ce45d9ea90f42faa6573a03a61)
-   [taskFlags](#afab151dbf2f1b02ec14e3e7f83207396)

## **Overview**<a name="section782171903165636"></a>

**Related Modules:**

[Samgr](Samgr.md)

**Description:**

Defines task configurations for a service. 

This structure defines task configurations for a service, including the task priority, stack size, queue size, task type, and shared task ID. 

## **Summary**<a name="section664677408165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table79778169165636"></a>
<table><thead align="left"><tr id="row1440325126165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1885288373165636"><a name="p1885288373165636"></a><a name="p1885288373165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p830931853165636"><a name="p830931853165636"></a><a name="p830931853165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row621737925165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2012212806165636"><a name="p2012212806165636"></a><a name="p2012212806165636"></a><a href="TaskConfig.md#a9578c14c10691d7f1cbd8c34210630e7">level</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p953882497165636"><a name="p953882497165636"></a><a name="p953882497165636"></a>int16 </p>
</td>
</tr>
<tr id="row2041478384165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1530233071165636"><a name="p1530233071165636"></a><a name="p1530233071165636"></a><a href="TaskConfig.md#abbfc4d996107bc34e0443e1a32d46b6d">priority</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p263247111165636"><a name="p263247111165636"></a><a name="p263247111165636"></a>int16 </p>
</td>
</tr>
<tr id="row412251447165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1093013303165636"><a name="p1093013303165636"></a><a name="p1093013303165636"></a><a href="TaskConfig.md#a4a4fb5ce45d9ea90f42faa6573a03a61">stackSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p567601751165636"><a name="p567601751165636"></a><a name="p567601751165636"></a>uint16 </p>
</td>
</tr>
<tr id="row762569586165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p735007712165636"><a name="p735007712165636"></a><a name="p735007712165636"></a><a href="TaskConfig.md#ae8fd2e3f9bc0937c09e07944cc9a5d30">queueSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p628244922165636"><a name="p628244922165636"></a><a name="p628244922165636"></a>uint16 </p>
</td>
</tr>
<tr id="row1199923955165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p515175156165636"><a name="p515175156165636"></a><a name="p515175156165636"></a><a href="TaskConfig.md#afab151dbf2f1b02ec14e3e7f83207396">taskFlags</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2095062712165636"><a name="p2095062712165636"></a><a name="p2095062712165636"></a>uint8 </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1671497423165636"></a>

## **Field **<a name="section1084727059165636"></a>

## level<a name="a9578c14c10691d7f1cbd8c34210630e7"></a>

```
int16 TaskConfig::level
```

 **Description:**

ID of a multi-service sharing task. For details about the level definition, see  [SpecifyTag](Samgr.md#gae9c7eed07272a46851d61e646b6e86d5). 

## priority<a name="abbfc4d996107bc34e0443e1a32d46b6d"></a>

```
int16 TaskConfig::priority
```

 **Description:**

Task priority. For details about the definition of priority, see  [TaskPriority](Samgr.md#gaef69bbb3353ea484414c3bbaf8ec362b). 

## queueSize<a name="ae8fd2e3f9bc0937c09e07944cc9a5d30"></a>

```
uint16 TaskConfig::queueSize
```

 **Description:**

Size of a task queue 

## stackSize<a name="a4a4fb5ce45d9ea90f42faa6573a03a61"></a>

```
uint16 TaskConfig::stackSize
```

 **Description:**

Size of a task stack 

## taskFlags<a name="afab151dbf2f1b02ec14e3e7f83207396"></a>

```
uint8 TaskConfig::taskFlags
```

 **Description:**

Task type. For details about the taskFlags definition, see  [TaskType](Samgr.md#gab265648f2dbef93878ad8c383712b43a). 

