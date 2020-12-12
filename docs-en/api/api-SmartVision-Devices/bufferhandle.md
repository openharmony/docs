# BufferHandle<a name="EN-US_TOPIC_0000001054918147"></a>

-   [Overview](#section1685523299165630)
-   [Summary](#section1513332779165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section617981076165630)
-   [Field](#section1936812515165630)
-   [handle](#a28ebaf90f9e4e04a8fa5bae04dbf8851)
-   [key](#a9bc55ed9347418af6092399549ee0ff2)
-   [phyAddr](#a0c8b61e872a3565f4e9e68ea8de6a669)
-   [shmid](#acef4311b898b393d4473cc77d9ba0c63)
-   [virAddr](#ad6dd19ba3f81e8a71607a62da61eee94)

## **Overview**<a name="section1685523299165630"></a>

**Related Modules:**

[Codec](codec.md)  |  [Display](display.md)

**Description:**

Defines the buffer handle type. The virtual address of a handle maps to its physical address. 

Defines the buffer handle, including the shared memory key, shared memory ID, and physical memory address.

## **Summary**<a name="section1513332779165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table42349857165630"></a>
<table><thead align="left"><tr id="row1808466573165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1941627823165630"><a name="p1941627823165630"></a><a name="p1941627823165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p116622222165630"><a name="p116622222165630"></a><a name="p116622222165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1962333689165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1227836977165630"><a name="p1227836977165630"></a><a name="p1227836977165630"></a><a href="bufferhandle.md#ad6dd19ba3f81e8a71607a62da61eee94">virAddr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p987103683165630"><a name="p987103683165630"></a><a name="p987103683165630"></a>uint8_t * </p>
</td>
</tr>
<tr id="row575209816165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2100666660165630"><a name="p2100666660165630"></a><a name="p2100666660165630"></a><a href="bufferhandle.md#a28ebaf90f9e4e04a8fa5bae04dbf8851">handle</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p359509311165630"><a name="p359509311165630"></a><a name="p359509311165630"></a>uintptr_t </p>
</td>
</tr>
<tr id="row865458785165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p115608280165630"><a name="p115608280165630"></a><a name="p115608280165630"></a><a href="bufferhandle.md#a9bc55ed9347418af6092399549ee0ff2">key</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2094410991165630"><a name="p2094410991165630"></a><a name="p2094410991165630"></a>int32_t </p>
</td>
</tr>
<tr id="row1024631673165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p949553054165630"><a name="p949553054165630"></a><a name="p949553054165630"></a><a href="bufferhandle.md#acef4311b898b393d4473cc77d9ba0c63">shmid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p534773722165630"><a name="p534773722165630"></a><a name="p534773722165630"></a>int32_t </p>
</td>
</tr>
<tr id="row1011925416165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1722020089165630"><a name="p1722020089165630"></a><a name="p1722020089165630"></a><a href="bufferhandle.md#a0c8b61e872a3565f4e9e68ea8de6a669">phyAddr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p539313867165630"><a name="p539313867165630"></a><a name="p539313867165630"></a>uint64_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section617981076165630"></a>

## **Field **<a name="section1936812515165630"></a>

## handle<a name="a28ebaf90f9e4e04a8fa5bae04dbf8851"></a>

```
uintptr_t BufferHandle::handle
```

 **Description:**

Physical address 

## key<a name="a9bc55ed9347418af6092399549ee0ff2"></a>

```
int32_t BufferHandle::key
```

 **Description:**

Shared memory key 

## phyAddr<a name="a0c8b61e872a3565f4e9e68ea8de6a669"></a>

```
uint64_t BufferHandle::phyAddr
```

 **Description:**

Physical address 

## shmid<a name="acef4311b898b393d4473cc77d9ba0c63"></a>

```
int32_t BufferHandle::shmid
```

 **Description:**

Unique ID of the shared memory 

## virAddr<a name="ad6dd19ba3f81e8a71607a62da61eee94"></a>

```
uint8_t* BufferHandle::virAddr
```

 **Description:**

Virtual address 

