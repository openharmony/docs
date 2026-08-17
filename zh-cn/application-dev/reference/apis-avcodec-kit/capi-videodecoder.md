# VideoDecoder
<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @rchdlee-->
<!--Designer: @dpy2650-->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->

## 概述

VideoDecoder模块提供用于视频解码的函数。

本模块提供的主要能力包括：

- **解码器创建与销毁**：根据MIME类型或解码器名称创建视频解码器实例，销毁解码器实例释放资源。
- **解码参数配置**：配置解码视频的描述信息（分辨率、帧率、像素格式等），设置输出Surface，设置DRM解密配置。
- **异步回调机制**：注册回调函数，响应解码器生成的错误、流变化、输入缓冲区请求、输出缓冲区就绪等事件。
- **解码控制**：启动、停止、刷新、重置解码器，控制解码流程状态。
- **输入输出处理**：提交填充数据的输入缓冲区，释放或渲染输出缓冲区，支持Buffer模式和Surface模式。
- **同步模式支持**：查询并获取可用的输入输出缓冲区，实现同步解码流程。
- **动态参数设置**：在解码运行时设置解码器动态参数。
- **DRM 解密支持**：配置DRM会话，支持安全视频通路和非安全视频通路。

适用场景包括：播放本地视频文件、网络视频流解码、视频通话、视频会议、视频录制回放、受DRM保护的视频内容解码等需要将压缩视频码流解码为原始帧数据的场景。

对应的开发指南及样例可参考[视频解码](../../media/avcodec/video-decoding.md)。

**系统能力：** SystemCapability.Multimedia.Media.VideoDecoder

**起始版本：** 9

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [native_avcodec_videodecoder.h](capi-native-avcodec-videodecoder-h.md) | 声明用于视频解码的Native API。 |
