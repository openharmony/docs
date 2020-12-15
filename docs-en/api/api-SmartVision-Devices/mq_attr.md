# mq\_attr<a name="EN-US_TOPIC_0000001054918201"></a>

-   [Overview](#section967744747165637)
-   [Summary](#section286386175165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section1376482333165637)
-   [Field](#section608672754165637)
-   [\_\_unused](#a65ed70c4a33bc709487bfa801ab21964)
-   [mq\_curmsgs](#a08cfd508cef817ba351c1af8d9af50f5)
-   [mq\_flags](#a19c05fa88c6d1126120d800647ddb0dd)
-   [mq\_maxmsg](#aa535e1fa6c07c1d189e720ba15f9af08)
-   [mq\_msgsize](#ae975d1d907081c1e53b079c981c32209)

## **Overview**<a name="section967744747165637"></a>

**Related Modules:**

[IPC](ipc.md)

**Description:**

Describes message queue attributes. 

## **Summary**<a name="section286386175165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table928126134165637"></a>
<table><thead align="left"><tr id="row1354297385165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p459309991165637"><a name="p459309991165637"></a><a name="p459309991165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p323611795165637"><a name="p323611795165637"></a><a name="p323611795165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1862446722165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1716127765165637"><a name="p1716127765165637"></a><a name="p1716127765165637"></a><a href="mq_attr.md#a19c05fa88c6d1126120d800647ddb0dd">mq_flags</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2078637193165637"><a name="p2078637193165637"></a><a name="p2078637193165637"></a>long </p>
</td>
</tr>
<tr id="row1739572262165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p886612895165637"><a name="p886612895165637"></a><a name="p886612895165637"></a><a href="mq_attr.md#aa535e1fa6c07c1d189e720ba15f9af08">mq_maxmsg</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p828357884165637"><a name="p828357884165637"></a><a name="p828357884165637"></a>long </p>
</td>
</tr>
<tr id="row332261193165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1310437883165637"><a name="p1310437883165637"></a><a name="p1310437883165637"></a><a href="mq_attr.md#ae975d1d907081c1e53b079c981c32209">mq_msgsize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p313227396165637"><a name="p313227396165637"></a><a name="p313227396165637"></a>long </p>
</td>
</tr>
<tr id="row885315962165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p411237028165637"><a name="p411237028165637"></a><a name="p411237028165637"></a><a href="mq_attr.md#a08cfd508cef817ba351c1af8d9af50f5">mq_curmsgs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p603331189165637"><a name="p603331189165637"></a><a name="p603331189165637"></a>long </p>
</td>
</tr>
<tr id="row1500225909165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p314533314165637"><a name="p314533314165637"></a><a name="p314533314165637"></a><a href="mq_attr.md#a65ed70c4a33bc709487bfa801ab21964">__unused</a> [4]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p783217248165637"><a name="p783217248165637"></a><a name="p783217248165637"></a>long </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1376482333165637"></a>

## **Field **<a name="section608672754165637"></a>

## \_\_unused<a name="a65ed70c4a33bc709487bfa801ab21964"></a>

```
long mq_attr::__unused[4]
```

 **Description:**

A reserved field 

## mq\_curmsgs<a name="a08cfd508cef817ba351c1af8d9af50f5"></a>

```
long mq_attr::mq_curmsgs
```

 **Description:**

Number of messages currently queued 

## mq\_flags<a name="a19c05fa88c6d1126120d800647ddb0dd"></a>

```
long mq_attr::mq_flags
```

 **Description:**

Message queue flags: 0 or  **O\_NONBLOCK** 

## mq\_maxmsg<a name="aa535e1fa6c07c1d189e720ba15f9af08"></a>

```
long mq_attr::mq_maxmsg
```

 **Description:**

Maximum number of messages on queue 

## mq\_msgsize<a name="ae975d1d907081c1e53b079c981c32209"></a>

```
long mq_attr::mq_msgsize
```

 **Description:**

Maximum length of a message 

