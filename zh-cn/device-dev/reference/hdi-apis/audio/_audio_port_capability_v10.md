# AudioPortCapability


## 概述

音频端口的支持能力。

**起始版本：** 4.0

**相关模块：**[HdiAudio](_hdi_audio_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [deviceType](#devicetype) | 设备输出、输入类型。 | 
| unsigned int [deviceId](#deviceid) | 设备ID，唯一的设备识别符。 | 
| boolean [hardwareMode](#hardwaremode) | 是否支持设备绑定处理。 | 
| unsigned int [formatNum](#formatnum) | 支持的音频格式数目。 | 
| enum [AudioFormat](_hdi_audio_v11.md#audioformat)[] formats | 支持的音频格式，详情参考[AudioFormat](_hdi_audio_v11.md#audioformat)。 | 
| unsigned int sampleRateMasks | 支持的音频采样频率（8k、16k、32k、48k）。 | 
| enum [AudioChannelMask](_hdi_audio_v11.md#audiochannelmask)[channelMasks](#channelmasks) | 设备的声道布局掩码，详情参考[AudioChannelMask](_hdi_audio_v11.md#audiochannelmask)。 | 
| unsigned int [channelCount](#channelcount) | 最大支持的声道总数。 | 
| struct [AudioSubPortCapability](_audio_sub_port_capability_v10.md)[] [subPorts](#subports) | 支持的子端口列表，详情参考[AudioSubPortCapability](_audio_sub_port_capability_v10.md)。 | 


## 类成员变量说明


### channelCount

```
unsigned int AudioPortCapability::channelCount
```

**描述**

最大支持的声道总数。


### channelMasks

```
enum AudioChannelMask AudioPortCapability::channelMasks
```

**描述**

设备的声道布局掩码，详情参考[AudioChannelMask](_hdi_audio_v11.md#audiochannelmask)。


### deviceId

```
unsigned int AudioPortCapability::deviceId
```

**描述**

设备ID，唯一的设备识别符。


### deviceType

```
unsigned int AudioPortCapability::deviceType
```

**描述**

设备输出、输入类型。


### formatNum

```
unsigned int AudioPortCapability::formatNum
```

**描述**

支持的音频格式数目。


### formats

```
enum AudioFormat[] AudioPortCapability::formats
```

**描述**

支持的音频格式，详情参考[AudioFormat](_hdi_audio_v11.md#audioformat)。


### hardwareMode

```
boolean AudioPortCapability::hardwareMode
```

**描述**

是否支持设备绑定处理。


### sampleRateMasks

```
unsigned int AudioPortCapability::sampleRateMasks
```

**描述**

支持的音频采样频率（8k、16k、32k、48k）。


### subPorts

```
struct AudioSubPortCapability [] AudioPortCapability::subPorts
```

**描述**

支持的子端口列表，详情参考[AudioSubPortCapability](_audio_sub_port_capability_v10.md)。
