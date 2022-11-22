# ExecutorRegisterInfo


## **概述**

执行器注册信息。

**Since：**

3.2

**Version：**

1.0

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [authType](#authtype) | 用户认证凭据类型。 | 
| [executorRole](#executorrole) | 执行器角色。 | 
| [executorSensorHint](#executorsensorhint) | 既定用户认证凭据类型的执行器ID。 | 
| [executorMatcher](#executormatcher) | 执行器类型，根据执行器支持的认证能力进行分类。 | 
| [esl](#esl) | 执行器安全等级。 | 
| [publicKey](#publickey) | 执行器公钥，用于校验该执行器私钥签名的信息。 | 


## **类成员变量说明**


### authType

  
```
enum AuthType ExecutorRegisterInfo::authType
```

**描述：**

用户认证凭据类型。


### esl

  
```
enum ExecutorSecureLevel ExecutorRegisterInfo::esl
```

**描述：**

执行器安全等级[ExecutorSecureLevel](_hdf_user_auth.md#executorsecurelevel)。


### executorSensorHint

  
```
unsigned int ExecutorRegisterInfo::executorSensorHint
```

**描述：**

既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。


### executorRole

  
```
enum ExecutorRole ExecutorRegisterInfo::executorRole
```

**描述：**

执行器角色[ExecutorRole](_hdf_user_auth.md#executorrole)。


### executorMatcher

  
```
unsigned int ExecutorRegisterInfo::executorMatcher
```

**描述：**

执行器匹配器，根据执行器支持的认证能力进行分类。


### publicKey

  
```
unsigned char [] ExecutorRegisterInfo::publicKey
```

**描述：**

执行器公钥，用于校验该执行器私钥签名的信息。
