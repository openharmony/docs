# WindowManager_NativeModule


## 概述

提供应用窗口的管理能力。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [oh_window_comm.h](oh__window__comm_8h.md) | 提供窗口的公共枚举、公共定义等。 | 
| [oh_window_event_filter.h](oh__window__event__filter_8h.md) | 定义窗口管理按键事件过滤的接口，当多模输入的事件经过窗口时，可以通过过滤接口拦截事件不让事件往下分发。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [WindowManager_ErrorCode](#windowmanager_errorcode)  [WindowManager_ErrorCode](#windowmanager_errorcode) | 窗口管理接口返回状态码枚举。 | 
| typedef bool(\*[OH_NativeWindowManager_KeyEventFilter](#oh_nativewindowmanager_keyeventfilter)) (Input_KeyEvent \*keyEvent) | 定义多模按键的过滤函数。 | 
| typedef bool(\* [OH_NativeWindowManager_MouseEventFilter](#oh_nativewindowmanager_mouseeventfilter)) (Input_MouseEvent \*mouseEvent) | 定义多模鼠标事件的过滤函数。 | 
| typedef bool(\* [OH_NativeWindowManager_TouchEventFilter](#oh_nativewindowmanager_toucheventfilter)) (Input_TouchEvent \*touchEvent) | 定义多模触摸事件的过滤函数。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [WindowManager_ErrorCode](#windowmanager_errorcode-1) { OK = 0, INVAILD_WINDOW_ID = 1000, SERVICE_ERROR = 2000 } | 窗口管理接口返回状态码枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [WindowManager_ErrorCode](#windowmanager_errorcode)  [OH_NativeWindowManager_RegisterKeyEventFilter](#oh_nativewindowmanager_registerkeyeventfilter) (int32_t windowId, [OH_NativeWindowManager_KeyEventFilter](#oh_nativewindowmanager_keyeventfilter) keyEventFilter) | 注册按键事件的过滤函数。 | 
| [WindowManager_ErrorCode](#windowmanager_errorcode)  [OH_NativeWindowManager_UnregisterKeyEventFilter](#oh_nativewindowmanager_unregisterkeyeventfilter) (int32_t windowId) | 取消注册窗口的按键事件过滤函数。 | 
| [WindowManager_ErrorCode](#windowmanager_errorcode)  [OH_NativeWindowManager_RegisterMouseEventFilter](#oh_nativewindowmanager_registermouseeventfilter) (int32_t windowId, [OH_NativeWindowManager_MouseEventFilter](#oh_nativewindowmanager_mouseeventfilter) mouseEventFilter) | 注册鼠标事件的过滤函数。 | 
| [WindowManager_ErrorCode](#windowmanager_errorcode)  [OH_NativeWindowManager_UnregisterMouseEventFilter](#oh_nativewindowmanager_unregistermouseeventfilter) (int32_t windowId) | 取消注册窗口的鼠标事件过滤函数。 | 
| [WindowManager_ErrorCode](#windowmanager_errorcode)  [OH_NativeWindowManager_RegisterTouchEventFilter](#oh_nativewindowmanager_registertoucheventfilter) (int32_t windowId, [OH_NativeWindowManager_TouchEventFilter](#oh_nativewindowmanager_toucheventfilter) touchEventFilter) | 注册触摸事件的过滤函数。 | 
| [WindowManager_ErrorCode](#windowmanager_errorcode)  [OH_NativeWindowManager_UnregisterTouchEventFilter](#oh_nativewindowmanager_unregistertoucheventfilter) (int32_t windowId) | 取消注册窗口的触摸事件过滤函数。 | 

## 类型定义说明


### OH_NativeWindowManager_MouseEventFilter

```
typedef bool(* OH_NativeWindowManager_MouseEventFilter) (Input_MouseEvent *mouseEvent)
```

**描述**

定义多模鼠标事件的过滤函数。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 多模鼠标事件，具体可见**Input_MouseEvent**，事件定义在oh_input_manager中。 | 

**返回：**

返回是否过滤该事件。true表示过滤该事件，不会继续往下分发；false表示不过滤不拦截此事件，将会继续分发。


### OH_NativeWindowManager_TouchEventFilter

```
typedef bool(* OH_NativeWindowManager_TouchEventFilter) (Input_TouchEvent *touchEvent)
```

**描述**

定义多模触摸事件的过滤函数。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| touchEvent | 多模触摸事件，具体可见**Input_TouchEvent**，事件定义在oh_input_manager中。 | 

**返回：**

返回是否过滤该事件。true表示过滤该事件，不会继续往下分发；false表示不过滤不拦截此事件，将会继续分发。

### OH_NativeWindowManager_KeyEventFilter

```
typedef bool(* OH_NativeWindowManager_KeyEventFilter) (Input_KeyEvent *keyEvent)
```

**描述**

定义多模按键的过滤函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 多模按键事件，具体可见Input_KeyEvent，事件定义在oh_input_manager中。 | 

**返回：**

返回是否过滤该事件，返回true窗口不再往下分发，返回false表示不拦截


### WindowManager_ErrorCode

```
typedef enum WindowManager_ErrorCode WindowManager_ErrorCode
```

**描述**

窗口管理接口返回状态码枚举。

**起始版本：** 12


## 枚举类型说明


### WindowManager_ErrorCode

```
enum WindowManager_ErrorCode
```

**描述**

窗口管理接口返回状态码枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| OK | 成功。 | 
| INVAILD_WINDOW_ID | 非法窗口ID。 | 
| SERVICE_ERROR | 服务异常。 | 


## 函数说明


### OH_NativeWindowManager_RegisterMouseEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_RegisterMouseEventFilter (int32_t windowId, OH_NativeWindowManager_MouseEventFilter mouseEventFilter )
```

**描述**

注册鼠标事件的过滤函数。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| windowId | 需要过滤鼠标事件的窗口ID。 | 
| mouseEventFilter | 多模鼠标事件的过滤函数。 | 

**返回：**

返回窗口管理接口的通用状态码，具体可见[WindowManager_ErrorCode](#windowmanager_errorcode)。


### OH_NativeWindowManager_RegisterTouchEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_RegisterTouchEventFilter (int32_t windowId, OH_NativeWindowManager_TouchEventFilter touchEventFilter )
```

**描述**

注册触摸事件的过滤函数。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| windowId | 需要过滤触摸事件的窗口ID。 | 
| touchEventFilter | 多模触摸事件的过滤函数。 | 

**返回：**

返回窗口管理接口的通用状态码，具体可见[WindowManager_ErrorCode](#windowmanager_errorcode)。


### OH_NativeWindowManager_UnregisterMouseEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterMouseEventFilter (int32_t windowId)
```

**描述**

取消注册窗口的鼠标事件过滤函数。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| windowId | 需要取消过滤鼠标事件的窗口ID。 | 

**返回：**

返回窗口管理接口的通用状态码，具体可见[WindowManager_ErrorCode](#windowmanager_errorcode)。


### OH_NativeWindowManager_UnregisterTouchEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterTouchEventFilter (int32_t windowId)
```

**描述**

取消注册窗口的触摸事件过滤函数。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| windowId | 需要取消过滤触摸事件的窗口ID。 | 

**返回：**

返回窗口管理接口的通用状态码，具体可见[WindowManager_ErrorCode](#windowmanager_errorcode)。

### OH_NativeWindowManager_RegisterKeyEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_RegisterKeyEventFilter (int32_t windowId, OH_NativeWindowManager_KeyEventFilter keyEventFilter )
```

**描述**

注册按键事件的过滤函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| windowId | 需要过滤按键事件的窗口ID。 | 
| keyEventFilter | 多模按键的过滤函数。 | 

**返回：**

返回窗口管理接口的通用状态码，具体可见[WindowManager_ErrorCode](#windowmanager_errorcode)。


### OH_NativeWindowManager_UnregisterKeyEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterKeyEventFilter (int32_t windowId)
```

**描述**

取消注册窗口的按键事件过滤函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| windowId | 需要取消过滤按键事件的窗口ID。 | 

**返回：**

返回窗口管理接口的通用状态码，具体可见[WindowManager_ErrorCode](#windowmanager_errorcode)。
