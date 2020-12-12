# ether.h<a name="ZH-CN_TOPIC_0000001054829483"></a>

-   [Overview](#section842490371165627)
-   [Summary](#section509898439165627)
-   [Functions](#func-members)

## **Overview**<a name="section842490371165627"></a>

**Related Modules:**

[NET](NET.md)

**Description:**

Provides functions and data structures related to network operations. For example, you can use the functions to send and receive network data, manage network addresses, and convert bytes. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section509898439165627"></a>

## Functions<a name="func-members"></a>

<a name="table892133621165627"></a>
<table><thead align="left"><tr id="row439431958165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1101875334165627"><a name="p1101875334165627"></a><a name="p1101875334165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1463973796165627"><a name="p1463973796165627"></a><a name="p1463973796165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1045514447165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p32797029165627"><a name="p32797029165627"></a><a name="p32797029165627"></a><a href="NET.md#ga07e34e6ee9e272c4799780915d11677c">ether_ntoa</a> (const struct <a href="ether_addr.md">ether_addr</a> *p_a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p269017894165627"><a name="p269017894165627"></a><a name="p269017894165627"></a>char * </p>
<p id="p1405780510165627"><a name="p1405780510165627"></a><a name="p1405780510165627"></a>Converts binary data in network byte order into a standard 48-bit Ethernet host address in the colon hexadecimal notation. </p>
</td>
</tr>
<tr id="row1718720621165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1842664051165627"><a name="p1842664051165627"></a><a name="p1842664051165627"></a><a href="NET.md#gaab4c5b65c36fc0ea96a017daabc3770a">ether_aton</a> (const char *x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1774432318165627"><a name="p1774432318165627"></a><a name="p1774432318165627"></a>struct <a href="ether_addr.md">ether_addr</a> * </p>
<p id="p367727982165627"><a name="p367727982165627"></a><a name="p367727982165627"></a>Converts a standard 48-bit Ethernet host address in the colon hexadecimal notation into binary data in network byte order. </p>
</td>
</tr>
<tr id="row73087080165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1017411538165627"><a name="p1017411538165627"></a><a name="p1017411538165627"></a><a href="NET.md#ga245e21de8e82756712a5182c2674c2ad">ether_ntoa_r</a> (const struct <a href="ether_addr.md">ether_addr</a> *p_a, char *x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1552430569165627"><a name="p1552430569165627"></a><a name="p1552430569165627"></a>char * </p>
<p id="p980051516165627"><a name="p980051516165627"></a><a name="p980051516165627"></a>Converts binary data in network byte order into a standard 48-bit Ethernet host address in the colon hexadecimal notation. This function is reentrant. </p>
</td>
</tr>
<tr id="row1535756929165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1348972757165627"><a name="p1348972757165627"></a><a name="p1348972757165627"></a><a href="NET.md#gac0954821754bace30f674e61bb9f4e5f">ether_aton_r</a> (const char *x, struct <a href="ether_addr.md">ether_addr</a> *p_a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1068616605165627"><a name="p1068616605165627"></a><a name="p1068616605165627"></a>struct <a href="ether_addr.md">ether_addr</a> * </p>
<p id="p1580477893165627"><a name="p1580477893165627"></a><a name="p1580477893165627"></a>Converts a standard 48-bit Ethernet host address in the colon hexadecimal notation into binary data in network byte order. This function is reentrant. </p>
</td>
</tr>
</tbody>
</table>

