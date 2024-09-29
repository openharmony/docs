# Bluetooth


## 概述

提供用于查询蓝牙开关状态的功能。

**起始版本：** 13


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [oh_bluetooth.h](oh__bluetooth_8h.md) | 定义查询蓝牙开关状态的接口。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Bluetooth_SwitchState](#bluetooth_switchstate) [Bluetooth_SwitchState](#bluetooth_switchstate) | 定义蓝牙开关状态的枚举值。 | 
| typedef enum [Bluetooth_ResultCode](#bluetooth_resultcode) [Bluetooth_ResultCode](#bluetooth_resultcode) | 定义蓝牙返回值的错误码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Bluetooth_SwitchState](#bluetooth_switchstate) {<br/>BLUETOOTH_STATE_OFF = 0,<br/>BLUETOOTH_STATE_TURNING_ON = 1,<br/>BLUETOOTH_STATE_ON = 2,<br/>BLUETOOTH_STATE_TURNING_OFF = 3,<br/>BLUETOOTH_STATE_BLE_TURNING_ON = 4,<br/>BLUETOOTH_STATE_BLE_ON = 5,<br/>BLUETOOTH_STATE_BLE_TURNING_OFF = 6<br/>} | 定义蓝牙开关状态的枚举值。 | 
| [Bluetooth_ResultCode](#bluetooth_resultcode) {<br/>BLUETOOTH_SUCCESS = 0,<br/>BLUETOOTH_INVALID_PARAM = 401<br/>} | 定义蓝牙返回值的错误码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Bluetooth_ResultCode](#bluetooth_resultcode) [OH_Bluetooth_GetBluetoothSwitchState](#oh_bluetooth_getbluetoothswitchstate) ([Bluetooth_SwitchState](#bluetooth_switchstate) \*state) | 获取蓝牙开关状态。 | 


## 类型定义说明


### Bluetooth_ResultCode

```
typedef enum Bluetooth_ResultCode Bluetooth_ResultCode
```

**描述**

定义蓝牙返回值的错误码。

**起始版本：** 13


### Bluetooth_SwitchState

```
typedef enum Bluetooth_SwitchState Bluetooth_SwitchState
```

**描述**

定义蓝牙开关状态的枚举值。

**起始版本：** 13


## 枚举类型说明


### Bluetooth_ResultCode

```
enum Bluetooth_ResultCode
```

**描述**

定义蓝牙返回值的错误码。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| BLUETOOTH_SUCCESS | 操作成功。 | 
| BLUETOOTH_INVALID_PARAM | 参数错误。可能原因：1. 输入参数为空指针；2. 参数数值超出定义范围。 | 


### Bluetooth_SwitchState

```
enum Bluetooth_SwitchState
```

**描述**

定义蓝牙开关状态的枚举值。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| BLUETOOTH_STATE_OFF | 表示蓝牙关闭。 | 
| BLUETOOTH_STATE_TURNING_ON | 表示蓝牙打开中。 | 
| BLUETOOTH_STATE_ON | 表示蓝牙已打开，使用就绪。 | 
| BLUETOOTH_STATE_TURNING_OFF | 表示蓝牙关闭中。 | 
| BLUETOOTH_STATE_BLE_TURNING_ON | 表示蓝牙LE only模式打开中。 | 
| BLUETOOTH_STATE_BLE_ON | 表示蓝牙处于LE only模式。 | 
| BLUETOOTH_STATE_BLE_TURNING_OFF | 表示蓝牙LE only模式关闭中。 | 


## 函数说明


### OH_Bluetooth_GetBluetoothSwitchState()

```
Bluetooth_ResultCode OH_Bluetooth_GetBluetoothSwitchState (Bluetooth_SwitchState * state)
```

**描述**

获取蓝牙开关状态。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| state | 指向接收蓝牙开关状态的枚举值的指针。 需要传入非空指针，否则将返回错误码。 详细定义请参考[Bluetooth_SwitchState](#bluetooth_switchstate)。 | 

**返回：**

返回蓝牙开关状态函数的错误码。详细定义请参考[Bluetooth_ResultCode](#bluetooth_resultcode)。 <br/>BLUETOOTH_SUCCESS 成功获取蓝牙开关状态。 BLUETOOTH_INVALID_PARAM 输入参数为空指针。
