# free<a name="EN-US_TOPIC_0000001133846472"></a>

## Command Function<a name="section175151514841"></a>

This command is used to display the system memory usage and the sizes of the  **text**,  **data**,  **rodata**, and  **bss**  segments.

## Syntax<a name="section8488721749"></a>

free \[_-k | -m_\]

## Parameters<a name="section27272181949"></a>

**Table  1**  Parameter description

<a name="table110mcpsimp"></a>
<table><thead align="left"><tr id="row116mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p120mcpsimp"><a name="p120mcpsimp"></a><a name="p120mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p122mcpsimp"><a name="p122mcpsimp"></a><a name="p122mcpsimp"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row123mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p125mcpsimp"><a name="p125mcpsimp"></a><a name="p125mcpsimp"></a>No parameter</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p127mcpsimp"><a name="p127mcpsimp"></a><a name="p127mcpsimp"></a>Displays the size in bytes.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p129mcpsimp"><a name="p129mcpsimp"></a><a name="p129mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row130mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p132mcpsimp"><a name="p132mcpsimp"></a><a name="p132mcpsimp"></a>-k</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p134mcpsimp"><a name="p134mcpsimp"></a><a name="p134mcpsimp"></a>Displays the size in KiB.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p136mcpsimp"><a name="p136mcpsimp"></a><a name="p136mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row137mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p139mcpsimp"><a name="p139mcpsimp"></a><a name="p139mcpsimp"></a>-m</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p141mcpsimp"><a name="p141mcpsimp"></a><a name="p141mcpsimp"></a>Displays the size in MiB.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p143mcpsimp"><a name="p143mcpsimp"></a><a name="p143mcpsimp"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section148661259410"></a>

None

## Example<a name="section68081530242"></a>

Run  **free**,  **free -k**, and  **free -m**, respectively.

## Output<a name="section171235517543"></a>

**Figure  1**  Displaying the memory usage in three units<a name="fig478715471421"></a>  
![](figure/displaying-the-memory-usage-in-three-units.png "displaying-the-memory-usage-in-three-units")

**Table  2**  Output

<a name="table633mcpsimp"></a>
<table><thead align="left"><tr id="row638mcpsimp"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p640mcpsimp"><a name="p640mcpsimp"></a><a name="p640mcpsimp"></a>Output</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p642mcpsimp"><a name="p642mcpsimp"></a><a name="p642mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row643mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p645mcpsimp"><a name="p645mcpsimp"></a><a name="p645mcpsimp"></a>total</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p647mcpsimp"><a name="p647mcpsimp"></a><a name="p647mcpsimp"></a>Total size of the dynamic memory pool</p>
</td>
</tr>
<tr id="row648mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p650mcpsimp"><a name="p650mcpsimp"></a><a name="p650mcpsimp"></a>used</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p652mcpsimp"><a name="p652mcpsimp"></a><a name="p652mcpsimp"></a>Size of the used memory</p>
</td>
</tr>
<tr id="row653mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p655mcpsimp"><a name="p655mcpsimp"></a><a name="p655mcpsimp"></a>free</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p657mcpsimp"><a name="p657mcpsimp"></a><a name="p657mcpsimp"></a>Size of the unallocated memory</p>
</td>
</tr>
<tr id="row658mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p660mcpsimp"><a name="p660mcpsimp"></a><a name="p660mcpsimp"></a>heap</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p662mcpsimp"><a name="p662mcpsimp"></a><a name="p662mcpsimp"></a>Size of the allocated heap</p>
</td>
</tr>
<tr id="row10101624938"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p610724734"><a name="p610724734"></a><a name="p610724734"></a>text</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1510024539"><a name="p1510024539"></a><a name="p1510024539"></a>Size of a code segment</p>
</td>
</tr>
<tr id="row207288271839"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p572872713317"><a name="p572872713317"></a><a name="p572872713317"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p272852716315"><a name="p272852716315"></a><a name="p272852716315"></a>Size of a data segment</p>
</td>
</tr>
<tr id="row1774316321731"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p274343218317"><a name="p274343218317"></a><a name="p274343218317"></a>rodata</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1974319321133"><a name="p1974319321133"></a><a name="p1974319321133"></a>Size of a read-only data segment</p>
</td>
</tr>
<tr id="row121618371536"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p0161183720314"><a name="p0161183720314"></a><a name="p0161183720314"></a>bss</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p09295155511"><a name="p09295155511"></a><a name="p09295155511"></a>Size of the memory occupied by uninitialized global variables</p>
</td>
</tr>
</tbody>
</table>

