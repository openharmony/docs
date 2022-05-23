# du

## Command Function<a name="section201149459368"></a>

This command is used to query the disk space occupied by a file.

## Syntax<a name="section579813484364"></a>

du \[_-kKmh_\] \[_file..._\]

## Parameters<a name="section168065311366"></a>

**Table  1**  Parameter description

<a name="table1845mcpsimp"></a>
<table><thead align="left"><tr id="row1851mcpsimp"><th class="cellrowborder" valign="top" width="20.84%" id="mcps1.2.4.1.1"><p id="p1853mcpsimp"><a name="p1853mcpsimp"></a><a name="p1853mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="52.16%" id="mcps1.2.4.1.2"><p id="p1855mcpsimp"><a name="p1855mcpsimp"></a><a name="p1855mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1857mcpsimp"><a name="p1857mcpsimp"></a><a name="p1857mcpsimp"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row10230133312716"><td class="cellrowborder" valign="top" width="20.84%" headers="mcps1.2.4.1.1 "><p id="p1921613332713"><a name="p1921613332713"></a><a name="p1921613332713"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="52.16%" headers="mcps1.2.4.1.2 "><p id="p14216153332715"><a name="p14216153332715"></a><a name="p14216153332715"></a>Displays the parameters supported by the <strong id="b22402916307"><a name="b22402916307"></a><a name="b22402916307"></a>du</strong> command.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p20216173362720"><a name="p20216173362720"></a><a name="p20216173362720"></a>N/A</p>
</td>
</tr>
<tr id="row1223010339271"><td class="cellrowborder" valign="top" width="20.84%" headers="mcps1.2.4.1.1 "><p id="p112161733202717"><a name="p112161733202717"></a><a name="p112161733202717"></a>-k</p>
</td>
<td class="cellrowborder" valign="top" width="52.16%" headers="mcps1.2.4.1.2 "><p id="p142161833172710"><a name="p142161833172710"></a><a name="p142161833172710"></a>Displays the occupied blocks, each of which is 1024 bytes by default.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p42161335276"><a name="p42161335276"></a><a name="p42161335276"></a>N/A</p>
</td>
</tr>
<tr id="row4230933182718"><td class="cellrowborder" valign="top" width="20.84%" headers="mcps1.2.4.1.1 "><p id="p152161336278"><a name="p152161336278"></a><a name="p152161336278"></a>-K</p>
</td>
<td class="cellrowborder" valign="top" width="52.16%" headers="mcps1.2.4.1.2 "><p id="p13216103319274"><a name="p13216103319274"></a><a name="p13216103319274"></a>Displays the occupied blocks, each of which is 512 bytes (POSIX).</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p192169337273"><a name="p192169337273"></a><a name="p192169337273"></a>N/A</p>
</td>
</tr>
<tr id="row1230103352716"><td class="cellrowborder" valign="top" width="20.84%" headers="mcps1.2.4.1.1 "><p id="p132161833192716"><a name="p132161833192716"></a><a name="p132161833192716"></a>-m</p>
</td>
<td class="cellrowborder" valign="top" width="52.16%" headers="mcps1.2.4.1.2 "><p id="p621673332720"><a name="p621673332720"></a><a name="p621673332720"></a>Displays the disk space in MB.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1321614336271"><a name="p1321614336271"></a><a name="p1321614336271"></a>N/A</p>
</td>
</tr>
<tr id="row10229133315272"><td class="cellrowborder" valign="top" width="20.84%" headers="mcps1.2.4.1.1 "><p id="p14216153313276"><a name="p14216153313276"></a><a name="p14216153313276"></a>-h</p>
</td>
<td class="cellrowborder" valign="top" width="52.16%" headers="mcps1.2.4.1.2 "><p id="p2216533192717"><a name="p2216533192717"></a><a name="p2216533192717"></a>Displays the disk space in human-readable format K, M, and G, for example, <strong id="b1315823125013"><a name="b1315823125013"></a><a name="b1315823125013"></a>1K</strong>, <strong id="b385962710225"><a name="b385962710225"></a><a name="b385962710225"></a>243M</strong>, or <strong id="b1114122962214"><a name="b1114122962214"></a><a name="b1114122962214"></a>2G</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p162161333102720"><a name="p162161333102720"></a><a name="p162161333102720"></a>N/A</p>
</td>
</tr>
<tr id="row1322918333273"><td class="cellrowborder" valign="top" width="20.84%" headers="mcps1.2.4.1.1 "><p id="p182160331270"><a name="p182160331270"></a><a name="p182160331270"></a>file</p>
</td>
<td class="cellrowborder" valign="top" width="52.16%" headers="mcps1.2.4.1.2 "><p id="p19216103310272"><a name="p19216103310272"></a><a name="p19216103310272"></a>Specifies the target file.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p182171332271"><a name="p182171332271"></a><a name="p182171332271"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section19190125723612"></a>

-   The  **du**  command is used to obtain the disk usage of a file rather than a directory.
-   The value of  **file**  must be the file name. It cannot contain the directory where the file is located.

## Example<a name="section10383416372"></a>

Run  **du -h testfile**.

## Output<a name="section16633113552815"></a>

Command output

```
OHOS:/$ du -h testfile
1.8K    testfile
```

