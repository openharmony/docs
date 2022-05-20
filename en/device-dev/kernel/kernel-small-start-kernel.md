# Startup in Kernel Mode


## Kernel Startup Process<a name="section9882154318299"></a>

The kernel startup process consists of the assembly startup and C language startup, as shown in the following figure. The assembly startup involves the following operations: initializing CPU settings, disabling dCache/iCache, enabling the FPU and NEON, setting the MMU to establish the virtual-physical address mapping, setting the system stack, clearing the BSS segment, and calling the main function of the C language. The C language startup involves the following operations: starting the OsMain function and starting scheduling. As shown in the following figure, the OsMain function is used for basic kernel initialization and architecture- and board-level initialization. The kernel startup framework leads the initialization process. The right part of the figure shows the phase in which external modules can register with the kernel startup framework and starts.  [Table 1](#table38544719428)  describes each phase.

**Figure  1**  Kernel startup process<a name="fig983731153511"></a>  
![](figures/kernel-startup-process-2.png "kernel-startup-process-2")

**Table  1**  Startup framework levels

<a name="table38544719428"></a>
<table><thead align="left"><tr id="row286134714423"><th class="cellrowborder" valign="top" width="35.58%" id="mcps1.2.3.1.1"><p id="p886164717423"><a name="p886164717423"></a><a name="p886164717423"></a>Level</p>
</th>
<th class="cellrowborder" valign="top" width="64.42%" id="mcps1.2.3.1.2"><p id="p586194716421"><a name="p586194716421"></a><a name="p586194716421"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row48664764218"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p7861447174211"><a name="p7861447174211"></a><a name="p7861447174211"></a>LOS_INIT_LEVEL_EARLIEST</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p1561350125815"><a name="p1561350125815"></a><a name="p1561350125815"></a>Earliest initialization.</p>
<p id="p13865183210552"><a name="p13865183210552"></a><a name="p13865183210552"></a>The initialization is architecture-independent. The board and subsequent modules initialize the pure software modules on which they depend.</p>
<p id="p1686104764216"><a name="p1686104764216"></a><a name="p1686104764216"></a>Example: trace module</p>
</td>
</tr>
<tr id="row4861478429"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p1986164710423"><a name="p1986164710423"></a><a name="p1986164710423"></a>LOS_INIT_LEVEL_ARCH_EARLY</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p6864470423"><a name="p6864470423"></a><a name="p6864470423"></a>Early initialization of the architecture.</p>
<p id="p118192355598"><a name="p118192355598"></a><a name="p118192355598"></a>The initialization is architecture-dependent. Subsequent modules initialize the modules on which they depend. It is recommended that functions not required for startup be placed at <strong id="b13751321192318"><a name="b13751321192318"></a><a name="b13751321192318"></a>LOS_INIT_LEVEL_ARCH</strong>.</p>
</td>
</tr>
<tr id="row98694774219"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p118624714210"><a name="p118624714210"></a><a name="p118624714210"></a>LOS_INIT_LEVEL_PLATFORM_EARLY</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p118531052143510"><a name="p118531052143510"></a><a name="p118531052143510"></a>Early initialization of the platform.</p>
<p id="p666132195816"><a name="p666132195816"></a><a name="p666132195816"></a>The initialization depends on the board platform and drivers. Subsequent modules initialize the modules on which they depend. It is recommended that functions required for startup be placed at <strong id="b44971429202712"><a name="b44971429202712"></a><a name="b44971429202712"></a>LOS_INIT_LEVEL_PLATFORM</strong>.
</td>
</tr>
<tr id="row8863470423"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p19861547114214"><a name="p19861547114214"></a><a name="p19861547114214"></a>LOS_INIT_LEVEL_KMOD_PREVM</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p2862471421"><a name="p2862471421"></a><a name="p2862471421"></a>Kernel module initialization before memory initialization.</p>
<p id="p989110481520"><a name="p989110481520"></a><a name="p989110481520"></a>Initialize the modules that need to be enabled before memory initialization.</p>
</td>
</tr>
<tr id="row4861147124218"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p16863472426"><a name="p16863472426"></a><a name="p16863472426"></a>LOS_INIT_LEVEL_VM_COMPLETE</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p1186114715427"><a name="p1186114715427"></a><a name="p1186114715427"></a>Initialization after the basic memory is ready.</p>
<p id="p26441930165910"><a name="p26441930165910"></a><a name="p26441930165910"></a>After memory initialization, initialize the modules that need to be enabled and do not depend on inter-process communication (IPC) and system processes.</p>
<p id="p76991543175013"><a name="p76991543175013"></a><a name="p76991543175013"></a>Example: shared memory function</p>
</td>
</tr>
<tr id="row12869472429"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p178694712429"><a name="p178694712429"></a><a name="p178694712429"></a>LOS_INIT_LEVEL_ARCH</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p1086104719427"><a name="p1086104719427"></a><a name="p1086104719427"></a>Late initialization of the architecture.</p>
<p id="p556511281688"><a name="p556511281688"></a><a name="p556511281688"></a>The initialization is related to the architecture extension functions. Subsequent modules initialize the modules on which they depend.</p>
</td>
</tr>
<tr id="row128624717424"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p198684711427"><a name="p198684711427"></a><a name="p198684711427"></a>LOS_INIT_LEVEL_PLATFORM</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p65519915524"><a name="p65519915524"></a><a name="p65519915524"></a>Late initialization of the platform.</p>
<p id="p187247164213"><a name="p187247164213"></a><a name="p187247164213"></a>The initialization depends on the board platform and drivers. Subsequent modules initialize the modules on which they depend.</p>
<p id="p138046651010"><a name="p138046651010"></a><a name="p138046651010"></a>Example: initialization of the driver kernel abstraction layer (MMC and MTD)</p>
</td>
</tr>
<tr id="row2149155220436"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p8150105215436"><a name="p8150105215436"></a><a name="p8150105215436"></a>LOS_INIT_LEVEL_KMOD_BASIC</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p81509525436"><a name="p81509525436"></a><a name="p81509525436"></a>Initialization of the kernel basic modules.</p>
<p id="p763134221115"><a name="p763134221115"></a><a name="p763134221115"></a>Initialize the basic modules that can be detached from the kernel.</p>
<p id="p7781186191213"><a name="p7781186191213"></a><a name="p7781186191213"></a>Example: VFS initialization</p>
</td>
</tr>
<tr id="row19671355174317"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p1596825564317"><a name="p1596825564317"></a><a name="p1596825564317"></a>LOS_INIT_LEVEL_KMOD_EXTENDED</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p6968155513438"><a name="p6968155513438"></a><a name="p6968155513438"></a>Initialization of the kernel extended modules.</p>
<p id="p669712304124"><a name="p669712304124"></a><a name="p669712304124"></a>Initialize the extended modules that can be detached from the kernel.</p>
<p id="p7600114618125"><a name="p7600114618125"></a><a name="p7600114618125"></a>Example: initialization of system call, ProcFS, Futex, HiLog, HiEvent, and LiteIPC</p>
</td>
</tr>
<tr id="row357517134414"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p12575676449"><a name="p12575676449"></a><a name="p12575676449"></a>LOS_INIT_LEVEL_KMOD_TASK</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p7128122619143"><a name="p7128122619143"></a><a name="p7128122619143"></a>Kernel task creation</p>
<p id="p1657587184419"><a name="p1657587184419"></a><a name="p1657587184419"></a>Create kernel tasks (kernel tasks and software timer tasks).</p>
<p id="p55485297219"><a name="p55485297219"></a><a name="p55485297219"></a>Example: creation of the resident resource reclaiming task, SystemInit task, and CPU usage statistics task.</p>
</td>
</tr>
</tbody>
</table>

## Programming Example<a name="section19145114703217"></a>

### Example Description<a name="section1045483642518"></a>

Add a kernel module and register the initialization function of the module to the kernel startup process through the kernel startup framework, so as to complete the module initialization during the kernel initialization process.

**Sample Code**

```
/* Header file of the kernel startup framework */
#include "los_init.h"
...

/* Initialization function of the new module */
unsigned int OsSampleModInit(void)
{
    PRINTK("OsSampleModInit SUCCESS!\n");
    ......
}
...
/* Register the new module at the target level of the kernel startup framework. */
LOS_MODULE_INIT(OsSampleModInit, LOS_INIT_LEVEL_KMOD_EXTENDED);
```

**Verification**

```
main core booting up...
OsSampleModInit SUCCESS!
releasing 1 secondary cores
cpu 1 entering scheduler
cpu 0 entering scheduler
```

According to the information displayed during the system startup, the kernel has called the initialization function of the registered module during the startup to initialize the module.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>Modules at the same level cannot depend on each other. It is recommended that a new module be split based on the preceding startup phase and be registered and started as required.
>You can view the symbol table in the  **.rodata.init.kernel.\***  segment of the  **OHOS\_Image.map**  file generated after the build is complete, so as to learn about the initialization entry of each module that has been registered with the kernel startup framework and check whether the newly registered initialization entry has taken effect.

