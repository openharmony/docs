# cpup


## 命令功能

cpup命令用于查询系统CPU的占用率。


## 命令格式

cpup [_mode_] [_taskID_]


## 参数说明

**表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| mode | -&nbsp;缺省：显示系统最近10s内的CPU占用率。<br/>-&nbsp;0：显示系统最近10s内的CPU占用率。<br/>-&nbsp;1：显示系统最近1s内的CPU占用率。<br/>-&nbsp;其他数字：显示系统启动至今总的CPU&nbsp;占用率。 | [0, 0xFFFFFFFF] | 
| taskID | 任务ID号 | [0, 0xFFFFFFFF] | 


## 使用指南

- 参数缺省时，显示系统10s前的CPU占用率。

- 只有一个参数时，该参数为mode，显示系统相应时间前的CPU占用率。

- 输入两个参数时，第一个参数为mode，第二个参数为taskID，显示对应ID号任务的相应时间前的CPU占用率。


## 使用实例

举例：输入cpup 1 5


## 输出说明

**示例** 指令输出结果

```
OHOS # cpup 1 5pid 5 

CpuUsage in 1s: 0.0
```
