# Asset_Result


## 概述

关键资产查询结果，用于定义一条关键资产。

**起始版本：** 11

**相关模块：**[AssetType](_asset_type.md)

**所在头文件：**[asset_type.h](asset__type_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [count](#count) | 关键资产属性的个数。  | 
| [Asset_Attr](_asset___attr.md) \* [attrs](#attrs) | 指向关键资产属性数组的指针。  | 


## 结构体成员变量说明


### attrs

```
Asset_Attr* Asset_Result::attrs
```
**描述**
指向关键资产属性数组的指针。


### count

```
uint32_t Asset_Result::count
```
**描述**
关键资产属性的个数。
