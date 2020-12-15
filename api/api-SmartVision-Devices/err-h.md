# err.h<a name="ZH-CN_TOPIC_0000001055547976"></a>

-   [Overview](#section832343483165627)
-   [Summary](#section1715116744165627)
-   [Functions](#func-members)

## **Overview**<a name="section832343483165627"></a>

**Related Modules:**

[IO](IO.md)

**Description:**

Provides common functions for error messages. 

You can use the functions provided in this file to implement error output operations required during development. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1715116744165627"></a>

## Functions<a name="func-members"></a>

<a name="table13941930165627"></a>
<table><thead align="left"><tr id="row48916791165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1518524409165627"><a name="p1518524409165627"></a><a name="p1518524409165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1192702849165627"><a name="p1192702849165627"></a><a name="p1192702849165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1237474727165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p203843943165627"><a name="p203843943165627"></a><a name="p203843943165627"></a><a href="IO.md#gaf80d19f1297a11626fab61a248959c71">warn</a> (const char *fmt,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2139168003165627"><a name="p2139168003165627"></a><a name="p2139168003165627"></a>void </p>
<p id="p89425521165627"><a name="p89425521165627"></a><a name="p89425521165627"></a>Displays a formatted error message on the standard error (stderr) output. </p>
</td>
</tr>
<tr id="row1902203483165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p505283285165627"><a name="p505283285165627"></a><a name="p505283285165627"></a><a href="IO.md#ga9ca1ffba0c6f5df7b172d25917611b4a">vwarn</a> (const char *fmt, va_list args)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p943295570165627"><a name="p943295570165627"></a><a name="p943295570165627"></a>void </p>
<p id="p1985656226165627"><a name="p1985656226165627"></a><a name="p1985656226165627"></a>Displays a formatted error message on the stderr output. </p>
</td>
</tr>
<tr id="row532296019165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1625063606165627"><a name="p1625063606165627"></a><a name="p1625063606165627"></a><a href="IO.md#ga58f3d9691c146f86e562022d39567b7f">warnx</a> (const char *fmt,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1497677291165627"><a name="p1497677291165627"></a><a name="p1497677291165627"></a>void </p>
<p id="p67685469165627"><a name="p67685469165627"></a><a name="p67685469165627"></a>Displays a formatted error message on the stderr output. </p>
</td>
</tr>
<tr id="row1120347671165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1491809491165627"><a name="p1491809491165627"></a><a name="p1491809491165627"></a><a href="IO.md#ga22924aaaaa6b6e8bba4c76d0a0fe86cd">vwarnx</a> (const char *fmt, va_list args)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p954101587165627"><a name="p954101587165627"></a><a name="p954101587165627"></a>void </p>
<p id="p1385160002165627"><a name="p1385160002165627"></a><a name="p1385160002165627"></a>Displays a formatted error message on the stderr output. </p>
</td>
</tr>
<tr id="row723061935165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1078388478165627"><a name="p1078388478165627"></a><a name="p1078388478165627"></a><a href="IO.md#gaa6b66a9a8eb4be40e4424a4dc92ae056">err</a> (int eval, const char *fmt, va_list args)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1367525416165627"><a name="p1367525416165627"></a><a name="p1367525416165627"></a>void </p>
<p id="p1908935748165627"><a name="p1908935748165627"></a><a name="p1908935748165627"></a>Displays error information. </p>
</td>
</tr>
<tr id="row137061952165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p466826215165627"><a name="p466826215165627"></a><a name="p466826215165627"></a><a href="IO.md#gaeaca83913c785b95d6c50f35207ff739">errx</a> (int eval, const char *fmt,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1799728815165627"><a name="p1799728815165627"></a><a name="p1799728815165627"></a>void </p>
<p id="p244178430165627"><a name="p244178430165627"></a><a name="p244178430165627"></a>Displays error information. </p>
</td>
</tr>
<tr id="row632767018165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1561266865165627"><a name="p1561266865165627"></a><a name="p1561266865165627"></a><a href="IO.md#gaf5491fca8b356da75d96fc469bf32ea6">verr</a> (int eval, const char *fmt, va_list args)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1647844851165627"><a name="p1647844851165627"></a><a name="p1647844851165627"></a>void </p>
<p id="p1474377952165627"><a name="p1474377952165627"></a><a name="p1474377952165627"></a>Displays error information. </p>
</td>
</tr>
<tr id="row1979295607165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p813474350165627"><a name="p813474350165627"></a><a name="p813474350165627"></a><a href="IO.md#ga4b5f9ccd84c00dc473329e4bf64125e1">verrx</a> (int eval, const char *fmt, va_list args)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1597565379165627"><a name="p1597565379165627"></a><a name="p1597565379165627"></a>void </p>
<p id="p610015088165627"><a name="p610015088165627"></a><a name="p610015088165627"></a>Displays a formatted error message. </p>
</td>
</tr>
</tbody>
</table>

