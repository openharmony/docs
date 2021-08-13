# 进程<a name="ZH-CN_TOPIC_0000001078704186"></a>

-   [基本概念](#section89346055119)
-   [运行机制](#section174514474512)
-   [开发指导](#section159637182521)
    -   [接口说明](#section1153124135212)
    -   [开发流程](#section1533674618526)


## 基本概念<a name="section89346055119"></a>

进程是系统资源管理的最小单元。OpenHarmony LiteOS-A内核提供的进程模块主要用于实现用户态进程的隔离，内核态被视为一个进程空间，不存在其它进程\(KIdle除外，KIdle进程是系统提供的空闲进程，和KProcess共享一个进程空间）。

-   OpenHarmony 的进程模块主要为用户提供多个进程，实现了进程之间的切换和通信，帮助用户管理业务程序流程。
-   OpenHarmony 的进程采用抢占式调度机制，采用高优先级优先+同优先级时间片轮转的调度算法。
-   OpenHarmony 的进程一共有32个优先级\(0-31\)，用户进程可配置的优先级有22个\(10-31\)，最高优先级为10，最低优先级为31。
-   高优先级的进程可抢占低优先级进程，低优先级进程必须在高优先级进程阻塞或结束后才能得到调度。
-   每一个用户态进程均拥有自己独立的进程空间，相互之间不可见，实现进程间隔离。
-   用户态根进程init由内核态创建，其它用户态子进程均由init进程fork而来。

**进程状态说明：**

-   初始化（Init）：进程正在被创建。

-   就绪（Ready）：进程在就绪列表中，等待CPU调度。
-   运行（Running）：进程正在运行。
-   阻塞（Pending）：进程被阻塞挂起。本进程内所有的线程均被阻塞时，进程被阻塞挂起。
-   僵尸（Zombies）：进程运行结束，等待父进程回收其控制块资源。

**图 1**  进程状态迁移示意图<a name="fig13604525122919"></a>  
![](figure/进程状态迁移示意图.png "进程状态迁移示意图")

**进程状态迁移说明：**

-   Init→Ready：

    进程创建或fork时，拿到该进程控制块后进入Init状态，处于进程初始化阶段，当进程初始化完成将进程插入调度队列，此时进程进入就绪状态。

-   Ready→Running：

    进程创建后进入就绪态，发生进程切换时，就绪列表中最高优先级的进程被执行，从而进入运行态。若此时该进程中已无其它线程处于就绪态，则进程从就绪列表删除，只处于运行态；若此时该进程中还有其它线程处于就绪态，则该进程依旧在就绪队列，此时进程的就绪态和运行态共存，但对外呈现的进程状态为运行态。

-   Running→Pending：

    进程在最后一个线程转为阻塞态时， 进程内所有的线程均处于阻塞态，此时进程同步进入阻塞态，然后发生进程切换。

-   Pending→Ready：

    阻塞进程内的任意线程恢复就绪态时，进程被加入到就绪队列，同步转为就绪态。

-   Ready→Pending：

    进程内的最后一个就绪态线程转为阻塞态时，进程从就绪列表中删除，进程由就绪态转为阻塞态。

-   Running→Ready：

    进程由运行态转为就绪态的情况有以下两种：

    1.  有更高优先级的进程创建或者恢复后，会发生进程调度，此刻就绪列表中最高优先级进程变为运行态，那么原先运行的进程由运行态变为就绪态。
    2.  若进程的调度策略为LOS\_SCHED\_RR，且存在同一优先级的另一个进程处于就绪态，则该进程的时间片消耗光之后，该进程由运行态转为就绪态，另一个同优先级的进程由就绪态转为运行态。

-   Running→Zombies：

    当进程的主线程或所有线程运行结束后，进程由运行态转为僵尸态，等待父进程回收资源。


## 运行机制<a name="section174514474512"></a>

OpenHarmony 提供的进程模块主要用于实现用户态进程的隔离，支持用户态进程的创建、退出、资源回收、设置/获取调度参数、获取进程ID、设置/获取进程组ID等功能。

用户态进程通过fork父进程而来，fork进程时会将父进程的进程虚拟内存空间clone到子进程，子进程实际运行时通过写时复制机制将父进程的内容按需复制到子进程的虚拟内存空间。

进程只是资源管理单元，实际运行是由进程内的各个线程完成的，不同进程内的线程相互切换时会进行进程空间的切换。

**图 2**  进程管理示意图<a name="fig5251243193113"></a>  


![](figure/zh-cn_image_0000001127519136.png)

## 开发指导<a name="section159637182521"></a>

### 接口说明<a name="section1153124135212"></a>

**表 1**  进程管理模块接口

<a name="table359914125718"></a>
<table><thead align="left"><tr id="row85991712770"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p13162121815218"><a name="p13162121815218"></a><a name="p13162121815218"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p12162618623"><a name="p12162618623"></a><a name="p12162618623"></a>接口<strong id="b197068338312"><a name="b197068338312"></a><a name="b197068338312"></a>名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p16162118427"><a name="p16162118427"></a><a name="p16162118427"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row66002121074"><td class="cellrowborder" rowspan="4" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p13571544484"><a name="p13571544484"></a><a name="p13571544484"></a>进程调度参数控制</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p7571644283"><a name="p7571644283"></a><a name="p7571644283"></a>LOS_GetProcessScheduler</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p205724410813"><a name="p205724410813"></a><a name="p205724410813"></a>获取指定进程的调度策略</p>
</td>
</tr>
<tr id="row166001712574"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6571144286"><a name="p6571144286"></a><a name="p6571144286"></a>LOS_SetProcessScheduler</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p18572443819"><a name="p18572443819"></a><a name="p18572443819"></a>设置指定进程的调度参数，包括优先级和调度策略</p>
</td>
</tr>
<tr id="row1560071212719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3571144885"><a name="p3571144885"></a><a name="p3571144885"></a>LOS_GetProcessPriority</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p95710448818"><a name="p95710448818"></a><a name="p95710448818"></a>获取指定进程的优先级</p>
</td>
</tr>
<tr id="row1274011131587"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17572443812"><a name="p17572443812"></a><a name="p17572443812"></a>LOS_SetProcessPriority</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p16573445819"><a name="p16573445819"></a><a name="p16573445819"></a>设置指定进程的优先级</p>
</td>
</tr>
<tr id="row162882182816"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p175734417814"><a name="p175734417814"></a><a name="p175734417814"></a>等待回收子进程</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p165754410812"><a name="p165754410812"></a><a name="p165754410812"></a>LOS_Wait</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p5578441687"><a name="p5578441687"></a><a name="p5578441687"></a>等待子进程结束并回收子进程</p>
</td>
</tr>
<tr id="row81051920589"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p4571844289"><a name="p4571844289"></a><a name="p4571844289"></a>进程组</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p20578442083"><a name="p20578442083"></a><a name="p20578442083"></a>LOS_GetProcessGroupID</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p145704416818"><a name="p145704416818"></a><a name="p145704416818"></a>获取指定进程的进程组ID</p>
</td>
</tr>
<tr id="row13410161611819"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p657944289"><a name="p657944289"></a><a name="p657944289"></a>LOS_GetCurrProcessGroupID</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p165816445819"><a name="p165816445819"></a><a name="p165816445819"></a>获取当前进程的进程组ID</p>
</td>
</tr>
<tr id="row1260011213718"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p125818441781"><a name="p125818441781"></a><a name="p125818441781"></a>获取进程ID</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p25814445819"><a name="p25814445819"></a><a name="p25814445819"></a>LOS_GetCurrProcessID</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1058644687"><a name="p1058644687"></a><a name="p1058644687"></a>获取当前进程的进程ID</p>
</td>
</tr>
<tr id="row060019121871"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p145810441285"><a name="p145810441285"></a><a name="p145810441285"></a>用户及用户组</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p10581744783"><a name="p10581744783"></a><a name="p10581744783"></a>LOS_GetUserID</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p7581944287"><a name="p7581944287"></a><a name="p7581944287"></a>获取当前进程的用户ID</p>
</td>
</tr>
<tr id="row1160021211713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18582447814"><a name="p18582447814"></a><a name="p18582447814"></a>LOS_GetGroupID</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p3581444382"><a name="p3581444382"></a><a name="p3581444382"></a>获取当前进程的用户组ID</p>
</td>
</tr>
<tr id="row1160018123717"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p19589442084"><a name="p19589442084"></a><a name="p19589442084"></a>LOS_CheckInGroups</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5581144689"><a name="p5581144689"></a><a name="p5581144689"></a>检查指定用户组ID是否在当前进程的用户组内</p>
</td>
</tr>
<tr id="row317461111812"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p105814419818"><a name="p105814419818"></a><a name="p105814419818"></a>系统支持的最大进程数</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p3583441888"><a name="p3583441888"></a><a name="p3583441888"></a>LOS_GetSystemProcessMaximum</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p115818441187"><a name="p115818441187"></a><a name="p115818441187"></a>获取系统支持的最大进程数目</p>
</td>
</tr>
</tbody>
</table>

### 开发流程<a name="section1533674618526"></a>

不支持内核态进程创建，内核态不涉及进程相关开发。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   idle线程的数量跟随CPU核心数，每个CPU均有一个相应的idle线程。
>-   不支持创建除KProcess和KIdle进程之外的其它内核态进程。
>-   用户态进程通过系统调用进入内核态后创建的线程属于KProcess, 不属于当前用户态进程。

