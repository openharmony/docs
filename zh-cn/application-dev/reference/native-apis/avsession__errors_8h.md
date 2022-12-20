# avsession_errors.h


## 概述

定义了avsession错误码。

**Since:**
9
**Version:**
1.0
**相关模块:**

[Avsession](avsession.md)


## 汇总


### 变量

  | 名称 | 描述 | 
| -------- | -------- |
| [OHOS::AVSession::AVSESSION_ERROR](#avsessionerror)&nbsp;=&nbsp;-1 | constexpr&nbsp;int32_t<br/>存在错误&nbsp; | 
| [OHOS::AVSession::AVSESSION_SUCCESS](#avsessionsuccess)&nbsp;=&nbsp;0 | constexpr&nbsp;int32_t<br/>操作成功&nbsp; | 
| [OHOS::AVSession::AVSESSION_ERROR_BASE](#avsessionerrorbase)&nbsp;=&nbsp;1000 | constexpr&nbsp;int32_t<br/>avsession错误码的基定义&nbsp; | 
| [OHOS::AVSession::ERR_NO_MEMORY](#errnomemory)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;1) | constexpr&nbsp;int32_t<br/>无可用内存&nbsp; | 
| [OHOS::AVSession::ERR_INVALID_PARAM](#errinvalidparam)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;2) | constexpr&nbsp;int32_t<br/>传递的参数无效&nbsp; | 
| [OHOS::AVSession::ERR_SERVICE_NOT_EXIST](#errservicenotexist)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;3) | constexpr&nbsp;int32_t<br/>服务不存在&nbsp; | 
| [OHOS::AVSession::ERR_SESSION_LISTENER_EXIST](#errsessionlistenerexist)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;4) | constexpr&nbsp;int32_t<br/>Session监听器已存在&nbsp; | 
| [OHOS::AVSession::ERR_MARSHALLING](#errmarshalling)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;5) | constexpr&nbsp;int32_t<br/>数据序列化操作错误&nbsp; | 
| [OHOS::AVSession::ERR_UNMARSHALLING](#errunmarshalling)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;6) | constexpr&nbsp;int32_t<br/>数据反序列化操作错误&nbsp; | 
| [OHOS::AVSession::ERR_IPC_SEND_REQUEST](#erripcsendrequest)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;7) | constexpr&nbsp;int32_t<br/>IPC发送数据失败&nbsp; | 
| [OHOS::AVSession::ERR_SESSION_EXCEED_MAX](#errsessionexceedmax)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;8) | constexpr&nbsp;int32_t<br/>超过允许会话最大数量&nbsp; | 
| [OHOS::AVSession::ERR_SESSION_NOT_EXIST](#errsessionnotexist)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;9) | constexpr&nbsp;int32_t<br/>会话不存在&nbsp; | 
| [OHOS::AVSession::ERR_COMMAND_NOT_SUPPORT](#errcommandnotsupport)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;10) | constexpr&nbsp;int32_t<br/>会话命令不支持&nbsp; | 
| [OHOS::AVSession::ERR_CONTROLLER_NOT_EXIST](#errcontrollernotexist)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;11) | constexpr&nbsp;int32_t<br/>控制器不存在&nbsp; | 
| [OHOS::AVSession::ERR_NO_PERMISSION](#errnopermission)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;12) | constexpr&nbsp;int32_t<br/>无权限&nbsp; | 
| [OHOS::AVSession::ERR_SESSION_DEACTIVE](#errsessiondeactive)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;13) | constexpr&nbsp;int32_t<br/>会话未激活&nbsp; | 
| [OHOS::AVSession::ERR_CONTROLLER_IS_EXIST](#errcontrollerisexist)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;14) | constexpr&nbsp;int32_t<br/>控制器存在&nbsp; | 
| [OHOS::AVSession::ERR_START_ABILITY_IS_RUNNING](#errstartabilityisrunning)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;15) | constexpr&nbsp;int32_t<br/>元能力正在运行&nbsp; | 
| [OHOS::AVSession::ERR_ABILITY_NOT_AVAILABLE](#errabilitynotavailable)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;16) | constexpr&nbsp;int32_t<br/>元能力启动超失败&nbsp; | 
| [OHOS::AVSession::ERR_START_ABILITY_TIMEOUT](#errstartabilitytimeout)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;17) | constexpr&nbsp;int32_t<br/>元能力启动超时&nbsp; | 
| [OHOS::AVSession::ERR_COMMAND_SEND_EXCEED_MAX](#errcommandsendexceedmax)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;18) | constexpr&nbsp;int32_t<br/>指令发送次数超过最大值&nbsp; | 
| [OHOS::AVSession::ERR_RPC_SEND_REQUEST](#errrpcsendrequest)&nbsp;=&nbsp;-(AVSESSION_ERROR_BASE&nbsp;+&nbsp;19) | constexpr&nbsp;int32_t<br/>RPC发送数据失败&nbsp; | 


## 变量说明


### AVSESSION_ERROR

  
```
constexpr int32_t OHOS::AVSession::AVSESSION_ERROR = -1
```
**描述:**
存在错误


### AVSESSION_ERROR_BASE

  
```
constexpr int32_t OHOS::AVSession::AVSESSION_ERROR_BASE = 1000
```
**描述:**
avsession错误码的基定义


### AVSESSION_SUCCESS

  
```
constexpr int32_t OHOS::AVSession::AVSESSION_SUCCESS = 0
```
**描述:**
操作成功


### ERR_ABILITY_NOT_AVAILABLE

  
```
constexpr int32_t OHOS::AVSession::ERR_ABILITY_NOT_AVAILABLE = -(AVSESSION_ERROR_BASE + 16)
```
**描述:**
元能力启动超失败


### ERR_COMMAND_NOT_SUPPORT

  
```
constexpr int32_t OHOS::AVSession::ERR_COMMAND_NOT_SUPPORT = -(AVSESSION_ERROR_BASE + 10)
```
**描述:**
会话命令不支持


### ERR_COMMAND_SEND_EXCEED_MAX

  
```
constexpr int32_t OHOS::AVSession::ERR_COMMAND_SEND_EXCEED_MAX = -(AVSESSION_ERROR_BASE + 18)
```
**描述:**
指令发送次数超过最大值


### ERR_CONTROLLER_IS_EXIST

  
```
constexpr int32_t OHOS::AVSession::ERR_CONTROLLER_IS_EXIST = -(AVSESSION_ERROR_BASE + 14)
```
**描述:**
控制器存在


### ERR_CONTROLLER_NOT_EXIST

  
```
constexpr int32_t OHOS::AVSession::ERR_CONTROLLER_NOT_EXIST = -(AVSESSION_ERROR_BASE + 11)
```
**描述:**
控制器不存在


### ERR_INVALID_PARAM

  
```
constexpr int32_t OHOS::AVSession::ERR_INVALID_PARAM = -(AVSESSION_ERROR_BASE + 2)
```
**描述:**
传递的参数无效


### ERR_IPC_SEND_REQUEST

  
```
constexpr int32_t OHOS::AVSession::ERR_IPC_SEND_REQUEST = -(AVSESSION_ERROR_BASE + 7)
```
**描述:**
IPC发送数据失败


### ERR_MARSHALLING

  
```
constexpr int32_t OHOS::AVSession::ERR_MARSHALLING = -(AVSESSION_ERROR_BASE + 5)
```
**描述:**
数据序列化操作错误


### ERR_NO_MEMORY

  
```
constexpr int32_t OHOS::AVSession::ERR_NO_MEMORY = -(AVSESSION_ERROR_BASE + 1)
```
**描述:**
无可用内存


### ERR_NO_PERMISSION

  
```
constexpr int32_t OHOS::AVSession::ERR_NO_PERMISSION = -(AVSESSION_ERROR_BASE + 12)
```
**描述:**
无权限


### ERR_RPC_SEND_REQUEST

  
```
constexpr int32_t OHOS::AVSession::ERR_RPC_SEND_REQUEST = -(AVSESSION_ERROR_BASE + 19)
```
**描述:**
RPC发送数据失败


### ERR_SERVICE_NOT_EXIST

  
```
constexpr int32_t OHOS::AVSession::ERR_SERVICE_NOT_EXIST = -(AVSESSION_ERROR_BASE + 3)
```
**描述:**
服务不存在


### ERR_SESSION_DEACTIVE

  
```
constexpr int32_t OHOS::AVSession::ERR_SESSION_DEACTIVE = -(AVSESSION_ERROR_BASE + 13)
```
**描述:**
会话未激活


### ERR_SESSION_EXCEED_MAX

  
```
constexpr int32_t OHOS::AVSession::ERR_SESSION_EXCEED_MAX = -(AVSESSION_ERROR_BASE + 8)
```
**描述:**
超过允许会话最大数量


### ERR_SESSION_LISTENER_EXIST

  
```
constexpr int32_t OHOS::AVSession::ERR_SESSION_LISTENER_EXIST = -(AVSESSION_ERROR_BASE + 4)
```
**描述:**
Session监听器已存在


### ERR_SESSION_NOT_EXIST

  
```
constexpr int32_t OHOS::AVSession::ERR_SESSION_NOT_EXIST = -(AVSESSION_ERROR_BASE + 9)
```
**描述:**
会话不存在


### ERR_START_ABILITY_IS_RUNNING

  
```
constexpr int32_t OHOS::AVSession::ERR_START_ABILITY_IS_RUNNING = -(AVSESSION_ERROR_BASE + 15)
```
**描述:**
元能力正在运行


### ERR_START_ABILITY_TIMEOUT

  
```
constexpr int32_t OHOS::AVSession::ERR_START_ABILITY_TIMEOUT = -(AVSESSION_ERROR_BASE + 17)
```
**描述:**
元能力启动超时


### ERR_UNMARSHALLING

  
```
constexpr int32_t OHOS::AVSession::ERR_UNMARSHALLING = -(AVSESSION_ERROR_BASE + 6)
```
**描述:**
数据反序列化操作错误
