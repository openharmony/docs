# Hid_Device


## 概述

设备基本信息。

**起始版本：** 11

**相关模块：**[HidDdk](_hid_ddk.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [deviceName](_hid_ddk.md#devicename) | 设备名称 | 
| uint16_t [vendorId](_hid_ddk.md#vendorid) | 厂商ID | 
| uint16_t [productId](_hid_ddk.md#productid) | 产品ID | 
| uint16_t [version](_hid_ddk.md#version) | 版本号 | 
| uint16_t [bustype](_hid_ddk.md#bustype) | 总线类型 | 
| [Hid_DeviceProp](_hid_ddk.md#hid_deviceprop) \* [properties](_hid_ddk.md#properties) | 设备特性 | 
| uint16_t [propLength](_hid_ddk.md#proplength) | 设备特性数量 | 
