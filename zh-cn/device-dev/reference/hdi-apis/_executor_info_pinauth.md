# ExecutorInfo


## 概述

执行器信息。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[HdfPinAuth](_hdf_pin_auth.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [sensorId](#sensorid) | unsigned&nbsp;short<br/>传感器ID，不同传感器在口令认证驱动内的唯一标识。 | 
| [executorType](#executortype) | unsigned&nbsp;int<br/>执行器类型，根据执行器支持的算法类型进行分类。 | 
| [executorRole](#executorrole) | enum&nbsp;[ExecutorRole](_hdf_pin_auth.md#executorrole)<br/>执行器角色。 | 
| [authType](#authtype) | enum&nbsp;[AuthType](_hdf_pin_auth.md#authtype)<br/>用户认证凭据类型。 | 
| [esl](#esl) | enum&nbsp;[ExecutorSecureLevel](_hdf_pin_auth.md#executorsecurelevel)<br/>执行器安全等级。 | 
| [publicKey](#publickey) | unsigned&nbsp;char[]<br/>执行器公钥，用于校验该执行器私钥签名的信息。 | 
| [extraInfo](#extrainfo) | unsigned&nbsp;char[]<br/>其他相关信息，用户支持信息扩展。 | 


## 类成员变量说明


### authType

  
```
enum AuthType ExecutorInfo::authType
```

**描述:**

用户认证凭据类型[AuthType](_hdf_pin_auth.md#authtype)。


### esl

  
```
enum ExecutorSecureLevel ExecutorInfo::esl
```

**描述:**

执行器安全等级[ExecutorSecureLevel](_hdf_pin_auth.md#executorsecurelevel)。


### executorRole

  
```
enum ExecutorRole ExecutorInfo::executorRole
```

**描述:**

执行器角色[ExecutorRole](_hdf_pin_auth.md#executorrole)。


### executorType

  
```
unsigned int ExecutorInfo::executorType
```

**描述:**

执行器类型，根据执行器支持的算法类型进行分类。


### extraInfo

  
```
unsigned char [] ExecutorInfo::extraInfo
```

**描述:**

其他相关信息，用户支持信息扩展。


### publicKey

  
```
unsigned char [] ExecutorInfo::publicKey
```

**描述:**

执行器公钥，用于校验该执行器私钥签名的信息。


### sensorId

  
```
unsigned short ExecutorInfo::sensorId
```

**描述:**

传感器ID，不同传感器在口令认证驱动内的唯一标识。
