# Memory Corruption Check


## Basic Concepts<a name="section17368154517335"></a>

As an optional function of the kernel, memory corruption check is used to check the integrity of a dynamic memory pool. This mechanism can detect memory corruption errors in the memory pool in a timely manner and provide alerts. It helps reduce problem locating costs and increase troubleshooting efficiency.

## Function Configuration<a name="section4696190123420"></a>

**LOSCFG\_BASE\_MEM\_NODE\_INTEGRITY\_CHECK**: specifies the setting of the memory corruption check. This function is disabled by default. To enable this function, configure it in  **Debug-\> Enable integrity check or not**.

If this macro is enabled, the memory pool integrity will be checked in real time upon each memory allocation.

If this macro is not enabled, you can call  **LOS\_MemIntegrityCheck**  to check the memory pool integrity when required. Using  **LOS\_MemIntegrityCheck**  does not affect the system performance. In addition, the check accuracy decreases because the node header does not contain the magic number \(which is available only when  **LOSCFG\_BASE\_MEM\_NODE\_INTEGRITY\_CHECK**  is enabled\).

This check only detects the corrupted memory node and provides information about the previous node \(because memory is contiguous, a node is most likely corrupted by the previous node\). To further determine the location where the previous node is requested, you need to enable the memory leak check and use LRs to locate the fault.

>![](../public_sys-resources/icon-caution.gif) **CAUTION:** 
>If memory corruption check is enabled, a magic number is added to the node header, which increases the size of the node header. The real-time integrity check has a great impact on the performance. In performance-sensitive scenarios, you are advised to disable this function and use  **LOS\_MemIntegrityCheck**  to check the memory pool integrity.

## Development Guidelines<a name="section672362973417"></a>

### How to Develop<a name="section026014863416"></a>

Check for memory corruption by calling  **LOS\_MemIntegrityCheck**. If no memory corruption occurs,  **0**  is returned and no log is output. If memory corruption occurs, the related log is output. For details, see the output of the following example.

### Development Example<a name="section186311302356"></a>

This example implements the following:

1.  Requests two physically adjacent memory blocks.
2.  Calls  **memset**  to construct an out-of-bounds access and overwrites the first four bytes of the next node.
3.  Calls  **LOS\_MemIntegrityCheck**  to check whether memory corruption occurs.

**Sample Code**

The sample code is as follows:

```
#include <stdio.h>
#include <string.h>
#include "los_memory.h"
#include "los_config.h"

void MemIntegrityTest(void)
{
 /* Request two physically adjacent memory blocks.*/
    void *ptr1 = LOS_MemAlloc(LOSCFG_SYS_HEAP_ADDR, 8);
    void *ptr2 = LOS_MemAlloc(LOSCFG_SYS_HEAP_ADDR, 8);
 /* Construct an out-of-bounds access to cause memory corruption. The memory block of the first node is 8 bytes. Clearing 12 bytes overwrites the header of the second memory node. */
    memset(ptr1, 0, 8 + 4);
    LOS_MemIntegrityCheck(LOSCFG_SYS_HEAP_ADDR);
}
```

**Verification**

The log is as follows:

```
[ERR][OsMemMagicCheckPrint], 2028, memory check error!
memory used but magic num wrong, magic num = 0x00000000 /* Error information, indicating that the first four bytes, that is, the magic number, of the next node are corrupted.*/

 broken node head: 0x20003af0  0x00000000  0x80000020, prev node head: 0x20002ad4  0xabcddcba  0x80000020   
/* Key information about the corrupted node and its previous node, including the address of the previous node, magic number of the node, and sizeAndFlag of the node. In this example, the magic number of the corrupted node is cleared. */

 broken node head LR info:  /* The node LR information can be output only after the memory leak check is enabled.*/
 LR[0]:0x0800414e
 LR[1]:0x08000cc2
 LR[2]:0x00000000

 pre node head LR info:   /* Based on the LR information, you can find where the previous node is requested in the assembly file and then perform further analysis.*/
 LR[0]:0x08004144
 LR[1]:0x08000cc2
 LR[2]:0x00000000
[ERR]Memory interity check error, cur node: 0x20003b10, pre node: 0x20003af0 /* Addresses of the corrupted node and its previous node*/
```

