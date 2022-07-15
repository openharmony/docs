# ExecutorRegisterInfo


## **概述**

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [authType](#authtype) | 用户认证凭据类型。 | 
| [executorRole](#executorrole) | 执行器角色ExecutorRole。 | 
| [executorId](#executorid) | 既定用户认证凭据类型的执行器ID。 | 
| [executorType](#executortype) | 执行器类型，根据执行器支持的认证能力进行分类。 | 
| [esl](#esl) | 执行器安全等级ExecutorSecureLevel。 | 
| [publicKey](#publickey) | 执行器公钥，用于校验该执行器私钥签名的信息。 | 


## **详细描述**

执行器注册信息。

**Since：**

3.2

**Version：**

1.0


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

执行器安全等级ExecutorSecureLevel。


### executorId

  
```
unsigned int ExecutorRegisterInfo::executorId
```

**描述：**

既定用户认证凭据类型的执行器ID。


### executorRole

  
```
enum ExecutorRole ExecutorRegisterInfo::executorRole
```

**描述：**

执行器角色ExecutorRole。


### executorType

  
```
unsigned int ExecutorRegisterInfo::executorType
```

**描述：**

执行器类型，根据执行器支持的认证能力进行分类。


### publicKey

  
```
unsigned char [] ExecutorRegisterInfo::publicKey
```

**描述：**

执行器公钥，用于校验该执行器私钥签名的信息。
