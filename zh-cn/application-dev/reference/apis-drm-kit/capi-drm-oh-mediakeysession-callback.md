# OH_MediaKeySession_Callback

## 概述

OH_MediaKeySession_Callback结构体，用于监听密钥过期、密钥更改等事件，返回媒体密钥会话实例，适用多个媒体密钥会话解密场景。

**起始版本：** 12

**相关模块：** [Drm](capi-drm.md)

**所在头文件：** [native_mediakeysession.h](capi-native-mediakeysession-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [OH_MediaKeySession_EventCallback](capi-native-mediakeysession-h.md#oh_mediakeysession_eventcallback) eventCallback | 正常事件回调，如密钥过期等。 |
| [OH_MediaKeySession_KeyChangeCallback](capi-native-mediakeysession-h.md#oh_mediakeysession_keychangecallback) keyChangeCallback | 密钥更改事件的密钥更改回调。 |


