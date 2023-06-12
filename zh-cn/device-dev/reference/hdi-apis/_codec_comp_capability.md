# CodecCompCapability


## 概述

定义Codec编解码能力。

**相关模块:**

[Codec](_codec.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [role](#role) | [AvCodecRole](_codec.md#avcodecrole)<br/>媒体类型。&nbsp; | 
| [type](#type) | [CodecType](_codec.md#codectype)<br/>编解码类型。&nbsp; | 
| [compName](#compname)&nbsp;[[NAME_LENGTH](_codec.md#name_length)] | char<br/>编解码组件名称。&nbsp; | 
| [supportProfiles](#supportprofiles)&nbsp;[[PROFILE_NUM](_codec.md#profile_num)] | int32_t<br/>支持的profiles，详见[Profile](_codec.md#profile)。&nbsp; | 
| [maxInst](#maxinst) | int32_t<br/>最大实例。&nbsp; | 
| [isSoftwareCodec](#issoftwarecodec) | bool<br/>软件编解码还是硬件编解码。&nbsp; | 
| [processModeMask](#processmodemask) | int32_t<br/>编解码处理模式掩码，详见[CodecProcessMode](_codec.md#codecprocessmode)。&nbsp; | 
| [capsMask](#capsmask) | uint32_t<br/>编解码播放能力掩码，详见[CodecCapsMask](_codec.md#codeccapsmask)。&nbsp; | 
| [bitRate](#bitrate) | [RangeValue](_range_value.md)<br/>支持的码率范围。&nbsp; | 
| [port](#port) | [PortCap](union_port_cap.md)<br/>支持的音视频编解码能力。&nbsp; | 


## 类成员变量说明


### bitRate

  
```
RangeValue CodecCompCapability::bitRate
```
**描述:**
支持的码率范围。


### capsMask

  
```
uint32_t CodecCompCapability::capsMask
```
**描述:**
编解码播放能力掩码，详见[CodecCapsMask](_codec.md#codeccapsmask)。


### compName

  
```
char CodecCompCapability::compName[NAME_LENGTH]
```
**描述:**
编解码组件名称。


### isSoftwareCodec

  
```
bool CodecCompCapability::isSoftwareCodec
```
**描述:**
软件编解码还是硬件编解码。


### maxInst

  
```
int32_t CodecCompCapability::maxInst
```
**描述:**
最大实例。


### port

  
```
PortCap CodecCompCapability::port
```
**描述:**
支持的音视频编解码能力。


### processModeMask

  
```
int32_t CodecCompCapability::processModeMask
```
**描述:**
编解码处理模式掩码，详见[CodecProcessMode](_codec.md#codecprocessmode)。


### role

  
```
AvCodecRole CodecCompCapability::role
```
**描述:**
媒体类型。


### supportProfiles

  
```
int32_t CodecCompCapability::supportProfiles[PROFILE_NUM]
```
**描述:**
支持的profiles，详见[Profile](_codec.md#profile)。


### type

  
```
CodecType CodecCompCapability::type
```
**描述:**
编解码类型。
