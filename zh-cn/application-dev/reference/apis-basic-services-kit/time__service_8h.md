# time_service.h


## 概述

声明获取时间时区信息的API。

**库：** libtime_service_ndk.so

**系统能力：** SystemCapability.MiscServices.Time

**起始版本：** 12

**相关模块：**[TimeService](_time_service.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
|[TimeService_ErrCode](_time_service.md#timeservice_errcode)| 枚举错误码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [TimeService_ErrCode](_time_service.md#timeservice_errcode) {<br/>TIMESERVICE_ERR_OK = 0,<br/>TIMESERVICE_ERR_INTERNAL_ERROR = 13000001,<br/>TIMESERVICE_ERR_INVALID_PARAMETER = 13000002<br/>} | 枚举错误码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [TimeService_ErrCode](_time_service.md#timeservice_errcode) [OH_TimeService_GetTimeZone](_time_service.md#oh_timeservice_gettimezone) (char \*timeZone, uint32_t len) | 获取当前系统时区。 | 
