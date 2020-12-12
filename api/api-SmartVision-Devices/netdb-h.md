# netdb.h<a name="ZH-CN_TOPIC_0000001054909432"></a>

-   [Overview](#section522354055165628)
-   [Summary](#section396219514165628)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section522354055165628"></a>

**Related Modules:**

[NET](NET.md)

**Description:**

Provides functions and data structures related to network operations. For example, you can use the functions to send and receive network data, manage network addresses, and convert bytes. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section396219514165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1965837525165628"></a>
<table><thead align="left"><tr id="row1193161300165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1284072601165628"><a name="p1284072601165628"></a><a name="p1284072601165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p951530028165628"><a name="p951530028165628"></a><a name="p951530028165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1508698289165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p237010360165628"><a name="p237010360165628"></a><a name="p237010360165628"></a><a href="hostent.md">hostent</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2028035767165628"><a name="p2028035767165628"></a><a name="p2028035767165628"></a>Describes the host name and address information. </p>
</td>
</tr>
<tr id="row2021117948165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1984725920165628"><a name="p1984725920165628"></a><a name="p1984725920165628"></a><a href="protoent.md">protoent</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1226195740165628"><a name="p1226195740165628"></a><a name="p1226195740165628"></a>Describes the protocol database information. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1301973803165628"></a>
<table><thead align="left"><tr id="row1249551633165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p803883459165628"><a name="p803883459165628"></a><a name="p803883459165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p590868828165628"><a name="p590868828165628"></a><a name="p590868828165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row705880490165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p410449291165628"><a name="p410449291165628"></a><a name="p410449291165628"></a><a href="NET.md#ga4d04a8261523c8f3473946257c12ce5b">h_addr</a>   h_addr_list[0]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1436680089165628"><a name="p1436680089165628"></a><a name="p1436680089165628"></a>Defines the first address in <strong id="b697573283165628"><a name="b697573283165628"></a><a name="b697573283165628"></a>h_addr_list</strong> for compatibility. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table688482281165628"></a>
<table><thead align="left"><tr id="row304893744165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p128665300165628"><a name="p128665300165628"></a><a name="p128665300165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1547071336165628"><a name="p1547071336165628"></a><a name="p1547071336165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1572881363165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p56314691165628"><a name="p56314691165628"></a><a name="p56314691165628"></a><a href="NET.md#ga6a806414e4ae5bffb09e3a1d25d8db75">setprotoent</a> (int stayopen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1163956187165628"><a name="p1163956187165628"></a><a name="p1163956187165628"></a>void </p>
<p id="p1631345549165628"><a name="p1631345549165628"></a><a name="p1631345549165628"></a>Opens a connection to the database and sets the next entry to the first entry. </p>
</td>
</tr>
<tr id="row1420555127165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1734829568165628"><a name="p1734829568165628"></a><a name="p1734829568165628"></a><a href="NET.md#gaca0da70657afbc3e723990bb229deec3">getprotoent</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p411043919165628"><a name="p411043919165628"></a><a name="p411043919165628"></a>struct <a href="protoent.md">protoent</a> * </p>
<p id="p1534046576165628"><a name="p1534046576165628"></a><a name="p1534046576165628"></a>Retrieves the current protocol information. </p>
</td>
</tr>
<tr id="row1722092473165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p501971423165628"><a name="p501971423165628"></a><a name="p501971423165628"></a><a href="NET.md#ga83ac8a97dd9d895cda658af3aa46fd55">getprotobyname</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p84797612165628"><a name="p84797612165628"></a><a name="p84797612165628"></a>struct <a href="protoent.md">protoent</a> * </p>
<p id="p1271668328165628"><a name="p1271668328165628"></a><a name="p1271668328165628"></a>Retrieves the information about a specified protocol. </p>
</td>
</tr>
<tr id="row1343701595165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1024057221165628"><a name="p1024057221165628"></a><a name="p1024057221165628"></a><a href="NET.md#gac01697dc4a5b8e434522220913bd46ea">getprotobynumber</a> (int num)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1879540640165628"><a name="p1879540640165628"></a><a name="p1879540640165628"></a>struct <a href="protoent.md">protoent</a> * </p>
<p id="p603300628165628"><a name="p603300628165628"></a><a name="p603300628165628"></a>Retrieves the information about a protocol with the specified number. </p>
</td>
</tr>
<tr id="row2010876471165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1843339889165628"><a name="p1843339889165628"></a><a name="p1843339889165628"></a><a href="NET.md#gaa68de2578d4e0849f82d70b2f5b9af70">herror</a> (const char *msg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2103912834165628"><a name="p2103912834165628"></a><a name="p2103912834165628"></a>void </p>
<p id="p929952898165628"><a name="p929952898165628"></a><a name="p929952898165628"></a>Prints error information. </p>
</td>
</tr>
<tr id="row2078792913165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p288483793165628"><a name="p288483793165628"></a><a name="p288483793165628"></a><a href="NET.md#gac1752c48d9cf2ff87e29f29df6caa585">hstrerror</a> (int ecode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1901645505165628"><a name="p1901645505165628"></a><a name="p1901645505165628"></a>const char * </p>
<p id="p644563864165628"><a name="p644563864165628"></a><a name="p644563864165628"></a>Retrieves error information associated with the specified error number. </p>
</td>
</tr>
</tbody>
</table>

