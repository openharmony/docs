# ftw.h<a name="ZH-CN_TOPIC_0000001055228014"></a>

-   [Overview](#section1747555187165627)
-   [Summary](#section1544322499165627)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section1747555187165627"></a>

**Related Modules:**

[FS](FS.md)

**Description:**

Provides functions and structures related to file tree traversal. 

You can use the functions and structures to traverse files in a specified directory to obtain or process related information.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1544322499165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1118294494165627"></a>
<table><thead align="left"><tr id="row1638252327165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p906266230165627"><a name="p906266230165627"></a><a name="p906266230165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p791474979165627"><a name="p791474979165627"></a><a name="p791474979165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2004595888165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1296109862165627"><a name="p1296109862165627"></a><a name="p1296109862165627"></a><a href="FTW.md">FTW</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1775660510165627"><a name="p1775660510165627"></a><a name="p1775660510165627"></a>Defines the file tree walker (<a href="FTW.md">FTW</a>). </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1011447654165627"></a>
<table><thead align="left"><tr id="row940470575165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p295639071165627"><a name="p295639071165627"></a><a name="p295639071165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1028996171165627"><a name="p1028996171165627"></a><a name="p1028996171165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2077561350165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p662561991165627"><a name="p662561991165627"></a><a name="p662561991165627"></a><a href="FS.md#ga2feb73df4762e428e3967f8dfbbc8696">FTW_F</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2012203918165627"><a name="p2012203918165627"></a><a name="p2012203918165627"></a>Regular file. </p>
</td>
</tr>
<tr id="row1084275158165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p431904318165627"><a name="p431904318165627"></a><a name="p431904318165627"></a><a href="FS.md#gabb7c3d2c39c0f3c8c5f0f1b9caa3499a">FTW_D</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1930574889165627"><a name="p1930574889165627"></a><a name="p1930574889165627"></a>Directory. </p>
</td>
</tr>
<tr id="row1994536915165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1221533645165627"><a name="p1221533645165627"></a><a name="p1221533645165627"></a><a href="FS.md#gaf38dcdf86d19736b0aa55ac4defa666e">FTW_DNR</a>   3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1024213774165627"><a name="p1024213774165627"></a><a name="p1024213774165627"></a>Unreadable directory. Its subdirectories will not be traversed. </p>
</td>
</tr>
<tr id="row350455150165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p932577599165627"><a name="p932577599165627"></a><a name="p932577599165627"></a><a href="FS.md#ga17ff288701c7c6baf075795c9a1beb86">FTW_NS</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p954489048165627"><a name="p954489048165627"></a><a name="p954489048165627"></a>The data of the <strong id="b508636078165627"><a name="b508636078165627"></a><a name="b508636078165627"></a>stat</strong> structure cannot be obtained. The possible cause is that the permission is incorrect. </p>
</td>
</tr>
<tr id="row1178568268165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1521889805165627"><a name="p1521889805165627"></a><a name="p1521889805165627"></a><a href="FS.md#gaeee6cd556fb6bfaf7237772e698fa48d">FTW_SL</a>   5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1435444727165627"><a name="p1435444727165627"></a><a name="p1435444727165627"></a>Symbolic link. </p>
</td>
</tr>
<tr id="row1679852695165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p18728145165627"><a name="p18728145165627"></a><a name="p18728145165627"></a><a href="FS.md#ga8b34563aa640cd03e2ddf054b0b99e49">FTW_DP</a>   6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row1697390869165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1573790680165627"><a name="p1573790680165627"></a><a name="p1573790680165627"></a><a href="FS.md#gaf0e95fe567ba665873d18284d67e0f80">FTW_SLN</a>   7</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p385246589165627"><a name="p385246589165627"></a><a name="p385246589165627"></a>Symbolic link that names a non-existent file. </p>
</td>
</tr>
<tr id="row1704520454165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2108972738165627"><a name="p2108972738165627"></a><a name="p2108972738165627"></a><a href="FS.md#ga8c98a3c79a82339a189b11094032a09a">FTW_PHYS</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1064800596165627"><a name="p1064800596165627"></a><a name="p1064800596165627"></a>Symbolic links that are not traversed. If not set, symbolic links are traversed by default. </p>
</td>
</tr>
<tr id="row1779943825165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1250545627165627"><a name="p1250545627165627"></a><a name="p1250545627165627"></a><a href="FS.md#ga7bbaf43efae1f2d3c8092d99a340729d">FTW_MOUNT</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1213113564165627"><a name="p1213113564165627"></a><a name="p1213113564165627"></a>Stay within the same file system. </p>
</td>
</tr>
<tr id="row738301046165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1252530193165627"><a name="p1252530193165627"></a><a name="p1252530193165627"></a><a href="FS.md#gad8a9cc4cf048af5fab2c5f65ed9cb0db">FTW_CHDIR</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p38866238165627"><a name="p38866238165627"></a><a name="p38866238165627"></a><a href="UTILS.md#ga03af571dfb595681bfa203c83385c07b">chdir</a> is called to go to the directory before reading the directory. </p>
</td>
</tr>
<tr id="row202749472165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1889042583165627"><a name="p1889042583165627"></a><a name="p1889042583165627"></a><a href="FS.md#gaf9008c0040247fbea883ec24b10cf884">FTW_DEPTH</a>   8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1142479797165627"><a name="p1142479797165627"></a><a name="p1142479797165627"></a>All subdirectories will be traversed before the directory itself. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1819805169165627"></a>
<table><thead align="left"><tr id="row1944464821165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1377601486165627"><a name="p1377601486165627"></a><a name="p1377601486165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p786878187165627"><a name="p786878187165627"></a><a name="p786878187165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row303503964165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p34927184165627"><a name="p34927184165627"></a><a name="p34927184165627"></a><a href="FS.md#ga8dda75835c2b90f305d96e908dc0f84d">ftw</a> (const char *path, int(*fn)(const char *file, const struct <a href="stat.md">stat</a> *sb, int flag), int depth)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1667536224165627"><a name="p1667536224165627"></a><a name="p1667536224165627"></a>int </p>
<p id="p552410343165627"><a name="p552410343165627"></a><a name="p552410343165627"></a>Traverses a file tree. </p>
</td>
</tr>
<tr id="row107365279165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1630861787165627"><a name="p1630861787165627"></a><a name="p1630861787165627"></a><a href="FS.md#ga3fb6324259c86bfee53d3354798cfd43">nftw</a> (const char *path, int(*fn)(const char *file, const struct <a href="stat.md">stat</a> *sb, int flag, struct <a href="FTW.md">FTW</a> *s), int fd_limit, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1736695747165627"><a name="p1736695747165627"></a><a name="p1736695747165627"></a>int </p>
<p id="p1359267068165627"><a name="p1359267068165627"></a><a name="p1359267068165627"></a>Traverses a file tree. </p>
</td>
</tr>
</tbody>
</table>

