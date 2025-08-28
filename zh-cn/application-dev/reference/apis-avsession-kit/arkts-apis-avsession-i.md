# Interfaces (其他)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## AVCastControlCommand<sup>10+</sup>

投播控制器接受的命令的对象描述。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称      | 类型                                              | 必填 | 说明           |
| --------- | ------------------------------------------------- | ---- | -------------- |
| command   | [AVCastControlCommandType](arkts-apis-avsession-t.md#avcastcontrolcommandtype10)     | 是   | 命令。每种命令对应的参数不同，具体的对应关系可查阅[AVCastControlCommandType](arkts-apis-avsession-t.md#avcastcontrolcommandtype10)里的详细介绍。 |
| parameter | [media.PlaybackSpeed](../apis-media-kit/arkts-apis-media-e.md#playbackspeed8) &#124; number &#124; string &#124; [LoopMode](arkts-apis-avsession-e.md#loopmode10) | 否   | 命令对应的参数。 |

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
| assetId         | string                  | 否   | 否   | 媒体ID。歌曲的唯一标识，由应用自定义。该属性发生变化则其他元数据属性都将被刷新。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                     |
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
| mediaImage      | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) &#124; string | 否   | 是   | 图片的像素数据或者图片路径地址(本地路径或网络路径)。应用通过setAVMetadata设置图片数据。<br>- 设置的数据类型为PixelMap时，通过getAVMetadata获取的将为PixelMap。<br>- 设置为url图片路径，获取的为url图片路径。  <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                             |
| bundleIcon<sup>18+</sup>      | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 是   | 是   | 应用图标图片的像素数据。只读类型，不从应用侧设置。|
| publishDate     | Date                    | 否   | 是   | 发行日期。          |
| subtitle        | string                  | 否   | 是   | 子标题。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。             |
| description     | string                  | 否   | 是   | 媒体描述。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。            |
| lyric           | string                  | 否   | 是   | 媒体歌词内容。应用需将歌词内容拼接为一个字符串传入。<br>字符串长度需<40960字节。<br>**说明：** 系统支持简单版的LRC格式（Simple LRC format）的歌词文本内容。当传入的歌词内容不规范（例如：出现重复的时间戳等），将导致解析失败，并在系统中显示异常。 |
| singleLyricText<sup>17+</sup> | string    | 否   | 是   | 单条媒体歌词内容。应用需将歌词内容拼接为一个字符串传入（不包含时间戳）。<br>字符串长度<40960字节。<br>**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。|
| previousAssetId | string                  | 否   | 是   | 上一首媒体ID。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| nextAssetId     | string                  | 否   | 是   | 下一首媒体ID。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| filter<sup>11+</sup>        | number         | 否   | 是   | 当前session支持的协议，默认为TYPE_CAST_PLUS_STREAM。具体取值参考[ProtocolType](arkts-apis-avsession-e.md#protocoltype11)。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                   |
| drmSchemes<sup>12+</sup>        | Array\<string>         | 否   | 是   | 当前session支持的DRM方案，取值为DRM方案uuid。|
| skipIntervals<sup>11+</sup>  | [SkipIntervals](arkts-apis-avsession-e.md#skipintervals11)        | 否   | 是   | 快进快退支持的时间间隔。默认为SECONDS_15，即15秒。                            |
|displayTags<sup>11+</sup>     | number                           | 否   | 是   | 媒体资源的金标类型，取值参考[DisplayTag](arkts-apis-avsession-e.md#displaytag11)。       |

## AVMediaDescription<sup>10+</sup>

播放列表媒体元数据的相关属性。

| 名称         | 类型                    | 只读  | 可选  | 说明                     |
| ------------ | ----------------------- | ---- | ---- | ----------------------- |
| assetId      | string                  | 否   | 否   | 播放列表媒体ID。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| title        | string                  | 否   | 是   | 播放列表媒体标题。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| subtitle     | string                  | 否   | 是   | 播放列表媒体子标题。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| description  | string                  | 否   | 是   | 播放列表媒体描述的文本。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| mediaImage | image.PixelMap \| string   | 否   | 是   | 播放列表媒体图片像素数据。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| extras       | {[key: string]: Object}    | 否   | 是   | 播放列表媒体额外字段。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| mediaUri     | string                  | 否   | 是   | 播放列表媒体URI。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| mediaType     | string                  | 否   | 是   | 播放列表媒体类型。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| mediaSize     | number                  | 否   | 是   | 播放列表媒体的大小。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| albumTitle     | string                  | 否   | 是   | 播放列表媒体专辑标题。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| albumCoverUri     | string                  | 否   | 是   | 播放列表媒体专辑标题URI。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| lyricContent     | string                  | 否   | 是   | 播放列表媒体歌词内容。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| lyricUri     | string                  | 否   | 是   | 播放列表媒体歌词URI。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| artist     | string                  | 否   | 是   | 播放列表媒体专辑作者。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| fdSrc     | [media.AVFileDescriptor](../apis-media-kit/arkts-apis-media-i.md#avfiledescriptor9)        | 否   | 是   | 播放列表媒体本地文件的句柄。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| dataSrc<sup>12+</sup>     | [media.AVDataSrcDescriptor](../apis-media-kit/arkts-apis-media-i.md#avdatasrcdescriptor10)        | 否   | 是   | 播放列表数据源描述。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| pcmSrc<sup>20+</sup>     | boolean        | 否   | 是   | 播放列表是否使用PCM数据源。true表示使用PCM数据源，false表示不使用PCM数据源。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>由于设备限制，暂时无法使用，将在后续版本提供支持。 |
| drmScheme<sup>12+</sup>     | string        | 否   | 是   | 播放列表媒体支持的DRM方案，由uuid表示。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| duration     | number                  | 否   | 是   | 播放列表媒体播放时长。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| startPosition     | number                  | 否   | 是   | 播放列表媒体起始播放位置。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| creditsPosition     | number                  | 否   | 是   | 播放列表媒体的片尾播放位置。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| appName     | string                  | 否   | 是   | 播放列表提供的应用的名字。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
|displayTags<sup>11+</sup>     | number | 否   | 是   | 媒体资源的金标类型，取值参考[DisplayTag](arkts-apis-avsession-e.md#displaytag11)。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
|launchClientData<sup>20+</sup> | string | 否 | 是 | 投播过程中应用程序向接收方发送的自定义数据。<br/>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast  <br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## AVQueueItem<sup>10+</sup>

播放列表中单项的相关属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称         | 类型                                        | 必填 | 说明                        |
| ------------ | ------------------------------------------ | ---- | --------------------------- |
| itemId       | number                                     | 是   | 播放列表中单项的ID。          |
| description  | [AVMediaDescription](#avmediadescription10)  | 否   | 播放列表中单项的媒体元数据。   |

## AVPlaybackState<sup>10+</sup>

媒体播放状态的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称         | 类型                                  | 必填 | 说明     |
| ------------ | ------------------------------------- | ---- | ------- |
| state        | [PlaybackState](arkts-apis-avsession-e.md#playbackstate10)       | 否   | 播放状态。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| speed        | number                                | 否   | 播放倍速。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| position     | [PlaybackPosition](#playbackposition10) | 否   | 播放位置。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| bufferedTime | number                                | 否   | 缓冲时间。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| loopMode     | [LoopMode](arkts-apis-avsession-e.md#loopmode10)                 | 否   | 循环模式。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| isFavorite   | boolean                               | 否   | 是否收藏，true表示收藏。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| activeItemId<sup>10+</sup> | number                  | 否   | 正在播放的媒体Id。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| volume<sup>10+</sup> | number                  | 否   | 正在播放的媒体音量。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| maxVolume<sup>11+</sup> | number                    | 否   | 最大音量。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| muted<sup>11+</sup>     | boolean                   | 否   | 当前静音状态，true表示静音。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| duration<sup>11+</sup>     | number                   | 否   | 当前媒体资源的时长。 |
| videoWidth<sup>11+</sup>  | number                  | 否   | 媒体资源的视频宽度，单位为像素（px）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| videoHeight<sup>11+</sup> |  number                 | 否   | 媒体资源的视频高度，单位为像素（px）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| extras<sup>10+</sup> | {[key: string]: Object}       | 否   | 自定义媒体数据。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## PlaybackPosition<sup>10+</sup>

媒体播放位置的相关属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称        | 类型   | 必填 | 说明               |
| ----------- | ------ | ---- | ------------------ |
| elapsedTime | number | 是   | 已用时间，单位毫秒（ms）。 |
| updateTime  | number | 是   | 更新时间，单位毫秒（ms）。 |

## CallMetadata<sup>11+</sup>

通话会话元数据相关属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称            | 类型                      | 必填 | 说明               |
| --------------- |-------------------------| ---- |---------------------------------------------------------------------|
| name            | string                  | 否    | 来电人姓名（别名）。    |
| phoneNumber     | string                  | 否    | 来电电话号码。            |
| avatar          | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)          | 否    | 来电人头像。            |

## AVCallState<sup>11+</sup>

通话状态相关属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称            | 类型                      | 必填 | 说明               |
| --------------- |-------------------------  | ---- |---------------------------------------------------------------------|
| state           | [CallState](arkts-apis-avsession-e.md#callstate11)                 | 是    | 当前通话状态。      |
| muted           | boolean                   | 是    | 通话mic是否静音。 <br>true：静音。 <br>false：不是静音。|

## DeviceInfo<sup>10+</sup>

播放设备的相关信息。

| 名称       | 类型           | 必填 | 说明                   |
| ---------- | -------------- | ---- | ---------------------- |
| castCategory   | [AVCastCategory](arkts-apis-avsession-e.md#avcastcategory10)        | 是   | 投播的类别。  <br> **系统能力：** SystemCapability.Multimedia.AVSession.Core  <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| deviceId   | string | 是   | 播放设备的ID。<br> **系统能力：** SystemCapability.Multimedia.AVSession.Core  <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| deviceName | string | 是   | 播放设备的名称。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| deviceType | DeviceType | 是   | 播放设备的类型。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| supportedProtocols<sup>11+</sup> | number | 否   | 播放设备支持的协议。默认为TYPE_LOCAL。具体取值参考[ProtocolType](arkts-apis-avsession-e.md#protocoltype11)。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast   <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| supportedDrmCapabilities<sup>12+</sup> | Array\<string> | 否   | 播放设备支持的DRM能力。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast   <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| manufacturer<sup>13+</sup> | string | 否   | 播放设备生产厂家。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast  <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。|
| modelName<sup>13+</sup> | string | 否   | 播放设备型号名称。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast  <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。|
| audioCapabilities<sup>20+</sup> | [AudioCapabilities](#audiocapabilities20) | 否   | 播放设备支持的音频能力。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast |
| supportedPullClients<sup>20+</sup> | Array\<number> | 否 | 支持拉端客户端的ID集合（只有支持4K投播的设备会返回此字段）。 <br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast  <br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## OutputDeviceInfo<sup>10+</sup>

播放设备的相关信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称       | 类型           | 必填 | 说明                   |
| ---------- | -------------- | ---- | ---------------------- |
| devices | Array\<DeviceInfo\> | 是   | 播放设备的集合。    |

## AVControlCommand<sup>10+</sup>

会话接受的命令的对象描述。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称      | 类型                                              | 必填 | 说明           |
| --------- | ------------------------------------------------- | ---- | -------------- |
| command   | [AVControlCommandType](arkts-apis-avsession-t.md#avcontrolcommandtype10)     | 是   | 命令。每种命令对应的参数不同，具体的对应关系可查阅[AVControlCommandType](arkts-apis-avsession-t.md#avcontrolcommandtype10)里的详细介绍。       |
| parameter | [LoopMode](arkts-apis-avsession-e.md#loopmode10) &#124; string &#124; number | 否   | 命令对应的参数。 |

## AVCastPickerOptions<sup>14+</sup>

拉起的投播半模态窗口相关属性。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称            | 类型                      | 必填 | 说明               |
| --------------- |-------------------------| ---- |---------------------------------------------------------------------|
| sessionType         | [AVSessionType](arkts-apis-avsession-t.md#avsessiontype10)  | 否   | 会话类型，默认值为'audio'。<br>当前仅支持'audio'、'video'会话类型。如果传入'voice_call'、'video_call'，将按照传入默认值'audio'处理。            |

## AudioCapabilities<sup>20+</sup>

表示投播设备支持的音频能力。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称            | 类型                      | 只读 | 可选 | 说明               |
| --------------- |-------------------------| ---- | ---- |---------------------------------------------------------------------|
| streamInfos            | Array\<[audio.AudioStreamInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiostreaminfo8)>                  | 是    | 否    | 音频能力参数的列表。  |
