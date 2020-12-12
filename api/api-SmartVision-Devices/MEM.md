# MEM<a name="ZH-CN_TOPIC_0000001055189439"></a>

-   [Overview](#section360371676165622)
-   [Summary](#section1312273962165622)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)
-   [Details](#section694393684165622)
-   [Function](#section1544222630165622)
-   [calloc\(\)](#ga62b7798461bd461da64c5f9d35feddf7)
-   [free\(\)](#gafbedc913aa4651b3c3b4b3aecd9b4711)
-   [malloc\(\)](#ga7ac38fce3243a7dcf448301ee9ffd392)
-   [malloc\_usable\_size\(\)](#gaa011d7b7bfeba45c8c32e04204a0f565)
-   [memalign\(\)](#ga6a1c0668b7069bb45fd6e69f301ed5b9)
-   [mmap\(\)](#gadcdc6990a7641f7ba05f5dd2a603b992)
-   [mprotect\(\)](#gaa0752189f14ca11ba413fc944ae08b9c)
-   [mremap\(\)](#ga1b5acd27009fbbf05d18e90640f6ef64)
-   [munmap\(\)](#ga1343e4aa663c9e8bb7d1b16d367f0b08)
-   [realloc\(\)](#ga1a6b5e8d2f1c37e5b43e4345586075be)
-   [shmat\(\)](#gac56f61130bf1ddd88ecd6a2e87b4c5cb)
-   [shmctl\(\)](#gab2cfe9a9370d4c74b485876260e2e0fe)
-   [shmdt\(\)](#ga934738fcc6c27c0d45cff9bb8cc38a7f)
-   [shmget\(\)](#ga23e346182fc10c5286f37213e09fefb2)

## **Overview**<a name="section360371676165622"></a>

**Description:**

Provides structures and functions for performing memory operations, including memory mapping, remapping, allocation, and release. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1312273962165622"></a>

## Files<a name="files"></a>

<a name="table2109457426165622"></a>
<table><thead align="left"><tr id="row1795190966165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p649622129165622"><a name="p649622129165622"></a><a name="p649622129165622"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1700038472165622"><a name="p1700038472165622"></a><a name="p1700038472165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row48835559165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p299712806165622"><a name="p299712806165622"></a><a name="p299712806165622"></a><a href="malloc-h.md">malloc.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1951705125165622"><a name="p1951705125165622"></a><a name="p1951705125165622"></a>Declares APIs for allocating and releasing memory. </p>
</td>
</tr>
<tr id="row1377036847165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1419746954165622"><a name="p1419746954165622"></a><a name="p1419746954165622"></a><a href="mman-h.md">mman.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1112891114165622"><a name="p1112891114165622"></a><a name="p1112891114165622"></a>Declares structures and functions for performing memory operations, including memory mapping, remapping, unmapping, and attribute setting. </p>
</td>
</tr>
<tr id="row1905677759165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1142969758165622"><a name="p1142969758165622"></a><a name="p1142969758165622"></a><a href="shm-h.md">shm.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1836919881165622"><a name="p1836919881165622"></a><a name="p1836919881165622"></a>Declares APIs for creating, mapping, deleting, and controlling shared memory. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1677567809165622"></a>
<table><thead align="left"><tr id="row624159534165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1317366925165622"><a name="p1317366925165622"></a><a name="p1317366925165622"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1711817136165622"><a name="p1711817136165622"></a><a name="p1711817136165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1040495194165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2080952639165622"><a name="p2080952639165622"></a><a name="p2080952639165622"></a><a href="shmid_ds.md">shmid_ds</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p874801136165622"><a name="p874801136165622"></a><a name="p874801136165622"></a>Stores information about a shared memory segment. </p>
</td>
</tr>
<tr id="row1079532247165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p667594752165622"><a name="p667594752165622"></a><a name="p667594752165622"></a><a href="shminfo.md">shminfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p665965142165622"><a name="p665965142165622"></a><a name="p665965142165622"></a>Describes limitations and attributes of system-level shared memory. </p>
</td>
</tr>
<tr id="row1189654364165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1944448053165622"><a name="p1944448053165622"></a><a name="p1944448053165622"></a><a href="shm_info.md">shm_info</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p649892246165622"><a name="p649892246165622"></a><a name="p649892246165622"></a>Describes system resource information about the shared memory. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1068177096165622"></a>
<table><thead align="left"><tr id="row156233597165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1446088363165622"><a name="p1446088363165622"></a><a name="p1446088363165622"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1423718184165622"><a name="p1423718184165622"></a><a name="p1423718184165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1767115954165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1201892166165622"><a name="p1201892166165622"></a><a name="p1201892166165622"></a><em id="ga8523dcf952f6ff059a3bed717e4f1296"><a name="ga8523dcf952f6ff059a3bed717e4f1296"></a><a name="ga8523dcf952f6ff059a3bed717e4f1296"></a></em>MAP_FAILED    ((void *) -1)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p728275977165622"><a name="p728275977165622"></a><a name="p728275977165622"></a>Indicates the return value of functions such as <a href="MEM.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a> when the operation fails. </p>
</td>
</tr>
<tr id="row1681932256165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1511539737165622"><a name="p1511539737165622"></a><a name="p1511539737165622"></a><em id="ga57028962c2a7c0c802ca6613492f2ef3"><a name="ga57028962c2a7c0c802ca6613492f2ef3"></a><a name="ga57028962c2a7c0c802ca6613492f2ef3"></a></em>MAP_SHARED    0x01</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p431355803165622"><a name="p431355803165622"></a><a name="p431355803165622"></a>Indicates the mapping attribute that the updates to the mapping are visible to other processes mapping the same file and are carried through to the underlying file. This macro is used as an input parameter passed to functions such as <a href="MEM.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row435258109165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p194037293165622"><a name="p194037293165622"></a><a name="p194037293165622"></a><em id="ga398ef47a991a44389aa9818c98a28d24"><a name="ga398ef47a991a44389aa9818c98a28d24"></a><a name="ga398ef47a991a44389aa9818c98a28d24"></a></em>MAP_PRIVATE    0x02</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p441968564165622"><a name="p441968564165622"></a><a name="p441968564165622"></a>Indicates the mapping attribute that the updates to the mapping are not visible to other mapping processes and are not carried through to the underlying file. This macro is used as an input parameter passed to functions such as <a href="MEM.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row303187908165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1916516635165622"><a name="p1916516635165622"></a><a name="p1916516635165622"></a><em id="ga387ec707b30c5e78cf20a14517a63b96"><a name="ga387ec707b30c5e78cf20a14517a63b96"></a><a name="ga387ec707b30c5e78cf20a14517a63b96"></a></em>MAP_FIXED    0x10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1763820610165622"><a name="p1763820610165622"></a><a name="p1763820610165622"></a>Indicates the mapping attribute that specifies the mapping as fixed mapping. This macro is used as an input parameter passed to functions such as <a href="MEM.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row714861494165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p902407643165622"><a name="p902407643165622"></a><a name="p902407643165622"></a><em id="ga298ddbffafbe6cf941b92092edfb86a5"><a name="ga298ddbffafbe6cf941b92092edfb86a5"></a><a name="ga298ddbffafbe6cf941b92092edfb86a5"></a></em>MAP_ANON    0x20</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p549284760165622"><a name="p549284760165622"></a><a name="p549284760165622"></a>Indicates the mapping attribute that specifies the mapping as anonymous mapping without a specified file or device. This macro is used as an input parameter passed to functions such as <a href="MEM.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row927250666165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p441470890165622"><a name="p441470890165622"></a><a name="p441470890165622"></a><em id="gae4f86bff73414c5fc08c058f957212f0"><a name="gae4f86bff73414c5fc08c058f957212f0"></a><a name="gae4f86bff73414c5fc08c058f957212f0"></a></em>MAP_ANONYMOUS    <a href="MEM.md#ga298ddbffafbe6cf941b92092edfb86a5">MAP_ANON</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p509860793165622"><a name="p509860793165622"></a><a name="p509860793165622"></a>Indicates the mapping attribute that specifies the mapping as anonymous mapping without a specified file or device. This macro is the synonym for <a href="MEM.md#ga298ddbffafbe6cf941b92092edfb86a5">MAP_ANON</a> and is used as an input parameter passed to functions such as <a href="MEM.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row1318381425165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p680801453165622"><a name="p680801453165622"></a><a name="p680801453165622"></a><em id="ga6a982b48b8d3eb8eccd17e0d54ee5379"><a name="ga6a982b48b8d3eb8eccd17e0d54ee5379"></a><a name="ga6a982b48b8d3eb8eccd17e0d54ee5379"></a></em>PROT_NONE    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1385665819165622"><a name="p1385665819165622"></a><a name="p1385665819165622"></a>Indicates that no permission is granted to the current process for accessing the mapping area. This macro is used as an input parameter passed to functions such as <a href="MEM.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row1838994144165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1960559659165622"><a name="p1960559659165622"></a><a name="p1960559659165622"></a><em id="ga15bf68ce8b590838b3a5c0b639d8d519"><a name="ga15bf68ce8b590838b3a5c0b639d8d519"></a><a name="ga15bf68ce8b590838b3a5c0b639d8d519"></a></em>PROT_READ    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1517745094165622"><a name="p1517745094165622"></a><a name="p1517745094165622"></a>Indicates that the current process is granted the read permission on the mapping area. This macro is used as an input parameter passed to functions such as <a href="MEM.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row398378457165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p497598612165622"><a name="p497598612165622"></a><a name="p497598612165622"></a><em id="ga2a79c8ceefb8fc25a940ae07a3d94429"><a name="ga2a79c8ceefb8fc25a940ae07a3d94429"></a><a name="ga2a79c8ceefb8fc25a940ae07a3d94429"></a></em>PROT_WRITE    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1182109567165622"><a name="p1182109567165622"></a><a name="p1182109567165622"></a>Indicates that the current process is granted the write permission on the mapping area. This macro is used as an input parameter passed to functions such as <a href="MEM.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row298493923165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2061232468165622"><a name="p2061232468165622"></a><a name="p2061232468165622"></a><em id="ga77848f068638e916c72cd543f5ecb815"><a name="ga77848f068638e916c72cd543f5ecb815"></a><a name="ga77848f068638e916c72cd543f5ecb815"></a></em>PROT_EXEC    4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p504133683165622"><a name="p504133683165622"></a><a name="p504133683165622"></a>Indicates that the current process is granted the execute permission on the mapping area. This macro is used as an input parameter passed to functions such as <a href="MEM.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row1650998806165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2075394306165622"><a name="p2075394306165622"></a><a name="p2075394306165622"></a><em id="ga979a9c42ee569172c2017c522c17a0b1"><a name="ga979a9c42ee569172c2017c522c17a0b1"></a><a name="ga979a9c42ee569172c2017c522c17a0b1"></a></em>MREMAP_MAYMOVE    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1371509875165622"><a name="p1371509875165622"></a><a name="p1371509875165622"></a>Indicates the remapping attribute that allows the mapping to be relocated to a new address. This macro is used as an input parameter passed to functions such as <a href="MEM.md#ga1b5acd27009fbbf05d18e90640f6ef64">mremap()</a>. </p>
</td>
</tr>
<tr id="row1339379414165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p389753492165622"><a name="p389753492165622"></a><a name="p389753492165622"></a><em id="ga689fc9cb8e5f54526471e67573624af9"><a name="ga689fc9cb8e5f54526471e67573624af9"></a><a name="ga689fc9cb8e5f54526471e67573624af9"></a></em>MREMAP_FIXED    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p931255401165622"><a name="p931255401165622"></a><a name="p931255401165622"></a>Indicates the remapping attribute that specifies the mapping as fixed mapping. This macro is used as an input parameter passed to functions such as <a href="MEM.md#ga1b5acd27009fbbf05d18e90640f6ef64">mremap()</a>. </p>
</td>
</tr>
<tr id="row743882811165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p126916332165622"><a name="p126916332165622"></a><a name="p126916332165622"></a><em id="ga1f422a47c416c67470e3a0fb8b7529d8"><a name="ga1f422a47c416c67470e3a0fb8b7529d8"></a><a name="ga1f422a47c416c67470e3a0fb8b7529d8"></a></em>SHMLBA    4096</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1476354527165622"><a name="p1476354527165622"></a><a name="p1476354527165622"></a>Aligns the shared memory address. </p>
</td>
</tr>
<tr id="row665826146165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p41060608165622"><a name="p41060608165622"></a><a name="p41060608165622"></a><em id="ga45da2dbfb146e926c8fd842379c0362c"><a name="ga45da2dbfb146e926c8fd842379c0362c"></a><a name="ga45da2dbfb146e926c8fd842379c0362c"></a></em>SHM_R    0400</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1227587066165622"><a name="p1227587066165622"></a><a name="p1227587066165622"></a>Indicates that the shared memory segment is readable. This macro is used for setting the <strong id="b1736557865165622"><a name="b1736557865165622"></a><a name="b1736557865165622"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#ga23e346182fc10c5286f37213e09fefb2">shmget()</a>. </p>
</td>
</tr>
<tr id="row1822756300165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p202180366165622"><a name="p202180366165622"></a><a name="p202180366165622"></a><em id="gafd00993215ed6030ec817bf3615044d1"><a name="gafd00993215ed6030ec817bf3615044d1"></a><a name="gafd00993215ed6030ec817bf3615044d1"></a></em>SHM_W    0200</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p651232721165622"><a name="p651232721165622"></a><a name="p651232721165622"></a>Indicates that the shared memory segment is writable. This macro is used for setting the <strong id="b536713978165622"><a name="b536713978165622"></a><a name="b536713978165622"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#ga23e346182fc10c5286f37213e09fefb2">shmget()</a>. </p>
</td>
</tr>
<tr id="row2019924977165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1076825094165622"><a name="p1076825094165622"></a><a name="p1076825094165622"></a><em id="ga899e8ef0c4c33e2a5cc708c05c75429a"><a name="ga899e8ef0c4c33e2a5cc708c05c75429a"></a><a name="ga899e8ef0c4c33e2a5cc708c05c75429a"></a></em>SHM_RDONLY    010000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p263798480165622"><a name="p263798480165622"></a><a name="p263798480165622"></a>Indicates that the attached shared memory segment is read-only. This macro is used for setting the <strong id="b773922152165622"><a name="b773922152165622"></a><a name="b773922152165622"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#gac56f61130bf1ddd88ecd6a2e87b4c5cb">shmat()</a>. </p>
</td>
</tr>
<tr id="row1720685983165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p617690391165622"><a name="p617690391165622"></a><a name="p617690391165622"></a><em id="ga4ae5f621aa1333d9d5962c3e9d674a90"><a name="ga4ae5f621aa1333d9d5962c3e9d674a90"></a><a name="ga4ae5f621aa1333d9d5962c3e9d674a90"></a></em>SHM_RND    020000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1438319962165622"><a name="p1438319962165622"></a><a name="p1438319962165622"></a>Indicates that the shared memory address can be rounded to a value meeting the requirement (<a href="MEM.md#ga1f422a47c416c67470e3a0fb8b7529d8">SHMLBA</a>). This macro is used for setting the <strong id="b1643813591165622"><a name="b1643813591165622"></a><a name="b1643813591165622"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#gac56f61130bf1ddd88ecd6a2e87b4c5cb">shmat()</a>. </p>
</td>
</tr>
<tr id="row4205299165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2106555981165622"><a name="p2106555981165622"></a><a name="p2106555981165622"></a><em id="gab652a1a4737f9118a64a8fb74084ef7d"><a name="gab652a1a4737f9118a64a8fb74084ef7d"></a><a name="gab652a1a4737f9118a64a8fb74084ef7d"></a></em>SHM_REMAP    040000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1072365034165622"><a name="p1072365034165622"></a><a name="p1072365034165622"></a>Indicates that the memory segment can be remapped. This macro is used for setting the <strong id="b196990871165622"><a name="b196990871165622"></a><a name="b196990871165622"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#gac56f61130bf1ddd88ecd6a2e87b4c5cb">shmat()</a>. </p>
</td>
</tr>
<tr id="row877924427165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1926618457165622"><a name="p1926618457165622"></a><a name="p1926618457165622"></a><em id="ga0bb6454e0dd48a66376bfaa05170ce82"><a name="ga0bb6454e0dd48a66376bfaa05170ce82"></a><a name="ga0bb6454e0dd48a66376bfaa05170ce82"></a></em>SHM_EXEC    0100000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2139888089165622"><a name="p2139888089165622"></a><a name="p2139888089165622"></a>Indicates that the attached shared memory segment is executable. This macro is used for setting the <strong id="b2144979973165622"><a name="b2144979973165622"></a><a name="b2144979973165622"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#gac56f61130bf1ddd88ecd6a2e87b4c5cb">shmat()</a>. </p>
</td>
</tr>
<tr id="row2067430151165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p144167379165622"><a name="p144167379165622"></a><a name="p144167379165622"></a><em id="ga66735ad43f79860ccdd21888c3ead8cc"><a name="ga66735ad43f79860ccdd21888c3ead8cc"></a><a name="ga66735ad43f79860ccdd21888c3ead8cc"></a></em>SHM_LOCK    11</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2072358068165622"><a name="p2072358068165622"></a><a name="p2072358068165622"></a>Locks the shared memory segment in memory so that it cannot be swapped to the swap partition. This macro is used for setting the <strong id="b111061534165622"><a name="b111061534165622"></a><a name="b111061534165622"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#ga23e346182fc10c5286f37213e09fefb2">shmget()</a>. </p>
</td>
</tr>
<tr id="row1408475145165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1278356036165622"><a name="p1278356036165622"></a><a name="p1278356036165622"></a><em id="ga7497459fc5ebe82bbbdfa3809c938312"><a name="ga7497459fc5ebe82bbbdfa3809c938312"></a><a name="ga7497459fc5ebe82bbbdfa3809c938312"></a></em>SHM_UNLOCK    12</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1259955702165622"><a name="p1259955702165622"></a><a name="p1259955702165622"></a>Unlocks the shared memory segment. This macro is used for setting the <strong id="b1833640300165622"><a name="b1833640300165622"></a><a name="b1833640300165622"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#ga23e346182fc10c5286f37213e09fefb2">shmget()</a>. </p>
</td>
</tr>
<tr id="row1789026058165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2116167477165622"><a name="p2116167477165622"></a><a name="p2116167477165622"></a><em id="ga2e0f8c5b0fafab9f2602d19588d03e95"><a name="ga2e0f8c5b0fafab9f2602d19588d03e95"></a><a name="ga2e0f8c5b0fafab9f2602d19588d03e95"></a></em>SHM_STAT    (13 | (<a href="IPC.md#ga16a91ee69c3cb6bfec425e1bfd5edd18">IPC_STAT</a> &amp; 0x100))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1112506809165622"><a name="p1112506809165622"></a><a name="p1112506809165622"></a>Obtains a <a href="shmid_ds.md">shmid_ds</a> data structure. This macro is used for setting the <strong id="b446719513165622"><a name="b446719513165622"></a><a name="b446719513165622"></a>cmd</strong> parameter passed to <a href="MEM.md#gab2cfe9a9370d4c74b485876260e2e0fe">shmctl()</a>. </p>
</td>
</tr>
<tr id="row2008245166165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658340728165622"><a name="p658340728165622"></a><a name="p658340728165622"></a><em id="gafecb9e202431a631f42469c9ecbee99e"><a name="gafecb9e202431a631f42469c9ecbee99e"></a><a name="gafecb9e202431a631f42469c9ecbee99e"></a></em>SHM_INFO    14</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p852965764165622"><a name="p852965764165622"></a><a name="p852965764165622"></a>Obtains a <a href="shm_info.md">shm_info</a> data structure that includes system resource information about this shared memory segment. This macro is used for setting the <strong id="b1401106949165622"><a name="b1401106949165622"></a><a name="b1401106949165622"></a>cmd</strong> parameter passed to <a href="MEM.md#gab2cfe9a9370d4c74b485876260e2e0fe">shmctl()</a>. </p>
</td>
</tr>
<tr id="row584159648165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p537706109165622"><a name="p537706109165622"></a><a name="p537706109165622"></a><em id="ga9e7f0a6d71663d9173d9aae2a2f01220"><a name="ga9e7f0a6d71663d9173d9aae2a2f01220"></a><a name="ga9e7f0a6d71663d9173d9aae2a2f01220"></a></em>SHM_STAT_ANY    (15 | (<a href="IPC.md#ga16a91ee69c3cb6bfec425e1bfd5edd18">IPC_STAT</a> &amp; 0x100))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2084195973165622"><a name="p2084195973165622"></a><a name="p2084195973165622"></a>Obtains a <a href="shmid_ds.md">shmid_ds</a> data structure without permission check. This macro is used for setting the <strong id="b1491778536165622"><a name="b1491778536165622"></a><a name="b1491778536165622"></a>cmd</strong> parameter passed to <a href="MEM.md#gab2cfe9a9370d4c74b485876260e2e0fe">shmctl()</a>. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table57493749165622"></a>
<table><thead align="left"><tr id="row426891160165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1625315147165622"><a name="p1625315147165622"></a><a name="p1625315147165622"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1471797182165622"><a name="p1471797182165622"></a><a name="p1471797182165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1960591769165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1413042398165622"><a name="p1413042398165622"></a><a name="p1413042398165622"></a><a href="MEM.md#ga7ac38fce3243a7dcf448301ee9ffd392">malloc</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p393683557165622"><a name="p393683557165622"></a><a name="p393683557165622"></a>void * </p>
<p id="p1836584942165622"><a name="p1836584942165622"></a><a name="p1836584942165622"></a>Dynamically allocates a block of uninitialized memory with the specified size. </p>
</td>
</tr>
<tr id="row1528236422165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1450162425165622"><a name="p1450162425165622"></a><a name="p1450162425165622"></a><a href="MEM.md#ga62b7798461bd461da64c5f9d35feddf7">calloc</a> (size_t nmemb, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p801746890165622"><a name="p801746890165622"></a><a name="p801746890165622"></a>void * </p>
<p id="p1024111230165622"><a name="p1024111230165622"></a><a name="p1024111230165622"></a>Dynamically allocates multiple blocks of memory with the specified size. </p>
</td>
</tr>
<tr id="row581521821165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p992729097165622"><a name="p992729097165622"></a><a name="p992729097165622"></a><a href="MEM.md#ga1a6b5e8d2f1c37e5b43e4345586075be">realloc</a> (void *ptr, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1587600949165622"><a name="p1587600949165622"></a><a name="p1587600949165622"></a>void * </p>
<p id="p1175786988165622"><a name="p1175786988165622"></a><a name="p1175786988165622"></a>Changes the size of a previously allocated memory block pointed to by <strong id="b1596219871165622"><a name="b1596219871165622"></a><a name="b1596219871165622"></a>ptr</strong> to the specified size. </p>
</td>
</tr>
<tr id="row114858676165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p97407392165622"><a name="p97407392165622"></a><a name="p97407392165622"></a><a href="MEM.md#gafbedc913aa4651b3c3b4b3aecd9b4711">free</a> (void *ptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1710918332165622"><a name="p1710918332165622"></a><a name="p1710918332165622"></a>void </p>
<p id="p253675235165622"><a name="p253675235165622"></a><a name="p253675235165622"></a>Frees the memory space pointed to by <strong id="b1362591472165622"><a name="b1362591472165622"></a><a name="b1362591472165622"></a>ptr</strong>. </p>
</td>
</tr>
<tr id="row114398757165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1551774177165622"><a name="p1551774177165622"></a><a name="p1551774177165622"></a><a href="MEM.md#ga6a1c0668b7069bb45fd6e69f301ed5b9">memalign</a> (size_t alignment, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1662637436165622"><a name="p1662637436165622"></a><a name="p1662637436165622"></a>void * </p>
<p id="p976479769165622"><a name="p976479769165622"></a><a name="p976479769165622"></a>Allocates a block of memory with the specified size based on the given alignment mode. </p>
</td>
</tr>
<tr id="row1051878679165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1868814205165622"><a name="p1868814205165622"></a><a name="p1868814205165622"></a><a href="MEM.md#gaa011d7b7bfeba45c8c32e04204a0f565">malloc_usable_size</a> (void *ptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p668681764165622"><a name="p668681764165622"></a><a name="p668681764165622"></a>size_t </p>
<p id="p126489980165622"><a name="p126489980165622"></a><a name="p126489980165622"></a>Obtains the size of the memory block pointed to by <strong id="b2121922310165622"><a name="b2121922310165622"></a><a name="b2121922310165622"></a>ptr</strong>. </p>
</td>
</tr>
<tr id="row665717406165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1748819546165622"><a name="p1748819546165622"></a><a name="p1748819546165622"></a><a href="MEM.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap</a> (void *addr, size_t length, int prot, int flags, int fd, off_t offset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1367518830165622"><a name="p1367518830165622"></a><a name="p1367518830165622"></a>void * </p>
<p id="p1565294400165622"><a name="p1565294400165622"></a><a name="p1565294400165622"></a>Creates a mapping between the virtual address space of the calling process and a file or device. </p>
</td>
</tr>
<tr id="row992132531165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p746259922165622"><a name="p746259922165622"></a><a name="p746259922165622"></a><a href="MEM.md#ga1343e4aa663c9e8bb7d1b16d367f0b08">munmap</a> (void *addr, size_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1372262617165622"><a name="p1372262617165622"></a><a name="p1372262617165622"></a>int </p>
<p id="p198771055165622"><a name="p198771055165622"></a><a name="p198771055165622"></a>Removes all mappings for the specified virtual address space. </p>
</td>
</tr>
<tr id="row1805744006165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p982454305165622"><a name="p982454305165622"></a><a name="p982454305165622"></a><a href="MEM.md#gaa0752189f14ca11ba413fc944ae08b9c">mprotect</a> (void *addr, size_t len, int prot)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p602491876165622"><a name="p602491876165622"></a><a name="p602491876165622"></a>int </p>
<p id="p973190300165622"><a name="p973190300165622"></a><a name="p973190300165622"></a>Sets protection attributes for the memory pages contained in the memory region starting from <strong id="b404715873165622"><a name="b404715873165622"></a><a name="b404715873165622"></a>addr</strong> with the specified length. </p>
</td>
</tr>
<tr id="row683667121165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1484660541165622"><a name="p1484660541165622"></a><a name="p1484660541165622"></a><a href="MEM.md#ga1b5acd27009fbbf05d18e90640f6ef64">mremap</a> (void *old_address, size_t old_size, size_t new_size, int flags,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p145428228165622"><a name="p145428228165622"></a><a name="p145428228165622"></a>void * </p>
<p id="p626318515165622"><a name="p626318515165622"></a><a name="p626318515165622"></a>Remaps a virtual memory region. </p>
</td>
</tr>
<tr id="row620734404165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p448394020165622"><a name="p448394020165622"></a><a name="p448394020165622"></a><a href="MEM.md#gac56f61130bf1ddd88ecd6a2e87b4c5cb">shmat</a> (int shmid, const void *shmaddr, int shmflg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p248864540165622"><a name="p248864540165622"></a><a name="p248864540165622"></a>void * </p>
<p id="p1720098103165622"><a name="p1720098103165622"></a><a name="p1720098103165622"></a>Attaches the shared memory segment identified by <strong id="b79741236165622"><a name="b79741236165622"></a><a name="b79741236165622"></a>shmid</strong> to the address space of the current process. </p>
</td>
</tr>
<tr id="row228793558165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p908171966165622"><a name="p908171966165622"></a><a name="p908171966165622"></a><a href="MEM.md#gab2cfe9a9370d4c74b485876260e2e0fe">shmctl</a> (int shmid, int cmd, struct <a href="shmid_ds.md">shmid_ds</a> *buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p247278105165622"><a name="p247278105165622"></a><a name="p247278105165622"></a>int </p>
<p id="p1445062900165622"><a name="p1445062900165622"></a><a name="p1445062900165622"></a>Performs a control operation specified by the <strong id="b1633168138165622"><a name="b1633168138165622"></a><a name="b1633168138165622"></a>cmd</strong> parameter on the shared memory segment identified by <strong id="b506844839165622"><a name="b506844839165622"></a><a name="b506844839165622"></a>shmid</strong>. </p>
</td>
</tr>
<tr id="row506404088165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1038692233165622"><a name="p1038692233165622"></a><a name="p1038692233165622"></a><a href="MEM.md#ga934738fcc6c27c0d45cff9bb8cc38a7f">shmdt</a> (const void *shmaddr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2039935057165622"><a name="p2039935057165622"></a><a name="p2039935057165622"></a>int </p>
<p id="p572522104165622"><a name="p572522104165622"></a><a name="p572522104165622"></a>Detaches the shared memory segment attached to the address pointed to by <strong id="b1013220392165622"><a name="b1013220392165622"></a><a name="b1013220392165622"></a>shmaddr</strong> from the address space of the calling process. </p>
</td>
</tr>
<tr id="row688381765165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1049584499165622"><a name="p1049584499165622"></a><a name="p1049584499165622"></a><a href="MEM.md#ga23e346182fc10c5286f37213e09fefb2">shmget</a> (<a href="UTILS.md#ga4f8c894a6c2b415e55f3f858afd9e7f5">key_t</a> key, size_t size, int shmflg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1525311700165622"><a name="p1525311700165622"></a><a name="p1525311700165622"></a>int </p>
<p id="p1538200068165622"><a name="p1538200068165622"></a><a name="p1538200068165622"></a>Obtains or creates a shared memory segment with the specified size based on the ID specified by <strong id="b1329170514165622"><a name="b1329170514165622"></a><a name="b1329170514165622"></a>key</strong>. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section694393684165622"></a>

## **Function **<a name="section1544222630165622"></a>

## calloc\(\)<a name="ga62b7798461bd461da64c5f9d35feddf7"></a>

```
void* calloc (size_t nmemb, size_t size )
```

 **Description:**

Dynamically allocates multiple blocks of memory with the specified size. 

**Parameters:**

<a name="table1614535270165622"></a>
<table><thead align="left"><tr id="row480847582165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p13823133165622"><a name="p13823133165622"></a><a name="p13823133165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p512523328165622"><a name="p512523328165622"></a><a name="p512523328165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row237799212165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nmemb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of memory blocks to allocate. </td>
</tr>
<tr id="row2011732482165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the memory block to allocate, in bytes. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the allocated memory block if the operation is successful; returns  **NULL**  and sets  **errno**  to a value in the following table if the operation fails or  **nmemb**  or  **size**  is set to  **0**. 

<a name="table348783175165622"></a>
<table><thead align="left"><tr id="row90835399165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1838414292165622"><a name="p1838414292165622"></a><a name="p1838414292165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1739508492165622"><a name="p1739508492165622"></a><a name="p1739508492165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1213821821165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1119868401165622"><a name="p1119868401165622"></a><a name="p1119868401165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1550342199165622"><a name="p1550342199165622"></a><a name="p1550342199165622"></a>Insufficient memory. </p>
</td>
</tr>
</tbody>
</table>

## free\(\)<a name="gafbedc913aa4651b3c3b4b3aecd9b4711"></a>

```
void free (void * ptr)
```

 **Description:**

Frees the memory space pointed to by  **ptr**. 

**Parameters:**

<a name="table1463494542165622"></a>
<table><thead align="left"><tr id="row257837640165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p559136950165622"><a name="p559136950165622"></a><a name="p559136950165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1589110336165622"><a name="p1589110336165622"></a><a name="p1589110336165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row335569733165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a memory block previously allocated with <a href="UTILS.md#ga7ac38fce3243a7dcf448301ee9ffd392">malloc</a>, <a href="UTILS.md#ga62b7798461bd461da64c5f9d35feddf7">calloc</a> or <a href="UTILS.md#ga1a6b5e8d2f1c37e5b43e4345586075be">realloc</a>. </td>
</tr>
</tbody>
</table>

## malloc\(\)<a name="ga7ac38fce3243a7dcf448301ee9ffd392"></a>

```
void* malloc (size_t size)
```

 **Description:**

Dynamically allocates a block of uninitialized memory with the specified size. 

The allocated memory can be initialized by calling  [memset\(\)](UTILS.md#gace6ee45c30e71865e6eb635200379db9). 

**Parameters:**

<a name="table1356997389165622"></a>
<table><thead align="left"><tr id="row104345131165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1542102956165622"><a name="p1542102956165622"></a><a name="p1542102956165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1290907284165622"><a name="p1290907284165622"></a><a name="p1290907284165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1968756823165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the memory block to allocate, in bytes. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the allocated memory block if the operation is successful; returns  **NULL**  and sets  **errno**  to a value in the following table if the operation fails or  **size**  is set to  **0**. 

<a name="table1046084506165622"></a>
<table><thead align="left"><tr id="row1698791018165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1619020691165622"><a name="p1619020691165622"></a><a name="p1619020691165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1538664948165622"><a name="p1538664948165622"></a><a name="p1538664948165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row861895211165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p567430379165622"><a name="p567430379165622"></a><a name="p567430379165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p393864216165622"><a name="p393864216165622"></a><a name="p393864216165622"></a>Insufficient memory. </p>
</td>
</tr>
</tbody>
</table>

## malloc\_usable\_size\(\)<a name="gaa011d7b7bfeba45c8c32e04204a0f565"></a>

```
size_t malloc_usable_size (void * ptr)
```

 **Description:**

Obtains the size of the memory block pointed to by  **ptr**. 

**Parameters:**

<a name="table1824125528165622"></a>
<table><thead align="left"><tr id="row827444116165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p460194275165622"><a name="p460194275165622"></a><a name="p460194275165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p978448681165622"><a name="p978448681165622"></a><a name="p978448681165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2102427729165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a block of memory previously allocated by functions such as <a href="MEM.md#ga7ac38fce3243a7dcf448301ee9ffd392">malloc()</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of usable bytes in the block of allocated memory pointed to by  **ptr**; returns  **0**  if  **ptr**  is  **NULL**. 

**See also:**

[malloc\(\)](MEM.md#ga7ac38fce3243a7dcf448301ee9ffd392)  |  [calloc\(\)](MEM.md#ga62b7798461bd461da64c5f9d35feddf7)  |  [realloc\(\)](MEM.md#ga1a6b5e8d2f1c37e5b43e4345586075be) 

## memalign\(\)<a name="ga6a1c0668b7069bb45fd6e69f301ed5b9"></a>

```
void* memalign (size_t alignment, size_t size )
```

 **Description:**

Allocates a block of memory with the specified size based on the given alignment mode. 

The value of  **alignment**  must be a power of two. 

**Parameters:**

<a name="table2044736457165622"></a>
<table><thead align="left"><tr id="row835450243165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p332177636165622"><a name="p332177636165622"></a><a name="p332177636165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1343650528165622"><a name="p1343650528165622"></a><a name="p1343650528165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row82425514165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">alignment</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the alignment size of the allocated memory. </td>
</tr>
<tr id="row1689103119165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the memory block to allocate, in bytes. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the allocated memory block if the operation is successful; returns  **NULL**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1452571165622"></a>
<table><thead align="left"><tr id="row387304697165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p269357311165622"><a name="p269357311165622"></a><a name="p269357311165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p826293994165622"><a name="p826293994165622"></a><a name="p826293994165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row869603382165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p405688710165622"><a name="p405688710165622"></a><a name="p405688710165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1756533052165622"><a name="p1756533052165622"></a><a name="p1756533052165622"></a>Invalid alignment value (not a power of two). </p>
</td>
</tr>
<tr id="row1121059371165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p408292545165622"><a name="p408292545165622"></a><a name="p408292545165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1958532134165622"><a name="p1958532134165622"></a><a name="p1958532134165622"></a>Insufficient memory. </p>
</td>
</tr>
</tbody>
</table>

## mmap\(\)<a name="gadcdc6990a7641f7ba05f5dd2a603b992"></a>

```
void* mmap (void * addr, size_t length, int prot, int flags, int fd, off_t offset )
```

 **Description:**

Creates a mapping between the virtual address space of the calling process and a file or device. 

The start address for the mapping is specified by  **addr**, and the length to map is specified by  **length**. The contents of the mapping are initialized starting at  **offset**  with the specified  **length**  in the file referred to by the file descriptor  **fd**. 

**Parameters:**

<a name="table2044604063165622"></a>
<table><thead align="left"><tr id="row1506234139165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1401573757165622"><a name="p1401573757165622"></a><a name="p1401573757165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1250978066165622"><a name="p1250978066165622"></a><a name="p1250978066165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1240846759165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the start address of the mapping. If this parameter is <strong id="b308258614165622"><a name="b308258614165622"></a><a name="b308258614165622"></a>NULL</strong>, the kernel determines the address to start. </td>
</tr>
<tr id="row712328121165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">length</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the mapping, in bytes. </td>
</tr>
<tr id="row511840112165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">prot</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the permission to be granted on the mapping area. The permission to grant must not conflict with the open mode of the file. The value of this parameter is the bitwise OR combination of one or more of the following constants: </td>
</tr>
<tr id="row136375306165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Specifies whether updates are visible to other processes mapping the same segment, and whether updates are carried through to the underlying file. The following table describes available values. </td>
</tr>
<tr id="row487605653165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file or device to map. </td>
</tr>
<tr id="row1480479680165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">offset</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the offset into the file where the mapping will start. </td>
</tr>
</tbody>
</table>

<a name="table1286648838165622"></a>
<table><thead align="left"><tr id="row51930557165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p363502622165622"><a name="p363502622165622"></a><a name="p363502622165622"></a>prot </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p84965932165622"><a name="p84965932165622"></a><a name="p84965932165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row701246180165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p829006170165622"><a name="p829006170165622"></a><a name="p829006170165622"></a>PROT_EXEC </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2040192705165622"><a name="p2040192705165622"></a><a name="p2040192705165622"></a>Executable </p>
</td>
</tr>
<tr id="row1850254301165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2114914875165622"><a name="p2114914875165622"></a><a name="p2114914875165622"></a>PROT_READ </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1256854486165622"><a name="p1256854486165622"></a><a name="p1256854486165622"></a>Readable </p>
</td>
</tr>
<tr id="row1628003465165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p358321768165622"><a name="p358321768165622"></a><a name="p358321768165622"></a>PROT_WRITE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1125320121165622"><a name="p1125320121165622"></a><a name="p1125320121165622"></a>Writable </p>
</td>
</tr>
</tbody>
</table>

<a name="table1399886519165622"></a>
<table><thead align="left"><tr id="row1489175010165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1691723228165622"><a name="p1691723228165622"></a><a name="p1691723228165622"></a>flags </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p813983583165622"><a name="p813983583165622"></a><a name="p813983583165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1606539930165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p65756822165622"><a name="p65756822165622"></a><a name="p65756822165622"></a>MAP_SHARED </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p175414830165622"><a name="p175414830165622"></a><a name="p175414830165622"></a>Updates to the mapping are visible to other processes mapping the same file, and are carried through to the underlying file. </p>
</td>
</tr>
<tr id="row867574280165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p203437174165622"><a name="p203437174165622"></a><a name="p203437174165622"></a>MAP_PRIVATE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p908733054165622"><a name="p908733054165622"></a><a name="p908733054165622"></a>Updates to the mapping are invisible to other processes mapping the same file, and are not carried through to the underlying file. </p>
</td>
</tr>
<tr id="row1637236096165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2018899585165622"><a name="p2018899585165622"></a><a name="p2018899585165622"></a>MAP_ANONYMOUS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1998811747165622"><a name="p1998811747165622"></a><a name="p1998811747165622"></a>No file or device is specified for the mapping (anonymous mapping). Both <strong id="b1239982007165622"><a name="b1239982007165622"></a><a name="b1239982007165622"></a>fd</strong> and <strong id="b1170204406165622"><a name="b1170204406165622"></a><a name="b1170204406165622"></a>offset</strong> are ignored. </p>
</td>
</tr>
</tbody>
</table>

**Attention:**

If the file mapping is successful,  **fd**  cannot be closed before the mapping is deleted. \(This rule does not conform to the Portable Operating System Interface \(POSIX\) standard. You should pay special attention to this rule.\) 

 This function can only be used to mapping a file in the JFFS2/NFS/FAT/RAMFS file systems. 

**Returns:**

Returns the pointer to the address where the mapping is placed if the operation is successful; returns  [MAP\_FAILED](MEM.md#ga8523dcf952f6ff059a3bed717e4f1296)  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1711503961165622"></a>
<table><thead align="left"><tr id="row41578690165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1095555781165622"><a name="p1095555781165622"></a><a name="p1095555781165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1664467109165622"><a name="p1664467109165622"></a><a name="p1664467109165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row2045811361165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p891547811165622"><a name="p891547811165622"></a><a name="p891547811165622"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p888605772165622"><a name="p888605772165622"></a><a name="p888605772165622"></a>The file descriptor specified by <strong id="b498909535165622"><a name="b498909535165622"></a><a name="b498909535165622"></a>fd</strong> refers to a non-regular file. Or a file mapping was requested, but <strong id="b1849111595165622"><a name="b1849111595165622"></a><a name="b1849111595165622"></a>fd</strong> is not open for reading. <a href="MEM.md#ga57028962c2a7c0c802ca6613492f2ef3">MAP_SHARED</a> and <a href="MEM.md#ga2a79c8ceefb8fc25a940ae07a3d94429">PROT_WRITE</a> are specified, but the file identified by <strong id="b218609106165622"><a name="b218609106165622"></a><a name="b218609106165622"></a>fd</strong> is not opened in <a href="FS.md#gabb0586253488ee61072b73557eeb873b">O_RDWR</a> mode. <a href="MEM.md#ga2a79c8ceefb8fc25a940ae07a3d94429">PROT_WRITE</a> is specified, but the file is append-only. </p>
</td>
</tr>
<tr id="row182758652165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1381103922165622"><a name="p1381103922165622"></a><a name="p1381103922165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2097525044165622"><a name="p2097525044165622"></a><a name="p2097525044165622"></a>The file descriptor specified by <strong id="b61205233165622"><a name="b61205233165622"></a><a name="b61205233165622"></a>fd</strong> is invalid, and <a href="MEM.md#gae4f86bff73414c5fc08c058f957212f0">MAP_ANONYMOUS</a> is not specified in <strong id="b65945968165622"><a name="b65945968165622"></a><a name="b65945968165622"></a>flags</strong>. </p>
</td>
</tr>
<tr id="row255566757165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p795908314165622"><a name="p795908314165622"></a><a name="p795908314165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p508319585165622"><a name="p508319585165622"></a><a name="p508319585165622"></a>The length and offset are too large, <strong id="b1754902506165622"><a name="b1754902506165622"></a><a name="b1754902506165622"></a>addr</strong> is not page-aligned with MAP_FIXED, or the length is <strong id="b105274338165622"><a name="b105274338165622"></a><a name="b105274338165622"></a>0</strong>. Neither <a href="MEM.md#ga57028962c2a7c0c802ca6613492f2ef3">MAP_SHARED</a> nor <a href="MEM.md#ga398ef47a991a44389aa9818c98a28d24">MAP_PRIVATE</a> is specified in <strong id="b11157207165622"><a name="b11157207165622"></a><a name="b11157207165622"></a>flags</strong>, or both are specified. </p>
</td>
</tr>
<tr id="row358265037165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2116149695165622"><a name="p2116149695165622"></a><a name="p2116149695165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1524713203165622"><a name="p1524713203165622"></a><a name="p1524713203165622"></a>The file identified by <strong id="b1778980320165622"><a name="b1778980320165622"></a><a name="b1778980320165622"></a>fd</strong> has been locked. </p>
</td>
</tr>
<tr id="row326584108165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p374879592165622"><a name="p374879592165622"></a><a name="p374879592165622"></a>ENFILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1448115192165622"><a name="p1448115192165622"></a><a name="p1448115192165622"></a>The total number of open files exceeds the system limit. </p>
</td>
</tr>
<tr id="row754941448165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1178786157165622"><a name="p1178786157165622"></a><a name="p1178786157165622"></a>ENODEV </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1665650050165622"><a name="p1665650050165622"></a><a name="p1665650050165622"></a>The file identified by <strong id="b461891067165622"><a name="b461891067165622"></a><a name="b461891067165622"></a>fd</strong> does not support memory mapping. </p>
</td>
</tr>
<tr id="row1012669357165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1984303801165622"><a name="p1984303801165622"></a><a name="p1984303801165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p839235796165622"><a name="p839235796165622"></a><a name="p839235796165622"></a>Insufficient memory. </p>
</td>
</tr>
<tr id="row1549589130165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1489411072165622"><a name="p1489411072165622"></a><a name="p1489411072165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p106751662165622"><a name="p106751662165622"></a><a name="p106751662165622"></a><a href="MEM.md#ga77848f068638e916c72cd543f5ecb815">PROT_EXEC</a> is specified in <strong id="b557822562165622"><a name="b557822562165622"></a><a name="b557822562165622"></a>prot</strong>, but the mapped area belongs to a file on a file system that was mounted non-executable, or the file seal does not allow this operation. </p>
</td>
</tr>
</tbody>
</table>

## mprotect\(\)<a name="gaa0752189f14ca11ba413fc944ae08b9c"></a>

```
int mprotect (void * addr, size_t len, int prot )
```

 **Description:**

Sets protection attributes for the memory pages contained in the memory region starting from  **addr**  with the specified length. 

The address specified by  **addr**  must be page-aligned. If the process attempts to access memory in a manner that violates the protection attributes, an access exception will occur, and the process will be terminated. 

**Parameters:**

<a name="table35535901165622"></a>
<table><thead align="left"><tr id="row1479444183165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1616856374165622"><a name="p1616856374165622"></a><a name="p1616856374165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1088538971165622"><a name="p1088538971165622"></a><a name="p1088538971165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1476018949165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the start address of the memory region to modify, which must be a multiple of the page size. </td>
</tr>
<tr id="row1957160511165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the memory region to modify, in bytes. </td>
</tr>
<tr id="row1337786153165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">prot</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the permission of the memory region to modify, which can be a bitwise OR combination of one or more of the constants listed in <strong id="b1354486484165622"><a name="b1354486484165622"></a><a name="b1354486484165622"></a>prot</strong>. </td>
</tr>
</tbody>
</table>

<a name="table1732479612165622"></a>
<table><thead align="left"><tr id="row989164561165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p628729968165622"><a name="p628729968165622"></a><a name="p628729968165622"></a>prot </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p905781424165622"><a name="p905781424165622"></a><a name="p905781424165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1778149273165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p292627926165622"><a name="p292627926165622"></a><a name="p292627926165622"></a>PROT_EXEC </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1589735113165622"><a name="p1589735113165622"></a><a name="p1589735113165622"></a>Executable </p>
</td>
</tr>
<tr id="row1962583631165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1252967248165622"><a name="p1252967248165622"></a><a name="p1252967248165622"></a>PROT_READ </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1710472435165622"><a name="p1710472435165622"></a><a name="p1710472435165622"></a>Readable </p>
</td>
</tr>
<tr id="row1822719824165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1209711152165622"><a name="p1209711152165622"></a><a name="p1209711152165622"></a>PROT_WRITE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p6043690165622"><a name="p6043690165622"></a><a name="p6043690165622"></a>Writable </p>
</td>
</tr>
<tr id="row275855685165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1046735337165622"><a name="p1046735337165622"></a><a name="p1046735337165622"></a>PROT_NONE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1271658336165622"><a name="p1271658336165622"></a><a name="p1271658336165622"></a>Not accessible </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table540330402165622"></a>
<table><thead align="left"><tr id="row1702433259165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p167830953165622"><a name="p167830953165622"></a><a name="p167830953165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p765414533165622"><a name="p765414533165622"></a><a name="p765414533165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1350835157165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1493217722165622"><a name="p1493217722165622"></a><a name="p1493217722165622"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p220731179165622"><a name="p220731179165622"></a><a name="p220731179165622"></a>The memory region cannot be granted the specified permission. This error can occur, for example, when you use <a href="MEM.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap</a> to map a file with <strong id="b636015157165622"><a name="b636015157165622"></a><a name="b636015157165622"></a>prot</strong> set to <a href="MEM.md#ga15bf68ce8b590838b3a5c0b639d8d519">PROT_READ</a> and then use this function to set <strong id="b1780724769165622"><a name="b1780724769165622"></a><a name="b1780724769165622"></a>prot</strong> to <a href="MEM.md#ga2a79c8ceefb8fc25a940ae07a3d94429">PROT_WRITE</a>. </p>
</td>
</tr>
<tr id="row1013704543165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1658731392165622"><a name="p1658731392165622"></a><a name="p1658731392165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p47873381165622"><a name="p47873381165622"></a><a name="p47873381165622"></a><strong id="b290145413165622"><a name="b290145413165622"></a><a name="b290145413165622"></a>addr</strong> is an invalid pointer or it points to an address that is not a multiple of the page size. </p>
</td>
</tr>
<tr id="row822818539165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1423808030165622"><a name="p1423808030165622"></a><a name="p1423808030165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p85700026165622"><a name="p85700026165622"></a><a name="p85700026165622"></a>Internal kernel structures cannot be allocated due to insufficient memory, or addresses in the specified range are invalid for the address space of the process. The total number of mappings with different attributes exceeds the maximum number allowed by the system if the protection attribute of the memory region is changed. </p>
</td>
</tr>
</tbody>
</table>

## mremap\(\)<a name="ga1b5acd27009fbbf05d18e90640f6ef64"></a>

```
void* mremap (void * old_address, size_t old_size, size_t new_size, int flags,  ... )
```

 **Description:**

Remaps a virtual memory region. 

This function expands or shrinks an existing memory mapping, and may also move the mapping at the same time depending on the settings of  **flags**  and the available virtual address space. 

**Parameters:**

<a name="table706663248165622"></a>
<table><thead align="left"><tr id="row298589865165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1505001593165622"><a name="p1505001593165622"></a><a name="p1505001593165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p855414879165622"><a name="p855414879165622"></a><a name="p855414879165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2112074806165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">old_address</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the old address of the virtual memory region to expand or shrink. </td>
</tr>
<tr id="row511062467165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">old_size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the old size of the virtual memory region. </td>
</tr>
<tr id="row420667334165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">new_size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the requested size of the virtual memory region after the expansion or shrinking. </td>
</tr>
<tr id="row1314773362165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Specifies whether the existing memory can be mapped to a new or specified address. </td>
</tr>
<tr id="row256035555165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">new_address</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the new address of the virtual memory region. This parameter is optional and is used when <a href="MEM.md#ga689fc9cb8e5f54526471e67573624af9">MREMAP_FIXED</a> is specified in <strong id="b878003426165622"><a name="b878003426165622"></a><a name="b878003426165622"></a>flags</strong>. </td>
</tr>
</tbody>
</table>

<a name="table30782311165622"></a>
<table><thead align="left"><tr id="row280367209165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1913750361165622"><a name="p1913750361165622"></a><a name="p1913750361165622"></a>flags </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1260160202165622"><a name="p1260160202165622"></a><a name="p1260160202165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1052106209165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1784625059165622"><a name="p1784625059165622"></a><a name="p1784625059165622"></a>MREMAP_MAYMOVE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1952365793165622"><a name="p1952365793165622"></a><a name="p1952365793165622"></a>By default, if no enough space is available to expand a mapping at its current location, the operation fails. If this flag is specified, the kernel is allowed to relocate the mapping to a new virtual address when necessary. </p>
</td>
</tr>
<tr id="row1033111198165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p580127620165622"><a name="p580127620165622"></a><a name="p580127620165622"></a>MREMAP_FIXED </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1612668454165622"><a name="p1612668454165622"></a><a name="p1612668454165622"></a>If this flag is specified, the <strong id="b485498455165622"><a name="b485498455165622"></a><a name="b485498455165622"></a>new_address</strong> parameter is enabled in this function and the memory is mapped to a new address. This flag must be used together with <a href="MEM.md#ga979a9c42ee569172c2017c522c17a0b1">MREMAP_MAYMOVE</a>. </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the new mapping address if the operation is successful; returns  [MAP\_FAILED](MEM.md#ga8523dcf952f6ff059a3bed717e4f1296)  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table17129895165622"></a>
<table><thead align="left"><tr id="row283779376165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1596498739165622"><a name="p1596498739165622"></a><a name="p1596498739165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2055646174165622"><a name="p2055646174165622"></a><a name="p2055646174165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row864891753165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1909358086165622"><a name="p1909358086165622"></a><a name="p1909358086165622"></a>EAGAIN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1227624261165622"><a name="p1227624261165622"></a><a name="p1227624261165622"></a>The memory segment to expand is locked. </p>
</td>
</tr>
<tr id="row1237034854165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1539841293165622"><a name="p1539841293165622"></a><a name="p1539841293165622"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1314527370165622"><a name="p1314527370165622"></a><a name="p1314527370165622"></a>Some memory addresses in the range from <strong id="b1255453998165622"><a name="b1255453998165622"></a><a name="b1255453998165622"></a>old_address</strong> to <strong id="b544394192165622"><a name="b544394192165622"></a><a name="b544394192165622"></a>old_address</strong>+<strong id="b1462698774165622"><a name="b1462698774165622"></a><a name="b1462698774165622"></a>old_size</strong> are invalid for this process. </p>
</td>
</tr>
<tr id="row1108142222165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p655884686165622"><a name="p655884686165622"></a><a name="p655884686165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1655149544165622"><a name="p1655149544165622"></a><a name="p1655149544165622"></a><strong id="b97839683165622"><a name="b97839683165622"></a><a name="b97839683165622"></a>old_address</strong> is not a multiple of the page size, or a value other than <a href="MEM.md#ga979a9c42ee569172c2017c522c17a0b1">MREMAP_MAYMOVE</a> and <a href="MEM.md#ga689fc9cb8e5f54526471e67573624af9">MREMAP_FIXED</a> is specified in <strong id="b749351178165622"><a name="b749351178165622"></a><a name="b749351178165622"></a>flags</strong>. <strong id="b1024104127165622"><a name="b1024104127165622"></a><a name="b1024104127165622"></a>new_size</strong> is <strong id="b1519184372165622"><a name="b1519184372165622"></a><a name="b1519184372165622"></a>0</strong>, <strong id="b44673326165622"><a name="b44673326165622"></a><a name="b44673326165622"></a>new_size</strong> or <strong id="b277077756165622"><a name="b277077756165622"></a><a name="b277077756165622"></a>new_address</strong> is invalid, or <a href="MEM.md#ga689fc9cb8e5f54526471e67573624af9">MREMAP_FIXED</a> is specified in <strong id="b1436523949165622"><a name="b1436523949165622"></a><a name="b1436523949165622"></a>flags</strong> without also specifying <a href="MEM.md#ga979a9c42ee569172c2017c522c17a0b1">MREMAP_MAYMOVE</a>. <strong id="b698332950165622"><a name="b698332950165622"></a><a name="b698332950165622"></a>old_size</strong> is <strong id="b11348532165622"><a name="b11348532165622"></a><a name="b11348532165622"></a>0</strong> but <strong id="b540891629165622"><a name="b540891629165622"></a><a name="b540891629165622"></a>old_address</strong> does not point to a shared memory mapping; <strong id="b2126282090165622"><a name="b2126282090165622"></a><a name="b2126282090165622"></a>old_size</strong> is <strong id="b1286839061165622"><a name="b1286839061165622"></a><a name="b1286839061165622"></a>0</strong> but <a href="MEM.md#ga979a9c42ee569172c2017c522c17a0b1">MREMAP_MAYMOVE</a> is not specified in <strong id="b981490426165622"><a name="b981490426165622"></a><a name="b981490426165622"></a>flags</strong>; or the new memory address range specified by <strong id="b371479226165622"><a name="b371479226165622"></a><a name="b371479226165622"></a>new_address</strong> and <strong id="b2125244293165622"><a name="b2125244293165622"></a><a name="b2125244293165622"></a>new_size</strong> overlaps the old memory address range specified by <strong id="b936326868165622"><a name="b936326868165622"></a><a name="b936326868165622"></a>old_address</strong> and <strong id="b1422963896165622"><a name="b1422963896165622"></a><a name="b1422963896165622"></a>old_size</strong>. </p>
</td>
</tr>
<tr id="row961618329165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1220118352165622"><a name="p1220118352165622"></a><a name="p1220118352165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p367010462165622"><a name="p367010462165622"></a><a name="p367010462165622"></a>Insufficient memory. </p>
</td>
</tr>
</tbody>
</table>

## munmap\(\)<a name="ga1343e4aa663c9e8bb7d1b16d367f0b08"></a>

```
int munmap (void * addr, size_t length )
```

 **Description:**

Removes all mappings for the specified virtual address space. 

After all mappings are removed, any references to addresses within the specified range will generate invalid memory references. The memory region will also be automatically unmapped when the process is terminated. Closing the file descriptor does not remove mappings from the region. 

**Parameters:**

<a name="table280874189165622"></a>
<table><thead align="left"><tr id="row1013993758165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1890257627165622"><a name="p1890257627165622"></a><a name="p1890257627165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1005292336165622"><a name="p1005292336165622"></a><a name="p1005292336165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row524151218165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the start address of the memory region to unmap, which is the return value of <a href="MEM.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </td>
</tr>
<tr id="row741733373165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">length</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the address range to unmap, which should be the length specified in <a href="MEM.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table908752176165622"></a>
<table><thead align="left"><tr id="row2033596760165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p468301784165622"><a name="p468301784165622"></a><a name="p468301784165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1215960443165622"><a name="p1215960443165622"></a><a name="p1215960443165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1984218877165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p693579901165622"><a name="p693579901165622"></a><a name="p693579901165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p240582224165622"><a name="p240582224165622"></a><a name="p240582224165622"></a>Invalid input parameters. </p>
</td>
</tr>
</tbody>
</table>

## realloc\(\)<a name="ga1a6b5e8d2f1c37e5b43e4345586075be"></a>

```
void* realloc (void * ptr, size_t size )
```

 **Description:**

Changes the size of a previously allocated memory block pointed to by  **ptr**  to the specified size. 

The contents of the memory block will be retained from the beginning of the memory pointed to by  **ptr**  to the lesser of the old and new sizes. If the new size is larger than the old size, the added memory portion will not be initialized. The behavior of this function varies depending on the input parameters: 

**Parameters:**

<a name="table1272973813165622"></a>
<table><thead align="left"><tr id="row1882622974165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p880305968165622"><a name="p880305968165622"></a><a name="p880305968165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1092238399165622"><a name="p1092238399165622"></a><a name="p1092238399165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row443771766165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a memory block previously allocated with <a href="UTILS.md#ga7ac38fce3243a7dcf448301ee9ffd392">malloc</a>, <a href="UTILS.md#ga62b7798461bd461da64c5f9d35feddf7">calloc</a> or <a href="UTILS.md#ga1a6b5e8d2f1c37e5b43e4345586075be">realloc</a>. </td>
</tr>
<tr id="row372323125165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the new size for the memory block, in bytes. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the new memory block if the operation is successful; returns  **NULL**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table483189295165622"></a>
<table><thead align="left"><tr id="row432043564165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p822375191165622"><a name="p822375191165622"></a><a name="p822375191165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p135074418165622"><a name="p135074418165622"></a><a name="p135074418165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1543297804165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p992268656165622"><a name="p992268656165622"></a><a name="p992268656165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p365081659165622"><a name="p365081659165622"></a><a name="p365081659165622"></a>Insufficient memory. </p>
</td>
</tr>
</tbody>
</table>

## shmat\(\)<a name="gac56f61130bf1ddd88ecd6a2e87b4c5cb"></a>

```
void* shmat (int shmid, const void * shmaddr, int shmflg )
```

 **Description:**

Attaches the shared memory segment identified by  **shmid**  to the address space of the current process. 

**Parameters:**

<a name="table969827970165622"></a>
<table><thead align="left"><tr id="row1243674438165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p935786063165622"><a name="p935786063165622"></a><a name="p935786063165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1657897049165622"><a name="p1657897049165622"></a><a name="p1657897049165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row357004425165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">shmid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Identifies the shared memory segment to attach, which is obtained by <a href="MEM.md#ga23e346182fc10c5286f37213e09fefb2">shmget()</a>. </td>
</tr>
<tr id="row104506257165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">shmaddr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the space address of the current process to attach. If this parameter is <strong id="b1271293154165622"><a name="b1271293154165622"></a><a name="b1271293154165622"></a>NULL</strong>, the system chooses an unused address to attach. </td>
</tr>
<tr id="row517301246165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">shmflg</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the attribute of the shared memory segment to attach, which is the bitwise OR combination of one or more of the following flags: </td>
</tr>
</tbody>
</table>

<a name="table1565321783165622"></a>
<table><thead align="left"><tr id="row797366315165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1454098302165622"><a name="p1454098302165622"></a><a name="p1454098302165622"></a>shmflg </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p231864571165622"><a name="p231864571165622"></a><a name="p231864571165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1792945643165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658287732165622"><a name="p658287732165622"></a><a name="p658287732165622"></a>SHM_RND </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1763708303165622"><a name="p1763708303165622"></a><a name="p1763708303165622"></a>Round the attached address. If <strong id="b1040777872165622"><a name="b1040777872165622"></a><a name="b1040777872165622"></a>shmaddr</strong> is not <strong id="b1324563473165622"><a name="b1324563473165622"></a><a name="b1324563473165622"></a>NULL</strong> and <a href="MEM.md#ga4ae5f621aa1333d9d5962c3e9d674a90">SHM_RND</a> is specified in <strong id="b1909575186165622"><a name="b1909575186165622"></a><a name="b1909575186165622"></a>shmflg</strong>, the address is rounded down to the nearest multiple of <a href="MEM.md#ga1f422a47c416c67470e3a0fb8b7529d8">SHMLBA</a>. </p>
</td>
</tr>
<tr id="row519279923165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p370468492165622"><a name="p370468492165622"></a><a name="p370468492165622"></a>SHM_EXEC </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p242867685165622"><a name="p242867685165622"></a><a name="p242867685165622"></a>Allow the contents of the attached shared memory segment to be executable. </p>
</td>
</tr>
<tr id="row1263067380165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1060207903165622"><a name="p1060207903165622"></a><a name="p1060207903165622"></a>SHM_RDONLY </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p135812853165622"><a name="p135812853165622"></a><a name="p135812853165622"></a>Set the contents of the attached shared memory segment to be read-only. </p>
</td>
</tr>
<tr id="row1580111072165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1660549554165622"><a name="p1660549554165622"></a><a name="p1660549554165622"></a>SHM_REMAP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p299672733165622"><a name="p299672733165622"></a><a name="p299672733165622"></a>Replace any existing mapping in the address range starting at <strong id="b1408157823165622"><a name="b1408157823165622"></a><a name="b1408157823165622"></a>shmaddr</strong> and continuing for the size of the segment during the current memory mapping. When <a href="MEM.md#gab652a1a4737f9118a64a8fb74084ef7d">SHM_REMAP</a> is not specified, an <strong id="b1567970712165622"><a name="b1567970712165622"></a><a name="b1567970712165622"></a>EINVAL</strong> error will be returned if a mapping exists in the address range. </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the address of the attached shared memory segment if the operation is successful; returns  **\(void \*\)-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table810886966165622"></a>
<table><thead align="left"><tr id="row1218124026165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1896806887165622"><a name="p1896806887165622"></a><a name="p1896806887165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p41822870165622"><a name="p41822870165622"></a><a name="p41822870165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1881437919165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1314808965165622"><a name="p1314808965165622"></a><a name="p1314808965165622"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p295139319165622"><a name="p295139319165622"></a><a name="p295139319165622"></a>The current process does not have the required permission on the requested mapping type. </p>
</td>
</tr>
<tr id="row111769485165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1569039019165622"><a name="p1569039019165622"></a><a name="p1569039019165622"></a>EIDRM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1940540989165622"><a name="p1940540989165622"></a><a name="p1940540989165622"></a>The shared memory segment specified by <strong id="b1851108006165622"><a name="b1851108006165622"></a><a name="b1851108006165622"></a>shmid</strong> has been removed. </p>
</td>
</tr>
<tr id="row2106244479165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1977338551165622"><a name="p1977338551165622"></a><a name="p1977338551165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p328446633165622"><a name="p328446633165622"></a><a name="p328446633165622"></a>The value of <strong id="b1835950957165622"><a name="b1835950957165622"></a><a name="b1835950957165622"></a>shmid</strong> is invalid. <strong id="b1562880118165622"><a name="b1562880118165622"></a><a name="b1562880118165622"></a>shmaddr</strong> is not aligned (not page-aligned and <a href="MEM.md#ga4ae5f621aa1333d9d5962c3e9d674a90">SHM_RND</a> is not specified) or its value is invalid. <a href="MEM.md#gab652a1a4737f9118a64a8fb74084ef7d">SHM_REMAP</a> is specified, but <strong id="b1556905372165622"><a name="b1556905372165622"></a><a name="b1556905372165622"></a>shmaddr</strong> is <strong id="b148365756165622"><a name="b148365756165622"></a><a name="b148365756165622"></a>NULL</strong>. </p>
</td>
</tr>
<tr id="row997078643165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2035530721165622"><a name="p2035530721165622"></a><a name="p2035530721165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1706172632165622"><a name="p1706172632165622"></a><a name="p1706172632165622"></a>No page tables can be allocated. </p>
</td>
</tr>
</tbody>
</table>

## shmctl\(\)<a name="gab2cfe9a9370d4c74b485876260e2e0fe"></a>

```
int shmctl (int shmid, int cmd, struct [shmid_ds](shmid_ds.md) * buf )
```

 **Description:**

Performs a control operation specified by the  **cmd**  parameter on the shared memory segment identified by  **shmid**. 

**Parameters:**

<a name="table1835331971165622"></a>
<table><thead align="left"><tr id="row611744333165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1220005157165622"><a name="p1220005157165622"></a><a name="p1220005157165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1256420348165622"><a name="p1256420348165622"></a><a name="p1256420348165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row908429839165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">shmid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Identifies the shared memory segment to attach, which is obtained by <a href="MEM.md#ga23e346182fc10c5286f37213e09fefb2">shmget()</a>. </td>
</tr>
<tr id="row745031101165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cmd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the control operation to perform. The following table describes available values. </td>
</tr>
<tr id="row1735266987165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer for storing the information to set or obtain. </td>
</tr>
</tbody>
</table>

<a name="table1718048492165622"></a>
<table><thead align="left"><tr id="row771463699165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1825980393165622"><a name="p1825980393165622"></a><a name="p1825980393165622"></a>cmd </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p178089772165622"><a name="p178089772165622"></a><a name="p178089772165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row2009634801165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p146650667165622"><a name="p146650667165622"></a><a name="p146650667165622"></a>IPC_STAT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1316334331165622"><a name="p1316334331165622"></a><a name="p1316334331165622"></a>Copy information from the kernel data structure associated with the shared memory segment identified by <strong id="b715003197165622"><a name="b715003197165622"></a><a name="b715003197165622"></a>shmid</strong> into the <a href="shmid_ds.md">shmid_ds</a> structure pointed to by <strong id="b577666378165622"><a name="b577666378165622"></a><a name="b577666378165622"></a>buf</strong>. </p>
</td>
</tr>
<tr id="row690289136165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p951013932165622"><a name="p951013932165622"></a><a name="p951013932165622"></a>SHM_STAT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1388996107165622"><a name="p1388996107165622"></a><a name="p1388996107165622"></a>Return a <a href="shmid_ds.md">shmid_ds</a> data structure. When <a href="MEM.md#ga2e0f8c5b0fafab9f2602d19588d03e95">SHM_STAT</a> is specified, <strong id="b1665111070165622"><a name="b1665111070165622"></a><a name="b1665111070165622"></a>shmid</strong> does not identify a shared memory segment. Instead, it indicates the index to the kernel's internal array that maintains information about all shared memory segments. </p>
</td>
</tr>
<tr id="row682200320165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1468908489165622"><a name="p1468908489165622"></a><a name="p1468908489165622"></a>IPC_SET </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1072784518165622"><a name="p1072784518165622"></a><a name="p1072784518165622"></a>Write the values of some fields in the <a href="shmid_ds.md">shmid_ds</a> data structure pointed to by <strong id="b558699843165622"><a name="b558699843165622"></a><a name="b558699843165622"></a>buf</strong> to the kernel data structure associated with the specified shared memory segment, updating also its <strong id="b577691805165622"><a name="b577691805165622"></a><a name="b577691805165622"></a>shm_ctime</strong>member. The following fields can be modified: <strong id="b1829003729165622"><a name="b1829003729165622"></a><a name="b1829003729165622"></a>shm_perm.uid</strong>, <strong id="b2034225005165622"><a name="b2034225005165622"></a><a name="b2034225005165622"></a>shm_perm.gid</strong>, and <strong id="b584744693165622"><a name="b584744693165622"></a><a name="b584744693165622"></a>shm_perm.mode</strong>. </p>
</td>
</tr>
<tr id="row580080972165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p980736905165622"><a name="p980736905165622"></a><a name="p980736905165622"></a>IPC_RMID </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1498907193165622"><a name="p1498907193165622"></a><a name="p1498907193165622"></a>Mark the shared memory segment to be destroyed. </p>
</td>
</tr>
<tr id="row1020643367165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p282935115165622"><a name="p282935115165622"></a><a name="p282935115165622"></a>IPC_INFO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1583797558165622"><a name="p1583797558165622"></a><a name="p1583797558165622"></a>Return information about system-wide shared memory limits and parameters in the structure pointed to by <strong id="b1519842606165622"><a name="b1519842606165622"></a><a name="b1519842606165622"></a>buf</strong>. The returned structure is of the <a href="shminfo.md">shminfo</a> type, and a cast is required. </p>
</td>
</tr>
<tr id="row898597112165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1300040665165622"><a name="p1300040665165622"></a><a name="p1300040665165622"></a>SHM_INFO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1303280364165622"><a name="p1303280364165622"></a><a name="p1303280364165622"></a>Return a <a href="shm_info.md">shm_info</a> structure that contains information about system resources consumed by the specified shared memory segment. </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1331639658165622"></a>
<table><thead align="left"><tr id="row972160714165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p783167853165622"><a name="p783167853165622"></a><a name="p783167853165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1860386280165622"><a name="p1860386280165622"></a><a name="p1860386280165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row169446596165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p115361522165622"><a name="p115361522165622"></a><a name="p115361522165622"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1452085036165622"><a name="p1452085036165622"></a><a name="p1452085036165622"></a><a href="IPC.md#ga16a91ee69c3cb6bfec425e1bfd5edd18">IPC_STAT</a> or <a href="MEM.md#ga2e0f8c5b0fafab9f2602d19588d03e95">SHM_STAT</a> is specified in <strong id="b1403573007165622"><a name="b1403573007165622"></a><a name="b1403573007165622"></a>cmb</strong>, but the <strong id="b1323415712165622"><a name="b1323415712165622"></a><a name="b1323415712165622"></a>mode</strong> field in <strong id="b1964366869165622"><a name="b1964366869165622"></a><a name="b1964366869165622"></a>shm_perm</strong> does not allow any read operation on the shared memory segment identified by <strong id="b111931222165622"><a name="b111931222165622"></a><a name="b111931222165622"></a>shmid</strong>. </p>
</td>
</tr>
<tr id="row1688431364165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1269785248165622"><a name="p1269785248165622"></a><a name="p1269785248165622"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p434216581165622"><a name="p434216581165622"></a><a name="p434216581165622"></a><a href="MEM.md#ga2e0f8c5b0fafab9f2602d19588d03e95">SHM_STAT</a> or <a href="IPC.md#ga16a91ee69c3cb6bfec425e1bfd5edd18">IPC_STAT</a> is specified in <strong id="b1348499370165622"><a name="b1348499370165622"></a><a name="b1348499370165622"></a>cmd</strong>, but the address pointed to by <strong id="b555013239165622"><a name="b555013239165622"></a><a name="b555013239165622"></a>buf</strong> is not accessible. </p>
</td>
</tr>
<tr id="row742319485165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p148965554165622"><a name="p148965554165622"></a><a name="p148965554165622"></a>EIDRM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p383627335165622"><a name="p383627335165622"></a><a name="p383627335165622"></a><strong id="b385453750165622"><a name="b385453750165622"></a><a name="b385453750165622"></a>shmid</strong> points to a removed shared memory segment. </p>
</td>
</tr>
<tr id="row1181506809165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p980291318165622"><a name="p980291318165622"></a><a name="p980291318165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p751850370165622"><a name="p751850370165622"></a><a name="p751850370165622"></a>The value of <strong id="b2142181649165622"><a name="b2142181649165622"></a><a name="b2142181649165622"></a>shmid</strong> or <strong id="b1834668180165622"><a name="b1834668180165622"></a><a name="b1834668180165622"></a>cmd</strong> is invalid. When <a href="MEM.md#ga2e0f8c5b0fafab9f2602d19588d03e95">SHM_STAT</a> is specified in <strong id="b624886103165622"><a name="b624886103165622"></a><a name="b624886103165622"></a>cmd</strong>, the value is considered invalid if the index specified by <strong id="b969273976165622"><a name="b969273976165622"></a><a name="b969273976165622"></a>shmid</strong> refers to an unused array slot. </p>
</td>
</tr>
<tr id="row818718203165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p702786270165622"><a name="p702786270165622"></a><a name="p702786270165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1778417542165622"><a name="p1778417542165622"></a><a name="p1778417542165622"></a>No page tables can be allocated. </p>
</td>
</tr>
<tr id="row468662414165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1447587282165622"><a name="p1447587282165622"></a><a name="p1447587282165622"></a>EPERM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p939210226165622"><a name="p939210226165622"></a><a name="p939210226165622"></a><a href="IPC.md#ga1f1cdce55426e50878b1c71a4fc67a41">IPC_SET</a> or <a href="IPC.md#ga752c83032a7bec60c904d97508ea4599">IPC_RMID</a> is attempted, but the effective user ID of the calling process is not that of the creator or the owner, and the process is not privileged. </p>
</td>
</tr>
</tbody>
</table>

## shmdt\(\)<a name="ga934738fcc6c27c0d45cff9bb8cc38a7f"></a>

```
int shmdt (const void * shmaddr)
```

 **Description:**

Detaches the shared memory segment attached to the address pointed to by  **shmaddr**  from the address space of the calling process. 

**Parameters:**

<a name="table774990192165622"></a>
<table><thead align="left"><tr id="row1948452200165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1644837760165622"><a name="p1644837760165622"></a><a name="p1644837760165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p667756205165622"><a name="p667756205165622"></a><a name="p667756205165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1516546343165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">shmaddr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the address of the shared memory segment to detach. The value of this parameter should be the pointer previously returned by <a href="MEM.md#gac56f61130bf1ddd88ecd6a2e87b4c5cb">shmat()</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table190066042165622"></a>
<table><thead align="left"><tr id="row865317981165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1214653333165622"><a name="p1214653333165622"></a><a name="p1214653333165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p180982474165622"><a name="p180982474165622"></a><a name="p180982474165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row654004332165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1083969824165622"><a name="p1083969824165622"></a><a name="p1083969824165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p480973756165622"><a name="p480973756165622"></a><a name="p480973756165622"></a>No shared memory segment is attached to <strong id="b421239291165622"><a name="b421239291165622"></a><a name="b421239291165622"></a>shmaddr</strong>, or <strong id="b1779477885165622"><a name="b1779477885165622"></a><a name="b1779477885165622"></a>shmaddr</strong> is not aligned. </p>
</td>
</tr>
</tbody>
</table>

## shmget\(\)<a name="ga23e346182fc10c5286f37213e09fefb2"></a>

```
int shmget ([key_t](UTILS.md#ga4f8c894a6c2b415e55f3f858afd9e7f5) key, size_t size, int shmflg )
```

 **Description:**

Obtains or creates a shared memory segment with the specified size based on the ID specified by  **key**. 

If the shared memory segment associated with  **key**  does not exist and  [IPC\_CREAT](IPC.md#gace43f23fcb66ddaad964bb8ea8de6e9c)  is specified in  **shmflg**  or if  **key**  has the value  [IPC\_PRIVATE](IPC.md#gae2b9b856a4a657c250b0b2e1cc0835d9), this function creates a shared memory segment with the size equal to the value of  **size**  rounded up to a multiple of  [PAGE\_SIZE](UTILS.md#ga7d467c1d283fdfa1f2081ba1e0d01b6e). 

**Parameters:**

<a name="table1167880526165622"></a>
<table><thead align="left"><tr id="row1417729485165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1476511996165622"><a name="p1476511996165622"></a><a name="p1476511996165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p716755287165622"><a name="p716755287165622"></a><a name="p716755287165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1246673936165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the key of the shared memory segment. </td>
</tr>
<tr id="row1737279550165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the shared memory segment to create. The actual size is rounded up to a multiple of <a href="UTILS.md#ga7d467c1d283fdfa1f2081ba1e0d01b6e">PAGE_SIZE</a>. </td>
</tr>
<tr id="row1773655652165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">shmflg</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the attribute of the shared memory segment, which is the bitwise OR combination of one or more of the following flags: </td>
</tr>
</tbody>
</table>

<a name="table952893440165622"></a>
<table><thead align="left"><tr id="row1388512755165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p371928259165622"><a name="p371928259165622"></a><a name="p371928259165622"></a>shmflg </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p769925486165622"><a name="p769925486165622"></a><a name="p769925486165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row461710179165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1194944144165622"><a name="p1194944144165622"></a><a name="p1194944144165622"></a>IPC_CREAT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1389437243165622"><a name="p1389437243165622"></a><a name="p1389437243165622"></a>Create a new shared memory segment. If this flag is not specified, this function will find the segment with the specified <strong id="b1380620002165622"><a name="b1380620002165622"></a><a name="b1380620002165622"></a>key</strong> and check to see whether the user has permission to access the segment. </p>
</td>
</tr>
<tr id="row172569549165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p283419607165622"><a name="p283419607165622"></a><a name="p283419607165622"></a>IPC_EXCL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p327356093165622"><a name="p327356093165622"></a><a name="p327356093165622"></a>Used together with <a href="IPC.md#gace43f23fcb66ddaad964bb8ea8de6e9c">IPC_CREAT</a> to ensure that this function is called to create a shared memory segment. The calling fails if the segment already exists. </p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the ID of the shared memory segment if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table2090048921165622"></a>
<table><thead align="left"><tr id="row1109761968165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1972667756165622"><a name="p1972667756165622"></a><a name="p1972667756165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p302272117165622"><a name="p302272117165622"></a><a name="p302272117165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row466821093165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p945299764165622"><a name="p945299764165622"></a><a name="p945299764165622"></a>EACCES </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1533633809165622"><a name="p1533633809165622"></a><a name="p1533633809165622"></a>The current process does not have the permission to obtain the specified shared memory segment. </p>
</td>
</tr>
<tr id="row1584570881165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1238204677165622"><a name="p1238204677165622"></a><a name="p1238204677165622"></a>EEXIST </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p359584865165622"><a name="p359584865165622"></a><a name="p359584865165622"></a><a href="IPC.md#gacd312ab97691605718a3ee9a1c7c63e9">IPC_EXCL</a> and <a href="IPC.md#gace43f23fcb66ddaad964bb8ea8de6e9c">IPC_CREAT</a> are specified, but the shared memory segment associated with <strong id="b712757231165622"><a name="b712757231165622"></a><a name="b712757231165622"></a>key</strong> already exists. </p>
</td>
</tr>
<tr id="row1306096725165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1622220126165622"><a name="p1622220126165622"></a><a name="p1622220126165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1423307910165622"><a name="p1423307910165622"></a><a name="p1423307910165622"></a>The size specified for the shared memory segment to create is less than the value of <strong id="b106390794165622"><a name="b106390794165622"></a><a name="b106390794165622"></a>shmmin</strong> in <a href="shminfo.md">shminfo</a> or greater than the value of <strong id="b827655335165622"><a name="b827655335165622"></a><a name="b827655335165622"></a>shmmax</strong>. The shared memory segment associated with <strong id="b1381975731165622"><a name="b1381975731165622"></a><a name="b1381975731165622"></a>key</strong> already exists, but the value of <strong id="b2035234178165622"><a name="b2035234178165622"></a><a name="b2035234178165622"></a>size</strong> is greater than the size of the segment. </p>
</td>
</tr>
<tr id="row1402254887165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1857140196165622"><a name="p1857140196165622"></a><a name="p1857140196165622"></a>ENOENT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1133904268165622"><a name="p1133904268165622"></a><a name="p1133904268165622"></a>No segment exists for the given key, and <a href="IPC.md#gace43f23fcb66ddaad964bb8ea8de6e9c">IPC_CREAT</a> is not specified. </p>
</td>
</tr>
<tr id="row1144641355165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p962379608165622"><a name="p962379608165622"></a><a name="p962379608165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p913928940165622"><a name="p913928940165622"></a><a name="p913928940165622"></a>Insufficient memory. </p>
</td>
</tr>
<tr id="row810465677165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1433067802165622"><a name="p1433067802165622"></a><a name="p1433067802165622"></a>ENOSPC </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p133118177165622"><a name="p133118177165622"></a><a name="p133118177165622"></a>Allocating a segment of the requested size would cause the system to exceed the system-wide limit on shared memory (<strong id="b386046405165622"><a name="b386046405165622"></a><a name="b386046405165622"></a>shmall</strong> in <a href="shminfo.md">shminfo</a>). </p>
</td>
</tr>
</tbody>
</table>

