# display\_gfx.h<a name="EN-US_TOPIC_0000001054598125"></a>

-   [Overview](#section1079528593165626)
-   [Summary](#section118988735165626)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section1079528593165626"></a>

**Related Modules:**

[Display](display.md)

**Description:**

Declares the driver functions for implementing hardware acceleration. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section118988735165626"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table697253543165626"></a>
<table><thead align="left"><tr id="row557987486165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p759330443165626"><a name="p759330443165626"></a><a name="p759330443165626"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p841276264165626"><a name="p841276264165626"></a><a name="p841276264165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row231107550165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1963032692165626"><a name="p1963032692165626"></a><a name="p1963032692165626"></a><a href="gfxfuncs.md">GfxFuncs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1468708053165626"><a name="p1468708053165626"></a><a name="p1468708053165626"></a>Defines pointers to the hardware acceleration driver functions. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table441854528165626"></a>
<table><thead align="left"><tr id="row1888104298165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p522200478165626"><a name="p522200478165626"></a><a name="p522200478165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1593185259165626"><a name="p1593185259165626"></a><a name="p1593185259165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1704404623165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1830406064165626"><a name="p1830406064165626"></a><a name="p1830406064165626"></a><a href="display.md#ga251580eb0614b601ef2c901c722a59d3">GfxInitialize</a> (<a href="gfxfuncs.md">GfxFuncs</a> **funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p865872831165626"><a name="p865872831165626"></a><a name="p865872831165626"></a>int32_t </p>
<p id="p810662569165626"><a name="p810662569165626"></a><a name="p810662569165626"></a>Initializes the hardware acceleration module to obtain the pointer to functions for hardware acceleration operations. </p>
</td>
</tr>
<tr id="row1948331726165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p832878662165626"><a name="p832878662165626"></a><a name="p832878662165626"></a><a href="display.md#ga32595139adb26cfaacf709661b29b347">GfxUninitialize</a> (<a href="gfxfuncs.md">GfxFuncs</a> *funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p602548685165626"><a name="p602548685165626"></a><a name="p602548685165626"></a>int32_t </p>
<p id="p561139752165626"><a name="p561139752165626"></a><a name="p561139752165626"></a>Deinitializes the hardware acceleration module to release the memory allocated to the pointer to functions for hardware acceleration operations. </p>
</td>
</tr>
</tbody>
</table>

