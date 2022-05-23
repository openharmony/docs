# Basic Concepts

Memory management, one of the core modules of the OS, manages the memory resources of the system. Memory management primarily involves initializing, allocating, and releasing memory.

While the OS is running, the memory management module manages the memory usage of users and the OS by allocating and releasing memory. This helps achieve the optimal memory usage and usage efficiency and minimize memory fragments.

The OpenHarmony LiteOS-M kernel memory management involves static and dynamic memory management, and provides functions such as memory initialization, allocation, and release.

-   Dynamic memory: memory blocks of user-specified size allocated in the dynamic memory pool.
    -   Advantage: Resources are allocated on demand.
    -   Disadvantage: Fragments may occur in the memory pool.

-   Static memory: memory blocks of the fixed size \(preset during initialization\) allocated in the static memory pool.
    -   Advantage: Memory is allocated and released efficiently, and there is no fragment in the static memory pool.
    -   Disadvantage: Only the memory blocks of the fixed size can be allocated. Memory cannot be allocated on demand.


