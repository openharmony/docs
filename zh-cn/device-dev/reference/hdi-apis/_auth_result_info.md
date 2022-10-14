# AuthResultInfo


## **概述**

用户身份认证结果信息。

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
| [result](#result) | 用户身份认证结果。 | 
| [freezingTime](#freezingtime) | 认证方式被冻结的时间。 | 
| [remainTimes](#remaintimes) | 认证方式距离被冻结的可处理认证请求次数。 | 
| [msgs](#msgs) | 执行器发送的消息。 | 
| [token](#token) | 用户身份认证令牌。 | 
| [rootSecret](#rootsecret) | 保护文件加密密钥的密钥。 | 


## **类成员变量说明**


### freezingTime

  
```
int AuthResultInfo::freezingTime
```

**描述：**

认证方式被冻结的时间。


### msgs

  
```
struct ExecutorSendMsg [] AuthResultInfo::msgs
```

**描述：**

执行器发送的消息。


### remainTimes

  
```
int AuthResultInfo::remainTimes
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
