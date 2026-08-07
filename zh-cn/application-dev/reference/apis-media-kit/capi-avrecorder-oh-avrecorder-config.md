# OH_AVRecorder_Config
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @zzs911-->

```c
typedef struct OH_AVRecorder_Config {...} OH_AVRecorder_Config
```

## 概述

提供媒体AVRecorder的配置定义，用于设置音视频录制时的音频源类型、视频源类型、编码配置、输出文件URL、文件生成模式、元数据及最大录制时长参数，适用于需要自定义录制配置的场景。

**起始版本：** 18

**相关模块：** [AVRecorder](capi-avrecorder.md)

**所在头文件：** [avrecorder_base.h](capi-avrecorder-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [OH_AVRecorder_AudioSourceType](capi-avrecorder-base-h.md#oh_avrecorder_audiosourcetype) audioSourceType | 录制音频源类型，用于指定录制时采集音频的输入源。 |
| [OH_AVRecorder_VideoSourceType](capi-avrecorder-base-h.md#oh_avrecorder_videosourcetype) videoSourceType | 录制视频源类型，用于指定录制时采集视频的输入源。 |
| [OH_AVRecorder_Profile](capi-avrecorder-oh-avrecorder-profile.md) profile | 包含音视频录制的详细参数，如编码格式、比特率、分辨率等。 |
| char* url | 指定录制输出文件的URL，格式为fd://xx，其中xx为文件描述符（fd）的数值，需为非负整数。当fileGenerationMode为应用创建模式时，必须设置此参数；当fileGenerationMode为系统创建模式时，无需设置此参数。传入不符合该格式的URL时，录制准备失败。使用时应确保文件描述符（fd）在录制期间保持有效，避免因fd失效导致录制异常。 |
| [OH_AVRecorder_FileGenerationMode](capi-avrecorder-base-h.md#oh_avrecorder_filegenerationmode) fileGenerationMode | 指定录制输出文件的生成模式。应用创建模式适用于需要自定义输出文件URL的录制场景；系统创建模式适用于无需指定输出文件URL的录制场景，但仅在相机录制场景下生效，且会触发OH_AVRecorder_OnUri回调通知应用获取录制生成的媒体资源。默认值为应用创建模式。 |
| [OH_AVRecorder_Metadata](capi-avrecorder-oh-avrecorder-metadata.md) metadata | 包含录制媒体的附加元数据。用于为录制文件添加描述性属性，如体裁分类、视频旋转方向、地理位置及自定义参数等。默认为空。 |
| int32_t maxDuration | 指定最大录制时长，单位为秒（s）。值小于等于0时表示无时长限制，默认值为0。达到最大录制时长后自动停止录制。 |


