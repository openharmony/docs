# hid_ddk_types.h


## 概述

提供HID DDK中的枚举变量与结构体定义。

引用文件：&lt;hid/hid_ddk_types.h&gt;

**起始版本：** 11

**相关模块：**[HID DDK](_hid_ddk.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [Hid_EmitItem](_hid___emit_item.md) | 事件信息。  | 
| [Hid_Device](_hid___device.md) | 设备基本信息。  | 
| [Hid_EventTypeArray](_hid___event_type_array.md) | 事件类型编码数组。  | 
| [Hid_KeyCodeArray](_hid___key_code_array.md) | 键值属性数组。  | 
| [Hid_AbsAxesArray](_hid___abs_axes_array.md) | 绝对坐标属性数组。  | 
| [Hid_RelAxesArray](_hid___rel_axes_array.md) | 相对坐标属性数组。  | 
| [Hid_MscEventArray](_hid___msc_event_array.md) | 其它特殊事件属性数组。  | 
| [Hid_EventProperties](_hid___event_properties.md) | 设备关注事件属性。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [Hid_EmitItem](_hid_ddk.md#hid_emititem) | 事件信息。  | 
| [Hid_Device](_hid_ddk.md#hid_device) | 设备基本信息。  | 
| [Hid_EventTypeArray](_hid_ddk.md#hid_eventtypearray) | 事件类型编码数组。  | 
| [Hid_KeyCodeArray](_hid_ddk.md#hid_keycodearray) | 键值属性数组。  | 
| [Hid_AbsAxesArray](_hid_ddk.md#hid_absaxesarray) | 绝对坐标属性数组。  | 
| [Hid_RelAxesArray](_hid_ddk.md#hid_relaxesarray) | 相对坐标属性数组。  | 
| [Hid_MscEventArray](_hid_ddk.md#hid_msceventarray) | 其它特殊事件属性数组。  | 
| [Hid_EventProperties](_hid_ddk.md#hid_eventproperties) | 设备关注事件属性。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Hid_DeviceProp](_hid_ddk.md#hid_deviceprop) {<br/>[HID_PROP_POINTER](_hid_ddk.md) = 0x00, [HID_PROP_DIRECT](_hid_ddk.md) = 0x01, [HID_PROP_BUTTON_PAD](_hid_ddk.md) = 0x02, [HID_PROP_SEMI_MT](_hid_ddk.md) = 0x03,<br/>[HID_PROP_TOP_BUTTON_PAD](_hid_ddk.md) = 0x04, [HID_PROP_POINTING_STICK](_hid_ddk.md) = 0x05, [HID_PROP_ACCELEROMETER](_hid_ddk.md) = 0x06<br/>} | 输入设备特性定义。  | 
| [Hid_EventType](_hid_ddk.md#hid_eventtype) {<br/>[HID_EV_SYN](_hid_ddk.md) = 0x00, [HID_EV_KEY](_hid_ddk.md) = 0x01, [HID_EV_REL](_hid_ddk.md) = 0x02, [HID_EV_ABS](_hid_ddk.md) = 0x03,<br/>[HID_EV_MSC](_hid_ddk.md) = 0x04<br/>} | 事件类型。  | 
| [Hid_SynEvent](_hid_ddk.md#hid_synevent) { [HID_SYN_REPORT](_hid_ddk.md) = 0, [HID_SYN_CONFIG](_hid_ddk.md) = 1, [HID_SYN_MT_REPORT](_hid_ddk.md) = 2, [HID_SYN_DROPPED](_hid_ddk.md) = 3 } | 同步事件编码。  | 
| [Hid_KeyCode](_hid_ddk.md#hid_keycode) {<br/>[HID_KEY_A](_hid_ddk.md) = 30, [HID_KEY_B](_hid_ddk.md) = 48, [HID_KEY_C](_hid_ddk.md) = 46, [HID_KEY_D](_hid_ddk.md) = 32,<br/>[HID_KEY_E](_hid_ddk.md) = 18, [HID_KEY_F](_hid_ddk.md) = 33, [HID_KEY_G](_hid_ddk.md) = 34, [HID_KEY_H](_hid_ddk.md) = 35,<br/>[HID_KEY_I](_hid_ddk.md) = 23, [HID_KEY_J](_hid_ddk.md) = 36, [HID_KEY_K](_hid_ddk.md) = 37, [HID_KEY_L](_hid_ddk.md) = 38,<br/>[HID_KEY_M](_hid_ddk.md) = 50, [HID_KEY_N](_hid_ddk.md) = 49, [HID_KEY_O](_hid_ddk.md) = 24, [HID_KEY_P](_hid_ddk.md) = 25,<br/>[HID_KEY_Q](_hid_ddk.md) = 16, [HID_KEY_R](_hid_ddk.md) = 19, [HID_KEY_S](_hid_ddk.md) = 31, [HID_KEY_T](_hid_ddk.md) = 20,<br/>[HID_KEY_U](_hid_ddk.md) = 22, [HID_KEY_V](_hid_ddk.md) = 47, [HID_KEY_W](_hid_ddk.md) = 17, [HID_KEY_X](_hid_ddk.md) = 45,<br/>[HID_KEY_Y](_hid_ddk.md) = 21, [HID_KEY_Z](_hid_ddk.md) = 44, [HID_KEY_ESC](_hid_ddk.md) = 1, [HID_KEY_0](_hid_ddk.md) = 11,<br/>[HID_KEY_1](_hid_ddk.md) = 2, [HID_KEY_2](_hid_ddk.md) = 3, [HID_KEY_3](_hid_ddk.md) = 4, [HID_KEY_4](_hid_ddk.md) = 5,<br/>[HID_KEY_5](_hid_ddk.md) = 6, [HID_KEY_6](_hid_ddk.md) = 7, [HID_KEY_7](_hid_ddk.md) = 8, [HID_KEY_8](_hid_ddk.md) = 9,<br/>[HID_KEY_9](_hid_ddk.md) = 10, [HID_KEY_GRAVE](_hid_ddk.md) = 41, [HID_KEY_MINUS](_hid_ddk.md) = 12, [HID_KEY_EQUALS](_hid_ddk.md) = 13,<br/>[HID_KEY_BACKSPACE](_hid_ddk.md) = 14, [HID_KEY_LEFT_BRACKET](_hid_ddk.md) = 26, [HID_KEY_RIGHT_BRACKET](_hid_ddk.md) = 27, [HID_KEY_ENTER](_hid_ddk.md) = 28,<br/>[HID_KEY_LEFT_SHIFT](_hid_ddk.md) = 42, [HID_KEY_BACKSLASH](_hid_ddk.md) = 43, [HID_KEY_SEMICOLON](_hid_ddk.md) = 39, [HID_KEY_APOSTROPHE](_hid_ddk.md) = 40,<br/>[HID_KEY_SPACE](_hid_ddk.md) = 57, [HID_KEY_SLASH](_hid_ddk.md) = 53, [HID_KEY_COMMA](_hid_ddk.md) = 51, [HID_KEY_PERIOD](_hid_ddk.md) = 52,<br/>[HID_KEY_RIGHT_SHIFT](_hid_ddk.md) = 54, [HID_KEY_NUMPAD_0](_hid_ddk.md) = 82, [HID_KEY_NUMPAD_1](_hid_ddk.md) = 79, [HID_KEY_NUMPAD_2](_hid_ddk.md) = 80,<br/>[HID_KEY_NUMPAD_3](_hid_ddk.md) = 81, [HID_KEY_NUMPAD_4](_hid_ddk.md) = 75, [HID_KEY_NUMPAD_5](_hid_ddk.md) = 76, [HID_KEY_NUMPAD_6](_hid_ddk.md) = 77,<br/>[HID_KEY_NUMPAD_7](_hid_ddk.md) = 71, [HID_KEY_NUMPAD_8](_hid_ddk.md) = 72, [HID_KEY_NUMPAD_9](_hid_ddk.md) = 73, [HID_KEY_NUMPAD_DIVIDE](_hid_ddk.md) = 70,<br/>[HID_KEY_NUMPAD_MULTIPLY](_hid_ddk.md) = 55, [HID_KEY_NUMPAD_SUBTRACT](_hid_ddk.md) = 74, [HID_KEY_NUMPAD_ADD](_hid_ddk.md) = 78, [HID_KEY_NUMPAD_DOT](_hid_ddk.md) = 83,<br/>[HID_KEY_SYSRQ](_hid_ddk.md) = 99, [HID_KEY_MUTE](_hid_ddk.md) = 113, [HID_KEY_VOLUME_DOWN](_hid_ddk.md) = 114, [HID_KEY_VOLUME_UP](_hid_ddk.md) = 115,<br/>[HID_KEY_BRIGHTNESS_DOWN](_hid_ddk.md) = 224, [HID_KEY_BRIGHTNESS_UP](_hid_ddk.md) = 225, [HID_BTN_0](_hid_ddk.md) = 0x100, [HID_BTN_1](_hid_ddk.md) = 0x101,<br/>[HID_BTN_2](_hid_ddk.md) = 0x102, [HID_BTN_3](_hid_ddk.md) = 0x103, [HID_BTN_4](_hid_ddk.md) = 0x104, [HID_BTN_5](_hid_ddk.md) = 0x105,<br/>[HID_BTN_6](_hid_ddk.md) = 0x106, [HID_BTN_7](_hid_ddk.md) = 0x107, [HID_BTN_8](_hid_ddk.md) = 0x108, [HID_BTN_9](_hid_ddk.md) = 0x109,<br/>[HID_BTN_LEFT](_hid_ddk.md) = 0x110, [HID_BTN_RIGHT](_hid_ddk.md) = 0x111, [HID_BTN_MIDDLE](_hid_ddk.md) = 0x112, [HID_BTN_SIDE](_hid_ddk.md) = 0x113,<br/>[HID_BTN_EXTRA](_hid_ddk.md) = 0x114, [HID_BTN_FORWARD](_hid_ddk.md) = 0x115, [HID_BTN_BACKWARD](_hid_ddk.md) = 0x116, [HID_BTN_TASK](_hid_ddk.md) = 0x117,<br/>[HID_BTN_TOOL_PEN](_hid_ddk.md) = 0x140, [HID_BTN_TOOL_RUBBER](_hid_ddk.md) = 0x141, [HID_BTN_TOOL_BRUSH](_hid_ddk.md) = 0x142, [HID_BTN_TOOL_PENCIL](_hid_ddk.md) = 0x143,<br/>[HID_BTN_TOOL_AIRBRUSH](_hid_ddk.md) = 0x144, [HID_BTN_TOOL_FINGER](_hid_ddk.md) = 0x145, [HID_BTN_TOOL_MOUSE](_hid_ddk.md) = 0x146, [HID_BTN_TOOL_LENS](_hid_ddk.md) = 0x147,<br/>[HID_BTN_TOOL_QUINT_TAP](_hid_ddk.md) = 0x148, [HID_BTN_STYLUS3](_hid_ddk.md) = 0x149, [HID_BTN_TOUCH](_hid_ddk.md) = 0x14a, [HID_BTN_STYLUS](_hid_ddk.md) = 0x14b,<br/>[HID_BTN_STYLUS2](_hid_ddk.md) = 0x14c, [HID_BTN_TOOL_DOUBLE_TAP](_hid_ddk.md) = 0x14d, [HID_BTN_TOOL_TRIPLE_TAP](_hid_ddk.md) = 0x14e, [HID_BTN_TOOL_QUAD_TAP](_hid_ddk.md) = 0x14f,<br/>[HID_BTN_WHEEL](_hid_ddk.md) = 0x150<br/>} | 键值编码。  | 
| [Hid_AbsAxes](_hid_ddk.md#hid_absaxes) {<br/>[HID_ABS_X](_hid_ddk.md) = 0x00, [HID_ABS_Y](_hid_ddk.md) = 0x01, [HID_ABS_Z](_hid_ddk.md) = 0x02, [HID_ABS_RX](_hid_ddk.md) = 0x03,<br/>[HID_ABS_RY](_hid_ddk.md) = 0x04, [HID_ABS_RZ](_hid_ddk.md) = 0x05, [HID_ABS_THROTTLE](_hid_ddk.md) = 0x06, [HID_ABS_RUDDER](_hid_ddk.md) = 0x07,<br/>[HID_ABS_WHEEL](_hid_ddk.md) = 0x08, [HID_ABS_GAS](_hid_ddk.md) = 0x09, [HID_ABS_BRAKE](_hid_ddk.md) = 0x0a, [HID_ABS_HAT0X](_hid_ddk.md) = 0x10,<br/>[HID_ABS_HAT0Y](_hid_ddk.md) = 0x11, [HID_ABS_HAT1X](_hid_ddk.md) = 0x12, [HID_ABS_HAT1Y](_hid_ddk.md) = 0x13, [HID_ABS_HAT2X](_hid_ddk.md) = 0x14,<br/>[HID_ABS_HAT2Y](_hid_ddk.md) = 0x15, [HID_ABS_HAT3X](_hid_ddk.md) = 0x16, [HID_ABS_HAT3Y](_hid_ddk.md) = 0x17, [HID_ABS_PRESSURE](_hid_ddk.md) = 0x18,<br/>[HID_ABS_DISTANCE](_hid_ddk.md) = 0x19, [HID_ABS_TILT_X](_hid_ddk.md) = 0x1a, [HID_ABS_TILT_Y](_hid_ddk.md) = 0x1b, [HID_ABS_TOOL_WIDTH](_hid_ddk.md) = 0x1c,<br/>[HID_ABS_VOLUME](_hid_ddk.md) = 0x20, [HID_ABS_MISC](_hid_ddk.md) = 0x28<br/>} | 绝对坐标编码。  | 
| [Hid_RelAxes](_hid_ddk.md#hid_relaxes) {<br/>[HID_REL_X](_hid_ddk.md) = 0x00, [HID_REL_Y](_hid_ddk.md) = 0x01, [HID_REL_Z](_hid_ddk.md) = 0x02, [HID_REL_RX](_hid_ddk.md) = 0x03,<br/>[HID_REL_RY](_hid_ddk.md) = 0x04, [HID_REL_RZ](_hid_ddk.md) = 0x05, [HID_REL_HWHEEL](_hid_ddk.md) = 0x06, [HID_REL_DIAL](_hid_ddk.md) = 0x07,<br/>[HID_REL_WHEEL](_hid_ddk.md) = 0x08, [HID_REL_MISC](_hid_ddk.md) = 0x09, [HID_REL_RESERVED](_hid_ddk.md) = 0x0a, [HID_REL_WHEEL_HI_RES](_hid_ddk.md) = 0x0b,<br/>[HID_REL_HWHEEL_HI_RES](_hid_ddk.md) = 0x0c<br/>} | 相对坐标编码。  | 
| [Hid_MscEvent](_hid_ddk.md#hid_mscevent) {<br/>[HID_MSC_SERIAL](_hid_ddk.md) = 0x00, [HID_MSC_PULSE_LED](_hid_ddk.md) = 0x01, [HID_MSC_GESTURE](_hid_ddk.md) = 0x02, [HID_MSC_RAW](_hid_ddk.md) = 0x03,<br/>[HID_MSC_SCAN](_hid_ddk.md) = 0x04, [HID_MSC_TIMESTAMP](_hid_ddk.md) = 0x05<br/>} | 不适合其它类型的输入事件编码。  | 
| [Hid_DdkErrCode](_hid_ddk.md#hid_ddkerrcode) {<br/>[HID_DDK_SUCCESS](_hid_ddk.md) = 0, [HID_DDK_FAILURE](_hid_ddk.md) = -1, [HID_DDK_INVALID_PARAMETER](_hid_ddk.md) = -2, [HID_DDK_INVALID_OPERATION](_hid_ddk.md) = -3,<br/>[HID_DDK_NULL_PTR](_hid_ddk.md) = -4, [HID_DDK_TIMEOUT](_hid_ddk.md) = -5, [HID_DDK_NO_PERM](_hid_ddk.md) = -6<br/>} | HID DDK错误码定义。  | 
