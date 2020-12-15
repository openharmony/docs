# sigaltstack<a name="EN-US_TOPIC_0000001055358156"></a>

-   [Overview](#section1699142902165637)
-   [Summary](#section1360507147165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section1075425471165637)
-   [Field](#section2052765666165637)
-   [ss\_flags](#a173db1abf4231d1850b2595a01ebc9e2)
-   [ss\_size](#a0a5016360b089485d55a5ad785f5bddc)
-   [ss\_sp](#a378427adf55664600553c3388b894d41)

## **Overview**<a name="section1699142902165637"></a>

**Related Modules:**

[IPC](ipc.md)

**Description:**

Describes a signal stack. 

## **Summary**<a name="section1360507147165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table2088720108165637"></a>
<table><thead align="left"><tr id="row1121749096165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p245570478165637"><a name="p245570478165637"></a><a name="p245570478165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p31716264165637"><a name="p31716264165637"></a><a name="p31716264165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2078630962165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p771030490165637"><a name="p771030490165637"></a><a name="p771030490165637"></a><a href="sigaltstack.md#a378427adf55664600553c3388b894d41">ss_sp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1704992434165637"><a name="p1704992434165637"></a><a name="p1704992434165637"></a>void * </p>
</td>
</tr>
<tr id="row338966528165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p536827756165637"><a name="p536827756165637"></a><a name="p536827756165637"></a><a href="sigaltstack.md#a173db1abf4231d1850b2595a01ebc9e2">ss_flags</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1740110330165637"><a name="p1740110330165637"></a><a name="p1740110330165637"></a>int </p>
</td>
</tr>
<tr id="row1545462420165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p843773560165637"><a name="p843773560165637"></a><a name="p843773560165637"></a><a href="sigaltstack.md#a0a5016360b089485d55a5ad785f5bddc">ss_size</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p559187912165637"><a name="p559187912165637"></a><a name="p559187912165637"></a>size_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1075425471165637"></a>

## **Field **<a name="section2052765666165637"></a>

## ss\_flags<a name="a173db1abf4231d1850b2595a01ebc9e2"></a>

```
int sigaltstack::ss_flags
```

 **Description:**

Flag 

## ss\_size<a name="a0a5016360b089485d55a5ad785f5bddc"></a>

```
size_t sigaltstack::ss_size
```

 **Description:**

Number of bytes in the signal stack 

## ss\_sp<a name="a378427adf55664600553c3388b894d41"></a>

```
void* sigaltstack::ss_sp
```

 **Description:**

Base address of the signal stack 

