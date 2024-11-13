# RunningLockInfo


## 概述

定义运行锁的信息。

**起始版本：** 4.0

**相关模块：**[Power](power_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [name](#name) | 运行锁的名称。不能为空  | 
| enum [RunningLockType](power_v11.md#runninglocktype)[type](#type) | 运行锁类型，默认值为RUNNINGLOCK_BACKGROUND_TASK  | 
| int [timeoutMs](#timeoutms) | 运行锁的超时时间，单位毫秒。值小于 0 表示没有超时。默认为3000  | 
| int [pid](#pid) | 进程ID  | 
| int [uid](#uid) | 用户ID  | 


## 类成员变量说明


### name

```
String RunningLockInfo::name
```
**描述**

运行锁的名称。不能为空


### pid

```
int RunningLockInfo::pid
```
**描述**

进程ID


### timeoutMs

```
int RunningLockInfo::timeoutMs
```
**描述**

运行锁的超时时间，单位毫秒。值小于 0 表示没有超时。默认为3000


### type

```
enum RunningLockType RunningLockInfo::type
```
**描述**

运行锁类型，默认值为RUNNINGLOCK_BACKGROUND_TASK


### uid

```
int RunningLockInfo::uid
```
**描述**

用户ID
