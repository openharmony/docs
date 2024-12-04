# oh_display_info.h


## 概述

提供屏幕的公共枚举、公共定义等。

**引用文件：**&lt;window_manager/oh_display_info.h&gt;

**库：** libnative_display_manager.so

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**相关模块：**[OH_DisplayManager](_o_h___display_manager.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [NativeDisplayManager_Rect](_native_display_manager___rect.md) | 矩形区域。 | 
| struct  [NativeDisplayManager_WaterfallDisplayAreaRects](ive_display_manager___waterfall_display_area_rects.md) | 瀑布屏曲面部分显示区域。 | 
| struct  [NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md) | 挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。 | 
| struct  [NativeDisplayManager_DisplayHdrFormat](_native_display_manager___display_hdr_format.md) | 显示设备支持的所有HDR格式。 | 
| struct  [NativeDisplayManager_DisplayColorSpace](_native_display_manager___display_color_space.md) | 显示设备支持的所有色域类型。 | 
| struct  [NativeDisplayManager_DisplayInfo](_native_display_manager___display_info.md) | 显示设备的对象属性。 | 
| struct  [NativeDisplayManager_DisplaysInfo](_native_display_manager___displays_info.md) | 多显示设备的Display对象。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [NativeDisplayManager_Rotation](_o_h___display_manager.md#nativedisplaymanager_rotation) [NativeDisplayManager_Rotation](_o_h___display_manager.md#nativedisplaymanager_rotation) | 屏幕顺时针的旋转角度。 | 
| typedef enum [NativeDisplayManager_Orientation](_o_h___display_manager.md#nativedisplaymanager_orientation) [NativeDisplayManager_Orientation](_o_h___display_manager.md#nativedisplaymanager_orientation) | 屏幕的旋转方向。 | 
| typedef enum [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) | 屏幕管理接口返回状态码枚举。 | 
| typedef enum [NativeDisplayManager_FoldDisplayMode](_o_h___display_manager.md#nativedisplaymanager_folddisplaymode) [NativeDisplayManager_FoldDisplayMode](_o_h___display_manager.md#nativedisplaymanager_folddisplaymode) | 可折叠设备的显示模式枚举。 | 
| typedef struct [NativeDisplayManager_Rect](_native_display_manager___rect.md) [NativeDisplayManager_Rect](_o_h___display_manager.md#nativedisplaymanager_rect) | 矩形区域。 | 
| typedef struct [NativeDisplayManager_WaterfallDisplayAreaRects](ive_display_manager___waterfall_display_area_rects.md) [NativeDisplayManager_WaterfallDisplayAreaRects](_o_h___display_manager.md#nativedisplaymanager_waterfalldisplayarearects) | 瀑布屏曲面部分显示区域。 | 
| typedef struct [NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md) [NativeDisplayManager_CutoutInfo](_o_h___display_manager.md#nativedisplaymanager_cutoutinfo) | 挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。 | 
| typedef enum [NativeDisplayManager_DisplayState](_o_h___display_manager.md#nativedisplaymanager_displaystate) [NativeDisplayManager_DisplayState](_o_h___display_manager.md#nativedisplaymanager_displaystate) | 显示设备的状态枚举。 | 
| typedef struct [NativeDisplayManager_DisplayHdrFormat](_native_display_manager___display_hdr_format.md) [NativeDisplayManager_DisplayHdrFormat](_o_h___display_manager.md#nativedisplaymanager_displayhdrformat) | 显示设备支持的所有HDR格式。 | 
| typedef struct [NativeDisplayManager_DisplayColorSpace](_native_display_manager___display_color_space.md) [NativeDisplayManager_DisplayColorSpace](_o_h___display_manager.md#nativedisplaymanager_displaycolorspace) | 显示设备支持的所有色域类型。 | 
| typedef struct [NativeDisplayManager_DisplayInfo](_native_display_manager___display_info.md) [NativeDisplayManager_DisplayInfo](_o_h___display_manager.md#nativedisplaymanager_displayinfo) | 显示设备的对象属性。 | 
| typedef struct [NativeDisplayManager_DisplaysInfo](_native_display_manager___displays_info.md) [NativeDisplayManager_DisplaysInfo](_o_h___display_manager.md#nativedisplaymanager_displaysinfo) | 多显示设备的Display对象。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [NativeDisplayManager_Rotation](_o_h___display_manager.md#nativedisplaymanager_rotation-1) { DISPLAY_MANAGER_ROTATION_0 = 0, DISPLAY_MANAGER_ROTATION_90 = 1, DISPLAY_MANAGER_ROTATION_180 = 2, DISPLAY_MANAGER_ROTATION_270 = 3 } | 屏幕顺时针的旋转角度。 | 
| [NativeDisplayManager_Orientation](_o_h___display_manager.md#nativedisplaymanager_orientation-1) {<br/>DISPLAY_MANAGER_PORTRAIT = 0, DISPLAY_MANAGER_LANDSCAPE = 1, DISPLAY_MANAGER_PORTRAIT_INVERTED = 2, DISPLAY_MANAGER_LANDSCAPE_INVERTED = 3,<br/>DISPLAY_MANAGER_UNKNOWN<br/>} | 屏幕的旋转方向。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode-1) {<br/>DISPLAY_MANAGER_OK = 0, DISPLAY_MANAGER_ERROR_NO_PERMISSION = 201, DISPLAY_MANAGER_ERROR_NOT_SYSTEM_APP = 202, DISPLAY_MANAGER_ERROR_INVALID_PARAM = 401,<br/>DISPLAY_MANAGER_ERROR_DEVICE_NOT_SUPPORTED = 801, DISPLAY_MANAGER_ERROR_INVALID_SCREEN = 1400001, DISPLAY_MANAGER_ERROR_INVALID_CALL = 1400002, DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL = 1400003<br/>} | 屏幕管理接口返回状态码枚举。 | 
| [NativeDisplayManager_FoldDisplayMode](_o_h___display_manager.md#nativedisplaymanager_folddisplaymode-1) {<br/>DISPLAY_MANAGER_FOLD_DISPLAY_MODE_UNKNOWN = 0, DISPLAY_MANAGER_FOLD_DISPLAY_MODE_FULL = 1, DISPLAY_MANAGER_FOLD_DISPLAY_MODE_MAIN = 2, DISPLAY_MANAGER_FOLD_DISPLAY_MODE_SUB = 3,<br/>DISPLAY_MANAGER_FOLD_DISPLAY_MODE_COORDINATION = 4<br/>} | 可折叠设备的显示模式枚举。 | 
| [NativeDisplayManager_DisplayState](_o_h___display_manager.md#nativedisplaymanager_displaystate-1) {<br/>DISPLAY_MANAGER_DISPLAY_STATE_UNKNOWN = 0, DISPLAY_MANAGER_DISPLAY_STATE_OFF = 1, DISPLAY_MANAGER_DISPLAY_STATE_ON = 2, DISPLAY_MANAGER_DISPLAY_STATE_DOZE = 3,<br/>DISPLAY_MANAGER_DISPLAY_STATE_DOZE_SUSPEND = 4, DISPLAY_MANAGER_DISPLAY_STATE_VR = 5, DISPLAY_MANAGER_DISPLAY_STATE_ON_SUSPEND = 6<br/>} | 显示设备的状态枚举。 | 
