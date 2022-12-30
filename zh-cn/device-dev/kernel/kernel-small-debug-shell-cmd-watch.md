# watch


## 命令功能

watch命令用于周期性的监视一个命令的运行结果。


## 命令格式

- watch

- watch [_-c/-n/-t/--count/--interval/-no-title/--over_] [_command_]


## 参数说明

  **表1** 参数说明

| 参数 | 参数说明 | 缺省值 | 取值范围 | 
| -------- | -------- | -------- | -------- |
| -c&nbsp;/&nbsp;--count | 命令执行的总次数。 | 0xFFFFFF | （0,0xFFFFFF] | 
| -n&nbsp;/&nbsp;--interval | 命令周期性执行的时间间隔（s）。 | 1s | （0,0xFFFFFF] | 
| -t&nbsp;/&nbsp;-no-title | 关闭顶端的时间显示。 | N/A | N/A | 
| command | 需要监测的命令。 | N/A | N/A | 
| --over | 关闭当前监测指令。 | N/A | N/A | 


## 使用指南

watch运行过程中可以执行**watch --over**结束本次watch命令。


## 使用实例

watch  -n 2 -c 6 task


## 输出说明

**示例** 每隔2秒运行一次task命令，一共运行6次

```
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
