# mman.h<a name="EN-US_TOPIC_0000001054748009"></a>

-   [Overview](#section1778029163165628)
-   [Summary](#section469997764165628)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section1778029163165628"></a>

**Related Modules:**

[MEM](mem.md)

**Description:**

Declares structures and functions for performing memory operations, including memory mapping, remapping, unmapping, and attribute setting. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section469997764165628"></a>

## Macros<a name="define-members"></a>

<a name="table86348474165628"></a>
<table><thead align="left"><tr id="row1995373848165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p788055280165628"><a name="p788055280165628"></a><a name="p788055280165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2046613941165628"><a name="p2046613941165628"></a><a name="p2046613941165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row693342011165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2098512777165628"><a name="p2098512777165628"></a><a name="p2098512777165628"></a><a href="mem.md#ga8523dcf952f6ff059a3bed717e4f1296">MAP_FAILED</a>   ((void *) -1)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p655460025165628"><a name="p655460025165628"></a><a name="p655460025165628"></a>Indicates the return value of functions such as <a href="mem.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a> when the operation fails. </p>
</td>
</tr>
<tr id="row1538076643165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p236846293165628"><a name="p236846293165628"></a><a name="p236846293165628"></a><a href="mem.md#ga57028962c2a7c0c802ca6613492f2ef3">MAP_SHARED</a>   0x01</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p342144454165628"><a name="p342144454165628"></a><a name="p342144454165628"></a>Indicates the mapping attribute that the updates to the mapping are visible to other processes mapping the same file and are carried through to the underlying file. This macro is used as an input parameter passed to functions such as <a href="mem.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row1570677910165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p59804665165628"><a name="p59804665165628"></a><a name="p59804665165628"></a><a href="mem.md#ga398ef47a991a44389aa9818c98a28d24">MAP_PRIVATE</a>   0x02</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1969993398165628"><a name="p1969993398165628"></a><a name="p1969993398165628"></a>Indicates the mapping attribute that the updates to the mapping are not visible to other mapping processes and are not carried through to the underlying file. This macro is used as an input parameter passed to functions such as <a href="mem.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row62648815165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1145081575165628"><a name="p1145081575165628"></a><a name="p1145081575165628"></a><a href="mem.md#ga387ec707b30c5e78cf20a14517a63b96">MAP_FIXED</a>   0x10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p831054551165628"><a name="p831054551165628"></a><a name="p831054551165628"></a>Indicates the mapping attribute that specifies the mapping as fixed mapping. This macro is used as an input parameter passed to functions such as <a href="mem.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row896903946165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p616581058165628"><a name="p616581058165628"></a><a name="p616581058165628"></a><a href="mem.md#ga298ddbffafbe6cf941b92092edfb86a5">MAP_ANON</a>   0x20</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1524912475165628"><a name="p1524912475165628"></a><a name="p1524912475165628"></a>Indicates the mapping attribute that specifies the mapping as anonymous mapping without a specified file or device. This macro is used as an input parameter passed to functions such as <a href="mem.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row1977840806165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1033607788165628"><a name="p1033607788165628"></a><a name="p1033607788165628"></a><a href="mem.md#gae4f86bff73414c5fc08c058f957212f0">MAP_ANONYMOUS</a>   <a href="mem.md#ga298ddbffafbe6cf941b92092edfb86a5">MAP_ANON</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p636793598165628"><a name="p636793598165628"></a><a name="p636793598165628"></a>Indicates the mapping attribute that specifies the mapping as anonymous mapping without a specified file or device. This macro is the synonym for <a href="mem.md#ga298ddbffafbe6cf941b92092edfb86a5">MAP_ANON</a> and is used as an input parameter passed to functions such as <a href="mem.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row1411855162165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p926125527165628"><a name="p926125527165628"></a><a name="p926125527165628"></a><a href="mem.md#ga6a982b48b8d3eb8eccd17e0d54ee5379">PROT_NONE</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1779139525165628"><a name="p1779139525165628"></a><a name="p1779139525165628"></a>Indicates that no permission is granted to the current process for accessing the mapping area. This macro is used as an input parameter passed to functions such as <a href="mem.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row1928697476165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p58263592165628"><a name="p58263592165628"></a><a name="p58263592165628"></a><a href="mem.md#ga15bf68ce8b590838b3a5c0b639d8d519">PROT_READ</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1317810608165628"><a name="p1317810608165628"></a><a name="p1317810608165628"></a>Indicates that the current process is granted the read permission on the mapping area. This macro is used as an input parameter passed to functions such as <a href="mem.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row743596533165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p514953450165628"><a name="p514953450165628"></a><a name="p514953450165628"></a><a href="mem.md#ga2a79c8ceefb8fc25a940ae07a3d94429">PROT_WRITE</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p874541341165628"><a name="p874541341165628"></a><a name="p874541341165628"></a>Indicates that the current process is granted the write permission on the mapping area. This macro is used as an input parameter passed to functions such as <a href="mem.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row1746544829165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1128354294165628"><a name="p1128354294165628"></a><a name="p1128354294165628"></a><a href="mem.md#ga77848f068638e916c72cd543f5ecb815">PROT_EXEC</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1566786366165628"><a name="p1566786366165628"></a><a name="p1566786366165628"></a>Indicates that the current process is granted the execute permission on the mapping area. This macro is used as an input parameter passed to functions such as <a href="mem.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap()</a>. </p>
</td>
</tr>
<tr id="row319418131165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p924286999165628"><a name="p924286999165628"></a><a name="p924286999165628"></a><a href="mem.md#ga979a9c42ee569172c2017c522c17a0b1">MREMAP_MAYMOVE</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1966410465165628"><a name="p1966410465165628"></a><a name="p1966410465165628"></a>Indicates the remapping attribute that allows the mapping to be relocated to a new address. This macro is used as an input parameter passed to functions such as <a href="mem.md#ga1b5acd27009fbbf05d18e90640f6ef64">mremap()</a>. </p>
</td>
</tr>
<tr id="row1930574545165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p209513904165628"><a name="p209513904165628"></a><a name="p209513904165628"></a><a href="mem.md#ga689fc9cb8e5f54526471e67573624af9">MREMAP_FIXED</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1543061230165628"><a name="p1543061230165628"></a><a name="p1543061230165628"></a>Indicates the remapping attribute that specifies the mapping as fixed mapping. This macro is used as an input parameter passed to functions such as <a href="mem.md#ga1b5acd27009fbbf05d18e90640f6ef64">mremap()</a>. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table194334345165628"></a>
<table><thead align="left"><tr id="row456031714165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p78668050165628"><a name="p78668050165628"></a><a name="p78668050165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1848397633165628"><a name="p1848397633165628"></a><a name="p1848397633165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1287345638165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p836288063165628"><a name="p836288063165628"></a><a name="p836288063165628"></a><a href="mem.md#gadcdc6990a7641f7ba05f5dd2a603b992">mmap</a> (void *addr, size_t length, int prot, int flags, int fd, off_t offset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p774392206165628"><a name="p774392206165628"></a><a name="p774392206165628"></a>void * </p>
<p id="p1674765094165628"><a name="p1674765094165628"></a><a name="p1674765094165628"></a>Creates a mapping between the virtual address space of the calling process and a file or device. </p>
</td>
</tr>
<tr id="row1133088316165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1242862183165628"><a name="p1242862183165628"></a><a name="p1242862183165628"></a><a href="mem.md#ga1343e4aa663c9e8bb7d1b16d367f0b08">munmap</a> (void *addr, size_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p978451065165628"><a name="p978451065165628"></a><a name="p978451065165628"></a>int </p>
<p id="p1137449635165628"><a name="p1137449635165628"></a><a name="p1137449635165628"></a>Removes all mappings for the specified virtual address space. </p>
</td>
</tr>
<tr id="row1236692537165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p192763749165628"><a name="p192763749165628"></a><a name="p192763749165628"></a><a href="mem.md#gaa0752189f14ca11ba413fc944ae08b9c">mprotect</a> (void *addr, size_t len, int prot)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p20544466165628"><a name="p20544466165628"></a><a name="p20544466165628"></a>int </p>
<p id="p1315526764165628"><a name="p1315526764165628"></a><a name="p1315526764165628"></a>Sets protection attributes for the memory pages contained in the memory region starting from <strong id="b2010548017165628"><a name="b2010548017165628"></a><a name="b2010548017165628"></a>addr</strong> with the specified length. </p>
</td>
</tr>
<tr id="row1049855393165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p870081964165628"><a name="p870081964165628"></a><a name="p870081964165628"></a><a href="mem.md#ga1b5acd27009fbbf05d18e90640f6ef64">mremap</a> (void *old_address, size_t old_size, size_t new_size, int flags,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p930535504165628"><a name="p930535504165628"></a><a name="p930535504165628"></a>void * </p>
<p id="p1821625835165628"><a name="p1821625835165628"></a><a name="p1821625835165628"></a>Remaps a virtual memory region. </p>
</td>
</tr>
</tbody>
</table>

