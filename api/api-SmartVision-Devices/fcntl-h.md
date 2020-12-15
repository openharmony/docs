# fcntl.h<a name="ZH-CN_TOPIC_0000001054909428"></a>

-   [Overview](#section837157889165627)
-   [Summary](#section128064695165627)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section837157889165627"></a>

**Related Modules:**

[FS](FS.md)

**Description:**

Declares structures and functions used for file and directory operations such as opening a file, creating a file, and allocating space. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section128064695165627"></a>

## Macros<a name="define-members"></a>

<a name="table1642017277165627"></a>
<table><thead align="left"><tr id="row985040873165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1021800003165627"><a name="p1021800003165627"></a><a name="p1021800003165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1570049122165627"><a name="p1570049122165627"></a><a name="p1570049122165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1848071926165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2128694785165627"><a name="p2128694785165627"></a><a name="p2128694785165627"></a><a href="FS.md#ga4dc4d45e07d2abc899bcaf04b2846a87">O_ACCMODE</a>   (03|O_SEARCH)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p979162459165627"><a name="p979162459165627"></a><a name="p979162459165627"></a>Access mode. </p>
</td>
</tr>
<tr id="row62912606165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p222543198165627"><a name="p222543198165627"></a><a name="p222543198165627"></a><a href="FS.md#ga7a68c9ffaac7dbcd652225dd7c06a54b">O_RDONLY</a>   00</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p785046952165627"><a name="p785046952165627"></a><a name="p785046952165627"></a>Read-only. </p>
</td>
</tr>
<tr id="row711042301165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p27398784165627"><a name="p27398784165627"></a><a name="p27398784165627"></a><a href="FS.md#ga11b644a8526139c4cc1850dac1271ced">O_WRONLY</a>   01</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1678537147165627"><a name="p1678537147165627"></a><a name="p1678537147165627"></a>Write-only. </p>
</td>
</tr>
<tr id="row1501715720165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1412359426165627"><a name="p1412359426165627"></a><a name="p1412359426165627"></a><a href="FS.md#gabb0586253488ee61072b73557eeb873b">O_RDWR</a>   02</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p602411085165627"><a name="p602411085165627"></a><a name="p602411085165627"></a>Read and write. </p>
</td>
</tr>
<tr id="row24747464165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1209136468165627"><a name="p1209136468165627"></a><a name="p1209136468165627"></a><a href="FS.md#ga3bc050c90515f35b4cd6cea24760110c">fallocate64</a>   <a href="FS.md#ga26ba05fc43886db02fe169b35e04bfdf">fallocate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p80654368165627"><a name="p80654368165627"></a><a name="p80654368165627"></a>Pre-allocates space to a file. See <a href="FS.md#ga26ba05fc43886db02fe169b35e04bfdf">fallocate</a>. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1751951586165627"></a>
<table><thead align="left"><tr id="row92830113165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p852121934165627"><a name="p852121934165627"></a><a name="p852121934165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p108461136165627"><a name="p108461136165627"></a><a name="p108461136165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row958704487165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1483239819165627"><a name="p1483239819165627"></a><a name="p1483239819165627"></a><a href="FS.md#gafddc24a65767ae35f275be8ccf53e036">creat</a> (const char *path, mode_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1471521802165627"><a name="p1471521802165627"></a><a name="p1471521802165627"></a>int </p>
<p id="p1430517705165627"><a name="p1430517705165627"></a><a name="p1430517705165627"></a>Creates a file or rewrites an existing file. </p>
</td>
</tr>
<tr id="row594002950165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p189396269165627"><a name="p189396269165627"></a><a name="p189396269165627"></a><a href="FS.md#ga219205a58e244a5acd35b767ac50ef9c">open</a> (const char *path, int oflags,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p853856034165627"><a name="p853856034165627"></a><a name="p853856034165627"></a>int </p>
<p id="p238293031165627"><a name="p238293031165627"></a><a name="p238293031165627"></a>Opens a file. </p>
</td>
</tr>
<tr id="row1097301044165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p708206651165627"><a name="p708206651165627"></a><a name="p708206651165627"></a><a href="FS.md#ga26ba05fc43886db02fe169b35e04bfdf">fallocate</a> (int fd, int mode, off_t offset, off_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1969924881165627"><a name="p1969924881165627"></a><a name="p1969924881165627"></a>int </p>
<p id="p1202322436165627"><a name="p1202322436165627"></a><a name="p1202322436165627"></a>Pre-allocates space to a file. </p>
</td>
</tr>
<tr id="row1395223816165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p485502758165627"><a name="p485502758165627"></a><a name="p485502758165627"></a><a href="FS.md#gad39ebe4c4767eaa9a680777400cfaafe">fcntl</a> (int fd, int cmd,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p341901906165627"><a name="p341901906165627"></a><a name="p341901906165627"></a>int </p>
<p id="p1370701597165627"><a name="p1370701597165627"></a><a name="p1370701597165627"></a>Manipulates a specified file descriptor. </p>
</td>
</tr>
</tbody>
</table>

