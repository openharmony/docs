# OH_MIDIPortDescriptor
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @owen_creeper-->
<!--Designer: @trytocalm-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct {...} OH_MIDIPortDescriptor
```

## 概述

端口描述符结构体，用于打开端口时指定端口索引和MIDI协议版本（MIDI 1.0或MIDI 2.0），由系统自动完成应用与硬件之间的协议适配与数据转换，适用于需要在不同MIDI协议版本间进行兼容通信的场景。

**起始版本：** 24

**相关模块：** [OHMIDI](capi-ohmidi.md)

**所在头文件：** [native_midi_base.h](capi-native-midi-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t portIndex | 要打开的端口索引号。取值范围为0到设备实际端口数减1，具体有效索引需通过设备枚举接口获取。<br>**起始版本：** 24 |
| [OH_MIDIProtocol](capi-native-midi-base-h.md#oh_midiprotocol) protocol | 指定要使用的MIDI协议版本（MIDI 1.0或MIDI 2.0）。服务会根据此字段在应用和硬件之间转换数据。应用只需声明期望的协议版本，以下是协议版本与硬件不匹配时的系统处理行为：<br> 1. 在MIDI 2.0设备上请求OH_MIDI_PROTOCOL_1_0：（无损兼容）<br>    应用发送UMP Type 2（MIDI 1.0通道声音）消息，服务直接转发给设备，无数据损失。<br> 2. 在MIDI 1.0设备上请求OH_MIDI_PROTOCOL_2_0：（有损转换）<br>    应用发送UMP Type 4（MIDI 2.0通道声音）消息，服务将Type 4降级转换为Type 2（例如：截断力度值，丢弃逐音符数据），会丢失数据精度，MIDI 2.0新增且在MIDI 1.0中无法表达的消息（如Per-Note控制器消息）可能被丢弃。<br>**起始版本：** 24 |


