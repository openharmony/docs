# AVScreenCapture
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @zzs911-->

## 概述

调用本模块下的接口，应用可以实现屏幕录制功能。支持录屏取码流和录屏写文件两种模式，适用于需要捕获屏幕音视频内容的各类场景，帮助开发者灵活获取屏幕数据并进行后续处理或保存为文件。典型使用场景包括：在线会议录制、游戏直播分享、教学演示视频制作、远程协作屏幕共享等。

开发者可根据实际的开发需求，参考对应的开发指南及样例：

- [使用AVScreenCapture录屏取码流](../../media/media/avscreencapture-c-basic-process.md)
- [使用AVScreenCapture录屏写文件](../../media/media/using-avscreencapture-for-file.md)

**起始版本：** 10

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [native_avscreen_capture.h](capi-native-avscreen-capture-h.md) | 声明用于构造屏幕录制对象的API。 |
| [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md) | 声明用于运行屏幕录制通用的结构体、字符常量、枚举。 |
| [native_avscreen_capture_errors.h](capi-native-avscreen-capture-errors-h.md) | 声明用于运行屏幕录制过程中接口调用的错误码说明。 |
