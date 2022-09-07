# Supported File Systems
## FAT


### Basic Concepts

File Allocation Table (FAT) is a file system developed for personal computers. It consists of the DOS Boot Record (DBR) region, FAT region, and Data region. Each entry in the FAT region records information about the corresponding cluster in the storage device. The cluster information includes whether the cluster is used, number of the next cluster of the file, whether the file ends with the cluster. The FAT file system supports multiple formats, such as FAT12, FAT16, and FAT32. The numbers 12, 16, and 32 indicate the number of bits per cluster within the FAT, and also restrict the maximum file size in the system. The FAT file system supports multiple media, especially removable media (such as USB flash drives, SD cards, and removable hard drives). The FAT file system ensures good compatibility between embedded devices and desktop systems (such as Windows and Linux) and facilitates file management.

The OpenHarmony kernel supports FAT12, FAT16, and FAT32 file systems. These file systems require a tiny amount of code to implement, use less resources, support a variety of physical media, and are tailorable and compatible with Windows and Linux systems. They also support identification of multiple devices and partitions. The kernel supports multiple partitions on hard drives and allows creation of the FAT file system on the primary partition and logical partition.


### Working Principles

This document does not include the FAT design and physical layout. You can find a lot of reference on the Internet.

The OpenHarmony LiteOS-A kernel uses block cache (Bcache) to improve FAT performance. When read and write operations are performed, Bcache caches the sectors close to the read and write sectors to reduce the number of I/Os and improve performance. The basic cache unit of Bcache is block. The size of each block is the same. By default, there are 28 blocks, and each block caches data of 64 sectors. When the Bcache dirty block rate (number of dirty sectors/total number of sectors) reaches the threshold, writeback is triggered and cached data is written back to disks. You can manually call **sync** and **fsync** to write data to disks if you want. Some FAT APIs (such as **close** and **umount**) may also trigger writeback operations. However, you are advised not to use them to trigger writeback.


### Development Guidelines


 **How to Develop**

The development process involves mounting partitions, managing files and directories, and unmounting partitions.

The device name of the SD card or MMC is **mmcblk[x]p[y]**, and the file system type is **vfat**.

Example:


