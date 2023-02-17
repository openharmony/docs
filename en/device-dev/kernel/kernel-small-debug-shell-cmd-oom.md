# oom


## Command Function

This command is used to query and set the low memory threshold and the PageCache reclaim threshold.


## Syntax

oom

oom -i [_interval_]

oom -m [_mem byte_]

oom -r [_mem byte_]

oom -h | --help


## Parameters

**Table 1** Parameter description

| Parameter                   | Description                       | Value Range                                                    |
| ----------------------- | ------------------------------- | ------------------------------------------------------------ |
| -i [interval]      | Sets the interval (in ms) for checking the Out Of Memory (OOM) thread task.| [100, 10000]                                   |
| -m [mem byte] | Sets the low memory threshold (in MB).               | 0 to 1<br>The value **0** means not to perform the low memory threshold check. |
| -r [mem byte] | Sets the PageCache reclaim threshold.    | Low memory threshold to the maximum available memory of the system<br>Generally, the size of a PageCache is 4 KB. Sometimes, it is 16 KB to 64 KB. |
| -h \| --help  | Displays help information.                     | N/A                                                          |


## Usage Guidelines

  If no parameter is specified, this command displays the current OOM configuration.

> **NOTE**<br>
> If the system memory is insufficient, the system displays a message indicating the insufficiency.


## Example

Run the following commands:

- oom
- oom -i 100


## Output

Example 1: The OOM configuration is displayed by default.


```
OHOS:/$ oom
[oom] oom loop task status: enabled
      oom low memory threshold: 0x80000(byte)
      oom reclaim memory threshold: 0x500000(byte)
      oom check interval: 100(microsecond)
```

Information displayed when the system memory is insufficient:


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


Example 2: The OOM check interval is set to 100 ms.



```
OHOS:/$ oom -i 100
[oom] set oom check interval (100)ms successful
```


**Table 2** Output description

| Parameter                                                    | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [oom] OS is in low memory state<br>total physical memory: 0x1bcf000(byte), used: 0x1b50000(byte), free: 0x7f000(byte), low memory threshold: 0x80000(byte) | The OS has low memory.<br>The total physical memory is **0x1bcf000** bytes, **0x1b50000** bytes are used, and **0x7f000** bytes are left.<br/>The current lower memory threshold is **0x80000** bytes. |
| [oom] candidate victim process init pid: 1, actual phy mem byte: 82602 | The memory occupied by the **init** process is 82602 bytes.  |
| [oom] candidate victim process UserProcess12 pid: 12, actual phy mem byte: 25951558 | The memory used by the **UserProcess12** process is **25951558** bytes. |
| [oom] max phy mem used process UserProcess12 pid: 12, actual phy mem: 25951558 | The process that uses the most memory currently is **UserProcess12**. |
| excFrom: User!                                               | The system memory is low, and the **UserProcess12** process fails to apply for memory and exits. |
