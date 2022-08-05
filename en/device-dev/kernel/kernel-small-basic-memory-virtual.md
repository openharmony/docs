# Virtual Memory Management


## Basic Concepts

Virtual memory management is a technology used by computer systems to manage memory. Each process has a continuous virtual address space. The size of the virtual address space is determined by the number of CPU bits. The maximum addressing space for a 32-bit hardware platform ranges from 0 GiB to 4 GiB. The 4 GiB space is divided into two parts: 3 GiB higher-address space for the LiteOS-A kernel and 1 GiB lower-address space for user-mode processes. The virtual address space of each process space is independent, and the code and data do not affect each other.

The system divides the virtual memory into memory blocks called virtual pages. The size of a virtual page is generally 4 KiB or 64 KiB. The virtual page of the LiteOS-A kernel is 4 KiB by default. You can configure memory management units (MMUs) as required. The minimum unit of the virtual memory management is a page. A virtual address region in the LiteOS-A kernel can contain one virtual page or multiple virtual pages with contiguous addresses. Similarly, the physical memory is also divided by page, and each memory block is called page frame. The virtual address space is divided as follows: 3 GiB (**0x40000000** to **0xFFFFFFFF**) for the kernel space and 1 GiB (**0x01000000** to **0x3F000000**) for the user space. The following tables describe the virtual address plan. You can view or configure virtual addresses in **los_vm_zone.h**.

**Table 1** Kernel-mode addresses

| Zone| Description| Property|
| -------- | -------- | -------- |
| DMA&nbsp;zone | Addresses for direct memory access (DMA) of I/O devices.| Uncache |
| Normal&nbsp;zone | Addresses for loading the kernel code segment, data segment, heap, and stack.| Cache |
| high&nbsp;mem&nbsp;zone | Addresses for allocating contiguous virtual memory. The mapped physical memory blocks may not be contiguous.| Cache |

**Table 2** User-mode virtual addresses

| Zone| Description| Property|
| -------- | -------- | -------- |
| Code snippet| User-mode code segment address range.| Cache |
| Heap| User-mode heap address range.| Cache |
| Stack| User-mode stack address range.| Cache |
| Shared databases| Address range for loading the user-mode shared library, including the address range mapped by mmap.| Cache |


## Working Principles

In virtual memory management, the virtual address space is contiguous, but the mapped physical memory is not necessarily contiguous, as depicted in the following figure. When an executable program is loaded and runs, the CPU accesses the code or data in the virtual address space in the following two cases:

