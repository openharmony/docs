# Interfaces (其他)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @chris2981-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

> **说明：**
>
> 本模块首批接口从API版本6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## AVFileDescriptor<sup>9+</sup>

音视频文件资源描述，一种特殊资源的播放方式，使用场景：应用中的音频资源被连续存储在同一个文件中，需要根据偏移量和长度进行播放。

**原子化服务API：** 从API版本11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称   | 类型   | 只读 | 可选  | 说明                                                         |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| fd     | number | 否  | 否  | 资源句柄，通过[resourceManager.getRawFd](../apis-localization-kit/js-apis-resource-manager.md#getrawfd9)获取，也可以通过[fileIo.open](../apis-core-file-kit/js-apis-file-fs.md#fileioopen)获取。    |
| offset | number | 否  | 是  | 资源偏移量。<br>取值范围为0到待播放音视频文件大小，默认值为0。需要基于预置资源的信息输入，非法值会造成音视频资源解析错误。 |
| length | number | 否  | 是  | 资源长度。<br>取值范围为0到待播放音视频文件大小，默认值为文件中从偏移量开始的剩余字节。需要基于预置资源的信息输入，非法值会造成音视频资源解析错误。 |

## AVDataSrcDescriptor<sup>10+</sup>

音视频文件资源描述，用于DataSource播放方式，使用场景：应用在未获取完整音视频资源时，允许用户创建播放实例并开始播放，达到提前播放的目的。

**原子化服务API：** 从API版本11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

| 名称   | 类型   | 只读 | 可选  | 说明                                                         |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| fileSize     | number | 否  | 否  | 待播放文件大小（字节），-1代表大小未知。如果fileSize设置为-1，播放模式类似于直播，不能进行seek及setSpeed操作，不能设置loop属性，因此不能重新播放。 |
| callback | (buffer: ArrayBuffer, length: number, pos?: number) => number | 否  | 否  | 用户设置的回调函数，用于填写数据。<br>- buffer: 表示被填写的内存，必选。<br>- length: 表示被填写内存的最大长度，必选。<br>- pos：表示填写的数据在资源文件中的位置，可选。当fileSize设置为-1时，该参数禁止被使用。 <br>- 返回值，number类型，返回填充数据的长度。返回-1表示到达流的末尾，返回-2表示遇到不可恢复的错误。|

## SubtitleInfo<sup>12+</sup>

外挂字幕信息，使用场景：订阅外挂字幕事件，回调返回外挂字幕详细信息。

**原子化服务API：** 从API版本12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称   | 类型   | 只读 | 可选  | 说明                                                         |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| text | string | 否  | 是  | 字幕文本信息。 |
| startTime | number | 否  | 是  | 显示当前字幕文本的开始时间（单位：毫秒）。 |
| duration | number | 否  | 是  | 显示当前字幕文本的持续时间（单位：毫秒）。 |

## SeiMessage<sup>18+</sup>

SEI信息内容，描述SEI信息的负载类型和数据。

**原子化服务API：** 从API版本18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称   | 类型   | 只读 | 可选  | 说明                                                         |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| payloadType | number | 否  | 否  | SEI信息的负载类型。 |
| payload | ArrayBuffer | 否  | 否  | SEI信息的负载数据。 |

## MediaDescription<sup>8+</sup>

通过key-value方式获取媒体信息。

**原子化服务API：** 从API版本11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称          | 类型   | 只读 | 可选  | 说明                                                         |
| ------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| [key: string] | Object | 否  | 是  | 该键值对支持的key取值范围，请参考[MediaDescriptionKey](arkts-apis-media-e.md#mediadescriptionkey8)；每个key值的Object类型和范围，请参考[MediaDescriptionKey](arkts-apis-media-e.md#mediadescriptionkey8)对应Key值的说明。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

function printfItemDescription(obj: media.MediaDescription, key: string) {
  let property: Object = obj[key];
  console.info('audio key is ' + key); // 通过key值获取对应的value。key值具体可见MediaDescriptionKey。
  console.info('audio value is ' + property); // 对应key值的value。其类型可为任意类型，具体key对应value的类型可参考MediaDescriptionKey。
}

let avPlayer: media.AVPlayer | undefined = undefined;
media.createAVPlayer((err: BusinessError, player: media.AVPlayer) => {
  if(player != null) {
    avPlayer = player;
    console.info(`Succeeded in creating AVPlayer`);
    avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
      if (arrList != null) {
        for (let i = 0; i < arrList.length; i++) {
          printfItemDescription(arrList[i], media.MediaDescriptionKey.MD_KEY_TRACK_TYPE); // 打印出每条轨道MD_KEY_TRACK_TYPE的值。
        }
      } else {
        console.error(`Failed to get TrackDescription, error:${error}`);
      }
    });
  } else {
    console.error(`Failed to create AVPlayer, error message:${err.message}`);
  }
});
```

## PlaybackInfo<sup>12+</sup>

通过key-value方式获取播放信息。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称          | 类型   | 只读 | 可选  | 说明                                                         |
| ------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| [key: string]| Object | 否  | 是  | 该键值对支持的key取值范围，请参考[PlaybackInfoKey](arkts-apis-media-e.md#playbackinfokey12)。<br>每个key值的Object类型和范围，请参考[PlaybackInfoKey](arkts-apis-media-e.md#playbackinfokey12)。 |

## WatermarkConfiguration

添加水印的配置参数。水印位置以视频左上角为原点计算。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称      | 类型   | 只读 | 可选 | 说明             |
| --------- | ------ | ---- | ---- | ---------------- |
| top  | number | 否   | 否   | 水印相对于视频顶部位置的偏移量。取值为整数，单位为像素（px）。 |
| left | number | 否   | 否   | 水印相对于视频左侧位置的偏移量。取值为整数，单位为像素（px）。 |
| width  | number | 否   | 是   | 水印图片的宽度。取值为正整数，取值范围为[1, 4096]，单位为像素（px）。 |
| height | number | 否   | 是   | 水印图片的高度。取值为正整数，取值范围为[1, 4096]，单位为像素（px）。 |

## AVRecorderConfig<sup>9+</sup>

表示音视频录制的参数设置。

通过audioSourceType和videoSourceType区分纯音频录制、纯视频录制或音视频录制。纯音频录制时，仅需要设置audioSourceType；纯视频录制时，仅需要设置videoSourceType；音视频录制时，audioSourceType和videoSourceType均需要设置。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

| 名称            | 类型                                     | 只读 | 可选 | 说明                                                         |
| --------------- | ---------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| audioSourceType | [AudioSourceType](arkts-apis-media-e.md#audiosourcetype9)     | 否   | 是   | 选择录制的音频源类型。选择音频录制时必填。<br> **原子化服务API：** 从API版本12开始，该接口支持在原子化服务中使用。|
| videoSourceType | [VideoSourceType](arkts-apis-media-e.md#videosourcetype9)     | 否   | 是   | 选择录制的视频源类型。选择视频录制时必填。                   |
| profile         | [AVRecorderProfile](#avrecorderprofile9) | 否   | 否   | 录制的profile，必要参数。<br> **原子化服务API：** 从API版本12开始，该接口支持在原子化服务中使用。|
| url             | string                                   | 否   | 否   | 录制输出URL：fd://xx (fd number) ![img](figures/image-url.png)，必要参数。 <br> **原子化服务API：** 从API版本12开始，该接口支持在原子化服务中使用。 |
|fileGenerationMode<sup>12+</sup> | [FileGenerationMode](arkts-apis-media-e.md#filegenerationmode12)  | 否   |  是   |  创建媒体文件的模式，配合[on('photoAssetAvailable')](arkts-apis-media-AVRecorder.md#onphotoassetavailable12)监听使用。|
| rotation<sup>(deprecated)</sup>        | number                                   | 否   | 是   | 录制的视频旋转角度，单位为度（°）。mp4格式支持0°、90°、180°和270°，默认值为0°。<br>从API版本6开始支持，从API版本12开始废弃。建议使用[AVMetadata](#avmetadata11).videoOrientation替代。<br>如果同时设置两个值，将会采用[AVMetadata](#avmetadata11).videoOrientation。     |
| location<sup>(deprecated)</sup>        | [Location](#location)                    | 否   | 是   | 录制的地理位置，默认不记录地理位置信息。<br>从API版本6开始支持，从API版本12开始废弃。建议使用 [AVMetadata](#avmetadata11).location。<br>如果同时设置两个值，将会采用[AVMetadata](#avmetadata11).location。 |
| metadata<sup>12+</sup>        | [AVMetadata](#avmetadata11)              | 否   | 是   | 设置元数据信息。详细内容请参考 [AVMetadata](#avmetadata11)。                  |
| maxDuration<sup>18+</sup>        | number             | 否   | 是   | 设置录制的最大时长，单位为秒，有效值取值范围[1, 2^31-1]，无效输入会重置为最大值。录制到达设定时长后，录制会自动停止，并通过stateChange回调录制状态，[AVRecorderState](arkts-apis-media-t.md#avrecorderstate9) = 'stopped'，[StateChangeReason](arkts-apis-media-e.md#statechangereason9) = BACKGROUND。|

## AVRecorderProfile<sup>9+</sup>

音视频录制的配置文件。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

| 名称             | 类型                                         | 只读 | 可选 | 说明                                                         |
| ---------------- | -------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| audioBitrate     | number                                       | 否   | 是   | 音频编码比特率，选择音频录制时必填。单位为比特/秒（bit/s）。<br>取值范围：<br>- AAC编码格式支持比特率范围[32000, 500000]。<br>- G711-mulaw编码格式支持比特率大小：64000。<br>- MP3编码格式取值范围[8000, 16000, 32000, 40000, 48000, 56000, 64000, 80000, 96000, 112000, 128000, 160000, 192000, 224000, 256000, 320000]。<br>当使用MP3编码格式时，采样率和比特率的映射关系： <br>- 采样率使用16K以下时，对应比特率范围为[8000 - 64000]。<br>- 采样率使用16K~32K时对应的比特率范围为[8000, 160000]。<br>- 采样率使用32K以上时对应的比特率范围为[32000, 320000]。<br>- AMR_NB编码格式支持比特率范围[4750, 5150, 5900, 6700, 7400, 7950, 10200, 12200]。<br>- AMR_WB编码格式支持比特率范围[6600, 8850, 12650, 14250, 15850, 18250, 19850, 23050, 23850]。<br> **原子化服务API：** 从API版本12开始，该接口支持在原子化服务中使用。 |
| audioChannels    | number                                       | 否   | 是   | 音频采集声道数，选择音频录制时必填。<br>- AAC编码格式取值范围[1, 2]。<br>- G711-mulaw编码格式支持大小：1。<br>- MP3编码格式取值范围[1, 2]。<br>- AMR-NB和AMR-WB编码格式支持大小：1。<br> **原子化服务API：** 从API版本12开始，该接口支持在原子化服务中使用。       |
| audioCodec       | [CodecMimeType](arkts-apis-media-e.md#codecmimetype8)             | 否   | 是   | 音频编码格式，选择音频录制时必填。<br>当前支持AUDIO_AAC、AUDIO_MP3、AUDIO_G711MU、AUDIO_AMR_NB和AUDIO_AMR_WB。<br> **原子化服务API：** 从API版本12开始，该接口支持在原子化服务中使用。     |
| aacProfile<sup>22+</sup>       | [AacProfile](arkts-apis-media-e.md#aacprofile22)             | 否   | 是   | 音频编码扩展格式，默认为AAC_LC格式。<br>当前支持类型：AAC_LC、AAC_HE和AAC_HE_V2。<br> **原子化服务API：** 从API版本22开始，该接口支持在原子化服务中使用。     |
| audioSampleRate  | number                                       | 否   | 是   | 音频采样率，选择音频录制时必填。单位为赫兹（Hz）。<br>取值范围：<br>- AAC编码支持采样率范围[8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000]。<br>- G711-mulaw编码支持采样率大小：8000。<br>- MP3编码支持采样率范围[8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000]。<br>- AMR_NB编码支持采样率大小：8000。<br>- AMR_WB编码支持采样率大小：16000。<br>可变比特率模式，码率仅作参考。<br> **原子化服务API：** 从API版本12开始，该接口支持在原子化服务中使用。 |
| fileFormat       | [ContainerFormatType](arkts-apis-media-e.md#containerformattype8) | 否   | 否   | 文件的容器格式，必要参数。当前支持MP4、M4A、MP3、WAV、AMR、AAC封装格式，当前AAC音频封装默认为ADTS帧头格式。不支持在MP4封装格式下使用AUDIO_MP3编码格式。<br>**原子化服务API：** 从API版本12开始，该接口支持在原子化服务中使用。|
| videoBitrate     | number                                       | 否   | 是   | 视频编码比特率，选择视频录制时必填。取值范围[10000, 100000000]，单位为比特/秒（bit/s）。  |
| videoCodec       | [CodecMimeType](arkts-apis-media-e.md#codecmimetype8)             | 否   | 是   | 视频编码格式，选择视频录制时必填。当前支持VIDEO_AVC和VIDEO_HEVC。|
| videoFrameWidth  | number                                       | 否   | 是   | 视频帧的宽，选择视频录制时必填。取值范围[176, 4096]，单位为像素（px）。         |
| videoFrameHeight | number                                       | 否   | 是   | 视频帧的高，选择视频录制时必填。取值范围[144, 4096]，单位为像素（px）。         |
| videoFrameRate   | number                                       | 否   | 是   | 视频帧率，选择视频录制时必填。推荐范围[1, 60]，单位为帧/秒（fps）。             |
| isHdr<sup>11+</sup>            | boolean                        | 否   | 是   | HDR编码，选择视频录制时选填。isHdr默认为false，对应编码格式没有要求，isHdr为true时，对应的编码格式必须为video/hevc。|
| enableTemporalScale<sup>12+</sup>            | boolean                        | 否   | 是   | 视频录制是否支持时域分层编码功能，选择视频录制时选填，enableTemporalScale默认为false。设置为true时，编码输出的码流中部分帧可以支持跳过不编码。|
| enableBFrame<sup>20+</sup>            | boolean                        | 否   | 是   | 视频录制是否启用B帧编码。true表示启用B帧编码（仅在视频编码格式为H.265且设备硬件支持的情况下生效），false表示不启用B帧编码。<br>该参数为视频录制场景下的可选项，默认值为false。|

### 音频参数配置对照表

此处提供音频参数配置的对照表，每项的具体释义，可查看下述字段解释。

|编码格式|封装格式|采样率|比特率|声道数|
|----|----|----|----|----|
|AUDIO_AAC|MP4,M4A|[8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000]|[32000-500000]|[1-2]|
|AUDIO_MP3|MP3|[8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000]|<br>- 采样率使用16000以下时，对应比特率范围为[8000, 16000, 32000, 40000, 48000, 56000, 64000]。<br>- 采样率使用16000~32000时对应的比特率范围为[8000, 16000, 32000, 40000, 48000, 56000, 64000, 80000, 96000, 112000, 128000, 160000]。<br>- 采样率使用32000以上时对应的比特率范围为[32000, 40000, 48000, 56000, 64000, 80000, 96000, 112000, 128000, 160000, 192000, 224000, 256000, 320000]。|[1-2]|
|AUDIO_G711MU|WAV|[8000]|[64000]|[1]|
|AUDIO_AMR_NB<sup>18+</sup> |AMR|[8000]|[4750, 5150, 5900, 6700, 7400, 7950, 10200, 12200]|[1]|
|AUDIO_AMR_WB<sup>18+</sup> |AMR|[16000]|[6600, 8850, 12650, 14250, 15850, 18250, 19850, 23050, 23850]|[1]|


## Location

视频录制的地理位置。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称      | 类型   | 只读 | 可选 | 说明             |
| --------- | ------ | ---- | ---- | ---------------- |
| latitude  | number | 否   | 否   | 地理位置的纬度，取值范围为[-90, 90]。 |
| longitude | number | 否   | 否   | 地理位置的经度，取值范围为[-180, 180]。 |

## EncoderInfo<sup>11+</sup>

编码器和规格参数。

系统能力：SystemCapability.Multimedia.Media.AVRecorder

| 名称       | 类型                             | 只读 | 可选 | 说明                                                         |
| ---------- | -------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| mimeType   | [CodecMimeType](arkts-apis-media-e.md#codecmimetype8) | 否   | 否   | 编码器MIME类型名称。                                           |
| type       | string                           | 否   | 否   | 编码器类型，audio表示音频编码器，video表示视频编码器。         |
| bitRate    | [Range](#range11)                | 否   | 是   | 比特率，包含该编码器的最大和最小值。单位为比特每秒（bit/s）。                           |
| frameRate  | [Range](#range11)                | 否   | 是   | 视频帧率，包含帧率的最大和最小值，仅视频编码器拥有。单位为帧率（FPS）。          |
| width      | [Range](#range11)                | 否   | 是   | 视频帧的宽度，包含宽度的最大和最小值，仅视频编码器拥有。单位为像素（px）。       |
| height     | [Range](#range11)                | 否   | 是   | 视频帧的高度，包含高度的最大和最小值，仅视频编码器拥有。单位为像素（px）。       |
| channels   | [Range](#range11)                | 否   | 是   | 音频采集声道数，包含声道数的最大和最小值，仅音频编码器拥有。   |
| sampleRate | Array\<number>                    | 否   | 是   | 音频采样率，包含所有可以使用的音频采样率值数组，具体数值依赖编码器类型，仅音频编码器拥有。单位为赫兹（Hz）。 |

## Range<sup>11+</sup>

表示一个类型的范围。

系统能力：SystemCapability.Multimedia.Media.AVRecorder

| 名称 | 类型   | 只读 | 可选 | 说明         |
| ---- | ------ | ---- | ---- | ------------ |
| min  | number | 否   | 否   | 范围的最小值。 |
| max  | number | 否   | 否   | 范围的最大值。 |

## AVTranscoderConfig<sup>12+</sup>

表示视频转码的参数设置。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

| 名称            | 类型                                    | 只读 | 可选 | 说明                                                         |
| --------------- | ---------------------------------------- |---- | ---- | ------------------------------------------------------------ |
| audioBitrate | number     | 否 | 是 | 输出音频的码率，单位为比特率（bps），支持范围[1, 500000]。默认设置为48Kbps。 <br> **原子化服务API：** 从API版本22开始，该接口支持在原子化服务中使用。 |
| audioCodec | [CodecMimeType](arkts-apis-media-e.md#codecmimetype8)     | 否 | 是  | 输出音频的编码格式，当前仅支持AAC。默认设置为AAC。 <br> **原子化服务API：** 从API版本22开始，该接口支持在原子化服务中使用。 |
| audioCodecV2 | [CodecMimeType](arkts-apis-media-e.md#codecmimetype8)     | 否 | 是  | 输出音频的编码格式。<br>如果指定的编码格式不被支持，prepare会失败。默认设置为AAC。<br> **起始版本：** 26.0.0 <br>**模型约束：** 此接口仅可在Stage模型下使用。 <br> **原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。 |
| fileFormat         | [ContainerFormatType](arkts-apis-media-e.md#containerformattype8) | 否 | 否   | 输出视频文件的封装格式，当前视频文件仅支持MP4。 <br> **原子化服务API：** 从API版本22开始，该接口支持在原子化服务中使用。 |
| videoBitrate         | number | 否 |  是  | 输出视频的码率，单位为比特率（bps）。默认码率按输出视频的分辨率设置，[240p, 480P]默认码率值为1Mbps，(480P, 720P]默认码率值为2Mbps，(720P, 1080P]默认码率值为4Mbps，1080P及以上默认值为8Mbps。 <br> **原子化服务API：** 从API版本22开始，该接口支持在原子化服务中使用。 |
| videoCodec        | [CodecMimeType](arkts-apis-media-e.md#codecmimetype8) | 否 | 是   | 输出视频的编码格式，当前仅支持AVC和HEVC。若源视频编码格式为HEVC，则默认设置为HEVC，否则默认设置为AVC。 <br> **原子化服务API：** 从API版本22开始，该接口支持在原子化服务中使用。 |
| videoFrameWidth        | number | 否 |  是   | 输出视频帧的宽，单位为像素（px），支持范围[240, 3840]。默认设置为源视频帧的宽。 <br> **原子化服务API：** 从API版本22开始，该接口支持在原子化服务中使用。 |
| videoFrameHeight        | number | 否 |  是   | 输出视频帧的高，单位为像素（px），支持范围[240, 2160]。默认设置为源视频帧的高。 <br> **原子化服务API：** 从API版本22开始，该接口支持在原子化服务中使用。 |
| enableBFrame<sup>20+</sup> | boolean | 否 |  是   | 转码使能B帧编码。true表示开启B帧编码，默认为不开启B帧编码。<br>B帧视频编码相关的约束和限制可以参考文档[B帧视频编码约束和限制](../../media/avcodec/video-encoding-b-frame.md#约束和限制)。如果当前不符合B帧视频编码的约束和限制，将忽略B帧，按不使能B帧进行编码。 <br> **原子化服务API：** 从API版本22开始，该接口支持在原子化服务中使用。 |


## AVMetadata<sup>11+</sup>

音视频元数据，包含各个元数据字段。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

| 名称   | 类型   | 只读 | 可选 | 说明                                                         |
| ------ | ------ | ---- | ---- |------------------------------------------------------------ |
| album     | string | 否 | 是 | 专辑的标题。不支持AVRecorder设置该属性。     |
| albumArtist | string | 否 | 是 | 专辑的艺术家。不支持AVRecorder设置该属性。 |
| artist | string | 否 | 是 | 媒体资源的艺术家。不支持AVRecorder设置该属性。 |
| author | string | 否 | 是 | 媒体资源的作者。不支持AVRecorder设置该属性。 |
| dateTime | string | 否 | 是 | 媒体资源的创建时间。不支持AVRecorder设置该属性。 |
| dateTimeFormat | string | 否 | 是 | 媒体资源的创建时间，按YYYY-MM-DD HH:mm:ss格式输出。不支持AVRecorder设置该属性。 |
| composer | string | 否 | 是 | 媒体资源的作曲家。不支持AVRecorder设置该属性。 |
| duration | string | 否 | 是 | 媒体资源的时长。不支持AVRecorder设置该属性。 |
| genre | string | 否 | 是 | 媒体资源的类型或体裁。|
| hasAudio | string | 否 | 是 | 媒体资源是否包含音频。不支持AVRecorder设置该属性。 |
| hasVideo | string | 否 | 是 | 媒体资源是否包含视频。不支持AVRecorder设置该属性。 |
| mimeType | string | 否 | 是 | 媒体资源的mime类型。不支持AVRecorder设置该属性。 |
| trackCount | string | 否 | 是 | 媒体资源的轨道数量。不支持AVRecorder设置该属性。 |
| sampleRate | string | 否 | 是 | 音频的采样率，单位为赫兹（Hz）。不支持AVRecorder设置该属性。 |
| title | string | 否 | 是 | 媒体资源的标题。当前版本为只读参数。不支持AVRecorder设置该属性。 |
| description<sup>23+</sup> | string | 否 | 是 | 媒体资源的描述信息。当前版本为只读参数。不支持AVRecorder设置该属性。 |
| videoHeight | string | 否 | 是 | 视频的高度，单位为像素（px）。不支持AVRecorder设置该属性。 |
| videoWidth | string | 否 | 是 | 视频的宽度，单位为像素（px）。不支持AVRecorder设置该属性。 |
| videoOrientation | string | 否 | 是 | 视频的旋转方向，单位为度（°）。|
| hdrType<sup>12+</sup> | [HdrType](arkts-apis-media-e.md#hdrtype12) | 否 | 是 | 媒体资源的HDR类型。不支持AVRecorder设置该属性。 |
| location<sup>12+</sup> | [Location](#location) | 否 | 是 | 视频的地理位置信息。 |
| customInfo<sup>12+</sup> | Record<string, string> | 否 | 是 | 从moov.meta.list 获取的自定义参数键值映射。|
| tracks<sup>20+</sup> | Array\<[MediaDescription](#mediadescription8)> | 否 | 是 | 媒体资源的轨道信息。不支持AVRecorder设置该属性。|
| encoder | string | 否 | 是 | 用于编码的软件、硬件及其设置的标识符。不支持AVRecorder设置该属性。<br>**起始版本：** 26.0.0<br> **模型约束：** 此接口仅可在Stage模型下使用。|

### AVMetadata.tracks支持的MediaDescriptionKey<sup>8+</sup>说明

AVMetadata.tracks支持的[MediaDescriptionKey](arkts-apis-media-e.md#mediadescriptionkey8)的范围如下：

| 名称   | 值   | 适用的轨道类型  |
| -------- | --------------------|------------------------ |
| MD_KEY_TRACK_INDEX | 'track_index' | 全部 |
| MD_KEY_TRACK_TYPE | 'track_type' | 全部 |
| MD_KEY_CODEC_MIME | 'codec_mime' | 音频、视频 |
| MD_KEY_WIDTH | 'width' | 视频 |
| MD_KEY_HEIGHT | 'height' | 视频 |
| MD_KEY_FRAME_RATE | 'frame_rate' | 视频 |
| MD_KEY_AUD_CHANNEL_COUNT | 'channel_count' | 音频 |
| MD_KEY_AUD_SAMPLE_RATE | 'sample_rate' | 音频 |
| MD_KEY_HDR_TYPE<sup>12+</sup> | 'hdr_type' | 视频 |
| MD_KEY_ORIGINAL_WIDTH<sup>21+</sup> | 'original_width' | 视频 |
| MD_KEY_ORIGINAL_HEIGHT<sup>21+</sup> | 'original_height' | 视频 |
| MD_KEY_BITRATE | 'bitrate' | 音频、视频（从API版本21开始，AVMetadata.tracks支持该值获取。） |
| MD_KEY_AUD_SAMPLE_DEPTH<sup>12+</sup> | 'sample_depth' | 音频（从API版本21开始，AVMetadata.tracks支持该值获取。） |

## PixelMapParams<sup>12+</sup>

获取视频缩略图时，输出缩略图的格式参数。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

| 名称   | 类型   | 只读 | 可选 | 说明                                                                            |
|--------|--------|------|------|---------------------------------------------------------------------------------|
| width  | number | 否   | 是   | 输出的缩略图宽度，单位为像素（px）。<br/>应保证大于0且不大于原始视频宽度。否则返回的缩略图不会进行缩放。 |
| height | number | 否   | 是   | 输出的缩略图高度，单位为像素（px）。<br/>应保证大于0且不大于原始视频高度。否则返回的缩略图不会进行缩放。 |

## OutputSize<sup>20+</sup>

用于获取视频缩略图时，来定义输出图像大小。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

| 名称   | 类型   | 只读 | 可选 | 说明                                                         |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| width  | number | 否   | 是   | 输出的缩略图宽度，单位为像素（px）。<br/>- 如果该值小于0，宽度是视频的原始宽度。<br/>- 如果值为0或未分配任何值，缩放比例同高度比例。<br/>- 如果宽度和高度均未分配任意值，则输出原始视频帧的宽度和高度。 |
| height | number | 否   | 是   | 输出的缩略图高度，单位为像素（px）。<br/>- 如果该值小于0，高度是视频的原始高度。<br/>- 如果值为0或未分配任何值，缩放比例同宽度比例。<br/>- 如果宽度和高度均未分配任意值，则输出原始视频帧的宽度和高度。 |

## FrameInfo<sup>23+</sup>

批量获取视频缩略图操作的返回值，包含请求抽帧的时间点、实际抽帧的时间点、从视频中输出缩略图的格式参数和获取单张缩略图操作的结果。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

| 名称   | 类型   | 只读 | 可选 | 说明                                                                            |
|--------|--------|------|------|---------------------------------------------------------------------------------|
| requestedTimeUs  | number | 否   | 否   | 请求抽帧的时间点。 |
| actualTimeUs | number | 否   | 是   | 实际抽帧的时间点。 |
| image | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 否   | 是   | 从视频中输出缩略图的格式参数。 |
| result | [FetchResult](arkts-apis-media-e.md#fetchresult23) | 否   | 否   | 获取单张缩略图任务的结果。例如成功，失败或任务被取消。 |

## MediaStream<sup>19+</sup>

媒体流数据信息。

**原子化服务API：** 从API版本19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称  | 类型   | 只读 | 可选 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| url     | string | 否   | 否   | 媒体资源链接，当前仅支持http或者https。                                                 |
| width   | number | 否   | 否   | 媒体资源视频宽像素值。未知时可以填0，此时将无法通过[PlaybackStrategy](#playbackstrategy12)优选匹配。 |
| height  | number | 否   | 否   | 媒体资源视频高像素值。未知时可以填0，此时将无法通过[PlaybackStrategy](#playbackstrategy12)优选匹配。 |
| bitrate | number | 否   | 否   | 媒体资源码率值，单位bps。                                        |

## MediaSourceLoader<sup>18+</sup>

用于定义媒体数据加载器，需要应用程序对其进行实现。

**原子化服务API：** 从API版本18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称   | 类型     | 只读 | 可选  | 说明                 |
| -------- | -------- | ---- | ---- | -------------------- |
| open | [SourceOpenCallback](arkts-apis-media-t.md#sourceopencallback18) | 否   | 否   | 由应用程序实现的回调函数，用于处理资源打开请求。 |
| read | [SourceReadCallback](arkts-apis-media-t.md#sourcereadcallback18) | 否   | 否   | 由应用程序实现的回调函数，用于处理资源读取请求。 |
| close | [SourceCloseCallback](arkts-apis-media-t.md#sourceclosecallback18) | 否   | 否   | 由应用程序实现的回调函数，用于处理资源关闭请求。 |

**示例：**

```ts
import { HashMap } from '@kit.ArkTS';
import { media } from '@kit.MediaKit';

