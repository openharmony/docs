# AudioOffloadInfo


## 概述

音频低功耗属性

**起始版本：** 4.1

**相关模块：**[HdiAudio](_hdi_audio_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [sampleRate](#samplerate) | 采样率  | 
| unsigned int [channelCount](#channelcount) | 声道数  | 
| unsigned long [channelLayout](#channellayout) | 声道布局  | 
| unsigned int [bitRate](#bitrate) | 比特率  | 
| unsigned int [bitWidth](#bitwidth) | 比特位宽  | 
| enum [AudioFormat](_hdi_audio_v20.md#audioformat)[format](#format) | 音频格式  | 
| unsigned int [offloadBufferSize](#offloadbuffersize) | 音频数据缓存长度  | 
| unsigned long [duration](#duration) | 音频持续时间，单位纳秒  | 


## 类成员变量说明


### bitRate

```
unsigned int AudioOffloadInfo::bitRate
```
**描述**

比特率


### bitWidth

```
unsigned int AudioOffloadInfo::bitWidth
```
**描述**

比特位宽


### channelCount

```
unsigned int AudioOffloadInfo::channelCount
```
**描述**

声道数


### channelLayout

```
unsigned long AudioOffloadInfo::channelLayout
```
**描述**

声道布局


### duration

```
unsigned long AudioOffloadInfo::duration
```
**描述**

音频持续时间，单位纳秒


### format

```
enum AudioFormat AudioOffloadInfo::format
```
**描述**

音频格式


### offloadBufferSize

```
unsigned int AudioOffloadInfo::offloadBufferSize
```
**描述**

音频数据缓存长度


### sampleRate

```
unsigned int AudioOffloadInfo::sampleRate
```
**描述**

采样率
