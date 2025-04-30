# 虚拟内存管理


## 基本概念

虚拟内存管理是计算机系统管理内存的一种技术。每个进程都有连续的虚拟地址空间，虚拟地址空间的大小由CPU的位数决定，32位的硬件平台可以提供的最大的寻址空间为0-4GiB。整个4GiB空间分成两部分，LiteOS-A内核占据3GiB的高地址空间，1GiB的低地址空间留给用户态进程使用。各个进程空间的虚拟地址空间是独立的，代码、数据互不影响。

系统将虚拟内存分割为称为虚拟页的内存块，大小一般为4KiB或64KiB，LiteOS-A内核默认的页的大小是4KiB，根据需要可以对MMU（Memory Management Units）进行配置。虚拟内存管理操作的最小单位就是一个页，LiteOS-A内核中一个虚拟地址区间region包含地址连续的多个虚拟页，也可只有一个页。同样，物理内存也会按照页大小进行分割，分割后的每个内存块称为页帧。虚拟地址空间划分：内核态占高地址3GiB(0x40000000 ~ 0xFFFFFFFF)，用户态占低地址1GiB(0x01000000 ~ 0x3F000000)，具体见下表，详细可以查看或配置los_vm_zone.h。

  **表1** 内核态地址规划

| Zone名称 | 描述 | 属性 |
| -------- | -------- | -------- |
| DMA&nbsp;zone | 供IO设备的DMA使用。 | Uncache |
| Normal&nbsp;zone | 加载内核代码段、数据段、堆和栈的地址区间。 | Cache |
| high&nbsp;mem&nbsp;zone | 可以分配连续的虚拟内存，但其所映射的物理内存不一定连续。 | Cache |

  **表2** 用户态虚地址规划

| Zone名称 | 描述 | 属性 |
| -------- | -------- | -------- |
| 代码段 | 用户态代码段地址区间。 | Cache |
| 堆 | 用户态堆地址区间。 | Cache |
| 栈 | 用户态栈地址区间。 | Cache |
| 共享库 | 用于加载用户态共享库的地址区间，包括mmap所映射的区间。 | Cache |


## 运行机制

虚拟内存管理中，虚拟地址空间是连续的，但是其映射的物理内存并不一定是连续的，如下图所示。可执行程序加载运行，CPU访问虚拟地址空间的代码或数据时存在两种情况：

- CPU访问的虚拟地址所在的页，如V0，已经与具体的物理页P0做映射，CPU通过找到进程对应的页表条目（详见[虚实映射](../kernel/kernel-small-basic-inner-reflect.md)），根据页表条目中的物理地址信息访问物理内存中的内容并返回。

- CPU访问的虚拟地址所在的页，如V2，没有与具体的物理页做映射，系统会触发缺页异常，系统申请一个物理页，并把相应的信息拷贝到物理页中，并且把物理页的起始地址更新到页表条目中。此时CPU重新执行访问虚拟内存的指令便能够访问到具体的代码或数据。

  **图1** 内存映射示意图

  ![zh-cn_image_0000001179142959](figures/zh-cn_image_0000001179142959.png)


## 开发指导


### 接口说明

  **表3** 获取进程空间系列接口

| 接口名称| 描述 | 
| -------- | -------- | 
|  LOS_CurrSpaceGet | 获取当前进程空间结构体指针 |
| LOS_SpaceGet | 获取虚拟地址对应的进程空间结构体指针 |
| LOS_GetKVmSpace | 获取内核进程空间结构体指针 |
| LOS_GetVmallocSpace | 获取vmalloc空间结构体指针 |
| LOS_GetVmSpaceList | 获取进程空间链表指针 |


  **表4** 虚拟地址区间region相关的操作

