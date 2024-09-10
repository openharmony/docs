# TemplateInfo


## 概述

凭据模版信息，口令模版在用户注册口令认证凭据时生成并存储，用于支持通过口令认证方式验证用户身份。

**弃用:**

从4.0版本开始废弃，使用**GetPropertyType**接口代替。

**起始版本：** 3.2

**相关模块：**[HdfPinAuth](_hdf_pin_auth_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [executorType](#executortype) | 执行器类型，根据执行器支持的算法类型进行分类。  | 
| int [lockoutDuration](#lockoutduration) | 认证执行器的剩余冻结时间。  | 
| int [remainAttempts](#remainattempts) | 认证执行器的剩余可重试次数。  | 
| unsigned char[] [extraInfo](#extrainfo) | 其他相关信息，用于支持信息扩展。  | 


## 类成员变量说明


### executorType

```
unsigned int TemplateInfo::executorType
```
**描述**

执行器类型，根据执行器支持的算法类型进行分类。


### extraInfo

```
unsigned char [] TemplateInfo::extraInfo
```
**描述**

其他相关信息，用于支持信息扩展。


### lockoutDuration

```
int TemplateInfo::lockoutDuration
```
**描述**

认证执行器的剩余冻结时间。


### remainAttempts

```
int TemplateInfo::remainAttempts
```
**描述**

认证执行器的剩余可重试次数。
