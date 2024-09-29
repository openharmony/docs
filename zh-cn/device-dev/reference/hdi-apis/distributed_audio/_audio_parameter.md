# AudioParameter


## 概述

音频采样属性。

**起始版本：** 4.1

**相关模块：**[Audio](_distributed.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [format](#format) | 音频采样频率。  | 
| unsigned int [channelCount](#channelcount) | 音频通道数目，如单通道为1、立体声为2。  | 
| unsigned int [sampleRate](#samplerate) | 音频采样频率。  | 
| unsigned int [period](#period) | 音频采样周期，单位赫兹。  | 
| unsigned int [frameSize](#framesize) | 音频数据的帧大小。  | 
| unsigned int [streamUsage](#streamusage) | 音频流使用情况。  | 
| enum [PortOperationMode](_distributed.md#portoperationmode)[renderFlags](#renderflags) | 音频播放标志，用于标志播放模式。  | 
| enum [PortOperationMode](_distributed.md#portoperationmode)[capturerFlags](#capturerflags) | 音频录音标志，用于标志播放模式。  | 
| String [ext](#ext) | 参数描述。  | 


## 类成员变量说明


### capturerFlags

```
enum PortOperationMode AudioParameter::capturerFlags
```
**描述**

音频录音标志，用于标志播放模式。


### channelCount

```
unsigned int AudioParameter::channelCount
```
**描述**

音频通道数目，如单通道为1、立体声为2。


### ext

```
String AudioParameter::ext
```
**描述**

参数描述。


### format

```
unsigned int AudioParameter::format
```
**描述**

音频采样频率。


### frameSize

```
unsigned int AudioParameter::frameSize
```
**描述**

音频数据的帧大小。


### period

```
unsigned int AudioParameter::period
```
**描述**

音频采样周期，单位赫兹。


### renderFlags

```
enum PortOperationMode AudioParameter::renderFlags
```
**描述**

音频播放标志，用于标志播放模式。


### sampleRate

```
unsigned int AudioParameter::sampleRate
```
**描述**

音频采样频率。


### streamUsage

```
unsigned int AudioParameter::streamUsage
```
**描述**

音频流使用情况。
