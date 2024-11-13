# TemplateInfo


## 概述

凭据模板信息。

**弃用:**   从4.0版本开始废弃，使用**Property**接口替代。

**起始版本：** 3.2

**相关模块：**[HdfFingerprintAuth](_hdf_fingerprint_auth_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [executorType](#executortype) | 执行器类型，根据执行器支持的能力进行分类。 | 
| int [lockoutDuration](#lockoutduration) | 认证方式被冻结的时间。 | 
| int [remainAttempts](#remainattempts) | 认证方式距离被冻结的可处理认证请求次数。 | 
| unsigned char[] [extraInfo](#extrainfo) | 其他相关信息，用于支持信息扩展。 | 


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


### lockoutDuration

```
int TemplateInfo::lockoutDuration
```

**描述**


认证方式被冻结的时间。


### remainAttempts

```
int TemplateInfo::remainAttempts
```

**描述**


认证方式距离被冻结的可处理认证请求次数。
