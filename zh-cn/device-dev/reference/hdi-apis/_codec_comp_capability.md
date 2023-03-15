# CodecCompCapability


## **概述**

定义Codec编解码能力。

**相关模块:**

[Codec](codec.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [role](#role) | 媒体类型。 | 
| [type](#type) | 编解码类型。 | 
| [compName](#compname)&nbsp;[NAME_LENGTH] | 编解码组件名称。 | 
| [supportProfiles](#supportprofiles)&nbsp;[PROFILE_NUM] | 支持的profiles。 | 
| [maxInst](#maxinst) | 最大实例。 | 
| [isSoftwareCodec](#issoftwarecodec) | 软件编解码还是硬件编解码。 | 
| [processModeMask](#processmodemask) | 编解码处理模式掩码。 | 
| [capsMask](#capsmask) | 编解码播放能力掩码。 | 
| [bitRate](#bitrate) | 支持的码率范围。 | 
| [port](#port) | 支持的音视频编解码能力。 | 


## **类成员变量说明**


### bitRate

  
```
RangeValue CodecCompCapability::bitRate
```

**描述：**

支持的码率范围。


### capsMask

  
```
uint32_t CodecCompCapability::capsMask
```

**描述：**

编解码播放能力掩码，详见[CodecCapsMask](codec.md#codeccapsmask)。


### compName

  
```
char CodecCompCapability::compName[NAME_LENGTH]
```

**描述：**

编解码组件名称。


### isSoftwareCodec

  
```
bool CodecCompCapability::isSoftwareCodec
```

**描述：**

软件编解码还是硬件编解码。


### maxInst

  
```
int32_t CodecCompCapability::maxInst
```

**描述：**

最大实例。


### port

  
```
PortCap CodecCompCapability::port
```

**描述：**

支持的音视频编解码能力。


### processModeMask

  
```
int32_t CodecCompCapability::processModeMask
```

**描述：**

编解码处理模式掩码，详见[CodecProcessMode](codec.md#codecprocessmode)。


### role

  
```
AvCodecRole CodecCompCapability::role
```

**描述：**

媒体类型。


### supportProfiles

  
```
int32_t CodecCompCapability::supportProfiles[PROFILE_NUM]
```

**描述：**

支持的profiles，详见[Profile](codec.md#profile)。


### type

  
```
CodecType CodecCompCapability::type
```

**描述：**

编解码类型。
