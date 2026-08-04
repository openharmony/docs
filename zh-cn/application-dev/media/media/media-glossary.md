# Media Kit术语

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @zengxi_3007-->
<!--Adviser: @w_Machine_cc-->

## A

### Audio Focus；音频焦点

  系统音频管理的策略机制。当多个应用同时播放音频时，系统通过音频焦点控制播放优先级，避免音频冲突。AVPlayer通过AudioInterruptMode配置焦点处理策略。

### AVImageGenerator；视频帧生成器

  用于从视频资源中提取指定时间点图像的工具。通过输入视频文件和时间参数，输出PixelMap格式的缩略图或视频帧。适用于生成视频预览图、关键帧提取等场景。

### AVMetadata；元数据

  描述音视频资源属性信息的结构体。包含标题、艺术家、专辑名称、时长、视频宽度、视频高度等字段，用于获取媒体资源的基本信息。

### AVMetadataExtractor；元数据提取器

  用于从音视频资源中提取元数据和专辑封面的工具。支持获取音频的标题、时长、艺术家等信息以及专辑封面图片，以及支持视频缩略图的批量提取。适用于媒体文件信息展示场景。

### AVPlayer；播放器

  提供端到端播放能力的组件，支持播放各种音视频格式（如mp4、mp3、mkv）。将媒体资源转码为可渲染的图像和音频信号，通过输出设备播放。支持流媒体播放（HLS、DASH、HTTP-FLV）、字幕添加、倍速播放等功能。

### AVRecorder；录制器

  集成音频捕获、音频编码、视频编码、音视频封装功能的组件。用于录制音视频并生成本地媒体文件，支持配置编码格式、封装格式、比特率、分辨率等参数。适用于相机录制、音频录制等场景。

### AVScreenCapture；屏幕捕获

  用于捕获设备屏幕音视频数据的组件。支持捕获主屏、指定屏幕或指定窗口，可采集麦克风音频和系统播放音频，输出形式包括文件保存和原始码流。适用于屏幕录制、会议共享、直播等场景。

### AVScreenCaptureRecorder；屏幕录制器

  ArkTS接口提供的屏幕录制组件。通过配置录制参数启动屏幕录制，生成音视频文件，支持麦克风和系统音频采集。适用于需要简单屏幕录制并生成文件的场景。

### AVTranscoder；视频转码器

  用于将已压缩编码的视频文件按照指定参数转换为另一种格式视频的工具。支持修改音视频编码格式、比特率、封装格式等参数。适用于视频压缩、格式转换、兼容性适配等场景。

## D

### Dynamic Adaptive Streaming over HTTP(DASH)；基于HTTP的动态自适应流

  一种基于HTTP的自适应流媒体传输协议，通过MPD（Media Presentation Description）文件描述多个不同码率的媒体片段，播放器可根据网络状况动态切换码率。适用于网络点播场景。

## H

### HDR；高动态范围

  一种视频显示技术，通过扩展亮度和色彩范围提供更真实的画面效果。Media Kit支持HDR Vivid视频的采集与播放，为用户带来更丰富的视觉体验。

### HTTP Live Streaming(HLS)；HTTP实时流式传输

  一种基于HTTP的自适应流媒体传输协议。通过M3U8索引文件描述媒体片段，支持直播和点播，播放器可根据网络状况自动切换不同码率的视频流。适用于网络直播和点播场景。

## I

### Inner Audio Capture；内录音频

  录制设备内部播放的音频数据。通过OH_ALL_PLAYBACK音频源捕获系统播放的声音，用于屏幕录制时同时录制系统音频。

## L

### LowPowerPlayer(LPP)；低功耗播放器

  一种通过低功耗实现从媒体源到渲染的视频播放通路能力。适用于需要长时间播放视频且对功耗敏感的场景，不支持纯视频和纯音频播放。

### LowPowerAudioSink；低功耗音频渲染器

  LPP播放器的音频渲染组件。负责音频数据的低功耗解码和渲染，支持音量调节、倍速播放、暂停恢复等播放控制操作。

### LowPowerVideoSink；低功耗视频渲染器

  LPP播放器的视频渲染组件。负责视频数据的低功耗解码和渲染，通过Surface设置显示窗口，支持倍速播放、暂停恢复等播放控制操作。

## M

### Media Kit；媒体服务套件

  提供音视频播放、录制、转码等媒体能力的开发套件。包含AVPlayer/AVRecorder/AVScreenCapture/AVMetadataExtractor/AVImageGenerator/AVTranscoder/SoundPool等模块、使用轻量媒体引擎支持音视频播放/录制、支持HDR视频/音频池等特性。

### MediaSource；媒体源

  描述媒体来源的结构体，包含URL和HTTP请求头信息。用于设置在线媒体资源来源。支持通过createMediaSourceWithUrl创建并配置请求头。

### Media Presentation Description(MPD)；媒体描述文件

  MPD是DASH协议中使用的媒体描述文件，采用XML格式，描述了媒体内容的各个片段、不同码率的媒体流以及它们之间的关系。播放器通过解析MPD文件来获取可用的媒体轨道信息并根据网络状况动态选择合适的码率进行播放。

### Mic Audio Capture；麦克风音频

  通过麦克风捕获外部音频数据，通过OH_MIC音频源录制环境声音。用于音频录制、屏幕录制等场景的音频采集。

### MPEG version 3 URL UTF-8 encoding(M3U8)；播放列表文件格式

  M3U8文件是HLS协议中使用的媒体播放列表文件，采用UTF-8编码。用于索引和描述多个媒体片段的播放顺序。

## P

### PixelMap；像素图

  图像数据的对象。包含像素信息、宽高、格式等属性，用于图片显示和处理。AVImageGenerator和AVMetadataExtractor输出的缩略图以PixelMap格式返回。

### Player Framework；播放服务框架

  系统层的播放服务框架。负责解析媒体资源、解码音视频数据、输出至音频服务和图形服务。AVPlayer和SoundPool通过Player Framework实现播放能力。

## S

### SoundPool；音频池

  用于播放短音效的组件，支持一次加载多次低时延播放。适用于相机快门音效、系统通知音效等急促简短的音效场景。当前支持播放解码后1MB以下的音频资源。

### Streaming Media；流媒体

  通过网络实时传输的音视频内容，支持边下载边播放，包括直播和点播两种形式。常用协议包括HLS、DASH、HTTP-FLV。

## T

### TrackDescription；轨道描述

  描述媒体文件中各个轨道信息的列表。包含视频轨道、音频轨道、字幕轨道的索引、类型、分辨率等信息。用于DASH流的轨道选择和切换。
