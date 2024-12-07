# AudioSampleAttributes


## 概述

音频采样属性。

**起始版本：** 4.0

**相关模块：**[HdiAudio](_hdi_audio_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [AudioCategory](_hdi_audio_v11.md#audiocategory)[type](#type) | 音频类型，详情参考[AudioCategory](_hdi_audio_v11.md#audiocategory)。  | 
| boolean [interleaved](#interleaved) | 音频数据交织的标记。  | 
| enum [AudioFormat](_hdi_audio_v11.md#audioformat)[format](#format) | 音频数据格式，详情参考[AudioFormat](_hdi_audio_v11.md#audioformat)。  | 
| unsigned int [sampleRate](#samplerate) | 音频采样频率。  | 
| unsigned int [channelCount](#channelcount) | 音频通道数目，如单通道为1、立体声为2。  | 
| unsigned int [period](#period) | 音频采样周期，单位赫兹。  | 
| unsigned int [frameSize](#framesize) | 音频数据的帧大小。  | 
| boolean [isBigEndian](#isbigendian) | 音频数据的大端标志。  | 
| boolean [isSignedData](#issigneddata) | 音频数据有符号或无符号标志。  | 
| unsigned int [startThreshold](#startthreshold) | 音频播放起始阈值。  | 
| unsigned int [stopThreshold](#stopthreshold) | 音频播放停止阈值。  | 
| unsigned int [silenceThreshold](#silencethreshold) | 录音缓冲区阈值。  | 
| int [streamId](#streamid) | 录音或播放的标识符。  | 
| int [sourceType](#sourcetype) | 播放或录音的音源类型  | 
| struct [AudioOffloadInfo](_audio_offload_info_v10.md)[offloadInfo](#offloadinfo) | offload流信息  | 


## 类成员变量说明


### channelCount

```
unsigned int AudioSampleAttributes::channelCount
```
**描述**

音频通道数目，如单通道为1、立体声为2。


### format

```
enum AudioFormat AudioSampleAttributes::format
```
**描述**

音频数据格式，详情参考[AudioFormat](_hdi_audio_v11.md#audioformat)。


### frameSize

```
unsigned int AudioSampleAttributes::frameSize
```
**描述**

音频数据的帧大小。


### interleaved

```
boolean AudioSampleAttributes::interleaved
```
**描述**

音频数据交织的标记。


### isBigEndian

```
boolean AudioSampleAttributes::isBigEndian
```
**描述**

音频数据的大端标志。


### isSignedData

```
boolean AudioSampleAttributes::isSignedData
```
**描述**

音频数据有符号或无符号标志。


### offloadInfo

```
struct AudioOffloadInfo AudioSampleAttributes::offloadInfo
```
**描述**

offload流信息


### period

```
unsigned int AudioSampleAttributes::period
```
**描述**

音频采样周期，单位赫兹。


### sampleRate

```
unsigned int AudioSampleAttributes::sampleRate
```
**描述**

音频采样频率。


### silenceThreshold

```
unsigned int AudioSampleAttributes::silenceThreshold
```
**描述**

录音缓冲区阈值。


### sourceType

```
int AudioSampleAttributes::sourceType
```
**描述**

播放或录音的音源类型


### startThreshold

```
unsigned int AudioSampleAttributes::startThreshold
```
**描述**

音频播放起始阈值。


### stopThreshold

```
unsigned int AudioSampleAttributes::stopThreshold
```
**描述**

音频播放停止阈值。


### streamId

```
int AudioSampleAttributes::streamId
```
**描述**

录音或播放的标识符。


### type

```
enum AudioCategory AudioSampleAttributes::type
```
**描述**

音频类型，详情参考[AudioCategory](_hdi_audio_v11.md#audiocategory)。
