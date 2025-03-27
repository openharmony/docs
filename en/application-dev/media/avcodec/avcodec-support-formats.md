# AVCodec Supported Formats

## Media Codec

### Video Decoding

Currently, the following decoding capabilities are supported:

| Video Hardware Decoding Type      | Video Software Decoding Type  |
| --------------------- | ---------------- |
| AVC (H.264) and HEVC (H.265)<!--RP14--><!--RP14End--> | MPEG2, MPEG4, and AVC (H.264)<!--RP12--><!--RP12End--> |

Video software decoding and hardware decoding are different. When a decoder is created based on the MIME type, <!--RP13-->only MPEG2 (OH_AVCODEC_MIMETYPE_VIDEO_MPEG2), MPEG4 (OH_AVCODEC_MIMETYPE_VIDEO_MPEG4_PART2), and H.264 (OH_AVCODEC_MIMETYPE_VIDEO_AVC) are supported for software decoding, <!--RP13End--><!--RP15-->and H.264 (OH_AVCODEC_MIMETYPE_VIDEO_AVC) and H.265 (OH_AVCODEC_MIMETYPE_VIDEO_HEVC)<!--RP15End--> can be used for hardware decoding as long as they are supported by the hardware platform.

For details about the range of each decoding capability, see [Obtaining Supported Codecs](obtain-supported-codecs.md).

For details about the development guide, see [Video Decoding](video-decoding.md).

### Video Encoding

Currently, the following encoding capabilities are supported:

| Video Encoding Type                |
| ---------------------------- |
| HEVC (H.265) and AVC (H.264)|

Only hardware encoding is supported. When an encoder is created based on the MIME type, H.264 (OH_AVCODEC_MIMETYPE_VIDEO_AVC) and H.265 (OH_AVCODEC_MIMETYPE_VIDEO_HEVC) are supported.

For details about the range of each encoding capability, see [Obtaining Supported Codecs](obtain-supported-codecs.md).

For details about the development guide, see [Video Encoding](video-encoding.md).


### Audio Decoding

Currently, the following decoding capabilities are supported:

AAC, MPEG (MP3), FLAC, Vorbis, AMR (AMR-NB and AMR-WB), G.711Mu, APE<!--RP1--><!--RP1End-->

For details about the development guide, see [Audio Decoding](audio-decoding.md).


### Audio Encoding

Currently, the following encoding capabilities are supported:

AAC, FLAC, MP3, G.711Mu<!--RP3--><!--RP3End-->

For details about the development guide, see [Audio Encoding](audio-encoding.md).


## Media Data Muxing and Demuxing

### Media Data Demuxing

The following container formats are supported:

| Media Format | Container Format                     | Stream Format                     |
| -------- | :----------------------------| :----------------------------|
| Audio/Video    | mp4                        |<!--RP4-->Video stream: AVC (H.264) and MPEG4; audio stream: AAC and MPEG (MP3); subtitle stream: WEBVTT<!--RP4End-->|
| Audio/Video    | fmp4                       |<!--RP5-->Video stream: AVC (H.264); audio stream: AAC and MPEG (MP3)<!--RP5End-->|
| Audio/Video    | mkv                        |<!--RP6-->Video stream: AVC (H.264); audio stream: AAC, MPEG (MP3), and OPUS<!--RP6End-->|
| Audio/Video    | mpeg-ts                    |<!--RP7-->Video stream: AVC (H.264), MPEG2, and MPEG4; audio stream: AAC and MPEG (MP3)<!--RP7End-->|
| Audio/Video    | flv                        |<!--RP8-->Video stream: AVC (H.264); audio stream: AAC<!--RP8End-->|
| Audio/Video    | mpeg-ps                    |Video stream: AVC (H.264) and MPEG2; audio stream: MPEG (MP2 and MP3)|
| Audio/Video    | avi                        |Video stream: H.263, AVC (H.264), MPEG2, and MPEG4; audio stream: AAC, MPEG (MP2 and MP3), and PCM|
| Audio      | m4a                        |<!--RP9-->Audio stream: AAC<!--RP9End-->|
| Audio      | aac                        |Audio stream: AAC|
| Audio      | mp3                        |Audio stream: MPEG (MP3)|
| Audio      | ogg                        |Audio stream: Vorbis|
| Audio      | flac                       |Audio stream: FLAC|
| Audio      | wav                        |Audio stream: PCM and G.711Mu|
| Audio      | amr                        |Audio stream: AMR (AMR-NB and AMR-WB)|
| Audio      | ape                        |Audio stream: APE|
| External subtitle  | srt                        |Subtitle stream: SRT|
| External subtitle  | webvtt                     |Subtitle stream: WEBVTT|

The DRM demuxing capability supports the following formats: <!--RP10-->mp4 (H.264 and AAC) and mpeg-ts (H.264 and AAC)<!--RP10End-->.

For details about the development guide, see [Media Data Demuxing](audio-video-demuxer.md).


### Media Data Muxing

Currently, the following muxer capabilities are supported:

| Container Format| Video Codec Type       | Audio Codec Type  | Cover Type      |
| -------- | --------------------- | ---------------- | -------------- |
| mp4      | AVC (H.264) <!--RP11--><!--RP11End-->    | AAC, MPEG (MP3)| jpeg, png, bmp|
| m4a      | -                     | AAC              | jpeg, png, bmp|
| mp3      | -                     | MPEG (MP3)     | -              |
| amr      | -                     | AMR (AMR-NB and AMR-WB)| -             |
| wav      | -                     | G711mu(pcm-mulaw) | -             |
| aac      | -                     | AAC               | -             |

