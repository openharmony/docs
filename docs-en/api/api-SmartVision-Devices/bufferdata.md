# BufferData<a name="EN-US_TOPIC_0000001054718119"></a>

-   [Overview](#section1963151255165630)
-   [Summary](#section2094519256165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section1799966536165630)
-   [Field](#section804052206165630)
-   [phyAddr](#a6e2adcd036df26d903bb8d464ac8f79d)
-   [virAddr](#a1deeebc7e7c016ff350f6fdf6e054901)

## **Overview**<a name="section1963151255165630"></a>

**Related Modules:**

[Display](display.md)

**Description:**

Defines buffer data of a layer, including the virtual and physical memory addresses. 

## **Summary**<a name="section2094519256165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table2070015862165630"></a>
<table><thead align="left"><tr id="row357254239165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p489610133165630"><a name="p489610133165630"></a><a name="p489610133165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1560771085165630"><a name="p1560771085165630"></a><a name="p1560771085165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1339850849165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1756429643165630"><a name="p1756429643165630"></a><a name="p1756429643165630"></a><a href="bufferdata.md#a6e2adcd036df26d903bb8d464ac8f79d">phyAddr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p225091868165630"><a name="p225091868165630"></a><a name="p225091868165630"></a>uint64_t </p>
</td>
</tr>
<tr id="row77733606165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1145765506165630"><a name="p1145765506165630"></a><a name="p1145765506165630"></a><a href="bufferdata.md#a1deeebc7e7c016ff350f6fdf6e054901">virAddr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1948272200165630"><a name="p1948272200165630"></a><a name="p1948272200165630"></a>void * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1799966536165630"></a>

## **Field **<a name="section804052206165630"></a>

## phyAddr<a name="a6e2adcd036df26d903bb8d464ac8f79d"></a>

```
uint64_t BufferData::phyAddr
```

 **Description:**

Physical memory address 

## virAddr<a name="a1deeebc7e7c016ff350f6fdf6e054901"></a>

```
void* BufferData::virAddr
```

 **Description:**

Virtual memory address 

