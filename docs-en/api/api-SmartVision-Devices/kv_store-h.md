# kv\_store.h<a name="EN-US_TOPIC_0000001054598133"></a>

-   [Overview](#section862287878165628)
-   [Summary](#section1736678644165628)
-   [Functions](#func-members)

## **Overview**<a name="section862287878165628"></a>

**Related Modules:**

[Kv\_store](kv_store.md)

**Description:**

Provides functions for obtaining, setting, and deleting a key-value pair. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1736678644165628"></a>

## Functions<a name="func-members"></a>

<a name="table1095070005165628"></a>
<table><thead align="left"><tr id="row147108039165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1013800797165628"><a name="p1013800797165628"></a><a name="p1013800797165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2121857461165628"><a name="p2121857461165628"></a><a name="p2121857461165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2066893981165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p609576094165628"><a name="p609576094165628"></a><a name="p609576094165628"></a><a href="kv_store.md#ga6e7d17b85aeb91c0cfa912ac141d41eb">UtilsGetValue</a> (const char *key, char *value, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2060194861165628"><a name="p2060194861165628"></a><a name="p2060194861165628"></a>int </p>
<p id="p1195854214165628"><a name="p1195854214165628"></a><a name="p1195854214165628"></a>Obtains the value matching a specified key from the file system or cache. </p>
</td>
</tr>
<tr id="row31065939165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1459790341165628"><a name="p1459790341165628"></a><a name="p1459790341165628"></a><a href="kv_store.md#ga32e7222aed175357499f5ced0e85775f">UtilsSetValue</a> (const char *key, const char *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p666229653165628"><a name="p666229653165628"></a><a name="p666229653165628"></a>int </p>
<p id="p39219150165628"><a name="p39219150165628"></a><a name="p39219150165628"></a>Adds or updates the value matching a specified key in the file system or cache. </p>
</td>
</tr>
<tr id="row783928885165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1750453162165628"><a name="p1750453162165628"></a><a name="p1750453162165628"></a><a href="kv_store.md#ga803cc2bcb5206b0378ec25df7a179834">UtilsDeleteValue</a> (const char *key)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1023408341165628"><a name="p1023408341165628"></a><a name="p1023408341165628"></a>int </p>
<p id="p1176839597165628"><a name="p1176839597165628"></a><a name="p1176839597165628"></a>Deletes the value matching a specified key from the file system or cache. </p>
</td>
</tr>
<tr id="row1299465186165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1063206938165628"><a name="p1063206938165628"></a><a name="p1063206938165628"></a><a href="kv_store.md#gaebe12bab9a2e181d1fea1095a5ce4d5a">ClearKVCache</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p577712013165628"><a name="p577712013165628"></a><a name="p577712013165628"></a>int </p>
<p id="p188633151165628"><a name="p188633151165628"></a><a name="p188633151165628"></a>Clears all key-value pairs from the cache. </p>
</td>
</tr>
</tbody>
</table>

