# swtmr


## 命令功能

swtmr命令用于查询系统软件定时器相关信息。


## 命令格式

swtmr [_ID_]


## 参数说明

**表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| ID | 软件定时器ID号。 | [0, 0xFFFFFFFF] | 


## 使用指南

- 参数缺省时，默认显示所有软件定时器的相关信息。

- swtmr后加ID号时，显示ID对应的软件定时器相关信息。


## 使用实例

举例：

- swtmr

- swtmr 1


## 输出说明

**示例1** 查询所有软件定时器相关信息

```
OHOS # swtmr
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000000  Ticking  Period   100      77      0x40802a50  0x4037b8a0
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000001  Ticking  Period   1000     876     0x00000000  0x4037fc04
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000002  Ticking  Period   100      76      0x00000000  0x403727f4
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000016  Ticking  NSD      10       6       0x8021e000  0x401fe7d8
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000079  Ticking  NSD      30000    1749    0x406189d8  0x40160e1c
```

**示例2** 查询对应 ID 的软件定时器信息

```
OHOS # swtmr 1
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000001  Ticking  Period   1000     841     0x00000000  0x4037fc04
```

  **表2** 输出说明

| 输出 | 说明 | 
| -------- | -------- |
| SwTmrID | 软件定时器ID。 | 
| State | 软件定时器状态。<br/>状态可能为："UnUsed",&nbsp;"Created",&nbsp;"Ticking"。 | 
| Mode | 软件定时器模式。<br/>模式可能为："Once",&nbsp;"Period",&nbsp;"NSD（单次定时器，定时结束后不会自动删除）"。 | 
| Interval | 软件定时器使用的Tick数。 | 
| Count | 软件定时器已经工作的次数。 | 
| Arg | 传入的参数。 | 
| handlerAddr | 回调函数的地址。 | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - swtmr命令的ID参数输入形式以十进制形式表示或十六进制形式表示皆可。
> 
> - swtmr命令的ID参数在[0, 当前软件定时器个数 - 1]范围内时，返回对应ID的软件定时器的状态；其他取值时返回错误提示。
