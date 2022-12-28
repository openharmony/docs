# AudioPortCap


## **概述**

定义音频编解码能力。

**所属模块:**

[Codec](codec.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [sampleFormats](#sampleformats)&nbsp;[SAMPLE_FMT_NUM] | 支持的音频采样格式，详见[AudioSampleFormat](codec.md#audiosampleformat)。 | 
| [sampleRate](#samplerate)&nbsp;[SAMPLE_RATE_NUM] | 支持的音频采样率，详见[AudioSampleRate](codec.md#audiosamplerate)。 | 
| [channelLayouts](#channellayouts)&nbsp;[CHANNEL_NUM] | 支持的音频通道数channel&nbsp;layouts。 | 
| [channelCount](#channelcount)&nbsp;[CHANNEL_NUM] | 支持的音频通道数。 | 


## **详细描述**

定义音频编解码能力。


## **类成员变量说明**


### channelCount

  
```
int32_t AudioPortCap::channelCount[CHANNEL_NUM]
```

**描述：**

支持的音频通道数


### channelLayouts

  
```
int32_t AudioPortCap::channelLayouts[CHANNEL_NUM]
```

**描述：**

支持的音频通道数channel layouts


### sampleFormats

  
```
int32_t AudioPortCap::sampleFormats[SAMPLE_FMT_NUM]
```

**描述：**

支持的音频采样格式，详见[AudioSampleFormat](codec.md#audiosampleformat)


### sampleRate

  
```
int32_t AudioPortCap::sampleRate[SAMPLE_RATE_NUM]
```

**描述：**

支持的音频采样率，详见[AudioSampleRate](codec.md#audiosamplerate)
