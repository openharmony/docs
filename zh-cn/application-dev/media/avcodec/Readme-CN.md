# AVCodec Kit（音视频编解码服务）

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @rchdlee-->
<!--Designer: @dpy2650-->
<!--Tester: @cyakee; @baotianhao-->
<!--Adviser: @w_Machine_cc-->

- [AVCodec Kit简介](avcodec-kit-intro.md)
- [AVCodec支持的格式](avcodec-support-formats.md)
- 音视频编解码<!--audio-video-codec-->
  - [获取支持的编解码能力](obtain-supported-codecs.md)
  - [音频编码](audio-encoding.md)
  - [音频编码同步模式](synchronous-audio-encoding.md)
  - [音频解码](audio-decoding.md)
  - [音频解码同步模式](synchronous-audio-decoding.md)
  - [视频编码](video-encoding.md)
  - [视频编码同步模式](synchronous-video-encoding.md)
  - [时域可分层视频编码](video-encoding-temporal-scalability.md)
  - [B帧视频编码](video-encoding-b-frame.md)
  - [典型场景的视频编码配置](video-encoding-configuration-typical-scenarios.md)
  - [ROI视频编码](video-encoding-ROI.md)
  - [编码支持一入二出](video-encoding-preproc-one-in-dual-out.md)
  - [编码支持前处理](video-encoding-preproc.md)
  - [视频解码](video-decoding.md)
  - [视频解码同步模式](synchronous-video-decoding.md)
  - [智能流畅倍速解码](video-smart-fluency-decoding.md)
  - [视频可变帧率](video-variable-refreshrate.md)<!--RP1--><!--RP1End--><!--RP3--><!--RP3End-->
- 媒体数据封装与解封装<!--file-muxing-demuxing-->
  - [媒体数据封装](audio-video-muxer.md)
  - [媒体数据解封装](audio-video-demuxer.md)<!--RP2--><!--RP2End-->
- AVCodec Kit常见问题<!--file-avcodec-kit-faq-->
  - [创建视频解码器和NativeWindow初始化并行](parallel-decoding-nativeWindow.md)
  - [视频编解码宽高、跨距与裁剪信息说明](video-dimension-guide.md)
