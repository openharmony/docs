# Property


## 概述

执行器属性。

**起始版本：** 4.0

**相关模块：**[HdfFingerprintAuth](_hdf_fingerprint_auth_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long [authSubType](#authsubtype) | 认证子类型。  | 
| int [lockoutDuration](#lockoutduration) | 指纹剩余锁定时间。  | 
| int [remainAttempts](#remainattempts) | 指纹剩余可重试次数。  | 
| String [enrollmentProgress](#enrollmentprogress) | 指纹录入进度。  | 
| String [sensorInfo](#sensorinfo) | 指纹光斑信息。  | 


## 类成员变量说明


### authSubType

```
unsigned long Property::authSubType
```
**描述**

认证子类型。


### enrollmentProgress

```
String Property::enrollmentProgress
```
**描述**

指纹录入进度。


### lockoutDuration

```
int Property::lockoutDuration
```
**描述**

指纹剩余锁定时间。


### remainAttempts

```
int Property::remainAttempts
```
**描述**

指纹剩余可重试次数。


### sensorInfo

```
String Property::sensorInfo
```
**描述**

指纹光斑信息。
