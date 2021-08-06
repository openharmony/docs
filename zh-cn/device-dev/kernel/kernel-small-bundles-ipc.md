# 轻量级进程间通信<a name="ZH-CN_TOPIC_0000001123520161"></a>

-   [基本概念](#section1980994712918)
-   [运行机制](#section849811592918)
-   [开发指导](#section17571315171017)
    -   [接口说明](#section725022011103)


## 基本概念<a name="section1980994712918"></a>

LiteIPC是OpenHarmony LiteOS-A内核提供的一种新型IPC（Inter-Process Communication，即进程间通信）机制，不同于传统的System V IPC机制，LiteIPC主要是为RPC（Remote Procedure Call，即远程过程调用）而设计的，而且是通过设备文件的方式对上层提供接口的，而非传统的API函数方式。

LiteIPC中有两个主要概念，一个是ServiceManager，另一个是Service。整个系统只能有一个ServiceManager，而Service可以有多个。ServiceManager有两个主要功能：一是负责Service的注册和注销，二是负责管理Service的访问权限（只有有权限的任务（Task）可以向对应的Service发送IPC消息）。

## 运行机制<a name="section849811592918"></a>

首先将需要接收IPC消息的任务通过ServiceManager注册成为一个Service，然后通过ServiceManager为该Service任务配置访问权限，即指定哪些任务可以向该Service任务发送IPC消息。LiteIPC的核心思想就是在内核态为每个Service任务维护一个IPC消息队列，该消息队列通过LiteIPC设备文件向上层用户态程序分别提供代表收取IPC消息的读操作和代表发送IPC消息的写操作。

## 开发指导<a name="section17571315171017"></a>

### 接口说明<a name="section725022011103"></a>

**表 1**  LiteIPC模块接口（仅LiteOS-A内部使用）

<a name="table1415203765610"></a>
<table><thead align="left"><tr id="row134151837125611"><th class="cellrowborder" valign="top" width="12.85128512851285%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="29.8029802980298%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>接口<strong id="b197068338312"><a name="b197068338312"></a><a name="b197068338312"></a>名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="57.34573457345735%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row0415737175610"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p8866127195914"><a name="p8866127195914"></a><a name="p8866127195914"></a>模块初始化</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p58621910185914"><a name="p58621910185914"></a><a name="p58621910185914"></a>OsLiteIpcInit</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p48623102592"><a name="p48623102592"></a><a name="p48623102592"></a>初始化LiteIPC模块</p>
</td>
</tr>
<tr id="row1213865218584"><td class="cellrowborder" rowspan="3" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p1219312239566"><a name="p1219312239566"></a><a name="p1219312239566"></a>IPC消息内存池</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p20862510115911"><a name="p20862510115911"></a><a name="p20862510115911"></a>LiteIpcPoolInit</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p1886211011599"><a name="p1886211011599"></a><a name="p1886211011599"></a>初始化进程的IPC消息内存池</p>
</td>
</tr>
<tr id="row3231257145813"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3313428135414"><a name="p3313428135414"></a><a name="p3313428135414"></a>LiteIpcPoolReInit</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p586261085913"><a name="p586261085913"></a><a name="p586261085913"></a>重新初始化进程的IPC消息内存池</p>
</td>
</tr>
<tr id="row73651459105815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p464344145411"><a name="p464344145411"></a><a name="p464344145411"></a>LiteIpcPoolDelete</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p555221518598"><a name="p555221518598"></a><a name="p555221518598"></a>释放进程的IPC消息内存池</p>
</td>
</tr>
<tr id="row178321454145812"><td class="cellrowborder" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p19527545175517"><a name="p19527545175517"></a><a name="p19527545175517"></a>Service管理</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p756845455415"><a name="p756845455415"></a><a name="p756845455415"></a>LiteIpcRemoveServiceHandle</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p1555261595915"><a name="p1555261595915"></a><a name="p1555261595915"></a>删除指定的Service</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **说明：** 
>LiteIPC模块接口都只在LiteOS-A内部使用。

