# Static Memory

## Working Principles

The static memory is a static array. The block size in the static memory pool is set during initialization and cannot be changed after initialization.

The static memory pool consists of a control block **LOS\_MEMBOX\_INFO** and several memory blocks **LOS\_MEMBOX\_NODE** of the same size. The control block is located at the head of the memory pool and used for memory block management. It contains the memory block size \(**uwBlkSize**\), number of memory blocks \(**uwBlkNum**\), number of allocated memory blocks \(**uwBlkCnt**\), and free list \(**stFreeList**\). Memory is allocated and released by block size. Each memory block contains the pointer **pstNext** that points to the next memory block.

**Figure 1** Static memory 
![](figures/static-memory.png "static-memory")

## Development Guidelines

### When to Use

Use static memory allocation to obtain memory blocks of the fixed size. When the memory is no longer required, release the static memory.

### Available APIs

The following table describes APIs available for OpenHarmony LiteOS-M static memory management. For more details about the APIs, see the API reference.

**Table 1** APIs of the static memory module

<a name="table1415203765610"></a>
<table><thead align="left"><tr id="row134151837125611"><th class="cellrowborder" valign="top" width="16.19161916191619%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="22.472247224722473%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="61.33613361336133%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row0415737175610"><td class="cellrowborder" valign="top" width="16.19161916191619%" headers="mcps1.2.4.1.1 "><p id="p2990613114416"><a name="p2990613114416"></a><a name="p2990613114416"></a>Initializing the static memory pool</p>
</td>
<td class="cellrowborder" valign="top" width="22.472247224722473%" headers="mcps1.2.4.1.2 "><p id="p169901113194416"><a name="p169901113194416"></a><a name="p169901113194416"></a>LOS_MemboxInit</p>
</td>
<td class="cellrowborder" valign="top" width="61.33613361336133%" headers="mcps1.2.4.1.3 "><p id="p5990113174414"><a name="p5990113174414"></a><a name="p5990113174414"></a>Initialize a static memory pool and sets the start address, total size, and size of each memory block based on the input parameters.</p>
</td>
</tr>
<tr id="row1841519376561"><td class="cellrowborder" valign="top" width="16.19161916191619%" headers="mcps1.2.4.1.1 "><p id="p9367164904413"><a name="p9367164904413"></a><a name="p9367164904413"></a>Clearing static memory blocks</p>
</td>
<td class="cellrowborder" valign="top" width="22.472247224722473%" headers="mcps1.2.4.1.2 "><p id="p103671549144411"><a name="p103671549144411"></a><a name="p103671549144411"></a>LOS_MemboxClr</p>
</td>
<td class="cellrowborder" valign="top" width="61.33613361336133%" headers="mcps1.2.4.1.3 "><p id="p18367184916448"><a name="p18367184916448"></a><a name="p18367184916448"></a>Clears the memory blocks allocated from the static memory pool.</p>
</td>
</tr>
<tr id="row1187514443616"><td class="cellrowborder" rowspan="2" valign="top" width="16.19161916191619%" headers="mcps1.2.4.1.1 "><p id="p64541711458"><a name="p64541711458"></a><a name="p64541711458"></a>Allocating or releasing static memory</p>
</td>
<td class="cellrowborder" valign="top" width="22.472247224722473%" headers="mcps1.2.4.1.2 "><p id="p84547710452"><a name="p84547710452"></a><a name="p84547710452"></a>LOS_MemboxAlloc</p>
</td>
<td class="cellrowborder" valign="top" width="61.33613361336133%" headers="mcps1.2.4.1.3 "><p id="p5454177164520"><a name="p5454177164520"></a><a name="p5454177164520"></a>Allocates a memory block from a specified static memory pool.</p>
</td>
</tr>
<tr id="row1745415527441"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p645457204512"><a name="p645457204512"></a><a name="p645457204512"></a>LOS_MemboxFree</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p545415704514"><a name="p545415704514"></a><a name="p545415704514"></a>Releases a memory block allocated from the static memory pool.</p>
</td>
</tr>
<tr id="row19101718144518"><td class="cellrowborder" rowspan="2" valign="top" width="16.19161916191619%" headers="mcps1.2.4.1.1 "><p id="p15927427144615"><a name="p15927427144615"></a><a name="p15927427144615"></a>Obtaining or printing static memory pool information</p>
</td>
<td class="cellrowborder" valign="top" width="22.472247224722473%" headers="mcps1.2.4.1.2 "><p id="p792715277464"><a name="p792715277464"></a><a name="p792715277464"></a>LOS_MemboxStatisticsGet</p>
</td>
<td class="cellrowborder" valign="top" width="61.33613361336133%" headers="mcps1.2.4.1.3 "><p id="p139271327114620"><a name="p139271327114620"></a><a name="p139271327114620"></a>Obtains information about a specified static memory pool, including the total number of memory blocks in the memory pool, number of allocated memory blocks, and size of each memory block.</p>
</td>
</tr>
<tr id="row1346314166464"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p8927102754619"><a name="p8927102754619"></a><a name="p8927102754619"></a>LOS_ShowBox</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p49274279460"><a name="p49274279460"></a><a name="p49274279460"></a>Prints information about all nodes in a specified static memory pool (the print level is <strong id="b1937798153019"><a name="b1937798153019"></a><a name="b1937798153019"></a>LOS_INFO_LEVEL</strong>). The information includes the start address of the memory pool, memory block size, total number of memory blocks, start address of each idle memory block, and start addresses of all memory blocks.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE**<br/> 
>The number of memory blocks in the memory pool after initialization is not equal to the total memory size divided by the memory block size. The reason is the control block of the memory pool and the control header of each memory block have memory overheads. When setting the total memory size, you need to consider these factors.

