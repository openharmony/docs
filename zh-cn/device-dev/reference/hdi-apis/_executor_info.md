# ExecutorInfo


## **概述**

执行器信息。

**Since：**

3.2

**Version：**

1.0

**所属模块:**

[HdfFaceAuth](_hdf_face_auth.md) | [HdfPinAuth](_hdf_pin_auth.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [sensorId](#sensorid) | 传感器ID，不同传感器在人脸/口令认证驱动内的唯一标识。 | 
| [executorType](#executortype) | 执行器类型，根据执行器支持的能力/算法类型进行分类。 | 
| [index](#index) | 用户认证框架的执行器索引。 | 
| [executorRole](#executorrole) | 执行器角色。 | 
| [authType](#authtype) | 用户认证凭据类型。 | 
| [esl](#esl) | 执行器安全等级。 | 
| [publicKey](#publickey) | 执行器公钥，用于校验该执行器私钥签名的信息。 | 
| [extraInfo](#extrainfo) | 其他相关信息，用于支持信息扩展。 | 
| [info](#info) | 执行器注册信息。 | 


## **类成员变量说明**


### authType

  
```
enum AuthType ExecutorInfo::authType
```

**描述：**

用户认证凭据类型。


### esl

  
```
enum ExecutorSecureLevel ExecutorInfo::esl
```

**描述：**

执行器安全等级[ExecutorSecureLevel](_hdf_face_auth.md#executorsecurelevel)。


### executorRole

  
```
enum ExecutorRole ExecutorInfo::executorRole
```

**描述：**

执行器角色[ExecutorRole](_hdf_face_auth.md#executorrole)。


### executorType

  
```
unsigned int ExecutorInfo::executorType
```

**描述：**

执行器类型，根据执行器支持的能力/算法类型进行分类。


### extraInfo

  
```
unsigned char [] ExecutorInfo::extraInfo
```

**描述：**

其他相关信息，用于支持信息扩展。


### index

  
```
unsigned long ExecutorInfo::index
```

**描述：**

用户认证框架的执行器索引。


### info

  
```
struct ExecutorRegisterInfo ExecutorInfo::info
```

**描述：**

执行器注册信息ExecutorRegisterInfo。


### publicKey

  
```
unsigned char [] ExecutorInfo::publicKey
```

**描述：**

执行器公钥，用于校验该执行器私钥签名的信息。


### sensorId

  
```
unsigned short ExecutorInfo::sensorId
```

**描述：**

传感器ID，不同传感器在人脸认证驱动、口令认证驱动内的唯一标识。
