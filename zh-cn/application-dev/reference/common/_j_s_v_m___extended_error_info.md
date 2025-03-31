# JSVM_ExtendedErrorInfo


## 概述

扩展的异常信息。

**起始版本：** 11

**相关模块：** [JSVM](_j_s_v_m.md)

**所在头文件：** [jsvm_types.h](jsvm__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [errorMessage](#errormessage) | UTF8编码的字符串，包含异常信息描述。  | 
| void \* [engineReserved](#enginereserved) | 特定于VM的详细异常信息。目前尚未为任何VM实现此功能。  | 
| uint32_t [engineErrorCode](#engineerrorcode) | 特定于VM的异常代码。目前尚未为任何VM实现此功能。  | 
| [JSVM_Status](_j_s_v_m.md#jsvm_status) [errorCode](#errorcode) | 源自最后一个异常的JSVM-API状态代码。  | 


## 结构体成员变量说明


### engineErrorCode

```
uint32_t JSVM_ExtendedErrorInfo::engineErrorCode
```
**描述**
特定于VM的异常代码。目前尚未为任何VM实现此功能。


### engineReserved

```
void* JSVM_ExtendedErrorInfo::engineReserved
```
**描述**
特定于VM的详细异常信息。目前尚未为任何VM实现此功能。


### errorCode

```
JSVM_Status JSVM_ExtendedErrorInfo::errorCode
```
**描述**
源自最后一个异常的JSVM-API状态代码。


### errorMessage

```
const char* JSVM_ExtendedErrorInfo::errorMessage
```
**描述**
UTF8编码的字符串，包含异常信息描述。