let headers: Record<string, string> = {"User-Agent" : "User-Agent-Value"};
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://xxx",  headers);
let uuid: number = 1;
let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();
let mediaSourceLoader: media.MediaSourceLoader = {
  open: (request: media.MediaSourceLoadingRequest) => {
    console.info(`Opening resource: ${request.url}`);
    // 成功打开资源，返回唯一的句柄, 保证uuid和request对应。
    uuid += 1;
    requests.set(uuid, request);
    return uuid;
  },
  read: (uuid: number, requestedOffset: number, requestedLength: number) => {
    console.info(`Reading resource with handle ${uuid}, offset: ${requestedOffset}, length: ${requestedLength}`);
    // 判断uuid是否合法、存储read请求，不要在read请求阻塞去推送数据和头信息。
  },
  close: (uuid: number) => {
    console.info(`Closing resource with handle ${uuid}`);
    // 清除当前uuid相关资源。
    requests.remove(uuid);
  }
};

mediaSource.setMediaResourceLoaderDelegate(mediaSourceLoader);
let playStrategy : media.PlaybackStrategy = {
  preferredBufferDuration: 20,
};

async function setupPlayer() {
  let player = await media.createAVPlayer();
  player.setMediaSource(mediaSource, playStrategy);
}
```

## PlaybackStrategy<sup>12+</sup>

播放策略。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称  | 类型     | 只读 | 可选  | 说明                 |
| -------- | -------- | ---- | ---- | -------------------- |
| preferredWidth| number | 否   | 是   | 播放策略首选宽度，设置范围为大于0的整数，如1080，单位为像素（px）。<br>**原子化服务API：** 从API版本12开始，该接口支持在原子化服务中使用。 |
| preferredHeight | number | 否   | 是   | 播放策略首选高度，设置范围为大于0的整数，如1920，单位为像素（px）。<br>**原子化服务API：** 从API版本12开始，该接口支持在原子化服务中使用。 |
| preferredBufferDuration | number | 否   | 是   | 播放策略首选缓冲持续时间，单位为秒（s），取值范围[1, 20]。<br>具体使用方式可参考[在线视频播放卡顿优化实践](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-online-video-playback-lags-practice)。<br>**原子化服务API：** 从API版本12开始，该接口支持在原子化服务中使用。 |
| preferredHdr | boolean | 否   | 是   | 表示播放策略是否为hdr。true表示是，false表示不是，默认为false。<br>**原子化服务API：** 从API版本12开始，该接口支持在原子化服务中使用。 |
| enableSuperResolution<sup>18+</sup> | boolean | 否   | 是   | 表示是否使能超分功能。true表示使能超分，false表示不使能超分，默认为false。<br>若不使能超分，则后续不能调用超分相关接口。若使能超分，则超分功能默认开启，默认目标分辨率为1920x1080，单位为像素。<br>**原子化服务API：** 从API版本18开始，该接口支持在原子化服务中使用。 |
| showFirstFrameOnPrepare<sup>17+</sup> | boolean | 否   | 是   | 播放策略true是Prepare之后显示视频起播首帧，false是Prepare之后不显示视频起播首帧，默认不显示。<br>**原子化服务API：** 从API版本17开始，该接口支持在原子化服务中使用。 |
| mutedMediaType | [MediaType](arkts-apis-media-e.md#mediatype8) | 否   | 是   | 关闭输出的媒体类型。<br>对于API版本12-19，仅支持设置MediaType.MEDIA_TYPE_AUD。从API版本20开始，增加支持MediaType.MEDIA_TYPE_VID。 |
| preferredAudioLanguage<sup>13+</sup> | string | 否   | 是   | 播放策略首选音轨语言。dash场景下应用可按需设置。非dash场景暂不支持，建议缺省。<br>**原子化服务API：** 从API版本13开始，该接口支持在原子化服务中使用。 |
| preferredSubtitleLanguage<sup>13+</sup> | string | 否   | 是   | 播放策略首选字幕语言。dash场景下应用可按需设置。非dash场景暂不支持，建议缺省。<br>**原子化服务API：** 从API版本13开始，该接口支持在原子化服务中使用。 |
| preferredBufferDurationForPlaying<sup>18+</sup> | number | 否   | 是   | 播放策略首选起播缓冲水线。当起播缓冲时间超过该值，开始播放。单位为秒（s），取值范围[0, 20]。<br>**原子化服务API：** 从API版本18开始，该接口支持在原子化服务中使用。 |
| thresholdForAutoQuickPlay<sup>18+</sup> | number | 否   | 是   | 智能追帧水线，单位为秒（s），取值应不小于2s，且需大于起播缓冲水线，默认设置为5s。<br>播放策略可以通过设置智能追帧水线来保证直播的实时性。flv直播场景下应用可按需设置，非flv直播场景暂不支持。网络状态的变化可能会导致播放器在某段时间内积压大量数据。播放器会定期检查当前播放时间与缓存中最新的帧时间戳之间的差值，当这个差值过大时，播放器将以1.2倍速开始智能追帧。[on('speedDone')](arkts-apis-media-AVPlayer.md#onspeeddone9)事件会回调特定值100，表示智能追帧开启成功。当差值小于起播缓冲水线时，则停止追帧并恢复到正常播放速度。<br>**原子化服务API：** 从API版本18开始，该接口支持在原子化服务中使用。 |
| keepDecodingOnMute<sup>20+</sup>  | boolean | 否   | 是   | 表示在关闭视频媒体时解码器是否继续运行，用于方便快速打开媒体。目前仅支持视频。默认设置为false，表示当媒体关闭时，相应的解码器将停止运行以减少功耗。<br>**原子化服务API：** 从API版本20开始，该接口支持在原子化服务中使用。 |

## AVScreenCaptureStrategy<sup>20+</sup>

录屏策略。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

| 名称                  | 类型    | 只读 | 可选 | 说明                 |
| --------------------- | ------- | --- | --- | -------------------- |
| keepCaptureDuringCall | boolean | 否 | 是  | 蜂窝通话时是否保持录屏。true表示蜂窝通话时保持录屏，false表示蜂窝通话时不进行录屏，默认为false。 |
| enableBFrame | boolean | 否 | 是 | 录屏是否使能B帧编码。true表示录屏文件使能B帧编码，false表示录屏文件禁用B帧编码，默认是false。<br>B帧视频编码相关的约束和限制可以参考文档[B帧视频编码约束和限制](../../media/avcodec/video-encoding-b-frame.md#约束和限制)。如果当前不符合B帧视频编码的约束和限制，则正常录制不含B帧的视频，不会返回错误。 |
| privacyMaskMode<sup>23+</sup> | number | 否 | 是 | 设置屏幕录制时对隐私窗口的屏蔽模式。<br> - 0：表示存在隐私窗口时，采用全屏屏蔽模式，默认是0。<br> - 1：表示存在隐私窗口时，采用隐私窗口屏蔽模式。<br> - 设置为其他值时返回错误。<br> **模型约束：** 此接口仅可在Stage模型下使用。 |
| enablePause | boolean | 否 | 是 | 表示录屏过程中是否允许暂停录屏。<br>true表示允许，false表示不允许。默认是false。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。|

## AVScreenCaptureRecordConfig<sup>12+</sup>

表示录屏参数配置。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

| 名称              | 类型                                                         | 只读 | 可选 | 说明                                                         |
| ----------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| fd                | number                                                       | 否   | 否   | 录制输出的文件fd。                                           |
| frameWidth        | number                                                       | 否   | 是   | 录屏的视频宽度。<br>默认屏幕宽度，根据不同屏幕默认值不同。单位为像素（px）。 |
| frameHeight       | number                                                       | 否   | 是   | 录屏的视频高度。<br>默认屏幕高度，根据不同屏幕默认值不同。单位为像素（px）。 |
| videoBitrate      | number                                                       | 否   | 是   | 录屏的视频比特率。<br>默认为10000000。单位为比特每秒（bit/s）。                            |
| audioSampleRate   | number                                                       | 否   | 是   | 录屏的音频采样率。<br>内录的系统音和外录的麦克风都是用此采样率，默认48000，仅支持设置48000或16000。单位为赫兹（Hz）。 |
| audioChannelCount | number                                                       | 否   | 是   | 录屏的音频通道数，内录的系统音和外录的麦克风都是用此通道数，默认2声道，仅支持设置1或2声道。 |
| audioBitrate      | number                                                       | 否   | 是   | 录屏的音频比特率，内录的系统音和外录的麦克风都是用此比特率，默认96000。单位为比特每秒（bit/s）。 |
| preset            | [AVScreenCaptureRecordPreset](arkts-apis-media-e.md#avscreencapturerecordpreset12) | 否   | 是   | 录屏使用的编码和封装格式，默认SCREEN_RECORD_PRESET_H264_AAC_MP4格式。 |
| displayId<sup>15+</sup>            | number | 否   | 是   | 指定录屏使用的屏幕，默认主屏幕。 |
| fillMode<sup>18+</sup>            | [AVScreenCaptureFillMode](arkts-apis-media-e.md#avscreencapturefillmode18)| 否   | 是   | 录屏时视频流的填充模式。 |
| strategy<sup>20+</sup>            | [AVScreenCaptureStrategy](#avscreencapturestrategy20)| 否   | 是   | 录屏策略。 |

## AVMetricsEvent<sup>23+</sup>

描述指标事件的信息。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

| 名称   | 类型   | 只读 | 可选 | 说明                                                         |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| event  | [AVMetricsEventType](arkts-apis-media-e.md#avmetricseventtype23) | 否   | 否   | 指标事件的类型。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| timeStamp | number | 否   | 否   | 事件发生时的系统时间。 |
| playbackPosition | number | 否   | 否   | 事件发生时的播放进度位置。 |
| details | Record\<string, Object> | 否   | 否   | 事件的详细信息，不同指标事件类型包含的信息不同。<br/>卡顿事件包含卡顿时间（duration: number）和卡顿的媒体类型（media: [MediaType](arkts-apis-media-e.md#mediatype8)）。<br/>音画不同步事件包含不同步类型（视频帧超前或滞后音频帧）和不同步起止时间。<br/>加载速率变化事件包含变化前后的数据下载速率。<br/>加载数据请求错误事件包含请求阶段（连接、请求流媒体播放列表、请求流媒体数据）、请求时间和网络错误码。<br/>播放内容切换事件包含切换前后的资源参数信息（视频分辨率、视频帧率、音频采样率、音频通道数等）。<br/>播放内容不连续事件包含不连续类型（PTS跳变或者音频参数变化）、跳变前后的PTS/变化前后的音频参数（音频采样率、音频通道数、音频位深）。<br/>音频状态变化事件包括失焦事件发生时的前/后状态。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## VideoSize

描述视频尺寸。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称   | 类型   | 只读 | 可选 | 说明                                                         |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| width  | number | 否   | 是   | 视频分辨率的宽度。<br>取值约束：该值必须为正整数。<br>单位为像素。 |
| height | number | 否   | 是   | 视频分辨率的高度。<br>取值约束：该值必须为正整数。<br>单位为像素。 |

## TrackSelectionFilter

描述轨道选择的过滤条件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称   | 类型   | 只读 | 可选 | 说明                                                         |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| maxVideoBitrate | number | 否   | 是   | 允许的视频最大比特率。<br>单位为比特/秒。<br>该值必须为正整数，如果未指定此参数，则视频最大比特率不受限制。 |
| minVideoBitrate | number | 否   | 是   | 允许的视频最小比特率。<br>单位为比特/秒。<br>该值必须为正整数，如果未指定此参数，则视频最小比特率不受限制。 |
| maxVideoFrameRate | number | 否   | 是   | 允许的视频最大帧率。<br>单位为帧/秒。<br>该值必须为正整数，如果未指定此参数，则视频最大帧率不受限制。 |
| minVideoFrameRate | number | 否   | 是   | 允许的视频最小帧率。<br>单位为帧/秒。<br>该值必须为正整数，如果未指定此参数，则视频最小帧率不受限制。 |
| maxVideoResolution | [VideoSize](#videosize) | 否   | 是   | 允许的视频最大分辨率。如果未指定此参数，则视频最大分辨率不受限制。 |
| minVideoResolution | [VideoSize](#videosize) | 否   | 是   | 允许的视频最小分辨率。如果未指定此参数，则视频最小分辨率不受限制。 |
| preferredVideoMimeTypes | Array\<string> | 否   | 是   | 视频轨道的首选MIME类型。多个MIME按数组顺序排列，优先级依次递减。<br>取值约束：格式为MIME字符串或HLS/DASH中的编解码器字符串。<br>如果未指定或设置为空数组，则MIME类型不受限制。 |
| maxAudioBitrate | number | 否   | 是   | 允许的音频最大比特率。<br>单位为比特/秒。<br>该值必须为正整数，如果未指定此参数，则音频最大比特率不受限制。 |
| minAudioBitrate | number | 否   | 是   | 允许的音频最小比特率。<br>单位为比特/秒。<br>该值必须为正整数，如果未指定此参数，则音频最小比特率不受限制。 |
| maxAudioChannels | number | 否   | 是   | 允许的音频最大通道数。该值必须为正整数，如果未指定此参数，则音频通道数不受限制。 |
| preferredAudioMimeTypes | Array\<string> | 否   | 是   | 音频轨道的首选MIME类型。多个MIME按数组顺序排列，优先级依次递减。<br>取值约束：格式为MIME字符串或HLS/DASH中的编解码器字符串。<br>如果未指定此参数或设置为空数组，则音频的MIME类型不受限制。 |
| preferredAudioLanguages | Array\<string> | 否   | 是   | 音频轨道的首选语言。多个语言按数组顺序排列，优先级依次递减。<br>取值约束：语言字符串符合IETF BCP 47标准定义。<br>如果未指定此参数或设置为空数组，则音频语言不受限制。 |
| preferredSubtitleLanguages | Array\<string> | 否   | 是   | 字幕轨道的首选语言。多个语言按数组顺序排列，优先级依次递减。<br>取值约束：语言字符串符合IETF BCP 47标准定义。<br>如果未指定此参数或设置为空数组，则字幕语言不受限制。 |

## AudioRecorderConfig<sup>(deprecated)</sup>

> **说明：**
> 从API版本6开始支持，从API版本9开始废弃，建议使用[AVRecorderConfig](#avrecorderconfig9)替代。

表示音频的录音配置。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

| 名称                                | 类型                                         | 只读 | 可选 | 说明                                                         |
| ----------------------------------- | -------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| audioEncoder                        | [AudioEncoder](arkts-apis-media-e.md#audioencoderdeprecated)                | 否   | 是   | 音频编码格式，默认设置为AAC_LC。<br/>**说明：** 从API版本6开始支持，从API版本8开始废弃，建议使用audioEncoderMime替代。 |
| audioEncodeBitRate                  | number                                       | 否   | 是   | 音频编码比特率，默认值为48000。单位为比特每秒（bit/s）。<br/>**说明：** 从API版本6开始支持，从API版本9开始废弃，建议使用[AVRecorderProfile](#avrecorderprofile9)中的audioBitrate替代。 |
| audioSampleRate                     | number                                       | 否   | 是   | 音频采集采样率，默认值为48000。单位为赫兹（Hz）。<br>可变比特率模式，码率仅作参考。<br/>**说明：** 从API版本6开始支持，从API版本9开始废弃，建议使用[AVRecorderProfile](#avrecorderprofile9)中的audioSampleRate替代。 |
| numberOfChannels                    | number                                       | 否   | 是   | 音频采集声道数，默认值为2。<br/>**说明：** 从API版本6开始支持，从API版本9开始废弃，建议使用[AVRecorderProfile](#avrecorderprofile9)中的audioChannels替代。 |
| format                              | [AudioOutputFormat](arkts-apis-media-e.md#audiooutputformatdeprecated)      | 否   | 是   | 音频输出封装格式，默认设置为MPEG_4。<br/>**说明：** 从API版本6开始支持，从API版本8开始废弃，建议使用fileFormat替代。 |
| location                            | [Location](#location)                        | 否   | 是   | 音频采集的地理位置。<br/>**说明：** 从API版本6开始支持，从API版本9开始废弃，建议使用[AVMetadata](#avmetadata11)中的location替代。 |
| uri                                 | string                                       | 否   | 否   | 音频输出URI：fd://xx&nbsp;(fd&nbsp;number)<br/>![](figures/image-url.png) <br/>文件需要由调用者创建，并赋予适当的权限。<br/>**说明：** 从API版本6开始支持，从API版本9开始废弃，建议使用[AVRecorderConfig](#avrecorderconfig9)中的url替代。 |
| audioEncoderMime<sup>8+</sup>       | [CodecMimeType](arkts-apis-media-e.md#codecmimetype8)             | 否   | 是   | 音频编码格式。<br/>**说明：** 从API版本8开始支持，从API版本9开始废弃，建议使用[AVRecorderProfile](#avrecorderprofile9)中的audioCodec替代。 |
| fileFormat<sup>8+</sup>             | [ContainerFormatType](arkts-apis-media-e.md#containerformattype8) | 否   | 是   | 文件容器格式。<br/>**说明：** 从API版本8开始支持，从API版本9开始废弃，建议使用[AVRecorderProfile](#avrecorderprofile9)中的fileFormat替代。 |

## AVTimedMetaData

描述基于时间的元数据的信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称   | 类型   | 只读 | 可选 | 说明                                                         |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| id  | string | 否   | 是   | 基于时间的元数据的唯一标记。<br>该标记在视频源的数据信息中须保持唯一。 |
| classify | string | 否   | 是   | 基于时间的元数据的分类标签。 |
| start | number | 否   | 否   | 基于时间的元数据相对整个媒体起始时间的偏移值。<br>取值限定为整数。<br>单位：毫秒。 |
| duration | number | 否   | 否   | 基于时间的元数据的持续时长。<br>取值限定为整数。<br>单位：毫秒。 |
| contents | Record<string, object> | 否   | 否   | 基于时间的元数据对应的键值对集合。 |