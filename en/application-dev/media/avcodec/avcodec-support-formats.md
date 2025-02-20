# AVCodec Supported Formats

## Media Codec

### Video Decoding

Currently, the following decoding capabilities are supported:

| Video Hardware Decoding Type      | Video Software Decoding Type  |
| --------------------- | ---------------- |
| AVC (H.264) and HEVC (H.265)|AVC (H.264)<!--RP12--><!--RP12End--> |

Video software decoding and hardware decoding are different. When a decoder is created based on the MIME type, <!--RP13-->only H.264 (OH_AVCODEC_MIMETYPE_VIDEO_AVC) is supported for software decoding,<!--RP13End--> and H.264 (OH_AVCODEC_MIMETYPE_VIDEO_AVC) and H.265 (OH_AVCODEC_MIMETYPE_VIDEO_HEVC) can be used for hardware decoding as long as they are supported by the hardware platform.

For details about the range of each decoding capability, see [Obtaining Supported Codecs](obtain-supported-codecs.md).

For details about the development guide, see [Video Decoding](video-decoding.md).

### Video Encoding

Currently, the following encoding capabilities are supported:

| Container Format| Video Encoding Type                |
| -------- | ---------------------------- |
| mp4      | HEVC (H.265) and AVC (H.264)|

Only hardware encoding is supported. When an encoder is created based on the MIME type, H.264 (OH_AVCODEC_MIMETYPE_VIDEO_AVC) and H.265 (OH_AVCODEC_MIMETYPE_VIDEO_HEVC) are supported.

For details about the range of each encoding capability, see [Obtaining Supported Codecs](obtain-supported-codecs.md).

For details about the development guide, see [Video Encoding](video-encoding.md).


### Audio Decoding

Currently, the following decoding capabilities are supported:

| Container Format| Audio Decoding Type                |
| -------- | :--------------------------- |
| mp4      | AAC, MPEG (MP3), FLAC, Vorbis<!--RP1--><!--RP1End--> |
| m4a      | AAC                          |
| flac     | Flac                         |
| ogg      | Vorbis<!--RP2--><!--RP2End-->    |
| aac      | AAC                          |
| mp3      | MPEG (MP3)                    |
| amr      | AMR (AMR-NB and AMR-WB)           |
| raw      | G711mu                       |
| ape      | APE                          |

For details about the development guide, see [Audio Decoding](audio-decoding.md).


### Audio Encoding

Currently, the following encoding capabilities are supported:

| Container Format| Audio Encoding Type      |
| -------- | :--------------- |
| mp4      | AAC, FLAC       |
| m4a      | AAC              |
| flac     | Flac             |
| aac      | AAC              |
| mp3      | MP3              |
| raw      | G711mu           |
<!--RP3--><!--RP3End-->

For details about the development guide, see [Audio Encoding](audio-encoding.md).


## Media Data Muxing and Demuxing

### Media Data Demuxing

The following demuxing formats are supported:

| Media Format | Muxing Format                     | Stream Format                     |
| -------- | :----------------------------| :----------------------------|
| Audio/Video    | mp4                        |<!--RP4-->Video stream: AVC (H.264); audio stream: AAC and MPEG (MP3); subtitle stream: WEBVTT<!--RP4End-->|
| Audio/Video    | fmp4                       |<!--RP5-->Video stream: AVC (H.264); audio stream: AAC and MPEG (MP3)<!--RP5End-->|
| Audio/Video    | mkv                        |<!--RP6-->Video stream: AVC (H.264); audio stream: AAC, MPEG (MP3), and OPUS<!--RP6End-->|
| Audio/Video    | mpeg-ts                    |<!--RP7-->Video stream: AVC (H.264); audio stream: AAC and MPEG (MP3)<!--RP7End-->|
| Audio/Video    | flv                        |<!--RP8-->Video stream: AVC (H.264); audio stream: AAC<!--RP8End-->|
| Audio      | m4a                        |<!--RP9-->Audio stream: AAC<!--RP9End-->|
| Audio      | aac                        |Audio stream: AAC|
| Audio      | mp3                        |Audio stream: MPEG (MP3)|
| Audio      | ogg                        |Audio stream: OGG|
| Audio      | flac                       |Audio stream: FLAC|
| Audio      | wav                        |Audio stream: PCM and PCM-MULAW|
| Audio      | amr                        |Audio stream: AMR (AMR-NB and AMR-WB)|
| Audio      | ape                        |Audio stream: APE|
| External subtitle  | srt                        |Subtitle stream: SRT|
| External subtitle  | webvtt                     |Subtitle stream: WEBVTT|

The DRM demuxing capability supports the following formats: <!--RP10-->mp4 (H.264 and AAC) and mpeg-ts (H.264 and AAC)<!--RP10End-->.

For details about the development guide, see [Media Data Demuxing](audio-video-demuxer.md).


### Media Data Muxing

Currently, the following muxer capabilities are supported:

| Muxing Format| Video Codec Type       | Audio Codec Type  | Cover Type      |
| -------- | --------------------- | ---------------- | -------------- |
| mp4      | AVC (H.264) <!--RP11--><!--RP11End-->    | AAC, MPEG (MP3)| jpeg, png, bmp|
| m4a      | -                     | AAC              | jpeg, png, bmp|
| mp3      | -                     | MPEG (MP3)     | -              |
| amr      | -                     | AMR (AMR-NB and AMR-WB)| -             |
| wav      | -                     | G711mu(pcm-mulaw) | -             |

> **NOTE**
>
> - When the container format is MP4 and the audio codec type is MPEG (MP3), the sampling rate must be greater than or equal to 16000 Hz. 
> - When the container format is MP4 or M4A and the audio codec type is AAC, the number of audio channels ranges from 1 to 7.

For details about the development guide, see [Media Data Muxing](audio-video-muxer.md).
