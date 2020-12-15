# Kv\_store<a name="EN-US_TOPIC_0000001054918111"></a>

-   [Overview](#section2003898650165625)
-   [Summary](#section324745041165625)
-   [Files](#files)
-   [Functions](#func-members)
-   [Details](#section1972519997165625)
-   [Function](#section178236753165625)
-   [ClearKVCache\(\)](#gaebe12bab9a2e181d1fea1095a5ce4d5a)
-   [UtilsDeleteValue\(\)](#ga803cc2bcb5206b0378ec25df7a179834)
-   [UtilsGetValue\(\)](#ga6e7d17b85aeb91c0cfa912ac141d41eb)
-   [UtilsSetValue\(\)](#ga32e7222aed175357499f5ced0e85775f)

## **Overview**<a name="section2003898650165625"></a>

**Description:**

Provides functions for obtaining, setting, and deleting a key-value pair. 

Key-value pairs can be permanently stored in the file system. If  [FEATURE\_KV\_CACHE](utils_config.md#gad3d71669516ef0bb50e2b105507a6b29)  is enabled, key-value pairs can be stored in the cache. For details about cache specifications, see  [MAX\_CACHE\_SIZE](utils_config.md#ga6c8469dfe973ac952cf40394bd2c160b). For details about the number of key-value pairs that can be stored in an application, see  [MAX\_KV\_SUM](utils_config.md#ga4f258bd7d7d52c6770cce77f3e16ce72). 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section324745041165625"></a>

## Files<a name="files"></a>

<a name="table1752726379165625"></a>
<table><thead align="left"><tr id="row515659175165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1844207572165625"><a name="p1844207572165625"></a><a name="p1844207572165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1116936408165625"><a name="p1116936408165625"></a><a name="p1116936408165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1516986958165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p985489995165625"><a name="p985489995165625"></a><a name="p985489995165625"></a><a href="kv_store-h.md">kv_store.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p303940786165625"><a name="p303940786165625"></a><a name="p303940786165625"></a>Provides functions for obtaining, setting, and deleting a key-value pair. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table684894424165625"></a>
<table><thead align="left"><tr id="row1727230214165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1117668522165625"><a name="p1117668522165625"></a><a name="p1117668522165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p709555883165625"><a name="p709555883165625"></a><a name="p709555883165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1456373705165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p998194844165625"><a name="p998194844165625"></a><a name="p998194844165625"></a><a href="kv_store.md#ga6e7d17b85aeb91c0cfa912ac141d41eb">UtilsGetValue</a> (const char *key, char *value, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p395447741165625"><a name="p395447741165625"></a><a name="p395447741165625"></a>int </p>
<p id="p1851981443165625"><a name="p1851981443165625"></a><a name="p1851981443165625"></a>Obtains the value matching a specified key from the file system or cache. </p>
</td>
</tr>
<tr id="row568744043165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1429842222165625"><a name="p1429842222165625"></a><a name="p1429842222165625"></a><a href="kv_store.md#ga32e7222aed175357499f5ced0e85775f">UtilsSetValue</a> (const char *key, const char *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p867344598165625"><a name="p867344598165625"></a><a name="p867344598165625"></a>int </p>
<p id="p2053575300165625"><a name="p2053575300165625"></a><a name="p2053575300165625"></a>Adds or updates the value matching a specified key in the file system or cache. </p>
</td>
</tr>
<tr id="row1240384965165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1292221143165625"><a name="p1292221143165625"></a><a name="p1292221143165625"></a><a href="kv_store.md#ga803cc2bcb5206b0378ec25df7a179834">UtilsDeleteValue</a> (const char *key)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1659948893165625"><a name="p1659948893165625"></a><a name="p1659948893165625"></a>int </p>
<p id="p731710694165625"><a name="p731710694165625"></a><a name="p731710694165625"></a>Deletes the value matching a specified key from the file system or cache. </p>
</td>
</tr>
<tr id="row1853674606165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1125604590165625"><a name="p1125604590165625"></a><a name="p1125604590165625"></a><a href="kv_store.md#gaebe12bab9a2e181d1fea1095a5ce4d5a">ClearKVCache</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1964717588165625"><a name="p1964717588165625"></a><a name="p1964717588165625"></a>int </p>
<p id="p1313880623165625"><a name="p1313880623165625"></a><a name="p1313880623165625"></a>Clears all key-value pairs from the cache. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1972519997165625"></a>

## **Function **<a name="section178236753165625"></a>

## ClearKVCache\(\)<a name="gaebe12bab9a2e181d1fea1095a5ce4d5a"></a>

```
int ClearKVCache (void )
```

 **Description:**

Clears all key-value pairs from the cache. 

**Attention:**

This function is available only if  [FEATURE\_KV\_CACHE](utils_config.md#gad3d71669516ef0bb50e2b105507a6b29)  is enabled. 

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## UtilsDeleteValue\(\)<a name="ga803cc2bcb5206b0378ec25df7a179834"></a>

```
int UtilsDeleteValue (const char * key)
```

 **Description:**

Deletes the value matching a specified key from the file system or cache. 

**Parameters:**

<a name="table620699289165625"></a>
<table><thead align="left"><tr id="row2095538912165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p908341605165625"><a name="p908341605165625"></a><a name="p908341605165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1559254701165625"><a name="p1559254701165625"></a><a name="p1559254701165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row807159645165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the key whose value is to be deleted. It allows only lowercase letters, digits, underscores (_), and dots (.). Its length cannot exceed 32 bytes (including the end-of-text character in the string). </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-9**  if a parameter is incorrect; returns  **-1**  in other scenarios. 

## UtilsGetValue\(\)<a name="ga6e7d17b85aeb91c0cfa912ac141d41eb"></a>

```
int UtilsGetValue (const char * key, char * value, unsigned int len )
```

 **Description:**

Obtains the value matching a specified key from the file system or cache. 

**Parameters:**

<a name="table1028553356165625"></a>
<table><thead align="left"><tr id="row342905759165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p983495772165625"><a name="p983495772165625"></a><a name="p983495772165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1109260961165625"><a name="p1109260961165625"></a><a name="p1109260961165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1258689655165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the key to be indexed. It allows only lowercase letters, digits, underscores (_), and dots (.). Its length cannot exceed 32 bytes (including the end-of-text character in the string). </td>
</tr>
<tr id="row1569570671165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the buffer for storing the value that matches the key. This is an output parameter. </td>
</tr>
<tr id="row2145064914165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the value space in the buffer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the length of the value if the operation is successful; returns  **-9**  if a parameter is incorrect; returns  **-1**  in other scenarios; returns  **0**  if the value is obtained from the cache. 

## UtilsSetValue\(\)<a name="ga32e7222aed175357499f5ced0e85775f"></a>

```
int UtilsSetValue (const char * key, const char * value )
```

 **Description:**

Adds or updates the value matching a specified key in the file system or cache. 

**Parameters:**

<a name="table1004055563165625"></a>
<table><thead align="left"><tr id="row967359286165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1873033213165625"><a name="p1873033213165625"></a><a name="p1873033213165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1333867317165625"><a name="p1333867317165625"></a><a name="p1333867317165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row378070561165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the key whose value is to be added or updated. It allows only lowercase letters, digits, underscores (_), and dots (.). Its length cannot exceed 32 bytes (including the end-of-text character in the string). </td>
</tr>
<tr id="row323600325165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value to be added or updated. Its length cannot exceed 128 bytes (including the end-of-text character in the string). </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-9**  if a parameter is incorrect; returns  **-1**  in other scenarios. 

