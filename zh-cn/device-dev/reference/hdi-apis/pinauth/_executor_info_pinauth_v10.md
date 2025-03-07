# ExecutorInfo


## 概述

执行器信息。

**起始版本：** 3.2

**相关模块：**[HdfPinAuth](_hdf_pin_auth_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned short [sensorId](#sensorid) | 传感器ID，不同传感器在口令认证驱动内的唯一标识。  | 
| unsigned int [executorType](#executortype) | 执行器类型，根据执行器支持的算法类型进行分类。  | 
| enum [ExecutorRole](_hdf_pin_auth_v10.md#executorrole)[executorRole](#executorrole) | 执行器角色ExecutorRole。  | 
| enum [AuthType](_hdf_pin_auth_v10.md#authtype)[authType](#authtype) | 用户认证凭据类型AuthType。  | 
| enum [ExecutorSecureLevel](_hdf_pin_auth_v10.md#executorsecurelevel)[esl](#esl) | 执行器安全等级ExecutorSecureLevel。  | 
| unsigned char[] [publicKey](#publickey) | 执行器公钥，用于校验该执行器私钥签名的信息。  | 
| unsigned char[] [extraInfo](#extrainfo) | 其他相关信息，用于支持信息扩展。  | 


## 类成员变量说明


### authType

```
enum AuthType ExecutorInfo::authType
```
**描述**

用户认证凭据类型AuthType。


### esl

```
enum ExecutorSecureLevel ExecutorInfo::esl
```
**描述**

执行器安全等级ExecutorSecureLevel。


### executorRole

```
enum ExecutorRole ExecutorInfo::executorRole
```
**描述**

执行器角色ExecutorRole。


### executorType

```
unsigned int ExecutorInfo::executorType
```
**描述**

执行器类型，根据执行器支持的算法类型进行分类。


### extraInfo

```
unsigned char [] ExecutorInfo::extraInfo
```
**描述**

其他相关信息，用于支持信息扩展。


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
