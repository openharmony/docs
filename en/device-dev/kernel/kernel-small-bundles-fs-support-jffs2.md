# JFFS2
## Basic Concepts<a name="section11411110155919"></a>

Journalling Flash File System Version 2 \(JFFS2\) is a log-structured file system designed for Memory Technology Devices \(MTDs\).

JFFS2 is used on the NOR flash memory of the OpenHarmony. JFFS2 is readable and writable, supports data compression, provides crash/power failure protection, and supports wear leveling. There are many differences between flash memory and disk media. Running a disk file system on a flash memory device will cause performance and security problems. JFFS2 is a file system optimized for flash memory.

## Working Principles<a name="section23911025195913"></a>

This document does not include the physical layout of JFFS2 on storage devices and JFFS2 specifications. For details, see the  [official JFFS2 specification document](https://sourceware.org/jffs2/).

The following describes several important mechanisms and features of JFFS2 that you may concern.

1.  Mount mechanism and speed: According to the JFFS2 design, all files are divided into nodes of different sizes based on certain rules and stored on the flash memory device in sequence. In the mount process, all node information needs to be obtained and cached in the memory. Therefore, the mount speed is in linear proportion to the flash device capacity and the number of files. This is a native design issue of JFFS2. To increase the mount speed, you can select  **Enable JFFS2 SUMMARY**  during kernel compilation. If this option is selected, information required by the mount operation will be stored to the flash memory in advance. When the mount operation is performed, this information can be read and parsed quickly, ensuring relatively constant mount speed. However, this space-for-time practice consumes about 8% extra space.
2.  Wear leveling: Due to the physical attributes of flash memory devices, read and write operations can be performed only on blocks of a specific size. To prevent certain blocks from being severely worn, wear leveling is used on written blocks in JFFS2 to ensure relatively balanced writes on all blocks. This prolongs the overall service life of the flash memory devices.
3.  Garbage collection \(GC\) mechanism: When a deletion operation is performed in JFFS2, the physical memory is not released immediately. An independent GC thread performs GC operations such as space defragmentation and migration. However, GC in JFFS2 affects instantaneous read/write performance, like all GC mechanisms. In addition, JFFS2 reserves about three blocks in each partition for space defragmentation. The reserved space is invisible to users.
4.  Compression mechanism: The underlying layer automatically decompresses or compresses the data read or written each time in JFFS2. The actual I/O size is different from the read or write size requested by the user. You cannot estimate whether the write operation will succeed or not based on the size of the written data and the remaining space of the flash memory.
5.  Hard link mechanism: JFFS2 supports hard links. Multiple hard links of the same file occupy physical memory space of only one hard link. The physical space is released only when all hard links are deleted.

## Development Guidelines<a name="section179711119014"></a>

The development based on JFFS2 and NOR flash memory is similar to the development based on other file systems because the VFS shields the differences of specific file systems and the standard POSIX APIs are used as external APIs.

The raw NOR flash device has no place to centrally manage and record partition information. Therefore, you need to transfer the partition information by using other configuration methods \(using the  **bootargs**  parameter during image burning\), call the corresponding API in the code to add partitions, and then mount the partitions.

**Creating a JFFS2 Image**

Use the  **mkfs.jffs2**  tool to create an image. The default page size is 4 KiB, and the default  **eraseblock**  size is 64 KiB. Modify the parameter values to match your development.

```
./mkfs.jffs2 -d rootfs/ -o rootfs.jffs2
```

**Table  1**  Command description \(run  **mkfs.jffs2 --help**  to view more details\)

<a name="table1925613541465"></a>
<table><thead align="left"><tr id="row325613545615"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p153851336772"><a name="p153851336772"></a><a name="p153851336772"></a>Command</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p43852366714"><a name="p43852366714"></a><a name="p43852366714"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row125715410619"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p20385103615715"><a name="p20385103615715"></a><a name="p20385103615715"></a>-s</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1338510362717"><a name="p1338510362717"></a><a name="p1338510362717"></a>Specifies the page size. If this parameter is not specified, the default value <strong id="b3814183173513"><a name="b3814183173513"></a><a name="b3814183173513"></a>4KiB</strong> is used.</p>
</td>
</tr>
<tr id="row787741814720"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p538673616710"><a name="p538673616710"></a><a name="p538673616710"></a>-e</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p6386123612719"><a name="p6386123612719"></a><a name="p6386123612719"></a>Specifies the <strong id="b56716452412"><a name="b56716452412"></a><a name="b56716452412"></a>eraseblock</strong> size. If this parameter is not specified, the default value <strong id="b17480133411354"><a name="b17480133411354"></a><a name="b17480133411354"></a>64KiB</strong> is used.</p>
</td>
</tr>
<tr id="row1160020211719"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p83861361079"><a name="p83861361079"></a><a name="p83861361079"></a>-p</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1491185544517"><a name="p1491185544517"></a><a name="p1491185544517"></a>Specifies the image size. 0xFF is filled at the end of the image file to make the file to the specified size. If the size is not specified, 0xFF is filled to a value aligned with <strong id="b6777155933718"><a name="b6777155933718"></a><a name="b6777155933718"></a>eraseblock</strong>.</p>
</td>
</tr>
<tr id="row151563245714"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p183864361579"><a name="p183864361579"></a><a name="p183864361579"></a>-d</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p238618361573"><a name="p238618361573"></a><a name="p238618361573"></a>Specifies the source directory of the file system image.</p>
</td>
</tr>
<tr id="row1323210319714"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p103867369710"><a name="p103867369710"></a><a name="p103867369710"></a>-o</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1938603617710"><a name="p1938603617710"></a><a name="p1938603617710"></a>Specifies the image name.</p>
</td>
</tr>
</tbody>
</table>

**Mounting a JFFS2 Partition**

Call  **int mount\(const char \*source, const char \*target, const char \*filesystemtype, unsigned long mountflags, const void \*data\)**  to mount the device node and mount point.

This function has the following parameters:

-   **const char \*source**  specifies the device node.
-   **const char \*target**  specifies the mount point.
-   **const char \*filesystemtype**  specifies the file system type.
-   **unsigned long mountflags**  specifies the mount flag, which is  **0**  by default. 
-   **const void \*data**  specifies the data, which is  **NULL**  by default. 

You can also run the  **mount**  command in  **shell**  to mount a JFFS2 partition. In this case, you do not need to specify the last two parameters.

Run the following command:

```
OHOS # mount /dev/spinorblk1 /jffs1 jffs2
```

If the following information is displayed, the JFFS2 partition is mounted:

```
OHOS # mount /dev/spinorblk1 /jffs1 jffs2
mount OK
```

Now, you can perform read and write operations on the NOR flash memory.

**Unmounting a JFFS2 Partition**

Call  **int umount\(const char \*target\)**  to unmount a partition. You only need to specify the correct mount point.

Run the following command:

```
OHOS # umount /jffs1
```

If the following information is displayed, the JFFS2 partition is unmounted:

```
OHOS # umount /jffs1
umount ok
```

