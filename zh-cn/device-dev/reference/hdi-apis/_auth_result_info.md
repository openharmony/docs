# AuthResultInfo


## **概述**

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [result](#result) | 用户身份认证结果。 | 
| [lockoutDuration](#lockoutduration) | 认证方式被冻结的时间。 |
| [remainAttempts](#remainattempts) | 认证方式距离被冻结的可处理认证请求次数。 |
| [msgs](#msgs) | 执行器发送的消息。 | 
| [token](#token) | 用户身份认证令牌。 | 
| rootSecret | 保护文件加密密钥的密钥。 | 


## **详细描述**

用户身份认证结果信息。

**Since：**

3.2

**Version：**

1.0


## **类成员变量说明**


### lockoutDuration

  
```
int AuthResultInfo::lockoutDuration
```

**描述：**

认证方式被冻结的时间。


### msgs

  
```
struct ExecutorSendMsg [] AuthResultInfo::msgs
```

**描述：**

执行器发送的消息。


### remainAttempts

  
```
int AuthResultInfo::remainAttempts
```

**描述：**

认证方式距离被冻结的可处理认证请求次数。


### result

  
```
unsigned int AuthResultInfo::result
```

**描述：**

用户身份认证结果。


### token

  
```
unsigned char [] AuthResultInfo::token
```

**描述：**

用户身份认证令牌。


### rootSecret

  
```
unsigned char [] AuthResultInfo::rootSecret
```

**描述：**

保护文件加密密钥的密钥。
