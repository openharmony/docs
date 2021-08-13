# Trace<a name="ZH-CN_TOPIC_0000001123695263"></a>

-   [基本概念](#section531482192018)
-   [运行机制](#section5125124532010)
-   [使用指导](#section1381714413216)

## 基本概念<a name="section531482192018"></a>

Trace是内核提供的一个跟踪模块关键流程的功能框架，各个模块根据机制需要，可以在关键位置通过Trace进行相关信息记录，再通过文件或者其他方式导出，对数据进行分析。

Trace的记录要求：

1.  需要尽快的完成信息记录，对系统时序的影响降低到最小；
2.  需要尽可能的用小的空间存储大的数据量，减少内存消耗。

## 运行机制<a name="section5125124532010"></a>

在内核启动初期完成Trace功能的初始化，并且在支持Trace功能的模块进行初始化时，完成模块相应的Trace类型及回调函数的注册，触发Trace记录的trace point的具体位置可由各模块自行决定。

当系统触发到一个trace point时，Trace模块会对输入信息进行封装，添加Trace帧头信息，包含Trace类型、运行的cpuid、运行的任务id、运行的相对时间戳以及运行的进程id；再将trace frame记录到预先申请好的循环buffer中。

如果循环buffer记录的frame过多则可能出现翻转，会覆盖之前的记录，故保持记录的信息始终是最新的信息。Trace循环buffer的数据可以通过文件dump等形式导出进行详细分析，导出信息已按照时间戳信息完成排序。

![](figure/zh-cn_image_0000001127390512.png)

## 使用指导<a name="section1381714413216"></a>

1.  配置Trace控制宏LOSCFG\_KERNEL\_TRACE，默认关，通过在menuconfig内核配置"Kernel-\>Enable Trace Feature"中打开。
2.  内核启动完成Trace初始化，对应接口OsTraceInit。
3.  统一在los\_trace\_frame.h定义模块内traceframe结构体，并在los\_trace\_frame.c中实现模块Trace回调函数的实现。
4.  需要跟踪的模块在初始化或者更早阶段完成Trace注册，对应接口LOS\_TraceReg。
5.  在需要开始跟踪的位置打开Trace开关进行记录，结束的位置关闭Trace开关停止记录。
6.  通过LOS\_Trace2File接口导出到文件。
7.  根据帧头及帧体数据结构，对数据进行二次分析。

**接口说明**

OpenHarmony LiteOS-A内核的Trace框架提供下面几种功能，接口详细信息可以查看API参考。

**表 1**  Trace接口说明

<a name="table818431314338"></a>
<table><thead align="left"><tr id="row151841613163315"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p159375113174"><a name="p159375113174"></a><a name="p159375113174"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p199385118173"><a name="p199385118173"></a><a name="p199385118173"></a>接口<strong id="b197068338312"><a name="b197068338312"></a><a name="b197068338312"></a>名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p18937511175"><a name="p18937511175"></a><a name="p18937511175"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1918541303315"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p518551319333"><a name="p518551319333"></a><a name="p518551319333"></a>打桩记录</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p19185513103317"><a name="p19185513103317"></a><a name="p19185513103317"></a>LOS_Trace</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1118515135337"><a name="p1118515135337"></a><a name="p1118515135337"></a>Trace信息记录打桩</p>
</td>
</tr>
<tr id="row13185111320331"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p13512294508"><a name="p13512294508"></a><a name="p13512294508"></a>注册解注册</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p151852013203318"><a name="p151852013203318"></a><a name="p151852013203318"></a>LOS_TraceReg</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1318571310338"><a name="p1318571310338"></a><a name="p1318571310338"></a>Trace类型注册</p>
</td>
</tr>
<tr id="row201858136336"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6185171393311"><a name="p6185171393311"></a><a name="p6185171393311"></a>LOS_TraceUnreg</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1185181363313"><a name="p1185181363313"></a><a name="p1185181363313"></a>Trace类型解注册</p>
</td>
</tr>
<tr id="row1518581363317"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p20974111585115"><a name="p20974111585115"></a><a name="p20974111585115"></a>开关</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p91858132336"><a name="p91858132336"></a><a name="p91858132336"></a>LOS_TraceTypeSwitch</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p11185121313333"><a name="p11185121313333"></a><a name="p11185121313333"></a>Trace分类开关</p>
</td>
</tr>
<tr id="row14185101310339"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1185151323311"><a name="p1185151323311"></a><a name="p1185151323311"></a>LOS_TraceSwitch</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p61852135331"><a name="p61852135331"></a><a name="p61852135331"></a>Trace总开关</p>
</td>
</tr>
<tr id="row71858133339"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p12306322125115"><a name="p12306322125115"></a><a name="p12306322125115"></a>数据导出</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p481141115110"><a name="p481141115110"></a><a name="p481141115110"></a>LOS_TraceBufDataGet</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p131851813173314"><a name="p131851813173314"></a><a name="p131851813173314"></a>Trace数据获取到堆缓存（缓存空间内部申请，使用完需显式释放）</p>
</td>
</tr>
<tr id="row10185131373310"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p31851139333"><a name="p31851139333"></a><a name="p31851139333"></a>LOS_Trace2File</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p121856132333"><a name="p121856132333"></a><a name="p121856132333"></a>Trace数据存储到文件系统（依赖文件系统）</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   frame buffer是个循环buffer，如果记录过长时间会覆盖旧的信息，该buffer的大小可以在los\_config.h中LOS\_TRACE\_BUFFER\_SIZE宏配置，默认配置512KiB。
>-   尽管Trace已经尽快的完成了组装及记录，但是仍旧会对系统整体性能产生不可避免的影响。
>-   Trace支持多个模块的Trace同时记录，根据需要开关各个模块的Trace，有助于降低数据分析量。
>-   当前内核的task、memory、liteipc模块支持Trace记录功能。

