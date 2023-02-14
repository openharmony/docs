# File Systems

## VFS


### Basic Concepts

The Virtual File System (VFS) is not a real file system. It is an abstract layer on top of a heterogeneous file system and provides you with a unified Unix-like interface for file operations. Different types of file systems use different file operation interfaces. If there are multiple types of file systems in a system, different and non-standard interfaces are required for accessing these file systems. The VFS is introduced as an abstract layer to shield the differences between these heterogeneous file systems. With the VFS, you do not need to care about the underlying storage medium and file system type.

The OpenHarmony LiteOS-M kernel supports the File Allocation Table (FAT) and LittleFS file systems. It provides the Portable Operating System Interface (POSIX) over the VFS to ensure interface consistency. However, the VFS of the LiteOS-M kernel is light and does not provide advanced functions (such as pagecache) due to insufficient resources. Therefore, the VFS of the LiteOS-M kernel implements only API standardization and adaptation. The file systems handle specific transactions. The following tables describe the APIs supported by the file systems of the LiteOS-M kernel.

### Available APIs

**Table 1** APIs for file operations

| API| Description| FAT | LittleFS |
| -------- | -------- | -------- | -------- |
| open | Opens a file.| Supported| Supported|
| close | Closes a file.| Supported| Supported|
| read   | Reads the file content.              | Supported | Supported    |
| write  | Writes data to a file.            | Supported | Supported    |
| lseek  | Sets the file offset.          | Supported | Supported    |
| stat   | Obtains file information based on the file path name.| Supported | Supported    |
| unlink | Deletes a file.| Supported| Supported|
| rename | Renames the file.| Supported| Supported|
| fstat  | Obtains file information based on the file handle.  | Supported | Supported    |
| fsync  | Saves a file to a storage device.    | Supported | Supported    |

**Table 2** APIs for directory operations

| API| Description| FATFS | LITTLEFS |
| -------- | -------- | -------- | -------- |
| mkdir | Creates a directory.| Supported| Supported|
| opendir | Opens a directory.| Supported| Supported|
| readdir | Reads the content of a directory.| Supported| Supported|
| closedir | Closes a directory.| Supported| Supported|
| rmdir | Deletes a directory.| Supported| Supported|

**Table 3** APIs for partition operations

| API| Description| FATFS | LITTLEFS |
| -------- | -------- | -------- | -------- |
| mount | Mounts a partition.| Supported| Supported|
| umount | Unmounts a partition.| Supported| Supported|
| umount2 | Forcibly unmounts a partition using the **MNT_FORCE** parameter.| Supported| Not supported|
| statfs | Obtains partition information.| Supported| Not supported|

Interfaces, such as **ioctl** and **fcntl**, are supported by different libraries and are irrelevant to the underlying file system.

## FAT


### Basic Concepts

As a file system designed for personal computers, the FAT file system consists of the DOS Boot Record (DBR) region, FAT region, and Data region. Each entry in the FAT region records information about the corresponding cluster in the storage device. The cluster information includes whether the cluster is used, number of the next cluster of the file, whether the file ends with the cluster. 

The FAT file system supports a variety of formats, including FAT12, FAT16, and FAT32. The numbers 12, 16, and 32 indicate the number of bits per cluster within the FAT, respectively. The FAT file system also supports diversified storage media, especially removable media (such as USB flash drives, SD cards, and removable hard drives). It features good compatibility between embedded devices and desktop systems (such as Windows and Linux) and facilitates file management.

The OpenHarmony kernel supports FAT12, FAT16, and FAT32 file systems. These file systems require a tiny amount of code to implement, use less resources, support a variety of physical media, and are tailorable and compatible with Windows and Linux systems. They also support identification of multiple devices and partitions. The kernel supports multiple partitions on hard drives and allows creation of the FAT file system on the primary and logical partitions.


### Development Guidelines


#### Driver Adaptation

The use of a FAT file system requires support from the underlying MultiMediaCard (MMC) driver. Before using a FAT file system on a board with an MMC, you must perform the following operations:

1. Implement the **disk_status**, **disk_initialize**, **disk_read**, **disk_write**, and **disk_ioctl** APIs to adapt to the embedded MMC (eMMC) driver on the board.

2. Add the **fs_config.h** file with information such as **FS_MAX_SS** (maximum sector size of the storage device) and **FF_VOLUME_STRS** (partition names) configured.

   The following is an example:


```
#define FF_VOLUME_STRS     "system", "inner", "update", "user"
#define FS_MAX_SS          512
#define FAT_MAX_OPEN_FILES 50
```

