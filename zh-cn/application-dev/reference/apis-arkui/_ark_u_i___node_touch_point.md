# ArkUI_NodeTouchPoint


## 概述

定义Touch事件触控点信息的数据结构。

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| int32_t [id](#id) | 触控事件标识。  |
| int64_t [pressedTime](#pressedtime) | 手指按下的时间戳，单位为微秒（us）。  |
| int32_t [screenX](#screenx) | 触摸位置所属的屏幕X坐标。  |
| int32_t [screenY](#screeny) | 触摸位置所属的屏幕Y坐标。  |
| int32_t [windowX](#windowx) | 触摸位置在窗口中的X坐标。  |
| int32_t [windowY](#windowy) | 触摸位置在窗口中的Y坐标。  |
| int32_t [nodeX](#nodex) | 触摸位置在当前触发事件组件中的X坐标。  |
| int32_t [nodeY](#nodey) | 触摸位置在当前触发事件组件中的Y坐标。  |
| double [pressure](#pressure) | 压力值，取值范围是[0.0, 1.0]，0.0表示不支持。  |
| int32_t [contactAreaWidth](#contactareawidth) | 触摸区域的宽度。  |
| int32_t [contactAreaHeight](#contactareaheight) | 触摸区域的高度。  |
| double [tiltX](#tiltx) | 相对YZ平面的角度，取值范围是[-90, 90]，其中正值是向右倾斜。  |
| double [tiltY](#tilty) | 相对XZ平面的角度，取值范围是[-90, 90]，其中正值是向下倾斜。  |
| int32_t [toolX](#toolx) | 工具区域的中心点X坐标。  |
| int32_t [toolY](#tooly) | 工具区域的中心点Y坐标。  |
| int32_t [toolWidth](#toolwidth) | 工具接触区域的宽度。  |
| int32_t [toolHeight](#toolheight) | 工具接触区域的高度。  |
| int32_t [rawX](#rawx) | 输入设备上的X坐标。  |
| int32_t [rawY](#rawy) | 输入设备上的Y坐标。  |
| [ArkUI_NodeToolType](_ark_u_i___native_module.md#arkui_nodetooltype)[toolType](#tooltype) | 工具类型。  |


## 结构体成员变量说明


### contactAreaHeight

```
int32_t ArkUI_NodeTouchPoint::contactAreaHeight
```
**描述：**

触摸区域的高度。


### contactAreaWidth

```
int32_t ArkUI_NodeTouchPoint::contactAreaWidth
```
**描述：**

触摸区域的宽度。


### id

```
int32_t ArkUI_NodeTouchPoint::id
```
**描述：**

触控事件标识。


### nodeX

```
int32_t ArkUI_NodeTouchPoint::nodeX
```
**描述：**

触摸位置在当前触发事件组件中的X坐标。


### nodeY

```
int32_t ArkUI_NodeTouchPoint::nodeY
```
**描述：**

触摸位置在当前触发事件组件中的Y坐标。


### pressedTime

```
int64_t ArkUI_NodeTouchPoint::pressedTime
```
**描述：**

手指按下的时间戳，单位为微秒（us）。


### pressure

```
double ArkUI_NodeTouchPoint::pressure
```
**描述：**

压力值，取值范围是[0.0, 1.0]，0.0表示不支持。


### rawX

```
int32_t ArkUI_NodeTouchPoint::rawX
```
**描述：**

输入设备上的X坐标。


### rawY

```
int32_t ArkUI_NodeTouchPoint::rawY
```
**描述：**

输入设备上的Y坐标。


### screenX

```
int32_t ArkUI_NodeTouchPoint::screenX
```
**描述：**

触摸位置所属的屏幕X坐标。


### screenY

```
int32_t ArkUI_NodeTouchPoint::screenY
```
**描述：**

触摸位置所属的屏幕Y坐标。


### tiltX

```
double ArkUI_NodeTouchPoint::tiltX
```

**描述：**

相对YZ平面的角度，取值范围是[-90, 90]，其中正值是向右倾斜。


### tiltY

```
double ArkUI_NodeTouchPoint::tiltY
```
**描述：**

相对XZ平面的角度，取值范围是[-90, 90]，其中正值是向下倾斜。


### toolHeight

```
int32_t ArkUI_NodeTouchPoint::toolHeight
```
**描述：**

工具接触区域的高度。


### toolType

```
ArkUI_NodeToolType ArkUI_NodeTouchPoint::toolType
```
**描述：**

工具类型。


### toolWidth

```
int32_t ArkUI_NodeTouchPoint::toolWidth
```
**描述：**

工具接触区域的宽度。


### toolX

```
int32_t ArkUI_NodeTouchPoint::toolX
```
**描述：**

工具区域的中心点X坐标。


### toolY

```
int32_t ArkUI_NodeTouchPoint::toolY
```
**描述：**

工具区域的中心点Y坐标。


### windowX

```
int32_t ArkUI_NodeTouchPoint::windowX
```
**描述：**

触摸位置在窗口中的X坐标。


### windowY

```
int32_t ArkUI_NodeTouchPoint::windowY
```
**描述：**

触摸位置在窗口中的Y坐标。
