# hid_ddk_types.h
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## Overview

Defines the enum variables and structs used in the HID DDK.

**File to include**: <hid/hid_ddk_types.h>

**Library**: libhid.z.so

**System capability**: SystemCapability.Driver.HID.Extension

**Since**: 11

**Related module**: [HidDdk](capi-hidddk.md)

## Summary

### Structs

| Name                                                       | typedef Keyword| Description|
|-----------------------------------------------------------| -- | -- |
| [Hid_EmitItem](capi-hidddk-hid-emititem.md)               | Hid_EmitItem | Defines event information.|
| [Hid_Device](capi-hidddk-hid-device.md)                   | Hid_Device | Defines basic device information.|
| [Hid_EventTypeArray](capi-hidddk-hid-eventtypearray.md)   | Hid_EventTypeArray | Defines an array of event types.|
| [Hid_KeyCodeArray](capi-hidddk-hid-keycodearray.md)       | Hid_KeyCodeArray | Defines an array of key codes.|
| [Hid_AbsAxesArray](capi-hidddk-hid-absaxesarray.md)       | Hid_AbsAxesArray | Defines an array of absolute coordinates.|
| [Hid_RelAxesArray](capi-hidddk-hid-relaxesarray.md)       | Hid_RelAxesArray | Defines an array of relative coordinates.|
| [Hid_MscEventArray](capi-hidddk-hid-msceventarray.md)     | Hid_MscEventArray | Defines an array of miscellaneous events.|
| [Hid_EventProperties](capi-hidddk-hid-eventproperties.md) | Hid_EventProperties | Defines the event properties of a device.|
| [Hid_RawDevInfo](capi-hidddk-hid-rawdevinfo.md)           | Hid_RawDevInfo | Defines the raw device information.|
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md)       | Hid_DeviceHandle | Defines the opaque USB HID device structure.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Hid_DeviceProp](#hid_deviceprop) | Hid_DeviceProp | Enumerates the properties of input devices.|
| [Hid_EventType](#hid_eventtype) | Hid_EventType | Enumerates the event types.|
| [Hid_SynEvent](#hid_synevent) | Hid_SynEvent | Enumerates sync events.|
| [Hid_KeyCode](#hid_keycode) | Hid_KeyCode | Enumerates the key codes.|
| [Hid_AbsAxes](#hid_absaxes) | Hid_AbsAxes | Enumerates the absolute coordinates.|
| [Hid_RelAxes](#hid_relaxes) | Hid_RelAxes | Enumerates the relative coordinates.|
| [Hid_MscEvent](#hid_mscevent) | Hid_MscEvent | Enumerates miscellaneous input events.|
| [Hid_DdkErrCode](#hid_ddkerrcode) | Hid_DdkErrCode | Enumerates the HID DDK error codes.|
| [Hid_ReportType](#hid_reporttype) | Hid_ReportType | Defines the report (data packets exchanged between the HID device and the host) type.|

### Macros

| Name| Description|
| -- | -- |
| HID_MAX_REPORT_BUFFER_SIZE (16 * 1024 - 1) | Defines the maximum size of the report buffer.|

## Enum Description

### Hid_DeviceProp

```
enum Hid_DeviceProp
```

**Description**

Enumerates the properties of input devices.

**Since**: 11

| Enum| Description|
| -- | -- |
| HID_PROP_POINTER = 0x00 | Pointer device.|
| HID_PROP_DIRECT = 0x01 | Direct input device.|
| HID_PROP_BUTTON_PAD = 0x02 | Touch device with bottom keys.|
| HID_PROP_SEMI_MT = 0x03 | Full multi-touch device.|
| HID_PROP_TOP_BUTTON_PAD = 0x04 | Touch device with top soft keys.|
| HID_PROP_POINTING_STICK = 0x05 | Pointing stick.|
| HID_PROP_ACCELEROMETER = 0x06 | Accelerometer.|

### Hid_EventType

```
enum Hid_EventType
```

**Description**

Enumerates the event types.

**Since**: 11

| Enum| Description|
| -- | -- |
| HID_EV_SYN = 0x00 | Sync event.|
| HID_EV_KEY = 0x01 | Key event.|
| HID_EV_REL = 0x02 | Relative coordinate event.|
| HID_EV_ABS = 0x03 | Absolute coordinate event.|
| HID_EV_MSC = 0x04 | Miscellaneous event.|

### Hid_SynEvent

```
enum Hid_SynEvent
```

**Description**

Enumerates sync events.

**Since**: 11

| Enum| Description|
| -- | -- |
| HID_SYN_REPORT = 0 | End of an event.|
| HID_SYN_CONFIG = 1 | Configuration synchronization.|
| HID_SYN_MT_REPORT = 2 | End of a multi-touch ABS data packet.|
| HID_SYN_DROPPED = 3 | Event discarded.|

### Hid_KeyCode

```
enum Hid_KeyCode
```

**Description**

Enumerates the key codes.

**Since**: 11

| Enum| Description|
| -- | -- |
| HID_KEY_A = 30 | Key A|
| HID_KEY_B = 48 | Key B|
| HID_KEY_C = 46 | Key C|
| HID_KEY_D = 32 | Key D|
| HID_KEY_E = 18 | Key E|
| HID_KEY_F = 33 | Key F|
| HID_KEY_G = 34 | Key G|
| HID_KEY_H = 35 | Key H|
| HID_KEY_I = 23 | Key I|
| HID_KEY_J = 36 | Key J|
| HID_KEY_K = 37 | Key K|
| HID_KEY_L = 38 | Key L|
| HID_KEY_M = 50 | Key M|
| HID_KEY_N = 49 | Key N|
| HID_KEY_O = 24 | Key O|
| HID_KEY_P = 25 | Key P|
| HID_KEY_Q = 16 | Key Q|
| HID_KEY_R = 19 | Key R|
| HID_KEY_S = 31 | Key S|
| HID_KEY_T = 20 | Key T|
| HID_KEY_U = 22 | Key U|
| HID_KEY_V = 47 | Key V|
| HID_KEY_W = 17 | Key W|
| HID_KEY_X = 45 | Key X|
| HID_KEY_Y = 21 | Key Y|
| HID_KEY_Z = 44 | Key Z|
| HID_KEY_ESC = 1 | Key Esc|
| HID_KEY_0 = 11 | Key 0|
| HID_KEY_1 = 2 | Key 1|
| HID_KEY_2 = 3 | Key 2|
| HID_KEY_3 = 4 | Key 3|
| HID_KEY_4 = 5 | Key 4|
| HID_KEY_5 = 6 | Key 5|
| HID_KEY_6 = 7 | Key 6|
| HID_KEY_7 = 8 | Key 7|
| HID_KEY_8 = 9 | Key 8|
| HID_KEY_9 = 10 | Key 9|
| HID_KEY_GRAVE = 41 | Key grave (`)|
| HID_KEY_MINUS = 12 | Key -|
| HID_KEY_EQUALS = 13 | Key =|
| HID_KEY_BACKSPACE = 14 | Key Backspace|
| HID_KEY_LEFT_BRACKET = 26 | Key [|
| HID_KEY_RIGHT_BRACKET = 27 | Key ]|
| HID_KEY_ENTER = 28 | Key Enter|
| HID_KEY_LEFT_SHIFT = 42 | Left Shift|
| HID_KEY_BACKSLASH = 43 | Key \|
| HID_KEY_SEMICOLON = 39 | Key ;|
| HID_KEY_APOSTROPHE = 40 | Key '|
| HID_KEY_SPACE = 57 | Key Space|
| HID_KEY_SLASH = 53 | Key /|
| HID_KEY_COMMA = 51 | Key comma (,)|
| HID_KEY_PERIOD = 52 | Key period (.)|
| HID_KEY_RIGHT_SHIFT = 54 | Right Shift|
| HID_KEY_NUMPAD_0 = 82 | Numeral 0 on the numeric keypad|
| HID_KEY_NUMPAD_1 = 79 | Numeral 1 on the numeric keypad|
| HID_KEY_NUMPAD_2 = 80 | Numeral 2 on the numeric keypad|
| HID_KEY_NUMPAD_3 = 81 | Numeral 3 on the numeric keypad|
| HID_KEY_NUMPAD_4 = 75 | Numeral 4 on the numeric keypad|
| HID_KEY_NUMPAD_5 = 76 | Numeral 5 on the numeric keypad|
| HID_KEY_NUMPAD_6 = 77 | Numeral 6 on the numeric keypad|
| HID_KEY_NUMPAD_7 = 71 | Numeral 7 on the numeric keypad|
| HID_KEY_NUMPAD_8 = 72 | Numeral 8 on the numeric keypad|
| HID_KEY_NUMPAD_9 = 73 | Numeral 9 on the numeric keypad|
| HID_KEY_NUMPAD_DIVIDE = 70 | Slash key (/) on the numeric keypad|
| HID_KEY_NUMPAD_MULTIPLY = 55 | Asterisk key (*) on the numeric keypad|
| HID_KEY_NUMPAD_SUBTRACT = 74 | Minus key (-) on the numeric keypad|
| HID_KEY_NUMPAD_ADD = 78 | Plus key (+) on the numeric keypad|
| HID_KEY_NUMPAD_DOT = 83 | Decimal point (.) on the numeric keypad|
| HID_KEY_SYSRQ = 99 | SYSRQ key|
| HID_KEY_DELETE = 111 | Delete key|
| HID_KEY_MUTE = 113 | Mute key|
| HID_KEY_VOLUME_DOWN = 114 | Volume Down key|
| HID_KEY_VOLUME_UP = 115 | Volume Up key|
| HID_KEY_BRIGHTNESS_DOWN = 224 | Brightness Down key|
| HID_KEY_BRIGHTNESS_UP = 225 | Brightness Up key|
| HID_BTN_0 = 0x100 | Button 0|
| HID_BTN_1 = 0x101 | Button 1|
| HID_BTN_2 = 0x102 | Button 2|
| HID_BTN_3 = 0x103 | Button 3|
| HID_BTN_4 = 0x104 | Button 4|
| HID_BTN_5 = 0x105 | Button 5|
| HID_BTN_6 = 0x106 | Button 6|
| HID_BTN_7 = 0x107 | Button 7|
| HID_BTN_8 = 0x108 | Button 8|
| HID_BTN_9 = 0x109 | Button 9|
| HID_BTN_LEFT = 0x110 | Left mouse button|
| HID_BTN_RIGHT = 0x111 | Right mouse button|
| HID_BTN_MIDDLE = 0x112 | Middle mouse button|
| HID_BTN_SIDE = 0x113 | Side mouse button|
| HID_BTN_EXTRA = 0x114 | Extra mouse button|
| HID_BTN_FORWARD = 0x115 | Mouse forward button|
| HID_BTN_BACKWARD = 0x116 | Mouse backward button|
| HID_BTN_TASK = 0x117 | Mouse task button|
| HID_BTN_TOOL_PEN = 0x140 | Pen|
| HID_BTN_TOOL_RUBBER = 0x141 | Eraser|
| HID_BTN_TOOL_BRUSH = 0x142 | Brush|
| HID_BTN_TOOL_PENCIL = 0x143 | Pencil|
| HID_BTN_TOOL_AIRBRUSH = 0x144 | Air brush|
| HID_BTN_TOOL_FINGER = 0x145 | Finger|
| HID_BTN_TOOL_MOUSE = 0x146 | Mouse|
| HID_BTN_TOOL_LENS = 0x147 | Lens|
| HID_BTN_TOOL_QUINT_TAP = 0x148 | Five-finger touch|
| HID_BTN_STYLUS3 = 0x149 | Stylus 3|
| HID_BTN_TOUCH = 0x14a | Touch|
| HID_BTN_STYLUS = 0x14b | Stylus|
| HID_BTN_STYLUS2 = 0x14c | Stylus 2|
| HID_BTN_TOOL_DOUBLE_TAP = 0x14d | Two-finger touch|
| HID_BTN_TOOL_TRIPLE_TAP = 0x14e | Three-finger touch|
| HID_BTN_TOOL_QUAD_TAP = 0x14f | Four-finger touch|
| HID_BTN_WHEEL = 0x150 | Scroll wheel|

### Hid_AbsAxes

```
enum Hid_AbsAxes
```

**Description**

Enumerates the absolute coordinates.

**Since**: 11

| Enum| Description|
| -- | -- |
| HID_ABS_X = 0x00 | X axis|
| HID_ABS_Y = 0x01 | Y axis|
| HID_ABS_Z = 0x02 | Z axis|
| HID_ABS_RX = 0x03 | X axis of the right analog stick|
| HID_ABS_RY = 0x04 | Y axis of the right analog stick|
| HID_ABS_RZ = 0x05 | Z axis of the right analog stick|
| HID_ABS_THROTTLE = 0x06 | Throttle|
| HID_ABS_RUDDER = 0x07 | Rudder|
| HID_ABS_WHEEL = 0x08 | Scroll wheel|
| HID_ABS_GAS = 0x09 | Gas|
| HID_ABS_BRAKE = 0x0a | Brake|
| HID_ABS_HAT0X = 0x10 | HAT0X |
| HID_ABS_HAT0Y = 0x11 | HAT0Y |
| HID_ABS_HAT1X = 0x12 | HAT1X |
| HID_ABS_HAT1Y = 0x13 | HAT1Y |
| HID_ABS_HAT2X = 0x14 | HAT2X |
| HID_ABS_HAT2Y = 0x15 | HAT2Y |
| HID_ABS_HAT3X = 0x16 | HAT3X |
| HID_ABS_HAT3Y = 0x17 | HAT3Y |
| HID_ABS_PRESSURE = 0x18 | Pressure|
| HID_ABS_DISTANCE = 0x19 | Distance|
| HID_ABS_TILT_X = 0x1a | Tilt of X axis|
| HID_ABS_TILT_Y = 0x1b | Tilt of Y axis|
| HID_ABS_TOOL_WIDTH = 0x1c | Width of the touch tool|
| HID_ABS_VOLUME = 0x20 | Volume|
| HID_ABS_MISC = 0x28 | Others|

### Hid_RelAxes

```
enum Hid_RelAxes
```

**Description**

Enumerates the relative coordinates.

**Since**: 11

| Enum| Description|
| -- | -- |
| HID_REL_X = 0x00 | X axis|
| HID_REL_Y = 0x01 | Y axis|
| HID_REL_Z = 0x02 | Z axis|
| HID_REL_RX = 0x03 | X axis of the right analog stick|
| HID_REL_RY = 0x04 | Y axis of the right analog stick|
| HID_REL_RZ = 0x05 | Z axis of the right analog stick|
| HID_REL_HWHEEL = 0x06 | Horizontal scroll wheel|
| HID_REL_DIAL = 0x07 | Scale|
| HID_REL_WHEEL = 0x08 | Scroll wheel|
| HID_REL_MISC = 0x09 | Others|
| HID_REL_RESERVED = 0x0a | Reserved|
| HID_REL_WHEEL_HI_RES = 0x0b | High-resolution scroll wheel|
| HID_REL_HWHEEL_HI_RES = 0x0c | High-resolution horizontal scroll wheel|

### Hid_MscEvent

```
enum Hid_MscEvent
```

**Description**

Enumerates miscellaneous input events.

**Since**: 11

| Enum| Description|
| -- | -- |
| HID_MSC_SERIAL = 0x00 | Serial number|
| HID_MSC_PULSE_LED = 0x01 | Pulse|
| HID_MSC_GESTURE = 0x02 | Gesture|
| HID_MSC_RAW = 0x03 | Start event|
| HID_MSC_SCAN = 0x04 | Scan|
| HID_MSC_TIMESTAMP = 0x05 | Timestamp|

### Hid_DdkErrCode

```
enum Hid_DdkErrCode
```

**Description**

Enumerates the HID DDK error codes.

**Since**: 11

| Enum| Description|
| -- | -- |
| HID_DDK_SUCCESS = 0 | Operation success.|
| HID_DDK_NO_PERM = 201 | No permission. The value is changed from **-6** to **201** since API version 16.|
| HID_DDK_INVALID_PARAMETER = 401 | Invalid parameter. The value is changed from **-2** to **401** since API version 16.|
| HID_DDK_FAILURE = 27300001 | Operation failed. The value is changed from **-1** to **27300001** since API version 16.|
| HID_DDK_NULL_PTR = 27300002 | Null pointer. The value is changed from **-4** to **27300002** since API version 16.|
| HID_DDK_INVALID_OPERATION = 27300003 | Invalid operation. The value is changed from **-3** to **27300003** since API version 16.|
| HID_DDK_TIMEOUT = 27300004 | Timeout. The value is changed from **-5** to **27300004** since API version 16.|
| HID_DDK_INIT_ERROR = 27300005 | DDK initialization error. This enum is supported since API version 16.|
| HID_DDK_SERVICE_ERROR = 27300006 | Service communication error. This enum is supported since API version 16.|
| HID_DDK_MEMORY_ERROR  = 27300007 | Memory-related errors, such as memory data copy failure and memory allocation failure. This enum is supported since API version 16.|
| HID_DDK_IO_ERROR = 27300008 | I/O operation failure. This enum is supported since API version 16.|
| HID_DDK_DEVICE_NOT_FOUND = 27300009 | Device not found. This enum is supported since API version 16.|

### Hid_ReportType

```
enum Hid_ReportType
```

**Description**

Defines the report (data packets exchanged between the HID device and the host) type.

**Since**: 18

| Enum| Description|
| -- | -- |
| HID_INPUT_REPORT = 0 | Input report.|
| HID_OUTPUT_REPORT = 1 | Output report.|
| HID_FEATURE_REPORT = 2 | Feature report.|


### HID_MAX_REPORT_BUFFER_SIZE

```
HID_MAX_REPORT_BUFFER_SIZE (16 * 1024 - 1)
```

**Description**

Defines the maximum size of the report buffer.

**Since**: 18
