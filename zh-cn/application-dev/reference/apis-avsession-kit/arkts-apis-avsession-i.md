# Interfaces (其他)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## AVCastControlCommand<sup>10+</sup>

投播控制器接受的命令的对象描述。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称      | 类型                                              | 只读 | 可选 | 说明           |
| --------- | ------------------------------------------------- | ---- |---- | -------------- |
| command   | [AVCastControlCommandType](arkts-apis-avsession-t.md#avcastcontrolcommandtype10)     |否 | 否  | 命令。每种命令对应的参数不同，具体的对应关系可查阅[AVCastControlCommandType](arkts-apis-avsession-t.md#avcastcontrolcommandtype10)。 |
| parameter | [media.PlaybackSpeed](../apis-media-kit/arkts-apis-media-e.md#playbackspeed8) &#124; number &#124; string &#124; [LoopMode](arkts-apis-avsession-e.md#loopmode10) | 否 | 是   | 命令对应的参数。 |

## CastDisplayInfo<sup>12+</sup>

扩展屏投播显示设备相关属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

| 名称            | 类型                      | 只读 | 可选 | 说明               |
| --------------- |-------------------------| ---- | ---- |---------------------------------------------------------------------|
| id            | number                  | 否    | 否    | 投播显示设备的ID，该参数应为整数。  |
| name     | string                  | 否    | 否    | 投播显示设备的名称。           |
| state          | [CastDisplayState](arkts-apis-avsession-e.md#castdisplaystate12)          | 否    | 否    |投播显示设备状态。            |
| width          | number          | 否    | 否    | 投播显示设备的屏幕宽度，单位为px，该参数应为整数。          |  
| height          | number          | 否    | 否    | 投播显示设备的屏幕高度，单位为px，该参数应为整数。            |  

## AVMetadata<sup>10+</sup>

媒体元数据的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称            | 类型                      | 只读 | 可选 | 说明               |
| --------------- |-------------------------| ---- | ---- |---------------------------------------------------------------------|
| assetId         | string                  | 否   | 否   | 媒体ID。媒体信息的唯一标识，由应用自定义。<br>- 该属性发生变化则其他元数据属性都将被刷新。<br>- 若该属性维持不变，且不设置相应的媒体元数据信息，那么将不会更新对应的媒体元数据信息。<br>- 当该属性设为空值时，调用[setAVMetadata](../apis-avsession-kit/arkts-apis-avsession-AVSession.md#setavmetadata10)方法将失败，返回错误码6600101。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                     |
| title           | string                  | 否   | 是   | 标题。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。              |
| artist          | string                  | 否   | 是   | 艺术家。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。             |
| author          | string                  | 否   | 是   | 专辑作者。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。            |
| avQueueName<sup>12+</sup>       | string                  | 否   | 是   | 歌单（歌曲列表）名称。            |
| avQueueId<sup>11+</sup>       | string                  | 否   | 是   | 歌单（歌曲列表）唯一标识Id。            |
| avQueueImage<sup>11+</sup>    | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) &#124; string | 否   | 是   | 歌单（歌曲列表）封面图。<br>图片的像素数据或者图片路径地址（本地路径或网络路径）。应用通过setAVMetadata设置图片数据。<br>- 设置的数据类型为PixelMap时，通过getAVMetadata获取的将为PixelMap。<br>- 设置为url图片路径，获取的为url图片路径。  |
| album           | string                  | 否   | 是   | 专辑名称。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。            |
| writer          | string                  | 否   | 是   | 词作者。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。             |
| composer        | string                  | 否   | 是   | 作曲者。             |
| duration        | number                  | 否   | 是   | 媒体时长，单位毫秒（ms）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                  |
| mediaImage      | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) &#124; string | 否   | 是   | 图片的像素数据或者图片路径地址（本地路径或网络路径）。应用通过setAVMetadata设置图片数据。<br>- 设置的数据类型为PixelMap时，通过getAVMetadata获取的将为PixelMap。<br>- 设置为url图片路径，获取的为url图片路径。  <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                             |
| bundleIcon<sup>18+</sup>      | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 是   | 是   | 应用图标图片的像素数据。只读类型，不从应用侧设置。|
| publishDate     | Date                    | 否   | 是   | 发行日期。          |
| subtitle        | string                  | 否   | 是   | 子标题。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。             |
| description     | string                  | 否   | 是   | 媒体描述。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。            |
| lyric           | string                  | 否   | 是   | 媒体歌词内容。应用需将歌词内容拼接为一个字符串传入。<br>字符串长度需小于40960字节。<br>**说明：** 系统支持简单版的LRC格式（Simple LRC format）的歌词文本内容。当传入的歌词内容不规范（例如：出现重复的时间戳等），将导致解析失败，并在系统中显示异常。 |
| singleLyricText<sup>17+</sup> | string    | 否   | 是   | 单条媒体歌词内容。应用需将歌词内容拼接为一个字符串传入（不包含时间戳）。<br>字符串长度小于40960字节。<br>**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。|
| previousAssetId | string                  | 否   | 是   | 上一首媒体ID。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| nextAssetId     | string                  | 否   | 是   | 下一首媒体ID。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| filter<sup>11+</sup>        | number         | 否   | 是   | 当前会话支持的协议，默认为TYPE_CAST_PLUS_STREAM。具体取值参考[ProtocolType](arkts-apis-avsession-e.md#protocoltype11)。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                   |
| drmSchemes<sup>12+</sup>        | Array\<string>         | 否   | 是   | 当前session支持的DRM方案，取值为DRM方案uuid。|
| skipIntervals<sup>11+</sup>  | [SkipIntervals](arkts-apis-avsession-e.md#skipintervals11)        | 否   | 是   | 快进快退支持的时间间隔。默认为SECONDS_15，即15秒。                            |
|displayTags<sup>11+</sup>     | number                           | 否   | 是   | 媒体资源的金标类型，取值参考[DisplayTag](arkts-apis-avsession-e.md#displaytag11)。      |
| rewindSkipIntervals | [SkipIntervals](arkts-apis-avsession-e.md#skipintervals11)        | 否   | 是   | 快退支持的时间间隔。默认为SECONDS_15，即15秒。<br>系统会使用此值作为快退操作的时间间隔，而非skipIntervals的值。<br>若未设置此参数，快退操作的时间间隔仍会沿用skipIntervals的值。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**起始版本**：26.0.0|
| fastForwardSkipIntervals</sup> | [SkipIntervals](arkts-apis-avsession-e.md#skipintervals11)        | 否   | 是   | 快进支持的时间间隔。默认为SECONDS_15，即15秒。<br>系统会使用此值作为快进操作的时间间隔，而非skipIntervals的值。<br>若未设置此参数，快进操作的时间间隔仍会沿用skipIntervals的值。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**起始版本**：26.0.0|

## AVMediaDescription<sup>10+</sup>

播放列表媒体元数据的相关属性。

| 名称         | 类型                    | 只读  | 可选  | 说明                     |
| ------------ | ----------------------- | ---- | ---- | ----------------------- |
| assetId      | string                  | 否   | 否   | 播放列表媒体ID。媒体信息的唯一标识，由应用自定义。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| title        | string                  | 否   | 是   | 播放列表媒体标题。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| subtitle     | string                  | 否   | 是   | 播放列表媒体子标题。<br>在使用了cast+协议的音频投播场景下，不支持使用该属性。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| description  | string                  | 否   | 是   | 播放列表媒体描述的文本。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| mediaImage | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) \| string  | 否   | 是   | 设置播放列表媒体图片像素数据。<br>在使用了cast+协议的音视频投播场景下，该字段用于给对端设备设置媒体专辑封面。<br>当入参为string类型时：<br>- 只支持使用网络URI设置封面，不支持本地URI。<br>- 其作用与albumCoverUri属性功能相同，且优先级高于albumCoverUri。<br>从API version 23开始，支持入参为image.PixelMap类型给对端设备设置媒体信息。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| extras       |  {[key: string]: Object}    | 否   | 是   | 播放列表媒体额外字段。<br>从API版本26.0.0开始，DLNA投播场景下支持将[ExtraKey](arkts-apis-avsession-e.md#extrakey)中DLNA_CURRENT_URI_METADATA和DLNA_DIDL_LITE两个键的值传递给对端设备，键值对的值需传入符合XML格式的字符串。如传入入参`{[avSession.ExtraKey.DLNA_CURRENT_URI_METADATA]: '<xxtv>...</xxtv>'}`。<br>- 非DLNA投播场景不生效。<br>- 非字符串类型不生效。<br>- 非XML格式会触发[on('castControlIoError')](arkts-apis-avsession-AVCastController.md#oncastcontrolioerror13)回调并返回错误码6612000。错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。<br>- 通过extras字段，在[ExtraKey](arkts-apis-avsession-e.md#extrakey)中通过DLNA_CURRENT_URI_METADATA和DLNA_DIDL_LITE键传入的字符串总长度需小于40960字节。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| mediaUri     | string                  | 否   | 是   | 播放列表媒体URI。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| mediaType     | string                  | 否   | 是   | 播放列表媒体类型。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| mediaSize     | number                  | 否   | 是   | 播放列表媒体的大小。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| albumTitle     | string                  | 否   | 是   | 播放列表媒体专辑标题。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| albumCoverUri     | string                  | 否   | 是   | 播放列表媒体专辑封面URI。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| lyricContent     | string                  | 否   | 是   | 播放列表媒体歌词内容。<br>字符串长度需小于40960字节。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| lyricUri     | string                  | 否   | 是   | 播放列表媒体歌词URI。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| artist     | string                  | 否   | 是   | 播放列表媒体专辑作者。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| fdSrc     | [media.AVFileDescriptor](../apis-media-kit/arkts-apis-media-i.md#avfiledescriptor9) | 否   | 是   | 播放列表媒体本地文件的句柄。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| dataSrc<sup>12+</sup>     | [media.AVDataSrcDescriptor](../apis-media-kit/arkts-apis-media-i.md#avdatasrcdescriptor10)         | 否   | 是   | 播放列表数据源描述。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| pcmSrc<sup>20+</sup>     | boolean        | 否   | 是   | 播放列表是否使用PCM数据源。true表示使用PCM数据源，false表示不使用PCM数据源。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| drmScheme<sup>12+</sup>     | string        | 否   | 是   | 播放列表媒体支持的DRM方案，由uuid表示。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| duration     | number                  | 否   | 是   | 播放列表媒体播放时长。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| startPosition     | number                  | 否   | 是   | 播放列表媒体起始播放位置。音视频投播场景中，在投播直播资源时，此字段应置空或赋值为0。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| creditsPosition     | number                  | 否   | 是   | 播放列表媒体的片尾播放位置。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| appName     | string                  | 否   | 是   | 播放列表提供的应用的名字。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
|displayTags<sup>11+</sup>     | number | 否   | 是   | 媒体资源的金标类型，取值参考[DisplayTag](arkts-apis-avsession-e.md#displaytag11)。<br>在使用了cast+协议的音频投播场景下，不支持使用该属性。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
|launchClientData<sup>20+</sup> | string | 否 | 是 | 投播过程中应用程序向接收方发送的自定义数据。<br/>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast  <br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## AVQueueItem<sup>10+</sup>

播放列表中单项的相关属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称         | 类型                                        | 只读 | 可选 | 说明                        |
| ------------ | ------------------------------------------ | ---- | --- |--------------------------- |
| itemId       | number                                     |  否 | 否 | 播放列表中单项的ID。          |
| description  | [AVMediaDescription](#avmediadescription10)  | 否   | 是 | 播放列表中单项的媒体元数据。   |

## AVPlaybackState<sup>10+</sup>

媒体播放状态的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称         | 类型                                  | 只读 | 可选 | 说明     |
| ------------ | ------------------------------------- | ---- | ---- | ------- |
| state        | [PlaybackState](arkts-apis-avsession-e.md#playbackstate10)       | 否 | 是  | 播放状态。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| speed        | number                                | 否 |是   | 播放倍速。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| position     | [PlaybackPosition](#playbackposition10) | 否 | 是   | 播放位置。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| bufferedTime | number                                | 否  | 是  | 缓冲时间。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| loopMode     | [LoopMode](arkts-apis-avsession-e.md#loopmode10)                 | 否  | 是 | 循环模式。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| isFavorite   | boolean                               | 否 | 是  | 表示是否收藏。true表示收藏，false表示不收藏。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| activeItemId | number                  | 否 |  是 | 正在播放的媒体ID。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| volume | number                  | 否  |  是  | 正在播放的媒体音量。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| maxVolume<sup>11+</sup> | number                    | 否  | 是 | 最大音量。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| muted<sup>11+</sup>     | boolean                   | 否  | 是 | 当前是否是静音状态。true表示是，false表示不是。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| duration<sup>11+</sup>     | number                   | 否 | 是  | 当前媒体资源的时长，单位为毫秒（ms）。 |
| videoWidth<sup>11+</sup>  | number                  | 否   | 是 | 媒体资源的视频宽度，单位为像素（px）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| videoHeight<sup>11+</sup> |  number                 | 否  |是  | 媒体资源的视频高度，单位为像素（px）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| extras | {[key: string]: Object}     | 否  | 是 | 自定义媒体数据。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## PlaybackPosition<sup>10+</sup>

媒体播放位置的相关属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称        | 类型   | 只读 | 可选 | 说明               |
| ----------- | ------ | ---- |---- | ------------------ |
| elapsedTime | number | 否 | 否   | 已用时间，单位毫秒（ms）。 |
| updateTime  | number | 否 | 否   | 更新时间，单位毫秒（ms）。 |

## CallMetadata<sup>11+</sup>

通话会话元数据相关属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称            | 类型                      |只读 | 可选 | 说明               |
| --------------- |-------------------------| ---- | ---- |---------------------------------------------------------------------|
| name            | string                  | 否  | 是   | 来电人姓名（别名）。    |
| phoneNumber     | string                  | 否  | 是  | 来电电话号码。            |
| avatar          | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)          | 否 |是   | 来电人头像。            |

## AVCallState<sup>11+</sup>

通话状态相关属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称            | 类型                      |只读 | 可选 | 说明               |
| --------------- |-------------------------  | ---- | ---- |---------------------------------------------------------------------|
| state           | [CallState](arkts-apis-avsession-e.md#callstate11)                 | 否 | 否    | 当前通话状态。      |
| muted           | boolean                   | 否 | 否    | 表示通话mic是否静音。 true表示是静音，false表示不是静音。|

## DeviceInfo<sup>10+</sup>

播放设备的相关信息。

| 名称       | 类型           | 只读 | 可选 | 说明                   |
| ---------- | -------------- | ---- | ---- | ---------------------- |
| castCategory   | [AVCastCategory](arkts-apis-avsession-e.md#avcastcategory10)        | 否 | 否   | 投播的类别。  <br> **系统能力：** SystemCapability.Multimedia.AVSession.Core  <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| deviceId   | string | 否 | 否   | 播放设备的ID。<br> **系统能力：** SystemCapability.Multimedia.AVSession.Core  <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| deviceName | string | 否  | 否   | 播放设备的名称。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| deviceType | [DeviceType](arkts-apis-avsession-e.md#devicetype10) | 否 | 否   | 播放设备的类型。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| supportedProtocols<sup>11+</sup> | number | 否 | 是  | 播放设备支持的协议。<br>默认为TYPE_LOCAL,具体取值来自[ProtocolType](arkts-apis-avsession-e.md#protocoltype11)，可以是ProtocolType中的某个协议或者多个协议的组合。<br>设备仅支持一种协议，返回对应枚举值；设备支持多种协议，返回对应枚举值之和。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast   <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| supportedDrmCapabilities<sup>12+</sup> | Array\<string> | 否 | 是 | 播放设备支持的DRM能力。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast   <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| manufacturer<sup>13+</sup> | string | 否 | 是  | 播放设备生产厂家。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast  <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。|
| modelName<sup>13+</sup> | string | 否 | 是 | 播放设备型号名称。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast  <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。|
| audioCapabilities<sup>20+</sup> | [AudioCapabilities](#audiocapabilities20) | 否  | 是 | 播放设备支持的音频能力。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast  <br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|
| supportedPullClients<sup>20+</sup> | Array\<number> | 否 | 是 | 支持拉端客户端的ID集合（只有支持4K投播的设备会返回此字段）。 <br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast  <br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## OutputDeviceInfo<sup>10+</sup>

播放设备的相关信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称       | 类型           | 只读 | 可选 | 说明                   |
| ---------- | -------------- | ---- | ---- | ---------------------- |
| devices | Array\<[DeviceInfo](#deviceinfo10)\>|否 | 否  | 播放设备的集合。    |

## AVControlCommand<sup>10+</sup>

会话接受的命令的对象描述。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称      | 类型                                                                       | 只读| 可选 | 说明         |
| --------- |--------------------------------------------------------------------------| ---- | ---- |------------|
| command   | [AVControlCommandType](arkts-apis-avsession-t.md#avcontrolcommandtype10) | 否 | 否   | 命令（不同命令对应不同参数）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| parameter | [LoopMode](arkts-apis-avsession-e.md#loopmode10) \| string \|  number    | 否 | 是   | 命令对应的参数。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。   |
| commandInfo<sup>22+</sup> | [CommandInfo](#commandinfo22)                                            | 否 | 是   | 命令信息。      |

## AVCastPickerOptions<sup>14+</sup>

拉起的投播组件包含的配置属性。<br>从API版本26.0.0开始支持Wearable设备使用本属性。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称            | 类型                      | 只读 | 可选 | 说明               |
| --------------- |-------------------------| ---- |  ---- |---------------------------------------------------------------------|
| sessionType         | [AVSessionType](arkts-apis-avsession-t.md#avsessiontype10)  | 否 | 是  | 会话类型，默认值为audio。<br>当前仅支持的会话类型有audio和video。如果传入voice_call或video_call，将默认按照传入audio处理。<br>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。            |
| pickerStyle<sup>22+</sup>   |[AVCastPickerStyle](js-apis-avCastPickerParam.md#avcastpickerstyle12) | 否 | 是  | 设置组件样式。<br>Wearable设备上无需配置该属性，拉起的设备列表以全屏显示。|
| menuPosition<sup>22+</sup>  |[MenuPosition](#menuposition-22) | 否 | 是  | 当pickerStyle设置为STYLE_MENU时，可以设置弹出菜单的位置。|

## AudioCapabilities<sup>20+</sup>

表示投播设备支持的音频能力。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称            | 类型                      | 只读 | 可选 | 说明               |
| --------------- |-------------------------| ---- | ---- |---------------------------------------------------------------------|
| streamInfos            | Array\<[audio.AudioStreamInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiostreaminfo8)>                  | 是    | 否    | 音频能力参数的列表。  |

## CommandInfo<sup>22+</sup>

定义要发送到会话的命令信息。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称               | 类型                                                   | 只读 | 可选 | 说明        |
|------------------|------------------------------------------------------|----|----|-----------|
| callerBundleName | string                                               | 否  | 是  | 调用方应用包名。  |
| callerModuleName | string                                               | 否  | 是  | 调用方应用模块名。 |
| callerDeviceId   | string                                               | 否  | 是  | 调用方设备ID。  |
| callerType       | [CallerType](arkts-apis-avsession-e.md#callertype22) | 否  | 是  | 调用方来源。    |

## MenuPosition <sup>22+</sup>

定义可弹出菜单的组件的位置。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称   | 类型 | 只读 | 可选 | 说明              |
| -------| -----| ---- | ---- | ------------------|
|x  | number  |  否  |  否  | 组件在X轴上的位置坐标。单位为vp。|
|y  | number  |  否  |  否  | 组件在y轴上的位置坐标。单位为vp。|
|width | number  |  否  |  否  | 组件宽度。单位为vp。 |
|height | number  |  否  |  否  | 组件高度。单位为vp。|

## AVSessionDescriptor <sup>23+</sup>

会话的相关描述信息。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

| 名称          | 类型              | 只读 | 可选 | 说明  |
| --------------| ---------------- | ---------------- | ---------------- |------|
| sessionId    | string    | 否 | 否  | 会话ID。      |
| type         | [AVSessionType](arkts-apis-avsession-t.md#avsessiontype10)   | 否 | 否 | 会话类型。    |
| sessionTag   | string             | 否 | 否 | 会话的自定义名称。    |
| elementName  | [ElementName](../apis-ability-kit/js-apis-bundle-ElementName.md)  | 否 | 否 | 会话所属应用的信息（包含bundleName、abilityName等）。 |
| isActive     | boolean             | 否 | 否 | 会话是否被激活。<br>true：已被激活。 <br>false：没有被激活。                                      |
| isTopSession | boolean             | 否 | 否 | 会话是否为最新的会话。 <br>true：是最新的会话。<br>false：不是最新的会话。                |

## DesktopLyricState<sup>23+</sup>

桌面歌词状态。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称      | 类型   | 只读 | 可选 | 说明         |
| :-------- | :----- | :--- |:--- | :----------- |
| isLocked  | boolean | 否 | 否   | 桌面歌词位置是否锁定。true表示已锁定，false表示未锁定。若已锁定，桌面显示歌词后，固定当前位置，不可被拖拽。  |