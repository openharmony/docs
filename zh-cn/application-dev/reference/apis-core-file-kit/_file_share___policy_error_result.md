# FileShare_PolicyErrorResult


## 概述

授予或使能权限失败的URI策略结果。

**起始版本：** 12

**相关模块：**[FileShare](file_share.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| char \* [uri](#uri) | 授予或使能策略失败的URI。  | 
| [FileShare_PolicyErrorCode](file_share.md#fileshare_policyerrorcode) [code](#code) | 授予或使能策略失败的URI对应的错误码。  | 
| char \* [message](#message) | 授予或使能策略失败的URI对应的原因。  | 


## 结构体成员变量说明


### code

```
FileShare_PolicyErrorCode FileShare_PolicyErrorResult::code
```
**描述**
授予或使能策略失败的URI对应的错误码。


### message

```
char* FileShare_PolicyErrorResult::message
```
**描述**
授予或使能策略失败的URI对应的原因。


### uri

```
char* FileShare_PolicyErrorResult::uri
```
**描述**
授予或使能策略失败的URI。