- If the page (for example, V0) containing the virtual address accessed by the CPU is mapped to a physical page (for example, P0), the CPU locates the page table entry corresponding to the process (for details, see  [Virtual-to-Physical Mapping](kernel-small-basic-inner-reflect.md)"), accesses the physical memory based on the physical address information in the page table entry, and returns the content.

- If the page (for example, V2) containing the virtual address accessed by the CPU is not mapped to a physical page, the system triggers a page missing fault, requests a physical page, copies the corresponding information to the physical page, and updates the start address of the physical page to the page table entry. Then, the CPU can access specific code or data by executing the instruction for accessing the virtual memory again.

  **Figure 1** Mapping between the virtual and physical memory addresses<br>

  ![](figures/mapping-between-the-virtual-and-physical-memory-addresses.png "mapping-between-the-virtual-and-physical-memory-addresses")


## Development Guidelines


### Available APIs

**Table 3** APIs of the virtual memory management module

| API| Description|
| -------- | -------- |
|  LOS_CurrSpaceGet | Obtains the pointer to the current process space structure.|
| LOS_SpaceGet | Obtains the pointer to the process space structure corresponding to the virtual address.|
| LOS_GetKVmSpace | Obtains the pointer to the kernel process space structure.|
| LOS_GetVmallocSpace | Obtains the pointer to the vmalloc space structure.|
| LOS_GetVmSpaceList | Obtains the pointer to the process space linked list.|

**Table 4** Operations related to the virtual address region

| API| Description|
| -------- | -------- |
| LOS_RegionFind | Searches for and returns the virtual address region corresponding to the specified address in the process space.|
| LOS_RegionRangeFind | Searches for and returns the virtual address region corresponding to the specified address range in the process space.|
| LOS_IsRegionFileValid | Checks whether the virtual address region is mapped to a file.|
| LOS_RegionAlloc | Requests a free virtual address region.|
| LOS_RegionFree | Releases a specific region in the process space.|
| LOS_RegionEndAddr | Obtains the end address of the specified address region.|
| LOS_RegionSize | Obtains the size of a region.|
| LOS_IsRegionTypeFile | Checks whether the address region is a file memory mapping.|
| LOS_IsRegionPermUserReadOnly | Checks whether the address region is read-only in the user space.|
| LOS_IsRegionFlagPrivateOnly | Checks whether the address region has private attributes.|
| LOS_SetRegionTypeFile | Sets the file memory mapping attributes. |
| LOS_IsRegionTypeDev | Checks whether the address region is device memory mapping.|
| LOS_SetRegionTypeDev | Sets the device memory mapping attributes. |
| LOS_IsRegionTypeAnon | Checks whether the address region is an anonymous mapping.|
| LOS_SetRegionTypeAnon | Sets the anonymous mapping attributes. |

**Table 5** APIs for address verification

| API| Description|
| -------- | -------- |
| LOS_IsUserAddress | Checks whether the address is in the user space.|
| LOS_IsUserAddressRange | Checks whether the address region is in the user space.|
| LOS_IsKernelAddress | Checks whether the address is in the kernel space.|
| LOS_IsKernelAddressRange | Checks whether the address region is in the kernel space.|
| LOS_IsRangeInSpace | Checks whether the address region is in the process space.|

**Table 6** APIs for vmalloc operations

| API| Description|
| -------- | -------- |
| LOS_VMalloc | Requests memory using **vmalloc**.|
| LOS_VFree | Releases memory using **vmalloc**.|
| LOS_IsVmallocAddress | Checks whether the address is requested using **vmalloc**. |

**Table 7** APIs for memory allocation

| API| Description|
| -------- | -------- |
| LOS_KernelMalloc | Allocates memory from the heap memory pool if the requested memory is less than 16 KiB; allocates multiple contiguous physical pages if the requested memory is greater than 16 KiB. |
| LOS_KernelMallocAlign | Allocates memory with alignment attributes. The allocation rule is the same as that of the **LOS_KernelMalloc** API.|
| LOS_KernelFree | Releases the memory requested by **LOS_KernelMalloc** and **LOS_KernelMallocAlign**.|
| LOS_KernelRealloc | Reallocates the memory requested by **LOS_KernelMalloc** and **LOS_KernelMallocAlign**.|

**Table 8** Other APIs

| API | Description |
| -------- | -------- |
| LOS_PaddrQuery | Obtains the physical address based on the virtual address. |
| LOS_VmSpaceFree | Releases the process space, including the virtual memory region and page table. |
| LOS_VmSpaceReserve | Reserves a memory space in the process space. |
| LOS_VaddrToPaddrMmap | Maps the physical address region with the specified length to a virtual address region. You need to request the physical address region before the operation. |


### How to Develop

To use APIs related to virtual memory:

1. Obtain the process space structure using the APIs for obtaining the process space, and access the structure information.
2. Perform the following operations on the virtual address region: 
   - Call **LOS_RegionAlloc** to request a virtual address region.
   - Call **LOS_RegionFind** and **LOS_RegionRangeFind** to check whether the corresponding address region exists.
   - Call **LOS_RegionFree** to release a virtual address region.

3. Call **vmalloc** APIs (see table 6) and memory allocation APIs (see table 7) to apply for memory in the kernel as required.

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> 
> The physical memory requested by using the memory allocation APIs must be contiguous. If the system cannot provide a large number of contiguous memory blocks, the request fails. Therefore, the memory allocation APIs are recommended for requesting small memory blocks. 
>
> **vmalloc** APIs are recommended for requesting non-contiguous physical memory. However, the memory is allocated in the unit of pages (4096 bytes/page in the current system). If you want memory that is an integer multiple of a page, you can use **vmalloc** APIs. For example, you can use **vmalloc** to request memory for file reading in a file system, which demands a large cache.
