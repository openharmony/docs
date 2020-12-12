# dirent.h<a name="ZH-CN_TOPIC_0000001055707976"></a>

-   [Overview](#section736132765165626)
-   [Summary](#section118574325165626)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section736132765165626"></a>

**Related Modules:**

[FS](FS.md)

**Description:**

Provides functions and structures used for performing file system operations, including file read/write, directory traversal, and file system mounting. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section118574325165626"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1887670268165626"></a>
<table><thead align="left"><tr id="row1182544542165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p159633852165626"><a name="p159633852165626"></a><a name="p159633852165626"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1730633149165626"><a name="p1730633149165626"></a><a name="p1730633149165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row785381569165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1880296033165626"><a name="p1880296033165626"></a><a name="p1880296033165626"></a><a href="dirent.md">dirent</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p426199417165626"><a name="p426199417165626"></a><a name="p426199417165626"></a>Defines the content of the directory. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1498591181165626"></a>
<table><thead align="left"><tr id="row1384162198165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1455319666165626"><a name="p1455319666165626"></a><a name="p1455319666165626"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1622365518165626"><a name="p1622365518165626"></a><a name="p1622365518165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1319337065165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p735190080165626"><a name="p735190080165626"></a><a name="p735190080165626"></a><a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2120260726165626"><a name="p2120260726165626"></a><a name="p2120260726165626"></a> typedef struct __dirstream </p>
<p id="p9426752165626"><a name="p9426752165626"></a><a name="p9426752165626"></a>Opens the handle of the folder directory. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table416673640165626"></a>
<table><thead align="left"><tr id="row98827615165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p976626113165626"><a name="p976626113165626"></a><a name="p976626113165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p349447686165626"><a name="p349447686165626"></a><a name="p349447686165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row499971150165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p242698517165626"><a name="p242698517165626"></a><a name="p242698517165626"></a><a href="FS.md#gaaeac2b41e8c2c3a5f91c9bd511a8c0a6">closedir</a> (<a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a> *dirp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p329492365165626"><a name="p329492365165626"></a><a name="p329492365165626"></a>int </p>
<p id="p71092400165626"><a name="p71092400165626"></a><a name="p71092400165626"></a>Closes a specified directory. </p>
</td>
</tr>
<tr id="row2128544675165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p894102297165626"><a name="p894102297165626"></a><a name="p894102297165626"></a><a href="FS.md#gad09dd96447776d2bc5d8321e4b499591">opendir</a> (const char *<a href="FS.md#gab1b6028f4625caec30c1020e737216e2">dirname</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1236889142165626"><a name="p1236889142165626"></a><a name="p1236889142165626"></a><a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a> * </p>
<p id="p1402812773165626"><a name="p1402812773165626"></a><a name="p1402812773165626"></a>Opens a specified directory. </p>
</td>
</tr>
<tr id="row600820419165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1907488671165626"><a name="p1907488671165626"></a><a name="p1907488671165626"></a><a href="FS.md#ga58257faf8b13b3f14558613c632b2373">readdir</a> (<a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a> *dirp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p609365531165626"><a name="p609365531165626"></a><a name="p609365531165626"></a>struct <a href="dirent.md">dirent</a> * </p>
<p id="p1330193730165626"><a name="p1330193730165626"></a><a name="p1330193730165626"></a>Reads a specified directory. </p>
</td>
</tr>
<tr id="row1540719799165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1357036326165626"><a name="p1357036326165626"></a><a name="p1357036326165626"></a><a href="FS.md#ga9f1bc61c37394eda9e74e0c79afec872">readdir_r</a> (<a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a> *__restrict dirp, struct <a href="dirent.md">dirent</a> *__restrict <a href="entry.md">entry</a>, struct <a href="dirent.md">dirent</a> **__restrict result)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p295995555165626"><a name="p295995555165626"></a><a name="p295995555165626"></a>int </p>
<p id="p1589326490165626"><a name="p1589326490165626"></a><a name="p1589326490165626"></a>Reads a specified directory (thread-safe version). </p>
</td>
</tr>
<tr id="row213622278165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1051795776165626"><a name="p1051795776165626"></a><a name="p1051795776165626"></a><a href="FS.md#gad4fcb58b9194b1a3c1699654de963719">rewinddir</a> (<a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a> *dirp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p896262477165626"><a name="p896262477165626"></a><a name="p896262477165626"></a>void </p>
<p id="p1208529799165626"><a name="p1208529799165626"></a><a name="p1208529799165626"></a>Resets a directory stream read position. </p>
</td>
</tr>
<tr id="row654958441165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p671242034165626"><a name="p671242034165626"></a><a name="p671242034165626"></a><a href="FS.md#ga8a52fd9a3ded793b8200ac0a5a1f10d2">alphasort</a> (const struct <a href="dirent.md">dirent</a> **a, const struct <a href="dirent.md">dirent</a> **b)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p91386020165626"><a name="p91386020165626"></a><a name="p91386020165626"></a>int </p>
<p id="p1796043404165626"><a name="p1796043404165626"></a><a name="p1796043404165626"></a>Sorts the directory entries in alphabetical order. </p>
</td>
</tr>
<tr id="row1831430342165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1654013701165626"><a name="p1654013701165626"></a><a name="p1654013701165626"></a><a href="FS.md#gaca6df630e382cf13bac90ed6e5c4141c">scandir</a> (const char *dir, struct <a href="dirent.md">dirent</a> ***namelist, int(*sel)(const struct <a href="dirent.md">dirent</a> *), int(*compar)(const struct <a href="dirent.md">dirent</a> **, const struct <a href="dirent.md">dirent</a> **))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1848659749165626"><a name="p1848659749165626"></a><a name="p1848659749165626"></a>int </p>
<p id="p735963542165626"><a name="p735963542165626"></a><a name="p735963542165626"></a>Scans directory to find the target entries. </p>
</td>
</tr>
<tr id="row131462024165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2144159806165626"><a name="p2144159806165626"></a><a name="p2144159806165626"></a><a href="FS.md#gacf0a74ce364760e330619edb38eadfff">seekdir</a> (<a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a> *dirp, long offset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p735538287165626"><a name="p735538287165626"></a><a name="p735538287165626"></a>void </p>
<p id="p1920207006165626"><a name="p1920207006165626"></a><a name="p1920207006165626"></a>Sets the position of the next <a href="FS.md#ga58257faf8b13b3f14558613c632b2373">readdir</a> call in the directory stream. </p>
</td>
</tr>
<tr id="row2049108892165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p915263365165626"><a name="p915263365165626"></a><a name="p915263365165626"></a><a href="FS.md#ga4c2cd02bd612ae655782632c9f5227ec">telldir</a> (<a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a> *dirp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p404064282165626"><a name="p404064282165626"></a><a name="p404064282165626"></a>long </p>
<p id="p591145331165626"><a name="p591145331165626"></a><a name="p591145331165626"></a>Obtains the current position in the specified directory stream. </p>
</td>
</tr>
</tbody>
</table>

