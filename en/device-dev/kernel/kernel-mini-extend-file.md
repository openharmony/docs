# File System

The OpenHarmony LiteOS-M kernel supports File Allocation Table file system (FATFS) and LittleFS file systems. Like the OpenHarmony LiteOS-A kernel, the OpenHarmony LiteOS-M kernel provides POSIX over the virtual file system (VFS) to ensure interface consistency. However, the VFS of the LiteOS-M kernel is light due to insufficient resources and does not provide advanced functions (such as pagecache). Therefore, the VFS of the LiteOS-M kernel implements only API standardization and adaptation. The file systems handle specific transactions. 

The following tables list the APIs supported by the file systems of the LiteOS-M kernel.


  **Table 1** File management operations

| API| Description| FATFS | LITTLEFS |
| -------- | -------- | -------- | -------- |
| open | Opens a file.| Supported| Supported|
| close | Closes a file.| Supported| Supported|
| read | Reads the file content.| Supported| Supported|
| write | Writes data to a file.| Supported| Supported|
| lseek | Sets the file offset.| Supported| Supported|
| unlink | Deletes a file.| Supported| Supported|
| rename | Renames the file.| Supported| Supported|
| fstat | Obtains file information based on the file handle.| Supported| Supported|
| stat | Obtains file information based on the file path name.| Supported| Supported|
| fsync | Saves file updates to a storage device.| Supported| Supported|


  **Table 2** Directory management operations

| API| Description| FATFS | LITTLEFS |
| -------- | -------- | -------- | -------- |
| mkdir | Creates a directory.| Supported| Supported|
| opendir | Opens a directory.| Supported| Supported|
| readdir | Reads the content of a directory.| Supported| Supported|
| closedir | Closes a directory.| Supported| Supported|
| rmdir | Deletes a directory.| Supported| Supported|


  **Table 3** Partition operations

| API| Description| FATFS | LITTLEFS |
| -------- | -------- | -------- | -------- |
| mount | Mounts a partition.| Supported| Supported|
| umount | Unmounts a partition.| Supported| Supported|
| umount2 | Forcibly unmounts a partition using the **MNT_FORCE** parameter.| Supported| Not supported|
| statfs | Obtains partition information.| Supported| Not supported|

## FAT


### Basic Concepts

File Allocation Table (FAT) is a file system developed for personal computers. It consists of the DOS Boot Record (DBR) region, FAT region, and Data region. Each entry in the FAT region records information about the corresponding cluster in the storage device. The cluster information includes whether the cluster is used, number of the next cluster of the file, whether the file ends with the cluster. The FAT file system supports multiple formats, such as FAT12, FAT16, and FAT32. The numbers 12, 16, and 32 indicate the number of bits per cluster within the FAT, respectively. The FAT file system supports multiple media, especially removable media (such as USB flash drives, SD cards, and removable hard drives). The FAT file system ensures good compatibility between embedded devices and desktop systems (such as Windows and Linux) and facilitates file management.

The OpenHarmony kernel supports FAT12, FAT16, and FAT32 file systems. These file systems require a tiny amount of code to implement, use less resources, support a variety of physical media, and are tailorable and compatible with Windows and Linux systems. They also support identification of multiple devices and partitions. The kernel supports multiple partitions on hard drives and allows creation of the FAT file system on the primary partition and logical partition.


### Development Guidelines


#### Driver Adaptation

The use of the FAT file system requires support from the underlying MultiMediaCard (MMC) drivers. To run FatFS on a board with an MMC storage device, you must:

1. Implement the **disk_status**, **disk_initialize**, **disk_read**, **disk_write**, and **disk_ioctl** APIs to adapt to the embedded MMC (eMMC) drivers on the board.

2. Add the **fs_config.h** file with information such as **FS_MAX_SS** (maximum sector size of the storage device) and **FF_VOLUME_STRS** (partition names) configured. The following is an example:


```
#define FF_VOLUME_STRS     "system", "inner", "update", "user"
#define FS_MAX_SS          512
#define FAT_MAX_OPEN_FILES 50
```


#### How to Develop

Note the following when managing FatFS files and directories:

- A file cannot exceed 4 GB.

