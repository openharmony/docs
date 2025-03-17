# 支持的文件系统

## FAT

### 基本概念

FAT文件系统是File Allocation Table（文件配置表）的简称，主要包括DBR区、FAT区、DATA区三个区域。其中，FAT区各个表项记录存储设备中对应簇的信息，包括簇是否被使用、文件下一个簇的编号、是否文件结尾等。FAT文件系统有FAT12、FAT16、FAT32等多种格式，其中，12、16、32表示对应格式中FAT表项的比特数，它们同时也限制了文件系统中的最大文件大小。FAT文件系统支持多种介质，特别在可移动存储介质（U盘、SD卡、移动硬盘等）上广泛使用，使嵌入式设备和Windows、Linux等桌面系统保持很好的兼容性，方便用户管理操作文件。

OpenHarmony内核支持FAT12、FAT16与FAT32三种格式的FAT文件系统，具有代码量小、资源占用小、可裁切、支持多种物理介质等特性，并且与Windows、Linux等系统保持兼容，支持多设备、多分区识别等功能。OpenHarmony内核支持硬盘多分区，可以在主分区以及逻辑分区上创建FAT文件系统。

### 运行机制

FAT文件系统设计与物理布局的相关文档在互联网上非常丰富，请开发者自行搜索查看。

OpenHarmony LiteOS-A内核通过Bcache提升FAT文件系统性能，Bcache是block cache的简称。当发生读写时，Bcache会缓存读写扇区附近的扇区，以减少I/O次数，提高性能。Bcache的基本缓存单位为block，每个block大小一致（默认有28个block，每个block缓存64个扇区的数据）。当Bcache脏块率（脏扇区数/总扇区数）达到阈值时，会触发写回；如果脏块率未达到阈值，则不会将缓存数据写回磁盘。如果需要保证数据写回，开发者应当调用sync和fsync触发写回。FAT文件系统的部分接口也会触发写回操作（如close、umount等），但开发者不应当基于这些接口触发写回。

### 开发指导

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

## JFFS2

### 基本概念

JFFS2是Journalling Flash File System Version 2（日志文件系统）的缩写，是针对MTD设备的日志型文件系统。

OpenHarmony内核的JFFS2主要应用于NOR FLASH闪存，其特点是：可读写、支持数据压缩、提供了崩溃/掉电安全保护、提供“写平衡”支持等。闪存与磁盘介质有许多差异，直接将磁盘文件系统运行在闪存设备上，会导致性能和安全问题。为解决这一问题，需要实现一个特别针对闪存的文件系统，JFFS2就是这样一种文件系统。

### 运行机制