#### Mounting Partitions

Before using a FAT file system on a device, you need to initialize the flash drive and partition the device storage.

API for partitioning the storage: 

**int LOS_DiskPartition(const char \*dev, const char \*fsType, int \*lengthArray, int \*addrArray, int partNum);**

- **dev**: pointer to the device name, for example, **spinorblk0**.
- **fsType**: pointer to the file system type, which is **vfat** for the FAT file system.
- **lengthArray**: pointer to a list of partition lengths (in percentage for a FAT file system) of the device.
- **addrArray**: pointer to a list of partition start addresses of the device.
- **partNum**: number of partitions.

API for formatting a partition: 

**int LOS_PartitionFormat(const char \*partName, char \*fsType, void \*data);**

- **partName**: pointer to the partition name, in the *Device_name*+**p**+*Partition_ number* format. For example, **spinorblk0p0**.
- **fsType**: pointer to the file system type, which is **vfat** for the FAT file system.
- **data**: pointer to the private data that passes in **(VOID \*) formatType**, for example, **FMT_FAT** or **FMT_FAT32**.

API for mounting a partition: 

**int mount(const char \*source, const char \*target, const char \*filesystemtype, unsigned long mountflags, const void \*data);**

- **source**: pointer to the partition name, in the *Device_name*+**p**+*Partition_ number* format. For example, **spinorblk0p0**.  
- **target**: pointer to the target path to mount.
- **filesystemtype**: pointer to the file system type, which is **vfat** for the FAT file system.
- **mountflags**: parameters used for the mount operation.
- **data**: pointer to the private data that passes in **(VOID \*) formatType**, for example, **FMT_FAT** or **FMT_FAT32**.

The sample code is implemented in **./device/qemu/arm_mps2_an386/liteos_m/board/fs/fs_init.c** and can be directly used on the Quick EMUlator (QEMU) that uses the LiteOS-M kernel. You can modify the code based on the hardware you use.

    #include "fatfs_conf.h"
    #include "fs_config.h"
    #include "los_config.h"
    #include "ram_virt_flash.h"
    #include "los_fs.h"
    
    struct fs_cfg {
        CHAR *mount_point;
        struct PartitionCfg partCfg;
    };
    
    INT32 FatfsLowLevelInit()
    {
        INT32 ret;
        INT32 i;
        UINT32 addr;
        int data = FMT_FAT32;
    
        const char * const pathName[FF_VOLUMES] = {FF_VOLUME_STRS};
        HalLogicPartition *halPartitionsInfo = getPartitionInfo(); /* Function for obtaining the partition lengths and start addresses. Modify it as required. */
        INT32 lengthArray[FF_VOLUMES] = {25, 25, 25, 25};
        INT32 addrArray[FF_VOLUMES];
    
        /* Set the address and length for each partition. */
        for (i = 0; i < FF_VOLUMES; i++) {
            addr = halPartitionsInfo[FLASH_PARTITION_DATA1].partitionStartAddr + i * 0x10000;
            addrArray[i] = addr;
            FlashInfoInit(i, addr);
        }
    
        /* Set partition information. */
        SetupDefaultVolToPartTable();
    
        ret = LOS_DiskPartition("spinorblk0", "vfat", lengthArray, addrArray, FF_VOLUMES);
        printf("%s: DiskPartition %s\n", __func__, (ret == 0) ? "succeed" : "failed");
        if (ret != 0) {
            return -1;
        }
    
        ret = LOS_PartitionFormat("spinorblk0p0", "vfat", &data);
        printf("%s: PartitionFormat %s\n", __func__, (ret == 0) ? "succeed" : "failed");
        if (ret != 0) {
            return -1;
        }
    
        ret = mount("spinorblk0p0", "/system", "vfat", 0, &data);
        printf("%s: mount fs on '%s' %s\n", __func__, pathName[0], (ret == 0) ? "succeed" : "failed");
        if (ret != 0) {
            return -1;
        }
        return 0;
    }
#### How to Develop

Observe the following when managing files and directories in a FAT file system:

