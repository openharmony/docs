# CodecAudioPortCap


## 概述

定义音频编解码能力。

**起始版本：** 4.1

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int[] [sampleFormats](#sampleformats) | 支持的音频采样格式，详见[AudioSampleFormat](_codec_v20.md#audiosampleformat)。  | 
| int[] [sampleRate](#samplerate) | 支持的音频采样率，详见[AudioSampleRate](_codec_v20.md#audiosamplerate)。  | 
| int[] [channelLayouts](#channellayouts) | 支持的通道格式类型、单通道、平衡声道、3D立体声道等。  | 
| int[] [channelCount](#channelcount) | 支持的音频通道数。  | 


## 类成员变量说明


### channelCount

```
int [] CodecAudioPortCap::channelCount
```
**描述**

支持的音频通道数。


### channelLayouts

```
int [] CodecAudioPortCap::channelLayouts
```
**描述**

支持的通道格式类型、单通道、平衡声道、3D立体声道等。


### sampleFormats

```
int [] CodecAudioPortCap::sampleFormats
```
**描述**

支持的音频采样格式，详见[AudioSampleFormat](_codec_v20.md#audiosampleformat)。


### sampleRate

```
int [] CodecAudioPortCap::sampleRate
```
**描述**

支持的音频采样率，详见[AudioSampleRate](_codec_v20.md#audiosamplerate)。