关于JFFS2文件系统的在存储设备上的实际物理布局，及文件系统本身的规格说明，请参考JFFS2的[官方规格说明文档](https://sourceware.org/jffs2/)。

这里仅列举几个对开发者和使用者会有一定影响的JFFS2的重要机制/特征：

1. Mount机制及速度问题：按照JFFS2的设计，所有的文件会按照一定的规则，切分成大小不等的节点，依次存储到flash设备上。在mount流程中，需要获取到所有的这些节点信息并缓存到内存里。因此，mount速度和flash设备的大小和文件数量的多少成线性比例关系。这是JFFS2的原生设计问题，对于mount速度非常介意的用户，可以在内核编译时开启“Enable JFFS2 SUMMARY”选项，可以极大提升mount的速度。这个选项的原理是将mount需要的信息提前存储到flash上，在mount时读取并解析这块内容，使得mount的速度变得相对恒定。这个实际是空间换时间的做法，会消耗8%左右的额外空间。

2. 写平衡的支持：由于flash设备的物理属性，读写都只能基于某个特定大小的“块”进行，为了防止某些特定的块磨损过于严重，在JFFS2中需要对写入的块进行“平衡”的管理，保证所有的块的写入次数都是相对平均的，进而保证flash设备的整体寿命。

3. GC(garbage collection)机制：在JFFS2里发生删除动作，实际的物理空间并不会立即释放，而是由独立的GC线程来做空间整理和搬移等GC动作，和所有的GC机制一样，在JFFS2里的GC会对瞬时的读写性能有一定影响。另外，为了有空间能被用来做空间整理，JFFS2会对每个分区预留3块左右的空间，这个空间是用户不可见的。

4. 压缩机制：当前使用的JFFS2，底层会自动的在每次读/写时进行解压/压缩动作，实际IO的大小和用户请求读写的大小并不会一样。特别在写入时，不能通过写入大小来和flash剩余空间的大小来预估写入一定会成功或者失败。

5. 硬链接机制：JFFS2支持硬链接，底层实际占用的物理空间是一份，对于同一个文件的多个硬连接，并不会增加空间的占用；反之，只有当删除了所有的硬链接时，实际物理空间才会被释放。

### 开发指导

对于基于JFFS2和nor flash的开发，总体而言，与其他文件系统非常相似，因为都有VFS层来屏蔽了具体文件系统的差异，对外接口体现也都是标准的POSIX接口。

对于整个裸nor flash设备而言，没有集中的地方来管理和记录分区的信息。因此，需要通过其他的配置方式来传递这部分信息（当前使用的方式是在烧写镜像的时候，使用bootargs参数配置的），然后在代码中调用相应的接口来添加分区，再进行挂载动作。

**制作JFFS2文件系统镜像**

使用mkfs.jffs2工具，制作镜像默认命令如下。页大小默认为4KiB，eraseblock大小默认64KiB。若实际参数与下面不同时，修改相应参数。
  
```
./mkfs.jffs2 -d rootfs/ -o rootfs.jffs2
```

  **表1** 指令含义表（更详细的介绍可以通过mkfs.jffs2 --help来查看）

| 指令 | 含义 | 
| -------- | -------- |
| -s | 页大小，不指定默认为4KiB。 | 
| -e | eraseblock大小，不指定默认为64KiB。 | 
| -p | 镜像大小。在镜像文件后面，用0xFF填充至指定大小，不指定则用0xFF填充至eraseblock对齐。 | 
| -d | 要制作成文件系统镜像的源目录。 | 
| -o | 要制成的镜像名称。 | 

**挂载JFFS2分区**

调用int mount(const char \*source, const char \*target, const char \*filesystemtype, unsigned long mountflags, const void \*data)函数实现设备节点和挂载点的挂载。

该函数有五个参数，第一个参数const char \*source,表示设备节点，第二个参数const char \*target表示挂载点。第三个参数 const char \*filesystemtype,表示文件系统类型。

最后两个参数unsigned long mountflags和const void \*data表示挂载标志和数据，默认为0和NULL；这一操作也可以在Shell中使用mount命令实现，最后两个参数不需要用户给出。

运行命令：
  
```
OHOS # mount /dev/spinorblk1 /jffs1 jffs2
```

将从串口得到如下回应信息，表明挂载成功。
  
```
OHOS # mount /dev/spinorblk1 /jffs1 jffs2
mount OK
```

挂载成功后，用户就能对norflash进行读写操作。

**卸载JFFS2分区**

调用int umount(const char \*target)函数卸载分区，只需要正确给出挂载点即可。

运行命令：
  
```
OHOS # umount /jffs1
```

将从串口得到如下回应信息，表明卸载成功。
  
```
OHOS # umount /jffs1
umount ok
```
## NFS

### 基本概念

NFS是Network File System（网络文件系统）的缩写。它最大的功能是可以通过网络，让不同的机器、不同的操作系统彼此分享其他用户的文件。因此，用户可以简单地将它看做是一个文件系统服务，在一定程度上相当于Windows环境下的共享文件夹。

### 运行机制

OpenHarmony LiteOS-A内核的NFS文件系统指的是NFS的客户端，NFS客户端能够将远程的NFS服务端分享的目录挂载到本地的机器中，运行程序和共享文件，但不占用当前系统的存储空间，在本地端的机器看起来，远程服务端的目录就好像是自己的一个磁盘一样。

### 开发指导

1. 搭建NFS服务器

   这里以Ubuntu操作系统为例，说明服务器端设置步骤。

   - 安装NFS服务器软件。

     设置好Ubuntu系统的下载源，保证网络连接好的情况下执行：


     ```
     sudo apt-get install nfs-kernel-server
     ```

   - 创建用于挂载的目录并设置完全权限。

  
     ```
     mkdir -p /home/sqbin/nfs
     sudo chmod 777 /home/sqbin/nfs
     ```

   - 设置和启动NFS server。

     修改NFS配置文件/etc/exports，添加如下一行：


     ```
     /home/sqbin/nfs *(rw,no_root_squash,async)
     ```

     其中/home/sqbin/nfs是NFS共享的根目录。

     执行以下命令启动NFS server：


     ```
     sudo /etc/init.d/nfs-kernel-server start
     ```

     执行以下命令重启NFS server：


     ```
     sudo /etc/init.d/nfs-kernel-server restart
     ```

2. 设置单板为NFS客户端。

   本指导中的NFS客户端指运行OpenHarmony内核的设备。

   - 硬件连接设置。

     OpenHarmony内核设备连接到NFS服务器的网络。设置两者IP，使其处于同一网段。比如，设置NFS服务器的IP为10.67.212.178/24，设置OpenHarmony内核设备IP为 
  10.67.212.3/24，注意：此IP为内网私有IP地址，用户使用时有差异，以用户实际IP为准。

     OpenHarmony内核设备上的IP信息可通过ifconfig命令查看。

   - 启动网络，确保单板到NFS服务器之间的网络通畅。

     启动以太网或者其他类型网络，使用ping命令检查到服务器的网络是否通畅。


     ```
     OHOS # ping 10.67.212.178
     [0]Reply from 10.67.212.178: time=1ms TTL=63
     [1]Reply from 10.67.212.178: time=0ms TTL=63
     [2]Reply from 10.67.212.178: time=1ms TTL=63
     [3]Reply from 10.67.212.178: time=1ms TTL=63
     --- 10.67.212.178 ping statistics ---
     packets transmitted, 4 received, 0 loss

   客户端NFS初始化，运行命令：


   ```
   OHOS # mkdir /nfs
   OHOS # mount 10.67.212.178:/home/sqbin/nfs /nfs nfs 1011 1000
   ```

   将从串口得到如下回应信息，表明初始化NFS客户端成功。


   ```
   OHOS # mount 10.67.212.178:/home/sqbin/nfs /nfs nfs 1011 1000
   Mount nfs on 10.67.212.178:/home/sqbin/nfs, uid:1011, gid:1000
   Mount nfs finished.
   ```

   该命令将服务器10.67.212.178上的/home/sqbin/nfs目录挂载到OpenHarmony内核设备上的/nfs上。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 本例默认nfs server已经配置可用，即示例中服务器10.67.212.178上的/home/sqbin/nfs已配置可访问。
   > 
   > mount命令的格式为：
   > 
   > 
   > ```
   > mount <SERVER_IP:SERVER_PATH> <CLIENT_PATH> nfs
   > ```
   > 
   > 其中“SERVER_IP”表示服务器的IP地址；“SERVER_PATH”表示服务器端NFS共享目录路径；“CLIENT_PATH”表示设备上的NFS路径，“nfs”表示客户端要挂载的路径，可以根据自己需要替换。
   > 
   > 如果不想有NFS访问权限限制，可以在Linux命令行将NFS根目录权限设置成777：
   > 
   > 
   > ```
   > chmod -R 777 /home/sqbin/nfs
   > ```
   > 
   > 至此，NFS客户端设置完毕。NFS文件系统已成功挂载。

3. 利用NFS共享文件。

   在NFS服务器下新建目录dir，并保存。在OpenHarmony内核下运行ls命令：

   ```
   OHOS # ls /nfs
   ```

   则可从串口得到如下回应：


   ```
   OHOS # ls /nfs 
   Directory /nfs:                 
   drwxr-xr-x 0        u:0     g:0     dir
   ```

   可见，刚刚在NFS服务器上新建的dir目录已同步到客户端(OpenHarmony内核系统)的/nfs目录，两者保持同步。

   同样地，在客户端(OpenHarmony内核系统)上创建文件和目录，在NFS服务器上也可以访问，读者可自行体验。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 目前，NFS客户端仅支持NFS v3部分规范要求，因此对于规范支持不全的服务器，无法完全兼容。在开发测试过程中，建议使用Linux的NFS server，其对NFS支持很完善。

## Ramfs

### 基本概念

RAMFS是一个可动态调整大小的基于RAM的文件系统。RAMFS没有后备存储源。向RAMFS中进行的文件写操作也会分配目录项和页缓存，但是数据并不写回到任何其他存储介质上，掉电后数据丢失。
### 运行机制
RAMFS文件系统把所有的文件都放在 RAM 中，所以读/写操作发生在RAM中，可以用RAMFS来存储一些临时性或经常要修改的数据，例如/tmp和/var目录，这样既避免了对存储器的读写损耗，也提高了数据读写速度。
### 开发指导
挂载：  
```
mount(NULL, "/dev/shm", "ramfs", 0, NULL)
```
创建目录：  
```
mkdir(pathname, mode)
```
创建文件： 
```
open(pathname, O_NONBLOCK | O_CREAT | O_RDWR, mode)
```
读取目录：  
```
dir = opendir(pathname) 
ptr = readdir(dir)
closedir(dir)
```
删除文件：  
```
unlink(pathname)
```
删除目录： 
```
rmdir(pathname)
```
去挂载：  
```
umount("/dev/shm")
```
> ![icon-caution.gif](public_sys-resources/icon-caution.gif) **注意：**
> - RAMFS只能挂载一次，一次挂载成功后，后面不能继续挂载到其他目录。
> 
> - RAMFS属于调测功能，默认配置为关闭，正式产品中不要使用该功能。

## Procfs


### 基本概念

procfs是进程文件系统的简称，是一种虚拟文件系统，他用文件的形式，展示进程或其他系统信息。相比调用接口的方式获取信息，以文件操作的方式获取系统信息更为方便。


### 运行机制

OpenHarmony内核中，procfs在开机时会自动挂载到/proc目录下，仅支持内核模块创建文件节点来提供查询服务。


### 开发指导

procfs文件的创建无法使用一般的文件系统接口，需要使用ProcMkdir接口创建目录，使用CreateProcEntry接口创建文件。文件节点功能的开发就是实现read和write函数的钩子挂到CreateProcEntry创建的文件中。当用户使用读写procfs的文件时，就会调用到钩子函数来实现自定义的功能。


编程实例

下面我们以创建/proc/hello/world文件为例，实现如下功能：

1.在/proc/hello/world位置创建一个文件

2.当读文件内容时，返回"HelloWorld!"

3.当写文件内容时，打印写入的内容

  
```
#include "proc_fs.h"

static int TestRead(struct SeqBuf *buf, void *arg)
{
    LosBufPrintf(buf, "Hello World!\n"); /* 将数据打印到buffer中，这个buffer中的数据会返回到read的结果中 */
    return 0;
}

static int TestWrite(struct ProcFile *pf, const char *buffer, size_t buflen, loff_t *ppos)
{
    if ((buffer == NULL) || (buflen <= 0)) {
        return -EINVAL;
    }

    PRINTK("your input is: %s\n", buffer); /* 注意和上面的read接口区别，这是对write接口输入命令的反馈，这个打印只会打印到控制台 */
    return buflen;
}
static const struct ProcFileOperations HELLO_WORLD_OPS = {
    .read = TestRead,
    .write = TestWrite,
};

void HelloWorldInit(void)
{
    /* 创建hello目录 */
    struct ProcDirEntry *dir = ProcMkdir("hello", NULL);
    if (dir == NULL) {
        PRINT_ERR("create dir failed!\n");
        return;
    }

    /* 创建world文件 */
    struct ProcDirEntry *entry = CreateProcEntry("world", 0, dir);
    if (entry == NULL) {
        PRINT_ERR("create entry failed!\n");
        return;
    }

    /* 将自定义的read和write钩子挂到文件中 */
    entry->procFileOps = &HELLO_WORLD_OPS;
}
```

**结果验证**

启动后在shell输入如下命令

  
```
OHOS # cat /proc/hello/world
OHOS # Hello World!
OHOS # echo "yo" > /proc/hello/world
OHOS # your input is: yo
```
