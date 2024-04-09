# Asset_ResultSet


## 概述

关键资产查询结果集合，用于定义多条关键资产。

**起始版本：** 11

**相关模块：**[AssetType](_asset_type.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [count](#count) | 关键资产的条数。  | 
| [Asset_Result](_asset___result.md) \* [results](#results) | 指向关键资产数组的指针。  | 


## 结构体成员变量说明


### count

```
uint32_t Asset_ResultSet::count
```
**描述**
关键资产的条数。


### results

```
Asset_Result* Asset_ResultSet::results
```
**描述**
指向关键资产数组的指针。
