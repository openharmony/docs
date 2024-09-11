# ExecutorRegisterInfo


## 概述

执行器注册信息。

**起始版本：** 3.2

**相关模块：**[HdfUserAuth](_hdf_user_auth_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [AuthType](_hdf_user_auth_v10.md#authtype)[authType](#authtype) | 用户认证凭据类型[AuthType](_hdf_user_auth_v10.md#authtype)。 | 
| enum [ExecutorRole](_hdf_user_auth_v10.md#executorrole)[executorRole](#executorrole) | 执行器角色[ExecutorRole](_hdf_user_auth_v10.md#executorrole)。 | 
| unsigned int [executorSensorHint](#executorsensorhint) | 既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。 | 
| unsigned int [executorMatcher](#executormatcher) | 执行器匹配器，根据执行器支持的认证能力进行分类。 | 
| enum [ExecutorSecureLevel](_hdf_user_auth_v10.md#executorsecurelevel)[esl](#esl) | 执行器安全等级[ExecutorSecureLevel](_hdf_user_auth_v10.md#executorsecurelevel)。 | 
| unsigned char[] [publicKey](#publickey) | 执行器公钥，用于校验该执行器私钥签名的信息。 | 


## 类成员变量说明


### authType

```
enum AuthType ExecutorRegisterInfo::authType
```

**描述**


用户认证凭据类型[AuthType](_hdf_user_auth_v10.md#authtype)。


### esl

```
enum ExecutorSecureLevel ExecutorRegisterInfo::esl
```

**描述**


执行器安全等级[ExecutorSecureLevel](_hdf_user_auth_v10.md#executorsecurelevel)。


### executorMatcher

```
unsigned int ExecutorRegisterInfo::executorMatcher
```

**描述**


执行器匹配器，根据执行器支持的认证能力进行分类。


### executorRole

```
enum ExecutorRole ExecutorRegisterInfo::executorRole
```

**描述**


执行器角色[ExecutorRole](_hdf_user_auth_v10.md#executorrole)。


### executorSensorHint

```
unsigned int ExecutorRegisterInfo::executorSensorHint
```

**描述**


既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。


### publicKey

```
unsigned char [] ExecutorRegisterInfo::publicKey
```

**描述**


执行器公钥，用于校验该执行器私钥签名的信息。
