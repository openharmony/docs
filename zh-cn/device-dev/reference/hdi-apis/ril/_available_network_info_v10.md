# AvailableNetworkInfo


## 概述

可用网络信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [longName](#longname) | 获取注册网络的长字母数字格式名称  | 
| String [shortName](#shortname) | 获取注册网络的短字母数字格式名称  | 
| String [numeric](#numeric) | 可用网络编号  | 
| int [status](#status) | 网络状态，具体查看[RilRegStatus](_ril_v10.md#rilregstatus) | 
| int [rat](#rat) | 语音接入技术类型，具体查看[RilRadioTech](_ril_v10.md#rilradiotech) | 


## 类成员变量说明


### longName

```
String AvailableNetworkInfo::longName
```
**描述**

获取注册网络的长字母数字格式名称


### numeric

```
String AvailableNetworkInfo::numeric
```
**描述**

可用网络编号


### rat

```
int AvailableNetworkInfo::rat
```
**描述**

语音接入技术类型，具体查看[RilRadioTech](_ril_v10.md#rilradiotech)


### shortName

```
String AvailableNetworkInfo::shortName
```
**描述**

获取注册网络的短字母数字格式名称


### status

```
int AvailableNetworkInfo::status
```
**描述**

网络状态，具体查看[RilRegStatus](_ril_v10.md#rilregstatus)
