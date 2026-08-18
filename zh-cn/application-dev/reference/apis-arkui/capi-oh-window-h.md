# oh_window.h
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## 概述

定义窗口管理的相关接口，主要用于设置和获取指定窗口的属性，以及设置指定窗口的状态栏样式、导航栏样式。

**引用文件：** <window_manager/oh_window.h>

**库：** libnative_window_manager.so

**系统能力：** SystemCapability.Window.SessionManager

**起始版本：** 15

**相关模块：** [WindowManager](capi-windowmanager.md)

## 汇总

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [int32_t OH_WindowManager_SetWindowStatusBarEnabled(int32_t windowId, bool enabled, bool enableAnimation)](#oh_windowmanager_setwindowstatusbarenabled) | - | 设置主窗口是否显示状态栏。 |
| [int32_t OH_WindowManager_SetWindowStatusBarColor(int32_t windowId, int32_t color)](#oh_windowmanager_setwindowstatusbarcolor) | - | 设置主窗口的状态栏内容颜色。 |
| [int32_t OH_WindowManager_SetWindowNavigationBarEnabled(int32_t windowId, bool enabled, bool enableAnimation)](#oh_windowmanager_setwindownavigationbarenabled) | - | 设置主窗口是否显示导航栏。 |
| [int32_t OH_WindowManager_GetWindowAvoidArea(int32_t windowId, WindowManager_AvoidAreaType type, WindowManager_AvoidArea* avoidArea)](#oh_windowmanager_getwindowavoidarea) | - | 获取指定窗口的避让区域。 |
| [int32_t OH_WindowManager_IsWindowShown(int32_t windowId, bool* isShow)](#oh_windowmanager_iswindowshown) | - | 判断指定窗口是否显示。 |
| [int32_t OH_WindowManager_ShowWindow(int32_t windowId)](#oh_windowmanager_showwindow) | - | 显示指定窗口。 |
| [int32_t OH_WindowManager_SetWindowTouchable(int32_t windowId, bool isTouchable)](#oh_windowmanager_setwindowtouchable) | - | 设置指定窗口是否可触。 |
| [int32_t OH_WindowManager_SetWindowFocusable(int32_t windowId, bool isFocusable)](#oh_windowmanager_setwindowfocusable) | - | 设置指定窗口是否可获焦。 |
| [int32_t OH_WindowManager_SetWindowBackgroundColor(int32_t windowId, const char* color)](#oh_windowmanager_setwindowbackgroundcolor) | - | 设置指定窗口背景颜色。 |
| [int32_t OH_WindowManager_SetWindowBrightness(int32_t windowId, float brightness)](#oh_windowmanager_setwindowbrightness) | - | 设置指定窗口的屏幕亮度。 |
| [int32_t OH_WindowManager_SetWindowKeepScreenOn(int32_t windowId, bool isKeepScreenOn)](#oh_windowmanager_setwindowkeepscreenon) | - | 设置指定窗口是否开启屏幕常亮。 |
| [int32_t OH_WindowManager_SetWindowPrivacyMode(int32_t windowId, bool isPrivacy)](#oh_windowmanager_setwindowprivacymode) | - | 设置指定窗口是否开启隐私模式。 |
| [int32_t OH_WindowManager_GetWindowProperties(int32_t windowId, WindowManager_WindowProperties* windowProperties)](#oh_windowmanager_getwindowproperties) | - | 获取指定窗口属性。 |
| [int32_t OH_WindowManager_Snapshot(int32_t windowId, OH_PixelmapNative* pixelMap)](#oh_windowmanager_snapshot) | - | 获取指定窗口截图。 |
| [int32_t OH_WindowManager_GetAllWindowLayoutInfoList(int64_t displayId,WindowManager_Rect** windowLayoutInfoList, size_t* windowLayoutInfoSize)](#oh_windowmanager_getallwindowlayoutinfolist) | - | 获取指定屏幕上可见的窗口布局信息数组，按当前窗口层级排列，层级最高的对应数组下标为0。 |
| [void OH_WindowManager_ReleaseAllWindowLayoutInfoList(WindowManager_Rect* windowLayoutInfoList)](#oh_windowmanager_releaseallwindowlayoutinfolist) | - | 释放窗口布局信息数组占用的内存。 |
| [int32_t OH_WindowManager_InjectTouchEvent(int32_t windowId, Input_TouchEvent* touchEvent, int32_t windowX, int32_t windowY)](#oh_windowmanager_injecttouchevent) | - | 将多模触摸事件注入给目标窗口，仅支持注入同进程窗口，且该注入不会触发窗口焦点和层级变化，不会触发窗口拖拽，事件会直接发送给ArkUI。该接口需要在指定窗口加载UI之后调用。 |
| [int32_t OH_WindowManager_GetAllMainWindowInfo(WindowManager_MainWindowInfo** infoList, size_t* mainWindowInfoSize)](#oh_windowmanager_getallmainwindowinfo) | - | 获取全部主窗口信息。 |
| [void OH_WindowManager_ReleaseAllMainWindowInfo(WindowManager_MainWindowInfo* infoList)](#oh_windowmanager_releaseallmainwindowinfo) | - | 释放主窗口信息列表的内存。 |
| [typedef void (\*OH_WindowManager_WindowSnapshotCallback)(const OH_PixelmapNative** snapshotPixelMapList, size_t snapshotListSize)](#oh_windowmanager_windowsnapshotcallback) | OH_WindowManager_WindowSnapshotCallback | 接收主窗口截图列表的回调接口。 |
| [int32_t OH_WindowManager_GetMainWindowSnapshot(int32_t* windowIdList, size_t windowIdListSize, WindowManager_WindowSnapshotConfig config, OH_WindowManager_WindowSnapshotCallback callback)](#oh_windowmanager_getmainwindowsnapshot) | - | 获取一个或多个指定windowId的主窗口截图。 |
| [void OH_WindowManager_ReleaseMainWindowSnapshot(const OH_PixelmapNative* snapshotPixelMapList)](#oh_windowmanager_releasemainwindowsnapshot) | - | 释放主窗口截图列表的内存。 |
| [int32_t OH_WindowManager_LockCursor(int32_t windowId, bool isCursorFollowMovement)](#oh_windowmanager_lockcursor) | - | 锁定鼠标光标，控制鼠标光标不超过指定窗口区域，同时可控制光标是否跟随鼠标移动。仅支持获焦窗口调用，失焦之后会自动取消锁定。 |
| [int32_t OH_WindowManager_UnlockCursor(int32_t windowId)](#oh_windowmanager_unlockcursor) | - | 清除窗口设置的鼠标光标指定的模式。 |
| [int32_t OH_WindowManager_FrameMetrics_IsFirstDrawFrame(const OH_WindowManager_FrameMetrics* metrics, bool* isFirstDrawFrame)](#oh_windowmanager_framemetrics_isfirstdrawframe) | - | 判断当前帧是否为首帧。 |
| [int32_t OH_WindowManager_FrameMetrics_GetInputHandlingDuration(const OH_WindowManager_FrameMetrics* metrics, uint64_t* duration)](#oh_windowmanager_framemetrics_getinputhandlingduration) | - | 获取当前帧中手势处理的耗时。 |
| [int32_t OH_WindowManager_FrameMetrics_GetLayoutMeasureDuration(const OH_WindowManager_FrameMetrics* metrics, uint64_t* duration)](#oh_windowmanager_framemetrics_getlayoutmeasureduration) | - | 获取当前帧中布局测量的耗时。 |
| [int32_t OH_WindowManager_FrameMetrics_GetVsyncTimestamp(const OH_WindowManager_FrameMetrics* metrics, uint64_t* timestamp)](#oh_windowmanager_framemetrics_getvsynctimestamp) | - | 获取当前帧开始的时间戳。 |
| [int32_t OH_WindowManager_RegisterFrameMetricsMeasuredCallback(int32_t windowId, OH_WindowManager_FrameMetricsMeasuredCallback callback)](#oh_windowmanager_registerframemetricsmeasuredcallback) | - | 订阅窗口帧率指标变更监听事件。 <br> 该接口依赖窗口页面内容加载，即需要在ArkTS侧loadContent()接口或setUIContent()接口生效后调用。 <br> 应用注册帧率指标变更监听后，仅当客户端UI内容发生重绘（例如页面切换、响应式组件交互、设置背景色和透明度等）时才会触发已注册回调。 <br> 如需取消订阅，请使用[OH_WindowManager_UnregisterFrameMetricsMeasuredCallback](#oh_windowmanager_unregisterframemetricsmeasuredcallback)接口。 |
| [int32_t OH_WindowManager_UnregisterFrameMetricsMeasuredCallback(int32_t windowId, OH_WindowManager_FrameMetricsMeasuredCallback callback)](#oh_windowmanager_unregisterframemetricsmeasuredcallback) | - | 取消订阅窗口帧率指标变更监听事件。 <br> 该接口依赖窗口页面内容加载，即需要在ArkTS侧loadContent()接口或setUIContent()接口生效后调用。 <br> 如需订阅，请使用[OH_WindowManager_RegisterFrameMetricsMeasuredCallback](#oh_windowmanager_registerframemetricsmeasuredcallback)接口。 |
| [int32_t OH_WindowManager_DensityInfo_GetDefaultDensity(const OH_WindowManager_DensityInfo* info, float* density)](#oh_windowmanager_densityinfo_getdefaultdensity) | - | 获取窗口所在屏幕的系统默认显示大小缩放系数。 |
| [int32_t OH_WindowManager_DensityInfo_GetSystemDensity(const OH_WindowManager_DensityInfo* info, float* density)](#oh_windowmanager_densityinfo_getsystemdensity) | - | 获取窗口所在屏幕的系统显示大小缩放系数。 |
| [int32_t OH_WindowManager_DensityInfo_GetCustomDensity(const OH_WindowManager_DensityInfo* info, float* density)](#oh_windowmanager_densityinfo_getcustomdensity) | - | 获取窗口的自定义显示大小缩放系数。 |
| [int32_t OH_WindowManager_GetDensityInfoCopy(int32_t windowId, const OH_WindowManager_DensityInfo** info)](#oh_windowmanager_getdensityinfocopy) | - | 获取窗口缩放系数相关信息，包括系统显示大小缩放系数、系统默认显示大小缩放系数、自定义显示大小缩放系数。优先级由高到低分别为：  <br> 自定义显示大小缩放系数： 窗口级显示缩放值，仅影响单个窗口。  <br> 系统显示大小缩放系数：当前系统配置的显示大小缩放系数。  <br> 系统默认显示大小缩放系数：系统默认的基准缩放值。  <br> |
| [int32_t OH_WindowManager_RegisterDensityInfoChangeCallback(int32_t windowId, OH_WindowManager_DensityInfoCallback callback)](#oh_windowmanager_registerdensityinfochangecallback) | - | 监听窗口缩放系数相关信息的变化。  <br> 当窗口所在屏幕的系统显示大小缩放系数、系统默认显示大小的缩放系数或自定义显示大小的缩放系数任一项发生变化时，会触发该回调函数。  <br> 如需取消监听窗口缩放系数相关信息的变化，请调用[OH_WindowManager_UnregisterDensityInfoChangeCallback](#oh_windowmanager_unregisterdensityinfochangecallback)。 |
| [int32_t OH_WindowManager_UnregisterDensityInfoChangeCallback(int32_t windowId, OH_WindowManager_DensityInfoCallback callback)](#oh_windowmanager_unregisterdensityinfochangecallback) | - | 取消监听窗口缩放系数相关信息的变化。 <br> 当窗口所在屏幕的系统显示大小缩放系数、系统默认显示大小缩放系数或自定义显示大小的缩放系数任一项发生变化时，不会触发已取消注册的回调函数。  <br> |
| [int32_t OH_WindowManager_DensityInfo_Release(const OH_WindowManager_DensityInfo* info)](#oh_windowmanager_densityinfo_release) | - | 释放窗口缩放系数相关信息对象占用的内存。 |

## 函数说明

### OH_WindowManager_SetWindowStatusBarEnabled()

```c
int32_t OH_WindowManager_SetWindowStatusBarEnabled(int32_t windowId, bool enabled, bool enableAnimation)
```

**描述**

设置主窗口是否显示状态栏。

调用生效后返回并不表示状态栏的显示或隐藏已完成。主窗口在非全屏/最大化模式（智慧多窗悬浮窗、分屏等场景）下配置不生效，进入全屏/最大化模式后配置生效。

**起始版本：** 15

**设备行为差异：**

该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不生效也不报错；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 主窗口id。传入非主窗口id时调用不生效也不报错。不存在对应窗口id时接口返回错误码WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL。 |
| bool enabled | 设置状态栏是否显示。true表示设置状态栏显示，false表示设置状态栏隐藏。 |
| bool enableAnimation | 设置是否开启状态栏的显隐动画。true表示开启状态栏的显隐动画，false表示关闭状态栏的显隐动画。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持功能。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_SetWindowStatusBarColor()

```c
int32_t OH_WindowManager_SetWindowStatusBarColor(int32_t windowId, int32_t color)
```

**描述**

设置主窗口的状态栏内容颜色。

调用生效后返回并不表示状态栏的颜色更新已完成。主窗口在非全屏/最大化模式（智慧多窗悬浮窗、分屏等场景）下配置不生效，进入全屏/最大化模式后配置生效。

**起始版本：** 15

**设备行为差异：**

该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不生效也不报错；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 主窗口id。传入非主窗口id时调用不生效也不报错。不存在对应窗口id时接口返回错误码WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL。 |
| int32_t color | 要设置的颜色值，格式为ARGB。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持功能。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_SetWindowNavigationBarEnabled()

```c
int32_t OH_WindowManager_SetWindowNavigationBarEnabled(int32_t windowId, bool enabled, bool enableAnimation)
```

**描述**

设置主窗口是否显示导航栏。<!--RP2-->此接口仅在导航区域只能表现为三键导航的设备上生效。<!--RP2End-->

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 主窗口id。传入非主窗口id时调用不生效也不报错。不存在对应窗口id时接口返回错误码WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL。 |
| bool enabled | 设置导航栏是否显示。true表示设置导航栏显示，false表示设置导航栏隐藏。 |
| bool enableAnimation | 设置是否开启导航栏的显隐动画。true表示开启导航栏的显隐动画，false表示关闭导航栏的显隐动画。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持功能。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_GetWindowAvoidArea()

```c
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

```c
int32_t OH_WindowManager_IsWindowShown(int32_t windowId, bool* isShow)
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
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。 |

### OH_WindowManager_ShowWindow()

```c
int32_t OH_WindowManager_ShowWindow(int32_t windowId)
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
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_SetWindowTouchable()

```c
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
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_SetWindowFocusable()

```c
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
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_SetWindowBackgroundColor()

```c
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

```c
int32_t OH_WindowManager_SetWindowBrightness(int32_t windowId, float brightness)
```

**描述**

指定主窗口设置窗口亮度。当窗口处于前台且获焦时，窗口亮度生效。

窗口亮度生效时只会影响当前设备屏幕亮度，无法修改虚拟屏（如投屏所在的屏幕）的屏幕亮度。

当接口入参为-1时，窗口亮度恢复为系统屏幕亮度（可以通过控制中心或快捷键调整）。

当窗口退至后台时，窗口亮度失效，可以通过控制中心或快捷键调整。不建议窗口退至后台时调用此接口，否则可能引发时序问题。

**设备行为差异：**
- 针对TV设备：当前接口不生效也不报错。
- 针对非2in1设备（不包含TV设备）：
  - 在<!--RP1-->OpenHarmony 6.1<!--RP1End-->之前，当前窗口的窗口亮度生效时，控制中心调整系统屏幕亮度不生效。
  - 从<!--RP1-->OpenHarmony 6.1<!--RP1End-->开始，当前窗口的窗口亮度生效时，控制中心可以调整系统屏幕亮度，同时会将当前窗口恢复为系统屏幕亮度。
- 针对2in1设备：
  - 在OpenHarmony 5.0.2之前，窗口设置屏幕亮度生效时，控制中心或快捷键调整系统屏幕亮度不生效。
  - 从OpenHarmony 5.0.2开始，窗口亮度与系统屏幕亮度保持一致，可以通过本接口、控制中心或者快捷键设置系统屏幕亮度。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| float brightness | 指定的屏幕亮度值。该参数为浮点数，取值范围为[0.0, 1.0]或-1.0。1.0表示最亮，-1.0表示恢复成设置窗口亮度前的系统控制中心亮度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_SetWindowKeepScreenOn()

```c
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
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_SetWindowPrivacyMode()

```c
int32_t OH_WindowManager_SetWindowPrivacyMode(int32_t windowId, bool isPrivacy)
```

**描述**

设置指定窗口是否开启隐私模式。

**需要权限：** ohos.permission.PRIVACY_WINDOW

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| bool isPrivacy | 指定窗口是否开启隐私模式。true表示开启隐私模式，false表示关闭隐私模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。<br> 返回WINDOW_MANAGER_ERRORCODE_NO_PERMISSION，权限校验错误。 |

### OH_WindowManager_GetWindowProperties()

```c
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
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功，在windowProperties中返回窗口属性的指针。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。 |

### OH_WindowManager_Snapshot()

```c
int32_t OH_WindowManager_Snapshot(int32_t windowId, OH_PixelmapNative* pixelMap)
```

**描述**

获取指定窗口截图。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。<br>窗口id非法或者窗口已经销毁，不能获取指定窗口截图，需要传入有效的窗口id才能成功获取指定窗口截图。<br>请通过窗口对象调用[getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9)接口（ArkTS接口）获取有效的窗口id。 |
| [OH_PixelmapNative](capi-struct.md)* pixelMap | 返回指向指定窗口的截图的指针，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功，在返回pixelMap中的像素图的指针。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_GetAllWindowLayoutInfoList()

```c
int32_t OH_WindowManager_GetAllWindowLayoutInfoList(int64_t displayId,WindowManager_Rect** windowLayoutInfoList, size_t* windowLayoutInfoSize)
```

**描述**

获取指定屏幕上可见的窗口布局信息数组，按当前窗口层级排列，层级最高的对应数组下标为0。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int64_t displayId | 指定屏幕的id。请通过窗口对象调用[getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9)接口（ArkTS接口）获取有效的屏幕id。 |
| [WindowManager_Rect](capi-windowmanager-rect.md)** windowLayoutInfoList | 指定屏幕上可见的窗口布局信息数组的数组指针，作为出参使用。 |
| size_t* windowLayoutInfoSize | 指定屏幕上可见的窗口布局信息数组长度的指针，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br> 返回OK，表示函数调用成功，返回指定屏幕上可见的窗口布局信息数组的数组指针和数组长度的指针。<br> 返回WINDOW_MANAGER_ERRORCODE_INVALID_PARAM，表示参数错误。<br> 返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持功能。<br> 返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_ReleaseAllWindowLayoutInfoList()

```c
void OH_WindowManager_ReleaseAllWindowLayoutInfoList(WindowManager_Rect* windowLayoutInfoList)
```

**描述**

释放窗口布局信息数组占用的内存。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [WindowManager_Rect](capi-windowmanager-rect.md)* windowLayoutInfoList | 指定屏幕上可见的窗口布局信息数组的数组指针，可通过[OH_WindowManager_GetAllWindowLayoutInfoList](#oh_windowmanager_getallwindowlayoutinfolist)接口获取。 |
### OH_WindowManager_InjectTouchEvent()

```c
int32_t OH_WindowManager_InjectTouchEvent(int32_t windowId, Input_TouchEvent* touchEvent, int32_t windowX, int32_t windowY)
```

**描述**

将多模触摸事件注入给目标窗口，仅支持注入同进程窗口，且该注入不会触发窗口焦点和层级变化，不会触发窗口拖拽，事件会直接发送给ArkUI。该接口需要在指定窗口加载UI之后调用。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口id。默认值为0。该参数为整数。 |
| [Input_TouchEvent](../apis-input-kit/capi-input-input-touchevent.md)* touchEvent | 多模触摸事件，具体可见[Input_TouchEvent](../apis-input-kit/capi-input-input-touchevent.md)，事件定义在oh_input_manager.h中。该参数包含的部分字段有参数限制，其中，action应为大于等于0且小于等于3的整数；id、displayX、displayY应为不小于0的整数。以上参数不符合限制条件会返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示：窗口管理器服务异常。 |
| int32_t windowX | 注入事件相对于注入窗口的落点横坐标。该参数为整数。 |
| int32_t windowY | 注入事件相对于注入窗口的落点纵坐标。该参数为整数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>返回OK，表示函数调用成功。<br>返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br>返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_GetAllMainWindowInfo()

```c
int32_t OH_WindowManager_GetAllMainWindowInfo(WindowManager_MainWindowInfo** infoList, size_t* mainWindowInfoSize)
```

**描述**

获取全部主窗口信息。

**设备行为差异：** 该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

**需要权限：** ohos.permission.CUSTOM_SCREEN_CAPTURE

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [WindowManager_MainWindowInfo](capi-windowmanager-windowmanager-mainwindowinfo.md)** infoList | 指向主窗口信息列表的指针，作为出参使用。 |
| size_t* mainWindowInfoSize | 指向主窗口信息数组长度的指针，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>返回OK，表示函数调用成功。<br>返回WINDOW_MANAGER_ERRORCODE_NO_PERMISSION，权限校验错误。<br>返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持功能。<br>返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_ReleaseAllMainWindowInfo()

```c
void OH_WindowManager_ReleaseAllMainWindowInfo(WindowManager_MainWindowInfo* infoList)
```

**描述**

释放主窗口信息列表的内存。

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [WindowManager_MainWindowInfo](capi-windowmanager-windowmanager-mainwindowinfo.md)* infoList | 主窗口信息列表。 |

### OH_WindowManager_WindowSnapshotCallback()

```c
typedef void (*OH_WindowManager_WindowSnapshotCallback)(const OH_PixelmapNative** snapshotPixelMapList, size_t snapshotListSize)
```

**描述**

接收主窗口截图列表的回调接口。

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_PixelmapNative](capi-struct.md)** snapshotPixelMapList | 窗口截图列表。 |
|  size_t snapshotListSize | 窗口截图列表的大小。 |

### OH_WindowManager_GetMainWindowSnapshot()

```c
int32_t OH_WindowManager_GetMainWindowSnapshot(int32_t* windowIdList, size_t windowIdListSize, WindowManager_WindowSnapshotConfig config, OH_WindowManager_WindowSnapshotCallback callback)
```

**描述**

获取一个或多个指定windowId的主窗口截图。

**设备行为差异：** 该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

**需要权限：** ohos.permission.CUSTOM_SCREEN_CAPTURE

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t* windowIdList | 需要获取截图的主窗口ID列表。 |
| size_t windowIdListSize | 主窗口ID列表的长度。 |
| [WindowManager_WindowSnapshotConfig](capi-windowmanager-windowmanager-windowsnapshotconfig.md) config | 获取窗口截图时的配置信息。 |
| [OH_WindowManager_WindowSnapshotCallback](#oh_windowmanager_windowsnapshotcallback) callback | 获取窗口截图的回调对象。用于返回窗口截图列表，并按照指定的窗口ID列表顺序排列。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>返回OK，表示函数调用成功。<br>返回WINDOW_MANAGER_ERRORCODE_NO_PERMISSION，权限校验错误。<br>返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持功能。<br>返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_ReleaseMainWindowSnapshot()

```c
void OH_WindowManager_ReleaseMainWindowSnapshot(const OH_PixelmapNative* snapshotPixelMapList)
```

**描述**

释放主窗口截图列表的内存。

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_PixelmapNative](capi-struct.md)* snapshotPixelMapList | 窗口截图列表。 |

### OH_WindowManager_LockCursor()

```c
int32_t OH_WindowManager_LockCursor(int32_t windowId, bool isCursorFollowMovement)
```

**描述**

锁定鼠标光标，控制鼠标光标不超过指定窗口区域，同时可控制光标是否跟随鼠标移动。仅支持获焦窗口调用，失焦之后会自动取消锁定。

**需要权限：** ohos.permission.LOCK_WINDOW_CURSOR

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口ID。该参数为整数。 |
| bool isCursorFollowMovement | 设置鼠标光标的锁定模式，若为true，则光标会跟随鼠标移动；若为false，则光标不会跟随鼠标移动。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>返回OK，表示函数调用成功。<br>返回WINDOW_MANAGER_ERRORCODE_NO_PERMISSION，表示没有权限调用该接口。<br>返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持该设备。<br>返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br>返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_UnlockCursor()

```c
int32_t OH_WindowManager_UnlockCursor(int32_t windowId)
```

**描述**

清除窗口设置的鼠标光标指定的模式。

**需要权限：** ohos.permission.LOCK_WINDOW_CURSOR

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口ID。该参数为整数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>返回OK，表示函数调用成功。<br>返回WINDOW_MANAGER_ERRORCODE_NO_PERMISSION，表示没有权限调用该接口。<br>返回WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED，表示不支持该设备。<br>返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。<br>返回WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL，表示窗口管理器服务异常。 |

### OH_WindowManager_FrameMetrics_IsFirstDrawFrame()

```c
int32_t OH_WindowManager_FrameMetrics_IsFirstDrawFrame(const OH_WindowManager_FrameMetrics* metrics, bool* isFirstDrawFrame)
```

**描述**

判断当前帧是否为首帧。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_WindowManager_FrameMetrics](capi-windowmanager-oh-windowmanager-framemetrics.md)* metrics | 帧率指标数据对象。 |
| bool* isFirstDrawFrame | 作为出参使用，表示当前帧是否为首帧，true表示是首帧，false表示不是首帧。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。 <br> 返回OK，表示函数调用成功。 <br> 返回WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM，表示参数错误，对应参数取值范围不合理。 <br> 具体可见[WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode)。 |

### OH_WindowManager_FrameMetrics_GetInputHandlingDuration()

```c
int32_t OH_WindowManager_FrameMetrics_GetInputHandlingDuration(const OH_WindowManager_FrameMetrics* metrics, uint64_t* duration)
```

**描述**

获取当前帧中手势处理的耗时。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_WindowManager_FrameMetrics](capi-windowmanager-oh-windowmanager-framemetrics.md)* metrics | 帧率指标数据对象。 |
| uint64_t* duration | 作为出参使用，表示当前帧中手势处理的耗时，单位为纳秒。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。 <br> 返回OK，表示函数调用成功。 <br> 返回WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM，表示参数错误，对应参数取值范围不合理。 <br> 具体可见[WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode)。 |

### OH_WindowManager_FrameMetrics_GetLayoutMeasureDuration()

```c
int32_t OH_WindowManager_FrameMetrics_GetLayoutMeasureDuration(const OH_WindowManager_FrameMetrics* metrics, uint64_t* duration)
```

**描述**

获取当前帧中布局测量的耗时。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_WindowManager_FrameMetrics](capi-windowmanager-oh-windowmanager-framemetrics.md)* metrics | 帧率指标数据对象。 |
| uint64_t* duration | 作为出参使用，表示当前帧中布局测量的耗时，单位为纳秒。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。 <br> 返回OK，表示函数调用成功。 <br> 返回WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM，表示参数错误，对应参数取值范围不合理。 <br> 具体可见[WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode)。 |

### OH_WindowManager_FrameMetrics_GetVsyncTimestamp()

```c
int32_t OH_WindowManager_FrameMetrics_GetVsyncTimestamp(const OH_WindowManager_FrameMetrics* metrics, uint64_t* timestamp)
```

**描述**

获取当前帧开始的时间戳。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_WindowManager_FrameMetrics](capi-windowmanager-oh-windowmanager-framemetrics.md)* metrics | 帧率指标数据对象。 |
| uint64_t* timestamp | 作为出参使用，表示当前帧开始的时间戳，单位为纳秒。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。 <br> 返回OK，表示函数调用成功。 <br> 返回WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM，表示参数错误，对应参数取值范围不合理。 <br> 具体可见[WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode)。 |

### OH_WindowManager_RegisterFrameMetricsMeasuredCallback()

```c
int32_t OH_WindowManager_RegisterFrameMetricsMeasuredCallback(int32_t windowId, OH_WindowManager_FrameMetricsMeasuredCallback callback)
```

**描述**

订阅窗口帧率指标变更监听事件。 <br> 该接口依赖窗口页面内容加载，即需要在ArkTS侧loadContent()接口或setUIContent()接口生效后调用。 <br> 应用注册帧率指标变更监听后，仅当客户端UI内容发生重绘（例如页面切换、响应式组件交互、设置背景色和透明度等）时才会触发已注册回调。 <br> 如需取消订阅，请使用[OH_WindowManager_UnregisterFrameMetricsMeasuredCallback](#oh_windowmanager_unregisterframemetricsmeasuredcallback)接口。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口ID。 |
| [OH_WindowManager_FrameMetricsMeasuredCallback](capi-oh-window-comm-h.md#oh_windowmanager_framemetricsmeasuredcallback) callback | 用于返回帧率指标结果的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。 <br> 返回OK，表示函数调用成功。 <br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。可能原因： <br> 1. 窗口未创建或已销毁； <br> 2. 窗口状态异常。 <br> 返回WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM，表示参数错误，对应参数取值范围不合理。 <br> 具体可见[WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode)。 |

### OH_WindowManager_UnregisterFrameMetricsMeasuredCallback()

```c
int32_t OH_WindowManager_UnregisterFrameMetricsMeasuredCallback(int32_t windowId, OH_WindowManager_FrameMetricsMeasuredCallback callback)
```

**描述**

取消订阅窗口帧率指标变更监听事件。 <br> 该接口依赖窗口页面内容加载，即需要在ArkTS侧loadContent()接口或setUIContent()接口生效后调用。 <br> 如需订阅，请使用[OH_WindowManager_RegisterFrameMetricsMeasuredCallback](#oh_windowmanager_registerframemetricsmeasuredcallback)接口。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 创建窗口时的窗口ID。 |
| [OH_WindowManager_FrameMetricsMeasuredCallback](capi-oh-window-comm-h.md#oh_windowmanager_framemetricsmeasuredcallback) callback | 用于返回帧率指标结果的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。 <br> 返回OK，表示函数调用成功。 <br> 返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。可能原因： <br> 1. 窗口未创建或已销毁； <br> 2. 窗口状态异常。 <br> 返回WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM，表示参数错误，对应参数取值范围不合理。 <br> 具体可见[WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode)。 |

### OH_WindowManager_DensityInfo_GetDefaultDensity()

```c
int32_t OH_WindowManager_DensityInfo_GetDefaultDensity(const OH_WindowManager_DensityInfo* info, float* density)
```

**描述**

获取窗口所在屏幕的系统默认显示大小缩放系数。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_WindowManager_DensityInfo](capi-windowmanager-oh-windowmanager-densityinfo.md)* info | 窗口缩放系数相关信息，通过[OH_WindowManager_GetDensityInfoCopy](#oh_windowmanager_getdensityinfocopy)获取。 |
| float* density | 用于返回系统默认显示大小的缩放系数，取值范围为0.5-4.0，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>返回OK，表示函数调用成功。<br>返回WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM，表示参数错误。可能原因：参数取值范围无效。<br>具体可见[WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode)。 |

### OH_WindowManager_DensityInfo_GetSystemDensity()

```c
int32_t OH_WindowManager_DensityInfo_GetSystemDensity(const OH_WindowManager_DensityInfo* info, float* density)
```

**描述**

获取窗口所在屏幕的系统显示大小缩放系数。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_WindowManager_DensityInfo](capi-windowmanager-oh-windowmanager-densityinfo.md)* info | 窗口缩放系数相关信息，通过[OH_WindowManager_GetDensityInfoCopy](#oh_windowmanager_getdensityinfocopy)获取。 |
| float* density | 用于返回系统显示大小的缩放系数，取值范围为0.5-4.0，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>返回OK，表示函数调用成功。<br>返回WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM，表示参数错误。可能原因：参数取值范围无效。<br>具体可见[WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode)。 |

### OH_WindowManager_DensityInfo_GetCustomDensity()

```c
int32_t OH_WindowManager_DensityInfo_GetCustomDensity(const OH_WindowManager_DensityInfo* info, float* density)
```

**描述**

获取窗口的自定义显示大小缩放系数。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_WindowManager_DensityInfo](capi-windowmanager-oh-windowmanager-densityinfo.md)* info | 窗口缩放系数相关信息，通过[OH_WindowManager_GetDensityInfoCopy](#oh_windowmanager_getdensityinfocopy)获取。 |
| float* density | 窗口的自定义显示大小缩放系数。取值范围为0.5-4.0。作为出参使用。<br>该参数未被设置时，将跟随系统显示大小缩放系数变化。针对子窗、全局悬浮窗、模态窗或系统窗，其自定义显示大小缩放系数等于系统显示大小缩放系数systemDensity。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码<br>返回OK，表示函数调用成功。<br>返回WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM，表示参数错误。可能原因：参数取值范围无效。 <br>具体可见[WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode)。 |

### OH_WindowManager_GetDensityInfoCopy()

```c
int32_t OH_WindowManager_GetDensityInfoCopy(int32_t windowId, const OH_WindowManager_DensityInfo** info)
```

**描述**

获取窗口缩放系数相关信息，包括系统显示大小缩放系数、系统默认显示大小缩放系数、自定义显示大小缩放系数。优先级由高到低分别为：

- 自定义显示大小缩放系数： 窗口级显示缩放值，仅影响单个窗口。

- 系统显示大小缩放系数：当前系统配置的显示大小缩放系数。

- 系统默认显示大小缩放系数：系统默认的基准缩放值。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 窗口创建时的窗口ID。 |
| [const OH_WindowManager_DensityInfo](capi-windowmanager-oh-windowmanager-densityinfo.md)** info | 窗口缩放系数相关信息，作为出参使用。<br>返回值为NULL表示当前设备不支持该接口。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>返回OK，表示函数调用成功。<br>返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。可能原因：1. 窗口未创建或已销毁；2. 窗口状态异常。<br>返回WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM，表示参数错误。可能原因：参数取值范围无效。<br>具体可见[WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode)。 |

### OH_WindowManager_RegisterDensityInfoChangeCallback()

```c
int32_t OH_WindowManager_RegisterDensityInfoChangeCallback(int32_t windowId, OH_WindowManager_DensityInfoCallback callback)
```

**描述**

监听窗口缩放系数相关信息的变化。

当窗口所在屏幕的系统显示大小缩放系数、系统默认显示大小的缩放系数或自定义显示大小的缩放系数任一项发生变化时，会触发该回调函数。

如需取消监听窗口缩放系数相关信息的变化，请调用[OH_WindowManager_UnregisterDensityInfoChangeCallback](#oh_windowmanager_unregisterdensityinfochangecallback)。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 窗口创建时的窗口ID。 |
| [OH_WindowManager_DensityInfoCallback](capi-oh-window-comm-h.md#oh_windowmanager_densityinfocallback) callback | 用于返回窗口缩放系数相关信息结果的回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>返回OK，表示函数调用成功。<br>返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。可能原因：1. 窗口未创建或已销毁；2. 窗口状态异常。<br>返回WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM，表示参数错误。可能原因：参数取值范围无效。<br>具体可见[WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode)。 |

### OH_WindowManager_UnregisterDensityInfoChangeCallback()

```c
int32_t OH_WindowManager_UnregisterDensityInfoChangeCallback(int32_t windowId, OH_WindowManager_DensityInfoCallback callback)
```

**描述**

取消监听窗口缩放系数相关信息的变化。

当窗口所在屏幕的系统显示大小缩放系数、系统默认显示大小缩放系数或自定义显示大小的缩放系数任一项发生变化时，不会触发已取消注册的回调函数。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t windowId | 窗口创建时的窗口ID。 |
| [OH_WindowManager_DensityInfoCallback](capi-oh-window-comm-h.md#oh_windowmanager_densityinfocallback) callback | 用于返回窗口缩放系数相关信息结果的回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>返回OK，表示函数调用成功。<br>返回WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL，表示窗口状态异常。可能原因：1. 窗口未创建或已销毁；2. 窗口状态异常。<br>返回WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM，表示参数错误。可能原因：参数取值范围无效。<br>具体可见[WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode)。 |

### OH_WindowManager_DensityInfo_Release()

```c
int32_t OH_WindowManager_DensityInfo_Release(const OH_WindowManager_DensityInfo* info)
```

**描述**

释放窗口缩放系数相关信息对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_WindowManager_DensityInfo](capi-windowmanager-oh-windowmanager-densityinfo.md)* info | 窗口缩放系数相关信息。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>返回OK，表示函数调用成功。<br>返回WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM，表示参数错误。可能原因：参数取值范围无效。<br>具体可见[WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode)。 |