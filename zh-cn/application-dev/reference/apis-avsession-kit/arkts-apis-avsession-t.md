# Types
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## AVSessionType<sup>10+<sup>

type AVSessionType = 'audio' | 'video' | 'voice_call' | 'video_call'

当前会话支持的会话类型。

该类型可取的值为下表字符串。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 类型  | 说明 |
| -----  | ---- |
| 'audio' | 音频 |
| 'video' | 视频 |
| 'voice_call'<sup>11+<sup> | 音频通话。 |
| 'video_call'<sup>12+<sup> | 视频通话。 |

## AVCastControlCommandType<sup>10+</sup>

type AVCastControlCommandType = 'play' | 'pause' | 'stop' | 'playNext' | 'playPrevious' | 'fastForward' | 'rewind' |
  'seek' | 'setVolume' | 'setSpeed' | 'setLoopMode' | 'toggleFavorite' | 'toggleMute'

投播控制器可传递的命令。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 类型             | 说明         |
| ---------------- | ------------ |
| 'play'           | 播放。无需传入参数。 |
| 'pause'          | 暂停。无需传入参数。   |
| 'stop'           | 停止。无需传入参数。         |
| 'playNext'       | 下一首。无需传入参数。       |
| 'playPrevious'   | 上一首。无需传入参数。       |
| 'fastForward'    | 快进。无需传入参数。       |
| 'rewind'         | 快退。无需传入参数。        |
| 'seek'           | 跳转某一节点。对应参数使用number类型。 |
| 'setVolume'      | 设置音量。对应参数使用number类型, 可通过[AVPlaybackState.maxVolume](arkts-apis-avsession-i.md#avplaybackstate10)获取系统最大音量     |
| 'setSpeed'       | 设置播放倍速。对应参数使用[media.PlaybackSpeed](../apis-media-kit/arkts-apis-media-e.md#playbackspeed8)。 |
| 'setLoopMode'    | 设置循环模式。对应参数使用[LoopMode](arkts-apis-avsession-e.md#loopmode10)。 |
| 'toggleFavorite' | 是否收藏。对应参数使用[AVMetadata.assetId](arkts-apis-avsession-i.md#avmetadata10)。    |
| 'toggleMute'     | 设置静音状态。无需传入参数。 |

## ExtraInfo<sup>18+</sup>

type ExtraInfo = { [key: string]: Object; }

媒体提供方设置的自定义媒体数据包对象。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| [key: string]: Object   | key为远端分布式事件类型。当前支持的事件类型包括：<br>'AUDIO_GET_VOLUME'：获取远端设备音量。<br>'AUDIO_GET_AVAILABLE_DEVICES'：获取远端所有可连接设备。<br>'AUDIO_GET_PREFERRED_OUTPUT_DEVICE_FOR_RENDERER_INFO'：获取远端实际发声设备。<br>媒体提供方根据不同的远端分布式事件类型，返回对应的媒体数据包Object对象。 |

## KeyRequestCallback<sup>12+</sup>

type KeyRequestCallback = (assetId: string, requestData: Uint8Array) => void

许可证请求事件的回调函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| assetId     | string  | 是   | 媒体ID。 |
| requestData |  Uint8Array  | 是   | 媒体许可证请求数据。                            |

**示例：**
<!--code_no_check-->
```ts
let keyRequestCallback: avSession.KeyRequestCallback = async(assetId: string, requestData: Uint8Array) => {
  console.info(`Succeeded in keyRequestCallback. assetId: ${assetId}, requestData: ${requestData}`);
}
```

## AVControlCommandType<sup>10+</sup>

type AVControlCommandType = 'play' | 'pause' | 'stop' | 'playNext' | 'playPrevious' | 'fastForward' | 'rewind' |
  'seek' | 'setSpeed' | 'setLoopMode' | 'toggleFavorite' | 'playFromAssetId' | 'playWithAssetId' | 'answer' | 'hangUp' | 'toggleCallMute' | 'setTargetLoopMode'

会话可传递的命令。

该类型可取的值为下表字符串的并集。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 类型             | 说明         |
| ---------------- | ------------ |
| 'play'           | 播放。无需传入参数。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| 'pause'          | 暂停。无需传入参数。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| 'stop'           | 停止。 无需传入参数。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| 'playNext'       | 下一首。无需传入参数。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| 'playPrevious'   | 上一首。无需传入参数。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| 'fastForward'    | 快进。无需传入参数。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| 'rewind'         | 快退。无需传入参数。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| 'seek'           | 跳转某一节点。对应参数使用number类型。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| 'setSpeed'       | 设置播放倍速。对应参数使用number类型。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| 'setLoopMode'    | 设置循环模式。对应参数使用[LoopMode](arkts-apis-avsession-e.md#loopmode10)。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| 'setTargetLoopMode' <sup>18+</sup>   | 设置目标循环模式。对应参数推荐使用[LoopMode](arkts-apis-avsession-e.md#loopmode10)。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。  |
| 'toggleFavorite' | 是否收藏。对应参数使用[AVMetadata.assetId](arkts-apis-avsession-i.md#avmetadata10)。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。    |
| 'playFromAssetId' <sup>11+</sup>| 播放指定的assetId。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| 'playWithAssetId' <sup>20+</sup>    | 播放指定的assetId。对应参数使用[AVMetadata.assetId](arkts-apis-avsession-i.md#avmetadata10)，<br>字符串长度<40960字节。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|
|'answer' <sup>11+</sup>        | 接听。无需传入参数。  <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。      |
| 'hangUp' <sup>11+</sup>         | 挂断。无需传入参数。  <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。      |
|'toggleCallMute' <sup>11+</sup>  | 设置通话静音状态。无需传入参数。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
