# ServiceCellParas


## 概述

多种网络模式的小区信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| struct [CellListRatGsm](_cell_list_rat_gsm_v11.md)[gsm](#gsm) | GSM小区信息，具体查看[CellListRatGsm](_cell_list_rat_gsm_v11.md) | 
| struct [CellListRatLte](_cell_list_rat_lte_v11.md)[lte](#lte) | LTE小区信息，具体查看[CellListRatLte](_cell_list_rat_lte_v11.md) | 
| struct [CellListRatWcdma](_cell_list_rat_wcdma_v11.md)[wcdma](#wcdma) | WCDMA小区信息，具体查看[CellListRatWcdma](_cell_list_rat_wcdma_v11.md) | 
| struct [CellListRatCdma](_cell_list_rat_cdma_v11.md)[cdma](#cdma) | CDMA小区信息，具体查看[CellListRatCdma](_cell_list_rat_cdma_v11.md) | 
| struct [CellListRatTdscdma](_cell_list_rat_tdscdma_v11.md)[tdscdma](#tdscdma) | TDSCDMA小区信息，具体查看[CellListRatTdscdma](_cell_list_rat_tdscdma_v11.md) | 
| struct [CellListRatNr](_cell_list_rat_nr_v11.md)[nr](#nr) | NR小区信息，具体查看[CellListRatNr](_cell_list_rat_nr_v11.md) | 


## 类成员变量说明


### cdma

```
struct CellListRatCdma ServiceCellParas::cdma
```
**描述**

CDMA小区信息，具体查看[CellListRatCdma](_cell_list_rat_cdma_v11.md)


### gsm

```
struct CellListRatGsm ServiceCellParas::gsm
```
**描述**

GSM小区信息，具体查看[CellListRatGsm](_cell_list_rat_gsm_v11.md)


### lte

```
struct CellListRatLte ServiceCellParas::lte
```
**描述**

LTE小区信息，具体查看[CellListRatLte](_cell_list_rat_lte_v11.md)


### nr

```
struct CellListRatNr ServiceCellParas::nr
```
**描述**

NR小区信息，具体查看[CellListRatNr](_cell_list_rat_nr_v11.md)


### tdscdma

```
struct CellListRatTdscdma ServiceCellParas::tdscdma
```
**描述**

TDSCDMA小区信息，具体查看[CellListRatTdscdma](_cell_list_rat_tdscdma_v11.md)


### wcdma

```
struct CellListRatWcdma ServiceCellParas::wcdma
```
**描述**

WCDMA小区信息，具体查看[CellListRatWcdma](_cell_list_rat_wcdma_v11.md)
