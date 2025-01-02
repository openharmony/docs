# oh_display_manager.h


## 概述

提供屏幕管理的一些基础能力，包括获取默认显示设备的信息，以及监听显示设备的旋转、折叠、展开等状态变化的能力。

**引用文件：**&lt;window_manager/oh_display_manager.h&gt;

**库：** libnative_display_manager.so.

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**相关模块：**[OH_DisplayManager](_o_h___display_manager.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(\* [OH_NativeDisplayManager_DisplayChangeCallback](_o_h___display_manager.md#oh_nativedisplaymanager_displaychangecallback)) (uint64_t displayId) | 注册屏幕状态变化的回调函数。 | 
| typedef void(\* [OH_NativeDisplayManager_FoldDisplayModeChangeCallback](_o_h___display_manager.md#oh_nativedisplaymanager_folddisplaymodechangecallback)) ([NativeDisplayManager_FoldDisplayMode](_o_h___display_manager.md#nativedisplaymanager_folddisplaymode) displayMode) | 注册屏幕展开、折叠状态变化的回调函数。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayId](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplayid) (uint64_t \*displayId) | 获取默认屏幕的id号。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayWidth](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplaywidth) (int32_t \*displayWidth) | 获取默认屏幕的宽度。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayHeight](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplayheight) (int32_t \*displayHeight) | 获取默认屏幕的高度。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayRotation](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplayrotation) ([NativeDisplayManager_Rotation](_o_h___display_manager.md#nativedisplaymanager_rotation) \*displayRotation) | 获取默认屏幕的顺时针旋转角度。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayOrientation](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplayorientation) ([NativeDisplayManager_Orientation](_o_h___display_manager.md#nativedisplaymanager_orientation) \*displayOrientation) | 获取默认屏幕的旋转方向。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayVirtualPixelRatio](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplayvirtualpixelratio) (float \*virtualPixels) | 获取默认屏幕的虚拟像素密度。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayRefreshRate](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplayrefreshrate) (uint32_t \*refreshRate) | 获取默认屏幕的刷新率。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityDpi](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplaydensitydpi) (int32_t \*densityDpi) | 获取屏幕的物理像素密度。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityPixels](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplaydensitypixels) (float \*densityPixels) | 获取屏幕逻辑像素的密度。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayScaledDensity](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplayscaleddensity) (float \*scaledDensity) | 获取屏幕显示字体的缩放因子。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityXdpi](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplaydensityxdpi) (float \*xDpi) | 获取屏幕X方向中每英寸屏幕的物理像素值。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityYdpi](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplaydensityydpi) (float \*yDpi) | 获取Y方向中每英寸屏幕的物理像素值。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo](_o_h___display_manager.md#oh_nativedisplaymanager_createdefaultdisplaycutoutinfo) ([NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md) \*\*cutoutInfo) | 获取挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo](_o_h___display_manager.md#oh_nativedisplaymanager_destroydefaultdisplaycutoutinfo) ([NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md) \*cutoutInfo) | 销毁挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。 | 
| bool [OH_NativeDisplayManager_IsFoldable](_o_h___display_manager.md#oh_nativedisplaymanager_isfoldable) () | 查询设备是否可折叠。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetFoldDisplayMode](_o_h___display_manager.md#oh_nativedisplaymanager_getfolddisplaymode) ([NativeDisplayManager_FoldDisplayMode](_o_h___display_manager.md#nativedisplaymanager_folddisplaymode) \*displayMode) | 获取可折叠设备的显示模式。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_RegisterDisplayChangeListener](_o_h___display_manager.md#oh_nativedisplaymanager_registerdisplaychangelistener) ([OH_NativeDisplayManager_DisplayChangeCallback](_o_h___display_manager.md#oh_nativedisplaymanager_displaychangecallback) displayChangeCallback, uint32_t \*listenerIndex) | 注册屏幕状态变化监听（如旋转变化、刷新率、DPI、分辨率等变化）。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_UnregisterDisplayChangeListener](_o_h___display_manager.md#oh_nativedisplaymanager_unregisterdisplaychangelistener) (uint32_t listenerIndex) | 取消屏幕状态变化的监听。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener](_o_h___display_manager.md#oh_nativedisplaymanager_registerfolddisplaymodechangelistener) ([OH_NativeDisplayManager_FoldDisplayModeChangeCallback](_o_h___display_manager.md#oh_nativedisplaymanager_folddisplaymodechangecallback) displayModeChangeCallback, uint32_t \*listenerIndex) | 注册屏幕展开、折叠状态变化的监听。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener](_o_h___display_manager.md#oh_nativedisplaymanager_unregisterfolddisplaymodechangelistener) (uint32_t listenerIndex) | 取消屏幕展开、折叠状态变化的监听。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_CreateAllDisplays](_o_h___display_manager.md#oh_nativedisplaymanager_createalldisplays) ([NativeDisplayManager_DisplaysInfo](_native_display_manager___displays_info.md) \*\*allDisplays) | 获取当前所有屏幕信息对象。 | 
| void [OH_NativeDisplayManager_DestroyAllDisplays](_o_h___display_manager.md#oh_nativedisplaymanager_destroyalldisplays) ([NativeDisplayManager_DisplaysInfo](_native_display_manager___displays_info.md) \*allDisplays) | 销毁所有屏幕的信息对象。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_CreateDisplayById](_o_h___display_manager.md#oh_nativedisplaymanager_createdisplaybyid) (uint32_t displayId, [NativeDisplayManager_DisplayInfo](_native_display_manager___display_info.md) \*\*displayInfo) | 获取指定屏幕的信息对象。 | 
| void [OH_NativeDisplayManager_DestroyDisplay](_o_h___display_manager.md#oh_nativedisplaymanager_destroydisplay) ([NativeDisplayManager_DisplayInfo](_native_display_manager___display_info.md) \*displayInfo) | 销毁指定屏幕的信息对象。 | 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_CreatePrimaryDisplay](_o_h___display_manager.md#oh_nativedisplaymanager_createprimarydisplay) ([NativeDisplayManager_DisplayInfo](_native_display_manager___display_info.md) \*\*displayInfo) | 获取主屏信息对象。除2in1之外的设备获取的是设备自带屏幕的屏幕信息；2in1设备外接屏幕时获取的是当前主屏幕的屏幕信息；2in1设备没有外接屏幕时获取的是自带屏幕的屏幕信息。 | 
