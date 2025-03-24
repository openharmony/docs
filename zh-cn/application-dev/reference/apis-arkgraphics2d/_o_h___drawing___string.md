# OH_Drawing_String


## 概述

采用UTF-16编码的字符串信息结构体。

**起始版本：** 14

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint8_t \* [strData](#strdata) | 指向包含UTF-16编码的字节数组的指针。  | 
| uint32_t [strLen](#strlen) | strData指向的字符串的实际长度，单位为字节。  | 


## 结构体成员变量说明


### strData

```
uint8_t* OH_Drawing_String::strData
```
**描述**

指向包含UTF-16编码的字节数组的指针。


### strLen

```
uint32_t OH_Drawing_String::strLen
```
**描述**

strData指向的字符串的实际长度，单位为字节。
