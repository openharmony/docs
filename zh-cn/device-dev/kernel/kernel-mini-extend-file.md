# 文件系统

## VFS


### 基本概念

**VFS（Virtual File System）** 是文件系统的虚拟层，它不是一个实际的文件系统，而是一个异构文件系统之上的软件粘合层，为用户提供统一的类Unix文件操作接口。由于不同类型的文件系统接口不统一，若系统中有多个文件系统类型，访问不同的文件系统就需要使用不同的非标准接口。而通过在系统中添加VFS层，提供统一的抽象接口，屏蔽了底层异构类型的文件系统的差异，使得访问文件系统的系统调用不用关心底层的存储介质和文件系统类型，提高开发效率。

M核的文件系统子系统当前支持的文件系统有FATFS与LittleFS。通过VFS层提供了POSIX标准的操作，保持了接口的一致性，但是因为M核的资源非常紧张，VFS层非常轻薄，没有提供类似A核的高级功能（如pagecache等），主要是接口的标准化和适配工作，具体的事务由各个文件系统实际承载。M核文件系统支持的功能如下表所示：

### 接口说明

**表1** 文件操作

| 接口名 | 描述 | FATFS | LITTLEFS |
| -------- | -------- | -------- | -------- |
| open | 打开文件 | 支持 | 支持 |
| close | 关闭文件 | 支持 | 支持 |
| read   | 读取文件内容               | 支持  | 支持     |
| write  | 往文件写入内容             | 支持  | 支持     |
| lseek  | 设置文件偏移位置           | 支持  | 支持     |
| stat   | 通过文件路径名获取文件信息 | 支持  | 支持     |
| unlink | 删除文件 | 支持 | 支持 |
| rename | 重命名文件 | 支持 | 支持 |
| fstat  | 通过文件句柄获取文件信息   | 支持  | 支持     |
| fsync  | 文件内容刷入存储设备       | 支持  | 支持     |


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

ioctl，fcntl等接口由不同的lib库支持，与底层文件系统无关。

## FAT


### 基本概念

FAT文件系统是File Allocation Table（文件配置表）的简称，主要包括DBR区、FAT区、DATA区三个区域。其中，FAT区各个表项记录存储设备中对应簇的信息，包括簇是否被使用、文件下一个簇的编号、是否文件结尾等。FAT文件系统有FAT12、FAT16、FAT32等多种格式，其中，12、16、32表示对应格式中FAT表项的比特数。FAT文件系统支持多种介质，特别在可移动存储介质（U盘、SD卡、移动硬盘等）上广泛使用，使嵌入式设备和Windows、Linux等桌面系统保持很好的兼容性，方便用户管理操作文件。

OpenHarmony内核支持FAT12、FAT16与FAT32三种格式的FAT文件系统，具有代码量小、资源占用小、可裁切、支持多种物理介质等特性，并且与Windows、Linux等系统保持兼容，支持多设备、多分区识别等功能。OpenHarmony内核支持硬盘多分区，可以在主分区以及逻辑分区上创建FAT文件系统。


### 开发指导


#### 驱动适配

FAT文件系统的使用需要底层MMC相关驱动的支持。在一个带MMC存储设备的板子上运行FATFS，需要：

1、适配板端EMMC驱动，实现disk_status、disk_initialize、disk_read、disk_write、disk_ioctl接口；

2、新增fs_config.h文件，配置FS_MAX_SS（存储设备最大sector大小）、FF_VOLUME_STRS（分区名）等信息，例如：


```
#define FF_VOLUME_STRS     "system", "inner", "update", "user"
#define FS_MAX_SS          512
#define FAT_MAX_OPEN_FILES 50
```

#### 分区挂载

移植FATFS到新硬件设备上，需要在初始化flash驱动后，完成设备分区。

设备分区接口：int LOS_DiskPartition(const char *dev, const char *fsType, int *lengthArray, int *addrArray, int partNum)；

- dev：设备名称， 如“spinorblk0”
- fsType：文件系统类型，”vfat“
- lengthArray：该设备上各分区的长度列表，fatfs填入百分比即可
- addrArray：该设备上各分区的起始地址列表
- partNum：分区的个数

