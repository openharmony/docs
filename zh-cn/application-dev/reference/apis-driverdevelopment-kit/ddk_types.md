# ddk_types.h


## 概述

提供BASE DDK中的枚举变量、结构体定义。

**起始版本：**

12

**相关模块:**

[BASE DDK](_base_ddk.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [DDK_Ashmem](_ddk_ashmem.md) | 共享内存。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DDK_RetCode](#ddk_retcode) &nbsp;{<br/>DDK_SUCCESS&nbsp;=&nbsp;0,<br/>DDK_FAILED&nbsp;=&nbsp;28600001,<br/>DDK_INVALID_PARAMETER&nbsp;=&nbsp;28600002,<br/>DDK_INVALID_OPERATION&nbsp;=&nbsp;28600003,<br/>DDK_NULL_PTR&nbsp;=&nbsp;28600004<br/>} | BASE DDK 错误码定义。  | 


## 枚举类型说明


### DDK_RetCode 


```
enum DDK_RetCode 
```

**描述:**

BASE DDK 错误码定义。

| 枚举值 | 描述 |
| -------- | -------- |
| DDK_SUCCESS | 操作成功。 |
| DDK_FAILED | 操作失败。 |
| DDK_INVALID_PARAMETER | 非法参数。 |
| DDK_INVALID_OPERATION | 非法操作。 |
| DDK_NULL_PTR | 空指针异常。 |