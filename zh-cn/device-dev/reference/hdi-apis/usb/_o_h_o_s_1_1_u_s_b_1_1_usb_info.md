# UsbInfo


## 概述

USB设备信息类。

**起始版本：** 3.0

**相关模块：**[USB](_u_s_b.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [setDevInfoStatus](#setdevinfostatus) (int32_t status) | 设置USB设备状态。  | 
| [setDevInfoBusNum](#setdevinfobusnum) (int32_t busNum) | 设置USB总线编号。  | 
| [setDevInfoDevNum](#setdevinfodevnum) (int32_t devNum) | 设置USB设备编号。  | 
| [getDevInfoStatus](#getdevinfostatus) () const | 获取USB设备状态。  | 
| [getDevInfoBusNum](#getdevinfobusnum) () const | 获取USB总线编号。  | 
| [getDevInfoDevNum](#getdevinfodevnum) () const | 获取USB设备编号。  | 


### Private 属性

| 名称 | 描述 | 
| -------- | -------- |
| [devInfo](#devinfo) | USB设备信息。 | 


## 成员函数说明


### getDevInfoBusNum()

```
int32_t UsbInfo::getDevInfoBusNum () const
```
**描述**

获取USB总线编号。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 输出参数，USB总线编号。 | 


### getDevInfoDevNum()

```
int32_t UsbInfo::getDevInfoDevNum () const
```
**描述**

获取USB设备编号。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 输出参数，USB设备编号。 | 


### getDevInfoStatus()

```
int32_t UsbInfo::getDevInfoStatus () const
```
**描述**

获取USB设备状态。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 输出参数，设备状态。 | 


### setDevInfoBusNum()

```
void UsbInfo::setDevInfoBusNum (int32_t busNum)
```
**描述**

设置USB总线编号。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 输入参数，USB总线编号。 | 


### setDevInfoDevNum()

```
void UsbInfo::setDevInfoDevNum (int32_t devNum)
```
**描述**

设置USB设备编号。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 输入参数，USB设备编号。 | 


### setDevInfoStatus()

```
void UsbInfo::setDevInfoStatus (int32_t status)
```
**描述**

设置USB设备状态。

**起始版本：** 3.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 输入参数，设备状态。 | 


## 类成员变量说明


### devInfo

```
USBDeviceInfo UsbInfo::devInfo
```
**描述**

USB设备信息。
