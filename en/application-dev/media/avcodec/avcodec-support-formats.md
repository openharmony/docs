# AVCodec Supported Formats

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran; @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

## Media Codec

### Video Decoding

Currently, the following decoding capabilities are supported:

| Video Hardware Decoding Type      | Video Software Decoding Type  |
| --------------------- | ---------------- |
| AVC (H.264), HEVC (H.265)<!--RP14--><!--RP14End--> | MPEG2, MPEG4, H.263, AVC (H.264)<!--RP12--><!--RP12End--> |

When you attempt to create a decoder using the MIME type, the system preferentially creates a hardware decoder instance. If the system platform does not support the hardware decoder or the hardware decoder resources are insufficient, the system creates a software decoder instance.

The system supports the following software decoder formats:
- MPEG2 (OH_AVCODEC_MIMETYPE_VIDEO_MPEG2)
- MPEG4 (OH_AVCODEC_MIMETYPE_VIDEO_MPEG4_PART2)
- H.263 (OH_AVCODEC_MIMETYPE_VIDEO_H263)
- H.264 (OH_AVCODEC_MIMETYPE_VIDEO_AVC)
<!--RP13--><!--RP13End-->

The hardware decoding capability provided by the system is closely related to the platform hardware capability. You can obtain the hardware decoding capability and capability specifications of the system by following the instructions provided in [Obtaining Supported Codecs](obtain-supported-codecs.md).

For example, you can query the <!--RP16-->hardware decoding capabilities of H.264 and H.265<!--RP16End--> by using <!--RP15-->**OH_AVCODEC_MIMETYPE_VIDEO_AVC** and **OH_AVCODEC_MIMETYPE_VIDEO_HEVC**<!--RP15End-->.

For details about the development guide, see [Video Decoding](video-decoding.md).

### Video Encoding

Currently, the following encoding capabilities are supported:

| Video Encoding Type                |
| ---------------------------- |
| HEVC (H.265), AVC (H.264)|

Only hardware encoding is supported. When an encoder is created based on the MIME type, H.264 (OH_AVCODEC_MIMETYPE_VIDEO_AVC) and H.265 (OH_AVCODEC_MIMETYPE_VIDEO_HEVC) are supported.

For details about the range of each encoding capability, see [Obtaining Supported Codecs](obtain-supported-codecs.md).

For details about the development guide, see [Video Encoding](video-encoding.md).


### Audio Decoding

Currently, the following decoding capabilities are supported:

AAC, MPEG (MP3), FLAC, Vorbis, AMR (AMR-NB and AMR-WB), G711mu, APE, G711a<!--RP1--><!--RP1End-->

For details about the development guide, see [Audio Decoding](audio-decoding.md).


### Audio Encoding

Currently, the following encoding capabilities are supported:

AAC, FLAC, MP3, G711mu<!--RP3--><!--RP3End-->

For details about the development guide, see [Audio Encoding](audio-encoding.md).


## Media Data Multiplexing and Demultiplexing

### Media Data Demultiplexing

The following formats are supported:

| Media Format | Container Format                     | Track Format                     |
| -------- | :----------------------------| :----------------------------|
| Audio/Video    | mp4                        |<!--RP4-->Video track: AVC (H.264), MPEG4<br>Audio track: AAC, MPEG (MP3)<br>Subtitle track: WEBVTT<br>Auxiliary track: AUXL (AAC, MP3)<br>Timed metadata track<!--RP4End-->|
| Audio/Video    | fmp4                       |<!--RP5-->Video track: AVC (H.264)<br>Audio track: AAC, MPEG (MP3)<!--RP5End-->|
| Audio/Video    | mkv                        |<!--RP6-->Video track: AVC (H.264)<br>Audio track: AAC, MPEG (MP3), OPUS<!--RP6End-->|
| Audio/Video    | mpeg-ts                    |<!--RP7-->Video track: AVC (H.264), MPEG2, MPEG4<br>Audio track: AAC, MPEG (MP3)<!--RP7End-->|
| Audio/Video    | flv                        |<!--RP8-->Video track: AVC (H.264)<br>Audio track: AAC<!--RP8End-->|
| Audio/Video    | mpeg-ps                    |Video track: AVC (H.264), MPEG2<br>Audio track: MPEG (MP2, MP3)|
| Audio/Video    | avi                        |Video track: H.263, AVC (H.264), MPEG2, MPEG4<br>Audio track: AAC, MPEG (MP2, MP3), PCM|
| Audio      | m4a                        |<!--RP9-->Audio track: AAC<!--RP9End-->|
| Audio      | aac                        |Audio track: AAC|
| Audio      | mp3                        |Audio track: MPEG (MP3)|
| Audio      | ogg                        |Audio track: Vorbis|
| Audio      | flac                       |Audio track: FLAC|
| Audio      | wav                        |Audio track: PCM, G711mu, G711a|
| Audio      | amr                        |Audio track: AMR (amrnb and amrwb)|
| Audio      | ape                        |Audio track: APE|
| External subtitle  | srt                        |Subtitle track: SRT|
| External subtitle  | webvtt                     |Subtitle track: WEBVTT|

