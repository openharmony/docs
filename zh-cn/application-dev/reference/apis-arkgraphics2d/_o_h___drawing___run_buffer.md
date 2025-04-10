# OH_Drawing_RunBuffer


## 概述

结构体用于描述一块内存，描述文字和位置信息。

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)

**所在头文件：**[drawing_text_blob.h](drawing__text__blob_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| uint16_t \* [glyphs](#glyphs) | 存储文字索引。  |
| float \* [pos](#pos) | 存储文字的位置。  |
| char \* [utf8text](#utf8text) | 存储文字UTF-8编码。  |
| uint32_t \* [clusters](#clusters) | 存储文字簇UTF-8编码（簇指的是集合）。  |


## 结构体成员变量说明


### clusters

```
uint32_t* OH_Drawing_RunBuffer::clusters
```
**描述**

存储文字簇UTF-8编码（簇指的是集合）。


### glyphs

```
uint16_t* OH_Drawing_RunBuffer::glyphs
```
**描述**

存储文字索引。


### pos

```
float* OH_Drawing_RunBuffer::pos
```
**描述**

存储文字的位置。


### utf8text

```
char* OH_Drawing_RunBuffer::utf8text
```
**描述**

存储文字UTF-8编码。
