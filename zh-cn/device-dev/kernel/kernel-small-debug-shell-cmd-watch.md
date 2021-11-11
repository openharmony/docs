# watch<a name="ZH-CN_TOPIC_0000001134006258"></a>

-   [命令功能](#section20643141481314)
-   [命令格式](#section1075441721316)
-   [参数说明](#section1472810220135)
-   [使用指南](#section186772414131)
-   [使用实例](#section4764192791314)
-   [输出说明](#section5791253155517)

## 命令功能<a name="section20643141481314"></a>

watch命令用于周期性的监视一个命令的运行结果。

## 命令格式<a name="section1075441721316"></a>

watch

watch \[_-c/-n/-t/--count/--interval/-no-title/--over_\] \[_command_\]

## 参数说明<a name="section1472810220135"></a>

**表 1**  参数说明

<a name="table966mcpsimp"></a>
<table><thead align="left"><tr id="row973mcpsimp"><th class="cellrowborder" valign="top" width="19.801980198019802%" id="mcps1.2.5.1.1"><p id="p975mcpsimp"><a name="p975mcpsimp"></a><a name="p975mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="29.222922292229224%" id="mcps1.2.5.1.2"><p id="p977mcpsimp"><a name="p977mcpsimp"></a><a name="p977mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="22.26222622262226%" id="mcps1.2.5.1.3"><p id="p979mcpsimp"><a name="p979mcpsimp"></a><a name="p979mcpsimp"></a>缺省值</p>
</th>
<th class="cellrowborder" valign="top" width="28.712871287128717%" id="mcps1.2.5.1.4"><p id="p981mcpsimp"><a name="p981mcpsimp"></a><a name="p981mcpsimp"></a>取值范围</p>
</th>
</tr>
</thead>
<tbody><tr id="row982mcpsimp"><td class="cellrowborder" valign="top" width="19.801980198019802%" headers="mcps1.2.5.1.1 "><p id="p984mcpsimp"><a name="p984mcpsimp"></a><a name="p984mcpsimp"></a>-c / --count</p>
</td>
<td class="cellrowborder" valign="top" width="29.222922292229224%" headers="mcps1.2.5.1.2 "><p id="p986mcpsimp"><a name="p986mcpsimp"></a><a name="p986mcpsimp"></a>命令执行的总次数。</p>
</td>
<td class="cellrowborder" valign="top" width="22.26222622262226%" headers="mcps1.2.5.1.3 "><p id="p988mcpsimp"><a name="p988mcpsimp"></a><a name="p988mcpsimp"></a>0xFFFFFF</p>
</td>
<td class="cellrowborder" valign="top" width="28.712871287128717%" headers="mcps1.2.5.1.4 "><p id="p990mcpsimp"><a name="p990mcpsimp"></a><a name="p990mcpsimp"></a>（0,0xFFFFFF]</p>
</td>
</tr>
<tr id="row991mcpsimp"><td class="cellrowborder" valign="top" width="19.801980198019802%" headers="mcps1.2.5.1.1 "><p id="p993mcpsimp"><a name="p993mcpsimp"></a><a name="p993mcpsimp"></a>-n / --interval</p>
</td>
<td class="cellrowborder" valign="top" width="29.222922292229224%" headers="mcps1.2.5.1.2 "><p id="p995mcpsimp"><a name="p995mcpsimp"></a><a name="p995mcpsimp"></a>命令周期性执行的时间间隔（s）。</p>
</td>
<td class="cellrowborder" valign="top" width="22.26222622262226%" headers="mcps1.2.5.1.3 "><p id="p997mcpsimp"><a name="p997mcpsimp"></a><a name="p997mcpsimp"></a>1s</p>
</td>
<td class="cellrowborder" valign="top" width="28.712871287128717%" headers="mcps1.2.5.1.4 "><p id="p999mcpsimp"><a name="p999mcpsimp"></a><a name="p999mcpsimp"></a>（0,0xFFFFFF]</p>
</td>
</tr>
<tr id="row1000mcpsimp"><td class="cellrowborder" valign="top" width="19.801980198019802%" headers="mcps1.2.5.1.1 "><p id="p1002mcpsimp"><a name="p1002mcpsimp"></a><a name="p1002mcpsimp"></a>-t / -no-title</p>
</td>
<td class="cellrowborder" valign="top" width="29.222922292229224%" headers="mcps1.2.5.1.2 "><p id="p1004mcpsimp"><a name="p1004mcpsimp"></a><a name="p1004mcpsimp"></a>关闭顶端的时间显示。</p>
</td>
<td class="cellrowborder" valign="top" width="22.26222622262226%" headers="mcps1.2.5.1.3 "><p id="p1006mcpsimp"><a name="p1006mcpsimp"></a><a name="p1006mcpsimp"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="28.712871287128717%" headers="mcps1.2.5.1.4 "><p id="p1008mcpsimp"><a name="p1008mcpsimp"></a><a name="p1008mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row1009mcpsimp"><td class="cellrowborder" valign="top" width="19.801980198019802%" headers="mcps1.2.5.1.1 "><p id="p1011mcpsimp"><a name="p1011mcpsimp"></a><a name="p1011mcpsimp"></a>command</p>
</td>
<td class="cellrowborder" valign="top" width="29.222922292229224%" headers="mcps1.2.5.1.2 "><p id="p1013mcpsimp"><a name="p1013mcpsimp"></a><a name="p1013mcpsimp"></a>需要监测的命令。</p>
</td>
<td class="cellrowborder" valign="top" width="22.26222622262226%" headers="mcps1.2.5.1.3 "><p id="p1015mcpsimp"><a name="p1015mcpsimp"></a><a name="p1015mcpsimp"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="28.712871287128717%" headers="mcps1.2.5.1.4 "><p id="p1017mcpsimp"><a name="p1017mcpsimp"></a><a name="p1017mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row1018mcpsimp"><td class="cellrowborder" valign="top" width="19.801980198019802%" headers="mcps1.2.5.1.1 "><p id="p1020mcpsimp"><a name="p1020mcpsimp"></a><a name="p1020mcpsimp"></a>--over</p>
</td>
<td class="cellrowborder" valign="top" width="29.222922292229224%" headers="mcps1.2.5.1.2 "><p id="p1022mcpsimp"><a name="p1022mcpsimp"></a><a name="p1022mcpsimp"></a>关闭当前监测指令。</p>
</td>
<td class="cellrowborder" valign="top" width="22.26222622262226%" headers="mcps1.2.5.1.3 "><p id="p1024mcpsimp"><a name="p1024mcpsimp"></a><a name="p1024mcpsimp"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="28.712871287128717%" headers="mcps1.2.5.1.4 "><p id="p1026mcpsimp"><a name="p1026mcpsimp"></a><a name="p1026mcpsimp"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="section186772414131"></a>

watch运行过程中可以执行**watch --over**结束本次watch命令。

## 使用实例<a name="section4764192791314"></a>

输入举例：

watch  -n 2 -c 6 task

## 输出说明<a name="section5791253155517"></a>

**示例 1**  watch task 结果

```shell
OHOS # watch  -n 2 -c 6 task
Thu Jan  1 23:57:13 1970

OHOS #
  allCpu(%):    3.55 sys,  196.45 idle

  PID  PPID PGID       UID  Status VirtualMem ShareMem PhysicalMem CPUUSE10s  PName
    1    -1    1         0 Pending   0x33b000  0xbb000     0x4dc8b      0.0   init
    2    -1    2         0 Running  0x19524f2        0   0x19524f2      1.14  KProcess
    3     1    3         7 Pending   0x730000 0x1a2000    0x1d34f6      0.0   foundation
    4     1    4         8 Pending   0x35e000  0xb8000     0x56777      0.0   bundle_daemon
    5     1    5         1 Pending   0xdfa000 0x2e7000    0x1487ce      0.0   appspawn
    6     1    6         0 Pending   0x688000 0x137000    0x11c518      0.0   media_server
    7     1    7         0 Pending   0x9d2000 0x103000     0xa1ddf      0.95  wms_server
    8     1    1      1000 Running   0x2bf000  0x8f000     0x2a8c6      0.0   shell
    9     5    5       101 Pending  0x11ea000 0x2f9000    0x20429d      1.2   com.huawei.launcher
   11     1   11         0 Pending   0x4d4000 0x112000     0xe0ad7      0.0   deviceauth_service
   12     1   12         0 Pending   0x34f000  0xbd000     0x519ee      0.0   sensor_service
   13     1   13         2 Pending   0x34e000  0xb3000     0x523d9      0.0   ai_server
   14     1   14         0 Pending   0x61f000 0x13b000    0x16841c      0.51  softbus_server

  TID  PID Affi CPU       Status StackSize WaterLine CPUUSE10s    MEMUSE  TaskName
   23    1  0x3  -1      Pending    0x3000     0xe44      0.0           0  init
    1    2  0x1  -1      Pending    0x4000     0x2c4      0.64          0  Swt_Task
    2    2  0x3  -1      Pending    0x4000     0x204      0.0           0  system_wq
    3    2  0x2  -1      Pending    0x4000     0x514      0.40          0  Swt_Task
    4    2  0x3  -1      Pending    0x1000     0x36c      0.0           0  ResourcesTask
    7    2  0x3  -1      Pending    0x4e20     0xa5c      0.0           0  PlatformWorkerThread
    8    2  0x3  -1      Pending    0x4e20     0xa6c      0.0           0  PlatformWorkerThread
    9    2  0x3  -1      Pending    0x4e20     0xa5c      0.0           0  PlatformWorkerThread
   10    2  0x3  -1     PendTime    0x4000     0x3e4      0.5           0  hi_vdec_thread
   11    2  0x3  -1      Pending    0x3000     0x4cc      0.0           0  bcache_async_task
   12    2  0x3  -1      Pending    0x2710     0x224      0.0           0  LiteOS usb pnp notify handle kt
   13    2  0x3  -1      Pending    0x4000     0x204      0.0           0  vibrator_queue
   14    2  0x3  -1      Pending    0x3000     0x37c      0.0           0  bcache_async_task
   15    2  0x3  -1      Pending   0x20000     0x3e4      0.0           0  eth_irq_Task
   16    2  0x3  -1     PendTime    0x2000     0x3a4      0.0           0  MessageDispatcher
   17    2  0x3   0      Running    0x3000     0x73c      0.0           0  shellcmd_watch
   18    2  0x3  -1      Pending    0x2710     0x3ac      0.0           0  GPIO_IRQ_TSK_0_4
```

>![](../public_sys-resources/icon-note.gif) **说明：** 
>示例中，总共有6次task命令打印，每次间隔2秒，示例1为最后一次打印详情。

