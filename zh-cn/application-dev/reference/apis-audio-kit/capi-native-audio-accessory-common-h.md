# native_audio_accessory_common.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

## 概述

声明外部音频配件设备接口的公共数据结构。

定义音频配件接口的公共类型。

**引用文件：** <ohaudio/native_audio_accessory_common.h>

**库：** libohaudio.so

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 26.0.0

**相关模块：** [OHAudio](capi-ohaudio.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioAccessoryManager](capi-ohaudio-oh-audioaccessorymanager.md) | OH_AudioAccessoryManager | 声明音频配件管理器。 |
| [OH_AudioAccessory](capi-ohaudio-oh-audioaccessory.md) | OH_AudioAccessory | 声明音频配件。 |
| [OH_AudioAccessoryInputStream](capi-ohaudio-oh-audioaccessoryinputstream.md) | OH_AudioAccessoryInputStream | 声明音频配件输入流。 |
| [OH_AudioAccessoryInfo](capi-ohaudio-oh-audioaccessoryinfo.md) | OH_AudioAccessoryInfo | 定义音频配件的基本信息。 |
| [OH_AudioAccessoryNoiseReductionCapability](capi-ohaudio-oh-audioaccessorynoisereductioncapability.md) | OH_AudioAccessoryNoiseReductionCapability | 定义音频配件的降噪能力。 |
| [OH_AudioAccessoryCapabilities](capi-ohaudio-oh-audioaccessorycapabilities.md) | OH_AudioAccessoryCapabilities | 定义音频配件的能力。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioAccessoryType](#oh_audioaccessorytype) | OH_AudioAccessoryType | 枚举音频配件连接类型。 |

## 枚举类型说明

### OH_AudioAccessoryType

```c
enum OH_AudioAccessoryType
```

**描述**

枚举音频配件连接类型。

**起始版本：** 26.0.0

| 枚举项 | 描述 |
| -- | -- |
| AUDIO_ACCESSORY_TYPE_BT_SPP = 1 | 蓝牙串行端口配置文件（Serial Port Profile，SPP）连接。 |