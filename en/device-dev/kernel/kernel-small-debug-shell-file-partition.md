# partition


## Command Function<a name="section255095212257"></a>

This command is used to query flash partition information.

## Syntax<a name="section10258056122515"></a>

partition \[_nand / spinor_\]

## Parameters<a name="section177200581256"></a>

**Table  1**  Parameter description

<a name="table1425mcpsimp"></a>
<table><thead align="left"><tr id="row1431mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1433mcpsimp"><a name="p1433mcpsimp"></a><a name="p1433mcpsimp"></a><strong id="b194783171311544"><a name="b194783171311544"></a><a name="b194783171311544"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p1435mcpsimp"><a name="p1435mcpsimp"></a><a name="p1435mcpsimp"></a><strong id="b207813185121"><a name="b207813185121"></a><a name="b207813185121"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1437mcpsimp"><a name="p1437mcpsimp"></a><a name="p1437mcpsimp"></a><strong id="b133141469711544"><a name="b133141469711544"></a><a name="b133141469711544"></a>Value Range</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1438mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1440mcpsimp"><a name="p1440mcpsimp"></a><a name="p1440mcpsimp"></a>nand</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1442mcpsimp"><a name="p1442mcpsimp"></a><a name="p1442mcpsimp"></a>Displays information about the NAND flash partition.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1444mcpsimp"><a name="p1444mcpsimp"></a><a name="p1444mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row1445mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1447mcpsimp"><a name="p1447mcpsimp"></a><a name="p1447mcpsimp"></a>spinor</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1449mcpsimp"><a name="p1449mcpsimp"></a><a name="p1449mcpsimp"></a>Displays information about the SPI NOR flash partition.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1451mcpsimp"><a name="p1451mcpsimp"></a><a name="p1451mcpsimp"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section17866411262"></a>

-   The  **partition**  command is used to query flash partition information.
-   The NAND flash partition information can be queried only when the Yet Another Flash File System \(YAFFS\) is enabled. The SPI NOR flash partition information can be queried only when the Journaling Flash File System \(JFFS\) or ROM filesystem \(romfs\) is enabled.

## Example<a name="section1927174202610"></a>

Run  **partition spinor**.

## Output<a name="section11321011223"></a>

SPI NOR flash partition information:

```
OHOS # partition spinor
spinor partition num:0,  blkdev name:/dev/spinorblk0, mountpt:/, startaddr:0x00500000, length:0x00a00000
```

