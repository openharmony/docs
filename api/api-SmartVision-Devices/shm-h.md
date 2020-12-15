# shm.h<a name="ZH-CN_TOPIC_0000001054948037"></a>

-   [Overview](#section1198649889165629)
-   [Summary](#section2021940440165629)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section1198649889165629"></a>

**Related Modules:**

[MEM](MEM.md)

**Description:**

Declares APIs for creating, mapping, deleting, and controlling shared memory. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2021940440165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table739961790165629"></a>
<table><thead align="left"><tr id="row1810290585165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1467688868165629"><a name="p1467688868165629"></a><a name="p1467688868165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1651075559165629"><a name="p1651075559165629"></a><a name="p1651075559165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row196905080165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1205311370165629"><a name="p1205311370165629"></a><a name="p1205311370165629"></a><a href="shmid_ds.md">shmid_ds</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2067719513165629"><a name="p2067719513165629"></a><a name="p2067719513165629"></a>Stores information about a shared memory segment. </p>
</td>
</tr>
<tr id="row288353432165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1864629486165629"><a name="p1864629486165629"></a><a name="p1864629486165629"></a><a href="shminfo.md">shminfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p934276984165629"><a name="p934276984165629"></a><a name="p934276984165629"></a>Describes limitations and attributes of system-level shared memory. </p>
</td>
</tr>
<tr id="row1927693164165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p545564922165629"><a name="p545564922165629"></a><a name="p545564922165629"></a><a href="shm_info.md">shm_info</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1170726896165629"><a name="p1170726896165629"></a><a name="p1170726896165629"></a>Describes system resource information about the shared memory. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1317509867165629"></a>
<table><thead align="left"><tr id="row1065777578165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1261404478165629"><a name="p1261404478165629"></a><a name="p1261404478165629"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p410099904165629"><a name="p410099904165629"></a><a name="p410099904165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row416369345165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p635418464165629"><a name="p635418464165629"></a><a name="p635418464165629"></a><a href="MEM.md#ga1f422a47c416c67470e3a0fb8b7529d8">SHMLBA</a>   4096</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p178374749165629"><a name="p178374749165629"></a><a name="p178374749165629"></a>Aligns the shared memory address. </p>
</td>
</tr>
<tr id="row667756139165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1581842693165629"><a name="p1581842693165629"></a><a name="p1581842693165629"></a><a href="MEM.md#ga45da2dbfb146e926c8fd842379c0362c">SHM_R</a>   0400</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p886750498165629"><a name="p886750498165629"></a><a name="p886750498165629"></a>Indicates that the shared memory segment is readable. This macro is used for setting the <strong id="b1177792702165629"><a name="b1177792702165629"></a><a name="b1177792702165629"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#ga23e346182fc10c5286f37213e09fefb2">shmget()</a>. </p>
</td>
</tr>
<tr id="row1651248258165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1448016660165629"><a name="p1448016660165629"></a><a name="p1448016660165629"></a><a href="MEM.md#gafd00993215ed6030ec817bf3615044d1">SHM_W</a>   0200</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1089125743165629"><a name="p1089125743165629"></a><a name="p1089125743165629"></a>Indicates that the shared memory segment is writable. This macro is used for setting the <strong id="b1939531592165629"><a name="b1939531592165629"></a><a name="b1939531592165629"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#ga23e346182fc10c5286f37213e09fefb2">shmget()</a>. </p>
</td>
</tr>
<tr id="row450674614165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p518951865165629"><a name="p518951865165629"></a><a name="p518951865165629"></a><a href="MEM.md#ga899e8ef0c4c33e2a5cc708c05c75429a">SHM_RDONLY</a>   010000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p250877436165629"><a name="p250877436165629"></a><a name="p250877436165629"></a>Indicates that the attached shared memory segment is read-only. This macro is used for setting the <strong id="b741361260165629"><a name="b741361260165629"></a><a name="b741361260165629"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#gac56f61130bf1ddd88ecd6a2e87b4c5cb">shmat()</a>. </p>
</td>
</tr>
<tr id="row585618638165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1697164266165629"><a name="p1697164266165629"></a><a name="p1697164266165629"></a><a href="MEM.md#ga4ae5f621aa1333d9d5962c3e9d674a90">SHM_RND</a>   020000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p433317175165629"><a name="p433317175165629"></a><a name="p433317175165629"></a>Indicates that the shared memory address can be rounded to a value meeting the requirement (<a href="MEM.md#ga1f422a47c416c67470e3a0fb8b7529d8">SHMLBA</a>). This macro is used for setting the <strong id="b165193561165629"><a name="b165193561165629"></a><a name="b165193561165629"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#gac56f61130bf1ddd88ecd6a2e87b4c5cb">shmat()</a>. </p>
</td>
</tr>
<tr id="row203679819165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p874002292165629"><a name="p874002292165629"></a><a name="p874002292165629"></a><a href="MEM.md#gab652a1a4737f9118a64a8fb74084ef7d">SHM_REMAP</a>   040000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p924545818165629"><a name="p924545818165629"></a><a name="p924545818165629"></a>Indicates that the memory segment can be remapped. This macro is used for setting the <strong id="b671276618165629"><a name="b671276618165629"></a><a name="b671276618165629"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#gac56f61130bf1ddd88ecd6a2e87b4c5cb">shmat()</a>. </p>
</td>
</tr>
<tr id="row842038188165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2145166003165629"><a name="p2145166003165629"></a><a name="p2145166003165629"></a><a href="MEM.md#ga0bb6454e0dd48a66376bfaa05170ce82">SHM_EXEC</a>   0100000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1510783023165629"><a name="p1510783023165629"></a><a name="p1510783023165629"></a>Indicates that the attached shared memory segment is executable. This macro is used for setting the <strong id="b1071411993165629"><a name="b1071411993165629"></a><a name="b1071411993165629"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#gac56f61130bf1ddd88ecd6a2e87b4c5cb">shmat()</a>. </p>
</td>
</tr>
<tr id="row1935891060165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1746759920165629"><a name="p1746759920165629"></a><a name="p1746759920165629"></a><a href="MEM.md#ga66735ad43f79860ccdd21888c3ead8cc">SHM_LOCK</a>   11</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p742885006165629"><a name="p742885006165629"></a><a name="p742885006165629"></a>Locks the shared memory segment in memory so that it cannot be swapped to the swap partition. This macro is used for setting the <strong id="b1255446780165629"><a name="b1255446780165629"></a><a name="b1255446780165629"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#ga23e346182fc10c5286f37213e09fefb2">shmget()</a>. </p>
</td>
</tr>
<tr id="row600370271165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p648880853165629"><a name="p648880853165629"></a><a name="p648880853165629"></a><a href="MEM.md#ga7497459fc5ebe82bbbdfa3809c938312">SHM_UNLOCK</a>   12</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1587261297165629"><a name="p1587261297165629"></a><a name="p1587261297165629"></a>Unlocks the shared memory segment. This macro is used for setting the <strong id="b2031367994165629"><a name="b2031367994165629"></a><a name="b2031367994165629"></a>shmflg</strong> parameter passed to functions such as <a href="MEM.md#ga23e346182fc10c5286f37213e09fefb2">shmget()</a>. </p>
</td>
</tr>
<tr id="row392273998165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1709316092165629"><a name="p1709316092165629"></a><a name="p1709316092165629"></a><a href="MEM.md#ga2e0f8c5b0fafab9f2602d19588d03e95">SHM_STAT</a>   (13 | (<a href="IPC.md#ga16a91ee69c3cb6bfec425e1bfd5edd18">IPC_STAT</a> &amp; 0x100))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1262731766165629"><a name="p1262731766165629"></a><a name="p1262731766165629"></a>Obtains a <a href="shmid_ds.md">shmid_ds</a> data structure. This macro is used for setting the <strong id="b2059598341165629"><a name="b2059598341165629"></a><a name="b2059598341165629"></a>cmd</strong> parameter passed to <a href="MEM.md#gab2cfe9a9370d4c74b485876260e2e0fe">shmctl()</a>. </p>
</td>
</tr>
<tr id="row940115131165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p729782995165629"><a name="p729782995165629"></a><a name="p729782995165629"></a><a href="MEM.md#gafecb9e202431a631f42469c9ecbee99e">SHM_INFO</a>   14</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1248921418165629"><a name="p1248921418165629"></a><a name="p1248921418165629"></a>Obtains a <a href="shm_info.md">shm_info</a> data structure that includes system resource information about this shared memory segment. This macro is used for setting the <strong id="b117251621165629"><a name="b117251621165629"></a><a name="b117251621165629"></a>cmd</strong> parameter passed to <a href="MEM.md#gab2cfe9a9370d4c74b485876260e2e0fe">shmctl()</a>. </p>
</td>
</tr>
<tr id="row1416503728165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p721531470165629"><a name="p721531470165629"></a><a name="p721531470165629"></a><a href="MEM.md#ga9e7f0a6d71663d9173d9aae2a2f01220">SHM_STAT_ANY</a>   (15 | (<a href="IPC.md#ga16a91ee69c3cb6bfec425e1bfd5edd18">IPC_STAT</a> &amp; 0x100))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1583400372165629"><a name="p1583400372165629"></a><a name="p1583400372165629"></a>Obtains a <a href="shmid_ds.md">shmid_ds</a> data structure without permission check. This macro is used for setting the <strong id="b216275170165629"><a name="b216275170165629"></a><a name="b216275170165629"></a>cmd</strong> parameter passed to <a href="MEM.md#gab2cfe9a9370d4c74b485876260e2e0fe">shmctl()</a>. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1745671911165629"></a>
<table><thead align="left"><tr id="row1379770157165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1259763368165629"><a name="p1259763368165629"></a><a name="p1259763368165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1505333645165629"><a name="p1505333645165629"></a><a name="p1505333645165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1318200914165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1788365977165629"><a name="p1788365977165629"></a><a name="p1788365977165629"></a><a href="MEM.md#gac56f61130bf1ddd88ecd6a2e87b4c5cb">shmat</a> (int shmid, const void *shmaddr, int shmflg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p202432062165629"><a name="p202432062165629"></a><a name="p202432062165629"></a>void * </p>
<p id="p1260351877165629"><a name="p1260351877165629"></a><a name="p1260351877165629"></a>Attaches the shared memory segment identified by <strong id="b513066560165629"><a name="b513066560165629"></a><a name="b513066560165629"></a>shmid</strong> to the address space of the current process. </p>
</td>
</tr>
<tr id="row1601141845165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1802367259165629"><a name="p1802367259165629"></a><a name="p1802367259165629"></a><a href="MEM.md#gab2cfe9a9370d4c74b485876260e2e0fe">shmctl</a> (int shmid, int cmd, struct <a href="shmid_ds.md">shmid_ds</a> *buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1645007194165629"><a name="p1645007194165629"></a><a name="p1645007194165629"></a>int </p>
<p id="p1109599554165629"><a name="p1109599554165629"></a><a name="p1109599554165629"></a>Performs a control operation specified by the <strong id="b1268376334165629"><a name="b1268376334165629"></a><a name="b1268376334165629"></a>cmd</strong> parameter on the shared memory segment identified by <strong id="b1935312642165629"><a name="b1935312642165629"></a><a name="b1935312642165629"></a>shmid</strong>. </p>
</td>
</tr>
<tr id="row1033396478165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p290863708165629"><a name="p290863708165629"></a><a name="p290863708165629"></a><a href="MEM.md#ga934738fcc6c27c0d45cff9bb8cc38a7f">shmdt</a> (const void *shmaddr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p112314169165629"><a name="p112314169165629"></a><a name="p112314169165629"></a>int </p>
<p id="p479906781165629"><a name="p479906781165629"></a><a name="p479906781165629"></a>Detaches the shared memory segment attached to the address pointed to by <strong id="b1783301639165629"><a name="b1783301639165629"></a><a name="b1783301639165629"></a>shmaddr</strong> from the address space of the calling process. </p>
</td>
</tr>
<tr id="row13553435165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p876339902165629"><a name="p876339902165629"></a><a name="p876339902165629"></a><a href="MEM.md#ga23e346182fc10c5286f37213e09fefb2">shmget</a> (<a href="UTILS.md#ga4f8c894a6c2b415e55f3f858afd9e7f5">key_t</a> key, size_t size, int shmflg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p763562659165629"><a name="p763562659165629"></a><a name="p763562659165629"></a>int </p>
<p id="p1485929917165629"><a name="p1485929917165629"></a><a name="p1485929917165629"></a>Obtains or creates a shared memory segment with the specified size based on the ID specified by <strong id="b1234604025165629"><a name="b1234604025165629"></a><a name="b1234604025165629"></a>key</strong>. </p>
</td>
</tr>
</tbody>
</table>

