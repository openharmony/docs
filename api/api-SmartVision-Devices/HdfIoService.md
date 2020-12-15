# HdfIoService<a name="ZH-CN_TOPIC_0000001054598161"></a>

-   [Overview](#section1204021025165631)
-   [Summary](#section710048610165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1793033829165631)
-   [Field](#section1999984985165631)
-   [dispatcher](#a3da28f5ff9b7805e136081bb65952761)
-   [object](#a6ad278c554dab0fa5b2269e3cae22cab)
-   [target](#a4b30a5c89ee7213eb1f74898e2ad605c)

## **Overview**<a name="section1204021025165631"></a>

**Related Modules:**

[Core](Core.md)

**Description:**

Defines a driver service object. 

**Since:**

1.0

## **Summary**<a name="section710048610165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1563384665165631"></a>
<table><thead align="left"><tr id="row2018697747165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p739598395165631"><a name="p739598395165631"></a><a name="p739598395165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p849131397165631"><a name="p849131397165631"></a><a name="p849131397165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row859079023165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p694940779165631"><a name="p694940779165631"></a><a name="p694940779165631"></a><a href="HdfIoService.md#a6ad278c554dab0fa5b2269e3cae22cab">object</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1432958749165631"><a name="p1432958749165631"></a><a name="p1432958749165631"></a>struct <a href="HdfObject.md">HdfObject</a> </p>
</td>
</tr>
<tr id="row1827601042165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1819673232165631"><a name="p1819673232165631"></a><a name="p1819673232165631"></a><a href="HdfIoService.md#a4b30a5c89ee7213eb1f74898e2ad605c">target</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p501939495165631"><a name="p501939495165631"></a><a name="p501939495165631"></a>struct <a href="HdfObject.md">HdfObject</a> * </p>
</td>
</tr>
<tr id="row870689594165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1056048576165631"><a name="p1056048576165631"></a><a name="p1056048576165631"></a><a href="HdfIoService.md#a3da28f5ff9b7805e136081bb65952761">dispatcher</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1400440976165631"><a name="p1400440976165631"></a><a name="p1400440976165631"></a>struct <a href="HdfIoDispatcher.md">HdfIoDispatcher</a> * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1793033829165631"></a>

## **Field **<a name="section1999984985165631"></a>

## dispatcher<a name="a3da28f5ff9b7805e136081bb65952761"></a>

```
struct [HdfIoDispatcher](HdfIoDispatcher.md)* HdfIoService::dispatcher
```

 **Description:**

[Service](Service.md)  call dispatcher 

## object<a name="a6ad278c554dab0fa5b2269e3cae22cab"></a>

```
struct [HdfObject](HdfObject.md) HdfIoService::object
```

 **Description:**

Base class object 

## target<a name="a4b30a5c89ee7213eb1f74898e2ad605c"></a>

```
struct [HdfObject](HdfObject.md)* HdfIoService::target
```

 **Description:**

Pointer to the bound service entity, which is used for framework management. You can ignore it. 

