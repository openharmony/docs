# oh_window.h

## 概述

定义窗口管理的相关接口，主要用于设置和获取指定窗口的属性，以及设置指定窗口的状态栏样式、导航栏样式。

**引用文件：** <window_manager/oh_window.h>

**库：** libnative_window_manager.so

**系统能力：** SystemCapability.Window.SessionManager

**起始版本：** 15

**相关模块：** [WindowManager](capi-windowmanager.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_WindowManager_SetWindowStatusBarEnabled(int32_t windowId, bool enabled, bool enableAnimation)](#oh_windowmanager_setwindowstatusbarenabled) | 设置指定窗口是否显示状态栏。 |
| [int32_t OH_WindowManager_SetWindowStatusBarColor(int32_t windowId, int32_t color)](#oh_windowmanager_setwindowstatusbarcolor) | 设置指定窗口的状态栏内容颜色。 |
| [int32_t OH_WindowManager_SetWindowNavigationBarEnabled(int32_t windowId, bool enabled, bool enableAnimation)](#oh_windowmanager_setwindownavigationbarenabled) | 设置指定窗口是否显示导航栏。 |
| [int32_t OH_WindowManager_GetWindowAvoidArea(int32_t windowId, WindowManager_AvoidAreaType type, WindowManager_AvoidArea* avoidArea)](#oh_windowmanager_getwindowavoidarea) | 获取指定窗口的避让区域。 |
| [WindowManager_ErrorCode OH_WindowManager_IsWindowShown(int32_t windowId, bool* isShow)](#oh_windowmanager_iswindowshown) | 判断指定窗口是否显示。 |
| [WindowManager_ErrorCode OH_WindowManager_ShowWindow(int32_t windowId)](#oh_windowmanager_showwindow) | 显示指定窗口。 |
| [int32_t OH_WindowManager_SetWindowTouchable(int32_t windowId, bool isTouchable)](#oh_windowmanager_setwindowtouchable) | 设置指定窗口是否可触。 |
| [int32_t OH_WindowManager_SetWindowFocusable(int32_t windowId, bool isFocusable)](#oh_windowmanager_setwindowfocusable) | 设置指定窗口是否可获焦。 |
| [int32_t OH_WindowManager_SetWindowBackgroundColor(int32_t windowId, const char* color)](#oh_windowmanager_setwindowbackgroundcolor) | 设置指定窗口背景颜色。 |
| [int32_t OH_WindowManager_SetWindowBrightness(int32_t windowId, float brightness)](#oh_windowmanager_setwindowbrightness) | 设置指定窗口的屏幕亮度。 |
| [int32_t OH_WindowManager_SetWindowKeepScreenOn(int32_t windowId, bool isKeepScreenOn)](#oh_windowmanager_setwindowkeepscreenon) | 设置指定窗口是否开启屏幕常亮。 |
| [int32_t OH_WindowManager_SetWindowPrivacyMode(int32_t windowId, bool isPrivacy)](#oh_windowmanager_setwindowprivacymode) | 设置指定窗口是否开启隐私模式。 |
| [int32_t OH_WindowManager_GetWindowProperties(int32_t windowId, WindowManager_WindowProperties* windowProperties)](#oh_windowmanager_getwindowproperties) | 获取指定窗口属性。 |
| [int32_t OH_WindowManager_Snapshot(int32_t windowId, OH_PixelmapNative* pixelMap)](#oh_windowmanager_snapshot) | 获取指定窗口截图。 |
| [int32_t OH_WindowManager_GetAllWindowLayoutInfoList(int64_t displayId,WindowManager_Rect** windowLayoutInfoList, size_t* windowLayoutInfoSize)](#oh_windowmanager_getallwindowlayoutinfolist) | 获取指定屏幕上可见的窗口布局信息数组，按当前窗口层级排列，层级最高的对应数组下标为0。 |
| [void OH_WindowManager_ReleaseAllWindowLayoutInfoList(WindowManager_Rect* windowLayoutInfoList)](#oh_windowmanager_releaseallwindowlayoutinfolist) | 释放窗口布局信息数组占用的内存。 |
| [int32_t OH_WindowManager_InjectTouchEvent(int32_t windowId, Input_TouchEvent* touchEvent, int32_t windowX, int32_t windowY)](#oh_windowmanager_injecttouchevent) | 将多模触摸事件注入给目标窗口，仅支持注入同进程窗口，且该注入不会触发窗口焦点和层级变化，不会触发窗口拖拽，事件会直接发送给ArkUI。该接口需要在指定窗口加载UI之后调用。 |

## 函数说明

### OH_WindowManager_SetWindowStatusBarEnabled()

```
int32_t OH_WindowManager_SetWindowStatusBarEnabled(int32_t windowId, bool enabled, bool enableAnimation)
```

**描述**

设置指定窗口是否显示状态栏。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| bool enabled | 设置状态栏是否显示。true表示设置状态栏显示，false表示设置状态栏隐藏。 |
| bool enableAnimation | 设置是否开启状态栏的显隐动画。true表示开启状态栏的显隐动画，false表示关闭状态栏的显隐动画。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持功能。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_SetWindowStatusBarColor()

```
int32_t OH_WindowManager_SetWindowStatusBarColor(int32_t windowId, int32_t color)
```

**描述**

设置指定窗口的状态栏内容颜色。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| int32_t color | 要设置的颜色值，格式为ARGB。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持功能。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_SetWindowNavigationBarEnabled()

```
int32_t OH_WindowManager_SetWindowNavigationBarEnabled(int32_t windowId, bool enabled, bool enableAnimation)
```

**描述**

设置指定窗口是否显示导航栏。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| bool enabled | 设置导航栏是否显示。true表示设置导航栏显示，false表示设置导航栏隐藏。 |
| bool enableAnimation | 设置是否开启导航栏的显隐动画。true表示开启导航栏的显隐动画，false表示关闭导航栏的显隐动画。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持功能。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_GetWindowAvoidArea()

```
int32_t OH_WindowManager_GetWindowAvoidArea(int32_t windowId, WindowManager_AvoidAreaType type, WindowManager_AvoidArea* avoidArea)
```

**描述**

获取指定窗口的避让区域。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| [WindowManager_AvoidAreaType](capi-oh-window-comm-h.md#windowmanager_avoidareatype) type | 避让区域的类型。 |
| [WindowManager_AvoidArea](capi-windowmanager-avoidarea.md)* avoidArea | 返回指向指定窗口的避让区域的指针，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功，返回指向对应窗口id的避让区域的指针。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_IsWindowShown()

```
WindowManager_ErrorCode OH_WindowManager_IsWindowShown(int32_t windowId, bool* isShow)
```

**描述**

判断指定窗口是否显示。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| bool* isShow | 返回指定窗口是否显示的结果。true表示指定窗口显示，false表示指定窗口不显示，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。 |

### OH_WindowManager_ShowWindow()

```
WindowManager_ErrorCode OH_WindowManager_ShowWindow(int32_t windowId)
```

**描述**

显示指定窗口。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_SetWindowTouchable()

```
int32_t OH_WindowManager_SetWindowTouchable(int32_t windowId, bool isTouchable)
```

**描述**

设置指定窗口是否可触。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| bool isTouchable | 窗口是否可触。true表示窗口可触，false表示窗口不可触。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_SetWindowFocusable()

```
int32_t OH_WindowManager_SetWindowFocusable(int32_t windowId, bool isFocusable)
```

**描述**

设置指定窗口是否可获焦。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| bool isFocusable | 窗口是否可获焦。true表示窗口可获焦，false表示窗口不可获焦。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_SetWindowBackgroundColor()

```
int32_t OH_WindowManager_SetWindowBackgroundColor(int32_t windowId, const char* color)
```

**描述**

设置指定窗口背景颜色。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| const char* color | 设置窗口的背景色。该参数为字符串类型，格式为十六进制RGB或ARGB颜色。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。 |

### OH_WindowManager_SetWindowBrightness()

```
int32_t OH_WindowManager_SetWindowBrightness(int32_t windowId, float brightness)
```

**描述**

设置指定窗口的屏幕亮度。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| float brightness | 指定的屏幕亮度值。该参数为浮点数，取值范围为[0.0, 1.0]或-1.0。1.0表示最亮，-1.0表示默认亮度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_SetWindowKeepScreenOn()

```
int32_t OH_WindowManager_SetWindowKeepScreenOn(int32_t windowId, bool isKeepScreenOn)
```

**描述**

设置指定窗口是否开启屏幕常亮。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| bool isKeepScreenOn | 指定窗口是否开启屏幕常亮。true表示开启屏幕常亮，false表示关闭屏幕常亮。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_SetWindowPrivacyMode()

```
int32_t OH_WindowManager_SetWindowPrivacyMode(int32_t windowId, bool isPrivacy)
```

**描述**

设置指定窗口是否开启隐私模式。

**需要权限：** {@code ohos.permission.PRIVACY_WINDOW}。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| bool isPrivacy | 指定窗口是否开启隐私模式。true表示开启隐私模式，false表示关闭隐私模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PERMISSION，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。<br> 返回WINDOW_MANAGER_ERRORCODE_NO_PERMISSION，权限校验错误。 |

### OH_WindowManager_GetWindowProperties()

```
int32_t OH_WindowManager_GetWindowProperties(int32_t windowId, WindowManager_WindowProperties* windowProperties)
```

**描述**

获取指定窗口属性。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| [WindowManager_WindowProperties](capi-windowmanager-windowproperties.md)* windowProperties | 返回指向指定窗口的属性的指针，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功，在windowProperties中返回窗口属性的指针。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_Snapshot()

```
int32_t OH_WindowManager_Snapshot(int32_t windowId, OH_PixelmapNative* pixelMap)
```

**描述**

获取指定窗口截图。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。<br>窗口id非法或者窗口已经销毁，不能获取指定窗口截图，需要传入有效的窗口id才能成功获取指定窗口截图。<br>请通过窗口对象调用getWindowProperties接口（ArkTS接口）获取有效的窗口id。 |
| [OH_PixelmapNative](capi-struct.md)* pixelMap | 返回指向指定窗口的截图的指针，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功，在返回pixelMap中的像素图的指针。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。 |

### OH_WindowManager_GetAllWindowLayoutInfoList()

```
int32_t OH_WindowManager_GetAllWindowLayoutInfoList(int64_t displayId,WindowManager_Rect** windowLayoutInfoList, size_t* windowLayoutInfoSize)
```

**描述**

获取指定屏幕上可见的窗口布局信息数组，按当前窗口层级排列，层级最高的对应数组下标为0。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int64_t displayId | 指定屏幕的id。请通过窗口对象调用getWindowProperties接口（ArkTS接口）获取有效的屏幕id。 |
| [WindowManager_Rect](capi-windowmanager-rect.md)** windowLayoutInfoList | 指定屏幕上可见的窗口布局信息数组的数组指针，作为出参使用。 |
| size_t* windowLayoutInfoSize | 指定屏幕上可见的窗口布局信息数组长度的指针，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功，返回指定屏幕上可见的窗口布局信息数组的数组指针和数组长度的指针。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持功能。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_ReleaseAllWindowLayoutInfoList()

```
void OH_WindowManager_ReleaseAllWindowLayoutInfoList(WindowManager_Rect* windowLayoutInfoList)
```

**描述**

释放窗口布局信息数组占用的内存。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [WindowManager_Rect](capi-windowmanager-rect.md)* windowLayoutInfoList | 指定屏幕上可见的窗口布局信息数组的数组指针，可通过[OH_WindowManager_GetAllWindowLayoutInfoList](capi-oh-window-h.md#oh_windowmanager_getallwindowlayoutinfolist)接口获取。 |
### OH_WindowManager_InjectTouchEvent()

```
int32_t OH_WindowManager_InjectTouchEvent(int32_t windowId, Input_TouchEvent* touchEvent, int32_t windowX, int32_t windowY)
```

**描述**

将多模触摸事件注入给目标窗口，仅支持注入同进程窗口，且该注入不会触发窗口焦点和层级变化，不会触发窗口拖拽，事件会直接发送给ArkUI。该接口需要在指定窗口加载UI之后调用。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| [Input_TouchEvent](../apis-input-kit/capi-input-input-touchevent.md)* touchEvent | 多模触摸事件，具体可见[Input_TouchEvent](../apis-input-kit/capi-input-input-touchevent.md)，事件定义在oh_input_manager.h中。该参数包含的部分字段有参数限制，其中，action应为大于等于0且小于等于3的整数；id、displayX、displayY和actionTime应为不小于0的整数。以上参数不符合限制条件会返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示：窗口管理器服务异常。 |
| int32_t windowX | 注入事件相对于注入窗口的落点横坐标。该参数为整数。 |
| int32_t windowY | 注入事件相对于注入窗口的落点纵坐标。该参数为整数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>返回OK，表示函数调用成功。<br>返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br>返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |