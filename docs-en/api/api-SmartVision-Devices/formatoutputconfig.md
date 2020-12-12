# FormatOutputConfig<a name="EN-US_TOPIC_0000001055198128"></a>

-   [Overview](#section1927231751165631)
-   [Summary](#section1120045599165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section754144248165631)
-   [Field](#section280343797165631)
-   [fd](#a06757484a244827b91183a40f636b2de)
-   [format](#a594a547d286a447681e983582c671a6a)
-   [type](#afdd8b72dc265610db88ed9893f673bb4)
-   [url](#a9ce729405e9489d021713689ed1ca17b)

## **Overview**<a name="section1927231751165631"></a>

**Related Modules:**

[Format](format.md)

**Description:**

Defines the muxer output configuration. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1120045599165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table602718143165631"></a>
<table><thead align="left"><tr id="row851408312165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2098985380165631"><a name="p2098985380165631"></a><a name="p2098985380165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p662559948165631"><a name="p662559948165631"></a><a name="p662559948165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row289274070165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p320295669165631"><a name="p320295669165631"></a><a name="p320295669165631"></a><a href="formatoutputconfig.md#afdd8b72dc265610db88ed9893f673bb4">type</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1263505984165631"><a name="p1263505984165631"></a><a name="p1263505984165631"></a><a href="format.md#ga4e0517338e6c4a31a2addafc06d4f3a3">OutputType</a> </p>
</td>
</tr>
<tr id="row2051427146165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1642869348165631"><a name="p1642869348165631"></a><a name="p1642869348165631"></a><a href="formatoutputconfig.md#a594a547d286a447681e983582c671a6a">format</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p562507639165631"><a name="p562507639165631"></a><a name="p562507639165631"></a><a href="format.md#gaeb712c6c6c0a8af0dfd79f451ecb9277">OutputFormat</a> </p>
</td>
</tr>
<tr id="row847482430165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p10249826165631"><a name="p10249826165631"></a><a name="p10249826165631"></a><a href="formatoutputconfig.md#a06757484a244827b91183a40f636b2de">fd</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1429592348165631"><a name="p1429592348165631"></a><a name="p1429592348165631"></a>int32_t </p>
</td>
</tr>
<tr id="row525605959165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p451098205165631"><a name="p451098205165631"></a><a name="p451098205165631"></a><a href="formatoutputconfig.md#a9ce729405e9489d021713689ed1ca17b">url</a> [<a href="format.md#ga1ac54dd3b9b49c1800b5f502a87650be">URL_LEN</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p873189272165631"><a name="p873189272165631"></a><a name="p873189272165631"></a>char </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section754144248165631"></a>

## **Field **<a name="section280343797165631"></a>

## fd<a name="a06757484a244827b91183a40f636b2de"></a>

```
int32_t FormatOutputConfig::fd
```

 **Description:**

File descriptor 

## format<a name="a594a547d286a447681e983582c671a6a"></a>

```
[OutputFormat](format.md#gaeb712c6c6c0a8af0dfd79f451ecb9277) FormatOutputConfig::format
```

 **Description:**

File format 

## type<a name="afdd8b72dc265610db88ed9893f673bb4"></a>

```
[OutputType](format.md#ga4e0517338e6c4a31a2addafc06d4f3a3) FormatOutputConfig::type
```

 **Description:**

Output type. For details, see  [OutputType](format.md#ga4e0517338e6c4a31a2addafc06d4f3a3). 

## url<a name="a9ce729405e9489d021713689ed1ca17b"></a>

```
char FormatOutputConfig::url[[URL_LEN](format.md#ga1ac54dd3b9b49c1800b5f502a87650be)]
```

 **Description:**

File path. For details, see  [URL\_LEN](format.md#ga1ac54dd3b9b49c1800b5f502a87650be). 

