# ExecutorInfo


## 概述

执行器信息。

**起始版本：** 3.2

**相关模块：**[HdfPinAuth](_hdf_pin_auth_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned short [sensorId](#sensorid) | 传感器ID，不同传感器在口令认证驱动内的唯一标识。 | 
| unsigned int [executorMatcher](#executormatcher) | 执行器类型。 | 
| int [executorRole](#executorrole) | 执行器角色。 | 
| int [authType](#authtype) | 用户认证类型。 | 
| int [esl](#esl) | 执行器安全等级。 | 
| unsigned char[] [publicKey](#publickey) | 执行器公钥，用于校验该执行器私钥签名的信息。 | 
| unsigned char[] [extraInfo](#extrainfo) | 其他相关信息，用于支持信息扩展。 | 
| unsigned int [maxTemplateAcl](#maxtemplateacl) | 模板的最大算法等级。 | 


## 类成员变量说明


### authType

```
int ExecutorInfo::authType
```

**描述**

用户认证类型[AuthType](_hdf_pin_auth_v20.md#authtype)。


### esl

```
int ExecutorInfo::esl
```

**描述**

执行器安全等级[ExecutorSecureLevel](_hdf_pin_auth_v20.md#executorsecurelevel)。


### executorMatcher

```
unsigned int ExecutorInfo::executorMatcher
```

**描述**

执行器类型。


### executorRole

```
int ExecutorInfo::executorRole
```

**描述**

执行器角色[ExecutorRole](_hdf_pin_auth_v20.md#executorrole)。


### extraInfo

```
unsigned char [] ExecutorInfo::extraInfo
```

**描述**

其他相关信息，用于支持信息扩展。


### maxTemplateAcl

```
unsigned int ExecutorInfo::maxTemplateAcl
```

**描述**

模板的最大算法等级。


### publicKey

```
unsigned char [] ExecutorInfo::publicKey
```

**描述**

执行器公钥，用于校验该执行器私钥签名的信息。


### sensorId

```
unsigned short ExecutorInfo::sensorId
```

**描述**

传感器ID，不同传感器在口令认证驱动内的唯一标识。
