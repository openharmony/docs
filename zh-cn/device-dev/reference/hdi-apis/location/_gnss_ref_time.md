# GnssRefTime


## 概述

定义GNSS参考时间结构体。

**起始版本：** 3.2

**相关模块：**[HdiGnss](_hdi_gnss.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long [timeMs](#timems) | UTC时间  | 
| long [timeReferenceMs](#timereferencems) | 自系统启动后经过的时间  | 
| int [uncertainty](#uncertainty) | 时间不确定度  | 


## 类成员变量说明


### timeMs

```
long GnssRefTime::timeMs
```
**描述**

UTC时间


### timeReferenceMs

```
long GnssRefTime::timeReferenceMs
```
**描述**

自系统启动后经过的时间


### uncertainty

```
int GnssRefTime::uncertainty
```
**描述**

时间不确定度