格式化接口：int LOS_PartitionFormat(const char *partName, char *fsType, void *data)；

- partName：分区名称，设备名称+ ‘p’ + 分区号，如“spinorblk0p0”
- fsType：文件系统类型，”vfat“
- data：私有数据  传入（VOID *）formatType，（如FMT_FAT， FMT_FAT32）

mount接口：int mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data)；

- source：分区名称，设备名称+ ‘p’ + 分区号，如“spinorblk0p0”   
- target：挂载路径
- filesystemtype：文件系统类型，”vfat“
- mountflags：mount配置参数
- data：私有数据，传入（VOID *）formatType，（如FMT_FAT， FMT_FAT32）

本参考代码已在 ./device/qemu/arm_mps2_an386/liteos_m/board/fs/fs_init.c 中实现，M核qemu上可直接使用，请参考并根据实际硬件修改。

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
        HalLogicPartition *halPartitionsInfo = getPartitionInfo(); /* 获取长度和起始地址的函数，请根据实际单板适配 */
        INT32 lengthArray[FF_VOLUMES] = {25, 25, 25, 25};
        INT32 addrArray[FF_VOLUMES];
    
        /* 配置各分区的地址和长度，请根据实际单板适配 */
        for (i = 0; i < FF_VOLUMES; i++) {
            addr = halPartitionsInfo[FLASH_PARTITION_DATA1].partitionStartAddr + i * 0x10000;
            addrArray[i] = addr;
            FlashInfoInit(i, addr);
        }
    
        /* 配置分区信息，请根据实际单板适配 */
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
#### 开发流程

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - FATFS文件与目录操作：
>   - 单个文件大小不超过4G。
>   - 支持同时打开的文件数最大为FAT_MAX_OPEN_FILES，文件夹数最大为FAT_MAX_OPEN_DIRS。
>   - 暂不支持根目录管理，文件/目录名均以分区名开头，例如“user/testfile”就是在“user”分区下名为“testfile”的文件或目录。
>   - 若需要同时多次打开同一文件，必须全部使用只读方式（O_RDONLY）。以可写方式（O_RDWR、O_WRONLY等）只能打开一次。
>   - 读写指针未分离，例如以O_APPEND（追加写）方式打开文件后，读指针也在文件尾，从头读文件前需要用户手动置位。
>   - 暂不支持文件与目录的权限管理。
>   - stat及fstat接口暂不支持查询修改时间、创建时间和最后访问时间。微软FAT协议不支持1980年以前的时间。
> - FATFS分区挂载与卸载：
>   - 支持以只读属性挂载分区。当mount函数的入参为MS_RDONLY时，所有的带有写入的接口，如write、mkdir、unlink，以及非O_RDONLY属性的open，将均被拒绝。
>   - mount支持通过MS_REMOUNT标记修改已挂载分区的权限。
>   - 在umount操作前，需确保所有目录及文件全部关闭。
>   - umount2支持通过MNT_FORCE参数强制关闭所有文件与文件夹并umount，但可能造成数据丢失，请谨慎使用。
> - FATFS支持重新划分存储设备分区、格式化分区，对应接口为fatfs_fdisk与fatfs_format：
>   - 在fatfs_format操作之前，若需要格式化的分区已挂载，需确保分区中的所有目录及文件全部关闭，并且分区umount。
>   - 在fatfs_fdisk操作前，需要该设备中的所有分区均已umount。
>   - fatfs_fdisk与fatfs_format会造成设备数据丢失，请谨慎使用。


### 编程实例


#### 实例描述

本实例实现以下功能：

1. 创建目录“system/test”

2. 在“system/test”目录下创建文件“file.txt”

3. 在文件起始位置写入“Hello OpenHarmony!”

4. 将文件内容刷入设备中

5. 设置偏移到文件起始位置

6. 读取文件内容

7. 关闭文件

8. 删除文件

9. 删除目录