- A file cannot exceed 4 GB.
- **FAT_MAX_OPEN_FILES** specifies the maximum number files you can open at a time, and **FAT_MAX_OPEN_DIRS** specifies the maximum number of folders you can open at a time.
- Root directory management is not supported. File and directory names start with the partition name. For example, **user/testfile** indicates the **testfile** file or directory in the **user** partition.
- To open a file multiple times at the same time, use **O_RDONLY** (read-only mode).  **O_RDWR** or **O_WRONLY** (writable mode) can open a file only once at a time.
- The read and write pointers are not separated. If a file is open in **O_APPEND** mode, the read pointer is also at the end of the file. If you want to read the file from the beginning, you must manually set the position of the read pointer.
- File and directory permission management is not supported.
- The **stat** and **fstat** APIs do not support query of the modification time, creation time, and last access time. The Microsoft FAT protocol does not support time before A.D. 1980.

Observe the following when managing files and directories in a FAT file system:

- Partitions can be mounted with the read-only attribute. If the input parameter of **mount()** is **MS_RDONLY**, all APIs with the write attribute, such as **write()**, **mkdir()**, **unlink()**, and **open()** with **non-O_RDONLY** attributes, will be rejected.
- You can use the **MS_REMOUNT** flag in **mount()** to modify the permissions for a mounted partition.
- Before unmounting a partition, ensure that all directories and files in the partition are closed.
- You can use **umount2** with the **MNT_FORCE** parameter to forcibly close all files and folders and unmount the partition. However, this may cause data loss. Therefore, exercise caution when using **umount2**.

You can use **fatfs_fdisk()** and **fatfs_format()** to re-partition the device storage and format the partitions. Observe the following:

- Before using  **fatfs_format()**, ensure that the target partition is unmounted and all directories and files in the partition are closed. 
- Before using **fatfs_fdisk**, ensure that all partitions in the device are unmounted.
- Using **fatfs_fdisk** and **fatfs_format** may cause data loss. Exercise caution when using them.


### Development Example


#### Example Description

This example implements the following:

1. Create a **system/test** directory.

2. Create a **file.txt** file in the **system/test** directory.

3. Write **Hello OpenHarmony!** at the beginning of the file.

4. Save the file to a device.

5. Set the offset to the start position of the file.

6. Reads the file content.

7. Close the file.

8. Delete the file.

9. Delete the directory.


#### Sample Code

**Prerequisites**

- The **system** partition is mounted to the QEMU.
- FAT is enabled. 
  1. In the **kernel/liteos_m** directory, run the **make menuconfig** command and choose **FileSystem->Enable FS VFS** to enable VFS.
  2. Select **Enable FAT** to enable the FAT file system.   

**Implementation**

The sample code can be compiled and verified in **./kernel/liteos_m/testsuites/src/osTest.c**. The **ExampleFatfs** function is called in **TestTaskEntry**.

  ```
#include <stdio.h>
#include <string.h>
#include "sys/stat.h"
#include "fcntl.h"
#include "unistd.h"

#define BUF_SIZE 20
#define TEST_ROOT "system" /* Set the test root directory. */
VOID ExampleFatfs(VOID)
{
    int ret;
    int fd;
    ssize_t len;
    off_t off;
    char dirName[BUF_SIZE] = TEST_ROOT"/test";
    char fileName[BUF_SIZE] = TEST_ROOT"/test/file.txt";
    char writeBuf[BUF_SIZE] = "Hello OpenHarmony!";
    char readBuf[BUF_SIZE] = {0};

    /* Create a test directory. */
    ret = mkdir(dirName, 0777);
    if (ret != LOS_OK) {
        printf("mkdir failed.\n");
        return;
    }

    /* Create a file that is readable and writable. */
    fd = open(fileName, O_RDWR | O_CREAT, 0777);
    if (fd < 0) {
        printf("open file failed.\n");
        return;
    }

    /* Write the content from writeBuf to the file. */
    len = write(fd, writeBuf, strlen(writeBuf));
    if (len != strlen(writeBuf)) {
        printf("write file failed.\n");
        return;
    }

    /* Save the file to a storage device. */
    ret = fsync(fd);
    if (ret != LOS_OK) {
        printf("fsync failed.\n");
        return;
    }

    /* Move the read/write pointer to the beginning of the file. */
    off = lseek(fd, 0, SEEK_SET);
    if (off != 0) {
        printf("lseek failed.\n");
        return;
    }

    /* Read the file content with the length of readBuf to readBuf. */
    len = read(fd, readBuf, sizeof(readBuf));
    if (len != strlen(writeBuf)) {
        printf("read file failed.\n");
        return;
    }
    printf("%s\n", readBuf);

    /* Close the test file. */
    ret = close(fd);
    if (ret != LOS_OK) {
        printf("close failed.\n");
        return;
    }

    /* Delete the test file. */
    ret = unlink(fileName);
    if (ret != LOS_OK) {
        printf("unlink failed.\n");
        return;
    }

    /* Delete the test directory. */
    ret = rmdir(dirName);
    if (ret != LOS_OK) {
        printf("rmdir failed.\n");
        return;
    }

    return;
}
  ```


