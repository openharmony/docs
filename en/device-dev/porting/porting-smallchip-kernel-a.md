# LiteOS Cortex-A

## Overview

### Porting Scenario

LiteOS Cortex-A supports the ARMv7-a instruction set architecture. If you are porting the kernel to a chipset that uses ARMv7-a, you can directly perform basic adaptation. Otherwise, you need to add support for the architecture used by the chipset. This process is complex and not covered in this document.

### Directory Specifications

For details about the LiteOS Cortex-A directory specifications, see  [LiteOS Cortex-A Overview](https://gitee.com/openharmony/kernel_liteos_a).

## Adaptation Process

LiteOS Cortex-A provides the system initialization process and custom configuration options required for system running. During porting, pay attention to the functions related to hardware configuration in the initialization process.

The LiteOS Cortex-A initialization process consists of seven steps:

1.  Add the  **target\_config.h** file and compile the macros **DDR\_MEM\_ADDR** and **DDR\_MEM\_SIZE**, which indicate the start address and length of the board memory, respectively. The prelinker script **board.ld.S** creates the linker script **board.ld** based on the two macros.
2.  Define **g\_archMmuInitMapping**, the global array of MMU mappings, to specify the memory segment attributes and the virtual-to-physical address mappings. The memory mapping will be established based on this array during kernel startup.
3.  If there are multiple cores, define **struct SmpOps**, the handle to the secondary core operation function. The **SmpOps-\>SmpCpuOn** function needs to implement the feature of waking up a secondary core. Then, define the **SmpRegFunc** function and call the **LOS\_SmpOpsSet** interface to register the handle. The registration process is completed by starting the framework using **LOS\_MODULE\_INIT\(SmpRegFunc, LOS\_INIT\_LEVEL\_EARLIEST\)**.
4.  Create a kernel image based on the linker script **board.ld**.
5.  Perform operations such as initialization of the interrupt vector table and MMU page table are performed in the assembly files: **reset\_vector\_up.S** and **reset\_vector\_mp.S**, from which a single-core CPU and a multi-core CPU start, respectively.
6.  Enable the assembly code in **reset\_vector.S** to jump to the **main** function of the C programming language to initialize the hardware clock, software timer, memory, and tasks. This process depends on the feature macro configuration in **target\_config.h**. Then, create the **SystemInit** task to be implemented in the board code, with **OsSchedStart\(\)** enabled for task scheduling.
7.  Call the **DeviceManagerStart** function to initialize the HDF driver. This process is implemented by calling the driver configuration file **hdf.hcs** and drivers source code in the board code.

The figure below shows the overall initialization process.

**Figure 1** Overall initialization process
![](figures/overall-initialization-process.png "overall-initialization-process")

As can be seen from preceding figure, kernel basic adaptation involves the following parts:

- Adding the **target\_config.h** file, which contains board hardware parameters and feature parameters described in the following table:

  **Table 1** Parameters in the target\_config.h file

  | Parameter               | Description                                                 |
  | ----------------------- | ----------------------------------------------------------- |
  | OS_SYS_CLOCK            | System cycle frequency                                      |
  | DDR_MEM_ADDR            | Start address of the system memory                          |
  | DDR_MEM_SIZE            | Size of the system memory                                   |
  | PERIPH_PMM_BASE         | Base address of the peripheral register                     |
  | PERIPH_PMM_SIZE         | Size of the peripheral register                             |
  | OS_HWI_MIN              | Minimum number of system interrupts                         |
  | OS_HWI_MAX              | Maximum number of system interrupts                         |
  | NUM_HAL_INTERRUPT_UART0 | UART0 interrupt ID                                          |
  | UART0_REG_BASE          | UART0 register base address                                 |
  | GIC_BASE_ADDR           | Base address of the GIC interrupt register                  |
  | GICD_OFFSET             | Offset address of the GICD relative to the GIC base address |
  | GICC_OFFSET             | Offset address of the GICC relative to the GIC base address |

  

- Implementing the **SystemInit** function to initialize services in the user space. Figure 2 shows a typical initialization scenario.

  **Figure  2**  Service startup process

  ![](figures/service-startup-process.png "service-startup-process")

-   Implementing the **main** function for basic kernel initialization and initialization of services in the board kernel space.  Figure 3 shows the initialization process, where the kernel startup framework takes the lead in the initialization process. The light blue part in the figure indicates the phase in which external modules can be registered and started in the startup framework.

    >![](../public_sys-resources/icon-caution.gif) **CAUTION**
    >
    >Modules at the same layer cannot depend on each other.

  **Figure 3**  Kernel startup framework
  
  ![](figures/kernel-startup-framework.jpg "kernel-startup-framework") 
  
  **Table  2**  Startup framework layers    

| Layer                         | Description                                                  |
| ----------------------------- | ------------------------------------------------------------ |
| LOS_INIT_LEVEL_EARLIEST       | Earliest initialization.<br>This layer does not depend on the architecture. The board and subsequent modules, such as the Trace module, will initialize the software-only modules on which they depend. |
| LOS_INIT_LEVEL_ARCH_EARLY     | Early initialization of the architecture.<br/>This layer depends on the architecture. Subsequent modules will initialize the modules on which they depend. It is recommended that functions not required for startup be placed at the **LOS_INIT_LEVEL_ARCH** layer. |
| LOS_INIT_LEVEL_PLATFORM_EARLY | Early initialization of the platform.<br/>This layer depends on the board platform and drivers. Subsequent modules will initialize the modules on which they depend. It is recommended that functions required for startup be placed at the **LOS_INIT_LEVEL_PLATFORM** layer.<br/>Example: UART module |
| LOS_INIT_LEVEL_KMOD_PREVM     | Kernel module initialization before memory initialization.<br/>This layer involves initialization of the modules that need to be enabled before memory initialization. |
| LOS_INIT_LEVEL_VM_COMPLETE    | Initialization after the basic memory is ready.<br/>This layer involves initialization of the modules that need to be enabled and do not depend on the inter-process communication mechanism and system processes.<br/>Example: shared memory function |
| LOS_INIT_LEVEL_ARCH           | Late initialization of the architecture.<br/>This layer depends on the architecture extension function. Subsequent modules will initialize the modules on which they depend. |
| LOS_INIT_LEVEL_PLATFORM       | Late initialization of the platform.<br/>This layer depends on the board platform and drivers. Subsequent modules will initialize the modules on which they depend.<br/>Example: initialization of the driver kernel abstraction layer (MMC and MTD) |
| LOS_INIT_LEVEL_KMOD_BASIC     | Initialization of the kernel basic modules.<br/>This layer is used to initialize the basic modules that can be detached from the kernel.<br/>Example: VFS initialization |
| LOS_INIT_LEVEL_KMOD_EXTENDED  | Initialization of the kernel extended modules.<br/>This layer is used to initialize the extended modules that can be detached from the kernel.<br/>Example: system call initialization, ProcFS initialization, Futex initialization, HiLog initialization, HiEvent initialization, and LiteIPC initialization |
| LOS_INIT_LEVEL_KMOD_TASK      | Kernel task creation.<br/>This layer can be used to create kernel tasks (kernel thread and software timer tasks).<br/>Example: creation of the resident resource reclaiming task, SystemInit task, and CPU usage statistics task |

Adaptation for board porting. Focus on layers between  **LOS\_INIT\_LEVEL\_ARCH**  and  **LOS\_INIT\_LEVEL\_KMOD\_TASK**  and try to divide the initialization process into as many phases as possible for refined registration.
    
  >![](../public_sys-resources/icon-note.gif) **NOTE**
  >
  >Modules at the same layer cannot depend on each other. It is recommended that a new module be split based on the preceding startup phase and be registered and started as required.
  >
  >You can view the symbol table in the **.rodata.init.kernel.\*** segment of the **OHOS\_Image.map** file generated after the build is complete, so as to learn about the initialization entry of each module that has been registered with the kernel startup framework and check whether the newly registered initialization entry takes effect.


## Programming Example

In the board SDK file:

```
/* Header file of the kernel startup framework */
#include "los_init.h"
......

/* Initialization function of the new module */
unsigned int OsSampleModInit(void)
{
    PRINTK("OsSampleModInit SUCCESS!\n");
    ......
}
......
/* Register the new module at the target layer of the startup framework. */
LOS_MODULE_INIT(OsSampleModInit, LOS_INIT_LEVEL_KMOD_EXTENDED);
```

## Verification

```
main core booting up...
OsSampleModInit SUCCESS!
releasing 1 secondary cores
cpu 1 entering scheduler
cpu 0 entering scheduler
```

According to the preceding information displayed during the system startup, the kernel calls the initialization function of the registered module during the startup to initialize the module.

The system enters the kernel-space shell and the task commands can be properly executed.

```
OHOS # help
***shell commands:*

arp           cat           cd            chgrp         chmod         chown         cp            cpup          
date          dhclient      dmesg         dns           format        free          help          hwi           
ifconfig      ipdebug       kill          log           ls            lsfd          memcheck      mkdir         
mount         netstat       oom           partinfo      partition     ping          ping6         pmm           
pwd           reset         rm            rmdir         sem           shm           stack         statfs        
su            swtmr         sync          systeminfo    task          telnet        touch         umount        
uname         v2p           virstatfs     vmm           watch         writeproc     

```

