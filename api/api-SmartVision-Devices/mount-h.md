# mount.h<a name="ZH-CN_TOPIC_0000001054829487"></a>

-   [Overview](#section256411640165628)
-   [Summary](#section1284779574165628)
-   [Functions](#func-members)

## **Overview**<a name="section256411640165628"></a>

**Related Modules:**

[FS](FS.md)

**Description:**

Provides functions for mounting and unmounting a file system. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1284779574165628"></a>

## Functions<a name="func-members"></a>

<a name="table1316754193165628"></a>
<table><thead align="left"><tr id="row326734844165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p516682408165628"><a name="p516682408165628"></a><a name="p516682408165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1675035463165628"><a name="p1675035463165628"></a><a name="p1675035463165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row828067816165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p268019722165628"><a name="p268019722165628"></a><a name="p268019722165628"></a><a href="FS.md#gadaaf1ec8aa37137233fa25d2b3af9fc8">mount</a> (const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1995906307165628"><a name="p1995906307165628"></a><a name="p1995906307165628"></a>int </p>
<p id="p1317463910165628"><a name="p1317463910165628"></a><a name="p1317463910165628"></a>Mounts a file system. </p>
</td>
</tr>
<tr id="row1074510242165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p742105729165628"><a name="p742105729165628"></a><a name="p742105729165628"></a><a href="FS.md#ga44634cfa8bcc732c29bcdf5822095422">umount</a> (const char *target)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p241083049165628"><a name="p241083049165628"></a><a name="p241083049165628"></a>int </p>
<p id="p667983442165628"><a name="p667983442165628"></a><a name="p667983442165628"></a>Unmounts a file system. </p>
</td>
</tr>
<tr id="row150843509165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p724735220165628"><a name="p724735220165628"></a><a name="p724735220165628"></a><a href="FS.md#ga2125a021d10f7a28a66cbc9335ad826f">umount2</a> (const char *target, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1033222173165628"><a name="p1033222173165628"></a><a name="p1033222173165628"></a>int </p>
<p id="p1901605697165628"><a name="p1901605697165628"></a><a name="p1901605697165628"></a>Unmounts a file system. </p>
</td>
</tr>
</tbody>
</table>

