# SrvccStatus


## 概述

SRVCC（Single Radio Voice Call Continuity）状态信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [status](#status) | SRVCC（Single Radio Voice Call Continuity）状态 | 


## 类成员变量说明


### status

```
int SrvccStatus::status
```
**描述**

SRVCC（Single Radio Voice Call Continuity）状态

- 0：开始

- 1：成功

- 2：失败

- 3：取消 
