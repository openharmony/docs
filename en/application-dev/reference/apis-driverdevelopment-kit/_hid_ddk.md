# HID DDK


## Overview

Provides HID driver development kit (DDK) functions, including those for creating a device, sending events to a device, and destroying a device.

**System capability**: SystemCapability.Driver.HID.Extension

**Since**: 11


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [hid_ddk_api.h](hid__ddk__api_8h.md) | Declares the HID DDK functions for accessing an input device from the host.<br>File to include: &lt;hid/hid_ddk_api.h&gt;<br>Library: libhid.z.so| 
| [hid_ddk_types.h](hid__ddk__types_8h.md) | Defines the enum variables and structs used in the HID DDK.<br>File to include: &lt;hid/hid_ddk_types.h&gt;<br>Library: libhid.z.so| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[Hid_EmitItem](_hid___emit_item.md) | Defines event information.| 
| struct&nbsp;&nbsp;[Hid_Device](_hid___device.md) | Defines basic device information.| 
| struct&nbsp;&nbsp;[Hid_EventTypeArray](_hid___event_type_array.md) | Defines an array of event types.| 
| struct&nbsp;&nbsp;[Hid_KeyCodeArray](_hid___key_code_array.md) | Defines an array of key codes.| 
| struct&nbsp;&nbsp;[Hid_AbsAxesArray](_hid___abs_axes_array.md) | Defines an array of absolute coordinates.| 
| struct&nbsp;&nbsp;[Hid_RelAxesArray](_hid___rel_axes_array.md) | Defines an array of relative coordinates.| 
| struct&nbsp;&nbsp;[Hid_MscEventArray](_hid___msc_event_array.md) | Defines an array of miscellaneous events.| 
| struct&nbsp;&nbsp;[Hid_EventProperties](_hid___event_properties.md) | Defines the event properties of a device.| 
| struct&nbsp;&nbsp;[Hid_RawDevInfo](_hid___raw_dev_info.md) | Defines the raw device information.| 


### Macros

