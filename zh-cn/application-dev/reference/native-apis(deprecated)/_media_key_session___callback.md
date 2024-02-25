# MediaKeySession_Callback


## 概述

MediaKeySession回调结构体, 用来监听密钥过期、密钥变化等事件。

**起始版本：** 11

**相关模块：**[Drm](_drm.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [MediaKeySession_EventCallback](_drm.md#mediakeysession_eventcallback)[eventCallback](_drm.md#eventcallback) | KeySession回调事件，如许可证过期。 | 
| [MediaKeySession_KeyChangeCallback](_drm.md#mediakeysession_keychangecallback)[keyChangeCallback](_drm.md#keychangecallback) | 密钥变化事件触发的keyChange事件。 | 
