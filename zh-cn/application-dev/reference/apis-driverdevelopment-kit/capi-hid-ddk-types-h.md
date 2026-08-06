# hid_ddk_types.h
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

## 概述

提供HID DDK中的枚举变量与结构体定义，支持开发者在驱动开发中定义和操作HID设备，适用于与鼠标、键盘、触摸屏等输入设备交互的场景，提供了设备特性、事件类型、键值编码、坐标轴等完整定义，帮助开发者快速实现HID设备的驱动开发。

**引用文件：** <hid/hid_ddk_types.h>

**库：** libhid.z.so

**系统能力：** SystemCapability.Driver.HID.Extension

**起始版本：** 11

**相关模块：** [HidDdk](capi-hidddk.md)

## 汇总

### 结构体

| 名称                                                        | typedef关键字 | 描述 |
|-----------------------------------------------------------| -- | -- |
| [Hid_EmitItem](capi-hidddk-hid-emititem.md)               | Hid_EmitItem | 表示HID事件信息结构体，包含事件类型、事件编码和事件值，用于描述输入设备的上报事件。在驱动开发场景中，该结构体用于传递和识别各类HID设备产生的事件。 |
| [Hid_Device](capi-hidddk-hid-device.md)                   | Hid_Device | 设备基本信息，用于表示HID设备的名称、厂商ID、产品ID等基本属性，在创建和操作HID设备时作为设备标识使用。 |
| [Hid_EventTypeArray](capi-hidddk-hid-eventtypearray.md)   | Hid_EventTypeArray | 事件类型编码数组，用于存储HID设备支持的事件类型信息。 |
| [Hid_KeyCodeArray](capi-hidddk-hid-keycodearray.md)       | Hid_KeyCodeArray | 键值属性编码数组，用于存储HID设备支持的键值编码信息。 |
| [Hid_AbsAxesArray](capi-hidddk-hid-absaxesarray.md)       | Hid_AbsAxesArray | 绝对坐标属性数组，用于存储HID设备的多个绝对坐标轴的属性信息，支持描述如触摸屏、游戏摇杆等输入设备的坐标特征，适用于需要精确读取和处理多维输入数据的驱动开发场景，例如在手柄、触摸板等输入设备中记录轴位数据。 |
| [Hid_RelAxesArray](capi-hidddk-hid-relaxesarray.md)       | Hid_RelAxesArray | 相对坐标属性编码数组，用于存储HID设备支持的相对坐标属性信息。 |
| [Hid_MscEventArray](capi-hidddk-hid-msceventarray.md)     | Hid_MscEventArray | 其他特殊事件属性数组，用于存储HID设备支持的特殊事件信息。 |
| [Hid_EventProperties](capi-hidddk-hid-eventproperties.md) | Hid_EventProperties | 设备事件属性，包括事件类型、键值、绝对坐标、相对坐标等各类事件属性编码及取值范围。用于HID设备的属性配置，适用于需要精细化管理输入事件的场景。使用结构体前，需根据HID设备规范初始化所有成员变量。 |
| [Hid_RawDevInfo](capi-hidddk-hid-rawdevinfo.md)           | Hid_RawDevInfo | HID原始设备信息，包含总线类型、供应商ID、产品ID等关键标识信息。开发者可以通过此结构体识别和区分不同的HID设备，通常用于设备识别、设备匹配、设备过滤等场景。 |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md)       | Hid_DeviceHandle | 不透明的USB HID设备结构，用于标识和操作HID设备实例。开发者通过该句柄进行HID设备的打开、关闭、读写等操作。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Hid_DeviceProp](#hid_deviceprop) | Hid_DeviceProp | 输入设备特性定义。 |
| [Hid_EventType](#hid_eventtype) | Hid_EventType | 事件类型。用于标识HID设备产生的事件类别，在驱动开发中用于事件分类和处理。 |
| [Hid_SynEvent](#hid_synevent) | Hid_SynEvent | 同步事件编码。 |
| [Hid_KeyCode](#hid_keycode) | Hid_KeyCode | 键值编码。包括键盘、鼠标、触摸屏等输入设备的按键和事件编码。 |
| [Hid_AbsAxes](#hid_absaxes) | Hid_AbsAxes | 绝对坐标编码。 |
| [Hid_RelAxes](#hid_relaxes) | Hid_RelAxes | 相对坐标编码。 |
| [Hid_MscEvent](#hid_mscevent) | Hid_MscEvent | 不适合其他类型的输入事件编码。 |
| [Hid_DdkErrCode](#hid_ddkerrcode) | Hid_DdkErrCode | HID DDK错误码定义。 |
| [Hid_ReportType](#hid_reporttype) | Hid_ReportType | 报告（HID设备与主机之间交换的数据包）类型定义，用于标识HID设备与主机之间通信的数据包类型，在设备通信和数据交换场景中使用。 |

### 宏定义

| 名称 | 描述 |
| -- | -- |
| HID_MAX_REPORT_BUFFER_SIZE (16 * 1024 - 1) | 最大报告缓冲区大小。 |

## 枚举类型说明

### Hid_DeviceProp

```c
enum Hid_DeviceProp
```

**描述**

输入设备特性定义。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| HID_PROP_POINTER = 0x00 | 指针设备。 |
| HID_PROP_DIRECT = 0x01 | 直接输入设备。 |
| HID_PROP_BUTTON_PAD = 0x02 | 底部按键触摸设备。 |
| HID_PROP_SEMI_MT = 0x03 | 半多点触控设备。 |
| HID_PROP_TOP_BUTTON_PAD = 0x04 | 顶部软按键触摸设备。 |
| HID_PROP_POINTING_STICK = 0x05 | 指点杆设备。 |
| HID_PROP_ACCELEROMETER = 0x06 | 加速度传感器设备。 |

### Hid_EventType

```c
enum Hid_EventType
```

**描述**

事件类型。用于标识HID设备产生的事件类别，在驱动开发中用于事件分类和处理。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| HID_EV_SYN = 0x00 | 同步事件。 |
| HID_EV_KEY = 0x01 | 按键事件。 |
| HID_EV_REL = 0x02 | 相对坐标事件。 |
| HID_EV_ABS = 0x03 | 绝对坐标事件。 |
| HID_EV_MSC = 0x04 | 特殊事件。 |

### Hid_SynEvent

```c
enum Hid_SynEvent
```

**描述**

同步事件编码。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| HID_SYN_REPORT = 0 | 表示一个事件的结束。 |
| HID_SYN_CONFIG = 1 | 表示配置同步。 |
| HID_SYN_MT_REPORT = 2 | 表示多点触摸的ABS数据包结束。 |
| HID_SYN_DROPPED = 3 | 表示该事件被丢弃。 |

### Hid_KeyCode

```c
enum Hid_KeyCode
```

**描述**

键值编码。包括键盘、鼠标、触摸屏等输入设备的按键和事件编码。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| HID_KEY_A = 30 | 键“A”。 |
| HID_KEY_B = 48 | 键“B”。 |
| HID_KEY_C = 46 | 键“C”。 |
| HID_KEY_D = 32 | 键“D”。 |
| HID_KEY_E = 18 | 键“E”。 |
| HID_KEY_F = 33 | 键“F”。 |
| HID_KEY_G = 34 | 键“G”。 |
| HID_KEY_H = 35 | 键“H”。 |
| HID_KEY_I = 23 | 键“I”。 |
| HID_KEY_J = 36 | 键“J”。 |
| HID_KEY_K = 37 | 键“K”。 |
| HID_KEY_L = 38 | 键“L”。 |
| HID_KEY_M = 50 | 键“M”。 |
| HID_KEY_N = 49 | 键“N”。 |
| HID_KEY_O = 24 | 键“O”。 |
| HID_KEY_P = 25 | 键“P”。 |
| HID_KEY_Q = 16 | 键“Q”。 |
| HID_KEY_R = 19 | 键“R”。 |
| HID_KEY_S = 31 | 键“S”。 |
| HID_KEY_T = 20 | 键“T”。 |
| HID_KEY_U = 22 | 键“U”。 |
| HID_KEY_V = 47 | 键“V”。 |
| HID_KEY_W = 17 | 键“W”。 |
| HID_KEY_X = 45 | 键“X”。 |
| HID_KEY_Y = 21 | 键“Y”。 |
| HID_KEY_Z = 44 | 键“Z”。 |
| HID_KEY_ESC = 1 | 键ESC。 |
| HID_KEY_0 = 11 | 键“0”。 |
| HID_KEY_1 = 2 | 键“1”。 |
| HID_KEY_2 = 3 | 键“2”。 |
| HID_KEY_3 = 4 | 键“3”。 |
| HID_KEY_4 = 5 | 键“4”。 |
| HID_KEY_5 = 6 | 键“5”。 |
| HID_KEY_6 = 7 | 键“6”。 |
| HID_KEY_7 = 8 | 键“7”。 |
| HID_KEY_8 = 9 | 键“8”。 |
| HID_KEY_9 = 10 | 键“9”。 |
| HID_KEY_GRAVE = 41 | 键“`”。 |
| HID_KEY_MINUS = 12 | 键“-”。 |
| HID_KEY_EQUALS = 13 | 键“=”。 |
| HID_KEY_BACKSPACE = 14 | 键退格。 |
| HID_KEY_LEFT_BRACKET = 26 | 键“[”。 |
| HID_KEY_RIGHT_BRACKET = 27 | 键“]”。 |
| HID_KEY_ENTER = 28 | 键回车。 |
| HID_KEY_LEFT_SHIFT = 42 | 键左shift。 |
| HID_KEY_BACKSLASH = 43 | 键“\”。 |
| HID_KEY_SEMICOLON = 39 | 键“;”。 |
| HID_KEY_APOSTROPHE = 40 | 键“'”。 |
| HID_KEY_SPACE = 57 | 键空格。 |
| HID_KEY_SLASH = 53 | 键“/”。 |
| HID_KEY_COMMA = 51 | 键“,”。 |
| HID_KEY_PERIOD = 52 | 键“.”。 |
| HID_KEY_RIGHT_SHIFT = 54 | 键右shift。 |
| HID_KEY_NUMPAD_0 = 82 | 数字小键盘的“0”键。 |
| HID_KEY_NUMPAD_1 = 79 | 数字小键盘的“1”键。 |
| HID_KEY_NUMPAD_2 = 80 | 数字小键盘的“2”键。 |
| HID_KEY_NUMPAD_3 = 81 | 数字小键盘的“3”键。 |
| HID_KEY_NUMPAD_4 = 75 | 数字小键盘的“4”键。 |
| HID_KEY_NUMPAD_5 = 76 | 数字小键盘的“5”键。 |
| HID_KEY_NUMPAD_6 = 77 | 数字小键盘的“6”键。 |
| HID_KEY_NUMPAD_7 = 71 | 数字小键盘的“7”键。 |
| HID_KEY_NUMPAD_8 = 72 | 数字小键盘的“8”键。 |
| HID_KEY_NUMPAD_9 = 73 | 数字小键盘的“9”键。 |
| HID_KEY_NUMPAD_DIVIDE = 70 | 数字小键盘的“/”键。 |
| HID_KEY_NUMPAD_MULTIPLY = 55 | 数字小键盘的“*”键。 |
| HID_KEY_NUMPAD_SUBTRACT = 74 | 数字小键盘的“-”键。 |
| HID_KEY_NUMPAD_ADD = 78 | 数字小键盘的“+”键。 |
| HID_KEY_NUMPAD_DOT = 83 | 数字小键盘的“.”键。 |
| HID_KEY_SYSRQ = 99 | 键打印屏幕。 |
| HID_KEY_DELETE = 111 | 键删除。 |
| HID_KEY_MUTE = 113 | 键静音。 |
| HID_KEY_VOLUME_DOWN = 114 | 键音量-。 |
| HID_KEY_VOLUME_UP = 115 | 键音量+。 |
| HID_KEY_BRIGHTNESS_DOWN = 224 | 键亮度-。 |
| HID_KEY_BRIGHTNESS_UP = 225 | 键亮度+。 |
| HID_BTN_0 = 0x100 | 按钮0。 |
| HID_BTN_1 = 0x101 | 按钮1。 |
| HID_BTN_2 = 0x102 | 按钮2。 |
| HID_BTN_3 = 0x103 | 按钮3。 |
| HID_BTN_4 = 0x104 | 按钮4。 |
| HID_BTN_5 = 0x105 | 按钮5。 |
| HID_BTN_6 = 0x106 | 按钮6。 |
| HID_BTN_7 = 0x107 | 按钮7。 |
| HID_BTN_8 = 0x108 | 按钮8。 |
| HID_BTN_9 = 0x109 | 按钮9。 |
| HID_BTN_LEFT = 0x110 | 鼠标按键左键。 |
| HID_BTN_RIGHT = 0x111 | 鼠标按键右键。 |
| HID_BTN_MIDDLE = 0x112 | 鼠标按键中键。 |
| HID_BTN_SIDE = 0x113 | 鼠标侧面按键。 |
| HID_BTN_EXTRA = 0x114 | 鼠标附加按键。 |
| HID_BTN_FORWARD = 0x115 | 鼠标向前按键。 |
| HID_BTN_BACKWARD = 0x116 | 鼠标向后按键。 |
| HID_BTN_TASK = 0x117 | 鼠标任务按键。 |
| HID_BTN_TOOL_PEN = 0x140 | 画笔。 |
| HID_BTN_TOOL_RUBBER = 0x141 | 橡皮擦。 |
| HID_BTN_TOOL_BRUSH = 0x142 | 笔刷。 |
| HID_BTN_TOOL_PENCIL = 0x143 | 钢笔。 |
| HID_BTN_TOOL_AIRBRUSH = 0x144 | 喷枪。 |
| HID_BTN_TOOL_FINGER = 0x145 | 手指。 |
| HID_BTN_TOOL_MOUSE = 0x146 | 鼠标。 |
| HID_BTN_TOOL_LENS = 0x147 | 镜头。 |
| HID_BTN_TOOL_QUINT_TAP = 0x148 | 五指触控。 |
| HID_BTN_STYLUS3 = 0x149 | 手写笔3。 |
| HID_BTN_TOUCH = 0x14a | 触摸。 |
| HID_BTN_STYLUS = 0x14b | 手写笔。 |
| HID_BTN_STYLUS2 = 0x14c | 手写笔2。 |
| HID_BTN_TOOL_DOUBLE_TAP = 0x14d | 二指触控。 |
| HID_BTN_TOOL_TRIPLE_TAP = 0x14e | 三指触控。 |
| HID_BTN_TOOL_QUAD_TAP = 0x14f | 四指触控。 |
| HID_BTN_WHEEL = 0x150 | 滚轮。 |

### Hid_AbsAxes

```c
enum Hid_AbsAxes
```

**描述**

绝对坐标编码。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| HID_ABS_X = 0x00 | X轴。 |
| HID_ABS_Y = 0x01 | Y轴。 |
| HID_ABS_Z = 0x02 | Z轴。 |
| HID_ABS_RX = 0x03 | 右模拟摇杆的 X 轴。 |
| HID_ABS_RY = 0x04 | 右模拟摇杆的 Y 轴。 |
| HID_ABS_RZ = 0x05 | 右模拟摇杆的 Z 轴。 |
| HID_ABS_THROTTLE = 0x06 | 油门控制。 |
| HID_ABS_RUDDER = 0x07 | 方向舵。 |
| HID_ABS_WHEEL = 0x08 | 滚轮。 |
| HID_ABS_GAS = 0x09 | 油门踏板。 |
| HID_ABS_BRAKE = 0x0a | 制动。 |
| HID_ABS_HAT0X = 0x10 | HAT0X，游戏手柄或操纵器的方向键X轴，表示水平方向的倾斜或旋转角度。 |
| HID_ABS_HAT0Y = 0x11 | HAT0Y，游戏手柄或操纵器的方向键Y轴，表示垂直方向的倾斜或旋转角度。 |
| HID_ABS_HAT1X = 0x12 | HAT1X，游戏手柄或操纵器的第二个方向键X轴，表示水平方向的倾斜或旋转角度。 |
| HID_ABS_HAT1Y = 0x13 | HAT1Y，游戏手柄或操纵器的第二个方向键Y轴，表示垂直方向的倾斜或旋转角度。 |
| HID_ABS_HAT2X = 0x14 | HAT2X，游戏手柄或操纵器的第三个方向键X轴，表示水平方向的倾斜或旋转角度。 |
| HID_ABS_HAT2Y = 0x15 | HAT2Y，游戏手柄或操纵器的第三个方向键Y轴，表示垂直方向的倾斜或旋转角度。 |
| HID_ABS_HAT3X = 0x16 | HAT3X，游戏手柄或操纵器的第四个方向键X轴，表示水平方向的倾斜或旋转角度。 |
| HID_ABS_HAT3Y = 0x17 | HAT3Y，游戏手柄或操纵器的第四个方向键Y轴，表示垂直方向的倾斜或旋转角度。 |
| HID_ABS_PRESSURE = 0x18 | 压力。 |
| HID_ABS_DISTANCE = 0x19 | 距离。 |
| HID_ABS_TILT_X = 0x1a | X轴倾斜度。 |
| HID_ABS_TILT_Y = 0x1b | Y轴倾斜度。 |
| HID_ABS_TOOL_WIDTH = 0x1c | 触摸工具的宽度。 |
| HID_ABS_VOLUME = 0x20 | 音量。 |
| HID_ABS_MISC = 0x28 | 其他类型的绝对坐标轴，用于不适合归入上述分类的特殊轴类型。 |

### Hid_RelAxes

```c
enum Hid_RelAxes
```

**描述**

相对坐标编码。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| HID_REL_X = 0x00 | X轴。 |
| HID_REL_Y = 0x01 | Y轴。 |
| HID_REL_Z = 0x02 | Z轴。 |
| HID_REL_RX = 0x03 | 右模拟摇杆的 X 轴。 |
| HID_REL_RY = 0x04 | 右模拟摇杆的 Y 轴。 |
| HID_REL_RZ = 0x05 | 右模拟摇杆的 Z 轴。 |
| HID_REL_HWHEEL = 0x06 | 水平滚轮，表示鼠标水平滚轮的滚动方向和距离，用于水平方向的滚动操作。 |
| HID_REL_DIAL = 0x07 | 刻度，表示旋钮或刻度盘的旋转方向和距离，用于调节音量、亮度或其他可调节参数。 |
| HID_REL_WHEEL = 0x08 | 垂直滚轮，表示鼠标垂直滚轮的滚动方向和距离，用于垂直方向的滚动操作。 |
| HID_REL_MISC = 0x09 | 其他类型的相对坐标事件，用于不适合归入上述分类的特殊相对坐标事件。 |
| HID_REL_RESERVED = 0x0a | 预留。 |
| HID_REL_WHEEL_HI_RES = 0x0b | 高分辨率滚轮，表示鼠标高精度滚轮的滚动方向和距离，提供比普通滚轮更高的分辨率和精度。 |
| HID_REL_HWHEEL_HI_RES = 0x0c | 高分辨率水平滚轮，表示鼠标高精度水平滚轮的滚动方向和距离，提供比普通水平滚轮更高的分辨率和精度。 |

### Hid_MscEvent

```c
enum Hid_MscEvent
```

**描述**

不适合其他类型的输入事件编码。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| HID_MSC_SERIAL = 0x00 | 序列号。 |
| HID_MSC_PULSE_LED = 0x01 | 脉冲。 |
| HID_MSC_GESTURE = 0x02 | 手势。 |
| HID_MSC_RAW = 0x03 | 原始事件。 |
| HID_MSC_SCAN = 0x04 | 扫描。 |
| HID_MSC_TIMESTAMP = 0x05 | 时间戳。 |

### Hid_DdkErrCode

```c
enum Hid_DdkErrCode
```

**描述**

HID DDK错误码定义。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| HID_DDK_SUCCESS = 0 | 操作成功。 |
| HID_DDK_NO_PERM = 201 | 没有权限，从API 16起，取值由-6变更为201。请检查应用是否已正确获取所需的权限。 |
| HID_DDK_INVALID_PARAMETER = 401 | 非法参数，从API 16起，取值由-2变更为401。请检查参数取值是否符合要求。 |
| HID_DDK_FAILURE = 27300001 | DDK接口执行失败，从API 16起，取值由-1变更为27300001。可能原因：设备状态异常或通信异常。请检查设备状态和参数设置。 |
| HID_DDK_NULL_PTR = 27300002 | 空指针异常，从API 16起，取值由-4变更为27300002。请检查传入参数的有效性。 |
| HID_DDK_INVALID_OPERATION = 27300003 | 非法操作，从API 16起，取值由-3变更为27300003。可能原因：调用API的时机或顺序不正确。请检查调用时机、以及是否初始化DDK。 |
| HID_DDK_TIMEOUT = 27300004 | 超时，从API 16起，取值由-5变更为27300004。请检查设备状态和超时时间设置。 |
| HID_DDK_INIT_ERROR = 27300005 | 初始化DDK失败或DDK未初始化。请检查系统服务状态，确保在调用API前先初始化DDK。<br> **起始版本：** 18 |
| HID_DDK_SERVICE_ERROR = 27300006 | 服务通信过程中错误。可能原因：服务内部错误。请检查当前操作和设备状态。<br> **起始版本：** 18 |
| HID_DDK_MEMORY_ERROR = 27300007 | 内存相关的错误，包括：内存数据拷贝失败、内存申请失败等。请检查内存使用情况和相关参数。<br> **起始版本：** 18 |
| HID_DDK_IO_ERROR = 27300008 | I/O操作失败。请检查设备状态和传输参数。<br> **起始版本：** 18 |
| HID_DDK_DEVICE_NOT_FOUND = 27300009 | 设备未找到。可能原因：设备未连接或设备ID错误。请检查设备是否连接、设备ID是否正确。<br> **起始版本：** 18 |

### Hid_ReportType

```c
enum Hid_ReportType
```

**描述**

报告（HID设备与主机之间交换的数据包）类型定义，用于标识HID设备与主机之间通信的数据包类型，在设备通信和数据交换场景中使用。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| HID_INPUT_REPORT = 0 | 输入报告，用于设备向主机上报数据。 |
| HID_OUTPUT_REPORT = 1 | 输出报告，用于主机向设备发送数据。 |
| HID_FEATURE_REPORT = 2 | 特性报告，用于设备配置和状态查询。 |


### HID_MAX_REPORT_BUFFER_SIZE

```c
HID_MAX_REPORT_BUFFER_SIZE (16 * 1024 - 1)
```

**描述**

最大报告缓冲区大小。

**起始版本：** 18
