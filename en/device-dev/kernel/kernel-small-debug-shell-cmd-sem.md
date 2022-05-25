# sem

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
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p14422125918562"><a name="p14422125918562"></a><a name="p14422125918562"></a>[0, 1023] or [0x0, 0x3FF]</p>
</td>
</tr>
<tr id="row458mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p460mcpsimp"><a name="p460mcpsimp"></a><a name="p460mcpsimp"></a>fulldata</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p462mcpsimp"><a name="p462mcpsimp"></a><a name="p462mcpsimp"></a>Queries information about all the semaphores in use. The information includes <strong id="b189454249533849"><a name="b189454249533849"></a><a name="b189454249533849"></a>SemID</strong>, <strong id="b162724654333849"><a name="b162724654333849"></a><a name="b162724654333849"></a>Count</strong>, <strong id="b111325307233849"><a name="b111325307233849"></a><a name="b111325307233849"></a>OriginalCount</strong>, <strong id="b182850346833849"><a name="b182850346833849"></a><a name="b182850346833849"></a>Creater(TaskEntry)</strong>, and <strong id="b213750533633849"><a name="b213750533633849"></a><a name="b213750533633849"></a>LastAccessTime</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="entry464mcpsimpp0"><a name="entry464mcpsimpp0"></a><a name="entry464mcpsimpp0"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section15935131220717"></a>

-   If no parameter is specified, this command displays the semaphore IDs and the number of times that each semaphore is used.
-   If  **ID**  is specified, the use of the specified semaphore is displayed.
-   The  **fulldata**  parameter depends on  **LOSCFG\_DEBUG\_SEMAPHORE**. Before using this parameter, select  **Enable Semaphore Debugging**  on  **menuconfig**.

    Debug  ---\> Enable a Debug Version ---\> Enable Debug LiteOS Kernel Resource ---\> Enable Semaphore Debugging


## Example<a name="section79281818476"></a>

-   Run  **sem**.
-   Configure  **LOSCFG\_DEBUG\_SEMAPHORE**  and run  **sem fulldata**.

## Output<a name="section1975118519456"></a>

Example 1: brief semaphore information

```
OHOS # sem
   SemID       Count
   ----------  -----
   0x00000000  1
   SemID       Count
   ----------  -----
   0x00000001  0
   SemID       Count
   ----------  -----
   0x00000002  0
   SemID       Count
   ----------  -----
   0x00000003  1
   SemID       Count
   ----------  -----
   0x00000004  0
   SemID       Count
   ----------  -----
   0x00000005  1
   SemID       Count
   ----------  -----
   0x00000006  0
```

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
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p506mcpsimp"><a name="p506mcpsimp"></a><a name="p506mcpsimp"></a>Number of times that the semaphore is used</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The  **ID**  value can be in decimal or hexadecimal format.
>When  **ID**  is a value within \[0, 1023\], semaphore information of the specified ID is displayed. If the specified semaphore is not used, a message is displayed to inform you of this case. For other values, a message is displayed indicating that the parameter is incorrect.

Example 2: detailed semaphore information

```
OHOS # sem fulldata
Used Semaphore List:
   SemID    Count    OriginalCount   Creater(TaskEntry)    LastAccessTime
   ------   ------   -------------   ------------------    --------------
   0xb      0x0      0x0             0x404978fc            0xa1
   0xc      0x0      0x0             0x404978fc            0xa1
   0xd      0x0      0x0             0x404978fc            0x12c
   0x10     0x0      0x0             0x404978fc            0x195
   0xf      0x0      0x0             0x404978fc            0x195
   0x11     0x0      0x0             0x4041a998            0x1d5
   0x15     0x0      0x0             0x404978fc            0x273
   0x14     0x0      0x0             0x404978fc            0x273
   0x18     0x0      0x0             0x404978fc            0x352
   0x17     0x0      0x0             0x404978fc            0x352
   0x16     0x0      0x0             0x404978fc            0x352
   0x1d     0x1      0x1             0x404978fc            0x385
   0x1e     0x1      0x1             0x404978fc            0x388
   0x1f     0x1      0x1             0x404978fc            0x38d
   0x20     0x1      0x1             0x404978fc            0x38f
   0x21     0x1      0x1             0x404978fc            0x392
   0x3d     0x1      0x1             0x404978fc            0x395
   0x3b     0x1      0x1             0x404978fc            0x395
   0x3c     0x1      0x1             0x404978fc            0x395
   0x39     0x1      0x1             0x404978fc            0x395
   0x3a     0x1      0x1             0x404978fc            0x395
   0x33     0x1      0x1             0x404978fc            0x395
   0x35     0x1      0x1             0x404978fc            0x395
   0x34     0x1      0x1             0x404978fc            0x395
   0x38     0x1      0x1             0x404978fc            0x395
```

**Table  3**  Output description

<a name="table57783201041"></a>
<table><thead align="left"><tr id="row12778320943"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p153641444643"><a name="p153641444643"></a><a name="p153641444643"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p236413447414"><a name="p236413447414"></a><a name="p236413447414"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14834640646"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7829840647"><a name="p7829840647"></a><a name="p7829840647"></a>SemID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p118291440244"><a name="p118291440244"></a><a name="p118291440244"></a>Semaphore ID</p>
</td>
</tr>
<tr id="row78346401141"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p08292401349"><a name="p08292401349"></a><a name="p08292401349"></a>Count</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1829104012416"><a name="p1829104012416"></a><a name="p1829104012416"></a>Number of times that the semaphore is used</p>
</td>
</tr>
<tr id="row1883414404411"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p88291640847"><a name="p88291640847"></a><a name="p88291640847"></a>OriginalCount</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p282916401148"><a name="p282916401148"></a><a name="p282916401148"></a>Original count of the semaphore</p>
</td>
</tr>
<tr id="row148347401646"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1782914401646"><a name="p1782914401646"></a><a name="p1782914401646"></a>Creater</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p168298407419"><a name="p168298407419"></a><a name="p168298407419"></a>Address of the entry function of the thread used to create the semaphore</p>
</td>
</tr>
<tr id="row783415401340"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p18829640549"><a name="p18829640549"></a><a name="p18829640549"></a>LastAccessTime</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p198292406412"><a name="p198292406412"></a><a name="p198292406412"></a>Last time when the semaphore was accessed</p>
</td>
</tr>
</tbody>
</table>