| 接口名称| 描述 | 
| -------- | -------- |
| LOS_RegionFind | 在进程空间内查找并返回指定地址对应的虚拟地址区间 |
| LOS_RegionRangeFind | 在进程空间内查找并返回指定地址范围对应的虚拟地址区间 |
| LOS_IsRegionFileValid | 判断虚拟地址区间region是否与文件关联映射 |
| LOS_RegionAlloc | 申请空闲的虚拟地址区间 |
| LOS_RegionFree | 释放进程空间内特定的region |
| LOS_RegionEndAddr | 获取指定地址区间region的结束地址 |
| LOS_RegionSize | 获取region的大小 |
| LOS_IsRegionTypeFile | 判断是否为文件内存映射 |
| LOS_IsRegionPermUserReadOnly | 判断地址区间是否是用户空间只读属性 |
| LOS_IsRegionFlagPrivateOnly | 判断地址区间是否是具有私有属性 |
| LOS_SetRegionTypeFile | 设置文件内存映射属性 |
| LOS_IsRegionTypeDev | 判断是否为设备内存映射 |
| LOS_SetRegionTypeDev | 设置设备内存映射属性 |
| LOS_IsRegionTypeAnon | 判断是否为匿名映射 |
| LOS_SetRegionTypeAnon | 设置匿名映射属性 |

  **表5** 地址校验

| 接口名称| 描述 | 
| -------- | -------- |
| LOS_IsUserAddress | 判断地址是否在用户态空间 |
| LOS_IsUserAddressRange | 判断地址区间是否在用户态空间 |
| LOS_IsKernelAddress | 判断地址是否在内核空间 |
| LOS_IsKernelAddressRange | 判断地址区间是否在内核空间 |
| LOS_IsRangeInSpace | 判断地址区间是否在进程空间内 |

  **表6** vmalloc操作

| 接口名称| 描述 | 
| -------- | -------- |
| LOS_VMalloc | vmalloc申请内存 |
| LOS_VFree | vmalloc释放内存 |
| LOS_IsVmallocAddress | 判断地址是否是通过vmalloc申请的 |

  **表7** 内存申请系列接口

| 接口名称| 描述 | 
| -------- | -------- |
| LOS_KernelMalloc | 当申请的内存小于16KiB时，系统从堆内存池分配内存；当申请的内存超过16KiB时，系统分配多个连续物理页用于内存分配 |
| LOS_KernelMallocAlign | 申请具有对齐属性的内存，申请规则同LOS_KernelMalloc接口 |
| LOS_KernelFree | 释放由LOS_KernelMalloc和LOS_KernelMallocAlign接口申请的内存 |
| LOS_KernelRealloc | 重新分配由LOS_KernelMalloc和LOS_KernelMallocAlign接口申请的内存 |

  **表8** 其他

| 接口名称| 描述 | 
| -------- | -------- |
| LOS_PaddrQuery | 根据虚拟地址获取对应的物理地址 |
| LOS_VmSpaceFree | 释放进程空间，包括虚拟内存区间、页表等信息 |
| LOS_VmSpaceReserve | 在进程空间中预留一块内存空间 |
| LOS_VaddrToPaddrMmap | 将指定长度的物理地址区间与虚拟地址区间做映射，需提前申请物理地址区间 |


### 开发流程

虚拟内存相关接口的使用：

1. 根据进程空间获取的系列接口可以得到进程空间结构体，进而可以读取结构体相应信息。

2. 对虚拟地址区间做相关操作：
   - 通过LOS_RegionAlloc申请虚拟地址区间；
   - 通过LOS_RegionFind、LOS_RegionRangeFind可以查询是否存在相应的地址区间；
   - 通过LOS_RegionFree释放虚拟地址区间。

3. vmalloc接口及内存申请系列接口可以在内核中根据需要申请内存。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   >
   > 内存申请系列接口申请的内存要求物理内存是连续的，当系统内存无法满足大块连续内存的申请条件时会申请失败，一般适用于小块内存的申请；vmalloc相关接口申请的内存可以获得不连续的物理内存，但其是以页（当前系统一个页为4096字节）为单位的，当需要申请以页为整数倍的内存时可以通过vmalloc申请，例如文件系统中文件读取需要较大的缓存，便可以通过vmalloc相关接口申请内存。
