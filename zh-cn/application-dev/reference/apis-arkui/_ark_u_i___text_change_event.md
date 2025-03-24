# ArkUI_TextChangeEvent


## 概述

定义输入框内容改变（包含预上屏内容）回调事件的返回值类型。

**起始版本：** 15

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [pStr](#pstr) | 字符串数据。  | 
| const char \* [pExtendStr](#pextendstr) | 字符串数据。  | 
| const char \* [number](#number) | 整型数据。  | 


## 结构体成员变量说明


### pStr

```
const char* ArkUI_TextChangeEvent::pStr
```
**描述：**

字符串数据，输入框文本内容。

### pExtendStr

```
const char* ArkUI_TextChangeEvent::pExtendStr
```
**描述：**

字符串数据，预上屏内容。

### number

```
const char* ArkUI_TextChangeEvent::number
```
**描述：**

整型数据，预上屏内容插入位置。
