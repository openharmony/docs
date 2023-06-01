# AudioSampleAttributes


## 概述

音频采样属性。

**Since:**
3.2
**Version:**
1.0
**相关模块:**

[Audio](_audio.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [type](#type) | enum&nbsp;[AudioCategory](_audio.md#audiocategory)<br/>音频类型，详情参考[AudioCategory](_audio.md#audiocategory)。&nbsp; | 
| [interleaved](#interleaved) | boolean<br/>音频数据交织的标记。&nbsp; | 
| [format](#format) | enum&nbsp;[AudioFormat](_audio.md#audioformat)<br/>音频数据格式，详情参考[AudioFormat](_audio.md#audioformat)。&nbsp; | 
| [sampleRate](#samplerate) | unsigned&nbsp;int<br/>音频采样频率。&nbsp; | 
| [channelCount](#channelcount) | unsigned&nbsp;int<br/>音频通道数目，如单通道为1、立体声为2。&nbsp; | 
| [period](#period) | unsigned&nbsp;int<br/>音频采样周期，单位赫兹。&nbsp; | 
| [frameSize](#framesize) | unsigned&nbsp;int<br/>音频数据的帧大小。&nbsp; | 
| [isBigEndian](#isbigendian) | boolean<br/>音频数据的大端标志。&nbsp; | 
| [isSignedData](#issigneddata) | boolean<br/>音频数据有符号或无符号标志。&nbsp; | 
| [startThreshold](#startthreshold) | unsigned&nbsp;int<br/>音频播放起始阈值。&nbsp; | 
| [stopThreshold](#stopthreshold) | unsigned&nbsp;int<br/>音频播放停止阈值。&nbsp; | 
| [silenceThreshold](#silencethreshold) | unsigned&nbsp;int<br/>录音缓冲区阈值。&nbsp; | 
| [streamId](#streamid) | int<br/>录音或播放的标识符。&nbsp; | 


## 类成员变量说明


### channelCount

  
```
unsigned int AudioSampleAttributes::channelCount
```
**描述:**
音频通道数目，如单通道为1、立体声为2。


### format

  
```
enum AudioFormat AudioSampleAttributes::format
```
**描述:**
音频数据格式，详情参考[AudioFormat](_audio.md#audioformat)。


### frameSize

  
```
unsigned int AudioSampleAttributes::frameSize
```
**描述:**
音频数据的帧大小。


### interleaved

  
```
boolean AudioSampleAttributes::interleaved
```
**描述:**
音频数据交织的标记。


### isBigEndian

  
```
boolean AudioSampleAttributes::isBigEndian
```
**描述:**
音频数据的大端标志。


### isSignedData

  
```
boolean AudioSampleAttributes::isSignedData
```
**描述:**
音频数据有符号或无符号标志。


### period

  
```
unsigned int AudioSampleAttributes::period
```
**描述:**
音频采样周期，单位赫兹。


### sampleRate

  
```
unsigned int AudioSampleAttributes::sampleRate
```
**描述:**
音频采样频率。


### silenceThreshold

  
```
unsigned int AudioSampleAttributes::silenceThreshold
```
**描述:**
录音缓冲区阈值。


### startThreshold

  
```
unsigned int AudioSampleAttributes::startThreshold
```
**描述:**
音频播放起始阈值。


### stopThreshold

  
```
unsigned int AudioSampleAttributes::stopThreshold
```
**描述:**
音频播放停止阈值。


### streamId

  
```
int AudioSampleAttributes::streamId
```
**描述:**
录音或播放的标识符。


### type

  
```
enum AudioCategory AudioSampleAttributes::type
```
**描述:**
音频类型，详情参考[AudioCategory](_audio.md#audiocategory)。
