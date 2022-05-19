# FAT

## Basic Concepts

File Allocation Table \(FAT\) is a file system developed for personal computers. It consists of the DOS Boot Record \(DBR\) region, FAT region, and Data region. Each entry in the FAT region records information about the corresponding cluster in the storage device. The cluster information includes whether the cluster is used, number of the next cluster of the file, whether the file ends with the cluster. The FAT file system supports multiple formats, such as FAT12, FAT16, and FAT32. The numbers 12, 16, and 32 indicate the number of bits per cluster within the FAT, respectively. The FAT file system supports multiple media, especially removable media \(such as USB flash drives, SD cards, and removable hard drives\). The FAT file system ensures good compatibility between embedded devices and desktop systems \(such as Windows and Linux\) and facilitates file management.

The OpenHarmony kernel supports FAT12, FAT16, and FAT32 file systems. These file systems require a tiny amount of code to implement, use less resources, support a variety of physical media, and are tailorable and compatible with Windows and Linux systems. They also support identification of multiple devices and partitions. The kernel supports multiple partitions on hard drives and allows creation of the FAT file system on the primary partition and logical partition.

## Development Guidelines

### Adaptation of Drivers

The use of the FAT file system requires support from the underlying MultiMediaCard \(MMC\) drivers. To run FatFS on a board with an MMC storage device, you must:

1. Implement the **disk\_status**, **disk\_initialize**, **disk\_read**, **disk\_write**, and **disk\_ioctl** APIs to adapt to the embedded MMC \(eMMC\) drivers on the board.

2. Add the **fs\_config.h** file with information such as **FS\_MAX\_SS** \(maximum sector size of the storage device\) and **FF\_VOLUME\_STRS** \(partition names\) configured. The following is an example:

```
#define FF_VOLUME_STRS     "system", "inner", "update", "user"
#define FS_MAX_SS          512
#define FAT_MAX_OPEN_FILES 50
```

### How to Develop

>![](../public_sys-resources/icon-note.gif) **NOTE**<br/> 
>-   Note the following when managing FatFS files and directories:
>    -   A file cannot exceed 4 GB.
>    -   **FAT\_MAX\_OPEN\_FILES** specifies the maximum number files you can open at a time, and **FAT\_MAX\_OPEN\_DIRS** specifies the maximum number of folders you can open at a time.
>    -   Root directory management is not supported. File and directory names start with the partition name. For example, **user/testfile** indicates the file or directory **testfile** in the **user** partition.
>    -   To open a file multiple times, use **O\_RDONLY** \(read-only mode\). **O\_RDWR** or **O\_WRONLY** \(writable mode\) can open a file only once.
>    -   The read and write pointers are not separated. If a file is open in **O\_APPEND** mode, the read pointer is also at the end of the file. If you want to read the file from the beginning, you must manually set the position of the read pointer.
>    -   File and directory permission management is not supported.
>    -   The **stat** and **fstat** APIs do not support query of the modification time, creation time, and last access time. The Microsoft FAT protocol does not support time before A.D. 1980.
>-   Note the following when mounting and unmounting FatFS partitions:
>    -   Partitions can be mounted with the read-only attribute. When the input parameter of the **mount** function is **MS\_RDONLY**, all APIs with the write attribute, such as **write**, **mkdir**, **unlink**, and **open** with **non-O\_RDONLY** attributes, will be rejected.
>    -   You can use the **MS\_REMOUNT** flag with **mount** to modify the permission for a mounted partition.
>    -   Before unmounting a partition, ensure that all directories and files in the partition are closed.
>    -   You can use **umount2** with the **MNT\_FORCE** parameter to forcibly close all files and folders and unmount the partition. However, this may cause data loss. Therefore, exercise caution when running **umount2**.
>-   The FAT file system supports re-partitioning and formatting of storage devices using **fatfs\_fdisk** and **fatfs\_format**.
>    -   If a partition is mounted before being formatted using **fatfs\_format**, you must close all directories and files in the partition and unmount the partition first.
>    -   Before calling **fatfs\_fdisk**, ensure that all partitions in the device are unmounted.
>    -   Using **fatfs\_fdisk** and **fatfs\_format** may cause data loss. Exercise caution when using them.

## Development Example

### Example Description

This example implements the following:

1.  Create the **user/test** directory.
2.  Create the **file.txt** file in the **user/test** directory.
3.  Write "Hello OpenHarmony!" at the beginning of the file.
4.  Save the update of the file to the device.
5.  Set the offset to the beginning of the file.
6.  Read the file.
7.  Close the file.
8.  Delete the file.
9.  Delete the directory.

### Sample Code

Prerequisites

-   The MMC device partition is mounted to the **user** directory.

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

    /* Create the user/test directory.*/
    ret = mkdir(dirName, 0777);
    if (ret != LOS_OK) {
        printf("mkdir failed.\n");
        return LOS_NOK;
    }

    /* Create the file user/test/file.txt and make it readable and writable.*/
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

    /* Save the update of the file to the device.*/
    ret = fsync(fd);
    if (ret != LOS_OK) {
        printf("fsync failed.\n");
        return LOS_NOK;
    }

    /* Move the read/write pointer to the file header. */
    off = lseek(fd, 0, SEEK_SET);
    if (off != 0) {
        printf("lseek failed.\n");
        return LOS_NOK;
    }

    /* Read the file content, with the same size as readBuf, to readBuf.*/
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

    /*Delete the file user/test/file.txt.*/
    ret = unlink(fileName);
    if (ret != LOS_OK) {
        printf("unlink failed.\n");
        return LOS_NOK;
    }

    /*Delete the user/test directory.*/
    ret = rmdir(dirName);
    if (ret != LOS_OK) {
        printf("rmdir failed.\n");
        return LOS_NOK;
    }

    return LOS_OK;
}
```

### Verification

The development is successful if the return result is as follows:

```
Hello OpenHarmony!
```

