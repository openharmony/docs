# 文件系统


M核的文件系统子系统当前支持的文件系统有FATFS与LittleFS。同A核一样，通过VFS层提供了POSIX标准的操作，保持了接口的一致性，但是因为M核的资源非常紧张，VFS层非常轻薄，没有提供类似A核的高级功能（如pagecache等），主要是接口的标准化和适配工作，具体的事务由各个文件系统实际承载。M核文件系统支持的功能如下表所示：


  **表1** 文件操作

| 接口名 | 描述 | FATFS | LITTLEFS | 
| -------- | -------- | -------- | -------- |
| open | 打开文件 | 支持 | 支持 | 
| close | 关闭文件 | 支持 | 支持 | 
| read | 读取文件内容 | 支持 | 支持 | 
| write | 往文件写入内容 | 支持 | 支持 | 
| lseek | 设置文件偏移位置 | 支持 | 支持 | 
| unlink | 删除文件 | 支持 | 支持 | 
| rename | 重命名文件 | 支持 | 支持 | 
| fstat | 通过文件句柄获取文件信息 | 支持 | 支持 | 
| stat | 通过文件路径名获取文件信息 | 支持 | 支持 | 
| fsync | 文件内容刷入存储设备 | 支持 | 支持 | 


  **表2** 目录操作

| 接口名 | 描述 | FATFS | LITTLEFS | 
| -------- | -------- | -------- | -------- |
| mkdir | 创建目录 | 支持 | 支持 | 
| opendir | 打开目录 | 支持 | 支持 | 
| readdir | 读取目录项内容 | 支持 | 支持 | 
| closedir | 关闭目录 | 支持 | 支持 | 
| rmdir | 删除目录 | 支持 | 支持 | 


  **表3** 分区操作

| 接口名 | 描述 | FATFS | LITTLEFS | 
| -------- | -------- | -------- | -------- |
| mount | 分区挂载 | 支持 | 支持 | 
| umount | 分区卸载 | 支持 | 支持 | 
| umount2 | 分区卸载，可通过MNT_FORCE参数进行强制卸载 | 支持 | 不支持 | 
| statfs | 获取分区信息 | 支持 | 不支持 | 

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
# LittleFS


## 基本概念

LittleFS是一个小型的Flash文件系统，它结合日志结构（log-structured）文件系统和COW（copy-on-write）文件系统的思想，以日志结构存储元数据，以COW结构存储数据。这种特殊的存储方式，使LittleFS具有强大的掉电恢复能力（power-loss resilience)。分配COW数据块时LittleFS采用了名为统计损耗均衡的动态损耗均衡算法，使Flash设备的寿命得到有效保障。同时LittleFS针对资源紧缺的小型设备进行设计，具有极其有限的ROM和RAM占用，并且所有RAM的使用都通过一个可配置的固定大小缓冲区进行分配，不会随文件系统的扩大占据更多的系统资源。

当在一个资源非常紧缺的小型设备上，寻找一个具有掉电恢复能力并支持损耗均衡的Flash文件系统时，LittleFS是一个比较好的选择。


## 开发指导

移植LittleFS到新硬件设备上，需要申明lfs_config：

  
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

其中.read，.prog，.erase，.sync分别对应该硬件平台上的底层的读写\擦除\同步等接口。

read_size 每次读取的字节数，可以比物理读单元大以改善性能，这个数值决定了读缓存的大小，但值太大会带来更多的内存消耗。

prog_size 每次写入的字节数，可以比物理写单元大以改善性能，这个数值决定了写缓存的大小，必须是read_size的整数倍，但值太大会带来更多的内存消耗。

block_size 每个擦除块的字节数，可以比物理擦除单元大，但此数值应尽可能小因为每个文件至少会占用一个块。必须是prog_size的整数倍。

block_count 可以被擦除的块数量，这取决于块设备的容量及擦除块的大小。


## 示例代码

  代码实现如下：
  
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


 **结果验证** 

首次编译运行得到的结果为：

  
```
Say hello 1 times.
```