### How to Develop

The typical development process of static memory is as follows:

1.  Plan a memory space as the static memory pool.
2.  Call the **LOS\_MemboxInit** API to initialize the static memory pool.

    During initialization, the memory space specified by the input parameter is divided into multiple blocks \(the number of blocks depends on the total static memory size and the block size\). Insert all memory blocks to the free list, and place the control header at the beginning of the memory.

3.  Call the **LOS\_MemboxAlloc** API to allocate static memory.

    The system allocates the first free memory block from the free list and returns the start address of this memory block.

4.  Call the **LOS\_MemboxClr** API.

    Clear the memory block corresponding to the address contained in the input parameter.

5.  Call the **LOS\_MemboxFree** API.

    Add the memory block to the free list.


### Development Example

This example implements the following:

1.  Initialize a static memory pool.
2.  Allocate a memory block from the static memory pool.
3.  Store a piece of data in a memory block.
4.  Print the data in the memory block.
5.  Clear the data in the memory block.
6.  Release the memory block.

    The sample code is as follows:


```
#include "los_membox.h"

VOID Example_StaticMem(VOID)
{
    UINT32 *mem = NULL;
    UINT32 blkSize = 10;
    UINT32 boxSize = 100;
    UINT32 boxMem[1000];
    UINT32 ret;

 /* Initialize the memory pool.*/
    ret = LOS_MemboxInit(&boxMem[0], boxSize, blkSize);
    if(ret != LOS_OK) {
        printf("Membox init failed!\n");
        return;
    } else {
        printf("Membox init success!\n");
    }

    /* Request a memory block.*/
    mem = (UINT32 *)LOS_MemboxAlloc(boxMem);
    if (NULL == mem) {
        printf("Mem alloc failed!\n");
        return;
    }
    printf("Mem alloc success!\n");

    /* Assign a value.*/
    *mem = 828;
    printf("*mem = %d\n", *mem);

 /* Clear data in the memory block. */
    LOS_MemboxClr(boxMem, mem);
    printf("Mem clear success \n *mem = %d\n", *mem);

    /* Release the memory.*/
    ret = LOS_MemboxFree(boxMem, mem);
    if (LOS_OK == ret) {
        printf("Mem free success!\n");
    } else {
        printf("Mem free failed!\n");
    }

    return;
}
```

### Verification

The output is as follows:

```
Membox init success!
Mem alloc success!
*mem = 828
Mem clear success   
*mem = 0
Mem free success!
```

