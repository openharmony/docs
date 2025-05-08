# OH_AVRecorder_Config


## 概述

提供媒体AVRecorder的配置定义。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**相关模块：**[AVRecorder](_a_v_recorder.md)

**所在头文件：**[avrecorder_base.h](avrecorder__base_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVRecorder_AudioSourceType](_a_v_recorder.md#oh_avrecorder_audiosourcetype) [audioSourceType](#audiosourcetype) | 录制音频源类型。 | 
| [OH_AVRecorder_VideoSourceType](_a_v_recorder.md#oh_avrecorder_videosourcetype) [videoSourceType](#videosourcetype) | 录制视频源类型。 | 
| [OH_AVRecorder_Profile](_o_h___a_v_recorder___profile.md) [profile](#profile) | 包含音频和视频编码配置。 | 
| char \*[url](#url) | 定义文件 URL，格式为fd://xx。 | 
| [OH_AVRecorder_FileGenerationMode](_a_v_recorder.md#oh_avrecorder_filegenerationmode) [fileGenerationMode](#filegenerationmode) | 指定录制输出文件的生成模式。 | 
| [OH_AVRecorder_Metadata](_o_h___a_v_recorder___metadata.md) [metadata](#metadata) | 包含录制媒体的附加元数据。 | 


## 成员变量说明


### audioSourceType

```
OH_AVRecorder_AudioSourceType audioSourceType
```

**描述**

录制音频源类型。


### videoSourceType

```
OH_AVRecorder_VideoSourceType videoSourceType
```

**描述**

录制视频源类型。


### profile

```
OH_AVRecorder_Profile profile
```

**描述**

包含音频和视频编码配置。


### url

```
char *url
```

**描述**

定义文件 URL，格式为fd://xx。


### fileGenerationMode

```
OH_AVRecorder_FileGenerationMode fileGenerationMode
```

**描述**

指定录制输出文件的生成模式。


### metadata

```
OH_AVRecorder_Metadata metadata
```

**描述**

包含录制媒体的附加元数据。
