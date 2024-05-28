# HID DDK


## 概述

提供HID DDK接口，包括创建设备、发送事件、销毁设备。

**系统能力：** SystemCapability.Driver.HID.Extension

**起始版本：** 

11

## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [hid_ddk_api.h](hid__ddk__api_8h.md) | 声明主机侧访问输入设备的HID DDK接口。<br/>引用文件：&lt;hid/hid_ddk_api.h&gt; <br/>库： libhid.z.so | 
| [hid_ddk_types.h](hid__ddk__types_8h.md) | 提供HID DDK中的枚举变量与结构体定义。<br/>引用文件：&lt;hid/hid_ddk_types.h&gt; <br/>库： libhid.z.so  | 


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
| [Hid_EmitItem](#hid_emititem) | 事件信息。  | 
| [Hid_Device](#hid_device) | 设备基本信息。  | 
| [Hid_EventTypeArray](#hid_eventtypearray) | 事件类型编码数组。  | 
| [Hid_KeyCodeArray](#hid_keycodearray) | 键值属性数组。  | 
| [Hid_AbsAxesArray](#hid_absaxesarray) | 绝对坐标属性数组。  | 
| [Hid_RelAxesArray](#hid_relaxesarray) | 相对坐标属性数组。  | 
| [Hid_MscEventArray](#hid_msceventarray) | 其它特殊事件属性数组。  | 
| [Hid_EventProperties](#hid_eventproperties) | 设备关注事件属性。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Hid_DeviceProp](#hid_deviceprop) {<br/>HID_PROP_POINTER = 0x00, HID_PROP_DIRECT = 0x01, HID_PROP_BUTTON_PAD = 0x02, HID_PROP_SEMI_MT = 0x03,<br/>HID_PROP_TOP_BUTTON_PAD = 0x04, HID_PROP_POINTING_STICK = 0x05, HID_PROP_ACCELEROMETER = 0x06<br/>} | 输入设备特性定义。  | 
| [Hid_EventType](#hid_eventtype) {<br/>HID_EV_SYN = 0x00, HID_EV_KEY = 0x01, HID_EV_REL = 0x02, HID_EV_ABS = 0x03,<br/>HID_EV_MSC = 0x04<br/>} | 事件类型。  | 
| [Hid_SynEvent](#hid_synevent) { HID_SYN_REPORT = 0, HID_SYN_CONFIG = 1, HID_SYN_MT_REPORT = 2, HID_SYN_DROPPED = 3 } | 同步事件编码。  | 
| [Hid_KeyCode](#hid_keycode) {<br/>HID_KEY_A = 30, HID_KEY_B = 48, HID_KEY_C = 46, HID_KEY_D = 32,<br/>HID_KEY_E = 18, HID_KEY_F = 33, HID_KEY_G = 34, HID_KEY_H = 35,<br/>HID_KEY_I = 23, HID_KEY_J = 36, HID_KEY_K = 37, HID_KEY_L = 38,<br/>HID_KEY_M = 50, HID_KEY_N = 49, HID_KEY_O = 24, HID_KEY_P = 25,<br/>HID_KEY_Q = 16, HID_KEY_R = 19, HID_KEY_S = 31, HID_KEY_T = 20,<br/>HID_KEY_U = 22, HID_KEY_V = 47, HID_KEY_W = 17, HID_KEY_X = 45,<br/>HID_KEY_Y = 21, HID_KEY_Z = 44, HID_KEY_ESC = 1, HID_KEY_0 = 11,<br/>HID_KEY_1 = 2, HID_KEY_2 = 3, HID_KEY_3 = 4, HID_KEY_4 = 5,<br/>HID_KEY_5 = 6, HID_KEY_6 = 7, HID_KEY_7 = 8, HID_KEY_8 = 9,<br/>HID_KEY_9 = 10, HID_KEY_GRAVE = 41, HID_KEY_MINUS = 12, HID_KEY_EQUALS = 13,<br/>HID_KEY_BACKSPACE = 14, HID_KEY_LEFT_BRACKET = 26, HID_KEY_RIGHT_BRACKET = 27, HID_KEY_ENTER = 28,<br/>HID_KEY_LEFT_SHIFT = 42, HID_KEY_BACKSLASH = 43, HID_KEY_SEMICOLON = 39, HID_KEY_APOSTROPHE = 40,<br/>HID_KEY_SPACE = 57, HID_KEY_SLASH = 53, HID_KEY_COMMA = 51, HID_KEY_PERIOD = 52,<br/>HID_KEY_RIGHT_SHIFT = 54, HID_KEY_NUMPAD_0 = 82, HID_KEY_NUMPAD_1 = 79, HID_KEY_NUMPAD_2 = 80,<br/>HID_KEY_NUMPAD_3 = 81, HID_KEY_NUMPAD_4 = 75, HID_KEY_NUMPAD_5 = 76, HID_KEY_NUMPAD_6 = 77,<br/>HID_KEY_NUMPAD_7 = 71, HID_KEY_NUMPAD_8 = 72, HID_KEY_NUMPAD_9 = 73, HID_KEY_NUMPAD_DIVIDE = 70,<br/>HID_KEY_NUMPAD_MULTIPLY = 55, HID_KEY_NUMPAD_SUBTRACT = 74, HID_KEY_NUMPAD_ADD = 78, HID_KEY_NUMPAD_DOT = 83,<br/>HID_KEY_SYSRQ = 99, HID_KEY_MUTE = 113, HID_KEY_VOLUME_DOWN = 114, HID_KEY_VOLUME_UP = 115,<br/>HID_KEY_BRIGHTNESS_DOWN = 224, HID_KEY_BRIGHTNESS_UP = 225, HID_BTN_0 = 0x100, HID_BTN_1 = 0x101,<br/>HID_BTN_2 = 0x102, HID_BTN_3 = 0x103, HID_BTN_4 = 0x104, HID_BTN_5 = 0x105,<br/>HID_BTN_6 = 0x106, HID_BTN_7 = 0x107, HID_BTN_8 = 0x108, HID_BTN_9 = 0x109,<br/>HID_BTN_LEFT = 0x110, HID_BTN_RIGHT = 0x111, HID_BTN_MIDDLE = 0x112, HID_BTN_SIDE = 0x113,<br/>HID_BTN_EXTRA = 0x114, HID_BTN_FORWARD = 0x115, HID_BTN_BACKWARD = 0x116, HID_BTN_TASK = 0x117,<br/>HID_BTN_TOOL_PEN = 0x140, HID_BTN_TOOL_RUBBER = 0x141, HID_BTN_TOOL_BRUSH = 0x142, HID_BTN_TOOL_PENCIL = 0x143,<br/>HID_BTN_TOOL_AIRBRUSH = 0x144, HID_BTN_TOOL_FINGER = 0x145, HID_BTN_TOOL_MOUSE = 0x146, HID_BTN_TOOL_LENS = 0x147,<br/>HID_BTN_TOOL_QUINT_TAP = 0x148, HID_BTN_STYLUS3 = 0x149, HID_BTN_TOUCH = 0x14a, HID_BTN_STYLUS = 0x14b,<br/>HID_BTN_STYLUS2 = 0x14c, HID_BTN_TOOL_DOUBLE_TAP = 0x14d, HID_BTN_TOOL_TRIPLE_TAP = 0x14e, HID_BTN_TOOL_QUAD_TAP = 0x14f,<br/>HID_BTN_WHEEL = 0x150<br/>} | 键值编码。  | 
| [Hid_AbsAxes](#hid_absaxes) {<br/>HID_ABS_X = 0x00, HID_ABS_Y = 0x01, HID_ABS_Z = 0x02, HID_ABS_RX = 0x03,<br/>HID_ABS_RY = 0x04, HID_ABS_RZ = 0x05, HID_ABS_THROTTLE = 0x06, HID_ABS_RUDDER = 0x07,<br/>HID_ABS_WHEEL = 0x08, HID_ABS_GAS = 0x09, HID_ABS_BRAKE = 0x0a, HID_ABS_HAT0X = 0x10,<br/>HID_ABS_HAT0Y = 0x11, HID_ABS_HAT1X = 0x12, HID_ABS_HAT1Y = 0x13, HID_ABS_HAT2X = 0x14,<br/>HID_ABS_HAT2Y = 0x15, HID_ABS_HAT3X = 0x16, HID_ABS_HAT3Y = 0x17, HID_ABS_PRESSURE = 0x18,<br/>HID_ABS_DISTANCE = 0x19, HID_ABS_TILT_X = 0x1a, HID_ABS_TILT_Y = 0x1b, HID_ABS_TOOL_WIDTH = 0x1c,<br/>HID_ABS_VOLUME = 0x20, HID_ABS_MISC = 0x28<br/>} | 绝对坐标编码。  | 
| [Hid_RelAxes](#hid_relaxes) {<br/>HID_REL_X = 0x00, HID_REL_Y = 0x01, HID_REL_Z = 0x02, HID_REL_RX = 0x03,<br/>HID_REL_RY = 0x04, HID_REL_RZ = 0x05, HID_REL_HWHEEL = 0x06, HID_REL_DIAL = 0x07,<br/>HID_REL_WHEEL = 0x08, HID_REL_MISC = 0x09, HID_REL_RESERVED = 0x0a, HID_REL_WHEEL_HI_RES = 0x0b,<br/>HID_REL_HWHEEL_HI_RES = 0x0c<br/>} | 相对坐标编码。  | 
| [Hid_MscEvent](#hid_mscevent) {<br/>HID_MSC_SERIAL = 0x00, HID_MSC_PULSE_LED = 0x01, HID_MSC_GESTURE = 0x02, HID_MSC_RAW = 0x03,<br/>HID_MSC_SCAN = 0x04, HID_MSC_TIMESTAMP = 0x05<br/>} | 不适合其它类型的输入事件编码。  | 
| [Hid_DdkErrCode](#hid_ddkerrcode) {<br/>HID_DDK_SUCCESS = 0, HID_DDK_FAILURE = -1, HID_DDK_INVALID_PARAMETER = -2, HID_DDK_INVALID_OPERATION = -3,<br/>HID_DDK_NULL_PTR = -4, HID_DDK_TIMEOUT = -5, HID_DDK_NO_PERM = -6<br/>} | HID DDK错误码定义。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Hid_CreateDevice](#oh_hid_createdevice) ([Hid_Device](_hid___device.md) \*hidDevice, [Hid_EventProperties](_hid___event_properties.md) \*hidEventProperties) | 创建设备。  | 
| [OH_Hid_EmitEvent](#oh_hid_emitevent) (int32_t deviceId, const [Hid_EmitItem](_hid___emit_item.md) items[], uint16_t length) | 向指定设备发送事件列表。  | 
| [OH_Hid_DestroyDevice](#oh_hid_destroydevice) (int32_t deviceId) | 销毁设备。  | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| [Hid_EmitItem::type](#type) | 事件类型  | 
| [Hid_EmitItem::code](#code) | 事件编码  | 
| [Hid_EmitItem::value](#value) | 事件值  | 
| [Hid_Device::deviceName](#devicename) | 设备名称  | 
| [Hid_Device::vendorId](#vendorid) | 厂商ID  | 
| [Hid_Device::productId](#productid) | 产品ID  | 
| [Hid_Device::version](#version) | 版本号  | 
| [Hid_Device::bustype](#bustype) | 总线类型  | 
| [Hid_Device::properties](#properties) | 设备特性  | 
| [Hid_Device::propLength](#proplength) | 设备特性数量  | 
| [Hid_EventTypeArray::hidEventType](#hideventtype) | 事件类型编码  | 
| [Hid_EventTypeArray::length](#length-15) | 数组长度  | 
| [Hid_KeyCodeArray::hidKeyCode](#hidkeycode) | 键值编码  | 
| [Hid_KeyCodeArray::length](#length-25) | 数组长度  | 
| [Hid_AbsAxesArray::hidAbsAxes](#hidabsaxes) | 绝对坐标属性编码  | 
| [Hid_AbsAxesArray::length](#length-35) | 数组长度  | 
| [Hid_RelAxesArray::hidRelAxes](#hidrelaxes) | 相对坐标属性编码  | 
| [Hid_RelAxesArray::length](#length-45) | 数组长度  | 
| [Hid_MscEventArray::hidMscEvent](#hidmscevent) | 其它特殊事件属性编码  | 
| [Hid_MscEventArray::length](#length-55) | 数组长度  | 
| [Hid_EventProperties::hidEventTypes](#hideventtypes) | 事件类型属性编码数组  | 
| [Hid_EventProperties::hidKeys](#hidkeys) | 键值属性编码数组  | 
| [Hid_EventProperties::hidAbs](#hidabs) | 绝对坐标属性编码数组  | 
| [Hid_EventProperties::hidRelBits](#hidrelbits) | 相对坐标属性编码数组  | 
| [Hid_EventProperties::hidMiscellaneous](#hidmiscellaneous) | 其它特殊事件属性编码数组  | 
| [Hid_EventProperties::hidAbsMax](#hidabsmax) [64] | 绝对坐标属性最大值  | 
| [Hid_EventProperties::hidAbsMin](#hidabsmin) [64] | 绝对坐标属性最小值  | 
| [Hid_EventProperties::hidAbsFuzz](#hidabsfuzz) [64] | 绝对坐标属性模糊值  | 
| [Hid_EventProperties::hidAbsFlat](#hidabsflat) [64] | 绝对坐标属性固定值  | 


## 类型定义说明


### Hid_AbsAxesArray

```
typedef struct Hid_AbsAxesArrayHid_AbsAxesArray
```
**描述**
绝对坐标属性数组。

**起始版本：** 11


### Hid_Device

```
typedef struct Hid_DeviceHid_Device
```
**描述**
设备基本信息。

**起始版本：** 11


### Hid_EmitItem

```
typedef struct Hid_EmitItemHid_EmitItem
```
**描述**
事件信息。

**起始版本：** 11


### Hid_EventProperties

```
typedef struct Hid_EventPropertiesHid_EventProperties
```
**描述**
设备关注事件属性。

**起始版本：** 11


### Hid_EventTypeArray

```
typedef struct Hid_EventTypeArrayHid_EventTypeArray
```
**描述**
事件类型编码数组。

**起始版本：** 11


### Hid_KeyCodeArray

```
typedef struct Hid_KeyCodeArrayHid_KeyCodeArray
```
**描述**
键值属性数组。

**起始版本：** 11


### Hid_MscEventArray

```
typedef struct Hid_MscEventArrayHid_MscEventArray
```
**描述**
其它特殊事件属性数组。

**起始版本：** 11


### Hid_RelAxesArray

```
typedef struct Hid_RelAxesArrayHid_RelAxesArray
```
**描述**
相对坐标属性数组。

**起始版本：** 11


## 枚举类型说明


### Hid_AbsAxes

```
enum Hid_AbsAxes
```
**描述**
绝对坐标编码。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| HID_ABS_X  | X轴 | 
| HID_ABS_Y  | Y轴 | 
| HID_ABS_Z  | Z轴 | 
| HID_ABS_RX  | 右模拟摇杆的 X 轴 | 
| HID_ABS_RY  | 右模拟摇杆的 Y 轴 | 
| HID_ABS_RZ  | 右模拟摇杆的 Z 轴 | 
| HID_ABS_THROTTLE  | 油门 | 
| HID_ABS_RUDDER  | 舵 | 
| HID_ABS_WHEEL  | 滚轮 | 
| HID_ABS_GAS  | 气 | 
| HID_ABS_BRAKE  | 制动 | 
| HID_ABS_HAT0X  | HAT0X | 
| HID_ABS_HAT0Y  | HAT0Y | 
| HID_ABS_HAT1X  | HAT1X | 
| HID_ABS_HAT1Y  | HAT1Y | 
| HID_ABS_HAT2X  | HAT2X | 
| HID_ABS_HAT2Y  | HAT2Y | 
| HID_ABS_HAT3X  | HAT3X | 
| HID_ABS_HAT3Y  | HAT3Y | 
| HID_ABS_PRESSURE  | 压力 | 
| HID_ABS_DISTANCE  | 距离 | 
| HID_ABS_TILT_X  | X轴倾斜度 | 
| HID_ABS_TILT_Y  | Y轴倾斜度 | 
| HID_ABS_TOOL_WIDTH  | 触摸工具的宽度 | 
| HID_ABS_VOLUME  | 音量 | 
| HID_ABS_MISC  | 其它 | 


### Hid_DdkErrCode

```
enum Hid_DdkErrCode
```
**描述**
HID DDK错误码定义。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| HID_DDK_SUCCESS  | 操作成功 | 
| HID_DDK_FAILURE  | 操作失败 | 
| HID_DDK_INVALID_PARAMETER  | 非法参数 | 
| HID_DDK_INVALID_OPERATION  | 非法操作 | 
| HID_DDK_NULL_PTR  | 空指针异常 | 
| HID_DDK_TIMEOUT  | 超时 | 
| HID_DDK_NO_PERM  | 没有权限 | 


### Hid_DeviceProp

```
enum Hid_DeviceProp
```
**描述**
输入设备特性定义。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| HID_PROP_POINTER  | 指针设备 | 
| HID_PROP_DIRECT  | 直接输入设备 | 
| HID_PROP_BUTTON_PAD  | 底部按键触摸设备 | 
| HID_PROP_SEMI_MT  | 全多点触控设备 | 
| HID_PROP_TOP_BUTTON_PAD  | 顶部软按键触摸设备 | 
| HID_PROP_POINTING_STICK  | 指点杆设备 | 
| HID_PROP_ACCELEROMETER  | 加速度传感器设备 | 


### Hid_EventType

```
enum Hid_EventType
```
**描述**
事件类型。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| HID_EV_SYN  | 同步事件 | 
| HID_EV_KEY  | 按键事件 | 
| HID_EV_REL  | 相对坐标事件 | 
| HID_EV_ABS  | 绝对坐标事件 | 
| HID_EV_MSC  | 特殊事件 | 


### Hid_KeyCode

```
enum Hid_KeyCode
```
**描述**
键值编码。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| HID_KEY_A  | 键A | 
| HID_KEY_B  | 键B | 
| HID_KEY_C  | 键C | 
| HID_KEY_D  | 键D | 
| HID_KEY_E  | 键E | 
| HID_KEY_F  | 键F | 
| HID_KEY_G  | 键G | 
| HID_KEY_H  | 键H | 
| HID_KEY_I  | 键I | 
| HID_KEY_J  | 键J | 
| HID_KEY_K  | 键K | 
| HID_KEY_L  | 键L | 
| HID_KEY_M  | 键M | 
| HID_KEY_N  | 键N | 
| HID_KEY_O  | 键O | 
| HID_KEY_P  | 键P | 
| HID_KEY_Q  | 键Q | 
| HID_KEY_R  | 键R | 
| HID_KEY_S  | 键S | 
| HID_KEY_T  | 键T | 
| HID_KEY_U  | 键U | 
| HID_KEY_V  | 键V | 
| HID_KEY_W  | 键W | 
| HID_KEY_X  | 键X | 
| HID_KEY_Y  | 键Y | 
| HID_KEY_Z  | 键Z | 
| HID_KEY_ESC  | 键ESC | 
| HID_KEY_0  | 键0 | 
| HID_KEY_1  | 键1 | 
| HID_KEY_2  | 键2 | 
| HID_KEY_3  | 键3 | 
| HID_KEY_4  | 键4 | 
| HID_KEY_5  | 键5 | 
| HID_KEY_6  | 键6 | 
| HID_KEY_7  | 键7 | 
| HID_KEY_8  | 键8 | 
| HID_KEY_9  | 键9 | 
| HID_KEY_GRAVE  | 键` | 
| HID_KEY_MINUS  | 键- | 
| HID_KEY_EQUALS  | 键= | 
| HID_KEY_BACKSPACE  | 键退格 | 
| HID_KEY_LEFT_BRACKET  | 键[ | 
| HID_KEY_RIGHT_BRACKET  | 键] | 
| HID_KEY_ENTER  | 键回车 | 
| HID_KEY_LEFT_SHIFT  | 键左shift | 
| HID_KEY_BACKSLASH  | 键\ | 
| HID_KEY_SEMICOLON  | 键; | 
| HID_KEY_APOSTROPHE  | 键' | 
| HID_KEY_SPACE  | 键空格 | 
| HID_KEY_SLASH  | 键/ | 
| HID_KEY_COMMA  | 键, | 
| HID_KEY_PERIOD  | 键. | 
| HID_KEY_RIGHT_SHIFT  | 键右shift | 
| HID_KEY_NUMPAD_0  | 数字键0 | 
| HID_KEY_NUMPAD_1  | 数字键1 | 
| HID_KEY_NUMPAD_2  | 数字键2 | 
| HID_KEY_NUMPAD_3  | 数字键3 | 
| HID_KEY_NUMPAD_4  | 数字键4 | 
| HID_KEY_NUMPAD_5  | 数字键5 | 
| HID_KEY_NUMPAD_6  | 数字键6 | 
| HID_KEY_NUMPAD_7  | 数字键7 | 
| HID_KEY_NUMPAD_8  | 数字键8 | 
| HID_KEY_NUMPAD_9  | 数字键9 | 
| HID_KEY_NUMPAD_DIVIDE  | 数字键/ | 
| HID_KEY_NUMPAD_MULTIPLY  | 数字键\* | 
| HID_KEY_NUMPAD_SUBTRACT  | 数字键- | 
| HID_KEY_NUMPAD_ADD  | 数字键+ | 
| HID_KEY_NUMPAD_DOT  | 数字键. | 
| HID_KEY_SYSRQ  | 键ESC | 
| HID_KEY_MUTE  | 键静音 | 
| HID_KEY_VOLUME_DOWN  | 键音量- | 
| HID_KEY_VOLUME_UP  | 键音量+ | 
| HID_KEY_BRIGHTNESS_DOWN  | 键亮度- | 
| HID_KEY_BRIGHTNESS_UP  | 键亮度+ | 
| HID_BTN_0  | 按钮0 | 
| HID_BTN_1  | 按钮1 | 
| HID_BTN_2  | 按钮2 | 
| HID_BTN_3  | 按钮3 | 
| HID_BTN_4  | 按钮4 | 
| HID_BTN_5  | 按钮5 | 
| HID_BTN_6  | 按钮6 | 
| HID_BTN_7  | 按钮7 | 
| HID_BTN_8  | 按钮8 | 
| HID_BTN_9  | 按钮9 | 
| HID_BTN_LEFT  | 鼠标按键左键 | 
| HID_BTN_RIGHT  | 鼠标按键右键 | 
| HID_BTN_MIDDLE  | 鼠标按键中键 | 
| HID_BTN_SIDE  | 鼠标侧面按键 | 
| HID_BTN_EXTRA  | 鼠标附加按键 | 
| HID_BTN_FORWARD  | 鼠标向前按键 | 
| HID_BTN_BACKWARD  | 鼠标向后按键 | 
| HID_BTN_TASK  | 鼠标任务按键 | 
| HID_BTN_TOOL_PEN  | 画笔 | 
| HID_BTN_TOOL_RUBBER  | 橡皮擦 | 
| HID_BTN_TOOL_BRUSH  | 笔刷 | 
| HID_BTN_TOOL_PENCIL  | 铅笔 | 
| HID_BTN_TOOL_AIRBRUSH  | 喷枪 | 
| HID_BTN_TOOL_FINGER  | 手指 | 
| HID_BTN_TOOL_MOUSE  | 鼠标 | 
| HID_BTN_TOOL_LENS  | 镜头 | 
| HID_BTN_TOOL_QUINT_TAP  | 五指触控 | 
| HID_BTN_STYLUS3  | 手写笔3 | 
| HID_BTN_TOUCH  | 触摸 | 
| HID_BTN_STYLUS  | 手写笔 | 
| HID_BTN_STYLUS2  | 手写笔2 | 
| HID_BTN_TOOL_DOUBLE_TAP  | 二指触控 | 
| HID_BTN_TOOL_TRIPLE_TAP  | 三指触控 | 
| HID_BTN_TOOL_QUAD_TAP  | 四指触控 | 
| HID_BTN_WHEEL  | 滚轮 | 


### Hid_MscEvent

```
enum Hid_MscEvent
```
**描述**
不适合其它类型的输入事件编码。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| HID_MSC_SERIAL  | 序列号 | 
| HID_MSC_PULSE_LED  | 脉冲 | 
| HID_MSC_GESTURE  | 手势 | 
| HID_MSC_RAW  | 开始事件 | 
| HID_MSC_SCAN  | 扫描 | 
| HID_MSC_TIMESTAMP  | 时间戳 | 


### Hid_RelAxes

```
enum Hid_RelAxes
```
**描述**
相对坐标编码。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| HID_REL_X  | X轴 | 
| HID_REL_Y  | Y轴 | 
| HID_REL_Z  | Z轴 | 
| HID_REL_RX  | 右模拟摇杆的 X 轴 | 
| HID_REL_RY  | 右模拟摇杆的 Y 轴 | 
| HID_REL_RZ  | 右模拟摇杆的 Z 轴 | 
| HID_REL_HWHEEL  | 水平滚轮 | 
| HID_REL_DIAL  | 刻度 | 
| HID_REL_WHEEL  | 滚轮 | 
| HID_REL_MISC  | 其它 | 
| HID_REL_RESERVED  | 预留 | 
| HID_REL_WHEEL_HI_RES  | 高分辨率滚轮 | 
| HID_REL_HWHEEL_HI_RES  | 高分辨率水平滚轮 | 


### Hid_SynEvent

```
enum Hid_SynEvent
```
**描述**
同步事件编码。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| HID_SYN_REPORT  | 表示一个事件的结束 | 
| HID_SYN_CONFIG  | 表示配置同步 | 
| HID_SYN_MT_REPORT  | 表示多点触摸的ABS数据包结束 | 
| HID_SYN_DROPPED  | 表示该事件被丢弃 | 


## 函数说明


### OH_Hid_CreateDevice()

```
int32_t OH_Hid_CreateDevice (Hid_Device * hidDevice, Hid_EventProperties * hidEventProperties )
```
**描述**
创建设备。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| hidDevice | 创建设备需要的基本信息，包括设备名、厂商ID、产品ID等。  | 
| hidEventProperties | 创建的设备关注的事件，包括事件类型、按键事件属性、绝对坐标事件属性、相对坐标事件属性等。  | 

**Permission：**

ohos.permission.ACCESS_DDK_HID

**返回：**

成功返回设备ID，非负数；否则返回负数。


### OH_Hid_DestroyDevice()

```
int32_t OH_Hid_DestroyDevice (int32_t deviceId)
```
**描述**
销毁设备。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deviceId | 设备ID。  | 

**Permission：**

ohos.permission.ACCESS_DDK_HID

**返回：**

成功返回0，否则返回负数。


### OH_Hid_EmitEvent()

```
int32_t OH_Hid_EmitEvent (int32_t deviceId, const Hid_EmitItem items[], uint16_t length )
```
**描述**
向指定设备发送事件列表。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deviceId | 设备ID。  | 
| items | 发送的事件列表，事件包括类型（取值来源事件类型Hid_EventType）、编码（取值来源同步事件编码Hid_SynEvent、键值编码Hid_KeyCode、按钮编码HidBtnCode、 绝对坐标编码Hid_AbsAxes、相对坐标编码Hid_RelAxes、其它类型的输入事件编码Hid_MscEvent）、值（根据实际设备输入决定）。  | 
| length | 发送事件列表长度（一次发送事件个数）。  | 

**Permission：**

ohos.permission.ACCESS_DDK_HID

**返回：**

成功返回0，否则返回负数。


## 变量说明


### bustype

```
uint16_t Hid_Device::bustype
```
**描述**
总线类型


### code

```
uint16_t Hid_EmitItem::code
```
**描述**
事件编码


### deviceName

```
const char* Hid_Device::deviceName
```
**描述**
设备名称


### hidAbs

```
struct Hid_AbsAxesArray Hid_EventProperties::hidAbs
```
**描述**
绝对坐标属性编码数组


### hidAbsAxes

```
Hid_AbsAxes* Hid_AbsAxesArray::hidAbsAxes
```
**描述**
绝对坐标属性编码


### hidAbsFlat

```
int32_t Hid_EventProperties::hidAbsFlat[64]
```
**描述**
绝对坐标属性固定值


### hidAbsFuzz

```
int32_t Hid_EventProperties::hidAbsFuzz[64]
```
**描述**
绝对坐标属性模糊值


### hidAbsMax

```
int32_t Hid_EventProperties::hidAbsMax[64]
```
**描述**
绝对坐标属性最大值


### hidAbsMin

```
int32_t Hid_EventProperties::hidAbsMin[64]
```
**描述**
绝对坐标属性最小值


### hidEventType

```
Hid_EventType* Hid_EventTypeArray::hidEventType
```
**描述**
事件类型编码


### hidEventTypes

```
struct Hid_EventTypeArray Hid_EventProperties::hidEventTypes
```
**描述**
事件类型属性编码数组


### hidKeyCode

```
Hid_KeyCode* Hid_KeyCodeArray::hidKeyCode
```
**描述**
键值编码


### hidKeys

```
struct Hid_KeyCodeArray Hid_EventProperties::hidKeys
```
**描述**
键值属性编码数组


### hidMiscellaneous

```
struct Hid_MscEventArray Hid_EventProperties::hidMiscellaneous
```
**描述**
其它特殊事件属性编码数组


### hidMscEvent

```
Hid_MscEvent* Hid_MscEventArray::hidMscEvent
```
**描述**
其它特殊事件属性编码


### hidRelAxes

```
Hid_RelAxes* Hid_RelAxesArray::hidRelAxes
```
**描述**
相对坐标属性编码


### hidRelBits

```
struct Hid_RelAxesArray Hid_EventProperties::hidRelBits
```
**描述**
相对坐标属性编码数组


### length [1/5]

```
uint16_t Hid_EventTypeArray::length
```
**描述**
数组长度


### length [2/5]

```
uint16_t Hid_KeyCodeArray::length
```
**描述**
数组长度


### length [3/5]

```
uint16_t Hid_AbsAxesArray::length
```
**描述**
数组长度


### length [4/5]

```
uint16_t Hid_RelAxesArray::length
```
**描述**
数组长度


### length [5/5]

```
uint16_t Hid_MscEventArray::length
```
**描述**
数组长度


### productId

```
uint16_t Hid_Device::productId
```
**描述**
产品ID


### properties

```
Hid_DeviceProp* Hid_Device::properties
```
**描述**
设备特性


### propLength

```
uint16_t Hid_Device::propLength
```
**描述**
设备特性数量


### type

```
uint16_t Hid_EmitItem::type
```
**描述**
事件类型


### value

```
uint32_t Hid_EmitItem::value
```
**描述**
事件值


### vendorId

```
uint16_t Hid_Device::vendorId
```
**描述**
厂商ID


### version

```
uint16_t Hid_Device::version
```
**描述**
版本号
