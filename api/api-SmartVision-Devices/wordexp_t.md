# wordexp\_t<a name="ZH-CN_TOPIC_0000001054598211"></a>

-   [Overview](#section934952805165637)
-   [Summary](#section74314588165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section1549392748165637)
-   [Field](#section1382145372165637)
-   [we\_offs](#a956cc2725b2ed52f61efd3fc8dfca853)
-   [we\_wordc](#aeca511502c524dbf33993c02cf7127c7)
-   [we\_wordv](#a00d1aa490abf8b5d0f6a1e04a323329b)

## **Overview**<a name="section934952805165637"></a>

**Related Modules:**

[IO](IO.md)

**Description:**

Describes information about word expansion. 

## **Summary**<a name="section74314588165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1426258748165637"></a>
<table><thead align="left"><tr id="row1933604180165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p586351869165637"><a name="p586351869165637"></a><a name="p586351869165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p449987078165637"><a name="p449987078165637"></a><a name="p449987078165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row17432424165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1249261897165637"><a name="p1249261897165637"></a><a name="p1249261897165637"></a><a href="wordexp_t.md#aeca511502c524dbf33993c02cf7127c7">we_wordc</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p632329336165637"><a name="p632329336165637"></a><a name="p632329336165637"></a>size_t </p>
</td>
</tr>
<tr id="row164450851165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1291339955165637"><a name="p1291339955165637"></a><a name="p1291339955165637"></a><a href="wordexp_t.md#a00d1aa490abf8b5d0f6a1e04a323329b">we_wordv</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1652215092165637"><a name="p1652215092165637"></a><a name="p1652215092165637"></a>char ** </p>
</td>
</tr>
<tr id="row2036313565165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1820241319165637"><a name="p1820241319165637"></a><a name="p1820241319165637"></a><a href="wordexp_t.md#a956cc2725b2ed52f61efd3fc8dfca853">we_offs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1939842775165637"><a name="p1939842775165637"></a><a name="p1939842775165637"></a>size_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1549392748165637"></a>

## **Field **<a name="section1382145372165637"></a>

## we\_offs<a name="a956cc2725b2ed52f61efd3fc8dfca853"></a>

```
size_t wordexp_t::we_offs
```

 **Description:**

Offset of the word string 

## we\_wordc<a name="aeca511502c524dbf33993c02cf7127c7"></a>

```
size_t wordexp_t::we_wordc
```

 **Description:**

Number of words 

## we\_wordv<a name="a00d1aa490abf8b5d0f6a1e04a323329b"></a>

```
char** wordexp_t::we_wordv
```

 **Description:**

Address of the word string 