```
mount("/dev/mmcblk0p0", "/mnt", "vfat", 0, NULL);
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> - The size of a single FAT file cannot be greater than 4 GiB.
> 
> - When there are two SD card slots, the first card inserted is card 0, and that inserted later is card 1.
> 
> - When multi-partition is enabled and there are multiple partitions, the device node **/dev/mmcblk0** (primary device) registered by card 0 and **/dev/mmcblk0p0** (secondary device) are the same device. In this case, you cannot perform operations on the primary device.
> 
> - Before removing an SD card, close the open files and directories and unmount the related nodes. Otherwise, SD card exceptions or memory leaks may occur.
> 
> - Before performing the **format** operation, unmount the mount point.
> 
> - After the Bcache feature takes effect, note the following:
>   - When **MS_NOSYNC** is carried in the **mount** function, FAT does not proactively write the content in the cache back to the storage device. The FAT-related APIs **open**, **close**, **unlink**, **rename**, **mkdir**, **rmdir**, and **truncate** do not automatically perform the **sync** operation, which improves the operation speed. However, the upper layer must actively invoke the **sync** operation to synchronize data. Otherwise, data loss may occur.
> 
>   - Bcache provides scheduled writeback. After **LOSCFG_FS_FAT_CACHE_SYNC_THREAD** is enabled in **menuconfig**, the OpenHarmony kernel creates a scheduled task to write the Bcache data back to disks. By default, the kernel checks the dirty block rate in the Bcache every 5 seconds. If the dirty block rate exceeds 80%, the **sync** operation will be performed to write all dirty data in the Bcache to disks. You can call **LOS_SetSyncThreadPrio**, **LOS_SetSyncThreadInterval**, and **LOS_SetDirtyRatioThreshold** to set the task priority, flush interval, and dirty block rate threshold, respectively.
>   - The cache has 28 blocks by default, and each block has 64 sectors.

## JFFS2


### Basic Concepts

Journalling Flash File System Version 2 (JFFS2) is a log-structured file system designed for Memory Technology Devices (MTDs).

JFFS2 is used on the NOR flash memory of the OpenHarmony. JFFS2 is readable and writable, supports data compression, provides crash or power failure protection, and supports wear leveling. There are many differences between flash memory and disk media. Running a disk file system on a flash memory device will cause performance and security problems. JFFS2 is a file system optimized for flash memory.


### Working Principles

For details about the physical layout of the JFFS2 file system on the storage device and the specifications of the file system, visit https://sourceware.org/jffs2/.

The following describes several important mechanisms and features of JFFS2 that you may concern.

1. Mount mechanism and speed: According to the JFFS2 design, all files are divided into nodes of different sizes based on certain rules and stored on the flash memory device in sequence. In the mount process, all node information needs to be obtained and cached in the memory. Therefore, the mount speed is in linear proportion to the flash device capacity and the number of files. This is a native design issue of JFFS2. To increase the mount speed, you can select **Enable JFFS2 SUMMARY** during kernel compilation. If this option is selected, information required by the mount operation will be stored to the flash memory in advance. When the mount operation is performed, this information can be read and parsed quickly, ensuring relatively constant mount speed. However, this space-for-time practice consumes about 8% extra space.

2. Wear leveling: Due to the physical attributes of flash memory devices, read and write operations can be performed only on blocks of a specific size. To prevent certain blocks from being severely worn, wear leveling is used on written blocks in JFFS2 to ensure relatively balanced writes on all blocks. This prolongs the overall service life of the flash memory devices.

3. Garbage collection (GC) mechanism: When a deletion operation is performed in JFFS2, the physical memory is not released immediately. An independent GC thread performs GC operations such as space defragmentation and migration. However, GC in JFFS2 affects instantaneous read/write performance, like all GC mechanisms. In addition, JFFS2 reserves about three blocks in each partition for space defragmentation. The reserved space is invisible to users.

4. Compression mechanism: The underlying layer automatically decompresses or compresses the data read or written each time in JFFS2. The actual I/O size is different from the read or write size requested by the user. You cannot estimate whether the write operation will succeed or not based on the size of the written data and the remaining space of the flash memory.

5. Hard link mechanism: JFFS2 supports hard links. Multiple hard links of the same file occupy physical memory space of only one hard link. The physical space is released only when all hard links are deleted.


### Development Guidelines

The development based on JFFS2 and NOR flash memory is similar to the development based on other file systems because the VFS shields the differences of specific file systems and the standard POSIX APIs are used as external APIs.

The raw NOR flash device has no place to centrally manage and record partition information. Therefore, you need to transfer the partition information by using other configuration methods (using the **bootargs** parameter during image burning), call the corresponding API in the code to add partitions, and then mount the partitions.

**Creating a JFFS2 Image**

Use the **mkfs.jffs2** tool to create an image. The default page size is 4 KiB, and the default **eraseblock** size is 64 KiB. Modify the parameter values to match your development.


```
./mkfs.jffs2 -d rootfs/ -o rootfs.jffs2
```

  **Table 1** Command description (run **mkfs.jffs2 --help** to view more details)

| Command| Description|
| -------- | -------- |
| -s | Specifies the page size. If this parameter is not specified, the default value **4KiB** is used.|
| -e | Specifies the **eraseblock** size. If this parameter is not specified, the default value **64KiB** is used.|
| -p | Specifies the image size. 0xFF is filled at the end of the image file to make the file to the specified size. If the size is not specified, 0xFF is filled to a value aligned with **eraseblock**.|
| -d | Specifies the source directory of the file system image.|
| -o | Specifies the image name.|

**Mounting a JFFS2 Partition**

Call **int mount(const char \*source, const char \*target, const char \*filesystemtype, unsigned long mountflags, const void \*data)** to mount the device node and mount point.

This function has the following parameters:

- **const char \*source** specifies the device node.
- **const char \*target** specifies the mount point. 
- **const char \*filesystemtype** specifies the file system type.
- **unsigned long mountflags** specifies the mount flag, which is **0** by default. 
- **const void \*data** specifies the data, which is **NULL** by default. 

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

Call **int umount(const char \*target)** to unmount a partition. You only need to specify the correct mount point.

Run the following command:


```
OHOS # umount /jffs1
```

If the following information is displayed, the JFFS2 partition is unmounted:


```
OHOS # umount /jffs1
umount ok
```
## NFS


### Basic Concepts

Network File System (NFS) allows you to share files across hosts and OSs over a network. You can treat NFS as a file system service, which is equivalent to folder sharing in the Windows OS to some extent.


### Working Principles

The NFS of the OpenHarmony LiteOS-A kernel acts as an NFS client. The NFS client can mount the directory shared by a remote NFS server to the local machine and run the programs and shared files without occupying the storage space of the current system. To the local machine, the directory on the remote server is like its disk.


### Development Guidelines

1. Create an NFS server.

   The following uses the Ubuntu OS as an example to describe how to configure an NFS server.

   - Install the NFS server software.

     Set the download source of the Ubuntu OS when the network connection is normal.


     ```
     sudo apt-get install nfs-kernel-server
     ```

   - Create a directory for mounting and assign full permissions for the directory.


     ```
     mkdir -p /home/sqbin/nfs
     sudo chmod 777 /home/sqbin/nfs
     ```

   - Configure and start the NFS server.

     Append the following line in the **/etc/exports** file:


     ```
     /home/sqbin/nfs *(rw,no_root_squash,async)
     ```
    
     **/home/sqbin/nfs** is the root directory shared by the NFS server.
    
     Start the NFS server.


     ```
     sudo /etc/init.d/nfs-kernel-server start
     ```
    
     Restart the NFS server.


     ```
     sudo /etc/init.d/nfs-kernel-server restart
     ```

2. Configure the board as an NFS client.

   In this section, the NFS client is a device running the OpenHarmony kernel.

   - Set the hardware connection.

     Connect the OpenHarmony kernel device to the NFS server. Set their IP addresses in the same network segment. For example, set the IP address of the NFS server to **10.67.212.178/24** and the IP address of the OpenHarmony kernel device to
    **10.67.212.3/24**. Note that this IP address is an intranet private IP address. Use the actual IP address.

     You can run the **ifconfig** command to check the OpenHarmony kernel device's IP address.

   - Start the network and ensure that the network between the board and NFS server is normal.

     Start the Ethernet or another type of network, and then run **ping** to check whether the network connection to the server is normal.


     ```
     OHOS # ping 10.67.212.178
     [0]Reply from 10.67.212.178: time=1ms TTL=63
     [1]Reply from 10.67.212.178: time=0ms TTL=63
     [2]Reply from 10.67.212.178: time=1ms TTL=63
     [3]Reply from 10.67.212.178: time=1ms TTL=63
     --- 10.67.212.178 ping statistics ---
     packets transmitted, 4 received, 0 loss

   Initialize the NFS client.


   ```
   OHOS # mkdir /nfs
   OHOS # mount 10.67.212.178:/home/sqbin/nfs /nfs nfs 1011 1000
   ```

   If the following information is displayed, the NFS client is initialized.


   ```
   OHOS # mount 10.67.212.178:/home/sqbin/nfs /nfs nfs 1011 1000
   Mount nfs on 10.67.212.178:/home/sqbin/nfs, uid:1011, gid:1000
   Mount nfs finished.
   ```

   This command mounts the **/home/sqbin/nfs** directory on the NFS server (IP address: 10.67.212.178) to the **/nfs** directory on the OpenHarmony kernel device.

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
   > This example assumes that the NFS server is available, that is, the **/home/sqbin/nfs** directory on the NFS server 10.67.212.178 is accessible.
   > 
   > The **mount** command format is as follows:
   > 
   > 
   > ```
   > mount <SERVER_IP:SERVER_PATH> <CLIENT_PATH> nfs
   > ```
   > 
   > **SERVER_IP** indicates the IP address of the server. <br>**SERVER_PATH** indicates the path of the shared directory on the NFS server. <br>**CLIENT_PATH** indicates the NFS path on the local device. <br>**nfs** indicates the path to which the remote shared directory is mounted on the local device. Replace the parameters as required.
   > 
   > If you do not want to restrict the NFS access permission, set the permission of the NFS root directory to **777** on the Linux CLI.
   > 
   > 
   > ```
   > chmod -R 777 /home/sqbin/nfs
   > ```
   > 
   > The NFS client setting is complete, and the NFS file system has been mounted.

