# OH_MediaKeySession_Callback


## 概述

OH_MediaKeySession_Callback结构体，用于监听密钥过期、密钥更改等事件，返回媒体密钥会话实例，适用多个媒体密钥会话解密场景。

**起始版本：** 12

**相关模块：**[Drm](_drm.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_MediaKeySession_EventCallback](_drm.md#oh_mediakeysession_eventcallback)[eventCallback](_drm.md#eventcallback-22) | 正常事件回调，如密钥过期等。 | 
| [OH_MediaKeySession_KeyChangeCallback](_drm.md#oh_mediakeysession_keychangecallback)[keyChangeCallback](_drm.md#keychangecallback-22) | 密钥更改事件的密钥更改回调。 | 