#### 示例代码

 **前提条件：** 

 系统已将设备分区挂载到目录，qemu默认已挂载system。

 在kernel/liteos_m目录下执行 make menuconfig 命令配置"FileSystem->Enable FS VFS"开启FS功能；

 开启FS后出现新选项“Enable FAT”开启FAT。

 **代码实现如下：** 

本演示代码在 ./kernel/liteos_m/testsuites/src/osTest.c 中编译验证，在TestTaskEntry中调用验证入口函数ExampleFatfs。

  ```
#include <stdio.h>
#include <string.h>
#include "sys/stat.h"
#include "fcntl.h"
#include "unistd.h"

#define BUF_SIZE 20
#define TEST_ROOT "system"  /* 测试的根目录请根据实际情况调整 */
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

    /* 创建测试目录 */
    ret = mkdir(dirName, 0777);
    if (ret != LOS_OK) {
        printf("mkdir failed.\n");
        return;
    }

    /* 创建可读写测试文件 */
    fd = open(fileName, O_RDWR | O_CREAT, 0777);
    if (fd < 0) {
        printf("open file failed.\n");
        return;
    }

    /* 将writeBuf中的内容写入文件 */
    len = write(fd, writeBuf, strlen(writeBuf));
    if (len != strlen(writeBuf)) {
        printf("write file failed.\n");
        return;
    }

    /* 将文件内容刷入存储设备中 */
    ret = fsync(fd);
    if (ret != LOS_OK) {
        printf("fsync failed.\n");
        return;
    }

    /* 将读写指针偏移至文件头 */
    off = lseek(fd, 0, SEEK_SET);
    if (off != 0) {
        printf("lseek failed.\n");
        return;
    }

    /* 将文件内容读出至readBuf中，读取长度为readBuf大小 */
    len = read(fd, readBuf, sizeof(readBuf));
    if (len != strlen(writeBuf)) {
        printf("read file failed.\n");
        return;
    }
    printf("%s\n", readBuf);

    /* 关闭测试文件 */
    ret = close(fd);
    if (ret != LOS_OK) {
        printf("close failed.\n");
        return;
    }

    /* 删除测试文件 */
    ret = unlink(fileName);
    if (ret != LOS_OK) {
        printf("unlink failed.\n");
        return;
    }

    /* 删除测试目录 */
    ret = rmdir(dirName);
    if (ret != LOS_OK) {
        printf("rmdir failed.\n");
        return;
    }

    return;
}
  ```


#### 结果验证

编译运行得到的结果为：


```
Hello OpenHarmony!
```
## LittleFS


### 基本概念

LittleFS是一个小型的Flash文件系统，它结合日志结构（log-structured）文件系统和COW（copy-on-write）文件系统的思想，以日志结构存储元数据，以COW结构存储数据。这种特殊的存储方式，使LittleFS具有强大的掉电恢复能力（power-loss resilience)。分配COW数据块时LittleFS采用了名为统计损耗均衡的动态损耗均衡算法，使Flash设备的寿命得到有效保障。同时LittleFS针对资源紧缺的小型设备进行设计，具有极其有限的ROM和RAM占用，并且所有RAM的使用都通过一个可配置的固定大小缓冲区进行分配，不会随文件系统的扩大占据更多的系统资源。

当在一个资源非常紧缺的小型设备上，寻找一个具有掉电恢复能力并支持损耗均衡的Flash文件系统时，LittleFS是一个比较好的选择。


### 开发指导

移植LittleFS到新硬件设备上，需要在初始化flash驱动后，完成设备分区。

设备分区接口：int LOS_DiskPartition(const char *dev, const char *fsType, int *lengthArray, int *addrArray, int partNum)；

- dev：设备名称
- fsType：文件系统类型， "littlefs"
- lengthArray：该设备上各分区的长度列表
- addrArray：该设备上各分区的起始地址列表
- partNum：分区的个数

格式化接口：int LOS_PartitionFormat(const char *partName, char *fsType, void *data)；

- partName：分区名称
- fsType：文件系统类型， "littlefs"
- data：私有数据  传入（VOID *）struct fs_cfg

mount接口：int mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data)；

