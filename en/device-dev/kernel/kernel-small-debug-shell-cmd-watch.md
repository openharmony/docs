# watch


## Command Function

This command is used to periodically run the specified command and display its execution result.


## Syntax

- watch

- watch [_-c/-n/-t/--count/--interval/-no-title/--over_] [_command_]


## Parameters

  **Table 1** Parameter description

| Parameter| Description| Default Value| Value Range|
| -------- | -------- | -------- | -------- |
| -c&nbsp;/&nbsp;--count | Specifies the number of times that the specified command is executed.| 0xFFFFFF | (0, 0xFFFFFF]|
| -n&nbsp;/&nbsp;--interval | Specifies the interval for running the command, in seconds.| 1s | (0, 0xFFFFFF]|
| -t&nbsp;/&nbsp;-no-title | Disables time display on the top.| N/A | N/A |
| command | Specifies the command to be monitored.| N/A | N/A |
| --over | Stops the current command monitoring.| N/A | N/A |


## Usage Guidelines

You can run the **watch --over** command to stop monitoring of the specified command.


## Example

Run **watch  -n 2 -c 6 task**.


## Output

Example: The **task** command is executed six times at an interval of 2 seconds.

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
