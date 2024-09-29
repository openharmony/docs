# oh_bluetooth.h


## 概述

定义查询蓝牙开关状态的接口。

**库：** libbluetooth.so

**系统能力：** SystemCapability.Communication.Bluetooth.Core

**起始版本：** 13

**相关模块：**[Bluetooth](_bluetooth.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Bluetooth_SwitchState](_bluetooth.md#bluetooth_switchstate) [Bluetooth_SwitchState](_bluetooth.md#bluetooth_switchstate) | 定义蓝牙开关状态的枚举值。 | 
| typedef enum [Bluetooth_ResultCode](_bluetooth.md#bluetooth_resultcode) [Bluetooth_ResultCode](_bluetooth.md#bluetooth_resultcode) | 定义蓝牙返回值的错误码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Bluetooth_SwitchState](_bluetooth.md#bluetooth_switchstate) {<br/>[BLUETOOTH_STATE_OFF](_bluetooth.md) = 0,<br/>[BLUETOOTH_STATE_TURNING_ON](_bluetooth.md) = 1,<br/>[BLUETOOTH_STATE_ON](_bluetooth.md) = 2,<br/>[BLUETOOTH_STATE_TURNING_OFF](_bluetooth.md) = 3,<br/>[BLUETOOTH_STATE_BLE_TURNING_ON](_bluetooth.md) = 4,<br/>[BLUETOOTH_STATE_BLE_ON](_bluetooth.md) = 5,<br/>[BLUETOOTH_STATE_BLE_TURNING_OFF](_bluetooth.md) = 6<br/>} | 定义蓝牙开关状态的枚举值。 | 
| [Bluetooth_ResultCode](_bluetooth.md#bluetooth_resultcode) {<br/>[BLUETOOTH_SUCCESS](_bluetooth.md) = 0,<br/>[BLUETOOTH_INVALID_PARAM](_bluetooth.md) = 401<br/>} | 定义蓝牙返回值的错误码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Bluetooth_ResultCode](_bluetooth.md#bluetooth_resultcode) [OH_Bluetooth_GetBluetoothSwitchState](_bluetooth.md#oh_bluetooth_getbluetoothswitchstate) ([Bluetooth_SwitchState](_bluetooth.md#bluetooth_switchstate) \*state) | 获取蓝牙开关状态。 | 
