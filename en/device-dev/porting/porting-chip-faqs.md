# FAQs


## How Do I Mount the Heap Memory to the Kernel?

The following table describes the macros for configuring the kernel heap memory. You can configure them as required in the **target\_config.h** file.

**Table  1**  Macros for configuring the kernel heap memory

| Macro | Description |
| -------- | -------- |
| LOSCFG_SYS_EXTERNAL_HEAP | Specifies whether the internal kernel heap memory or the user heap memory will be used. The default value is **0** and indicates that the internal heap memory whose size is **0x10000** will be used. If you want to use the external heap memory, set this macro to **1**. |
| LOSCFG_SYS_HEAP_ADDR | Specifies the start address of the kernel heap memory. |
| LOSCFG_SYS_HEAP_SIZE | Specifies the size of the kernel heap memory, that is, size of the memory block specified by **LOSCFG_SYS_HEAP_ADDR**. |


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
>
> Ensure that the specified heap memory range is not used by other modules. Otherwise, functions of the heap memory will be damaged due to the heap memory corruption.
