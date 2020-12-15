# InputEventData<a name="ZH-CN_TOPIC_0000001055198132"></a>

-   [Overview](#section1681739667165631)
-   [Summary](#section1695957968165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section2138103727165631)
-   [Field](#section426995162165631)
-   [definedEvent](#af96272ca27f818ad8dcb58475363101d)
-   [fingerID](#ad40fe0acac67d262635f5eb1e6e69a2b)
-   [moreDataFlag](#a658814930c4b4cccfe9a434322149704)
-   [pointNum](#ab84237936381c935eb96634fd5c05918)
-   [pressure](#a8cf135e67e3f5650bfb66365d8379f79)
-   [timeStamp](#a0f5849a6cd26dfa2a9e9584f5e97cfdb)
-   [x](#affbfe056ed2c7ea85a512b144a4d64ba)
-   [y](#a8f1d6c23976289c3ba86c449b2ba86df)

## **Overview**<a name="section1681739667165631"></a>

**Related Modules:**

[Input](Input.md)

**Description:**

Describes the input event data. 

## **Summary**<a name="section1695957968165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table201550170165631"></a>
<table><thead align="left"><tr id="row1146938122165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p449509765165631"><a name="p449509765165631"></a><a name="p449509765165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1249180356165631"><a name="p1249180356165631"></a><a name="p1249180356165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row463402694165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p146202235165631"><a name="p146202235165631"></a><a name="p146202235165631"></a><a href="InputEventData.md#affbfe056ed2c7ea85a512b144a4d64ba">x</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p292223417165631"><a name="p292223417165631"></a><a name="p292223417165631"></a>int32_t </p>
</td>
</tr>
<tr id="row1512872433165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1049066649165631"><a name="p1049066649165631"></a><a name="p1049066649165631"></a><a href="InputEventData.md#a8f1d6c23976289c3ba86c449b2ba86df">y</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1088099682165631"><a name="p1088099682165631"></a><a name="p1088099682165631"></a>int32_t </p>
</td>
</tr>
<tr id="row301267069165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p576550912165631"><a name="p576550912165631"></a><a name="p576550912165631"></a><a href="InputEventData.md#a8cf135e67e3f5650bfb66365d8379f79">pressure</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p195778850165631"><a name="p195778850165631"></a><a name="p195778850165631"></a>int32_t </p>
</td>
</tr>
<tr id="row877152883165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1511765501165631"><a name="p1511765501165631"></a><a name="p1511765501165631"></a><a href="InputEventData.md#af96272ca27f818ad8dcb58475363101d">definedEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p427933048165631"><a name="p427933048165631"></a><a name="p427933048165631"></a>int32_t </p>
</td>
</tr>
<tr id="row27147423165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p426153779165631"><a name="p426153779165631"></a><a name="p426153779165631"></a><a href="InputEventData.md#ad40fe0acac67d262635f5eb1e6e69a2b">fingerID</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1896713497165631"><a name="p1896713497165631"></a><a name="p1896713497165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row1421203151165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1864445682165631"><a name="p1864445682165631"></a><a name="p1864445682165631"></a><a href="InputEventData.md#ab84237936381c935eb96634fd5c05918">pointNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1494365344165631"><a name="p1494365344165631"></a><a name="p1494365344165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row1850268620165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p266615921165631"><a name="p266615921165631"></a><a name="p266615921165631"></a><a href="InputEventData.md#a0f5849a6cd26dfa2a9e9584f5e97cfdb">timeStamp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1076750235165631"><a name="p1076750235165631"></a><a name="p1076750235165631"></a>struct <a href="timeval.md">timeval</a> </p>
</td>
</tr>
<tr id="row1666132658165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p145789505165631"><a name="p145789505165631"></a><a name="p145789505165631"></a><a href="InputEventData.md#a658814930c4b4cccfe9a434322149704">moreDataFlag</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1612756477165631"><a name="p1612756477165631"></a><a name="p1612756477165631"></a>bool </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2138103727165631"></a>

## **Field **<a name="section426995162165631"></a>

## definedEvent<a name="af96272ca27f818ad8dcb58475363101d"></a>

```
int32_t InputEventData::definedEvent
```

 **Description:**

Specific input event, such as the pick-up or put-down event 

## fingerID<a name="ad40fe0acac67d262635f5eb1e6e69a2b"></a>

```
uint32_t InputEventData::fingerID
```

 **Description:**

Finger ID, used in multi-touch scenarios 

## moreDataFlag<a name="a658814930c4b4cccfe9a434322149704"></a>

```
bool InputEventData::moreDataFlag
```

 **Description:**

Flag of continuous data read 

## pointNum<a name="ab84237936381c935eb96634fd5c05918"></a>

```
uint32_t InputEventData::pointNum
```

 **Description:**

Total number of fingers touching the screen 

## pressure<a name="a8cf135e67e3f5650bfb66365d8379f79"></a>

```
int32_t InputEventData::pressure
```

 **Description:**

Z coordinate of a touch point, such as the pressure 

## timeStamp<a name="a0f5849a6cd26dfa2a9e9584f5e97cfdb"></a>

```
struct [timeval](timeval.md) InputEventData::timeStamp
```

 **Description:**

Timestamp 

## x<a name="affbfe056ed2c7ea85a512b144a4d64ba"></a>

```
int32_t InputEventData::x
```

 **Description:**

X coordinate of a touch point 

## y<a name="a8f1d6c23976289c3ba86c449b2ba86df"></a>

```
int32_t InputEventData::y
```

 **Description:**

Y coordinate of a touch point 

