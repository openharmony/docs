# AVCodec支持的格式

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran; @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

## 媒体编解码

### 视频解码

当前支持的解码能力如下：

| 视频硬解类型       | 视频软解类型   |
| --------------------- | ---------------- |
| AVC(H.264)、HEVC(H.265)<!--RP14--><!--RP14End--> | MPEG2、MPEG4、H.263、AVC(H.264)<!--RP12--><!--RP12End--> |

通过MimeType创建解码器时，系统会优先创建硬件解码器实例。如果系统平台不支持或者硬件解码器资源不足时，系统会创建软件解码器实例。
当前系统支持的软件解码器格式包括：
- MPEG2(OH_AVCODEC_MIMETYPE_VIDEO_MPEG2)
- MPEG4(OH_AVCODEC_MIMETYPE_VIDEO_MPEG4_PART2)
- H.263(OH_AVCODEC_MIMETYPE_VIDEO_H263)
- H.264(OH_AVCODEC_MIMETYPE_VIDEO_AVC)
<!--RP13--><!--RP13End-->

系统提供的硬件解码能力和平台硬件能力强相关，开发者可以通过[获取支持的编解码能力](obtain-supported-codecs.md)获取系统硬件解码的能力和能力规格。
例如可以通过<!--RP15-->OH_AVCODEC_MIMETYPE_VIDEO_AVC、OH_AVCODEC_MIMETYPE_VIDEO_HEVC<!--RP15End-->来查询系统支持的<!--RP16-->H.264、H.265的硬件解码能力。<!--RP16End-->

具体开发指导请参考[视频解码](video-decoding.md)。

### 视频编码

当前支持的编码能力如下：

| 视频编码类型                 |
| ---------------------------- |
| HEVC(H.265)、 AVC(H.264) |

目前仅支持硬件编码，基于MimeType创建编码器时，支持配置为H.264(OH_AVCODEC_MIMETYPE_VIDEO_AVC)和H.265(OH_AVCODEC_MIMETYPE_VIDEO_HEVC)。

每一种编码的能力范围，可以通过[获取支持的编解码能力](obtain-supported-codecs.md)获取。

具体开发指导请参考[视频编码](video-encoding.md)。


### 音频解码

当前支持的解码能力：

AAC、MPEG(MP3)、Flac、Vorbis、AMR(amrnb、amrwb)、G711mu、APE、G711a<!--RP1--><!--RP1End-->。

具体开发指导请参考[音频解码](audio-decoding.md)。


### 音频编码

当前支持的编码能力：

AAC、Flac、MP3、G711mu<!--RP3--><!--RP3End-->。

具体开发指导请参考[音频编码](audio-encoding.md)。


## 媒体数据封装与解析

### 媒体数据解析

支持的解封装格式如下：

| 媒体格式  | 封装格式                      | 轨道格式                      |
| -------- | :----------------------------| :----------------------------|
| 音视频     | mp4                        |<!--RP4-->视频轨：AVC(H.264)、MPEG4<br>音频轨：AAC、MPEG(MP3)<br>字幕轨：WEBVTT<br>辅助轨：AUXL(AAC、MP3)<br>timed metadata轨<!--RP4End-->|
| 音视频     | fmp4                       |<!--RP5-->视频轨：AVC(H.264)<br>音频轨：AAC、MPEG(MP3)<!--RP5End-->|
| 音视频     | mkv                        |<!--RP6-->视频轨：AVC(H.264)<br>音频轨：AAC、MPEG(MP3)、OPUS<!--RP6End-->|
| 音视频     | mpeg-ts                    |<!--RP7-->视频轨：AVC(H.264)、MPEG2、MPEG4<br>音频轨：AAC、MPEG(MP3)<!--RP7End-->|
| 音视频     | flv                        |<!--RP8-->视频轨：AVC(H.264)<br>音频轨：AAC<!--RP8End-->|
| 音视频     | mpeg-ps                    |视频轨：AVC(H.264)、MPEG2<br>音频轨：MPEG(MP2、MP3)|
| 音视频     | avi                        |视频轨：H.263、AVC(H.264)、MPEG2、MPEG4<br>音频轨：AAC、MPEG(MP2、MP3)、PCM|
| 音频       | m4a                        |<!--RP9-->音频轨：AAC<!--RP9End-->|
| 音频       | aac                        |音频轨：AAC|
| 音频       | mp3                        |音频轨：MPEG(MP3)|
| 音频       | ogg                        |音频轨：Vorbis|
| 音频       | flac                       |音频轨：Flac|
| 音频       | wav                        |音频轨：PCM、G711mu、G711a|
| 音频       | amr                        |音频轨：AMR(amrnb、amrwb)|
| 音频       | ape                        |音频轨：APE|
| 外挂字幕   | srt                        |字幕轨：SRT|
| 外挂字幕   | webvtt                     |字幕轨：WEBVTT|

DRM解密能力支持的解封装格式：<!--RP10-->mp4(H.264，AAC)、mpeg-ts(H.264，AAC)<!--RP10End-->。

具体开发指导请参考[媒体数据解析](audio-video-demuxer.md)。


### 媒体数据封装

当前支持的封装能力如下：

