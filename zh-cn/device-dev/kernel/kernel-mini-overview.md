# 内核概述<a name="ZH-CN_TOPIC_0000001123863153"></a>

-   [内核简介](#section1429342661510)
    -   [cpu体系架构支持](#section48891456112819)
    -   [运行机制](#section4599142312817)


## 内核简介<a name="section1429342661510"></a>

OpenHarmony LiteOS-M内核是面向IoT领域构建的轻量级物联网操作系统内核，具有小体积、低功耗、高性能的特点。其代码结构简单，主要包括内核最小功能集、内核抽象层、可选组件以及工程目录等。OpenHarmony LiteOS-M内核架构包含硬件相关层以及硬件无关层，如下图所示，其中Kernel Arch模块属于硬件相关层，该模块按不同编译工具链、芯片架构分类，提供统一的HAL（Hardware Abstraction Layer）接口，提升了硬件易适配性，满足AIoT类型丰富的硬件和编译工具链的拓展；Components等其他模块属于硬件无关层，其中Kernel Task等内核模块提供基础能力，Components模块提供网络、文件系统等组件能力，Utils模块提供错误处理、调测等能力，KAL（Kernel Abstraction Layer）模块提供统一的标准接口。

**图 1**  内核架构图<a name="fig17231457191415"></a>  
![](figure/内核架构图.png "内核架构图")

### cpu体系架构支持<a name="section48891456112819"></a>

CPU体系架构分为通用架构定义和特定架构定义两层，通用架构定义层为所有体系架构都需要支持和实现的接口，特定架构定义层为特定体系架构所特有的部分。在新增一个体系架构的时候，必须需要实现通用架构定义层，如果该体系架构还有特有的功能，可以在特定架构定义层来实现。

**表 1**  CPU体系架构规则

<a name="table577192233214"></a>
<table><thead align="left"><tr id="row977192213323"><th class="cellrowborder" valign="top" width="21.592159215921594%" id="mcps1.2.4.1.1"><p id="p15771422123213"><a name="p15771422123213"></a><a name="p15771422123213"></a>规则</p>
</th>
<th class="cellrowborder" valign="top" width="34.713471347134714%" id="mcps1.2.4.1.2"><p id="p57782211323"><a name="p57782211323"></a><a name="p57782211323"></a>通用体系架构层</p>
</th>
<th class="cellrowborder" valign="top" width="43.694369436943695%" id="mcps1.2.4.1.3"><p id="p977132223217"><a name="p977132223217"></a><a name="p977132223217"></a>特定体系架构层</p>
</th>
</tr>
</thead>
<tbody><tr id="row1577522103217"><td class="cellrowborder" valign="top" width="21.592159215921594%" headers="mcps1.2.4.1.1 "><p id="p378152243213"><a name="p378152243213"></a><a name="p378152243213"></a>头文件位置</p>
</td>
<td class="cellrowborder" valign="top" width="34.713471347134714%" headers="mcps1.2.4.1.2 "><p id="p37819227320"><a name="p37819227320"></a><a name="p37819227320"></a>kernel/arch/include</p>
</td>
<td class="cellrowborder" valign="top" width="43.694369436943695%" headers="mcps1.2.4.1.3 "><p id="p9783225321"><a name="p9783225321"></a><a name="p9783225321"></a>kernel/arch/&lt;arch&gt;/&lt;arch&gt;/&lt;toolchain&gt;/</p>
</td>
</tr>
<tr id="row16781422193218"><td class="cellrowborder" valign="top" width="21.592159215921594%" headers="mcps1.2.4.1.1 "><p id="p978112283215"><a name="p978112283215"></a><a name="p978112283215"></a>头文件命名</p>
</td>
<td class="cellrowborder" valign="top" width="34.713471347134714%" headers="mcps1.2.4.1.2 "><p id="p2781322193210"><a name="p2781322193210"></a><a name="p2781322193210"></a>los_&lt;function&gt;.h</p>
</td>
<td class="cellrowborder" valign="top" width="43.694369436943695%" headers="mcps1.2.4.1.3 "><p id="p912752623513"><a name="p912752623513"></a><a name="p912752623513"></a>los_arch_&lt;function&gt;.h</p>
</td>
</tr>
<tr id="row207882213215"><td class="cellrowborder" valign="top" width="21.592159215921594%" headers="mcps1.2.4.1.1 "><p id="p10789229321"><a name="p10789229321"></a><a name="p10789229321"></a>函数命名</p>
</td>
<td class="cellrowborder" valign="top" width="34.713471347134714%" headers="mcps1.2.4.1.2 "><p id="p1778202218329"><a name="p1778202218329"></a><a name="p1778202218329"></a>Halxxxx</p>
</td>
<td class="cellrowborder" valign="top" width="43.694369436943695%" headers="mcps1.2.4.1.3 "><p id="p207817224327"><a name="p207817224327"></a><a name="p207817224327"></a>Halxxxx</p>
</td>
</tr>
</tbody>
</table>

LiteOS-M已经支持ARM Cortex-M3、ARM Cortex-M4、ARM Cortex-M7、ARM Cortex-M33、RISC-V等主流架构，如果需要扩展CPU体系架构，请参考[芯片架构适配点](../porting/porting-chip-kernel-overview.md#section137431650339)。

### 运行机制<a name="section4599142312817"></a>

在开发板配置文件target\_config.h配置系统时钟、每秒Tick数，可以对任务、内存、IPC、异常处理模块进行裁剪配置。系统启动时，根据配置进行指定模块的初始化。内核启动流程包含外设初始化、系统时钟配置、内核初始化、操作系统启动等，详见内核启动流程图。

**图 2**  内核启动流程<a name="fig19742101817344"></a>  
![](figure/内核启动流程.png "内核启动流程")

