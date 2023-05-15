# 音视频概述

在音视频开发指导中，将介绍各种涉及音频、视频播放或录制功能场景的开发方式，指导开发者如何使用系统提供的音视频API实现对应功能。比如使用TonePlayer实现简单的提示音，当设备接收到新消息时，会发出短促的“滴滴”声；使用AVPlayer实现音乐播放器，循环播放一首音乐。

在每个功能中，会介绍多种实现方式以应对不同的使用场景，以及该场景相关的子功能点。比如在音频播放功能内，会同时介绍音频的并发策略、音量管理和输出设备等在操作系统中的处理方式，帮助开发者能够开发出功能覆盖更全面的应用。

本开发指导仅针对音视频播放或录制本身，由[@ohos.multimedia.audio](../reference/apis/js-apis-audio.md)（下文简称audio模块）和[@ohos.multimedia.media](../reference/apis/js-apis-media.md)（下文简称media模块）提供相关能力，不涉及UI界面、图形处理、媒体存储或其他相关领域功能。

## 开发说明

在开发音频功能之前，尤其是要实现处理音频数据的功能前，建议开发者先了解声学相关的知识，帮助理解操作系统提供的API是如何控制音频系统，从而开发出更易用、体验更好的音视频类应用。建议了解的相关概念包括但不限于：

- 音频量化的过程：采样 &gt; 量化 &gt; 编码

- 音频量化过程的相关概念：模拟信号和数字信号、采样率、声道、采样格式、位宽、码率、常见编码格式（如AAC、MP3、PCM、WMA等）、常见封装格式（如WAV、MPA、FLAC、AAC、OGG等）

在开发音乐、视频播放功能之前，建议了解流媒体播放的相关概念包括但不限于：

- 播放过程：网络协议 &gt; 容器格式 &gt; 音视频编解码 &gt; 图形/音频渲染

- 网络协议：比如HLS、HTTP/HTTPS；容器格式：比如mp4，mkv，mpeg-ts，webm。

- 编码格式：比如h263/h264/h265，MPEG4/MPEG2。

## 音频流介绍

在开发音频应用之前，还需要了解什么是音频流，它是OpenHarmony音频系统中的关键概念，在之后的章节中会多次提及。

音频流，是音频系统中对一个具备音频格式和音频使用场景信息的独立音频数据处理单元的定义，可以表示播放，也可以表示录制，并且具备独立音量调节和音频设备路由切换能力。

音频流基础信息通过[AudioStreamInfo](../reference/apis/js-apis-audio.md#audiostreaminfo8)表示，包含采样、声道、位宽、编码信息，是创建音频播放或录制流的必要参数，描述了音频数据的基本属性。在配置时开发者需要保证基础信息与传输的音频数据是相匹配的，音频系统才能正确处理数据。

### 音频流使用场景信息

除了基本属性，音频流还需要具备使用场景信息。基础信息只能对音频数据进行描述，但在实际的使用过程中，不同的音频流，在音量大小，设备路由，并发策略上是有区别的。系统就是通过音频流所附带的使用场景信息，为不同的音频流制定合适的处理策略，以达到更好的音频用户体验。

- 播放场景
  音频播放场景的信息，通过[StreamUsage](../reference/apis/js-apis-audio.md#streamusage)和[ContentType](../reference/apis/js-apis-audio.md#contenttype)进行描述。

  StreamUsage指音频流本身的用途类型，包括媒体、语音通信、语音播报、通知、铃声等。

  ContentType指音频流中数据的内容类型，包括语音、音乐、影视、通知、铃声等。

- 录制场景
  音频流录制场景的信息，通过[SourceType](../reference/apis/js-apis-audio.md#sourcetype8)进行描述。

  SourceType指音频流中录音源的类型，包括麦克风音频源、语音识别音频源、语音通话音频源等。

## 支持的音频格式

audio模块下的接口支持PCM编码，包括AudioRenderer、AudioCapturer、TonePlayer、OpenSL ES等。

音频格式说明：

- 支持的常用的音频采样率（Hz）：8000、11025、12000、16000、22050、24000、32000、44100、48000、64000、96000，具体参考枚举[AudioSamplingRate](../reference/apis/js-apis-audio.md#audiosamplingrate8)。
  不同设备支持的采样率规格会存在差异。

- 支持单声道、双声道，具体参考[AudioChannel](../reference/apis/js-apis-audio.md#audiochannel8)。

- 支持的采样格式：U8（无符号8位整数）、S16LE（带符号的16位整数，小尾数）、S24LE（带符号的24位整数，小尾数）、S32LE（带符号的32位整数，小尾数）、F32LE（带符号的32位浮点数，小尾数），具体参考[AudioSampleFormat](../reference/apis/js-apis-audio.md#audiosampleformat8)。
  由于系统限制，S24LE、S32LE、F32LE仅部分设备支持，请根据实际情况使用。

  小尾数指的是小端模式，即数据的高字节保存在内存的高地址中，而数据的低字节保存在内存的低地址中。这种存储模式将地址的高低和数据的位权有效结合起来，高地址部分权值高，低地址部分权值低。

media模块下的接口支持的音视频格式将在[AVPlayer和AVRecorder](avplayer-avrecorder-overview.md)的介绍中承载。
