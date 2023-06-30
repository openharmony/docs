# AudioPortCapability


## 概述

音频端口的支持能力。

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
| [deviceType](#devicetype) | unsigned&nbsp;int<br/>设备输出、输入类型。 | 
| [deviceId](#deviceid) | unsigned&nbsp;int<br/>设备ID，唯一的设备识别符。 | 
| [hardwareMode](#hardwaremode) | boolean<br/>是否支持设备绑定处理。 | 
| [formatNum](#formatnum) | unsigned&nbsp;int<br/>支持的音频格式数目。 | 
| [channelMasks](#channelmasks) | enum&nbsp;[AudioFormat](_audio.md#audioformat)[]&nbsp;formats&nbsp;unsigned&nbsp;int&nbsp;sampleRateMasks&nbsp;enum&nbsp;[AudioChannelMask](_audio.md#audiochannelmask)<br/>支持的音频格式，详情参考[AudioFormat](_audio.md#audioformat)。 | 
| [channelCount](#channelcount) | unsigned&nbsp;int<br/>最大支持的声道总数。 | 
| [subPorts](#subports) | struct&nbsp;[AudioSubPortCapability](_audio_sub_port_capability.md)[]<br/>支持的子端口列表，详情参考[AudioSubPortCapability](_audio_sub_port_capability.md)。 | 


## 类成员变量说明


### channelCount

  
```
unsigned int AudioPortCapability::channelCount
```

**描述:**

最大支持的声道总数。


### channelMasks

  
```
enum AudioFormat [] formats unsigned int sampleRateMasks enum AudioChannelMask AudioPortCapability::channelMasks
```

**描述:**

支持的音频格式，详情参考[AudioFormat](_audio.md#audioformat)。

支持的音频采样频率（8k、16k、32k、48k）。 设备的声道布局掩码，详情参考[AudioChannelMask](_audio.md#audiochannelmask)。


### deviceId

  
```
unsigned int AudioPortCapability::deviceId
```

**描述:**

设备ID，唯一的设备识别符。


### deviceType

  
```
unsigned int AudioPortCapability::deviceType
```

**描述:**

设备输出、输入类型。


### formatNum

  
```
unsigned int AudioPortCapability::formatNum
```

**描述:**

支持的音频格式数目。


### hardwareMode

  
```
boolean AudioPortCapability::hardwareMode
```

**描述:**

是否支持设备绑定处理。


### subPorts

  
```
struct AudioSubPortCapability [] AudioPortCapability::subPorts
```

**描述:**

支持的子端口列表，详情参考[AudioSubPortCapability](_audio_sub_port_capability.md)。