| 封装格式 | 视频编解码类型        | 音频编解码类型   | 封面类型       |
| -------- | --------------------- | ---------------- | -------------- |
| mp4      | AVC（H.264）<!--RP11--><!--RP11End-->    | AAC、MPEG（MP3） | jpeg、png、bmp |
| m4a      | -                     | AAC              | jpeg、png、bmp |
| mp3      | -                     | MPEG（MP3）      | -              |
| amr      | -                     | AMR(amrnb、amrwb) | -             |
| wav      | -                     | G711mu(pcm-mulaw) 、raw(pcm)| -             |
| aac      | -                     | AAC               | -             |
| flac     | -                     | Flac              | jpeg、png、bmp |

> **说明：**
>
> - 封装格式为mp4，音频编解码类型为MPEG（MP3）时采样率需大于等于16000Hz。  
> - 封装格式为mp4/m4a，音频编解码类型为AAC时声道数范围为1~7。

文件级数据已定义的key如下所示：
   |                key                 |                       描述                    |
   | ---------------------------------- | :-------------------------------------------: |
   | OH_MD_KEY_CREATION_TIME            | 媒体文件创建时间的元数据，值类型为string（API14开始支持）。        |
   | OH_MD_KEY_COMMENT                  | 媒体文件注释的键，值类型为string（API20开始支持）。               |
   | OH_MD_KEY_ENABLE_MOOV_FRONT        | 媒体文件moov元数据是否前置标志，值类型为int32_t（API20开始支持）。 |

> **说明：**
>
> 用户自定义的key必须以"com.openharmony."为开头。值类型可以为int32_t、float、string，从API20开始增加支持uint8_t*。

配置选项key值说明：  

mp4封装格式：
   |                key                 |         描述         |   aac  |   mp3  |  H.264  |  H.265  |  jpg   |  png   |  bmp   |
   | ---------------------------------- | :------------------: | :----: | :----: | :----: | :----: | :----: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |  必须  |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |  必须  |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  可选  |  可选  |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选  |  可选  |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_PROFILE                  | 编码档次              |  可选  |   -   |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_BITRATE                  | 码率                  |  可选  |  可选  |  可选  |  可选  |   -   |   -   |   -   |
   | OH_MD_KEY_CODEC_CONFIG             | 编解码器特定数据       |  可选  |   -   |  可选  |  可选  |   -   |   -   |   -   |
   | OH_MD_KEY_WIDTH                    | 宽度                  |   -   |   -   |  必须  |  必须  |  必须  |  必须  |  必须  |
   | OH_MD_KEY_HEIGHT                   | 高度                  |   -   |   -   |  必须  |  必须  |  必须  |  必须  |  必须  |
   | OH_MD_KEY_FRAME_RATE               | 视频流帧率            |   -   |   -   |  可选  |  可选  |   -   |   -   |   -   |
   | OH_MD_KEY_COLOR_PRIMARIES          | 视频色域              |   -   |   -   |  可选  |  可选  |   -   |   -   |   -   |
   | OH_MD_KEY_TRANSFER_CHARACTERISTICS | 视频传递函数          |   -   |   -   |  可选  |  可选  |   -   |   -   |   -   |
   | OH_MD_KEY_MATRIX_COEFFICIENTS      | 视频矩阵系数          |   -   |   -   |  可选  |  可选  |   -   |   -   |   -   |
   | OH_MD_KEY_RANGE_FLAG               | 值域标志              |   -   |   -   |  可选  |  可选  |   -   |   -   |   -   |
   | OH_MD_KEY_VIDEO_IS_HDR_VIVID       | 视频轨是否为HDR VIVID |   -   |   -   |   -    |  可选  |   -   |   -   |   -   |

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
   |                key                 |         描述         |   aac  |  jpg   |  png   |  bmp   |
   | ---------------------------------- | :------------------: | :----: | :----: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须   |   -   |   -   |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须   |   -   |   -   |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  可选   |   -   |   -   |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选   |   -   |   -   |   -   |
   | OH_MD_KEY_PROFILE                  | 编码档次              |  可选  |   -   |   -   |   -   |
   | OH_MD_KEY_BITRATE                  | 码率                  |  可选   |   -   |   -   |   -   |
   | OH_MD_KEY_CODEC_CONFIG             | 编解码器特定数据       |  可选  |   -   |   -   |   -   |
   | OH_MD_KEY_WIDTH                    | 宽度                  |   -   |  必须  |  必须  |  必须  |
   | OH_MD_KEY_HEIGHT                   | 高度                  |   -   |  必须  |  必须  |  必须  |

amr封装格式：
   |                key                 |         描述         | amr_nb | amr_wb |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |  必须  |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |  必须  |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  可选  |  可选  |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选  |  可选  |
   | OH_MD_KEY_BITRATE                  | 码率                  |  可选  |  可选  |

mp3封装格式：
   |                key                 |         描述         |   mp3  |  jpg   |
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
   |                key                 |         描述         |  flac   |
   | ---------------------------------- | :------------------: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  必须  |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选  |
   | OH_MD_KEY_BITRATE                  | 码率                  |  可选  |
   | OH_MD_KEY_CODEC_CONFIG             | 编解码器特定数据       |  可选  |
   
具体开发指导请参考[媒体数据封装](audio-video-muxer.md)。