3. Share files using NFS.

   Create the **dir** directory on the NFS server and save the directory. Run the **ls** command in the OpenHarmony kernel.

   ```
   OHOS # ls /nfs
   ```

   The following information is returned from the serial port:


   ```
   OHOS # ls /nfs 
   Directory /nfs:                 
   drwxr-xr-x 0        u:0     g:0     dir
   ```

   The **dir** directory created on the NFS server has been synchronized to the **/nfs** directory on the client (OpenHarmony kernel system).

   Similarly, you can create files and directories on the client (OpenHarmony kernel system) and access them from the NFS server.

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
   > Currently, the NFS client supports some NFS v3 specifications. Therefore, the NFS client is not fully compatible with all types of NFS servers. You are advised to use the Linux NFS server to perform the development.

## Ramfs


### Basic Concepts

Ramfs is a RAM-based file system whose size can be dynamically adjusted. Ramfs does not have a backing store. Directory entries and page caches are allocated when files are written into RAMFS. However, data is not written back to any other storage medium. This means that data will be lost after a power outage.
### Working Principles
Ramfs stores all files in RAM, and read/write operations are performed in RAM. Ramfs is generally used to store temporary data or data that needs to be frequently modified, such as the **/tmp** and **/var** directories. Using ramfs reduces the read/write loss of the memory and improves the data read/write speed.
### Development Guidelines
Mount: 
```
mount(NULL, "/dev/shm", "ramfs", 0, NULL)
```
Create a directory: 
```
mkdir(pathname, mode)
```
Create a file:
```
open(pathname, O_NONBLOCK | O_CREAT | O_RDWR, mode)
```
Read a directory: 
```
dir = opendir(pathname) 
ptr = readdir(dir)
closedir(dir)
```
Delete a file: 
```
unlink(pathname)
```
Delete a directory:
```
rmdir(pathname)
```
Unmount: 
```
umount("/dev/shm")
```
> ![icon-caution.gif](../public_sys-resources/icon-caution.gif) **CAUTION**<br/>
> - A ramfs file system can be mounted only once. Once mounted to a directory, it cannot be mounted to other directories.
> 
> - Ramfs is under debugging and disabled by default. Do not use it in formal products.

