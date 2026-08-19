# Core

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @rchdlee-->
<!--Designer: @dpy2650-->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->

## 概述

Core模块提供用于媒体系统的基础骨干能力，包含内存、错误码、媒体数据结构等相关函数。作为多媒体框架的骨干支撑，本模块定义了媒体数据在内存中的组织形式、音视频参数的标准化描述方式以及统一的错误码规范，为上层音视频编解码、封装解封装等业务提供公共基础能力。

本模块提供的主要能力包括：

- **媒体格式描述**：创建和管理OH_AVFormat实例，以键值对形式存储音视频参数，支持int、long、float、double、string、buffer等多种数据类型，提供音频/视频格式的快速创建接口。
- **媒体缓冲区管理**：创建和管理OH_AVBuffer实例，承载音视频数据及相关元数据，支持缓冲区属性（时间戳、大小、偏移、标记）的读写操作，支持扩展参数的传递。
- **音频声道布局**：定义从单声道到22.2声道的完整声道布局方案，支持立体声、环绕声、Ambisonics三维音频等多种配置。
- **Audio Vivid 元数据构建**：构建Audio Vivid三维音频编码所需的元数据，支持音频对象位置管理、增益控制、对象增删和元数据合并。
- **媒体类型定义**：定义 HDR 类型等常见媒体类型枚举。
- **错误码规范**：定义统一的媒体框架错误码，覆盖内存、I/O、超时、DRM解密、网络等各类错误场景。

适用场景包括：所有涉及音视频数据处理的场景，如配置编解码参数、管理输入输出缓冲区、处理三维音频、解析HDR视频信息、处理编解码异常等。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [media_types.h](capi-media-types-h.md) | 声明了常见媒体类型的定义。 |
| [native_audio_channel_layout.h](capi-native-audio-channel-layout-h.md) | 声明了录制和播放时的扬声器布局。 |
| [native_audio_vivid.h](capi-native-audio-vivid-h.md) | 声明Audio Vivid相关的函数和枚举。 |
| [native_avbuffer.h](capi-native-avbuffer-h.md) | 声明了媒体数据结构AVBuffer的函数接口。 |
| [native_avbuffer_info.h](capi-native-avbuffer-info-h.md) | 声明了媒体数据结构AVBuffer属性的定义。 |
| [native_averrors.h](capi-native-averrors-h.md) | 媒体框架错误码。 |
| [native_avformat.h](capi-native-avformat-h.md) | 声明了OH_AVFormat相关的函数和枚举。 |
| [native_avmemory.h](capi-native-avmemory-h.md) | 声明了媒体数据结构AVMemory的定义。 |
