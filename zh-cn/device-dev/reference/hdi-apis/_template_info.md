# TemplateInfo


## **概述**

**所属模块:**

[HdfFaceAuth](_hdf_face_auth.md) | [HdfPinAuth](_hdf_pin_auth.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [executorType](#executortype) | 执行器类型，根据执行器支持的算法类型进行分类。 | 
| [lockoutDuration](#lockoutduration) | 认证方式被冻结的时间。 |
| [remainAttempts](#remainattempts) | 认证方式距离被冻结的可处理认证请求次数。 |
| [extraInfo](#extrainfo) | 其他相关信息，用于支持信息扩展。 | 


## **详细描述**

凭据模版信息。

**Since：**

3.2

**Version：**

1.0


## **类成员变量说明**


### executorType

  
```
unsigned int TemplateInfo::executorType
```

**描述：**

执行器类型，根据执行器支持的算法类型进行分类。


### extraInfo

  
```
unsigned char [] TemplateInfo::extraInfo
```

**描述：**

其他相关信息，用于支持信息扩展。


### lockoutDuration

  
```
int TemplateInfo::lockoutDuration
```

**描述：**

认证方式被冻结的时间。


### remainAttempts

  
```
int TemplateInfo::remainAttempts
```

**描述：**

认证方式距离被冻结的可处理认证请求次数。
