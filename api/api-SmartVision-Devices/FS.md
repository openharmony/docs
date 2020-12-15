# FS<a name="ZH-CN_TOPIC_0000001055069400"></a>

-   [Overview](#section1062091515165621)
-   [Summary](#section1685696024165621)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)
-   [Details](#section1643023632165621)
-   [Macro Definition](#section292839151165621)
-   [FTW\_DP](#ga8b34563aa640cd03e2ddf054b0b99e49)
-   [Function](#section1726533183165621)
-   [alphasort\(\)](#ga8a52fd9a3ded793b8200ac0a5a1f10d2)
-   [basename\(\)](#gaa14fc3333d84f41eacc023626687aebd)
-   [chmod\(\)](#ga1b893413bc424887bbe61f8d0952a0ee)
-   [closedir\(\)](#gaaeac2b41e8c2c3a5f91c9bd511a8c0a6)
-   [creat\(\)](#gafddc24a65767ae35f275be8ccf53e036)
-   [dirname\(\)](#gab1b6028f4625caec30c1020e737216e2)
-   [fallocate\(\)](#ga26ba05fc43886db02fe169b35e04bfdf)
-   [fcntl\(\)](#gad39ebe4c4767eaa9a680777400cfaafe)
-   [fstat\(\)](#ga198a57e185e8a036ad06345623b84521)
-   [ftw\(\)](#ga8dda75835c2b90f305d96e908dc0f84d)
-   [glob\(\)](#gae98601409da7fd3c85a9c219e1a9020c)
-   [globfree\(\)](#gaa43d417234c8572d6e98fb1dc12a4794)
-   [ioctl\(\)](#ga28db05c84676b387c2d8cfdd317bb9bd)
-   [lstat\(\)](#ga879b7c433a19b6b07b42edcf3871c40f)
-   [mkdir\(\)](#gaee98bbe743c2d14dbaa67f01c3fb9ed5)
-   [mkdirat\(\)](#gae0b68526355956a8e3298fcb6a72e3bc)
-   [mkfifo\(\)](#ga6b0f61de936f648da290c92ed36192c4)
-   [mount\(\)](#gadaaf1ec8aa37137233fa25d2b3af9fc8)
-   [nftw\(\)](#ga3fb6324259c86bfee53d3354798cfd43)
-   [open\(\)](#ga219205a58e244a5acd35b767ac50ef9c)
-   [opendir\(\)](#gad09dd96447776d2bc5d8321e4b499591)
-   [readdir\(\)](#ga58257faf8b13b3f14558613c632b2373)
-   [readdir\_r\(\)](#ga9f1bc61c37394eda9e74e0c79afec872)
-   [rewinddir\(\)](#gad4fcb58b9194b1a3c1699654de963719)
-   [scandir\(\)](#gaca6df630e382cf13bac90ed6e5c4141c)
-   [seekdir\(\)](#gacf0a74ce364760e330619edb38eadfff)
-   [stat\(\)](#gad2e0bcbe40344116102877f6268ee6ea)
-   [statfs\(\)](#gae7af18cc5fa39f42a3be1bf1eb24119d)
-   [statvfs\(\)](#ga41058769ad8ea7d7d467799f651b8b1a)
-   [telldir\(\)](#ga4c2cd02bd612ae655782632c9f5227ec)
-   [umask\(\)](#ga556063623e479c26c64544024a046024)
-   [umount\(\)](#ga44634cfa8bcc732c29bcdf5822095422)
-   [umount2\(\)](#ga2125a021d10f7a28a66cbc9335ad826f)
-   [utime\(\)](#ga1299674b4b1934ebf0441388d07981a6)

## **Overview**<a name="section1062091515165621"></a>

**Description:**

Provides functions for file system, include file operations, directory operations and so on. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1685696024165621"></a>

## Files<a name="files"></a>

<a name="table1775892172165621"></a>
<table><thead align="left"><tr id="row1365623505165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1806314026165621"><a name="p1806314026165621"></a><a name="p1806314026165621"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p915120491165621"><a name="p915120491165621"></a><a name="p915120491165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row317747624165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p616271579165621"><a name="p616271579165621"></a><a name="p616271579165621"></a><a href="dirent-h.md">dirent.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2128328789165621"><a name="p2128328789165621"></a><a name="p2128328789165621"></a>Provides functions and structures used for performing file system operations, including file read/write, directory traversal, and file system mounting. </p>
</td>
</tr>
<tr id="row227991972165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1504549775165621"><a name="p1504549775165621"></a><a name="p1504549775165621"></a><a href="fcntl-h.md">fcntl.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p242126645165621"><a name="p242126645165621"></a><a name="p242126645165621"></a>Declares structures and functions used for file and directory operations such as opening a file, creating a file, and allocating space. </p>
</td>
</tr>
<tr id="row1055616613165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p789992131165621"><a name="p789992131165621"></a><a name="p789992131165621"></a><a href="ftw-h.md">ftw.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p934576009165621"><a name="p934576009165621"></a><a name="p934576009165621"></a>Provides functions and structures related to file tree traversal. </p>
</td>
</tr>
<tr id="row1014109788165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1340266070165621"><a name="p1340266070165621"></a><a name="p1340266070165621"></a><a href="glob-h.md">glob.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1903282285165621"><a name="p1903282285165621"></a><a name="p1903282285165621"></a>Provides functions and structures used to find path names matching a pattern and release the memory that was applied for during the search. </p>
</td>
</tr>
<tr id="row1011834121165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p743414660165621"><a name="p743414660165621"></a><a name="p743414660165621"></a><a href="libgen-h.md">libgen.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2051530604165621"><a name="p2051530604165621"></a><a name="p2051530604165621"></a>Provides functions related to file management, for example, obtaining directory and file names. </p>
</td>
</tr>
<tr id="row827520543165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2024999430165621"><a name="p2024999430165621"></a><a name="p2024999430165621"></a><a href="ioctl-h.md">ioctl.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p107603851165621"><a name="p107603851165621"></a><a name="p107603851165621"></a>Manipulates a device. </p>
</td>
</tr>
<tr id="row124313600165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2033850197165621"><a name="p2033850197165621"></a><a name="p2033850197165621"></a><a href="mount-h.md">mount.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1579966084165621"><a name="p1579966084165621"></a><a name="p1579966084165621"></a>Provides functions for mounting and unmounting a file system. </p>
</td>
</tr>
<tr id="row1526156922165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p976618885165621"><a name="p976618885165621"></a><a name="p976618885165621"></a><a href="stat-h.md">stat.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1314981007165621"><a name="p1314981007165621"></a><a name="p1314981007165621"></a>Provides functions for file and directory operations. </p>
</td>
</tr>
<tr id="row245758841165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p96928892165621"><a name="p96928892165621"></a><a name="p96928892165621"></a><a href="statfs-h.md">statfs.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p837595786165621"><a name="p837595786165621"></a><a name="p837595786165621"></a>Provides a function to obtain information about a file system. </p>
</td>
</tr>
<tr id="row1783477794165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p535364220165621"><a name="p535364220165621"></a><a name="p535364220165621"></a><a href="statvfs-h.md">statvfs.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p202438385165621"><a name="p202438385165621"></a><a name="p202438385165621"></a>Provides a function and structure related to file system information operation, for example, viewing file system information. </p>
</td>
</tr>
<tr id="row1364819832165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1859420254165621"><a name="p1859420254165621"></a><a name="p1859420254165621"></a><a href="utime-h.md">utime.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p156535922165621"><a name="p156535922165621"></a><a name="p156535922165621"></a>Provides the function and structure used for setting file access time and modification time. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table241149299165621"></a>
<table><thead align="left"><tr id="row1613273187165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p661050800165621"><a name="p661050800165621"></a><a name="p661050800165621"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p955396683165621"><a name="p955396683165621"></a><a name="p955396683165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1989179555165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p859846944165621"><a name="p859846944165621"></a><a name="p859846944165621"></a><a href="dirent.md">dirent</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p83898250165621"><a name="p83898250165621"></a><a name="p83898250165621"></a>Defines the content of the directory. </p>
</td>
</tr>
<tr id="row1898774197165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p516893038165621"><a name="p516893038165621"></a><a name="p516893038165621"></a><a href="FTW.md">FTW</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2034014734165621"><a name="p2034014734165621"></a><a name="p2034014734165621"></a>Defines the file tree walker (<a href="FTW.md">FTW</a>). </p>
</td>
</tr>
<tr id="row1266683520165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1315909051165621"><a name="p1315909051165621"></a><a name="p1315909051165621"></a><a href="glob_t.md">glob_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2049622065165621"><a name="p2049622065165621"></a><a name="p2049622065165621"></a>Defines the search information. </p>
</td>
</tr>
<tr id="row1314268193165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1452074689165621"><a name="p1452074689165621"></a><a name="p1452074689165621"></a><a href="stat.md">stat</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p866900159165621"><a name="p866900159165621"></a><a name="p866900159165621"></a>Defines the file information structure. </p>
</td>
</tr>
<tr id="row236790405165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1709082170165621"><a name="p1709082170165621"></a><a name="p1709082170165621"></a><a href="statvfs.md">statvfs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p743537892165621"><a name="p743537892165621"></a><a name="p743537892165621"></a>Describes file system information. </p>
</td>
</tr>
<tr id="row998829651165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1600428163165621"><a name="p1600428163165621"></a><a name="p1600428163165621"></a><a href="utimbuf.md">utimbuf</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p985938512165621"><a name="p985938512165621"></a><a name="p985938512165621"></a>Defines the file access time and modification time. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table2113743537165621"></a>
<table><thead align="left"><tr id="row927801066165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1365468372165621"><a name="p1365468372165621"></a><a name="p1365468372165621"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p718352291165621"><a name="p718352291165621"></a><a name="p718352291165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row275022440165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p654307223165621"><a name="p654307223165621"></a><a name="p654307223165621"></a><em id="ga4dc4d45e07d2abc899bcaf04b2846a87"><a name="ga4dc4d45e07d2abc899bcaf04b2846a87"></a><a name="ga4dc4d45e07d2abc899bcaf04b2846a87"></a></em>O_ACCMODE    (03|O_SEARCH)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p533116280165621"><a name="p533116280165621"></a><a name="p533116280165621"></a>Access mode. </p>
</td>
</tr>
<tr id="row907585346165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p967658811165621"><a name="p967658811165621"></a><a name="p967658811165621"></a><em id="ga7a68c9ffaac7dbcd652225dd7c06a54b"><a name="ga7a68c9ffaac7dbcd652225dd7c06a54b"></a><a name="ga7a68c9ffaac7dbcd652225dd7c06a54b"></a></em>O_RDONLY    00</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1456712262165621"><a name="p1456712262165621"></a><a name="p1456712262165621"></a>Read-only. </p>
</td>
</tr>
<tr id="row694540965165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1074995333165621"><a name="p1074995333165621"></a><a name="p1074995333165621"></a><em id="ga11b644a8526139c4cc1850dac1271ced"><a name="ga11b644a8526139c4cc1850dac1271ced"></a><a name="ga11b644a8526139c4cc1850dac1271ced"></a></em>O_WRONLY    01</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1967894396165621"><a name="p1967894396165621"></a><a name="p1967894396165621"></a>Write-only. </p>
</td>
</tr>
<tr id="row1211824628165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1636636094165621"><a name="p1636636094165621"></a><a name="p1636636094165621"></a><em id="gabb0586253488ee61072b73557eeb873b"><a name="gabb0586253488ee61072b73557eeb873b"></a><a name="gabb0586253488ee61072b73557eeb873b"></a></em>O_RDWR    02</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2095835698165621"><a name="p2095835698165621"></a><a name="p2095835698165621"></a>Read and write. </p>
</td>
</tr>
<tr id="row916908932165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1897382577165621"><a name="p1897382577165621"></a><a name="p1897382577165621"></a><em id="ga3bc050c90515f35b4cd6cea24760110c"><a name="ga3bc050c90515f35b4cd6cea24760110c"></a><a name="ga3bc050c90515f35b4cd6cea24760110c"></a></em>fallocate64    <a href="FS.md#ga26ba05fc43886db02fe169b35e04bfdf">fallocate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1186297149165621"><a name="p1186297149165621"></a><a name="p1186297149165621"></a>Pre-allocates space to a file. See <a href="FS.md#ga26ba05fc43886db02fe169b35e04bfdf">fallocate</a>. </p>
</td>
</tr>
<tr id="row518428026165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1966556518165621"><a name="p1966556518165621"></a><a name="p1966556518165621"></a><em id="ga2feb73df4762e428e3967f8dfbbc8696"><a name="ga2feb73df4762e428e3967f8dfbbc8696"></a><a name="ga2feb73df4762e428e3967f8dfbbc8696"></a></em>FTW_F    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1533412371165621"><a name="p1533412371165621"></a><a name="p1533412371165621"></a>Regular file. </p>
</td>
</tr>
<tr id="row1226209083165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p500018195165621"><a name="p500018195165621"></a><a name="p500018195165621"></a><em id="gabb7c3d2c39c0f3c8c5f0f1b9caa3499a"><a name="gabb7c3d2c39c0f3c8c5f0f1b9caa3499a"></a><a name="gabb7c3d2c39c0f3c8c5f0f1b9caa3499a"></a></em>FTW_D    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p167506656165621"><a name="p167506656165621"></a><a name="p167506656165621"></a>Directory. </p>
</td>
</tr>
<tr id="row1527697745165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1199553285165621"><a name="p1199553285165621"></a><a name="p1199553285165621"></a><em id="gaf38dcdf86d19736b0aa55ac4defa666e"><a name="gaf38dcdf86d19736b0aa55ac4defa666e"></a><a name="gaf38dcdf86d19736b0aa55ac4defa666e"></a></em>FTW_DNR    3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p283455975165621"><a name="p283455975165621"></a><a name="p283455975165621"></a>Unreadable directory. Its subdirectories will not be traversed. </p>
</td>
</tr>
<tr id="row1945687948165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p548970734165621"><a name="p548970734165621"></a><a name="p548970734165621"></a><em id="ga17ff288701c7c6baf075795c9a1beb86"><a name="ga17ff288701c7c6baf075795c9a1beb86"></a><a name="ga17ff288701c7c6baf075795c9a1beb86"></a></em>FTW_NS    4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1795839924165621"><a name="p1795839924165621"></a><a name="p1795839924165621"></a>The data of the <strong id="b1361341614165621"><a name="b1361341614165621"></a><a name="b1361341614165621"></a>stat</strong> structure cannot be obtained. The possible cause is that the permission is incorrect. </p>
</td>
</tr>
<tr id="row1437944056165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1942506674165621"><a name="p1942506674165621"></a><a name="p1942506674165621"></a><em id="gaeee6cd556fb6bfaf7237772e698fa48d"><a name="gaeee6cd556fb6bfaf7237772e698fa48d"></a><a name="gaeee6cd556fb6bfaf7237772e698fa48d"></a></em>FTW_SL    5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p895526496165621"><a name="p895526496165621"></a><a name="p895526496165621"></a>Symbolic link. </p>
</td>
</tr>
<tr id="row566684105165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1938268037165621"><a name="p1938268037165621"></a><a name="p1938268037165621"></a><a href="FS.md#ga8b34563aa640cd03e2ddf054b0b99e49">FTW_DP</a>   6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row50050909165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1296579928165621"><a name="p1296579928165621"></a><a name="p1296579928165621"></a><em id="gaf0e95fe567ba665873d18284d67e0f80"><a name="gaf0e95fe567ba665873d18284d67e0f80"></a><a name="gaf0e95fe567ba665873d18284d67e0f80"></a></em>FTW_SLN    7</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1508207504165621"><a name="p1508207504165621"></a><a name="p1508207504165621"></a>Symbolic link that names a non-existent file. </p>
</td>
</tr>
<tr id="row1989499589165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p149776490165621"><a name="p149776490165621"></a><a name="p149776490165621"></a><em id="ga8c98a3c79a82339a189b11094032a09a"><a name="ga8c98a3c79a82339a189b11094032a09a"></a><a name="ga8c98a3c79a82339a189b11094032a09a"></a></em>FTW_PHYS    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1896834064165621"><a name="p1896834064165621"></a><a name="p1896834064165621"></a>Symbolic links that are not traversed. If not set, symbolic links are traversed by default. </p>
</td>
</tr>
<tr id="row1421736039165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1541361921165621"><a name="p1541361921165621"></a><a name="p1541361921165621"></a><em id="ga7bbaf43efae1f2d3c8092d99a340729d"><a name="ga7bbaf43efae1f2d3c8092d99a340729d"></a><a name="ga7bbaf43efae1f2d3c8092d99a340729d"></a></em>FTW_MOUNT    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p684021849165621"><a name="p684021849165621"></a><a name="p684021849165621"></a>Stay within the same file system. </p>
</td>
</tr>
<tr id="row1054105133165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p801685215165621"><a name="p801685215165621"></a><a name="p801685215165621"></a><em id="gad8a9cc4cf048af5fab2c5f65ed9cb0db"><a name="gad8a9cc4cf048af5fab2c5f65ed9cb0db"></a><a name="gad8a9cc4cf048af5fab2c5f65ed9cb0db"></a></em>FTW_CHDIR    4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2013759852165621"><a name="p2013759852165621"></a><a name="p2013759852165621"></a><a href="UTILS.md#ga03af571dfb595681bfa203c83385c07b">chdir</a> is called to go to the directory before reading the directory. </p>
</td>
</tr>
<tr id="row1710448172165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p56290924165621"><a name="p56290924165621"></a><a name="p56290924165621"></a><em id="gaf9008c0040247fbea883ec24b10cf884"><a name="gaf9008c0040247fbea883ec24b10cf884"></a><a name="gaf9008c0040247fbea883ec24b10cf884"></a></em>FTW_DEPTH    8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p220643919165621"><a name="p220643919165621"></a><a name="p220643919165621"></a>All subdirectories will be traversed before the directory itself. </p>
</td>
</tr>
<tr id="row466660852165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p586334876165621"><a name="p586334876165621"></a><a name="p586334876165621"></a><em id="ga9e77b0b20a1c1d66cdf924a07776f360"><a name="ga9e77b0b20a1c1d66cdf924a07776f360"></a><a name="ga9e77b0b20a1c1d66cdf924a07776f360"></a></em>GLOB_ERR    0x01</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p175386835165621"><a name="p175386835165621"></a><a name="p175386835165621"></a>Return upon a read error. </p>
</td>
</tr>
<tr id="row428002441165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p996743110165621"><a name="p996743110165621"></a><a name="p996743110165621"></a><em id="gac6ec2b6ae844d895de9685a689dd27f0"><a name="gac6ec2b6ae844d895de9685a689dd27f0"></a><a name="gac6ec2b6ae844d895de9685a689dd27f0"></a></em>GLOB_MARK    0x02</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1944993592165621"><a name="p1944993592165621"></a><a name="p1944993592165621"></a>Append a slash (/) to each path, which corresponds to a directory. </p>
</td>
</tr>
<tr id="row936261037165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1664691241165621"><a name="p1664691241165621"></a><a name="p1664691241165621"></a><em id="ga4eba6cedebdfe13f924d9b4a489bfe83"><a name="ga4eba6cedebdfe13f924d9b4a489bfe83"></a><a name="ga4eba6cedebdfe13f924d9b4a489bfe83"></a></em>GLOB_NOSORT    0x04</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1188027575165621"><a name="p1188027575165621"></a><a name="p1188027575165621"></a>Do not sort the returned path names. </p>
</td>
</tr>
<tr id="row702511149165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p311981436165621"><a name="p311981436165621"></a><a name="p311981436165621"></a><em id="ga8ae13e97ae5da0993fe526c406337c62"><a name="ga8ae13e97ae5da0993fe526c406337c62"></a><a name="ga8ae13e97ae5da0993fe526c406337c62"></a></em>GLOB_DOOFFS    0x08</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1009928977165621"><a name="p1009928977165621"></a><a name="p1009928977165621"></a>In the <strong id="b251254287165621"><a name="b251254287165621"></a><a name="b251254287165621"></a>pglob</strong> parameter of the <a href="FS.md#gae98601409da7fd3c85a9c219e1a9020c">glob()</a> function, reserve a string that has a length of <strong id="b532599379165621"><a name="b532599379165621"></a><a name="b532599379165621"></a>pglob-&gt;gl_offs</strong> and ends with <strong id="b678152925165621"><a name="b678152925165621"></a><a name="b678152925165621"></a>\0</strong> at the beginning of the string list in <strong id="b1928547902165621"><a name="b1928547902165621"></a><a name="b1928547902165621"></a>pglob-&gt;pathv</strong>. That is, the newly matched string is appended to a position where the distance from the beginning of <strong id="b1679072051165621"><a name="b1679072051165621"></a><a name="b1679072051165621"></a>pglob-&gt;pathv</strong> is the length of <strong id="b634377968165621"><a name="b634377968165621"></a><a name="b634377968165621"></a>pglob-&gt;gl_offs</strong>. </p>
</td>
</tr>
<tr id="row1158445326165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p482524564165621"><a name="p482524564165621"></a><a name="p482524564165621"></a><em id="gaf183b2f40936442579be8d62b87e6fc6"><a name="gaf183b2f40936442579be8d62b87e6fc6"></a><a name="gaf183b2f40936442579be8d62b87e6fc6"></a></em>GLOB_NOCHECK    0x10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1707230167165621"><a name="p1707230167165621"></a><a name="p1707230167165621"></a>If no pattern matches, return the original pattern. </p>
</td>
</tr>
<tr id="row1435832584165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1710413938165621"><a name="p1710413938165621"></a><a name="p1710413938165621"></a><em id="ga7e586df07bb159e904a61d8470f1fda2"><a name="ga7e586df07bb159e904a61d8470f1fda2"></a><a name="ga7e586df07bb159e904a61d8470f1fda2"></a></em>GLOB_APPEND    0x20</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p447704669165621"><a name="p447704669165621"></a><a name="p447704669165621"></a>Append the results of this call to the results returned by a previous call to <strong id="b1696284764165621"><a name="b1696284764165621"></a><a name="b1696284764165621"></a><a href="FS.md#gae98601409da7fd3c85a9c219e1a9020c">glob()</a></strong>. </p>
</td>
</tr>
<tr id="row1763479464165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1788424044165621"><a name="p1788424044165621"></a><a name="p1788424044165621"></a><em id="gad21c37825788f86d5fefea803276f746"><a name="gad21c37825788f86d5fefea803276f746"></a><a name="gad21c37825788f86d5fefea803276f746"></a></em>GLOB_NOESCAPE    0x40</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1044549217165621"><a name="p1044549217165621"></a><a name="p1044549217165621"></a>Do not use a backslash () as an escape character. </p>
</td>
</tr>
<tr id="row1457007112165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2026055981165621"><a name="p2026055981165621"></a><a name="p2026055981165621"></a><em id="gab548aece9c1254c6c08475ce8c6274a2"><a name="gab548aece9c1254c6c08475ce8c6274a2"></a><a name="gab548aece9c1254c6c08475ce8c6274a2"></a></em>GLOB_PERIOD    0x80</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p560248880165621"><a name="p560248880165621"></a><a name="p560248880165621"></a>Allow a leading period to be matched by metacharacters. </p>
</td>
</tr>
<tr id="row1229055273165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1980676354165621"><a name="p1980676354165621"></a><a name="p1980676354165621"></a><em id="ga4f1c6c0dae8dfefcf3032fed1b5cd0fe"><a name="ga4f1c6c0dae8dfefcf3032fed1b5cd0fe"></a><a name="ga4f1c6c0dae8dfefcf3032fed1b5cd0fe"></a></em>GLOB_TILDE    0x1000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p406633838165621"><a name="p406633838165621"></a><a name="p406633838165621"></a>Carry out tilde expansion. If a tilde (~) is the only character in the pattern, or an initial tilde is followed immediately by a slash (/), then the home directory of the caller is substituted for the tilde. </p>
</td>
</tr>
<tr id="row676867485165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p5494945165621"><a name="p5494945165621"></a><a name="p5494945165621"></a><em id="gacf779f5283225f7a1507122f75418103"><a name="gacf779f5283225f7a1507122f75418103"></a><a name="gacf779f5283225f7a1507122f75418103"></a></em>GLOB_TILDE_CHECK    0x4000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1867251702165621"><a name="p1867251702165621"></a><a name="p1867251702165621"></a>Similar to <a href="FS.md#ga4f1c6c0dae8dfefcf3032fed1b5cd0fe">GLOB_TILDE</a>. The difference is that if the username is invalid, or the home directory cannot be determined, <a href="FS.md#gae98601409da7fd3c85a9c219e1a9020c">glob()</a> returns <a href="FS.md#gaed760cf90fd4398067cdb679ebe60312">GLOB_NOMATCH</a> to indicate an error. </p>
</td>
</tr>
<tr id="row1184438423165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2098926270165621"><a name="p2098926270165621"></a><a name="p2098926270165621"></a><em id="gab53de39e075e6fb9a11678341772930b"><a name="gab53de39e075e6fb9a11678341772930b"></a><a name="gab53de39e075e6fb9a11678341772930b"></a></em>GLOB_NOSPACE    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1260895595165621"><a name="p1260895595165621"></a><a name="p1260895595165621"></a>Memory insufficient. </p>
</td>
</tr>
<tr id="row1513224542165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p619206358165621"><a name="p619206358165621"></a><a name="p619206358165621"></a><em id="gab5de50cedafa21283878657d05fb2ba8"><a name="gab5de50cedafa21283878657d05fb2ba8"></a><a name="gab5de50cedafa21283878657d05fb2ba8"></a></em>GLOB_ABORTED    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p359559681165621"><a name="p359559681165621"></a><a name="p359559681165621"></a>Read error. </p>
</td>
</tr>
<tr id="row932684028165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p339662054165621"><a name="p339662054165621"></a><a name="p339662054165621"></a><em id="gaed760cf90fd4398067cdb679ebe60312"><a name="gaed760cf90fd4398067cdb679ebe60312"></a><a name="gaed760cf90fd4398067cdb679ebe60312"></a></em>GLOB_NOMATCH    3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1020479957165621"><a name="p1020479957165621"></a><a name="p1020479957165621"></a>No matching item is found. </p>
</td>
</tr>
<tr id="row1619316803165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1500565683165621"><a name="p1500565683165621"></a><a name="p1500565683165621"></a><em id="ga121ff4729e5e2d403808f90e6a47a113"><a name="ga121ff4729e5e2d403808f90e6a47a113"></a><a name="ga121ff4729e5e2d403808f90e6a47a113"></a></em>GLOB_NOSYS    4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1405522173165621"><a name="p1405522173165621"></a><a name="p1405522173165621"></a>The function is not supported. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1365102444165621"></a>
<table><thead align="left"><tr id="row959616113165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p990962567165621"><a name="p990962567165621"></a><a name="p990962567165621"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p411317339165621"><a name="p411317339165621"></a><a name="p411317339165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1841461609165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1474975922165621"><a name="p1474975922165621"></a><a name="p1474975922165621"></a>DIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p683753452165621"><a name="p683753452165621"></a><a name="p683753452165621"></a><strong id="ga0ebe68390948c14bb9d82987adbfc849"><a name="ga0ebe68390948c14bb9d82987adbfc849"></a><a name="ga0ebe68390948c14bb9d82987adbfc849"></a></strong> typedef struct __dirstream </p>
<p id="p1794559655165621"><a name="p1794559655165621"></a><a name="p1794559655165621"></a>Opens the handle of the folder directory. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table437930332165621"></a>
<table><thead align="left"><tr id="row808546051165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1606954788165621"><a name="p1606954788165621"></a><a name="p1606954788165621"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p588255937165621"><a name="p588255937165621"></a><a name="p588255937165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row396752680165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1950084343165621"><a name="p1950084343165621"></a><a name="p1950084343165621"></a><a href="FS.md#gaaeac2b41e8c2c3a5f91c9bd511a8c0a6">closedir</a> (<a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a> *dirp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p920832012165621"><a name="p920832012165621"></a><a name="p920832012165621"></a>int </p>
<p id="p1449778486165621"><a name="p1449778486165621"></a><a name="p1449778486165621"></a>Closes a specified directory. </p>
</td>
</tr>
<tr id="row230951953165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1919377049165621"><a name="p1919377049165621"></a><a name="p1919377049165621"></a><a href="FS.md#gad09dd96447776d2bc5d8321e4b499591">opendir</a> (const char *<a href="FS.md#gab1b6028f4625caec30c1020e737216e2">dirname</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1767519975165621"><a name="p1767519975165621"></a><a name="p1767519975165621"></a><a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a> * </p>
<p id="p327196603165621"><a name="p327196603165621"></a><a name="p327196603165621"></a>Opens a specified directory. </p>
</td>
</tr>
<tr id="row1010271609165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p734071319165621"><a name="p734071319165621"></a><a name="p734071319165621"></a><a href="FS.md#ga58257faf8b13b3f14558613c632b2373">readdir</a> (<a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a> *dirp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1310428082165621"><a name="p1310428082165621"></a><a name="p1310428082165621"></a>struct <a href="dirent.md">dirent</a> * </p>
<p id="p109036113165621"><a name="p109036113165621"></a><a name="p109036113165621"></a>Reads a specified directory. </p>
</td>
</tr>
<tr id="row157824591165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1085380168165621"><a name="p1085380168165621"></a><a name="p1085380168165621"></a><a href="FS.md#ga9f1bc61c37394eda9e74e0c79afec872">readdir_r</a> (<a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a> *__restrict dirp, struct <a href="dirent.md">dirent</a> *__restrict <a href="entry.md">entry</a>, struct <a href="dirent.md">dirent</a> **__restrict result)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p328926122165621"><a name="p328926122165621"></a><a name="p328926122165621"></a>int </p>
<p id="p1140467789165621"><a name="p1140467789165621"></a><a name="p1140467789165621"></a>Reads a specified directory (thread-safe version). </p>
</td>
</tr>
<tr id="row191088056165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1677627878165621"><a name="p1677627878165621"></a><a name="p1677627878165621"></a><a href="FS.md#gad4fcb58b9194b1a3c1699654de963719">rewinddir</a> (<a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a> *dirp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1835813404165621"><a name="p1835813404165621"></a><a name="p1835813404165621"></a>void </p>
<p id="p1359146976165621"><a name="p1359146976165621"></a><a name="p1359146976165621"></a>Resets a directory stream read position. </p>
</td>
</tr>
<tr id="row1578753295165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1779699138165621"><a name="p1779699138165621"></a><a name="p1779699138165621"></a><a href="FS.md#ga8a52fd9a3ded793b8200ac0a5a1f10d2">alphasort</a> (const struct <a href="dirent.md">dirent</a> **a, const struct <a href="dirent.md">dirent</a> **b)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p135902351165621"><a name="p135902351165621"></a><a name="p135902351165621"></a>int </p>
<p id="p1428594622165621"><a name="p1428594622165621"></a><a name="p1428594622165621"></a>Sorts the directory entries in alphabetical order. </p>
</td>
</tr>
<tr id="row1988724403165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p451406646165621"><a name="p451406646165621"></a><a name="p451406646165621"></a><a href="FS.md#gaca6df630e382cf13bac90ed6e5c4141c">scandir</a> (const char *dir, struct <a href="dirent.md">dirent</a> ***namelist, int(*sel)(const struct <a href="dirent.md">dirent</a> *), int(*compar)(const struct <a href="dirent.md">dirent</a> **, const struct <a href="dirent.md">dirent</a> **))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1317878839165621"><a name="p1317878839165621"></a><a name="p1317878839165621"></a>int </p>
<p id="p2129767878165621"><a name="p2129767878165621"></a><a name="p2129767878165621"></a>Scans directory to find the target entries. </p>
</td>
</tr>
<tr id="row303233376165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1908799639165621"><a name="p1908799639165621"></a><a name="p1908799639165621"></a><a href="FS.md#gacf0a74ce364760e330619edb38eadfff">seekdir</a> (<a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a> *dirp, long offset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1525170444165621"><a name="p1525170444165621"></a><a name="p1525170444165621"></a>void </p>
<p id="p595509006165621"><a name="p595509006165621"></a><a name="p595509006165621"></a>Sets the position of the next <a href="FS.md#ga58257faf8b13b3f14558613c632b2373">readdir</a> call in the directory stream. </p>
</td>
</tr>
<tr id="row1832236740165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1580152085165621"><a name="p1580152085165621"></a><a name="p1580152085165621"></a><a href="FS.md#ga4c2cd02bd612ae655782632c9f5227ec">telldir</a> (<a href="FS.md#ga0ebe68390948c14bb9d82987adbfc849">DIR</a> *dirp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p783800954165621"><a name="p783800954165621"></a><a name="p783800954165621"></a>long </p>
<p id="p924813656165621"><a name="p924813656165621"></a><a name="p924813656165621"></a>Obtains the current position in the specified directory stream. </p>
</td>
</tr>
<tr id="row1544165492165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1071997794165621"><a name="p1071997794165621"></a><a name="p1071997794165621"></a><a href="FS.md#gafddc24a65767ae35f275be8ccf53e036">creat</a> (const char *path, mode_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1908367204165621"><a name="p1908367204165621"></a><a name="p1908367204165621"></a>int </p>
<p id="p28556193165621"><a name="p28556193165621"></a><a name="p28556193165621"></a>Creates a file or rewrites an existing file. </p>
</td>
</tr>
<tr id="row1533936823165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1375175153165621"><a name="p1375175153165621"></a><a name="p1375175153165621"></a><a href="FS.md#ga219205a58e244a5acd35b767ac50ef9c">open</a> (const char *path, int oflags,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p909564609165621"><a name="p909564609165621"></a><a name="p909564609165621"></a>int </p>
<p id="p309192075165621"><a name="p309192075165621"></a><a name="p309192075165621"></a>Opens a file. </p>
</td>
</tr>
<tr id="row1193218355165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p627596412165621"><a name="p627596412165621"></a><a name="p627596412165621"></a><a href="FS.md#ga26ba05fc43886db02fe169b35e04bfdf">fallocate</a> (int fd, int mode, off_t offset, off_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p482500443165621"><a name="p482500443165621"></a><a name="p482500443165621"></a>int </p>
<p id="p2027818029165621"><a name="p2027818029165621"></a><a name="p2027818029165621"></a>Pre-allocates space to a file. </p>
</td>
</tr>
<tr id="row1103258563165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1248479281165621"><a name="p1248479281165621"></a><a name="p1248479281165621"></a><a href="FS.md#gad39ebe4c4767eaa9a680777400cfaafe">fcntl</a> (int fd, int cmd,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p575448169165621"><a name="p575448169165621"></a><a name="p575448169165621"></a>int </p>
<p id="p1557141356165621"><a name="p1557141356165621"></a><a name="p1557141356165621"></a>Manipulates a specified file descriptor. </p>
</td>
</tr>
<tr id="row551846312165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1574465935165621"><a name="p1574465935165621"></a><a name="p1574465935165621"></a><a href="FS.md#ga8dda75835c2b90f305d96e908dc0f84d">ftw</a> (const char *path, int(*fn)(const char *file, const struct <a href="stat.md">stat</a> *sb, int flag), int depth)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p468534870165621"><a name="p468534870165621"></a><a name="p468534870165621"></a>int </p>
<p id="p2013856732165621"><a name="p2013856732165621"></a><a name="p2013856732165621"></a>Traverses a file tree. </p>
</td>
</tr>
<tr id="row381434407165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1700879657165621"><a name="p1700879657165621"></a><a name="p1700879657165621"></a><a href="FS.md#ga3fb6324259c86bfee53d3354798cfd43">nftw</a> (const char *path, int(*fn)(const char *file, const struct <a href="stat.md">stat</a> *sb, int flag, struct <a href="FTW.md">FTW</a> *s), int fd_limit, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p575749317165621"><a name="p575749317165621"></a><a name="p575749317165621"></a>int </p>
<p id="p581563543165621"><a name="p581563543165621"></a><a name="p581563543165621"></a>Traverses a file tree. </p>
</td>
</tr>
<tr id="row1072357671165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p200276395165621"><a name="p200276395165621"></a><a name="p200276395165621"></a><a href="FS.md#gae98601409da7fd3c85a9c219e1a9020c">glob</a> (const char *__restrict pattern, int flags, int(*errfunc)(const char *, int), <a href="glob_t.md">glob_t</a> *__restrict pglob)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1539370744165621"><a name="p1539370744165621"></a><a name="p1539370744165621"></a>int </p>
<p id="p1712690330165621"><a name="p1712690330165621"></a><a name="p1712690330165621"></a>Searches for path names that meet a specified pattern. </p>
</td>
</tr>
<tr id="row921589887165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p968144139165621"><a name="p968144139165621"></a><a name="p968144139165621"></a><a href="FS.md#gaa43d417234c8572d6e98fb1dc12a4794">globfree</a> (<a href="glob_t.md">glob_t</a> *pglob)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1058931105165621"><a name="p1058931105165621"></a><a name="p1058931105165621"></a>void </p>
<p id="p333186062165621"><a name="p333186062165621"></a><a name="p333186062165621"></a>Frees allocated memory from a call to <strong id="b1793905724165621"><a name="b1793905724165621"></a><a name="b1793905724165621"></a><a href="FS.md#gae98601409da7fd3c85a9c219e1a9020c">glob()</a></strong>. </p>
</td>
</tr>
<tr id="row738024543165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p617209472165621"><a name="p617209472165621"></a><a name="p617209472165621"></a><a href="FS.md#gab1b6028f4625caec30c1020e737216e2">dirname</a> (char *path)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p133296975165621"><a name="p133296975165621"></a><a name="p133296975165621"></a>char * </p>
<p id="p970232027165621"><a name="p970232027165621"></a><a name="p970232027165621"></a>Obtains a directory name in a specified path. </p>
</td>
</tr>
<tr id="row2052996795165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p554768723165621"><a name="p554768723165621"></a><a name="p554768723165621"></a><a href="FS.md#gaa14fc3333d84f41eacc023626687aebd">basename</a> (char *path)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1742491819165621"><a name="p1742491819165621"></a><a name="p1742491819165621"></a>char * </p>
<p id="p706203598165621"><a name="p706203598165621"></a><a name="p706203598165621"></a>Obtains a file name (excluding the directory) in a specified path. </p>
</td>
</tr>
<tr id="row1687458807165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1101890820165621"><a name="p1101890820165621"></a><a name="p1101890820165621"></a><a href="FS.md#ga28db05c84676b387c2d8cfdd317bb9bd">ioctl</a> (int fd, int cmd,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p919028863165621"><a name="p919028863165621"></a><a name="p919028863165621"></a>int </p>
<p id="p684292480165621"><a name="p684292480165621"></a><a name="p684292480165621"></a>Manipulates a device. </p>
</td>
</tr>
<tr id="row628189478165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1286281560165621"><a name="p1286281560165621"></a><a name="p1286281560165621"></a><a href="FS.md#gadaaf1ec8aa37137233fa25d2b3af9fc8">mount</a> (const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1606251913165621"><a name="p1606251913165621"></a><a name="p1606251913165621"></a>int </p>
<p id="p1146150627165621"><a name="p1146150627165621"></a><a name="p1146150627165621"></a>Mounts a file system. </p>
</td>
</tr>
<tr id="row1113311284165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1294128569165621"><a name="p1294128569165621"></a><a name="p1294128569165621"></a><a href="FS.md#ga44634cfa8bcc732c29bcdf5822095422">umount</a> (const char *target)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p237603857165621"><a name="p237603857165621"></a><a name="p237603857165621"></a>int </p>
<p id="p1269677465165621"><a name="p1269677465165621"></a><a name="p1269677465165621"></a>Unmounts a file system. </p>
</td>
</tr>
<tr id="row732151715165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1053448559165621"><a name="p1053448559165621"></a><a name="p1053448559165621"></a><a href="FS.md#ga2125a021d10f7a28a66cbc9335ad826f">umount2</a> (const char *target, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p777391023165621"><a name="p777391023165621"></a><a name="p777391023165621"></a>int </p>
<p id="p231194214165621"><a name="p231194214165621"></a><a name="p231194214165621"></a>Unmounts a file system. </p>
</td>
</tr>
<tr id="row1400151850165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1478506485165621"><a name="p1478506485165621"></a><a name="p1478506485165621"></a><a href="FS.md#gad2e0bcbe40344116102877f6268ee6ea">stat</a> (const char *__restrict path, struct <a href="stat.md">stat</a> *__restrict buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p880418335165621"><a name="p880418335165621"></a><a name="p880418335165621"></a>int </p>
<p id="p1787240935165621"><a name="p1787240935165621"></a><a name="p1787240935165621"></a>Obtains file information. </p>
</td>
</tr>
<tr id="row1481633238165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1701629444165621"><a name="p1701629444165621"></a><a name="p1701629444165621"></a><a href="FS.md#ga198a57e185e8a036ad06345623b84521">fstat</a> (int fd, struct <a href="stat.md">stat</a> *buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p361396531165621"><a name="p361396531165621"></a><a name="p361396531165621"></a>int </p>
<p id="p1904574819165621"><a name="p1904574819165621"></a><a name="p1904574819165621"></a>Obtains file status information. </p>
</td>
</tr>
<tr id="row873461191165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1834571599165621"><a name="p1834571599165621"></a><a name="p1834571599165621"></a><a href="FS.md#ga879b7c433a19b6b07b42edcf3871c40f">lstat</a> (const char *__restrict path, struct <a href="stat.md">stat</a> *__restrict buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1515670556165621"><a name="p1515670556165621"></a><a name="p1515670556165621"></a>int </p>
<p id="p303198308165621"><a name="p303198308165621"></a><a name="p303198308165621"></a>Obtains file information. </p>
</td>
</tr>
<tr id="row726196457165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p122881296165621"><a name="p122881296165621"></a><a name="p122881296165621"></a><a href="FS.md#gaee98bbe743c2d14dbaa67f01c3fb9ed5">mkdir</a> (const char *pathname, mode_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p45019469165621"><a name="p45019469165621"></a><a name="p45019469165621"></a>int </p>
<p id="p2087818763165621"><a name="p2087818763165621"></a><a name="p2087818763165621"></a>Creates a directory. </p>
</td>
</tr>
<tr id="row1647397172165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1676802432165621"><a name="p1676802432165621"></a><a name="p1676802432165621"></a><a href="FS.md#ga6b0f61de936f648da290c92ed36192c4">mkfifo</a> (const char *name, mode_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p433141262165621"><a name="p433141262165621"></a><a name="p433141262165621"></a>int </p>
<p id="p644441559165621"><a name="p644441559165621"></a><a name="p644441559165621"></a>Creates a named pipe to implement inter-process communication. </p>
</td>
</tr>
<tr id="row2112503223165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p989559199165621"><a name="p989559199165621"></a><a name="p989559199165621"></a><a href="FS.md#gae0b68526355956a8e3298fcb6a72e3bc">mkdirat</a> (int fd, const char *pathname, mode_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1821004445165621"><a name="p1821004445165621"></a><a name="p1821004445165621"></a>int </p>
<p id="p611866487165621"><a name="p611866487165621"></a><a name="p611866487165621"></a>Creates a directory. </p>
</td>
</tr>
<tr id="row16556981165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p644169436165621"><a name="p644169436165621"></a><a name="p644169436165621"></a><a href="FS.md#ga1b893413bc424887bbe61f8d0952a0ee">chmod</a> (const char *pathname, mode_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p125820781165621"><a name="p125820781165621"></a><a name="p125820781165621"></a>int </p>
<p id="p1352821803165621"><a name="p1352821803165621"></a><a name="p1352821803165621"></a>Modifies permissions for a file. </p>
</td>
</tr>
<tr id="row75352516165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1989926325165621"><a name="p1989926325165621"></a><a name="p1989926325165621"></a><a href="FS.md#ga556063623e479c26c64544024a046024">umask</a> (mode_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1302704323165621"><a name="p1302704323165621"></a><a name="p1302704323165621"></a>mode_t </p>
<p id="p503273596165621"><a name="p503273596165621"></a><a name="p503273596165621"></a>Sets umask for a process. </p>
</td>
</tr>
<tr id="row1043171378165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p972361971165621"><a name="p972361971165621"></a><a name="p972361971165621"></a><a href="FS.md#gae7af18cc5fa39f42a3be1bf1eb24119d">statfs</a> (const char *path, struct statfs *buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1628572234165621"><a name="p1628572234165621"></a><a name="p1628572234165621"></a>int </p>
<p id="p288039589165621"><a name="p288039589165621"></a><a name="p288039589165621"></a>Obtains file system information of a file in a specified path. </p>
</td>
</tr>
<tr id="row538859243165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1137036808165621"><a name="p1137036808165621"></a><a name="p1137036808165621"></a><a href="FS.md#ga41058769ad8ea7d7d467799f651b8b1a">statvfs</a> (const char *__restrict path, struct <a href="statvfs.md">statvfs</a> *__restrict buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1611199518165621"><a name="p1611199518165621"></a><a name="p1611199518165621"></a>int </p>
<p id="p1720756113165621"><a name="p1720756113165621"></a><a name="p1720756113165621"></a>Obtains the file system information. </p>
</td>
</tr>
<tr id="row1395773379165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2024562769165621"><a name="p2024562769165621"></a><a name="p2024562769165621"></a><a href="FS.md#ga1299674b4b1934ebf0441388d07981a6">utime</a> (const char *filename, const struct <a href="utimbuf.md">utimbuf</a> *times)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1170777284165621"><a name="p1170777284165621"></a><a name="p1170777284165621"></a>int </p>
<p id="p1665214062165621"><a name="p1665214062165621"></a><a name="p1665214062165621"></a>Sets the access time and modification time of a file. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1643023632165621"></a>

## **Macro Definition **<a name="section292839151165621"></a>

## FTW\_DP<a name="ga8b34563aa640cd03e2ddf054b0b99e49"></a>

```
#define FTW_DP   6
```

 **Description:**

@briefDirectory. All subdirectories in this directory have been traversed. 

## **Function **<a name="section1726533183165621"></a>

## alphasort\(\)<a name="ga8a52fd9a3ded793b8200ac0a5a1f10d2"></a>

```
int alphasort (const struct [dirent](dirent.md) ** a, const struct [dirent](dirent.md) ** b )
```

 **Description:**

Sorts the directory entries in alphabetical order. 

This function is used to sort the two directory entries passed through the input parameters in alphabetical order. Generally, these parameters are passed in  [scandir](FS.md#gaca6df630e382cf13bac90ed6e5c4141c)  as its last parameter. 

**Parameters:**

<a name="table899876002165621"></a>
<table><thead align="left"><tr id="row2109121364165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1073756735165621"><a name="p1073756735165621"></a><a name="p1073756735165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2003803045165621"><a name="p2003803045165621"></a><a name="p2003803045165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1537476606165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to directory entry a. </td>
</tr>
<tr id="row714955053165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to directory entry b. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns an integer greater than, equal to, or less than  **0**, respectively, based on whether the name of the directory entry to which  **a**  points is lexically greater than, equal to, or less than the directory. 

## basename\(\)<a name="gaa14fc3333d84f41eacc023626687aebd"></a>

```
char* basename (char * path)
```

 **Description:**

Obtains a file name \(excluding the directory\) in a specified path. 

**Parameters:**

<a name="table760512241165621"></a>
<table><thead align="left"><tr id="row1777428882165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p636114803165621"><a name="p636114803165621"></a><a name="p636114803165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p848955471165621"><a name="p848955471165621"></a><a name="p848955471165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1569773694165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">path</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the path. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the file name if the operation is successful; returns  **NULL**  otherwise. 

## chmod\(\)<a name="ga1b893413bc424887bbe61f8d0952a0ee"></a>

```
int chmod (const char * pathname, mode_t mode )
```

 **Description:**

Modifies permissions for a file. 

**Parameters:**

<a name="table2057590983165621"></a>
<table><thead align="left"><tr id="row1021997541165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p342447456165621"><a name="p342447456165621"></a><a name="p342447456165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p152702497165621"><a name="p152702497165621"></a><a name="p152702497165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1762309249165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pathname</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the path of the file. </td>
</tr>
<tr id="row1733961611165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the new file permission. </td>
</tr>
</tbody>
</table>

**Attention:**

This function can be used only in the JFFS2 file system. 

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table36773072165621"></a>
<table><thead align="left"><tr id="row1542261405165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p694851532165621"><a name="p694851532165621"></a><a name="p694851532165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1062338630165621"><a name="p1062338630165621"></a><a name="p1062338630165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row597739866165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p396066776165621"><a name="p396066776165621"></a><a name="p396066776165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p251416956165621"><a name="p251416956165621"></a><a name="p251416956165621"></a>The <strong id="b666035787165621"><a name="b666035787165621"></a><a name="b666035787165621"></a>pathname</strong> is a null pointer or an empty string. </p>
</td>
</tr>
<tr id="row452361029165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p907098594165621"><a name="p907098594165621"></a><a name="p907098594165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p699261178165621"><a name="p699261178165621"></a><a name="p699261178165621"></a>The permission bit of the file mode does not allow the requested access, or the search permission is denied on the path prefix directory. </p>
</td>
</tr>
<tr id="row15946788165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1380409742165621"><a name="p1380409742165621"></a><a name="p1380409742165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1963697241165621"><a name="p1963697241165621"></a><a name="p1963697241165621"></a>Incorrect IP address. </p>
</td>
</tr>
<tr id="row1419981847165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1873621025165621"><a name="p1873621025165621"></a><a name="p1873621025165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1434287949165621"><a name="p1434287949165621"></a><a name="p1434287949165621"></a>The path name length is greater than the value of <a href="UTILS.md#gac64541bdd81c961304b9babef1402640">NAME_MAX</a>. </p>
</td>
</tr>
<tr id="row1021938291165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p170121841165621"><a name="p170121841165621"></a><a name="p170121841165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1546461537165621"><a name="p1546461537165621"></a><a name="p1546461537165621"></a>The directory component in the path name does not exist. </p>
</td>
</tr>
<tr id="row402969278165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1491326526165621"><a name="p1491326526165621"></a><a name="p1491326526165621"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p159024320165621"><a name="p159024320165621"></a><a name="p159024320165621"></a>Insufficient memory. </p>
</td>
</tr>
<tr id="row1342920709165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1363371254165621"><a name="p1363371254165621"></a><a name="p1363371254165621"></a>ENOTDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2062105226165621"><a name="p2062105226165621"></a><a name="p2062105226165621"></a>A component of the <strong id="b265415755165621"><a name="b265415755165621"></a><a name="b265415755165621"></a>path</strong> prefix is the name of an existing file. The file is neither a directory nor a symbolic link of a directory. </p>
</td>
</tr>
<tr id="row140080014165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p542090991165621"><a name="p542090991165621"></a><a name="p542090991165621"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1362177467165621"><a name="p1362177467165621"></a><a name="p1362177467165621"></a>Operation not permitted or access denied because the access is prohibited or the directory is full. </p>
</td>
</tr>
<tr id="row689987176165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p555632576165621"><a name="p555632576165621"></a><a name="p555632576165621"></a>EROFS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p208600323165621"><a name="p208600323165621"></a><a name="p208600323165621"></a>The physical drive is write-protected. </p>
</td>
</tr>
<tr id="row798996767165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1226292773165621"><a name="p1226292773165621"></a><a name="p1226292773165621"></a>EEXIST </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1278615670165621"><a name="p1278615670165621"></a><a name="p1278615670165621"></a>The file or directory already exists. </p>
</td>
</tr>
<tr id="row1262020691165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1062972943165621"><a name="p1062972943165621"></a><a name="p1062972943165621"></a>ENOSYS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1930283067165621"><a name="p1930283067165621"></a><a name="p1930283067165621"></a>The function is not supported. </p>
</td>
</tr>
</tbody>
</table>

## closedir\(\)<a name="gaaeac2b41e8c2c3a5f91c9bd511a8c0a6"></a>

```
int closedir ([DIR](FS.md#ga0ebe68390948c14bb9d82987adbfc849) * dirp)
```

 **Description:**

Closes a specified directory. 

**Parameters:**

<a name="table315234609165621"></a>
<table><thead align="left"><tr id="row512493476165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p549504194165621"><a name="p549504194165621"></a><a name="p549504194165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p967069363165621"><a name="p967069363165621"></a><a name="p967069363165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row488936122165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dirp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the structure representing the directory to close. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the directory is successfully closed; returns  **-1**  and sets  **errno**  to the following value otherwise. 

<a name="table968129699165621"></a>
<table><thead align="left"><tr id="row2039553129165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p472217388165621"><a name="p472217388165621"></a><a name="p472217388165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1125171851165621"><a name="p1125171851165621"></a><a name="p1125171851165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row482512050165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2006478360165621"><a name="p2006478360165621"></a><a name="p2006478360165621"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1712963847165621"><a name="p1712963847165621"></a><a name="p1712963847165621"></a><strong id="b1388678002165621"><a name="b1388678002165621"></a><a name="b1388678002165621"></a>dirp</strong> is not a valid opened directory stream. </p>
</td>
</tr>
</tbody>
</table>

## creat\(\)<a name="gafddc24a65767ae35f275be8ccf53e036"></a>

```
int creat (const char * path, mode_t mode )
```

 **Description:**

Creates a file or rewrites an existing file. 

**Parameters:**

<a name="table682278701165621"></a>
<table><thead align="left"><tr id="row1576167141165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1286535130165621"><a name="p1286535130165621"></a><a name="p1286535130165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p962729754165621"><a name="p962729754165621"></a><a name="p962729754165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row279189594165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">path</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the file to create or rewrite. </td>
</tr>
<tr id="row17357747165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates permissions on the file. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the file is created or rewritten successfully; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table1938828751165621"></a>
<table><thead align="left"><tr id="row1419436712165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1444859679165621"><a name="p1444859679165621"></a><a name="p1444859679165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2131065233165621"><a name="p2131065233165621"></a><a name="p2131065233165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1034225889165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p797420708165621"><a name="p797420708165621"></a><a name="p797420708165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2020861257165621"><a name="p2020861257165621"></a><a name="p2020861257165621"></a><strong id="b1787004015165621"><a name="b1787004015165621"></a><a name="b1787004015165621"></a>path</strong> points to an invalid path. </p>
</td>
</tr>
<tr id="row657625775165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1645924316165621"><a name="p1645924316165621"></a><a name="p1645924316165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p93778076165621"><a name="p93778076165621"></a><a name="p93778076165621"></a>The length of <strong id="b1290218197165621"><a name="b1290218197165621"></a><a name="b1290218197165621"></a>path</strong> is greater than the value of <a href="UTILS.md#gac64541bdd81c961304b9babef1402640">NAME_MAX</a>. </p>
</td>
</tr>
<tr id="row1362517578165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p95050043165621"><a name="p95050043165621"></a><a name="p95050043165621"></a>ENXIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p624223354165621"><a name="p624223354165621"></a><a name="p624223354165621"></a>Invalid inode or the inode is not a mount point. </p>
</td>
</tr>
<tr id="row2062632208165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p771558026165621"><a name="p771558026165621"></a><a name="p771558026165621"></a>EMFILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1095913852165621"><a name="p1095913852165621"></a><a name="p1095913852165621"></a>All file descriptors that can be used by the process are opened. </p>
</td>
</tr>
<tr id="row988767174165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1872520466165621"><a name="p1872520466165621"></a><a name="p1872520466165621"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1400870129165621"><a name="p1400870129165621"></a><a name="p1400870129165621"></a>The file structure corresponding to the file descriptor cannot be obtained. </p>
</td>
</tr>
<tr id="row2040652828165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p877572067165621"><a name="p877572067165621"></a><a name="p877572067165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1934512907165621"><a name="p1934512907165621"></a><a name="p1934512907165621"></a>Access denied by the permission bit of file mode </p>
</td>
</tr>
<tr id="row2138074327165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2041140597165621"><a name="p2041140597165621"></a><a name="p2041140597165621"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1302923582165621"><a name="p1302923582165621"></a><a name="p1302923582165621"></a>The memory is insufficient. </p>
</td>
</tr>
<tr id="row357131379165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1360061383165621"><a name="p1360061383165621"></a><a name="p1360061383165621"></a>ENODEV </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1308066390165621"><a name="p1308066390165621"></a><a name="p1308066390165621"></a>The device does not exist. </p>
</td>
</tr>
<tr id="row942998134165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p271143529165621"><a name="p271143529165621"></a><a name="p271143529165621"></a>EEXIST </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1818189271165621"><a name="p1818189271165621"></a><a name="p1818189271165621"></a><strong id="b918548527165621"><a name="b918548527165621"></a><a name="b918548527165621"></a>O_CREAT</strong> and <strong id="b73229124165621"><a name="b73229124165621"></a><a name="b73229124165621"></a>O_EXCL</strong> are set. </p>
</td>
</tr>
<tr id="row981097151165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1313396656165621"><a name="p1313396656165621"></a><a name="p1313396656165621"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1338759671165621"><a name="p1338759671165621"></a><a name="p1338759671165621"></a>A hardware error occurs at the low-level disk I/O layer. As a result, the physical drive cannot work. </p>
</td>
</tr>
<tr id="row312116990165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p113011089165621"><a name="p113011089165621"></a><a name="p113011089165621"></a>ENFILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1795383596165621"><a name="p1795383596165621"></a><a name="p1795383596165621"></a>The number of opened files in the system has reached the maximum. </p>
</td>
</tr>
<tr id="row869718961165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1722895304165621"><a name="p1722895304165621"></a><a name="p1722895304165621"></a>ENOTDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p309040498165621"><a name="p309040498165621"></a><a name="p309040498165621"></a>A component of the path prefix is the name of an existing file and is not a directory. </p>
</td>
</tr>
<tr id="row946892755165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1199771334165621"><a name="p1199771334165621"></a><a name="p1199771334165621"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p650284993165621"><a name="p650284993165621"></a><a name="p650284993165621"></a>The operation is rejected according to the file sharing policy. </p>
</td>
</tr>
<tr id="row1208106559165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1609857094165621"><a name="p1609857094165621"></a><a name="p1609857094165621"></a>ENOTEMPTY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p37409732165621"><a name="p37409732165621"></a><a name="p37409732165621"></a>The directory is not empty. </p>
</td>
</tr>
<tr id="row470974110165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p585746441165621"><a name="p585746441165621"></a><a name="p585746441165621"></a>ELOOP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1825276789165621"><a name="p1825276789165621"></a><a name="p1825276789165621"></a>Too many symbolic links are encountered. </p>
</td>
</tr>
<tr id="row763749517165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1960499911165621"><a name="p1960499911165621"></a><a name="p1960499911165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p383711412165621"><a name="p383711412165621"></a><a name="p383711412165621"></a>The IP address is incorrect. </p>
</td>
</tr>
</tbody>
</table>

## dirname\(\)<a name="gab1b6028f4625caec30c1020e737216e2"></a>

```
char* dirname (char * path)
```

 **Description:**

Obtains a directory name in a specified path. 

**Parameters:**

<a name="table2056747806165621"></a>
<table><thead align="left"><tr id="row1482158514165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1981606582165621"><a name="p1981606582165621"></a><a name="p1981606582165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p244303226165621"><a name="p244303226165621"></a><a name="p244303226165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row366712511165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">path</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the path. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the directory name if the operation is successful; returns  **NULL**  otherwise. 

## fallocate\(\)<a name="ga26ba05fc43886db02fe169b35e04bfdf"></a>

```
int fallocate (int fd, int mode, off_t offset, off_t len )
```

 **Description:**

Pre-allocates space to a file. 

**Parameters:**

<a name="table100476209165621"></a>
<table><thead align="left"><tr id="row1729857525165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p182596051165621"><a name="p182596051165621"></a><a name="p182596051165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1466277334165621"><a name="p1466277334165621"></a><a name="p1466277334165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row257313642165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor. </td>
</tr>
<tr id="row181170355165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the operation mode. Only <strong id="b912241116165621"><a name="b912241116165621"></a><a name="b912241116165621"></a>FALLOC_FL_KEEP_SIZE</strong> is supported. </td>
</tr>
<tr id="row552644664165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">offset</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the offset of the file to allocate. </td>
</tr>
<tr id="row795007879165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the disk space to be allocated to the file. </td>
</tr>
</tbody>
</table>

**Attention:**

This function can be used only in the FAT file system. 

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table1253972088165621"></a>
<table><thead align="left"><tr id="row1144990992165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p753443182165621"><a name="p753443182165621"></a><a name="p753443182165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1321910188165621"><a name="p1321910188165621"></a><a name="p1321910188165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1301800971165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1979592963165621"><a name="p1979592963165621"></a><a name="p1979592963165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p583587085165621"><a name="p583587085165621"></a><a name="p583587085165621"></a>The value of <strong id="b1279592272165621"><a name="b1279592272165621"></a><a name="b1279592272165621"></a>len</strong> or <strong id="b1771702220165621"><a name="b1771702220165621"></a><a name="b1771702220165621"></a>offset</strong> is less than 0 or greater than that of <a href="UTILS.md#ga9ec306f36d50c7375e74f0d1c55a3a67">INT_MAX</a>, or the value of <strong id="b1472310413165621"><a name="b1472310413165621"></a><a name="b1472310413165621"></a>mode</strong> is not <strong id="b603246990165621"><a name="b603246990165621"></a><a name="b603246990165621"></a>FALLOC_FL_KEEP_SIZE</strong>. </p>
</td>
</tr>
<tr id="row483689895165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1034100466165621"><a name="p1034100466165621"></a><a name="p1034100466165621"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1514407066165621"><a name="p1514407066165621"></a><a name="p1514407066165621"></a><strong id="b2142623150165621"><a name="b2142623150165621"></a><a name="b2142623150165621"></a>fd</strong> is not a valid file descriptor, or the basic file system does not support this operation. </p>
</td>
</tr>
<tr id="row927841162165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p755715778165621"><a name="p755715778165621"></a><a name="p755715778165621"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1150316411165621"><a name="p1150316411165621"></a><a name="p1150316411165621"></a>The file list is null. </p>
</td>
</tr>
<tr id="row1027965692165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1970777770165621"><a name="p1970777770165621"></a><a name="p1970777770165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1761292554165621"><a name="p1761292554165621"></a><a name="p1761292554165621"></a>Access denied by the authority bit of file mode </p>
</td>
</tr>
<tr id="row1264179783165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p430498731165621"><a name="p430498731165621"></a><a name="p430498731165621"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1292411458165621"><a name="p1292411458165621"></a><a name="p1292411458165621"></a>An I/O error occurs when data is read from or written to the file system. </p>
</td>
</tr>
<tr id="row135621051165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1836290421165621"><a name="p1836290421165621"></a><a name="p1836290421165621"></a>EROFS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p753841588165621"><a name="p753841588165621"></a><a name="p753841588165621"></a>The physical drive is write-protected. </p>
</td>
</tr>
<tr id="row894854793165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2026990466165621"><a name="p2026990466165621"></a><a name="p2026990466165621"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1623521196165621"><a name="p1623521196165621"></a><a name="p1623521196165621"></a>The operation is not allowed or the access is rejected. </p>
</td>
</tr>
<tr id="row1395402991165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1883233751165621"><a name="p1883233751165621"></a><a name="p1883233751165621"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1063401413165621"><a name="p1063401413165621"></a><a name="p1063401413165621"></a>The operation is rejected according to the file sharing policy. </p>
</td>
</tr>
</tbody>
</table>

## fcntl\(\)<a name="gad39ebe4c4767eaa9a680777400cfaafe"></a>

```
int fcntl (int fd, int cmd,  ... )
```

 **Description:**

Manipulates a specified file descriptor. 

**Parameters:**

<a name="table601355730165621"></a>
<table><thead align="left"><tr id="row252808167165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1278687046165621"><a name="p1278687046165621"></a><a name="p1278687046165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p939921570165621"><a name="p939921570165621"></a><a name="p939921570165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row562704108165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor. </td>
</tr>
<tr id="row794981573165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cmd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the command used to manipulate the file descriptor. </td>
</tr>
</tbody>
</table>

<a name="table503863869165621"></a>
<table><thead align="left"><tr id="row837213114165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1115187273165621"><a name="p1115187273165621"></a><a name="p1115187273165621"></a>cmd </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1271923165621"><a name="p1271923165621"></a><a name="p1271923165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1732552429165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1047895997165621"><a name="p1047895997165621"></a><a name="p1047895997165621"></a>F_DUPFD </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p703842543165621"><a name="p703842543165621"></a><a name="p703842543165621"></a>Copy a new file descriptor (<strong id="b949384572165621"><a name="b949384572165621"></a><a name="b949384572165621"></a>fd</strong> is a file). </p>
</td>
</tr>
<tr id="row832152778165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1198470596165621"><a name="p1198470596165621"></a><a name="p1198470596165621"></a>F_GETFL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p732660667165621"><a name="p732660667165621"></a><a name="p732660667165621"></a>Obtain the status of the file specified by <strong id="b766319400165621"><a name="b766319400165621"></a><a name="b766319400165621"></a>fd</strong>. (<strong id="b856633040165621"><a name="b856633040165621"></a><a name="b856633040165621"></a>fd</strong> is a file or sockets are available.) </p>
</td>
</tr>
<tr id="row236687945165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1118755748165621"><a name="p1118755748165621"></a><a name="p1118755748165621"></a>F_SETFL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1764010742165621"><a name="p1764010742165621"></a><a name="p1764010742165621"></a>Set the file descriptor status. (<strong id="b1415445367165621"><a name="b1415445367165621"></a><a name="b1415445367165621"></a>fd</strong> is a file or sockets are available.) </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the value depending on  **cmd**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table2055280497165621"></a>
<table><thead align="left"><tr id="row1456048388165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p269150756165621"><a name="p269150756165621"></a><a name="p269150756165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1489519031165621"><a name="p1489519031165621"></a><a name="p1489519031165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1549550885165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2142547883165621"><a name="p2142547883165621"></a><a name="p2142547883165621"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p134790400165621"><a name="p134790400165621"></a><a name="p134790400165621"></a>The operation is prohibited. </p>
</td>
</tr>
<tr id="row1871507137165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2041766325165621"><a name="p2041766325165621"></a><a name="p2041766325165621"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p918894964165621"><a name="p918894964165621"></a><a name="p918894964165621"></a><strong id="b1486145872165621"><a name="b1486145872165621"></a><a name="b1486145872165621"></a>fd</strong> is an invalid file descriptor. </p>
</td>
</tr>
<tr id="row1601811339165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p466512370165621"><a name="p466512370165621"></a><a name="p466512370165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1626962944165621"><a name="p1626962944165621"></a><a name="p1626962944165621"></a>Beyond the accessible address space. </p>
</td>
</tr>
<tr id="row851596343165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p152448387165621"><a name="p152448387165621"></a><a name="p152448387165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p558664417165621"><a name="p558664417165621"></a><a name="p558664417165621"></a>The command specified by <strong id="b1855426798165621"><a name="b1855426798165621"></a><a name="b1855426798165621"></a>cmd</strong> cannot be recognized. </p>
</td>
</tr>
<tr id="row255478135165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p197600829165621"><a name="p197600829165621"></a><a name="p197600829165621"></a>ENOLCK </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p703721715165621"><a name="p703721715165621"></a><a name="p703721715165621"></a>Too many segment locks open, lock table is full, or a remote locking protocol failed. </p>
</td>
</tr>
<tr id="row991223905165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p68698804165621"><a name="p68698804165621"></a><a name="p68698804165621"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1292975282165621"><a name="p1292975282165621"></a><a name="p1292975282165621"></a>Attempt to clear the <strong id="b864690314165621"><a name="b864690314165621"></a><a name="b864690314165621"></a>O_APPEND</strong> flag on a file that has the append-only attribute set. </p>
</td>
</tr>
</tbody>
</table>

## fstat\(\)<a name="ga198a57e185e8a036ad06345623b84521"></a>

```
int fstat (int fd, struct [stat](stat.md) * buf )
```

 **Description:**

Obtains file status information. 

**Parameters:**

<a name="table1305788291165621"></a>
<table><thead align="left"><tr id="row95527282165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1271233742165621"><a name="p1271233742165621"></a><a name="p1271233742165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p971685895165621"><a name="p971685895165621"></a><a name="p971685895165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1167024699165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor. </td>
</tr>
<tr id="row1417504938165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a <strong id="b1780142716165621"><a name="b1780142716165621"></a><a name="b1780142716165621"></a>stat</strong> structure into which file information is placed. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if file information is obtained successfully; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table2104626383165621"></a>
<table><thead align="left"><tr id="row1248702949165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p861329083165621"><a name="p861329083165621"></a><a name="p861329083165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p731934215165621"><a name="p731934215165621"></a><a name="p731934215165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row585837990165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p284813464165621"><a name="p284813464165621"></a><a name="p284813464165621"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1151434618165621"><a name="p1151434618165621"></a><a name="p1151434618165621"></a><strong id="b465822302165621"><a name="b465822302165621"></a><a name="b465822302165621"></a>fd</strong> is an invalid file descriptor. </p>
</td>
</tr>
<tr id="row1128921255165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1787613015165621"><a name="p1787613015165621"></a><a name="p1787613015165621"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p746439533165621"><a name="p746439533165621"></a><a name="p746439533165621"></a>The file list is null. </p>
</td>
</tr>
<tr id="row2146079756165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1816677796165621"><a name="p1816677796165621"></a><a name="p1816677796165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p385989118165621"><a name="p385989118165621"></a><a name="p385989118165621"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row372999328165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p93883074165621"><a name="p93883074165621"></a><a name="p93883074165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1584468209165621"><a name="p1584468209165621"></a><a name="p1584468209165621"></a>A component of <strong id="b1724558424165621"><a name="b1724558424165621"></a><a name="b1724558424165621"></a>path</strong> does not name an existing file or <strong id="b1245085555165621"><a name="b1245085555165621"></a><a name="b1245085555165621"></a>path</strong> is an empty string. </p>
</td>
</tr>
<tr id="row752533585165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1095201368165621"><a name="p1095201368165621"></a><a name="p1095201368165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p443079299165621"><a name="p443079299165621"></a><a name="p443079299165621"></a>The path name length is greater than the value of <a href="UTILS.md#gac64541bdd81c961304b9babef1402640">NAME_MAX</a>. </p>
</td>
</tr>
<tr id="row256032568165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1456424670165621"><a name="p1456424670165621"></a><a name="p1456424670165621"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1777506970165621"><a name="p1777506970165621"></a><a name="p1777506970165621"></a>Insufficient memory. </p>
</td>
</tr>
<tr id="row952050443165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p740495152165621"><a name="p740495152165621"></a><a name="p740495152165621"></a>ENOSYS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p83603538165621"><a name="p83603538165621"></a><a name="p83603538165621"></a>The function is not supported. </p>
</td>
</tr>
<tr id="row699074547165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p512789432165621"><a name="p512789432165621"></a><a name="p512789432165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p896568635165621"><a name="p896568635165621"></a><a name="p896568635165621"></a>Search permission is denied on a component of the path prefix. </p>
</td>
</tr>
<tr id="row2267460165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1198336561165621"><a name="p1198336561165621"></a><a name="p1198336561165621"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p429277474165621"><a name="p429277474165621"></a><a name="p429277474165621"></a>An I/O error occurs when data is read from or written to the file system. </p>
</td>
</tr>
<tr id="row1439472543165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1793439355165621"><a name="p1793439355165621"></a><a name="p1793439355165621"></a>EROFS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p3099258165621"><a name="p3099258165621"></a><a name="p3099258165621"></a>The physical drive is write-protected. </p>
</td>
</tr>
<tr id="row478808818165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p130501062165621"><a name="p130501062165621"></a><a name="p130501062165621"></a>ENOSPC </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p259657042165621"><a name="p259657042165621"></a><a name="p259657042165621"></a>No available space on the device. </p>
</td>
</tr>
<tr id="row2003198299165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p735979296165621"><a name="p735979296165621"></a><a name="p735979296165621"></a>EISDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1398199155165621"><a name="p1398199155165621"></a><a name="p1398199155165621"></a>The named file is a directory. </p>
</td>
</tr>
<tr id="row1218080974165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1856542500165621"><a name="p1856542500165621"></a><a name="p1856542500165621"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p794115236165621"><a name="p794115236165621"></a><a name="p794115236165621"></a>Operation not permitted or access denied because the access is prohibited or the directory is full. </p>
</td>
</tr>
<tr id="row1750672662165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p547702679165621"><a name="p547702679165621"></a><a name="p547702679165621"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1229012858165621"><a name="p1229012858165621"></a><a name="p1229012858165621"></a>The operation is rejected according to the file sharing policy. </p>
</td>
</tr>
<tr id="row868733189165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p632001562165621"><a name="p632001562165621"></a><a name="p632001562165621"></a>EPROTO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p305703185165621"><a name="p305703185165621"></a><a name="p305703185165621"></a>The protocol in NFS is incorrect. </p>
</td>
</tr>
<tr id="row1430594335165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p611634570165621"><a name="p611634570165621"></a><a name="p611634570165621"></a>ENODEV </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p187255082165621"><a name="p187255082165621"></a><a name="p187255082165621"></a>No such device. </p>
</td>
</tr>
<tr id="row86021249165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p946679941165621"><a name="p946679941165621"></a><a name="p946679941165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p893763025165621"><a name="p893763025165621"></a><a name="p893763025165621"></a>Incorrect IP address. </p>
</td>
</tr>
</tbody>
</table>

## ftw\(\)<a name="ga8dda75835c2b90f305d96e908dc0f84d"></a>

```
int ftw (const char * path, int(*)(const char *file, const struct [stat](stat.md) *sb, int flag) fn, int depth )
```

 **Description:**

Traverses a file tree. 

This function is used to traverse a file tree for search. 

**Parameters:**

<a name="table10105655165621"></a>
<table><thead align="left"><tr id="row1336632061165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p714767342165621"><a name="p714767342165621"></a><a name="p714767342165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1063398647165621"><a name="p1063398647165621"></a><a name="p1063398647165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row332396676165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">path</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file directory to traverse. </td>
</tr>
<tr id="row313984418165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fn</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the function to be called for the found entry. For the <strong id="b830687309165621"><a name="b830687309165621"></a><a name="b830687309165621"></a>fn</strong> function, <strong id="b675021516165621"><a name="b675021516165621"></a><a name="b675021516165621"></a>file</strong> identifies the path of the file relative to <strong id="b2008879597165621"><a name="b2008879597165621"></a><a name="b2008879597165621"></a>path</strong>, and <strong id="b1282616905165621"><a name="b1282616905165621"></a><a name="b1282616905165621"></a>sb</strong> indicates the pointer to the <a href="stat.md">stat</a> structure. <strong id="b1994863647165621"><a name="b1994863647165621"></a><a name="b1994863647165621"></a>flag</strong> indicates the flag. The values of <strong id="b1223908638165621"><a name="b1223908638165621"></a><a name="b1223908638165621"></a>flag</strong> are as follows: </td>
</tr>
<tr id="row537347499165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">depth</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of files that can be opened during traversal. </td>
</tr>
</tbody>
</table>

<a name="table275823733165621"></a>
<table><thead align="left"><tr id="row422265859165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p23104863165621"><a name="p23104863165621"></a><a name="p23104863165621"></a>value </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p952742935165621"><a name="p952742935165621"></a><a name="p952742935165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1014684673165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1120599153165621"><a name="p1120599153165621"></a><a name="p1120599153165621"></a>FTW_F </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p290113405165621"><a name="p290113405165621"></a><a name="p290113405165621"></a>Regular file </p>
</td>
</tr>
<tr id="row596047746165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p732555367165621"><a name="p732555367165621"></a><a name="p732555367165621"></a>FTW_D </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p516972302165621"><a name="p516972302165621"></a><a name="p516972302165621"></a>Directory </p>
</td>
</tr>
<tr id="row256692138165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p72805554165621"><a name="p72805554165621"></a><a name="p72805554165621"></a>FTW_DNR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1799584292165621"><a name="p1799584292165621"></a><a name="p1799584292165621"></a>Unreadable directory. Its subdirectories will not be traversed. </p>
</td>
</tr>
<tr id="row1108492136165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p69824027165621"><a name="p69824027165621"></a><a name="p69824027165621"></a>FTW_SL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1072699888165621"><a name="p1072699888165621"></a><a name="p1072699888165621"></a>Symbolic link </p>
</td>
</tr>
<tr id="row1270610154165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1219387168165621"><a name="p1219387168165621"></a><a name="p1219387168165621"></a>FTW_NS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p469337755165621"><a name="p469337755165621"></a><a name="p469337755165621"></a>The data of the <strong id="b1017676922165621"><a name="b1017676922165621"></a><a name="b1017676922165621"></a>stat</strong> structure cannot be obtained. The possible cause is that the permission is incorrect. </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the tree is traversed; returns the value that is returned by the  **fn\(\)**  function if the traversal is interrupted; returns  **-1**  if an error occurs. 

## glob\(\)<a name="gae98601409da7fd3c85a9c219e1a9020c"></a>

```
int glob (const char *__restrict pattern, int flags, int(*)(const char *, int) errfunc, [glob_t](glob_t.md) *__restrict pglob )
```

 **Description:**

Searches for path names that meet a specified pattern. 

**Parameters:**

<a name="table1967178382165621"></a>
<table><thead align="left"><tr id="row70649636165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2104724043165621"><a name="p2104724043165621"></a><a name="p2104724043165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1509400834165621"><a name="p1509400834165621"></a><a name="p1509400834165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1437289425165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pattern</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pattern you want to match. </td>
</tr>
<tr id="row156097770165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the matching mode. </td>
</tr>
<tr id="row620446887165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">errfunc</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the error processing callback function. If <strong id="b2040534743165621"><a name="b2040534743165621"></a><a name="b2040534743165621"></a>errfunc</strong> is not a null pointer, <strong id="b1035820135165621"><a name="b1035820135165621"></a><a name="b1035820135165621"></a>errfunc()</strong> is called when an error occurs (<a href="FS.md#gad09dd96447776d2bc5d8321e4b499591">opendir()</a>, <a href="FS.md#ga58257faf8b13b3f14558613c632b2373">readdir()</a>, or <a href="FS.md#gad2e0bcbe40344116102877f6268ee6ea">stat()</a> fails) during the search. If the function returns a non-zero value or <a href="FS.md#ga9e77b0b20a1c1d66cdf924a07776f360">GLOB_ERR</a> is set, <strong id="b838258386165621"><a name="b838258386165621"></a><a name="b838258386165621"></a><a href="FS.md#gae98601409da7fd3c85a9c219e1a9020c">glob()</a></strong> terminates the entire search process. </td>
</tr>
<tr id="row2129062689165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pglob</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the address storing the matched path names. </td>
</tr>
</tbody>
</table>

<a name="table1252678440165621"></a>
<table><thead align="left"><tr id="row427149005165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1441257077165621"><a name="p1441257077165621"></a><a name="p1441257077165621"></a>flags </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1664973437165621"><a name="p1664973437165621"></a><a name="p1664973437165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row412364506165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p168490492165621"><a name="p168490492165621"></a><a name="p168490492165621"></a>GLOB_ERR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1053202071165621"><a name="p1053202071165621"></a><a name="p1053202071165621"></a><a href="FS.md#ga9e77b0b20a1c1d66cdf924a07776f360">GLOB_ERR</a> </p>
</td>
</tr>
<tr id="row135830048165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1947412003165621"><a name="p1947412003165621"></a><a name="p1947412003165621"></a>GLOB_MARK </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1801860781165621"><a name="p1801860781165621"></a><a name="p1801860781165621"></a><a href="FS.md#gac6ec2b6ae844d895de9685a689dd27f0">GLOB_MARK</a> </p>
</td>
</tr>
<tr id="row984517715165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p179260878165621"><a name="p179260878165621"></a><a name="p179260878165621"></a>GLOB_NOSORT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1540814635165621"><a name="p1540814635165621"></a><a name="p1540814635165621"></a><a href="FS.md#ga4eba6cedebdfe13f924d9b4a489bfe83">GLOB_NOSORT</a> </p>
</td>
</tr>
<tr id="row531499386165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1388567606165621"><a name="p1388567606165621"></a><a name="p1388567606165621"></a>GLOB_DOOFFS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1470920453165621"><a name="p1470920453165621"></a><a name="p1470920453165621"></a><a href="FS.md#ga8ae13e97ae5da0993fe526c406337c62">GLOB_DOOFFS</a> </p>
</td>
</tr>
<tr id="row293355347165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1285876948165621"><a name="p1285876948165621"></a><a name="p1285876948165621"></a>GLOB_NOCHECK </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p759103204165621"><a name="p759103204165621"></a><a name="p759103204165621"></a><a href="FS.md#gaf183b2f40936442579be8d62b87e6fc6">GLOB_NOCHECK</a> </p>
</td>
</tr>
<tr id="row1563829151165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1902982228165621"><a name="p1902982228165621"></a><a name="p1902982228165621"></a>GLOB_APPEND </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p103262531165621"><a name="p103262531165621"></a><a name="p103262531165621"></a><a href="FS.md#ga7e586df07bb159e904a61d8470f1fda2">GLOB_APPEND</a> </p>
</td>
</tr>
<tr id="row2129571906165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p518943028165621"><a name="p518943028165621"></a><a name="p518943028165621"></a>GLOB_NOESCAPE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1483817273165621"><a name="p1483817273165621"></a><a name="p1483817273165621"></a><a href="FS.md#gad21c37825788f86d5fefea803276f746">GLOB_NOESCAPE</a> </p>
</td>
</tr>
<tr id="row1383905680165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p743917772165621"><a name="p743917772165621"></a><a name="p743917772165621"></a>GLOB_PERIOD </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1267666838165621"><a name="p1267666838165621"></a><a name="p1267666838165621"></a><a href="FS.md#gab548aece9c1254c6c08475ce8c6274a2">GLOB_PERIOD</a> </p>
</td>
</tr>
<tr id="row1704402488165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p91989430165621"><a name="p91989430165621"></a><a name="p91989430165621"></a>GLOB_TILDE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p332198936165621"><a name="p332198936165621"></a><a name="p332198936165621"></a><a href="FS.md#ga4f1c6c0dae8dfefcf3032fed1b5cd0fe">GLOB_TILDE</a> </p>
</td>
</tr>
<tr id="row1062170584165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p124230141165621"><a name="p124230141165621"></a><a name="p124230141165621"></a>GLOB_TILDE_CHECK </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p968627311165621"><a name="p968627311165621"></a><a name="p968627311165621"></a><a href="FS.md#gacf779f5283225f7a1507122f75418103">GLOB_TILDE_CHECK</a> </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  on successful completion; returns  [GLOB\_NOSPACE](FS.md#gab53de39e075e6fb9a11678341772930b)  for running out of memory; returns  [GLOB\_ABORTED](FS.md#gab5de50cedafa21283878657d05fb2ba8)  for a read error; returns  [GLOB\_NOMATCH](FS.md#gaed760cf90fd4398067cdb679ebe60312)  for no match found. 

## globfree\(\)<a name="gaa43d417234c8572d6e98fb1dc12a4794"></a>

```
void globfree ([glob_t](glob_t.md) * pglob)
```

 **Description:**

Frees allocated memory from a call to  **[glob\(\)](FS.md#gae98601409da7fd3c85a9c219e1a9020c)**. 

**Parameters:**

<a name="table813124571165621"></a>
<table><thead align="left"><tr id="row805611058165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1000555303165621"><a name="p1000555303165621"></a><a name="p1000555303165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1451620011165621"><a name="p1451620011165621"></a><a name="p1451620011165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1655580810165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pglob</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the address of memory dynamically allocated for a <a href="FS.md#gae98601409da7fd3c85a9c219e1a9020c">glob</a> call. </td>
</tr>
</tbody>
</table>

## ioctl\(\)<a name="ga28db05c84676b387c2d8cfdd317bb9bd"></a>

```
int ioctl (int fd, int cmd,  ... )
```

 **Description:**

Manipulates a device. 

This function is used to perform specified operations on an input device file descriptor. 

**Parameters:**

<a name="table1949121827165621"></a>
<table><thead align="left"><tr id="row1099920648165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1852829610165621"><a name="p1852829610165621"></a><a name="p1852829610165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2073999545165621"><a name="p2073999545165621"></a><a name="p2073999545165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row940576414165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor of the device (file-related file descriptors are not supported). </td>
</tr>
<tr id="row1532896602165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cmd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the operation instruction for the device. You can define it based on the specific device. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table1419421014165621"></a>
<table><thead align="left"><tr id="row1564730561165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1615623993165621"><a name="p1615623993165621"></a><a name="p1615623993165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1566607895165621"><a name="p1566607895165621"></a><a name="p1566607895165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row543670726165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p287941840165621"><a name="p287941840165621"></a><a name="p287941840165621"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1468451094165621"><a name="p1468451094165621"></a><a name="p1468451094165621"></a><strong id="b190179346165621"><a name="b190179346165621"></a><a name="b190179346165621"></a>fd</strong> is an invalid file descriptor. </p>
</td>
</tr>
<tr id="row1218993489165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1145676593165621"><a name="p1145676593165621"></a><a name="p1145676593165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2099074051165621"><a name="p2099074051165621"></a><a name="p2099074051165621"></a>An inaccessible memory area is referenced. </p>
</td>
</tr>
<tr id="row610910344165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p755431416165621"><a name="p755431416165621"></a><a name="p755431416165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1223463225165621"><a name="p1223463225165621"></a><a name="p1223463225165621"></a>The command request is invalid. </p>
</td>
</tr>
<tr id="row951043427165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p725877390165621"><a name="p725877390165621"></a><a name="p725877390165621"></a>ENOTTY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p692570988165621"><a name="p692570988165621"></a><a name="p692570988165621"></a><strong id="b580713656165621"><a name="b580713656165621"></a><a name="b580713656165621"></a>fd</strong> is not associated with a character special device. </p>
</td>
</tr>
</tbody>
</table>

## lstat\(\)<a name="ga879b7c433a19b6b07b42edcf3871c40f"></a>

```
int lstat (const char *__restrict path, struct [stat](stat.md) *__restrict buf )
```

 **Description:**

Obtains file information. 

**Parameters:**

<a name="table420159156165621"></a>
<table><thead align="left"><tr id="row1588630674165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p633462711165621"><a name="p633462711165621"></a><a name="p633462711165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p861782640165621"><a name="p861782640165621"></a><a name="p861782640165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row842671816165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">path</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file path. </td>
</tr>
<tr id="row1375230996165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a <strong id="b418280821165621"><a name="b418280821165621"></a><a name="b418280821165621"></a>stat</strong> structure into which file information is placed. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if file information is obtained successfully; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table788551223165621"></a>
<table><thead align="left"><tr id="row978225657165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1406108069165621"><a name="p1406108069165621"></a><a name="p1406108069165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1309028949165621"><a name="p1309028949165621"></a><a name="p1309028949165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1439208759165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p301425412165621"><a name="p301425412165621"></a><a name="p301425412165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p77659793165621"><a name="p77659793165621"></a><a name="p77659793165621"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row1912005515165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1049759708165621"><a name="p1049759708165621"></a><a name="p1049759708165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1757960026165621"><a name="p1757960026165621"></a><a name="p1757960026165621"></a>A component of <strong id="b1966081506165621"><a name="b1966081506165621"></a><a name="b1966081506165621"></a>path</strong> does not name an existing file or <strong id="b1555865314165621"><a name="b1555865314165621"></a><a name="b1555865314165621"></a>path</strong> is an empty string. </p>
</td>
</tr>
<tr id="row1152362261165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1634455658165621"><a name="p1634455658165621"></a><a name="p1634455658165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1139977902165621"><a name="p1139977902165621"></a><a name="p1139977902165621"></a>The path name length is greater than the value of <a href="UTILS.md#gac64541bdd81c961304b9babef1402640">NAME_MAX</a>. </p>
</td>
</tr>
<tr id="row901006342165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p314605890165621"><a name="p314605890165621"></a><a name="p314605890165621"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1867185241165621"><a name="p1867185241165621"></a><a name="p1867185241165621"></a>Insufficient memory. </p>
</td>
</tr>
<tr id="row5765336165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1240153653165621"><a name="p1240153653165621"></a><a name="p1240153653165621"></a>ENOSYS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p376988207165621"><a name="p376988207165621"></a><a name="p376988207165621"></a>The function is not supported. </p>
</td>
</tr>
<tr id="row361074908165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p425765254165621"><a name="p425765254165621"></a><a name="p425765254165621"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p456457277165621"><a name="p456457277165621"></a><a name="p456457277165621"></a>The file list is null. </p>
</td>
</tr>
<tr id="row26475935165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1361627989165621"><a name="p1361627989165621"></a><a name="p1361627989165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p262200443165621"><a name="p262200443165621"></a><a name="p262200443165621"></a>The permission bit of the file mode does not allow the requested access, or the search permission is denied on the path prefix component. </p>
</td>
</tr>
<tr id="row870282226165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p73085674165621"><a name="p73085674165621"></a><a name="p73085674165621"></a>EEXIST </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2096349223165621"><a name="p2096349223165621"></a><a name="p2096349223165621"></a>The file or directory already exists. </p>
</td>
</tr>
<tr id="row2135423143165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1314726414165621"><a name="p1314726414165621"></a><a name="p1314726414165621"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2032417095165621"><a name="p2032417095165621"></a><a name="p2032417095165621"></a>An I/O error occurs when data is read from or written to the file system. </p>
</td>
</tr>
<tr id="row56569786165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1418138847165621"><a name="p1418138847165621"></a><a name="p1418138847165621"></a>EROFS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p34994466165621"><a name="p34994466165621"></a><a name="p34994466165621"></a>The physical drive is write-protected. </p>
</td>
</tr>
<tr id="row1874035705165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2136735874165621"><a name="p2136735874165621"></a><a name="p2136735874165621"></a>ENOSPC </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p406370972165621"><a name="p406370972165621"></a><a name="p406370972165621"></a>No available space on the device. </p>
</td>
</tr>
<tr id="row430202249165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1450185402165621"><a name="p1450185402165621"></a><a name="p1450185402165621"></a>ENFILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p333672615165621"><a name="p333672615165621"></a><a name="p333672615165621"></a>The number of opened files in the system has reached the maximum. </p>
</td>
</tr>
<tr id="row298705451165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1823382724165621"><a name="p1823382724165621"></a><a name="p1823382724165621"></a>ENOTEMPTY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p887282687165621"><a name="p887282687165621"></a><a name="p887282687165621"></a>The directory is not empty. </p>
</td>
</tr>
<tr id="row648117355165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1677551665165621"><a name="p1677551665165621"></a><a name="p1677551665165621"></a>EISDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p563342945165621"><a name="p563342945165621"></a><a name="p563342945165621"></a>The named file is a directory. </p>
</td>
</tr>
<tr id="row611134301165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1101828215165621"><a name="p1101828215165621"></a><a name="p1101828215165621"></a>ENOTDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1929417520165621"><a name="p1929417520165621"></a><a name="p1929417520165621"></a>A component of the <strong id="b1589796277165621"><a name="b1589796277165621"></a><a name="b1589796277165621"></a>path</strong> prefix is the name of an existing file. The file is neither a directory nor a symbolic link of a directory. </p>
</td>
</tr>
<tr id="row967645752165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1626377361165621"><a name="p1626377361165621"></a><a name="p1626377361165621"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p610554620165621"><a name="p610554620165621"></a><a name="p610554620165621"></a>Operation not permitted or access denied because the access is prohibited or the directory is full. </p>
</td>
</tr>
<tr id="row1191420883165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2050090228165621"><a name="p2050090228165621"></a><a name="p2050090228165621"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p536851473165621"><a name="p536851473165621"></a><a name="p536851473165621"></a>The operation is rejected according to the file sharing policy. </p>
</td>
</tr>
<tr id="row1399080778165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1806596365165621"><a name="p1806596365165621"></a><a name="p1806596365165621"></a>EPROTO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p107004098165621"><a name="p107004098165621"></a><a name="p107004098165621"></a>The protocol in NFS is incorrect. </p>
</td>
</tr>
<tr id="row1384007597165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p368059548165621"><a name="p368059548165621"></a><a name="p368059548165621"></a>ENODEV </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2137569365165621"><a name="p2137569365165621"></a><a name="p2137569365165621"></a>No such device. </p>
</td>
</tr>
<tr id="row2092609677165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1786394564165621"><a name="p1786394564165621"></a><a name="p1786394564165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1770445008165621"><a name="p1770445008165621"></a><a name="p1770445008165621"></a>Incorrect IP address. </p>
</td>
</tr>
</tbody>
</table>

## mkdir\(\)<a name="gaee98bbe743c2d14dbaa67f01c3fb9ed5"></a>

```
int mkdir (const char * pathname, mode_t mode )
```

 **Description:**

Creates a directory. 

**Parameters:**

<a name="table303074648165621"></a>
<table><thead align="left"><tr id="row1392862276165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1267881697165621"><a name="p1267881697165621"></a><a name="p1267881697165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p99034309165621"><a name="p99034309165621"></a><a name="p99034309165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1595963319165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pathname</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the directory to create. </td>
</tr>
<tr id="row556232792165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the directory permission. </td>
</tr>
</tbody>
</table>

**Attention:**

This function can NOT be used in the PROC file system. 

**Returns:**

Returns  **0**  if the directory is created successfully; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table1001400194165621"></a>
<table><thead align="left"><tr id="row1967446736165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1826205995165621"><a name="p1826205995165621"></a><a name="p1826205995165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1531661275165621"><a name="p1531661275165621"></a><a name="p1531661275165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row661693382165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p196619685165621"><a name="p196619685165621"></a><a name="p196619685165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p314175788165621"><a name="p314175788165621"></a><a name="p314175788165621"></a>The <strong id="b89475312165621"><a name="b89475312165621"></a><a name="b89475312165621"></a>pathname</strong> is a null pointer or an empty string. </p>
</td>
</tr>
<tr id="row701405992165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p136254669165621"><a name="p136254669165621"></a><a name="p136254669165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2000296866165621"><a name="p2000296866165621"></a><a name="p2000296866165621"></a>The permission bit of the file mode does not allow the requested access, or the search permission is denied on the path prefix directory. </p>
</td>
</tr>
<tr id="row1100841517165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p723768514165621"><a name="p723768514165621"></a><a name="p723768514165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p181836599165621"><a name="p181836599165621"></a><a name="p181836599165621"></a>The path name length is greater than the value of <a href="UTILS.md#gac64541bdd81c961304b9babef1402640">NAME_MAX</a>. </p>
</td>
</tr>
<tr id="row778101707165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1214683590165621"><a name="p1214683590165621"></a><a name="p1214683590165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p733445939165621"><a name="p733445939165621"></a><a name="p733445939165621"></a>The directory component in the path name does not exist. </p>
</td>
</tr>
<tr id="row1455902543165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1343999913165621"><a name="p1343999913165621"></a><a name="p1343999913165621"></a>EEXIST </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p459383674165621"><a name="p459383674165621"></a><a name="p459383674165621"></a>The file or directory already exists. </p>
</td>
</tr>
<tr id="row1739790254165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1671165836165621"><a name="p1671165836165621"></a><a name="p1671165836165621"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p159990498165621"><a name="p159990498165621"></a><a name="p159990498165621"></a>An I/O error occurs when data is read from or written to the file system. </p>
</td>
</tr>
<tr id="row773794150165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p37245330165621"><a name="p37245330165621"></a><a name="p37245330165621"></a>EROFS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p439681498165621"><a name="p439681498165621"></a><a name="p439681498165621"></a>The physical drive is write-protected. </p>
</td>
</tr>
<tr id="row1295319351165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p625833102165621"><a name="p625833102165621"></a><a name="p625833102165621"></a>ENOSPC </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p573491931165621"><a name="p573491931165621"></a><a name="p573491931165621"></a>No available space on the device. </p>
</td>
</tr>
<tr id="row67498714165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p294471409165621"><a name="p294471409165621"></a><a name="p294471409165621"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1405661968165621"><a name="p1405661968165621"></a><a name="p1405661968165621"></a>Operation not permitted or access denied because the access is prohibited or the directory is full. </p>
</td>
</tr>
<tr id="row1459367406165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1344464199165621"><a name="p1344464199165621"></a><a name="p1344464199165621"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1676736217165621"><a name="p1676736217165621"></a><a name="p1676736217165621"></a>The operation is rejected according to the file sharing policy. </p>
</td>
</tr>
<tr id="row756721395165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1374406464165621"><a name="p1374406464165621"></a><a name="p1374406464165621"></a>ENOSYS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p215750807165621"><a name="p215750807165621"></a><a name="p215750807165621"></a>The function is not supported. </p>
</td>
</tr>
<tr id="row228093720165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1071772116165621"><a name="p1071772116165621"></a><a name="p1071772116165621"></a>EPROTO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p466799436165621"><a name="p466799436165621"></a><a name="p466799436165621"></a>The protocol in NFS is incorrect. </p>
</td>
</tr>
<tr id="row1697677257165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p441178934165621"><a name="p441178934165621"></a><a name="p441178934165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1482743307165621"><a name="p1482743307165621"></a><a name="p1482743307165621"></a>Incorrect IP address. </p>
</td>
</tr>
</tbody>
</table>

## mkdirat\(\)<a name="gae0b68526355956a8e3298fcb6a72e3bc"></a>

```
int mkdirat (int fd, const char * pathname, mode_t mode )
```

 **Description:**

Creates a directory. 

**Parameters:**

<a name="table1520652363165621"></a>
<table><thead align="left"><tr id="row1324994250165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p700250833165621"><a name="p700250833165621"></a><a name="p700250833165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1913009539165621"><a name="p1913009539165621"></a><a name="p1913009539165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1144775925165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor of the target directory. (Currently, only <strong id="b1339780900165621"><a name="b1339780900165621"></a><a name="b1339780900165621"></a>AT_FDCWD</strong> is supported.) </td>
</tr>
<tr id="row1936260269165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pathname</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the directory to create. </td>
</tr>
<tr id="row1724462371165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the directory permission. </td>
</tr>
</tbody>
</table>

**Attention:**

This function can NOT be used in the PROC file system. 

 Currently, the relative path is not supported. \(**fd**  must be  **AT\_FDCWD**, and the  **pathname**  argument is an absolute path.\) 

**Returns:**

Returns  **0**  if the directory is created successfully; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table1372160152165621"></a>
<table><thead align="left"><tr id="row1248920792165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p21341467165621"><a name="p21341467165621"></a><a name="p21341467165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2146914599165621"><a name="p2146914599165621"></a><a name="p2146914599165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1034331132165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p423581964165621"><a name="p423581964165621"></a><a name="p423581964165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p318482774165621"><a name="p318482774165621"></a><a name="p318482774165621"></a>The <strong id="b743151343165621"><a name="b743151343165621"></a><a name="b743151343165621"></a>pathname</strong> is a null pointer or an empty string. </p>
</td>
</tr>
<tr id="row867281934165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p790803967165621"><a name="p790803967165621"></a><a name="p790803967165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1769088429165621"><a name="p1769088429165621"></a><a name="p1769088429165621"></a>The permission bit of the file mode does not allow the requested access, or the search permission is denied on the path prefix directory. </p>
</td>
</tr>
<tr id="row1192348571165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1834801237165621"><a name="p1834801237165621"></a><a name="p1834801237165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p332420501165621"><a name="p332420501165621"></a><a name="p332420501165621"></a>The path name length is greater than the value of <a href="UTILS.md#gac64541bdd81c961304b9babef1402640">NAME_MAX</a>. </p>
</td>
</tr>
<tr id="row1461490607165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p353013322165621"><a name="p353013322165621"></a><a name="p353013322165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p367575104165621"><a name="p367575104165621"></a><a name="p367575104165621"></a>The directory component in the path name does not exist. </p>
</td>
</tr>
<tr id="row795945072165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p667461943165621"><a name="p667461943165621"></a><a name="p667461943165621"></a>EEXIST </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p647045373165621"><a name="p647045373165621"></a><a name="p647045373165621"></a>The file or directory already exists. </p>
</td>
</tr>
<tr id="row324824743165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1769170785165621"><a name="p1769170785165621"></a><a name="p1769170785165621"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1601710612165621"><a name="p1601710612165621"></a><a name="p1601710612165621"></a>An I/O error occurs when data is read from or written to the file system. </p>
</td>
</tr>
<tr id="row388846179165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p139538325165621"><a name="p139538325165621"></a><a name="p139538325165621"></a>EROFS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1659482149165621"><a name="p1659482149165621"></a><a name="p1659482149165621"></a>The physical drive is write-protected. </p>
</td>
</tr>
<tr id="row495745043165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p775359496165621"><a name="p775359496165621"></a><a name="p775359496165621"></a>ENOSPC </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p497691384165621"><a name="p497691384165621"></a><a name="p497691384165621"></a>No available space on the device. </p>
</td>
</tr>
<tr id="row1000234927165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p738307953165621"><a name="p738307953165621"></a><a name="p738307953165621"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1383360982165621"><a name="p1383360982165621"></a><a name="p1383360982165621"></a>Operation not permitted or access denied because the access is prohibited or the directory is full. </p>
</td>
</tr>
<tr id="row1222700818165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p428836062165621"><a name="p428836062165621"></a><a name="p428836062165621"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p399662723165621"><a name="p399662723165621"></a><a name="p399662723165621"></a>The operation is rejected according to the file sharing policy. </p>
</td>
</tr>
<tr id="row28489879165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p120739314165621"><a name="p120739314165621"></a><a name="p120739314165621"></a>ENOSYS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p511151933165621"><a name="p511151933165621"></a><a name="p511151933165621"></a>The function is not supported. </p>
</td>
</tr>
<tr id="row681491289165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p771985850165621"><a name="p771985850165621"></a><a name="p771985850165621"></a>EPROTO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1965138023165621"><a name="p1965138023165621"></a><a name="p1965138023165621"></a>The protocol in NFS is incorrect. </p>
</td>
</tr>
<tr id="row1633613288165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p732494586165621"><a name="p732494586165621"></a><a name="p732494586165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1352085374165621"><a name="p1352085374165621"></a><a name="p1352085374165621"></a>Incorrect IP address. </p>
</td>
</tr>
</tbody>
</table>

## mkfifo\(\)<a name="ga6b0f61de936f648da290c92ed36192c4"></a>

```
int mkfifo (const char * name, mode_t mode )
```

 **Description:**

Creates a named pipe to implement inter-process communication. 

**Parameters:**

<a name="table1482412714165621"></a>
<table><thead align="left"><tr id="row962575992165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1993249892165621"><a name="p1993249892165621"></a><a name="p1993249892165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p623075753165621"><a name="p623075753165621"></a><a name="p623075753165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row625769475165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">name</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the pipe to create. </td>
</tr>
<tr id="row292760665165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Not supported. </td>
</tr>
</tbody>
</table>

**Attention:**

Permission control is not supported. The number of pipes that can be created is not limited. Pipes can be created only in the  **/dev**  directory. 

**Returns:**

Returns  **0**  if the pipe is created successfully; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table1411234014165621"></a>
<table><thead align="left"><tr id="row2024665382165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1459062298165621"><a name="p1459062298165621"></a><a name="p1459062298165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p792542557165621"><a name="p792542557165621"></a><a name="p792542557165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1294286667165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1269556206165621"><a name="p1269556206165621"></a><a name="p1269556206165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p220383043165621"><a name="p220383043165621"></a><a name="p220383043165621"></a>Invalid input parameter (for example, empty address, file name too long or the file is not in the <strong id="b2030199513165621"><a name="b2030199513165621"></a><a name="b2030199513165621"></a>/dev</strong> directory). </p>
</td>
</tr>
<tr id="row897666933165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1852701519165621"><a name="p1852701519165621"></a><a name="p1852701519165621"></a>EEXIST </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1161974304165621"><a name="p1161974304165621"></a><a name="p1161974304165621"></a>The file already exists. </p>
</td>
</tr>
<tr id="row881650660165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p68480627165621"><a name="p68480627165621"></a><a name="p68480627165621"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1620996666165621"><a name="p1620996666165621"></a><a name="p1620996666165621"></a>Insufficient memory. </p>
</td>
</tr>
</tbody>
</table>

## mount\(\)<a name="gadaaf1ec8aa37137233fa25d2b3af9fc8"></a>

```
int mount (const char * source, const char * target, const char * filesystemtype, unsigned long mountflags, const void * data )
```

 **Description:**

Mounts a file system. 

Mounts a device \(referenced by a file system name\) to a specified directory. 

**Parameters:**

<a name="table2103666555165621"></a>
<table><thead align="left"><tr id="row951251395165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p431488374165621"><a name="p431488374165621"></a><a name="p431488374165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1392351020165621"><a name="p1392351020165621"></a><a name="p1392351020165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1163955205165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">source</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device to mount. </td>
</tr>
<tr id="row333046480165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">target</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the path of the mount point. </td>
</tr>
<tr id="row1535132860165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">filesystemtype</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file system type. </td>
</tr>
<tr id="row607042336165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mountflags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the mounting flag. </td>
</tr>
<tr id="row98386410165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mounting data. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the mounting is successful; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table875978714165621"></a>
<table><thead align="left"><tr id="row926440709165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p558487818165621"><a name="p558487818165621"></a><a name="p558487818165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p941065658165621"><a name="p941065658165621"></a><a name="p941065658165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row256186863165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p273194238165621"><a name="p273194238165621"></a><a name="p273194238165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p564474643165621"><a name="p564474643165621"></a><a name="p564474643165621"></a>A component of the path was not searchable. </p>
</td>
</tr>
<tr id="row1175194814165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p889474437165621"><a name="p889474437165621"></a><a name="p889474437165621"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p584330328165621"><a name="p584330328165621"></a><a name="p584330328165621"></a><strong id="b892020194165621"><a name="b892020194165621"></a><a name="b892020194165621"></a>source</strong> is already mounted. </p>
</td>
</tr>
<tr id="row1813434492165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p205433917165621"><a name="p205433917165621"></a><a name="p205433917165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1391478249165621"><a name="p1391478249165621"></a><a name="p1391478249165621"></a>One of the pointer parameters points outside the user address space. </p>
</td>
</tr>
<tr id="row1782832397165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1550098345165621"><a name="p1550098345165621"></a><a name="p1550098345165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1737036144165621"><a name="p1737036144165621"></a><a name="p1737036144165621"></a><strong id="b535319551165621"><a name="b535319551165621"></a><a name="b535319551165621"></a>source</strong> cannot be mounted. </p>
</td>
</tr>
<tr id="row1017571036165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p839661971165621"><a name="p839661971165621"></a><a name="p839661971165621"></a>ELOOP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1896523761165621"><a name="p1896523761165621"></a><a name="p1896523761165621"></a>Too many links encountered during path name resolution. </p>
</td>
</tr>
<tr id="row1962325097165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1367910655165621"><a name="p1367910655165621"></a><a name="p1367910655165621"></a>EMFILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1156269293165621"><a name="p1156269293165621"></a><a name="p1156269293165621"></a>(Non-block device) Virtual device table is full. </p>
</td>
</tr>
<tr id="row952451113165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p711193354165621"><a name="p711193354165621"></a><a name="p711193354165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1382697961165621"><a name="p1382697961165621"></a><a name="p1382697961165621"></a>The path name length is greater than the value of <strong id="b1140973736165621"><a name="b1140973736165621"></a><a name="b1140973736165621"></a>MAXPATHLEN</strong>. </p>
</td>
</tr>
<tr id="row72691352165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1348904244165621"><a name="p1348904244165621"></a><a name="p1348904244165621"></a>ENODEV </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1345303639165621"><a name="p1345303639165621"></a><a name="p1345303639165621"></a>No such file system type is configured in the kernel. </p>
</td>
</tr>
<tr id="row1148225645165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1409251062165621"><a name="p1409251062165621"></a><a name="p1409251062165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p145603003165621"><a name="p145603003165621"></a><a name="p145603003165621"></a>A path name is null or has a nonexistent component. </p>
</td>
</tr>
<tr id="row1961510807165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p456189505165621"><a name="p456189505165621"></a><a name="p456189505165621"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p626429972165621"><a name="p626429972165621"></a><a name="p626429972165621"></a>Insufficient memory. </p>
</td>
</tr>
<tr id="row1774915189165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p255954350165621"><a name="p255954350165621"></a><a name="p255954350165621"></a>ENOTBLK </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1775468727165621"><a name="p1775468727165621"></a><a name="p1775468727165621"></a><strong id="b1794923742165621"><a name="b1794923742165621"></a><a name="b1794923742165621"></a>source</strong> is not a block device. </p>
</td>
</tr>
<tr id="row1722588978165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1793173747165621"><a name="p1793173747165621"></a><a name="p1793173747165621"></a>ENOTDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p524481055165621"><a name="p524481055165621"></a><a name="p524481055165621"></a><strong id="b2013493044165621"><a name="b2013493044165621"></a><a name="b2013493044165621"></a>target</strong> or the prefix of <strong id="b1222971790165621"><a name="b1222971790165621"></a><a name="b1222971790165621"></a>source</strong> is not a directory. </p>
</td>
</tr>
<tr id="row288458587165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p971467065165621"><a name="p971467065165621"></a><a name="p971467065165621"></a>ENGIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1524875429165621"><a name="p1524875429165621"></a><a name="p1524875429165621"></a>No such device. </p>
</td>
</tr>
<tr id="row142577994165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p864477298165621"><a name="p864477298165621"></a><a name="p864477298165621"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p826238535165621"><a name="p826238535165621"></a><a name="p826238535165621"></a>No permission. </p>
</td>
</tr>
</tbody>
</table>

## nftw\(\)<a name="ga3fb6324259c86bfee53d3354798cfd43"></a>

```
int nftw (const char * path, int(*)(const char *file, const struct [stat](stat.md) *sb, int flag, struct [FTW](FTW.md) *s) fn, int fd_limit, int flags )
```

 **Description:**

Traverses a file tree. 

This function is used to traverse a file tree. It has a similar effect to  [ftw](FS.md#ga8dda75835c2b90f305d96e908dc0f84d)  except that it takes an additional parameter  **flags**. 

**Parameters:**

<a name="table1154380733165621"></a>
<table><thead align="left"><tr id="row336767740165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p935064824165621"><a name="p935064824165621"></a><a name="p935064824165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p250050783165621"><a name="p250050783165621"></a><a name="p250050783165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1195029843165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">path</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the file directory to traverse. </td>
</tr>
<tr id="row247274039165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fn</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the function to be called for the found entry. For the <strong id="b2107202907165621"><a name="b2107202907165621"></a><a name="b2107202907165621"></a>fn</strong> function, <strong id="b1177119302165621"><a name="b1177119302165621"></a><a name="b1177119302165621"></a>file</strong> identifies the path of the file relative to <strong id="b113077948165621"><a name="b113077948165621"></a><a name="b113077948165621"></a>path</strong>, and <strong id="b1967230454165621"><a name="b1967230454165621"></a><a name="b1967230454165621"></a>sb</strong> indicates the pointer to the <a href="stat.md">stat</a> structure. <strong id="b912333378165621"><a name="b912333378165621"></a><a name="b912333378165621"></a>flag</strong> indicates the flag. The values of <strong id="b1882094013165621"><a name="b1882094013165621"></a><a name="b1882094013165621"></a>flag</strong> are as follows: The fourth argument of <strong id="b1051289533165621"><a name="b1051289533165621"></a><a name="b1051289533165621"></a>fn()</strong> is a pointer to a <a href="FTW.md">FTW</a> structure. </td>
</tr>
<tr id="row1016866726165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd_limit</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of files that can be opened during traversal. </td>
</tr>
<tr id="row715654017165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the traversal action. It is a bitwise inclusive-OR of zero or more of the following flags: </td>
</tr>
</tbody>
</table>

<a name="table155461169165621"></a>
<table><thead align="left"><tr id="row898071275165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p669929083165621"><a name="p669929083165621"></a><a name="p669929083165621"></a>value </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p556966740165621"><a name="p556966740165621"></a><a name="p556966740165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row165734128165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p482546175165621"><a name="p482546175165621"></a><a name="p482546175165621"></a>FTW_F </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p279952003165621"><a name="p279952003165621"></a><a name="p279952003165621"></a>Regular file </p>
</td>
</tr>
<tr id="row2097776323165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p975338099165621"><a name="p975338099165621"></a><a name="p975338099165621"></a>FTW_D </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1426074747165621"><a name="p1426074747165621"></a><a name="p1426074747165621"></a>Directory </p>
</td>
</tr>
<tr id="row1161419200165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1824123710165621"><a name="p1824123710165621"></a><a name="p1824123710165621"></a>FTW_DNR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p294807211165621"><a name="p294807211165621"></a><a name="p294807211165621"></a>Unreadable directory. Its subdirectories will not be traversed. </p>
</td>
</tr>
<tr id="row1355391649165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1522749661165621"><a name="p1522749661165621"></a><a name="p1522749661165621"></a>FTW_SL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p394951619165621"><a name="p394951619165621"></a><a name="p394951619165621"></a>Symbolic link </p>
</td>
</tr>
<tr id="row1072964952165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p85741994165621"><a name="p85741994165621"></a><a name="p85741994165621"></a>FTW_NS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p310747930165621"><a name="p310747930165621"></a><a name="p310747930165621"></a>The data of the <strong id="b160851565165621"><a name="b160851565165621"></a><a name="b160851565165621"></a>stat</strong> structure cannot be obtained. The possible cause is that the permission is incorrect. </p>
</td>
</tr>
<tr id="row971898648165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p396602702165621"><a name="p396602702165621"></a><a name="p396602702165621"></a>FTW_DP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1817912023165621"><a name="p1817912023165621"></a><a name="p1817912023165621"></a>Directory. All subdirectories have been traversed. </p>
</td>
</tr>
<tr id="row1100382048165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p479634274165621"><a name="p479634274165621"></a><a name="p479634274165621"></a>FTW_SLN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p324284115165621"><a name="p324284115165621"></a><a name="p324284115165621"></a>Symbolic link that names a non-existent file </p>
</td>
</tr>
</tbody>
</table>

<a name="table950930463165621"></a>
<table><thead align="left"><tr id="row894724261165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1182080401165621"><a name="p1182080401165621"></a><a name="p1182080401165621"></a>value </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1293153159165621"><a name="p1293153159165621"></a><a name="p1293153159165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row260021465165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1500768513165621"><a name="p1500768513165621"></a><a name="p1500768513165621"></a>FTW_CHDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p828403800165621"><a name="p828403800165621"></a><a name="p828403800165621"></a>Go to the directory through <a href="UTILS.md#ga03af571dfb595681bfa203c83385c07b">chdir</a> before reading the directory. </p>
</td>
</tr>
<tr id="row2047121397165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p760182256165621"><a name="p760182256165621"></a><a name="p760182256165621"></a>FTW_DEPTH </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1738188791165621"><a name="p1738188791165621"></a><a name="p1738188791165621"></a>All subdirectories will be traversed before the directory itself. </p>
</td>
</tr>
<tr id="row1743308808165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1903754524165621"><a name="p1903754524165621"></a><a name="p1903754524165621"></a>FTW_MOUNT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1028893115165621"><a name="p1028893115165621"></a><a name="p1028893115165621"></a>Stay within the same file system. </p>
</td>
</tr>
<tr id="row787228483165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1133193461165621"><a name="p1133193461165621"></a><a name="p1133193461165621"></a>FTW_PHYS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1736172146165621"><a name="p1736172146165621"></a><a name="p1736172146165621"></a>Symbolic links that are not traversed. If not set, symbolic links are traversed by default. </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the tree is traversed; returns the value that is returned by the  **fn\(\)**  function if the traversal is interrupted; returns  **-1**  if an error occurs. 

## open\(\)<a name="ga219205a58e244a5acd35b767ac50ef9c"></a>

```
int open (const char * path, int oflags,  ... )
```

 **Description:**

Opens a file. 

**Parameters:**

<a name="table1052645246165621"></a>
<table><thead align="left"><tr id="row199844844165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p187919431165621"><a name="p187919431165621"></a><a name="p187919431165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1956459202165621"><a name="p1956459202165621"></a><a name="p1956459202165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row332757158165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">path</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the file to open. </td>
</tr>
<tr id="row1728516822165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">oflags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file access mode. Available values are as follows: </td>
</tr>
</tbody>
</table>

<a name="table1021259609165621"></a>
<table><thead align="left"><tr id="row885513887165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p210732513165621"><a name="p210732513165621"></a><a name="p210732513165621"></a>oflags </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p982267670165621"><a name="p982267670165621"></a><a name="p982267670165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row142242275165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2039134577165621"><a name="p2039134577165621"></a><a name="p2039134577165621"></a>O_RDONLY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p734237189165621"><a name="p734237189165621"></a><a name="p734237189165621"></a>Read-only </p>
</td>
</tr>
<tr id="row2076781732165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p522356346165621"><a name="p522356346165621"></a><a name="p522356346165621"></a>O_WRONLY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1179691416165621"><a name="p1179691416165621"></a><a name="p1179691416165621"></a>Write-only </p>
</td>
</tr>
<tr id="row170244614165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1235637072165621"><a name="p1235637072165621"></a><a name="p1235637072165621"></a>O_RDWR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p932368339165621"><a name="p932368339165621"></a><a name="p932368339165621"></a>Read and write </p>
</td>
</tr>
<tr id="row918689633165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1498490182165621"><a name="p1498490182165621"></a><a name="p1498490182165621"></a>O_APPEND </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p100991237165621"><a name="p100991237165621"></a><a name="p100991237165621"></a>If set, the file offset will be set to the end of the file prior to each write. </p>
</td>
</tr>
<tr id="row1294392963165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p620775578165621"><a name="p620775578165621"></a><a name="p620775578165621"></a>O_CREAT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1795418876165621"><a name="p1795418876165621"></a><a name="p1795418876165621"></a>If the file does not exist, it will be created. </p>
</td>
</tr>
<tr id="row1914832824165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p200817228165621"><a name="p200817228165621"></a><a name="p200817228165621"></a>O_LARGEFILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p415922660165621"><a name="p415922660165621"></a><a name="p415922660165621"></a>A file exceeding 2 GB can be created. </p>
</td>
</tr>
<tr id="row1514706612165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p353371151165621"><a name="p353371151165621"></a><a name="p353371151165621"></a>O_TRUNC </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p627420968165621"><a name="p627420968165621"></a><a name="p627420968165621"></a>If the file is opened successfully with <a href="FS.md#ga11b644a8526139c4cc1850dac1271ced">O_WRONLY</a> or <a href="FS.md#gabb0586253488ee61072b73557eeb873b">O_RDWR</a>, its length is truncated to 0. </p>
</td>
</tr>
<tr id="row283576393165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p291662128165621"><a name="p291662128165621"></a><a name="p291662128165621"></a>O_EXCL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1342747679165621"><a name="p1342747679165621"></a><a name="p1342747679165621"></a>Used together with <strong id="b1945022016165621"><a name="b1945022016165621"></a><a name="b1945022016165621"></a>O_CREAT</strong>. This function fails if the file exists. </p>
</td>
</tr>
<tr id="row1504304543165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p532597298165621"><a name="p532597298165621"></a><a name="p532597298165621"></a>O_DIRECTORY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1916839809165621"><a name="p1916839809165621"></a><a name="p1916839809165621"></a>This flag must be added for opening a directory. Otherwise, the directory fails to be opened. </p>
</td>
</tr>
</tbody>
</table>

**Attention:**

This function can NOT be used in the PROC file system to create a file. This function is used to open a file. If the file does not exist, this function creates a file and opens it. 

**Returns:**

Returns the file descriptor if the file is opened successfully; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table826222052165621"></a>
<table><thead align="left"><tr id="row552449925165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1733964222165621"><a name="p1733964222165621"></a><a name="p1733964222165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p155258047165621"><a name="p155258047165621"></a><a name="p155258047165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row350264897165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p705030813165621"><a name="p705030813165621"></a><a name="p705030813165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1911174719165621"><a name="p1911174719165621"></a><a name="p1911174719165621"></a>Search permission is denied on a component of the path prefix. </p>
</td>
</tr>
<tr id="row499978853165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1354453140165621"><a name="p1354453140165621"></a><a name="p1354453140165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1419278633165621"><a name="p1419278633165621"></a><a name="p1419278633165621"></a>The path name format is invalid. </p>
</td>
</tr>
<tr id="row2089678549165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1729844851165621"><a name="p1729844851165621"></a><a name="p1729844851165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1590434980165621"><a name="p1590434980165621"></a><a name="p1590434980165621"></a>The length of <strong id="b756824948165621"><a name="b756824948165621"></a><a name="b756824948165621"></a>path</strong> is greater than the value of <a href="UTILS.md#gac64541bdd81c961304b9babef1402640">NAME_MAX</a>. </p>
</td>
</tr>
<tr id="row1874104073165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2045461416165621"><a name="p2045461416165621"></a><a name="p2045461416165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1984147977165621"><a name="p1984147977165621"></a><a name="p1984147977165621"></a>The <strong id="b649106615165621"><a name="b649106615165621"></a><a name="b649106615165621"></a>O_CREAT</strong> flag is not set and the named file does not exist. </p>
</td>
</tr>
<tr id="row718990672165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1782202511165621"><a name="p1782202511165621"></a><a name="p1782202511165621"></a>ENXIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p962368330165621"><a name="p962368330165621"></a><a name="p962368330165621"></a>Inode is invalid, not a normal character driver, or not a mount point. </p>
</td>
</tr>
<tr id="row274040171165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1339339001165621"><a name="p1339339001165621"></a><a name="p1339339001165621"></a>EMFILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1234598543165621"><a name="p1234598543165621"></a><a name="p1234598543165621"></a>All available file descriptors of the process are opened. </p>
</td>
</tr>
<tr id="row1395507649165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1887144654165621"><a name="p1887144654165621"></a><a name="p1887144654165621"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14526438165621"><a name="p14526438165621"></a><a name="p14526438165621"></a>The file structure corresponding to the file descriptor cannot be obtained. </p>
</td>
</tr>
<tr id="row1674428925165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p192843858165621"><a name="p192843858165621"></a><a name="p192843858165621"></a>EEXIST </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p552810205165621"><a name="p552810205165621"></a><a name="p552810205165621"></a><strong id="b1609621137165621"><a name="b1609621137165621"></a><a name="b1609621137165621"></a>O_CREAT</strong> and <strong id="b346799527165621"><a name="b346799527165621"></a><a name="b346799527165621"></a>O_EXCL</strong> are set. </p>
</td>
</tr>
<tr id="row1822409485165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1609782718165621"><a name="p1609782718165621"></a><a name="p1609782718165621"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p916632109165621"><a name="p916632109165621"></a><a name="p916632109165621"></a>A hardware error occurs at the low-level disk I/O layer. As a result, the physical drive cannot work. </p>
</td>
</tr>
<tr id="row248448577165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1801696714165621"><a name="p1801696714165621"></a><a name="p1801696714165621"></a>EROFS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1990188011165621"><a name="p1990188011165621"></a><a name="p1990188011165621"></a>The named file resides on a read-only file system, and either <a href="FS.md#ga11b644a8526139c4cc1850dac1271ced">O_WRONLY</a>, <a href="FS.md#gabb0586253488ee61072b73557eeb873b">O_RDWR</a>, <strong id="b1744231917165621"><a name="b1744231917165621"></a><a name="b1744231917165621"></a>O_CREAT</strong> (if file does not exist), or <strong id="b1017491883165621"><a name="b1017491883165621"></a><a name="b1017491883165621"></a>O_TRUNC</strong> is set in the <strong id="b238249095165621"><a name="b238249095165621"></a><a name="b238249095165621"></a>oflags</strong> parameter. </p>
</td>
</tr>
<tr id="row1798840312165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p886755372165621"><a name="p886755372165621"></a><a name="p886755372165621"></a>ENOSPC </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p605109732165621"><a name="p605109732165621"></a><a name="p605109732165621"></a>The directory or file system that would contain the new file cannot be expanded, the file does not exist, and <strong id="b1751877277165621"><a name="b1751877277165621"></a><a name="b1751877277165621"></a>O_CREAT</strong> is specified. </p>
</td>
</tr>
<tr id="row545330766165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2005620256165621"><a name="p2005620256165621"></a><a name="p2005620256165621"></a>ENFILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1261490186165621"><a name="p1261490186165621"></a><a name="p1261490186165621"></a>The number of opened files in the system has reached the maximum. </p>
</td>
</tr>
<tr id="row229884573165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1497106312165621"><a name="p1497106312165621"></a><a name="p1497106312165621"></a>EISDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p204271982165621"><a name="p204271982165621"></a><a name="p204271982165621"></a>The named file is a directory, and <strong id="b1955203360165621"><a name="b1955203360165621"></a><a name="b1955203360165621"></a>oflags</strong> includes <a href="FS.md#ga11b644a8526139c4cc1850dac1271ced">O_WRONLY</a>, <a href="FS.md#gabb0586253488ee61072b73557eeb873b">O_RDWR</a>, or <strong id="b351385920165621"><a name="b351385920165621"></a><a name="b351385920165621"></a>O_CREAT</strong> without <strong id="b1612451438165621"><a name="b1612451438165621"></a><a name="b1612451438165621"></a>O_DIRECTORY</strong>. </p>
</td>
</tr>
<tr id="row1570491596165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1354979189165621"><a name="p1354979189165621"></a><a name="p1354979189165621"></a>ENOTDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p116231719165621"><a name="p116231719165621"></a><a name="p116231719165621"></a>A component of the path prefix names an existing file that is not a directory. </p>
</td>
</tr>
<tr id="row1270937196165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1465076197165621"><a name="p1465076197165621"></a><a name="p1465076197165621"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p962184495165621"><a name="p962184495165621"></a><a name="p962184495165621"></a>The operation is rejected according to the file sharing policy. </p>
</td>
</tr>
<tr id="row234179337165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p810540809165621"><a name="p810540809165621"></a><a name="p810540809165621"></a>ENODEV </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p555497900165621"><a name="p555497900165621"></a><a name="p555497900165621"></a>The device does not exist. </p>
</td>
</tr>
<tr id="row975954360165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1576894909165621"><a name="p1576894909165621"></a><a name="p1576894909165621"></a>ENOTEMPTY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p36831344165621"><a name="p36831344165621"></a><a name="p36831344165621"></a>The directory is not empty. </p>
</td>
</tr>
<tr id="row292724392165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1548266540165621"><a name="p1548266540165621"></a><a name="p1548266540165621"></a>ELOOP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1619299461165621"><a name="p1619299461165621"></a><a name="p1619299461165621"></a>Too many symbolic links are encountered. </p>
</td>
</tr>
<tr id="row1389548911165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p708652249165621"><a name="p708652249165621"></a><a name="p708652249165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p298855157165621"><a name="p298855157165621"></a><a name="p298855157165621"></a>The IP address is incorrect. </p>
</td>
</tr>
</tbody>
</table>

## opendir\(\)<a name="gad09dd96447776d2bc5d8321e4b499591"></a>

```
[DIR](FS.md#ga0ebe68390948c14bb9d82987adbfc849)* opendir (const char * dirname)
```

 **Description:**

Opens a specified directory. 

**Parameters:**

<a name="table323106968165621"></a>
<table><thead align="left"><tr id="row1083624875165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p537774078165621"><a name="p537774078165621"></a><a name="p537774078165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2139808632165621"><a name="p2139808632165621"></a><a name="p2139808632165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row749879129165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dirname</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of directory to open. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the  **DIR**  structure representing the directory if it is opened successfully; returns  **NULL**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table2939535165621"></a>
<table><thead align="left"><tr id="row743169829165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p599399311165621"><a name="p599399311165621"></a><a name="p599399311165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p7006879165621"><a name="p7006879165621"></a><a name="p7006879165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row53042093165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1489561260165621"><a name="p1489561260165621"></a><a name="p1489561260165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1639327314165621"><a name="p1639327314165621"></a><a name="p1639327314165621"></a>The <strong id="b928301744165621"><a name="b928301744165621"></a><a name="b928301744165621"></a>dirname</strong> is empty. </p>
</td>
</tr>
<tr id="row1440446861165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1891814295165621"><a name="p1891814295165621"></a><a name="p1891814295165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p611034946165621"><a name="p611034946165621"></a><a name="p611034946165621"></a>The length of the path name string is longer than the value of <a href="UTILS.md#gac64541bdd81c961304b9babef1402640">NAME_MAX</a>. </p>
</td>
</tr>
<tr id="row627039665165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1955770802165621"><a name="p1955770802165621"></a><a name="p1955770802165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1593861034165621"><a name="p1593861034165621"></a><a name="p1593861034165621"></a>The path component does not exist. </p>
</td>
</tr>
<tr id="row146232141165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1985830655165621"><a name="p1985830655165621"></a><a name="p1985830655165621"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1102769726165621"><a name="p1102769726165621"></a><a name="p1102769726165621"></a>The storage memory is insufficient. </p>
</td>
</tr>
<tr id="row730858892165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p26037389165621"><a name="p26037389165621"></a><a name="p26037389165621"></a>ENOTDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p57118073165621"><a name="p57118073165621"></a><a name="p57118073165621"></a><strong id="b1751470268165621"><a name="b1751470268165621"></a><a name="b1751470268165621"></a> dirname </strong> is not a directory. </p>
</td>
</tr>
</tbody>
</table>

## readdir\(\)<a name="ga58257faf8b13b3f14558613c632b2373"></a>

```
struct [dirent](dirent.md)* readdir ([DIR](FS.md#ga0ebe68390948c14bb9d82987adbfc849) * dirp)
```

 **Description:**

Reads a specified directory. 

**Parameters:**

<a name="table304787689165621"></a>
<table><thead align="left"><tr id="row667422556165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p472020384165621"><a name="p472020384165621"></a><a name="p472020384165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1292592149165621"><a name="p1292592149165621"></a><a name="p1292592149165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row253030917165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dirp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the directory structure. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the  **dirent**  structure representing the directory if it is read successfully; returns  **NULL**  if reaching the end of the directory stream or the directory fails to be read. If the directory fails to be read, the corresponding error code is returned. 

<a name="table44010359165621"></a>
<table><thead align="left"><tr id="row944041580165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p955248492165621"><a name="p955248492165621"></a><a name="p955248492165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1232654756165621"><a name="p1232654756165621"></a><a name="p1232654756165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1412039773165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p187703820165621"><a name="p187703820165621"></a><a name="p187703820165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1286812133165621"><a name="p1286812133165621"></a><a name="p1286812133165621"></a>This feature is not supported by the file system. </p>
</td>
</tr>
<tr id="row1349961911165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1890180471165621"><a name="p1890180471165621"></a><a name="p1890180471165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p943436711165621"><a name="p943436711165621"></a><a name="p943436711165621"></a>The path name length is greater than the value of <a href="UTILS.md#gac64541bdd81c961304b9babef1402640">NAME_MAX</a>. </p>
</td>
</tr>
<tr id="row354374375165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p236725905165621"><a name="p236725905165621"></a><a name="p236725905165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1484991868165621"><a name="p1484991868165621"></a><a name="p1484991868165621"></a>The current position in the directory stream is invalid. </p>
</td>
</tr>
<tr id="row1093576965165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p638810172165621"><a name="p638810172165621"></a><a name="p638810172165621"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p890323952165621"><a name="p890323952165621"></a><a name="p890323952165621"></a><strong id="b150867958165621"><a name="b150867958165621"></a><a name="b150867958165621"></a>dirp</strong> is not an opened directory stream. </p>
</td>
</tr>
</tbody>
</table>

## readdir\_r\(\)<a name="ga9f1bc61c37394eda9e74e0c79afec872"></a>

```
int readdir_r ([DIR](FS.md#ga0ebe68390948c14bb9d82987adbfc849) *__restrict dirp, struct [dirent](dirent.md) *__restrict entry, struct [dirent](dirent.md) **__restrict result )
```

 **Description:**

Reads a specified directory \(thread-safe version\). 

**Parameters:**

<a name="table1995205673165621"></a>
<table><thead align="left"><tr id="row1735967385165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1975375469165621"><a name="p1975375469165621"></a><a name="p1975375469165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1498455614165621"><a name="p1498455614165621"></a><a name="p1498455614165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row147960334165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dirp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the directory structure. </td>
</tr>
<tr id="row2000719048165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">entry</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the entry read from the <strong id="b27419862165621"><a name="b27419862165621"></a><a name="b27419862165621"></a>dirp</strong> stream. </td>
</tr>
<tr id="row1861331229165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">result</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the returned buffer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**. If the directory fails to be read,  **errno**  is sets to a value in the following table. 

<a name="table1318977237165621"></a>
<table><thead align="left"><tr id="row2137154658165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1609637065165621"><a name="p1609637065165621"></a><a name="p1609637065165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1094388283165621"><a name="p1094388283165621"></a><a name="p1094388283165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row319374700165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1187074163165621"><a name="p1187074163165621"></a><a name="p1187074163165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1702149007165621"><a name="p1702149007165621"></a><a name="p1702149007165621"></a>This feature is not supported by the file system. </p>
</td>
</tr>
<tr id="row1998421018165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1748233073165621"><a name="p1748233073165621"></a><a name="p1748233073165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2025457705165621"><a name="p2025457705165621"></a><a name="p2025457705165621"></a>The path name length is greater than the value of <a href="UTILS.md#gac64541bdd81c961304b9babef1402640">NAME_MAX</a>. </p>
</td>
</tr>
<tr id="row377442944165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1671839101165621"><a name="p1671839101165621"></a><a name="p1671839101165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p86494824165621"><a name="p86494824165621"></a><a name="p86494824165621"></a>The current position in the directory stream is invalid. </p>
</td>
</tr>
<tr id="row521104835165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1040112274165621"><a name="p1040112274165621"></a><a name="p1040112274165621"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1124011039165621"><a name="p1124011039165621"></a><a name="p1124011039165621"></a><strong id="b152986776165621"><a name="b152986776165621"></a><a name="b152986776165621"></a>dirp</strong> is not an opened directory stream. </p>
</td>
</tr>
</tbody>
</table>

## rewinddir\(\)<a name="gad4fcb58b9194b1a3c1699654de963719"></a>

```
void rewinddir ([DIR](FS.md#ga0ebe68390948c14bb9d82987adbfc849) * dirp)
```

 **Description:**

Resets a directory stream read position. 

This function is used to change the current read position of the specified directory stream to the original read position \(that is, the start position after the directory stream is opened by  [opendir](FS.md#gad09dd96447776d2bc5d8321e4b499591)\). 

**Parameters:**

<a name="table195739908165621"></a>
<table><thead align="left"><tr id="row1037266424165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1855908908165621"><a name="p1855908908165621"></a><a name="p1855908908165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p348895140165621"><a name="p348895140165621"></a><a name="p348895140165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2076085666165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dirp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the directory stream whose read position needs to be reset. </td>
</tr>
</tbody>
</table>

<a name="table83981550165621"></a>
<table><thead align="left"><tr id="row1827907935165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p219522939165621"><a name="p219522939165621"></a><a name="p219522939165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2055731526165621"><a name="p2055731526165621"></a><a name="p2055731526165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1812402355165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1042881208165621"><a name="p1042881208165621"></a><a name="p1042881208165621"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1742961743165621"><a name="p1742961743165621"></a><a name="p1742961743165621"></a><strong id="b292116177165621"><a name="b292116177165621"></a><a name="b292116177165621"></a>dirp</strong> is not an opened directory stream. </p>
</td>
</tr>
</tbody>
</table>

## scandir\(\)<a name="gaca6df630e382cf13bac90ed6e5c4141c"></a>

```
int scandir (const char * dir, struct [dirent](dirent.md) *** namelist, int(*)(const struct [dirent](dirent.md) *) sel, int(*)(const struct [dirent](dirent.md) **, const struct [dirent](dirent.md) **) compar )
```

 **Description:**

Scans directory to find the target entries. 

**Parameters:**

<a name="table1703119377165621"></a>
<table><thead align="left"><tr id="row1662152033165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1973396988165621"><a name="p1973396988165621"></a><a name="p1973396988165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2075032419165621"><a name="p2075032419165621"></a><a name="p2075032419165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1272300154165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dir</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the directory to scan. </td>
</tr>
<tr id="row2067743242165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">namelist</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the array storing the directory entries filtered by the function referenced by the <strong id="b1668470688165621"><a name="b1668470688165621"></a><a name="b1668470688165621"></a>sel</strong> parameter. </td>
</tr>
<tr id="row307639012165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sel</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the filtering condition. You can customize the function referenced by this parameter. Value <strong id="b1692833362165621"><a name="b1692833362165621"></a><a name="b1692833362165621"></a>0</strong> is returned if the filtering condition is not met; a non-zero value is returned otherwise. </td>
</tr>
<tr id="row299205384165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">compar</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the function for sorting the directory entries. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of entries copied to the  **namelist**  array if the scanning is successful; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table1201433048165621"></a>
<table><thead align="left"><tr id="row1634794634165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1655482943165621"><a name="p1655482943165621"></a><a name="p1655482943165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1854569372165621"><a name="p1854569372165621"></a><a name="p1854569372165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row513102526165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1277753581165621"><a name="p1277753581165621"></a><a name="p1277753581165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1842091402165621"><a name="p1842091402165621"></a><a name="p1842091402165621"></a><strong id="b1722312526165621"><a name="b1722312526165621"></a><a name="b1722312526165621"></a>dir</strong> is empty. </p>
</td>
</tr>
<tr id="row2063500919165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p805640336165621"><a name="p805640336165621"></a><a name="p805640336165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1130944083165621"><a name="p1130944083165621"></a><a name="p1130944083165621"></a>The length of the path name string is greater than the value of <a href="UTILS.md#gac64541bdd81c961304b9babef1402640">NAME_MAX</a>. </p>
</td>
</tr>
<tr id="row404980351165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p421075722165621"><a name="p421075722165621"></a><a name="p421075722165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1102929030165621"><a name="p1102929030165621"></a><a name="p1102929030165621"></a>The directory component does not exist. </p>
</td>
</tr>
<tr id="row2018417453165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p489569081165621"><a name="p489569081165621"></a><a name="p489569081165621"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p970661295165621"><a name="p970661295165621"></a><a name="p970661295165621"></a>The storage memory is insufficient. </p>
</td>
</tr>
<tr id="row1738097640165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1662944569165621"><a name="p1662944569165621"></a><a name="p1662944569165621"></a>ENOTDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1466056600165621"><a name="p1466056600165621"></a><a name="p1466056600165621"></a><strong id="b1078087424165621"><a name="b1078087424165621"></a><a name="b1078087424165621"></a>dir</strong> is not a directory. </p>
</td>
</tr>
<tr id="row2002364101165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1569106444165621"><a name="p1569106444165621"></a><a name="p1569106444165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1938855130165621"><a name="p1938855130165621"></a><a name="p1938855130165621"></a>This feature is not supported by the file system. </p>
</td>
</tr>
</tbody>
</table>

## seekdir\(\)<a name="gacf0a74ce364760e330619edb38eadfff"></a>

```
void seekdir ([DIR](FS.md#ga0ebe68390948c14bb9d82987adbfc849) * dirp, long offset )
```

 **Description:**

Sets the position of the next  [readdir](FS.md#ga58257faf8b13b3f14558613c632b2373)  call in the directory stream. 

**Parameters:**

<a name="table1852547857165621"></a>
<table><thead align="left"><tr id="row1725894242165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1719713479165621"><a name="p1719713479165621"></a><a name="p1719713479165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p527148276165621"><a name="p527148276165621"></a><a name="p527148276165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1999432694165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dirp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the directory stream in which the position of the next <a href="FS.md#ga58257faf8b13b3f14558613c632b2373">readdir</a> call needs to be set. </td>
</tr>
<tr id="row1896640087165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">offset</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the offset of the position relative to the current position. </td>
</tr>
</tbody>
</table>

## stat\(\)<a name="gad2e0bcbe40344116102877f6268ee6ea"></a>

```
int [stat](stat.md) (const char *__restrict path, struct [stat](stat.md) *__restrict buf )
```

 **Description:**

Obtains file information. 

**Parameters:**

<a name="table2025778919165621"></a>
<table><thead align="left"><tr id="row1279892889165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p508576313165621"><a name="p508576313165621"></a><a name="p508576313165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1918608760165621"><a name="p1918608760165621"></a><a name="p1918608760165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1104628136165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">path</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file path. </td>
</tr>
<tr id="row718930811165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a <strong id="b1602351246165621"><a name="b1602351246165621"></a><a name="b1602351246165621"></a>stat</strong> structure into which file information is placed. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if file information is obtained successfully; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table1907036936165621"></a>
<table><thead align="left"><tr id="row1767012108165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p462530880165621"><a name="p462530880165621"></a><a name="p462530880165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1853055140165621"><a name="p1853055140165621"></a><a name="p1853055140165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row84098540165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2018136124165621"><a name="p2018136124165621"></a><a name="p2018136124165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p891673563165621"><a name="p891673563165621"></a><a name="p891673563165621"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row98497227165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p496579443165621"><a name="p496579443165621"></a><a name="p496579443165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p494983348165621"><a name="p494983348165621"></a><a name="p494983348165621"></a>A component of <strong id="b1833584366165621"><a name="b1833584366165621"></a><a name="b1833584366165621"></a>path</strong> does not name an existing file or <strong id="b228145811165621"><a name="b228145811165621"></a><a name="b228145811165621"></a>path</strong> is an empty string. </p>
</td>
</tr>
<tr id="row1491932378165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1976667954165621"><a name="p1976667954165621"></a><a name="p1976667954165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1931381814165621"><a name="p1931381814165621"></a><a name="p1931381814165621"></a>The path name length is greater than the value of <a href="UTILS.md#gac64541bdd81c961304b9babef1402640">NAME_MAX</a>. </p>
</td>
</tr>
<tr id="row305616610165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p933352120165621"><a name="p933352120165621"></a><a name="p933352120165621"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p315095004165621"><a name="p315095004165621"></a><a name="p315095004165621"></a>Insufficient memory. </p>
</td>
</tr>
<tr id="row447454046165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1748843139165621"><a name="p1748843139165621"></a><a name="p1748843139165621"></a>ENOSYS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1545977723165621"><a name="p1545977723165621"></a><a name="p1545977723165621"></a>The function is not supported. </p>
</td>
</tr>
<tr id="row1382629617165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1383043321165621"><a name="p1383043321165621"></a><a name="p1383043321165621"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1578565130165621"><a name="p1578565130165621"></a><a name="p1578565130165621"></a>The file list is null. </p>
</td>
</tr>
<tr id="row1639726236165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p886160885165621"><a name="p886160885165621"></a><a name="p886160885165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1812160020165621"><a name="p1812160020165621"></a><a name="p1812160020165621"></a>The permission bit of the file mode does not allow the requested access, or the search permission is denied on the path prefix component. </p>
</td>
</tr>
<tr id="row1437878106165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1744375672165621"><a name="p1744375672165621"></a><a name="p1744375672165621"></a>EEXIST </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p398002780165621"><a name="p398002780165621"></a><a name="p398002780165621"></a>The file or directory already exists. </p>
</td>
</tr>
<tr id="row1843937249165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1480147771165621"><a name="p1480147771165621"></a><a name="p1480147771165621"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p64473098165621"><a name="p64473098165621"></a><a name="p64473098165621"></a>An I/O error occurs when data is read from or written to the file system. </p>
</td>
</tr>
<tr id="row768252672165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1497696463165621"><a name="p1497696463165621"></a><a name="p1497696463165621"></a>EROFS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p113424169165621"><a name="p113424169165621"></a><a name="p113424169165621"></a>The physical drive is write-protected. </p>
</td>
</tr>
<tr id="row875150167165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1102662423165621"><a name="p1102662423165621"></a><a name="p1102662423165621"></a>ENOSPC </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p368179897165621"><a name="p368179897165621"></a><a name="p368179897165621"></a>No available space on the device. </p>
</td>
</tr>
<tr id="row2038999135165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p708038746165621"><a name="p708038746165621"></a><a name="p708038746165621"></a>ENFILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p161328540165621"><a name="p161328540165621"></a><a name="p161328540165621"></a>The number of opened files in the system has reached the maximum. </p>
</td>
</tr>
<tr id="row635858760165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1372110511165621"><a name="p1372110511165621"></a><a name="p1372110511165621"></a>ENOTEMPTY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1743655049165621"><a name="p1743655049165621"></a><a name="p1743655049165621"></a>The directory is not empty. </p>
</td>
</tr>
<tr id="row1208540149165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658814739165621"><a name="p658814739165621"></a><a name="p658814739165621"></a>EISDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p427162330165621"><a name="p427162330165621"></a><a name="p427162330165621"></a>The named file is a directory. </p>
</td>
</tr>
<tr id="row1244809819165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1858821509165621"><a name="p1858821509165621"></a><a name="p1858821509165621"></a>ENOTDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1525122273165621"><a name="p1525122273165621"></a><a name="p1525122273165621"></a>A component of the <strong id="b1636838650165621"><a name="b1636838650165621"></a><a name="b1636838650165621"></a>path</strong> prefix is the name of an existing file. The file is neither a directory nor a symbolic link of a directory. </p>
</td>
</tr>
<tr id="row1603885660165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p131556748165621"><a name="p131556748165621"></a><a name="p131556748165621"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p858165590165621"><a name="p858165590165621"></a><a name="p858165590165621"></a>Operation not permitted or access denied because the access is prohibited or the directory is full. </p>
</td>
</tr>
<tr id="row365486156165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1787978881165621"><a name="p1787978881165621"></a><a name="p1787978881165621"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p505140203165621"><a name="p505140203165621"></a><a name="p505140203165621"></a>The operation is rejected according to the file sharing policy. </p>
</td>
</tr>
<tr id="row1592862282165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p933241705165621"><a name="p933241705165621"></a><a name="p933241705165621"></a>EPROTO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1909740491165621"><a name="p1909740491165621"></a><a name="p1909740491165621"></a>The protocol in NFS is incorrect. </p>
</td>
</tr>
<tr id="row466329143165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1728001926165621"><a name="p1728001926165621"></a><a name="p1728001926165621"></a>ENODEV </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p743984539165621"><a name="p743984539165621"></a><a name="p743984539165621"></a>No such device. </p>
</td>
</tr>
<tr id="row1257930046165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1912703051165621"><a name="p1912703051165621"></a><a name="p1912703051165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1026603144165621"><a name="p1026603144165621"></a><a name="p1026603144165621"></a>Incorrect IP address. </p>
</td>
</tr>
</tbody>
</table>

## statfs\(\)<a name="gae7af18cc5fa39f42a3be1bf1eb24119d"></a>

```
int statfs (const char * path, struct statfs * buf )
```

 **Description:**

Obtains file system information of a file in a specified path. 

**Parameters:**

<a name="table1996438542165621"></a>
<table><thead align="left"><tr id="row220644246165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p415315302165621"><a name="p415315302165621"></a><a name="p415315302165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p935253869165621"><a name="p935253869165621"></a><a name="p935253869165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row391269919165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">path</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the target file. </td>
</tr>
<tr id="row1040844572165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a <strong id="b1133586208165621"><a name="b1133586208165621"></a><a name="b1133586208165621"></a>statfs</strong> structure that stores the information about the file system. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table86486157165621"></a>
<table><thead align="left"><tr id="row1983819744165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p593759384165621"><a name="p593759384165621"></a><a name="p593759384165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1412994419165621"><a name="p1412994419165621"></a><a name="p1412994419165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1140773029165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1591126312165621"><a name="p1591126312165621"></a><a name="p1591126312165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p165267647165621"><a name="p165267647165621"></a><a name="p165267647165621"></a>Search permission is denied on a component of the path prefix. </p>
</td>
</tr>
<tr id="row1357243058165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1684425630165621"><a name="p1684425630165621"></a><a name="p1684425630165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1482387268165621"><a name="p1482387268165621"></a><a name="p1482387268165621"></a><strong id="b246936938165621"><a name="b246936938165621"></a><a name="b246936938165621"></a>buf</strong> or <strong id="b249875514165621"><a name="b249875514165621"></a><a name="b249875514165621"></a>path</strong> points to an invalid address. </p>
</td>
</tr>
<tr id="row1969902419165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p702225269165621"><a name="p702225269165621"></a><a name="p702225269165621"></a>EINTR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1674865419165621"><a name="p1674865419165621"></a><a name="p1674865419165621"></a>The function call was interrupted by a signal. </p>
</td>
</tr>
<tr id="row1007145951165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1289464926165621"><a name="p1289464926165621"></a><a name="p1289464926165621"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1187563887165621"><a name="p1187563887165621"></a><a name="p1187563887165621"></a>An I/O error occurred while reading from the file system. </p>
</td>
</tr>
<tr id="row427931887165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p146804410165621"><a name="p146804410165621"></a><a name="p146804410165621"></a>ELOOP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1538830086165621"><a name="p1538830086165621"></a><a name="p1538830086165621"></a>Too many symbolic links were found. </p>
</td>
</tr>
<tr id="row392576057165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1298533031165621"><a name="p1298533031165621"></a><a name="p1298533031165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p127151038165621"><a name="p127151038165621"></a><a name="p127151038165621"></a><strong id="b2061122265165621"><a name="b2061122265165621"></a><a name="b2061122265165621"></a>path</strong> is too long. </p>
</td>
</tr>
<tr id="row1905770618165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p980323350165621"><a name="p980323350165621"></a><a name="p980323350165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1064565289165621"><a name="p1064565289165621"></a><a name="p1064565289165621"></a>The file referred to by <strong id="b1572373196165621"><a name="b1572373196165621"></a><a name="b1572373196165621"></a>path</strong> does not exist. </p>
</td>
</tr>
<tr id="row768763710165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1253047337165621"><a name="p1253047337165621"></a><a name="p1253047337165621"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p669643941165621"><a name="p669643941165621"></a><a name="p669643941165621"></a>Insufficient memory. </p>
</td>
</tr>
<tr id="row421581028165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1863789319165621"><a name="p1863789319165621"></a><a name="p1863789319165621"></a>ENOSYS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1755091090165621"><a name="p1755091090165621"></a><a name="p1755091090165621"></a>The operation is not supported. </p>
</td>
</tr>
<tr id="row1504921479165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1872826003165621"><a name="p1872826003165621"></a><a name="p1872826003165621"></a>ENOTDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2002374607165621"><a name="p2002374607165621"></a><a name="p2002374607165621"></a>A component of the path prefix of <strong id="b754159516165621"><a name="b754159516165621"></a><a name="b754159516165621"></a>path</strong> is not a directory. </p>
</td>
</tr>
<tr id="row1096012106165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p407609314165621"><a name="p407609314165621"></a><a name="p407609314165621"></a>EOVERFLOW </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1933472103165621"><a name="p1933472103165621"></a><a name="p1933472103165621"></a>Information overflow </p>
</td>
</tr>
</tbody>
</table>

## statvfs\(\)<a name="ga41058769ad8ea7d7d467799f651b8b1a"></a>

```
int [statvfs](statvfs.md) (const char *__restrict path, struct [statvfs](statvfs.md) *__restrict buf )
```

 **Description:**

Obtains the file system information. 

**Parameters:**

<a name="table1963242587165621"></a>
<table><thead align="left"><tr id="row758444970165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p708914619165621"><a name="p708914619165621"></a><a name="p708914619165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p275204725165621"><a name="p275204725165621"></a><a name="p275204725165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row563984149165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">path</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the path name of the file. </td>
</tr>
<tr id="row411999672165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b674664465165621"><a name="b674664465165621"></a><a name="b674664465165621"></a>statvfs</strong> structure that stores the obtained file system information. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the file system information is obtained successfully; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table133013004165621"></a>
<table><thead align="left"><tr id="row1154105302165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1864091957165621"><a name="p1864091957165621"></a><a name="p1864091957165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1204294566165621"><a name="p1204294566165621"></a><a name="p1204294566165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1853804656165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1189657956165621"><a name="p1189657956165621"></a><a name="p1189657956165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p79663349165621"><a name="p79663349165621"></a><a name="p79663349165621"></a>Search permission is denied on a component of the path prefix. </p>
</td>
</tr>
<tr id="row244406532165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1255545354165621"><a name="p1255545354165621"></a><a name="p1255545354165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p869230810165621"><a name="p869230810165621"></a><a name="p869230810165621"></a><strong id="b1236480739165621"><a name="b1236480739165621"></a><a name="b1236480739165621"></a>buf</strong> or <strong id="b1819596382165621"><a name="b1819596382165621"></a><a name="b1819596382165621"></a>path</strong> points to an invalid address. </p>
</td>
</tr>
<tr id="row2106626391165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p219077994165621"><a name="p219077994165621"></a><a name="p219077994165621"></a>EINTR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1311562190165621"><a name="p1311562190165621"></a><a name="p1311562190165621"></a>This call was interrupted by a signal. </p>
</td>
</tr>
<tr id="row1247945326165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2097398391165621"><a name="p2097398391165621"></a><a name="p2097398391165621"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p531715912165621"><a name="p531715912165621"></a><a name="p531715912165621"></a>An I/O error occurred while reading from the file system. </p>
</td>
</tr>
<tr id="row377030832165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1673021425165621"><a name="p1673021425165621"></a><a name="p1673021425165621"></a>ELOOP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p340389256165621"><a name="p340389256165621"></a><a name="p340389256165621"></a>Too many symbolic links were found. </p>
</td>
</tr>
<tr id="row700831043165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p622324515165621"><a name="p622324515165621"></a><a name="p622324515165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1608220525165621"><a name="p1608220525165621"></a><a name="p1608220525165621"></a><strong id="b1167051078165621"><a name="b1167051078165621"></a><a name="b1167051078165621"></a>path</strong> is too long. </p>
</td>
</tr>
<tr id="row66600060165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1732631061165621"><a name="p1732631061165621"></a><a name="p1732631061165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1257446100165621"><a name="p1257446100165621"></a><a name="p1257446100165621"></a>The file specified by <strong id="b238045397165621"><a name="b238045397165621"></a><a name="b238045397165621"></a>path</strong> does not exist. </p>
</td>
</tr>
<tr id="row566523852165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p503123301165621"><a name="p503123301165621"></a><a name="p503123301165621"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p459361881165621"><a name="p459361881165621"></a><a name="p459361881165621"></a>Insufficient memory. </p>
</td>
</tr>
<tr id="row939491602165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1041517995165621"><a name="p1041517995165621"></a><a name="p1041517995165621"></a>ENOSYS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p356717909165621"><a name="p356717909165621"></a><a name="p356717909165621"></a>The file system does not support this call. </p>
</td>
</tr>
<tr id="row695251200165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p673552903165621"><a name="p673552903165621"></a><a name="p673552903165621"></a>ENOTDIR </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p361708973165621"><a name="p361708973165621"></a><a name="p361708973165621"></a>A component of the path prefix of <strong id="b454459437165621"><a name="b454459437165621"></a><a name="b454459437165621"></a>path</strong> is not a directory. </p>
</td>
</tr>
<tr id="row296542298165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2074339779165621"><a name="p2074339779165621"></a><a name="p2074339779165621"></a>EOVERFLOW </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1259901905165621"><a name="p1259901905165621"></a><a name="p1259901905165621"></a>Information overflows. </p>
</td>
</tr>
</tbody>
</table>

## telldir\(\)<a name="ga4c2cd02bd612ae655782632c9f5227ec"></a>

```
long telldir ([DIR](FS.md#ga0ebe68390948c14bb9d82987adbfc849) * dirp)
```

 **Description:**

Obtains the current position in the specified directory stream. 

**Parameters:**

<a name="table507122790165621"></a>
<table><thead align="left"><tr id="row982452568165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1602771796165621"><a name="p1602771796165621"></a><a name="p1602771796165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p593257200165621"><a name="p593257200165621"></a><a name="p593257200165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1147458190165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dirp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the directory stream. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the current position in the directory stream if the operation is successful; returns  **-1**  and sets  **errno**  to the value in the following table otherwise. 

<a name="table724160139165621"></a>
<table><thead align="left"><tr id="row1429226919165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p366706556165621"><a name="p366706556165621"></a><a name="p366706556165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1725757584165621"><a name="p1725757584165621"></a><a name="p1725757584165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row751670522165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p394330242165621"><a name="p394330242165621"></a><a name="p394330242165621"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1928798274165621"><a name="p1928798274165621"></a><a name="p1928798274165621"></a><strong id="b1835907982165621"><a name="b1835907982165621"></a><a name="b1835907982165621"></a>drip</strong> is not an opened directory stream. </p>
</td>
</tr>
</tbody>
</table>

## umask\(\)<a name="ga556063623e479c26c64544024a046024"></a>

```
mode_t umask (mode_t mode)
```

 **Description:**

Sets umask for a process. 

This function sets the umask of the current process file and returns the previous value of the umask. umask is used to turn off permission bits corresponding to in the  **mode**  parameter. 

**Parameters:**

<a name="table945718771165621"></a>
<table><thead align="left"><tr id="row1901556185165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p600182499165621"><a name="p600182499165621"></a><a name="p600182499165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p395117860165621"><a name="p395117860165621"></a><a name="p395117860165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1428910611165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Used to specify the umask value of a process. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the previous value of the umask. This function call always succeeds. 

## umount\(\)<a name="ga44634cfa8bcc732c29bcdf5822095422"></a>

```
int umount (const char * target)
```

 **Description:**

Unmounts a file system. 

**Parameters:**

<a name="table1264940071165621"></a>
<table><thead align="left"><tr id="row1434348428165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2126831668165621"><a name="p2126831668165621"></a><a name="p2126831668165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2091263393165621"><a name="p2091263393165621"></a><a name="p2091263393165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row579517460165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">target</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the path of the file system to unmount. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the file system is unmounted successfully; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table950946690165621"></a>
<table><thead align="left"><tr id="row1699602898165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1307921852165621"><a name="p1307921852165621"></a><a name="p1307921852165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1965190704165621"><a name="p1965190704165621"></a><a name="p1965190704165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1375122833165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1330251889165621"><a name="p1330251889165621"></a><a name="p1330251889165621"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p167026957165621"><a name="p167026957165621"></a><a name="p167026957165621"></a><strong id="b383920578165621"><a name="b383920578165621"></a><a name="b383920578165621"></a>target</strong> could not be unmounted because it is busy. </p>
</td>
</tr>
<tr id="row769978302165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p232189091165621"><a name="p232189091165621"></a><a name="p232189091165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1902457154165621"><a name="p1902457154165621"></a><a name="p1902457154165621"></a><strong id="b1273784377165621"><a name="b1273784377165621"></a><a name="b1273784377165621"></a>target</strong> points outside the user address space. </p>
</td>
</tr>
<tr id="row88156269165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1826710582165621"><a name="p1826710582165621"></a><a name="p1826710582165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p108849106165621"><a name="p108849106165621"></a><a name="p108849106165621"></a><strong id="b1633412095165621"><a name="b1633412095165621"></a><a name="b1633412095165621"></a>target</strong> is not a mount point. </p>
</td>
</tr>
<tr id="row2115991093165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p314385309165621"><a name="p314385309165621"></a><a name="p314385309165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p65598911165621"><a name="p65598911165621"></a><a name="p65598911165621"></a>The path length is greater than the value of <strong id="b1827377929165621"><a name="b1827377929165621"></a><a name="b1827377929165621"></a>MAXPATHLEN</strong>. </p>
</td>
</tr>
<tr id="row244097759165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1679858400165621"><a name="p1679858400165621"></a><a name="p1679858400165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1573237070165621"><a name="p1573237070165621"></a><a name="p1573237070165621"></a>A path name is null or has a nonexistent component. </p>
</td>
</tr>
<tr id="row1374228786165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p671964317165621"><a name="p671964317165621"></a><a name="p671964317165621"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1418027462165621"><a name="p1418027462165621"></a><a name="p1418027462165621"></a>Insufficient memory. </p>
</td>
</tr>
<tr id="row1369755941165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1065073379165621"><a name="p1065073379165621"></a><a name="p1065073379165621"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p338442431165621"><a name="p338442431165621"></a><a name="p338442431165621"></a>No permission. </p>
</td>
</tr>
</tbody>
</table>

## umount2\(\)<a name="ga2125a021d10f7a28a66cbc9335ad826f"></a>

```
int umount2 (const char * target, int flags )
```

 **Description:**

Unmounts a file system. 

This function is used to unmount a file system. Currently, the value of  **flags**  can only be  **0**. In this case, this function is the same as  **[umount\(\)](FS.md#ga44634cfa8bcc732c29bcdf5822095422)**. 

**Parameters:**

<a name="table1941365296165621"></a>
<table><thead align="left"><tr id="row1468455943165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1882401623165621"><a name="p1882401623165621"></a><a name="p1882401623165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p985665741165621"><a name="p985665741165621"></a><a name="p985665741165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row241244371165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">target</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the path of the file system to unmount. </td>
</tr>
<tr id="row618880714165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the control flag. (Currently, the value of <strong id="b1268477379165621"><a name="b1268477379165621"></a><a name="b1268477379165621"></a>flags</strong> can only be <strong id="b1700716859165621"><a name="b1700716859165621"></a><a name="b1700716859165621"></a>0</strong>. In this case, this function is the same as <strong id="b1693710257165621"><a name="b1693710257165621"></a><a name="b1693710257165621"></a><a href="FS.md#ga44634cfa8bcc732c29bcdf5822095422">umount()</a></strong>.) </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the file system is unmounted successfully; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table1418811228165621"></a>
<table><thead align="left"><tr id="row1498604170165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p375741700165621"><a name="p375741700165621"></a><a name="p375741700165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p378008398165621"><a name="p378008398165621"></a><a name="p378008398165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row591143650165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p271301079165621"><a name="p271301079165621"></a><a name="p271301079165621"></a>EBUSY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p175469125165621"><a name="p175469125165621"></a><a name="p175469125165621"></a><strong id="b1205700573165621"><a name="b1205700573165621"></a><a name="b1205700573165621"></a>target</strong> could not be unmounted because it is busy. </p>
</td>
</tr>
<tr id="row1815153653165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2108101141165621"><a name="p2108101141165621"></a><a name="p2108101141165621"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1660216174165621"><a name="p1660216174165621"></a><a name="p1660216174165621"></a><strong id="b654729887165621"><a name="b654729887165621"></a><a name="b654729887165621"></a>target</strong> points outside the user address space. </p>
</td>
</tr>
<tr id="row1349766847165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1256423612165621"><a name="p1256423612165621"></a><a name="p1256423612165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p844327673165621"><a name="p844327673165621"></a><a name="p844327673165621"></a><strong id="b1684273775165621"><a name="b1684273775165621"></a><a name="b1684273775165621"></a>target</strong> is not a mount point or <strong id="b1117721321165621"><a name="b1117721321165621"></a><a name="b1117721321165621"></a>flags</strong> value is not 0. </p>
</td>
</tr>
<tr id="row707046498165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p135819072165621"><a name="p135819072165621"></a><a name="p135819072165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1180744962165621"><a name="p1180744962165621"></a><a name="p1180744962165621"></a>The path length is greater than the value of <strong id="b1304153597165621"><a name="b1304153597165621"></a><a name="b1304153597165621"></a>MAXPATHLEN</strong>. </p>
</td>
</tr>
<tr id="row1190923688165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1555726545165621"><a name="p1555726545165621"></a><a name="p1555726545165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1663152546165621"><a name="p1663152546165621"></a><a name="p1663152546165621"></a>A path name is null or has a nonexistent component. </p>
</td>
</tr>
<tr id="row856862756165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p500200342165621"><a name="p500200342165621"></a><a name="p500200342165621"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p403576335165621"><a name="p403576335165621"></a><a name="p403576335165621"></a>Insufficient memory. </p>
</td>
</tr>
<tr id="row710442638165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1626495155165621"><a name="p1626495155165621"></a><a name="p1626495155165621"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1201501427165621"><a name="p1201501427165621"></a><a name="p1201501427165621"></a>No permission. </p>
</td>
</tr>
<tr id="row1131806292165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1574544505165621"><a name="p1574544505165621"></a><a name="p1574544505165621"></a>ENOSYS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1256706686165621"><a name="p1256706686165621"></a><a name="p1256706686165621"></a>The function call is not supported. (<strong id="b724184939165621"><a name="b724184939165621"></a><a name="b724184939165621"></a>flags</strong> value is not 0.) </p>
</td>
</tr>
</tbody>
</table>

## utime\(\)<a name="ga1299674b4b1934ebf0441388d07981a6"></a>

```
int utime (const char * filename, const struct [utimbuf](utimbuf.md) * times )
```

 **Description:**

Sets the access time and modification time of a file. 

**Parameters:**

<a name="table539062428165621"></a>
<table><thead align="left"><tr id="row446504456165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1238740378165621"><a name="p1238740378165621"></a><a name="p1238740378165621"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p667689305165621"><a name="p667689305165621"></a><a name="p667689305165621"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1209816433165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">filename</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the file whose access time and modification time need to be set. </td>
</tr>
<tr id="row652606441165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">times</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the time to which the access time and modification time are set. If <strong id="b1202637520165621"><a name="b1202637520165621"></a><a name="b1202637520165621"></a>times</strong> is a null pointer, then the access time and modification time are set to the current time. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the access time and modification time are set successfully; returns  **-1**  and sets  **errno**  to a value in the following table otherwise. 

<a name="table1533631072165621"></a>
<table><thead align="left"><tr id="row241068250165621"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1940722505165621"><a name="p1940722505165621"></a><a name="p1940722505165621"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1443120238165621"><a name="p1443120238165621"></a><a name="p1443120238165621"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row497102742165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1707330872165621"><a name="p1707330872165621"></a><a name="p1707330872165621"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2069096715165621"><a name="p2069096715165621"></a><a name="p2069096715165621"></a><strong id="b147796165621"><a name="b147796165621"></a><a name="b147796165621"></a>filename</strong> is null or <strong id="b988661523165621"><a name="b988661523165621"></a><a name="b988661523165621"></a>times</strong> is invalid. </p>
</td>
</tr>
<tr id="row1864548683165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p705300637165621"><a name="p705300637165621"></a><a name="p705300637165621"></a>ENAMETOOLONG </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p648451884165621"><a name="p648451884165621"></a><a name="p648451884165621"></a>The length of the component in the path name is greater than the value of <a href="UTILS.md#gac64541bdd81c961304b9babef1402640">NAME_MAX</a>. </p>
</td>
</tr>
<tr id="row2012872285165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1733327876165621"><a name="p1733327876165621"></a><a name="p1733327876165621"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p904525902165621"><a name="p904525902165621"></a><a name="p904525902165621"></a>Some paths do not exist. </p>
</td>
</tr>
<tr id="row1555448472165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p186440230165621"><a name="p186440230165621"></a><a name="p186440230165621"></a>ENOSYS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1185466513165621"><a name="p1185466513165621"></a><a name="p1185466513165621"></a>This function is not supported. </p>
</td>
</tr>
<tr id="row1956064196165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p605377680165621"><a name="p605377680165621"></a><a name="p605377680165621"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1849527040165621"><a name="p1849527040165621"></a><a name="p1849527040165621"></a>The file system is read-only. </p>
</td>
</tr>
<tr id="row1123324053165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p164935965165621"><a name="p164935965165621"></a><a name="p164935965165621"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p163466006165621"><a name="p163466006165621"></a><a name="p163466006165621"></a>Insufficient memory. </p>
</td>
</tr>
<tr id="row894034358165621"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p174763211165621"><a name="p174763211165621"></a><a name="p174763211165621"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1777802563165621"><a name="p1777802563165621"></a><a name="p1777802563165621"></a>A hardware error occurs at the underlying disk I/O layer. </p>
</td>
</tr>
</tbody>
</table>