- **FAT_MAX_OPEN_FILES** specifies the maximum number files you can open at a time, and **FAT_MAX_OPEN_DIRS** specifies the maximum number of folders you can open at a time.
- Root directory management is not supported. File and directory names start with the partition name. For example, **user/testfile** indicates the file or directory **testfile** in the **user** partition.
- To open a file multiple times, use **O_RDONLY** (read-only mode).  **O_RDWR** or **O_WRONLY** (writable mode) can open a file only once.
- The read and write pointers are not separated. If a file is open in **O_APPEND** mode, the read pointer is also at the end of the file. If you want to read the file from the beginning, you must manually set the position of the read pointer.
- File and directory permission management is not supported.
- The **stat** and **fstat** APIs do not support query of the modification time, creation time, and last access time. The Microsoft FAT protocol does not support time before A.D. 1980.

Note the following when mounting and unmounting FatFS partitions:
- Partitions can be mounted with the read-only attribute. When the input parameter of the **mount** function is **MS_RDONLY**, all APIs with the write attribute, such as **write**, **mkdir**, **unlink**, and **open** with **non-O_RDONLY** attributes, will be rejected.
- You can use the **MS_REMOUNT** flag with **mount** to modify the permission for a mounted partition.
- Before unmounting a partition, ensure that all directories and files in the partition are closed.
- You can use **umount2** with the **MNT_FORCE** parameter to forcibly close all files and folders and unmount the partition. However, this may cause data loss. Therefore, exercise caution when running **umount2**.

The FAT file system supports re-partitioning and formatting of storage devices using **fatfs_fdisk** and **fatfs_format**.
- If a partition is mounted before being formatted using **fatfs_format**, you must close all directories and files in the partition and unmount the partition first.
- Before calling **fatfs_fdisk**, ensure that all partitions in the device are unmounted.
- Using **fatfs_fdisk** and **fatfs_format** may cause data loss. Exercise caution when using them.


### Development Example


#### Example Description

This example implements the following:

1. Create the **user/test** directory.

2. Create the **file.txt** file in the **user/test** directory.

3. Write **Hello OpenHarmony!** at the beginning of the file.

4. Save the file to a device.

5. Set the offset to the start position of the file.

6. Reads the file content.

7. Close the file.

8. Delete the file.

9. Delete the directory.


#### Sample Code

 **Prerequisites**

  The MMC device partition is mounted to the **user** directory.

 The sample code is as follows:

  ```
  #include <stdio.h>
  #include <string.h>
  #include "sys/stat.h"
  #include "fcntl.h"
  #include "unistd.h"

  #define LOS_OK 0
  #define LOS_NOK -1

  int FatfsTest(void) 
  {     
    int ret;
    int fd = -1;
    ssize_t len;
    off_t off;
    char dirName[20] = "user/test";
    char fileName[20] = "user/test/file.txt";
    char writeBuf[20] = "Hello OpenHarmony!";
    char readBuf[20] = {0};

    /* Create the user/test directory. */
    ret = mkdir(dirName, 0777);
    if (ret != LOS_OK) {
        printf("mkdir failed.\n");
        return LOS_NOK;
    }

    /* Create a readable and writable file named file.txt in the user/test/ directory. */
    fd = open(fileName, O_RDWR | O_CREAT, 0777);
    if (fd < 0) {
        printf("open file failed.\n");
        return LOS_NOK;
    }

    /* Write the content from writeBuf to the file. */
    len = write(fd, writeBuf, strlen(writeBuf));
    if (len != strlen(writeBuf)) {
        printf("write file failed.\n");
        return LOS_NOK;
    }

    /* Save the file to a storage device. */
    ret = fsync(fd);
    if (ret != LOS_OK) {
        printf("fsync failed.\n");
        return LOS_NOK;
    }

    /* Move the read/write pointer to the beginning of the file. */
    off = lseek(fd, 0, SEEK_SET);
    if (off != 0) {
        printf("lseek failed.\n");
        return LOS_NOK;
    }

    /* Read the file content with the length of readBuf to readBuf. */
    len = read(fd, readBuf, sizeof(readBuf));
    if (len != strlen(writeBuf)) {
        printf("read file failed.\n");
        return LOS_NOK;
    }
    printf("%s\n", readBuf);

    /* Close the file. */
    ret = close(fd);
    if (ret != LOS_OK) {
        printf("close failed.\n");
        return LOS_NOK;
    }

    /* Delete file.txt from the user/test directory. */
    ret = unlink(fileName);
    if (ret != LOS_OK) {
        printf("unlink failed.\n");
        return LOS_NOK;
    }

    /* Delete the user/test directory. */
    ret = rmdir(dirName);
    if (ret != LOS_OK) {
        printf("rmdir failed.\n");
        return LOS_NOK;
    }

    return LOS_OK;
    }
  ```


