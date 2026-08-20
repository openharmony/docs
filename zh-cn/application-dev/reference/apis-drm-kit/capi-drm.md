# Drm

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @hanzhengshi-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @qin_wei_jie-->
## 概述

提供数字版权保护能力的API。

开发者可根据开发需求，参考开发指南及样例：

- [数字版权保护(C/C++)](../../media/drm/drm-c-dev-guide.md)
- [基于AVCodec播放DRM节目(C/C++)](../../media/drm/drm-avcodec-integration.md)


**起始版本：** 11

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [native_drm_common.h](capi-native-drm-common-h.md) | 定义DRM数据类型，包括媒体密钥请求、内容保护级别、证书状态等核心数据结构，用于支持DRM（数字版权管理）功能的开发，帮助应用实现受版权保护的多媒体内容的播放和管理。 |
| [native_drm_err.h](capi-native-drm-err-h.md) | 定义DRM错误码，用于标识DRM模块在运行过程中可能出现的各种异常情况。开发者可基于错误码进行错误处理和问题定位，提高DRM应用的稳定性和可维护性，适用于需要处理DRM功能异常的场景。 |
| [native_mediakeysession.h](capi-native-mediakeysession-h.md) | 定义DRM MediaKeySession API。提供以下功能：<br>生成媒体密钥请求、处理媒体密钥响应、事件监听、获取内容保护级别、检查媒体密钥状态、删除媒体密钥等。 |
| [native_mediakeysystem.h](capi-native-mediakeysystem-h.md) | 定义DRM MediaKeySystem API。提供以下功能：<br>查询是否支持特定的DRM、创建媒体密钥会话、获取和设置配置、获取统计信息、获取内容保护级别、生成提供请求、处理提供响应、事件监听、管理离线媒体密钥等。 |
