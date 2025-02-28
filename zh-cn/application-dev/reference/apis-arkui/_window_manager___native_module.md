# WindowManager_NativeModule


## 概述

提供应用窗口的管理能力。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [oh_window.h](oh__window_8h.md) | 定义窗口管理的相关接口，主要用于设置和获取指定窗口的属性，以及设置指定窗口的状态栏样式、导航栏样式。 |
| [oh_window_comm.h](oh__window__comm_8h.md) | 提供窗口的公共枚举、公共定义等。 |
| [oh_window_event_filter.h](oh__window__event__filter_8h.md) | 定义窗口管理按键事件过滤的接口，当多模输入的事件经过窗口时，可以通过过滤接口拦截事件不让事件往下分发。 |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| struct  [WindowManager_Rect](_window_manager___rect.md) | 定义窗口矩形结构体，包含窗口位置和宽高信息。 |
| struct  [WindowManager_WindowProperties](_window_manager___window_properties.md) | 窗口属性。 |
| struct  [WindowManager_AvoidArea](_window_manager___avoid_area.md) | 定义避让区域结构体。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [WindowManager_ErrorCode](#windowmanager_errorcode)  [WindowManager_ErrorCode](#windowmanager_errorcode) | 窗口管理接口返回状态码枚举。 |
| typedef bool(\* [OH_NativeWindowManager_KeyEventFilter](#oh_nativewindowmanager_keyeventfilter)) (Input_KeyEvent \*keyEvent) | 定义多模按键的过滤函数。 |
| typedef bool(\* [OH_NativeWindowManager_MouseEventFilter](#oh_nativewindowmanager_mouseeventfilter)) (Input_MouseEvent \*mouseEvent) | 定义多模鼠标事件的过滤函数。 |
| typedef bool(\* [OH_NativeWindowManager_TouchEventFilter](#oh_nativewindowmanager_toucheventfilter)) (Input_TouchEvent \*touchEvent) | 定义多模触摸事件的过滤函数。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [WindowManager_ErrorCode](#windowmanager_errorcode-1) {<br/>OK = 0, WINDOW_MANAGER_ERRORCODE_NO_PERMISSION = 201, WINDOW_MANAGER_ERRORCODE_INVALID_PARAM = 401, WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED = 801,<br/>INVAILD_WINDOW_ID = 1000, SERVICE_ERROR = 2000, WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL = 1300002, WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL = 1300003<br/>} | 窗口管理接口返回状态码枚举。 |
| [WindowManager_AvoidAreaType](#windowmanager_avoidareatype) {<br/>WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM = 0, WINDOW_MANAGER_AVOID_AREA_TYPE_CUTOUT = 1, WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM_GESTURE = 2, WINDOW_MANAGER_AVOID_AREA_TYPE_KEYBOARD = 3,<br/>WINDOW_MANAGER_AVOID_AREA_TYPE_NAVIGATION_INDICATOR = 4<br/>} | 避让区域枚举类型。 |
| [WindowManager_WindowType](#windowmanager_windowtype) { WINDOW_MANAGER_WINDOW_TYPE_APP = 0, WINDOW_MANAGER_WINDOW_TYPE_MAIN = 1, WINDOW_MANAGER_WINDOW_TYPE_FLOAT = 8, WINDOW_MANAGER_WINDOW_TYPE_DIALOG = 16 } | 窗口类型。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| int32_t [OH_WindowManager_SetWindowStatusBarEnabled](#oh_windowmanager_setwindowstatusbarenabled) (int32_t windowId, bool enabled, bool enableAnimation) | 设置指定窗口是否显示状态栏。 |
| int32_t [OH_WindowManager_SetWindowStatusBarColor](#oh_windowmanager_setwindowstatusbarcolor) (int32_t windowId, int32_t color) | 设置指定窗口的状态栏内容颜色。 |
| int32_t [OH_WindowManager_SetWindowNavigationBarEnabled](#oh_windowmanager_setwindownavigationbarenabled) (int32_t windowId, bool enabled, bool enableAnimation) | 设置指定窗口是否显示导航栏。 |
| int32_t [OH_WindowManager_GetWindowAvoidArea](#oh_windowmanager_getwindowavoidarea) (int32_t windowId, [WindowManager_AvoidAreaType](#windowmanager_avoidareatype) type, [WindowManager_AvoidArea](_window_manager___avoid_area.md) \*avoidArea) | 获取指定窗口的避让区域。 |
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_WindowManager_IsWindowShown](#oh_windowmanager_iswindowshown) (int32_t windowId, bool \*isShow) | 判断指定窗口是否显示。 |
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_WindowManager_ShowWindow](#oh_windowmanager_showwindow) (int32_t windowId) | 显示指定窗口。 |
| int32_t [OH_WindowManager_SetWindowTouchable](#oh_windowmanager_setwindowtouchable) (int32_t windowId, bool isTouchable) | 设置指定窗口是否可触。 |
| int32_t [OH_WindowManager_SetWindowFocusable](#oh_windowmanager_setwindowfocusable) (int32_t windowId, bool isFocusable) | 设置指定窗口是否可获焦。 |
| int32_t [OH_WindowManager_SetWindowBackgroundColor](#oh_windowmanager_setwindowbackgroundcolor) (int32_t windowId, const char \*color) | 设置指定窗口背景颜色。 |
| int32_t [OH_WindowManager_SetWindowBrightness](#oh_windowmanager_setwindowbrightness) (int32_t windowId, float brightness) | 设置指定窗口的屏幕亮度。 |
| int32_t [OH_WindowManager_SetWindowKeepScreenOn](#oh_windowmanager_setwindowkeepscreenon) (int32_t windowId, bool isKeepScreenOn) | 设置指定窗口是否开启屏幕常亮。 |
| int32_t [OH_WindowManager_SetWindowPrivacyMode](#oh_windowmanager_setwindowprivacymode) (int32_t windowId, bool isPrivacy) | 设置指定窗口是否开启隐私模式。 |
| int32_t [OH_WindowManager_GetWindowProperties](#oh_windowmanager_getwindowproperties) (int32_t windowId, [WindowManager_WindowProperties](_window_manager___window_properties.md) \*windowProperties) | 获取指定窗口属性。 |
| int32_t [OH_WindowManager_Snapshot](#oh_windowmanager_snapshot) (int32_t windowId, OH_PixelmapNative \*pixelMap) | 获取指定窗口截图。 |
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_NativeWindowManager_RegisterKeyEventFilter](#oh_nativewindowmanager_registerkeyeventfilter) (int32_t windowId, [OH_NativeWindowManager_KeyEventFilter](#oh_nativewindowmanager_keyeventfilter) keyEventFilter) | 注册按键事件的过滤函数。 |
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_NativeWindowManager_UnregisterKeyEventFilter](#oh_nativewindowmanager_unregisterkeyeventfilter) (int32_t windowId) | 取消注册窗口的按键事件过滤函数。 |
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_NativeWindowManager_RegisterMouseEventFilter](#oh_nativewindowmanager_registermouseeventfilter) (int32_t windowId, [OH_NativeWindowManager_MouseEventFilter](#oh_nativewindowmanager_mouseeventfilter) mouseEventFilter) | 注册鼠标事件的过滤函数。 |
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_NativeWindowManager_UnregisterMouseEventFilter](#oh_nativewindowmanager_unregistermouseeventfilter) (int32_t windowId) | 取消注册窗口的鼠标事件过滤函数。 |
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_NativeWindowManager_RegisterTouchEventFilter](#oh_nativewindowmanager_registertoucheventfilter) (int32_t windowId, [OH_NativeWindowManager_TouchEventFilter](#oh_nativewindowmanager_toucheventfilter) touchEventFilter) | 注册触摸事件的过滤函数。 |
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_NativeWindowManager_UnregisterTouchEventFilter](#oh_nativewindowmanager_unregistertoucheventfilter) (int32_t windowId) | 取消注册窗口的触摸事件过滤函数。 |


## 类型定义说明


### OH_NativeWindowManager_KeyEventFilter

```
typedef bool(* OH_NativeWindowManager_KeyEventFilter) (Input_KeyEvent *keyEvent)
```

**描述**

定义多模按键的过滤函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| keyEvent | 多模按键事件，具体可见**Input_KeyEvent**，事件定义在oh_input_manager中。 |

**返回：**

返回是否过滤该事件，返回true窗口不再往下分发，返回false表示不拦截


### OH_NativeWindowManager_MouseEventFilter

```
typedef bool(* OH_NativeWindowManager_MouseEventFilter) (Input_MouseEvent *mouseEvent)
```

**描述**

定义多模鼠标事件的过滤函数。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| mouseEvent | 多模鼠标事件，具体可见**Input_MouseEvent**，事件定义在oh_input_manager中。 |

**返回：**

返回是否过滤该事件。true表示过滤该事件，不会继续往下分发；false表示不过滤不拦截此事件，将会继续分发。


### OH_NativeWindowManager_TouchEventFilter

```
typedef bool(* OH_NativeWindowManager_TouchEventFilter) (Input_TouchEvent *touchEvent)
```

**描述**

定义多模触摸事件的过滤函数。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| touchEvent | 多模触摸事件，具体可见**Input_TouchEvent**，事件定义在oh_input_manager中。 |

**返回：**

返回是否过滤该事件。true表示过滤该事件，不会继续往下分发；false表示不过滤不拦截此事件，将会继续分发。


### WindowManager_ErrorCode

```
typedef enum WindowManager_ErrorCode WindowManager_ErrorCode
```

**描述**

窗口管理接口返回状态码枚举。

**起始版本：** 12


## 枚举类型说明


### WindowManager_AvoidAreaType

```
enum WindowManager_AvoidAreaType
```

**描述**

避让区域枚举类型。

**起始版本：** 15

| 枚举值 | 描述 |
| -------- | -------- |
| WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM | 系统避让区域。 |
| WINDOW_MANAGER_AVOID_AREA_TYPE_CUTOUT | 刘海屏避让。 |
| WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM_GESTURE | 系统手势区域。 |
| WINDOW_MANAGER_AVOID_AREA_TYPE_KEYBOARD | 键盘区域。 |
| WINDOW_MANAGER_AVOID_AREA_TYPE_NAVIGATION_INDICATOR | 导航条区域。 |


### WindowManager_ErrorCode

```
enum WindowManager_ErrorCode
```

**描述**

窗口管理接口返回状态码枚举。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| OK | 成功。 |
| WINDOW_MANAGER_ERRORCODE_NO_PERMISSION<sup>15+</sup> | 无权限。 |
| WINDOW_MANAGER_ERRORCODE_INVALID_PARAM<sup>15+</sup> | 非法参数。 |
| WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED<sup>15+</sup> | 设备不支持。 |
| INVAILD_WINDOW_ID | 非法窗口ID。 |
| SERVICE_ERROR | 服务异常。 |
| WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL<sup>15+</sup> | 窗口状态异常。 |
| WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL<sup>15+</sup> | 窗口管理器服务异常。 |


### WindowManager_WindowType

```
enum WindowManager_WindowType
```

**描述**

窗口类型。

**起始版本：** 15

| 枚举值 | 描述 |
| -------- | -------- |
| WINDOW_MANAGER_WINDOW_TYPE_APP | 子窗口。 |
| WINDOW_MANAGER_WINDOW_TYPE_MAIN | 主窗口。 |
| WINDOW_MANAGER_WINDOW_TYPE_FLOAT | 悬浮窗口。 |
| WINDOW_MANAGER_WINDOW_TYPE_DIALOG | 模态窗口。 |


## 函数说明


### OH_NativeWindowManager_RegisterKeyEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_RegisterKeyEventFilter (int32_t windowId, OH_NativeWindowManager_KeyEventFilter keyEventFilter )
```

**描述**

注册按键事件的过滤函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 需要过滤按键事件的窗口ID。 |
| keyEventFilter | 多模按键的过滤函数。 |

**返回：**

返回窗口管理接口的通用状态码，具体可见[WindowManager_ErrorCode](#windowmanager_errorcode)。


### OH_NativeWindowManager_RegisterMouseEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_RegisterMouseEventFilter (int32_t windowId, OH_NativeWindowManager_MouseEventFilter mouseEventFilter )
```

**描述**

注册鼠标事件的过滤函数。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 需要过滤鼠标事件的窗口ID。 |
| mouseEventFilter | 多模鼠标事件的过滤函数。 |

**返回：**

返回窗口管理接口的通用状态码，具体可见[WindowManager_ErrorCode](#windowmanager_errorcode)。


### OH_NativeWindowManager_RegisterTouchEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_RegisterTouchEventFilter (int32_t windowId, OH_NativeWindowManager_TouchEventFilter touchEventFilter )
```

**描述**

注册触摸事件的过滤函数。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 需要过滤触摸事件的窗口ID。 |
| touchEventFilter | 多模触摸事件的过滤函数。 |

**返回：**

返回窗口管理接口的通用状态码，具体可见[WindowManager_ErrorCode](#windowmanager_errorcode)。


### OH_NativeWindowManager_UnregisterKeyEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterKeyEventFilter (int32_t windowId)
```

**描述**

取消注册窗口的按键事件过滤函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 需要取消过滤按键事件的窗口ID。 |

**返回：**

返回窗口管理接口的通用状态码，具体可见[WindowManager_ErrorCode](#windowmanager_errorcode)。


### OH_NativeWindowManager_UnregisterMouseEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterMouseEventFilter (int32_t windowId)
```

**描述**

取消注册窗口的鼠标事件过滤函数。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 需要取消过滤鼠标事件的窗口ID。 |

**返回：**

返回窗口管理接口的通用状态码，具体可见[WindowManager_ErrorCode](#windowmanager_errorcode)。


### OH_NativeWindowManager_UnregisterTouchEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterTouchEventFilter (int32_t windowId)
```

**描述**

取消注册窗口的触摸事件过滤函数。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 需要取消过滤触摸事件的窗口ID。 |

**返回：**

返回窗口管理接口的通用状态码，具体可见[WindowManager_ErrorCode](#windowmanager_errorcode)。


### OH_WindowManager_GetWindowAvoidArea()

```
int32_t OH_WindowManager_GetWindowAvoidArea (int32_t windowId, WindowManager_AvoidAreaType type, WindowManager_AvoidArea * avoidArea )
```

**描述**

获取指定窗口的避让区域。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| type | 避让区域的类型。 |
| avoidArea | 返回指向指定窗口的避让区域的指针，作为出参使用。 |

**返回：**

返回结果代码。

返回OK，表示函数调用成功，返回指向对应窗口id的避让区域的指针。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。

返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。


### OH_WindowManager_GetWindowProperties()

```
int32_t OH_WindowManager_GetWindowProperties (int32_t windowId, WindowManager_WindowProperties * windowProperties )
```

**描述**

获取指定窗口属性。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| windowProperties | 返回指向指定窗口的属性的指针，作为出参使用。 |

**返回：**

返回结果代码。

返回OK，表示函数调用成功，在windowProperties中返回窗口属性的指针。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。

返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。


### OH_WindowManager_IsWindowShown()

```
WindowManager_ErrorCode OH_WindowManager_IsWindowShown (int32_t windowId, bool * isShow )
```

**描述**

判断指定窗口是否显示。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| isShow | 返回指定窗口是否显示的结果。true表示指定窗口显示，false表示指定窗口不显示，作为出参使用。 |

**返回：**

返回结果代码。

返回OK，表示函数调用成功。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。


### OH_WindowManager_SetWindowBackgroundColor()

```
int32_t OH_WindowManager_SetWindowBackgroundColor (int32_t windowId, const char * color )
```

**描述**

设置指定窗口背景颜色。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| color | 设置窗口的背景色。该参数为字符串类型，格式为十六进制RGB或ARGB颜色。 |

**返回：**

返回结果代码。

返回OK，表示函数调用成功。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。


### OH_WindowManager_SetWindowBrightness()

```
int32_t OH_WindowManager_SetWindowBrightness (int32_t windowId, float brightness )
```

**描述**

设置指定窗口的屏幕亮度。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| brightness | 指定的屏幕亮度值。该参数为浮点数，取值范围为[0.0, 1.0]或-1.0。1.0表示最亮，-1.0表示默认亮度。 |

**返回：**

返回结果代码。

返回OK，表示函数调用成功。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。

返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。


### OH_WindowManager_SetWindowFocusable()

```
int32_t OH_WindowManager_SetWindowFocusable (int32_t windowId, bool isFocusable )
```

**描述**

设置指定窗口是否可获焦。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| isFocusable | 窗口是否可获焦。true表示窗口可获焦，false表示窗口不可获焦。 |

**返回：**

返回结果代码。

返回OK，表示函数调用成功。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。

返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。


### OH_WindowManager_SetWindowKeepScreenOn()

```
int32_t OH_WindowManager_SetWindowKeepScreenOn (int32_t windowId, bool isKeepScreenOn )
```

**描述**

设置指定窗口是否开启屏幕常亮。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| isKeepScreenOn | 指定窗口是否开启屏幕常亮。true表示开启屏幕常亮，false表示关闭屏幕常亮。 |

**返回：**

返回结果代码。

返回OK，表示函数调用成功。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。

返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。


### OH_WindowManager_SetWindowNavigationBarEnabled()

```
int32_t OH_WindowManager_SetWindowNavigationBarEnabled (int32_t windowId, bool enabled, bool enableAnimation )
```

**描述**

设置指定窗口是否显示导航栏。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| enabled | 设置导航栏是否显示。true表示设置导航栏显示，false表示设置导航栏隐藏。 |
| enableAnimation | 设置是否开启导航栏的显隐动画。true表示开启导航栏的显隐动画，false表示关闭导航栏的显隐动画。 |

**返回：**

返回结果代码。

返回OK，表示函数调用成功。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持功能。

返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。

返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。


### OH_WindowManager_SetWindowPrivacyMode()

```
int32_t OH_WindowManager_SetWindowPrivacyMode (int32_t windowId, bool isPrivacy )
```

**描述**

设置指定窗口是否开启隐私模式。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| isPrivacy | 指定窗口是否开启隐私模式。true表示开启隐私模式，false表示关闭隐私模式。 |

**需要权限：**ohos.permission.PRIVACY_WINDOW  。

**返回：**

返回结果代码。

返回OK，表示函数调用成功。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PERMISSION，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。

返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。

返回WINDOW_MANAGER_ERRORCODE_NO_PERMISSION，权限校验错误。


### OH_WindowManager_SetWindowStatusBarColor()

```
int32_t OH_WindowManager_SetWindowStatusBarColor (int32_t windowId, int32_t color )
```

**描述**

设置指定窗口的状态栏内容颜色。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| color | 要设置的颜色值，格式为ARGB。 |

**返回：**

返回结果代码。

返回OK，表示函数调用成功。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持功能。

返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。

返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。


### OH_WindowManager_SetWindowStatusBarEnabled()

```
int32_t OH_WindowManager_SetWindowStatusBarEnabled (int32_t windowId, bool enabled, bool enableAnimation )
```

**描述**

设置指定窗口是否显示状态栏。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| enabled | 设置状态栏是否显示。true表示设置状态栏显示，false表示设置状态栏隐藏。 |
| enableAnimation | 设置是否开启状态栏的显隐动画。true表示开启状态栏的显隐动画，false表示关闭状态栏的显隐动画。 |

**返回：**

返回结果代码。

返回OK，表示函数调用成功。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持功能。

返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。

返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。


### OH_WindowManager_SetWindowTouchable()

```
int32_t OH_WindowManager_SetWindowTouchable (int32_t windowId, bool isTouchable )
```

**描述**

设置指定窗口是否可触。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| isTouchable | 窗口是否可触。true表示窗口可触，false表示窗口不可触。 |

**返回：**

返回结果代码。

返回OK，表示函数调用成功。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。

返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。


### OH_WindowManager_ShowWindow()

```
WindowManager_ErrorCode OH_WindowManager_ShowWindow (int32_t windowId)
```

**描述**

显示指定窗口。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |

**返回：**

返回结果代码。

返回OK，表示函数调用成功。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。

返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。


### OH_WindowManager_Snapshot()

```
int32_t OH_WindowManager_Snapshot (int32_t windowId, OH_PixelmapNative * pixelMap )
```

**描述**

获取指定窗口截图。

**起始版本：** 15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。窗口id非法或者窗口已经销毁，不能获取指定窗口截图，需要传入有效的窗口id才能成功获取指定窗口截图。请通过窗口对象调用getWindowProperties接口（ArkTS接口）获取有效的窗口id。 |
| pixelMap | 返回指向指定窗口的截图的指针，作为出参使用。 |

**返回：**

返回结果代码。

返回OK，表示函数调用成功，在返回pixelMap中的像素图的指针。

返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。

返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。
