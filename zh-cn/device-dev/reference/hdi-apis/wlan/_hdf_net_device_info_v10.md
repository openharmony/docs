# HdfNetDeviceInfo


## 概述

网络设备信息。

**起始版本：** 3.2

**相关模块：**[WLAN](_w_l_a_n_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [index](#index) | 网络设备索引。  | 
| String [ifName](#ifname) | 网卡名称。  | 
| unsigned int [ifNameLen](#ifnamelen) | 网卡名称长度。  | 
| unsigned char [iftype](#iftype) | 网卡类型。  | 
| unsigned char[] [mac](#mac) | 网络设备MAC地址。  | 


## 类成员变量说明


### ifName

```
String HdfNetDeviceInfo::ifName
```
**描述**

网卡名称。


### ifNameLen

```
unsigned int HdfNetDeviceInfo::ifNameLen
```
**描述**

网卡名称长度。


### iftype

```
unsigned char HdfNetDeviceInfo::iftype
```
**描述**

网卡类型。


### index

```
unsigned int HdfNetDeviceInfo::index
```
**描述**

网络设备索引。


### mac

```
unsigned char [] HdfNetDeviceInfo::mac
```
**描述**

网络设备MAC地址。
