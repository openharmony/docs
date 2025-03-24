# Print_PrintAttributes


## 概述

打印属性结构体。

**起始版本：** 13

**相关模块：**[OH_Print](_o_h___print.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [Print_Range](_print___range.md)[pageRange](#pagerange) | 打印范围。  | 
| [Print_PageSize](_print___page_size.md)[pageSize](#pagesize) | 打印尺寸。  | 
| [Print_Margin](_print___margin.md)[pageMargin](#pagemargin) | 打印边距。  | 
| uint32_t [copyNumber](#copynumber) | 打印份数。  | 
| uint32_t [duplexMode](#duplexmode) | 单双面。  | 
| uint32_t [colorMode](#colormode) | 彩色。  | 
| bool [isSequential](#issequential) | 顺序打印。  | 
| bool [isLandscape](#islandscape) | 横纵向。  | 
| bool [hasOption](#hasoption) | 打印选项标识位。  | 
| char [options](#options) [256] | 打印选项。  | 


## 结构体成员变量说明


### colorMode

```
uint32_t Print_PrintAttributes::colorMode
```
**描述**
彩色。


### copyNumber

```
uint32_t Print_PrintAttributes::copyNumber
```
**描述**
打印份数。


### duplexMode

```
uint32_t Print_PrintAttributes::duplexMode
```
**描述**
单双面。


### hasOption

```
bool Print_PrintAttributes::hasOption
```
**描述**
打印选项标识位。


### isLandscape

```
bool Print_PrintAttributes::isLandscape
```
**描述**
横纵向。


### isSequential

```
bool Print_PrintAttributes::isSequential
```
**描述**
顺序打印。


### options

```
char Print_PrintAttributes::options[256]
```
**描述**
打印选项。


### pageMargin

```
Print_Margin Print_PrintAttributes::pageMargin
```
**描述**
打印边距。


### pageRange

```
Print_Range Print_PrintAttributes::pageRange
```
**描述**
打印范围。


### pageSize

```
Print_PageSize Print_PrintAttributes::pageSize
```
**描述**
打印尺寸。
