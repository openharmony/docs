# sigval<a name="EN-US_TOPIC_0000001054598209"></a>

-   [Overview](#section1196970877165637)
-   [Summary](#section1173402438165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section1769052517165637)
-   [Field](#section584151725165637)
-   [sival\_int](#a560393252ee7edc37df44bf1c11bdbdd)
-   [sival\_ptr](#a4668f1bd7463de7b70bd0022207e26ac)

## **Overview**<a name="section1196970877165637"></a>

**Related Modules:**

[IPC](ipc.md)

**Description:**

Describes signal values in different cases. 

## **Summary**<a name="section1173402438165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table2775849165637"></a>
<table><thead align="left"><tr id="row1034117422165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p803524270165637"><a name="p803524270165637"></a><a name="p803524270165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1901784877165637"><a name="p1901784877165637"></a><a name="p1901784877165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1000435119165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1945637309165637"><a name="p1945637309165637"></a><a name="p1945637309165637"></a><a href="sigval.md#a560393252ee7edc37df44bf1c11bdbdd">sival_int</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p403247149165637"><a name="p403247149165637"></a><a name="p403247149165637"></a>int </p>
</td>
</tr>
<tr id="row1313754894165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1229368248165637"><a name="p1229368248165637"></a><a name="p1229368248165637"></a><a href="sigval.md#a4668f1bd7463de7b70bd0022207e26ac">sival_ptr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p91247409165637"><a name="p91247409165637"></a><a name="p91247409165637"></a>void * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1769052517165637"></a>

## **Field **<a name="section584151725165637"></a>

## sival\_int<a name="a560393252ee7edc37df44bf1c11bdbdd"></a>

```
int sigval::sival_int
```

 **Description:**

Integer signal value 

## sival\_ptr<a name="a4668f1bd7463de7b70bd0022207e26ac"></a>

```
void* sigval::sival_ptr
```

 **Description:**

Pointer signal value 

