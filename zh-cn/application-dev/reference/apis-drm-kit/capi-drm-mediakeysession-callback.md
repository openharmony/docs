# MediaKeySession_Callback
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct MediaKeySession_Callback {...} MediaKeySession_Callback
```

## 概述

MediaKeySession_Callback结构体，用于监听密钥过期、密钥更改等事件，不返回媒体密钥会话实例，适用于单媒体密钥会话解密场景。

**起始版本：** 11

**相关模块：** [Drm](capi-drm.md)

**所在头文件：** [native_mediakeysession.h](capi-native-mediakeysession-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [MediaKeySession_EventCallback](capi-native-mediakeysession-h.md#mediakeysession_eventcallback) eventCallback | 正常事件回调函数指针，用于处理密钥过期等常规事件。当MediaKeySession状态发生常规变化时，系统会调用此回调函数通知应用。 |
| [MediaKeySession_KeyChangeCallback](capi-native-mediakeysession-h.md#mediakeysession_keychangecallback) keyChangeCallback | 密钥更改事件回调函数指针，用于处理密钥状态变化事件。当密钥状态发生变化（如密钥可用、密钥过期等）时，系统会调用此回调函数通知应用，回调参数中包含变化的密钥信息。 |


