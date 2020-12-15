# BundleStatusCallback<a name="EN-US_TOPIC_0000001058067356"></a>

-   [Overview](#section1138901815165630)
-   [Summary](#section1984981971165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section335321196165630)
-   [Field](#section91076479165630)
-   [bundleName](#ad92bee444c17e378809065e23d6d796a)
-   [callBack](#a5e6bccc1fb386a428ae77271e5b21354)
-   [data](#ae6bd742d12d3c9034471299d69ba374a)

## **Overview**<a name="section1138901815165630"></a>

**Related Modules:**

[BundleManager](bundlemanager.md)

**Description:**

Defines the application state callback information. 

## **Summary**<a name="section1984981971165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1682735928165630"></a>
<table><thead align="left"><tr id="row1661304284165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2104728106165630"><a name="p2104728106165630"></a><a name="p2104728106165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p167942876165630"><a name="p167942876165630"></a><a name="p167942876165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row942616751165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1121670335165630"><a name="p1121670335165630"></a><a name="p1121670335165630"></a><a href="bundlestatuscallback.md#ad92bee444c17e378809065e23d6d796a">bundleName</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p28254094165630"><a name="p28254094165630"></a><a name="p28254094165630"></a>char * </p>
</td>
</tr>
<tr id="row522153542165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p836635152165630"><a name="p836635152165630"></a><a name="p836635152165630"></a><a href="bundlestatuscallback.md#ae6bd742d12d3c9034471299d69ba374a">data</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p418931144165630"><a name="p418931144165630"></a><a name="p418931144165630"></a>void * </p>
</td>
</tr>
<tr id="row898667514165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p211505773165630"><a name="p211505773165630"></a><a name="p211505773165630"></a><a href="bundlestatuscallback.md#a5e6bccc1fb386a428ae77271e5b21354">callBack</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2002637700165630"><a name="p2002637700165630"></a><a name="p2002637700165630"></a><a href="bundlemanager.md#gad7ea6d0bf78db2d59e6d339c31819885">BundleStateCallback</a> </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section335321196165630"></a>

## **Field **<a name="section91076479165630"></a>

## bundleName<a name="ad92bee444c17e378809065e23d6d796a"></a>

```
char* BundleStatusCallback::bundleName
```

 **Description:**

Pointer to the bundle name of the application that the callback listens to. If this parameter is set to  **nullptr**, the callback listens to all applications in the system. 

## callBack<a name="a5e6bccc1fb386a428ae77271e5b21354"></a>

```
[BundleStateCallback](bundlemanager.md#gad7ea6d0bf78db2d59e6d339c31819885) BundleStatusCallback::callBack
```

 **Description:**

Callback to be invoked upon application state changes. 

## data<a name="ae6bd742d12d3c9034471299d69ba374a"></a>

```
void* BundleStatusCallback::data
```

 **Description:**

Pointer to the registered data that will be used by  [BundleStateCallback](bundlemanager.md#gad7ea6d0bf78db2d59e6d339c31819885). 

