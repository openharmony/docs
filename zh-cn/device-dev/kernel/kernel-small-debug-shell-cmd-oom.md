# oom


## 命令功能

查看和设置低内存阈值以及pagecache内存回收阈值。


## 命令格式

oom

oom -i [_interval_]

oom -m [_mem byte_]

oom -r [_mem byte_]

oom -h | --help


## 参数说明

**表1** 参数说明

| 参数                    | 参数说明                        | 取值范围                                                     |
| ----------------------- | ------------------------------- | ------------------------------------------------------------ |
| -i&nbsp;[interval]      | 设置oom线程任务检查的时间间隔。 | [100, 10000] 单位: ms                                    |
| -m&nbsp;[mem&nbsp;byte] | 设置低内存阈值。                | 0MB&nbsp;~&nbsp;1MB，0MB表示不做低内存阈值检查。             |
| -r&nbsp;[mem&nbsp;byte] | 设置pagecache内存回收阈值。     | 低内存阈值 ~ 系统可用最大内存，一个pagecache页一般为4KB，也有16 ~ 64KB的情况。 |
| -h&nbsp;\|&nbsp;--help  | 使用帮助。                      | N/A                                                          |


## 使用指南

  参数缺省时，显示oom功能当前配置信息。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 当系统内存不足时，会打印出内存不足的提示信息。


## 使用实例

举例：

- oom

- oom -i 100


## 输出说明

**示例1** oom缺省打印配置信息


```
OHOS:/$ oom
[oom] oom loop task status: enabled
      oom low memory threshold: 0x80000(byte)
      oom reclaim memory threshold: 0x500000(byte)
      oom check interval: 100(microsecond)
```

系统内存不足时打印提示信息


```
T:20 Enter:IT MEM 00M 001
[oom] OS is in low memory state
total physical memory: 0x1bcf000(byte), used: 0x1b50000(byte) ,free: 0x7f000(byte), low memory threshold: 0x80000(byte)
[oom] candidate victim process init pid: 1, actual phy mem byte:82602
[oom] candidate victim process shell pid: 3, actual phy mem byte:14950e
[oom] candidate victim process testsuits app pid: 4, actual phy mem byte:1334598
[oom] candidate victim process UserProcess12 pid: 12, actual phy mem byte:25951558
[oom] max phy mem used process UserProcess12 pid: 12, actual phy mem 25951558
################excFrom: User!####################
data abort fsr:0x817, far:0x225af000
Abort caused by a write instruction. Translation fault, page
excType: data abort
processName    = UserProcess12
processID      = 12
process aspace = 0х01000000 -> 0х3f000000
taskName       = threado
taskID         = 22
task user stack = 0х20e17000 -> 0х20e21000
pc   = 0x93969dc in /usr/bin/testsuits app ---> 0x19f9dc
ulr  = 0x93969cc in /usr/bin/testsuits app ---> 0x19f9cc
usp  = 0х20e20c68fp = 0x20e20c8c
R0   = 0х20e35000
R1   = 0x225af000
R2   = 0x0
R3   = 0х28e35000
R4   = 0х0
R5   = 0х9500000
R6   = 0х14
R7   = 0х97822c4
R8   = 0x970cfa8
R9   = 0x9090909
R10  = 0xa0a0a0a
R11  = 0x20e20c8c
R12  = 0х0
CPSR = 0х80000010
***backtrace beain***
traceback 0 -- lr = 0x9242e1c fp = 0х20e20cc4 lr in /usr/bin/testsuits apr 0x4be1c
traceback 1 -- 1r = 0х92430cc fp = 0x20e20cdc lr in /usr/bin/testsuits app --> 0x4c0cc
traceback 2 -- 1r = 0x9396ab0 fp = 0x20e20cec lr in /usr/bin/testsuits app -> 0х19fab0
traceback 3 -- lr = 0x9393eb4 fp = 0x20e20cf4 lr in /usr/bin/testsuits ap --> 0x19ceb4
traceback 4 -- lr = 0x92427d4 fp = 0x20e20d44 lr in /usr/bin/testsuits app --> 0x4b7d4
traceback 5 -- 1r = 0x20c4df50 fp = 0хb0b0b0b 1r in /1ib/libc.so - -> 0x62f50
```


**示例2** 设置 oom 线程任务检查的时间间隔



```
OHOS:/$ oom -i 100
[oom] set oom check interval (100)ms successful
```


**表2** 输出说明

| 输出                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [oom]&nbsp;OS&nbsp;is&nbsp;in&nbsp;low&nbsp;memory&nbsp;state<br/>total&nbsp;physical&nbsp;memory:&nbsp;0x1bcf000(byte),&nbsp;used:&nbsp;0x1b50000(byte),&nbsp;free:&nbsp;0x7f000(byte),&nbsp;low&nbsp;memory&nbsp;threshold:&nbsp;0x80000(byte) | 操作系统处于低内存状态。<br/>整个系统可用物理内存为0x1bcf000&nbsp;byte，已经使用了&nbsp;0x1b50000&nbsp;byte，&nbsp;还剩0x7f000&nbsp;byte，当前设置的低内存阈值为0x80000&nbsp;byte。 |
| [oom]&nbsp;candidate&nbsp;victim&nbsp;process&nbsp;init&nbsp;pid:&nbsp;1,&nbsp;actual&nbsp;phy&nbsp;mem&nbsp;byte:&nbsp;82602 | 打印当前各个进程的内存使用情况，init进程实际占用物理内存82602byte。 |
| [oom]&nbsp;candidate&nbsp;victim&nbsp;process&nbsp;UserProcess12&nbsp;pid:&nbsp;12,&nbsp;actual&nbsp;phy&nbsp;mem&nbsp;byte:&nbsp;25951558 | UserProcess12进程实际使用25951558byte内存。                  |
| [oom]&nbsp;max&nbsp;phy&nbsp;mem&nbsp;used&nbsp;process&nbsp;UserProcess12&nbsp;pid:&nbsp;12,&nbsp;actual&nbsp;phy&nbsp;mem:&nbsp;25951558 | 当前使用内存最多的进程是UserProcess12。                      |
| excFrom:&nbsp;User!                                          | 当系统处于低内存的情况下，UserProcess12进程再去申请内存时失败退出。 |