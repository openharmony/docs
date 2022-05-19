# rmdir


## Command Function<a name="section1839611420266"></a>

This command is used to delete a directory.

## Syntax<a name="section329574512266"></a>

rmdir \[_-p_\] \[_dirname..._\]

## Parameters<a name="section15865747102620"></a>

**Table  1**  Parameter description

<a name="table1557mcpsimp"></a>
<table><thead align="left"><tr id="row1563mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1565mcpsimp"><a name="p1565mcpsimp"></a><a name="p1565mcpsimp"></a><strong id="b170710424141"><a name="b170710424141"></a><a name="b170710424141"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p1567mcpsimp"><a name="p1567mcpsimp"></a><a name="p1567mcpsimp"></a><strong id="b10358846121415"><a name="b10358846121415"></a><a name="b10358846121415"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1569mcpsimp"><a name="p1569mcpsimp"></a><a name="p1569mcpsimp"></a><strong id="b171032047111410"><a name="b171032047111410"></a><a name="b171032047111410"></a>Value Range</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row17771161013316"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p19752111019336"><a name="p19752111019336"></a><a name="p19752111019336"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p18752121015338"><a name="p18752121015338"></a><a name="p18752121015338"></a>Displays the parameters supported by the <strong id="b101038101521"><a name="b101038101521"></a><a name="b101038101521"></a>rmdir</strong> command.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p127521810103316"><a name="p127521810103316"></a><a name="p127521810103316"></a>N/A</p>
</td>
</tr>
<tr id="row977061043317"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p67521810113316"><a name="p67521810113316"></a><a name="p67521810113316"></a>-p</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1475271013319"><a name="p1475271013319"></a><a name="p1475271013319"></a>Deletes a path.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p117525107338"><a name="p117525107338"></a><a name="p117525107338"></a>N/A</p>
</td>
</tr>
<tr id="row2769810133315"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p775211053314"><a name="p775211053314"></a><a name="p775211053314"></a>--ignore-fail-on-non-empty</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p77522010123314"><a name="p77522010123314"></a><a name="p77522010123314"></a>Suppresses the error message when a non-empty directory is to be deleted.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1475281014339"><a name="p1475281014339"></a><a name="p1475281014339"></a>N/A</p>
</td>
</tr>
<tr id="row1776918105337"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p5752141018337"><a name="p5752141018337"></a><a name="p5752141018337"></a>dir</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p3752161083313"><a name="p3752161083313"></a><a name="p3752161083313"></a>Specifies the name of the directory to delete. The directory must be empty. A path is supported.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p57521210113313"><a name="p57521210113313"></a><a name="p57521210113313"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section107857508261"></a>

-   The  **rmdir**  command can only be used to delete directories.
-   The  **rmdir**  command can delete only one directory at a time.
-   The  **rmdir**  command can delete only empty directories.

## Example<a name="section11196165315262"></a>

Run  **rmdir dir**.

## Output<a name="section1073811415613"></a>

Deleting the directory  **dir**:

```
OHOS:/test$ mkdir dir
OHOS:/test$ ls
dir
OHOS:/test$ rmdir dir/
OHOS:/test$ ls
```

