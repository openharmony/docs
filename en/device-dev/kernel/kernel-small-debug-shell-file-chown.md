# chown

## Command Function<a name="section247414691513"></a>

This command is used to change the owner of a file.

## Syntax<a name="section14773151018159"></a>

chown \[_owner_\] \[_pathname_\]

## Parameters<a name="section598731391517"></a>

**Table  1**  Parameter description

<a name="table1049mcpsimp"></a>
<table><thead align="left"><tr id="row1055mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1057mcpsimp"><a name="p1057mcpsimp"></a><a name="p1057mcpsimp"></a><strong id="b130925344111510"><a name="b130925344111510"></a><a name="b130925344111510"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p1059mcpsimp"><a name="p1059mcpsimp"></a><a name="p1059mcpsimp"></a><strong id="b1226032904716"><a name="b1226032904716"></a><a name="b1226032904716"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1061mcpsimp"><a name="p1061mcpsimp"></a><a name="p1061mcpsimp"></a><strong id="b34190246311510"><a name="b34190246311510"></a><a name="b34190246311510"></a>Value Range</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1541931122113"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p84121716217"><a name="p84121716217"></a><a name="p84121716217"></a>owner</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p14126172111"><a name="p14126172111"></a><a name="p14126172111"></a>Specifies the file owner.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p24129113218"><a name="p24129113218"></a><a name="p24129113218"></a>[0,0xFFFFFFFF]</p>
</td>
</tr>
<tr id="row12419191192111"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p141215115212"><a name="p141215115212"></a><a name="p141215115212"></a>pathname</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p7412315218"><a name="p7412315218"></a><a name="p7412315218"></a>Specifies the file path.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p134126102118"><a name="p134126102118"></a><a name="p134126102118"></a>An existing file</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section16524152071510"></a>

This command does not apply to the FAT file system.

## Example<a name="section17901152561510"></a>

Run  **chown 100 testfile**.

## Output<a name="section15513163115816"></a>

Changing the UID of the  **testfile**  file in  **/dev**  to  **100**:

```
OHOS:/dev$ touch testfile
OHOS:/dev$ ll testfile
-rw-r--r-- 0 0 100 0 1970-01-01 00:00 testfile
OHOS:/dev$ chown 100 testfile
OHOS:/dev$ ll testfile
-rw-r--r-- 0 100 100 0 1970-01-01 00:00 testfile
```

