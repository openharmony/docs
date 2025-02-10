# Input_DeviceListener


## 概述

定义一个结构体用于监听设备热插拔。

**起始版本：** 13

**相关模块：**[Input](input.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [Input_DeviceAddedCallback](input.md#input_deviceaddedcallback) [deviceAddedCallback](#deviceaddedcallback) | 定义一个回调函数用于回调设备热插事件。  | 
| [Input_DeviceRemovedCallback](input.md#input_deviceremovedcallback) [deviceRemovedCallback](#deviceremovedcallback) | 定义一个回调函数用于回调设备热拔事件。  | 


## 结构体成员变量说明


### deviceAddedCallback

```
Input_DeviceAddedCallback Input_DeviceListener::deviceAddedCallback
```
**描述**
定义一个回调函数用于回调设备热插事件。


### deviceRemovedCallback

```
Input_DeviceRemovedCallback Input_DeviceListener::deviceRemovedCallback
```
**描述**
定义一个回调函数用于回调设备热拔事件。
