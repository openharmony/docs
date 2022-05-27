# mount


## Command Function<a name="section11631837182"></a>

This command is used to mount a device to a specified directory.

## Syntax<a name="section1697638111820"></a>

mount \[_-f_\] \[_-t TYPE_\] \[_-o OPTION,_\] \[\[_DEVICE_\]  _DIR_\]

## Parameters<a name="section1650151221819"></a>

**Table  1**  Parameter description

<a name="table1338mcpsimp"></a>
<table><thead align="left"><tr id="row1344mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1346mcpsimp"><a name="p1346mcpsimp"></a><a name="p1346mcpsimp"></a><strong id="b84913249612"><a name="b84913249612"></a><a name="b84913249612"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p1348mcpsimp"><a name="p1348mcpsimp"></a><a name="p1348mcpsimp"></a><strong id="b1136292612616"><a name="b1136292612616"></a><a name="b1136292612616"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1350mcpsimp"><a name="p1350mcpsimp"></a><a name="p1350mcpsimp"></a><strong id="b4385271067"><a name="b4385271067"></a><a name="b4385271067"></a>Value Range</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row081413014400"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p080318303407"><a name="p080318303407"></a><a name="p080318303407"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p8804113024018"><a name="p8804113024018"></a><a name="p8804113024018"></a>Displays the parameters supported by the <strong id="b07421044122514"><a name="b07421044122514"></a><a name="b07421044122514"></a>mount</strong> command.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p280418307406"><a name="p280418307406"></a><a name="p280418307406"></a>N/A</p>
</td>
</tr>
<tr id="row1781443044019"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1580410305409"><a name="p1580410305409"></a><a name="p1580410305409"></a>-f</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1980419305409"><a name="p1980419305409"></a><a name="p1980419305409"></a>Fakes mounting the file system (no mounting is actually performed).</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p58041230114019"><a name="p58041230114019"></a><a name="p58041230114019"></a>N/A</p>
</td>
</tr>
<tr id="row1981411307404"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p11804143024013"><a name="p11804143024013"></a><a name="p11804143024013"></a>-t</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p680443010409"><a name="p680443010409"></a><a name="p680443010409"></a>Specifies the file system type.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p13804193034020"><a name="p13804193034020"></a><a name="p13804193034020"></a>vfat, yaffs, jffs, ramfs, nfs, procfs, romfs</p>
</td>
</tr>
<tr id="row20813330184020"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p168041330194012"><a name="p168041330194012"></a><a name="p168041330194012"></a>-o</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p280473015402"><a name="p280473015402"></a><a name="p280473015402"></a>Specifies the mount options.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p4804193020407"><a name="p4804193020407"></a><a name="p4804193020407"></a>N/A</p>
</td>
</tr>
<tr id="row0813730134015"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p38041030124019"><a name="p38041030124019"></a><a name="p38041030124019"></a>DEVICE</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p28045303401"><a name="p28045303401"></a><a name="p28045303401"></a>Specifies the device to mount (in the format of the device directory).</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p8804113084010"><a name="p8804113084010"></a><a name="p8804113084010"></a>A device in the system</p>
</td>
</tr>
<tr id="row1381383044011"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p7804133012406"><a name="p7804133012406"></a><a name="p7804133012406"></a>DIR</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1380419308409"><a name="p1380419308409"></a><a name="p1380419308409"></a>Specifies the directory.</p>
<p id="p14804153014011"><a name="p14804153014011"></a><a name="p14804153014011"></a>You must have the execution (search) permission on the specified directory.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1780403094017"><a name="p1780403094017"></a><a name="p1780403094017"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section124541520171912"></a>

By specifying the device to mount, directory, and file system format in the  **mount**  command, you can successfully mount the file system to the specified directory.

## Example<a name="section7424625171917"></a>

Run  **mount -t nfs 192.168.1.3:/nfs nfs**.

## Output<a name="section14757018116"></a>

Mounting the  **nfs**  directory on the server with IP address of  **192.168.1.3**  to the newly created  **/nfs**  directory in the current system

```
OHOS:/$ mkdir nfs
OHOS:/$ mount -t nfs 192.168.1.3:/nfs nfs
Mount nfs on 192.168.1.3:/nfs, uid:0, gid:0
Mount nfs finished.
OHOS:/$ ls nfs/
16d.xml         gpio_test             ohos_test.txt    userfs_vfat.img
OHOS_Image.bin  hello                 rootfs_vfat.img
dev_tools       mksh_rootfs_vfat.img  test_demo
```

