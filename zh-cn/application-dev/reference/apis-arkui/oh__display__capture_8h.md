# oh_display_capture.h


## 概述

提供屏幕截屏的能力。

**引用文件：**&lt;window_manager/oh_display_capture.h&gt;

**库：** libnative_display_manager.so

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 14

**相关模块：**[OH_DisplayManager](_o_h___display_manager.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_CaptureScreenPixelmap](_o_h___display_manager.md#oh_nativedisplaymanager_capturescreenpixelmap) (uint32_t displayId, OH_PixelmapNative \*\*pixelMap) | 获取屏幕全屏截图，此接口仅支持在平板和2in1设备上使用，可以通过设置不同的屏幕id号截取不同屏幕的截图。 | 
