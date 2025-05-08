# MediaKeySession_Callback


## 概述

MediaKeySession_Callback结构体，用于监听密钥过期、密钥更改等事件，不返回媒体密钥会话实例，适用于单媒体密钥会话解密场景。

**起始版本：** 11

**相关模块：**[Drm](_drm.md)

**所在头文件：**[native_mediakeysession.h](native__mediakeysession_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [MediaKeySession_EventCallback](_drm.md#mediakeysession_eventcallback) [eventCallback](_drm.md#eventcallback-12) | 正常事件回调，如密钥过期等。 |
| [MediaKeySession_KeyChangeCallback](_drm.md#mediakeysession_keychangecallback) [keyChangeCallback](_drm.md#keychangecallback-12) | 密钥更改事件的密钥更改回调。 |
