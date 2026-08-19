# AVCodec支持的格式

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @rchdlee-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->

音视频的编解码能力以及文件格式封装和解封装能力的支持情况，在不同平台存在能力和规格的差异。开发者可以通过[获取支持的编解码能力](obtain-supported-codecs.md)来获取实际的支持情况和规格情况。

## 音视频编解码

### 视频解码
当前支持的解码能力如下：
| 视频解码类型       | 视频解码格式的MIME类型   |
| --------------------- | ---------------- |
| MSVIDEO1<sup>22+</sup>| [OH_AVCODEC_MIMETYPE_VIDEO_MSVIDEO1](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| WMV3<sup>22+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_WMV3](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| MJPEG<sup>22+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_MJPEG](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| MPEG2 | [OH_AVCODEC_MIMETYPE_VIDEO_MPEG2](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| MPEG4 | [OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| H.263 | [OH_AVCODEC_MIMETYPE_VIDEO_H263](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| AVC(H.264) | [OH_AVCODEC_MIMETYPE_VIDEO_AVC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| HEVC(H.265) | [OH_AVCODEC_MIMETYPE_VIDEO_HEVC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| AV1<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_AV1](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| VP9<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_VP9](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| VP8<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_VP8](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| RV30<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_RV30](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| RV40<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_RV40](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| WVC1<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_WVC1](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| DVVIDEO<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_DVVIDEO](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| RAWVIDEO<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_RAWVIDEO](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| MPEG1<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_MPEG1](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| Cinepak<sup>24+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_CINEPAK](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
<!--RP14--> <!--RP14End-->

通过MIME类型创建解码器时，如果系统平台支持硬件解码，系统平台会优先创建硬件解码器实例；如果系统平台不支持或者硬件解码器资源不足时，系统平台会创建软件解码器实例；如果系统平台无对应解码能力，会创建解码器实例失败。

系统平台提供的解码能力和设备强相关，开发者可以通过[获取支持的编解码能力](obtain-supported-codecs.md)获取系统平台支持的软硬件解码能力和能力规格。

例如可以通过<!--RP15-->OH_AVCODEC_MIMETYPE_VIDEO_AVC、OH_AVCODEC_MIMETYPE_VIDEO_HEVC<!--RP15End-->来查询系统平台支持的<!--RP16-->H.264、H.265的硬件解码能力。<!--RP16End-->

具体开发指导请参考[视频解码](video-decoding.md)。

### 视频编码
当前支持的编码能力如下：
| 视频编码类型       | 视频编码格式的MIME类型    |
| --------------------- | ---------------- |
| HEVC(H.265) | [OH_AVCODEC_MIMETYPE_VIDEO_HEVC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| AVC(H.264) | [OH_AVCODEC_MIMETYPE_VIDEO_AVC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |

如果系统平台无对应编码能力，会创建编码器实例失败。

基于MimeType创建编码器时，可以配置为H.264(OH_AVCODEC_MIMETYPE_VIDEO_AVC)和H.265(OH_AVCODEC_MIMETYPE_VIDEO_HEVC)。

系统平台支持情况和每种编码的能力范围，可以通过[获取支持的编解码能力](obtain-supported-codecs.md)获取。

具体开发指导请参考[视频编码](video-encoding.md)。

### 音频解码
当前支持的解码能力：
| 音频解码类型         | 音频解码格式的MIME类型     |
| --------------------- | ---------------- |
| AAC | [OH_AVCODEC_MIMETYPE_AUDIO_AAC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| MPEG(MP3) | [OH_AVCODEC_MIMETYPE_AUDIO_MPEG](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| Flac | [OH_AVCODEC_MIMETYPE_AUDIO_FLAC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| Vorbis | [OH_AVCODEC_MIMETYPE_AUDIO_VORBIS](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| AMR(amrnb、amrwb) | [OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量)、[OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| G711mu | [OH_AVCODEC_MIMETYPE_AUDIO_G711MU](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| APE | [OH_AVCODEC_MIMETYPE_AUDIO_APE](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| G711a<sup>20+</sup> | [OH_AVCODEC_MIMETYPE_AUDIO_G711A](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| ALAC<sup>22+</sup> | [OH_AVCODEC_MIMETYPE_AUDIO_ALAC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| AC3<sup>22+</sup> | [OH_AVCODEC_MIMETYPE_AUDIO_AC3](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| WMA<sup>22+</sup>(V1、V2、PRO) | [OH_AVCODEC_MIMETYPE_AUDIO_WMAV1](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量)、[OH_AVCODEC_MIMETYPE_AUDIO_WMAV2](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量)、[OH_AVCODEC_MIMETYPE_AUDIO_WMAPRO](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| GSM<sup>22+</sup> | [OH_AVCODEC_MIMETYPE_AUDIO_GSM](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| GSM_MS<sup>22+</sup> | [OH_AVCODEC_MIMETYPE_AUDIO_GSM_MS](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
<!--RP1--> <!--RP1End-->
<!--RP2--> <!--RP2End-->

如果系统平台无对应解码能力，会创建解码器实例失败。

系统平台提供的解码能力和设备强相关，开发者可以通过[获取支持的编解码能力](obtain-supported-codecs.md)获取系统平台支持的解码能力和能力规格。

从API version 23开始支持：TWINVQ、ILBC、TRUEHD、DVAUDIO、DTS、COOK。

具体开发指导请参考[音频解码](audio-decoding.md)。

### 音频编码
当前支持的编码能力：
| 音频编码类型         | 音频编码格式的MIME类型     |
| --------------------- | ---------------- |
| AAC | [OH_AVCODEC_MIMETYPE_AUDIO_AAC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| Flac | [OH_AVCODEC_MIMETYPE_AUDIO_FLAC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| MPEG(MP3) | [OH_AVCODEC_MIMETYPE_AUDIO_MPEG](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
| G711mu | [OH_AVCODEC_MIMETYPE_AUDIO_G711MU](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#变量) |
<!--RP3--> <!--RP3End-->
<!--RP13--> <!--RP13End-->
<!--RP20--> <!--RP20End-->

如果系统平台无对应编码能力，会创建编码器实例失败。

系统平台提供的编码能力和设备强相关，开发者可以通过[获取支持的编解码能力](obtain-supported-codecs.md)获取系统平台支持的编码能力和能力规格。

具体开发指导请参考[音频编码](audio-encoding.md)。

## 媒体数据封装与解封装

### 媒体数据解封装
支持的解封装格式如下：
| 媒体格式  | 封装格式                      | 轨道格式                      |
| -------- | :----------------------------| :----------------------------|
| 音视频     | mp4                        |<!--RP4-->视频轨：AVC(H.264)、MPEG4<br>音频轨：AAC、MPEG(MP3)、ALAC<sup>22+</sup>、TRUEHD<sup>23+</sup>、DTS<sup>23+</sup><br>字幕轨：WEBVTT<br>辅助轨：AUXL（如音频RAW信息、视频深度信息等。）<br>timed metadata轨：有时间属性的描述信息，如帧级的维测信息、传感器信息等。<!--RP4End-->|
| 音视频     | fmp4                       |<!--RP5-->视频轨：AVC(H.264)<br>音频轨：AAC、MPEG(MP3)、TRUEHD<sup>23+</sup>、DTS<sup>23+</sup><!--RP5End-->|
| 音视频     | mkv                        |<!--RP6-->视频轨：AVC(H.264)、MSVIDEO1<sup>22+</sup><br>音频轨：AAC、MPEG(MP3)、OPUS、ADPCM_YAMAHA<sup>22+</sup>、ADPCM_G722<sup>22+</sup>、ALAC<sup>22+</sup>、TRUEHD<sup>23+</sup>、DTS<sup>23+</sup><!--RP6End-->|
| 音视频     | mpeg-ts                    |<!--RP7-->视频轨：AVC(H.264)、MPEG2、MPEG4<br>音频轨：AAC、MPEG(MP3)、TRUEHD<sup>23+</sup>、DTS<sup>23+</sup><!--RP7End-->|
| 音视频     | flv                        |<!--RP8-->视频轨：AVC(H.264)<br>音频轨：AAC<!--RP8End-->|
| 音视频     | mpeg-ps                    |视频轨：AVC(H.264)、MPEG2<br>音频轨：MPEG(MP2、MP3)、DTS<sup>23+</sup>|
| 音视频     | avi                        |视频轨：H.263、AVC(H.264)、MPEG2、MPEG4、MJPEG<sup>22+</sup>、MSVIDEO1<sup>22+</sup><br>音频轨：AAC、MPEG(MP2、MP3)、PCM、GSM_MS<sup>22+</sup>、ADPCM_YAMAHA<sup>22+</sup>、ADPCM_G722<sup>22+</sup>、DVAUDIO<sup>23+</sup>、DTS<sup>23+</sup>|
| 音视频     | 3gp<sup>22+</sup>                        |视频轨：H.263、AVC(H.264)、MPEG4<br>音频轨：AAC、AMR(amrnb、amrwb)|
| 音视频     | 3g2<sup>22+</sup>                        |视频轨：H.263、AVC(H.264)、MPEG4<br>音频轨：AAC、AMR(amrnb、amrwb)|
| 音视频     | m4v<sup>22+</sup>                        |<!--RP12-->视频轨：AVC(H.264)、MPEG4<!--RP12End--><br>音频轨：AAC、ALAC、AC3|
| 音视频     | wmv<sup>22+</sup>                        |视频轨：AVC(H.264)、WMV3<br>音频轨：WMAV1、WMAV2、WMAPRO|
| 音视频     | rm<sup>23+</sup>、rmvb<sup>23+</sup>                        |视频轨：RV30、RV40<br>音频轨：AAC、AC3、COOK|
| 音频       | m4a                        |<!--RP9-->音频轨：AAC、ALAC<sup>22+</sup><!--RP9End-->|
| 音频       | aac                        |音频轨：AAC|
| 音频       | mp3                        |音频轨：MPEG(MP3)|
| 音频       | ogg                        |音频轨：Vorbis|
| 音频       | flac                       |音频轨：Flac|
| 音频       | wav                        |音频轨：PCM、G711mu、G711a、GSM_MS<sup>22+</sup>、ADPCM_YAMAHA<sup>22+</sup>、ADPCM_G722<sup>22+</sup>、ADPCM_G726<sup>22+</sup>、DVAUDIO<sup>23+</sup>、DTS<sup>23+</sup>|
| 音频       | amr                        |音频轨：AMR(amrnb、amrwb)|
| 音频       | ape                        |音频轨：APE|
| 音频       | wma<sup>22+</sup>                        |音频轨：AC3、WMAV1、WMAV2、Vorbis、Flac、AMR(amrnb、amrwb)、AAC、MPEG(MP2、MP3)、GSM_MS、G711mu、G711a、PCM、ADPCM_G722、ADPCM_G726、ADPCM_IMA_WAV、ADPCM_MS、ADPCM_YAMAHA、DVAUDIO<sup>23+</sup>、DTS<sup>23+</sup>|
| 音频       | sunAU<sup>24+</sup>          |音频轨：PCM、ADPCM_G722、ADPCM_G726LE、G711mu、G711a|
| 音频       | dts<sup>23+</sup>          |音频轨：DTS|
| 外挂字幕   | srt                        |字幕轨：SRT|
| 外挂字幕   | webvtt                     |字幕轨：WEBVTT|

DRM解密能力支持的解封装格式：<!--RP10-->mp4(H.264，AAC)、mpeg-ts(H.264，AAC)<!--RP10End-->。

具体开发指导请参考[媒体数据解封装](audio-video-demuxer.md)。

### 媒体数据封装
当前支持的封装能力如下：
| 封装格式 | 视频编解码类型        | 音频编解码类型   | 封面类型       |
| -------- | --------------------- | ---------------- | -------------- |
| mp4      | AVC（H.264）<!--RP11--><!--RP11End-->    | AAC、MPEG（MP3） | jpg、png、bmp |
| m4a      | -                     | AAC              | jpg、png、bmp |
| mp3      | -                     | MPEG（MP3）      | jpg             |
| amr      | -                     | AMR(amrnb、amrwb) | -             |
| wav      | -                     | G711mu(pcm-mulaw) 、raw(pcm)| -             |
| aac      | -                     | AAC               | -             |
| flac     | -                     | Flac              | jpg、png、bmp |
| ogg<sup>23+</sup>      | -                     | Vorbis、OPUS      | -              |
| flv      | AVC（H.264）<!--RP11--><!--RP11End-->    | AAC<!--RP17--><!--RP17End--> | - |

> **说明：**
>
> - 封装格式为mp4时，音频编解码类型为MPEG（MP3）时采样率需大于等于16000Hz。
> - 封装格式为mp4/m4a时，音频编解码类型为AAC时声道数范围为[1, 7]。
> - 从API版本26.0.0开始，支持flv格式封装。封装格式为flv时，仅支持一个音频轨和一个视频轨，不支持设置旋转角度，不支持封面轨和辅助轨。

文件级数据已定义的key如下所示：
   |                key                 |                       描述                    |
   | ---------------------------------- | :-------------------------------------------: |
   | OH_MD_KEY_CREATION_TIME            | 媒体文件创建时间的元数据，值类型为string（API14开始支持）。        |
   | OH_MD_KEY_COMMENT                  | 媒体文件注释的键，值类型为string（API20开始支持）。               |
   | OH_MD_KEY_ENABLE_MOOV_FRONT        | 媒体文件moov元数据是否前置标志，值类型为int32_t（API20开始支持）。 |
   | OH_MD_KEY_LATITUDE                 | 纬度的键，值类型为float，范围为[-90.0, 90.0]。表示地理位置信息中的纬度（从API version 24开始支持）。 |
   | OH_MD_KEY_LONGITUDE                | 经度的键，值类型为float，范围为[-180.0, 180.0]。表示地理位置信息中的经度（从API version 24开始支持）。 |
   | OH_MD_KEY_ALTITUDE                 | 海拔的键，值类型为float，该键是可选的。表示地理位置信息中的海拔（从API version 24开始支持）。 |

> **说明：**
>
> 封装格式为mp4时，用户自定义的key必须以"com.openharmony."为开头。值类型可以为int32_t、float、string，从API version 20开始增加支持uint8_t*。
> 封装格式为flv时，用户自定义的key必须以"com.openharmony."为开头。值类型为string。

配置选项key值说明：

mp4封装格式：
   |                key                 |         描述         |   aac  |   mp3  |  H.264  |  H.265  | 封面类型（jpg、png、bmp） |
   | ---------------------------------- | :------------------: | :----: | :----: | :----: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |  必须  |   -    |   -    |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |  必须  |   -    |   -    |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  可选  |  可选  |   -    |   -    |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选  |  可选  |   -    |   -    |   -   |
   | OH_MD_KEY_PROFILE                  | 编码档次              |  可选  |   -   |   -    |   -    |   -   |
   | OH_MD_KEY_BITRATE                  | 码率                  |  可选  |  可选  |  可选  |  可选  |   -   |
   | OH_MD_KEY_CODEC_CONFIG             | 编解码器特定数据       |  可选  |   -   |  可选  |  可选  |   -   |
   | OH_MD_KEY_WIDTH                    | 宽度                  |   -   |   -   |  必须  |  必须  |  必须  |
   | OH_MD_KEY_HEIGHT                   | 高度                  |   -   |   -   |  必须  |  必须  |  必须  |
   | OH_MD_KEY_FRAME_RATE               | 视频流帧率            |   -   |   -   |  可选  |  可选  |   -   |
   | OH_MD_KEY_COLOR_PRIMARIES          | 视频色域              |   -   |   -   |  可选  |  可选  |   -   |
   | OH_MD_KEY_TRANSFER_CHARACTERISTICS | 视频传递函数          |   -   |   -   |  可选  |  可选  |   -   |
   | OH_MD_KEY_MATRIX_COEFFICIENTS      | 视频矩阵系数          |   -   |   -   |  可选  |  可选  |   -   |
   | OH_MD_KEY_RANGE_FLAG               | 值域标志              |   -   |   -   |  可选  |  可选  |   -   |
   | OH_MD_KEY_VIDEO_IS_HDR_VIVID       | 视频轨是否为HDR VIVID |   -   |   -   |   -    |  可选  |   -   |

mp4封装辅助轨格式：
   |                key                 |         描述         |   aac  |   mp3  |  H.264  |  H.265  |
   | ---------------------------------- | :------------------: | :----: | :----: | :----: | :----: |
   | OH_MD_KEY_TRACK_TYPE               | 轨道媒体类型          |  必须  |  必须  |  必须   |  必须   |
   | OH_MD_KEY_TRACK_REFERENCE_TYPE     | 轨道引用类型          |  必须  |  必须  |  必须   |  必须   |
   | OH_MD_KEY_TRACK_DESCRIPTION        | 轨道标识              |  必须  |  必须  |  必须   |  必须   |
   | OH_MD_KEY_REFERENCE_TRACK_IDS      | 引用轨道编号          |  必须  |  必须  |  必须   |  必须   |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |  必须  |   -    |   -    |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |  必须  |   -    |   -    |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  可选  |  可选  |   -    |   -    |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选  |  可选  |   -    |   -    |
   | OH_MD_KEY_PROFILE                  | 编码档次              |  可选  |   -   |   -    |   -    |
   | OH_MD_KEY_BITRATE                  | 码率                  |  可选  |  可选  |  可选  |  可选  |
   | OH_MD_KEY_CODEC_CONFIG             | 编解码器特定数据       |  可选  |   -   |  可选  |  可选  |
   | OH_MD_KEY_WIDTH                    | 宽度                  |   -   |   -   |  必须  |  必须  |
   | OH_MD_KEY_HEIGHT                   | 高度                  |   -   |   -   |  必须  |  必须  |
   | OH_MD_KEY_FRAME_RATE               | 视频流帧率            |   -   |   -   |  可选  |  可选  |
   | OH_MD_KEY_COLOR_PRIMARIES          | 视频色域              |   -   |   -   |  可选  |  可选  |
   | OH_MD_KEY_TRANSFER_CHARACTERISTICS | 视频传递函数          |   -   |   -   |  可选  |  可选  |
   | OH_MD_KEY_MATRIX_COEFFICIENTS      | 视频矩阵系数          |   -   |   -   |  可选  |  可选  |
   | OH_MD_KEY_RANGE_FLAG               | 值域标志              |   -   |   -   |  可选  |  可选  |
   | OH_MD_KEY_VIDEO_IS_HDR_VIVID       | 视频轨是否为HDR VIVID |   -   |   -   |   -    |  可选  |

m4a封装格式：
   |                key                 |         描述         |   aac  | 封面类型（jpg、png、bmp） |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须   |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须   |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  可选   |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选   |   -   |
   | OH_MD_KEY_PROFILE                  | 编码档次              |  可选  |   -   |
   | OH_MD_KEY_BITRATE                  | 码率                  |  可选   |   -   |
   | OH_MD_KEY_CODEC_CONFIG             | 编解码器特定数据       |  可选  |   -   |
   | OH_MD_KEY_WIDTH                    | 宽度                  |   -   |  必须  |
   | OH_MD_KEY_HEIGHT                   | 高度                  |   -   |  必须  |

amr封装格式：
   |                key                 |         描述         | amr_nb | amr_wb |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |  必须  |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |  必须  |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  可选  |  可选  |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选  |  可选  |
   | OH_MD_KEY_BITRATE                  | 码率                  |  可选  |  可选  |

mp3封装格式：
   |                key                 |         描述         |   mp3  | 封面类型（jpg） |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  可选  |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选  |   -   |
   | OH_MD_KEY_BITRATE                  | 码率                  |  可选  |   -   |
   | OH_MD_KEY_WIDTH                    | 宽度                  |   -   |  必须  |
   | OH_MD_KEY_HEIGHT                   | 高度                  |   -   |  必须  |

wav封装格式：
   |                key                 |         描述         | g711mu  | raw  |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |  必须  |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |  必须  |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  可选  |  必须  |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选  |  可选  |
   | OH_MD_KEY_BITRATE                  | 码率                  |  必须  |  可选  |

aac封装格式：
   |                key                 |         描述         |  aac   |
   | ---------------------------------- | :------------------: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  可选  |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选  |
   | OH_MD_KEY_BITRATE                  | 码率                  |  可选  |
   | OH_MD_KEY_PROFILE                  | 编码档次              |  必须  |
   | OH_MD_KEY_AAC_IS_ADTS              | 是否为ADTS格式        |  必须  |

flac封装格式：
   |                key                 |         描述         |  flac   | 封面类型（jpg、png、bmp） |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  必须  |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选  |   -   |
   | OH_MD_KEY_BITRATE                  | 码率                  |  可选  |   -   |
   | OH_MD_KEY_CODEC_CONFIG             | 编解码器特定数据       |  可选  |   -   |
   | OH_MD_KEY_WIDTH                    | 宽度                  |   -   |  必须  |
   | OH_MD_KEY_HEIGHT                   | 高度                  |   -   |  必须  |

ogg封装格式（从API version 23开始支持）：
   |                key                 |         描述         | Vorbis |  OPUS  |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |  必须  |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |  必须  |
   | OH_MD_KEY_CODEC_CONFIG             | 编解码器特定数据       |  必须  |  必须  |

flv封装格式（从API版本26.0.0开始支持）：
<!--RP18-->
   |                key                 |         描述         |   aac  |  H.264  |  H.265  |
   | ---------------------------------- | :------------------: | :----: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |   -    |   -    |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |   -    |   -    |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选  |   -    |   -    |
   | OH_MD_KEY_PROFILE                  | 编码档次              |  可选  |   -    |   -    |
   | OH_MD_KEY_BITRATE                  | 码率                  |  可选  |  可选  |  可选  |
   | OH_MD_KEY_CODEC_CONFIG             | 编解码器特定数据       |  可选  |  可选  |  可选  |
   | OH_MD_KEY_WIDTH                    | 宽度                  |   -   |  必须  |  必须  |
   | OH_MD_KEY_HEIGHT                   | 高度                  |   -   |  必须  |  必须  |
   | OH_MD_KEY_FRAME_RATE               | 视频流帧率            |   -   |  可选  |  可选  |
   | OH_MD_KEY_COLOR_PRIMARIES          | 视频色域              |   -   |  可选  |  可选  |
   | OH_MD_KEY_TRANSFER_CHARACTERISTICS | 视频传递函数          |   -   |  可选  |  可选  |
   | OH_MD_KEY_MATRIX_COEFFICIENTS      | 视频矩阵系数          |   -   |  可选  |  可选  |
   | OH_MD_KEY_RANGE_FLAG               | 值域标志              |   -   |  可选  |  可选  |
<!--RP18End-->

具体开发指导请参考[媒体数据封装](audio-video-muxer.md)。
