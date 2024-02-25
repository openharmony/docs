# OH_Drawing_Font_Metrics


## 概述

定义字体度量信息的结构体。

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| float [top](#top) | 字符最高点到基线的最大距离  |
| float [ascent](#ascent) | 字符最高点到基线的推荐距离  |
| float [descent](#descent) | 字符最低点到基线的推荐距离  |
| float [bottom](#bottom) | 字符最低点到基线的最大距离  |
| float [leading](#leading) | 行间距  |


## 结构体成员变量说明


### ascent

```
float OH_Drawing_Font_Metrics::ascent
```
**描述**
字符最高点到基线的推荐距离


### bottom

```
float OH_Drawing_Font_Metrics::bottom
```
**描述**
字符最低点到基线的最大距离


### descent

```
float OH_Drawing_Font_Metrics::descent
```
**描述**
字符最低点到基线的推荐距离


### leading

```
float OH_Drawing_Font_Metrics::leading
```
**描述**
行间距


### top

```
float OH_Drawing_Font_Metrics::top
```
**描述**
字符最高点到基线的最大距离
