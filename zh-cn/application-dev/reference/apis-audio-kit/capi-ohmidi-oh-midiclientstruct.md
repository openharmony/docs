# OH_MIDIClientStruct
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @owen_creeper-->
<!--Designer: @trytocalm-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_MIDIClientStruct OH_MIDIClient
```

## 概述

声明MIDI客户端。OH_MIDIClient用于建立与MIDI服务的连接，是开发者进行MIDI数据收发和设备管理等操作的基础句柄，适用于音乐播放器、MIDI控制器接入、数字音乐创作等需要与MIDI设备通信的场景。

**起始版本：** 24

**相关模块：** [OHMIDI](capi-ohmidi.md)

**所在头文件：** [native_midi_base.h](capi-native-midi-base-h.md)

