# shm\_info<a name="EN-US_TOPIC_0000001054479611"></a>

-   [Overview](#section2048856853165637)
-   [Summary](#section830881613165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section337996501165637)
-   [Field](#section1475747661165637)
-   [\_\_swap\_attempts](#a994182b446373fe20ba4392fac1608df)
-   [\_\_swap\_successes](#a612f7346d1f84cd756fa9ee4ba68cc14)
-   [\_\_used\_ids](#aa2de99231240b0e9e36cb1720bba0ef5)
-   [shm\_rss](#a677b785fd7c65a72a2a3e5c361ced94f)
-   [shm\_swp](#a55655441c2480741960372b4ae5aa76b)
-   [shm\_tot](#a68b58013a245638488a89c6026a757a5)

## **Overview**<a name="section2048856853165637"></a>

**Related Modules:**

[MEM](mem.md)

**Description:**

Describes system resource information about the shared memory. 

## **Summary**<a name="section830881613165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1225882133165637"></a>
<table><thead align="left"><tr id="row317986704165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p535491506165637"><a name="p535491506165637"></a><a name="p535491506165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p227901010165637"><a name="p227901010165637"></a><a name="p227901010165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row565543910165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p286330448165637"><a name="p286330448165637"></a><a name="p286330448165637"></a><a href="shm_info.md#aa2de99231240b0e9e36cb1720bba0ef5">__used_ids</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1889244379165637"><a name="p1889244379165637"></a><a name="p1889244379165637"></a>int </p>
</td>
</tr>
<tr id="row1157656028165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p187919386165637"><a name="p187919386165637"></a><a name="p187919386165637"></a><a href="shm_info.md#a68b58013a245638488a89c6026a757a5">shm_tot</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1228630817165637"><a name="p1228630817165637"></a><a name="p1228630817165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row1210063937165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1204307143165637"><a name="p1204307143165637"></a><a name="p1204307143165637"></a><a href="shm_info.md#a677b785fd7c65a72a2a3e5c361ced94f">shm_rss</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1966811484165637"><a name="p1966811484165637"></a><a name="p1966811484165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row1806877703165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p853885059165637"><a name="p853885059165637"></a><a name="p853885059165637"></a><a href="shm_info.md#a55655441c2480741960372b4ae5aa76b">shm_swp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2106433712165637"><a name="p2106433712165637"></a><a name="p2106433712165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row2068999080165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p777370739165637"><a name="p777370739165637"></a><a name="p777370739165637"></a><a href="shm_info.md#a994182b446373fe20ba4392fac1608df">__swap_attempts</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p521223542165637"><a name="p521223542165637"></a><a name="p521223542165637"></a>unsigned long </p>
</td>
</tr>
<tr id="row1310794010165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1630868607165637"><a name="p1630868607165637"></a><a name="p1630868607165637"></a><a href="shm_info.md#a612f7346d1f84cd756fa9ee4ba68cc14">__swap_successes</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p631919098165637"><a name="p631919098165637"></a><a name="p631919098165637"></a>unsigned long </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section337996501165637"></a>

## **Field **<a name="section1475747661165637"></a>

## \_\_swap\_attempts<a name="a994182b446373fe20ba4392fac1608df"></a>

```
unsigned long shm_info::__swap_attempts
```

 **Description:**

Number of swap attempts 

## \_\_swap\_successes<a name="a612f7346d1f84cd756fa9ee4ba68cc14"></a>

```
unsigned long shm_info::__swap_successes
```

 **Description:**

Number of successful swap attempts 

## \_\_used\_ids<a name="aa2de99231240b0e9e36cb1720bba0ef5"></a>

```
int shm_info::__used_ids
```

 **Description:**

Number of existing shared memory segments 

## shm\_rss<a name="a677b785fd7c65a72a2a3e5c361ced94f"></a>

```
unsigned long shm_info::shm_rss
```

 **Description:**

Number of resident shared memory pages 

## shm\_swp<a name="a55655441c2480741960372b4ae5aa76b"></a>

```
unsigned long shm_info::shm_swp
```

 **Description:**

Number of shared memory pages in the swap partition 

## shm\_tot<a name="a68b58013a245638488a89c6026a757a5"></a>

```
unsigned long shm_info::shm_tot
```

 **Description:**

Total number of shared memory pages 

