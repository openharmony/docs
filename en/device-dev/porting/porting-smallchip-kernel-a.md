# LiteOS Cortex-A<a name="EN-US_TOPIC_0000001200171989"></a>

## Overview<a name="section14876256185510"></a>

### Porting Scenario<a name="section1986014410569"></a>

LiteOS Cortex-A supports the ARMv7-a instruction set architecture. If you are porting the kernel to a chipset that uses ARMv7-a, you can directly perform basic adaptation. Otherwise, you need to add support for the architecture used by the chipset. This process is complex and not covered in this document.

### Directory Specifications<a name="section10916181716564"></a>

For details about the LiteOS Cortex-A directory specifications, see  [LiteOS Cortex-A Overview](https://gitee.com/openharmony/kernel_liteos_a).

## Adaptation Process<a name="section814974018565"></a>

LiteOS Cortex-A provides the system initialization process and custom configuration options required for system running. During porting, pay attention to the functions related to hardware configuration in the initialization process.

The LiteOS Cortex-A initialization process consists of seven steps:

1.  Add the  **target\_config.h**  file and compile the macros  **DDR\_MEM\_ADDR**  and  **DDR\_MEM\_SIZE**, which indicate the start address and length of the board memory, respectively. The prelinker script  **board.ld.S**  creates the linker script  **board.ld**  based on the two macros.
2.  Define  **g\_archMmuInitMapping**, the global array of MMU mappings, to specify the memory segment attributes and the virtual-to-physical address mappings. The memory mapping will be established based on this array during kernel startup.
3.  If there are multiple cores, define  **struct SmpOps**, the handle to the secondary core operation function. The  **SmpOps-\>SmpCpuOn**  function needs to implement the feature of waking up a secondary core. Then, define the  **SmpRegFunc**  function and call the  **LOS\_SmpOpsSet**  interface to register the handle. The registration process is completed by starting the framework using  **LOS\_MODULE\_INIT\(SmpRegFunc, LOS\_INIT\_LEVEL\_EARLIEST\)**.
4.  Create a kernel image based on the linker script  **board.ld**.
5.  Perform operations such as initialization of the interrupt vector table and MMU page table are performed in the assembly files:  **reset\_vector\_up.S**  and  **reset\_vector\_mp.S**, from which a single-core CPU and a multi-core CPU start, respectively.
6.  Enable the assembly code in  **reset\_vector.S**  to jump to the  **main**  function of the C programming language to initialize the hardware clock, software timer, memory, and tasks. This process depends on the feature macro configuration in  **target\_config.h**. Then, create the  **SystemInit**  task to be implemented in the board code, with  **OsSchedStart\(\)**  enabled for task scheduling.
7.  Call the  **DeviceManagerStart**  function to initialize the HDF driver. This process is implemented by calling the driver configuration file  **hdf.hcs**  and drivers source code in the board code.

The figure below shows the overall initialization process.

**Figure  1**  Overall initialization process<a name="fig68283211926"></a>  
![](figures/overall-initialization-process.png "overall-initialization-process")

As can be seen from preceding figure, kernel basic adaptation involves the following parts:

-   Adding the  **target\_config.h**  file, which contains board hardware parameters and feature parameters described in the following table:

    **Table  1**  Parameters in the target\_config.h file

    <a name="table174922816418"></a>
    <table><thead align="left"><tr id="row549388144112"><th class="cellrowborder" valign="top" width="34.81%" id="mcps1.2.3.1.1"><p id="p04939810417"><a name="p04939810417"></a><a name="p04939810417"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="65.19%" id="mcps1.2.3.1.2"><p id="p9493588417"><a name="p9493588417"></a><a name="p9493588417"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row249319816418"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p6493788413"><a name="p6493788413"></a><a name="p6493788413"></a>OS_SYS_CLOCK</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p74937810416"><a name="p74937810416"></a><a name="p74937810416"></a>System cycle frequency</p>
    </td>
    </tr>
    <tr id="row1649388104117"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p2049316816414"><a name="p2049316816414"></a><a name="p2049316816414"></a>DDR_MEM_ADDR</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p349317815413"><a name="p349317815413"></a><a name="p349317815413"></a>Start address of the system memory</p>
    </td>
    </tr>
    <tr id="row5493182419"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p1149316814114"><a name="p1149316814114"></a><a name="p1149316814114"></a>DDR_MEM_SIZE</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p1949311816415"><a name="p1949311816415"></a><a name="p1949311816415"></a>Size of the system memory</p>
    </td>
    </tr>
    <tr id="row9493178194110"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p13493108134115"><a name="p13493108134115"></a><a name="p13493108134115"></a>PERIPH_PMM_BASE</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p1549318134111"><a name="p1549318134111"></a><a name="p1549318134111"></a>Base address of the peripheral register</p>
    </td>
    </tr>
    <tr id="row1749314894112"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p1749328154115"><a name="p1749328154115"></a><a name="p1749328154115"></a>PERIPH_PMM_SIZE</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p1449312816410"><a name="p1449312816410"></a><a name="p1449312816410"></a>Size of the peripheral register</p>
    </td>
    </tr>
    <tr id="row149398114120"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p16493982410"><a name="p16493982410"></a><a name="p16493982410"></a>OS_HWI_MIN</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p184931781412"><a name="p184931781412"></a><a name="p184931781412"></a>Minimum number of system interrupts</p>
    </td>
    </tr>
    <tr id="row124939854118"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p1349348194113"><a name="p1349348194113"></a><a name="p1349348194113"></a>OS_HWI_MAX</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p134935894120"><a name="p134935894120"></a><a name="p134935894120"></a>Maximum number of system interrupts</p>
    </td>
    </tr>
    <tr id="row1332213815810"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p14322781588"><a name="p14322781588"></a><a name="p14322781588"></a>NUM_HAL_INTERRUPT_UART0</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p43224815817"><a name="p43224815817"></a><a name="p43224815817"></a>UART0 interrupt ID</p>
    </td>
    </tr>
    <tr id="row108730542581"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p4873115455813"><a name="p4873115455813"></a><a name="p4873115455813"></a>UART0_REG_BASE</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p3873115417581"><a name="p3873115417581"></a><a name="p3873115417581"></a>UART0 register base address</p>
    </td>
    </tr>
    <tr id="row12172101495718"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p1172514115717"><a name="p1172514115717"></a><a name="p1172514115717"></a>GIC_BASE_ADDR</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p1617216144572"><a name="p1617216144572"></a><a name="p1617216144572"></a>Base address of the GIC interrupt register</p>
    </td>
    </tr>
    <tr id="row24371957115711"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p143785715710"><a name="p143785715710"></a><a name="p143785715710"></a>GICD_OFFSET</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p7437125725717"><a name="p7437125725717"></a><a name="p7437125725717"></a>Offset address of the GICD relative to the GIC base address</p>
    </td>
    </tr>
    <tr id="row19221159175917"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p152211159185918"><a name="p152211159185918"></a><a name="p152211159185918"></a>GICC_OFFSET</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p522105912593"><a name="p522105912593"></a><a name="p522105912593"></a>Offset address of the GICC relative to the GIC base address</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Implementing the  **SystemInit**  function to initialize services in the user space. Figure 2 shows a typical initialization scenario.

    **Figure  2**  Service startup process<a name="fig1919217914418"></a>  
    ![](figures/service-startup-process.png "service-startup-process")

-   Implementing the  **main**  function for basic kernel initialization and initialization of services in the board kernel space.  [Figure 3](#fig32611728133919)  shows the initialization process, where the kernel startup framework takes the lead in the initialization process. The light blue part in the figure indicates the phase in which external modules can be registered and started in the startup framework.

    >![](../public_sys-resources/icon-caution.gif) **CAUTION:** 
    >Modules at the same layer cannot depend on each other.

    **Figure  3**  Kernel startup framework<a name="fig32611728133919"></a>  
    ![](figures/kernel-startup-framework.jpg "kernel-startup-framework")

    **Table  2**  Startup framework layers

    <a name="table38544719428"></a>
    <table><thead align="left"><tr id="row286134714423"><th class="cellrowborder" valign="top" width="34.089999999999996%" id="mcps1.2.3.1.1"><p id="p886164717423"><a name="p886164717423"></a><a name="p886164717423"></a>Layer</p>
    </th>
    <th class="cellrowborder" valign="top" width="65.91%" id="mcps1.2.3.1.2"><p id="p586194716421"><a name="p586194716421"></a><a name="p586194716421"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row48664764218"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p7861447174211"><a name="p7861447174211"></a><a name="p7861447174211"></a>LOS_INIT_LEVEL_EARLIEST</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p1561350125815"><a name="p1561350125815"></a><a name="p1561350125815"></a>Earliest initialization.</p>
    <p id="p13865183210552"><a name="p13865183210552"></a><a name="p13865183210552"></a>This layer does not depend on the architecture. The board and subsequent modules, such as the Trace module, will initialize the software-only modules on which they depend.</p>
    </td>
    </tr>
    <tr id="row4861478429"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p1986164710423"><a name="p1986164710423"></a><a name="p1986164710423"></a>LOS_INIT_LEVEL_ARCH_EARLY</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p6864470423"><a name="p6864470423"></a><a name="p6864470423"></a>Early initialization of the architecture.</p>
    <p id="p118192355598"><a name="p118192355598"></a><a name="p118192355598"></a>This layer depends on the architecture. Subsequent modules will initialize the modules on which they depend. It is recommended that functions not required for startup be placed at the <strong id="b1585085713330"><a name="b1585085713330"></a><a name="b1585085713330"></a>LOS_INIT_LEVEL_ARCH</strong> layer.</p>
    </td>
    </tr>
    <tr id="row98694774219"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p118624714210"><a name="p118624714210"></a><a name="p118624714210"></a>LOS_INIT_LEVEL_PLATFORM_EARLY</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p118531052143510"><a name="p118531052143510"></a><a name="p118531052143510"></a>Early initialization of the platform.</p>
    <p id="p666132195816"><a name="p666132195816"></a><a name="p666132195816"></a>This layer depends on the board platform and drivers. Subsequent modules will initialize the modules on which they depend. It is recommended that functions required for startup be placed at the <strong id="b1857593373411"><a name="b1857593373411"></a><a name="b1857593373411"></a>LOS_INIT_LEVEL_PLATFORM</strong> layer.</p>
    <p id="p1986104794218"><a name="p1986104794218"></a><a name="p1986104794218"></a>Example: UART module</p>
    </td>
    </tr>
    <tr id="row8863470423"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p19861547114214"><a name="p19861547114214"></a><a name="p19861547114214"></a>LOS_INIT_LEVEL_KMOD_PREVM</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p2862471421"><a name="p2862471421"></a><a name="p2862471421"></a>Kernel module initialization before memory initialization.</p>
    <p id="p989110481520"><a name="p989110481520"></a><a name="p989110481520"></a>This layer involves initialization of the modules that need to be enabled before memory initialization.</p>
    </td>
    </tr>
    <tr id="row4861147124218"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p16863472426"><a name="p16863472426"></a><a name="p16863472426"></a>LOS_INIT_LEVEL_VM_COMPLETE</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p1186114715427"><a name="p1186114715427"></a><a name="p1186114715427"></a>Initialization after the basic memory is ready.</p>
    <p id="p26441930165910"><a name="p26441930165910"></a><a name="p26441930165910"></a>This layer involves initialization of the modules that need to be enabled and do not depend on the inter-process communication mechanism and system processes.</p>
    <p id="p76991543175013"><a name="p76991543175013"></a><a name="p76991543175013"></a>Example: shared memory function</p>
    </td>
    </tr>
    <tr id="row12869472429"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p178694712429"><a name="p178694712429"></a><a name="p178694712429"></a>LOS_INIT_LEVEL_ARCH</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p1086104719427"><a name="p1086104719427"></a><a name="p1086104719427"></a>Late initialization of the architecture.</p>
    <p id="p556511281688"><a name="p556511281688"></a><a name="p556511281688"></a>This layer depends on the architecture extension function. Subsequent modules will initialize the modules on which they depend.</p>
    </td>
    </tr>
    <tr id="row128624717424"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p198684711427"><a name="p198684711427"></a><a name="p198684711427"></a>LOS_INIT_LEVEL_PLATFORM</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p65519915524"><a name="p65519915524"></a><a name="p65519915524"></a>Late initialization of the platform.</p>
    <p id="p187247164213"><a name="p187247164213"></a><a name="p187247164213"></a>This layer depends on the board platform and drivers. Subsequent modules will initialize the modules on which they depend.</p>
    <p id="p138046651010"><a name="p138046651010"></a><a name="p138046651010"></a>Example: initialization of the driver kernel abstraction layer (MMC and MTD)</p>
    </td>
    </tr>
    <tr id="row2149155220436"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p8150105215436"><a name="p8150105215436"></a><a name="p8150105215436"></a>LOS_INIT_LEVEL_KMOD_BASIC</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p81509525436"><a name="p81509525436"></a><a name="p81509525436"></a>Initialization of the kernel basic modules.</p>
    <p id="p763134221115"><a name="p763134221115"></a><a name="p763134221115"></a>This layer is used to initialize the basic modules that can be detached from the kernel.</p>
    <p id="p7781186191213"><a name="p7781186191213"></a><a name="p7781186191213"></a>Example: VFS initialization</p>
    </td>
    </tr>
    <tr id="row19671355174317"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p1596825564317"><a name="p1596825564317"></a><a name="p1596825564317"></a>LOS_INIT_LEVEL_KMOD_EXTENDED</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p6968155513438"><a name="p6968155513438"></a><a name="p6968155513438"></a>Initialization of the kernel extended modules.</p>
    <p id="p669712304124"><a name="p669712304124"></a><a name="p669712304124"></a>This layer is used to initialize the extended modules that can be detached from the kernel.</p>
    <p id="p7600114618125"><a name="p7600114618125"></a><a name="p7600114618125"></a>Example: system call initialization, ProcFS initialization, Futex initialization, HiLog initialization, HiEvent initialization, and LiteIPC initialization</p>
    </td>
    </tr>
    <tr id="row357517134414"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p12575676449"><a name="p12575676449"></a><a name="p12575676449"></a>LOS_INIT_LEVEL_KMOD_TASK</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p7128122619143"><a name="p7128122619143"></a><a name="p7128122619143"></a>Kernel task creation.</p>
    <p id="p1657587184419"><a name="p1657587184419"></a><a name="p1657587184419"></a>This layer can be used to create kernel tasks (kernel thread and software timer tasks).</p>
    <p id="p55485297219"><a name="p55485297219"></a><a name="p55485297219"></a>Example: creation of the resident resource reclaiming task, SystemInit task, and CPU usage statistics task</p>
    </td>
    </tr>
    </tbody>
    </table>

    Adaptation for board porting. Focus on layers between  **LOS\_INIT\_LEVEL\_ARCH**  and  **LOS\_INIT\_LEVEL\_KMOD\_TASK**  and try to divide the initialization process into as many phases as possible for refined registration.

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >Modules at the same layer cannot depend on each other. It is recommended that a new module be split based on the preceding startup phase and be registered and started as required.
    >You can view the symbol table in the  **.rodata.init.kernel.\***  segment of the  **OHOS\_Image.map**  file generated after the build is complete, so as to learn about the initialization entry of each module that has been registered with the kernel startup framework and check whether the newly registered initialization entry takes effect.


### Programming Example<a name="section10854481825"></a>

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

## Verification<a name="section646410453212"></a>

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
*******************shell commands:*************************

arp           cat           cd            chgrp         chmod         chown         cp            cpup          
date          dhclient      dmesg         dns           format        free          help          hwi           
ifconfig      ipdebug       kill          log           ls            lsfd          memcheck      mkdir         
mount         netstat       oom           partinfo      partition     ping          ping6         pmm           
pwd           reset         rm            rmdir         sem           shm           stack         statfs        
su            swtmr         sync          systeminfo    task          telnet        touch         umount        
uname         v2p           virstatfs     vmm           watch         writeproc     

```

