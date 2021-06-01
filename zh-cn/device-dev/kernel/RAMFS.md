# RAMFS<a name="ZH-CN_TOPIC_0000001052810480"></a>

-   [概述](#section7216205735619)
-   [注意事项](#section970375615711)
-   [开发指导](#section18433111125812)

## 概述<a name="section7216205735619"></a>

RAMFS是一个可动态调整大小的基于RAM的文件系统。RAMFS没有后备存储源。向RAMFS中进行的文件写操作也会分配目录项和页缓存，但是数据并不写回到任何其他存储介质上，掉电后数据丢失。

RAMFS文件系统把所有的文件都放在 RAM 中，所以读/写操作发生在RAM中，可以用RAMFS来存储一些临时性或经常要修改的数据，例如/tmp和/var目录，这样既避免了对存储器的读写损耗，也提高了数据读写速度。

OpenHarmony内核的RAMFS是一个简单的文件系统，它是基于RAM的动态文件系统的一种缓冲机制。

OpenHarmony内核的RAMFS基于虚拟文件系统层（VFS\)，不能格式化。

## 注意事项<a name="section970375615711"></a>

-   RAMFS文件系统的读写指针没有分离，所以以O\_APPEND（追加写）方式打开文件后，读指针也在文件尾，读文件前需要用户手动置位。

-   RAMFS只能挂载一次，一次挂载成功后，后面不能继续挂载到其他目录。

-   RAMFS文件数量受信号量资源限制，不能超过LOSCFG\_BASE\_IPC\_SEM\_LIMIT。

-   open打开一个文件，参数有O\_TRUNC时，会将文件中的内容清空。


-   RAMFS文件系统支持的操作有：open, close, read, write, seek, opendir, closedir, readdir, readdir\_r, rewinddir,  sync, statfs, remove, unlink, mkdir, rmdir, rename, stat, stat64, seek64, mmap, mount, umount。


-   RAMFS属于调测功能，默认配置为关闭，正式产品中禁止使用该功能。


## 开发指导<a name="section18433111125812"></a>

RAMFS的挂载和卸载可以在如下两种方式中任选其一：

-   使用代码挂载和卸载完成RAMFS文件系统的初始化和去初始化。
    1.  调用mount函数完成RAMFS文件系统的初始化。

        ```
        void ram_fs_init(void) {
             int swRet;
             swRet = mount(NULL, RAMFS_DIR, "ramfs", 0, NULL);
             if (swRet != 0) {
                 dprintf("mount ramfs err %d\n", swRet);
                 return;
             }
             dprintf("Mount ramfs finished.\n");
         }
        ```

        调用初始化函数，随后在OpenHarmony内核系统启动时可以看到如下显示，表示RAMFS文件系统已初始化成功：

        ```
        Mount ramfs finished
        ```

    2.  卸载。调用去初始化函数，随后在OpenHarmony内核系统可以看到如下显示，表示RAMFS文件系统已卸载：

        ```
        void ram_fs_uninit(void) {
             int swRet;
             swRet = umount(RAMFS_DIR);
             if (swRet != 0) {
                 dprintf("Umount ramfs err %d\n", swRet);
                 return;
             }
             dprintf("Umount ramfs finished.\n");
         }
        ```


-   使用命令行的方式完成RAMFS文件系统的挂载和卸载 。
    1.  使用mount命令完成RAMFS文件系统的挂载，将从串口得到如下回应信息，表明挂载成功。

        ```
        OHOS # mount 0 /ramfs ramfs
        mount ok
        ```

    2.  使用umount命令完成卸载，将从串口得到如下回应信息，表明卸载成功。

        ```
        OHOS # umount /ramfs 
        umount ok
        ```



