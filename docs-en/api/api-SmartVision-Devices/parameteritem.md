# ParameterItem<a name="EN-US_TOPIC_0000001054799635"></a>

-   [Overview](#section1277844240165635)
-   [Summary](#section1337305937165635)
-   [Data Fields](#pub-attribs)
-   [Details](#section1974216673165635)
-   [Field](#section648134752165635)
-   [dValue](#af4be109572705fcd01778c2af5ad1868)
-   [fValue](#ae6d56dc8bd3f5a206fdd085ce65a9e33)
-   [key](#a7fd3dd0c0ddbf9e4cf04d214fae1a857)
-   [pValue](#a7bd2066c1aa644f4cd7a88a4fa0f9776)
-   [s32Value](#a67b4403be08a141554d8974be14c9ec4)
-   [s64Value](#af7566b817d49b505e9a3f25be6feafe3)
-   [size](#ad708dec0457cddcc56f1955f80ea2dfe)
-   [u32Value](#a20cbcbc7418ac8d885418d09a4041e00)
-   [u64Value](#a4f04b2e5166d5e39142a16b6a1ae2392)

## **Overview**<a name="section1277844240165635"></a>

**Related Modules:**

[Format](format.md)

**Description:**

Defines a structure for configuring and obtaining dynamic parameters. 

## **Summary**<a name="section1337305937165635"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1832709310165635"></a>
<table><thead align="left"><tr id="row753653102165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1442686330165635"><a name="p1442686330165635"></a><a name="p1442686330165635"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1296420618165635"><a name="p1296420618165635"></a><a name="p1296420618165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row270620239165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1574433553165635"><a name="p1574433553165635"></a><a name="p1574433553165635"></a><a href="parameteritem.md#a7fd3dd0c0ddbf9e4cf04d214fae1a857">key</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1253846355165635"><a name="p1253846355165635"></a><a name="p1253846355165635"></a>uint32_t </p>
</td>
</tr>
<tr id="row498565567165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p379208252165635"><a name="p379208252165635"></a><a name="p379208252165635"></a><a href="parameteritem.md#ad708dec0457cddcc56f1955f80ea2dfe">size</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1067044430165635"><a name="p1067044430165635"></a><a name="p1067044430165635"></a>int32_t </p>
</td>
</tr>
<tr id="row1086153619165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p958791531165635"><a name="p958791531165635"></a><a name="p958791531165635"></a><strong id="a9cf4ed2fb8664644efcf6f9891001cfe"><a name="a9cf4ed2fb8664644efcf6f9891001cfe"></a><a name="a9cf4ed2fb8664644efcf6f9891001cfe"></a></strong> union {</p>
</td>
</tr>
<tr id="row1975873642165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p343965433165635"><a name="p343965433165635"></a><a name="p343965433165635"></a>   int32_t   <a href="parameteritem.md#a67b4403be08a141554d8974be14c9ec4">s32Value</a></p>
</td>
</tr>
<tr id="row1682151531165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p271468283165635"><a name="p271468283165635"></a><a name="p271468283165635"></a>   uint32_t   <a href="parameteritem.md#a20cbcbc7418ac8d885418d09a4041e00">u32Value</a></p>
</td>
</tr>
<tr id="row206272154165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1971628343165635"><a name="p1971628343165635"></a><a name="p1971628343165635"></a>   int64_t   <a href="parameteritem.md#af7566b817d49b505e9a3f25be6feafe3">s64Value</a></p>
</td>
</tr>
<tr id="row861306452165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p345295701165635"><a name="p345295701165635"></a><a name="p345295701165635"></a>   uint64_t   <a href="parameteritem.md#a4f04b2e5166d5e39142a16b6a1ae2392">u64Value</a></p>
</td>
</tr>
<tr id="row698493183165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p122617472165635"><a name="p122617472165635"></a><a name="p122617472165635"></a>   float   <a href="parameteritem.md#ae6d56dc8bd3f5a206fdd085ce65a9e33">fValue</a></p>
</td>
</tr>
<tr id="row1229403858165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p735667325165635"><a name="p735667325165635"></a><a name="p735667325165635"></a>   double   <a href="parameteritem.md#af4be109572705fcd01778c2af5ad1868">dValue</a></p>
</td>
</tr>
<tr id="row1009327384165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2132524993165635"><a name="p2132524993165635"></a><a name="p2132524993165635"></a>   const void *   <a href="parameteritem.md#a7bd2066c1aa644f4cd7a88a4fa0f9776">pValue</a></p>
</td>
</tr>
<tr id="row510852960165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p866887224165635"><a name="p866887224165635"></a><a name="p866887224165635"></a><a href="parameteritem.md#a9cf4ed2fb8664644efcf6f9891001cfe">value</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p909606355165635"><a name="p909606355165635"></a><a name="p909606355165635"></a>} </p>
<p id="p1017849578165635"><a name="p1017849578165635"></a><a name="p1017849578165635"></a>Defines value types of the parameters. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1974216673165635"></a>

## **Field **<a name="section648134752165635"></a>

## dValue<a name="af4be109572705fcd01778c2af5ad1868"></a>

```
double ParameterItem::dValue
```

 **Description:**

Double-precision floating point number 

## fValue<a name="ae6d56dc8bd3f5a206fdd085ce65a9e33"></a>

```
float ParameterItem::fValue
```

 **Description:**

Single-precision floating point number 

## key<a name="a7fd3dd0c0ddbf9e4cf04d214fae1a857"></a>

```
uint32_t ParameterItem::key
```

 **Description:**

Key type. For details, see  [KeyType](format.md#gaab0feaba617470cb4aa830dc5935238c) 

## pValue<a name="a7bd2066c1aa644f4cd7a88a4fa0f9776"></a>

```
const void* ParameterItem::pValue
```

 **Description:**

Pointer 

## s32Value<a name="a67b4403be08a141554d8974be14c9ec4"></a>

```
int32_t ParameterItem::s32Value
```

 **Description:**

32-bit integer 

## s64Value<a name="af7566b817d49b505e9a3f25be6feafe3"></a>

```
int64_t ParameterItem::s64Value
```

 **Description:**

64-bit integer 

## size<a name="ad708dec0457cddcc56f1955f80ea2dfe"></a>

```
int32_t ParameterItem::size
```

 **Description:**

Data size, which indicates the size of the buffer memory pointed by  **pValue** 

## u32Value<a name="a20cbcbc7418ac8d885418d09a4041e00"></a>

```
uint32_t ParameterItem::u32Value
```

 **Description:**

32-bit unsigned integer 

## u64Value<a name="a4f04b2e5166d5e39142a16b6a1ae2392"></a>

```
uint64_t ParameterItem::u64Value
```

 **Description:**

64-bit unsigned integer 

