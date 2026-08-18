# oh_window_event_filter.h
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## 概述

定义窗口管理事件过滤的接口。当多模输入的事件经过窗口时，可通过过滤接口拦截事件，阻止事件向下分发。

**引用文件：** <window_manager/oh_window_event_filter.h>

**库：** libnative_window_manager.so

**系统能力：** SystemCapability.Window.SessionManager

**起始版本：** 12

**相关模块：** [WindowManager](capi-windowmanager.md)

## 汇总

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef bool (\*OH_NativeWindowManager_KeyEventFilter)(Input_KeyEvent* keyEvent)](#oh_nativewindowmanager_keyeventfilter) | OH_NativeWindowManager_KeyEventFilter | 定义多模按键的过滤函数。 |
| [WindowManager_ErrorCode OH_NativeWindowManager_RegisterKeyEventFilter(int32_t windowId,OH_NativeWindowManager_KeyEventFilter keyEventFilter)](#oh_nativewindowmanager_registerkeyeventfilter) | - | 注册按键事件的过滤函数。 |
| [WindowManager_ErrorCode OH_NativeWindowManager_UnregisterKeyEventFilter(int32_t windowId)](#oh_nativewindowmanager_unregisterkeyeventfilter) | - | 取消注册窗口的按键事件过滤函数。 |
| [typedef bool (\*OH_NativeWindowManager_MouseEventFilter)(Input_MouseEvent* mouseEvent)](#oh_nativewindowmanager_mouseeventfilter) | OH_NativeWindowManager_MouseEventFilter | 定义多模鼠标事件的过滤函数。 |
| [WindowManager_ErrorCode OH_NativeWindowManager_RegisterMouseEventFilter(int32_t windowId,OH_NativeWindowManager_MouseEventFilter mouseEventFilter)](#oh_nativewindowmanager_registermouseeventfilter) | - | 注册鼠标事件的过滤函数。 |
| [WindowManager_ErrorCode OH_NativeWindowManager_UnregisterMouseEventFilter(int32_t windowId)](#oh_nativewindowmanager_unregistermouseeventfilter) | - | 取消注册窗口的鼠标事件过滤函数。 |
| [typedef bool (\*OH_NativeWindowManager_TouchEventFilter)(Input_TouchEvent* touchEvent)](#oh_nativewindowmanager_toucheventfilter) | OH_NativeWindowManager_TouchEventFilter | 定义多模触摸事件的过滤函数。 |
| [WindowManager_ErrorCode OH_NativeWindowManager_RegisterTouchEventFilter(int32_t windowId,OH_NativeWindowManager_TouchEventFilter touchEventFilter)](#oh_nativewindowmanager_registertoucheventfilter) | - | 注册触摸事件的过滤函数。 |
| [WindowManager_ErrorCode OH_NativeWindowManager_UnregisterTouchEventFilter(int32_t windowId)](#oh_nativewindowmanager_unregistertoucheventfilter) | - | 取消注册窗口的触摸事件过滤函数。 |
| [WindowManager_ErrorCode OH_NativeWindowManager_GetKeyEventFilter(int32_t windowId, OH_NativeWindowManager_KeyEventFilter* outKeyEventFilter)](#oh_nativewindowmanager_getkeyeventfilter) | - | 获取指定窗口注册的多模按键事件过滤函数。 |
| [WindowManager_ErrorCode OH_NativeWindowManager_GetMouseEventFilter(int32_t windowId, OH_NativeWindowManager_MouseEventFilter* outMouseEventFilter)](#oh_nativewindowmanager_getmouseeventfilter) | - | 获取指定窗口注册的多模鼠标事件过滤函数。 |
| [WindowManager_ErrorCode OH_NativeWindowManager_GetTouchEventFilter(int32_t windowId, OH_NativeWindowManager_TouchEventFilter* outTouchEventFilter)](#oh_nativewindowmanager_gettoucheventfilter) | - | 获取指定窗口注册的多模触摸事件过滤函数。 |

## 函数说明

### OH_NativeWindowManager_KeyEventFilter()

```c
typedef bool (*OH_NativeWindowManager_KeyEventFilter)(Input_KeyEvent* keyEvent)
```

**描述**

定义多模按键的过滤函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_KeyEvent](../apis-input-kit/capi-input-input-keyevent.md)* keyEvent | 多模按键事件，具体可见[Input_KeyEvent](../apis-input-kit/capi-input-input-keyevent.md)，事件定义在oh_input_manager中。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回是否过滤该事件。返回true窗口不再往下分发，返回false表示不拦截。 |

### OH_NativeWindowManager_RegisterKeyEventFilter()

```c
WindowManager_ErrorCode OH_NativeWindowManager_RegisterKeyEventFilter(int32_t windowId,OH_NativeWindowManager_KeyEventFilter keyEventFilter)
```

**描述**

注册按键事件的过滤函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 需要过滤按键事件的窗口ID。 |
| [OH_NativeWindowManager_KeyEventFilter](#oh_nativewindowmanager_keyeventfilter) keyEventFilter | 多模按键的过滤函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | 函数返回的执行结果。<br> 返回OK，表示接口调用成功。<br> 返回INVALID_WINDOW_ID，表示参数windowId无效。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数keyEventFilter无效。<br> 返回SERVICE_ERROR，表示窗口管理服务异常。|

### OH_NativeWindowManager_UnregisterKeyEventFilter()

```c
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterKeyEventFilter(int32_t windowId)
```

**描述**

取消注册窗口的按键事件过滤函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 需要取消过滤按键事件的窗口ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | 函数返回的执行结果。<br> 返回OK，表示接口调用成功。<br> 返回INVALID_WINDOW_ID，表示参数windowId无效。<br> 返回SERVICE_ERROR，表示窗口管理服务异常。 |

### OH_NativeWindowManager_MouseEventFilter()

```c
typedef bool (*OH_NativeWindowManager_MouseEventFilter)(Input_MouseEvent* mouseEvent)
```

**描述**

定义多模鼠标事件的过滤函数。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_MouseEvent](../apis-input-kit/capi-input-input-mouseevent.md)* mouseEvent | 多模鼠标事件，具体可见[Input_MouseEvent](../apis-input-kit/capi-input-input-mouseevent.md)，事件定义在oh_input_manager中。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回是否过滤该事件。true表示过滤该事件，不会继续往下分发；false表示不过滤不拦截此事件，将会继续分发。 |

### OH_NativeWindowManager_RegisterMouseEventFilter()

```c
WindowManager_ErrorCode OH_NativeWindowManager_RegisterMouseEventFilter(int32_t windowId,OH_NativeWindowManager_MouseEventFilter mouseEventFilter)
```

**描述**

注册鼠标事件的过滤函数。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 需要过滤鼠标事件的窗口ID。 |
| [OH_NativeWindowManager_MouseEventFilter](#oh_nativewindowmanager_mouseeventfilter) mouseEventFilter | 多模鼠标事件的过滤函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | 函数返回的执行结果。<br> 返回OK，表示接口调用成功。<br> 返回INVALID_WINDOW_ID，表示参数windowId无效。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数mouseEventFilter无效。<br> 返回SERVICE_ERROR，表示窗口管理服务异常。 |

### OH_NativeWindowManager_UnregisterMouseEventFilter()

```c
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterMouseEventFilter(int32_t windowId)
```

**描述**

取消注册窗口的鼠标事件过滤函数。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 需要取消过滤鼠标事件的窗口ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | 函数返回的执行结果。<br> 返回OK，表示接口调用成功。<br> 返回INVALID_WINDOW_ID，表示参数windowId无效。<br> 返回SERVICE_ERROR，表示窗口管理服务异常。 |

### OH_NativeWindowManager_TouchEventFilter()

```c
typedef bool (*OH_NativeWindowManager_TouchEventFilter)(Input_TouchEvent* touchEvent)
```

**描述**

定义多模触摸事件的过滤函数。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_TouchEvent](../apis-input-kit/capi-input-input-touchevent.md)* touchEvent | 多模触摸事件，具体可见[Input_TouchEvent](../apis-input-kit/capi-input-input-touchevent.md)，事件定义在oh_input_manager中。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回是否过滤该事件。true表示过滤该事件，不会继续往下分发；false表示不过滤不拦截此事件，将会继续分发。 |

### OH_NativeWindowManager_RegisterTouchEventFilter()

```c
WindowManager_ErrorCode OH_NativeWindowManager_RegisterTouchEventFilter(int32_t windowId,OH_NativeWindowManager_TouchEventFilter touchEventFilter)
```

**描述**

注册触摸事件的过滤函数。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 需要过滤触摸事件的窗口ID。 |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | 函数返回的执行结果。<br> 返回OK，表示接口调用成功。<br> 返回INVALID_WINDOW_ID，表示参数windowId无效。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数touchEventFilter无效。<br> 返回SERVICE_ERROR，表示窗口管理服务异常。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | 返回窗口管理接口的通用状态码，具体可见[WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode)。 |

### OH_NativeWindowManager_UnregisterTouchEventFilter()

```c
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterTouchEventFilter(int32_t windowId)
```

**描述**

取消注册窗口的触摸事件过滤函数。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 需要取消过滤触摸事件的窗口ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | 函数返回的执行结果。<br> 返回OK，表示接口调用成功。<br> 返回INVALID_WINDOW_ID，表示参数windowId无效。<br> 返回SERVICE_ERROR，表示窗口管理服务异常。|

### OH_NativeWindowManager_GetKeyEventFilter()

```c
WindowManager_ErrorCode OH_NativeWindowManager_GetKeyEventFilter(int32_t windowId, OH_NativeWindowManager_KeyEventFilter* outKeyEventFilter)
```

**描述**

获取指定窗口注册的多模按键事件过滤函数。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 窗口ID。 |
| [OH_NativeWindowManager_KeyEventFilter](capi-oh-window-event-filter-h.md#oh_nativewindowmanager_keyeventfilter)* outKeyEventFilter | 返回已注册的多模按键事件过滤函数指针。如果窗口没有注册过滤器，*outKeyEventFilter将返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | 函数返回的执行结果。<br>返回OK，表示接口调用成功。<br>返回INVALID_WINDOW_ID，表示入参windowId无效。<br>返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示入参outKeyEventFilter为NULL。 |

### OH_NativeWindowManager_GetMouseEventFilter()

```c
WindowManager_ErrorCode OH_NativeWindowManager_GetMouseEventFilter(int32_t windowId, OH_NativeWindowManager_MouseEventFilter* outMouseEventFilter)
```

**描述**

获取指定窗口注册的多模鼠标事件过滤函数。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 窗口ID。 |
| [OH_NativeWindowManager_MouseEventFilter](capi-oh-window-event-filter-h.md#oh_nativewindowmanager_mouseeventfilter)* outMouseEventFilter | 返回已注册的多模鼠标事件过滤函数指针。如果窗口没有注册过滤器，*outMouseEventFilter将返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | 函数返回的执行结果。<br>返回OK，表示接口调用成功。<br>返回INVALID_WINDOW_ID，表示入参windowId无效。<br>返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示入参outMouseEventFilter为NULL。 |

### OH_NativeWindowManager_GetTouchEventFilter()

```c
WindowManager_ErrorCode OH_NativeWindowManager_GetTouchEventFilter(int32_t windowId, OH_NativeWindowManager_TouchEventFilter* outTouchEventFilter)
```

**描述**

获取指定窗口注册的多模触摸事件过滤函数。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 窗口ID。 |
| [OH_NativeWindowManager_TouchEventFilter](capi-oh-window-event-filter-h.md#oh_nativewindowmanager_toucheventfilter)* outTouchEventFilter | 返回已注册的多模触摸事件过滤函数指针。如果窗口没有注册过滤器，*outTouchEventFilter将返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | 函数返回的执行结果。<br>返回OK，表示接口调用成功。<br>返回INVALID_WINDOW_ID，表示入参windowId无效。<br>返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示入参outTouchEventFilter为NULL。 |