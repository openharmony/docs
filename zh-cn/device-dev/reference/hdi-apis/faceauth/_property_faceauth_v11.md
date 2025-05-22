# Property


## 概述

执行器相关属性。

**起始版本：** 4.0

**相关模块：**[HdfFaceAuth](_hdf_face_auth_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long [authSubType](#authsubtype) | 人脸认证子类型。  | 
| int [lockoutDuration](#lockoutduration) | 认证方式被冻结的时间。  | 
| int [remainAttempts](#remainattempts) | 认证方式距离被冻结的可处理认证请求次数。  | 
| String [enrollmentProgress](#enrollmentprogress) | 人脸录入进程。  | 
| String [sensorInfo](#sensorinfo) | 传感器信息。  | 


## 类成员变量说明


### authSubType

```
unsigned long Property::authSubType
```
**描述**

人脸认证子类型。


### enrollmentProgress

```
String Property::enrollmentProgress
```
**描述**

人脸录入进程。


### lockoutDuration

```
int Property::lockoutDuration
```
**描述**

认证方式被冻结的时间。


### remainAttempts

```
int Property::remainAttempts
```
**描述**

认证方式距离被冻结的可处理认证请求次数。


### sensorInfo

```
String Property::sensorInfo
```
**描述**

传感器信息。
