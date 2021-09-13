# LiteOS-A内核<a name="ZH-CN_TOPIC_0000001113392962"></a>

-   [移植概述](#section14876256185510)
    -   [移植场景](#section1986014410569)
    -   [目录规范](#section10916181716564)

-   [基础适配](#section814974018565)
    -   [编程样例](#section10854481825)

-   [验证](#section646410453212)

## 移植概述<a name="section14876256185510"></a>

### 移植场景<a name="section1986014410569"></a>

LiteOS-A当前支持ARMv7-a指令集架构，如果三方芯片为ARMv7-a架构，可以进行内核基础适配；否则还需要先根据芯片的架构来新增内核对该芯片架构的支持，这个工作较为复杂，不在这篇文章范围内。

### 目录规范<a name="section10916181716564"></a>

LiteOS-A目录规范参考[LiteOS-A 简介](https://gitee.com/openharmony/kernel_liteos_a)。

## 基础适配<a name="section814974018565"></a>

LiteOS-A提供系统运行所需的系统初始化流程和定制化配置选项。移植过程中，需要关注初始化流程中跟硬件配置相关的函数。

如下图所示，LiteOS-A的初始化流程主要包含以下七步：

1.  新增target\_config.h文件，并且编写单板内存相关的配置宏DDR\_MEM\_ADDR和DDR\_MEM\_SIZE，分别表示内存起始地址和内存的长度，预链接脚本board.ld.S会根据这两个宏进行展开生成链接脚本board.ld。
2.  新增定义MMU映射全局数组\(g\_archMmuInitMapping\)，指定各个内存段属性及虚实映射关系，内核启动阶段根据该表建立内存映射关系。
3.  如果是多核，需要新增定义从核操作函数句柄\(struct SmpOps\)，其中SmpOps-\>SmpCpuOn函数需要实现唤醒从核的功能；接着定义SmpRegFunc函数，调用LOS\_SmpOpsSet接口进行句柄注册；最后通过启动框架完成注册过程，即LOS\_MODULE\_INIT\(SmpRegFunc, LOS\_INIT\_LEVEL\_EARLIEST\)。
4.  链接阶段根据链接脚本board.ld生成内核镜像。
5.  单核CPU镜像运行入口为汇编文件reset\_vector\_up.S，多核CPU的入口为reset\_vector\_mp.S，在汇编文件中进行中断向量表初始化、MMU页表初始化等操作。
6.  reset\_vector.S汇编代码最终会跳转到C语言的main函数，进行硬件时钟、软件定时器、内存和任务等初始化，这个过程会依赖target\_config.h的特性宏配置，最后会创建SystemInit任务，并且开启任务调度OsSchedStart\(\)。
7.  SystemInit任务在单板代码中实现，其中调用DeviceManagerStart函数进行HDF驱动初始化，这个过程会调用单板代码中的驱动配置文件hdf.hcs以及drivers源码实现

整体启动流程如下图所示：

**图 1**  整体启动流程<a name="fig68283211926"></a>  
![](figure/整体启动流程.png "整体启动流程")

从图1中可以看到，内核基础适配需要单板进行适配的代码包含三部分：

-   新增target\_config.h文件，其中新增单板硬件配置参数和特性开关的配置参数，具体说明如下：

    **表 1**  target\_config.h配置项说明

    <a name="table174922816418"></a>
    <table><thead align="left"><tr id="row549388144112"><th class="cellrowborder" valign="top" width="34.81%" id="mcps1.2.3.1.1"><p id="p04939810417"><a name="p04939810417"></a><a name="p04939810417"></a>配置项</p>
    </th>
    <th class="cellrowborder" valign="top" width="65.19%" id="mcps1.2.3.1.2"><p id="p9493588417"><a name="p9493588417"></a><a name="p9493588417"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row249319816418"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p6493788413"><a name="p6493788413"></a><a name="p6493788413"></a>OS_SYS_CLOCK</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p74937810416"><a name="p74937810416"></a><a name="p74937810416"></a>系统cycle的频率</p>
    </td>
    </tr>
    <tr id="row1649388104117"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p2049316816414"><a name="p2049316816414"></a><a name="p2049316816414"></a>DDR_MEM_ADDR</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p349317815413"><a name="p349317815413"></a><a name="p349317815413"></a>系统内存的起始地址</p>
    </td>
    </tr>
    <tr id="row5493182419"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p1149316814114"><a name="p1149316814114"></a><a name="p1149316814114"></a>DDR_MEM_SIZE</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p1949311816415"><a name="p1949311816415"></a><a name="p1949311816415"></a>系统内存的大小</p>
    </td>
    </tr>
    <tr id="row9493178194110"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p13493108134115"><a name="p13493108134115"></a><a name="p13493108134115"></a>PERIPH_PMM_BASE</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p1549318134111"><a name="p1549318134111"></a><a name="p1549318134111"></a>外设寄存器的起始地址</p>
    </td>
    </tr>
    <tr id="row1749314894112"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p1749328154115"><a name="p1749328154115"></a><a name="p1749328154115"></a>PERIPH_PMM_SIZE</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p1449312816410"><a name="p1449312816410"></a><a name="p1449312816410"></a>外设寄存器的长度大小</p>
    </td>
    </tr>
    <tr id="row149398114120"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p16493982410"><a name="p16493982410"></a><a name="p16493982410"></a>OS_HWI_MIN</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p184931781412"><a name="p184931781412"></a><a name="p184931781412"></a>系统中断最小值</p>
    </td>
    </tr>
    <tr id="row124939854118"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p1349348194113"><a name="p1349348194113"></a><a name="p1349348194113"></a>OS_HWI_MAX</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p134935894120"><a name="p134935894120"></a><a name="p134935894120"></a>系统中断最大值</p>
    </td>
    </tr>
    <tr id="row1332213815810"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p14322781588"><a name="p14322781588"></a><a name="p14322781588"></a>NUM_HAL_INTERRUPT_UART0</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p43224815817"><a name="p43224815817"></a><a name="p43224815817"></a>UART0中断号</p>
    </td>
    </tr>
    <tr id="row108730542581"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p4873115455813"><a name="p4873115455813"></a><a name="p4873115455813"></a>UART0_REG_BASE</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p3873115417581"><a name="p3873115417581"></a><a name="p3873115417581"></a>UART0寄存器基址</p>
    </td>
    </tr>
    <tr id="row12172101495718"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p1172514115717"><a name="p1172514115717"></a><a name="p1172514115717"></a>GIC_BASE_ADDR</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p1617216144572"><a name="p1617216144572"></a><a name="p1617216144572"></a>GIC中断寄存器基址</p>
    </td>
    </tr>
    <tr id="row24371957115711"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p143785715710"><a name="p143785715710"></a><a name="p143785715710"></a>GICD_OFFSET</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p7437125725717"><a name="p7437125725717"></a><a name="p7437125725717"></a>GICD相对GIC基址的偏移地址</p>
    </td>
    </tr>
    <tr id="row19221159175917"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p152211159185918"><a name="p152211159185918"></a><a name="p152211159185918"></a>GICC_OFFSET</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p522105912593"><a name="p522105912593"></a><a name="p522105912593"></a>GICC相对GIC基址的偏移地址</p>
    </td>
    </tr>
    </tbody>
    </table>

-   SystemInit函数用于单板用户态业务初始化，典型的初始化场景如图2所示：

    **图 2**  业务启动流程<a name="fig1919217914418"></a>  
    ![](figure/业务启动流程.png "业务启动流程")

-   main函数用于内核基础初始化和单板内核态业务初始化，流程如下图3所示，整体由内核启动框架主导初始化流程，图中浅蓝色部分为启动框架中可接受外部模块注册启动的阶段。

    >![](../public_sys-resources/icon-caution.gif) **注意：** 
    >同一层级内的模块不能有依赖关系。

    **图 3**  内核启动框架<a name="fig32611728133919"></a>  
    ![](figure/内核启动框架.jpg "内核启动框架")

    **表 2**  启动框架层级

    <a name="table38544719428"></a>
    <table><thead align="left"><tr id="row286134714423"><th class="cellrowborder" valign="top" width="34.089999999999996%" id="mcps1.2.3.1.1"><p id="p886164717423"><a name="p886164717423"></a><a name="p886164717423"></a>层级</p>
    </th>
    <th class="cellrowborder" valign="top" width="65.91%" id="mcps1.2.3.1.2"><p id="p586194716421"><a name="p586194716421"></a><a name="p586194716421"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row48664764218"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p7861447174211"><a name="p7861447174211"></a><a name="p7861447174211"></a>LOS_INIT_LEVEL_EARLIEST</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p1561350125815"><a name="p1561350125815"></a><a name="p1561350125815"></a>最早期初始化</p>
    <p id="p13865183210552"><a name="p13865183210552"></a><a name="p13865183210552"></a>说明：不依赖架构，单板以及后续模块会对其有依赖的纯软件模块初始化</p>
    <p id="p1686104764216"><a name="p1686104764216"></a><a name="p1686104764216"></a>例如：Trace模块</p>
    </td>
    </tr>
    <tr id="row4861478429"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p1986164710423"><a name="p1986164710423"></a><a name="p1986164710423"></a>LOS_INIT_LEVEL_ARCH_EARLY</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p6864470423"><a name="p6864470423"></a><a name="p6864470423"></a>架构早期初始化</p>
    <p id="p118192355598"><a name="p118192355598"></a><a name="p118192355598"></a>说明：架构相关，后续模块会对其有依赖的模块初始化，如启动过程中非必需的功能，建议放到LOS_INIT_LEVEL_ARCH层</p>
    </td>
    </tr>
    <tr id="row98694774219"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p118624714210"><a name="p118624714210"></a><a name="p118624714210"></a>LOS_INIT_LEVEL_PLATFORM_EARLY</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p118531052143510"><a name="p118531052143510"></a><a name="p118531052143510"></a>平台早期初始化</p>
    <p id="p666132195816"><a name="p666132195816"></a><a name="p666132195816"></a>说明：单板平台、驱动相关，后续模块会对其有依赖的模块初始化，如启动过程中必需的功能，建议放到LOS_INIT_LEVEL_PLATFORM层</p>
    <p id="p1986104794218"><a name="p1986104794218"></a><a name="p1986104794218"></a>例如：uart模块</p>
    </td>
    </tr>
    <tr id="row8863470423"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p19861547114214"><a name="p19861547114214"></a><a name="p19861547114214"></a>LOS_INIT_LEVEL_KMOD_PREVM</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p2862471421"><a name="p2862471421"></a><a name="p2862471421"></a>内存初始化前的内核模块初始化</p>
    <p id="p989110481520"><a name="p989110481520"></a><a name="p989110481520"></a>说明：在内存初始化之前需要使能的模块初始化</p>
    </td>
    </tr>
    <tr id="row4861147124218"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p16863472426"><a name="p16863472426"></a><a name="p16863472426"></a>LOS_INIT_LEVEL_VM_COMPLETE</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p1186114715427"><a name="p1186114715427"></a><a name="p1186114715427"></a>基础内存就绪后的初始化</p>
    <p id="p26441930165910"><a name="p26441930165910"></a><a name="p26441930165910"></a>说明：此时内存初始化完毕，需要进行使能且不依赖进程间通讯机制与系统进程的模块初始化</p>
    <p id="p76991543175013"><a name="p76991543175013"></a><a name="p76991543175013"></a>例如：共享内存功能</p>
    </td>
    </tr>
    <tr id="row12869472429"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p178694712429"><a name="p178694712429"></a><a name="p178694712429"></a>LOS_INIT_LEVEL_ARCH</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p1086104719427"><a name="p1086104719427"></a><a name="p1086104719427"></a>架构后期初始化</p>
    <p id="p556511281688"><a name="p556511281688"></a><a name="p556511281688"></a>说明：架构拓展功能相关，后续模块会对其有依赖的模块初始化</p>
    </td>
    </tr>
    <tr id="row128624717424"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p198684711427"><a name="p198684711427"></a><a name="p198684711427"></a>LOS_INIT_LEVEL_PLATFORM</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p65519915524"><a name="p65519915524"></a><a name="p65519915524"></a>平台后期初始化</p>
    <p id="p187247164213"><a name="p187247164213"></a><a name="p187247164213"></a>说明：单板平台、驱动相关，后续模块会对其有依赖的模块初始化</p>
    <p id="p138046651010"><a name="p138046651010"></a><a name="p138046651010"></a>例如：驱动内核抽象层初始化（mmc、mtd）</p>
    </td>
    </tr>
    <tr id="row2149155220436"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p8150105215436"><a name="p8150105215436"></a><a name="p8150105215436"></a>LOS_INIT_LEVEL_KMOD_BASIC</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p81509525436"><a name="p81509525436"></a><a name="p81509525436"></a>内核基础模块初始化</p>
    <p id="p763134221115"><a name="p763134221115"></a><a name="p763134221115"></a>说明：内核可拆卸的基础模块初始化</p>
    <p id="p7781186191213"><a name="p7781186191213"></a><a name="p7781186191213"></a>例如：VFS初始化</p>
    </td>
    </tr>
    <tr id="row19671355174317"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p1596825564317"><a name="p1596825564317"></a><a name="p1596825564317"></a>LOS_INIT_LEVEL_KMOD_EXTENDED</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p6968155513438"><a name="p6968155513438"></a><a name="p6968155513438"></a>内核扩展模块初始化</p>
    <p id="p669712304124"><a name="p669712304124"></a><a name="p669712304124"></a>说明：内核可拆卸的扩展模块初始化</p>
    <p id="p7600114618125"><a name="p7600114618125"></a><a name="p7600114618125"></a>例如：系统调用初始化、ProcFS初始化、Futex初始化、HiLog初始化、HiEvent初始化、LiteIPC初始化</p>
    </td>
    </tr>
    <tr id="row357517134414"><td class="cellrowborder" valign="top" width="34.089999999999996%" headers="mcps1.2.3.1.1 "><p id="p12575676449"><a name="p12575676449"></a><a name="p12575676449"></a>LOS_INIT_LEVEL_KMOD_TASK</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.91%" headers="mcps1.2.3.1.2 "><p id="p7128122619143"><a name="p7128122619143"></a><a name="p7128122619143"></a>内核任务创建</p>
    <p id="p1657587184419"><a name="p1657587184419"></a><a name="p1657587184419"></a>说明：进行内核任务的创建（内核线程，软件定时器任务）</p>
    <p id="p55485297219"><a name="p55485297219"></a><a name="p55485297219"></a>例如：资源回收系统常驻任务的创建、SystemInit任务创建、CPU占用率统计任务创建</p>
    </td>
    </tr>
    </tbody>
    </table>

    进行单板移植适配，推荐关注LOS\_INIT\_LEVEL\_ARCH至LOS\_INIT\_LEVEL\_KMOD\_TASK之间的层级，且尽可能拆分初始化行为进行细化阶段注册。

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >启动框架中同一层级内的注册模块不能有依赖关系，建议新增模块按照上述启动阶段进行模块初始化的拆分，按需注册启动。
    >可通过查看系统编译生成文件OHOS\_Image.map中.rodata.init.kernel.\*段内的符号表来了解当前已注册进内核启动框架中的各个模块初始化入口，以及检查新注册的模块初始化入口是否生效。


### 编程样例<a name="section10854481825"></a>

在单板SDK文件中

```
/* 内核启动框架头文件 */
#include "los_init.h"
......

/* 新增模块的初始化函数 */
unsigned int OsSampleModInit(void)
{
    PRINTK("OsSampleModInit SUCCESS!\n");
    ......
}
......
/* 在启动框架的目标层级中注册新增模块 */
LOS_MODULE_INIT(OsSampleModInit, LOS_INIT_LEVEL_KMOD_EXTENDED);
```

## 验证<a name="section646410453212"></a>

```
main core booting up...
OsSampleModInit SUCCESS!
releasing 1 secondary cores
cpu 1 entering scheduler
cpu 0 entering scheduler
```

根据上述系统启动阶段的打印可知，内核在启动时进行了该注册模块的初始化函数调用，完成该模块的初始化操作。

系统启动完毕后进入内核态shell，能够运行task命令能够正常显示即可。

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

