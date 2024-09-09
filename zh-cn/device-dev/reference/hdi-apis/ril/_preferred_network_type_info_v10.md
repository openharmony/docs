# PreferredNetworkTypeInfo


## 概述

首选网络类型信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [preferredNetworkType](#preferrednetworktype) | 网络类型 | 
| int [flag](#flag) | 网络标识  | 


## 类成员变量说明


### flag

```
int PreferredNetworkTypeInfo::flag
```
**描述**

网络标识


### preferredNetworkType

```
int PreferredNetworkTypeInfo::preferredNetworkType
```
**描述**

网络类型

- 0：自动。

- 1：GSM。

- 2：WCDMA。

- 3：LTE。

- 4：LTE、WCDMA。

- 5：LTE、WCDMA、GSM。

- 6：WCDMA、GSM。

- 7：CDMA。

- 8：EVDO。

- 9：EVDO、CDMA。

- 10：WCDMA、GSM、EVDO、CDMA。

- 11：LTE、EVDO、CDMA。

- 12：LTE、WCDMA、GSM、EVDO、CDMA。

- 13：TDSCDMA。

- 14：TDSCDMA、GSM。

- 15：TDSCDMA、WCDMA。

- 16：TDSCDMA、WCDMA、GSM。

- 17：LTE、TDSCDMA。

- 18：LTE、TDSCDMA、GSM。

- 19：LTE、TDSCDMA、WCDMA。

- 20：LTE、TDSCDMA、WCDMA、GSM。

- 21：TDSCDMA、WCDMA、GSM、EVDO、CDMA。

- 22：LTE、TDSCDMA、WCDMA、GSM、EVDO、CDMA。

- 31：NR。

- 32：NR、LTE。

- 33：NR、LTE、WCDMA。

- 34：NR、LTE、WCDMA、GSM。

- 35：NR、LTE、EVDO、CDMA。

- 36：NR、LTE、WCDMA、GSM、EVDO、CDMA。

- 37：NR、LTE、TDSCDMA。

- 38：NR、LTE、TDSCDMA、GSM。

- 39：NR、LTE、TDSCDMA、WCDMA。

- 40：NR、LTE、TDSCDMA、WCDMA、GSM。

- 41：NR、LTE、TDSCDMA、WCDMA、GSM、EVDO、CDMA 