#### Verification

The development is successful if the return result is as follows:


```
Hello OpenHarmony!
```
## LittleFS


### Basic Concepts

LittleFS is a small file system designed for the flash drive. It stores metadata in log structure and data in the copy-on-write (COW) structure. This feature empowers LittleFS high power-loss resilience. LittleFS uses the statistical wear leveling algorithm when allocating COW data blocks, effectively prolonging the service life of flash devices. LittleFS is designed for small-sized devices with limited resources, such as ROM and RAM. All RAM resources are allocated through a buffer with the fixed size (configurable). That is, the RAM usage does not grow with the file system.

LittleFS is a good choice when you look for a flash file system that is power-cut resilient and has wear leveling support on a small device with limited resources.


### Development Guidelines

Before using a LittleFS to a device, you need to initialize the flash drive and partition the device storage

API for partitioning the storage: 

**int LOS_DiskPartition(const char \*dev, const char \*fsType, int \*lengthArray, int \*addrArray, int partNum);**

- **dev**: pointer to the device name.
- **fsType**: pointer to the file system type, which is **littlefs** for LittleFS.
- **lengthArray**: pointer to a list of partition lengths of the device.
- **addrArray**: pointer to a list of partition start addresses of the device.
- **partNum**: number of partitions.

API for formatting a partition: 

**int LOS_PartitionFormat(const char \*partName, char \*fsType, void \*data);**

- **partName**: pointer to the partition name.
- **fsType**: pointer to the file system type, which is **littlefs** for LittleFS.
- **data**: pointer to the private data that passes in **void pass (VOID \*) struct fs_cfg**.

API for mounting a partition: 

**int mount(const char \*source, const char \*target, const char \*filesystemtype, unsigned long mountflags, const void \*data);**

- **source**: pointer to the partition name.
- **target**: pointer to the target path to mount.
- **filesystemtype**: pointer to the file system type, which is **littlefs** for LittleFS.
- **mountflags**: parameters used for the mount operation.
- **data**: pointer to the private data that passes in **void pass (VOID \*) struct fs_cfg**.

The sample code is implemented in **./device/qemu/arm_mps2_an386/liteos_m/board/fs/fs_init.c** and can be directly used on the QEMU that uses the LiteOS-M kernel. You can modify the code based on the hardware you use.


```
#include "los_config.h"
#include "ram_virt_flash.h"
#include "los_fs.h"

struct fs_cfg {
    CHAR *mount_point;
    struct PartitionCfg partCfg;
};

INT32 LfsLowLevelInit()
{
    INT32 ret;
    struct fs_cfg fs[LOSCFG_LFS_MAX_MOUNT_SIZE] = {0};
    HalLogicPartition *halPartitionsInfo = getPartitionInfo();  /* Function for obtaining the partition lengths and start addresses. You can modify the function to match your development. */

    INT32 lengthArray[2];
    lengthArray[0]= halPartitionsInfo[FLASH_PARTITION_DATA0].partitionLength;

    INT32 addrArray[2];
    addrArray[0] = halPartitionsInfo[FLASH_PARTITION_DATA0].partitionStartAddr;

    ret = LOS_DiskPartition("flash0", "littlefs", lengthArray, addrArray, 2);
    printf("%s: DiskPartition %s\n", __func__, (ret == 0) ? "succeed" : "failed");
    if (ret != 0) {
        return -1;
    }
    fs[0].mount_point = "/littlefs";
    fs[0].partCfg.partNo = 0;
    fs[0].partCfg.blockSize = 4096; /* 4096, lfs block size */
    fs[0].partCfg.blockCount = 1024; /* 2048, lfs block count */
    fs[0].partCfg.readFunc = virt_flash_read;		/* Function for reading data from the flash drive. You can modify it to match your development. */
    fs[0].partCfg.writeFunc = virt_flash_write;		/* Function for writing data to the flash drive. You can modify it to match your development. */
    fs[0].partCfg.eraseFunc = virt_flash_erase;		/* Function for erasing the flash driver. You can modify it to match your development. */

    fs[0].partCfg.readSize = 256; /* 256, lfs read size */
    fs[0].partCfg.writeSize = 256; /* 256, lfs prog size */
    fs[0].partCfg.cacheSize = 256; /* 256, lfs cache size */
    fs[0].partCfg.lookaheadSize = 16; /* 16, lfs lookahead size */
    fs[0].partCfg.blockCycles = 1000; /* 1000, lfs block cycles */

    ret = LOS_PartitionFormat("flash0", "littlefs", &fs[0].partCfg);
    printf("%s: PartitionFormat %s\n", __func__, (ret == 0) ? "succeed" : "failed");
    if (ret != 0) {
        return -1;
    }
    ret = mount(NULL, fs[0].mount_point, "littlefs", 0, &fs[0].partCfg);
    printf("%s: mount fs on '%s' %s\n", __func__, fs[0].mount_point, (ret == 0) ? "succeed" : "failed");
    if (ret != 0) {
        return -1;
    }
    return 0;
}
```

