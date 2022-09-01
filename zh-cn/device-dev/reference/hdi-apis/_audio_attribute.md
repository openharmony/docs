# AudioAttribute


## **概述**

**所属模块:**

[Audio](_audio.md)


## **汇总**


### Public 属性

| Public&nbsp;属性 | 描述 |
| -------- | -------- |
| (&nbsp;[GetFrameSize](#getframesize)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;uint64_t&nbsp;\*size) | 获取音频帧（frame）的大小&nbsp;[更多...](#getframesize) |
| (&nbsp;[GetFrameCount](#getframecount)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;uint64_t&nbsp;\*count) | 获取音频buffer中的音频帧数&nbsp;[更多...](#getframecount) |
| (&nbsp;[SetSampleAttributes](#setsampleattributes)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;const&nbsp;struct&nbsp;[AudioSampleAttributes](_audio_sample_attributes.md)&nbsp;\*attrs) | 设置音频采样的属性参数&nbsp;[更多...](#setsampleattributes) |
| (&nbsp;[GetSampleAttributes](#getsampleattributes)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;struct&nbsp;[AudioSampleAttributes](_audio_sample_attributes.md)&nbsp;\*attrs) | 获取音频采样的属性参数&nbsp;[更多...](#getsampleattributes) |
| (&nbsp;[GetCurrentChannelId](#getcurrentchannelid)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;uint32_t&nbsp;\*channelId) | 获取音频的数据通道ID&nbsp;[更多...](#getcurrentchannelid) |
| (&nbsp;[SetExtraParams](#setextraparams)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;const&nbsp;char&nbsp;\*keyValueList) | 设置音频拓展参数&nbsp;[更多...](#setextraparams) |
| (&nbsp;[GetExtraParams](#getextraparams)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;char&nbsp;\*keyValueList) | 获取音频拓展参数&nbsp;[更多...](#getextraparams) |
| (&nbsp;[ReqMmapBuffer](#reqmmapbuffer)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;int32_t&nbsp;reqSize,&nbsp;struct&nbsp;[AudioMmapBufferDescripter](_audio_mmap_buffer_descripter.md)&nbsp;\*desc) | 请求mmap缓冲区&nbsp;[更多...](#reqmmapbuffer) |
| (&nbsp;[GetMmapPosition](#getmmapposition)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;uint64_t&nbsp;\*frames,&nbsp;struct&nbsp;[AudioTimeStamp](_audio_time_stamp.md)&nbsp;\*time) | 获取当前mmap的读/写位置&nbsp;[更多...](#getmmapposition) |
| (&nbsp;[AddAudioEffect](#addaudioeffect)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;uint64_t&nbsp;\*effectid) |添加音频效果算法实例&nbsp;[更多...](#addaudioeffect) |
| (&nbsp;[RemoveAudioEffect](#removeaudioeffect)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;uint64_t&nbsp;effectid) |移除音频效果算法实例&nbsp;[更多...](#removeaudioeffect) |
| (&nbsp;[GetFrameBufferSize](#getframebuffersize)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;uint64_t&nbsp;\*effectid) |获取播放或录音的缓冲区大小&nbsp;[更多...](#getframebuffersize) |


## **详细描述**

AudioAttribute音频属性接口

提供音频播放（render）或录音（capture）需要的公共属性驱动能力，包括获取帧（frame）信息、设置采样属性等。

**Since：**

1.0

**Version：**

1.0


## **类成员变量说明**


### GetCurrentChannelId


```
int32_t(* AudioAttribute::GetCurrentChannelId) (AudioHandle handle, uint32_t *channelId)
```

**描述：**

获取音频的数据通道ID

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| handle | 待操作的音频句柄 |
| channelId | 获取的通道ID保存到channelId中 |

**返回：**

成功返回值0，失败返回负值。


### GetExtraParams


```
int32_t(* AudioAttribute::GetExtraParams) (AudioHandle handle, char *keyValueList)
```

**描述：**

获取音频拓展参数。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| handle | 待操作的音频句柄 |
| keyValueList | 拓展参数键值对字符串列表，格式为key=value，多个键值对通过分号分割 |

**返回：**

成功返回值0，失败返回负值。


### GetFrameCount


```
int32_t(* AudioAttribute::GetFrameCount) (AudioHandle handle, uint64_t *count)
```

**描述：**

获取音频buffer中的音频帧数。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| handle | 待操作的音频句柄 |
| count | 一个音频buffer中包含的音频帧数，获取后保存到count中 |

**返回：**

成功返回值0，失败返回负值。


### GetFrameSize


```
int32_t(* AudioAttribute::GetFrameSize) (AudioHandle handle, uint64_t *size)
```

**描述：**

获取音频帧（frame）的大小

获取一帧音频数据的长度（字节数）

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| handle | 待操作的音频句柄 |
| size | 获取的音频帧大小（字节数）保存到size中 |

**返回：**

成功返回值0，失败返回负值。


### GetMmapPosition


```
int32_t(* AudioAttribute::GetMmapPosition) (AudioHandle handle, uint64_t *frames, struct AudioTimeStamp *time)
```

**描述：**

获取当前mmap的读/写位置

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| handle | 待操作的音频句柄 |
| frames | 获取的音频帧计数保存到frames中 |
| time | 获取的关联时间戳保存到time中 |

**返回：**

成功返回值0，失败返回负值。


### GetSampleAttributes


```
int32_t(* AudioAttribute::GetSampleAttributes) (AudioHandle handle, struct AudioSampleAttributes *attrs)
```

**描述：**

获取音频采样的属性参数。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| handle | 待操作的音频句柄 |
| attrs | 获取的音频采样属性（例如采样频率、采样精度、通道）保存到attrs中 |

**返回：**

成功返回值0，失败返回负值。

**参见：**

[SetSampleAttributes](#setsampleattributes)


### ReqMmapBuffer


```
int32_t(* AudioAttribute::ReqMmapBuffer) (AudioHandle handle, int32_t reqSize, struct AudioMmapBufferDescripter *desc)
```

**描述：**

请求mmap缓冲区

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| handle | 待操作的音频句柄 |
| reqSize | 请求缓冲区的大小 |
| desc | 缓冲区描述符 |

**返回：**

成功返回值0，失败返回负值。


### SetExtraParams


```
int32_t(* AudioAttribute::SetExtraParams) (AudioHandle handle, const char *keyValueList)
```

**描述：**

设置音频拓展参数。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| handle | 待操作的音频句柄 |
| keyValueList | 拓展参数键值对字符串列表，格式为key=value，多个键值对通过分号分割 |

**返回：**

成功返回值0，失败返回负值。


### SetSampleAttributes


```
int32_t(* AudioAttribute::SetSampleAttributes) (AudioHandle handle, const struct AudioSampleAttributes *attrs)
```

**描述：**

设置音频采样的属性参数。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| handle | 待操作的音频句柄 |
| attrs | 待设置的音频采样属性，例如采样频率、采样精度、通道 |

**返回：**

成功返回值0，失败返回负值。

**参见：**

[GetSampleAttributes](#getsampleattributes)


### AddAudioEffect


```
int32_t (* AudioAttribute::AddAudioEffect)(AudioHandle handle, uint64_t effectid)
```

**描述：**

添加音频效果算法实例。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| handle | 待操作的音频句柄 |
| effectid | 待添加的音频效果算法实例ID |

**返回：**

成功返回值0，失败返回负值。


### RemoveAudioEffect


```
int32_t (* AudioAttribute::RemoveAudioEffect)(AudioHandle handle, uint64_t effectid)
```

**描述：**

移除音频效果算法实例。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| handle | 待操作的音频句柄 |
| effectid | 待移除的音频效果算法实例ID |

**返回：**

成功返回值0，失败返回负值。


### GetFrameBufferSize


```
int32_t (* AudioAttribute::GetFrameBufferSize)(AudioHandle handle, uint64_t *bufferSize)
```

**描述：**

获取播放或录音的缓冲区大小。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| handle | 待操作的音频句柄 |
| bufferSize | 获取的缓冲区大小保存到bufferSize中 |

**返回：**

成功返回值0，失败返回负值。
