# SdioFuncInfo<a name="ZH-CN_TOPIC_0000001055518126"></a>

-   [Overview](#section2002007150165636)
-   [Summary](#section1215254666165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section2041610636165636)
-   [Field](#section1415428545165636)
-   [data](#a3867493e7beca9cafb6833523f29ccda)
-   [enTimeout](#a85c9b17ab885cb72eab7ded6e49d8476)
-   [funcNum](#a7d99a390cc82cdccda84122580f20e2b)
-   [irqCap](#aff0bdebbfd7969076ab2f9ccd2b1867c)
-   [maxBlockNum](#a04d38dfd2a8d39a35eafcfc29b673e26)
-   [maxBlockSize](#af5f3459fa5c7b774f59b0dcd70b9a0b6)
-   [maxRequestSize](#a2b5bfbd05ef54dc65027068de0175d9e)

## **Overview**<a name="section2002007150165636"></a>

**Related Modules:**

[SDIO](SDIO.md)

**Description:**

Defines the SDIO capabilities. 

You can obtain and set the SDIO capabilities by calling  [SdioGetCommonInfo](SDIO.md#ga1289cc512ba56e3e904204c15d8ae23d)  and  [SdioSetCommonInfo](SDIO.md#ga6a8eb2f6413c4685f92236dd1c8083dc)  with  [SdioCommonInfo](SdioCommonInfo.md)  and  [SdioCommonInfoType](SDIO.md#ga4037437ac001a9848dd242e8aa632678)  passed. 

## **Summary**<a name="section1215254666165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table513915153165636"></a>
<table><thead align="left"><tr id="row2060671924165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1889148822165636"><a name="p1889148822165636"></a><a name="p1889148822165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p738555051165636"><a name="p738555051165636"></a><a name="p738555051165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row459396493165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p232059588165636"><a name="p232059588165636"></a><a name="p232059588165636"></a><a href="SdioFuncInfo.md#a04d38dfd2a8d39a35eafcfc29b673e26">maxBlockNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1044176101165636"><a name="p1044176101165636"></a><a name="p1044176101165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1746730433165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p109995389165636"><a name="p109995389165636"></a><a name="p109995389165636"></a><a href="SdioFuncInfo.md#af5f3459fa5c7b774f59b0dcd70b9a0b6">maxBlockSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1764810712165636"><a name="p1764810712165636"></a><a name="p1764810712165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row246692513165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2051766781165636"><a name="p2051766781165636"></a><a name="p2051766781165636"></a><a href="SdioFuncInfo.md#a2b5bfbd05ef54dc65027068de0175d9e">maxRequestSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1236538532165636"><a name="p1236538532165636"></a><a name="p1236538532165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row347909051165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p491993407165636"><a name="p491993407165636"></a><a name="p491993407165636"></a><a href="SdioFuncInfo.md#a85c9b17ab885cb72eab7ded6e49d8476">enTimeout</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1138721127165636"><a name="p1138721127165636"></a><a name="p1138721127165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row917932060165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1078355034165636"><a name="p1078355034165636"></a><a name="p1078355034165636"></a><a href="SdioFuncInfo.md#a7d99a390cc82cdccda84122580f20e2b">funcNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p68710802165636"><a name="p68710802165636"></a><a name="p68710802165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row584796187165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1869711597165636"><a name="p1869711597165636"></a><a name="p1869711597165636"></a><a href="SdioFuncInfo.md#aff0bdebbfd7969076ab2f9ccd2b1867c">irqCap</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p656699317165636"><a name="p656699317165636"></a><a name="p656699317165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1199063877165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p177520054165636"><a name="p177520054165636"></a><a name="p177520054165636"></a><a href="SdioFuncInfo.md#a3867493e7beca9cafb6833523f29ccda">data</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1141529175165636"><a name="p1141529175165636"></a><a name="p1141529175165636"></a>void * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2041610636165636"></a>

## **Field **<a name="section1415428545165636"></a>

## data<a name="a3867493e7beca9cafb6833523f29ccda"></a>

```
void* SdioFuncInfo::data
```

 **Description:**

Private data 

## enTimeout<a name="a85c9b17ab885cb72eab7ded6e49d8476"></a>

```
uint32_t SdioFuncInfo::enTimeout
```

 **Description:**

Maximum timeout duration, in milliseconds. The value cannot exceed  **1**  second. 

## funcNum<a name="a7d99a390cc82cdccda84122580f20e2b"></a>

```
uint32_t SdioFuncInfo::funcNum
```

 **Description:**

Functionality number, ranging from  **1**  to  **7**. 

## irqCap<a name="aff0bdebbfd7969076ab2f9ccd2b1867c"></a>

```
uint32_t SdioFuncInfo::irqCap
```

 **Description:**

IRQ capabilities 

## maxBlockNum<a name="a04d38dfd2a8d39a35eafcfc29b673e26"></a>

```
uint32_t SdioFuncInfo::maxBlockNum
```

 **Description:**

Maximum number of blocks in a request 

## maxBlockSize<a name="af5f3459fa5c7b774f59b0dcd70b9a0b6"></a>

```
uint32_t SdioFuncInfo::maxBlockSize
```

 **Description:**

Maximum number of bytes in a block. The value ranges from  **1**  to  **2048**. 

## maxRequestSize<a name="a2b5bfbd05ef54dc65027068de0175d9e"></a>

```
uint32_t SdioFuncInfo::maxRequestSize
```

 **Description:**

Maximum number of bytes in a request. The value ranges from  **1**  to  **2048**. 

