# CardStatusInfo


## 概述

SIM卡状态信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [index](#index) | SIM卡索引。  | 
| int [simType](#simtype) | SIM卡类型。 | 
| int [simState](#simstate) | SIM卡状态。 | 


## 类成员变量说明


### index

```
int CardStatusInfo::index
```
**描述**

SIM卡索引。


### simState

```
int CardStatusInfo::simState
```
**描述**

SIM卡状态。

- -1：未知。

- 0：SIM卡未插入。

- 1：正常识卡。

- 2：需要输入PIN码。

- 3：需要输入PUK码。

- 4：需要输入PIN2码。

- 5：需要输入PUK2码。 


### simType

```
int CardStatusInfo::simType
```
**描述**

SIM卡类型。

- 0：未知。

- 1：普通SIM卡。

- 2：USIM，支持4G网络。
