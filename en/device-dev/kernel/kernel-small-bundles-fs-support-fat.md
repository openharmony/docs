# FAT


## Basic Concepts<a name="section621393911385"></a>

File Allocation Table \(FAT\) is a file system developed for personal computers. It consists of the DOS Boot Record \(DBR\) region, FAT region, and Data region. Each entry in the FAT region records information about the corresponding cluster in the storage device. The cluster information includes whether the cluster is used, the number of the next cluster of the file, and whether the file ends with the cluster. The FAT file system supports multiple formats, such as FAT12, FAT16, and FAT32. The numbers 12, 16, and 32 indicate the number of bits per cluster within the FAT, and also restrict the maximum file size in the system. The FAT file system supports multiple media, especially removable media \(such as USB flash drives, SD cards, and removable hard drives\). The FAT file system ensures good compatibility between embedded devices and desktop systems \(such as Windows and Linux\) and facilitates file management.

The OpenHarmony kernel supports FAT12, FAT16, and FAT32 file systems. These file systems require a tiny amount of code to implement, use less resources, support a variety of physical media, and are tailorable and compatible with Windows and Linux systems. They also support identification of multiple devices and partitions. The kernel supports multiple partitions on hard drives and allows creation of the FAT file system on the primary partition and logical partition.

## Working Principles<a name="section10796155213381"></a>

This document does not include the FAT design and physical layout. You can find a lot of reference on the Internet.

The OpenHarmony LiteOS-A kernel uses block cache \(Bcache\) to improve FAT performance. When read and write operations are performed, Bcache caches the sectors close to the read and write sectors to reduce the number of I/Os and improve performance. The basic cache unit of Bcache is block. The size of each block is the same. By default, there are 28 blocks, and each block caches data of 64 sectors. When the Bcache dirty block rate \(number of dirty sectors/total number of sectors\) reaches the threshold, writeback is triggered and cached data is written back to disks. You can manually call  **sync**  and  **fsync**  to write data to disks if you want. Some FAT APIs \(such as  **close**  and  **umount**\) may also trigger writeback operations. However, you are advised not to use them to trigger writeback.

## Development Guidelines<a name="section144094483919"></a>

### How to Develop<a name="section139086116394"></a>

The development process involves mounting partitions, managing files and directories, and unmounting partitions.

The device name of the SD card or MMC is  **mmcblk\[x\]p\[y\]**, and the file system type is  **vfat**.

Example:

```
mount("/dev/mmcblk0p0", "/mnt", "vfat", 0, NULL);
```

>![](../public_sys-resources/icon-note.gif) **NOTE**<br/> 
>-   The size of a single FAT file cannot be greater than 4 GiB.
>-   When there are two SD card slots, the first card inserted is card 0, and that inserted later is card 1.
>-   When multi-partition is enabled and there are multiple partitions, the device node  **/dev/mmcblk0**  \(primary device\) registered by card 0 and  **/dev/mmcblk0p0**  \(secondary device\) are the same device. In this case, you cannot perform operations on the primary device.
>-   Before removing an SD card, close the open files and directories and unmount the related nodes. Otherwise, SD card exceptions or memory leaks may occur.
>-   Before performing the  **format**  operation, unmount the mount point.
>-   After the Bcache feature takes effect, note the following:
>    -   When  **MS\_NOSYNC**  is carried in the  **mount**  function, FAT does not proactively write the content in the cache back to the storage device. The FAT-related APIs  **open**,  **close**,  **unlink**,  **rename**,  **mkdir**,  **rmdir**, and  **truncate**  do not automatically perform the  **sync**  operation, which improves the operation speed. However, the upper layer must actively invoke the  **sync**  operation to synchronize data. Otherwise, data loss may occur.
>    -   Bcache provides scheduled writeback. After  **LOSCFG\_FS\_FAT\_CACHE\_SYNC\_THREAD**  is enabled in  **menuconfig**, the OpenHarmony kernel creates a scheduled task to write the Bcache data back to disks. By default, the kernel checks the dirty block rate in the Bcache every 5 seconds. If the dirty block rate exceeds 80%, the  **sync**  operation will be performed to write all dirty data in the Bcache to disks. You can call  **LOS\_SetSyncThreadPrio**,  **LOS\_SetSyncThreadInterval**, and  **LOS\_SetDirtyRatioThreshold**  to set the task priority, flush interval, and dirty block rate threshold, respectively.
>    -   The cache has 28 blocks by default, and each block has 64 sectors.

