# Pms\_types<a name="EN-US_TOPIC_0000001055039472"></a>

-   [Overview](#section87665533165625)
-   [Summary](#section1423129036165625)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Enumerations](#enum-members)
-   [Details](#section1304863685165625)
-   [Macro Definition](#section1103827987165625)
-   [PERM\_DESC\_LEN](#gafb859b51e2b9552103cf1ba665e8eb7a)
-   [PERM\_NAME\_LEN](#ga1d7d82a3741ecedc4d993b523d95c0c8)
-   [Enumeration Type](#section488131239165625)
-   [IsGranted](#ga56644f429963f015addb12e36e2344f7)
-   [PmsErrorCode](#gacb79d7f5cd64c73479e0bdd9525265a8)
-   [Variable](#section149054169165625)
-   [desc](#gac30cf9ead0186519b49c3ecd58e39937)
-   [granted](#ga1b618be368f56d0d8c857aacc5b42baf)
-   [name](#gad57ecbb6ba51b1ab7f7b1533e5f8bbff)

## **Overview**<a name="section87665533165625"></a>

**Description:**

Defines variables and data structures used by the permission management module. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1423129036165625"></a>

## Files<a name="files"></a>

<a name="table489167442165625"></a>
<table><thead align="left"><tr id="row1475556846165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1617722541165625"><a name="p1617722541165625"></a><a name="p1617722541165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1898874562165625"><a name="p1898874562165625"></a><a name="p1898874562165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row754310177165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2075408749165625"><a name="p2075408749165625"></a><a name="p2075408749165625"></a><a href="pms_types-h.md">pms_types.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p759847087165625"><a name="p759847087165625"></a><a name="p759847087165625"></a>Declares variables and data structures used by the permission management module. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table65026429165625"></a>
<table><thead align="left"><tr id="row841150645165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1664806148165625"><a name="p1664806148165625"></a><a name="p1664806148165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1607547569165625"><a name="p1607547569165625"></a><a name="p1607547569165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1498720351165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1502837178165625"><a name="p1502837178165625"></a><a name="p1502837178165625"></a><a href="permissionsaved.md">PermissionSaved</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p83785271165625"><a name="p83785271165625"></a><a name="p83785271165625"></a>Defines the permission, including the name, description, and whether the permission is granted. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1626209229165625"></a>
<table><thead align="left"><tr id="row1038363727165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1354038882165625"><a name="p1354038882165625"></a><a name="p1354038882165625"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p939605092165625"><a name="p939605092165625"></a><a name="p939605092165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row97258096165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2004518408165625"><a name="p2004518408165625"></a><a name="p2004518408165625"></a><a href="pms_types.md#ga1d7d82a3741ecedc4d993b523d95c0c8">PERM_NAME_LEN</a>   64</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1346734119165625"><a name="p1346734119165625"></a><a name="p1346734119165625"></a>Indicates the length of a permission name. </p>
</td>
</tr>
<tr id="row297331487165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p900663854165625"><a name="p900663854165625"></a><a name="p900663854165625"></a><a href="pms_types.md#gafb859b51e2b9552103cf1ba665e8eb7a">PERM_DESC_LEN</a>   128</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1371604661165625"><a name="p1371604661165625"></a><a name="p1371604661165625"></a>Indicates the length of a permission description. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table783861988165625"></a>
<table><thead align="left"><tr id="row1988114911165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p382549727165625"><a name="p382549727165625"></a><a name="p382549727165625"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p205103258165625"><a name="p205103258165625"></a><a name="p205103258165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1213678207165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p271546066165625"><a name="p271546066165625"></a><a name="p271546066165625"></a><a href="pms_types.md#ga56644f429963f015addb12e36e2344f7">IsGranted</a> { <a href="pms_types.md#gga56644f429963f015addb12e36e2344f7a3d1fb18b35633f486c86113d8ed298b0">NOT_GRANTED</a> = 0, <a href="pms_types.md#gga56644f429963f015addb12e36e2344f7a440c8b08fdd77c2aa90283c06dbe465a">GRANTED</a> = 1 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1650686987165625"><a name="p1650686987165625"></a><a name="p1650686987165625"></a>Enumerates granting statuses of the permission. </p>
</td>
</tr>
<tr id="row439226580165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1691448380165625"><a name="p1691448380165625"></a><a name="p1691448380165625"></a><a href="pms_types.md#gacb79d7f5cd64c73479e0bdd9525265a8">PmsErrorCode</a> {   <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8a0c588903ef5651fc0305f212e093c492">PERM_ERRORCODE_SUCCESS</a> = 0, <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8ad3d70d0327fc60a9067f853bbe938fd4">PERM_ERRORCODE_INVALID_PARAMS</a> = 10, <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8ae6c8da1f46cf729021be0ee3ac28d506">PERM_ERRORCODE_INVALID_PERMNAME</a>, <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8a29ad932e0c9f71f287b0854635fbfdfc">PERM_ERRORCODE_MALLOC_FAIL</a>,   <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8a93548eedb6a47d5240f04d9e7066ae42">PERM_ERRORCODE_OPENFD_FAIL</a>, <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8ad5bbbd7a5c1964a8e32f8cd910d1e1b1">PERM_ERRORCODE_READFD_FAIL</a>, <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8ac9f97daf3819939bec448a74633d76dd">PERM_ERRORCODE_WRITEFD_FAIL</a>, <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8a93871916c514e5e08b5e71668e78c5f9">PERM_ERRORCODE_JSONPARSE_FAIL</a>,   <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8a21d2c3ca74a60578d909d7e3599d2329">PERM_ERRORCODE_COPY_ERROR</a>, <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8ab60b867e2cd8d6dad65fec5438bc9d8f">PERM_ERRORCODE_FIELD_TOO_LONG</a>, <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8ae50528fd433961afa3d384a296d7c1e1">PERM_ERRORCODE_PERM_NOT_EXIST</a>, <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8aee363de3178fe3be3d48c6b93a9ab0e2">PERM_ERRORCODE_UNLINK_ERROR</a>,   <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8a09f77eaf46086239b3e72abfe8629d6d">PERM_ERRORCODE_FILE_NOT_EXIST</a>, <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8a2041efbb9d8c5dd30df4894ee7cc7b1e">PERM_ERRORCODE_MEMSET_FAIL</a>, <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8a62c441a20ff74358ff3400a60d11d2a2">PERM_ERRORCODE_STAT_FAIL</a>, <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8ae652b4433e08622981c7457b4ead9dd8">PERM_ERRORCODE_PATH_INVALID</a>,   <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8a28397170788e73451c03bdacaf07bb09">PERM_ERRORCODE_TOO_MUCH_PERM</a>, <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8a20ce1cb092907845a84f138e45d06651">PERM_ERRORCODE_TASKID_NOT_EXIST</a>, <a href="pms_types.md#ggacb79d7f5cd64c73479e0bdd9525265a8a2e7d34ab9f33c396cac29e094277fef5">PERM_ERRORCODE_PERM_NUM_ERROR</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1892447483165625"><a name="p1892447483165625"></a><a name="p1892447483165625"></a>Enumerates error codes of the permission management module. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1304863685165625"></a>

## **Macro Definition **<a name="section1103827987165625"></a>

## PERM\_DESC\_LEN<a name="gafb859b51e2b9552103cf1ba665e8eb7a"></a>

```
#define PERM_DESC_LEN   128
```

 **Description:**

Indicates the length of a permission description. 

The default length is 128 bytes, including the terminating null byte  **'\\0'**. 

## PERM\_NAME\_LEN<a name="ga1d7d82a3741ecedc4d993b523d95c0c8"></a>

```
#define PERM_NAME_LEN   64
```

 **Description:**

Indicates the length of a permission name. 

The default length is 64 bytes, including the terminating null byte  **'\\0'**. 

## **Enumeration Type **<a name="section488131239165625"></a>

## IsGranted<a name="ga56644f429963f015addb12e36e2344f7"></a>

```
enum [IsGranted](pms_types.md#ga56644f429963f015addb12e36e2344f7)
```

 **Description:**

Enumerates granting statuses of the permission. 

<a name="table1024767802165625"></a>
<table><thead align="left"><tr id="row667102831165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1480913700165625"><a name="p1480913700165625"></a><a name="p1480913700165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1753028360165625"><a name="p1753028360165625"></a><a name="p1753028360165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1590783748165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga56644f429963f015addb12e36e2344f7a3d1fb18b35633f486c86113d8ed298b0"><a name="gga56644f429963f015addb12e36e2344f7a3d1fb18b35633f486c86113d8ed298b0"></a><a name="gga56644f429963f015addb12e36e2344f7a3d1fb18b35633f486c86113d8ed298b0"></a></strong>NOT_GRANTED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p114065181165625"><a name="p114065181165625"></a><a name="p114065181165625"></a>Not granted </p>
 </td>
</tr>
<tr id="row498722691165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga56644f429963f015addb12e36e2344f7a440c8b08fdd77c2aa90283c06dbe465a"><a name="gga56644f429963f015addb12e36e2344f7a440c8b08fdd77c2aa90283c06dbe465a"></a><a name="gga56644f429963f015addb12e36e2344f7a440c8b08fdd77c2aa90283c06dbe465a"></a></strong>GRANTED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1603444705165625"><a name="p1603444705165625"></a><a name="p1603444705165625"></a>Granted </p>
 </td>
</tr>
</tbody>
</table>

## PmsErrorCode<a name="gacb79d7f5cd64c73479e0bdd9525265a8"></a>

```
enum [PmsErrorCode](pms_types.md#gacb79d7f5cd64c73479e0bdd9525265a8)
```

 **Description:**

Enumerates error codes of the permission management module. 

<a name="table2015302894165625"></a>
<table><thead align="left"><tr id="row1472975453165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p677655672165625"><a name="p677655672165625"></a><a name="p677655672165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1483423492165625"><a name="p1483423492165625"></a><a name="p1483423492165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1535132546165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8a0c588903ef5651fc0305f212e093c492"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a0c588903ef5651fc0305f212e093c492"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a0c588903ef5651fc0305f212e093c492"></a></strong>PERM_ERRORCODE_SUCCESS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1120198018165625"><a name="p1120198018165625"></a><a name="p1120198018165625"></a>Success </p>
 </td>
</tr>
<tr id="row30492028165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8ad3d70d0327fc60a9067f853bbe938fd4"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8ad3d70d0327fc60a9067f853bbe938fd4"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8ad3d70d0327fc60a9067f853bbe938fd4"></a></strong>PERM_ERRORCODE_INVALID_PARAMS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p96492309165625"><a name="p96492309165625"></a><a name="p96492309165625"></a>Invalid parameters </p>
 </td>
</tr>
<tr id="row1701250768165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8ae6c8da1f46cf729021be0ee3ac28d506"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8ae6c8da1f46cf729021be0ee3ac28d506"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8ae6c8da1f46cf729021be0ee3ac28d506"></a></strong>PERM_ERRORCODE_INVALID_PERMNAME </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p27795360165625"><a name="p27795360165625"></a><a name="p27795360165625"></a>Invalid permission name </p>
 </td>
</tr>
<tr id="row560757044165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8a29ad932e0c9f71f287b0854635fbfdfc"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a29ad932e0c9f71f287b0854635fbfdfc"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a29ad932e0c9f71f287b0854635fbfdfc"></a></strong>PERM_ERRORCODE_MALLOC_FAIL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1268440172165625"><a name="p1268440172165625"></a><a name="p1268440172165625"></a>Failed to allocate memory using the <strong id="b1473431013165625"><a name="b1473431013165625"></a><a name="b1473431013165625"></a>malloc</strong> function. </p>
 </td>
</tr>
<tr id="row1507425177165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8a93548eedb6a47d5240f04d9e7066ae42"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a93548eedb6a47d5240f04d9e7066ae42"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a93548eedb6a47d5240f04d9e7066ae42"></a></strong>PERM_ERRORCODE_OPENFD_FAIL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2110188091165625"><a name="p2110188091165625"></a><a name="p2110188091165625"></a>Failed to open the file descriptor. </p>
 </td>
</tr>
<tr id="row1019839781165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8ad5bbbd7a5c1964a8e32f8cd910d1e1b1"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8ad5bbbd7a5c1964a8e32f8cd910d1e1b1"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8ad5bbbd7a5c1964a8e32f8cd910d1e1b1"></a></strong>PERM_ERRORCODE_READFD_FAIL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2000434239165625"><a name="p2000434239165625"></a><a name="p2000434239165625"></a>Failed to read the file descriptor. </p>
 </td>
</tr>
<tr id="row1863990628165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8ac9f97daf3819939bec448a74633d76dd"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8ac9f97daf3819939bec448a74633d76dd"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8ac9f97daf3819939bec448a74633d76dd"></a></strong>PERM_ERRORCODE_WRITEFD_FAIL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p814447258165625"><a name="p814447258165625"></a><a name="p814447258165625"></a>Failed to write the file descriptor. </p>
 </td>
</tr>
<tr id="row1530296721165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8a93871916c514e5e08b5e71668e78c5f9"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a93871916c514e5e08b5e71668e78c5f9"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a93871916c514e5e08b5e71668e78c5f9"></a></strong>PERM_ERRORCODE_JSONPARSE_FAIL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1957542620165625"><a name="p1957542620165625"></a><a name="p1957542620165625"></a>Failed to parse the JSON string. </p>
 </td>
</tr>
<tr id="row1169196628165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8a21d2c3ca74a60578d909d7e3599d2329"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a21d2c3ca74a60578d909d7e3599d2329"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a21d2c3ca74a60578d909d7e3599d2329"></a></strong>PERM_ERRORCODE_COPY_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p392251768165625"><a name="p392251768165625"></a><a name="p392251768165625"></a>Failed to copy the string. </p>
 </td>
</tr>
<tr id="row1838700958165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8ab60b867e2cd8d6dad65fec5438bc9d8f"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8ab60b867e2cd8d6dad65fec5438bc9d8f"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8ab60b867e2cd8d6dad65fec5438bc9d8f"></a></strong>PERM_ERRORCODE_FIELD_TOO_LONG </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1402417961165625"><a name="p1402417961165625"></a><a name="p1402417961165625"></a>The permission name or description is too long. </p>
 </td>
</tr>
<tr id="row1449847442165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8ae50528fd433961afa3d384a296d7c1e1"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8ae50528fd433961afa3d384a296d7c1e1"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8ae50528fd433961afa3d384a296d7c1e1"></a></strong>PERM_ERRORCODE_PERM_NOT_EXIST </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1613179508165625"><a name="p1613179508165625"></a><a name="p1613179508165625"></a>The permission does not exist. </p>
 </td>
</tr>
<tr id="row979108399165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8aee363de3178fe3be3d48c6b93a9ab0e2"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8aee363de3178fe3be3d48c6b93a9ab0e2"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8aee363de3178fe3be3d48c6b93a9ab0e2"></a></strong>PERM_ERRORCODE_UNLINK_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1821530716165625"><a name="p1821530716165625"></a><a name="p1821530716165625"></a>Failed to delete the permission file. </p>
 </td>
</tr>
<tr id="row1577756181165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8a09f77eaf46086239b3e72abfe8629d6d"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a09f77eaf46086239b3e72abfe8629d6d"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a09f77eaf46086239b3e72abfe8629d6d"></a></strong>PERM_ERRORCODE_FILE_NOT_EXIST </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p656245967165625"><a name="p656245967165625"></a><a name="p656245967165625"></a>The file does not exist. </p>
 </td>
</tr>
<tr id="row1310691498165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8a2041efbb9d8c5dd30df4894ee7cc7b1e"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a2041efbb9d8c5dd30df4894ee7cc7b1e"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a2041efbb9d8c5dd30df4894ee7cc7b1e"></a></strong>PERM_ERRORCODE_MEMSET_FAIL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p939911677165625"><a name="p939911677165625"></a><a name="p939911677165625"></a>Failed to set memory using the <strong id="b2066640588165625"><a name="b2066640588165625"></a><a name="b2066640588165625"></a>memset</strong> function. </p>
 </td>
</tr>
<tr id="row587559199165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8a62c441a20ff74358ff3400a60d11d2a2"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a62c441a20ff74358ff3400a60d11d2a2"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a62c441a20ff74358ff3400a60d11d2a2"></a></strong>PERM_ERRORCODE_STAT_FAIL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p970219139165625"><a name="p970219139165625"></a><a name="p970219139165625"></a>Failed to obtain information about the named file using the <strong id="b697160849165625"><a name="b697160849165625"></a><a name="b697160849165625"></a>stat</strong> function. </p>
 </td>
</tr>
<tr id="row348551143165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8ae652b4433e08622981c7457b4ead9dd8"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8ae652b4433e08622981c7457b4ead9dd8"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8ae652b4433e08622981c7457b4ead9dd8"></a></strong>PERM_ERRORCODE_PATH_INVALID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1823536970165625"><a name="p1823536970165625"></a><a name="p1823536970165625"></a>Invalid path </p>
 </td>
</tr>
<tr id="row1407451611165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8a28397170788e73451c03bdacaf07bb09"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a28397170788e73451c03bdacaf07bb09"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a28397170788e73451c03bdacaf07bb09"></a></strong>PERM_ERRORCODE_TOO_MUCH_PERM </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p39103915165625"><a name="p39103915165625"></a><a name="p39103915165625"></a>Too many permissions </p>
 </td>
</tr>
<tr id="row1498197654165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8a20ce1cb092907845a84f138e45d06651"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a20ce1cb092907845a84f138e45d06651"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a20ce1cb092907845a84f138e45d06651"></a></strong>PERM_ERRORCODE_TASKID_NOT_EXIST </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1106881375165625"><a name="p1106881375165625"></a><a name="p1106881375165625"></a>The process ID does not exist. </p>
 </td>
</tr>
<tr id="row1774331318165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacb79d7f5cd64c73479e0bdd9525265a8a2e7d34ab9f33c396cac29e094277fef5"><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a2e7d34ab9f33c396cac29e094277fef5"></a><a name="ggacb79d7f5cd64c73479e0bdd9525265a8a2e7d34ab9f33c396cac29e094277fef5"></a></strong>PERM_ERRORCODE_PERM_NUM_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1251482204165625"><a name="p1251482204165625"></a><a name="p1251482204165625"></a>Abnormal number of permissions </p>
 </td>
</tr>
</tbody>
</table>

## **Variable **<a name="section149054169165625"></a>

## desc<a name="gac30cf9ead0186519b49c3ecd58e39937"></a>

```
char PermissionSaved::desc[[PERM_DESC_LEN](pms_types.md#gafb859b51e2b9552103cf1ba665e8eb7a)]
```

 **Description:**

Permission description. For details about its length, see  [PERM\_DESC\_LEN](pms_types.md#gafb859b51e2b9552103cf1ba665e8eb7a). 

## granted<a name="ga1b618be368f56d0d8c857aacc5b42baf"></a>

```
enum [IsGranted](pms_types.md#ga56644f429963f015addb12e36e2344f7) PermissionSaved::granted
```

 **Description:**

Whether the permission is granted 

## name<a name="gad57ecbb6ba51b1ab7f7b1533e5f8bbff"></a>

```
char PermissionSaved::name[[PERM_NAME_LEN](pms_types.md#ga1d7d82a3741ecedc4d993b523d95c0c8)]
```

 **Description:**

Permission name. For details about its length, see  [PERM\_NAME\_LEN](pms_types.md#ga1d7d82a3741ecedc4d993b523d95c0c8). 

