# 虚拟文件系统


## 基本概念

VFS（Virtual File System）是文件系统的虚拟层，它不是一个实际的文件系统，而是一个异构文件系统之上的软件粘合层，为用户提供统一的类Unix文件操作接口。由于不同类型的文件系统接口不统一，若系统中有多个文件系统类型，访问不同的文件系统就需要使用不同的非标准接口。而通过在系统中添加VFS层，提供统一的抽象接口，屏蔽了底层异构类型的文件系统的差异，使得访问文件系统的系统调用不用关心底层的存储介质和文件系统类型，提高开发效率。

OpenHarmony内核中，VFS框架是通过在内存中的树结构来实现的，树的每个结点都是一个Vnode结构体，父子结点的关系以PathCache结构体保存。VFS最主要的两个功能是：

- 查找节点。

- 统一调用（标准）。


## 运行机制

当前，VFS层主要通过函数指针，实现对不同文件系统类型调用不同接口实现标准接口功能；通过Vnode与PathCache机制，提升路径搜索以及文件访问的性能；通过挂载点管理进行分区管理；通过FD管理进行进程间FD隔离等。下面将对这些机制进行简要说明。

1. 文件系统操作函数指针：VFS层通过函数指针的形式，将统一调用按照不同的文件系统类型，分发到不同文件系统中进行底层操作。各文件系统的各自实现一套Vnode操作、挂载点操作以及文件操作接口，并以函数指针结构体的形式存储于对应Vnode、挂载点、File结构体中，实现VFS层对下访问。

2. Vnode：Vnode是具体文件或目录在VFS层的抽象封装，它屏蔽了不同文件系统的差异，实现资源的统一管理。Vnode节点主要有以下几种类型：
   - 挂载点：挂载具体文件系统，如/、/storage
   - 设备节点：/dev目录下的节点，对应于一个设备，如/dev/mmcblk0
   - 文件/目录节点：对应于具体文件系统中的文件/目录，如/bin/init

   Vnode通过哈希以及LRU机制进行管理。当系统启动后，对文件或目录的访问会优先从哈希链表中查找Vnode缓存，若缓存没有命中，则并从对应文件系统中搜索目标文件或目录，创建并缓存对应的Vnode。当Vnode缓存数量达到上限时，将淘汰长时间未访问的Vnode，其中挂载点Vnode与设备节点Vnode不参与淘汰。当前系统中Vnode的规格默认为512，该规格可以通过LOSCFG_MAX_VNODE_SIZE进行配置。Vnode数量过大，会造成较大的内存占用；Vnode数量过少，则会造成搜索性能下降。下图展示了Vnode的创建流程。

     **图1** Vnode创建流程

     ![zh-cn_image_0000001127393126](figures/zh-cn_image_0000001127393126.png)

1. PathCache：PathCache是路径缓存，它通过哈希表存储，利用父节点Vnode的地址和子节点的文件名，可以从PathCache中快速查找到子节点对应的Vnode。下图展示了文件/目录的查找流程。
    
     **图2** 文件查找流程

     ![zh-cn_image_0000001175795145](figures/zh-cn_image_0000001175795145.png)

1. PageCache：PageCache是内核中文件的缓存。当前PageCache仅支持缓存二进制文件，在初次访问文件时通过mmap映射到内存中，下次再访问时，直接从PageCache中读取，可以提升对同一个文件的读写速度。另外基于PageCache可实现以文件为基底的进程间通信。

2. fd管理：Fd（File Descriptor）是描述一个打开的文件/目录的描述符。当前OpenHarmony内核中，fd总规格为896，分为三种类型：
   - 普通文件描述符，系统总规格为512。
   - Socket描述符，系统总规格为128。
   - 消息队列描述符，系统总规格为256。

   当前OpenHarmony内核中，对不同进程中的fd进行隔离，即进程只能访问本进程的fd，所有进程的fd映射到全局fd表中进行统一分配管理。进程的文件描述符最多有256个。

3. 挂载点管理：当前OpenHarmony内核中，对系统中所有挂载点通过链表进行统一管理。挂载点结构体中，记录了该挂载分区内的所有Vnode。当分区卸载时，会释放分区内的所有Vnode。