> **NOTE**
>
> - When the container format is MP4 and the audio codec type is MPEG (MP3), the sampling rate must be greater than or equal to 16000 Hz. 
> - When the container format is MP4 or M4A and the audio codec type is AAC, the number of audio channels ranges from 1 to 7.

Key values of configuration options are described as follows: 

mp4 container format
   |                key                 |         Description        |   aac  |   mp3  |  H.264  |  H.265  |  jpg   |  png   |  bmp   |
   | ---------------------------------- | :------------------: | :----: | :----: | :----: | :----: | :----: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sampling rate               |  Mandatory |  Mandatory |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Number of audio channels               |  Mandatory |  Mandatory |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format        |  Optional |  Optional |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout             |  Optional |  Optional |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_PROFILE                  | Encoding profile             |  Optional |   -   |   -    |   -    |   -   |   -   |   -   |
   | OH_MD_KEY_BITRATE                  | Bit rate                 |  Optional |  Optional |  Optional |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_CODEC_CONFIG             | Codec-specific data      |  Optional |   -   |  Optional |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_WIDTH                    | Width                 |   -   |   -   |  Mandatory |  Mandatory |  Mandatory |  Mandatory |  Mandatory |
   | OH_MD_KEY_HEIGHT                   | Height                 |   -   |   -   |  Mandatory |  Mandatory |  Mandatory |  Mandatory |  Mandatory |
   | OH_MD_KEY_FRAME_RATE               | Video stream frame rate           |   -   |   -   |  Optional |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_COLOR_PRIMARIES          | Video color gamut             |   -   |   -   |  Optional |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_TRANSFER_CHARACTERISTICS | Video transfer function         |   -   |   -   |  Optional |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_MATRIX_COEFFICIENTS      | Video matrix coefficient         |   -   |   -   |  Optional |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_RANGE_FLAG               | Value range flag             |   -   |   -   |  Optional |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_VIDEO_IS_HDR_VIVID       | Whether the video track is an HDR Vivid|   -   |   -   |   -    |  Optional |   -   |   -   |   -   |

m4a container format
   |                key                 |         Description        |   aac  |  jpg   |  png   |  bmp   |
   | ---------------------------------- | :------------------: | :----: | :----: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sampling rate               |  Mandatory  |   -   |   -   |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Number of audio channels               |  Mandatory  |   -   |   -   |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format        |  Optional  |   -   |   -   |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout             |  Optional  |   -   |   -   |   -   |
   | OH_MD_KEY_PROFILE                  | Encoding profile             |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_BITRATE                  | Bit rate                 |  Optional  |   -   |   -   |   -   |
   | OH_MD_KEY_CODEC_CONFIG             | Codec-specific data      |  Optional |   -   |   -   |   -   |
   | OH_MD_KEY_WIDTH                    | Width                 |   -   |  Mandatory |  Mandatory |  Mandatory |
   | OH_MD_KEY_HEIGHT                   | Height                 |   -   |  Mandatory |  Mandatory |  Mandatory |

amr container format
   |                key                 |         Description        | amr_nb | amr_wb |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sampling rate               |  Mandatory |  Mandatory |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Number of audio channels               |  Mandatory |  Mandatory |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format        |  Optional |  Optional |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout             |  Optional |  Optional |
   | OH_MD_KEY_BITRATE                  | Bit rate                 |  Optional |  Optional |

mp3 container format
   |                key                 |         Description        |   mp3  |  jpg   |
   | ---------------------------------- | :------------------: | :----: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sampling rate               |  Mandatory |   -   |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Number of audio channels               |  Mandatory |   -   |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format        |  Optional |   -   |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout             |  Optional |   -   |
   | OH_MD_KEY_BITRATE                  | Bit rate                 |  Optional |   -   |
   | OH_MD_KEY_WIDTH                    | Width                 |   -   |  Mandatory |
   | OH_MD_KEY_HEIGHT                   | Height                 |   -   |  Mandatory |

wav container format
   |                key                 |         Description        | g711mu  |
   | ---------------------------------- | :------------------: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sampling rate               |  Mandatory |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Number of audio channels               |  Mandatory |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format        |  Optional |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout             |  Optional |
   | OH_MD_KEY_BITRATE                  | Bit rate                 |  Mandatory |

aac container format
   |                key                 |         Description        |  aac   |
   | ---------------------------------- | :------------------: | :----: |
   | OH_MD_KEY_AUD_SAMPLE_RATE          | Sampling rate               |  Mandatory |
   | OH_MD_KEY_AUD_CHANNEL_COUNT        | Number of audio channels               |  Mandatory |
   | OH_MD_KEY_AUDIO_SAMPLE_FORMAT      | Output audio stream format        |  Optional |
   | OH_MD_KEY_CHANNEL_LAYOUT           | Channel layout             |  Optional |
   | OH_MD_KEY_BITRATE                  | Bit rate                 |  Optional |
   | OH_MD_KEY_PROFILE                  | Encoding profile             |  Mandatory |
   | OH_MD_KEY_AAC_IS_ADTS              | Whether the format is ADTS       |  Mandatory |
   
For details about the development guide, see [Media Data Muxing](audio-video-muxer.md).
