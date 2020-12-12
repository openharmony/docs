# protoent<a name="ZH-CN_TOPIC_0000001058556880"></a>

-   [Overview](#section1089534924165637)
-   [Summary](#section118561954165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section681549265165637)
-   [Field](#section1932251206165637)
-   [p\_aliases](#aa0adbe8a3e56d93695d9e1d171e1f2f4)
-   [p\_name](#ac70bd11c764a52b2ed1a7c54760b5385)
-   [p\_proto](#a3ee5b885146ea094cc17e0e210cfc606)

## **Overview**<a name="section1089534924165637"></a>

**Related Modules:**

[NET](NET.md)

**Description:**

Describes the protocol database information. 

## **Summary**<a name="section118561954165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1288831355165637"></a>
<table><thead align="left"><tr id="row1793249402165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p385091634165637"><a name="p385091634165637"></a><a name="p385091634165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p922642155165637"><a name="p922642155165637"></a><a name="p922642155165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row391307833165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p950346094165637"><a name="p950346094165637"></a><a name="p950346094165637"></a><a href="protoent.md#ac70bd11c764a52b2ed1a7c54760b5385">p_name</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p126868750165637"><a name="p126868750165637"></a><a name="p126868750165637"></a>char * </p>
</td>
</tr>
<tr id="row481014851165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1922384747165637"><a name="p1922384747165637"></a><a name="p1922384747165637"></a><a href="protoent.md#aa0adbe8a3e56d93695d9e1d171e1f2f4">p_aliases</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p563854545165637"><a name="p563854545165637"></a><a name="p563854545165637"></a>char ** </p>
</td>
</tr>
<tr id="row622292338165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1233107428165637"><a name="p1233107428165637"></a><a name="p1233107428165637"></a><a href="protoent.md#a3ee5b885146ea094cc17e0e210cfc606">p_proto</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p573671043165637"><a name="p573671043165637"></a><a name="p573671043165637"></a>int </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section681549265165637"></a>

## **Field **<a name="section1932251206165637"></a>

## p\_aliases<a name="aa0adbe8a3e56d93695d9e1d171e1f2f4"></a>

```
char** protoent::p_aliases
```

 **Description:**

Protocol alias 

## p\_name<a name="ac70bd11c764a52b2ed1a7c54760b5385"></a>

```
char* protoent::p_name
```

 **Description:**

Official protocol name 

## p\_proto<a name="a3ee5b885146ea094cc17e0e210cfc606"></a>

```
int protoent::p_proto
```

 **Description:**

Protocol number 

