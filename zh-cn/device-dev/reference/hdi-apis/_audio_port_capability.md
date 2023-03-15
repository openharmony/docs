# AudioPortCapability


## **概述**

音频端口的支持能力。

**相关模块:**

[Audio](_audio.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [deviceType](_audio.md#devicetype) | 设备输出、输入类型。 | 
| [deviceId](_audio.md#deviceid) | 绑定（bind）设备ID，唯一的设备识别符。 | 
| [hardwareMode](_audio.md#hardwaremode) | 是否支持设备绑定处理。 | 
| [formatNum](_audio.md#formatnum) | 支持的音频格式数目。 | 
| [formats](_audio.md#formats) | 支持的音频格式。 | 
| [sampleRateMasks](_audio.md#sampleratemasks) | 支持的音频采样频率（8k、16k、32k、48k）。 | 
| [channelMasks](_audio.md#channelmasks) | 设备的声道布局掩码（mask）。 | 
| [channelCount](_audio.md#channelcount-22) | 支持的最大声道总数。 | 
| [subPortsNum](_audio.md#subportsnum) | 支持的子端口数目（仅用于输出设备）。 | 
| [subPorts](_audio.md#subports) | 支持的子端口列表。 | 
| [supportSampleFormatNum](_audio.md#supportsampleformatnum) | 支持的音频样本格式数量。 | 
| [supportSampleFormats](_audio.md#supportsampleformats) | 支持的音频样本格式。 | 
