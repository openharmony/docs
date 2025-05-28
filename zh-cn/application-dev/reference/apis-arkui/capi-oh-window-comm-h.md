# oh_window_comm.h

## 概述

提供窗口的公共枚举、公共定义等。

**引用文件：** oh_window_comm.h

**库：** libnative_window_manager.so

**系统能力：** SystemCapability.Window.SessionManager

**起始版本：** 12

**相关模块：** [WindowManager](capi-windowmanager.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [WindowManager_Rect](capi-windowmanager-rect.md) | WindowManager_Rect | 定义窗口矩形结构体，包含窗口位置和宽高信息。 |
| [struct](capi-struct.md) | OH_PixelmapNative | 定义原生像素图片信息。 |
| [WindowManager_WindowProperties](capi-windowmanager-windowproperties.md) | WindowManager_WindowProperties | 窗口属性。 |
| [WindowManager_AvoidArea](capi-windowmanager-avoidarea.md) | WindowManager_AvoidArea | 定义避让区域结构体。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [WindowManager_ErrorCode](#windowmanager_errorcode) | WindowManager_ErrorCode | 窗口管理接口返回状态码枚举。 |
| [WindowManager_AvoidAreaType](#windowmanager_avoidareatype) | WindowManager_AvoidAreaType | 避让区域枚举类型。 |
| [WindowManager_WindowType](#windowmanager_windowtype) | WindowManager_WindowType | 窗口类型。 |

## 枚举类型说明

### WindowManager_ErrorCode

```
enum WindowManager_ErrorCode
```

**描述**

窗口管理接口返回状态码枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| OK = 0 | 成功。 |
| WINDOW_MANAGER_ERRORCODE_NO_PERMISSION = 201 | 无权限。<br/>**起始版本：** 15 |
| WINDOW_MANAGER_ERRORCODE_INVALID_PARAM = 401 | 非法参数。<br/>**起始版本：** 15 |
| WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED = 801 | 设备不支持。<br/>**起始版本：** 15 |
| INVAILD_WINDOW_ID = 1000 | 非法窗口ID。 |
| SERVICE_ERROR = 2000 | 服务异常。 |
| WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL = 1300002 | 窗口状态异常。<br/>**起始版本：** 15 |
| WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL = 1300003 | 窗口管理器服务异常。<br/>**起始版本：** 15 |
| WINDOW_MANAGER_ERRORCODE_PIP_DESTROY_FAILED = 1300011 | 画中画销毁失败。<br/>**起始版本：** 20 |
| WINDOW_MANAGER_ERRORCODE_PIP_STATE_ABNORMAL = 1300012 | 画中画状态异常。<br/>**起始版本：** 20 |
| WINDOW_MANAGER_ERRORCODE_PIP_CREATE_FAILED = 1300013 | 画中画创建失败。<br/>**起始版本：** 20 |
| WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR = 1300014 | 画中画内部错误。可能原因：<br/>1.画中画依赖的窗口异常，可能窗口为空；2.画中画控制器异常。<br/>**起始版本：** 20 |
| WINDOW_MANAGER_ERRORCODE_PIP_REPEATED_OPERATION = 1300015 | 画中画重复操作。<br/>**起始版本：** 20 |
| WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM = 1300016 | 参数错误。 可能原因：<br/>1.参数取值范围非法；2.参数数量非法；3.参数类型非法。<br/>**起始版本：** 20 |

### WindowManager_AvoidAreaType

```
enum WindowManager_AvoidAreaType
```

**描述**

避让区域枚举类型。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM = 0 | 系统避让区域。 |
| WINDOW_MANAGER_AVOID_AREA_TYPE_CUTOUT = 1 | 刘海屏避让。 |
| WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM_GESTURE = 2 | 系统手势区域。 |
| WINDOW_MANAGER_AVOID_AREA_TYPE_KEYBOARD = 3 | 键盘区域。 |
| WINDOW_MANAGER_AVOID_AREA_TYPE_NAVIGATION_INDICATOR = 4 | 导航条区域。 |

### WindowManager_WindowType

```
enum WindowManager_WindowType
```

**描述**

窗口类型。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| WINDOW_MANAGER_WINDOW_TYPE_APP = 0 | 子窗口。 |
| WINDOW_MANAGER_WINDOW_TYPE_MAIN = 1 | 主窗口。 |
| WINDOW_MANAGER_WINDOW_TYPE_FLOAT = 8 | 悬浮窗口。 |
| WINDOW_MANAGER_WINDOW_TYPE_DIALOG = 16 | 模态窗口。 |


