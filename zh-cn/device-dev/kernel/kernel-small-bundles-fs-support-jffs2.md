# JFFS2


## 基本概念

JFFS2是Journalling Flash File System Version 2（日志文件系统）的缩写，是针对MTD设备的日志型文件系统。

OpenHarmony内核的JFFS2主要应用于NOR FLASH闪存，其特点是：可读写、支持数据压缩、提供了崩溃/掉电安全保护、提供“写平衡”支持等。闪存与磁盘介质有许多差异，直接将磁盘文件系统运行在闪存设备上，会导致性能和安全问题。为解决这一问题，需要实现一个特别针对闪存的文件系统，JFFS2就是这样一种文件系统。


## 运行机制

关于JFFS2文件系统的在存储设备上的实际物理布局，及文件系统本身的规格说明，请参考JFFS2的[官方规格说明文档](https://sourceware.org/jffs2/)。

这里仅列举几个对开发者和使用者会有一定影响的JFFS2的重要机制/特征：

1. Mount机制及速度问题：按照JFFS2的设计，所有的文件会按照一定的规则，切分成大小不等的节点，依次存储到flash设备上。在mount流程中，需要获取到所有的这些节点信息并缓存到内存里。因此，mount速度和flash设备的大小和文件数量的多少成线性比例关系。这是JFFS2的原生设计问题，对于mount速度非常介意的用户，可以在内核编译时开启“Enable JFFS2 SUMMARY”选项，可以极大提升mount的速度。这个选项的原理是将mount需要的信息提前存储到flash上，在mount时读取并解析这块内容，使得mount的速度变得相对恒定。这个实际是空间换时间的做法，会消耗8%左右的额外空间。

2. 写平衡的支持：由于flash设备的物理属性，读写都只能基于某个特定大小的“块”进行，为了防止某些特定的块磨损过于严重，在JFFS2中需要对写入的块进行“平衡”的管理，保证所有的块的写入次数都是相对平均的，进而保证flash设备的整体寿命。

3. GC(garbage collection)机制：在JFFS2里发生删除动作，实际的物理空间并不会立即释放，而是由独立的GC线程来做空间整理和搬移等GC动作，和所有的GC机制一样，在JFFS2里的GC会对瞬时的读写性能有一定影响。另外，为了有空间能被用来做空间整理，JFFS2会对每个分区预留3块左右的空间，这个空间是用户不可见的。

4. 压缩机制：当前使用的JFFS2，底层会自动的在每次读/写时进行解压/压缩动作，实际IO的大小和用户请求读写的大小并不会一样。特别在写入时，不能通过写入大小来和flash剩余空间的大小来预估写入一定会成功或者失败。

5. 硬链接机制：JFFS2支持硬链接，底层实际占用的物理空间是一份，对于同一个文件的多个硬连接，并不会增加空间的占用；反之，只有当删除了所有的硬链接时，实际物理空间才会被释放。


## 开发指导

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
| -s | 页大小，不指定默认为4KiB | 
| -e | eraseblock大小，不指定默认为64KiB | 
| -p | 镜像大小。在镜像文件后面，用0xFF填充至指定大小，不指定则用0xFF填充至eraseblock对齐。 | 
| -d | 要制作成文件系统镜像的源目录 | 
| -o | 要制成的镜像名称 | 

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