## 开发指导


### 接口说明

当前文件系统支持的接口如下表所示，表格中的“×”代表对应文件系统不支持该接口。

  **表1** 文件操作

| 接口**名称** | 功能 | FAT | JFFS2 | NFS | TMPFS | PROCFS | 
| -------- | -------- | -------- | -------- | -------- | -------- | -------- |
| open | 打开文件 | √ | √ | √ | √ | √ | 
| read/pread/readv/preadv | 读取文件 | √ | √ | √ | √ | √ | 
| write/pwrite/writev/pwritev | 写入文件 | √ | √ | √ | √ | √ | 
| lseek | 设置文件偏移 | √ | √ | √ | √ | × | 
| close | 关闭文件 | √ | √ | √ | √ | √ | 
| unlink | 删除文件 | √ | √ | √ | √ | × | 
| fstat | 查询文件信息 | √ | √ | √ | √ | √ | 
| fallocate | 预分配大小 | √ | × | × | × | × | 
| truncate | 文件截断 | √ | √ | × | √ | × | 
| link | 创建硬链接 | × | √ | × | × | × | 
| symlink | 创建软链接 | √ | √ | × | × | × | 
| readlink | 读取软链接 | √ | √ | × | × | × | 
| dup | 复制文件句柄 | √ | √ | √ | √ | √ | 
| fsync | 文件内容刷入设备 | √ | × | × | × | × | 
| ioctl | 设备控制 | × | × | × | √ | × | 
| fcntl | 文件控制操作 | √ | √ | √ | √ | √ | 
| mkdir | 创建目录 | √ | √ | √ | √ | × | 
| opendir | 打开目录 | √ | √ | √ | √ | √ | 
| readdir | 读取目录 | √ | √ | √ | √ | √ | 
| closedir | 关闭目录 | √ | √ | √ | √ | √ | 
| telldir | 获取目录偏移 | √ | √ | √ | √ | √ | 
| seekdir | 设置目录偏移 | √ | √ | √ | √ | √ | 
| rewinddir | 重置目录偏移 | √ | √ | √ | √ | × | 
| scandir | 读取目录数据 | √ | √ | √ | √ | √ | 
| rmdir | 删除目录 | √ | √ | √ | √ | × | 
| chdir | 切换当前路径 | √ | √ | √ | √ | √ | 
| getcwd | 获取当前路径 | √ | √ | √ | √ | √ | 
| realpath | 相对/绝对路径转换 | √ | √ | √ | √ | √ | 
| rename | 文件/目录重命名 | √ | √ | √ | √ | × | 
| chmod | 修改文件/目录属性 | √ | √ | × | × | × | 
| chown | 修改文件/目录所有者 | √ | √ | × | × | × | 
| stat/lstat | 查询文件/目录信息 | √ | √ | √ | √ | √ | 
| access | 查询文件/目录访问权限 | √ | √ | √ | √ | √ | 
| mount | 挂载分区 | √ | √ | √ | √ | √ | 
| umount | 卸载分区 | √ | √ | √ | √ | × | 
| statfs | 查询挂载分区信息 | √ | √ | √ | √ | √ | 
| format | 格式化分区 | √ | × | × | × | × | 
| sync | 分区内容刷入设备 | √ | × | × | × | × | 

  **表2** 目录操作

