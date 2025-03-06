# IVideoProcessSession


## 概述

图像处理会话进程。

获取待处理视频，准备需要处理视频，创建流，提交流，释放流，处理视频，删除视频，执行会话中断，会话重启。

**起始版本：** 5.0

**相关模块：**[Camera](_camera_v13.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetPendingVideos](#getpendingvideos) ([out] List&lt; String &gt; videoIds) | 获取未处理的挂起视频的ID。 | 
| [Prepare](#prepare) ([in] String videoId, [in] FileDescriptor fd, [out] [StreamDescription](_stream_description_v13.md)[]streamDescs) | 准备待处理的视频。 | 
| [CreateStreams](#createstreams) ([in] struct StreamInfo_V1_1[] streamInfos) | 创建流。 | 
| [CommitStreams](#commitstreams) ([in] unsigned char[] modeSetting) | 配置流。 | 
| [ReleaseStreams](#releasestreams) ([in] struct StreamInfo_V1_1[] streamInfos) | 释放流。 | 
| [ProcessVideo](#processvideo) ([in] String videoId, [in] unsigned long timestamp) | 按照视频id处理对对应的视频。 | 
| [RemoveVideo](#removevideo) ([in] String videoId) | 通过视频id删除视频。 | 
| [Interrupt](#interrupt) () | 中断会话。 | 
| [Reset](#reset) () | 重启会话。 | 


## 成员函数说明


### CommitStreams()

```
IVideoProcessSession::CommitStreams ([in] unsigned char[] modeSetting)
```

**描述**

配置流。

接口调用必须在调用 [CreateStreams](#createstreams)之后。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| modeSetting | 流的配置信息，报错帧率和zoom信息。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### CreateStreams()

```
IVideoProcessSession::CreateStreams ([in] struct StreamInfo_V1_1[] streamInfos)
```

**描述**

创建流。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| streamInfos | 需要创建流信息列表，详细信息请参阅 **[StreamInfo](_stream_info_v10.md)**。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### GetPendingVideos()

```
IVideoProcessSession::GetPendingVideos ([out] List< String > videoIds)
```

**描述**

获取未处理的挂起视频的ID。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoIds | 待处理视频的ID。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### Interrupt()

```
IVideoProcessSession::Interrupt ()
```

**描述**

中断会话。

**起始版本：** 5.0

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### Prepare()

```
IVideoProcessSession::Prepare ([in] String videoId, [in] FileDescriptor fd, [out] StreamDescription[] streamDescs)
```

**描述**

准备待处理的视频。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoId | 待处理视频的id。 | 
| fd | 待处理视频的fd。 | 
| streamDescs | 返回待处理视频流信息。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### ProcessVideo()

```
IVideoProcessSession::ProcessVideo ([in] String videoId, [in] unsigned long timestamp)
```

**描述**

按照视频id处理对对应的视频。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoId | 需要处理视频的id。 | 
| timestamp | 需要从视频的时间戳开始处理。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### ReleaseStreams()

```
IVideoProcessSession::ReleaseStreams ([in] struct StreamInfo_V1_1[] streamInfos)
```

**描述**

释放流。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| streamInfos | 需要释放流的信息列表。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### RemoveVideo()

```
IVideoProcessSession::RemoveVideo ([in] String videoId)
```

**描述**

通过视频id删除视频。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoId | 需要删除视频id。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。


### Reset()

```
IVideoProcessSession::Reset ()
```

**描述**

重启会话。

**起始版本：** 5.0