The **.readFunc**, **.writeFunc**, and **.eraseFunc** functions correspond to **read()**, **write()**, and **erase()** of the underlying hardware platform.

**readSize** indicates the number of bytes read each time. You can set it to a value greater than the physical read unit to improve performance. This value determines the size of the read cache. However, if the value is too large, more memory is consumed.

**writeSize** indicates the number of bytes written each time. You can set it to a value greater than the physical write unit to improve performance. This value determines the size of the write cache and must be an integral multiple of **readSize**. However, if the value is too large, more memory is consumed.

**blockSize** indicates the number of bytes in each erase block. The value can be greater than that of the physical erase unit. However, a smaller value is recommended because each file occupies at least one block. The value must be an integral multiple of **writeSize**.

**blockCount** indicates the number of blocks that can be erased, which depends on the capacity of the block device and the size of the block to be erased (**blockSize**).


### Sample Code

**Prerequisites**

- **/littlefs** is mounted to the QEMU.
- LittleFS is enabled.
  1. In the **kernel/liteos_m** directory, run the **make menuconfig** command and choose **FileSystem->Enable FS VFS** to enable VFS.
  2. Select **Enable Little FS** to enable the LittleFS.

The sample code is as follows:

The sample code can be compiled and verified in **./kernel/liteos_m/testsuites/src/osTest.c**. The **ExampleLittlefs** function is called in **TestTaskEntry**.

```
#include <stdio.h>
#include <string.h>
#include "sys/stat.h"
#include "fcntl.h"
#include "unistd.h"

#define BUF_SIZE 20
#define TEST_ROOT "/littlefs" /* Set the test root directory. */
VOID ExampleLittlefs(VOID)
{
    int ret;
    int fd;
    ssize_t len;
    off_t off;
    char dirName[BUF_SIZE] = TEST_ROOT"/test";
    char fileName[BUF_SIZE] = TEST_ROOT"/test/file.txt";
    char writeBuf[BUF_SIZE] = "Hello OpenHarmony!";
    char readBuf[BUF_SIZE] = {0};

    /* Create a test directory. */
    ret = mkdir(dirName, 0777);
    if (ret != LOS_OK) {
        printf("mkdir failed.\n");
        return;
    }

    /* Create a file that is readable and writable. */
    fd = open(fileName, O_RDWR | O_CREAT, 0777);
    if (fd < 0) {
        printf("open file failed.\n");
        return;
    }

    /* Write the content from writeBuf to the file. */
    len = write(fd, writeBuf, strlen(writeBuf));
    if (len != strlen(writeBuf)) {
        printf("write file failed.\n");
        return;
    }

    /* Save the file to a storage device. */
    ret = fsync(fd);
    if (ret != LOS_OK) {
        printf("fsync failed.\n");
        return;
    }

    /* Move the read/write pointer to the beginning of the file. */
    off = lseek(fd, 0, SEEK_SET);
    if (off != 0) {
        printf("lseek failed.\n");
        return;
    }

    /* Read the file content with the length of readBuf to readBuf. */
    len = read(fd, readBuf, sizeof(readBuf));
    if (len != strlen(writeBuf)) {
        printf("read file failed.\n");
        return;
    }
    printf("%s\n", readBuf);

    /* Close the test file. */
    ret = close(fd);
    if (ret != LOS_OK) {
        printf("close failed.\n");
        return;
    }

    /* Delete the test file. */
    ret = unlink(fileName);
    if (ret != LOS_OK) {
        printf("unlink failed.\n");
        return;
    }

    /* Delete the directory. */
    ret = rmdir(dirName);
    if (ret != LOS_OK) {
        printf("rmdir failed.\n");
        return;
    }

    return LOS_OK;
}
```

**Verification**

The development is successful if the return result is as follows:


```
Hello OpenHarmony!
```

