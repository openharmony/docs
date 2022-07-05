# FAT


## 基本概念

FAT文件系统是File Allocation Table（文件配置表）的简称，主要包括DBR区、FAT区、DATA区三个区域。其中，FAT区各个表项记录存储设备中对应簇的信息，包括簇是否被使用、文件下一个簇的编号、是否文件结尾等。FAT文件系统有FAT12、FAT16、FAT32等多种格式，其中，12、16、32表示对应格式中FAT表项的比特数，它们同时也限制了文件系统中的最大文件大小。FAT文件系统支持多种介质，特别在可移动存储介质（U盘、SD卡、移动硬盘等）上广泛使用，使嵌入式设备和Windows、Linux等桌面系统保持很好的兼容性，方便用户管理操作文件。

OpenHarmony内核支持FAT12、FAT16与FAT32三种格式的FAT文件系统，具有代码量小、资源占用小、可裁切、支持多种物理介质等特性，并且与Windows、Linux等系统保持兼容，支持多设备、多分区识别等功能。OpenHarmony内核支持硬盘多分区，可以在主分区以及逻辑分区上创建FAT文件系统。


## 运行机制

FAT文件系统设计与物理布局的相关文档在互联网上非常丰富，请开发者自行搜索查看。

OpenHarmony LiteOS-A内核通过Bcache提升FAT文件系统性能，Bcache是block cache的简称。当发生读写时，Bcache会缓存读写扇区附近的扇区，以减少I/O次数，提高性能。Bcache的基本缓存单位为block，每个block大小一致（默认有28个block，每个block缓存64个扇区的数据）。当Bcache脏块率（脏扇区数/总扇区数）达到阈值时，会触发写回；如果脏块率未达到阈值，则不会将缓存数据写回磁盘。如果需要保证数据写回，开发者应当调用sync和fsync触发写回。FAT文件系统的部分接口也会触发写回操作（如close、umount等），但开发者不应当基于这些接口触发写回。


## 开发指导


 **开发流程** 

基本使用流程为挂载→操作→卸载。

SD卡或MMC的设备名为mmcblk[x]p[y]，文件系统类型为“vfat”。

示例：

  
```
mount("/dev/mmcblk0p0", "/mnt", "vfat", 0, NULL);
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - FAT文件系统中，单个文件不能大于4 GiB。
> 
> - 当有两个SD卡插槽时，卡0和卡1不固定，先插上的为卡0，后插上的为卡1。
> 
> - 当多分区功能打开，存在多分区的情况下，卡0注册的设备节点/dev/mmcblk0(主设备)和/dev/mmcblk0p0(次设备)是同一个设备，禁止对主设备进行操作。
> 
> - 为避免SD卡使用异常或内存泄漏，SD卡使用过程中拔卡，用户必须先关闭正处于打开状态的文件和目录，并且卸载挂载节点。
> 
> - 在format操作之前，需要首先umount挂载点。
> 
> - 当Bcache功能生效时，需要注意：
>   - 当mount函数的入参为MS_NOSYNC时，FAT不会主动将cache的内容写回存储器件。FAT的如下接口（open、close、 unlink、rename、mkdir、rmdir、truncate）不会自动进行sync操作，速度可以提升，但是需要上层主动调用sync来进行数据同步，否则可能会数据丢失。
> 
>   - Bcache有定时写回功能。在menuconfig中开启LOSCFG_FS_FAT_CACHE_SYNC_THREAD选项，打开后系统会创建一个任务定时写回Bcache中的数据，默认每隔5秒检查Bcache中脏数据块比例，超过80%时进行sync操作，将Bcache中的脏数据全部写回磁盘。任务优先级、刷新时间间隔以及脏数据块比例的阈值可分别通过接口LOS_SetSyncThreadPrio、 LOS_SetSyncThreadInterval和LOS_SetDirtyRatioThreshold设置。
>   - 当前cache的默认大小为28个块，每个块64个扇区。
