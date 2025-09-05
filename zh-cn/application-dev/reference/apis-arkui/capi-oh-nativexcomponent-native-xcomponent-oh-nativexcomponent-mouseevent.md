# OH_NativeXComponent_MouseEvent
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zjsxstar-->
<!--Designer: @sunbees-->
<!--Tester: @liuli0427-->
<!--Adviser: @HelloCrease-->

## 概述

鼠标事件。

**起始版本：** 9

**相关模块：** [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

**所在头文件：** [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| float x | 点击触点相对于当前组件左上角的x轴坐标。 |
| float y | 点击触点相对于当前组件左上角的y轴坐标。 |
| float screenX | 点击触点相对于XComponent所在应用屏幕左上角的x轴坐标。 |
| float screenY | 点击触点相对于XComponent所在应用屏幕左上角的y轴坐标。 |
| int64_t timestamp | 当前鼠标事件的时间戳。触发事件时距离系统启动的时间间隔，单位纳秒。 |
| [OH_NativeXComponent_MouseEventAction](capi-native-interface-xcomponent-h.md#oh_nativexcomponent_mouseeventaction) action | 当前鼠标事件动作。 |
| [OH_NativeXComponent_MouseEventButton](capi-native-interface-xcomponent-h.md#oh_nativexcomponent_mouseeventbutton) button | 鼠标事件按键。 |