## procfs


### Basic Concepts

The proc filesystem (procfs) is a virtual file system that displays process or other system information in a file-like structure. It is more convenient to obtain system information in file operation mode than API calling mode.


### Working Principles

In the OpenHarmony kernel, procfs is automatically mounted to the **/proc** directory during startup. Only the kernel module can create file nodes to provide the query service.


### Development Guidelines

To create a procfs file, you need to use **ProcMkdir** to create a directory and use **CreateProcEntry** to create a file. The development of the file node function is to hook the read and write functions to the file created by **CreateProcEntry**. When the procfs file is read or written, the hooked functions will be called to implement custom functions.


Development Example

The following describes how to create the **/proc/hello/world** file to implement the following functions:

1. Create a file in **/proc/hello/world**.

2. Read the file. When the file is read, "HelloWorld!" is returned.

3. Write the file and print the data written in the file.


```
#include "proc_fs.h"

static int TestRead(struct SeqBuf *buf, void *arg)
{
    LosBufPrintf(buf, "Hello World! \n"); /* Print "Hello World!" to the buffer. The data in the buffer will be returned to the read result. */
    return 0;
}

static int TestWrite(struct ProcFile *pf, const char *buffer, size_t buflen, loff_t *ppos)
{
    if ((buffer == NULL) || (buflen <= 0)) {
        return -EINVAL;
    }

    PRINTK("your input is: %s\n", buffer); /* Different from the read API, the write API prints the data only to the console. */
    return buflen;
}
static const struct ProcFileOperations HELLO_WORLD_OPS = {
    .read = TestRead,
    .write = TestWrite,
};

void HelloWorldInit(void)
{
    /* Create the hello directory. */
    struct ProcDirEntry *dir = ProcMkdir("hello", NULL);
    if (dir == NULL) {
        PRINT_ERR("create dir failed!\n");
        return;
    }

    /* Create the world file. */
    struct ProcDirEntry *entry = CreateProcEntry("world", 0, dir);
    if (entry == NULL) {
        PRINT_ERR("create entry failed!\n");
        return;
    }

    /* Hook the custom read and write APIs to the file. */
    entry->procFileOps = &HELLO_WORLD_OPS;
}
```

**Verification**

After the OS startup, run the following commands in shell:


```
OHOS # cat /proc/hello/world
OHOS # Hello World!
OHOS # echo "yo" > /proc/hello/world
OHOS # your input is: yo
```
