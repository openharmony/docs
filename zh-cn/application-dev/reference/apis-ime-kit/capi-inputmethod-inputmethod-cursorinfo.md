# InputMethod_CursorInfo
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

```c
typedef struct InputMethod_CursorInfo InputMethod_CursorInfo
```

## 概述

InputMethod_CursorInfo是光标信息的不透明类型（opaque type），用于描述文本输入时光标在物理屏幕上的位置和尺寸，包括光标的水平坐标（left）、垂直坐标（top）、宽度（width）和高度（height）。

用途：为输入法服务提供光标的精确位置和尺寸信息，输入法根据此信息实现以下功能：
- 光标跟随：键盘面板根据光标位置调整显示位置，确保键盘不遮挡光标所在区域。
- 候选词定位：输入法的候选词区域在光标附近显示，提供精准的输入体验。
- 避让计算：输入法根据光标高度和位置计算需要避让的区域。

使用场景：
1. 在TextConfig中携带光标信息：应用在[OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc)回调中返回TextConfig时，其中包含的CursorInfo告知输入法当前光标位置和尺寸。
2. 主动通知光标更新：当光标位置发生变化时（如用户移动光标、文本插入导致光标偏移），应用通过[OH_InputMethodProxy_NotifyCursorUpdate](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_notifycursorupdate)主动通知输入法最新的光标位置。

相关函数：

| 函数 | 说明 |
| -- | -- |
| [OH_CursorInfo_Create](capi-inputmethod-cursor-info-capi-h.md#oh_cursorinfo_create) | 创建CursorInfo实例，需传入left、top、width、height。 |
| [OH_CursorInfo_Destroy](capi-inputmethod-cursor-info-capi-h.md#oh_cursorinfo_destroy) | 销毁CursorInfo实例。 |
| [OH_CursorInfo_SetRect](capi-inputmethod-cursor-info-capi-h.md#oh_cursorinfo_setrect) | 设置光标的位置和尺寸。 |
| [OH_CursorInfo_GetRect](capi-inputmethod-cursor-info-capi-h.md#oh_cursorinfo_getrect) | 获取光标的位置和尺寸。 |

与其他结构体的关系：
- 与InputMethod_TextConfig的关系：CursorInfo是TextConfig的子属性。应用在[OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc)回调中返回TextConfig时，TextConfig内部包含CursorInfo，输入法通过[OH_TextConfig_GetCursorInfo](capi-inputmethod-text-config-capi-h.md#oh_textconfig_getcursorinfo)获取光标信息。因此应用需先创建CursorInfo并设置正确的光标坐标，然后在GetTextConfig回调中将CursorInfo放入TextConfig。
- 与OH_InputMethodProxy_NotifyCursorUpdate的关系：CursorInfo作为NotifyCursorUpdate函数的参数直接传入，用于在光标位置变化时主动通知输入法。应用创建或更新CursorInfo后，通过NotifyCursorUpdate将最新光标信息发送给输入法。
- 与InputMethod_InputMethodProxy的关系：NotifyCursorUpdate函数需要InputMethod_InputMethodProxy参数（由Attach返回）和InputMethod_CursorInfo参数配合使用，inputMethodProxy标识交互通道，cursorInfo携带光标信息。

**起始版本：** 12

**相关模块：** [InputMethod](capi-inputmethod.md)

**所在头文件：** [inputmethod_cursor_info_capi.h](capi-inputmethod-cursor-info-capi-h.md)
