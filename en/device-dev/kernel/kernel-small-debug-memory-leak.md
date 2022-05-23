# Memory Leak Check


## Basic Concepts<a name="section1026719436293"></a>

As an optional function of the kernel, memory leak check is used to locate dynamic memory leak problems. After this function is enabled, the dynamic memory mechanism automatically records the link registers \(LRs\) used when memory is allocated. If a memory leak occurs, the recorded information helps locate the memory allocated for further analysis.

## Function Configuration<a name="section13991354162914"></a>

1.  **LOSCFG\_MEM\_LEAKCHECK**: specifies the setting of the memory leak check. This function is disabled by default. To enable this function, configure it in  **Debug-\> Enable Function call stack of Mem operation recorded**.
2.  **LOS\_RECORD\_LR\_CNT**: number of LRs recorded. The default value is  **3**. Each LR consumes the memory of  **sizeof\(void \*\)**  bytes.
3.  **LOS\_OMIT\_LR\_CNT**: number of ignored LRs. The default value is  **2**, which indicates that LRs are recorded from the time when  **LOS\_MemAlloc**  is called. You can change the value based on actual requirements. This macro is configured because:
    -   **LOS\_MemAlloc**  is also called internally.
    -   **LOS\_MemAlloc**  may be encapsulated externally.
    -   The number of LRs configured by  **LOS\_RECORD\_LR\_CNT**  is limited.


Correctly setting this macro can ignore invalid LRs and reduce memory consumption.

## Development Guidelines<a name="section95828159308"></a>

### How to Develop<a name="section369844416304"></a>

Memory leak check provides a method to check for memory leak in key code logic. If this function is enabled, LR information is recorded each time when memory is allocated. When  **LOS\_MemUsedNodeShow**  is called before and after the code snippet is checked, information about all nodes that have been used in the specified memory pool is printed. You can compare the node information. The newly added node information indicates the node where the memory leak may occur. You can locate the code based on the LR and further check whether a memory leak occurs.

The node information output by calling  **LOS\_MemUsedNodeShow**  is in the following format: 

-   Each line contains information about a node. 
-   The first column indicates the node address, based on which you can obtain complete node information using a tool such as a GNU Debugger \(GDB\). 
-   The second column indicates the node size, which is equal to the node header size plus the data field size. 
-   Columns 3 to 5 list the LR addresses. 

You can determine the specific memory location of the node based on the LR addresses and the assembly file.

```
node        size   LR[0]      LR[1]       LR[2]  
0x10017320: 0x528 0x9b004eba  0x9b004f60  0x9b005002 
0x10017848: 0xe0  0x9b02c24e  0x9b02c246  0x9b008ef0 
0x10017928: 0x50  0x9b008ed0  0x9b068902  0x9b0687c4 
0x10017978: 0x24  0x9b008ed0  0x9b068924  0x9b0687c4
0x1001799c: 0x30  0x9b02c24e  0x9b02c246  0x9b008ef0 
0x100179cc: 0x5c  0x9b02c24e  0x9b02c246  0x9b008ef0 
```

>![](../public_sys-resources/icon-caution.gif) **CAUTION:** 
>Enabling memory leak check affects memory application performance. LR addresses will be recorded for each memory node, increasing memory overhead.

### Development Example<a name="section460801313313"></a>

This example implements the following:

1.  Call  **OsMemUsedNodeShow**  to print information about all nodes.
2.  Simulate a memory leak by requesting memory without releasing it.
3.  Call  **OsMemUsedNodeShow**  to print information about all nodes.
4.  Compare the logs to obtain information about the node where a memory leak occurred.
5.  Locate the code based on the LR address.

**Sample Code**

The sample code is as follows:

```
#include <stdio.h>
#include <string.h>
#include "los_memory.h"
#include "los_config.h"

void MemLeakTest(void)
{
    OsMemUsedNodeShow(LOSCFG_SYS_HEAP_ADDR);
    void *ptr1 = LOS_MemAlloc(LOSCFG_SYS_HEAP_ADDR, 8);
    void *ptr2 = LOS_MemAlloc(LOSCFG_SYS_HEAP_ADDR, 8);
    OsMemUsedNodeShow(LOSCFG_SYS_HEAP_ADDR);
}
```

**Verification**

The log is as follows:

```
node         size   LR[0]       LR[1]       LR[2]   
0x20001b04:  0x24   0x08001a10  0x080035ce  0x080028fc 
0x20002058:  0x40   0x08002fe8  0x08003626  0x080028fc 
0x200022ac:  0x40   0x08000e0c  0x08000e56  0x0800359e 
0x20002594:  0x120  0x08000e0c  0x08000e56  0x08000c8a 
0x20002aac:  0x56   0x08000e0c  0x08000e56  0x08004220 

node         size   LR[0]       LR[1]       LR[2]   
0x20001b04:  0x24   0x08001a10  0x080035ce  0x080028fc 
0x20002058:  0x40   0x08002fe8  0x08003626  0x080028fc 
0x200022ac:  0x40   0x08000e0c  0x08000e56  0x0800359e 
0x20002594:  0x120  0x08000e0c  0x08000e56  0x08000c8a 
0x20002aac:  0x56   0x08000e0c  0x08000e56  0x08004220 
0x20003ac4:  0x1d   0x08001458  0x080014e0  0x080041e6 
0x20003ae0:  0x1d   0x080041ee  0x08000cc2  0x00000000 
```

The difference between the two logs is as follows. The following memory nodes are suspected to have blocks with a memory leak.

```
0x20003ac4:  0x1d   0x08001458  0x080014e0  0x080041e6 
0x20003ae0:  0x1d   0x080041ee  0x08000cc2  0x00000000 
```

The following is part of the assembly file:

```
                MemLeakTest:
  0x80041d4: 0xb510         PUSH     {R4, LR}
  0x80041d6: 0x4ca8         LDR.N    R4, [PC, #0x2a0]       ; g_memStart
  0x80041d8: 0x0020         MOVS     R0, R4
  0x80041da: 0xf7fd 0xf93e  BL       LOS_MemUsedNodeShow    ; 0x800145a
  0x80041de: 0x2108         MOVS     R1, #8
  0x80041e0: 0x0020         MOVS     R0, R4
  0x80041e2: 0xf7fd 0xfbd9  BL       LOS_MemAlloc           ; 0x8001998
  0x80041e6: 0x2108         MOVS     R1, #8
  0x80041e8: 0x0020         MOVS     R0, R4
  0x80041ea: 0xf7fd 0xfbd5  BL       LOS_MemAlloc           ; 0x8001998
  0x80041ee: 0x0020         MOVS     R0, R4
  0x80041f0: 0xf7fd 0xf933  BL       LOS_MemUsedNodeShow    ; 0x800145a
  0x80041f4: 0xbd10         POP      {R4, PC}
  0x80041f6: 0x0000         MOVS     R0, R0
```

The memory node addressed by  **0x080041ee**  is not released after being requested in  **MemLeakTest**.

