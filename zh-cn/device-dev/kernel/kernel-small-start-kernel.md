# 内核态启动<a name="ZH-CN_TOPIC_0000001127506594"></a>

-   [内核启动流程](#section9882154318299)
-   [编程样例](#section19145114703217)
    -   [实例描述](#section1045483642518)


## 内核启动流程<a name="section9882154318299"></a>

内核启动流程包含汇编启动阶段和C语言启动阶段2部分，如图1所示。汇编启动阶段完成CPU初始设置，关闭dcache/icache，使能FPU及neon，设置MMU建立虚实地址映射，设置系统栈，清理bss段，调用C语言main函数等。C语言启动阶段包含OsMain函数及开始调度等，其中如上图所示，OsMain函数用于内核基础初始化和架构、板级初始化等，其整体由内核启动框架主导初始化流程，图中右边区域为启动框架中可接受外部模块注册启动的阶段，各个阶段的说明如下表1所示。

**图 1**  内核启动流程图<a name="fig1372861419385"></a>  


![](figure/zh-cn_image_0000001178856385.png)

**表 1**  启动框架层级

<a name="table38544719428"></a>
<table><thead align="left"><tr id="row286134714423"><th class="cellrowborder" valign="top" width="35.58%" id="mcps1.2.3.1.1"><p id="p886164717423"><a name="p886164717423"></a><a name="p886164717423"></a>层级</p>
</th>
<th class="cellrowborder" valign="top" width="64.42%" id="mcps1.2.3.1.2"><p id="p586194716421"><a name="p586194716421"></a><a name="p586194716421"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row48664764218"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p7861447174211"><a name="p7861447174211"></a><a name="p7861447174211"></a>LOS_INIT_LEVEL_EARLIEST</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p1561350125815"><a name="p1561350125815"></a><a name="p1561350125815"></a>最早期初始化</p>
<p id="p13865183210552"><a name="p13865183210552"></a><a name="p13865183210552"></a>说明：不依赖架构，单板以及后续模块会对其有依赖的纯软件模块初始化</p>
<p id="p1686104764216"><a name="p1686104764216"></a><a name="p1686104764216"></a>例如：Trace模块</p>
</td>
</tr>
<tr id="row4861478429"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p1986164710423"><a name="p1986164710423"></a><a name="p1986164710423"></a>LOS_INIT_LEVEL_ARCH_EARLY</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p6864470423"><a name="p6864470423"></a><a name="p6864470423"></a>架构早期初始化</p>
<p id="p118192355598"><a name="p118192355598"></a><a name="p118192355598"></a>说明：架构相关，后续模块会对其有依赖的模块初始化，如启动过程中非必需的功能，建议放到LOS_INIT_LEVEL_ARCH层</p>
</td>
</tr>
<tr id="row98694774219"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p118624714210"><a name="p118624714210"></a><a name="p118624714210"></a>LOS_INIT_LEVEL_PLATFORM_EARLY</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p118531052143510"><a name="p118531052143510"></a><a name="p118531052143510"></a>平台早期初始化</p>
<p id="p666132195816"><a name="p666132195816"></a><a name="p666132195816"></a>说明：单板平台、驱动相关，后续模块会对其有依赖的模块初始化，如启动过程中必需的功能，建议放到LOS_INIT_LEVEL_PLATFORM层</p>
<p id="p1986104794218"><a name="p1986104794218"></a><a name="p1986104794218"></a>例如：uart模块</p>
</td>
</tr>
<tr id="row8863470423"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p19861547114214"><a name="p19861547114214"></a><a name="p19861547114214"></a>LOS_INIT_LEVEL_KMOD_PREVM</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p2862471421"><a name="p2862471421"></a><a name="p2862471421"></a>内存初始化前的内核模块初始化</p>
<p id="p989110481520"><a name="p989110481520"></a><a name="p989110481520"></a>说明：在内存初始化之前需要使能的模块初始化</p>
</td>
</tr>
<tr id="row4861147124218"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p16863472426"><a name="p16863472426"></a><a name="p16863472426"></a>LOS_INIT_LEVEL_VM_COMPLETE</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p1186114715427"><a name="p1186114715427"></a><a name="p1186114715427"></a>基础内存就绪后的初始化</p>
<p id="p26441930165910"><a name="p26441930165910"></a><a name="p26441930165910"></a>说明：此时内存初始化完毕，需要进行使能且不依赖进程间通讯机制与系统进程的模块初始化</p>
<p id="p76991543175013"><a name="p76991543175013"></a><a name="p76991543175013"></a>例如：共享内存功能</p>
</td>
</tr>
<tr id="row12869472429"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p178694712429"><a name="p178694712429"></a><a name="p178694712429"></a>LOS_INIT_LEVEL_ARCH</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p1086104719427"><a name="p1086104719427"></a><a name="p1086104719427"></a>架构后期初始化</p>
<p id="p556511281688"><a name="p556511281688"></a><a name="p556511281688"></a>说明：架构拓展功能相关，后续模块会对其有依赖的模块初始化</p>
</td>
</tr>
<tr id="row128624717424"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p198684711427"><a name="p198684711427"></a><a name="p198684711427"></a>LOS_INIT_LEVEL_PLATFORM</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p65519915524"><a name="p65519915524"></a><a name="p65519915524"></a>平台后期初始化</p>
<p id="p187247164213"><a name="p187247164213"></a><a name="p187247164213"></a>说明：单板平台、驱动相关，后续模块会对其有依赖的模块初始化</p>
<p id="p138046651010"><a name="p138046651010"></a><a name="p138046651010"></a>例如：驱动内核抽象层初始化（mmc、mtd）</p>
</td>
</tr>
<tr id="row2149155220436"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p8150105215436"><a name="p8150105215436"></a><a name="p8150105215436"></a>LOS_INIT_LEVEL_KMOD_BASIC</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p81509525436"><a name="p81509525436"></a><a name="p81509525436"></a>内核基础模块初始化</p>
<p id="p763134221115"><a name="p763134221115"></a><a name="p763134221115"></a>说明：内核可拆卸的基础模块初始化</p>
<p id="p7781186191213"><a name="p7781186191213"></a><a name="p7781186191213"></a>例如：VFS初始化</p>
</td>
</tr>
<tr id="row19671355174317"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p1596825564317"><a name="p1596825564317"></a><a name="p1596825564317"></a>LOS_INIT_LEVEL_KMOD_EXTENDED</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p6968155513438"><a name="p6968155513438"></a><a name="p6968155513438"></a>内核扩展模块初始化</p>
<p id="p669712304124"><a name="p669712304124"></a><a name="p669712304124"></a>说明：内核可拆卸的扩展模块初始化</p>
<p id="p7600114618125"><a name="p7600114618125"></a><a name="p7600114618125"></a>例如：系统调用初始化、ProcFS初始化、Futex初始化、HiLog初始化、HiEvent初始化、LiteIPC初始化</p>
</td>
</tr>
<tr id="row357517134414"><td class="cellrowborder" valign="top" width="35.58%" headers="mcps1.2.3.1.1 "><p id="p12575676449"><a name="p12575676449"></a><a name="p12575676449"></a>LOS_INIT_LEVEL_KMOD_TASK</p>
</td>
<td class="cellrowborder" valign="top" width="64.42%" headers="mcps1.2.3.1.2 "><p id="p7128122619143"><a name="p7128122619143"></a><a name="p7128122619143"></a>内核任务创建</p>
<p id="p1657587184419"><a name="p1657587184419"></a><a name="p1657587184419"></a>说明：进行内核任务的创建（内核线程，软件定时器任务）</p>
<p id="p55485297219"><a name="p55485297219"></a><a name="p55485297219"></a>例如：资源回收系统常驻任务的创建、SystemInit任务创建、CPU占用率统计任务创建</p>
</td>
</tr>
</tbody>
</table>

## 编程样例<a name="section19145114703217"></a>

### 实例描述<a name="section1045483642518"></a>

新增一个内核模块，需要在内核初始化时进行该模块的初始化，则通过内核启动框架将该模块的初始化函数注册进内核启动流程中。

**示例代码**

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

**结果验证**

```
main core booting up...
OsSampleModInit SUCCESS!
releasing 1 secondary cores
cpu 1 entering scheduler
cpu 0 entering scheduler
```

根据上述系统启动阶段的打印可知，内核在启动时进行了该注册模块的初始化函数调用，完成该模块的初始化操作。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>启动框架中同一层级内的注册模块不能有依赖关系，建议新增模块按照上述启动阶段进行模块初始化的拆分，按需注册启动。
>可通过查看系统编译生成文件OHOS\_Image.map中.rodata.init.kernel.\*段内的符号表来了解当前已注册进内核启动框架中的各个模块初始化入口，以及检查新注册的模块初始化入口是否生效。

