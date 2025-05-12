# OH_AudioBuffer


## 概述

定义了音频数据的大小，类型，时间戳等配置信息。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**相关模块：**[AVScreenCapture](_a_v_screen_capture.md)

**所在头文件：**[native_avscreen_capture_base.h](native__avscreen__capture__base_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint8_t \* [buf](#buf) | 音频buffer内存。  | 
| int32_t [size](#size) | 音频buffer内存大小。  | 
| int64_t [timestamp](#timestamp) | 音频buffer时间戳。  | 
| [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) [type](#type) | 音频录制源类型。  | 


## 结构体成员变量说明


### buf

```
uint8_t* OH_AudioBuffer::buf
```
**描述**
音频buffer内存。


### size

```
int32_t OH_AudioBuffer::size
```
**描述**
音频buffer内存大小。


### timestamp

```
int64_t OH_AudioBuffer::timestamp
```
**描述**
音频buffer时间戳。


### type

```
OH_AudioCaptureSourceType OH_AudioBuffer::type
```
**描述**
音频录制源类型。
