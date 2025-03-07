# Rssi


## 概述

接收信号强度信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| struct [GsmRssi](_gsm_rssi_v11.md)[gw](#gw) | GSM信号强度信息，具体查看[GsmRssi](_gsm_rssi_v11.md) | 
| struct [CdmaRssi](_cdma_rssi_v11.md)[cdma](#cdma) | CDMA信号强度信息，具体查看[CdmaRssi](_cdma_rssi_v11.md) | 
| struct [WcdmaRssi](_wcdma_rssi_v11.md)[wcdma](#wcdma) | WCDMA信号强度信息，具体查看[WcdmaRssi](_wcdma_rssi_v11.md) | 
| struct [LteRssi](_lte_rssi_v11.md)[lte](#lte) | LTE信号强度信息，具体查看[LteRssi](_lte_rssi_v11.md) | 
| struct [TdScdmaRssi](_td_scdma_rssi_v11.md)[tdScdma](#tdscdma) | TDSCDMA信号强度信息，具体查看[TdScdmaRssi](_td_scdma_rssi_v11.md) | 
| struct [NrRssi](_nr_rssi_v11.md)[nr](#nr) | NR信号强度信息，具体查看[NrRssi](_nr_rssi_v11.md) | 


## 类成员变量说明


### cdma

```
struct CdmaRssi Rssi::cdma
```
**描述**

CDMA信号强度信息，具体查看[CdmaRssi](_cdma_rssi_v11.md)


### gw

```
struct GsmRssi Rssi::gw
```
**描述**

GSM信号强度信息，具体查看[GsmRssi](_gsm_rssi_v11.md)


### lte

```
struct LteRssi Rssi::lte
```
**描述**

LTE信号强度信息，具体查看[LteRssi](_lte_rssi_v11.md)


### nr

```
struct NrRssi Rssi::nr
```
**描述**

NR信号强度信息，具体查看[NrRssi](_nr_rssi_v11.md)


### tdScdma

```
struct TdScdmaRssi Rssi::tdScdma
```
**描述**

TDSCDMA信号强度信息，具体查看[TdScdmaRssi](_td_scdma_rssi_v11.md)


### wcdma

```
struct WcdmaRssi Rssi::wcdma
```
**描述**

WCDMA信号强度信息，具体查看[WcdmaRssi](_wcdma_rssi_v11.md)
