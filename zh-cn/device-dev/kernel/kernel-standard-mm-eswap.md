# Enhanced SWAP特性介绍


## 基本概念

ESwap(Enhanced Swap)提供了自定义新增存储分区作为内存交换分区的能力，并创建了一个常驻进程zswapd将[ZRAM](https://www.kernel.org/doc/html/latest/admin-guide/blockdev/zram.html)压缩后的匿名页加密换出到ESwap存储分区，从而能完全的空出一块可用内存，以此来达到维持Memavailable水线的目标。同时，配合这个回收机制，在整个内存框架上进行改进，优化匿名页和文件页的回收效率，并且使两者的回收比例更加合理以避免过度回收导致的refault问题造成卡顿现象。


## ZRAM与ESwap配置指导

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 使能ESwap需要在使能ZRAM之前，不需要使用ESwap时, 也可以仅使能ZRAM。如部分设备不包括用于换出的存储设备，也没有新建相应的存储分区，那么可以仅使能ZRAM来通过zswapd进行内存回收。

### 使能ESwap
1. 打开相关配置项及依赖。

	启用ESwap，需要通过编译内核时打开相应的配置项及依赖，ESwap相关CONFIG如下：

	```
	CONFIG_HYPERHOLD=y                  // Enable HyperHold
	CONFIG_HYPERHOLD_DEBUG=y            // Enable HyperHold Debug
	CONFIG_HYPERHOLD_ZSWAPD=y           // Enable zswapd thread to reclaim anon pages in background
	CONFIG_HYPERHOLD_FILE_LRU=y         // Enable HyperHold FILE LRU
	CONFIG_HYPERHOLD_MEMCG=y            // Enable Memcg Management in HyperHold
	CONFIG_ZRAM_GROUP=y                 // Enable Manage Zram objs with mem_cgroup
	CONFIG_ZRAM_GROUP_DEBUG=y           // Enable Manage Zram objs with mem_cgroup Debug
	CONFIG_ZLIST_DEBUG=y                // Enable Debug info for zram group list
	CONFIG_ZRAM_GROUP_WRITEBACK=y       // Enable Write back grouped zram objs to Hyperhold driver
	```

	同时，开启ESwap需依赖以下CONFIG：

	```
	CONFIG_MEMCG=y       // Enable Memory controller
	CONFIG_SWAP=y        // Enable Support for paging of anonymous memory (swap)
	CONFIG_ZSMALLOC=y    // Enable Memory allocator for compressed pages
	CONFIG_ZRAM=y        // Enable Compressed RAM block device support
	```

2. 创建ESwap设备。

	可以使用任意block设备作为ESwap交换设备，这里创建一个文件hpdisk挂载为loop6设备：

	```Bash
	// 通过dd命令创建一个文件hpdisk用于ESwap换出，具体大小需根据产品及需求调整，此处设置为512MB。
	dd if=/dev/random of=/data/hpdisk bs=4096 count=131072
	// 将上一步创建的hpdisk与ESwap device进行绑定。
	losetup /dev/block/loop6 hpdisk
	```

3. 配置ESwap。

	将2中创建的设备绑定为ESwap换出设备：

	```Bash
	echo /dev/block/loop6 > /proc/sys/kernel/hyperhold/device
	```

	ESwap默认对换出数据使用软件加密，如果2中创建的ESwap设备支持inline加密，可以关闭ESwap的软件加密功能：

	```Bash
	// 需咨询开发板厂商是否支持并开启硬加密，否则不要执行该操作。
	echo 0 > /proc/sys/kernel/hyperhold/soft_crypt
	```

	> ![icon-caution.gif](public_sys-resources/icon-caution.gif) **注意：**
	> 出于安全考虑，所有换出内容均需加密。因此若当前配置ESwap的设备不支持inline加密，或编译时未打开inline加密宏，则在关闭软加密时，ESwap无法enable。

4. 使能ESwap。

	使能ESwap，使能后无法更改上述配置：

	```Bash
	echo enable > /proc/sys/kernel/hyperhold/enable
	```


### 使能ZRAM

1. 初始化ZRAM。

	设置ZRAM与ESwap的交互方式，并配置ZRAM的大小。

	```Bash
	// 打开ZRAM到ESwap的换入换出功能，该步骤必须要在配置ZRAM大小之前。
	echo readwrite > /sys/block/zram0/group
	// 配置ZRAM的大小，具体大小需根据产品及需求调整，此处设置为512MB。
	echo 512M > /sys/block/zram0/disksize
	```

	> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
	> /sys/block/zram0/group可接受参数及作用为：
	>
	> - disable：表示禁用；
	> - readonly：表示只记录数据的cgroup信息，并不换出；
	> - readwrite：表示打开ZRAM到eswap的换入换出功能。

2. 使能ZRAM。

	启用ZRAM设备为交换分区并将其使能。

	```Bash
	mkswap /dev/block/zram0
	swapon /dev/block/zram0
	```


### 关闭ESwap与ZRAM

1. 关闭ESwap。

	```Bash
	echo disable > /proc/sys/kernel/hyperhold/enable
	或
	echo force_disable > /proc/sys/kernel/hyperhold/enable
	```

	> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
	> 两者的区别在于：
	>
	> - disable：表示如果ESwap中没有数据，则完全关闭，否则变为只读模式；
	> - force_disable：表示如果没有数据，完全关闭，否则变为只读模式，并同步等待ESwap中数据完全读出，然后完全关闭。

2. 关闭ZRAM及ZRAM group。

	```Bash
	// 若已经执行过swapon，则需先执行swapoff
	swapoff /dev/block/zram0
	echo 1 > /sys/block/zram0/reset
	```


## ESwap相关接口

ESwap提供了一些接口用于控制换入换出策略以及记录当前状态，这些接口位于memcg所挂载的目录当中，如`/dev/memcg/`。

| 功能分类 | 接口名 | 描述 | 参考值 |
| -------- | -------- | -------- | -------- |
| 控制接口 | [avail_buffers](#avail_buffers) | 设置buffer区间 | 300 250 350 200 |
|         | [zswapd_single_memcg_param](#zswapd_single_memcg_param) | 设置当前memcg相关配置 | 300 40 0 0 |
|         | [zram_wm_ratio](#zram_wm_ratio) | 设置zram换出水线 | 0 |
| 状态接口 | [zswapd_pressure_show](#zswapd_pressure_show) | 记录当前buffer以及refault | NA |
|          | [stat](#stat) | 检测ESwap实时情况 | NA |
|          | [zswapd_vmstat_show](#zswapd_vmstat_show) | 记录zswapd运行过程中各种事件 | NA |

> ![icon-caution.gif](public_sys-resources/icon-caution.gif) **注意：**
> 除avail_buffers会因为调整了buffer水线而会主动去唤醒zswapd外，其余控制接口并不会主动唤醒zswapd，只是其配置需在zswapd所被唤醒后方可生效。


### avail_buffers

avail_buffers接口用于设置buffer区间[min_avail_buffers, high_avail_buffers]，当检测到当前的buffer低于min_avail_buffers时则会唤醒zswapd进行匿名页回收，期望的回收量为high_avail_buffers与当前系统buffer值的差值，实际可能会因为无法回收等原因而未回收足够多内存。avail_buffers为期望的内存正常状态buffer值，free_swap_threshold则是设置交换分区空闲容量的阈值，当zswapd唤醒并进行内存回收之后，会根据当前系统情况以及两者的设置记录当前内存压力事件，如medium press，critical press等。可主动调整来触发zswapd回收，如`echo 1000 950 1050 0 > /dev/memcg/memory.avail_buffers`。

**默认值：**

```
avail_buffers: 0
min_avail_buffers: 0
high_avail_buffers: 0
free_swap_threshold: 0
```

**限制：**

0<=min_avail_buffers<=avail_buffers<=high_avail_buffers

0<=free_swap_threashold

取值均为整型。

### zswapd_single_memcg_param

设置当前memcg的相关配置。score为当前memcg回收优先级，ub_mem2zram_ratio为内存压缩到ZRAM的比率，ub_zram2ufs_ratio为ZRAM换出到ESwap的比率，refault_threshold为refault的阈值，可通过调整比率来控制ZRAM压缩以及ESwap换出情况，如`echo 60 10 50 > memory.zswapd_single_memcg_param`。

默认值：

```
memcg score: 300
memcg ub_mem2zram_ratio: 60
memcg ub_zram2ufs_ratio: 10
memcg refault_threshold: 50
```

限制：

0<=ub_mem2zram_ratio<=100

0<=ub_zram2ufs_ratio<=100

0<=refault_threshold<=100

取值均为整型。

### zram_wm_ratio

设置ZRAM换出水线，即当当前ZRAM中压缩的匿名页大于ZRAM总大小*zram_wm_ratio时，会开始向ESwap进行换出，但是具体换出时间为zswapd因buffer水线而唤醒之后。设置为0时系统默认为37，可进行调整，如`echo 30 > /dev/memcg/memory.zram_wm_ratio`。

**默认值：**

```
zram_wm_ratio: 0
```

**限制：**

0<=zram_wm_ratio<=100

取值为整型。

### zswapd_pressure_show

记录当前zswapd所需相关状态，buffer_size为当前系统的buffer值，recent_refault为最近产生的refault次数。


### stat

在原有memcg.stat的基础上新增了Anon，File，zram，Eswap等项，用以监测ESwap的实时情况。


### zswapd_vmstat_show

记录zswapd运行过程中的各种事件。


## 触发zswapd回收

可先通过`cat /dev/memcg/memory.zswapd_pressure_show`查看当前buffer值，比如当前为1200，那么可通过主动调整buffer区间大于1200，来主动唤醒zswapd。

```Bash
echo 1300 1250 1350 0 > /dev/memcg/memory.avail_buffers
```


## ESwap配置大小示例

ZRAM与ESwap的大小配置需根据实际使用场景以及产品硬件特点进行适配。目前在rk3568板子上使用时，其ram为2G，因此设置的ZRAM与ESwap大小均为512MB。