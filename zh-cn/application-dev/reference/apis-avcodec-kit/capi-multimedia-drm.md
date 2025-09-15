# Multimedia_Drm

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

## 概述

该功能使第三方应用程序可以自行实现媒体解封装和解复用功能，而不是使用系统提供的。<br> 在创建DRM实例和会话后，可以调用DRM提供的解密接口进行解密。解密参数结构定义了解密参数的传输格式。

对应的开发指南及样例可参考[媒体数据解析](../../media/avcodec/audio-video-demuxer.md)。

**起始版本：** 12

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [native_cencinfo.h](capi-native-cencinfo-h.md) | 声明用于设置解密参数的Native API。 |
