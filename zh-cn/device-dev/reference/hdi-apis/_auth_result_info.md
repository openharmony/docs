# AuthResultInfo


## 概述

用户身份认证结果信息。

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
| [result](#result) | unsigned&nbsp;int<br/>用户身份认证结果。&nbsp; | 
| [freezingTime](#freezingtime) | int<br/>认证方式被冻结的时间。&nbsp; | 
| [remainTimes](#remaintimes) | int<br/>认证方式距离被冻结的可处理认证请求次数。&nbsp; | 
| [msgs](#msgs) | struct&nbsp;[ExecutorSendMsg](_executor_send_msg.md)[]<br/>执行器发送的消息。&nbsp; | 
| [token](#token) | unsigned&nbsp;char[]<br/>用户身份认证令牌。&nbsp; | 
| [rootSecret](#rootsecret) | unsigned&nbsp;char[]<br/>保护文件加密密钥的密钥。&nbsp; | 


## 类成员变量说明


### freezingTime

  
```
int AuthResultInfo::freezingTime
```
**描述:**
认证方式被冻结的时间。


### msgs

  
```
struct ExecutorSendMsg [] AuthResultInfo::msgs
```
**描述:**
执行器发送的消息。


### remainTimes

  
```
int AuthResultInfo::remainTimes
```
**描述:**
认证方式距离被冻结的可处理认证请求次数。


### result

  
```
unsigned int AuthResultInfo::result
```
**描述:**
用户身份认证结果。


### rootSecret

  
```
unsigned char [] AuthResultInfo::rootSecret
```
**描述:**
保护文件加密密钥的密钥。


### token

  
```
unsigned char [] AuthResultInfo::token
```
**描述:**
用户身份认证令牌。
