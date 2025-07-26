# Input_DeviceListener

## 概述

定义一个结构体用于监听设备热插拔。

**起始版本：** 13

**相关模块：** [input](capi-input.md)

**所在头文件：** [oh_input_manager.h](capi-oh-input-manager-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| Input_DeviceAddedCallback deviceAddedCallback | 定义一个回调函数，用于回调设备热插事件。 |
| Input_DeviceRemovedCallback deviceRemovedCallback | 定义一个回调函数，用于回调设备热拔事件。 |