| Name| Description| 
| -------- | -------- |
| [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size)&nbsp;&nbsp;&nbsp;(16 \* 1024 - 1) | Defines the maximum size of the report buffer.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [Hid_EmitItem](_hid___emit_item.md)[Hid_EmitItem](#hid_emititem) | Defines event information.| 
| typedef struct [Hid_Device](_hid___device.md)[Hid_Device](#hid_device) | Defines basic device information.| 
| typedef struct [Hid_EventTypeArray](_hid___event_type_array.md)[Hid_EventTypeArray](#hid_eventtypearray) | Defines an array of event types.| 
| typedef struct [Hid_KeyCodeArray](_hid___key_code_array.md)[Hid_KeyCodeArray](#hid_keycodearray) | Defines an array of key codes.| 
| typedef struct [Hid_AbsAxesArray](_hid___abs_axes_array.md)[Hid_AbsAxesArray](#hid_absaxesarray) | Defines an array of absolute coordinates.| 
| typedef struct [Hid_RelAxesArray](_hid___rel_axes_array.md)[Hid_RelAxesArray](#hid_relaxesarray) | Defines an array of relative coordinates.| 
| typedef struct [Hid_MscEventArray](_hid___msc_event_array.md)[Hid_MscEventArray](#hid_msceventarray) | Defines an array of miscellaneous events.| 
| typedef struct [Hid_EventProperties](_hid___event_properties.md)[Hid_EventProperties](#hid_eventproperties) | Defines the event properties of a device.| 
| typedef struct [Hid_DeviceHandle](#hid_devicehandle)[Hid_DeviceHandle](#hid_devicehandle) | Defines the opaque USB HID device structure.| 
| typedef struct [Hid_RawDevInfo](_hid___raw_dev_info.md)[Hid_RawDevInfo](#hid_rawdevinfo) | Defines the raw device information.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Hid_DeviceProp](#hid_deviceprop) {<br>HID_PROP_POINTER = 0x00, HID_PROP_DIRECT = 0x01, HID_PROP_BUTTON_PAD = 0x02, HID_PROP_SEMI_MT = 0x03,HID_PROP_TOP_BUTTON_PAD = 0x04, HID_PROP_POINTING_STICK = 0x05, HID_PROP_ACCELEROMETER = 0x06<br>} | Enumerates the properties of input devices.| 
| [Hid_EventType](#hid_eventtype) {<br>HID_EV_SYN = 0x00, HID_EV_KEY = 0x01, HID_EV_REL = 0x02, HID_EV_ABS = 0x03,HID_EV_MSC = 0x04<br>} | Enumerates the event types.| 
| [Hid_SynEvent](#hid_synevent) { HID_SYN_REPORT = 0, HID_SYN_CONFIG = 1, HID_SYN_MT_REPORT = 2, HID_SYN_DROPPED = 3 } | Enumerates sync events.| 
| [Hid_KeyCode](#hid_keycode) {<br>HID_KEY_A = 30, HID_KEY_B = 48, HID_KEY_C = 46, HID_KEY_D = 32,HID_KEY_E = 18, HID_KEY_F = 33, HID_KEY_G = 34, HID_KEY_H = 35,HID_KEY_I = 23, HID_KEY_J = 36, HID_KEY_K = 37, HID_KEY_L = 38,HID_KEY_M = 50, HID_KEY_N = 49, HID_KEY_O = 24, HID_KEY_P = 25,HID_KEY_Q = 16, HID_KEY_R = 19, HID_KEY_S = 31, HID_KEY_T = 20,HID_KEY_U = 22, HID_KEY_V = 47, HID_KEY_W = 17, HID_KEY_X = 45,HID_KEY_Y = 21, HID_KEY_Z = 44, HID_KEY_ESC = 1, HID_KEY_0 = 11,HID_KEY_1 = 2, HID_KEY_2 = 3, HID_KEY_3 = 4, HID_KEY_4 = 5,HID_KEY_5 = 6, HID_KEY_6 = 7, HID_KEY_7 = 8, HID_KEY_8 = 9,HID_KEY_9 = 10, HID_KEY_GRAVE = 41, HID_KEY_MINUS = 12, HID_KEY_EQUALS = 13,HID_KEY_BACKSPACE = 14, HID_KEY_LEFT_BRACKET = 26, HID_KEY_RIGHT_BRACKET = 27, HID_KEY_ENTER = 28,HID_KEY_LEFT_SHIFT = 42, HID_KEY_BACKSLASH = 43, HID_KEY_SEMICOLON = 39, HID_KEY_APOSTROPHE = 40,HID_KEY_SPACE = 57, HID_KEY_SLASH = 53, HID_KEY_COMMA = 51, HID_KEY_PERIOD = 52,HID_KEY_RIGHT_SHIFT = 54, HID_KEY_NUMPAD_0 = 82, HID_KEY_NUMPAD_1 = 79, HID_KEY_NUMPAD_2 = 80,HID_KEY_NUMPAD_3 = 81, HID_KEY_NUMPAD_4 = 75, HID_KEY_NUMPAD_5 = 76, HID_KEY_NUMPAD_6 = 77,HID_KEY_NUMPAD_7 = 71, HID_KEY_NUMPAD_8 = 72, HID_KEY_NUMPAD_9 = 73, HID_KEY_NUMPAD_DIVIDE = 70,HID_KEY_NUMPAD_MULTIPLY = 55, HID_KEY_NUMPAD_SUBTRACT = 74, HID_KEY_NUMPAD_ADD = 78, HID_KEY_NUMPAD_DOT = 83,HID_KEY_SYSRQ = 99, HID_KEY_MUTE = 113, HID_KEY_VOLUME_DOWN = 114, HID_KEY_VOLUME_UP = 115,HID_KEY_BRIGHTNESS_DOWN = 224, HID_KEY_BRIGHTNESS_UP = 225, HID_BTN_0 = 0x100, HID_BTN_1 = 0x101,HID_BTN_2 = 0x102, HID_BTN_3 = 0x103, HID_BTN_4 = 0x104, HID_BTN_5 = 0x105,HID_BTN_6 = 0x106, HID_BTN_7 = 0x107, HID_BTN_8 = 0x108, HID_BTN_9 = 0x109,HID_BTN_LEFT = 0x110, HID_BTN_RIGHT = 0x111, HID_BTN_MIDDLE = 0x112, HID_BTN_SIDE = 0x113,HID_BTN_EXTRA = 0x114, HID_BTN_FORWARD = 0x115, HID_BTN_BACKWARD = 0x116, HID_BTN_TASK = 0x117,HID_BTN_TOOL_PEN = 0x140, HID_BTN_TOOL_RUBBER = 0x141, HID_BTN_TOOL_BRUSH = 0x142, HID_BTN_TOOL_PENCIL = 0x143,HID_BTN_TOOL_AIRBRUSH = 0x144, HID_BTN_TOOL_FINGER = 0x145, HID_BTN_TOOL_MOUSE = 0x146, HID_BTN_TOOL_LENS = 0x147,HID_BTN_TOOL_QUINT_TAP = 0x148, HID_BTN_STYLUS3 = 0x149, HID_BTN_TOUCH = 0x14a, HID_BTN_STYLUS = 0x14b,HID_BTN_STYLUS2 = 0x14c, HID_BTN_TOOL_DOUBLE_TAP = 0x14d, HID_BTN_TOOL_TRIPLE_TAP = 0x14e, HID_BTN_TOOL_QUAD_TAP = 0x14f,HID_BTN_WHEEL = 0x150<br>} | Enumerates the key codes.| 
| [Hid_AbsAxes](#hid_absaxes) {<br>HID_ABS_X = 0x00, HID_ABS_Y = 0x01, HID_ABS_Z = 0x02, HID_ABS_RX = 0x03,HID_ABS_RY = 0x04, HID_ABS_RZ = 0x05, HID_ABS_THROTTLE = 0x06, HID_ABS_RUDDER = 0x07,HID_ABS_WHEEL = 0x08, HID_ABS_GAS = 0x09, HID_ABS_BRAKE = 0x0a, HID_ABS_HAT0X = 0x10,HID_ABS_HAT0Y = 0x11, HID_ABS_HAT1X = 0x12, HID_ABS_HAT1Y = 0x13, HID_ABS_HAT2X = 0x14,HID_ABS_HAT2Y = 0x15, HID_ABS_HAT3X = 0x16, HID_ABS_HAT3Y = 0x17, HID_ABS_PRESSURE = 0x18,HID_ABS_DISTANCE = 0x19, HID_ABS_TILT_X = 0x1a, HID_ABS_TILT_Y = 0x1b, HID_ABS_TOOL_WIDTH = 0x1c,HID_ABS_VOLUME = 0x20, HID_ABS_MISC = 0x28<br>} | Enumerates the absolute coordinates.| 
| [Hid_RelAxes](#hid_relaxes) {<br>HID_REL_X = 0x00, HID_REL_Y = 0x01, HID_REL_Z = 0x02, HID_REL_RX = 0x03,HID_REL_RY = 0x04, HID_REL_RZ = 0x05, HID_REL_HWHEEL = 0x06, HID_REL_DIAL = 0x07,HID_REL_WHEEL = 0x08, HID_REL_MISC = 0x09, HID_REL_RESERVED = 0x0a, HID_REL_WHEEL_HI_RES = 0x0b,HID_REL_HWHEEL_HI_RES = 0x0c<br>} | Enumerates the relative coordinates.| 
| [Hid_MscEvent](#hid_mscevent) {<br>HID_MSC_SERIAL = 0x00, HID_MSC_PULSE_LED = 0x01, HID_MSC_GESTURE = 0x02, HID_MSC_RAW = 0x03,HID_MSC_SCAN = 0x04, HID_MSC_TIMESTAMP = 0x05<br>} | Enumerates miscellaneous input events.| 
| [Hid_DdkErrCode](#hid_ddkerrcode) {<br>HID_DDK_SUCCESS = 0, HID_DDK_NO_PERM = 201, HID_DDK_INVALID_PARAMETER = 401,HID_DDK_FAILURE = 27300001,HID_DDK_NULL_PTR = 27300002, HID_DDK_INVALID_OPERATION = 27300003, HID_DDK_TIMEOUT = 27300004, HID_DDK_INIT_ERROR = 27300005, HID_DDK_SERVICE_ERROR = 27300006, HID_DDK_MEMORY_ERROR = 27300007, HID_DDK_IO_ERROR = 27300008, HID_DDK_DEVICE_NOT_FOUND = 27300009<br>} | Enumerates the HID DDK error codes.| 
| [Hid_ReportType](#hid_reporttype) { HID_INPUT_REPORT = 0, HID_OUTPUT_REPORT = 1, HID_FEATURE_REPORT = 2 } | Defines the report (data packets exchanged between the HID device and the host) type.| 


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_Hid_CreateDevice](#oh_hid_createdevice) ([Hid_Device](_hid___device.md) \*hidDevice, [Hid_EventProperties](_hid___event_properties.md) \*hidEventProperties) | Creates a device.| 
| int32_t [OH_Hid_EmitEvent](#oh_hid_emitevent) (int32_t deviceId, const [Hid_EmitItem](_hid___emit_item.md) items[], uint16_t length) | Sends an event list to a device.| 
| int32_t [OH_Hid_DestroyDevice](#oh_hid_destroydevice) (int32_t deviceId) | Destroys a device.| 
| int32_t [OH_Hid_Init](#oh_hid_init) (void) | Initializes an HID DDK.| 
| int32_t [OH_Hid_Release](#oh_hid_release) (void) | Releases an HID DDK.| 
| int32_t [OH_Hid_Open](#oh_hid_open) (uint64_t deviceId, uint8_t interfaceIndex, [Hid_DeviceHandle](#hid_devicehandle) \*\*dev) | Opens the device specified by **deviceId** and **interfaceIndex**.| 
| int32_t [OH_Hid_Close](#oh_hid_close) ([Hid_DeviceHandle](#hid_devicehandle) \*\*dev) | Closes an HID device.| 
| int32_t [OH_Hid_Write](#oh_hid_write) ([Hid_DeviceHandle](#hid_devicehandle) \*dev, uint8_t \*data, uint32_t length, uint32_t \*bytesWritten) | Writes reports to an HID device.| 
| int32_t [OH_Hid_ReadTimeout](#oh_hid_readtimeout) ([Hid_DeviceHandle](#hid_devicehandle) \*dev, uint8_t \*data, uint32_t bufSize, int timeout, uint32_t \*bytesRead) | Reads reports from the HID device within the specified timeout interval.| 
| int32_t [OH_Hid_Read](#oh_hid_read) ([Hid_DeviceHandle](#hid_devicehandle) \*dev, uint8_t \*data, uint32_t bufSize, uint32_t \*bytesRead) | Reads reports from the HID device. The blocking mode (that is, blocking remains active until data can be read) is used by default. You can call [OH_Hid_SetNonBlocking](#oh_hid_setnonblocking) to change the mode.| 
| int32_t [OH_Hid_SetNonBlocking](#oh_hid_setnonblocking) ([Hid_DeviceHandle](#hid_devicehandle) \*dev, int nonBlock) | Sets the device read mode to non-blocking mode.| 
| int32_t [OH_Hid_GetRawInfo](#oh_hid_getrawinfo) ([Hid_DeviceHandle](#hid_devicehandle) \*dev, [Hid_RawDevInfo](_hid___raw_dev_info.md) \*rawDevInfo) | Obtains the original device information.| 
| int32_t [OH_Hid_GetRawName](#oh_hid_getrawname) ([Hid_DeviceHandle](#hid_devicehandle) \*dev, char \*data, uint32_t bufSize) | Obtains the original device name.| 
| int32_t [OH_Hid_GetPhysicalAddress](#oh_hid_getphysicaladdress) ([Hid_DeviceHandle](#hid_devicehandle) \*dev, char \*data, uint32_t bufSize) | Obtains the physical address of the HID device.| 
| int32_t [OH_Hid_GetRawUniqueId](#oh_hid_getrawuniqueid) ([Hid_DeviceHandle](#hid_devicehandle) \*dev, uint8_t \*data, uint32_t bufSize) | Obtains the original unique identifier of a device.| 
| <!--DelRow-->int32_t [OH_Hid_SendReport](#oh_hid_sendreport) ([Hid_DeviceHandle](#hid_devicehandle) \*dev, [Hid_ReportType](#hid_reporttype) reportType, const uint8_t \*data, uint32_t length) | Sends reports to the HID device.| 
| <!--DelRow-->int32_t [OH_Hid_GetReport](#oh_hid_getreport) ([Hid_DeviceHandle](#hid_devicehandle) \*dev, [Hid_ReportType](#hid_reporttype) reportType, uint8_t \*data, uint32_t bufSize) | Obtains reports from the HID device.| 
| int32_t [OH_Hid_GetReportDescriptor](#oh_hid_getreportdescriptor) ([Hid_DeviceHandle](#hid_devicehandle) \*dev, uint8_t \*buf, uint32_t bufSize, uint32_t \*bytesRead) | Obtains the report descriptor of the HID device.| 


### Variables

| Name| Description| 
| -------- | -------- |
| uint16_t [Hid_EmitItem::type](#type) | Event type.| 
| uint16_t [Hid_EmitItem::code](#code) | Event code.| 
| uint32_t [Hid_EmitItem::value](#value) | Event value.| 
| const char \* [Hid_Device::deviceName](#devicename) | Device name.| 
| uint16_t [Hid_Device::vendorId](#vendorid) | Vendor ID.| 
| uint16_t [Hid_Device::productId](#productid) | Product ID.| 
| uint16_t [Hid_Device::version](#version) | Version number.| 
| uint16_t [Hid_Device::bustype](#bustype) | Bus type.| 
| [Hid_DeviceProp](#hid_deviceprop) \* [Hid_Device::properties](#properties) | Device properties.| 
| uint16_t [Hid_Device::propLength](#proplength) | Number of device properties.| 
| [Hid_EventType](#hid_eventtype) \* [Hid_EventTypeArray::hidEventType](#hideventtype) | Event type.| 
| uint16_t [Hid_EventTypeArray::length](#length-15) | Array length.| 
| [Hid_KeyCode](#hid_keycode) \* [Hid_KeyCodeArray::hidKeyCode](#hidkeycode) | key code.| 
| uint16_t [Hid_KeyCodeArray::length](#length-25) | Array length.| 
| [Hid_AbsAxes](#hid_absaxes) \* [Hid_AbsAxesArray::hidAbsAxes](#hidabsaxes) | Array of absolute coordinates.| 
| uint16_t [Hid_AbsAxesArray::length](#length-35) | Array length.| 
| [Hid_RelAxes](#hid_relaxes) \* [Hid_RelAxesArray::hidRelAxes](#hidrelaxes) | Array of relative coordinates.| 
| uint16_t [Hid_RelAxesArray::length](#length-45) | Array length.| 
| [Hid_MscEvent](#hid_mscevent) \* [Hid_MscEventArray::hidMscEvent](#hidmscevent) | Miscellaneous event.| 
| uint16_t [Hid_MscEventArray::length](#length-55) | Array length.| 
| struct [Hid_EventTypeArray](_hid___event_type_array.md)[Hid_EventProperties::hidEventTypes](#hideventtypes) | Array of event types.| 
| struct [Hid_KeyCodeArray](_hid___key_code_array.md)[Hid_EventProperties::hidKeys](#hidkeys) | Array of key codes.| 
| struct [Hid_AbsAxesArray](_hid___abs_axes_array.md)[Hid_EventProperties::hidAbs](#hidabs) | Array of absolute coordinate properties.| 
| struct [Hid_RelAxesArray](_hid___rel_axes_array.md)[Hid_EventProperties::hidRelBits](#hidrelbits) | Array of relative coordinate properties.| 
| struct [Hid_MscEventArray](_hid___msc_event_array.md)[Hid_EventProperties::hidMiscellaneous](#hidmiscellaneous) | Array of miscellaneous events.| 
| int32_t [Hid_EventProperties::hidAbsMax](#hidabsmax) [64] | Maximum values of the absolute coordinates.| 
| int32_t [Hid_EventProperties::hidAbsMin](#hidabsmin) [64] | Minimum values of the absolute coordinates.| 
| int32_t [Hid_EventProperties::hidAbsFuzz](#hidabsfuzz) [64] | Fuzzy values of the absolute coordinates.| 
| int32_t [Hid_EventProperties::hidAbsFlat](#hidabsflat) [64] | Fixed values of the absolute coordinates.| 
| uint32_t [Hid_RawDevInfo::busType](#bustype) | Bus type.| 
| uint16_t [Hid_RawDevInfo::vendor](#vendor) | Provider ID.| 
| uint16_t [Hid_RawDevInfo::product](#product) | Product ID.| 


## Macro Description


### HID_MAX_REPORT_BUFFER_SIZE

```
#define HID_MAX_REPORT_BUFFER_SIZE   (16 * 1024 - 1)
```

**Description**

Defines the maximum size of the report buffer.

**Since**: 16


## Type Description


### Hid_AbsAxesArray

```
typedef struct Hid_AbsAxesArrayHid_AbsAxesArray
```

**Description**

Defines a struct for an array of absolute coordinates.

**Since**: 11


### Hid_Device

```
typedef struct Hid_DeviceHid_Device
```

**Description**

Defines a struct for basic device information.

**Since**: 11


### Hid_DeviceHandle

```
typedef struct Hid_DeviceHandleHid_DeviceHandle
```

**Description**

Defines the opaque USB HID device structure.

**Since**: 16


### Hid_EmitItem

```
typedef struct Hid_EmitItemHid_EmitItem
```

**Description**

Defines a struct for event information.

**Since**: 11


### Hid_EventProperties

```
typedef struct Hid_EventPropertiesHid_EventProperties
```

**Description**

Defines a struct for the event properties of a device.

**Since**: 11


### Hid_EventTypeArray

```
typedef struct Hid_EventTypeArrayHid_EventTypeArray
```

**Description**

Defines a struct for an array of event types.

**Since**: 11


### Hid_KeyCodeArray

```
typedef struct Hid_KeyCodeArrayHid_KeyCodeArray
```

**Description**

Defines a struct for an array of key codes.

**Since**: 11


### Hid_MscEventArray

```
typedef struct Hid_MscEventArrayHid_MscEventArray
```

**Description**

Defines a struct for an array of miscellaneous events.

**Since**: 11


### Hid_RawDevInfo

```
typedef struct Hid_RawDevInfoHid_RawDevInfo
```

**Description**

Defines the raw device information.

**Since**: 16


### Hid_RelAxesArray

```
typedef struct Hid_RelAxesArrayHid_RelAxesArray
```

**Description**

Defines a struct for an array of relative coordinates.

**Since**: 11


## Enum Description


### Hid_AbsAxes

```
enum Hid_AbsAxes
```

**Description**

Enumerates the absolute coordinates.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| HID_ABS_X | X axis.| 
| HID_ABS_Y | Y axis.| 
| HID_ABS_Z | Z axis.| 
| HID_ABS_RX | X axis of the right analog stick.| 
| HID_ABS_RY | Y axis of the right analog stick.| 
| HID_ABS_RZ | Z axis of the right analog stick.| 
| HID_ABS_THROTTLE | Throttle.| 
| HID_ABS_RUDDER | Rudder.| 
| HID_ABS_WHEEL | Scroll wheel.| 
| HID_ABS_GAS | Gas.| 
| HID_ABS_BRAKE | Brake.| 
| HID_ABS_HAT0X | HAT0X | 
| HID_ABS_HAT0Y | HAT0Y | 
| HID_ABS_HAT1X | HAT1X | 
| HID_ABS_HAT1Y | HAT1Y | 
| HID_ABS_HAT2X | HAT2X | 
| HID_ABS_HAT2Y | HAT2Y | 
| HID_ABS_HAT3X | HAT3X | 
| HID_ABS_HAT3Y | HAT3Y | 
| HID_ABS_PRESSURE | Pressure.| 
| HID_ABS_DISTANCE | Distance.| 
| HID_ABS_TILT_X | Tilt of X axis.| 
| HID_ABS_TILT_Y | Tilt of Y axis.| 
| HID_ABS_TOOL_WIDTH | Width of the touch tool.| 
| HID_ABS_VOLUME | Volume.| 
| HID_ABS_MISC | Others.| 


### Hid_DdkErrCode

```
enum Hid_DdkErrCode
```

**Description**

Enumerates the HID DDK error codes.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| HID_DDK_SUCCESS | Operation succeeded.| 
| HID_DDK_NO_PERM | No permission. The value is changed from **-6** to **201** since API version 16.| 
| HID_DDK_INVALID_PARAMETER | Invalid parameter. The value is changed from **-2** to **401** since API version 16.| 
| HID_DDK_FAILURE | Operation failed. The value is changed from **-1** to **27300001** since API version 16.| 
| HID_DDK_NULL_PTR | Null pointer. The value is changed from **-4** to **27300002** since API version 16.| 
| HID_DDK_INVALID_OPERATION | Invalid operation. The value is changed from **-3** to **27300003** since API version 16.| 
| HID_DDK_TIMEOUT | Timeout. The value is changed from **-5** to **27300004** since API version 16.| 
| HID_DDK_INIT_ERROR | DDK initialization error. This enum is supported since API version 16.| 
| HID_DDK_SERVICE_ERROR | Service communication error. This enum is supported since API version 16.| 
| HID_DDK_MEMORY_ERROR | Memory-related errors, such as memory data copy failure and memory allocation failure. This enum is supported since API version 16.| 
| HID_DDK_IO_ERROR | I/O operation failure. This enum is supported since API version 16.| 
| HID_DDK_DEVICE_NOT_FOUND | Device not found. This enum is supported since API version 16.| 


### Hid_DeviceProp

```
enum Hid_DeviceProp
```

**Description**

Enumerates the properties of input devices.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| HID_PROP_POINTER | Pointer device.| 
| HID_PROP_DIRECT | Direct input device.| 
| HID_PROP_BUTTON_PAD | Touch device with bottom keys.| 
| HID_PROP_SEMI_MT | Full multi-touch device.| 
| HID_PROP_TOP_BUTTON_PAD | Touch device with top soft keys.| 
| HID_PROP_POINTING_STICK | Pointing stick.| 
| HID_PROP_ACCELEROMETER | Accelerometer.| 


### Hid_EventType

```
enum Hid_EventType
```

**Description**

Enumerates the event types.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| HID_EV_SYN | Sync event.| 
| HID_EV_KEY | Key event.| 
| HID_EV_REL | Relative coordinate event.| 
| HID_EV_ABS | Absolute coordinate event.| 
| HID_EV_MSC |  Miscellaneous event.| 


### Hid_KeyCode

```
enum Hid_KeyCode
```

**Description**

Enumerates the key codes.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| HID_KEY_A | Key A.| 
| HID_KEY_B | Key B.| 
| HID_KEY_C | Key C.| 
| HID_KEY_D | Key D.| 
| HID_KEY_E | Key E.| 
| HID_KEY_F | Key F.| 
| HID_KEY_G | Key G.| 
| HID_KEY_H | Key H.| 
| HID_KEY_I | Key I.| 
| HID_KEY_J | Key J.| 
| HID_KEY_K | Key K.| 
| HID_KEY_L | Key L.| 
| HID_KEY_M | Key M.| 
| HID_KEY_N | Key N.| 
| HID_KEY_O | Key O.| 
| HID_KEY_P | Key P.| 
| HID_KEY_Q | Key Q.| 
| HID_KEY_R | Key R.| 
| HID_KEY_S | Key S.| 
| HID_KEY_T | Key T.| 
| HID_KEY_U | Key U.| 
| HID_KEY_V | Key V.| 
| HID_KEY_W | Key W.| 
| HID_KEY_X | Key X.| 
| HID_KEY_Y | Key Y.| 
| HID_KEY_Z | Key Z.| 
| HID_KEY_ESC | Key Esc.| 
| HID_KEY_0 | Key 0.| 
| HID_KEY_1 | Key 1.| 
| HID_KEY_2 | Key 2.| 
| HID_KEY_3 | Key 3.| 
| HID_KEY_4 | Key 4.| 
| HID_KEY_5 | Key 5.| 
| HID_KEY_6 | Key 6.| 
| HID_KEY_7 | Key 7.| 
| HID_KEY_8 | Key 8.| 
| HID_KEY_9 | Key 9.| 
| HID_KEY_GRAVE | Key grave (`).| 
| HID_KEY_MINUS | Key minus (-).| 
| HID_KEY_EQUALS | Key equals (=).| 
| HID_KEY_BACKSPACE | key Backspace.| 
| HID_KEY_LEFT_BRACKET | Key left bracket ([).| 
| HID_KEY_RIGHT_BRACKET | Key right bracket (]).| 
| HID_KEY_ENTER | Key Enter.| 
| HID_KEY_LEFT_SHIFT | Left Shift.| 
| HID_KEY_BACKSLASH | Key backslash (\).| 
| HID_KEY_SEMICOLON | Key semicolon (;).| 
| HID_KEY_APOSTROPHE | Key apostrophe (').| 
| HID_KEY_SPACE | Key Space.| 
| HID_KEY_SLASH | Key slash (/).| 
| HID_KEY_COMMA | Key comma (,).| 
| HID_KEY_PERIOD | Key period (.).| 
| HID_KEY_RIGHT_SHIFT | Right Shift.| 
| HID_KEY_NUMPAD_0 | Numeral 0 on the numeric keypad.| 
| HID_KEY_NUMPAD_1 | Numeral 1 on the numeric keypad.| 
| HID_KEY_NUMPAD_2 | Numeral 2 on the numeric keypad.| 
| HID_KEY_NUMPAD_3 | Numeral 3 on the numeric keypad.| 
| HID_KEY_NUMPAD_4 | Numeral 4 on the numeric keypad.| 
| HID_KEY_NUMPAD_5 | Numeral 5 on the numeric keypad.| 
| HID_KEY_NUMPAD_6 | Numeral 6 on the numeric keypad.| 
| HID_KEY_NUMPAD_7 | Numeral 7 on the numeric keypad.| 
| HID_KEY_NUMPAD_8 | Numeral 8 on the numeric keypad.| 
| HID_KEY_NUMPAD_9 | Numeral 9 on the numeric keypad.| 
| HID_KEY_NUMPAD_DIVIDE | Arithmetic operator / (division) on the numeric keypad.| 
| HID_KEY_NUMPAD_MULTIPLY | Arithmetic operator * (multiplication) on the numeric keypad.| 
| HID_KEY_NUMPAD_SUBTRACT | Arithmetic operator - (subtraction) on the numeric keypad.| 
| HID_KEY_NUMPAD_ADD | Arithmetic operator + (addition) on the numeric keypad.| 
| HID_KEY_NUMPAD_DOT | Decimal point (.) on the numeric keypad. | 
| HID_KEY_SYSRQ | Key Esc.| 
| HID_KEY_MUTE | Mute key.| 
| HID_KEY_VOLUME_DOWN | Volume Down key.| 
| HID_KEY_VOLUME_UP | Volume Up key.| 
| HID_KEY_BRIGHTNESS_DOWN | Brightness Down key.| 
| HID_KEY_BRIGHTNESS_UP | Brightness Up key.| 
| HID_BTN_0 | Button 0.| 
| HID_BTN_1 | Button 1| 
| HID_BTN_2 | Button 2.| 
| HID_BTN_3 | Button 3.| 
| HID_BTN_4 | Button 4.| 
| HID_BTN_5 | Button 5.| 
| HID_BTN_6 | Button 6.| 
| HID_BTN_7 | Button 7.| 
| HID_BTN_8 | Button 8.| 
| HID_BTN_9 | Button 9.| 
| HID_BTN_LEFT | Left mouse button.| 
| HID_BTN_RIGHT | Right mouse button.| 
| HID_BTN_MIDDLE | Middle mouse button.| 
| HID_BTN_SIDE | Side mouse button.| 
| HID_BTN_EXTRA | Extra mouse button.| 
| HID_BTN_FORWARD | Mouse forward button.| 
| HID_BTN_BACKWARD | Mouse backward button.| 
| HID_BTN_TASK | Mouse task button.| 
| HID_BTN_TOOL_PEN | Pen.| 
| HID_BTN_TOOL_RUBBER | Eraser.| 
| HID_BTN_TOOL_BRUSH | Brush.| 
| HID_BTN_TOOL_PENCIL | Pencil.| 
| HID_BTN_TOOL_AIRBRUSH | Air brush.| 
| HID_BTN_TOOL_FINGER | Finger.| 
| HID_BTN_TOOL_MOUSE | Mouse.| 
| HID_BTN_TOOL_LENS | Lens.| 
| HID_BTN_TOOL_QUINT_TAP | Five-finger touch.| 
| HID_BTN_STYLUS3 | Stylus 3.| 
| HID_BTN_TOUCH | Touch.| 
| HID_BTN_STYLUS | Stylus.| 
| HID_BTN_STYLUS2 | Stylus 2.| 
| HID_BTN_TOOL_DOUBLE_TAP | Two-finger touch.| 
| HID_BTN_TOOL_TRIPLE_TAP | Three-finger touch.| 
| HID_BTN_TOOL_QUAD_TAP | Four-finger touch.| 
| HID_BTN_WHEEL | Scroll wheel.| 


### Hid_MscEvent

```
enum Hid_MscEvent
```

**Description**

Enumerates miscellaneous input events.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| HID_MSC_SERIAL | Serial number.| 
| HID_MSC_PULSE_LED | Pulse.| 
| HID_MSC_GESTURE | Gesture.| 
| HID_MSC_RAW | Start event.| 
| HID_MSC_SCAN | Scan.| 
| HID_MSC_TIMESTAMP | Timestamp.| 


### Hid_RelAxes

```
enum Hid_RelAxes
```

**Description**

Enumerates the relative coordinates.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| HID_REL_X | X axis.| 
| HID_REL_Y | Y axis.| 
| HID_REL_Z | Z axis.| 
| HID_REL_RX | X axis of the right analog stick.| 
| HID_REL_RY | Y axis of the right analog stick.| 
| HID_REL_RZ | Z axis of the right analog stick.| 
| HID_REL_HWHEEL | Horizontal scroll wheel.| 
| HID_REL_DIAL | Scale.| 
| HID_REL_WHEEL | Scroll wheel.| 
| HID_REL_MISC | Others.| 
| HID_REL_RESERVED | Reserved.| 
| HID_REL_WHEEL_HI_RES | High-resolution scroll wheel.| 
| HID_REL_HWHEEL_HI_RES | High-resolution horizontal scroll wheel.| 


### Hid_ReportType

```
enum Hid_ReportType
```

**Description**

Defines the report (data packets exchanged between the HID device and the host) type.

**Since**: 16

| Value| Description| 
| -------- | -------- |
| HID_INPUT_REPORT | Input report.| 
| HID_OUTPUT_REPORT | Output report.| 
| HID_FEATURE_REPORT | Feature report.| 


### Hid_SynEvent

```
enum Hid_SynEvent
```

**Description**

Enumerates sync events.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| HID_SYN_REPORT | Indicates the end of an event.| 
| HID_SYN_CONFIG | Indicates configuration synchronization.| 
| HID_SYN_MT_REPORT | Indicates the end of a multi-touch ABS data packet.| 
| HID_SYN_DROPPED | Indicates that the event is discarded.| 


## Function Description


### OH_Hid_Close()

```
int32_t OH_Hid_Close (Hid_DeviceHandle ** dev)
```

**Description**

Closes an HID device.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device operation handle.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INIT_ERROR DDK: DDK initialization error.

- HID_DDK_SERVICE_ERROR: DDK service communication error.

- HID_DDK_IO_ERROR: I/O operation error.

- HID_DDK_INVALID_PARAMETER: Empty **dev**.


### OH_Hid_CreateDevice()

```
int32_t OH_Hid_CreateDevice (Hid_Device * hidDevice, Hid_EventProperties * hidEventProperties )
```

**Description**

Creates a device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| hidDevice | Pointer to the basic information about the device to create, including the device name, vendor ID, and product ID.| 
| hidEventProperties | Pointer to the event properties related to the device to create, including the event type, key event properties, absolute coordinate event properties, and relative coordinate event properties.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- deviceID (a non-negative number) if the API call is successful.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INVALID_OPERATION: hid_ddk service connection failed.

- HID_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. The input **hidDevice** is a null pointer. 2. The input **hidEventProperties** is a null pointer. 3. The length of **properties** exceeds 7 characters. 4. The length of **hidEventTypes** exceeds 5 characters. 5. The length of **hidKeys** exceeds 100 characters. 6. The length of **hidAbs** exceeds 26 characters. 7. The length of **hidRelBits** exceeds 13 characters. 8. The length of **hidMiscellaneous** exceeds 6 characters.

- HID_DDK_FAILURE: Number of devices exceeding the maximum value (200).


### OH_Hid_DestroyDevice()

```
int32_t OH_Hid_DestroyDevice (int32_t deviceId)
```

**Description**

Destroys a device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceId | ID of the device to destroy.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INVALID_OPERATION: Invalid operation. The hid_ddk service connection fails or the caller is not the device creator.

- HID_DDK_FAILURE: Device not exist.


### OH_Hid_EmitEvent()

```
int32_t OH_Hid_EmitEvent (int32_t deviceId, const Hid_EmitItem items[], uint16_t length )
```

**Description**

Sends an event list to a device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceId | ID of the target device.| 
| items | List of the events to send. The event information includes the event type (**Hid_EventType**), code (**Hid_SynEvent**, **Hid_KeyCode**, **HidBtnCode**, **Hid_AbsAxes**, **Hid_RelAxes**, or **Hid_MscEvent**), and value (depending on the actual device input).| 
| length | Length of the event list (number of events to be sent at a time).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INVALID_OPERATION: Invalid operation. The hid_ddk service connection fails or the caller is not the device creator.

- HID_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. The device ID is smaller than 0. 2. The length of the input parameter exceeds 7 characters. 3. The input **items** is a null pointer.

- HID_DDK_NULL_PTR: Null pointer. The input device is empty.

- HID_DDK_FAILURE: Device not exist.


### OH_Hid_GetPhysicalAddress()

```
int32_t OH_Hid_GetPhysicalAddress (Hid_DeviceHandle * dev, char * data, uint32_t bufSize )
```

**Description**

Obtains the physical address of the HID device.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device operation handle.| 
| data | Buffer for storing the read data.| 
| bufSize | Size of the buffer for storing read data. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is empty. 2. **data** is empty. 3. The value of **bufSize** is **0**. 4. The value of **bufSize** exceeds [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size). HID_DDK_INIT_ERROR DDK: DDK initialization error.

- HID_DDK_SERVICE_ERROR: DDK service communication error.

- HID_DDK_MEMORY_ERROR: Memory data copy error.

- HID_DDK_IO_ERROR: I/O operation error.

- HID_DDK_INVALID_OPERATION: Invalid operation.


### OH_Hid_GetRawInfo()

```
int32_t OH_Hid_GetRawInfo (Hid_DeviceHandle * dev, Hid_RawDevInfo * rawDevInfo )
```

**Description**

Obtains the original device information.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device operation handle.| 
| rawDevInfo | Original device information, including the vendor ID, product ID, and bus type.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is empty. 2. **rawDevInfo** is empty.

- HID_DDK_INIT_ERROR DDK: DDK initialization error.

- HID_DDK_SERVICE_ERROR: DDK service communication error.

- HID_DDK_IO_ERROR: I/O operation error.

- HID_DDK_INVALID_OPERATION: Invalid operation.


### OH_Hid_GetRawName()

```
int32_t OH_Hid_GetRawName (Hid_DeviceHandle * dev, char * data, uint32_t bufSize )
```

**Description**

Obtains the original device name.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device operation handle.| 
| data | Buffer for storing the read data.| 
| bufSize | Size of the buffer for storing read data. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is empty. 2. **data** is empty. 3. The value of **bufSize** is **0**. 4. The value of **bufSize** exceeds [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size). HID_DDK_INIT_ERROR DDK: DDK initialization error.

- HID_DDK_SERVICE_ERROR: DDK service communication error.

- HID_DDK_MEMORY_ERROR: Memory data copy error.

- HID_DDK_IO_ERROR: I/O operation error.

- HID_DDK_INVALID_OPERATION: Invalid operation.


### OH_Hid_GetRawUniqueId()

```
int32_t OH_Hid_GetRawUniqueId (Hid_DeviceHandle * dev, uint8_t * data, uint32_t bufSize )
```

**Description**

Obtains the original unique identifier of a device.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device operation handle.| 
| data | Buffer for storing the read data.| 
| bufSize | Size of the buffer for storing read data. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is empty. 2. **data** is empty. 3. The value of **bufSize** is **0**. 4. The value of **bufSize** exceeds [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size). HID_DDK_INIT_ERROR DDK: DDK initialization error.

- HID_DDK_SERVICE_ERROR: DDK service communication error.

- HID_DDK_MEMORY_ERROR: Memory data copy error.

- HID_DDK_IO_ERROR: I/O operation error.

- HID_DDK_INVALID_OPERATION: Invalid operation.

<!--Del-->
### OH_Hid_GetReport()

```
int32_t OH_Hid_GetReport (Hid_DeviceHandle * dev, Hid_ReportType reportType, uint8_t * data, uint32_t bufSize )
```

**Description**

Obtains reports from the HID device.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device operation handle.| 
| reportType | Report type.| 
| data | Buffer for storing the read data.| 
| bufSize | Size of the buffer for storing read data. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is empty. 2. **data** is empty. 3. The value of **bufSize** is **0**. 4. The value of **bufSize** exceeds [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size).

- HID_DDK_INIT_ERROR DDK: DDK initialization error.

- HID_DDK_SERVICE_ERROR: DDK service communication error.

- HID_DDK_MEMORY_ERROR: Memory data copy error.

- HID_DDK_IO_ERROR: I/O operation error.

- HID_DDK_INVALID_OPERATION: Invalid operation.
<!--DelEnd-->

### OH_Hid_GetReportDescriptor()

```
int32_t OH_Hid_GetReportDescriptor (Hid_DeviceHandle * dev, uint8_t * buf, uint32_t bufSize, uint32_t * bytesRead )
```

**Description**

Obtains the report descriptor of the HID device.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device operation handle.| 
| buf | Buffer for storing descriptors.| 
| bufSize | Size of the buffer, in bytes. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size).| 
| bytesRead | Number of bytes to read.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is empty. 2. **buf** is empty. 3. The value of **bufSize** is **0**. 4. The value of **bufSize** exceeds that of **[HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size)**. 5. **bytesRead** is empty.

- HID_DDK_INIT_ERROR DDK: DDK initialization error.

- HID_DDK_SERVICE_ERROR: DDK service communication error.

- HID_DDK_MEMORY_ERROR: Memory data copy error.

- HID_DDK_IO_ERROR: I/O operation error.

- HID_DDK_INVALID_OPERATION: Invalid operation.


### OH_Hid_Init()

```
int32_t OH_Hid_Init (void )
```

**Description**

Initializes an HID DDK.

**Since**: 16

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INIT_ERROR: DDK initialization error.

- HID_DDK_SERVICE_ERROR: DDK service communication error.


### OH_Hid_Open()

```
int32_t OH_Hid_Open (uint64_t deviceId, uint8_t interfaceIndex, Hid_DeviceHandle ** dev )
```

**Description**

Opens the device specified by **deviceId** and **interfaceIndex**.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceId | Device ID.| 
| interfaceIndex | Interface index for the API of the HID device.| 
| dev | Device operation handle.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INIT_ERROR DDK: DDK initialization error.

- HID_DDK_SERVICE_ERROR: DDK service communication error.

- HID_DDK_MEMORY_ERROR: dev memory application error.

- HID_DDK_IO_ERROR: I/O operation error.

- HID_DDK_INVALID_PARAMETER: Empty **dev**.

- HID_DDK_DEVICE_NOT_FOUND: Device not found based on the specified **deviceId** and **interfaceIndex**.


### OH_Hid_Read()

```
int32_t OH_Hid_Read (Hid_DeviceHandle * dev, uint8_t * data, uint32_t bufSize, uint32_t * bytesRead )
```

**Description**

Reads reports from the HID device. The blocking mode (that is, blocking remains active until data can be read) is used by default. You can call [OH_Hid_SetNonBlocking](#oh_hid_setnonblocking) to change the mode.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device operation handle.| 
| data | Buffer for storing the read data.| 
| bufSize | Size of the buffer for storing read data. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size).| 
| bytesRead | Number of bytes to read.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is empty. 2. **data** is empty. 3. The value of **bufSize** is **0**. 4. The value of **bufSize** exceeds that of **[HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size)**. 5. **bytesRead** is empty.

- HID_DDK_INIT_ERROR DDK: DDK initialization error.

- HID_DDK_SERVICE_ERROR: DDK service communication error.

- HID_DDK_MEMORY_ERROR: Memory data copy error.

- HID_DDK_IO_ERROR: I/O operation error.

- HID_DDK_TIMEOUT: Reading timed out.


### OH_Hid_ReadTimeout()

```
int32_t OH_Hid_ReadTimeout (Hid_DeviceHandle * dev, uint8_t * data, uint32_t bufSize, int timeout, uint32_t * bytesRead )
```

**Description**

Reads reports from the HID device within the specified timeout interval.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device operation handle.| 
| data | Buffer for storing the read data.| 
| bufSize | Size of the buffer for storing read data. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size).| 
| timeout | Timeout interval, in ms. The value **-1** indicates block waiting.| 
| bytesRead | Number of bytes to read.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is empty. 2. **data** is empty. 3. The value of **bufSize** is **0**. 4. The value of **bufSize** exceeds that of **[HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size)**. 5. **bytesRead** is empty.

- HID_DDK_INIT_ERROR DDK: DDK initialization error.

- HID_DDK_SERVICE_ERROR: DDK service communication error.

- HID_DDK_MEMORY_ERROR: Memory data copy error.

- HID_DDK_IO_ERROR: I/O operation error.

- HID_DDK_TIMEOUT: Reading timed out.


### OH_Hid_Release()

```
int32_t OH_Hid_Release (void )
```

**Description**

Releases an HID DDK.

**Since**: 16

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INIT_ERROR DDK: DDK initialization error.

- HID_DDK_SERVICE_ERROR: DDK service communication error.

<!--Del-->
### OH_Hid_SendReport()

```
int32_t OH_Hid_SendReport (Hid_DeviceHandle * dev, Hid_ReportType reportType, const uint8_t * data, uint32_t length )
```

**Description**

Sends reports to the HID device.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device operation handle.| 
| reportType | Report type.| 
| data | Data to be sent.| 
| length | Length of the data to be sent, in bytes. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is empty. 2. **data** is empty. 3. The value of **length** is **0**; 4. The value of **length** exceeds [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size).

- HID_DDK_INIT_ERROR DDK: DDK initialization error.

- HID_DDK_SERVICE_ERROR: DDK service communication error.

- HID_DDK_IO_ERROR: I/O operation error.

- HID_DDK_INVALID_OPERATION: Invalid operation.

<!--DelEnd-->
### OH_Hid_SetNonBlocking()

```
int32_t OH_Hid_SetNonBlocking (Hid_DeviceHandle * dev, int nonBlock )
```

**Description**

Sets the device read mode to non-blocking mode.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device operation handle.| 
| nonBlock | Whether to enable the non-blocking mode for reading data.<br>- 1: The non-blocking mode is enabled. When [OH_Hid_Read](#oh_hid_read) is called, if the device has readable data, **HID_DDK_SUCCESS** is returned; if the device has no readable data, **HID_DDK_TIMEOUT** is returned.<br>- 0: The non-blocking mode is disabled.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INIT_ERROR DDK: DDK initialization error.

- HID_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is empty. 2. The value of **nonBlock** is not **1** or **0**.

- HID_DDK_SERVICE_ERROR: DDK service communication error.


### OH_Hid_Write()

```
int32_t OH_Hid_Write (Hid_DeviceHandle * dev, uint8_t * data, uint32_t length, uint32_t * bytesWritten )
```

**Description**

Writes reports to an HID device.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device operation handle.| 
| data | Data to be written.| 
| length | Length of the data to be written, in bytes. The value cannot exceed [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size).| 
| bytesWritten | Number of written bytes.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_HID

**Returns**

- HID_DDK_SUCCESS: Operation succeeded.

- HID_DDK_NO_PERM: Permission verification failed.

- HID_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is empty. 2. **data** is empty. 3. The value of length is **0**; 4. The value of **length** exceeds [HID_MAX_REPORT_BUFFER_SIZE](#hid_max_report_buffer_size); 5. **bytesWritten** is empty.

- HID_DDK_INIT_ERROR DDK: DDK initialization error.

- HID_DDK_SERVICE_ERROR: DDK service communication error.

- HID_DDK_IO_ERROR: I/O operation error.


## Variable Description


### bustype

```
uint16_t Hid_Device::bustype
```

**Description**

Bus type.


### busType

```
uint32_t Hid_RawDevInfo::busType
```

**Description**

Bus type.


### code

```
uint16_t Hid_EmitItem::code
```

**Description**

Event code.


### deviceName

```
const char* Hid_Device::deviceName
```

**Description**

Device name.


### hidAbs

```
struct Hid_AbsAxesArray Hid_EventProperties::hidAbs
```

**Description**

Array of absolute coordinates.


### hidAbsAxes

```
Hid_AbsAxes* Hid_AbsAxesArray::hidAbsAxes
```

**Description**

Absolute coordinates.


### hidAbsFlat

```
int32_t Hid_EventProperties::hidAbsFlat[64]
```

**Description**

Fixed values of the absolute coordinates.


### hidAbsFuzz

```
int32_t Hid_EventProperties::hidAbsFuzz[64]
```

**Description**

Fuzzy values of the absolute coordinates.


### hidAbsMax

```
int32_t Hid_EventProperties::hidAbsMax[64]
```

**Description**

Maximum values of the absolute coordinates.


### hidAbsMin

```
int32_t Hid_EventProperties::hidAbsMin[64]
```

**Description**

Minimum values of the absolute coordinates.


### hidEventType

```
Hid_EventType* Hid_EventTypeArray::hidEventType
```

**Description**

Event type.


### hidEventTypes

```
struct Hid_EventTypeArray Hid_EventProperties::hidEventTypes
```

**Description**

Array of event types.


### hidKeyCode

```
Hid_KeyCode* Hid_KeyCodeArray::hidKeyCode
```

**Description**

Key code.


### hidKeys

```
struct Hid_KeyCodeArray Hid_EventProperties::hidKeys
```

**Description**

Array of key codes.


### hidMiscellaneous

```
struct Hid_MscEventArray Hid_EventProperties::hidMiscellaneous
```

**Description**

Array of miscellaneous events.


### hidMscEvent

```
Hid_MscEvent* Hid_MscEventArray::hidMscEvent
```

**Description**

Miscellaneous event.


### hidRelAxes

```
Hid_RelAxes* Hid_RelAxesArray::hidRelAxes
```

**Description**

Relative coordinates.


### hidRelBits

```
struct Hid_RelAxesArray Hid_EventProperties::hidRelBits
```

**Description**

Array of relative coordinates.


### length [1/5]

```
uint16_t Hid_EventTypeArray::length
```

**Description**

Length of the event type array.


### length [2/5]

```
uint16_t Hid_KeyCodeArray::length
```

**Description**

Length of the key code array.


### length [3/5]

```
uint16_t Hid_AbsAxesArray::length
```

**Description**

Length of the absolute coordinate array.


### length [4/5]

```
uint16_t Hid_RelAxesArray::length
```

**Description**

Length of the relative coordinate array.


### length [5/5]

```
uint16_t Hid_MscEventArray::length
```

**Description**

Length of the event type array.


### product

```
uint16_t Hid_RawDevInfo::product
```

**Description**

Product ID.


### productId

```
uint16_t Hid_Device::productId
```

**Description**

Product ID.


### properties

```
Hid_DeviceProp* Hid_Device::properties
```

**Description**

Device properties.


### propLength

```
uint16_t Hid_Device::propLength
```

**Description**

Number of device properties.


### type

```
uint16_t Hid_EmitItem::type
```

**Description**

Event type.


### value

```
uint32_t Hid_EmitItem::value
```

**Description**

Event value.


### vendor

```
uint16_t Hid_RawDevInfo::vendor
```

**Description**

Provider ID.


### vendorId

```
uint16_t Hid_Device::vendorId
```

**Description**

Vendor ID.


### version

```
uint16_t Hid_Device::version
```

**Description**

Version number.
