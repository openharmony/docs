# OsalThreadParam<a name="ZH-CN_TOPIC_0000001054479579"></a>

-   [Overview](#section807159970165633)
-   [Summary](#section1112501934165633)
-   [Data Fields](#pub-attribs)
-   [Details](#section180003492165633)
-   [Field](#section1762739165633)
-   [name](#a6bd1010a71ee937fa5fdbcbf11e733ab)
-   [priority](#a11ba2334842664dce682fef5cadfbf30)
-   [stackSize](#a658a540a5c27b8bbe7feb8f143364b18)

## **Overview**<a name="section807159970165633"></a>

**Related Modules:**

[OSAL](OSAL.md)

**Description:**

Describes thread parameters. 

## **Summary**<a name="section1112501934165633"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1456439790165633"></a>
<table><thead align="left"><tr id="row1843591701165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p153028912165633"><a name="p153028912165633"></a><a name="p153028912165633"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2015243986165633"><a name="p2015243986165633"></a><a name="p2015243986165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row817597709165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2144779915165633"><a name="p2144779915165633"></a><a name="p2144779915165633"></a><a href="OsalThreadParam.md#a6bd1010a71ee937fa5fdbcbf11e733ab">name</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p813757892165633"><a name="p813757892165633"></a><a name="p813757892165633"></a>char * </p>
</td>
</tr>
<tr id="row635466502165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p693997193165633"><a name="p693997193165633"></a><a name="p693997193165633"></a><a href="OsalThreadParam.md#a658a540a5c27b8bbe7feb8f143364b18">stackSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1671099025165633"><a name="p1671099025165633"></a><a name="p1671099025165633"></a>size_t </p>
</td>
</tr>
<tr id="row880065298165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p375847477165633"><a name="p375847477165633"></a><a name="p375847477165633"></a><a href="OsalThreadParam.md#a11ba2334842664dce682fef5cadfbf30">priority</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1631567140165633"><a name="p1631567140165633"></a><a name="p1631567140165633"></a><a href="OSAL.md#gab8c099a9c39fdde73c74b3f7367be5d0">OSAL_THREAD_PRIORITY</a> </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section180003492165633"></a>

## **Field **<a name="section1762739165633"></a>

## name<a name="a6bd1010a71ee937fa5fdbcbf11e733ab"></a>

```
char* OsalThreadParam::name
```

 **Description:**

Thread name 

## priority<a name="a11ba2334842664dce682fef5cadfbf30"></a>

```
[OSAL_THREAD_PRIORITY](OSAL.md#gab8c099a9c39fdde73c74b3f7367be5d0) OsalThreadParam::priority
```

 **Description:**

Thread priority 

## stackSize<a name="a658a540a5c27b8bbe7feb8f143364b18"></a>

```
size_t OsalThreadParam::stackSize
```

 **Description:**

Stack size of a thread 

