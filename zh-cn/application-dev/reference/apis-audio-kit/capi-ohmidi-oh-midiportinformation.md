# OH_MIDIPortInformation
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @owen_creeper-->
<!--Designer: @trytocalm-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct {...} OH_MIDIPortInformation
```

## 概述

端口信息结构体。用于枚举和标识MIDI设备端口，包含可显示的端口名称、端口索引、所属设备ID及端口方向（输入或输出）等关键信息，便于开发者在MIDI应用中管理和操作各端口。

**起始版本：** 24

**相关模块：** [OHMIDI](capi-ohmidi.md)

**所在头文件：** [native_midi_base.h](capi-native-midi-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t portIndex | 端口在设备中的索引号。<br>**起始版本：** 24 |
| int64_t deviceId | 端口所属的MIDI设备ID。<br>**起始版本：** 24 |
| [OH_MIDIPortDirection](capi-native-midi-base-h.md#oh_midiportdirection) direction | 端口方向（输入或输出）。<br>**起始版本：** 24 |
| char name[64] | 端口名称。<br>**起始版本：** 24 |


