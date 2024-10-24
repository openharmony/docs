# ExecutorSendMsg


## 概述

执行器发送的消息。

**起始版本：** 3.2

**相关模块：**[HdfUserAuth](_hdf_user_auth_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long [executorIndex](#executorindex) | 用户认证框架的执行器索引。  | 
| int [commandId](#commandid) | 消息命令ID。  | 
| unsigned char[] [msg](#msg) | 执行器发送的消息。  | 


## 类成员变量说明


### commandId

```
int ExecutorSendMsg::commandId
```
**描述**

消息命令ID。


### executorIndex

```
unsigned long ExecutorSendMsg::executorIndex
```
**描述**

用户认证框架的执行器索引。


### msg

```
unsigned char [] ExecutorSendMsg::msg
```
**描述**

执行器发送的消息。
