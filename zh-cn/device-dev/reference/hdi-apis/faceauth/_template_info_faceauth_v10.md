# TemplateInfo


## 概述

凭据模版信息。

**起始版本：** 3.2

**相关模块：**[HdfFaceAuth](_hdf_face_auth_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [executorType](#executortype) | 执行器类型，根据执行器支持的能力进行分类。  | 
| int [freezingTime](#freezingtime) | 认证方式被冻结的时间。  | 
| int [remainTimes](#remaintimes) | 认证方式距离被冻结的可处理认证请求次数。  | 
| unsigned char[] [extraInfo](#extrainfo) | 其他相关信息，用于支持信息扩展。  | 


## 类成员变量说明


### executorType

```
unsigned int TemplateInfo::executorType
```
**描述**

执行器类型，根据执行器支持的能力进行分类。


### extraInfo

```
unsigned char [] TemplateInfo::extraInfo
```
**描述**

其他相关信息，用于支持信息扩展。


### freezingTime

```
int TemplateInfo::freezingTime
```
**描述**

认证方式被冻结的时间。


### remainTimes

```
int TemplateInfo::remainTimes
```
**描述**

认证方式距离被冻结的可处理认证请求次数。