| 接口**名称** | 功能 | FAT | JFFS2 | NFS | TMPFS | PROCFS | 
| -------- | -------- | -------- | -------- | -------- | -------- | -------- |
| mkdir | 创建目录 | √ | √ | √ | √ | × | 
| opendir | 打开目录 | √ | √ | √ | √ | √ | 
| readdir | 读取目录 | √ | √ | √ | √ | √ | 
| closedir | 关闭目录 | √ | √ | √ | √ | √ | 
| telldir | 获取目录偏移 | √ | √ | √ | √ | √ | 
| seekdir | 设置目录偏移 | √ | √ | √ | √ | √ | 
| rewinddir | 重置目录偏移 | √ | √ | √ | √ | × | 
| scandir | 读取目录数据 | √ | √ | √ | √ | √ | 
| rmdir | 删除目录 | √ | √ | √ | √ | × | 
| chdir | 切换当前路径 | √ | √ | √ | √ | √ | 
| getcwd | 获取当前路径 | √ | √ | √ | √ | √ | 
| realpath | 相对/绝对路径转换 | √ | √ | √ | √ | √ | 
| rename | 文件/目录重命名 | √ | √ | √ | √ | × | 
| chmod | 修改文件/目录属性 | √ | √ | × | × | × | 
| chown | 修改文件/目录所有者 | √ | √ | × | × | × | 
| stat/lstat | 查询文件/目录信息 | √ | √ | √ | √ | √ | 
| access | 查询文件/目录访问权限 | √ | √ | √ | √ | √ | 
| mount | 挂载分区 | √ | √ | √ | √ | √ | 
| umount | 卸载分区 | √ | √ | √ | √ | × | 
| statfs | 查询挂载分区信息 | √ | √ | √ | √ | √ | 
| format | 格式化分区 | √ | × | × | × | × | 
| sync | 分区内容刷入设备 | √ | × | × | × | × | 

  **表3** 分区操作

| 接口**名称** | 功能 | FAT | JFFS2 | NFS | TMPFS | PROCFS | 
| -------- | -------- | -------- | -------- | -------- | -------- | -------- |
| mount | 挂载分区 | √ | √ | √ | √ | √ | 
| umount | 卸载分区 | √ | √ | √ | √ | × | 
| statfs | 查询挂载分区信息 | √ | √ | √ | √ | √ | 
| format | 格式化分区 | √ | × | × | × | × | 
| sync | 分区内容刷入设备 | √ | × | × | × | × | 


### 开发流程

文件系统的主要开发流程包括挂载/卸载分区，以及系列目录/文件操作。


### 编程实例

代码实现如下：

  
```
#include <stdio.h>
#include <string.h>
#include "sys/stat.h"
#include "fcntl.h"
#include "unistd.h"

#define LOS_OK 0
#define LOS_NOK -1

int main(void)
{
    int ret;
    int fd = -1;
    ssize_t len;
    off_t off;
    char mntName[20] = "/storage";
    char devName[20] = "/dev/mmcblk0p0";
    char dirName[20] = "/storage/test";
    char fileName[20] = "/storage/test/file.txt";
    char writeBuf[20] = "Hello OpenHarmony!";
    char readBuf[20] = {0};

    /* 创建目录“/storage” */
    ret = mkdir(mntName, 0777);
    if (ret != LOS_OK) {
        printf("mkdir failed.\n");
        return LOS_NOK;
    }

    /* 挂载设备“/dev/mmcblk0p0”到“/storage” */
    ret = mount(devName, mntName, "vfat", 0, 0);
    if (ret != LOS_OK) {
        printf("mount failed.\n");
        return LOS_NOK;
    }

    /* 创建目录“/storage/test” */
    ret = mkdir(dirName, 0777);
    if (ret != LOS_OK) {
        printf("mkdir failed.\n");
        return LOS_NOK;
    }

    /* 创建可读写文件“/storage/test/file.txt” */
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
    if (len != strlen(readBuf)) {
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

    /* 删除文件“/storage/test/file.txt” */
    ret = unlink(fileName);
    if (ret != LOS_OK) {
        printf("unlink failed.\n");
        return LOS_NOK;
    }

    /* 删除目录“/storage/test” */
    ret = rmdir(dirName);
    if (ret != LOS_OK) {
        printf("rmdir failed.\n");
        return LOS_NOK;
    }

    /* 卸载分区“/storage” */
    ret = umount(mntName);
    if (ret != LOS_OK) {
        printf("umount failed.\n");
        return LOS_NOK;
    }

    /* 删除目录“/storage” */
    ret = rmdir(mntName);
    if (ret != LOS_OK) {
        printf("rmdir failed.\n");
        return LOS_NOK;
    }

    return LOS_OK;
}
```


**结果验证**


编译运行得到的结果为：


  
```
Hello OpenHarmony!
```
