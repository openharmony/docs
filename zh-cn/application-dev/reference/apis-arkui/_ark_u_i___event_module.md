# ArkUI_EventModule


## 概述

在Native端提供ArkUI的UI输入事件能力。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ui_input_event.h](ui__input__event_8h.md) | 提供ArkUI在Native侧的事件定义。<br>**库：** libace_ndk.z.so| 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [ArkUI_UIInputEvent](#arkui_uiinputevent) [ArkUI_UIInputEvent](#arkui_uiinputevent) | UI输入事件定义。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_UIInputEvent_Type](#arkui_uiinputevent_type) { ArkUI_UIINPUTEVENT_TYPE_UNKNOWN = 0, ArkUI_UIINPUTEVENT_TYPE_TOUCH = 1, ArkUI_UIINPUTEVENT_TYPE_AXIS = 2 } | UI输入事件类型定义。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_ArkUI_UIInputEvent_GetType](#oh_arkui_uiinputevent_gettype) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取UI输入事件的类型。  | 
| int64_t [OH_ArkUI_UIInputEvent_GetEventTime](#oh_arkui_uiinputevent_geteventtime) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取UI输入事件发生的时间。  | 
| float [OH_ArkUI_PointerEvent_GetX](#oh_arkui_pointerevent_getx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetY](#oh_arkui_pointerevent_gety) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetWindowX](#oh_arkui_pointerevent_getwindowx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetWindowY](#oh_arkui_pointerevent_getwindowy) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetDisplayX](#oh_arkui_pointerevent_getdisplayx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetDisplayY](#oh_arkui_pointerevent_getdisplayy) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的Y坐标。  | 
| double [OH_ArkUI_AxisEvent_GetVerticalAxisValue](#oh_arkui_axisevent_getverticalaxisvalue) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取当前轴事件的垂直滚动轴的值。  | 
| double [OH_ArkUI_AxisEvent_GetHorizontalAxisValue](#oh_arkui_axisevent_gethorizontalaxisvalue) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取当前轴事件的水平滚动轴的值。  | 
| double [OH_ArkUI_AxisEvent_GetPinchAxisScaleValue](#oh_arkui_axisevent_getpinchaxisscalevalue) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取当前轴事件的捏合轴缩放的值。  | 


## 类型定义说明


### ArkUI_UIInputEvent

```
typedef struct ArkUI_UIInputEventArkUI_UIInputEvent
```
**描述：**

UI输入事件定义。

**起始版本：** 12


## 枚举类型说明


### ArkUI_UIInputEvent_Type

```
enum ArkUI_UIInputEvent_Type
```
**描述：**

UI输入事件类型定义。

**起始版本：** 12


## 函数说明


### OH_ArkUI_AxisEvent_GetHorizontalAxisValue()

```
double OH_ArkUI_AxisEvent_GetHorizontalAxisValue (const ArkUI_UIInputEvent * event)
```
**描述：**

获取当前轴事件的水平滚动轴的值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前轴事件的水平滚动轴的值。


### OH_ArkUI_AxisEvent_GetPinchAxisScaleValue()

```
double OH_ArkUI_AxisEvent_GetPinchAxisScaleValue (const ArkUI_UIInputEvent * event)
```
**描述：**

获取当前轴事件的捏合轴缩放的值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前轴事件的捏合轴缩放的值。


### OH_ArkUI_AxisEvent_GetVerticalAxisValue()

```
double OH_ArkUI_AxisEvent_GetVerticalAxisValue (const ArkUI_UIInputEvent * event)
```
**描述：**

获取当前轴事件的垂直滚动轴的值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前轴事件的垂直滚动轴的值。


### OH_ArkUI_PointerEvent_GetDisplayX()

```
float OH_ArkUI_PointerEvent_GetDisplayX (const ArkUI_UIInputEvent * event)
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的X坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前屏幕左上角的X坐标。


### OH_ArkUI_PointerEvent_GetDisplayY()

```
float OH_ArkUI_PointerEvent_GetDisplayY (const ArkUI_UIInputEvent * event)
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的Y坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前屏幕左上角的Y坐标。


### OH_ArkUI_PointerEvent_GetWindowX()

```
float OH_ArkUI_PointerEvent_GetWindowX (const ArkUI_UIInputEvent * event)
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的X坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前应用窗口左上角的X坐标。


### OH_ArkUI_PointerEvent_GetWindowY()

```
float OH_ArkUI_PointerEvent_GetWindowY (const ArkUI_UIInputEvent * event)
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的Y坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前应用窗口左上角的Y坐标。


### OH_ArkUI_PointerEvent_GetX()

```
float OH_ArkUI_PointerEvent_GetX (const ArkUI_UIInputEvent * event)
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的X坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前组件左上角的X坐标。


### OH_ArkUI_PointerEvent_GetY()

```
float OH_ArkUI_PointerEvent_GetY (const ArkUI_UIInputEvent * event)
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的Y坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前组件左上角的Y坐标。


### OH_ArkUI_UIInputEvent_GetEventTime()

```
int64_t OH_ArkUI_UIInputEvent_GetEventTime (const ArkUI_UIInputEvent * event)
```
**描述：**

获取UI输入事件发生的时间。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回UI输入事件发生的时间。


### OH_ArkUI_UIInputEvent_GetType()

```
int32_t OH_ArkUI_UIInputEvent_GetType (const ArkUI_UIInputEvent * event)
```
**描述：**

获取UI输入事件的类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前UI输入事件的类型。
