# FormatBufferSetting<a name="EN-US_TOPIC_0000001054799597"></a>

-   [Overview](#section1979688351165631)
-   [Summary](#section1007372768165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section486372543165631)
-   [Field](#section1457047107165631)
-   [maxDurationMs](#a6cf1da1ecc6506d134027d3a057cf968)
-   [maxSize](#a9f23c583e5dd21894f4ffce0589ed179)

## **Overview**<a name="section1979688351165631"></a>

**Related Modules:**

[Format](format.md)

**Description:**

Defines the buffer configuration. 

If  **maxSize**  and  **maxDurationMs**  are valid at the same time, the smaller value is used as the upper limit for the buffer.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1007372768165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1950987389165631"></a>
<table><thead align="left"><tr id="row1634697366165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1758240283165631"><a name="p1758240283165631"></a><a name="p1758240283165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p280637549165631"><a name="p280637549165631"></a><a name="p280637549165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row869295436165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1009592081165631"><a name="p1009592081165631"></a><a name="p1009592081165631"></a><a href="formatbuffersetting.md#a9f23c583e5dd21894f4ffce0589ed179">maxSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p703843102165631"><a name="p703843102165631"></a><a name="p703843102165631"></a>int64_t </p>
</td>
</tr>
<tr id="row1322930470165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p518246815165631"><a name="p518246815165631"></a><a name="p518246815165631"></a><a href="formatbuffersetting.md#a6cf1da1ecc6506d134027d3a057cf968">maxDurationMs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2046023336165631"><a name="p2046023336165631"></a><a name="p2046023336165631"></a>int64_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section486372543165631"></a>

## **Field **<a name="section1457047107165631"></a>

## maxDurationMs<a name="a6cf1da1ecc6506d134027d3a057cf968"></a>

```
int64_t FormatBufferSetting::maxDurationMs
```

 **Description:**

Maximum duration of a media file 

## maxSize<a name="a9f23c583e5dd21894f4ffce0589ed179"></a>

```
int64_t FormatBufferSetting::maxSize
```

 **Description:**

Maximum buffer size 

