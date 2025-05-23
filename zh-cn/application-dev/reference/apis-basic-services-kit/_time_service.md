# TimeService


## 概述

描述TimeService向应用提供时间时区能力。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [time_service.h](time__service_8h.md) | 声明获取时间时区信息的API。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [TimeService_ErrCode](#timeservice_errcode) [TimeService_ErrCode](#timeservice_errcode) | 枚举错误码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [TimeService_ErrCode](#timeservice_errcode) {<br/>TIMESERVICE_ERR_OK = 0,<br/>TIMESERVICE_ERR_INTERNAL_ERROR = 13000001,<br/>TIMESERVICE_ERR_INVALID_PARAMETER = 13000002<br/>} | 枚举错误码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [TimeService_ErrCode](#timeservice_errcode) [OH_TimeService_GetTimeZone](#oh_timeservice_gettimezone) (char \*timeZone, uint32_t len) | 获取当前系统时区信息。 | 


## 类型定义说明


### TimeService_ErrCode

```
typedef enum TimeService_ErrCode TimeService_ErrCode
```

**描述**

枚举错误码。

**起始版本：** 12


## 枚举类型说明


### TimeService_ErrCode

```
enum TimeService_ErrCode
```

**描述**

枚举错误码。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| TIMESERVICE_ERR_OK | 成功。 | 
| TIMESERVICE_ERR_INTERNAL_ERROR | 获取系统参数失败。 | 
| TIMESERVICE_ERR_INVALID_PARAMETER | 无效的参数。 | 


## 函数说明


### OH_TimeService_GetTimeZone()

```
TimeService_ErrCode OH_TimeService_GetTimeZone (char * timeZone, uint32_t len)
```

**描述**

获取系统当前时区。

**系统能力：** SystemCapability.MiscServices.Time

**起始版本：** 12

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| timeZone | 时区ID字符数组，成功时写入当前系统时区ID字符串，失败时写入空字符串。字符串以'\0'结尾。 | 
| len | 时区ID字符数组分配的内存大小，当前时区字符串没有最大长度规格，必须申请至少31字节的内存。 | 

**返回：**

返回TIMESERVICE_ERR_OK表示成功；

返回TIMESERVICE_ERR_INTERNAL_ERROR表示获取系统参数失败；

返回TIMESERVICE_ERR_INVALID_PARAMETER表示timeZone为NULL指针或时区名称（不包括结束字符（'\0'））的大小大于或等于len。