#### Verification

The development is successful if the return result is as follows:


```
Hello OpenHarmony!
```
## LittleFS


### Basic Concepts

LittleFS is a small file system designed for flash. By combining the log-structured file system and the copy-on-write (COW) file system, LittleFS stores metadata in log structure and data in the COW structure. This special storage empowers LittleFS high power-loss resilience. LittleFS uses the statistical wear leveling algorithm when allocating COW data blocks, effectively prolonging the service life of flash devices. LittleFS is designed for small-sized devices with limited resources, such as ROM and RAM. All RAM resources are allocated through a buffer with the fixed size (configurable). That is, the RAM usage does not grow with the file system.

LittleFS is a good choice when you look for a flash file system that is power-cut resilient and has wear leveling support on a small device with limited resources.


### Development Guidelines

Before porting LittleFS to a new hardware device, you need to declare **lfs_config**:


```
const struct lfs_config cfg = {
    // block device operations
    .read  = user_provided_block_device_read,
    .prog  = user_provided_block_device_prog,
    .erase = user_provided_block_device_erase,
    .sync  = user_provided_block_device_sync,

    // block device configuration
    .read_size = 16,
    .prog_size = 16,
    .block_size = 4096,
    .block_count = 128,
    .cache_size = 16,
    .lookahead_size = 16,
    .block_cycles = 500,
};
```

**.read**, **.prog**, **.erase**, and **.sync** correspond to the read, write, erase, and synchronization APIs at the bottom layer of the hardware platform, respectively.

**read_size** indicates the number of bytes read each time. You can set it to a value greater than the physical read unit to improve performance. This value determines the size of the read cache. However, if the value is too large, more memory is consumed.

**prog_size** indicates the number of bytes written each time. You can set it to a value greater than the physical write unit to improve performance. This value determines the size of the write cache and must be an integral multiple of **read_size**. However, if the value is too large, more memory is consumed.

**block_size**: indicates the number of bytes in each erase block. The value can be greater than that of the physical erase unit. However, a smaller value is recommended because each file occupies at least one block. The value must be an integral multiple of **prog_size**.

**block_count** indicates the number of blocks that can be erased, which depends on the capacity of the block device and the size of the block to be erased (**block_size**).


### Sample Code

  The sample code is as follows:

```
#include "lfs.h"
#include "stdio.h"
lfs_t lfs;
lfs_file_t file;
const struct lfs_config cfg = {
    // block device operations
    .read  = user_provided_block_device_read,
    .prog  = user_provided_block_device_prog,
    .erase = user_provided_block_device_erase,
    .sync  = user_provided_block_device_sync,
    // block device configuration
    .read_size = 16,
    .prog_size = 16,
    .block_size = 4096,
    .block_count = 128,
    .cache_size = 16,
    .lookahead_size = 16,
    .block_cycles = 500,
};
int main(void) {
    // mount the filesystem
    int err = lfs_mount(&lfs, &cfg);
    // reformat if we can't mount the filesystem
    // this should only happen on the first boot
    if (err) {
        lfs_format(&lfs, &cfg);
        lfs_mount(&lfs, &cfg);
    }
    // read current count
    uint32_t boot_count = 0;
    lfs_file_open(&lfs, &file, "boot_count", LFS_O_RDWR | LFS_O_CREAT);
    lfs_file_read(&lfs, &file, &boot_count, sizeof(boot_count));
    // update boot count
    boot_count += 1;
    lfs_file_rewind(&lfs, &file);
    lfs_file_write(&lfs, &file, &boot_count, sizeof(boot_count));
    // remember the storage is not updated until the file is closed successfully
    lfs_file_close(&lfs, &file);
    // release any resources we were using
    lfs_unmount(&lfs);
    // print the boot count
    printf("boot_count: %d\n", boot_count);
}
```


 **Verification**

The development is successful if the return result is as follows:


```
Say hello 1 times.
```
