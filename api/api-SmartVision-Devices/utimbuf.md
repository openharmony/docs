# utimbuf<a name="ZH-CN_TOPIC_0000001055078189"></a>

-   [Overview](#section632455972165637)
-   [Summary](#section475755132165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section1410956332165637)
-   [Field](#section1607560064165637)
-   [actime](#aa39cf0bad7eff4df6239528506a557df)
-   [modtime](#a7588ffe699a9eda52e94aa593bf7d6d8)

## **Overview**<a name="section632455972165637"></a>

**Related Modules:**

[FS](FS.md)

**Description:**

Defines the file access time and modification time. 

## **Summary**<a name="section475755132165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1107249126165637"></a>
<table><thead align="left"><tr id="row2080209742165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p104038599165637"><a name="p104038599165637"></a><a name="p104038599165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p343412797165637"><a name="p343412797165637"></a><a name="p343412797165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row657695184165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1099293866165637"><a name="p1099293866165637"></a><a name="p1099293866165637"></a><a href="utimbuf.md#aa39cf0bad7eff4df6239528506a557df">actime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1082962848165637"><a name="p1082962848165637"></a><a name="p1082962848165637"></a><a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> </p>
</td>
</tr>
<tr id="row1545752849165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1920442867165637"><a name="p1920442867165637"></a><a name="p1920442867165637"></a><a href="utimbuf.md#a7588ffe699a9eda52e94aa593bf7d6d8">modtime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1283302987165637"><a name="p1283302987165637"></a><a name="p1283302987165637"></a><a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1410956332165637"></a>

## **Field **<a name="section1607560064165637"></a>

## actime<a name="aa39cf0bad7eff4df6239528506a557df"></a>

```
[time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) utimbuf::actime
```

 **Description:**

File access time: the last time the file was accessed 

## modtime<a name="a7588ffe699a9eda52e94aa593bf7d6d8"></a>

```
[time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) utimbuf::modtime
```

 **Description:**

File modification time: the last time the file was modified 

