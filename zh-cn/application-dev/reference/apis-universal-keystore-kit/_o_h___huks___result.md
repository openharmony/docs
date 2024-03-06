# OH_Huks_Result


## 概述

表示状态返回数据，包括返回码和消息。

**起始版本：** 9

**相关模块：**[HuksTypeApi](_huks_type_api.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [errorCode](#errorcode) | 状态返回码。  | 
| const char \* [errorMsg](#errormsg) | 对状态返回码的说明信息。  | 
| uint8_t \* [data](#data) | 其他返回数据。  | 


## 结构体成员变量说明


### data

```
uint8_t* OH_Huks_Result::data
```
**描述**
其他返回数据。


### errorCode

```
int32_t OH_Huks_Result::errorCode
```
**描述**
状态返回码。


### errorMsg

```
const char* OH_Huks_Result::errorMsg
```
**描述**
对状态返回码的说明信息。
