# registry.h<a name="EN-US_TOPIC_0000001055039494"></a>

-   [Overview](#section1164334444165628)
-   [Summary](#section456991567165628)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section1164334444165628"></a>

**Related Modules:**

[Registry](registry.md)

**Description:**

Provides basic APIs for remote service registration and discovery. 

APIs provided by this file include the factory registration function of the client code. This file is used when there are customized client objects. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section456991567165628"></a>

## Typedefs<a name="typedef-members"></a>

<a name="table335539576165628"></a>
<table><thead align="left"><tr id="row653424350165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p462350907165628"><a name="p462350907165628"></a><a name="p462350907165628"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2140031014165628"><a name="p2140031014165628"></a><a name="p2140031014165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row685161963165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1535228553165628"><a name="p1535228553165628"></a><a name="p1535228553165628"></a><a href="registry.md#ga0c8aa2ef9883bd97b4f1309895adaa4c">Creator</a>) (const char *service, const char *feature, uint32 size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1586822902165628"><a name="p1586822902165628"></a><a name="p1586822902165628"></a>typedef void *(* </p>
<p id="p1057351171165628"><a name="p1057351171165628"></a><a name="p1057351171165628"></a>Indicates the creator of the customized client proxy. </p>
</td>
</tr>
<tr id="row811052883165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p765743015165628"><a name="p765743015165628"></a><a name="p765743015165628"></a><a href="registry.md#ga1e6298b1246357f70ad0b581e0eb9305">Destroyer</a>) (const char *service, const char *feature, void *iproxy)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p626077137165628"><a name="p626077137165628"></a><a name="p626077137165628"></a>typedef void(* </p>
<p id="p1784502678165628"><a name="p1784502678165628"></a><a name="p1784502678165628"></a>Indicates the destroyer of the customized client proxy. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1817982157165628"></a>
<table><thead align="left"><tr id="row2010686949165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1616234975165628"><a name="p1616234975165628"></a><a name="p1616234975165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p19232784165628"><a name="p19232784165628"></a><a name="p19232784165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1457080904165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p834516641165628"><a name="p834516641165628"></a><a name="p834516641165628"></a><a href="registry.md#ga64797e3f63201c40dbdf21b90cff23d2">SAMGR_RegisterFactory</a> (const char *service, const char *feature, <a href="registry.md#ga0c8aa2ef9883bd97b4f1309895adaa4c">Creator</a> creator, <a href="registry.md#ga1e6298b1246357f70ad0b581e0eb9305">Destroyer</a> destroyer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p345139889165628"><a name="p345139889165628"></a><a name="p345139889165628"></a>int </p>
<p id="p1198075154165628"><a name="p1198075154165628"></a><a name="p1198075154165628"></a>Registers the factory method of the client proxy object with the Samgr. </p>
</td>
</tr>
</tbody>
</table>

