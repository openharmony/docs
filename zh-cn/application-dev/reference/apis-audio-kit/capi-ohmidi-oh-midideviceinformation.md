# OH_MIDIDeviceInformation
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @owen_creeper-->
<!--Designer: @trytocalm-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct {...} OH_MIDIDeviceInformation
```

## 概述

设备信息结构体，用于存储MIDI设备的详细信息，包括设备唯一标识符、设备类型（如USB、BLE）、支持的MIDI协议、设备名称、厂商ID、产品ID及物理地址等。适用于在MIDI设备枚举、识别和连接管理等场景中，获取并传递设备的完整属性信息。

**起始版本：** 24

**相关模块：** [OHMIDI](capi-ohmidi.md)

**所在头文件：** [native_midi_base.h](capi-native-midi-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int64_t midiDeviceId | MIDI设备的唯一标识符。<br>**起始版本：** 24 |
| [OH_MIDIDeviceType](capi-native-midi-base-h.md#oh_mididevicetype) deviceType | 设备类型（USB或BLE）。<br>**起始版本：** 24 |
| [OH_MIDIProtocol](capi-native-midi-base-h.md#oh_midiprotocol) nativeProtocol | 设备原生支持的MIDI协议。- OH_MIDI_PROTOCOL_1_0：设备是传统设备或当前配置为MIDI 1.0。<br> - OH_MIDI_PROTOCOL_2_0：设备使用MIDI 2.0协议。<br>**起始版本：** 24 |
| char deviceName[256] | 设备名称。<br>**起始版本：** 24 |
| uint64_t vendorId | 厂商ID。<br>**起始版本：** 24 |
| uint64_t productId | 产品ID。<br>**起始版本：** 24 |
| char deviceAddress[64] | 设备物理地址，采用冒号分隔的十六进制MAC地址格式，例如"00:11:22:33:44:55"，仅BLE设备类型时有效。<br>**起始版本：** 24 |


