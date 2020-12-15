# utime.h<a name="EN-US_TOPIC_0000001055228022"></a>

-   [Overview](#section645385307165629)
-   [Summary](#section841083568165629)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section645385307165629"></a>

**Related Modules:**

[FS](fs.md)

**Description:**

Provides the function and structure used for setting file access time and modification time. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section841083568165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table188924743165629"></a>
<table><thead align="left"><tr id="row548092375165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1489072132165629"><a name="p1489072132165629"></a><a name="p1489072132165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1779920793165629"><a name="p1779920793165629"></a><a name="p1779920793165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row666818481165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1678709564165629"><a name="p1678709564165629"></a><a name="p1678709564165629"></a><a href="utimbuf.md">utimbuf</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p938582761165629"><a name="p938582761165629"></a><a name="p938582761165629"></a>Defines the file access time and modification time. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1552520573165629"></a>
<table><thead align="left"><tr id="row1231151920165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1017967886165629"><a name="p1017967886165629"></a><a name="p1017967886165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1038210618165629"><a name="p1038210618165629"></a><a name="p1038210618165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1354735789165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2004285128165629"><a name="p2004285128165629"></a><a name="p2004285128165629"></a><a href="fs.md#ga1299674b4b1934ebf0441388d07981a6">utime</a> (const char *filename, const struct <a href="utimbuf.md">utimbuf</a> *times)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p623235214165629"><a name="p623235214165629"></a><a name="p623235214165629"></a>int </p>
<p id="p1765471444165629"><a name="p1765471444165629"></a><a name="p1765471444165629"></a>Sets the access time and modification time of a file. </p>
</td>
</tr>
</tbody>
</table>

