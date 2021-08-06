# 读写锁<a name="ZH-CN_TOPIC_0000001078912738"></a>

-   [基本概念](#section4692105214260)
-   [运行机制](#section1239111562720)
-   [开发指导](#section11643194275)
    -   [接口说明](#section15335332122717)
    -   [开发流程](#section14774114882714)


## 基本概念<a name="section4692105214260"></a>

读写锁与互斥锁类似，可用来同步同一进程中的各个任务，但与互斥锁不同的是，其允许多个读操作并发重入，而写操作互斥。

相对于互斥锁的开锁或闭锁状态，读写锁有三种状态：读模式下的锁，写模式下的锁，无锁。

读写锁的使用规则：

-   保护区无写模式下的锁，任何任务均可以为其增加读模式下的锁。
-   保护区处于无锁状态下，才可增加写模式下的锁。

多任务环境下往往存在多个任务访问同一共享资源的应用场景，读模式下的锁以共享状态对保护区访问，而写模式下的锁可被用于对共享资源的保护从而实现独占式访问。

这种共享-独占的方式非常适合多任务中读数据频率远大于写数据频率的应用中，提高应用多任务并发度。

## 运行机制<a name="section1239111562720"></a>

相较于互斥锁，读写锁如何实现读模式下的锁及写模式下的锁来控制多任务的读写访问呢？

-   若A任务首次获取了写模式下的锁，有其他任务来获取或尝试获取读模式下的锁，均无法再上锁。

-   若A任务获取了读模式下的锁，当有任务来获取或尝试获取读模式下的锁时，读写锁计数均加一。

## 开发指导<a name="section11643194275"></a>

### 接口说明<a name="section15335332122717"></a>

**表 1**  读写锁模块接口

<a name="table37108292611"></a>
<table><thead align="left"><tr id="row8711112919610"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p3711102912617"><a name="p3711102912617"></a><a name="p3711102912617"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p1671110293610"><a name="p1671110293610"></a><a name="p1671110293610"></a>接口<strong id="b197068338312"><a name="b197068338312"></a><a name="b197068338312"></a>名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p87114292617"><a name="p87114292617"></a><a name="p87114292617"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row37115291166"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1795312108911"><a name="p1795312108911"></a><a name="p1795312108911"></a>读写锁的创建和删除</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1671120293611"><a name="p1671120293611"></a><a name="p1671120293611"></a>LOS_RwlockInit</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p171112291967"><a name="p171112291967"></a><a name="p171112291967"></a>创建读写锁</p>
</td>
</tr>
<tr id="row17711329268"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p071114291864"><a name="p071114291864"></a><a name="p071114291864"></a>LOS_RwlockDestroy</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p137111129965"><a name="p137111129965"></a><a name="p137111129965"></a>删除指定的读写锁</p>
</td>
</tr>
<tr id="row5711192912616"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p86087143910"><a name="p86087143910"></a><a name="p86087143910"></a>读模式下的锁的申请</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1171112295614"><a name="p1171112295614"></a><a name="p1171112295614"></a>LOS_RwlockRdLock</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1271110291969"><a name="p1271110291969"></a><a name="p1271110291969"></a>申请指定的读模式下的锁</p>
</td>
</tr>
<tr id="row1571162918615"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1564192618292"><a name="p1564192618292"></a><a name="p1564192618292"></a>LOS_RwlockTryRdLock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p107118291660"><a name="p107118291660"></a><a name="p107118291660"></a>尝试申请指定的读模式下的锁</p>
</td>
</tr>
<tr id="row189551130172817"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p7951153082815"><a name="p7951153082815"></a><a name="p7951153082815"></a>写模式下的锁的申请</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p111591404308"><a name="p111591404308"></a><a name="p111591404308"></a>LOS_RwlockWrLock</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p11951183013281"><a name="p11951183013281"></a><a name="p11951183013281"></a>申请指定的写模式下的锁</p>
</td>
</tr>
<tr id="row199551530122820"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p32171573014"><a name="p32171573014"></a><a name="p32171573014"></a>LOS_RwlockTryWrLock</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5951123092819"><a name="p5951123092819"></a><a name="p5951123092819"></a>尝试申请指定的写模式下的锁</p>
</td>
</tr>
<tr id="row1642820328301"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1542823210305"><a name="p1542823210305"></a><a name="p1542823210305"></a>读写锁的释放</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p174281324308"><a name="p174281324308"></a><a name="p174281324308"></a>LOS_RwlockUnLock</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1342810327309"><a name="p1342810327309"></a><a name="p1342810327309"></a>释放指定读写锁</p>
</td>
</tr>
<tr id="row11318134133111"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p73182345312"><a name="p73182345312"></a><a name="p73182345312"></a>读写锁有效性判断</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1031813416318"><a name="p1031813416318"></a><a name="p1031813416318"></a>LOS_RwlockIsValid</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p43187342311"><a name="p43187342311"></a><a name="p43187342311"></a>判断读写锁有效性</p>
</td>
</tr>
</tbody>
</table>

### 开发流程<a name="section14774114882714"></a>

读写锁典型场景的开发流程：

1. 创建读写锁LOS\_RwlockInit。

2. 申请读模式下的锁LOS\_RwlockRdLock或写模式下的锁LOS\_RwlockWrLock。

申请读模式下的锁：

-   若无人持有锁，读任务可获得锁。
-   若有人持有锁，读任务可获得锁，读取顺序按照任务优先级。
-   若有人（非自己）持有写模式下的锁，则当前任务无法获得锁，直到写模式下的锁释放。

申请写模式下的锁：

-   若该锁当前没有任务持有，或者持有该读模式下的锁的任务和申请该锁的任务为同一个任务，则申请成功，可立即获得写模式下的锁。
-   若该锁当前已经存在读模式下的锁，且读取任务优先级较高，则当前任务挂起，直到读模式下的锁释放。

3.申请读模式下的锁和写模式下的锁均有三种：无阻塞模式、永久阻塞模式、定时阻塞模式，区别在于挂起任务的时间。

4.释放读写锁LOS\_RwlockUnLock。

-   如果有任务阻塞于指定读写锁，则唤醒被阻塞任务中优先级高的，该任务进入就绪态，并进行任务调度；

-   如果没有任务阻塞于指定读写锁，则读写锁释放成功。

5. 删除读写锁LOS\_RwlockDestroy。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   读写锁不能在中断服务程序中使用。
>-   LiteOS-A内核作为实时操作系统需要保证任务调度的实时性，尽量避免任务的长时间阻塞，因此在获得读写锁之后，应该尽快释放该锁。
>-   持有读写锁的过程中，不得再调用LOS\_TaskPriSet等接口更改持有读写锁任务的优先级

