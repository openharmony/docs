# AudioAttribute


## **概述**

AudioAttribute音频属性接口。

提供音频播放（Render）或录音（Capture）需要的公共属性驱动能力，包括获取帧（frame）信息、设置采样属性等。

**Since:**

1.0

**Version:**

1.0

**相关模块:**

[Audio](_audio.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| ([GetFrameSize](#getframesize))(AudioHandle&nbsp;handle,&nbsp;uint64_t&nbsp;\*size) | 获取音频帧（frame）的大小 | 
| ([GetFrameCount](#getframecount))(AudioHandle&nbsp;handle,&nbsp;uint64_t&nbsp;\*count) | 获取音频buffer中的音频帧数 | 
| ([SetSampleAttributes](#setsampleattributes))(AudioHandle&nbsp;handle,&nbsp;const&nbsp;struct&nbsp;AudioSampleAttributes&nbsp;\*attrs) | 设置音频采样的属性参数 | 
| ([GetSampleAttributes](#getsampleattributes))(AudioHandle&nbsp;handle,&nbsp;struct&nbsp;AudioSampleAttributes&nbsp;\*attrs) | 获取音频采样的属性参数 | 
| ([GetCurrentChannelId](#getcurrentchannelid))(AudioHandle&nbsp;handle,&nbsp;uint32_t&nbsp;\*channelId) | 获取音频的数据通道ID | 
| ([SetExtraParams](#setextraparams))(AudioHandle&nbsp;handle,&nbsp;const&nbsp;char&nbsp;\*keyValueList) | 设置音频拓展参数 | 
| ([GetExtraParams](#getextraparams))(AudioHandle&nbsp;handle,&nbsp;char&nbsp;\*keyValueList) | 获取音频拓展参数 | 
| ([ReqMmapBuffer](#reqmmapbuffer))(AudioHandle&nbsp;handle,&nbsp;int32_t&nbsp;reqSize,&nbsp;struct&nbsp;AudioMmapBufferDescriptor&nbsp;\*desc) | 请求Mmap缓冲区 | 
| ([GetMmapPosition](#getmmapposition))(AudioHandle&nbsp;handle,&nbsp;uint64_t&nbsp;\*frames,&nbsp;struct&nbsp;AudioTimeStamp&nbsp;\*time) | 获取当前Mmap的读/写位置 | 
| ([AddAudioEffect](#addaudioeffect))(AudioHandle&nbsp;handle,&nbsp;uint64_t&nbsp;effectid) | 添加音频效果算法实例 | 
| ([RemoveAudioEffect](#removeaudioeffect))(AudioHandle&nbsp;handle,&nbsp;uint64_t&nbsp;effectid) | 移除音频效果算法实例 | 
| ([GetFrameBufferSize](#getframebuffersize))(AudioHandle&nbsp;handle,&nbsp;uint64_t&nbsp;\*bufferSize) | 获取播放或录音的缓冲区大小 | 


## **类成员变量说明**


### AddAudioEffect

  
```
int32_t (*AudioAttribute::AddAudioEffect)(AudioHandle handle, uint64_t effectid)
```

**描述：**

添加音频效果算法实例。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| effectid | 输入参数，待添加的音频效果算法实例ID。 | 

**返回:**

成功返回值0，失败返回负值。


### GetCurrentChannelId

  
```
int32_t(* AudioAttribute::GetCurrentChannelId) (AudioHandle handle, uint32_t *channelId)
```

**描述：**

获取音频的数据通道ID。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| channelId | 输出参数，获取的通道ID保存到channelId中。 | 

**返回:**

成功返回值0，失败返回负值。


### GetExtraParams

  
```
int32_t(* AudioAttribute::GetExtraParams) (AudioHandle handle, char *keyValueList)
```

**描述：**

获取音频拓展参数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| keyValueList | 输出参数，拓展参数键值对字符串列表，格式为key=value，多个键值对通过分号分割。 | 

**返回:**

成功返回值0，失败返回负值。


### GetFrameBufferSize

  
```
int32_t (*AudioAttribute::GetFrameBufferSize)(AudioHandle handle, uint64_t *bufferSize)
```

**描述：**

获取播放或录音的缓冲区大小。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| bufferSize | 输出参数，获取的缓冲区大小保存到bufferSize中。 | 

**返回:**

成功返回值0，失败返回负值。


### GetFrameCount

  
```
int32_t(* AudioAttribute::GetFrameCount) (AudioHandle handle, uint64_t *count)
```

**描述：**

获取音频buffer中的音频帧数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| count | 输出参数，一个音频buffer中包含的音频帧数，获取后保存到count中。 | 

**返回:**

成功返回值0，失败返回负值。


### GetFrameSize

  
```
int32_t(* AudioAttribute::GetFrameSize) (AudioHandle handle, uint64_t *size)
```

**描述：**

获取音频帧（frame）的大小，即一帧音频数据的长度（字节数）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| size | 输出参数，获取的音频帧大小（字节数）保存到size中。 | 

**返回:**

成功返回值0，失败返回负值。


### GetMmapPosition

  
```
int32_t(* AudioAttribute::GetMmapPosition) (AudioHandle handle, uint64_t *frames, struct AudioTimeStamp *time)
```

**描述：**

获取当前Mmap的读/写位置。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| frames | 输出参数，获取的音频帧计数保存到frames中。 | 
| time | 输出参数，获取的关联时间戳保存到time中。 | 

**返回:**

成功返回值0，失败返回负值。


### GetSampleAttributes

  
```
int32_t(* AudioAttribute::GetSampleAttributes) (AudioHandle handle, struct AudioSampleAttributes *attrs)
```

**描述：**

获取音频采样的属性参数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| attrs | 输出参数，获取的音频采样属性（例如采样频率、采样精度、通道）保存到attrs中。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetSampleAttributes](#getsampleattributes)


### RemoveAudioEffect

  
```
int32_t (*AudioAttribute::RemoveAudioEffect)(AudioHandle handle, uint64_t effectid)
```

**描述：**

移除音频效果算法实例。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| effectid | 输入参数，待移除的音频效果算法实例ID。 | 

**返回:**

成功返回值0，失败返回负值。


### ReqMmapBuffer

  
```
int32_t(* AudioAttribute::ReqMmapBuffer) (AudioHandle handle, int32_t reqSize, struct AudioMmapBufferDescriptor *desc)
```

**描述：**

请求Mmap缓冲区。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| reqSize | 输入参数，请求缓冲区的大小。 | 
| desc | 输出参数，缓冲区描述符。 | 

**返回:**

成功返回值0，失败返回负值。


### SetExtraParams

  
```
int32_t(* AudioAttribute::SetExtraParams) (AudioHandle handle, const char *keyValueList)
```

**描述：**

设置音频拓展参数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| keyValueList | 输入参数，拓展参数键值对字符串列表，格式为key=value，多个键值对通过分号分割。 | 

**返回:**

成功返回值0，失败返回负值。


### SetSampleAttributes

  
```
int32_t(* AudioAttribute::SetSampleAttributes) (AudioHandle handle, const struct AudioSampleAttributes *attrs)
```

**描述：**

设置音频采样的属性参数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| attrs | 输入参数，待设置的音频采样属性，例如采样频率、采样精度、通道。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetSampleAttributes](#getsampleattributes)
