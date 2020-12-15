# FormatSource<a name="ZH-CN_TOPIC_0000001054879530"></a>

-   [Overview](#section1977746972165631)
-   [Summary](#section1154583350165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1037039597165631)
-   [Field](#section1175359571165631)
-   [fd](#adc25d5e97f531f36d7f129136abb483d)
-   [stream](#a33f6a121891b692ef246011e0415f3fe)
-   [type](#abdb0407f672c5e9af53eae7726c2e7b2)
-   [url](#adc0405c090069d6bbf2017995710a0f8)

## **Overview**<a name="section1977746972165631"></a>

**Related Modules:**

[Format](Format.md)

**Description:**

Defines the demuxer data source. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1154583350165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table193281277165631"></a>
<table><thead align="left"><tr id="row449632266165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p551734375165631"><a name="p551734375165631"></a><a name="p551734375165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1372431400165631"><a name="p1372431400165631"></a><a name="p1372431400165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row521214892165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p316078515165631"><a name="p316078515165631"></a><a name="p316078515165631"></a><a href="FormatSource.md#abdb0407f672c5e9af53eae7726c2e7b2">type</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1235966448165631"><a name="p1235966448165631"></a><a name="p1235966448165631"></a><a href="Format.md#ga3ae727773c367ac1041d72ac770a0ab1">SourceType</a> </p>
</td>
</tr>
<tr id="row1434855637165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p202869730165631"><a name="p202869730165631"></a><a name="p202869730165631"></a><strong id="a906e88d66b9e3cafea9624d05a7517d6"><a name="a906e88d66b9e3cafea9624d05a7517d6"></a><a name="a906e88d66b9e3cafea9624d05a7517d6"></a></strong> union {</p>
</td>
</tr>
<tr id="row110779224165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1376628040165631"><a name="p1376628040165631"></a><a name="p1376628040165631"></a>   int   <a href="FormatSource.md#adc25d5e97f531f36d7f129136abb483d">fd</a></p>
</td>
</tr>
<tr id="row1973332737165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p752246261165631"><a name="p752246261165631"></a><a name="p752246261165631"></a>   char   <a href="FormatSource.md#adc0405c090069d6bbf2017995710a0f8">url</a> [<a href="Format.md#ga1ac54dd3b9b49c1800b5f502a87650be">URL_LEN</a>]</p>
</td>
</tr>
<tr id="row88304787165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1066567480165631"><a name="p1066567480165631"></a><a name="p1066567480165631"></a>   <a href="BufferStream.md">BufferStream</a> *   <a href="FormatSource.md#a33f6a121891b692ef246011e0415f3fe">stream</a></p>
</td>
</tr>
<tr id="row1534194864165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p137038995165631"><a name="p137038995165631"></a><a name="p137038995165631"></a>}; </p>
<p id="p1816399533165631"><a name="p1816399533165631"></a><a name="p1816399533165631"></a>Defines information about different types of data sources. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1037039597165631"></a>

## **Field **<a name="section1175359571165631"></a>

## fd<a name="adc25d5e97f531f36d7f129136abb483d"></a>

```
int FormatSource::fd
```

 **Description:**

Local file descriptor 

## stream<a name="a33f6a121891b692ef246011e0415f3fe"></a>

```
[BufferStream](BufferStream.md)* FormatSource::stream
```

 **Description:**

Pointer to the function for reading buffer stream data 

## type<a name="abdb0407f672c5e9af53eae7726c2e7b2"></a>

```
[SourceType](Format.md#ga3ae727773c367ac1041d72ac770a0ab1) FormatSource::type
```

 **Description:**

Data source type. For details, see  [SourceType](Format.md#ga3ae727773c367ac1041d72ac770a0ab1). 

## url<a name="adc0405c090069d6bbf2017995710a0f8"></a>

```
char FormatSource::url[[URL_LEN](Format.md#ga1ac54dd3b9b49c1800b5f502a87650be)]
```

 **Description:**

Network URI or local file path. The maximum length is specified by  **URL\_LEN**. 