The DRM demultiplexing capability supports the following formats: <!--RP10-->mp4 (H.264 and AAC) and mpeg-ts (H.264 and AAC)<!--RP10End-->.

For details about the development guide, see [Media Data Demultiplexing](audio-video-demuxer.md).


### Media Data Multiplexing

Currently, the following muxer capabilities are supported:

| Container Format| Video Codec Type       | Audio Codec Type  | Cover Type      |
| -------- | --------------------- | ---------------- | -------------- |
| mp4      | AVC (H.264) <!--RP11--><!--RP11End-->    | AAC, MPEG (MP3)| jpeg, png, bmp|
| m4a      | -                     | AAC              | jpeg, png, bmp|
| mp3      | -                     | MPEG (MP3)     | -              |
| amr      | -                     | AMR (AMR-NB and AMR-WB)| -             |
| wav      | -                     | G711mu (pcm-mulaw), raw (pcm)| -             |
| aac      | -                     | AAC               | -             |
| flac     | -                     | Flac              | jpeg, png, bmp|

> **NOTE**
>
> - When the container format is mp4 and the audio codec type is MPEG (MP3), the sample rate must be greater than or equal to 16000 Hz. 
> - When the container format is mp4 or m4a and the audio codec type is AAC, the number of audio channels ranges from 1 to 7.

Key values of configuration options are described as follows: 

mp4 container format:
   |                key                 |         Description        |   aac  |   mp3  |  H.264  |  H.265  |  jpg   |  png   |  bmp   |
   | ---------------------------------- | :------------------: | :----: | :----: | :----: | :----: | :----: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate.               |  Mandatory |  Mandatory |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Audio channel count.               |  Mandatory |  Mandatory |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format.        |  Optional |  Optional |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout.             |  Optional |  Optional |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_PROFILE                  | Encoding profile.             |  Optional |   -   |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_BITRATE                  | Bit rate.                 |  Optional |  Optional |  Optional |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_CODEC_CONFIG             | Codec-specific data.      |  Optional |   -   |  Optional |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_WIDTH                    | Width.                 |   -   |   -   |  Mandatory |  Mandatory |  Mandatory |  Mandatory |  Mandatory |
   | OH_MD_KEY_HEIGHT                   | Height.                 |   -   |   -   |  Mandatory |  Mandatory |  Mandatory |  Mandatory |  Mandatory |
   | OH_MD_KEY_FRAME_RATE               | Video stream frame rate.           |   -   |   -   |  Optional |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_COLOR_PRIMARIES          | Video color gamut.             |   -   |   -   |  Optional |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_TRANSFER_CHARACTERISTICS | Video transfer characteristics function.         |   -   |   -   |  Optional |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_MATRIX_COEFFICIENTS      | Video matrix coefficient.         |   -   |   -   |  Optional |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_RANGE_FLAG               | Value range flag.             |   -   |   -   |  Optional |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_VIDEO_IS_HDR_VIVID       | Whether the video track is an HDR Vivid.|   -   |   -   |   -    |  Optional |   -   |   -   |   -   |

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
   |                key                 |         Description        |   aac  |  jpg   |  png   |  bmp   |
   | ---------------------------------- | :------------------: | :----: | :----: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate.               |  Mandatory  |   -   |   -   |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Audio channel count.               |  Mandatory  |   -   |   -   |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format.        |  Optional  |   -   |   -   |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout.             |  Optional  |   -   |   -   |   -   |
   | OH_MD_KEY_PROFILE                  | Encoding profile.             |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_BITRATE                  | Bit rate.                 |  Optional  |   -   |   -   |   -   |
   | OH_MD_KEY_CODEC_CONFIG             | Codec-specific data.      |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_WIDTH                    | Width.                 |   -   |  Mandatory |  Mandatory |  Mandatory |
   | OH_MD_KEY_HEIGHT                   | Height.                 |   -   |  Mandatory |  Mandatory |  Mandatory |

amr container format:
   |                key                 |         Description        | amr_nb | amr_wb |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate.               |  Mandatory |  Mandatory |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Audio channel count.               |  Mandatory |  Mandatory |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format.        |  Optional |  Optional |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout.             |  Optional |  Optional |
   | OH_MD_KEY_BITRATE                  | Bit rate.                 |  Optional |  Optional |

mp3 container format:
   |                key                 |         Description        |   mp3  |  jpg   |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate.               |  Mandatory |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Audio channel count.               |  Mandatory |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format.        |  Optional |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout.             |  Optional |   -   |
   | OH_MD_KEY_BITRATE                  | Bit rate.                 |  Optional |   -   |
   | OH_MD_KEY_WIDTH                    | Width.                 |   -   |  Mandatory |
   | OH_MD_KEY_HEIGHT                   | Height.                 |   -   |  Mandatory |

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
   |                key                 |         Description        |  flac   |
   | ---------------------------------- | :------------------: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sample rate.               |  Mandatory |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Audio channel count.               |  Mandatory |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format.        |  Mandatory |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout.             |  Optional |
   | OH_MD_KEY_BITRATE                  | Bit rate.                 |  Optional |
   | OH_MD_KEY_CODEC_CONFIG             | Codec-specific data.      |  Optional |
   
For details about the development guide, see [Media Data Multiplexing](audio-video-muxer.md).
