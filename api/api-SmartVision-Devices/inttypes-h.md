# inttypes.h<a name="ZH-CN_TOPIC_0000001055228016"></a>

-   [Overview](#section1985275435165627)
-   [Summary](#section2145262334165627)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section1985275435165627"></a>

**Related Modules:**

[UTILS](UTILS.md)

**Description:**

Provides functions and related data structures for conversion between character strings and plural. 

You can use the functions provided in this file to perform operations related to wide character types during development, for example, performing a division operation, converting a character string to an imax-type parameter, or converting a character string to an umax-type parameter. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2145262334165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1418773867165627"></a>
<table><thead align="left"><tr id="row1865678079165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p160523429165627"><a name="p160523429165627"></a><a name="p160523429165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p200038745165627"><a name="p200038745165627"></a><a name="p200038745165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1597182251165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1794916303165627"><a name="p1794916303165627"></a><a name="p1794916303165627"></a><a href="imaxdiv_t.md">imaxdiv_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p943500313165627"><a name="p943500313165627"></a><a name="p943500313165627"></a>Stores the division result. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table72266491165627"></a>
<table><thead align="left"><tr id="row2005595762165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1900189688165627"><a name="p1900189688165627"></a><a name="p1900189688165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2013527666165627"><a name="p2013527666165627"></a><a name="p2013527666165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2010791060165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1464850452165627"><a name="p1464850452165627"></a><a name="p1464850452165627"></a><a href="UTILS.md#gad9e8a565a34b6981f500d88773ec7bcd">imaxabs</a> (intmax_t j)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p588776228165627"><a name="p588776228165627"></a><a name="p588776228165627"></a>intmax_t </p>
<p id="p1115531093165627"><a name="p1115531093165627"></a><a name="p1115531093165627"></a>Calculates the absolute value of an input parameter of the integer type. </p>
</td>
</tr>
<tr id="row1337342819165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p734023917165627"><a name="p734023917165627"></a><a name="p734023917165627"></a><a href="UTILS.md#ga17335f74f0abcfd3047de48f6823f527">imaxdiv</a> (intmax_t numerator, intmax_t denominator)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1868519906165627"><a name="p1868519906165627"></a><a name="p1868519906165627"></a><a href="imaxdiv_t.md">imaxdiv_t</a> </p>
<p id="p526346920165627"><a name="p526346920165627"></a><a name="p526346920165627"></a>Calculates the quotient and remainder after the division operation is performed on an integer. </p>
</td>
</tr>
<tr id="row690918099165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p307729161165627"><a name="p307729161165627"></a><a name="p307729161165627"></a><a href="UTILS.md#ga996146b4c9a860837a1f09868a6c0a61">strtoimax</a> (const char *str, char **endptr, int base)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1674514191165627"><a name="p1674514191165627"></a><a name="p1674514191165627"></a>intmax_t </p>
<p id="p416386107165627"><a name="p416386107165627"></a><a name="p416386107165627"></a>Parses a string to a value of the <strong id="b566341765165627"><a name="b566341765165627"></a><a name="b566341765165627"></a>intmax_t</strong> type. </p>
</td>
</tr>
<tr id="row259311859165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1707376333165627"><a name="p1707376333165627"></a><a name="p1707376333165627"></a><a href="UTILS.md#ga706f89e2b5a9a623207f2d77b19ff6f8">strtoumax</a> (const char *str, char **endptr, int base)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p951450077165627"><a name="p951450077165627"></a><a name="p951450077165627"></a>uintmax_t </p>
<p id="p1187812948165627"><a name="p1187812948165627"></a><a name="p1187812948165627"></a>Parses a string to a value of the <strong id="b1052596759165627"><a name="b1052596759165627"></a><a name="b1052596759165627"></a>uintmax_t</strong> type. </p>
</td>
</tr>
<tr id="row1168416385165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1648559910165627"><a name="p1648559910165627"></a><a name="p1648559910165627"></a><a href="UTILS.md#gaab72fde556caed7f725c0bece02e4cc9">wcstoimax</a> (const wchar_t *str, wchar_t **endptr, int base)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1335443950165627"><a name="p1335443950165627"></a><a name="p1335443950165627"></a>intmax_t </p>
<p id="p1694383090165627"><a name="p1694383090165627"></a><a name="p1694383090165627"></a>Parses a string to a value of the <strong id="b569049449165627"><a name="b569049449165627"></a><a name="b569049449165627"></a>intmax_t</strong> type. </p>
</td>
</tr>
<tr id="row119691724165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2075373805165627"><a name="p2075373805165627"></a><a name="p2075373805165627"></a><a href="UTILS.md#gaaf3fa62320e289517f453bf1e470a1f9">wcstoumax</a> (const wchar_t *str, wchar_t **endptr, int base)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p789419268165627"><a name="p789419268165627"></a><a name="p789419268165627"></a>uintmax_t </p>
<p id="p1591817580165627"><a name="p1591817580165627"></a><a name="p1591817580165627"></a>Parses a string to a value of the <strong id="b1949500402165627"><a name="b1949500402165627"></a><a name="b1949500402165627"></a>uintmax_t</strong> type. </p>
</td>
</tr>
</tbody>
</table>

