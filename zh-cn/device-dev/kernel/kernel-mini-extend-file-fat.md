# FAT


## 基本概念

FAT文件系统是File Allocation Table（文件配置表）的简称，主要包括DBR区、FAT区、DATA区三个区域。其中，FAT区各个表项记录存储设备中对应簇的信息，包括簇是否被使用、文件下一个簇的编号、是否文件结尾等。FAT文件系统有FAT12、FAT16、FAT32等多种格式，其中，12、16、32表示对应格式中FAT表项的比特数。FAT文件系统支持多种介质，特别在可移动存储介质（U盘、SD卡、移动硬盘等）上广泛使用，使嵌入式设备和Windows、Linux等桌面系统保持很好的兼容性，方便用户管理操作文件。

OpenHarmony内核支持FAT12、FAT16与FAT32三种格式的FAT文件系统，具有代码量小、资源占用小、可裁切、支持多种物理介质等特性，并且与Windows、Linux等系统保持兼容，支持多设备、多分区识别等功能。OpenHarmony内核支持硬盘多分区，可以在主分区以及逻辑分区上创建FAT文件系统。


## 开发指导


### 驱动适配

FAT文件系统的使用需要底层MMC相关驱动的支持。在一个带MMC存储设备的板子上运行FATFS，需要：

1、适配板端EMMC驱动，实现disk_status、disk_initialize、disk_read、disk_write、disk_ioctl接口；

2、新增fs_config.h文件，配置FS_MAX_SS（存储设备最大sector大小）、FF_VOLUME_STRS（分区名）等信息，例如：

  
```
#define FF_VOLUME_STRS     "system", "inner", "update", "user"
#define FS_MAX_SS          512
#define FAT_MAX_OPEN_FILES 50
```


### 开发流程

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - FATFS文件与目录操作：
>   - 单个文件大小不超过4G。
>   - 支持同时打开的文件数最大为FAT_MAX_OPEN_FILES，文件夹数最大为FAT_MAX_OPEN_DIRS。
>   - 暂不支持根目录管理，文件/目录名均以分区名开头，例如“user/testfile”就是在“user”分区下名为“testfile”的文件或目录。
>   - 若需要同时多次打开同一文件，必须全部使用只读方式（O_RDONLY）。以可写方式（O_RDWR、O_WRONLY等）只能打开一次。
>   - 读写指针未分离，例如以O_APPEND（追加写）方式打开文件后，读指针也在文件尾，从头读文件前需要用户手动置位。
>   - 暂不支持文件与目录的权限管理。
>   - stat及fstat接口暂不支持查询修改时间、创建时间和最后访问时间。微软FAT协议不支持1980年以前的时间。
> 
> - FATFS分区挂载与卸载：
>   - 支持以只读属性挂载分区。当mount函数的入参为MS_RDONLY时，所有的带有写入的接口，如write、mkdir、unlink，以及非O_RDONLY属性的open，将均被拒绝。
>   - mount支持通过MS_REMOUNT标记修改已挂载分区的权限。
>   - 在umount操作前，需确保所有目录及文件全部关闭。
>   - umount2支持通过MNT_FORCE参数强制关闭所有文件与文件夹并umount，但可能造成数据丢失，请谨慎使用。
> 
> - FATFS支持重新划分存储设备分区、格式化分区，对应接口为fatfs_fdisk与fatfs_format：
>   - 在fatfs_format操作之前，若需要格式化的分区已挂载，需确保分区中的所有目录及文件全部关闭，并且分区umount。
>   - 在fatfs_fdisk操作前，需要该设备中的所有分区均已umount。
>   - fatfs_fdisk与fatfs_format会造成设备数据丢失，请谨慎使用。


## 编程实例


### 实例描述

本实例实现以下功能：

1. 创建目录“user/test”

2. 在“user/test”目录下创建文件“file.txt”

3. 在文件起始位置写入“Hello OpenHarmony!”

4. 将文件内容刷入设备中

5. 设置偏移到文件起始位置

6. 读取文件内容

7. 关闭文件

8. 删除文件

9. 删除目录


### 示例代码

 **前提条件：** 

 系统已将MMC设备分区挂载到user目录

 **代码实现如下：** 
  
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

    /* 创建目录“user/test” */
    ret = mkdir(dirName, 0777);
    if (ret != LOS_OK) {
        printf("mkdir failed.\n");
        return LOS_NOK;
    }

    /* 创建可读写文件"user/test/file.txt" */
    fd = open(fileName, O_RDWR | O_CREAT, 0777);
    if (fd < 0) {
        printf("open file failed.\n");
        return LOS_NOK;
    }

    /* 将writeBuf中的内容写入文件 */
    len = write(fd, writeBuf, strlen(writeBuf));
    if (len != strlen(writeBuf)) {
        printf("write file failed.\n");
        return LOS_NOK;
    }

    /* 将文件内容刷入存储设备中 */
    ret = fsync(fd);
    if (ret != LOS_OK) {
        printf("fsync failed.\n");
        return LOS_NOK;
    }

    /* 将读写指针偏移至文件头 */
    off = lseek(fd, 0, SEEK_SET);
    if (off != 0) {
        printf("lseek failed.\n");
        return LOS_NOK;
    }

    /* 将文件内容读出至readBuf中，读取长度为readBuf大小 */
    len = read(fd, readBuf, sizeof(readBuf));
    if (len != strlen(writeBuf)) {
        printf("read file failed.\n");
        return LOS_NOK;
    }
    printf("%s\n", readBuf);

    /* 关闭文件 */
    ret = close(fd);
    if (ret != LOS_OK) {
        printf("close failed.\n");
        return LOS_NOK;
    }

    /* 删除文件"user/test/file.txt" */
    ret = unlink(fileName);
    if (ret != LOS_OK) {
        printf("unlink failed.\n");
        return LOS_NOK;
    }

    /* 删除目录“user/test” */
    ret = rmdir(dirName);
    if (ret != LOS_OK) {
        printf("rmdir failed.\n");
        return LOS_NOK;
    }

    return LOS_OK;
    }
  ```


### 结果验证

编译运行得到的结果为：

  
```
Hello OpenHarmony!
```