- source：分区名称
- target：挂载路径
- filesystemtype：文件系统类型，"littlefs"
- mountflags：mount配置参数
- data：私有数据，传入（VOID *）struct fs_cfg

本参考代码已在 ./device/qemu/arm_mps2_an386/liteos_m/board/fs/fs_init.c 中实现，M核qemu上可直接使用，请参考并根据实际硬件修改。


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
    HalLogicPartition *halPartitionsInfo = getPartitionInfo();  /* 获取长度和起始地址的函数，请根据实际单板适配 */

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
    fs[0].partCfg.readFunc = virt_flash_read;		/* flash读函数，请根据实际单板适配 */
    fs[0].partCfg.writeFunc = virt_flash_write;		/* flash写函数，请根据实际单板适配 */
    fs[0].partCfg.eraseFunc = virt_flash_erase;		/* flash擦函数，请根据实际单板适配 */

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

其中.readFunc，.writeFunc，.eraseFunc分别对应该硬件平台上的底层的读写\擦除等接口。

readSize 每次读取的字节数，可以比物理读单元大以改善性能，这个数值决定了读缓存的大小，但值太大会带来更多的内存消耗。

writeSize 每次写入的字节数，可以比物理写单元大以改善性能，这个数值决定了写缓存的大小，必须是readSize的整数倍，但值太大会带来更多的内存消耗。

blockSize 每个擦除块的字节数，可以比物理擦除单元大，但此数值应尽可能小因为每个文件至少会占用一个块。必须是writeSize的整数倍。

blockCount 可以被擦除的块数量，这取决于块设备的容量及擦除块的大小。


### 示例代码

 **前提条件：** 

系统已将设备分区挂载到目录，qemu默认已挂载/littlefs。

在kernel/liteos_m目录下执行 make menuconfig 命令配置"FileSystem->Enable FS VFS"开启FS功能；

开启FS后出现新选项“Enable Little FS”开启littlefs。

代码实现如下：

本演示代码在 ./kernel/liteos_m/testsuites/src/osTest.c 中编译验证，在TestTaskEntry中调用验证入口函数ExampleLittlefs。

```
#include <stdio.h>
#include <string.h>
#include "sys/stat.h"
#include "fcntl.h"
#include "unistd.h"

#define BUF_SIZE 20
#define TEST_ROOT "/littlefs"  /* 测试的根目录请根据实际情况调整 */
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

    /* 创建测试目录 */
    ret = mkdir(dirName, 0777);
    if (ret != LOS_OK) {
        printf("mkdir failed.\n");
        return;
    }

    /* 创建可读写测试文件 */
    fd = open(fileName, O_RDWR | O_CREAT, 0777);
    if (fd < 0) {
        printf("open file failed.\n");
        return;
    }

    /* 将writeBuf中的内容写入文件 */
    len = write(fd, writeBuf, strlen(writeBuf));
    if (len != strlen(writeBuf)) {
        printf("write file failed.\n");
        return;
    }

    /* 将文件内容刷入存储设备中 */
    ret = fsync(fd);
    if (ret != LOS_OK) {
        printf("fsync failed.\n");
        return;
    }

    /* 将读写指针偏移至文件头 */
    off = lseek(fd, 0, SEEK_SET);
    if (off != 0) {
        printf("lseek failed.\n");
        return;
    }

    /* 将文件内容读出至readBuf中，读取长度为readBuf大小 */
    len = read(fd, readBuf, sizeof(readBuf));
    if (len != strlen(writeBuf)) {
        printf("read file failed.\n");
        return;
    }
    printf("%s\n", readBuf);

    /* 关闭测试文件 */
    ret = close(fd);
    if (ret != LOS_OK) {
        printf("close failed.\n");
        return;
    }

    /* 删除测试文件 */
    ret = unlink(fileName);
    if (ret != LOS_OK) {
        printf("unlink failed.\n");
        return;
    }

    /* 删除测试目录 */
    ret = rmdir(dirName);
    if (ret != LOS_OK) {
        printf("rmdir failed.\n");
        return;
    }

    return LOS_OK;
}
```


 **结果验证** 

首次编译运行得到的结果为：


```
Hello OpenHarmony!
```