# resolv.h<a name="ZH-CN_TOPIC_0000001055308037"></a>

-   [Overview](#section382619964165628)
-   [Summary](#section161328308165628)
-   [Functions](#func-members)

## **Overview**<a name="section382619964165628"></a>

**Related Modules:**

[NET](NET.md)

**Description:**

Provides functions and data structures related to network operations. For example, you can use the functions to send and receive network data, manage network addresses, and convert bytes. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section161328308165628"></a>

## Functions<a name="func-members"></a>

<a name="table73436815165628"></a>
<table><thead align="left"><tr id="row264178795165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1082630153165628"><a name="p1082630153165628"></a><a name="p1082630153165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1011390346165628"><a name="p1011390346165628"></a><a name="p1011390346165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1793644960165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1157580785165628"><a name="p1157580785165628"></a><a name="p1157580785165628"></a><a href="NET.md#ga0438570faf515401bffa1a0d9c94a266">dn_comp</a> (const char *src, unsigned char *dst, int space, unsigned char **dnptrs, unsigned char **lastdnptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p772950711165628"><a name="p772950711165628"></a><a name="p772950711165628"></a>int </p>
<p id="p2063382266165628"><a name="p2063382266165628"></a><a name="p2063382266165628"></a>Compresses a network domain name. </p>
</td>
</tr>
<tr id="row988320917165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p310396063165628"><a name="p310396063165628"></a><a name="p310396063165628"></a><a href="NET.md#ga91eb2055a64b28e4942a3a760d747243">dn_expand</a> (const unsigned char *base, const unsigned char *end, const unsigned char *src, char *dest, int space)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1668302687165628"><a name="p1668302687165628"></a><a name="p1668302687165628"></a>int </p>
<p id="p820497556165628"><a name="p820497556165628"></a><a name="p820497556165628"></a>Expands a compressed domain name to a full domain name. </p>
</td>
</tr>
</tbody>
</table>

