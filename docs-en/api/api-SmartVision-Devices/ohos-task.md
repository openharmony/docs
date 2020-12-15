# OHOS::Task<a name="EN-US_TOPIC_0000001054718145"></a>

-   [Overview](#section1993709289165633)
-   [Summary](#section1680911653165633)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1993709289165633"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Represents the  **[Task](ohos-task.md)**  class of the graphics module. This class provides functions for setting the running period and time of a task. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1680911653165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1770492122165633"></a>
<table><thead align="left"><tr id="row2117218259165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1832369367165633"><a name="p1832369367165633"></a><a name="p1832369367165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p833052241165633"><a name="p833052241165633"></a><a name="p833052241165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row291984135165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1336354656165633"><a name="p1336354656165633"></a><a name="p1336354656165633"></a><a href="graphic.md#gad94964a9139150b967ad640ea2076312">Task</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p388383894165633"><a name="p388383894165633"></a><a name="p388383894165633"></a>  </p>
<p id="p126752186165633"><a name="p126752186165633"></a><a name="p126752186165633"></a>A constructor used to create a <strong id="b456551982165633"><a name="b456551982165633"></a><a name="b456551982165633"></a><a href="ohos-task.md">Task</a></strong> instance. </p>
</td>
</tr>
<tr id="row1591936764165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p241650609165633"><a name="p241650609165633"></a><a name="p241650609165633"></a><a href="graphic.md#gaa7c50eb360b6a4478b5332b8bf565940">Task</a> (uint32_t period)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p889074376165633"><a name="p889074376165633"></a><a name="p889074376165633"></a> </p>
<p id="p652211749165633"><a name="p652211749165633"></a><a name="p652211749165633"></a>A constructor used to create a <strong id="b1087884501165633"><a name="b1087884501165633"></a><a name="b1087884501165633"></a><a href="ohos-task.md">Task</a></strong> instance with the specified running period. </p>
</td>
</tr>
<tr id="row941289972165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1543667871165633"><a name="p1543667871165633"></a><a name="p1543667871165633"></a><a href="graphic.md#ga293d4e1533ea98cdebbbffe1afed38ef">~Task</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p372076876165633"><a name="p372076876165633"></a><a name="p372076876165633"></a> virtual </p>
<p id="p510393349165633"><a name="p510393349165633"></a><a name="p510393349165633"></a>A destructor used to delete the <strong id="b1037338469165633"><a name="b1037338469165633"></a><a name="b1037338469165633"></a><a href="ohos-task.md">Task</a></strong> instance. </p>
</td>
</tr>
<tr id="row496684390165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p239704796165633"><a name="p239704796165633"></a><a name="p239704796165633"></a><a href="graphic.md#gac6e9fe7bde72bf506558a6f0d0287a92">SetPeriod</a> (uint32_t period)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1807614888165633"><a name="p1807614888165633"></a><a name="p1807614888165633"></a>void </p>
<p id="p435617228165633"><a name="p435617228165633"></a><a name="p435617228165633"></a>Sets the running period for this task. </p>
</td>
</tr>
<tr id="row1277743524165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1762782459165633"><a name="p1762782459165633"></a><a name="p1762782459165633"></a><a href="graphic.md#gabdbfe69d5f5da3cc5bbb1749d281af62">SetLastRun</a> (uint32_t lastRun)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1199533189165633"><a name="p1199533189165633"></a><a name="p1199533189165633"></a>void </p>
<p id="p839388951165633"><a name="p839388951165633"></a><a name="p839388951165633"></a>Sets the end time for this task. </p>
</td>
</tr>
<tr id="row120211706165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p519034774165633"><a name="p519034774165633"></a><a name="p519034774165633"></a><a href="graphic.md#gabd53b86c63b41172af155b8a7f86b84c">GetPeriod</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p763651023165633"><a name="p763651023165633"></a><a name="p763651023165633"></a>uint32_t </p>
<p id="p185950816165633"><a name="p185950816165633"></a><a name="p185950816165633"></a>Obtains the running period of this task. </p>
</td>
</tr>
<tr id="row429207274165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1398300726165633"><a name="p1398300726165633"></a><a name="p1398300726165633"></a><a href="graphic.md#ga2d4c9fbb026686623ff4d6e0b19d4960">GetLastRun</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1305604304165633"><a name="p1305604304165633"></a><a name="p1305604304165633"></a>uint32_t </p>
<p id="p823100229165633"><a name="p823100229165633"></a><a name="p823100229165633"></a>Obtains the end time of this task. </p>
</td>
</tr>
<tr id="row1350007919165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1171564146165633"><a name="p1171564146165633"></a><a name="p1171564146165633"></a><a href="graphic.md#ga96ed6680b2b9ad667e51d60554013020">TaskExecute</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p902513597165633"><a name="p902513597165633"></a><a name="p902513597165633"></a> void </p>
<p id="p409931340165633"><a name="p409931340165633"></a><a name="p409931340165633"></a>Executes this task. </p>
</td>
</tr>
<tr id="row11028586165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1962850705165633"><a name="p1962850705165633"></a><a name="p1962850705165633"></a><a href="graphic.md#gad1ddf68898304dad1f912f750ace8281">Callback</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p612316600165633"><a name="p612316600165633"></a><a name="p612316600165633"></a> virtual void </p>
<p id="p1857999102165633"><a name="p1857999102165633"></a><a name="p1857999102165633"></a>Called when this task is executed. </p>
</td>
</tr>
<tr id="row315666677165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1248791258165633"><a name="p1248791258165633"></a><a name="p1248791258165633"></a><a href="graphic.md#gab9968727a3d5e8b6270f5efd0eb1cff6">Init</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p249560768165633"><a name="p249560768165633"></a><a name="p249560768165633"></a> virtual void </p>
<p id="p531349408165633"><a name="p531349408165633"></a><a name="p531349408165633"></a>Initializes this task. </p>
</td>
</tr>
<tr id="row1998952047165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p565791649165633"><a name="p565791649165633"></a><a name="p565791649165633"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p503801089165633"><a name="p503801089165633"></a><a name="p503801089165633"></a>void * </p>
<p id="p965405686165633"><a name="p965405686165633"></a><a name="p965405686165633"></a>Overrides the <strong id="b1895007792165633"><a name="b1895007792165633"></a><a name="b1895007792165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row2101887839165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p771503204165633"><a name="p771503204165633"></a><a name="p771503204165633"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1077792069165633"><a name="p1077792069165633"></a><a name="p1077792069165633"></a>void </p>
<p id="p1290439089165633"><a name="p1290439089165633"></a><a name="p1290439089165633"></a>Overrides the <strong id="b1567029896165633"><a name="b1567029896165633"></a><a name="b1567029896165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

