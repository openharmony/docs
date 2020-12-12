# stdarg.h<a name="EN-US_TOPIC_0000001055308039"></a>

-   [Overview](#section578590524165629)
-   [Summary](#section1992330270165629)
-   [Macros](#define-members)

## **Overview**<a name="section578590524165629"></a>

**Related Modules:**

[UTILS](utils.md)

**Description:**

Provides functions and data structures, such as applying for and ending a variable-length argument list and obtaining an argument type. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1992330270165629"></a>

## Macros<a name="define-members"></a>

<a name="table128332149165629"></a>
<table><thead align="left"><tr id="row252421803165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1126726737165629"><a name="p1126726737165629"></a><a name="p1126726737165629"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p312201843165629"><a name="p312201843165629"></a><a name="p312201843165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row652212987165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2007220761165629"><a name="p2007220761165629"></a><a name="p2007220761165629"></a><a href="utils.md#gaa0628ab596c3d7e78f5e08c2d98e24da">va_start</a>(v, l)   __builtin_va_start(v,l)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1168112452165629"><a name="p1168112452165629"></a><a name="p1168112452165629"></a>Defines the start position of the variable-length argument list. </p>
</td>
</tr>
<tr id="row376010870165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p438828606165629"><a name="p438828606165629"></a><a name="p438828606165629"></a><a href="utils.md#ga823b205416e9129825841b74c3bf8484">va_end</a>(v)   __builtin_va_end(v)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2125959498165629"><a name="p2125959498165629"></a><a name="p2125959498165629"></a>Ends a variable-length argument list. </p>
</td>
</tr>
<tr id="row1806731525165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p488301716165629"><a name="p488301716165629"></a><a name="p488301716165629"></a><a href="utils.md#ga9cfd655f1203c9a345ddd90446f0bcee">va_arg</a>(v, l)   __builtin_va_arg(v,l)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1336136670165629"><a name="p1336136670165629"></a><a name="p1336136670165629"></a>Obtains the next argument in the variable-length argument list. </p>
</td>
</tr>
<tr id="row1400147264165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p434966750165629"><a name="p434966750165629"></a><a name="p434966750165629"></a><a href="utils.md#ga23a32070bb5595761e7ed3884a84eb4a">va_copy</a>(d, s)   __builtin_va_copy(d,s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1066959999165629"><a name="p1066959999165629"></a><a name="p1066959999165629"></a>Copies the previously initialized variable argument list <strong id="b1051790796165629"><a name="b1051790796165629"></a><a name="b1051790796165629"></a>s</strong> to <strong id="b1856295171165629"><a name="b1856295171165629"></a><a name="b1856295171165629"></a>d</strong>. </p>
</td>
</tr>
</tbody>
</table>

