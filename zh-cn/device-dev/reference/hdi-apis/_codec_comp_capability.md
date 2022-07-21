# CodecCompCapability


## **概述**

**所属模块:**

[Codec](_codec.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [role](#role) | 媒体类型。 | 
| [type](#type) | 编解码类型。 | 
| [compName](#compname)&nbsp;[[NAME_LENGTH](_codec.md#gaf71324c57f05ff9e24bd384925dd6b17)] | 编解码组件名称。 | 
| [supportProfiles](#supportprofiles)&nbsp;[[PROFILE_NUM](_codec.md#gaab6353cb3662bdc672ae8ab90df529ce)] | 支持的profiles，详见[Profile](_codec.md#profile)。 | 
| [maxInst](#maxinst) | 最大实例。 | 
| [isSoftwareCodec](#issoftwarecodec) | 软件编解码还是硬件编解码。 | 
| [processModeMask](#processmodemask) | 编解码处理模式掩码，详见[CodecProcessMode](_codec.md#codecprocessmode)。 | 
| [capsMask](#capsmask) | 编解码播放能力掩码，详见[CodecCapsMask](_codec.md#codeccapsmask)。 | 
| [bitRate](#bitrate) | 支持的码率范围。 | 
| [port](#port) | 支持的音视频编解码能力。 | 


## **详细描述**

定义Codec编解码能力。


## **类成员变量说明**


### bitRate

  
```
RangeValue CodecCompCapability::bitRate
```

**描述：**

支持的码率范围


### capsMask

  
```
uint32_t CodecCompCapability::capsMask
```

**描述：**

编解码播放能力掩码，详见[CodecCapsMask](_codec.md#codeccapsmask).


### compName

  
```
char CodecCompCapability::compName[NAME_LENGTH]
```

**描述：**

编解码组件名称


### isSoftwareCodec

  
```
bool CodecCompCapability::isSoftwareCodec
```

**描述：**

软件编解码还是硬件编解码


### maxInst

  
```
int32_t CodecCompCapability::maxInst
```

**描述：**

最大实例


### port

  
```
PortCap CodecCompCapability::port
```

**描述：**

支持的音视频编解码能力


### processModeMask

  
```
int32_t CodecCompCapability::processModeMask
```

**描述：**

编解码处理模式掩码，详见[CodecProcessMode](_codec.md#codecprocessmode).


### role

  
```
AvCodecRole CodecCompCapability::role
```

**描述：**

媒体类型


### supportProfiles

  
```
int32_t CodecCompCapability::supportProfiles[PROFILE_NUM]
```

**描述：**

支持的profiles，详见[Profile](_codec.md#profile)


### type

  
```
CodecType CodecCompCapability::type
```

**描述：**

编解码类型
