# ExecutorRegisterInfo


## 概述

执行器注册信息。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[HdfUserAuth](_hdf_user_auth.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [authType](#authtype) | enum&nbsp;[AuthType](_hdf_user_auth.md#authtype)<br/>用户认证凭据类型。 | 
| [executorRole](#executorrole) | enum&nbsp;[ExecutorRole](_hdf_user_auth.md#executorrole)<br/>执行器角色。 | 
| [executorSensorHint](#executorsensorhint) | unsigned&nbsp;int<br/>既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。 | 
| [executorMatcher](#executormatcher) | unsigned&nbsp;int<br/>执行器匹配器，根据执行器支持的认证能力进行分类。 | 
| [esl](#esl) | enum&nbsp;[ExecutorSecureLevel](_hdf_user_auth.md#executorsecurelevel)<br/>执行器安全等级。 | 
| [publicKey](#publickey) | unsigned&nbsp;char[]<br/>执行器公钥，用于校验该执行器私钥签名的信息。 | 


## 类成员变量说明


### authType

  
```
enum AuthType ExecutorRegisterInfo::authType
```

**描述:**

用户认证凭据类型[AuthType](_hdf_user_auth.md#authtype)。


### esl

  
```
enum ExecutorSecureLevel ExecutorRegisterInfo::esl
```

**描述:**

执行器安全等级[ExecutorSecureLevel](_hdf_user_auth.md#executorsecurelevel)。


### executorMatcher

  
```
unsigned int ExecutorRegisterInfo::executorMatcher
```

**描述:**

执行器匹配器，根据执行器支持的认证能力进行分类。


### executorRole

  
```
enum ExecutorRole ExecutorRegisterInfo::executorRole
```

**描述:**

执行器角色[ExecutorRole](_hdf_user_auth.md#executorrole)。


### executorSensorHint

  
```
unsigned int ExecutorRegisterInfo::executorSensorHint
```

**描述:**

既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。


### publicKey

  
```
unsigned char [] ExecutorRegisterInfo::publicKey
```

**描述:**

执行器公钥，用于校验该执行器私钥签名的信息。
