# umount


## Command Function<a name="section365125133520"></a>

This command is used to unmount a specified file system.

## Syntax<a name="section9615254123512"></a>

umount \[_-a \[-t TYPE\]_\] \[_dir_\]

## Parameters<a name="section63446577355"></a>

**Table  1**  Parameter description

<a name="table1713mcpsimp"></a>
<table><thead align="left"><tr id="row1719mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1721mcpsimp"><a name="p1721mcpsimp"></a><a name="p1721mcpsimp"></a><strong id="b18608121184416"><a name="b18608121184416"></a><a name="b18608121184416"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p1723mcpsimp"><a name="p1723mcpsimp"></a><a name="p1723mcpsimp"></a><strong id="b123794114417"><a name="b123794114417"></a><a name="b123794114417"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1725mcpsimp"><a name="p1725mcpsimp"></a><a name="p1725mcpsimp"></a><strong id="b8664446440"><a name="b8664446440"></a><a name="b8664446440"></a>Value Range</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row915417105016"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1299991675018"><a name="p1299991675018"></a><a name="p1299991675018"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p5999201625017"><a name="p5999201625017"></a><a name="p5999201625017"></a>Displays the parameters supported by the <strong id="b15196112818310"><a name="b15196112818310"></a><a name="b15196112818310"></a>umount</strong> command.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1899981685020"><a name="p1899981685020"></a><a name="p1899981685020"></a>N/A</p>
</td>
</tr>
<tr id="row17151317125011"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1399931616501"><a name="p1399931616501"></a><a name="p1399931616501"></a>-a</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p159991716125019"><a name="p159991716125019"></a><a name="p159991716125019"></a>Unmounts all file systems mounted.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p999918167508"><a name="p999918167508"></a><a name="p999918167508"></a>N/A</p>
</td>
</tr>
<tr id="row21414171504"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p129997169509"><a name="p129997169509"></a><a name="p129997169509"></a>-t</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p49997167506"><a name="p49997167506"></a><a name="p49997167506"></a>Used together with the <strong id="b19922101571717"><a name="b19922101571717"></a><a name="b19922101571717"></a>-a</strong> option to restrict the file systems specified by <strong id="b1927154112172"><a name="b1927154112172"></a><a name="b1927154112172"></a>-a</strong>, allowing only the file system specified by <strong id="b99221198185"><a name="b99221198185"></a><a name="b99221198185"></a>-t</strong> to be unmounted.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p0999171695016"><a name="p0999171695016"></a><a name="p0999171695016"></a>N/A</p>
</td>
</tr>
<tr id="row131441775015"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p49990164502"><a name="p49990164502"></a><a name="p49990164502"></a>dir</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p129991162504"><a name="p129991162504"></a><a name="p129991162504"></a>Specifies the directory from which the file system is to be unmounted.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1499916164502"><a name="p1499916164502"></a><a name="p1499916164502"></a>Directory mounted with the file system</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section92931509368"></a>

By specifying the  **dir**  parameter in the  **unmount**  command, you can unmount the specified file system from the directory.

## Example<a name="section144311323616"></a>

Run the following commands:

-   umount ./nfs
-   umount -a -t nfs

## Output<a name="section360525113611"></a>

**unmount**  command output:

Example 1: unmounting the file system from  **./nfs**

```
OHOS:/$ umount ./nfs/
umount ok
```

Example 2: unmounting all NFS directories

```
OHOS:/$ umount -a -t nfs
umount ok
```

