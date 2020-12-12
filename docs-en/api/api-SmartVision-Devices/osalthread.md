# OsalThread<a name="EN-US_TOPIC_0000001054879548"></a>

-   [Overview](#section499057880165633)
-   [Summary](#section1787618970165633)
-   [Data Fields](#pub-attribs)
-   [Details](#section1199761491165633)
-   [Field](#section187397808165633)
-   [realThread](#a610e38635cc4f16cd3b274ae9351818f)
-   [status](#ac7c4d7a09cb3a91c98dd04588a79d4d4)

## **Overview**<a name="section499057880165633"></a>

**Related Modules:**

[OSAL](osal.md)

**Description:**

Describes a thread. 

## **Summary**<a name="section1787618970165633"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table829018074165633"></a>
<table><thead align="left"><tr id="row1107477781165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1033588178165633"><a name="p1033588178165633"></a><a name="p1033588178165633"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p749590718165633"><a name="p749590718165633"></a><a name="p749590718165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1835792347165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p467926265165633"><a name="p467926265165633"></a><a name="p467926265165633"></a><a href="osalthread.md#ac7c4d7a09cb3a91c98dd04588a79d4d4">status</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p590388812165633"><a name="p590388812165633"></a><a name="p590388812165633"></a>int32_t </p>
</td>
</tr>
<tr id="row783982843165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p723417444165633"><a name="p723417444165633"></a><a name="p723417444165633"></a><a href="osalthread.md#a610e38635cc4f16cd3b274ae9351818f">realThread</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p182101684165633"><a name="p182101684165633"></a><a name="p182101684165633"></a>void * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1199761491165633"></a>

## **Field **<a name="section187397808165633"></a>

## realThread<a name="a610e38635cc4f16cd3b274ae9351818f"></a>

```
void* OsalThread::realThread
```

 **Description:**

Pointer to a created thread object 

## status<a name="ac7c4d7a09cb3a91c98dd04588a79d4d4"></a>

```
int32_t OsalThread::status
```

 **Description:**

Thread running status 

