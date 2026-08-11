# OH_MIDICallbacks
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @owen_creeper-->
<!--Designer: @trytocalm-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct {...} OH_MIDICallbacks
```

## 概述

客户端回调结构体，用于监听MIDI设备的热插拔事件和关键服务错误，包含设备热插拔和错误处理的回调函数指针，适用于需要在应用中实时感知MIDI设备状态变化并处理异常的场景。

**起始版本：** 24

**相关模块：** [OHMIDI](capi-ohmidi.md)

**所在头文件：** [native_midi_base.h](capi-native-midi-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [OH_MIDICallback_OnDeviceChange](capi-native-midi-base-h.md#oh_midicallback_ondevicechange) onDeviceChange | 处理设备热插拔事件的回调函数指针。<br>**起始版本：** 24 |
| [OH_MIDICallback_OnError](capi-native-midi-base-h.md#oh_midicallback_onerror) onError | 处理服务运行过程中发生的关键错误的回调函数指针。<br>**起始版本：** 24 |


