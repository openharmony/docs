# Typical Memory Problems


## Use After Free \(UAF\)<a name="section4427132815445"></a>

-   Requested memory block less than or equal to 0x1c000 bytes:

    After the memory is released:

    Read operation: If the magic number \(0xFEFEFEFE\) is read from the memory block released, UAF occurs.

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >After  **free**  is called, the heap memory will not be released to the heap memory pool immediately. Instead, the heap memory is placed in a queue with a fixed length and filled with the magic number 0xFE. When the queue is full, the memory block first placed in the queue is released to the heap memory pool first.

    Write operation: The memory debugging module cannot detect UAF errors from write operations.


-   Requested memory block greater than 0x1c000 bytes:

    The heap memory greater than 0x1c000 bytes must be requested by calling the  **mmap**  API via  **malloc**. If the heap memory is accessed after being released, the user program will become abnormal \(because the memory region has been unmapped\).


## Double Free<a name="section827194818458"></a>

Double free errors occur when  **free\(\)**  is called more than once with the same memory address as an argument. When a double free error occurs, the user program exits unexpectedly.

## Heap Memory Node Corrupted<a name="section1763741216461"></a>

-   Requested memory block less than or equal to 0x1c000 bytes:

    When a heap memory node is corrupted, the user program exits unexpectedly, and the call stack that requests the heap memory of the node corrupted is output. The memory debugging module, however, cannot debug the memory corrupted by a wild pointer. For example, if the user program mem\_check has heap memory overwriting, you can use the command line to obtain the possible location of the memory corruption.

    ```
    OHOS # ./mem_check --mwatch  
    OHOS # 
    ==PID:6== Memory integrity information:
        [TID:28 allocated addr: 0x272e1ea0, size: 0x120] The possible attacker was allocated from:
            #00: <malloc+0x808>[0x640e8] -> /lib/libc.so
            #01: <threadFunc1+0x7c>[0x21d0] -> mem_check 
    ```

    You can use the call stack parsing script to parse the call stack information.


-   Requested memory block greater than 0x1c000 bytes:

    When a large memory block \(greater than 0x1c000 bytes\) is requested by calling the  **mmap**  API via  **malloc**, one more page of  **PAGE\_SIZE**  is allocated at the start and end of the memory region. The two pages are neither readable nor writeable. Any read or write operation to the pages may cause an exception of the user program.


