# CurrentServiceCellParas


## 概述

当前蜂窝数据信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| struct [CellRatGsm](_cell_rat_gsm_v11.md)[gsm](#gsm) | Gsm蜂窝信息  | 
| struct [CellRatLte](_cell_rat_lte_v11.md)[lte](#lte) | LTE蜂窝信息  | 
| struct [CellRatWcdma](_cell_rat_wcdma_v11.md)[wcdma](#wcdma) | WCDMA蜂窝信息  | 
| struct [CellRatCdma](_cell_rat_cdma_v11.md)[cdma](#cdma) | CDMA蜂窝信息  | 
| struct [CellRatTdscdma](_cell_rat_tdscdma_v11.md)[tdscdma](#tdscdma) | TDSCDMA蜂窝信息  | 
| struct [CellRatNr](_cell_rat_nr_v11.md)[nr](#nr) | NR蜂窝信息  | 


## 类成员变量说明


### cdma

```
struct CellRatCdma CurrentServiceCellParas::cdma
```
**描述**

CDMA蜂窝信息


### gsm

```
struct CellRatGsm CurrentServiceCellParas::gsm
```
**描述**

Gsm蜂窝信息


### lte

```
struct CellRatLte CurrentServiceCellParas::lte
```
**描述**

LTE蜂窝信息


### nr

```
struct CellRatNr CurrentServiceCellParas::nr
```
**描述**

NR蜂窝信息


### tdscdma

```
struct CellRatTdscdma CurrentServiceCellParas::tdscdma
```
**描述**

TDSCDMA蜂窝信息


### wcdma

```
struct CellRatWcdma CurrentServiceCellParas::wcdma
```
**描述**

WCDMA蜂窝信息
