# search.h<a name="ZH-CN_TOPIC_0000001055108027"></a>

-   [Overview](#section536723199165629)
-   [Summary](#section199634982165629)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section536723199165629"></a>

**Related Modules:**

[UTILS](UTILS.md)

**Description:**

Provides functions and related data structures, such as creating, destroying, or searching for a hash table. 

You can use the functions provided in this file to perform operations related to wide character types during development, such as, creating, destroying, or searching for a hash table, and creating or searching for a binary tree. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section199634982165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table221474344165629"></a>
<table><thead align="left"><tr id="row517372211165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p480357928165629"><a name="p480357928165629"></a><a name="p480357928165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1147492964165629"><a name="p1147492964165629"></a><a name="p1147492964165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1866355354165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2010499693165629"><a name="p2010499693165629"></a><a name="p2010499693165629"></a><a href="entry.md">entry</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p954612893165629"><a name="p954612893165629"></a><a name="p954612893165629"></a>Defines a hash table entry. </p>
</td>
</tr>
<tr id="row477899874165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1019496916165629"><a name="p1019496916165629"></a><a name="p1019496916165629"></a><a href="qelem.md">qelem</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1647604100165629"><a name="p1647604100165629"></a><a name="p1647604100165629"></a>Creates a queue from the doubly linked list for <a href="UTILS.md#ga7dc680d5d6d07984f96737c220058d64">insque</a> and <a href="UTILS.md#ga1d2e353620a8dc3bb2702831607a3fc1">remque</a>. </p>
</td>
</tr>
<tr id="row1832951767165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1970490928165629"><a name="p1970490928165629"></a><a name="p1970490928165629"></a><a href="hsearch_data.md">hsearch_data</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p695030956165629"><a name="p695030956165629"></a><a name="p695030956165629"></a>Defines a hash table. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table53297876165629"></a>
<table><thead align="left"><tr id="row1791038646165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1957812128165629"><a name="p1957812128165629"></a><a name="p1957812128165629"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1796810867165629"><a name="p1796810867165629"></a><a name="p1796810867165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1161816266165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p154520823165629"><a name="p154520823165629"></a><a name="p154520823165629"></a><a href="UTILS.md#gaf609835b21489409e39a22ed20313ab8">ENTRY</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1471299034165629"><a name="p1471299034165629"></a><a name="p1471299034165629"></a> typedef struct <a href="entry.md">entry</a> </p>
<p id="p91500386165629"><a name="p91500386165629"></a><a name="p91500386165629"></a>Defines a hash table entry. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table683103530165629"></a>
<table><thead align="left"><tr id="row518484557165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p998959607165629"><a name="p998959607165629"></a><a name="p998959607165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p667738585165629"><a name="p667738585165629"></a><a name="p667738585165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1830834239165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1303059224165629"><a name="p1303059224165629"></a><a name="p1303059224165629"></a><a href="UTILS.md#gafb18cb23be808765135c3aa903df62fd">hcreate</a> (size_t nel)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1497158222165629"><a name="p1497158222165629"></a><a name="p1497158222165629"></a>int </p>
<p id="p713256020165629"><a name="p713256020165629"></a><a name="p713256020165629"></a>Creates a hash table based on the number of entries. </p>
</td>
</tr>
<tr id="row876196684165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1725579522165629"><a name="p1725579522165629"></a><a name="p1725579522165629"></a><a href="UTILS.md#ga883c8dedada64c9525c78bfa56ad69bf">hdestroy</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p433441659165629"><a name="p433441659165629"></a><a name="p433441659165629"></a>void </p>
<p id="p1902850801165629"><a name="p1902850801165629"></a><a name="p1902850801165629"></a>Destroys a hash table. </p>
</td>
</tr>
<tr id="row2089274194165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p636707536165629"><a name="p636707536165629"></a><a name="p636707536165629"></a><a href="UTILS.md#ga8082cd062e20579f6a981bb73963b3f4">hsearch</a> (<a href="UTILS.md#gaf609835b21489409e39a22ed20313ab8">ENTRY</a> item, ACTION action)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p210998721165629"><a name="p210998721165629"></a><a name="p210998721165629"></a><a href="UTILS.md#gaf609835b21489409e39a22ed20313ab8">ENTRY</a> * </p>
<p id="p351738289165629"><a name="p351738289165629"></a><a name="p351738289165629"></a>Adds or searches for a hash entry. </p>
</td>
</tr>
<tr id="row605150181165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1497854466165629"><a name="p1497854466165629"></a><a name="p1497854466165629"></a><a href="UTILS.md#ga038ec523340da68e90a5f22e1e4e5520">hcreate_r</a> (size_t nel, struct <a href="hsearch_data.md">hsearch_data</a> *htab)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1076505564165629"><a name="p1076505564165629"></a><a name="p1076505564165629"></a>int </p>
<p id="p47275995165629"><a name="p47275995165629"></a><a name="p47275995165629"></a>Creates a hash table based on the number of entries and its description. </p>
</td>
</tr>
<tr id="row1201154706165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1306960145165629"><a name="p1306960145165629"></a><a name="p1306960145165629"></a><a href="UTILS.md#gafb5169db08a09e98495c26bdd7e6d8dc">hdestroy_r</a> (struct <a href="hsearch_data.md">hsearch_data</a> *htab)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1593888478165629"><a name="p1593888478165629"></a><a name="p1593888478165629"></a>void </p>
<p id="p1526136842165629"><a name="p1526136842165629"></a><a name="p1526136842165629"></a>Destroys a hash table. </p>
</td>
</tr>
<tr id="row1568764401165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p268549374165629"><a name="p268549374165629"></a><a name="p268549374165629"></a><a href="UTILS.md#ga22072d94699358ab02286f4c7b6aac55">hsearch_r</a> (<a href="UTILS.md#gaf609835b21489409e39a22ed20313ab8">ENTRY</a> item, ACTION action, <a href="UTILS.md#gaf609835b21489409e39a22ed20313ab8">ENTRY</a> **retval, struct <a href="hsearch_data.md">hsearch_data</a> *htab)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p314734639165629"><a name="p314734639165629"></a><a name="p314734639165629"></a>int </p>
<p id="p211709576165629"><a name="p211709576165629"></a><a name="p211709576165629"></a>Searches for a hash table. </p>
</td>
</tr>
<tr id="row332272497165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p428890649165629"><a name="p428890649165629"></a><a name="p428890649165629"></a><a href="UTILS.md#ga7dc680d5d6d07984f96737c220058d64">insque</a> (void *element, void *pred)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1138171382165629"><a name="p1138171382165629"></a><a name="p1138171382165629"></a>void </p>
<p id="p1783262683165629"><a name="p1783262683165629"></a><a name="p1783262683165629"></a>Adds an entry to a queue. </p>
</td>
</tr>
<tr id="row855344651165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p30501457165629"><a name="p30501457165629"></a><a name="p30501457165629"></a><a href="UTILS.md#ga1d2e353620a8dc3bb2702831607a3fc1">remque</a> (void *elem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p576082890165629"><a name="p576082890165629"></a><a name="p576082890165629"></a>void </p>
<p id="p1786870688165629"><a name="p1786870688165629"></a><a name="p1786870688165629"></a>Removes an entry from a queue. </p>
</td>
</tr>
<tr id="row604789893165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1965357535165629"><a name="p1965357535165629"></a><a name="p1965357535165629"></a><a href="UTILS.md#ga2e48c29ae7f3ef8f5707f4cc4f4ef608">lsearch</a> (const void *key, const void *base, size_t *nelp, size_t width, int(*compar)(const void *, const void *))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p985662002165629"><a name="p985662002165629"></a><a name="p985662002165629"></a>void * </p>
<p id="p1550653452165629"><a name="p1550653452165629"></a><a name="p1550653452165629"></a>Performs a linear search for a key in the array and adds a key to the end of the array if the key is not found. </p>
</td>
</tr>
<tr id="row916462268165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p305254132165629"><a name="p305254132165629"></a><a name="p305254132165629"></a><a href="UTILS.md#ga9f8c694512c6c8a53f7e5a5f5e25cf86">lfind</a> (const void *key, const void *base, size_t *nelp, size_t width, int(*compar)(const void *, const void *))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p162930022165629"><a name="p162930022165629"></a><a name="p162930022165629"></a>void * </p>
<p id="p1218062070165629"><a name="p1218062070165629"></a><a name="p1218062070165629"></a>Performs a linear search for a key in the array. </p>
</td>
</tr>
<tr id="row1446109075165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2132532079165629"><a name="p2132532079165629"></a><a name="p2132532079165629"></a><a href="UTILS.md#ga58961b9d8ec6333735b53fd0999eff17">tdelete</a> (const void *key, void **rootp, int(*compar)(const void *, const void *))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p232811138165629"><a name="p232811138165629"></a><a name="p232811138165629"></a>void * </p>
<p id="p325103886165629"><a name="p325103886165629"></a><a name="p325103886165629"></a>Deletes a key from the binary tree. </p>
</td>
</tr>
<tr id="row228615664165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p688017213165629"><a name="p688017213165629"></a><a name="p688017213165629"></a><a href="UTILS.md#ga576dc73ee732b840e09c88972b7d487e">tfind</a> (const void *key, void *const *rootp, int(*compar)(const void *, const void *))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1115272291165629"><a name="p1115272291165629"></a><a name="p1115272291165629"></a>void * </p>
<p id="p1565739043165629"><a name="p1565739043165629"></a><a name="p1565739043165629"></a>Searches for a key in the binary tree. </p>
</td>
</tr>
<tr id="row565611548165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1273969883165629"><a name="p1273969883165629"></a><a name="p1273969883165629"></a><a href="UTILS.md#ga197c455a4e5f17cb8565be72d18344cc">tsearch</a> (const void *key, void *const *rootp, int(*compar)(const void *, const void *))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1434123073165629"><a name="p1434123073165629"></a><a name="p1434123073165629"></a>void * </p>
<p id="p1821486071165629"><a name="p1821486071165629"></a><a name="p1821486071165629"></a>Searches for a key in the binary tree and adds a key to the tree if the key is not found. </p>
</td>
</tr>
<tr id="row1710129506165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p399493176165629"><a name="p399493176165629"></a><a name="p399493176165629"></a><a href="UTILS.md#ga4d8ee780402dd74ec06e7b5089565168">twalk</a> (const void *root, void(*action)(const void *nodep, VISIT which, int depth))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p299845195165629"><a name="p299845195165629"></a><a name="p299845195165629"></a>void </p>
<p id="p302906171165629"><a name="p302906171165629"></a><a name="p302906171165629"></a>Traverses a binary tree from left to right. </p>
</td>
</tr>
<tr id="row338524751165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p134839132165629"><a name="p134839132165629"></a><a name="p134839132165629"></a><a href="UTILS.md#gab12d1869fd9d20ce6706fcef217ba222">tdestroy</a> (void *root, void(*free_node)(void *nodep))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2039449474165629"><a name="p2039449474165629"></a><a name="p2039449474165629"></a>void </p>
<p id="p1030897027165629"><a name="p1030897027165629"></a><a name="p1030897027165629"></a>Releases all nodes in the binary tree. </p>
</td>
</tr>
</tbody>
</table>

