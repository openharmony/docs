# top

## Command Function<a name="section20643141481314"></a>

This command is used to query process and thread information.

## Syntax<a name="section1075441721316"></a>

top \[_-a_\]

## Parameters<a name="section1472810220135"></a>

**Table  1**  Parameter description

<a name="table966mcpsimp"></a>
<table><thead align="left"><tr id="row973mcpsimp"><th class="cellrowborder" valign="top" width="19.801980198019802%" id="mcps1.2.5.1.1"><p id="p975mcpsimp"><a name="p975mcpsimp"></a><a name="p975mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="29.222922292229224%" id="mcps1.2.5.1.2"><p id="p977mcpsimp"><a name="p977mcpsimp"></a><a name="p977mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="22.26222622262226%" id="mcps1.2.5.1.3"><p id="p979mcpsimp"><a name="p979mcpsimp"></a><a name="p979mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="28.712871287128717%" id="mcps1.2.5.1.4"><p id="p981mcpsimp"><a name="p981mcpsimp"></a><a name="p981mcpsimp"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row1643213388538"><td class="cellrowborder" valign="top" width="19.801980198019802%" headers="mcps1.2.5.1.1 "><p id="p11426113820531"><a name="p11426113820531"></a><a name="p11426113820531"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="29.222922292229224%" headers="mcps1.2.5.1.2 "><p id="p942673885313"><a name="p942673885313"></a><a name="p942673885313"></a>Displays the parameters supported by the <strong id="b2435956125215"><a name="b2435956125215"></a><a name="b2435956125215"></a>top</strong> command.</p>
</td>
<td class="cellrowborder" valign="top" width="22.26222622262226%" headers="mcps1.2.5.1.3 "><p id="p9426538195319"><a name="p9426538195319"></a><a name="p9426538195319"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="28.712871287128717%" headers="mcps1.2.5.1.4 ">&nbsp;&nbsp;</td>
</tr>
<tr id="row1943253865311"><td class="cellrowborder" valign="top" width="19.801980198019802%" headers="mcps1.2.5.1.1 "><p id="p1542613812537"><a name="p1542613812537"></a><a name="p1542613812537"></a>-a</p>
</td>
<td class="cellrowborder" valign="top" width="29.222922292229224%" headers="mcps1.2.5.1.2 "><p id="p1842663895320"><a name="p1842663895320"></a><a name="p1842663895320"></a>Displays detailed information.</p>
</td>
<td class="cellrowborder" valign="top" width="22.26222622262226%" headers="mcps1.2.5.1.3 "><p id="p13426123815313"><a name="p13426123815313"></a><a name="p13426123815313"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="28.712871287128717%" headers="mcps1.2.5.1.4 ">&nbsp;&nbsp;</td>
</tr>
</tbody>
</table>

## Usage<a name="section186772414131"></a>

If no parameter is specified, this command displays process and thread information of some tasks by default.

## Example<a name="section4764192791314"></a>

Run  **top**.

## Output<a name="section5791253155517"></a>

Command output

```
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

**Table  2**  Output description

<a name="table1522165195511"></a>
<table><thead align="left"><tr id="row1952285165514"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p25224518556"><a name="p25224518556"></a><a name="p25224518556"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p16522852554"><a name="p16522852554"></a><a name="p16522852554"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row207354303550"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p107238309551"><a name="p107238309551"></a><a name="p107238309551"></a>PID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p372373015515"><a name="p372373015515"></a><a name="p372373015515"></a>Process ID</p>
</td>
</tr>
<tr id="row1373513035514"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p972343012551"><a name="p972343012551"></a><a name="p972343012551"></a>PPID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p19723153055519"><a name="p19723153055519"></a><a name="p19723153055519"></a>Parent process ID</p>
</td>
</tr>
<tr id="row16735133035518"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p14723153065514"><a name="p14723153065514"></a><a name="p14723153065514"></a>PGID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p117231630165519"><a name="p117231630165519"></a><a name="p117231630165519"></a>Process group ID</p>
</td>
</tr>
<tr id="row157354306558"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p3723430195510"><a name="p3723430195510"></a><a name="p3723430195510"></a>UID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1372373016559"><a name="p1372373016559"></a><a name="p1372373016559"></a>User ID</p>
</td>
</tr>
<tr id="row573515301555"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1472318308552"><a name="p1472318308552"></a><a name="p1472318308552"></a>Status</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p57231430165518"><a name="p57231430165518"></a><a name="p57231430165518"></a>Current task status</p>
</td>
</tr>
<tr id="row15735730135515"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p472363045510"><a name="p472363045510"></a><a name="p472363045510"></a>CPUUSE10s</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1172323019556"><a name="p1172323019556"></a><a name="p1172323019556"></a>CPU usage within last 10 seconds</p>
</td>
</tr>
<tr id="row16735163025519"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p10723183035516"><a name="p10723183035516"></a><a name="p10723183035516"></a>PName</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1472310309557"><a name="p1472310309557"></a><a name="p1472310309557"></a>Process name</p>
</td>
</tr>
<tr id="row973593017554"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p13724123075515"><a name="p13724123075515"></a><a name="p13724123075515"></a>TID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p12724630135510"><a name="p12724630135510"></a><a name="p12724630135510"></a>Task ID</p>
</td>
</tr>
<tr id="row157341730135512"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p87241930135520"><a name="p87241930135520"></a><a name="p87241930135520"></a>StackSize</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p8724930135519"><a name="p8724930135519"></a><a name="p8724930135519"></a>Size of the task stack</p>
</td>
</tr>
<tr id="row187341330145517"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1172483055520"><a name="p1172483055520"></a><a name="p1172483055520"></a>WaterLine</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p10724103013559"><a name="p10724103013559"></a><a name="p10724103013559"></a>Peak value of the stack used</p>
</td>
</tr>
<tr id="row473473025513"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p87240306554"><a name="p87240306554"></a><a name="p87240306554"></a>MEMUSE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p10724123005519"><a name="p10724123005519"></a><a name="p10724123005519"></a>Memory usage</p>
</td>
</tr>
<tr id="row18734143035519"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7724163011559"><a name="p7724163011559"></a><a name="p7724163011559"></a>TaskName</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p872414301552"><a name="p872414301552"></a><a name="p872414301552"></a>Task name</p>
</td>
</tr>
</tbody>
</table>

