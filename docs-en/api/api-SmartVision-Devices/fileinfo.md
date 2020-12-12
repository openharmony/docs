# FileInfo<a name="EN-US_TOPIC_0000001054479561"></a>

-   [Overview](#section1402189407165631)
-   [Summary](#section964552924165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section86417929165631)
-   [Field](#section1265510319165631)
-   [bitrate](#ac6afb3ba1891e7fd02c3b2c942d2525f)
-   [formatName](#a38797d4349538f098d6f14b94446bee7)
-   [programInfo](#aeb2b662b1dd525c9b56f2ddca1013058)
-   [programNum](#a1373e3d2662f2112eb58078c7ef7e2a2)

## **Overview**<a name="section1402189407165631"></a>

**Related Modules:**

[Format](format.md)

**Description:**

Defines movie file information. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section964552924165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table2045705371165631"></a>
<table><thead align="left"><tr id="row1032798109165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1725423474165631"><a name="p1725423474165631"></a><a name="p1725423474165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1738565833165631"><a name="p1738565833165631"></a><a name="p1738565833165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1177943554165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1027891068165631"><a name="p1027891068165631"></a><a name="p1027891068165631"></a><a href="fileinfo.md#a38797d4349538f098d6f14b94446bee7">formatName</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1060790044165631"><a name="p1060790044165631"></a><a name="p1060790044165631"></a>char * </p>
</td>
</tr>
<tr id="row924006075165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p680143417165631"><a name="p680143417165631"></a><a name="p680143417165631"></a><a href="fileinfo.md#ac6afb3ba1891e7fd02c3b2c942d2525f">bitrate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p65847340165631"><a name="p65847340165631"></a><a name="p65847340165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row1878111396165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p118457790165631"><a name="p118457790165631"></a><a name="p118457790165631"></a><a href="fileinfo.md#a1373e3d2662f2112eb58078c7ef7e2a2">programNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1059784720165631"><a name="p1059784720165631"></a><a name="p1059784720165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row1806868783165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1520463838165631"><a name="p1520463838165631"></a><a name="p1520463838165631"></a><a href="fileinfo.md#aeb2b662b1dd525c9b56f2ddca1013058">programInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p862463695165631"><a name="p862463695165631"></a><a name="p862463695165631"></a><a href="programinfo.md">ProgramInfo</a> * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section86417929165631"></a>

## **Field **<a name="section1265510319165631"></a>

## bitrate<a name="ac6afb3ba1891e7fd02c3b2c942d2525f"></a>

```
uint32_t FileInfo::bitrate
```

 **Description:**

Bit rate of the movie file 

## formatName<a name="a38797d4349538f098d6f14b94446bee7"></a>

```
char* FileInfo::formatName
```

 **Description:**

Pointer to the name of the movie file container format 

## programInfo<a name="aeb2b662b1dd525c9b56f2ddca1013058"></a>

```
[ProgramInfo](programinfo.md)* FileInfo::programInfo
```

 **Description:**

Pointer to the array of information about the movie file program 

## programNum<a name="a1373e3d2662f2112eb58078c7ef7e2a2"></a>

```
uint32_t FileInfo::programNum
```

 **Description:**

Number of programs 

