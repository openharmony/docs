# AuthResultInfo


## 概述

用户身份认证结果信息。

**起始版本：** 3.2

**相关模块：**[HdfUserAuth](_hdf_user_auth_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [result](#result) | 用户身份认证结果。 | 
| int [lockoutDuration](#lockoutduration) | 认证方式被冻结的时间。 | 
| int [remainAttempts](#remainattempts) | 认证方式距离被冻结的可处理认证请求次数。 | 
| struct [ExecutorSendMsg](_executor_send_msg_v10.md)[] [msgs](#msgs) | 执行器发送的消息[ExecutorSendMsg](_executor_send_msg_v10.md)。 | 
| unsigned char[] [token](#token) | 用户身份认证令牌。 | 
| unsigned char[] [rootSecret](#rootsecret) | 保护文件加密密钥的密钥。 | 


## 类成员变量说明


### lockoutDuration

```
int AuthResultInfo::lockoutDuration
```

**描述**


认证方式被冻结的时间。


### msgs

```
struct ExecutorSendMsg [] AuthResultInfo::msgs
```

**描述**


执行器发送的消息[ExecutorSendMsg](_executor_send_msg_v10.md)。


### remainAttempts

```
int AuthResultInfo::remainAttempts
```

**描述**


认证方式距离被冻结的可处理认证请求次数。


### result

```
int AuthResultInfo::result
```

**描述**


用户身份认证结果。


### rootSecret

```
unsigned char [] AuthResultInfo::rootSecret
```

**描述**


保护文件加密密钥的密钥。


### token

```
unsigned char [] AuthResultInfo::token
```

**描述**


用户身份认证令牌。
