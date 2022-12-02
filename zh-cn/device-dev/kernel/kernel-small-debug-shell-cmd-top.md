# top


## 命令功能

top命令用于查询进程及线程信息。


## 命令格式

top [_-a_]


## 参数说明

**表1** 参数说明

| 参数   | 参数说明                    |
| ------ | --------------------------- |
| --help | 查看top命令支持的参数列表。 |
| -a     | 显示更详细的信息。          |


## 使用指南

参数缺省时默认打印部分任务信息。

## 特殊说明

shell端暂不支持。切换mksh版本可全支持，方法：cd bin; ./mksh。

## 使用实例

举例：输入top


## 输出说明

**示例1** top 命令显示详情

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

**表2** 输出元素说明

| 输出      | 说明              |
| --------- | ----------------- |
| PID       | 进程ID。          |
| PPID      | 父进程ID。        |
| PGID      | 进程组ID。        |
| UID       | 用户ID。          |
| Status    | 任务当前的状态。  |
| CPUUSE10s | 10秒内CPU使用率。 |
| PName     | 进程名。          |
| TID       | 任务ID。          |
| StackSize | 任务堆栈的大小。  |
| WaterLine | 栈使用的峰值。    |
| MEMUSE    | 内存使用量。      |
| TaskName  | 任务名。          |