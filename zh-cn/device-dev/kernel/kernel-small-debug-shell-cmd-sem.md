# sem


## 命令功能

sem命令用于查询系统内核信号量相关信息。


## 命令格式

sem [_ID__ / fulldata_]


## 参数说明

**表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| ID | 信号量ID。 | [0,&nbsp;1023]或[0x0,&nbsp;0x3FF] | 
| fulldata | 查询所有在用的信号量信息，打印信息包括如下：SemID,&nbsp;Count,&nbsp;Original&nbsp;Count,&nbsp;Creator&nbsp;TaskEntry,&nbsp;Last&nbsp;Access&nbsp;Time。 | N/A | 


## 使用指南

- 参数缺省时，显示所有的信号量的使用数及信号量总数。

- sem后加ID，显示对应ID信号量的使用数。

- 参数fulldata依赖于LOSCFG_DEBUG_SEMAPHORE，使用时通过menuconfig在配置项中开启"Enable Semaphore Debugging"：
  Debug  ---&gt; Enable a Debug Version ---&gt; Enable Debug LiteOS Kernel Resource ---&gt; Enable Semaphore Debugging


## 使用实例

- 输入sem

- 配置LOSCFG_DEBUG_SEMAPHORE标志，输入 sem fulldata


## 输出说明

**示例1** 查询所有在用的信号量信息

```
OHOS # sem
   SemID       Count
   ----------  -----
   0x00000000  1
   SemID       Count
   ----------  -----
   0x00000001  0
   SemID       Count
   ----------  -----
   0x00000002  0
   SemID       Count
   ----------  -----
   0x00000003  1
   SemID       Count
   ----------  -----
   0x00000004  0
   SemID       Count
   ----------  -----
   0x00000005  1
   SemID       Count
   ----------  -----
   0x00000006  0
```

**表2** 输出说明

| 输出 | 说明 | 
| -------- | -------- |
| SemID | 信号量ID。 | 
| Count | 信号量使用数。 | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> ● sem命令的ID参数输入形式以十进制形式表示或十六进制形式表示皆可。
> 
> ● sem命令的ID参数在[0, 1023]范围内时，返回对应ID的信号量的状态（如果对应ID的信号量未被使用则进行提示）；其他取值时返回参数错误的提示。

**示例2** 查询所有在用的信号量信息

```
OHOS # sem fulldata
Used Semaphore List:
   SemID    Count    OriginalCount   Creator(TaskEntry)    LastAccessTime
   ------   ------   -------------   ------------------    --------------
   0xb      0x0      0x0             0x404978fc            0xa1
   0xc      0x0      0x0             0x404978fc            0xa1
   0xd      0x0      0x0             0x404978fc            0x12c
   0x10     0x0      0x0             0x404978fc            0x195
   0xf      0x0      0x0             0x404978fc            0x195
   0x11     0x0      0x0             0x4041a998            0x1d5
   0x15     0x0      0x0             0x404978fc            0x273
   0x14     0x0      0x0             0x404978fc            0x273
   0x18     0x0      0x0             0x404978fc            0x352
   0x17     0x0      0x0             0x404978fc            0x352
   0x16     0x0      0x0             0x404978fc            0x352
   0x1d     0x1      0x1             0x404978fc            0x385
   0x1e     0x1      0x1             0x404978fc            0x388
   0x1f     0x1      0x1             0x404978fc            0x38d
   0x20     0x1      0x1             0x404978fc            0x38f
   0x21     0x1      0x1             0x404978fc            0x392
   0x3d     0x1      0x1             0x404978fc            0x395
   0x3b     0x1      0x1             0x404978fc            0x395
   0x3c     0x1      0x1             0x404978fc            0x395
   0x39     0x1      0x1             0x404978fc            0x395
   0x3a     0x1      0x1             0x404978fc            0x395
   0x33     0x1      0x1             0x404978fc            0x395
   0x35     0x1      0x1             0x404978fc            0x395
   0x34     0x1      0x1             0x404978fc            0x395
   0x38     0x1      0x1             0x404978fc            0x395
```

**表3** 输出说明

| 输出 | 说明 | 
| -------- | -------- |
| SemID | 信号量ID。 | 
| Count | 信号量使用数。 | 
| OriginalCount | 信号量原始计数。 | 
| Creator | 信号量的创建线程的入口函数地址。 | 
| LastAccessTime | 上次访问时间。 | 
