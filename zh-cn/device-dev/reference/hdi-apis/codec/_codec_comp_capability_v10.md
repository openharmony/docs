# CodecCompCapability


## 概述

定义Codec编解码能力。

**起始版本：** 3.2

**相关模块：**[Codec](_codec_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [AvCodecRole](_codec_v10.md#avcodecrole)[role](#role) | 媒体类型。  | 
| enum [CodecType](_codec_v10.md#codectype)[type](#type) | 编解码类型。  | 
| String [compName](#compname) | 编解码组件名称。  | 
| int[] [supportProfiles](#supportprofiles) | 支持的profiles，详见[Profile](_codec_v10.md#profile)。  | 
| int [maxInst](#maxinst) | 最大实例。  | 
| boolean [isSoftwareCodec](#issoftwarecodec) | 软件编解码还是硬件编解码。  | 
| int [processModeMask](#processmodemask) | 编解码处理模式掩码，详见[CodecProcessMode](_codec_v10.md#codecprocessmode)。  | 
| unsigned int [capsMask](#capsmask) | 编解码播放能力掩码，详见[CodecCapsMask](_codec_v10.md#codeccapsmask)。  | 
| struct [RangeValue](_range_value_v10.md)[bitRate](#bitrate) | 支持的码率范围。  | 
| struct [PortCap](_port_cap_v10.md)[port](#port) | 支持的音视频编解码能力。  | 


## 类成员变量说明


### bitRate

```
struct RangeValue CodecCompCapability::bitRate
```
**描述**

支持的码率范围。


### capsMask

```
unsigned int CodecCompCapability::capsMask
```
**描述**

编解码播放能力掩码，详见[CodecCapsMask](_codec_v10.md#codeccapsmask)。


### compName

```
String CodecCompCapability::compName
```
**描述**

编解码组件名称。


### isSoftwareCodec

```
boolean CodecCompCapability::isSoftwareCodec
```
**描述**

软件编解码还是硬件编解码。


### maxInst

```
int CodecCompCapability::maxInst
```
**描述**

最大实例。


### port

```
struct PortCap CodecCompCapability::port
```
**描述**

支持的音视频编解码能力。


### processModeMask

```
int CodecCompCapability::processModeMask
```
**描述**

编解码处理模式掩码，详见[CodecProcessMode](_codec_v10.md#codecprocessmode)。


### role

```
enum AvCodecRole CodecCompCapability::role
```
**描述**

媒体类型。


### supportProfiles

```
int [] CodecCompCapability::supportProfiles
```
**描述**

支持的profiles，详见[Profile](_codec_v10.md#profile)。


### type

```
enum CodecType CodecCompCapability::type
```
**描述**

编解码类型。
