# oh_display_capture.h

## 概述

提供屏幕截屏的能力。

**引用文件：** oh_display_capture.h

**库：** libnative_display_manager.so

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 14

**相关模块：** [OH_DisplayManager](capi-oh-displaymanager.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CaptureScreenPixelmap(uint32_t displayId,OH_PixelmapNative **pixelMap)](#oh_nativedisplaymanager_capturescreenpixelmap) | 获取屏幕全屏截图，此接口仅支持在平板和2in1设备上使用，可以通过设置不同的屏幕id号截取不同屏幕的截图。 |

## 函数说明

### OH_NativeDisplayManager_CaptureScreenPixelmap()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CaptureScreenPixelmap(uint32_t displayId,OH_PixelmapNative **pixelMap)
```

**描述**

获取屏幕全屏截图，此接口仅支持在平板和2in1设备上使用，可以通过设置不同的屏幕id号截取不同屏幕的截图。

**系统能力：** SystemCapability.Window.SessionManager.Core

**需要权限：** ohos.permission.CUSTOM_SCREEN_CAPTURE

**起始版本：** 14

**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint32_t displayId | 需要截屏的屏幕id号，该值为非负整数。 |
| [OH_PixelmapNative](../apis-image-kit/_image___native_module.md#oh_pixelmapnative) **pixelMap | 创建指定屏幕id的OH_PixelmapNative对象，此处作为出参返回。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | 返回屏幕管理接口的通用状态码，具体可见[NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode)。 |


