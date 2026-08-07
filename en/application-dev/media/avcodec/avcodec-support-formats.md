# AVCodec Supported Formats

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran; @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=a33e33bc9d77acacea3ab60a23c994b62787103b translatedAt=2026-08-06T13:44:19.130Z pushedAt=2026-08-07T07:17:19.330Z -->

The capabilities for encoding and decoding audio and video, as well as for multiplexing and demultiplexing file formats, vary across different platforms in terms of functionality and specifications. You can obtain the supported capabilities and specifications by following the instructions provided in [Obtaining Supported Codecs](obtain-supported-codecs.md).

## Media Codec

### Video Decoding

Currently, the following decoding capabilities are supported:

| Video Decoding Type       | MIME Type of Video Decoding Format   |
| --------------------- | ---------------- |
| MSVIDEO1<sup>22+</sup>| [OH_AVCODEC_MIMETYPE_VIDEO_MSVIDEO1](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| WMV3<sup>22+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_WMV3](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| MJPEG<sup>22+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_MJPEG](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| MPEG2 | [OH_AVCODEC_MIMETYPE_VIDEO_MPEG2](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| MPEG4 | [OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| H.263 | [OH_AVCODEC_MIMETYPE_VIDEO_H263](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| AVC(H.264) | [OH_AVCODEC_MIMETYPE_VIDEO_AVC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| HEVC(H.265) | [OH_AVCODEC_MIMETYPE_VIDEO_HEVC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| AV1<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_AV1](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| VP9<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_VP9](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| VP8<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_VP8](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| RV30<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_RV30](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| RV40<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_RV40](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| WVC1<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_WVC1](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| DVVIDEO<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_DVVIDEO](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| RAWVIDEO<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_RAWVIDEO](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| MPEG1<sup>23+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_MPEG1](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |
| Cinepak<sup>24+</sup> | [OH_AVCODEC_MIMETYPE_VIDEO_CINEPAK](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) |

<!--RP14--><!--RP14End-->

When you attempt to create a decoder using the MIME type, if the system supports hardware decoding, the system preferentially creates a hardware decoder instance. If the system does not support hardware decoding or the hardware decoder resources are insufficient, the system creates a software decoder instance.

The decoding capabilities provided by the system platform are device-dependent. For details about the software and hardware decoding capabilities and capability specifications supported by the system platform, see [Obtaining Supported Codecs](obtain-supported-codecs.md).

For example, you can query the <!--RP16-->hardware decoding capabilities of H.264 and H.265<!--RP16End--> by using <!--RP15-->**OH_AVCODEC_MIMETYPE_VIDEO_AVC** and **OH_AVCODEC_MIMETYPE_VIDEO_HEVC**<!--RP15End-->.

For details about the development guide, see [Video Decoding](video-decoding.md).

### Video Encoding

Currently, the following encoding capabilities are supported:

| Video Encoding Type      | MIME Type for Video Encoding Format   |
| --------------------- | ---------------- |
| HEVC(H.265) | [OH_AVCODEC_MIMETYPE_VIDEO_HEVC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| AVC(H.264) | [OH_AVCODEC_MIMETYPE_VIDEO_AVC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|

If the system does not support the required encoding capability, the encoder instance fails to be created.

Supported MIME types for encoder creation include H.264 (`OH_AVCODEC_MIMETYPE_VIDEO_AVC`) and H.265 (`OH_AVCODEC_MIMETYPE_VIDEO_HEVC`).

For details about the platform support status and the capability range of each encoding type, see [Obtaining Supported Codecs](obtain-supported-codecs.md).

For details about the development guide, see [Video Encoding](video-encoding.md).

### Audio Decoding

Currently, the following decoding capabilities are supported:

| Audio Decoding Type        | MIME Type for Audio Decoding Format    |
| --------------------- | ---------------- |
| AAC | [OH_AVCODEC_MIMETYPE_AUDIO_AAC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| MPEG(MP3) | [OH_AVCODEC_MIMETYPE_AUDIO_MPEG](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| Flac | [OH_AVCODEC_MIMETYPE_AUDIO_FLAC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| Vorbis | [OH_AVCODEC_MIMETYPE_AUDIO_VORBIS](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| AMR (AMR-NB and AMR-WB)| [OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables) and [OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| G711mu | [OH_AVCODEC_MIMETYPE_AUDIO_G711MU](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| APE | [OH_AVCODEC_MIMETYPE_AUDIO_APE](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| G711a<sup>20+</sup> | [OH_AVCODEC_MIMETYPE_AUDIO_G711A](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| ALAC<sup>22+</sup> | [OH_AVCODEC_MIMETYPE_AUDIO_ALAC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| AC3<sup>22+</sup> | [OH_AVCODEC_MIMETYPE_AUDIO_AC3](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| WMA<sup>22+</sup>(V1, V2, PRO)| [OH_AVCODEC_MIMETYPE_AUDIO_WMAV1](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables), [OH_AVCODEC_MIMETYPE_AUDIO_WMAV2](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables), and [OH_AVCODEC_MIMETYPE_AUDIO_WMAPRO](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| GSM<sup>22+</sup> | [OH_AVCODEC_MIMETYPE_AUDIO_GSM](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| GSM_MS<sup>22+</sup> | [OH_AVCODEC_MIMETYPE_AUDIO_GSM_MS](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|

<!--RP1--> <!--RP1End-->
<!--RP2--> <!--RP2End-->

If the system does not support the required decoding capability, the decoder instance fails to be created.

The decoding capability provided by the system is closely related to the device. You can obtain the supported capabilities and specifications by following the instructions provided in [Obtaining Supported Codecs](obtain-supported-codecs.md).

Supported since API version 23: TWINVQ, ILBC, TRUEHD, DVAUDIO, DTS, and COOK

For details about the development guide, see [Audio Decoding](audio-decoding.md).

### Audio Encoding

Currently, the following encoding capabilities are supported:

| Audio Encoding Type        | MIME Type for Audio Encoding Format    |
| --------------------- | ---------------- |
| AAC | [OH_AVCODEC_MIMETYPE_AUDIO_AAC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| Flac | [OH_AVCODEC_MIMETYPE_AUDIO_FLAC](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| MPEG(MP3) | [OH_AVCODEC_MIMETYPE_AUDIO_MPEG](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|
| G711mu | [OH_AVCODEC_MIMETYPE_AUDIO_G711MU](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#variables)|

<!--RP3--> <!--RP3End-->
<!--RP13--> <!--RP13End-->
<!--RP20--> <!--RP20End-->

If the system does not support the required encoding capability, the encoder instance fails to be created.

The encoding capability provided by the system is closely related to the device. You can obtain the supported capabilities and specifications by following the instructions provided in [Obtaining Supported Codecs](obtain-supported-codecs.md).

For details about the development guide, see [Audio Encoding](audio-encoding.md).

## Media Data Multiplexing and Demultiplexing

### Media Data Demultiplexing

The following formats are supported:

| Media Format | Multiplexing Format                     | Track Format                     |
| -------- | :----------------------------| :----------------------------|
| Audio/Video    | mp4                        |<!--RP4-->Video track: AVC (H.264), MPEG4<br>Audio track: AAC, MPEG (MP3), ALAC<sup>22+</sup>, TRUEHD<sup>23+</sup>, DTS<sup>23+</sup><br>Subtitle track: WEBVTT<br>Auxiliary track: AUXL (such as audio raw information and video depth information)<br>Timed metadata track: time-related description information, such as frame-level maintenance and debugging information and sensor information.<!--RP4End-->|
| Audio/Video    | fmp4                       |<!--RP5-->Video track: AVC (H.264)<br>Audio track: AAC, MPEG (MP3), TRUEHD<sup>23+</sup>, DTS<sup>23+</sup><!--RP5End-->|
| Audio/Video    | mkv                        |<!--RP6-->Video track: AVC (H.264), MSVIDEO1<sup>22+</sup><br>Audio track: AAC, MPEG (MP3), OPUS, ADPCM_YAMAHA<sup>22+</sup>, ADPCM_G722<sup>22+</sup>, ALAC<sup>22+</sup>, TRUEHD<sup>23+</sup>, DTS<sup>23+</sup><!--RP6End-->|
| Audio/Video    | mpeg-ts                    |<!--RP7-->Video track: AVC (H.264), MPEG2, MPEG4<br>Audio track: AAC, MPEG (MP3), TRUEHD<sup>23+</sup>, DTS<sup>23+</sup><!--RP7End-->|
| Audio/Video    | flv                        |<!--RP8-->Video track: AVC (H.264)<br>Audio track: AAC<!--RP8End-->|
| Audio/Video    | mpeg-ps                    |Video track: AVC (H.264), MPEG2<br>Audio track: MPEG (MP2, MP3), DTS<sup>23+</sup>|
| Audio/Video    | avi                        |Video track: H.263, AVC(H.264), MPEG2, MPEG4, MJPEG<sup>22+</sup>, MSVIDEO1<sup>22+</sup><br>Audio track: AAC, MPEG(MP2, MP3), PCM, GSM_MS<sup>22+</sup>, ADPCM_YAMAHA<sup>22+</sup>, ADPCM_G722<sup>22+</sup>, DVAUDIO<sup>23+</sup>, DTS<sup>23+</sup>|
| Audio/Video    | 3gp<sup>22+</sup>                        |Video track: H.263, AVC (H.264), MPEG4<br>Audio track: AAC, AMR (amrnb and amrwb)|
| Audio/Video    | 3g2<sup>22+</sup>                        |Video track: H.263, AVC (H.264), MPEG4<br>Audio track: AAC, AMR (amrnb and amrwb)|
| Audio/Video    | m4v<sup>22+</sup>                        |<!--RP12-->Video track: AVC (H.264), MPEG4<!--RP12End--><br>Audio track: AAC, ALAC, AC3|
| Audio/Video    | wmv<sup>22+</sup>                        |Video track: AVC (H.264), WMV3<br>Audio track: WMAV1, WMAV2, WMAPRO|
| Audio/Video    | rm<sup>23+</sup>, rmvb<sup>23+</sup>                       |Video track: RV30, RV40<br>Audio track: AAC, AC3, COOK|
| Audio      | m4a                        |<!--RP9-->Audio track: AAC, ALAC<sup>22+</sup><!--RP9End-->|
| Audio      | aac                        |Audio track: AAC|
| Audio      | mp3                        |Audio track: MPEG (MP3)|
| Audio      | ogg                        |Audio track: Vorbis|
| Audio      | flac                       |Audio track: FLAC|
| Audio      | wav                        |Audio track: PCM, G711mu, G711a, GSM_MS<sup>22+</sup>, ADPCM_YAMAHA<sup>22+</sup>, ADPCM_G722<sup>22+</sup>, ADPCM_G726<sup>22+</sup>, DVAUDIO<sup>23+</sup>, DTS<sup>23+</sup>|
| Audio      | amr                        |Audio track: AMR (amrnb and amrwb)|
| Audio      | ape                        |Audio track: APE|
| Audio      | wma<sup>22+</sup>                        |Audio track: AC3, WMAV1, WMAV2, Vorbis, Flac, AMR (amrnb, amrwb), AAC, MPEG (MP2, MP3), GSM_MS, G711mu, G711a, PCM, ADPCM_G722, ADPCM_G726, ADPCM_IMA_WAV, ADPCM_MS, ADPCM_YAMAHA, DVAUDIO<sup>23+</sup>, DTS<sup>23+</sup>|
| Audio       | sunAU<sup>24+</sup>          |Audio track: PCM, ADPCM_G722, ADPCM_G726LE, G711mu, G711a|
| Audio      | dts<sup>23+</sup>          |Audio track: DTS|
| External subtitle  | srt                        |Subtitle track: SRT|
| External subtitle  | webvtt                     |Subtitle track: WEBVTT|

The DRM demultiplexing capability supports the following formats: <!--RP10-->mp4 (H.264 and AAC) and mpeg-ts (H.264 and AAC)<!--RP10End-->.

For details about the development guide, see [Media Data Demultiplexing](audio-video-demuxer.md).

### Media Data Multiplexing

Currently, the following muxer capabilities are supported:

| Container Format| Video Codec Type       | Audio Codec Type  | Cover Type      |
| -------- | --------------------- | ---------------- | -------------- |
| mp4      | AVC (H.264)<!--RP11--><!--RP11End-->    | AAC, MPEG (MP3) | jpg, png, bmp |
| m4a      | -                     | AAC              | jpg, png, bmp |
| mp3      | -                     | MPEG (MP3)      | jpg             |
| amr      | -                     | AMR (AMR-NB and AMR-WB)| -             |
| wav      | -                     | G711mu (pcm-mulaw), raw (pcm)| -             |
| aac      | -                     | AAC               | -             |
| flac     | -                     | Flac              | jpg, png, bmp |
| ogg<sup>23+</sup>      | -                     | Vorbis, OPUS     | -              |
| flv      | AVC (H.264)<!--RP11--><!--RP11End-->    | AAC<!--RP17--><!--RP17End--> | - |

> **NOTE**
>
> - When the multiplexing format is mp4 and the audio codec type is MPEG (MP3), the sample rate must be greater than or equal to 16000 Hz.
> - When the multiplexing format is mp4 or m4a and the audio codec type is AAC, the channel count ranges from 1 to 7.
> - Starting from API version 26.0.0, flv format multiplexing is supported. When the multiplexing format is flv, only one audio track and one video track are supported. Rotation angle setting, cover tracks, and auxiliary tracks are not supported.

The keys defined for file-level data are as follows:

   |                key                 |                       Description                   |
   | ---------------------------------- | :-------------------------------------------: |
   | OH_MD_KEY_CREATION_TIME            | Media file creation time. The value type is string. This key is supported since API version 14.       |
   | OH_MD_KEY_COMMENT                  | Comment in a media file. The value type is string. This key is supported since API version 20.              |
   | OH_MD_KEY_ENABLE_MOOV_FRONT        | Whether the moov metadata should be at the front of a media file. The value type is int32_t. This key is supported since API version 20.|
   | OH_MD_KEY_LATITUDE                 | Key for latitude. The value type is float, with a range of [-90.0, 90.0]. Represents the latitude in geographic location information (supported from API version 24). |
   | OH_MD_KEY_LONGITUDE                | Key for longitude. The value type is float, with a range of [-180.0, 180.0]. Represents the longitude in geographic location information (supported from API version 24). |
   | OH_MD_KEY_ALTITUDE                 | Key for altitude. The value type is float. This key is optional. Represents the altitude in geographic location information (supported from API version 24). |

> **NOTE**
>
> When the multiplexing format is mp4, custom keys must start with "com.openharmony.". The value type can be int32_t, float, or string. uint8_t* is also supported starting from API version 20.
> When the multiplexing format is flv, custom keys must start with "com.openharmony.". The value type is string.

Key values of configuration options are described as follows:

mp4 container format:

   |                key                 |         Description        |   aac  |   mp3  |  H.264  |  H.265  | Cover Type (jpg, png, bmp) |
   | ---------------------------------- | :------------------: | :----: | :----: | :----: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate                |  Mandatory  |  Mandatory  |   -    |   -    |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Channel count                |  Mandatory  |  Mandatory  |   -    |   -    |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format         |  Optional  |  Optional  |   -    |   -    |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout              |  Optional  |  Optional  |   -    |   -    |   -   |
   | OH_MD_KEY_PROFILE                  | Encoding profile              |  Optional  |   -   |   -    |   -    |   -   |
   | OH_MD_KEY_BITRATE                  | Bitrate                  |  Optional  |  Optional  |  Optional  |  Optional  |   -   |
   | OH_MD_KEY_CODEC_CONFIG             | Codec specific data       |  Optional  |   -   |  Optional  |  Optional  |   -   |
   | OH_MD_KEY_WIDTH                    | Width                  |   -   |   -   |  Mandatory  |  Mandatory  |  Mandatory  |
   | OH_MD_KEY_HEIGHT                   | Height                  |   -   |   -   |  Mandatory  |  Mandatory  |  Mandatory  |
   | OH_MD_KEY_FRAME_RATE               | Video stream frame rate            |   -   |   -   |  Optional  |  Optional  |   -   |
   | OH_MD_KEY_COLOR_PRIMARIES          | Video color gamut              |   -   |   -   |  Optional  |  Optional  |   -   |
   | OH_MD_KEY_TRANSFER_CHARACTERISTICS | Video transfer characteristics          |   -   |   -   |  Optional  |  Optional  |   -   |
   | OH_MD_KEY_MATRIX_COEFFICIENTS      | Video matrix coefficients          |   -   |   -   |  Optional  |  Optional  |   -   |
   | OH_MD_KEY_RANGE_FLAG               | Value domain flag              |   -   |   -   |  Optional  |  Optional  |   -   |
   | OH_MD_KEY_VIDEO_IS_HDR_VIVID       | Whether the video track is HDR VIVID |   -   |   -   |   -    |  Optional  |   -   |

MP4 container format of the auxiliary track:

   |                key                 |         Description        |   aac  |   mp3  |  H.264  |  H.265  |
   | ---------------------------------- | :------------------: | :----: | :----: | :----: | :----: |
   | OH_MD_KEY_TRACK_TYPE               | Media type of the track.         |  Mandatory |  Mandatory |  Mandatory  |  Mandatory  |
   | OH_MD_KEY_TRACK_REFERENCE_TYPE     | Reference type of the track.         |  Mandatory |  Mandatory |  Mandatory  |  Mandatory  |
   | OH_MD_KEY_TRACK_DESCRIPTION        | Track ID.             |  Mandatory |  Mandatory |  Mandatory  |  Mandatory  |
   | OH_MD_KEY_REFERENCE_TRACK_IDS      | Reference track number.         |  Mandatory |  Mandatory |  Mandatory  |  Mandatory  |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate.               |  Mandatory |  Mandatory |   -    |   -    |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Audio channel count.               |  Mandatory |  Mandatory |   -    |   -    |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format.        |  Optional |  Optional |   -    |   -    |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout.             |  Optional |  Optional |   -    |   -    |
   | OH_MD_KEY_PROFILE                  | Encoding profile.             |  Optional |   -   |   -    |   -    |
   | OH_MD_KEY_BITRATE                  | Bit rate.                 |  Optional |  Optional |  Optional |  Optional |
   | OH_MD_KEY_CODEC_CONFIG             | Codec-specific data.      |  Optional |   -   |  Optional |  Optional |
   | OH_MD_KEY_WIDTH                    | Width.                 |   -   |   -   |  Mandatory |  Mandatory |
   | OH_MD_KEY_HEIGHT                   | Height.                 |   -   |   -   |  Mandatory |  Mandatory |
   | OH_MD_KEY_FRAME_RATE               | Video stream frame rate.           |   -   |   -   |  Optional |  Optional |
   | OH_MD_KEY_COLOR_PRIMARIES          | Video color gamut.             |   -   |   -   |  Optional |  Optional |
   | OH_MD_KEY_TRANSFER_CHARACTERISTICS | Video transfer characteristics function.         |   -   |   -   |  Optional |  Optional |
   | OH_MD_KEY_MATRIX_COEFFICIENTS      | Video matrix coefficient.         |   -   |   -   |  Optional |  Optional |
   | OH_MD_KEY_RANGE_FLAG               | Value range flag.             |   -   |   -   |  Optional |  Optional |
   | OH_MD_KEY_VIDEO_IS_HDR_VIVID       | Whether the video track is an HDR Vivid.|   -   |   -   |   -    |  Optional |

m4a container format:

   |                key                 |         Description         |   aac  | Cover Type (jpg, png, bmp) |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate                |  Mandatory   |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Channel count                |  Mandatory   |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format         |  Optional   |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout              |  Optional   |   -   |
   | OH_MD_KEY_PROFILE                  | Encoding profile              |  Optional  |   -   |
   | OH_MD_KEY_BITRATE                  | Bitrate                  |  Optional   |   -   |
   | OH_MD_KEY_CODEC_CONFIG             | Codec specific data       |  Optional  |   -   |
   | OH_MD_KEY_WIDTH                    | Width                  |   -   |  Mandatory  |
   | OH_MD_KEY_HEIGHT                   | Height                  |   -   |  Mandatory  |

amr container format:

   |                key                 |         Description        | amr_nb | amr_wb |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate.               |  Mandatory |  Mandatory |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Audio channel count.               |  Mandatory |  Mandatory |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format.        |  Optional |  Optional |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout.             |  Optional |  Optional |
   | OH_MD_KEY_BITRATE                  | Bit rate.                 |  Optional |  Optional |

mp3 container format:

   |                key                 |         Description         |   mp3  | Cover Type (jpg) |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate                |  Mandatory  |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Channel count                |  Mandatory  |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format         |  Optional  |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout              |  Optional  |   -   |
   | OH_MD_KEY_BITRATE                  | Bitrate                  |  Optional  |   -   |
   | OH_MD_KEY_WIDTH                    | Width                  |   -   |  Mandatory  |
   | OH_MD_KEY_HEIGHT                   | Height                  |   -   |  Mandatory  |

wav container format:

   |                key                 |         Description        | g711mu  | raw  |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate.               |  Mandatory |  Mandatory |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Audio channel count.               |  Mandatory |  Mandatory |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format.        |  Optional |  Mandatory |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout.             |  Optional |  Optional |
   | OH_MD_KEY_BITRATE                  | Bit rate.                 |  Mandatory |  Optional |

aac container format:

   |                key                 |         Description        |  aac   |
   | ---------------------------------- | :------------------: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate.               |  Mandatory |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Audio channel count.               |  Mandatory |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format.        |  Optional |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout.             |  Optional |
   | OH_MD_KEY_BITRATE                  | Bit rate.                 |  Optional |
   | OH_MD_KEY_PROFILE                  | Encoding profile.             |  Mandatory |
   | OH_MD_KEY_AAC_IS_ADTS              | Whether the format is ADTS.       |  Mandatory |

flac container format:

   |                key                 |         Description         |  flac   | Cover Type (jpg, png, bmp) |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate                |  Mandatory  |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Channel count                |  Mandatory  |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format         |  Mandatory  |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout              |  Optional  |   -   |
   | OH_MD_KEY_BITRATE                  | Bitrate                  |  Optional  |   -   |
   | OH_MD_KEY_CODEC_CONFIG             | Codec specific data       |  Optional  |   -   |
   | OH_MD_KEY_WIDTH                    | Width                  |   -   |  Mandatory  |
   | OH_MD_KEY_HEIGHT                   | Height                  |   -   |  Mandatory  |

ogg container format (supported since API version 23):

   |                key                 |         Description        | Vorbis |  OPUS  |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate.               |  Mandatory |  Mandatory |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Audio channel count.               |  Mandatory |  Mandatory |
   | OH_MD_KEY_CODEC_CONFIG             | Codec-specific data.      |  Mandatory |  Mandatory |

flv multiplexing format (supported since API version 26.0.0):

<!--RP18-->

   |                key                 |         Description         |   aac  |  H.264  |  H.265  |
   | ---------------------------------- | :------------------: | :----: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate                |  Mandatory  |   -    |   -    |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Channel count                |  Mandatory  |   -    |   -    |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout              |  Optional  |   -    |   -    |
   | OH_MD_KEY_PROFILE                  | Encoding profile              |  Optional  |   -    |   -    |
   | OH_MD_KEY_BITRATE                  | Bitrate                  |  Optional  |  Optional  |  Optional  |
   | OH_MD_KEY_CODEC_CONFIG             | Codec specific data       |  Optional  |  Optional  |  Optional  |
   | OH_MD_KEY_WIDTH                    | Width                  |   -   |  Mandatory  |  Mandatory  |
   | OH_MD_KEY_HEIGHT                   | Height                  |   -   |  Mandatory  |  Mandatory  |
   | OH_MD_KEY_FRAME_RATE               | Video stream frame rate            |   -   |  Optional  |  Optional  |
   | OH_MD_KEY_COLOR_PRIMARIES          | Video color gamut              |   -   |  Optional  |  Optional  |
   | OH_MD_KEY_TRANSFER_CHARACTERISTICS | Video transfer characteristics          |   -   |  Optional  |  Optional  |
   | OH_MD_KEY_MATRIX_COEFFICIENTS      | Video matrix coefficients          |   -   |  Optional  |  Optional  |
   | OH_MD_KEY_RANGE_FLAG               | Value domain flag              |   -   |  Optional  |  Optional  |

<!--RP18End-->

For details about the development guide, see [Media Data Multiplexing](audio-video-muxer.md).