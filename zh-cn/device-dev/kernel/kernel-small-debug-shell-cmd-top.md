# top<a name="ZH-CN_TOPIC_0000001179845936"></a>

-   [命令功能](#section01)
-   [命令格式](#section02)
-   [参数说明](#section03)
-   [使用指南](#section04)
-   [使用实例](#section05)
-   [输出说明](#section06)

## 命令功能<a name="section01"></a>

top命令用于查询进程及线程信息。

## 命令格式<a name="section02"></a>

top \[_-a_\]

## 参数说明<a name="section03"></a>

**表 1**  参数说明

<a name="table1557mcpsimp"></a>
<table><thead align="left"><tr id="row1563mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1565mcpsimp"><a name="p1565mcpsimp"></a><a name="p1565mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p1567mcpsimp"><a name="p1567mcpsimp"></a><a name="p1567mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1569mcpsimp"><a name="p1569mcpsimp"></a><a name="p1569mcpsimp"></a>取值范围</p>
</th>
</tr>
</thead>
<tbody><tr id="row451mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2500105121818"><a name="p2500105121818"></a><a name="p2500105121818"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p1149945111817"><a name="p1149945111817"></a><a name="p1149945111817"></a>查看top命令支持的参数列表。</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p749810571812"><a name="p749810571812"></a><a name="p749810571812"></a>N/A</p>
</td>
</tr>
<tr id="row451mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2500105121818"><a name="p2500105121818"></a><a name="p2500105121818"></a>-a</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p1149945111817"><a name="p1149945111817"></a><a name="p1149945111817"></a>显示更详细的信息。</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p749810571812"><a name="p749810571812"></a><a name="p749810571812"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="section04"></a>

-   参数缺省时默认打印部分任务信息。

## 使用实例<a name="section05"></a>

举例：输入top

## 输出说明<a name="section06"></a>

**示例 1**  top 命令显示详情

```shell
OHOS:/$ top

  allCpu(%):    4.68 sys,  195.32 idle

  PID  PPID PGID       UID  Status VirtualMem ShareMem PhysicalMem CPUUSE10s  PName
    1    -1    1         0 Pending   0x33b000  0xbb000     0x4e01c      0.0   init
    2    -1    2         0 Pending   0xd838c0        0    0xd838c0      1.16  KProcess
    3     1    3         7 Pending   0x72e000 0x1a3000    0x1d29dc      0.0   foundation
    4     1    4         8 Pending   0x362000  0xbb000     0x5cc19      0.0   bundle_daemon
    5     1    5         1 Pending   0xdfa000 0x2e7000    0x148a0a      0.0   appspawn
    6     1    6         0 Pending   0x688000 0x137000    0x11c1ba      0.0   media_server
    7     1    7         0 Pending   0x9d2000 0x103000     0xa21f9      0.87  wms_server
    8     1    8         2 Pending   0x1f5000  0x48000     0x462dc      0.0   mksh
    9     5    5       101 Pending  0x11ea000 0x2f9000    0x204561      0.94  com.huawei.launcher
   11     1   11         0 Pending   0x4d4000 0x112000     0xe0d9c      0.0   deviceauth_service
   12     1   12         0 Pending   0x34f000  0xbd000     0x51cb3      0.0   sensor_service
   13     1   13         2 Pending   0x34e000  0xb3000     0x5269e      0.0   ai_server
   14     1   14         0 Pending   0x61f000 0x13b000    0x16858b      0.45  softbus_server
   43     8   43         2 Running   0x1d7000  0x3a000     0x1e9f5      0.0   toybox

  TID  PID Affi CPU       Status StackSize WaterLine CPUUSE10s    MEMUSE  TaskName
   23    1  0x3  -1      Pending    0x3000     0xcf4      0.0           0  init
    1    2  0x1  -1      Pending    0x4000     0x2c4      0.33          0  Swt_Task
    2    2  0x3  -1      Pending    0x4000     0x204      0.0           0  system_wq
    3    2  0x2  -1      Pending    0x4000     0x514      0.75          0  Swt_Task
    4    2  0x3  -1      Pending    0x1000     0x3ac      0.0           0  ResourcesTask
    7    2  0x3  -1      Pending    0x4e20     0xa5c      0.0           0  PlatformWorkerThread
    8    2  0x3  -1      Pending    0x4e20     0xa6c      0.0           0  PlatformWorkerThread
    9    2  0x3  -1      Pending    0x4e20     0xbf4      0.0           0  PlatformWorkerThread
   10    2  0x3  -1      Pending    0x3000     0x4dc      0.0           0  bcache_async_task
   11    2  0x3  -1     PendTime    0x4000     0x3e4      0.5           0  hi_vdec_thread
   12    2  0x3  -1      Pending    0x2710     0x224      0.0           0  LiteOS usb pnp notify handle kt
   13    2  0x3  -1      Pending    0x3000     0x37c      0.0           0  bcache_async_task
   14    2  0x3  -1      Pending    0x4000     0x204      0.0           0  vibrator_queue
   15    2  0x3  -1      Pending   0x20000     0x35c      0.0           0  eth_irq_Task
   16    2  0x3  -1     PendTime    0x2000     0x354      0.0           0  MessageDispatcher
   18    2  0x3  -1      Pending    0x2710     0x200      0.0           0  GPIO_IRQ_TSK_0_4
   19    2  0x3  -1      Pending    0x4000     0x204      0.0           0  dispWQ
   20    2  0x3  -1      Pending    0x4000     0x204      0.0           0  hdf_sensor_test_work_queue
   21    2  0x3  -1     PendTime    0x6000     0x40c      0.2           0  tcpip_thread
   22    2  0x3  -1      Pending    0x4000     0x36c      0.0           0  SendToSer
   61    2  0x3  -1      Pending    0x4000     0x244      0.0           0  USB_GIANT_Task
   63    2  0x3  -1      Pending    0x4000     0x244      0.0           0  USB_NGIAN_ISOC_Task
   64    2  0x3  -1      Pending    0x4000     0x244      0.0           0  USB_NGIAN_BULK_TasK
```

**表2**  输出元素说明

<table><thead align="left"><tr id="row814mcpsimp"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p816mcpsimp"><a name="p816mcpsimp"></a><a name="p816mcpsimp"></a>输出</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p818mcpsimp"><a name="p818mcpsimp"></a><a name="p818mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row20360171311398"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p123611139397"><a name="p123611139397"></a><a name="p123611139397"></a>PID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p3361171333920"><a name="p3361171333920"></a><a name="p3361171333920"></a>进程ID。</p>
</td>
</tr>
<tr id="row262535153913"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p862625163918"><a name="p862625163918"></a><a name="p862625163918"></a>PPID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1062611511398"><a name="p1062611511398"></a><a name="p1062611511398"></a>父进程ID。</p>
</td>
</tr>
<tr id="row9683953153916"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p76831753103915"><a name="p76831753103915"></a><a name="p76831753103915"></a>PGID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2068355383916"><a name="p2068355383916"></a><a name="p2068355383916"></a>进程组ID。</p>
</td>
</tr>
<tr id="row85721136402"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p8572151313402"><a name="p8572151313402"></a><a name="p8572151313402"></a>UID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p55721813164013"><a name="p55721813164013"></a><a name="p55721813164013"></a>用户ID。</p>
</td>
</tr>
<tr id="row19180126151415"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p836mcpsimp"><a name="p836mcpsimp"></a><a name="p836mcpsimp"></a>Status</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p838mcpsimp"><a name="p838mcpsimp"></a><a name="p838mcpsimp"></a>任务当前的状态。</p>
</td>
</tr>
<tr id="row511517331702"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p2116833506"><a name="p2116833506"></a><a name="p2116833506"></a>CPUUSE10s</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2011611331604"><a name="p2011611331604"></a><a name="p2011611331604"></a>10秒内CPU使用率。</p>
</td>
</tr>
<tr id="row136191839311"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p66199397110"><a name="p66199397110"></a><a name="p66199397110"></a>PName</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p11619153916110"><a name="p11619153916110"></a><a name="p11619153916110"></a>进程名。</p>
</td>
</tr>
<tr id="row824mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p826mcpsimp"><a name="p826mcpsimp"></a><a name="p826mcpsimp"></a>TID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p828mcpsimp"><a name="p828mcpsimp"></a><a name="p828mcpsimp"></a>任务ID。</p>
</td>
</tr>
<tr id="row839mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p841mcpsimp"><a name="p841mcpsimp"></a><a name="p841mcpsimp"></a>StackSize</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p843mcpsimp"><a name="p843mcpsimp"></a><a name="p843mcpsimp"></a>任务堆栈的大小。</p>
</td>
</tr>
<tr id="row844mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p846mcpsimp"><a name="p846mcpsimp"></a><a name="p846mcpsimp"></a>WaterLine</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p848mcpsimp"><a name="p848mcpsimp"></a><a name="p848mcpsimp"></a>栈使用的峰值。</p>
</td>
</tr>
<tr id="row10188146131813"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p218912671818"><a name="p218912671818"></a><a name="p218912671818"></a>MEMUSE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1518926151810"><a name="p1518926151810"></a><a name="p1518926151810"></a>内存使用量。</p>
</td>
</tr>
<tr id="row45465584313"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p821mcpsimp"><a name="p821mcpsimp"></a><a name="p821mcpsimp"></a>TaskName</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p823mcpsimp"><a name="p823mcpsimp"></a><a name="p823mcpsimp"></a>任务名。</p>
</td>
</tr>
</tbody>
</table>
