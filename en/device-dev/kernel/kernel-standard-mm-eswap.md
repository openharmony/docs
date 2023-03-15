# ESwap


## Basic Concepts

Enhanced Swap (ESwap) allows a custom partition to serve as a swap partition and uses a resident process zswapd to encrypt and swap the anonymous pages compressed by [zram](https://www.kernel.org/doc/html/latest/admin-guide/blockdev/zram.html) to the ESwap partition. In this way, a block of memory can be completely released to ensure the available memory (Memavailable) waterline. In addition to this reclaiming mechanism, the entire memory framework is enhanced to improve the reclaiming efficiency of anonymous pages and file pages and streamline the reclaiming ratio of these two types of pages to prevent refaults caused by excessive reclamation.


## Configuring zram and ESwap

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> Enable ESwap before zram is enabled. If ESwap is not used, you can enable zram alone. If a device does not have the storage device for swap-out or have the corresponding storage partition created, you can enable zram to reclaim memory using **zswapd**.

### Enabling ESwap
1. Enable related configuration items and dependencies.

	To enable ESwap, you must enable the corresponding configuration items and dependencies during kernel compilation. The configuration items related to ESwap are as follows:

	```
	CONFIG_HYPERHOLD=y                  // Enable Hyperhold
	CONFIG_HYPERHOLD_DEBUG=y            // Enable Hyperhold debug
	CONFIG_HYPERHOLD_ZSWAPD=y           // Enable the zswapd thread to reclaim Anon pages in background
	CONFIG_HYPERHOLD_FILE_LRU=y         // Enable Hyperhold FILE LRU
	CONFIG_HYPERHOLD_MEMCG=y            // Enable Memcg management in Hyperhold
	CONFIG_ZRAM_GROUP=y                 // Enable Manage Zram objs with mem_cgroup
	CONFIG_ZRAM_GROUP_DEBUG=y           // Enable Manage Zram objs with mem_cgroup Debug
	CONFIG_ZLIST_DEBUG=y                // Enable Debug info for zram group list
	CONFIG_ZRAM_GROUP_WRITEBACK=y       // Enable write back grouped zram objs to Hyperhold driver
	```

	Enable the following dependencies:

	```
	CONFIG_MEMCG=y       // Enable memory controller
	CONFIG_SWAP=y        // Enable paging of anonymous memory (swap)
	CONFIG_ZSMALLOC=y    // Enable memory allocator for compressed pages
	CONFIG_ZRAM=y        // Enable compressed RAM block device support
	```

2. Create an ESwap device.

	You can use any block device as the ESwap device. In this example, create the **hpdisk** file and mount it to the loop6 device.

	```Bash
	// Run the dd command to create the hpdisk file for ESwap. In this example, the file size is 512 MB. Set the file size based on service requirements.
	dd if=/dev/random of=/data/hpdisk bs=4096 count=131072
	// Associate the hpdisk file with the ESwap device.
	losetup /dev/block/loop6 hpdisk
	```

3. Configure ESwap.

	Bind the device created in step 2 as the ESwap device.

	```Bash
	echo /dev/block/loop6 > /proc/sys/kernel/hyperhold/device
	```

	By default, ESwap encrypts the data swapped out. If the ESwap device created in step 2 supports inline encryption, you can disable the ESwap software encryption function.

	```Bash
	// Check whether hardware-based encryption is supported and enabled. If yes, disable software encryption. Otherwise, do not disable software encryption.
	echo 0 > /proc/sys/kernel/hyperhold/soft_crypt
	```

	> ![icon-caution.gif](public_sys-resources/icon-caution.gif) **CAUTION**<br>
	> For security purposes, all swapped content must be encrypted. If the ESwap device created does not support inline encryption or the inline encryption macro is not enabled during compilation, ESwap cannot be enabled after software encryption is disabled.

4. Enable ESwap.

	After ESwap is enabled, the preceding configuration cannot be modified.

	```Bash
	echo enable > /proc/sys/kernel/hyperhold/enable
	```


### Enabling zram

1. Initialize zram.

	Configure the interaction between zram and ESwap and set the zram size.

	```Bash
	// Enable the swap-in and swap-out functions from zram to ESwap. Perform this step before setting the zram size.
	echo readwrite > /sys/block/zram0/group
	// Set the zram size. In this example, the zram size is set to 512 MB.
	echo 512M > /sys/block/zram0/disksize
	```

	> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
	> The parameters and functions of **/sys/block/zram0/group** are as follows:
	>
	> - **disable**: disables the function.
	> - **readonly**: only records the cgroup information of the data but not swap it out.
	> - **readwrite**: enables swap-in and swap-out from zram to ESwap.

2. Enable zram.

	Use the zram device as the swap partition.

	```Bash
	mkswap /dev/block/zram0
	swapon /dev/block/zram0
	```


### Disabling ESwap and zram

1. Disable ESwap.

	```Bash
	echo disable > /proc/sys/kernel/hyperhold/enable
	Or
	echo force_disable > /proc/sys/kernel/hyperhold/enable
	```

	> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
	> The difference of the two commands is as follows:
	>
	> - **disable**: If there is no data in the ESwap partition, disable ESwap. Otherwise, changes ESwap to **readonly** mode.
	> - **force_disable**: If there is no data in the ESwap partition, disable ESwap. Otherwise, changes ESwap to **readonly** mode and disable ESwap until all data in the ESWAP partition is read.

2. Disable zram and zram group.

	```Bash
	// If swapon is executed, run swapoff first.
	swapoff /dev/block/zram0
	echo 1 > /sys/block/zram0/reset
	```


## ESwap APIs

ESwap provides APIs to control swap-in and swap-out policies and record the current status. These APIs are located in the directory to which memcg is mounted, for example, **/dev/memcg/**.

| Category| API| Description| Reference Value|
| -------- | -------- | -------- | -------- |
| Control| [avail_buffers](#avail_buffers) | Sets the buffer range.| 300 250 350 200 |
|         | [zswapd_single_memcg_param](#zswapd_single_memcg_param) | Sets memcg configuration.| 300 40 0 0 |
|         | [zram_wm_ratio](#zram_wm_ratio) | Sets the zram swap-out waterline.| 0 |
| Status| [zswapd_pressure_show](#zswapd_pressure_show) | Records the current buffer and refault.| NA |
|          | [stat](#stat) | Checks the real-time status of ESwap.| NA |
|          | [zswapd_vmstat_show](#zswapd_vmstat_show) | Records events during the zswapd running.| NA |

> ![icon-caution.gif](public_sys-resources/icon-caution.gif) **CAUTION**<br>
> Only **avail_buffers** proactively wakes up zswapd because the buffer waterline is adjusted. Other control APIs do not proactively wake up zswapd, but their configuration takes effect only after zswapd is woken up.


### avail_buffers

The **avail_buffers** API sets the buffer range [min_avail_buffers, high_avail_buffers]. When the current buffer is less than the value of **min_avail_buffers**, zswapd will be woken up to reclaim anonymous pages. The expected amount of memory to reclaim is the difference between the value of **high_avail_buffers** and the current system buffer value. In fact, less memory is reclaimed due to reasons such as reclamation failure. 

The parameters include the following:

- **avail_buffers** indicates the expected buffer value.
- **free_swap_threshold** indicates the threshold of the free capacity of the swap partition. After zswapd is woken up to reclaim memory, press events, such as medium press and critical press, will be recorded based on the current system status and the settings of these two parameters. 

You can proactively adjust the values to trigger zswapd reclamation.

**Example**:

`echo 1000 950 1050 0 > /dev/memcg/memory.avail_buffers`

**Default value**:

```
avail_buffers: 0
min_avail_buffers: 0
high_avail_buffers: 0
free_swap_threshold: 0
```

**Limit**:

0<=min_avail_buffers<=avail_buffers<=high_avail_buffers

0<=free_swap_threashold

The values are all integers.

### zswapd_single_memcg_param

**zswapd_single_memcg_param** sets the memcg configuration. The parameters include the following:

- **score** indicates the current memcg reclamation priority. 
- **ub_mem2zram_ratio** indicates the memory compression ratio to zram. 
- **ub_zram2ufs_ratio** indicates the ratio of zram to ESwap. 
- **refault_threshold** indicates the refault threshold. 

You can modify the parameters to control zram compression and ESwap. 

**Example**:

`echo 60 10 50 > memory.zswapd_single_memcg_param`

**Default value**:

```
memcg score: 300
memcg ub_mem2zram_ratio: 60
memcg ub_zram2ufs_ratio: 10
memcg refault_threshold: 50
```

**Limit**:

0<=ub_mem2zram_ratio<=100

0<=ub_zram2ufs_ratio<=100

0<=refault_threshold<=100

The values are all integers.

### zram_wm_ratio

**zram_wm_ratio** sets the zram swap-out waterline. When the size of the compressed anonymous page in the zram partition is greater than the total size of zram multiplied by **zram_wm_ratio**, the page is swapped out to the ESwap partition. The swap is performed after zswapd is woken up by the buffer waterline. The system defaults the value **0** as **37**. 

You can change the value as required.

**Example**: 

`echo 30 > /dev/memcg/memory.zram_wm_ratio`

**Default value**:

```
zram_wm_ratio: 0
```

**Limit**:

0<=zram_wm_ratio<=100

The value is an integer.

### zswapd_pressure_show

**zswapd_pressure_show** records the zswapd status. **buffer_size** indicates the current buffer size of the system, and **recent_refault** indicates the number of refaults occurred.


### stat

In addition to **memcg.stat**, the **stat** API is added with **Anon**, **File**, **zram**, and **Eswap** to monitor ESwap in real time.


### zswapd_vmstat_show

**zswapd_vmstat_show** records events occurred during the zswapd running.


## Triggering zswapd

You can run **cat /dev/memcg/memory.zswapd_pressure_show** to check the current buffer value. For example, if the current buffer value is 1200, you can adjust the buffer range to a value greater than 1200 to wake up zswapd.

```Bash
echo 1300 1250 1350 0 > /dev/memcg/memory.avail_buffers
```


## ESwap Size

Set zram and ESwap partition sizes based on service requirements and hardware features. For the rk3568 board whose RAM is 2 GB, the zram and ESwap partitions are set to 512 MB.
