# systeminfo


## 命令功能

systeminfo命令用于显示当前操作系统内资源使用情况，包括任务、信号量、互斥量、队列、定时器等。


## 命令格式

systeminfo


## 参数说明

无


## 使用指南

无


## 使用实例

举例：输入systeminfo


## 输出说明

**示例** 查看系统资源使用情况

```
OHOS:/$ systeminfo
   Module    Used      Total     Enabled
--------------------------------------------
   Task      96        256       YES
   Sem       435       1024      YES
   Queue     13        1024      YES
   SwTmr     20        1024      YES
```

**表1** 输出说明

| 输出    | 说明           |
| ------- | -------------- |
| Module  | 模块名称。     |
| Used    | 当前使用量。   |
| Total   | 最大可用量。   |
| Enabled | 模块是否开启。 |
| Task    | 任务。         |
| Sem     | 信号量。       |
| Queue   | 队列。         |
| SwTmr   | 定时器。       |