# FTW<a name="ZH-CN_TOPIC_0000001055078137"></a>

-   [Overview](#section2113894244165631)
-   [Summary](#section719265223165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section2063003499165631)
-   [Field](#section956008264165631)
-   [base](#adc64b6d8f0f13269fdb026b67c1a6b11)
-   [level](#af3d03dada9fed0c37d2cb30ff742c130)

## **Overview**<a name="section2113894244165631"></a>

**Related Modules:**

[FS](FS.md)

**Description:**

Defines the file tree walker \([FTW](FTW.md)\). 

**[ftw.h](ftw-h.md)**  describes the  **[FTW](FTW.md)**  structure. The file location can be determined based on the offset and the depth relative to the root node. 

## **Summary**<a name="section719265223165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table882519815165631"></a>
<table><thead align="left"><tr id="row1257209900165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p579444752165631"><a name="p579444752165631"></a><a name="p579444752165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1422774900165631"><a name="p1422774900165631"></a><a name="p1422774900165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1304600856165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p392377878165631"><a name="p392377878165631"></a><a name="p392377878165631"></a><a href="FTW.md#adc64b6d8f0f13269fdb026b67c1a6b11">base</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p745770507165631"><a name="p745770507165631"></a><a name="p745770507165631"></a>int </p>
</td>
</tr>
<tr id="row1632532797165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p100227457165631"><a name="p100227457165631"></a><a name="p100227457165631"></a><a href="FTW.md#af3d03dada9fed0c37d2cb30ff742c130">level</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1083197098165631"><a name="p1083197098165631"></a><a name="p1083197098165631"></a>int </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2063003499165631"></a>

## **Field **<a name="section956008264165631"></a>

## base<a name="adc64b6d8f0f13269fdb026b67c1a6b11"></a>

```
int FTW::base
```

 **Description:**

Offset of the file name in the path name 

## level<a name="af3d03dada9fed0c37d2cb30ff742c130"></a>

```
int FTW::level
```

 **Description:**

Depth of the file name, relative to the root node of the tree 

