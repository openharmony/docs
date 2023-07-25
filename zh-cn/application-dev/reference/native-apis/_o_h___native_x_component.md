# Native XComponent


## 概述

描述ArkUI XComponent持有的surface和触摸事件，该事件可用于EGL/OpenGLES和媒体数据输入，并显示在ArkUI XComponent上，具体使用请参考[XComponent开发指导](../../napi/xcomponent-guidelines.md)。

**起始版本:**

8


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [native_interface_xcomponent.h](native__interface__xcomponent_8h.md) | 声明用于访问Native&nbsp;XComponent的API。<br/>引用文件：&lt;ace/xcomponent/native_interface_xcomponent.h&gt; |
| [native_xcomponent_key_event.h](native__xcomponent__key__event_8h.md) | 声明用于访问Native&nbsp;XComponent键盘事件所使用到的枚举类型。<br/>引用文件：&lt;ace/xcomponent/native_xcomponent_key_event.h&gt; |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeXComponent_TouchPoint](_o_h___native_x_component___touch_point.md) | 触摸事件中触摸点的信息。 |
| [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) | 触摸事件。 |
| [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) | 鼠标事件。 |
| [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) | 注册surface生命周期和触摸事件回调。 |
| [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) | 注册鼠标事件的回调。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeXComponent](#oh_nativexcomponent) | 提供封装的OH_NativeXComponent实例。 |
| [OH_NativeXComponent_Callback](#oh_nativexcomponent_callback) | 注册surface生命周期和触摸事件回调。 |
| [OH_NativeXComponent_MouseEvent_Callback](#oh_nativexcomponent_mouseevent_callback) | 注册鼠标事件的回调。 |
| [OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent) | 提供封装的OH_NativeXComponent_KeyEvent实例。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| {&nbsp;OH_NATIVEXCOMPONENT_RESULT_SUCCESS&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_RESULT_FAILED&nbsp;=&nbsp;-1,&nbsp;OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER&nbsp;=&nbsp;-2&nbsp;} | 枚举API访问状态。 |
| [OH_NativeXComponent_TouchEventType](#oh_nativexcomponent_toucheventtype)&nbsp;{<br/>OH_NATIVEXCOMPONENT_DOWN&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_UP,&nbsp;OH_NATIVEXCOMPONENT_MOVE,&nbsp;OH_NATIVEXCOMPONENT_CANCEL,<br/>OH_NATIVEXCOMPONENT_UNKNOWN<br/>} | 触摸事件类型。 |
| [OH_NativeXComponent_TouchPointToolType](#oh_nativexcomponent_touchpointtooltype)&nbsp;{<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS<br/>} | 触摸点工具类型。 |
| [OH_NativeXComponent_EventSourceType](#oh_nativexcomponent_eventsourcetype)&nbsp;{<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE,&nbsp;OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN,&nbsp;OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD,<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK,&nbsp;OH_NATIVEXCOMPONENT_SOURCE_TYPE_KEYBOARD<br/>} | 触摸事件源类型。 |
| [OH_NativeXComponent_MouseEventAction](#oh_nativexcomponent_mouseeventaction)&nbsp;{&nbsp;OH_NATIVEXCOMPONENT_MOUSE_NONE&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_MOUSE_PRESS,&nbsp;OH_NATIVEXCOMPONENT_MOUSE_RELEASE,&nbsp;OH_NATIVEXCOMPONENT_MOUSE_MOVE&nbsp;} | 鼠标事件动作。 |
| [OH_NativeXComponent_MouseEventButton](#oh_nativexcomponent_mouseeventbutton)&nbsp;{<br/>OH_NATIVEXCOMPONENT_NONE_BUTTON&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_LEFT_BUTTON&nbsp;=&nbsp;0x01,&nbsp;OH_NATIVEXCOMPONENT_RIGHT_BUTTON&nbsp;=&nbsp;0x02,&nbsp;OH_NATIVEXCOMPONENT_MIDDLE_BUTTON&nbsp;=&nbsp;0x04,<br/>OH_NATIVEXCOMPONENT_BACK_BUTTON&nbsp;=&nbsp;0x08,&nbsp;OH_NATIVEXCOMPONENT_FORWARD_BUTTON&nbsp;=&nbsp;0x10<br/>} | 鼠标事件按键。 |
| [OH_NativeXComponent_KeyAction](#oh_nativexcomponent_keyaction)&nbsp;{&nbsp;OH_NATIVEXCOMPONENT_KEY_ACTION_UNKNOWN&nbsp;=&nbsp;-1,&nbsp;OH_NATIVEXCOMPONENT_KEY_ACTION_DOWN&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_KEY_ACTION_UP&nbsp;} | 按键事件动作。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeXComponent_GetXComponentId](#oh_nativexcomponent_getxcomponentid)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;char&nbsp;\*id,&nbsp;uint64_t&nbsp;\*size) | 获取ArkUI&nbsp;XComponent的id。 |
| [OH_NativeXComponent_GetXComponentSize](#oh_nativexcomponent_getxcomponentsize)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;uint64_t&nbsp;\*width,&nbsp;uint64_t&nbsp;\*height) | 获取ArkUI&nbsp;XComponent持有的surface的大小。 |
| [OH_NativeXComponent_GetXComponentOffset](#oh_nativexcomponent_getxcomponentoffset)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;double&nbsp;\*x,&nbsp;double&nbsp;\*y) | 获取ArkUI&nbsp;XComponent组件相对屏幕左上顶点的偏移量。 |
| [OH_NativeXComponent_GetTouchEvent](#oh_nativexcomponent_gettouchevent)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;[OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md)&nbsp;\*touchEvent) | 获取ArkUI&nbsp;XComponent调度的触摸事件。 |
| [OH_NativeXComponent_GetTouchPointToolType](#oh_nativexcomponent_gettouchpointtooltype)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;uint32_t&nbsp;pointIndex,&nbsp;[OH_NativeXComponent_TouchPointToolType](#oh_nativexcomponent_touchpointtooltype)&nbsp;\*toolType) | 获取ArkUI&nbsp;XComponent触摸点工具类型。 |
| [OH_NativeXComponent_GetTouchPointTiltX](#oh_nativexcomponent_gettouchpointtiltx)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;uint32_t&nbsp;pointIndex,&nbsp;float&nbsp;\*tiltX) | 获取ArkUI&nbsp;XComponent触摸点倾斜与X轴角度。 |
| [OH_NativeXComponent_GetTouchPointTiltY](#oh_nativexcomponent_gettouchpointtilty)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;uint32_t&nbsp;pointIndex,&nbsp;float&nbsp;\*tiltY) | 获取ArkUI&nbsp;XComponent触摸点倾斜与Y轴角度。 |
| [OH_NativeXComponent_GetMouseEvent](#oh_nativexcomponent_getmouseevent)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;[OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md)&nbsp;\*mouseEvent) | 获取ArkUI&nbsp;XComponent调度的鼠标事件。 |
| [OH_NativeXComponent_RegisterCallback](#oh_nativexcomponent_registercallback)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;[OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md)&nbsp;\*callback) | 为此OH_NativeXComponent实例注册回调。 |
| [OH_NativeXComponent_RegisterMouseEventCallback](#oh_nativexcomponent_registermouseeventcallback)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;[OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md)&nbsp;\*callback) | 为此OH_NativeXComponent实例注册鼠标事件回调。 |
| [OH_NativeXComponent_RegisterFocusEventCallback](#oh_nativexcomponent_registerfocuseventcallback)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window)) | 为此OH_NativeXComponent实例注册获焦事件回调。 |
| [OH_NativeXComponent_RegisterKeyEventCallback](#oh_nativexcomponent_registerkeyeventcallback)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window)) | 为此OH_NativeXComponent实例注册按键事件回调。 |
| [OH_NativeXComponent_RegisterBlurEventCallback](#oh_nativexcomponent_registerblureventcallback)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window)) | 为此OH_NativeXComponent实例注册失焦事件回调。 |
| [OH_NativeXComponent_GetKeyEvent](#oh_nativexcomponent_getkeyevent)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;[OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)&nbsp;\*\*keyEvent) | 获取ArkUI&nbsp;XComponent调度的按键事件。 |
| [OH_NativeXComponent_GetKeyEventAction](#oh_nativexcomponent_getkeyeventaction)&nbsp;([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;[OH_NativeXComponent_KeyAction](#oh_nativexcomponent_keyaction)&nbsp;\*action) | 获取传入按键事件的动作。 |
| [OH_NativeXComponent_GetKeyEventCode](#oh_nativexcomponent_getkeyeventcode)&nbsp;([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;[OH_NativeXComponent_KeyCode](#oh_nativexcomponent_keycode)&nbsp;\*code) | 获取传入按键事件的按键码。 |
| [OH_NativeXComponent_GetKeyEventSourceType](#oh_nativexcomponent_getkeyeventsourcetype)&nbsp;([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;[OH_NativeXComponent_EventSourceType](#oh_nativexcomponent_eventsourcetype)&nbsp;\*sourceType) | 获取传入按键事件的事件源类型。 |
| [OH_NativeXComponent_GetKeyEventDeviceId](#oh_nativexcomponent_getkeyeventdeviceid)&nbsp;([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;int64_t&nbsp;\*deviceId) | 获取传入按键事件的设备id。 |
| [OH_NativeXComponent_GetKeyEventTimeStamp](#oh_nativexcomponent_getkeyeventtimestamp)&nbsp;([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;int64_t&nbsp;\*timeStamp) | 获取传入按键事件的时间戳。 |


### 变量

| 名称 | 描述 |
| -------- | -------- |
| **OH_XCOMPONENT_ID_LEN_MAX**&nbsp;=&nbsp;128 | ArkUI&nbsp;XComponent的id最大长度。 |
| **OH_MAX_TOUCH_POINTS_NUMBER**&nbsp;=&nbsp;10 | 触摸事件中的可识别的触摸点个数最大值。 |
| [OH_NativeXComponent_TouchPoint::id](#id-12)&nbsp;=&nbsp;0 | 手指的唯一标识符。 |
| [OH_NativeXComponent_TouchPoint::screenX](#screenx-13)&nbsp;=&nbsp;0.0 | 触摸点相对于XComponent所在应用窗口左上角的x坐标。 |
| [OH_NativeXComponent_TouchPoint::screenY](#screeny-13)&nbsp;=&nbsp;0.0 | 触摸点相对于XComponent所在应用窗口左上角的y坐标。 |
| [OH_NativeXComponent_TouchPoint::x](#x-13)&nbsp;=&nbsp;0.0 | 触摸点相对于XComponent组件左边缘的x坐标。 |
| [OH_NativeXComponent_TouchPoint::y](#y-13)&nbsp;=&nbsp;0.0 | 触摸点相对于XComponent组件上边缘的y坐标。 |
| [OH_NativeXComponent_TouchPoint::type](#type-12)&nbsp;=&nbsp;OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN | 触摸事件的触摸类型。 |
| [OH_NativeXComponent_TouchPoint::size](#size-12)&nbsp;=&nbsp;0.0 | 指垫和屏幕之间的接触面积。 |
| [OH_NativeXComponent_TouchPoint::force](#force-12)&nbsp;=&nbsp;0.0 | 当前触摸事件的压力。 |
| [OH_NativeXComponent_TouchPoint::timeStamp](#timestamp-12)&nbsp;=&nbsp;0 | 当前触摸事件的时间戳。 |
| [OH_NativeXComponent_TouchPoint::isPressed](#ispressed)&nbsp;=&nbsp;false | 当前点是否被按下。 |
| [OH_NativeXComponent_TouchEvent::id](#id-22)&nbsp;=&nbsp;0 | 手指的唯一标识符。 |
| [OH_NativeXComponent_TouchEvent::screenX](#screenx-23)&nbsp;=&nbsp;0.0 | 触摸点相对于屏幕左边缘的x坐标。 |
| [OH_NativeXComponent_TouchEvent::screenY](#screeny-23)&nbsp;=&nbsp;0.0 | 触摸点相对于屏幕上边缘的y坐标。 |
| [OH_NativeXComponent_TouchEvent::x](#x-23)&nbsp;=&nbsp;0.0 | 触摸点相对于XComponent组件左边缘的x坐标。 |
| [OH_NativeXComponent_TouchEvent::y](#y-23)&nbsp;=&nbsp;0.0 | 触摸点相对于XComponent组件上边缘的y坐标。 |
| [OH_NativeXComponent_TouchEvent::type](#type-22)&nbsp;=&nbsp;OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN | 触摸事件的触摸类型。 |
| [OH_NativeXComponent_TouchEvent::size](#size-22)&nbsp;=&nbsp;0.0 | 指垫和屏幕之间的接触面积。 |
| [OH_NativeXComponent_TouchEvent::force](#force-22)&nbsp;=&nbsp;0.0 | 当前触摸事件的压力。 |
| [OH_NativeXComponent_TouchEvent::deviceId](#deviceid)&nbsp;=&nbsp;0 | 产生当前触摸事件的设备的ID。 |
| [OH_NativeXComponent_TouchEvent::timeStamp](#timestamp-22)&nbsp;=&nbsp;0 | 当前触摸事件的时间戳。 |
| [OH_NativeXComponent_TouchEvent::touchPoints](#touchpoints)&nbsp;[OH_MAX_TOUCH_POINTS_NUMBER] | 当前触摸点的数组。 |
| [OH_NativeXComponent_TouchEvent::numPoints](#numpoints)&nbsp;=&nbsp;0 | 当前接触点的数量。 |
| [OH_NativeXComponent_MouseEvent::x](#x-33)&nbsp;=&nbsp;0.0 | 点击触点相对于当前组件左上角的x轴坐标。 |
| [OH_NativeXComponent_MouseEvent::y](#y-33)=&nbsp;0.0 | 点击触点相对于当前组件左上角的y轴坐标。 |
| [OH_NativeXComponent_MouseEvent::screenX](#screenx-33)=&nbsp;0.0 | 点击触点相对于屏幕左上角的x轴坐标。 |
| [OH_NativeXComponent_MouseEvent::screenY](#screeny-33)=&nbsp;0.0 | 点击触点相对于屏幕左上角的y轴坐标。 |
| [OH_NativeXComponent_MouseEvent::timestamp](#timestamp)=&nbsp;0 | 当前鼠标事件的时间戳。 |
| [OH_NativeXComponent_MouseEvent::action](#action)=&nbsp;[OH_NativeXComponent_MouseEventAction::OH_NATIVEXCOMPONENT_MOUSE_NONE](#oh_nativexcomponent_mouseeventaction) | 当前鼠标事件动作。 |
| [OH_NativeXComponent_MouseEvent::button](#button)=&nbsp;[OH_NativeXComponent_MouseEventButton::OH_NATIVEXCOMPONENT_NONE_BUTTON](#oh_nativexcomponent_mouseeventbutton) | 鼠标事件按键。 |
| [OH_NativeXComponent_Callback::OnSurfaceCreated](#onsurfacecreated) | 创建surface时调用。 |
| [OH_NativeXComponent_Callback::OnSurfaceChanged](#onsurfacechanged) | 当surface改变时调用。 |
| [OH_NativeXComponent_Callback::OnSurfaceDestroyed](#onsurfacedestroyed) | 当surface被销毁时调用。 |
| [OH_NativeXComponent_Callback::DispatchTouchEvent](#dispatchtouchevent) | 当触摸事件被触发时调用。 |
| [OH_NativeXComponent_MouseEvent_Callback::DispatchMouseEvent](#dispatchmouseevent) | 当鼠标事件被触发时调用。 |
| [OH_NativeXComponent_MouseEvent_Callback::DispatchHoverEvent](#dispatchhoverevent) | 当悬停事件被触发时调用。 |


## 类型定义说明


### OH_NativeXComponent

```
typedef struct OH_NativeXComponent OH_NativeXComponent
```

**描述:**

提供封装的OH_NativeXComponent实例。

**起始版本：**

8


### OH_NativeXComponent_Callback

```
typedef struct OH_NativeXComponent_Callback OH_NativeXComponent_Callback
```

**描述:**

注册surface生命周期和触摸事件回调。

**起始版本：**

8


### OH_NativeXComponent_KeyEvent

```
typedef struct OH_NativeXComponent_KeyEvent OH_NativeXComponent_KeyEvent
```

**描述:**

提供封装的OH_NativeXComponent_KeyEvent实例。

**起始版本：**

10


### OH_NativeXComponent_MouseEvent_Callback

```
typedef struct OH_NativeXComponent_MouseEvent_Callback OH_NativeXComponent_MouseEvent_Callback
```

**描述:**

注册鼠标事件的回调。

**起始版本：**

9


## 枚举类型说明


### anonymous enum

```
anonymous enum
```

**描述:**

枚举API访问状态。

| 枚举值 | 描述 |
| -------- | -------- |
| OH_NATIVEXCOMPONENT_RESULT_SUCCESS | 成功结果。 |
| OH_NATIVEXCOMPONENT_RESULT_FAILED | 失败结果。 |
| OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER | 无效参数。 |

**起始版本：**

8


### OH_NativeXComponent_EventSourceType

```
enum OH_NativeXComponent_EventSourceType
```

**描述:**

触摸事件源类型。

| 枚举值 | 描述 |
| -------- | -------- |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN | 未知的输入源类型。 |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE | 表示输入源生成鼠标多点触摸事件。 |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN | 表示输入源生成一个触摸屏多点触摸事件。 |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD | 表示输入源生成一个触摸板多点触摸事件。 |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK | 表示输入源生成一个操纵杆多点触摸事件。 |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_KEYBOARD | 表示输入源生成一个键盘事件。 |

**起始版本：**

9


### OH_NativeXComponent_KeyAction

```
enum OH_NativeXComponent_KeyAction
```

**描述:**

按键事件动作。

| 枚举值 | 描述 |
| -------- | -------- |
| OH_NATIVEXCOMPONENT_KEY_ACTION_UNKNOWN | 未知的按键动作。 |
| OH_NATIVEXCOMPONENT_KEY_ACTION_DOWN | 按键按下动作。 |
| OH_NATIVEXCOMPONENT_KEY_ACTION_UP | 按键抬起动作。 |

**起始版本：**

10


### OH_NativeXComponent_KeyCode

```
enum OH_NativeXComponent_KeyCode
```

**描述:**

按键事件的键码。

| 枚举值 | 描述 |
| -------- | -------- |
| KEY_UNKNOWN | 未知按键 |
| KEY_FN | 功能（Fn）键 |
| KEY_HOME | 功能（Home）键 |
| KEY_BACK | 返回键 |
| KEY_MEDIA_PLAY_PAUSE | 多媒体键&nbsp;播放/暂停 |
| KEY_MEDIA_STOP | 多媒体键&nbsp;停止 |
| KEY_MEDIA_NEXT | 多媒体键&nbsp;下一首 |
| KEY_MEDIA_PREVIOUS | 多媒体键&nbsp;上一首 |
| KEY_MEDIA_REWIND | 多媒体键&nbsp;快退 |
| KEY_MEDIA_FAST_FORWARD | 多媒体键&nbsp;快进 |
| KEY_VOLUME_UP | 音量增加键 |
| KEY_VOLUME_DOWN | 音量减小键 |
| KEY_POWER | 电源键 |
| KEY_CAMERA | 拍照键 |
| KEY_VOLUME_MUTE | 扬声器静音键 |
| KEY_MUTE | 话筒静音键 |
| KEY_BRIGHTNESS_UP | 亮度调节按键&nbsp;调亮 |
| KEY_BRIGHTNESS_DOWN | 亮度调节按键&nbsp;调暗 |
| KEY_0 | 按键'0' |
| KEY_1 | 按键'1' |
| KEY_2 | 按键'2' |
| KEY_3 | 按键'3' |
| KEY_4 | 按键'4' |
| KEY_5 | 按键'5' |
| KEY_6 | 按键'6' |
| KEY_7 | 按键'7' |
| KEY_8 | 按键'8' |
| KEY_9 | 按键'9' |
| KEY_STAR | 按键'\*' |
| KEY_POUND | 按键'\#' |
| KEY_DPAD_UP | 导航键&nbsp;向上 |
| KEY_DPAD_DOWN | 导航键&nbsp;向下 |
| KEY_DPAD_LEFT | 导航键&nbsp;向左 |
| KEY_DPAD_RIGHT | 导航键&nbsp;向右 |
| KEY_DPAD_CENTER | 导航键&nbsp;确定键 |
| KEY_A | 按键'A' |
| KEY_B | 按键'B' |
| KEY_C | 按键'C' |
| KEY_D | 按键'D' |
| KEY_E | 按键'E' |
| KEY_F | 按键'F' |
| KEY_G | 按键'G' |
| KEY_H | 按键'H' |
| KEY_I | 按键'I' |
| KEY_J | 按键'J' |
| KEY_K | 按键'K' |
| KEY_L | 按键'L' |
| KEY_M | 按键'M' |
| KEY_N | 按键'N' |
| KEY_O | 按键'O' |
| KEY_P | 按键'P' |
| KEY_Q | 按键'Q' |
| KEY_R | 按键'R' |
| KEY_S | 按键'S' |
| KEY_T | 按键'T' |
| KEY_U | 按键'U' |
| KEY_V | 按键'V' |
| KEY_W | 按键'W' |
| KEY_X | 按键'X' |
| KEY_Y | 按键'Y' |
| KEY_Z | 按键'Z' |
| KEY_COMMA | 按键',' |
| KEY_PERIOD | 按键'.' |
| KEY_ALT_LEFT | 左Alt键 |
| KEY_ALT_RIGHT | 右Alt键 |
| KEY_SHIFT_LEFT | 左Shift键 |
| KEY_SHIFT_RIGHT | 右Shift键 |
| KEY_TAB | Tab键 |
| KEY_SPACE | 空格键 |
| KEY_SYM | 符号修改器按键 |
| KEY_EXPLORER | 浏览器功能键，此键用于启动浏览器应用程序。 |
| KEY_ENVELOPE | 电子邮件功能键，此键用于启动电子邮件应用程序。 |
| KEY_ENTER | 回车键 |
| KEY_DEL | 退格键 |
| KEY_GRAVE | 按键'‘’ |
| KEY_MINUS | 按键'-' |
| KEY_EQUALS | 按键'=' |
| KEY_LEFT_BRACKET | 按键'[' |
| KEY_RIGHT_BRACKET | 按键']' |
| KEY_BACKSLASH | 按键'\' |
| KEY_SEMICOLON | 按键';' |
| KEY_APOSTROPHE | 按键'''&nbsp;(单引号) |
| KEY_SLASH | 按键'/' |
| KEY_AT | 按键'\@' |
| KEY_PLUS | 按键'+' |
| KEY_MENU | 菜单键 |
| KEY_PAGE_UP | 向上翻页键 |
| KEY_PAGE_DOWN | 向下翻页键 |
| KEY_ESCAPE | ESC键 |
| KEY_FORWARD_DEL | 删除键 |
| KEY_CTRL_LEFT | 左Ctrl键 |
| KEY_CTRL_RIGHT | 右Ctrl键 |
| KEY_CAPS_LOCK | 大写锁定键 |
| KEY_SCROLL_LOCK | 滚动锁定键 |
| KEY_META_LEFT | 左元修改器键 |
| KEY_META_RIGHT | 右元修改器键 |
| KEY_FUNCTION | 功能键 |
| KEY_SYSRQ | 系统请求/打印屏幕键 |
| KEY_BREAK | Break/Pause键 |
| KEY_MOVE_HOME | 光标移动到开始键 |
| KEY_MOVE_END | 光标移动到末尾键 |
| KEY_INSERT | 插入键 |
| KEY_FORWARD | 前进键 |
| KEY_MEDIA_PLAY | 多媒体键&nbsp;播放 |
| KEY_MEDIA_PAUSE | 多媒体键&nbsp;暂停 |
| KEY_MEDIA_CLOSE | 多媒体键&nbsp;关闭 |
| KEY_MEDIA_EJECT | 多媒体键&nbsp;弹出 |
| KEY_MEDIA_RECORD | 多媒体键&nbsp;录音 |
| KEY_F1 | 按键'F1' |
| KEY_F2 | 按键'F2' |
| KEY_F3 | 按键'F3' |
| KEY_F4 | 按键'F4' |
| KEY_F5 | 按键'F5' |
| KEY_F6 | 按键'F6' |
| KEY_F7 | 按键'F7' |
| KEY_F8 | 按键'F8' |
| KEY_F9 | 按键'F9' |
| KEY_F10 | 按键'F10' |
| KEY_F11 | 按键'F11' |
| KEY_F12 | 按键'F12' |
| KEY_NUM_LOCK | 小键盘锁 |
| KEY_NUMPAD_0 | 小键盘按键'0' |
| KEY_NUMPAD_1 | 小键盘按键'1' |
| KEY_NUMPAD_2 | 小键盘按键'2' |
| KEY_NUMPAD_3 | 小键盘按键'3' |
| KEY_NUMPAD_4 | 小键盘按键'4' |
| KEY_NUMPAD_5 | 小键盘按键'5' |
| KEY_NUMPAD_6 | 小键盘按键'6' |
| KEY_NUMPAD_7 | 小键盘按键'7' |
| KEY_NUMPAD_8 | 小键盘按键'8' |
| KEY_NUMPAD_9 | 小键盘按键'9' |
| KEY_NUMPAD_DIVIDE | 小键盘按键'/' |
| KEY_NUMPAD_MULTIPLY | 小键盘按键'\*' |
| KEY_NUMPAD_SUBTRACT | 小键盘按键'-' |
| KEY_NUMPAD_ADD | 小键盘按键'+' |
| KEY_NUMPAD_DOT | 小键盘按键'.' |
| KEY_NUMPAD_COMMA | 小键盘按键',' |
| KEY_NUMPAD_ENTER | 小键盘按键回车 |
| KEY_NUMPAD_EQUALS | 小键盘按键'=' |
| KEY_NUMPAD_LEFT_PAREN | 小键盘按键'(' |
| KEY_NUMPAD_RIGHT_PAREN | 小键盘按键')' |
| KEY_VIRTUAL_MULTITASK | 虚拟多任务键 |
| KEY_SLEEP | 睡眠键 |
| KEY_ZENKAKU_HANKAKU | 日文全宽/半宽键 |
| KEY_102ND | 102nd按键 |
| KEY_RO | 日文Ro键 |
| KEY_KATAKANA | 日文片假名键 |
| KEY_HIRAGANA | 日文平假名键 |
| KEY_HENKAN | 日文转换键 |
| KEY_KATAKANA_HIRAGANA | 日语片假名/平假名键 |
| KEY_MUHENKAN | 日文非转换键 |
| KEY_LINEFEED | 换行键 |
| KEY_MACRO | 宏键 |
| KEY_NUMPAD_PLUSMINUS | 数字键盘上的加号/减号键 |
| KEY_SCALE | 扩展键 |
| KEY_HANGUEL | 日文韩语键 |
| KEY_HANJA | 日文汉语键 |
| KEY_YEN | 日元键 |
| KEY_STOP | 停止键 |
| KEY_AGAIN | 重复键 |
| KEY_PROPS | 道具键 |
| KEY_UNDO | 撤消键 |
| KEY_COPY | 复制键 |
| KEY_OPEN | 打开键 |
| KEY_PASTE | 粘贴键 |
| KEY_FIND | 查找键 |
| KEY_CUT | 剪切键 |
| KEY_HELP | 帮助键 |
| KEY_CALC | 计算器特殊功能键，用于启动计算器应用程序 |
| KEY_FILE | 文件按键 |
| KEY_BOOKMARKS | 书签键 |
| KEY_NEXT | 下一个按键 |
| KEY_PLAYPAUSE | 播放/暂停键 |
| KEY_PREVIOUS | 上一个按键 |
| KEY_STOPCD | CD停止键 |
| KEY_CONFIG | 配置键 |
| KEY_REFRESH | 刷新键 |
| KEY_EXIT | 退出键 |
| KEY_EDIT | 编辑键 |
| KEY_SCROLLUP | 向上滚动键 |
| KEY_SCROLLDOWN | 向下滚动键 |
| KEY_NEW | 新建键 |
| KEY_REDO | 恢复键 |
| KEY_CLOSE | 关闭键 |
| KEY_PLAY | 播放键 |
| KEY_BASSBOOST | 低音增强键 |
| KEY_PRINT | 打印键 |
| KEY_CHAT | 聊天键 |
| KEY_FINANCE | 金融键 |
| KEY_CANCEL | 取消键 |
| KEY_KBDILLUM_TOGGLE | 键盘灯光切换键 |
| KEY_KBDILLUM_DOWN | 键盘灯光调亮键 |
| KEY_KBDILLUM_UP | 键盘灯光调暗键 |
| KEY_SEND | 发送键 |
| KEY_REPLY | 答复键 |
| KEY_FORWARDMAIL | 邮件转发键 |
| KEY_SAVE | 保存键 |
| KEY_DOCUMENTS | 文件键 |
| KEY_VIDEO_NEXT | 下一个视频键 |
| KEY_VIDEO_PREV | 上一个视频键 |
| KEY_BRIGHTNESS_CYCLE | 背光渐变键 |
| KEY_BRIGHTNESS_ZERO | 亮度调节为0键 |
| KEY_DISPLAY_OFF | 显示关闭键 |
| KEY_BTN_MISC | 游戏手柄上的各种按键 |
| KEY_GOTO | 进入键 |
| KEY_INFO | 信息查看键 |
| KEY_PROGRAM | 程序键 |
| KEY_PVR | 个人录像机(PVR)键 |
| KEY_SUBTITLE | 字幕键 |
| KEY_FULL_SCREEN | 全屏键 |
| KEY_KEYBOARD | 键盘 |
| KEY_ASPECT_RATIO | 屏幕纵横比调节键 |
| KEY_PC | 端口控制键 |
| KEY_TV | TV键 |
| KEY_TV2 | TV键2 |
| KEY_VCR | 录像机开启键 |
| KEY_VCR2 | 录像机开启键2 |
| KEY_SAT | SIM卡应用工具包（SAT）键 |
| KEY_CD | CD键 |
| KEY_TAPE | 磁带键 |
| KEY_TUNER | 调谐器键 |
| KEY_PLAYER | 播放器键 |
| KEY_DVD | DVD键 |
| KEY_AUDIO | 音频键 |
| KEY_VIDEO | 视频键 |
| KEY_MEMO | 备忘录键 |
| KEY_CALENDAR | 日历键 |
| KEY_RED | 红色指示器 |
| KEY_GREEN | 绿色指示器 |
| KEY_YELLOW | 黄色指示器 |
| KEY_BLUE | 蓝色指示器 |
| KEY_CHANNELUP | 频道向上键 |
| KEY_CHANNELDOWN | 频道向下键 |
| KEY_LAST | 末尾键 |
| KEY_RESTART | 重启键 |
| KEY_SLOW | 慢速键 |
| KEY_SHUFFLE | 随机播放键 |
| KEY_VIDEOPHONE | 可视电话键 |
| KEY_GAMES | 游戏键 |
| KEY_ZOOMIN | 放大键 |
| KEY_ZOOMOUT | 缩小键 |
| KEY_ZOOMRESET | 缩放重置键 |
| KEY_WORDPROCESSOR | 文字处理键 |
| KEY_EDITOR | 编辑器键 |
| KEY_SPREADSHEET | 电子表格键 |
| KEY_GRAPHICSEDITOR | 图形编辑器键 |
| KEY_PRESENTATION | 演示文稿键 |
| KEY_DATABASE | 数据库键标 |
| KEY_NEWS | 新闻键 |
| KEY_VOICEMAIL | 语音信箱 |
| KEY_ADDRESSBOOK | 通讯簿 |
| KEY_MESSENGER | 通信键 |
| KEY_BRIGHTNESS_TOGGLE | 亮度切换键 |
| KEY_SPELLCHECK | AL拼写检查 |
| KEY_COFFEE | 终端锁/屏幕保护程序 |
| KEY_MEDIA_REPEAT | 媒体循环键 |
| KEY_IMAGES | 图像键 |
| KEY_BUTTONCONFIG | 按键配置键 |
| KEY_TASKMANAGER | 任务管理器 |
| KEY_JOURNAL | 日志按键 |
| KEY_CONTROLPANEL | 控制面板键 |
| KEY_APPSELECT | 应用程序选择键 |
| KEY_SCREENSAVER | 屏幕保护程序键 |
| KEY_ASSISTANT | 辅助键 |
| KEY_KBD_LAYOUT_NEXT | 下一个键盘布局键 |
| KEY_BRIGHTNESS_MIN | 最小亮度键 |
| KEY_BRIGHTNESS_MAX | 最大亮度键 |
| KEY_KBDINPUTASSIST_PREV | 键盘输入Assist_Previous |
| KEY_KBDINPUTASSIST_NEXT | 键盘输入Assist_Next |
| KEY_KBDINPUTASSIST_PREVGROUP | 键盘输入Assist_Previous |
| KEY_KBDINPUTASSIST_NEXTGROUP | 键盘输入Assist_Next |
| KEY_KBDINPUTASSIST_ACCEPT | 键盘输入Assist_Accept |
| KEY_KBDINPUTASSIST_CANCEL | 键盘输入Assist_Cancel |
| KEY_FRONT | 挡风玻璃除雾器开关 |
| KEY_SETUP | 设置键 |
| KEY_WAKEUP | 唤醒键 |
| KEY_SENDFILE | 发送文件按键 |
| KEY_DELETEFILE | 删除文件按键 |
| KEY_XFER | 文件传输(XFER)按键 |
| KEY_PROG1 | 程序键1 |
| KEY_PROG2 | 程序键2 |
| KEY_MSDOS | MS-DOS键（微软磁盘操作系统 |
| KEY_SCREENLOCK | 屏幕锁定键 |
| KEY_DIRECTION_ROTATE_DISPLAY | 方向旋转显示键 |
| KEY_CYCLEWINDOWS | Windows循环键 |
| KEY_COMPUTER | 按键 |
| KEY_EJECTCLOSECD | 弹出CD键 |
| KEY_ISO | ISO键 |
| KEY_MOVE | 移动键 |
| KEY_F13 | 按键'F13' |
| KEY_F14 | 按键'F14' |
| KEY_F15 | 按键'F15' |
| KEY_F16 | 按键'F16' |
| KEY_F17 | 按键'F17' |
| KEY_F18 | 按键'F18' |
| KEY_F19 | 按键'F19' |
| KEY_F20 | 按键'F20' |
| KEY_F21 | 按键'F21' |
| KEY_F22 | 按键'F22' |
| KEY_F23 | 按键'F23' |
| KEY_F24 | 按键'F24' |
| KEY_PROG3 | 程序键3 |
| KEY_PROG4 | 程序键4 |
| KEY_DASHBOARD | 仪表板 |
| KEY_SUSPEND | 挂起键 |
| KEY_HP | 高阶路径键 |
| KEY_SOUND | 音量键 |
| KEY_QUESTION | 疑问按键 |
| KEY_CONNECT | 连接键 |
| KEY_SPORT | 运动按键 |
| KEY_SHOP | 商城键 |
| KEY_ALTERASE | 交替键 |
| KEY_SWITCHVIDEOMODE | 在可用视频之间循环输出（监视器/LCD/TV输出/等） |
| KEY_BATTERY | 电池按键 |
| KEY_BLUETOOTH | 蓝牙按键 |
| KEY_WLAN | 无线局域网 |
| KEY_UWB | 超宽带（UWB） |
| KEY_WWAN_WIMAX | WWAN&nbsp;WiMAX按键 |
| KEY_RFKILL | 控制所有收音机的键 |
| KEY_CHANNEL | 向上频道键 |
| KEY_BTN_0 | 按键0 |
| KEY_BTN_1 | 按键1 |
| KEY_BTN_2 | 按键2 |
| KEY_BTN_3 | 按键3 |
| KEY_BTN_4 | 按键4 |
| KEY_BTN_5 | 按键5 |
| KEY_BTN_6 | 按键6 |
| KEY_BTN_7 | 按键7 |
| KEY_BTN_8 | 按键8 |
| KEY_BTN_9 | 按键9 |

**起始版本：**

10


### OH_NativeXComponent_MouseEventAction

```
enum OH_NativeXComponent_MouseEventAction
```

**描述:**

鼠标事件动作。

| 枚举值 | 描述 |
| -------- | -------- |
| OH_NATIVEXCOMPONENT_MOUSE_NONE | 无效鼠标事件&nbsp;。 |
| OH_NATIVEXCOMPONENT_MOUSE_PRESS | 鼠标按键按下时触发鼠标事件。 |
| OH_NATIVEXCOMPONENT_MOUSE_RELEASE | 鼠标按键松开时触发鼠标事件。 |
| OH_NATIVEXCOMPONENT_MOUSE_MOVE | 鼠标在屏幕上移动时触发鼠标事件。 |

**起始版本：**

9


### OH_NativeXComponent_MouseEventButton

```
enum OH_NativeXComponent_MouseEventButton
```

**描述:**

鼠标事件按键。

| 枚举值 | 描述 |
| -------- | -------- |
| OH_NATIVEXCOMPONENT_NONE_BUTTON | 鼠标无按键操作时触发鼠标事件。 |
| OH_NATIVEXCOMPONENT_LEFT_BUTTON | 按下鼠标左键时触发鼠标事件。 |
| OH_NATIVEXCOMPONENT_RIGHT_BUTTON | 按下鼠标右键时触发鼠标事件。 |
| OH_NATIVEXCOMPONENT_MIDDLE_BUTTON | 按下鼠标中键时触发鼠标事件。 |
| OH_NATIVEXCOMPONENT_BACK_BUTTON | 按下鼠标左侧后退键时触发鼠标事件。 |
| OH_NATIVEXCOMPONENT_FORWARD_BUTTON | 按下鼠标左侧前进键时触发鼠标事件。 |

**起始版本：**

9


### OH_NativeXComponent_TouchEventType

```
enum OH_NativeXComponent_TouchEventType
```

**描述:**

触摸事件类型。

| 枚举值 | 描述 |
| -------- | -------- |
| OH_NATIVEXCOMPONENT_DOWN | 手指按下时触发触摸事件。 |
| OH_NATIVEXCOMPONENT_UP | 手指抬起时触发触摸事件。 |
| OH_NATIVEXCOMPONENT_MOVE | 手指按下状态下在屏幕上移动时触发触摸事件。 |
| OH_NATIVEXCOMPONENT_CANCEL | 触摸事件取消时触发事件。 |
| OH_NATIVEXCOMPONENT_UNKNOWN | 无效的触摸类型。 |

**起始版本：**

8


### OH_NativeXComponent_TouchPointToolType

```
enum OH_NativeXComponent_TouchPointToolType
```

**描述:**

触摸点工具类型

| 枚举值 | 描述 |
| -------- | -------- |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN | 未识别工具类型。 |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER | 表示用手指。 |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN | 表示用触笔。 |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER | 表示用橡皮擦。 |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH | 表示用画笔。 |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL | 表示用铅笔。 |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH | 表示用气笔。 |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE | 表示用鼠标。 |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS | 表示用晶状体。 |

**起始版本：**

9


## 函数说明


### OH_NativeXComponent_GetKeyEvent()

```
int32_t OH_NativeXComponent_GetKeyEvent (OH_NativeXComponent * component, OH_NativeXComponent_KeyEvent ** keyEvent )
```

**描述:**

获取ArkUI XComponent调度的按键事件。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| keyEvent | 表示指向当前按键事件指针的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_GetKeyEventAction()

```
int32_t OH_NativeXComponent_GetKeyEventAction (OH_NativeXComponent_KeyEvent * keyEvent, OH_NativeXComponent_KeyAction * action )
```

**描述:**

获取传入按键事件的动作。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| keyEvent | 表示指向OH_NativeXComponent_KeyEvent实例的指针。 |
| action | 表示指向按键事件动作的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_GetKeyEventCode()

```
int32_t OH_NativeXComponent_GetKeyEventCode (OH_NativeXComponent_KeyEvent * keyEvent, OH_NativeXComponent_KeyCode * code )
```

**描述:**

获取传入按键事件的按键码。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| keyEvent | 表示指向OH_NativeXComponent_KeyEvent实例的指针。 |
| code | 表示指向按键事件按键码的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_GetKeyEventDeviceId()

```
int32_t OH_NativeXComponent_GetKeyEventDeviceId (OH_NativeXComponent_KeyEvent * keyEvent, int64_t * deviceId )
```

**描述:**

获取传入按键事件的设备id。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| keyEvent | 表示指向OH_NativeXComponent_KeyEvent实例的指针。 |
| deviceId | 表示指向按键事件设备id的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_GetKeyEventSourceType()

```
int32_t OH_NativeXComponent_GetKeyEventSourceType (OH_NativeXComponent_KeyEvent * keyEvent, OH_NativeXComponent_EventSourceType * sourceType )
```

**描述:**

获取传入按键事件的事件源类型。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| keyEvent | 表示指向OH_NativeXComponent_KeyEvent实例的指针。 |
| sourceType | 表示指向按键事件事件源类型的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_GetKeyEventTimeStamp()

```
int32_t OH_NativeXComponent_GetKeyEventTimeStamp (OH_NativeXComponent_KeyEvent * keyEvent, int64_t * timeStamp )
```

**描述:**

获取传入按键事件的时间戳。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| keyEvent | 表示指向OH_NativeXComponent_KeyEvent实例的指针。 |
| timeStamp | 表示指向按键事件时间戳的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_GetMouseEvent()

```
int32_t OH_NativeXComponent_GetMouseEvent (OH_NativeXComponent * component, const void * window, OH_NativeXComponent_MouseEvent * mouseEvent )
```

**描述:**

获取ArkUI XComponent调度的鼠标事件

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| window | 表示NativeWindow句柄 |
| mouseEvent | 指示指向当前鼠标事件的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

9


### OH_NativeXComponent_GetTouchEvent()

```
int32_t OH_NativeXComponent_GetTouchEvent (OH_NativeXComponent * component, const void * window, OH_NativeXComponent_TouchEvent * touchEvent )
```

**描述:**

获取ArkUI XComponent调度的触摸事件。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| window | 表示NativeWindow句柄。 |
| touchEvent | 指示指向当前触摸事件的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_GetTouchPointTiltX()

```
int32_t OH_NativeXComponent_GetTouchPointTiltX (OH_NativeXComponent * component, uint32_t pointIndex, float * tiltX )
```

**描述:**

获取ArkUI XComponent触摸点倾斜与X轴角度。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| pointIndex | 表示触摸点的指针索引。 |
| tiltX | 表示指向X倾斜度的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

9


### OH_NativeXComponent_GetTouchPointTiltY()

```
int32_t OH_NativeXComponent_GetTouchPointTiltY (OH_NativeXComponent * component, uint32_t pointIndex, float * tiltY )
```

**描述:**

获取ArkUI XComponent触摸点倾斜与Y轴角度。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| pointIndex | 表示触摸点的指针索引。 |
| tiltY | 表示指向Y倾斜度的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

9


### OH_NativeXComponent_GetTouchPointToolType()

```
int32_t OH_NativeXComponent_GetTouchPointToolType (OH_NativeXComponent * component, uint32_t pointIndex, OH_NativeXComponent_TouchPointToolType * toolType )
```

**描述:**

获取ArkUI XComponent触摸点工具类型。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| pointIndex | 表示触摸点的指针索引。 |
| toolType | 表示指向工具类型的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

9


### OH_NativeXComponent_GetXComponentId()

```
int32_t OH_NativeXComponent_GetXComponentId (OH_NativeXComponent * component, char * id, uint64_t * size )
```

**描述:**

获取ArkUI XComponent的id。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| id | 指示用于保存此OH_NativeXComponent实例的ID的字符缓冲区。&nbsp;请注意，空终止符将附加到字符缓冲区，因此字符缓冲区的大小应至少比真实id长度大一个单位。&nbsp;建议字符缓冲区的大小为[OH_XCOMPONENT_ID_LEN_MAX&nbsp;+&nbsp;1]。 |
| size | 指示指向id长度的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_GetXComponentOffset()

```
int32_t OH_NativeXComponent_GetXComponentOffset (OH_NativeXComponent * component, const void * window, double * x, double * y )
```

**描述:**

获取ArkUI XComponent组件相对屏幕左上顶点的偏移量。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| window | 表示NativeWindow句柄。 |
| x | 指示指向当前surface的x坐标的指针。 |
| y | 指示指向当前surface的y坐标的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_GetXComponentSize()

```
int32_t OH_NativeXComponent_GetXComponentSize (OH_NativeXComponent * component, const void * window, uint64_t * width, uint64_t * height )
```

**描述:**

获取ArkUI XComponent持有的surface的大小。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| window | 表示NativeWindow句柄。 |
| width | 指示指向当前surface宽度的指针。 |
| height | 指示指向当前surface高度的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_RegisterBlurEventCallback()

```
int32_t OH_NativeXComponent_RegisterBlurEventCallback (OH_NativeXComponent * component, void(*)(OH_NativeXComponent *component, void *window) callback )
```

**描述:**

为此OH_NativeXComponent实例注册失焦事件回调。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| callback | 指示指向失焦事件回调的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_RegisterCallback()

```
int32_t OH_NativeXComponent_RegisterCallback (OH_NativeXComponent * component, OH_NativeXComponent_Callback * callback )
```

**描述:**

为此OH_NativeXComponent实例注册回调。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| callback | 指示指向surface生命周期和触摸事件回调的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_RegisterFocusEventCallback()

```
int32_t OH_NativeXComponent_RegisterFocusEventCallback (OH_NativeXComponent * component, void(*)(OH_NativeXComponent *component, void *window) callback )
```

**描述:**

为此OH_NativeXComponent实例注册获焦事件回调。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| callback | 指示指向获焦事件回调的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_RegisterKeyEventCallback()

```
int32_t OH_NativeXComponent_RegisterKeyEventCallback (OH_NativeXComponent * component, void(*)(OH_NativeXComponent *component, void *window) callback )
```

**描述:**

为此OH_NativeXComponent实例注册按键事件回调。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| callback | 指示指向按键事件回调的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_RegisterMouseEventCallback()

```
int32_t OH_NativeXComponent_RegisterMouseEventCallback (OH_NativeXComponent * component, OH_NativeXComponent_MouseEvent_Callback * callback )
```

**描述:**

为此OH_NativeXComponent实例注册鼠标事件回调。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| callback | 指示指向鼠标事件回调的指针。 |

**返回:**

返回执行的状态代码。

**起始版本：**

9


## 变量说明


### OH_XCOMPONENT_ID_LEN_MAX

```
const uint32_t OH_XCOMPONENT_ID_LEN_MAX = 128
```


**描述：**


ArkUI XComponent的id最大长度。


**起始版本：**


8


### OH_MAX_TOUCH_POINTS_NUMBER

```
const uint32_t OH_MAX_TOUCH_POINTS_NUMBER = 10
```

**描述：**

触摸事件中的可识别的触摸点个数最大值。

**起始版本：**

8


### action

```
OH_NativeXComponent_MouseEventAction OH_NativeXComponent_MouseEvent::action
```

**描述:**

当前鼠标事件动作。

**起始版本：**

8


### button

```
OH_NativeXComponent_MouseEventButton OH_NativeXComponent_MouseEvent::button
```

**描述:**

鼠标事件按键。

**起始版本：**

8


### deviceId

```
int64_t OH_NativeXComponent_TouchEvent::deviceId = 0
```

**描述:**

产生当前触摸事件的设备的ID。

**起始版本：**

8


### DispatchHoverEvent

```
void(* OH_NativeXComponent_MouseEvent_Callback::DispatchHoverEvent) (OH_NativeXComponent *component, bool isHover)
```

**描述:**

当悬停事件被触发时调用。

**起始版本：**

8


### DispatchMouseEvent

```
void(* OH_NativeXComponent_MouseEvent_Callback::DispatchMouseEvent) (OH_NativeXComponent *component, void *window)
```

**描述:**

当鼠标事件被触发时调用。

**起始版本：**

8


### DispatchTouchEvent

```
void(* OH_NativeXComponent_Callback::DispatchTouchEvent) (OH_NativeXComponent *component, void *window)
```

**描述:**

当触摸事件被触发时调用。

**起始版本：**

8


### force [1/2]

```
float OH_NativeXComponent_TouchPoint::force = 0.0
```

**描述:**

当前触摸事件的压力。

**起始版本：**

8


### force [2/2]

```
float OH_NativeXComponent_TouchEvent::force = 0.0
```

**描述:**

当前触摸事件的压力。

**起始版本：**

8


### id [1/2]

```
int32_t OH_NativeXComponent_TouchPoint::id = 0
```

**描述:**

手指的唯一标识符。

**起始版本：**

8


### id [2/2]

```
int32_t OH_NativeXComponent_TouchEvent::id = 0
```

**描述:**

手指的唯一标识符。

**起始版本：**

8


### isPressed

```
bool OH_NativeXComponent_TouchPoint::isPressed = false
```

**描述:**

当前点是否被按下。

**起始版本：**

8


### numPoints

```
uint32_t OH_NativeXComponent_TouchEvent::numPoints = 0
```

**描述:**

当前接触点的数量。

**起始版本：**

8


### OnSurfaceChanged

```
void(* OH_NativeXComponent_Callback::OnSurfaceChanged) (OH_NativeXComponent *component, void *window)
```

**描述:**

当surface改变时调用。

**起始版本：**

8


### OnSurfaceCreated

```
void(* OH_NativeXComponent_Callback::OnSurfaceCreated) (OH_NativeXComponent *component, void *window)
```

**描述:**

创建surface时调用。

**起始版本：**

8


### OnSurfaceDestroyed

```
void(* OH_NativeXComponent_Callback::OnSurfaceDestroyed) (OH_NativeXComponent *component, void *window)
```

**描述:**

当surface被销毁时调用。

**起始版本：**

8


### screenX [1/3]

```
float OH_NativeXComponent_TouchPoint::screenX = 0.0
```

**描述:**

触摸点相对于XComponent所在应用窗口左上角的x坐标。

**起始版本：**

8


### screenX [2/3]

```
float OH_NativeXComponent_TouchEvent::screenX = 0.0
```

**描述:**

触摸点相对于屏幕左边缘的x坐标。

**起始版本：**

8


### screenX [3/3]

```
float OH_NativeXComponent_MouseEvent::screenX
```

**描述:**

点击触点相对于屏幕左上角的x轴坐标。

**起始版本：**

8


### screenY [1/3]

```
float OH_NativeXComponent_TouchPoint::screenY = 0.0
```

**描述:**

触摸点相对于XComponent所在应用窗口左上角的y坐标。

**起始版本：**

8


### screenY [2/3]

```
float OH_NativeXComponent_TouchEvent::screenY = 0.0
```

**描述:**

触摸点相对于屏幕上边缘的y坐标。

**起始版本：**

8


### screenY [3/3]

```
float OH_NativeXComponent_MouseEvent::screenY
```

**描述:**

点击触点相对于屏幕左上角的y轴坐标。

**起始版本：**

8


### size [1/2]

```
double OH_NativeXComponent_TouchPoint::size = 0.0
```

**描述:**

指垫和屏幕之间的接触面积。

**起始版本：**

8


### size [2/2]

```
double OH_NativeXComponent_TouchEvent::size = 0.0
```

**描述:**

指垫和屏幕之间的接触面积。

**起始版本：**

8


### timeStamp [1/2]

```
long long OH_NativeXComponent_TouchPoint::timeStamp = 0
```

**描述:**

当前触摸事件的时间戳。

**起始版本：**

8


### timeStamp [2/2]

```
long long OH_NativeXComponent_TouchEvent::timeStamp = 0
```

**描述:**

当前触摸事件的时间戳。

**起始版本：**

8


### timestamp

```
int64_t OH_NativeXComponent_MouseEvent::timestamp
```

**描述:**

当前鼠标事件的时间戳。

**起始版本：**

8


### touchPoints

```
OH_NativeXComponent_TouchPoint OH_NativeXComponent_TouchEvent::touchPoints[OH_MAX_TOUCH_POINTS_NUMBER]
```

**描述:**

当前触摸点的数组。

**起始版本：**

8


### type [1/2]

```
OH_NativeXComponent_TouchEventType OH_NativeXComponent_TouchPoint::type = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN
```

**描述:**

触摸事件的触摸类型。

**起始版本：**

8


### type [2/2]

```
OH_NativeXComponent_TouchEventType OH_NativeXComponent_TouchEvent::type = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN
```

**描述:**

触摸事件的触摸类型。

**起始版本：**

8


### x [1/3]

```
float OH_NativeXComponent_TouchPoint::x = 0.0
```

**描述:**

触摸点相对于XComponent组件左边缘的x坐标。

**起始版本：**

8


### x [2/3]

```
float OH_NativeXComponent_TouchEvent::x = 0.0
```

**描述:**

触摸点相对于XComponent组件左边缘的x坐标。

**起始版本：**

8


### x [3/3]

```
float OH_NativeXComponent_MouseEvent::x
```

**描述:**

点击触点相对于当前组件左上角的x轴坐标。

**起始版本：**

8


### y [1/3]

```
float OH_NativeXComponent_TouchPoint::y = 0.0
```

**描述:**

触摸点相对于XComponent组件上边缘的y坐标。

**起始版本：**

8


### y [2/3]

```
float OH_NativeXComponent_TouchEvent::y = 0.0
```

**描述:**

触摸点相对于XComponent组件上边缘的y坐标。

**起始版本：**

8


### y [3/3]

```
float OH_NativeXComponent_MouseEvent::y
```

**描述:**

点击触点相对于当前组件左上角的y轴坐标。

**起始版本：**

8
