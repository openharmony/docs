# Utils\_config<a name="EN-US_TOPIC_0000001055678050"></a>

-   [Overview](#section283503600165625)
-   [Summary](#section606142748165625)
-   [Files](#files)
-   [Macros](#define-members)
-   [Details](#section1459959621165625)
-   [Macro Definition](#section1221236926165625)
-   [FEATURE\_KV\_CACHE](#gad3d71669516ef0bb50e2b105507a6b29)
-   [MAX\_CACHE\_SIZE](#ga6c8469dfe973ac952cf40394bd2c160b)
-   [MAX\_KV\_SUM](#ga4f258bd7d7d52c6770cce77f3e16ce72)

## **Overview**<a name="section283503600165625"></a>

**Description:**

Represents the configuration file of the utils subsystem. 

Vendors can set their desired items in the configuration file.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section606142748165625"></a>

## Files<a name="files"></a>

<a name="table769284303165625"></a>
<table><thead align="left"><tr id="row1240426824165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1202063122165625"><a name="p1202063122165625"></a><a name="p1202063122165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p778362253165625"><a name="p778362253165625"></a><a name="p778362253165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1466493833165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1750869396165625"><a name="p1750869396165625"></a><a name="p1750869396165625"></a><a href="utils_config-h.md">utils_config.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p465268705165625"><a name="p465268705165625"></a><a name="p465268705165625"></a>Represents the configuration file of the utils subsystem. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1445887054165625"></a>
<table><thead align="left"><tr id="row1593286064165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2031018992165625"><a name="p2031018992165625"></a><a name="p2031018992165625"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p837964968165625"><a name="p837964968165625"></a><a name="p837964968165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row502531266165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1748743693165625"><a name="p1748743693165625"></a><a name="p1748743693165625"></a><a href="utils_config.md#gad3d71669516ef0bb50e2b105507a6b29">FEATURE_KV_CACHE</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1379312202165625"><a name="p1379312202165625"></a><a name="p1379312202165625"></a>Specifies whether the KV store supports cache. </p>
</td>
</tr>
<tr id="row298487383165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1459237922165625"><a name="p1459237922165625"></a><a name="p1459237922165625"></a><a href="utils_config.md#ga6c8469dfe973ac952cf40394bd2c160b">MAX_CACHE_SIZE</a>   10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p68247525165625"><a name="p68247525165625"></a><a name="p68247525165625"></a>Indicates the number of data items that can be stored in the KV store cache. </p>
</td>
</tr>
<tr id="row1791635485165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1825089851165625"><a name="p1825089851165625"></a><a name="p1825089851165625"></a><a href="utils_config.md#ga4f258bd7d7d52c6770cce77f3e16ce72">MAX_KV_SUM</a>   50</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p350263247165625"><a name="p350263247165625"></a><a name="p350263247165625"></a>Indicates the number of data items that can be stored for each application. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1459959621165625"></a>

## **Macro Definition **<a name="section1221236926165625"></a>

## FEATURE\_KV\_CACHE<a name="gad3d71669516ef0bb50e2b105507a6b29"></a>

```
#define FEATURE_KV_CACHE
```

 **Description:**

Specifies whether the KV store supports cache. 

If this variable is defined, the KV store supports cache. Vendors determine whether to enable this feature. It is enabled by default. 

## MAX\_CACHE\_SIZE<a name="ga6c8469dfe973ac952cf40394bd2c160b"></a>

```
#define MAX_CACHE_SIZE   10
```

 **Description:**

Indicates the number of data items that can be stored in the KV store cache. 

Default value: 10 

## MAX\_KV\_SUM<a name="ga4f258bd7d7d52c6770cce77f3e16ce72"></a>

```
#define MAX_KV_SUM   50
```

 **Description:**

Indicates the number of data items that can be stored for each application. 

Default value: 50 

