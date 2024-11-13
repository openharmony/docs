# GnssCachingConfig


## 概述

定义GNSS缓存功能的配置参数。

**起始版本：** 3.2

**相关模块：**[HdiGnss](_hdi_gnss.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [interval](#interval) | 缓存位置之间的时间间隔  | 
| boolean [fifoFullNotify](#fifofullnotify) | 如果为true，在FIFO满后唤醒AP并报告缓存的位置  | 


## 类成员变量说明


### fifoFullNotify

```
boolean GnssCachingConfig::fifoFullNotify
```
**描述**

如果为true，在FIFO满后唤醒AP并报告缓存的位置


### interval

```
unsigned int GnssCachingConfig::interval
```
**描述**

缓存位置之间的时间间隔
