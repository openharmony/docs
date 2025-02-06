# AVCodec支持的格式

## 媒体编解码

### 视频解码

当前支持的解码能力如下：

| 视频硬解类型       | 视频软解类型   |
| --------------------- | ---------------- |
| AVC(H.264)、HEVC(H.265) |AVC(H.264)<!--RP12--><!--RP12End--> |

视频解码软/硬件解码存在差异，基于MimeType创建解码器时，<!--RP13-->软解当前仅支持H264(OH_AVCODEC_MIMETYPE_VIDEO_AVC)，<!--RP13End-->
如果硬件平台支持，则可以使用H264(OH_AVCODEC_MIMETYPE_VIDEO_AVC)和H265(OH_AVCODEC_MIMETYPE_VIDEO_HEVC)硬件解码能力。

每一种解码的能力范围，可以通过[获取支持的编解码能力](obtain-supported-codecs.md)获取。

具体开发指导请参考[视频解码](video-decoding.md)。

### 视频编码

当前支持的编码能力如下：

| 容器规格 | 视频编码类型                 |
| -------- | ---------------------------- |
| mp4      | HEVC（H.265）、 AVC（H.264） |

目前仅支持硬件编码，基于MimeType创建编码器时，支持配置为H264(OH_AVCODEC_MIMETYPE_VIDEO_AVC)和H265(OH_AVCODEC_MIMETYPE_VIDEO_HEVC)。

每一种编码的能力范围，可以通过[获取支持的编解码能力](obtain-supported-codecs.md)获取。

具体开发指导请参考[视频编码](video-encoding.md)。


### 音频解码

当前支持的解码能力如下:

| 容器规格 | 音频解码类型                 |
| -------- | :--------------------------- |
| mp4      | AAC、MPEG(MP3)、Flac、Vorbis<!--RP1--><!--RP1End--> |
| m4a      | AAC                          |
| flac     | Flac                         |
| ogg      | Vorbis<!--RP2--><!--RP2End-->    |
| aac      | AAC                          |
| mp3      | MPEG(MP3)                    |
| amr      | AMR(amrnb、amrwb)            |
| raw      | G711mu                       |
| ape      | APE                          |

具体开发指导请参考[音频解码](audio-decoding.md)。


### 音频编码

当前支持的编码能力如下：

| 容器规格 | 音频编码类型       |
| -------- | :--------------- |
| mp4      | AAC、Flac        |
| m4a      | AAC              |
| flac     | Flac             |
| aac      | AAC              |
| mp3      | MP3              |
| raw      | G711mu           |
<!--RP3--><!--RP3End-->

具体开发指导请参考[音频编码](audio-encoding.md)。


## 媒体数据封装与解析

### 媒体数据解析

支持的解封装格式如下：

| 媒体格式  | 封装格式                      | 码流格式                      |
| -------- | :----------------------------| :----------------------------|
| 音视频     | mp4                        |<!--RP4-->视频码流：AVC(H.264)，音频码流：AAC、MPEG(MP3)，字幕流：WEBVTT<!--RP4End-->|
| 音视频     | fmp4                       |<!--RP5-->视频码流：AVC(H.264)，音频码流：AAC、MPEG(MP3)<!--RP5End-->|
| 音视频     | mkv                        |<!--RP6-->视频码流：AVC(H.264)，音频码流：AAC、MPEG(MP3)、OPUS<!--RP6End-->|
| 音视频     | mpeg-ts                    |<!--RP7-->视频码流：AVC(H.264)，音频码流：AAC、MPEG(MP3)<!--RP7End-->|
| 音视频     | flv                        |<!--RP8-->视频码流：AVC(H.264)，音频码流：AAC<!--RP8End-->|
| 音频       | m4a                        |<!--RP9-->音频码流：AAC<!--RP9End-->|
| 音频       | aac                        |音频码流：AAC|
| 音频       | mp3                        |音频码流：MPEG(MP3)|
| 音频       | ogg                        |音频码流：OGG|
| 音频       | flac                       |音频码流：FLAC|
| 音频       | wav                        |音频码流：PCM、PCM-MULAW|
| 音频       | amr                        |音频码流：AMR(AMR-NB、AMR-WB)|
| 音频       | ape                        |音频码流：APE|
| 外挂字幕   | srt                        |字幕流：SRT|
| 外挂字幕   | webvtt                     |字幕流：WEBVTT|

DRM解密能力支持的解封装格式：<!--RP10-->mp4(H.264，AAC)、mpeg-ts(H264，AAC)<!--RP10End-->。

具体开发指导请参考[媒体数据解析](audio-video-demuxer.md)。


### 媒体数据封装

当前支持的封装能力如下：

| 封装格式 | 视频编解码类型        | 音频编解码类型   | 封面类型       |
| -------- | --------------------- | ---------------- | -------------- |
| mp4      | AVC（H.264）<!--RP11--><!--RP11End-->    | AAC、MPEG（MP3） | jpeg、png、bmp |
| m4a      | -                     | AAC              | jpeg、png、bmp |
| mp3      | -                     | MPEG（MP3）      | -              |
| amr      | -                     | AMR(amrnb、amrwb) | -             |
| wav      | -                     | G711mu(pcm-mulaw) | -             |

> **说明：**
>
> - 封装格式为mp4，音频编解码类型为MPEG（MP3）时采样率需大于等于16000Hz。  
> - 封装格式为mp4/m4a，音频编解码类型为AAC时声道数范围为1~7。

配置选项key值说明：  

mp4封装格式
   |                key                 |         描述         |   aac  |   mp3  |  h264  |  h265  |  jpg   |  png   |  bmp   |
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

m4a封装格式
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

amr封装格式
   |                key                 |         描述         | amr_nb | amr_wb |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |  必须  |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |  必须  |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  可选  |  可选  |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选  |  可选  |
   | OH_MD_KEY_BITRATE                  | 码率                  |  可选  |  可选  |

mp3封装格式
   |                key                 |         描述         |   mp3  |  jpg   |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  可选  |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选  |   -   |
   | OH_MD_KEY_BITRATE                  | 码率                  |  可选  |   -   |
   | OH_MD_KEY_WIDTH                    | 宽度                  |   -   |  必须  |
   | OH_MD_KEY_HEIGHT                   | 高度                  |   -   |  必须  |

wav封装格式
   |                key                 |         描述         | g711mu  |
   | ---------------------------------- | :------------------: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | 采样率                |  必须  |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | 声道数                |  必须  |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | 输出音频流格式         |  可选  |
   | OH_MD_KEY_CHANNEL_LAYOUT           | 通道布局              |  可选  |
   | OH_MD_KEY_BITRATE                  | 码率                  |  必须  |
   
具体开发指导请参考[媒体数据封装](audio-video-muxer.md)。
