# MediaKeySession
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct MediaKeySession MediaKeySession
```

## 概述

MediaKeySession结构，用于表示一个媒体密钥会话实例。MediaKeySession是DRM解密流程的核心组件，负责生成许可证请求、处理许可证响应、管理密钥状态等功能。每个MediaKeySession实例对应一个播放会话的密钥解密过程。

通过OH_MediaKeySystem_CreateMediaKeySession接口创建实例，通过OH_MediaKeySession_Destroy接口销毁实例。每个MediaKeySystem可创建多个MediaKeySession实例，用于处理不同的播放会话。

**起始版本：** 11

**相关模块：** [Drm](capi-drm.md)

**所在头文件：** [native_drm_common.h](capi-native-drm-common-h.md)

