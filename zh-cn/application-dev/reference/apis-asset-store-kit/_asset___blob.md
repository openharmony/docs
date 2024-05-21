# Asset_Blob


## 概述

二进制数组类型，即不定长的字节数组。

**起始版本：** 11

**相关模块：**[AssetType](_asset_type.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [size](#size) | 表示字节数组的大小。  | 
| uint8_t \* [data](#data) | 指向字节数组的指针。  | 


## 结构体成员变量说明


### data

```
uint8_t* Asset_Blob::data
```
**描述**
指向字节数组的指针。


### size

```
uint32_t Asset_Blob::size
```
**描述**
表示字节数组的大小。
