# strings.h<a name="EN-US_TOPIC_0000001055707984"></a>

-   [Overview](#section1129275238165629)
-   [Summary](#section1961971547165629)
-   [Functions](#func-members)

## **Overview**<a name="section1129275238165629"></a>

**Related Modules:**

[UTILS](utils.md)

**Description:**

Declares commonly used functions for byte sequence operations. 

You can use the functions provided in this file to perform the mathematical operations required during development. Example operations include comparing, copying byte sequences, and setting a byte sequence to 0. You must pay attention to memory management during function calls. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1961971547165629"></a>

## Functions<a name="func-members"></a>

<a name="table709132478165629"></a>
<table><thead align="left"><tr id="row2078853865165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p623901159165629"><a name="p623901159165629"></a><a name="p623901159165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p515543131165629"><a name="p515543131165629"></a><a name="p515543131165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1746205295165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1672635498165629"><a name="p1672635498165629"></a><a name="p1672635498165629"></a><a href="utils.md#ga840ecc6fc750bf00e99015d2817b0e12">bcmp</a> (const void *s1, const void *s2, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p786917942165629"><a name="p786917942165629"></a><a name="p786917942165629"></a>int </p>
<p id="p1634808064165629"><a name="p1634808064165629"></a><a name="p1634808064165629"></a>Compares byte sequences. </p>
</td>
</tr>
<tr id="row1093949628165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p786969966165629"><a name="p786969966165629"></a><a name="p786969966165629"></a><a href="utils.md#ga2bf0688adef533a3285e7e0c00f98ff8">bcopy</a> (const void *src, void *dest, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p653789258165629"><a name="p653789258165629"></a><a name="p653789258165629"></a>void </p>
<p id="p1315899775165629"><a name="p1315899775165629"></a><a name="p1315899775165629"></a>Copies byte sequences. </p>
</td>
</tr>
<tr id="row1586077921165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p736057118165629"><a name="p736057118165629"></a><a name="p736057118165629"></a><a href="utils.md#ga59505af7f1c47ff01fdb944801642033">bzero</a> (void *s, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p246572152165629"><a name="p246572152165629"></a><a name="p246572152165629"></a>void </p>
<p id="p1461435299165629"><a name="p1461435299165629"></a><a name="p1461435299165629"></a>Sets byte sequences to zero. </p>
</td>
</tr>
<tr id="row172378299165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1481809596165629"><a name="p1481809596165629"></a><a name="p1481809596165629"></a><a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a> (const char *s, int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1411167633165629"><a name="p1411167633165629"></a><a name="p1411167633165629"></a>char * </p>
<p id="p1363828192165629"><a name="p1363828192165629"></a><a name="p1363828192165629"></a>Searches for the first position of the matched character in a string. </p>
</td>
</tr>
<tr id="row178875571165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1370124016165629"><a name="p1370124016165629"></a><a name="p1370124016165629"></a><a href="utils.md#ga83d9aa3251fdee263ad43bf75933de46">rindex</a> (const char *s, int c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p461590210165629"><a name="p461590210165629"></a><a name="p461590210165629"></a>char * </p>
<p id="p2110794630165629"><a name="p2110794630165629"></a><a name="p2110794630165629"></a>Searches for the last position of the matched character in a string. </p>
</td>
</tr>
<tr id="row169709790165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2044269330165629"><a name="p2044269330165629"></a><a name="p2044269330165629"></a><a href="utils.md#ga2385d975eddea296daa497e5d36febc9">ffs</a> (int i)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p90066550165629"><a name="p90066550165629"></a><a name="p90066550165629"></a>int </p>
<p id="p1180846952165629"><a name="p1180846952165629"></a><a name="p1180846952165629"></a>Searches for the first bit in a word of the integer type. </p>
</td>
</tr>
<tr id="row1818252247165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2101348178165629"><a name="p2101348178165629"></a><a name="p2101348178165629"></a><a href="utils.md#ga73690a58537a6dbafa9aa4b3afa7baac">ffsl</a> (long int i)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p812590975165629"><a name="p812590975165629"></a><a name="p812590975165629"></a>int </p>
<p id="p488625065165629"><a name="p488625065165629"></a><a name="p488625065165629"></a>Searches for the first bit in a word of the long integer type. </p>
</td>
</tr>
<tr id="row68786877165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1930600002165629"><a name="p1930600002165629"></a><a name="p1930600002165629"></a><a href="utils.md#gae7eaa572ad4e097865bd409b121fb33c">ffsll</a> (long long int i)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1454843313165629"><a name="p1454843313165629"></a><a name="p1454843313165629"></a>int </p>
<p id="p2071239777165629"><a name="p2071239777165629"></a><a name="p2071239777165629"></a>Searches for the first bit in a word of the 8-byte long integer type. </p>
</td>
</tr>
<tr id="row1667901238165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p717826378165629"><a name="p717826378165629"></a><a name="p717826378165629"></a><a href="utils.md#ga2436604f43de7f27e7434ceea7d64528">strcasecmp</a> (const char *_l, const char *_r)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1447481630165629"><a name="p1447481630165629"></a><a name="p1447481630165629"></a>int </p>
<p id="p1158588758165629"><a name="p1158588758165629"></a><a name="p1158588758165629"></a>Compares two strings (string 1 and string 2), regardless of the letter case. </p>
</td>
</tr>
<tr id="row1262418822165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p510961782165629"><a name="p510961782165629"></a><a name="p510961782165629"></a><a href="utils.md#ga103fd689d8438a246e0cd4d90cb084ac">strncasecmp</a> (const char *_l, const char *_r, size_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p631721396165629"><a name="p631721396165629"></a><a name="p631721396165629"></a>int </p>
<p id="p2108044422165629"><a name="p2108044422165629"></a><a name="p2108044422165629"></a>Compares a specified length of two strings (string 1 and string 2), regardless of the letter case. </p>
</td>
</tr>
</tbody>
</table>

