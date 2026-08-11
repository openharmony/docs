# OH_MIDIEvent
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @owen_creeper-->
<!--Designer: @trytocalm-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct {...} OH_MIDIEvent
```

## 概述

MIDI事件结构体（通用），用于以Universal MIDI Packets（UMP）格式承载和传输MIDI事件数据，适用于MIDI消息的接收、发送与处理场景（如音乐制作应用接收和处理MIDI控制器输入事件、数字音频工作站处理MIDI消息、音乐教育类应用中MIDI设备交互等）。原始字节流（MIDI 1.0）数据需要先转换为UMP格式后再填充此结构体。

**起始版本：** 24

**相关模块：** [OHMIDI](capi-ohmidi.md)

**所在头文件：** [native_midi_base.h](capi-native-midi-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint64_t timestamp | 时间戳，单位为纳秒。<br> 通过clock_gettime(CLOCK_MONOTONIC, &time)获取基准时间。值为0表示立即发送。<br>**起始版本：** 24 |
| size_t length | UMP数据包中的32位字（word）数量，而非字节数。取值取决于UMP消息类型。<br> 例如：Type 1消息（如UMP系统实时与公共消息）占1个字（32位），Type 4消息（如UMP MIDI 2.0通道声音消息）占2个字（64位）。<br>**起始版本：** 24 |
| uint32_t *data | 指向UMP数据的指针，包含UMP字（uint32_t）。原始字节流（MIDI 1.0）数据需先转换为UMP格式后再填充此字段。此指针必须指向4字节对齐的内存地址，以满足UMP规范对32位边界对齐的要求。<br>**起始版本：** 24 |


