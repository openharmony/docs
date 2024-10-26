# OH_DisplayManager


## 概述

提供屏幕管理的能力。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [oh_display_info.h](oh__display__info_8h.md) | 提供屏幕的公共枚举、公共定义等。 | 
| [oh_display_manager.h](oh__display__manager_8h.md) | 提供屏幕管理的一些基础能力，包括获取默认显示设备的信息，以及监听显示设备的旋转、折叠、展开等状态变化的能力。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [NativeDisplayManager_Rect](_native_display_manager___rect.md) | 矩形区域。 | 
| struct  [NativeDisplayManager_WaterfallDisplayAreaRects](ive_display_manager___waterfall_display_area_rects.md) | 瀑布屏曲面部分显示区域。 | 
| struct  [NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md) | 挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [NativeDisplayManager_Rotation](#nativedisplaymanager_rotation) [NativeDisplayManager_Rotation](#nativedisplaymanager_rotation) | 屏幕顺时针的旋转角度。 | 
| typedef enum [NativeDisplayManager_Orientation](#nativedisplaymanager_orientation) [NativeDisplayManager_Orientation](#nativedisplaymanager_orientation) | 屏幕的旋转方向。 | 
| typedef enum [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) | 屏幕管理接口返回状态码枚举。 | 
| typedef enum [NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode) [NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode) | 可折叠设备的显示模式枚举。 | 
| typedef struct [NativeDisplayManager_Rect](_native_display_manager___rect.md) [NativeDisplayManager_Rect](#nativedisplaymanager_rect) | 矩形区域。 | 
| typedef struct [NativeDisplayManager_WaterfallDisplayAreaRects](ive_display_manager___waterfall_display_area_rects.md) [NativeDisplayManager_WaterfallDisplayAreaRects](#nativedisplaymanager_waterfalldisplayarearects) | 瀑布屏曲面部分显示区域。 | 
| typedef struct [NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md) [NativeDisplayManager_CutoutInfo](#nativedisplaymanager_cutoutinfo) | 挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。 | 
| typedef void(\* [OH_NativeDisplayManager_DisplayChangeCallback](#oh_nativedisplaymanager_displaychangecallback)) (uint64_t displayId) | 注册屏幕状态变化的回调函数。 | 
| typedef void(\* [OH_NativeDisplayManager_FoldDisplayModeChangeCallback](#oh_nativedisplaymanager_folddisplaymodechangecallback)) ([NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode) displayMode) | 注册屏幕展开、折叠状态变化的回调函数。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [NativeDisplayManager_Rotation](#nativedisplaymanager_rotation-1) { DISPLAY_MANAGER_ROTATION_0 = 0, DISPLAY_MANAGER_ROTATION_90 = 1, DISPLAY_MANAGER_ROTATION_180 = 2, DISPLAY_MANAGER_ROTATION_270 = 3 } | 屏幕顺时针的旋转角度。 | 
| [NativeDisplayManager_Orientation](#nativedisplaymanager_orientation-1) {<br/>DISPLAY_MANAGER_PORTRAIT = 0, DISPLAY_MANAGER_LANDSCAPE = 1, DISPLAY_MANAGER_PORTRAIT_INVERTED = 2, DISPLAY_MANAGER_LANDSCAPE_INVERTED = 3,<br/>DISPLAY_MANAGER_UNKNOWN<br/>} | 屏幕的旋转方向。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode-1) {<br/>DISPLAY_MANAGER_OK = 0, DISPLAY_MANAGER_ERROR_NO_PERMISSION = 201, DISPLAY_MANAGER_ERROR_NOT_SYSTEM_APP = 202, DISPLAY_MANAGER_ERROR_INVALID_PARAM = 401,<br/>DISPLAY_MANAGER_ERROR_DEVICE_NOT_SUPPORTED = 801, DISPLAY_MANAGER_ERROR_INVALID_SCREEN = 1400001, DISPLAY_MANAGER_ERROR_INVALID_CALL = 1400002, DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL = 1400003<br/>} | 屏幕管理接口返回状态码枚举。 | 
| [NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode-1) {<br/>DISPLAY_MANAGER_FOLD_DISPLAY_MODE_UNKNOWN = 0, DISPLAY_MANAGER_FOLD_DISPLAY_MODE_FULL = 1, DISPLAY_MANAGER_FOLD_DISPLAY_MODE_MAIN = 2, DISPLAY_MANAGER_FOLD_DISPLAY_MODE_SUB = 3,<br/>DISPLAY_MANAGER_FOLD_DISPLAY_MODE_COORDINATION = 4<br/>} | 可折叠设备的显示模式枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayId](#oh_nativedisplaymanager_getdefaultdisplayid) (uint64_t \*displayId) | 获取默认屏幕的id号。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayWidth](#oh_nativedisplaymanager_getdefaultdisplaywidth) (int32_t \*displayWidth) | 获取默认屏幕的宽度。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayHeight](#oh_nativedisplaymanager_getdefaultdisplayheight) (int32_t \*displayHeight) | 获取默认屏幕的高度。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayRotation](#oh_nativedisplaymanager_getdefaultdisplayrotation) ([NativeDisplayManager_Rotation](#nativedisplaymanager_rotation) \*displayRotation) | 获取默认屏幕的顺时针旋转角度。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayOrientation](#oh_nativedisplaymanager_getdefaultdisplayorientation) ([NativeDisplayManager_Orientation](#nativedisplaymanager_orientation) \*displayOrientation) | 获取默认屏幕的旋转方向。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayVirtualPixelRatio](#oh_nativedisplaymanager_getdefaultdisplayvirtualpixelratio) (float \*virtualPixels) | 获取默认屏幕的虚拟像素密度。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayRefreshRate](#oh_nativedisplaymanager_getdefaultdisplayrefreshrate) (uint32_t \*refreshRate) | 获取默认屏幕的刷新率。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityDpi](#oh_nativedisplaymanager_getdefaultdisplaydensitydpi) (int32_t \*densityDpi) | 获取屏幕的物理像素密度。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityPixels](#oh_nativedisplaymanager_getdefaultdisplaydensitypixels) (float \*densityPixels) | 获取屏幕逻辑像素的密度。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayScaledDensity](#oh_nativedisplaymanager_getdefaultdisplayscaleddensity) (float \*scaledDensity) | 获取屏幕显示字体的缩放因子。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityXdpi](#oh_nativedisplaymanager_getdefaultdisplaydensityxdpi) (float \*xDpi) | 获取屏幕X方向中每英寸屏幕的物理像素值。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityYdpi](#oh_nativedisplaymanager_getdefaultdisplaydensityydpi) (float \*yDpi) | 获取Y方向中每英寸屏幕的物理像素值。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo](#oh_nativedisplaymanager_createdefaultdisplaycutoutinfo) ([NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md) \*\*cutoutInfo) | 获取挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo](#oh_nativedisplaymanager_destroydefaultdisplaycutoutinfo) ([NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md) \*cutoutInfo) | 销毁挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。 | 
| bool [OH_NativeDisplayManager_IsFoldable](#oh_nativedisplaymanager_isfoldable) () | 查询设备是否可折叠。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetFoldDisplayMode](#oh_nativedisplaymanager_getfolddisplaymode) ([NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode) \*displayMode) | 获取可折叠设备的显示模式。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_RegisterDisplayChangeListener](#oh_nativedisplaymanager_registerdisplaychangelistener) ([OH_NativeDisplayManager_DisplayChangeCallback](#oh_nativedisplaymanager_displaychangecallback) displayChangeCallback, uint32_t \*listenerIndex) | 注册屏幕状态变化监听（如旋转变化、刷新率、DPI、分辨率等变化）。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_UnregisterDisplayChangeListener](#oh_nativedisplaymanager_unregisterdisplaychangelistener) (uint32_t listenerIndex) | 取消屏幕状态变化的监听。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener](#oh_nativedisplaymanager_registerfolddisplaymodechangelistener) ([OH_NativeDisplayManager_FoldDisplayModeChangeCallback](#oh_nativedisplaymanager_folddisplaymodechangecallback) displayModeChangeCallback, uint32_t \*listenerIndex) | 注册屏幕展开、折叠状态变化的监听。 | 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener](#oh_nativedisplaymanager_unregisterfolddisplaymodechangelistener) (uint32_t listenerIndex) | 取消屏幕展开、折叠状态变化的监听。 | 


## 类型定义说明


### NativeDisplayManager_CutoutInfo

```
typedef struct NativeDisplayManager_CutoutInfo NativeDisplayManager_CutoutInfo
```

**描述**

挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12


### NativeDisplayManager_ErrorCode

```
typedef enum NativeDisplayManager_ErrorCode NativeDisplayManager_ErrorCode
```

**描述**

屏幕管理接口返回状态码枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12


### NativeDisplayManager_FoldDisplayMode

```
typedef enum NativeDisplayManager_FoldDisplayMode NativeDisplayManager_FoldDisplayMode
```

**描述**

可折叠设备的显示模式枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12


### NativeDisplayManager_Orientation

```
typedef enum NativeDisplayManager_Orientation NativeDisplayManager_Orientation
```

**描述**

屏幕的旋转方向。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12


### NativeDisplayManager_Rect

```
typedef struct NativeDisplayManager_Rect NativeDisplayManager_Rect
```

**描述**

矩形区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12


### NativeDisplayManager_Rotation

```
typedef enum NativeDisplayManager_Rotation NativeDisplayManager_Rotation
```

**描述**

屏幕顺时针的旋转角度。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12


### NativeDisplayManager_WaterfallDisplayAreaRects

```
typedef struct NativeDisplayManager_WaterfallDisplayAreaRects NativeDisplayManager_WaterfallDisplayAreaRects
```

**描述**

瀑布屏曲面部分显示区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12


### OH_NativeDisplayManager_DisplayChangeCallback

```
typedef void(* OH_NativeDisplayManager_DisplayChangeCallback) (uint64_t displayId)
```

**描述**

注册屏幕状态变化的回调函数。

**系统能力：** SystemCapability.Window.SessionManager

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| displayId | 屏幕状态发生变化的编号。 | 


### OH_NativeDisplayManager_FoldDisplayModeChangeCallback

```
typedef void(* OH_NativeDisplayManager_FoldDisplayModeChangeCallback) (NativeDisplayManager_FoldDisplayMode displayMode)
```

**描述**

注册屏幕展开、折叠状态变化的回调函数。

**系统能力：** SystemCapability.Window.SessionManager

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| displayMode | 折叠/展开动作执行后屏幕的状态，具体可见[NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode)。 | 


## 枚举类型说明


### NativeDisplayManager_ErrorCode

```
enum NativeDisplayManager_ErrorCode
```

**描述**

屏幕管理接口返回状态码枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| DISPLAY_MANAGER_OK | 成功。 | 
| DISPLAY_MANAGER_ERROR_NO_PERMISSION | 权限校验失败，应用无权限使用该API，需要申请权限。 | 
| DISPLAY_MANAGER_ERROR_NOT_SYSTEM_APP | 权限校验失败，非系统应用使用了系统API。 | 
| DISPLAY_MANAGER_ERROR_INVALID_PARAM | 参数检查失败。 | 
| DISPLAY_MANAGER_ERROR_DEVICE_NOT_SUPPORTED | 该设备不支持此API。 | 
| DISPLAY_MANAGER_ERROR_INVALID_SCREEN | 操作的显示设备无效。 | 
| DISPLAY_MANAGER_ERROR_INVALID_CALL | 当前操作对象无操作权限。 | 
| DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL | 系统服务工作异常。 | 


### NativeDisplayManager_FoldDisplayMode

```
enum NativeDisplayManager_FoldDisplayMode
```

**描述**

可折叠设备的显示模式枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_UNKNOWN | 表示设备当前折叠显示模式未知。 | 
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_FULL | 表示设备当前全屏显示。 | 
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_MAIN | 表示设备当前主屏幕显示。 | 
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_SUB | 表示设备当前子屏幕显示。 | 
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_COORDINATION | 表示设备当前双屏协同显示。 | 


### NativeDisplayManager_Orientation

```
enum NativeDisplayManager_Orientation
```

**描述**

屏幕的旋转方向。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| DISPLAY_MANAGER_PORTRAIT | 表示设备当前以竖屏方式显示。 | 
| DISPLAY_MANAGER_LANDSCAPE | 表示设备当前以横屏方式显示。 | 
| DISPLAY_MANAGER_PORTRAIT_INVERTED | 表示设备当前以反向竖屏方式显示。 | 
| DISPLAY_MANAGER_LANDSCAPE_INVERTED | 表示设备当前以反向横屏方式显示。 | 
| DISPLAY_MANAGER_UNKNOWN | 表示显示未识别屏幕方向。 | 


### NativeDisplayManager_Rotation

```
enum NativeDisplayManager_Rotation
```

**描述**

屏幕顺时针的旋转角度。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| DISPLAY_MANAGER_ROTATION_0 | 代表屏幕顺时针旋转角度0度。 | 
| DISPLAY_MANAGER_ROTATION_90 | 代表屏幕顺时针旋转角度90度。 | 
| DISPLAY_MANAGER_ROTATION_180 | 代表屏幕顺时针旋转角度180度。 | 
| DISPLAY_MANAGER_ROTATION_270 | 代表屏幕顺时针旋转角度270度。 | 


## 函数说明


### OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo (NativeDisplayManager_CutoutInfo **cutoutInfo)
```

**描述**

获取挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cutoutInfo | 挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息，具体可见[NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md)，此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo (NativeDisplayManager_CutoutInfo *cutoutInfo)
```

**描述**

销毁挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cutoutInfo | 销毁通过[OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo](#oh_nativedisplaymanager_createdefaultdisplaycutoutinfo)接口获取的挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息对象，具体可见[NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md)。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_GetDefaultDisplayDensityDpi()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityDpi (int32_t *densityDpi)
```

**描述**

获取屏幕的物理像素密度。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| densityDpi | 屏幕的物理像素密度，表示每英寸上的像素点数。该参数为浮点数，单位为px，实际能取到的值取决于不同设备设置里提供的可选值。此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_GetDefaultDisplayDensityPixels()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityPixels (float *densityPixels)
```

**描述**

获取屏幕逻辑像素的密度。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| densityPixels | 设备逻辑像素的密度，代表物理像素与逻辑像素的缩放系数，该参数为浮点数，受densityDPI范围限制，取值范围在[0.5，4.0]。一般取值1.0、3.0等，实际取值取决于不同设备提供的densityDpi。此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_GetDefaultDisplayDensityXdpi()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityXdpi (float *xDpi)
```

**描述**

获取屏幕X方向中每英寸屏幕的物理像素值。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| xDpi | X方向中每英寸屏幕的物理像素值，该参数为浮点数，此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_GetDefaultDisplayDensityYdpi()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityYdpi (float *yDpi)
```

**描述**

获取Y方向中每英寸屏幕的物理像素值。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| yDpi | 获取Y方向中每英寸屏幕的物理像素值，该参数为浮点数，此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_GetDefaultDisplayHeight()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayHeight (int32_t *displayHeight)
```

**描述**

获取默认屏幕的高度。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| displayHeight | 默认屏幕的高度，单位为px，该参数应为整数，此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_GetDefaultDisplayId()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayId (uint64_t *displayId)
```

**描述**

获取默认屏幕的id号。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| displayId | 默认屏幕的id号，非负整数，此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_GetDefaultDisplayOrientation()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayOrientation (NativeDisplayManager_Orientation *displayOrientation)
```

**描述**

获取默认屏幕的旋转方向。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| displayOrientation | 屏幕当前显示的方向，具体可见[NativeDisplayManager_Orientation](#nativedisplaymanager_orientation)，此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_GetDefaultDisplayRefreshRate()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayRefreshRate (uint32_t *refreshRate)
```

**描述**

获取默认屏幕的刷新率。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| refreshRate | 屏幕的刷新率，该参数应为整数，单位为hz，此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_GetDefaultDisplayRotation()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayRotation (NativeDisplayManager_Rotation *displayRotation)
```

**描述**

获取默认屏幕的顺时针旋转角度。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| displayRotation | 默认屏幕的顺时针旋转角度，具体可见[NativeDisplayManager_Rotation](#nativedisplaymanager_rotation)，此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_GetDefaultDisplayScaledDensity()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayScaledDensity (float *scaledDensity)
```

**描述**

获取屏幕显示字体的缩放因子。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scaledDensity | 显示字体的缩放因子，该参数为浮点数，通常与densityPixels相同，此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_GetDefaultDisplayVirtualPixelRatio()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayVirtualPixelRatio (float *virtualPixels)
```

**描述**

获取默认屏幕的虚拟像素密度。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| virtualPixels | 屏幕的虚拟像素密度，该参数为浮点数，通常与densityPixels相同，此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_GetDefaultDisplayWidth()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayWidth (int32_t *displayWidth)
```

**描述**

获取默认屏幕的宽度。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| displayWidth | 默认屏幕的宽度，单位为px，该参数应为整数，此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_GetFoldDisplayMode()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetFoldDisplayMode (NativeDisplayManager_FoldDisplayMode *displayMode)
```

**描述**

获取可折叠设备的显示模式。

**系统能力：** SystemCapability.Window.SessionManager

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| displayMode | 折叠设备当前的显示模式，具体可见[NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode)，此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_IsFoldable()

```
bool OH_NativeDisplayManager_IsFoldable ()
```

**描述**

查询设备是否可折叠。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**返回：**

返回查询设备是否可折叠的结果。true表示设备可折叠，false表示设备不可折叠。


### OH_NativeDisplayManager_RegisterDisplayChangeListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterDisplayChangeListener (OH_NativeDisplayManager_DisplayChangeCallback displayChangeCallback, uint32_t *listenerIndex )
```

**描述**

注册屏幕状态变化监听（如旋转变化、刷新率、DPI、分辨率等变化）。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| displayChangeCallback | 屏幕状态变化后触发的回调函数，回调函数定义见[OH_NativeDisplayManager_DisplayChangeCallback](#oh_nativedisplaymanager_displaychangecallback)。 | 
| listenerIndex | 注册成功后返回的监听编号，调用取消注册函数[OH_NativeDisplayManager_UnregisterDisplayChangeListener](#oh_nativedisplaymanager_unregisterdisplaychangelistener)时作为入参使用，此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener (OH_NativeDisplayManager_FoldDisplayModeChangeCallback displayModeChangeCallback, uint32_t *listenerIndex )
```

**描述**

注册屏幕展开、折叠状态变化的监听。

**系统能力：** SystemCapability.Window.SessionManager

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| displayModeChangeCallback | 屏幕展开和折叠变化后触发的回调函数，回调函数定义见[OH_NativeDisplayManager_FoldDisplayModeChangeCallback](#oh_nativedisplaymanager_folddisplaymodechangecallback)。 | 
| listenerIndex | 注册成功后返回的监听编号，调用取消注册函数[OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener](#oh_nativedisplaymanager_unregisterfolddisplaymodechangelistener)时作为入参使用，此处作为出参返回。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_UnregisterDisplayChangeListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterDisplayChangeListener (uint32_t listenerIndex)
```

**描述**

取消屏幕状态变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| listenerIndex | 调用注册函数[OH_NativeDisplayManager_RegisterDisplayChangeListener](#oh_nativedisplaymanager_registerdisplaychangelistener)时获取到的监听编号。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。


### OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener (uint32_t listenerIndex)
```

**描述**

取消屏幕展开、折叠状态变化的监听。

**系统能力：** SystemCapability.Window.SessionManager

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| listenerIndex | 调用注册函数[OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener](#oh_nativedisplaymanager_registerfolddisplaymodechangelistener)时获取到的监听编号。 | 

**返回：**

返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode)。
