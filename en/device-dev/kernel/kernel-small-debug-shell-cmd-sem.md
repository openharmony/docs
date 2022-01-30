# sem<a name="EN-US_TOPIC_0000001134006254"></a>

## Command Function<a name="section366714216619"></a>

This command is used to query information about kernel semaphores.

## Syntax<a name="section8833164614615"></a>

sem \[_ID__ / fulldata_\]

## Parameters<a name="section12809111019453"></a>

**Table  1**  Parameter description

<a name="table438mcpsimp"></a>
<table><thead align="left"><tr id="row444mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p446mcpsimp"><a name="p446mcpsimp"></a><a name="p446mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p448mcpsimp"><a name="p448mcpsimp"></a><a name="p448mcpsimp"></a>Parameters</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p450mcpsimp"><a name="p450mcpsimp"></a><a name="p450mcpsimp"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row451mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p453mcpsimp"><a name="p453mcpsimp"></a><a name="p453mcpsimp"></a>ID</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p455mcpsimp"><a name="p455mcpsimp"></a><a name="p455mcpsimp"></a>Specifies the semaphore ID.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p457mcpsimp"><a name="p457mcpsimp"></a><a name="p457mcpsimp"></a>[0, 0xFFFFFFFF]</p>
</td>
</tr>
<tr id="row458mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p460mcpsimp"><a name="p460mcpsimp"></a><a name="p460mcpsimp"></a>fulldata</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p462mcpsimp"><a name="p462mcpsimp"></a><a name="p462mcpsimp"></a>Queries information about all the semaphores in use. The information to be printed includes <strong id="b189454249533849"><a name="b189454249533849"></a><a name="b189454249533849"></a>SemID</strong>, <strong id="b162724654333849"><a name="b162724654333849"></a><a name="b162724654333849"></a>Count</strong>, <strong id="b111325307233849"><a name="b111325307233849"></a><a name="b111325307233849"></a>OriginalCount</strong>, <strong id="b182850346833849"><a name="b182850346833849"></a><a name="b182850346833849"></a>Creater(TaskEntry)</strong>, and <strong id="b213750533633849"><a name="b213750533633849"></a><a name="b213750533633849"></a>LastAccessTime</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="entry464mcpsimpp0"><a name="entry464mcpsimpp0"></a><a name="entry464mcpsimpp0"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section15935131220717"></a>

-   If the parameters are not specified, this command displays the number of used semaphores and the total number of semaphores.
-   If the  **ID**  parameter is specified, semaphores of the specified ID are displayed.
-   The  **fulldata**  parameter depends on  **LOSCFG\_DEBUG\_SEMAPHORE**. Before using this parameter, select  **Enable Semaphore Debugging**  on  **menuconfig**.

    Debug  ---\> Enable a Debug Version ---\> Enable Debug LiteOS Kernel Resource ---\> Enable Semaphore Debugging


## Example<a name="section79281818476"></a>

Run  **sem fulldata**.

## Output<a name="section1975118519456"></a>

**Figure  1**  Querying information about all semaphores in use<a name="fig18750181620222"></a>  
![](figure/querying-information-about-all-semaphores-in-use.png "querying-information-about-all-semaphores-in-use")

**Table  2**  Output

<a name="table487mcpsimp"></a>
<table><thead align="left"><tr id="row492mcpsimp"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p494mcpsimp"><a name="p494mcpsimp"></a><a name="p494mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p496mcpsimp"><a name="p496mcpsimp"></a><a name="p496mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row497mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p499mcpsimp"><a name="p499mcpsimp"></a><a name="p499mcpsimp"></a>SemID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p501mcpsimp"><a name="p501mcpsimp"></a><a name="p501mcpsimp"></a>Semaphore ID</p>
</td>
</tr>
<tr id="row502mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p504mcpsimp"><a name="p504mcpsimp"></a><a name="p504mcpsimp"></a>Count</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p506mcpsimp"><a name="p506mcpsimp"></a><a name="p506mcpsimp"></a>Number of used semaphores</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The  **ID**  value can be in decimal or hexadecimal format.
>When the  **ID**  value is within the range of \[0, 1023\], semaphore information of the specified ID is displayed. If the semaphore ID is not used, a message is displayed to inform you of this case. For other values, a message is displayed indicating that the parameter is incorrect.

