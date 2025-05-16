# hid_ddk_types.h


## 概述

提供HID DDK中的枚举变量与结构体定义。

**引用文件：**&lt;hid/hid_ddk_types.h&gt;

**库：** libhid.z.so

**系统能力：** SystemCapability.Driver.HID.Extension

**起始版本：** 11

**相关模块：**[HID DDK](_hid_ddk.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[Hid_EmitItem](_hid___emit_item.md) | 事件信息。 | 
| struct&nbsp;&nbsp;[Hid_Device](_hid___device.md) | 设备基本信息。 | 
| struct&nbsp;&nbsp;[Hid_EventTypeArray](_hid___event_type_array.md) | 事件类型编码数组。 | 
| struct&nbsp;&nbsp;[Hid_KeyCodeArray](_hid___key_code_array.md) | 键值属性数组。 | 
| struct&nbsp;&nbsp;[Hid_AbsAxesArray](_hid___abs_axes_array.md) | 绝对坐标属性数组。 | 
| struct&nbsp;&nbsp;[Hid_RelAxesArray](_hid___rel_axes_array.md) | 相对坐标属性数组。 | 
| struct&nbsp;&nbsp;[Hid_MscEventArray](_hid___msc_event_array.md) | 其它特殊事件属性数组。 | 
| struct&nbsp;&nbsp;[Hid_EventProperties](_hid___event_properties.md) | 设备关注事件属性。 | 
| struct&nbsp;&nbsp;[Hid_RawDevInfo](_hid___raw_dev_info.md) | 原始设备信息定义。 | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [HID_MAX_REPORT_BUFFER_SIZE](_hid_ddk.md#hid_max_report_buffer_size)&nbsp;&nbsp;&nbsp;(16 \* 1024 - 1) | 最大报告缓冲区大小。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Hid_EmitItem](_hid___emit_item.md) [Hid_EmitItem](_hid_ddk.md#hid_emititem) | 事件信息。 | 
| typedef struct [Hid_Device](_hid___device.md) [Hid_Device](_hid_ddk.md#hid_device) | 设备基本信息。 | 
| typedef struct [Hid_EventTypeArray](_hid___event_type_array.md) [Hid_EventTypeArray](_hid_ddk.md#hid_eventtypearray) | 事件类型编码数组。 | 
| typedef struct [Hid_KeyCodeArray](_hid___key_code_array.md) [Hid_KeyCodeArray](_hid_ddk.md#hid_keycodearray) | 键值属性数组。 | 
| typedef struct [Hid_AbsAxesArray](_hid___abs_axes_array.md) [Hid_AbsAxesArray](_hid_ddk.md#hid_absaxesarray) | 绝对坐标属性数组。 | 
| typedef struct [Hid_RelAxesArray](_hid___rel_axes_array.md) [Hid_RelAxesArray](_hid_ddk.md#hid_relaxesarray) | 相对坐标属性数组。 | 
| typedef struct [Hid_MscEventArray](_hid___msc_event_array.md) [Hid_MscEventArray](_hid_ddk.md#hid_msceventarray) | 其它特殊事件属性数组。 | 
| typedef struct [Hid_EventProperties](_hid___event_properties.md) [Hid_EventProperties](_hid_ddk.md#hid_eventproperties) | 设备关注事件属性。 | 
| typedef struct [Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) [Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) | 不透明的USB HID设备结构。 | 
| typedef struct [Hid_RawDevInfo](_hid___raw_dev_info.md) [Hid_RawDevInfo](_hid_ddk.md#hid_rawdevinfo) | 原始设备信息定义。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Hid_DeviceProp](_hid_ddk.md#hid_deviceprop) {<br/>HID_PROP_POINTER = 0x00, HID_PROP_DIRECT = 0x01, HID_PROP_BUTTON_PAD = 0x02, HID_PROP_SEMI_MT = 0x03, HID_PROP_TOP_BUTTON_PAD = 0x04, HID_PROP_POINTING_STICK = 0x05, HID_PROP_ACCELEROMETER = 0x06<br/>} | 输入设备特性定义。 | 
| [Hid_EventType](_hid_ddk.md#hid_eventtype) {<br/>HID_EV_SYN = 0x00, HID_EV_KEY = 0x01, HID_EV_REL = 0x02, HID_EV_ABS = 0x03, HID_EV_MSC = 0x04<br/>} | 事件类型。 | 
| [Hid_SynEvent](_hid_ddk.md#hid_synevent) { HID_SYN_REPORT = 0, HID_SYN_CONFIG = 1, HID_SYN_MT_REPORT = 2, HID_SYN_DROPPED = 3 } | 同步事件编码。 | 
| [Hid_KeyCode](_hid_ddk.md#hid_keycode) {<br/>HID_KEY_A = 30, HID_KEY_B = 48, HID_KEY_C = 46, HID_KEY_D = 32, HID_KEY_E = 18, HID_KEY_F = 33, HID_KEY_G = 34, HID_KEY_H = 35, HID_KEY_I = 23, HID_KEY_J = 36, HID_KEY_K = 37, HID_KEY_L = 38, HID_KEY_M = 50, HID_KEY_N = 49, HID_KEY_O = 24, HID_KEY_P = 25, HID_KEY_Q = 16, HID_KEY_R = 19, HID_KEY_S = 31, HID_KEY_T = 20, HID_KEY_U = 22, HID_KEY_V = 47, HID_KEY_W = 17, HID_KEY_X = 45, HID_KEY_Y = 21, HID_KEY_Z = 44, HID_KEY_ESC = 1, HID_KEY_0 = 11, HID_KEY_1 = 2, HID_KEY_2 = 3, HID_KEY_3 = 4, HID_KEY_4 = 5, HID_KEY_5 = 6, HID_KEY_6 = 7, HID_KEY_7 = 8, HID_KEY_8 = 9, HID_KEY_9 = 10, HID_KEY_GRAVE = 41, HID_KEY_MINUS = 12, HID_KEY_EQUALS = 13, HID_KEY_BACKSPACE = 14, HID_KEY_LEFT_BRACKET = 26, HID_KEY_RIGHT_BRACKET = 27, HID_KEY_ENTER = 28, HID_KEY_LEFT_SHIFT = 42, HID_KEY_BACKSLASH = 43, HID_KEY_SEMICOLON = 39, HID_KEY_APOSTROPHE = 40, HID_KEY_SPACE = 57, HID_KEY_SLASH = 53, HID_KEY_COMMA = 51, HID_KEY_PERIOD = 52, HID_KEY_RIGHT_SHIFT = 54, HID_KEY_NUMPAD_0 = 82, HID_KEY_NUMPAD_1 = 79, HID_KEY_NUMPAD_2 = 80, HID_KEY_NUMPAD_3 = 81, HID_KEY_NUMPAD_4 = 75, HID_KEY_NUMPAD_5 = 76, HID_KEY_NUMPAD_6 = 77, HID_KEY_NUMPAD_7 = 71, HID_KEY_NUMPAD_8 = 72, HID_KEY_NUMPAD_9 = 73, HID_KEY_NUMPAD_DIVIDE = 70, HID_KEY_NUMPAD_MULTIPLY = 55, HID_KEY_NUMPAD_SUBTRACT = 74, HID_KEY_NUMPAD_ADD = 78, HID_KEY_NUMPAD_DOT = 83, HID_KEY_SYSRQ = 99, HID_KEY_DELETE = 111, HID_KEY_MUTE = 113, HID_KEY_VOLUME_DOWN = 114, HID_KEY_VOLUME_UP = 115, HID_KEY_BRIGHTNESS_DOWN = 224, HID_KEY_BRIGHTNESS_UP = 225, HID_BTN_0 = 0x100, HID_BTN_1 = 0x101, HID_BTN_2 = 0x102, HID_BTN_3 = 0x103, HID_BTN_4 = 0x104, HID_BTN_5 = 0x105, HID_BTN_6 = 0x106, HID_BTN_7 = 0x107, HID_BTN_8 = 0x108, HID_BTN_9 = 0x109, HID_BTN_LEFT = 0x110, HID_BTN_RIGHT = 0x111, HID_BTN_MIDDLE = 0x112, HID_BTN_SIDE = 0x113, HID_BTN_EXTRA = 0x114, HID_BTN_FORWARD = 0x115, HID_BTN_BACKWARD = 0x116, HID_BTN_TASK = 0x117, HID_BTN_TOOL_PEN = 0x140, HID_BTN_TOOL_RUBBER = 0x141, HID_BTN_TOOL_BRUSH = 0x142, HID_BTN_TOOL_PENCIL = 0x143, HID_BTN_TOOL_AIRBRUSH = 0x144, HID_BTN_TOOL_FINGER = 0x145, HID_BTN_TOOL_MOUSE = 0x146, HID_BTN_TOOL_LENS = 0x147, HID_BTN_TOOL_QUINT_TAP = 0x148, HID_BTN_STYLUS3 = 0x149, HID_BTN_TOUCH = 0x14a, HID_BTN_STYLUS = 0x14b, HID_BTN_STYLUS2 = 0x14c, HID_BTN_TOOL_DOUBLE_TAP = 0x14d, HID_BTN_TOOL_TRIPLE_TAP = 0x14e, HID_BTN_TOOL_QUAD_TAP = 0x14f, HID_BTN_WHEEL = 0x150<br/>} | 键值编码。 | 
| [Hid_AbsAxes](_hid_ddk.md#hid_absaxes) {<br/>HID_ABS_X = 0x00, HID_ABS_Y = 0x01, HID_ABS_Z = 0x02, HID_ABS_RX = 0x03, HID_ABS_RY = 0x04, HID_ABS_RZ = 0x05, HID_ABS_THROTTLE = 0x06, HID_ABS_RUDDER = 0x07, HID_ABS_WHEEL = 0x08, HID_ABS_GAS = 0x09, HID_ABS_BRAKE = 0x0a, HID_ABS_HAT0X = 0x10, HID_ABS_HAT0Y = 0x11, HID_ABS_HAT1X = 0x12, HID_ABS_HAT1Y = 0x13, HID_ABS_HAT2X = 0x14, HID_ABS_HAT2Y = 0x15, HID_ABS_HAT3X = 0x16, HID_ABS_HAT3Y = 0x17, HID_ABS_PRESSURE = 0x18, HID_ABS_DISTANCE = 0x19, HID_ABS_TILT_X = 0x1a, HID_ABS_TILT_Y = 0x1b, HID_ABS_TOOL_WIDTH = 0x1c, HID_ABS_VOLUME = 0x20, HID_ABS_MISC = 0x28<br/>} | 绝对坐标编码。 | 
| [Hid_RelAxes](_hid_ddk.md#hid_relaxes) {<br/>HID_REL_X = 0x00, HID_REL_Y = 0x01, HID_REL_Z = 0x02, HID_REL_RX = 0x03, HID_REL_RY = 0x04, HID_REL_RZ = 0x05, HID_REL_HWHEEL = 0x06, HID_REL_DIAL = 0x07, HID_REL_WHEEL = 0x08, HID_REL_MISC = 0x09, HID_REL_RESERVED = 0x0a, HID_REL_WHEEL_HI_RES = 0x0b, HID_REL_HWHEEL_HI_RES = 0x0c<br/>} | 相对坐标编码。 | 
| [Hid_MscEvent](_hid_ddk.md#hid_mscevent) {<br/>HID_MSC_SERIAL = 0x00, HID_MSC_PULSE_LED = 0x01, HID_MSC_GESTURE = 0x02, HID_MSC_RAW = 0x03, HID_MSC_SCAN = 0x04, HID_MSC_TIMESTAMP = 0x05<br/>} | 不适合其它类型的输入事件编码。 | 
| [Hid_DdkErrCode](_hid_ddk.md#hid_ddkerrcode) {<br/>HID_DDK_SUCCESS = 0, HID_DDK_NO_PERM = 201, HID_DDK_INVALID_PARAMETER = 401, HID_DDK_FAILURE = 27300001, HID_DDK_NULL_PTR = 27300002, HID_DDK_INVALID_OPERATION = 27300003, HID_DDK_TIMEOUT = 27300004, HID_DDK_INIT_ERROR = 27300005, HID_DDK_SERVICE_ERROR = 27300006, HID_DDK_MEMORY_ERROR = 27300007, HID_DDK_IO_ERROR = 27300008, HID_DDK_DEVICE_NOT_FOUND = 27300009<br/>} | HID DDK错误码定义。 | 
| [Hid_ReportType](_hid_ddk.md#hid_reporttype) { HID_INPUT_REPORT = 0, HID_OUTPUT_REPORT = 1, HID_FEATURE_REPORT = 2 } | 报告（HID设备与主机之间交换的数据包）类型定义。 | 
