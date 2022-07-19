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
