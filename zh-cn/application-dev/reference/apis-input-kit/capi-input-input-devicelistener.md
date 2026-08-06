# Input_DeviceListener

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @zhang_yixin13-->

```c
typedef struct Input_DeviceListener {
    // ...
} Input_DeviceListener
```

## 概述

定义一个结构体用于监听设备热插拔，该功能适用于需要实时响应输入设备连接和断开场景的应用程序，如游戏、音乐播放器等。通过监听设备热插拔事件，应用程序可以及时更新输入状态，提升用户体验，避免因设备断开导致的异常情况。

**起始版本：** 13

**相关模块：** [input](capi-input.md)

**所在头文件：** [oh_input_manager.h](capi-oh-input-manager-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [Input_DeviceAddedCallback](capi-oh-input-manager-h.md#input_deviceaddedcallback) deviceAddedCallback | 定义一个回调函数，用于接收设备热插事件。 |
| [Input_DeviceRemovedCallback](capi-oh-input-manager-h.md#input_deviceremovedcallback) deviceRemovedCallback | 定义一个回调函数，用于接收设备热拔事件。 |
