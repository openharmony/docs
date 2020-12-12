# iconv.h<a name="ZH-CN_TOPIC_0000001055547978"></a>

-   [Overview](#section345551095165627)
-   [Summary](#section61299095165627)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section345551095165627"></a>

**Related Modules:**

[IO](IO.md)

**Description:**

Declares functions related to the I/O character set conversion. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section61299095165627"></a>

## Typedefs<a name="typedef-members"></a>

<a name="table214952925165627"></a>
<table><thead align="left"><tr id="row515638819165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1571962477165627"><a name="p1571962477165627"></a><a name="p1571962477165627"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1243291934165627"><a name="p1243291934165627"></a><a name="p1243291934165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1680032769165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1081702103165627"><a name="p1081702103165627"></a><a name="p1081702103165627"></a><a href="IO.md#ga72517f6ffadddaafa9d51dee9b535c9f">iconv_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1733723817165627"><a name="p1733723817165627"></a><a name="p1733723817165627"></a> typedef void * </p>
<p id="p1933359703165627"><a name="p1933359703165627"></a><a name="p1933359703165627"></a>Type of the character set conversion descriptor. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1881901115165627"></a>
<table><thead align="left"><tr id="row1358602972165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1178597599165627"><a name="p1178597599165627"></a><a name="p1178597599165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1994613532165627"><a name="p1994613532165627"></a><a name="p1994613532165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row128439752165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p962678678165627"><a name="p962678678165627"></a><a name="p962678678165627"></a><a href="IO.md#ga934548ab8aaae237ac5cce0ed0b3edec">iconv_open</a> (const char *to, const char *from)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2070127239165627"><a name="p2070127239165627"></a><a name="p2070127239165627"></a><a href="IO.md#ga72517f6ffadddaafa9d51dee9b535c9f">iconv_t</a> </p>
<p id="p341724696165627"><a name="p341724696165627"></a><a name="p341724696165627"></a>Obtain a character set conversion descriptor. </p>
</td>
</tr>
<tr id="row168680754165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1668224080165627"><a name="p1668224080165627"></a><a name="p1668224080165627"></a><a href="IO.md#gab7c1300a663def659ce6d4a01076c39d">iconv</a> (<a href="IO.md#ga72517f6ffadddaafa9d51dee9b535c9f">iconv_t</a> cd, char **restrict in, size_t *restrict inb, char **restrict out, size_t *restrict outb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1174947926165627"><a name="p1174947926165627"></a><a name="p1174947926165627"></a>size_t </p>
<p id="p866576120165627"><a name="p866576120165627"></a><a name="p866576120165627"></a>Converts a character set. </p>
</td>
</tr>
<tr id="row1149185953165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p119339656165627"><a name="p119339656165627"></a><a name="p119339656165627"></a><a href="IO.md#ga062da5f802d9e274a8702f11921e691b">iconv_close</a> (<a href="IO.md#ga72517f6ffadddaafa9d51dee9b535c9f">iconv_t</a> cd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p944686055165627"><a name="p944686055165627"></a><a name="p944686055165627"></a>int </p>
<p id="p1842755855165627"><a name="p1842755855165627"></a><a name="p1842755855165627"></a>Closes a character set conversion descriptor. </p>
</td>
</tr>
</tbody>
</table>

