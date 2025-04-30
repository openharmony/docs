# oh_window_comm.h


## 概述

提供窗口的公共枚举、公共定义等。

**系统能力：** SystemCapability.Window.SessionManager

**引用文件：**&lt;window_manager/oh_window_comm.h&gt;

**库：** libnative_window_manager.so

**起始版本：** 12

**相关模块：**[WindowManager](_window_manager___native_module.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| struct  [WindowManager_Rect](_window_manager___rect.md) | 定义窗口矩形结构体，包含窗口位置和宽高信息。 |
| struct  [WindowManager_WindowProperties](_window_manager___window_properties.md) | 窗口属性。 |
| struct  [WindowManager_AvoidArea](_window_manager___avoid_area.md) | 定义避让区域结构体。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode)  [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) | 窗口管理接口返回状态码枚举。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) {<br/>OK = 0, WINDOW_MANAGER_ERRORCODE_NO_PERMISSION = 201, WINDOW_MANAGER_ERRORCODE_INVALID_PARAM = 401, WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED = 801,<br/>INVAILD_WINDOW_ID = 1000, SERVICE_ERROR = 2000, WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL = 1300002, WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL = 1300003<br/>} | 窗口管理接口返回状态码枚举。 |
| [WindowManager_AvoidAreaType](_window_manager___native_module.md#windowmanager_avoidareatype) {<br/>WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM = 0, WINDOW_MANAGER_AVOID_AREA_TYPE_CUTOUT = 1, WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM_GESTURE = 2, WINDOW_MANAGER_AVOID_AREA_TYPE_KEYBOARD = 3,<br/>WINDOW_MANAGER_AVOID_AREA_TYPE_NAVIGATION_INDICATOR = 4<br/>} | 避让区域枚举类型。 |
| [WindowManager_WindowType](_window_manager___native_module.md#windowmanager_windowtype) { WINDOW_MANAGER_WINDOW_TYPE_APP = 0, WINDOW_MANAGER_WINDOW_TYPE_MAIN = 1, WINDOW_MANAGER_WINDOW_TYPE_FLOAT = 8, WINDOW_MANAGER_WINDOW_TYPE_DIALOG = 16 } | 窗口类型。 |
